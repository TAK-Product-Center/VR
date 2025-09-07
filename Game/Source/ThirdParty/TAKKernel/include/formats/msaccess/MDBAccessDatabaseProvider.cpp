#include "formats/msaccess/MDBAccessDatabaseProvider.h"
#include "util/URI.h"
#include "db/Query.h"
#include <map>
#include <vector>
#include <mdbtools.h>
#include <mdbsql.h>
#include <math.h>
#include <cstdlib>
#include <climits>

using namespace TAK::Engine::Util;
using namespace TAK::Engine::DB;

namespace {

    class MdbAccessQuery : public Query {
    private:
        MdbAccessQuery(MdbHandle *dbHandle, MdbTableDef *table, char **boundVals, int *boundLens) NOTHROWS;
    public:
        static TAKErr create(QueryPtr &query, MdbHandle *db, std::string &tableName) NOTHROWS;
        virtual ~MdbAccessQuery() NOTHROWS;

        virtual TAKErr getColumnIndex(std::size_t *value, const char *columnName) NOTHROWS override;
        virtual TAKErr getColumnName(const char **value, const std::size_t columnIndex) NOTHROWS override;
        virtual TAKErr getColumnCount(std::size_t *value) NOTHROWS override;
        virtual TAKErr getBlob(const uint8_t **value, std::size_t *len, const std::size_t columnIndex) NOTHROWS override;
        virtual TAKErr getString(const char **value, const std::size_t columnIndex) NOTHROWS override;
        virtual TAKErr getInt(int32_t *value, const std::size_t columnIndex) NOTHROWS override;
        virtual TAKErr getLong(int64_t *value, const std::size_t columnIndex) NOTHROWS override;
        virtual TAKErr getDouble(double *value, const std::size_t columnIndex) NOTHROWS override;
        virtual TAKErr getType(FieldType *value, const std::size_t columnIndex) NOTHROWS override;
        virtual TAKErr isNull(bool *value, const std::size_t columnIndex) NOTHROWS override;

        virtual TAK::Engine::Util::TAKErr moveToNext() NOTHROWS override;
        virtual TAKErr bindBlob(const std::size_t idx, const uint8_t *blob, const std::size_t size) NOTHROWS override;
        virtual TAKErr bindInt(const std::size_t idx, const int32_t value) NOTHROWS override;
        virtual TAKErr bindLong(const std::size_t idx, const int64_t value) NOTHROWS override;
        virtual TAKErr bindDouble(const std::size_t idx, const double value) NOTHROWS override;
        virtual TAKErr bindString(const std::size_t idx, const char *value) NOTHROWS override;
        virtual TAKErr bindNull(const std::size_t idx) NOTHROWS override;
        virtual TAKErr clearBindings() NOTHROWS override;

    private:
        int dispIndexToRealIndex(std::size_t dispIndex);
        void readOleFully(std::vector<uint8_t> *fullValue, MdbColumn *col);

        const static size_t OLE_READ_SIZE = MDB_BIND_SIZE * 64;

        MdbHandle *dbHandle;
        MdbTableDef *table;
        char **boundVals;
        int *boundLens;
        // DispIndex is "display index", the ordering of columns displayed in access UI;
        // this accounts for reordering/deletion/etc of columns after an initial creation from
        // what limited info is available.
        // Some existing parts of TAK engine depend on use of the display index rather than
        // raw column order or lookup by name (see FalconViewFeatureDataSource.cpp)
        std::map<std::string, int> colNameToDispIndex;
        std::map<std::size_t, int> colDispIndexToRealIndex;
        std::map<int, std::vector<uint8_t>> oleCache;
    };

    class MdbAccessDatabase : public Database2 {
    private:
        MdbAccessDatabase(MdbHandle *dbHandle) NOTHROWS;
    public:
        static TAKErr create(DatabasePtr &db, const char *filename) NOTHROWS;
        virtual ~MdbAccessDatabase() NOTHROWS override;

        virtual TAKErr execute(const char *sql, const char **args, const std::size_t len) NOTHROWS override;
        virtual TAKErr query(QueryPtr &query, const char *sql) NOTHROWS override;
        virtual TAKErr compileStatement(StatementPtr &stmt, const char *sql) NOTHROWS override;
        virtual TAKErr compileQuery(QueryPtr &query, const char *sql) NOTHROWS override;

