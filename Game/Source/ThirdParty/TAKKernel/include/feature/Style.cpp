#include "feature/Style.h"

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <regex>
#include <sstream>

#include "feature/DrawingTool.h"
#include "math/Utils.h"
#include "util/Memory.h"
#include "util/MathUtils.h"

using namespace atakmap;

using namespace TAK::Engine;
using namespace TAK::Engine::Util;

namespace
{

    class OGR_Color
    {
    public:
        OGR_Color (unsigned int color) :
            color (color)
        { }
    private:
        template <class _CharT, class _Traits>
        friend
        std::basic_ostream<_CharT, _Traits>& operator<< (std::basic_ostream<_CharT, _Traits>& strm, const OGR_Color& ogr)
        {
            std::ios::fmtflags oldFlags (strm.flags ());
            std::streamsize oldWidth (strm.width ());
            char oldFill (strm.fill ('0'));
            char fmt[10];
#ifdef MSVC
            _snprintf(fmt, 10, "#%06X%02X", (ogr.color & 0xFFFFFF), (ogr.color >> 24 & 0xFF));
#else
            snprintf(fmt, 10, "#%06X%02X", (ogr.color & 0xFFFFFF), (ogr.color >> 24 & 0xFF));
#endif
            strm << fmt;

            // Return stream with restored settings.
            strm.flags (oldFlags);
            return strm << std::setw (oldWidth) << std::setfill (oldFill);
        }

        unsigned int color;
    };

    template <typename T>
    struct VecDeleter
    {
        VecDeleter (const std::vector<T*>& vector) :
            vector (vector)
        { }

        static void deleteElement (T* elem)
        { delete elem; }

        void operator() () const
        {
            std::for_each (vector.begin (), vector.end (),
                       deleteElement);
        }

        const std::vector<T*>& vector;
    };
}

namespace
{

    bool isNULL (const void* ptr)
    { return !ptr; }

    inline
    float pixelsToPoints (float pixels)
    {
        // This value of PPI is copied from convertUnits in DrawingTool.cpp.
        // Both functions should get the value from elsewhere.
        const double PPI (240);             // Need to get this from somewhere!!!

        return static_cast<float>(pixels * 72 / PPI);           // 72 points per inch.
    }

    // derived from https://codereview.stackexchange.com/questions/66711/greatest-common-divisor/66735
    template<class T>
    T gcd(const T a, const T b) NOTHROWS
    {
        return (a<b) ? gcd(b, a) : (!b ? a : gcd(b, a % b));
    }

    template<class T>
    T gcd(const std::vector<T>& values) NOTHROWS
    {
        T result = values[0];
        for (std::size_t i = 1u; i < values.size(); i++)
        {
            result = gcd(result, values[i]);
            if (result == 1)
                break;
        }
        return result;
    }

    bool isEmptyMatrix(const float* matrix)
    {
        for (int i = 0; i < 16; i++)
        {
            if (matrix[i] != 0) return false;
        }
        return true;
    }

    uint32_t interpolate(const uint32_t colorA, const uint32_t colorB, const double weight) NOTHROWS;
    std::shared_ptr<atakmap::feature::Style> interpolate(const atakmap::feature::Style& a, const atakmap::feature::Style& b, const double weight) NOTHROWS;
}

using namespace atakmap::feature;

Style::Style(const StyleClass styleClass_) NOTHROWS :
    styleClass(styleClass_)
{}
Style::~Style () NOTHROWS
  { }
StyleClass Style::getClass() const NOTHROWS
{
    return styleClass;
}
bool Style::operator==(const Style &other) const NOTHROWS
{
    return this->equalsImpl(other);
}
bool Style::operator!=(const Style &other) const NOTHROWS
{
    return !this->equalsImpl(other);
}
void Style::destructStyle(const Style *style)
{
    delete style;
}

std::unique_ptr<Style> Style::wrapLodStyle(unsigned int minLod, unsigned int maxLod, std::unique_ptr<Style> style)
{
    if (minLod != -1 || maxLod != -1) {
        return std::unique_ptr<Style>(new LevelOfDetailStyle(std::move(style), minLod, maxLod));
    } else {
        return style;
    }
}

