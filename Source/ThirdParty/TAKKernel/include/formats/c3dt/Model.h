#ifndef TAK_ENGINE_FORMATS_C3DT_MODEL_H
#define TAK_ENGINE_FORMATS_C3DT_MODEL_H

#include "math/Point2.h"
#include "port/Platform.h"
#include "util/Error.h"

#include "CesiumGltf/Model.h"
#include "CesiumGltfContent/GltfUtilities.h"

namespace TAK {
    namespace Engine {
        namespace Formats {
            namespace Cesium3DTiles {
                typedef std::unique_ptr<CesiumGltf::Model, void(*)(const CesiumGltf::Model *)> ModelPtr;

                ENGINE_API Util::TAKErr Model_intersectRayGltfModel(CesiumGltfContent::GltfUtilities::IntersectResult* intersectResult, double originx, double originy, double originz, double directionx, double directiony, double directionz, const CesiumGltf::Model &gltf) NOTHROWS;
                ENGINE_API Util::TAKErr Model_getRtc(Math::Point2<double>& rtc, const CesiumGltf::Model &gltf) NOTHROWS;
            }
        }
    }
}

#endif //TAK_ENGINE_FORMATS_C3DT_MODEL_H
