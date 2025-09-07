
#include "renderer/GLWorkers.h"
#include "renderer/RenderContextAssociatedCache.h"

using namespace TAK::Engine::Renderer;
using namespace TAK::Engine::Core;
using namespace TAK::Engine::Util;

namespace {
    struct ContextWorkers {
        std::shared_ptr<ControlWorker> resourceLoad;
        std::shared_ptr<ControlWorker> threadWorker;
    };

    GlobalRenderContextAssociatedCache<ContextWorkers> workerCache;
}

static std::shared_ptr<ControlWorker> makeGLControlWorker() NOTHROWS {
	std::shared_ptr<ControlWorker> worker;
	Worker_createControlWorker(worker);
	return worker;
}

static std::shared_ptr<ControlWorker> globalGLResourceControlWorker() NOTHROWS {
	RenderContext* renderContext = nullptr;
    RenderContext_getCurrent(&renderContext);
    ContextWorkers& workers = workerCache.get(renderContext);
    if (!workers.resourceLoad)
        workers.resourceLoad = makeGLControlWorker();
    return workers.resourceLoad;
}

static std::shared_ptr<ControlWorker> globalGLThreadWorker() NOTHROWS {
    RenderContext* renderContext = nullptr;
	RenderContext_getCurrent(&renderContext);
    ContextWorkers& workers = workerCache.get(renderContext);
    if (!workers.threadWorker)
        workers.threadWorker = makeGLControlWorker();
    return workers.threadWorker;
}

SharedWorkerPtr TAK::Engine::Renderer::GLWorkers_resourceLoad() NOTHROWS {
	return globalGLResourceControlWorker();
}

TAKErr TAK::Engine::Renderer::GLWorkers_doResourceLoadingWork(size_t millisecondLimit) NOTHROWS {
	std::shared_ptr<ControlWorker> worker = globalGLResourceControlWorker();
	if (!worker)
		return TE_Err;
	worker->doAnyWork(millisecondLimit);
	return TE_Ok;
}

SharedWorkerPtr TAK::Engine::Renderer::GLWorkers_glThread() NOTHROWS {
	return globalGLThreadWorker();
}

TAKErr TAK::Engine::Renderer::GLWorkers_doGLThreadWork() NOTHROWS {
	std::shared_ptr<ControlWorker> worker = globalGLThreadWorker();
	if (!worker)
		return TE_Err;
	worker->doAnyWork(INT64_MAX);
	return TE_Ok;
}