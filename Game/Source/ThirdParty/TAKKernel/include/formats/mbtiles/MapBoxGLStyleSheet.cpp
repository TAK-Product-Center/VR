#include "formats/mbtiles/MapBoxGLStyleSheet.h"

#include <map>
#include <fstream>
#include <sstream>

#include "feature/DataDrivenStyleSheet.h"
#include "renderer/Bitmap2.h"
#include "renderer/BitmapFactory2.h"
#include "renderer/core/GLMapRenderGlobals.h"
#include "util/DataOutput2.h"
#include "util/ProtocolHandler.h"

using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Renderer;
using namespace TAK::Engine::Util;

namespace {
    struct Layer {
        struct Layout {
            TAK::Engine::Port::String visibility;
            TAK::Engine::Port::String lineCap;
            TAK::Engine::Port::String lineJoin;
            TAK::Engine::Port::String textField;
            TAK::Engine::Port::String textFont;
            std::vector<std::pair<int, float>> textSize;
            TAK::Engine::Port::String iconImage;
        };
        struct Paint {
            unsigned int backgroundColor{ 0u };
            float backgroundOpacity{ 0.f };
            unsigned int fillColor{ 0u };
            std::vector<std::pair<int, float>> fillOpacity;
            bool fillAntialias{ true };
            TAK::Engine::Port::String fillPattern;
            unsigned int lineColor{ 0u };
            std::vector<std::pair<int, float>> lineOpacity;
            std::vector<std::pair<int, float>> lineWidth;
            std::vector<float> lineDashArray;
            unsigned int textColor{ 0u };
            unsigned int textHaloColor{ 0u };
        };

        TAK::Engine::Port::String id;
        TAK::Engine::Port::String type;
        TAK::Engine::Port::String source;
        std::string sourceLayer;
        int minZoom{ 0 };
        int maxZoom{ 0 };
        DataDrivenStyleSheet::StyleFilterBuilder filter;
        Layout layout;
        Paint paint;
    };

    struct SpriteSheet
    {
        struct Entry
        {
            float x{ 0.f };
            float y{ 0.f };
            float width{ 0.f };
            float height{ 0.f };
            float pixelRatio{ 1.f };
        };

        std::shared_ptr<Bitmap2> bitmap;
        std::map<std::string, Entry> entries;
    };

    struct {
        int parseInt(const std::string &s, int radix = 10) {
            if (radix == 10) {
                return atoi(s.c_str());
            } else if(radix == 16) {
                unsigned int x;   
                std::stringstream ss;
                ss << std::hex << s;
                ss >> x;
                return x;
            } else {
                return 0;
            }
        }
    } Integer;

    struct {
        float parseFloat(const std::string &s) {
            return (float)atof(s.c_str());
        }
    } Float;