        virtual TAKErr isReadOnly(bool *value) NOTHROWS override;
        virtual TAKErr getVersion(int *value) NOTHROWS override;
        virtual TAKErr setVersion(const int version) NOTHROWS override;

        virtual TAKErr beginTransaction() NOTHROWS override;
        virtual TAKErr setTransactionSuccessful() NOTHROWS override;
        virtual TAKErr endTransaction() NOTHROWS override;

        virtual TAKErr inTransaction(bool *value) NOTHROWS override;

        virtual TAKErr getErrorMessage(TAK::Engine::Port::String &value) NOTHROWS override;

    private:
        MdbHandle *dbHandle;

    };
}


MdbAccessQuery::MdbAccessQuery(MdbHandle *dbHandle, MdbTableDef *table, char **boundVals, int *boundLens) NOTHROWS :
        dbHandle(dbHandle), table(table), boundVals(boundVals), boundLens(boundLens), colNameToDispIndex(), colDispIndexToRealIndex(), oleCache()
{
    for (unsigned int i = 0; i < table->num_cols; ++i) {
        MdbColumn *col = (MdbColumn *)g_ptr_array_index(table->columns, i);
        colDispIndexToRealIndex[col->row_col_num] = i;
        colNameToDispIndex[col->name] = col->row_col_num;
    }
}

TAKErr MdbAccessQuery::create(QueryPtr &query, MdbHandle *db, std::string &tableName) NOTHROWS
{
    MdbTableDef *table = mdb_read_table_by_name(db, tableName.data(), MDB_TABLE);
    if (!table)
        return TE_Err;

    bool err = false;
    mdb_read_columns(table);
    mdb_rewind_table(table);

    char **boundVals = (char **)g_malloc0(table->num_cols * sizeof(char *));
    if (!boundVals) {
        mdb_free_tabledef(table);
        return TE_Err;
    }
    memset(boundVals, 0, sizeof(char *) * table->num_cols);

    int *boundLens = (int *)g_malloc(table->num_cols * sizeof(int));
    if (!boundLens) {
        mdb_free_tabledef(table);
        g_free(boundVals);
        return TE_Err;
    }

    for (unsigned int i = 0; i < table->num_cols; ++i) {
        boundVals[i] = (char *)g_malloc0(MDB_BIND_SIZE);
        if (!boundVals[i] || mdb_bind_column(table, i + 1, boundVals[i], boundLens + i) == -1) {
            err = true;
            break;
        }
    }
    if (err) {
        for (unsigned int i = 0; i < table->num_cols; ++i) {
            // MSVC wrongly reports the below as an uninitialised variable.
            #pragma warning(push)
            #pragma warning(disable: 6001)
            if (boundVals[i])
                g_free(boundVals[i]);
            #pragma warning(pop)
        }
        g_free(boundVals);
        g_free(boundLens);
        mdb_free_tabledef(table);
        return TE_Err;
    }

    query = QueryPtr(new MdbAccessQuery(db, table, boundVals, boundLens), Memory_deleter_const<Query, MdbAccessQuery>);
    return TE_Ok;
}

MdbAccessQuery::~MdbAccessQuery() NOTHROWS
{
    for (unsigned int i = 0; i < table->num_cols; ++i)
        g_free(boundVals[i]);
    g_free(boundVals);
    g_free(boundLens);
    mdb_free_tabledef(table);
    oleCache.clear();
}

TAKErr MdbAccessQuery::getColumnIndex(std::size_t *value, const char *columnName) NOTHROWS
{
    auto iter = colNameToDispIndex.find(columnName);
    if (iter == colNameToDispIndex.end()) {
        *value = -1;
    } else {
        *value = iter->second;
    }
    return TE_Ok;
}

TAKErr MdbAccessQuery::getColumnName(const char **value, const std::size_t columnIndex) NOTHROWS
{
    int realIndex = dispIndexToRealIndex(columnIndex);
    if (realIndex < 0)
        return TE_Err;

    MdbColumn *col = (MdbColumn *)g_ptr_array_index(table->columns, realIndex);
    *value = col->name;
    return TE_Ok;
}

