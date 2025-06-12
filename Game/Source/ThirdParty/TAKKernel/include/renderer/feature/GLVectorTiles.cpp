#include "GLVectorTiles.h"

#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

#include <gdal.h>

#include "feature/FeatureSetDatabase.h"
#include "formats/ogr/OGR_FeatureDataSource2.h"
#include "formats/ogr/OGRFeatureDataStore.h"
#include "math/Point2.h"
#include "math/Rectangle2.h"
#include "port/STLListAdapter.h"
#include "port/STLVectorAdapter.h"
#include "raster/tilematrix/TileClientFactory.h"
#include "raster/tilematrix/TileContainerFactory.h"
#include "raster/tilematrix/TileProxy.h"
#include "renderer/BitmapFactory2.h"
#include "renderer/GLES20FixedPipeline.h"
#include "renderer/GLText2.h"
#include "renderer/core/GLGlobeBase.h"
#include "renderer/core/GLLabelManager.h"
#include "renderer/core/controls/SurfaceRendererControl.h"
#include "renderer/feature/GLBatchGeometryRenderer4.h"
#include "renderer/feature/GLBatchGeometryFeatureDataStoreRenderer3.h"
#include "renderer/feature/GLGeometryBatchBuilder.h"
#include "renderer/raster/TileCacheControl.h"
#include "renderer/raster/TileClientControl.h"
#include "thread/Monitor.h"
#include "util/ConfigOptions.h"
#include "util/DataInput2.h"
#include "util/PoolAllocator.h"
#include "util/ProtocolHandler.h"
#include "util/StringMap.h"

using namespace TAK::Engine::Renderer::Core;

using namespace TAK::Engine::Core;
using namespace TAK::Engine::Math;
using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Formats::OGR;
using namespace TAK::Engine::Raster::TileMatrix;
using namespace TAK::Engine::Renderer;
using namespace TAK::Engine::Renderer::Core::Controls;
using namespace TAK::Engine::Renderer::Feature;
using namespace TAK::Engine::Renderer::Raster;
using namespace TAK::Engine::Thread;
using namespace TAK::Engine::Util;

namespace
{
    struct DefaultLayerStyle
    {
        DefaultLayerStyle(const uint32_t color) :
            stroke(color, 1.f),
            fill(color&0x80FFFFFFu),
            point(color, 32.f)
        {}

