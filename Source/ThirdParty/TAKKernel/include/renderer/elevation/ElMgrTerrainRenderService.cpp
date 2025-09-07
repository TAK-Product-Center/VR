#include "renderer/elevation/ElMgrTerrainRenderService.h"

#include <algorithm>
#include <functional>
#include <memory>
#include <vector>
#include <cassert>
#include <climits>

#include "core/GeoPoint2.h"
#include "core/ProjectionFactory3.h"
#include "elevation/ElevationChunkFactory.h"
#include "elevation/ElevationManager.h"
#include "elevation/ElevationManagerElevationSource.h"
#include "elevation/ElevationSource.h"
#include "elevation/ElevationSourceManager.h"
#include "elevation/ElevationTileClient.h"
#include "elevation/MultiplexingElevationSource.h"
#include "elevation/MultiplexingElevationChunkCursor.h"
#include "elevation/ResolutionConstrainedElevationSource.h"
#include "elevation/TileMatrixElevationSource.h"
#include "elevation/VirtualCLODElevationSource.h"
#include "feature/GeometryTransformer.h"
#include "feature/Polygon2.h"
#include "formats/osmdroid/OSMDroidContainer.h"
#include "math/AABB.h"
#include "math/Frustum2.h"
#include "math/Mesh.h"
#include "math/Point2.h"
#include "math/Rectangle.h"
#include "model/Mesh.h"
#include "model/MeshBuilder.h"
#include "model/MeshTransformer.h"
#include "model/SceneBuilder.h"
#include "port/STLListAdapter.h"
#include "port/STLVectorAdapter.h"
#include "raster/osm/OSMUtils.h"
#include "raster/tilematrix/LRUTileContainer.h"
#include "raster/tilematrix/TileProxy.h"
#include "renderer/GLTexture2.h"
#include "renderer/HeightMap.h"
#include "renderer/Skirt.h"
#include "renderer/raster/TileClientControl.h"
#include "thread/Lock.h"
#include "thread/Mutex.h"
#include "util/ConfigOptions.h"
#include "util/BlockPoolAllocator.h"
#include "util/MathUtils.h"
#include "util/ProtocolHandler.h"

using namespace TAK::Engine::Renderer::Elevation;

using namespace TAK::Engine::Core;
using namespace TAK::Engine::Elevation;
using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Math;
using namespace TAK::Engine::Model;
using namespace TAK::Engine::Port;
using namespace TAK::Engine::Raster::TileMatrix;
using namespace TAK::Engine::Renderer;
using namespace TAK::Engine::Renderer::Core;
using namespace TAK::Engine::Thread;
using namespace TAK::Engine::Util;

using namespace atakmap::math;
using namespace atakmap::renderer;

#define NUM_TILE_FETCH_WORKERS 4u
#ifdef __ANDROID__
#define MAX_SSE 10.0
#else
#define MAX_SSE 8.0
#endif
#define MAX_LEVEL 21u
// observation is that total mesh size has an upper limit around 300 tiles, but
// is most frequently circa 150-200 tiles. queue limit of 225 would assume that
// we are loading circa 75% of the upper-limit mesh.
#define MAX_TILE_QUEUE_SIZE 225u
#define DERIVE_TILE_ENABLED true

#define NUM_POSTS 32u
#define NUM_POLAR_POSTS_LAT 8u
#define NUM_POLAR_POSTS_LNG 4u

namespace
{
    typedef TAK::Engine::Math::Point2<std::size_t> TileIndex;

    struct {
        std::map<std::string, std::weak_ptr<TileContainer>> value;
        Mutex mutex;
    } caches;

    //https://stackoverflow.com/questions/1903954/is-there-a-standard-sign-function-signum-sgn-in-c-c
    template <typename T>
    int sgn(T val)
    {
        return (T(0) < val) - (val < T(0));
    }

    template<class QuadNode>
    TileIndex getTileIndex(const QuadNode &tile)
    {
        const double tileSize = 180.0 / (double)(1<<tile.level);
        const double tileCenterX = (tile.bounds.wgs84.minX+tile.bounds.wgs84.maxX) / 2.0;
        const double tileCenterY = (tile.bounds.wgs84.minY+tile.bounds.wgs84.maxY) / 2.0;
        return TileIndex((std::size_t)((180.0 + tileCenterX) / tileSize), (std::size_t)((90.0 - tileCenterY) / tileSize), tile.level);
    };
    double computeDistanceSquared(const MapSceneModel2 &scene, const Envelope2 &aabbWGS84_) NOTHROWS
    {
        const int srid = scene.projection->getSpatialReferenceID();

        GeoPoint2 camlla;
        scene.projection->inverse(&camlla, scene.camera.location);
        // XXX - compute closest point on aabb
        Envelope2 aabbWGS84(aabbWGS84_);
        const double centroid = ((aabbWGS84.minX+aabbWGS84.maxX)/2.0);
        if(fabs(centroid-camlla.longitude) > 180.0 && (centroid*camlla.longitude < 0.0)) {
            // shift the AABB to the primary hemisphere
            const double hemiShift = (camlla.longitude >= 0.0) ? 360.0 : -360.0;
            aabbWGS84.minX += hemiShift;
            aabbWGS84.maxX += hemiShift;
        }

        GeoPoint2 closest(clamp(camlla.latitude, aabbWGS84.minY, aabbWGS84.maxY),
                          clamp(camlla.longitude, aabbWGS84.minX, aabbWGS84.maxX),
                          (aabbWGS84.maxZ + aabbWGS84.minZ + 500.0) / 2.0,
                          AltitudeReference::HAE);

        // compute distance to closet from camera
        TAK::Engine::Math::Point2<double> xyz;
        scene.projection->forward(&xyz, closest);
        xyz = Vector2_subtract(xyz, scene.camera.location);
        xyz.x *= scene.displayModel->projectionXToNominalMeters;
        xyz.y *= scene.displayModel->projectionYToNominalMeters;
        xyz.z *= scene.displayModel->projectionZToNominalMeters;
        return (xyz.x*xyz.x) + (xyz.y*xyz.y) + (xyz.z*xyz.z);
    }
    double computeSSE(const MapSceneModel2& scene, const double distance, const double geometricError) NOTHROWS
    {
        // project geometric error
        const double lambda = (scene.height / 2.0) / tan((scene.camera.fov / 2.0) / 180.0 * M_PI);
        return lambda * (geometricError / distance);
    }
    double computeSSE(const MapSceneModel2 &scene, const Envelope2 &aabbWGS84_, const double geometricError) NOTHROWS
    {
        return computeSSE(scene, sqrt(computeDistanceSquared(scene, aabbWGS84_)), geometricError);
    }
    bool MapSceneModel2_intersects(const MapSceneModel2 &scene, const Envelope2 &aabbWGS84) NOTHROWS
    {
        bool isects = false;
        MapSceneModel2_intersects(&isects, scene, aabbWGS84.minX, aabbWGS84.minY, aabbWGS84.minZ, aabbWGS84.maxX, aabbWGS84.maxY, aabbWGS84.maxZ);
        return isects;
    }
    std::size_t getNumEdgeVertices(const std::size_t numPostsLat, const std::size_t numPostsLng) NOTHROWS
    {
        // number of edge vertices is equal to perimeter length, plus one, to
        // close the linestring
        return ((numPostsLat-1u)*2u)+((numPostsLng-1u)*2u) + 1u;
    }
    TAKErr createEdgeIndices(MemBuffer2 &edgeIndices, const std::size_t numPostsLat, const std::size_t numPostsLng) NOTHROWS
    {
        // NOTE: edges are computed in CCW order

        TAKErr code(TE_Ok);
        // top edge (right-to-left), exclude last
        for(int i = static_cast<int>(numPostsLng)-1; i > 0; i--) {
            code = edgeIndices.put<uint16_t>((uint16_t) i);
            TE_CHECKBREAK_CODE(code);
        }
        TE_CHECKRETURN_CODE(code);
        // left edge (bottom-to-top), exclude last
        for(int i = 0; i < static_cast<int>(numPostsLat-1u); i++) {
            const std::size_t idx = (static_cast<std::size_t>(i)*numPostsLng);
            code = edgeIndices.put<uint16_t>((uint16_t)idx);
            TE_CHECKBREAK_CODE(code);
        }
        TE_CHECKRETURN_CODE(code);
        // bottom edge (left-to-right), exclude last
        for(int i = 0; i < static_cast<int>(numPostsLng-1u); i++) {
            const std::size_t idx = ((numPostsLat-1u)*numPostsLng)+static_cast<std::size_t>(i);
            code = edgeIndices.put<uint16_t>((uint16_t)idx);
            TE_CHECKBREAK_CODE(code);
        }
        TE_CHECKRETURN_CODE(code);
        // right edge (top-to-bottom), exclude last
        for(int i = static_cast<int>(numPostsLat-1); i > 0; i--) {
            code = edgeIndices.put<uint16_t>((uint16_t) ((i * numPostsLng) + (numPostsLng - 1)));
            TE_CHECKBREAK_CODE(code);
        }
        TE_CHECKRETURN_CODE(code);

        // close the loop by adding first-point-as-last
        code = edgeIndices.put<uint16_t>((uint16_t)(numPostsLng-1u));
        TE_CHECKRETURN_CODE(code);

        edgeIndices.flip();
        return code;
    }
    TAKErr createHeightmapMeshIndices(MemBuffer2 &indices, const MemBuffer2 &edgeIndices, const std::size_t numPostsLat, const std::size_t numPostsLng) NOTHROWS
    {
        TAKErr code(TE_Ok);

        const std::size_t numEdgeVertices = getNumEdgeVertices(numPostsLat, numPostsLng);

        std::size_t numSkirtIndices;
        code = Skirt_getNumOutputIndices(&numSkirtIndices, GL_TRIANGLE_STRIP, numEdgeVertices);
        const std::size_t numIndices = GLTexture2_getNumQuadMeshIndices(numPostsLng - 1u, numPostsLat - 1u)
                               + 2u // degenerate link to skirt
                               + numSkirtIndices;

        code = GLTexture2_createQuadMeshIndexBuffer(indices, GL_UNSIGNED_SHORT, numPostsLng - 1u, numPostsLat - 1u);
        TE_CHECKRETURN_CODE(code);

        const std::size_t skirtOffset = GLTexture2_getNumQuadMeshIndices(numPostsLng - 1u, numPostsLat - 1u);

        // insert the degenerate, last index of the mesh and first index
        // for the skirt
        code = indices.put<uint16_t>(*reinterpret_cast<const uint16_t *>(indices.get()+indices.position()-sizeof(uint16_t)));
        TE_CHECKRETURN_CODE(code);
        code = indices.put<uint16_t>(reinterpret_cast<const uint16_t *>(edgeIndices.get())[0u]);
        TE_CHECKRETURN_CODE(code);

        code = Skirt_createIndices<uint16_t>(
                indices,
                GL_TRIANGLE_STRIP,
                &edgeIndices,
                numEdgeVertices,
                static_cast<uint16_t>(numPostsLat*numPostsLng));
        TE_CHECKRETURN_CODE(code);

        return code;
    }

