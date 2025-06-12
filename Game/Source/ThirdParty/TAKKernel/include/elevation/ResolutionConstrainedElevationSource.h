#ifndef TAK_ENGINE_ELEVATION_RESOLUTIONCONSTRAINEDELEVATIONSOURCE_H
#define TAK_ENGINE_ELEVATION_RESOLUTIONCONSTRAINEDELEVATIONSOURCE_H

#include "elevation/ElevationSource.h"

namespace TAK {
    namespace Engine {
        namespace Elevation {
            class ENGINE_API ResolutionConstrainedElevationSource : public ElevationSource
            {
            public:
                ResolutionConstrainedElevationSource(const std::shared_ptr<ElevationSource> &impl, const double minRes, const double maxRes) NOTHROWS;
            public:
                const char *getName() const NOTHROWS override;
                Util::TAKErr query(ElevationChunkCursorPtr &value, const QueryParameters &params) NOTHROWS override;
                Feature::Envelope2 getBounds() const NOTHROWS override;
                Util::TAKErr addOnContentChangedListener(OnContentChangedListener *l) NOTHROWS override;
                Util::TAKErr removeOnContentChangedListener(OnContentChangedListener *l) NOTHROWS override;
            private :
                std::shared_ptr<ElevationSource> impl;
                double minRes;
                double maxRes;
            };
        }
    }
}

#endif //TAK_ENGINE_ELEVATION_MULTIPLEXINGELEVATIONSOURCE_H
