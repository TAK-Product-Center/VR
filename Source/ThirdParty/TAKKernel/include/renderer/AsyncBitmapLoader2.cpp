#include "renderer/AsyncBitmapLoader2.h"


#include "renderer/BitmapFactory2.h"
#include "thread/Lock.h"
#include "util/NonHeapAllocatable.h"
#include "util/ProtocolHandler.h"

using namespace TAK::Engine::Renderer;

using namespace TAK::Engine::Thread;
using namespace TAK::Engine::Util;

using namespace atakmap::util;


namespace
{
    class ProtocolHandlerBitmapFactory : public BitmapFactory2
    {
    public :
        TAKErr decode(BitmapPtr &result, const char *uri, const BitmapDecodeOptions *opts) NOTHROWS override
        {
            TAKErr code = TE_Ok;

            // handle the URI
            DataInput2Ptr ctx(nullptr, nullptr);
            code = ProtocolHandler_handleURI(ctx, uri);
            TE_CHECKLOGRETURN_CODE(code, atakmap::util::Logger::Error, "failed to handle URI %s", uri);

            // decode the data stream
            return BitmapFactory2_decode(result, *ctx, nullptr);
        }
    };

    struct BitmapDecodeOpaque
    {
        AsyncBitmapLoader2 *loader{nullptr};
        std::string scheme;
        std::string uri;
    };

    FileProtocolHandler fileHandler;
    ZipProtocolHandler zipHandler;

    bool registerHandlers() NOTHROWS
    {
        AsyncBitmapLoader2::registerProtocolHandler("file", &fileHandler, "LOCAL");
        AsyncBitmapLoader2::registerProtocolHandler("zip", &zipHandler, "LOCAL_COMPRESSED");
        AsyncBitmapLoader2::registerProtocolHandler("arc", &zipHandler, "LOCAL_COMPRESSED");
        return true;
    }
}

RWMutex AsyncBitmapLoader2::decoderHandlerMutex;
std::map<std::string, std::string> AsyncBitmapLoader2::protoSchemeQueueHints;

AsyncBitmapLoader2::AsyncBitmapLoader2(const std::size_t threadCount, bool notifyThreadsOnDestruct_) NOTHROWS :
    threadCount(threadCount),
    notifyThreadsOnDestruct(notifyThreadsOnDestruct_),
    shouldTerminate(false)
{
    static bool rh = registerHandlers();
}

AsyncBitmapLoader2::~AsyncBitmapLoader2() NOTHROWS
{
    Lock lock(queuesMutex);

    // Firstly, mark as terminated so nothing new is accepted
    shouldTerminate = true;

    std::map<std::string, Queue *>::iterator iter;
    for (iter = queues.begin(); iter != queues.end(); iter++)
        delete iter->second;
    queues.clear();
}


TAKErr AsyncBitmapLoader2::loadBitmapUri(Task &task, const char *curi) NOTHROWS
{
    if (!curi)
        return TE_InvalidArg;

    ReadLock handlersLock(handlers.mutex);

    std::string uri(curi);

    std::size_t cloc = uri.find_first_of(':');
    std::string scheme = (cloc == std::string::npos) ? "" : uri.substr(0, cloc);

    // check the global protocol handlers if there isn't a registered instance handler
    if(handlers.value.find(scheme) == handlers.value.end()) {
        // if the URI does not have a protocol, assume it's a file
        if (cloc == std::string::npos) {
            std::ostringstream strm;
            strm << "file://";
            strm << uri;

            uri = strm.str();
            scheme = "file";
        }
        if (!ProtocolHandler_isHandlerRegistered(scheme.c_str())) {
            Logger::log(Logger::Error, "no protocol handler found: %s", scheme.c_str());
            return TE_Err;
        }
    }

    Lock lock(queuesMutex);
    std::string queueHint = (handlers.schemeHints.find(scheme) != handlers.schemeHints.end()) ?
            handlers.schemeHints[scheme] : protoSchemeQueueHints[scheme];
    if (!ensureThread(queueHint.c_str())) {
        // Already in shutdown mode - don't allow the job
        return TE_IllegalState;
    }

    std::unique_ptr<BitmapDecodeOpaque> decodeUriFnArgs(new BitmapDecodeOpaque());
    decodeUriFnArgs->loader = this;
    decodeUriFnArgs->scheme = scheme;
    decodeUriFnArgs->uri = uri;
    task.reset(new FutureTask<std::shared_ptr<Bitmap2>>(decodeUriFn, (void*)decodeUriFnArgs.release()));

    auto queue = queues[queueHint];
    Monitor::Lock qlock(queue->monitor);
    queue->jobQueue.push_back(Task(task));
    qlock.signal();
    return TE_Ok;
}

TAKErr AsyncBitmapLoader2::loadBitmapTask(const Task &task, const char *queueHint) NOTHROWS
{
    if (!task.get())
        return TE_InvalidArg;

    Lock lock(queuesMutex);

    if (!ensureThread(queueHint)) {
        // Already in shutdown mode - don't allow the job
        return TE_IllegalState;
    }

    auto queue = queues[std::string(queueHint ? queueHint : "")];
    Monitor::Lock qlock(queue->monitor);
    queue->jobQueue.push_back(Task(task));
    qlock.signal();
    return TE_Ok;
}

TAKErr AsyncBitmapLoader2::addBitmapFactory(const char *scheme, const std::shared_ptr<BitmapFactory2> &handler, const char *queueHint) NOTHROWS
{
    WriteLock lock(handlers.mutex);
    if(scheme && queueHint)
        handlers.schemeHints[scheme] = queueHint;
    if(!scheme)
        scheme = "";
    handlers.value[scheme] = handler;
    return TE_Ok;
}
TAKErr AsyncBitmapLoader2::removeBitmapFactory(const BitmapFactory2 &handler) NOTHROWS
{
    WriteLock lock(handlers.mutex);
    for(auto it = handlers.value.begin(); it != handlers.value.end(); it++) {
        if((&handler) == it->second.get()) {
            handlers.value.erase(it);
            break;
        }
    }
    return TE_Ok;
}