    bool intersects(const Frustum2& frustum, const TAK::Engine::Feature::Envelope2& aabbWCS, const int srid, const double lng) NOTHROWS;

    std::size_t getTerrainMeshSize(const std::size_t numPostsLat, const std::size_t numPostsLng) NOTHROWS
    {
        const std::size_t numEdgeVertices = getNumEdgeVertices(numPostsLat, numPostsLng);
        std::size_t numSkirtIndices;
        Skirt_getNumOutputIndices(&numSkirtIndices, GL_TRIANGLE_STRIP, numEdgeVertices);
        const std::size_t numIndices = GLTexture2_getNumQuadMeshIndices(numPostsLng - 1u, numPostsLat - 1u)
                               + 2u // degenerate link to skirt
                               + numSkirtIndices;

        const std::size_t ib_size = numIndices * sizeof(uint16_t);
        const std::size_t numPostVerts = numPostsLat * numPostsLng;
        const std::size_t numSkirtVerts = Skirt_getNumOutputVertices(numEdgeVertices);
        const std::size_t numVerts = (numPostVerts + numSkirtVerts);
        const std::size_t vb_size = numVerts *
                                        ((3u * sizeof(float)) + // position
                                         (3u * sizeof(float)) + // ecef position
                                         (4u*sizeof(int8_t)) + // normal
                                         sizeof(float)); // no data mask
        const std::size_t buf_size = ib_size + vb_size;
        return buf_size;
    }

    bool isPolarLoRes(const Envelope2 &aabb, const double threshold = 78.75) NOTHROWS
    {
        return std::min(fabs(aabb.minY), fabs(aabb.maxY)) >= threshold;
    }

    std::shared_ptr<ElevationSource> initLoResEl() NOTHROWS
    {
        TAK::Engine::DB::DatabasePtr lredb(nullptr, nullptr);
        do {
            // get path to the Low Res Elevation dataset
            TAK::Engine::Port::String appFiles;
            ConfigOptions_getOption(appFiles, "app.dirs.files");
#ifdef _MSC_VER
            if(!appFiles) {
                TAK::Engine::Port::String terrainCache;
                ConfigOptions_getOption(terrainCache, "elmgr.terrain-cache.path");
                if (terrainCache)
                    IO_getParentFile(appFiles, terrainCache);
            }
#endif
            if(!appFiles)
                break;
            const char *lreDbFilename = "loresel.v2.sqlite";
            std::ostringstream strm;
            strm << appFiles << '/' << lreDbFilename;
            TAK::Engine::Port::String assetPath = strm.str().c_str();
            if(!IO_exists(assetPath)) {
                // the file did not exist, try to load from assets
                DataInput2Ptr assetStream(nullptr, nullptr);
                if(ProtocolHandler_handleURI(assetStream, "asset:/loresel.sqlite.zip") != TE_Ok)
                    break;
                // copy the zip out of assets
                strm << ".zip";
                {
                    FileOutput2 assetZipFile;
                    assetZipFile.open(strm.str().c_str());
                    if (IO_copy(assetZipFile, *assetStream) != TE_Ok)
                        break;
                }
                // unzip
                if(IO_openZipEntry(assetStream, strm.str().c_str(), "loresel.sqlite") != TE_Ok)
                    break;
                {
                    FileOutput2 assetFile;
                    assetFile.open(assetPath);
                    if (IO_copy(assetFile, *assetStream) != TE_Ok)
                        break;
                }
                // delete the zip file
                IO_delete(strm.str().c_str());
            }
            // open the database
            if(TAK::Engine::DB::Databases_openDatabase(lredb,
                                                       assetPath,
                                                       true) != TE_Ok) {
                IO_delete(assetPath);
            }
        } while(false);
        if(lredb) {
            std::shared_ptr<TileMatrix> loresel(new LRUTileContainer(std::move(lredb), 0u, 0.f));
            return std::move(ElevationSourcePtr(new TileMatrixElevationSource("DTED", loresel, ElevationTileClient_info()), Memory_deleter_const<ElevationSource, TileMatrixElevationSource>));
        } else {
            return std::shared_ptr<ElevationSource>();
        }
    }
    std::shared_ptr<ElevationSource> createDefaultElevationSource() NOTHROWS
    {
        ElevationSourcePtr sourceImpl(nullptr, nullptr);

        struct {
            TAK::Engine::Port::String path {nullptr};
            int limit {0};
        } cache;
        ConfigOptions_getOption(cache.path, "elmgr.terrain-cache.path");
        cache.limit = ConfigOptions_getIntOptionOrDefault("elmgr.terrain-cache.limit", 0);

        HeightmapParams hmp;
        hmp.numPostsLng = NUM_POSTS;
        hmp.numPostsLat = NUM_POSTS;
        hmp.invertYAxis = true;
        hmp.bounds = Envelope2(-180.0, -90.0, NAN, 180.0, 90.0, NAN);
//        TileClientPtr elctr(new ElevationTileClient(hmp), Memory_deleter_const<TileClient, ElevationTileClient>);

        ElevationSourcePtr tiles(nullptr, nullptr);
        VirtualCLODElevationSource::Builder()
                .setPointSampler(false)
                .enableCaching(cache.path, cache.limit, false)
                .optimizeForTileGrid(4326, hmp)
            .build(tiles);
        constexpr auto minTerrainLevel = 8;

        std::vector<std::shared_ptr<ElevationSource>> sources;
        // hi-res
        std::shared_ptr<ElevationSource> hires(new ResolutionConstrainedElevationSource(
                std::move(tiles),
                atakmap::raster::osm::OSMUtils::mapnikTileResolution(minTerrainLevel),
                NAN));
        // short-circuit if config option is defined
        if(!ConfigOptions_getIntOptionOrDefault("elmgr.lores-dted-enabled", 1))
            return hires;
        sources.push_back(hires);

        // level 6/7
        ElevationSourcePtr point_tiles(nullptr, nullptr);
        VirtualCLODElevationSource::Builder()
                .setPointSampler(true)
                .enableCaching(cache.path, cache.limit, true)
                .optimizeForTileGrid(4326, hmp)
            .build(point_tiles);
        sources.push_back(std::shared_ptr<ElevationSource>(new ResolutionConstrainedElevationSource(
                std::move(point_tiles),
                atakmap::raster::osm::OSMUtils::mapnikTileResolution(minTerrainLevel-2),
                atakmap::raster::osm::OSMUtils::mapnikTileResolution(minTerrainLevel-1))));

        ElevationSourcePtr loresel(nullptr, nullptr);
        ElMgrTerrainRenderService_getDefaultLoResElevationSource(loresel);
        if(loresel) {
            sources.push_back(std::shared_ptr<ElevationSource>(new ResolutionConstrainedElevationSource(
                    std::move(loresel),
                    NAN,
                    atakmap::raster::osm::OSMUtils::mapnikTileResolution(minTerrainLevel-3))));
        }
        return ElevationSourcePtr(
                new MultiplexingElevationSource("Default", sources.data(), sources.size()),
                Memory_deleter_const<ElevationSource, MultiplexingElevationSource>);
    }

    template<class T>
    void updateParentZBounds(T &node) NOTHROWS
    {
        std::shared_ptr<T> parent(node.parent.lock());
        if (parent) {
            const bool updated = (node.bounds.wgs84.minZ < parent->bounds.wgs84.minZ) || (node.bounds.wgs84.maxZ > parent->bounds.wgs84.maxZ);
            if (node.bounds.wgs84.minZ < parent->bounds.wgs84.minZ) {
                parent->bounds.wgs84.minZ = node.bounds.wgs84.minZ;
                parent->bounds.proj.minZ = node.bounds.proj.minZ;
            }
            if (node.bounds.wgs84.maxZ > parent->bounds.wgs84.maxZ) {
                parent->bounds.wgs84.maxZ = node.bounds.wgs84.maxZ;
                parent->bounds.proj.maxZ = node.bounds.proj.maxZ;
            }

            if (updated)
                updateParentZBounds(*parent);
        }
    }

    template<class QueryFilter, class QuadNode, bool UseParentBounds>
    bool shouldFetch(const QueryFilter &filter, const QuadNode &node) NOTHROWS
    {
        auto bounds = node.bounds.wgs84;
        if constexpr(UseParentBounds)
        {
            auto parent(node.parent.lock());
            if(parent)
                bounds = parent->bounds.wgs84;
        }

        GeoPoint2 focus;
        filter.scene.projection->inverse(&focus, filter.scene.camera.target);
        Matrix2 m(filter.scene.camera.projection);
        m.concatenate(filter.scene.camera.modelView);
        Frustum2 frustum(m);
        // compute AABB in WCS and check for intersection with the frustum
        TAK::Engine::Feature::Envelope2 aabbWCS(bounds);
        const int srid = filter.scene.projection->getSpatialReferenceID();
        TAK::Engine::Feature::GeometryTransformer_transform(&aabbWCS, aabbWCS, 4326, srid);
        return intersects(frustum, aabbWCS, srid, focus.longitude);
    }
}

class ElMgrTerrainRenderService::SourceRefresh : public ElevationSource::OnContentChangedListener
{
public :
    SourceRefresh(ElMgrTerrainRenderService &service) NOTHROWS;
public : // ElevationSource::OnContentChangedListener
    TAKErr onContentChanged(const ElevationSource &source) NOTHROWS override;
private :
    ElMgrTerrainRenderService &service;
};