Style* Style::parseStyle (const char* styleOGR)
{
    if (!styleOGR) {
        throw std::invalid_argument
                  ("atakmap::feature::Style::parseStyle: "
                   "Received NULL OGR style string");
    }

    const char* styleEnd (styleOGR+ std::strlen (styleOGR));
    std::vector<std::unique_ptr<Style>> styles;

    while (styleOGR!= styleEnd) {
        std::unique_ptr<DrawingTool> tool (DrawingTool::parseOGR_Tool (styleOGR, styleOGR));
        Brush* tmpBrush = (tool.get() && tool->getType() == DrawingTool::BRUSH) ? static_cast<Brush *>(tool.get()) : nullptr;
        Label* tmpLabel = (tool.get() && tool->getType() == DrawingTool::LABEL) ? static_cast<Label *>(tool.get()) : nullptr;
        Pen* tmpPen = (tool.get() && tool->getType() == DrawingTool::PEN) ? static_cast<Pen *>(tool.get()) : nullptr;
        Symbol* tmpSymbol = (tool.get() && tool->getType() == DrawingTool::SYMBOL) ? static_cast<Symbol *>(tool.get()) : nullptr;

        if (tmpBrush) {
            styles.emplace_back (std::unique_ptr<Style>(wrapLodStyle(tmpBrush->minLod, tmpBrush->maxLod,
                   std::unique_ptr<Style>(new BasicFillStyle (tmpBrush->foreColor)))));
        } else if (tmpPen) {
            if(tmpPen->arrowRadius > 0.f) {
                int16_t pattern = (int16_t)0xFFFF;
                std::size_t factor = 1u;
                if(!tmpPen->pattern.empty()) {
                    std::size_t len = tmpPen->pattern[0u];
                    for (std::size_t i = 1u; i < tmpPen->pattern.size(); i++)
                        len += tmpPen->pattern[i];
                    if (len >= 16) {
                        // the factor will be the total pattern length, divided by 16
                        factor = len / 16u;
                    } else {
                        factor = 1u;
                    }

                    pattern = 0x0;
                    std::size_t bit = 0u;
                    for (std::size_t i = 0; i < tmpPen->pattern.size(); i++) {
                        std::size_t run = (tmpPen->pattern[i] / factor);
                        for (std::size_t j = 0; j < run; j++) {
                            if (i % 2 == 0)
                                pattern |= static_cast<int16_t>(0x1u) << bit;
                            bit++;
                        }
                    }
                    if (bit > 16)
                        Logger_log(TELL_Warning, "Stroke pattern overflow");
                    else if(bit < 16)
                        Logger_log(TELL_Warning, "Stroke pattern underflow");
                }
                StrokeExtrusionMode extrusionMode = TEEM_Vertex;
                switch(tmpPen->extrusionMode) {
                    case atakmap::feature::Pen::NONE :
                        extrusionMode = TEEM_None;
                        break;
                    case atakmap::feature::Pen::ENDPOINT :
                        extrusionMode = TEEM_EndPoint;
                        break;
                    default :
                        extrusionMode = TEEM_Vertex;
                        break;
                }
                ArrowHeadMode arrowHeadMode = TEAH_OnlyLast;
                switch (tmpPen->arrowHeadMode) {
                    case Pen::ONLYLAST :
                        arrowHeadMode = TEAH_OnlyLast;
                        break;
                    case Pen::PERVERTEX :
                        arrowHeadMode = TEAH_PerVertex;
                        break;
                }
                styles.emplace_back(wrapLodStyle(tmpPen->minLod, tmpPen->maxLod,
                    std::unique_ptr<Style>(new ArrowStrokeStyle(
                    tmpPen->arrowRadius,
                    factor,
                    pattern,
                    tmpPen->color,
                    tmpPen->width,
                    extrusionMode,
                    arrowHeadMode))));
            } else if (tmpPen->pattern.size()) {
                std::size_t len = tmpPen->pattern[0u];
                for (std::size_t i = 1u; i < tmpPen->pattern.size(); i++)
                    len += tmpPen->pattern[i];
                std::size_t factor;
                if (len >= 16) {
                    // the factor will be the total pattern length, divided by 16
                    factor = len / 16u;
                } else {
                    factor = 1u;
                }

                std::size_t bit = 0u;
                int16_t pattern = 0LL;
                for (std::size_t i = 0; i < tmpPen->pattern.size(); i++) {
                    std::size_t run = (tmpPen->pattern[i] / factor);
                    for (std::size_t j = 0; j < run; j++) {
                        if (i % 2 == 0)
                            pattern |= static_cast<int16_t>(0x1u) << bit;
                        bit++;
                    }
                }
                if (bit > 16)
                    Logger_log(TELL_Warning, "Stroke pattern overflow");
                else if(bit < 16)
                    Logger_log(TELL_Warning, "Stroke pattern underflow");
                StrokeExtrusionMode extrusionMode = TEEM_Vertex;
                switch(tmpPen->extrusionMode) {
                    case atakmap::feature::Pen::NONE :
                        extrusionMode = TEEM_None;
                        break;
                    case atakmap::feature::Pen::ENDPOINT :
                        extrusionMode = TEEM_EndPoint;
                        break;
                    default :
                        extrusionMode = TEEM_Vertex;
                        break;
                }
                styles.emplace_back(wrapLodStyle(tmpPen->minLod, tmpPen->maxLod,
                    std::unique_ptr<Style>(new PatternStrokeStyle(
                    factor,
                    pattern,
                    tmpPen->color,
                    tmpPen->width,
                    extrusionMode))));
            } else {
                StrokeExtrusionMode extrusionMode = TEEM_Vertex;
                switch(tmpPen->extrusionMode) {
                    case atakmap::feature::Pen::NONE :
                        extrusionMode = TEEM_None;
                        break;
                    case atakmap::feature::Pen::ENDPOINT :
                        extrusionMode = TEEM_EndPoint;
                        break;
                    default :
                        extrusionMode = TEEM_Vertex;
                        break;
                }
                styles.emplace_back(wrapLodStyle(tmpPen->minLod, tmpPen->maxLod,
                    std::unique_ptr<Style>(new BasicStrokeStyle(tmpPen->color, tmpPen->width, extrusionMode))));
            }
        } else if (tmpSymbol && !isEmptyMatrix(tmpSymbol->transform)) {
            styles.emplace_back(wrapLodStyle(tmpSymbol->minLod, tmpSymbol->maxLod,
                                             std::unique_ptr<Style>(new MeshPointStyle(tmpSymbol->names,
                                                                                       tmpSymbol->color,
                                                                                       tmpSymbol->transform))));
        } else if (tmpSymbol) {
            float scaling (tmpSymbol->scaling);
            float width (tmpSymbol->size);
            float height (tmpSymbol->size);
            if (tmpSymbol->symbolWidth && tmpSymbol->symbolHeight) {
                width = tmpSymbol->symbolWidth;
                height = tmpSymbol->symbolHeight;
            }
            IconPointStyle::HorizontalAlignment hAlign (IconPointStyle::H_CENTER);

            switch (tmpSymbol->position)
            {
            case Symbol::Position::BASELINE_LEFT:
            case Symbol::Position::CENTER_LEFT:
            case Symbol::Position::TOP_LEFT:
            case Symbol::Position::BOTTOM_LEFT:
                hAlign = IconPointStyle::RIGHT;
                break;
            case Symbol::Position::BASELINE_RIGHT:
            case Symbol::Position::CENTER_RIGHT:
            case Symbol::Position::TOP_RIGHT:
            case Symbol::Position::BOTTOM_RIGHT:
                hAlign = IconPointStyle::LEFT;
                break;
            default:
                break;
            }

            IconPointStyle::VerticalAlignment vAlign (IconPointStyle::V_CENTER);

            switch (tmpSymbol->position)
            {
            case Symbol::Position::BASELINE_LEFT:
            case Symbol::Position::BASELINE_CENTER:
            case Symbol::Position::BASELINE_RIGHT:
            case Symbol::Position::BOTTOM_LEFT:
            case Symbol::Position::BOTTOM_CENTER:
            case Symbol::Position::BOTTOM_RIGHT:
                vAlign = IconPointStyle::ABOVE;
                break;
            case Symbol::Position::TOP_LEFT:
            case Symbol::Position::TOP_CENTER:
            case Symbol::Position::TOP_RIGHT:
                vAlign = IconPointStyle::BELOW;
                break;
            default:
                break;
            }

            const bool relativeRotation = (TE_ISNAN(tmpSymbol->relativeAngle) && TE_ISNAN(tmpSymbol->angle)) || !TE_ISNAN(tmpSymbol->relativeAngle);
            if (TE_ISNAN(tmpSymbol->angle))            tmpSymbol->angle = 0.0;
            if (TE_ISNAN(tmpSymbol->relativeAngle))    tmpSymbol->relativeAngle = 0.0;

            if(!tmpSymbol->names.get()) {
                styles.emplace_back(wrapLodStyle(tmpSymbol->minLod, tmpSymbol->maxLod,
                       std::unique_ptr<Style>(new BasicPointStyle(tmpSymbol->color, tmpSymbol->size))));
            } else {
                styles.emplace_back(wrapLodStyle(tmpSymbol->minLod, tmpSymbol->maxLod,
                    scaling
                      ? std::unique_ptr<Style>(new IconPointStyle(tmpSymbol->color,
                      tmpSymbol->names,
                      scaling,
                      hAlign,
                      vAlign,
                      !relativeRotation ? -tmpSymbol->angle : -tmpSymbol->relativeAngle, 
                      !relativeRotation))
                      : std::unique_ptr<Style>(new IconPointStyle(tmpSymbol->color,
                      tmpSymbol->names,
                      width, height,
                      tmpSymbol->dx,
                      tmpSymbol->dy,
                      hAlign,
                      vAlign,
                      !relativeRotation ? -tmpSymbol->angle : -tmpSymbol->relativeAngle, 
                      !relativeRotation))));
            }
        } else if (tmpLabel) {
            // Label represents font size in pixels.  Convert to points.
            float fontSize (pixelsToPoints (tmpLabel->fontSize));
            LabelPointStyle::HorizontalAlignment hAlign (LabelPointStyle::H_CENTER);

            switch (tmpLabel->position)
            {
            case Label::BASELINE_LEFT:
            case Label::CENTER_LEFT:
            case Label::TOP_LEFT:
            case Label::BOTTOM_LEFT:
                hAlign = LabelPointStyle::RIGHT;
                break;
            case Label::BASELINE_RIGHT:
            case Label::CENTER_RIGHT:
            case Label::TOP_RIGHT:
            case Label::BOTTOM_RIGHT:
                hAlign = LabelPointStyle::LEFT;
                break;
            default:
                break;
            }

            LabelPointStyle::VerticalAlignment vAlign (LabelPointStyle::V_CENTER);

            switch (tmpLabel->position)
            {
            case Label::BASELINE_LEFT:
            case Label::BASELINE_CENTER:
            case Label::BASELINE_RIGHT:
            case Label::BOTTOM_LEFT:
            case Label::BOTTOM_CENTER:
            case Label::BOTTOM_RIGHT:
                vAlign = LabelPointStyle::ABOVE;
                break;
            case Label::TOP_LEFT:
            case Label::TOP_CENTER:
            case Label::TOP_RIGHT:
                vAlign = LabelPointStyle::BELOW;
                break;
            default:
                break;
            }

            // Determine ScrollMode from OGR Label placement mode.  See
            // LabelPointStyle::toOGR below.
            LabelPointStyle::ScrollMode scrollMode (LabelPointStyle::DEFAULT);

            switch (tmpLabel->placement)
              {
              case Label::STRETCHED:

                scrollMode = LabelPointStyle::ON;
                break;

              case Label::MIDDLE:

                scrollMode = LabelPointStyle::OFF;
                break;

              default:
                break;
            }

            unsigned style = 0u;
            if (tmpLabel->bold)
                style |= LabelPointStyle::BOLD;
            if (tmpLabel->italic)
                style |= LabelPointStyle::ITALIC;
            if (tmpLabel->strikeout)
                style |= LabelPointStyle::STRIKETHROUGH;
            if (tmpLabel->underline)
                style |= LabelPointStyle::UNDERLINE;

            const char *face = nullptr;
            if (tmpLabel->fontNames) {
                // truncate to the first font name
                const char* sep = strstr(tmpLabel->fontNames, ",");
                if (sep)
                    tmpLabel->fontNames.get()[sep - tmpLabel->fontNames.get()] = '\0';
                face = tmpLabel->fontNames;
            }
            if(!tmpLabel->text)
                tmpLabel->text = "";

            const bool relativeRotation = (TE_ISNAN(tmpLabel->relativeAngle) && TE_ISNAN(tmpLabel->angle)) || !TE_ISNAN(tmpLabel->relativeAngle);
            if (TE_ISNAN(tmpLabel->angle))         tmpLabel->angle = 0.0;
            if (TE_ISNAN(tmpLabel->relativeAngle)) tmpLabel->relativeAngle = 0.0;

            styles.emplace_back (wrapLodStyle(tmpLabel->minLod, tmpLabel->maxLod,
                    std::unique_ptr<Style>(new LabelPointStyle (tmpLabel->text,
                                                   tmpLabel->foreColor,
                                                   tmpLabel->backColor,
                                                   tmpLabel->outlineColor,
                                                   scrollMode,
                                                   face,
                                                   fontSize,
                                                   (LabelPointStyle::Style)style,
                                                   tmpLabel->dx,
                                                   tmpLabel->dy,
                                                   hAlign,
                                                   vAlign,
                                                   !relativeRotation ? -tmpLabel->angle : -tmpLabel->relativeAngle, 
                                                   !relativeRotation,
                                                   0, 0, 13,
                                                   tmpLabel->stretch / 100.0f))));
        }
    }

    Style* result (nullptr);

    if (styles.size () == 1) {
        result = styles[0].release();
    } else if (styles.size () > 1) {
        std::vector<std::shared_ptr<Style>> compositeStyles;
        compositeStyles.reserve(styles.size());
        for (std::size_t i = 0u; i < styles.size(); i++)
            compositeStyles.push_back(std::move(styles[i]));
        result = new CompositeStyle (compositeStyles.data(), styles.size());
    }

    return result;
}

