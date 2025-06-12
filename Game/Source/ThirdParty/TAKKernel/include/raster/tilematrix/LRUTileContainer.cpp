#include "raster/tilematrix/LRUTileContainer.h"

#include <cassert>
#include <map>
#include <set>
#include <string>

#include "db/DatabaseFactory.h"
#include "db/Query.h"
#include "db/Statement2.h"
#include "port/STLVectorAdapter.h"
#include "thread/Lock.h"

using namespace TAK::Engine::Raster::TileMatrix;

using namespace TAK::Engine::DB;
using namespace TAK::Engine::Math;
using namespace TAK::Engine::Thread;
using namespace TAK::Engine::Util;

#define POOL_ALLOCATOR_RESERVED_OVERHEAD 1024u

namespace
{
    struct BenchmarkObservation
    {
        BenchmarkObservation(Statistics &stats_) NOTHROWS :
            stats(stats_),
            start(TAK::Engine::Port::Platform_systime_millis()),
            d(false)
        {}
        ~BenchmarkObservation() NOTHROWS
        {
            if(!d)
            stats.observe((double)(TAK::Engine::Port::Platform_systime_millis() - start));
        }
        void discard() NOTHROWS { d = true; }
    private :
        Statistics& stats;
        int64_t start;
        bool d;
    };

    /**
     * @return TE_Ok on success, TE_InvalidArg if the database is not compatible, various codes on failure
     */
    TAKErr verifySchema(Database2& database) NOTHROWS;
    TAKErr initDatabase(Database2& database, const char *name, const int srid, const std::vector<TileMatrix::ZoomLevel> &zoomLevels, const Point2<double> &origin, const TAK::Engine::Feature::Envelope2 &bounds) NOTHROWS;
    std::size_t length(Database2& database) NOTHROWS;

    TAKErr insertMetadata(Database2& database, const char* key, const int value) NOTHROWS;
    TAKErr insertMetadata(Database2& database, const char* key, const double value) NOTHROWS;
    TAKErr insertMetadata(Database2& database, const char* key, const char *value) NOTHROWS;

    std::size_t getMaxTileDataLength(Database2 &database) NOTHROWS 
    {
        TAKErr code(TE_Ok);
        do {
            QueryPtr query(nullptr, nullptr);
            code = database.compileQuery(query, "SELECT max(tileWidth), max(tileHeight) FROM tile_matrix");
            TE_CHECKBREAK_CODE(code);

            code = query->moveToNext();
            TE_CHECKBREAK_CODE(code);

            int maxTileWidth, maxTileHeight;
            code = query->getInt(&maxTileWidth, 0);
            TE_CHECKBREAK_CODE(code);
            code = query->getInt(&maxTileHeight, 1);
            TE_CHECKBREAK_CODE(code);

            return (std::size_t)(maxTileWidth * maxTileHeight * 4u) + POOL_ALLOCATOR_RESERVED_OVERHEAD;
        } while (false);
        
        return 0u;
    }
}