namespace
{
    TAKErr fetch(std::shared_ptr<TerrainTile> &value, ElevationSource &elsrc, double *els, const double resolution, const Envelope2 &mbb, const int srid, const std::size_t numPostsLat, const std::size_t numPostsLng, const MemBuffer2 &edgeIndices, const bool fetchEl, BlockPoolAllocator &allocator, PoolAllocator<TerrainTile> &tileAllocator) NOTHROWS;
    TAKErr derive(std::shared_ptr<TerrainTile> &value, const Envelope2 &mbb, const int srid, const std::size_t numPostsLat, const std::size_t numPostsLng, const MemBuffer2 &edgeIndices, const TerrainTile &deriveFrom, BlockPoolAllocator &allocator, PoolAllocator<TerrainTile> &tileAllocator) NOTHROWS;

    struct TerrainTileBuilder
    {
    public :
        Envelope2 mbb;
        std::size_t numPostsLat;
        std::size_t numPostsLng;
        double cellHeightLat;
        double cellWidthLng;
        double localOriginX;
        double localOriginY;
        double localOriginZ;
        std::size_t numEdgeVertices;
        std::size_t numSkirtIndices;
        std::size_t numIndices;
        std::size_t skirtOffset;
        std::size_t numPostVerts;
        std::size_t numSkirtVerts;
        std::size_t numVerts;
        double* els{ nullptr };
        VertexDataLayout layout;
        const MemBuffer2 &edgeIndices_;
    public :
        TerrainTileBuilder(const Envelope2& mbb, const std::size_t numPostsLat, const std::size_t numPostsLng, const MemBuffer2 &edgeIndices) NOTHROWS;
    public :
        TAKErr build(std::shared_ptr<TerrainTile>& value, const float skirtHeight, BlockPoolAllocator& allocator, PoolAllocator<TerrainTile>& tileAllocator) NOTHROWS;
    private :
        virtual TAKErr fillPositions(MemBuffer2& positions, MemBuffer2& noDataMask, bool& hasData, double& minEl, double& maxEl) NOTHROWS = 0;
        virtual TAKErr generateNormals(MemBuffer2& normals, const MemBuffer2& edgeIndices, const bool hasData) NOTHROWS = 0;
    };

    struct FetchTileBuilder : public TerrainTileBuilder
    {
    public :
        double* els;
        double resolution;
        ElevationSource &elevationSource;
    public :
        FetchTileBuilder(ElevationSource &elevationSource, const Envelope2& mbb, const std::size_t numPostsLat, const std::size_t numPostsLng, const MemBuffer2 &edgeIndices, double *els, const double resolution) NOTHROWS;
    private :
        virtual TAKErr fillPositions(MemBuffer2& positions, MemBuffer2& noDataMask, bool& hasData, double& minEl, double& maxEl) NOTHROWS override;
        virtual TAKErr generateNormals(MemBuffer2& normals, const MemBuffer2& edgeIndices, const bool hasData) NOTHROWS override;
    };

    struct NoDataTileBuilder : public TerrainTileBuilder
    {
    public :
        NoDataTileBuilder(const Envelope2& mbb, const std::size_t numPostsLat, const std::size_t numPostsLng, const MemBuffer2 &edgeIndices) NOTHROWS;
    private :
        virtual TAKErr fillPositions(MemBuffer2& positions, MemBuffer2& noDataMask, bool& hasData, double& minEl, double& maxEl) NOTHROWS override;
        virtual TAKErr generateNormals(MemBuffer2& normals, const MemBuffer2& edgeIndices, const bool hasData) NOTHROWS override;
    };

    struct DeriveTileBuilder : public TerrainTileBuilder
    {
    public :
        DeriveTileBuilder(const Envelope2& mbb, const std::size_t numPostsLat, const std::size_t numPostsLng, const MemBuffer2& edgeIndices, const TerrainTile& deriveFrom) NOTHROWS;
    private :
        virtual TAKErr fillPositions(MemBuffer2& positions, MemBuffer2& noDataMask, bool& hasData, double& minEl, double& maxEl) NOTHROWS override;
        virtual TAKErr generateNormals(MemBuffer2& normals, const MemBuffer2& edgeIndices, const bool hasData) NOTHROWS override;
    public :
        const TerrainTile& deriveFrom;
    };
}

ElMgrTerrainRenderService::ElMgrTerrainRenderService(RenderContext &renderer_) NOTHROWS : ElMgrTerrainRenderService(renderer_, MAX_SSE){}

