#include "renderer/feature/GLBatchGeometryFeatureDataStoreRenderer3.h"

#include <cassert>

#include "core/ProjectionFactory3.h"
#include "elevation/ElevationManager.h"
#include "feature/FeatureCursor2.h"
#include "feature/GeometryFactory.h"
#include "feature/Polygon.h"
#include "feature/Style.h"
#include "math/Mesh.h"
#include "math/Vector4.h"
#include "model/Scene.h"
#include "port/STLListAdapter.h"
#include "port/STLVectorAdapter.h"
#include "port/StringBuilder.h"
#include "raster/osm/OSMUtils.h"
#include "renderer/GL.h"
#include "renderer/GLES20FixedPipeline.h"
#include "renderer/GLTextureAtlas2.h"
#include "renderer/core/GLGlobe.h"
#include "renderer/core/GLGlobeBase.h"
#include "renderer/core/GLMapRenderGlobals.h"
#include "renderer/elevation/TerrainRenderService.h"
#include "renderer/feature/GLGeometryBatchBuilder.h"
#include "util/ConfigOptions.h"
#include "util/MathUtils.h"
#include "util/Memory.h"
#include "util/PoolAllocator.h"
#include "util/StringMap.h"

using namespace TAK::Engine::Renderer::Feature;

using namespace TAK::Engine::Core;
using namespace TAK::Engine::Elevation;
using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Math;
using namespace TAK::Engine::Port;
using namespace TAK::Engine::Renderer;
using namespace TAK::Engine::Renderer::Core;
using namespace TAK::Engine::Renderer::Core::Controls;
using namespace TAK::Engine::Thread;
using namespace TAK::Engine::Util;

using namespace atakmap::core;
using namespace atakmap::feature;
using namespace atakmap::raster::osm;
using namespace atakmap::renderer;
using namespace atakmap::util;

namespace
{

    struct
    {
        std::map<const RenderContext *, std::vector<GLuint>> value;
        Mutex mutex;
    } discardBuffers;
    struct IconLoaderRef
    {
        StringMap<AsyncBitmapLoader2::Task> *loading{nullptr};
        StringSet<StringLess> *failed{nullptr};
        TAK::Engine::Port::String *defaultIconUri{nullptr};
        GLTextureAtlas2* atlas{ nullptr };
        bool defaultIconOnLoadFailure{true};
        Mutex *mutex{nullptr};
    };

    struct TextureAtlasEntry
    {
        GLuint texid{ GL_NONE };
        float u0{ 0.f };
        float v0{ 0.f };
        float u1{ 0.f };
        float v1{ 0.f };
        std::size_t width{ 0u };
        std::size_t height{ 0u };
        float rotation{ 0.0f };
        bool isAbsoluteRotation{ false };
    };
    struct CallbackExchange
    {
        Monitor monitor;
        bool terminated{ false };
    };

    struct FeatureRecord
    {
        int64_t fid{ FeatureDataStore2::FEATURE_ID_NONE };
        int64_t version{ FeatureDataStore2::FEATURE_VERSION_NONE };
        std::size_t touch{ 0u };
        struct {
            uint32_t id{ GLLabelManager::NO_ID };
            uint32_t deferredRemoveIndex{ 0u };
            std::vector<uint32_t> overflow;
            bool invalid{ true };
            bool hitTestable{false};
        } labels;
        uint32_t hitid{ 0u };
    };

    struct FeatureLabelsControlState {
        struct {
            /** current per-FID label visibility requested state */
            std::set<int64_t> value;
            /** updates since last validation */
            std::set<int64_t> updated;
        } visMap_;
        bool shapeCenterVisible_ = false;
        struct {
            std::size_t minLod {atakmap::feature::LevelOfDetailStyle::MIN_LOD};
            std::size_t maxLod {atakmap::feature::LevelOfDetailStyle::MAX_LOD};
        } levelOfDetail;
        struct {
            uint32_t color {0x0u};
            bool override {false};
        } background;
    };

    class BuilderQueryContext : public GLAsynchronousMapRenderable3::QueryContext,
                             public GLGeometryBatchBuilder::Callback3
    {
    public :
        BuilderQueryContext(RenderContext &ctx, std::size_t &ctxid) NOTHROWS;
        ~BuilderQueryContext() NOTHROWS;
    public :
        void startFeature(const int64_t fid, const int64_t version) NOTHROWS;
        void endFeature() NOTHROWS;
    public :
        TAKErr mapBuffer(GLuint *handle, void **buffer, const std::size_t size) NOTHROWS override;
        TAKErr unmapBuffer(const GLuint handle) NOTHROWS override;
        TAKErr getElevation(double *value, const double latitude, const double longitude) NOTHROWS override;
        TAKErr getIcon(GLuint *id, float *u0, float *v0, float *u1, float *v1, std::size_t *w, std::size_t *h, float *rotation, bool *isAbsoluteRotation, const char* uri) NOTHROWS override;
        TAKErr addLabel(const GLLabel &label) NOTHROWS override;
        TAKErr addLabel(GLLabel &&label) NOTHROWS override;
        uint32_t reserveHitId() NOTHROWS override;
        TAKErr getMesh(std::shared_ptr<const TAK::Engine::Model::Mesh>& mesh, const char* uri) NOTHROWS override;

    public :
        RenderContext &ctx;
        const std::size_t initCtxId;
        std::size_t &activeCtxId;
        GLGeometryBatchBuilder builder;
        StringMap<TextureAtlasEntry> iconEntryCache;
        std::shared_ptr<CallbackExchange> cbex;
        std::size_t queryCount{ 0u };
        uint32_t nextHitId{ 0u };
        std::size_t iconDimensionConstraint{ 64u };

        std::map<int64_t, FeatureRecord> featureRecords;
        /** labelid => FID */
        std::map<uint32_t, int64_t> hitTestLabels;

        FeatureRecord* current{ nullptr };
        GLLabelManager* labelManager{ nullptr };
        std::shared_ptr<int> labelRenderPump;
        struct {
            std::vector<std::shared_ptr<const TAK::Engine::Renderer::Elevation::TerrainTile>> value;
            std::shared_ptr<const TAK::Engine::Renderer::Elevation::TerrainTile> last;
        } terrainTiles;

        IconLoaderRef iconLoader;
        std::map<std::string, std::shared_ptr<const TAK::Engine::Model::Mesh>>* loadedMeshes;

        struct {
            bool current {false};
            bool last {false};
        } forceClampToGround;

        // query thread copy of control state
        FeatureLabelsControlState featureLabels;

        struct {
            std::size_t resultsSize{ 0u };
            unsigned queryTime{ 0u };
        } metrics;
    };

    struct BuilderCallbackBundle
    {
        GLuint handle{ GL_NONE };
        void *buffer{ nullptr };
        std::size_t bufsize{ 0u };
        const char *iconUri;
        TextureAtlasEntry icon;
        RenderContext *ctx;
        bool done{ false };
        IconLoaderRef iconLoader;
    };

    struct CallbackOpaque
    {
        BuilderCallbackBundle *bundle{ nullptr };
        std::shared_ptr<CallbackExchange> cbex;
    };

    PoolAllocator<CallbackOpaque> cb_alloc(64u);

    struct HitTestParams 
    {
        CallbackExchange callbackExchange;
        GLBatchGeometryRenderer4* renderer{ nullptr };
        struct {
            std::vector<uint32_t> *features{nullptr};
            std::vector<uint32_t> *labels{nullptr};
        } ids;
        const Core::GLGlobeBase* view{ nullptr };
        float screenX; 
        float screenY;
        float radius{0.f};
        const GeoPoint* geoPoint{ nullptr };
        std::size_t limit{ 1u };
        bool done{ false };
    };

    void hitTest(void *params) NOTHROWS;
    unsigned getGeomFilterMask(const atakmap::feature::Geometry::Type geomType) NOTHROWS
    {
        switch(geomType) {
        case atakmap::feature::Geometry::COLLECTION :
            return 1u << (unsigned)TEGC_GeometryCollection;
        case atakmap::feature::Geometry::LINESTRING :
            return 1u << (unsigned)TEGC_LineString;
        case atakmap::feature::Geometry::POINT :
            return 1u << (unsigned)TEGC_Point;
        case atakmap::feature::Geometry::POLYGON :
            return 1u << (unsigned)TEGC_Polygon;
        default :
            return 0u;
        }
    }
    GLBatchGeometryFeatureDataStoreRenderer3::Options createOptions(const atakmap::feature::Geometry::Type *filterTypes, const std::size_t numFilterTypes, const bool tessellationDisabled) NOTHROWS
    {
        GLBatchGeometryFeatureDataStoreRenderer3::Options opts;
        opts.geometryFilter.types = filterTypes;
        opts.geometryFilter.count = numFilterTypes;
        opts.tessellationDisabled = tessellationDisabled;
        return opts;
    }

    int nextMetricsIdx = 0;

    struct {
        std::map<const RenderContext *, std::shared_ptr<GLTextureAtlas2>> value;
        Mutex mutex;
    } iconAtlases;
}

