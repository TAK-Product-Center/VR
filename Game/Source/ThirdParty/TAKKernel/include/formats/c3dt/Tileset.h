#ifndef TAK_ENGINE_FORMATS_C3DT_TILESET_H
#define TAK_ENGINE_FORMATS_C3DT_TILESET_H

#include "port/Platform.h"
#include "util/Error.h"

#include "Tile.h"
#include "Cesium3DTilesSelection/Tileset.h"

namespace TAK {
    namespace Engine {
        namespace Formats {
            namespace Cesium3DTiles {
                typedef std::unique_ptr<Cesium3DTilesSelection::Tileset, void(*)(const Cesium3DTilesSelection::Tileset *)> TilesetPtr;

                struct TilesetOpenOptions
                {
                    double maximumScreenSpaceError = 16.0;
                };

                ENGINE_API Util::TAKErr Tileset_create(TilesetPtr &result, const char* uri, std::shared_ptr<CesiumAsync::IAssetAccessor> &assetAccessor, const TilesetOpenOptions& opts) NOTHROWS;
                ENGINE_API Util::TAKErr Tileset_updateView(std::unique_ptr<const Cesium3DTilesSelection::ViewUpdateResult> &result,
                                                   Cesium3DTilesSelection::Tileset& tileset,
                                                   double positionx, double positiony, double positionz,
                                                   double directionx, double directiony, double directionz,
                                                   double upx, double upy, double upz,
                                                   double viewportSizex, double viewportSizey,
                                                   double hfov, double vfov) NOTHROWS;
                ENGINE_API Util::TAKErr Tileset_loadRootTileSync(Cesium3DTilesSelection::Tileset& tileset) NOTHROWS;
                ENGINE_API Util::TAKErr Tileset_getRootTile(const Cesium3DTilesSelection::Tile** tile, const Cesium3DTilesSelection::Tileset& tileset) NOTHROWS;
                ENGINE_API Util::TAKErr Tileset_destroy(Cesium3DTilesSelection::Tileset* tileset) NOTHROWS;
            }
        }
    }
}

#endif //TAK_ENGINE_FORMATS_C3DT_TILESET_H
