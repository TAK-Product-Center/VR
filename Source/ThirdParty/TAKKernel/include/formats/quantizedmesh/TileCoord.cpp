#include "formats/quantizedmesh/TileCoord.h"

#include <cmath>

#include "raster/osm/OSMUtils.h"

namespace {
    struct LocalConsts {
    private:
        static const int numSpacings = 32;

    public:
        // Geodetic spacing at each level
        // Here we calculate the spacing of each level ahead of time to save processing
        double spacing[numSpacings];

        LocalConsts()
        {
            for (int i = 0; i < numSpacings; ++i)
                spacing[i] = 180.0 / (1 << i);
        }
    };

    const LocalConsts LOCAL_CONSTS;

    // The max GSD used for mobile imagery datasets
    const double DEFAULT_MAX_GSD = 156542.9878125;
}

// NOTE: all functions assume TMS tile grid origin (lower-left)

double TAK::Engine::Formats::QuantizedMesh::TileCoord_getLatitude(double y, int level, int srid)
{
    return (srid == 3857) ?
        atakmap::raster::osm::OSMUtils::mapnikTileLat(level, (1<<level)-(int)y-1) :
        (y * TileCoord_getSpacing(level, srid)) - 90;
}

double TAK::Engine::Formats::QuantizedMesh::TileCoord_getLongitude(double x, int level, int srid)
{
    return (srid == 3857) ?
           atakmap::raster::osm::OSMUtils::mapnikTileLng(level, (int)x) :
           (x * TileCoord_getSpacing(level, srid)) - 180;
}

double TAK::Engine::Formats::QuantizedMesh::TileCoord_getTileX(double lng, int level, int srid)
{
    return (srid == 3857) ?
           atakmap::raster::osm::OSMUtils::mapnikTileXd(level, lng) :
           (lng + 180) / TileCoord_getSpacing(level, srid);
}

double TAK::Engine::Formats::QuantizedMesh::TileCoord_getTileY(double lat, int level, int srid)
{
    return (srid == 3857) ?
           (1<<level)-atakmap::raster::osm::OSMUtils::mapnikTileYd(level, lat)-1 :
           (lat + 90) / TileCoord_getSpacing(level, srid);
}

int TAK::Engine::Formats::QuantizedMesh::TileCoord_getLevel(double gsd)
{
    return (int) round(log2(DEFAULT_MAX_GSD / gsd));
}

double TAK::Engine::Formats::QuantizedMesh::TileCoord_getSpacing(int level, int srid)
{
    return (srid == 3857) ?
           40007863.0 / (double)(1<<level) :
           LOCAL_CONSTS.spacing[level];
}

double TAK::Engine::Formats::QuantizedMesh::TileCoord_getGSD(int level)
{
    return DEFAULT_MAX_GSD / (1 << level);
}