ElMgrTerrainRenderService::ElMgrTerrainRenderService(RenderContext& renderer_, double maxSSE) NOTHROWS :
    ElMgrTerrainRenderService(renderer_, createDefaultElevationSource(), true, maxSSE)
{}
ElMgrTerrainRenderService::ElMgrTerrainRenderService(RenderContext &renderer_, const std::shared_ptr<ElevationSource> &source, double maxSSE) NOTHROWS :
    ElMgrTerrainRenderService(renderer_, createDefaultElevationSource(), false, maxSSE)
{}
ElMgrTerrainRenderService::ElMgrTerrainRenderService(RenderContext &renderer_, const std::shared_ptr<ElevationSource> &source, const bool defaultSource, double maxSSE) NOTHROWS :
    renderer(renderer_),
    globe(new TerrainTiledGlobe(TiledGlobe_matrix4326<TerrainTiledGlobe::TileMatrix>(MAX_LEVEL), MAX_TILE_QUEUE_SIZE, NUM_TILE_FETCH_WORKERS)),
    reset(false),
    numPosts(32),
    nodeSelectResolutionAdjustment(8.0),
    sticky(true),
    meshAllocator(getTerrainMeshSize(numPosts, numPosts), 512),
    polarMeshAllocator(getTerrainMeshSize(NUM_POLAR_POSTS_LAT, NUM_POLAR_POSTS_LNG), 256),
    tileAllocator(256),
    edgeIndices(getNumEdgeVertices(numPosts, numPosts)*sizeof(uint16_t)),
    polarEdgeIndices(getNumEdgeVertices(NUM_POLAR_POSTS_LAT, NUM_POLAR_POSTS_LNG)*sizeof(uint16_t))
{
    globe->shouldRecurse = [](SseRecord &sseRecord, const QueryFilter &s, const TerrainTiledGlobe::QuadNode &n, const bool self)
    {
        if(self) {
            return n.level+1u == s.sse.limit.level;
        }
        if(n.level >= s.sse.limit.level)
            return false;

        double reslat = 1.0;
        // if non-planar projection, start adapting the geometric error per
        // the actual resolution at the edge of the tile closest to the
        // equator
        if(s.scene.displayModel->earth->getGeomClass() != GeometryModel2::PLANE) {
            if(isPolarLoRes(n.bounds.wgs84, 84.375))
                return false;
            // fudge the value we're feeding into the resolution
            // computation by doubling the distance (in degrees latitude)
            // from the centroid to the respective pole
            if(isPolarLoRes(n.bounds.wgs84))
                reslat = 1.5;
        }
        const double geometricError = atakmap::raster::osm::OSMUtils::mapnikTileResolution((int)n.level, 0.0);
        const double sse = computeSSE(s.scene, n.bounds.wgs84, geometricError) / reslat;
        bool recurse = (sse > s.sse.serviceMax);

        bool isect = MapSceneModel2_intersects(s.scene, n.bounds.wgs84);
        // exclude beyond far plane
        if (computeDistanceSquared(s.scene, n.bounds.wgs84) > (s.scene.camera.farMeters*s.scene.camera.farMeters))
            isect = false;

        if(isect && !recurse) {
            // this is a terminal node, update the SSE record
            if (n.level > sseRecord.level || (n.level == sseRecord.level && sse < sseRecord.maxSse)) {
                sseRecord.level = n.level;
                sseRecord.maxSse = sse;
            }

            const auto dlevel = (n.level < s.sse.limit.level) ? (s.sse.limit.level-n.level) : 0u;
            if (dlevel == 1u) {
                // if adjacent to the max zoom, fudge up the SSE to the max observed
                recurse = (sse > s.sse.limit.maxSse);
            }
        }
        // only recurse on SSE and intersect frustum
        return recurse&&isect;
    };
    globe->fetchTileData = [&](const TerrainTiledGlobe::QuadNode &node, const TerrainTiledGlobe::CollectHints &hints)
    {
        thread_local std::vector<double> els((this->numPosts+2u)*(this->numPosts+2u)*3u);
        auto fetchSource = this->elevationSource.value;
        const bool polarLoRes = isPolarLoRes(node.bounds.wgs84);
        std::shared_ptr<TerrainTile> tile;
        fetch(tile,
              *fetchSource,
              els.data(),
              atakmap::raster::osm::OSMUtils::mapnikTileResolution((int)node.level),
              node.bounds.wgs84,
              4326/*hints.srid*/,
              polarLoRes ? NUM_POLAR_POSTS_LAT : this->numPosts,
              polarLoRes ? NUM_POLAR_POSTS_LNG : this->numPosts,
              polarLoRes ? this->polarEdgeIndices : this->edgeIndices,
              hints.fetch && !!fetchSource,
              polarLoRes ? this->polarMeshAllocator : this->meshAllocator,
              this->tileAllocator);
        return tile;
    };
    globe->deriveTileData = [&](const TerrainTiledGlobe::QuadNode &node, const TerrainTiledGlobe::CollectHints &hints, const TerrainTiledGlobe::DeriveSource &from)
    {
        const bool polarLoRes = isPolarLoRes(node.bounds.wgs84);
        std::shared_ptr<TerrainTile> derivedTile;
        ::derive(derivedTile,
                 node.bounds.wgs84,
                 4326/*hints.srid*/,
                 polarLoRes ? NUM_POLAR_POSTS_LAT : this->numPosts,
                 polarLoRes ? NUM_POLAR_POSTS_LNG : this->numPosts,
                 polarLoRes ? this->polarEdgeIndices : this->edgeIndices,
                 *from.tile,
                 polarLoRes ? this->polarMeshAllocator : this->meshAllocator,
                 this->tileAllocator);
        return derivedTile;
    };
    globe->emptyTileData = [&](const TerrainTiledGlobe::QuadNode &node)
    {
        const bool polarLoRes = isPolarLoRes(node.bounds.wgs84);
        std::shared_ptr<TerrainTile> tile;
        NoDataTileBuilder ttb(node.bounds.wgs84,
                              polarLoRes ? NUM_POLAR_POSTS_LAT : this->numPosts,
                              polarLoRes ? NUM_POLAR_POSTS_LNG : this->numPosts,
                              polarLoRes ? this->polarEdgeIndices : this->edgeIndices);
        ttb.build(tile, 500.0, polarLoRes ? this->polarMeshAllocator : this->meshAllocator, this->tileAllocator);
        return tile;
    };
    globe->hasValue = [](const std::shared_ptr<TerrainTile> &value) { return !!value; };
    globe->shouldCollect = ::shouldFetch<QueryFilter, TerrainTiledGlobe::QuadNode, false>;
    globe->shouldFetch = ::shouldFetch<QueryFilter, TerrainTiledGlobe::QuadNode, true>;
    globe->getValue = [](TerrainTiledGlobe::QuadNode &node){ return std::atomic_load(&node.tile); };
    globe->setValue = [](TerrainTiledGlobe::QuadNode &node, const std::shared_ptr<TerrainTile> &value, const bool derived)
    {
        std::atomic_store(&node.tile, value);
        if (value->hasData) {
            node.bounds.wgs84.minZ = value->aabb_wgs84.minZ;
            node.bounds.wgs84.maxZ = value->aabb_wgs84.maxZ;
            node.bounds.proj.minZ = node.bounds.wgs84.minZ;
            node.bounds.proj.maxZ = node.bounds.wgs84.maxZ;
            if(!derived)
                updateParentZBounds(node);
        }

        if(!derived)
            value->aabb_wgs84 = node.bounds.wgs84;
    };
    globe->clearValue = [](std::shared_ptr<TerrainTile> &value) { value.reset(); };
#if 1
    globe->fillRequest = [&](SseRecord &sse, const TerrainTiledGlobe::CollectHints &hints_, const QueryFilter &filter, const std::function<void(const std::shared_ptr<TerrainTiledGlobe::QuadNode> &)> &collector)
    {
        auto fetch = filter;
        auto hints = hints_;

        // recurse nodes to determine nominal SSE
        hints.fetch = true;
        hints.cull = false;
        hints.checkVersion = false;

        GeoPoint2 sceneFocusLLA;
        fetch.scene.projection->inverse(&sceneFocusLLA, fetch.scene.camera.target);
        MapSceneModel2 nadirScene(
                fetch.scene.displayDpi,
                fetch.scene.width, fetch.scene.height,
                fetch.scene.projection->getSpatialReferenceID(),
                sceneFocusLLA,
                fetch.scene.focusX, fetch.scene.focusY,
                fetch.scene.camera.azimuth,
                0.0,
                fetch.scene.gsd);
        struct {
            std::vector<std::shared_ptr<TerrainTiledGlobe::QuadNode>> filtered;
            std::vector<std::shared_ptr<TerrainTiledGlobe::QuadNode>> unfiltered;
        } collectedTiles;
        globe->collectRequestResults(sse, hints, fetch,
            [&collectedTiles, &nadirScene](const std::shared_ptr<TerrainTiledGlobe::QuadNode> &tile)
            {
                if(MapSceneModel2_intersects(nadirScene, tile->bounds.wgs84))
                    collectedTiles.filtered.push_back(tile);
                else // not nadir or does not intersect
                    collectedTiles.unfiltered.push_back(tile);
            });

        // configure the fetching parameters for the terminal level/SSE
#define te_mix(a, b, wt) \
    ((double)(a) + (((double)(b)-(double)(a))*(double)(wt)))
        constexpr double threshold = 40.0;
        const double weight = 1.0 - (std::min(fabs(fetch.scene.camera.elevation), threshold) / threshold);
        fetch.sse.limit.level = (std::size_t)te_mix(sse.level, fetch.sse.limit.level, weight);
        fetch.sse.limit.maxSse = te_mix(std::min(sse.maxSse, this->getMaxScreenSpaceError()), fetch.sse.limit.maxSse, weight);
        fetch.sse.limit.discover = false;
#undef te_mix

        // filter any remaining nodes
        const std::size_t limit = collectedTiles.filtered.size();
        if(limit) {

            // highest zoom > row major
            struct TileIndex_LT {
                bool operator()(const TileIndex &a, const TileIndex &b) const {
                    if(a.z > b.z)
                        return true;
                    else if(a.z < b.z)
                        return false;
                    else if(a.y < b.y)
                        return true;
                    else if(a.y > b.y)
                        return false;
                    else
                        return a.x < b.x;
                }
            } compTileIndex;
            std::set<TileIndex, TileIndex_LT> collectedTileIndices(compTileIndex);
            std::map<TileIndex, std::shared_ptr<TerrainTiledGlobe::QuadNode>, TileIndex_LT> remaining(compTileIndex);

            auto fetchNeighbors = fetch;
            for (std::size_t i = 0; i < limit; i++) {
                SseRecord ignoreSse;
                collectedTiles.filtered[i]->collect(ignoreSse, hints, fetchNeighbors,
                                                 TerrainTiledGlobe::DeriveSource(),
                [&collectedTiles, &remaining, &fetchNeighbors](const std::shared_ptr<TerrainTiledGlobe::QuadNode> &tile)
                {
                    if(MapSceneModel2_intersects(fetchNeighbors.scene, tile->bounds.wgs84)){
                        // tile is in view, mark it as remaining to do adjacent neighbor processing
                        remaining[getTileIndex(*tile)] = tile;
                    } else {
                        // tile is now out of view
                        collectedTiles.unfiltered.push_back(tile);
                    }
                });
            }
            collectedTiles.filtered.clear();

            auto tt = Platform_systime_millis();
            if(!remaining.empty()) {
                // transfer all tiles at the max zoom and adjacent zoom into the collected tiles
                // list
                const auto maxCollectedZoom = remaining.begin()->first.z;
                while(!remaining.empty()) {
                    auto it = remaining.begin();
                    if((maxCollectedZoom-it->first.z) > 1u)
                        break;
                    collectedTiles.unfiltered.push_back(it->second);
                    collectedTileIndices.insert(it->first);
                    remaining.erase(it);
                }

                // skip post-processing on extremely low resolution tiles
                constexpr unsigned loResCutoffDelta = 7u;
                while(!remaining.empty()) {
                    auto it = remaining.rbegin();
                    if((maxCollectedZoom-it->first.z) < loResCutoffDelta)
                        break;
                    collectedTiles.unfiltered.push_back(it->second);
                    remaining.erase(it->first);
                }

                // emit/recurse all nodes adjacent to terminal
                while (!remaining.empty()) {
                    auto it = remaining.begin();
                    // find all neighbors
                    const auto tileIndex = it->first;
                    std::size_t neighborZoom = maxCollectedZoom;
                    bool hasZoomNeighbors = false;
                    assert(neighborZoom > tileIndex.z);
                    while(neighborZoom > tileIndex.z && !hasZoomNeighbors) {
                        const auto zShift = (neighborZoom-tileIndex.z);
                        std::size_t neighborLeft = (tileIndex.x == 0u) ? (1u << neighborZoom) - 1u : (tileIndex.x<<zShift) - 1u;
                        std::size_t neighborRight = (tileIndex.x + 1u) << zShift;
                        std::size_t neighborTop = (tileIndex.y == 0u) ? (1u << neighborZoom) - 1u : (tileIndex.y<<zShift) - 1u;
                        std::size_t neighborBottom = (tileIndex.y + 1u) << zShift;

                        const auto noCollectedTileIndex = collectedTileIndices.end();
                        // search for any neighbors
                        // left/right edges (UL/UR exclusive)
                        for(std::size_t i = (tileIndex.y<<zShift); i < neighborBottom; i++) {
                            if(hasZoomNeighbors) break;
                            hasZoomNeighbors |= (collectedTileIndices.find(TileIndex(neighborLeft, i, neighborZoom)) != noCollectedTileIndex) ||
                                                (collectedTileIndices.find(TileIndex(neighborRight, i, neighborZoom)) != noCollectedTileIndex);
                        }
                        // top/bottom edges (UL/BL exclusive)
                        for(std::size_t i = (tileIndex.x<<zShift); i < neighborRight; i++) {
                            if(hasZoomNeighbors) break;
                            hasZoomNeighbors |= (collectedTileIndices.find(TileIndex(i, neighborTop, neighborZoom)) != noCollectedTileIndex) ||
                                                (collectedTileIndices.find(TileIndex(i, neighborBottom, neighborZoom)) != noCollectedTileIndex);
                        }
                        hasZoomNeighbors |= (collectedTileIndices.find(TileIndex(neighborLeft, neighborTop, neighborZoom)) != noCollectedTileIndex);
                        neighborZoom--;
                    }

                    if(!hasZoomNeighbors || neighborZoom == tileIndex.z) {
                        // an zoom adjacent neighbor exists or there is no neighbor transfer as-is
                        collectedTiles.unfiltered.push_back(it->second);
                        collectedTileIndices.insert(it->first);
                    } else {
                        // force a single recursion
                        SseRecord ignoreSse;
                        const auto terminalZoom = neighborZoom;
                        auto forceRecurse = fetchNeighbors;
                        forceRecurse.sse.limit.level = tileIndex.z+1u;
                        forceRecurse.sse.serviceMax = 0.0;
                        it->second->collect(ignoreSse, hints, forceRecurse,
                                                            TerrainTiledGlobe::DeriveSource(),
                            [&collectedTiles, &collectedTileIndices, &remaining, &fetchNeighbors, terminalZoom](const std::shared_ptr<TerrainTiledGlobe::QuadNode> &tile)
                            {
                                const auto tileIndex = getTileIndex(*tile);
                                if(tileIndex.z < terminalZoom && MapSceneModel2_intersects(fetchNeighbors.scene, tile->bounds.wgs84)) {
                                    // tile is in view, mark it as remaining to do adjacent neighbor processing
                                    remaining[tileIndex] = tile;
                                } else {
                                    // tile is at terminal zoom or out of view
                                    collectedTiles.unfiltered.push_back(tile);
                                    collectedTileIndices.insert(tileIndex);
                                }
                            });
                    }
                    remaining.erase(it);
                }
            }
            auto ee = Platform_systime_millis();
            //Logger_log(TELL_Info, "elmgr adjacent neighbor adjust in %ums", (unsigned)(ee-tt));

        }

        // recurse over all terminal nodes with scene SSE for final tile list
        hints.fetch = true;
        hints.cull = true;
        hints.checkVersion = true;
        for(const auto &node : collectedTiles.unfiltered) {
            SseRecord ignoreSse;
            node->collect(ignoreSse, hints, fetch, TerrainTiledGlobe::DeriveSource(), collector);
        }
        collectedTiles.unfiltered.clear();

        return true;
    };
#endif
    globe->sortFetchQueue = [&](const QueryFilter &queryFilter)
    {
        GeoPoint2 cam;
        queryFilter.scene.projection->inverse(&cam, queryFilter.scene.camera.location);

        // NOTE: sort into LIFO order
        return [cam](const std::shared_ptr<TerrainTiledGlobe::QuadNode> &a, const std::shared_ptr<TerrainTiledGlobe::QuadNode> &b)
        {
            // bias fetch of non-derived tiles
            if(a->derived.value && !b->derived.value)
                return false;
            else if(!a->derived.value && b->derived.value)
                return true;

            // sort based on distance from camera
            double calat = (a->bounds.wgs84.minY+a->bounds.wgs84.maxY)/2.0;
            double calng = (a->bounds.wgs84.minX+a->bounds.wgs84.maxX)/2.0;
            if(cam.longitude*calng < 0 && fabs(cam.longitude-calng) > 180.0)
                calng += (cam.longitude < 0.0) ? -360.0 : 360.0;

            const double dalat = cam.latitude-calat;
            const double dalng = cam.longitude-calng;
            const double da2 = (dalat*dalat)+(dalng*dalng);

            double cblat = (b->bounds.wgs84.minY+b->bounds.wgs84.maxY)/2.0;
            double cblng = (b->bounds.wgs84.minX+b->bounds.wgs84.maxX)/2.0;
            if(cam.longitude*cblng < 0 && fabs(cam.longitude-cblng) > 180.0)
                cblng += (cam.longitude < 0.0) ? -360.0 : 360.0;

            const double dblat = cam.latitude-cblat;
            const double dblng = cam.longitude-cblng;
            const double db2 = (dblat*dblat)+(dblng*dblng);

            if(da2 < db2)
                return false;
            else if(da2 > db2)
                return true;

            // don't expect this to happen
            return (intptr_t)a.get() < (intptr_t)b.get();
        };
    };
    globe->sortCollectResults = [&](const QueryFilter &queryFilter)
    {
        GeoPoint2 camlla;
        queryFilter.scene.projection->inverse(&camlla, queryFilter.scene.camera.location);
        return [camlla](const std::shared_ptr<const TerrainTile>& a, const std::shared_ptr<const TerrainTile>& b)
        {
            const auto cax = (a->aabb_wgs84.minX + a->aabb_wgs84.maxX) / 2.0;
            const auto cay = (a->aabb_wgs84.minY + a->aabb_wgs84.maxY) / 2.0;
            const auto cbx = (b->aabb_wgs84.minX + b->aabb_wgs84.maxX) / 2.0;
            const auto cby = (b->aabb_wgs84.minY + b->aabb_wgs84.maxY) / 2.0;

            auto dax = camlla.longitude - cax;
            if (dax > 180.0)
                dax -= 360.0;
            else if (dax < -180.0)
                dax += 360.0;
            const auto day = camlla.latitude - cay;
            auto dbx = camlla.longitude - cbx;
            if (dbx > 180.0)
                dbx -= 360.0;
            else if (dbx < -180.0)
                dbx += 360.0;
            const auto dby = camlla.latitude - cby;
            return (dax*dax)+(day*day) < (dbx*dbx)+(dby*dby);
        };
    };
    globe->queryFilterEquals = [](const QueryFilter &a, const QueryFilter &b) { return a.sceneVersion == b.sceneVersion; };
    globe->onQuadtreeUpdate = [&renderer_]() { renderer_.requestRefresh(); };
    globe->onRequestFetched = [&renderer_]() { renderer_.requestRefresh(); };

    sourceRefresh.reset(new SourceRefresh(*this));

    elevationSource.value = source;
    elevationSource.isDefault = defaultSource;
    elevationSource.value->addOnContentChangedListener(sourceRefresh.get());

    maxScreenSpaceError = ConfigOptions_getDoubleOptionOrDefault("terrain.max-sse", maxSSE);


#ifdef __ANDROID__
    nodeSelectResolutionAdjustment = 4.0;
#else
    nodeSelectResolutionAdjustment = 4.0;
#endif

    createEdgeIndices(edgeIndices, numPosts, numPosts);
    createEdgeIndices(polarEdgeIndices, NUM_POLAR_POSTS_LAT, NUM_POLAR_POSTS_LNG);
}

