#include "renderer/feature/GLGeometryBatchBuilder.h"

#include "core/ProjectionFactory3.h"
#include "feature/GeometryCollection.h"
#include "feature/GeometryFactory.h"
#include "feature/LegacyAdapters.h"
#include "feature/LineString.h"
#include "feature/ParseGeometry.h"
#include "feature/Polygon.h"
#include "feature/Style.h"
#include "raster/osm/OSMUtils.h"
#include "renderer/core/GLMapRenderGlobals.h"
#include "util/MathUtils.h"
#include "core/Datum2.h"

#include <vector>

using namespace TAK::Engine::Renderer::Feature;

using namespace TAK::Engine::Core;
using namespace TAK::Engine::Renderer;
using namespace TAK::Engine::Renderer::Core;
using namespace TAK::Engine::Util;

// 512kb
#define BUILDER_BUF_SIZE (512u*1024u)

namespace
{
    constexpr double _iconDeclutterRangeFactor = 2.0;

    /**
     * Bitmask for label processing.
     */
    enum ProcessLabelsMask
    {
        /** A label should be auto-generated if no explicit label style is provided */
        AutoGenerate = 0x1,
        /** A label should only be generated if an explicit label style is provided */
        ExplicitStyle = 0x2,
    };
    struct _PointBufferLayout {
        GLfloat position[3];            // 0...11
        GLfloat surfacePosition[3];     // 12..23
        GLshort rotation[2];            // 24..27
        GLushort spriteBottomLeft[2];   // 28..31
        GLushort spriteDimensions[2];   // 32..35
        GLfloat pointSize;              // 36..39
        GLubyte color[4];               // 40..43
        GLuint id;                      // 44..47
        GLubyte absoluteRotationFlag;   // 48..
        GLubyte minLod;                 // 49..
        GLubyte maxLod;                 // 50..
        GLubyte reserved[1u];           // 51..
        GLshort offset[2];              // 52..55
    };

    struct _LineBufferLayout {
        GLfloat position0[3];       // 0...11
        GLfloat position1[3];       // 12..23
        GLubyte color[4];           // 24..27
        GLuint id;                  // 28..31
        GLushort pattern;           // 32..33
        GLubyte cap[2];             // 34..35
        GLubyte factor;             // 36..
        GLubyte halfStrokeWidth;    // 37..
        GLubyte minLod;             // 38..
        GLubyte maxLod;             // 39..
        GLubyte radius;
        GLubyte reserved[3u];
    };

    struct _PolygonBufferLayout {
        GLfloat position[3];    // 0...11
        GLuint id;              // 12..15
        GLubyte color[4];       // 16..20
        GLubyte outlineWidth;   // 17..
        GLubyte exteriorVertex; // 18..
        GLubyte minLod;         // 19..
        GLubyte maxLod;         // 20..
    };

    struct _MeshBufferLayout {
        GLfloat vertexCoord[3];       // 0...11
        GLushort spriteBottomLeft[2]; // 12..15
        GLushort spriteTopRight[2];   // 16..19
        GLuint id;                    // 20..23
        GLubyte color[4];             // 24..27
        GLubyte minLod;               // 28..
        GLubyte maxLod;               // 29..
        GLubyte reserved[2u];         // 30..31
        GLfloat transform[16];        // 32..95
    };

    BatchGeometryBufferLayout layout;

    struct _Color
    {
        uint8_t r{ 0x0u };
        uint8_t g{ 0x0u };
        uint8_t b{ 0x0u };
        uint8_t a{ 0x0u };
    };

    struct FeatureStyle {
        struct {
            _Color stroke;
            _Color fill;
        } color;
        struct
        {
            float u0{ 0.f };
            float v0{ 0.f };
            float u1{ 0.f };
            float v1{ 0.f };
        } texCoords;
        GLuint texid{ GL_NONE };
        struct {
            std::size_t width{ 0u };
            std::size_t height{ 0u };
            float rotation{ 0.0f };
            bool isAbsoluteRotation{ false };
            TAK::Engine::Math::Point2<float> offset;
        } icon;
        struct {
            std::string meshUri;
            std::shared_ptr<const TAK::Engine::Model::Mesh> meshPtr;
            std::vector<float> transform;
        } mesh;
        struct {
            TAK::Engine::Port::String text;
            struct {
                double angle{ 0.0 };
                bool absolute{ false };
            } rotation;
            struct {
                unsigned int foreground{ 0xFFFFFFFFu };
                unsigned int background{ 0u };
            } color;
            struct {
                TextAlignment text{ TETA_Center };
                HorizontalAlignment horizontal{ TEHA_Center };
                VerticalAlignment vertical{ TEVA_Top };
            } alignment;
            double maxResolution{ 13.0 };
            TAK::Engine::Math::Point2<double> offset;
            TextFormatParams format{ TextFormatParams(nullptr, 0.f) };
        } label;
        struct {
            uint32_t pattern{ 0xFFFFFFFFu };
            uint16_t factor{ 0u };
            float width{ 1.0f };
            float arrowRadius{ 0.f };
            atakmap::feature::StrokeExtrusionMode extrude {atakmap::feature::TEEM_Vertex};
            atakmap::feature::ArrowHeadMode arrowHeadMode {atakmap::feature::TEAH_OnlyLast};
            bool endCap {true};
        } stroke;
        struct {
            std::size_t basicFill{ 0u };
            std::size_t basicPoint{ 0u };
            std::size_t basicStroke{ 0u };
            std::size_t icon{ 0u };
            std::size_t mesh{ 0u };
            std::size_t pattern{ 0u };
            std::size_t label{ 0u };
            std::size_t arrow{ 0u };
            std::size_t levelOfDetail{0u};
        } composite;
        struct {
            std::size_t minimum{ atakmap::feature::LevelOfDetailStyle::MIN_LOD };
            std::size_t maximum{ atakmap::feature::LevelOfDetailStyle::MAX_LOD };
        } levelOfDetail;
    };

    class CallbackAdapter : public GLGeometryBatchBuilder::Callback2
    {
    public :
        CallbackAdapter(GLGeometryBatchBuilder::Callback &cb_) :
            cb(cb_)
        {}
    public :
        TAKErr mapBuffer(GLuint *handle, void **buffer, const std::size_t size) NOTHROWS override
        {
            return cb.mapBuffer(handle, buffer, size);
        }
        TAKErr unmapBuffer(const GLuint handle) NOTHROWS override
        {
            return cb.unmapBuffer(handle);
        }
        TAKErr getElevation(double *value, const double latitude, const double longitude) NOTHROWS override
        {
            return cb.getElevation(value, latitude, longitude);
        }
        TAKErr getIcon(GLuint *id, float *u0, float *v0, float *u1, float *v1, std::size_t *w, std::size_t *h, float *rotation, bool *isAbsoluteRotation, const char* uri) NOTHROWS override
        {
            return cb.getIcon(id, u0, v0, u1, v1, w, h, rotation, isAbsoluteRotation, uri);
        }
        TAKErr addLabel(TAK::Engine::Renderer::Core::GLLabel &&label) NOTHROWS override
        {
            const GLLabel &clabel = label;
            return cb.addLabel(clabel);
        }
        TAKErr addLabel(const GLLabel &label) NOTHROWS override
        {
            return cb.addLabel(label);
        }
        uint32_t reserveHitId() NOTHROWS override
        {
            return cb.reserveHitId();
        }
    private :
        GLGeometryBatchBuilder::Callback &cb;
    };
    class CallbackAdapter2 : public GLGeometryBatchBuilder::Callback3
    {
    public :
        CallbackAdapter2(GLGeometryBatchBuilder::Callback2 &cb_) :
                cb(cb_)
        {}
    public :
        TAKErr mapBuffer(GLuint *handle, void **buffer, const std::size_t size) NOTHROWS override
        {
            return cb.mapBuffer(handle, buffer, size);
        }
        TAKErr unmapBuffer(const GLuint handle) NOTHROWS override
        {
            return cb.unmapBuffer(handle);
        }
        TAKErr getElevation(double *value, const double latitude, const double longitude) NOTHROWS override
        {
            return cb.getElevation(value, latitude, longitude);
        }
        TAKErr getIcon(GLuint *id, float *u0, float *v0, float *u1, float *v1, std::size_t *w, std::size_t *h, float *rotation, bool *isAbsoluteRotation, const char* uri) NOTHROWS override
        {
            return cb.getIcon(id, u0, v0, u1, v1, w, h, rotation, isAbsoluteRotation, uri);
        }
        TAKErr addLabel(TAK::Engine::Renderer::Core::GLLabel &&label) NOTHROWS override
        {
            return cb.addLabel(label);
        }
        TAKErr addLabel(const GLLabel &label) NOTHROWS override
        {
            return cb.addLabel(label);
        }
        uint32_t reserveHitId() NOTHROWS override
        {
            return cb.reserveHitId();
        }
        TAKErr getMesh(std::shared_ptr<const TAK::Engine::Model::Mesh>& mesh, const char* uri) NOTHROWS override
        {
            return TE_Unsupported;
        }
    private :
        GLGeometryBatchBuilder::Callback2 &cb;
    };

    TAK::Engine::Math::Point2<double> extrudeImpl(const TAK::Engine::Math::Point2<double> &p, const double extrude_, GLGeometryBatchBuilder::Callback& callback) NOTHROWS
    {
        double extrude = extrude_;
        if (extrude < 0.0) {
            double localel = NAN;
            callback.getElevation(&localel, p.y, p.x);
            if (TE_ISNAN(localel))
                localel = 0.0;
            extrude = localel - p.z;
        }
        return TAK::Engine::Math::Point2<double>(p.x, p.y, p.z + extrude);
    }

    struct PrimitiveLabels
    {
    public :
        PrimitiveLabels() NOTHROWS = default;
        PrimitiveLabels(PrimitiveLabels &&other) NOTHROWS
        {
            primary.pointer = other.primary.pointer;
            other.primary.pointer = nullptr;

        }
        // XXX-
        PrimitiveLabels(const PrimitiveLabels &other) NOTHROWS
        {
            // copy constructor does not take ownership
            primary.pointer = nullptr;
            if(other.primary.pointer)
                secondary.push_back(*other.primary.pointer);
            for(auto &s : other.secondary)
                secondary.push_back(s);
        }
        ~PrimitiveLabels() NOTHROWS
        {
            if(primary.pointer) {
                primary.pointer->~GLLabel();
                primary.pointer = nullptr;
            }
        }
    public :
        void push_back(GLLabel &&lbl) NOTHROWS
        {
            if(!primary.pointer) {
                primary() = std::move(lbl);
            } else {
                secondary.push_back(std::move(lbl));
            }
        }
        void pop_back() NOTHROWS
        {
            if(!secondary.empty()) {
                secondary.pop_back();
            } else if(primary.pointer) {
                primary.pointer->~GLLabel();
                primary.pointer = nullptr;
            }
        }
        GLLabel &back() NOTHROWS
        {
            return !secondary.empty() ? secondary.back() : primary();
        }
        bool empty() const NOTHROWS
        {
            return !primary.pointer;
        }
    private :
        // NOTE: construct of empty `GLLabel` is relatively expensive. Reserve the memory and
        // do lazy in-place new on demand
        struct {
            GLLabel *pointer{nullptr};
            uint8_t data[sizeof(GLLabel)];
            GLLabel &operator()() NOTHROWS
            {
                if(!pointer) pointer = new(data) GLLabel();
                return *pointer;
            }
        } primary;
        std::vector<GLLabel> secondary;
    };

    struct PrimitiveVertexAttributes
    {
        struct {
            /**
             * 1 - round cap, fill
             * 0 - butt cap
             * -1 - round cap, hole
             */
            int8_t cap{ 0 };
            bool first{ false };
            bool last{ false };
        } lines;
        struct
        {
            bool exterior{ false };
        } triangles;
        GeoPoint2 geoPoint;
    };

    struct VertexWriterImpl
    {
        // TODO-JGM: Don't understand why we're using a function pointer instead of a virtual method?
        TAKErr(*emitPrimitives)(MemoryOutput2 &sink, const FeatureStyle &style, const TAK::Engine::Math::Point2<float> *primitive, const uint32_t hitid, const PrimitiveVertexAttributes *attrs, const TAK::Engine::Math::Point2<double>& rtc) NOTHROWS { nullptr };

        std::size_t vertexSize{ 0u };
        struct {
            std::size_t in{ 0u };
            std::size_t out{ 0u };
        } verticesPerEmitPrimitives;
        GLenum mode{ GL_NONE };
        GLBatchGeometryRenderer4::Program type{ GLBatchGeometryRenderer4::Points };
        TAK::Engine::Feature::AltitudeMode altmode{ TAK::Engine::Feature::TEAM_ClampToGround };
    };

    struct VertexWriterContext
    {
        GLGeometryBatchBuilder *owner{ nullptr };
        GLGeometryBatchBuilder::BatchContext batchContext;
        double simplifyFactor{ 1e-15 };
        GLGeometryBatchBuilder::Callback3 *callback{ nullptr };
        VertexWriterImpl impl;
        FeatureStyle style;
        std::size_t bufsize{ BUILDER_BUF_SIZE };
        uint32_t hitid{ 0u };
        std::size_t batchedPrimitives{0u};
        PrimitiveLabels labels;
        // used for implicit labeling
        struct {
            std::size_t minLod {atakmap::feature::LevelOfDetailStyle::MIN_LOD};
            std::size_t maxLod {atakmap::feature::LevelOfDetailStyle::MAX_LOD};
            uint32_t backgroundColor {0x0u};
            bool overrideBackgroundColor {false};
        } labelDefaults;
        std::vector<TAK::Engine::Math::Rectangle2<double>> *iconOcclusionMask{nullptr};
    };

    // Point streaming

    /**
     * Streams the points of a geometry to the specified callback
     */
    class PointStream
    {
    public :
        class Callback
        {
        public :
            virtual void restart() NOTHROWS = 0;
            virtual void point(const TAK::Engine::Math::Point2<double>& value, const PrimitiveVertexAttributes &attr) NOTHROWS = 0;
        };
    public :
        /**
         * Begins streaming points to the specified callback.
         * @return TE_Ok on complete, TE_Done if no points were streamed; various codes on error
         */
        virtual TAKErr start(Callback &cb) NOTHROWS = 0;
        virtual TAKErr reset(PointStream& impl) NOTHROWS
        {
            return TE_Ok;
        }
    };
    // linestring > GL_LINE_STRIP
    class LineStringStripPointStream : public PointStream
    {
    public :
        LineStringStripPointStream(const atakmap::feature::LineString &linestring_) NOTHROWS :
            linestring(&linestring_)
        {}
        TAKErr start(Callback &cb) NOTHROWS override
        {
            const std::size_t pointCount = linestring->getPointCount();
            if (pointCount < 2u)
                return TE_Done;

            cb.restart();

            PrimitiveVertexAttributes attrs;
            const auto points = linestring->getPoints();
            if (linestring->getDimension() == 2) {
                for (std::size_t i = 0; i < pointCount; i++)
                    cb.point(TAK::Engine::Math::Point2<double>(points[i*2], points[i*2+1], 0.0), attrs);
            } else {
                for (std::size_t i = 0; i < pointCount; i++)
                    cb.point(TAK::Engine::Math::Point2<double>(points[i*3], points[i*3+1], points[i*3+2]), attrs);
            }
            return TE_Ok;
        }
    public :
        void reset(const atakmap::feature::LineString &linestring_) NOTHROWS
        {
            linestring = &linestring_;
        }
    private :
        const atakmap::feature::LineString *linestring;
    };

    class CrossTrackSimplifierstream : public PointStream
    {
    public:
        /**
         *
         * @param ps_
         * @param threshold_    Simplification threshold in DEGREES
         */
        CrossTrackSimplifierstream(PointStream &ps_, double threshold_) : ps(ps_), threshold(threshold_) {}
        TAKErr start(Callback &cb_) NOTHROWS override 
        {
            CB cb(cb_, threshold);
            TAKErr code = ps.start(cb);
            cb.flush();
            return code;

        }
        TAKErr reset(PointStream &ps_) NOTHROWS override
        { 
            ps = ps_;
            return TE_Ok;
        }

    private :
        struct CB : public Callback {
            CB(Callback &cb_, double threshold_) : cb(cb_), threshold(threshold_/180.0*M_PI) {}
            void restart() NOTHROWS override 
            {
                flush();
                cb.restart();
                numPoints = 0;
            }
            void point(const TAK::Engine::Math::Point2<double> &xyz, const PrimitiveVertexAttributes &attr_) NOTHROWS override 
            { 
                const auto &d = xyz;

                //invalid at poles
                if (d.x == 0 && (d.y == 90 || d.y == -90)) {
                    flush();
                    cb.point(d, attr_);
                }
                else if (numPoints == 0) {
                    a = xyz;
                    ++numPoints;
                    cb.point(a, attr_);
                }
                else if (numPoints == 1) {
                    b = xyz;
                    GeoPoint2 A(a.y, a.x);
                    GeoPoint2 B(b.y, b.x);

                    crs_AB = GeoPoint2_bearing(A, B, true) / 180.0 * M_PI;
                    ++numPoints;
                }
                else {
                    GeoPoint2 A(a.y, a.x);
                    GeoPoint2 B(b.y, b.x);
                    GeoPoint2 D(d.y, d.x);
                    const double crs_AD = GeoPoint2_bearing(A, D, true) / 180.0 * M_PI;
                    const double dist_AD = GeoPoint2_distance(A, D, true) / Datum2::WGS84.reference.semiMajorAxis;
                    const double dist_AB = GeoPoint2_distance(A, B, true) / Datum2::WGS84.reference.semiMajorAxis;
                    const double XTD = asin(sin(dist_AD) * sin(crs_AD - crs_AB));

                    if (fabs(XTD) < threshold && dist_AB < dist_AD) {
                        b = d;
                    }
                    else {
                        cb.point(b, attr_);
                        a = b;
                        b = d;
                        crs_AB = GeoPoint2_bearing(B, D, true) / 180.0 * M_PI;
                    }
                }
            }

