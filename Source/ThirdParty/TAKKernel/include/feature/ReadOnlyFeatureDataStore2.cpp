//
// Created by Geo Dev on 2/23/25.
//

#include "feature/ReadOnlyFeatureDataStore2.h"

using namespace TAK::Engine::Feature;

using namespace TAK::Engine::Util;

ReadOnlyFeatureDataStore2::ReadOnlyFeatureDataStore2(int visibilityFlags) NOTHROWS:
    AbstractFeatureDataStore2(0, visibilityFlags)
{}
TAKErr ReadOnlyFeatureDataStore2::beginBulkModificationImpl() NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::endBulkModificationImpl(const bool successful) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::insertFeatureSetImpl(FeatureSetPtr_const *featureSet, const char *provider, const char *type, const char *name, const double minResolution, const double maxResolution) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::updateFeatureSetImpl(const int64_t fsid, const char *name) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::updateFeatureSetImpl(const int64_t fsid, const double minResolution, const double maxResolution) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::updateFeatureSetImpl(const int64_t fsid, const char *name, const double minResolution, const double maxResolution) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::deleteFeatureSetImpl(const int64_t fsid) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::deleteAllFeatureSetsImpl() NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::insertFeatureImpl(FeaturePtr_const *feature, const int64_t fsid, const char *name, const atakmap::feature::Geometry &geom, const AltitudeMode altitudeMode, const double extrude, const atakmap::feature::Style *style, const atakmap::util::AttributeSet &attributes) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::updateFeatureImpl(const int64_t fid, const char *name) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::updateFeatureImpl(const int64_t fid, const atakmap::feature::Geometry &geom) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::updateFeatureImpl(const int64_t fid, const TAK::Engine::Feature::AltitudeMode altitudeMode, const double extrude) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::updateFeatureImpl(const int64_t fid, const atakmap::feature::Style *style) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::updateFeatureImpl(const int64_t fid, const atakmap::util::AttributeSet &attributes) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::updateFeatureImpl(const int64_t fid, const char *name, const atakmap::feature::Geometry &geom, const atakmap::feature::Style *style, const atakmap::util::AttributeSet &attributes) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::deleteFeatureImpl(const int64_t fid) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::deleteAllFeaturesImpl(const int64_t fsid) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::setFeatureSetReadOnlyImpl(const int64_t fsid, const bool readOnly) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::setFeatureSetsReadOnlyImpl(const FeatureSetQueryParameters &params, const bool readOnly) NOTHROWS { return TE_Unsupported; }
TAKErr ReadOnlyFeatureDataStore2::isFeatureSetReadOnly(bool *value, const int64_t fsid) NOTHROWS
{
    *value = true;
    return TE_Ok;
}
TAKErr ReadOnlyFeatureDataStore2::isFeatureReadOnly(bool *value, const int64_t fsid) NOTHROWS
{
    *value = true;
    return TE_Ok;
}
