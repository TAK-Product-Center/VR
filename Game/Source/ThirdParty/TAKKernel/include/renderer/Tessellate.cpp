#include "renderer/Tessellate.h"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <array>
#include <list>
#include <vector>

#include "core/GeoPoint2.h"
#include "formats/mbtiles/earcut.hpp"
#include "math/Vector4.h"

using namespace TAK::Engine::Renderer;

using namespace TAK::Engine::Core;
using namespace TAK::Engine::Math;
using namespace TAK::Engine::Util;

namespace mapbox {
    namespace util {
        template <>
        struct nth<0, Point2<double>> {
            inline static auto get(const Point2<double> &t) {
                return t.x;
            };
        };
        template <>
        struct nth<1, Point2<double>> {
            inline static auto get(const Point2<double> &t) {
                return t.y;
            };
        };
    } // namespace util
} // namespace mapbox

namespace
{
    struct Ring_
    {
        typedef Point2<double> value_type;

        value_type operator[](const std::size_t idx) const
        {
            Point2<double> xy;
            data.buffer.position(idx*data.layout.stride);
            readVert(&xy, data.buffer, data.layout);
            return xy;
        }
        std::size_t size() const
        {
            return data.count;
        }

        ReadVertexFn readVert{nullptr};
        struct {
            mutable MemBuffer2 buffer;
            VertexData layout;
            std::size_t count{0u};
        } data;
    };
    struct Polygon_
    {
        typedef Ring_ value_type;

        value_type operator[](const std::size_t idx) const
        {
            Ring_ ring;
            ring.readVert = readVert;
            ring.data.layout = rings.startIndex ? rings.data[0] : rings.data[idx];
            ring.data.count = (std::size_t)rings.vertexCount[idx];
            ring.data.buffer = MemBuffer2(
                    reinterpret_cast<uint8_t*>(ring.data.layout.data) +
                        (rings.startIndex ? (ring.data.layout.stride * rings.startIndex[idx]) : 0),
                    ring.data.count*ring.data.layout.stride);
            return ring;
        }
        std::size_t size() const
        {
            return rings.count;
        }
        bool empty() const
        {
            return !rings.count;
        }

        ReadVertexFn readVert {nullptr};
        struct {
            const VertexData* data{nullptr};
            const int *vertexCount{nullptr};
            const int *startIndex{nullptr};
            std::size_t count {0u};
        } rings;
    };

    void VertexData_deleter(const VertexData *value);

    Algorithm wgs84() NOTHROWS;
    double WGS84_distance(const Point2<double> &a, const Point2<double> &b);
    Point2<double> WGS84_direction(const Point2<double> &a, const Point2<double> &b);
    Point2<double> WGS84_interpolate(const Point2<double> &origin, const Point2<double> &dir, const double distance);
	TAKErr WGS84_intersect(Point2<double> &intersect,
		const Point2<double> &origin1, const Point2<double> &dir1,
		const Point2<double> &origin2, const Point2<double> &dir2);

    Algorithm cartesian() NOTHROWS;
    double Cartesian_distance(const Point2<double> &a, const Point2<double> &b);
    Point2<double> Cartesian_direction(const Point2<double> &a, const Point2<double> &b);
    Point2<double> Cartesian_interpolate(const Point2<double> &origin, const Point2<double> &dir, const double distance);
	TAKErr Cartesian_intersect(Point2<double> &intersect,
		const Point2<double> &origin1, const Point2<double> &dir1,
		const Point2<double> &origin2, const Point2<double> &dir2);

    Point2<double> midpoint(const Point2<double> &a, const Point2<double> &b, Algorithm alg) NOTHROWS;
    Point2<double> midpoint2(const Point2<double> &a, const Point2<double> &dir, const double hdab, Algorithm alg) NOTHROWS
    {
        return alg.interpolate(a, dir, hdab);
    }

    TAKErr triangle_r(TessellateCallback &sink, const Point2<double>& a, const Point2<double>& b, const Point2<double>& c, const double dab, const double dbc, const double dca, const double threshold, Algorithm alg, std::size_t depth) NOTHROWS;

