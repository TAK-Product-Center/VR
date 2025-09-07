#include "renderer/core/GLLabel.h"

#include <algorithm>
#include <cmath>

#include "core/ProjectionFactory3.h"
#include "elevation/ElevationManager.h"
#include "feature/Geometry2.h"

#include "feature/LineString.h"
#include "feature/LineString2.h"
#include "feature/Point2.h"
#include "util/MathUtils.h"
#include "math/Rectangle.h"
#include "raster/osm/OSMUtils.h"
#include "renderer/GLES20FixedPipeline.h"
#include "renderer/GLNinePatch.h"
#include "renderer/GLText2.h"
#include "renderer/core/GLMapView2.h"
#include "util/Distance.h"

// XXX - must come after `GLMapView2` otherwise NDK build barfs
#include "feature/LegacyAdapters.h"
#include "renderer/core/GLMapRenderGlobals.h"
#include "math/Mesh.h"
#include "math/Ray2.h"
#include "math/Vector4.h"
#include "math/Plane2.h"


using namespace TAK::Engine::Renderer::Core;

using namespace TAK::Engine;
using namespace TAK::Engine::Core;
using namespace TAK::Engine::Math;
using namespace TAK::Engine::Renderer;
using namespace TAK::Engine::Util;

using namespace atakmap::renderer;

#define ONE_EIGHTY_OVER_PI 57.295779513082320876798154814105
#define LABEL_PADDING_X 10
#define LABEL_PADDING_Y 5

#define CALL_LOCALIZE 1

atakmap::renderer::GLNinePatch* GLLabel::small_nine_patch_ = nullptr;

namespace {
template<class T>
static T DistanceSquared(T ax, T ay, T bx, T by) {
    T dx = ax - bx;
    T dy = ay - by;
    return dx * dx + dy * dy;
}

template<class T>
static bool IntersectLine(TAK::Engine::Math::Point2<T>& pIntersection, T a1x, T a1y, T a2x, T a2y, T b1x, T b1y,
                          T b2x, T b2y) {
    // code from
    // http://csharphelper.com/blog/2014/08/determine-where-two-lines-intersect-in-c/

    // Get the segments' parameters.
    T dx12 = a2x - a1x;
    T dy12 = a2y - a1y;
    T dx34 = b2x - b1x;
    T dy34 = b2y - b1y;

    // Solve for t1 and t2
    T denominator = (dy12 * dx34 - dx12 * dy34);

    T t1 = ((a1x - b1x) * dy34 + (b1y - a1y) * dx34) / denominator;
    if (std::isinf(t1)) {
        // The lines are parallel (or close enough to it).
        return false;
    }

    // the lines intersect
    T t2 = ((b1x - a1x) * dy12 + (a1y - b1y) * dx12) / -denominator;

    // The segments intersect if t1 and t2 are between 0 and 1.
    if ((t1 >= 0) && (t1 <= 1) && (t2 >= 0) && (t2 <= 1)) {
        pIntersection = TAK::Engine::Math::Point2<T>(a1x + dx12 * t1, a1y + dy12 * t1);
        return true;
    }
    return false;
}

template<class T>
static bool IntersectRectangle(TAK::Engine::Math::Point2<T>& p1, T p2x, T p2y, T rx0, T ry0, T rx1, T ry1) {
    auto isects = std::vector<TAK::Engine::Math::Point2<T>>();
    // intersect left
    TAK::Engine::Math::Point2<T> i1, i2, i3, i4;
    if (IntersectLine(i1, p1.x, p1.y, p2x, p2y, rx0, ry0, rx0, ry1)) {
        isects.push_back(i1);  // intersect left
    }
    if (IntersectLine(i2, p1.x, p1.y, p2x, p2y, rx0, ry0, rx1, ry0)) {
        isects.push_back(i2);  // intersect top
    }
    if (IntersectLine(i3, p1.x, p1.y, p2x, p2y, rx0, ry1, rx1, ry1)) {
        isects.push_back(i3);  // intersect bottom
    }
    if (IntersectLine(i4, p1.x, p1.y, p2x, p2y, rx1, ry0, rx1, ry1)) {
        isects.push_back(i4);  // intersect right
    }

    if (isects.size() < 1) return false;

    auto isect = isects[0];
    auto dist2 = DistanceSquared(isect.x, isect.y, p1.x, p1.y);
    for (size_t i = 1; i < isects.size(); i++) {
        T d2 = DistanceSquared(isects[i].x, isects[i].y, p1.x, p1.y);
        if (d2 < dist2) {
            isect = isects[i];
            dist2 = d2;
        }
    }

    p1 = isect;
    return true;
}
bool IntersectRotatedRectangle(const std::array<Point2<float>,4>& r0, const std::array<Point2<float>,4>& r1) NOTHROWS
{
    // derived from https://www.flipcode.com/archives/2D_OBB_Intersection.shtml
    struct {
        /** Corners of the box, where 0 is the lower left. */
        Point2<double> corner[4];
        /** Two edges of the box extended away from corner[0]. */
        Point2<double> axis[2];
        /** origin[a] = corner[0].dot(axis[a]); */
        double origin[2];
    } obb2d[2];

    for(std::size_t i = 0u; i < 4u; i++) {
        obb2d[0].corner[i] = Point2<double>(r0[i].x, r0[i].y, 0.0);
        obb2d[1].corner[i] = Point2<double>(r1[i].x, r1[i].y, 0.0);
    }
    for(std::size_t i = 0u; i < 2u; i++) {
        obb2d[i].axis[0] = Vector2_subtract(obb2d[i].corner[1], obb2d[i].corner[0]);
        obb2d[i].axis[1] = Vector2_subtract(obb2d[i].corner[3], obb2d[i].corner[0]);

        // Make the length of each axis 1/edge length so we know any
        // dot product must be less than 1 to fall within the edge.
        for (int a = 0; a < 2; ++a) {
            obb2d[i].axis[a] = Vector2_multiply(obb2d[i].axis[a], 1.0 / Vector2_dot(obb2d[i].axis[a], obb2d[i].axis[a]));
            obb2d[i].origin[a] = Vector2_dot(obb2d[i].corner[0], obb2d[i].axis[a]);
        }
    }

    for(std::size_t i = 0u; i < 2u; i++) {
        const auto &other = obb2d[(i+1u)%2u];
        for (int a = 0; a < 2; ++a) {
            double t = Vector2_dot(other.corner[0], obb2d[i].axis[a]);

            // Find the extent of box 2 on axis a
            double tMin = t;
            double tMax = t;

            for (int c = 1; c < 4; ++c) {
                t = Vector2_dot(other.corner[c], obb2d[i].axis[a]);

                if (t < tMin) {
                    tMin = t;
                } else if (t > tMax) {
                    tMax = t;
                }
            }

            // We have to subtract off the origin

            // See if [tMin, tMax] intersects [0, 1]
            if ((tMin > 1 + obb2d[i].origin[a]) || (tMax < obb2d[i].origin[a])) {
                // There was no intersection along this dimension;
                // the boxes cannot possibly overlap.
                return false;
            }
        }
    }

    // There was no dimension along which there is no intersection.
    // Therefore the boxes overlap.
    return true;
}
double rectangleOverlap(const double aminX, const double aminY, const double amaxX, const double amaxY,
                        const double bminX, const double bminY, const double bmaxX, const double bmaxY) NOTHROWS
{
    // compute overlap
    const double iminx = std::max(aminX, bminX);
    const double iminy = std::max(aminY, bminY);
    const double imaxx = std::min(amaxX, bmaxX);
    const double imaxy = std::min(amaxY, bmaxY);
    return ((imaxx-iminx)*(imaxy-iminy))/((amaxX-aminX)*(amaxY-aminY));
}
}

void GLLabel::LabelPlacement::recomputeForSurface(const GLGlobeBase::State& view, const double heightInMeters, const double absoluteRotation, const float width, const float height) NOTHROWS
{
    GeoPoint2 renderGeoPoint(0,0);
    view.scene.inverse(&renderGeoPoint, Math::Point2<float>((float)render_xyz_.x, (float)render_xyz_.y, (float)render_xyz_.z));
    GeoPoint2 anchorGeoPoint(0,0);
    view.scene.inverse(&anchorGeoPoint, Math::Point2<float>((float)anchor_xyz_.x, (float)anchor_xyz_.y, (float)anchor_xyz_.z));

    double scale = width / height;
    double widthInMeters = heightInMeters * scale;
    // XXX - x2 because Equirectangular is twice as wide as it is tall?
    double widthInProjX = (widthInMeters / view.scene.displayModel->projectionXToNominalMeters) * 2;
    double heightInProjY = (heightInMeters / view.scene.displayModel->projectionYToNominalMeters);

    Math::Point2<double> renderPoint;
    view.scene.projection->forward(&renderPoint, renderGeoPoint);
    Math::Point2<double> anchorPoint;
    view.scene.projection->forward(&anchorPoint, anchorGeoPoint);
    double offsetX = renderPoint.x - anchorPoint.x;
    double offsetY = renderPoint.y - anchorPoint.y;

    double rotate = rotation_.angle_;
    if (rotation_.absolute_) {
        rotate = fmod(rotate + absoluteRotation, 360.0);
    }

    rotate *= M_PI / 180.;

    float rsin = 0;
    float rcos = 1;

    if(rotate != 0.0f)
    {
        rsin = sinf(static_cast<float>(rotate));
        rcos = cosf(static_cast<float>(rotate));
    }

    boundingGeometry.proj[0] = TAK::Engine::Math::Point2<double>(offsetX, heightInProjY + offsetY);
    boundingGeometry.proj[1] = TAK::Engine::Math::Point2<double>(offsetX, offsetY);
    boundingGeometry.proj[2] = TAK::Engine::Math::Point2<double>(widthInProjX + offsetX, offsetY);
    boundingGeometry.proj[3] = TAK::Engine::Math::Point2<double>(widthInProjX + offsetX, heightInProjY + offsetY);

    for(int i=0; i < 4;++i)
    {
        double x = boundingGeometry.proj[i].x * rcos - boundingGeometry.proj[i].y * rsin;
        double y = boundingGeometry.proj[i].y * rcos + boundingGeometry.proj[i].x * rsin;

        boundingGeometry.proj[i].x = x + anchorPoint.x;
        boundingGeometry.proj[i].y = y + anchorPoint.y;
        view.scene.projection->inverse(&boundingGeometry.shape[i], boundingGeometry.proj[i]);
    }

    boundingGeometry.minlat = MathUtils_min(boundingGeometry.shape[0].latitude, boundingGeometry.shape[1].latitude, boundingGeometry.shape[2].latitude, boundingGeometry.shape[3].latitude);
    boundingGeometry.minlon = MathUtils_min(boundingGeometry.shape[0].longitude, boundingGeometry.shape[1].longitude, boundingGeometry.shape[2].longitude, boundingGeometry.shape[3].longitude);
    boundingGeometry.maxlat = MathUtils_max(boundingGeometry.shape[0].latitude, boundingGeometry.shape[1].latitude, boundingGeometry.shape[2].latitude, boundingGeometry.shape[3].latitude);
    boundingGeometry.maxlon = MathUtils_max(boundingGeometry.shape[0].longitude, boundingGeometry.shape[1].longitude, boundingGeometry.shape[2].longitude, boundingGeometry.shape[3].longitude);
    boundingGeometry.rotated = (rotate != 0.0);
}