    struct {
    private :
        // trim from start (in place)
        inline void ltrim(std::string &s) {
            s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
                return !std::isspace(ch);
            }));
        }

        // trim from end (in place)
        inline void rtrim(std::string &s) {
            s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
                return !std::isspace(ch);
            }).base(), s.end());
        }
    public :
        std::string trim(const std::string &s_)
        {
            std::string s(s_);
            ltrim(s);
            rtrim(s);
            return s;
        }
        std::vector<std::string> split(const std::string& s_, const char delim, const bool trim_ = false)
        {
            std::vector<std::string> splits;
            std::string s(s_);
            size_t pos = 0;
            while ((pos = s.find(delim)) != std::string::npos) {
                auto token = s.substr(0, pos);
                if (trim_) {
                    token = trim(token);
                }
                splits.push_back(token);
                s.erase(0, pos + 1u);
            }
            splits.push_back(s);
            return splits;
        }
        std::vector<std::string> split(const char* s, const char delim, const bool trim_ = false)
        {
            return s ? split(std::string(s), delim, trim_) : std::vector<std::string>();
        }
    } String;

    struct {
        unsigned int HSVToColor(const uint8_t alpha, const float hsv[3])
        {
            // https://www.rapidtables.com/convert/color/hsv-to-rgb.html
            const float H = hsv[0] * 360.f;
            const float S = hsv[1];
            const float V = hsv[2];
            const float C = V * S;

            float X = C * (1.f - std::fabs(std::fmod((H / 60.f), 2.f) - 1.f));

            const float m = V - C;
            float r1, g1, b1;
            if(H < 60.f) {
                r1 = C;
                g1 = X;
                b1 = 0;
            } else if(H < 120.f) {
                r1 = X;
                g1 = C;
                b1 = 0;
            } else if(H < 180.f) {
                r1 = 0;
                g1 = C;
                b1 = X;
            } else if(H < 240.f) {
                r1 = 0;
                g1 = X;
                b1 = C;
            } else if(H < 300.f) {
                r1 = X;
                g1 = 0;
                b1 = C;
            } else {  // H < 360
                r1 = C;
                g1 = 0;
                b1 = X;
            }

            return ((unsigned int)alpha<<24) |
                    ((unsigned int)((r1+m)*255)<<16) |
                    ((unsigned int)((g1+m)*255)<<8) |
                    (unsigned int)((b1+m)*255);
        }
        unsigned int HSVToColor(const float hsv[3])
        {
            return HSVToColor(0xFFu, hsv);
        }
    } Color;

    TAK::Engine::Util::TAKErr paint2style(TAK::Engine::Feature::StylePtr& value, Layer layer, const float spriteHeight) NOTHROWS;
    TAK::Engine::Port::String optString(const nlohmann::json& json, const char* defValue) NOTHROWS;
    TAK::Engine::Port::String optString(const nlohmann::json& json, const char* key, const char* defValue) NOTHROWS;
    TAK::Engine::Port::String optString(const nlohmann::json& json, const std::size_t idx, const char* defValue) NOTHROWS;
    int optInt(const nlohmann::json& json, int defValue) NOTHROWS;
    int optInt(const nlohmann::json& json, const char* key, int defValue) NOTHROWS;
    double optDouble(const nlohmann::json& json, double defValue) NOTHROWS;
    double optDouble(const nlohmann::json& json, const char* key, double defValue) NOTHROWS;
    int optBoolean(const nlohmann::json& json, const char* key, bool defValue) NOTHROWS;
    nlohmann::json optJSONArray(const nlohmann::json& json, const char* key) NOTHROWS;
    nlohmann::json optJSONObject(const nlohmann::json& json, const char* key) NOTHROWS;
    DataDrivenStyleSheet::StyleFilterBuilder parseFilter(const nlohmann::json& filter) NOTHROWS;
    int parseColor(const std::string& color) NOTHROWS;
    int parseColor(const nlohmann::json& json) NOTHROWS;
    std::vector<std::pair<int, float>> parseFloatStopsValue(const nlohmann::json& json) NOTHROWS;
    std::vector<float> toFloatArray(const nlohmann::json& arr) NOTHROWS;
    Layer::Layout parseLayout(const nlohmann::json& json) NOTHROWS;
    Layer::Paint parsePaint(const nlohmann::json& json) NOTHROWS;
    bool parseLayer(Layer* layer, const nlohmann::json& json) NOTHROWS;
    SpriteSheet parseSprites(const char* path) NOTHROWS;
}

