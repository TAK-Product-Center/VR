#ifndef TAK_ENGINE_FORMATS_QUANTIZEDMESH_TILEHEADER_H_INCLUDED
#define TAK_ENGINE_FORMATS_QUANTIZEDMESH_TILEHEADER_H_INCLUDED

#include "port/Platform.h"
#include "util/Error.h"
#include "util/DataInput2.h"

namespace TAK {
namespace Engine {
namespace Formats {
namespace QuantizedMesh {
namespace Impl {

class TileHeader {
public:
    static const int TOTAL_SIZE = (10 * 8) + (3 * 4);

    TileHeader() NOTHROWS;

    // The center of the tile in Earth-centered Fixed coordinates.
    double centerX {0.0};
    double centerY {0.0};
    double centerZ {0.0};
    
    // The minimum and maximum heights in the area covered by this tile.
    // The minimum may be lower and the maximum may be higher than
    // the height of any vertex in this tile in the case that the min/max vertex
    // was removed during mesh simplification, but these are the appropriate
    // values to use for analysis or visualization.
    float minimumHeight {0.f};
    float maximumHeight {0.f};

    // The tile’s bounding sphere.  The X,Y,Z coordinates are again expressed
    // in Earth-centered Fixed coordinates, and the radius is in meters.
    double boundingSphereCenterX {0.0};
    double boundingSphereCenterY {0.0};
    double boundingSphereCenterZ {0.0};
    double boundingSphereRadius {0.0};

    // The horizon occlusion point, expressed in the ellipsoid-scaled Earth-centered Fixed frame.
    // If this point is below the horizon, the entire tile is below the horizon.
    // See http://cesiumjs.org/2013/04/25/Horizon-culling/ for more information.
    double horizonOcclusionPointX {0.0};
    double horizonOcclusionPointY {0.0};
    double horizonOcclusionPointZ {0.0};

    float getHeight() const;

  private:
    friend Util::TAKErr TileHeader_deserialize(std::unique_ptr<TileHeader> &result, Util::DataInput2 &input) NOTHROWS;
    friend Util::TAKErr TileHeader_deserialize(TileHeader &result, Util::DataInput2 &input) NOTHROWS;
};

Util::TAKErr TileHeader_deserialize(std::unique_ptr<TileHeader> &result, Util::DataInput2 &input) NOTHROWS;
Util::TAKErr TileHeader_deserialize(TileHeader &result, Util::DataInput2 &input) NOTHROWS;

}
}
}
}
}

#endif
