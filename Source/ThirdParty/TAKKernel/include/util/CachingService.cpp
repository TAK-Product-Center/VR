#include <queue>
#include <climits>

#include "feature/Geometry.h"

#include "port/STLVectorAdapter.h"

#include "raster/tilematrix/TileScraper.h"
#include "raster/tilematrix/TileClientFactory.h"
#include "raster/tilematrix/TileContainerFactory.h"
#include "raster/tilematrix/TileProxy.h"

#include "thread/Lock.h"
#include "thread/Thread.h"

#include "util/CachingService.h"
#include "util/ConfigOptions.h"

using TAK::Engine::Port::String;
using namespace TAK::Engine::Util;
using namespace TAK::Engine::Raster::TileMatrix;
using namespace TAK::Engine;

namespace
{

    struct CachingServiceTask
    {
        int id;
        int priority;
        int secondaryPriority;
        std::vector<TileScraperPtr> scrapers;

        CachingServiceTask(int id, int priority, int secondaryPriority, std::vector<TileScraperPtr>&& ptr) : id(id), secondaryPriority(secondaryPriority),
            priority(priority), scrapers(std::move(ptr))
        {

        }

        bool operator<(const CachingServiceTask& other)
        {
            return priority < other.priority ? true : secondaryPriority < other.secondaryPriority;
        }

        void run()
        {
            for (auto& scraper : scrapers)
                scraper->run();
        }

        void cancel()
        {
            for (auto& scraper : scrapers)
                scraper->cancel();
        }

    };

    class ScraperListenerForwarder : public CacheRequestListener
    {
        std::shared_ptr<CachingServiceStatusListener> listener;
        int id;
        std::size_t scraperCount;
        std::atomic_bool started;
        std::atomic<int> completedCount;
        std::weak_ptr<CachingServiceTask> task;
        int64_t startTime = 0;
    public:
        ScraperListenerForwarder(int id_, const std::shared_ptr<CachingServiceStatusListener>& l, std::size_t scrapers) : id(id_), listener(l), scraperCount(scrapers), started(false), completedCount(0)
        {
        }
        virtual TAKErr onRequestStarted() NOTHROWS
        {
            if (!listener)
                return TE_Ok;
            CachingServiceStatus status
            {
                id, StatusType::Started, 0
            };
            if (!started.exchange(true))
            {
                startTime = TAK::Engine::Port::Platform_systime_millis();
                listener->statusUpdate(status);
            }
            return TE_Ok;
        }
        virtual TAKErr onRequestComplete() NOTHROWS
        {
            if (!listener)
                return TE_Ok;

            CachingServiceStatus status
            {
                id, StatusType::Complete
            };

            if(++completedCount == scraperCount)
                listener->statusUpdate(status);
            return TE_Ok;
        }
        virtual TAKErr onRequestProgress(int taskNum, int numTasks, int taskProgress, int maxTaskProgress, int totalProgress, int maxTotalProgress) NOTHROWS
        {
            if (!listener)
                return TE_Ok;

            CachingServiceStatus status
            {
                id, StatusType::Progress
            };

            std::size_t totalTiles = 0, totalDownloaded = 0, totalBytesDownloaded = 0;
            std::shared_ptr<CachingServiceTask> locked = task.lock();
            if (locked)
            {
                for (TileScraperPtr& scraper : locked->scrapers)
                {
                    totalTiles += scraper->getTotalTiles();
                    int tiles = 0;
                    std::size_t bytes = 0;
                    scraper->getTilesDownloaded(tiles, bytes);
                    totalDownloaded += tiles;
                    totalBytesDownloaded += bytes;
                }
                if (totalDownloaded && totalBytesDownloaded)
                {
                    double estimatedTotalBytes = ((double)totalBytesDownloaded / (double)totalDownloaded) * (double)totalTiles;
                    int64_t currentTime = TAK::Engine::Port::Platform_systime_millis();

                    status.completed = (int)totalDownloaded;
                    status.estimateDownloadSize = (int64_t)estimatedTotalBytes;
                    status.total = (int)totalTiles;
                    status.startTime = startTime;
                    status.downloadRate = (double)totalBytesDownloaded / double((currentTime - startTime) / 1000.);

                    double remainingTime = (estimatedTotalBytes - (double)totalBytesDownloaded) / (status.downloadRate * 1000.);
                    status.estimateCompleteTime = currentTime + (int64_t)remainingTime;
                }
            }

            return TE_Ok;
        }
        virtual TAKErr onRequestError(const char* message, bool fatal) NOTHROWS
        {
            if (!listener)
                return TE_Ok;

            CachingServiceStatus status
            {
                id, StatusType::Error
            };
            listener->statusUpdate(status);
            return TE_Ok;
        }
        virtual TAKErr onRequestCanceled() NOTHROWS
        {
            if (!listener)
                return TE_Ok;

            CachingServiceStatus status
            {
                id, StatusType::Canceled
            };
            listener->statusUpdate(status);
            return TE_Ok;
        }
        void setTask(std::weak_ptr<CachingServiceTask> cachingServiceTask)
        {
            task = cachingServiceTask;
        }
    };  