            void flush() 
            { 
                PrimitiveVertexAttributes attr;
                if (numPoints == 2) 
                    cb.point(b, attr);
                numPoints = 0;
            }
            Callback &cb;
            std::size_t numPoints = 0;
            TAK::Engine::Math::Point2<double> a;
            TAK::Engine::Math::Point2<double> b;
            double crs_AB = 0;
            /** threshold in RADIANS */
            double threshold{1e-15};
        };

        PointStream &ps;
        double threshold;
    };

    // GL_LINE_STRIP > GL_LINES
    class LineStripSegmentizer : public PointStream
    {
    public :
        LineStripSegmentizer(PointStream &ps_, const TAK::Engine::Feature::AltitudeMode altMode, const bool endCaps_) NOTHROWS :
            ps(&ps_),
            cap((altMode == TAK::Engine::Feature::TEAM_ClampToGround) ? 1 : 0),
            endCaps(endCaps_)
        {}
        TAKErr start(Callback &cb_) NOTHROWS override
        {
            struct CB : public Callback
            {
            public :
                void restart() NOTHROWS override
                {
                    flush();
                    pointCount = 0u;
                    cb->restart();
                }
                void point(const TAK::Engine::Math::Point2<double> &xyz, const PrimitiveVertexAttributes& attr_) NOTHROWS override
                {
                    if(pointCount > 1u) {
                        // emit the segment. apply the cap to the _first_ point on the segment.
                        PrimitiveVertexAttributes attr(attr_);
                        attr.lines.cap = 1*cap;
                        attr.lines.first = (pointCount == 2u);
                        if(attr.lines.first && !endCaps)
                            attr.lines.cap = 0;
                        cb->point(segment.a, attr);
                        attr.lines.cap = -1*cap;
                        cb->point(segment.b, attr);
                    }
                    // push the new point
                    segment.a = segment.b;
                    segment.b = xyz;

                    pointCount++;
                }
                void flush()
                {
                    if (pointCount < 2u) return;
                    // emit the final buffered segment, both ends are capped
                    PrimitiveVertexAttributes attr;
                    attr.lines.cap = cap;
                    attr.lines.first = (pointCount == 2u);
                    if(attr.lines.first && !endCaps)
                        attr.lines.cap = 0;
                    cb->point(segment.a, attr);
                    attr.lines.cap = cap;
                    attr.lines.last = true;
                    if(attr.lines.last && !endCaps)
                        attr.lines.cap = 0;
                    cb->point(segment.b, attr);
                }
            public :
                Callback* cb{ nullptr };
                int cap{ 0 };
                bool endCaps{true};
            private:
                std::size_t pointCount{ 0u };
                struct {
                    TAK::Engine::Math::Point2<double> a;
                    TAK::Engine::Math::Point2<double> b;
                } segment;
            } cb;

            cb.cb = &cb_;
            cb.cap = cap;
            cb.endCaps = endCaps;

            TAKErr code = ps->start(cb);
            cb.flush();
            return code;
        }
    public :
        TAKErr reset(PointStream &ps_) NOTHROWS override
        {
            ps = &ps_;
            return TE_Ok;
        }
    private :
        PointStream *ps;
        const int8_t cap;
        bool endCaps;
    };
    // GL_LINE_STRIP > GL_LINE_STRIP
    class TessellatePointStream : public PointStream
    {
    public :
        TessellatePointStream(PointStream &ps_, const double threshold_) NOTHROWS :
            ps(&ps_),
            threshold(threshold_)
        {}
        TAKErr start(Callback &cb_) NOTHROWS override
        {
            struct CB : public Callback, public TessellateCallback
            {
            public :
            public : // PointStream::Callback
                void restart() NOTHROWS override
                {
                    pointCount = 0u;
                    cb->restart();
                }
                void point(const TAK::Engine::Math::Point2<double>& xyz, const PrimitiveVertexAttributes& attr) NOTHROWS override
                {
                    segment.a.xyz = segment.b.xyz;
                    segment.a.attrs = segment.b.attrs;
                    segment.b.xyz = xyz;
                    segment.b.attrs = attr;
                    pointCount++;
                    if (pointCount > 1u) {
                        // explicitly emit `a` if first line segment
                        if (pointCount == 2) cb->point(segment.a.xyz, segment.a.attrs);
                        // tessellate segment for remainder of points
                        double abxyz[6u];
                        abxyz[0] = segment.a.xyz.x;
                        abxyz[1] = segment.a.xyz.y;
                        abxyz[2] = segment.a.xyz.z;
                        abxyz[3] = segment.b.xyz.x;
                        abxyz[4] = segment.b.xyz.y;
                        abxyz[5] = segment.b.xyz.z;
                        VertexData ab;
                        ab.data = (void*)abxyz;
                        ab.size = 3u;
                        ab.stride = 3u * sizeof(double);
                        // reset segment first point marker flag
                        segment.first = true;
                        Tessellate_linestring<double>(*this, ab, 2u, threshold, Tessellate_WGS84Algorithm());
                    }
                }
            public : // TessellateCallback
                TAKErr point(const TAK::Engine::Math::Point2<double> &xyz) NOTHROWS override
                { 
                    // emit all tessellated points after the first
                    if (segment.first) segment.first = false;
                    else cb->point(xyz, segment.a.attrs);
                    return TE_Ok;
                }
            public :
                Callback* cb{ nullptr };
                double threshold{ 0.0 };
            private :
                std::size_t pointCount{ 0u };
                struct {
                    struct {
                        TAK::Engine::Math::Point2<double> xyz;
                        PrimitiveVertexAttributes attrs;
                    } a;
                    struct {
                        TAK::Engine::Math::Point2<double> xyz;
                        PrimitiveVertexAttributes attrs;
                    } b;
                    bool first{ true };
                } segment;
            } cb;

            cb.cb = &cb_;
            cb.threshold = threshold;

            return ps->start(cb);
        }
    public :
        TAKErr reset(PointStream &ps_) NOTHROWS override
        {
            ps = &ps_;
            return TE_Ok;
        }
    private :
        PointStream* ps;
        double threshold;
    };
    // GL_LINE_STRIP > GL_LINE_STRIP
    class HemisphereNormalizationPointStream : public PointStream
    {
    public :
        HemisphereNormalizationPointStream(PointStream &impl_) NOTHROWS :
            impl(&impl_)
        {}
        TAKErr start(Callback &cb_) NOTHROWS override
        {
            struct CB : public Callback
            {
            public :
                void restart() NOTHROWS override
                {
                    lastx = NAN;
                    // propagate same hemisphere for all starts
                    if (!inPrimaryHemi)
                        inPrimaryHemi = primaryHemi;
                    primaryHemi = inPrimaryHemi;
                    unwrap = 0.0;
                    cb->restart();
                }
                void point(const TAK::Engine::Math::Point2<double>& xyz_, const PrimitiveVertexAttributes& attr) NOTHROWS override
                {
                    // start of line segment
                    double ax = wrapLongitude(xyz_.x);
                    double ay = xyz_.y;
                    double az = xyz_.z;

                    if (TE_ISNAN(lastx)) {
                        lastx = ax;
                        if (inPrimaryHemi) {
                            if (ax >= 0.0 && inPrimaryHemi == -1) {
                                unwrap = -360.0;
                            } else if (ax < 0.0 && inPrimaryHemi == 1) {
                                unwrap = 360.0;
                            }
                        }
                    }

                    // check for IDL crossing -- any longitudinal span greater than
                    // 180 deg crosses
                    if (fabs(ax - lastx) > 180.0)
                    {
                        // capture IDL crossing, assign primary hemi
                        if (!primaryHemi)
                        {
                            primaryHemi = (lastx >= 0.0) ? 1 : -1;
                        }

                        // we were unwrapping, but have crossed back
                        if (unwrap != 0.0)
                            unwrap = 0.0;
                            // start wrapping east
                        else if (lastx >= 0.0)
                            unwrap = 360.0;
                            // start wrapping west
                        else
                            unwrap = -360.0;
                    }
                    // assign BEFORE unwrapping
                    lastx = ax;


                    cb->point(TAK::Engine::Math::Point2<double>(ax+unwrap, ay, az), attr);
                }
            private :
                double wrapLongitude(double longitude)
                {
                    if (longitude < -180.0) return longitude + 360;
                    else if (longitude > 180.0) return longitude - 360;
                    else return longitude;
                }
            public :
                Callback* cb{ nullptr };
                
                double lastx{ NAN };
                double unwrap{ 0.0 };
                int primaryHemi{ 0 };
                int inPrimaryHemi{ 0 };
            } cb;
            cb.cb = &cb_;
            cb.inPrimaryHemi = primaryHemi;

            const TAKErr code = impl->start(cb);
            primaryHemi = cb.primaryHemi;
            return code;
        }
    public :
        TAKErr reset(PointStream &impl_) NOTHROWS override
        {
            impl = &impl_;
            return TE_Ok;
        }
    public :
        /** 0 => autodetect, 1 => east, -1 => west */
        int primaryHemi{ 0 };
    private :
        PointStream *impl;
    };
    // linestring extrude GL_LINES > GL_TRIANGLES
    class QuadStripPointStream : public PointStream
    {
    public :
        QuadStripPointStream(PointStream &impl_, const double extrude_, GLGeometryBatchBuilder::Callback &callback_) NOTHROWS :
            impl(impl_),
            extrude(extrude_),
            callback(callback_)
        {
            reset(impl);
        }
        TAKErr start(Callback &cb) NOTHROWS override
        {
            struct ExtrudeToQuad : public Callback
            {
                void restart() NOTHROWS override
                {
                    emit = true;
                    cb->restart();
                }
                void point(const TAK::Engine::Math::Point2<double>& p, const PrimitiveVertexAttributes &attr) NOTHROWS override
                {
                    // select based on value of emit flag
                    if (emit)
                        p0 = p;
                    else
                        p1 = p;
                    // toggle
                    emit = !emit;

                    // extrude and emit two triangles
                    if (emit) {
                        /*
                        * p0----p1
                        * |\     |
                        * | \    |
                        * |  \   |
                        * |   \  |
                        * |    \ |
                        * p0'---p1'
                        * 
                        * { p0',p1',p0, p0,p1',p1 } 
                        */
                        const TAK::Engine::Math::Point2<double> p0ex = extrudeImpl(p0, extrude, *elevationFetcher);
                        const TAK::Engine::Math::Point2<double> p1ex = extrudeImpl(p1, extrude, *elevationFetcher);

                        cb->point(p0ex, attr);
                        cb->point(p1ex, attr);
                        cb->point(p0, attr);

                        cb->point(p0, attr);
                        cb->point(p1ex, attr);
                        cb->point(p1, attr);
                    }
                }
                TAK::Engine::Math::Point2<double> p0;
                TAK::Engine::Math::Point2<double> p1;
                bool emit{ true };
                GLGeometryBatchBuilder::Callback *elevationFetcher{ nullptr };
                Callback *cb{ nullptr };
                double extrude{ 0.0 };
            } extruder;
            extruder.elevationFetcher = &callback;
            extruder.extrude = extrude;
            extruder.cb = &cb;

            return impl.start(extruder);
        }
    public :
        TAKErr reset(PointStream &impl_) NOTHROWS override
        {
            impl = impl_;
            return TE_Ok;
        }
    private :
        PointStream &impl;
        double extrude;
        GLGeometryBatchBuilder::Callback &callback;
    };
    // polygon > linestring > GL_LINE_STRIP
    class PolygonLineStripPointStream : public PointStream
    {
    public :
        PolygonLineStripPointStream(const atakmap::feature::Polygon &polygon_) :
            polygon(&polygon_)
        {}
    public :
        TAKErr start(Callback &cb) NOTHROWS override
        {
            const auto rings = polygon->getRings();
            if (rings.first == rings.second)
                return TE_Done;
            for (auto it = rings.first; it != rings.second; it++) {
                const auto &ring = *it;
                LineStringStripPointStream ps(ring);
                ps.start(cb);                
            }
            return TE_Ok;
        }
    public :
        void reset(const atakmap::feature::Polygon& polygon_) NOTHROWS
        {
            polygon = &polygon_;
        }
    private :
        const atakmap::feature::Polygon *polygon;
    };
    // polygon (fill//triangles)
    // polygon (stroke//lines)
    class FillPolygonPointStream : public PointStream
    {
    public :
        FillPolygonPointStream(const atakmap::feature::Polygon &polygon_, const bool *cancelToken_) :
            polygon(&polygon_),
            cancelToken(cancelToken_),
            impl(nullptr)
        {}
        FillPolygonPointStream(const atakmap::feature::Polygon& polygon_, PointStream& impl_, const bool *cancelToken_) :
            polygon(&polygon_),
            cancelToken(cancelToken_),
            impl(&impl_)
        {}
    public :
        TAKErr start(Callback &cb) NOTHROWS override
        {
            const auto rings = polygon->getRings();
            if (rings.first == rings.second)
                return TE_Done;

            struct Tessellate : public TessellateCallback
            {
                TAKErr point(const TAK::Engine::Math::Point2<double>& xyz) NOTHROWS override
                {
                    return point(xyz, PrimitiveVertexAttributes());
                }
                TAKErr point(const TAK::Engine::Math::Point2<double>& xyz, const PrimitiveVertexAttributes &attr) NOTHROWS /*override*/
                {
                    impl->point(xyz, attr);
                    return TE_Ok;
                }
                Callback *impl{ nullptr };
            } tessellate;
            tessellate.impl = &cb;

            const size_t vertexSize = (rings.first->getDimension() == atakmap::feature::Geometry::_2D) ? 2u : 3u;
            std::vector<VertexData> ringsToTessellate;
            std::vector<int> ringSizes;
            for (auto ring = rings.first; ring != rings.second; ring++) {
                VertexData src;
                src.data = (void*)ring->getPoints();
                src.size = vertexSize;
                src.stride = src.size * sizeof(double);
                ringsToTessellate.push_back(src);
                ringSizes.push_back((int)ring->getPointCount());
            }

            return Tessellate_polygon<double>(tessellate, ringsToTessellate.data(), ringSizes.data(), (int)ringsToTessellate.size(), 0.0, Tessellate_CartesianAlgorithm(), cancelToken);
        }
    public :
        void reset(const atakmap::feature::Polygon& polygon_) NOTHROWS
        {
            polygon = &polygon_;
        }
    private :
        /**
         * Optional wrapper that may perform operations like segment extrusion,
         * relative alt adjustment, etc. May be set to `&ps` if none was
         * specified at construction.
         */
        PointStream *impl;
        const atakmap::feature::Polygon *polygon;
        const bool *cancelToken;
    };
    // polygon extruder (fill//triangles)
    // point
    class PointPointStream : public PointStream
    {
    public :
        PointPointStream(const atakmap::feature::Point& point_) NOTHROWS :
            point(point_)
        {}
    public :
        TAKErr start(Callback &cb) NOTHROWS override
        {
            PrimitiveVertexAttributes attributes;
            attributes.geoPoint.latitude = point.y;
            attributes.geoPoint.longitude = point.x;
            attributes.geoPoint.altitude = point.z;
            cb.point(TAK::Engine::Math::Point2<double>(point.x, point.y, point.z), attributes);
            return TE_Ok;
        }
    private :
        const atakmap::feature::Point &point;
    };
    // utility
    class RelativeAltPointStream : public PointStream
    {
    public :
        RelativeAltPointStream(PointStream &impl_, GLGeometryBatchBuilder::Callback &callback_) NOTHROWS :
            impl(impl_),
            callback(callback_)
        {}
        TAKErr start(Callback &cb) NOTHROWS override
        {
            struct AltAdjuster : public Callback
            {
                void restart() NOTHROWS override { cb->restart(); }
                void point(const TAK::Engine::Math::Point2<double>& p_, const PrimitiveVertexAttributes &attr_) NOTHROWS override
                {
                    TAK::Engine::Math::Point2<double> p(p_);
                    PrimitiveVertexAttributes attr(attr_);
                    double localel;
                    if (elevationFetcher->getElevation(&localel, p.y, p.x) == TE_Ok) {
                        if (TE_ISNAN(p.z))
                            p.z = localel;
                        else if (!TE_ISNAN(localel))
                            p.z += localel;
                        attr.geoPoint.altitude = p.z;
                    }
                    cb->point(p, attr);
                }
                GLGeometryBatchBuilder::Callback *elevationFetcher{ nullptr };
                Callback *cb{ nullptr };
            } altAdjuster;
            altAdjuster.elevationFetcher = &callback;
            altAdjuster.cb = &cb;

            return impl.start(altAdjuster);
        }
        TAKErr reset(PointStream& impl_) NOTHROWS override
        {
            impl = impl_;
            return TE_Ok;
        }
    private :
        PointStream &impl;
        GLGeometryBatchBuilder::Callback &callback;
    };
    /**
     * Adjusts all input `point.z` to match the elevation of the centroid of
     * the MBB of all input points
     */
    class RelativeBasePointStream : public PointStream
    {
    public :
        RelativeBasePointStream(PointStream &impl_, GLGeometryBatchBuilder::Callback &callback_) NOTHROWS :
            impl(impl_),
            callback(callback_)
        {}
        TAKErr start(Callback &cb) NOTHROWS override
        {
            struct BoundsDiscovery : public Callback
            {
                void restart() NOTHROWS override {}
                void point(const TAK::Engine::Math::Point2<double>& p, const PrimitiveVertexAttributes &attr) NOTHROWS override
                {
                    if (!n) {
                        mbb.minX = p.x;
                        mbb.minY = p.y;
                        mbb.minZ = p.z;
                        mbb.maxX = p.x;
                        mbb.maxY = p.y;
                        mbb.maxZ = p.z;
                    } else {
                        if (p.x < mbb.minX)     mbb.minX = p.x;
                        else if(p.x > mbb.maxX) mbb.maxX = p.x;
                        if (p.y < mbb.minY)     mbb.minY = p.y;
                        else if(p.y > mbb.maxY) mbb.maxY = p.y;
                        if (p.z < mbb.minZ)     mbb.minZ = p.z;
                        else if(p.z > mbb.maxZ) mbb.maxZ = p.z;
                    }
                    n++;
                }
                TAK::Engine::Feature::Envelope2 mbb;
                std::size_t n{ 0u };
            } bounds;

            // run first pass to discover the base altitude
            const TAKErr code = impl.start(bounds);
            TE_CHECKRETURN_CODE(code);
            
            struct AltAdjuster : public Callback
            {
                void restart() NOTHROWS override { cb->restart(); }
                void point(const TAK::Engine::Math::Point2<double>& p_, const PrimitiveVertexAttributes &attr_) NOTHROWS override
                {
                    TAK::Engine::Math::Point2<double> p(p_);
                    PrimitiveVertexAttributes attr(attr_);
                    if (TE_ISNAN(p.z))
                        p.z = baseElevation;
                    else if (!TE_ISNAN(baseElevation))
                        p.z += baseElevation;
                    attr.geoPoint.altitude = p.z;
                    cb->point(p, attr);
                }
                double baseElevation{ 0.0 };
                Callback *cb{ nullptr };
            } altAdjuster;
            altAdjuster.cb = &cb;
            callback.getElevation(&altAdjuster.baseElevation, (bounds.mbb.minY+bounds.mbb.maxY)/2.0, (bounds.mbb.minX+bounds.mbb.maxX)/2.0);

            // run second pass to adjust by base elevation
            return impl.start(altAdjuster);
        }
        TAKErr reset(PointStream& impl_) NOTHROWS override
        {
            impl = impl_;
            return TE_Ok;
        }
    private :
        PointStream &impl;
        GLGeometryBatchBuilder::Callback &callback;
    };
    class HeightOffsetPointStream : public PointStream
    {
    public :
        HeightOffsetPointStream(PointStream &impl_, GLGeometryBatchBuilder::Callback &callback_, const double offset_) NOTHROWS :
            impl(impl_),
            callback(callback_),
            offset(offset_)
        {}
        TAKErr start(Callback &cb) NOTHROWS override
        {
            struct AltAdjuster : public Callback
            {
                void restart() NOTHROWS override { cb->restart(); }
                void point(const TAK::Engine::Math::Point2<double>& p_, const PrimitiveVertexAttributes &attr_) NOTHROWS override
                {
                    TAK::Engine::Math::Point2<double> p(p_);
                    PrimitiveVertexAttributes attr(attr_);
                    p.z += offset;
                    attr.geoPoint.altitude = p.z;
                    cb->point(p, attr);
                }
                double offset{ 0.0 };
                Callback *cb{ nullptr };
            } altAdjuster;
            altAdjuster.cb = &cb;
            altAdjuster.offset = offset;

            // run second pass to adjust by base elevation
            return impl.start(altAdjuster);
        }
        TAKErr reset(PointStream& impl_) NOTHROWS override
        {
            impl = impl_;
            return TE_Ok;
        }
    private :
        PointStream &impl;
        GLGeometryBatchBuilder::Callback &callback;
        double offset;
    };
    class TerrainCollisionPointStream : public PointStream
    {
    public :
        TerrainCollisionPointStream(PointStream &impl_, GLGeometryBatchBuilder::Callback &callback_) NOTHROWS :
            impl(impl_),
            callback(callback_)
        {}
        TAKErr start(Callback &cb) NOTHROWS override
        {
            struct AltAdjuster : public Callback
            {
                void restart() NOTHROWS override { cb->restart(); }
                void point(const TAK::Engine::Math::Point2<double>& p_, const PrimitiveVertexAttributes &attr_) NOTHROWS override
                {
                    TAK::Engine::Math::Point2<double> p(p_);
                    PrimitiveVertexAttributes attr(attr_);
                    double localel = NAN;
                    if (elevationFetcher->getElevation(&localel, p.y, p.x) != TE_Ok || TE_ISNAN(localel))
                        localel = 0.0;
                    if (TE_ISNAN(p.z) || (p.z < localel))
                        p.z = localel;
                    attr.geoPoint.altitude = p.z;
                    cb->point(p, attr);
                }
                GLGeometryBatchBuilder::Callback *elevationFetcher{ nullptr };
                Callback *cb{ nullptr };
            } altAdjuster;
            altAdjuster.elevationFetcher = &callback;
            altAdjuster.cb = &cb;

            return impl.start(altAdjuster);
        }
        TAKErr reset(PointStream& impl_) NOTHROWS override
        {
            impl = impl_;
            return TE_Ok;
        }
    private :
        PointStream &impl;
        GLGeometryBatchBuilder::Callback &callback;
    };
    class EmptyPointStream : public PointStream
    {
    public :
        TAKErr start(Callback &cb) NOTHROWS override
        {
            return TE_Done;
        }
    };
    class SegmentExtruder : public PointStream
    {
    public :
        SegmentExtruder(PointStream &impl_, const double extrude_, const atakmap::feature::StrokeExtrusionMode mode_, GLGeometryBatchBuilder::Callback &callback_) NOTHROWS :
            impl(impl_),
            callback(callback_),
            extrude(extrude_),
            mode(mode_)
        {
            reset(impl);
        }
        TAKErr start(Callback &cb) NOTHROWS override
        {
            struct ExtrudeLines : public Callback
            {
                void restart() NOTHROWS override
                {
                    emit = true;
                    cb->restart();
                }
                void point(const TAK::Engine::Math::Point2<double>& p, const PrimitiveVertexAttributes &attr) NOTHROWS override
                {
                    // select based on value of emit flag
                    if (emit)
                        p0 = p;
                    else
                        p1 = p;
                    // toggle
                    emit = !emit;

                    // extrude and emit two triangles
                    if (emit) {
                        /*
                        * p0-------p1
                        * |         |
                        * p0'------p1'
                        *
                        * {p0',p0, p0,p1, p1,p1', p1',p0'}
                        */
                        const TAK::Engine::Math::Point2<double> p0ex = extrudeImpl(p0, extrude, *elevationFetcher);
                        const TAK::Engine::Math::Point2<double> p1ex = extrudeImpl(p1, extrude, *elevationFetcher);

                        if(mode == atakmap::feature::TEEM_Vertex) {
                            cb->point(p0ex, attr);
                            cb->point(p0, attr);
                        }

                        cb->point(p0, attr);
                        cb->point(p1, attr);

                        if(mode == atakmap::feature::TEEM_Vertex) {
                            cb->point(p1, attr);
                            cb->point(p1ex, attr);
                        }
                        
                        cb->point(p1ex, attr);
                        cb->point(p0ex, attr);
                    }
                }
                TAK::Engine::Math::Point2<double> p0;
                TAK::Engine::Math::Point2<double> p1;
                bool emit{ true };
                GLGeometryBatchBuilder::Callback *elevationFetcher{ nullptr };
                Callback *cb{ nullptr };
                double extrude{ 0.0 };
                atakmap::feature::StrokeExtrusionMode mode {atakmap::feature::TEEM_Vertex};

            } linesExtruder;
            linesExtruder.elevationFetcher = &callback;
            linesExtruder.extrude = extrude;
            linesExtruder.cb = &cb;
            linesExtruder.mode = mode;

            return impl.start(linesExtruder);
        }
    public :
        TAKErr reset(PointStream& impl_) NOTHROWS override
        {
            impl = impl_;
            return TE_Ok;
        }
    private :
        PointStream &impl;
        GLGeometryBatchBuilder::Callback &callback;
        const double extrude;
        const atakmap::feature::StrokeExtrusionMode mode;
    };
    class PointExtruder : public PointStream
    {
    public :
        PointExtruder(PointStream &impl_, const double extrude_, GLGeometryBatchBuilder::Callback &callback_) NOTHROWS :
            impl(impl_),
            callback(callback_),
            extrude(extrude_)
        {
            reset(impl);
        }
        TAKErr start(Callback &cb) NOTHROWS override
        {
            struct ExtrudePoint : public Callback
            {
                void restart() NOTHROWS override { cb->restart(); }
                void point(const TAK::Engine::Math::Point2<double>& p, const PrimitiveVertexAttributes &attr_) NOTHROWS override
                {
                    const TAK::Engine::Math::Point2<double> pex = extrudeImpl(p, extrude, *elevationFetcher);
                    PrimitiveVertexAttributes attrex(attr_);
                    cb->point(p, attr_);
                    attrex.geoPoint.altitude = pex.z;
                    cb->point(pex, attrex);
                }
                GLGeometryBatchBuilder::Callback *elevationFetcher{ nullptr };
                Callback *cb{ nullptr };
                double extrude{ 0.0 };
            } linesExtruder;
            linesExtruder.elevationFetcher = &callback;
            linesExtruder.extrude = extrude;
            linesExtruder.cb = &cb;

            return impl.start(linesExtruder);
        }
    public :
        TAKErr reset(PointStream& impl_) NOTHROWS override
        {
            impl = impl_;
            return TE_Ok;
        }
    private :
        PointStream &impl;
        GLGeometryBatchBuilder::Callback &callback;
        const double extrude;
    };

