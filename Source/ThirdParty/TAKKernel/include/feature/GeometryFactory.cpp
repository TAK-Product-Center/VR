#include "feature/GeometryFactory.h"

#include <cstdlib>
#include <sstream>

#include "feature/LegacyAdapters.h"
#include "feature/ParseGeometry.h"
#include "feature/GeometryCollection2.h"
#include "feature/LineString2.h"
#include "feature/Point2.h"
#include "feature/Polygon2.h"
#include "feature/Style.h"
#include "math/Vector4.h"
#include "port/STLVectorAdapter.h"
#include "util/DataInput2.h"
#include "util/DataOutput2.h"
#include "util/Memory.h"

using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Port;
using namespace TAK::Engine::Util;

namespace
{
    	// allow for nesting of GeometryCollection > Polygon > LineString > Point without vector
	constexpr std::size_t geometryBuilderArrayCountLimit = 4u;

    struct GeometryStackElement
    {
        GeometryClass gc;
        std::size_t encounteredRings{ 0u };
        Geometry2Ptr value{ nullptr, nullptr };
    };
    struct GeometryBuilder
    {
        struct {
			GeometryStackElement s[geometryBuilderArrayCountLimit];
			std::vector<GeometryStackElement> v;
			GeometryStackElement* value{ &s[0u] };
			std::size_t count{ 0u };

			void push(GeometryStackElement &&el) NOTHROWS
			{
				do {
					if (value != v.data() && count < geometryBuilderArrayCountLimit) {
						s[count] = std::move(el);
						break;
					} else if (value != v.data()) {
						// transfer contents
						for(std::size_t i = 0u; i < geometryBuilderArrayCountLimit; i++) {
							GeometryStackElement sel;
							sel.gc = s[i].gc;
							sel.value = std::move(s[i].value);
							v.push_back(std::move(sel));

						}
					}
					v.push_back(std::move(el));
					value = v.data();
				} while (false);
				count++;
			}
			void pop() NOTHROWS
			{
				if(count > 0u) {
                    if(v.data() == value)
                        v.pop_back();
					count--;
				}
			}
			GeometryStackElement &peek() NOTHROWS
			{
				return value[count-1u];
			}
			bool empty() const NOTHROWS
			{
				return !count;
			}
			std::size_t size() const NOTHROWS
			{
				return count;
			}
		} stack;

        TAKErr push(Geometry2Ptr &&geom) NOTHROWS
        {
            TAKErr code(TE_Ok);
            if(!stack.empty()) {
                // the stack is not empty, we should only be pushing geometry objects onto it if we have a
                // polygon (rings) or a geometry collection (child geometries)
                auto &peek = stack.peek();
                switch(peek.gc) {
                    case TEGC_Polygon :
                    {
                        if (geom->getClass() != TEGC_LineString)
                            return TE_InvalidArg;
                        auto& p = static_cast<Polygon2&>(*peek.value);
                        if(peek.encounteredRings) {
                            // add interior ring
                            code = p.addInteriorRing(static_cast<const LineString2&>(*geom));
                            TE_CHECKBREAK_CODE(code);
                            std::shared_ptr<LineString2> added;
                            code = p.getInteriorRing(added, p.getNumInteriorRings() - 1u);
                            TE_CHECKBREAK_CODE(code);
                            geom = Geometry2Ptr(added.get(), Memory_leaker_const<Geometry2>);
                        } else {
                            // get exterior ring
                            std::shared_ptr<LineString2> exterior;
                            code = p.getExteriorRing(exterior);
                            TE_CHECKBREAK_CODE(code);
                            // sync content
                            const auto &ls = static_cast<const LineString2&>(*geom);
                            const std::size_t dim = ls.getDimension();
                            exterior->setDimension(dim);
                            for(std::size_t i = 0; i < ls.getNumPoints(); i++) {
                                Point2 xyz(0.0, 0.0, 0.0);
                                ls.get(&xyz, i);
                                if(dim == 2u)
                                    exterior->addPoint(xyz.x, xyz.y);
                                else if(dim == 3u)
                                    exterior->addPoint(xyz.x, xyz.y, xyz.z);
                            }
                            geom = Geometry2Ptr(exterior.get(), Memory_leaker_const<Geometry2>);
                        }
                        peek.encounteredRings++;
                        break;
                    }
                    case TEGC_GeometryCollection :
                    {
                        auto& c = static_cast<GeometryCollection2&>(*peek.value);
                        code = c.addGeometry(std::move(geom));
                        TE_CHECKBREAK_CODE(code);
                        std::shared_ptr<Geometry2> added;
                        code = c.getGeometry(added, c.getNumGeometries() - 1u);
                        TE_CHECKBREAK_CODE(code);
                        geom = Geometry2Ptr(added.get(), Memory_leaker_const<Geometry2>);
                        break;
                    }
                    default :
                        return TE_InvalidArg;
                }
                TE_CHECKRETURN_CODE(code);
            }

            GeometryStackElement el;
            el.gc = geom->getClass();
            el.value = std::move(geom);
            stack.push(std::move(el));
            return code;
        }

        TAKErr operator()(const GeometryParseCommand cmd, const GeometryClass gc, const std::size_t dim, const std::size_t count, const TAK::Engine::Feature::Point2 &p)
        {
            switch(cmd) {
                // starting a new geometry
                case TEGF_StartGeometry :
                {
                    Geometry2Ptr geom(nullptr, nullptr);
                    switch (gc) {
                    case TEGC_Point:
                    {
                        if (!stack.empty()) {
                            const auto& peek = stack.peek();
                            // if linestring or point, nothing to do when a new point starts
                            if (peek.gc == TEGC_LineString || peek.gc == TEGC_Point)
                                return TE_Ok;
                        }
                        geom = Geometry2Ptr(new Point2(p), Memory_deleter_const<Geometry2, Point2>);
                        break;
                    }
                    case TEGC_LineString:
                        geom = Geometry2Ptr(new LineString2(), Memory_deleter_const<Geometry2, LineString2>);
                        break;
                    case TEGC_Polygon:
                        geom = Geometry2Ptr(new Polygon2(), Memory_deleter_const<Geometry2, Polygon2>);
                        break;
                    case TEGC_GeometryCollection:
                        geom = Geometry2Ptr(new GeometryCollection2(), Memory_deleter_const<Geometry2, GeometryCollection2>);
                        break;
                    default:
                        return TE_Err;
                    }

                    if (geom) {
                        geom->setDimension(dim);
                        push(std::move(geom));
                    }
                    break;
                }
                // adding point to current geometry
                case TEGF_Point :
                {
                    if (stack.empty())
                        return TE_IllegalState;
                    // expect that the top of the stack is either a point or a linestring
                    auto& peek = stack.peek();
                    switch(peek.gc)
                    {
                        case TEGC_LineString :
                            if (p.getDimension() == 2u)
                                static_cast<LineString2&>(*peek.value).addPoint(p.x, p.y);
                            else if (p.getDimension() == 3u)
                                static_cast<LineString2&>(*peek.value).addPoint(p.x, p.y, p.z);
                            else
                                return TE_IllegalState;
                            break;
                        case TEGC_Point :
                            static_cast<Point2&>(*peek.value) = p;
                            break;
                        default :
                            return TE_IllegalState;
                    }
                    break;
                }
                // ending current geometry
                case TEGF_EndGeometry :
                {
                    if (stack.size() > 1u)
                        stack.pop();
                    break;
                }
            }
            return TE_Ok;
        }

        TAKErr build(Geometry2Ptr_const &value) NOTHROWS
        {
            if (stack.size() != 1u)
                return TE_IllegalState;
            value = std::move(stack.peek().value);
            stack.pop();
            return TE_Ok;
        }
        TAKErr build(Geometry2Ptr &value) NOTHROWS
        {
            if (stack.size() != 1u)
                return TE_IllegalState;
            value = std::move(stack.peek().value);
            stack.pop();
            return TE_Ok;
        }
    };

    TAKErr parseSpatiaLiteGeometry(DataInput2 &strm,
                                   const size_t dimension,
                                   const int typeRestriction,
                                   const bool hasMeasure,
                                   const bool isCompressed,
                                   const GeometryParseCallback &cb) NOTHROWS;
    TAKErr parseSpatiaLiteLineString(DataInput2 &strm,
                                     const std::size_t dimension,
                                     const bool hasMeasure,
                                     const bool isCompressed,
                                    const GeometryParseCallback &cb) NOTHROWS;
    TAKErr parseSpatiaLitePolygon(DataInput2 &strm,
                                  const std::size_t dim,
                                  const bool hasMeasure,
                                  const bool isCompressed,
                                  const GeometryParseCallback &cb) NOTHROWS;
    TAKErr parseWKB_LineString(DataInput2 &strm,
                               const std::size_t dim,
                               const bool hasMeasure,
                               const GeometryParseCallback &cb) NOTHROWS;
    TAKErr parseWKB_Point(DataInput2 &strm,
                          const std::size_t dim,
                          const bool hasMeasure,
                          const bool raiseStartEndGeom,
                          const GeometryParseCallback &cb) NOTHROWS;

