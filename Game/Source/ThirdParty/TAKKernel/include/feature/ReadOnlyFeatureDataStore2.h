//
// Created by Geo Dev on 2/23/25.
//

#ifndef TAK_ENGINE_FEATURE_READONLYFEATUREDATASTORE2_H
#define TAK_ENGINE_FEATURE_READONLYFEATUREDATASTORE2_H

#include "feature/AbstractDataSourceFeatureDataStore2.h"

namespace TAK {
    namespace Engine {
        namespace Feature {
            class ENGINE_API ReadOnlyFeatureDataStore2 : public AbstractFeatureDataStore2
            {
            protected :
                ReadOnlyFeatureDataStore2(int visibilityFlags) NOTHROWS;
            public :
                Util::TAKErr isFeatureSetReadOnly(bool *value, const int64_t fsid) NOTHROWS override;
                Util::TAKErr isFeatureReadOnly(bool *value, const int64_t fsid) NOTHROWS override;
            protected :
                Util::TAKErr beginBulkModificationImpl() NOTHROWS override;
                Util::TAKErr endBulkModificationImpl(const bool successful) NOTHROWS override;
                Util::TAKErr insertFeatureSetImpl(FeatureSetPtr_const *featureSet, const char *provider, const char *type, const char *name, const double minResolution, const double maxResolution) NOTHROWS override;
                Util::TAKErr updateFeatureSetImpl(const int64_t fsid, const char *name) NOTHROWS override;
                Util::TAKErr updateFeatureSetImpl(const int64_t fsid, const double minResolution, const double maxResolution) NOTHROWS override;
                Util::TAKErr updateFeatureSetImpl(const int64_t fsid, const char *name, const double minResolution, const double maxResolution) NOTHROWS override;
                Util::TAKErr deleteFeatureSetImpl(const int64_t fsid) NOTHROWS override;
                Util::TAKErr deleteAllFeatureSetsImpl() NOTHROWS override;
                Util::TAKErr insertFeatureImpl(FeaturePtr_const *feature, const int64_t fsid, const char *name, const atakmap::feature::Geometry &geom, const AltitudeMode altitudeMode, const double extrude, const atakmap::feature::Style *style, const atakmap::util::AttributeSet &attributes) NOTHROWS override;
                Util::TAKErr updateFeatureImpl(const int64_t fid, const char *name) NOTHROWS override;
                Util::TAKErr updateFeatureImpl(const int64_t fid, const atakmap::feature::Geometry &geom) NOTHROWS override;
                Util::TAKErr updateFeatureImpl(const int64_t fid, const TAK::Engine::Feature::AltitudeMode altitudeMode, const double extrude) NOTHROWS override;
                Util::TAKErr updateFeatureImpl(const int64_t fid, const atakmap::feature::Style *style) NOTHROWS override;
                Util::TAKErr updateFeatureImpl(const int64_t fid, const atakmap::util::AttributeSet &attributes) NOTHROWS override;
                Util::TAKErr updateFeatureImpl(const int64_t fid, const char *name, const atakmap::feature::Geometry &geom, const atakmap::feature::Style *style, const atakmap::util::AttributeSet &attributes) NOTHROWS override;
                Util::TAKErr deleteFeatureImpl(const int64_t fid) NOTHROWS override;
                Util::TAKErr deleteAllFeaturesImpl(const int64_t fsid) NOTHROWS override;
                Util::TAKErr setFeatureSetReadOnlyImpl(const int64_t fsid, const bool readOnly) NOTHROWS override;
                Util::TAKErr setFeatureSetsReadOnlyImpl(const FeatureSetQueryParameters &params, const bool readOnly) NOTHROWS override;
            };
        }
    }
}

#endif //TAK_ENGINE_FEATURE_READONLYFEATUREDATASTORE2_H