ElMgrTerrainRenderService::~ElMgrTerrainRenderService() NOTHROWS
{
    elevationSource.value->removeOnContentChangedListener(sourceRefresh.get());

    stop();
}

TAKErr ElMgrTerrainRenderService::setElevationSource(const std::shared_ptr<ElevationSource>& source_) NOTHROWS
{
    std::shared_ptr<ElevationSource> source(source_);
    bool isDefault = !source;
    if (!source) {
        source = createDefaultElevationSource();
        isDefault = true;
    }

    {
        Monitor::Lock lock(monitor);
        TE_CHECKRETURN_CODE(lock.status);

        if (elevationSource.value)
            elevationSource.value->removeOnContentChangedListener(sourceRefresh.get());
        elevationSource.value = source;
        elevationSource.isDefault = isDefault;
        elevationSource.value->addOnContentChangedListener(sourceRefresh.get());
    }
    globe->sourceContentUpdated();
    renderer.requestRefresh();
    
    return TE_Ok;
}
TAKErr ElMgrTerrainRenderService::getElevationSource(std::shared_ptr<ElevationSource>& value, const bool defaultReturnsEmpty) NOTHROWS
{
    Monitor::Lock lock(monitor);
    TE_CHECKRETURN_CODE(lock.status);
    if(elevationSource.isDefault && defaultReturnsEmpty)
        value.reset();
    else
        value = elevationSource.value;
    return TE_Ok;
}

//public synchronized void lock(GLMapView view, Collection<GLMapView.TerrainTile> tiles) {
TAKErr ElMgrTerrainRenderService::lock(TAK::Engine::Port::Collection<std::shared_ptr<const TerrainTile>> &value, const MapSceneModel2 &view, const int srid, const int sceneVersion, const bool derive) NOTHROWS
{
    QueryFilter filter;
    filter.scene = view;
    filter.srid = srid;
    filter.sceneVersion = sceneVersion;
    filter.derive = derive;
    filter.sse.limit.level = globe->getMaxLevel();
    filter.sse.limit.maxSse = this->getMaxScreenSpaceError();
    filter.sse.serviceMax = this->getMaxScreenSpaceError();
    return lock(value, filter);
}
TAKErr ElMgrTerrainRenderService::lock(TAK::Engine::Port::Collection<std::shared_ptr<const TerrainTile>> &value, const QueryFilter &filter) NOTHROWS
{
    TAKErr code(TE_Ok);
    std::vector<std::shared_ptr<TerrainTile>> tiles;
    TAK::Engine::Port::STLVectorAdapter<std::shared_ptr<TerrainTile>> tiles_v(tiles);
    code = globe->lock(tiles_v, filter);

    // copy the tiles into the client collection. acquire new locks on each
    // tile. these locks will be relinquished by the client when it calls
    // `unlock`
    for(auto &tile : tiles) {
        // acquire a new reference on the tile since it's being passed
        code = value.add(tile);
        TE_CHECKBREAK_CODE(code);

        assert(globe->hasValue(tile));
    }
    TE_CHECKRETURN_CODE(code);

    return code;
}
TAKErr ElMgrTerrainRenderService::lock(TAK::Engine::Port::Collection<std::shared_ptr<const TerrainTile>> &value) NOTHROWS
{
    TAKErr code(TE_Ok);
    std::vector<std::shared_ptr<TerrainTile>> tiles;
    TAK::Engine::Port::STLVectorAdapter<std::shared_ptr<TerrainTile>> tiles_v(tiles);
    code = globe->lock(tiles_v);
    TE_CHECKRETURN_CODE(code);

    // copy the tiles into the client collection. acquire new locks on each
    // tile. these locks will be relinquished by the client when it calls
    // `unlock`
    for(auto &tile : tiles) {
        // acquire a new reference on the tile since it's being passed
        code = value.add(tile);
        TE_CHECKBREAK_CODE(code);

        assert(!!tile);
        assert(!!tile->data.value);
    }
    TE_CHECKRETURN_CODE(code);

    return code;
}

int ElMgrTerrainRenderService::getTerrainVersion() const NOTHROWS
{
    return globe->getTilesVersion();
}

double ElMgrTerrainRenderService::getMaxScreenSpaceError() const NOTHROWS
{
    return maxScreenSpaceError;
}

//public synchronized void unlock(Collection<GLMapView.TerrainTile> tiles)
TAKErr ElMgrTerrainRenderService::unlock(TAK::Engine::Port::Collection<std::shared_ptr<const TerrainTile>> &tiles) NOTHROWS
{
    return TE_Ok;
}

//public double getElevation(GeoPoint geo)
TAKErr ElMgrTerrainRenderService::getElevation(double *value, const double latitude, const double longitude) const NOTHROWS
{
    return ElevationManager_getElevation(value, nullptr, latitude, longitude, ElevationSource::QueryParameters());
}

TAKErr ElMgrTerrainRenderService::start() NOTHROWS
{
    return globe->start();
}
TAKErr ElMgrTerrainRenderService::stop() NOTHROWS
{
    return globe->stop();
}

ElMgrTerrainRenderService::SourceRefresh::SourceRefresh(ElMgrTerrainRenderService &service_) NOTHROWS :
    service(service_)
{}
TAKErr ElMgrTerrainRenderService::SourceRefresh::onContentChanged(const ElevationSource &source) NOTHROWS
{
    service.globe->sourceContentUpdated();

    service.renderer.requestRefresh();
    return TE_Ok;
}

TAKErr TAK::Engine::Renderer::Elevation::ElMgrTerrainRenderService_getDefaultLoResElevationSource(ElevationSourcePtr &loresel) NOTHROWS
{
    static std::shared_ptr<ElevationSource> loreseldb = initLoResEl();
    loresel = ElevationSourcePtr(loreseldb.get(), Memory_leaker_const<ElevationSource>);
    return loresel ? TE_Ok : TE_Err;
}