TAKErr MdbAccessQuery::getColumnCount(std::size_t *value) NOTHROWS
{
    *value = table->num_cols;
    return TE_Ok;
}


int MdbAccessQuery::dispIndexToRealIndex(std::size_t dispIndex)
{
    auto iter = colDispIndexToRealIndex.find(dispIndex);
    if (iter == colDispIndexToRealIndex.end())
        return -1;
    return iter->second;
}

void MdbAccessQuery::readOleFully(std::vector<uint8_t> *fullValue, MdbColumn *col)
{
    char ole_ptr[MDB_MEMO_OVERHEAD];
    fullValue->reserve(OLE_READ_SIZE);

    size_t len;

    memcpy(ole_ptr, col->bind_ptr, MDB_MEMO_OVERHEAD);

    len = mdb_ole_read(dbHandle, col, ole_ptr, OLE_READ_SIZE);
    fullValue->insert(fullValue->end(), (uint8_t *)col->bind_ptr,
                      (uint8_t *)col->bind_ptr + len);

    while ((len = mdb_ole_read_next(dbHandle, col, ole_ptr)) != 0)
        fullValue->insert(fullValue->end(), (uint8_t *)col->bind_ptr,
                          (uint8_t *)col->bind_ptr + len);
}

TAKErr MdbAccessQuery::getBlob(const uint8_t **value, std::size_t *len, const std::size_t columnIndex) NOTHROWS
{
    int realIndex = dispIndexToRealIndex(columnIndex);
    if (realIndex < 0)
        return TE_Err;

    MdbColumn *col = (MdbColumn *)g_ptr_array_index(table->columns, realIndex);
    if (col->col_type == MDB_BINARY) {
        *value = (const uint8_t *)boundVals[realIndex];
        *len = boundLens[realIndex];
    } else if (col->col_type == MDB_OLE) {
        auto iter = oleCache.find(realIndex);
        if (iter == oleCache.end()) {
            std::vector<uint8_t> fullValue;
            readOleFully(&fullValue, col);

            auto insRet = oleCache.insert(std::pair<int, std::vector<uint8_t>>(realIndex, fullValue));
            iter = insRet.first;
        }
        *value = iter->second.data();
        *len = iter->second.size();
    } else {
        *value = NULL;
        *len = 0;
    }
    return TE_Ok;
}

TAKErr MdbAccessQuery::getString(const char **value, const std::size_t columnIndex) NOTHROWS
{
    int realIndex = dispIndexToRealIndex(columnIndex);
    if (realIndex < 0)
        return TE_Err;

    MdbColumn *col = (MdbColumn *)g_ptr_array_index(table->columns, realIndex);
    *value = "";
    if (col->col_type == MDB_MEMO || col->col_type == MDB_TEXT) {
        *value = boundVals[realIndex];
    }
    return TE_Ok;
}

TAKErr MdbAccessQuery::getInt(int32_t *value, const std::size_t columnIndex) NOTHROWS
{
    int realIndex = dispIndexToRealIndex(columnIndex);
    if (realIndex < 0)
        return TE_Err;

    MdbColumn *col = (MdbColumn *)g_ptr_array_index(table->columns, realIndex);
    int64_t v = 0;
    if (col->col_type == MDB_INT || col->col_type == MDB_LONGINT || col->col_type == MDB_COMPLEX || col->col_type == MDB_BOOL) {
        v = 0;
        char *end;
        v = strtoll(boundVals[realIndex], &end, 10);
        if (v == LONG_MIN || v == LONG_MAX || *end != '\0' || v < INT_MIN || v > INT_MAX)
            v = 0;
    }
    *value = (int)v;
    return TE_Ok;
}

