//
// Created by Geo Dev on 2/23/25.
//

#include "formats/mbtiles/VectorTile.h"

#include <cassert>

#include "feature/FeatureCursor2.h"
#include "feature/FeatureCursor2Filter.h"
#include "feature/FeatureDefinition2.h"
#include "formats/ogr/OGRFeatureDataStore.h"
#include "thread/Lock.h"
#include "thread/Mutex.h"

using namespace TAK::Engine::Formats::MBTiles;

using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Formats::OGR;
using namespace TAK::Engine::Thread;
using namespace TAK::Engine::Util;

namespace {
    struct DefaultLayerStyle
    {
        DefaultLayerStyle(const uint32_t color);

        atakmap::feature::BasicStrokeStyle stroke;
        atakmap::feature::BasicFillStyle fill;
        atakmap::feature::BasicPointStyle point;
    };

    class VectorTilesSchemaHandler : public OGRFeatureDataStore::SchemaHandler
    {
    public:
        VectorTilesSchemaHandler(const StyleSheet *ss_, const int lod_ = -1);
    public :
        TAKErr ignoreLayer(bool *value, OGRLayerH layer) const NOTHROWS override;
        bool styleRequiresAttributes() const NOTHROWS override;
        TAKErr getFeatureStyle(StylePtr_const &value, OGRLayerH layer, OGRFeatureH feature, const atakmap::util::AttributeSet &attribs) NOTHROWS override;
        TAKErr getFeatureName(TAK::Engine::Port::String &value, OGRLayerH layer, OGRFeatureH feature, const atakmap::util::AttributeSet &attribs) NOTHROWS override;
        TAKErr getFeatureSetName(TAK::Engine::Port::String &value, OGRLayerH layer) NOTHROWS override;
    private :
        const StyleSheet *ss;
        int lod;
        std::map<GIntBig, StylePtr_const> featureStyles;
        atakmap::feature::BasicStrokeStyle transportationStroke{0xFFFF0000u, 2.f};
        atakmap::feature::BasicStrokeStyle boundaryStroke{0xFF000000u, 1.f};
        const StyleSheet::LayerStyle* sheet{ nullptr };
        OGRLayerH fieldsLayer{ nullptr };
        std::vector<int> fieldIndices_;
        std::map<const char *, std::map<int, int>> fieldIds;
    };

    uint32_t randomLayerColor(const char *layerId, const uint8_t alpha);
    const DefaultLayerStyle &getLayerStyle(const char *layerId);
    void raw_null_deleter(const FeatureDefinition2::RawData *data)
    {
        std::unique_ptr<const FeatureDefinition2::RawData> cleaner(data);
    }
    void raw_geometry_deleter(const FeatureDefinition2::RawData *data)
    {
        std::unique_ptr<const FeatureDefinition2::RawData> cleaner(data);
        auto value = static_cast<const atakmap::feature::Geometry *>(data->object);
        delete value;
    }
    void raw_binary_deleter(const FeatureDefinition2::RawData *data)
    {
        std::unique_ptr<const FeatureDefinition2::RawData> cleaner(data);
        delete [] data->binary.value;
    }
    void raw_text_deleter(const FeatureDefinition2::RawData *data)
    {
        std::unique_ptr<const FeatureDefinition2::RawData> cleaner(data);
        delete [] data->text;
    }
    void raw_style_deleter(const FeatureDefinition2::RawData *data)
    {
        std::unique_ptr<const FeatureDefinition2::RawData> cleaner(data);
        auto value = static_cast<const atakmap::feature::Style *>(data->object);
        delete value;
    }
}

