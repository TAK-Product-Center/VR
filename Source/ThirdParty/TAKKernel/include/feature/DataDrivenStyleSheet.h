#ifndef TAK_ENGINE_FEATURE_DATADRIVENSTYLESHEET_H_INCLUDED
#define TAK_ENGINE_FEATURE_DATADRIVENSTYLESHEET_H_INCLUDED

#include <cmath>
#include <functional>
#include <list>
#include <map>
#include <vector>

#include "feature/Feature2.h"
#include "feature/Geometry2.h"
#include "feature/Style.h"
#include "feature/StyleSheet.h"
#include "math/Rectangle2.h"
#include "port/String.h"
#include "renderer/Bitmap2.h"
#include "util/AttributeSet.h"

namespace TAK {
    namespace Engine {
        namespace Feature {
            class DataDrivenStyleSheet : public StyleSheet
            {
            public:
                enum FilterMode
                {
                    Any,
                    All,
                    Equals,
                    NotEquals,
                    In,
                    NotIn,
                    LessThan,
                    LessThanEqual,
                    MoreThan,
                    MoreThanEqual,
                    Has,
                    NotHas,
                    Always
                };

                struct StyleFilter;
                class StyleFilterBuilder;
            public :
                DataDrivenStyleSheet() NOTHROWS;
            public :
                void push(const char *layer, StyleFilterBuilder& f_, StylePtr_const&& s) NOTHROWS;
                Util::TAKErr getStyle(StylePtr_const& value, const char *layer, const int lod, const GeometryClass tegc, const std::function<Util::TAKErr(StyleSheet::Attribute *attr, const char *key, int schemaId)> &getAttribute) const NOTHROWS;
                Util::TAKErr getStyle(StylePtr_const& value, const char *layer, const int lod, const GeometryClass tegc, const atakmap::util::AttributeSet& attrs) const NOTHROWS;
            private :
                TAK::Engine::Port::String nameLocalAttrKey;
            };

            class DataDrivenStyleSheet::StyleFilterBuilder
            {
            public :
                StyleFilterBuilder() NOTHROWS;
            public :
                StyleFilterBuilder &setFilterMode(const FilterMode mode) NOTHROWS;
                StyleFilterBuilder &setKey(const char *key) NOTHROWS;
                StyleFilterBuilder &addValue(const char *value) NOTHROWS;
                StyleFilterBuilder &setCompareValue(const double compare) NOTHROWS;
                StyleFilterBuilder &appendChild(const StyleFilterBuilder &child) NOTHROWS;
            public :
                Util::TAKErr build(StyleFilter &value) const NOTHROWS;
            private :
                FilterMode mode {FilterMode::Any};
                std::string key;
                std::set<std::string> values;
                double compare{ 0.0 };
                std::vector<StyleFilterBuilder> children;
            };
        }
    }
}

#endif //TAK_ENGINE_FEATURE_STYLESHEET_H_INCLUDED