std::shared_ptr<StyleSheet> TAK::Engine::Formats::MBTiles::MapBoxGLStyleSheet_parse(const nlohmann::json &json, const char *styleDocPath) NOTHROWS
{
    std::shared_ptr<DataDrivenStyleSheet> ss(new DataDrivenStyleSheet());
    // XXX -
    ss->setExtrudeHeightKey("render_height");
    ss->setExtrudeBaseHeightKey("render_min_height");

    std::ostringstream spritesPath;
    const auto sprite = optString(json, "sprite", nullptr);
    if (sprite) {
        if(strstr(sprite, ":/") || strstr(sprite, ":\\") || !styleDocPath) {
            // if path appears to be absolute, then pass through
            spritesPath << sprite;
        } else {
            std::string styleDocDir(styleDocPath);
            while(!styleDocDir.empty()) {
                const char last = styleDocDir[styleDocDir.length()-1];
                styleDocDir.pop_back();
                if((last == '/') || (last == '/'))
                    break;
            }
            spritesPath << styleDocDir << '/' << sprite;
        }
    }

    auto sprites = parseSprites(spritesPath.str().c_str());
    float spriteHeight = 0.f;
    for(const auto &e : sprites.entries) {
        spriteHeight = std::max(spriteHeight, e.second.height);
    }

    // apply the spritesheet, if available
    if(!sprites.entries.empty() && sprites.bitmap) {
        ss->setSpriteSheet(BitmapPtr_const(new Bitmap2(*sprites.bitmap), Memory_deleter_const<Bitmap2>));
        for(const auto &r : sprites.entries) {
            ss->addSpriteMapping(r.first.c_str(), TAK::Engine::Math::Rectangle2<float>(r.second.x, r.second.y, r.second.width, r.second.height));
        }
    }

    const auto layers = json.find("layers");
    if(layers != json.end() && (*layers).is_array()) {
        for (int i = 0; i < (*layers).size(); i++) {
            Layer l;
            if (parseLayer(&l, (*layers)[i])) {
                if(TAK::Engine::Port::String_equal(l.type, "background") ) {
                    ss->setBackground(l.paint.fillColor);
                    continue;
                } else if(l.sourceLayer.empty()) {
                    continue;
                }
                TAK::Engine::Feature::StylePtr s(nullptr, nullptr);
                if(paint2style(s, l, spriteHeight) != TAK::Engine::Util::TE_Ok) {
                    continue;
                }

                // wrap with LOD
                if (s && (l.minZoom > 0 || l.maxZoom < 32) && s->getClass() != atakmap::feature::TESC_LevelOfDetailStyle) {
                    if(atakmap::feature::LevelOfDetailStyle_create(s, *s, l.minZoom, l.maxZoom) != TAK::Engine::Util::TE_Ok)
                        continue;
                }

                TAK::Engine::Feature::StylePtr_const sc(s.release(), s.get_deleter());
                                
                ss->push(l.sourceLayer.c_str(), l.filter, std::move(sc));
            }
        }
    }

    return ss;
}

