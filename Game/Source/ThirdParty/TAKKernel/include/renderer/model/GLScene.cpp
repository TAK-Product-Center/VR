#include "renderer/GL.h"

#include "renderer/model/GLScene.h"

#include "core/Projection2.h"
#include "core/ProjectionFactory3.h"
#include "elevation/ElevationManager.h"
#include "feature/GeometryTransformer.h"
#include "feature/LineString2.h"
#include "model/MeshTransformer.h"
#include "renderer/model/HitTestControl.h"
#include "renderer/model/SceneObjectControl2.h"
#include "thread/Lock.h"
#include "util/ConfigOptions.h"
#include "util/Memory.h"
#include "util/Tasking.h"
#include "renderer/GLWorkers.h"
#include "renderer/GLDepthSampler.h"
#include "renderer/model/GLMesh.h"
#include "renderer/GLES20FixedPipeline.h"

#define PROFILE_HIT_TESTS 0

#if PROFILE_HIT_TESTS
#include <chrono>
#endif


using namespace TAK::Engine::Renderer::Model;

using namespace TAK::Engine::Core;
using namespace TAK::Engine::Elevation;
using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Math;
using namespace TAK::Engine::Model;
using namespace TAK::Engine::Port;
using namespace TAK::Engine::Renderer::Core;
using namespace TAK::Engine::Thread;
using namespace TAK::Engine::Util;
using namespace atakmap::renderer;

namespace
{
    struct Indicator
    {
        double minDrawResolution{ 0.0 };
        struct {
            Envelope2 value;
            bool valid{ false };
        } bounds;
        std::shared_ptr<GLContentIndicator> value;
    };

    TAKErr buildNodeList(std::list<std::shared_ptr<SceneNode>> &value, SceneNode &node) NOTHROWS
    {
        TAKErr code(TE_Ok);
        if (node.hasChildren()) {
            Collection<std::shared_ptr<SceneNode>>::IteratorPtr iter(nullptr, nullptr);
            code = node.getChildren(iter);
            TE_CHECKRETURN_CODE(code);

            do {
                std::shared_ptr<SceneNode> child;
                code = iter->get(child);
                TE_CHECKBREAK_CODE(code);

                if (child->hasMesh())
                    value.push_back(child);
                if (child->hasSubscene())
                    value.push_back(child);

                if (child->hasChildren())
                    buildNodeList(value, *child);

                code = iter->next();
                TE_CHECKBREAK_CODE(code);
            } while (true);
            if(code == TE_Done)
                code = TE_Ok;
            TE_CHECKRETURN_CODE(code);
        }
        return code;
    }
}

class GLScene::SceneControlImpl : public SceneObjectControl2
{
public :
    SceneControlImpl(GLScene &owner) NOTHROWS;
public :
    TAKErr setLocation(const GeoPoint2 &location, const Matrix2 *localFrame, const int srid, const AltitudeMode altitudeMode) NOTHROWS override;
    TAKErr getInfo(SceneInfo *value) NOTHROWS override;
    TAKErr addUpdateListener(UpdateListener *l) NOTHROWS override;
    TAKErr removeUpdateListener(const UpdateListener &l) NOTHROWS override;
    TAKErr clampToGround() NOTHROWS override;
    TAKErr setXrayColor(const unsigned int color) NOTHROWS override;
    TAKErr getXrayColor(unsigned int *color) NOTHROWS override;
public :
    void dispatchBoundsChanged(const Envelope2 &aabb, const double minGsd, const double maxGsd) NOTHROWS;
    void dispatchClampToGroundOffsetComputed(const double offset) NOTHROWS;
private :
    GLScene &owner_;
    std::set<UpdateListener *> listeners_;
    Mutex mutex_;
};

struct GLScene::SharedContext
{
    RenderContext* ctx{ nullptr };
    std::shared_ptr<MaterialManager> materials;
    std::shared_ptr<GLSceneNodeLoader> nodeLoader;
    struct {
        std::shared_ptr<ThreadPool> pool;
        std::deque<std::weak_ptr<GLScene::SceneCore>> queue;
        Monitor monitor;
    } sceneInitializer;
    struct {
        Mutex mutex;
        std::map<int64_t, std::shared_ptr<Indicator>> value;
    } indicators;
};

struct GLScene::SceneCore
{
    SceneCore(const SceneInfo &info, ScenePtr &&scene, const GLSceneSpi::Options &opts) :
        mutex_(TEMT_Recursive),
        info_(info),
        scene_(std::move(scene)),
        opts_(opts)
    {}