BasicFillStyle::BasicFillStyle (unsigned int color) NOTHROWS :
    Style(TESC_BasicFillStyle),
    color (color)
{ }
TAKErr BasicFillStyle::toOGR(Port::String &value) const NOTHROWS
{
    std::ostringstream strm;
    strm << "BRUSH(fc:" << OGR_Color(color) << ")";
    value = strm.str().c_str();
    return TE_Ok;
}
Style *BasicFillStyle::clone() const
{
    return new BasicFillStyle(*this);
}
bool BasicFillStyle::equalsImpl(const Style &other) const NOTHROWS
{
    if(other.getClass() != getClass())
        return false;
    const auto &test = static_cast<const BasicFillStyle &>(other);
    return color == test.color;
}

BasicPointStyle::BasicPointStyle (unsigned int color, float size) :
    Style(TESC_BasicPointStyle),
    color (color),
    size (size)
{
    if (size < 0) {
        throw std::invalid_argument
                  ("atakmap::feature::BasicPointStyle::BasicPoinStyle: "
                   "Received negative size");
    }
}
TAKErr BasicPointStyle::toOGR(Port::String &value) const NOTHROWS
{
    std::ostringstream strm;
    strm << "SYMBOL(c:" << OGR_Color(color) << ",s:" << size << "px)";
    value = strm.str().c_str();
    return TE_Ok;
}
Style * BasicPointStyle::clone() const
{
  return new BasicPointStyle(*this);
}
bool BasicPointStyle::equalsImpl(const Style &other) const NOTHROWS
{
    if(other.getClass() != getClass())
        return false;
    const auto &test = static_cast<const BasicPointStyle &>(other);
    return color == test.color &&
            size == test.size;
}

BasicStrokeStyle::BasicStrokeStyle (unsigned int color, float width, const StrokeExtrusionMode extrusionMode) :
    Style(TESC_BasicStrokeStyle),
    color (color),
    width (width),
    extrusionMode (extrusionMode)
{
    if (width < 0) {
        throw std::invalid_argument
                  ("atakmap::feature::BasicStrokeStyle::BasicStrokeStyle: "
                   "Received negative width");
    }
}
TAKErr BasicStrokeStyle::toOGR(Port::String &value) const NOTHROWS
{
    std::ostringstream strm;
	strm << "PEN(c:" << OGR_Color(color) << ",w:" << width << "px,";
    switch(extrusionMode) {
        case TEEM_EndPoint :
            strm << "ex:ep";
            break;
        case TEEM_None :
            strm << "ex:no";
            break;
        case TEEM_Vertex :
            strm << "ex:vt";
            break;
    }
    strm << ")";
    value = strm.str().c_str();
    return TE_Ok;
}
Style *BasicStrokeStyle::clone() const
{
    return new BasicStrokeStyle(*this);
}
bool BasicStrokeStyle::equalsImpl(const Style &other) const NOTHROWS
{
    if(other.getClass() != getClass())
        return false;
    const auto &test = static_cast<const BasicStrokeStyle &>(other);
    return color == test.color &&
           width == test.width;
}

CompositeStyle::CompositeStyle (const std::vector<Style*>& styles) :
    Style(TESC_CompositeStyle)
{
    if (styles.empty ()) {
        throw std::invalid_argument
                  ("atakmap::feature::CompositeStyle::CompositeStyle: "
                   "Received empty Style vector");
    }

    this->styles_.reserve(styles.size());
    for(std::size_t i = 0u; i < styles.size(); i++) {
        if(styles[i])
            this->styles_.push_back(std::shared_ptr<Style>(styles[i]));
        else
            throw std::invalid_argument
                  ("atakmap::feature::CompositeStyle::CompositeStyle: "
                   "Received NULL Style");
    }
}
CompositeStyle::CompositeStyle (const std::shared_ptr<Style> *styles, const std::size_t count) :
    Style(TESC_CompositeStyle)
{
    if (!styles || !count) {
        throw std::invalid_argument
                  ("atakmap::feature::CompositeStyle::CompositeStyle: "
                   "Received empty Style vector");
    }

    this->styles_.reserve(count);
    for(std::size_t i = 0u; i < count; i++) {
        if(styles[i])
            this->styles_.push_back(styles[i]);
        else
            throw std::invalid_argument
                  ("atakmap::feature::CompositeStyle::CompositeStyle: "
                   "Received NULL Style");
    }
}
const Style& CompositeStyle::getStyle (std::size_t index) const 
{
    if (index >= styles_.size ()) {
        throw std::range_error
                  ("atakmap::feature::CompositeStyle::getStyle: "
                   "Received out-of-range index");
    }
    return *styles_[index];
}
TAKErr CompositeStyle::toOGR(Port::String &value) const NOTHROWS
{
    TAKErr code(TE_Ok);
    std::ostringstream strm;
    auto iter (styles_.begin ());
    auto end (styles_.end ());

    TAK::Engine::Port::String substyle;

    code = (*iter)->toOGR(substyle);
    TE_CHECKRETURN_CODE(code);
    strm << substyle;
    while (++iter != end) {
        substyle = nullptr;
        code = (*iter)->toOGR(substyle);
        TE_CHECKRETURN_CODE(code);
        strm << ";" << substyle;
    }

    value = strm.str().c_str();
    return TE_Ok;
}
Style *CompositeStyle::clone() const
{
    return new CompositeStyle(styles_.data(), styles_.size());
}
bool CompositeStyle::equalsImpl(const Style &other) const NOTHROWS
{
    if(other.getClass() != getClass())
        return false;
    const auto &test = static_cast<const CompositeStyle &>(other);
    if(styles_.size() != test.styles_.size())
        return false;
    for(std::size_t i = 0u; i < styles_.size(); i++)
        if(styles_[i] != test.styles_[i])
            return false;
    return true;
}

IconPointStyle::IconPointStyle (unsigned int color,
                                const char* iconURI,
                                float scaling,
                                HorizontalAlignment hAlign,
                                VerticalAlignment vAlign,
                                float rotation,
                                bool absoluteRotation) :
    Style(TESC_IconPointStyle),
    color (color),
    iconURI (iconURI),
    hAlign (hAlign),
    vAlign (vAlign),
    scaling (scaling == 0 ? 1.0f : scaling),
    width (0),
    height (0),
    rotation (rotation),
    absoluteRotation (absoluteRotation),
    offsetX(0.0),
    offsetY(0.0)
{

    if (!iconURI) {
        throw std::invalid_argument
                  ("atakmap::feature::IconPointStyle::IconPointStyle: "
                   "Received NULL icon URI");
    }
    if (scaling < 0) {
        throw std::invalid_argument
                  ("atakmap::feature::IconPointStyle::IconPointStyle: "
                   "Received negative scaling");
    }
}
IconPointStyle::IconPointStyle (unsigned int color,
                                const char* iconURI,
                                float width,
                                float height,
                                HorizontalAlignment hAlign,
                                VerticalAlignment vAlign,
                                float rotation,
                                bool absoluteRotation) :
    Style(TESC_IconPointStyle),
    color (color),
    iconURI (iconURI),
    hAlign (hAlign),
    vAlign (vAlign),
    scaling (!width && !height ? 1.0f : 0.0f),
    width (width),
    height (height),
    rotation (rotation),
    absoluteRotation (absoluteRotation),
    offsetX(0.0),
    offsetY(0.0)
{
    if (!iconURI) {
        throw std::invalid_argument
                  ("atakmap::feature::IconPointStyle::IconPointStyle: "
                   "Received NULL icon URI");
    }
    if (width < 0) {
        throw std::invalid_argument
                  ("atakmap::feature::IconPointStyle::IconPointStyle: "
                   "Received negative width");
    }
    if (height < 0) {
        throw std::invalid_argument
                  ("atakmap::feature::IconPointStyle::IconPointStyle: "
                   "Received negative height");
    }
}
IconPointStyle::IconPointStyle (unsigned int color,
                                const char* iconURI,
                                float width,
                                float height,
                                float offsetX,
                                float offsetY,
                                HorizontalAlignment hAlign,
                                VerticalAlignment vAlign,
                                float rotation,
                                bool absoluteRotation) :
    Style(TESC_IconPointStyle),
    color (color),
    iconURI (iconURI),
    hAlign (hAlign),
    vAlign (vAlign),
    scaling (!width && !height ? 1.0f : 0.0f),
    width (width),
    height (height),
    rotation (rotation),
    absoluteRotation (absoluteRotation),
    offsetX(offsetX),
    offsetY(offsetY)
{
    if (!iconURI) {
        throw std::invalid_argument
                  ("atakmap::feature::IconPointStyle::IconPointStyle: "
                   "Received NULL icon URI");
    }
    if (width < 0) {
        throw std::invalid_argument
                  ("atakmap::feature::IconPointStyle::IconPointStyle: "
                   "Received negative width");
    }
    if (height < 0) {
        throw std::invalid_argument
                  ("atakmap::feature::IconPointStyle::IconPointStyle: "
                   "Received negative height");
    }
}
TAKErr IconPointStyle::toOGR(Port::String &value) const NOTHROWS
{
    std::ostringstream strm;
    float size (std::max (width, height));

    strm << "SYMBOL(id:\"" << iconURI << "\"";
    if (rotation) {
        if(absoluteRotation)
            strm << ",a:" << -rotation;     // OGR uses CCW degrees.
        else
            strm << ",ra:" << -rotation;     // OGR uses CCW degrees.
    }
	strm << ",c:" << OGR_Color(color);
    if (!scaling) {
        strm << ",sw:" << width << "px";
        strm << ",sh:" << height << "px"; // Units means size, not scaling.
    } else if(scaling && scaling != 1.0) {
        strm << ",s:" << scaling;       // No units means scaling, not size.
    }

    unsigned anchorPosition = 5;
    switch (hAlign)
    {
    case LEFT:  anchorPosition += 1;    break;
    case RIGHT: anchorPosition -= 1;    break;
    default:                            break;
    }
    switch (vAlign)
    {
    case ABOVE: anchorPosition += 6;    break;
    case BELOW: anchorPosition += 3;    break;
    default:                            break;
    }
    if (anchorPosition != 5) {
        strm << ",p:" << anchorPosition;
    }
    if(offsetX)
        strm << ",dx:" << offsetX << "px";
    if(offsetY)
        strm << ",dy:" << offsetY << "px";
    strm << ")";

    value = strm.str().c_str();
    return TE_Ok;
}
Style *IconPointStyle::clone() const
{
  return new IconPointStyle(*this);
}
bool IconPointStyle::equalsImpl(const Style &other) const NOTHROWS
{
    if(other.getClass() != getClass())
        return false;
    const auto &test = static_cast<const IconPointStyle &>(other);
    return color == test.color &&
           iconURI == test.iconURI &&
           hAlign == test.hAlign &&
           vAlign == test.vAlign &&
           scaling == test.scaling &&
           width == test.width &&
           height == test.height &&
           rotation == test.rotation &&
           absoluteRotation == test.absoluteRotation &&
           offsetX == test.offsetX &&
           offsetY == test.offsetY;
}

