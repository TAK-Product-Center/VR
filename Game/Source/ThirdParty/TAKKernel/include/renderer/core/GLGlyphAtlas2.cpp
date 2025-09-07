#include "renderer/core/GLGlyphAtlas2.h"

#include "port/StringBuilder.h"
#include "renderer/BitmapFactory2.h"
#include "util/DataInput2.h"
#include "util/MathUtils.h"
#include "util/Memory.h"
#include "util/ProtocolHandler.h"
#include "renderer/core/GLGlyphBatch2.h"
#include <renderer/Bitmap2.h>
#include <climits>
#include "util/ConfigOptions.h"


using namespace TAK::Engine::Renderer::Core;
using namespace TAK::Engine::Renderer;
using namespace TAK::Engine::Util;
using namespace TAK::Engine::Port;

namespace {

    //rendering implementation expects a fairly large buffer region around the text
    constexpr auto glyphBuffer = (int)1;

    //anti-aliasing is done with some smooth-step like method, 
    // perform an approximate inverse to make a linear distance to the edge
    float inverse_smoothstep(float x) {
        x = std::abs(x);
        if (x == .5f || x >= 1.f || x == 0)
            return x;

        float p = x > .5 ? x - .5f : .5f - x;
        p *= 2.f;

        if (x > .5f)
            return (p * p / 2.f) + .5f;
        else
            return -(p * p / 2.f) + .5f;
    }

    //compute the approximate distance from [pixelX, pixelY] to the nearest edge, with a given bitmap
    //hasOutline gives whether the rendered glyph contains a black outline around the rendered glyph
    float sdfPixelDistance(uint8_t* data, int width, int height, int pixelSize, int pixelX, int pixelY, const float maxDistance, bool hasOutline)
    {
        auto signedPixel = [data, width, height, pixelSize, hasOutline](int x, int y)
            {
                if (x < 0 || x > width - 1 || y < 0 || y > height - 1)
                    return hasOutline ? -1.f : 0;

                auto p = (float)data[(y * width + x) * pixelSize + 0] / 255.f;
                auto a = (float)data[(y * width + x) * pixelSize + 3] / 255.f;
                bool inside = a == 1.f;
                if (!hasOutline)
                {
                    p = a;
                }
                else if (!inside)
                {
                    p = -(1.0f - a);
                }

                if (p > .9f)
                    p = 1.f;
                else if (p < -.9)
                    p = -1.f;
                else if (p > -.1f && p < .1f)
                    p = 0;

                return p;
            };

        float centerValue = signedPixel(pixelX, pixelY);

        float distance = maxDistance;

        //half filled pixel assumed to be centered on edge
        if ((hasOutline && centerValue != 1.0f && centerValue != -1.0f) || (!hasOutline && centerValue != 0 && centerValue != 1.0))
        {
            distance = inverse_smoothstep(std::abs(centerValue));
        }

        //kernel size
        const int kernelSize = 3;
        if (centerValue == 1.0f || centerValue == -1.0f || distance == 1.f || (!hasOutline && centerValue == 0))
        {
            for (int x = std::max(pixelX - kernelSize, 0); x < std::min(pixelX + kernelSize + 1, width); x++)
                for (int y = std::max(pixelY - kernelSize, 0); y < std::min(pixelY + kernelSize + 1, height); y++)
                {
                    if (x == pixelX && y == pixelY)
                        continue;
                    float p = (float)signedPixel(x, y);

                    if (centerValue == p)
                        continue;

                    float distx = (float)abs(pixelX - x);
                    float disty = (float)abs(pixelY - y);

                    float signedAdj = 0;

                    if (std::signbit(centerValue) && p == 0)
                        continue;

                    if ((hasOutline && std::signbit(p) == std::signbit(centerValue)) || (!hasOutline && centerValue != 0))
                    {
                        signedAdj = inverse_smoothstep(p);
                    }
                    else
                    {
                        signedAdj = -inverse_smoothstep(p);
                    }

                    if (distx != 0)
                        distx += signedAdj;

                    if (disty != 0)
                        disty += signedAdj;
                    distance = std::min(distance, sqrtf(float(distx * distx + disty * disty)));
                }
        }
        if (centerValue <= 0)
            distance *= -1.f;

        return distance;
    }

//compute the sdf value pixel at the given location
uint8_t sdfPixel(BitmapPtr& bitmap, int w, int h, int pixelSize, int x, int y, bool hasOutline)
{
    const float maxDistance = 100.f;
    auto f = sdfPixelDistance(bitmap->getData(), (int)w, (int)h, (int)pixelSize, x, y, maxDistance, hasOutline);

    const float gamma = 11;
    const float edgeOffset = -2;

    //convert pixel value from [-1, 1] to [0, 255]
    f *= gamma;

    f += 127.f;

    f += edgeOffset;

    f = std::min(f, 255.f);
    f = std::max(f, 0.f);

    uint8_t d = (uint8_t)f;
    return d;
}

//create a bitmap contiaining the SDF glyph
void renderSDFGlyph(BitmapPtr& dest, int buffer, BitmapPtr& src)
{
    size_t pixelSize;
    Bitmap2_formatPixelSize(&pixelSize, src->getFormat());

    int w = (int)src->getWidth();
    int h = (int)src->getHeight();

    //Slightly different algorithm if the glyph contains a black outline or not
    bool hasOutline = false;
    for (int y = 0; y < h ; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            int index = (y* w + x) * (int)pixelSize;
            if (src->getData()[index + 2] == 0 && src->getData()[index + 3] == 255)
            {
                hasOutline = true;
                break;
            }
        }
        if (hasOutline) break;
    }
    for (int y = -buffer; y < h + buffer; ++y)
    {
        for (int x = -buffer; x < w + buffer; ++x)
        {
            int destW = (int)dest->getWidth();
            int destH = (int)dest->getHeight();

            auto sdf = sdfPixel(src, w, h, (int)pixelSize, x, y, hasOutline);
            int destIndex = ((y + buffer) * destW + x + buffer) * (int)pixelSize;

            dest->getData()[destIndex] = sdf;
            dest->getData()[destIndex + 1] = sdf;
            dest->getData()[destIndex + 2] = sdf;
            dest->getData()[destIndex + 3] = 255;
        }
    }
}

    bool isSkipControlChar(int cp) NOTHROWS;
    bool isNewLineControlChar(int cp) NOTHROWS;
    TAKErr openPathOrUri(DataInput2Ptr& value, const char* pathOrUri) NOTHROWS;
}