    Mutex mutex_;
    SceneInfo info_;
    ScenePtr scene_;
    GLSceneSpi::Options opts_;
    bool loading_ {false};
    std::map<TAK::Engine::Model::SceneNode *, std::shared_ptr<GLSceneNode>> node_renderers_;
    bool clampRequested{ false };
    std::list<std::shared_ptr<TAK::Engine::Model::SceneNode>> display_nodes_;
    std::unique_ptr<SceneControlImpl> sceneCtrl;
    std::shared_ptr<Indicator> indicator;
};


GLScene::GLScene(RenderContext& ctx, const SceneInfo& info, const GLSceneSpi::Options& opts) NOTHROWS :
    GLScene(ctx, info, ScenePtr(nullptr, nullptr), opts) {}

GLScene::GLScene(TAK::Engine::Core::RenderContext& ctx, const TAK::Engine::Model::SceneInfo& info, TAK::Engine::Model::ScenePtr&& scene, const GLSceneSpi::Options& opts) NOTHROWS :
    ctx_(ctx),
    core_(new SceneCore(info, std::move(scene), opts)),
    location_dirty_(false)
{
    core_->clampRequested = (info.altitudeMode == TEAM_ClampToGround);
    core_->sceneCtrl.reset(new SceneControlImpl(*this));

    controls_[SceneObjectControl_getType()] = (void*)static_cast<SceneObjectControl*>(core_->sceneCtrl.get());
    controls_[SceneObjectControl2_getType()] = (void*)static_cast<SceneObjectControl2*>(core_->sceneCtrl.get());
}

GLScene::~GLScene() NOTHROWS
{}

