#ifndef TAK_ENGINE_FORMATS_C3DT_TILE_H
#define TAK_ENGINE_FORMATS_C3DT_TILE_H

#include "port/Platform.h"
#include "port/String.h"
#include "util/Error.h"
#include "Cesium3DTilesSelection/Tileset.h"

namespace TAK {
    namespace Engine {
        namespace Formats {
            namespace Cesium3DTiles {
                typedef std::unique_ptr<Cesium3DTilesSelection::Tile, void(*)(const Cesium3DTilesSelection::Tile *)> TilePtr;

                ENGINE_API Util::TAKErr Tile_getContentType(int* contentType, const Cesium3DTilesSelection::Tile& tile) NOTHROWS;
                ENGINE_API Util::TAKErr Tile_getExternalContent(const Cesium3DTilesSelection::TileExternalContent** externalContent, const Cesium3DTilesSelection::Tile& tile) NOTHROWS;
                ENGINE_API Util::TAKErr Tile_getRenderContent(const Cesium3DTilesSelection::TileRenderContent** renderContent, const Cesium3DTilesSelection::Tile& tile) NOTHROWS;
                ENGINE_API Util::TAKErr Tile_estimateGlobeRectangle(std::optional<CesiumGeospatial::GlobeRectangle>* globeRectangle, const Cesium3DTilesSelection::BoundingVolume& boundingVolume) NOTHROWS;
                ENGINE_API Util::TAKErr Tile_isRenderable(bool* isRenderable, const Cesium3DTilesSelection::Tile& tile) NOTHROWS;
                ENGINE_API Util::TAKErr Tile_getRefine(int* refine, const Cesium3DTilesSelection::Tile& tile) NOTHROWS;
                ENGINE_API Util::TAKErr Tile_computeBoundingRegion(std::unique_ptr<CesiumGeospatial::BoundingRegion>& boundingRegion, const CesiumGeospatial::S2CellBoundingVolume &s2CellBoundingVolume) NOTHROWS;
                ENGINE_API Util::TAKErr Tile_createTileIdString(Port::String* tileId, const Cesium3DTilesSelection::Tile& tile) NOTHROWS;
            }
        }
    }
}

#endif //TAK_ENGINE_FORMATS_C3DT_TILE_H