    template<typename T>
    TAKErr polygon(TessellateCallback &value, const T &polygon, const double threshold, Algorithm &algorithm, const bool *cancelToken) NOTHROWS
    {
        TessellateCallback &cb = value;
        struct TriangleTessellator : public TessellateCallback
        {
            TriangleTessellator(TessellateCallback &v, const double t, Algorithm &a) : value(v), threshold(t), algorithm(a) {}
        public :
            TAKErr point(const Point2<double> &xyz) NOTHROWS override
            {
                return point(xyz, false);
            }
            TAKErr point(const Point2<double> &xyz, const bool exteriorVertex) NOTHROWS override
            {
                TAKErr code(TE_Ok);
                triangle.push_back(xyz);
                if(triangle.size() == 3u) {
                    code = triangle_r(
                            value,
                            triangle[0u], triangle[1u], triangle[2u],
                            algorithm.distance(triangle[0u], triangle[1u]),
                            algorithm.distance(triangle[1u], triangle[2u]),
                            algorithm.distance(triangle[2u], triangle[0u]),
                            threshold,
                            algorithm,
                            0u);
                    triangle.clear();
                }
                return code;
            }
        private :
            TessellateCallback &value;
            std::vector<Point2<double>> triangle;
            double threshold;
            Algorithm algorithm;
        } tcb(value, threshold, algorithm);
        if(threshold)
            cb = tcb;

        // Run tessellation
        // Returns array of indices that refer to the vertices of the input polygon.
        // e.g: the index 6 would refer to {25, 75} in this example.
        // Three subsequent indices form a triangle. Output triangles are clockwise.
        const auto indices = mapbox::earcut<uint32_t>(polygon);
        const auto numIndices = indices.size();
        const auto numRings = polygon.size();
        for(std::size_t i = 0u; i < numIndices; i++) {
            if(cancelToken && *cancelToken) return TE_Interrupted;
            auto pointIdx = indices[i];
            for(std::size_t j = 0u; j < numRings; j++) {
                if(pointIdx < polygon[j].size()) {
                    cb.point(polygon[j][pointIdx]);
                    break;
                }
                pointIdx -= (unsigned)polygon[j].size();
            }
        }
        return TE_Ok;
    }
}

TAKErr TAK::Engine::Renderer::VertexData_allocate(VertexDataPtr &value, const std::size_t stride, const std::size_t size, const std::size_t count) NOTHROWS
{
    value = VertexDataPtr(new VertexData(), VertexData_deleter);
    value->data = new uint8_t[stride*count];
    value->stride = stride;
    value->size = size;
    return TE_Ok;
}

Algorithm &TAK::Engine::Renderer::Tessellate_CartesianAlgorithm() NOTHROWS
{
    static Algorithm a = cartesian();
    return a;
}
Algorithm &TAK::Engine::Renderer::Tessellate_WGS84Algorithm() NOTHROWS
{
    static Algorithm a = wgs84();
    return a;
}

TessellateCallback::~TessellateCallback() NOTHROWS
{}

