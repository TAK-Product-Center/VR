#ifdef MSVC
#include "renderer/GLLinesEmulation.h"

#include <cinttypes>
#include <cmath>
#include <cstdlib>

#include "renderer/GL.h"
#include "renderer/RenderContextAssociatedCache.h"
#include "renderer/feature/GLBatchGeometryShaders.h"
#include "util/MemBuffer2.h"

using namespace atakmap::renderer;

using namespace TAK::Engine::Util;
using namespace TAK::Engine::Renderer::Feature;

#define MAX_INDEX_VALUE 0xFFFFu
#define VERTEX_SIZE 28u

namespace
{
    // 4 vertices per quad; xyz0 + xyz1 + normal dir
    uint8_t vertsBuffer[MAX_INDEX_VALUE*VERTEX_SIZE];

    template<class V, class I, class VertexFetch>
    void emulateLineDrawImpl(GLES20FixedPipeline &gl, const ArrayPointer &pointer, float width, int mode, int count, const I *srcIndices, const VertexFetch vf) NOTHROWS;

    template<class V, class I>
    struct ArraysVertexFetcher
    {
        ArraysVertexFetcher(const std::size_t first_) : first(first_) {}

        void operator()(const V **a, const V **b, const I *indices, const std::size_t segmentIdx, const std::size_t segStride, const ArrayPointer &verts) const NOTHROWS
        {
            const std::size_t aidx = segmentIdx*segStride + first;
            const std::size_t bidx = aidx+1u;
            *a = reinterpret_cast<const V*>(static_cast<const uint8_t*>(verts.pointer) + aidx*verts.stride);
            *b = reinterpret_cast<const V*>(static_cast<const uint8_t*>(verts.pointer) + bidx*verts.stride);
        }

        std::size_t first;
    };
    template<class V, class I>
    struct ElementsVertexFetcher
    {
        void operator()(const V **a, const V **b, const I *indices, const std::size_t segmentIdx, const std::size_t segStride, const ArrayPointer &verts) const NOTHROWS
        {
            const std::size_t aidx = segmentIdx*segStride;
            const std::size_t bidx = aidx+1u;
            *a = reinterpret_cast<const V*>(static_cast<const uint8_t*>(verts.pointer) + indices[aidx]*verts.stride);
            *b = reinterpret_cast<const V*>(static_cast<const uint8_t*>(verts.pointer) + indices[bidx]*verts.stride);
        }
    };
}

GLLinesEmulation::GLLinesEmulation()
{}

GLLinesEmulation::~GLLinesEmulation()
{}

void GLLinesEmulation::emulateLineDrawArrays(const int mode, const int first, const int count, GLES20FixedPipeline *pipeline, const float width, const ArrayPointer *vertexPointer, const ArrayPointer *texCoordsPointer)
{
    if (vertexPointer && !texCoordsPointer)
    {
        switch (vertexPointer->type) {
#define CASE_DEF(l, t) \
    case l :  \
    { \
        ArraysVertexFetcher<t, uint8_t> vertexFetcher((std::size_t)first); \
        emulateLineDrawImpl<t, uint8_t, ArraysVertexFetcher<t, uint8_t>>(*pipeline, *vertexPointer, width, mode, count, nullptr, vertexFetcher); \
        break; \
    }
            CASE_DEF(GL_UNSIGNED_BYTE, uint8_t)
                CASE_DEF(GL_BYTE, int8_t)
                CASE_DEF(GL_UNSIGNED_SHORT, unsigned short)
                CASE_DEF(GL_SHORT, short)
                CASE_DEF(GL_UNSIGNED_INT, unsigned int)
                CASE_DEF(GL_INT, int)
                CASE_DEF(GL_FLOAT, float)
#undef CASE_DEF
        }
    }
}

void GLLinesEmulation::emulateLineDrawArrays(const int mode, const int first, const int count, const float *proj, const float *modelView, const float *texture, const float r, const float g, const float b, const float a, const float width, const ArrayPointer *vertexPointer, const ArrayPointer *texCoordsPointer)
{
}

void GLLinesEmulation::emulateLineDrawElements(const int mode, const int count, const int type, const void *indices, GLES20FixedPipeline *pipeline, const float width, const ArrayPointer *vertexPointer, const ArrayPointer *texCoordsPointer)
{
    switch (vertexPointer->type) {
#define IDX_CASE_DEF(l, tv, ti) \
    case l : \
    { \
        ElementsVertexFetcher<tv, ti> vertexFetcher; \
        emulateLineDrawImpl<tv, ti, ElementsVertexFetcher<tv, ti>>(*pipeline, *vertexPointer, width, mode, count, reinterpret_cast<const ti *>(indices), vertexFetcher); \
    } \
    break;
#define VTX_CASE_DEF(l, t) \
    case l :  \
        { \
        switch(type) \
                    { \
        IDX_CASE_DEF(GL_UNSIGNED_BYTE, t, uint8_t) \
        IDX_CASE_DEF(GL_UNSIGNED_SHORT, t, unsigned short) \
        IDX_CASE_DEF(GL_UNSIGNED_INT, t, unsigned int) \
                    } \
        } \
    break;

        VTX_CASE_DEF(GL_UNSIGNED_BYTE, uint8_t)
            VTX_CASE_DEF(GL_BYTE, int8_t)
            VTX_CASE_DEF(GL_UNSIGNED_SHORT, unsigned short)
            VTX_CASE_DEF(GL_SHORT, short)
            VTX_CASE_DEF(GL_UNSIGNED_INT, unsigned int)
            VTX_CASE_DEF(GL_INT, int)
            VTX_CASE_DEF(GL_FLOAT, float)
#undef VTX_CASE_DEF
#undef IDX_CASE_DEF
    }
}