struct VectorTile::VectorFeature : public FeatureDefinition2
{
public :
    VectorFeature() NOTHROWS = default;
    VectorFeature(VectorFeature &&other) NOTHROWS :
        attributes(other.attributes)
    {
        fid = other.fid;
        fsid = other.fsid;
        geometry.coding = other.geometry.coding;
        geometry.value = std::move(other.geometry.value);
        geometry.extrude = other.geometry.extrude;
        geometry.altitudeMode = other.geometry.altitudeMode;
        style.coding = other.style.coding;
        style.value = std::move(other.style.value);
    }
public : // FeatureDefinition2
    TAKErr getRawGeometry(RawData *value) NOTHROWS override;
    GeometryEncoding getGeomCoding() NOTHROWS override;
    AltitudeMode getAltitudeMode() NOTHROWS override;
    double getExtrude() NOTHROWS override;
    TAKErr getName(const char **value) NOTHROWS override;
    StyleEncoding getStyleCoding() NOTHROWS override;
    TAKErr getRawStyle(RawData *value) NOTHROWS override;
    TAKErr getAttributes(const atakmap::util::AttributeSet **value) NOTHROWS override;
    TAKErr get(const Feature2 **feature) NOTHROWS override;
public :
    int64_t fid {FeatureDataStore2::FEATURE_ID_NONE};
    int64_t fsid {FeatureDataStore2::FEATURESET_ID_NONE};
    struct {
        FeatureDefinition2::GeometryEncoding coding {FeatureDefinition2::GeomGeometry};
        std::unique_ptr<FeatureDefinition2::RawData, void(*)(const FeatureDefinition2::RawData *)> value {nullptr, nullptr};
        double extrude {0.0};
        AltitudeMode altitudeMode {TEAM_ClampToGround};
    } geometry;
    struct {
        FeatureDefinition2::StyleEncoding coding {FeatureDefinition2::StyleStyle};
        std::unique_ptr<FeatureDefinition2::RawData, void(*)(const FeatureDefinition2::RawData *)> value {nullptr, nullptr};
    } style;
    atakmap::util::AttributeSet attributes;
};

class VectorTile::FeatureCursorImpl : public FeatureCursor2
{
public :
    FeatureCursorImpl(const std::vector<VectorFeature> &features_, FeatureCursor2FilterPtr &&filter_) NOTHROWS;
public : // FeatureCursor2
    TAKErr getId(int64_t *value) NOTHROWS override;
    TAKErr getFeatureSetId(int64_t *value) NOTHROWS override;
    TAKErr getVersion(int64_t *value) NOTHROWS override;
public : // FeatureDefinition2
    TAKErr getRawGeometry(RawData *value) NOTHROWS override;
    GeometryEncoding getGeomCoding() NOTHROWS override;
    AltitudeMode getAltitudeMode() NOTHROWS override;
    double getExtrude() NOTHROWS override;
    TAKErr getName(const char **value) NOTHROWS override;
    StyleEncoding getStyleCoding() NOTHROWS override;
    TAKErr getRawStyle(RawData *value) NOTHROWS override;
    TAKErr getAttributes(const atakmap::util::AttributeSet **value) NOTHROWS override;
    TAKErr get(const Feature2 **feature) NOTHROWS override;
public: // RowIterator
    TAKErr moveToNext() NOTHROWS override;
private :
    const std::vector<VectorFeature> &features;
    FeatureCursor2FilterPtr filter;
    const VectorFeature *row;
    std::size_t index;
    FeaturePtr_const featureRef;
};

