#include "elevation/MultiplexingElevationSource.h"

#include "elevation/ElevationManager.h"

using namespace TAK::Engine::Elevation;

using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Util;

MultiplexingElevationSource::MultiplexingElevationSource(const char *name_, const std::shared_ptr<ElevationSource> *sources_, const std::size_t count) NOTHROWS :
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
const char *MultiplexingElevationSource::getName() const NOTHROWS
{
    return name;
}
TAKErr MultiplexingElevationSource::query(ElevationChunkCursorPtr &value, const QueryParameters &params) NOTHROWS
{
    return ElevationManager_queryElevationSources(value, sources.data(), sources.size(), params);
}
Envelope2 MultiplexingElevationSource::getBounds() const NOTHROWS
{
    return bounds;
}
TAKErr MultiplexingElevationSource::addOnContentChangedListener(OnContentChangedListener *l) NOTHROWS
{
    bool err = false;
    for(auto &source : sources)
        err |= (source->addOnContentChangedListener(l) != TE_Ok);
    return err ? TE_Err : TE_Ok;
}
TAKErr MultiplexingElevationSource::removeOnContentChangedListener(OnContentChangedListener *l) NOTHROWS
{
    bool err = false;
    for(auto &source : sources)
        err |= (source->removeOnContentChangedListener(l) != TE_Ok);
    return err ? TE_Err : TE_Ok;
}