TAKErr TAK::Engine::Renderer::Tessellate_polygon(VertexDataPtr &value, std::size_t *dstCount, const VertexData &src, const std::size_t count, const double threshold, Algorithm &algorithm, ReadVertexFn vertRead, WriteVertexFn vertWrite, const bool *cancelToken) NOTHROWS
{
    int startIndices[] = {0};
    int counts[] = {(int)count};
    return Tessellate_polygon(value, dstCount, src, counts, startIndices, 1, threshold, algorithm, vertRead, vertWrite, cancelToken);
}
TAKErr TAK::Engine::Renderer::Tessellate_polygon(TessellateCallback &value, const VertexData &src, const std::size_t count, const double threshold, Algorithm &algorithm, ReadVertexFn vertRead, const bool *cancelToken) NOTHROWS
{
    int startIndices[] = {0};
    int counts[] = {(int)count};
    return Tessellate_polygon(value, src, counts, startIndices, 1, threshold, algorithm, vertRead, cancelToken);
}
TAKErr TAK::Engine::Renderer::Tessellate_polygon(VertexDataPtr &value, std::size_t *dstCount, const VertexData &src, const int *counts, const int *startIndices, const int numPolygons, const double threshold, Algorithm &algorithm, ReadVertexFn vertRead, WriteVertexFn vertWrite, const bool *cancelToken) NOTHROWS
{
    TAKErr code(TE_Ok);
    if(!dstCount)
        return TE_InvalidArg;


    struct Count : public TessellateCallback
    {
        TAKErr point(const Point2<double>& p) NOTHROWS override
        {
            n++;
            return TE_Ok;
        }
        std::size_t n{ 0u };
    } count;

    code = Tessellate_polygon(count, src, counts, startIndices, numPolygons, threshold, algorithm, vertRead, cancelToken);
    TE_CHECKRETURN_CODE(code);

    code = VertexData_allocate(value, src.stride, src.size, count.n);
    TE_CHECKRETURN_CODE(code);

    struct Assemble : public TessellateCallback
    {
        TAKErr point(const Point2<double>& p) NOTHROWS override
        {
            return writeV(*buf, layout, p);
        }
        WriteVertexFn writeV{ nullptr };
        VertexData layout;
        MemBuffer2* buf{ nullptr };
    } assemble;

    MemBuffer2 dstbuf((uint8_t*)value->data, (count.n* value->stride));
    assemble.writeV = vertWrite;
    assemble.layout = src;
    assemble.buf = &dstbuf;

    code = Tessellate_polygon(assemble, src, counts, startIndices, numPolygons, threshold, algorithm, vertRead, cancelToken);
    TE_CHECKRETURN_CODE(code);

    return code;

}
TAKErr TAK::Engine::Renderer::Tessellate_polygon(TessellateCallback &value, const VertexData& src, const int* counts, const int* startIndices, const int numPolygons, const double threshold, Algorithm& algorithm, ReadVertexFn vertRead, const bool *cancelToken) NOTHROWS
{
    TAKErr code(TE_Ok);

    if(!src.data)
        return TE_InvalidArg;
    if (src.size != 2u && src.size != 3u)
        return TE_InvalidArg;
    if (counts == nullptr || startIndices == nullptr)
        return TE_InvalidArg;
    if (!vertRead)
        return TE_InvalidArg;

    if (numPolygons < 1)
        return TE_Ok; // nothing to do

// Fill polygon structure with actual data. Any winding order works.
// The first polyline defines the main polygon.
// Following polylines define holes.
    Polygon_ polygon;
    polygon.readVert = vertRead;
    polygon.rings.count = (std::size_t)numPolygons;
    polygon.rings.data = &src;
    polygon.rings.startIndex = startIndices;
    polygon.rings.vertexCount = counts;

    return ::polygon(value, polygon, threshold, algorithm, cancelToken);
}

TAKErr TAK::Engine::Renderer::Tessellate_polygon(TessellateCallback &value, const VertexData *polygons, const int *counts, const int numPolygons, const size_t totalVertexCount, const double threshold, Algorithm &algorithm, ReadVertexFn vertRead, const bool *cancelToken)
{
    TAKErr code(TE_Ok);

    if (!polygons)
        return TE_InvalidArg;
    if (!counts)
        return TE_InvalidArg;
    if (!vertRead)
        return TE_InvalidArg;

    if (numPolygons < 1)
        return TE_Ok; // nothing to do

    // Fill polygon structure with actual data. Any winding order works.
    // The first polyline defines the main polygon.
    // Following polylines define holes.
    Polygon_ polygon;
    polygon.readVert = vertRead;
    polygon.rings.count = (std::size_t)numPolygons;
    polygon.rings.data = polygons;
    polygon.rings.vertexCount = counts;

    return ::polygon(value, polygon, threshold, algorithm, cancelToken);
}

namespace
{
    void VertexData_deleter(const VertexData *value)
    {
        if(value) {
            const auto *data = static_cast<const uint8_t *>(value->data);
            delete [] data;
            delete value;
        }
    }