VectorTile::VectorTile(const std::size_t zoom, const std::size_t x, const std::size_t y, const uint8_t *data, const std::size_t dataLen, const std::shared_ptr<StyleSheet> &stylesheet_, const int srid) NOTHROWS :
    ReadOnlyFeatureDataStore2(0),
    stylesheet(stylesheet_),
    available(false)
{
    do {
        const auto ps = TAK::Engine::Port::Platform_systime_millis();
        std::ostringstream os;
        os << "/vsimem/" << (uintptr_t) (void *) data << "/" << zoom << "/" << x << "/" << y;

        const auto gdalMemoryFile = os.str();
        VSILFILE *fpMem = VSIFileFromMemBuffer(gdalMemoryFile.c_str(),
                                               (GByte *) data,
                                               (vsi_l_offset) dataLen, FALSE);
        if (nullptr == fpMem)
            break;

        const int gdalCode = VSIFCloseL(fpMem);

        VectorTilesSchemaHandler schemaHandler(stylesheet.get());
        OGRFeatureDataStore::Options ogrOpts;
        if (srid != 3857)
            ogrOpts.srid = srid;
        ogrOpts.asyncRefresh = false;
        ogrOpts.driver = "MVT";
        ogrOpts.schema = OGRFeatureDataStore::SchemaHandlerPtr(&schemaHandler, Memory_leaker_const<OGRFeatureDataStore::SchemaHandler>);
        if (stylesheet) {
            ogrOpts.extrudeHeightField = stylesheet->getExtrudeHeightKey();
            ogrOpts.extrudeBaseHeightField = stylesheet->getExtrudeBaseHeightKey();
        }
        std::vector<const char *> openOpts;
        openOpts.push_back("CLIP=NO");
        ogrOpts.openOpts.size = openOpts.size();
        ogrOpts.openOpts.value = openOpts.data();
        OGRFeatureDataStore source(gdalMemoryFile.c_str(), ogrOpts);
        source.isAvailable(&available);

        FeatureCursorPtr result(nullptr, nullptr);
        if(source.queryFeatures(result) == TE_Ok) {
            while(result->moveToNext() == TE_Ok) {
                VectorFeature feature;
                result->getId(&feature.fid);
                result->getFeatureSetId(&feature.fsid);
                feature.geometry.coding = result->getGeomCoding();
                {
                    FeatureDefinition2::RawData geom;
                    result->getRawGeometry(&geom);
                    void(*deleter)(const FeatureDefinition2::RawData *) = nullptr;
                    switch(feature.geometry.coding) {
                        case FeatureDefinition2::GeomGeometry :
                            if(geom.object) {
                                geom.object = static_cast<const atakmap::feature::Geometry *>(geom.object)->clone();
                                deleter = raw_geometry_deleter;
                            } else {
                                deleter = raw_null_deleter;
                            }
                            break;
                        case FeatureDefinition2::GeomBlob :
                        case FeatureDefinition2::GeomWkb :
                            if(geom.binary.len && geom.binary.value) {
                                auto binary = new uint8_t[geom.binary.len];
                                memcpy(binary, geom.binary.value, geom.binary.len);
                                geom.binary.value = binary;
                                deleter = raw_binary_deleter;
                            } else {
                                geom.binary.len = 0u;
                                geom.binary.value = nullptr;
                                deleter = raw_null_deleter;
                            }
                            break;
                        case FeatureDefinition2::GeomWkt :
                            if(geom.text) {
                                const auto textLen = strlen(geom.text);
                                auto text = new char[textLen+1u];
                                snprintf(text, textLen+1u, "%s", geom.text);
                                geom.text = text;
                                deleter = raw_text_deleter;
                            } else {
                                deleter = raw_null_deleter;
                            }
                            break;
                        default :
                            feature.geometry.coding = FeatureDefinition2::GeomGeometry;
                            geom.object = nullptr;
                            deleter = raw_null_deleter;
                            break;
                    }
                    feature.geometry.value = std::unique_ptr<FeatureDefinition2::RawData, void(*)(const FeatureDefinition2::RawData *)>(new FeatureDefinition2::RawData(geom), deleter);
                }
                feature.geometry.altitudeMode = result->getAltitudeMode();
                feature.geometry.extrude = result->getExtrude();
                feature.style.coding = result->getStyleCoding();
                {
                    FeatureDefinition2::RawData style;
                    result->getRawStyle(&style);
                    void(*deleter)(const FeatureDefinition2::RawData *) = nullptr;
                    switch(feature.style.coding) {
                        case FeatureDefinition2::StyleStyle :
                            if (style.object) {
                                const auto ostyle = static_cast<const atakmap::feature::Style *>(style.object);
                                style.object = static_cast<const atakmap::feature::Style *>(style.object)->clone();
                                deleter = raw_style_deleter;
                            } else {
                                deleter = raw_null_deleter;
                            }
                            break;
                        case FeatureDefinition2::StyleOgr :
                            if(style.text) {
                                const auto textLen = strlen(style.text);
                                auto text = new char[textLen+1u];
                                snprintf(text, textLen+1u, "%s", style.text);
                                style.text = text;
                                deleter = raw_text_deleter;
                            } else {
                                deleter = raw_null_deleter;
                            }
                            break;
                        default :
                            feature.style.coding = FeatureDefinition2::StyleStyle;
                            style.object = nullptr;
                            deleter = raw_null_deleter;
                            break;
                    }
                    feature.style.value = std::unique_ptr<FeatureDefinition2::RawData, void(*)(const FeatureDefinition2::RawData *)>(new FeatureDefinition2::RawData(style), deleter);
                }
                fidIndex[feature.fid] = features.size();
                features.push_back(std::move(feature));
            }
        }
        VSIUnlink(gdalMemoryFile.c_str());
    } while(false);
}
VectorTile::~VectorTile() NOTHROWS
{}
TAKErr VectorTile::getFeature(FeaturePtr_const &feature, const int64_t fid) NOTHROWS
{
    auto entry = fidIndex.find(fid);
    if(entry == fidIndex.end())
        return TE_InvalidArg;
    return Feature_create(feature,
                   features[entry->second].fid,
                   features[entry->second].fsid,
                   features[entry->second],
                   1LL);
}
TAKErr VectorTile::queryFeatures(FeatureCursorPtr &cursor) NOTHROWS
{
    cursor = FeatureCursorPtr(new FeatureCursorImpl(features, FeatureCursor2FilterPtr(nullptr, nullptr)), Memory_deleter_const<FeatureCursor2, FeatureCursorImpl>);
    return TE_Ok;
}
TAKErr VectorTile::queryFeatures(FeatureCursorPtr &cursor, const FeatureQueryParameters &params) NOTHROWS
{
    // XXX - params filters
//    auto filter = FeatureCursor2Filter::Builder()
//
//            .build();
    cursor = FeatureCursorPtr(new FeatureCursorImpl(features, FeatureCursor2FilterPtr(nullptr, nullptr)), Memory_deleter_const<FeatureCursor2, FeatureCursorImpl>);
    return TE_Ok;
}
TAKErr VectorTile::queryFeaturesCount(int *value) NOTHROWS
{
    *value = (int)features.size();
    return TE_Ok;
}
TAKErr VectorTile::queryFeaturesCount(int *value, const FeatureQueryParameters &params) NOTHROWS
{
    // XXX - filters
    *value = (int)features.size();
    return TE_Ok;
}
TAKErr VectorTile::getFeatureSet(FeatureSetPtr_const &featureSet, const int64_t featureSetId) NOTHROWS
{

    return TE_NotImplemented;
}
TAKErr VectorTile::queryFeatureSets(FeatureSetCursorPtr &cursor) NOTHROWS
{
    return TE_NotImplemented;
}
TAKErr VectorTile::queryFeatureSets(FeatureSetCursorPtr &cursor, const FeatureSetQueryParameters &params) NOTHROWS
{
    return TE_NotImplemented;
}
TAKErr VectorTile::queryFeatureSetsCount(int *value) NOTHROWS
{
    *value = (int)featureSets.size();
    return TE_Ok;
}
TAKErr VectorTile::queryFeatureSetsCount(int *value, const FeatureSetQueryParameters &params) NOTHROWS
{
    // XXX - filtering
    *value = (int)featureSets.size();
    return TE_Ok;
}
TAKErr VectorTile::isFeatureVisible(bool *value, const int64_t fid) NOTHROWS
{
    *value = true;
    return TE_Ok;
}
TAKErr VectorTile::isFeatureSetVisible(bool *value, const int64_t setId) NOTHROWS
{
    *value = true;
    return TE_Ok;
}
TAKErr VectorTile::isAvailable(bool *value) NOTHROWS
{
    *value = available;
    return TE_Ok;
}
TAKErr VectorTile::refresh() NOTHROWS
{
    return TE_Ok;
}
TAKErr VectorTile::getUri(Port::String &value) NOTHROWS
{
    return TE_NotImplemented;
}
TAKErr VectorTile::close() NOTHROWS
{
    return TE_Ok;
}
TAKErr VectorTile::setFeatureVisibleImpl(const int64_t fid, const bool visible) NOTHROWS
{
    return TE_NotImplemented;
}
TAKErr VectorTile::setFeaturesVisibleImpl(const FeatureQueryParameters &params, const bool visible) NOTHROWS
{
    return TE_NotImplemented;
}
TAKErr VectorTile::setFeatureSetVisibleImpl(const int64_t setId, const bool visible) NOTHROWS
{
    return TE_NotImplemented;
}
TAKErr VectorTile::setFeatureSetsVisibleImpl(const FeatureSetQueryParameters &params, const bool visible) NOTHROWS
{
    return TE_NotImplemented;
}

