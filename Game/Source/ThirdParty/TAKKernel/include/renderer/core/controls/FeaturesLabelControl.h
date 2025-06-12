#ifndef TAK_ENGINE_RENDERER_CORE_CONTROLS_FEATURESLABELCONTROL_H_INCLUDED
#define TAK_ENGINE_RENDERER_CORE_CONTROLS_FEATURESLABELCONTROL_H_INCLUDED

#include <unordered_map>
#include "feature/Style.h"
#include "thread/Mutex.h"

namespace TAK {
    namespace Engine {
        namespace Renderer {
            namespace Core {
                namespace Controls {
                    class ENGINE_API FeaturesLabelControl
                    {
                    protected :
                        virtual ~FeaturesLabelControl() NOTHROWS = 0;
                    public :
                        virtual void setShapeCenterMarkersVisible(const bool v) NOTHROWS = 0;
                        virtual bool getShapeCenterMarkersVisible() NOTHROWS = 0;
                        virtual void setShapeLabelVisible(int64_t fid, bool visible) NOTHROWS = 0;
                        virtual bool getShapeLabelVisible(int64_t fid) NOTHROWS = 0;
                        virtual void setDefaultLabelBackground(const uint32_t bgColor, const bool override) NOTHROWS = 0;
                        virtual void getDefaultLabelBackground(uint32_t *color, bool *override) NOTHROWS = 0;
                        virtual void setDefaultLabelLevelOfDetail(const std::size_t minLod, const std::size_t maxLod) NOTHROWS = 0;
                        virtual void getDefaultLabelLevelOfDetail(std::size_t *minLod, std::size_t *maxLod) NOTHROWS = 0;
                    };

                    ENGINE_API const char* FeaturesLabelControl_getType() NOTHROWS;
                }
            }
        }
    }
}
#endif