    TAKErr parseWKB_Polygon(DataInput2 &strm,
                            const std::size_t dim,
                            const bool hasMeasure,
                            const GeometryParseCallback &cb) NOTHROWS;

    TAKErr packWKB_writeHeader(DataOutput2 &strm,
                               const TAKEndian order,
                               const Geometry2 &geom,
                               const uint32_t baseType) NOTHROWS;
    TAKErr packWKB_Point(DataOutput2 &strm,
                         const TAKEndian order,
                         const Point2 &point) NOTHROWS;
    TAKErr packWKB_LineString(DataOutput2 &strm,
                              const TAKEndian order,
                              const LineString2 &linestring) NOTHROWS;
    TAKErr packWKB_writePoints(DataOutput2 &strm,
                               const LineString2 &linestring) NOTHROWS;
    TAKErr packWKB_Polygon(DataOutput2 &strm,
                           const TAKEndian order,
                           const Polygon2 &polygon) NOTHROWS;
    TAKErr packWKB_GeometryCollection(DataOutput2 &strm,
                                      const TAKEndian order,
                                      const GeometryCollection2 &c) NOTHROWS;

    /*************************************************************************/
    // Extrude Specitication
    /*
     * struct
     * {
     *     // returns `true` if all vertices can be extruded, `false` otherwise
     *     bool operator()(const Geometry2 &src) const;
     *     // returns the extrude height for the given vertex
     *     double operator[](const std::size_t) const;
     * };
     */
    /*************************************************************************/

    struct ExtrudeConstant
    {
        ExtrudeConstant(const double v) NOTHROWS :
            value(v)
        {}
        bool operator()(const Geometry2 &src) const NOTHROWS
        {
            return true;
        }
        double operator[](const std::size_t idx) const NOTHROWS
        {
            return value;
        }

        double value;
    };
    struct ExtrudePerVertex
    {
        ExtrudePerVertex(const double *v, const std::size_t count_) NOTHROWS :
            value(v),
            count(count_)
        {}
        bool operator()(const Geometry2 &src) const NOTHROWS
        {
            switch(src.getClass()) {
                case TEGC_Point :
                    return !!count;
                case TEGC_LineString :
                    return (count >= static_cast<const LineString2 &>(src).getNumPoints());
                case TEGC_Polygon :
                {
                    std::shared_ptr<LineString2> ring;
                    if(static_cast<const Polygon2 &>(src).getExteriorRing(ring) != TE_Ok)
                        return false;
                    return (*this)(*ring);
                }
                default :
                    return false;
            }
        }
        double operator[](const std::size_t idx) const NOTHROWS
        {
            if(idx >= count)
                return NAN;
            return value[idx];
        }

        const double *value;
        const std::size_t count;
    };

    template<class T>
    TAKErr extrudeGeometry(Geometry2Ptr &value, const Geometry2 &src, const T &extrude, const int hints) NOTHROWS;

    template<class T>
    TAKErr extrudePointAsLine(Geometry2Ptr& value, const Point2& point, const T &extrude) NOTHROWS;
    template<class T>
    TAKErr extrudeLineAsPolygon(Geometry2Ptr& value, const LineString2& line, const T &extrude) NOTHROWS;
    template<class T>
    TAKErr extrudeLineAsCollection(Geometry2Ptr& value, const LineString2& line, const T &extrude, const int hints) NOTHROWS;
    template<class T>
    TAKErr extrudePolygonAsCollection(Geometry2Ptr& value, const Polygon2& polygon, const T &extrude, const int hints) NOTHROWS;

    int samplingFactor(const double &semiMajorAxis, const double &semiMinorAxis) NOTHROWS;
}

TAKErr TAK::Engine::Feature::GeometryFactory_fromWkb(Geometry2Ptr& value, DataInput2& src) NOTHROWS
{
    GeometryBuilder builder;
    auto buildercb = [&](const GeometryParseCommand cmd, const GeometryClass gc, const std::size_t dim, const std::size_t count, const TAK::Engine::Feature::Point2& p)
    {
        return builder(cmd, gc, dim, count, p);
    };

    TAKErr code(TE_Ok);
    code = GeometryFactory_fromWkb(src, buildercb);
    TE_CHECKRETURN_CODE(code);

    return builder.build(value);
}
TAKErr TAK::Engine::Feature::GeometryFactory_fromWkb(Geometry2Ptr &value, const uint8_t *wkb, const std::size_t wkbLen) NOTHROWS
{
    TAKErr code(TE_Ok);
    MemoryInput2 strm;
    code = strm.open(wkb, wkbLen);
    TE_CHECKRETURN_CODE(code);
    return GeometryFactory_fromWkb(value, strm);
}
TAKErr TAK::Engine::Feature::GeometryFactory_fromWkb(DataInput2 &src, const GeometryParseCallback &cb) NOTHROWS
{
    TAKErr code(TE_Ok);
    uint8_t byteOrder;
    code = src.readByte(&byteOrder);

    if (byteOrder > 1)
        return TE_InvalidArg;
    src.setSourceEndian2(byteOrder ? TE_LittleEndian : TE_BigEndian);

    int type;
    code = src.readInt(&type);
    TE_CHECKRETURN_CODE(code);

    std::size_t dim = ((unsigned)type / 1000u & 1u ? 3u : 2u);
    const bool hasMeasure (type / 2000 > 0);

    switch (type % 1000)
        {
        case 1:                           // Point
        code = parseWKB_Point(src, dim, hasMeasure, true, cb);
        break;

        case 2:                           // LineString
        case 13:                          // Curve
        code = parseWKB_LineString(src, dim, hasMeasure, cb);
        break;

        case 3:                           // Polygon
        case 14 :                         // Surface
        case 17:                          // Triangle
        code = parseWKB_Polygon(src, dim, hasMeasure, cb);
        break;

        case 4:                           // MultiPoint
        case 5:                           // MultiLineString
        case 11:                          // MultiCurve
        case 6:                           // MultiPolygon
        case 15:                          // PolyhedralSurface
        case 16:                          // TIN
        case 7:                           // GeometryCollection
        case 12:                         // MultiSurface
            {
            int count;
            code = src.readInt(&count);
            TE_CHECKRETURN_CODE(code);

            code = cb(TEGF_StartGeometry, TEGC_GeometryCollection, dim, (std::size_t)count, Point2(NAN, NAN));
            if (code != TE_Ok) return code;
            for (int i (0); i < count; ++i)
                {
                    code = GeometryFactory_fromWkb(src, cb);
                    if (code != TE_Ok) return code;
                }
            TE_CHECKRETURN_CODE(code);

            code = cb(TEGF_EndGeometry, TEGC_GeometryCollection, dim, (std::size_t)count, Point2(NAN, NAN));
            if (code != TE_Ok) return code;
            }
        break;

        default:
            {
            return TE_InvalidArg;
            }
        }

    return code;
}
TAKErr TAK::Engine::Feature::GeometryFactory_fromSpatiaLiteBlob(Geometry2Ptr &value, Util::DataInput2 &src) NOTHROWS
{
    return GeometryFactory_fromSpatiaLiteBlob(value, nullptr, src);
}
TAKErr TAK::Engine::Feature::GeometryFactory_fromSpatiaLiteBlob(Geometry2Ptr &value, const uint8_t *wkb, const std::size_t wkbLen) NOTHROWS
{
    return GeometryFactory_fromSpatiaLiteBlob(value, nullptr, wkb, wkbLen);
}
TAKErr TAK::Engine::Feature::GeometryFactory_fromSpatiaLiteBlob(DataInput2 &src, int *srid, const GeometryParseCallback &cb) NOTHROWS
{
    TAKErr code(TE_Ok);
    uint8_t octet;
    code = src.readByte(&octet);
    TE_CHECKRETURN_CODE(code);
    if ((octet & 0xFF) != 0x00)
        return TE_InvalidArg;

    uint8_t byteOrder;
    code = src.readByte(&byteOrder);
    TE_CHECKRETURN_CODE(code);
    if (byteOrder > 1u)
        return TE_InvalidArg;

    src.setSourceEndian2(byteOrder ? TE_LittleEndian : TE_BigEndian);
    if (srid) {
        code = src.readInt(srid);
        TE_CHECKRETURN_CODE(code);
    } else {
        code = src.skip(4u);
        TE_CHECKRETURN_CODE(code);
    }
    code = src.skip(32);
    TE_CHECKRETURN_CODE(code);

    code = src.readByte(&octet);
    TE_CHECKRETURN_CODE(code);
    if ((octet & 0xFF) != 0x7C)
        return TE_InvalidArg;

    int type;
    code = src.readInt(&type);
    TE_CHECKRETURN_CODE(code);

    if (type < 0)
        return TE_InvalidArg;

    const std::size_t dim = ((unsigned)type / 1000u & 1u ? 3u : 2u);
    const bool hasMeasure (type / 1000 % 1000 > 1);
    const bool isCompressed (type / 1000000 == 1);

    switch (type % 1000u)
      {
      case 1u:                           // Point (SpatiaLite is same as WKB)
        code = parseWKB_Point(src, dim, hasMeasure, true, cb);
        break;

      case 2u:                           // LineString
        code = parseSpatiaLiteLineString(src, dim, hasMeasure, isCompressed, cb);
        break;

      case 3u:                           // Polygon
        code = parseSpatiaLitePolygon(src, dim, hasMeasure, isCompressed, cb);
        break;

      case 4u:                           // MultiPoint
      case 5u:                           // MultiLineString
      case 6u:                           // MultiPolygon
          {
            int count;
            code = src.readInt(&count);
            TE_CHECKRETURN_CODE(code);
            if (count < 0)
                return TE_InvalidArg;
            code = cb(TEGF_StartGeometry, TEGC_GeometryCollection, dim, (std::size_t)count, Point2(NAN, NAN));
            if (code != TE_Ok) return code;

            for (int i (0); i < count; ++i)
              {
                code = parseSpatiaLiteGeometry(src, dim, (type % 1000) - 3, hasMeasure, isCompressed, cb);
                if (code != TE_Ok) return code;
              }
            TE_CHECKRETURN_CODE(code);

            code = cb(TEGF_EndGeometry, TEGC_GeometryCollection, dim, (std::size_t)count, Point2(NAN, NAN));
            if (code != TE_Ok) return code;
          }
        break;

      case 7u:                           // GeometryCollection
          {
            int count;
            code = src.readInt(&count);
            TE_CHECKRETURN_CODE(code);
            if (count < 0)
                return TE_InvalidArg;
            code = cb(TEGF_StartGeometry, TEGC_GeometryCollection, dim, (std::size_t)count, Point2(NAN, NAN));
            if (code != TE_Ok) return code;

            for (int i (0); i < count; ++i)
              {
                code = parseSpatiaLiteGeometry(src, dim, 0, hasMeasure, isCompressed, cb);
                if (code != TE_Ok) return code;
              }
            TE_CHECKRETURN_CODE(code);

            code = cb(TEGF_EndGeometry, TEGC_GeometryCollection, dim, (std::size_t)count, Point2(NAN, NAN));
            if (code != TE_Ok) return code;
          }
        break;

      default:
          {
            return TE_InvalidArg;
          }
      }

    return code;
}
TAKErr TAK::Engine::Feature::GeometryFactory_fromSpatiaLiteBlob(Geometry2Ptr &value, int *srid, Util::DataInput2 &src) NOTHROWS
{
    GeometryBuilder builder;
    auto buildercb = [&](const GeometryParseCommand cmd, const GeometryClass gc, const std::size_t dim, const std::size_t count, const TAK::Engine::Feature::Point2& p)
    {
        return builder(cmd, gc, dim, count, p);
    };

    TAKErr code = GeometryFactory_fromSpatiaLiteBlob(src, srid, buildercb);
    TE_CHECKRETURN_CODE(code);

    return builder.build(value);
}
TAKErr TAK::Engine::Feature::GeometryFactory_fromSpatiaLiteBlob(Geometry2Ptr &value, int *srid, const uint8_t *wkb, const std::size_t wkbLen) NOTHROWS
{
    TAKErr code(TE_Ok);
    MemoryInput2 strm;
    code = strm.open(wkb, wkbLen);
    TE_CHECKRETURN_CODE(code);
    return GeometryFactory_fromSpatiaLiteBlob(value, srid, strm);
}

