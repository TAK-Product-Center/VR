#include "renderer/feature/GLBatchGeometryRenderer4.h"

#include <cassert>
#include <map>
#include <math.h>
#include <string>

#include "core/MapSceneModel2.h"
#include "feature/GeometryTransformer.h"
#include "feature/Style.h"
#include "math/AABB.h"
#include "math/Mesh.h"
#include "model/MeshTransformer.h"
#include "raster/osm/OSMUtils.h"
#include "renderer/GL.h"
#include "renderer/GLES20FixedPipeline.h"
#include "renderer/GLSLUtil.h"
#include "renderer/core/GLMapRenderGlobals.h"
#include "renderer/elevation/GLTerrainTile.h"
#include "renderer/feature/GLBatchGeometryRenderer4.h"
#include "renderer/GLMatrix.h"
#include "renderer/RenderState.h"
#include "thread/Lock.h"
#include "thread/Mutex.h"
#include "util/ConfigOptions.h"
#include "util/Logging.h"
#include "util/MathUtils.h"

#ifndef GL_PROGRAM_POINT_SIZE
#define GL_PROGRAM_POINT_SIZE             0x8642
#endif

#ifndef GL_POINT_SPRITE
#define GL_POINT_SPRITE                   0x8861
#endif

using namespace TAK::Engine::Renderer::Feature;

using namespace TAK::Engine::Core;
using namespace TAK::Engine::Math;
using namespace TAK::Engine::Model;
using namespace TAK::Engine::Port;
using namespace TAK::Engine::Renderer;
using namespace TAK::Engine::Renderer::Core;
using namespace TAK::Engine::Renderer::Elevation;
using namespace TAK::Engine::Thread;
using namespace TAK::Engine::Util;


namespace {
    constexpr uint16_t antialiasLineInstanceGeom[12u] =
    {
        // triangle 1
        0xFFFFu, 0xFFFFu,
        0xFFFFu, 0x0000u,
        0x0000u, 0xFFFFu,
        // triangle 2
        0xFFFFu, 0xFFFFu,
        0xFFFFu, 0x0000u,
        0x0000u, 0x0000u,
    };

    constexpr std::size_t arrowInstanceGeomCount = 4u;
    constexpr float arrowInstanceGeom[arrowInstanceGeomCount*2u] =
    {
        // triangle strip
        -0.5f, -1.f,
        0.f, 0.f,
        0.f, -0.67f,
        0.5f, -1.f,
    };

    struct {
        Mutex mutex;
        std::map<const RenderContext*, std::weak_ptr<GLOffscreenFramebuffer>> pixel;
        std::map<const RenderContext*, std::weak_ptr<GLOffscreenFramebuffer>> tile;
    } sharedFbos;

    TAKErr getSharedFbo(std::shared_ptr<GLOffscreenFramebuffer> &fbo, std::map<const RenderContext*, std::weak_ptr<GLOffscreenFramebuffer>> &cache, const RenderContext &ctx, const std::size_t width, const std::size_t height, const GLOffscreenFramebuffer::Options &opts) NOTHROWS
    {
        Lock lock(sharedFbos.mutex);
        do {
            const auto& entry = cache.find(&ctx);
            if (entry != cache.end()) {
                fbo = entry->second.lock();
                if (fbo)
                    break;
                // reference is cleared, evict entry
                cache.erase(entry);
            }

            // create offscreen FBO
            GLOffscreenFramebufferPtr tile(nullptr, nullptr);
            const TAKErr code = GLOffscreenFramebuffer_create(
                tile,
                (int)width, (int)height,
                opts);
            TE_CHECKRETURN_CODE(code);

            fbo = std::move(tile);
            cache[&ctx] = fbo;
        } while (false);

        return TE_Ok;
    }

    struct GLResourceBundle {
        std::vector<GLuint> buffers;
        std::vector<std::shared_ptr<GLOffscreenFramebuffer>> fbos;
    };

    void glResourcesDestruct(void *opaque) NOTHROWS
    {
        auto resources = static_cast<GLResourceBundle *>(opaque);
        if(!resources->buffers.empty())
            glDeleteBuffers((GLsizei)resources->buffers.size(), resources->buffers.data());
        resources->fbos.clear();
    }
    TAKErr intersectWithTerrainTileImpl(GeoPoint2 *value, const TerrainTile &tile, const MapSceneModel2 &scene, const float x, const float y) NOTHROWS;
}

GLBatchGeometryRenderer4::GLBatchGeometryRenderer4(const RenderContext &ctx) NOTHROWS :
    GLBatchGeometryRenderer4(ctx, 0u)
{}
GLBatchGeometryRenderer4::GLBatchGeometryRenderer4(const RenderContext &ctx, const unsigned int featuresPresort_) NOTHROWS :
    context(ctx),
    featuresPresort(featuresPresort_)
{
    pointShader.handle = 0u;
    lineShader.base.handle = 0u;
    polygonsShader.handle = 0u;
    meshesShader.handle = 0u;

    isMpu = ConfigOptions_getIntOptionOrDefault("mpu", 0);
}
GLBatchGeometryRenderer4::~GLBatchGeometryRenderer4() NOTHROWS
{
    markForRelease();
    if(markedForRelease.empty() && !fbo.tile && !fbo.pixel)
        return;
    std::unique_ptr<GLResourceBundle> resources(new GLResourceBundle());
    resources->buffers = markedForRelease;
    markedForRelease.clear();
    if(fbo.tile) {
        resources->fbos.push_back(fbo.tile);
        fbo.tile.reset();
    }
    if(fbo.pixel) {
        resources->fbos.push_back(fbo.pixel);
        fbo.pixel.reset();
    }

    const_cast<RenderContext &>(context).queueEvent(glResourcesDestruct, std::unique_ptr<void, void(*)(const void *)>(resources.release(), Memory_void_deleter_const<GLResourceBundle>));
}