namespace
{
    TAKErr fetch(std::shared_ptr<TerrainTile> &value_, ElevationSource &elsrc, double *els, const double resolution, const Envelope2 &mbb, const int srid, const std::size_t numPostsLat, const std::size_t numPostsLng, const MemBuffer2 &edgeIndices_, const bool fetchEl, BlockPoolAllocator &allocator, PoolAllocator<TerrainTile> &tileAllocator) NOTHROWS
    {
        if (fetchEl && els) {
            FetchTileBuilder ttb(elsrc, mbb, numPostsLat, numPostsLng, edgeIndices_, els, resolution);
            return ttb.build(value_, 500.0, allocator, tileAllocator);
        } else {
            NoDataTileBuilder ttb(mbb, numPostsLat, numPostsLng, edgeIndices_);
            return ttb.build(value_, 500.0, allocator, tileAllocator);
        }
    }
    double getHeightMapElevation(const TerrainTile &tile, const double latitude, const double longitude) NOTHROWS
    {
        const Envelope2& aabb_wgs84 = tile.aabb_wgs84;
        // do a heightmap lookup
        const double postSpaceX = (aabb_wgs84.maxX-aabb_wgs84.minX) / ((tile).posts_x-1u);
        const double postSpaceY = (aabb_wgs84.maxY-aabb_wgs84.minY) / ((tile).posts_y-1u);

        const double postX = (longitude-aabb_wgs84.minX)/postSpaceX;
        const double postY = (tile).invert_y_axis ?
            (latitude-aabb_wgs84.minY)/postSpaceY :
            (aabb_wgs84.maxY-latitude)/postSpaceY ;

        const auto postL = static_cast<std::size_t>(MathUtils_clamp((int)postX, 0, (int)((tile).posts_x-1u)));
        const auto postR = static_cast<std::size_t>(MathUtils_clamp((int)ceil(postX), 0, (int)((tile).posts_x-1u)));
        const auto postT = static_cast<std::size_t>(MathUtils_clamp((int)postY, 0, (int)((tile).posts_y-1u)));
        const auto postB = static_cast<std::size_t>(MathUtils_clamp((int)ceil(postY), 0, (int)((tile).posts_y-1u)));

        TAK::Engine::Math::Point2<double> p;

        // obtain the four surrounding posts to interpolate from
        (tile).data.value->getPosition(&p, (postT*(tile).posts_x)+postL);
        const double ul = p.z;
        (tile).data.value->getPosition(&p, (postT*(tile).posts_x)+postR);
        const double ur = p.z;
        (tile).data.value->getPosition(&p, (postB*(tile).posts_x)+postR);
        const double lr = p.z;
        (tile).data.value->getPosition(&p, (postB*(tile).posts_x)+postL);
        const double ll = p.z;

        // interpolate the height
        p.z = MathUtils_interpolate(ul, ur, lr, ll,
                MathUtils_clamp(postX-(double)postL, 0.0, 1.0),
                MathUtils_clamp(postY-(double)postT, 0.0, 1.0));
        // transform the height back to HAE
        (tile).data.localFrame.transform(&p, p);
        return p.z;
    }
    TAK::Engine::Math::Point2<float> getHeightMapNormal(const TerrainTile &tile, const double latitude, const double longitude) NOTHROWS
    {
        const Envelope2& aabb_wgs84 = tile.aabb_wgs84;
        // do a heightmap lookup
        const double postSpaceX = (aabb_wgs84.maxX-aabb_wgs84.minX) / ((tile).posts_x-1u);
        const double postSpaceY = (aabb_wgs84.maxY-aabb_wgs84.minY) / ((tile).posts_y-1u);

        const double postX = (longitude-aabb_wgs84.minX)/postSpaceX;
        const double postY = (tile).invert_y_axis ?
            (latitude-aabb_wgs84.minY)/postSpaceY :
            (aabb_wgs84.maxY-latitude)/postSpaceY ;

        const auto postL = static_cast<std::size_t>(MathUtils_clamp((int)postX, 0, (int)((tile).posts_x-1u)));
        const auto postR = static_cast<std::size_t>(MathUtils_clamp((int)ceil(postX), 0, (int)((tile).posts_x-1u)));
        const auto postT = static_cast<std::size_t>(MathUtils_clamp((int)postY, 0, (int)((tile).posts_y-1u)));
        const auto postB = static_cast<std::size_t>(MathUtils_clamp((int)ceil(postY), 0, (int)((tile).posts_y-1u)));

        // obtain the four surrounding posts to interpolate from
        TAK::Engine::Math::Point2<float> ul(0.f, 0.f, 1.f);
        (tile).data.value->getNormal(&ul, (postT*(tile).posts_x)+postL);
        TAK::Engine::Math::Point2<float> ur(0.f, 0.f, 1.f);
        (tile).data.value->getNormal(&ur, (postT*(tile).posts_x)+postR);
        TAK::Engine::Math::Point2<float> lr(0.f, 0.f, 1.f);
        (tile).data.value->getNormal(&lr, (postB*(tile).posts_x)+postR);
        TAK::Engine::Math::Point2<float> ll(0.f, 0.f, 1.f);
        (tile).data.value->getNormal(&ll, (postB*(tile).posts_x)+postL);

        // interpolate the normal
        TAK::Engine::Math::Point2<float> normal;
        normal.x = (float)MathUtils_interpolate(ul.x, ur.x, lr.x, ll.x,
                MathUtils_clamp(postX-(double)postL, 0.0, 1.0),
                MathUtils_clamp(postY-(double)postT, 0.0, 1.0));
        normal.y = (float)MathUtils_interpolate(ul.y, ur.y, lr.y, ll.y,
                MathUtils_clamp(postX-(double)postL, 0.0, 1.0),
                MathUtils_clamp(postY-(double)postT, 0.0, 1.0));
        normal.z = (float)MathUtils_interpolate(ul.z, ur.z, lr.z, ll.z,
                MathUtils_clamp(postX-(double)postL, 0.0, 1.0),
                MathUtils_clamp(postY-(double)postT, 0.0, 1.0));
        return Vector2_normalize<float>(normal);
    }
    TAKErr derive(std::shared_ptr<TerrainTile>& value_, const Envelope2& mbb, const int srid, const std::size_t numPostsLat, const std::size_t numPostsLng, const MemBuffer2& edgeIndices_, const TerrainTile& deriveFrom, BlockPoolAllocator& allocator, PoolAllocator<TerrainTile>& tileAllocator) NOTHROWS
    {
        if(deriveFrom.hasData) {
            DeriveTileBuilder ttb(mbb, numPostsLat, numPostsLng, edgeIndices_, deriveFrom);
            return ttb.build(value_, 500.0, allocator, tileAllocator);
        } else {
            NoDataTileBuilder ttb(mbb, numPostsLat, numPostsLng, edgeIndices_);
            return ttb.build(value_, 500.0, allocator, tileAllocator);
        }
    }

    bool intersects(const Frustum2& frustum, const TAK::Engine::Feature::Envelope2& aabbWCS, const int srid, const double lng) NOTHROWS
    {
        return (frustum.intersects(AABB(TAK::Engine::Math::Point2<double>(aabbWCS.minX, aabbWCS.minY, aabbWCS.minZ), TAK::Engine::Math::Point2<double>(aabbWCS.maxX, aabbWCS.maxY, aabbWCS.maxZ))) ||
            ((srid == 4326) && lng * ((aabbWCS.minX + aabbWCS.maxX) / 2.0) < 0 &&
                frustum.intersects(
                    AABB(TAK::Engine::Math::Point2<double>(aabbWCS.minX - (360.0 * sgn((aabbWCS.minX + aabbWCS.maxX) / 2.0)), aabbWCS.minY, aabbWCS.minZ),
                        TAK::Engine::Math::Point2<double>(aabbWCS.maxX - (360.0 * sgn((aabbWCS.minX + aabbWCS.maxX) / 2.0)), aabbWCS.maxY, aabbWCS.maxZ)))));
    }

    TerrainTileBuilder::TerrainTileBuilder(const Envelope2 &mbb, const std::size_t numPostsLat, const std::size_t numPostsLng, const MemBuffer2 &edgeIndices) NOTHROWS :
        edgeIndices_(edgeIndices)
    {
        this->mbb = mbb;
        this->numPostsLat = numPostsLat;
        this->numPostsLng = numPostsLng;

        cellHeightLat = ((mbb.maxY - mbb.minY) / (numPostsLat - 1));
        cellWidthLng = ((mbb.maxX - mbb.minX) / (numPostsLng - 1));
        // number of edge vertices is equal to perimeter length, plus one, to
        // close the linestring
        numEdgeVertices = ((numPostsLat-1u)*2u)+((numPostsLng-1u)*2u) + 1u;

        localOriginX = (mbb.minX+mbb.maxX)/2.0;
        localOriginY = (mbb.minY+mbb.maxY)/2.0;
        localOriginZ = 0.0;

        Skirt_getNumOutputIndices(&numSkirtIndices, GL_TRIANGLE_STRIP, numEdgeVertices);
        numIndices = GLTexture2_getNumQuadMeshIndices(numPostsLng - 1u, numPostsLat - 1u)
                                + 2u // degenerate link to skirt
                                + numSkirtIndices;

        skirtOffset = GLTexture2_getNumQuadMeshIndices(numPostsLng - 1u, numPostsLat - 1u);

        numPostVerts = numPostsLat * numPostsLng;
        numSkirtVerts = Skirt_getNumOutputVertices(numEdgeVertices);
        numVerts = (numPostVerts + numSkirtVerts);

        // all positions followed by all normals followed by no data mask
        layout.interleaved = true;
        layout.attributes = TEVA_Position | TEVA_Normal | TEVA_Reserved0 | TEVA_Reserved1;
        // position
        layout.position.offset = 0u;
        layout.position.type = TEDT_Float32;
        layout.position.size = 3u;
        layout.position.stride = layout.position.size * DataType_size(layout.position.type);
        // normal
        layout.normal.offset = layout.position.offset + (numVerts * layout.position.stride);
        layout.normal.type = TEDT_Int8;
        layout.normal.stride = 4u*sizeof(int8_t);
        layout.normal.size = 3u;
        // no data mask
        layout.reserved[0u].offset = layout.normal.offset + (numVerts*layout.normal.stride);
        layout.reserved[0u].type = TEDT_Float32;
        layout.reserved[0u].stride = sizeof(float);
        layout.reserved[0u].size = 1u;
        // ecef position
        layout.reserved[1u].offset = layout.reserved[0u].offset + (numVerts * layout.reserved[0u].stride);
        layout.reserved[1u].type = TEDT_Float32;
        layout.reserved[1u].size = 3u;
        layout.reserved[1u].stride = layout.reserved[1u].size * DataType_size(layout.reserved[1u].type);
    }