    class LabelingPointStream : public PointStream
    {
    public :
        LabelingPointStream(PointStream &impl_, VertexWriterContext &callback_) :
            impl(&impl_),
            callback(callback_)
        {}
    public :
        TAKErr start(Callback &cb) NOTHROWS override
        {
            struct Labeler : public Callback
            {
                void restart() NOTHROWS override { cb->restart(); }
                void point(const TAK::Engine::Math::Point2<double>& p, const PrimitiveVertexAttributes &attr) NOTHROWS override
                {
                    if(geometry.numPoints < 2) {
                        geometry.points[geometry.numPoints] = p;
                    } else if(geometry.numPoints == 2u) {
                        // transfer to overflow
                        geometry.overflow = TAK::Engine::Feature::LineString2Ptr(new TAK::Engine::Feature::LineString2(), Memory_deleter_const<TAK::Engine::Feature::LineString2>);
                        geometry.overflow->setDimension(3);
                        for(std::size_t i = 0u; i < geometry.numPoints; i++)
                            geometry.overflow->addPoint(geometry.points[i].x, geometry.points[i].y, geometry.points[i].z);
                        geometry.overflow->addPoint(p.x, p.y, p.z);
                    } else {
                        geometry.overflow->addPoint(p.x, p.y, p.z);
                    }
                    geometry.numPoints++;
                    cb->point(p, attr);
                }
                TAKErr setGeometry(GLLabel &label) NOTHROWS
                {
                    if (!geometry.numPoints) {
                        return TE_Done;
                    } else if(geometry.numPoints == 1) {
                        label.setGeometry(
                            TAK::Engine::Feature::Point2(
                                geometry.points[0].x,
                                geometry.points[0].y,
                                geometry.points[0].z));
                    } else if (geometry.numPoints == 2) {
                        TAK::Engine::Feature::LineString2 segment;
                        segment.setDimension(3u);
                        for(std::size_t i = 0u; i < geometry.numPoints; i++)
                            segment.addPoint(geometry.points[i].x, geometry.points[i].y, geometry.points[i].z);
                        label.setGeometry(segment);
                    } else {
                        label.setGeometry(*geometry.overflow);
                    }
                    return TE_Ok;
                }
                Callback *cb{ nullptr };
                struct {
                    TAK::Engine::Math::Point2<double> points[2u];
                    std::size_t numPoints{ 0u };
                    TAK::Engine::Feature::LineString2Ptr overflow{nullptr, nullptr};
                } geometry;
            } labeler;
            labeler.cb = &cb;

            TAKErr code;
            if(didRun) {
                code = impl->start(cb);
            } else {
                code = impl->start(labeler);
                // flush labels
                while(!labels.empty()) {
                    GLLabel &lbl = labels.back();
                    if(labeler.setGeometry(lbl) == TE_Ok)
                        callback.labels.push_back(std::move(lbl));
                    labels.pop_back();
                }
                didRun = true;
            }
            return code;
        }
        TAKErr reset(PointStream& impl_) NOTHROWS override
        {
            impl = &impl_;
            return TE_Ok;
        }
    private :
        PointStream* impl{ nullptr };
        VertexWriterContext &callback;
        bool didRun{ false };
    public :
        PrimitiveLabels labels;
    };

    struct AntiAliasVertexWriter : public VertexWriterImpl
    {
        AntiAliasVertexWriter()
        {
            vertexSize = 36u;
            verticesPerEmitPrimitives.in = 2u;
            verticesPerEmitPrimitives.out = 1u;
            mode = GL_TRIANGLES;
            emitPrimitives = emitPrimitivesImpl;
            type = GLBatchGeometryRenderer4::AntiAliasedLines;
        }
    private :
        using Point = TAK::Engine::Math::Point2<float>;
        static void writeLineVertex(MemoryOutput2 &sink, const FeatureStyle &style, const Point &start, const Point &end, const int8_t *cap, const uint32_t hitid, const float radius)  NOTHROWS
        {
/*
    struct _LineBufferLayout {
        GLfloat position0[3];       // 0...11
        GLfloat position1[3];       // 12..23
        GLubyte color[4];           // 24..27
        GLuint id;                  // 28..31
        GLushort pattern;           // 32..33
        GLubyte cap[2];             // 34..35
        GLubyte factor;             // 36..
        GLubyte halfStrokeWidth;    // 37..
        GLubyte minLod;             // 38..
        GLubyte maxLod;             // 39..
    };
*/
            sink.writeFloat(start.x);
            sink.writeFloat(start.y);
            sink.writeFloat(start.z);
            sink.writeFloat(end.x);
            sink.writeFloat(end.y);
            sink.writeFloat(end.z);
            sink.writeByte(style.color.stroke.r);
            sink.writeByte(style.color.stroke.g);
            sink.writeByte(style.color.stroke.b);
            sink.writeByte(style.color.stroke.a);
            sink.writeInt(hitid);
            sink.writeShort(style.stroke.factor ? static_cast<uint16_t>(style.stroke.pattern) : 0xFFFFu);
            sink.writeByte(cap[0u]);
            sink.writeByte((style.composite.arrow && radius) ? 0u : cap[1u]);
            sink.writeByte(style.stroke.factor ? static_cast<uint8_t>(style.stroke.factor) : 0x1u);
            // NOTE: width is passed as byte, so ensure range [1,255]
            sink.writeByte(static_cast<uint8_t>(MathUtils_clamp(style.stroke.width/2.f, 1.0f, 255.0f)));
            sink.writeByte((uint8_t)style.levelOfDetail.minimum);
            sink.writeByte((uint8_t)style.levelOfDetail.maximum);

            sink.writeByte(static_cast<uint8_t>(radius));
            // padding
            sink.skip(3u);
        }
        static TAKErr emitPrimitivesImpl(MemoryOutput2 &sink, const FeatureStyle &style, const TAK::Engine::Math::Point2<float> *primitive, const uint32_t hitid, const PrimitiveVertexAttributes *attrs, const TAK::Engine::Math::Point2<double>& rtc) NOTHROWS
        {
            const TAK::Engine::Math::Point2<float> a(primitive[0]);
            const TAK::Engine::Math::Point2<float> b(primitive[1]);
            int8_t cap[3];
            cap[0] = !!attrs ? attrs[0].lines.cap : 0;
            cap[1] = !!attrs ? attrs[1].lines.cap : 0;
            cap[2] = !!attrs ? attrs[0].lines.cap : 0;
            bool perVertex = style.stroke.arrowHeadMode == atakmap::feature::TEAH_PerVertex;
            float radius = perVertex || (!!attrs && attrs[1].lines.last) ?
                MathUtils_clamp(style.stroke.arrowRadius, 0.0f, 255.0f) :
                0.0f;
            writeLineVertex(sink, style, a, b, cap, hitid, radius);

            return TE_Ok;
        }
    };

    struct PointSpriteVertexWriter : public VertexWriterImpl
    {
    public :
        PointSpriteVertexWriter() NOTHROWS
        {
            vertexSize = POINT_VERTEX_SIZE;
            verticesPerEmitPrimitives.in =  2u;
            verticesPerEmitPrimitives.out =  1u;
            mode = GL_POINTS;
            emitPrimitives = emitPrimitivesImpl;
            type = GLBatchGeometryRenderer4::Points;
        }
    private :
        static TAKErr emitPrimitivesImpl(MemoryOutput2 &sink, const FeatureStyle &style, const TAK::Engine::Math::Point2<float> *primitive, const uint32_t hitid, const PrimitiveVertexAttributes *attrs, const TAK::Engine::Math::Point2<double>& rtc) NOTHROWS
        {
            sink.writeFloat(primitive[0].x);
            sink.writeFloat(primitive[0].y);
            sink.writeFloat(primitive[0].z);
            sink.writeFloat(primitive[1].x);
            sink.writeFloat(primitive[1].y);
            sink.writeFloat(primitive[1].z);
            sink.writeShort((int16_t)((style.icon.rotation / (2 * M_PI)) * 0x7FFF));
            sink.writeShort((int16_t)((style.icon.rotation / (2 * M_PI)) * 0x7FFF));
            sink.writeShort((int16_t)(style.texCoords.u0*0xFFFFu));
            sink.writeShort((int16_t)(style.texCoords.v0*0xFFFFu));
            sink.writeShort((int16_t)(style.texCoords.u1*0xFFFFu));
            sink.writeShort((int16_t)(style.texCoords.v1*0xFFFFu));
            sink.writeFloat((float)std::max(style.icon.width, style.icon.height));
            sink.writeByte(style.color.fill.r);
            sink.writeByte(style.color.fill.g);
            sink.writeByte(style.color.fill.b);
            sink.writeByte(style.color.fill.a);
            sink.writeInt(hitid);
            sink.writeByte(style.icon.isAbsoluteRotation ? 0x1u : 0x0);
            sink.writeByte((uint8_t)style.levelOfDetail.minimum);
            sink.writeByte((uint8_t)style.levelOfDetail.maximum);
            sink.writeByte(0x0); // reserved
            sink.writeShort((short)style.icon.offset.x);
            sink.writeShort((short)style.icon.offset.y);
            return TE_Ok;
        }
    };