namespace {
    TAKErr paint2style(StylePtr &value, Layer layer, const float spriteHeight) NOTHROWS
    {
        Layer::Paint paint = layer.paint;
        Layer::Layout layout = layer.layout;

        if(layout.visibility && TAK::Engine::Port::String_equal(layout.visibility, "none"))
            return TE_Done;

        if(paint.fillColor != 0) {
            uint32_t alpha = 0xFFFFFFFFu;
            if (!paint.fillOpacity.empty()) {
                alpha = ((uint32_t)(paint.fillOpacity[0].second * 255.f) << 24u) | 0x00FFFFFF;
            }
            if(paint.lineWidth.empty()) {
                value = StylePtr(new atakmap::feature::BasicFillStyle(paint.fillColor&alpha), atakmap::feature::Style::destructStyle);
            } else {
                std::vector<std::shared_ptr<atakmap::feature::Style>> fill;
                fill.reserve(2u);
                fill.push_back(std::shared_ptr<atakmap::feature::Style>(new atakmap::feature::BasicFillStyle(paint.fillColor&alpha)));
                fill.push_back(std::shared_ptr<atakmap::feature::Style>(new atakmap::feature::BasicStrokeStyle(paint.lineColor&alpha, paint.lineWidth[0].second)));
                value = TAK::Engine::Feature::StylePtr(new atakmap::feature::CompositeStyle(fill.data(), fill.size()), atakmap::feature::Style::destructStyle);
            }
            return TAK::Engine::Util::TE_Ok;
        } else if(paint.lineColor != 0) {
            constexpr std::size_t defaultFactor = 1u;
            constexpr uint16_t defaultPattern = (uint16_t)0xF0F0;

            if(paint.lineWidth.empty()) {
                StylePtr s1(new atakmap::feature::PatternStrokeStyle(defaultFactor, defaultPattern, paint.lineColor, 2.f), atakmap::feature::Style::destructStyle);
                StylePtr s2(new atakmap::feature::BasicStrokeStyle(paint.lineColor, 2.f), atakmap::feature::Style::destructStyle);

                value = std::move(!paint.lineDashArray.empty() ? s1 : s2);
                return TAK::Engine::Util::TE_Ok;
            } else if(paint.lineWidth.size() == 1) {
                StylePtr s1(new atakmap::feature::PatternStrokeStyle(defaultFactor, defaultPattern, paint.lineColor, paint.lineWidth[0].second), atakmap::feature::Style::destructStyle)  ;
                StylePtr s2(new atakmap::feature::BasicStrokeStyle(paint.lineColor, paint.lineWidth[0].second), atakmap::feature::Style::destructStyle);
                value = std::move(!paint.lineDashArray.empty() ? s1 : s2);
                return TAK::Engine::Util::TE_Ok;
            } else {
                std::vector<std::shared_ptr<atakmap::feature::Style>> stops;
                std::vector<std::size_t> lods;
                stops.reserve(paint.lineWidth.size());
                lods.reserve(paint.lineWidth.size());
                for(int i = 0; i < paint.lineWidth.size(); i++) {
                    StylePtr s1(new atakmap::feature::PatternStrokeStyle(defaultFactor, defaultPattern, paint.lineColor, paint.lineWidth[i].second), atakmap::feature::Style::destructStyle)  ;
                    StylePtr s2(new atakmap::feature::BasicStrokeStyle(paint.lineColor, paint.lineWidth[i].second), atakmap::feature::Style::destructStyle);

                    stops.push_back(!paint.lineDashArray.empty() ? std::move(s1) : std::move(s2));
                    lods.push_back(paint.lineWidth[i].first);
                }
                if (lods.front() > layer.minZoom) {
                    stops.insert(stops.begin(), stops.front());
                    lods.insert(lods.begin(), layer.minZoom);
                }
                if (lods.back() < layer.maxZoom+1) {
                    stops.push_back(stops.back());
                    lods.push_back((std::size_t)layer.maxZoom+1);
                }
                return atakmap::feature::LevelOfDetailStyle_create(value,
                    stops.data(),
                    lods.data(),
                    stops.size()
                );
            }
        }
                    
        StylePtr icon(nullptr, nullptr);
        StylePtr label(nullptr, nullptr);

        if (layout.iconImage) {
            icon = TAK::Engine::Feature::StylePtr(
                    new atakmap::feature::IconPointStyle(0xFFFFFFFFu, layout.iconImage),
                    atakmap::feature::Style::destructStyle);
        }

        if(paint.textColor != 0) {
            const float offY = icon ? spriteHeight/2.f + 4.f : 0.f;
            if (layout.textSize.empty()) {
                label = StylePtr(
                    new atakmap::feature::LabelPointStyle(
                        layout.textField,
                        paint.textColor,
                        0u,
                        paint.textHaloColor,
                        atakmap::feature::LabelPointStyle::DEFAULT,
                        nullptr,
                        0.f,
                        (atakmap::feature::LabelPointStyle::Style)0,
                        0.f, offY),
                    atakmap::feature::Style::destructStyle
                );
            } else if(layout.textSize.size() == 1) {
                label = StylePtr(
                    new atakmap::feature::LabelPointStyle(
                        layout.textField,
                        paint.textColor,
                        0u,
                        paint.textHaloColor,
                        atakmap::feature::LabelPointStyle::DEFAULT,
                        nullptr,
                        layout.textSize[0].second * Core::GLMapRenderGlobals_getRelativeDisplayDensity(),
                        (atakmap::feature::LabelPointStyle::Style)0,
                        0.f, offY),
                    atakmap::feature::Style::destructStyle
                );
            } else {
                std::vector<std::shared_ptr<atakmap::feature::Style>> stops;
                std::vector<std::size_t> lods;
                stops.reserve(layout.textSize.size());
                lods.reserve(layout.textSize.size());
                for(int i = 0; i < layout.textSize.size(); i++) {
                    stops.push_back(std::shared_ptr<atakmap::feature::Style>(
                        new atakmap::feature::LabelPointStyle(
                            layout.textField,
                            paint.textColor,
                            0u,
                            paint.textHaloColor,
                            atakmap::feature::LabelPointStyle::DEFAULT,
                            nullptr,
                            layout.textSize[i].second * Core::GLMapRenderGlobals_getRelativeDisplayDensity(),
                            (atakmap::feature::LabelPointStyle::Style)0,
                            0.f, offY)));
                    lods.push_back(layout.textSize[i].first);
                }
                if (lods.front() > layer.minZoom) {
                    stops.insert(stops.begin(), stops.front());
                    lods.insert(lods.begin(), layer.minZoom);
                }
                if (lods.back() < layer.maxZoom+1) {
                    stops.push_back(stops.back());
                    lods.push_back(layer.maxZoom+1);
                }
                const auto code = atakmap::feature::LevelOfDetailStyle_create(label,
                    stops.data(),
                    lods.data(),
                    stops.size()
                );
                if (code != TAK::Engine::Util::TE_Ok)
                    return code;
            }
        }

        if (label && icon) {
            std::shared_ptr<atakmap::feature::Style> labeledIcon[2u];
            labeledIcon[0] = std::move(icon);
            labeledIcon[1] = std::move(label);
            return atakmap::feature::CompositeStyle_create(value, labeledIcon, 2u);
        } else if(label) {
            value = std::move(label);
            return TAK::Engine::Util::TE_Ok;
        } else if(icon){
            value = std::move(icon);
            return TAK::Engine::Util::TE_Ok;
        } else {
            return TAK::Engine::Util::TE_InvalidArg;
        }
    }
    TAK::Engine::Port::String optString(const nlohmann::json &json, const char *defValue) NOTHROWS
    {
        if(json.is_string())
            return json.get<std::string>().c_str();
        else if(!json.is_number())
            return defValue;

        std::ostringstream strm;
        if (json.is_number_integer())
            strm << json.get<int>();
        else // v->is_number_float()
            strm << json.get<double>();
        return strm.str().c_str();
    }
    TAK::Engine::Port::String optString(const nlohmann::json &json, const char *key, const char *defValue) NOTHROWS
    {
        const auto v = json.find(key);
        if(v == json.end()) return defValue;
        else return optString(*v, defValue);
    }
    TAK::Engine::Port::String optString(const nlohmann::json &json, const std::size_t idx, const char *defValue) NOTHROWS
    {
        if (!json.is_array() || idx >= json.size()) return defValue;
        else return optString(json[idx], defValue);
    }
    int optInt(const nlohmann::json &json, int defValue) NOTHROWS
    {
        if (json.is_number_integer())
            return json.get<int>();
        else if(json.is_number_float())
            return (int)json.get<double>();
        else
            return defValue;
    }
    int optInt(const nlohmann::json &json, const char *key, int defValue) NOTHROWS
    {
        auto v = json.find(key);
        return (v == json.end()) ? defValue : optInt(*v, defValue);
    }
    double optDouble(const nlohmann::json &json, double defValue) NOTHROWS
    {
        if (json.is_number_float())
            return json.get<double>();
        else if (json.is_number_integer())
            return json.get<int>();
        else
            return defValue;
    }
    double optDouble(const nlohmann::json &json, const char *key, double defValue) NOTHROWS
    {
        auto v = json.find(key);
        return (v == json.end()) ? defValue : optDouble(*v, defValue);
    }
    int optBoolean(const nlohmann::json &json, const char *key, bool defValue) NOTHROWS
    {
        auto v = json.find(key);
        if(v == json.end())
            return defValue;
        else if(v->is_boolean())
            return v->get<bool>();
        else
            return defValue;
    }
    nlohmann::json optJSONArray(const nlohmann::json &json, const char *key) NOTHROWS
    {
        auto v = json.find(key);
        if(v == json.end())
            return nlohmann::json();
        else if(v->is_array())
            return *v;
        else
            return nlohmann::json();
    }
    nlohmann::json optJSONObject(const nlohmann::json &json, const char *key) NOTHROWS
    {
        auto v = json.find(key);
        if(v == json.end())
            return nlohmann::json();
        else if(v->is_object())
            return *v;
        else
            return nlohmann::json();
    }