namespace
{
    template<class V, class I, class VertexFetch>
    void emulateLineDrawImpl(GLES20FixedPipeline &gl, const ArrayPointer &pointer_, float width, int mode, int count, const I *srcIndices, const VertexFetch vf) NOTHROWS
    {
        using namespace atakmap::renderer;

        // need at least 2 points for a line
        if (count < 2)
            return;

        // instance geometry
        constexpr uint16_t instanceGeom[12] =
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

        ArrayPointer pointer(pointer_);
        if (!pointer.stride)
            pointer.stride = sizeof(V)*pointer.size;

        MemBuffer2 pVertsBuffer(vertsBuffer, MAX_INDEX_VALUE*VERTEX_SIZE);

        // init program
        TAK::Engine::Core::RenderContext* renderContext = nullptr;
        TAK::Engine::Core::RenderContext_getCurrent(&renderContext);
        auto prog = GLBatchGeometryShaders_getAntiAliasedLinesShader(*renderContext);

        glUseProgram(prog.base.handle);

        // MVP
        {
            // projection
            float matrixF[48u];

            gl.readMatrix(GLES20FixedPipeline::MatrixMode::MM_GL_PROJECTION, matrixF);
            gl.readMatrix(GLES20FixedPipeline::MatrixMode::MM_GL_MODELVIEW, matrixF+16u);
            atakmap::renderer::GLMatrix::multiply(matrixF + 32u, matrixF, matrixF + 16u);
            glUniformMatrix4fv(prog.u_mvp, 1u, false, matrixF+32u);
        }
        // viewport size
        {
            GLint viewport[4];
            glGetIntegerv(GL_VIEWPORT, viewport);
            glUniform2f(prog.u_viewportSize, (float)viewport[2] / 2.0f, (float)viewport[3] / 2.0f);
        }

        float color[4u];
        gl.getColor(color);

        glUniform1i(prog.u_hitTest, 0);

        glEnableVertexAttribArray(prog.a_vertexCoord0);
        glEnableVertexAttribArray(prog.a_vertexCoord1);
        glEnableVertexAttribArray(prog.a_normal);
        glEnableVertexAttribArray(prog.a_pattern);
        glEnableVertexAttribArray(prog.a_dir);
        glEnableVertexAttribArray(prog.a_cap);
        // constant attribute values
        glDisableVertexAttribArray(prog.a_factor);
        glDisableVertexAttribArray(prog.a_color);
        glDisableVertexAttribArray(prog.a_halfStrokeWidth);
        glDisableVertexAttribArray(prog.a_outlineWidth);
        glDisableVertexAttribArray(prog.a_outlineColor);

        // NOTE: `pattern` and `factor` cannot be constant attribute values as `glVertexAttrib`
        // only supports float attributes, not int

        glVertexAttribDivisor(prog.a_normal, 0);
        glVertexAttribDivisor(prog.a_dir, 0);

        glVertexAttribDivisor(prog.a_vertexCoord0, 1);
        glVertexAttribDivisor(prog.a_vertexCoord1, 1);
        glVertexAttribDivisor(prog.a_pattern, 1);
        glVertexAttribDivisor(prog.a_cap, 1);

        glVertexAttribPointer(prog.a_normal, 1u, GL_UNSIGNED_SHORT, true, 4u, instanceGeom);
        glVertexAttribPointer(prog.a_dir, 1u, GL_UNSIGNED_SHORT, true, 4u, &instanceGeom[1u]);

        glVertexAttribPointer(prog.a_vertexCoord0, pointer.size, GL_FLOAT, false, VERTEX_SIZE, vertsBuffer);
        glVertexAttribPointer(prog.a_vertexCoord1, pointer.size, GL_FLOAT, false, VERTEX_SIZE, vertsBuffer+12u);
        glVertexAttribIPointer(prog.a_pattern, 1u, GL_UNSIGNED_SHORT, VERTEX_SIZE, vertsBuffer+24u);
        glVertexAttribPointer(prog.a_cap, 2u, GL_BYTE, false, VERTEX_SIZE, vertsBuffer+26u);
        // constant attribute values
        glVertexAttrib1f(prog.a_halfStrokeWidth, width/2.f);
        glVertexAttrib4f(prog.a_color, color[0], color[1], color[2], color[3]);
        glVertexAttrib1f(prog.a_factor, 1.f);
        glVertexAttrib1f(prog.a_outlineWidth, 0.f);
        glVertexAttrib4f(prog.a_outlineColor, 0.f, 0.f, 0.f, 0.f);

        const bool loop = (mode == GL_LINE_LOOP);
        size_t pointerStep;
        size_t numSegments;
        switch (mode) {
        case GL_LINES:
            pointerStep = 2;
            numSegments = count / 2;
            break;
        case GL_LINE_STRIP:
        case GL_LINE_LOOP:
            pointerStep = 1;
            numSegments = count - 1;
            break;
        default:
            return;
        }
        
        GLboolean depthWriteEnabled;
        glGetBooleanv(GL_DEPTH_WRITEMASK, &depthWriteEnabled);

        auto aaline_vert = [&](const V* aXYZ, const V* bXYZ, const int8_t acap, const int8_t bcap)
        {
            float faXYZ[3] = { (float)aXYZ[0], (float)aXYZ[1], (float)aXYZ[pointer.size-1u] };
            float fbXYZ[3] = { (float)bXYZ[0], (float)bXYZ[1], (float)bXYZ[pointer.size-1u] };
            pVertsBuffer.put<float>(faXYZ, 3); // [0, 4, 8] : 12
            pVertsBuffer.put<float>(fbXYZ, 3); // [12, 16, 20] : 24
            pVertsBuffer.put<uint16_t>(0xFFFFu); // [24] : 26
            pVertsBuffer.put<int8_t>(acap); // [26] : 28
            pVertsBuffer.put<int8_t>(bcap);
        };

        auto flushLinesBuffer = [&](const bool doubleDraw)
        {
            glDrawArraysInstanced(GL_TRIANGLES, 0, 6u, (GLsizei)(pVertsBuffer.position() / VERTEX_SIZE));
            if (!doubleDraw)
            {
                // turn off depth writes
                if(depthWriteEnabled)
                    glDepthMask(GL_FALSE);
                // turn off cap/join vertex attribute
                glDisableVertexAttribArray(prog.a_cap);
                // enable joins on all segments
                glVertexAttrib2f(prog.a_cap, 1.f, 1.f);
                // draw lines
                glDrawArraysInstanced(GL_TRIANGLES, 0, 6u, (GLsizei)(pVertsBuffer.position() / VERTEX_SIZE));
                // re-enable cap/join vertex attribute
                glEnableVertexAttribArray(prog.a_cap);
                // restore depth writes
                if(depthWriteEnabled)
                    glDepthMask(GL_TRUE);
            }
            pVertsBuffer.reset();
        };

        const std::size_t capSegmentIdx = loop ? numSegments : numSegments - 1u;
        // if depth test is enabled, specify _no cap_ per vertex attribute to avoid issues with
        // alpha and depth test
        const bool depthEnabled = glIsEnabled(GL_DEPTH_TEST);
        const int8_t acap = (depthEnabled && numSegments > 1) ? 0 : 1;
        for (size_t i = 0; i < numSegments; i++) {
            if (pVertsBuffer.remaining() < VERTEX_SIZE)
                flushLinesBuffer(acap);

            const V *a = nullptr;
            const V *b = nullptr;
            vf(&a, &b, srcIndices, i, pointerStep, pointer);

            const int8_t bcap =
                ((mode == GL_LINES) || // cap if lines
                 (i == capSegmentIdx)) ?  // cap if last segment
                1 : -1;

            aaline_vert(a, b, acap, bcap*acap);
        }

        // close the loop if there are more than 2 points
        if (loop && count > 2) {
            if (pVertsBuffer.remaining() < VERTEX_SIZE)
                flushLinesBuffer(acap);

            const V *a = nullptr;
            const V *scratch = nullptr;
            const V* b = nullptr;
            vf(&scratch, &a, srcIndices, (numSegments-1u), pointerStep, pointer);
            vf(&b, &scratch, srcIndices, 0u, pointerStep, pointer);

            aaline_vert(a, b, acap, acap);
        }

        // flush anything remaining
        if (pVertsBuffer.position())
            flushLinesBuffer(acap);

        glDisableVertexAttribArray(prog.a_vertexCoord0);
        glDisableVertexAttribArray(prog.a_vertexCoord1);
        glDisableVertexAttribArray(prog.a_color);
        glDisableVertexAttribArray(prog.a_normal);
        glDisableVertexAttribArray(prog.a_halfStrokeWidth);
        glDisableVertexAttribArray(prog.a_dir);
        glDisableVertexAttribArray(prog.a_pattern);
        glDisableVertexAttribArray(prog.a_factor);
        glDisableVertexAttribArray(prog.a_cap);

        glVertexAttribDivisor(prog.a_normal, 0);
        glVertexAttribDivisor(prog.a_dir, 0);
        glVertexAttribDivisor(prog.a_vertexCoord0, 0);
        glVertexAttribDivisor(prog.a_vertexCoord1, 0);
        glVertexAttribDivisor(prog.a_pattern, 0);
        glVertexAttribDivisor(prog.a_factor, 0);
        glVertexAttribDivisor(prog.a_cap, 0);

        glUseProgram(GL_NONE);
    }
}
#endif