void GLLabel::LabelPlacement::recompute(const Point2<double> &baseline_xyz, const double absoluteRotation, const float width, const float height) NOTHROWS
{
    double rotate = rotation_.angle_;
    if (rotation_.absolute_) {
        rotate = fmod(rotate + absoluteRotation, 360.0);
    }

    rotate *= M_PI / 180.;

    float rsin = 0;
    float rcos = 1;

    if(rotate != 0.0f)
    {
        rsin = sinf(static_cast<float>(rotate));
        rcos = cosf(static_cast<float>(rotate));
    }

    float width2 = width / 2.0f;
    float height2 = height / 2.0f;

    boundingRect.shape[0] = TAK::Engine::Math::Point2<float>(-width2, height2);
    boundingRect.shape[1] = TAK::Engine::Math::Point2<float>(-width2, -height2);
    boundingRect.shape[2] = TAK::Engine::Math::Point2<float>(width2, -height2);
    boundingRect.shape[3] = TAK::Engine::Math::Point2<float>(width2, height2);

    for(int i=0; i < 4;++i)
    {
        float x = boundingRect.shape[i].x * rcos - boundingRect.shape[i].y * rsin;
        float y = boundingRect.shape[i].y * rcos + boundingRect.shape[i].x * rsin;

        boundingRect.shape[i].x = x + static_cast<float>(baseline_xyz.x) + width2;
        boundingRect.shape[i].y = y + static_cast<float>(baseline_xyz.y) + height2;
    }

    boundingRect.minX = MathUtils_min(boundingRect.shape[0].x, boundingRect.shape[1].x, boundingRect.shape[2].x, boundingRect.shape[3].x);
    boundingRect.minY = MathUtils_min(boundingRect.shape[0].y, boundingRect.shape[1].y, boundingRect.shape[2].y, boundingRect.shape[3].y);
    boundingRect.maxX = MathUtils_max(boundingRect.shape[0].x, boundingRect.shape[1].x, boundingRect.shape[2].x, boundingRect.shape[3].x);
    boundingRect.maxY = MathUtils_max(boundingRect.shape[0].y, boundingRect.shape[1].y, boundingRect.shape[2].y, boundingRect.shape[3].y);
    boundingRect.rotated = (rotate != 0.0);
}

namespace
{

template<class T>
static bool FindIntersection(TAK::Engine::Math::Point2<T>& p1, TAK::Engine::Math::Point2<T>& p2, T rx0, T ry0, T rx1,
                             T ry1) {
    // if endpoint 1 is not contained, find intersection
    if (!atakmap::math::Rectangle<T>::contains(rx0, ry0, rx1, ry1, p1.x, p1.y) &&
        !IntersectRectangle(p1, p2.x, p2.y, rx0, rx0, rx1, ry1)) {
        // no intersection point
        return false;
    }
    // if endpoint 2 is not contained, find intersection
    if (!atakmap::math::Rectangle<T>::contains(rx0, ry0, rx1, ry1, p2.x, p2.y) &&
        !IntersectRectangle(p2, p1.x, p1.y, rx0, rx0, rx1, ry1)) {
        // no intersection point
        return false;
    }

    return true;
}

    struct FloatingAnchor
    {
        GeoPoint2 lla;
        struct {
            Point2<float> a;
            Point2<float> b;
        } axis;
    };

    TAKErr getTerrainMeshElevation(double* value, const GLGlobeBase::State& state, const double latitude, const double longitude) NOTHROWS;

    Point2<double> nearestPointOnSegment(const Point2<double> &sp, const Point2<double> &ep, const Point2<double> p) NOTHROWS
    {
        Point2<double> v = Vector2_subtract(ep, sp);
        Point2<double> w = Vector2_subtract(p, sp);
        const double c1 = Vector2_dot(w, v);
        if (c1 <= 0.0)
            return sp;
        const double c2 = Vector2_dot(v, v);
        if (c2 <= c1)
            return ep;
        const double b = c1 / c2;
        return Point2<double>(sp.x + b * v.x, sp.y + b * v.y, sp.z + b
                * v.z);
    }

    GeoPoint2 closestSurfacePointToFocus(const GLGlobeBase::State &ortho, const float xmid, const float ymid, const GeoPoint2 &a, const GeoPoint2 &b) NOTHROWS
    {
        struct
        {
            GeoPoint2 geo;
            Point2<double> pointD;
        } scratch;

        ortho.scene.projection->inverse(&scratch.geo, ortho.scene.camera.target);
        if(TE_ISNAN(scratch.geo.altitude))
            scratch.geo.altitude = 100.0;
        else
            scratch.geo.altitude += 100.0;
        ortho.scene.projection->forward(&scratch.pointD, scratch.geo);

        // compute focus as location as screen point at x,y on the plane
        // passing through the camera focus with the local up as the normal
        // vector
        Vector4<double> normal (
                (scratch.pointD.x-ortho.scene.camera.target.x),
                (scratch.pointD.y-ortho.scene.camera.target.y),
                (scratch.pointD.z-ortho.scene.camera.target.z));
        Plane2 focusPlane(normal, ortho.scene.camera.target);
        GeoPoint2 focus;
        if(ortho.scene.inverse(&focus, Point2<float>(xmid, ymid), focusPlane) != TE_Ok)
            ortho.scene.projection->inverse(&focus, ortho.scene.camera.target);

        if(ortho.drawSrid == 4978) {
            // compute the interpolation weight for the surface point
            scratch.geo = focus;
            const double dpts = GeoPoint2_distance(a, b, true);
            double dtofocus = GeoPoint2_alongTrackDistance(a, b, scratch.geo, true);
            if(dtofocus < dpts &&
                    GeoPoint2_distance(scratch.geo, a, true) <
                    GeoPoint2_distance(scratch.geo, GeoPoint2_pointAtDistance(a, b,
                        dtofocus/dpts, true), true)) {
                dtofocus *= -1.0;
            }

            const double weight = MathUtils_clamp(dtofocus / dpts, 0.0, 1.0);

            return GeoPoint2_pointAtDistance(a, b,
                        weight, true);
        } else {
            // execute closest-point-on-line as cartesian math
            ortho.scene.projection->forward(&scratch.pointD, a);
            const double ax = scratch.pointD.x*ortho.scene.displayModel->projectionXToNominalMeters;
            const double ay = scratch.pointD.y*ortho.scene.displayModel->projectionYToNominalMeters;
            const double az = scratch.pointD.z*ortho.scene.displayModel->projectionZToNominalMeters;
            ortho.scene.projection->forward(&scratch.pointD, b);
            const double bx = scratch.pointD.x*ortho.scene.displayModel->projectionXToNominalMeters;
            const double by = scratch.pointD.y*ortho.scene.displayModel->projectionYToNominalMeters;
            const double bz = scratch.pointD.z*ortho.scene.displayModel->projectionZToNominalMeters;

            ortho.scene.projection->forward(&scratch.pointD, focus);
            const double dx = scratch.pointD.x*ortho.scene.displayModel->projectionXToNominalMeters;
            const double dy = scratch.pointD.y*ortho.scene.displayModel->projectionYToNominalMeters;
            const double dz = scratch.pointD.z*ortho.scene.displayModel->projectionZToNominalMeters;

            Point2<double> p = nearestPointOnSegment(Point2<double>(ax, ay, az), Point2<double>(bx, by, bz), Point2<double>(dx, dy, dz));

            scratch.pointD.x = p.x / ortho.scene.displayModel->projectionXToNominalMeters;
            scratch.pointD.y = p.y / ortho.scene.displayModel->projectionYToNominalMeters;
            scratch.pointD.z = p.z / ortho.scene.displayModel->projectionZToNominalMeters;

            ortho.scene.projection->inverse(&scratch.geo, scratch.pointD);
            return scratch.geo;
        }
    }

    GeoPoint2 adjustSurfaceLabelAnchor(const GLGlobeBase::State &view, const GeoPoint2 &geo, const Feature::AltitudeMode altitudeMode) NOTHROWS
    {
        // Z/altitude
        if (view.drawTilt == 0.0 && view.scene.camera.mode == MapCamera2::Scale)
            return geo;

        bool belowTerrain = false;
        double posEl = 0.0;
        // XXX - altitude
        double alt = geo.altitude;
        double terrain;
        getTerrainMeshElevation(&terrain, view, geo.latitude, geo.longitude);
        if (TE_ISNAN(alt) || altitudeMode == TAK::Engine::Feature::AltitudeMode::TEAM_ClampToGround) {
            alt = terrain;
        } else if (altitudeMode == TAK::Engine::Feature::AltitudeMode::TEAM_Relative) {
            alt += terrain;
        } else if (alt < terrain) {
            // if the explicitly specified altitude is below the terrain,
            // float above and annotate appropriately
            belowTerrain = true;
            alt = terrain;
        }

        // note: always NaN if source alt is NaN
        double adjustedAlt = alt * view.elevationScaleFactor;

        // move up ~5 pixels from surface
#ifndef __ANDROID__
        if(view.drawTilt)
            adjustedAlt += view.drawMapResolution * 25.0;
#endif
        return GeoPoint2(geo.latitude, geo.longitude, adjustedAlt, AltitudeReference::HAE);
    }