    DataDrivenStyleSheet::StyleFilterBuilder parseFilter(const nlohmann::json &filter) NOTHROWS
    {
        DataDrivenStyleSheet::StyleFilterBuilder sf;
        if (filter.empty()) {
            sf.setFilterMode(DataDrivenStyleSheet::Always);
            return sf;
        }
        const auto key = optString(filter, 1, nullptr);
        if (key && key[0] == '$') {
            //sf.mode = DataDrivenStyleSheet::All;
            sf.setFilterMode(DataDrivenStyleSheet::Always);
            return sf;
        }
        const auto filterType = filter[0].get<std::string>();
        if(filterType == "==") {
            sf.setFilterMode(DataDrivenStyleSheet::Equals);
            sf.setKey(key);
            sf.addValue(optString(filter, 2, ""));
        } else if(filterType == "!=") {
            sf.setFilterMode(DataDrivenStyleSheet::NotEquals);
            sf.setKey(key);
            sf.addValue(optString(filter, 2, ""));
        } else if(filterType == "<=") {
            sf.setFilterMode(DataDrivenStyleSheet::LessThanEqual);
            sf.setKey(key);
            sf.setCompareValue(optDouble(filter[2], NAN));
        } else if(filterType == "<") {
            sf.setFilterMode(DataDrivenStyleSheet::LessThan);
            sf.setKey(key);
            sf.setCompareValue(optDouble(filter[2], NAN));
        } else if(filterType == ">=") {
            sf.setFilterMode(DataDrivenStyleSheet::MoreThanEqual);
            sf.setKey(key);
            sf.setCompareValue(optDouble(filter[2], NAN));
        } else if(filterType == ">") {
            sf.setFilterMode(DataDrivenStyleSheet::MoreThan);
            sf.setKey(key);
            sf.setCompareValue(optDouble(filter[2], NAN));
        } else if(filterType == "in") {
            sf.setFilterMode(DataDrivenStyleSheet::In);
            sf.setKey(key);
            for (std::size_t i = 2u; i < filter.size(); i++) {
                const auto v = optString(filter, i, nullptr);
                // XXX - nullptr?
                if(v)
                    sf.addValue(v);
            }
        } else if(filterType == "!in") {
            sf.setFilterMode(DataDrivenStyleSheet::NotIn);
            sf.setKey(key);
            const std::string k(key);
            for (std::size_t i = 2u; i < filter.size(); i++) {
                const auto v = optString(filter, i, nullptr);
                // XXX - nullptr?
                if(v)
                    sf.addValue(v);
            }
        } else if(filterType == "has") {
            sf.setFilterMode(DataDrivenStyleSheet::Has);
            sf.setKey(key);
        } else if(filterType == "!has") {
            sf.setFilterMode(DataDrivenStyleSheet::NotHas);
            sf.setKey(key);
        } else if(filterType == "any") {
            sf.setFilterMode(DataDrivenStyleSheet::Any);
            for(std::size_t i = 1u; i < filter.size(); i++)
                sf.appendChild(parseFilter(filter[i]));
        } else if(filterType == "all") {
            sf.setFilterMode(DataDrivenStyleSheet::All);
            for(std::size_t i = 1u; i < filter.size(); i++)
                sf.appendChild(parseFilter(filter[i]));
        } else {
            sf.setFilterMode(DataDrivenStyleSheet::Any);
        }
        return sf;
    }
    int parseColor(const std::string &color) NOTHROWS
    {
        if(color[0] == '#') {
            int rgb = Integer.parseInt(color.substr(1), 16);
            if(color.length() == 4) {
                const int r = (rgb&0xF00)>>4;
                const int g = (rgb&0xF0);
                const int b = (rgb&0xF)<<4;
                rgb = (r<<16)|(g<<8)|b;
            }
            return rgb|0xFF000000;
        } else if(color.find("rgb") == 0u) {
            auto tokens = String.split(color.substr(4, color.length() - 1), ',', true);
            const unsigned int r = Integer.parseInt(tokens[0])&0xFFu;
            const unsigned int g = Integer.parseInt(tokens[1])&0xFFu;
            const unsigned int b = Integer.parseInt(tokens[2])&0xFFu;
            return (0xFF << 24) | (r << 16) | (g << 8) | b;
        } else if(color.find("rgba") == 0u) {
            auto tokens = String.split(color.substr(5, color.length() - 1), ',', true);
            const unsigned int r = Integer.parseInt(tokens[0])&0xFFu;
            const unsigned int g = Integer.parseInt(tokens[1])&0xFFu;
            const unsigned int b = Integer.parseInt(tokens[2])&0xFFu;
            const unsigned int a = (unsigned int) (Float.parseFloat(tokens[3]) * 255.f);
            return (a << 24) | (r << 16) | (g << 8) | b;
        } else if(color.find("hsla") == 0u) {
            auto tokens = String.split(color.substr(5, color.length() - 1), ',', true);
            const float h = Integer.parseInt(tokens[0]) / 360.f;
            const float s = Integer.parseInt(tokens[1].substr(0, tokens[1].length() - 1)) / 100.f;
            const float v = Integer.parseInt(tokens[2].substr(0, tokens[2].length() - 1)) / 100.f;
            const int a = (int) (Float.parseFloat(tokens[3]) * 255.f);
            float hsv[3]{ h, s, v };
            return Color.HSVToColor(a, hsv);
        } else if(color.find("hsl") == 0u) {
            auto tokens = String.split(color.substr(4, color.length() - 1), ',', true);
            const float h = Integer.parseInt(tokens[0]) / 360.f;
            const float s = Integer.parseInt(tokens[1].substr(0, tokens[1].length() - 1)) / 100.f;
            const float v = Integer.parseInt(tokens[2].substr(0, tokens[2].length() - 1)) / 100.f;
            float hsv[3]{ h, s, v };
            return Color.HSVToColor(hsv);
        } else {
            bool isNum = !!color.length();
            for (std::size_t i = 0; i < color.length(); i++)
                isNum |= !!std::isdigit(color[i]);
            return isNum ? Integer.parseInt(color) : 0xFFFF0000;
        }
    }