void GLScene::start() NOTHROWS
{}
void GLScene::stop() NOTHROWS
{}
int GLScene::getRenderPass() NOTHROWS
{
    return GLMapView2::Sprites | GLMapView2::XRay;
}
void GLScene::draw(const GLGlobeBase &view, const int renderPass) NOTHROWS
{
    if (!(getRenderPass() & renderPass))
        return;
    if(!shared_context_) {
        shared_context_ = getSharedContext(view.getRenderContext());
    }

    // init tile grid, if necessary
    SceneInfo locationUpdate;
    bool updateLocation = false;
    {
        Lock lock(core_->mutex_);
        if(core_->info_.minDisplayResolution && view.renderPass->drawMapResolution > core_->info_.minDisplayResolution) {
            // not visible per resolution; draw indicator if applicable
            if (ssid_ && !core_->loading_ && !core_->indicator) {
                Lock ilock(shared_context_->indicators.mutex);
                do {
                    auto entry = shared_context_->indicators.value.find(ssid_);
                    if(entry != shared_context_->indicators.value.end()) {
                        core_->indicator = entry->second;
                        break;
                    }
                    core_->indicator.reset(new Indicator());
                    core_->indicator->value.reset(new GLContentIndicator(view.context));
                    shared_context_->indicators.value[ssid_] = core_->indicator;
                } while (false);

                do {
                    if (!core_->info_.location && !core_->info_.aabb)
                        break;
                    Envelope2 sceneBounds;
                    if (core_->info_.aabb) {
                        Envelope2 aabb_wgs84;
                        Matrix2 localFrame;
                        if (core_->info_.localFrame)
                            localFrame = *core_->info_.localFrame;
                        if (Mesh_transform(&sceneBounds, *core_->info_.aabb, MeshTransformOptions(core_->info_.srid, localFrame), MeshTransformOptions(4326)) != TE_Ok)
                            break;
                    } else if (core_->info_.location) {
                        sceneBounds.minX = core_->info_.location->longitude;
                        sceneBounds.minY = core_->info_.location->latitude;
                        sceneBounds.maxX = core_->info_.location->longitude;
                        sceneBounds.maxY = core_->info_.location->latitude;
                    }

                    if(core_->indicator->bounds.valid) {
                        core_->indicator->bounds.value.minX = std::min(core_->indicator->bounds.value.minX, sceneBounds.minX);
                        core_->indicator->bounds.value.minY = std::min(core_->indicator->bounds.value.minY, sceneBounds.minY);
                        core_->indicator->bounds.value.maxX = std::max(core_->indicator->bounds.value.maxX, sceneBounds.maxX);
                        core_->indicator->bounds.value.maxY = std::max(core_->indicator->bounds.value.maxY, sceneBounds.maxY);
                    } else {
                        core_->indicator->bounds.value = sceneBounds;
                        core_->indicator->bounds.valid = true;
                    }

                    TAK::Engine::Port::String modelIcon;
                    if (ConfigOptions_getOption(modelIcon, "TAK.Engine.Model.default-icon") != TE_Ok) modelIcon = "null";
                    core_->indicator->value->setIcon(
                        GeoPoint2(
                            (core_->indicator->bounds.value.minY+core_->indicator->bounds.value.maxY)/2.0,
                            (core_->indicator->bounds.value.minX+core_->indicator->bounds.value.maxX)/2.0),
                        modelIcon);
                } while (false);

                core_->indicator->minDrawResolution = std::max(core_->indicator->minDrawResolution, core_->info_.minDisplayResolution);
            }
            if (core_->indicator && core_->indicator->value && view.renderPass->drawMapResolution > core_->indicator->minDrawResolution)
                core_->indicator->value->draw(view, renderPass);
            return;
        } else if(!core_->scene_) {
            // kick off initialization if zoomed in sufficiently
            if (!core_->loading_) {
                core_->loading_ = true;
                Monitor::Lock qlock(shared_context_->sceneInitializer.monitor);
                shared_context_->sceneInitializer.queue.push_back(core_);
                qlock.broadcast();
            }
            return;
        }

        if (location_dirty_) {
            updateLocation = true;
            locationUpdate = this->core_->info_;
            location_dirty_ = false;
        }
    }

    // XXX - can tile AOI be quickly computed???

    // XXX - should be graph traversal...

    // compute and draw tiles in view

    std::map<SceneNode *, std::shared_ptr<GLSceneNode>>::iterator it;
    std::list<GLSceneNode *> drawable;
    for (it = core_->node_renderers_.begin(); it != core_->node_renderers_.end(); it++) {
        GLSceneNode &tile = *it->second;
        if (updateLocation) {
            tile.setLocation(*locationUpdate.location, locationUpdate.localFrame.get(), locationUpdate.srid, locationUpdate.altitudeMode);
        }

        // XXX - more efficient testing

        // test in view
        if (renderPass&(GLMapView2::Sprites|GLMapView2::XRay)) {
#if 1
            GLSceneNode::RenderVisibility renderable = tile.isRenderable(view);
#else
            GLSceneNode::RenderVisibility renderable = GLSceneNode::Draw;
#endif
            if (renderable == GLSceneNode::RenderVisibility::None) {
                shared_context_->nodeLoader->cancel(tile);
                if (tile.hasLODs())
                    tile.unloadLODs();
                else
                    tile.release();
            } else {
                const bool prefetch = (renderable == GLSceneNode::RenderVisibility::Prefetch);

                if (!tile.isLoaded(view)) {
                    bool queued;
                    if ((shared_context_->nodeLoader->isQueued(&queued, tile, prefetch) == TE_Ok) && !queued) {
                        GLSceneNode::LoadContext loadContext;
                        if (tile.prepareLoadContext(&loadContext, view) == TE_Ok)
                            shared_context_->nodeLoader->enqueue(it->second, std::move(loadContext), prefetch, view.renderPass->drawSrid);
                    }
                }

                // draw
                if (!prefetch)
                    drawable.push_back(&tile);
            }
        }
    }

    // RAII construct to restore render state
    class RenderStateRestore
    {
    public :
        RenderStateRestore() NOTHROWS : _state(RenderState_getCurrent())
        {}
        ~RenderStateRestore() NOTHROWS { reset(); }
    public :
        /** resets to initial state */
        void reset() NOTHROWS { RenderState_makeCurrent(_state); }
    private :
        RenderState _state;
    };
    RenderStateRestore restore;

    RenderState state = RenderState_getCurrent();

    // xray draw
    if(core_->info_.xrayColor && (renderPass&GLMapView2::XRay) && isXRayCapable()) {
        // only draw samples below surface
        if (!state.depth.enabled) {
            state.depth.enabled = true;
            glEnable(GL_DEPTH_TEST);
        }
        if (state.depth.mask) {
            state.depth.mask = GL_FALSE;
            glDepthMask(state.depth.mask);
        }
        if (state.depth.func != GL_GREATER) {
            state.depth.func = GL_GREATER;
            glDepthFunc(state.depth.func);
        }

        for (auto it_drawables = drawable.begin(); it_drawables != drawable.end(); it_drawables++) {
            (*it_drawables)->setColor(ColorControl::Replace, core_->info_.xrayColor);
            (*it_drawables)->draw(view, state, ((renderPass|GLMapView2::Sprites)&~GLMapView2::XRay));
        }
    }
    if (GLMapView2::Sprites) {
        //  regular draw
        if (!state.depth.enabled) {
            state.depth.enabled = true;
            glEnable(GL_DEPTH_TEST);
        }
        if (!state.depth.mask) {
            state.depth.mask = GL_TRUE;
            glDepthMask(state.depth.mask);
        }
        if (state.depth.func != GL_LEQUAL) {
            state.depth.func = GL_LEQUAL;
            glDepthFunc(state.depth.func);
        }
        for (auto it_drawables = drawable.begin(); it_drawables != drawable.end(); it_drawables++) {
            (*it_drawables)->setColor(ColorControl::Modulate, 0xFFFFFFFFu);
            (*it_drawables)->draw(view, state, renderPass);
        }
        if (state.shader.get()) {
            for (std::size_t i = state.shader->numAttribs; i > 0u; i--)
                glDisableVertexAttribArray(static_cast<GLuint>(i - 1u));
        }

        restore.reset();
    }
}
void GLScene::release() NOTHROWS
{
    std::vector<std::shared_ptr<GLSceneNode>> nodeRenderers;
    ScenePtr scene(nullptr, nullptr);
    {
        Lock lock(core_->mutex_);
        // signal no longer interested in laoding
        core_->loading_ = false;
        if (!core_->node_renderers_.empty()) {
            nodeRenderers.reserve(core_->node_renderers_.size());
            for (auto entry : core_->node_renderers_)
                nodeRenderers.push_back(entry.second);
        }
        core_->node_renderers_.clear();
        // clear nodes
        core_->display_nodes_.clear();

        scene = std::move(core_->scene_);

    }

    // clear renderers and stop all loading
    for (auto it = nodeRenderers.begin(); it != nodeRenderers.end(); it++) {
        shared_context_->nodeLoader->cancel(*(*it));
        (*it)->release();
    }

    // clear scene
    scene.reset();

    shared_context_.reset();
}

