#include "elevation/VirtualCLODElevationSource.h"

#include <string>

#include "core/Control.h"
#include "elevation/ElevationChunkFactory.h"
#include "elevation/ElevationTileClient.h"
#include "port/STLVectorAdapter.h"
#include "raster/tilematrix/TileProxy.h"
#include "raster/tilematrix/LRUTileContainer.h"
#include "thread/Lock.h"
#include "thread/Mutex.h"

using namespace TAK::Engine::Elevation;

using namespace TAK::Engine::Core;
using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Port;
using namespace TAK::Engine::Raster::TileMatrix;
using namespace TAK::Engine::Thread;
using namespace TAK::Engine::Util;

namespace {
    struct {
        std::map<std::string, std::weak_ptr<TileContainer>> value;
        Mutex mutex;
    } caches;

    class PointsSampler : public Sampler
    {
    public :
        PointsSampler(ElevationChunkPtr &&impl) NOTHROWS;
    public :
        virtual TAKErr sample(double *value, const double latitude, const double longitude) NOTHROWS override;
    private :
        ElevationChunkPtr impl;
    };

    class PointsSamplerCursor : public ElevationChunkCursor
    {
    public :
        PointsSamplerCursor(ElevationChunkCursorPtr &&impl) NOTHROWS;
    public :
        TAKErr moveToNext() NOTHROWS override;
        TAKErr get(ElevationChunkPtr &value) NOTHROWS override;
        TAKErr getResolution(double *value) NOTHROWS override;
        TAKErr isAuthoritative(bool *value) NOTHROWS override;
        TAKErr getCE(double *value) NOTHROWS override;
        TAKErr getLE(double *value) NOTHROWS override;
        TAKErr getUri(const char **value) NOTHROWS override;
        TAKErr getType(const char **value) NOTHROWS override;
        TAKErr getBounds(const Polygon2 **value) NOTHROWS override;
        TAKErr getFlags(unsigned int *value) NOTHROWS override;
    private :
        ElevationChunkCursorPtr impl;
    };

    class CascadingParamsCursor : public ElevationChunkCursor
    {
    public :
        CascadingParamsCursor(ElevationSource &source, const std::vector<ElevationSource::QueryParameters> &params) NOTHROWS;
    public :
        TAKErr moveToNext() NOTHROWS override;
        TAKErr get(ElevationChunkPtr &value) NOTHROWS override;
        TAKErr getResolution(double *value) NOTHROWS override;
        TAKErr isAuthoritative(bool *value) NOTHROWS override;
        TAKErr getCE(double *value) NOTHROWS override;
        TAKErr getLE(double *value) NOTHROWS override;
        TAKErr getUri(const char **value) NOTHROWS override;
        TAKErr getType(const char **value) NOTHROWS override;
        TAKErr getBounds(const Polygon2 **value) NOTHROWS override;
        TAKErr getFlags(unsigned int *value) NOTHROWS override;
    private :
        ElevationSource &source;
        std::vector<ElevationSource::QueryParameters> params;
        int idx;
        ElevationChunkCursorPtr impl;
    };
}

VirtualCLODElevationSource::VirtualCLODElevationSource(const std::shared_ptr<ElevationSource> &impl_, const HeightmapStrategy strategy_, const bool forcePointSample_) NOTHROWS :
    impl(impl_),
    strategy(strategy_ == HeightmapStrategy::Low ? HeightmapStrategy::LowFillHoles : HeightmapStrategy::HighestResolution),
    forcePointSample(forcePointSample_)
{}
const char *VirtualCLODElevationSource::getName() const NOTHROWS
{
    return impl->getName();
}
TAKErr VirtualCLODElevationSource::query(ElevationChunkCursorPtr &value, const QueryParameters &params_) NOTHROWS
{
    TAKErr code(TE_Ok);
    if(TE_ISNAN(params_.maxResolution)) {
        code = impl->query(value, params_);
    } else if(strategy == HeightmapStrategy::HighestResolution) {
        QueryParameters params(params_);
        params.maxResolution = NAN;
        code = impl->query(value, params);
    } else if(strategy == HeightmapStrategy::LowFillHoles) {
        std::vector<QueryParameters> params;
        params.reserve(2);
        // normal query
        params.push_back(params_);
        // hi-res fill
        params.push_back(params_);
        params.back().minResolution = params_.maxResolution;
        params.back().maxResolution = NAN;
        params.back().order->clear();
        params.back().order->add(QueryParameters::Order::ResolutionAsc);
        // cascade low query + hi-res fill
        value = ElevationChunkCursorPtr(new CascadingParamsCursor(*this, params), Memory_deleter_const<ElevationChunkCursor, CascadingParamsCursor>);
    } else {
        return TE_IllegalState;
    }

    // force sampling as requested
    if(code == TE_Ok && forcePointSample)
        value = ElevationChunkCursorPtr(new PointsSamplerCursor(std::move(value)), Memory_deleter_const<ElevationChunkCursor, PointsSamplerCursor>);
    return code;
}
Envelope2 VirtualCLODElevationSource::getBounds() const NOTHROWS
{
    return impl->getBounds();
}
TAKErr VirtualCLODElevationSource::addOnContentChangedListener(OnContentChangedListener *l) NOTHROWS
{
    return impl->addOnContentChangedListener(l);
}
TAKErr VirtualCLODElevationSource::removeOnContentChangedListener(OnContentChangedListener *l) NOTHROWS
{
    return impl->removeOnContentChangedListener(l);
}