    void intersectWithNearPlane(Point2<float> &axy, Point2<float> &bxy, const GLGlobeBase::State &view, const GeoPoint2 &alla, const GeoPoint2 &blla) NOTHROWS
    {
        // both are in front of the camera
        if(axy.z < 1.f && bxy.z < 1.f)
            return;
        // both are behind the camera
        if(axy.z > 1.f && bxy.z > 1.f)
            return;

        // find the intersect of the segment with the near plane
        const double losdx = view.scene.camera.location.x-view.scene.camera.target.x;
        const double losdy = view.scene.camera.location.y-view.scene.camera.target.y;
        const double losdz = view.scene.camera.location.z-view.scene.camera.target.z;

        const double losm = Vector2_length(Point2<double>(losdx, losdy, losdz));
        const Plane2 near(Vector4<double>(losdx, losdy, losdz),
                Point2<double>(view.scene.camera.location.x-(losdx/losm)*view.scene.camera.nearMeters,
                        view.scene.camera.location.y-(losdy/losm)*view.scene.camera.nearMeters,
                        view.scene.camera.location.z-(losdz/losm)*view.scene.camera.nearMeters
                        ));

        Point2<double> p0;
        view.scene.projection->forward(&p0, alla);
        Point2<double> p1;
        view.scene.projection->forward(&p1, blla);

        // create segment
        Point2<double> isect;
        if(near.intersect(&isect, Ray2<double>(p0, Vector4<double>(p1.x-p0.x, p1.y-p0.y, p1.z-p0.z)))) {
            view.scene.forwardTransform.transform(&isect, isect);
            Point2<float> *xyzpos = (axy.z > 1.f) ? &axy : &bxy;
            xyzpos->x = (float)isect.x;
            xyzpos->y = (float)isect.y;
            xyzpos->z = (float)isect.z;
        }
    }
    void getRenderPoint(GeoPoint2 *value, const GLGlobeBase::State &ortho, const Feature::LineString2 &points, const std::size_t idx, const Feature::AltitudeMode altitudeMode) NOTHROWS
    {
        if(idx >= points.getNumPoints())
            return;
        points.getY(&value->latitude, idx);
        points.getX(&value->longitude, idx);


        // source altitude is populated for absolute or relative IF 3 elements specified
        if(points.getDimension() == 3 && altitudeMode != Feature::TEAM_ClampToGround)
            points.getZ(&value->altitude, idx);
        else
            value->altitude = 0.0;
        // terrain is populated for clamp-to-ground or relative
        double terrain = 0.0;
        if(altitudeMode != Feature::TEAM_Absolute) {
            getTerrainMeshElevation(&terrain, ortho, value->latitude, value->longitude);
            if(TE_ISNAN(terrain))
                terrain = 0.0;
        }
        value->altitude += terrain;
    }
    void validateSurfaceFloatingLabel(std::vector<FloatingAnchor> &anchors, Point2<double> *midpoint, const GLGlobeBase::State &ortho, const Feature::LineString2 &points, const float segmentPositionWeight, const float labelWidth) NOTHROWS {
        const std::size_t numPoints = points.getNumPoints();
        if (!numPoints)
            return;

        double stripLength = 0.0;
        std::vector<double> segmentLengths;
        segmentLengths.reserve(numPoints - 1u);
        double xmin = std::numeric_limits<double>::max(), ymin = std::numeric_limits<double>::max(),
                xmax = std::numeric_limits<double>::min(), ymax = std::numeric_limits<double>::min();

        double txmin = xmin;
        double txmax = xmax;
        double tymin = ymin;
        double tymax = ymax;

        GeoPoint2 startGeo;
        GeoPoint2 endGeo;

        getRenderPoint(&endGeo, ortho, points, 0u, Feature::TEAM_ClampToGround);

        Point2<float> start;
        Point2<float> end;
        ortho.scene.forward(&end, endGeo);

        int stripStartIdx = -1;
        for (std::size_t i = 0u; i < numPoints - 1u; i++) {
            startGeo = endGeo;
            getRenderPoint(&endGeo, ortho, points, i + 1u, Feature::TEAM_ClampToGround);

            Point2<float> xy0, xy1;
            ortho.scene.forward(&xy0, startGeo);
            ortho.scene.forward(&xy1, endGeo);

            // emit the strip currently being processed if it will be clipped
            const bool emit =
                    !atakmap::math::Rectangle<float>::contains(static_cast<float>(ortho.left), static_cast<float>(ortho.bottom),
                        static_cast<float>(ortho.right), static_cast<float>(ortho.top), xy1.x, xy1.y);

            // clip the segment
            if(!FindIntersection<float>(xy0, xy1, static_cast<float>(ortho.left), static_cast<float>(ortho.bottom),
                    static_cast<float>(ortho.right), static_cast<float>(ortho.top)))
                continue; // segment was completely outside region

            // start a new strip if necessary
            if(stripStartIdx == -1) {
                stripStartIdx = static_cast<int>(i);
            }

            // record the segment length
            segmentLengths.push_back(Vector2_length(
                    Point2<double>(xy0.x-xy1.x, xy0.y-xy1.y)));
            // update total strip length
            stripLength += segmentLengths.back();

            // update bounds for current strip
            Point2<float> clippedSegment[2];

            clippedSegment[0] = xy0;
            clippedSegment[1] = xy1;
            for (int j = 0; j < 2; j++) {
                const float x = clippedSegment[j].x;
                const float y = clippedSegment[j].y;
                if (x > xmax)
                    xmax = x;
                if (x < xmin)
                    xmin = x;
                if (y > ymax)
                    ymax = y;
                if (y < ymin)
                    ymin = y;
            }

            if(xmin < txmin) txmin = xmin;
            if(ymin < tymin) tymin = ymin;
            if(xmax > txmax) txmax = xmax;
            if(ymax > tymax) tymax = ymax;

            // check emit
            if (emit && stripStartIdx != -1 &&
                (std::max(xmax - xmin, ymax - ymin) >= labelWidth)) {

                // locate the segment that contains the midpoint of the current strip
                const double weightedLength = stripLength * segmentPositionWeight;
                double t = 0.0;
                int containingSegIdx = stripStartIdx;
                for (int j = stripStartIdx; j <= i; j++) {
                    t += segmentLengths[j-stripStartIdx];
                    if (t > weightedLength) {
                        containingSegIdx = j;
                        break;
                    }
                }

                const double segStart = t - segmentLengths[containingSegIdx - stripStartIdx];
                const double segPercent = (weightedLength - segStart)
                                          / segmentLengths[containingSegIdx - stripStartIdx];

                GeoPoint2 segStartLLA, segEndLLA;
                Point2<float> segStartXY, segEndXY;
                getRenderPoint(&segStartLLA, ortho, points, containingSegIdx, Feature::TEAM_ClampToGround);
                ortho.scene.forward(&segStartXY, segStartLLA);
                const float segStartX = segStartXY.x;
                const float segStartY = segStartXY.y;
                getRenderPoint(&segEndLLA, ortho, points, containingSegIdx+1u, Feature::TEAM_ClampToGround);
                ortho.scene.forward(&segEndXY, segEndLLA);
                const float segEndX = segEndXY.x;
                const float segEndY = segEndXY.y;

                Point2<float> clippedSegStartXY(segStartXY);
                Point2<float> clippedSegEndXY(segEndXY);
                FindIntersection<float>(clippedSegStartXY, clippedSegEndXY,
                    static_cast<float>(ortho.left),
                    static_cast<float>(ortho.bottom),
                    static_cast<float>(ortho.right),
                    static_cast<float>(ortho.top));

                const float px = clippedSegStartXY.x + (clippedSegEndXY.x - clippedSegStartXY.x) * (float) segPercent;
                const float py = clippedSegStartXY.y + (clippedSegEndXY.y - clippedSegStartXY.y) * (float) segPercent;

                const double segNormalX =
                        (clippedSegEndXY.x - clippedSegStartXY.x) / segmentLengths[containingSegIdx - stripStartIdx];
                const double segNormalY =
                        (clippedSegEndXY.y - clippedSegStartXY.y) / segmentLengths[containingSegIdx - stripStartIdx];

                start.x = (float) (px - segNormalX);
                start.y = (float) (py - segNormalY);
                end.x = (float) (px + segNormalX);
                end.y = (float) (py + segNormalY);

                const Point2<float> textPoint(start.x+(end.x-start.x)*segmentPositionWeight, start.y+(end.y-start.y)*segmentPositionWeight);

                // recompute LLA
                const double weight =
                        Vector2_length<double>(Point2<double>(textPoint.x-segStartX, textPoint.y-segStartY)) /
                        Vector2_length(Point2<double>(segStartX-segEndX, segStartY-segEndY));
                GeoPoint2 label_lla = GeoPoint2_pointAtDistance(segStartLLA, segEndLLA,
                        weight, true);

                getTerrainMeshElevation(
                      &label_lla.altitude,
                      ortho,
                      label_lla.latitude,
                      label_lla.longitude);

                FloatingAnchor anchor;
                anchor.lla = label_lla;
                anchor.axis.a = start;
                anchor.axis.b = end;

                anchors.push_back(anchor);

                // reset for next strip
                stripStartIdx = -1;

                stripLength = 0.0;
                segmentLengths.clear();

                xmin = std::numeric_limits<double>::max();
                ymin = std::numeric_limits<double>::max();
                xmax = std::numeric_limits<double>::min();
                ymax = std::numeric_limits<double>::min();
            }
        }

        if(midpoint) {
            midpoint->x = txmin+(txmax-txmin)*segmentPositionWeight;
            midpoint->y = tymin+(tymax-tymin)*segmentPositionWeight;
        }

        // check emit
        if (stripStartIdx != -1 &&
            (std::max(xmax - xmin, ymax - ymin) >= labelWidth)) {

            // locate the segment that contains the midpoint of the current strip
            const double weightedLength = stripLength * segmentPositionWeight;
            double t = 0.0;
            int containingSegIdx = -1;
            for (int j = 0; j < (numPoints-1u)-stripStartIdx; j++) {
                t += segmentLengths[j];
                if (t > weightedLength) {
                    containingSegIdx = j + stripStartIdx;
                    break;
                }
            }
            if (containingSegIdx >= 0) {
                const double segStart = t - segmentLengths[containingSegIdx - stripStartIdx];
                const double segPercent = (weightedLength - segStart)
                                          / segmentLengths[containingSegIdx - stripStartIdx];

                GeoPoint2 segStartLLA, segEndLLA;
                Point2<float> segStartXY, segEndXY;
                getRenderPoint(&segStartLLA, ortho, points, containingSegIdx, Feature::TEAM_ClampToGround);
                ortho.scene.forward(&segStartXY, segStartLLA);
                const float segStartX = segStartXY.x;
                const float segStartY = segStartXY.y;
                getRenderPoint(&segEndLLA, ortho, points, containingSegIdx+1u, Feature::TEAM_ClampToGround);
                ortho.scene.forward(&segEndXY, segEndLLA);
                const float segEndX = segEndXY.x;
                const float segEndY = segEndXY.y;

                Point2<float> clippedSegStartXY(segStartXY);
                Point2<float> clippedSegEndXY(segEndXY);
                FindIntersection<float>(clippedSegStartXY, clippedSegEndXY,
                    static_cast<float>(ortho.left),
                    static_cast<float>(ortho.bottom),
                    static_cast<float>(ortho.right),
                    static_cast<float>(ortho.top));

                const float px = clippedSegStartXY.x + (clippedSegEndXY.x - clippedSegStartXY.x) * (float) segPercent;
                const float py = clippedSegStartXY.y + (clippedSegEndXY.y - clippedSegStartXY.y) * (float) segPercent;

                const double segNormalX =
                        (clippedSegEndXY.x - clippedSegStartXY.x) / segmentLengths[containingSegIdx - stripStartIdx];
                const double segNormalY =
                        (clippedSegEndXY.y - clippedSegStartXY.y) / segmentLengths[containingSegIdx - stripStartIdx];

                start.x = (float) (px - segNormalX);
                start.y = (float) (py - segNormalY);
                end.x = (float) (px + segNormalX);
                end.y = (float) (py + segNormalY);

                const Point2<float> textPoint(start.x+(end.x-start.x)*segmentPositionWeight, start.y+(end.y-start.y)*segmentPositionWeight);

                // XXX - rotation

                // recompute LLA
                const double weight =
                        Vector2_length<double>(Point2<double>(textPoint.x-segStartX, textPoint.y-segStartY)) /
                        Vector2_length(Point2<double>(segStartX-segEndX, segStartY-segEndY));
                GeoPoint2 label_lla = GeoPoint2_pointAtDistance(
                        segStartLLA,
                        segEndLLA,
                        weight, true);

                getTerrainMeshElevation(
                      &label_lla.altitude,
                      ortho,
                      label_lla.latitude,
                      label_lla.longitude);

                FloatingAnchor anchor;
                anchor.lla = label_lla;
                anchor.axis.a = start;
                anchor.axis.b = end;

                anchors.push_back(anchor);
            }

            stripStartIdx = -1;
        }
    }
    void validateSurfaceLabel(std::vector<FloatingAnchor> &anchors, Point2<double> *midpoint, const GLGlobeBase::State &ortho, const Feature::LineString2 &points, const float segmentPositionWeight, const float labelWidth) NOTHROWS {
        const std::size_t numPoints = points.getNumPoints();
        if (!numPoints)
            return;

        double totalLength = 0.0;
        GeoPoint2 a;
        GeoPoint2 b;
        points.getX(&b.longitude, 0u);
        points.getY(&b.latitude, 0u);
        for(std::size_t i = 1u; i < numPoints; i++) {
            a = b;
            points.getX(&b.longitude, i);
            points.getY(&b.latitude, i);
            totalLength += GeoPoint2_distance(a, b, true);
        }

        const double anchorDistance = totalLength*segmentPositionWeight;
        std::size_t containingSegmentIndex = points.getNumPoints()-1u;

        FloatingAnchor anchor;
        double d = 0.0;
        points.getX(&b.longitude, 0u);
        points.getY(&b.latitude, 0u);
        for(std::size_t i = 1u; i < numPoints; i++) {
            a = b;
            points.getX(&b.longitude, i);
            points.getY(&b.latitude, i);
            const auto sd = GeoPoint2_distance(a, b, true);
            if(sd >= (anchorDistance-d)) {
                anchor.lla = GeoPoint2_pointAtDistance(a, b, (anchorDistance-d) / sd, true);
                getTerrainMeshElevation(&anchor.lla.altitude, ortho, anchor.lla.latitude, anchor.lla.longitude);
                containingSegmentIndex = i;
                break;
            }
            d += sd;
        }

        // record the anchor in screenspace
        Point2<float> anchorXY;
        ortho.scene.forward(&anchorXY, anchor.lla);

        anchor.axis.a = anchorXY;
        anchor.axis.b = anchorXY;


        // traverse the line from the anchor to the endpoints to find screenspace anchors
        for(std::size_t i = containingSegmentIndex; i > 0u; i--) {
            GeoPoint2 geo;
            getRenderPoint(&geo, ortho, points, i-1u, TAK::Engine::Feature::TEAM_ClampToGround);
            Point2<float> axy;
            ortho.scene.forward(&axy, geo);
            const double daxy = Vector2_length(Vector2_subtract(Point2<float>(axy.x, axy.y), Point2<float>(anchorXY.x, anchorXY.y)));
            if(daxy < (labelWidth/2.f))
                continue;
            anchor.axis.a = axy;
            break;
        }
        for(std::size_t i = containingSegmentIndex; i < numPoints; i++) {
            GeoPoint2 geo;
            getRenderPoint(&geo, ortho, points, i, TAK::Engine::Feature::TEAM_ClampToGround);
            Point2<float> bxy;
            ortho.scene.forward(&bxy, geo);
            const double dbxy = Vector2_length(Vector2_subtract(Point2<float>(bxy.x, bxy.y), Point2<float>(anchorXY.x, anchorXY.y)));
            if(dbxy < (labelWidth/2.f))
                continue;
            anchor.axis.b = bxy;
            break;
        }

        if(midpoint)
            *midpoint = Point2<double>(anchorXY.x, anchorXY.y, anchorXY.z);

        if(Vector2_length(Vector2_subtract(Point2<float>(anchor.axis.a.x, anchor.axis.a.y), Point2<float>(anchor.axis.b.x, anchor.axis.b.y))) >= labelWidth)
            anchors.push_back(anchor);
    }
    inline GlyphHAlignment toGlyphHAlignment(TextAlignment a) {
        switch (a) {
            case TextAlignment::TETA_Left: return GlyphHAlignment_Left;
            default:
            case TextAlignment::TETA_Center: return GlyphHAlignment_Center;
            case TextAlignment::TETA_Right: return GlyphHAlignment_Right;
        }
    }

