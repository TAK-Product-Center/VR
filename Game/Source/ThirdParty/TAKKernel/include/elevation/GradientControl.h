#ifndef TAK_ENGINE_ELEVATION_GRADIENTCONTROL_H_INCLUDED
#define TAK_ENGINE_ELEVATION_GRADIENTCONTROL_H_INCLUDED

#include "core/Control.h"
#include "port/Platform.h"
#include "util/Error.h"
#include "port/Collection.h"
#include "port/String.h"

namespace TAK {
    namespace Engine {
        namespace Elevation {
            class ENGINE_API GradientControl {
            public:
                enum {
                    RELATIVE_MODE = 0,
                    ABSOLUTE_MODE = 1,
                };
            protected :
                virtual ~GradientControl() NOTHROWS = 0;
            public :
                virtual Util::TAKErr getGradientColors(Port::Collection<uint32_t>& gradientColors) NOTHROWS = 0;
                virtual Util::TAKErr getLineItemStrings(Port::Collection<Port::String>& itemStrings) NOTHROWS = 0;
                virtual Util::TAKErr getMode(int* mode) NOTHROWS = 0;
                virtual Util::TAKErr setMode(int mode) NOTHROWS = 0;
            };

            ENGINE_API const char* GradientControl_getType() NOTHROWS;
        }
    }
}

#endif