TAKErr TAK::Engine::Feature::GeometryFactory_getWkbGeometryType(GeometryClass *type, std::size_t *dim, const uint8_t *srcData, const std::size_t srcDataLen) NOTHROWS
{
    MemoryInput2 src;
    src.open(srcData, srcDataLen);
    return GeometryFactory_getWkbGeometryType(type, dim, src);
}
TAKErr TAK::Engine::Feature::GeometryFactory_getWkbGeometryType(GeometryClass *rtype, std::size_t *rdim, DataInput2 &src)
    NOTHROWS
{
    TAKErr code(TE_Ok);
    bool visited = false;
    auto cb = [&](const GeometryParseCommand cmd, const GeometryClass geomClass, const std::size_t dim, const std::size_t, const Point2 &)
    {
        if (cmd != TEGF_StartGeometry)
            return TE_Ok;
        if(rtype)
            *rtype = geomClass;
        if(rdim)
            *rdim = dim;
        visited = true;
        return TE_Done;
    };
    code = GeometryFactory_fromWkb(src, cb);
    if (code == TE_Done)
        code = TE_Ok;
    TE_CHECKRETURN_CODE(code);
    return visited ? TE_Ok : TE_Err;
}
TAKErr TAK::Engine::Feature::GeometryFactory_getSpatiaLiteBlobGeometryType(GeometryClass *rtype, std::size_t *rdim, const uint8_t *srcData, const std::size_t srcDataLen) NOTHROWS
{
    TAKErr code(TE_Ok);
    if (srcDataLen < 43u)
        return TE_EOF;
    // start byte
    if (srcData[0] != 0x00)
        return TE_InvalidArg;
    // byte order, 0x0 or 0x1
    if (srcData[1u] > 1u)
        return TE_InvalidArg;
    // MBR end byte
    if (srcData[38] != 0x7C)
        return TE_InvalidArg;

    uint32_t type = *reinterpret_cast<const uint32_t*>(srcData + 39u);
    const auto byteOrder = srcData[1u] ? TE_LittleEndian : TE_BigEndian;
    if(byteOrder != TE_PlatformEndian) {
        // swap byte order
        type = (type >> 24u) | (((type >> 16u) & 0xFF) << 8u) | (((type >> 8u) & 0xFF) << 16u) | ((type & 0xFF) << 24u);
    }

    if(rdim) *rdim = ((unsigned)type / 1000u & 1u ? 3u : 2u);
    switch (type % 1000u)
      {
      case 1u:                           // Point (SpatiaLite is same as WKB)
          if (rtype) *rtype = TEGC_Point;
        break;
      case 2u:                           // LineString
        if (rtype) *rtype = TEGC_LineString;
        break;
      case 3u:                           // Polygon
        if (rtype) *rtype = TEGC_Polygon;
        break;
      case 4u:                           // MultiPoint
      case 5u:                           // MultiLineString
      case 6u:                           // MultiPolygon
      case 7u:                           // GeometryCollection
        if (rtype) *rtype = TEGC_GeometryCollection;
        break;
      default:
        return TE_InvalidArg;
      }

    return code;
}
TAKErr TAK::Engine::Feature::GeometryFactory_getSpatiaLiteBlobGeometryType(GeometryClass *rtype, std::size_t *rdim, DataInput2 &src)
    NOTHROWS
{
    TAKErr code(TE_Ok);
    uint8_t header[43u];
    std::size_t nread;
    code = src.read(header, &nread, 43u);
    TE_CHECKRETURN_CODE(code);
    
    return GeometryFactory_getSpatiaLiteBlobGeometryType(rtype, rdim, header, nread);
}

TAKErr TAK::Engine::Feature::GeometryFactory_toWkb(DataOutput2 &sink, const Geometry2 &geometry) NOTHROWS
{
    return GeometryFactory_toWkb(sink, geometry, TE_PlatformEndian);
}

TAKErr TAK::Engine::Feature::GeometryFactory_toWkb(DataOutput2 &sink, const Geometry2 &geometry, const TAKEndian endian) NOTHROWS
{
    // set the endian
    sink.setSourceEndian2(endian);

    switch(geometry.getClass()) {
        case TEGC_Point :
            return packWKB_Point(sink, endian, static_cast<const Point2 &>(geometry));
        case TEGC_LineString :
            return packWKB_LineString(sink, endian, static_cast<const LineString2 &>(geometry));
        case TEGC_Polygon :
            return packWKB_Polygon(sink, endian, static_cast<const Polygon2 &>(geometry));
        case TEGC_GeometryCollection :
            return packWKB_GeometryCollection(sink, endian, static_cast<const GeometryCollection2 &>(geometry));
        default :
            return TE_IllegalState;
    }
}

TAKErr TAK::Engine::Feature::GeometryFactory_toSpatiaLiteBlob(DataOutput2 &sink, const Geometry2 &geometry, const int srid) NOTHROWS
{
    return GeometryFactory_toSpatiaLiteBlob(sink, geometry, srid, TE_PlatformEndian);
}

TAKErr TAK::Engine::Feature::GeometryFactory_toSpatiaLiteBlob(DataOutput2 &sink, const Geometry2 &geometry, const int srid, const TAKEndian endian) NOTHROWS
{
    if (srid == 4326 && endian == TE_PlatformEndian) {
        TAKErr code(TE_Ok);
        atakmap::feature::UniqueGeometryPtr legacy(nullptr, nullptr);
        code = LegacyAdapters_adapt(legacy, geometry);
        TE_CHECKRETURN_CODE(code);

        try {
            std::ostringstream strstream;
            legacy->toBlob(strstream);
            std::string s = strstream.str();
            for (std::size_t i = 0u; i < s.length(); ++i) {
                code = sink.writeByte(s[i]);
                TE_CHECKBREAK_CODE(code);
            }
            TE_CHECKRETURN_CODE(code);
        } catch (...) {
            return TE_Err;
        }

        return code;
    } else {
        return TE_NotImplemented;
    }
}

