#include "Model.h"

#include "CesiumGeometry/Ray.h"
#include "CesiumGltf/ExtensionCesiumRTC.h"

using namespace CesiumGltfContent;
using namespace TAK::Engine;
using namespace TAK::Engine::Util;

TAKErr TAK::Engine::Formats::Cesium3DTiles::Model_intersectRayGltfModel(CesiumGltfContent::GltfUtilities::IntersectResult* intersectResult, double originx, double originy, double originz, double directionx, double directiony, double directionz, const CesiumGltf::Model &gltf) NOTHROWS
{
    CesiumGeometry::Ray ray(glm::dvec3(originx, originy, originz),
                            glm::normalize(glm::dvec3(directionx, directiony, directionz)));
    *intersectResult = GltfUtilities::intersectRayGltfModel(ray, gltf);
    return TE_Ok;
}

TAKErr TAK::Engine::Formats::Cesium3DTiles::Model_getRtc(Math::Point2<double>& rtc, const CesiumGltf::Model &gltf) NOTHROWS
{
    // Start with default result
    rtc.x = 0;
    rtc.y = 0;
    rtc.z = 0;
    if (!gltf.hasExtension<CesiumGltf::ExtensionCesiumRTC>()) {
        return TE_Done;
    }
    auto rtcExt = gltf.getExtension<CesiumGltf::ExtensionCesiumRTC>();
    if (!rtcExt) {
        return TE_Done;
    }
    std::vector<double> rtcVector = rtcExt->center;
    rtc.x = rtcVector[0];
    rtc.y = rtcVector[1];
    rtc.z = rtcVector[2];
    return TE_Ok;
}
