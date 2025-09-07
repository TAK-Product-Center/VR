#ifndef TAK_ENGINE_FORMATS_QUANTIZEDMESH_TERRAINDATA_H_INCLUDED
#define TAK_ENGINE_FORMATS_QUANTIZEDMESH_TERRAINDATA_H_INCLUDED

#include "feature/Envelope2.h"
#include "port/Platform.h"
#include "util/Error.h"
#include "util/DataInput2.h"
#include "math/Vector4.h"
#include "thread/RWMutex.h"

#include "formats/quantizedmesh/impl/EdgeIndices.h"
#include "formats/quantizedmesh/impl/IndexData.h"
#include "formats/quantizedmesh/impl/TileHeader.h"
#include "formats/quantizedmesh/impl/VertexData.h"

namespace TAK {
namespace Engine {
namespace Formats {
namespace QuantizedMesh {
namespace Impl {

/**
 * Terrain data struct read from .terrain file
 */
class ENGINE_API TerrainData {
    
public:
    static const int MAX_RANGE = 32767;
    
    /**
     * Check if this tiles seams are resolved
     * @return True if this tiles seams are resolved
     */
    bool areSeamsResolved() NOTHROWS;

    /**
     * Resolve the seams between each tile and its neighbors, if any
     * Seams are common between adjacent tiles with a disparity in detail
     * @param neighbors Adjacent neighbors starting with the north, going clockwise
     */
    void resolveSeams(const std::vector<TerrainData *> &neighbors) NOTHROWS;
    int64_t getTotalSize() NOTHROWS;

    /**
     * Get elevation for a given point
     * @param lat Latitude
     * @param lng Longitude
     * @param convertToHAE True to convert MSL result to HAE
     * @return Elevation in meters (or NaN if not found)
     */
    double getElevation(double lat, double lon, bool convertToHAE) NOTHROWS;

    /**
     * Get elevations, in meters, for a given array of points.  Any elevation not found will have its corresponding
     * dst value set to NaN.
     * @param value output array.  Must be at least 'count' * 'dstStride' elements.
     * @param count number of points to query and populate 
     * @param srcLat latitude values for the source points.  Must be at least 'count' * 'srcLatStride' elements long
     * @param srcLng longitude values for the source points.  Must be at least 'count' * 'srcLonStride' elements long
     * @param srcLatStride number of elements in srcLat array between consecutive latitude values
     * @param srcLonStride number of elements in srcLng array between consecutive longitude values
     * @param dstStride number of elements in value array between consecutive output values
     * @param convertToHAE True to convert MSL results to HAE
     * @return TE_Ok if all elevations were found, TE_Done if at least one value was missing, or TE_Err if error is encountered
     */
    Util::TAKErr getElevation(double *value, const std::size_t count, const double *srcLat, const double *srcLng, 
            const std::size_t srcLatStride, const std::size_t srcLngStride, const std::size_t dstStride, bool convertToHAE) NOTHROWS;

    Feature::Envelope2 getBounds() const NOTHROWS;
private:
    /**
     * Triplet of vectors.  Heavily paired down port of Java Map Engine's Triangle class
     */
    struct TriVec {
        TriVec(const Math::Vector4<double> &v0, const Math::Vector4<double> &v1, const Math::Vector4<double> &v2);

        Math::Vector4<double> v0;
        Math::Vector4<double> v1;
        Math::Vector4<double> v2;
    };

    Thread::RWMutex mutex;
    int64_t totalSize;
    int srid;
    int level;
    int x;
    int y;
    double spacing;

    TileHeader header;
    VertexData vertexData;
    IndexData indexData;
    EdgeIndices edgeIndices;

    bool seamsResolved[4];
    std::vector<TriVec> skirts;



    TerrainData(int level, int srid) NOTHROWS;

    void addSkirt(const Math::Vector4<double> &v1, const Math::Vector4<double> &v2, const Math::Vector4<double> &v3) NOTHROWS;
    int findEdgeTriangle(int i1, int i2) NOTHROWS;
    int findEdgeTriangle(int d, int i1, int i2, const Math::Vector4<double> &v1, const Math::Vector4<double> &v2) NOTHROWS;

    void mirror(int dir, const TerrainData &other, const Math::Vector4<double> &vSrc, Math::Vector4<double>* vDst) NOTHROWS;

    /**
     * Transform Z-value to elevation
     * @param z Z value
     * @return Elevation in meters MSL
     */
    double zToElev(double z) const NOTHROWS;

    /**
     * Transform elevation to a Z-value on this tile
     * @param elev Elevation in meters MSL
     * @return Z value
     */
    double elevToZ(double elev) const NOTHROWS;

    /**
     * Convert lat/lng to tile coordinate (0.0 to 32767.0)
     * @param result Vector to store result
     * @param lat Latitude
     * @param lon Longitude
     */
    void getTileCoord(Math::Vector4<double> *result, double lat, double lon) NOTHROWS;
    
    double getElevationNoSync(double lat, double lng, bool convertToHAE,
            Math::Vector4<double> *vec) NOTHROWS;
    double getElevationNoSync(const Math::Vector4<double> &vec, bool ignoreSkirts) NOTHROWS;

    void resolveSeams(int d1, TerrainData *t1, TerrainData *t2) NOTHROWS;

    static Util::TAKErr deserialize(TerrainData &result, Util::DataInput2 &blob, const int level, const int srid, const bool sortEdges) NOTHROWS;

    friend Util::TAKErr ENGINE_API TerrainData_deserialize(std::unique_ptr<TerrainData> &result, const char* filename, int level, int srid) NOTHROWS;
    friend Util::TAKErr ENGINE_API TerrainData_deserialize(std::unique_ptr<TerrainData, void(*)(const TerrainData *)> &result, Util::DataInput2 &blob, int level, int srid) NOTHROWS;
};

typedef std::unique_ptr<TerrainData, void(*)(const TerrainData *)> TerrainDataPtr;

Util::TAKErr ENGINE_API TerrainData_deserialize(std::unique_ptr<TerrainData> &result, const char* filename, int level, int srid = 4326) NOTHROWS;
Util::TAKErr ENGINE_API TerrainData_deserialize(TerrainDataPtr &result, const char *filename, int level, int srid = 4326) NOTHROWS;
Util::TAKErr ENGINE_API TerrainData_deserialize(TerrainDataPtr &result, const uint8_t *buf, const std::size_t bufLen, int level, int srid = 4326) NOTHROWS;
Util::TAKErr ENGINE_API TerrainData_deserialize(TerrainDataPtr &result, Util::DataInput2 &blob, int level, int srid = 4326) NOTHROWS;

}
}
}
}
}

#endif
