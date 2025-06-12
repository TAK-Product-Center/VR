#ifndef TAK_ENGINE_RENDERER_FEATURE_GLBATCHGEOMETRYRENDERER4_H_INCLUDED
#define TAK_ENGINE_RENDERER_FEATURE_GLBATCHGEOMETRYRENDERER4_H_INCLUDED

#include <functional>
#include <memory>

#include "renderer/GLOffscreenFramebuffer.h"
#include "renderer/Shader.h"
#include "renderer/GLVertexArray.h"
#include "renderer/core/GLDirtyRegion.h"
#include "renderer/core/GLMapRenderable2.h"
#include "renderer/core/GLGlobeBase.h"
#include "renderer/core/controls/ClampToGroundControl.h"
#include "renderer/feature/GLBatchGeometryShaders.h"

#include "core/GeoPoint2.h"
#include "port/Collection.h"
#include "util/Error.h"
#include "util/MemBuffer2.h"

namespace TAK {
    namespace Engine {
        namespace Renderer {
            namespace Feature {

                struct PointBufferLayout {
                    GLfloat position[3];
                    GLfloat surfacePosition[3];
                    GLshort rotation[2];
                    GLushort spriteBottomLeft[2];
                    GLushort spriteDimensions[2];
                    GLfloat pointSize;
                    GLubyte color[4];
                    GLuint id;
                    GLubyte absoluteRotationFlag;
                    GLubyte minLod;
                    GLubyte maxLod;
                    GLubyte reserved[1u];
                    GLshort offset[2];
                };

                // Various buffer size and offset constants
                constexpr GLuint POINT_VERTEX_SIZE = sizeof(PointBufferLayout);
                constexpr GLuint POINT_VERTEX_POSITION_OFFSET = offsetof(PointBufferLayout, position);
                constexpr GLuint POINT_VERTEX_SURFACE_POSITION_OFFSET = offsetof(PointBufferLayout, surfacePosition);
                constexpr GLuint POINT_VERTEX_ROTATION_OFFSET = offsetof(PointBufferLayout, rotation);
                constexpr GLuint POINT_VERTEX_SPRITE_BOTTOM_LEFT_OFFSET = offsetof(PointBufferLayout, spriteBottomLeft);
                constexpr GLuint POINT_VERTEX_SPRITE_DIMENSIONS_OFFSET = offsetof(PointBufferLayout, spriteDimensions);
                constexpr GLuint POINT_VERTEX_POINT_SIZE_OFFSET = offsetof(PointBufferLayout, pointSize);
                constexpr GLuint POINT_VERTEX_COLOR_OFFSET = offsetof(PointBufferLayout, color);
                constexpr GLuint POINT_VERTEX_ID_OFFSET = offsetof(PointBufferLayout, id);
                constexpr GLuint POINT_VERTEX_ABSOLUTE_ROTATION_FLAG_OFFSET = offsetof(PointBufferLayout, absoluteRotationFlag);
                constexpr GLuint POINT_VERTEX_MIN_LOD = offsetof(PointBufferLayout, minLod);
                constexpr GLuint POINT_VERTEX_MAX_LOD = offsetof(PointBufferLayout, maxLod);
                constexpr GLuint POINT_VERTEX_OFFSET = offsetof(PointBufferLayout, offset);

                struct LineBufferLayout {
                    GLfloat position0[3];       // 0...11
                    GLfloat position1[3];       // 12..23
                    GLubyte color[4];           // 24..27
                    GLuint id;                  // 28..31
                    GLushort pattern;           // 32..33
                    GLubyte cap[2];             // 34..35
                    GLubyte factor;             // 36..
                    GLubyte halfStrokeWidth;    // 37..
                    GLubyte radius;             // 38..
                    GLubyte dir;                // 39..
                    GLubyte normal;             // 40..
                    GLubyte minLod;             // 41..
                    GLubyte maxLod;             // 42..
                    GLubyte reserved[1u];       // 43..
                };