namespace {
    uint32_t packColor(float r, float g, float b, float a) {
        return (((unsigned int)(r * 0xFFu) << 24u) & 0xFF000000u) |
            (((unsigned int)(g * 0xFFu) << 16u) & 0xFF0000u) |
            (((unsigned int)(b * 0xFFu) << 8u) & 0xFF00u) |
            (((unsigned int)(a * 0xFFu)) & 0xFFu);
    }

    uint32_t packHalfInts(int32_t i1, int32_t i2) {
        i1 = atakmap::math::clamp(i1, SHRT_MIN, SHRT_MAX) + 32767;
        i2 = atakmap::math::clamp(i2, SHRT_MIN, SHRT_MAX) + 32767;
        auto ui1 = reinterpret_cast<uint32_t&>(i1);
        auto ui2 = reinterpret_cast<uint32_t&>(i2);
        return (ui1 << 16) | ui2 & 0xFFFFu;
    }

    uint32_t packFloats(float f1, int decPlaces1, float f2, int decPlaces2) {
        auto i1 = static_cast<int32_t>(f1 * (decPlaces1 * 10.0));
        auto i2 = static_cast<int32_t>(f2 * (decPlaces2 * 10.0));
        return packHalfInts(i1, i2);
    }
}

GLGlyphAtlas2::GLGlyphAtlas2(const TextFormatParams& params) : 
    textureAtlas(512), creationParams(params), textFormat(nullptr, nullptr),
    line_height_(1.14990234375), ascender_(0.9052734375),descender_(- 0.2119140625),
    underline_y_( - 0.142578125),underline_thickness_( 0.0732421875),
    method_(GlyphRenderMethod_MSDF)
{
    //same size as in GlyphAtlas
    creationParams.size = 32.f;
    creationParams.outline = true;

    //WinTAK uses GDI+ which is creating font 33% larger than java.
    //Use default-font-size, only set by WinTAK, to determine the size for WinTAK.
    Port::String opt;
    auto code = ConfigOptions_getOption(opt, "default-font-size");
    if (code == TE_Ok) {
        auto defaultSize = (float)atof(opt) * 3.f / 2.f;
        creationParams.size = std::max(defaultSize, creationParams.size);
    }
#ifndef __ANDROID__
    if (TAK::Engine::Port::String_equal(creationParams.fontName, "Courier"))
        creationParams.fontName = "Courier New";
#endif
    TextFormat2_createTextFormat(textFormat, this->creationParams);

    descender_ = textFormat->getDescent() / creationParams.size;
    line_height_ = textFormat->getBaselineSpacing() / creationParams.size;
}

