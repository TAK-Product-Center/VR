#include "renderer/feature/GLBatchGeometryShaders.h"

#include <cassert>
#include <map>
#include <sstream>

#include "renderer/GLSLUtil.h"
#include "thread/Lock.h"
#include "thread/Mutex.h"
#include "util/ConfigOptions.h"

using namespace TAK::Engine::Renderer::Feature;

using namespace TAK::Engine::Core;
using namespace TAK::Engine::Renderer;
using namespace TAK::Engine::Thread;
using namespace TAK::Engine::Util;

namespace
{
    const char *POINT_VSH =
    #include "renderer/feature/BatchGeometryPoints.vert"
    ;
    const char *POINT_FSH =
    #include "renderer/feature/BatchGeometryPoints.frag"
    ;
    const char *LINE_VSH =
    #include "renderer/feature/BatchGeometryAntiAliasedLines.vert"
    ;
    const char *LINE_FSH =
    #include "renderer/feature/BatchGeometryAntiAliasedLines.frag"
    ;
    const char *POLYGON_VSH =
    #include "renderer/feature/BatchGeometryPolygons.vert"
    ;
    const char *POLYGON_FSH =
    #include "renderer/feature/BatchGeometryPolygons.frag"
    ;
    const char *ARROW_VSH =
    #include "renderer/feature/BatchGeometryArrowLines.vert"
    ;
    const char *ARROW_FSH =
    #include "renderer/feature/BatchGeometryArrowLines.frag"
    ;
    const char *MESH_VSH =
    #include "renderer/feature/BatchGeometryMeshes.vert"
    ;
    const char *MESH_FSH =
    #include "renderer/feature/BatchGeometryMeshes.frag"
    ;

    Mutex mutex;
    struct {
        std::map<const RenderContext*, std::map<std::size_t, LinesShader>> lines;
        std::map<const RenderContext*, std::map<std::size_t, AntiAliasedLinesShader>> antiAliasedLines;
        std::map<const RenderContext*, std::map<std::size_t, PolygonsShader>> polygons;
        std::map<const RenderContext*, std::map<std::size_t, StrokedPolygonsShader>> strokedPolygons;
        std::map<const RenderContext*, std::map<std::size_t, PointsShader>> points;
        std::map<const RenderContext*, std::map<std::size_t, ArrowLinesShader>> arrows;
        std::map<const RenderContext*, std::map<std::size_t, MeshesShader>> meshes;
    } shaders;