TAKErr TAK::Engine::Feature::GeometryFactory_extrude(Geometry2Ptr &value, const Geometry2 &src, const double height, const int hints) NOTHROWS
{
    ExtrudeConstant impl(height);
    return extrudeGeometry(value, src, impl, hints);
}
TAKErr TAK::Engine::Feature::GeometryFactory_extrude(Geometry2Ptr &value, const Geometry2 &src, const double *vertexHeights, const std::size_t count, const int hints) NOTHROWS
{
    if(!vertexHeights)
        return TE_InvalidArg;
    ExtrudePerVertex impl(vertexHeights, count);
    return extrudeGeometry(value, src, impl, hints);
}

TAKErr TAK::Engine::Feature::GeometryFactory_createRectangle(Geometry2Ptr& value, const Math::Point2<double>& corner1, const Math::Point2<double>& corner2, const Renderer::Algorithm& algo) NOTHROWS
{
    TAKErr code(TE_Ok);
    const double xMin = std::min(corner1.x, corner2.x);
    const double xMax = std::max(corner1.x, corner2.x);
    const double yMin = std::min(corner1.y, corner2.y);
    const double yMax = std::max(corner1.y, corner2.y);
    const double zMax = std::max(corner1.z, corner2.z);

    if (xMax == xMin)
        return TE_InvalidArg;

    if (yMax == yMin)
        return TE_InvalidArg;

    // closed line string created in CCW order
    LineString2 ring;
    code = ring.setDimension(3);
    TE_CHECKRETURN_CODE(code);
    code = ring.addPoint(xMin, yMin, zMax);
    TE_CHECKRETURN_CODE(code);
    code = ring.addPoint(xMax, yMin, zMax);
    TE_CHECKRETURN_CODE(code);
    code = ring.addPoint(xMax, yMax, zMax);
    TE_CHECKRETURN_CODE(code);
    code = ring.addPoint(xMin, yMax, zMax);
    TE_CHECKRETURN_CODE(code);
    code = ring.addPoint(xMin, yMin, zMax);
    TE_CHECKRETURN_CODE(code);

    value = Geometry2Ptr(new Polygon2(ring), Memory_deleter_const<Geometry2, Polygon2>);
    return code;
}

TAKErr TAK::Engine::Feature::GeometryFactory_createRectangle(Geometry2Ptr& value, const Math::Point2<double>& corner1, const Math::Point2<double>& corner2, const Math::Point2<double>& point3, const Renderer::Algorithm& algo) NOTHROWS
{
    TAKErr code(TE_Ok);

    typedef Math::Point2<double> point2d;

    // Calcuate the distance from the third point to the arc / line between C1 and C2
    // Change the problem to 2D solution of Side, Side, Side triangle
    // using the Law of Cosigns.
    const double distanceC1C2 = algo.distance(corner1, corner2);
    const double distanceC1P3 = algo.distance(corner1, point3);
    const double distanceC2P3 = algo.distance(corner2, point3);
    const double cosAngleP3C1C2 =
        (distanceC1C2 * distanceC1C2 +
            distanceC1P3 * distanceC1P3 -
            distanceC2P3 * distanceC2P3) /
            (2 * distanceC1C2 * distanceC1P3);
    const double projectedDistanceC1 = distanceC1P3 * cosAngleP3C1C2;
    const double distanceP3ToC1C2 = sqrt(distanceC1P3 * distanceC1P3 - projectedDistanceC1 * projectedDistanceC1);
    const point2d directionC1C2 = algo.direction(corner1, corner2);
    const point2d projectedP3OntoC1C2 = algo.interpolate(corner1, directionC1C2, projectedDistanceC1);
    const point2d directionC1C2ToP3 = algo.direction(projectedP3OntoC1C2, point3);
    const point2d corner3 = algo.interpolate(corner2, directionC1C2ToP3, distanceP3ToC1C2);
    const point2d corner4 = algo.interpolate(corner1, directionC1C2ToP3, distanceP3ToC1C2);

    LineString2 ring;
    code = ring.setDimension(3);
    TE_CHECKRETURN_CODE(code);
    code = ring.addPoint(corner1.x, corner1.y, corner1.z);
    TE_CHECKRETURN_CODE(code);
    code = ring.addPoint(corner2.x, corner2.y, corner2.z);
    TE_CHECKRETURN_CODE(code);
    code = ring.addPoint(corner3.x, corner3.y, corner3.z);
    TE_CHECKRETURN_CODE(code);
    code = ring.addPoint(corner4.x, corner4.y, corner4.z);
    TE_CHECKRETURN_CODE(code);
    // and to close, repeat of first corner
    code = ring.addPoint(corner1.x, corner1.y, corner1.z);
    TE_CHECKRETURN_CODE(code);

    value = Geometry2Ptr(new Polygon2(ring), Memory_deleter_const<Geometry2, Polygon2>);
    return code;
}

TAKErr  TAK::Engine::Feature::GeometryFactory_createRectangle(Geometry2Ptr& value, const Math::Point2<double>& location, const double orientation, const double length, const double width, const Renderer::Algorithm& algo) NOTHROWS
{
    TAKErr code(TE_Ok);

    LineString2 ring;
    code = ring.setDimension(3);
    TE_CHECKRETURN_CODE(code);
    typedef Math::Point2<double> point2d;
    const double bearing = orientation * M_PI / 180.0;
    const point2d directionCoaxial(sin(bearing), cos(bearing), 0);
    const point2d directionPerpendicular(directionCoaxial.y, directionCoaxial.x, 0);
    point2d last;
    TE_CHECKRETURN_CODE(code);
    for (std::size_t index = 0; 4 > index; ++index) {
        point2d coaxial, perpendicular;
        switch (index) {
        case 0:
        {
            code = Math::Vector2_multiply(&coaxial, directionCoaxial, -1.0);
            TE_CHECKRETURN_CODE(code);
            code = Math::Vector2_multiply(&perpendicular, directionPerpendicular, -1.0);
            TE_CHECKRETURN_CODE(code);
        }
        break;
        case 1:
        {
            code = Math::Vector2_multiply(&coaxial, directionCoaxial, -1.0);
            TE_CHECKRETURN_CODE(code);
            perpendicular = directionPerpendicular;
        }
        break;
        case 2:
        {
            coaxial = directionCoaxial;
            perpendicular = directionPerpendicular;
        }
        break;
        case 3:
        {
            coaxial = directionCoaxial;
            code = Math::Vector2_multiply(&perpendicular, directionPerpendicular, -1.0);
            TE_CHECKRETURN_CODE(code);
        }
        break;
        default:
            return TE_IllegalState;
        }

        point2d corner = algo.interpolate(location, coaxial, length / 2.);
        corner = algo.interpolate(corner, perpendicular, width / 2.);

        if (0 == index)
            last = corner;
        code = ring.addPoint(corner.x, corner.y, corner.z);
        TE_CHECKRETURN_CODE(code);
    }
    // and to close, repeat of first corner
    code = ring.addPoint(last.x, last.y, last.z);
    TE_CHECKRETURN_CODE(code);

    value = Geometry2Ptr(new Polygon2(ring), Memory_deleter_const<Geometry2, Polygon2>);
    return code;
}

TAKErr  TAK::Engine::Feature::GeometryFactory_createWedge(Geometry2Ptr& value, const Math::Point2<double>& location, const double startAngle, const double endAngle, const double range, const Renderer::Algorithm& algo) NOTHROWS
{
    TAKErr code(TE_Ok);

    LineString2 ring;
    ring.setDimension(3);

    double startRadian = startAngle * M_PI / 180.0;
    double endRadian = endAngle * M_PI / 180.0;

    Math::Point2<double> start = algo.interpolate(location, Math::Point2<double>(sin(startRadian), cos(startRadian), 0), range);
    Math::Point2<double> end   = algo.interpolate(location, Math::Point2<double>(sin(endRadian), cos(endRadian), 0), range);

    ring.addPoint(location.x, location.y, location.z);
    

    const int NUM_SEGMENTS = (int) (double(samplingFactor(range, range)) * (fabs(endAngle - startAngle) / 360.0)) + 1;
    double fraction = 1.0 / NUM_SEGMENTS;

    for (int i = 0; i <= NUM_SEGMENTS; i++) {

        double angle = startRadian + endRadian * i * fraction;
        Math::Point2<double> p = algo.interpolate(location, Math::Point2<double>(sin(angle), cos(angle), 0), range);
        ring.addPoint(p.x, p.y, p.z);
    }

    ring.addPoint(location.x, location.y, location.z);

    value = Geometry2Ptr(new Polygon2(ring), Memory_deleter_const<Geometry2, Polygon2>);
    return code;
}


