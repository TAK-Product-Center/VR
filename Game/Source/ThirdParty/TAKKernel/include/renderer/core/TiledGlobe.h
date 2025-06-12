//
// Created by Geo Dev on 12/21/23.
//

#ifndef TAK_ENGINE_RENDERER_CORE_TILEDGLOBE_H
#define TAK_ENGINE_RENDERER_CORE_TILEDGLOBE_H

#include <cassert>
#include <functional>

#include "core/ProjectionFactory3.h"
#include "feature/GeometryTransformer.h"
#include "port/Platform.h"
#include "raster/osm/OSMUtils.h"
#include "raster/tilematrix/TileMatrix.h"
#include "thread/Monitor.h"
#include "thread/Thread.h"
#include "thread/ThreadPool.h"
#include "util/Error.h"

namespace TAK {
    namespace Engine {
        namespace Renderer {
            namespace Core {
                template<class TileBlob, class QueryFilter, class CollectStatistics>
                class TiledGlobe
                {
                public :
                    struct CollectHints
                    {
                        bool derive{ true };
                        bool fetch{ true };
                        bool checkVersion{ true };
                        bool cull{ true };
                        int sourceVersion {0};
                    };
                    struct DeriveSource
                    {
                        std::size_t level{0u};
                        int version{-1};
                        TileBlob tile;
                    };
                    class QuadNode;
                    struct TileMatrix {
                        int srid;
                        std::size_t numLevels;
                        TAK::Engine::Math::Point2<double> origin;
                        double z0TileWidth;
                        double z0TileHeight;
                        TAK::Engine::Feature::Envelope2 bounds;
                    };
                private :   
                    struct GlobeTiles
                    {
                        QueryFilter filter;
                        int sourceVersion {-1};
                        int tilesVersion {-1};
                        std::vector<TileBlob> tiles;
                    };
                private :
                    typedef std::function<bool(const std::shared_ptr<QuadNode> &a, const std::shared_ptr<QuadNode> &b)> FetchQueueSort;
                    typedef std::function<bool(const TileBlob &a, const TileBlob &b)> CollectResultsSort;
                public :
                    TiledGlobe(const TileMatrix &tileMatrix, const std::size_t maxTileQueueSize, const std::size_t numTileFetchWorkers) NOTHROWS;
                public :
                    ~TiledGlobe() NOTHROWS;
                public :
                    /**
                     * Returns the mesh that was returned from the most recent
                     * call to
                     * `lock(Collection<TileBlob>, QueryFilter, ...)`
                     *
                     * @param value
                     * @return
                     */
                    virtual Util::TAKErr lock(Port::Collection<TileBlob> &value) NOTHROWS;
                    /**
                     *
                     * @param value
                     * @param filter
                     * @return
                     */
                    virtual Util::TAKErr lock(Port::Collection<TileBlob> &value, const QueryFilter &filter) NOTHROWS;
                    virtual Util::TAKErr unlock(Port::Collection<TileBlob> &tiles) NOTHROWS;
                    virtual Util::TAKErr start() NOTHROWS;
                    virtual Util::TAKErr stop() NOTHROWS;
                    std::size_t getMaxLevel() const NOTHROWS { return maxLevel; }
                    int getTilesVersion() const NOTHROWS
                    {
                        TAK::Engine::Thread::Monitor::Lock mlock(monitor);
                        return (version.world + version.source + version.quadtree);
                    }
                    void sourceContentUpdated() NOTHROWS
                    {
                        TAK::Engine::Thread::Monitor::Lock mlock(monitor);
                        version.source++;
                        version.quadtree++;
                    }
                    void sourceContentUpdated(const std::size_t zoom, const std::size_t x, const std::size_t y) NOTHROWS;
                private :
                    Util::TAKErr enqueue(const std::shared_ptr<QuadNode> &node) NOTHROWS;
                public :
                    bool collectRequestResults(CollectStatistics &stats, const CollectHints &hints, const QueryFilter &filter, const std::function<void(const std::shared_ptr<QuadNode> &)> &collector) NOTHROWS;
                private :
                    static void *fetchWorkerThread(void *);
                    static void *requestWorkerThread(void *);
                private :
                public :
                    TileMatrix tileMatrix;
                    bool debug{false};
                    bool sparse{false};
                private:
                    struct {
                        Thread::ThreadPoolPtr worker {Thread::ThreadPoolPtr(nullptr, nullptr)};
                        std::vector<std::shared_ptr<QuadNode>> entries;
                        bool sorted {false};
                        mutable Thread::Monitor monitor {Thread::TEMT_Recursive};
                    } queue;
                    TAK::Engine::Core::Projection2Ptr projection {nullptr, nullptr};
                    std::unique_ptr<GlobeTiles> worldTerrain;

                    QueryFilter request;

                    struct {
                        std::vector<std::shared_ptr<QuadNode>> z0;
                        std::vector<std::shared_ptr<QuadNode>> z1;
                    } roots;

                    Thread::ThreadPtr requestWorker;

                    std::size_t nodeCount;
                public :
                    struct {
                        /** version of quadtree, bumped when a tile is fetched */
                        int quadtree{ 1 };
                        /** version of source data, bumped on source added/removed/changed */
                        int source{ 0 };
                        /** version of the world front buffer, bumped on flip */
                        int world{ 0 };
                    } version;
                private :
                    bool reset {false};

