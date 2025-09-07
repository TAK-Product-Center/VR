#ifndef TAK_ENGINE_UTIL_CACHINGSERVICE_H_INCLUDED
#define TAK_ENGINE_UTIL_CACHINGSERVICE_H_INCLUDED

#include <vector>
#include "port/String.h"
#include "util/Error.h"
#include "feature/Geometry2.h"

namespace atakmap {
    namespace feature {
        class Geometry;
    }
}

namespace TAK {
    namespace Engine {
        namespace Util {
            enum class StatusType {
                Started,
                Complete,
                Canceled,
                Error,
                Progress
            };

            struct CachingServiceRequest
            {
                int id;
                std::shared_ptr<TAK::Engine::Feature::Geometry2> geom;
                int priority;
                double minRes;
                double maxRes; 
                std::unique_ptr<Port::String[]> sourcePaths;
                std::size_t sourceCount;
                std::unique_ptr<Port::String[]> sinkPaths;
                std::size_t sinkCount;
            };

            struct CachingServiceStatus
            {
                int id;
                StatusType status;
                int completed;
                int total;
                int64_t startTime;
                int64_t estimateDownloadSize;
                int64_t estimateCompleteTime;
                double downloadRate;
            };

            struct CachingServiceStatusListener
            {
                virtual TAKErr statusUpdate(const CachingServiceStatus&) = 0;
            };

            ENGINE_API TAKErr CachingService_updateSource(const Port::String &source, const Port::String &defaultSink);
            ENGINE_API TAKErr CachingService_smartRequest(const CachingServiceRequest& request, const std::shared_ptr<CachingServiceStatusListener>& callback);
            ENGINE_API TAKErr CachingService_panZoomRequest(const CachingServiceRequest& request, const std::shared_ptr<CachingServiceStatusListener>& callback);
            ENGINE_API TAKErr CachingService_downloadRequest(const CachingServiceRequest& request, const std::shared_ptr<CachingServiceStatusListener>& callback);
            ENGINE_API TAKErr CachingService_cancelRequest(int id);
            ENGINE_API TAKErr CachingService_setSmartCacheDownloadLimit(const std::size_t &size);
            ENGINE_API TAKErr CachingService_getSmartCacheDownloadLimit(std::size_t& size);
            ENGINE_API TAKErr CachingService_setSmartCacheEnabled(bool enabled);
            ENGINE_API TAKErr CachingService_getSmartCacheEnabled(bool &enabled);

        }
    }
}

#endif