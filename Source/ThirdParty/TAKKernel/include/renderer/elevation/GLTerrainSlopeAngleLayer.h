#ifndef TAK_ENGINE_RENDERER_ELEVATION_GLTERRAINSLOPEANGLELAYER_H_INCLUDED
#define TAK_ENGINE_RENDERER_ELEVATION_GLTERRAINSLOPEANGLELAYER_H_INCLUDED

#include "elevation/TerrainSlopeAngleLayer.h"
#include "elevation/GradientControl.h"
#include "renderer/core/GLLayer2.h"
#include "renderer/core/GLLayerSpi2.h"
#include "thread/Mutex.h"

namespace TAK {
    namespace Engine {
        namespace Renderer {
            namespace Elevation {
                class ENGINE_API GLTerrainSlopeAngleLayer : public TAK::Engine::Renderer::Core::GLLayer2,
                                                            public TAK::Engine::Elevation::TerrainSlopeAngleLayer::SlopeAngleListener,
                                                            public TAK::Engine::Core::Layer2::VisibilityListener,
                                                            public TAK::Engine::Elevation::GradientControl
                {
                public :
                    GLTerrainSlopeAngleLayer(TAK::Engine::Elevation::TerrainSlopeAngleLayer &subject) NOTHROWS;
                    GLTerrainSlopeAngleLayer(TAK::Engine::Core::MapRenderer* ctx, TAK::Engine::Elevation::TerrainSlopeAngleLayer &subject) NOTHROWS;
                    ~GLTerrainSlopeAngleLayer() NOTHROWS;
                public: // GLLayer2
                    virtual TAK::Engine::Core::Layer2 &getSubject() NOTHROWS;
                public : // GLMapRenderable2
                    virtual void draw(const TAK::Engine::Renderer::Core::GLGlobeBase &view, const int renderPass) NOTHROWS;
                    virtual void release() NOTHROWS;
                    virtual int getRenderPass() NOTHROWS;
                    virtual void start() NOTHROWS;
                    virtual void stop() NOTHROWS;
                private :
                    void drawSlopeAngle(const TAK::Engine::Renderer::Core::GLGlobeBase &view) NOTHROWS;
                    void drawLegend(const TAK::Engine::Renderer::Core::GLGlobeBase &view) NOTHROWS;
                public : // TerrainSlopeAngleLayer::SlopeAngleListener
                    virtual Util::TAKErr onColorChanged(const TAK::Engine::Elevation::TerrainSlopeAngleLayer& subject, const float alpha) NOTHROWS;
                public : // Layer2::VisibilityListener
                    virtual Util::TAKErr layerVisibilityChanged(const TAK::Engine::Core::Layer2 &layer, const bool visible) NOTHROWS;
                public : // GradientControl
                    virtual Util::TAKErr getGradientColors(Port::Collection<uint32_t>& gradientColors) NOTHROWS;
                    virtual Util::TAKErr getLineItemStrings(Port::Collection<Port::String>& itemStrings) NOTHROWS;
                    virtual Util::TAKErr getMode(int* mode) NOTHROWS;
                    virtual Util::TAKErr setMode(int mode) NOTHROWS;
                private :
                    TAK::Engine::Core::MapRenderer* renderer_;
                    TAK::Engine::Elevation::TerrainSlopeAngleLayer &subject_;
                    float alpha_;
                    bool visible_;
                    bool legend_enabled_;
                    unsigned int texture_id_;
                    unsigned int legend_vbo_;
                };

                ENGINE_API TAK::Engine::Util::TAKErr GLTerrainSlopeAngleLayer_createSpi(Core::GLLayerSpi2Ptr& spi) NOTHROWS;
            }
        }
    }
}

#endif