MeshPointStyle::MeshPointStyle (const char* meshURI,
                                unsigned int color,
                                const float* transform) :
        Style(TESC_MeshPointStyle),
        meshURI (meshURI),
        color (color)
{
    if (!meshURI) {
        throw std::invalid_argument
                ("atakmap::feature::MeshPointStyle::MeshPointStyle: "
                 "Received NULL mesh URI");
    }
    memcpy(this->transform, transform, sizeof(float) * 16);
}
TAKErr MeshPointStyle::toOGR(Port::String &value) const NOTHROWS
{
    std::ostringstream strm;

    strm << "SYMBOL(id:\"" << meshURI << "\"";
    strm << ",c:" << OGR_Color(color);
    strm << ",tf:";
    for (int i = 0; i < 16; i++) strm << (i > 0 ? " " : "") << transform[i];
    strm << ")";

    value = strm.str().c_str();
    return TE_Ok;
}
Style *MeshPointStyle::clone() const
{
    return new MeshPointStyle(*this);
}
bool MeshPointStyle::equalsImpl(const Style &other) const NOTHROWS
{
    if(other.getClass() != getClass())
        return false;
    const auto &test = static_cast<const MeshPointStyle &>(other);
    return meshURI == test.meshURI &&
           color == test.color &&
           std::memcmp(transform, test.transform, 16*sizeof(float)) == 0;
}

LabelPointStyle::LabelPointStyle (const char* text,
                                  unsigned int textColor,
                                  unsigned int backColor,
                                  ScrollMode mode,
                                  const char *face,
                                  float textSize,
                                  LabelPointStyle::Style style,
                                  float offsetX,
                                  float offsetY,
                                  HorizontalAlignment hAlign,
                                  VerticalAlignment vAlign,
                                  float rotation,
                                  bool absoluteRotation,
                                  float paddingX,
                                  float paddingY,
                                  double labelMinRenderResolution,
                                  float labelScale) :
    atakmap::feature::Style(TESC_LabelPointStyle),
    text (text),
    foreColor (textColor),
    backColor (backColor),
    scrollMode (mode),
    hAlign (hAlign),
    vAlign (vAlign),
    textSize (textSize ? textSize : 16),        // ATAK hack
    rotation (rotation),
    paddingX(paddingX),
    paddingY(paddingY),
    absoluteRotation (absoluteRotation),
    labelMinRenderResolution (labelMinRenderResolution),
    labelScale (labelScale),
    offsetX(offsetX),
    offsetY(offsetY),
    face(face),
    style(style),
    outlineColor(0u)
  {
    if (!text) {
        throw std::invalid_argument
                  ("atakmap::feature::LabelPointStyle::LabelPointStyle: "
                   "Received NULL label text");
    }
    if (textSize < 0) {
        throw std::invalid_argument
                  ("atakmap::feature::LabelPointStyle::LabelPointStyle: "
                   "Received negative textSize");
    }
}
LabelPointStyle::LabelPointStyle (const char* text,
                                  unsigned int textColor,
                                  unsigned int backColor,
                                  unsigned int outlineColor,
                                  ScrollMode mode,
                                  const char *face,
                                  float textSize,
                                  LabelPointStyle::Style style,
                                  float offsetX,
                                  float offsetY,
                                  HorizontalAlignment hAlign,
                                  VerticalAlignment vAlign,
                                  float rotation,
                                  bool absoluteRotation,
                                  float paddingX,
                                  float paddingY,
                                  double labelMinRenderResolution,
                                  float labelScale) :
    atakmap::feature::Style(TESC_LabelPointStyle),
    text (text),
    foreColor (textColor),
    backColor (backColor),
    scrollMode (mode),
    hAlign (hAlign),
    vAlign (vAlign),
    textSize (textSize ? textSize : 16),        // ATAK hack
    rotation (rotation),
    paddingX(paddingX),
    paddingY(paddingY),
    absoluteRotation (absoluteRotation),
    labelMinRenderResolution (labelMinRenderResolution),
    labelScale (labelScale),
    offsetX(offsetX),
    offsetY(offsetY),
    face(face),
    style(style),
    outlineColor(outlineColor)
  {
    if (!text) {
        throw std::invalid_argument
                  ("atakmap::feature::LabelPointStyle::LabelPointStyle: "
                   "Received NULL label text");
    }
    if (textSize < 0) {
        throw std::invalid_argument
                  ("atakmap::feature::LabelPointStyle::LabelPointStyle: "
                   "Received negative textSize");
    }
}
TAKErr LabelPointStyle::toOGR(Port::String &value) const NOTHROWS
{
    std::ostringstream strm;

    strm << "LABEL(t:\"";
    if (text) {
        for (int i = 0u; i < static_cast<int>(strlen(text)); i++) {
            const char c = text[i];
            if (c == '"')
                strm << '\\';
            strm << c;
        }
    }
    strm << "\""
         << ",s:" << textSize << "pt";
    if (style & LabelPointStyle::BOLD)
        strm << ",bo:1";
    if (style & LabelPointStyle::ITALIC)
        strm << ",it:1";
    if (style & LabelPointStyle::UNDERLINE)
        strm << ",un:1";
    if (style & LabelPointStyle::STRIKETHROUGH)
        strm << ",st:1";
    if (face)
        strm << ",f:\"" << face << "\"";
    if (rotation) {
        if (absoluteRotation)
            strm << ",a:" << -rotation;     // OGR uses CCW degrees.
        else
            strm << ",ra:" << -rotation;
    }
    strm << ",c:" << OGR_Color (foreColor)
         << ",b:" << OGR_Color (backColor);
    if (outlineColor & 0xFF000000)
        strm << ",o:" << OGR_Color(outlineColor);
    if (labelScale != 1.0)
        strm << ",w:" << (labelScale * 100.0);

    // Co-opt the OGR Label placement mode to specify the scroll mode.  The
    // co-opted placements normally apply to polylines.
    //
    //  ScrollMode::DEFAULT     ==>     Label::DEFAULT
    //  ScrollMode::ON          ==>     Label::STRETCHED
    //  ScrollMode::OFF         ==>     Label::MIDDLE
    Label::Placement placement (Label::DEFAULT);

    switch (scrollMode)
    {
    case ON:  placement = Label::STRETCHED; break;
    case OFF: placement = Label::MIDDLE;    break;
    default:                                break;
    }
    (strm << ",m:").put (placement);

    // Translate the horizontal and vertical alignments into an OGR Label anchor
    // position number.  We use baseline rather than bottom vertical alignments
    // for labels that are to be above the point.
    unsigned short position (0);

    switch (hAlign)
    {
    case LEFT:  position = 6;   break;
    case RIGHT: position = 4;   break;
    default:    position = 5;   break;
    }
    switch (vAlign)
    {
    case ABOVE: position += 6;  break;  // Adjust to baseline values.
    case BELOW: position += 3;  break;  // Adjust to top values.
    default:                    break;
    }
    if (offsetX)
        strm << ",dx:" << offsetX << "px";
    if (offsetY)
        strm << ",dy:" << offsetY << "px";
    strm << ",p:" << position << ")";

    value = strm.str().c_str();
    return TE_Ok;
}
Style *LabelPointStyle::clone() const
{
    return new LabelPointStyle(*this);
}
bool LabelPointStyle::equalsImpl(const atakmap::feature::Style &other) const NOTHROWS
{
    if(other.getClass() != getClass())
        return false;
    const auto &test = static_cast<const LabelPointStyle &>(other);
    return text == test.text &&
           foreColor == test.foreColor &&
           backColor == test.backColor &&
           scrollMode == test.scrollMode &&
           hAlign == test.hAlign &&
           vAlign == test.vAlign &&
           textSize == test.textSize &&
           rotation == test.rotation &&
           paddingX == test.paddingX &&
           paddingY == test.paddingY &&
           absoluteRotation == test.absoluteRotation &&
           labelMinRenderResolution == test.labelMinRenderResolution &&
           labelScale == test.labelScale &&
           offsetX == test.offsetX &&
           offsetY == test.offsetY &&
           face == test.face &&
           style == test.style &&
           outlineColor == test.outlineColor;
}