LRUTileContainer::LRUTileContainer(DatabasePtr &&db_, const std::size_t limit_, const float trimBuffer_) NOTHROWS :
    srid(-1),
    limit(limit_),
    trimBuffer(trimBuffer_),
    db(std::move(db_)),
    poolTileDataMaxSize(getMaxTileDataLength(*db)),
    // observed max simultaenous block drawdown is 4u, block allocate approximately 2X observed max
    tileDataAllocator(getMaxTileDataLength(*db), 8u),
    mutex(TEMT_Recursive)
{
    TAKErr code(TE_Ok);
    do {
        // metadata
        {
            QueryPtr query(nullptr, nullptr);
            code = db->compileQuery(query, "SELECT key, value_i, value_d, value_s FROM metadata");
            TE_CHECKBREAK_CODE(code);
            do {
                code = query->moveToNext();
                TE_CHECKBREAK_CODE(code);

                const char* key;
                code = query->getString(&key, 0);
                TE_CHECKBREAK_CODE(code);

                if(TAK::Engine::Port::String_equal(key, "srid")) {
                    code = query->getInt(&srid, 1);
                    TE_CHECKBREAK_CODE(code);
                } else if(TAK::Engine::Port::String_equal(key, "origin_x")) {
                    code = query->getDouble(&origin.x, 2);
                    TE_CHECKBREAK_CODE(code);
                } else if(TAK::Engine::Port::String_equal(key, "origin_y")) {
                    code = query->getDouble(&origin.y, 2);
                    TE_CHECKBREAK_CODE(code);
                } else if(TAK::Engine::Port::String_equal(key, "bounds_minX")) {
                    code = query->getDouble(&bounds.minX, 2);
                    TE_CHECKBREAK_CODE(code);
                } else if(TAK::Engine::Port::String_equal(key, "bounds_minY")) {
                    code = query->getDouble(&bounds.minY, 2);
                    TE_CHECKBREAK_CODE(code);
                } else if(TAK::Engine::Port::String_equal(key, "bounds_maxX")) {
                    code = query->getDouble(&bounds.maxX, 2);
                    TE_CHECKBREAK_CODE(code);
                } else if(TAK::Engine::Port::String_equal(key, "bounds_maxY")) {
                    code = query->getDouble(&bounds.maxY, 2);
                    TE_CHECKBREAK_CODE(code);
                } else if(TAK::Engine::Port::String_equal(key, "name")) {
                    const char* cname = nullptr;
                    code = query->getString(&cname, 3);
                    TE_CHECKBREAK_CODE(code);
                    name = cname;
                }
            } while (true);
            if (code == TE_Done)
                code = TE_Ok;
            TE_CHECKBREAK_CODE(code);
        }
        // tile matrix
        {
            QueryPtr query(nullptr, nullptr);
            code = db->compileQuery(query, "SELECT level, resolution, pixelSizeX, pixelSizeY, tileWidth, tileHeight FROM tile_matrix");
            TE_CHECKBREAK_CODE(code);

            do {
                code = query->moveToNext();
                TE_CHECKBREAK_CODE(code);

                TileMatrix::ZoomLevel zoomLevel;
                code = query->getInt(&zoomLevel.level, 0);
                TE_CHECKBREAK_CODE(code);
                code = query->getDouble(&zoomLevel.resolution, 1);
                TE_CHECKBREAK_CODE(code);
                code = query->getDouble(&zoomLevel.pixelSizeX, 2);
                TE_CHECKBREAK_CODE(code);
                code = query->getDouble(&zoomLevel.pixelSizeY, 3);
                TE_CHECKBREAK_CODE(code);
                code = query->getInt(&zoomLevel.tileWidth, 4);
                TE_CHECKBREAK_CODE(code);
                code = query->getInt(&zoomLevel.tileHeight, 5);
                TE_CHECKBREAK_CODE(code);

                zoomLevels.push_back(zoomLevel);
            } while (true);
            if (code == TE_Done)
                code = TE_Ok;
            TE_CHECKBREAK_CODE(code);
        }
    } while (false);
    if (code != TE_Ok)
        db.reset();
}
LRUTileContainer::~LRUTileContainer() NOTHROWS
{
}
TAKErr LRUTileContainer::isReadOnly(bool* value) NOTHROWS
{
    *value = readOnly;
    return TE_Ok;
}
TAKErr LRUTileContainer::setTile(const std::size_t level, const std::size_t x, const std::size_t y, const uint8_t* value, const std::size_t len, const int64_t expiration) NOTHROWS
{
    if (!db)
        return TE_IllegalState;
    TAKErr code(TE_Ok);
    Lock lock(mutex);
    BenchmarkObservation benchmark_std(statistics.setTileData);

    auto& statements = precompiledStatements.get();

    Record record;
    const bool exists = getTileRecord(&record, level, x, y) == TE_Ok;
    std::size_t sizeAfterInsert;
    {
        BenchmarkObservation obs(statistics.dblen);
        sizeAfterInsert = length(*db);
    }
    StatementPtr stmt(nullptr, nullptr);
    if (!exists)
        sizeAfterInsert += len;
    else if (record.len < len)
        sizeAfterInsert += (len - record.len);
    // check for trim
    if(limit && sizeAfterInsert > limit) {
        benchmark_std.discard();
        BenchmarkObservation benchmark_t(statistics.trim);
        int64_t deleteFrom = -1;
        //Database2::Transaction transaction(*db);
        QueryPtr query(nullptr, nullptr);
        code = db->compileQuery(query, "SELECT length(data), access, x, y, z FROM tiles ORDER BY access ASC");
        TE_CHECKRETURN_CODE(code);
        do {
            code = query->moveToNext();
            TE_CHECKBREAK_CODE(code);
            int recordLen;
            code = query->getInt(&recordLen, 0);
            TE_CHECKBREAK_CODE(code);
            assert(sizeAfterInsert >= recordLen);
            sizeAfterInsert -= (recordLen);
            code = query->getLong(&deleteFrom, 1);
            TE_CHECKBREAK_CODE(code);

            int recordX;
            code = query->getInt(&recordX, 2);
            TE_CHECKBREAK_CODE(code);
            int recordY;
            code = query->getInt(&recordY, 3);
            TE_CHECKBREAK_CODE(code);
            int recordZ;
            code = query->getInt(&recordZ, 4);
            TE_CHECKBREAK_CODE(code);

            if (sizeAfterInsert < (limit * (1.0-trimBuffer)))
                break;
        } while (true);
        if (code == TE_Done)
            code = TE_Ok;
        TE_CHECKRETURN_CODE(code);

        stmt.reset();
        code = db->compileStatement(stmt, "DELETE FROM tiles WHERE access <= ?");
        TE_CHECKRETURN_CODE(code);
        code = stmt->bindLong(1, deleteFrom);
        TE_CHECKRETURN_CODE(code);
        code = stmt->execute();
        TE_CHECKRETURN_CODE(code);

        std::size_t sizeAfterTrim = length(*db);
        code = TE_Ok;
    }

    stmt.reset();
    if (!exists) {
        if (!statements.insertTile) {
            code = db->compileStatement(statements.insertTile, "INSERT INTO tiles (data, expiration, access, x, y, z, id) VALUES(?, ?, ?, ?, ?, ?, ?)");
            TE_CHECKRETURN_CODE(code);
        }
        stmt = StatementPtr(statements.insertTile.get(), Memory_leaker_const<Statement2>);
    } else {
        if (!statements.updateTile) {
            code = db->compileStatement(statements.updateTile, "UPDATE tiles SET data = ?, expiration = ?, access = ?, x = ?, y = ?, z = ? WHERE id = ?");
            TE_CHECKRETURN_CODE(code);
        }
        stmt = StatementPtr(statements.updateTile.get(), Memory_leaker_const<Statement2>);
    }
    code = stmt->clearBindings();
    TE_CHECKRETURN_CODE(code);
    code = stmt->bindBlob(1, value, len);
    TE_CHECKRETURN_CODE(code);
    code = stmt->bindLong(2, (int64_t)expiration);
    TE_CHECKRETURN_CODE(code);
    code = stmt->bindLong(3, TAK::Engine::Port::Platform_systime_millis());
    TE_CHECKRETURN_CODE(code);
    code = stmt->bindInt(4, (int)x);
    TE_CHECKRETURN_CODE(code);
    code = stmt->bindInt(5, (int)y);
    TE_CHECKRETURN_CODE(code);
    code = stmt->bindInt(6, (int)level);
    TE_CHECKRETURN_CODE(code);
    code = stmt->bindLong(7, ((int64_t)level<<58LL)|((int64_t)y<<29LL)|((int64_t)x));
    TE_CHECKRETURN_CODE(code);

    code = stmt->execute();
    TE_CHECKRETURN_CODE(code);

    record.index = Point2<std::size_t>(x, y, level);
    record.expiration = expiration;
    record.len = len;

    return code;
}
TAKErr LRUTileContainer::setTile(const std::size_t level, const std::size_t x, const std::size_t y, const Renderer::Bitmap2* data, const int64_t expiration) NOTHROWS
{
    return TE_NotImplemented;
}
bool LRUTileContainer::hasTileExpirationMetadata() NOTHROWS
{
    return true;
}
int64_t LRUTileContainer::getTileExpiration(const std::size_t level, const std::size_t x, const std::size_t y) NOTHROWS
{
    Lock lock(mutex);
    Record record;
    return getTileRecord(&record, level, x, y) == TE_Ok ? record.expiration : -1LL;
}
const char* LRUTileContainer::getName() const NOTHROWS
{
    return name;
}
int LRUTileContainer::getSRID() const NOTHROWS
{
    return srid;
}
TAKErr LRUTileContainer::getZoomLevel(Port::Collection<ZoomLevel>& value) const NOTHROWS
{
    for(auto zoomLevel : zoomLevels)
        value.add(zoomLevel);
    return TE_Ok;
}
double LRUTileContainer::getOriginX() const NOTHROWS
{
    return origin.x;
}
double LRUTileContainer::getOriginY() const NOTHROWS
{
    return origin.y;
}
TAKErr LRUTileContainer::getTile(Renderer::BitmapPtr& result, const std::size_t zoom, const std::size_t x, const std::size_t y) NOTHROWS
{
    return TE_NotImplemented;
}
TAKErr LRUTileContainer::getTileData(std::unique_ptr<const uint8_t, void (*)(const uint8_t*)>& value, std::size_t* len,
                         const std::size_t zoom, const std::size_t x, const std::size_t y) NOTHROWS
{
    TAKErr code(TE_Ok);
    Lock lock(mutex);
    BenchmarkObservation gtd(statistics.getTileData);
    if(false) {
        Record record;
        code = getTileRecord(&record, zoom, x, y);
        if (code != TE_Ok)
            return code;
    }

    auto& statements = precompiledStatements.get();
    if(!statements.queryTileData) {
        code = db->compileQuery(statements.queryTileData, "SELECT data, id, expiration FROM tiles WHERE id = ? LIMIT 1");
        TE_CHECKRETURN_CODE(code);
    }

    code = statements.queryTileData->clearBindings();
    TE_CHECKRETURN_CODE(code);
    code = statements.queryTileData->bindLong(1, ((int64_t)zoom<<58LL)|((int64_t)y<<29LL)|((int64_t)x));
    TE_CHECKRETURN_CODE(code);
    code = statements.queryTileData->moveToNext();
    if (code == TE_Done)
        return TE_IllegalState;
    TE_CHECKRETURN_CODE(code);

    struct {
        const uint8_t* value{ nullptr };
        std::size_t len{ 0u };
    } blob;
    code = statements.queryTileData->getBlob(&blob.value, &blob.len, 0);
    TE_CHECKRETURN_CODE(code);
    int rowid;
    code = statements.queryTileData->getInt(&rowid, 1);
    TE_CHECKRETURN_CODE(code);

    std::unique_ptr<uint8_t, void(*)(const uint8_t*)> arr(nullptr, nullptr);
    if (blob.len <= poolTileDataMaxSize) {
        // pool allocate if blob will fit in block
        code = tileDataAllocator.allocate<uint8_t>(arr);
    } else {
        arr = std::unique_ptr<uint8_t, void(*)(const uint8_t*)>(new(std::nothrow) uint8_t[blob.len], Memory_array_deleter_const<uint8_t>);
        code = !arr ? TE_OutOfMemory : TE_Ok;
    }
    TE_CHECKRETURN_CODE(code);

    memcpy(arr.get(), blob.value, blob.len);

    value = std::move(arr);
    *len = blob.len;

    // update last access
    bool ro = true;
    if(db->isReadOnly(&ro) == TE_Ok && !ro) {
        do {
            if (!statements.updateAccess) {
                code = db->compileStatement(statements.updateAccess, "UPDATE tiles SET access = ? WHERE id = ?");
                TE_CHECKBREAK_CODE(code);
            }
            statements.updateAccess->clearBindings();
            TE_CHECKBREAK_CODE(code);
            code = statements.updateAccess->bindLong(1, TAK::Engine::Port::Platform_systime_millis());
            TE_CHECKBREAK_CODE(code);
            code = statements.updateAccess->bindInt(2, rowid);
            TE_CHECKBREAK_CODE(code);
            code = statements.updateAccess->execute();
            TE_CHECKBREAK_CODE(code);
        } while(false);
        if(code != TE_Ok) {
            // failed to update access. This is not a critical failure, but may result in cache thrash
            Logger_log(TELL_Debug, "LRUTileContainer: Failed to update access for {%u, %u, %u}", (unsigned)zoom, (unsigned)x, (unsigned)y);
            code = TE_Ok;
        }
    }
    return TE_Ok;
}
TAKErr LRUTileContainer::getBounds(TAK::Engine::Feature::Envelope2 *value) const NOTHROWS
{
    *value = bounds;
    return TE_Ok;
}
TAKErr LRUTileContainer::getTileRecord(Record *value, const std::size_t level, const std::size_t x, const std::size_t y) NOTHROWS
{
    TAKErr code(TE_Ok);
    auto& statements = precompiledStatements.get();
    if (!statements.queryTileRecord) {
        code = db->compileQuery(statements.queryTileRecord, "SELECT length(data), expiration FROM tiles WHERE id = ? LIMIT 1");
        if (code != TE_Ok) return code;
    }
    code = statements.queryTileRecord->clearBindings();
    if (code != TE_Ok) return code;
    code = statements.queryTileRecord->bindLong(1, ((int64_t)level<<58LL)|((int64_t)y<<29LL)|((int64_t)x));
    if (code != TE_Ok) return code;
    code = statements.queryTileRecord->moveToNext();
    if (code != TE_Ok) return code;
    int len = 0;
    code = statements.queryTileRecord->getInt(&len, 0);
    if (code != TE_Ok) return code;
    value->len = (std::size_t)len;
    code = statements.queryTileRecord->getLong(&value->expiration, 1);
    if (code != TE_Ok) return code;

    value->index = Point2<std::size_t>(x, y, level);
    return TE_Ok;
}