TAKErr VectorTile::VectorFeature::getRawGeometry(FeatureDefinition2::RawData *value) NOTHROWS
{
    *value = *geometry.value;
    return TE_Ok;
}
FeatureDefinition2::GeometryEncoding VectorTile::VectorFeature::getGeomCoding() NOTHROWS
{
    return geometry.coding;
}
AltitudeMode VectorTile::VectorFeature::getAltitudeMode() NOTHROWS
{
    return geometry.altitudeMode;
}
double VectorTile::VectorFeature::getExtrude() NOTHROWS
{
    return geometry.extrude;
}
TAKErr VectorTile::VectorFeature::getName(const char **value) NOTHROWS
{
    value = nullptr;
    return TE_Ok;
}
FeatureDefinition2::StyleEncoding VectorTile::VectorFeature::getStyleCoding() NOTHROWS
{
    return style.coding;
}
TAKErr VectorTile::VectorFeature::getRawStyle(FeatureDefinition2::RawData *value) NOTHROWS
{
    *value = *style.value;
    return TE_Ok;
}
TAKErr VectorTile::VectorFeature::getAttributes(const atakmap::util::AttributeSet **value) NOTHROWS
{
    *value = &attributes;
    return TE_Ok;
}
TAKErr VectorTile::VectorFeature::get(const Feature2 **feature) NOTHROWS
{
    return TE_NotImplemented;
}

