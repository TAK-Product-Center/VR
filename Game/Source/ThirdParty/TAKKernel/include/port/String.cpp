

#include "port/String.h"

#include <new>
#include <cstdlib>
#include <cstring>
#include <map>
#include <memory>
#include <sstream>

#include "thread/Lock.h"
#include "thread/Mutex.h"
#include "util/Memory.h"

using namespace TAK::Engine::Port;

using namespace TAK::Engine::Thread;
using namespace TAK::Engine::Util;

namespace
{
    struct {
        std::map<const char*, std::unique_ptr<char, void(*)(const char *)>, StringLess> values;
        Mutex mutex;
    } interned;
}

String::String() NOTHROWS :
    String(nullptr, 0)
{ }

String::String(const char* s) NOTHROWS :
    String(s, !!s ? strlen(s) : 0u)
{ }

String::String(const char* s, std::size_t len) NOTHROWS
{
    data.shared = false;
    if(!s) {
        data.heapAlloc = true;
        data.heap.reset();
        data.stack[0] = '\0';
    } else {
        if(len < stackStorageSize-1u) {
            data.heapAlloc = false;
        } else {
            data.heap = std::unique_ptr<char, void(*)(const char *)>(new char[len + 1u], Memory_array_deleter_const<char>);
            data.heapAlloc = true;
        }
        char* value = data.heapAlloc ? data.heap.get() : data.stack;
        if (len)
            memcpy(value, s, len);
        value[len] = '\0';
    }
}

String::String(const String& rhs) NOTHROWS
{
    *this = rhs;
}

String::String(String&& rhs) NOTHROWS
{
    *this = rhs;
}

String::~String() NOTHROWS
{}


String& String::operator= (const String& rhs) NOTHROWS
{
    if(rhs.data.shared) {
        // if shared, reference shared data
        this->data.heap = std::unique_ptr<char, void(*)(const char *)>(rhs.data.heap.get(), Memory_leaker_const<char>);
        this->data.shared = true;
        this->data.heapAlloc = true;
    } else {
        // create copy
        *this = rhs.get();
    }
    return *this;
}

String& String::operator= (String&& rhs) NOTHROWS
{
    if(rhs.data.shared) {
        // if shared, reference shared data
        this->data.heap = std::unique_ptr<char, void(*)(const char *)>(rhs.data.heap.get(), Memory_leaker_const<char>);
        this->data.shared = true;
        this->data.heapAlloc = true;
    } else if (rhs.data.heapAlloc) {
        this->data.heap = std::move(rhs.data.heap);
        this->data.heapAlloc = true;
        this->data.shared = false;
    } else {
        // create copy
        *this = (const char *)rhs;
    }
    return *this;
}

String& String::operator= (const char* rhs) NOTHROWS
{
    if (((const char *)(*this)) != rhs)
    {
        // no longer shared
        data.shared = false;
        if(!rhs) {
            data.heapAlloc = true;
            data.heap.reset();
            data.stack[0] = '\0';
        } else {
            const std::size_t len = strlen(rhs);
            if(len < stackStorageSize-1u) {
                data.heapAlloc = false;
            } else {
                data.heap = std::unique_ptr<char, void(*)(const char *)>(new char[len + 1u], Memory_array_deleter_const<char>);
                data.heapAlloc = true;
            }    
            char* value = data.heapAlloc ? data.heap.get() : data.stack;
            if (len)
                memcpy(value, rhs, len);
            value[len] = '\0';
        }
    }

    return *this;
}

bool String::operator== (const String& rhs) const NOTHROWS
{
    return (*this) == (const char *)rhs;
}

bool String::operator!= (const String& rhs) const NOTHROWS
{
    return !(*this == rhs);
}

bool String::operator== (const char *rhs) const NOTHROWS
{
    return !!((const char *)(*this))
        ? rhs && !std::strcmp(((const char *)(*this)), rhs) :
        !rhs;
}

bool String::operator!= (const char *rhs) const NOTHROWS
{
    return !(*this == rhs);
}

String::operator const char* () const NOTHROWS
{
    return get();
}

char& String::operator[] (int index) NOTHROWS
{
    if (data.shared) {
        // data is shared, create a copy before allowing modification
        const char* value = ((const char *)(*this));
        *this = value;
    }
    return get()[index];
}

char String::operator[] (int index) const NOTHROWS
{
    return get()[index];
}

char* String::get() NOTHROWS
{
    if (data.shared) {
        // data is shared, create a copy before allowing modification
        const auto& cthis = *this;
        const char* value = cthis.get();
        *this = value;
    }
    return data.heapAlloc ? data.heap.get() : data.stack;
}

const char *String::get() const NOTHROWS
{
    return data.heapAlloc ? data.heap.get() : data.stack;
}

