#ifndef TAK_ENGINE_RENDERER_FEATURE_GLBATCHGEOMETRYSHADERS_H_INCLUDED
#define TAK_ENGINE_RENDERER_FEATURE_GLBATCHGEOMETRYSHADERS_H_INCLUDED

#include "renderer/Shader.h"
#include "util/Error.h"

namespace TAK {
    namespace Engine {
        namespace Renderer {
            namespace Feature {
                constexpr std::size_t GLBatchGeometryShader_maxIgnoreIds = 128u;

                struct ENGINE_API LinesShader
                {
                    GLuint handle{ GL_NONE };
                    GLint u_mvp{ -1 };
                    GLint u_color{ -1 };
                    GLint a_vertexCoords{ -1 };
                    GLint a_color{ -1 };
                };
                struct ENGINE_API AntiAliasedLinesShader
                {
                    Renderer::Shader2 base;
                    GLint u_mvp{ -1 };
                    GLint u_viewportSize{ -1 };
                    GLint uIgnoreIds{ -1 };
                    GLint u_hitTest{ -1 };
                    GLint uLevelOfDetail{ -1 };
                    GLint uHitTestRadius{ -1 };
                    GLint uColor{ -1 };
                    GLint a_vertexCoord0{ -1 };
                    GLint a_vertexCoord1{ -1 };
                    GLint a_texCoord{ -1 };
                    GLint a_color{ -1 };
                    GLint a_outlineColor{ -1 };
                    GLint a_normal{ -1 };
                    GLint a_halfStrokeWidth{ -1 };
                    GLint a_outlineWidth{ -1 };
                    GLint a_dir{ -1 };
                    GLint a_pattern{ -1 };
                    GLint a_factor{ -1 };
                    GLint a_cap{ -1 };
                    GLint aId{ -1 };
                    GLint aMinLevelOfDetail{ -1 };
                    GLint aMaxLevelOfDetail{ -1 };
                    GLint aOffset{ -1 };
                };
                struct ENGINE_API ArrowLinesShader
                {
                    GLuint handle{GL_NONE};
                    GLint u_mvp{ -1 };
                    GLint u_viewportSize{ -1 };
                    GLint uIgnoreIds{ -1 };
                    GLint uColor{ -1 };
                    GLint uLevelOfDetail{ -1 };
                    GLint a_vertexCoord0{ -1 };
                    GLint a_vertexCoord1{ -1 };
                    GLint a_color{ -1 };
                    GLint a_outlineColor{ -1 };
                    GLint a_position{ -1 };
                    GLint a_radius{ -1 };
                    GLint a_outlineWidth{ -1 };
                    GLint aId{ -1 };
                    GLint aMinLevelOfDetail{ -1 };
                    GLint aMaxLevelOfDetail{ -1 };
                    GLint aOffset{ -1 };
                };
                struct ENGINE_API PolygonsShader
                {
                    //Renderer::Shader2 base;
                    GLuint handle{ GL_NONE };
                    GLint uColor{ -1 };
                    GLint uIgnoreIds{ -1 };
                    GLint uLevelOfDetail{ -1 };
                    GLint uLightingFactor{-1 };
                    GLint aPosition{ -1 };
                    GLint aOutlineWidth{ -1 };
                    GLint aExteriorVertex{ -1 };
                    GLint u_mvp{ -1 };
                    GLint a_color{ -1 };
                    GLint uViewport{ -1 };
                    GLint aId{ -1 };
                    GLint aMinLevelOfDetail{ -1 };
                    GLint aMaxLevelOfDetail{ -1 };
                    GLint aOffset{ -1 };
                };
                struct ENGINE_API StrokedPolygonsShader
                {
                    Renderer::Shader2 base;
                    GLint u_mvp{ -1 };
                    GLint a_fillColor{ -1 };
                    GLint a_strokeColor{ -1 };
                    GLint a_strokeWidth{ -1 };
                    GLint a_edges{ -1 };
                    GLint aOffset{ -1 };
                };
                struct ENGINE_API PointsShader
                {
                    GLuint handle{ GL_NONE };
                    GLint uMVP{ -1 };
                    GLint uTexture{ -1 };
                    GLint uColor{ -1 };
                    GLint uMapRotation{ -1 };
                    GLint uCameraRtc{ -1 };
                    GLint uWcsScale{ -1 };
                    GLint uTanHalfFov{ -1 };
                    GLint uViewportWidth{ -1 };
                    GLint uViewportHeight{ -1 };
                    GLint uDrawTilt{ -1 };
                    GLint uIgnoreIds{ -1 };
                    GLint uHitTestRadius{ -1 };
                    GLint uClampToSurface{ -1 };
                    GLint uLevelOfDetail{ -1 };
                    GLint aRotation{ -1 };
                    GLint spriteBottomLeft{ -1 };
                    GLint spriteDimensions{ -1 };
                    GLint aVertexCoords{ -1 };
                    GLint aSurfaceVertexCoords{ -1 };
                    GLint aPointSize{ -1 };
                    GLint aColor{ -1 };
                    GLint aId{ -1 };
                    GLint aAbsoluteRotationFlag{ -1 };
                    GLint aMinLevelOfDetail{ -1 };
                    GLint aMaxLevelOfDetail{ -1 };
                    GLint aOffset{ -1 };
                };
                struct ENGINE_API MeshesShader
                {
                    GLuint handle{ GL_NONE };
                    GLint uMvp{ -1 };
                    GLint uIgnoreIds{ -1 };
                    GLint uLevelOfDetail{ -1 };
                    GLint uTexture{ -1 };
                    GLint uColor{ -1 };
                    GLint uLightingFactor{-1 };
                    GLint aPosition{ -1 };
                    GLint aTexPos{ -1 };
                    GLint aVertColor{ -1 };
                    GLint aNormals{ -1 };
                    GLint aVertexCoord{ -1 };
                    GLint aSpriteBottomLeft{ -1 };
                    GLint aSpriteTopRight{ -1 };
                    GLint aColor{ -1 };
                    GLint aTransform{-1 };
                    GLint aId{ -1 };
                    GLint aMinLevelOfDetail{ -1 };
                    GLint aMaxLevelOfDetail{ -1 };
                };

