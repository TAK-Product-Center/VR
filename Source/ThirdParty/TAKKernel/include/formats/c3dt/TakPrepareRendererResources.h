#ifndef TAK_ENGINE_FORMATS_C3DT_TAKPREPARERENDERERRESOURCES_H
#define TAK_ENGINE_FORMATS_C3DT_TAKPREPARERENDERERRESOURCES_H

#include "Cesium3DTilesSelection/IPrepareRendererResources.h"
#include "Cesium3DTilesSelection/TileLoadResult.h"

namespace TAK {
    namespace Engine {
        namespace Formats {
            namespace Cesium3DTiles {
                class TakPrepareRendererResources : public Cesium3DTilesSelection::IPrepareRendererResources {
                public:
                    CesiumAsync::Future<Cesium3DTilesSelection::TileLoadResultAndRenderResources>
                    prepareInLoadThread(const CesiumAsync::AsyncSystem &asyncSystem,
                                        Cesium3DTilesSelection::TileLoadResult &&tileLoadResult,
                                        const glm::dmat4 &transform, const std::any &rendererOptions) override;

                    void *prepareInMainThread(Cesium3DTilesSelection::Tile &tile, void *pLoadThreadResult) override;

                    void free(Cesium3DTilesSelection::Tile &tile, void *pLoadThreadResult,
                              void *pMainThreadResult) noexcept override;

                    void attachRasterInMainThread(const Cesium3DTilesSelection::Tile &tile,
                                                  int32_t overlayTextureCoordinateID,
                                                  const CesiumRasterOverlays::RasterOverlayTile &rasterTile,
                                                  void *pMainThreadRendererResources, const glm::dvec2 &translation,
                                                  const glm::dvec2 &scale) override;

                    void detachRasterInMainThread(const Cesium3DTilesSelection::Tile &tile,
                                                  int32_t overlayTextureCoordinateID,
                                                  const CesiumRasterOverlays::RasterOverlayTile &rasterTile,
                                                  void *pMainThreadRendererResources) noexcept override;

                    void *prepareRasterInLoadThread(CesiumGltf::ImageCesium &image,
                                                    const std::any &rendererOptions) override;

                    void *prepareRasterInMainThread(CesiumRasterOverlays::RasterOverlayTile &rasterTile,
                                                    void *pLoadThreadResult) override;

                    void freeRaster(const CesiumRasterOverlays::RasterOverlayTile &rasterTile, void *pLoadThreadResult,
                                    void *pMainThreadResult) noexcept override;
                };
            }
        }
    }
}

#endif //TAK_ENGINE_FORMATS_C3DT_TAKPREPARERENDERERRESOURCES_H