    Algorithm wgs84() NOTHROWS
    {
        Algorithm geo;
        geo.distance = WGS84_distance;
        geo.direction = WGS84_direction;
        geo.interpolate = WGS84_interpolate;
		geo.intersect = WGS84_intersect;
        return geo;
    }
    double WGS84_distance(const Point2<double> &a, const Point2<double> &b)
    {
        return GeoPoint2_distance(GeoPoint2(a.y, a.x), GeoPoint2(b.y, b.x), true);
    }
    Point2<double> WGS84_direction(const Point2<double> &a, const Point2<double> &b)
    {
		const double bearing = GeoPoint2_bearing(GeoPoint2(a.y, a.x), GeoPoint2(b.y, b.x), true) * M_PI / 180.0;
		Point2<double> result(sin(bearing), cos(bearing), 0.);
        if(a.z != b.z) {
            // doing a cartesian slant angle for purposes of preserving relative height over ellipsoid surface rather than doing a slant line
            const double dz = b.z-a.z;
            const double distance = GeoPoint2_distance(GeoPoint2(a.y, a.x), GeoPoint2(b.y, b.x), true);
            result.z = dz / distance;
        }
        return result;
    }
    Point2<double> WGS84_interpolate(const Point2<double> &origin, const Point2<double> &dir, const double distance)
    {
		const double bearing = atan2(dir.x, dir.y) * 180.0 / M_PI;
        GeoPoint2 result = GeoPoint2_pointAtDistance(GeoPoint2(origin.y, origin.x), bearing, distance, true);
        result.altitude = origin.z + (dir.z*distance);
        return Point2<double>(result.longitude, result.latitude, result.altitude);
    }

	TAKErr WGS84_intersect(Point2<double> &intersect, const Point2<double> &origin1, const Point2<double> &dir1, const Point2<double> &origin2, const Point2<double> &dir2)
	{
		// https://www.movable-type.co.uk/scripts/latlong.html
		// see https://www.edwilliams.org/avform.htm#Intersection

		static const double deg2rad = M_PI / 180.0;
		static const double rad2deg = 180.0 / M_PI;
		static const double EPSILON = 1e-9;

		const double phi1 = origin1.y * deg2rad;
		const double lambda1 = origin1.x * deg2rad;
		const double phi2 = origin2.y * deg2rad;
		const double lambda2 = origin2.x * deg2rad;
		//const double theta13 = dir1.x * deg2rad; // note, only using bearing
		//const double theta23 = dir2.x * deg2rad; // note, only using bearing
		const double theta13 = atan2(dir1.x, dir1.y); // note, only using bearing
		const double theta23 = atan2(dir2.x, dir2.y); // note, only using bearing
		const double delPhi = phi2 - phi1;
		const double delLambda = lambda2 - lambda1;
		const double sinHalfDelPhi = sin(delPhi / 2.);
		const double sinHalfDelLambda = sin(delLambda / 2.);

		// angular distance p1-p2
		const double gamma12 = 2. * asin(sqrt(sinHalfDelPhi * sinHalfDelPhi
			+ cos(phi1) * cos(phi2) * sinHalfDelLambda * sinHalfDelLambda));
		if (fabs(gamma12) < EPSILON) {
			// coincident points
			intersect.x = origin1.x;
			intersect.y = origin1.y;
			intersect.z = origin1.z;

			return TE_Ok;
		}

		// initial/final bearings between points
		const double cosThetaA = (sin(phi2) - sin(phi1)*cos(gamma12)) / (sin(gamma12)*cos(phi1));
		const double cosThetaB = (sin(phi1) - sin(phi2)*cos(gamma12)) / (sin(gamma12)*cos(phi2));
		const double thetaA = acos(std::min(std::max(cosThetaA, -1.), 1.)); // protect against rounding errors
		const double thetaB = acos(std::min(std::max(cosThetaB, -1.), 1.)); // protect against rounding errors

		const double theta12 = sin(delLambda) > 0 ? thetaA : 2. * M_PI - thetaA;
		const double theta21 = sin(delLambda) > 0 ? 2. * M_PI - thetaB : thetaB;

		const double alpha1 = theta13 - theta12; // angle 2-1-3
		const double alpha2 = theta21 - theta23; // angle 1-2-3

		if (sin(alpha1) == 0 && sin(alpha2) == 0) return TE_IllegalState; // infinite intersections
		if (sin(alpha1) * sin(alpha2) < 0) return TE_IllegalState;        // ambiguous intersection (antipodal?)

		const double cosAlpha3 = -cos(alpha1)*cos(alpha2) + sin(alpha1)*sin(alpha2)*cos(gamma12);

		const double gamma13 = atan2(sin(gamma12)*sin(alpha1)*sin(alpha2), cos(alpha2) + cos(alpha1)*cosAlpha3);

		const double phi3 = asin(std::min(std::max(sin(phi1)*cos(gamma13) + cos(phi1)*sin(gamma13)*cos(theta13), -1.), 1.));

		const double delLambda13 = atan2(sin(theta13)*sin(gamma13)*cos(phi1), cos(gamma13) - sin(phi1)*sin(phi3));
		const double lambda3 = lambda1 + delLambda13;

		intersect.x = lambda3 * rad2deg;
		intersect.y = phi3 * rad2deg;
		intersect.z = std::max(origin1.z, origin2.z);
		return TE_Ok;
	}

