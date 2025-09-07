#ifndef TAK_ENGINE_FORMATS_C3DT_TILERENDERCONTENT_H
#define TAK_ENGINE_FORMATS_C3DT_TILERENDERCONTENT_H

#include "port/Platform.h"

#include "Cesium3DTilesSelection/Tileset.h"

namespace TAK {
    namespace Engine {
        namespace Formats {
            namespace Cesium3DTiles {
                typedef std::unique_ptr<Cesium3DTilesSelection::TileRenderContent, void(*)(const Cesium3DTilesSelection::TileRenderContent *)> TileRenderContentPtr;

                ENGINE_API CesiumGltf::Model* TileRenderContent_getModel(const Cesium3DTilesSelection::TileRenderContent* tileRenderContent);
            }
        }
    }
}

#endif //TAK_ENGINE_FORMATS_C3DT_TILERENDERCONTENT_H