    int parseColor(const nlohmann::json& json) NOTHROWS
    {
        auto stops = optJSONArray(json, "stops");
        return parseColor(stops[stops.size()-1][1].get<std::string>());
    }

    std::vector<std::pair<int, float>> parseFloatStopsValue(const nlohmann::json &json) NOTHROWS
    {
        const float base = (float)optDouble(json, "base", NAN);
        auto stops = optJSONArray(json, "stops");
        std::vector<std::pair<int, float>> fstops;
        fstops.reserve(stops.size() + (TE_ISNAN(base) ? 0 : 1));
        for(int i = 0; i < stops.size(); i++) {
            fstops.push_back(std::pair<int, float>(
                    optInt(stops[i][0], 0),
                    (float)optDouble(stops[i][1], NAN)
            ));
        }
        return fstops;
    }

    std::vector<float> toFloatArray(const nlohmann::json& arr) NOTHROWS
    {
        std::vector<float> f;
        f.reserve(arr.size());
        for(int i = 0; i < arr.size(); i++)
            f.push_back((float)optDouble(arr[i], 0.0));
        return f;
    }

    Layer::Layout parseLayout(const nlohmann::json &json) NOTHROWS
    {
        Layer::Layout layout;
        if(!json.empty()) {
            layout.lineCap = optString(json, "line-cap", "");
            layout.lineJoin = optString(json, "line-join", "");
            layout.visibility = optString(json, "visibility", nullptr);
            layout.textField = optString(json, "text-field", nullptr);
            // XXX - array
            layout.textFont = nullptr;
            auto textSize = json.find("text-size");
            if (textSize != json.end()) {
                if (textSize->is_number())
                    layout.textSize.push_back(std::make_pair<int, float>(0, textSize->get<float>()));
                else if (textSize->is_object())
                    layout.textSize = parseFloatStopsValue(*textSize);
            }
            auto iconImage = json.find("icon-image");
            if(iconImage != json.end()) {
                if(iconImage->is_string()) {
                    layout.iconImage = optString(json, "icon-image", nullptr);
                } else if(iconImage->is_array() && TAK::Engine::Port::String_equal(optString(*iconImage, (std::size_t)0u, nullptr), "match")) {
                    // grab the default icon from the last index
                    auto defIcon = iconImage->at(iconImage->size()-1u);
                    if(TAK::Engine::Port::String_equal(optString(defIcon, (std::size_t)0u, nullptr), "get")) {
                        const auto iconKey = optString(defIcon, 1u, nullptr);
                        if(iconKey) {
                            std::ostringstream strm;
                            strm << '{' << iconKey << '}';
                            layout.iconImage = strm.str().c_str();
                        }
                    }

                }
            }
        }
        return layout;
    }

