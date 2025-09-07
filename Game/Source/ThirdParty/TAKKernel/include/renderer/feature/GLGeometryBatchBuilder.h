#ifndef TAK_ENGINE_RENDERER_FEATURE_GLGEOMETRYBATCHBUILDER_H_INCLUDED
#define TAK_ENGINE_RENDERER_FEATURE_GLGEOMETRYBATCHBUILDER_H_INCLUDED

#include <map>
#include <vector>
#include <renderer/core/controls/FeaturesLabelControl.h>

#include "core/Projection2.h"
#include "feature/Feature2.h"
#include "feature/FeatureDefinition2.h"
#include "math/Point2.h"
#include "port/Platform.h"
#include "renderer/core/GLLabel.h"
#include "renderer/feature/GLBatchGeometryRenderer4.h"
#include "util/DataInput2.h"
#include "util/DataOutput2.h"
#include "util/Error.h"

namespace TAK {
    namespace Engine {
        namespace Renderer {
            namespace Feature {
                class GLBatchGeometryFeatureDataStoreRenderer3;

                class ENGINE_API GLGeometryBatchBuilder
                {
                public :
                    enum PushHints {
                        ProcessLabels = 0x1u,
                        ForceClampToGround = 0x2u,
                        PolygonCenterLabels = 0x4u,
                        RequireLabel = 0x8u,
                        TessellationDisabled = 0x10u,
                        SimplificationDisabled = 0x20u,
                        AntiMeridianHandlingDisabled = 0x40u,
                        LabelOnlyHandlingDisabled = 0x80u,
                        SkipNoStyleFeatures = 0x100u,
                        LinestringIcons = 0x200u,
                        DensityAdjustStroke = 0x400u,
                        IconDeclutter = 0x800u,
                    };
                public :
                    class Callback;
                    class Callback2;
                    class Callback3;
                public :
                    class VertexWriter;
                public :
                    struct BatchContext {
                        int surfaceSrid{-1};
                        int spritesSrid{-1};
                        TAK::Engine::Core::GeoPoint2 relativeToCenter{ TAK::Engine::Core::GeoPoint2(NAN, NAN) };
                        struct {
                            double scene {NAN};
                            double tessellate {NAN};
                            double gsdRange {NAN};
                        } resolution;
                        TAK::Engine::Core::GeoPoint2 camera{ TAK::Engine::Core::GeoPoint2(NAN, NAN) };
                        TAK::Engine::Feature::Envelope2 bounds{ TAK::Engine::Feature::Envelope2(-180.0, -90.0, 0.0, 180.0, 90.0, 0.0) };
                        const bool *cancelToken{nullptr};
                    };
                public :
                    GLGeometryBatchBuilder() NOTHROWS;
                    ~GLGeometryBatchBuilder() NOTHROWS;
                public :
                    /** @deprecated use `reset(BatchContext, Callback3)` */
                    Util::TAKErr reset(const int surfaceSrid, const int spritesSrid, const TAK::Engine::Core::GeoPoint2  &relativeToCenter, const double resolution, Callback &callback) NOTHROWS;
                    /** @deprecated use `reset(BatchContext, Callback3)` */
                    Util::TAKErr reset(const int surfaceSrid, const int spritesSrid, const TAK::Engine::Core::GeoPoint2& relativeToCenter, const double resolution, Callback2& callback) NOTHROWS;
                    /** @deprecated use `reset(BatchContext, Callback3)` */
                    Util::TAKErr reset(const int surfaceSrid, const int spritesSrid, const TAK::Engine::Core::GeoPoint2& relativeToCenter, const double resolution, Callback3& callback) NOTHROWS;
                    /**
                     * Prepares the builder for the next batch of data. This function must always be invoked prior to calling `push`
                     */
                    Util::TAKErr reset(const BatchContext &batchContext, Callback3& callback) NOTHROWS;
                    /** @deprecated use `PushHints` overload */
                    Util::TAKErr push(TAK::Engine::Feature::FeatureDefinition2 &def, const bool processLabels, const bool forceClampToGround = true) NOTHROWS;
                    /** @deprecated use `PushHints` overload */
                    Util::TAKErr push(const TAK::Engine::Feature::Feature2 &def, const bool processLabels, const bool forceClampToGround = true) NOTHROWS;

                    Util::TAKErr push(TAK::Engine::Feature::FeatureDefinition2 &def, const PushHints hints = (PushHints)0u) NOTHROWS;
                    Util::TAKErr push(const TAK::Engine::Feature::Feature2 &def, const PushHints hints = (PushHints)0u) NOTHROWS;