    bool isMpu() NOTHROWS
    {
        const static bool mpu = ConfigOptions_getIntOptionOrDefault("mpu", 0);
        return mpu;
    }
    const char *mpu5Workaround(const char *csh, std::string &sh) NOTHROWS
    {
        // toggle on all MPU5 code
        sh = csh;
        while(true) {
            auto index = sh.find("//<<MPU5>>", 0u);
            if (index == std::string::npos)
                break;
            sh.erase(index, 10u);
            csh = sh.c_str();
        }
        // replace usages of `gl_PointCoord`
        sh = csh;
        while(true) {
            auto index = sh.find("gl_PointCoord", 0u);
            if (index == std::string::npos)
                break;
            sh.erase(index, 13u);
            // emulate `gl_PointCoord`: https://registry.khronos.org/OpenGL/extensions/ARB/ARB_point_sprite.txt
            sh.insert(index, "vec2(0.5 + (gl_FragCoord.x + 0.5 - vPointCoordParams.x) / vPointCoordParams.z, 0.5 - (gl_FragCoord.y + 0.5 - vPointCoordParams.y) / vPointCoordParams.z)");
            csh = sh.c_str();
        }
        return csh;
    }
    const char *getVertexShaderSource(const char *cvsh, std::string &vsh, const GLBatchGeometryShaderOptions &opts) NOTHROWS
    {
        if(opts.ignoreIdsCount) {
            // replace value of `maxIgnoreIds`
            vsh = cvsh;
            auto index = vsh.find("const int maxIgnoreIds = 0;", 0u);
            if (index != std::string::npos) {
                std::ostringstream strm;
                strm << opts.ignoreIdsCount;
                vsh.replace(index + 25u, 1, strm.str());
                cvsh = vsh.c_str();
            }
        }
        if(opts.enableDisplayThresholds) {
            // switch from LOD threshold constants to attributes
            vsh = cvsh;
            auto minLodIndex = vsh.find("float minLevelOfDetail = cMinLevelOfDetail;", 0u);
            if (minLodIndex != std::string::npos) {
                vsh[minLodIndex+25] = 'a';
                cvsh = vsh.c_str();
            }
            auto maxLodIndex = vsh.find("float maxLevelOfDetail = cMaxLevelOfDetail;", 0u);
            if (maxLodIndex != std::string::npos) {
                vsh[maxLodIndex+25] = 'a';
                cvsh = vsh.c_str();
            }
        }
        if(opts.enableHitTestRadius) {
            // replace value of `hitTestRadius`
            vsh = cvsh;
            auto index = vsh.find("float hitTestRadius = cHitTestRadius;", 0u);
            if (index != std::string::npos) {
                vsh[index+22] = 'u';
                cvsh = vsh.c_str();
            }
        }
        if (opts.enablePixelOffset) {
            vsh = cvsh;
            auto minLodIndex = vsh.find("vec2 offset = cOffset;", 0u);
            if (minLodIndex != std::string::npos) {
                vsh[minLodIndex+14] = 'a';
                cvsh = vsh.c_str();
            }
            auto maxLodIndex = vsh.find("float viewportWidth = cViewportWidth;", 0u);
            if (maxLodIndex != std::string::npos) {
                vsh[maxLodIndex+22] = 'u';
                cvsh = vsh.c_str();
            }
        }
        if (opts.enablePolygonLighting) {
            vsh = cvsh;
            auto lightingFactorIndex = vsh.find("vLightingFactor = cLightingFactor;", 0u);
            if (lightingFactorIndex != std::string::npos) {
                vsh[lightingFactorIndex+18] = 'u';
                cvsh = vsh.c_str();
            }
        }
        return cvsh;
    }

    unsigned optionsKey(const GLBatchGeometryShaderOptions &opts) NOTHROWS
    {
        // create a key unique for the options via bit masking. boolean options should be packed
        // using the low order bits; fixed width using the high order bits
        return (unsigned)((opts.enableHitTestRadius ? 0x1u : 0x0u) |
               (opts.enableDisplayThresholds ? 0x1u : 0x0u) << 1u |
               (opts.enablePixelOffset? 0x1u : 0x0u) << 2u |
               (opts.ignoreIdsCount << 3u));
    }
}

