#include "TakTaskProcessor.h"

#include "thread/Lock.h"
#include "util/Error.h"

#define NUM_THREADS 3

using namespace TAK::Engine::Util;
using namespace TAK::Engine::Thread;

TAK::Engine::Formats::Cesium3DTiles::TakTaskProcessor::TakTaskProcessor() NOTHROWS
        : threadPool(nullptr, nullptr) { }

TAK::Engine::Formats::Cesium3DTiles::TakTaskProcessor::~TakTaskProcessor() NOTHROWS
{
    {
        Monitor::Lock lock(monitor);
        shutdown = true;
        workQueue.clear();
        lock.broadcast();
    }
    if (threadPool) {
        threadPool->joinAll();
        threadPool.reset();
    }
}

void TAK::Engine::Formats::Cesium3DTiles::TakTaskProcessor::startTask(std::function<void()> f)
{
    Monitor::Lock lock(monitor);
    if(!threadPool) {
        if (ThreadPool_create(threadPool, NUM_THREADS, threadProcessEntry, this) != TE_Ok) {
            return;
        }
    }
    workQueue.push_back(f);
    lock.broadcast();
}

void *TAK::Engine::Formats::Cesium3DTiles::TakTaskProcessor::threadProcessEntry(void *opaque)
{
    auto *thiz = (TakTaskProcessor *)opaque;
    thiz->threadProcess();
    return nullptr;
}

void TAK::Engine::Formats::Cesium3DTiles::TakTaskProcessor::threadProcess()
{
    while (true) {
        std::function<void()> task;
        {
            Monitor::Lock lock(monitor);
            if (shutdown)
                break;

            if (workQueue.empty()) {
                lock.wait();
                continue;
            }

            task = workQueue.front();
            workQueue.pop_front();
        }
        task();
    }
}