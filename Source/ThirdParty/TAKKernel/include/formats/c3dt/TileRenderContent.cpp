#include "TileRenderContent.h"

CesiumGltf::Model* TAK::Engine::Formats::Cesium3DTiles::TileRenderContent_getModel(const Cesium3DTilesSelection::TileRenderContent* tileRenderContent)
{
    return new CesiumGltf::Model(tileRenderContent->getModel());
}