    struct CachingServiceTaskCompare
    {
        bool operator()(const std::weak_ptr<CachingServiceTask>& a, const std::weak_ptr<CachingServiceTask>& b)
        {
            auto al = a.lock();
            auto bl = b.lock();
            if (!al && !bl)
                return false;
            else if (!al)
                return true;
            else if (!bl)
                return false;

            return *al < *bl;
        }
    };


    class CachingService
    {
        std::priority_queue<std::weak_ptr<CachingServiceTask>, std::vector<std::weak_ptr<CachingServiceTask>>, CachingServiceTaskCompare> priorityQueue;
        std::atomic<int> priorityQueueSize;
        std::map<int, std::shared_ptr<CachingServiceTask>> idToTaskMap;
        int count = INT_MAX;
        Thread::Monitor queueMonitor;
        bool isShutdown = false;
        Thread::ThreadPoolPtr pool;
        std::size_t threadCount = 2;
        int run = 0;

    public:

        CachingService(std::size_t threadCount = 2) : pool(nullptr, nullptr), threadCount(threadCount), priorityQueueSize(0)
        {
            Thread::ThreadPool_create(pool, (std::size_t)1, threadRun, (void*)this);
        }

        ~CachingService()
        {
            shutdown();
            pool->joinAll();
        }
        std::weak_ptr<CachingServiceTask> addTask(int id, int priority, std::vector<TileScraperPtr> &&ptr)
        {
            Thread::Monitor::Lock mLock(queueMonitor);
            std::shared_ptr<CachingServiceTask> task(new CachingServiceTask(id, priority, --count, std::move(ptr)));
            priorityQueue.push(task);
            ++priorityQueueSize;
            idToTaskMap[id] = task;
            mLock.broadcast();
            return task;
        }

        int getPriorityQueueSize()
        {
            return priorityQueueSize;
        }

        void shutdown()
        {
            Thread::Monitor::Lock mLock(queueMonitor);
            isShutdown = true;
            mLock.broadcast();
        }

        void cancelTask(int id)
        {
            Thread::Monitor::Lock mLock(queueMonitor);
            auto it = idToTaskMap.find(id);
            if (it != idToTaskMap.end())
            {
                it->second->cancel();
                idToTaskMap.erase(it);
            }
        }

        static void *threadRun(void* selfPtr)
        {
            CachingService* self = static_cast<CachingService*>(selfPtr);
            while (true) 
            {
                std::shared_ptr<CachingServiceTask> task;
                {
                    Thread::Monitor::Lock mLock(self->queueMonitor);
                    while (!task && !self->priorityQueue.empty())
                    {
                        task = self->priorityQueue.top().lock();
                        self->priorityQueue.pop();
                        --self->priorityQueueSize;
                    }
                    if (!task && self->priorityQueue.empty())
                    {
                        if(self->isShutdown)
                            break;
                        mLock.wait();
                    }
                }
                
                ++self->run;
                if(task)
                {
                    task->run();
                    Thread::Monitor::Lock mLock(self->queueMonitor);
                    self->idToTaskMap.erase(task->id);
                }
            }
            return nullptr;
        }
    };