                    /**
                     * Flushes any data that is in mapped buffers and unmaps. This function should always be called prior to `setBatch`.
                     */
                    Util::TAKErr flush() NOTHROWS;
                    /**
                     */
                    Util::TAKErr setBatch(GLBatchGeometryRenderer4 &sink) const NOTHROWS;
                private :
                    struct Builder {
                        Util::MemoryOutput2 buffer;
                        GLBatchGeometryRenderer4::PrimitiveBuffer pb;
                    };
                    struct {
                        struct {
                            Builder lines;
                            Builder antiAliasedLines;
                            Builder arrows;
                            Builder polygons;
                            Builder strokedPolygons;
                            Builder points;
                        } surface;
                        struct {
                            Builder lines;
                            Builder antiAliasedLines;
                            Builder arrows;
                            std::map<std::shared_ptr<const TAK::Engine::Model::Mesh>, Builder> meshes;
                            Builder polygons;
                            Builder strokedPolygons;
                            Builder points;
                        } sprites;
                    } builders;
                    struct {
                        struct {
                            std::vector<GLBatchGeometryRenderer4::PrimitiveBuffer> lines;
                            std::vector<GLBatchGeometryRenderer4::PrimitiveBuffer> antiAliasedLines;
                            std::vector<GLBatchGeometryRenderer4::PrimitiveBuffer> arrows;
                            std::vector<GLBatchGeometryRenderer4::PrimitiveBuffer> polygons;
                            std::vector<GLBatchGeometryRenderer4::PrimitiveBuffer> strokedPolygons;
                            std::vector<GLBatchGeometryRenderer4::PrimitiveBuffer> points;
                        } surface;
                        struct {
                            std::vector<GLBatchGeometryRenderer4::PrimitiveBuffer> lines;
                            std::vector<GLBatchGeometryRenderer4::PrimitiveBuffer> antiAliasedLines;
                            std::vector<GLBatchGeometryRenderer4::PrimitiveBuffer> arrows;
                            std::map<std::shared_ptr<const TAK::Engine::Model::Mesh>, std::vector<GLBatchGeometryRenderer4::PrimitiveBuffer>> meshes;
                            std::vector<GLBatchGeometryRenderer4::PrimitiveBuffer> polygons;
                            std::vector<GLBatchGeometryRenderer4::PrimitiveBuffer> strokedPolygons;
                            std::vector<GLBatchGeometryRenderer4::PrimitiveBuffer> points;
                        } sprites;
                    } buffers;

                    struct {
                        TAK::Engine::Core::Projection2Ptr surface{ TAK::Engine::Core::Projection2Ptr(nullptr, nullptr) };
                        TAK::Engine::Core::Projection2Ptr sprites{ TAK::Engine::Core::Projection2Ptr(nullptr, nullptr) };
                    } proj;
                    struct {
                        Math::Point2<double> surface;
                        Math::Point2<double> sprites;
                    } relativeToCenter;
                    std::map<Port::String, TAK::Engine::Feature::StylePtr_const, Port::StringLess> parsedStyles;
                    BatchContext batchContext;
                    double simplifyFactor;
                    Callback3 *callback;
                    // used for implicit labeling
                    struct {
                        std::size_t minLod {atakmap::feature::LevelOfDetailStyle::MIN_LOD};
                        std::size_t maxLod {atakmap::feature::LevelOfDetailStyle::MAX_LOD};
                        uint32_t backgroundColor {0x0u};
                        bool overrideBackgroundColor {false};
                    } labelDefaults;

                    std::vector<TAK::Engine::Math::Rectangle2<double>> iconOcclusionMask;
                    friend class GLBatchGeometryFeatureDataStoreRenderer3;
                };

                class GLGeometryBatchBuilder::Callback
                {
                protected :
                    virtual ~Callback() NOTHROWS = 0;
                public :
                    virtual Util::TAKErr mapBuffer(GLuint *handle, void **buffer, const std::size_t size) NOTHROWS = 0;
                    virtual Util::TAKErr unmapBuffer(const GLuint handle) NOTHROWS = 0;
                    virtual Util::TAKErr getElevation(double *value, const double latitude, const double longitude) NOTHROWS = 0;
                    virtual Util::TAKErr getIcon(GLuint *id, float *u0, float *v0, float *u1, float *v1, std::size_t *w, std::size_t *h, float *rotation, bool *isAbsoluteRotation, const char* uri) NOTHROWS = 0;
                    /**
                     * Adds a label to the feature currently being processed.
                     */
                    virtual Util::TAKErr addLabel(const TAK::Engine::Renderer::Core::GLLabel &label) NOTHROWS  = 0;
                    virtual uint32_t reserveHitId() NOTHROWS = 0;
                };
                class GLGeometryBatchBuilder::Callback2 : public GLGeometryBatchBuilder::Callback
                {
                protected :
                    virtual ~Callback2() NOTHROWS = 0;
                public :
                    using GLGeometryBatchBuilder::Callback::mapBuffer;
                    using GLGeometryBatchBuilder::Callback::unmapBuffer;
                    using GLGeometryBatchBuilder::Callback::getElevation;
                    using GLGeometryBatchBuilder::Callback::getIcon;
                    using GLGeometryBatchBuilder::Callback::addLabel;
                    using GLGeometryBatchBuilder::Callback::reserveHitId;

                    /**
                     * Adds a label to the feature currently being processed.
                     */
                    virtual Util::TAKErr addLabel(TAK::Engine::Renderer::Core::GLLabel &&label) NOTHROWS  = 0;
                };
                class GLGeometryBatchBuilder::Callback3 : public GLGeometryBatchBuilder::Callback2
                {
                protected :
                    virtual ~Callback3() NOTHROWS = 0;
                public :
                    using GLGeometryBatchBuilder::Callback::mapBuffer;
                    using GLGeometryBatchBuilder::Callback::unmapBuffer;
                    using GLGeometryBatchBuilder::Callback::getElevation;
                    using GLGeometryBatchBuilder::Callback::getIcon;
                    using GLGeometryBatchBuilder::Callback::addLabel;
                    using GLGeometryBatchBuilder::Callback::reserveHitId;
                    using GLGeometryBatchBuilder::Callback2::addLabel;

                    /**
                     * Adds a label to the feature currently being processed.
                     */
                    virtual Util::TAKErr getMesh(std::shared_ptr<const TAK::Engine::Model::Mesh>& mesh, const char* uri) NOTHROWS = 0;
                };
            }
        }
    }
}

#endif
