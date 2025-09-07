#include "CesiumUtility.h"

#include "CesiumUtility/Uri.h"

using namespace TAK::Engine::Util;

TAKErr TAK::Engine::Formats::Cesium3DTiles::CesiumUtility_nativePathToUriPath(TAK::Engine::Port::String *uriPath, const TAK::Engine::Port::String& nativePath) NOTHROWS
{
    auto uriPathStr = CesiumUtility::Uri::nativePathToUriPath(nativePath.get());
    *uriPath = uriPathStr.c_str();
    return TE_Ok;
}