VectorTile::FeatureCursorImpl::FeatureCursorImpl(const std::vector<VectorFeature> &features_, FeatureCursor2FilterPtr &&filter_) NOTHROWS :
    features(features_),
    filter(std::move(filter_)),
    row(nullptr),
    index(0u),
    featureRef(nullptr, nullptr)
{}
TAKErr VectorTile::FeatureCursorImpl::getId(int64_t *value) NOTHROWS
{
    if(!row) return TE_IllegalState;
    *value = row->fid;
    return TE_Ok;
}
TAKErr VectorTile::FeatureCursorImpl::getFeatureSetId(int64_t *value) NOTHROWS
{
    if(!row) return TE_IllegalState;
    *value = row->fsid;
    return TE_Ok;
}
TAKErr VectorTile::FeatureCursorImpl::getVersion(int64_t *value) NOTHROWS
{
    *value = 1LL;
    return TE_Ok;
}
TAKErr VectorTile::FeatureCursorImpl::getRawGeometry(RawData *value) NOTHROWS
{
    if(!row) return TE_IllegalState;
    *value = *row->geometry.value;
    return TE_Ok;
}
FeatureDefinition2::GeometryEncoding VectorTile::FeatureCursorImpl::getGeomCoding() NOTHROWS
{
    return row ? row->geometry.coding : FeatureDefinition2::GeomGeometry;
}
AltitudeMode VectorTile::FeatureCursorImpl::getAltitudeMode() NOTHROWS
{
    return row ? row->geometry.altitudeMode : TEAM_ClampToGround;
}
double VectorTile::FeatureCursorImpl::getExtrude() NOTHROWS
{
    return row ? row->geometry.extrude : 0.0;
}
TAKErr VectorTile::FeatureCursorImpl::getName(const char **value) NOTHROWS
{
    if(!row) return TE_IllegalState;
    *value = nullptr;
    return TE_Ok;
}
FeatureDefinition2::StyleEncoding VectorTile::FeatureCursorImpl::getStyleCoding() NOTHROWS
{
    return row ? row->style.coding : FeatureDefinition2::StyleStyle;
}
TAKErr VectorTile::FeatureCursorImpl::getRawStyle(RawData *value) NOTHROWS
{
    if(!row) return TE_IllegalState;
    *value = *row->style.value;
    return TE_Ok;
}
TAKErr VectorTile::FeatureCursorImpl::getAttributes(const atakmap::util::AttributeSet **value) NOTHROWS
{
    if(!row) return TE_IllegalState;
    *value = &row->attributes;
    return TE_Ok;
}
TAKErr VectorTile::FeatureCursorImpl::get(const Feature2 **value) NOTHROWS
{
    if(!row) return TE_IllegalState;
    Feature_create(featureRef, row->fid, row->fsid, *this, 1LL);
    *value = featureRef.get();
    return featureRef ? TE_Ok : TE_Err;
}
TAKErr VectorTile::FeatureCursorImpl::moveToNext() NOTHROWS
{
    do {
        row = nullptr;
        featureRef.reset();
        if (index == features.size())
            return TE_Done;
        row = &features[index++];
        if(filter) {
            bool accept = false;
            filter->accept(&accept, *this);
            if(!accept)
                continue;
        }
        return TE_Ok;
    } while(true);
}