    TAKErr enu2ecef_transform(TAK::Engine::Math::Matrix2 &value, GeoPoint2 geoPoint) NOTHROWS
    {
        TAKErr code(TE_Ok);

        TAK::Engine::Math::Matrix2 mx;

        TAK::Engine::Math::Point2<double> pointD(0.0, 0.0, 0.0);
        GeoPoint2 geo;

        // transform origin to ECEF
        geo.latitude = geoPoint.latitude;
        geo.longitude = geoPoint.longitude;
        geo.altitude = geoPoint.altitude;
        geo.altitudeRef = AltitudeReference::HAE;

        Projection2Ptr ecef(nullptr, nullptr);
        code = ProjectionFactory3_create(ecef, 4978);
        TE_CHECKRETURN_CODE(code)

        code = ecef->forward(&pointD, geo);
        TE_CHECKRETURN_CODE(code)

        // construct ENU -> ECEF
        const double phi = atakmap::math::toRadians(geo.latitude);
        const double lambda = atakmap::math::toRadians(geo.longitude);

        mx.translate(pointD.x, pointD.y, pointD.z);

        TAK::Engine::Math::Matrix2 enu2ecef(
                -sin(lambda), -sin(phi)*cos(lambda), cos(phi)*cos(lambda), 0.0,
                cos(lambda), -sin(phi)*sin(lambda), cos(phi)*sin(lambda), 0.0,
                0, cos(phi), sin(phi), 0.0,
                0.0, 0.0, 0.0, 1.0
        );

        mx.concatenate(enu2ecef);

        value.set(mx);
        return code;
    }

    struct PointMeshVertexWriter : public VertexWriterImpl
    {
    public :
        PointMeshVertexWriter() NOTHROWS
        {
            vertexSize = MESH_VERTEX_SIZE;
            verticesPerEmitPrimitives.in =  2u;
            verticesPerEmitPrimitives.out =  1u;
            mode = GL_POINTS;
            emitPrimitives = emitPrimitivesImpl;
            type = GLBatchGeometryRenderer4::Meshes;
        }
    private :
        static TAKErr emitPrimitivesImpl(MemoryOutput2 &sink, const FeatureStyle &style, const TAK::Engine::Math::Point2<float> *primitive, const uint32_t hitid, const PrimitiveVertexAttributes *attrs, const TAK::Engine::Math::Point2<double>& rtc) NOTHROWS
        {
            sink.writeFloat(primitive[0].x);
            sink.writeFloat(primitive[0].y);
            sink.writeFloat(primitive[0].z);
            sink.writeShort((int16_t)(style.texCoords.u0*0xFFFFu));
            sink.writeShort((int16_t)(style.texCoords.v0*0xFFFFu));
            sink.writeShort((int16_t)(style.texCoords.u1*0xFFFFu));
            sink.writeShort((int16_t)(style.texCoords.v1*0xFFFFu));
            sink.writeInt(hitid);
            sink.writeByte(style.color.fill.r);
            sink.writeByte(style.color.fill.g);
            sink.writeByte(style.color.fill.b);
            sink.writeByte(style.color.fill.a);
            sink.writeByte((uint8_t)style.levelOfDetail.minimum);
            sink.writeByte((uint8_t)style.levelOfDetail.maximum);
            sink.skip(2u); // reserved

            TAK::Engine::Math::Matrix2 local(
                    style.mesh.transform[0],
                    style.mesh.transform[1],
                    style.mesh.transform[2],
                    style.mesh.transform[3],
                    style.mesh.transform[4],
                    style.mesh.transform[5],
                    style.mesh.transform[6],
                    style.mesh.transform[7],
                    style.mesh.transform[8],
                    style.mesh.transform[9],
                    style.mesh.transform[10],
                    style.mesh.transform[11],
                    style.mesh.transform[12],
                    style.mesh.transform[13],
                    style.mesh.transform[14],
                    style.mesh.transform[15]
                    );

            TAK::Engine::Math::Matrix2 enu2ecef;
            enu2ecef_transform(enu2ecef, attrs->geoPoint);

            TAK::Engine::Math::Matrix2 transform;
            transform.translate(-rtc.x, -rtc.y, -rtc.z);
            transform.concatenate(enu2ecef);
            transform.concatenate(local);
            double matrixD[16];
            transform.get(matrixD, TAK::Engine::Math::Matrix2::COLUMN_MAJOR);
            sink.writeFloat((float)matrixD[0]);
            sink.writeFloat((float)matrixD[1]);
            sink.writeFloat((float)matrixD[2]);
            sink.writeFloat((float)matrixD[3]);

            sink.writeFloat((float)matrixD[4]);
            sink.writeFloat((float)matrixD[5]);
            sink.writeFloat((float)matrixD[6]);
            sink.writeFloat((float)matrixD[7]);

            sink.writeFloat((float)matrixD[8]);
            sink.writeFloat((float)matrixD[9]);
            sink.writeFloat((float)matrixD[10]);
            sink.writeFloat((float)matrixD[11]);

            sink.writeFloat((float)matrixD[12]);
            sink.writeFloat((float)matrixD[13]);
            sink.writeFloat((float)matrixD[14]);
            sink.writeFloat((float)matrixD[15]);

            return TE_Ok;
        }
    };

    struct PolygonVertexWriter : public VertexWriterImpl
    {
    public :
        PolygonVertexWriter() NOTHROWS
        {
            vertexSize = POLYGON_VERTEX_SIZE;
            verticesPerEmitPrimitives.in = 3u;
            verticesPerEmitPrimitives.out = 3u;
            emitPrimitives = emitPrimitivesImpl;
            mode = GL_TRIANGLES;
            type = GLBatchGeometryRenderer4::Polygons;
        }
    private :
        static TAKErr emitPrimitivesImpl(MemoryOutput2 &sink, const FeatureStyle &style, const TAK::Engine::Math::Point2<float> *primitive, const uint32_t hitid, const PrimitiveVertexAttributes *attrs, const TAK::Engine::Math::Point2<double>& rtc) NOTHROWS
        {
#if 0
    struct _PolygonBufferLayout {
        GLfloat position0[3];
        GLuint id;
        GLubyte color[4];
        GLubyte outlineWidth;
        GLubyte exteriorVertex;
        GLubyte minLod;
        GLubyte maxLod;
    };
#endif
            for (std::size_t i = 0; i < 3u; i++) {
                sink.writeFloat(primitive[i].x);
                sink.writeFloat(primitive[i].y);
                sink.writeFloat(primitive[i].z);
                sink.writeInt(hitid);
                sink.writeByte(style.color.fill.r);
                sink.writeByte(style.color.fill.g);
                sink.writeByte(style.color.fill.b);
                sink.writeByte(style.color.fill.a);
                sink.writeByte((uint8_t)std::max(style.stroke.width, 255.0f));
                // https://community.khronos.org/t/how-do-i-draw-a-polygon-with-a-1-2-or-n-pixel-inset-outline-in-opengl-4-1/104201
                // The aExteriorVertex attribute should be 0.0 for exterior vertices and 1.0 for interior vertices.
                // The opposite was assumed to be true, which is why the commented out line is inverted
                // TODO: rename `exteriorVertices` to `interiorVertices`
                // TODO: determine if this is an exterior vertex
                //sink.writeByte(!exteriorVertices[i] ? 0x1u : 0x0u);
                sink.writeByte(0x1u);
                sink.writeByte((uint8_t)style.levelOfDetail.minimum);
                sink.writeByte((uint8_t)style.levelOfDetail.maximum);
            }

            return TE_Ok;
        }
    };

    const atakmap::feature::Style &getDefaultLinestringStyle() NOTHROWS;
    const atakmap::feature::Style &getDefaultPolygonStyle() NOTHROWS;
    const atakmap::feature::Style &getDefaultPointStyle() NOTHROWS;

    float luminance(unsigned int argb) NOTHROWS
    {
        const auto color_r = (argb>>24u)&0xFFu;
        const auto color_g = (argb>>16u)&0xFFu;
        const auto color_b = argb&0xFFu;

        return 0.2126f * color_r + 0.7152f * color_g + 0.0722f * color_b;
    }

    TAKErr push(VertexWriterContext &ctx, const std::function<const char *()> &featureNameAccess, const atakmap::feature::Geometry& geom, const double extrude, const TAK::Engine::Feature::AltitudeMode altmode, const atakmap::feature::Style *style, const ProcessLabelsMask processLabels, const GLGeometryBatchBuilder::PushHints hints) NOTHROWS;

    TAKErr flushPrimitives(VertexWriterContext &ctx, const atakmap::feature::Geometry &geom, const double extrude, const TAK::Engine::Feature::AltitudeMode altmode, const GLGeometryBatchBuilder::PushHints hints) NOTHROWS;
    bool GLGeometryBatchBuilder_init() NOTHROWS;
}

class GLGeometryBatchBuilder::VertexWriter : public PointStream::Callback
{
public :
    void setError() NOTHROWS;
    void restart() NOTHROWS override {}
    void point(const TAK::Engine::Math::Point2<double>& p_, const PrimitiveVertexAttributes &attr) NOTHROWS override;
public :
    VertexWriterContext *ctx{ nullptr };
    TAK::Engine::Math::Point2<float> primitive[6u];
    PrimitiveVertexAttributes vertexAttributes[6u];
    std::size_t idx{ 0u };
    bool error{ false };
};

GLGeometryBatchBuilder::GLGeometryBatchBuilder() NOTHROWS :
    callback(nullptr)
{
    static bool clinit = GLGeometryBatchBuilder_init();
}
GLGeometryBatchBuilder::~GLGeometryBatchBuilder() NOTHROWS
{}
 
