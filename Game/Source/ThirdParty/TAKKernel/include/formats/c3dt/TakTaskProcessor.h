#ifndef TAK_ENGINE_FORMATS_C3DT_TAKTASKPROCESSOR_H
#define TAK_ENGINE_FORMATS_C3DT_TAKTASKPROCESSOR_H

#include <deque>

#include "port/Platform.h"
#include "thread/Monitor.h"
#include "thread/ThreadPool.h"

#include "CesiumAsync/ITaskProcessor.h"

namespace TAK {
    namespace Engine {
        namespace Formats {
            namespace Cesium3DTiles {
                class TakTaskProcessor : public CesiumAsync::ITaskProcessor {
                public:
                    TakTaskProcessor() NOTHROWS;
                    ~TakTaskProcessor() NOTHROWS;

                    void startTask(std::function<void()> f) override;
                private:
                    static void* threadProcessEntry(void *opaque);
                    void threadProcess();
                private:
                    TAK::Engine::Thread::ThreadPoolPtr threadPool;
                    TAK::Engine::Thread::Monitor monitor;
                    std::deque<std::function<void()>> workQueue;
                    bool shutdown = false;
                };
            }
        }
    }
}

#endif //TAK_ENGINE_FORMATS_C3DT_TAKTASKPROCESSOR_H
