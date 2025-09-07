#include "feature/ParseGeometry.h"

#include <list>
#include <memory>
#include <sstream>
#include <stack>

#include "feature/GeometryFactory.h"
#include "feature/Feature2.h"

#include "feature/Geometry.h"
#include "feature/GeometryCollection.h"
#include "feature/LineString.h"
#include "feature/Point.h"
#include "feature/Polygon.h"

#include "util/DataInput2.h"
#include "util/IO.h"


#define MEM_FN( fn )    "atakmap::feature::ParseGeometry::" fn ": "


using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Util;

namespace                               // Open unnamed namespace.
{
	// allow for nesting of GeometryCollection > Polygon > LineString > Point without vector
	constexpr std::size_t geometryBuilderArrayCountLimit = 4u;

	struct GeometryStackElement
	{
		GeometryClass gc;
		GeometryPtr value{ nullptr, nullptr };
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
					count--;
					if(v.data() == value)
						v.pop_back();
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

		TAKErr push(GeometryPtr &&geom) NOTHROWS
		{
			TAKErr code(TE_Ok);
			if(!stack.empty()) {
				// the stack is not empty, we should only be pushing geometry objects onto it if we have a
				// polygon (rings) or a geometry collection (child geometries)
				auto &peek = stack.peek();
				switch(peek.gc) {
					case TEGC_Polygon :
					{
						if (geom->getType() != atakmap::feature::Geometry::LINESTRING)
							return TE_InvalidArg;
						auto& p = static_cast<atakmap::feature::Polygon&>(*peek.value);
						// add ring
						p.addRing(static_cast<const atakmap::feature::LineString&>(*geom));
						geom = GeometryPtr(p.getRing(p.getRingCount()-1u), Memory_leaker_const<atakmap::feature::Geometry>);
						break;
					}
					case TEGC_GeometryCollection :
					{
						auto& c = static_cast<atakmap::feature::GeometryCollection&>(*peek.value);
						geom = GeometryPtr(c.add(*geom), Memory_leaker_const<atakmap::feature::Geometry>);
						break;
					}
					default :
						return TE_InvalidArg;
				}
				TE_CHECKRETURN_CODE(code);
			}

			GeometryStackElement el;
			switch(geom->getType()) {
				case atakmap::feature::Geometry::POINT:
					el.gc = TEGC_Point;
					break;
				case atakmap::feature::Geometry::LINESTRING:
					el.gc = TEGC_LineString;
					break;
				case atakmap::feature::Geometry::POLYGON:
					el.gc = TEGC_Polygon;
					break;
				case atakmap::feature::Geometry::COLLECTION:
					el.gc = TEGC_GeometryCollection;
					break;
				default :
					return TE_IllegalState;
			}
			el.value = std::move(geom);
			stack.push(std::move(el));
			return code;
		}

