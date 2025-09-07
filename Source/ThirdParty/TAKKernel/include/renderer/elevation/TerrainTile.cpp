#include "renderer/elevation/TerrainTile.h"

#include <cmath>

#include "core/Projection2.h"
#include "core/ProjectionFactory3.h"
#include "math/Mesh.h"
#include "math/Rectangle.h"
#include "util/MathUtils.h"

using namespace TAK::Engine::Renderer::Elevation;

using namespace TAK::Engine::Core;
using namespace TAK::Engine::Math;
using namespace TAK::Engine::Util;

TAKErr TAK::Engine::Renderer::Elevation::TerrainTile_getElevation(double *value, const TerrainTile &tile, const double latitude, const double longitude) NOTHROWS
{
    *value = NAN;
    
    // AABB/bounds check
    const TAK::Engine::Feature::Envelope2 aabb_wgs84 = tile.aabb_wgs84;
    if (!atakmap::math::Rectangle<double>::contains(aabb_wgs84.minX,
                                                    aabb_wgs84.minY,
                                                    aabb_wgs84.maxX,
                                                    aabb_wgs84.maxY,
                                                    longitude, latitude)) {
        return TE_InvalidArg;
    }

    // the tile has no elevation data values...
    if (!tile.hasData) {
        // if on a border, continue as other border tile may have data, else break
        if(aabb_wgs84.minX < longitude && aabb_wgs84.maxX > longitude &&
           aabb_wgs84.minY < latitude && aabb_wgs84.maxY > latitude) {
    
           *value = 0.0;
           return TE_Ok;
        } else {
            return TE_InvalidArg;
        }
    }
    if(!tile.heightmap) {
        // if there's no heightmap, shoot a nadir ray into the
        // terrain tile mesh and obtain the height at the
        // intersection
        Projection2Ptr proj(nullptr, nullptr);
        if (ProjectionFactory3_create(proj, tile.data.srid) != TE_Ok)
            return TE_Err;

        Matrix2 invLocalFrame;
        tile.data.localFrame.createInverse(&invLocalFrame);

        // obtain the ellipsoid surface point
        Point2<double> surface;
        if (proj->forward(&surface, GeoPoint2(latitude, longitude)) != TE_Ok)
            return TE_Err;
        invLocalFrame.transform(&surface, surface);

        // obtain the point at altitude
        Point2<double> above;
        if (proj->forward(&above, GeoPoint2(latitude, longitude, 30000.0, TAK::Engine::Core::AltitudeReference::HAE)) != TE_Ok)
            return TE_Err;
        invLocalFrame.transform(&above, above);

        // construct the geometry model and compute the intersection
        Mesh model(tile.data.value, nullptr);

        Point2<double> isect;
        if (!model.intersect(&isect, Ray2<double>(above, Vector4<double>(surface.x - above.x, surface.y - above.y, surface.z - above.z))))
            return TE_InvalidArg;

        tile.data.localFrame.transform(&isect, isect);
        GeoPoint2 geoIsect;
        if (proj->inverse(&geoIsect, isect) != TE_Ok)
            return TE_Err;

        *value = geoIsect.altitude;
        return TE_Ok;
    } else {
        // do a heightmap lookup
        const double postSpaceX = (aabb_wgs84.maxX-aabb_wgs84.minX) / (tile.posts_x-1u);
        const double postSpaceY = (aabb_wgs84.maxY-aabb_wgs84.minY) / (tile.posts_y-1u);
        
        const double postX = (longitude-aabb_wgs84.minX)/postSpaceX;
        const double postY = tile.invert_y_axis ?
                             (latitude-aabb_wgs84.minY)/postSpaceY :
                             (aabb_wgs84.maxY-latitude)/postSpaceY ;
        
        const auto postL = static_cast<std::size_t>(MathUtils_clamp((int)postX, 0, (int)(tile.posts_x-1u)));
        const auto postR = static_cast<std::size_t>(MathUtils_clamp((int)ceil(postX), 0, (int)(tile.posts_x-1u)));
        const auto postT = static_cast<std::size_t>(MathUtils_clamp((int)postY, 0, (int)(tile.posts_y-1u)));
        const auto postB = static_cast<std::size_t>(MathUtils_clamp((int)ceil(postY), 0, (int)(tile.posts_y-1u)));
        
        TAK::Engine::Math::Point2<double> p;
        
        // obtain the four surrounding posts to interpolate from
        tile.data.value->getPosition(&p, (postT*tile.posts_x)+postL);
        const double ul = p.z;
        tile.data.value->getPosition(&p, (postT*tile.posts_x)+postR);
        const double ur = p.z;
        tile.data.value->getPosition(&p, (postB*tile.posts_x)+postR);
        const double lr = p.z;
        tile.data.value->getPosition(&p, (postB*tile.posts_x)+postL);
        const double ll = p.z;
        
        // interpolate the height
        p.z = MathUtils_interpolate(ul, ur, lr, ll,
                                    MathUtils_clamp(postX-(double)postL, 0.0, 1.0),
                                    MathUtils_clamp(postY-(double)postT, 0.0, 1.0));
        // transform the height back to HAE
        tile.data.localFrame.transform(&p, p);
        *value = p.z;
        return TE_Ok;
    }
}