PatternStrokeStyle::PatternStrokeStyle (const std::size_t factor_,
                    const uint16_t pattern_,
                    const unsigned int color_,
                    const float strokeWidth_,
                    const StrokeExtrusionMode extrusionMode_) :
    PatternStrokeStyle(TESC_PatternStrokeStyle, factor_, pattern_, color_, strokeWidth_, extrusionMode_)
{}
PatternStrokeStyle::PatternStrokeStyle (const StyleClass clazz,
                    const std::size_t factor_,
                    const uint16_t pattern_,
                    const unsigned int color_,
                    const float strokeWidth_,
                    const StrokeExtrusionMode extrusionMode_) :
    Style(clazz),
    pattern(pattern_),
    factor(factor_),
    color(color_),
    width(strokeWidth_),
    extrusionMode(extrusionMode_)
{
    if(!factor)
        throw std::invalid_argument("bad pattern length");
    if(width < 0.0)
        throw std::invalid_argument("invalid stroke width");
}
uint16_t PatternStrokeStyle::getPattern() const NOTHROWS
{
    return pattern;
}
std::size_t PatternStrokeStyle::getFactor() const NOTHROWS
{
    return factor;
}
unsigned int PatternStrokeStyle::getColor () const NOTHROWS
{
    return color;
}
float PatternStrokeStyle::getStrokeWidth() const NOTHROWS
{
    return width;
}
StrokeExtrusionMode PatternStrokeStyle::getExtrusionMode() const NOTHROWS
{
    return extrusionMode;
}
TAKErr PatternStrokeStyle::toOGR(TAK::Engine::Port::String &value) const NOTHROWS
{
    std::ostringstream ogr;
    //PEN(c:#FF0000,w:2px,p:”4px 5px”)
    ogr << "PEN(c:" << OGR_Color (color) << ",w:" << width << "px,p:\"";
    uint8_t state = 0x1;
    std::size_t stateCount = 0;
    uint64_t pat = pattern;
    std::size_t emit = 0;
    for(std::size_t i = 0u; i < 16u; i++) {
        const uint8_t px = pat&0x1u;
        pat >>= 0x1u;
        if(px != state) {
            // the state has flipped, emit the pixel count
            if(!emit)
                ogr << ' ';
            ogr << (stateCount*factor) << "px";
            emit++;
            state = px;
            stateCount = 0u;
        }

        // update pixel count for current state
        stateCount++;
    }
    if(stateCount) {
        if(!emit)
            ogr << ' ';
        ogr << (stateCount*factor) << "px";
    }
    ogr << "\",";
    switch(extrusionMode) {
        case TEEM_EndPoint :
            ogr << "ex:ep";
            break;
        case TEEM_None :
            ogr << "ex:no";
            break;
        case TEEM_Vertex :
            ogr << "ex:vt";
            break;
    }
    ogr << ")";
    value = ogr.str().c_str();
    return TE_Ok;
}
Style *PatternStrokeStyle::clone() const
{
    return new PatternStrokeStyle(*this);
}
bool PatternStrokeStyle::equalsImpl(const Style &other) const NOTHROWS
{
    if(other.getClass() != getClass())
        return false;
    const auto &test = static_cast<const PatternStrokeStyle &>(other);
    return pattern == test.pattern &&
           factor == test.factor &&
           color == test.color &&
           width == test.width;
}

ArrowStrokeStyle::ArrowStrokeStyle (const float arrowRadius_,
                    const std::size_t factor_,
                    const uint16_t pattern_,
                    const unsigned int color_,
                    const float strokeWidth_,
                    const StrokeExtrusionMode extrusionMode_,
                    const ArrowHeadMode arrowHeadMode_) :
    PatternStrokeStyle(TESC_ArrowStrokeStyle,
                    factor_,
                    pattern_,
                    color_,
                    strokeWidth_,
                    extrusionMode_),
    arrowRadius(arrowRadius_),
    arrowHeadMode(arrowHeadMode_)
{
    if(arrowRadius <= 0.0)
        throw std::invalid_argument("invalid stroke width");
}
float ArrowStrokeStyle::getArrowRadius() const NOTHROWS
{
    return arrowRadius;
}
ArrowHeadMode ArrowStrokeStyle::getArrowHeadMode() const NOTHROWS
{
    return arrowHeadMode;
}
TAKErr ArrowStrokeStyle::toOGR(TAK::Engine::Port::String &value) const NOTHROWS
{
    std::ostringstream ogr;
    ogr << "PEN(c:" << OGR_Color (getColor()) << ",w:" << getStrokeWidth() << "px,ar:" << arrowRadius;
    // code pattern, if set
    const uint16_t pattern_ = getPattern();
    const std::size_t factor_ = getFactor();
    if (pattern_ != 0xFFFFu) {
        ogr << ",p:\"";
        uint8_t state = 0x1;
        std::size_t stateCount = 0;
        uint64_t pat = pattern_;
        std::size_t emit = 0;
        for (std::size_t i = 0u; i < 16u; i++) {
            const uint8_t px = pat & 0x1u;
            pat >>= 0x1u;
            if (px != state) {
                // the state has flipped, emit the pixel count
                if (!emit)
                    ogr << ' ';
                ogr << (stateCount * factor_) << "px";
                emit++;
                state = px;
                stateCount = 0u;
            }

            // update pixel count for current state
            stateCount++;
        }
        if (stateCount) {
            if (!emit)
                ogr << ' ';
            ogr << (stateCount * factor_) << "px";
        }
        ogr << "\"";
    }
    ogr << ",";
    switch(getExtrusionMode()) {
        case TEEM_EndPoint :
            ogr << "ex:ep";
            break;
        case TEEM_None :
            ogr << "ex:no";
            break;
        case TEEM_Vertex :
            ogr << "ex:vt";
            break;
    }
    ogr << ",";
    switch(getArrowHeadMode()) {
        case TEAH_OnlyLast :
            ogr << "ah:ol";
            break;
        case TEAH_PerVertex :
            ogr << "ah:pv";
            break;
    }
    ogr << ")";
    value = ogr.str().c_str();
    return TE_Ok;
}
Style *ArrowStrokeStyle::clone() const
{
    return new ArrowStrokeStyle(*this);
}
bool ArrowStrokeStyle::equalsImpl(const Style &other) const NOTHROWS
{
    if(!PatternStrokeStyle::equalsImpl(other))
        return false;
    const auto &test = static_cast<const ArrowStrokeStyle &>(other);
    return arrowRadius == test.arrowRadius &&
           arrowHeadMode == test.arrowHeadMode;
}

LevelOfDetailStyle::LevelOfDetailStyle (const Style &style, const std::size_t minLod, const std::size_t maxLod) :
    LevelOfDetailStyle(std::move(StylePtr(style.clone(), Style::destructStyle)), minLod, maxLod)
{}
LevelOfDetailStyle::LevelOfDetailStyle (const std::shared_ptr<Style> &style_, const std::size_t minLod_, const std::size_t maxLod_) :
    Style(TESC_LevelOfDetailStyle)
{
    assert(style_);
    styles.reserve(2);
    styles.push_back(style_);
    styles.push_back(style_);
    lods.reserve(2);
    lods.push_back(minLod_);
    lods.push_back(maxLod_);
}
LevelOfDetailStyle::LevelOfDetailStyle (const Style **style_, const std::size_t *lod_, const std::size_t count_) :
    Style(TESC_LevelOfDetailStyle)
{
    styles.reserve(count_);
    lods.reserve(count_);
    for(std::size_t i = 0u; i < count_; i++) {
        StylePtr styleptr(nullptr, nullptr);
        styleptr = StylePtr(style_[i]->clone(), Style::destructStyle);
        styles.push_back(std::move(styleptr));
        lods.push_back(lod_[i]);
    }
}
LevelOfDetailStyle::LevelOfDetailStyle (const std::shared_ptr<Style> *style_, const std::size_t *lod_, const std::size_t count_) :
    Style(TESC_LevelOfDetailStyle)
{
    styles.reserve(count_);
    lods.reserve(count_);
    for(std::size_t i = 0u; i < count_; i++) {
        assert(style_[i]);
        styles.push_back(style_[i]);
        lods.push_back(lod_[i]);
    }
}

const Style &LevelOfDetailStyle::getStyle() const NOTHROWS
  { return *styles.back(); }