size_t GLGlyphAtlas2::fillBuffers(std::vector<float>& pos, std::vector<float>& uvs, std::vector<uint16_t>* idxs,
    std::vector<float>& decor_pos, GlyphCursor& cursor, const GlyphBuffersOpts& opts,
    const uint32_t* codepoints, size_t num_codepoints, LabelData* labelData, GLGlyphBatch2 &batch) NOTHROWS {

    return this->fillBuffersOrMeasure_(&pos, &uvs, idxs, &decor_pos, cursor, opts, codepoints, num_codepoints, labelData, &batch);
}

size_t GLGlyphAtlas2::measureCodepoints(
    GlyphCursor& cursor,
    const GlyphBuffersOpts& opts,
    const uint32_t* codepoints, size_t num_codepoints) NOTHROWS {

    return this->fillBuffersOrMeasure_(nullptr, nullptr, nullptr, nullptr, cursor, opts, codepoints, num_codepoints, nullptr, nullptr);
}

//add a glyph to the texture atlas
void GLGlyphAtlas2::addGlyph(int unicode)
{
    BitmapPtr src(nullptr, nullptr);
    textFormat->loadGlyph(src, unicode);


    BitmapPtr dest(new Bitmap2(src->getWidth() + glyphBuffer * 2, src->getHeight() + glyphBuffer * 2, src->getFormat()), Memory_deleter_const<Bitmap2>);

    renderSDFGlyph(dest, glyphBuffer, src);

    char uri[5];
    uri[4] = '\0';
    memcpy(uri, &unicode, 4);

    int64_t key;
    textureAtlas.addImage(&key, uri, *dest);

    atakmap::math::Rectangle<float> uvrect;
    textureAtlas.getImageRect(&uvrect, key, true);

    atakmap::math::Rectangle<float> rect;
    textureAtlas.getImageRect(&rect, key, false);

    const auto glyphGeneratorSize = (float)(creationParams.size + 0.25);

    Glyph_ glyph;
    glyph.advance = ((float)src->getWidth()) / glyphGeneratorSize;

    glyph.uv_bottom = uvrect.y + uvrect.height;
    glyph.uv_top = uvrect.y;
    glyph.uv_left = uvrect.x;
    glyph.uv_right = uvrect.x + uvrect.width;

    glyph.bottom = 0.f;
    glyph.top = (rect.height) / glyphGeneratorSize;
    glyph.left = -.43f;
    glyph.right = -.43f + (rect.width) / glyphGeneratorSize;

    glyph.textureKey = key;

    glyphs_[unicode] = glyph;

}
size_t GLGlyphAtlas2::fillBuffersOrMeasure_(std::vector<float>*pos, std::vector<float>*uvs, std::vector<uint16_t>*idxs,
    std::vector<float>* decor_pos, GlyphCursor & cursor, const GlyphBuffersOpts & opts,
    const uint32_t * codepoints, size_t num_codepoints, LabelData* labelData, GLGlyphBatch2 *batch) NOTHROWS {

    const uint32_t *cp = codepoints;
    size_t num_processed = 0;

    bool break_signal = false;

    const bool is_building = pos && uvs && batch;

    while (num_codepoints && !break_signal) {

        int current_cp = *cp++;

        // just ended a line (or string)?
        if (cursor.end_of_line || cursor.end_of_string) {
            cursor.kerning_cp = 0;
            cursor.line_min_x = cursor.x_origin;
            cursor.line_max_x = cursor.x_origin;
            cursor.line_min_y = cursor.y;
            cursor.line_max_y = cursor.y;
            cursor.advance = 0.0;
            cursor.line_add_count = 0;
            cursor.line_decor_add_count = 0;
        }

        // just ended a string?
        if (cursor.end_of_string) {
            cursor.string_min_x = cursor.x_origin;
            cursor.string_max_x = cursor.x_origin;
            cursor.string_min_y = cursor.y_origin;
            cursor.string_max_y = cursor.y_origin;
            cursor.string_add_count = 0;
            cursor.string_decor_add_count = 0;
        }

        cursor.end_of_string = false;
        cursor.end_of_line = false;

        if (isNewLineControlChar(current_cp)) {

            if (is_building)
                finishDecor_(cursor, *decor_pos, opts, true, true);

            alignLine_(pos, uvs, decor_pos, cursor, opts);

            // move cursor
            cursor.x = cursor.x_origin;
            cursor.y -= this->line_height_;
            
            // set signals
            cursor.end_of_line = true;
            break_signal = opts.break_on_end_of_line;

        } else if (current_cp == 0) {

            if (is_building)
                finishDecor_(cursor, *decor_pos, opts, true, true);

            alignLine_(pos, uvs, decor_pos, cursor, opts);
            alignString_(pos, uvs, decor_pos, cursor, opts);

            // set signals
            cursor.end_of_string = true;
            break_signal = opts.break_on_end_of_string;

        } else if (!isSkipControlChar(current_cp)) {

            auto it = this->glyphs_.find(current_cp);
            if (it == this->glyphs_.end())
            {
                addGlyph(current_cp);
                it = this->glyphs_.find(current_cp);
                if (it == this->glyphs_.end())
                    break;
            }

            uint16_t idx = 0;
            if (is_building)
                idx = static_cast<uint16_t>(pos->size() / getStride_(*pos, *uvs));// (idxs->size() / 6) * 4);

            if (UINT16_MAX - idx < 4)
                break;

            // advance cursor X
            cursor.x += cursor.advance;

            double left = cursor.x;
            double right = cursor.x;
            double bottom = cursor.y;
            double top = cursor.y;

            left = cursor.x + it->second.left;
            right = cursor.x + it->second.right;
            bottom = cursor.y + it->second.bottom;
            top = cursor.y + it->second.top;

            if (is_building) {
                int id;
                textureAtlas.getTexId(&id, it->second.textureKey);
                batch->batch(id, static_cast<float>(left), static_cast<float>(right), static_cast<float>(top), static_cast<float>(bottom), 
                    it->second.uv_left, it->second.uv_right, it->second.uv_top, it->second.uv_bottom, cursor, labelData, *this);
            }

            cursor.line_add_count++;
            cursor.string_add_count++;

            // current line metrics
            cursor.line_min_x = std::min(cursor.line_min_x, left);
            cursor.line_max_x = std::max(cursor.line_max_x, right);
            cursor.line_min_y = std::min(cursor.line_min_y, bottom);
            cursor.line_max_y = std::max(cursor.line_max_y, top);

            // advance info
            cursor.kerning_cp = it->first;
            cursor.advance = it->second.advance;

            // change in underline?
            if (cursor.underlining != opts.underline) {

                if (!cursor.underlining) {
                    cursor.underline_begin_x = cursor.x;
                }
                else if (is_building) {
                    finishDecor_(cursor, *decor_pos, opts, false, true);
                }

                cursor.underlining = opts.underline;
            }

            // change in strokethrough?
            if (cursor.striking != opts.strikethrough) {

                if (!cursor.striking) {
                    cursor.strike_begin_x = cursor.x;
                }
                else if (is_building) {
                    finishDecor_(cursor, *decor_pos, opts, true, false);
                }

                cursor.striking = opts.strikethrough;
            }
        }

        --num_codepoints;
        ++num_processed;
    }

    return num_processed;
}