TAKErr TAK::Engine::Feature::GeometryFactory_createEllipse(Geometry2Ptr& value, const Math::Point2<double>& location, const double orientation, const double major, const double minor, const Renderer::Algorithm& algo) NOTHROWS
{
    TAKErr code(TE_Ok);

    LineString2 ring;
    code = ring.setDimension(3);
    TE_CHECKRETURN_CODE(code);

    static const double TWOPI = 2 * M_PI;

    // normalize in case we get something out of bounds ...
    double bearing = orientation * M_PI / 180.0;
    const int multiple = static_cast<int>(bearing / TWOPI);
    bearing -= multiple * TWOPI;

    int sampling = samplingFactor(major, minor);
    // ensure that we get points associated with the semi axes
    sampling += sampling % 4;

    const double step = TWOPI / sampling;

    Math::Point2<double> last;
    for (double t = 0; TWOPI > t; t += step) {
        double arcBearing = bearing + t;
        if (M_PI < arcBearing)
            arcBearing -= TWOPI;
        if (-M_PI > arcBearing)
            arcBearing += TWOPI;
        const Math::Point2<double> dir(sin(arcBearing), cos(arcBearing), 0.0);
        TE_CHECKRETURN_CODE(code);
        const double x = minor * cos(t);
        const double y = major * sin(t);
        const double range = major * minor / sqrt(x * x + y * y);
        const Math::Point2<double> point = algo.interpolate(location, dir, range);
        if (0 == t)
            last = point;
        code = ring.addPoint(point.x, point.y, point.z);
        TE_CHECKRETURN_CODE(code);
    }
    // and to close, repeat of first point
    code = ring.addPoint(last.x, last.y, last.z);
    TE_CHECKRETURN_CODE(code);

    value = Geometry2Ptr(new Polygon2(ring), Memory_deleter_const<Geometry2, Polygon2>);
    return code;
}

TAKErr TAK::Engine::Feature::GeometryFactory_createEllipse(Geometry2Ptr& value, const Feature::Envelope2 &bounds, const Renderer::Algorithm& algo) NOTHROWS
{
    const Math::Point2<double> min(bounds.minX, bounds.minY, bounds.minZ);
    const Math::Point2<double> max(bounds.maxX, bounds.maxY, bounds.maxZ);

    const double diagonalDistance = algo.distance(min, max);
    const Math::Point2<double> diagonalDirection = algo.direction(min, max);
    const Math::Point2<double> center = algo.interpolate(min, diagonalDirection, diagonalDistance / 2.);

    const Math::Point2<double> centeredMaxX(bounds.maxX, center.y, center.z);
    const double minor = algo.distance(center, centeredMaxX);

    const Math::Point2<double> centeredMaxY(center.x, bounds.maxY, center.z);
    const double major = algo.distance(center, centeredMaxY);

    return GeometryFactory_createEllipse(value, center, 0.0, major, minor, algo);
}

TAKErr TAK::Engine::Feature::GeometryFactory_fromEnvelope(Geometry2Ptr &value, const Envelope2 &e) NOTHROWS
{
    return Polygon2_fromEnvelope(value, e);
}

namespace
{
    TAKErr parseSpatiaLiteGeometry(
        DataInput2 &strm,
        const size_t dim,
        const int typeRestriction,
        const bool hasMeasure,
        const bool isCompressed,
        const GeometryParseCallback &cb) NOTHROWS
    {
        TAKErr code(TE_Ok);

        uint8_t octet;
        code = strm.readByte(&octet);
        TE_CHECKRETURN_CODE(code);
        if ((octet & 0xFF) != 0x69)
        {
            return TE_InvalidArg;
        }

        int type;
        code = strm.readInt(&type);
        int typeModulo = type % 1000;
        TE_CHECKRETURN_CODE(code);

        if (typeRestriction && typeModulo != typeRestriction)
        {
            return TE_InvalidArg;
        }
        switch (typeModulo)
        {
        case 1:                           // Point (SpatiaLite is same as WKB)
            code = parseWKB_Point(strm, dim, hasMeasure, true, cb);
            break;
        case 2:                           // LineString
            code = parseSpatiaLiteLineString(strm, dim, hasMeasure, isCompressed, cb);
            break;

        case 3:                           // Polygon
            code = parseSpatiaLitePolygon(strm, dim, hasMeasure, isCompressed, cb);
            break;

        default:
            return TE_InvalidArg;
        }
        if (code != TE_Ok) return code;

        return code;
    }


    TAKErr parseSpatiaLiteLineString(
        DataInput2 &strm,
        const std::size_t dim,
        const bool hasMeasure,
        const bool isCompressed, 
        const GeometryParseCallback &cb) NOTHROWS
    {
        TAKErr code(TE_Ok);
        TE_CHECKRETURN_CODE(code);
        int count;
        code = strm.readInt(&count);
        TE_CHECKRETURN_CODE(code);
        if (count < 0)
            return TE_Err;

        // start the geometry
        code = cb(TEGF_StartGeometry, TEGC_LineString, dim, (std::size_t)count, Point2(NAN, NAN));
        if (code != TE_Ok) return code;
        if (!isCompressed)
        {
            if (!hasMeasure)                // !isCompressed && !hasMeasure
            {
                if (strm.getSourceEndian() == TE_PlatformEndian)
                {
                    double xyz[3u];
                    const std::size_t readSize = (dim * sizeof(double));
                    for(std::size_t i = 0u; i < (std::size_t)count; i++) {
                        std::size_t numRead;
                        code = strm.read(reinterpret_cast<uint8_t *>(xyz), &numRead, readSize);
                        TE_CHECKBREAK_CODE(code);
                        if (numRead < readSize)
                            return TE_EOF;
                        Point2 p(xyz[0], xyz[1], xyz[2]);
                        p.setDimension(dim);
                        code = cb(TEGF_Point, TEGC_LineString, dim, count, p);
                        if (code != TE_Ok) return code;
                    }
                    TE_CHECKRETURN_CODE(code);
                }
                else
                {
                    double xyz[3u];
                    for(std::size_t i = 0u; i < (std::size_t)count; i++) {
                        for(std::size_t j = 0u; j < dim; j++) {
                            code = strm.readDouble(xyz + j);
                            TE_CHECKBREAK_CODE(code);

                        }
                        TE_CHECKBREAK_CODE(code);
                        Point2 p(xyz[0], xyz[1], xyz[2]);
                        p.setDimension(dim);
                        code = cb(TEGF_Point, TEGC_LineString, dim, count, p);
                        if (code != TE_Ok) return code;
                    }
                    TE_CHECKRETURN_CODE(code);
                }
            }
            else                            // !isCompressed && hasMeasure
            {
                switch (dim)
                {
                case 2u:

                    for (int i(0); i < count; ++i)
                    {
                        double x;
                        code = strm.readDouble(&x);
                        TE_CHECKBREAK_CODE(code);
                        double y;
                        code = strm.readDouble(&y);
                        TE_CHECKBREAK_CODE(code);

                        code = cb(TEGF_Point, TEGC_LineString, dim, count, Point2(x, y));
                        if (code != TE_Ok) return code;

                        code = strm.skip(8);
                        TE_CHECKBREAK_CODE(code);
                    }
                    TE_CHECKRETURN_CODE(code);
                    break;

                case 3u:

                    for (int i(0); i < count; ++i)
                    {
                        double x;
                        code = strm.readDouble(&x);
                        TE_CHECKBREAK_CODE(code);
                        double y;
                        code = strm.readDouble(&y);
                        TE_CHECKBREAK_CODE(code);
                        double z;
                        code = strm.readDouble(&z);
                        TE_CHECKBREAK_CODE(code);

                        code = cb(TEGF_Point, TEGC_LineString, dim, count, Point2(x, y, z));
                        if (code != TE_Ok) return code;

                        code = strm.skip(8);
                        TE_CHECKBREAK_CODE(code);
                    }
                    TE_CHECKRETURN_CODE(code);
                    break;
                default:
                    return TE_InvalidArg;
                }
            }
        }
        else                                // isCompressed
        {
            switch (dim)
            {
            case 2u:

                if (!hasMeasure)            // isCompressed && !hasMeasure
                {
                    double x;
                    double y;
                    code = strm.readDouble(&x);
                    TE_CHECKRETURN_CODE(code);
                    code = strm.readDouble(&y);
                    TE_CHECKRETURN_CODE(code);

                    code = cb(TEGF_Point, TEGC_LineString, dim, count, Point2(x, y));
                    if (code != TE_Ok) return code;

                    for (int i(1); i < count; ++i)
                    {
                        float xoff;
                        float yoff;
                        code = strm.readFloat(&xoff);
                        TE_CHECKBREAK_CODE(code);
                        code = strm.readFloat(&yoff);
                        TE_CHECKBREAK_CODE(code);
                        x += xoff;
                        y += yoff;
                        code = cb(TEGF_Point, TEGC_LineString, dim, count, Point2(x, y));
                        if (code != TE_Ok) return code;
                    }
                    TE_CHECKRETURN_CODE(code);
                }
                else                        // isCompressed && hasMeasure
                {
                    double x;
                    double y;
                    code = strm.readDouble(&x);
                    TE_CHECKRETURN_CODE(code);
                    code = strm.readDouble(&y);
                    TE_CHECKRETURN_CODE(code);

                    code = cb(TEGF_Point, TEGC_LineString, dim, count, Point2(x, y));
                    if (code != TE_Ok) return code;

                    code = strm.skip(8u);
                    TE_CHECKRETURN_CODE(code);

                    for (int i(1); i < count; ++i)
                    {
                        float xoff;
                        float yoff;
                        code = strm.readFloat(&xoff);
                        TE_CHECKBREAK_CODE(code);
                        code = strm.readFloat(&yoff);
                        TE_CHECKBREAK_CODE(code);
                        x += xoff;
                        y += yoff;
                        code = cb(TEGF_Point, TEGC_LineString, dim, count, Point2(x, y));
                        if (code != TE_Ok) return code;
                        code = strm.skip(4u);
                        TE_CHECKBREAK_CODE(code);
                    }
                    TE_CHECKRETURN_CODE(code);
                }
                break;
            case 3u:

                if (!hasMeasure)            // isCompressed && !hasMeasure
                {
                    double x;
                    double y;
                    double z;

                    code = strm.readDouble(&x);
                    TE_CHECKRETURN_CODE(code);
                    code = strm.readDouble(&y);
                    TE_CHECKRETURN_CODE(code);
                    code = strm.readDouble(&z);
                    TE_CHECKRETURN_CODE(code);

                    code = cb(TEGF_Point, TEGC_LineString, dim, count, Point2(x, y, z));
                    if (code != TE_Ok) return code;

                    for (int i(1); i < count; ++i)
                    {
                        float xoff;
                        float yoff;
                        float zoff;
                        code = strm.readFloat(&xoff);
                        TE_CHECKBREAK_CODE(code);
                        code = strm.readFloat(&yoff);
                        TE_CHECKBREAK_CODE(code);
                        code = strm.readFloat(&zoff);
                        TE_CHECKBREAK_CODE(code);
                        x += xoff;
                        y += yoff;
                        z += zoff;

                        code = cb(TEGF_Point, TEGC_LineString, dim, count, Point2(x, y, z));
                        if (code != TE_Ok) return code;
                    }
                    TE_CHECKRETURN_CODE(code);
                }
                else
                {
                    double x;
                    double y;
                    double z;

                    code = strm.readDouble(&x);
                    TE_CHECKRETURN_CODE(code);
                    code = strm.readDouble(&y);
                    TE_CHECKRETURN_CODE(code);
                    code = strm.readDouble(&z);
                    TE_CHECKRETURN_CODE(code);

                    code = cb(TEGF_Point, TEGC_LineString, dim, count, Point2(x, y, z));
                    if (code != TE_Ok) return code;

                    code = strm.skip(8u);
                    TE_CHECKRETURN_CODE(code);

                    for (int i(1); i < count; ++i)
                    {
                        float xoff;
                        float yoff;
                        float zoff;
                        code = strm.readFloat(&xoff);
                        TE_CHECKBREAK_CODE(code);
                        code = strm.readFloat(&yoff);
                        TE_CHECKBREAK_CODE(code);
                        code = strm.readFloat(&zoff);
                        TE_CHECKBREAK_CODE(code);
                        x += xoff;
                        y += yoff;
                        z += zoff;

                        code = cb(TEGF_Point, TEGC_LineString, dim, count, Point2(x, y, z));
                        if (code != TE_Ok) return code;

                        code = strm.skip(4u);
                        TE_CHECKBREAK_CODE(code);
                    }
                    TE_CHECKRETURN_CODE(code);
                }
                break;

            default:
                return TE_InvalidArg;
            }
        }

        code = cb(TEGF_EndGeometry, TEGC_LineString, dim, (std::size_t)count, Point2(NAN, NAN));
        return code;
    }