    TAKErr getTerrainMeshElevation(double *value, const GLGlobeBase::State& state, const double latitude, const double longitude_) NOTHROWS
    {
        TAKErr code(TE_InvalidArg);

        *value = NAN;

        // wrap the longitude if necessary
        double longitude = longitude_;
        if(longitude > 180.0)
            longitude -= 360.0;
        else if(longitude < -180.0)
            longitude += 360.0;

        double elevation = NAN;
        struct {
            std::shared_ptr<const TAK::Engine::Renderer::Elevation::TerrainTile> value;
            GeoPoint2 point;
        } closestTile;

        {
            {
                const double altAboveSurface = 30000.0;
                for (std::size_t i = 0u; i < state.renderTiles.count; i++) {
                    auto tile = state.renderTiles.value[i].tile;
                    if (!tile)
                        continue;

                    if(TAK::Engine::Renderer::Elevation::TerrainTile_getElevation(&elevation, *tile, latitude, longitude) == TE_Ok) {
                        code = TE_Ok;
                        break;
                    }

                    auto aabbWGS84(tile->aabb_wgs84);
                    const double centroid = ((aabbWGS84.minX+aabbWGS84.maxX)/2.0);
                    double tlongitude = longitude;
                    if(fabs(centroid-longitude) > 180.0 && (centroid*longitude < 0.0)) {
                        // shift the POI longitude to the AABB hemisphere
                        const double hemiShift = (longitude >= 0.0) ? -360.0 : 360.0;
                        tlongitude += hemiShift;
                        tlongitude += hemiShift;
                    }
                    GeoPoint2 p(
                            MathUtils_clamp(latitude, aabbWGS84.minY, aabbWGS84.maxY),
                            MathUtils_clamp(tlongitude, aabbWGS84.minX, aabbWGS84.maxX));

                    if(!closestTile.value) {
                        closestTile.value = tile;
                        closestTile.point = p;
                    } else {
                        const double pda = p.latitude-latitude;
                        double pdo = p.longitude-longitude;
                        if(pdo > 180.0) pdo -= 360.0;
                        else if(pdo < -180.0) pdo += 360.0;
                        const double cda = closestTile.point.latitude-latitude;
                        double cdo = closestTile.point.longitude-longitude;
                        if(cdo > 180.0) cdo -= 360.0;
                        else if(cdo < -180.0) cdo += 360.0;
                        if((pda*pda+pdo*pdo) < (cda*cda+cdo*cdo)) {
                            closestTile.value = tile;
                            closestTile.point = p;
                        }
                    }
                }
            }
        }

        // failed to find elevation in render tiles, fallback
        if (TE_ISNAN(elevation)) {
            //elevation = terrainLookupFallback(latitude, longitude);
            // clamp elevation using the closest tile to the point
            if(!closestTile.value || TAK::Engine::Renderer::Elevation::TerrainTile_getElevation(&elevation, *closestTile.value, closestTile.point.latitude, closestTile.point.longitude) != TE_Ok)
                elevation = 0.0;
            code = TE_Ok;
        }

        *value = elevation;

        return code;
    }
}

GLLabel::GLLabel()
    : altitude_mode_(TAK::Engine::Feature::AltitudeMode::TEAM_ClampToGround),
      visible_(true),
      always_render_(false),
      alignment_(TextAlignment::TETA_Center),
      horizontal_alignment_(HorizontalAlignment::TEHA_Center),
      vertical_alignment_(VerticalAlignment::TEVA_Top),
      priority_(Priority::TEP_Standard),
      color_r_(1),
      color_g_(1),
      color_b_(1),
      color_a_(1),
      back_color_r_(0),
      back_color_g_(0),
      back_color_b_(0),
      back_color_a_(0),
      outline_color_r_(0),
      outline_color_g_(0),
      outline_color_b_(0),
      outline_color_a_(1),
      fill_(false),
      projected_size_(std::numeric_limits<double>::quiet_NaN()),
      mark_dirty_(true),
      draw_version_(-1),
      hints_(Hints::AutoSurfaceOffsetAdjust|Hints::WeightedFloat),
      float_weight_(0.5f),
      gltext_(nullptr),
      textFormatParams_(nullptr),
      hit_testable_(false),
      heightInMeters_(0)
{
    rotation_.angle_ = 0.0f;
    rotation_.absolute_ = false;
    rotation_.explicit_ = false;

    initGlyphBuffersOpts(&buffer_opts_, *this);
}

GLLabel::GLLabel(const GLLabel& rhs) : GLLabel() {
    if (rhs.geometry.pointer) {
        Feature::Geometry_clone(geometry.pointer, *rhs.geometry.pointer);
    } else {
        geometry.point = rhs.geometry.point;
    }
    geometry.empty = rhs.geometry.empty;
    altitude_mode_ = rhs.altitude_mode_;
    text_ = rhs.text_;
    desired_offset_ = rhs.desired_offset_;
    visible_ = rhs.visible_;
    always_render_ = rhs.always_render_;
    alignment_ = rhs.alignment_;
    horizontal_alignment_ = rhs.horizontal_alignment_;
    vertical_alignment_ = rhs.vertical_alignment_;
    priority_ = rhs.priority_;
    rotation_ = rhs.rotation_;
    insets_ = rhs.insets_;
    float_weight_ = rhs.float_weight_;
    transformed_anchor_ = rhs.transformed_anchor_;
    draw_version_ = rhs.draw_version_;
    color_a_ = rhs.color_a_;
    color_r_ = rhs.color_r_;
    color_g_ = rhs.color_g_;
    color_b_ = rhs.color_b_;
    back_color_a_ = rhs.back_color_a_;
    back_color_r_ = rhs.back_color_r_;
    back_color_g_ = rhs.back_color_g_;
    back_color_b_ = rhs.back_color_b_;
    outline_color_a_ = rhs.outline_color_a_;
    outline_color_r_ = rhs.outline_color_r_;
    outline_color_g_ = rhs.outline_color_g_;
    outline_color_b_ = rhs.outline_color_b_;
    hints_ = rhs.hints_;
    fill_ = rhs.fill_;
    gltext_ = rhs.gltext_;
    if (rhs.textFormatParams_)
        textFormatParams_.reset(new TextFormatParams(*rhs.textFormatParams_));
    buffer_opts_ = rhs.buffer_opts_;
    textSize = rhs.textSize;
    labelSize = rhs.labelSize;
    force_clamp_to_ground.front_ = rhs.force_clamp_to_ground.front_;
    force_clamp_to_ground.back_ = rhs.force_clamp_to_ground.back_;
    level_of_detail.min_ = rhs.level_of_detail.min_;
    level_of_detail.max_ = rhs.level_of_detail.max_;
    hit_testable_ = rhs.hit_testable_;
    heightInMeters_ = rhs.heightInMeters_;
    label_render_pump_ = rhs.label_render_pump_;
    max_tilt_ = rhs.max_tilt_;
}

GLLabel::GLLabel(GLLabel&& rhs) NOTHROWS : GLLabel() {
    if (rhs.geometry.pointer) {
        geometry.pointer = std::move(rhs.geometry.pointer);
    } else {
        geometry.point = rhs.geometry.point;
    }
    geometry.empty = rhs.geometry.empty;
    altitude_mode_ = rhs.altitude_mode_;
    text_ = rhs.text_;
    desired_offset_ = rhs.desired_offset_;
    visible_ = rhs.visible_;
    always_render_ = rhs.always_render_;
    alignment_ = rhs.alignment_;
    horizontal_alignment_ = rhs.horizontal_alignment_;
    vertical_alignment_ = rhs.vertical_alignment_;
    priority_ = rhs.priority_;
    rotation_ = rhs.rotation_;
    insets_ = rhs.insets_;
    float_weight_ = rhs.float_weight_;
    hints_ = rhs.hints_;
    transformed_anchor_ = rhs.transformed_anchor_;
    draw_version_ = rhs.draw_version_;
    color_a_ = rhs.color_a_;
    color_r_ = rhs.color_r_;
    color_g_ = rhs.color_g_;
    color_b_ = rhs.color_b_;
    back_color_a_ = rhs.back_color_a_;
    back_color_r_ = rhs.back_color_r_;
    back_color_g_ = rhs.back_color_g_;
    back_color_b_ = rhs.back_color_b_;
    outline_color_a_ = rhs.outline_color_a_;
    outline_color_r_ = rhs.outline_color_r_;
    outline_color_g_ = rhs.outline_color_g_;
    outline_color_b_ = rhs.outline_color_b_;
    fill_ = rhs.fill_;
    gltext_ = rhs.gltext_;
    textFormatParams_ = std::move(rhs.textFormatParams_);
    buffer_opts_ = std::move(rhs.buffer_opts_);
    textSize = rhs.textSize;
    labelSize = rhs.labelSize;
    force_clamp_to_ground.front_ = rhs.force_clamp_to_ground.front_;
    force_clamp_to_ground.back_ = rhs.force_clamp_to_ground.back_;
    level_of_detail.min_ = rhs.level_of_detail.min_;
    level_of_detail.max_ = rhs.level_of_detail.max_;
    hit_testable_ = rhs.hit_testable_;
    heightInMeters_ = rhs.heightInMeters_;
    label_render_pump_ = rhs.label_render_pump_;
    max_tilt_ = rhs.max_tilt_;
}

GLLabel::GLLabel(Feature::Geometry2Ptr_const&& geom, TAK::Engine::Port::String text, Point2<double> desired_offset,
                 double max_draw_resolution, TextAlignment alignment, VerticalAlignment vertical_alignment, int color, int backColor,
                 bool fill, TAK::Engine::Feature::AltitudeMode altitude_mode, Priority priority)
    : altitude_mode_(altitude_mode),
      text_(text.get() != nullptr ? text.get() : ""),
      desired_offset_(desired_offset),
      visible_(true),
      alignment_(alignment),
      horizontal_alignment_(HorizontalAlignment::TEHA_Center),
      vertical_alignment_(vertical_alignment),
      priority_(priority),
      always_render_(false),
      color_r_(1),
      color_g_(1),
      color_b_(1),
      color_a_(1),
      back_color_r_(0),
      back_color_g_(0),
      back_color_b_(0),
      back_color_a_(0),
      outline_color_r_(0),
      outline_color_g_(0),
      outline_color_b_(0),
      outline_color_a_(1),
      fill_(fill),
      hints_(Hints::AutoSurfaceOffsetAdjust),
      float_weight_(0.5f),
      projected_size_(std::numeric_limits<double>::quiet_NaN()),
      mark_dirty_(true),
      draw_version_(-1),
      gltext_(nullptr),
      textFormatParams_(nullptr),
      hit_testable_(false),
      heightInMeters_(0)
{
    setMaxDrawResolution(max_draw_resolution);

    if(geom) {
        if (geom->getClass() == TAK::Engine::Feature::TEGC_Point) {
            geometry.point = static_cast<const TAK::Engine::Feature::Point2&>(*geom);
        } else {
            geometry.pointer = std::move(geom);
        }
        geometry.empty = false;
    } else {
        geometry.empty = true;
    }

    rotation_.angle_ = 0.0f;
    rotation_.absolute_ = false;
    rotation_.explicit_ = false;

#if CALL_LOCALIZE
    if (!text_.empty()) {
        Port::String localizedText;
        GLText2_localize(&localizedText, text_.c_str());
        text_ = localizedText.get() ? localizedText.get() : "";
    }
#endif
    setColor(color);
    setBackColor(backColor);

    initGlyphBuffersOpts(&buffer_opts_, *this);
}


GLLabel::GLLabel(Feature::Geometry2Ptr_const&& geometry, TAK::Engine::Port::String text, Point2<double> desired_offset,
                 double max_draw_resolution, TextAlignment alignment, VerticalAlignment vertical_alignment, int color, int fill_color,
                 bool fill, TAK::Engine::Feature::AltitudeMode altitude_mode, float rotation, bool absolute_rotation, Priority priority)
    : GLLabel(std::move(geometry), text, desired_offset, max_draw_resolution, alignment, vertical_alignment, color, fill_color, fill, altitude_mode, priority)
{
    rotation_.angle_ = rotation;
    rotation_.absolute_ = absolute_rotation;
    rotation_.explicit_ = true;
}

