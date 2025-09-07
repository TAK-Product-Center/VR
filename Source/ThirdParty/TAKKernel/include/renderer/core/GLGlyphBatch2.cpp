#include "renderer/core/GLGlyphBatch2.h"

#include "thread/Mutex.h"
#include "thread/Lock.h"

#include <climits>
#include <iterator>

using namespace TAK::Engine::Renderer;
using namespace TAK::Engine::Renderer::Core;
using namespace TAK::Engine::Math;
using namespace TAK::Engine::Util;
using namespace TAK::Engine::Thread;

namespace {
    void insertQuad(std::vector<float>& verts, std::vector<uint16_t>& vertIdxs,
                    float x, float y, float z, float width, float height, const LabelData& labelData) NOTHROWS;


    // dst_count, src_count
    std::pair<size_t, size_t> decode_utf8(uint32_t* dst, const char* src, size_t dst_size) NOTHROWS;
    std::string encode_utf8(unsigned int cp);
}

#define DRAWS_DECORATION_ID -1
#define DRAWS_FILL_ID -2

namespace {
    Mutex& shadersMutex() NOTHROWS
    {
        static Mutex m;
        return m;
    }
}
TAKErr GLGlyphBatch2::batch(const int texId, float left, float right, float top, float bottom,
    float uv_left, float uv_right, float uv_top, float uv_bottom, const GlyphCursor& cursor,  LabelData const*  labelData, const GLGlyphAtlas2& atlas)
{
    TAKErr code = TE_Ok;

    std::size_t stride = 14;

    auto it = drawMap_.find(texId);
    if (it == drawMap_.end())
    {
        it = drawMap_.insert(std::pair<GLuint, GLGlyphBatch2::Draw_>(texId, GLGlyphBatch2::Draw_())).first;

        it->second.method = atlas.renderMethod();
        it->second.targetLayer_ = GLGlyphBatch2::Draw_::Glyph;
        it->second.texId_ = texId;
    }

    auto& drawMap = it->second;

    auto pos = &this->verts_;
    auto uvs = &this->verts_;
    auto idxs = &drawMap.idxs_;

    auto idx = static_cast<uint16_t>(pos->size() / stride);

    pos->push_back(static_cast<float>(left));
    pos->push_back(static_cast<float>(bottom));
    pos->push_back(static_cast<float>(cursor.z));
    uvs->push_back(uv_left);
    uvs->push_back(uv_bottom);
    labelData->insert(*pos);

    pos->push_back(static_cast<float>(left));
    pos->push_back(static_cast<float>(top));
    pos->push_back(static_cast<float>(cursor.z));
    uvs->push_back(uv_left);
    uvs->push_back(uv_top);
    labelData->insert(*pos);

    pos->push_back(static_cast<float>(right));
    pos->push_back(static_cast<float>(top));
    pos->push_back(static_cast<float>(cursor.z));
    uvs->push_back(uv_right);
    uvs->push_back(uv_top);
    labelData->insert(*pos);

    pos->push_back(static_cast<float>(right));
    pos->push_back(static_cast<float>(bottom));
    pos->push_back(static_cast<float>(cursor.z));
    uvs->push_back(uv_right);
    uvs->push_back(uv_bottom);
    labelData->insert(*pos);

    idxs->push_back(idx + 0);
    idxs->push_back(idx + 1);
    idxs->push_back(idx + 2);

    idxs->push_back(idx + 0);
    idxs->push_back(idx + 2);
    idxs->push_back(idx + 3);

    return code;
}