    TAKErr TerrainTileBuilder::build(std::shared_ptr<TerrainTile> &value, const float skirtHeight, BlockPoolAllocator &allocator, PoolAllocator<TerrainTile> &tileAllocator) NOTHROWS
    {
        TAKErr code(TE_Ok);

        {
            std::unique_ptr<TerrainTile, void(*)(const TerrainTile *)> tileptr(nullptr, nullptr);
            code = tileAllocator.allocate(tileptr);
            TE_CHECKRETURN_CODE(code);

            value = std::move(tileptr);
        }
        value->data.srid = 4326;
        value->data.localFrame.setToTranslate(localOriginX, localOriginY, localOriginZ);

        const std::size_t ib_size = numIndices * sizeof(uint16_t);

        std::unique_ptr<void, void(*)(const void *)> buf(nullptr, nullptr);
        // allocate the mesh data from the pool
        code = allocator.allocate(buf);

        MemBuffer2 indices(static_cast<uint16_t *>(buf.get()), numIndices);
        code = createHeightmapMeshIndices(indices, edgeIndices_, numPostsLat, numPostsLng);
        TE_CHECKRETURN_CODE(code);

        // duplicate the `edgeIndices` buffer for independent position/limit
        MemBuffer2 edgeIndices(edgeIndices_.get(), edgeIndices_.size());
        edgeIndices.limit(edgeIndices_.limit());
        edgeIndices.position(edgeIndices_.position());

        // set up buffers for positions, normals and no-data-mask as separate views into allocated block
        MemBuffer2 positions(static_cast<uint8_t *>(buf.get())+ib_size+layout.position.offset, numVerts*layout.position.stride);
        MemBuffer2 normals(static_cast<uint8_t*>(buf.get()) + ib_size + layout.normal.offset, numVerts*layout.normal.stride);
        MemBuffer2 noDataMask(static_cast<uint8_t*>(buf.get()) + ib_size + layout.reserved[0].offset, numVerts* layout.reserved[0u].stride);
        MemBuffer2 ecef(static_cast<uint8_t*>(buf.get()) + ib_size + layout.reserved[1].offset, numVerts*layout.reserved[1u].stride);


        // fill the positions
        bool hasData;
        double minEl;
        double maxEl;
        code = fillPositions(positions, noDataMask, hasData, minEl, maxEl);
        TE_CHECKRETURN_CODE(code);
        positions.flip();

        code = Skirt_createVertices<float, uint16_t>(positions,
                GL_TRIANGLE_STRIP,
                3u*sizeof(float),
                &edgeIndices,
                numEdgeVertices,
                skirtHeight);
        TE_CHECKRETURN_CODE(code);

        // ecef vert generation
        Projection2Ptr ecefProjection(nullptr, nullptr);
        code = ProjectionFactory3_create(ecefProjection, 4978);
        TE_CHECKRETURN_CODE(code)

        TAK::Engine::Math::Point2<double> ecefLocalOrigin;
        // transform translation into destination spatial reference
        {
            GeoPoint2 geo(localOriginY, localOriginX, localOriginZ, AltitudeReference::HAE);
            code = ecefProjection->forward(&ecefLocalOrigin, geo);
            TE_CHECKRETURN_CODE(code);
        }

        {
            positions.reset();
            float xyz[3];
            while ((code = positions.get<float>(xyz, 3)) == TE_Ok) {
                TAK::Engine::Math::Point2<double> ecefPoint;
                ecefProjection->forward(&ecefPoint, GeoPoint2(xyz[1] + localOriginY, xyz[0] + localOriginX, xyz[2] + localOriginZ, AltitudeReference::HAE));
                ecefPoint.x -= ecefLocalOrigin.x;
                ecefPoint.y -= ecefLocalOrigin.y;
                ecefPoint.z -= ecefLocalOrigin.z;
                float ecefxyz[3] = { float(ecefPoint.x), float(ecefPoint.y), float(ecefPoint.z) };
                code = ecef.put<float>(ecefxyz, 3u);
                TE_CHECKRETURN_CODE(code);
            }
            if (code == TE_EOF) code = TE_Ok;
            TE_CHECKRETURN_CODE(code);
        }

        // normal generation
        code = generateNormals(normals, edgeIndices, hasData);

        Envelope2 aabb;
        aabb.minX = mbb.minX - localOriginX;
        aabb.minY = mbb.minY - localOriginY;
        aabb.minZ = (minEl-skirtHeight) - localOriginZ;
        aabb.maxX = mbb.maxX - localOriginX;
        aabb.maxY = mbb.maxY - localOriginY;
        aabb.maxZ = maxEl - localOriginZ;

        // create the mesh
        MeshPtr terrainMesh(nullptr, nullptr);
        code = MeshBuilder_buildInterleavedMesh(
            terrainMesh,
            TEDM_TriangleStrip,
            TEWO_Clockwise,
            layout,
            0u,
            nullptr,
            aabb,
            numVerts,
            positions.get(),
            TEDT_UInt16,
            indices.limit() / sizeof(uint16_t),
            indices.get(),
            std::move(buf));

        TE_CHECKRETURN_CODE(code);

        value->data.srid = 4326;
        value->data.value = std::move(terrainMesh);
        value->data.localFrame.setToTranslate(localOriginX, localOriginY, localOriginZ);
        value->data.interpolated = true;
        value->skirtIndexOffset = skirtOffset;
        value->aabb_wgs84 = value->data.value->getAABB();
        value->aabb_wgs84.minX += localOriginX;
        value->aabb_wgs84.minY += localOriginY;
        value->aabb_wgs84.minZ += localOriginZ;
        value->aabb_wgs84.maxX += localOriginX;
        value->aabb_wgs84.maxY += localOriginY;
        value->aabb_wgs84.maxZ += localOriginZ;
        value->hasData = hasData;

        value->heightmap = true;
        value->posts_x = numPostsLng;
        value->posts_y = numPostsLat;
        value->invert_y_axis = true;
        value->noDataAttr = TEVA_Reserved0;
        value->ecefAttr = TEVA_Reserved1;

        // XXX - small downstream "optimization" pending implementation of depth hittest
        {
            ElevationChunk::Data &node = value->data;
            MeshPtr transformed(nullptr, nullptr);
            VertexDataLayout dataProjLayout{ layout };
            // ECEF position is reserved1
            dataProjLayout.position = dataProjLayout.reserved[1];
            dataProjLayout.attributes &= ~TEVA_Reserved1;
            // transform AABB
            Envelope2 dataProjAabb;
            GeometryTransformer_transform(
                &dataProjAabb,
                value->aabb_wgs84,
                4326, 4978);
            // WCS -> LCS
            dataProjAabb.minX -= ecefLocalOrigin.x;
            dataProjAabb.minY -= ecefLocalOrigin.y;
            dataProjAabb.minZ -= ecefLocalOrigin.z;
            dataProjAabb.maxX -= ecefLocalOrigin.x;
            dataProjAabb.maxY -= ecefLocalOrigin.y;
            dataProjAabb.maxZ -= ecefLocalOrigin.z;

            std::unique_ptr<void, void(*)(const void*)> bufref(new std::shared_ptr<TAK::Engine::Model::Mesh>(value->data.value), Memory_void_deleter_const<std::shared_ptr<TAK::Engine::Model::Mesh>>);
            code = MeshBuilder_buildInterleavedMesh(
                transformed,
                value->data.value->getDrawMode(),
                value->data.value->getFaceWindingOrder(),
                dataProjLayout,
                0u, nullptr, // materials, known to be null
                dataProjAabb,
                value->data.value->getNumVertices(),
                positions.get(),
                TEDT_UInt16,
                indices.limit() / sizeof(uint16_t),
                indices.get(),
                std::move(bufref));

            value->data_proj.localFrame = Matrix2();
            value->data_proj.localFrame.setToTranslate(ecefLocalOrigin.x, ecefLocalOrigin.y, ecefLocalOrigin.z);
            value->data_proj.srid = 4978;

            value->data_proj.value = std::move(transformed);
        }

        return code;
    }

