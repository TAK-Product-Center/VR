#include "GLVectorTiles.h"

#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

#include <gdal.h>

#include "feature/FeatureSetDatabase.h"
#include "formats/mbtiles/VectorTile.h"
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
using namespace TAK::Engine::Formats::MBTiles;
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
    class GLTileFeatures : public GLBatchGeometryFeatureDataStoreRenderer3
    {
    public :
        typedef std::unique_ptr<GLTileFeatures, void(*)(const GLTileFeatures *)> Ptr;
    public :
        GLTileFeatures(RenderContext &context, const std::shared_ptr<FeatureDataStore2> &subject, const GLGlobeBase::State &fetchState_, const bool staticContent_, const GLBatchGeometryFeatureDataStoreRenderer3::Options &opts) NOTHROWS :
            GLBatchGeometryFeatureDataStoreRenderer3(context, *subject, opts),
            prefetched(false),
            features(subject),
            fetchState(fetchState_),
            staticContent(staticContent_)
        {
            lod.dynamic = !staticContent;
            lod.adjust = -2;

            check_surface_intersect_ = false;

            // deep copy terrain tiles
            if(need_render_tiles_)
                fetchState.renderTiles.own();

            std::vector<atakmap::feature::StyleClass> dynamicStyleTypes;
            dynamicStyleTypes.push_back(atakmap::feature::TESC_MeshPointStyle);
            dynamicStyleTypes.push_back(atakmap::feature::TESC_BasicPointStyle);
            dynamicStyleTypes.push_back(atakmap::feature::TESC_IconPointStyle);
            dynamicStyleTypes.push_back(atakmap::feature::TESC_LabelPointStyle);
            if(staticContent) {
                queryFilter = FeatureCursor2Filter::Builder()
                            .setStyleFilter(nullptr, 0u, dynamicStyleTypes.data(), dynamicStyleTypes.size())
                        .build();
            } else {
                queryFilter = FeatureCursor2Filter::Builder()
                            .setStyleFilter(dynamicStyleTypes.data(), dynamicStyleTypes.size(), nullptr, 0u)
                        .build();
            }
        }
        ~GLTileFeatures() NOTHROWS override {}
    public :
        void prefetch(const GLGlobeBase *view, const GLGlobeBase::State &state) NOTHROWS
        {
            if(prefetched || lod.dynamic)
                return;
            if(view) {
                void *surfaceControl = nullptr;
                if(view->getControl(&surfaceControl, SurfaceRendererControl_getType()) == TE_Ok)
                    surface_ctrl_ = static_cast<SurfaceRendererControl *>(surfaceControl);
                initImpl(*view);
                context_ = &view->context;
            }
            initialized_ = false;
            target_state_ = state;
            // deep copy terrain tiles
            if(need_render_tiles_)
                target_state_.renderTiles.own();
            prepared_state_ = state;
            lod.current = std::max(atakmap::raster::osm::OSMUtils::mapnikTileLeveld(state.drawMapResolution, 0.0)+lod.adjust, 0.0);
            lod.pending = lod.current;
            GLBatchGeometryFeatureDataStoreRenderer3::createQueryContext(queryContext);
            query(*queryContext, state);
            updateRenderableLists(*queryContext);
            prefetched = true;
            prefetchTime = lastQuery;
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
        void setColor(const uint32_t color_) NOTHROWS
        {
            color = color_;
        }
        void drawImpl(const GLGlobeBase &view, const int renderPass) NOTHROWS override
        {
            Monitor::Lock lock(monitor_);
            GLBatchGeometryFeatureDataStoreRenderer3::drawImpl(view, renderPass);

            // align target state to fetch state
            if(!lod.dynamic) {
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
            }
            target_state_.drawMapResolution = atakmap::raster::osm::OSMUtils::mapnikTileResolution(lod.current, 0.0);
            target_state_.drawMapScale = atakmap::core::AtakMapView_getMapScale(target_state_.scene.displayDpi, target_state_.drawMapResolution);
        }

        TAKErr createQueryContext(QueryContextPtr &value) NOTHROWS override
        {
            queryThreadId = Thread_currentThreadID();
            return GLBatchGeometryFeatureDataStoreRenderer3::createQueryContext(value);
        }

        bool shouldQuery() NOTHROWS override
        {
            if(lod.dynamic || Thread_currentThreadID() == queryThreadId)
                return GLBatchGeometryFeatureDataStoreRenderer3::shouldQuery();

            const double preparedLod = atakmap::raster::osm::OSMUtils::mapnikTileLevel(prepared_state_.drawMapResolution, 0.0);
            // XXX - quantize LOD
            return ((invalid_ || (int)preparedLod != (int)lod.current || fabs(preparedLod-lod.current) > 0.25));
        }
        TAKErr query(QueryContext &ctx, const GLGlobeBase::State &state_) NOTHROWS override
        {
#if 0
            if(debug) {
                static auto initTime = TAK::Engine::Port::Platform_systime_millis();
                const auto upTime = TAK::Engine::Port::Platform_systime_millis()-initTime;
                Logger_log(TELL_Info, "GLTileFeatures[%s]::query up=%u gsd: %.3lf, lod: %d, {aoi: {%lf,%lf %lf,%lf}}", membuf.c_str(), (unsigned)upTime, state_.drawMapResolution, atakmap::raster::osm::OSMUtils::mapnikTileLevel(state_.drawMapResolution), state_.northBound, state_.westBound, state_.southBound, state_.eastBound);
            }
#endif
            const auto ss = TAK::Engine::Port::Platform_systime_millis();
            const auto code = GLBatchGeometryFeatureDataStoreRenderer3::query(ctx, state_);
            const auto ee = TAK::Engine::Port::Platform_systime_millis();
            lastQuery = (unsigned)(ee-ss);
            return code;
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
            if(impl->context_)
                impl->context_->queueEvent(releaseAndDelete, std::move(opaque));
        }
    public :
        bool prefetched;
        std::shared_ptr<FeatureDataStore2> features;
        QueryContextPtr queryContext{nullptr, nullptr};
        GLGlobeBase::State fetchState;
        struct {
            int adjust {0};
            double pending {-1};
            double current {-1};
            int pump {-1};
            bool dynamic {false};
        } lod;
        unsigned lastQuery{0u};
        unsigned prefetchTime{0u};
        bool staticContent;
        ThreadID queryThreadId;

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
        GLTileData(RenderContext &context_, const QuadNode &node, const uint32_t rgba_, const char *msg_ = nullptr, const std::shared_ptr<GLTileFeatures> &sfeatures_ = std::shared_ptr<GLTileFeatures>(), const std::shared_ptr<GLTileFeatures> &dfeatures_ = std::shared_ptr<GLTileFeatures>()) NOTHROWS :
            bounds(node.bounds.wgs84),
            rgba(rgba_),
            index(getTileIndex(node)),
            msg(msg_),
            derived(false)
        {
            glfeatures.s = sfeatures_;
            glfeatures.d = dfeatures_;
        }
        GLTileData(RenderContext &context_, const QuadNode &node, const uint32_t rgba_, const GLTileData<QuadNode> &deriveFrom) NOTHROWS :
            GLTileData(context_, node, rgba_, nullptr, deriveFrom.glfeatures.s, deriveFrom.glfeatures.d)
        {
            derived = true;
        }
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

            // collect the greatest LOD requested during the current surface pass
            auto updateLod = [&view, isSurface, isect](const std::shared_ptr<GLTileFeatures> &gltf)
            {
                if(!gltf)
                    return;
                if(!gltf->lod.dynamic && isSurface) {
                    if(isect) {
                        const auto lod = std::max(atakmap::raster::osm::OSMUtils::mapnikTileLevel(view.renderPass->drawMapResolution)+gltf->lod.adjust, 0);
                        if (gltf->lod.pump != view.renderPass->renderPump) {
                            gltf->lod.pending = lod;
                            gltf->lod.pump = view.renderPass->renderPump;
                        } else if(lod > gltf->lod.pending) {
                            gltf->lod.pending = lod;
                        }
                    }
                    if(gltf->lod.pump == view.renderPass->renderPump && !view.multiPartPass) {
                        // flip
                        gltf->lod.current = gltf->lod.pending;
                    }
                } else if(gltf->lod.dynamic && !isSurface) {
                    // XXX - continuous zoom level
                    gltf->lod.current = gltf->lod.pending = std::max(atakmap::raster::osm::OSMUtils::mapnikTileLevel(view.renderPass->drawMapResolution)+gltf->lod.adjust, 0);
                }
            };
            updateLod(glfeatures.s);
            updateLod(glfeatures.d);

            // XXX - render features
            if((glfeatures.s || glfeatures.d) && (isSprites || (isSurface && isect))) {
                if (isSurface) {
                    glScissor((GLint) fb[6]-1, (GLint) fb[7]-1, (GLsizei) (ceil(fb[2]) - (GLint)fb[6])+2u,
                              (GLsizei) (ceil(fb[3]) - (GLint)fb[7])+2u);
                    glEnable(GL_SCISSOR_TEST);
                }
                if(glfeatures.s) glfeatures.s->draw(view, renderPass);
                if(glfeatures.d) glfeatures.d->draw(view, renderPass);
                if (isSurface) {
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
            txtParams.outline = true;
            auto gltext = GLText2_intern(txtParams);
            std::ostringstream strm;
            strm << "Tile " << index.z << "/" << index.x << "/" << index.y;
            if(glfeatures.s)
                strm << "\nS lod {d=" << glfeatures.s->lod.dynamic << " c=" << glfeatures.s->lod.current << " p=" << glfeatures.s->lod.pending << " a=" << glfeatures.s->lod.adjust << "} last query: " << glfeatures.s->lastQuery << "ms prefetch " << glfeatures.s->prefetchTime << "ms";
            if(glfeatures.d)
                strm << "\nD lod {d=" << glfeatures.d->lod.dynamic << " c=" << glfeatures.d->lod.current << " p=" << glfeatures.d->lod.pending << " a=" << glfeatures.d->lod.adjust << "} last query: " << glfeatures.d->lastQuery << "ms prefetch " << glfeatures.d->prefetchTime << "ms";
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
            glfeatures.s.reset();
            glfeatures.d.reset();
        }
        int getRenderPass() NOTHROWS override { return GLGlobeBase::Surface|GLGlobeBase::Sprites; }
        void start() NOTHROWS override {
            if(glfeatures.s) glfeatures.s->start();
            if(glfeatures.d) glfeatures.d->start();
        }
        void stop() NOTHROWS override {
            if(glfeatures.s) glfeatures.s->stop();
            if(glfeatures.d) glfeatures.d->stop();
        }
    public :
        Envelope2 bounds;
        TAK::Engine::Math::Point2<std::size_t> index;
        uint32_t rgba;
        TAK::Engine::Port::String msg;
        struct {
            std::shared_ptr<GLTileFeatures> s;
            std::shared_ptr<GLTileFeatures> d;
        } glfeatures;
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

    class SpriteSheetAnnotator : public BitmapFactory2
    {
    public :
        SpriteSheetAnnotator(const StyleSheet &styleSheet) NOTHROWS;
    public :
        TAKErr decode(BitmapPtr &result, const char *bitmapFilePath, const BitmapDecodeOptions *opts) NOTHROWS override;
    private :
        struct {
            std::map<std::string, TAK::Engine::Math::Rectangle2<float>> entries;
            TAK::Engine::Renderer::BitmapPtr_const bitmap{nullptr, nullptr};
        } spriteSheet;
        TextFormat2Ptr defaultText {nullptr, nullptr};
    };
}

GLVectorTiles::GLVectorTiles(RenderContext &context_, const std::shared_ptr<TileClient> &tiles_, const bool overlay_, const std::shared_ptr<StyleSheet> &stylesheet_) NOTHROWS :
    GLVectorTiles(context_, std::static_pointer_cast<TileMatrix>(tiles_), overlay_, stylesheet_)
{
   tiles.client = tiles_;
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
    stylesheet(stylesheet_),
    bitmapLoader(new AsyncBitmapLoader2(8u)),
    color(0xFFFFFFFFu)
{
    tiles.value = tiles_;
    if(tiles.value) {
        std::vector<TileMatrix::ZoomLevel> zoom;
        TAK::Engine::Port::STLVectorAdapter<TileMatrix::ZoomLevel> zoom_a(zoom);
        tiles.value->getZoomLevel(zoom_a);
        if(!zoom.empty())
            maxZoom = zoom.back().level;
    }

    // set up a custom bitmap loader if there's a spritesheet to annotate burn-in text icons
    // (e.g. road shields)
    if(stylesheet && stylesheet->hasSpriteSheet()) {
        std::shared_ptr<BitmapFactory2> factory;
        factory.reset(new SpriteSheetAnnotator(*stylesheet));
        bitmapLoader->addBitmapFactory(nullptr, factory);
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
    impl.fetchTileData = [&](const GLTiledGlobe::QuadNode &node, const GLTiledGlobe::CollectHints &hints) {
        struct {
            GLTileFeatures::Ptr s{nullptr, nullptr};
            GLTileFeatures::Ptr d{nullptr, nullptr};
        } glfeatures;
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
                    std::shared_ptr<FeatureDataStore2> features(
                        new VectorTile(
                                tileIndex.z, tileIndex.x, tileIndex.y,
                                dataPtr.get(), dataLen,
                                stylesheet,
                                tiles.value->getSRID()));
                    const auto pe = TAK::Engine::Port::Platform_systime_millis();

                    auto &ds = *features;
                    features->queryFeaturesCount(&nfeatures);

                    parse = (unsigned)(pe-ps);

                    // XXX - fix DPI
                    const double dpi = 96.0;

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
                    state.focusx = (float)(state.left+state.right) / 2.f;
                    state.focusy = (float)(state.bottom+state.top) / 2.f;
                    state.drawMapResolution = atakmap::raster::osm::OSMUtils::mapnikTileResolution((int)tileIndex.z);
                    state.drawMapScale = atakmap::core::AtakMapView_getMapScale(dpi, state.drawMapResolution);
                    state.scene.set(dpi, (std::size_t)(state.right-state.left), (std::size_t)(state.top-state.bottom), state.drawSrid, GeoPoint2(state.drawLat, state.drawLng), state.focusx, state.focusy, state.drawRotation, 0.0, state.drawMapResolution);

                    GLBatchGeometryFeatureDataStoreRenderer3::Options opts;
                    opts.spritesheet = spritesheet.value;
                    opts.spritesheetMutex = spritesheet.mutex;
                    opts.bitmapLoader = bitmapLoader;
                    opts.defaultIconOnLoadFailure = false;
                    opts.simplificationEnabled = false;
                    opts.antiMeridianHandlingEnabled = false;
                    opts.touchLabelVisibility = true;
                    opts.labelOnlyPrecedence = false;
                    opts.tessellationDisabled = true;
                    opts.skipNoStyleFeatures = true;
                    opts.linestringIcons = true;
                    opts.densityAdjustedStroke = false;
                    opts.declutterIcons = true;
                    opts.iconDimensionConstraint.min = 32u;
                    opts.iconDimensionConstraint.max = 64u;
                    opts.labelHints = (opts.labelHints&~GLLabel::WeightedFloat)
                            | GLLabel::DisableDeconflict
                            | GLLabel::XRay;
                    opts.labelMaxTilt = 60.0;
                    //opts.labelsEnabled = false;

                    opts.renderPass = GLGlobeBase::Surface|GLGlobeBase::Sprites;
                    std::unique_ptr<GLTileFeatures> gltf_s(new GLTileFeatures(context_, features, state, true, opts));

                    opts.renderPass = GLGlobeBase::Sprites;
                    std::unique_ptr<GLTileFeatures> gltf_d(new GLTileFeatures(context_, features, state, false, opts));
                    gltf_s->prefetch(this->view, state);
                    gltf_d->prefetch(this->view, state);
                    bool prefetched = false;
                    ds.isAvailable(&prefetched);
                    if(!prefetched) {
                        // no data -- return empty value
                        return value;
                    }
                    const auto fe = TAK::Engine::Port::Platform_systime_millis();
                    prefetch = (unsigned)(fe-fs);
                    glfeatures.s = GLTileFeatures::Ptr(gltf_s.release(), GLTileFeatures::deleter);
                    glfeatures.d = GLTileFeatures::Ptr(gltf_d.release(), GLTileFeatures::deleter);
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
        value.reset(new GLTileData<GLTiledGlobe::QuadNode>(context_, node, 0x00FF00FFu, msg.c_str(), std::move(glfeatures.s), std::move(glfeatures.d)));
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
}
void GLVectorTiles::draw(const GLGlobeBase& view_, const int renderPass) NOTHROWS
{
    if(!this->view)
        this->view = &view_;
    // XXX - skip prefetch
    if(!spritesheet.value) {
        spritesheet.value = std::make_shared<GLTextureAtlas2>(1024u);
        spritesheet.mutex = std::make_shared<Mutex>();
    }
    // initialize spritesheet atlas
    if(!spritesheet.value) {
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
            spritesheet.value = std::move(atlas);
            spritesheet.mutex = std::make_shared<Mutex>();
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
        if(renderable) {
            auto &glfeatures = static_cast<GLTileData<GLTiledGlobe::QuadNode> &>(*renderable).glfeatures;
            if(glfeatures.s) glfeatures.s->setColor(color);
            if(glfeatures.d) glfeatures.d->setColor(color);
            renderable->draw(view_, renderPass);
        }
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
                if(glfeatures.s) glfeatures.s->releaseLabels();
                if(glfeatures.d) glfeatures.d->releaseLabels();
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
        if(!(glfeatures.s || glfeatures.d))
            continue;
        auto limit = limit_;
        if(limit && features.size()) {
            limit -= features.size();
        }
        std::vector<int64_t> fids;
        TAK::Engine::Port::STLVectorAdapter<int64_t> fids_a(fids);
        if(glfeatures.d) glfeatures.d->hitTest2(fids_a, screenX, screenY, touch, resolution, radius, limit_);
        if(glfeatures.s) glfeatures.s->hitTest2(fids_a, screenX, screenY, touch, resolution, radius, limit_);
        if(!fids.empty()) {
            for(const auto &fid : fids) {
                FeaturePtr_const f(nullptr, nullptr);
                glfeatures.s->getDataStore().getFeature(f, fid);
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
uint32_t GLVectorTiles::getColor() const NOTHROWS
{
    return color;
}
void GLVectorTiles::setColor(const uint32_t argb) NOTHROWS
{
    color = argb;
}

GLVectorTiles::CacheUpdateForwarder::CacheUpdateForwarder(GLVectorTiles &owner_) NOTHROWS :
        owner(owner_)
{}
void GLVectorTiles::CacheUpdateForwarder::onTileUpdated(const std::size_t level, const std::size_t x, const std::size_t y) NOTHROWS
{
    //Logger_log(TELL_Info, " GLVectorTiles::CacheUpdateForwarder::onTileUpdated(%u, %u, %u)", level, x, y);
    owner.impl.sourceContentUpdated(level, x, y);
}

namespace {
    void colorComponents(float &a, float &r, float &g, float &b, const uint32_t argb)
    {
        a = (float)((argb>>24u)&0xFF)/255.f;
        r = (float)((argb>>16u)&0xFF)/255.f;
        g = (float)((argb>>8u)&0xFF)/255.f;
        b = (float)(argb&0xFF)/255.f;
    }
    void colorize(Bitmap2 &bmp, const uint32_t argb) NOTHROWS
    {
        float a, r, g, b;
        colorComponents(a, r, g, b, argb);
        const auto w = bmp.getWidth();
        const auto h = bmp.getHeight();
        for(std::size_t y = 0u; y < h; y++) {
            for (std::size_t x = 0u; x < w; x++) {
                uint32_t p;
                bmp.getPixel(&p, x, y);
                float pa, pr, pg, pb;
                colorComponents(pa, pr, pg, pb, p);
                p = (uint8_t)(a*pa*255.f) << 24u |
                    (uint8_t)(r*pr*255.f) << 16u |
                    (uint8_t)(g*pg*255.f) << 8u |
                    (uint8_t)(b*pb*255.f);
                bmp.setPixel(x, y, p);
            }
        }
    }
    double interpolate(double a, double b, double weight) NOTHROWS
    {
        return (a*(1.0-weight)) + (b*weight);
    }
    void composite(Bitmap2 &dst, const Bitmap2 &src, const std::size_t dstX, const std::size_t dstY) NOTHROWS
    {
        for(std::size_t y = 0u; y < src.getHeight(); y++) {
            for(std::size_t x = 0u; x < src.getWidth(); x++) {
                uint32_t srcPixel;
                src.getPixel(&srcPixel, x, y);
                if((srcPixel&0xFF000000u) != 0xFF000000u) {
                    uint32_t dstPixel;
                    dst.getPixel(&dstPixel, x+dstX, y+dstY);
                    float sa, sr, sg, sb;
                    float da, dr, dg, db;
                    colorComponents(sa, sr, sg, sb, srcPixel);
                    colorComponents(da, dr, dg, db, dstPixel);
                    auto blend = [sa](const float s, const float d)
                    {
                        const auto ss = sa*s;
                        const auto dd = (1.f-sa)*d;
                        return std::min(ss+dd, 1.f);
                    };
                    srcPixel =
                        (uint8_t)(std::min(sa+da, 1.f)*255.f) << 24u |
                        (uint8_t)(blend(sr, dr)*255.f) << 16u |
                        (uint8_t)(blend(sg, dg)*255.f) << 8u |
                        (uint8_t)(blend(sb, db)*255.f);

                }
                dst.setPixel(x + dstX, y + dstY, srcPixel);
            }
        }
    }

    SpriteSheetAnnotator::SpriteSheetAnnotator(const StyleSheet &styleSheet) NOTHROWS
    {
        const Bitmap2 *bitmap;
        styleSheet.getSpriteSheet(&bitmap);
        spriteSheet.bitmap = BitmapPtr(new Bitmap2(*bitmap), Memory_deleter_const<Bitmap2>);
        for(std::size_t i = 0u; i < styleSheet.getNumSpriteMappings(); i++) {
            TAK::Engine::Port::String path;
            Rectangle2<float> region;
            styleSheet.getSpriteMapping(path, region, i);
            spriteSheet.entries[std::string(path.get())] = region;
        }

        TextFormat2_createDefaultSystemTextFormat(defaultText, 10.f);
    }
    TAKErr SpriteSheetAnnotator::decode(BitmapPtr &result, const char *curi, const BitmapDecodeOptions *opts) NOTHROWS
    {
        //Logger_log(TELL_Info, "SpriteSheetAnnotator[%p]::decode %s", this, curi);
        std::string uri(curi);
        const auto paramsIdx = uri.find('?');
        const auto key = uri.substr(0, paramsIdx);
        const auto entry = spriteSheet.entries.find(key);
        if(entry == spriteSheet.entries.end())
            return TE_InvalidArg;
        auto code = spriteSheet.bitmap->subimage(result, (std::size_t)entry->second.x, (std::size_t)entry->second.y, (std::size_t)entry->second.width, (std::size_t)entry->second.height, false);
        if((code != TE_Ok) || (paramsIdx == std::string::npos))
            return code;

        constexpr float baseTextPad = 8.f;
        struct {
            std::string value;
            uint32_t color {0xFF000000u};
            float size {0.f};
            float pad {baseTextPad + 4.f};
        } text;
        // params parsing
        if(paramsIdx != std::string::npos) {
        std::string params = uri.substr(paramsIdx+1u);
        //Logger_log(TELL_Info, "annotate parse %s params [%s]", uri.c_str(), params.c_str());
        while(true) {
            const auto paramEnd = params.find('&');
            const auto param = params.substr(0, paramEnd);
            const auto delimIdx = param.find('=');
            if(delimIdx != std::string::npos) {
                const auto k = param.substr(0, delimIdx);
                const auto v = param.substr(delimIdx+1u);
                //Logger_log(TELL_Info, "annotate parse params [%s:%s]", k.c_str(), v.c_str());
                if(k == "text") {
                    text.value = v;
                } else if(k == "textColor") {
                    int i;
                    if(TAK::Engine::Port::String_parseInteger(&i, v.c_str(), 16) == TE_Ok)
                        text.color = (uint32_t)i;
                } else if(k == "textSize") {
                    double d;
                    if(TAK::Engine::Port::String_parseDouble(&d, v.c_str()) == TE_Ok) {
                        if(d > defaultText->getFontSize())
                            text.size = (float) d;
                    }
                }
            }
            if(paramEnd == std::string::npos)
                break;
            params = params.substr(paramEnd+1u);
        }
        if(text.value.empty())
            return TE_Done;
        }
        //Logger_log(TELL_Info, "SpriteSheetAnnotator[%p]::decode %s key -> %s {%f, %f, %f, %f} text=%s", this, curi, key.c_str(), entry->second.x, entry->second.y, entry->second.width, entry->second.height, text.value.c_str());

        TextFormat2Ptr  textFormat(nullptr, nullptr);
        if(text.size && text.size != (float)defaultText->getFontSize()) {
            TextFormat2_createDefaultSystemTextFormat(textFormat, text.size);
        } else {
            textFormat = TextFormat2Ptr(defaultText.get(), Memory_leaker_const<TextFormat2>);
        }
        const auto textWidth = textFormat->getStringWidth(text.value.c_str());
        const auto textHeight = textFormat->getStringHeight(text.value.c_str());
        Bitmap2 renderedText((std::size_t)textWidth, (std::size_t)textHeight, Bitmap2::ARGB32);
        TAK::Engine::Math::Point2<std::size_t> carat;
        for(std::size_t i = 0u; i < text.value.length(); i++) {
            const auto c = text.value[i];
            if(c == '\n') {
                carat.x = 0u;
                carat.y += (std::size_t)textFormat->getBaselineSpacing();
                continue;
            }
            BitmapPtr glyph(nullptr, nullptr);
            if(textFormat->loadGlyph(glyph, c) == TE_Ok) {
                colorize(*glyph, text.color);
                renderedText.setRegion(*glyph, carat.x, carat.y);
            }
            carat.x += (std::size_t)textFormat->getCharPositionWidth(text.value.c_str(), (int)i);
        }
        if(result->getWidth() < renderedText.getWidth()+2u*(unsigned)text.pad || result->getHeight() < renderedText.getHeight()+2u*(unsigned)text.pad)
            result = BitmapPtr(new Bitmap2(*result, std::max(renderedText.getWidth()+2u*(unsigned)text.pad, result->getWidth()), std::max(renderedText.getHeight()+2u*(unsigned)text.pad, result->getHeight()), Bitmap2::ARGB32), Memory_deleter_const<Bitmap2>);
        composite(*result, renderedText, (result->getWidth()-renderedText.getWidth())/2u, (result->getHeight()-renderedText.getHeight())/2u);
        return code;
    }
}