std::shared_ptr<const Style> LevelOfDetailStyle::getStyle(const std::size_t lod) const NOTHROWS
  {
    if (lod < lods.front() || lod >= lods.back())
        return std::shared_ptr<const Style>();
    else if (lod == lods.front())
        return styles.front();
    else if (lod == lods.back() - 1u)
        return styles.back();

    for(std::size_t i = 1u; i < lods.size(); i++) {
        if (lod == lods[i]) {
            return styles[i];
        } else if(lod < lods[i]) {
            const auto weight = (double)(lod - (lods[i - 1u])) / (double)(lods[i] - lods[i - 1u]);
            return interpolate(*styles[i - 1u], *styles[i], weight);
        }
    }

    // illegal state
    return std::shared_ptr<const Style>();
  }
std::size_t LevelOfDetailStyle::getMinLevelOfDetail() const NOTHROWS
  {  return lods.front();  }
std::size_t LevelOfDetailStyle::getMaxLevelOfDetail() const NOTHROWS
  {  return lods.back();  }
bool LevelOfDetailStyle::isContinuous() const NOTHROWS
  { return (*styles.back()) != (*styles.front()); }
std::size_t LevelOfDetailStyle::getLevelOfDetailCount() const NOTHROWS
  { return lods.size(); }
std::size_t LevelOfDetailStyle::getLevelOfDetail(const std::size_t idx) const NOTHROWS
  { return (idx <= lods.size()) ? lods[idx] : lods.back(); }

TAKErr LevelOfDetailStyle::toOGR(TAK::Engine::Port::String &value) const NOTHROWS
{
    TAKErr code(TE_Ok);
    code = getStyle().toOGR(value);
    if (code != TE_Ok)
        return code;
    // convert inner style to OGR
    return LevelOfDetailStyle_addLodToOGRStyle(value, getMinLevelOfDetail(), getMaxLevelOfDetail());
}
Style *LevelOfDetailStyle::clone() const
{
    return new LevelOfDetailStyle(styles.data(), lods.data(), styles.size());
}
bool LevelOfDetailStyle::equalsImpl(const Style &other) const NOTHROWS
{
    if(getClass() != other.getClass())
        return false;
    const auto &test = static_cast<const LevelOfDetailStyle &>(other);
    if (styles.size() != test.styles.size())
        return false;
    for(std::size_t i = 0u; i < styles.size(); i++) {
        if (*styles[i] != *test.styles[i])
            return false;
    }
    return true;
}

TAKErr atakmap::feature::Style_parseStyle(StylePtr &value, const char *ogr) NOTHROWS
{
    try {
        value = StylePtr(Style::parseStyle(ogr), Style::destructStyle);
        return !value ? TE_InvalidArg : TE_Ok;
    } catch(const std::invalid_argument &) {
        return TE_InvalidArg;
    } catch(const std::bad_alloc &) {
        return TE_OutOfMemory;
    } catch(...) {
        return TE_Err;
    }
}
TAKErr atakmap::feature::Style_parseStyle(StylePtr_Const& value, const char* ogr) NOTHROWS
{
    TAKErr code(TE_Ok);
    StylePtr v(nullptr, nullptr);
    code = Style_parseStyle(v, ogr);
    if (code != TE_Ok)
        return code;
    value = StylePtr_Const(v.release(), v.get_deleter());
    return code;
    
}
TAKErr atakmap::feature::BasicFillStyle_create(StylePtr &value, const unsigned int color) NOTHROWS
{
    try {
        value = StylePtr(new BasicFillStyle(color), Memory_deleter_const<Style, BasicFillStyle>);
        return TE_Ok;
    } catch(const std::invalid_argument &) {
        return TE_InvalidArg;
    } catch(const std::bad_alloc &) {
        return TE_OutOfMemory;
    } catch(...) {
        return TE_Err;
    }
}
TAKErr atakmap::feature::BasicPointStyle_create(StylePtr &value, const unsigned int color, const float size) NOTHROWS
{
    try {
        value = StylePtr(new BasicPointStyle(color, size), Memory_deleter_const<Style, BasicPointStyle>);
        return TE_Ok;
    } catch(const std::invalid_argument &) {
        return TE_InvalidArg;
    } catch(const std::bad_alloc &) {
        return TE_OutOfMemory;
    } catch(...) {
        return TE_Err;
    }
}
TAKErr atakmap::feature::BasicStrokeStyle_create(StylePtr &value, const unsigned int color, const float width, const StrokeExtrusionMode extrusionMode) NOTHROWS
{
    try {
        value = StylePtr(new BasicStrokeStyle(color, width, extrusionMode), Memory_deleter_const<Style, BasicStrokeStyle>);
        return TE_Ok;
    } catch(const std::invalid_argument &) {
        return TE_InvalidArg;
    } catch(const std::bad_alloc &) {
        return TE_OutOfMemory;
    } catch(...) {
        return TE_Err;
    }
}
TAKErr atakmap::feature::CompositeStyle_create(StylePtr &value, const Style **styles, const std::size_t count) NOTHROWS
{
    try {
        std::vector<std::shared_ptr<Style>> styles_v;
        styles_v.reserve(count);
        for(std::size_t i = 0u; i < count; i++) {
            if(!styles[i])
                return TE_InvalidArg;
            styles_v.push_back(std::shared_ptr<Style>(styles[i]->clone()));
        }
        value = StylePtr(new CompositeStyle(styles_v.data(), styles_v.size()), Memory_deleter_const<Style, CompositeStyle>);
        return TE_Ok;
    } catch(const std::invalid_argument &) {
        return TE_InvalidArg;
    } catch(const std::bad_alloc &) {
        return TE_OutOfMemory;
    } catch(...) {
        return TE_Err;
    }
}
TAKErr atakmap::feature::CompositeStyle_create(StylePtr &value, const std::shared_ptr<Style> *styles, const std::size_t count) NOTHROWS
{
    try {
        for(std::size_t i = 0u; i < count; i++) {
            if(!styles[i])
                return TE_InvalidArg;
        }
        value = StylePtr(new CompositeStyle(styles, count), Memory_deleter_const<Style, CompositeStyle>);
        return TE_Ok;
    } catch(const std::invalid_argument &) {
        return TE_InvalidArg;
    } catch(const std::bad_alloc &) {
        return TE_OutOfMemory;
    } catch(...) {
        return TE_Err;
    }
}
TAKErr atakmap::feature::IconPointStyle_create(StylePtr &value, unsigned int color,
                                                                const char* iconURI,
                                                                float scaleFactor,
                                                                IconPointStyle::HorizontalAlignment hAlign,
                                                                IconPointStyle::VerticalAlignment vAlign,
                                                                float rotation,
                                                                bool absoluteRotation) NOTHROWS
{
    try {
        value = StylePtr(new IconPointStyle(color, iconURI, scaleFactor, hAlign, vAlign, rotation, absoluteRotation), Memory_deleter_const<Style, IconPointStyle>);
        return TE_Ok;
    } catch(const std::invalid_argument &) {
        return TE_InvalidArg;
    } catch(const std::bad_alloc &) {
        return TE_OutOfMemory;
    } catch(...) {
        return TE_Err;
    }
}
TAKErr atakmap::feature::IconPointStyle_create(StylePtr &value, unsigned int color,
                                                                            const char* iconURI,
                                                                            float width,
                                                                            float height,
                                                                            float offsetX, float offsetY,
                                                                            IconPointStyle::HorizontalAlignment hAlign,
                                                                            IconPointStyle::VerticalAlignment vAlign,
                                                                            float rotation,
                                                                            bool absoluteRotation) NOTHROWS
{
    try {
        value = StylePtr(new IconPointStyle(color, iconURI, width, height, offsetX, offsetY, hAlign, vAlign, rotation, absoluteRotation), Memory_deleter_const<Style, IconPointStyle>);
        return TE_Ok;
    } catch(const std::invalid_argument &) {
        return TE_InvalidArg;
    } catch(const std::bad_alloc &) {
        return TE_OutOfMemory;
    } catch(...) {
        return TE_Err;
    }
}
TAKErr atakmap::feature::MeshPointStyle_create(StylePtr &value, const char* meshURI,
                                               unsigned int color,
                                               const float* transform) NOTHROWS
{
    try {
        value = StylePtr(new MeshPointStyle(meshURI, color, transform), Memory_deleter_const<Style, MeshPointStyle>);
        return TE_Ok;
    } catch(const std::invalid_argument &) {
        return TE_InvalidArg;
    } catch(const std::bad_alloc &) {
        return TE_OutOfMemory;
    } catch(...) {
        return TE_Err;
    }
}
TAKErr atakmap::feature::LabelPointStyle_create(StylePtr &value, const char* text,
                                                unsigned int textColor,    // 0xAARRGGBB
                                                unsigned int backColor,    // 0xAARRGGBB
                                                LabelPointStyle::ScrollMode mode,
                                                float textSize,      // Use system default size.
                                                float offsetX,
                                                float offsetY,
                                                LabelPointStyle::HorizontalAlignment hAlign,
                                                LabelPointStyle::VerticalAlignment vAlign,
                                                float rotation,      // 0 degrees of rotation.
                                                bool absoluteRotation, // Relative to screen.
                                                float paddingX, // offset from alignment position
                                                float paddingY,
                                                double labelMinRenderResolution,
                                                float labelScale) NOTHROWS
{
    return LabelPointStyle_create(value, text, textColor, backColor, mode, nullptr, textSize, 0, offsetX, offsetY, hAlign, vAlign, rotation, absoluteRotation, paddingX, paddingY, labelMinRenderResolution, labelScale);
}
TAKErr atakmap::feature::LabelPointStyle_create(StylePtr &value, const char* text,
                                                                 unsigned int textColor,    // 0xAARRGGBB
                                                                 unsigned int backColor,    // 0xAARRGGBB
                                                                 LabelPointStyle::ScrollMode mode,
                                                                 const char* fontFace,
                                                                 float textSize,      // Use system default size.
                                                                 int style,
                                                                 float offsetX,
                                                                 float offsetY,
                                                                 LabelPointStyle::HorizontalAlignment hAlign,
                                                                 LabelPointStyle::VerticalAlignment vAlign,
                                                                 float rotation,      // 0 degrees of rotation.
                                                                 bool absoluteRotation, // Relative to screen.
                                                                 float paddingX, // offset from alignment position
                                                                 float paddingY,
                                                                 double labelMinRenderResolution,
                                                                 float labelScale) NOTHROWS
{
    try {

        value = StylePtr(new LabelPointStyle(text, textColor, backColor, mode, fontFace, textSize, (LabelPointStyle::Style)style, offsetX, offsetY, hAlign, vAlign, rotation, absoluteRotation, paddingX, paddingY, labelMinRenderResolution, labelScale), Memory_deleter_const<Style, LabelPointStyle>);
        return TE_Ok;
    } catch(const std::invalid_argument &) {
        return TE_InvalidArg;
    } catch(const std::bad_alloc &) {
        return TE_OutOfMemory;
    } catch(...) {
        return TE_Err;
    }
}
TAKErr atakmap::feature::PatternStrokeStyle_create(StylePtr &value, const std::size_t factor,
                                                                    const uint16_t pattern,
                                                                    const unsigned int color,
                                                                    const float strokeWidth,
                                                                    const StrokeExtrusionMode extrusionMode) NOTHROWS
{
    try {
        value = StylePtr(new PatternStrokeStyle(factor, pattern, color, strokeWidth, extrusionMode), Memory_deleter_const<Style, PatternStrokeStyle>);
        return TE_Ok;
    } catch(const std::invalid_argument &) {
        return TE_InvalidArg;
    } catch(const std::bad_alloc &) {
        return TE_OutOfMemory;
    } catch(...) {
        return TE_Err;
    }
}
TAKErr atakmap::feature::ArrowStrokeStyle_create(StylePtr &value, const float arrowRadius,
                                                                    const std::size_t factor,
                                                                    const uint16_t pattern,
                                                                    const unsigned int color,
                                                                    const float strokeWidth,
                                                                    const StrokeExtrusionMode extrusionMode,
                                                                    const ArrowHeadMode arrowHeadMode) NOTHROWS
{
    try {
        value = StylePtr(new ArrowStrokeStyle(arrowRadius, factor, pattern, color, strokeWidth, extrusionMode, arrowHeadMode), Memory_deleter_const<Style, ArrowStrokeStyle>);
        return TE_Ok;
    } catch(const std::invalid_argument &) {
        return TE_InvalidArg;
    } catch(const std::bad_alloc &) {
        return TE_OutOfMemory;
    } catch(...) {
        return TE_Err;
    }
}

