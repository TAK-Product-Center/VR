#include "TakPrepareRendererResources.h"
#include "CesiumAsync/AsyncSystem.h"

CesiumAsync::Future<Cesium3DTilesSelection::TileLoadResultAndRenderResources>
TAK::Engine::Formats::Cesium3DTiles::TakPrepareRendererResources::prepareInLoadThread(const CesiumAsync::AsyncSystem &asyncSystem,
                                                 Cesium3DTilesSelection::TileLoadResult &&tileLoadResult,
                                                 const glm::dmat4 &transform,
                                                 const std::any &rendererOptions) {
    return asyncSystem.runInWorkerThread(
            [&tileLoadResult]() {
                Cesium3DTilesSelection::TileLoadResultAndRenderResources result;
                result.result = tileLoadResult;
                return result;
            });
}

void* TAK::Engine::Formats::Cesium3DTiles::TakPrepareRendererResources::prepareInMainThread(Cesium3DTilesSelection::Tile &tile,
                                                       void *pLoadThreadResult) {
    return nullptr;
}

void TAK::Engine::Formats::Cesium3DTiles::TakPrepareRendererResources::free(Cesium3DTilesSelection::Tile &tile, void *pLoadThreadResult,
                                       void *pMainThreadResult) noexcept {

}

void TAK::Engine::Formats::Cesium3DTiles::TakPrepareRendererResources::attachRasterInMainThread(const Cesium3DTilesSelection::Tile &tile,
                                                           int32_t overlayTextureCoordinateID,
                                                           const CesiumRasterOverlays::RasterOverlayTile &rasterTile,
                                                           void *pMainThreadRendererResources,
                                                           const glm::dvec2 &translation,
                                                           const glm::dvec2 &scale) {

}

void TAK::Engine::Formats::Cesium3DTiles::TakPrepareRendererResources::detachRasterInMainThread(const Cesium3DTilesSelection::Tile &tile,
                                                           int32_t overlayTextureCoordinateID,
                                                           const CesiumRasterOverlays::RasterOverlayTile &rasterTile,
                                                           void *pMainThreadRendererResources) noexcept {

}

void* TAK::Engine::Formats::Cesium3DTiles::TakPrepareRendererResources::prepareRasterInLoadThread(CesiumGltf::ImageCesium &image,
                                                             const std::any &rendererOptions) {
    return nullptr;
}

void* TAK::Engine::Formats::Cesium3DTiles::TakPrepareRendererResources::prepareRasterInMainThread(
        CesiumRasterOverlays::RasterOverlayTile &rasterTile, void *pLoadThreadResult) {
    return nullptr;
}

void TAK::Engine::Formats::Cesium3DTiles::TakPrepareRendererResources::freeRaster(const CesiumRasterOverlays::RasterOverlayTile &rasterTile,
                                        void *pLoadThreadResult, void *pMainThreadResult) noexcept {

}
