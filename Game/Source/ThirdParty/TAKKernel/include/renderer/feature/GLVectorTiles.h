#ifndef TAK_ENGINE_RENDERER_CORE_GLTILEDGLOBEDEMO_H
#define TAK_ENGINE_RENDERER_CORE_GLTILEDGLOBEDEMO_H

#include <map>

#include "core/RenderContext.h"
#include "feature/Envelope2.h"
#include "feature/StyleSheet.h"
#include "port/Platform.h"
#include "raster/tilematrix/TileClient.h"
#include "raster/tilematrix/TileContainer.h"
#include "raster/tilematrix/TileMatrix.h"
#include "renderer/GLTextureAtlas2.h"
#include "renderer/core/GLMapRenderable2.h"
#include "renderer/core/TiledGlobe.h"
#include "renderer/raster/TileCacheControl.h"
#include "util/Error.h"

namespace TAK {
    namespace Engine {
        namespace Renderer {
            namespace Core {
                class ENGINE_API GLVectorTiles : public GLMapRenderable2
                {
                private :
                    typedef TiledGlobe<std::shared_ptr<GLMapRenderable2>, std::vector<TAK::Engine::Feature::Envelope2>, bool> GLTiledGlobe;
                    class CacheUpdateForwarder;
                public :
                    GLVectorTiles(TAK::Engine::Core::RenderContext &context, const std::shared_ptr<TAK::Engine::Raster::TileMatrix::TileClient> &tiles, const bool overlay, const std::shared_ptr<TAK::Engine::Feature::StyleSheet> &stylesheet) NOTHROWS;
                    GLVectorTiles(TAK::Engine::Core::RenderContext &context, const std::shared_ptr<TAK::Engine::Raster::TileMatrix::TileContainer> &tiles, const bool overlay, const std::shared_ptr<TAK::Engine::Feature::StyleSheet> &stylesheet) NOTHROWS;
                private :
                    GLVectorTiles(TAK::Engine::Core::RenderContext &context, const std::shared_ptr<TAK::Engine::Raster::TileMatrix::TileMatrix> &tiles, const bool overlay, const std::shared_ptr<TAK::Engine::Feature::StyleSheet> &stylesheet) NOTHROWS;
                public :
                    void draw(const GLGlobeBase& view, const int renderPass) NOTHROWS override;
                    void release() NOTHROWS override;
                    int getRenderPass() NOTHROWS override;
                    void start() NOTHROWS override;
                    void stop() NOTHROWS override;
                public :
                    Util::TAKErr hitTest(Port::Collection<std::shared_ptr<const TAK::Engine::Feature::Feature2>> &features, const float screenX, const float screenY, const TAK::Engine::Core::GeoPoint2 &touch, const double resolution, const float radius, const std::size_t limit) NOTHROWS;
                public :
                    inline GLTiledGlobe &getTiles() NOTHROWS { return impl; }
                private :
                    GLTiledGlobe impl;
                    TAK::Engine::Core::RenderContext &context;
                    struct {
                        std::shared_ptr<TAK::Engine::Raster::TileMatrix::TileClient> client;
                        std::shared_ptr<TAK::Engine::Raster::TileMatrix::TileContainer> container;
                        std::shared_ptr<TAK::Engine::Raster::TileMatrix::TileMatrix> value;
                    } tiles;
                    std::size_t maxZoom {30u};
                    std::shared_ptr<TAK::Engine::Feature::StyleSheet> stylesheet;
                    const GLGlobeBase *view {nullptr};
                    std::unique_ptr<CacheUpdateForwarder> cacheUpdateForwarder;
                    std::shared_ptr<GLTextureAtlas2> spritesheet;
                    bool overlay;
                };

                class GLVectorTiles::CacheUpdateForwarder : public TAK::Engine::Renderer::Raster::TileCacheControl::OnTileUpdateListener
                {
                public :
                    CacheUpdateForwarder(GLVectorTiles &owner) NOTHROWS ;
                public:
                    void onTileUpdated(const std::size_t level, const std::size_t x, const std::size_t y) NOTHROWS;
                private :
                    GLVectorTiles &owner;
                };
            }
        }
    }
}

#endif