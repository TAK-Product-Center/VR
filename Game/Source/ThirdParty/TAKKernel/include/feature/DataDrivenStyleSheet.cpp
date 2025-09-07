#include "feature/DataDrivenStyleSheet.h"

#include <cassert>

#include "util/ConfigOptions.h"

using namespace TAK::Engine::Feature;

using namespace TAK::Engine::Util;

namespace
{
    struct KVValue {
        unsigned valueid{ 63u };
        double compare{ NAN };

        // XXX-
        std::string raw;
    };
    class LayerStyleImpl : public StyleSheet::LayerStyle
    {
    private :
        std::vector<std::pair<DataDrivenStyleSheet::StyleFilter, std::shared_ptr<const atakmap::feature::Style>>> styleFilters;
        struct {
            /** filters */
            std::vector<std::pair<DataDrivenStyleSheet::StyleFilter, std::vector<std::size_t>>> v;
            /** interned keyid => v[i] */
            std::vector<std::pair<int, std::vector<std::size_t>>> m;
            /** indices of _parent_ filters (e.g. All, Any) */
            std::vector<std::size_t> p;
            std::vector<std::size_t> always;
            std::vector<std::size_t> nothas;
        } filterIndex;
        struct {
            struct {
                TAK::Engine::Util::StringMap<int> m;
                std::vector<std::pair<const char *, int>> v;
            } keys;
            TAK::Engine::Util::StringMap<int> values;
            std::size_t size() const NOTHROWS
            {
                return keys.m.size() + values.size();
            }
        } kvintern;
    public :
        const char *nameLocalAttrKey;
    private :
        void addToIndex(DataDrivenStyleSheet::StyleFilter& f, const std::size_t filterIdx) NOTHROWS;
    public :
        void push(const DataDrivenStyleSheet::StyleFilter& f_, StylePtr_const&& s) NOTHROWS;
        TAKErr getStyle(StylePtr_const& value, const int lod, const GeometryClass tegc, const std::function<TAKErr(StyleSheet::Attribute *attr, const char *key, int schemaId)> &getAttribute) const NOTHROWS override;
        TAKErr getStyle(StylePtr_const& value, const int lod, const GeometryClass tegc, const atakmap::util::AttributeSet& attrs) const NOTHROWS override;
        TAKErr getStyle(StylePtr_const& value, const int lod, const GeometryClass tegc, const std::vector<std::pair<int, KVValue>> &attrs) const NOTHROWS;
    };
    template<class T>
    bool contains(const T *arr, const std::size_t count, const T &v) NOTHROWS;
    template<class T>
    std::string toString(const T& v) NOTHROWS;
    bool varsubst(std::string &value, const char* txt, const atakmap::util::AttributeSet& attrs, const bool allowDupeSubst, const GeometryClass tegc, const char *nameLocalAttrKey) NOTHROWS;
    void flatten(std::vector<std::shared_ptr<atakmap::feature::Style>> &value, const int lod, const std::shared_ptr<const atakmap::feature::Style> &s, const atakmap::util::AttributeSet &attrs, const GeometryClass tegc, const char *nameLocalAttrKey) NOTHROWS;
    TAKErr getAttribute(KVValue *attr, const char* key, const atakmap::util::AttributeSet &attrs) NOTHROWS;
    bool filterMatches(const DataDrivenStyleSheet::StyleFilter &f, const GeometryClass tegc, const atakmap::util::AttributeSet& attrs) NOTHROWS;
    bool matches(const DataDrivenStyleSheet::StyleFilter& f, const std::vector<std::pair<int, KVValue>>& fastmap) NOTHROWS;
    bool matches(const DataDrivenStyleSheet::StyleFilter& f, const int attrKey, const KVValue& attrVal) NOTHROWS;
}

struct DataDrivenStyleSheet::StyleFilter
{
    FilterMode mode;
    struct {
        std::string raw;
        int interned{ -1 };
    } key;
    struct {
        std::set<std::string> raw;
        std::vector<unsigned> interned;
        uint64_t mask {0ULL};
    } values;
    double compare{ 0.0 };

    std::vector<StyleFilter> children;
    uint64_t childFilterMask{ 0ULL };

    bool operator==(const StyleFilter& other) const NOTHROWS;
};

bool DataDrivenStyleSheet::StyleFilter::operator==(const StyleFilter& other) const NOTHROWS
{
    if (mode != other.mode)
        return false;
    if (key.raw != other.key.raw)
        return false;
    if (values.raw != other.values.raw)
        return false;
    if (TE_ISNAN(compare) != TE_ISNAN(other.compare) || (!TE_ISNAN(compare) && compare != other.compare))
        return false;
    if (children.size() != other.children.size())
        return false;
    for (unsigned i = 0u; i < children.size(); i++)
        if (!(children[i] == other.children[i]))
            return false;
    return true;
}

