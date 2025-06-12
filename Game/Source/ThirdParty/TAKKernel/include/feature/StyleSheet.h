#ifndef TAK_ENGINE_FEATURE_STYLESHEET_H_INCLUDED
#define TAK_ENGINE_FEATURE_STYLESHEET_H_INCLUDED

#include <cmath>
#include <functional>
#include <list>
#include <map>
#include <vector>

#include "feature/Feature2.h"
#include "feature/Geometry2.h"
#include "feature/Style.h"
#include "math/Rectangle2.h"
#include "renderer/Bitmap2.h"
#include "util/AttributeSet.h"

namespace TAK {
    namespace Engine {
        namespace Feature {
            class StyleSheet
            {
            public :
                class LayerStyle;
                typedef std::unique_ptr<LayerStyle, void(*)(const LayerStyle *)> LayerStylePtr;
            public:
                struct Attribute
                {
                    atakmap::util::AttributeSet::Type type{ atakmap::util::AttributeSet::STRING };
                    const char* s{ nullptr };
                    int i{ 0 };
                    double d{ NAN };
                };
            public :
                virtual Util::TAKErr getStyle(const LayerStyle **value, const char *layerName) const NOTHROWS;
                virtual bool empty() const NOTHROWS;
                virtual uint32_t getBackground() const NOTHROWS;
                virtual void setBackground(const uint32_t background) NOTHROWS;
                virtual bool hasSpriteSheet() const NOTHROWS;
                virtual Util::TAKErr getSpriteSheet(const Renderer::Bitmap2 **spritesheet) const NOTHROWS;
                virtual std::size_t getNumSpriteMappings() const NOTHROWS;
                virtual Util::TAKErr getSpriteMapping(Port::String &path, Math::Rectangle2<float> &region, const std::size_t idx) const NOTHROWS;
                virtual Util::TAKErr setSpriteSheet(Renderer::BitmapPtr_const &&spritesheet) NOTHROWS;
                virtual Util::TAKErr addSpriteMapping(const char *path, const Math::Rectangle2<float> &region) NOTHROWS;
                virtual const char *getExtrudeHeightKey() const NOTHROWS;
                virtual const char *getExtrudeBaseHeightKey() const NOTHROWS;
                virtual void setExtrudeHeightKey(const char *extrudeHeightKey) NOTHROWS;
                virtual void setExtrudeBaseHeightKey(const char *extrudeHeightKey) NOTHROWS;
            protected :
                virtual Util::TAKErr setLayerStyle(const char *layerId, LayerStylePtr &&style) NOTHROWS;
                virtual Util::TAKErr setLayerStyle(const char *layerId, std::shared_ptr<LayerStyle> &style) NOTHROWS;
                virtual std::shared_ptr<LayerStyle> &getLayerStyle(const char *layerId) NOTHROWS;
            private :
                uint32_t background {0u};
                struct {
                    std::map<std::string, TAK::Engine::Math::Rectangle2<float>> entries;
                    TAK::Engine::Renderer::BitmapPtr_const bitmap{nullptr, nullptr};
                } spriteSheet;
                std::map<std::string, std::shared_ptr<LayerStyle>> layers;
                Port::String extrudeHeightKey;
                Port::String extrudeBaseHeightKey;
            };

            class StyleSheet::LayerStyle
            {
            protected :
                ~LayerStyle() NOTHROWS;
            public :
                virtual Util::TAKErr getStyle(StylePtr_const& value, const int lod, const GeometryClass tegc, const std::function<Util::TAKErr(Attribute *attr, const char *key, int schemaId)> &getAttribute) const NOTHROWS = 0;
                virtual Util::TAKErr getStyle(StylePtr_const& value, const int lod, const GeometryClass tegc, const atakmap::util::AttributeSet& attrs) const NOTHROWS = 0;
            };
        }
    }
}

#endif //TAK_ENGINE_FEATURE_STYLESHEET_H_INCLUDED