    Algorithm cartesian() NOTHROWS
    {
        Algorithm xyz;
        xyz.distance = Cartesian_distance;
        xyz.direction = Cartesian_direction;
        xyz.interpolate = Cartesian_interpolate;
		xyz.intersect = Cartesian_intersect;
        return xyz;
    }
    double Cartesian_distance(const Point2<double> &a, const Point2<double> &b)
    {
        const double dx = b.x-a.x;
        const double dy = b.y-a.y;
        const double dz = b.z-a.z;
        return ::sqrt(dx*dx + dy*dy + dz*dz);
    }
    Point2<double> Cartesian_direction(const Point2<double> &a, const Point2<double> &b)
    {
        const double dx = b.x-a.x;
        const double dy = b.y-a.y;
        const double dz = b.z-a.z;
        const double length = ::sqrt(dx*dx + dy*dy + dz*dz);
        return Point2<double>(dx/length, dy/length, dz/length);
    }
    Point2<double> Cartesian_interpolate(const Point2<double> &origin, const Point2<double> &dir, const double distance)
    {
        return Point2<double>(origin.x + (dir.x*distance),
                              origin.y + (dir.y*distance),
                              origin.z + (dir.z*distance));
    }

	TAKErr Cartesian_intersect(Point2<double> &intersect, const Point2<double> &origin1, const Point2<double> &dir1, const Point2<double> &origin2, const Point2<double> &dir2)
	{
		Point2<double> del, crossTwoDel, crossTwoOne, offsetOne, result;
		double dotCross(0), crossTwoDelMag(0), crossTwoOneMag(0);
		Vector2_subtract(&del, origin2, origin1);
		Vector2_cross(&crossTwoDel, dir2, del);
		Vector2_cross(&crossTwoOne, dir2, dir1);
		Vector2_dot(&dotCross, crossTwoDel, crossTwoOne);
		const double sign = dotCross < 0 ? -1 : 1;
		Vector2_length(&crossTwoDelMag, crossTwoDel);
		Vector2_length(&crossTwoOneMag, crossTwoOne);
		Vector2_multiply(&offsetOne, dir1, sign * crossTwoDelMag / crossTwoOneMag);
		Vector2_add(&intersect, origin1, offsetOne);
		return TE_Ok;
	}

    Point2<double> midpoint(const Point2<double> &a, const Point2<double> &b, Algorithm alg) NOTHROWS
    {
        const double dist = alg.distance(a, b);
        const Point2<double> dir = alg.direction(a, b);
        return alg.interpolate(a, dir, dist / 2.0);
    }