    Layer::Paint parsePaint(const nlohmann::json &json) NOTHROWS
    {
        Layer::Paint paint;
        auto optColor = [&](unsigned int& color, const char *key)
        {
            auto entry = json.find(key);
            if(entry != json.end()) {
                if (entry->is_string()) {
                    color = parseColor(entry->get<std::string>());
                } else if (entry->is_object()) {
                    color = parseColor(*entry);
                }
            }
        };
        optColor(paint.backgroundColor, "background-color");
        paint.backgroundOpacity = (float)optDouble(json, "background-opacity", 1.0);
        paint.fillAntialias = optBoolean(json, "fill-antialias", true);
        optColor(paint.fillColor, "fill-color");
        if(!paint.fillColor) {
            optColor(paint.fillColor, "background-color");
        }
        auto fillOpacity = json.find("fill-opacity");
        if (fillOpacity != json.end()) {
            if (fillOpacity->is_number())
                paint.fillOpacity.push_back(std::make_pair<int, float>(0, fillOpacity->get<float>()));
            else if (fillOpacity->is_object())
                paint.fillOpacity = parseFloatStopsValue(*fillOpacity);
        }
        paint.fillPattern = optString(json, "fill-pattern", "");
        optColor(paint.lineColor, "line-color");
        auto lineOpacity = json.find("line-opacity");
        if (lineOpacity != json.end()) {
            if (lineOpacity->is_number())
                paint.lineOpacity.push_back(std::make_pair<int, float>(0, lineOpacity->get<float>()));
            else if (lineOpacity->is_object())
                paint.lineOpacity = parseFloatStopsValue(*lineOpacity);
        }
        auto lineWidth = json.find("line-width");
        if (lineWidth != json.end()) {
            if (lineWidth->is_number())
                paint.lineWidth.push_back(std::make_pair<int, float>(0, lineWidth->get<float>()));
            else if (lineWidth->is_object())
                paint.lineWidth = parseFloatStopsValue(*lineWidth);
        }
        auto lineDashArray = json.find("line-dasharray");
        if (lineDashArray != json.end()) {
            if (lineDashArray->is_number()) {
                paint.lineDashArray.push_back((float)optDouble(*lineDashArray, 2.0));
                paint.lineDashArray.push_back((float)optDouble(*lineDashArray, 2.0));
            }
            else if (lineDashArray->is_array()) {
                paint.lineDashArray = toFloatArray(*lineDashArray);
            }
        }
        optColor(paint.textColor, "text-color");
        optColor(paint.textHaloColor, "text-halo-color");

        if (!paint.lineColor && paint.fillColor) {
            optColor(paint.lineColor, "fill-outline-color");
            if (paint.lineWidth.empty())
                paint.lineWidth.push_back(std::pair<int, float>(0, 1.f));
        }
        return paint;
    }

