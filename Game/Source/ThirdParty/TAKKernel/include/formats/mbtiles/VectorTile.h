//
// Created by Geo Dev on 2/23/25.
//

#ifndef TAK_ENGINE_FORMATS_MBTILES_VECTORTILE_H
#define TAK_ENGINE_FORMATS_MBTILES_VECTORTILE_H

#include <map>
#include <vector>

#include "feature/ReadOnlyFeatureDataStore2.h"
#include "feature/StyleSheet.h"

namespace TAK {
    namespace Engine {
        namespace Formats {
            namespace MBTiles {
                class ENGINE_API VectorTile : public Feature::ReadOnlyFeatureDataStore2
                {
                private :
                    struct VectorFeature;
                    class FeatureCursorImpl;
                public :
                    VectorTile(const std::size_t zoom, const std::size_t x, const std::size_t y, const uint8_t *data, const std::size_t dataLen, const std::shared_ptr<Feature::StyleSheet> &styleSheet, const int srid = 3857) NOTHROWS;
                    ~VectorTile() NOTHROWS;
                public :
                    Util::TAKErr getFeature(Feature::FeaturePtr_const &feature, const int64_t fid) NOTHROWS override;
                    Util::TAKErr queryFeatures(Feature::FeatureCursorPtr &cursor) NOTHROWS override;
                    Util::TAKErr queryFeatures(Feature::FeatureCursorPtr &cursor, const FeatureQueryParameters &params) NOTHROWS override;
                    Util::TAKErr queryFeaturesCount(int *value) NOTHROWS override;
                    Util::TAKErr queryFeaturesCount(int *value, const FeatureQueryParameters &params) NOTHROWS override;
                    Util::TAKErr getFeatureSet(Feature::FeatureSetPtr_const &featureSet, const int64_t featureSetId) NOTHROWS override;
                    Util::TAKErr queryFeatureSets(Feature::FeatureSetCursorPtr &cursor) NOTHROWS override;
                    Util::TAKErr queryFeatureSets(Feature::FeatureSetCursorPtr &cursor, const FeatureSetQueryParameters &params) NOTHROWS override;
                    Util::TAKErr queryFeatureSetsCount(int *value) NOTHROWS override;
                    Util::TAKErr queryFeatureSetsCount(int *value, const FeatureSetQueryParameters &params) NOTHROWS override;
                    Util::TAKErr isFeatureVisible(bool *value, const int64_t fid) NOTHROWS override;
                    Util::TAKErr isFeatureSetVisible(bool *value, const int64_t setId) NOTHROWS override;
                    Util::TAKErr isAvailable(bool *value) NOTHROWS override;
                    Util::TAKErr refresh() NOTHROWS override;
                    Util::TAKErr getUri(Port::String &value) NOTHROWS override;
                    Util::TAKErr close() NOTHROWS override;
                protected :
                    Util::TAKErr setFeatureVisibleImpl(const int64_t fid, const bool visible) NOTHROWS override;
                    Util::TAKErr setFeaturesVisibleImpl(const FeatureQueryParameters &params, const bool visible) NOTHROWS override;
                    Util::TAKErr setFeatureSetVisibleImpl(const int64_t setId, const bool visible) NOTHROWS override;
                    Util::TAKErr setFeatureSetsVisibleImpl(const FeatureSetQueryParameters &params, const bool visible) NOTHROWS override;
                private:
                    std::shared_ptr<Feature::StyleSheet> stylesheet;
                    std::vector<VectorFeature> features;
                    std::map<int64_t, std::size_t> fidIndex;
                    std::map<int64_t, Feature::FeatureSet2> featureSets;
                    bool available;
                };
            }
        }
    }
}

#endif //TAK_ENGINE_FORMATS_MBTILES_VECTORTILE_H