                constexpr GLuint LINE_VERTEX_SIZE = sizeof(LineBufferLayout);
                constexpr GLuint LINE_VERTEX_POSITION0_OFFSET = offsetof(LineBufferLayout, position0);
                constexpr GLuint LINE_VERTEX_POSITION1_OFFSET = offsetof(LineBufferLayout, position1);
                constexpr GLuint LINE_VERTEX_COLOR_OFFSET = offsetof(LineBufferLayout, color);
                constexpr GLuint LINE_VERTEX_PATTERN_OFFSET = offsetof(LineBufferLayout, pattern);
                constexpr GLuint LINE_VERTEX_NORMAL_OFFSET = offsetof(LineBufferLayout, normal);
                constexpr GLuint LINE_VERTEX_HALF_STROKE_WIDTH_OFFSET = offsetof(LineBufferLayout, halfStrokeWidth);
                constexpr GLuint LINE_VERTEX_DIR_OFFSET = offsetof(LineBufferLayout, dir);
                constexpr GLuint LINE_VERTEX_FACTOR_OFFSET = offsetof(LineBufferLayout, factor);
                constexpr GLuint LINE_VERTEX_ID_OFFSET = offsetof(LineBufferLayout, id);
                constexpr GLuint LINE_VERTEX_CAP_OFFSET = offsetof(LineBufferLayout, cap);
                constexpr GLuint LINE_VERTEX_MIN_LOD = offsetof(LineBufferLayout, minLod);
                constexpr GLuint LINE_VERTEX_MAX_LOD = offsetof(LineBufferLayout, maxLod);


                constexpr GLuint ARROW_VERTEX_SIZE = sizeof(LineBufferLayout);
                constexpr GLuint ARROW_VERTEX_POSITION0_OFFSET = offsetof(LineBufferLayout, position0);
                constexpr GLuint ARROW_VERTEX_POSITION1_OFFSET = offsetof(LineBufferLayout, position1);
                constexpr GLuint ARROW_VERTEX_COLOR_OFFSET = offsetof(LineBufferLayout, color);
                constexpr GLuint ARROW_VERTEX_ID_OFFSET = offsetof(LineBufferLayout, id);
                constexpr GLuint ARROW_VERTEX_RADIUS_OFFSET = offsetof(LineBufferLayout, radius);
                constexpr GLuint ARROW_VERTEX_MIN_LOD = offsetof(LineBufferLayout, minLod);
                constexpr GLuint ARROW_VERTEX_MAX_LOD = offsetof(LineBufferLayout, maxLod);

                struct PolygonBufferLayout {
                    GLfloat position0[3];
                    GLubyte color[4];
                    GLfloat outlineWidth;
                    GLfloat exteriorVertex;
                    GLuint id;
                    GLubyte minLod;
                    GLubyte maxLod;
                    GLubyte reserved[2u];
                };

                constexpr GLuint POLYGON_VERTEX_SIZE = sizeof(PolygonBufferLayout);
                constexpr GLuint POLYGON_VERTEX_POSITION_OFFSET = offsetof(PolygonBufferLayout, position0);
                constexpr GLuint POLYGON_VERTEX_COLOR_OFFSET = offsetof(PolygonBufferLayout, color);
                constexpr GLuint POLYGON_VERTEX_OUTLINE_WIDTH_OFFSET = offsetof(PolygonBufferLayout, outlineWidth);
                constexpr GLuint POLYGON_VERTEX_EXTERIOR_VERTEX_OFFSET = offsetof(PolygonBufferLayout, exteriorVertex);
                constexpr GLuint POLYGON_VERTEX_ID_OFFSET = offsetof(PolygonBufferLayout, id);
                constexpr GLuint POLYGON_VERTEX_MIN_LOD = offsetof(PolygonBufferLayout, minLod);
                constexpr GLuint POLYGON_VERTEX_MAX_LOD = offsetof(PolygonBufferLayout, maxLod);

