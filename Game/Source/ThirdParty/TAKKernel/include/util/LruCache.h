#ifndef TAK_ENGINE_UTIL_LRUCACHE_H_INCLUDED
#define TAK_ENGINE_UTIL_LRUCACHE_H_INCLUDED

#include <list>
#include <unordered_map>

#include "port/Platform.h"
#include "util/Error.h"

namespace TAK {
    namespace Engine {
        namespace Util {
            template<class T>
            struct ENGINE_API LruCache_cost
            {
                std::size_t operator()(const T &t) NOTHROWS
                {
                    return 1u;
                }
            };
            
            template<class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>, class Cost = LruCache_cost<T>>
            class ENGINE_API LruCache
            {
            private :
                typedef typename std::list<std::pair<Key, T>>::iterator EntriesListIt;
            public :
                LruCache(const std::size_t limit) NOTHROWS;
                ~LruCache() NOTHROWS = default;
            public :
                Util::TAKErr get(T *value, const Key &key) NOTHROWS;
                Util::TAKErr insert(const Key &key, T &&value) NOTHROWS;
                Util::TAKErr insert(const Key &key, const T &value) NOTHROWS;
                Util::TAKErr erase(const Key &key);
            private :
                std::size_t limit;
                struct {
                    std::unordered_map<Key, EntriesListIt, Hash, KeyEqual> m;
                    std::list<std::pair<Key, T>> l;
                } entries;
                Cost cost;
                std::size_t size;
            };

            template<typename Key, typename T, class Hash, class KeyEqual, class Cost>
            LruCache<Key, T, Hash, KeyEqual, Cost>::LruCache(const std::size_t limit_) NOTHROWS :
                limit(limit_),
                size(0u)
            {}
            
            template<typename Key, typename T, class Hash, class KeyEqual, class Cost>
            Util::TAKErr LruCache<Key, T, Hash, KeyEqual, Cost>::get(T *value, const Key &key) NOTHROWS
            {
                const auto &entry = entries.m.find(key);
                if(entry == entries.m.end())
                    return Util::TE_BadIndex;
                *value = (*entry->second).second;
                // move element to front of LRU list
                if (entry->second != entries.l.begin()) {
                    entries.l.splice(entries.l.begin(), entries.l, entry->second);
                }
                return TE_Ok;
            }
            template<typename Key, typename T, class Hash, class KeyEqual, class Cost>
            Util::TAKErr LruCache<Key, T, Hash, KeyEqual, Cost>::insert(const Key &key, T &&value) NOTHROWS
            {
                erase(key);
                const auto c = cost(value);
                std::size_t evicted = 0u;
                while((size+c) > limit) {
                    const auto &evict = entries.l.back();
                    size -= cost(evict.second);
                    evicted += cost(evict.second);
                    entries.m.erase(evict.first);
                    entries.l.pop_back();
                }
                entries.l.emplace_front(key, value);
                entries.m[key] = entries.l.begin();
                size += c;
                return TE_Ok;
            }
            template<typename Key, typename T, class Hash, class KeyEqual, class Cost>
            Util::TAKErr LruCache<Key, T, Hash, KeyEqual, Cost>::insert(const Key &key, const T &value) NOTHROWS
            {
                erase(key);
                const auto c = cost(value);
                std::size_t evicted = 0u;
                while((size+c) > limit) {
                    const auto &evict = entries.l.back();
                    size -= cost(evict.second);
                    evicted += cost(evict.second);
                    entries.m.erase(evict.first);
                    entries.l.pop_back();
                }
                entries.l.emplace_front(key, value);
                entries.m[key] = entries.l.begin();
                size += c;
                return TE_Ok;
            }
            template<typename Key, typename T, class Hash, class KeyEqual, class Cost>
            Util::TAKErr LruCache<Key, T, Hash, KeyEqual, Cost>::erase(const Key &key)
            {
                const auto &entry = entries.m.find(key);
                if(entry == entries.m.end())
                    return Util::TE_BadIndex;

                size -= cost((*entry->second).second);
                entries.l.erase(entry->second);
                entries.m.erase(entry);
                return TE_Ok;
            }
        }
    }
}
#endif