class GLBatchGeometryFeatureDataStoreRenderer3::FeaturesLabelControlImpl : public FeaturesLabelControl
{
public :
    FeatureLabelsControlState state;
public :
    FeaturesLabelControlImpl(GLBatchGeometryFeatureDataStoreRenderer3 &renderer3) NOTHROWS;
    ~FeaturesLabelControlImpl() NOTHROWS;
public :
    void setShapeCenterMarkersVisible(const bool v) NOTHROWS override;
    bool getShapeCenterMarkersVisible() NOTHROWS override;
    void setShapeLabelVisible(int64_t fid, bool visible) NOTHROWS override;
    bool getShapeLabelVisible(int64_t fid) NOTHROWS override;
    void setDefaultLabelBackground(const uint32_t bgColor, const bool override) NOTHROWS override;
    void getDefaultLabelBackground(uint32_t *color, bool *override) NOTHROWS override;
    void setDefaultLabelLevelOfDetail(const std::size_t minLod, const std::size_t maxLod) NOTHROWS override;
    void getDefaultLabelLevelOfDetail(std::size_t *minLod, std::size_t *maxLod) NOTHROWS override;
private:
    TAK::Engine::Renderer::Feature::GLBatchGeometryFeatureDataStoreRenderer3 &renderer;
};

GLBatchGeometryFeatureDataStoreRenderer3::GLBatchGeometryFeatureDataStoreRenderer3(TAK::Engine::Core::RenderContext &surface_, FeatureDataStore2 &subject_) NOTHROWS :
    GLBatchGeometryFeatureDataStoreRenderer3(surface_, subject_, nullptr, 0u)
{}
GLBatchGeometryFeatureDataStoreRenderer3::GLBatchGeometryFeatureDataStoreRenderer3(TAK::Engine::Core::RenderContext &surface_, FeatureDataStore2 &subject_, const atakmap::feature::Geometry::Type *filteredTypes_, const std::size_t filteredTypesCount_) NOTHROWS :
    GLBatchGeometryFeatureDataStoreRenderer3(surface_, subject_, filteredTypes_, filteredTypesCount_, false)
{}
GLBatchGeometryFeatureDataStoreRenderer3::GLBatchGeometryFeatureDataStoreRenderer3(TAK::Engine::Core::RenderContext &surface_, FeatureDataStore2 &subject_, const atakmap::feature::Geometry::Type *filteredTypes_, const std::size_t filteredTypesCount_, const bool tessellationDisabled_) NOTHROWS :
    GLBatchGeometryFeatureDataStoreRenderer3(surface_, subject_, createOptions(filteredTypes_, filteredTypesCount_, tessellationDisabled_))
{}
GLBatchGeometryFeatureDataStoreRenderer3::GLBatchGeometryFeatureDataStoreRenderer3(TAK::Engine::Core::RenderContext &surface_, FeatureDataStore2 &subject_, const GLBatchGeometryFeatureDataStoreRenderer3::Options &opts_) NOTHROWS :
    GLAsynchronousMapRenderable3(),
    surface(surface_),
    dataStore(subject_),
    iconDimensionConstraint(32u),
    validContext(0u),
    renderer(surface_, opts_.featuresPresorted),
    editRenderer(surface_),
    spatialFilterControl(&invalid_),
    opts(opts_),
    featuresLabelControl(nullptr, nullptr),
    labelRenderPump(new int {-1})
{
    filteredGeometryTypes.accept.insert(atakmap::feature::Geometry::POINT);
    filteredGeometryTypes.accept.insert(atakmap::feature::Geometry::LINESTRING);
    filteredGeometryTypes.accept.insert(atakmap::feature::Geometry::POLYGON);
    filteredGeometryTypes.accept.insert(atakmap::feature::Geometry::COLLECTION);

    for (std::size_t i = 0u; i < opts.geometryFilter.count; i++) {
        filteredGeometryTypes.mask |= getGeomFilterMask(opts.geometryFilter.types[i]);
        filteredGeometryTypes.reject.insert(opts.geometryFilter.types[i]);
        filteredGeometryTypes.accept.erase(opts.geometryFilter.types[i]);
    }

    if(opts.spritesheet) {
        iconLoader.atlas = opts.spritesheet;
    } else {
        // NOTE: the renderer uses its own icon atlas as a critical resource optimization to
        // eliminate the need to access/mutate exclusively on the render thread
        Lock lock(iconAtlases.mutex);
        auto entry = iconAtlases.value.find(&surface);
        if(entry != iconAtlases.value.end()) {
            iconLoader.atlas = entry->second;
        } else {
            GLTextureAtlas2 *globalAtlas;
            GLMapRenderGlobals_getTextureAtlas2(&globalAtlas, surface);

            iconLoader.atlas.reset(new GLTextureAtlas2(globalAtlas->getTextureSize()));
            iconAtlases.value[&surface] = iconLoader.atlas;
        }
    }
    iconLoader.defaultIconOnLoadFailure = opts.defaultIconOnLoadFailure;

    featuresLabelControl = std::unique_ptr<FeaturesLabelControlImpl, void(*)(const FeaturesLabelControlImpl *)>(new FeaturesLabelControlImpl(*this), Memory_deleter_const<FeaturesLabelControlImpl>);

    const int configIconDimensionConstraint = ConfigOptions_getIntOptionOrDefault(
            "overlays.icon-dimension-constraint", -1);
    if(configIconDimensionConstraint > 0)
        iconDimensionConstraint = (std::size_t)configIconDimensionConstraint;
}

/**************************************************************************/
// GL Asynchronous Map Renderable

