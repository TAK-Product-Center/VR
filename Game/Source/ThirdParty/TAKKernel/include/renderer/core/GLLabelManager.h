#ifndef TAK_ENGINE_RENDERER_CORE_GLLABELMANAGER_H_INCLUDED
#define TAK_ENGINE_RENDERER_CORE_GLLABELMANAGER_H_INCLUDED

#include "core/GeoPoint.h"
#include "feature/Geometry2.h"
#include "math/Point2.h"
#include "port/Platform.h"
#include "renderer/core/GLGlyphBatch.h"
#include "renderer/core/GLLabel.h"
#include "renderer/core/GLAsynchronousMapRenderable3.h"
#include "renderer/core/controls/ClampToGroundControl.h"
#include "renderer/GLRenderBatch2.h"
#include "renderer/GLRenderContext.h"
#include "renderer/GLTextureAtlas2.h"
#include "thread/Mutex.h"
#include "util/StringMap.h"

#include <functional>
#include <vector>

namespace
{
    class AtlasTextFormat;
}

namespace TAK
{
    namespace Engine
    {
        namespace Renderer
        {
            namespace Core
            {
                class ENGINE_API GLLabelManager : public TAK::Engine::Renderer::Core::GLAsynchronousMapRenderable3
                {
                public:
#ifdef __ANDROID__
                    // UINT32_MAX does not appear to be defined in
                    // <cstdint> or <stdint.h> for NDK
                    static const uint32_t NO_ID = 0xFFFFFFFFu;
#else
                    static const uint32_t NO_ID = UINT32_MAX;
#endif
                private:
                    class RenderCore;
                public:
                    GLLabelManager();
                    virtual ~GLLabelManager();
                public:
                    void resetFont() NOTHROWS;
                    uint32_t addLabel(GLLabel& label) NOTHROWS;
                    void removeLabel(const uint32_t id) NOTHROWS;
                    void setGeometry(const uint32_t id, const TAK::Engine::Feature::Geometry2& geometry) NOTHROWS;
                    void setAltitudeMode(const uint32_t id, const TAK::Engine::Feature::AltitudeMode altitude_mode) NOTHROWS;
                    void setText(const uint32_t id, const TAK::Engine::Port::String text) NOTHROWS;
                    void setTextFormat(const uint32_t id, const TextFormatParams* fmt) NOTHROWS;
                    void setVisible(const uint32_t id, const bool visible) NOTHROWS;
                    void setAlwaysRender(const uint32_t id, const bool always_render) NOTHROWS;
                    void setMaxDrawResolution(const uint32_t id, const double max_draw_resolution) NOTHROWS;
                    void setAlignment(const uint32_t id, const TextAlignment alignment) NOTHROWS;
                    void setHorizontalAlignment(const uint32_t id, const HorizontalAlignment alignment) NOTHROWS;
                    void setVerticalAlignment(const uint32_t id, const VerticalAlignment alignment) NOTHROWS;
                    void setDesiredOffset(const uint32_t id, const Math::Point2<double>& desired_offset) NOTHROWS;
                    void setColor(const uint32_t id, const int color) NOTHROWS;
                    void setBackColor(const uint32_t id, const int color) NOTHROWS;
                    void setFill(const uint32_t id, const bool fill) NOTHROWS;
                    void setRotation(const uint32_t id, const float rotation, const bool absolute) NOTHROWS;
                    void setPriority(const uint32_t, const Priority priority) NOTHROWS;
                    void setHints(const uint32_t id, const unsigned int hints) NOTHROWS;
                    unsigned int getHints(const uint32_t id) NOTHROWS;
                    void setFloatWeight(const uint32_t id, const float weight) NOTHROWS;
                    void getSize(const uint32_t id, atakmap::math::Rectangle<double>& size_rect) NOTHROWS;
                    void setVisible(const bool visible) NOTHROWS;
                    /**
                     * @param minLod rendered if current level of detail is greater than or equal to
                     * @param maxLod rendered if current level of detail is less than
                     */
                    void setLevelOfDetail(const uint32_t id, const std::size_t minLod, const std::size_t maxLod) NOTHROWS;

                    void setHitTestable(const uint32_t id, const bool value) NOTHROWS;
                    void setHeightInMeters(const uint32_t id, const double heightInMeters) NOTHROWS;

                    Util::TAKErr hitTest(Port::Collection<uint32_t> &hitids, const float viewportX, const float viewportY, const float radius, const std::size_t limit) NOTHROWS;
                    Util::TAKErr hitTest(Port::Collection<uint32_t> &hitids, const float viewportX, const float viewportY, const float radius, const atakmap::core::GeoPoint* geoPoint, const std::size_t limit) NOTHROWS;