TAKErr atakmap::feature::LevelOfDetailStyle_create(StylePtr &value, const Style &style,
                                                                    const std::size_t minLod,
                                                                    const std::size_t maxLod) NOTHROWS
{
    StylePtr styleptr(nullptr, nullptr);
    try {
        styleptr = StylePtr(style.clone(), Style::destructStyle);
    } catch(const std::invalid_argument &) {
        return TE_InvalidArg;
    } catch(const std::bad_alloc &) {
        return TE_OutOfMemory;
    } catch(...) {
        return TE_Err;
    }

    return LevelOfDetailStyle_create(value, std::move(styleptr), minLod, maxLod);
}
TAKErr atakmap::feature::LevelOfDetailStyle_create(StylePtr &value, const std::shared_ptr<Style> &style,
                                                                    const std::size_t minLod,
                                                                    const std::size_t maxLod) NOTHROWS
{
    if (!style)
        return TE_InvalidArg;
    if (minLod >= maxLod)
        return TE_InvalidArg;
    value = StylePtr(new(std::nothrow) LevelOfDetailStyle(style, minLod, maxLod), Style::destructStyle);
    return !value ? TE_OutOfMemory : TE_Ok;
}
TAK::Engine::Util::TAKErr atakmap::feature::LevelOfDetailStyle_create(StylePtr &value, const Style **style,
                                                                                const std::size_t *lod,
                                                                                const std::size_t count) NOTHROWS
{
    if (!style)
        return TE_InvalidArg;
    if (!count)
        return TE_InvalidArg;
    std::vector<std::shared_ptr<Style>> stylePtrs;
    stylePtrs.reserve(count);
    for(std::size_t i = 0u; i < count; i++) {
        if (!style[i])
            return TE_InvalidArg;
        StylePtr styleptr(nullptr, nullptr);
        try {
            styleptr = StylePtr(style[i]->clone(), Style::destructStyle);
        } catch(const std::invalid_argument &) {
            return TE_InvalidArg;
        } catch(const std::bad_alloc &) {
            return TE_OutOfMemory;
        } catch(...) {
            return TE_Err;
        }
        stylePtrs.push_back(std::move(styleptr));
    }
    return LevelOfDetailStyle_create(value, stylePtrs.data(), lod, count);
}
TAK::Engine::Util::TAKErr atakmap::feature::LevelOfDetailStyle_create(StylePtr &value, const std::shared_ptr<Style> *style,
                                                                                const std::size_t *lod,
                                                                                const std::size_t count) NOTHROWS
{
    if (!style)
        return TE_InvalidArg;
    if (!lod)
        return TE_InvalidArg;
    if (!count)
        return TE_InvalidArg;

    if (!style[0])
        return TE_InvalidArg;
    for(std::size_t i = 1u; i < count; i++) {
        if (!style[i])
            return TE_InvalidArg;
        if (style[i]->getClass() != style[i - 1u]->getClass())
            return TE_InvalidArg;
        if (lod[i] <= lod[i-1u])
            return TE_InvalidArg;
    }

    value = StylePtr(new(std::nothrow) LevelOfDetailStyle(style, lod, count), Style::destructStyle);
    return !value ? TE_OutOfMemory : TE_Ok;
}
TAK::Engine::Util::TAKErr atakmap::feature::LevelOfDetailStyle_addLodToOGRStyle(TAK::Engine::Port::String& ogrStyle, const std::size_t minLod, const std::size_t maxLod) NOTHROWS
{
    // create the LOD tags substring to be injected
    std::string lodTags;
    {
        std::ostringstream strm;
        strm << "nd:" << minLod << ",xd:" << maxLod << ",";
        lodTags = strm.str();
    }

    // for each drawing tool directive, insert the min/max LOD tags immediately after the open paranthesis
    const char* tools[4] =
    {
        "BRUSH(",
        "LABEL(",
        "PEN(",
        "SYMBOL(",
    };

    std::string result(ogrStyle);
    for (auto& tool : tools) {
        size_t pos = 0;
        do {
            pos = result.find(tool, pos);
            if (pos != std::string::npos) {
                pos += strlen(tool);
                result.insert(pos, lodTags);
                pos += lodTags.length();
            }
        } while (pos != std::string::npos);
    }

    ogrStyle = result.c_str();
    return TE_Ok;
}