void GLBatchGeometryFeatureDataStoreRenderer3::draw(const GLGlobeBase &view, const int renderPass) NOTHROWS
{
    {
        Lock lock(iconLoader.mutex);
        bool doInvalidate = false;
        if (iconLoader.atlas) {
            auto it = iconLoader.loading.begin();
            while (it != iconLoader.loading.end()) {
                if (it->second->getFuture().getState() == atakmap::util::SharedState::Complete) {
                    // upload bitmap to atlas
                    int64_t key;
                    if(iconLoader.atlas->addImage(&key, it->first, *it->second->getFuture().get()) != TE_Ok) {
                        iconLoader.failed.insert(it->first);
                    }
                    it = iconLoader.loading.erase(it);

                    // mark invalid to refresh buffers
                    invalid_ |= true;
                    editor.dirty.features = true;
                } else if (it->second->getFuture().getState() == atakmap::util::SharedState::Error) {
                    iconLoader.failed.insert(it->first);
                    it = iconLoader.loading.erase(it);

                    // mark invalid to refresh buffers
                    invalid_ |= iconLoader.defaultIconOnLoadFailure;
                } else {
                    it++;
                }
            }
        }
    }
    currentView = &view;
    if(clampToGroundControl.value) {
        const bool forceClampToGround = clampToGroundControl.value->getClampToGroundAtNadir() && view.renderPasses[0].drawTilt == 0.0;
        invalid_ |= forceClampToGround != clampToGroundControl.lastDrawForceClampToGround;
        clampToGroundControl.lastDrawForceClampToGround = forceClampToGround;
    }
    {
        if(!editor.ctx)
            createQueryContext(editor.ctx);
        auto &editctx = static_cast<BuilderQueryContext &>(*editor.ctx);

        // toggle the _force-clamp-to-ground_ state for this query pass
        editctx.forceClampToGround.current = (clampToGroundControl.value &&
                                              clampToGroundControl.value->getClampToGroundAtNadir() &&
                                              view.renderPasses[0].drawTilt == 0.0);
        const bool forceClampChanged = editctx.forceClampToGround.current != editctx.forceClampToGround.last;
        editctx.forceClampToGround.last = editctx.forceClampToGround.current;

        std::vector<std::shared_ptr<const Feature2>> editFeatures;
        {
            Monitor::Lock lock(monitor_);
            if (editor.dirty.features || forceClampChanged) {
                editor.dirty.features = false;
                editFeatures.reserve(editor.editing.size()+editor.edited.pending.size()+editor.edited.purgeable.size());
                for(auto entry : editor.editing)
                    editFeatures.push_back(entry.second);
                for(auto entry : editor.edited.pending)
                    editFeatures.push_back(entry.second);
                for(auto entry : editor.edited.purgeable)
                    editFeatures.push_back(entry.second);

                // edit list is dirty, discard old buffers
                auto renderCtx = &view.getRenderContext();
                editRenderer.markForRelease([renderCtx](const GLBatchGeometryRenderer4::PrimitiveBuffer &buf)
                {
                    Lock l(discardBuffers.mutex);
                    if(buf.vbo) discardBuffers.value[renderCtx].push_back(buf.vbo);
                    if(buf.ibo) discardBuffers.value[renderCtx].push_back(buf.ibo);
                });
            }
        }
        // if the edit list has content, build new buffers
        if(!editFeatures.empty()) {
            if (iconDimensionConstraint > 0)
                editctx.iconDimensionConstraint = iconDimensionConstraint;
            editctx.terrainTiles.last.reset();
            editctx.terrainTiles.value.clear();
            STLVectorAdapter<std::shared_ptr<const TAK::Engine::Renderer::Elevation::TerrainTile>> terrainTiles(editctx.terrainTiles.value);
            view.getTerrainRenderService().lock(terrainTiles);

            // XXX - SRIDs
            struct {
                int surface;
                int sprites;
            } srid;
            srid.surface = view.renderPasses[0].drawSrid;
            srid.sprites = view.renderPasses[0].drawSrid;
            if (surface_ctrl_ || view.renderPasses[0].drawTilt)
                srid.surface = 4326;
            editctx.builder.reset(srid.surface, srid.sprites,
                                  GeoPoint2(view.renderPasses[0].drawLat,
                                            view.renderPasses[0].drawLng),
                                  view.renderPasses[0].drawMapResolution, editctx);
            for (const auto &f: editFeatures) {
                editctx.startFeature(f->getId(), f->getVersion());
                editctx.builder.push(*f, false, editctx.forceClampToGround.current);
                editctx.endFeature();
            }
            editctx.builder.flush();
            editctx.builder.setBatch(editRenderer);
            view.getTerrainRenderService().unlock(terrainTiles);
        }
    }

    {
        Lock bl(discardBuffers.mutex);
        auto renderCtx = &view.getRenderContext();
        if(!discardBuffers.value[renderCtx].empty()) {
            glDeleteBuffers((GLsizei)discardBuffers.value[renderCtx].size(), discardBuffers.value[renderCtx].data());
            discardBuffers.value[renderCtx].clear();
        }
    }
    if(renderPass&GLGlobeBase::Sprites)
        *labelRenderPump = view.renderPasses[0u].renderPump;
    drawImpl(view, renderPass);
#if 0
    if((renderPass&GLGlobeBase::Sprites) && metrics.resultsCount) {
        if (metrics.idx < 0)
            metrics.idx = nextMetricsIdx++;
        auto gltext = GLText2_intern(TextFormatParams(nullptr, 24.f));
        if(!gltext)
            return;
        std::ostringstream strm;
        strm << "Query count: " << metrics.resultsCount << " elapsed: " << metrics.queryTime << "ms";
        auto& gl = *atakmap::renderer::GLES20FixedPipeline::getInstance();
        gl.glMatrixMode(atakmap::renderer::GLES20FixedPipeline::MM_GL_PROJECTION);
        gl.glPushMatrix();
        gl.glOrthof((float)view.renderPass->left, (float)view.renderPass->right, (float)view.renderPass->bottom, (float)view.renderPass->top, 1.f, -1.f);
        gl.glMatrixMode(atakmap::renderer::GLES20FixedPipeline::MM_GL_MODELVIEW);
        gl.glPushMatrix();
        gl.glLoadIdentity();
        gl.glTranslatef(view.renderPass->right / 2.f, view.renderPass->top / 2.f + metrics.idx*gltext->getTextFormat().getCharHeight(), 0.f);
        gltext->draw(strm.str().c_str(), 1.f, 0.f, 1.f, 1.f);
        gl.glMatrixMode(atakmap::renderer::GLES20FixedPipeline::MM_GL_PROJECTION);
        gl.glPopMatrix();
        gl.glMatrixMode(atakmap::renderer::GLES20FixedPipeline::MM_GL_MODELVIEW);
        gl.glPopMatrix();
    }
#endif
}
void GLBatchGeometryFeatureDataStoreRenderer3::drawImpl(const TAK::Engine::Renderer::Core::GLGlobeBase &view, const int renderPass) NOTHROWS
{
    GLAsynchronousMapRenderable3::draw(view, renderPass);
}
TAKErr GLBatchGeometryFeatureDataStoreRenderer3::getControl(void **ctrl, const char *type) const NOTHROWS
{
    if (!type)
        return TE_InvalidArg;
    if (!ctrl)
        return TE_InvalidArg;
    if (strcmp(type, SpatialFilterControl_getType()) == 0) {
        const SpatialFilterControl& iface = spatialFilterControl;
        *ctrl = (void*)&iface;
        return TE_Ok;
    }
    if(strcmp(type, FeaturesLabelControl_getType()) == 0) {
        const FeaturesLabelControl &iface = *featuresLabelControl;
        *ctrl = (void *)&iface;
        return TE_Ok;
    }
    return TE_InvalidArg;
}
void GLBatchGeometryFeatureDataStoreRenderer3::release() NOTHROWS
{
    validContext++;
    Lock bl(discardBuffers.mutex);
    auto renderCtx = &surface;
    if(!discardBuffers.value.empty()) {
        glDeleteBuffers((GLsizei)discardBuffers.value[renderCtx].size(), discardBuffers.value[renderCtx].data());
        discardBuffers.value[renderCtx].clear();
        discardBuffers.value.erase(renderCtx);
    }
    GLAsynchronousMapRenderable3::release();
}
int GLBatchGeometryFeatureDataStoreRenderer3::getRenderPass() NOTHROWS
{
    return GLMapView2::Surface|GLMapView2::Sprites;
}
void GLBatchGeometryFeatureDataStoreRenderer3::start() NOTHROWS
{
    this->dataStore.addOnDataStoreContentChangedListener(this);
}
void GLBatchGeometryFeatureDataStoreRenderer3::stop() NOTHROWS
{
    this->dataStore.removeOnDataStoreContentChangedListener(this);
}
void GLBatchGeometryFeatureDataStoreRenderer3::initImpl(const GLGlobeBase &view) NOTHROWS
{
    currentView = &view;
    if (!clampToGroundControl.initialized) {
        clampToGroundControl.initialized = true;
        void* ctrl{ nullptr };
        view.getControl(&ctrl, TAK::Engine::Renderer::Core::Controls::ClampToGroundControl_getType());
        if (ctrl)
            clampToGroundControl.value = static_cast<TAK::Engine::Renderer::Core::Controls::ClampToGroundControl*>(ctrl);
    }
}
TAKErr GLBatchGeometryFeatureDataStoreRenderer3::releaseImpl() NOTHROWS
{
    renderer.release();
    return TE_Ok;
}

TAKErr GLBatchGeometryFeatureDataStoreRenderer3::getRenderables(Collection<GLMapRenderable2 *>::IteratorPtr &iter) NOTHROWS
{
    if (this->renderList.empty())
        return TE_Done;
    STLListAdapter<GLMapRenderable2 *> adapter(this->renderList);
    return adapter.iterator(iter);
}

TAKErr GLBatchGeometryFeatureDataStoreRenderer3::resetQueryContext(QueryContext &ctx) NOTHROWS
{
    return TE_Ok;
}

TAKErr GLBatchGeometryFeatureDataStoreRenderer3::createQueryContext(QueryContextPtr &result) NOTHROWS
{
    std::unique_ptr<BuilderQueryContext> queryContext(new(std::nothrow) BuilderQueryContext(surface, validContext));
    if (!queryContext)
        return TE_OutOfMemory;

    if (currentView)
        queryContext->labelManager = currentView->getLabelManager();

    queryContext->iconLoader.mutex = &iconLoader.mutex;
    queryContext->iconLoader.loading = &iconLoader.loading;
    queryContext->iconLoader.failed = &iconLoader.failed;
    queryContext->iconLoader.atlas = iconLoader.atlas.get();
    queryContext->iconLoader.defaultIconUri = &iconLoader.defaultIconUri;
    queryContext->iconLoader.defaultIconOnLoadFailure = iconLoader.defaultIconOnLoadFailure;
    queryContext->loadedMeshes = &loadedMeshes;

    if(opts.touchLabelVisibility)
        queryContext->labelRenderPump = labelRenderPump;

    result = QueryContextPtr(queryContext.release(), Memory_deleter_const<QueryContext, BuilderQueryContext>);
    return TE_Ok;
}

TAKErr GLBatchGeometryFeatureDataStoreRenderer3::updateRenderableLists(QueryContext &opaque) NOTHROWS
{
    auto& ctx = static_cast<BuilderQueryContext &>(opaque);

    // mark all current buffers for release
    auto c = this->renderer.markForRelease([&ctx](const GLBatchGeometryRenderer4::PrimitiveBuffer &buf)
    {
        Lock l(discardBuffers.mutex);
        if(buf.vbo) discardBuffers.value[&(ctx.ctx)].push_back(buf.vbo);
        if(buf.ibo) discardBuffers.value[&(ctx.ctx)].push_back(buf.ibo);
    });

    // Purge unused meshes
    auto meshes = ctx.builder.builders.sprites.meshes;
    for (auto it = loadedMeshes.cbegin(); it != loadedMeshes.cend(); ) {
        if (meshes.find(it->second) == meshes.end()) {
            it = loadedMeshes.erase(it);
        } else {
            ++it;
        }
    }
    // flush new buffers to renderer
    ctx.builder.setBatch(renderer);

    this->renderList.clear();
    this->renderList.push_back(&renderer);
    this->renderList.push_back(&editRenderer);

    // feature hit IDs
    this->hitids.features.clear();
    for (const auto& record : ctx.featureRecords)
        this->hitids.features[record.second.hitid] = record.first;

    // label hit IDs
    this->hitids.labels = ctx.hitTestLabels;

    // purge _edited_ features
    const bool purgeEditFeatures = !editor.edited.purgeable.empty();
    if(purgeEditFeatures || editor.dirty.hitids) {
        if(purgeEditFeatures) {
            editor.edited.purgeable.clear();
            editor.dirty.features = true;
        }
        editor.dirty.hitids = false;
        std::vector<uint32_t> ignoreFeatures;
        ignoreFeatures.reserve(editor.editing.size()+editor.edited.pending.size());
        for (const auto efid: editor.editing) {
            auto r = ctx.featureRecords.find(efid.first);
            if(r != ctx.featureRecords.end())
                ignoreFeatures.push_back(r->second.hitid);
            else
                editor.dirty.hitids = true;
        }
        for (const auto efid: editor.edited.pending) {
            auto r = ctx.featureRecords.find(efid.first);
            if(r != ctx.featureRecords.end()) {
                ignoreFeatures.push_back(r->second.hitid);
            } else {
                editor.dirty.hitids = true;
            }
        }
        renderer.setIgnoreFeatures(ignoreFeatures.data(), ignoreFeatures.size());
    }

    metrics.queryTime = ctx.metrics.queryTime;
    metrics.resultsCount = ctx.metrics.resultsSize;

    // if query results _force-clamp-to-ground_ changed, request a streaming surface redraw
    if(surface_ctrl_ && ((ctx.forceClampToGround.current != ctx.forceClampToGround.last) || purgeEditFeatures)) {
        for(std::size_t i = 0u; i < surface_dirty_regions_.size(); i++)
            surface_ctrl_->markDirty(surface_dirty_regions_[i], true);
        // we marked dirty;m clear regions so `base` doesn't signal
        surface_dirty_regions_.clear();
    }
    ctx.forceClampToGround.last = ctx.forceClampToGround.current;

    return TE_Ok;
}

