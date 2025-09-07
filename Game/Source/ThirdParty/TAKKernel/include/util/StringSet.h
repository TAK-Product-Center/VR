#ifndef TAK_ENGINE_UTIL_STRINGSET_H_INCLUDED
#define TAK_ENGINE_UTIL_STRINGSET_H_INCLUDED

#include <map>
#include <set>

#include "util/Memory.h"
#include "port/Platform.h"
#include "port/String.h"

namespace TAK {
    namespace Engine {
        namespace Util {
            template<class Comp = Port::StringLess>
            class StringSet
            {
            public :
                class iterator;
                class const_iterator;
            private :
                typedef typename std::map<const char*, std::unique_ptr<char, void(*)(const char*)>, Comp>::iterator _Iter;
                typedef typename std::map<const char*, std::unique_ptr<char, void(*)(const char*)>, Comp>::const_iterator _ConstIter;
            public :
                StringSet() NOTHROWS;
                StringSet(const StringSet& other) NOTHROWS;
                StringSet(StringSet&& other) NOTHROWS;
            public :
#ifdef _MSC_VER
#define ITERDECL typename
#else
#define ITERDECL
#endif
                ITERDECL iterator find(const char* key) NOTHROWS;
                ITERDECL const_iterator find(const char* key) const NOTHROWS;
                ITERDECL iterator begin() NOTHROWS;
                ITERDECL const_iterator begin() const NOTHROWS;
                ITERDECL iterator end() NOTHROWS;
                ITERDECL const_iterator end() const NOTHROWS;
                std::pair<ITERDECL iterator, bool> insert(const char* value) NOTHROWS;
                void erase(const char* value);
                ITERDECL iterator erase(ITERDECL iterator& it) NOTHROWS;
                ITERDECL const_iterator erase(ITERDECL const_iterator& it) NOTHROWS;
                void clear() NOTHROWS;
                bool empty() const NOTHROWS;
            public :
                StringSet<Comp>& operator=(const StringSet<Comp>& other) NOTHROWS;
            private :
                std::map<const char*, std::unique_ptr<char, void(*)(const char*)>, Comp> values;
            };

            template<class Comp>
            class StringSet<Comp>::iterator
            {
            private :
                iterator(StringSet<Comp>::_Iter iter_) :
                    iter(iter_)
                {}
            public :
                const char *operator *() NOTHROWS
                {
                    return iter->first;
                }
                bool operator ==(const iterator &other) const NOTHROWS
                {
                    return iter == other.iter;
                }
                bool operator !=(const iterator &other) const NOTHROWS
                {
                    return iter != other.iter;
                }
                iterator &operator ++() NOTHROWS
                {
                    iter++;
                    return *this;
                }
                iterator operator ++(int) NOTHROWS
                {
                    iterator result = *this;
                    iter++;
                    return result;
                }
            private :
                StringSet<Comp>::_Iter iter;
                friend class StringSet<Comp>;
            };

            template<class Comp>
            class StringSet<Comp>::const_iterator
            {
            private :
                const_iterator(StringSet<Comp>::_ConstIter iter_) :
                    iter(iter_)
                {}
            public :
                const char *operator *() NOTHROWS
                {
                    return iter->first;
                }
                bool operator ==(const const_iterator &other) const NOTHROWS
                {
                    return iter == other.iter;
                }
                bool operator !=(const const_iterator &other) const NOTHROWS
                {
                    return iter != other.iter;
                }
                const_iterator &operator ++() NOTHROWS
                {
                    iter++;
                    return *this;
                }
                const_iterator operator ++(int) NOTHROWS
                {
                    const_iterator result = *this;
                    iter++;
                    return result;
                }
            private :
                StringSet<Comp>::_ConstIter iter;
                friend class StringSet<Comp>;
            };

            template<class Comp>
            inline StringSet<Comp>::StringSet() NOTHROWS
            {}
            template<class Comp>
            inline StringSet<Comp>::StringSet(const StringSet& other) NOTHROWS
            {
                *this = other;
            }
            template<class Comp>
            inline StringSet<Comp>::StringSet(StringSet&& other) NOTHROWS
            {
                values = std::move(other.values);
            }

            template<class Comp>
            inline typename StringSet<Comp>::iterator StringSet<Comp>::find(const char* key) NOTHROWS
            {
                return iterator(values.find(key));
            }
            template<class Comp>
            inline typename StringSet<Comp>::const_iterator StringSet<Comp>::find(const char* key) const NOTHROWS
            {
                return const_iterator(values.find(key));
            }
            template<class Comp>
            inline typename StringSet<Comp>::iterator StringSet<Comp>::begin() NOTHROWS
            {
                return iterator(values.begin());
            }
            template<class Comp>
            inline typename StringSet<Comp>::const_iterator StringSet<Comp>::begin() const NOTHROWS
            {
                return const_iterator(values.begin());
            }
            template<class Comp>
            inline typename StringSet<Comp>::iterator StringSet<Comp>::end() NOTHROWS
            {
                return iterator(values.end());
            }
            template<class Comp>
            inline typename StringSet<Comp>::const_iterator StringSet<Comp>::end() const NOTHROWS
            {
                return const_iterator(values.end());
            }
            template<class Comp>
            std::pair<typename StringSet<Comp>::iterator, bool> StringSet<Comp>::insert(const char *value) NOTHROWS
            {
                auto dkey = values.find(value);
                if(dkey == values.end())
                {
                    const auto keyLen = strlen(value);
                    std::unique_ptr<char, void(*)(const char*)> pkey(new char[keyLen + 1u], Memory_array_deleter_const<char>);
                    memcpy(pkey.get(), value, keyLen);
                    pkey.get()[keyLen] = '\0';
                    value = pkey.get();
                    auto inserted = values.insert(std::make_pair(value, std::move(pkey)));
                    return std::make_pair(iterator(inserted.first), inserted.second);
                } else {
                    return std::make_pair(iterator(dkey), false);
                }
            }
            template<class Comp>
            void StringSet<Comp>::erase(const char *key)
            {
                auto entry = values.find(key);
                if(entry != values.end()) {
                    values.erase(entry);
                }
            }
            template<class Comp>
            inline typename StringSet<Comp>::iterator StringSet<Comp>::erase(iterator &it) NOTHROWS
            {
                return iterator(values.erase(it.iter));
            }
            template<class Comp>
            inline typename StringSet<Comp>::const_iterator StringSet<Comp>::erase(const_iterator &it) NOTHROWS
            {
                return const_iterator(values.erase(it.iter));
            }
            template<class Comp>
            void StringSet<Comp>::clear() NOTHROWS
            {
                values.clear();
            }
            template<class Comp>
            bool StringSet<Comp>::empty() const NOTHROWS
            {
                return values.empty();
            }
            template<class Comp>
            inline StringSet<Comp>& StringSet<Comp>::operator=(const StringSet<Comp>& other) NOTHROWS
            {
                clear();
                for (auto it = other.begin(); it != other.end(); it++)
                    insert(*it);
                return *this;
            }
        }
    }
}

#endif
