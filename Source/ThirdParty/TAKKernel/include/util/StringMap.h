#ifndef TAK_ENGINE_UTIL_STRINGMAP_H_INCLUDED
#define TAK_ENGINE_UTIL_STRINGMAP_H_INCLUDED

#include <map>

#include "port/Platform.h"
#include "port/String.h"
#include "util/Memory.h"
#include "util/StringSet.h"

namespace TAK {
    namespace Engine {
        namespace Util {
            template<class ValueType, class Comp = Port::StringLess>
            class StringMap
            {
            private :
                typedef typename std::map<const char*, ValueType, Comp>::iterator _Iter;
                typedef typename std::map<const char*, ValueType, Comp>::const_iterator _ConstIter;
            public :
                StringMap() NOTHROWS;
                StringMap(const StringMap& other) NOTHROWS;
                StringMap(StringMap&& other) NOTHROWS;
            public :
                _Iter find(const char* key) NOTHROWS;
                _ConstIter find(const char* key) const NOTHROWS;
                _Iter begin() NOTHROWS;
                _ConstIter begin() const NOTHROWS;
                _Iter end() NOTHROWS;
                _ConstIter end() const NOTHROWS;
                void insert(const char* key, const ValueType& value) NOTHROWS;
                void insert(const char* key, ValueType&& value) NOTHROWS;
                void erase(const char* key);
                _Iter erase(_Iter& it) NOTHROWS;
                _ConstIter erase(_ConstIter& it) NOTHROWS;
                void clear(const bool resetIntern = false) NOTHROWS;
                std::size_t size() const NOTHROWS;
                bool empty() const NOTHROWS;
                ValueType& operator[](const char* key);
            public :
                StringMap<ValueType, Comp>& operator=(const StringMap<ValueType, Comp>& other) NOTHROWS;
            private :
                struct {
                    std::map<const char*, ValueType, Comp> values;
                    StringSet<Comp> keys;
                } data;
            };

            template<class ValueType, class Comp>
            inline StringMap<ValueType, Comp>::StringMap() NOTHROWS
            {}
            template<class ValueType, class Comp>
            inline StringMap<ValueType, Comp>::StringMap(const StringMap& other) NOTHROWS
            {
                *this = other;
            }
            template<class ValueType, class Comp>
            inline StringMap<ValueType, Comp>::StringMap(StringMap&& other) NOTHROWS
            {
                data.values = std::move(other.data.values);
                data.keys = std::move(other.data.keys);
            }

            template<class ValueType, class Comp>
            inline typename StringMap<ValueType, Comp>::_Iter StringMap<ValueType, Comp>::find(const char* key) NOTHROWS
            {
                return data.values.find(key);
            }
            template<class ValueType, class Comp>
            inline typename StringMap<ValueType, Comp>::_ConstIter StringMap<ValueType, Comp>::find(const char* key) const NOTHROWS
            {
                return data.values.find(key);
            }
            template<class ValueType, class Comp>
            inline typename StringMap<ValueType, Comp>::_Iter StringMap<ValueType, Comp>::begin() NOTHROWS
            {
                return data.values.begin();
            }
            template<class ValueType, class Comp>
            inline typename StringMap<ValueType, Comp>::_ConstIter StringMap<ValueType, Comp>::begin() const NOTHROWS
            {
                return data.values.begin();
            }
            template<class ValueType, class Comp>
            inline typename StringMap<ValueType, Comp>::_Iter StringMap<ValueType, Comp>::end() NOTHROWS
            {
                return data.values.end();
            }
            template<class ValueType, class Comp>
            inline typename StringMap<ValueType, Comp>::_ConstIter StringMap<ValueType, Comp>::end() const NOTHROWS
            {
                return data.values.end();
            }
            template<class ValueType, class Comp>
            void StringMap<ValueType, Comp>::insert(const char *key, const ValueType &value) NOTHROWS
            {
                auto inserted = data.keys.insert(key);
                key = *inserted.first;
                data.values.insert(std::make_pair(key, value));
            }
            template<class ValueType, class Comp>
            void StringMap<ValueType, Comp>::insert(const char *key, ValueType &&value) NOTHROWS
            {
                auto inserted = data.keys.insert(key);
                key = *inserted.first;
                data.values.insert(std::make_pair(key, value));
            }
            template<class ValueType, class Comp>
            void StringMap<ValueType, Comp>::erase(const char *key)
            {
                auto& entry = data.values.find(key);
                if(entry != data.values.end()) {
                    data.values.erase(entry);
                    data.keys.erase(entry.first);
                }
            }
            template<class ValueType, class Comp>
            inline typename StringMap<ValueType, Comp>::_Iter StringMap<ValueType, Comp>::erase(_Iter &it) NOTHROWS
            {
                const char* key = it->first;
                auto result = data.values.erase(it);
                data.keys.erase(key);
                return result;
            }
            template<class ValueType, class Comp>
            inline typename StringMap<ValueType, Comp>::_ConstIter StringMap<ValueType, Comp>::erase(_ConstIter &it) NOTHROWS
            {
                const char* key = it->first;
                auto result = data.values.erase(it);
                data.keys.erase(key);
                return result;
            }
            template<class ValueType, class Comp>
            void StringMap<ValueType, Comp>::clear(const bool resetIntern) NOTHROWS
            {
                data.values.clear();
                if (resetIntern)
                    data.keys.clear();
            }
            template<class ValueType, class Comp>
            std::size_t StringMap<ValueType, Comp>::size() const NOTHROWS
            {
                return data.values.size();
            }
            template<class ValueType, class Comp>
            bool StringMap<ValueType, Comp>::empty() const NOTHROWS
            {
                return data.values.empty();
            }
            template<class ValueType, class Comp>
            inline ValueType &StringMap<ValueType, Comp>::operator [](const char *key)
            {
                auto dkey = data.keys.find(key);
                if(dkey == data.keys.end())
                {
                    auto inserted = data.keys.insert(key);
                    key = *inserted.first;
                } else {
                    key = *dkey;
                }
                return data.values[key];
            }
            template<class ValueType, class Comp>
            inline StringMap<ValueType, Comp>& StringMap<ValueType, Comp>::operator=(const StringMap<ValueType, Comp>& other) NOTHROWS
            {
                clear();
                for (auto it = other.begin(); it != other.end(); it++)
                    insert(it->first, it->second);
                return *this;
            }
        }
    }
}

#endif