TAKErr GLBatchGeometryFeatureDataStoreRenderer3::getBackgroundThreadName(TAK::Engine::Port::String &value) NOTHROWS
{
    StringBuilder strm;
    strm << "GLBatchGeometryFeatureDataStoreRenderer3-";
    strm << (uintptr_t)this;

    value = strm.c_str();
    return TE_Ok;
}

TAKErr GLBatchGeometryFeatureDataStoreRenderer3::query(QueryContext& opaque, const GLMapView2::State& state) NOTHROWS
{
    TAKErr code(TE_Ok);

    auto& ctx = static_cast<BuilderQueryContext&>(opaque);

    // query is starting:
    //  - transfer all _pending edited_ features into the _purgeable edited_ features list
    //  - transfer features label state to query context
    bool labelsInvalid;
    {
        Monitor::Lock lock(monitor_);
        for(auto e : editor.edited.pending)
            editor.edited.purgeable[e.first] = e.second;
        editor.edited.pending.clear();

        labelsInvalid =
                (ctx.featureLabels.shapeCenterVisible_ != featuresLabelControl->state.shapeCenterVisible_) ||
                (ctx.featureLabels.background.override != featuresLabelControl->state.background.override) ||
                (ctx.featureLabels.background.color != featuresLabelControl->state.background.color) ||
                (ctx.featureLabels.levelOfDetail.minLod != featuresLabelControl->state.levelOfDetail.minLod) ||
                (ctx.featureLabels.levelOfDetail.maxLod != featuresLabelControl->state.levelOfDetail.maxLod);
        ctx.featureLabels = featuresLabelControl->state;
        // updated FIDs have been transferred; reset to track new updates
        featuresLabelControl->state.visMap_.updated.clear();
    }

    // the labels have become invalid, update all records
    if(labelsInvalid) {
        for (auto &it: ctx.featureRecords) {
            auto &record = it.second;
            // twiddle the version to force label revalidation
            record.version = ~record.version;
        }
    } else if(!ctx.featureLabels.visMap_.updated.empty()) {
        // the state on one or more feature specific labels has changed
        for(auto fid : ctx.featureLabels.visMap_.updated) {
            auto record = ctx.featureRecords.find(fid);
            if(record == ctx.featureRecords.end())
                continue;
            record->second.version = ~record->second.version;
        }
        // updated FIDs have been marked, reset
        ctx.featureLabels.visMap_.updated.clear();
    }

    ctx.queryCount++;

    if (currentView) {
        STLVectorAdapter<std::shared_ptr<const TAK::Engine::Renderer::Elevation::TerrainTile>> tiles_a(ctx.terrainTiles.value);
        currentView->getTerrainRenderService().lock(tiles_a);
    }
    if (!ctx.labelManager && currentView)
        ctx.labelManager = currentView->getLabelManager();

    // toggle the _force-clamp-to-ground_ state for this query pass
    ctx.forceClampToGround.current = (clampToGroundControl.value &&
        clampToGroundControl.value->getClampToGroundAtNadir() && state.drawTilt == 0.0);

    ctx.metrics.resultsSize = 0u;

    auto qs = Platform_systime_millis();

    // XXX - SRIDs
    struct
    {
        int surface;
        int sprites;
    } srid;
    srid.surface = state.drawSrid;
    srid.sprites = state.drawSrid;
    if (surface_ctrl_ || state.drawTilt)
        srid.surface = 4326;
    ctx.builder.reset(srid.surface, srid.sprites, GeoPoint2(state.drawLat, state.drawLng), state.drawMapResolution, ctx);
    // set up batch defaults
    ctx.builder.labelDefaults.minLod = ctx.featureLabels.levelOfDetail.minLod;
    ctx.builder.labelDefaults.maxLod = ctx.featureLabels.levelOfDetail.maxLod;
    ctx.builder.labelDefaults.backgroundColor = ctx.featureLabels.background.color;
    ctx.builder.labelDefaults.overrideBackgroundColor = ctx.featureLabels.background.override;

    do {
        const bool crossIdl = (state.westBound > state.eastBound);
        if (crossIdl) {
            // XXX - SpatiaLite will not correctly perform intersection (at least
            //       when the using spatial index) if the geometry provided is a
            //       GeometryCollection that is divided across the IDL. Two queries
            //       must be performed, one for each hemisphere.

            GLMapView2::State stateE;
            stateE = state;
            stateE.eastBound = 180;
            GLMapView2::State stateW;
            stateW = state;
            stateW.westBound = -180;

            code = this->queryImpl(ctx, stateE);
            TE_CHECKBREAK_CODE(code);

            code = this->queryImpl(ctx, stateW);
            TE_CHECKBREAK_CODE(code);
        } else {
            code = this->queryImpl(ctx, state);
            TE_CHECKBREAK_CODE(code);
        }
    } while (false);

    ctx.builder.flush();
    TE_CHECKRETURN_CODE(code);

    // evict stale records
    auto it = ctx.featureRecords.begin();
    while(it != ctx.featureRecords.end()) {
        auto& record = it->second;

        // feature was not included with current query, evict
        if(record.touch != ctx.queryCount) {
            // remove associated label(s)
            if (ctx.labelManager) {
                if (record.labels.id != GLLabelManager::NO_ID)
                    ctx.labelManager->removeLabel(record.labels.id);
                for (const auto& id : record.labels.overflow) {
                    ctx.labelManager->removeLabel(id);
                }
            }

            // evict
            it = ctx.featureRecords.erase(it);
        } else {
            // labels were updated this pass, handle deferred label removes
            if (record.labels.invalid) {
                if (record.labels.deferredRemoveIndex == 0) {
                    if (record.labels.id != GLLabelManager::NO_ID) {
                        ctx.labelManager->removeLabel(record.labels.id);
                        record.labels.id = GLLabelManager::NO_ID;
                    }
                    for (const auto& id : record.labels.overflow)
                        ctx.labelManager->removeLabel(id);
                } else {
                    size_t popCount = record.labels.overflow.size() - (record.labels.deferredRemoveIndex - 1);
                    while (popCount) {
                        ctx.labelManager->removeLabel(record.labels.overflow.back());
                        record.labels.overflow.pop_back();
                        --popCount;
                    }
                }

                record.labels.invalid = false;
                record.labels.deferredRemoveIndex = 0;
            }
            it++;
        }
    }

    if (currentView) {
        STLVectorAdapter<std::shared_ptr<const TAK::Engine::Renderer::Elevation::TerrainTile>> tiles_a(ctx.terrainTiles.value);
        currentView->getTerrainRenderService().unlock(tiles_a);
        ctx.terrainTiles.value.clear();

        ctx.terrainTiles.last.reset();
    }

    auto qe = Platform_systime_millis();

    ctx.metrics.queryTime = (unsigned)(qe - qs);

    return TE_Ok;
}