TAKErr MdbAccessQuery::getLong(int64_t *value, const std::size_t columnIndex) NOTHROWS
{
    int realIndex = dispIndexToRealIndex(columnIndex);
    if (realIndex < 0)
        return TE_Err;

    MdbColumn *col = (MdbColumn *)g_ptr_array_index(table->columns, realIndex);
    int64_t v = 0;
    if (col->col_type == MDB_INT || col->col_type == MDB_LONGINT || col->col_type == MDB_COMPLEX) {
        v = 0;
        char *end;
        v = strtoll(boundVals[realIndex], &end, 10);
        if (v == LONG_MIN || v == LONG_MAX || *end != '\0')
            v = 0;
    }
    *value = v;
    return TE_Ok;
}

TAKErr MdbAccessQuery::getDouble(double *value, const std::size_t columnIndex) NOTHROWS
{
    int realIndex = dispIndexToRealIndex(columnIndex);
    if (realIndex < 0)
        return TE_Err;

    MdbColumn *col = (MdbColumn *)g_ptr_array_index(table->columns, realIndex);
    double d = 0;
    if (col->col_type == MDB_DOUBLE || col->col_type == MDB_FLOAT) {
        d = 0;
        char *end;
        d = strtod(boundVals[realIndex], &end);
        if (d == HUGE_VAL || d == -HUGE_VAL || *end != '\0')
            d = 0;
    }
    *value = d;
    return TE_Ok;
}

TAKErr MdbAccessQuery::getType(FieldType *value, const std::size_t columnIndex) NOTHROWS
{
    int realIndex = dispIndexToRealIndex(columnIndex);
    if (realIndex < 0)
        return TE_Err;

    MdbColumn *col = (MdbColumn *)g_ptr_array_index(table->columns, realIndex);
    switch (col->col_type) {
        case MDB_INT:
        case MDB_LONGINT:
        case MDB_COMPLEX:
        case MDB_BOOL:
            *value = FieldType::TEFT_Integer;
            break;
        case MDB_BINARY:
        case MDB_OLE:
            *value = FieldType::TEFT_Blob;
            break;
        case MDB_FLOAT:
        case MDB_DOUBLE:
            *value = FieldType::TEFT_Float;
            break;
        case MDB_TEXT:
        case MDB_MEMO:
            *value = FieldType::TEFT_String;
            break;
        case MDB_DATETIME:
        case MDB_BYTE:
        case MDB_NUMERIC:
        default:
            *value = FieldType::TEFT_Null;
            break;
    }
    return TE_Ok;
}

TAKErr MdbAccessQuery::isNull(bool *value, const std::size_t columnIndex) NOTHROWS
{
    FieldType t;
    getType(&t, columnIndex);
    *value = t == FieldType::TEFT_Null;
    return TE_Ok;
}

TAKErr MdbAccessQuery::moveToNext() NOTHROWS
{
    oleCache.clear();
    return mdb_fetch_row(table) ? TE_Ok : TE_Done;
}

TAKErr MdbAccessQuery::bindBlob(const std::size_t idx, const uint8_t *blob, const std::size_t size) NOTHROWS
{
    return TE_Ok;
}

TAKErr MdbAccessQuery::bindInt(const std::size_t idx, const int32_t value) NOTHROWS
{
    return TE_Ok;
}

TAKErr MdbAccessQuery::bindLong(const std::size_t idx, const int64_t value) NOTHROWS
{
    return TE_Ok;
}

TAKErr MdbAccessQuery::bindDouble(const std::size_t idx, const double value) NOTHROWS
{
    return TE_Ok;
}

TAKErr MdbAccessQuery::bindString(const std::size_t idx, const char *value) NOTHROWS
{
    return TE_Ok;
}

TAKErr MdbAccessQuery::bindNull(const std::size_t idx) NOTHROWS
{
    return TE_Ok;
}

TAKErr MdbAccessQuery::clearBindings() NOTHROWS
{
    return TE_Ok;
}



MdbAccessDatabase::MdbAccessDatabase(MdbHandle *dbHandle) NOTHROWS : dbHandle(dbHandle)
{
}

MdbAccessDatabase::~MdbAccessDatabase() NOTHROWS
{
    mdb_close(dbHandle);
    dbHandle = NULL;
}