    TAKErr parseSpatiaLitePolygon(
        DataInput2 &strm,
        const std::size_t dim,
        const bool hasMeasure,
        const bool isCompressed,
        const GeometryParseCallback &cb) NOTHROWS
    {
        TAKErr code(TE_Ok);

        int count;
        code = strm.readInt(&count);
        TE_CHECKRETURN_CODE(code);

        if (count < 1)
            return TE_InvalidArg;

        code = cb(TEGF_StartGeometry, TEGC_Polygon, dim, (std::size_t)count, Point2(NAN, NAN));
        if (code != TE_Ok) return code;

        // exterior ring
        code = parseSpatiaLiteLineString(strm, dim, hasMeasure, isCompressed, cb);
        if (code != TE_Ok) return code;

        // interior rings
        for (int i(1); i < count; ++i)
        {
            code = parseSpatiaLiteLineString(strm, dim, hasMeasure, isCompressed, cb);
            if (code != TE_Ok) return code;
        }
        TE_CHECKRETURN_CODE(code);

        code = cb(TEGF_EndGeometry, TEGC_Polygon, dim, (std::size_t)count, Point2(NAN, NAN));

        return code;
    }

    TAKErr parseWKB_LineString(
        DataInput2 &strm,
        const std::size_t dim,
        const bool hasMeasure,
        const GeometryParseCallback &cb) NOTHROWS
    {
        TAKErr code(TE_Ok);

        int count;
        code = strm.readInt(&count);
        TE_CHECKRETURN_CODE(code);

        code = cb(TEGF_StartGeometry, TEGC_LineString, dim, (std::size_t)count, Point2(NAN, NAN));
        if (code != TE_Ok) return code;
        if (!hasMeasure)
        {
            if (strm.getSourceEndian() == TE_PlatformEndian)
            {
                double xyz[3u];
                const std::size_t readSize = (dim * sizeof(double));
                for(std::size_t i = 0u; i < (std::size_t)count; i++) {
                    std::size_t numRead;
                    code = strm.read(reinterpret_cast<uint8_t *>(xyz), &numRead, readSize);
                    TE_CHECKBREAK_CODE(code);
                    if (numRead < readSize)
                        return TE_EOF;
                    Point2 p(xyz[0], xyz[1], xyz[2]);
                    p.setDimension(dim);
                    code = cb(TEGF_Point, TEGC_LineString, dim, count, p);
                    if (code != TE_Ok) return code;
                }
                TE_CHECKRETURN_CODE(code);
            }
            else
            {
                double xyz[3u];
                for(std::size_t i = 0u; i < (std::size_t)count; i++) {
                    for(std::size_t j = 0u; j < dim; j++) {
                        code = strm.readDouble(xyz + j);
                        TE_CHECKBREAK_CODE(code);

                    }
                    TE_CHECKBREAK_CODE(code);
                    Point2 p(xyz[0], xyz[1], xyz[2]);
                    p.setDimension(dim);
                    code = cb(TEGF_Point, TEGC_LineString, dim, count, p);
                    if (code != TE_Ok) return code;
                }
                TE_CHECKRETURN_CODE(code);
            }
        }
        else
        {
            switch (dim)
            {
             case 2u:

                for (int i(0); i < count; ++i)
                {
                    double x;
                    double y;
                    code = strm.readDouble(&x);
                    TE_CHECKBREAK_CODE(code);
                    code = strm.readDouble(&y);
                    TE_CHECKBREAK_CODE(code);
                    code = cb(TEGF_Point, TEGC_LineString, dim, (std::size_t)count, Point2(x, y));
                    if (code != TE_Ok) return code;

                    code = strm.skip(8u);
                    TE_CHECKBREAK_CODE(code);
                }
                TE_CHECKRETURN_CODE(code);
                break;
            case 3u:

                for (int i(0); i < count; ++i)
                {
                    double x;
                    double y;
                    double z;
                    code = strm.readDouble(&x);
                    TE_CHECKBREAK_CODE(code);
                    code = strm.readDouble(&y);
                    TE_CHECKBREAK_CODE(code);
                    code = strm.readDouble(&z);
                    TE_CHECKBREAK_CODE(code);
                    code = cb(TEGF_Point, TEGC_LineString, dim, (std::size_t)count, Point2(x, y, z));
                    if (code != TE_Ok) return code;

                    code = strm.skip(8u);
                    TE_CHECKBREAK_CODE(code);
                }
                TE_CHECKRETURN_CODE(code);
                break;
            default:
                return TE_InvalidArg;
            }
        }

        code = cb(TEGF_EndGeometry, TEGC_LineString, dim, (std::size_t)count, Point2(NAN, NAN));

        return code;
    }


    TAKErr parseWKB_Point(
        DataInput2 &strm,
        const std::size_t dim,
        const bool hasMeasure,
        const bool raiseStartEndGeom,
        const GeometryParseCallback &cb) NOTHROWS
    {
        TAKErr code(TE_Ok);

        if(raiseStartEndGeom) {
            code = cb(TEGF_StartGeometry, TEGC_Point, dim, 0u, Point2(NAN, NAN));
            if (code != TE_Ok) return code;
        }
        double x;
        double y;
        code = strm.readDouble(&x);
        TE_CHECKRETURN_CODE(code);
        code = strm.readDouble(&y);
        TE_CHECKRETURN_CODE(code);


        Point2 result(x, y);
        if (dim == 3) {
            code = result.setDimension(dim);
            TE_CHECKRETURN_CODE(code);
            double z;
            code = strm.readDouble(&z);
            TE_CHECKRETURN_CODE(code);

            result.z = z;
        }
        if (hasMeasure)
        {
            code = strm.skip(8u);
            TE_CHECKRETURN_CODE(code);
        }

        code = cb(TEGF_Point, TEGC_Point, dim, 0u, result);
        if (code != TE_Ok) return code;

        if(raiseStartEndGeom) {
            code = cb(TEGF_EndGeometry, TEGC_Point, dim, 0u, Point2(NAN, NAN));
            if (code != TE_Ok) return code;
        }

        return code;
    }