TAKErr GLBatchGeometryFeatureDataStoreRenderer3::queryImpl(QueryContext &opaque, const GLMapView2::State &state) NOTHROWS
{
    TAKErr code(TE_Ok);

    auto &ctx = static_cast<BuilderQueryContext &>(opaque);

    unsigned basePushHints = 0;
    if(ctx.forceClampToGround.current)
        basePushHints |= GLGeometryBatchBuilder::PushHints::ForceClampToGround;
    if(ctx.featureLabels.shapeCenterVisible_)
        basePushHints |= GLGeometryBatchBuilder::PushHints::PolygonCenterLabels;
    if(!opts.antiMeridianHandlingEnabled)
        basePushHints |= GLGeometryBatchBuilder::PushHints::AntiMeridianHandlingDisabled;
    if(!opts.simplificationEnabled)
        basePushHints |= GLGeometryBatchBuilder::PushHints::SimplificationDisabled;
    if(opts.tessellationDisabled)
        basePushHints |= GLGeometryBatchBuilder::PushHints::TessellationDisabled;
    if(!opts.labelOnlyPrecedence)
        basePushHints |= GLGeometryBatchBuilder::PushHints::LabelOnlyHandlingDisabled;
    if(opts.skipNoStyleFeatures)
        basePushHints |= GLGeometryBatchBuilder::PushHints::SkipNoStyleFeatures;

    ctx.iconDimensionConstraint = iconDimensionConstraint;

    double simplifyFactor;
    if (state.scene.camera.mode == TAK::Engine::Core::MapCamera2::Perspective) {
        simplifyFactor = (state.drawMapResolution /
            TAK::Engine::Core::GeoPoint2_approximateMetersPerDegreeLatitude(state.drawLat)) * 2.0;
    } else {
        simplifyFactor = Vector2_length(TAK::Engine::Math::Point2<double>(
            state.upperLeft.longitude-state.lowerRight.longitude, state.upperLeft.latitude-state.lowerRight.latitude)) /
        Vector2_length(TAK::Engine::Math::Point2<double>(
            state.right-state.left, state.top-state.bottom)) * 2;
    }

    FeatureDataStore2::FeatureQueryParameters params;
    params.visibleOnly = true;

    LineString mbb(atakmap::feature::Geometry::_2D);
    mbb.addPoint(state.westBound, state.northBound);
    mbb.addPoint(state.eastBound, state.northBound);
    mbb.addPoint(state.eastBound, state.southBound);
    mbb.addPoint(state.westBound, state.southBound);
    mbb.addPoint(state.westBound, state.northBound);

    {
        const auto include_spatial_filter_envelope = spatialFilterControl.getIncludeMinimumBoundingBox();
        auto mbb_envelope = mbb.getEnvelope();

        mbb_envelope.minX = std::max(mbb_envelope.minX, include_spatial_filter_envelope.minX);
        mbb_envelope.minY = std::max(mbb_envelope.minY, include_spatial_filter_envelope.minY);
        mbb_envelope.maxX = std::min(mbb_envelope.maxX, include_spatial_filter_envelope.maxX);
        mbb_envelope.maxY = std::min(mbb_envelope.maxY, include_spatial_filter_envelope.maxY);

        mbb.setX(0, mbb_envelope.minX);
        mbb.setY(0, mbb_envelope.maxY);
        mbb.setX(1, mbb_envelope.maxX);
        mbb.setY(1, mbb_envelope.maxY);
        mbb.setX(2, mbb_envelope.maxX);
        mbb.setY(2, mbb_envelope.minY);
        mbb.setX(3, mbb_envelope.minX);
        mbb.setY(3, mbb_envelope.minY);
        mbb.setX(4, mbb_envelope.minX);
        mbb.setY(4, mbb_envelope.maxY);
    }

    atakmap::feature::Polygon spatialFilter(mbb);

    params.spatialFilter = GeometryPtr_const(&spatialFilter, Memory_leaker_const<atakmap::feature::Geometry>);
    params.maxResolution = state.drawMapResolution;
	params.minResolution = state.drawMapResolution * 0.5;

    if (filteredGeometryTypes.mask) {
        for(const auto &type : filteredGeometryTypes.accept)
            params.geometryTypes->add(type);
    }

    params.ignoredFields = FeatureDataStore2::FeatureQueryParameters::AttributesField;

    FeatureCursorPtr cursor(nullptr, nullptr);
        
    int64_t s = Platform_systime_millis();
    std::size_t n = 0u;
    code = this->dataStore.queryFeatures(cursor, params);
    TE_CHECKRETURN_CODE(code);
    do {
        if(ctx.activeCtxId != ctx.initCtxId)
            break;
        code = cursor->moveToNext();
        TE_CHECKBREAK_CODE(code);

        bool matchesFilter;
        code = spatialFilterControl.accept(&matchesFilter, *cursor);
        TE_CHECKBREAK_CODE(code);
        if (!matchesFilter)
            continue;

        if (filteredGeometryTypes.mask) {
            unsigned geomTypeMask = 0u;
            FeatureDefinition2::RawData rawGeom;
            code = cursor->getRawGeometry(&rawGeom);
            TE_CHECKBREAK_CODE(code);
            switch (cursor->getGeomCoding()) {
                case TAK::Engine::Feature::FeatureDefinition2::GeomBlob:
                {
                    if (!rawGeom.binary.value || !rawGeom.binary.len)
                        break;
                    GeometryClass geomClass;
                    code = GeometryFactory_getSpatiaLiteBlobGeometryType(&geomClass, nullptr, rawGeom.binary.value, rawGeom.binary.len);
                    TE_CHECKBREAK_CODE(code);
                    geomTypeMask = 1u << (unsigned)geomClass;
                    break;
                }
                case TAK::Engine::Feature::FeatureDefinition2::GeomWkb:
                {
                    if (!rawGeom.binary.value || !rawGeom.binary.len)
                        break;
                    GeometryClass geomClass;
                    code = GeometryFactory_getWkbGeometryType(&geomClass, nullptr, rawGeom.binary.value, rawGeom.binary.len);
                    TE_CHECKBREAK_CODE(code);
                    geomTypeMask = 1u << (unsigned)geomClass;
                    break;
                }
                case TAK::Engine::Feature::FeatureDefinition2::GeomGeometry:
                {
                    if (!rawGeom.object)
                        break;
                    const auto &geom = *static_cast<const atakmap::feature::Geometry *>(rawGeom.object);
                    geomTypeMask = getGeomFilterMask(geom.getType());
                    break;
                }
                default :
                {
                    const Feature2 *feature = nullptr;
                    code = cursor->get(&feature);
                    TE_CHECKBREAK_CODE(code);
                    const auto &geom = feature->getGeometry();
                    if (!geom)
                        break;
                    geomTypeMask = getGeomFilterMask(geom->getType());
                    break;
                }
            }

            // skip if the geometry type is filtered. note that this will also skip if the geometry
            // type could not be derived.
            if ((filteredGeometryTypes.mask & geomTypeMask) == geomTypeMask)
                continue;
        }

        int64_t id = 0;
        code = cursor->getId(&id);
        TE_CHECKBREAK_CODE(code);

        int64_t version = 0;
        code = cursor->getVersion(&version);
        TE_CHECKBREAK_CODE(code);

        ctx.startFeature(id, version);
        ctx.current->labels.invalid |= opts.forceLabelUpdateOnQuery;
        // feature specific push hints
        unsigned pushHints = basePushHints;
        if(opts.labelsEnabled && !!ctx.labelManager && ctx.current->labels.invalid)
            pushHints |= GLGeometryBatchBuilder::PushHints::ProcessLabels;
        if(ctx.featureLabels.visMap_.value.find(id) != ctx.featureLabels.visMap_.value.end())
            pushHints |= GLGeometryBatchBuilder::PushHints::RequireLabel;
        code = ctx.builder.push(*cursor, (GLGeometryBatchBuilder::PushHints)pushHints);
        ctx.endFeature();

        ctx.metrics.resultsSize++;

        TE_CHECKBREAK_CODE(code);
        n++;
    } while (true);
    if (code == TE_Done)
        code = TE_Ok;
    TE_CHECKRETURN_CODE(code);

    cursor.reset();

    int64_t e = Platform_systime_millis();
#if 0
    if(n)
        Logger_log(TELL_Info, "Processed %u features in %ums", (unsigned)n, (unsigned)(e - s));
#endif


    return code;
}

void GLBatchGeometryFeatureDataStoreRenderer3::onDataStoreContentChanged(FeatureDataStore2 &data_store) NOTHROWS
{
    this->invalidate();
}

/**************************************************************************/
// Hit Test Service

