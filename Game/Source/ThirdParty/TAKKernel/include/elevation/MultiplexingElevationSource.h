//
// Created by Geo Dev on 5/9/24.
//

#ifndef TAK_ENGINE_ELEVATION_MULTIPLEXINGELEVATIONSOURCE_H
#define TAK_ENGINE_ELEVATION_MULTIPLEXINGELEVATIONSOURCE_H

#include <vector>

#include "elevation/ElevationSource.h"

namespace TAK {
    namespace Engine {
        namespace Elevation {
            class ENGINE_API MultiplexingElevationSource : public ElevationSource
            {
            public:
                MultiplexingElevationSource(const char *name, const std::shared_ptr<ElevationSource> *sources, const std::size_t count) NOTHROWS;
            public:
                const char *getName() const NOTHROWS override;
                Util::TAKErr query(ElevationChunkCursorPtr &value, const QueryParameters &params) NOTHROWS override;
                Feature::Envelope2 getBounds() const NOTHROWS override;
                Util::TAKErr addOnContentChangedListener(OnContentChangedListener *l) NOTHROWS override;
                Util::TAKErr removeOnContentChangedListener(OnContentChangedListener *l) NOTHROWS override;
            private :
                std::vector<std::shared_ptr<ElevationSource>> sources;
                Port::String name;
                Feature::Envelope2 bounds;
            };
        }
    }
}

#endif //TAK_ENGINE_ELEVATION_MULTIPLEXINGELEVATIONSOURCE_H