                    /**
                     * Sets the current priority level for the label manager. Labels will only be
                     * rendered if their priority level is greater than or equal to the specified
                     * priority.
                     */
                    void setPriorityLevel(const Priority priority) NOTHROWS;
                    /**
                     * Gets the current priority level for the label manager.
                     */
                    Priority getPriorityLevel() NOTHROWS;
                private :
                    static void glHitTest(void* opaque) NOTHROWS;
                private :
                    void updateLabel(const uint32_t id, std::function<void(GLLabel &)> updatefn) NOTHROWS;
                private :
                    bool shouldUseFallbackMethod(GLLabel& label) NOTHROWS;
                private:
                    static void adjustForSurface(GLLabel& label, const GLGlobeBase::State& state, AtlasTextFormat& tf);
                protected : // GLAsynchronousMapRenderable3
                    Util::TAKErr createQueryContext(QueryContextPtr &value) NOTHROWS override;
                    Util::TAKErr resetQueryContext(QueryContext &pendingData) NOTHROWS override;
                private:
                    Util::TAKErr getRenderables(Port::Collection<GLMapRenderable2 *>::IteratorPtr &iter) NOTHROWS override;
                protected :
                    Util::TAKErr updateRenderableLists(QueryContext &pendingData) NOTHROWS override;
                    Util::TAKErr releaseImpl() NOTHROWS override;
                    Util::TAKErr query(QueryContext &result, const GLGlobeBase::State &state)  NOTHROWS override;
                private :
                    void queryImpl(QueryContext &result, const GLGlobeBase::State &state, const Priority priority, std::vector<GLLabel::LabelPlacement>& label_placements) NOTHROWS;
                public :
                    void invalidate() NOTHROWS;
                public: // GLMapRenderable2
                    void draw(const GLGlobeBase& view, const int render_pass) NOTHROWS override;
                    int getRenderPass() NOTHROWS override;
                    void start() NOTHROWS override;
                    void stop() NOTHROWS override;
                private:
                    void draw(const GLGlobeBase& view, const std::vector<uint32_t> &idsToRender,
                              std::vector<GLLabel::LabelPlacement>& label_placements, const bool forceClampToGround, const int render_pass) NOTHROWS;
                private:
                    static float defaultFontSize;
                    GLText2* getDefaultText() NOTHROWS;
                    static TextFormatParams* getDefaultTextFormatParams() NOTHROWS;
                public:
                    float labelRotation;
                    bool absoluteLabelRotation;
                    int64_t labelFadeTimer;
                // GlyphAtlas {
                private:
                    std::shared_ptr<GLGlyphBatchFactory> glyph_batch_factory_;
                    std::unique_ptr<GLGlyphBatch> glyph_batch_;

                    Util::TAKErr loadAtlas(GLGlyphBatchFactory& factory, const char* font, const char* style, const char* type) NOTHROWS;
                    GlyphBuffersOpts toGlyphBuffersOpts(const GLLabel &label, bool adjustFontNameIfInvalid = true) NOTHROWS;

                    std::shared_ptr<GLGlyphBatchFactory> defaultGlyphBatchFactory() NOTHROWS;
                    void batchGlyphs(const GLGlobeBase& view, GLGlyphBatch& glyphBatch, GLLabel& label) NOTHROWS;
                    void batchGlyphs(const GLGlobeBase& view, GLGlyphBatch& glyphBatch, GLLabel& label, const GLLabel::LabelPlacement& placement) NOTHROWS;
                    void drawBatchedGlyphs(const GLGlobeBase& view, const bool xrayPass) NOTHROWS;
                // } GlyphAtlas
                private:
                    friend ENGINE_API Util::TAKErr GLLabelManager_updateLabel(GLLabelManager& lmgr, uint32_t labelID, GLLabel&& label) NOTHROWS;
                private:
                    GLText2* defaultText;
                    std::map<uint32_t, GLLabel> labels_;
                    //std::map<Priority, std::set<uint32_t>> label_priorities_;
                    struct {
                        std::size_t locked {0u};
                        std::size_t modCount{ 0u };
                        struct {
                            std::map<uint32_t, GLLabel> added;
                            std::map<uint32_t, GLLabel> updated;
                            std::set<uint32_t> removed;
                            std::map<Priority, std::set<uint32_t>> priorityUpdates;
                            bool replaceLabels{false};
                            bool refreshRequested{false};
                        } modifyBuffer;
                    } labels;
                    // type : { font : style[] }
                    Util::StringMap<Util::StringMap<Util::StringSet<Port::StringLess>>> loadedFonts_;
                    Util::StringMap<Util::StringMap<Util::StringSet<Port::StringLess>>> invalidFonts_;
                    Util::StringMap<Util::StringMap<Util::StringSet<Port::StringLess>>> fontsToLoad_;
                    Util::StringSet<Port::StringLess> legacyFonts_;
                    uint32_t map_idx_;
                    uint32_t always_render_idx_;
                    int draw_version_;
                    bool replace_labels_;
                    std::unique_ptr<TAK::Engine::Renderer::GLRenderBatch2> batch_;
                    bool visible_;
                    std::vector<uint32_t> idsToRenderSprite_;
                    std::vector<uint32_t> idsToRenderSurface_;
                    std::size_t drawModCount_{ 0u };
                    std::size_t glyphFactoryVersion_{ 0u };
                    struct
                    {
                        bool initialized_{ false };
                        Controls::ClampToGroundControl *value_ { nullptr };
                    } clamp_to_ground_control;
                    Priority priority_level_;
                };

                typedef std::unique_ptr<GLLabelManager, void(*)(const GLLabelManager*)> GLLabelManagerPtr;

                /**
                 * Extension method to update an entire label in one step, so that all updates are synchronized
                 */
                ENGINE_API Util::TAKErr GLLabelManager_updateLabel(GLLabelManager& lmgr, uint32_t labelID, GLLabel&& label) NOTHROWS;
            }
        }
    }
}

#endif //TAK_ENGINE_RENDERER_CORE_GLLABELMANAGER_H_INCLUDED