                struct MeshBufferLayout {
                    GLfloat position0[3];
                    GLubyte color[4];
                    GLuint id;
                    GLubyte minLod;
                    GLubyte maxLod;
                    GLubyte reserved[2u];
                    GLfloat transform[16];
                };

                constexpr GLuint MESH_VERTEX_SIZE = sizeof(MeshBufferLayout);
                constexpr GLuint MESH_VERTEX_POSITION_OFFSET = offsetof(MeshBufferLayout, position0);
                constexpr GLuint MESH_VERTEX_COLOR_OFFSET = offsetof(MeshBufferLayout, color);
                constexpr GLuint MESH_VERTEX_ID_OFFSET = offsetof(MeshBufferLayout, id);
                constexpr GLuint MESH_VERTEX_MIN_LOD = offsetof(MeshBufferLayout, minLod);
                constexpr GLuint MESH_VERTEX_MAX_LOD = offsetof(MeshBufferLayout, maxLod);
                constexpr GLuint MESH_VERTEX_TRANSFORM = offsetof(MeshBufferLayout, transform);

                // TODO jgm: I don't see why these can't be constants?
                struct ENGINE_API BatchGeometryBufferLayout
                {
                    // XXX - union here
                    struct {
                        struct {
                            TAK::Engine::Renderer::GLVertexArray position;
                            TAK::Engine::Renderer::GLVertexArray color;
                            TAK::Engine::Renderer::GLVertexArray normal;
                            TAK::Engine::Renderer::GLVertexArray id;
                            TAK::Engine::Renderer::GLVertexArray minLod;
                            TAK::Engine::Renderer::GLVertexArray maxLod;
                        } lines;
                        struct {
                            TAK::Engine::Renderer::GLVertexArray position0;
                            TAK::Engine::Renderer::GLVertexArray position1;
                            TAK::Engine::Renderer::GLVertexArray color;
                            TAK::Engine::Renderer::GLVertexArray normal;
                            TAK::Engine::Renderer::GLVertexArray halfStrokeWidth;
                            TAK::Engine::Renderer::GLVertexArray dir;
                            TAK::Engine::Renderer::GLVertexArray pattern;
                            TAK::Engine::Renderer::GLVertexArray factor;
                            TAK::Engine::Renderer::GLVertexArray id;
                            TAK::Engine::Renderer::GLVertexArray cap;
                            TAK::Engine::Renderer::GLVertexArray minLod;
                            TAK::Engine::Renderer::GLVertexArray maxLod;
                        } antiAliasedLines;
                        struct {
                            TAK::Engine::Renderer::GLVertexArray position0;
                            TAK::Engine::Renderer::GLVertexArray position1;
                            TAK::Engine::Renderer::GLVertexArray color;
                            TAK::Engine::Renderer::GLVertexArray radius;
                            TAK::Engine::Renderer::GLVertexArray id;
                            TAK::Engine::Renderer::GLVertexArray minLod;
                            TAK::Engine::Renderer::GLVertexArray maxLod;
                        } arrows;
                        struct {
                            TAK::Engine::Renderer::GLVertexArray position;
                            TAK::Engine::Renderer::GLVertexArray color;
                            TAK::Engine::Renderer::GLVertexArray outlineWidth;
                            TAK::Engine::Renderer::GLVertexArray exteriorVertex;
                            TAK::Engine::Renderer::GLVertexArray normal;
                            TAK::Engine::Renderer::GLVertexArray id;
                            TAK::Engine::Renderer::GLVertexArray minLod;
                            TAK::Engine::Renderer::GLVertexArray maxLod;
                        } polygons;
                        struct {
                            TAK::Engine::Renderer::GLVertexArray position;
                            TAK::Engine::Renderer::GLVertexArray fillColor;
                            TAK::Engine::Renderer::GLVertexArray strokeColor;
                            TAK::Engine::Renderer::GLVertexArray normal;
                            TAK::Engine::Renderer::GLVertexArray edge;
                            TAK::Engine::Renderer::GLVertexArray strokeWidth;
                            TAK::Engine::Renderer::GLVertexArray id;
                            TAK::Engine::Renderer::GLVertexArray minLod;
                            TAK::Engine::Renderer::GLVertexArray maxLod;
                        } strokedPolygons;
                        struct {
                            TAK::Engine::Renderer::GLVertexArray position;
                            TAK::Engine::Renderer::GLVertexArray surfacePosition;
                            TAK::Engine::Renderer::GLVertexArray rotation;
                            TAK::Engine::Renderer::GLVertexArray pointSize;
                            TAK::Engine::Renderer::GLVertexArray spriteBottomLeft;
                            TAK::Engine::Renderer::GLVertexArray spriteDimensions;
                            TAK::Engine::Renderer::GLVertexArray color;
                            TAK::Engine::Renderer::GLVertexArray normal;
                            TAK::Engine::Renderer::GLVertexArray id;
                            TAK::Engine::Renderer::GLVertexArray absoluteRotationFlag;
                            TAK::Engine::Renderer::GLVertexArray minLod;
                            TAK::Engine::Renderer::GLVertexArray maxLod;
                            TAK::Engine::Renderer::GLVertexArray offset;
                        } points;
                        struct {
                            TAK::Engine::Renderer::GLVertexArray vertexCoord;
                            TAK::Engine::Renderer::GLVertexArray spriteBottomLeft;
                            TAK::Engine::Renderer::GLVertexArray spriteTopRight;
                            TAK::Engine::Renderer::GLVertexArray color;
                            TAK::Engine::Renderer::GLVertexArray normal;
                            TAK::Engine::Renderer::GLVertexArray id;
                            TAK::Engine::Renderer::GLVertexArray minLod;
                            TAK::Engine::Renderer::GLVertexArray maxLod;
                            TAK::Engine::Renderer::GLVertexArray transform;
                        } meshes;
                    } vertex;
                };