TAKErr GLGeometryBatchBuilder::reset(const int surfaceSrid_, const int spritesSrid_, const GeoPoint2& relativeToCenter_, const double resolution_, Callback& callback_) NOTHROWS
{
    CallbackAdapter cb2(callback_);
    return reset(surfaceSrid_, spritesSrid_, relativeToCenter_, resolution_, static_cast<Callback2&>(cb2));
}
TAKErr GLGeometryBatchBuilder::reset(const int surfaceSrid_, const int spritesSrid_, const GeoPoint2 &relativeToCenter_, const double resolution_, Callback2 &callback_) NOTHROWS
{
    CallbackAdapter2 cb2(callback_);
    return reset(surfaceSrid_, spritesSrid_, relativeToCenter_, resolution_, static_cast<Callback3&>(cb2));
}
TAKErr GLGeometryBatchBuilder::reset(const int surfaceSrid_, const int spritesSrid_, const GeoPoint2 &relativeToCenter_, const double resolution_, Callback3 &callback_) NOTHROWS
{
    BatchContext bc;
    bc.surfaceSrid = surfaceSrid_;
    bc.spritesSrid = spritesSrid_;
    bc.relativeToCenter = relativeToCenter_;
    bc.resolution.scene = resolution_;
    return reset(bc, callback_);
}
TAKErr GLGeometryBatchBuilder::reset(const BatchContext &batchContext_, Callback3 &callback_) NOTHROWS
{
    TAKErr code(TE_Ok);
    code = ProjectionFactory3_create(proj.surface, batchContext_.surfaceSrid);
    TE_CHECKRETURN_CODE(code);
    code = ProjectionFactory3_create(proj.sprites, batchContext_.spritesSrid);
    TE_CHECKRETURN_CODE(code);

    // unmap any mapped buffers (warn, none should be mapped); this gets done before callback is reassigned
    bool warn = false;
    auto unmapFunc = [this, &warn](Builder* builder)
    {
        if (builder->pb.count) {
            warn |= true;
            callback->unmapBuffer(builder->pb.vbo);
        }

        // reset
        builder->pb = GLBatchGeometryRenderer4::PrimitiveBuffer();
    };
    unmapFunc(&builders.sprites.antiAliasedLines);
    unmapFunc(&builders.sprites.arrows);
    unmapFunc(&builders.sprites.lines);
    unmapFunc(&builders.sprites.polygons);
    unmapFunc(&builders.sprites.strokedPolygons);
    unmapFunc(&builders.sprites.points);
    for (auto &item: builders.sprites.meshes) unmapFunc(&item.second);
    unmapFunc(&builders.surface.antiAliasedLines);
    unmapFunc(&builders.surface.arrows);
    unmapFunc(&builders.surface.lines);
    unmapFunc(&builders.surface.polygons);
    unmapFunc(&builders.surface.strokedPolygons);
    unmapFunc(&builders.surface.points);

    if (warn) {
        Logger_log(TELL_Warning, "GLBatchGeometryBuilder::reset() encountered unflushed buffer data, VBO leaked.");
    }

    builders.sprites.meshes.clear();

    buffers.sprites.antiAliasedLines.clear();
    buffers.sprites.arrows.clear();
    buffers.sprites.lines.clear();
    buffers.sprites.polygons.clear();
    buffers.sprites.strokedPolygons.clear();
    buffers.sprites.points.clear();
    buffers.sprites.meshes.clear();
    buffers.surface.antiAliasedLines.clear();
    buffers.surface.arrows.clear();
    buffers.surface.lines.clear();
    buffers.surface.polygons.clear();
    buffers.surface.strokedPolygons.clear();
    buffers.surface.points.clear();

    batchContext = batchContext_;
    if(TE_ISNAN(batchContext.resolution.tessellate))
        batchContext.resolution.tessellate = batchContext.resolution.scene;
    proj.surface->forward(&relativeToCenter.surface, batchContext.relativeToCenter);
    proj.sprites->forward(&relativeToCenter.sprites, batchContext.relativeToCenter);
    simplifyFactor = (batchContext.resolution.scene /
                      TAK::Engine::Core::GeoPoint2_approximateMetersPerDegreeLatitude(batchContext.relativeToCenter.latitude));
    iconOcclusionMask.clear();
    callback = &callback_;
    return TE_Ok;
}
TAKErr GLGeometryBatchBuilder::push(TAK::Engine::Feature::FeatureDefinition2 &def, const bool processLabels, const bool forceClampToGround) NOTHROWS
{
    unsigned pushHints = 0u;
    if(processLabels)
        pushHints |= PushHints::ProcessLabels;
    if(forceClampToGround)
        pushHints |= PushHints::ForceClampToGround;
    return push(def, (PushHints)pushHints);
}
TAKErr GLGeometryBatchBuilder::push(TAK::Engine::Feature::FeatureDefinition2 &def, const PushHints pushHints) NOTHROWS
{
    TAKErr code(TE_Ok);
    if (!this->callback)
        return TE_IllegalState;
    VertexWriterContext ctx;
    ctx.owner = this;
    ctx.batchContext = batchContext;
    ctx.simplifyFactor = simplifyFactor;
    ctx.callback = this->callback;
    ctx.bufsize = BUILDER_BUF_SIZE;
    ctx.hitid = callback->reserveHitId();
    ctx.labelDefaults.backgroundColor = labelDefaults.backgroundColor;
    ctx.labelDefaults.overrideBackgroundColor = labelDefaults.overrideBackgroundColor;
    ctx.labelDefaults.minLod = labelDefaults.minLod;
    ctx.labelDefaults.maxLod = labelDefaults.maxLod;
    ctx.style.label.color.background = ctx.labelDefaults.backgroundColor;
    ctx.iconOcclusionMask = &iconOcclusionMask;
    TAK::Engine::Feature::FeatureDefinition2::RawData rawStyle;
    def.getRawStyle(&rawStyle);
    if ((pushHints&SkipNoStyleFeatures) && !(rawStyle.object || rawStyle.text))
        return TE_Ok;
    const atakmap::feature::Style *style = nullptr;
    switch (def.getStyleCoding()) {
    case TAK::Engine::Feature::FeatureDefinition2::StyleStyle :
        style = static_cast<const atakmap::feature::Style*>(rawStyle.object);
        break;
    case TAK::Engine::Feature::FeatureDefinition2::StyleOgr :
        if (rawStyle.text) {
            const auto &entry = parsedStyles.find(rawStyle.text);
            if (entry != parsedStyles.end()) {
                style = entry->second.get();
            } else {
                TAK::Engine::Feature::StylePtr_const parsed(nullptr, nullptr);
                atakmap::feature::Style_parseStyle(parsed, rawStyle.text);
                style = parsed.get();
                parsedStyles.insert(std::make_pair(rawStyle.text, std::move(parsed)));
            }
        }
        break;
    default :
        break;
    }
    TAK::Engine::Feature::FeatureDefinition2::RawData rawGeom;
    def.getRawGeometry(&rawGeom);
    TAK::Engine::Feature::GeometryPtr_const geom(nullptr, nullptr);
    atakmap::feature::Point point(NAN, NAN, NAN);
    switch (def.getGeomCoding()) {
    case TAK::Engine::Feature::FeatureDefinition2::GeomGeometry :
        geom = TAK::Engine::Feature::GeometryPtr_const(static_cast<const atakmap::feature::Geometry*>(rawGeom.object), Memory_leaker_const<atakmap::feature::Geometry>);
        break;
    case TAK::Engine::Feature::FeatureDefinition2::GeomBlob :
        if (rawGeom.binary.len) {
            using namespace TAK::Engine::Feature;
            do {
                GeometryClass gc;
                if(GeometryFactory_getSpatiaLiteBlobGeometryType(&gc, nullptr, rawGeom.binary.value, rawGeom.binary.len) != TE_Ok)
                    break; 
                if (gc != TAK::Engine::Feature::TEGC_Point)
                    break;
                MemoryInput2 blob;
                blob.open(rawGeom.binary.value, rawGeom.binary.len);
                auto parsed = GeometryFactory_fromSpatiaLiteBlob(blob, nullptr, [&point](const GeometryParseCommand cmd, const GeometryClass gpc, std::size_t dim, const std::size_t count, const Point2& p)
                {
                    if (cmd == TEGF_Point) {
                        point.x = p.x;
                        point.y = p.y;
                        point.z = p.z;
                        if(dim == 2u)
                            point.setDimension(atakmap::feature::Geometry::_2D);
                    }
                    return TE_Ok;
                });
                if (parsed != TE_Ok)
                    break;
                geom = GeometryPtr_const(&point, Memory_leaker_const<atakmap::feature::Geometry>);
            } while (false);

            if(!geom) {
                try {
                    geom = TAK::Engine::Feature::GeometryPtr_const(
                        atakmap::feature::parseBlob(atakmap::feature::ByteBuffer(rawGeom.binary.value, rawGeom.binary.value + rawGeom.binary.len)),
                        atakmap::feature::destructGeometry);
                }
                catch (...) {}
            }
        }
        break;
    case TAK::Engine::Feature::FeatureDefinition2::GeomWkb :
        if (rawGeom.binary.len) {
            try {
                geom = TAK::Engine::Feature::GeometryPtr_const(
                    atakmap::feature::parseWKB(atakmap::feature::ByteBuffer(rawGeom.binary.value, rawGeom.binary.value + rawGeom.binary.len)),
                    atakmap::feature::destructGeometry);
            } catch (...) {}
        }
        break;
    default :
        break;
    }
    if (!geom)
        return TE_Ok;
    auto FeatureDefinition_getName = [&def]()
    {
        const char* name = nullptr;
        def.getName(&name);
        return name;
    };
    // NOTE: point clamping occurs in shader at realtime; no override for mode is required here
    unsigned processLabelsMask = 0u;
    if(pushHints&PushHints::ProcessLabels)
        processLabelsMask |= ProcessLabelsMask::AutoGenerate|ProcessLabelsMask::ExplicitStyle;
    code = ::push(ctx, FeatureDefinition_getName, *geom, def.getExtrude(), ((pushHints&PushHints::ForceClampToGround) && geom->getType() != atakmap::feature::Geometry::POINT) ? TAK::Engine::Feature::TEAM_ClampToGround : def.getAltitudeMode(), style, (ProcessLabelsMask)processLabelsMask, pushHints);
    if(code != TE_Ok)
        return code;

    // add a label if required and none were added per the style
    if((pushHints&PushHints::RequireLabel) && ctx.labels.empty()) {
            atakmap::feature::LabelPointStyle label(
                    FeatureDefinition_getName(),
                    0xFFFFFFFFu,
                    0x0u,
                    atakmap::feature::LabelPointStyle::ScrollMode::DEFAULT);

            auto hints = pushHints;
            if(hints&PushHints::ForceClampToGround)
                hints = (PushHints)(hints|TessellationDisabled);
            code = ::push(ctx, FeatureDefinition_getName, *geom, def.getExtrude(),
                          (pushHints&PushHints::ForceClampToGround) ? TAK::Engine::Feature::TEAM_ClampToGround
                                               : def.getAltitudeMode(), &label,
                          ProcessLabelsMask::ExplicitStyle, hints);
    }
    if(geom->getType() == atakmap::feature::Geometry::POLYGON && (pushHints&PushHints::PolygonCenterLabels))
    {
        do {
            atakmap::feature::Point p(0.0, 0.0, 0.0);
            try {
                // obtain the centroid; may throw if empty
                atakmap::feature::Envelope e = geom->getEnvelope();
                p = atakmap::feature::Point((e.maxX + e.minX) / 2, (e.maxY + e.minY) / 2, e.maxZ);
            } catch(...) {
                break;
            }

            std::function<uint32_t(const atakmap::feature::Style *)> getStyleColor;
            getStyleColor = [&getStyleColor](const atakmap::feature::Style *s) {
                if(const auto stroke = dynamic_cast<const atakmap::feature::BasicStrokeStyle *>(s)) {
                    return stroke->getColor();
                } else if(const auto fill = dynamic_cast<const atakmap::feature::BasicFillStyle *>(s)) {
                    return fill->getColor();
                } else if(const auto composite = dynamic_cast<const atakmap::feature::CompositeStyle *>(s)) {
                    for(auto it : composite->components()) {
                        const auto c = getStyleColor(it.get());
                        if(c)
                            return c;
                    }
                }
                return 0u;
            };
            const uint32_t color = getStyleColor(style);
            atakmap::feature::BasicPointStyle basicPoint(
                    color ? color : 0xFFFFFFFFu,
                    32.0f * GLMapRenderGlobals_getRelativeDisplayDensity());
            code = ::push(ctx, FeatureDefinition_getName, p, def.getExtrude(),
                          (pushHints & PushHints::ForceClampToGround)
                          ? TAK::Engine::Feature::TEAM_ClampToGround : def.getAltitudeMode(),
                          &basicPoint, ProcessLabelsMask::AutoGenerate, pushHints);
        } while(false);
    }


    // flush labels
    while(!ctx.labels.empty()) {
        GLLabel &lbl = ctx.labels.back();
        // if there were not batched primitives -- label only style -- toggle hit-testing and
        // disable minimum display threshold
        if(!ctx.batchedPrimitives && !(pushHints&LabelOnlyHandlingDisabled)) {
            lbl.setLevelOfDetail(0u, 32u);
            lbl.setHitTestable(!ctx.batchedPrimitives);
        }
        callback->addLabel(std::move(lbl));
        ctx.labels.pop_back();
    }
    return code;
}
TAKErr GLGeometryBatchBuilder::push(const TAK::Engine::Feature::Feature2 &def, const bool processLabels, const bool forceClampToGround) NOTHROWS
{
    unsigned pushHints = 0u;
    if(processLabels)
        pushHints |= PushHints::ProcessLabels;
    if(forceClampToGround)
        pushHints |= PushHints::ForceClampToGround;
    return push(def, (PushHints)pushHints);
}
TAKErr GLGeometryBatchBuilder::push(const TAK::Engine::Feature::Feature2 &def, const PushHints pushHints) NOTHROWS
{
    class FeatureDefinitionImpl : public TAK::Engine::Feature::FeatureDefinition2
    {
    public :
        FeatureDefinitionImpl(const TAK::Engine::Feature::Feature2 &impl_) NOTHROWS : impl(impl_) {}
    public :
        TAKErr getRawGeometry(RawData *value) NOTHROWS override {
            value->object = impl.getGeometry();
            return TE_Ok;
        }
        GeometryEncoding getGeomCoding() NOTHROWS override { return GeomGeometry; }
        TAK::Engine::Feature::AltitudeMode getAltitudeMode() NOTHROWS override { return impl.getAltitudeMode(); }
        double getExtrude() NOTHROWS override { return impl.getExtrude(); }
        TAKErr getName(const char **value) NOTHROWS override {
            *value = impl.getName();
            return TE_Ok;
        }
        StyleEncoding getStyleCoding() NOTHROWS override { return StyleStyle; }
        TAKErr getRawStyle(RawData *value) NOTHROWS override {
            value->object = impl.getStyle();
            return TE_Ok;
        }
        TAKErr getAttributes(const atakmap::util::AttributeSet **value) NOTHROWS override {
            *value = impl.getAttributes();
            return TE_Ok;
        }
        TAKErr get(const TAK::Engine::Feature::Feature2 **feature) NOTHROWS override {
            *feature = &impl;
            return TE_Ok;
        }
    public :
        const TAK::Engine::Feature::Feature2 &impl;
    };
    FeatureDefinitionImpl iface(def);
    return push(iface, pushHints);
}
TAKErr GLGeometryBatchBuilder::flush() NOTHROWS
{
    auto flushContextFunc = [this](Builder &builder, std::vector<GLBatchGeometryRenderer4::PrimitiveBuffer> &buffer)
    {
        if (builder.pb.count) {
            callback->unmapBuffer(builder.pb.vbo);
            buffer.push_back(builder.pb);
        }

        // reset
        builder.pb = GLBatchGeometryRenderer4::PrimitiveBuffer();
        builder.buffer.close();
    };
    flushContextFunc(builders.sprites.antiAliasedLines, buffers.sprites.antiAliasedLines);
    flushContextFunc(builders.sprites.arrows, buffers.sprites.arrows);
    flushContextFunc(builders.sprites.lines, buffers.sprites.lines);
    flushContextFunc(builders.sprites.polygons, buffers.sprites.polygons);
    flushContextFunc(builders.sprites.strokedPolygons, buffers.sprites.strokedPolygons);
    flushContextFunc(builders.sprites.points, buffers.sprites.points);
    for (auto &item: builders.sprites.meshes) flushContextFunc(item.second, buffers.sprites.meshes[item.first]);
    flushContextFunc(builders.surface.antiAliasedLines, buffers.surface.antiAliasedLines);
    flushContextFunc(builders.surface.arrows, buffers.surface.arrows);
    flushContextFunc(builders.surface.lines, buffers.surface.lines);
    flushContextFunc(builders.surface.polygons, buffers.surface.polygons);
    flushContextFunc(builders.surface.strokedPolygons, buffers.surface.strokedPolygons);
    flushContextFunc(builders.surface.points, buffers.surface.points);

    return TE_Ok;
}
TAKErr GLGeometryBatchBuilder::setBatch(GLBatchGeometryRenderer4 &sink) const NOTHROWS
{
    // verify flushed
    auto sumCountFunc = [](const Builder* builder)
    {
        return builder->pb.count;
    };
    int count = 0;
    count += sumCountFunc(&builders.sprites.antiAliasedLines);
    count += sumCountFunc(&builders.sprites.arrows);
    count += sumCountFunc(&builders.sprites.lines);
    count += sumCountFunc(&builders.sprites.polygons);
    count += sumCountFunc(&builders.sprites.strokedPolygons);
    count += sumCountFunc(&builders.sprites.points);
    for (auto &item: builders.sprites.meshes) count += sumCountFunc(&item.second);
    count += sumCountFunc(&builders.surface.antiAliasedLines);
    count += sumCountFunc(&builders.surface.arrows);
    count += sumCountFunc(&builders.surface.lines);
    count += sumCountFunc(&builders.surface.polygons);
    count += sumCountFunc(&builders.surface.strokedPolygons);
    count += sumCountFunc(&builders.surface.points);
    if (count) return TE_IllegalState;

    // reset batch state for upload buffers
    GLBatchGeometryRenderer4::BatchState surface;
    GLBatchGeometryRenderer4::BatchState sprites;
    if(proj.surface) {
        surface.srid = proj.surface->getSpatialReferenceID();
        proj.surface->inverse(&surface.centroid, relativeToCenter.surface);
        surface.centroidProj = relativeToCenter.surface;
        surface.localFrame.setToTranslate(surface.centroidProj.x, surface.centroidProj.y, surface.centroidProj.z);
    }
    if(proj.sprites) {
        sprites.srid = proj.sprites->getSpatialReferenceID();
        proj.sprites->inverse(&sprites.centroid, relativeToCenter.sprites);
        sprites.centroidProj = relativeToCenter.sprites;
        sprites.localFrame.setToTranslate(sprites.centroidProj.x, sprites.centroidProj.y, sprites.centroidProj.z);
    }
    sink.setBatchState(surface, sprites);

    // sprites
    for (const auto& pb : buffers.sprites.lines)
        sink.addBatchBuffer(GLBatchGeometryRenderer4::Lines, pb, layout, GLGlobeBase::Sprites);
    for (const auto& pb : buffers.sprites.antiAliasedLines)
        sink.addBatchBuffer(GLBatchGeometryRenderer4::AntiAliasedLines, pb, layout, GLGlobeBase::Sprites);
    for (const auto& pb : buffers.sprites.arrows)
        sink.addBatchBuffer(GLBatchGeometryRenderer4::Arrows, pb, layout, GLGlobeBase::Sprites);
    for (const auto& pb : buffers.sprites.polygons)
        sink.addBatchBuffer(GLBatchGeometryRenderer4::Polygons, pb, layout, GLGlobeBase::Sprites);
    for (const auto& pb : buffers.sprites.strokedPolygons)
        sink.addBatchBuffer(GLBatchGeometryRenderer4::StrokedPolygons, pb, layout, GLGlobeBase::Sprites);
    for (const auto& pb : buffers.sprites.points)
        sink.addBatchBuffer(GLBatchGeometryRenderer4::Points, pb, layout, GLGlobeBase::Sprites);
    for (const auto& entry : buffers.sprites.meshes)
        for(const auto& pb : entry.second)
            sink.addBatchBuffer(GLBatchGeometryRenderer4::Meshes, pb, layout,GLGlobeBase::Sprites, entry.first);

    // surface
    for (const auto& pb : buffers.surface.lines)
        sink.addBatchBuffer(GLBatchGeometryRenderer4::Lines, pb, layout, GLGlobeBase::Surface);
    for (const auto& pb : buffers.surface.antiAliasedLines)
        sink.addBatchBuffer(GLBatchGeometryRenderer4::AntiAliasedLines, pb, layout, GLGlobeBase::Surface);
    for (const auto& pb : buffers.surface.arrows)
        sink.addBatchBuffer(GLBatchGeometryRenderer4::Arrows, pb, layout, GLGlobeBase::Surface);
    for (const auto& pb : buffers.surface.polygons)
        sink.addBatchBuffer(GLBatchGeometryRenderer4::Polygons, pb, layout, GLGlobeBase::Surface);
    for (const auto& pb : buffers.surface.strokedPolygons)
        sink.addBatchBuffer(GLBatchGeometryRenderer4::StrokedPolygons, pb, layout, GLGlobeBase::Surface);
    for (const auto& pb : buffers.surface.points)
        sink.addBatchBuffer(GLBatchGeometryRenderer4::Points, pb, layout, GLGlobeBase::Surface);

    return TE_Ok;
}

GLGeometryBatchBuilder::Callback::~Callback() NOTHROWS
{}

GLGeometryBatchBuilder::Callback2::~Callback2() NOTHROWS
{}

GLGeometryBatchBuilder::Callback3::~Callback3() NOTHROWS
{}

void GLGeometryBatchBuilder::VertexWriter::setError() NOTHROWS
{
    error = true;
}
void GLGeometryBatchBuilder::VertexWriter::point(const TAK::Engine::Math::Point2<double> &p_, const PrimitiveVertexAttributes &attr) NOTHROWS
{
    if (error)
        return;
    if (!ctx) {
        error = true;
        return;
    }

    const bool sprites = (ctx->impl.altmode != TAK::Engine::Feature::TEAM_ClampToGround);

    TAK::Engine::Core::GeoPoint2 lla(p_.y, p_.x, p_.z, TAK::Engine::Core::HAE);
    TAK::Engine::Math::Point2<double> p;
    const Projection2 &lla2xyz = sprites ? *ctx->owner->proj.sprites : *ctx->owner->proj.surface;
    const TAK::Engine::Math::Point2<double> &rtc = sprites ? ctx->owner->relativeToCenter.sprites : ctx->owner->relativeToCenter.surface;
    if (lla2xyz.forward(&p, lla) != TE_Ok) {
        error = true;
        return;
    }
    p.x -= rtc.x;
    p.y -= rtc.y;
    p.z -= rtc.z;

    struct {
        GLGeometryBatchBuilder::Builder* builder{ nullptr };
        std::vector<GLBatchGeometryRenderer4::PrimitiveBuffer> *buffers{ nullptr };
    } sink;
    switch (ctx->impl.type) {
    case GLBatchGeometryRenderer4::AntiAliasedLines :
        sink.builder = sprites ? &ctx->owner->builders.sprites.antiAliasedLines : &ctx->owner->builders.surface.antiAliasedLines;
        sink.buffers = sprites ? &ctx->owner->buffers.sprites.antiAliasedLines : &ctx->owner->buffers.surface.antiAliasedLines;
        break;
    case GLBatchGeometryRenderer4::Arrows :
        sink.builder = sprites ? &ctx->owner->builders.sprites.arrows : &ctx->owner->builders.surface.arrows;
        sink.buffers = sprites ? &ctx->owner->buffers.sprites.arrows : &ctx->owner->buffers.surface.arrows;
        break;
    case GLBatchGeometryRenderer4::Lines :
        sink.builder = sprites ? &ctx->owner->builders.sprites.lines : &ctx->owner->builders.surface.lines;
        sink.buffers = sprites ? &ctx->owner->buffers.sprites.lines : &ctx->owner->buffers.surface.lines;
        break;
    case GLBatchGeometryRenderer4::Polygons :
        sink.builder = sprites ? &ctx->owner->builders.sprites.polygons : &ctx->owner->builders.surface.polygons;
        sink.buffers = sprites ? &ctx->owner->buffers.sprites.polygons : &ctx->owner->buffers.surface.polygons;
        break;
    case GLBatchGeometryRenderer4::StrokedPolygons :
        sink.builder = sprites ? &ctx->owner->builders.sprites.strokedPolygons : &ctx->owner->builders.surface.strokedPolygons;
        sink.buffers = sprites ? &ctx->owner->buffers.sprites.strokedPolygons : &ctx->owner->buffers.surface.strokedPolygons;
        break;
    case GLBatchGeometryRenderer4::Points :
        // points are always sprites
        sink.builder = &ctx->owner->builders.sprites.points;
        sink.buffers = &ctx->owner->buffers.sprites.points;
        break;
    case GLBatchGeometryRenderer4::Meshes :
        sink.builder = &ctx->owner->builders.sprites.meshes[ctx->style.mesh.meshPtr];
        sink.buffers = &ctx->owner->buffers.sprites.meshes[ctx->style.mesh.meshPtr];
        break;
    }
    
    primitive[idx] = TAK::Engine::Math::Point2<float>((float)p.x, (float)p.y, (float)p.z);
    vertexAttributes[idx] = attr;
    idx++;
    if (idx == ctx->impl.verticesPerEmitPrimitives.in) {
        std::size_t remaining = 0u;
        sink.builder->buffer.remaining(&remaining);
        if (!sink.builder->pb.vbo ||
            ctx->style.texid != sink.builder->pb.texid ||
            remaining < (ctx->impl.verticesPerEmitPrimitives.out*ctx->impl.vertexSize)) {

            // flush builder contents
            if (sink.builder->pb.vbo) {
                if (ctx->owner->callback->unmapBuffer(sink.builder->pb.vbo) != TE_Ok) {
                    error = true;
                    return;
                }

                sink.buffers->push_back(sink.builder->pb);
            }
            // reset
            sink.builder->pb = GLBatchGeometryRenderer4::PrimitiveBuffer();
            sink.builder->buffer.close();

            GLuint handle;
            void *data;
            if (ctx->owner->callback->mapBuffer(&handle, &data, ctx->bufsize) != TE_Ok) {
                error = true;
                return;
            }
            sink.builder->pb.vbo = handle;
            if (sink.builder->buffer.open((uint8_t*)data, ctx->bufsize) != TE_Ok) {
                error = true;
                return;
            }
            sink.builder->buffer.setSourceEndian2(TE_PlatformEndian);
            sink.builder->pb.mode = ctx->impl.mode;
            sink.builder->pb.texid = ctx->style.texid;
        }

        idx = 0u;
        if (ctx->impl.emitPrimitives(sink.builder->buffer, ctx->style, primitive, ctx->hitid, vertexAttributes, rtc) != TE_Ok) {
            error = true;
            return;
        }
        sink.builder->pb.count += (GLsizei)ctx->impl.verticesPerEmitPrimitives.out;
    }
}