GLLabel::GLLabel(const TextFormatParams &fmt,
                 TAK::Engine::Feature::Geometry2Ptr_const&& geometry, TAK::Engine::Port::String text,
                 Math::Point2<double> desired_offset, double max_draw_resolution,
                 TextAlignment alignment,
                 VerticalAlignment vertical_alignment, int color,
                 int fill_color, bool fill,
                 TAK::Engine::Feature::AltitudeMode altitude_mode,
                 Priority priority) :
    GLLabel(std::move(geometry), text, desired_offset, max_draw_resolution, alignment, vertical_alignment, color, fill_color, fill, altitude_mode, priority)
{
    gltext_ = GLText2_intern(fmt);
    textFormatParams_.reset(new TextFormatParams(fmt));
    rotation_.angle_ = 0.0f;
    rotation_.absolute_ = false;
    rotation_.explicit_ = false;

    initGlyphBuffersOpts(&buffer_opts_, *this);
}

GLLabel::GLLabel(const TextFormatParams &fmt,
                 TAK::Engine::Feature::Geometry2Ptr_const&& geometry, TAK::Engine::Port::String text,
                 Math::Point2<double> desired_offset, double max_draw_resolution,
                 TextAlignment alignment,
                 VerticalAlignment vertical_alignment, int color,
                 int fill_color, bool fill,
                 TAK::Engine::Feature::AltitudeMode altitude_mode,
                 float rotation, bool rotationAbsolute,
                 Priority priority) :
    GLLabel(std::move(geometry), text, desired_offset, max_draw_resolution, alignment, vertical_alignment, color, fill_color, fill, altitude_mode, priority)
{
    gltext_ = GLText2_intern(fmt);
    textFormatParams_.reset(new TextFormatParams(fmt));
    rotation_.angle_ = rotation;
    rotation_.absolute_ = rotationAbsolute;
    rotation_.explicit_ = true;

    initGlyphBuffersOpts(&buffer_opts_, *this);
}

GLLabel::~GLLabel() NOTHROWS
{}

GLLabel& GLLabel::operator=(GLLabel&& rhs) NOTHROWS {
    if (this != &rhs) {
        geometry.pointer.reset();
        if (rhs.geometry.pointer) {
            geometry.pointer = std::move(rhs.geometry.pointer);
        } else {
            geometry.point = rhs.geometry.point;
        }
        geometry.empty = rhs.geometry.empty;
        altitude_mode_ = rhs.altitude_mode_;
        text_ = rhs.text_;
        desired_offset_ = rhs.desired_offset_;
        visible_ = rhs.visible_;
        always_render_ = rhs.always_render_;
        alignment_ = rhs.alignment_;
        horizontal_alignment_ = rhs.horizontal_alignment_;
        vertical_alignment_ = rhs.vertical_alignment_;
        priority_ = rhs.priority_;
        rotation_ = rhs.rotation_;
        insets_ = rhs.insets_;
        transformed_anchor_ = rhs.transformed_anchor_;
        draw_version_ = rhs.draw_version_;
        color_a_ = rhs.color_a_;
        color_r_ = rhs.color_r_;
        color_g_ = rhs.color_g_;
        color_b_ = rhs.color_b_;
        back_color_a_ = rhs.back_color_a_;
        back_color_r_ = rhs.back_color_r_;
        back_color_g_ = rhs.back_color_g_;
        back_color_b_ = rhs.back_color_b_;
        outline_color_a_ = rhs.outline_color_a_;
        outline_color_r_ = rhs.outline_color_r_;
        outline_color_g_ = rhs.outline_color_g_;
        outline_color_b_ = rhs.outline_color_b_;
        fill_ = rhs.fill_;
        gltext_ = rhs.gltext_;
        textFormatParams_ = std::move(rhs.textFormatParams_);
        hints_ = rhs.hints_;
        float_weight_ = rhs.float_weight_;
        buffer_opts_ = std::move(rhs.buffer_opts_);
        textSize = rhs.textSize;
        labelSize = rhs.labelSize;
        mark_dirty_ = rhs.mark_dirty_;
        force_clamp_to_ground.front_ = rhs.force_clamp_to_ground.front_;
        force_clamp_to_ground.back_ = rhs.force_clamp_to_ground.back_;
        level_of_detail.min_ = rhs.level_of_detail.min_;
        level_of_detail.max_ = rhs.level_of_detail.max_;
        hit_testable_ = rhs.hit_testable_;
        heightInMeters_ = rhs.heightInMeters_;
        should_use_fallback_method_ = rhs.should_use_fallback_method_;
        label_render_pump_ = rhs.label_render_pump_;
        max_tilt_ = rhs.max_tilt_;
    }

    return *this;
}

void GLLabel::setGeometry(const TAK::Engine::Feature::Geometry2& geom) NOTHROWS {
    geometry.pointer.reset();
    if (geom.getClass() == TAK::Engine::Feature::TEGC_Point) {
        geometry.point = static_cast<const TAK::Engine::Feature::Point2&>(geom);
    } else {
        TAK::Engine::Feature::Geometry_clone(geometry.pointer, geom);
    }
    geometry.empty = false;

    // need to invalidate the projected point
    mark_dirty_ = true;
}

const TAK::Engine::Feature::Geometry2* GLLabel::getGeometry() const NOTHROWS { return (geometry.empty || !!geometry.pointer) ? geometry.pointer.get() : &geometry.point; }

void GLLabel::setAltitudeMode(const TAK::Engine::Feature::AltitudeMode altitude_mode) NOTHROWS { altitude_mode_ = altitude_mode; }

void GLLabel::setText(TAK::Engine::Port::String text) NOTHROWS {
    if (text.get() != nullptr) {
#if CALL_LOCALIZE
        Port::String localizedText;
        GLText2_localize(&localizedText, text.get());
        text_ = localizedText.get() ? localizedText.get() : "";
#else
        text_ = text.get();
#endif
    } else
        text_.clear();

    // invalidate text size
    textSize.width = 0.f;
    textSize.height = 0.f;
    should_use_fallback_method_.check = 0u;
    textSize.valid = false;
}

void GLLabel::setTextFormat(const TextFormatParams* fmt) NOTHROWS {
    if (fmt != nullptr) {
        gltext_ = GLText2_intern(*fmt);
        if(textFormatParams_)
            *textFormatParams_ = *fmt;
        else
            textFormatParams_.reset(new TextFormatParams(*fmt));
    } else {
        gltext_ = nullptr;
        textFormatParams_ = nullptr;
    }
    buffer_opts_.is_default_font = !textFormatParams_;
    buffer_opts_.fontName = !textFormatParams_ ? nullptr : textFormatParams_->fontName;
    if (textFormatParams_) {
        buffer_opts_.bold = textFormatParams_->bold;
        buffer_opts_.italic = textFormatParams_->italic;
    } else {
        buffer_opts_.bold = false;
        buffer_opts_.italic = false;
    }
    buffer_opts_.underline = textFormatParams_ ? textFormatParams_->underline : false;
    buffer_opts_.strikethrough = textFormatParams_ ? textFormatParams_->strikethrough : false;

    // invalidate text size
    textSize.width = 0.f;
    textSize.height = 0.f;
    should_use_fallback_method_.check = 0u;
    textSize.valid = false;
}

void GLLabel::setVisible(const bool visible) NOTHROWS { visible_ = visible; }

void GLLabel::setAlwaysRender(const bool always_render) NOTHROWS { always_render_ = always_render; }

void GLLabel::setMaxDrawResolution(const double max_draw_resolution) NOTHROWS {
    int minLod = (!max_draw_resolution || TE_ISNAN(max_draw_resolution)) ?
        0 : atakmap::raster::osm::OSMUtils::mapnikTileLevel(max_draw_resolution);
    minLod = MathUtils_clamp(minLod, (int)atakmap::feature::LevelOfDetailStyle::MIN_LOD, (int)atakmap::feature::LevelOfDetailStyle::MAX_LOD);
    setLevelOfDetail((std::size_t)minLod, level_of_detail.max_);
}

void GLLabel::setAlignment(const TextAlignment alignment) NOTHROWS { 
    alignment_ = alignment;
    buffer_opts_.h_alignment = toGlyphHAlignment(alignment_);
}

void GLLabel::setHorizontalAlignment(const HorizontalAlignment horizontal_alignment) NOTHROWS { horizontal_alignment_ = horizontal_alignment; }

void GLLabel::setVerticalAlignment(const VerticalAlignment vertical_alignment) NOTHROWS { vertical_alignment_ = vertical_alignment; }

void GLLabel::setDesiredOffset(const Math::Point2<double>& desired_offset) NOTHROWS { desired_offset_ = desired_offset; }

void GLLabel::setColor(const int color) NOTHROWS {
    color_a_ = static_cast<float>((color >> 24) & 0xFF) / 255.0f;
    color_r_ = static_cast<float>((color >> 16) & 0xFF) / 255.0f;
    color_g_ = static_cast<float>((color >> 8) & 0xFF) / 255.0f;
    color_b_ = static_cast<float>((color >> 0) & 0xFF) / 255.0f;

    buffer_opts_.text_color_red = color_r_;
    buffer_opts_.text_color_green = color_g_;
    buffer_opts_.text_color_blue = color_b_;
    buffer_opts_.text_color_alpha = color_a_;

    //contrast outline color with text color based on luminosity
    float bglum = 0.2126f * color_r_ + 0.7152f * color_g_ + 0.0722f * color_b_;
    if(bglum > 0.5f)
    {
        outline_color_r_ = 0;
        outline_color_g_ = 0;
        outline_color_b_ = 0;
    }
    else
    {
        outline_color_r_ = 1;
        outline_color_g_ = 1;
        outline_color_b_ = 1;
    }

    buffer_opts_.outline_color_red = outline_color_r_;
    buffer_opts_.outline_color_green = outline_color_g_;
    buffer_opts_.outline_color_blue = outline_color_b_;

    // outline alpha should match color alpha
    buffer_opts_.outline_color_alpha = color_a_;
}
int GLLabel::getColor() const NOTHROWS {
    return (int)((uint32_t)(color_a_*255.f)<<24u |
            (uint32_t)(color_a_*255.f)<<16u |
            (uint32_t)(color_a_*255.f)<<8u |
            (uint32_t)(color_a_*255.f));
}

void GLLabel::setBackColor(const int color) NOTHROWS {
    back_color_a_ = static_cast<float>((color >> 24) & 0xFF) / 255.0f;
    back_color_r_ = static_cast<float>((color >> 16) & 0xFF) / 255.0f;
    back_color_g_ = static_cast<float>((color >> 8) & 0xFF) / 255.0f;
    back_color_b_ = static_cast<float>((color >> 0) & 0xFF) / 255.0f;

    buffer_opts_.back_color_red = back_color_r_;
    buffer_opts_.back_color_green = back_color_g_;
    buffer_opts_.back_color_blue = back_color_b_;
    buffer_opts_.back_color_alpha = back_color_a_;
}

void GLLabel::setFill(const bool fill) NOTHROWS
{
    fill_ = fill;
    buffer_opts_.fill = fill_;
    buffer_opts_.outline_weight = fill_ ? 0.f : 2.f;
}

void GLLabel::getRotation(float &angle, bool &absolute) const NOTHROWS {
    angle = rotation_.angle_;
    absolute = rotation_.absolute_;
}

void GLLabel::setRotation(const float rotation, const bool absolute_rotation) NOTHROWS {
    rotation_.angle_ = rotation;
    rotation_.absolute_ = absolute_rotation;
    rotation_.explicit_ = true;

    mark_dirty_ = true;
}

void GLLabel::setMaxTilt(const double maxTilt) NOTHROWS
{
    max_tilt_ = maxTilt;
    mark_dirty_ = true;
}

void GLLabel::setPriority(const Priority priority) NOTHROWS
{
    priority_ = priority;
    mark_dirty_ = true;
}

bool GLLabel::shouldRenderAtResolution(const double draw_resolution) const NOTHROWS {
    if (!visible_) return false;
    const int lod = atakmap::raster::osm::OSMUtils::mapnikTileLevel(draw_resolution);
    return priority_ == TEP_Always || always_render_ || (lod >= (int)level_of_detail.min_) && (lod < (int)level_of_detail.max_);
}

bool GLLabel::place(GLLabel::LabelPlacement &placement, const GLGlobeBase::State& view, const std::vector<LabelPlacement>& label_rects, const PlacementDeconflictMode deconflictMode, bool& rePlaced) NOTHROWS {

    return place(placement, view, *this, projected_size_, labelSize.width, labelSize.height, label_rects, deconflictMode, rePlaced);
}

