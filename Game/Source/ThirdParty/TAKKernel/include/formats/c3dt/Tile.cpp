#include "Tile.h"

using namespace TAK::Engine::Util;

TAKErr TAK::Engine::Formats::Cesium3DTiles::Tile_getContentType(int* contentType, const Cesium3DTilesSelection::Tile& tile) NOTHROWS
{
    if (tile.getContent().isUnknownContent()) *contentType = 0;
    else if (tile.getContent().isEmptyContent()) *contentType = 1;
    else if (tile.getContent().isExternalContent()) *contentType = 2;
    else if (tile.getContent().isRenderContent()) *contentType = 3;
    else *contentType = 0;
    return TE_Ok;
}

TAKErr TAK::Engine::Formats::Cesium3DTiles::Tile_getRefine(int* refine, const Cesium3DTilesSelection::Tile& tile) NOTHROWS
{
    if (tile.getRefine() == Cesium3DTilesSelection::TileRefine::Add) *refine = 0;
    else if (tile.getRefine() == Cesium3DTilesSelection::TileRefine::Replace) *refine = 1;
    else *refine = -1;
    return TE_Ok;
}

TAKErr TAK::Engine::Formats::Cesium3DTiles::Tile_getExternalContent(const Cesium3DTilesSelection::TileExternalContent** externalContent, const Cesium3DTilesSelection::Tile& tile) NOTHROWS
{
    *externalContent = tile.getContent().getExternalContent();
    return TE_Ok;
}

TAKErr TAK::Engine::Formats::Cesium3DTiles::Tile_getRenderContent(const Cesium3DTilesSelection::TileRenderContent** renderContent, const Cesium3DTilesSelection::Tile& tile) NOTHROWS
{
    *renderContent = tile.getContent().getRenderContent();
    return TE_Ok;
}

TAKErr TAK::Engine::Formats::Cesium3DTiles::Tile_estimateGlobeRectangle(std::optional<CesiumGeospatial::GlobeRectangle>* globeRectangle, const Cesium3DTilesSelection::BoundingVolume& boundingVolume) NOTHROWS
{
    *globeRectangle = Cesium3DTilesSelection::estimateGlobeRectangle(boundingVolume);
    return TE_Ok;
}

TAKErr TAK::Engine::Formats::Cesium3DTiles::Tile_isRenderable(bool* isRenderable, const Cesium3DTilesSelection::Tile& tile) NOTHROWS
{
    *isRenderable = tile.isRenderable();
    return TE_Ok;
}

TAKErr TAK::Engine::Formats::Cesium3DTiles::Tile_computeBoundingRegion(std::unique_ptr<CesiumGeospatial::BoundingRegion>& boundingRegion, const CesiumGeospatial::S2CellBoundingVolume &s2CellBoundingVolume) NOTHROWS
{
    boundingRegion = std::unique_ptr<CesiumGeospatial::BoundingRegion>(new CesiumGeospatial::BoundingRegion(s2CellBoundingVolume.computeBoundingRegion()));
    return TE_Ok;
}

TAKErr TAK::Engine::Formats::Cesium3DTiles::Tile_createTileIdString(Port::String* tileId, const Cesium3DTilesSelection::Tile& tile) NOTHROWS
{
    std::string tileIdStr;
    if (std::holds_alternative<std::string>(tile.getTileID())){
        // String based tileIds may not be unique, so build hierarchy of ids
        const Cesium3DTilesSelection::Tile* it = &tile;
        while (it != nullptr) {
            tileIdStr += ";";
            tileIdStr += Cesium3DTilesSelection::TileIdUtilities::createTileIdString(it->getTileID());
            it = it->getParent();
        }
    } else {
        tileIdStr = Cesium3DTilesSelection::TileIdUtilities::createTileIdString(tile.getTileID());
    }
    *tileId = tileIdStr.c_str();
    return TE_Ok;
}