    CachingService &downloadCachingService()
    {
        static CachingService service;
        return service;
    }

    CachingService& smartCachingService()
    {
        static CachingService service(4);
        return service;
    }
}

namespace
{
    static Thread::Mutex sourceMutex;
    static std::map<String, String, TAK::Engine::Port::StringLess> defaultSourceSink;
    static String mostRecentSource;
    static std::size_t cacheLimitSizeBytes = 5000000;
    static bool smartCacheEnabled = false;
    static int maxPriorityQueueSize = 4;

    void addDefaults(const String& source, const String& sink)
    {
        Thread::Lock lock(sourceMutex);
        defaultSourceSink[source] = sink;
        mostRecentSource = source;
    }

    void getDefaults(std::vector<String>& sources, std::vector<String>& sinks)
    {
        Thread::Lock lock(sourceMutex);
        for (auto& sourceSink : defaultSourceSink)
        {
            sources.push_back(sourceSink.first);
            sinks.push_back(sourceSink.second);
        }
    }

    void getMostRecentDefault(String& source, String& sink)
    {
        Thread::Lock lock(sourceMutex);
        if (!mostRecentSource)
            return;
        source = mostRecentSource;
        sink = defaultSourceSink[mostRecentSource];
    }

    std::size_t getSmartCacheDownloadLimitBytes()
    {
        Thread::Lock lock(sourceMutex);
        return cacheLimitSizeBytes;

    }
    void setSmartCacheDownloadLimitBytes(const std::size_t size)
    {
        Thread::Lock lock(sourceMutex);
        cacheLimitSizeBytes = size;
    }

    bool getSmartCacheEnabled()
    {
        Thread::Lock lock(sourceMutex);
        return smartCacheEnabled;
    }
    void setSmartCacheEnabled(bool enabled)
    {
        Thread::Lock lock(sourceMutex);
        smartCacheEnabled = enabled;
    }
}

TAKErr TAK::Engine::Util::CachingService_updateSource(const String & source, const String & defaultSink)
{
    addDefaults(source, defaultSink);
    return TE_Ok;
}

TAKErr createScrapers(std::vector<TileScraperPtr>& scrapers, std::shared_ptr<ScraperListenerForwarder>& forwarder, const CachingServiceRequest& request, const std::shared_ptr<CachingServiceStatusListener>& listener, bool useCacheLimit)
{
    if (!request.geom)
        return TE_InvalidArg;

    TileContainerPtr sink(nullptr, nullptr);
    TileClientPtr tileClient(nullptr, nullptr);
    TileScraperPtr tileScraper(nullptr, nullptr);
    CacheRequest scraperRequest;
    TileClientSpi::Options options;
    scraperRequest.minResolution = request.minRes;
    scraperRequest.maxResolution = request.maxRes;
    if(useCacheLimit)
        scraperRequest.maxDownloadBytes = getSmartCacheDownloadLimitBytes();
    TAK::Engine::Feature::Geometry_clone(scraperRequest.region, *request.geom);

    if (request.sinkCount != request.sourceCount)
        return TE_InvalidArg;

    std::vector<String> sinks, sources;
    for (int i = 0; i < request.sinkCount; ++i)
    {
        sources.push_back(request.sourcePaths[i]);
        sinks.push_back(request.sinkPaths[i]);
    }
    if (sources.empty())
    {
        TAK::Engine::Port::String lastSource;
        TAK::Engine::Port::String lastSink;
        getMostRecentDefault(lastSource, lastSink);
        if(!lastSource || !lastSink)
            return TE_InvalidArg;
        sources.push_back(lastSource);
        sinks.push_back(lastSink);
    }

    forwarder.reset(new ScraperListenerForwarder(request.id, listener, request.sinkCount));
    for (int i = 0; i < sinks.size(); ++i)
    {
        // pass nullptr for sink so that a proxy is not created on platforms where it would be
        TileClientFactory_create(tileClient, sources[i], nullptr, &options);
        TileContainerFactory_open(sink, sinks[i], false, nullptr);

        if (!sink || !tileClient)
            return TE_InvalidArg;

        std::shared_ptr<TileContainer> sinkShared(sink.release(), sink.get_deleter());
        std::shared_ptr<TileClient> clientShared(tileClient.release(), tileClient.get_deleter());

        if (TE_ISNAN(scraperRequest.minResolution) || TE_ISNAN(scraperRequest.maxResolution))
        {
            Port::STLVectorAdapter<TileMatrix::ZoomLevel> zoomLevels;

            clientShared->getZoomLevel(zoomLevels);
            TileMatrix::ZoomLevel zoomLevel;
            if (TE_ISNAN(scraperRequest.minResolution))
            {
                zoomLevels.get(zoomLevel, 0);
                scraperRequest.minResolution = zoomLevel.resolution;
            }

            if (TE_ISNAN(scraperRequest.maxResolution))
            {
                zoomLevels.get(zoomLevel, zoomLevels.size()-1);
                scraperRequest.maxResolution = zoomLevel.resolution;
            }
        }

        TileScraperPtr scraper(nullptr, nullptr);
        scraperRequest.maxThreads = 3;
        TileScraper_create(scraper, clientShared, sinkShared, scraperRequest, forwarder);

        // set debug tint option if requested
        if (scraper) {
            String enabled;
            ConfigOptions_getOption(enabled, "caching-service.debug-tint-enabled");
            if (enabled != nullptr && enabled != "0")
                TileScraper_enableDebugTint(*scraper);
        }

        scrapers.push_back(std::move(scraper));
    }
    return TE_Ok;
}

