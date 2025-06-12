#ifndef TAK_ENGINE_RENDERER_CORE_CONTROLS_CLAMPTOGROUNDCONTROL_H_INCLUDED
#define TAK_ENGINE_RENDERER_CORE_CONTROLS_CLAMPTOGROUNDCONTROL_H_INCLUDED

#include "feature/Envelope2.h"
#include "model/Mesh.h"
#include "renderer/core/ColorControl.h"
#include "port/Collection.h"
#include "port/Platform.h"
#include "util/Error.h"

namespace TAK {
    namespace Engine {
        namespace Renderer {
            namespace Core {
                namespace Controls {
                    class ENGINE_API ClampToGroundControl
                    {
                    protected :
                        ~ClampToGroundControl() NOTHROWS;
                    public :
                        /**
                         * Sets the global status of the markers to clamp ground when looking straight down from overhead.
                         *
                         * @param v true if the marker should be clamped to ground when looking straight down.
                         */
                        virtual void setClampToGroundAtNadir(const bool v) NOTHROWS = 0;

                        /**
                         * Checks the global status of the clamp to ground setting for Markers.
                         *
                         * @return true if at least one marker is clamped to ground
                         */
                        virtual bool getClampToGroundAtNadir() const NOTHROWS = 0;
                    };

                    ENGINE_API const char* ClampToGroundControl_getType() NOTHROWS;
                }
            }
        }
    }
}

#endif