        atakmap::feature::BasicStrokeStyle stroke;
        atakmap::feature::BasicFillStyle fill;
        atakmap::feature::BasicPointStyle point;
    };

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
        for (std::size_t i = 0; i < strlen(layerId); i++) {
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

    class VectorTilesSchemaHandler : public OGRFeatureDataStore::SchemaHandler
    {
    private :
        const StyleSheet *ss;
        int lod;
        std::map<GIntBig, StylePtr_const> featureStyles;
    public:
        VectorTilesSchemaHandler(const StyleSheet *ss_, const int lod_) :
            ss(ss_),
            lod(lod_)
        {}
    public :
        TAKErr ignoreLayer(bool *value, OGRLayerH layer) const NOTHROWS override
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
        bool styleRequiresAttributes() const NOTHROWS override
        {
            return !!ss;
        }
        TAKErr getFeatureStyle(StylePtr_const &value, OGRLayerH layer, OGRFeatureH feature, const atakmap::util::AttributeSet &attribs) NOTHROWS override
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
        const StyleSheet::LayerStyle* sheet{ nullptr };
        OGRLayerH fieldsLayer{ nullptr };
        std::vector<int> fieldIndices_;
        std::map<const char *, std::map<int, int>> fieldIds;
        TAKErr getFeatureName(TAK::Engine::Port::String &value, OGRLayerH layer, OGRFeatureH feature, const atakmap::util::AttributeSet &attribs) NOTHROWS override
        {
            value = nullptr;
            return TE_Ok;
        }
        TAKErr getFeatureSetName(TAK::Engine::Port::String &value, OGRLayerH layer) NOTHROWS override
        {
            value = OGR_L_GetName(layer);
            return TE_Ok;
        }
    private :
        atakmap::feature::BasicStrokeStyle transportationStroke{0xFFFF0000u, 2.f};
        atakmap::feature::BasicStrokeStyle boundaryStroke{0xFF000000u, 1.f};
    };

    class GLTileFeatures : public GLBatchGeometryFeatureDataStoreRenderer3
    {
    public :
        typedef std::unique_ptr<GLTileFeatures, void(*)(const GLTileFeatures *)> Ptr;
    public :
        GLTileFeatures(RenderContext &context, FeatureDataStore2Ptr &&subject, const GLGlobeBase::State &fetchState_, const std::string &membuf_, std::unique_ptr<const uint8_t, void(*)(const uint8_t *)> blob_, const bool dynamicLod_, const GLBatchGeometryFeatureDataStoreRenderer3::Options &opts) NOTHROWS :
            GLBatchGeometryFeatureDataStoreRenderer3(context, *subject, opts),
            prefetched(false),
            features(std::move(subject)),
            fetchState(fetchState_),
            membuf(membuf_),
            blob(std::move(blob_))
        {
            lod.dynamic = dynamicLod_;
            lod.adjust = -3;

            check_surface_intersect_ = false;

            // deep copy terrain tiles
            if(need_render_tiles_)
                fetchState.renderTiles.own();
        }
        ~GLTileFeatures() NOTHROWS override
        {
            VSIUnlink(membuf.c_str());
        }
    public :
        void prefetch(const GLGlobeBase *view, const GLGlobeBase::State &state) NOTHROWS
        {
            if(prefetched)
                return;
            if(view) {
                void *surfaceControl = nullptr;
                if(view->getControl(&surfaceControl, SurfaceRendererControl_getType()) == TE_Ok)
                    surface_ctrl_ = static_cast<SurfaceRendererControl *>(surfaceControl);
                initImpl(*view);
            }
            initialized_ = !lod.dynamic;
            context_ = &view->context;
            target_state_ = state;
            // deep copy terrain tiles
            if(need_render_tiles_)
                target_state_.renderTiles.own();
            prepared_state_ = state;
            lod.current = atakmap::raster::osm::OSMUtils::mapnikTileLevel(state.drawMapResolution);
            lod.pending = lod.current;
            GLBatchGeometryFeatureDataStoreRenderer3::createQueryContext(queryContext);
            query(*queryContext, state);
            updateRenderableLists(*queryContext);
            prefetched = true;
        }
        void releaseLabels() NOTHROWS
        {
            *labelRenderPump = -1;
        }
        FeatureDataStore2 &getDataStore() const NOTHROWS
        {
            return *features;
        }
        void initImpl(const GLGlobeBase &view) NOTHROWS override
        {
            GLBatchGeometryFeatureDataStoreRenderer3::initImpl(view);
            if(prefetched) {
                target_state_ = fetchState;
                prepared_state_ = target_state_;
                invalid_ = false;
            }
        }

        void drawImpl(const GLGlobeBase &view, const int renderPass) NOTHROWS override
        {
            Monitor::Lock lock(monitor_);
            GLBatchGeometryFeatureDataStoreRenderer3::drawImpl(view, renderPass);

            // align target state to fetch state
            target_state_.westBound = fetchState.westBound;
            target_state_.southBound = fetchState.southBound;
            target_state_.eastBound = fetchState.eastBound;
            target_state_.northBound = fetchState.northBound;
            target_state_.drawTilt = fetchState.drawTilt; // XXX -
            target_state_.drawRotation = fetchState.drawRotation;
            target_state_.drawLat = fetchState.drawLat;
            target_state_.drawLng = fetchState.drawLng;
            target_state_.left = fetchState.left;
            target_state_.right = fetchState.right;
            target_state_.bottom = fetchState.bottom;
            target_state_.top = fetchState.top;
            target_state_.drawMapResolution = atakmap::raster::osm::OSMUtils::mapnikTileResolution(lod.current);
            target_state_.drawMapScale = atakmap::core::AtakMapView_getMapScale(target_state_.scene.displayDpi, target_state_.drawMapResolution);
        }

        bool shouldQuery() NOTHROWS override
        {
            const int preparedLod = atakmap::raster::osm::OSMUtils::mapnikTileLevel(prepared_state_.drawMapResolution);
            return (lod.dynamic && (invalid_ || preparedLod != lod.current)) || (!lod.dynamic && !prefetched);
        }
        TAKErr query(QueryContext &ctx, const GLGlobeBase::State &state_) NOTHROWS override
        {
            if(prefetched && !lod.dynamic) return TE_Done;
#if 0
            if(debug) {
                static auto initTime = TAK::Engine::Port::Platform_systime_millis();
                const auto upTime = TAK::Engine::Port::Platform_systime_millis()-initTime;
                Logger_log(TELL_Info, "GLTileFeatures[%s]::query up=%u gsd: %.3lf, lod: %d, {aoi: {%lf,%lf %lf,%lf}}", membuf.c_str(), (unsigned)upTime, state_.drawMapResolution, atakmap::raster::osm::OSMUtils::mapnikTileLevel(state_.drawMapResolution), state_.northBound, state_.westBound, state_.southBound, state_.eastBound);
            }
#endif
            return GLBatchGeometryFeatureDataStoreRenderer3::query(ctx, state_);
        }
        void release() NOTHROWS override
        {
            prefetched = false;
            GLBatchGeometryFeatureDataStoreRenderer3::release();
        }
    private :
        static void releaseAndDelete(void *opaque) NOTHROWS
        {
            auto impl = static_cast<GLTileFeatures *>(opaque);
            if(impl)
                impl->release();
        }
    public :
        static void deleter(const GLTileFeatures *impl) NOTHROWS
        {
            // XXX - queue on GL thread
            std::unique_ptr<void, void(*)(const void *)> opaque(const_cast<GLTileFeatures *>(impl), Memory_void_deleter_const<GLTileFeatures>);
            impl->context_->queueEvent(releaseAndDelete, std::move(opaque));
        }
    public :
        bool prefetched;
        FeatureDataStore2Ptr features;
        QueryContextPtr queryContext{nullptr, nullptr};
        GLGlobeBase::State fetchState;
        std::string membuf;
        std::unique_ptr<const uint8_t, void(*)(const uint8_t *)> blob;
        struct {
            int adjust {0};
            int pending {-1};
            int current {-1};
            int pump {-1};
            bool dynamic {false};
        } lod;

        template <class> friend class GLTileData;
    };

    template<class QuadNode>
    TAK::Engine::Math::Point2<std::size_t> getTileIndex(const QuadNode &node) NOTHROWS
    {
        TAK::Engine::Math::Point2<std::size_t> index;
        index.x = (std::size_t)((((node.bounds.proj.minX+node.bounds.proj.maxX)/2.0)-node.service.tileMatrix.origin.x)/(node.service.tileMatrix.z0TileWidth/(1u<<node.level)));
        index.y = (std::size_t)((node.service.tileMatrix.origin.y-(((node.bounds.proj.minY+node.bounds.proj.maxY)/2.0)))/(node.service.tileMatrix.z0TileHeight/(1u<<node.level)));
        index.z = node.level;
        return index;
    }
    template<class QuadNode>
    class GLTileData : public GLMapRenderable2
    {
    public :
        GLTileData(RenderContext &context_, const QuadNode &node, const uint32_t rgba_, const char *msg_ = nullptr, GLTileFeatures::Ptr &&features_ = GLTileFeatures::Ptr (nullptr, nullptr)) NOTHROWS :
            bounds(node.bounds.wgs84),
            rgba(rgba_),
            index(getTileIndex(node)),
            msg(msg_),
            glfeatures(std::move(features_)),
            derived(false)
        {}
        GLTileData(RenderContext &context_, const QuadNode &node, const uint32_t rgba_, const GLTileData<QuadNode> &deriveFrom) NOTHROWS :
                bounds(node.bounds.wgs84),
                rgba(rgba_),
                index(getTileIndex(node)),
                msg(nullptr),
                glfeatures(deriveFrom.glfeatures),
                derived(true)
        {}
    public :
        void draw(const GLGlobeBase& view, const int renderPass) NOTHROWS override
        {
            if(!(renderPass&getRenderPass()))
                return;

            float fb[8];
            GeoPoint2 crns[4u];
            crns[0].latitude = bounds.maxY; crns[0].longitude = bounds.minX;
            crns[1].latitude = bounds.maxY; crns[1].longitude = bounds.maxX;
            crns[2].latitude = bounds.minY; crns[2].longitude = bounds.maxX;
            crns[3].latitude = bounds.minY; crns[3].longitude = bounds.minX;

            for(std::size_t i = 0; i < 4; i++) {
                TAK::Engine::Math::Point2<float> crn;
                view.renderPass->scene.forward(&crn, crns[i]);
                fb[i*2] = crn.x;
                fb[i*2+1] = crn.y;
            }

            Envelope2 checkBounds(bounds);
            checkBounds.minX += (checkBounds.maxX-checkBounds.minX)/512.0;
            checkBounds.minY += (checkBounds.maxX-checkBounds.minX)/512.0;
            checkBounds.maxX -= (checkBounds.maxY-checkBounds.minY)/512.0;
            checkBounds.maxY -= (checkBounds.maxY-checkBounds.minY)/512.0;
            const bool isect = Rectangle2_intersects(
                    checkBounds.minX, checkBounds.minY,
                    checkBounds.maxX, checkBounds.maxY,
                    view.renderPass->westBound, view.renderPass->southBound,
                    view.renderPass->eastBound, view.renderPass->northBound);
            const bool isSprites = !!(renderPass&GLGlobeBase::Sprites);
            const bool isSurface = !!(renderPass&GLGlobeBase::Surface);

            if(glfeatures && glfeatures->lod.dynamic && isSurface) {
                if(isect) {
                    const auto lod = std::max(atakmap::raster::osm::OSMUtils::mapnikTileLevel(view.renderPass->drawMapResolution)+glfeatures->lod.adjust, 0);
                    if (glfeatures->lod.pump != view.renderPass->renderPump) {
                        glfeatures->lod.pending = lod;
                        glfeatures->lod.pump = view.renderPass->renderPump;
                    } else if(lod > glfeatures->lod.pending) {
                            glfeatures->lod.pending = lod;
                    }
                }
                if(glfeatures->lod.pump == view.renderPass->renderPump && !view.multiPartPass) {
                    // flip
                    glfeatures->lod.current = glfeatures->lod.pending;
                }
            }
            // XXX - render features
            if(glfeatures && (isSprites || (isSurface && isect))) {
                if (derived && isSurface) {
                    glScissor((GLint) fb[6], (GLint) fb[7], (GLsizei) (fb[2] - fb[6]),
                              (GLsizei) (fb[3] - fb[7]));
                    glEnable(GL_SCISSOR_TEST);
                }
                glfeatures->draw(view, renderPass);
                if (derived && isSurface) {
                    glDisable(GL_SCISSOR_TEST);
                }
            }
#if 0
            if(!isSurface)
                return;
            if(!isect)
                return;
            float r = (rgba>>24u) / 255.f;
            float g = ((rgba>>16u)&0xFFu) / 255.f;
            float b = ((rgba>>8u)&0xFFu) / 255.f;
            float a = (rgba&0xFFu) / 255.f;

            TAK::Engine::Math::Point2<float> xyz;
            view.renderPass->scene.forward(&xyz, GeoPoint2((bounds.minY+bounds.maxY)/2.0, bounds.minX + (bounds.maxX-bounds.minX)/64));

            TextFormatParams txtParams(18.f);
            auto gltext = GLText2_intern(txtParams);
            std::ostringstream strm;
            strm << "Tile " << index.z << "/" << index.x << "/" << index.y;
            if(msg)
                strm << "\n" << msg;

            auto &gles = *atakmap::renderer::GLES20FixedPipeline::getInstance();

            // XXX - draw bounding box
            gles.glColor4f(r, g, b, a);
            gles.glLineWidth(2.f);

            gles.glEnableClientState(atakmap::renderer::GLES20FixedPipeline::CS_GL_VERTEX_ARRAY);
            gles.glVertexPointer(2, GL_FLOAT, 0, fb);
            gles.glDrawArrays(GL_LINE_LOOP, 0, 4);
            gles.glDisableClientState(atakmap::renderer::GLES20FixedPipeline::CS_GL_VERTEX_ARRAY);

            gles.glPushMatrix();
            gles.glTranslatef(xyz.x, xyz.y, 0.f);
            gltext->draw(strm.str().c_str(), r, g, b, a);
            gles.glPopMatrix();
#endif
        }
        void release() NOTHROWS override
        {
            glfeatures.reset();
        }
        int getRenderPass() NOTHROWS override { return GLGlobeBase::Surface|GLGlobeBase::Sprites; }
        void start() NOTHROWS override { if(glfeatures) glfeatures->start(); }
        void stop() NOTHROWS override { if(glfeatures) glfeatures->stop(); }
    public :
        Envelope2 bounds;
        TAK::Engine::Math::Point2<std::size_t> index;
        uint32_t rgba;
        TAK::Engine::Port::String msg;
        std::shared_ptr<GLTileFeatures> glfeatures;
        bool derived;
    };

    template<class T>
    T getTilesMatrix(const TileMatrix &tiles) NOTHROWS
    {
        std::vector<TileMatrix::ZoomLevel> zoom;
        TAK::Engine::Port::STLVectorAdapter<TileMatrix::ZoomLevel> zoom_a(zoom);
        tiles.getZoomLevel(zoom_a);
        const std::size_t maxZoom = zoom.empty() ? 19u : (std::size_t)zoom.back().level;
        switch(tiles.getSRID()) {
            case 3395 :
                return TiledGlobe_matrix3395<T>(maxZoom);
            case 3857 :
                return TiledGlobe_matrix3857<T>(maxZoom);
            case 4326 :
                return TiledGlobe_matrix4326<T>(maxZoom);
            default :
                return TiledGlobe_matrix3857<T>(maxZoom);
        }
    }
}

GLVectorTiles::GLVectorTiles(RenderContext &context_, const std::shared_ptr<TileClient> &tiles_, const bool overlay_, const std::shared_ptr<StyleSheet> &stylesheet_) NOTHROWS :
    GLVectorTiles(context_, std::static_pointer_cast<TileMatrix>(tiles_), overlay_, stylesheet_)
{
   tiles.client = tiles_;
#if 0
    //const char *config = "/sdcard/Download/rbt-cultural-vector.json";
    const char *cachePath = nullptr;
#ifndef _MSC_VER
    const char *configPath = "/sdcard/Download/swar-topo-vector2.json";
    cachePath = "/sdcard/Download/vectortilescache.sqlite";
    //const char *sspath = "/sdcard/Download/osm-bright-style.json";
    const char *sspath = "asset:/style/bright/style.json";
    const bool isUnitTest = false;
#else
    const char *configPath = "C:\\Users\\TAK Developer\\Downloads\\swar-topo-vector.xml";
    cachePath = "C:\\Users\\TAK Developer\\Downloads\\vectortilescache.sqlite";
    //const char *sspath = "C:\\Users\\TAK Developer\\Downloads\\osm-bright-style.json";
    const char *sspath = "C:\\Users\\TAK Developer\\Downloads\\osm-liberty-gh-pages\\style.json";
    const bool isUnitTest = !(&context_);
#endif
    do {
        if (tiles.client) {
            Logger_log(TELL_Info, "GLVectorTiles::<init> use ctor client");
            break;
        }
        TileClientPtr dc(nullptr, nullptr);
        TileClientFactory_create(dc, configPath, nullptr, nullptr);
        if(!dc)
            break;
        if (cachePath) {
            // XXX -
            //if(IO_exists(cachePath)) IO_delete(cachePath);

            do {
                TileContainerPtr cache(nullptr, nullptr);
                TileContainerFactory_openOrCreateCompatibleContainer(cache, cachePath, dc.get(), nullptr);
                if (!cache)
                    break;
                //std::unique_ptr<TileProxy> tileProxy(new TileProxy(std::move(client), std::move(cache)));
                bool fetchOnMiss = isUnitTest;

                std::unique_ptr<TileProxy> tileProxy(
                        new TileProxy(std::move(dc), nullptr, 1, std::move(cache), nullptr, 1,
                                      fetchOnMiss));
                Control ctrl;
                tileProxy->getControl(&ctrl, TileCacheControl_getType());
                if (ctrl.value) {
                    cacheUpdateForwarder.reset(new CacheUpdateForwarder(*this));
                    auto &cacheControl = *static_cast<TileCacheControl *>(ctrl.value);
                    cacheControl.setOnTileUpdateListener(cacheUpdateForwarder.get());
                }

                tileProxy->getControl(&ctrl, TileClientControl_getType());
                if (ctrl.value) {
                    auto &clientControl = *static_cast<TileClientControl *>(ctrl.value);
                    //clientControl.setOfflineOnlyMode(true);
                }
                dc = TileClientPtr(tileProxy.release(),
                                             Memory_deleter_const<TileClient, TileProxy>);
            } while (false);
            tiles.client = std::move(dc);
            tiles.value = std::static_pointer_cast<TileMatrix>(tiles.client);
        }
    } while(false);
#endif
}
GLVectorTiles::GLVectorTiles(RenderContext &context_, const std::shared_ptr<TileContainer> &tiles_, const bool overlay_, const std::shared_ptr<StyleSheet> &stylesheet_) NOTHROWS :
        GLVectorTiles(context_, std::static_pointer_cast<TileMatrix>(tiles_), overlay_, stylesheet_)
{
    tiles.container = tiles_;
}
GLVectorTiles::GLVectorTiles(RenderContext &context_, const std::shared_ptr<TileMatrix> &tiles_, const bool overlay_, const std::shared_ptr<StyleSheet> &stylesheet_) NOTHROWS :
    impl(getTilesMatrix<GLTiledGlobe::TileMatrix>(*tiles_), 64u, 8u),
    context(context_),
    overlay(overlay_),
    stylesheet(stylesheet_)
{
    tiles.value = tiles_;
    if(tiles.value) {
        std::vector<TileMatrix::ZoomLevel> zoom;
        TAK::Engine::Port::STLVectorAdapter<TileMatrix::ZoomLevel> zoom_a(zoom);
        tiles.value->getZoomLevel(zoom_a);
        if(!zoom.empty())
            maxZoom = zoom.back().level;
    }

    //impl.debug = true;
    impl.sparse = true;

    impl.shouldRecurse = [](bool &stats, const std::vector<Envelope2> &filter, const GLTiledGlobe::QuadNode &node, const bool self)
    {
        for(const auto &mbb : filter) {
            if(Rectangle2_intersects(
                    mbb.minX, mbb.minY, mbb.maxX, mbb.maxY,
                    node.bounds.wgs84.minX, node.bounds.wgs84.minY, node.bounds.wgs84.maxX, node.bounds.wgs84.maxY)) {

                const double fdx = (mbb.maxX-mbb.minX);
                const double ndx = (node.bounds.wgs84.maxX-node.bounds.wgs84.minX);
                if(ndx/fdx >= 2.0)
                    return true;
            }
        }
        return false;
    };
    impl.fetchTileData = [&](const GLTiledGlobe::QuadNode &node, const GLTiledGlobe::CollectHints &hints)
    {
        GLTileFeatures::Ptr glfeatures(nullptr, nullptr);
        std::shared_ptr<GLMapRenderable2> value;
        auto tileIndex = getTileIndex(node);
        std::string msg;
        unsigned parse = 0u;
        unsigned prefetch = 0u;
        std::size_t dataLen = 0u;
        if(tiles.value) {
            std::unique_ptr<const uint8_t, void(*)(const uint8_t *)> dataPtr(nullptr, nullptr);
            if(tiles.value->getTileData(dataPtr, &dataLen, tileIndex.z, tileIndex.x, tileIndex.y) == TE_Ok) {
                int nfeatures = -1;
                do {
                    const auto ps = TAK::Engine::Port::Platform_systime_millis();
                    std::ostringstream os;
                    os << "/vsimem/" << (uintptr_t) (void *) dataPtr.get() << "/" << tileIndex.z << "/" << tileIndex.x << "/" << tileIndex.y;

                    const auto gdalMemoryFile = os.str();
                    VSILFILE *fpMem = VSIFileFromMemBuffer(gdalMemoryFile.c_str(),
                                                           (GByte *) dataPtr.get(),
                                                           (vsi_l_offset) dataLen, FALSE);
                    if (nullptr == fpMem)
                        break;

                    int gdalCode = VSIFCloseL(fpMem);

                    const bool dynamicLod = stylesheet && (tileIndex.z == maxZoom);
                    OGRFeatureDataStore::Options ogrOpts;
                    if(tiles.value->getSRID() != 3857)
                        ogrOpts.srid = tiles.value->getSRID();
                    ogrOpts.asyncRefresh = false;
                    ogrOpts.driver = "MVT";
                    ogrOpts.schema = OGRFeatureDataStore::SchemaHandlerPtr(new VectorTilesSchemaHandler(stylesheet.get(), dynamicLod ? -1 : (int)tileIndex.z), Memory_deleter_const<OGRFeatureDataStore::SchemaHandler, VectorTilesSchemaHandler>);
                    if(stylesheet) {
                        ogrOpts.extrudeHeightField = stylesheet->getExtrudeHeightKey();
                        ogrOpts.extrudeBaseHeightField = stylesheet->getExtrudeBaseHeightKey();
                    }
                    FeatureDataStore2Ptr features(
                        new OGRFeatureDataStore(
                            gdalMemoryFile.c_str(),
                            ogrOpts),
                        Memory_deleter_const<FeatureDataStore2, OGRFeatureDataStore>);
                    auto &ds = *features;

                    const auto pe = TAK::Engine::Port::Platform_systime_millis();

                    parse = (unsigned)(pe-ps);

                    const auto fs = TAK::Engine::Port::Platform_systime_millis();
                    GLGlobeBase::State state;
                    state.westBound = node.bounds.wgs84.minX;
                    state.southBound = node.bounds.wgs84.minY;
                    state.eastBound = node.bounds.wgs84.maxX;
                    state.northBound = node.bounds.wgs84.maxY;
                    state.drawSrid = 4978;
                    state.drawTilt = 1.0; // seed with tilt
                    state.drawLat = (state.southBound+state.northBound) / 2.0;
                    state.drawLng = (state.westBound+state.eastBound) / 2.0;
                    state.left = 0;
                    state.right = 256;
                    state.bottom = 0;
                    state.top = 256;
                    state.drawMapResolution = atakmap::raster::osm::OSMUtils::mapnikTileResolution((int)tileIndex.z);
                    state.drawMapScale = atakmap::core::AtakMapView_getMapScale(96.0, state.drawMapResolution);

                    GLBatchGeometryFeatureDataStoreRenderer3::Options opts;
                    opts.spritesheet = spritesheet;
                    opts.defaultIconOnLoadFailure = false;
                    opts.simplificationEnabled = false;
                    opts.antiMeridianHandlingEnabled = false;
                    opts.touchLabelVisibility = true;
                    opts.labelOnlyPrecedence = false;
                    opts.tessellationDisabled = true;
                    opts.skipNoStyleFeatures = true;
                    std::unique_ptr<GLTileFeatures> gltf(new GLTileFeatures(context_, std::move(features), state, gdalMemoryFile, std::move(dataPtr), dynamicLod, opts));
                    gltf->prefetch(this->view, state);
                    bool prefetched = false;
                    ds.isAvailable(&prefetched);
                    if(!prefetched) {
                        // no data -- return empty value
                        return value;
                    }
                    const auto fe = TAK::Engine::Port::Platform_systime_millis();
                    prefetch = (unsigned)(fe-fs);
                    glfeatures = GLTileFeatures::Ptr(gltf.release(), GLTileFeatures::deleter);
                } while(false);

                std::ostringstream strm;
                strm << "Downloaded " << dataLen << " bytes" << "\n" << "Features: " << nfeatures;
                msg = strm.str();
            } else {
                msg = "Download Failed";
                // no data -- return empty value
                return value;
            }

        } else {
            msg = "No Client";
        }
        value.reset(new GLTileData<GLTiledGlobe::QuadNode>(context_, node, 0x00FF00FFu, msg.c_str(), std::move(glfeatures)));
        return value;
    };
    impl.deriveTileData = [&context_](const GLTiledGlobe::QuadNode &node, const GLTiledGlobe::CollectHints &hints, const GLTiledGlobe::DeriveSource &from)
    {
        std::shared_ptr<GLMapRenderable2> value;
        value.reset(new GLTileData<GLTiledGlobe::QuadNode>(context_, node, 0xFFFF00FFu, static_cast<GLTileData<GLTiledGlobe::QuadNode> &>(*from.tile)));
        return value;
    };
    impl.emptyTileData = [&context_](const GLTiledGlobe::QuadNode &node)
    {
        std::shared_ptr<GLMapRenderable2> value;
        value.reset(new GLTileData<GLTiledGlobe::QuadNode>(context_, node, 0xFF0000FFu));
        return value;
    };
    impl.hasValue = [](const std::shared_ptr<GLMapRenderable2> &blob) { return !!blob; };
    impl.shouldCollect = [](const std::vector<Envelope2> &filter, const GLTiledGlobe::QuadNode &node)
    {
        for(const auto &mbb : filter) {
            if(Rectangle2_intersects(
                    mbb.minX, mbb.minY, mbb.maxX, mbb.maxY,
                    node.bounds.wgs84.minX, node.bounds.wgs84.minY, node.bounds.wgs84.maxX, node.bounds.wgs84.maxY)) {

                return true;
            }
        }
        return false;
    };
    impl.shouldFetch = impl.shouldCollect;
    impl.clearValue = [](std::shared_ptr<GLMapRenderable2> &blob)
    {
        blob.reset();
    };
    impl.queryFilterEquals = [](const std::vector<Envelope2> &a, const std::vector<Envelope2> &b)
    {
        const auto count = a.size();
        if(count != b.size())
            return false;
        for(auto i = 0u; i < count; i++) {
            const auto &ae = a[i];
            const auto &be = b[i];
            if(ae.minX != be.minX) return false;
            if(ae.minY != be.minY) return false;
            if(ae.maxX != be.maxX) return false;
            if(ae.maxY != be.maxY) return false;
        }
        return true;
    };

// optional
//                    std::function<void(GLTiledGlobe::QuadNode &node, const std::shared_ptr<GLMapRenderable2> &value, const bool derived)> setValue;
//                    std::function<bool(CollectStatistics &stats, const CollectHints &hints, const std::vector<Envelope2> &filter, const std::function<void(const std::shared_ptr<GLTiledGlobe::QuadNode> &)> &collector)> fillRequest;
//                    std::function<FetchQueueSort(const std::vector<Envelope2> &queryFilter)> sortFetchQueue;
//                    std::function<CollectResultsSort(const std::vector<Envelope2> &queryFilter)> sortCollectResults;
#if 0
    auto bms = TAK::Engine::Port::Platform_systime_millis();
    int cnt = 0;
    while(isUnitTest)
    {
        if (cnt++ > 5)  break;
        TAK::Engine::Math::Point2<std::size_t> tileIndex(150, 192, 9);
        std::unique_ptr<const uint8_t, void(*)(const uint8_t*)> dataPtr(nullptr, nullptr);
        std::size_t dataLen;
        if(tiles.value->getTileData(dataPtr, &dataLen, tileIndex.z, tileIndex.x, tileIndex.y) == TE_Ok) {
            int nfeatures = -1;
            do {
                const auto ps = TAK::Engine::Port::Platform_systime_millis();
                std::ostringstream os;
                os << "/vsimem/" << (uintptr_t) (void *) dataPtr.get() << "/" << tileIndex.z << "/" << tileIndex.x << "/" << tileIndex.y;

                const auto gdalMemoryFile = os.str();
                VSILFILE *fpMem = VSIFileFromMemBuffer(gdalMemoryFile.c_str(),
                                                        (GByte *) dataPtr.get(),
                                                        (vsi_l_offset) dataLen, FALSE);
                if (nullptr == fpMem)
                    break;

                int gdalCode = VSIFCloseL(fpMem);

                OGRFeatureDataStore::SchemaHandlerPtr schema(new VectorTilesSchemaHandler(ss.empty() ? nullptr: &ss, (int)tileIndex.z), Memory_deleter_const<OGRFeatureDataStore::SchemaHandler, VectorTilesSchemaHandler>);
                FeatureDataStore2Ptr features(new OGRFeatureDataStore(gdalMemoryFile.c_str(), nullptr, false, std::move(schema)), Memory_deleter_const<FeatureDataStore2, OGRFeatureDataStore>);
                auto &ds = *features;

                const auto pe = TAK::Engine::Port::Platform_systime_millis();

                auto parse = (unsigned)(pe-ps);

                const auto fs = TAK::Engine::Port::Platform_systime_millis();
                FeatureCursorPtr result(nullptr, nullptr);
                ds.queryFeatures(result);
                while(result->moveToNext() == TE_Ok) {
                    FeatureDefinition2::RawData d;
                    //result->getRawGeometry(&d);
                    result->getRawStyle(&d);
                    d.object = nullptr;
                    //const atakmap::util::AttributeSet *a;
                    //result->getAttributes(&a);
                    nfeatures++;
                }

                const auto fe = TAK::Engine::Port::Platform_systime_millis();
                auto prefetch = (unsigned)(fe-fs);

                std::ostringstream sprefetch;
                sprefetch << prefetch;
                ConfigOptions_setOption("internalprefetch", sprefetch.str().c_str());

                Logger_log(TELL_Info, "Fetched tile %u/%u/%u prefetch=%ums nfeatures=%d", tileIndex.z, tileIndex.x, tileIndex.y, prefetch, nfeatures);

            } while(false);

            std::ostringstream strm;
            strm << "Downloaded " << dataLen << " bytes" << "\n" << "Features: " << nfeatures;
        } else {
            // no data -- return empty value
            Logger_log(TELL_Info, "Fetched tile %u/%u/%u prefetch data not available", tileIndex.z, tileIndex.x, tileIndex.y);
        }
        if (isUnitTest) break;
    }
    auto bme = TAK::Engine::Port::Platform_systime_millis();
    auto bmt = (bme - bms);
    std::ostringstream sbmt;
    sbmt << bmt;
    ConfigOptions_setOption("internalparse", sbmt.str().c_str());
    cnt = 0;
#endif
}
void GLVectorTiles::draw(const GLGlobeBase& view_, const int renderPass) NOTHROWS
{
    if(!this->view)
        this->view = &view_;
    // initialize spritesheet atlas
    if(!spritesheet) {
        std::unique_ptr<GLTextureAtlas2, void(*)(const GLTextureAtlas2 *)> atlas(nullptr, nullptr);
        std::vector<std::string> uris_storage;
        std::vector<const char *> uris;
        std::vector<TAK::Engine::Math::Rectangle2<float>> regions;
        BitmapPtr_const bitmap(nullptr, nullptr);
        if(!stylesheet) {
            std::vector<TAK::Engine::Port::String> paths;
            TAK::Engine::Port::String defaultIconUri;
            ConfigOptions_getOption(defaultIconUri, "defaultIconUri");
            if(defaultIconUri)
                paths.push_back(defaultIconUri);
            paths.push_back("asset:/icons/reference_point.png");
            for(const auto &iconPath : paths) {
                DataInput2Ptr bitmapStream(nullptr, nullptr);
                if(ProtocolHandler_handleURI(bitmapStream, iconPath) != TE_Ok)
                    continue;
                BitmapPtr icon(nullptr, nullptr);
                if(BitmapFactory2_decode(icon, *bitmapStream, nullptr) != TE_Ok)
                    continue;
                bitmap = std::move(icon);
                break;
            }
            if(!bitmap) {
                Bitmap2 basicPoint(4u, 4u, Bitmap2::RGBA32);
                auto data = reinterpret_cast<uint32_t *>(basicPoint.getData());
                data[5u] = 0xFFFFFFFFu;
                data[6u] = 0xFFFFFFFFu;
                data[9u] = 0xFFFFFFFFu;
                data[10u] = 0xFFFFFFFFu;
                bitmap = BitmapPtr_const(new Bitmap2(basicPoint), Memory_deleter_const<Bitmap2>);
            }
            uris.push_back("");
            regions.push_back(Rectangle2<float>(0.f, 0.f, (float)bitmap->getWidth(), (float)bitmap->getHeight()));
        } else if(stylesheet->hasSpriteSheet()) {
            const std::size_t numEntries = stylesheet->getNumSpriteMappings();
            uris.reserve(numEntries);
            uris_storage.reserve(numEntries);
            regions.reserve(numEntries);
            for(std::size_t i = 0u; i < numEntries; i++) {
                TAK::Engine::Port::String mappingUri;
                Rectangle2<float> region;
                if(stylesheet->getSpriteMapping(mappingUri, region, i) != TE_Ok)
                    continue;
                uris_storage.push_back(mappingUri.get());
                uris.push_back(uris_storage[i].c_str());
                regions.push_back(region);
            }
            const Bitmap2 *icons = nullptr;
            if(stylesheet->getSpriteSheet(&icons) == TE_Ok)
                bitmap = BitmapPtr_const(icons, Memory_leaker_const<Bitmap2>);
        }

        if(bitmap) {
            GLTextureAtlas_create(atlas, *bitmap, uris.data(), regions.data(),uris.size());
            spritesheet = std::move(atlas);
        }
    }
    GLfloat clearColor[4u];
    glGetFloatv(GL_COLOR_CLEAR_VALUE, clearColor);
    std::list<std::shared_ptr<GLMapRenderable2>> renderables;
    TAK::Engine::Port::STLListAdapter<std::shared_ptr<GLMapRenderable2>> renderables_a(renderables);
    if(renderPass&GLGlobeBase::Sprites) {
        std::vector<Envelope2> filter;
        filter.reserve(view_.renderPasses[0].renderTiles.count);
        for (std::size_t i = 0u; i < view_.renderPasses[0].renderTiles.count; i++)
            filter.push_back(view_.renderPasses[0].renderTiles.value[i].tile->aabb_wgs84);
        std::sort(filter.begin(), filter.end(), [](const Envelope2 &a, const Envelope2 &b) {
            if (a.maxY > b.maxY) return true;
            else if (a.maxY < b.maxY) return false;
            else if (a.minX < b.minX) return true;
            else if (a.minX > b.minX) return false;
            else if (a.minY < b.minY) return true; // larger extent => lower zoom level
            else if (a.minY > b.minY) return false; // smaller extent => higher zoom level
            else return false; // ==
        });
        impl.lock(renderables_a, filter);
        for(auto it = renderables.begin(); it != renderables.end(); ) {
            bool isect = false;
            // XXX - frustum cull
            if(*it) {
                for(const auto &mbb : filter) {
                    const auto rmbb = static_cast<GLTileData<GLTiledGlobe::QuadNode> &>(*(*it)).bounds;
                    isect |= atakmap::math::Rectangle<double>::intersects(mbb.minX, mbb.minY, mbb.maxX, mbb.maxY, rmbb.minX, rmbb.minY, rmbb.maxX, rmbb.maxY);
                    if(isect)
                        break;
                }
            }
            if(!isect)
                it = renderables.erase(it);
            else
                it++;
        }
    } else {
        const uint32_t bg = stylesheet ? stylesheet->getBackground() : 0xFFEFEFEFu;
        if((renderPass&GLGlobeBase::Surface) && !overlay && (bg&0xFF000000u)) {
            const float r = ((bg>>16u)&0xFFu) / 255.f;
            const float g = ((bg>>8u)&0xFFu) / 255.f;
            const float b = (bg&0xFFu) / 255.f;
            const float a = ((bg>>24u)&0xFFu) / 255.f;
            glClearColor(r, g, b, a);
            glClear(GL_COLOR_BUFFER_BIT);
        }
        impl.lock(renderables_a);
    }
    for(auto &renderable : renderables) {
        if(renderable)
            renderable->draw(view_, renderPass);
    }
    glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
}
void GLVectorTiles::release() NOTHROWS
{
    if(view) {
        auto *lblmgr = view->getLabelManager();
        if(lblmgr) {
            std::list<std::shared_ptr<GLMapRenderable2>> renderables;
            TAK::Engine::Port::STLListAdapter<std::shared_ptr<GLMapRenderable2>> renderables_a(renderables);
            impl.lock(renderables_a);
            for(auto &it : renderables) {
                if(!it)
                    continue;
                auto glfeatures = static_cast<GLTileData<GLTiledGlobe::QuadNode> &>(*it).glfeatures;
                if(!glfeatures)
                    continue;
                glfeatures->releaseLabels();
            }
            lblmgr->invalidate();
        }
    }
}
int GLVectorTiles::getRenderPass() NOTHROWS
{
    return GLGlobeBase::Surface|GLGlobeBase::Sprites;
}
void GLVectorTiles::start() NOTHROWS
{
    impl.start();
}
void GLVectorTiles::stop() NOTHROWS
{
    impl.stop();
}
TAKErr GLVectorTiles::hitTest(TAK::Engine::Port::Collection<std::shared_ptr<const Feature2>> &features, const float screenX, const float screenY, const GeoPoint2 &touch, const double resolution, const float radius, const std::size_t limit_) NOTHROWS
{
    std::list<std::shared_ptr<GLMapRenderable2>> renderables;
    TAK::Engine::Port::STLListAdapter<std::shared_ptr<GLMapRenderable2>> renderables_a(renderables);
    impl.lock(renderables_a);
    for(auto &it : renderables) {
        if(!it)
            continue;
        auto &tile = static_cast<GLTileData<GLTiledGlobe::QuadNode> &>(*it);
        if(!atakmap::math::Rectangle<double>::contains(tile.bounds.minX, tile.bounds.minY, tile.bounds.maxX, tile.bounds.maxY, touch.longitude, touch.latitude))
            continue;
        auto glfeatures = tile.glfeatures;
        if(!glfeatures)
            continue;
        auto limit = limit_;
        if(limit && features.size()) {
            limit -= features.size();
        }
        std::vector<int64_t> fids;
        TAK::Engine::Port::STLVectorAdapter<int64_t> fids_a(fids);
        glfeatures->hitTest2(fids_a, screenX, screenY, touch, resolution, radius, limit_);
        if(!fids.empty()) {
            for(const auto &fid : fids) {
                FeaturePtr_const f(nullptr, nullptr);
                glfeatures->getDataStore().getFeature(f, fid);
                if(!f)
                    continue;
                features.add(std::move(f));
            }
        }
        if(limit_ && features.size() >= limit_)
            break;
    }
    return TE_Ok;
}

GLVectorTiles::CacheUpdateForwarder::CacheUpdateForwarder(GLVectorTiles &owner_) NOTHROWS :
        owner(owner_)
{}
void GLVectorTiles::CacheUpdateForwarder::onTileUpdated(const std::size_t level, const std::size_t x, const std::size_t y) NOTHROWS
{
    Logger_log(TELL_Info, " GLVectorTiles::CacheUpdateForwarder::onTileUpdated(%u, %u, %u)", level, x, y);
    owner.impl.sourceContentUpdated(level, x, y);
}