                    bool terminate;

                    std::size_t maxLevel;
                    std::size_t maxTileQueueSize;
                    std::size_t numTileFetchWorkers;

                    mutable Thread::Monitor monitor;
                public:
                    ////////////////////////////////////
                    /** invoked during `collect` to determine whether or not to recurse child nodes */
                    std::function<bool(CollectStatistics &stats, const QueryFilter &filter, const QuadNode &node, const bool self)> shouldRecurse;
                    std::function<TileBlob(const QuadNode &node, const CollectHints &hints)> fetchTileData;
                    std::function<TileBlob(const QuadNode &node, const CollectHints &hints, const DeriveSource &from)> deriveTileData;
                    std::function<TileBlob(const QuadNode &node)> emptyTileData;
                    std::function<bool(const TileBlob &)> hasValue;
                    /** invoked by value request worker to determine if node is eligible for collect */
                    std::function<bool(const QueryFilter &filter, const QuadNode &node)> shouldCollect;
                    /** invoked by value fetch worker to determine if value should still be fetched */
                    std::function<bool(const QueryFilter &filter, const QuadNode &node)> shouldFetch;
                    std::function<void(QuadNode &node, const TileBlob &value, const bool derived)> setValue;
                    std::function<void(TileBlob &)> clearValue;

                    std::function<bool(CollectStatistics &stats, const CollectHints &hints, const QueryFilter &filter, const std::function<void(const std::shared_ptr<QuadNode> &)> &collector)> fillRequest;
                    std::function<FetchQueueSort(const QueryFilter &queryFilter)> sortFetchQueue;
                    std::function<CollectResultsSort(const QueryFilter &queryFilter)> sortCollectResults;
                    std::function<bool(const QueryFilter &a, const QueryFilter &b)> queryFilterEquals;

                    // callbacks
                    std::function<void()> onQuadtreeUpdate;
                    std::function<void()> onRequestFetched;
                };

                template<class TileBlob, class QueryFilter, class CollectStatistics>
                class TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::QuadNode
                {
                public:
                    QuadNode(TiledGlobe<TileBlob, QueryFilter, CollectStatistics> &service, const std::shared_ptr<QuadNode> &parent, const TAK::Engine::Feature::Envelope2 &bounds_proj) NOTHROWS;
                    QuadNode(TiledGlobe<TileBlob, QueryFilter, CollectStatistics> &service, const std::shared_ptr<QuadNode> &parent, const std::size_t childIdx) NOTHROWS;
                public :
                    static bool needsFetch(const std::weak_ptr<QuadNode> &node, const CollectHints &hints) NOTHROWS;
                    bool collect(CollectStatistics &stats, const CollectHints &hints, const QueryFilter &filter, DeriveSource deriveFrom, const std::function<void(const std::shared_ptr<QuadNode> &)> &collector) NOTHROWS;
                    void reset(const bool data) NOTHROWS;
                    void derive(const CollectHints &hints, const DeriveSource &deriveFrom) NOTHROWS;
                public :
                    TiledGlobe &service;

                    std::shared_ptr<QuadNode> ul;
                    std::shared_ptr<QuadNode> ur;
                    std::shared_ptr<QuadNode> lr;
                    std::shared_ptr<QuadNode> ll;

                    std::weak_ptr<QuadNode> self;

                    struct {
                        TAK::Engine::Feature::Envelope2 proj;
                        TAK::Engine::Feature::Envelope2 wgs84;
                    } bounds;

                    std::size_t level;

                    TileBlob tile;
                    bool queued;

                    int sourceVersion {-1};

                    struct {
                        std::size_t level{0u};
                        bool value {true};
                        bool error {false};
                        int version {-1};
                    } derived;

                    std::weak_ptr<QuadNode> parent;
                };