//
// GLGlyphBatch
//
const GlyphShader* GLGlyphBatch2::getGlyphProg(const TAK::Engine::Core::RenderContext& rc, GlyphRenderMethod method) {
    Lock lock(shadersMutex());
    GlyphBatchShaders &s = shaders[&rc];

    switch (method) {
    case GlyphRenderMethod_Texture: {
        if (!s.texture_glyph_prog)
            GlyphShader_create(s.texture_glyph_prog, rc, GlyphRenderMethod_Texture);
        return s.texture_glyph_prog.get();
    }

    case GlyphRenderMethod_SDF: {
        if (!s.sdf_glyph_prog)
            GlyphShader_create(s.sdf_glyph_prog, rc, GlyphRenderMethod_SDF);
        return s.sdf_glyph_prog.get();
    }
    case GlyphRenderMethod_MSDF: {
        if (!s.msdf_glyph_prog)
            GlyphShader_create(s.msdf_glyph_prog, rc, GlyphRenderMethod_MSDF);
        return s.msdf_glyph_prog.get();
    }
    case GlyphRenderMethod_Vector: {
        if (!s.vector_glyph_prog)
            GlyphShader_create(s.vector_glyph_prog, rc, GlyphRenderMethod_Vector);
        return s.vector_glyph_prog.get();
    }
    }

    return nullptr;
}

