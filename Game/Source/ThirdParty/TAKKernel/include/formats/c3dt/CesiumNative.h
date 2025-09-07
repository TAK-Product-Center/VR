#ifndef TAK_ENGINE_FORMATS_C3DT_CESIUMNATIVE_H
#define TAK_ENGINE_FORMATS_C3DT_CESIUMNATIVE_H

#include "port/Platform.h"
#include "Cesium3DTilesSelection/Tileset.h"

namespace TAK {
    namespace Engine {
        namespace Formats {
            namespace Cesium3DTiles {
                ENGINE_API CesiumAsync::Future<std::shared_ptr<CesiumAsync::IAssetRequest>>
                runInWorkerThread(const CesiumAsync::AsyncSystem &asyncSystem, std::function<std::shared_ptr<CesiumAsync::IAssetRequest>()> f);
            }
        }
    }
}

#endif //TAK_ENGINE_FORMATS_C3DT_CESIUMNATIVE_H