TAKErr GLBatchGeometryRenderer4::setBatchState(const BatchState &surface, const BatchState& sprites) NOTHROWS
{
    batchState.sprites = sprites;
    batchState.surface = surface;
    return TE_Ok;
}
TAKErr GLBatchGeometryRenderer4::addBatchBuffer(const Program program, const PrimitiveBuffer &buffer, const BatchGeometryBufferLayout &layout, const int renderPass, const std::shared_ptr<const TAK::Engine::Model::Mesh> mesh) NOTHROWS
{
    const bool surface = !!(renderPass & GLGlobeBase::Surface);
    const bool sprites = !!(renderPass & GLGlobeBase::Sprites);

    VertexBuffer buf;
    buf.primitive = buffer;
    buf.layout = layout;
    switch (program) {
    case Program::Points:
        pointsBuffers.push_back(buf);
        break;
    case Program::Arrows:
        if (surface)
            surfaceArrowBuffers.push_back(buf);
        if (sprites)
            spriteArrowBuffers.push_back(buf);
        break;
    case Program::AntiAliasedLines:
        if (surface)
            surfaceLineBuffers.push_back(buf);
        if (sprites)
            spriteLineBuffers.push_back(buf);
        break;
    case Program::Polygons:
        if (surface)
            surfacePolygonBuffers.push_back(buf);
        if (sprites)
            spritePolygonBuffers.push_back(buf);
        break;
    case Program::Meshes:
        if (!mesh) return TE_InvalidArg;
        spriteMeshBuffers[mesh].push_back(buf);
        break;
    default:
        // XXX - other
        return TE_InvalidArg;
    }
    return TE_Ok;
}
std::size_t GLBatchGeometryRenderer4::markForRelease(const std::function<void(const PrimitiveBuffer &)> &recycler) NOTHROWS
{
    auto markForRelease = [&](auto &buffers)
    {
        for (const auto& buf : buffers) {
            if(recycler) {
                recycler(buf.primitive);
            } else {
                if (buf.primitive.vbo)
                    markedForRelease.push_back(buf.primitive.vbo);
                if (buf.primitive.ibo)
                    markedForRelease.push_back(buf.primitive.ibo);
            }
        }
        buffers.clear();
    };
    markForRelease(surfaceLineBuffers);
    markForRelease(spriteLineBuffers);
    markForRelease(surfaceArrowBuffers);
    markForRelease(spriteArrowBuffers);
    markForRelease(surfacePolygonBuffers);
    markForRelease(spritePolygonBuffers);
    markForRelease(pointsBuffers);
    for (auto &entry : spriteMeshBuffers)
        markForRelease(entry.second);
    spriteMeshBuffers.clear();

    return markedForRelease.size();
}
void GLBatchGeometryRenderer4::setIgnoreFeatures(const uint32_t *hitids, const std::size_t count) NOTHROWS
{
    ignoreFeatures.clear();
    ignoreFeatures.reserve(count);
    for(std::size_t i = 0u; i < count; i++)
        ignoreFeatures.push_back(hitids[i]);
}
void GLBatchGeometryRenderer4::hitTest(Port::Collection<uint32_t>& featureIds, const Renderer::Core::GLGlobeBase& view, const float screenX, const float screenY, const std::size_t limit) NOTHROWS
{
    hitTest(featureIds, view, screenX, screenY, 0.f, limit);
}
void GLBatchGeometryRenderer4::hitTest(Port::Collection<uint32_t>& featureIds, const Renderer::Core::GLGlobeBase& view, const float screenX, const float screenY, const float hitTestRadius, const std::size_t limit) NOTHROWS
{
    if (!fbo.pixel) {
        GLOffscreenFramebuffer::Options opts;
        opts.bufferMask = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT;
        opts.colorFormat = GL_RGBA;
        opts.colorType = GL_UNSIGNED_BYTE;
        // XXX - MPU requires oversized readback FBO
        const unsigned fboPixelTexSize = isMpu ? 512u : 1u;
        if (getSharedFbo(fbo.pixel, sharedFbos.pixel, context, fboPixelTexSize, fboPixelTexSize, opts) != TE_Ok)
            return;
        fbo.pixel->width = 1;
        fbo.pixel->height = 1;
    }

    const std::size_t levelOfDetail = (std::size_t)MathUtils_clamp(atakmap::raster::osm::OSMUtils::mapnikTileLevel(view.renderPasses[0].drawMapResolution), (int)atakmap::feature::LevelOfDetailStyle::MIN_LOD, (int)atakmap::feature::LevelOfDetailStyle::MAX_LOD);


    struct RestoreState {
        RestoreState() NOTHROWS
        {
            glGetIntegerv(GL_FRAMEBUFFER_BINDING, &framebuffer);
            glGetFloatv(GL_COLOR_CLEAR_VALUE, clearColor);
            glGetFloatv(GL_DEPTH_CLEAR_VALUE, &clearDepth);
            glGetIntegerv(GL_VIEWPORT, viewport);

            glGetIntegerv(GL_DEPTH_FUNC, &depthFunc);
            glGetBooleanv(GL_DEPTH_WRITEMASK, &depthMask);
            depthEnabled = glIsEnabled(GL_DEPTH_TEST);
        }
        ~RestoreState() NOTHROWS
        {
            glBindFramebuffer(GL_FRAMEBUFFER, framebuffer);
            glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);
            glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
            glClearDepthf(clearDepth);

            glDepthFunc(depthFunc);
            glDepthMask(depthMask);
            if (depthEnabled)
                glEnable(GL_DEPTH_TEST);
            else
                glDisable(GL_DEPTH_TEST);
        }

        GLint depthFunc;
        GLboolean depthMask;
        GLboolean depthEnabled;
        GLfloat clearColor[4u];
        GLint viewport[4u];
        GLfloat clearDepth{ 0.f };
        GLint framebuffer{ GL_NONE };
    } restoreState;

    fbo.pixel->bind();

    struct SurfaceTile {
        GLTerrainTile value;
        struct {
            GeoPoint2 lla;
            double dcam2 {NAN}; // distance to camera, squared
            TAKErr code { TE_IllegalState };
        } meshIsect;
    };
    struct {
        std::vector<GLTerrainTile> gl;
        std::vector<std::tuple<GeoPoint2, double, TAKErr>> meshIsect;
        bool needGpuIsect {false};
    } surfaceTiles;

    // translate viewport to pixel
    glViewport((GLint)-screenX, (GLint)-screenY, restoreState.viewport[2u], restoreState.viewport[3u]);

    // XXX - MPU does not appear to support negative viewport origin. reset the viewport to the
    //       extent of the FBO texture and adjust the readback x,y
    Point2<GLint> spriteReadbackXY(0, 0);
    if(isMpu) {
        glViewport(restoreState.viewport[0u], restoreState.viewport[1u], (GLint)fbo.pixel->textureWidth, (GLint)fbo.pixel->textureHeight);
        spriteReadbackXY.x = (GLint)(screenX / (float)restoreState.viewport[2u] * (float)fbo.pixel->textureWidth);
        spriteReadbackXY.y = (GLint)(screenY / (float)restoreState.viewport[3u] * (float)fbo.pixel->textureHeight);
    }

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glDepthFunc(GL_LEQUAL);
    glDepthMask(GL_TRUE);
    glEnable(GL_DEPTH_TEST);

    // for each terrain tile that intersects the ray capture into the tile render list
    const auto hasSurfaceFeatures = (!surfaceLineBuffers.empty() || !surfacePolygonBuffers.empty() || !surfaceArrowBuffers.empty());
    if (hasSurfaceFeatures) {
        for (std::size_t i = 0u; i < view.renderPasses[0u].renderTiles.count; i++) {
            const auto& gltile = view.renderPasses[0u].renderTiles.value[i];
            const auto& tile = *gltile.tile;
            SurfaceTile surfaceTile;
            surfaceTile.value = gltile;

            // check for ray intersection

            // AABB filter
            TAK::Engine::Feature::Envelope2 aabb(tile.aabb_wgs84);
            if (view.renderPasses[0u].drawSrid == 4978) {
                const auto localaabb = tile.data_proj.value->getAABB();
                Point2<double> min(localaabb.minX, localaabb.minY, localaabb.minZ);
                Point2<double> max(localaabb.maxX, localaabb.maxY, localaabb.maxZ);
                tile.data_proj.localFrame.transform(&min, min);
                tile.data_proj.localFrame.transform(&max, max);
                aabb.minX = min.x;
                aabb.minY = min.y;
                aabb.minZ = min.z;
                aabb.maxX = max.x;
                aabb.maxY = max.y;
                aabb.maxZ = max.z;
            } else if (view.renderPasses[0].drawSrid != 4326) {
                TAK::Engine::Feature::GeometryTransformer_transform(&aabb, aabb, 4326, view.renderPasses[0u].drawSrid);
            }

            if (view.renderPasses[0u].scene.inverse(
                &surfaceTile.meshIsect.lla,
                Point2<float>(screenX, screenY, 0.0),
                AABB(
                    Point2<double>(aabb.minX, aabb.minY, aabb.minZ),
                    Point2<double>(aabb.maxX, aabb.maxY, aabb.maxZ))) != TE_Ok) {

                continue;
            }

            // mesh specific intersection
            surfaceTile.meshIsect.code = intersectWithTerrainTileImpl(&surfaceTile.meshIsect.lla, tile, view.renderPasses[0u].scene, screenX, screenY);
            switch(surfaceTile.meshIsect.code) {
                case TE_Ok :
                    // have intersect
                    break;
                case TE_NotImplemented :
                    // intersect on the mesh is not supported, no scissor
                    break;
                default :
                    // assume no intersect with mesh, continue
                    continue;
            }

            Point2<double> isectxyz;
            view.renderPasses[0].scene.projection->forward(&isectxyz, surfaceTile.meshIsect.lla);
            const double dx = (isectxyz.x-view.renderPasses[0].scene.camera.location.x)*view.renderPasses[0].scene.displayModel->projectionXToNominalMeters;
            const double dy = (isectxyz.y-view.renderPasses[0].scene.camera.location.y)*view.renderPasses[0].scene.displayModel->projectionYToNominalMeters;
            const double dz = (isectxyz.z-view.renderPasses[0].scene.camera.location.z)*view.renderPasses[0].scene.displayModel->projectionZToNominalMeters;
            surfaceTile.meshIsect.dcam2 = dx*dx + dy*dy + dz*dz;

            surfaceTiles.gl.push_back(surfaceTile.value);
            surfaceTiles.meshIsect.push_back(std::tuple<GeoPoint2, double, TAKErr>(surfaceTile.meshIsect.lla, surfaceTile.meshIsect.dcam2, surfaceTile.meshIsect.code));
            surfaceTiles.needGpuIsect |= (surfaceTile.meshIsect.code == TE_NotImplemented);
        }
    }

    const auto hitTestStart = Platform_systime_millis();
    // use scissor to restrict render to single pixel
    glEnable(GL_SCISSOR_TEST);
    glScissor(spriteReadbackXY.x, spriteReadbackXY.y, fbo.pixel->width, fbo.pixel->height);

    std::vector<uint32_t> ignoreIds;
    ignoreIds.reserve(16u);
    // render the sprites
    do {
        if (!surfaceTiles.gl.empty()) {
            // render the terrain tile(s) at the hit location, but disable color buffer writes
            glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
            const auto surfaceShaders = GLTerrainTile_getColorShader(view.context, view.renderPasses[0].scene.projection->getSpatialReferenceID(), 0);
            auto surfacectx = GLTerrainTile_begin(view.renderPasses[0u].scene, surfaceShaders);

            GLTerrainTile_bindTexture(surfacectx, GL_NONE, 1u, 1u);
            GLTerrainTile_drawTerrainTiles(
                surfacectx,
                Matrix2(
                    0.0, 0.0, 0.0, 0.5,
                    0.0, 0.0, 0.0, 0.5,
                    0.0, 0.0, 0.0, 0.0,
                    0.0, 0.0, 0.0, 0.1),
                surfaceTiles.gl.data(), surfaceTiles.gl.size(),
                0.f, 0.f, 0.f, 0.f);

            GLTerrainTile_end(surfacectx);
            glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
        }
        draw(view.renderPasses[0u], levelOfDetail, GLGlobeBase::Sprites, true, hitTestRadius, ignoreIds);

        uint32_t id {0x0u};
        glReadPixels(
            spriteReadbackXY.x, spriteReadbackXY.y,
            1, 1,
            GL_RGBA, GL_UNSIGNED_BYTE,
            &id);
        if (id&0xFFFFFFu) {
            featureIds.add(static_cast<int64_t>(id));
            ignoreIds.push_back(id);
        } else {
            // nothing hit, done
            break;
        }
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        const unsigned elapsed = (unsigned)(Platform_systime_millis() - hitTestStart);
        // only allow 100ms worth of deconflict hit-testing
        if (elapsed > 100u && featureIds.size() > 2u)
            break;
    } while (featureIds.size() != limit);

    // perform surface hit-test
    if(!surfaceTiles.gl.empty() && featureIds.size() < limit && hasSurfaceFeatures) {
        do {
            if (!fbo.tile) {
                GLOffscreenFramebuffer::Options opts;
                opts.bufferMask = GL_COLOR_BUFFER_BIT;
                opts.colorFormat = GL_RGBA;
                opts.colorType = GL_UNSIGNED_BYTE;
                if (getSharedFbo(fbo.tile, sharedFbos.tile, context, 512u, 512u, opts) != TE_Ok)
                    break;
            }

            const std::size_t surfaceTileCount = surfaceTiles.needGpuIsect ? surfaceTiles.gl.size() : 1u;
            std::vector<unsigned> drawOrder;
            drawOrder.reserve(surfaceTileCount);
            for(std::size_t i = 0u; i < surfaceTiles.gl.size(); i++)
                drawOrder.push_back((unsigned)i);

            // if GPU isect is not required, sort by isect distance from camera
            if(!surfaceTiles.needGpuIsect) {
                std::sort(drawOrder.begin(), drawOrder.end(), [&surfaceTiles](const unsigned aidx, const unsigned bidx)
                {
                    return std::get<1>(surfaceTiles.meshIsect[aidx]) < std::get<1>(surfaceTiles.meshIsect[bidx]);
                });
            } // TODO : do render pass to detect closest tile and get mesh specific isect

            // only need first tile (closest to camera)
            const auto closestTileIdx = drawOrder[0];
            SurfaceTile surfaceTile;
            surfaceTile.value = surfaceTiles.gl[closestTileIdx];
            surfaceTile.meshIsect.lla = std::get<0>(surfaceTiles.meshIsect[closestTileIdx]);
            surfaceTile.meshIsect.dcam2 = std::get<1>(surfaceTiles.meshIsect[closestTileIdx]);
            surfaceTile.meshIsect.code = std::get<2>(surfaceTiles.meshIsect[closestTileIdx]);
            const auto &tile = *surfaceTile.value.tile;

            // create ortho scene
            MapSceneModel2 surfaceScene;
            MapSceneModel2_createOrtho(
                    &surfaceScene,
                    (unsigned) fbo.tile->width,
                    (unsigned) fbo.tile->height,
                    GeoPoint2(surfaceTile.value.tile->aabb_wgs84.maxY,
                              surfaceTile.value.tile->aabb_wgs84.minX),
                    GeoPoint2(surfaceTile.value.tile->aabb_wgs84.minY,
                              surfaceTile.value.tile->aabb_wgs84.maxX));

            // capture state for restore after generating surface tile
            RestoreState surfaceRestore;

            // bind the surface tile FBO
            fbo.tile->bind();

            // reset the viewport to the tile dimensions
            glViewport(0, 0, (GLsizei) fbo.tile->width, (GLsizei) fbo.tile->height);

            // XXX - render surface
            GLGlobeBase::State pumpState(view.renderPasses[0]);

            // set the state that will be passed to the renderable
            pumpState.scene = surfaceScene;
            pumpState.drawSrid = 4326;
            pumpState.left = 0;
            pumpState.right = fbo.tile->width;
            pumpState.bottom = 0;
            pumpState.top = fbo.tile->height;
            pumpState.focusx = surfaceScene.focusX;
            pumpState.focusy = surfaceScene.focusY;
            pumpState.northBound = tile.aabb_wgs84.maxY;
            pumpState.westBound = tile.aabb_wgs84.minX;
            pumpState.southBound = tile.aabb_wgs84.minY;
            pumpState.eastBound = tile.aabb_wgs84.maxX;
            pumpState.upperLeft = GeoPoint2(pumpState.northBound, pumpState.westBound);
            pumpState.upperRight = GeoPoint2(pumpState.northBound, pumpState.eastBound);
            pumpState.lowerRight = GeoPoint2(pumpState.southBound, pumpState.eastBound);
            pumpState.lowerLeft = GeoPoint2(pumpState.southBound, pumpState.westBound);
            pumpState.drawRotation = 0.0;
            pumpState.drawTilt = 0.0;
            pumpState.drawLat = (tile.aabb_wgs84.maxY + tile.aabb_wgs84.minY) / 2.0;
            pumpState.drawLng = (tile.aabb_wgs84.maxX + tile.aabb_wgs84.minX) / 2.0;
            pumpState.crossesIDL = false;
            pumpState.drawMapResolution = surfaceScene.gsd;
            pumpState.drawMapScale = atakmap::core::AtakMapView_getMapScale(
                    view.renderPasses[0u].scene.displayDpi,
                    pumpState.drawMapResolution);

            pumpState.viewport.x = 0;
            pumpState.viewport.y = 0;
            pumpState.viewport.width = (float) fbo.tile->width;
            pumpState.viewport.height = (float) fbo.tile->height;

            // XXX - should retrieve actual `GLTerrainTile` as mac requires VBO
            pumpState.renderTiles.value = &surfaceTile.value;
            pumpState.renderTiles.count = 1u;

            // reset the scene model to map to the tile
            {
                double mx[16u];
                pumpState.scene.forwardTransform.get(mx, Matrix2::COLUMN_MAJOR);
                for (int ix = 0; ix < 16; ix++)
                    pumpState.sceneModelForwardMatrix[ix] = (float) mx[ix];
            }

            // `isect` contains world location of intersect, apply tight scissor to reduce fill rate
            TAK::Engine::Math::Point2<float> surfacexy;
            surfaceScene.forward(&surfacexy, surfaceTile.meshIsect.lla);
            glScissor((GLint) surfacexy.x - 1, (GLint) surfacexy.y - 1, 3, 3);

            // render the surface features over the surface tile area
            while(featureIds.size() < limit) {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                draw(pumpState, levelOfDetail, GLGlobeBase::Surface, true, hitTestRadius,
                     ignoreIds);

                // read pixel at isect
                uint32_t id;
                glReadPixels(
                        (GLint)surfacexy.x, (GLint)surfacexy.y,
                        1, 1,
                        GL_RGBA, GL_UNSIGNED_BYTE,
                        &id);
                if (id&0xFFFFFFu) {
                    featureIds.add(static_cast<int64_t>(id));
                    ignoreIds.push_back(id);
                } else {
                    // nothing hit, done
                    break;
                }
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                const unsigned elapsed = (unsigned)(Platform_systime_millis() - hitTestStart);
                // only allow 100ms worth of deconflict hit-testing
                if (elapsed > 100u && featureIds.size() > 2u) {
                    break;
                }
            }
        } while(false);
    }

    glDisable(GL_SCISSOR_TEST);
    auto hte = Platform_systime_millis();

    //if(featureIds.size())
    //Logger_log(TELL_Info, "GLBatchGeometryRenderer4::hitTest in %ums", (unsigned)(hte - hitTestStart));
}