    TAKErr parseWKB_Polygon(
        DataInput2 &strm,
        const std::size_t dim,
        const bool hasMeasure,
        const GeometryParseCallback &cb) NOTHROWS
    {
        TAKErr code(TE_Ok);

        int count;
        code = strm.readInt(&count);
        TE_CHECKRETURN_CODE(code);

        if (count < 1)
            return TE_InvalidArg;

        code = cb(TEGF_StartGeometry, TEGC_Polygon, dim, (std::size_t)count, Point2(NAN, NAN));
        TE_CHECKRETURN_CODE(code);

        code = parseWKB_LineString(strm, dim, hasMeasure, cb);
        TE_CHECKRETURN_CODE(code);

        for (int i(1); i < count; ++i)
        {
            code = parseWKB_LineString(strm, dim, hasMeasure, cb);
            TE_CHECKBREAK_CODE(code);
        }
        TE_CHECKRETURN_CODE(code);

        return cb(TEGF_EndGeometry, TEGC_Polygon, dim, (std::size_t)count, Point2(NAN, NAN));
    }

    TAKErr packWKB_writeHeader(DataOutput2 &strm, const TAKEndian order, const Geometry2 &geom, const uint32_t baseType) NOTHROWS
    {
        TAKErr code(TE_Ok);
        uint8_t orderFlag;
        if (order == TE_BigEndian)
            orderFlag = (uint8_t)0x00u;
        else if (order == TE_LittleEndian)
            orderFlag = (uint8_t)0x01u;
        else
            return TE_IllegalState;;
        code = strm.writeByte(orderFlag);
        TE_CHECKRETURN_CODE(code);

        std::size_t dim = geom.getDimension();
        uint32_t typeCode;
        if (dim == 2u)
            typeCode = baseType;
        else if (dim == 3u)
            typeCode = baseType + 1000u;
        else
            return TE_IllegalState;
        code = strm.writeInt(static_cast<int32_t>(typeCode));
        TE_CHECKRETURN_CODE(code);

        return code;
    }

    TAKErr packWKB_Point(DataOutput2 &strm, const TAKEndian order, const Point2 &p) NOTHROWS
    {
        TAKErr code(TE_Ok);
        code = packWKB_writeHeader(strm, order, p, 1u);
        TE_CHECKRETURN_CODE(code);

        code = strm.writeDouble(p.x);
        TE_CHECKRETURN_CODE(code);
        code = strm.writeDouble(p.y);
        TE_CHECKRETURN_CODE(code);
        if (p.getDimension() == 3u) {
            code = strm.writeDouble(p.z);
            TE_CHECKRETURN_CODE(code);
        }

        return code;
    }

    TAKErr packWKB_LineString(DataOutput2 &strm, const TAKEndian order, const LineString2 &linestring) NOTHROWS
    {
        TAKErr code(TE_Ok);
        code = packWKB_writeHeader(strm, order, linestring, 2u);
        TE_CHECKRETURN_CODE(code);

        code = packWKB_writePoints(strm, linestring);
        TE_CHECKRETURN_CODE(code);

        return code;
    }
    TAKErr packWKB_writePoints(DataOutput2 &strm, const LineString2 &linestring) NOTHROWS
    {
        TAKErr code(TE_Ok);
        const std::size_t numPoints = linestring.getNumPoints();
        const std::size_t dimension = linestring.getDimension();
        code = strm.writeInt(static_cast<int32_t>(numPoints));
        TE_CHECKRETURN_CODE(code);
        if (dimension == 3u) {
            for (std::size_t i = 0; i < numPoints; i++) {
                double v;

                code = linestring.getX(&v, i);
                TE_CHECKBREAK_CODE(code);
                code = strm.writeDouble(v);
                TE_CHECKBREAK_CODE(code);

                code = linestring.getY(&v, i);
                TE_CHECKBREAK_CODE(code);
                code = strm.writeDouble(v);
                TE_CHECKBREAK_CODE(code);

                code = linestring.getZ(&v, i);
                TE_CHECKBREAK_CODE(code);
                code = strm.writeDouble(v);
                TE_CHECKBREAK_CODE(code);
            }
            TE_CHECKRETURN_CODE(code);
        }
        else if (dimension == 2u) {
            for (std::size_t i = 0; i < numPoints; i++) {
                double v;

                code = linestring.getX(&v, i);
                TE_CHECKBREAK_CODE(code);
                code = strm.writeDouble(v);
                TE_CHECKBREAK_CODE(code);

                code = linestring.getY(&v, i);
                TE_CHECKBREAK_CODE(code);
                code = strm.writeDouble(v);
                TE_CHECKBREAK_CODE(code);
            }
            TE_CHECKRETURN_CODE(code);
        }
        else {
            return TE_IllegalState;
        }

        return code;
    }
    TAKErr packWKB_Polygon(DataOutput2 &strm, const TAKEndian order, const Polygon2 &polygon) NOTHROWS
    {
        TAKErr code(TE_Ok);
        code = packWKB_writeHeader(strm, order, polygon, 3u);

        std::size_t numInteriorRings = polygon.getNumInteriorRings();
        code = strm.writeInt(static_cast<int32_t>(numInteriorRings + 1u));
        TE_CHECKRETURN_CODE(code);

        std::shared_ptr<LineString2> ring;

        code = polygon.getExteriorRing(ring);
        TE_CHECKRETURN_CODE(code);
        if (!ring.get())
            return TE_IllegalState;
        code = packWKB_writePoints(strm, *ring);
        TE_CHECKRETURN_CODE(code);

        for (std::size_t i = 0u; i < numInteriorRings; i++) {
            code = polygon.getInteriorRing(ring, i);
            TE_CHECKRETURN_CODE(code);
            if (!ring.get())
                return TE_IllegalState;
            code = packWKB_writePoints(strm, *ring);
            TE_CHECKBREAK_CODE(code);
        }
        TE_CHECKRETURN_CODE(code);

        return code;
    }
    TAKErr packWKB_GeometryCollection(DataOutput2 &strm, const TAKEndian order, const GeometryCollection2 &c) NOTHROWS
    {
        TAKErr code(TE_Ok);
        code = packWKB_writeHeader(strm, order, c, 7u);
        TE_CHECKRETURN_CODE(code);

        const std::size_t numChildren = c.getNumGeometries();
        code = strm.writeInt(static_cast<int32_t>(numChildren));
        TE_CHECKRETURN_CODE(code);

        for (std::size_t i = 0u; i < numChildren; i++) {
            std::shared_ptr<Geometry2> child;
            code = c.getGeometry(child, i);
            TE_CHECKRETURN_CODE(code);

            if (!child.get())
                return TE_IllegalState;

            code = GeometryFactory_toWkb(strm, *child, order);
            TE_CHECKBREAK_CODE(code);
        }
        TE_CHECKRETURN_CODE(code);

        return code;
    }