//private :
//TAK::Engine::Port::String path;
//std::vector<Raster::TileMatrix::TileMatrix::ZoomLevel> zoomLevels;
//int srid;
//Math::Point2<double> origin;
//Feature::Envelope2 bounds;
//std::size_t maxRecordSize;
//std::vector<std::pair<Math::Point2<std::size_t>, int64_t>> records;

ENGINE_API TAKErr TAK::Engine::Raster::TileMatrix::LruTileContainer_openOrCreate(TileContainerPtr &result, const char *name, const char *path, const TileMatrix *spec, const std::size_t limit, const float trimBuffer) NOTHROWS
{
    TAKErr code(TE_Ok);
    DatabasePtr db(nullptr, nullptr);

    for (std::size_t i = 0u; i < 2u; i++) {
        bool exists = false;
        IO_exists(&exists, path);
        DatabaseFactory_create(db, DatabaseInformation(path));
        if (!db) {
            break;
        }
        if (!exists) {
            // a tile matrix specification is required if creating
            if(!spec)
                return TE_InvalidArg;
            std::vector<TileMatrix::ZoomLevel> zoomLevels;
            TAK::Engine::Port::STLVectorAdapter<TileMatrix::ZoomLevel> zoomLevels_v(zoomLevels);
            code = spec->getZoomLevel(zoomLevels_v);
            TE_CHECKBREAK_CODE(code);
            TAK::Engine::Feature::Envelope2 bounds;
            code = spec->getBounds(&bounds);
            TE_CHECKBREAK_CODE(code);
            if (initDatabase(*db, name, spec->getSRID(), zoomLevels, Point2<double>(spec->getOriginX(), spec->getOriginY()), bounds) != TE_Ok)
                db.reset();
            break;
        } else if (verifySchema(*db) == TE_Ok) {
            // database exists and has good schema
            break;
        } else {
            if (!spec)
                return TE_InvalidArg;
            // database existed but was not valid, delete and loop to init
            db.reset();
            IO_delete(path);
        }
    }

    if (!db) return TE_Err;

    result = TileContainerPtr(new LRUTileContainer(std::move(db), limit, trimBuffer), Memory_deleter_const<TileContainer, LRUTileContainer>);
    return TE_Ok;
}

