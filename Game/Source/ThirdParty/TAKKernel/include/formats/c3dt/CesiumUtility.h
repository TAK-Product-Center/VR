#ifndef TAK_ENGINE_FORMATS_C3DT_CESIUMUTILITY_H
#define TAK_ENGINE_FORMATS_C3DT_CESIUMUTILITY_H

#include <string>

#include "port/Platform.h"
#include "port/String.h"
#include "util/Error.h"

namespace TAK {
    namespace Engine {
        namespace Formats {
            namespace Cesium3DTiles {
                ENGINE_API Util::TAKErr CesiumUtility_nativePathToUriPath(TAK::Engine::Port::String *uriPath, const TAK::Engine::Port::String& nativePath) NOTHROWS;
            }
        }
    }
}


#endif //TAK_ENGINE_FORMATS_C3DT_CESIUMUTILITY_H