TAKErr GLBatchGeometryFeatureDataStoreRenderer3::hitTest2(Collection<int64_t> &fids, const float screenX, const float screenY, const GeoPoint &touch, const double resolution, const float radius, const std::size_t limit) NOTHROWS
{
    TAKErr code(TE_Ok);
    if (!currentView)
        return code;
    std::vector<uint32_t> featurehits;
    std::vector<uint32_t> labelhits;
    if (surface.isRenderThread()) {
        TAK::Engine::Port::STLVectorAdapter<uint32_t> fhtids_a(featurehits);
        const bool current = surface.isAttached();
        if (!current)
            surface.attach();
        renderer.hitTest(fhtids_a, *currentView, screenX, currentView->renderPass->scene.height - screenY, radius, limit);
        if(currentView && (!limit || featurehits.size() < limit) && !hitids.labels.empty()) {
            TAK::Engine::Port::STLVectorAdapter<uint32_t> lhtids_a(labelhits);
            currentView->getLabelManager()->hitTest(
                    lhtids_a,
                    screenX, currentView->renderPass->scene.height - screenY,
                    radius,
                    &touch,
                    limit ? limit - featurehits.size() : limit);
        }
        if (!current)
            surface.detach();
    } else if(currentView) {
        HitTestParams hitTestParams;
        hitTestParams.renderer = &renderer;
        hitTestParams.ids.features = &featurehits;
        if(!hitids.labels.empty())
            hitTestParams.ids.labels = &labelhits; // toggle label hit-testing
        hitTestParams.view = currentView;
        hitTestParams.screenX = screenX;
        // Need to flip the y-coordinate, so that the origin is at the bottom left instead of top left
        hitTestParams.screenY = currentView->renderPass->scene.height - screenY;
        hitTestParams.radius = radius;
        hitTestParams.geoPoint = &touch;
        hitTestParams.limit = limit;
        hitTestParams.done = false;

        surface.queueEvent(hitTest, std::move(std::unique_ptr<void, void(*)(const void *)>(&hitTestParams, Memory_leaker_const<void>)));
        {
            Monitor::Lock lock(hitTestParams.callbackExchange.monitor);
            while (!hitTestParams.done) {
                lock.wait(500u);
            }
        }
    }

    Monitor::Lock lock(monitor_);
    std::set<int64_t> ufids;
    const bool hasLabelHits = !labelhits.empty();
    for (auto& htid : featurehits) {
        const auto fid = hitids.features.find(htid);
        if (fid != hitids.features.end()) {
            fids.add(fid->second);
            if (hasLabelHits)
                ufids.insert(fid->second);
        }
    }
    if(!limit || fids.size() < limit) {
        for (auto& htid : labelhits) {
            const auto fid = hitids.labels.find(htid);
            // unmap and dedupe
            if (fid != hitids.labels.end() && ufids.find(fid->second) == ufids.end()) {
                fids.add(fid->second);
                if(fids.size() == limit)
                    break;
            }
        }
    }

    return code;
}

// Feature Edit Control

TAKErr GLBatchGeometryFeatureDataStoreRenderer3::startEditing(const int64_t fid) NOTHROWS {
    TAKErr code(TE_Ok);
    Monitor::Lock lock(monitor_);
    if (editor.editing.find(fid) != editor.editing.end())
        return TE_Ok;
    FeaturePtr_const f(nullptr, nullptr);
    code = dataStore.getFeature(f, fid);
    TE_CHECKRETURN_CODE(code);
    editor.editing[fid] = std::move(f);
    editor.edited.pending.erase(fid);
    editor.edited.purgeable.erase(fid);
    editor.dirty.features = true;

    // XXX - efficiency
    editor.dirty.hitids = false;
    std::vector<uint32_t> ignoreFeatures;
    ignoreFeatures.reserve(editor.editing.size()+editor.edited.pending.size()+editor.edited.purgeable.size());
    auto updateIgnoreFeatures = [this](std::vector<uint32_t> &ignoreFeatures, const std::map<int64_t, std::shared_ptr<const Feature2>> &features)
    {
        for (const auto efid: features) {
            auto e = std::find_if(hitids.features.begin(), hitids.features.end(), [&](const std::pair<const uint32_t, const int64_t> &entry)
            {
                return entry.second == efid.first;
            });
            if(e != hitids.features.end()) {
                ignoreFeatures.push_back(e->first);
            } else {
                // there is no `hitid` associated with the query context; mark dirty as the ID may
                editor.dirty.hitids |= true;
            }
        }
    };
    updateIgnoreFeatures(ignoreFeatures, editor.editing);
    updateIgnoreFeatures(ignoreFeatures, editor.edited.pending);
    updateIgnoreFeatures(ignoreFeatures, editor.edited.purgeable);

    renderer.setIgnoreFeatures(ignoreFeatures.data(), ignoreFeatures.size());

    return TE_Ok;
}
TAKErr GLBatchGeometryFeatureDataStoreRenderer3::stopEditing(const int64_t fid) NOTHROWS
{
    TAKErr code(TE_Ok);
    Monitor::Lock lock(monitor_);
    auto it = editor.editing.find(fid);
    if(it == editor.editing.end())
        return TE_Ok;

    const auto f = it->second;
    editor.editing.erase(it);
    editor.edited.pending[fid] = f;
    editor.dirty.features = true;

    return TE_Ok;
}
TAKErr GLBatchGeometryFeatureDataStoreRenderer3::updateFeature(const int64_t fid, const unsigned updatePropertyMask, const char *name, const atakmap::feature::Geometry *geometry, const atakmap::feature::Style *style, const TAK::Engine::Feature::AltitudeMode altitudeMode, const double extrude) NOTHROWS
{
    TAKErr code(TE_Ok);
    Monitor::Lock lock(monitor_);
    std::map<int64_t, std::shared_ptr<const Feature2>>::iterator it;
    do {
        it = editor.editing.find(fid);
        if(it != editor.editing.end())
            break;
        it = editor.edited.pending.find(fid);
        if(it != editor.edited.pending.end())
            break;
        it = editor.edited.purgeable.find(fid);
        if(it != editor.edited.purgeable.end())
            break;
        return TE_Ok;
    } while(false);

    auto &f = it->second;
    GeometryPtr updateGeom(nullptr, nullptr);
    const auto g = (updatePropertyMask&FeatureDataStore2::FeatureQueryParameters::GeometryField) ? geometry : f->getGeometry();
    if(g)
        updateGeom = GeometryPtr(g->clone(), atakmap::feature::destructGeometry);
    StylePtr updateStyle(nullptr, nullptr);
    const auto s = (updatePropertyMask&FeatureDataStore2::FeatureQueryParameters::StyleField) ? style : f->getStyle();
    if(s)
        updateStyle = StylePtr(s->clone(), atakmap::feature::Style::destructStyle);
    AttributeSetPtr updateAttrs(nullptr, nullptr);
    f.reset(new Feature2(
                f->getId(),
                f->getFeatureSetId(),
                (updatePropertyMask&FeatureDataStore2::FeatureQueryParameters::NameField) ? name : f->getName(),
                std::move(updateGeom),
                (updatePropertyMask&FeatureDataStore2::FeatureQueryParameters::GeometryField) ? altitudeMode : f->getAltitudeMode(),
                (updatePropertyMask&FeatureDataStore2::FeatureQueryParameters::GeometryField) ? extrude : f->getExtrude(),
                std::move(updateStyle),
                AttributeSetPtr(nullptr, nullptr),
                f->getVersion()+1u));
    editor.dirty.features = true;

    const auto fg = f->getGeometry();
    if(fg && f->getAltitudeMode() == TEAM_ClampToGround && surface_ctrl_) {
        // queue a streaming update for a surface feature
        try {
            const auto mbb = f->getGeometry()->getEnvelope();
            surface_ctrl_->markDirty(Envelope2(mbb.minX, mbb.minY, 0.0, mbb.maxX, mbb.maxY, 0.0), true);
        } catch(std::length_error &) {} // thrown if empty geometry
    } else if(context_){
        context_->requestRefresh();
    }

    return TE_Ok;
}

GLBatchGeometryFeatureDataStoreRenderer3::FeaturesLabelControlImpl::FeaturesLabelControlImpl(GLBatchGeometryFeatureDataStoreRenderer3 &renderer3) NOTHROWS :
        renderer(renderer3)
{}
GLBatchGeometryFeatureDataStoreRenderer3::FeaturesLabelControlImpl::~FeaturesLabelControlImpl() NOTHROWS
{}

void GLBatchGeometryFeatureDataStoreRenderer3::FeaturesLabelControlImpl::setShapeCenterMarkersVisible(const bool v) NOTHROWS
{
    Monitor::Lock lock(renderer.monitor_);
    state.shapeCenterVisible_ = v;
    renderer.invalidateNoSync();
}
bool GLBatchGeometryFeatureDataStoreRenderer3::FeaturesLabelControlImpl::getShapeCenterMarkersVisible() NOTHROWS
{
    Monitor::Lock lock(renderer.monitor_);
    return state.shapeCenterVisible_;
}
void GLBatchGeometryFeatureDataStoreRenderer3::FeaturesLabelControlImpl::setShapeLabelVisible(int64_t fid, bool visible) NOTHROWS
{
    Monitor::Lock lock(renderer.monitor_);
    if(visible)
        state.visMap_.value.insert(fid);
    else
        state.visMap_.value.erase(fid);
    state.visMap_.updated.insert(fid);
    renderer.invalidateNoSync();
}
bool GLBatchGeometryFeatureDataStoreRenderer3::FeaturesLabelControlImpl::getShapeLabelVisible(int64_t fid) NOTHROWS
{
    Monitor::Lock lock(renderer.monitor_);
    return (state.visMap_.value.find(fid) != state.visMap_.value.end());
}
void GLBatchGeometryFeatureDataStoreRenderer3::FeaturesLabelControlImpl::setDefaultLabelBackground(const uint32_t bgColor, const bool override) NOTHROWS
{
    Monitor::Lock lock(renderer.monitor_);
    state.background.color = bgColor;
    state.background.override = override;
    renderer.invalidateNoSync();
}
void GLBatchGeometryFeatureDataStoreRenderer3::FeaturesLabelControlImpl::getDefaultLabelBackground(uint32_t *color, bool *override) NOTHROWS
{
    Monitor::Lock lock(renderer.monitor_);
    *color = state.background.color;
    *override = state.background.override;
}
void GLBatchGeometryFeatureDataStoreRenderer3::FeaturesLabelControlImpl::setDefaultLabelLevelOfDetail(const std::size_t minLod, const std::size_t maxLod) NOTHROWS
{
    Monitor::Lock lock(renderer.monitor_);
    state.levelOfDetail.minLod = minLod;
    state.levelOfDetail.maxLod = maxLod;
    renderer.invalidateNoSync();
}
void GLBatchGeometryFeatureDataStoreRenderer3::FeaturesLabelControlImpl::getDefaultLabelLevelOfDetail(std::size_t *minLod, std::size_t *maxLod) NOTHROWS
{
    Monitor::Lock lock(renderer.monitor_);
    *minLod = state.levelOfDetail.minLod;
    *maxLod = state.levelOfDetail.maxLod;
}

