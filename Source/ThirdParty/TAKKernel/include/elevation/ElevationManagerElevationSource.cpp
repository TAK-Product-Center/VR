#include "elevation/ElevationManagerElevationSource.h"

#include <set>

#include "elevation/ElevationChunkFactory.h"
#include "elevation/ElevationManager.h"
#include "elevation/ElevationSourceManager.h"
#include "port/STLVectorAdapter.h"
#include "thread/Monitor.h"
#include "thread/Thread.h"

using namespace TAK::Engine::Elevation;

using namespace TAK::Engine::Core;
using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Thread;
using namespace TAK::Engine::Util;

namespace
{
    typedef std::pair<std::shared_ptr<ElevationSource>, const ElevationSource *> ElevationSourceSubscription;

    class ElevationSourceImpl : public ElevationSource,
                                public ElevationSource::OnContentChangedListener,
                                public ElevationSourcesChangedListener
    {
    private :
        struct AsyncCore
        {
            Monitor monitor { TEMT_Recursive };
            struct {
                bool contentChanged {false};
                std::vector<ElevationSourceSubscription> subscriptions;
            } pendingNotification;
            bool terminate { false };
            std::set<ElevationSource::OnContentChangedListener*> listeners;
            ElevationSourceImpl *owner {nullptr};
        };
    public :
        ElevationSourceImpl() NOTHROWS;
        ~ElevationSourceImpl() NOTHROWS;
    public : // ElevationSource
        const char *getName() const NOTHROWS override;
        TAKErr query(ElevationChunkCursorPtr &value, const QueryParameters &params) NOTHROWS override;
        TAK::Engine::Feature::Envelope2 getBounds() const NOTHROWS override;
        TAKErr addOnContentChangedListener(ElevationSource::OnContentChangedListener *l) NOTHROWS override;
        TAKErr removeOnContentChangedListener(ElevationSource::OnContentChangedListener *l) NOTHROWS override;
    public : // ElevationSource::OnContentChangedListener
        TAKErr onContentChanged(const ElevationSource &source) NOTHROWS override;
    public : // ElevationSourcesChangedListener
        TAKErr onSourceAttached(const std::shared_ptr<ElevationSource> &src) NOTHROWS override;
        TAKErr onSourceDetached(const ElevationSource &src) NOTHROWS override;
    private :

    private :
        static void *eventDispatchThread(void *opaque);
    public :
        std::shared_ptr<AsyncCore> core;
        ThreadPtr dispatcher;
    };
}

TAKErr TAK::Engine::Elevation::ElevationManagerElevationSource_create(ElevationSourcePtr& value, const std::size_t numPostsLat, const std::size_t numPostLng, const HeightmapStrategy strategy) NOTHROWS
{
    return ElevationManagerElevationSource_create(value);
}
TAKErr TAK::Engine::Elevation::ElevationManagerElevationSource_create(ElevationSourcePtr& value) NOTHROWS
{
    value = ElevationSourcePtr(new ElevationSourceImpl(), Memory_deleter_const<ElevationSource, ElevationSourceImpl>);
    return TE_Ok;
}

namespace
{   
    ElevationSourceImpl::ElevationSourceImpl() NOTHROWS :
        core(std::make_shared<AsyncCore>()),
        dispatcher(nullptr, nullptr)
    {
        core->owner = this;
        ElevationSourceManager_addOnSourcesChangedListener(this);
        Thread_start(dispatcher, eventDispatchThread, new std::shared_ptr<AsyncCore>(core));
    }
    ElevationSourceImpl::~ElevationSourceImpl() NOTHROWS
    {
        ElevationSourceManager_removeOnSourcesChangedListener(this);
        {
            Monitor::Lock lock(core->monitor);
            core->terminate = true;
            lock.broadcast();
        }
        dispatcher.reset();
    }

    const char* ElevationSourceImpl::getName() const NOTHROWS
    {
        return "ElevationManager";
    }
    TAKErr ElevationSourceImpl::query(ElevationChunkCursorPtr &value, const QueryParameters &params) NOTHROWS
    {
        return ElevationManager_queryElevationSources(value, params);
    }
    TAK::Engine::Feature::Envelope2 ElevationSourceImpl::getBounds() const NOTHROWS
    {
        return TAK::Engine::Feature::Envelope2(-180.0, -90.0, 0.0, 180.0, 90.0, 0.0);
    }
    TAKErr ElevationSourceImpl::addOnContentChangedListener(ElevationSource::OnContentChangedListener *l) NOTHROWS
    {
        if (!l)
            return TE_InvalidArg;
        Monitor::Lock lock(core->monitor);
        core->listeners.insert(l);
        return TE_Ok;
    }
    TAKErr ElevationSourceImpl::removeOnContentChangedListener(ElevationSource::OnContentChangedListener *l) NOTHROWS
    {
        if (!l)
            return TE_InvalidArg;
        Monitor::Lock lock(core->monitor);
        core->listeners.erase(l);
        return TE_Ok;
    }
    TAKErr ElevationSourceImpl::onContentChanged(const ElevationSource &source) NOTHROWS
    {
        Monitor::Lock lock(core->monitor);
        core->pendingNotification.contentChanged = true;
        lock.signal();
        return TE_Ok;
    }
    TAKErr ElevationSourceImpl::onSourceAttached(const std::shared_ptr<ElevationSource> &src) NOTHROWS
    {
        Monitor::Lock lock(core->monitor);
        core->pendingNotification.subscriptions.push_back(ElevationSourceSubscription(src, nullptr));
        lock.signal();
        return TE_Ok;
    }
    TAKErr ElevationSourceImpl::onSourceDetached(const ElevationSource &src) NOTHROWS
    {
        Monitor::Lock lock(core->monitor);
        core->pendingNotification.subscriptions.push_back(ElevationSourceSubscription(std::shared_ptr<ElevationSource>(), &src));
        lock.signal();
        return TE_Ok;
    }
    void *ElevationSourceImpl::eventDispatchThread(void *opaque)
    {
        std::shared_ptr<AsyncCore> core;
        {
            std::unique_ptr<std::shared_ptr<AsyncCore>> arg(static_cast<std::shared_ptr<AsyncCore> *>(opaque));
            core = *arg.get();
        }

        std::set<std::shared_ptr<ElevationSource>> subscribedSources;
        std::vector<ElevationSourceSubscription> subscriptionUpdates;
        while(true) {
            {
                Monitor::Lock lock(core->monitor);
                if(core->terminate)
                    break;

                if(!core->pendingNotification.contentChanged &&
                    core->pendingNotification.subscriptions.empty()) {

                    lock.wait();
                    continue;
                }

                if(core->pendingNotification.contentChanged) {
                    for(auto l : core->listeners)
                        l->onContentChanged(*core->owner);
                    core->pendingNotification.contentChanged = false;
                }

                subscriptionUpdates = core->pendingNotification.subscriptions;
                core->pendingNotification.subscriptions.clear();
            }

            for(auto &subscription : subscriptionUpdates) {
                if(subscription.first) {
                    if(subscribedSources.find(subscription.first) == subscribedSources.end()) {
                        subscription.first->addOnContentChangedListener(core->owner);
                        subscribedSources.insert(subscription.first);
                    }
                } else if(subscription.second) {
                    for(auto &subscribedSource : subscribedSources) {
                        if(subscribedSource.get() == subscription.second) {
                            subscribedSource->removeOnContentChangedListener(core->owner);
                            subscribedSources.erase(subscribedSource);
                            break;
                        }
                    }
                }
            }
        }

        return nullptr;
    }
}
