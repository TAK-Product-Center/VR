#include "elevation/ResolutionConstrainedElevationSource.h"

using namespace TAK::Engine::Elevation;

using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Util;

ResolutionConstrainedElevationSource::ResolutionConstrainedElevationSource(const std::shared_ptr<ElevationSource> &impl_, const double minRes_, const double maxRes_) NOTHROWS :
    impl(impl_),
    minRes(minRes_),
    maxRes(maxRes_)
{}
const char *ResolutionConstrainedElevationSource::getName() const NOTHROWS
{
    return impl->getName();
}
TAKErr ResolutionConstrainedElevationSource::query(ElevationChunkCursorPtr &value, const QueryParameters &params) NOTHROWS
{
    QueryParameters constrainedParams(params);
    if(TE_ISNAN(constrainedParams.minResolution) || (!TE_ISNAN(minRes) && minRes < constrainedParams.minResolution))
        constrainedParams.minResolution = minRes;
    if(TE_ISNAN(constrainedParams.maxResolution) || (!TE_ISNAN(maxRes) && maxRes > constrainedParams.maxResolution))
        constrainedParams.maxResolution = maxRes;
    return impl->query(value, constrainedParams);
}
Envelope2 ResolutionConstrainedElevationSource::getBounds() const NOTHROWS
{
    return impl->getBounds();
}
TAKErr ResolutionConstrainedElevationSource::addOnContentChangedListener(OnContentChangedListener *l) NOTHROWS
{
    return impl->addOnContentChangedListener(l);
}
TAKErr ResolutionConstrainedElevationSource::removeOnContentChangedListener(OnContentChangedListener *l) NOTHROWS
{
    return impl->removeOnContentChangedListener(l);
}
