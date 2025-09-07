//
// Created by Geo Dev on 2/24/25.
//

#include "feature/FeatureCursor2Filter.h"

#include "feature/GeometryFactory.h"
#include "feature/FeatureDefinition2.h"
#include "feature/LegacyAdapters.h"
#include "feature/ParseGeometry.h"
#include "feature/SpatialCalculator.h"
#include "feature/SpatialCalculator2.h"
#include "math/Rectangle2.h"

using namespace TAK::Engine::Feature;

using namespace TAK::Engine::Util;

namespace
{
    class BuilderFilter : public FeatureCursor2Filter
    {
    public :
        BuilderFilter() NOTHROWS;
    public :
        TAKErr accept(bool *value, TAK::Engine::Feature::FeatureCursor2 &feature) NOTHROWS override;
    public :
        struct {
            std::set<atakmap::feature::StyleClass> accept;
            std::set<atakmap::feature::StyleClass> reject;
        } styles;
        struct {
            struct {
                Geometry2Ptr_const ptr{nullptr, nullptr};
                int64_t handle{0LL};
            } geom;
            Envelope2 mbb;
            bool valid {false};
            std::shared_ptr<atakmap::feature::SpatialCalculator> calculator;
        } spatialFilter;
        bool extrudeOnly {false};
    };
}

FeatureCursor2Filter::~FeatureCursor2Filter() NOTHROWS {}

FeatureCursor2Filter::Builder &FeatureCursor2Filter::Builder::setExtrudeOnly() NOTHROWS
{
    extrudeOnly = true;
    return *this;
}
FeatureCursor2Filter::Builder &FeatureCursor2Filter::Builder::setSpatialFilter(const Envelope2 &filter) NOTHROWS
{
    spatialFilter.mbb = filter;
    spatialFilter.geom.reset();
    spatialFilter.valid = true;
    return *this;
}
FeatureCursor2Filter::Builder &FeatureCursor2Filter::Builder::setSpatialFilter(const Geometry2 &filter) NOTHROWS
{
    filter.getEnvelope(&spatialFilter.mbb);
    Geometry_clone(spatialFilter.geom, filter);
    spatialFilter.valid = true;
    return *this;
}
FeatureCursor2Filter::Builder &FeatureCursor2Filter::Builder::setStyleFilter(const atakmap::feature::StyleClass *accept, const std::size_t acceptCount, const atakmap::feature::StyleClass *reject, const std::size_t rejectCount) NOTHROWS
{
    styles.accept.clear();
    for(std::size_t i = 0u; i < acceptCount; i++)
        styles.accept.insert(accept[i]);
    styles.reject.clear();
    for(std::size_t i = 0u; i < rejectCount; i++)
        styles.reject.insert(reject[i]);
    return *this;
}
FeatureCursor2FilterPtr FeatureCursor2Filter::Builder::build() NOTHROWS
{
    std::unique_ptr<BuilderFilter> filter(new BuilderFilter());
    filter->styles.accept = styles.accept;
    filter->styles.reject = styles.reject;
    filter->extrudeOnly = extrudeOnly;
    filter->spatialFilter.mbb = spatialFilter.mbb;
    if(filter->spatialFilter.geom.ptr)
        Geometry_clone(filter->spatialFilter.geom.ptr, *spatialFilter.geom);
    filter->spatialFilter.valid = spatialFilter.valid;
    return FeatureCursor2FilterPtr(filter.release(), Memory_deleter_const<FeatureCursor2Filter, BuilderFilter>);
}