TAKErr GLScene::hitTest(TAK::Engine::Core::GeoPoint2 *value, const TAK::Engine::Core::MapSceneModel2 &scene, const float x, const float y) NOTHROWS
{
#if PROFILE_HIT_TESTS
    auto profile_start = std::chrono::high_resolution_clock::now();
#endif

    TAKErr code(TE_Done);

    if (!value)
        return TE_InvalidArg;

#if 1 // Flip this to compare CPU hit tests
    GeoPoint2 hitGeo;
    if (!ctx_.isRenderThread()) {
        TAKErr awaitCode = Task_begin(GLWorkers_glThread(), depthTestTask, this, scene, x, y).await(hitGeo, code);
        // XXX - temporary hack to prevent deadlock; update to have task queued by context
        ctx_.requestRefresh();
        if (awaitCode != TE_Ok) return awaitCode;
    } else {
        const bool current = ctx_.isAttached();
        if (!current) 
            ctx_.attach();
        code = depthTestTask(hitGeo, this, scene, x, y);
        if (!current)
            ctx_.detach();
    }

    if (code == TE_Ok)
        *value = hitGeo;
#else
    code = TE_InvalidArg;
#endif

    // if depth method unsupported, fall back on pure CPU method (perhaps some really janky GPU)
    if (code == TE_InvalidArg) {
        std::vector<std::shared_ptr<GLSceneNode>> hitTestNodes;
        {
            Lock lock(core_->mutex_);
            TAKErr lockCode = lock.status;
            TE_CHECKRETURN_CODE(lockCode);

            //XXX-- compatibleSrid check

            auto it = core_->node_renderers_.begin();
            auto end = core_->node_renderers_.end();

            hitTestNodes.reserve(core_->node_renderers_.size());
            while (it != end) {
                hitTestNodes.push_back(it->second);
                ++it;
            }
        }

        auto it = hitTestNodes.begin();
        auto end = hitTestNodes.end();

        bool candidate = false;
        double candDist2 = NAN;
        while (it != end) {
            // XXX - AABB pre-screen

            // test intersect on the mesh
            GeoPoint2 isect;
            code = (*it)->hitTest(&isect, scene, x, y);
            ++it;
            if (code == TE_Done)
                continue;

            // we had an intersect, compare it with the best candidate
            TAK::Engine::Math::Point2<double> hit;
            if (TE_Ok == scene.forward(&hit, isect)) {
                // XXX - we should check to see if 'z' is outside of near/far clip planes

                if (!candidate || hit.z < candDist2) {
                    candDist2 = hit.z;

                    // candidate identified
                    candidate = true;

                    // record the intersection
                    *value = isect;
                }
            }
        }

        // set code for return
        code = candidate ? TE_Ok : TE_Done;
    }

#if PROFILE_HIT_TESTS
    auto profile_end = std::chrono::high_resolution_clock::now();
    auto profile_span = profile_end - profile_start;
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(profile_span).count();
    TAK::Engine::Util::Logger_log(TAK::Engine::Util::LogLevel::TELL_Debug, "GLScene: hitTest: millis=%lld", millis);
#endif

    return code;
}


