
#ifndef TAK_ENGINE_RENDERER_RENDERER_CONTEXT_ASSOCIATED_CACHE_H_INCLUDED
#define TAK_ENGINE_RENDERER_RENDERER_CONTEXT_ASSOCIATED_CACHE_H_INCLUDED

#include "core/RenderContext.h"
#include "thread/ThreadLocal.h"
#include "thread/Mutex.h"
#include "thread/Lock.h"
#include <map>
#include <new>

namespace TAK {
    namespace Engine {
        namespace Renderer {
            /**
             * Utility for caching associated data with a RenderContext
             */
            template <typename T, template <typename, typename> class S = TAK::Engine::Thread::ThreadLocalPtr >
            class RenderContextAssociatedCache {
            public:
                RenderContextAssociatedCache(const RenderContextAssociatedCache&) = delete;
                RenderContextAssociatedCache(RenderContextAssociatedCache&&) = delete;
                void operator=(const RenderContextAssociatedCache&) = delete;
                void operator=(RenderContextAssociatedCache&&) = delete;

                RenderContextAssociatedCache() {}
                ~RenderContextAssociatedCache() {}

                /**
                 * Get the data associated with the render context
                 */
                T& get(const TAK::Engine::Core::RenderContext* renderContext);
            private:
                struct Map_ {
                    enum {
                        BRUTE_FORCE_ARRAY_SIZE = 4
                    };

                    const TAK::Engine::Core::RenderContext* contexts[BRUTE_FORCE_ARRAY_SIZE];

                    // store values instead of pointers to keep to one cache page
                    T null_item;
                    T items[BRUTE_FORCE_ARRAY_SIZE];

                    std::map<const TAK::Engine::Core::RenderContext*, T> overflow;
                };

                S <Map_, std::default_delete<Map_>> impl_;
                TAK::Engine::Thread::Mutex mutex_;
            };

            template <typename T>
            using GlobalRenderContextAssociatedCache = RenderContextAssociatedCache<T, std::unique_ptr>;

             

            template <typename T, template <typename, typename> class S>
            T& RenderContextAssociatedCache<T, S>::get(const TAK::Engine::Core::RenderContext* renderContext) {
                TAK::Engine::Thread::Lock lock(mutex_);
                if (!impl_)
                    impl_.reset(new Map_());

                if (renderContext == nullptr) {
                    return impl_->null_item;
                }

                for (int i = 0; i < Map_::BRUTE_FORCE_ARRAY_SIZE; ++i) {
                    if (impl_->contexts[i] == renderContext) {
                        return impl_->items[i];
                    }
                }

                for (int i = 0; i < Map_::BRUTE_FORCE_ARRAY_SIZE; ++i) {
                    if (impl_->contexts[i] == nullptr) {
                        impl_->contexts[i] = renderContext;

                        // reinit the item to future lifecycle of multiple contexts
                        T& item = impl_->items[i];
                        item.~T();
                        ::new (static_cast<void*>(&item)) T();
                        return item;
                    }
                }

                auto it = impl_->overflow.find(renderContext);
                if (it == impl_->overflow.end())
                    it = impl_->overflow.insert(std::make_pair(renderContext, T())).first;
                return it->second;
            }
        }
    }
}

#endif