VirtualCLODElevationSource::Builder::Builder() NOTHROWS
{
#define NUM_POSTS 32u
    params.numPostsLng = NUM_POSTS;
    params.numPostsLat = NUM_POSTS;
    params.invertYAxis = true;
    params.bounds = Envelope2(-180.0, -90.0, NAN, 180.0, 90.0, NAN);
}

VirtualCLODElevationSource::Builder &VirtualCLODElevationSource::Builder::setSource(const std::shared_ptr<ElevationSource> &impl_) NOTHROWS
{
    impl = impl_;
    return *this;
}
VirtualCLODElevationSource::Builder &VirtualCLODElevationSource::Builder::setPointSampler(const bool pointSampler) NOTHROWS
{
    forcePointSample = pointSampler;
    return *this;
}
VirtualCLODElevationSource::Builder &VirtualCLODElevationSource::Builder::setStrategy(const HeightmapStrategy strategy_) NOTHROWS
{
    strategy = strategy_;
    return *this;
}
VirtualCLODElevationSource::Builder &VirtualCLODElevationSource::Builder::enableCaching(const char *path, const std::size_t cacheLimit, const bool async) NOTHROWS
{
    cache.path = path;
    cache.limit = cacheLimit;
    cache.async = async;
    return *this;
}
VirtualCLODElevationSource::Builder &VirtualCLODElevationSource::Builder::optimizeForTileGrid(const int srid_, const HeightmapParams &params_) NOTHROWS
{
    srid = srid_;
    params = params_;
    return *this;
}
TAKErr VirtualCLODElevationSource::Builder::build(ElevationSourcePtr &value) NOTHROWS
{
    if(cache.path || srid != -1) {
        TileClientPtr elctr(new ElevationTileClient(impl, srid, params, 1u, forcePointSample), Memory_deleter_const<TileClient, ElevationTileClient>);

        std::vector<Control> srcCtrls;
        STLVectorAdapter<Control> srcCtrls_v(srcCtrls);

        // obtain controls on _client_
        static_cast<ElevationTileClient&>(*elctr).getControls(srcCtrls_v);

        std::shared_ptr<TileContainer> container;
        if(cache.path && cache.limit) {
            do {
                Lock lock(caches.mutex);
                auto entry = caches.value.find(cache.path.get());
                if (entry != caches.value.end()) {
                    container = entry->second.lock();
                    if(container)
                        break;
                }
                TileContainerPtr containerPtr(nullptr, nullptr);
                if (LruTileContainer_openOrCreate(containerPtr, "terrainlru", cache.path,
                                                  elctr.get(), cache.limit, 0.1f) == TE_Ok) {
                    container = std::move(containerPtr);
                    caches.value[cache.path.get()] = container;
                }
            } while(false);
        }
        if(cache.path &&
           cache.limit &&
           container) {

            // create a proxy to cache the source data
            std::unique_ptr<TileProxy> tileProxy(
                    new TileProxy(
                            std::move(elctr), srcCtrls.data(), srcCtrls.size(),
                            container, nullptr, 0u,
                            !cache.async));

            // obtain any additional controls from _proxy_
            tileProxy->getControls(srcCtrls_v);

            // reset the elevation tile matrix to the proxy
            elctr = TileClientPtr(tileProxy.release(), Memory_deleter_const<TileClient, TileProxy>);
        }

        value = ElevationSourcePtr(
                new TileMatrixElevationSource(std::move(elctr), ElevationTileClient_info(), srcCtrls.data(), srcCtrls.size()),
                Memory_deleter_const<ElevationSource, TileMatrixElevationSource>);

    } else {
        value = ElevationSourcePtr(new VirtualCLODElevationSource(impl, strategy, forcePointSample), Memory_deleter_const<ElevationSource, VirtualCLODElevationSource>);
    }
    return TE_Ok;
}
TAKErr VirtualCLODElevationSource::Builder::build(std::shared_ptr<ElevationSource> &value) NOTHROWS
{
    ElevationSourcePtr valuePtr(nullptr, nullptr);
    const auto code = build(valuePtr);
    if(code == TE_Ok)
        value = std::move(valuePtr);
    return code;
}