                class ENGINE_API GLBatchGeometryRenderer4 :
                    public TAK::Engine::Renderer::Core::GLMapRenderable2
                {
                public :
                    enum Program {
                        Lines,
                        AntiAliasedLines,
                        Polygons,
                        StrokedPolygons,
                        Points,
                        Arrows,
                        Meshes,
                    };
                    struct PrimitiveBuffer {
                        GLuint vbo{ GL_NONE };
                        GLuint ibo{ GL_NONE };
                        GLsizei count{ 0u };
                        GLenum mode{ GL_NONE };
                        GLuint texid{ GL_NONE };
                    };
                    struct BatchState {
                        TAK::Engine::Core::GeoPoint2 centroid;
                        Math::Point2<double> centroidProj;
                        int srid{ -1 };
                        Math::Matrix2 localFrame;
                    };
                private :
                    struct VertexBuffer
                    {
                        PrimitiveBuffer primitive;
                        BatchGeometryBufferLayout layout;
                    };
                public:
                    GLBatchGeometryRenderer4(const TAK::Engine::Core::RenderContext &context) NOTHROWS;
                    GLBatchGeometryRenderer4(const TAK::Engine::Core::RenderContext &context, const unsigned int primitivesPresorted) NOTHROWS;
                    ~GLBatchGeometryRenderer4() NOTHROWS;
                public:
                    Util::TAKErr setBatchState(const BatchState &surface, const BatchState &sprites) NOTHROWS;
                    /**
                     * <P>Ownership of the buffer is transferred as a result of this call.
                     */
                    Util::TAKErr addBatchBuffer(const Program program, const PrimitiveBuffer &buffer, const BatchGeometryBufferLayout &layout, const int renderPass, const std::shared_ptr<const TAK::Engine::Model::Mesh> mesh = nullptr) NOTHROWS;
                    /**
                     * Marks all buffers currently owned for release. Will be released on next call to `draw` or `release`.
                     * 
                     * <P>This may be invoked from other threads, but the caller must externally synchronize.
                     */
                    std::size_t markForRelease(const std::function<void(const PrimitiveBuffer &)> &recycler = nullptr) NOTHROWS;

                    void setIgnoreFeatures(const uint32_t *hitids, const std::size_t count) NOTHROWS;

                    /**
                     * Performs a hit test by rendering all objects with their IDs in place of their color attribute and reading the contents
                     * of the back buffer at the specified x and y screen coordinates.
                     *
                     * <P>Utilizes a hit radius of 1px
                     * 
                     * @param featureIds Output parameter which will contain the IDs of the features that have been hit.
                     * @param view The current GLGlobeBase, used for rendering the features.
                     * @param screenX The x screen coordinate.
                     * @param screenY The y screen coordinate.
                     * @param limit   The maximum number of results, zero for unbound
                     */
                    void hitTest(Port::Collection<uint32_t> &hitids, const Core::GLGlobeBase &view, const float screenX, const float screenY, const std::size_t limit = 1u) NOTHROWS;
                    /**
                     * Performs a hit test by rendering all objects with their IDs in place of their color attribute and reading the contents
                     * of the back buffer at the specified x and y screen coordinates.
                     *
                     * @param featureIds Output parameter which will contain the IDs of the features that have been hit.
                     * @param view The current GLGlobeBase, used for rendering the features.
                     * @param screenX The x screen coordinate.
                     * @param screenY The y screen coordinate.
                     * @param radius  The radius to hit-test against, in pixels
                     * @param limit   The maximum number of results, zero for unbound
                     */
                    void hitTest(Port::Collection<uint32_t> &hitids, const Core::GLGlobeBase &view, const float screenX, const float screenY, const float radius, const std::size_t limit) NOTHROWS;
                private:
                    /**
                     * Draws the contents of the buffers. 
                     * 
                     * @param view The current GLGlobeBase, used for rendering the features.
                     * @param renderPass The current render pass. Should be `GLGlobeBase::Surface` for rendering features to the terrain surface, 
                     *                   `GLGlobeBase::Sprites` for rendering 3D features, or both bitwise or'd togethor.
                     * @param drawForHitTest If true then the features' color attribute will be replaced with either the upper or lower half of their feature id,
                     *                       depending on what `hitTestPass` is set to. Otherwise, the features will be rendered normally.
                     * @param hitTestPass Determines which half of feature ID will be used as the color attribute. If 0 then the upper half will be used.
                     *                    If 1 then the lower half will be used.
                     */
                    void draw(const Core::GLGlobeBase::State &view, const std::size_t levelOfDetail, const int renderPass, const bool drawForHitTest, const float hitTestRadius, const std::vector<uint32_t> &ignoreIds);
                    virtual void drawSurface(const TAK::Engine::Renderer::Core::GLGlobeBase::State &view, const std::size_t levelOfDetail, const bool drawForHitTest, const float hitTestRadius, const std::vector<uint32_t> &ignoreIds) NOTHROWS;
                    virtual void drawSprites(const TAK::Engine::Renderer::Core::GLGlobeBase::State &view, const std::size_t levelOfDetail, const bool drawForHitTest, const float hitTestRadius, const std::vector<uint32_t> &ignoreIds) NOTHROWS;


                    Util::TAKErr drawLineBuffers(const TAK::Engine::Renderer::Core::GLGlobeBase::State &view, const std::size_t levelOfDetail, const BatchState &ctx, const std::vector<VertexBuffer> &bufs, const bool drawForHitTest, const float hitTestRadius, const bool surface, const std::vector<uint32_t> &ignoreIds, const float r = 1.f, const float g = 1.f, const float b = 1.f, const float a = 1.f) NOTHROWS;
                    Util::TAKErr drawArrowBuffers(const TAK::Engine::Renderer::Core::GLGlobeBase::State &view, const std::size_t levelOfDetail, const BatchState &ctx, const std::vector<VertexBuffer> &bufs, const bool drawForHitTest, const float hitTestRadius, const bool surface, const std::vector<uint32_t> &ignoreIds, const float r = 1.f, const float g = 1.f, const float b = 1.f, const float a = 1.f) NOTHROWS;
                    Util::TAKErr drawPolygonBuffers(const TAK::Engine::Renderer::Core::GLGlobeBase::State &view, const std::size_t levelOfDetail, const BatchState &ctx, const std::vector<VertexBuffer> &bufs, const bool drawForHitTest, const float hitTestRadius, const bool surface, const std::vector<uint32_t> &ignoreIds) NOTHROWS;
                    Util::TAKErr batchDrawPoints(const TAK::Engine::Renderer::Core::GLGlobeBase::State &view, const std::size_t levelOfDetail, const BatchState &ctx, const bool drawForHitTest, const float hitTestRadius, const std::vector<uint32_t> &ignoreIds) NOTHROWS;
                    Util::TAKErr drawMeshBuffers(const TAK::Engine::Renderer::Core::GLGlobeBase::State &view, const std::size_t levelOfDetail, const BatchState &ctx, const std::vector<VertexBuffer> &buf, bool drawForHitTest, const float hitTestRadius, const std::vector<uint32_t> &ignoreIds, const std::shared_ptr<const TAK::Engine::Model::Mesh>& mesh) NOTHROWS;

                    Util::TAKErr drawLollipopBuffers(const TAK::Engine::Renderer::Core::GLGlobeBase::State &view, const std::size_t levelOfDetail, const BatchState &ctx, const std::vector<VertexBuffer> &bufs, const bool drawForHitTest, const float hitTestRadius, const bool surface, const std::vector<uint32_t> &ignoreIds, const float r = 1.f, const float g = 1.f, const float b = 1.f, const float a = 1.f) NOTHROWS;
                   // Util::TAKErr drawPoints(const TAK::Engine::Renderer::Core::GLGlobeBase::State &view) NOTHROWS;
                    //Util::TAKErr renderPointsBuffers(const TAK::Engine::Renderer::Core::GLGlobeBase::State &view, GLBatchPointBuffer & batch_point_buffer) NOTHROWS;
                public:
                    virtual void draw(const TAK::Engine::Renderer::Core::GLGlobeBase &view, const int renderPass) NOTHROWS override;
                    virtual int getRenderPass() NOTHROWS override;

                    virtual void start() NOTHROWS override;
                    virtual void stop() NOTHROWS override;

                    virtual void release() NOTHROWS override;
                private:
                    const TAK::Engine::Core::RenderContext &context;
                    std::vector<VertexBuffer> surfaceLineBuffers;
                    std::vector<VertexBuffer> spriteLineBuffers;
                    std::vector<VertexBuffer> surfaceArrowBuffers;
                    std::vector<VertexBuffer> spriteArrowBuffers;
                    std::vector<VertexBuffer> surfacePolygonBuffers;
                    std::vector<VertexBuffer> spritePolygonBuffers;
                    std::vector<VertexBuffer> pointsBuffers;
                    std::map<std::shared_ptr<const TAK::Engine::Model::Mesh>, std::vector<VertexBuffer>> spriteMeshBuffers;
                    std::vector<uint32_t> ignoreFeatures;

                    Core::GLDirtyRegion surfaceCoverage;

                    PointsShader pointShader;
                    AntiAliasedLinesShader lineShader;
                    ArrowLinesShader arrowShader;
                    PolygonsShader polygonsShader;
                    MeshesShader meshesShader;

                    struct {
                        BatchState surface;
                        BatchState sprites;
                    } batchState;
                    std::vector<GLuint> markedForRelease;
                    unsigned int featuresPresort{ 0u };

                    struct {
                        std::shared_ptr<GLOffscreenFramebuffer> pixel;
                        std::shared_ptr<GLOffscreenFramebuffer> tile;
                    } fbo;

                    struct {
                        bool initialized{ false };
                        Core::Controls::ClampToGroundControl *value{nullptr};
                    } clampToGroundControl;

                    bool isMpu;
                };
            }
        }
    }
}

#endif // TAK_ENGINE_RENDERER_FEATURE_GLBATCHGEOMETRYRENDERER4_H_INCLUDED