TAKErr GLGlyphBatch2::draw(const TAK::Engine::Core::RenderContext& rc, const unsigned int glyphMask, const float mvp[16]) NOTHROWS {
    const bool xrayPass = !!glyphMask;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    const GlyphShader* curr_prog = nullptr;
    GLuint curr_tex_id = 0;

    // Sort draws to ensure proper rendering order
    std::vector<Draw_> draws;
    for (auto& drawPair : drawMap_)
        draws.push_back(drawPair.second);
    std::sort(draws.begin(), draws.end());

    for (auto& draw : draws) {
        if (draw.idxs_.empty())
            continue;

        auto tex_id = draw.texId_;

        // switch programs
        const GlyphShader* draw_prog = getGlyphProg(rc, draw.method);
        if (!draw_prog)
            return TE_Err;

        if (curr_prog != draw_prog) {
            curr_prog = draw_prog;
            glUseProgram(curr_prog->shader->handle);
            glUniformMatrix4fv(curr_prog->shader->uMVP, 1, false, mvp);
        }

        // switch texture
        if (curr_tex_id != tex_id) {
            curr_tex_id = tex_id;
            if (tex_id != 0 && tex_id != DRAWS_FILL_ID && tex_id != DRAWS_DECORATION_ID) {
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, tex_id);
                glUniform1i(curr_prog->shader->uTexture, 0);
            } else {
                glBindTexture(GL_TEXTURE_2D, 0);
            }
        }

        // Wire up label data to a texture
        glUniform1i(curr_prog->uXrayPass, static_cast<GLint>(xrayPass ? 1 : 0));

        const GLint posSize = 3;
        const GLint uvSize = 2;
        const GLsizei vertexStride = (posSize + uvSize + LabelDataStride) * sizeof(float);

        // glEnableVertexAttribArray
        glEnableVertexAttribArray(curr_prog->shader->aVertexCoords);
        if (curr_prog->shader->aTexCoords != -1)
            glEnableVertexAttribArray(curr_prog->shader->aTexCoords);
        if (curr_prog->aTranslate != -1)
            glEnableVertexAttribArray(curr_prog->aTranslate);
        if (curr_prog->aAnchorF != -1)
            glEnableVertexAttribArray(curr_prog->aAnchorF);
        if (curr_prog->aRotRadsFontSizeF != -1)
            glEnableVertexAttribArray(curr_prog->aRotRadsFontSizeF);
        if (curr_prog->aXrayAlpha != -1)
            glEnableVertexAttribArray(curr_prog->aXrayAlpha);
        if (curr_prog->aColor != -1)
            glEnableVertexAttribArray(curr_prog->aColor);
        if (curr_prog->aColorOutlineFloat != -1)
            glEnableVertexAttribArray(curr_prog->aColorOutlineFloat);
        if (curr_prog->aBufferValsF != -1)
            glEnableVertexAttribArray(curr_prog->aBufferValsF);

        // glVertexAttribPointer
        const float* vertptr = this->verts_.data();
        glVertexAttribPointer(curr_prog->shader->aVertexCoords, posSize,
            GL_FLOAT, GL_FALSE, vertexStride, vertptr);
        if (curr_prog->shader->aTexCoords != -1)
            glVertexAttribPointer(curr_prog->shader->aTexCoords, uvSize, GL_FLOAT,
                                  false, vertexStride, vertptr + posSize);
        if (curr_prog->aTranslate != -1)
            glVertexAttribPointer(curr_prog->aTranslate, 3, GL_FLOAT,
                                   false, vertexStride, (void*)(vertptr + 7));
        if (curr_prog->aAnchorF != -1)
            glVertexAttribPointer(curr_prog->aAnchorF, 1, GL_FLOAT,
                                  false, vertexStride, (void*)(vertptr + 10));
        if (curr_prog->aRotRadsFontSizeF != -1)
            glVertexAttribPointer(curr_prog->aRotRadsFontSizeF, 1, GL_FLOAT,
                                  false, vertexStride, (void*)(vertptr + 11));
        if (curr_prog->aXrayAlpha != -1)
            glVertexAttribPointer(curr_prog->aXrayAlpha, 1, GL_FLOAT,
                                  false, vertexStride, (void*)(vertptr + 13));
        if (curr_prog->aColor != -1)
            glVertexAttribPointer(curr_prog->aColor, 1, GL_FLOAT,
                                  false, vertexStride, (void*)(vertptr + 5));
        if (curr_prog->aColorOutlineFloat != -1)
            glVertexAttribPointer(curr_prog->aColorOutlineFloat, 1, GL_FLOAT,
                                  false, vertexStride, (void*)(vertptr + 6));
        if (curr_prog->aBufferValsF != -1)
            glVertexAttribPointer(curr_prog->aBufferValsF, 1, GL_FLOAT,
                                  false, vertexStride, (void*)(vertptr + 12));

        // Set uniforms
        if (draw.method == GlyphRenderMethod_Vector) {
            // Give background fills rounded corners & antialiased edges
            float edgeSoftness = draw.targetLayer_ == Draw_::Fill ? 0.1f : 0.0f;
            float radius = draw.targetLayer_ == Draw_::Fill ? .2f : 0.0f;
            glUniform1f(curr_prog->uEdgeSoftness, edgeSoftness);
            glUniform1f(curr_prog->uRadius, radius);
        }

        // main text
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(draw.idxs_.size()),
                       GL_UNSIGNED_SHORT, draw.idxs_.data());

        // glDisableVertexAttribArray
        glDisableVertexAttribArray(curr_prog->shader->aVertexCoords);
        if (curr_prog->shader->aTexCoords != -1)
            glDisableVertexAttribArray(curr_prog->shader->aTexCoords);
        if (curr_prog->aTranslate != -1)
            glDisableVertexAttribArray(curr_prog->aTranslate);
        if (curr_prog->aAnchorF != -1)
            glDisableVertexAttribArray(curr_prog->aAnchorF);
        if (curr_prog->aRotRadsFontSizeF != -1)
            glDisableVertexAttribArray(curr_prog->aRotRadsFontSizeF);
        if (curr_prog->aXrayAlpha != -1)
            glDisableVertexAttribArray(curr_prog->aXrayAlpha);
        if (curr_prog->aColor != -1)
            glDisableVertexAttribArray(curr_prog->aColor);
        if (curr_prog->aColorOutlineFloat != -1)
            glDisableVertexAttribArray(curr_prog->aColorOutlineFloat);
        if (curr_prog->aBufferValsF != -1)
            glDisableVertexAttribArray(curr_prog->aBufferValsF);

    }

    glUseProgram(GL_NONE);
    glDisable(GL_BLEND);

    return TE_Ok;
}

//
// GLGlyphBatchFactory
//
GLGlyphBatchFactory2::~GLGlyphBatchFactory2() NOTHROWS
{
}

