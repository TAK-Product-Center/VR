//
// Created by Geo Dev on 2/24/25.
//

#ifndef TAK_ENGINE_FEATURE_FEATURECURSOR2FILTER_H
#define TAK_ENGINE_FEATURE_FEATURECURSOR2FILTER_H

#include <set>

#include "feature/Geometry2.h"
#include "feature/Envelope2.h"
#include "feature/FeatureCursor2.h"
#include "feature/Style.h"
#include "port/Platform.h"
#include "util/Error.h"

namespace TAK {
    namespace Engine {
        namespace Feature {
            class ENGINE_API FeatureCursor2Filter
            {
            public :
                class Builder;
            protected :
                virtual ~FeatureCursor2Filter() NOTHROWS = 0;
            public :
                virtual Util::TAKErr accept(bool *value, TAK::Engine::Feature::FeatureCursor2 &feature) NOTHROWS = 0;
            };

            typedef std::unique_ptr<FeatureCursor2Filter, void(*)(const FeatureCursor2Filter *)> FeatureCursor2FilterPtr;

            class ENGINE_API FeatureCursor2Filter::Builder
            {
            public :
                Builder() NOTHROWS = default;
                Builder(const Builder &other) NOTHROWS;
                Builder(Builder &&other) NOTHROWS;
            public :
                Builder &setExtrudeOnly() NOTHROWS;
                Builder &setSpatialFilter(const Envelope2 &filter) NOTHROWS;
                Builder &setSpatialFilter(const Geometry2 &filter) NOTHROWS;
                Builder &setStyleFilter(const atakmap::feature::StyleClass *accept, const std::size_t acceptCount, const atakmap::feature::StyleClass *reject, const std::size_t rejectCount) NOTHROWS;
                FeatureCursor2FilterPtr build() NOTHROWS;
            private :
                struct {
                    std::set<atakmap::feature::StyleClass> accept;
                    std::set<atakmap::feature::StyleClass> reject;
                } styles;
                struct {
                    Geometry2Ptr_const geom {nullptr, nullptr};
                    Envelope2 mbb;
                    bool valid {false};
                } spatialFilter;
                bool extrudeOnly {false};
            };
        }
    }
}

#endif //TAK_ENGINE_FEATURE_FEATURECURSOR2FILTER_H
