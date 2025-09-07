#ifndef TAK_ENGINE_RENDERER_CORE_GLYPHATLAS2_H_INCLUDED
#define TAK_ENGINE_RENDERER_CORE_GLYPHATLAS2_H_INCLUDED

#include <string>

#include "port/String.h"
#include "renderer/Bitmap2.h"
#include "renderer/GLTextureAtlas2.h"
#include "renderer/GLText2.h"
#include "GlyphAtlas.h"

#include <unordered_map>
#include <vector>

namespace TAK {
    namespace Engine {
        namespace Renderer {
            namespace Core {
                class GLGlyphBatch2;
                class GLGlyphBatchFactory2;
            }

            class GLTextureAtlas2;

            namespace Core {

                class GLGlyphAtlas2 {

                public:

                    GLGlyphAtlas2(const TextFormatParams &params);

                private :
                    /**
                     * Add to position, texture coord and index buffers for a given set of UNICODE code points. This method will return 
                     * on the first unknown codepoint (given the atlas). This gives the calling code the chance to handle this. Usually
                     * by building another set of buffers for another atlas using the same GlyphCursor.
                     * 
                     * @param pos the x,y z positions
                     * @param uvs the u,v texture coords
                     * @param idxs the index buffer
                     * @param decor_pos the decor buffer
                     * @param cursor [in, out] the glyph cursor position to start and move from
                     * @param opts options for buffer creation
                     * @param codepoints the code points to add
                     * @param num_codepoints the number of codepoints from source to add
                     * 
                     * @return the number of codepoints added.
                     */
                    size_t fillBuffers(
                        std::vector<float>& pos,
                        std::vector<float>& uvs,
                        std::vector<uint16_t>* idxs,
                        std::vector<float>& decor_pos,
                        GlyphCursor& cursor,
                        const GlyphBuffersOpts& opts,
                        const uint32_t *codepoints, size_t num_codepoints, LabelData* labelData,
                        GLGlyphBatch2& batch) NOTHROWS;


                    void addGlyph(int glyph);
                public :
                    size_t measureCodepoints(
                        GlyphCursor& cursor,
                        const GlyphBuffersOpts& opts,
                        const uint32_t* codepoints, size_t num_codepoints) NOTHROWS;
                    
                    inline GlyphRenderMethod renderMethod() const NOTHROWS { return method_; }

                    inline double getDescender() const NOTHROWS {
                        return descender_;
                    }

                    inline double getLineHeight() const NOTHROWS {
                        return line_height_;
                    }
                private:

                    static size_t getStride_(const std::vector<float>& pos,
                        const std::vector<float>& uvs) NOTHROWS;

                    /**
                     * Horizontally align line.
                     */
                    void alignLine_(std::vector<float>* pos,
                        std::vector<float>* uvs,
                        std::vector<float>* decor_pos,
                        GlyphCursor& cursor,
                        const GlyphBuffersOpts& opts) NOTHROWS;

                    /**
                     * Adjust string horizontally to be positioned back at origin.
                     */
                    void alignString_(std::vector<float>* pos,
                        std::vector<float>* uvs,
                        std::vector<float>* decor_pos,
                        GlyphCursor& cursor,
                        const GlyphBuffersOpts& opts) NOTHROWS;

                    size_t fillBuffersOrMeasure_(
                        std::vector<float>* pos,
                        std::vector<float>* uvs,
                        std::vector<uint16_t>* idxs,
                        std::vector<float>* decor_pos,
                        GlyphCursor& cursor,
                        const GlyphBuffersOpts& opts,
                        const uint32_t* codepoints, size_t num_codepoints, LabelData* labelData, GLGlyphBatch2 *batch) NOTHROWS;

                    void addLineDecor_(GlyphCursor& cursor, std::vector<float>& decor_pos,
                        double x, double y, double z, double width, double height) NOTHROWS;

                    void finishDecor_(GlyphCursor& cursor, std::vector<float>& decor_pos,
                        const GlyphBuffersOpts& opts, bool finish_strike, bool finish_underline) NOTHROWS;

                private:
                    struct Glyph_ {
                        double advance;
                        float uv_left;
                        float uv_right;
                        float uv_bottom;
                        float uv_top;

                        // plane bounds
                        double left;
                        double right;
                        double bottom;
                        double top;

                        int64_t textureKey;
                    };

                    std::unordered_map<uint32_t, Glyph_> glyphs_;

                    double line_height_;
                    double ascender_;
                    double descender_;
                    double underline_y_;
                    double underline_thickness_;

                    GlyphRenderMethod method_;

                    TextFormatParams creationParams;
                    TextFormat2Ptr textFormat;
                    GLTextureAtlas2 textureAtlas;
                    const int kernelSize = 3;

                    friend class TAK::Engine::Renderer::Core::GLGlyphBatchFactory2;
                };

            }
        }
    }
}

#endif