TAKErr GLGlyphBatchFactory2::batch(GLGlyphBatch2& glyphBatch, const char* utf8, const GlyphBuffersOpts& opts, GLText2& gltext) NOTHROWS {
    ReadLock rlock(mutex_);
    std::vector<float> decor_buf;

    auto atlas = &getOrCreateAtlas(opts);

    // A buffer of 0.5 seems to produce an appropriate visual weight.
    float text_buffer = 0.5f;
    // Add 0.05 for each additional weight unit. Limit buffer to be between 0.5 and 0.1.
    float outline_buffer = std::max(0.5f - (opts.outline_weight * 0.05f), 0.1f);
    LabelData labelData(opts.text_color_red, opts.text_color_green,
                                          opts.text_color_blue, opts.text_color_alpha,
                                          opts.outline_color_red, opts.outline_color_green,
                                          opts.outline_color_blue, opts.outline_color_alpha,
                                          opts.renderX, opts.renderY, opts.renderZ,
                                            opts.anchorX - opts.renderX,
                                            opts.anchorY - opts.renderY, opts.rotation,
                                          opts.font_size, text_buffer, outline_buffer,
                                          opts.xray_alpha);

    GlyphCursor cursor;

    uint32_t codepoints[256];
        
    const char* cp = utf8;
    while (*cp) {

        auto decode_counts = decode_utf8(codepoints, cp, sizeof(codepoints) / sizeof(uint32_t));
        size_t dst_count = decode_counts.first;
        size_t src_count = decode_counts.second;
        size_t codepoint_index = 0;

        while (codepoint_index < dst_count) {

            size_t pre_atlas_codepoint_index = codepoint_index;

            size_t startingSize = glyphBatch.verts_.size() / VertexAttibSize;
            size_t fill_count = atlas->fillBuffers(glyphBatch.verts_, glyphBatch.verts_, nullptr, decor_buf,
                cursor, opts, codepoints + codepoint_index, dst_count - codepoint_index, &labelData, glyphBatch);
            size_t endingSize = glyphBatch.verts_.size() / VertexAttibSize;

            codepoint_index += fill_count;
            if (codepoint_index == dst_count)
                break;

        }
        cp += src_count;
    }

    // has line decorations?
    if (!decor_buf.empty()) {
        auto it = glyphBatch.drawMap_.find(DRAWS_DECORATION_ID);
        if (it == glyphBatch.drawMap_.end()) {
            it = glyphBatch.drawMap_.insert(std::pair<GLuint, GLGlyphBatch2::Draw_>(DRAWS_DECORATION_ID,
                                                           GLGlyphBatch2::Draw_())).first;
            it->second.method = GlyphRenderMethod_Vector;
            it->second.targetLayer_ = GLGlyphBatch2::Draw_::Decoration;
            it->second.texId_ = DRAWS_DECORATION_ID;
        }

        for (size_t i = 0; i < decor_buf.size(); i += 5) {
            float renderX = opts.renderX + (decor_buf[i + 0] * opts.font_size);
            float renderY = opts.renderY + (decor_buf[i + 1] * opts.font_size);
            float renderZ = opts.renderZ + (decor_buf[i + 2] * opts.font_size);
            float width = decor_buf[i + 3];
            float height = decor_buf[i + 4];
            LabelData decorLabelData(opts.text_color_red, opts.text_color_green,
                                                   opts.text_color_blue, opts.text_color_alpha,
                                                   opts.outline_color_red, opts.outline_color_green,
                                                   opts.outline_color_blue, opts.outline_color_alpha,
                                                   renderX, renderY, renderZ,
                                                   opts.anchorX - renderX,
                                                   opts.anchorY - renderY,
                                                   opts.rotation, opts.font_size, text_buffer,
                                                   outline_buffer, opts.xray_alpha);
            insertQuad(glyphBatch.verts_, it->second.idxs_, 0, 0, 0, width, height, decorLabelData);
        }
    }

    // Has fill?
    if (opts.fill) {
        auto it = glyphBatch.drawMap_.find(DRAWS_FILL_ID);
        if (it == glyphBatch.drawMap_.end()) {
            it = glyphBatch.drawMap_.insert(std::pair<GLuint, GLGlyphBatch2::Draw_>(DRAWS_FILL_ID,
                                                                                    GLGlyphBatch2::Draw_())).first;
            it->second.method = GlyphRenderMethod_Vector;
            it->second.targetLayer_ = GLGlyphBatch2::Draw_::Fill;
            it->second.texId_ = DRAWS_FILL_ID;
        }

        float renderX = opts.renderX + static_cast<float>(cursor.min_x * opts.font_size);
        float renderY = opts.renderY + static_cast<float>(cursor.min_y * opts.font_size);
        float renderZ = opts.renderZ + static_cast<float>(cursor.min_z * opts.font_size);
        LabelData fillLabelData(opts.back_color_red, opts.back_color_green,
                                              opts.back_color_blue, opts.back_color_alpha,
                                              0.f, 0.f, 0.f, 0.f,
                                              renderX, renderY, renderZ,
                                              opts.anchorX - renderX,
                                              opts.anchorY - renderY,
                                              opts.rotation, opts.font_size, 0.f, 0.f,
                                              opts.xray_alpha);
        auto width = static_cast<float>(cursor.max_x - cursor.min_x);
        auto height = static_cast<float>(cursor.max_y - cursor.min_y);

        insertQuad(glyphBatch.verts_, it->second.idxs_, 0, 0, 0, width, height, fillLabelData);
    }

    return TE_Ok;
}

