#ifndef TAK_ENGINE_ELEVATION_HEIGHTMAPPARAMS_H_INCLUDED
#define TAK_ENGINE_ELEVATION_HEIGHTMAPPARAMS_H_INCLUDED

#include "feature/Envelope2.h"
#include "port/Platform.h"

namespace TAK {
    namespace Engine {
        namespace Elevation {
            struct ENGINE_API HeightmapParams
            {
                /**
                 * The bounds (inclusive) of the heightmap.
                 */
                Feature::Envelope2 bounds;
                /**
                 * The number of latitude samples/rows in the heightmap.
                 */
                std::size_t numPostsLat {0u};
                /**
                 * The number of longitude samples/columns in the heightmap.
                 */
                std::size_t numPostsLng {0u};
                /**
                 * if `false`, first row is max lat, last row is min lat; if `true` first row is
                 * min lat, last row is max lat.
                 */
                bool invertYAxis {false};
            };
        }
    }
}

#endif