TAKErr TAK::Engine::Port::String_parseDouble(double *value, const char *str) NOTHROWS
{
    char *end;
    const double result = std::strtod(str, &end);

    if(!result && end == str)
        return TE_InvalidArg;
    *value = result;
    return TE_Ok;
}
TAKErr TAK::Engine::Port::String_parseInteger(int *value, const char *str, const int base) NOTHROWS
{
    char *end;
    const auto result = std::strtoul(str, &end, base);

    if(!result && end == str)
        return TE_InvalidArg;
    *value = (int)result;
    return TE_Ok;
}

char* TAK::Engine::Port::String_strcasestr(const char* lhs, const char* rhs) NOTHROWS
{
    const char* p1 = lhs;
    const char* p2 = rhs;
    const char* r = *p2 == 0 ? lhs : 0;

    while (*p1 != 0 && *p2 != 0)
    {
        if (tolower((unsigned char)*p1) == tolower((unsigned char)*p2))
        {
            if (r == 0)
            {
                r = p1;
            }

            p2++;
        }
        else
        {
            p2 = rhs;
            if (r != 0)
            {
                p1 = r + 1;
            }

            if (tolower((unsigned char)*p1) == tolower((unsigned char)*p2))
            {
                r = p1;
                p2++;
            }
            else
            {
                r = 0;
            }
        }

        p1++;
    }

    return *p2 == 0 ? (char*)r : 0;
}


TAKErr TAK::Engine::Port::String_compareIgnoreCase(int *result, const char *lhs, const char *rhs) NOTHROWS
{
    if (!lhs || !rhs || !result)
        return TE_InvalidArg;

#if _WIN32
    *result = _strcmpi(lhs, rhs);
#else
    *result = strcasecmp(lhs, rhs);
#endif
    return TE_Ok;
}

int TAK::Engine::Port::String_strcasecmp(const char *lhs, const char *rhs) NOTHROWS
{
    if(!lhs && !rhs)
        return 0;
    else if(!lhs)
        return 1;
    else if(!rhs)
        return -1;

#if _WIN32
    return _strcmpi(lhs, rhs);
#else
    return strcasecmp(lhs, rhs);
#endif
}

int TAK::Engine::Port::String_strcmp(const char *lhs, const char *rhs) NOTHROWS
{
    if(!lhs && !rhs)
        return 0;
    else if(!lhs)
        return 1;
    else if(!rhs)
        return -1;

    return strcmp(lhs, rhs);
}

bool TAK::Engine::Port::String_less(const char *a, const char *b) NOTHROWS
{
    if(!a && !b)
        return false;
    else if(!a)
        return false;
    else if(!b)
        return true;
    else
        return strcmp(a, b)<0;
}
bool TAK::Engine::Port::String_equal(const char *a, const char *b) NOTHROWS
{
    if(!a && !b)
        return true;
    else if(!a)
        return false;
    else if(!b)
        return true;
    else
        return strcmp(a, b)==0;
}
bool TAK::Engine::Port::String_endsWith(const char *str, const char *suffix) NOTHROWS
{
    if (!str && !suffix)
        return true;
    else if (!str || !suffix)
        return false;
    const std::size_t srclen = strlen(str);
    const std::size_t suffixlen = strlen(suffix);
    if (srclen < suffixlen)
        return false;
    for (std::size_t i = suffixlen; i > 0; i--) {
        if (str[(srclen-suffixlen)+i-1u] != suffix[i-1u])
            return false;
    }
    return true;

}
bool TAK::Engine::Port::String_trim(TAK::Engine::Port::String &value, const char *str) NOTHROWS
{
    if (!str)
        return false;
    const std::size_t srclen = strlen(str);
    std::ostringstream strm;
    for (std::size_t i = 0; i < srclen; i++)
        if (!isspace(str[i]))
            strm << str[i];
    if (strm.str().empty())
        return false;
    value = strm.str().c_str();
    return true;
}
TAK::Engine::Port::String TAK::Engine::Port::String_intern(const char *cstr) NOTHROWS
{
    String value;
    if (cstr) {
        Lock lock(interned.mutex);
        auto entry = interned.values.find(cstr);
        if (entry != interned.values.end()) {
            value.data.heap = std::unique_ptr<char, void(*)(const char *)>(const_cast<char *>(entry->first), Memory_leaker_const<char>);
            value.data.heapAlloc = true;
        } else {
            std::size_t len = strlen(cstr);
            std::unique_ptr<char, void(*)(const char*)> str(new char[len + 1u], Memory_array_deleter_const<char>);
            memcpy(str.get(), cstr, len);
            str.get()[len] = '\0';
            value.data.heap = std::unique_ptr<char, void(*)(const char *)>(const_cast<char *>(str.get()), Memory_leaker_const<char>);
            interned.values.insert(std::make_pair(str.get(), std::move(str)));

        }
        value.data.heapAlloc = true;
        value.data.shared = true;
    }
    return value;
}
TAK::Engine::Port::String TAK::Engine::Port::String_intern(const String &value) NOTHROWS
{
    if(value.data.shared) {
        return String(value);
    } else {
        return String_intern(value.get());
    }
}
