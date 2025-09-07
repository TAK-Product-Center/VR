#include "renderer/core/GLLabelManager.h"

#include <unordered_map>
#include <sstream>

#include "elevation/ElevationManager.h"
#include "renderer/AsyncBitmapLoader2.h"
#include "renderer/GLES20FixedPipeline.h"
#include "renderer/core/GLMapRenderGlobals.h"
#include "renderer/core/GLMapView2.h"
#include "thread/Lock.h"
#include "util/ConfigOptions.h"

using namespace TAK::Engine::Renderer::Core;

using namespace TAK::Engine::Core;
using namespace TAK::Engine::Elevation;
using namespace TAK::Engine::Math;
using namespace TAK::Engine::Renderer;
using namespace TAK::Engine::Thread;
using namespace TAK::Engine::Util;

using namespace atakmap::renderer;
using namespace atakmap::core;

namespace {
typedef std::function<double(double, double)> TerrainLookupFallback;

TAK::Engine::Port::String defaultFontName;
std::unique_ptr<TextFormatParams> defaultTextFormatParams(nullptr);

class AtlasTextFormat : public TextFormat2 {
public:
    ~AtlasTextFormat() override;
    float getStringWidth(const char* text) NOTHROWS override;
    float getCharPositionWidth(const char* text, int position) NOTHROWS override;
    float getCharWidth(const unsigned int chr) NOTHROWS override;
    float getCharHeight() NOTHROWS override;
    float getDescent() NOTHROWS override;
    float getStringHeight(const char* text) NOTHROWS override;
    float getBaselineSpacing() NOTHROWS override;
    int getFontSize() NOTHROWS override;
    TAK::Engine::Util::TAKErr loadGlyph(BitmapPtr& value, const unsigned int c) NOTHROWS override;
    GLGlyphBatchFactory2* ftor_{nullptr};
    GLText2* gltext_{nullptr};
    double font_size{0.0};
    GlyphBuffersOpts opts;
};

    inline GlyphHAlignment toGlyphHAlignment(TextAlignment a) {
        switch (a) {
            case TextAlignment::TETA_Left: return GlyphHAlignment_Left;
            default:
            case TextAlignment::TETA_Center: return GlyphHAlignment_Center;
            case TextAlignment::TETA_Right: return GlyphHAlignment_Right;
        }
    }


struct QueryContextImpl : GLAsynchronousMapRenderable3::QueryContext
{
    /** IDs of labels selected for sprite render */
    std::list<uint32_t> renderSpriteIds;
    /** IDs of labels selected for surface render */
    std::list<uint32_t> renderSurfaceIds;
    std::size_t fetchid{ 1u };
    std::size_t lastFetchid{ 0u };
    bool contentChanged{ false };
    std::vector<uint32_t> invalidLabelsIds;
};

struct LabelsLock
{
public :
    LabelsLock(Monitor &m, std::size_t &l) NOTHROWS :
        lock(l),
        monitor(m)
    {
        Monitor::Lock mlock(monitor);
        lock++;
    }
    ~LabelsLock() NOTHROWS
    {
        Monitor::Lock mlock(monitor);
        lock--;
    }
private :
    std::size_t &lock;
    Monitor &monitor;
};

struct {
    float charHeight{ 0.f };
    float descent{ 0.f };
    float baselineSpacing{ 0.f };
} default_font_metrics;

struct HitTestArgs
{
    GLLabelManager* lblmgr{ nullptr };
    TAK::Engine::Port::Collection<uint32_t>* hitids{ nullptr };
    float radius;
    float viewportX;
    float viewportY;
    const GeoPoint* geoPoint{ nullptr };
    std::size_t limit{ 1u };
    bool done{ false };
};

}  // namespace

float GLLabelManager::defaultFontSize = 0;

GLLabelManager::GLLabelManager()
    : defaultText(nullptr),
      labelRotation(0.0),
      absoluteLabelRotation(false),
      labelFadeTimer(-1LL),
      map_idx_(1), // many instances of user code using zero as invalid ID instead of NO_ID. Rather than fixing them all, just start at 1
      always_render_idx_(NO_ID),
      draw_version_(-1),
      replace_labels_(true),
      visible_(true),
      priority_level_(Priority::TEP_Low)
{
    need_render_tiles_ = true;

    // XXX -
    AsyncBitmapLoader2 initProtoHandlers(0, false);
}

GLLabelManager::~GLLabelManager() { this->stop(); }

void GLLabelManager::resetFont() NOTHROWS {
    Monitor::Lock lock(monitor_);
    glyph_batch_factory_.reset();
}

uint32_t GLLabelManager::addLabel(GLLabel& label) NOTHROWS {
    Monitor::Lock lock(monitor_);
    const auto id = map_idx_++;

    if(labels.locked) {
        labels.modifyBuffer.added[id] = std::move(label);
        if (!labels.modifyBuffer.refreshRequested && context_) {
            context_->requestRefresh();
            labels.modifyBuffer.refreshRequested = true;
        }
    } else {
        draw_version_ = -1;
        replace_labels_ = true;
        labels_[id] = std::move(label);
        labels.modCount++;
        invalidateNoSync();
    }
    return id;
}

void GLLabelManager::removeLabel(const uint32_t id) NOTHROWS {
    Monitor::Lock lock(monitor_);

    if (map_idx_ <= id) return;
    if (labels.locked) {
        labels.modifyBuffer.removed.insert(id);
        labels.modifyBuffer.added.erase(id);
        labels.modifyBuffer.updated.erase(id);
        labels.modifyBuffer.replaceLabels = true;

        if (!labels.modifyBuffer.refreshRequested && context_) {
            context_->requestRefresh();
            labels.modifyBuffer.refreshRequested = true;
        }
    } else {
        replace_labels_ = true;
        labels_.erase(id);
        
        // evict any queued updates
        labels.modifyBuffer.added.erase(id);
        labels.modifyBuffer.updated.erase(id);

        labels.modCount++;
        invalidateNoSync();
    }
    if (always_render_idx_ == id) always_render_idx_ = NO_ID;
}

void GLLabelManager::setGeometry(const uint32_t id, const TAK::Engine::Feature::Geometry2& geometry) NOTHROWS {
    Monitor::Lock lock(monitor_);

    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl)
    {
        lbl.setGeometry(geometry);
        if (labels.locked)
            labels.modifyBuffer.replaceLabels = true;
        else
            replace_labels_ = true;
    });
}

void GLLabelManager::setAltitudeMode(const uint32_t id, const TAK::Engine::Feature::AltitudeMode altitude_mode) NOTHROWS {
    Monitor::Lock lock(monitor_);

    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl)
    {
        lbl.setAltitudeMode(altitude_mode);
        if (labels.locked)
            labels.modifyBuffer.replaceLabels = true;
        else
            replace_labels_ = true;
    });
}

void GLLabelManager::setText(const uint32_t id, TAK::Engine::Port::String text) NOTHROWS {
    Monitor::Lock lock(monitor_);

    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl)
    {
        lbl.setText(text);
        if (labels.locked)
            labels.modifyBuffer.replaceLabels = true;
        else
            replace_labels_ = true;
    });
}

