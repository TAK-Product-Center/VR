#ifndef TAK_ENGINE_ELEVATION_VIRTUALCLODELEVATIONSOURCE_H
#define TAK_ENGINE_ELEVATION_VIRTUALCLODELEVATIONSOURCE_H

#include "elevation/ElevationManager.h"
#include "elevation/ElevationSource.h"

namespace TAK {
    namespace Engine {
        namespace Elevation {
            class ENGINE_API VirtualCLODElevationSource : public ElevationSource
            {
            public :
                class Builder;
            public:
                VirtualCLODElevationSource(const std::shared_ptr<ElevationSource> &impl, const HeightmapStrategy strategy = HeightmapStrategy::LowFillHoles, const bool forcePointSample = false) NOTHROWS;
            public:
                const char *getName() const NOTHROWS override;
                Util::TAKErr query(ElevationChunkCursorPtr &value, const QueryParameters &params) NOTHROWS override;
                Feature::Envelope2 getBounds() const NOTHROWS override;
                Util::TAKErr addOnContentChangedListener(OnContentChangedListener *l) NOTHROWS override;
                Util::TAKErr removeOnContentChangedListener(OnContentChangedListener *l) NOTHROWS override;
            private :
                std::shared_ptr<ElevationSource> impl;
                HeightmapStrategy strategy;
                bool forcePointSample;
            };

            class ENGINE_API VirtualCLODElevationSource::Builder
            {
            public :
                Builder() NOTHROWS;
            public :
                Builder &setSource(const std::shared_ptr<ElevationSource> &impl) NOTHROWS;
                Builder &setPointSampler(const bool forcePointSample) NOTHROWS;
                Builder &setStrategy(const HeightmapStrategy strategy) NOTHROWS;
                Builder &enableCaching(const char *path, const std::size_t cacheLimit, const bool async = false) NOTHROWS;
                Builder &optimizeForTileGrid(const int srid, const HeightmapParams &params) NOTHROWS;
                Util::TAKErr build(ElevationSourcePtr &value) NOTHROWS;
                Util::TAKErr build(std::shared_ptr<ElevationSource> &value) NOTHROWS;
            private :
                std::shared_ptr<ElevationSource> impl;
                HeightmapStrategy strategy {HeightmapStrategy::HighestResolution};
                bool forcePointSample {false};
                struct {
                    TAK::Engine::Port::String path;
                    std::size_t limit {0u};
                    bool async {false};
                } cache;
                int srid {-1};
                HeightmapParams params;
            };
        }
    }
}

#endif //TAK_ENGINE_ELEVATION_VIRTUALCLODELEVATIONSOURCE_H
