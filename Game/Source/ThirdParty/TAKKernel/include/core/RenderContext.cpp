#include "core/RenderContext.h"
#include "thread/ThreadLocal.h"

using namespace TAK::Engine::Core;
using namespace TAK::Engine::Util;

RenderContext::~RenderContext() NOTHROWS
{}

static thread_local RenderContext* currentRenderContext;

TAKErr TAK::Engine::Core::RenderContext_setCurrent(RenderContext* renderContext) NOTHROWS {
    currentRenderContext = renderContext;
    return TE_Ok;
}

TAKErr TAK::Engine::Core::RenderContext_getCurrent(RenderContext** renderContextPtr) NOTHROWS {
    if (!renderContextPtr)
        return TE_Err;
    *renderContextPtr = currentRenderContext;
    return TE_Ok;
}