void GLLabelManager::setTextFormat(const uint32_t id, const TextFormatParams* fmt) NOTHROWS {
    Monitor::Lock lock(monitor_);

    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl)
    {
        // RWI - If it's the default font just reset to null
        if (fmt == nullptr ||
            (fmt->size == defaultFontSize && fmt->fontName == nullptr && !fmt->bold && !fmt->italic && !fmt->underline && !fmt->strikethrough))
            lbl.setTextFormat(nullptr);
        else {
            lbl.setTextFormat(fmt);
        }
        if (labels.locked)
            labels.modifyBuffer.replaceLabels = true;
        else
            replace_labels_ = true;
    });
}

void GLLabelManager::setVisible(const uint32_t id, bool visible) NOTHROWS {
    Monitor::Lock lock(monitor_);

    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl)
    {
        lbl.setVisible(visible);
        if (labels.locked)
            labels.modifyBuffer.replaceLabels = true;
        else
            replace_labels_ = true;
    });
}

void GLLabelManager::setAlwaysRender(const uint32_t id, bool always_render) NOTHROWS {
    Monitor::Lock lock(monitor_);

    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl)
    {
        lbl.setAlwaysRender(always_render);
        if (always_render)
            always_render_idx_ = id;
        else if (always_render_idx_ == id)
            always_render_idx_ = NO_ID;
        if (labels.locked)
            labels.modifyBuffer.replaceLabels = true;
        else
            replace_labels_ = true;
    });
}

void GLLabelManager::setMaxDrawResolution(const uint32_t id, double max_draw_resolution) NOTHROWS {
    Monitor::Lock lock(monitor_);

    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl)
    {
        lbl.setMaxDrawResolution(max_draw_resolution);
        if (labels.locked)
            labels.modifyBuffer.replaceLabels = true;
        else
            replace_labels_ = true;
    });
}

void GLLabelManager::setAlignment(const uint32_t id, TextAlignment alignment) NOTHROWS {
    Monitor::Lock lock(monitor_);

    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl) { lbl.setAlignment(alignment); });
}

void GLLabelManager::setHorizontalAlignment(const uint32_t id, HorizontalAlignment horizontal_alignment) NOTHROWS {
    Monitor::Lock lock(monitor_);

    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl) { lbl.setHorizontalAlignment(horizontal_alignment); });
}

void GLLabelManager::setVerticalAlignment(const uint32_t id, VerticalAlignment vertical_alignment) NOTHROWS {
    Monitor::Lock lock(monitor_);

    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl) { lbl.setVerticalAlignment(vertical_alignment); });
}

void GLLabelManager::setDesiredOffset(const uint32_t id, const TAK::Engine::Math::Point2<double>& desired_offset) NOTHROWS {
    Monitor::Lock lock(monitor_);

    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl) { lbl.setDesiredOffset(desired_offset); });
}

void GLLabelManager::setColor(const uint32_t id, int color) NOTHROWS {
    Monitor::Lock lock(monitor_);

    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl) { lbl.setColor(color); });
}

void GLLabelManager::setBackColor(const uint32_t id, int color) NOTHROWS {
    Monitor::Lock lock(monitor_);

    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl) { lbl.setBackColor(color); });
}

void GLLabelManager::setFill(const uint32_t id, bool fill) NOTHROWS {
    Monitor::Lock lock(monitor_);

    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl) { lbl.setFill(fill); });
}

void GLLabelManager::setRotation(const uint32_t id, const float rotation, const bool absolute) NOTHROWS {
    Monitor::Lock lock(monitor_);
    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl) { lbl.setRotation(rotation, absolute); });
}

void GLLabelManager::getSize(const uint32_t id, atakmap::math::Rectangle<double>& size_rect) NOTHROWS {
    Monitor::Lock lock(monitor_);

    if (map_idx_ <= id) return;
    if(labels_.find(id) == labels_.end()) return;

    GLLabel& label = labels_[id];
    size_rect.width = label.labelSize.width;
    size_rect.height = label.labelSize.height;

    if (!label.transformed_anchor_.empty()) {
        size_rect.x = label.transformed_anchor_[0].render_xyz_.x;
        size_rect.y = label.transformed_anchor_[0].render_xyz_.y;
    }

    if (size_rect.width == 0 && size_rect.height == 0) {
        GLText2* gltext = label.gltext_;
        if (!gltext)
            gltext = getDefaultText();
        if (gltext) {
            size_rect.width = gltext->getTextFormat().getStringWidth(label.text_.c_str());
            size_rect.height = gltext->getTextFormat().getStringHeight(label.text_.c_str());
        }
    }
}

void GLLabelManager::setPriority(const uint32_t id, const Priority priority) NOTHROWS {
    Monitor::Lock lock(monitor_);
    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl)
    {
        lbl.setPriority(priority);
    });
}

void GLLabelManager::setHints(const uint32_t id, const unsigned int hints) NOTHROWS
{
    Monitor::Lock lock(monitor_);
    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl)
    {
        lbl.setHints(hints);
    });
}

unsigned int GLLabelManager::getHints(const uint32_t id) NOTHROWS
{
    Monitor::Lock lock(monitor_);
    if (map_idx_ <= id) return 0u;

    const auto label = labels_.find(id);
    if(label == labels_.end())
        return 0u;

    return label->second.hints_;
}

void GLLabelManager::setFloatWeight(const uint32_t id, const float weight) NOTHROWS
{
    Monitor::Lock lock(monitor_);
    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl)
    {
        lbl.setFloatWeight(weight);
    });
}
void GLLabelManager::setLevelOfDetail(const uint32_t id, const std::size_t minLod, const std::size_t maxLod) NOTHROWS
{
    Monitor::Lock lock(monitor_);
    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl)
    {
        lbl.setLevelOfDetail(minLod, maxLod);
    });
}

void GLLabelManager::setHitTestable(const uint32_t id, const bool value) NOTHROWS
{
    Monitor::Lock lock(monitor_);
    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl)
    {
        lbl.setHitTestable(value);
    });
}

void GLLabelManager::setHeightInMeters(const uint32_t id, const double heightInMeters) NOTHROWS
{
    Monitor::Lock lock(monitor_);
    if (map_idx_ <= id) return;
    updateLabel(id, [&](GLLabel& lbl)
    {
        lbl.setHeightInMeters(heightInMeters);
    });
}

void GLLabelManager::setPriorityLevel(const Priority priority) NOTHROWS
{
    priority_level_ = priority;
}
Priority GLLabelManager::getPriorityLevel() NOTHROWS
{
    return priority_level_;
}


TAKErr GLLabelManager::hitTest(TAK::Engine::Port::Collection<uint32_t>& hitids, const float viewportX, const float viewportY, const float radius, const std::size_t limit) NOTHROWS
{
    return hitTest(hitids, viewportX, viewportY, radius, nullptr, limit);
}