                template<class TileMatrix>
                TileMatrix TiledGlobe_matrix4326(const std::size_t maxLevel) NOTHROWS
                {
                    TileMatrix tiles;
                    tiles.srid = 4326;
                    tiles.origin = TAK::Engine::Math::Point2<double>(-180.0, 90.0);
                    tiles.bounds = TAK::Engine::Feature::Envelope2(-180.0, -90.0, 0.0, 180.0, 90.0, 0.0);
                    tiles.numLevels = maxLevel+1u;
                    tiles.z0TileWidth = 180.0;
                    tiles.z0TileHeight = 180.0;
                    return tiles;
                }
                template<class TileMatrix>
                TileMatrix TiledGlobe_matrix3857(const std::size_t maxLevel) NOTHROWS
                {
                    TileMatrix tiles;
                    tiles.srid = 3857;
                    tiles.origin = TAK::Engine::Math::Point2<double>(-20037508.34, 20037508.34);
                    tiles.bounds = TAK::Engine::Feature::Envelope2(-20037508.34, -20037508.34, 0.0, 20037508.34, 20037508.34, 0.0);
                    tiles.numLevels = maxLevel+1u;
                    tiles.z0TileWidth = 20037508.34 * 2.0;
                    tiles.z0TileHeight = 20037508.34 * 2.0;
                    return tiles;
                }
                template<class TileMatrix>
                TileMatrix TiledGlobe_matrix3395(const std::size_t maxLevel) NOTHROWS
                {
                    TileMatrix tiles;
                    tiles.srid = 3395;
                    tiles.origin = TAK::Engine::Math::Point2<double>(-20037508.34, 20037508.34);
                    tiles.bounds = TAK::Engine::Feature::Envelope2(-20037508.34, -20037508.34, 0.0, 20037508.34, 20037508.34, 0.0);
                    tiles.numLevels = maxLevel+1u;
                    tiles.z0TileWidth = 20037508.34 * 2.0;
                    tiles.z0TileHeight = 20037508.34 * 2.0;
                    return tiles;
                }

                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::TiledGlobe(const TileMatrix &tileMatrix_, const std::size_t maxTileQueueSize_, const std::size_t numTileFetchWorkers_) NOTHROWS :
                        tileMatrix(tileMatrix_),
                        requestWorker(nullptr, nullptr),
                        nodeCount(0u),
                        reset(false),
                        monitor(TAK::Engine::Thread::TEMT_Recursive),
                        terminate(false),
                        maxLevel(tileMatrix_.numLevels-1u),
                        maxTileQueueSize(maxTileQueueSize_),
                        numTileFetchWorkers(numTileFetchWorkers_),
                        shouldRecurse(nullptr),
                        fetchTileData(nullptr),
                        deriveTileData(nullptr),
                        emptyTileData(nullptr),
                        hasValue(nullptr),
                        shouldCollect(nullptr),
                        shouldFetch(nullptr),
                        setValue(nullptr),
                        clearValue(nullptr),
                        sortFetchQueue(nullptr),
                        sortCollectResults(nullptr),
                        onQuadtreeUpdate(nullptr),
                        onRequestFetched(nullptr)
                {
                    TAK::Engine::Core::ProjectionFactory3_create(projection, tileMatrix.srid);

                    sortFetchQueue = [](const QueryFilter &queryFilter) { return nullptr; };
                    sortCollectResults = [](const QueryFilter &queryFilter) { return nullptr; };
                    fillRequest = [&](CollectStatistics &stats, const CollectHints &hints, const QueryFilter &filter, const std::function<void(const std::shared_ptr<QuadNode> &)> &collector)
                    {
                        return this->collectRequestResults(stats, hints, filter, collector);
                    };
                    setValue = [](QuadNode &node, const TileBlob &value, const bool derived)
                    {
                        node.tile = value;
                    };

                    const std::size_t stx = (std::size_t)((tileMatrix.bounds.minX-tileMatrix.origin.x + (tileMatrix.z0TileWidth/256.0)) / tileMatrix.z0TileWidth);
                    const std::size_t ftx = (std::size_t)((tileMatrix.bounds.maxX-tileMatrix.origin.x - (tileMatrix.z0TileWidth/256.0)) / tileMatrix.z0TileWidth);
                    const std::size_t sty = (std::size_t)((tileMatrix.origin.y-tileMatrix.bounds.maxY + (tileMatrix.z0TileHeight/256.0)) / tileMatrix.z0TileHeight);
                    const std::size_t fty = (std::size_t)((tileMatrix.origin.y-tileMatrix.bounds.minY - (tileMatrix.z0TileHeight/256.0)) / tileMatrix.z0TileHeight);

                    const std::size_t ntx = ftx-stx+1u;
                    const std::size_t nty = fty-sty+1u;
                    roots.z0.reserve(ntx*nty);
                    for(std::size_t ty = 0; ty < nty; ty++) {
                        for (std::size_t tx = 0u; tx < ntx; tx++) {
                            TAK::Engine::Feature::Envelope2 bounds(
                                    tileMatrix.origin.x+(tx*tileMatrix.z0TileWidth),
                                    tileMatrix.origin.y-((ty+1u)*tileMatrix.z0TileHeight),
                                    0.0,
                                    tileMatrix.origin.x+((tx+1u)*tileMatrix.z0TileWidth),
                                    tileMatrix.origin.y-(ty*tileMatrix.z0TileHeight),
                                    0.0);
                            std::shared_ptr<QuadNode> root(new QuadNode(*this, std::shared_ptr<QuadNode>(nullptr), bounds));
                            root->self = root;
                            roots.z0.push_back(root);
                        }
                    }

                    roots.z1.reserve(roots.z0.size()*4u);
                    for(const auto &root : roots.z0) {
                        roots.z1.push_back(std::shared_ptr<QuadNode>(new QuadNode(*this, root, 0u)));
                        roots.z1.push_back(std::shared_ptr<QuadNode>(new QuadNode(*this, root, 1u)));
                        roots.z1.push_back(std::shared_ptr<QuadNode>(new QuadNode(*this, root, 2u)));
                        roots.z1.push_back(std::shared_ptr<QuadNode>(new QuadNode(*this, root, 3u)));
                    }

                    for(auto &root : roots.z1)
                        root->self = root;

                    worldTerrain.reset(new GlobeTiles());
                    worldTerrain->sourceVersion = -1;
                    worldTerrain->tilesVersion = -1;
                    queue.entries.reserve(maxTileQueueSize);
                }
                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::~TiledGlobe() NOTHROWS
                {
                    stop();

                    // release `roots`
                    roots.z1.clear();
                    roots.z0.clear();

                }
                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline Util::TAKErr TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::lock(TAK::Engine::Port::Collection<TileBlob> &value, const QueryFilter &filter) NOTHROWS
                {
                    Util::TAKErr code(Util::TE_Ok);
                    Thread::Monitor::Lock lock(monitor);
                    TE_CHECKRETURN_CODE(lock.status);

                    queue.sorted &= queryFilterEquals(filter, request);

                    request = filter;

                    // if `front` is empty or content invalid repopulate with "root" tiles
                    // temporarily until new data is fetched
                    if(worldTerrain->tiles.empty() /*|| invalid*/) {
                        // drain the `front` buffer
                        worldTerrain->tiles.clear();

                        for(auto &root : roots.z1) {
                            root->derived.value = true;
                            root->derived.level = 0u;
                            worldTerrain->tiles.push_back(emptyTileData(*root));
                        }
                        worldTerrain->filter = filter;
                    }
                    TE_CHECKRETURN_CODE(code);

                    // signal the request handler
                    if(/*invalid ||*/ !queryFilterEquals(request, worldTerrain->filter) || version.quadtree != worldTerrain->tilesVersion) {
                        if (!requestWorker.get()) {
                            Thread::ThreadCreateParams params;
                            params.name = "TiledGlobeBackgroundWorker-request-thread";
                            params.priority = Thread::TETP_Normal;
                            code = Thread::Thread_start(requestWorker, requestWorkerThread, this, params);
                            TE_CHECKRETURN_CODE(code);
                        }

                        lock.broadcast();
                    }

                    // copy the tiles into the client collection. acquire new locks on each
                    // tile. these locks will be relinquished by the client when it calls
                    // `unlock`
                    for(auto &tile : worldTerrain->tiles) {
                        // acquire a new reference on the tile since it's being passed
                        code = value.add(tile);
                        TE_CHECKBREAK_CODE(code);
                    }
                    TE_CHECKRETURN_CODE(code);

                    return code;
                }
                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline Util::TAKErr TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::lock(TAK::Engine::Port::Collection<TileBlob> &value) NOTHROWS
                {
                    Util::TAKErr code(Util::TE_Ok);
                    Thread::Monitor::Lock lock(monitor);
                    TE_CHECKRETURN_CODE(lock.status);

                    // copy the tiles into the client collection. acquire new locks on each
                    // tile. these locks will be relinquished by the client when it calls
                    // `unlock`
                    for(auto tile : worldTerrain->tiles) {
                        // acquire a new reference on the tile since it's being passed
                        code = value.add(tile);
                        TE_CHECKBREAK_CODE(code);
                    }
                    TE_CHECKRETURN_CODE(code);

                    return code;
                }
                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline Util::TAKErr TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::unlock(TAK::Engine::Port::Collection<TileBlob> &tiles) NOTHROWS
                {
                    return Util::TE_Ok;
                }
                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline Util::TAKErr TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::start() NOTHROWS
                {
                    {
                        Thread::Monitor::Lock mlock(monitor);
                        terminate = false;
                    }
                    return Util::TE_Ok;
                }
                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline Util::TAKErr TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::stop() NOTHROWS
                {
                    {
                        Thread::Monitor::Lock mlock(monitor);
                        // signal to worker threads that we are terminating
                        terminate = true;
                        mlock.broadcast();
                    }
                    {
                        Thread::Monitor::Lock mlock(queue.monitor);
                        queue.entries.clear();
                        mlock.broadcast();
                    }

                    // wait for the worker thread to die
                    requestWorker.reset();
                    queue.worker.reset();

                    return Util::TE_Ok;
                }
                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline Util::TAKErr TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::enqueue(const std::shared_ptr<QuadNode> &node) NOTHROWS
                {
                    Util::TAKErr code(Util::TE_Ok);
                    Thread::Monitor::Lock mlock(queue.monitor);
                    TE_CHECKRETURN_CODE(mlock.status);

                    // already queued
                    if(node->queued)
                        return code;

                    // queue is at max capacity
                    if(queue.entries.size() == maxTileQueueSize)
                        return Util::TE_Busy;

                    if (!queue.worker.get()) {
                        code = Thread::ThreadPool_create(queue.worker, numTileFetchWorkers, fetchWorkerThread, this);
                        TE_CHECKRETURN_CODE(code);
                    }

                    // enqueue the node
                    node->queued = true;
                    queue.entries.push_back(node);
                    queue.sorted = false;
                    code = mlock.signal();
                    TE_CHECKRETURN_CODE(code);

                    return code;
                }
                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline bool TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::collectRequestResults(CollectStatistics &stats, const CollectHints &hints, const QueryFilter &filter, const std::function<void(const std::shared_ptr<QuadNode> &)> &collector) NOTHROWS
                {
                    for(auto &root : roots.z1) {
                        if (!shouldCollect(filter, *root))
                            continue;
                        root->collect(
                                stats,
                                hints,
                                filter,
                                DeriveSource(),
                                collector);
                    }
                    return true;
                }