		TAKErr operator()(const GeometryParseCommand cmd, const GeometryClass gc, const std::size_t dim, const std::size_t count, const TAK::Engine::Feature::Point2 &p)
		{
			auto ldim = (dim == 3u) ? atakmap::feature::Geometry::_3D : atakmap::feature::Geometry::_2D;
			switch(cmd) {
				// starting a new geometry
				case TEGF_StartGeometry :
				{
					GeometryPtr geom(nullptr, nullptr);
					switch (gc) {
					case TEGC_Point:
					{
						if (!stack.empty()) {
							const auto& peek = stack.peek();
							// if linestring or point, nothing to do when a new point starts
							if (peek.gc == TEGC_LineString || peek.gc == TEGC_Point)
								return TE_Ok;
						}
						geom = GeometryPtr(new atakmap::feature::Point(p.x, p.y, p.z), Memory_deleter_const<atakmap::feature::Geometry, atakmap::feature::Point>);
						break;
					}
					case TEGC_LineString:
						geom = GeometryPtr(new atakmap::feature::LineString(), Memory_deleter_const<atakmap::feature::Geometry, atakmap::feature::LineString>);
						break;
					case TEGC_Polygon:
						geom = GeometryPtr(new atakmap::feature::Polygon(ldim), Memory_deleter_const<atakmap::feature::Geometry, atakmap::feature::Polygon>);
						break;
					case TEGC_GeometryCollection:
						geom = GeometryPtr(new atakmap::feature::GeometryCollection(ldim), Memory_deleter_const<atakmap::feature::Geometry, atakmap::feature::GeometryCollection>);
						break;
					default:
						return TE_Err;
					}

					if (geom) {
						geom->setDimension(dim == 3u ? atakmap::feature::Geometry::_3D : atakmap::feature::Geometry::_2D);
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
								static_cast<atakmap::feature::LineString&>(*peek.value).addPoint(p.x, p.y);
							else if (p.getDimension() == 3u)
								static_cast<atakmap::feature::LineString&>(*peek.value).addPoint(p.x, p.y, p.z);
							else
								return TE_IllegalState;
							break;
						case TEGC_Point :
							static_cast<atakmap::feature::Point&>(*peek.value).x = p.x;
							static_cast<atakmap::feature::Point&>(*peek.value).y = p.y;
							static_cast<atakmap::feature::Point&>(*peek.value).z = p.z;
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

		TAKErr build(GeometryPtr_const &value) NOTHROWS
		{
			if (stack.size() != 1u)
				return TE_IllegalState;
			value = std::move(stack.peek().value);
			stack.pop();
			return TE_Ok;
		}
		TAKErr build(GeometryPtr &value) NOTHROWS
		{
			if (stack.size() != 1u)
				return TE_IllegalState;
			value = std::move(stack.peek().value);
			stack.pop();
			return TE_Ok;
		}
	};

    class IStreamInput2 : public DataInput2
    {
    public:
        IStreamInput2() NOTHROWS :
            strm_(nullptr)
        {}
        virtual ~IStreamInput2() NOTHROWS
        {}

        virtual TAKErr open(std::istream &strm) NOTHROWS
        {
            strm_ = &strm;
            return TE_Ok;
        }
        virtual TAKErr close() NOTHROWS override
        {
            if(strm_)
                strm_ = nullptr;
            return TE_Ok;
        }

        virtual TAKErr read(uint8_t *buf, std::size_t *numRead, const std::size_t len) NOTHROWS override
        {
            try {
                strm_->read(reinterpret_cast<char *>(buf), len);
                if (numRead)
                    *numRead = strm_->gcount();
                return !!(*strm_) ? TE_Ok : TE_EOF;
            } catch (...) {
                return TE_Err;
            }
        }
        virtual TAKErr readByte(uint8_t *value) NOTHROWS override
        {
            try {
                *value = strm_->get() & 0xFF;
                return !!(*strm_) ? TE_Ok : TE_EOF;
            } catch (...) {
                return TE_Err;
            }
        }
        virtual TAKErr skip(const std::size_t n) NOTHROWS override
        {
            strm_->ignore(n);
            return TE_Ok;
        }
    private:
        std::istream *strm_;
    };
}                                       // Close unnamed namespace.


namespace atakmap                       // Open atakmap namespace.
{
namespace feature                       // Open feature namespace.
{


Geometry*
parseBlob (const ByteBuffer& buffer)
  {
	if (!buffer.first)
        return nullptr;
	GeometryBuilder builder;
	auto buildercb = [&](const GeometryParseCommand cmd, const GeometryClass gc, const std::size_t dim, const std::size_t count, const TAK::Engine::Feature::Point2& p)
	{
		return builder(cmd, gc, dim, count, p);
	};
	MemoryInput2 src;
	src.open(buffer.first, buffer.second - buffer.first);

	if(GeometryFactory_fromSpatiaLiteBlob(src, nullptr, buildercb) != TE_Ok)
		throw util::IO_Error(MEM_FN("parseBlob") "Parse error");

	GeometryPtr geom(nullptr, nullptr);
	builder.build(geom);

	return geom.release();
  }


Geometry*
parseBlob (std::istream& strm)
  {
	GeometryBuilder builder;
	auto buildercb = [&](const GeometryParseCommand cmd, const GeometryClass gc, const std::size_t dim, const std::size_t count, const TAK::Engine::Feature::Point2& p)
	{
		return builder(cmd, gc, dim, count, p);
	};
	IStreamInput2 src;
	src.open(strm);

	if(GeometryFactory_fromSpatiaLiteBlob(src, nullptr, buildercb) != TE_Ok)
		throw util::IO_Error(MEM_FN("parseBlob") "Parse error");

	GeometryPtr geom(nullptr, nullptr);
	builder.build(geom);

	return geom.release();
  }


Geometry*
parseWKB (const ByteBuffer& buffer)
  {
	if (!buffer.first)
        return nullptr;
	GeometryBuilder builder;
	auto buildercb = [&](const GeometryParseCommand cmd, const GeometryClass gc, const std::size_t dim, const std::size_t count, const TAK::Engine::Feature::Point2& p)
	{
		return builder(cmd, gc, dim, count, p);
	};
	MemoryInput2 src;
	src.open(buffer.first, buffer.second - buffer.first);

	if(GeometryFactory_fromWkb(src, buildercb) != TE_Ok)
		throw util::IO_Error(MEM_FN("parseWkb") "Parse error");

	GeometryPtr geom(nullptr, nullptr);
	builder.build(geom);

	return geom.release();
  }

Geometry*
parseWKB (std::istream& strm)
  {
	GeometryBuilder builder;
	auto buildercb = [&](const GeometryParseCommand cmd, const GeometryClass gc, const std::size_t dim, const std::size_t count, const TAK::Engine::Feature::Point2& p)
	{
		return builder(cmd, gc, dim, count, p);
	};
	IStreamInput2 src;
	src.open(strm);

	if(GeometryFactory_fromWkb(src, buildercb) != TE_Ok)
		throw util::IO_Error(MEM_FN("parseWkb") "Parse error");

	GeometryPtr geom(nullptr, nullptr);
	builder.build(geom);

	return geom.release();
  }

//
// Parses a Geometry from the supplied string.
//
Geometry*
parseWKT(const char* input)
  {
    throw util::IO_Error("atakmap::feature::parseWKT: Not supported");
  }
}                                       // Close feature namespace.
}                                       // Close atakmap namespace.