TAKErr TAK::Engine::Util::CachingService_smartRequest(const CachingServiceRequest& request, const std::shared_ptr<CachingServiceStatusListener>& listener)
{
    std::vector<TileScraperPtr> scrapers;
    std::shared_ptr<ScraperListenerForwarder> forwarder;

    if (!getSmartCacheEnabled())
        return TE_Ok;

    if (smartCachingService().getPriorityQueueSize() > maxPriorityQueueSize)
        return TE_Ok;

    auto code = createScrapers(scrapers, forwarder, request, listener, true);
    TE_CHECKRETURN_CODE(code);

    if (scrapers.size())
    {
        auto task = smartCachingService().addTask(request.id, request.priority, std::move(scrapers));
        forwarder->setTask(task);
    }
    return TE_Ok;
}

TAKErr TAK::Engine::Util::CachingService_panZoomRequest(const CachingServiceRequest& request, const std::shared_ptr<CachingServiceStatusListener>& listener)
{
    return TE_NotImplemented;
}

TAKErr TAK::Engine::Util::CachingService_downloadRequest(const CachingServiceRequest& request, const std::shared_ptr<CachingServiceStatusListener>& listener)
{
    std::vector<TileScraperPtr> scrapers;
    std::shared_ptr<ScraperListenerForwarder> forwarder;

    auto code = createScrapers(scrapers, forwarder, request, listener, false);
    TE_CHECKRETURN_CODE(code);
    
    if (scrapers.size())
    {
        auto task = downloadCachingService().addTask(request.id, request.priority, std::move(scrapers));
        forwarder->setTask(task);
    }
    return TE_Ok;
}

TAKErr TAK::Engine::Util::CachingService_cancelRequest(int id)
{
    smartCachingService().cancelTask(id);
    downloadCachingService().cancelTask(id);
    return TE_Ok;
}

TAKErr TAK::Engine::Util::CachingService_setSmartCacheDownloadLimit(const std::size_t& size)
{
    setSmartCacheDownloadLimitBytes(size);
    return TE_Ok;
}
TAKErr TAK::Engine::Util::CachingService_getSmartCacheDownloadLimit(std::size_t& size)
{
    size = getSmartCacheDownloadLimitBytes();
    return TE_Ok;
}

TAKErr TAK::Engine::Util::CachingService_setSmartCacheEnabled(bool enabled)
{
    setSmartCacheEnabled(enabled);
    return TE_Ok;
}

TAKErr TAK::Engine::Util::CachingService_getSmartCacheEnabled(bool &enabled)
{
    enabled = smartCacheEnabled;
    return TE_Ok;
}