TAKErr GLScene::depthTestTask(TAK::Engine::Core::GeoPoint2& value, GLScene* scene, const TAK::Engine::Core::MapSceneModel2& sceneModel, float x, float y) NOTHROWS {

    TAKErr code = TE_Done;

    // Used only by the glThread and therefore statically cached for reuse, but as depth sampling grows in scope
    // in the renderer, should be moved to a shared place.
    static GLDepthSamplerPtr depth_sampler_(nullptr, nullptr);

    if (!depth_sampler_) {
        // For now, use (ENCODED_DEPTH_ENCODED_ID) method, since seems to get a 16-bit only depth buffer
        // the other way
        code = GLDepthSampler_create(depth_sampler_, scene->ctx_, GLDepthSampler::ENCODED_DEPTH_ENCODED_ID);
        if (code != TE_Ok)
            return code;
    }

    const bool isOrtho = (sceneModel.camera.mode == MapCamera2::Scale);
    float screenY = isOrtho ? y : sceneModel.height-y;
    double pointZ = 0.0;
    Matrix2 projection;

    code = depth_sampler_->performDepthSample(&pointZ, &projection, nullptr, *scene, sceneModel, x, screenY);
    if (code != TE_Ok)
        return code;

    TAK::Engine::Math::Point2<double> point;
    if (isOrtho) {
        projection.transform(&point, TAK::Engine::Math::Point2<double>(x, screenY, 0));
    point.z = pointZ;

    Matrix2 mat;
    if (projection.createInverse(&mat) != TE_Ok)
        return TE_Done;

    mat.transform(&point, point);

    // ortho -> projection
    sceneModel.inverseTransform.transform(&point, point);
    } else {
        // transform screen location at depth to NDC
        point.x = (x / (float)(sceneModel.width)) * 2.0f - 1.0f;
        point.y = (((float)sceneModel.height - y) / (float)(sceneModel.height)) * 2.0f - 1.0f;
        //point.z = pointZ * 2.0f - 1.0f;
        point.z = pointZ; // already NDC

        // compute inverse transform
        Matrix2 mat;
        mat.set(sceneModel.camera.projection);
        mat.concatenate(sceneModel.camera.modelView);

        mat.createInverse(&mat);

        // NDC -> projection
        mat.transform(&point, point);
    }

    // projection -> LLA
    code = sceneModel.projection->inverse(&value, point);

    return code;
}

TAKErr GLScene::gatherDepthSamplerDrawables(std::vector<GLDepthSamplerDrawable*>& result, int levelDepth, const TAK::Engine::Core::MapSceneModel2& sceneModel, float x, float y) NOTHROWS {

    TAKErr code(TE_Ok);

    auto it = core_->node_renderers_.begin();
    auto end = core_->node_renderers_.end();

    if (levelDepth == 0) {
        while (it != end) {
            // XXX - AABB pre-screen

            result.push_back(it->second.get());
            ++it;
        }
    } else {
        while (it != end) {
            // XXX - AABB pre-screen

            code = it->second->gatherDepthSamplerDrawables(result, levelDepth - 1, sceneModel, x, y);
            if (code != TE_Ok)
                break;
            ++it;
        }
    }

    return code;
}

void GLScene::depthSamplerDraw(TAK::Engine::Renderer::GLDepthSampler& sampler, const TAK::Engine::Core::MapSceneModel2& sceneModel) NOTHROWS {
    auto it = core_->node_renderers_.begin();
    auto end = core_->node_renderers_.end();

    while (it != end) {
        // XXX - AABB pre-screen

        it->second->depthSamplerDraw(sampler, sceneModel);
        ++it;
    }
}

TAKErr GLScene::getControl(void **ctrl, const char *type) NOTHROWS
{
    if (!type)
        return TE_InvalidArg;
    auto entry = controls_.find(type);
    if (entry == controls_.end())
        return TE_InvalidArg;
    *ctrl = entry->second;
    return TE_Ok;
}

