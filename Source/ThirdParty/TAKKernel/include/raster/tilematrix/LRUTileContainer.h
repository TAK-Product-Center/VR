#ifndef TAK_ENGINE_RASTER_TILEMATRIX_LRUTILECONTAINER_H_INCLUDED
#define TAK_ENGINE_RASTER_TILEMATRIX_LRUTILECONTAINER_H_INCLUDED

#include <list>
#include <memory>
#include <set>
#include <vector>

#include "db/Database2.h"
#include "math/Statistics.h"
#include "raster/tilematrix/TileContainer.h"
#include "raster/tilematrix/TileContainerFactory.h"
#include "port/String.h"
#include "thread/Mutex.h"
#include "thread/Thread.h"
#include "util/BlockPoolAllocator.h"
#include "util/IO2.h"
#include "util/MemBuffer2.h"

namespace TAK {
    namespace Engine {
        namespace Raster {
            namespace TileMatrix {

                class ENGINE_API LRUTileContainer : public TileContainer
                {
                private :
                    struct Record
                    {
                        Math::Point2<std::size_t> index;
                        int64_t offset;
                        int64_t touch;
                        int64_t expiration;
                        std::size_t len;
                    };
                    struct PrecompiledStatements
                    {
                        Thread::ThreadID tid;
                        DB::QueryPtr queryTileData{ nullptr, nullptr };
                        DB::QueryPtr queryTileRecord{ nullptr, nullptr };
                        DB::StatementPtr insertTile{ nullptr, nullptr };
                        DB::StatementPtr updateTile{ nullptr, nullptr };
                        DB::StatementPtr deleteTiles{ nullptr, nullptr };
                        DB::StatementPtr updateAccess{ nullptr, nullptr };
                    };
                public :
                    LRUTileContainer(DB::DatabasePtr &&db, const std::size_t limit, const float trimBuffer) NOTHROWS;
                    ~LRUTileContainer() NOTHROWS;
                public: // TileContainer
                    Util::TAKErr isReadOnly(bool* value) NOTHROWS override;
                    Util::TAKErr setTile(const std::size_t level, const std::size_t x, const std::size_t y, const uint8_t* value, const std::size_t len, const int64_t expiration) NOTHROWS override;
                    Util::TAKErr setTile(const std::size_t level, const std::size_t x, const std::size_t y, const Renderer::Bitmap2* data, const int64_t expiration) NOTHROWS override;

                    bool hasTileExpirationMetadata() NOTHROWS override;
                    int64_t getTileExpiration(const std::size_t level, const std::size_t x, const std::size_t y) NOTHROWS override;
                public : // TileMatrix
                    const char* getName() const NOTHROWS override;
                    int getSRID() const NOTHROWS override;
                    Util::TAKErr getZoomLevel(Port::Collection<ZoomLevel>& value) const NOTHROWS override;
                    double getOriginX() const NOTHROWS override;
                    double getOriginY() const NOTHROWS override;
                    Util::TAKErr getTile(Renderer::BitmapPtr& result, const std::size_t zoom, const std::size_t x, const std::size_t y) NOTHROWS override;
                    Util::TAKErr getTileData(std::unique_ptr<const uint8_t, void (*)(const uint8_t*)>& value, std::size_t* len,
                                                     const std::size_t zoom, const std::size_t x, const std::size_t y) NOTHROWS override;
                    Util::TAKErr getBounds(Feature::Envelope2 *value) const NOTHROWS override;
                private :
                    Util::TAKErr getTileRecord(Record *value, const std::size_t level, const std::size_t x, const std::size_t y) NOTHROWS;
                private :
                    Port::String name;
                    bool readOnly;
                    std::vector<Raster::TileMatrix::TileMatrix::ZoomLevel> zoomLevels;
                    int srid;
                    Math::Point2<double> origin;
                    Feature::Envelope2 bounds;
                    Thread::Mutex mutex;
                    std::size_t limit;
                    float trimBuffer;
                    
                    DB::DatabasePtr db;
                    std::size_t poolTileDataMaxSize;
                    Util::BlockPoolAllocator tileDataAllocator;

                    struct {
                        PrecompiledStatements value[16u];
                        std::list<PrecompiledStatements> overflow;
                        PrecompiledStatements &get() NOTHROWS
                        {
                            const auto tid = Thread::Thread_currentThreadID();
                            const auto ThreadID_none = Thread::ThreadID();
                            for(std::size_t i = 0u; i < 16u; i++) {
                                if (ThreadID_none == value[i].tid)
                                    value[i].tid = tid;
                                if (tid == value[i].tid)
                                    return value[i];
                            }
                            for (auto it = overflow.rbegin(); it != overflow.rend(); it++) {
                                auto &o = *it;
                                if (tid == o.tid)
                                    return o;
                            }
                            overflow.push_back(PrecompiledStatements());
                            overflow.back().tid = tid;
                            return overflow.back();
                        }
                    } precompiledStatements;

                    friend ENGINE_API Util::TAKErr LruTileContainer_openOrCreate(TileContainerPtr &, const char *, const char *, const TileMatrix *, const std::size_t) NOTHROWS;

                    struct {
                        Math::Statistics getTileData;
                        Math::Statistics setTileData;
                        Math::Statistics trim;
                        Math::Statistics dblen;
                    } statistics;
                };

                ENGINE_API Util::TAKErr LruTileContainer_openOrCreate(TileContainerPtr &result, const char *name, const char *path, const TileMatrix *spec, const std::size_t limit, const float trimBuffer) NOTHROWS;

            }
        }  // namespace Raster
    }  // namespace Engine
}  // namespace TAK

#endif