GLGlyphAtlas2& GLGlyphBatchFactory2::getOrCreateAtlas(const GlyphBuffersOpts& opts)
{
    auto atlasit = atlases.find(opts);
    if (atlasit == atlases.end())
    {
        TextFormatParams params(opts.fontName, 24);

        params.bold = opts.bold;
        params.italic = opts.italic;

        atlases[opts] = std::unique_ptr<GLGlyphAtlas2>(new GLGlyphAtlas2(params));
        atlasit = atlases.find(opts);
        atlasit->second->method_ = GlyphRenderMethod_MSDF;

    }
    return *atlasit->second;
}

TAK::Engine::Util::TAKErr GLGlyphBatchFactory2::measureStringBounds(GlyphMeasurements* measurements, const GlyphBuffersOpts& opts, 
    const char* utf8) NOTHROWS {

    ReadLock rlock(mutex_);
    GlyphCursor cursor;

    uint32_t codepoints[256];
    double descender = 0.0;
    double line_height = 0.0;

    const char* cp = utf8;
    while (*cp) {

        auto decode_counts = decode_utf8(codepoints, cp, sizeof(codepoints) / sizeof(uint32_t));
        size_t dst_count = decode_counts.first;
        size_t src_count = decode_counts.second;
        size_t codepoint_index = 0;

        while (codepoint_index < dst_count) {


            size_t pre_atlas_codepoint_index = codepoint_index;
            auto atlas = &getOrCreateAtlas(opts);

            size_t measure_count = atlas->measureCodepoints(cursor, opts,
                codepoints + codepoint_index, dst_count - codepoint_index);

            codepoint_index += measure_count;

            if (measure_count) {
                descender = std::min(descender, atlas->getDescender());
                line_height = std::max(line_height, atlas->getLineHeight());
            }
        }
        cp += src_count;
    }

    if (measurements) {
        measurements->min_x = cursor.min_x;
        measurements->max_x = cursor.max_x;
        measurements->min_y = cursor.min_y;
        measurements->max_y = cursor.max_y;
        measurements->min_z = cursor.min_z;
        measurements->max_z = cursor.max_z;
        measurements->descender = descender;
        measurements->line_height = line_height;
    }

    return TE_Ok;

}

void GLGlyphBatch2::clearBatchedGlyphs() NOTHROWS {
    this->verts_.clear();
    this->drawMap_.clear();
}

namespace {