                template<class TileBlob, class QueryFilter, class CollectStatistics>
                void TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::sourceContentUpdated(const std::size_t zoom, const std::size_t x, const std::size_t y) NOTHROWS
                {
                    if(zoom < 1)
                        return;
                    TAK::Engine::Thread::Monitor::Lock mlock(monitor);

                    auto getTileIndex = [](const QuadNode &n)
                    {
                        TAK::Engine::Math::Point2<std::size_t> index;
                        index.x = (std::size_t)((((n.bounds.proj.minX+n.bounds.proj.maxX)/2.0)-n.service.tileMatrix.origin.x)/(n.service.tileMatrix.z0TileWidth/(1u<<n.level)));
                        index.y = (std::size_t)((n.service.tileMatrix.origin.y-(((n.bounds.proj.minY+n.bounds.proj.maxY)/2.0)))/(n.service.tileMatrix.z0TileHeight/(1u<<n.level)));
                        index.z = n.level;
                        return index;
                    };
                    auto isAncestor = [&](const QuadNode &n)
                    {
                        auto tileIndex = getTileIndex(n);
                        return (tileIndex.x == (x>>(zoom-n.level)) && tileIndex.y == (y>>(zoom-n.level)));
                    };

                    std::shared_ptr<QuadNode> node;
                    for(auto &root : roots.z1) {
                        if(isAncestor(*root)) {
                            node = root;
                            break;
                        }
                    }

                    while(node) {
                        if(node->level == zoom) {
                            auto tileIndex = getTileIndex(*node);
                            if(tileIndex.x != x && tileIndex.y != y)
                                node.reset();
                            break;
                        } else if(node->ul && isAncestor(*node->ul)) {
                            node = node->ul;
                        } else if(node->ur && isAncestor(*node->ur)) {
                            node = node->ur;
                        } else if(node->lr && isAncestor(*node->lr)) {
                            node = node->lr;
                        } else if(node->ll && isAncestor(*node->ll)) {
                            node = node->ll;
                        } else {
                            node.reset();
                        }
                    }
                    if(node) {
                        node->sourceVersion = -1;
                        version.quadtree++;
                    }
                }

                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline void *TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::requestWorkerThread(void *opaque)
                {
                    auto &owner = *static_cast<TiledGlobe<TileBlob, QueryFilter, CollectStatistics> *>(opaque);

                    // signals that the front and back buffers should be flipped
                    bool flip = false;
                    // NOTE: `reset` is external here to allow for forcing tree rebuild
                    // by toggling value in debugger
                    bool reset = false;
                    QueryFilter fetch;
                    //fetch.srid = -1;
                    std::unique_ptr<GlobeTiles> fetchBuffer(new GlobeTiles());
                    std::vector<std::shared_ptr<QuadNode>> collectedTiles;
                    while(true) {
                        {
                            Thread::Monitor::Lock mlock(owner.monitor);
                            if (owner.terminate)
                                break;

                            // if we're marked for flip and the SRID is the same, swap the front and back
                            // buffers
                            if(flip/* && fetchBuffer->srid == owner.request.srid*/) {
                                // flip the front and back buffers, references are transferred
                                std::unique_ptr<GlobeTiles> swap = std::move(owner.worldTerrain);
                                owner.worldTerrain = std::move(fetchBuffer);
                                fetchBuffer = std::move(swap);
                                owner.version.world++;

                                // flip was done
                                flip = false;

                                // clear back buffer for the next fetch
                                fetchBuffer->tiles.clear();

                                // request refresh
                                if(owner.onRequestFetched)
                                    owner.onRequestFetched();
                            }

                            // if scene is unchanged and no new terrain, wait
                            if(owner.queryFilterEquals(owner.request, owner.worldTerrain->filter) &&
                               owner.version.quadtree == owner.worldTerrain->tilesVersion) {
                                mlock.wait();

                                flip = false;
                                continue;
                            }
                            fetch = owner.request;

                            const bool invalid = false;
                            reset |= invalid;

                            // synchronize quadtree SRID with current scene
                            if(reset) {
                                for(auto &root : owner.roots.z1) {
                                    std::shared_ptr<QuadNode> parent(root->parent.lock());
                                    root.reset(new QuadNode(owner, parent, root->bounds.proj));
                                    root->self = root;
                                }

                                owner.queue.entries.clear();
                                reset = false;
                            }

                            flip = true;
                            fetchBuffer->filter = owner.request;
                            fetchBuffer->sourceVersion = owner.version.source;
                            fetchBuffer->tilesVersion = owner.version.quadtree;
                            fetchBuffer->tiles = owner.worldTerrain->tiles;

                            // XXX - ?
                            if(owner.onRequestFetched)
                                owner.onRequestFetched();
                        }
                        // clear the tiles in preparation for fetch
                        fetchBuffer->tiles.clear();
                        for(auto &root : owner.roots.z1) {
                            if(!owner.shouldCollect(fetch, *root)) {
                                // no intersection
                                if(!owner.hasValue(root->tile)) {
                                    // there's no data, grab an empty tile
                                    CollectHints hints;
                                    hints.fetch = true;
                                    owner.setValue(*root, owner.fetchTileData(*root, hints), false);
                                    root->sourceVersion = fetchBuffer->sourceVersion;
                                    if(owner.hasValue(root->tile)) {
                                        root->derived.value = false;
                                        root->derived.error = false;
                                    } else {
                                        // leave current value intact
                                        root->derived.error = true;
                                    }
                                }

                                root->reset(false);

                                // add a new reference to the tile to "back"
                                fetchBuffer->tiles.push_back(root->tile);
                            }
                        }

                        // obtain the max SSE for the scene
#ifdef _MSC_VER
                        typename CollectStatistics sse;
#else
                        CollectStatistics sse;
#endif

                        CollectHints hints;
                        hints.checkVersion = true;
                        hints.derive = true;
                        hints.fetch = true;
                        hints.cull = true;
                        hints.sourceVersion = fetchBuffer->sourceVersion;

                        owner.fillRequest(sse, hints, fetch,
                                    [&fetchBuffer](const std::shared_ptr<QuadNode> &node)
                                    {
                                        fetchBuffer->tiles.push_back(node->tile);
                                    });

                        auto sort = owner.sortCollectResults(fetch);
                        if(sort)
                            std::sort(fetchBuffer->tiles.begin(), fetchBuffer->tiles.end(), sort);
                    }

                    return nullptr;
                }
                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline void *TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::fetchWorkerThread(void *opaque)
                {
                    struct {
                        TAK::Engine::Feature::Envelope2 bounds;
                        std::size_t level;
                        double gsd;
                        unsigned cost{ 0u };
                    } mostExpensive;

                    auto &service = *static_cast<TiledGlobe<TileBlob, QueryFilter, CollectStatistics> *>(opaque);

                    std::shared_ptr<QuadNode> node;
                    TileBlob tile;
                    std::size_t fetchedNodes = 0;
                    int fetchSrcVersion = ~service.version.source;
                    QueryFilter filter;
                    while(true) {
                        TAK::Engine::Feature::Envelope2 bounds;

                        // execute the fetch loop
                        {
                            Util::TAKErr code(Util::TE_Ok);
                            Thread::Monitor::Lock qlock(service.queue.monitor);
                            code = qlock.status;

                            const bool quadtreeUpdate = !!node;
                            if(quadtreeUpdate) {
                                // transfer the tile
                                {
                                    node->queued = false;
                                    node->sourceVersion = fetchSrcVersion;
                                    if(service.hasValue(tile)) {
                                        service.setValue(*node, tile, false);
                                        node->derived.value = false;
                                        node->derived.error = false;
                                    } else {
                                        node->derived.error = true;
                                    }
                                }
                                node.reset();
                                service.clearValue(tile);
                            }

                            // check for termination; capture state from service for fetch
                            {
                                Thread::Monitor::Lock slock(service.monitor);
                                code = slock.status;

                                if (service.terminate)
                                    break;

                                if(quadtreeUpdate) {
                                    service.version.quadtree++;
                                    if(service.onQuadtreeUpdate)
                                        service.onQuadtreeUpdate();
                                }

                                filter = service.request;
                                fetchSrcVersion = service.version.source;
                            }

                            if(service.queue.entries.empty()) {
                                code = qlock.wait();
                                if (code == Util::TE_Interrupted)
                                    code = Util::TE_Ok;
                                TE_CHECKBREAK_CODE(code);

                                continue;
                            }

                            // sort the queue if necessary
                            if(!service.queue.sorted) {
                                auto sort = service.sortFetchQueue(service.request);
                                if(sort)
                                    std::sort(service.queue.entries.begin(), service.queue.entries.end(), sort);
                                service.queue.sorted = true;
                            }

                            node = service.queue.entries.back();
                            service.queue.entries.pop_back();

                            std::shared_ptr<QuadNode> parent(node->parent.lock());
                            bounds = parent ? parent->bounds.wgs84 : node->bounds.wgs84;
                        }

                        if (!service.shouldFetch(filter, *node)) {
                            node->queued = false;
                            node.reset();
                            continue;
                        }

                        int64_t fetchstart = Port::Platform_systime_millis();

                        CollectHints fetchHints;
                        fetchHints.fetch = true;
                        tile = service.fetchTileData(*node, fetchHints);

                        fetchedNodes++;

                        int64_t fetchend = Port::Platform_systime_millis();

                        const unsigned fetchcost = (unsigned)(fetchend - fetchstart);
                        if(fetchcost > mostExpensive.cost) {
                            mostExpensive.bounds = node->bounds.wgs84;
                            mostExpensive.level = node->level;
                            mostExpensive.gsd = atakmap::raster::osm::OSMUtils::mapnikTileResolution((int)node->level);
                            mostExpensive.cost = fetchcost;
                        }
                    }

                    return nullptr;
                }
                
