#ifndef TAK_ENGINE_RENDERER_ELEVATION_ELMGRTERRAINRENDERSERVICE_H_INCLUDED
#define TAK_ENGINE_RENDERER_ELEVATION_ELMGRTERRAINRENDERSERVICE_H_INCLUDED

#include <functional>

#include "core/MapSceneModel2.h"
#include "core/RenderContext.h"
#include "elevation/ElevationSource.h"
#include "feature/Envelope2.h"
#include "renderer/elevation/TerrainRenderService.h"
#include "renderer/core/ContentControl.h"
#include "renderer/core/TiledGlobe.h"
#include "thread/Monitor.h"
#include "thread/Thread.h"
#include "thread/ThreadPool.h"
#include "util/BlockPoolAllocator.h"
#include "util/Error.h"
#include "util/MemBuffer2.h"
#include "util/PoolAllocator.h"

namespace TAK {
    namespace Engine {
        namespace Renderer {
            namespace Elevation {
                class ENGINE_API ElMgrTerrainRenderService : public TerrainRenderService
                {
                private :
                    struct SseRecord
                    {
                        std::size_t level{0u};
                        double maxSse{std::numeric_limits<double>::max()};
                    };

                    struct QueryFilter
                    {
                        TAK::Engine::Core::MapSceneModel2 scene;
                        int srid {-1};
                        int sceneVersion {-1};
                        bool derive {false};
                        struct {
                            struct {
                                std::size_t level{0u};
                                double maxSse{std::numeric_limits<double>::max()};
                            } limit;
                            double serviceMax {10.0};
                        } sse;

                    };
                    class SourceRefresh;

                    typedef Core::TiledGlobe<std::shared_ptr<TerrainTile>, QueryFilter, SseRecord> TerrainTiledGlobe;
                private :
                    typedef std::function<bool(const std::shared_ptr<TerrainTiledGlobe::QuadNode> &a, const std::shared_ptr<TerrainTiledGlobe::QuadNode> &b)> FetchQueueSort;
                    typedef std::function<bool(const std::shared_ptr<TerrainTile> &a, const std::shared_ptr<TerrainTile> &b)> CollectResultsSort;
                public :
                    ElMgrTerrainRenderService() NOTHROWS;
                    ElMgrTerrainRenderService(TAK::Engine::Core::RenderContext &ctx) NOTHROWS;
                    ElMgrTerrainRenderService(TAK::Engine::Core::RenderContext &ctx, double maxSSE) NOTHROWS;
                    ElMgrTerrainRenderService(TAK::Engine::Core::RenderContext &ctx, const std::shared_ptr<TAK::Engine::Elevation::ElevationSource> &source, double maxSSE) NOTHROWS;
                private :
                    ElMgrTerrainRenderService(TAK::Engine::Core::RenderContext &ctx, const std::shared_ptr<TAK::Engine::Elevation::ElevationSource> &source, const bool defaultSource, double maxSSE) NOTHROWS;
                public :
                    ~ElMgrTerrainRenderService() NOTHROWS;
                public :
                    Util::TAKErr setElevationSource(const std::shared_ptr<TAK::Engine::Elevation::ElevationSource>& source) NOTHROWS;
                    Util::TAKErr getElevationSource(std::shared_ptr<TAK::Engine::Elevation::ElevationSource>& source, const bool defaultReturnsEmpty = true) NOTHROWS;
                public : // TerrainRenderService
                    int getTerrainVersion() const NOTHROWS;
                    double getMaxScreenSpaceError() const NOTHROWS;
                    /**
                     * Returns the mesh that was returned from the most recent
                     * call to
                     * `lock(Collection<shared_ptr<TerrainTile>>, MapSceneModel2, ...)`
                     *
                     * @param value
                     * @return
                     */
                    Util::TAKErr lock(Port::Collection<std::shared_ptr<const TerrainTile>> &value) NOTHROWS;
                    /**
                     *
                     * @param value
                     * @param view
                     * @param srid
                     * @param sceneVersion
                     * @param allowDerive   If `true` the service may derive
                     *                      high resolution tiles from lower
                     *                      resolution. This may result in a
                     *                      higher resolution mesh being
                     *                      returned if terrain data is not
                     *                      yet loaded for the entire extent of
                     *                      the scene.
                     * @return
                     */
                    Util::TAKErr lock(Port::Collection<std::shared_ptr<const TerrainTile>> &value, const TAK::Engine::Core::MapSceneModel2 &view, const int srid, const int sceneVersion, const bool allowDerive = false) NOTHROWS;
                private :
                    Util::TAKErr lock(Port::Collection<std::shared_ptr<const TerrainTile>> &value, const QueryFilter &filter) NOTHROWS;
                public :
                    Util::TAKErr unlock(Port::Collection<std::shared_ptr<const TerrainTile>> &tiles) NOTHROWS;
                    Util::TAKErr getElevation(double *value, const double latitude, const double longitude) const NOTHROWS;
                    Util::TAKErr start() NOTHROWS;
                    Util::TAKErr stop() NOTHROWS;
                private :
                    std::unique_ptr<TerrainTiledGlobe> globe;
                    mutable Thread::Monitor monitor { Thread::TEMT_Recursive };
                    //QueryFilter request;

                    std::unique_ptr<SourceRefresh> sourceRefresh;

                    struct {
                        std::shared_ptr<TAK::Engine::Elevation::ElevationSource> value;
                        bool isDefault;
                    } elevationSource;

                    bool sticky;

                    bool reset = false;
                    std::size_t numPosts;
                    /**
                     * Scalar adjustment applied to node level selection based
                     * on current camera.
                     */
                    double nodeSelectResolutionAdjustment;
                    /**
                     * Configurable parameter that specifies the maximum screen space error (SSE)
                     */
                    double maxScreenSpaceError;

                    Util::BlockPoolAllocator meshAllocator;
                    Util::BlockPoolAllocator polarMeshAllocator;
                    Util::PoolAllocator<TerrainTile> tileAllocator;

                    Util::MemBuffer2 edgeIndices;
                    Util::MemBuffer2 polarEdgeIndices;

                    TAK::Engine::Core::RenderContext &renderer;
                };

                ENGINE_API Util::TAKErr ElMgrTerrainRenderService_getDefaultLoResElevationSource(TAK::Engine::Elevation::ElevationSourcePtr &loresel) NOTHROWS;
            }
        }
    }
}

#endif