TAKErr MdbAccessDatabase::create(TAK::Engine::DB::DatabasePtr &db, const char *filename) NOTHROWS
{
    MdbHandle *dbHandle = mdb_open(filename, MDB_NOFLAGS);
    if (!dbHandle)
        return TE_Err;
    mdb_set_boolean_fmt_numbers(dbHandle);
    db = DatabasePtr(new MdbAccessDatabase(dbHandle), Memory_deleter_const<Database2, MdbAccessDatabase>);
    return TE_Ok;
}

TAKErr MdbAccessDatabase::execute(const char *sql, const char **args, const std::size_t len) NOTHROWS
{
    // Unsupported
    return TE_Unsupported;
}

TAKErr MdbAccessDatabase::query(QueryPtr &query, const char *sql) NOTHROWS
{
    return compileQuery(query, sql);
}

TAKErr MdbAccessDatabase::compileStatement(StatementPtr &stmt, const char *sql) NOTHROWS
{
    // Unsupported
    return TE_Unsupported;
}

TAKErr MdbAccessDatabase::compileQuery(QueryPtr &query, const char *sql) NOTHROWS
{
    // Adapted from legacy Java impl
    const char *fromLoc;
    size_t len = strlen(sql);
    if (TAK::Engine::Port::String_strcasestr(sql, "select ") == sql &&
            (fromLoc = TAK::Engine::Port::String_strcasestr(sql, " from ")) != NULL) {
        // Extract table name
        const char *fromEnd = fromLoc + 6;
        const char *tabNameEnd = NULL;
        if (fromEnd - sql != len)
            // There was stuff after the from clause, presumably the table name.
            // Search for next space, indicating end of table name.
            tabNameEnd = TAK::Engine::Port::String_strcasestr(fromEnd, " ");
        if (tabNameEnd == NULL)
            tabNameEnd = sql + len;
        std::string tableName(fromEnd, tabNameEnd - fromEnd);

        // Get the table and convert to a cursor interface
        return MdbAccessQuery::create(query, dbHandle, tableName);
    }
    return TE_Err;
}

TAKErr MdbAccessDatabase::isReadOnly(bool *value) NOTHROWS
{
    *value = true;
    return TE_Ok;
}

TAKErr MdbAccessDatabase::getVersion(int *value) NOTHROWS
{
    *value = 0;
    return TE_Ok;
}

TAKErr MdbAccessDatabase::setVersion(const int version) NOTHROWS
{
    // Not supported, but return Ok based on prior Java-only impl
    return TE_Ok;
}

TAKErr MdbAccessDatabase::beginTransaction() NOTHROWS
{
    // Not supported, but return Ok based on prior Java-only impl
    return TE_Ok;
}

TAKErr MdbAccessDatabase::setTransactionSuccessful() NOTHROWS
{
    // Not supported, but return Ok based on prior Java-only impl
    return TE_Ok;
}

TAKErr MdbAccessDatabase::endTransaction() NOTHROWS
{
    // Not supported, but return Ok based on prior Java-only impl
    return TE_Ok;
}

TAKErr MdbAccessDatabase::inTransaction(bool *value) NOTHROWS
{
    *value = false;
    return TE_Ok;
}

TAKErr MdbAccessDatabase::getErrorMessage(TAK::Engine::Port::String &value) NOTHROWS
{
    value = NULL;
    return TE_Ok;
}




TAK::Engine::Formats::MsAccess::MDBAccessDatabaseProvider::MDBAccessDatabaseProvider() NOTHROWS
{

}

TAKErr TAK::Engine::Formats::MsAccess::MDBAccessDatabaseProvider::create(DatabasePtr &result, const DatabaseInformation &information) NOTHROWS
{
    TAKErr code(TE_Ok);
    Port::String curi;
    Port::String uriScheme, uriPath;
    code = information.getUri(curi);
    TE_CHECKRETURN_CODE(code);
    code = URI_parse(&uriScheme, NULL, NULL, NULL, NULL, &uriPath, NULL, NULL, curi);
    TE_CHECKRETURN_CODE(code);

    code = MdbAccessDatabase::create(result, uriPath);
    return code;
}

TAKErr TAK::Engine::Formats::MsAccess::MDBAccessDatabaseProvider::getType(const char **value) NOTHROWS
{
    *value = "TAK::Engine::Formats::MsAccess::MDBAccessDatabaseProvider";
    return TE_Ok;
}