namespace
{
    bool acceptStyle(const atakmap::feature::Style *style, const std::set<atakmap::feature::StyleClass> &accept, const std::set<atakmap::feature::StyleClass> &reject) NOTHROWS
    {
        if(!style)
            return false;
        const bool checkParent =
                accept.find(atakmap::feature::TESC_LevelOfDetailStyle) != accept.end() ||
                reject.find(atakmap::feature::TESC_LevelOfDetailStyle) != reject.end() ||
                accept.find(atakmap::feature::TESC_CompositeStyle) != accept.end() ||
                reject.find(atakmap::feature::TESC_CompositeStyle) != reject.end();
        const uint8_t hasReject = !reject.empty() ? 0x2u : 0x0u;
        const uint8_t doneMask = hasReject ? hasReject : 0x1u;
        uint8_t matches = 0u;
        atakmap::feature::Style_recurse(*style, [&](const atakmap::feature::Style &ss, const atakmap::feature::Style *parent)
        {
            if(checkParent && parent) {
                const auto pc = parent->getClass();
                if(accept.find(pc) != accept.end())
                    matches |= 0x1u;
                if(hasReject && reject.find(pc) != reject.end())
                    matches |= 0x2u;
            }
            if(!(doneMask&matches)) {
                const auto sc = ss.getClass();
                if(accept.find(sc) != accept.end())
                    matches |= 0x1u;
                if(hasReject && reject.find(sc) != reject.end())
                    matches |= 0x2u;
            }
            return (doneMask&matches) ? TE_Done : TE_Ok;
        });
        if(matches&hasReject)
            return false; // flagged for reject
        else
            return !!matches || (accept.empty() && hasReject);
    }
    BuilderFilter::BuilderFilter() NOTHROWS
    {}
    TAKErr BuilderFilter::accept(bool *value, TAK::Engine::Feature::FeatureCursor2 &feature) NOTHROWS
    {
        TAKErr code(TE_Ok);
        do {
            if (!(styles.accept.empty() && styles.reject.empty())) {
                FeatureDefinition2::RawData rowStyle;
                code = feature.getRawStyle(&rowStyle);
                TE_CHECKBREAK_CODE(code);
                StylePtr ogrStyle(nullptr, nullptr);
                switch(feature.getStyleCoding()) {
                    case FeatureDefinition2::StyleOgr :
                        if(rowStyle.text) {
                            code = atakmap::feature::Style_parseStyle(ogrStyle, rowStyle.text);
                            rowStyle.object = ogrStyle.get();
                            TE_CHECKBREAK_CODE(code);
                        } else {
                            rowStyle.object = nullptr;
                        }
                    case FeatureDefinition2::StyleStyle :
                        break;
                    default :
                        *value = false;
                        return TE_IllegalState;
                }
                if(!acceptStyle(static_cast<const atakmap::feature::Style *>(rowStyle.object), styles.accept, styles.reject)) {
                    *value = false;
                    break;
                }
            }
            if (spatialFilter.valid) {
                FeatureDefinition2::RawData rowGeom;
                code = feature.getRawGeometry(&rowGeom);
                TE_CHECKBREAK_CODE(code);
                if(spatialFilter.geom.ptr) {
                    if(!spatialFilter.geom.handle) {
                        spatialFilter.calculator.reset(new atakmap::feature::SpatialCalculator());
                        GeometryPtr lgeom(nullptr, nullptr);
                        LegacyAdapters_adapt(lgeom, *spatialFilter.geom.ptr);
                        spatialFilter.geom.handle = spatialFilter.calculator->createGeometry(lgeom.get());
                    }

                    struct SpatialCalculatorBatch {
                        SpatialCalculatorBatch(atakmap::feature::SpatialCalculator &c_) : c(c_) { c.beginBatch(); }
                        ~SpatialCalculatorBatch() { c.endBatch(false); }
                        atakmap::feature::SpatialCalculator &c;
                    } batch(*spatialFilter.calculator);

                    int64_t rowHandle = 0LL;
                    switch(feature.getGeomCoding()) {
                        case FeatureDefinition2::GeomGeometry :
                            if(rowGeom.object)
                                rowHandle = spatialFilter.calculator->createGeometry(static_cast<const atakmap::feature::Geometry *>(rowGeom.object));
                            break;
                        case FeatureDefinition2::GeomWkb :
                            if(rowGeom.binary.value && rowGeom.binary.len)
                                rowHandle = spatialFilter.calculator->createGeometryFromWkb(atakmap::feature::SpatialCalculator::Blob (rowGeom.binary.value, rowGeom.binary.value+rowGeom.binary.len));
                            break;
                        case FeatureDefinition2::GeomBlob :
                            if(rowGeom.binary.value && rowGeom.binary.len)
                                rowHandle = spatialFilter.calculator->createGeometryFromBlob(atakmap::feature::SpatialCalculator::Blob (rowGeom.binary.value, rowGeom.binary.value+rowGeom.binary.len));
                            break;
                        case FeatureDefinition2::GeomWkt :
                            if(rowGeom.text)
                                rowHandle = spatialFilter.calculator->createGeometryFromWkt(rowGeom.text);
                            break;
                        default :
                            break;
                    }
                    if(!rowHandle || !spatialFilter.calculator->intersects(spatialFilter.geom.handle, rowHandle)) {
                        *value = false;
                        break;
                    }
                } else { // MBB
                    struct {
                        Envelope2 value;
                        bool valid{false};
                    } rowBounds;
                    std::unique_ptr<const atakmap::feature::Geometry> wktGeom;
                    switch(feature.getGeomCoding()) {
                        case FeatureDefinition2::GeomWkt :
                            if(rowGeom.text) {
                                try {
                                    wktGeom.reset(atakmap::feature::parseWKT(rowGeom.text));
                                    rowGeom.object = wktGeom.get();
                                } catch(...) {
                                    break;
                                }

                                // fall-through to process as geometry
                            } else {
                                break;
                            }
                        case FeatureDefinition2::GeomGeometry :
                            if(rowGeom.object) {
                                try {
                                    auto e = static_cast<const atakmap::feature::Geometry *>(rowGeom.object)->getEnvelope();
                                    rowBounds.value.minX = e.minX;
                                    rowBounds.value.minY = e.minY;
                                    rowBounds.value.maxX = e.maxX;
                                    rowBounds.value.maxY = e.maxY;
                                    rowBounds.valid = true;
                                } catch(...) {}
                            }
                            break;
                        case FeatureDefinition2::GeomWkb :
                            if(rowGeom.binary.value && rowGeom.binary.len) {
                                Geometry2Ptr wkbGeom(nullptr, nullptr);
                                code = GeometryFactory_fromWkb(wkbGeom, rowGeom.binary.value, rowGeom.binary.len);
                                TE_CHECKBREAK_CODE(code);
                                code = wkbGeom->getEnvelope(&rowBounds.value);
                                TE_CHECKBREAK_CODE(code);
                                rowBounds.valid = true;
                            }
                            break;
                        case FeatureDefinition2::GeomBlob :
                            if(rowGeom.binary.value && rowGeom.binary.len) {
                                Geometry2Ptr blobGeom(nullptr, nullptr);
                                code = GeometryFactory_fromSpatiaLiteBlob(blobGeom, rowGeom.binary.value, rowGeom.binary.len);
                                TE_CHECKBREAK_CODE(code);
                                code = blobGeom->getEnvelope(&rowBounds.value);
                                TE_CHECKBREAK_CODE(code);
                                rowBounds.valid = true;
                            }
                            break;
                        default :
                            break;
                    }
                    if(!rowBounds.valid || !SpatialCalculator_intersects(spatialFilter.mbb, rowBounds.value)) {
                        *value = false;
                        break;
                    }
                }
            }
            if (extrudeOnly && feature.getExtrude() == 0.0) {
                *value = false;
                break;
            }
            *value = true;
        } while(false);
        return code;
    }
}