TAKErr GLLabelManager::hitTest(TAK::Engine::Port::Collection<uint32_t>& hitids, const float viewportX, const float viewportY, const float radius, const GeoPoint* geoPoint, const std::size_t limit) NOTHROWS
{
    if (!context_)
        return TE_IllegalState;
    HitTestArgs args;
    args.lblmgr = this;
    args.hitids = &hitids;
    args.viewportX = viewportX;
    args.viewportY = viewportY;
    args.radius = radius;
    args.geoPoint = geoPoint;
    args.limit = limit;
    if(context_->isRenderThread()) {
        const bool current = context_->isAttached();
        if (!current)
            context_->attach();
        glHitTest(&args);
        if (!current)
            context_->detach();
    } else {
        context_->queueEvent(GLLabelManager::glHitTest, std::unique_ptr<void, void(*)(const void*)>(&args, Memory_leaker_const<void>));

        Monitor::Lock lock(monitor_);
        while (!args.done)
            lock.wait();
    }

    return TE_Ok;
}
void GLLabelManager::glHitTest(void* opaque) NOTHROWS
{
    auto& arg = *static_cast<HitTestArgs *>(opaque);
    atakmap::math::Rectangle<float> hitBox;
    hitBox.x = arg.viewportX - arg.radius;
    hitBox.y = arg.viewportY - arg.radius;
    hitBox.width = arg.radius * 2.f;
    hitBox.height = arg.radius * 2.f;

    Monitor::Lock lock(arg.lblmgr->monitor_);
    auto hitTestImpl = [&arg, &hitBox](const std::vector<uint32_t> &idsToRender)
    {
        for (const auto& id : idsToRender) {
            const auto entry = arg.lblmgr->labels_.find(id);
            if (entry == arg.lblmgr->labels_.end())
                continue;
            const auto& label = entry->second;
            if (!label.isHitTestable())
                continue;
            for(const auto &anchor : label.transformed_anchor_) {
                if (label.hints_ & GLLabel::Surface) {
                    if (!arg.geoPoint || TE_ISNAN(arg.geoPoint->latitude) || TE_ISNAN(arg.geoPoint->longitude)) continue;
                    if (!atakmap::math::Rectangle<double>::contains(anchor.boundingGeometry.minlon, anchor.boundingGeometry.minlat, anchor.boundingGeometry.maxlon, anchor.boundingGeometry.maxlat,
                                                                    arg.geoPoint->longitude, arg.geoPoint->latitude)) {
                        continue;
                    }
                } else {
                    if (!atakmap::math::Rectangle<float>::intersects(hitBox.x, hitBox.y, hitBox.x + hitBox.width, hitBox.y + hitBox.height,
                                                                        anchor.boundingRect.minX, anchor.boundingRect.minY, anchor.boundingRect.maxX, anchor.boundingRect.maxY)) {
                        continue;
                    }
                }

                arg.hitids->add(id);
                if (arg.hitids->size() >= arg.limit)
                    break;
            }
        }
    };
    hitTestImpl(arg.lblmgr->idsToRenderSprite_);
    hitTestImpl(arg.lblmgr->idsToRenderSurface_);
    arg.done = true;
    lock.broadcast();
}

void GLLabelManager::setVisible(bool visible) NOTHROWS {
    Monitor::Lock lock(monitor_);

    visible_ = visible;
}