    bool parseLayer(Layer *layer, const nlohmann::json &json) NOTHROWS
    {
        auto sourceLayer = optString(json, "source-layer", nullptr);
        layer->id = optString(json, "id", "");
        layer->type = optString(json, "type", "");
        layer->source = optString(json, "source", "");
        layer->sourceLayer = optString(json, "source-layer", "");
        layer->minZoom = optInt(json, "minzoom", 0);
        layer->maxZoom = optInt(json, "maxzoom", (int)atakmap::feature::LevelOfDetailStyle::MAX_LOD-1);
        layer->filter = parseFilter(optJSONArray(json, "filter"));
        layer->layout = parseLayout(optJSONObject(json, "layout"));
        layer->paint = parsePaint(optJSONObject(json, "paint"));
        return true;
    }

    SpriteSheet parseSprites(const char* path) NOTHROWS
    {
        SpriteSheet sprites;

        // load json and parse entries
        {
            std::ostringstream strm;
            strm << path << ".json";

            std::stringstream buffer;
            DataInput2Ptr assetStream(nullptr, nullptr);
            if(ProtocolHandler_handleURI(assetStream, strm.str().c_str()) != TE_Ok)
                return sprites;

            char buf[4096];
            std::size_t numRead;
            while(assetStream->read(reinterpret_cast<uint8_t *>(buf), &numRead, 512) == TE_Ok) {
                buffer.write(buf, numRead);
            }

            auto sprites_json = nlohmann::json::parse(buffer.str());

            for(auto it = sprites_json.begin(); it != sprites_json.end(); it++) {
                const auto v = it.value();
                if(v.is_object()) {
                    SpriteSheet::Entry entry;
                    entry.x = (float)optDouble(v, "x", 0.0);
                    entry.y = (float)optDouble(v, "y", 0.0);
                    entry.width = (float)optDouble(v, "width", 0.0);
                    entry.height = (float)optDouble(v, "height", 0.0);
                    entry.pixelRatio = (float)optDouble(v, "pixelRatio", 1.0);
                    if (!entry.width || !entry.height)
                        continue;
                    sprites.entries[it.key()] = entry;
                }
            }
        }
        // load bitmap
        {
            std::ostringstream strm;
            strm << path << ".png";
            DataInput2Ptr bitmapStream(nullptr, nullptr);
            ProtocolHandler_handleURI(bitmapStream, strm.str().c_str());
            BitmapPtr bitmap(nullptr, nullptr);
            if (!bitmapStream || BitmapFactory2_decode(bitmap, *bitmapStream, nullptr) != TE_Ok)
                BitmapFactory2_decode(bitmap, strm.str().c_str(), nullptr);
            sprites.bitmap = std::move(bitmap);
        }
        return sprites;
    }
}