DataDrivenStyleSheet::DataDrivenStyleSheet() NOTHROWS
{
    TAK::Engine::Port::String locale;
    ConfigOptions_getOption(locale, "locale");
    if(!locale)
        locale = "en";
    char nameLocal[9u];
    if(snprintf(nameLocal, 9u, "name:%s", locale.get()) > 0)
        nameLocalAttrKey = nameLocal;
}
void DataDrivenStyleSheet::push(const char *layer, DataDrivenStyleSheet::StyleFilterBuilder& f_, StylePtr_const&& s) NOTHROWS
{
    if(!layer)
        return;
    StyleFilter f;
    if(f_.build(f)  == TE_Ok) {
        auto &style = getLayerStyle(layer);
        if(!style)
            style.reset(new LayerStyleImpl());
        auto &styleImpl = static_cast<LayerStyleImpl &>(*style);
        styleImpl.nameLocalAttrKey = nameLocalAttrKey;
        styleImpl.push(f, std::move(s));
    }
}
TAKErr DataDrivenStyleSheet::getStyle(StylePtr_const& value, const char *layer, const int lod, const GeometryClass tegc, const std::function<TAKErr(StyleSheet::Attribute *attr, const char *key, int schemaId)> &getAttribute) const NOTHROWS
{
    TAKErr code(TE_Ok);
    const LayerStyle *styles = nullptr;
    code = StyleSheet::getStyle(&styles, layer);
    if(code != TE_Ok)
        return code;
    return styles->getStyle(value, lod, tegc, getAttribute);
}
TAKErr DataDrivenStyleSheet::getStyle(StylePtr_const& value, const char *layer, const int lod, const GeometryClass tegc, const atakmap::util::AttributeSet& attrs) const NOTHROWS
{
    TAKErr code(TE_Ok);
    const LayerStyle *styles = nullptr;
    code = StyleSheet::getStyle(&styles, layer);
    if(code != TE_Ok)
        return code;
    return styles->getStyle(value, lod, tegc, attrs);
}

DataDrivenStyleSheet::StyleFilterBuilder::StyleFilterBuilder() NOTHROWS
{}
DataDrivenStyleSheet::StyleFilterBuilder &DataDrivenStyleSheet::StyleFilterBuilder::setFilterMode(const FilterMode mode_) NOTHROWS
{
    mode = mode_;
    return *this;
}
DataDrivenStyleSheet::StyleFilterBuilder &DataDrivenStyleSheet::StyleFilterBuilder::setKey(const char *key_) NOTHROWS
{
    if(key_)
        key = key_;
    return *this;
}
DataDrivenStyleSheet::StyleFilterBuilder &DataDrivenStyleSheet::StyleFilterBuilder::addValue(const char *value) NOTHROWS
{
    if(value)
        values.insert(value);
    return *this;
}
DataDrivenStyleSheet::StyleFilterBuilder &DataDrivenStyleSheet::StyleFilterBuilder::setCompareValue(const double compare_) NOTHROWS
{
    compare = compare_;
    return *this;
}
DataDrivenStyleSheet::StyleFilterBuilder &DataDrivenStyleSheet::StyleFilterBuilder::appendChild(const DataDrivenStyleSheet::StyleFilterBuilder &child) NOTHROWS
{
    children.push_back(child);
    return *this;
}
TAKErr DataDrivenStyleSheet::StyleFilterBuilder::build(DataDrivenStyleSheet::StyleFilter &value) const NOTHROWS
{
    value.mode = mode;
    value.key.raw = key;
    value.compare = compare;
    for(const auto &v : values)
        value.values.raw.insert(v);
    if(!children.empty()) {
        value.children.reserve(children.size());
        for(const auto &child_ : children) {
            StyleFilter child;
            if(child_.build(child) == TE_Ok)
                value.children.push_back(child);
        }
    }
    return TE_Ok;
}