namespace
{
    void cb_mapBufferImpl(void* opaque) NOTHROWS
    {
        auto arg = static_cast<CallbackOpaque *>(opaque);
        Monitor::Lock lock(arg->cbex->monitor);
        if (arg->cbex->terminated)
            return;

        arg->bundle->handle = GL_NONE;
        arg->bundle->buffer = nullptr;
        glGenBuffers(1u, &arg->bundle->handle);
        if(arg->bundle->handle) {
            glBindBuffer(GL_ARRAY_BUFFER, arg->bundle->handle);
            glBufferData(GL_ARRAY_BUFFER, arg->bundle->bufsize, nullptr, GL_STATIC_DRAW);
            arg->bundle->buffer = glMapBufferRange(GL_ARRAY_BUFFER, 0, arg->bundle->bufsize, GL_MAP_WRITE_BIT);
        }
        glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
        arg->bundle->done = true;

        lock.signal();
    }
    void cb_unmapBufferImpl(void* opaque) NOTHROWS
    {
        auto arg = static_cast<CallbackOpaque *>(opaque);
        Monitor::Lock lock(arg->cbex->monitor);
        if (arg->cbex->terminated)
            return;


        glBindBuffer(GL_ARRAY_BUFFER, arg->bundle->handle);
        glUnmapBuffer(GL_ARRAY_BUFFER);
        glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
        arg->bundle->done = true;

        lock.signal();
    }
    void cb_getIconImpl(BuilderCallbackBundle *bundle) NOTHROWS
    {
        bundle->icon.texid = GL_NONE;
        do {
            const char* iconUri = bundle->iconUri;
            auto &loader = bundle->iconLoader;
            Lock lock(*bundle->iconLoader.mutex);
            if (loader.failed->find(bundle->iconUri) != loader.failed->end()) {
                if(!loader.defaultIconOnLoadFailure)
                    break;
                // icon won't load, try default
                if (!(*loader.defaultIconUri)) {
                    ConfigOptions_getOption(*loader.defaultIconUri, "defaultIconUri");
                    if (!(*loader.defaultIconUri))
                        *loader.defaultIconUri =  "asset:/icons/reference_point.png";
                }
                iconUri = *loader.defaultIconUri;
            }
            // check atlas
            if (loader.atlas) {
                int64_t key;
                if (loader.atlas->getTextureKey(&key, iconUri) == TE_Ok) {
                    int texid;
                    loader.atlas->getTexId(&texid, key);
                    bundle->icon.texid = texid;
                    atakmap::math::Rectangle<float> rect;
                    loader.atlas->getImageRect(&rect, key, true);
                    bundle->icon.u0 = rect.x;
                    bundle->icon.v0 = rect.y;
                    bundle->icon.u1 = rect.width;
                    bundle->icon.v1 = rect.height;
                    loader.atlas->getImageWidth(&bundle->icon.width, key);
                    loader.atlas->getImageHeight(&bundle->icon.height, key);
                    break;
                }
            }

            // already queued for load
            const auto& loading = loader.loading->find(iconUri);
            if (loading != loader.loading->end()) {
                // XXX - check complete
                break;
            }

            // queue load
            AsyncBitmapLoader2 *bitmapLoader;
            GLMapRenderGlobals_getBitmapLoader(&bitmapLoader, *bundle->ctx);

            AsyncBitmapLoader2::Task task;
            if(bitmapLoader->loadBitmapUri(task, iconUri) == TE_Ok)
                (*loader.loading)[iconUri] = task;
            else
                loader.failed->insert(iconUri);
        } while (false);
    }

    BuilderQueryContext::BuilderQueryContext(RenderContext &ctx_, std::size_t &ctxid_) NOTHROWS :
        ctx(ctx_),
        initCtxId(ctxid_),
        activeCtxId(ctxid_),
        cbex(std::make_shared<CallbackExchange>())
    {}
    BuilderQueryContext::~BuilderQueryContext() NOTHROWS
    {
        if(labelManager) {
            for (auto it: featureRecords) {
                auto &record = it.second;
                // remove associated label(s)
                if (record.labels.id != GLLabelManager::NO_ID)
                    labelManager->removeLabel(record.labels.id);
                for (const auto &id: record.labels.overflow)
                    labelManager->removeLabel(id);
            }
            featureRecords.clear();
        }
    }
    void BuilderQueryContext::startFeature(const int64_t fid, const int64_t version) NOTHROWS
    {
        current = &featureRecords[fid];
        if(current->fid == FeatureDataStore2::FEATURE_ID_NONE) {
            // new record
            current->fid = fid;
            current->hitid = 0xFF000000u | (nextHitId+1u);

            // 24-bit ID, allows for ~16m IDs before reuse
            nextHitId = (nextHitId + 1) % 0xFFFFFEu;
        }
        // process labels if the feature has updated
        current->labels.invalid = (current->version != version);
        if(current->labels.invalid && current->labels.hitTestable) {
            if(current->labels.id != GLLabelManager::NO_ID)
                hitTestLabels.erase(current->labels.id);
            for(const auto lblid : current->labels.overflow)
                hitTestLabels.erase(lblid);
            current->labels.hitTestable = false;
        }

        current->labels.deferredRemoveIndex = 0;
        current->version = version;
        current->touch = queryCount;
    }
    void BuilderQueryContext::endFeature() NOTHROWS
    {
        current = nullptr;
    }
    TAKErr BuilderQueryContext::mapBuffer(GLuint* handle, void** buffer, const std::size_t size) NOTHROWS
    {        
        BuilderCallbackBundle arg;
        arg.handle = GL_NONE;
        arg.buffer = nullptr;
        arg.bufsize = size;

        CallbackOpaque opaque;
        opaque.bundle = &arg;
        opaque.cbex = cbex;

        if (ctx.isRenderThread()) {
            cb_mapBufferImpl(&opaque);
        } else {
            std::unique_ptr<void, void(*)(const void*)> glopaque(nullptr, nullptr);
            const TAKErr code = cb_alloc.allocate(glopaque);
            TE_CHECKRETURN_CODE(code);
            *(static_cast<CallbackOpaque*>(glopaque.get())) = opaque;
            ctx.queueEvent(cb_mapBufferImpl, std::move(glopaque));
            {
                Monitor::Lock lock(cbex->monitor);
                do {
                    if (arg.done)
                        break;
                    cbex->terminated = (initCtxId != activeCtxId);
                    if (cbex->terminated)
                        break;
                    lock.wait(500LL);
                } while(true);
            }
        }

        if (arg.done) {
            *handle = arg.handle;
            *buffer = arg.buffer;
        } else {
            // terminated
            *handle = GL_NONE;
            *buffer = nullptr;
        }
        return !!(*buffer) ? TE_Ok : TE_Interrupted;
    }
    TAKErr BuilderQueryContext::unmapBuffer(const GLuint handle) NOTHROWS
    {
        BuilderCallbackBundle arg;
        arg.handle = handle;

        CallbackOpaque opaque;
        opaque.bundle = &arg;
        opaque.cbex = cbex;

        if (ctx.isRenderThread()) {
            cb_unmapBufferImpl(&opaque);
        } else {
            std::unique_ptr<void, void(*)(const void*)> glopaque(nullptr, nullptr);
            const TAKErr code = cb_alloc.allocate(glopaque);
            TE_CHECKRETURN_CODE(code);
            *(static_cast<CallbackOpaque*>(glopaque.get())) = opaque;
            ctx.queueEvent(cb_unmapBufferImpl, std::move(glopaque));
            {
                Monitor::Lock lock(cbex->monitor);
                do {
                    if (arg.done)
                        break;
                    cbex->terminated = (initCtxId != activeCtxId);
                    if (cbex->terminated)
                        break;
                    lock.wait(500LL);
                } while(true);
            }
        }
        return arg.done ? TE_Ok : TE_Interrupted;
    }

    TAKErr getElevation(double* value, const double latitude, const double longitude_, const TAK::Engine::Renderer::Elevation::TerrainTile &tile) NOTHROWS
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
        const double altAboveSurface = 30000.0;

        // AABB/bounds check
        const TAK::Engine::Feature::Envelope2 aabb_wgs84 = tile.aabb_wgs84;
        if (!atakmap::math::Rectangle<double>::contains(aabb_wgs84.minX,
                                                        aabb_wgs84.minY,
                                                        aabb_wgs84.maxX,
                                                        aabb_wgs84.maxY,
                                                        longitude, latitude)) {
            return TE_Done;
        }