    TAKErr triangle_r(TessellateCallback &sink, const Point2<double>& a, const Point2<double>& b, const Point2<double>& c, const double dab, const double dbc, const double dca, const double threshold, Algorithm alg, std::size_t depth) NOTHROWS
    {
        TAKErr code(TE_Ok);

        const bool reprocess = ((dab/threshold) > 2.0 || (dbc/threshold) > 2.0 || (dca/threshold) > 2.0);

        const std::size_t subAB = dab > threshold ? 1u : 0u;
        const std::size_t subBC = dbc > threshold ? 1u : 0u;
        const std::size_t subCA = dca > threshold ? 1u : 0u;

        const std::size_t subs = subAB+subBC+subCA;

        // XXX - winding order!!!

#define __te_emit_or_recurse(sa, sb, sc, dsab, dsbc, dsca) \
    if(reprocess && ((dsab) > threshold || (dsbc) > threshold || (dsca) > threshold))  {\
        code = triangle_r(sink, sa, sb, sc, dsab, dsbc, dsca, threshold, alg, depth+1); \
        TE_CHECKRETURN_CODE(code); \
    } else { \
        code = sink.point(sa); \
        TE_CHECKRETURN_CODE(code); \
        code = sink.point(sb); \
        TE_CHECKRETURN_CODE(code); \
        code = sink.point(sc); \
        TE_CHECKRETURN_CODE(code); \
    }

        // no tessellation
        if(subs == 0) {
            code = sink.point(a);
            TE_CHECKRETURN_CODE(code);
            code = sink.point(b);
            TE_CHECKRETURN_CODE(code);
            code = sink.point(c);
            TE_CHECKRETURN_CODE(code);
            return code;
        } else if(subs == 3u) {
            // full tessellation
            const double hdab = dab / 2.0;
            const double hdbc = dbc / 2.0;
            const double hdca = dca / 2.0;

            const Point2<double> d = midpoint2(a, alg.direction(a, b), hdab, alg);
            const Point2<double> e = midpoint2(b, alg.direction(b, c), hdbc, alg);
            const Point2<double> f = midpoint2(c, alg.direction(c, a), hdca, alg);

            const double ddf = alg.distance(d, f);
            __te_emit_or_recurse(a, d, f, hdab, ddf, hdca);
            const double ded = alg.distance(e, d);
            __te_emit_or_recurse(d, b, e, hdab, hdbc, alg.distance(e, d));
            const double def = alg.distance(e, f);
            __te_emit_or_recurse(d, e, f, ded, def, ddf);
            __te_emit_or_recurse(f, e, c, def, hdbc, hdca);
        } else if(subs == 2u) {
            if(!subBC) {
                const double hdab = dab / 2.0;
                const double hdca = dca / 2.0;

                const Point2<double> d = midpoint2(a, alg.direction(a, b), hdab, alg);
                const Point2<double> f = midpoint2(c, alg.direction(c, a), hdca, alg);

                const double ddf = alg.distance(d, f);
                const double dbf = alg.distance(b, f);

                __te_emit_or_recurse(a, d, f, hdab, ddf, hdca);
                __te_emit_or_recurse(f, d, b, ddf, hdab, dbf);
                __te_emit_or_recurse(f, b, c, dbf, dbc,hdca);
            } else if(!subCA) {
                const double hdab = dab / 2.0;
                const double hdbc = dbc / 2.0;

                const Point2<double> d = midpoint2(a, alg.direction(a, b), hdab, alg);
                const Point2<double> e = midpoint2(b, alg.direction(b, c), hdbc, alg);

                const double ded = alg.distance(e, d);
                const double dea = alg.distance(e, a);

                __te_emit_or_recurse(a, d, e, hdab, ded, dea);
                __te_emit_or_recurse(d, b, e, hdab, hdbc, ded);
                __te_emit_or_recurse(a, e, c, dea, hdbc, dca);
            } else if(!subAB) {
                const double hdbc = dbc / 2.0;
                const double hdca = dca / 2.0;

                const Point2<double> e = midpoint2(b, alg.direction(b, c), hdbc, alg);
                const Point2<double> f = midpoint2(c, alg.direction(c, a), hdca, alg);

                const double def = alg.distance(e, f);
                const double dea = alg.distance(e, a);

                __te_emit_or_recurse(c, e, f, hdbc, def, hdca);
                __te_emit_or_recurse(f, e, a, def, dea, hdca);
                __te_emit_or_recurse(e, a, b, dea, dab, hdbc);
            } else {
                return TE_IllegalState;
            }
        } else if(subs == 1u) {
            if(subAB) {
                const double hdab = dab / 2.0;

                const Point2<double> d = midpoint2(a, alg.direction(a, b), hdab, alg);

                const double ddc = alg.distance(d, c);

                __te_emit_or_recurse(a, d, c, hdab, ddc, dca);
                __te_emit_or_recurse(c, b, d, dbc, hdab, ddc);
            } else if(subBC) {
                const double hdbc = dbc / 2.0;

                const Point2<double> e = midpoint2(b, alg.direction(b, c), hdbc, alg);

                const double dea = alg.distance(e, a);

                __te_emit_or_recurse(b, e, a, hdbc, dea, dab);
                __te_emit_or_recurse(a, e, c, dea, hdbc, dca);
            } else if(subCA) {
                const double hdca = dca / 2.0;

                const Point2<double> f = midpoint2(c, alg.direction(c, a), hdca, alg);

                const double dbf = alg.distance(b, f);

                __te_emit_or_recurse(a, b, f, dab, dbf, hdca);
                __te_emit_or_recurse(f, b, c, dbf, dbc, hdca);
            } else {
                return TE_IllegalState;
            }
        } else {
            return TE_IllegalState;
        }

        return code;
    }
}