void GLLabelManager::updateLabel(const uint32_t id, std::function<void(GLLabel &)> updatefn) NOTHROWS
{
    if (labels.locked) {
        if (labels.modifyBuffer.removed.find(id) != labels.modifyBuffer.removed.end())
            return;
        do {
            auto aentry = labels.modifyBuffer.added.find(id);
            if (aentry != labels.modifyBuffer.added.end()) {
                // label is in the buffer to be added
                updatefn(aentry->second);
                break;
            }
            // label is an update
            auto uentry = labels.modifyBuffer.updated.find(id);
            if (uentry == labels.modifyBuffer.updated.end()) {
                // no label exists to update
                if(labels_.find(id) == labels_.end()) break;

                // copy
                GLLabel update(labels_[id]);
                updatefn(update);
                labels.modifyBuffer.updated.insert(std::make_pair(id, std::move(update)));
            } else {
                updatefn(uentry->second);
            }
        } while (false);

        if (!labels.modifyBuffer.refreshRequested && context_) {
            context_->requestRefresh();
            labels.modifyBuffer.refreshRequested = true;
        }
    } else if(labels_.find(id) != labels_.end()) {
        draw_version_ = -1;
        updatefn(labels_[id]);
        labels.modCount++;
        invalidateNoSync();
    }
}
void GLLabelManager::validateLabels(const GLGlobeBase::State &state) NOTHROWS {

    if (invalidLabelsIds_.empty())
        return;

    for (auto& id : invalidLabelsIds_) {
        auto labelIt = labels_.find(id);
        if (labelIt == labels_.end())
            continue;
        auto& label = labelIt->second;

        if (label.textSize.valid)
            continue;

        GLText2* gltext = label.gltext_;
        if (!gltext) gltext = defaultText;

        AtlasTextFormat tf;
        tf.ftor_ = defaultGlyphBatchFactory().get();
        tf.gltext_ = gltext;
        tf.font_size = gltext->getTextFormat().getFontSize();
        tf.opts = toGlyphBuffersOpts(state, label);
        const bool fallback_method = shouldUseFallbackMethod(label);
        TextFormat2& rtf = fallback_method ?
            gltext->getTextFormat() : tf;
        label.validateTextSize(label, rtf);
    }
    
    invalid_ = true;

    invalidLabelsIds_.clear();
}
void GLLabelManager::draw(const GLGlobeBase& view, const int render_pass) NOTHROWS {
    bool is_surface_pass = render_pass & GLGlobeBase::Surface;
    if(!clamp_to_ground_control.initialized_) {
        clamp_to_ground_control.initialized_ = true;
        void* ctrl{ nullptr };
        view.getControl(&ctrl, TAK::Engine::Renderer::Core::Controls::ClampToGroundControl_getType());
        if (ctrl)
            clamp_to_ground_control.value_ = static_cast<TAK::Engine::Renderer::Core::Controls::ClampToGroundControl*>(ctrl);
    }

    const bool forceClampToGround = clamp_to_ground_control.value_ ?
        (!view.renderPass->drawTilt && clamp_to_ground_control.value_->getClampToGroundAtNadir()) :
        false;

    std::shared_ptr<GLGlyphBatchFactory2> factory;
    {
        Monitor::Lock lock(monitor_);
        if (!context_)
            context_ = &view.context;
        if (labels.modCount != drawModCount_) {
            drawModCount_ = labels.modCount;
            draw_version_ = -1;
            invalid_ = true;
        }
        if (labels_.empty() || !visible_) return;
        

        factory = defaultGlyphBatchFactory();
        validateLabels(*view.renderPass);
    }
    
    defaultText = getDefaultText();
    GLAsynchronousMapRenderable3::draw(view, render_pass);

    std::vector<uint32_t> renderedLabels;
    {
        Monitor::Lock lock(monitor_);
        if (!labels.locked && !is_surface_pass) {
            // sync delayed modifications
            if (!labels.modifyBuffer.added.empty() || !labels.modifyBuffer.updated.empty() || !labels.modifyBuffer.removed.empty()) {
                draw_version_ = -1;
                invalid_ = true;
                if(context_)
                    context_->requestRefresh();
            }
            for (auto e : labels.modifyBuffer.added)
                labels_[e.first] = std::move(e.second);
            labels.modifyBuffer.added.clear();
            for (auto e : labels.modifyBuffer.updated) {
                // label no longer exists
                if(labels_.find(e.first) == labels_.end()) continue;

                e.second.mark_dirty_ = true;
                labels_[e.first] = std::move(e.second);
            }
            labels.modifyBuffer.updated.clear();
            for (auto id : labels.modifyBuffer.removed) {
                labels_.erase(id);
                if (id == always_render_idx_)
                    always_render_idx_ = NO_ID;
            }
            labels.modifyBuffer.removed.clear();
            replace_labels_ |= labels.modifyBuffer.replaceLabels;
            labels.modifyBuffer.replaceLabels = false;
            labels.modifyBuffer.refreshRequested = false;
        }
        const auto &idsToRender = is_surface_pass ? idsToRenderSurface_ : idsToRenderSprite_;
        renderedLabels.resize(idsToRender.size());
        memcpy(renderedLabels.data(), idsToRender.data(), idsToRender.size() * sizeof(uint32_t));
    }
    LabelsLock ll(monitor_, labels.locked);
    if (!this->batch_) {
        this->batch_.reset(new GLRenderBatch2(0xFFFF));
    }

    bool depthRestore = false;
    if (view.renderPass->drawTilt == 0) {
        depthRestore = glIsEnabled(GL_DEPTH_TEST);
        glDisable(GL_DEPTH_TEST);
    }

    bool didAnimate = false;
    try {
        if (!glyph_batch_) {
            glyph_batch_.reset(new GLGlyphBatch2());
        }
        GLES20FixedPipeline::getInstance()->glMatrixMode(GLES20FixedPipeline::MatrixMode::MM_GL_MODELVIEW);
        GLES20FixedPipeline::getInstance()->glPushMatrix();

        GLES20FixedPipeline::getInstance()->glMatrixMode(GLES20FixedPipeline::MatrixMode::MM_GL_PROJECTION);
        GLES20FixedPipeline::getInstance()->glPushMatrix();
        GLES20FixedPipeline::getInstance()->glOrthof((float)view.renderPass->left, (float)view.renderPass->right, (float)view.renderPass->bottom, (float)view.renderPass->top,
                                                     (float)view.renderPass->near, (float)view.renderPass->far);

        batch_->begin();
        {
            float mx[16];
            GLES20FixedPipeline::getInstance()->readMatrix(GLES20FixedPipeline::MatrixMode::MM_GL_PROJECTION, mx);
            this->batch_->setMatrix(GL_PROJECTION, mx);
            GLES20FixedPipeline::getInstance()->readMatrix(GLES20FixedPipeline::MatrixMode::MM_GL_MODELVIEW, mx);
            this->batch_->setMatrix(GL_MODELVIEW, mx);
        }

        std::vector<GLLabel::LabelPlacement> label_placements;

        if (draw_version_ != view.drawVersion) {
            draw_version_ = view.drawVersion;
            replace_labels_ = true;
        }
        if (always_render_idx_ != NO_ID && labels_.find(always_render_idx_) != labels_.end()) {
            GLLabel& label = labels_[always_render_idx_];

            const Feature::Geometry2* geometry = label.getGeometry();
            bool forRenderPass = !!(label.hints_ & GLLabel::Surface) == is_surface_pass;
            if (forRenderPass && geometry != nullptr) {
                GLText2 *gltext = label.gltext_;
                if (!gltext)
                    gltext = defaultText;

                AtlasTextFormat tf;
                tf.ftor_ = factory.get();
                tf.gltext_ = gltext;
                tf.font_size = gltext->getTextFormat().getFontSize();
                tf.opts = toGlyphBuffersOpts(*view.renderPass, label);
                const bool fallback_method = shouldUseFallbackMethod(label);
                if (!fallback_method) adjustForSurface(label, *view.renderPass, tf);
                TextFormat2& rtf = fallback_method ?
                    gltext->getTextFormat() : tf;

                label.setForceClampToGround(forceClampToGround);
                label.validate(view, rtf);
                for(auto &placement : label.transformed_anchor_) {
                    bool didReplace;
                    if(label.place(placement, view, label_placements, GLLabel::PlacementDeconflictMode::None, didReplace))
                        label_placements.push_back(placement);
                }
                if (fallback_method) {
                    label.batch(view, *gltext, *(batch_.get()), render_pass);
                } else {
                    batchGlyphs(view, *glyph_batch_, label);
                }
                renderedLabels.push_back(always_render_idx_);
            }
        }
        draw(view, renderedLabels, label_placements, forceClampToGround, render_pass);
        batch_->end();

        //
        // GLGlyphBatch2 rendering
        //

        if (view.renderPass->drawTilt == 0) {
            depthRestore = glIsEnabled(GL_DEPTH_TEST);
            glDisable(GL_DEPTH_TEST);
        }

        // Draw underground portion
        if (view.renderPass->drawTilt > 0) {
            int depthFunc;
            glGetIntegerv(GL_DEPTH_FUNC, &depthFunc);
            glDepthMask(GL_FALSE);
            glDepthFunc(GL_GEQUAL);
            drawBatchedGlyphs(view, true);
            glDepthFunc(depthFunc);
            glDepthMask(GL_TRUE);
        }

        drawBatchedGlyphs(view, false);

        this->glyph_batch_->clearBatchedGlyphs();

        // Check to see if we have any legacy drawing requiring XRay rendering.
        bool legacyDrawing = false;
        for(uint32_t& label_id : renderedLabels) {
            auto label_it = labels_.find(label_id);
            if(label_it == labels_.end()) continue;
            GLLabel &label = label_it->second;
            if (shouldUseFallbackMethod(label) && label.hints_ & GLLabel::XRay) {
                legacyDrawing = true;
                break;
            }
        }
        // If so, draw XRay as necessary
        if (legacyDrawing) {
            glDisable(GL_DEPTH_TEST);
            batch_->begin();
            {
                float mx[16];
                GLES20FixedPipeline::getInstance()->readMatrix(GLES20FixedPipeline::MatrixMode::MM_GL_PROJECTION, mx);
                this->batch_->setMatrix(GL_PROJECTION, mx);
                GLES20FixedPipeline::getInstance()->readMatrix(GLES20FixedPipeline::MatrixMode::MM_GL_MODELVIEW, mx);
                this->batch_->setMatrix(GL_MODELVIEW, mx);
            }
            for (uint32_t &label_id : renderedLabels) {
                auto label_it = labels_.find(label_id);
                if(label_it == labels_.end()) continue;
                GLLabel &label = label_it->second;
                if (shouldUseFallbackMethod(label) && label.hints_ & GLLabel::XRay) {
                    GLText2 *gltext = label.gltext_;
                    if (!gltext)
                        gltext = defaultText;
                    label.batch(view, *gltext, *batch_, GLGlobeBase::XRay);
                }

                // mark if any animated
                didAnimate |= label.did_animate_;
            }
            batch_->end();
            glEnable(GL_DEPTH_TEST);
        }

#if 0
        if (!is_surface_pass) {
            auto &gl = *GLES20FixedPipeline::getInstance();

            glBindBuffer(GL_ARRAY_BUFFER, GL_NONE);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_NONE);
            glDisable(GL_DEPTH_TEST);
            gl.glMatrixMode(GLES20FixedPipeline::MatrixMode::MM_GL_PROJECTION);
            gl.glOrthof((float)view.renderPass->left, (float)view.renderPass->right, (float)view.renderPass->bottom, (float)view.renderPass->top,
                                                     (float)view.renderPass->near, (float)view.renderPass->far);
            gl.glMatrixMode(GLES20FixedPipeline::MatrixMode::MM_GL_MODELVIEW);

            glLineWidth(2.f);
            float db[10];


            gl.glEnableClientState(GLES20FixedPipeline::CS_GL_VERTEX_ARRAY);
                gl.glColor4f(1.f, 0.f, 0.f, 1.f);

            for (auto& p : label_placements) {
                for (int i = 0; i < 5; i++) {
                    db[i*2] = p.boundingRect.shape[(i%4)].x;
                    db[i*2+1] = p.boundingRect.shape[(i%4)].y;
                }
                gl.glVertexPointer(2, GL_FLOAT, 0, db);
                gl.glDrawArrays(GL_LINE_STRIP, 0, 5);
            }
            gl.glDisableClientState(GLES20FixedPipeline::CS_GL_VERTEX_ARRAY);
            depthRestore = true;
        }
#endif
        GLES20FixedPipeline::getInstance()->glMatrixMode(GLES20FixedPipeline::MatrixMode::MM_GL_PROJECTION);
        GLES20FixedPipeline::getInstance()->glPopMatrix();

        GLES20FixedPipeline::getInstance()->glMatrixMode(GLES20FixedPipeline::MatrixMode::MM_GL_MODELVIEW);
        GLES20FixedPipeline::getInstance()->glPopMatrix();
    } catch (...) {
        // ignored
    }

    if (depthRestore)
        glEnable(GL_DEPTH_TEST);

    replace_labels_ = false;

    // if an animation was performed, queue up a refresh
    if(didAnimate)
        view.context.requestRefresh();
}