        // the tile has no elevation data values...
        if (!tile.hasData) {
            // if on a border, continue as other border tile may have data, else break
            if(aabb_wgs84.minX < longitude && aabb_wgs84.maxX > longitude &&
                aabb_wgs84.minY < latitude && aabb_wgs84.maxY > latitude) {

                elevation = 0.0;
                return TE_Ok;
            } else {
                return TE_Done;
            }
        }
        if(!tile.heightmap) {
            // if there's no heightmap, shoot a nadir ray into the
            // terrain tile mesh and obtain the height at the
            // intersection
            Projection2Ptr proj(nullptr, nullptr);
            code = ProjectionFactory3_create(proj, tile.data.srid);
            TE_CHECKRETURN_CODE(code);

            Matrix2 invLocalFrame;
            tile.data.localFrame.createInverse(&invLocalFrame);

            // obtain the ellipsoid surface point
            TAK::Engine::Math::Point2<double> surface;
            code = proj->forward(&surface, GeoPoint2(latitude, longitude));
            TE_CHECKRETURN_CODE(code);

            invLocalFrame.transform(&surface, surface);

            // obtain the point at altitude
            TAK::Engine::Math::Point2<double> above;
            code = proj->forward(&above, GeoPoint2(latitude, longitude, 30000.0, TAK::Engine::Core::AltitudeReference::HAE));
            TE_CHECKRETURN_CODE(code);

            invLocalFrame.transform(&above, above);

            // construct the geometry model and compute the intersection
            TAK::Engine::Math::Mesh model(tile.data.value, nullptr);

            TAK::Engine::Math::Point2<double> isect;
            if (!model.intersect(&isect, Ray2<double>(above, Vector4<double>(surface.x - above.x, surface.y - above.y, surface.z - above.z))))
                return TE_Done;

            tile.data.localFrame.transform(&isect, isect);
            GeoPoint2 geoIsect;
            code = proj->inverse(&geoIsect, isect);
            TE_CHECKRETURN_CODE(code);

            elevation = geoIsect.altitude;
            code = TE_Ok;
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
            elevation = p.z;
            code = TE_Ok;
        }

        *value = elevation;

        return code;
    }
    TAKErr BuilderQueryContext::getElevation(double* value, const double latitude, const double longitude) NOTHROWS
    {
        *value = NAN;
        if (terrainTiles.last && ::getElevation(value, latitude, longitude, *terrainTiles.last) == TE_Ok)
            return TE_Ok;
        else if(terrainTiles.last)
            terrainTiles.last.reset();
        for (const auto &tile : terrainTiles.value) {
            if (::getElevation(value, latitude, longitude, *tile) == TE_Ok) {
                terrainTiles.last = tile;
                return TE_Ok;
            }
        }

        return TE_Done;
    }
    TAKErr BuilderQueryContext::getIcon(GLuint *id, float *u0, float *v0, float *u1, float *v1, std::size_t *w, std::size_t *h, float *rotation, bool *isAbsoluteRotation, const char* uri) NOTHROWS
    {
        if (!uri)
            return TE_InvalidArg;

        const auto& entry = iconEntryCache.find(uri);
        if (entry != iconEntryCache.end()) {
            *id = entry->second.texid;
            *u0 = entry->second.u0;
            *v0 = entry->second.v0;
            *u1 = entry->second.u1;
            *v1 = entry->second.v1;
            *w = std::min(entry->second.width, iconDimensionConstraint);
            *h = std::min(entry->second.height, iconDimensionConstraint);
            *rotation = entry->second.rotation;
            *isAbsoluteRotation = entry->second.isAbsoluteRotation;
            return TE_Ok;
        }
        BuilderCallbackBundle arg;
        arg.iconUri = uri;
        arg.ctx = &ctx;
        arg.iconLoader = iconLoader;

        cb_getIconImpl(&arg);
        if (!arg.icon.texid)
            return TE_Busy;
        *id = arg.icon.texid;
        *u0 = arg.icon.u0;
        *v0 = arg.icon.v0;
        *u1 = arg.icon.u1;
        *v1 = arg.icon.v1;
        *w = arg.icon.width;
        *h = arg.icon.height;
        *rotation = arg.icon.rotation;
        *isAbsoluteRotation = arg.icon.isAbsoluteRotation;
        iconEntryCache[uri] = arg.icon;
        return TE_Ok;
    }
    TAKErr BuilderQueryContext::addLabel(const GLLabel& lbl_) NOTHROWS
    {
        TAKErr code(TE_Ok);
        if (!current)
            return TE_IllegalState;
        if (!labelManager)
            return TE_IllegalState;

        GLLabel lbl(lbl_);
        return addLabel(std::move(lbl));
    }
    TAKErr BuilderQueryContext::addLabel(GLLabel &&lbl) NOTHROWS
    {
        TAKErr code(TE_Ok);
        if (!current)
            return TE_IllegalState;
        if (!labelManager)
            return TE_IllegalState;

        lbl.setAltitudeMode(TAK::Engine::Feature::AltitudeMode::TEAM_ClampToGround);
        if(labelRenderPump)
            lbl.setTouchLabelVisibility(labelRenderPump);

        uint32_t labelid;
        const auto hitTestable = lbl.isHitTestable();
        if (current->labels.deferredRemoveIndex == 0) {
            // primary label
            if (current->labels.id != GLLabelManager::NO_ID)
                GLLabelManager_updateLabel(*labelManager, current->labels.id, std::move(lbl));
            else
                current->labels.id = labelManager->addLabel(lbl);
            labelid = current->labels.id;
        } else if (current->labels.deferredRemoveIndex <= current->labels.overflow.size()) {
            // reuse overflow label
            labelid = current->labels.overflow[current->labels.deferredRemoveIndex - 1];
            GLLabelManager_updateLabel(*labelManager, labelid, std::move(lbl));
        } else {
            // new overflow label
            labelid = labelManager->addLabel(lbl);
            current->labels.overflow.push_back(labelid);
        }

        if(hitTestable) {
            hitTestLabels[labelid] = current->fid;
        }

        ++current->labels.deferredRemoveIndex;

        return TE_Ok;
    }
    uint32_t BuilderQueryContext::reserveHitId() NOTHROWS
    {
        return current ? current->hitid : 0u;
    }

    TAKErr BuilderQueryContext::getMesh(std::shared_ptr<const TAK::Engine::Model::Mesh>& mesh, const char *uri) NOTHROWS
    {
        if (!uri) {
            return TE_InvalidArg;
        }
        auto loadedMesh = loadedMeshes->find(uri);
        if (loadedMesh == loadedMeshes->end())
        {
            TAK::Engine::Model::ScenePtr scenePtr(nullptr, nullptr);
            TAKErr code = TAK::Engine::Model::SceneFactory_create(scenePtr, uri, nullptr, nullptr, nullptr);
            TE_CHECKRETURN_CODE(code)
            Collection<std::shared_ptr<TAK::Engine::Model::SceneNode>>::IteratorPtr iter(nullptr, nullptr);
            scenePtr->getRootNode().getChildren(iter);
            do {
                std::shared_ptr<TAK::Engine::Model::SceneNode> sceneNode;
                code = iter->get(sceneNode);
                TE_CHECKBREAK_CODE(code)
                if (sceneNode->hasMesh()) {
                    code = sceneNode->loadMesh(mesh);
                    if (code == TE_Ok) {
                        loadedMesh = loadedMeshes->insert( loadedMeshes->end(), {uri, mesh});
                        // TODO - we only load the first mesh instead of all meshes.
                        break;
                    }
                }
                code = iter->next();
                TE_CHECKBREAK_CODE(code)
            } while (true);
        } else {
            mesh = loadedMesh->second;
        }
        return TE_Ok;
    }

    void hitTest(void *params) NOTHROWS {
        auto *hitTestParams = static_cast<HitTestParams*>(params);

        Monitor::Lock lock(hitTestParams->callbackExchange.monitor);
        if (hitTestParams->callbackExchange.terminated)
            return;
        // hit-test features
        TAK::Engine::Port::STLVectorAdapter<uint32_t> htids_a(*hitTestParams->ids.features);
        hitTestParams->renderer->hitTest(htids_a, *hitTestParams->view, hitTestParams->screenX, hitTestParams->screenY, hitTestParams->radius, hitTestParams->limit);
        if(hitTestParams->view &&
           (!hitTestParams->limit || hitTestParams->ids.features->size() < hitTestParams->limit) &&
           hitTestParams->ids.labels) {

            TAK::Engine::Port::STLVectorAdapter<uint32_t> lhtids_a(*hitTestParams->ids.labels);
            hitTestParams->view->getLabelManager()->hitTest(
                    lhtids_a,
                    hitTestParams->screenX, hitTestParams->screenY,
                    hitTestParams->radius,
                    hitTestParams->geoPoint,
                    hitTestParams->limit ?
                            hitTestParams->limit - hitTestParams->ids.features->size() :
                            hitTestParams->limit);
        }
        hitTestParams->done = true;
        lock.signal();
    }
}
