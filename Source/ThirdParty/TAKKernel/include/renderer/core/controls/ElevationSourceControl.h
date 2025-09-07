//
// Created by Geo Dev on 9/13/23.
//

#ifndef TAK_ENGINE_RENDERER_CORE_CONTROLS_ELEVATIONSOURCECONTROL_H
#define TAK_ENGINE_RENDERER_CORE_CONTROLS_ELEVATIONSOURCECONTROL_H

#include "elevation/ElevationSource.h"
#include "port/Platform.h"
#include "util/Error.h"

namespace TAK {
    namespace Engine {
        namespace Renderer {
            namespace Core {
                namespace Controls {
                    class ENGINE_API ElevationSourceControl
                    {
                    protected :
                        ~ElevationSourceControl() NOTHROWS;
                    public :
                        /**
                         * Sets the `ElevationSource` to be used.
                         *
                         * @param source The `ElevationSource` or `nullptr` to use the default
                         */
                        virtual Util::TAKErr setElevationSource(const std::shared_ptr<TAK::Engine::Elevation::ElevationSource> &source) NOTHROWS = 0;
                        /**
                         * Returns the `ElevationSource` currently in use
                         *
                         * @return  The `ElevationSource` currently in use; `nullptr` if the default
                         */
                        virtual Util::TAKErr getElevationSource(std::shared_ptr<TAK::Engine::Elevation::ElevationSource> &source) NOTHROWS = 0;
                    };

                    ENGINE_API const char* ElevationSourceControl_getType() NOTHROWS;
                }
            }
        }
    }
}

#endif //ATAK_ELEVATIONSOURCECONTROL_H
