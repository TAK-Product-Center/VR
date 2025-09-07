#ifndef TAK_ENGINE_RENDERER_CORE_CONTENTCONTROL_H_INCLUDED
#define TAK_ENGINE_RENDERER_CORE_CONTENTCONTROL_H_INCLUDED

#include "port/Platform.h"
#include "util/Error.h"

namespace TAK {
    namespace Engine {
        namespace Renderer {
            namespace Core {
                class ENGINE_API ContentControl
                {
                public :
                    class OnContentChangedListener;
                public :
                    virtual ~ContentControl() NOTHROWS = 0;
                public :
                    virtual Util::TAKErr addOnContentChangedListener(OnContentChangedListener *l) NOTHROWS = 0;
                    virtual Util::TAKErr removeOnContentChangedListener(OnContentChangedListener *l) NOTHROWS = 0;
                };

                class ContentControl::OnContentChangedListener
                {
                public :
                    virtual ~OnContentChangedListener() NOTHROWS = 0;
                public :
                    /**
                     * @return  `TE_Ok` on success, `TE_Done` to unsubscribe from future events,
                     *          various codes on failure
                     */
                    virtual Util::TAKErr onContentChanged() NOTHROWS = 0;
                };

                ENGINE_API const char* ContentControl_getType() NOTHROWS;
            }
        }
    }
}
#endif