TAKErr processCB(void *opaque, int current, int max) NOTHROWS
{
    static_cast<GLContentIndicator *>(opaque)->showProgress((int)((double)current / (double)max*100.0));
    return TE_Ok;
}

void *GLScene::initializeThread(void *opaque)
{
    std::unique_ptr<std::weak_ptr<SharedContext>> handle(static_cast<std::weak_ptr<SharedContext> *>(opaque));
    do {
        auto sharedContext = handle->lock();
        if (!sharedContext)
            break;

        std::weak_ptr<GLScene::SceneCore> coreref;
        {
            Monitor::Lock lock(sharedContext->sceneInitializer.monitor);
            // queue is empty, wait
            if (sharedContext->sceneInitializer.queue.empty()) {
                lock.wait();
                continue;
            }

            coreref = sharedContext->sceneInitializer.queue.front();
            sharedContext->sceneInitializer.queue.pop_front();
        }

        TAKErr code(TE_Ok);
        ScenePtr scene(nullptr, nullptr);
        SceneInfo info;

        // load scene
        do {
            auto core = coreref.lock();
            if (!core || !core->loading_) {
                code = TE_Canceled;
                break;
            }
            info = core->info_;

            // look for optimized
            TAK::Engine::Port::String optimizedPath;
            if (core->opts_.cacheDir) {
                std::ostringstream strm;
                strm << core->opts_.cacheDir << TAK::Engine::Port::Platform_pathSep() << "optimized.tbsg";
                optimizedPath = strm.str().c_str();
            }
            bool optimizedExists;
            if (IO_exists(&optimizedExists, optimizedPath) == TE_Ok && optimizedExists) {
                code = SceneFactory_decode(scene, optimizedPath, true);
                if (code == TE_Ok)
                    break;
            }

            // no optimized, create
            code = SceneFactory_create(scene, core->info_.uri, nullptr, nullptr, core->info_.resourceAliases.get());
            TE_CHECKBREAK_CODE(code);

            // if not direct, store optimized version
            if (!(scene->getProperties()&Scene::DirectSceneGraph) && optimizedPath) {
                TAK::Engine::Port::String resourceDir;
                if (IO_getParentFile(resourceDir, optimizedPath) != TE_Ok)
                    break;
                IO_mkdirs(resourceDir);
                SceneFactory_encode(optimizedPath, *scene); 
            }
        } while (false);
        if (code != TE_Ok)
            continue;

        // build out nodes
        std::list<std::shared_ptr<SceneNode>> meshNodes;
        SceneNodePtr root(&scene->getRootNode(), Memory_leaker_const<SceneNode>);
        buildNodeList(meshNodes, scene->getRootNode());
        if(root->hasMesh())
            meshNodes.push_back(std::shared_ptr<SceneNode>(std::move(root)));

        // create renderers
        std::map<SceneNode *, std::shared_ptr<GLSceneNode>> renderers;
        std::list<std::shared_ptr<SceneNode>>::iterator it;
        for (it = meshNodes.begin(); it != meshNodes.end(); it++) {
            auto renderer = std::shared_ptr<GLSceneNode>(new GLSceneNode(*sharedContext->ctx, *it, info, sharedContext->materials));
            renderers[(*it).get()] = renderer;
        }
        MeshTransformOptions aabb_src;
        aabb_src.srid = info.srid;
        aabb_src.localFrame = Matrix2Ptr(new Matrix2(*info.localFrame), Memory_deleter_const<Matrix2>);

        Envelope2 update_aabb_lcs = scene->getAABB();

        MeshTransformOptions aabb_dst;
        aabb_dst.srid = 4326;

        Envelope2 update_aabb_wgs84;
        TAK::Engine::Model::Mesh_transform(&update_aabb_wgs84, scene->getAABB(), aabb_src, aabb_dst);

        // set 'glscene' members to initialize outputs
        bool needSourceBounds;
        {
            auto core = coreref.lock();
            // check canceled
            if (!core || !core->loading_)
                continue;
            // transfer the initialized objects
            do {
                Lock lock(core->mutex_);
                code = lock.status;

                core->scene_ = std::move(scene);
                core->display_nodes_ = meshNodes;
                core->node_renderers_ = renderers;

                needSourceBounds = !core->info_.aabb.get();
                if (needSourceBounds) {
                    core->info_.aabb = Envelope2Ptr(new Envelope2(update_aabb_wgs84), Memory_deleter_const<Envelope2>);
                }

                // XXX - 
                // initializer thread is done, detach and reset the pointer
                //glscene->initializer->detach();
                //glscene->initializer.reset();

                if (core->clampRequested)
                    core->sceneCtrl->clampToGround();
            } while (false);

            // update the bounds on the source, if not previously populated
            if(needSourceBounds)
                core->sceneCtrl->dispatchBoundsChanged(update_aabb_lcs, info.minDisplayResolution, info.maxDisplayResolution);
        }
    } while (true);

    return nullptr;
}