TAKErr AsyncBitmapLoader2::registerProtocolHandler(const char *scheme, ProtocolHandler *handler, const char *queueHint) NOTHROWS
{
    TAKErr code(TE_Ok);
    if (!scheme || !handler)
        return TE_InvalidArg;
    WriteLock lock(decoderHandlerMutex);
    code = ProtocolHandler_registerHandler(scheme, *handler);
    TE_CHECKRETURN_CODE(code);
    protoSchemeQueueHints[scheme] = std::string(queueHint ? queueHint : "");
    return code;
}

TAKErr AsyncBitmapLoader2::unregisterProtocolHandler(const char *scheme) NOTHROWS
{
    TAKErr code(TE_Ok);
    if (!scheme)
        return TE_InvalidArg;
    WriteLock lock(decoderHandlerMutex);
    code = ProtocolHandler_unregisterHandler(scheme);
    TE_CHECKRETURN_CODE(code);
    protoSchemeQueueHints.erase(scheme);
    return code;
}
TAKErr AsyncBitmapLoader2::unregisterProtocolHandler(const ProtocolHandler &handler) NOTHROWS
{
    TAKErr code(TE_Ok);
    WriteLock lock(decoderHandlerMutex);
    code = ProtocolHandler_unregisterHandler(handler);
    TE_CHECKRETURN_CODE(code);
    // XXX - won't erase the scheme hint -- but since no handler is registered, moot
    return code;
}

bool AsyncBitmapLoader2::ensureThread(const char *queueHint)
{
    if (shouldTerminate)
        return false;

    Queue *queue;

    std::map<std::string, Queue *>::iterator entry;
    entry = queues.find(std::string(queueHint ? queueHint : ""));
    if (entry == queues.end()) {
        std::unique_ptr<Queue> queuePtr(queue=new Queue(*this));
        queues[std::string(queueHint ? queueHint : "")] = queuePtr.release();
    } else {
        queue = entry->second;
    }

    if (queue->threadPool.get() == nullptr) {

        // init threads
        return ( ThreadPool_create(queue->threadPool, threadCount, threadProcessEntry, queue) == TE_Ok );
    }

    return true;
}

void *AsyncBitmapLoader2::threadProcessEntry(void *opaque)
{
    auto *obj = (Queue *)opaque;
    obj->owner.threadProcess(*obj);
    return nullptr;
}

void AsyncBitmapLoader2::threadProcess(Queue &queue)
{
    while (true) {
        Task job;
        {
            Monitor::Lock lock(queue.monitor);
            if (shouldTerminate)
                break;

            if (queue.jobQueue.empty()) {
                lock.wait();
                continue;
            }

            job = queue.jobQueue.front();
            queue.jobQueue.pop_front();
        }
        threadTryDecode(job);
    }
}

void AsyncBitmapLoader2::threadTryDecode(const Task &job)
{
    ReadLock lock(decoderHandlerMutex);

    if(job->valid()) {
        job->run();
        return;
    }
}

std::shared_ptr<Bitmap2> AsyncBitmapLoader2::decodeUriFn(void *opaque)
{
    std::unique_ptr<BitmapDecodeOpaque> args(static_cast<BitmapDecodeOpaque *>(opaque));
    BitmapPtr b(nullptr, nullptr);
    const char *uri = args->uri.c_str();

    std::shared_ptr<BitmapFactory2> instanceFactory;
    {
        ReadLock lock(args->loader->handlers.mutex);
        auto entry = args->loader->handlers.value.find(args->scheme);
        if(entry != args->loader->handlers.value.end())
            instanceFactory = entry->second;
    }
    do {
        if(!instanceFactory)
            break;
        if(instanceFactory->decode(b, uri, nullptr) != TE_Ok)
            break;
        if(!b)
            break;
        return std::shared_ptr<Bitmap2>(std::move(b));
    } while(false);

    if(args->scheme.empty())
        throw std::runtime_error("no scheme specified");
    ProtocolHandlerBitmapFactory protocolFactory;
    if(protocolFactory.decode(b, uri, nullptr) != TE_Ok || !b)
        throw std::runtime_error("failed to decode bitmap");
    return std::shared_ptr<Bitmap2>(std::move(b));
}

AsyncBitmapLoader2::Queue::Queue(AsyncBitmapLoader2 &owner_) NOTHROWS :
    owner(owner_),
    shouldTerminate(false),
    threadPool(nullptr, nullptr)
{}

AsyncBitmapLoader2::Queue::~Queue() NOTHROWS
{
    ThreadPoolPtr ltp(nullptr, nullptr);
    {
        Monitor::Lock lock(monitor);

        // Firstly, mark as terminated so nothing new is accepted
        shouldTerminate = true;

        if (threadPool) {
            ltp = std::move(threadPool);

            // kill threads first - release lock and join
            // In-progress jobs may complete; unstarted jobs will linger in queue
            if (owner.notifyThreadsOnDestruct)
                lock.broadcast();
        }
    }

    // wait for threads to exit
    if (owner.notifyThreadsOnDestruct && ltp.get())
        ltp.reset();

    {
        Monitor::Lock lock(monitor);
        // Now look at remaining jobs and clean them out with callback indicating
        // they are dead due to termination of the loader
        for(auto &job : jobQueue)
            job->getFuture().cancel();
        jobQueue.clear();
    }
}