    void insertQuad(std::vector<float>& verts, std::vector<uint16_t>& vertIdxs,
                    float x, float y, float z, float width, float height, const LabelData& labelData) NOTHROWS {
        size_t idx = verts.size() / VertexAttibSize;

        verts.push_back(x);
        verts.push_back(y);
        verts.push_back(z);
        verts.push_back(width);
        verts.push_back(height);
        labelData.insert(verts);

        verts.push_back(x);
        verts.push_back(y + height);
        verts.push_back(z);
        verts.push_back(width);
        verts.push_back(height);
        labelData.insert(verts);

        verts.push_back(x + width);
        verts.push_back(y + height);
        verts.push_back(z);
        verts.push_back(width);
        verts.push_back(height);
        labelData.insert(verts);

        verts.push_back(x + width);
        verts.push_back(y);
        verts.push_back(z);
        verts.push_back(width);
        verts.push_back(height);
        labelData.insert(verts);

        vertIdxs.emplace_back(static_cast<uint16_t>(idx + 0));
        vertIdxs.emplace_back(static_cast<uint16_t>(idx + 1));
        vertIdxs.emplace_back(static_cast<uint16_t>(idx + 2));
        vertIdxs.emplace_back(static_cast<uint16_t>(idx + 0));
        vertIdxs.emplace_back(static_cast<uint16_t>(idx + 3));
        vertIdxs.emplace_back(static_cast<uint16_t>(idx + 2));
    }

    size_t read_cp_bits(uint32_t &cp, const char* src, size_t expect) NOTHROWS {

        size_t i = 0;
        uint32_t bits = cp;

        while (src[i] && expect) {

            uint32_t b = *reinterpret_cast<const uint8_t*>(src + i);
            
            // unexpected
            if ((b & 0xc0) != 0x80) {
                break;
            }

            bits = (bits << 6) | (b & 0x3f);

            ++i;
            --expect;
        }

        cp = bits;
        return i;
    }

    // dst_count, src_count
    std::pair<size_t, size_t> decode_utf8(uint32_t* dst, const char* src, size_t dst_size) NOTHROWS {

        size_t src_i = 0;
        size_t dst_i = 0;

        while (src[src_i] && dst_i < dst_size) {
            
            uint32_t bits = *reinterpret_cast<const uint8_t*>(src + src_i);
            if (!(bits & 0x80)) {
                dst[dst_i++] = bits;
                src_i++;
            } else {
                size_t expect = 0;

                if ((bits & 0xf8) == 0xf0) { // length 4
                    bits = bits & 0x7;
                    expect = 3;
                } else if ((bits & 0xf0) == 0xe0) { // length 3
                    bits = bits & 0xf;
                    expect = 2;
                } else if ((bits & 0xe0) == 0xc0) { // length 2
                    bits = bits & 0x1f;
                    expect = 1;
                }

                // make sure we have enough
                size_t found = read_cp_bits(bits, src + src_i + 1, expect);
                if (found != expect) {
                    // malformed UTF8. Try and continue, but don't trust code point value.
                    bits = 0xffffffff;
                }

                dst[dst_i++] = bits;
                src_i += 1 + found;
            }
        }

        // null terminate. This is needed to trigger the end of the string in fillBuffers
        if (!src[src_i] && dst_i < dst_size) {
            dst[dst_i++] = 0;
        }

        return std::make_pair(dst_i, src_i);
    }

    std::string encode_utf8(unsigned int cp)
    {
        char c[5]={ 0x00,0x00,0x00,0x00,0x00 };
        if     (cp<=0x7F) { c[0] = cp;  }
        else if(cp<=0x7FF) { c[0] = (cp>>6)+192; c[1] = (cp&63)+128; }
        else if(0xd800<=cp && cp<=0xdfff) {} //invalid block of utf8
        else if(cp<=0xFFFF) { c[0] = (cp>>12)+224; c[1]= ((cp>>6)&63)+128; c[2]=(cp&63)+128; }
        else if(cp<=0x10FFFF) { c[0] = (cp>>18)+240; c[1] = ((cp>>12)&63)+128; c[2] = ((cp>>6)&63)+128; c[3]=(cp&63)+128; }
        return std::string(c);
    }
}