namespace
{
    const atakmap::feature::Style& getDefaultLinestringStyle() NOTHROWS
    {
        static atakmap::feature::BasicStrokeStyle defls(0xFFFFFFFF, 1.0f);
        return defls;
    }
    const atakmap::feature::Style &getDefaultPolygonStyle() NOTHROWS
    {
        static atakmap::feature::BasicStrokeStyle defls(0xFFFFFFFF, 1.0f);
        return defls;
    }
    const atakmap::feature::Style &getDefaultPointStyle() NOTHROWS
    {
        static atakmap::feature::BasicPointStyle defls(0xFFFFFFFF, 32.0f);
        return defls;
    }

    TAKErr push(VertexWriterContext & ctx, const std::function<const char *()> &featureNameAccess, const atakmap::feature::Geometry &geom, const double extrude_, const TAK::Engine::Feature::AltitudeMode altmode, const atakmap::feature::Style *style_, const ProcessLabelsMask processLabels, const GLGeometryBatchBuilder::PushHints hints) NOTHROWS
    {
        if (geom.getType() == atakmap::feature::Geometry::COLLECTION) {
            const auto &gc = static_cast<const atakmap::feature::GeometryCollection &>(geom);
            for (auto it = gc.contents().first; it != gc.contents().second; it++)
                push(ctx, featureNameAccess, **it, extrude_, altmode, style_, (ProcessLabelsMask)(processLabels&ProcessLabelsMask::ExplicitStyle), hints);
            return TE_Ok;
        }

        // XXX - KML placemarks with explicit extrude of zero aren't being clamped...
        const auto extrude = (geom.getType() == atakmap::feature::Geometry::POINT) ?
                -1.0 : (TE_ISNAN(extrude_) ? 0.0 : extrude_);

        bool needsLabel = (geom.getType() == atakmap::feature::Geometry::POINT && (processLabels&ProcessLabelsMask::AutoGenerate));
        if (!style_) {
            switch (geom.getType()) {
            case atakmap::feature::Geometry::POINT :
                style_ = &getDefaultPointStyle();
                break;
            case atakmap::feature::Geometry::LINESTRING:
                style_ = &getDefaultLinestringStyle();
                break;
            case atakmap::feature::Geometry::POLYGON :
                style_ = &getDefaultPolygonStyle();
                break;
            default :
                return TE_IllegalState;
            }
        }
        const atakmap::feature::Style &style = *style_;
        switch (style.getClass()) {
        case atakmap::feature::TESC_BasicFillStyle :
        {
            if (ctx.style.composite.basicFill) {
                flushPrimitives(ctx, geom, extrude, altmode, hints);
                ctx.style = FeatureStyle();
                ctx.style.label.color.background = ctx.labelDefaults.backgroundColor;
            }
            const auto &impl = static_cast<const atakmap::feature::BasicFillStyle &>(style);
            ctx.style.color.fill.r = (impl.getColor() >> 16u) & 0xFFu;
            ctx.style.color.fill.g = (impl.getColor() >> 8u) & 0xFFu;
            ctx.style.color.fill.b = impl.getColor() & 0xFFu;
            ctx.style.color.fill.a = (impl.getColor() >> 24u) & 0xFFu;
            ctx.style.composite.basicFill++;
            break;
        }
        case atakmap::feature::TESC_BasicPointStyle :
        {
            if (ctx.style.composite.icon) {
                flushPrimitives(ctx, geom, extrude, altmode, hints);
                ctx.style = FeatureStyle();
                ctx.style.label.color.background = ctx.labelDefaults.backgroundColor;
            }
            // empty URI is a signal to fallback on the default icon URI
            if (ctx.callback->getIcon(&ctx.style.texid,
                &ctx.style.texCoords.u0,
                &ctx.style.texCoords.v0,
                &ctx.style.texCoords.u1,
                &ctx.style.texCoords.v1,
                &ctx.style.icon.width,
                &ctx.style.icon.height,
                &ctx.style.icon.rotation,
                &ctx.style.icon.isAbsoluteRotation,
                "") != TE_Ok) {

                // for purposes of label emit, failure to load icon should be ignored
                ctx.batchedPrimitives++;
                break;
            }
            const auto& impl = static_cast<const atakmap::feature::BasicPointStyle&>(style);
            ctx.style.color.fill.r = (impl.getColor() >> 16u) & 0xFFu;
            ctx.style.color.fill.g = (impl.getColor() >> 8u) & 0xFFu;
            ctx.style.color.fill.b = impl.getColor() & 0xFFu;
            ctx.style.color.fill.a = (impl.getColor() >> 24u) & 0xFFu;
            ctx.style.icon.rotation = 0.f;
            ctx.style.icon.isAbsoluteRotation = false;

            if (impl.getSize() > 0.f) {
                ctx.style.icon.width = (std::size_t)std::max(impl.getSize(), 1.f);
                ctx.style.icon.height = (std::size_t)std::max(impl.getSize(), 1.f);
            }

            // apply density adjustment scaling
            float scale = GLMapRenderGlobals_getRelativeDisplayDensity();
            if (scale != 1.f) {
                ctx.style.icon.width = (std::size_t)std::max(scale * (float)ctx.style.icon.width, 1.f);
                ctx.style.icon.height = (std::size_t)std::max(scale * (float)ctx.style.icon.height, 1.f);
            }

            ctx.style.composite.icon++;
            break;
        }
        case atakmap::feature::TESC_BasicStrokeStyle :
        {
            if (ctx.style.composite.basicStroke || ctx.style.composite.pattern || ctx.style.composite.arrow) {
                flushPrimitives(ctx, geom, extrude, altmode, hints);
                ctx.style = FeatureStyle();
                ctx.style.label.color.background = ctx.labelDefaults.backgroundColor;
            }
            const auto &impl = static_cast<const atakmap::feature::BasicStrokeStyle &>(style);
            ctx.style.color.stroke.r = (impl.getColor() >> 16u) & 0xFFu;
            ctx.style.color.stroke.g = (impl.getColor() >> 8u) & 0xFFu;
            ctx.style.color.stroke.b = impl.getColor() & 0xFFu;
            ctx.style.color.stroke.a = (impl.getColor() >> 24u) & 0xFFu;
            ctx.style.stroke.width = impl.getStrokeWidth();
            if(hints&GLGeometryBatchBuilder::DensityAdjustStroke)
                ctx.style.stroke.width *= GLMapRenderGlobals_getRelativeDisplayDensity();
            ctx.style.stroke.extrude = impl.getExtrusionMode();
            ctx.style.composite.basicStroke++;
            break;
        }
        case atakmap::feature::TESC_CompositeStyle :
        {
            const auto &impl = static_cast<const atakmap::feature::CompositeStyle &>(style);
            // only allow explicit label processing in recursion
            const unsigned processLabelsMask = processLabels&ProcessLabelsMask::ExplicitStyle;
            for (std::size_t i = 0u; i < impl.getStyleCount(); i++)
                push(ctx, featureNameAccess, geom, extrude, altmode, &impl.getStyle(i), (ProcessLabelsMask)processLabelsMask, hints);
            // labeling is assumed to have occurred during recursion
            needsLabel = false;
            break;
        }
        case atakmap::feature::TESC_IconPointStyle :
        {
            if (ctx.style.composite.icon) {
                flushPrimitives(ctx, geom, extrude, altmode, hints);
                ctx.style = FeatureStyle();
                ctx.style.label.color.background = ctx.labelDefaults.backgroundColor;
            }
            // XXX - skip icon for shape type geometries. Probably best to implement this fix at
            //       the `FeatureDataSource` level...
            if(geom.getType() != atakmap::feature::Geometry::POINT && geom.getType() != atakmap::feature::Geometry::LINESTRING)
                return TE_Ok;
            const auto &impl = static_cast<const atakmap::feature::IconPointStyle &>(style);

            // ensure icon is visible
            if(!(impl.getColor()&0xFF000000u)) break; // transparent

            if (ctx.callback->getIcon(&ctx.style.texid,
                                      &ctx.style.texCoords.u0,
                                      &ctx.style.texCoords.v0,
                                      &ctx.style.texCoords.u1,
                                      &ctx.style.texCoords.v1,
                                      &ctx.style.icon.width,
                                      &ctx.style.icon.height, 
                                      &ctx.style.icon.rotation,
                                      &ctx.style.icon.isAbsoluteRotation,
                                      impl.getIconURI()) != TE_Ok) {

                // for purposes of label emit, failure to load icon should be ignored
                ctx.batchedPrimitives++;
                break;
            }
            // use explicit dimensions if defined
            if(impl.getWidth() > 0.f && impl.getHeight() > 0.f) {
                ctx.style.icon.width = (std::size_t)impl.getWidth();
                ctx.style.icon.height = (std::size_t)impl.getHeight();
            }
            // apply scaling (including density adjustment)
            float scale = GLMapRenderGlobals_getRelativeDisplayDensity();
            if(impl.getScaling())
                scale *= impl.getScaling();
            if (scale != 1.f) {
                ctx.style.icon.width = (std::size_t)std::max(scale * (float)ctx.style.icon.width, 1.f);
                ctx.style.icon.height = (std::size_t)std::max(scale * (float)ctx.style.icon.height, 1.f);
            }
            switch(impl.getHorizontalAlignment()) {
                case atakmap::feature::IconPointStyle::LEFT :
                    ctx.style.icon.offset.x -= (float)ctx.style.icon.width / 2.f;
                    break;
                case atakmap::feature::IconPointStyle::H_CENTER :
                    break;
                case atakmap::feature::IconPointStyle::RIGHT :
                    ctx.style.icon.offset.x += (float)ctx.style.icon.width / 2.f;
                    break;
            }
            switch(impl.getVerticalAlignment()) {
                case atakmap::feature::IconPointStyle::ABOVE :
                    ctx.style.icon.offset.y += (float)ctx.style.icon.height / 2.f;
                    break;
                case atakmap::feature::IconPointStyle::V_CENTER :
                    break;
                case atakmap::feature::IconPointStyle::BELOW :
                    ctx.style.icon.offset.y -= (float)ctx.style.icon.height / 2.f;
                    break;
            }
            ctx.style.icon.offset.x += impl.getOffsetX() * GLMapRenderGlobals_getRelativeDisplayDensity();
            ctx.style.icon.offset.y += impl.getOffsetY() * GLMapRenderGlobals_getRelativeDisplayDensity();
            ctx.style.color.fill.r = (impl.getColor() >> 16u) & 0xFFu;
            ctx.style.color.fill.g = (impl.getColor() >> 8u) & 0xFFu;
            ctx.style.color.fill.b = impl.getColor() & 0xFFu;
            ctx.style.color.fill.a = (impl.getColor() >> 24u) & 0xFFu;
            float r = fmodf(impl.getRotation(), 360.0f);
            if (r < 0)
                r += 360.0f;
            ctx.style.icon.rotation = r * (float)(M_PI / 180.0f); 
            ctx.style.icon.isAbsoluteRotation = impl.isRotationAbsolute();
            ctx.style.composite.icon++;
            break;
        }
        case atakmap::feature::TESC_MeshPointStyle :
        {
            if (ctx.style.composite.mesh) {
                flushPrimitives(ctx, geom, extrude, altmode, hints);
                ctx.style = FeatureStyle();
                ctx.style.label.color.background = ctx.labelDefaults.backgroundColor;
            }
            // XXX - skip mesh for shape type geometries. Probably best to implement this fix at
            //       the `FeatureDataSource` level...
            if(geom.getType() != atakmap::feature::Geometry::POINT)
                return TE_Ok;
            const auto &impl = static_cast<const atakmap::feature::MeshPointStyle &>(style);

            // ensure mesh is visible
            if(!(impl.getColor()&0xFF000000u)) break; // transparent

            ctx.style.mesh.meshUri = impl.getMeshURI();
            ctx.style.mesh.transform.assign(impl.getTransform(), impl.getTransform() + 16);
            if (ctx.callback->getMesh(ctx.style.mesh.meshPtr,
                                      ctx.style.mesh.meshUri.c_str()) != TE_Ok) {
                                // for purposes of label emit, failure to load mesh should be ignored
                                ctx.batchedPrimitives++;
                                break;
            }

            if (ctx.style.mesh.meshPtr) {
                if (ctx.style.mesh.meshPtr->getNumMaterials() > 0) {
                    TAK::Engine::Model::Material material;
                    if (ctx.style.mesh.meshPtr->getMaterial(&material, 0) == TE_Ok) {
                        if (material.textureUri) {
                            // TODO - construction of textureUri may need additional attention depending on platform and Uri protocol
                            IO_correctPathSeps(material.textureUri,material.textureUri);
                            std::string textureUri("file://");
                            textureUri += material.textureUri;
                            std::size_t width;
                            std::size_t height;
                            float rotation;
                            bool isAbsoluteRotation;
                            if (ctx.callback->getIcon(&ctx.style.texid,
                                                      &ctx.style.texCoords.u0,
                                                      &ctx.style.texCoords.v0,
                                                      &ctx.style.texCoords.u1,
                                                      &ctx.style.texCoords.v1,
                                                      &width,
                                                      &height,
                                                      &rotation,
                                                      &isAbsoluteRotation,
                                                      textureUri.c_str()) != TE_Ok) {
                                // for purposes of label emit, failure to load texture should be ignored
                                ctx.batchedPrimitives++;
                                break;
                            }
                        }
                    }
                }
            }

            ctx.style.color.fill.r = (impl.getColor() >> 16u) & 0xFFu;
            ctx.style.color.fill.g = (impl.getColor() >> 8u) & 0xFFu;
            ctx.style.color.fill.b = impl.getColor() & 0xFFu;
            ctx.style.color.fill.a = (impl.getColor() >> 24u) & 0xFFu;
            ctx.style.composite.mesh++;
            break;
        }
        case atakmap::feature::TESC_LabelPointStyle :
        {
            if(!(processLabels&ProcessLabelsMask::ExplicitStyle))
                break;

            if (ctx.style.composite.label) {
                flushPrimitives(ctx, geom, extrude, altmode, hints);
                ctx.style = FeatureStyle();
                ctx.style.label.color.background = ctx.labelDefaults.backgroundColor;
            }

            const auto &impl = static_cast<const atakmap::feature::LabelPointStyle &>(style);

            float textSize = impl.getTextSize()*impl.getLabelScale();
            ctx.style.label.format = TextFormatParams(impl.getFontFace(), textSize);
            ctx.style.label.format.bold = !!(impl.getStyle() & atakmap::feature::LabelPointStyle::BOLD);
            ctx.style.label.format.italic = !!(impl.getStyle() & atakmap::feature::LabelPointStyle::ITALIC);
            ctx.style.label.format.underline = !!(impl.getStyle() & atakmap::feature::LabelPointStyle::UNDERLINE);
            ctx.style.label.format.strikethrough = !!(impl.getStyle() & atakmap::feature::LabelPointStyle::STRIKETHROUGH);
            ctx.style.label.format.outline = (impl.getOutlineColor()&0xFF00000u);

            ctx.style.label.text = impl.getText();
            // XXX - OGR data source should output `nullptr` text when label should defer to feature name
            if ((!ctx.style.label.text || ctx.style.label.text == "") && geom.getType() == atakmap::feature::Geometry::POINT) {
                ctx.style.label.text = featureNameAccess();
            }
            // XXX -
            const double drawTilt = 0.0;
            ctx.style.label.offset = TAK::Engine::Math::Point2<double>(
                impl.getOffsetX(),
                impl.getOffsetY(),
                (-0.00025 * cos(M_PI / 180.0 * drawTilt)));
            if(!ctx.style.label.offset.y)
                ctx.style.label.offset.y += (double)ctx.style.icon.height * 3.0 / 4.0;

            ctx.style.label.maxResolution = impl.getLabelMinRenderResolution();
            switch(impl.getHorizontalAlignment()) {
                case atakmap::feature::LabelPointStyle::H_CENTER :
                    ctx.style.label.alignment.horizontal = TEHA_Center;
                    break;
                case atakmap::feature::LabelPointStyle::LEFT :
                    ctx.style.label.alignment.horizontal = TEHA_Left;
                    break;
                case atakmap::feature::LabelPointStyle::RIGHT :
                    ctx.style.label.alignment.horizontal = TEHA_Right;
                    break;
                default :
                    ctx.style.label.alignment.horizontal = TEHA_Center;
                    break;
            }
            switch(impl.getVerticalAlignment()) {
                case atakmap::feature::LabelPointStyle::V_CENTER :
                    ctx.style.label.alignment.vertical = TEVA_Middle;
                    break;
                case atakmap::feature::LabelPointStyle::ABOVE :
                    ctx.style.label.alignment.vertical = TEVA_Top;
                    break;
                case atakmap::feature::LabelPointStyle::BELOW :
                    ctx.style.label.alignment.vertical = TEVA_Bottom;
                    break;
                default :
                    ctx.style.label.alignment.vertical = TEVA_Top;
                    break;
            }
            ctx.style.label.color.foreground = impl.getTextColor();
            if(!ctx.labelDefaults.overrideBackgroundColor) {
                ctx.style.label.color.background = !!(impl.getBackgroundColor() & 0xFF000000) ? impl.getBackgroundColor() : 0u;
            } else if(ctx.style.label.color.background&0xFF000000) {
                //contrast outline color with text color based on luminosity
                const auto fglum = luminance(ctx.style.label.color.foreground);
                const auto bglum = luminance(ctx.style.label.color.background);
                if((bglum > 0.5f) == (fglum > 0.5))
                {
                    ctx.style.label.color.foreground =
                            (ctx.style.label.color.foreground&0xFF000000u) |
                                    ((bglum > 0.5f) ? 0xFFFFFFu : 0x0u);
                }
            }
            ctx.style.label.rotation.angle = impl.getRotation();
            ctx.style.label.rotation.absolute = impl.isRotationAbsolute();
            // verify
            //  1. we have text
            //  2. scale is not zero (zero scale used by KML to hide label)
            if(ctx.style.label.text && impl.getLabelScale())
                ctx.style.composite.label++;
            needsLabel = false;
            break;
        }
        case atakmap::feature::TESC_PatternStrokeStyle :
        {
            if (ctx.style.composite.basicStroke || ctx.style.composite.pattern || ctx.style.composite.arrow) {
                flushPrimitives(ctx, geom, extrude, altmode, hints);
                ctx.style = FeatureStyle();
                ctx.style.label.color.background = ctx.labelDefaults.backgroundColor;
            }
            const auto &impl = static_cast<const atakmap::feature::PatternStrokeStyle &>(style);
            ctx.style.color.stroke.r = (impl.getColor() >> 16u) & 0xFFu;
            ctx.style.color.stroke.g = (impl.getColor() >> 8u) & 0xFFu;
            ctx.style.color.stroke.b = impl.getColor() & 0xFFu;
            ctx.style.color.stroke.a = (impl.getColor() >> 24u) & 0xFFu;
            ctx.style.stroke.width = impl.getStrokeWidth();
            if(hints&GLGeometryBatchBuilder::DensityAdjustStroke)
                ctx.style.stroke.width *= GLMapRenderGlobals_getRelativeDisplayDensity();
            ctx.style.stroke.pattern = impl.getPattern();
            ctx.style.stroke.factor = (uint32_t)impl.getFactor();
            ctx.style.stroke.extrude = impl.getExtrusionMode();
            if(ctx.style.stroke.factor) {
                ctx.style.composite.pattern++;
            } else {
                ctx.style.stroke.pattern = 0xFFFFFFFu;
                ctx.style.composite.basicStroke++;
            }
            ctx.style.stroke.endCap = impl.getEndCap();
            break;
        }
        case atakmap::feature::TESC_ArrowStrokeStyle :
        {
            if (ctx.style.composite.basicStroke || ctx.style.composite.pattern || ctx.style.composite.arrow) {
                flushPrimitives(ctx, geom, extrude, altmode, hints);
                ctx.style = FeatureStyle();
                ctx.style.label.color.background = ctx.labelDefaults.backgroundColor;
            }
            const auto &impl = static_cast<const atakmap::feature::ArrowStrokeStyle &>(style);
            ctx.style.stroke.arrowRadius = impl.getArrowRadius();
            if(hints&GLGeometryBatchBuilder::DensityAdjustStroke)
                ctx.style.stroke.arrowRadius *= GLMapRenderGlobals_getRelativeDisplayDensity();
            ctx.style.color.stroke.r = (impl.getColor() >> 16u) & 0xFFu;
            ctx.style.color.stroke.g = (impl.getColor() >> 8u) & 0xFFu;
            ctx.style.color.stroke.b = impl.getColor() & 0xFFu;
            ctx.style.color.stroke.a = (impl.getColor() >> 24u) & 0xFFu;
            ctx.style.stroke.width = impl.getStrokeWidth();
            if(hints&GLGeometryBatchBuilder::DensityAdjustStroke)
                ctx.style.stroke.width *= GLMapRenderGlobals_getRelativeDisplayDensity();
            ctx.style.stroke.pattern = impl.getPattern();
            ctx.style.stroke.factor = (uint32_t)impl.getFactor();
            ctx.style.stroke.extrude = impl.getExtrusionMode();
            ctx.style.stroke.arrowHeadMode = impl.getArrowHeadMode();
            // if there is an arrow radius, mark as arrow; otherwise, mark as pattern
            if (!!ctx.style.stroke.arrowRadius)
                ctx.style.composite.arrow++;
            else
                ctx.style.composite.pattern++;
            break;
        }
        case atakmap::feature::TESC_LevelOfDetailStyle :
        {
            // XXX - composite style nesting here will clear out LODs
            const auto &impl = static_cast<const atakmap::feature::LevelOfDetailStyle &>(style);
            const auto minLod = ctx.style.levelOfDetail.minimum;
            const auto maxLod = ctx.style.levelOfDetail.maximum;
            // push the LOD
            ctx.style.levelOfDetail.minimum = std::max(minLod, impl.getMinLevelOfDetail());
            ctx.style.levelOfDetail.maximum = std::min(maxLod, impl.getMaxLevelOfDetail());
            ctx.style.composite.levelOfDetail++;
            if(!TE_ISNAN(ctx.batchContext.resolution.scene)) {
                const auto lod = atakmap::raster::osm::OSMUtils::mapnikTileLeveld(ctx.batchContext.resolution.scene, 0.0);
                const auto child = impl.getStyle((double)lod);
                if(child)
                    push(ctx, featureNameAccess, geom, extrude, altmode, child.get(), processLabels, hints);
            } else {
                push(ctx, featureNameAccess, geom, extrude, altmode, &impl.getStyle(), processLabels, hints);
            }
            // pop the LOD
            ctx.style.levelOfDetail.minimum = minLod;
            ctx.style.levelOfDetail.maximum = maxLod;

            // any labeling will be handled via recursion
            needsLabel = false;
            break;
        }
        default :
            break;
        }

        if(needsLabel) {
            ctx.style.label.text = featureNameAccess();
            ctx.style.label.format.size = 16.0;
            // XXX -

            const double drawTilt = 0.0;
            ctx.style.label.offset = TAK::Engine::Math::Point2<double>(
                0.0,
                ctx.style.icon.height * 3.0 / 4.0,
                (-0.00025 * cos(M_PI / 180.0 * drawTilt)));

            if(ctx.style.label.text)
                ctx.style.composite.label++;
        }

        if (ctx.style.composite.basicFill ||
            ctx.style.composite.basicPoint ||
            ctx.style.composite.basicStroke ||
            ctx.style.composite.icon ||
            ctx.style.composite.mesh ||
            ctx.style.composite.label ||
            ctx.style.composite.pattern ||
            ctx.style.composite.arrow) {

            flushPrimitives(ctx, geom, extrude, altmode, hints);
            ctx.style = FeatureStyle();
            ctx.style.label.color.background = ctx.labelDefaults.backgroundColor;
        }

        return TE_Ok;
    }

