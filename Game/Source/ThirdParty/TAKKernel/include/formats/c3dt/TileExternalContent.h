#ifndef TAK_ENGINE_FORMATS_C3DT_TILEEXTERNALCONTENT_H
#define TAK_ENGINE_FORMATS_C3DT_TILEEXTERNALCONTENT_H

#include "Cesium3DTilesSelection/Tileset.h"

namespace TAK {
    namespace Engine {
        namespace Formats {
            namespace Cesium3DTiles {
                typedef std::unique_ptr<Cesium3DTilesSelection::TileExternalContent, void(*)(const Cesium3DTilesSelection::TileExternalContent *)> TileExternalContentPtr;
            }
        }
    }
}

#endif //TAK_ENGINE_FORMATS_C3DT_TILEEXTERNALCONTENT_H