std::shared_ptr<GLScene::SharedContext> GLScene::getSharedContext(const RenderContext &ctx) NOTHROWS
{
    static Mutex mutex;
    Lock lock(mutex);
    static std::map<const RenderContext*, std::weak_ptr<GLScene::SharedContext>> sharedContexts;
    do {
        auto entry = sharedContexts.find(&ctx);
        if (entry == sharedContexts.end())
            break;
        auto shared = entry->second.lock();
        if (shared)
            return shared;
    } while (false);
    std::shared_ptr<SharedContext> retval(std::make_shared<GLScene::SharedContext>());
    retval->ctx = const_cast<RenderContext *>(&ctx);
    retval->materials.reset(new MaterialManager(const_cast<RenderContext&>(ctx)));
    constexpr std::size_t sceneInitializerPoolSize = 6u;
    retval->nodeLoader.reset(new GLSceneNodeLoader(sceneInitializerPoolSize));
    void* sceneInitializerData[sceneInitializerPoolSize];
    for (std::size_t i = 0u; i < sceneInitializerPoolSize; i++)
        sceneInitializerData[i] = new std::weak_ptr<SharedContext>(retval);
    ThreadPoolPtr sceneInitializerPool(nullptr, nullptr);
    TAK::Engine::Thread::ThreadPool_create(sceneInitializerPool, sceneInitializerPoolSize, GLScene::initializeThread, sceneInitializerData);
    retval->sceneInitializer.pool = std::shared_ptr<ThreadPool>(std::move(sceneInitializerPool));
    sharedContexts[&ctx] = retval;
    return retval;
}