namespace
{
    TAKErr verifySchema(Database2& database) NOTHROWS
    {
        std::map<std::string, std::set<std::string>> schema;
        schema["metadata"].insert("key");
        schema["metadata"].insert("value_s");
        schema["metadata"].insert("value_i");
        schema["metadata"].insert("value_d");

        schema["tile_matrix"].insert("level");
        schema["tile_matrix"].insert("resolution");
        schema["tile_matrix"].insert("pixelSizeX");
        schema["tile_matrix"].insert("pixelSizeY");
        schema["tile_matrix"].insert("tileWidth");
        schema["tile_matrix"].insert("tileHeight");

        schema["tiles"].insert("x");
        schema["tiles"].insert("y");
        schema["tiles"].insert("z");
        schema["tiles"].insert("data");
        schema["tiles"].insert("expiration");
        schema["tiles"].insert("access");

        std::vector<TAK::Engine::Port::String> tableNames;
        TAK::Engine::Port::STLVectorAdapter<TAK::Engine::Port::String> tableNames_v(tableNames);
        Databases_getTableNames(tableNames_v, database);
        for(const auto &entry : schema)
        {
            if (tableNames.end() == std::find_if(tableNames.begin(), tableNames.end(), [&](const TAK::Engine::Port::String &s)
            {
                return TAK::Engine::Port::String_equal(s, entry.first.c_str());
            })) {

                return TE_InvalidArg;
            }

            std::vector<TAK::Engine::Port::String> columnNames;
            TAK::Engine::Port::STLVectorAdapter<TAK::Engine::Port::String> columnNames_v(columnNames);
            if (Databases_getColumnNames(columnNames_v, database, entry.first.c_str()) != TE_Ok)
                return TE_InvalidArg;

            for(const auto &c : entry.second) {
                if (columnNames.end() == std::find_if(columnNames.begin(), columnNames.end(), [&](const TAK::Engine::Port::String &s)
                {
                    return TAK::Engine::Port::String_equal(s, c.c_str());
                })) {

                    return TE_InvalidArg;
                }
            }
        }

        return TE_Ok;
    }
    TAKErr initDatabase(Database2& database, const char *name, const int srid, const std::vector<TileMatrix::ZoomLevel> &zoomLevels, const Point2<double> &origin, const TAK::Engine::Feature::Envelope2 &bounds) NOTHROWS
    {
        TAKErr code(TE_Ok);
        code = database.beginTransaction();
        TE_CHECKRETURN_CODE(code);
        code = database.execute("CREATE TABLE metadata(id INTEGER PRIMARY KEY AUTOINCREMENT, key TEXT, value_s TEXT, value_i INTEGER, value_d REAL)", nullptr, 0u);
        TE_CHECKRETURN_CODE(code);
        code = database.execute("CREATE TABLE tile_matrix(id INTEGER PRIMARY KEY AUTOINCREMENT, level INTEGER, resolution REAL, pixelSizeX REAL, pixelSizeY REAL, tileWidth INTEGER, tileHeight INTEGER)", nullptr, 0u);
        TE_CHECKRETURN_CODE(code);
        code = database.execute("CREATE TABLE tiles(id INTEGER PRIMARY KEY, x INTEGER, y INTEGER, z INTEGER, data BLOB, expiration INTEGER, access INTEGER)", nullptr, 0u);
        TE_CHECKRETURN_CODE(code);

        // populate metadata
        code = insertMetadata(database, "srid", srid);
        TE_CHECKRETURN_CODE(code);
        code = insertMetadata(database, "origin_x", origin.x);
        TE_CHECKRETURN_CODE(code);
        code = insertMetadata(database, "origin_y", origin.y);
        TE_CHECKRETURN_CODE(code);
        code = insertMetadata(database, "bounds_minX", bounds.minX);
        TE_CHECKRETURN_CODE(code);
        code = insertMetadata(database, "bounds_minY", bounds.minY);
        TE_CHECKRETURN_CODE(code);
        code = insertMetadata(database, "bounds_maxX", bounds.maxX);
        TE_CHECKRETURN_CODE(code);
        code = insertMetadata(database, "bounds_maxY", bounds.maxY);
        TE_CHECKRETURN_CODE(code);
        code = insertMetadata(database, "name", name);
        TE_CHECKRETURN_CODE(code);

        // populate tile_matrix
        {
            StatementPtr stmt(nullptr, nullptr);
            code = database.compileStatement(stmt, "INSERT INTO tile_matrix (level, resolution, pixelSizeX, pixelSizeY, tileWidth, tileHeight) VALUES(?, ?, ?, ?, ?, ?)");
            TE_CHECKRETURN_CODE(code);
            for (const auto& zoomLevel : zoomLevels) {
                code = stmt->clearBindings();
                TE_CHECKBREAK_CODE(code);
                code = stmt->bindInt(1, zoomLevel.level);
                TE_CHECKBREAK_CODE(code);
                code = stmt->bindDouble(2, zoomLevel.resolution);
                TE_CHECKBREAK_CODE(code);
                code = stmt->bindDouble(3, zoomLevel.pixelSizeX);
                TE_CHECKBREAK_CODE(code);
                code = stmt->bindDouble(4, zoomLevel.pixelSizeY);
                TE_CHECKBREAK_CODE(code);
                code = stmt->bindInt(5, zoomLevel.tileWidth);
                TE_CHECKBREAK_CODE(code);
                code = stmt->bindInt(6, zoomLevel.tileHeight);
                TE_CHECKBREAK_CODE(code);
                code = stmt->execute();
                TE_CHECKBREAK_CODE(code);
            }
            TE_CHECKRETURN_CODE(code);
        }

        code = database.setTransactionSuccessful();
        TE_CHECKRETURN_CODE(code);
        code = database.endTransaction();
        TE_CHECKRETURN_CODE(code);

        return TE_Ok;
    }