void GLGlyphAtlas2::finishDecor_(GlyphCursor& cursor, std::vector<float>& decor_pos,
    const GlyphBuffersOpts& opts, bool finish_strike, bool finish_underline) NOTHROWS {

    // end underline and strike
    if (cursor.underlining && finish_underline) {
        
        double underline_height = underline_thickness_;

        addLineDecor_(cursor, decor_pos, cursor.underline_begin_x, cursor.y - underline_height,
                cursor.z, cursor.line_max_x - cursor.underline_begin_x - cursor.advance, underline_height);
    }
    if (cursor.striking && finish_strike) {

        double strike_height = 0.06;
        double y = (cursor.line_max_y + cursor.line_min_y - strike_height) / 2.0;

        addLineDecor_(cursor, decor_pos, cursor.strike_begin_x, y, cursor.z,
                      cursor.line_max_x - cursor.strike_begin_x - cursor.advance, strike_height);
    }
}

void GLGlyphAtlas2::alignLine_(std::vector<float>* pos,
    std::vector<float>* uvs,
    std::vector<float>* decor_pos,
    GlyphCursor& cursor,
    const GlyphBuffersOpts& opts) NOTHROWS {

    // x offset to align as desired
    float align_offset = 0.f;
    auto line_width = static_cast<float>(cursor.line_max_x - cursor.line_min_x);
    switch (opts.h_alignment) {
    case GlyphHAlignment_Left: align_offset = static_cast<float>(cursor.line_min_x); break;
    case GlyphHAlignment_Center: align_offset = static_cast<float>(cursor.line_min_x + (line_width / 2.0)); break;
    case GlyphHAlignment_Right: align_offset = static_cast<float>(cursor.line_min_x + line_width); break;
    }

    if (pos && uvs) {
        const size_t stride = getStride_(*pos, *uvs);

        size_t glyph_step = stride * 4;

        for (size_t c = cursor.line_add_count, i = pos->size() - glyph_step; c > 0; --c, i -= glyph_step) {
            (*pos)[i] -= align_offset;
            (*pos)[i + stride] -= align_offset;
            (*pos)[i + 2 * stride] -= align_offset;
            (*pos)[i + 3 * stride] -= align_offset;
        }
    }

    if (decor_pos) {
        size_t glyph_step = 5;

        for (size_t c = cursor.line_decor_add_count, i = decor_pos->size() - glyph_step; c > 0; --c, i -= glyph_step) {
            (*decor_pos)[i] -= align_offset;
        }
    }

    // adjust min/max x
    cursor.line_min_x -= align_offset;
    cursor.line_max_x -= align_offset;

    // update string metrics
    cursor.string_min_x = std::min(cursor.line_min_x, cursor.string_min_x);
    cursor.string_max_x = std::max(cursor.line_max_x, cursor.string_max_x);
    cursor.string_min_y = std::min(cursor.line_min_y, cursor.string_min_y);
    cursor.string_max_y = std::max(cursor.line_max_y, cursor.string_max_y);
}