void GLLabelManager::draw(const GLGlobeBase& view, const std::vector<uint32_t> &idsToRender,
                          std::vector<GLLabel::LabelPlacement>& label_placements, const bool forceClampToGround, const int render_pass) NOTHROWS {
    auto &ids = idsToRender;
    auto glyphBatchFactory = defaultGlyphBatchFactory();
    bool didAnimate = false;
    bool is_surface_pass = render_pass & GLGlobeBase::Surface;

    //first render all GLLabels that do not need replacing,
    // store GLLabels that need to be replaced for later placement
    std::vector<uint32_t> nodeconflict_labels;
    std::vector<uint32_t> replaced_labels;
    for (auto it = ids.begin(); it != ids.end(); it++) {
        const uint32_t label_id = *it;
        if (label_id == always_render_idx_) continue;

        auto label_it = labels_.find(label_id);
        if (label_it == labels_.end()) continue;

        GLLabel& label = label_it->second;
        if (label.priority_ > priority_level_) continue;
        if (label.text_.empty()) continue;
        if (!label.getTextAlphaAdjust(view)) continue;

        if (!label. shouldRenderAtResolution(view.renderPass->drawMapResolution)) continue;

        GLText2* gltext = label.gltext_;
        if (!gltext) gltext = defaultText;

        AtlasTextFormat tf;
        tf.ftor_ = glyphBatchFactory.get();
        tf.gltext_ = gltext;
        tf.font_size = gltext->getTextFormat().getFontSize();
        tf.opts = toGlyphBuffersOpts(*view.renderPass, label);
        const bool fallback_method = shouldUseFallbackMethod(label);
        if (!fallback_method) adjustForSurface(label, *view.renderPass, tf);
        TextFormat2& rtf = fallback_method ?
            gltext->getTextFormat() : tf;

        label.setForceClampToGround(forceClampToGround);
        label.validate(view, rtf);

        bool didReplace = false;
        bool canDraw = false;
        const auto deconflict = (label.hints_ & GLLabel::DisableDeconflict) ?
            GLLabel::PlacementDeconflictMode::None : GLLabel::PlacementDeconflictMode::Shift;

        std::vector<GLLabel::LabelPlacement> temporaryPlacements;
        for(auto &placement : label.transformed_anchor_)
        {
            Point2<double> xyz(placement.anchor_xyz_);

            // skip points outside of the near and far clip planes
            if(placement.anchor_xyz_.z > 1.f) continue;

            // confirm location is in view
            if (!is_surface_pass && !atakmap::math::Rectangle<double>::contains(view.renderPass->left, view.renderPass->bottom, view.renderPass->right, view.renderPass->top, xyz.x, xyz.y)) continue;

            canDraw = true;

            if (replace_labels_)
            {
                if(label.place(placement, *view.renderPass, label_placements, deconflict, didReplace))
                {
                    if(!didReplace)
                    {
                        temporaryPlacements.push_back(placement);
                    }
                    else
                    {
                        replaced_labels.push_back(label_id);
                        break;
                    }
                }
            }
        }

        if(!didReplace && canDraw)
        {
            if(!temporaryPlacements.empty())
                label_placements.insert(label_placements.end(), temporaryPlacements.begin(), temporaryPlacements.end());
            if (deconflict == GLLabel::PlacementDeconflictMode::None) {
                // handle "no deconflict" labels during placement below
                nodeconflict_labels.push_back(label_id);
            } else {
                if (fallback_method) {
                    label.batch(view, *gltext, *(batch_.get()), GLGlobeBase::Sprites);
                } else {
                    batchGlyphs(view, *glyph_batch_, label);
                }
            }
        }

        // mark if any animated
        didAnimate |= fallback_method && label.did_animate_;
    }

    // place all labels marked as no-deconflict. in the case that two labels overlap, the label with the maximum height value is displayed
    if (!nodeconflict_labels.empty()) {
        // sort by height DESC
        std::sort(nodeconflict_labels.begin(), nodeconflict_labels.end(), [&](const uint32_t a_id, const uint32_t b_id)
        {
            const auto& a_lbl = labels_[a_id];
            const auto& b_lbl = labels_[b_id];

            if (a_lbl.geometry.empty && b_lbl.geometry.empty)
                return false;
            else if (a_lbl.geometry.empty)
                return false;
            else if (b_lbl.geometry.empty)
                return true;

            const auto& a_labelGeom = *a_lbl.getGeometry();
            const auto& b_labelGeom = *b_lbl.getGeometry();

            const bool a_point = a_labelGeom.getClass() == Feature::TEGC_Point;
            const bool b_point = b_labelGeom.getClass() == Feature::TEGC_Point;

            if (a_point && !b_point)
                return true;
            else if (!a_point && b_point)
                return false;
            else if (!a_point && !b_point)
                return false;

            const double a_hgt = TE_ISNAN(a_lbl.geometry.point.z) ? 0.0 : a_lbl.geometry.point.z;
            const double b_hgt = TE_ISNAN(b_lbl.geometry.point.z) ? 0.0 : b_lbl.geometry.point.z;

            return (a_hgt > b_hgt);
        });

        //rePlace and render all sprite labels that haven't been rendered
        std::vector<GLLabel::LabelPlacement> nodeconflict_placements;
        nodeconflict_placements.reserve(nodeconflict_labels.size());
        for (int label_id : nodeconflict_labels)
        {
            GLLabel& label = labels_[label_id];
            GLText2* gltext = label.gltext_;
            if (!gltext) gltext = defaultText;
            AtlasTextFormat tf;
            tf.ftor_ = glyphBatchFactory.get();
            tf.gltext_ = gltext;
            tf.font_size = gltext->getTextFormat().getFontSize();
            tf.opts = toGlyphBuffersOpts(*view.renderPass, label);
            const bool fallback_method = shouldUseFallbackMethod(label);
            TextFormat2& rtf = fallback_method ?
                gltext->getTextFormat() : tf;
            bool placed = false;
            for (auto& placement : label.transformed_anchor_) {
                // place labels. use a clean placement structure as we will use the `Discard` placement mode to only emit the "top-most" label per height
                bool didReplace;
                if (label.place(placement, view, nodeconflict_placements, GLLabel::PlacementDeconflictMode::Discard, didReplace)) {
                    nodeconflict_placements.push_back(placement);
                    placed = true;
                }
            }
            if(!placed)
                continue;
            if (fallback_method) {
                label.batch(view, *gltext, *(batch_.get()), GLGlobeBase::Sprites);
            }
            else {
                batchGlyphs(view, *glyph_batch_, label);
            }
        }
    }

    // re-place all remaining
    for(int label_id : replaced_labels)
    {
        GLLabel& label = labels_[label_id];
        GLText2* gltext = label.gltext_;
        if (!gltext) gltext = defaultText;
        AtlasTextFormat tf;
        tf.ftor_ = glyphBatchFactory.get();
        tf.gltext_ = gltext;
        tf.font_size = gltext->getTextFormat().getFontSize();
        tf.opts = toGlyphBuffersOpts(*view.renderPass, label);
        const bool fallback_method = shouldUseFallbackMethod(label);
        TextFormat2& rtf = fallback_method ?
            gltext->getTextFormat() : tf;
        for(auto &placement : label.transformed_anchor_) {
            bool didReplace;
            if(label.place(placement, view, label_placements, GLLabel::PlacementDeconflictMode::Shift, didReplace)) {
                label_placements.push_back(placement);
            }
        }
        if (fallback_method) {
            label.batch(view, *gltext, *(batch_.get()), GLGlobeBase::Sprites);
        } else {
            batchGlyphs(view, *glyph_batch_, label);
        }
    }

    // if an animation was performed, queue up a refresh
    if(didAnimate)
        view.context.requestRefresh();
}


