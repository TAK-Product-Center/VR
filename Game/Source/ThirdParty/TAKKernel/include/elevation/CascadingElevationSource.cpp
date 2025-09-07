#include "elevation/CascadingElevationSource.h"

#include "elevation/ElevationManager.h"

using namespace TAK::Engine::Elevation;

using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Util;

namespace {
    class CursorImpl : public ElevationChunkCursor
    {
    public :
        CursorImpl(const std::vector<std::shared_ptr<ElevationSource>> &cursors, const ElevationSource::QueryParameters &params) NOTHROWS;
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
        std::vector<std::shared_ptr<ElevationSource>> sources;
        ElevationSource::QueryParameters params;
        int idx;
        ElevationChunkCursorPtr impl;
    };
}

CascadingElevationSource::CascadingElevationSource(const char *name_, const std::shared_ptr<ElevationSource> *sources_, const std::size_t count) NOTHROWS :
        name(name_),
        bounds(-180.0, -90.0, 0.0, 180.0, 90.0, 0.0)
{
    if(count) {
        sources.reserve(count);
        sources.push_back(sources_[0]);
        bounds = sources[0]->getBounds();
        for (std::size_t i = 1u; i < count; i++) {
            sources.push_back(sources_[i]);
            const auto &sourceBounds = sources[i]->getBounds();
            if(sourceBounds.minX < bounds.minX) bounds.minX = sourceBounds.minX;
            if(sourceBounds.minY < bounds.minY) bounds.minY = sourceBounds.minY;
            if(sourceBounds.maxX > bounds.maxX) bounds.maxX = sourceBounds.maxX;
            if(sourceBounds.maxY > bounds.maxY) bounds.maxY = sourceBounds.maxY;
        }
    }
}
const char *CascadingElevationSource::getName() const NOTHROWS
{
    return name;
}
TAKErr CascadingElevationSource::query(ElevationChunkCursorPtr &value, const QueryParameters &params) NOTHROWS
{
    value = ElevationChunkCursorPtr(new CursorImpl(sources, params), Memory_deleter_const<ElevationChunkCursor, CursorImpl>);
    return TE_Ok;
}
Envelope2 CascadingElevationSource::getBounds() const NOTHROWS
{
    return bounds;
}
TAKErr CascadingElevationSource::addOnContentChangedListener(OnContentChangedListener *l) NOTHROWS
{
    bool err = false;
    for(auto &source : sources)
        err |= (source->addOnContentChangedListener(l) != TE_Ok);
    return err ? TE_Err : TE_Ok;
}
TAKErr CascadingElevationSource::removeOnContentChangedListener(OnContentChangedListener *l) NOTHROWS
{
    bool err = false;
    for(auto &source : sources)
        err |= (source->removeOnContentChangedListener(l) != TE_Ok);
    return err ? TE_Err : TE_Ok;
}

namespace {
    CursorImpl::CursorImpl(const std::vector<std::shared_ptr<ElevationSource>> &sources_, const ElevationSource::QueryParameters &params_) NOTHROWS :
        sources(sources_),
        params(params_),
        idx(0),
        impl(nullptr, nullptr)
    {}

    TAKErr CursorImpl::moveToNext() NOTHROWS
    {
        do {
            if(impl) {
                const auto code = impl->moveToNext();
                if(code == TE_Done)
                    impl.reset();
                else
                    return code;
            } else if(idx < sources.size()) {
                const auto code = sources[idx++]->query(impl, params);
                if(code != TE_Ok)
                    return code;
            } else {
                break;
            }
        } while(true);
        return TE_Done;
    }
    TAKErr CursorImpl::get(ElevationChunkPtr &value) NOTHROWS
    {
        return impl ? impl->get(value) : TE_IllegalState;
    }
    TAKErr CursorImpl::getResolution(double *value) NOTHROWS
    {
        return impl ? impl->getResolution(value) : TE_IllegalState;
    }
    TAKErr CursorImpl::isAuthoritative(bool *value) NOTHROWS
    {
        return impl ? impl->isAuthoritative(value) : TE_IllegalState;
    }
    TAKErr CursorImpl::getCE(double *value) NOTHROWS
    {
        return impl ? impl->getCE(value) : TE_IllegalState;
    }
    TAKErr CursorImpl::getLE(double *value) NOTHROWS
    {
        return impl ? impl->getLE(value) : TE_IllegalState;
    }
    TAKErr CursorImpl::getUri(const char **value) NOTHROWS
    {
        return impl ? impl->getUri(value) : TE_IllegalState;
    }
    TAKErr CursorImpl::getType(const char **value) NOTHROWS
    {
        return impl ? impl->getType(value) : TE_IllegalState;
    }
    TAKErr CursorImpl::getBounds(const Polygon2 **value) NOTHROWS
    {
        return impl ? impl->getBounds(value) : TE_IllegalState;
    }
    TAKErr CursorImpl::getFlags(unsigned int *value) NOTHROWS
    {
        return impl ? impl->getFlags(value) : TE_IllegalState;
    }
}