void GLBatchGeometryRenderer4::draw(const GLGlobeBase &view, const int renderPass) NOTHROWS
{
    if (!clampToGroundControl.initialized) {
        clampToGroundControl.initialized = true;
        void* ctrl{ nullptr };
        view.getControl(&ctrl, TAK::Engine::Renderer::Core::Controls::ClampToGroundControl_getType());
        if (ctrl)
            clampToGroundControl.value = static_cast<TAK::Engine::Renderer::Core::Controls::ClampToGroundControl*>(ctrl);
    }

    const std::size_t levelOfDetail = (std::size_t)MathUtils_clamp(atakmap::raster::osm::OSMUtils::mapnikTileLevel(view.renderPasses[0u].drawMapResolution), (int)atakmap::feature::LevelOfDetailStyle::MIN_LOD, (int)atakmap::feature::LevelOfDetailStyle::MAX_LOD);

    draw(*view.renderPass, levelOfDetail, renderPass, false, 0.f, ignoreFeatures);
}

void GLBatchGeometryRenderer4::draw(const Core::GLGlobeBase::State &view, const std::size_t levelOfDetail, const int renderPass, const bool drawForHitTest, const float hitTestRadius, const std::vector<uint32_t> &ignoreIds)
{
    // delete all buffers marked for release
    if (!markedForRelease.empty()) {
        glDeleteBuffers((GLsizei)markedForRelease.size(), markedForRelease.data());
        markedForRelease.clear();
    }

    const bool surface = !!(renderPass & GLGlobeBase::Surface);
    const bool sprites = !!(renderPass & GLGlobeBase::Sprites);

    if (drawForHitTest) {
        glDisable(GL_BLEND);
    } else {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    if (surface)
        drawSurface(view, levelOfDetail, drawForHitTest, hitTestRadius, ignoreIds);
    if (sprites)
        drawSprites(view, levelOfDetail, drawForHitTest, hitTestRadius, ignoreIds);

    glDisable(GL_BLEND);
}

void GLBatchGeometryRenderer4::drawSurface(const GLGlobeBase::State &view, const std::size_t levelOfDetail, const bool drawForHitTest, const float hitTestRadius, const std::vector<uint32_t> &ignoreIds) NOTHROWS
{
#if 0
    if (!surfaceCoverage.intersects(TAK::Engine::Feature::Envelope2(view.renderPass->westBound, view.renderPass->southBound, 0.0, view.renderPass->eastBound, view.renderPass->northBound, 0.0)))
        return;
#endif

    // polygons
    if (!this->surfacePolygonBuffers.empty()) {
        this->drawPolygonBuffers(view, levelOfDetail, batchState.surface, surfacePolygonBuffers, drawForHitTest, hitTestRadius, true, ignoreIds);
    }
    // lines
    if (!this->surfaceLineBuffers.empty()) {
        this->drawLineBuffers(view, levelOfDetail, batchState.surface, surfaceLineBuffers, drawForHitTest, hitTestRadius, true, ignoreIds);
    }
    // arrows
    if(!this->surfaceArrowBuffers.empty()) {
        this->drawLineBuffers(view, levelOfDetail, batchState.surface, surfaceArrowBuffers, drawForHitTest, hitTestRadius, true, ignoreIds);
        this->drawArrowBuffers(view, levelOfDetail, batchState.surface, surfaceArrowBuffers, drawForHitTest, hitTestRadius, true, ignoreIds);
    }
}
void GLBatchGeometryRenderer4::drawSprites(const GLGlobeBase::State &view, const std::size_t levelOfDetail, const bool drawForHitTest, const float hitTestRadius, const std::vector<uint32_t> &ignoreIds) NOTHROWS
{
    // XXX - depth does not appear to be enabled by default during sprites pass with nadir camera
    struct DepthRestore
    {
        DepthRestore() NOTHROWS
        {
            glGetIntegerv(GL_DEPTH_FUNC, &depthFunc);
            glGetBooleanv(GL_DEPTH_WRITEMASK, &depthMask);
            depthEnabled = glIsEnabled(GL_DEPTH_TEST);
        }
        ~DepthRestore() NOTHROWS
        {
            glDepthFunc(depthFunc);
            glDepthMask(depthMask);
            if (depthEnabled)
                glEnable(GL_DEPTH_TEST);
            else
                glDisable(GL_DEPTH_TEST);
        }
        GLint depthFunc;
        GLboolean depthMask;
        GLboolean depthEnabled;
    } depthRestore;

    glDepthFunc(GL_LEQUAL);
    glDepthMask(GL_TRUE);
    glEnable(GL_DEPTH_TEST);

    // NOTE: render order allows for visibility of points in transluncent polygons. line geometries
    // are reserved as last to facilitate polygon stroking for depth equal. long term, consideration
    // should be given to separating translucent and opaque primitives for better interleaving.

    // points
    if (!this->pointsBuffers.empty()) {
        const bool pointsPresorted =
            ((featuresPresort&0x1u) && view.scene.camera.elevation == -90.0) ||
            ((featuresPresort&0x2u) && view.scene.camera.elevation != -90.0);
        if(pointsPresorted) {
            // client has pre-sorted back-to-front

            // disable depth writes
            glDepthMask(GL_FALSE);
            this->batchDrawPoints(view, levelOfDetail, batchState.sprites, drawForHitTest, hitTestRadius, ignoreIds);
            glDepthMask(GL_TRUE);
            glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
            this->batchDrawPoints(view, levelOfDetail, batchState.sprites, drawForHitTest, hitTestRadius, ignoreIds);
            glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
        } else {
            // client has not sorted, rely on depth test exclusively
            this->batchDrawPoints(view, levelOfDetail, batchState.sprites, drawForHitTest, hitTestRadius, ignoreIds);
        }
    }
    // lines
    if(!spriteLineBuffers.empty()) {
        this->drawLineBuffers(view, levelOfDetail, batchState.sprites, spriteLineBuffers, drawForHitTest, hitTestRadius, false, ignoreIds);
    }
    // arrows
    if(!spriteArrowBuffers.empty()) {
        // NOTE: consideration may want to be given in the future towards how any x-ray section of
        // the line should be considered for hit-testing
        glDepthMask(GL_FALSE);
        glDepthFunc(GL_GREATER);
        this->drawLineBuffers(view, levelOfDetail, batchState.sprites, spriteArrowBuffers, drawForHitTest, hitTestRadius, false, ignoreIds, 1.f, 1.f, 1.f, 0.25f);
        this->drawArrowBuffers(view, levelOfDetail, batchState.sprites, spriteArrowBuffers, drawForHitTest, hitTestRadius, false, ignoreIds, 1.f, 1.f, 1.f, 0.25f);
        glDepthMask(GL_TRUE);
        glDepthFunc(GL_LEQUAL);

        this->drawLineBuffers(view, levelOfDetail, batchState.sprites, spriteArrowBuffers, drawForHitTest, hitTestRadius, false, ignoreIds);
        this->drawArrowBuffers(view, levelOfDetail, batchState.sprites, spriteArrowBuffers, drawForHitTest, hitTestRadius, false, ignoreIds);
    }
    // polygons
    if(!spritePolygonBuffers.empty()) {
        this->drawPolygonBuffers(view, levelOfDetail, batchState.sprites, spritePolygonBuffers, drawForHitTest, hitTestRadius, false, ignoreIds);
    }
    // meshes
    for (const auto &entry : spriteMeshBuffers) {
        if (!entry.second.empty()) {
            this->drawMeshBuffers(view, levelOfDetail, batchState.sprites, entry.second, drawForHitTest, hitTestRadius, ignoreIds, entry.first);
        }
    }
}
int GLBatchGeometryRenderer4::getRenderPass() NOTHROWS
{
    return GLGlobeBase::Surface | GLGlobeBase::Sprites;
}

TAKErr GLBatchGeometryRenderer4::drawLineBuffers(const GLGlobeBase::State &view, const std::size_t levelOfDetail, const BatchState &ctx, const std::vector<VertexBuffer> &buf, bool drawForHitTest, const float hitTestRadius, const bool surface, const std::vector<uint32_t> &ignoreIds, const float r, const float g, const float b, const float a) NOTHROWS {
    TAKErr code(TE_Ok);

    GLboolean depthWriteEnabled;
    glGetBooleanv(GL_DEPTH_WRITEMASK, &depthWriteEnabled);

    AntiAliasedLinesShader shader;
    GLBatchGeometryShaderOptions opts;
    opts.enableDisplayThresholds = true;
    opts.enableHitTestRadius = true;
    if (ignoreIds.empty()) {
        if (lineShader.base.handle == 0) {
            lineShader = GLBatchGeometryShaders_getAntiAliasedLinesShader(context, opts);
            assert(lineShader.base.handle);
        }
        shader = lineShader;
    } else {
        const std::size_t numIgnoreIds = ignoreIds.size();
        opts.ignoreIdsCount = std::min(GLBatchGeometryShader_maxIgnoreIds, (std::size_t)1u<<(std::size_t)std::ceil(std::log((double)numIgnoreIds)/std::log(2.0)));
        shader = GLBatchGeometryShaders_getAntiAliasedLinesShader(context, opts);
        assert(shader.base.handle);
    }
    glUseProgram(shader.base.handle);

    // MVP
    {
        Matrix2 mvp;
        // projection
        float matrixF[16u];
        atakmap::renderer::GLMatrix::orthoM(matrixF, (float)view.left, (float)view.right, (float)view.bottom, (float)view.top, (float)view.scene.camera.near, (float)view.scene.camera.far);
        for(std::size_t i = 0u; i < 16u; i++)
            mvp.set(i%4, i/4, matrixF[i]);
        // model-view
        mvp.concatenate(view.scene.forwardTransform);
        mvp.translate(ctx.centroidProj.x, ctx.centroidProj.y, ctx.centroidProj.z);
        for (std::size_t i = 0u; i < 16u; i++) {
            double v;
            mvp.get(&v, i % 4, i / 4);
            matrixF[i] = (float)v;
        }
        glUniformMatrix4fv(shader.u_mvp, 1u, false, matrixF);
    }
    // viewport size
    {
        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);
        glUniform2f(shader.u_viewportSize, (float)viewport[2] / 2.0f, (float)viewport[3] / 2.0f);
    }

    glUniform1i(shader.u_hitTest, drawForHitTest);

    GLfloat ignoreIdsRgba[GLBatchGeometryShader_maxIgnoreIds*4u];
    for (std::size_t i = 0u; i < (GLBatchGeometryShader_maxIgnoreIds*4u); i++)
        ignoreIdsRgba[i] = 0.f;

    const auto ignoreIdsLimit = std::min(GLBatchGeometryShader_maxIgnoreIds, ignoreIds.size());
    for (std::size_t i = 0u; i < ignoreIdsLimit; i++) {
        const auto ignoreId = ignoreIds[i];
        ignoreIdsRgba[i*4u+3u] = ((ignoreId>>24u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+2u] = ((ignoreId>>16u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+1u] = ((ignoreId>>8u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+0u] = (ignoreId&0xFFu) / 255.f;
    }

    glUniform4fv(shader.uIgnoreIds, GLBatchGeometryShader_maxIgnoreIds, ignoreIdsRgba);
    glUniform1f(shader.uLevelOfDetail, (float) levelOfDetail);
    glUniform1f(shader.uHitTestRadius, hitTestRadius);

    glUniform4f(shader.uColor, r, g, b, a);

    glEnableVertexAttribArray(shader.a_vertexCoord0);
    glEnableVertexAttribArray(shader.a_vertexCoord1);
    glEnableVertexAttribArray(shader.a_color);
    glEnableVertexAttribArray(shader.a_normal);
    glEnableVertexAttribArray(shader.a_halfStrokeWidth);
    glEnableVertexAttribArray(shader.a_dir);
    glEnableVertexAttribArray(shader.a_pattern); 
    glEnableVertexAttribArray(shader.a_factor);
    glEnableVertexAttribArray(shader.a_cap);
    if(shader.aId >= 0)
        glEnableVertexAttribArray(shader.aId);
    if(shader.aMinLevelOfDetail >= 0)
        glEnableVertexAttribArray(shader.aMinLevelOfDetail);
    if(shader.aMaxLevelOfDetail >= 0)
        glEnableVertexAttribArray(shader.aMaxLevelOfDetail);

    glVertexAttribDivisor(shader.a_normal, 0);
    glVertexAttribDivisor(shader.a_dir, 0);

    glVertexAttribDivisor(shader.a_vertexCoord0, 1);
    glVertexAttribDivisor(shader.a_vertexCoord1, 1);
    glVertexAttribDivisor(shader.a_color, 1);
    glVertexAttribDivisor(shader.a_halfStrokeWidth, 1);
    glVertexAttribDivisor(shader.a_pattern, 1);
    glVertexAttribDivisor(shader.a_factor, 1);
    glVertexAttribDivisor(shader.a_cap, 1);
    if(shader.aId >= 0)
        glVertexAttribDivisor(shader.aId, 1);
    if(shader.aMinLevelOfDetail >= 0)
        glVertexAttribDivisor(shader.aMinLevelOfDetail, 1);
    if(shader.aMaxLevelOfDetail >= 0)
        glVertexAttribDivisor(shader.aMaxLevelOfDetail, 1);

    // constant attribute values
    glDisableVertexAttribArray(shader.a_outlineWidth);
    glDisableVertexAttribArray(shader.a_outlineColor);

    glVertexAttrib1f(shader.a_outlineWidth, 0.f);
    glVertexAttrib4f(shader.a_outlineColor, 0.f, 0.f, 0.f, 0.f);

    // instance data
    glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
    ::glVertexAttribPointer(shader.a_normal, 1u, GL_UNSIGNED_SHORT, true, 4u, antialiasLineInstanceGeom);
    ::glVertexAttribPointer(shader.a_dir, 1u, GL_UNSIGNED_SHORT, true, 4u, &antialiasLineInstanceGeom[1u]);

    // XXX - employ some workarounds for nuances with the MPU RDC GL driers
    if(isMpu) {
        glDisableVertexAttribArray(shader.a_factor);
        glVertexAttribDivisor(shader.a_factor, 0);
        glVertexAttrib1f(shader.a_factor, 0.f);
    }


    for (const auto &buffer : buf) {
        glBindBuffer(GL_ARRAY_BUFFER, buffer.primitive.vbo);
        // XXX - VAOs
        glVertexAttribPointer(shader.a_vertexCoord0, buffer.layout.vertex.antiAliasedLines.position0);
        glVertexAttribPointer(shader.a_vertexCoord1, buffer.layout.vertex.antiAliasedLines.position1);
        if (drawForHitTest) {
            glVertexAttribPointer(shader.a_color, buffer.layout.vertex.antiAliasedLines.id);
        } else {
            glVertexAttribPointer(shader.a_color, buffer.layout.vertex.antiAliasedLines.color);
        }
        if(shader.aId >= 0)
            glVertexAttribPointer(shader.aId, buffer.layout.vertex.antiAliasedLines.id);
        if(shader.aMinLevelOfDetail >= 0)
            glVertexAttribPointer(shader.aMinLevelOfDetail, buffer.layout.vertex.antiAliasedLines.minLod);
        if(shader.aMaxLevelOfDetail >= 0)
            glVertexAttribPointer(shader.aMaxLevelOfDetail, buffer.layout.vertex.antiAliasedLines.maxLod);
        glVertexAttribPointer(shader.a_halfStrokeWidth, buffer.layout.vertex.antiAliasedLines.halfStrokeWidth);
        glVertexAttribIPointer(shader.a_pattern, buffer.layout.vertex.antiAliasedLines.pattern);
        if(!isMpu)
            glVertexAttribPointer(shader.a_factor, buffer.layout.vertex.antiAliasedLines.factor);
        glVertexAttribPointer(shader.a_cap, buffer.layout.vertex.antiAliasedLines.cap);
        glDrawArraysInstanced(buffer.primitive.mode, 0u, 6u, buffer.primitive.count);

        if(!drawForHitTest && !surface)
        {
            // turn off depth writes
            if(depthWriteEnabled)
                glDepthMask(GL_FALSE);
            // turn off cap/join vertex attribute
            glDisableVertexAttribArray(shader.a_cap);
            // enable joins on all segments
            glVertexAttrib2f(shader.a_cap, 1.f, 1.f);
            // draw lines
            glDrawArraysInstanced(buffer.primitive.mode, 0u, 6u, buffer.primitive.count);
            // re-enable cap/join vertex attribute
            glEnableVertexAttribArray(shader.a_cap);
            // restore depth writes
            if(depthWriteEnabled)
                glDepthMask(GL_TRUE);
        }
    }

    glDisableVertexAttribArray(shader.a_vertexCoord0);
    glDisableVertexAttribArray(shader.a_vertexCoord1);
    glDisableVertexAttribArray(shader.a_color);
    glDisableVertexAttribArray(shader.a_normal);
    glDisableVertexAttribArray(shader.a_halfStrokeWidth);
    glDisableVertexAttribArray(shader.a_dir);
    glDisableVertexAttribArray(shader.a_pattern);
    glDisableVertexAttribArray(shader.a_factor);
    glDisableVertexAttribArray(shader.a_cap);
    if(shader.aId >= 0)
        glDisableVertexAttribArray(shader.aId);
    if(shader.aMinLevelOfDetail >= 0)
        glDisableVertexAttribArray(shader.aMinLevelOfDetail);
    if(shader.aMaxLevelOfDetail >= 0)
        glDisableVertexAttribArray(shader.aMaxLevelOfDetail);

    glVertexAttribDivisor(shader.a_normal, 0);
    glVertexAttribDivisor(shader.a_dir, 0);
    glVertexAttribDivisor(shader.a_vertexCoord0, 0);
    glVertexAttribDivisor(shader.a_vertexCoord1, 0);
    glVertexAttribDivisor(shader.a_color, 0);
    glVertexAttribDivisor(shader.a_halfStrokeWidth, 0);
    glVertexAttribDivisor(shader.a_pattern, 0);
    glVertexAttribDivisor(shader.a_factor, 0);
    glVertexAttribDivisor(shader.a_cap, 0);
    if(shader.aId >= 0)
        glVertexAttribDivisor(shader.aId, 0);
    if(shader.aMinLevelOfDetail >= 0)
        glVertexAttribDivisor(shader.aMinLevelOfDetail, 0);
    if(shader.aMaxLevelOfDetail >= 0)
        glVertexAttribDivisor(shader.aMaxLevelOfDetail, 0);

    glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
    glUseProgram(GL_NONE);

    return code;
}
TAKErr GLBatchGeometryRenderer4::drawArrowBuffers(const GLGlobeBase::State &view, const std::size_t levelOfDetail, const BatchState &ctx, const std::vector<VertexBuffer> &buf, bool drawForHitTest, const float hitTestRadius, const bool surface, const std::vector<uint32_t> &ignoreIds, const float r, const float g, const float b, const float a) NOTHROWS {
    TAKErr code(TE_Ok);

    GLboolean depthWriteEnabled;
    glGetBooleanv(GL_DEPTH_WRITEMASK, &depthWriteEnabled);

    ArrowLinesShader shader;
    GLBatchGeometryShaderOptions opts;
    opts.enableDisplayThresholds = true;
    if (ignoreIds.empty()) {
        if (arrowShader.handle == 0) {
            arrowShader = GLBatchGeometryShaders_getArrowLinesShader(context, opts);
            assert(lineShader.base.handle);
        }
        shader = arrowShader;
    } else {
        const std::size_t numIgnoreIds = ignoreIds.size();
        opts.ignoreIdsCount = std::min(GLBatchGeometryShader_maxIgnoreIds, (std::size_t)1u<<(std::size_t)std::ceil(std::log((double)numIgnoreIds)/std::log(2.0)));
        shader = GLBatchGeometryShaders_getArrowLinesShader(context, opts);
        assert(shader.handle);
    }
    glUseProgram(shader.handle);

    // MVP
    {
        Matrix2 mvp;
        // projection
        float matrixF[16u];
        atakmap::renderer::GLMatrix::orthoM(matrixF, (float)view.left, (float)view.right, (float)view.bottom, (float)view.top, (float)view.scene.camera.near, (float)view.scene.camera.far);
        for(std::size_t i = 0u; i < 16u; i++)
            mvp.set(i%4, i/4, matrixF[i]);
        // model-view
        mvp.concatenate(view.scene.forwardTransform);
        mvp.translate(ctx.centroidProj.x, ctx.centroidProj.y, ctx.centroidProj.z);
        for (std::size_t i = 0u; i < 16u; i++) {
            double v;
            mvp.get(&v, i % 4, i / 4);
            matrixF[i] = (float)v;
        }
        glUniformMatrix4fv(shader.u_mvp, 1u, false, matrixF);
    }
    // viewport size
    {
        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);
        glUniform2f(shader.u_viewportSize, (float)viewport[2] / 2.0f, (float)viewport[3] / 2.0f);
    }

    GLfloat ignoreIdsRgba[GLBatchGeometryShader_maxIgnoreIds*4u];
    for (std::size_t i = 0u; i < (GLBatchGeometryShader_maxIgnoreIds*4u); i++)
        ignoreIdsRgba[i] = 0.f;

    const auto ignoreIdsLimit = std::min(GLBatchGeometryShader_maxIgnoreIds, ignoreIds.size());
    for (std::size_t i = 0u; i < ignoreIdsLimit; i++) {
        const auto ignoreId = ignoreIds[i];
        ignoreIdsRgba[i*4u+3u] = ((ignoreId>>24u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+2u] = ((ignoreId>>16u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+1u] = ((ignoreId>>8u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+0u] = (ignoreId&0xFFu) / 255.f;
    }

    glUniform4fv(shader.uIgnoreIds, GLBatchGeometryShader_maxIgnoreIds, ignoreIdsRgba);
    glUniform1f(shader.uLevelOfDetail, (float) levelOfDetail);

    glUniform4f(shader.uColor, r, g, b, a);

    glEnableVertexAttribArray(shader.a_vertexCoord0);
    glEnableVertexAttribArray(shader.a_vertexCoord1);
    glEnableVertexAttribArray(shader.a_color);
    glEnableVertexAttribArray(shader.a_position);
    glEnableVertexAttribArray(shader.a_radius);
    if(shader.aId >= 0)
        glEnableVertexAttribArray(shader.aId);
    if(shader.aMinLevelOfDetail >= 0)
        glEnableVertexAttribArray(shader.aMinLevelOfDetail);
    if(shader.aMaxLevelOfDetail >= 0)
        glEnableVertexAttribArray(shader.aMaxLevelOfDetail);

    glVertexAttribDivisor(shader.a_position, 0);

    glVertexAttribDivisor(shader.a_vertexCoord0, 1);
    glVertexAttribDivisor(shader.a_vertexCoord1, 1);
    glVertexAttribDivisor(shader.a_color, 1);
    glVertexAttribDivisor(shader.a_radius, 1);
    if(shader.aId >= 0)
        glVertexAttribDivisor(shader.aId, 1);
    if(shader.aMinLevelOfDetail >= 0)
        glVertexAttribDivisor(shader.aMinLevelOfDetail, 1);
    if(shader.aMaxLevelOfDetail >= 0)
        glVertexAttribDivisor(shader.aMaxLevelOfDetail, 1);

    // constant attribute values
    glDisableVertexAttribArray(shader.a_outlineWidth);
    glDisableVertexAttribArray(shader.a_outlineColor);

    glVertexAttrib1f(shader.a_outlineWidth, 0.f);
    glVertexAttrib4f(shader.a_outlineColor, 0.f, 0.f, 0.f, 0.f);

    // instance data
    glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
    ::glVertexAttribPointer(shader.a_position, 2u, GL_FLOAT, false, 8u, arrowInstanceGeom);

    for (const auto &buffer : buf) {
        glBindBuffer(GL_ARRAY_BUFFER, buffer.primitive.vbo);
        // XXX - VAOs
        glVertexAttribPointer(shader.a_vertexCoord0, buffer.layout.vertex.arrows.position0);
        glVertexAttribPointer(shader.a_vertexCoord1, buffer.layout.vertex.arrows.position1);
        if (drawForHitTest) {
            glVertexAttribPointer(shader.a_color, buffer.layout.vertex.arrows.id);
        } else {
            glVertexAttribPointer(shader.a_color, buffer.layout.vertex.arrows.color);
        }
        if(shader.aId >= 0)
            glVertexAttribPointer(shader.aId, buffer.layout.vertex.arrows.id);
        if(shader.aMinLevelOfDetail >= 0)
            glVertexAttribPointer(shader.aMinLevelOfDetail, buffer.layout.vertex.arrows.minLod);
        if(shader.aMaxLevelOfDetail >= 0)
            glVertexAttribPointer(shader.aMaxLevelOfDetail, buffer.layout.vertex.arrows.maxLod);
        glVertexAttribPointer(shader.a_radius, buffer.layout.vertex.arrows.radius);

        glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0u, arrowInstanceGeomCount, buffer.primitive.count);
    }

    glDisableVertexAttribArray(shader.a_vertexCoord0);
    glDisableVertexAttribArray(shader.a_vertexCoord1);
    glDisableVertexAttribArray(shader.a_color);
    glDisableVertexAttribArray(shader.a_position);
    glDisableVertexAttribArray(shader.a_radius);
    if(shader.aId >= 0)
        glDisableVertexAttribArray(shader.aId);
    if(shader.aMinLevelOfDetail >= 0)
        glDisableVertexAttribArray(shader.aMinLevelOfDetail);
    if(shader.aMaxLevelOfDetail >= 0)
        glDisableVertexAttribArray(shader.aMaxLevelOfDetail);

    glVertexAttribDivisor(shader.a_position, 0);
    glVertexAttribDivisor(shader.a_vertexCoord0, 0);
    glVertexAttribDivisor(shader.a_vertexCoord1, 0);
    glVertexAttribDivisor(shader.a_color, 0);
    glVertexAttribDivisor(shader.a_radius, 0);
    if(shader.aId >= 0)
        glVertexAttribDivisor(shader.aId, 0);
    if(shader.aMinLevelOfDetail >= 0)
        glVertexAttribDivisor(shader.aMinLevelOfDetail, 0);
    if(shader.aMaxLevelOfDetail >= 0)
        glVertexAttribDivisor(shader.aMaxLevelOfDetail, 0);

    glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
    glUseProgram(GL_NONE);

    return code;
}
TAKErr GLBatchGeometryRenderer4::drawMeshBuffers(const GLGlobeBase::State &view, const std::size_t levelOfDetail, const BatchState &ctx, const std::vector<VertexBuffer> &buf, bool drawForHitTest, const float hitTestRadius, const std::vector<uint32_t> &ignoreIds, const std::shared_ptr<const TAK::Engine::Model::Mesh>& mesh) NOTHROWS {
    TAKErr code(TE_Ok);

    if (!mesh) return TE_InvalidArg;

    MeshesShader shader;
    GLBatchGeometryShaderOptions opts;
    opts.enableDisplayThresholds = true;
    if (ignoreIds.empty()) {
        if (meshesShader.handle == 0) {
            meshesShader = GLBatchGeometryShaders_getMeshesShader(context, opts);
            assert(meshesShader.handle);
        }
        shader = meshesShader;
    } else {
        const std::size_t numIgnoreIds = ignoreIds.size();
        opts.ignoreIdsCount = std::min(GLBatchGeometryShader_maxIgnoreIds, (std::size_t)1u<<(std::size_t)std::ceil(std::log((double)numIgnoreIds)/std::log(2.0)));
        shader = GLBatchGeometryShaders_getMeshesShader(context, opts);
        assert(shader.handle);
    }

    // Get vertex data from mesh
    const void *vertices;
    const void *texCoords;
    const void *colorCoords;
    const void *normals;
    code = mesh->getVertices(&vertices, TEVA_Position);
    code = mesh->getVertices(&texCoords, TEVA_TexCoord0);
    bool hasTextureCoordinates = code == TE_Ok;
    code = mesh->getVertices(&colorCoords, TEVA_Color);
    bool hasColorCoordinates = !drawForHitTest && code == TE_Ok;
    code = mesh->getVertices(&normals, TEVA_Normal);
    bool hasNormals = code == TE_Ok;

    glUseProgram(shader.handle);
    RenderState rs = RenderState_getCurrent();

    if (mesh->getFaceWindingOrder() != TEWO_Undefined) {
        GLint frontFace;
        switch (mesh->getFaceWindingOrder()) {
            case TEWO_Clockwise :
                frontFace = GL_CW;
                break;
            case TEWO_CounterClockwise :
                frontFace = GL_CCW;
                break;
            default :
                // XXX - illegal state
                frontFace = GL_CCW;
                break;
        }
        glCullFace(GL_BACK);
        glFrontFace(frontFace);
        glEnable(GL_CULL_FACE);
    }

    // MVP
    {
        Matrix2 mvp;
        // projection
        float matrixF[16u];
        atakmap::renderer::GLMatrix::orthoM(matrixF, (float)view.left, (float)view.right, (float)view.bottom, (float)view.top, (float)view.scene.camera.near, (float)view.scene.camera.far);
        for(std::size_t i = 0u; i < 16u; i++)
            mvp.set(i%4, i/4, matrixF[i]);
        // model-view
        mvp.concatenate(view.scene.forwardTransform);
        mvp.translate(ctx.centroidProj.x, ctx.centroidProj.y, ctx.centroidProj.z);
        for (std::size_t i = 0u; i < 16u; i++) {
            double v;
            mvp.get(&v, i % 4, i / 4);
            matrixF[i] = (float)v;
        }
        glUniformMatrix4fv(shader.uMvp, 1u, false, matrixF);
    }

    GLfloat ignoreIdsRgba[GLBatchGeometryShader_maxIgnoreIds*4u];
    for (std::size_t i = 0u; i < (GLBatchGeometryShader_maxIgnoreIds*4u); i++)
        ignoreIdsRgba[i] = 0.f;

    const auto ignoreIdsLimit = std::min(GLBatchGeometryShader_maxIgnoreIds, ignoreIds.size());
    for (std::size_t i = 0u; i < ignoreIdsLimit; i++) {
        const auto ignoreId = ignoreIds[i];
        ignoreIdsRgba[i*4u+3u] = ((ignoreId>>24u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+2u] = ((ignoreId>>16u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+1u] = ((ignoreId>>8u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+0u] = (ignoreId&0xFFu) / 255.f;
    }

    glUniform4fv(shader.uIgnoreIds, GLBatchGeometryShader_maxIgnoreIds, ignoreIdsRgba);
    glUniform1f(shader.uLevelOfDetail, (float) levelOfDetail);

    GLenum textureUnit{ GL_TEXTURE0 };
    glActiveTexture(textureUnit);
    glUniform1i(shader.uTexture, textureUnit - GL_TEXTURE0);

    glUniform4f(shader.uColor, 1.0f, 1.0f, 1.0f, 1.0f);
    if (drawForHitTest) {
        glUniform1f(shader.uLightingFactor, 0.f);
    } else {
        glUniform1f(shader.uLightingFactor, 1.f);
    }

    glEnableVertexAttribArray(shader.aPosition);
    if (hasTextureCoordinates) glEnableVertexAttribArray(shader.aTexPos);
    if (hasColorCoordinates) glEnableVertexAttribArray(shader.aVertColor);
    if (hasNormals) glEnableVertexAttribArray(shader.aNormals);
    glEnableVertexAttribArray(shader.aVertexCoord);
    glEnableVertexAttribArray(shader.aSpriteBottomLeft);
    glEnableVertexAttribArray(shader.aSpriteTopRight);
    glEnableVertexAttribArray(shader.aColor);
    glEnableVertexAttribArray(shader.aTransform);
    glEnableVertexAttribArray(shader.aTransform + 1);
    glEnableVertexAttribArray(shader.aTransform + 2);
    glEnableVertexAttribArray(shader.aTransform + 3);
    if (shader.aId >= 0)
        glEnableVertexAttribArray(shader.aId);
    if (shader.aMinLevelOfDetail >= 0)
        glEnableVertexAttribArray(shader.aMinLevelOfDetail);
    if (shader.aMaxLevelOfDetail >= 0)
        glEnableVertexAttribArray(shader.aMaxLevelOfDetail);

    glVertexAttribDivisor(shader.aPosition, 0);
    glVertexAttribDivisor(shader.aTexPos, 0);
    glVertexAttribDivisor(shader.aVertColor, 0);
    glVertexAttribDivisor(shader.aNormals, 0);

    glVertexAttribDivisor(shader.aVertexCoord, 1);
    glVertexAttribDivisor(shader.aSpriteBottomLeft, 1);
    glVertexAttribDivisor(shader.aSpriteTopRight, 1);
    glVertexAttribDivisor(shader.aColor, 1);
    glVertexAttribDivisor(shader.aTransform, 1);
    glVertexAttribDivisor(shader.aTransform + 1, 1);
    glVertexAttribDivisor(shader.aTransform + 2, 1);
    glVertexAttribDivisor(shader.aTransform + 3, 1);
    if(shader.aId >= 0)
        glVertexAttribDivisor(shader.aId, 1);
    if(shader.aMinLevelOfDetail >= 0)
        glVertexAttribDivisor(shader.aMinLevelOfDetail, 1);
    if(shader.aMaxLevelOfDetail >= 0)
        glVertexAttribDivisor(shader.aMaxLevelOfDetail, 1);

    GLuint bufs[5u];
    glGenBuffers(5u, bufs);
    {
        const VertexDataLayout vertexDataLayout = mesh->getVertexDataLayout();
        std::size_t size = mesh->getNumVertices() * vertexDataLayout.position.stride;
        if (vertexDataLayout.interleaved)
            VertexDataLayout_requiredInterleavedDataSize(&size, vertexDataLayout, mesh->getNumVertices());
        glBindBuffer(GL_ARRAY_BUFFER, bufs[0]);
        ::glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
        ::glVertexAttribPointer(shader.aPosition, 3u, GL_FLOAT, false, static_cast<GLsizei>(vertexDataLayout.position.stride), (void *)vertexDataLayout.position.offset);
        glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
    }
    if (mesh->isIndexed()) {
        DataType indexType;
        mesh->getIndexType(&indexType);
        std::size_t size = mesh->getNumIndices() * DataType_size(indexType);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufs[1]);
        ::glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, static_cast<const uint8_t *>(mesh->getIndices()) + mesh->getIndexOffset(), GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_NONE);
    }
    if (hasTextureCoordinates) {
        const VertexDataLayout vertexDataLayout = mesh->getVertexDataLayout();
        std::size_t size = mesh->getNumVertices() * vertexDataLayout.texCoord0.stride;
        if (vertexDataLayout.interleaved)
            VertexDataLayout_requiredInterleavedDataSize(&size, vertexDataLayout, mesh->getNumVertices());
        glBindBuffer(GL_ARRAY_BUFFER, bufs[2]);
        ::glBufferData(GL_ARRAY_BUFFER, size, texCoords, GL_STATIC_DRAW);
        ::glVertexAttribPointer(shader.aTexPos, 2u, GL_FLOAT, false, static_cast<GLsizei>(vertexDataLayout.texCoord0.stride), (void *)vertexDataLayout.texCoord0.offset);
        glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
    } else {
        glVertexAttrib2f(shader.aTexPos, 0, 0);
    }
    if (hasColorCoordinates) {
        const VertexDataLayout vertexDataLayout = mesh->getVertexDataLayout();
        std::size_t size = mesh->getNumVertices() * vertexDataLayout.color.stride;
        if (vertexDataLayout.interleaved)
            VertexDataLayout_requiredInterleavedDataSize(&size, vertexDataLayout, mesh->getNumVertices());
        glBindBuffer(GL_ARRAY_BUFFER, bufs[3]);
        ::glBufferData(GL_ARRAY_BUFFER, size, colorCoords, GL_STATIC_DRAW);
        ::glVertexAttribPointer(shader.aVertColor, 4u, GL_UNSIGNED_BYTE, true, static_cast<GLsizei>(vertexDataLayout.color.stride), (void *)vertexDataLayout.color.offset);
        glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
    } else {
        glVertexAttrib4f(shader.aVertColor, 1, 1, 1, 1);
    }
    if (hasNormals) {
        const VertexDataLayout vertexDataLayout = mesh->getVertexDataLayout();
        std::size_t size = mesh->getNumVertices() * vertexDataLayout.normal.stride;
        if (vertexDataLayout.interleaved)
            VertexDataLayout_requiredInterleavedDataSize(&size, vertexDataLayout, mesh->getNumVertices());
        glBindBuffer(GL_ARRAY_BUFFER, bufs[4]);
        ::glBufferData(GL_ARRAY_BUFFER, size, normals, GL_STATIC_DRAW);
        ::glVertexAttribPointer(shader.aNormals, 3u, GL_FLOAT, false, static_cast<GLsizei>(vertexDataLayout.normal.stride), (void *)vertexDataLayout.normal.offset);
        glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
    } else {
        glVertexAttrib3f(shader.aNormals, 1, 1, 1);
    }

    GLenum draw_mode = GL_NONE;

    switch (mesh->getDrawMode()) {
        case TEDM_Triangles:
            draw_mode = GL_TRIANGLES;
            break;
        case TEDM_TriangleStrip:
            draw_mode = GL_TRIANGLE_STRIP;
            break;
        case TEDM_Points:
            draw_mode = GL_POINTS;
            break;
        default: break;
    }

    for (const auto &buffer : buf) {
        glBindBuffer(GL_ARRAY_BUFFER, buffer.primitive.vbo);
        glVertexAttribPointer(shader.aVertexCoord, buffer.layout.vertex.meshes.vertexCoord);
        glVertexAttribPointer(shader.aSpriteBottomLeft, buffer.layout.vertex.meshes.spriteBottomLeft);
        glVertexAttribPointer(shader.aSpriteTopRight, buffer.layout.vertex.meshes.spriteTopRight);
        if (drawForHitTest) {
            glVertexAttribPointer(shader.aColor, buffer.layout.vertex.meshes.id);
        } else {
            glVertexAttribPointer(shader.aColor, buffer.layout.vertex.meshes.color);
        }
        ::glVertexAttribPointer(shader.aTransform, buffer.layout.vertex.meshes.transform.size / 4, buffer.layout.vertex.meshes.transform.type, buffer.layout.vertex.meshes.transform.normalized, buffer.layout.vertex.meshes.transform.stride, (const void*)((const unsigned char *)nullptr + buffer.layout.vertex.meshes.transform.offset));
        ::glVertexAttribPointer(shader.aTransform + 1, buffer.layout.vertex.meshes.transform.size / 4, buffer.layout.vertex.meshes.transform.type, buffer.layout.vertex.meshes.transform.normalized, buffer.layout.vertex.meshes.transform.stride, (const void*)((const unsigned char *)nullptr + buffer.layout.vertex.meshes.transform.offset + (sizeof(float) * 4)));
        ::glVertexAttribPointer(shader.aTransform + 2, buffer.layout.vertex.meshes.transform.size / 4, buffer.layout.vertex.meshes.transform.type, buffer.layout.vertex.meshes.transform.normalized, buffer.layout.vertex.meshes.transform.stride, (const void*)((const unsigned char *)nullptr + buffer.layout.vertex.meshes.transform.offset + (sizeof(float) * 8)));
        ::glVertexAttribPointer(shader.aTransform + 3, buffer.layout.vertex.meshes.transform.size / 4, buffer.layout.vertex.meshes.transform.type, buffer.layout.vertex.meshes.transform.normalized, buffer.layout.vertex.meshes.transform.stride, (const void*)((const unsigned char *)nullptr + buffer.layout.vertex.meshes.transform.offset + (sizeof(float) * 12)));

        if(shader.aId >= 0)
            glVertexAttribPointer(shader.aId, buffer.layout.vertex.meshes.id);
        if(shader.aMinLevelOfDetail >= 0)
            glVertexAttribPointer(shader.aMinLevelOfDetail, buffer.layout.vertex.meshes.minLod);
        if(shader.aMaxLevelOfDetail >= 0)
            glVertexAttribPointer(shader.aMaxLevelOfDetail, buffer.layout.vertex.meshes.maxLod);

        if (!hasTextureCoordinates || drawForHitTest) {
            GLuint hitTestTexture;
            GLMapRenderGlobals_getWhitePixel(&hitTestTexture, context);
            glBindTexture(GL_TEXTURE_2D, hitTestTexture);
        } else {
            glBindTexture(GL_TEXTURE_2D, buffer.primitive.texid);
        }

        glDrawArraysInstanced(draw_mode, 0u, (GLsizei)mesh->getNumVertices(), buffer.primitive.count);
    }

    glDisableVertexAttribArray(shader.aPosition);
    glDisableVertexAttribArray(shader.aTexPos);
    glDisableVertexAttribArray(shader.aVertColor);
    glDisableVertexAttribArray(shader.aNormals);
    glDisableVertexAttribArray(shader.aVertexCoord);
    glDisableVertexAttribArray(shader.aSpriteBottomLeft);
    glDisableVertexAttribArray(shader.aSpriteTopRight);
    glDisableVertexAttribArray(shader.aColor);
    glDisableVertexAttribArray(shader.aTransform);
    glDisableVertexAttribArray(shader.aTransform + 1);
    glDisableVertexAttribArray(shader.aTransform + 2);
    glDisableVertexAttribArray(shader.aTransform + 3);
    if (shader.aId)
        glDisableVertexAttribArray(shader.aId);
    if (shader.aMinLevelOfDetail)
        glDisableVertexAttribArray(shader.aMinLevelOfDetail);
    if (shader.aMaxLevelOfDetail)
        glDisableVertexAttribArray(shader.aMaxLevelOfDetail);

    glVertexAttribDivisor(shader.aPosition, 0);
    glVertexAttribDivisor(shader.aTexPos, 0);
    glVertexAttribDivisor(shader.aVertColor, 0);
    glVertexAttribDivisor(shader.aNormals, 0);
    glVertexAttribDivisor(shader.aVertexCoord, 0);
    glVertexAttribDivisor(shader.aSpriteBottomLeft, 0);
    glVertexAttribDivisor(shader.aSpriteTopRight, 0);
    glVertexAttribDivisor(shader.aColor, 0);
    glVertexAttribDivisor(shader.aTransform, 0);
    glVertexAttribDivisor(shader.aTransform + 1, 0);
    glVertexAttribDivisor(shader.aTransform + 2, 0);
    glVertexAttribDivisor(shader.aTransform + 3, 0);
    if(shader.aId >= 0)
        glVertexAttribDivisor(shader.aId, 0);
    if(shader.aMinLevelOfDetail >= 0)
        glVertexAttribDivisor(shader.aMinLevelOfDetail, 0);
    if(shader.aMaxLevelOfDetail >= 0)
        glVertexAttribDivisor(shader.aMaxLevelOfDetail, 0);

    glBindTexture(GL_TEXTURE_2D, 0);
    glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
    glDeleteBuffers(5u, bufs);
    RenderState_makeCurrent(rs);
    glUseProgram(GL_NONE);

    return code;
}
TAKErr GLBatchGeometryRenderer4::drawPolygonBuffers(const GLGlobeBase::State &view, const std::size_t levelOfDetail, const BatchState &ctx, const std::vector<VertexBuffer> &buf, bool drawForHitTest, const float hitTestRadius, const bool surface, const std::vector<uint32_t> &ignoreIds) NOTHROWS
{
    TAKErr code(TE_Ok);

    PolygonsShader shader;
    GLBatchGeometryShaderOptions opts;
    opts.enableDisplayThresholds = true;
    opts.enablePolygonLighting = true;
    if (ignoreIds.empty()) {
        if (polygonsShader.handle == 0) {
            polygonsShader = GLBatchGeometryShaders_getPolygonsShader(context, opts);
            assert(polygonsShader.handle);
        }
        shader = polygonsShader;
    } else {
        const std::size_t numIgnoreIds = ignoreIds.size();
        opts.ignoreIdsCount = std::min(GLBatchGeometryShader_maxIgnoreIds, (std::size_t)1u<<(std::size_t)std::ceil(std::log((double)numIgnoreIds)/std::log(2.0)));
        shader = GLBatchGeometryShaders_getPolygonsShader(context, opts);
        assert(shader.handle);
    }
    glUseProgram(shader.handle);

    // MVP
    {
        Matrix2 mvp;
        // projection
        float matrixF[16u];
        atakmap::renderer::GLMatrix::orthoM(matrixF, (float)view.left, (float)view.right, (float)view.bottom, (float)view.top, (float)view.scene.camera.near, (float)view.scene.camera.far);
        for(std::size_t i = 0u; i < 16u; i++)
            mvp.set(i%4, i/4, matrixF[i]);
        // model-view
        mvp.concatenate(view.scene.forwardTransform);
        mvp.translate(ctx.centroidProj.x, ctx.centroidProj.y, ctx.centroidProj.z);
        for (std::size_t i = 0u; i < 16u; i++) {
            double v;
            mvp.get(&v, i % 4, i / 4);
            matrixF[i] = (float)v;
        }
        glUniformMatrix4fv(shader.u_mvp, 1u, false, matrixF);
    }

    glUniform4f(shader.uColor, 1.f, 1.f, 1.f, 1.f);

    GLfloat ignoreIdsRgba[GLBatchGeometryShader_maxIgnoreIds*4u];
    for (std::size_t i = 0u; i < (GLBatchGeometryShader_maxIgnoreIds*4u); i++)
        ignoreIdsRgba[i] = 0.f;

    const auto ignoreIdsLimit = std::min(GLBatchGeometryShader_maxIgnoreIds, ignoreIds.size());
    for (std::size_t i = 0u; i < ignoreIdsLimit; i++) {
        const auto ignoreId = ignoreIds[i];
        ignoreIdsRgba[i*4u+3u] = ((ignoreId>>24u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+2u] = ((ignoreId>>16u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+1u] = ((ignoreId>>8u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+0u] = (ignoreId&0xFFu) / 255.f;
    }

    glUniform4fv(shader.uIgnoreIds, GLBatchGeometryShader_maxIgnoreIds, ignoreIdsRgba);
    glUniform1f(shader.uLevelOfDetail, (float) levelOfDetail);
    glUniform1f(shader.uLightingFactor, (drawForHitTest || surface) ? 0.f : 0.6f);

    glEnableVertexAttribArray(shader.aPosition);
    glEnableVertexAttribArray(shader.a_color);
    glEnableVertexAttribArray(shader.aOutlineWidth);
    glEnableVertexAttribArray(shader.aExteriorVertex);
    if (shader.aId >= 0)
        glEnableVertexAttribArray(shader.aId);
    if (shader.aMinLevelOfDetail >= 0)
        glEnableVertexAttribArray(shader.aMinLevelOfDetail);
    if (shader.aMaxLevelOfDetail >= 0)
        glEnableVertexAttribArray(shader.aMaxLevelOfDetail);

    for (const auto &buffer : buf) {
        glBindBuffer(GL_ARRAY_BUFFER, buffer.primitive.vbo);
        // XXX - VAOs
        glVertexAttribPointer(shader.aPosition, buffer.layout.vertex.polygons.position);
        glVertexAttribPointer(shader.aOutlineWidth, buffer.layout.vertex.polygons.outlineWidth);
        glVertexAttribPointer(shader.aExteriorVertex, buffer.layout.vertex.polygons.exteriorVertex);
        if (drawForHitTest) {
            glVertexAttribPointer(shader.a_color, buffer.layout.vertex.polygons.id);
        } else {
            glVertexAttribPointer(shader.a_color, buffer.layout.vertex.polygons.color);
        }
        if(shader.aId >= 0)
            glVertexAttribPointer(shader.aId, buffer.layout.vertex.polygons.id);
        if(shader.aMinLevelOfDetail >= 0)
            glVertexAttribPointer(shader.aMinLevelOfDetail, buffer.layout.vertex.polygons.minLod);
        if(shader.aMaxLevelOfDetail >= 0)
            glVertexAttribPointer(shader.aMaxLevelOfDetail, buffer.layout.vertex.polygons.maxLod);
        glDrawArrays(buffer.primitive.mode, 0u, buffer.primitive.count);
    }

    glDisableVertexAttribArray(shader.aPosition);
    glDisableVertexAttribArray(shader.a_color);
    glDisableVertexAttribArray(shader.aOutlineWidth);
    glDisableVertexAttribArray(shader.aExteriorVertex);
    if (shader.aId)
        glDisableVertexAttribArray(shader.aId);
    if (shader.aMinLevelOfDetail)
        glDisableVertexAttribArray(shader.aMinLevelOfDetail);
    if (shader.aMaxLevelOfDetail)
        glDisableVertexAttribArray(shader.aMaxLevelOfDetail);

    glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
    glUseProgram(GL_NONE);

    return code;
}
TAKErr GLBatchGeometryRenderer4::batchDrawPoints(const GLGlobeBase::State &view, const std::size_t levelOfDetail, const BatchState &ctx, bool drawForHitTest, const float hitTestRadius, const std::vector<uint32_t> &ignoreIds) NOTHROWS
{
    TAKErr code(TE_Ok);

    const bool forceClampToGround = clampToGroundControl.value ?
        (clampToGroundControl.value->getClampToGroundAtNadir() && !view.drawTilt) : false;

    struct
    {
        unsigned int color{ 0xFFFFFFFFu };
        GLuint texId{ GL_NONE };
        GLenum textureUnit{ GL_TEXTURE0 };
    } state;

    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(1.f, 1.f);

    glEnable(GL_PROGRAM_POINT_SIZE);
    glEnable(GL_POINT_SPRITE);

    PointsShader shader;
    GLBatchGeometryShaderOptions opts;
    opts.enableDisplayThresholds = true;
    opts.enableHitTestRadius = true;
    opts.enablePixelOffset = true;
    if (ignoreIds.empty()) {
        if (pointShader.handle == 0) {
            pointShader = GLBatchGeometryShaders_getPointsShader(context, opts);
            assert(pointShader.handle);
        }
        shader = pointShader;
    } else {
        const std::size_t numIgnoreIds = ignoreIds.size();
        opts.ignoreIdsCount = std::min(GLBatchGeometryShader_maxIgnoreIds, (std::size_t)1u<<(std::size_t)std::ceil(std::log((double)numIgnoreIds)/std::log(2.0)));
        shader = GLBatchGeometryShaders_getPointsShader(context, opts);
        assert(shader.handle);
    }

    glUseProgram(shader.handle);

    float proj[16];
    atakmap::renderer::GLMatrix::orthoM(proj, (float)view.left, (float)view.right, (float)view.bottom, (float)view.top, (float)view.scene.camera.near, (float)view.scene.camera.far);

    Matrix2 mvp(
        proj[0], proj[4], proj[8], proj[12],
        proj[1], proj[5], proj[9], proj[13],
        proj[2], proj[6], proj[10], proj[14],
        proj[3], proj[7], proj[11], proj[15]);
    mvp.concatenate(view.scene.forwardTransform);
    // we will concatenate the local frame to the MapSceneModel's Model-View matrix to transform
    // from the Local Coordinate System into world coordinates before applying the model view.
    // If we do this all in double precision, then cast to single-precision, we'll avoid the
    // precision issues with trying to cast the world coordinates to float
    mvp.concatenate(ctx.localFrame);
    double mvpd[16];
    mvp.get(mvpd, Matrix2::COLUMN_MAJOR);
    float mvpf[16];
    for (std::size_t i = 0u; i < 16u; i++) mvpf[i] = (float)mvpd[i];

    glUniformMatrix4fv(shader.uMVP, 1, false, mvpf);

    // work with texture0
    glActiveTexture(state.textureUnit);
    glUniform1i(shader.uTexture, state.textureUnit - GL_TEXTURE0);

    // sync the current color with the shader
    glUniform4f(shader.uColor, ((state.color >> 16) & 0xFF) / (float)255, ((state.color >> 8) & 0xFF) / (float)255,
                (state.color & 0xFF) / (float)255, ((state.color >> 24) & 0xFF) / (float)255);

    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);

    double angle = (view.scene.camera.azimuth * M_PI) / 180.0;
    glUniform2f(shader.uMapRotation, (float)angle, (float)angle);
    glUniform1f(shader.uDrawTilt, (float)((90.0 + view.scene.camera.elevation)*M_PI/180.0));
    glUniform3f(shader.uWcsScale,
        (float)view.scene.displayModel->projectionXToNominalMeters,
        (float)view.scene.displayModel->projectionYToNominalMeters,
        (float)view.scene.displayModel->projectionZToNominalMeters);
    glUniform3f(shader.uCameraRtc,
        (float)(view.scene.camera.location.x-ctx.centroidProj.x),
        (float)(view.scene.camera.location.y-ctx.centroidProj.y),
        (float)(view.scene.camera.location.z-ctx.centroidProj.z));
    glUniform1f(shader.uTanHalfFov, (float)tan((view.scene.camera.fov / 2.0)* M_PI / 180.0));
    glUniform1f(shader.uViewportWidth, (float)viewport[2]);
    glUniform1f(shader.uViewportHeight, (float)viewport[3]);
    glUniform1f(shader.uClampToSurface, forceClampToGround ? 1.f : 0.f);

    GLfloat ignoreIdsRgba[GLBatchGeometryShader_maxIgnoreIds*4u];
    for (std::size_t i = 0u; i < (GLBatchGeometryShader_maxIgnoreIds*4u); i++)
        ignoreIdsRgba[i] = 0.f;

    const auto ignoreIdsLimit = std::min(GLBatchGeometryShader_maxIgnoreIds, ignoreIds.size());
    for (std::size_t i = 0u; i < ignoreIdsLimit; i++) {
        const auto ignoreId = ignoreIds[i];
        ignoreIdsRgba[i*4u+3u] = ((ignoreId>>24u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+2u] = ((ignoreId>>16u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+1u] = ((ignoreId>>8u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+0u] = (ignoreId&0xFFu) / 255.f;
    }

    glUniform4fv(shader.uIgnoreIds, GLBatchGeometryShader_maxIgnoreIds, ignoreIdsRgba);
    glUniform1f(shader.uLevelOfDetail, (float) levelOfDetail);
    glUniform1f(shader.uHitTestRadius, hitTestRadius);

    glEnableVertexAttribArray(shader.aVertexCoords);
    glEnableVertexAttribArray(shader.aSurfaceVertexCoords);
    glEnableVertexAttribArray(shader.spriteBottomLeft);
    glEnableVertexAttribArray(shader.spriteDimensions);
    glEnableVertexAttribArray(shader.aAbsoluteRotationFlag);
    glEnableVertexAttribArray(shader.aRotation);
    glEnableVertexAttribArray(shader.aPointSize);
    glEnableVertexAttribArray(shader.aColor);
    if(shader.aId >= 0)
        glEnableVertexAttribArray(shader.aId);
    if(shader.aMinLevelOfDetail >= 0)
        glEnableVertexAttribArray(shader.aMinLevelOfDetail);
    if(shader.aMaxLevelOfDetail >= 0)
        glEnableVertexAttribArray(shader.aMaxLevelOfDetail);
    if (shader.aOffset >= 0)
        glEnableVertexAttribArray(shader.aOffset);

    for (auto &buf : pointsBuffers) {
        // set the texture for this batch
        state.texId = buf.primitive.texid;
        if (!state.texId)
            continue;

        if (drawForHitTest) {
            GLuint hitTestTexture;
            GLMapRenderGlobals_getWhitePixel(&hitTestTexture, context);
            glBindTexture(GL_TEXTURE_2D, hitTestTexture);
        } else {
            glBindTexture(GL_TEXTURE_2D, state.texId);
        }

        // set the color for this batch
        // XXX - 
        state.color = 0xFFFFFFFFu;

            
        if (drawForHitTest) {
            glUniform4f(shader.uColor, 1.0f, 1.0f, 1.0f, 1.0f);
        } else {
            glUniform4f(shader.uColor, ((state.color >> 16) & 0xFF) / (float)255,
                        ((state.color >> 8) & 0xFF) / (float)255, (state.color & 0xFF) / (float)255,
                        ((state.color >> 24) & 0xFF) / (float)255);
        }

        glBindBuffer(GL_ARRAY_BUFFER, buf.primitive.vbo);

        glVertexAttribPointer(shader.aVertexCoords, buf.layout.vertex.points.position);
        glVertexAttribPointer(shader.aSurfaceVertexCoords, buf.layout.vertex.points.surfacePosition);
        glVertexAttribPointer(shader.spriteBottomLeft, buf.layout.vertex.points.spriteBottomLeft);
        glVertexAttribPointer(shader.spriteDimensions, buf.layout.vertex.points.spriteDimensions);
        glVertexAttribPointer(shader.aAbsoluteRotationFlag, buf.layout.vertex.points.absoluteRotationFlag);
        glVertexAttribPointer(shader.aRotation, buf.layout.vertex.points.rotation);
        glVertexAttribPointer(shader.aPointSize, buf.layout.vertex.points.pointSize);
        if (drawForHitTest) {
            glVertexAttribPointer(shader.aColor, buf.layout.vertex.points.id);
        } else {
            glVertexAttribPointer(shader.aColor, buf.layout.vertex.points.color);
        }
        if(shader.aId >= 0)
            glVertexAttribPointer(shader.aId, buf.layout.vertex.points.id);
        if(shader.aMinLevelOfDetail >= 0)
            glVertexAttribPointer(shader.aMinLevelOfDetail, buf.layout.vertex.points.minLod);
        if(shader.aMaxLevelOfDetail >= 0)
            glVertexAttribPointer(shader.aMaxLevelOfDetail, buf.layout.vertex.points.maxLod);
        if(shader.aOffset >= 0)
            glVertexAttribPointer(shader.aOffset, buf.layout.vertex.points.offset);

        glDrawArrays(buf.primitive.mode, 0, buf.primitive.count);
    }

    glDisableVertexAttribArray(shader.aVertexCoords);
    glDisableVertexAttribArray(shader.aSurfaceVertexCoords);
    glDisableVertexAttribArray(shader.spriteBottomLeft);
    glDisableVertexAttribArray(shader.spriteDimensions);
    glDisableVertexAttribArray(shader.aAbsoluteRotationFlag);
    glDisableVertexAttribArray(shader.aRotation);
    glDisableVertexAttribArray(shader.aPointSize);
    glDisableVertexAttribArray(shader.aColor);
    if (shader.aId >= 0)
        glDisableVertexAttribArray(shader.aId);
    if (shader.aMinLevelOfDetail >= 0)
        glDisableVertexAttribArray(shader.aMinLevelOfDetail);
    if (shader.aMaxLevelOfDetail >= 0)
        glDisableVertexAttribArray(shader.aMaxLevelOfDetail);
    if (shader.aOffset >= 0)
        glDisableVertexAttribArray(shader.aOffset);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    if (state.texId != 0) {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
    glUseProgram(GL_NONE);

    glDisable(GL_PROGRAM_POINT_SIZE);
    glDisable(GL_POINT_SPRITE);

    glDisable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(0.f, 0.f);

    // draw lollipops
    if(!forceClampToGround && !drawForHitTest)
        drawLollipopBuffers(view, levelOfDetail, ctx, pointsBuffers, drawForHitTest, hitTestRadius, false, ignoreIds);

    return code;
}
TAKErr GLBatchGeometryRenderer4::drawLollipopBuffers(const GLGlobeBase::State &view, const std::size_t levelOfDetail, const BatchState &ctx, const std::vector<VertexBuffer> &buf, bool drawForHitTest, const float hitTestRadius, const bool surface, const std::vector<uint32_t> &ignoreIds, const float r, const float g, const float b, const float a) NOTHROWS {
    TAKErr code(TE_Ok);

    GLboolean depthWriteEnabled;
    glGetBooleanv(GL_DEPTH_WRITEMASK, &depthWriteEnabled);

    AntiAliasedLinesShader shader;
    GLBatchGeometryShaderOptions opts;
    opts.enableDisplayThresholds = true;
    opts.enableHitTestRadius = true;
    if (ignoreIds.empty()) {
        if (lineShader.base.handle == 0) {
            lineShader = GLBatchGeometryShaders_getAntiAliasedLinesShader(context, opts);
            assert(lineShader.base.handle);
        }
        shader = lineShader;
    } else {
        const std::size_t numIgnoreIds = ignoreIds.size();
        opts.ignoreIdsCount = std::min(GLBatchGeometryShader_maxIgnoreIds, (std::size_t)1u<<(std::size_t)std::ceil(std::log((double)numIgnoreIds)/std::log(2.0)));
        shader = GLBatchGeometryShaders_getAntiAliasedLinesShader(context, opts);
        assert(shader.base.handle);
    }
    glUseProgram(shader.base.handle);

    // MVP
    {
        Matrix2 mvp;
        // projection
        float matrixF[16u];
        atakmap::renderer::GLMatrix::orthoM(matrixF, (float)view.left, (float)view.right, (float)view.bottom, (float)view.top, (float)view.scene.camera.near, (float)view.scene.camera.far);
        for(std::size_t i = 0u; i < 16u; i++)
            mvp.set(i%4, i/4, matrixF[i]);
        // model-view
        mvp.concatenate(view.scene.forwardTransform);
        mvp.translate(ctx.centroidProj.x, ctx.centroidProj.y, ctx.centroidProj.z);
        for (std::size_t i = 0u; i < 16u; i++) {
            double v;
            mvp.get(&v, i % 4, i / 4);
            matrixF[i] = (float)v;
        }
        glUniformMatrix4fv(shader.u_mvp, 1u, false, matrixF);
    }
    // viewport size
    {
        GLint viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);
        glUniform2f(shader.u_viewportSize, (float)viewport[2] / 2.0f, (float)viewport[3] / 2.0f);
    }

    glUniform1i(shader.u_hitTest, drawForHitTest);

    glUniform1f(shader.uHitTestRadius, hitTestRadius);

    GLfloat ignoreIdsRgba[GLBatchGeometryShader_maxIgnoreIds*4u];
    for (std::size_t i = 0u; i < (GLBatchGeometryShader_maxIgnoreIds*4u); i++)
        ignoreIdsRgba[i] = 0.f;

    const auto ignoreIdsLimit = std::min(GLBatchGeometryShader_maxIgnoreIds, ignoreIds.size());
    for (std::size_t i = 0u; i < ignoreIdsLimit; i++) {
        const auto ignoreId = ignoreIds[i];
        ignoreIdsRgba[i*4u+3u] = ((ignoreId>>24u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+2u] = ((ignoreId>>16u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+1u] = ((ignoreId>>8u)&0xFFu) / 255.f;
        ignoreIdsRgba[i*4u+0u] = (ignoreId&0xFFu) / 255.f;
    }

    glUniform4fv(shader.uIgnoreIds, GLBatchGeometryShader_maxIgnoreIds, ignoreIdsRgba);
    glUniform1f(shader.uLevelOfDetail, (float) levelOfDetail);

    glUniform4f(shader.uColor, r, g, b, a);

    glEnableVertexAttribArray(shader.a_vertexCoord0);
    glEnableVertexAttribArray(shader.a_vertexCoord1);
    glEnableVertexAttribArray(shader.a_color);
    glEnableVertexAttribArray(shader.a_normal);
    glEnableVertexAttribArray(shader.a_dir);
    if(shader.aId >= 0)
        glEnableVertexAttribArray(shader.aId);
    if(shader.aMinLevelOfDetail >= 0)
        glEnableVertexAttribArray(shader.aMinLevelOfDetail);
    if(shader.aMaxLevelOfDetail >= 0)
        glEnableVertexAttribArray(shader.aMaxLevelOfDetail);

    glVertexAttribDivisor(shader.a_normal, 0);
    glVertexAttribDivisor(shader.a_dir, 0);
    glVertexAttribDivisor(shader.a_pattern, 0);

    glVertexAttribDivisor(shader.a_vertexCoord0, 1);
    glVertexAttribDivisor(shader.a_vertexCoord1, 1);
    glVertexAttribDivisor(shader.a_color, 1);
    glVertexAttribDivisor(shader.a_factor, 1);
    glVertexAttribDivisor(shader.a_cap, 1);
    glVertexAttribDivisor(shader.a_halfStrokeWidth, 1);
    if(shader.aId >= 0)
        glVertexAttribDivisor(shader.aId, 1);
    if(shader.aMinLevelOfDetail >= 0)
        glVertexAttribDivisor(shader.aMinLevelOfDetail, 1);
    if(shader.aMaxLevelOfDetail >= 0)
        glVertexAttribDivisor(shader.aMaxLevelOfDetail, 1);

    // constant attribute values
    glDisableVertexAttribArray(shader.a_outlineWidth);
    glDisableVertexAttribArray(shader.a_outlineColor);
    glDisableVertexAttribArray(shader.a_halfStrokeWidth);
    glDisableVertexAttribArray(shader.a_factor);
    glDisableVertexAttribArray(shader.a_cap);
    glDisableVertexAttribArray(shader.a_pattern);


    glVertexAttrib1f(shader.a_outlineWidth, 0.f);
    glVertexAttrib4f(shader.a_outlineColor, 0.f, 0.f, 0.f, 0.f);
    glVertexAttrib1f(shader.a_halfStrokeWidth, 1.f);
    glVertexAttrib1f(shader.a_factor, 0.f);
    glVertexAttrib1f(shader.a_pattern, 0.f); // since a_factor == 0, this is ignored
    glVertexAttrib2f(shader.a_cap, 1.f, 1.f);

    // instance data
    glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
    ::glVertexAttribPointer(shader.a_normal, 1u, GL_UNSIGNED_SHORT, true, 4u, antialiasLineInstanceGeom);
    ::glVertexAttribPointer(shader.a_dir, 1u, GL_UNSIGNED_SHORT, true, 4u, &antialiasLineInstanceGeom[1u]);

    for (const auto &buffer : buf) {
        glBindBuffer(GL_ARRAY_BUFFER, buffer.primitive.vbo);
        // XXX - VAOs
        glVertexAttribPointer(shader.a_vertexCoord0, buffer.layout.vertex.points.position);
        glVertexAttribPointer(shader.a_vertexCoord1, buffer.layout.vertex.points.surfacePosition);
        if (drawForHitTest) {
            glVertexAttribPointer(shader.a_color, buffer.layout.vertex.points.id);
        } else {
            glVertexAttribPointer(shader.a_color, buffer.layout.vertex.points.color);
        }
        if(shader.aId >= 0)
            glVertexAttribPointer(shader.aId, buffer.layout.vertex.points.id);
        if(shader.aMinLevelOfDetail >= 0)
            glVertexAttribPointer(shader.aMinLevelOfDetail, buffer.layout.vertex.points.minLod);
        if(shader.aMaxLevelOfDetail >= 0)
            glVertexAttribPointer(shader.aMaxLevelOfDetail, buffer.layout.vertex.points.maxLod);
        glDrawArraysInstanced(GL_TRIANGLES, 0u, 6u, buffer.primitive.count);
    }

    glDisableVertexAttribArray(shader.a_vertexCoord0);
    glDisableVertexAttribArray(shader.a_vertexCoord1);
    glDisableVertexAttribArray(shader.a_color);
    glDisableVertexAttribArray(shader.a_normal);
    glDisableVertexAttribArray(shader.a_halfStrokeWidth);
    glDisableVertexAttribArray(shader.a_dir);
    glDisableVertexAttribArray(shader.a_pattern);
    glDisableVertexAttribArray(shader.a_factor);
    glDisableVertexAttribArray(shader.a_cap);
    if(shader.aId >= 0)
        glDisableVertexAttribArray(shader.aId);
    if(shader.aMinLevelOfDetail >= 0)
        glDisableVertexAttribArray(shader.aMinLevelOfDetail);
    if(shader.aMaxLevelOfDetail >= 0)
        glDisableVertexAttribArray(shader.aMaxLevelOfDetail);

    glVertexAttribDivisor(shader.a_normal, 0);
    glVertexAttribDivisor(shader.a_dir, 0);
    glVertexAttribDivisor(shader.a_vertexCoord0, 0);
    glVertexAttribDivisor(shader.a_vertexCoord1, 0);
    glVertexAttribDivisor(shader.a_color, 0);
    glVertexAttribDivisor(shader.a_halfStrokeWidth, 0);
    glVertexAttribDivisor(shader.a_pattern, 0);
    glVertexAttribDivisor(shader.a_factor, 0);
    glVertexAttribDivisor(shader.a_cap, 0);
    if(shader.aId >= 0)
        glVertexAttribDivisor(shader.aId, 0);
    if(shader.aMinLevelOfDetail >= 0)
        glVertexAttribDivisor(shader.aMinLevelOfDetail, 0);
    if(shader.aMaxLevelOfDetail >= 0)
        glVertexAttribDivisor(shader.aMaxLevelOfDetail, 0);

    glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
    glUseProgram(GL_NONE);

    return code;
}
void GLBatchGeometryRenderer4::start() NOTHROWS
{}
void GLBatchGeometryRenderer4::stop() NOTHROWS
{}
void GLBatchGeometryRenderer4::release() NOTHROWS
{
    markForRelease();

    if (!markedForRelease.empty()) {
        glDeleteBuffers((GLsizei)markedForRelease.size(), markedForRelease.data());
        markedForRelease.clear();
    }

    fbo.pixel.reset();
    fbo.tile.reset();
}

namespace
{
    // NOTE: this is an _extremely_ trimmed down version of the method from `GLGlobe`
    TAKErr intersectWithTerrainTileImpl(GeoPoint2 *value, const TerrainTile &tile, const MapSceneModel2 &scene, const float x, const float y) NOTHROWS
    {
        TAKErr code(TE_Ok);
        const int sceneSrid = scene.projection->getSpatialReferenceID();
        TAK::Engine::Elevation::ElevationChunk::Data node(tile.data);
        if (node.srid != sceneSrid) {
            // use GPU only path rather than CPU transforming the mesh
            if (!tile.data_proj.value || tile.data_proj.srid != sceneSrid)
                return TE_NotImplemented;
            node = tile.data_proj;
        }

        TAK::Engine::Math::Mesh mesh(node.value, &node.localFrame, (sceneSrid == 4978));
        return scene.inverse(value, Point2<float>(x, y), mesh);
    }
}