namespace {
    DefaultLayerStyle::DefaultLayerStyle(const uint32_t color) :
            stroke(color, 1.f),
            fill(color&0x80FFFFFFu),
            point(color, 32.f)
    {}

    VectorTilesSchemaHandler::VectorTilesSchemaHandler(const StyleSheet *ss_, const int lod_) :
        ss(ss_),
        lod(lod_)
    {}
    TAKErr VectorTilesSchemaHandler::ignoreLayer(bool *value, OGRLayerH layer) const NOTHROWS
    {
        const char *name = OGR_L_GetName(layer);
        if(!ss) {
            *value = !name;
        } else {
            const StyleSheet::LayerStyle *style;
            *value = !name || ss->getStyle(&style, name) != TE_Ok;
        }
        return TE_Ok;
    }
    bool VectorTilesSchemaHandler::styleRequiresAttributes() const NOTHROWS
    {
        return !!ss;
    }
    TAKErr VectorTilesSchemaHandler::getFeatureStyle(StylePtr_const &value, OGRLayerH layer, OGRFeatureH feature, const atakmap::util::AttributeSet &attribs) NOTHROWS
    {
        const auto &cachedStyle = featureStyles.find(OGR_F_GetFID(feature));
        if(cachedStyle != featureStyles.end()) {
            value = StylePtr_const(cachedStyle->second.get(), Memory_leaker_const<atakmap::feature::Style>);
            return TE_Ok;
        }

        GeometryClass tegc = TEGC_Point;
        switch (OGR_G_GetGeometryType(OGR_F_GetGeometryRef(feature))%1000) {
            case OGRwkbGeometryType::wkbGeometryCollection :
                tegc = TEGC_GeometryCollection;
                break;
            case OGRwkbGeometryType::wkbCircularString :
            case OGRwkbGeometryType::wkbCompoundCurve :
            case OGRwkbGeometryType::wkbCurve :
            case OGRwkbGeometryType::wkbLinearRing :
            case OGRwkbGeometryType::wkbLineString :
            case OGRwkbGeometryType::wkbMultiCurve :
            case OGRwkbGeometryType::wkbMultiLineString :
                tegc = TEGC_LineString;
                break;
            case OGRwkbGeometryType::wkbMultiPoint :
            case OGRwkbGeometryType::wkbPoint :
                tegc = TEGC_Point;
                break;
            case OGRwkbGeometryType::wkbCurvePolygon :
            case OGRwkbGeometryType::wkbMultiPolygon :
            case OGRwkbGeometryType::wkbMultiSurface :
            case OGRwkbGeometryType::wkbPolygon :
            case OGRwkbGeometryType::wkbPolyhedralSurface :
            case OGRwkbGeometryType::wkbSurface :
            case OGRwkbGeometryType::wkbTIN :
            case OGRwkbGeometryType::wkbTriangle:
                tegc = TEGC_Polygon;
                break;
            default :
                break;
        }

        if(!ss) {
            const auto &styles = getLayerStyle(OGR_L_GetName(layer));
            switch(tegc) {
                case TEGC_Point :
                    value = StylePtr_const(&styles.point, Memory_leaker_const<atakmap::feature::Style>);
                    break;
                case TEGC_LineString :
                    value = StylePtr_const(&styles.stroke, Memory_leaker_const<atakmap::feature::Style>);
                    break;
                case TEGC_Polygon :
                    value = StylePtr_const(&styles.fill, Memory_leaker_const<atakmap::feature::Style>);
                    break;
                case TEGC_GeometryCollection :
                    value = StylePtr_const(&styles.stroke, Memory_leaker_const<atakmap::feature::Style>);
                    break;
            }
            return TE_Ok;
        }

        // 478
        auto& fieldIndices = this->fieldIndices_;//fieldIds[name];
        const bool initFieldIndices = fieldsLayer != layer;
        if(fieldsLayer != layer) {
            fieldsLayer = layer;
            sheet = nullptr;
            fieldIndices.clear();


            auto name = OGR_L_GetName(layer);
            if(!name)
                return TE_IllegalState;
            auto e = ss->getStyle(&sheet, name);
            if(e != TE_Ok)
                return TE_InvalidArg;
        } else if(!sheet) {
            return TE_InvalidArg;
        }

#if 1
        const auto code = sheet->getStyle(value, lod, tegc, attribs);
//            if(code == TE_Ok && value) {
//                featureStyles.insert(std::make_pair<GIntBig, StylePtr_const>(OGR_F_GetFID(feature), std::move(StylePtr_const(value->clone(), atakmap::feature::Style::destructStyle))));
//            }
        return code;
#else
        return sheet->getStyle(value, tegc, [&feature, &fieldIndices, initFieldIndices](StyleSheet::Attribute *attr, const char *key, const int schemaId)
        {
            int fieldIndex;
            if(initFieldIndices) {
                fieldIndex = OGR_F_GetFieldIndex(feature, key);
                
                fieldIndices.push_back(schemaId);
                fieldIndices.push_back(fieldIndex);
            } else {
                fieldIndex = -1;
                const int* fi = fieldIndices.data();
                const std::size_t count = fieldIndices.size() / 2u;
                for (std::size_t i = 0u; i < count; i++) {
                    if (fi[i * 2u] == schemaId) {
                        fieldIndex = fi[i * 2 + 1];
                        break;
                    }
                }
            }

            if (fieldIndex < 0) // 230
                return TE_InvalidArg;
            auto field = OGR_F_GetFieldDefnRef(feature, fieldIndex);
            if (!field)
                return TE_InvalidArg;
            auto fieldType = OGR_Fld_GetType(field);
            switch (fieldType) {
            case OGRFieldType::OFTInteger:
                attr->type = atakmap::util::AttributeSet::INT;
                attr->i = OGR_F_GetFieldAsInteger(feature, fieldIndex);
                return TE_Ok;
            case OGRFieldType::OFTInteger64:
                attr->type = atakmap::util::AttributeSet::INT;
                attr->i = (int)OGR_F_GetFieldAsInteger64(feature, fieldIndex);
                return TE_Ok;
            case OGRFieldType::OFTReal:
                attr->type = atakmap::util::AttributeSet::DOUBLE;
                attr->d = OGR_F_GetFieldAsDouble(feature, fieldIndex);
                return TE_Ok;
            case OGRFieldType::OFTString:
                attr->type = atakmap::util::AttributeSet::STRING;
                attr->s = OGR_F_GetFieldAsString(feature, fieldIndex);
                return TE_Ok;
            default :
                return TE_InvalidArg;    
            }
        });
        //return TE_Ok;
#endif
    }
    TAKErr VectorTilesSchemaHandler::getFeatureName(TAK::Engine::Port::String &value, OGRLayerH layer, OGRFeatureH feature, const atakmap::util::AttributeSet &attribs) NOTHROWS
    {
        value = nullptr;
        return TE_Ok;
    }
    TAKErr VectorTilesSchemaHandler::getFeatureSetName(TAK::Engine::Port::String &value, OGRLayerH layer) NOTHROWS
    {
        value = OGR_L_GetName(layer);
        return TE_Ok;
    }