namespace {
    void LayerStyleImpl::addToIndex(DataDrivenStyleSheet::StyleFilter &f, const std::size_t filterIdx) NOTHROWS {
        // recurse if nested filters
        if (!f.children.empty()) {
            for (auto &c: f.children) {
                addToIndex(c, filterIdx);
                f.childFilterMask |= c.childFilterMask;
            }
            return;
        }

        const auto key = kvintern.keys.m.find(f.key.raw.c_str());
        if (key == kvintern.keys.m.end()) {
            f.key.interned = (int) kvintern.size();
            kvintern.keys.m[f.key.raw.c_str()] = f.key.interned;
            kvintern.keys.v.clear();
            for (const auto &e: kvintern.keys.m)
                kvintern.keys.v.push_back(std::make_pair(e.first, e.second));
        } else {
            f.key.interned = key->second;
        }
        for (const auto &v: f.values.raw) {
            // XXX - skip if integer
            const auto value = kvintern.values.find(v.c_str());
            if (value == kvintern.values.end()) {
                const auto vi = (unsigned) kvintern.size();
                f.values.interned.push_back(vi);
                f.values.mask |= 1ULL << vi;
                kvintern.values[v.c_str()] = vi;
            } else {
                if (!contains(f.values.interned.data(), f.values.interned.size(),
                              (unsigned) value->second))
                    f.values.interned.push_back(value->second);
                f.values.mask |= 1ULL << value->second;
            }
        }
        // search for match and append new index
        for (auto &e: filterIndex.v) {
            if (e.first == f) {
                e.second.push_back(filterIdx);
                return;
            }
        }

        // insert new filter with index
        //filterIndex.m[f.key.interned].push_back(filterIndex.v.size());
        for (int i = (int) filterIndex.m.size(); i <= f.key.interned; i++)
            filterIndex.m.push_back(
                    std::pair<int, std::vector<std::size_t>>(i, std::vector<std::size_t>()));

        filterIndex.m[f.key.interned].second.push_back(filterIndex.v.size());
        f.childFilterMask |= 1ULL << filterIndex.v.size();
        if (f.mode == DataDrivenStyleSheet::Always)
            filterIndex.always.push_back(filterIndex.v.size());
        else if (f.mode == DataDrivenStyleSheet::NotHas ||
                 f.mode == DataDrivenStyleSheet::NotEquals || f.mode == DataDrivenStyleSheet::NotIn)
            filterIndex.nothas.push_back(filterIndex.v.size());
        filterIndex.v.push_back(std::make_pair(f, std::vector<std::size_t>(1u, filterIdx)));
    }
    void LayerStyleImpl::push(const DataDrivenStyleSheet::StyleFilter& f_, StylePtr_const&& s) NOTHROWS
    {
        DataDrivenStyleSheet::StyleFilter f(f_);
        const std::size_t idx = styleFilters.size();
        addToIndex(f, idx);
        styleFilters.emplace_back(std::pair<DataDrivenStyleSheet::StyleFilter, std::shared_ptr<const atakmap::feature::Style>>(f, std::move(s)));
        if (!f.children.empty()) {
            for(std::size_t i = 0u; i < filterIndex.v.size(); i++) {
                for (const auto& pidx : filterIndex.v[i].second) {
                    if (pidx == idx) {
                        f.childFilterMask |= 1ULL << i;
                        break;
                    }
                }
            }
            filterIndex.p.push_back(idx);
        }
    }
    TAKErr LayerStyleImpl::getStyle(StylePtr_const& value, const int lod, const GeometryClass tegc, const std::function<TAKErr(StyleSheet::Attribute *attr, const char *key, int schemaId)> &getAttribute) const NOTHROWS
    {
        std::vector<std::pair<int, KVValue>> fastmap;
//if (fastmap.empty()) return Util::TE_Done;
        const auto kvintern_values_end = kvintern.values.end();
        const std::size_t nkeys = kvintern.keys.v.size();
        //for(const auto &n : kvintern.keys)
        for(std::size_t i = 0u; i < nkeys; i++)
        {
            const auto &n = kvintern.keys.v[i];
            StyleSheet::Attribute attr;
            if (getAttribute(&attr, n.first, n.second) != TE_Ok)
                continue;
            const auto at = attr.type;
            KVValue v;
            std::map<const char *, int, TAK::Engine::Port::StringLess>::const_iterator ve;
            switch (at) {
                case atakmap::util::AttributeSet::ATTRIBUTE_SET:
                case atakmap::util::AttributeSet::BLOB:
                case atakmap::util::AttributeSet::BLOB_ARRAY:
                case atakmap::util::AttributeSet::DOUBLE_ARRAY:
                case atakmap::util::AttributeSet::INT_ARRAY:
                case atakmap::util::AttributeSet::LONG_ARRAY:
                case atakmap::util::AttributeSet::STRING_ARRAY:
                    break;
                case atakmap::util::AttributeSet::STRING:
                    ve = kvintern.values.find(attr.s);
                    if (ve != kvintern_values_end)
                        v.valueid = ve->second;
                    break;
                case atakmap::util::AttributeSet::INT:
                    v.valueid = attr.i;
                    break;
                case atakmap::util::AttributeSet::LONG:
                    v.valueid = (int)attr.i;
                    break;
                case atakmap::util::AttributeSet::DOUBLE:
                    v.compare = attr.d;
                    break;
                default:
                    break;
            }
            fastmap.push_back(std::make_pair(n.second, v));
        }
        return getStyle(value, lod, tegc, fastmap);
    }
    TAKErr LayerStyleImpl::getStyle(StylePtr_const& value, const int lod, const GeometryClass tegc, const atakmap::util::AttributeSet& attrs) const NOTHROWS
    {
#if 0
        return getStyle(value, lod, tegc, [&attrs](Attribute *attr, const char* key, const int schemaId)
    {
        if (!attrs.containsAttribute(key))
            return Util::TE_InvalidArg;;
        attr->type = attrs.getAttributeType(key);
        switch (attr->type) {
        case atakmap::util::AttributeSet::ATTRIBUTE_SET:
        case atakmap::util::AttributeSet::BLOB:
        case atakmap::util::AttributeSet::BLOB_ARRAY:
        case atakmap::util::AttributeSet::DOUBLE_ARRAY:
        case atakmap::util::AttributeSet::INT_ARRAY:
        case atakmap::util::AttributeSet::LONG_ARRAY:
        case atakmap::util::AttributeSet::STRING_ARRAY:
            break;
        case atakmap::util::AttributeSet::STRING:
            attr->s = attrs.getString(key);
            return Util::TE_Ok;
        case atakmap::util::AttributeSet::INT:
            attr->i = attrs.getInt(key);
            return Util::TE_Ok;
        case atakmap::util::AttributeSet::LONG:
            attr->i = (int)attrs.getLong(key);
            return Util::TE_Ok;
        case atakmap::util::AttributeSet::DOUBLE:
            attr->d = attrs.getDouble(key);
            return Util::TE_Ok;
        default:
            break;
        }
        return Util::TE_InvalidArg;
    });
#else
        std::vector<std::shared_ptr<atakmap::feature::Style>> xstyles;
        if(tegc == GeometryClass::TEGC_LineString)
            xstyles.reserve(3u);

        //Map<String, Object> mattrs = ContentFeatureCursor.attr2map(attrs);
#if 0
        for (auto &f: filters) {
#else

        //for(std::size_t i = styleFilters.size(); i > 0u; i--)
        for(std::size_t i = 0u; i < styleFilters.size(); i++)
        {
            auto& f = styleFilters[i];
#endif
            auto &filter = f.first;
            if (filterMatches(filter, tegc, attrs)) {
                std::shared_ptr<const atakmap::feature::Style> s = f.second;
                if (!s)
                    continue;
                flatten(xstyles, lod, std::const_pointer_cast<atakmap::feature::Style>(s), attrs, tegc, nameLocalAttrKey);
            }
        }
#if 0
        for(auto &s : xstyles) {
        if(s->getClass() == atakmap::feature::TESC_LabelPointStyle) {
            const auto& label = static_cast<const atakmap::feature::LabelPointStyle&>(*s.get());
            if (!label.getText())
                continue;
            std::string factored;
            if (varsubst(factored, label.getText(), attrs, false)) {
                s.reset(
                        new atakmap::feature::LabelPointStyle(
                                factored.c_str(),
                                label.getTextColor(),
                                label.getBackgroundColor(),
                                label.getOutlineColor(),
                                label.getScrollMode(),
                                label.getFontFace(),
                                label.getTextSize(),
                                label.getStyle(),
                                label.getOffsetX(),
                                label.getOffsetY(),
                                label.getHorizontalAlignment(),
                                label.getVerticalAlignment(),
                                label.getRotation(),
                                label.isRotationAbsolute(),
                                label.getPaddingX(),
                                label.getPaddingY(),
                                label.getLabelMinRenderResolution(),
                                label.getLabelScale()));
            }
        }
        if(s->getClass() == atakmap::feature::TESC_IconPointStyle) {
            const auto& icon = static_cast<const atakmap::feature::IconPointStyle&>(*s.get());
            if (!icon.getIconURI())
                continue;
            if (strstr(icon.getIconURI(), "road_"))
                icon.getWidth();
            std::string factored;
            if (varsubst(factored, icon.getIconURI(), attrs, false)) {
                s.reset(
                        new atakmap::feature::IconPointStyle(
                                icon.getColor(),
                                factored.c_str(),
                                icon.getWidth(),
                                icon.getHeight(),
                                icon.getOffsetX(),
                                icon.getOffsetY(),
                                icon.getHorizontalAlignment(),
                                icon.getVerticalAlignment(),
                                icon.getRotation(),
                                icon.isRotationAbsolute()));
            }
        }
    }
#endif
        if (xstyles.empty()) {
            value.reset();
            //value = StylePtr_const(new atakmap::feature::BasicStrokeStyle(0xFF808080, 3.f), atakmap::feature::Style::destructStyle);
            //value = StylePtr_const(new atakmap::feature::BasicStrokeStyle(0xFFFF0000, 1.f), atakmap::feature::Style::destructStyle);
            return TAK::Engine::Util::TE_Done;
        } else if (xstyles.size() == 1) {
            value = StylePtr_const(xstyles[0]->clone(), atakmap::feature::Style::destructStyle);
            //} else if(true) {
            //    value = StylePtr_const(styles[styles.size()-1], TAK::Engine::Util::Memory_leaker_const<atakmap::feature::Style>);
        } else {
            StylePtr s(nullptr, nullptr);
            atakmap::feature::CompositeStyle_create(s, xstyles.data(), xstyles.size());
            value = StylePtr_const(s.release(), s.get_deleter());
        }

        return TAK::Engine::Util::TE_Ok;
#endif
    }
    TAKErr LayerStyleImpl::getStyle(StylePtr_const& value, const int lod, const GeometryClass tegc, const std::vector<std::pair<int, KVValue>> &attrs) const NOTHROWS
    {
        //if (true) return Util::TE_Done;

        // XXX - geometry type
        {
        }

        std::vector<const atakmap::feature::Style *> styles;
        if(tegc == GeometryClass::TEGC_LineString)
            styles.reserve(3u);

        //Map<String, Object> mattrs = ContentFeatureCursor.attr2map(attrs);
#if 0
        #if 0
    for (auto &f: filters) {
#else
    for(std::size_t i = filters.size(); i > 0u; i--) {
        auto& f = filters[i-1];
#endif
        auto &filter = f.first;
        if (filter(tegc, attrs)) {
            if (f.second)
                styles.push_back(f.second.get());
            // XXX - ???
            if (styles.size() > 2) {
                filter(tegc, attrs);
            }
        }
    }
#else

#define MATCHER(fff) this->matches(fff, attrs)
//#define MATCHER(fff) fff.filter(tegc, attrs)

        uint64_t matches{ 0ULL };
        std::size_t numMatches = 0u;
#if 1
        const auto filterIndexLimit = filterIndex.m.size();
        for(const auto &attributeEntry : attrs) {
            if (attributeEntry.first >= filterIndexLimit)
                continue;
            const auto& filterIndexEntry = filterIndex.m[attributeEntry.first];
            //if (filterIndexEntry == filterIndexLimit)
            //    continue;
            for (const auto filterValueIndex : filterIndexEntry.second) {
                const auto &e = filterIndex.v[filterValueIndex];
                if (::matches(e.first, attributeEntry.first, attributeEntry.second)) {
                    matches |= 1ULL << filterValueIndex;
                    numMatches++;
                    //matches.insert(e.second.begin(), e.second.end());
                } else {
                    //rejects.insert(e.second.begin(), e.second.end());
                }
            }
        }
        for (const auto filterValueIndex : filterIndex.always) {
            const auto &e = filterIndex.v[filterValueIndex];
            matches |= 1ULL << filterValueIndex;
            numMatches++;
        }
        for (const auto filterValueIndex : filterIndex.nothas) {
            const auto &e = filterIndex.v[filterValueIndex];
            bool has = false;
            for (const auto& attributeEntry : attrs) {
                if (attributeEntry.first == e.first.key.interned) {
                    has = true;
                    break;
                }
            }
            if (!has) {
                matches |= 1ULL << filterValueIndex;
                numMatches++;
                //matches.insert(e.second.begin(), e.second.end());
            } else {
                //rejects.insert(e.second.begin(), e.second.end());
            }
        }
#elif 1
        for(const auto &e : filterIndex) {
        if(MATCHER(e.first)) {
            matches.insert(e.second.begin(), e.second.end());
        } else {
            rejects.insert(e.second.begin(), e.second.end());
        }
    }
#else
    for (int i = 0; i < styleFilters.size(); i++)
        matches.insert(i);
#endif

        // no match
        if(!numMatches)
            return TAK::Engine::Util::TE_Done;

        std::list<std::shared_ptr<const atakmap::feature::Style>> srefs;
        // construct the style based on the matched indices
        for(std::size_t i = styleFilters.size(); i > 0u; i--) {
            auto& f = styleFilters[i-1];
            const atakmap::feature::Style *s = nullptr;
            if (!f.first.childFilterMask && ::matches(f.first, attrs)) {
                s = f.second.get();
            } else if (f.first.mode == DataDrivenStyleSheet::Any && (f.first.childFilterMask&matches)) {
                s = f.second.get();
                // XXX - ???
//                            if (styles.size() > 2) {
//                                filter(tegc, attrs);
//                            }
            } else if (f.first.mode == DataDrivenStyleSheet::All && (f.first.childFilterMask & matches) == f.first.childFilterMask) {
                s = f.second.get();
            }
            if (!s)
                continue;

            // XXX - use `flatten`
            if(s->getClass() == atakmap::feature::TESC_LevelOfDetailStyle) {
                const auto& simpl = static_cast<const atakmap::feature::LevelOfDetailStyle&>(*s);
                if (lod < 0) {
                    s = &simpl.getStyle();
                } else {
                    auto sref = simpl.getStyle((std::size_t)lod);
                    if (!sref)
                        continue;
                    s = sref.get();
                    srefs.push_back(sref);
                }
            }
            styles.push_back(s);
        }
        if (false) return TE_Done;
#endif
        if (styles.empty()) {
            value.reset();
            //value = StylePtr_const(new atakmap::feature::BasicStrokeStyle(0xFF808080, 3.f), atakmap::feature::Style::destructStyle);
            return TAK::Engine::Util::TE_Done;
        } else if (styles.size() == 1) {
            value = StylePtr_const(styles[0], TAK::Engine::Util::Memory_leaker_const<atakmap::feature::Style>);
            //} else if(true) {
            //    value = StylePtr_const(styles[styles.size()-1], TAK::Engine::Util::Memory_leaker_const<atakmap::feature::Style>);
        } else {
            StylePtr s(nullptr, nullptr);
            atakmap::feature::CompositeStyle_create(s, styles.data(), styles.size());
            value = StylePtr_const(s.release(), s.get_deleter());
        }

        return TAK::Engine::Util::TE_Ok;
    }

    template<class T>
    bool contains(const T *arr, const std::size_t count, const T &v) NOTHROWS {
        for (std::size_t i = 0; i < count; i++)
            if (arr[i] == v)
                return true;
        return false;
    }
    template<class T>
    std::string toString(const T& v) NOTHROWS
    {
        std::ostringstream strm;
        strm << v;
        return strm.str();
    }

    bool varsubst(std::string &value, const char *txt, const atakmap::util::AttributeSet &attrs,
                  const bool allowDupeSubst, const GeometryClass tegc, const char *nameLocalAttrKey) NOTHROWS {
        const auto txtlim = strlen(txt);
        std::ostringstream strm;
        int tokenStart = -1;
        bool subst = false;
        std::set<std::string> substs;
        for (unsigned j = 0; j < txtlim; j++) {
            if (txt[j] == '{') {
                tokenStart = (int) j + 1;
                subst = true;
            } else if (txt[j] == '}') {
                std::vector<char> token(j - tokenStart + 1, '\0');
                memcpy(token.data(), txt + tokenStart, (j - tokenStart) * sizeof(char));
                tokenStart = -1;
                const char *attrKey = token.data();
                if (TAK::Engine::Port::String_strcmp(token.data(), "name:latin") == 0 ||
                    TAK::Engine::Port::String_strcmp(token.data(), "name") == 0) {

                    if (attrs.containsAttribute(nameLocalAttrKey))
                        attrKey = nameLocalAttrKey;
                }
                if (!attrs.containsAttribute(attrKey)) {
                    if (TAK::Engine::Port::String_strcmp(token.data(), "name:latin") == 0 &&
                        attrs.containsAttribute("name"))
                        attrKey = "name";
                    else
                        continue;
                }
                switch (attrs.getAttributeType(attrKey)) {
                    case atakmap::util::AttributeSet::STRING : {
                        const char *substval = attrs.getString(attrKey);
                        if (substval &&
                            (allowDupeSubst || substs.insert(std::string(substval)).second))
                            strm << substval;
                        break;
                    }
                    case atakmap::util::AttributeSet::INT : {
                        strm << attrs.getInt(attrKey);
                        break;
                    }
                    case atakmap::util::AttributeSet::LONG : {
                        strm << attrs.getLong(attrKey);
                        break;
                    }
                    case atakmap::util::AttributeSet::DOUBLE : {
                        strm << attrs.getDouble(attrKey);
                        break;
                    }
                    default :
                        break;
                }
            } else if (tokenStart < 0) {
                strm << txt[j];
            }
        }
        if (subst) {
            value = strm.str();
            // trailing trim the string
            value.erase(std::find_if(value.rbegin(), value.rend(), [](unsigned char ch) {
                return !std::isspace(ch);
            }).base(), value.end());
        }
        return subst;
    }
    void flatten(std::vector<std::shared_ptr<atakmap::feature::Style>> &value, const int lod_, const std::shared_ptr<const atakmap::feature::Style> &s, const atakmap::util::AttributeSet &attrs, const GeometryClass tegc, const char *nameLocalAttrKey) NOTHROWS
    {
        switch(s->getClass()) {
            case atakmap::feature::TESC_LevelOfDetailStyle :
            {
                const auto &impl = static_cast<const atakmap::feature::LevelOfDetailStyle &>(*s);
                if(lod_ == -1) {
                    const std::size_t numLods = impl.getLevelOfDetailCount();
                    std::vector<std::shared_ptr<atakmap::feature::Style>> children;
                    std::vector<std::size_t> lods;
                    children.reserve(numLods);
                    lods.reserve(numLods);
                    for (std::size_t i = 0u; i < numLods; i++) {
                        auto lod = impl.getLevelOfDetail(i);
                        lods.push_back(lod);
                        if (i == (numLods - 1u))
                            lod--;
                        flatten(children, -1, impl.getStyle(lod), attrs, tegc, nameLocalAttrKey);
                    }
                    StylePtr flattened(nullptr, nullptr);
                    atakmap::feature::LevelOfDetailStyle_create(flattened, children.data(),
                                                                lods.data(), numLods);
                    value.push_back(std::move(flattened));
                } else {
                    auto child = impl.getStyle((std::size_t)lod_);
                    if(child)
                        flatten(value, lod_, child, attrs, tegc, nameLocalAttrKey);
                }
                break;
            }
            case atakmap::feature::TESC_CompositeStyle :
            {
                const auto &impl = static_cast<const atakmap::feature::CompositeStyle &>(*s);
                std::vector<std::shared_ptr<atakmap::feature::Style>> children;
                for(const auto &c : impl.components()) {
                    flatten(children, lod_, c, attrs, tegc, nameLocalAttrKey);
                }
                StylePtr flattened(nullptr, nullptr);
                atakmap::feature::CompositeStyle_create(flattened, children.data(), children.size());
                value.push_back(std::move(flattened));
                break;
            }
            case atakmap::feature::TESC_LabelPointStyle :
            {
                const auto& label = static_cast<const atakmap::feature::LabelPointStyle&>(*s.get());
                if (!label.getText())
                    break;
                std::string factored;
                if (varsubst(factored, label.getText(), attrs, false, tegc, nameLocalAttrKey)) {
                    const auto maxWidth = label.getMaxTextWidth();
                    if(maxWidth && tegc == TEGC_Point) {
                        std::size_t lineLen = 0u;
                        for (std::size_t i = 0u; i < factored.length(); i++) {
                            if (factored[i] == ' ' && lineLen >= maxWidth) {
                                factored[i] = '\n';
                                lineLen = 0u;
                            } else {
                                lineLen++;
                            }
                        }
                    }
                    value.push_back(std::shared_ptr<atakmap::feature::Style>(
                            new atakmap::feature::LabelPointStyle(
                                    factored.c_str(),
                                    label.getTextColor(),
                                    label.getBackgroundColor(),
                                    label.getOutlineColor(),
                                    label.getScrollMode(),
                                    label.getFontFace(),
                                    label.getTextSize(),
                                    label.getStyle(),
                                    label.getOffsetX(),
                                    label.getOffsetY(),
                                    label.getHorizontalAlignment(),
                                    label.getVerticalAlignment(),
                                    label.getRotation(),
                                    label.isRotationAbsolute(),
                                    label.getPaddingX(),
                                    label.getPaddingY(),
                                    label.getLabelMinRenderResolution(),
                                    label.getLabelScale())));
                } else {
                    value.push_back(std::const_pointer_cast<atakmap::feature::Style>(s));
                }
                break;
            }
            case atakmap::feature::TESC_IconPointStyle :
            {
                const auto& icon = static_cast<const atakmap::feature::IconPointStyle&>(*s.get());
                if (!icon.getIconURI())
                    break;
                std::string factored;
                if (varsubst(factored, icon.getIconURI(), attrs, false, tegc, nameLocalAttrKey)) {
                    value.push_back(std::shared_ptr<atakmap::feature::Style>(
                            new atakmap::feature::IconPointStyle(
                                    icon.getColor(),
                                    factored.c_str(),
                                    icon.getWidth(),
                                    icon.getHeight(),
                                    icon.getOffsetX(),
                                    icon.getOffsetY(),
                                    icon.getHorizontalAlignment(),
                                    icon.getVerticalAlignment(),
                                    icon.getRotation(),
                                    icon.isRotationAbsolute())));
                } else {
                    value.push_back(std::const_pointer_cast<atakmap::feature::Style>(s));
                }
                break;
            }
            default :
                value.push_back(std::const_pointer_cast<atakmap::feature::Style>(s));
                break;
        }
    }
    TAKErr getAttribute(KVValue *attr, const char* key, const atakmap::util::AttributeSet &attrs) NOTHROWS
    {
        if (!attrs.containsAttribute(key))
            return TE_InvalidArg;;
        switch (attrs.getAttributeType(key)) {
            case atakmap::util::AttributeSet::ATTRIBUTE_SET:
            case atakmap::util::AttributeSet::BLOB:
            case atakmap::util::AttributeSet::BLOB_ARRAY:
            case atakmap::util::AttributeSet::DOUBLE_ARRAY:
            case atakmap::util::AttributeSet::INT_ARRAY:
            case atakmap::util::AttributeSet::LONG_ARRAY:
            case atakmap::util::AttributeSet::STRING_ARRAY:
                break;
            case atakmap::util::AttributeSet::STRING:
                attr->raw = attrs.getString(key);
                return TE_Ok;
            case atakmap::util::AttributeSet::INT:
                attr->compare = attrs.getInt(key);
                // XXX -
                attr->raw = toString((int)attr->compare);
                return TE_Ok;
            case atakmap::util::AttributeSet::LONG:
                attr->compare = (int)attrs.getLong(key);
                // XXX -
                attr->raw = toString((int)attr->compare);
                return TE_Ok;
            case atakmap::util::AttributeSet::DOUBLE:
                attr->compare = attrs.getDouble(key);
                attr->raw = toString(attr->compare);
                return TE_Ok;
            default:
                break;
        }
        return TE_InvalidArg;
    }
    bool filterMatches(const DataDrivenStyleSheet::StyleFilter &f, const GeometryClass tegc, const atakmap::util::AttributeSet& attrs) NOTHROWS
    {
        if (f.mode == DataDrivenStyleSheet::Always)
            return true;
        else
        if(f.mode == DataDrivenStyleSheet::Any) {
            for (const auto& c : f.children)
                if (filterMatches(c, tegc, attrs))
                    return true;
            return false;
        } else if (f.mode == DataDrivenStyleSheet::All) {
            for (const auto& c : f.children)
                if (!filterMatches(c, tegc, attrs))
                    return false;
            return true;
        }

        if (!attrs.containsAttribute(f.key.raw.c_str()))
            return f.mode == DataDrivenStyleSheet::NotHas || f.mode == DataDrivenStyleSheet::NotEquals || f.mode == DataDrivenStyleSheet::NotIn;

        KVValue value;
        if (getAttribute(&value, f.key.raw.c_str(), attrs) != TE_Ok)
            return false;

        switch (f.mode) {
            // XXX - next two
            case DataDrivenStyleSheet::Any:
                return false;
            case DataDrivenStyleSheet::All:
                return true;
            case DataDrivenStyleSheet::Equals:
            case DataDrivenStyleSheet::In:
            {
                return f.values.raw.find(value.raw) != f.values.raw.end();
            }
            case DataDrivenStyleSheet::NotEquals:
            case DataDrivenStyleSheet::NotIn:
            {
                return f.values.raw.find(value.raw) == f.values.raw.end();
            }
            case DataDrivenStyleSheet::LessThan:
            {

                return value.compare < f.compare;
            }
            case DataDrivenStyleSheet::LessThanEqual:
            {
                return value.compare <= f.compare;
            }
            case DataDrivenStyleSheet::MoreThan:
            {
                return value.compare > f.compare;
            }
            case DataDrivenStyleSheet::MoreThanEqual:
            {
                return value.compare >= f.compare;
            }
            case DataDrivenStyleSheet::Has:
                //return fastmap.find(f.key.interned) != fastmap.end();
                return true;
            case DataDrivenStyleSheet::NotHas:
                //return fastmap.find(f.key.interned) == fastmap.end();
            default:
                return false;
        }
    }
    bool matches(const DataDrivenStyleSheet::StyleFilter& f, const std::vector<std::pair<int, KVValue>>& fastmap) NOTHROWS
    {
        switch (f.mode) {
            case DataDrivenStyleSheet::Always:
                return true;
            case DataDrivenStyleSheet::Any:
                for (const auto& c : f.children)
                    if (matches(c, fastmap))
                        return true;
                return false;
            case DataDrivenStyleSheet::All:
                for (const auto& c : f.children)
                    if (!matches(c, fastmap))
                        return false;
                return true;
            case DataDrivenStyleSheet::Equals:
            case DataDrivenStyleSheet::In:
            {
                for (const auto& e : fastmap) {
                    if (e.first == f.key.interned)
                        return contains(f.values.interned.data(), f.values.interned.size(), e.second.valueid);
                }
                return false;
            }
            case DataDrivenStyleSheet::NotEquals:
            case DataDrivenStyleSheet::NotIn:
            {
                for (const auto& e : fastmap) {
                    if (e.first == f.key.interned)
                        return !contains(f.values.interned.data(), f.values.interned.size(), e.second.valueid);;
                }
                return true;
            }
            case DataDrivenStyleSheet::LessThan:
            {
                for (const auto& e : fastmap) {
                    if (e.first == f.key.interned)
                        return e.second.compare < f.compare;
                }
                return false;
            }
            case DataDrivenStyleSheet::LessThanEqual:
            {
                for (const auto& e : fastmap) {
                    if (e.first == f.key.interned)
                        return e.second.compare <= f.compare;
                }
                return false;
            }
            case DataDrivenStyleSheet::MoreThan:
            {
                for (const auto& e : fastmap) {
                    if (e.first == f.key.interned)
                        return e.second.compare > f.compare;
                }
                return false;
            }
            case DataDrivenStyleSheet::MoreThanEqual:
            {
                for (const auto& e : fastmap) {
                    if (e.first == f.key.interned)
                        return e.second.compare >= f.compare;
                }
                return false;
            }
            case DataDrivenStyleSheet::Has:
                for (const auto& e : fastmap) {
                    if (e.first == f.key.interned)
                        return true;
                }
                return false;
            case DataDrivenStyleSheet::NotHas:
                for (const auto& e : fastmap) {
                    if (e.first == f.key.interned)
                        return false;
                }
                return true;
            default:
                return false;
        }
    }

    bool matches(const DataDrivenStyleSheet::StyleFilter& f, const int attrKey, const KVValue& attrVal) NOTHROWS
    {
        switch (f.mode) {
            case DataDrivenStyleSheet::Always:
                return true;
                // XXX - next two
            case DataDrivenStyleSheet::Any:
                for (const auto& c : f.children)
                    if (matches(c, attrKey, attrVal))
                        return true;
                return false;
            case DataDrivenStyleSheet::All:
                for (const auto& c : f.children)
                    if (!matches(c, attrKey, attrVal))
                        return false;
                return true;
            case DataDrivenStyleSheet::Equals:
            case DataDrivenStyleSheet::In:
            {
                //return f.values.interned.find(attrVal.valueid) != f.values.interned.end();
                return f.values.mask & (1ULL << attrVal.valueid);
            }
            case DataDrivenStyleSheet::NotEquals:
            case DataDrivenStyleSheet::NotIn:
            {
                //return f.values.interned.find(attrVal.valueid) == f.values.interned.end();
                return ~f.values.mask & (1ULL << attrVal.valueid);
            }
            case DataDrivenStyleSheet::LessThan:
            {
                return attrVal.compare < f.compare;
            }
            case DataDrivenStyleSheet::LessThanEqual:
            {
                return attrVal.compare <= f.compare;
            }
            case DataDrivenStyleSheet::MoreThan:
            {
                return attrVal.compare > f.compare;
            }
            case DataDrivenStyleSheet::MoreThanEqual:
            {
                return attrVal.compare >= f.compare;
            }
            case DataDrivenStyleSheet::Has:
                //return fastmap.find(f.key.interned) != fastmap.end();
                return true;
            case DataDrivenStyleSheet::NotHas:
                //return fastmap.find(f.key.interned) == fastmap.end();
            default:
                return false;
        }
    }
}