    template<class T>
    TAKErr extrudeGeometry(Geometry2Ptr &value, const Geometry2 &src, const T &extrude, const int hints) NOTHROWS
    {
        TAKErr code(TE_Ok);

        if (3 != src.getDimension())
            return TE_InvalidArg;

        if(!extrude(src))
            return TE_InvalidArg;

        switch (src.getClass()) {
        case GeometryClass::TEGC_Point:
        {
            static const int invalidHints = TEEH_GeneratePolygons | TEEH_IncludeBottomFace;
            if (0 != (invalidHints & hints))
                return TE_InvalidArg;
            code = extrudePointAsLine(value, static_cast<const Point2&>(src), extrude);
        }
        break;
        case GeometryClass::TEGC_LineString:
        {
            static const int invalidHints = TEEH_IncludeBottomFace;
            if (0 != (invalidHints & hints))
                return TE_InvalidArg;

            const auto& line = static_cast<const LineString2 &>(src);
            if (2 > line.getNumPoints())
                return TE_InvalidArg;

            code = ((hints & TEEH_GeneratePolygons) == TEEH_GeneratePolygons) ?
                extrudeLineAsPolygon(value, line, extrude) :
                extrudeLineAsCollection(value, line, extrude, hints);
        }
        break;
        case GeometryClass::TEGC_Polygon:
        {
            static const int invalidHints = TEEH_GeneratePolygons;
            if (0 != (invalidHints & hints))
                return TE_InvalidArg;

            code = extrudePolygonAsCollection(value, static_cast<const Polygon2&>(src), extrude, hints);
        }
        break;
        default:
            break;
        }

        return code;
    }
    template<class T>
    TAKErr extrudePointAsLine(Geometry2Ptr& value, const Point2& point, const T &extrude) NOTHROWS
    {
        TAKErr code(TE_Ok);
        std::unique_ptr<LineString2> line(new LineString2);
        code = line->setDimension(3);
        TE_CHECKRETURN_CODE(code);
        code = line->addPoint(point.x, point.y, point.z);
        TE_CHECKRETURN_CODE(code);
        code = line->addPoint(point.x, point.y, point.z + extrude[0u]);
        TE_CHECKRETURN_CODE(code);

        value = Geometry2Ptr(line.release(), Memory_deleter_const<Geometry2, LineString2>);
        return code;
    }
    template<class T>
    TAKErr extrudeLineAsPolygon(Geometry2Ptr& value, const LineString2& line, const T &extrude) NOTHROWS
    {
        TAKErr code(TE_Ok);

        Point2 point(0, 0, 0);
        const std::size_t pointCount = 2 * line.getNumPoints();
        std::unique_ptr<double[], void(*)(const double*)> points(new double[pointCount * 3], Memory_array_deleter_const<double>);
        for (std::size_t index = 0, max = line.getNumPoints(), last = pointCount - 1; max > index; ++index) {
            code = line.get(&point, index);
            TE_CHECKRETURN_CODE(code);
            double *base = points.get() + 3 * index;
            base[0] = point.x;
            base[1] = point.y;
            base[2] = point.z;
            point.z += extrude[index];
            double *mirror = points.get() + 3 * (last - index);
            mirror[0] = point.x;
            mirror[1] = point.y;
            mirror[2] = point.z;
        }

        LineString2 ring;
        code = ring.setDimension(3);
        TE_CHECKRETURN_CODE(code);
        code = ring.addPoints(points.get(), pointCount, 3);
        TE_CHECKRETURN_CODE(code);
        // close the ring
        code = ring.get(&point, 0);
        TE_CHECKRETURN_CODE(code);
        code = ring.addPoint(point.x, point.y, point.z);
        TE_CHECKRETURN_CODE(code);

        value = Geometry2Ptr(new Polygon2(ring), Memory_deleter_const<Geometry2, Polygon2>);
        return code;
    }
    template<class T>
    TAKErr extrudeLineAsCollection(Geometry2Ptr& value, const LineString2& line, const T &extrude, const int hints) NOTHROWS
    {
        TAKErr code(TE_Ok);

        std::unique_ptr<GeometryCollection2> collection(new GeometryCollection2);
        code = collection->setDimension(3);
        TE_CHECKRETURN_CODE(code);

        Point2 point(0, 0, 0); // 3D point for reuse below ...
        for (std::size_t index = 0, max = line.getNumPoints() - 1; max > index; ++index) {
            double points[12];
            for (std::size_t offset = 0; 2 > offset; ++offset) {
                code = line.get(&point, index + offset);
                TE_CHECKRETURN_CODE(code);
                double *base = points + 3 * offset;
                base[0] = point.x;
                base[1] = point.y;
                base[2] = point.z;
                point.z += extrude[index+offset];
                double *mirror = points + 3 * (3 - offset);
                mirror[0] = point.x;
                mirror[1] = point.y;
                mirror[2] = point.z;
            }

            LineString2 ring;
            code = ring.setDimension(3);
            TE_CHECKRETURN_CODE(code);
            code = ring.addPoints(points, 4, 3);
            TE_CHECKRETURN_CODE(code);

            // close the ring ...
            code = ring.get(&point, 0);
            TE_CHECKRETURN_CODE(code);
            code = ring.addPoint(point.x, point.y, point.z);
            TE_CHECKRETURN_CODE(code);

            Geometry2Ptr geometry(new Polygon2(ring), Memory_deleter_const<Geometry2, Polygon2>);
            code = collection->addGeometry(std::move(geometry));
            TE_CHECKRETURN_CODE(code);
        }

        value = Geometry2Ptr(collection.release(), Memory_deleter_const<Geometry2, GeometryCollection2>);
        return code;
    }

    TAKErr appendGeometryCollection(GeometryCollection2 &sink, const GeometryCollection2 &source) {
        TAKErr code(TE_Ok);

        STLVectorAdapter<std::shared_ptr<Geometry2>> collection;
        code = source.getGeometries(collection);
        TE_CHECKRETURN_CODE(code);

        Collection<std::shared_ptr<Geometry2>>::IteratorPtr itr(nullptr, nullptr);
        code = collection.iterator(itr);
        TE_CHECKRETURN_CODE(code);

        do {
            std::shared_ptr<Geometry2> element;
            code = itr->get(element);
            if (TE_Ok == code) {
                code = sink.addGeometry(*element);
                TE_CHECKRETURN_CODE(code);
                code = itr->next();
            }
        } while (TE_Ok == code);

        if (TE_Done == code)
            code = TE_Ok;

        return code;
    }

    template<class T>
    TAKErr projectLineString(LineString2Ptr &projected, const LineString2 &source, const T &extrude) {
        TAKErr code(TE_Ok);
        LineString2Ptr line(new LineString2(source), Memory_deleter_const<LineString2>);
        for (std::size_t index = 0, max = line->getNumPoints(); max > index; ++index) {
            double zValue;
            code = line->getZ(&zValue, index);
            TE_CHECKRETURN_CODE(code);
            zValue += extrude[index];
            code = line->setZ(index, zValue);
            TE_CHECKRETURN_CODE(code);
        }
        projected.swap(line);
        return code;
    }

    template<class T>
    TAKErr extrudePolygonAsCollection(Geometry2Ptr& value, const Polygon2& polygon, const T &extrude, const int hints) NOTHROWS
    {
        static const ExtrusionHints faceHints = TEEH_OmitTopFace;

        TAKErr code(TE_Ok);

        // the collection for all generated faces
        std::unique_ptr<GeometryCollection2> collection(new GeometryCollection2);

        // get the exterior ring and its faces
        std::shared_ptr<LineString2> exteriorRing;
        code = polygon.getExteriorRing(exteriorRing);
        TE_CHECKRETURN_CODE(code);
        Geometry2Ptr exteriorFaces(nullptr, nullptr);
        code = extrudeLineAsCollection(exteriorFaces, *exteriorRing, extrude, faceHints);
        TE_CHECKRETURN_CODE(code);
        code = appendGeometryCollection(*collection, static_cast<const GeometryCollection2&>(*exteriorFaces));
        TE_CHECKRETURN_CODE(code);

        // and collect for top polygon, if hinted

        std::unique_ptr<Polygon2> top(nullptr);
        if (0 == (hints & TEEH_OmitTopFace)) {
            LineString2Ptr projected(nullptr, Memory_deleter_const<LineString2>);
            code = projectLineString(projected, *exteriorRing, extrude);
            TE_CHECKRETURN_CODE(code);

            top.reset(new Polygon2(*projected));
        }

        // get the interior rings and their faces
        STLVectorAdapter<std::shared_ptr<LineString2>> interiorRings;
        code = polygon.getInteriorRings(interiorRings);
        TE_CHECKRETURN_CODE(code);

        Collection<std::shared_ptr<LineString2>>::IteratorPtr itr(nullptr, nullptr);
        code = interiorRings.iterator(itr);
        TE_CHECKRETURN_CODE(code);

        do {
            std::shared_ptr<LineString2> ring;
            code = itr->get(ring);
            if (TE_Ok == code) {
                Geometry2Ptr faces(nullptr, nullptr);
                code = extrudeLineAsCollection(faces, *ring, extrude, faceHints);
                TE_CHECKRETURN_CODE(code);
                code = appendGeometryCollection(*collection, static_cast<const GeometryCollection2&>(*faces));
                TE_CHECKRETURN_CODE(code);
                if (top) {
                    LineString2Ptr projected(nullptr, Memory_deleter_const<LineString2>);
                    code = projectLineString(projected, *ring, extrude);
                    TE_CHECKRETURN_CODE(code);
                    code = top->addInteriorRing(*projected);
                    TE_CHECKRETURN_CODE(code);
                }
                code = itr->next();
            }

        } while (TE_Ok == code);

        if (TE_Done == code)
            code = TE_Ok;
        TE_CHECKRETURN_CODE(code);

        // add top
        if (top) {
            Geometry2Ptr geo(top.release(), Memory_deleter_const<Geometry2, Polygon2>);
            code = collection->addGeometry(std::move(geo));
            TE_CHECKRETURN_CODE(code);
        }

        // and bottom
        if (TEEH_IncludeBottomFace == (TEEH_IncludeBottomFace & hints)) {
            code = collection->addGeometry(polygon);
            TE_CHECKRETURN_CODE(code);
        }

        value = Geometry2Ptr(collection.release(), Memory_deleter_const<Geometry2, GeometryCollection2>);
        return code;
    }

    int samplingFactor(const double &semiMajorAxis, const double &semiMinorAxis) NOTHROWS
    {
        const double maxe = std::max(semiMajorAxis, semiMinorAxis);
        const double mine = std::min(semiMajorAxis, semiMinorAxis);
        return std::min(std::max(360, static_cast<int>(40.0 * maxe / mine)), 1024);
    }

}
