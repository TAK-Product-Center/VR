#ifndef TAK_ENGINE_RENDERER_FEATURE_GLBATCHGEOMETRYFEATUREDATASTORERENDERER3_H_INCLUDED
#define TAK_ENGINE_RENDERER_FEATURE_GLBATCHGEOMETRYFEATUREDATASTORERENDERER3_H_INCLUDED

#include <list>
#include <map>
#include <memory>
#include <set>

#include "feature/FeatureDataStore2.h"
#include "feature/FeatureHitTestControl.h"
#include "renderer/AsyncBitmapLoader2.h"
#include "renderer/GLRenderContext.h"
#include "renderer/GLTextureAtlas2.h"
#include "renderer/core/GLAsynchronousMapRenderable3.h"
#include "renderer/core/GLGlobeBase.h"
#include "renderer/core/controls/FeaturesLabelControl.h"
#include "renderer/feature/DefaultSpatialFilterControl.h"
#include "renderer/feature/GLBatchGeometryRenderer4.h"
#include "util/StringMap.h"

namespace TAK {
    namespace Engine {
        namespace Renderer {
            namespace Feature {
                class ENGINE_API GLBatchGeometryFeatureDataStoreRenderer3 :
                    public TAK::Engine::Renderer::Core::GLAsynchronousMapRenderable3,
                    public TAK::Engine::Feature::FeatureDataStore2::OnDataStoreContentChangedListener,
                    TAK::Engine::Util::NonCopyable
                {
                private :
                    class FeaturesLabelControlImpl;
                public :
                    enum FeaturePresort
                    {
                        None = 0x0u,
                        Nadir = 0x1u,
                        OffNadir = 0x2u,
                    };
                    struct Options
                    {
                        struct {
                            const atakmap::feature::Geometry::Type* types{ nullptr };
                            std::size_t count{ 0u };
                        } geometryFilter;
                        bool labelsEnabled{ true };
                        bool tessellationDisabled{ true };
                        bool terrainCollisionEnabled{ true };
                        unsigned int featuresPresorted {FeaturePresort::None};
                        std::shared_ptr<GLTextureAtlas2> spritesheet;
                        bool defaultIconOnLoadFailure {true};
                        bool simplificationEnabled{true};
                        bool antiMeridianHandlingEnabled{true};
                        bool forceLabelUpdateOnQuery{false};
                        bool touchLabelVisibility{false};
                        bool labelOnlyPrecedence{true};
                        bool skipNoStyleFeatures{false};
                    };
                public:
                    GLBatchGeometryFeatureDataStoreRenderer3(TAK::Engine::Core::RenderContext &surface, TAK::Engine::Feature::FeatureDataStore2 &subject) NOTHROWS;
                    /**
                     * @param filteredTypes     specifies geoemtry types that will be ignored by the renderer
                     * @param filterTypesCount  The number of entries in `filteredTypes`
                     */
                    GLBatchGeometryFeatureDataStoreRenderer3(TAK::Engine::Core::RenderContext &surface, TAK::Engine::Feature::FeatureDataStore2 &subject, const atakmap::feature::Geometry::Type *filteredTypes, const std::size_t filteredTypesCount) NOTHROWS;
                    GLBatchGeometryFeatureDataStoreRenderer3(TAK::Engine::Core::RenderContext &surface, TAK::Engine::Feature::FeatureDataStore2 &subject, const atakmap::feature::Geometry::Type *filteredTypes, const std::size_t filteredTypesCount, const bool tessellationDisabled) NOTHROWS;
                    GLBatchGeometryFeatureDataStoreRenderer3(TAK::Engine::Core::RenderContext &surface, TAK::Engine::Feature::FeatureDataStore2 &subject, const Options &opts) NOTHROWS;
                public:
                    Util::TAKErr getControl(void **ctrl, const char *type) const NOTHROWS;
                public: // GLAsynchronousMapRenderable
                    void draw(const TAK::Engine::Renderer::Core::GLGlobeBase &view, const int renderPass) NOTHROWS override;
                    int getRenderPass() NOTHROWS override;
                    void start() NOTHROWS override;
                    void stop() NOTHROWS override;
                    void release() NOTHROWS override;
                private :
                    Util::TAKErr getRenderables(Port::Collection<TAK::Engine::Renderer::Core::GLMapRenderable2 *>::IteratorPtr &iter) NOTHROWS override;
                protected:
                    void initImpl(const Core::GLGlobeBase &view) NOTHROWS override;
                    Util::TAKErr releaseImpl() NOTHROWS override;
                    Util::TAKErr createQueryContext(QueryContextPtr &value) NOTHROWS override;
                    Util::TAKErr resetQueryContext(QueryContext &pendingData) NOTHROWS override;
                    Util::TAKErr updateRenderableLists(QueryContext &pendingData) NOTHROWS override;
                    Util::TAKErr getBackgroundThreadName(Port::String &value) NOTHROWS override;
                    Util::TAKErr query(QueryContext &result, const TAK::Engine::Renderer::Core::GLGlobeBase::State &state) NOTHROWS override;
                    virtual void drawImpl(const TAK::Engine::Renderer::Core::GLGlobeBase &view, const int renderPass) NOTHROWS;
                private:
                    Util::TAKErr queryImpl(QueryContext &result, const TAK::Engine::Renderer::Core::GLGlobeBase::State &state) NOTHROWS;
                public: // FeatureDataStore2.OnDataStoreContentChangedListener
                    void onDataStoreContentChanged(TAK::Engine::Feature::FeatureDataStore2 &data_store) NOTHROWS override;
                    /**************************************************************************/
                    // Hit Test Service

                public:
                    virtual Util::TAKErr hitTest2(Port::Collection<int64_t> &features, const float screenX, const float screenY, const atakmap::core::GeoPoint &touch, const double resolution, const float radius, const std::size_t limit) NOTHROWS;
                public: // Feature Editor Control
                    Util::TAKErr startEditing(const int64_t fid) NOTHROWS;
                    Util::TAKErr stopEditing(const int64_t fid) NOTHROWS;
                    Util::TAKErr updateFeature(const int64_t fid, const unsigned updatePropertyMask, const char * name, const atakmap::feature::Geometry *geometry, const atakmap::feature::Style *style, const TAK::Engine::Feature::AltitudeMode altitudeMode, const double extrude) NOTHROWS;
                private:
                    std::list<TAK::Engine::Renderer::Core::GLMapRenderable2 *> renderList;
                    TAK::Engine::Core::RenderContext &surface;
                    GLBatchGeometryRenderer4 renderer;
                    GLBatchGeometryRenderer4 editRenderer;
                    std::size_t iconDimensionConstraint;
                    TAK::Engine::Feature::FeatureDataStore2 &dataStore;
                    std::shared_ptr<TAK::Engine::Feature::FeatureHitTestControl> hittest;
                    std::size_t validContext;
                    const Renderer::Core::GLGlobeBase* currentView{ nullptr };
                    struct {
                        /** currently editing */
                        std::map<int64_t, std::shared_ptr<const TAK::Engine::Feature::Feature2>> editing;
                        /** previously in `editing`, waiting for refresh from query to evict */
                        struct {
                            std::map<int64_t, std::shared_ptr<const TAK::Engine::Feature::Feature2>> pending;
                            std::map<int64_t, std::shared_ptr<const TAK::Engine::Feature::Feature2>> purgeable;
                        } edited;
                        QueryContextPtr ctx{QueryContextPtr(nullptr, nullptr)};
                        struct {
                            bool features {false};
                            bool hitids {false};
                        } dirty;
                    } editor;
                    struct {
                        std::map<uint32_t, int64_t> features;
                        std::map<uint32_t, int64_t> labels;
                    } hitids;
                    struct {
                        /**
                         * bitmask of geometry types to be ignored by `query`. Masks are constructed
                         * by shifting `1u` by corresponding `GeometryClass` cast as `unsigned`
                         */
                        unsigned mask{ 0u };
                        std::set<atakmap::feature::Geometry::Type> accept;
                        std::set<atakmap::feature::Geometry::Type> reject;
                    } filteredGeometryTypes;
                    Options opts;

                    struct
                    {
                        Util::StringMap<TAK::Engine::Renderer::AsyncBitmapLoader2::Task> loading;
                        Util::StringSet<Port::StringLess> failed;
                        Port::String defaultIconUri;
                        std::shared_ptr<TAK::Engine::Renderer::GLTextureAtlas2> atlas;
                        Thread::Mutex mutex;
                        bool preloaded{false};
                        bool defaultIconOnLoadFailure{true};
                    } iconLoader;

                    std::map<std::string, std::shared_ptr<const TAK::Engine::Model::Mesh>> loadedMeshes;

                    DefaultSpatialFilterControl spatialFilterControl;
                    struct {
                        bool initialized{false};
                        TAK::Engine::Renderer::Core::Controls::ClampToGroundControl *value {nullptr};
                        /** tracks state during last call to `draw` on sprites pass */
                        bool lastDrawForceClampToGround {false};
                    } clampToGroundControl;

                    std::unique_ptr<FeaturesLabelControlImpl, void(*)(const FeaturesLabelControlImpl *)> featuresLabelControl;
                protected :
                    std::shared_ptr<int> labelRenderPump;
                private :
                    struct {
                        int idx{ -1 };
                        std::size_t resultsCount{ 0u };
                        unsigned queryTime{ 0u };
                    } metrics;
                };
            }
        }
    }
}

#endif