    TAKErr flushPrimitives(VertexWriterContext &ctx, const atakmap::feature::Geometry &geom, const double extrude, const TAK::Engine::Feature::AltitudeMode altmode, const GLGeometryBatchBuilder::PushHints hints) NOTHROWS
    {
        // XXX - 
        EmptyPointStream empty;
        LabelingPointStream labeler(empty, ctx);
        if (ctx.style.composite.label) {
            // set up label templates
            auto &lbl = labeler.labels.back();
            lbl.setTextFormat(&ctx.style.label.format);
            lbl.setText(ctx.style.label.text);
            if(ctx.style.label.rotation.angle != 0.0 || ctx.style.label.rotation.absolute)
                lbl.setRotation((float)ctx.style.label.rotation.angle, ctx.style.label.rotation.absolute);
            lbl.setDesiredOffset(ctx.style.label.offset);
            lbl.setAlignment(ctx.style.label.alignment.text);
            lbl.setHorizontalAlignment(ctx.style.label.alignment.horizontal);
            lbl.setVerticalAlignment(ctx.style.label.alignment.vertical);
            lbl.setColor(ctx.style.label.color.foreground);
            lbl.setBackColor(ctx.style.label.color.background);
            lbl.setFill(!!(ctx.style.label.color.background & 0xFF000000u));
            lbl.setAltitudeMode(TAK::Engine::Feature::TEAM_Absolute);
            if(ctx.style.composite.levelOfDetail)
                lbl.setLevelOfDetail(ctx.style.levelOfDetail.minimum, ctx.style.levelOfDetail.maximum);
            else
                lbl.setLevelOfDetail(ctx.labelDefaults.minLod, ctx.labelDefaults.maxLod);
        }


        const double tessellationThresholdMeters = !(hints&GLGeometryBatchBuilder::TessellationDisabled) ?
                1250000 : std::numeric_limits<double>::max();


        GLGeometryBatchBuilder::VertexWriter vw;
        vw.ctx = &ctx;
        if (ctx.style.color.fill.a && (ctx.style.texid || ctx.style.mesh.meshPtr)) {
            if (geom.getType() == atakmap::feature::Geometry::POINT) {
                auto pointGeom = static_cast<const atakmap::feature::Point &>(geom);
                // check for occlusion
                if(!ctx.style.mesh.meshPtr && (hints&GLGeometryBatchBuilder::PushHints::IconDeclutter)) {
                    TAK::Engine::Math::Rectangle2<double> ib;
                    double localResolution = ctx.batchContext.resolution.scene;
                    do {
                        if (TE_ISNAN(ctx.batchContext.camera.latitude) || TE_ISNAN(ctx.batchContext.camera.longitude))
                            break;
                        const double pd = GeoPoint2_distance(ctx.batchContext.camera, GeoPoint2(pointGeom.y, pointGeom.x), true);
                        if(pd <= ctx.batchContext.resolution.gsdRange)
                            break;
                        else if(pd >= (ctx.batchContext.resolution.gsdRange * _iconDeclutterRangeFactor)) {
                            ctx.style.composite.icon = 0;
                            return TE_Ok;
                        }
                        localResolution *= log(pd/ctx.batchContext.resolution.gsdRange) / log(2.0);
                    } while(false);
                    const auto pxToDegX = localResolution / GeoPoint2_approximateMetersPerDegreeLongitude(pointGeom.y);
                    const auto pxToDegY = localResolution / GeoPoint2_approximateMetersPerDegreeLatitude(pointGeom.y);
                    ib.width = ((double)ctx.style.icon.width)*pxToDegX / 2.0;
                    ib.height = ((double)ctx.style.icon.height)*pxToDegY / 2.0;
                    ib.x = pointGeom.x - ib.width / 2.0;
                    ib.y = pointGeom.y - ib.height / 2.0;
                    for(const auto &m : (*ctx.iconOcclusionMask)) {
                        if(TAK::Engine::Math::Rectangle2_intersects(m.x, m.y, m.x+m.width, m.y+m.height, ib.x, ib.y, ib.x+ib.width, ib.y+ib.height)) {
                            ctx.style.composite.icon = 0;
                            return TE_Ok;
                        }
                    }

                    ctx.iconOcclusionMask->push_back(ib);
                }
                VertexWriterImpl pvw = ctx.style.mesh.meshPtr ?
                        static_cast<VertexWriterImpl>(PointMeshVertexWriter()) :
                        static_cast<VertexWriterImpl>(PointSpriteVertexWriter());
                pvw.altmode = (altmode == TAK::Engine::Feature::TEAM_ClampToGround) ?
                    TAK::Engine::Feature::TEAM_Relative : altmode;
                ctx.impl = pvw;

                PointStream *ps = nullptr;
                if(pointGeom.getDimension() == atakmap::feature::Geometry::_2D)
                    pointGeom.z = NAN;
                PointPointStream point(pointGeom);
                RelativeAltPointStream agl(point, *ctx.callback);
                if (altmode == TAK::Engine::Feature::TEAM_Relative)
                    ps = &agl;
                else
                    ps = &point;
                // XXX - supporting legacy UX. elevation queries are roughly
                //       doubling vertex construction time. should utilize
                //       some caching mechanism (invalidate on elevation
                //       content changes and feature version changes)
                TerrainCollisionPointStream collide(*ps, *ctx.callback);
                ps = &collide;
                if (ctx.style.composite.label) {
                    labeler.reset(*ps);
                    ps = &labeler;
                }
                // XXX - 
                {
                    PointExtruder extruder(*ps, extrude, *ctx.callback);
                    extruder.start(vw);
                    //ps->start(vw);
                }
#if 0
                if (extrude) {
                    VertexWriterContext extrudeCtx = ctx;
                    AntiAliasVertexWriter aavw;
                    aavw.altmode = TAK::Engine::Feature::TEAM_Absolute;
                    extrudeCtx.impl = aavw;

                    extrudeCtx.style.stroke.width = 1.f;
                    // use icon color for stroke
                    extrudeCtx.style.color.stroke = extrudeCtx.style.color.fill;
                    extrudeCtx.style.color.fill.a = 0u;

                    vw.ctx = &extrudeCtx;
                    PointExtruder extruder(*ps, extrude, *extrudeCtx.callback);
                    extruder.start(vw);
                }
#endif
            } else if(geom.getType() == atakmap::feature::Geometry::LINESTRING && static_cast<const atakmap::feature::LineString&>(geom).getPointCount() && (hints&GLGeometryBatchBuilder::LinestringIcons)) {
                // tessellate points along the linestring
                const auto &ls = static_cast<const atakmap::feature::LineString&>(geom);
                double d = 0.0;
                //Logger_log(TELL_Info, "Linestring tessellate icons {icon=%u, threshold=%.2lfm}", ctx.style.texid, threshold);
                GeoPoint2 a;
                GeoPoint2 b(ls.getY(0), ls.getX(0));
                for(std::size_t i = 1u; i < ls.getPointCount(); i++) {
                    a = b;
                    b = GeoPoint2(ls.getY(i), ls.getX(i));
                    d += GeoPoint2_distance(a, b, true);
                }
                if(d == 0.0)
                    return TE_Ok;

                const auto midpoint = d / 2.0;
                const double threshold = std::max(d / 64.0, 250.0 * ctx.batchContext.resolution.tessellate);
                double nextIcon = midpoint - ((int)(midpoint / threshold) * threshold);
                b = GeoPoint2(ls.getY(0), ls.getX(0));
                d = 0.0;
                for(std::size_t i = 1u; i < ls.getPointCount(); i++) {
                    a = b;
                    b = GeoPoint2(ls.getY(i), ls.getX(i));
                    const double sd = GeoPoint2_distance(a, b, true);
                    // if the next icon falls on this segment, emit
                    if(d < nextIcon && (d+sd) >= nextIcon) {
                        const double dx = (b.longitude-a.longitude);
                        const double dy = (b.latitude-a.latitude);
                        double alongDistance = nextIcon-d; // compute distance along segment to the next icon
                        while(d+alongDistance <= std::min(nextIcon, d+sd)) {
                            atakmap::feature::Point p(a.longitude + dx*(alongDistance/sd), a.latitude + dy*(alongDistance/sd));
                            VertexWriterContext icon = ctx;
                            //Logger_log(TELL_Info, "  point at %.2lf", d);
                            if(TAK::Engine::Math::Rectangle2_contains(
                                    ctx.batchContext.bounds.minX,
                                    ctx.batchContext.bounds.minY,
                                    ctx.batchContext.bounds.maxX,
                                    ctx.batchContext.bounds.maxY,
                                    p.x, p.y)) {

                                flushPrimitives(icon, p, 0.0, TAK::Engine::Feature::TEAM_ClampToGround, (GLGeometryBatchBuilder::PushHints)(hints&~GLGeometryBatchBuilder::ProcessLabels));
                            }
                            // advance the icon by the threshold distance
                            nextIcon += threshold;
                            // advance the distance we've traveled along the segment
                            alongDistance += threshold;
                        }
                    }
                    // update total distance traveled
                    d += sd;
                }
            }
        } else if (ctx.style.color.fill.a && ctx.style.color.stroke.a) {
            if (geom.getType() == atakmap::feature::Geometry::LINESTRING) {
                VertexWriterContext stroke = ctx;
                stroke.style.color.fill.a = 0u;
                flushPrimitives(stroke, geom, extrude, altmode, hints);
                VertexWriterContext fill = ctx;
                fill.style.color.stroke.a = 0u;
                flushPrimitives(fill, geom, extrude, altmode, hints);
            } else if (geom.getType() == atakmap::feature::Geometry::POLYGON) {
                // XXX - need to implement separate path for combined stroke+fill for surface polygons

                // sprite polygons should be decomposed into stroke and fill and may be rendered separately
                VertexWriterContext stroke = ctx;
                stroke.style.color.fill.a = 0u;
                flushPrimitives(stroke, geom, extrude, altmode, hints);
//                VertexWriterContext fill = ctx;
//                fill.style.color.stroke.a = 0u;
//                flushPrimitives(fill, geom, extrude, altmode, hints);
            }
        } else if (ctx.style.color.fill.a) {
            PolygonVertexWriter pgvw;
            pgvw.altmode = altmode;
            ctx.impl = pgvw;
            if (geom.getType() == atakmap::feature::Geometry::LINESTRING && extrude && altmode != TAK::Engine::Feature::TEAM_ClampToGround) {
                LineStringStripPointStream linestring(static_cast<const atakmap::feature::LineString&>(geom));
                PointStream *ps = &linestring;
                // not _clamp-to-ground_ -- no simplification
                TessellatePointStream tessellate(*ps, tessellationThresholdMeters);
                if(!(hints&GLGeometryBatchBuilder::TessellationDisabled))
                    ps = &tessellate;
                RelativeAltPointStream agl(*ps, *ctx.callback);
                if (altmode == TAK::Engine::Feature::TEAM_Relative)
                    ps = &agl;
                // inject labels before quadstrip extrusion
                if (ctx.style.composite.label) {
                    labeler.reset(*ps);
                    ps = &labeler;
                }
                // segmentize
                LineStripSegmentizer segments(*ps, altmode, ctx.style.stroke.endCap);
                // extrude walls
                QuadStripPointStream qsps(segments, extrude, *ctx.callback);
                ps = &qsps;
                ps->start(vw);
            } else if (geom.getType() == atakmap::feature::Geometry::POLYGON && extrude && altmode != TAK::Engine::Feature::TEAM_ClampToGround) {
                PointStream *ps = nullptr;
                // top/bottom faces
                {
                    FillPolygonPointStream polygon(static_cast<const atakmap::feature::Polygon&>(geom), ctx.batchContext.cancelToken);
                    RelativeAltPointStream agl(polygon, *ctx.callback);
                    RelativeBasePointStream base(polygon, *ctx.callback);
                    if (altmode != TAK::Engine::Feature::TEAM_Relative)
                        ps = &polygon;
                    else if (extrude < 0.0 || true)
                        ps = &base;
                    else // extrude >= 0.0
                        ps = &agl;
                    // stream top face
                    ps->start(vw);

                    // stream bottom face
                    if (extrude > 0.0) {
                        HeightOffsetPointStream heightOffset(*ps, *ctx.callback, extrude);
                        heightOffset.start(vw);
                    }
                }

                // stream walls
                {
                    PolygonLineStripPointStream polygon(static_cast<const atakmap::feature::Polygon&>(geom));
                    ps = &polygon;
                    // not _clamp-to-ground_ -- no simplification
                    TessellatePointStream tessellate(*ps, tessellationThresholdMeters);
                    if(!(hints&GLGeometryBatchBuilder::TessellationDisabled))
                        ps = &tessellate;
                    RelativeAltPointStream agl(*ps, *ctx.callback);
                    RelativeBasePointStream base(*ps, *ctx.callback);
                    if (altmode != TAK::Engine::Feature::TEAM_Relative)
                        ps = &polygon;
                    else if (extrude < 0.0 || true)
                        ps = &base;
                    else // extrude >= 0.0
                        ps = &agl;

                    // inject labels before quadstrip extrusion
                    if (ctx.style.composite.label) {
                        labeler.reset(*ps);
                        ps = &labeler;
                    }

                    // segmentize
                    LineStripSegmentizer segments(*ps, altmode, ctx.style.stroke.endCap);
                    // extrude walls from segments
                    QuadStripPointStream qsps(segments, extrude, *ctx.callback);
                    ps = &qsps;
                    ps->start(vw);
                }
            } else if (geom.getType() == atakmap::feature::Geometry::POLYGON) {
                struct {
                    const atakmap::feature::Polygon* value{ nullptr };
                    std::size_t count{ 0u };
                } polys;
                polys.value = static_cast<const atakmap::feature::Polygon*>(&geom);
                polys.count = 1u;

                // check for IDL crossing
                std::vector<atakmap::feature::Polygon> hemiNormalizedPolys;
                if(!(hints&GLGeometryBatchBuilder::AntiMeridianHandlingDisabled)) {
                    const auto mbb = geom.getEnvelope();
                    if (altmode == TAK::Engine::Feature::TEAM_ClampToGround && ((mbb.maxX - mbb.minX) > 180.0 || (mbb.minX < -180.0) || (mbb.maxX > 180.0))) {
                        struct CB : public PointStream::Callback
                        {
                        public : // PointStream::Callback
                            void restart() NOTHROWS override
                            {
                                poly->addRing(atakmap::feature::LineString(poly->getDimension()));
                                currentRing = poly->getRing(poly->getRingCount() - 1u);
                            }
                            void point(const TAK::Engine::Math::Point2<double> &xyz, const PrimitiveVertexAttributes &attr) NOTHROWS override
                            {
                                currentRing->addPoint(xyz.x, xyz.y, xyz.z);
                            }
                        public :
                            atakmap::feature::Polygon *poly{ nullptr };
                            atakmap::feature::LineString* currentRing{ nullptr };
                        } cb;

                        hemiNormalizedPolys.push_back(atakmap::feature::Polygon(atakmap::feature::Geometry::_3D));
                        cb.poly = &hemiNormalizedPolys.back();

                        PolygonLineStripPointStream plsps(*polys.value);
                        HemisphereNormalizationPointStream idl(plsps);
                        idl.start(cb);

                        if (idl.primaryHemi) {
                            hemiNormalizedPolys.push_back(atakmap::feature::Polygon(atakmap::feature::Geometry::_3D));
                            cb.poly = &hemiNormalizedPolys.back();
                            idl.primaryHemi *= -1;
                            idl.start(cb);
                        }

                        polys.value = hemiNormalizedPolys.data();
                        polys.count = hemiNormalizedPolys.size();
                    }
                }

                for (std::size_t i = 0u; i < polys.count; i++) {
                    // no extrude
                    PointStream *ps = nullptr;
                    FillPolygonPointStream polygon(polys.value[i], ctx.batchContext.cancelToken);
                    RelativeAltPointStream agl(polygon, *ctx.callback);
                    if (altmode == TAK::Engine::Feature::TEAM_Relative)
                        ps = &agl;
                    else
                        ps = &polygon;
                    // inject labels
                    if (ctx.style.composite.label) {
                        labeler.reset(*ps);
                        ps = &labeler;
                    }
                    ps->start(vw);
                }
            }
        } else if (ctx.style.color.stroke.a) {
            AntiAliasVertexWriter aavw;
            aavw.altmode = altmode;
            aavw.type = !!ctx.style.composite.arrow ? GLBatchGeometryRenderer4::Arrows : GLBatchGeometryRenderer4::AntiAliasedLines;
            ctx.impl = aavw;
            if (geom.getType() == atakmap::feature::Geometry::LINESTRING) {
                LineStringStripPointStream linestring(static_cast<const atakmap::feature::LineString &>(geom));
                PointStream *ps = &linestring;
                // apply simplification if _clamp-to-ground_
                CrossTrackSimplifierstream simplify(*ps, ctx.simplifyFactor);
                if(!(hints&GLGeometryBatchBuilder::SimplificationDisabled) && (altmode == TAK::Engine::Feature::TEAM_ClampToGround))
                    ps = &simplify;
                TessellatePointStream tessellate(*ps, tessellationThresholdMeters);
                if(!(hints&GLGeometryBatchBuilder::TessellationDisabled))
                    ps = &tessellate;
                RelativeAltPointStream agl(*ps, *ctx.callback);
                if (altmode == TAK::Engine::Feature::TEAM_Relative)
                    ps = &agl;
                // inject labels before extrusion
                if (ctx.style.composite.label) {
                    labeler.reset(*ps);
                    ps = &labeler;
                }
                HemisphereNormalizationPointStream idlHandler(*ps);
                if (!(hints&GLGeometryBatchBuilder::AntiMeridianHandlingDisabled) && (altmode == TAK::Engine::Feature::TEAM_ClampToGround))
                    ps = &idlHandler;
                LineStripSegmentizer segments(*ps, altmode, ctx.style.stroke.endCap);
                SegmentExtruder extruder(segments, extrude, ctx.style.stroke.extrude, *ctx.callback);
                if (extrude)
                    ps = &extruder;
                else
                    ps = &segments;
                    
                ps->start(vw);
                if (!(hints&GLGeometryBatchBuilder::AntiMeridianHandlingDisabled) && idlHandler.primaryHemi) {
                    // if crosses IDL, generate primitives for opposite hemisphere
                    idlHandler.primaryHemi *= -1;
                    ps->start(vw);
                }
            } else if (geom.getType() == atakmap::feature::Geometry::POLYGON) {
                PolygonLineStripPointStream polygon(static_cast<const atakmap::feature::Polygon &>(geom));
                PointStream *ps = &polygon;
                // apply simplification if _clamp-to-ground_
                CrossTrackSimplifierstream simplify(polygon, ctx.simplifyFactor);
                if(!(hints&GLGeometryBatchBuilder::SimplificationDisabled) && (altmode == TAK::Engine::Feature::TEAM_ClampToGround))
                    ps = &simplify;
                TessellatePointStream tessellate(*ps, tessellationThresholdMeters);
                if(!(hints&GLGeometryBatchBuilder::TessellationDisabled))
                    ps = &tessellate;
                RelativeAltPointStream agl(*ps, *ctx.callback);
                RelativeBasePointStream base(*ps, *ctx.callback);
                if(altmode != TAK::Engine::Feature::TEAM_Relative)
                    ps = &tessellate;
                else if (extrude < 0.0)
                    ps = &base;
                else // extrude >= 0.0
                    ps = &agl;
                // inject labels before extrusion
                if (ctx.style.composite.label) {
                    labeler.reset(*ps);
                    ps = &labeler;
                }
                HemisphereNormalizationPointStream idlHandler(*ps);
                if (!(hints&GLGeometryBatchBuilder::AntiMeridianHandlingDisabled) && altmode == TAK::Engine::Feature::TEAM_ClampToGround)
                    ps = &idlHandler;
                LineStripSegmentizer segments(*ps, altmode, ctx.style.stroke.endCap);
                SegmentExtruder extruder(segments, extrude, ctx.style.stroke.extrude, *ctx.callback);
                if (extrude)
                    ps = &extruder;
                else
                    ps = &segments;
                    
                ps->start(vw);
                if (!(hints&GLGeometryBatchBuilder::AntiMeridianHandlingDisabled) && idlHandler.primaryHemi) {
                    // if crosses IDL, generate primitives for opposite hemisphere
                    idlHandler.primaryHemi *= -1;
                    ps->start(vw);
                }
            }
        } else if(ctx.style.composite.label) {
            // label only
            if (ctx.style.label.text) {
                if((hints&GLGeometryBatchBuilder::IconDeclutter) && (geom.getType() == atakmap::feature::Geometry::POINT)) {
                    const auto &pointGeom = static_cast<const atakmap::feature::Point&>(geom);
                    do {
                        if (TE_ISNAN(ctx.batchContext.camera.latitude) || TE_ISNAN(ctx.batchContext.camera.longitude))
                            break;
                        const double pd = GeoPoint2_distance(ctx.batchContext.camera, GeoPoint2(pointGeom.y, pointGeom.x), true);
                        if(pd >= (ctx.batchContext.resolution.gsdRange * _iconDeclutterRangeFactor)) {
                            ctx.style.composite.label = 0;
                            return TE_Ok;
                        }
                    } while(false);
                }
                TAK::Engine::Feature::Geometry2Ptr geom2(nullptr, nullptr);
                TAK::Engine::Feature::LegacyAdapters_adapt(geom2, geom);
                labeler.labels.back().setGeometry(*geom2);
                labeler.labels.back().setAltitudeMode(altmode);
                ctx.labels.push_back(std::move(labeler.labels.back()));
            }
        }

        // record primitive output, ignoring label
        ctx.batchedPrimitives +=
                ctx.style.composite.arrow +
                ctx.style.composite.mesh +
                ctx.style.composite.pattern +
                ctx.style.composite.icon +
                ctx.style.composite.basicStroke +
                ctx.style.composite.basicFill +
                ctx.style.composite.basicPoint;

        return TE_Ok;
    }