bool GLLabel::place(GLLabel::LabelPlacement &placement, const GLGlobeBase::State& view, 
    const GLLabel &label, const double projectedSize, const float labelWidth, const float labelHeight, const std::vector<LabelPlacement>& label_rects, const PlacementDeconflictMode deconflictMode, bool& rePlaced) NOTHROWS {

    bool is_surface_label = !!(label.hints_ & GLLabel::Surface);
    rePlaced = false;

    const auto xpos = static_cast<float>(placement.anchor_xyz_.x);
    const auto ypos = static_cast<float>(placement.anchor_xyz_.y);
    const auto zpos = static_cast<float>(placement.anchor_xyz_.z);

    placement.render_xyz_.x = xpos;
    placement.render_xyz_.y = ypos;
    placement.render_xyz_.z = zpos;

    float textWidth = 0.f;
    float textHeight = 0.f;
    if (!label.text_.empty()) {
        const auto textDescent = label.textSize.descent;
        const auto textBaseline = label.textSize.baselineSpacing;

        float offy = 0;
        float offtx = 0;
        float offz = 0;
        textWidth = is_surface_label ? labelWidth : std::min(labelWidth, (float)(view.right - 20));
        textHeight = labelHeight;

        if (!TE_ISNAN(projectedSize)) {
            double availableWidth = projectedSize / view.drawMapResolution;
            if (availableWidth < textWidth) {
                placement.can_draw_ = false;
                return false;
            }
        }

        offtx = (float)label.desired_offset_.x;
        offy = (float)label.desired_offset_.y;
        offz = (float)label.desired_offset_.z;

#ifndef __ANDROID__
        if ((label.hints_&AutoSurfaceOffsetAdjust) && offy != 0.0 && view.drawTilt > 0.0) {
            offy *= (float)(1.0f + view.drawTilt / 100.0f);
        }
#else

        if((label.hints_&AutoSurfaceOffsetAdjust) && label.altitude_mode_ == Feature::TEAM_ClampToGround) {
            const double sin_tilt = sin(view.drawTilt/180.0*M_PI);
            offy += (float)(textHeight*sin_tilt*sin_tilt);
        }
#endif
        switch (label.vertical_alignment_) {
            case VerticalAlignment::TEVA_Top:
                offy += textDescent + textHeight;
                break;
            case VerticalAlignment::TEVA_Middle:
                offy += ((textDescent + textHeight) / 2.0f);
                break;
            case VerticalAlignment::TEVA_Bottom:
                break;
        }
        switch (label.horizontal_alignment_) {
            case HorizontalAlignment::TEHA_Left:
                offtx -= textWidth / 2.0f;
                break;
            case HorizontalAlignment::TEHA_Center:
                break;
            case HorizontalAlignment::TEHA_Right:
                offtx += textWidth / 2.0f;
                break;
        }

        // initial placement position
        placement.render_xyz_.x += (offtx - textWidth / 2.0);
        placement.render_xyz_.y += (double)(offy - textBaseline);
        placement.render_xyz_.z += offz;
    }

    const float alignOffX = static_cast<float>(placement.render_xyz_.x) - xpos;
    const float alignOffY = static_cast<float>(placement.render_xyz_.y) - ypos;

    if (is_surface_label)
    {
        placement.recomputeForSurface(view, label.heightInMeters_, view.drawRotation, labelWidth, labelHeight);
    } else
    {
        Point2<double> baseline_xyz(placement.render_xyz_);
        baseline_xyz.y -= label.textSize.descent + label.textSize.baselineSpacing * (float) (label.textSize.linecount - 1u);
        placement.recompute(baseline_xyz, view.drawRotation, labelWidth, labelHeight);
    }

    auto rectanglesOverlap = [](const LabelPlacement& a, const LabelPlacement& b) {
        if (!atakmap::math::Rectangle<double>::intersects(
            a.boundingRect.minX, a.boundingRect.minY, a.boundingRect.maxX, a.boundingRect.maxY,
            b.boundingRect.minX, b.boundingRect.minY, b.boundingRect.maxX, b.boundingRect.maxY)) {

            return false;
        }
        constexpr double maxOverlap = 0.0; // allow up to 30% overlap
        if (!a.boundingRect.rotated && !b.boundingRect.rotated) {
            // compute overlap
            const auto isectpct = rectangleOverlap(
                a.boundingRect.minX, a.boundingRect.minY, a.boundingRect.maxX, a.boundingRect.maxY,
                b.boundingRect.minX, b.boundingRect.minY, b.boundingRect.maxX, b.boundingRect.maxY);
            return isectpct > maxOverlap;
        }
        if (!IntersectRotatedRectangle(a.boundingRect.shape, b.boundingRect.shape))
            return false;

        // rotated rectangles are not aligned, do not test for overlap
        if (a.rotation_.absolute_ != b.rotation_.absolute_ || a.rotation_.angle_ != b.rotation_.angle_)
            return true;
        const double aw = Vector2_length(Vector2_subtract(a.boundingRect.shape[0], a.boundingRect.shape[3]));
        const double ah = Vector2_length(Vector2_subtract(a.boundingRect.shape[0], a.boundingRect.shape[1]));
        const double bw = Vector2_length(Vector2_subtract(b.boundingRect.shape[0], b.boundingRect.shape[3]));
        const double bh = Vector2_length(Vector2_subtract(b.boundingRect.shape[0], b.boundingRect.shape[1]));

        // test on the unrotated dimension at the render location. because the rotation of both
        // regions is the same, this should be sufficient for determining overlap percent and much
        // faster than computing the intersecting polygon and its area
        const auto isectpct = rectangleOverlap(
            a.render_xyz_.x, a.render_xyz_.y-ah, a.render_xyz_.x+aw, a.render_xyz_.y,
            b.render_xyz_.x, b.render_xyz_.y-bh, b.render_xyz_.x+bw, b.render_xyz_.y);
        return isectpct > maxOverlap;
    };

    bool overlaps = false;
    int replace_idx = -1;

    if(deconflictMode != PlacementDeconflictMode::None && !(label.hints_&GLLabel::Surface)) {
        int label_rectsLimit = (int)label_rects.size();
        for(int itr_idx = 0; itr_idx < label_rectsLimit; ) {
            const auto &itr = &label_rects[itr_idx];
            overlaps = rectanglesOverlap(placement, *itr);
            if (overlaps && !rePlaced && deconflictMode == PlacementDeconflictMode::Shift) {
                replace_idx = itr_idx;
                rePlaced = true;
                double leftShift = fabs((placement.render_xyz_.x + textWidth) - itr->render_xyz_.x);
                double rightShift = fabs(placement.render_xyz_.x - (itr->render_xyz_.x + textWidth));
                if (rightShift < leftShift && rightShift < (textWidth / 2.0f)) {
                    // shift right of compared label rect
                    placement.render_xyz_.x = itr->render_xyz_.x + textWidth + LABEL_PADDING_X;
                } else if (leftShift < (textWidth / 2.0f)) {
                    // shift left of compared label rect
                    placement.render_xyz_.x = itr->render_xyz_.x - textWidth - LABEL_PADDING_X;
                } else {
                    break;
                }

                Point2<double> baseline_xyz(placement.render_xyz_);
                baseline_xyz.y -= label.textSize.baselineSpacing * (float)(label.textSize.linecount-1u);
                placement.recompute(baseline_xyz, view.drawRotation, labelWidth, labelHeight);
                overlaps = rectanglesOverlap(placement, (*itr));
            }

            itr_idx++;
            if (overlaps) break;
        }
    }

    if (!overlaps && rePlaced) {
        for( ; replace_idx >= 0; replace_idx--) {
            auto reverse_itr = &label_rects[replace_idx];
            overlaps = rectanglesOverlap(placement, (*reverse_itr));

            if (overlaps) break;
        }
    }

    placement.can_draw_ &= !overlaps;
    return placement.can_draw_;
}

void GLLabel::draw(const GLGlobeBase& view, GLText2& gl_text) NOTHROWS {
    if (!text_.empty()) {
        const char* text = text_.c_str();

        for(const auto &a : transformed_anchor_) {
            try {
                GLES20FixedPipeline::getInstance()->glPushMatrix();

                const auto xpos = static_cast<float>(a.anchor_xyz_.x);
                const auto ypos = static_cast<float>(a.anchor_xyz_.y);
                const auto zpos = static_cast<float>(a.anchor_xyz_.z);
                GLES20FixedPipeline::getInstance()->glTranslatef(xpos, ypos, zpos);
                float rotate = static_cast<float>(a.rotation_.angle_);
                if (a.rotation_.absolute_) {
                    rotate = (float)fmod(rotate + view.renderPass->drawRotation, 360.0);
                }
                GLES20FixedPipeline::getInstance()->glRotatef(rotate, 0.0f, 0.0f, 1.0f);
                GLES20FixedPipeline::getInstance()->glTranslatef((float)a.anchor_xyz_.x - xpos, (float)a.anchor_xyz_.y - ypos, 0.0f - zpos);

                const auto alphaAdjust = getTextAlphaAdjust(*view.renderPass);

                if(hints_&GLLabel::ScrollingText && (labelSize.width > (MAX_TEXT_WIDTH*GLMapRenderGlobals_getRelativeDisplayDensity()))) {
                    GLES20FixedPipeline::getInstance()->glPushMatrix();
                    GLES20FixedPipeline::getInstance()->glTranslatef(marquee_.offset_, 0.f, 0.f);
                    gl_text.draw(text,
                            color_r_,
                            color_g_,
                            color_b_,
                            color_a_ * alphaAdjust,
                            -marquee_.offset_, -marquee_.offset_ + labelSize.width);
                    GLES20FixedPipeline::getInstance()->glPopMatrix();

                    marqueeAnimate(view.animationDelta);
                } else {
                    gl_text.draw(text, color_r_, color_g_, color_b_, color_a_ * alphaAdjust);
                }

                GLES20FixedPipeline::getInstance()->glPopMatrix();
            } catch (std::out_of_range&) {
                // ignored
            }
        }
    }
}

void GLLabel::batch(const GLGlobeBase& view, GLText2& gl_text, GLRenderBatch2& batch, int render_pass) NOTHROWS
{
    if (text_.empty())
        return;
    for(const auto &a : transformed_anchor_)
        if(a.can_draw_) this->batch(view, gl_text, batch, a, render_pass);
}