                // *** QuadNode function definitions *** //
                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::QuadNode::QuadNode(TiledGlobe &service_, const std::shared_ptr<QuadNode> &parent_, const std::size_t childIdx) NOTHROWS :
                        QuadNode(
                                service_,
                                parent_,
                                TAK::Engine::Feature::Envelope2(
                                            (childIdx%2u) ? (parent_->bounds.proj.minX+parent_->bounds.proj.maxX) / 2.0 : parent_->bounds.proj.minX,
                                            (childIdx/2u) ? parent_->bounds.proj.minY : (parent_->bounds.proj.minY+parent_->bounds.proj.maxY) / 2.0,
                                            parent_->bounds.proj.minZ,
                                            (childIdx%2u) ? parent_->bounds.proj.maxX : (parent_->bounds.proj.minX+parent_->bounds.proj.maxX) / 2.0,
                                            (childIdx/2u) ? (parent_->bounds.proj.minY+parent_->bounds.proj.maxY) / 2.0 : parent_->bounds.proj.maxY,
                                            parent_->bounds.proj.maxZ))
                { }

                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::QuadNode::QuadNode(TiledGlobe &service_, const std::shared_ptr<QuadNode> &parent_, const TAK::Engine::Feature::Envelope2 &bounds_) NOTHROWS :
                    service(service_),
                    parent(parent_),
                    level(0u),
                    queued(false)
                {
                    bounds.proj = bounds_;
                    if(service.tileMatrix.srid == 4326)
                        bounds.wgs84 = bounds.proj;
                    else
                        TAK::Engine::Feature::GeometryTransformer_transform(&bounds.wgs84, bounds.proj, service.tileMatrix.srid, 4326);
                    std::shared_ptr<QuadNode> p(parent.lock());
                    if(p)
                        level = p->level+1u;
                }
                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline bool TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::QuadNode::needsFetch(const std::weak_ptr<QuadNode> &ref, const CollectHints &hints) NOTHROWS
                {
                    std::shared_ptr<QuadNode> node(ref.lock());
                    if (!node)
                        return true;
                    Thread::Monitor::Lock lock(node->service.queue.monitor);
                    // fetch if not queued AND
                    //  - stale version
                    //      = OR =
                    //  - no data
                    return
                        !node->queued &&
                        (hints.checkVersion && (node->sourceVersion != hints.sourceVersion)) ||
                         (!node->service.hasValue(node->tile)/* || node->tile->data.srid != hints.srid*/);
                }
                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline bool TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::QuadNode::collect(CollectStatistics &stats, const CollectHints &hints, const QueryFilter &queryFilter, DeriveSource deriveFrom, const std::function<void(const std::shared_ptr<QuadNode> &)> &collector) NOTHROWS
                {
                    if(level < (service.tileMatrix.numLevels-1u) && service.shouldRecurse(stats, queryFilter, *this, false)) {
                        const double centerX = (this->bounds.proj.minX+this->bounds.proj.maxX)/2.0;
                        const double centerY = (this->bounds.proj.minY+this->bounds.proj.maxY)/2.0;
    
                        QuadNode llt(service, self.lock(), TAK::Engine::Feature::Envelope2(bounds.proj.minX, bounds.proj.minY, bounds.proj.minZ, centerX, centerY, bounds.proj.maxZ));
                        QuadNode lrt(service, self.lock(), TAK::Engine::Feature::Envelope2(centerX, bounds.proj.minY, bounds.proj.minZ, bounds.proj.maxX, centerY, bounds.proj.maxZ));
                        QuadNode urt(service, self.lock(), TAK::Engine::Feature::Envelope2(centerX, centerY, bounds.proj.minZ, bounds.proj.maxX, bounds.proj.maxY, bounds.proj.maxZ));
                        QuadNode ult(service, self.lock(), TAK::Engine::Feature::Envelope2(bounds.proj.minX, centerY, bounds.proj.minZ, centerX, bounds.proj.maxY, bounds.proj.maxZ));
    
                        // compute child intersections
                        const bool recursell = service.shouldRecurse(stats, queryFilter, llt, false);
                        const bool recurselr = service.shouldRecurse(stats, queryFilter, lrt, false);
                        const bool recurseur = service.shouldRecurse(stats, queryFilter, urt, false);
                        const bool recurseul = service.shouldRecurse(stats, queryFilter, ult, false);
    
                        const bool fetchul = needsFetch(ul, hints);
                        const bool fetchur = needsFetch(ur, hints);
                        const bool fetchlr = needsFetch(lr, hints);
                        const bool fetchll = needsFetch(ll, hints);
                        const bool fetchingul = (ul.get() && ul->queued);
                        const bool fetchingur = (ur.get() && ur->queued);
                        const bool fetchinglr = (lr.get() && lr->queued);
                        const bool fetchingll = (ll.get() && ll->queued);
    
                        // derive root
                        if (hints.derive && level == 1u && !service.hasValue(deriveFrom.tile)) {
                            Thread::Monitor::Lock lock(service.queue.monitor);
                            if(service.hasValue(this->tile)) {
                                deriveFrom.tile = this->tile;
                                deriveFrom.level = this->level;
                                deriveFrom.version = this->sourceVersion;
                            }
                        }
    
                        // fetch tile nodes
#define doFetchChild(child) \
        if(fetch##child && !fetching##child) { \
            if(!child.get()) { \
                child.reset(new QuadNode(child##t)); \
                child->self = child; \
            } \
            if(hints.fetch) \
                service.enqueue(child); \
        }
    
                        doFetchChild(ll);
                        doFetchChild(lr);
                        doFetchChild(ur);
                        doFetchChild(ul);
#undef doFetchChild
    
                        // only allow recursion if all nodes have been fetched
                        const bool recurseAny = (recursell || recurseul || recurseur || recurselr);
                        // recurse into the children if either any children are recurse OR if the child level is the terminal level
                        const bool recurse = (recurseAny || service.shouldRecurse(stats, queryFilter, *this, true)) &&
                                 (((ll.get() && service.hasValue(ll->tile)) &&
                                  (lr.get() && service.hasValue(lr->tile)) &&
                                  (ur.get() && service.hasValue(ur->tile)) &&
                                  (ul.get() && service.hasValue(ul->tile))) || service.hasValue(deriveFrom.tile));

                        // children may fetch recursively if they are all fetched for the
                        // current source. This is employed to mitigate tile pops and provide
                        // an experience more consistent with legacy while preserving the
                        // ability to do derivation
                        const bool recurseFetch = hints.fetch &&
                                                  recurseAny &&
                                                  (ll.get() && (service.sparse || !hints.checkVersion || ll->sourceVersion == hints.sourceVersion)) &&
                                                  (lr.get() && (service.sparse || !hints.checkVersion || lr->sourceVersion == hints.sourceVersion)) &&
                                                  (ur.get() && (service.sparse || !hints.checkVersion || ur->sourceVersion == hints.sourceVersion)) &&
                                                  (ul.get() && (service.sparse || !hints.checkVersion || ul->sourceVersion == hints.sourceVersion));
    
                        // descendents derive from `this` if we have tile data and there is no
                        // derive root or we have a newer or same source version
                        if(recurse && hints.derive) {
                            Thread::Monitor::Lock lock(service.queue.monitor);
    
                            // XXX - original implementation compared the source version. This
                            //       led to circa continuous tile pops for streaming data as
                            //       source changed would trigger a domino effect through
                            //       derived tiles. While the implications are not yet fully
                            //       appreciated, simply relying on any ancestor with data is
                            //       observed to allow for updates without the undesired
                            //       popping.
                            if(service.hasValue(tile)) {
                                deriveFrom.tile = this->tile;
                                deriveFrom.version = this->sourceVersion;
                                deriveFrom.level = this->level;
                            }
                        }
    
#define doChildRecurse(child) \
        if(recurse##child) { \
            if(recurse) { \
                CollectHints recurseHints(hints); \
                recurseHints.fetch &= recurseFetch; \
                child->collect(stats, recurseHints, queryFilter, deriveFrom, collector); \
            } \
        } else if(child.get()) { \
            if(hints.cull) child->reset(false); \
            if (recurse) { \
                if (!service.hasValue(child->tile) || (service.hasValue(deriveFrom.tile) && child->derived.level < deriveFrom.level)) \
                    child->derive(hints, deriveFrom); \
                collector(child); \
            } \
        }
    
                        doChildRecurse(ll);
                        doChildRecurse(lr);
                        doChildRecurse(ur);
                        doChildRecurse(ul);
#undef doRecurseChild
                        if(recurse)
                            return true;
                    }
    
                    if(needsFetch(self, hints)) {
                        if(this->level <= 1) {
                            this->sourceVersion = (int)hints.sourceVersion;

                            CollectHints fetchHints(hints);
                            fetchHints.fetch = false;
                            service.setValue(*this, service.emptyTileData(*this), true);
                            derived.value = true;
                            derived.error = false;
                            derived.level = 0u;
                            derived.version = -1;
                        }
    
                        // XXX - this is a little goofy
                        auto self_ptr = self.lock();
                        if(self_ptr)
                            service.enqueue(self_ptr);
                    }
                    bool shouldDerive = !service.hasValue(this->tile);
                    do {
                        if(shouldDerive)
                            break;
                        if(!hints.checkVersion)
                            break;
                        if(!derived.value)
                            break;
                        if(!service.hasValue(deriveFrom.tile))
                            break;
                        if(sourceVersion >= deriveFrom.version)
                            break;
                        else if(derived.version == deriveFrom.version && derived.level >= deriveFrom.level)
                            break;
                        shouldDerive = true;
                    } while(false);
                    if(shouldDerive) {
                        if (!service.hasValue(deriveFrom.tile))
                            return false; // should be illegal state
                        derive(hints, deriveFrom);
                    }
    
                    assert(service.hasValue(this->tile));
                    collector(self.lock());
                    return true;
                }
                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline void TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::QuadNode::derive(const CollectHints &hints, const DeriveSource& deriveFrom) NOTHROWS
                {
                    auto derivedTile = service.deriveTileData(*this, hints, deriveFrom);
                    // set the derived tile
                    {
                        Thread::Monitor::Lock lock(service.queue.monitor);
                        // check for async fetch
                        if (service.hasValue(this->tile) && this->sourceVersion >= deriveFrom.version)
                            return;
                        service.setValue(*this, derivedTile, true);
                        this->derived.value = true;
                        this->derived.level = deriveFrom.level;
                        this->derived.version = deriveFrom.version;
                        // error and sourceVersion state remains intact
                    }
                }
                template<class TileBlob, class QueryFilter, class CollectStatistics>
                inline void TiledGlobe<TileBlob, QueryFilter, CollectStatistics>::QuadNode::reset(const bool data) NOTHROWS
                {
                    Thread::Monitor::Lock qlock(service.queue.monitor);
    
                    // release all children. if queued, reset level to `0` to move out of the
                    // queue as fast as possible
                    auto resetChild = [](std::shared_ptr<QuadNode> &child)
                    {
                        if (child) {
                            if(child->queued) child->level = 0u;
                            child->reset(true);
                            child.reset();
                        }
                    };
                    resetChild(ul);
                    resetChild(ur);
                    resetChild(lr);
                    resetChild(ll);
    
                    if (data && service.hasValue(this->tile)) {
                        service.clearValue(this->tile);
                        this->derived.value = true;
                        this->derived.level = 0u;
                        this->derived.version = -1;
                    }
                }
            } // end namespace TAK::Engine::Renderer::Core
        } // end namespace TAK::Engine::Renderer
    } // end namespace TAK::Engine
} // end namespace TAK

#endif //TAK_ENGINE_RENDERER_CORE_TILEDGLOBE_H