GLScene::SceneControlImpl::SceneControlImpl(GLScene &owner) NOTHROWS :
    owner_(owner)
{}
TAKErr GLScene::SceneControlImpl::setLocation(const GeoPoint2 &location, const Matrix2 *localFrame, const int srid, const AltitudeMode altitudeMode) NOTHROWS
{
    TAKErr code(TE_Ok);
    {
        Lock lock(owner_.core_->mutex_);
        code = lock.status;
        TE_CHECKRETURN_CODE(code);

        if (srid == owner_.core_->info_.srid &&
            owner_.core_->info_.location->latitude == location.latitude &&
            owner_.core_->info_.location->longitude == location.longitude &&
            owner_.core_->info_.location->altitude == location.altitude &&
            owner_.core_->info_.location->altitudeRef == location.altitudeRef &&
            owner_.core_->info_.altitudeMode == altitudeMode &&
            ((localFrame && owner_.core_->info_.localFrame.get() &&
                *localFrame == *owner_.core_->info_.localFrame) ||
                (!localFrame && !owner_.core_->info_.localFrame.get()))) {

            return TE_Ok;
        }
        owner_.core_->info_.srid = srid;
        owner_.core_->info_.location = GeoPoint2Ptr(new GeoPoint2(location), Memory_deleter_const<GeoPoint2>);
        owner_.core_->info_.altitudeMode = altitudeMode;

        if (owner_.core_->info_.altitudeMode == TEAM_ClampToGround)
            return clampToGround();

        if (localFrame)
            owner_.core_->info_.localFrame = Matrix2Ptr(new Matrix2(*localFrame), Memory_deleter_const<Matrix2>);
        else
            owner_.core_->info_.localFrame.reset();

        // if the renderers are already initalized, need to update them
        owner_.location_dirty_ = true;
    }

    return code;
}
TAKErr GLScene::SceneControlImpl::getInfo(SceneInfo *info) NOTHROWS
{
    if(!info)
        return TE_InvalidArg;
    info = &owner_.core_->info_;
    return TE_Ok;
}
TAKErr GLScene::SceneControlImpl::addUpdateListener(UpdateListener *l) NOTHROWS
{
    TAKErr code(TE_Ok);
    Lock lock(mutex_);
    code = lock.status;
    TE_CHECKRETURN_CODE(code);
    listeners_.insert(l);
    return code;
}
TAKErr GLScene::SceneControlImpl::removeUpdateListener(const UpdateListener &l) NOTHROWS
{
    TAKErr code(TE_Ok);
    Lock lock(mutex_);
    code = lock.status;
    TE_CHECKRETURN_CODE(code);
    listeners_.erase(&const_cast<UpdateListener &>(l));
    return code;
}
TAKErr GLScene::SceneControlImpl::clampToGround() NOTHROWS
{
    TAKErr code(TE_Ok);
    // acquire lock
    Lock lock(owner_.core_->mutex_);
    code = lock.status;
    TE_CHECKRETURN_CODE(code);
    
    // if initialization is not completed,  flag clamp request
    if (!owner_.core_->scene_) {
        owner_.core_->clampRequested = true;
        return code;
    }

    // iterate nodes and find anchor point on lowest LOD meshes
    TAK::Engine::Math::Point2<double> sceneMinLCS(NAN, NAN, NAN);
    for (auto entry = owner_.core_->node_renderers_.begin(); entry != owner_.core_->node_renderers_.end(); entry++) {
        SceneNode &node = *entry->second->subject;
        const std::size_t numLods = node.getNumLODs();
        for (std::size_t i = 0; i < numLods; i++) {
            std::shared_ptr<const Mesh> mesh;
            if (node.loadMesh(mesh, i) != TE_Ok)
                continue;

            const std::size_t numVerts = mesh->getNumVertices();
            if (!numVerts)
                continue;

            const Envelope2 &aabb = mesh->getAABB();
            TAK::Engine::Math::Point2<double> meshMin((aabb.minX+aabb.maxX)/2.0, (aabb.minY+aabb.maxY)/2.0, aabb.minZ);
            
            // apply mesh transform to mesh min to convert to scene LCS
            if (node.getLocalFrame() && node.getLocalFrame()->transform(&meshMin, meshMin) != TE_Ok)
                continue;

            // compare with current LCS reference
            if (TE_ISNAN(sceneMinLCS.z) || meshMin.z < sceneMinLCS.z)
                sceneMinLCS = meshMin;
        }
    }

    if (TE_ISNAN(sceneMinLCS.z))
        return TE_Ok;

    TAK::Engine::Math::Point2<double> sceneOriginWCS(0.0, 0.0, 0.0);
    if (owner_.core_->info_.localFrame.get()) {
        code = owner_.core_->info_.localFrame->transform(&sceneOriginWCS, sceneOriginWCS);
        TE_CHECKRETURN_CODE(code);
    }

    // XXX - this is a little crude, but we are assuming that the floor of the
    //       AABB is on the surface

    // first, subtract off origin WCS to reset WCS origin to 0AGL, then subtract off the scene LCS AABB floor to reset WCS floor to 0AGL
    owner_.core_->sceneCtrl->dispatchClampToGroundOffsetComputed(-sceneOriginWCS.z-sceneMinLCS.z);
    return code;
}
TAKErr GLScene::SceneControlImpl::setXrayColor(const unsigned int color) NOTHROWS {
    owner_.core_->info_.xrayColor = color;
    return TAKErr::TE_Ok;
}
TAKErr GLScene::SceneControlImpl::getXrayColor(unsigned int *color) NOTHROWS {
    if (!color)
        return TE_InvalidArg;
    *color = owner_.core_->info_.xrayColor;
    return TAKErr::TE_Ok;
}

void GLScene::SceneControlImpl::dispatchBoundsChanged(const Envelope2 &aabb, const double minGsd, const double maxGsd) NOTHROWS
{
    Lock lock(mutex_);
    if (lock.status != TE_Ok)
        return;

    auto it = listeners_.begin();
    while (it != listeners_.end()) {
        if ((*it)->onBoundsChanged(aabb, minGsd, maxGsd) == TE_Done)
            it = listeners_.erase(it);
        else
            it++;
    }
}
void GLScene::SceneControlImpl::dispatchClampToGroundOffsetComputed(const double offset) NOTHROWS
{
    Lock lock(mutex_);
    if (lock.status != TE_Ok)
        return;

    auto it = listeners_.begin();
    while (it != listeners_.end()) {
        if ((*it)->onClampToGroundOffsetComputed(offset) == TE_Done)
            it = listeners_.erase(it);
        else
            it++;
    }
}

bool GLScene::isXRayCapable() NOTHROWS
{
    return static_cast<bool>(core_->info_.capabilities & SceneInfo::CapabilitiesType::XRay);
}