TAKErr GLLabelManager::releaseImpl() NOTHROWS
{
    // release resources previously allocated as a result of `draw`
    resetFont();
    idsToRenderSprite_.clear();
    idsToRenderSurface_.clear();
    return TE_Ok;
}

int GLLabelManager::getRenderPass() NOTHROWS { return GLMapView2::Sprites | GLMapView2::Surface; }

void GLLabelManager::start() NOTHROWS {}

void GLLabelManager::stop() NOTHROWS {}

TextFormatParams* GLLabelManager::getDefaultTextFormatParams() NOTHROWS {
    if (defaultTextFormatParams == nullptr) {
        TAKErr code;
        Port::String opt;
        code = ConfigOptions_getOption(opt, "default-font-size");
        float fontSize;
        if (code == TE_Ok)
            fontSize = (float)atof(opt);
        else
            fontSize = 14.0f;
        ConfigOptions_getOption(defaultFontName, "default-font-name");
        if (code != TE_Ok)
            defaultFontName = "Arial";

        defaultTextFormatParams.reset(new TextFormatParams(defaultFontName.get(), fontSize));
        default_font_metrics.baselineSpacing = 0.f;
        default_font_metrics.charHeight = 0.f;
        default_font_metrics.descent = 0.f;
    }
    return defaultTextFormatParams.get();
}

GLText2* GLLabelManager::getDefaultText() NOTHROWS {
    if (defaultText == nullptr) {
        TAKErr code;
        TextFormat2Ptr fmt(nullptr, nullptr);
        if (!defaultFontSize) {
            Port::String opt;
            code = ConfigOptions_getOption(opt, "default-font-size");
            if (code == TE_Ok)
                defaultFontSize = (float)atof(opt);
            else
                defaultFontSize = 14.0f;
        }
        code = TextFormat2_createDefaultSystemTextFormat(fmt, defaultFontSize);
        if (code == TE_Ok) {
            std::shared_ptr<TextFormat2> sharedFmt = std::move(fmt);
            defaultText = GLText2_intern(sharedFmt);
        }
    }
    return defaultText;
}

std::shared_ptr<GLGlyphBatchFactory2> GLLabelManager::defaultGlyphBatchFactory() NOTHROWS {
    Monitor::Lock lock(monitor_);
    if (glyph_batch_factory_ == nullptr)
    {
        glyph_batch_factory_ = std::make_shared<GLGlyphBatchFactory2>();
    }

    return glyph_batch_factory_;
}

void GLLabelManager::batchGlyphs(const GLGlobeBase& view, GLGlyphBatch2& glyphBatch, GLLabel& label) NOTHROWS {
    if (label.text_.empty())
        return;
    for (const auto& a : label.transformed_anchor_)
        if (a.can_draw_) batchGlyphs(view, glyphBatch, label, a);
}

void GLLabelManager::batchGlyphs(const GLGlobeBase& view, GLGlyphBatch2& glyphBatch, GLLabel& label, const GLLabel::LabelPlacement& placement) NOTHROWS {
    auto factory = defaultGlyphBatchFactory();

    GlyphBuffersOpts opts = toGlyphBuffersOpts(*view.renderPass, label);
    GLText2 *gltext = label.gltext_;
    if (!gltext) gltext = defaultText;

    // placement is determined by GLLabel
    opts.renderX = static_cast<float>(placement.render_xyz_.x);
    opts.renderY = static_cast<float>(placement.render_xyz_.y);
    opts.renderZ = static_cast<float>(placement.render_xyz_.z);
    opts.anchorX = static_cast<float>(placement.anchor_xyz_.x);
    opts.anchorY = static_cast<float>(placement.anchor_xyz_.y);
    opts.anchorZ = static_cast<float>(placement.anchor_xyz_.z);

    double rotate = placement.rotation_.angle_;
    if (placement.rotation_.absolute_)
        rotate = fmod(rotate + view.renderPass->drawRotation, 360.0);
    opts.rotation = static_cast<float>(atakmap::math::toRadians(rotate));

    if (label.textFormatParams_ && label.textFormatParams_->size != 0)
        opts.font_size = label.textFormatParams_->size;
    else
        opts.font_size = getDefaultTextFormatParams()->size;
    opts.xray_alpha = label.hints_ & GLLabel::XRay ? 0.4f : 0.0f;

    factory->batch(*glyph_batch_, label.text_.c_str(), opts, *gltext);
}