void GLLabel::batch(const GLGlobeBase& view, GLText2& gl_text, GLRenderBatch2& batch, const LabelPlacement& anchor, int render_pass) NOTHROWS
{
    did_animate_ = false;
    if (!text_.empty()) {
        const char* text = text_.c_str();
#if 0
        float zpos = (float)std::max(transformedAnchor.z, 0.0);

        if (view.drawTilt > 0.0) {
            zpos -= 1;
        }
#else
        auto zpos = (float)anchor.anchor_xyz_.z;
#endif

        float alpha = color_a_;
        float back_alpha = back_color_a_;

        if(render_pass & GLGlobeBase::XRay)
        {
            alpha = std::min(alpha, .4f);
            back_alpha = std::min(back_alpha, .4f);
        }

        const auto alphaAdjust = getTextAlphaAdjust(*view.renderPass);
        alpha *= alphaAdjust;
        back_alpha *= alphaAdjust;

        double rotate = anchor.rotation_.angle_;
        if (anchor.rotation_.absolute_) {
            rotate = fmod(rotate + view.renderPass->drawRotation, 360.0);
        }

        size_t lineCount = gl_text.getLineCount(text);
        float lineHeight = gl_text.getTextFormat().getCharHeight();
        float lineWidth = textSize.width;
        float ninePatchYShift = ((lineCount - 1) * lineHeight);
        float ninePatchHeightShift = 0.f;

        // may find that Windows/other plats needs this too. If so, incorporate.
#if __ANDROID__
        // shift down descent minus some padding to to look centered in background
        ninePatchYShift += std::max(0.f, gl_text.getTextFormat().getDescent() - 2.f);

        // involve descent in background ninepatch height (correct for multiline labels)
        ninePatchHeightShift = (lineCount - 1) * (gl_text.getTextFormat().getDescent() - 2.f);
#endif
        // adjust the transforms and render location if rotation should be applied
        Math::Point2<double> labelCorner(anchor.render_xyz_);
        if (rotate) {
            batch.pushMatrix(GL_MODELVIEW);
            float mx[16];
            GLES20FixedPipeline::getInstance()->readMatrix(GLES20FixedPipeline::MatrixMode::MM_GL_MODELVIEW, mx);
            Matrix2 matrix(mx[0], mx[4], mx[8], mx[12],
                           mx[1], mx[5], mx[9], mx[13],
                           mx[2], mx[6],mx[10], mx[14],
                           mx[3], mx[7], mx[11], mx[15]);
            matrix.rotate((360 - rotate) / ONE_EIGHTY_OVER_PI, 0, 0, 1);

            double v[16u];
            matrix.get(v, Matrix2::ROW_MAJOR);
            for(std::size_t i = 0u; i < 16u; i++)
                mx[i] = (float)v[i];
            batch.setMatrix(GL_MODELVIEW, mx);

            const auto xpos = static_cast<float>(anchor.anchor_xyz_.x);
            const auto ypos = static_cast<float>(anchor.anchor_xyz_.y);
            matrix.transform(&labelCorner, Math::Point2<double>(xpos, ypos));

            labelCorner.x += anchor.render_xyz_.x - xpos;
            labelCorner.y += anchor.render_xyz_.y - ypos;
        }

        if (fill_) {
            getSmallNinePatch(view.context);
            if (small_nine_patch_ != nullptr) {
                small_nine_patch_->batch(batch, (float)labelCorner.x - 4.0f, (float)labelCorner.y - ninePatchYShift - 4.0f,
                                      zpos, (float)labelSize.width + 8.0f, (float)labelSize.height + ninePatchHeightShift, back_color_r_, back_color_g_,
                                      back_color_b_, back_alpha);
            }
        }

        const float maxTextWidth = MAX_TEXT_WIDTH*GLMapRenderGlobals_getRelativeDisplayDensity();
        if((hints_&GLLabel::ScrollingText) && (textSize.width > maxTextWidth)) {
            // apply scrolling effect
            float scissorX0 = 0.0f;
            float scissorX1 = std::numeric_limits<float>::max();

            scissorX0 = -marquee_.offset_;
            scissorX1 = -marquee_.offset_ + maxTextWidth;
            labelCorner.x += marquee_.offset_;

            gl_text.batch(batch,
                    text,
                    (float)labelCorner.x,
                    (float)labelCorner.y + gl_text.getTextFormat().getBaselineSpacing(),
                    zpos,
                    color_r_,
                    color_g_,
                    color_b_,
                    alpha,
                    fill_ ? 0.f : outline_color_r_,
                    fill_ ? 0.f : outline_color_b_,
                    fill_ ? 0.f : outline_color_g_,
                    fill_ ? 0.f : alpha,
                    scissorX0, scissorX1);

            marqueeAnimate(view.animationDelta);
        } else
        if (lineCount == 1 || alignment_ == TextAlignment::TETA_Left && lineWidth <= labelSize.width) {
            gl_text.batch(batch, text, (float)labelCorner.x, (float)labelCorner.y, zpos, color_r_, color_g_, color_b_, alpha,
                    fill_ ? 0.f : outline_color_r_,
                    fill_ ? 0.f : outline_color_b_,
                    fill_ ? 0.f : outline_color_g_,
                    fill_ ? 0.f : alpha);
        } else {
            size_t pos = 0;
            std::string token;
            std::string strText = text_;
            float offx = 0.0;
            float offy = 0.0;
            while ((pos = strText.find("\n")) != std::string::npos) {
                token = strText.substr(0, pos);
                const char* token_text = token.c_str();
                float tokenLineWidth = gl_text.getTextFormat().getStringWidth(token_text);
                if (tokenLineWidth > labelSize.width) {
                    size_t numChars = (size_t)((labelSize.width / tokenLineWidth) * token.length()) - 2;
                    token = token.substr(0, numChars);
                    token += "...";
                    token_text = token.c_str();
                    tokenLineWidth = gl_text.getTextFormat().getStringWidth(token_text);
                }
                switch (alignment_) {
                    case TextAlignment::TETA_Left:
                        offx = 0;
                        break;
                    case TextAlignment::TETA_Center:
                        offx = ((float)labelSize.width - tokenLineWidth) / 2.0f;
                        break;
                    case TextAlignment::TETA_Right:
                        offx = (float)labelSize.width - tokenLineWidth;
                        break;
                }
                gl_text.batch(batch, token.c_str(), (float)labelCorner.x + offx, (float)labelCorner.y - offy, zpos, color_r_, color_g_,
                             color_b_, alpha,
                             fill_ ? 0.f : outline_color_r_,
                             fill_ ? 0.f : outline_color_b_,
                             fill_ ? 0.f : outline_color_g_,
                             fill_ ? 0.f : alpha);
                offy += gl_text.getTextFormat().getStringHeight(token.c_str());
                strText.erase(0, pos + 1);
            }

            text = strText.c_str();
            lineWidth = gl_text.getTextFormat().getStringWidth(text);
            if (lineWidth > labelSize.width) {
                size_t numChars = (size_t)((labelSize.width / lineWidth) * strText.length()) - 1;
                strText = strText.substr(0, numChars);
                strText += "...";
                text = strText.c_str();
                lineWidth = gl_text.getTextFormat().getStringWidth(text);
            }
            switch (alignment_) {
                case TextAlignment::TETA_Left:
                    offx = 0;
                    break;
                case TextAlignment::TETA_Center:
                    offx = ((float)labelSize.width - lineWidth) / 2.0f;
                    break;
                case TextAlignment::TETA_Right:
                    offx = (float)labelSize.width - lineWidth;
                    break;
            }
            gl_text.batch(batch, text, (float)labelCorner.x + offx, (float)labelCorner.y - offy, zpos, color_r_, color_g_, color_b_,
                         alpha,
                         fill_ ? 0.f : outline_color_r_,
                         fill_ ? 0.f : outline_color_b_,
                         fill_ ? 0.f : outline_color_g_,
                         fill_ ? 0.f : alpha);
        }
        // reset the transforms if rotated
        if(rotate)
            batch.popMatrix(GL_MODELVIEW);
    }
}

atakmap::renderer::GLNinePatch* GLLabel::getSmallNinePatch(TAK::Engine::Core::RenderContext &surface) NOTHROWS {
    if (this->small_nine_patch_ == nullptr) {
        GLTextureAtlas2* atlas;
        GLMapRenderGlobals_getTextureAtlas2(&atlas, surface);
        small_nine_patch_ = new GLNinePatch(atlas, GLNinePatch::Size::SMALL, 16, 16, 5, 5, 10, 10);
    }
    return small_nine_patch_;
}

