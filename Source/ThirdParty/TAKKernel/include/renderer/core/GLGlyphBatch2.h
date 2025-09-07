#ifndef TAK_ENGINE_RENDERER_CORE_GLGLYPHBATCH_H_INCLUDED
#define TAK_ENGINE_RENDERER_CORE_GLGLYPHBATCH_H_INCLUDED

#include "math/Matrix2.h"
#include "renderer/GLTexture2.h"
#include "renderer/Shader.h"
#include "renderer/core/GLGlyphAtlas2.h"
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

                class GLGlyphBatchFactory2;
                class GLLabelManager;

                /**
                 * Represents static resources for drawing a batched set of glyphs that can reference multiple atlas textures
                 */
                class GLGlyphBatch2 {
                public:
                    GLGlyphBatch2() { };
                    TAK::Engine::Util::TAKErr draw(const TAK::Engine::Core::RenderContext& rc, const unsigned int glyphMask, const float mvp[16]) NOTHROWS;
                    void clearBatchedGlyphs() NOTHROWS;
                    Util::TAKErr batch(const int texId, float left, float right, float top, float bottom,
                        float uvleft, float uvright, float rvtop, float uvbottom, const GlyphCursor& cursor, LabelData const *labelData, 
                        const GLGlyphAtlas2 &atlas);
                private :
                    const GlyphShader* getGlyphProg(const TAK::Engine::Core::RenderContext& rc, GlyphRenderMethod method);
                private :
                    friend class GLGlyphBatchFactory2;
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
                class GLGlyphBatchFactory2 {
                public:
                    ~GLGlyphBatchFactory2() NOTHROWS;
                    TAK::Engine::Util::TAKErr batch(GLGlyphBatch2& glyphBatch, const char* utf8, const GlyphBuffersOpts& opts, GLText2& gltext) NOTHROWS;

                    /**
                     * Measure the string bounds.
                     */
                    TAK::Engine::Util::TAKErr measureStringBounds(
                        GlyphMeasurements* measurements,
                        const GlyphBuffersOpts& opts,
                        const char* utf8) NOTHROWS;

                    GLGlyphAtlas2& getOrCreateAtlas(const GlyphBuffersOpts& opts);

                private:
                    struct GlyphBuffersOptsComparator
                    {
                        bool operator () (const GlyphBuffersOpts& a, const GlyphBuffersOpts& b) const {
                            if (a.italic != b.italic)
                                return a.italic < b.italic;

                            if (a.bold != b.bold)
                                return a.bold < b.bold;

                            return String_less(a.fontName, b.fontName);

                        };
                    };
                    std::map<GlyphBuffersOpts, std::unique_ptr<GLGlyphAtlas2>, GlyphBuffersOptsComparator> atlases;
                    /** guards `atlases` */
                    mutable Thread::RWMutex mutex_;
                };
            }
        }
    }
}

#endif