    std::size_t length(Database2& database) NOTHROWS
    {
        do {
            TAKErr code(TE_Ok);
            QueryPtr query(nullptr, nullptr);
            code = database.compileQuery(query, "SELECT (page_count - freelist_count) * page_size as size FROM pragma_page_count(), pragma_freelist_count(), pragma_page_size()");
            TE_CHECKBREAK_CODE(code);
            code = query->moveToNext();
            TE_CHECKBREAK_CODE(code);
            int value;
            code = query->getInt(&value, 0);
            TE_CHECKBREAK_CODE(code);
            return (std::size_t)value;
        } while (false);

        return 0LL;
    }

    TAKErr insertMetadata(Database2 &database, const char* key, const int value) NOTHROWS
    {
        TAKErr code(TE_Ok);
        StatementPtr stmt(nullptr, nullptr);
        code = database.compileStatement(stmt, "INSERT INTO metadata (key, value_i) VALUES(?, ?)");
        TE_CHECKRETURN_CODE(code);
        code = stmt->bindString(1, key);
        TE_CHECKRETURN_CODE(code);
        code = stmt->bindInt(2, value);
        TE_CHECKRETURN_CODE(code);
        code = stmt->execute();
        TE_CHECKRETURN_CODE(code);
        return code;
    }
    TAKErr insertMetadata(Database2& database, const char* key, const double value) NOTHROWS
    {
        TAKErr code(TE_Ok);
        StatementPtr stmt(nullptr, nullptr);
        code = database.compileStatement(stmt, "INSERT INTO metadata (key, value_d) VALUES(?, ?)");
        TE_CHECKRETURN_CODE(code);
        code = stmt->bindString(1, key);
        TE_CHECKRETURN_CODE(code);
        code = stmt->bindDouble(2, value);
        TE_CHECKRETURN_CODE(code);
        code = stmt->execute();
        TE_CHECKRETURN_CODE(code);
        return code;
    }
    TAKErr insertMetadata(Database2& database, const char* key, const char *value) NOTHROWS
    {
        TAKErr code(TE_Ok);
        StatementPtr stmt(nullptr, nullptr);
        code = database.compileStatement(stmt, "INSERT INTO metadata (key, value_s) VALUES(?, ?)");
        TE_CHECKRETURN_CODE(code);
        code = stmt->bindString(1, key);
        TE_CHECKRETURN_CODE(code);
        code = stmt->bindString(2, value);
        TE_CHECKRETURN_CODE(code);
        code = stmt->execute();
        TE_CHECKRETURN_CODE(code);
        return code;
    }
}