GlyphBuffersOpts GLLabelManager::toGlyphBuffersOpts(const GLGlobeBase::State &state, const GLLabel &label) NOTHROWS {
    GlyphBuffersOpts opts(label.buffer_opts_);
    const auto defaultTextParams = getDefaultTextFormatParams();
    if (label.buffer_opts_.is_default_font) {
        opts.fontName = TAK::Engine::Port::String_intern(defaultTextParams->fontName);

        opts.bold = defaultTextParams->bold;
        opts.italic = defaultTextParams->italic;

    } else {
        if(!opts.fontName)
            opts.fontName = TAK::Engine::Port::String_intern(defaultTextParams->fontName);
    }
    const auto alphaAdjust = label.getTextAlphaAdjust(state);
    opts.back_color_alpha *= alphaAdjust;
    opts.text_color_alpha *= alphaAdjust;
    opts.outline_color_alpha *= alphaAdjust;
    return opts;
}

void GLLabelManager::drawBatchedGlyphs(const GLGlobeBase& view, const bool xrayPass) NOTHROWS {
    float proj[16];
    GLES20FixedPipeline::getInstance()->readMatrix(GLES20FixedPipeline::MatrixMode::MM_GL_PROJECTION, proj);

    glyph_batch_->draw(view.getRenderContext(), xrayPass, proj);
}

bool GLLabelManager::shouldUseFallbackMethod(GLLabel& label) NOTHROWS {
#ifdef __ANDROID__
    if ((label.hints_ & GLLabel::ScrollingText) != 0 && label.textSize.width > GLLabel::MAX_TEXT_WIDTH * GLMapRenderGlobals_getRelativeDisplayDensity())
        return true;
#endif
    return false;
}

void GLLabelManager::adjustForSurface(GLLabel& label, const GLGlobeBase::State& state, AtlasTextFormat& tf) {
    if (label.hints_ & GLLabel::Surface) {
        // Get height of string in pixels at point size 1
        tf.font_size = 1;
        float onePointHeight = tf.getStringHeight(label.text_.c_str());
        // XXX - we seem to require scaling the result to a tile size of 512
        double tileScale = state.scene.width / 512.0;
        // Calculate desired height of text in pixels based on meter height
        double desiredHeightPx = label.heightInMeters_ / (state.scene.gsd / tileScale);
        // Scale based on point size 1
        desiredHeightPx /= onePointHeight;
        // Make sure we're at least 1
        desiredHeightPx = std::max(desiredHeightPx, 1.0);
        // Set new font size
        tf.font_size = desiredHeightPx;
        // If the label doesn't have a textFormatParams, create a copy we can mutate from the defaults
        if (label.textFormatParams_) label.textFormatParams_.reset(new TextFormatParams(*getDefaultTextFormatParams()));
        label.textFormatParams_->size = (float)desiredHeightPx;
        // Invalidate label text size
        label.textSize.width = 0;
        label.textSize.height = 0;
        label.textSize.valid = false;
    }
}