void GLLabel::validate(const GLGlobeBase& view, const GLText2 &text) NOTHROWS
{
    validate(view, text.getTextFormat());
}
void GLLabel::validate(const GLGlobeBase::State& view, const GLText2 &text) NOTHROWS
{
    validate(view, text.getTextFormat());
}
void GLLabel::validate(const GLGlobeBase& view, TextFormat2& text_format) NOTHROWS
{
    validateImpl(*view.renderPass, text_format);
}
void GLLabel::validate(const GLGlobeBase::State& view, TextFormat2& text_format) NOTHROWS
{
    validateImpl(view, text_format);
}
void GLLabel::setForceClampToGround(const bool v) NOTHROWS
{
    force_clamp_to_ground.back_ = v;
}
void GLLabel::setLevelOfDetail(const std::size_t minLod, const std::size_t maxLod) NOTHROWS
{
    level_of_detail.min_ = minLod;
    level_of_detail.max_ = maxLod;
}
void GLLabel::setHitTestable(const bool value) NOTHROWS
{
    hit_testable_ = value;
}
bool GLLabel::isHitTestable() const NOTHROWS
{
    return hit_testable_;
}
void GLLabel::setHeightInMeters(const double value) NOTHROWS
{
    heightInMeters_ = value;
}
void GLLabel::setTouchLabelVisibility(const std::shared_ptr<int> &renderPump) NOTHROWS
{
    label_render_pump_ = renderPump;
}
bool GLLabel::isVisible(const int renderPump) const NOTHROWS
{
    auto lrp = label_render_pump_;
    return !lrp || (*lrp >= renderPump);
}
void GLLabel::validateImpl(const GLGlobeBase::State& view, TextFormat2& text_format) NOTHROWS
{
    mark_dirty_ |= (force_clamp_to_ground.front_ != force_clamp_to_ground.back_);
    if (!mark_dirty_ && draw_version_ == view.drawVersion) return;
    if (geometry.empty) return;

    force_clamp_to_ground.front_ = force_clamp_to_ground.back_;
    validateTextSize(*this, text_format);
    labelSize.width = (hints_&GLLabel::ScrollingText) ?
            std::min(textSize.width, MAX_TEXT_WIDTH*GLMapRenderGlobals_getRelativeDisplayDensity()) :
            textSize.width;
    labelSize.height = textSize.height;
    validateTextPlacement(transformed_anchor_, view, *this);

    mark_dirty_ = false;
    draw_version_ = view.drawVersion;
}
float GLLabel::getTextAlphaAdjust(const GLGlobeBase::State &state) const NOTHROWS
{
    if(TE_ISNAN(max_tilt_))
        return 1.f;

    constexpr auto thresholdPercent = 0.6;
    const auto tilt = fabs(state.drawTilt);
    const auto fadeThreshold = max_tilt_ * thresholdPercent;
    if(tilt < fadeThreshold)
        return 1.f;
    else if(tilt >= max_tilt_)
        return 0.f;

    return 1.f - (float)((tilt-fadeThreshold) / (max_tilt_-fadeThreshold));
}
void GLLabel::validateTextSize(const GLLabel &label, TextFormat2& text_format) NOTHROWS
{
    if(label.textSize.valid) {
    } else if (!label.text_.empty()) {
        const char* text = label.text_.c_str();
        textSize.width = text_format.getStringWidth(text);
        textSize.height = text_format.getStringHeight(text);
        textSize.baselineSpacing = text_format.getBaselineSpacing();
        textSize.descent = text_format.getDescent();
        textSize.linecount = 1u;
        const auto textLength = label.text_.length();
        for(std::size_t i = 0u; i < textLength; i++)
            if(label.text_[i] == '\n')
                textSize.linecount++;
        textSize.valid = true;
    } else {
        textSize.width = 0.f;
        textSize.height = 0.f;
        textSize.baselineSpacing = 0;
        textSize.descent = 0;
        textSize.linecount = 1;
        textSize.valid = true;
    }
}
void GLLabel::validateTextPlacement(std::vector<LabelPlacement> &placements, const TAK::Engine::Renderer::Core::GLGlobeBase::State& view, const GLLabel &label) NOTHROWS
{
    if (label.geometry.empty) return;

    auto& labelGeom = *label.getGeometry();
    const auto altitudeMode = label.force_clamp_to_ground.front_ ?
        Feature::TEAM_ClampToGround : label.altitude_mode_;

    switch (labelGeom.getClass()) {
        case Feature::TEGC_Point:
            validatePointTextPlacement(placements, view, label, altitudeMode, static_cast<const Feature::Point2&>(labelGeom));
            break;
        case Feature::TEGC_LineString:
            validateLineStringTextPlacement(placements, view, label, altitudeMode, static_cast<const Feature::LineString2&>(labelGeom));
            break;
        case Feature::TEGC_Polygon: {
                std::shared_ptr<Feature::LineString2> exteriorRing;
                static_cast<const Feature::Polygon2 &>(labelGeom).getExteriorRing(exteriorRing);
                if(exteriorRing)
                    validateLineStringTextPlacement(placements, view, label, altitudeMode, *exteriorRing);
            } break;
            // case TEGC_GeometryCollection:
            //	value = Geometry2Ptr(new GeometryCollection2(static_cast<const
            // GeometryCollection2&>(geometry)),
            // Memory_deleter_const<Geometry2>); 	break;
        default :
            break;
    }

    // sync render locations with anchor locations; to be updated via subsequent placement
    for(auto &a : placements)
        a.render_xyz_ = a.anchor_xyz_;
}
void GLLabel::validatePointTextPlacement(std::vector<LabelPlacement> &placements, const TAK::Engine::Renderer::Core::GLGlobeBase::State& view, const GLLabel &label, const TAK::Engine::Feature::AltitudeMode altitudeMode, const TAK::Engine::Feature::Point2 &point) NOTHROWS
{
    GeoPoint2 textLoc(point.y, point.x, point.z, AltitudeReference::HAE);
    if (altitudeMode == Feature::TEAM_ClampToGround) textLoc.altitude = NAN;
    // if rotation was not explicitly specified, make relative
    const bool rotationAbsolute = label.rotation_.absolute_ && label.rotation_.explicit_;
    if(label.hints_&AutoSurfaceOffsetAdjust)
        textLoc = adjustSurfaceLabelAnchor(view, textLoc, altitudeMode);
    else if (altitudeMode == Feature::TEAM_Relative) {
        double elevation;
        getTerrainMeshElevation(&elevation, view, textLoc.latitude, textLoc.longitude);
        textLoc.altitude += elevation;
    } else if (altitudeMode == Feature::TEAM_ClampToGround) {
        getTerrainMeshElevation(&textLoc.altitude, view, textLoc.latitude, textLoc.longitude);
    }

    placements.clear();
    placements.push_back(LabelPlacement());

    Point2<double> pos_projected;
    view.scene.projection->forward(&pos_projected, textLoc);
    view.scene.forwardTransform.transform(&placements[0].anchor_xyz_, pos_projected);
    if (label.rotation_.explicit_) {
        placements[0].rotation_.angle_ = label.rotation_.angle_;
        placements[0].rotation_.absolute_ = rotationAbsolute;
    }
}
void GLLabel::validateLineStringTextPlacement(std::vector<LabelPlacement> &placements, const TAK::Engine::Renderer::Core::GLGlobeBase::State& view, const GLLabel &label, const TAK::Engine::Feature::AltitudeMode altitudeMode, const TAK::Engine::Feature::LineString2 &lineString) NOTHROWS
{
    struct {
        float width;
        float height;
    } labelSize;;
    labelSize.width = (label.hints_&GLLabel::ScrollingText) ?
                      std::min(label.textSize.width, MAX_TEXT_WIDTH*GLMapRenderGlobals_getRelativeDisplayDensity()) :
                      label.textSize.width;
    labelSize.height = label.textSize.height;

    size_t numPoints = lineString.getNumPoints();
    const bool isFloatingLabel = label.hints_&Hints::WeightedFloat;

    GeoPoint2 sp;
    getRenderPoint(&sp, view, lineString, 0u, altitudeMode);
    GeoPoint2 ep;
    getRenderPoint(&ep, view, lineString, 1u, altitudeMode);

    Point2<float> spxy, epxy;
    view.scene.forward(&spxy, sp);
    view.scene.forward(&epxy, ep);

    // adjust points on other side of near plane
    intersectWithNearPlane(spxy, epxy, view, sp, ep);

    // LLA location of text anchor
    GeoPoint2 textLoc = GeoPoint2_midpoint(sp, ep, true);

    // forms rotated axis for text baseline
    Point2<float> axisa(spxy);
    Point2<float> axisb(epxy);
    if(isFloatingLabel)
        FindIntersection<float>(axisa, axisb, static_cast<float>(view.left), static_cast<float>(view.bottom),
                                static_cast<float>(view.right), static_cast<float>(view.top));

    const float segmentPositionWeight = label.float_weight_;
    if(altitudeMode == Feature::TEAM_ClampToGround && numPoints == 2u) {
        placements.clear();

        // ensure the screenspace size of the line is sufficient for render
        const auto dx = axisb.x-axisa.x;
        const auto dy = axisb.y-axisa.y;
        const auto axislen = Vector2_length(Point2<double>(dx, dy));
        if(std::max(labelSize.width, labelSize.height) <= axislen) {
            textLoc = isFloatingLabel ?
                    closestSurfacePointToFocus(view, (float)(axisa.x+dx*segmentPositionWeight), (float)(axisa.y+dy*segmentPositionWeight), sp, ep) :
                    GeoPoint2_pointAtDistance(sp, ep, segmentPositionWeight, true);

            // use terrain mesh elevation
            getTerrainMeshElevation(&textLoc.altitude, view, textLoc.latitude, textLoc.longitude);

            if(!label.rotation_.explicit_) {
                const double weight = GeoPoint2_distance(sp, textLoc, true) /
                                      GeoPoint2_distance(sp, ep, true);
                const double startBrg = GeoPoint2_bearing(textLoc, sp, true);
                const double endBrg = GeoPoint2_bearing(textLoc, ep, true);

#define SS_ROTATION_AXIS_RADIUS 16.0

                const double rotationAxisRadius = (!!labelSize.width) ?
                                                  labelSize.width / 2.0 : SS_ROTATION_AXIS_RADIUS;

                // recompute `points` as small segment within screen bounds
                // based on surface text location to ensure proper label
                // rotation
                GeoPoint2 rotAxisSP = GeoPoint2_pointAtDistance(textLoc,
                                                                weight > 0.0 ? startBrg
                                                                             : -endBrg,
                                                                rotationAxisRadius *
                                                                view.scene.gsd,
                                                                true);
                getTerrainMeshElevation(&rotAxisSP.altitude, view, rotAxisSP.latitude,
                                        rotAxisSP.longitude);
                view.scene.forward(&axisa, rotAxisSP);

                GeoPoint2 rotAxisEP = GeoPoint2_pointAtDistance(textLoc,
                                                                weight < 1.0 ? endBrg
                                                                             : -startBrg,
                                                                rotationAxisRadius *
                                                                view.scene.gsd,
                                                                true);
                getTerrainMeshElevation(&rotAxisEP.altitude, view, rotAxisEP.latitude,
                                        rotAxisEP.longitude);
                view.scene.forward(&axisb, rotAxisEP);
            }

            if (label.hints_ & AutoSurfaceOffsetAdjust)
                textLoc = adjustSurfaceLabelAnchor(view, textLoc, altitudeMode);

            placements.push_back(LabelPlacement());

            Point2<double> pos_projected;
            view.scene.projection->forward(&pos_projected, textLoc);
            view.scene.forwardTransform.transform(&placements.back().anchor_xyz_, pos_projected);
        }
    } else if(altitudeMode == Feature::TEAM_ClampToGround) {
        std::vector<FloatingAnchor> anchors;
        Point2<double> midpointxy;
        // NOTE: `validateSurfaceFloatingLabel` only returns those
        //       labels with adequately sized screenspace geometry
        if(isFloatingLabel)
            validateSurfaceFloatingLabel(anchors, &midpointxy, view, lineString, segmentPositionWeight, labelSize.width);
        else
            validateSurfaceLabel(anchors, &midpointxy, view, lineString, segmentPositionWeight, labelSize.width);
        placements.clear();
        for(auto &a : anchors) {
            if(label.hints_&AutoSurfaceOffsetAdjust)
                textLoc = adjustSurfaceLabelAnchor(view, a.lla, altitudeMode);

            LabelPlacement placement;
            Point2<double> pos_projected;
            view.scene.projection->forward(&pos_projected, a.lla);
            view.scene.forwardTransform.transform(&placement.anchor_xyz_, pos_projected);

            if(label.rotation_.explicit_) {
                placement.rotation_.angle_ = label.rotation_.angle_;
                placement.rotation_.absolute_ = label.rotation_.absolute_;
            } else {
                placement.rotation_.angle_ =
                        (float) (atan2(a.axis.a.y - a.axis.b.y, a.axis.a.x - a.axis.b.x)
                                 * 180.0 / M_PI);
                if (placement.rotation_.angle_ > 90 || placement.rotation_.angle_ < -90)
                    placement.rotation_.angle_ += 180.0;
                placement.rotation_.absolute_ = false;
            }

            if((label.hints_&DuplicateOnSplit) || placements.empty()) {
                placements.push_back(placement);
                axisa = a.axis.a;
                axisb = a.axis.b;
            } else if(placement.anchor_xyz_.z < 1.f &&
                      DistanceSquared<double>(placement.anchor_xyz_.x, placement.anchor_xyz_.y, midpointxy.x, midpointxy.y) <
                      DistanceSquared<double>(placements[0].anchor_xyz_.x, placements[0].anchor_xyz_.y, midpointxy.x, midpointxy.y)) {

                // no duplication is occurring, output will be
                // segment label closest to focus
                placements[0] = placement;
                axisa = a.axis.a;
                axisb = a.axis.b;
            }
        }
    } else {
        const Point2<double> midpointxy(axisa.x+(axisb.x-axisa.x)*segmentPositionWeight, axisa.y+(axisb.y-axisa.y)*segmentPositionWeight);

        placements.clear();
        if(std::max(labelSize.width, labelSize.height) <=
           Vector2_length(Point2<double>(axisa.x-axisb.x, axisa.y-axisb.y))) {

            placements.push_back(LabelPlacement());
            placements.back().anchor_xyz_ = midpointxy;
            placements.back().anchor_xyz_.z = std::min(spxy.z, epxy.z);
        }
    }

    // if the rotation is not explicit, compute from the screen-space rotation axis
    float rotationAngle = label.rotation_.angle_;
    bool rotationAbsolute = label.rotation_.absolute_;
    if(!label.rotation_.explicit_) {
        rotationAngle = (float) (atan2(axisa.y - axisb.y, axisa.x - axisb.x)
                                 * 180.0 / M_PI);
        if (rotationAngle > 90 || rotationAngle < -90) rotationAngle += 180.0;
        rotationAbsolute = false;
    }
    if(placements.size() == 1u) {
        placements.back().rotation_.angle_ = rotationAngle;
        placements.back().rotation_.absolute_ = rotationAbsolute;
    }
}

void GLLabel::setHints(const unsigned int hints) NOTHROWS
{
    hints_ = hints;
}
unsigned int GLLabel::getHints() const NOTHROWS
{
    return hints_;
}
void GLLabel::setPlacementInsets(const float left, const float right, const float bottom, const float top) NOTHROWS
{
    insets_.left_ = left;
    insets_.right_ = right;
    insets_.bottom_ = bottom;
    insets_.top_ = top;
}
TAKErr GLLabel::setFloatWeight(const float weight) NOTHROWS
{
    if(weight < 0.f || weight > 1.f)
        return TE_InvalidArg;
    float_weight_ = weight;
    return TE_Ok;
}
void GLLabel::marqueeAnimate(const int64_t animDelta) NOTHROWS
{
    const float maxTextWidth = MAX_TEXT_WIDTH*GLMapRenderGlobals_getRelativeDisplayDensity();
    float textEndX = marquee_.offset_ + textSize.width;
    if (marquee_.timer_ <= 0) {
        // return to neutral scroll and wait 3 seconds
        if (textEndX <= maxTextWidth) {
            marquee_.timer_ = 3000LL;
            marquee_.offset_ = 0.f;
        } else {
            // animate at 10 pixels per second
            marquee_.offset_ -= (animDelta * 0.02f);
            if (marquee_.offset_ + textSize.width <= maxTextWidth) {
                marquee_.offset_ = maxTextWidth - textSize.width;
                marquee_.timer_ = 2000LL;
            }
        }
    } else {
        marquee_.timer_ -= animDelta;
    }

    did_animate_ = true;
}
void GLLabel::initGlyphBuffersOpts(GlyphBuffersOpts *value, const GLLabel &label) NOTHROWS
{
    auto& opts = *value;
    auto textFormatParams = label.textFormatParams_.get();
    const char *fontName = !!textFormatParams ? textFormatParams->fontName : nullptr;

    if (textFormatParams) {
        opts.bold = textFormatParams->bold;
        opts.italic = textFormatParams->italic;
    } else {
        opts.bold = false;
        opts.italic = false;
    }

    opts.fontName = TAK::Engine::Port::String_intern(fontName);
    opts.underline = textFormatParams ? textFormatParams->underline : false;
    opts.strikethrough = textFormatParams ? textFormatParams->strikethrough : false;
    opts.fill = label.fill_;
    opts.outline_weight = label.fill_ ? 0.f : 2.f;
    opts.text_color_red = label.color_r_;
    opts.text_color_green = label.color_g_;
    opts.text_color_blue = label.color_b_;
    opts.text_color_alpha = label.color_a_;
    opts.back_color_red = label.back_color_r_;
    opts.back_color_green = label.back_color_g_;
    opts.back_color_blue = label.back_color_b_;
    opts.back_color_alpha = label.back_color_a_;
    opts.outline_color_red = label.outline_color_r_;
    opts.outline_color_blue = label.outline_color_g_;
    opts.outline_color_green = label.outline_color_b_;
    opts.outline_color_alpha = label.outline_color_a_;
    opts.h_alignment = toGlyphHAlignment(label.alignment_);
    opts.point_size = 0.0;
    opts.xray_alpha = label.hints_ & GLLabel::XRay ? 0.4f : 0.0f;
    opts.is_default_font = !textFormatParams;
}
