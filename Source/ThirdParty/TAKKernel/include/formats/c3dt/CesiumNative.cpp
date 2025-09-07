#include "CesiumNative.h"

CesiumAsync::Future<std::shared_ptr<CesiumAsync::IAssetRequest>>
TAK::Engine::Formats::Cesium3DTiles::runInWorkerThread(const CesiumAsync::AsyncSystem &asyncSystem, std::function<std::shared_ptr<CesiumAsync::IAssetRequest>()> f)
{
    return asyncSystem.runInWorkerThread(f);
}