LinesShader TAK::Engine::Renderer::Feature::GLBatchGeometryShaders_getLinesShader(const RenderContext& ctx, const GLBatchGeometryShaderOptions &opts) NOTHROWS
{
    const unsigned key = optionsKey(opts);
    Lock lock(mutex);
    do {
        const auto &a = shaders.lines.find(&ctx);
        if (a == shaders.lines.end())
            break;
        const auto& b = a->second.find(key);
        if (b == a->second.end())
            break;
        return b->second;
    } while (false);
    LinesShader shader;
    // XXX - TODO
    shaders.lines[&ctx][key] = shader;
    return shader;
}
AntiAliasedLinesShader TAK::Engine::Renderer::Feature::GLBatchGeometryShaders_getAntiAliasedLinesShader(const RenderContext& ctx, const GLBatchGeometryShaderOptions &opts) NOTHROWS
{
    const unsigned key = optionsKey(opts);
    Lock lock(mutex);
    do {
        const auto &a = shaders.antiAliasedLines.find(&ctx);
        if (a == shaders.antiAliasedLines.end())
            break;
        const auto& b = a->second.find(key);
        if (b == a->second.end())
            break;
        return b->second;
    } while (false);

    TAKErr code(TE_Ok);

    std::string vsh;
    const char* cvsh = getVertexShaderSource(LINE_VSH, vsh, opts);

    AntiAliasedLinesShader shader;
    int vertShader = GL_NONE;
    code = GLSLUtil_loadShader(&vertShader, cvsh, GL_VERTEX_SHADER);
    assert(code == TE_Ok);

    int fragShader = GL_NONE;
    code = GLSLUtil_loadShader(&fragShader, LINE_FSH, GL_FRAGMENT_SHADER);
    assert(code == TE_Ok);

    ShaderProgram prog;
    code = GLSLUtil_createProgram(&prog, vertShader, fragShader);
    glDeleteShader(vertShader);
    glDeleteShader(fragShader);
    assert(code == TE_Ok);
    shader.base.handle = prog.program;

    glUseProgram(shader.base.handle);
    shader.u_mvp = glGetUniformLocation(shader.base.handle, "u_mvp");
    shader.u_viewportSize = glGetUniformLocation(shader.base.handle, "u_viewportSize");
    shader.uIgnoreIds = glGetUniformLocation(shader.base.handle, "uIgnoreIds");
    shader.u_hitTest = glGetUniformLocation(shader.base.handle, "u_hitTest");
    shader.uColor = glGetUniformLocation(shader.base.handle, "uColor");
    shader.uLevelOfDetail = glGetUniformLocation(shader.base.handle, "uLevelOfDetail");
    shader.uHitTestRadius = glGetUniformLocation(shader.base.handle, "uHitTestRadius");
    shader.a_vertexCoord0 = glGetAttribLocation(shader.base.handle, "a_vertexCoord0");
    shader.a_vertexCoord1 = glGetAttribLocation(shader.base.handle, "a_vertexCoord1");
    shader.a_color = glGetAttribLocation(shader.base.handle, "a_color");
    shader.a_outlineColor = glGetAttribLocation(shader.base.handle, "a_outlineColor");
    shader.a_normal = glGetAttribLocation(shader.base.handle, "a_normal");
    shader.a_halfStrokeWidth = glGetAttribLocation(shader.base.handle, "a_halfStrokeWidth");
    shader.a_outlineWidth = glGetAttribLocation(shader.base.handle, "a_outlineWidth");
    shader.a_dir = glGetAttribLocation(shader.base.handle, "a_dir");
    shader.a_pattern = glGetAttribLocation(shader.base.handle, "a_pattern");
    shader.a_factor = glGetAttribLocation(shader.base.handle, "a_factor");
    shader.a_cap = glGetAttribLocation(shader.base.handle, "a_cap");
    shader.aId = glGetAttribLocation(shader.base.handle, "aId");
    shader.aMinLevelOfDetail = glGetAttribLocation(shader.base.handle, "aMinLevelOfDetail");
    shader.aMaxLevelOfDetail = glGetAttribLocation(shader.base.handle, "aMaxLevelOfDetail");
    shader.aOffset = glGetAttribLocation(shader.base.handle, "aOffset");

    glUniform4f(shader.uColor, 1.f, 1.f, 1.f, 1.f);

    shaders.antiAliasedLines[&ctx][key] = shader;
    return shader;
}
ArrowLinesShader TAK::Engine::Renderer::Feature::GLBatchGeometryShaders_getArrowLinesShader(const RenderContext& ctx, const GLBatchGeometryShaderOptions &opts) NOTHROWS
{
    const unsigned key = optionsKey(opts);
    Lock lock(mutex);
    do {
        const auto &a = shaders.arrows.find(&ctx);
        if (a == shaders.arrows.end())
            break;
        const auto& b = a->second.find(key);
        if (b == a->second.end())
            break;
        return b->second;
    } while (false);

    TAKErr code(TE_Ok);

    std::string vsh;
    const char* cvsh = getVertexShaderSource(ARROW_VSH, vsh, opts);

    ArrowLinesShader shader;
    int vertShader = GL_NONE;
    code = GLSLUtil_loadShader(&vertShader, cvsh, GL_VERTEX_SHADER);
    assert(code == TE_Ok);

    int fragShader = GL_NONE;
    code = GLSLUtil_loadShader(&fragShader, ARROW_FSH, GL_FRAGMENT_SHADER);
    assert(code == TE_Ok);

    ShaderProgram prog;
    code = GLSLUtil_createProgram(&prog, vertShader, fragShader);
    glDeleteShader(vertShader);
    glDeleteShader(fragShader);
    assert(code == TE_Ok);
    shader.handle = prog.program;

    glUseProgram(shader.handle);
    shader.u_mvp = glGetUniformLocation(shader.handle, "u_mvp");
    shader.u_viewportSize = glGetUniformLocation(shader.handle, "u_viewportSize");
    shader.uIgnoreIds = glGetUniformLocation(shader.handle, "uIgnoreIds");
    shader.uColor = glGetUniformLocation(shader.handle, "uColor");
    shader.uLevelOfDetail = glGetUniformLocation(shader.handle, "uLevelOfDetail");
    shader.a_vertexCoord0 = glGetAttribLocation(shader.handle, "a_vertexCoord0");
    shader.a_vertexCoord1 = glGetAttribLocation(shader.handle, "a_vertexCoord1");
    shader.a_color = glGetAttribLocation(shader.handle, "a_color");
    shader.a_outlineColor = glGetAttribLocation(shader.handle, "a_outlineColor");
    shader.a_position = glGetAttribLocation(shader.handle, "a_position");
    shader.a_outlineWidth = glGetAttribLocation(shader.handle, "a_outlineWidth");
    shader.a_radius = glGetAttribLocation(shader.handle, "a_radius");
    shader.aId = glGetAttribLocation(shader.handle, "aId");
    shader.aMinLevelOfDetail = glGetAttribLocation(shader.handle, "aMinLevelOfDetail");
    shader.aMaxLevelOfDetail = glGetAttribLocation(shader.handle, "aMaxLevelOfDetail");
    shader.aOffset = glGetAttribLocation(shader.handle, "aOffset");

    shaders.arrows[&ctx][key] = shader;
    return shader;
}
PolygonsShader TAK::Engine::Renderer::Feature::GLBatchGeometryShaders_getPolygonsShader(const RenderContext& ctx, const GLBatchGeometryShaderOptions &opts) NOTHROWS
{
    const unsigned key = optionsKey(opts);
    Lock lock(mutex);
    do {
        const auto &a = shaders.polygons.find(&ctx);
        if (a == shaders.polygons.end())
            break;
        const auto& b = a->second.find(key);
        if (b == a->second.end())
            break;
        return b->second;
    } while (false);
    TAKErr code(TE_Ok);

    std::string vsh;
    const char* cvsh = getVertexShaderSource(POLYGON_VSH, vsh, opts);

    PolygonsShader shader;
    int vertShader = GL_NONE;
    code = GLSLUtil_loadShader(&vertShader, cvsh, GL_VERTEX_SHADER);
    assert(code == TE_Ok);

    int fragShader = GL_NONE;
    code = GLSLUtil_loadShader(&fragShader, POLYGON_FSH, GL_FRAGMENT_SHADER);
    assert(code == TE_Ok);

    ShaderProgram prog;
    code = GLSLUtil_createProgram(&prog, vertShader, fragShader);
    glDeleteShader(vertShader);
    glDeleteShader(fragShader);
    assert(code == TE_Ok);
    shader.handle = prog.program;

    glUseProgram(shader.handle);
    shader.u_mvp = glGetUniformLocation(shader.handle, "u_mvp");
    shader.uViewport = glGetUniformLocation(shader.handle, "uViewport");
    shader.uIgnoreIds = glGetUniformLocation(shader.handle, "uIgnoreIds");
    shader.uLevelOfDetail = glGetUniformLocation(shader.handle, "uLevelOfDetail");
    shader.uColor = glGetUniformLocation(shader.handle, "u_color");
    shader.uLightingFactor = glGetUniformLocation(shader.handle, "uLightingFactor");
    shader.aPosition = glGetAttribLocation(shader.handle, "aPosition");
    shader.aOutlineWidth = glGetAttribLocation(shader.handle, "aOutlineWidth");
    shader.aExteriorVertex = glGetAttribLocation(shader.handle, "aExteriorVertex");
    shader.a_color = glGetAttribLocation(shader.handle, "a_color");
    shader.aId = glGetAttribLocation(shader.handle, "aId");
    shader.aMinLevelOfDetail = glGetAttribLocation(shader.handle, "aMinLevelOfDetail");
    shader.aMaxLevelOfDetail = glGetAttribLocation(shader.handle, "aMaxLevelOfDetail");
    shader.aOffset = glGetAttribLocation(shader.handle, "aOffset");
    shaders.polygons[&ctx][key] = shader;
    return shader;
}
StrokedPolygonsShader TAK::Engine::Renderer::Feature::GLBatchGeometryShaders_getStrokedPolygonsShader(const RenderContext& ctx, const GLBatchGeometryShaderOptions &opts) NOTHROWS
{
    const unsigned key = optionsKey(opts);
    Lock lock(mutex);
    do {
        const auto &a = shaders.strokedPolygons.find(&ctx);
        if (a == shaders.strokedPolygons.end())
            break;
        const auto& b = a->second.find(key);
        if (b == a->second.end())
            break;
        return b->second;
    } while (false);
    StrokedPolygonsShader shader;
    // XXX - TODO
    shaders.strokedPolygons[&ctx][key] = shader;
    return shader;
}
PointsShader TAK::Engine::Renderer::Feature::GLBatchGeometryShaders_getPointsShader(const RenderContext& ctx, const GLBatchGeometryShaderOptions &opts) NOTHROWS
{
    const unsigned key = optionsKey(opts);
    Lock lock(mutex);
    do {
        const auto &a = shaders.points.find(&ctx);
        if (a == shaders.points.end())
            break;
        const auto& b = a->second.find(key);
        if (b == a->second.end())
            break;
        return b->second;
    } while (false);

    std::string vsh;
    const char* cvsh = getVertexShaderSource(POINT_VSH, vsh, opts);
    std::string fsh;
    const char* cfsh = POINT_FSH;

    if(isMpu()) {
        cvsh = mpu5Workaround(cvsh, vsh);
        cfsh = mpu5Workaround(cfsh, fsh);
    }

    TAKErr code(TE_Ok);
    PointsShader shader;
    int vertShader = GL_NONE;
    code = GLSLUtil_loadShader(&vertShader, cvsh, GL_VERTEX_SHADER);
    assert(code == TE_Ok);

    int fragShader = GL_NONE;
    code = GLSLUtil_loadShader(&fragShader, cfsh, GL_FRAGMENT_SHADER);
    assert(code == TE_Ok);

    ShaderProgram prog{ 0u, 0u, 0u };
    code = GLSLUtil_createProgram(&prog, vertShader, fragShader);
    glDeleteShader(prog.fragShader);
    glDeleteShader(prog.vertShader);
    assert(code == TE_Ok);

    shader.handle = prog.program;
    glUseProgram(shader.handle);

    shader.uMVP = glGetUniformLocation(shader.handle, "uMVP");
    shader.uTexture = glGetUniformLocation(shader.handle, "uTexture");
    shader.uColor = glGetUniformLocation(shader.handle, "uColor");
    shader.uMapRotation = glGetUniformLocation(shader.handle, "uMapRotation");
    shader.uCameraRtc = glGetUniformLocation(shader.handle, "uCameraRtc");
    shader.uWcsScale = glGetUniformLocation(shader.handle, "uWcsScale");
    shader.uTanHalfFov = glGetUniformLocation(shader.handle, "uTanHalfFov");
    shader.uViewportWidth = glGetUniformLocation(shader.handle, "uViewportWidth");
    shader.uViewportHeight = glGetUniformLocation(shader.handle, "uViewportHeight");
    shader.uDrawTilt = glGetUniformLocation(shader.handle, "uDrawTilt");
    shader.uIgnoreIds = glGetUniformLocation(shader.handle, "uIgnoreIds");
    shader.uClampToSurface = glGetUniformLocation(shader.handle, "uClampToSurface");
    shader.uLevelOfDetail = glGetUniformLocation(shader.handle, "uLevelOfDetail");
    shader.uHitTestRadius = glGetUniformLocation(shader.handle, "uHitTestRadius");
    shader.aColor = glGetUniformLocation(shader.handle, "aRotation");
    shader.aPointSize = glGetAttribLocation(shader.handle, "aPointSize");
    shader.aRotation = glGetAttribLocation(shader.handle, "aRotation");
    shader.aVertexCoords = glGetAttribLocation(shader.handle, "aVertexCoords");
    shader.aSurfaceVertexCoords = glGetAttribLocation(shader.handle, "aSurfaceVertexCoords");
    shader.spriteBottomLeft = glGetAttribLocation(shader.handle, "aSpriteBottomLeft");
    shader.spriteDimensions = glGetAttribLocation(shader.handle, "aSpriteDimensions");
    shader.aColor = glGetAttribLocation(shader.handle, "aColor");
    shader.aId = glGetAttribLocation(shader.handle, "aId");
    shader.aAbsoluteRotationFlag = glGetAttribLocation(shader.handle, "aAbsoluteRotationFlag");
    shader.aMinLevelOfDetail = glGetAttribLocation(shader.handle, "aMinLevelOfDetail");
    shader.aMaxLevelOfDetail = glGetAttribLocation(shader.handle, "aMaxLevelOfDetail");
    shader.aOffset = glGetAttribLocation(shader.handle, "aOffset");

    shaders.points[&ctx][key] = shader;
    return shader;
}
MeshesShader TAK::Engine::Renderer::Feature::GLBatchGeometryShaders_getMeshesShader(const RenderContext& ctx, const GLBatchGeometryShaderOptions &opts) NOTHROWS
{
    const unsigned key = optionsKey(opts);
    Lock lock(mutex);
    do {
        const auto &a = shaders.meshes.find(&ctx);
        if (a == shaders.meshes.end())
            break;
        const auto& b = a->second.find(key);
        if (b == a->second.end())
            break;
        return b->second;
    } while (false);
    TAKErr code(TE_Ok);

    std::string vsh;
    const char* cvsh = getVertexShaderSource(MESH_VSH, vsh, opts);

    MeshesShader shader;
    int vertShader = GL_NONE;
    code = GLSLUtil_loadShader(&vertShader, cvsh, GL_VERTEX_SHADER);
    assert(code == TE_Ok);

    int fragShader = GL_NONE;
    code = GLSLUtil_loadShader(&fragShader, MESH_FSH, GL_FRAGMENT_SHADER);
    assert(code == TE_Ok);

    ShaderProgram prog;
    code = GLSLUtil_createProgram(&prog, vertShader, fragShader);
    glDeleteShader(vertShader);
    glDeleteShader(fragShader);
    assert(code == TE_Ok);
    shader.handle = prog.program;

    glUseProgram(shader.handle);
    shader.uMvp = glGetUniformLocation(shader.handle, "uMvp");
    shader.uIgnoreIds = glGetUniformLocation(shader.handle, "uIgnoreIds");
    shader.uLevelOfDetail = glGetUniformLocation(shader.handle, "uLevelOfDetail");
    shader.uTexture = glGetUniformLocation(shader.handle, "uTexture");
    shader.uColor = glGetUniformLocation(shader.handle, "uColor");
    shader.uLightingFactor = glGetUniformLocation(shader.handle, "uLightingFactor");
    shader.aPosition = glGetAttribLocation(shader.handle, "aPosition");
    shader.aTexPos = glGetAttribLocation(shader.handle, "aTexPos");
    shader.aVertColor = glGetAttribLocation(shader.handle, "aVertColor");
    shader.aNormals = glGetAttribLocation(shader.handle, "aNormals");
    shader.aVertexCoord = glGetAttribLocation(shader.handle, "aVertexCoord");
    shader.aSpriteBottomLeft = glGetAttribLocation(shader.handle, "aSpriteBottomLeft");
    shader.aSpriteTopRight = glGetAttribLocation(shader.handle, "aSpriteTopRight");
    shader.aColor = glGetAttribLocation(shader.handle, "aColor");
    shader.aTransform = glGetAttribLocation(shader.handle, "aTransform");
    shader.aId = glGetAttribLocation(shader.handle, "aId");
    shader.aMinLevelOfDetail = glGetAttribLocation(shader.handle, "aMinLevelOfDetail");
    shader.aMaxLevelOfDetail = glGetAttribLocation(shader.handle, "aMaxLevelOfDetail");
    shaders.meshes[&ctx][key] = shader;
    return shader;
}
