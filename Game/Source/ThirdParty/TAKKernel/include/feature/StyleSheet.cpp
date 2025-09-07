#include "feature/StyleSheet.h"

#include <cassert>

using namespace TAK::Engine::Feature;

using namespace TAK::Engine::Util;

TAKErr StyleSheet::getStyle(const LayerStyle **value, const char *layer) const NOTHROWS
{
    if(!layer)
        return TE_InvalidArg;
    auto entry = layers.find(layer);
    if(entry == layers.end())
        return TE_InvalidArg;
    *value = entry->second.get();
    return TE_Ok;
}
bool StyleSheet::empty() const NOTHROWS
{
    return layers.empty();
}
uint32_t StyleSheet::getBackground() const NOTHROWS
{
    return background;
}
void StyleSheet::setBackground(const uint32_t background_) NOTHROWS
{
    background = background_;
}
bool StyleSheet::hasSpriteSheet() const NOTHROWS
{
    return spriteSheet.bitmap && !spriteSheet.entries.empty();
}
TAKErr StyleSheet::getSpriteSheet(const Renderer::Bitmap2 **bitmap) const NOTHROWS
{
    *bitmap = spriteSheet.bitmap.get();
    return TE_Ok;
}
std::size_t StyleSheet::getNumSpriteMappings() const NOTHROWS
{
    return spriteSheet.entries.size();
}
TAKErr StyleSheet::getSpriteMapping(Port::String &path, Math::Rectangle2<float> &region, const std::size_t idx) const NOTHROWS
{
    if(idx >= spriteSheet.entries.size())
        return TE_InvalidArg;
    const auto entry = std::next(spriteSheet.entries.begin(), idx);
    if(entry == spriteSheet.entries.end())
        return TE_InvalidArg;

    path = entry->first.c_str();
    region = entry->second;
    return TE_Ok;
}
TAKErr StyleSheet::setSpriteSheet(Renderer::BitmapPtr_const &&bitmap) NOTHROWS
{
    spriteSheet.bitmap = std::move(bitmap);
    return TE_Ok;
}
TAKErr StyleSheet::addSpriteMapping(const char *path, const Math::Rectangle2<float> &region) NOTHROWS
{
    if(!path)
        return TE_InvalidArg;
    spriteSheet.entries[path] = region;
    return TE_Ok;
}
const char *StyleSheet::getExtrudeHeightKey() const NOTHROWS
{
    return extrudeHeightKey;
}
const char *StyleSheet::getExtrudeBaseHeightKey() const NOTHROWS
{
    return extrudeBaseHeightKey;
}
void StyleSheet::setExtrudeHeightKey(const char *key) NOTHROWS
{
    extrudeHeightKey = key;
}
void StyleSheet::setExtrudeBaseHeightKey(const char *key) NOTHROWS
{
    extrudeBaseHeightKey = key;
}
TAKErr StyleSheet::setLayerStyle(const char *layerId, LayerStylePtr &&style_) NOTHROWS
{
    std::shared_ptr<LayerStyle> style(std::move(style_));
    return setLayerStyle(layerId, style);
}
TAKErr StyleSheet::setLayerStyle(const char *layerId, std::shared_ptr<LayerStyle> &style) NOTHROWS
{
    if(!layerId)
        return TE_InvalidArg;
    if(!style)
        return TE_InvalidArg;
    layers[layerId] = style;
    return TE_Ok;
}
std::shared_ptr<StyleSheet::LayerStyle> &StyleSheet::getLayerStyle(const char *layerId) NOTHROWS
{
    return layers[layerId];
}

StyleSheet::LayerStyle::~LayerStyle() NOTHROWS
{}