TAKErr GLLabelManager::createQueryContext(QueryContextPtr &value) NOTHROWS
{
    value = QueryContextPtr(new(std::nothrow) QueryContextImpl(), Memory_deleter_const<QueryContext, QueryContextImpl>);
    return !!value ? TE_Ok : TE_OutOfMemory;
}
TAKErr GLLabelManager::resetQueryContext(QueryContext &pendingData) NOTHROWS
{
    auto &ctx = static_cast<QueryContextImpl&>(pendingData);
    ctx.renderSpriteIds.clear();
    ctx.renderSurfaceIds.clear();
    ctx.invalidLabelsIds.clear();
    return TE_Ok;
}
TAKErr GLLabelManager::getRenderables(TAK::Engine::Port::Collection<GLMapRenderable2 *>::IteratorPtr &iter) NOTHROWS
{
    // not returning renderables; `draw` overload uses computed `idsToRenderSprite/Surface_`
    return TE_Done;
}
TAKErr GLLabelManager::updateRenderableLists(QueryContext &pendingData) NOTHROWS
{
    auto &ctx = static_cast<QueryContextImpl&>(pendingData);
    idsToRenderSprite_.clear();
    idsToRenderSurface_.clear();
    idsToRenderSprite_.reserve(ctx.renderSpriteIds.size());
    idsToRenderSurface_.reserve(ctx.renderSurfaceIds.size());
    for (const auto id : ctx.renderSpriteIds)
        idsToRenderSprite_.push_back(id);
    for (const auto id : ctx.renderSurfaceIds)
        idsToRenderSurface_.push_back(id);
    if (labels.locked)
        labels.modifyBuffer.replaceLabels |= ctx.contentChanged;
    else
        replace_labels_ |= ctx.contentChanged;
    
    invalidLabelsIds_.insert(invalidLabelsIds_.end(), ctx.invalidLabelsIds.begin(), ctx.invalidLabelsIds.end());

    return TE_Ok;
}
TAKErr GLLabelManager::query(QueryContext &result, const GLGlobeBase::State &state)  NOTHROWS
{
    auto &ctx = static_cast<QueryContextImpl&>(result);
    ctx.contentChanged = false;
    ctx.lastFetchid = ctx.fetchid;
    ctx.fetchid++;
    std::vector<GLLabel::LabelPlacement> label_placements;

    LabelsLock ll(monitor_, labels.locked);

    queryImpl(ctx, state, Priority::TEP_Always, label_placements);
    queryImpl(ctx, state, Priority::TEP_High, label_placements);
    queryImpl(ctx, state, Priority::TEP_Standard, label_placements);
    queryImpl(ctx, state, Priority::TEP_Low, label_placements);
    return TE_Ok;
}
void GLLabelManager::queryImpl(QueryContext &result, const GLGlobeBase::State &state, const Priority priority, std::vector<GLLabel::LabelPlacement>& label_placements) NOTHROWS
{
    QueryContextImpl& ctx = static_cast<QueryContextImpl&>(result);
    auto glyphBatchFactory = defaultGlyphBatchFactory();

    //first render all GLLabels that do not need replacing,
    // store GLLabels that need to be replaced for later placement
    std::map<uint32_t, std::vector<GLLabel::LabelPlacement>> replaced_labels;
    std::vector<GLLabel::LabelPlacement> placements;
    for(auto &it : labels_) {
        GLLabel& label = it.second;
        if (label.priority_ != priority) continue;
        const auto label_id = it.first;

        if (label.hints_ & GLLabel::Surface) {
            // Surface labels are always included
            ctx.renderSurfaceIds.push_back(label_id);
            ctx.contentChanged |= (label.fetchid == ctx.lastFetchid);
            continue;
        }

        if (label.text_.empty()) {
            ctx.contentChanged |= (label.fetchid == ctx.lastFetchid);
            continue;
        }

        if (!label.shouldRenderAtResolution(state.drawMapResolution)) {
            ctx.contentChanged |= (label.fetchid == ctx.lastFetchid);
            continue;
        }

        if(!label.isVisible(state.renderPump)) {
            ctx.contentChanged |= (label.fetchid == ctx.lastFetchid);
            continue;
        }

        if (!label.getTextAlphaAdjust(state)) {
            ctx.contentChanged |= (label.fetchid == ctx.lastFetchid);
            continue;
        }

        GLText2* gltext = label.gltext_;
        if (!gltext) gltext = defaultText;

        if (!label.textSize.valid)
        {
            ctx.invalidLabelsIds.push_back(label_id);
            continue;
        }

        const float labelWidth = (label.hints_&GLLabel::ScrollingText) ?
            std::min(label.textSize.width, GLLabel::MAX_TEXT_WIDTH*GLMapRenderGlobals_getRelativeDisplayDensity()) : label.textSize.width;
        const float labelHeight = label.textSize.height;
        GLLabel::validateTextPlacement(placements, state, label);

        bool didReplace = false;
        bool canDraw = false;
        const auto deconflictMode = (label.hints_ & GLLabel::DisableDeconflict) ?
            GLLabel::PlacementDeconflictMode::None : GLLabel::PlacementDeconflictMode::Shift;

        bool skipped = true;
        std::vector<GLLabel::LabelPlacement> temporaryPlacements;
        for(auto &placement : placements)
        {
            Point2<double> xyz(placement.anchor_xyz_);

            // skip points outside of the near and far clip planes
            if(placement.anchor_xyz_.z > 1.f) continue;

            // confirm location is in view
            if (!atakmap::math::Rectangle<double>::contains(state.left, state.bottom, state.right, state.top, xyz.x, xyz.y)) continue;

            canDraw = true;

            {
                if(GLLabel::place(placement, state, label, NAN, labelWidth, labelHeight, label_placements, deconflictMode, didReplace))
                {
                    skipped = false;
                    if(!didReplace)
                    {
                        // label was placed
                        temporaryPlacements.push_back(placement);
                    }
                    else
                    {
                        // label could not be placed due to deconfliction, defer to post-placement
                        replaced_labels[label_id].push_back(placement);
                        break;
                    }
                }
            }
        }

        if(!didReplace && canDraw)
        {
            label_placements.insert(label_placements.end(), temporaryPlacements.begin(), temporaryPlacements.end());
            ctx.renderSpriteIds.push_back(label_id);
            ctx.contentChanged |= (label.fetchid != ctx.lastFetchid);
            label.fetchid = ctx.fetchid;
        }

        ctx.contentChanged |= (skipped && label.fetchid == ctx.lastFetchid);
    }

    //rePlace and render all labels that haven't been rendered
    for(auto &e : replaced_labels)
    {
        GLLabel& label = labels_[e.first];
        GLText2* gltext = label.gltext_;
        if (!gltext) gltext = defaultText;
        const char* text = label.text_.c_str();
        const float textWidth = label.textSize.width;
        const float textHeight = label.textSize.height;
        const float labelWidth = (label.hints_&GLLabel::ScrollingText) ?
            std::min(textWidth, GLLabel::MAX_TEXT_WIDTH*GLMapRenderGlobals_getRelativeDisplayDensity()) : textWidth;
        const float labelHeight = textHeight;
        bool placed = false;
        for(auto &placement : e.second) {
            bool didReplace;
            if(GLLabel::place(placement, state, label, NAN, labelWidth, labelHeight, label_placements, GLLabel::PlacementDeconflictMode::Shift, didReplace)) {
                label_placements.push_back(placement);
                ctx.renderSpriteIds.push_back(e.first);
                ctx.contentChanged |= (label.fetchid != ctx.lastFetchid);
                label.fetchid = ctx.fetchid;
                placed = true;
            }
        }

        // content has changed if we weren't able to place and it was in the last fetch
        ctx.contentChanged |= (!placed && label.fetchid == ctx.lastFetchid);
    }
}
void GLLabelManager::invalidate() NOTHROWS
{
    GLAsynchronousMapRenderable3::invalidate();
}

TAKErr TAK::Engine::Renderer::Core::GLLabelManager_updateLabel(GLLabelManager& lmgr, uint32_t labelID, GLLabel&& src) NOTHROWS
{
    Monitor::Lock lock(lmgr.monitor_);
    lmgr.updateLabel(labelID, [&](GLLabel& dst) {
        dst = std::move(src);

        if (lmgr.labels.locked)
            lmgr.labels.modifyBuffer.replaceLabels = true;
        else
            lmgr.replace_labels_ = true;
    });

    return TE_Ok;
}

namespace {
    AtlasTextFormat::~AtlasTextFormat() = default;

    float AtlasTextFormat::getStringWidth(const char* text) NOTHROWS {
        GlyphMeasurements m{};
        ftor_->measureStringBounds(&m, opts, text);
        return static_cast<float>((m.max_x - m.min_x) * font_size);
    }

    float AtlasTextFormat::getCharPositionWidth(const char* text, int position) NOTHROWS {
        return getCharWidth(text[position]);
    }

    float AtlasTextFormat::getCharWidth(const unsigned int chr) NOTHROWS {
        char str[] = { static_cast<char>(chr), '\0' };
        return getStringWidth(str);
    }

    float AtlasTextFormat::getCharHeight() NOTHROWS {
        if (opts.is_default_font && default_font_metrics.charHeight)   return default_font_metrics.charHeight;
        const float charHeight = getStringHeight("A");
        if (opts.is_default_font)    default_font_metrics.charHeight = charHeight;
        return charHeight;
    }

    float AtlasTextFormat::getDescent() NOTHROWS {
        if (opts.is_default_font && default_font_metrics.descent)   return default_font_metrics.descent;
        GlyphMeasurements m{};
        ftor_->measureStringBounds(&m, opts, "A");
        const float descent = static_cast<float>(-m.descender * font_size);
        if (opts.is_default_font)   default_font_metrics.descent = descent;
        return descent;
    }

    float AtlasTextFormat::getStringHeight(const char* text) NOTHROWS {
        GlyphMeasurements m{};
        ftor_->measureStringBounds(&m, opts, text);
        return static_cast<float>((m.max_y - m.min_y) * font_size);
    }

    float AtlasTextFormat::getBaselineSpacing() NOTHROWS {
        if (opts.is_default_font && default_font_metrics.baselineSpacing)   return default_font_metrics.baselineSpacing;
        GlyphMeasurements m{};
        ftor_->measureStringBounds(&m, opts, "A");
        const float baselineSpacing = static_cast<float>(m.line_height * font_size);;
        if (opts.is_default_font)   default_font_metrics.baselineSpacing = baselineSpacing;
        return baselineSpacing;
    }

    int AtlasTextFormat::getFontSize() NOTHROWS {
        return static_cast<int>(font_size);
    }

    TAK::Engine::Util::TAKErr AtlasTextFormat::loadGlyph(BitmapPtr& value, const unsigned int c) NOTHROWS {
        return TE_NotImplemented;
    }
    
}