                struct GLBatchGeometryShaderOptions
                {
                    std::size_t ignoreIdsCount{ 0u };
                    bool enableDisplayThresholds{ false };
                    bool enableHitTestRadius{ false };
                    bool enablePixelOffset { false };
                    bool enablePolygonLighting {false};
                };

                ENGINE_API LinesShader GLBatchGeometryShaders_getLinesShader(const TAK::Engine::Core::RenderContext& ctx, const GLBatchGeometryShaderOptions &opts = GLBatchGeometryShaderOptions()) NOTHROWS;
                ENGINE_API AntiAliasedLinesShader GLBatchGeometryShaders_getAntiAliasedLinesShader(const TAK::Engine::Core::RenderContext& ctx, const GLBatchGeometryShaderOptions &opts = GLBatchGeometryShaderOptions()) NOTHROWS;
                ENGINE_API ArrowLinesShader GLBatchGeometryShaders_getArrowLinesShader(const TAK::Engine::Core::RenderContext& ctx, const GLBatchGeometryShaderOptions &opts = GLBatchGeometryShaderOptions()) NOTHROWS;
                ENGINE_API PolygonsShader GLBatchGeometryShaders_getPolygonsShader(const TAK::Engine::Core::RenderContext& ctx, const GLBatchGeometryShaderOptions &opts = GLBatchGeometryShaderOptions()) NOTHROWS;
                ENGINE_API StrokedPolygonsShader GLBatchGeometryShaders_getStrokedPolygonsShader(const TAK::Engine::Core::RenderContext& ctx, const GLBatchGeometryShaderOptions &opts = GLBatchGeometryShaderOptions()) NOTHROWS;
                ENGINE_API PointsShader GLBatchGeometryShaders_getPointsShader(const TAK::Engine::Core::RenderContext& ctx, const GLBatchGeometryShaderOptions &opts = GLBatchGeometryShaderOptions()) NOTHROWS;
                ENGINE_API MeshesShader GLBatchGeometryShaders_getMeshesShader(const TAK::Engine::Core::RenderContext& ctx, const GLBatchGeometryShaderOptions &opts = GLBatchGeometryShaderOptions()) NOTHROWS;
            }
        }
    }
}

#endif // TAK_ENGINE_RENDERER_FEATURE_GLBATCHGEOMETRYRENDERER4_H_INCLUDED