    FetchTileBuilder::FetchTileBuilder(ElevationSource &elsrc, const Envelope2& mbb, const std::size_t numPostsLat, const std::size_t numPostsLng, const MemBuffer2 &edgeIndices, double *els, const double resolution) NOTHROWS :
        TerrainTileBuilder(mbb, numPostsLat, numPostsLng, edgeIndices),
        elevationSource(elsrc),
        els(els),
        resolution(resolution)
    {}
    TAKErr FetchTileBuilder::fillPositions(MemBuffer2 &positions, MemBuffer2 &noDataMask, bool &hasData, double &minEl, double &maxEl) NOTHROWS
    {
        TAKErr code(TE_Ok);

        {

            HeightmapParams params;
            params.numPostsLng = numPostsLng+2u;
            params.numPostsLat = numPostsLat+2u;
            params.bounds.minX = mbb.minX-cellWidthLng;
            params.bounds.minY = mbb.minY-cellHeightLat;
            params.bounds.maxX = mbb.maxX+cellWidthLng;
            params.bounds.maxY = mbb.maxY+cellHeightLat;
            params.invertYAxis = true;
            code = ElevationManager_createHeightmap(els, elevationSource, resolution, params, HeightmapStrategy::Low);
        }

        hasData = !TE_ISNAN(els[0]);
        minEl = !hasData ? 0.0 : els[0];
        maxEl = !hasData ? 0.0 : els[0];
        for (std::size_t postLat = 0u; postLat < numPostsLat; postLat++) {
            std::size_t postRowIdx = 1u+((numPostsLng+2u)*(postLat+1u));
            // tile row
            for(std::size_t postLng = 0u; postLng < numPostsLng; postLng++) {
                const double el = els[postRowIdx + postLng];
                const bool elnan = TE_ISNAN(el);
                const double lat = mbb.minY+cellHeightLat*postLat;
                const double lng = mbb.minX+cellWidthLng*postLng;
                const double hae = elnan ? 0.0 : el;

                if (!elnan) {
                    if(hae < minEl)         minEl = hae;
                    else if(hae > maxEl)    maxEl = hae;
                    hasData = true;
                } else {
                    // reset invalid source elevations for normal generation
                    els[postRowIdx + postLng] = 0.0;
                }

                float xyz[3u] = {
                    (float)(lng-localOriginX),
                    (float)(lat-localOriginY),
                    (float)(hae-localOriginZ),
                };
                code = positions.put<float>(xyz, 3u);
                TE_CHECKBREAK_CODE(code);
                // no data mask
                code = noDataMask.put<float>(elnan ? 0.f : 1.f);
                TE_CHECKBREAK_CODE(code);
            }
            TE_CHECKBREAK_CODE(code);
        }
        TE_CHECKRETURN_CODE(code);

        return code;
    }
    TAKErr FetchTileBuilder::generateNormals(MemBuffer2 &normals, const MemBuffer2 &edgeIndices, const bool hasData) NOTHROWS
    {
        TAKErr code(TE_Ok);

        if (hasData) {
            // ensure no NANs on border
            for (std::size_t i = 0u; i < (numPostsLng + 2u); i++) {
                if (TE_ISNAN(els[i]))
                    els[i] = 0.0;
                if (TE_ISNAN(els[((numPostsLat+1u) * (numPostsLng+2u)) + i]))
                    els[((numPostsLat+1u) * (numPostsLng+2u)) + i] = 0.0;
            }
            for (std::size_t i = 0u; i < (numPostsLat + 2u); i++) {
                const std::size_t rowStartIdx = i * (numPostsLng + 2u);
                if (TE_ISNAN(els[rowStartIdx]))
                    els[rowStartIdx] = 0.0;
                if (TE_ISNAN(els[rowStartIdx + (numPostsLng+1u)]))
                    els[rowStartIdx + (numPostsLng+1u)] = 0.0;
            }

            // point source data at the first post in the requested region (ignoring border)
            MemBuffer2 elssrc(reinterpret_cast<const uint8_t*>(els + (numPostsLng+2u) + 1u), (numPostsLat+2u)*(numPostsLng+2u)*sizeof(double));

            VertexArray postLayout;
            postLayout.offset = 0u;
            postLayout.stride = sizeof(double);
            postLayout.type = TEDT_Float64;

            VertexArray normalLayout = layout.normal;
            normalLayout.offset = 0u;

            const double scaleX = TAK::Engine::Core::GeoPoint2_approximateMetersPerDegreeLongitude((mbb.minY + mbb.maxY) / 2.0) * cellWidthLng;
            const double scaleY = TAK::Engine::Core::GeoPoint2_approximateMetersPerDegreeLatitude((mbb.minY + mbb.maxY) / 2.0) * cellHeightLat;
            const double scaleZ = 1.0;
            code = Heightmap_generateNormals(normals, elssrc, numPostsLng, numPostsLat, postLayout, postLayout.stride * (numPostsLng + 2u), normalLayout, normalLayout.stride * numPostsLng, false, scaleX, scaleY, scaleZ);
            TE_CHECKRETURN_CODE(code);
        } else {
            const int8_t nUp[4u] = { 0x0, 0x0, 0x7F, 0x0 };
            for (std::size_t i = 0; i < (numPostsLat*numPostsLng); i++) {
                normals.put<int8_t>(nUp, 4u);
            }
        }
        // set the normals on the skirt to corresponding vert.
        // `Skirt_createVertices` will automate this for us.
        normals.position(0u);
        normals.limit(layout.normal.stride*numPostVerts);
        code = Skirt_createVertices<int8_t, uint16_t>(normals,
                GL_TRIANGLE_STRIP,
                layout.normal.stride,
                &edgeIndices,
                numEdgeVertices,
                0);
        TE_CHECKRETURN_CODE(code);

        return code;
    }

    NoDataTileBuilder::NoDataTileBuilder(const Envelope2& mbb, const std::size_t numPostsLat, const std::size_t numPostsLng, const MemBuffer2 &edgeIndices) NOTHROWS :
        TerrainTileBuilder(mbb, numPostsLat, numPostsLng, edgeIndices)
    {}
    TAKErr NoDataTileBuilder::fillPositions(MemBuffer2 &positions, MemBuffer2 &noDataMask, bool &hasData, double &minEl, double &maxEl) NOTHROWS
    {
        TAKErr code(TE_Ok);

        const bool fetchEl = !!els;
        hasData = false;
        minEl = 0.0;
        maxEl = 0.0;
        for (std::size_t postLat = 0u; postLat < numPostsLat; postLat++) {
            std::size_t postRowIdx = 1u+((numPostsLng+2u)*(postLat+1u));
            // tile row
            for(std::size_t postLng = 0u; postLng < numPostsLng; postLng++) {
                const double lat = mbb.minY+cellHeightLat*postLat;
                const double lng = mbb.minX+cellWidthLng*postLng;
                const double hae = 0.0;

                float xyz[3u] = {
                    (float)(lng-localOriginX),
                    (float)(lat-localOriginY),
                    (float)(hae-localOriginZ),
                };
                code = positions.put<float>(xyz, 3u);
                TE_CHECKBREAK_CODE(code);
                // no data mask
                code = noDataMask.put<float>(0.f);
                TE_CHECKBREAK_CODE(code);
            }
            TE_CHECKBREAK_CODE(code);
        }
        TE_CHECKRETURN_CODE(code);

        return code;
    }
    TAKErr NoDataTileBuilder::generateNormals(MemBuffer2 &normals, const MemBuffer2 &edgeIndices, const bool hasData) NOTHROWS
    {
        TAKErr code(TE_Ok);
        const int8_t nUp[4u] = { 0x0, 0x0, 0x7F, 0x0 };
        for (std::size_t i = 0; i < (numPostsLat*numPostsLng); i++) {
            normals.put<int8_t>(nUp, 4u);
        }

        // set the normals on the skirt to corresponding vert.
        // `Skirt_createVertices` will automate this for us.
        normals.position(0u);
        normals.limit(layout.normal.stride*numPostVerts);
        code = Skirt_createVertices<int8_t, uint16_t>(normals,
                GL_TRIANGLE_STRIP,
                layout.normal.stride,
                &edgeIndices,
                numEdgeVertices,
                0);
        TE_CHECKRETURN_CODE(code);

        return code;
    }

    DeriveTileBuilder::DeriveTileBuilder(const Envelope2& mbb, const std::size_t numPostsLat, const std::size_t numPostsLng, const MemBuffer2 &edgeIndices, const TerrainTile &deriveFrom) NOTHROWS :
        TerrainTileBuilder(mbb, numPostsLat, numPostsLng, edgeIndices),
        deriveFrom(deriveFrom)
    {}

    TAKErr DeriveTileBuilder::fillPositions(MemBuffer2& positions, MemBuffer2& noDataMask, bool& hasData, double& minEl, double& maxEl) NOTHROWS
    {
        TAKErr code(TE_Ok);
        const std::size_t ib_size = numIndices * sizeof(uint16_t);

        minEl = getHeightMapElevation(deriveFrom, mbb.minY, mbb.minX);
        maxEl = minEl;
        hasData = deriveFrom.hasData && !TE_ISNAN(minEl);

        for (std::size_t postLat = 0u; postLat < numPostsLat; postLat++) {
            // tile row
            for(std::size_t postLng = 0u; postLng < numPostsLng; postLng++) {
                const double lat = mbb.minY+((mbb.maxY-mbb.minY)/(numPostsLat-1))*postLat;
                const double lng = mbb.minX+((mbb.maxX-mbb.minX)/(numPostsLng-1))*postLng;
                const double el = getHeightMapElevation(deriveFrom, lat, lng);
                const bool elnan = TE_ISNAN(el);
                const double hae = elnan ? 0.0 : el;

                const double x = lng-localOriginX;
                const double y = lat-localOriginY;
                const double z = hae-localOriginZ;

                float xyz[3] = { (float)x, (float)y, (float)z };
                code = positions.put<float>(xyz, 3u);
                TE_CHECKBREAK_CODE(code);

                code = noDataMask.put<float>(elnan ? 0.f : 1.f);
                TE_CHECKBREAK_CODE(code);
            }
            TE_CHECKBREAK_CODE(code);
        }
        TE_CHECKRETURN_CODE(code);

        return code;
    }
    TAKErr DeriveTileBuilder::generateNormals(MemBuffer2& normals, const MemBuffer2& edgeIndices, const bool hasData) NOTHROWS
    {
        TAKErr code(TE_Ok);
        if (hasData) {
            for (std::size_t postLat = 0u; postLat < numPostsLat; postLat++) {
                // tile row
                for(std::size_t postLng = 0u; postLng < numPostsLng; postLng++) {
                    const double lat = mbb.minY+((mbb.maxY-mbb.minY)/(numPostsLat-1))*postLat;
                    const double lng = mbb.minX+((mbb.maxX-mbb.minX)/(numPostsLng-1))*postLng;
                    const TAK::Engine::Math::Point2<float> normal = getHeightMapNormal(deriveFrom, lat, lng);

                    const int8_t n[4u] =
                    {
                        (int8_t)(normal.x*0x7F),
                        (int8_t)(normal.y*0x7F),
                        (int8_t)(normal.z*0x7F),
                        0x0
                    };
                    code = normals.put<int8_t>(n, 4u);
                    TE_CHECKBREAK_CODE(code);
                }
                TE_CHECKBREAK_CODE(code);
            }
            TE_CHECKRETURN_CODE(code);
        } else {
            const int8_t nUp[4u] = { 0x0, 0x0, 0x7F, 0x0 };
            for (std::size_t i = 0; i < (numPostsLat*numPostsLng); i++) {
                normals.put<int8_t>(nUp, 4u);
            }
        }
        // set the normals on the skirt to corresponding vert.
        // `Skirt_createVertices` will automate this for us.
        normals.position(0u);
        normals.limit(layout.normal.stride*numPostVerts);
        code = Skirt_createVertices<int8_t, uint16_t>(normals,
                GL_TRIANGLE_STRIP,
                layout.normal.stride,
                &edgeIndices,
                numEdgeVertices,
                0);

        return code;
    }
}