namespace
{
    double interpolate(double a, double b, double weight)
    {
        return (a*(1.0-weight)) + (b*weight);
    }
    template<class T>
    const T &select(const T &a, const T &b, double weight)
    {
        return (weight < 0.5) ? a : b;
    }
    uint32_t interpolate(const uint32_t color0, const uint32_t color1, const double weight) NOTHROWS
    {
        const double a0 = ((color0 >> 24u)&0xFFu) / 255.0;
        const double r0 = ((color0 >> 16u)&0xFFu) / 255.0;
        const double g0 = ((color0 >> 8u)&0xFFu) / 255.0;
        const double b0 = (color0&0xFFu) / 255.0;

        const double a1 = ((color1 >> 24u)&0xFFu) / 255.0;
        const double r1 = ((color1 >> 16u)&0xFFu) / 255.0;
        const double g1 = ((color1 >> 8u)&0xFFu) / 255.0;
        const double b1 = (color1&0xFFu) / 255.0;

        const double a = interpolate(a0, a1, weight);
        const double r = interpolate(r0, r1, weight);
        const double g = interpolate(g0, g1, weight);
        const double b = interpolate(b0, b1, weight);

        return (((uint32_t)(a * 255.0)) << 24u) |
            (((uint32_t)(r * 255.0)) << 16u) |
            (((uint32_t)(g * 255.0)) << 8u) |
            ((uint32_t)(b * 255.0));
    }
    std::shared_ptr<atakmap::feature::Style> interpolate(const atakmap::feature::Style& a, const atakmap::feature::Style& b, const double weight) NOTHROWS
    {
        if(a.getClass() != b.getClass()) {
            StylePtr s((weight < 0.5) ? a.clone() : b.clone(), atakmap::feature::Style::destructStyle);
            return std::move(s);
        }

        switch(a.getClass()) {
        case TESC_BasicPointStyle :
        {
            const auto &aimpl = static_cast<const BasicPointStyle&>(a);
            const auto &bimpl = static_cast<const BasicPointStyle&>(b);
            return std::shared_ptr<Style>(new BasicPointStyle(
                interpolate(aimpl.getColor(), bimpl.getColor(), weight),
                (float)interpolate(aimpl.getSize(), bimpl.getSize(), weight)
            ));
        }
        case TESC_LabelPointStyle :
        {
            const auto &aimpl = static_cast<const LabelPointStyle&>(a);
            const auto &bimpl = static_cast<const LabelPointStyle&>(b);
            return std::shared_ptr<Style>(new LabelPointStyle(
                select(aimpl.getText(), bimpl.getText(), weight),
                interpolate(aimpl.getTextColor(), bimpl.getTextColor(), weight),
                interpolate(aimpl.getBackgroundColor(), bimpl.getBackgroundColor(), weight),
                interpolate(aimpl.getOutlineColor(), bimpl.getOutlineColor(), weight),
                select(aimpl.getScrollMode(), bimpl.getScrollMode(), weight),
                select(aimpl.getFontFace(), bimpl.getFontFace(), weight),
                (aimpl.getTextSize() && bimpl.getTextSize()) ?
                    (float)interpolate(aimpl.getTextSize(), bimpl.getTextSize(), weight) :
                    select(aimpl.getTextSize(), bimpl.getTextSize(), weight),
                select(aimpl.getStyle(), bimpl.getStyle(), weight),
                (float)interpolate(aimpl.getOffsetX(), bimpl.getOffsetX(), weight),
                (float)interpolate(aimpl.getOffsetY(), bimpl.getOffsetY(), weight),
                select(aimpl.getHorizontalAlignment(), bimpl.getHorizontalAlignment(), weight),
                select(aimpl.getVerticalAlignment(), bimpl.getVerticalAlignment(), weight),
                (aimpl.isRotationAbsolute() == bimpl.isRotationAbsolute()) ?
                    (float)interpolate(aimpl.getRotation(), bimpl.getRotation(), weight) :
                    select(aimpl.getRotation(), bimpl.getRotation(), weight),
                select(aimpl.isRotationAbsolute(), bimpl.isRotationAbsolute(), weight),
                (float)interpolate(aimpl.getPaddingX(), bimpl.getPaddingX(), weight),
                (float)interpolate(aimpl.getPaddingY(), bimpl.getPaddingY(), weight),
                interpolate(aimpl.getLabelMinRenderResolution(), bimpl.getLabelMinRenderResolution(), weight),
                (float)interpolate(aimpl.getLabelScale(), bimpl.getLabelScale(), weight)
            ));
        }
        case TESC_IconPointStyle :
        {
            const auto &aimpl = static_cast<const IconPointStyle&>(a);
            const auto &bimpl = static_cast<const IconPointStyle&>(b);
            if((!aimpl.getWidth()) != (!bimpl.getWidth()) || (!aimpl.getHeight()) != (!bimpl.getHeight())) {
                StylePtr s((weight < 0.5) ? a.clone() : b.clone(), atakmap::feature::Style::destructStyle);
                return std::move(s);
            } else if(aimpl.getWidth()) {
                return std::shared_ptr<Style>(new IconPointStyle(
                    interpolate(aimpl.getColor(), bimpl.getColor(), weight),
                    select(aimpl.getIconURI(), bimpl.getIconURI(), weight),
                    (float)interpolate(aimpl.getWidth(), bimpl.getWidth(), weight),
                    (float)interpolate(aimpl.getHeight(), bimpl.getHeight(), weight),
                    (float)interpolate(aimpl.getOffsetX(), bimpl.getOffsetX(), weight),
                    (float)interpolate(aimpl.getOffsetY(), bimpl.getOffsetY(), weight),
                    select(aimpl.getHorizontalAlignment(), bimpl.getHorizontalAlignment(), weight),
                    select(aimpl.getVerticalAlignment(), bimpl.getVerticalAlignment(), weight),
                    (aimpl.isRotationAbsolute() == bimpl.isRotationAbsolute()) ?
                        (float)interpolate(aimpl.getRotation(), bimpl.getRotation(), weight) :
                        select(aimpl.getRotation(), bimpl.getRotation(), weight),
                    select(aimpl.isRotationAbsolute(), bimpl.isRotationAbsolute(), weight)                    
                ));
            } else {
                return std::shared_ptr<Style>(new IconPointStyle(
                    interpolate(aimpl.getColor(), bimpl.getColor(), weight),
                    select(aimpl.getIconURI(), bimpl.getIconURI(), weight),
                    (float)interpolate(aimpl.getScaling(), bimpl.getScaling(), weight),
                    select(aimpl.getHorizontalAlignment(), bimpl.getHorizontalAlignment(), weight),
                    select(aimpl.getVerticalAlignment(), bimpl.getVerticalAlignment(), weight),
                    (aimpl.isRotationAbsolute() == bimpl.isRotationAbsolute()) ?
                        (float)interpolate(aimpl.getRotation(), bimpl.getRotation(), weight) :
                        select(aimpl.getRotation(), bimpl.getRotation(), weight),
                    select(aimpl.isRotationAbsolute(), bimpl.isRotationAbsolute(), weight)                    
                ));
            }
        }
        case TESC_BasicStrokeStyle :
        {
            const auto &aimpl = static_cast<const BasicStrokeStyle&>(a);
            const auto &bimpl = static_cast<const BasicStrokeStyle&>(b);
            return std::shared_ptr<Style>(new BasicStrokeStyle(
                interpolate(aimpl.getColor(), bimpl.getColor(), weight),
                (float)interpolate(aimpl.getStrokeWidth(), bimpl.getStrokeWidth(), weight),
                select(aimpl.getExtrusionMode(), bimpl.getExtrusionMode(), weight)
            ));
        }
        case TESC_BasicFillStyle :
        {
            const auto &aimpl = static_cast<const BasicFillStyle&>(a);
            const auto &bimpl = static_cast<const BasicFillStyle&>(b);
            return std::shared_ptr<Style>(new BasicFillStyle(
                interpolate(aimpl.getColor(), bimpl.getColor(), weight)
            ));
        }
        case TESC_PatternStrokeStyle :
        {
            const auto &aimpl = static_cast<const PatternStrokeStyle&>(a);
            const auto &bimpl = static_cast<const PatternStrokeStyle&>(b);
            return std::shared_ptr<Style>(new PatternStrokeStyle(
                select(aimpl.getFactor(), bimpl.getFactor(), weight),
                select(aimpl.getPattern(), bimpl.getPattern(), weight),
                interpolate(aimpl.getColor(), bimpl.getColor(), weight),
                (float)interpolate(aimpl.getStrokeWidth(), bimpl.getStrokeWidth(), weight),
                select(aimpl.getExtrusionMode(), bimpl.getExtrusionMode(), weight)
            ));
        }
        case TESC_ArrowStrokeStyle :
        {
            const auto &aimpl = static_cast<const ArrowStrokeStyle&>(a);
            const auto &bimpl = static_cast<const ArrowStrokeStyle&>(b);
            return std::shared_ptr<Style>(new ArrowStrokeStyle(
                (float)interpolate(aimpl.getArrowRadius(), bimpl.getArrowRadius(), weight),
                select(aimpl.getFactor(), bimpl.getFactor(), weight),
                select(aimpl.getPattern(), bimpl.getPattern(), weight),
                interpolate(aimpl.getColor(), bimpl.getColor(), weight),
                (float)interpolate(aimpl.getStrokeWidth(), bimpl.getStrokeWidth(), weight),
                select(aimpl.getExtrusionMode(), bimpl.getExtrusionMode(), weight),
                select(aimpl.getArrowHeadMode(), bimpl.getArrowHeadMode(), weight)
            ));
        }
        case TESC_CompositeStyle :
        {
            const auto &aimpl = static_cast<const CompositeStyle&>(a);
            const auto &bimpl = static_cast<const CompositeStyle&>(b);
            if(aimpl.getStyleCount() == bimpl.getStyleCount()) {
                bool canInterpolate = true;
                for(std::size_t i = 0u; i < aimpl.getStyleCount(); i++) {
                    canInterpolate &= aimpl.getStyle(i).getClass() == bimpl.getStyle(i).getClass();
                    if (!canInterpolate)
                        break;
                }
                if(canInterpolate) {
                    std::vector<std::shared_ptr<Style>> s;
                    s.reserve(aimpl.getStyleCount());
                    for(std::size_t i = 0u; i < aimpl.getStyleCount(); i++) {
                        s.push_back(interpolate(aimpl.getStyle(i), bimpl.getStyle(i), weight));
                    }
                    StylePtr cs(nullptr, nullptr);
                    return CompositeStyle_create(cs, s.data(), s.size()) == TE_Ok ? std::move(cs) : std::shared_ptr<Style>();
                }
            }
            
            
            // can't interpolate, fall through to select based on weight
        }
        case TESC_LevelOfDetailStyle :
        default :
            StylePtr s((weight < 0.5) ? a.clone() : b.clone(), atakmap::feature::Style::destructStyle);
            return std::move(s);
        }
    }
}