namespace {
    PointsSampler::PointsSampler(ElevationChunkPtr &&impl_) NOTHROWS :
        impl(std::move(impl_))
    {}
    TAKErr PointsSampler::sample(double *value, const double latitude, const double longitude) NOTHROWS
    {
        return impl->sample(value, latitude, longitude);
    }

    PointsSamplerCursor::PointsSamplerCursor(ElevationChunkCursorPtr &&impl_) NOTHROWS :
            impl(std::move(impl_))
    {}
    TAKErr PointsSamplerCursor::moveToNext() NOTHROWS
    {
        return impl->moveToNext();
    }
    TAKErr PointsSamplerCursor::get(ElevationChunkPtr &value) NOTHROWS
    {
        if(!impl)
            return TE_IllegalState;
        const auto code = impl->get(value);
        if(code != TE_Ok || !value)
            return code;
        return ElevationChunkFactory_create(
                value,
                value->getType(),
                value->getUri(),
                value->getFlags(),
                value->getResolution(),
                *value->getBounds(),
                value->getCE(),
                value->getLE(),
                value->isAuthoritative(),
                SamplerPtr(new PointsSampler(std::move(value)), Memory_deleter_const<Sampler, PointsSampler>));
    }
    TAKErr PointsSamplerCursor::getResolution(double *value) NOTHROWS
    {
        return impl ? impl->getResolution(value) : TE_IllegalState;
    }
    TAKErr PointsSamplerCursor::isAuthoritative(bool *value) NOTHROWS
    {
        return impl ? impl->isAuthoritative(value) : TE_IllegalState;
    }
    TAKErr PointsSamplerCursor::getCE(double *value) NOTHROWS
    {
        return impl ? impl->getCE(value) : TE_IllegalState;
    }
    TAKErr PointsSamplerCursor::getLE(double *value) NOTHROWS
    {
        return impl ? impl->getLE(value) : TE_IllegalState;
    }
    TAKErr PointsSamplerCursor::getUri(const char **value) NOTHROWS
    {
        return impl ? impl->getUri(value) : TE_IllegalState;
    }
    TAKErr PointsSamplerCursor::getType(const char **value) NOTHROWS
    {
        return impl ? impl->getType(value) : TE_IllegalState;
    }
    TAKErr PointsSamplerCursor::getBounds(const Polygon2 **value) NOTHROWS
    {
        return impl ? impl->getBounds(value) : TE_IllegalState;
    }
    TAKErr PointsSamplerCursor::getFlags(unsigned int *value) NOTHROWS
    {
        return impl ? impl->getFlags(value) : TE_IllegalState;
    }

    CascadingParamsCursor::CascadingParamsCursor(ElevationSource &source_, const std::vector<ElevationSource::QueryParameters> &params_) NOTHROWS :
            source(source_),
            params(params_),
            idx(0),
            impl(nullptr, nullptr)
    {}

    TAKErr CascadingParamsCursor::moveToNext() NOTHROWS
    {
        do {
            if(impl) {
                const auto code = impl->moveToNext();
                if(code == TE_Done)
                    impl.reset();
                else
                    return code;
            } else if(idx < params.size()) {
                const auto code = source.query(impl, params[idx++]);
                if(code != TE_Ok)
                    return code;
            } else {
                break;
            }
        } while(true);
        return TE_Done;
    }
    TAKErr CascadingParamsCursor::get(ElevationChunkPtr &value) NOTHROWS
    {
        return impl ? impl->get(value) : TE_IllegalState;
    }
    TAKErr CascadingParamsCursor::getResolution(double *value) NOTHROWS
    {
        return impl ? impl->getResolution(value) : TE_IllegalState;
    }
    TAKErr CascadingParamsCursor::isAuthoritative(bool *value) NOTHROWS
    {
        return impl ? impl->isAuthoritative(value) : TE_IllegalState;
    }
    TAKErr CascadingParamsCursor::getCE(double *value) NOTHROWS
    {
        return impl ? impl->getCE(value) : TE_IllegalState;
    }
    TAKErr CascadingParamsCursor::getLE(double *value) NOTHROWS
    {
        return impl ? impl->getLE(value) : TE_IllegalState;
    }
    TAKErr CascadingParamsCursor::getUri(const char **value) NOTHROWS
    {
        return impl ? impl->getUri(value) : TE_IllegalState;
    }
    TAKErr CascadingParamsCursor::getType(const char **value) NOTHROWS
    {
        return impl ? impl->getType(value) : TE_IllegalState;
    }
    TAKErr CascadingParamsCursor::getBounds(const Polygon2 **value) NOTHROWS
    {
        return impl ? impl->getBounds(value) : TE_IllegalState;
    }
    TAKErr CascadingParamsCursor::getFlags(unsigned int *value) NOTHROWS
    {
        return impl ? impl->getFlags(value) : TE_IllegalState;
    }
}