    uint32_t randomLayerColor(const char *layerId, const uint8_t alpha) {
        // hue
        const char *blue[5] = {"water", "ocean", "lake", "sea", "river"};
        const char *pink[3] = {"state", "country", "place"};
        const char *orange[4] = {"road", "highway", "transport", "streets"};
        const char *monochrome[4] = {"contour", "building", "earth", "boundary"};
        const char *yellow[2] = {"contour", "landuse"};
        const char *green[7] = {"wood", "forest", "park", "landcover", "land", "natural", "trail"};
    
        uint32_t hue = 0u;
    
        auto checkHue = [layerId, &hue](const char **val, const std::size_t lim, const uint32_t v)
        {
            for(std::size_t i = 0u; i < lim; i++) {
                if(strstr(layerId, val[i])) {
                    hue = v;
                    break;
                }
            }
        };
    
        checkHue(blue, sizeof(blue)/sizeof(const char *), 0x0000FFu);
        checkHue(pink, sizeof(pink)/sizeof(const char *), 0xFFC0CBu);
        checkHue(orange, sizeof(orange)/sizeof(const char *), 0xFF8C00u);
        checkHue(monochrome, sizeof(monochrome)/sizeof(const char *), 0x808080u);
        checkHue(yellow, sizeof(yellow)/sizeof(const char *), 0xFFFF00u);
        checkHue(green, sizeof(green)/sizeof(const char *), 0x008000u);
    
        // luminosity
    
        int8_t lum = 0;
        if(strstr(layerId, "building")) {
            lum = -1;
        }
        if (strstr(layerId, "earth")) {
            lum = 1;
        }
    
        uint8_t rgb[3] = {0, 0, 0};
        for (std::size_t i = 0u; i < strlen(layerId); i++) {
            const auto v = layerId[i];
            rgb[v % 3] = (rgb[i % 3] + (13*(v%13))) % 12;
        }
        auto r = 4 + rgb[0];
        auto g = 4 + rgb[1];
        auto b = 4 + rgb[2];
        r = (r * 16) + r;
        g = (g * 16) + g;
        b = (b * 16) + b;
    
        if(!hue)
            hue = (r<<16u)|(g<<8u)|b;
        if(lum) {
            r = (uint8_t) ((hue >> 16u) & 0xFFu);
            g = (uint8_t) ((hue >> 8u) & 0xFFu);
            b = (uint8_t) (hue & 0xFFu);
            if (lum > 0) {
                r = (uint8_t) std::min(((uint32_t)r << (uint8_t) lum), 0xFFu);
                g = (uint8_t) std::min(((uint32_t)g << (uint8_t) lum), 0xFFu);
                b = (uint8_t) std::min(((uint32_t)b << (uint8_t) lum), 0xFFu);
            } else if (lum < 0) {
                lum = abs(lum);
                r = (uint8_t) std::min(((uint32_t)r >> (uint8_t) lum), 0xFFu);
                g = (uint8_t) std::min(((uint32_t)g >> (uint8_t) lum), 0xFFu);
                b = (uint8_t) std::min(((uint32_t)b >> (uint8_t) lum), 0xFFu);
            }
            hue = (r<<16u)|(g<<8u)|b;
        }
        return (alpha<<24u)|hue;
    }
    
    const DefaultLayerStyle &getLayerStyle(const char *layerId)
    {
        static Mutex m;
        Lock l(m);
        do {
            static std::map<std::string, DefaultLayerStyle > layerStyles;
            auto ls = layerStyles.find(layerId);
            if (ls != layerStyles.end())
                return ls->second;
            const uint32_t c = randomLayerColor(layerId, 0xFFu);
            layerStyles.insert(std::make_pair(std::string(layerId), DefaultLayerStyle(c)));
        } while(true);
    }
}