    bool GLGeometryBatchBuilder_init() NOTHROWS
    {
#if 0
    struct _LineBufferLayout {
        GLfloat position0[3];       // 0...11
        GLfloat position1[3];       // 12..23
        GLubyte color[4];           // 24..27
        GLuint id;                  // 28..31
        GLushort pattern;           // 32..33
        GLubyte cap[2];             // 34..35
        GLubyte factor;             // 36..
        GLubyte halfStrokeWidth;    // 37..
        GLubyte minLod;             // 38..
        GLubyte maxLod;             // 39..
    };
#endif
        // layout
# define declVertexLayout(ss, ll, ff, count, type, normalize) \
    layout.vertex.ll.ff = GLVertexArray(count, type, normalize, sizeof(ss), offsetof(ss, ff))

        declVertexLayout(_LineBufferLayout, antiAliasedLines, position0, 3u, GL_FLOAT, false);
        declVertexLayout(_LineBufferLayout, antiAliasedLines, position1, 3u, GL_FLOAT, false);
        declVertexLayout(_LineBufferLayout, antiAliasedLines, color, 4u, GL_UNSIGNED_BYTE, true);
        declVertexLayout(_LineBufferLayout, antiAliasedLines, id, 4u, GL_UNSIGNED_BYTE, true);
        declVertexLayout(_LineBufferLayout, antiAliasedLines, pattern, 1u, GL_UNSIGNED_SHORT, false);
        declVertexLayout(_LineBufferLayout, antiAliasedLines, cap, 2u, GL_BYTE, false);
        declVertexLayout(_LineBufferLayout, antiAliasedLines, factor, 1u, GL_UNSIGNED_BYTE, false);
        declVertexLayout(_LineBufferLayout, antiAliasedLines, halfStrokeWidth, 1u, GL_UNSIGNED_BYTE, false);
        declVertexLayout(_LineBufferLayout, antiAliasedLines, minLod, 1u, GL_UNSIGNED_BYTE, false);
        declVertexLayout(_LineBufferLayout, antiAliasedLines, maxLod, 1u, GL_UNSIGNED_BYTE, false);
        
        declVertexLayout(_LineBufferLayout, arrows, position0, 3u, GL_FLOAT, false);
        declVertexLayout(_LineBufferLayout, arrows, position1, 3u, GL_FLOAT, false);
        declVertexLayout(_LineBufferLayout, arrows, color, 4u, GL_UNSIGNED_BYTE, true);
        declVertexLayout(_LineBufferLayout, arrows, id, 4u, GL_UNSIGNED_BYTE, true);
        declVertexLayout(_LineBufferLayout, arrows, minLod, 1u, GL_UNSIGNED_BYTE, false);
        declVertexLayout(_LineBufferLayout, arrows, maxLod, 1u, GL_UNSIGNED_BYTE, false);
        declVertexLayout(_LineBufferLayout, arrows, radius, 1u, GL_UNSIGNED_BYTE, false);

#if 0
    struct _PointBufferLayout {
        GLfloat position[3];            // 0...11
        GLfloat surfacePosition[3];     // 12..23
        GLshort rotation[2];            // 24..27
        GLushort spriteBottomLeft[2];   // 28..31
        GLushort spriteDimensions[2];   // 32..35
        GLfloat pointSize;              // 36..39
        GLubyte color[4];               // 40..43
        GLuint id;                      // 44..47
        GLubyte absoluteRotationFlag;   // 48..
        GLubyte minLod;                 // 49..
        GLubyte maxLod;                 // 50..
        GLubyte reserved[1u];           // 51..
        GLshort offset[2];              // 52..55
    };
#endif
        declVertexLayout(_PointBufferLayout, points, position, 3u, GL_FLOAT, GL_FALSE);  
        declVertexLayout(_PointBufferLayout, points, surfacePosition, 3u, GL_FLOAT, GL_FALSE);
        declVertexLayout(_PointBufferLayout, points, rotation, 2u, GL_SHORT, GL_TRUE);
        declVertexLayout(_PointBufferLayout, points, spriteBottomLeft, 2u, GL_UNSIGNED_SHORT, GL_TRUE);
        declVertexLayout(_PointBufferLayout, points, spriteDimensions, 2u, GL_UNSIGNED_SHORT, GL_TRUE);
        declVertexLayout(_PointBufferLayout, points, pointSize, 1u, GL_FLOAT, GL_FALSE);
        declVertexLayout(_PointBufferLayout, points, color, 4u, GL_UNSIGNED_BYTE, GL_TRUE);
        declVertexLayout(_PointBufferLayout, points, id, 4u, GL_UNSIGNED_BYTE, GL_TRUE);
        declVertexLayout(_PointBufferLayout, points, absoluteRotationFlag, 1u, GL_UNSIGNED_BYTE, GL_FALSE);
        declVertexLayout(_PointBufferLayout, points, minLod, 1u, GL_UNSIGNED_BYTE, GL_FALSE);
        declVertexLayout(_PointBufferLayout, points, maxLod, 1u, GL_UNSIGNED_BYTE, GL_FALSE);
        declVertexLayout(_PointBufferLayout, points, offset, 2u, GL_SHORT, GL_FALSE);

#if 0
    struct _PolygonBufferLayout {
        GLfloat position0[3];
        GLuint id;
        GLubyte color[4];
        GLubyte outlineWidth;
        GLubyte exteriorVertex;
        GLubyte minLod;
        GLubyte maxLod;
    };
#endif
        declVertexLayout(_PolygonBufferLayout, polygons, position, 3u, GL_FLOAT, GL_FALSE);
        declVertexLayout(_PolygonBufferLayout, polygons, id, 4u, GL_UNSIGNED_BYTE, GL_TRUE);
        declVertexLayout(_PolygonBufferLayout, polygons, color, 4u, GL_UNSIGNED_BYTE, GL_TRUE);
        declVertexLayout(_PolygonBufferLayout, polygons, outlineWidth, 1u, GL_UNSIGNED_BYTE, GL_FALSE);
        declVertexLayout(_PolygonBufferLayout, polygons, exteriorVertex, 1u, GL_UNSIGNED_BYTE, GL_FALSE);
        declVertexLayout(_PolygonBufferLayout, polygons, minLod, 1u, GL_UNSIGNED_BYTE, GL_FALSE);
        declVertexLayout(_PolygonBufferLayout, polygons, maxLod, 1u, GL_UNSIGNED_BYTE, GL_FALSE);

#if 0
    struct _MeshBufferLayout {
        GLfloat vertexCoord[3];
        GLuint id;
        GLubyte color[4];
        GLubyte minLod;
        GLubyte maxLod;
        GLubyte reserved[2u];
        GLfloat transform[16];
    };
#endif
        declVertexLayout(_MeshBufferLayout, meshes, vertexCoord, 3u, GL_FLOAT, GL_FALSE);
        declVertexLayout(_MeshBufferLayout, meshes, spriteBottomLeft, 2u, GL_UNSIGNED_SHORT, GL_TRUE);
        declVertexLayout(_MeshBufferLayout, meshes, spriteTopRight, 2u, GL_UNSIGNED_SHORT, GL_TRUE);
        declVertexLayout(_MeshBufferLayout, meshes, id, 4u, GL_UNSIGNED_BYTE, GL_TRUE);
        declVertexLayout(_MeshBufferLayout, meshes, color, 4u, GL_UNSIGNED_BYTE, GL_TRUE);
        declVertexLayout(_MeshBufferLayout, meshes, minLod, 1u, GL_UNSIGNED_BYTE, GL_FALSE);
        declVertexLayout(_MeshBufferLayout, meshes, maxLod, 1u, GL_UNSIGNED_BYTE, GL_FALSE);
        declVertexLayout(_MeshBufferLayout, meshes, transform, 16u, GL_FLOAT, GL_FALSE);

#undef declVertexLayout

        return true;
    }
}
