#ifndef TAK_ENGINE_RENDERER_CORE_GLGLYPHBATCH2_H_INCLUDED
#define TAK_ENGINE_RENDERER_CORE_GLGLYPHBATCH2_H_INCLUDED

#include "math/Matrix2.h"
#include "renderer/GLTexture2.h"
#include "renderer/GLText2.h"
#include "renderer/Shader.h"
#include "renderer/core/GlyphAtlas.h"
#include "thread/RWMutex.h"


namespace TAK {
    namespace Engine {
        namespace Renderer {
            namespace Core {
                constexpr int LabelDataStride = 9;
                constexpr int VertexAttibSize = 14;

                struct GlyphShader {
                    GLint uEdgeSoftness;
                    GLint uRadius;
                    GLint uXrayPass;
                    GLint aTranslate;
                    GLint aAnchorF;
                    GLint aRotRadsFontSizeF;
                    GLint aXrayAlpha;
                    GLint aColor;
                    GLint aColorOutlineFloat;
                    GLint aBufferValsF;

                    std::shared_ptr<const Shader2> shader;
                };

                TAK::Engine::Util::TAKErr GlyphShader_create(std::shared_ptr<const GlyphShader>& shader, const TAK::Engine::Core::RenderContext& rc, GlyphRenderMethod method) NOTHROWS;
                TAK::Engine::Util::TAKErr GlyphShader_create(GlyphShader& shader, const TAK::Engine::Core::RenderContext& rc, GlyphRenderMethod method) NOTHROWS;

                class GLGlyphBatchFactory;
                class GLLabelManager;

                /**
                 * Represents static resources for drawing a batched set of glyphs that can reference multiple atlas textures
                 */
                //@deprecated use GLGlyphBatch2
                class GLGlyphBatch {
                public:
                    GLGlyphBatch() { };
                    TAK::Engine::Util::TAKErr draw(const TAK::Engine::Core::RenderContext& rc, const unsigned int glyphMask, const float mvp[16]) NOTHROWS;
                    void clearBatchedGlyphs() NOTHROWS;
                private :
                    TAK::Engine::Util::TAKErr drawLegacy(const TAK::Engine::Core::RenderContext& rc, const unsigned int glyphMask, const float proj[16]) NOTHROWS;
                    const GlyphShader* getGlyphProg(const TAK::Engine::Core::RenderContext& rc, GlyphRenderMethod method);
                private :
                    static void deleteTexture(TAK::Engine::Renderer::GLTexture2 *texture);
                private:
                    friend class GLGlyphBatchFactory;
                    friend class GLLabelManager;

                    std::vector<float> verts_;

                    struct Draw_ {
                        enum TargetLayer { Fill, Glyph, Decoration };

                        GlyphRenderMethod method;
                        TargetLayer targetLayer_;
                        GLuint texId_;
                        std::vector<uint16_t> idxs_;
                        // Group Draw_ by method
                        bool operator<(const Draw_& d) const {
                            if (targetLayer_ != d.targetLayer_)
                                return targetLayer_ < d.targetLayer_;
                            else
                                return method < d.method;
                        }
                    };

                    struct LegacyDraw_ {
                        unsigned int codepoint;
                        double x;
                        double y;
                        float packedColor;
                        float xrayAlpha;
                        GLText2& gltext;
                    };
                    std::vector<std::pair<TAK::Engine::Math::Matrix2, std::vector<LegacyDraw_>>> legacyDrawBatch_;

                    std::map<GLuint, Draw_> drawMap_;

                    struct GlyphBatchShaders {
                        std::shared_ptr<const GlyphShader> sdf_glyph_prog;
                        std::shared_ptr<const GlyphShader> msdf_glyph_prog;
                        std::shared_ptr<const GlyphShader> texture_glyph_prog;
                        std::shared_ptr<const GlyphShader> vector_glyph_prog;
                    };
                    std::map<const TAK::Engine::Core::RenderContext *, GlyphBatchShaders> shaders;

                    struct {
                        TAK::Engine::Thread::Mutex mutex;
                        std::map<const TAK::Engine::Core::RenderContext *, std::unique_ptr<TAK::Engine::Renderer::GLRenderBatch2>> value;
                    } spriteBatch;
                };

                struct GlyphMeasurements {
                    double min_x, min_y, min_z, max_x, max_y, max_z;
                    double descender;
                    double line_height;
                };

                /**
                 * Fills a GLGlyphBatch from given utf8 strings. A factory can be thought of as a "font" in a sense. It can contain multiple atlases that support
                 * different sets of code points and produces a single batch to support drawing a whole string of glyphs.
                 */
                //@deprecated use GLGlyphBatchFactory2
                class GLGlyphBatchFactory {
                public:
                    ~GLGlyphBatchFactory() NOTHROWS;
                    TAK::Engine::Util::TAKErr batch(GLGlyphBatch& glyphBatch, const char* utf8, const GlyphBuffersOpts& opts, GLText2& gltext) NOTHROWS;

                    /**
                     * Add an atlas, texture pair to the factory
                     * 
                     * @param atlas the atlas
                     * @param tex the texture containing the glyphs
                     */
                    /** @deprecated shared_ptr prevents assigning responsibility of releasing added resources */
                    TAK::Engine::Util::TAKErr addAtlas(const std::shared_ptr<GlyphAtlas>& atlas, const std::shared_ptr<GLTexture2>& tex) NOTHROWS;

                    /**
                     * Give an atlas, texture pair to the factory. The factory will release the resources upon destruction.
                     * 
                     * @param atlas the atlas
                     * @param tex the texture containing the glyphs
                     */
                    TAK::Engine::Util::TAKErr addAtlas(std::unique_ptr<GlyphAtlas> atlas, std::unique_ptr<GLTexture2> tex) NOTHROWS;

                    /**
                     * Get the number of attached atlases
                     */
                    size_t atlasCount() const NOTHROWS;

                    /**
                     * Measure the string bounds.
                     */
                    TAK::Engine::Util::TAKErr measureStringBounds(
                        GlyphMeasurements* measurements,
                        const GlyphBuffersOpts& opts,
                        const char* utf8,
                        const GLText2& gltext) NOTHROWS;

                    bool canRenderAllGlyphs(const GlyphBuffersOpts& opts, const char* utf8) NOTHROWS;

                private:
                    std::vector<GlyphAtlas*> getAtlasStack();
                    std::vector<GLTexture2*> getTextureStack();
                private:
                    std::vector<std::shared_ptr<GlyphAtlas>> atlas_stack_shared_;
                    std::vector<std::shared_ptr<GLTexture2>> tex_stack_shared_;
                    std::vector<std::unique_ptr<GlyphAtlas>> atlas_stack_unique_;
                    std::vector<std::unique_ptr<GLTexture2>> tex_stack_unique_;
                    /** guards `atlas_stack_` */
                    mutable Thread::RWMutex mutex_;
                };
            }
        }
    }
}

#endif