#ifndef TAK_ENGINE_ELEVATION_ELEVATIONMANGERELEVATIONSOURCE_H_INCLUDED
#define TAK_ENGINE_ELEVATION_ELEVATIONMANGERELEVATIONSOURCE_H_INCLUDED

#include "elevation/ElevationManager.h"
#include "elevation/ElevationSource.h"
#include "port/Platform.h"
#include "util/Error.h"

namespace TAK {
    namespace Engine {
        namespace Elevation {
            /** @deprecated use `ElevationManagerElevationSource_create(ElevationSourcePtr& value)` */
            Util::TAKErr ENGINE_API ElevationManagerElevationSource_create(ElevationSourcePtr& value, const std::size_t numPostsLat, const std::size_t numPostLng, const HeightmapStrategy strategy = HighestResolution) NOTHROWS;
            Util::TAKErr ENGINE_API ElevationManagerElevationSource_create(ElevationSourcePtr& value) NOTHROWS;
        }
    }
}

#endif