size_t GLGlyphAtlas2::getStride_(const std::vector<float>& pos,
    const std::vector<float>& uvs) NOTHROWS {
    size_t stride = 12;
    // uvs buffer same as pos buffer?
    if (&uvs == &pos) {
        stride += 2;
    }
    return stride;
}

void GLGlyphAtlas2::alignString_(std::vector<float>* pos,
    std::vector<float>* uvs,
    std::vector<float>* decor_pos,
    GlyphCursor& cursor,
    const GlyphBuffersOpts& opts) NOTHROWS {

    float align_offset = 0.f;
    auto string_width = static_cast<float>(cursor.string_max_x - cursor.string_min_x);
    switch (opts.h_alignment) {
    case GlyphHAlignment_Left: align_offset = 0.f; break;
    case GlyphHAlignment_Center: align_offset = static_cast<float>(string_width / 2.0); break;
    case GlyphHAlignment_Right: align_offset = static_cast<float>(string_width); break;
    }

    if (pos && uvs) {
        const size_t stride = getStride_(*pos, *uvs);

        size_t glyph_step = stride * 4;

        for (size_t c = cursor.string_add_count, i = pos->size() - glyph_step; c > 0; --c, i -= glyph_step) {
            (*pos)[i] += align_offset;
            (*pos)[i + stride] += align_offset;
            (*pos)[i + 2 * stride] += align_offset;
            (*pos)[i + 3 * stride] += align_offset;
        }
    }

    if (decor_pos) {
        size_t glyph_step = 5;

        for (size_t c = cursor.string_decor_add_count, i = decor_pos->size() - glyph_step; c > 0; --c, i -= glyph_step) {
            (*decor_pos)[i] += align_offset;
        }
    }

    cursor.string_min_x += align_offset;
    cursor.string_max_x += align_offset;

    // update total metrics
    cursor.min_x = std::min(cursor.min_x, cursor.string_min_x);
    cursor.max_x = std::max(cursor.max_x, cursor.string_max_x);
    cursor.min_y = std::min(cursor.min_y, cursor.string_min_y);
    cursor.max_y = std::max(cursor.max_y, cursor.string_max_y);
    cursor.min_z = std::min(cursor.min_z, cursor.z);
    cursor.max_z = std::max(cursor.max_z, cursor.z);
}

void GLGlyphAtlas2::addLineDecor_(GlyphCursor& cursor, std::vector<float>& decor_pos, double x, double y,
                               double z, double width, double height) NOTHROWS {
    decor_pos.push_back(static_cast<float>(x));
    decor_pos.push_back(static_cast<float>(y));
    decor_pos.push_back(static_cast<float>(z));
    decor_pos.push_back(static_cast<float>(width));
    decor_pos.push_back(static_cast<float>(height));

    cursor.line_decor_add_count++;
    cursor.string_decor_add_count++;
}

namespace {

    bool isSkipControlChar(int cp) NOTHROWS {
        switch (cp) {
        case '\r':
            //TODO-- add more, bell, etc.
            return true;
        }

        return false;
    }

    bool isNewLineControlChar(int cp) NOTHROWS {
        return cp == '\n';
    }

}
