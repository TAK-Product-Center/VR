#include "util/AttributeSet.h"

#include "util/Logging2.h"

using namespace atakmap::util;

using namespace TAK::Engine::Util;

#define MEM_FN( fn )    "atakmap::util::AttributeSet::" fn ": "

namespace
{
    template<class T>
    std::pair<const T *, const T *> asArray(const bool null, const std::vector<uint8_t> &object) NOTHROWS
    {
        if (null)
            return std::pair<const T*, const T*>(nullptr, nullptr);

        const auto arr = reinterpret_cast<const T*>(object.data());
        return std::pair<const T*, const T*>(arr, arr+object.size()/sizeof(T));
    }

    template<class T>
    bool setArray(std::vector<uint8_t> &object, const std::pair<const T *, const T *> &arr) NOTHROWS
    {
        if (!arr.first)
            return true;
        const std::size_t nelems = arr.second - arr.first;
        const std::size_t size = nelems * sizeof(T);
        object.resize(size);
        memcpy(reinterpret_cast<T*>(object.data()), arr.first, size);
        return false;
    }
}


AttributeSet::~AttributeSet()
NOTHROWS
{ }

void
AttributeSet::clear()
{
    attrItems.clear();
}


std::vector<const char*>
AttributeSet::getAttributeNames()
const
NOTHROWS
{
    std::vector<const char*> result;
    result.reserve(attrItems.size());
    auto iter = attrItems.begin();
    while (iter != attrItems.end()) {
#if ATTRSET_CSTRING_KEY
        result.push_back(iter->first);
#else
        result.push_back(iter->first.c_str());
#endif
        ++iter;
    }

    return result;
}


void
AttributeSet::throwNotFound(const char* attributeName,
    const char* attributeType,
    const char* errHeader)
    const
{
    std::ostringstream strm;

    strm << errHeader << attributeName;
    if (containsAttribute(attributeName))
    {
        strm << " not of type " << attributeType;
    }
    else
    {
        strm << " not found";
    }

    throw std::invalid_argument(strm.str().c_str());
}


const AttributeSet&
AttributeSet::getAttributeSet(const char* attrName)
const
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("getAttributeSet")
            "Received NULL attributeName");
    }

    auto iter = attrItems.find(attrName);

    if (iter == attrItems.end() || iter->second.type != ATTRIBUTE_SET)
    {
        throwNotFound(attrName, "ATTRIBUTE_SET", MEM_FN("getAttributeSet"));
    }

    return *iter->second.nested;
}

void
AttributeSet::getAttributeSet(std::shared_ptr<AttributeSet> &value, const char* attrName)
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("getAttributeSet")
            "Received NULL attributeName");
    }

    auto iter = attrItems.find(attrName);

    if (iter == attrItems.end() || iter->second.type != ATTRIBUTE_SET)
    {
        throwNotFound(attrName, "ATTRIBUTE_SET", MEM_FN("getAttributeSet"));
    }

    value = iter->second.nested;
}

AttributeSet::Type
AttributeSet::getAttributeType(const char* attrName)
const
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("getAttributeType")
            "Received NULL attributeName");
    }

    auto iter = attrItems.find(attrName);

    if (iter == attrItems.end())
    {
        std::ostringstream msg;
        msg << MEM_FN("getAttributeType") <<
            "Attribute not found: " <<
            attrName;
        throw std::invalid_argument(msg.str());
    }

    return iter->second.type;
}


AttributeSet::Blob
AttributeSet::getBlob(const char* attrName)
const
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("getBlob")
            "Received NULL attributeName");
    }

    auto iter = attrItems.find(attrName);

    if (iter == attrItems.end() || iter->second.type != BLOB)
    {
        throwNotFound(attrName, "BLOB", MEM_FN("getBlob"));
    }

    const auto &value = iter->second;
    return asArray<unsigned char>(value.null, value.object);
}


std::pair<const AttributeSet::Blob*, const AttributeSet::Blob*>
AttributeSet::getBlobArray(const char* attrName)
const
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("getBlobArray")
            "Received NULL attributeName");
    }

    auto iter = attrItems.find(attrName);

    if (iter == attrItems.end() || iter->second.type != BLOB_ARRAY)
    {
        throwNotFound(attrName, "BLOB_ARRAY", MEM_FN("getBlobArray"));
    }

    const auto &value = iter->second;
    return asArray<AttributeSet::Blob>(value.null, value.object);
}



double
AttributeSet::getDouble(const char* attrName)
const
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("getDouble")
            "Received NULL attributeName");
    }

    auto iter = attrItems.find(attrName);

    if (iter == attrItems.end() || iter->second.type != DOUBLE)
    {
        throwNotFound(attrName, "DOUBLE", MEM_FN("getDouble"));
    }

    return iter->second.primitive.d;
}



std::pair<const double*, const double*>
AttributeSet::getDoubleArray(const char* attrName)
const
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("getDoubleArray")
            "Received NULL attributeName");
    }

    auto iter = attrItems.find(attrName);

    if (iter == attrItems.end() || iter->second.type != DOUBLE_ARRAY)
    {
        throwNotFound(attrName, "DOUBLE_ARRAY", MEM_FN("getDoubleArray"));
    }

    const auto &value = iter->second;
    return asArray<double>(value.null, value.object);
}



int
AttributeSet::getInt(const char* attrName)
const
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("getInt")
            "Received NULL attributeName");
    }

    auto iter = attrItems.find(attrName);

    if (iter == attrItems.end() || iter->second.type != INT)
    {
        throwNotFound(attrName, "INT", MEM_FN("getInt"));
    }

    return iter->second.primitive.i;
}



std::pair<const int*, const int*>
AttributeSet::getIntArray(const char* attrName)
const
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("getIntArray")
            "Received NULL attributeName");
    }

    auto iter = attrItems.find(attrName);

    if (iter == attrItems.end() || iter->second.type != INT_ARRAY)
    {
        throwNotFound(attrName, "INT_ARRAY", MEM_FN("getIntArray"));
    }

    const auto &value = iter->second;
    return asArray<int>(value.null, value.object);
}



int64_t
AttributeSet::getLong(const char* attrName)
const
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("getLong")
            "Received NULL attributeName");
    }

    auto iter = attrItems.find(attrName);

    if (iter == attrItems.end() || iter->second.type != LONG)
    {
        throwNotFound(attrName, "LONG", MEM_FN("getLong"));
    }

    return iter->second.primitive.l;
}



std::pair<const int64_t*, const int64_t*>
AttributeSet::getLongArray(const char* attrName)
const
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("getLongArray")
            "Received NULL attributeName");
    }

    auto iter = attrItems.find(attrName);

    if (iter == attrItems.end() || iter->second.type != LONG_ARRAY)
    {
        throwNotFound(attrName, "LONG_ARRAY", MEM_FN("getLongArray"));
    }

    const auto &value = iter->second;
    return asArray<int64_t>(value.null, value.object);
}



const char*
AttributeSet::getString(const char* attrName)
const
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("getString")
            "Received NULL attributeName");
    }

    auto iter = attrItems.find(attrName);

    if (iter == attrItems.end() || iter->second.type != STRING)
    {
        throwNotFound(attrName, "STRING", MEM_FN("getString"));
    }

    const auto &value = iter->second;
    if (value.null)
        return nullptr;
    else
        return reinterpret_cast<const char*>(value.object.data());
}



std::pair<const char* const*, const char* const*>
AttributeSet::getStringArray(const char* attrName)
const
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("getStringArray")
            "Received NULL attributeName");
    }

    auto iter = attrItems.find(attrName);

    if (iter == attrItems.end() || iter->second.type != STRING_ARRAY)
    {
        throwNotFound(attrName, "STRING_ARRAY", MEM_FN("getStringArray"));
    }

    const auto &value = iter->second;
    return asArray<char* const>(value.null, value.object);
}



void
AttributeSet::removeAttribute(const char* attrName)
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("removeAttribute")
            "Received NULL attributeName");
    }

    auto attrIter = attrItems.find(attrName);
    if (attrIter != attrItems.end()) {
        attrItems.erase(attrIter);
    }
}



void
AttributeSet::setAttributeSet(const char* attrName,
    const AttributeSet& value_)
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("setAttributeSet")
            "Received NULL attributeName");
    }

    AttrItem_ &value = attrItems[attrName];
    value.type = ATTRIBUTE_SET;
    value.nested.reset(new AttributeSet(value_));
}



void
AttributeSet::setBlob(const char* attrName,
    const Blob& value_)
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("setBlob")
            "Received NULL attributeName");
    }

    AttrItem_ &value = attrItems[attrName];
    value.reset(BLOB);
    value.null = setArray<unsigned char>(value.object, value_);
}



void
AttributeSet::setBlobArray(const char* attrName,
    const std::pair<const Blob*, const Blob*>& value_)
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("setBlobArray")
            "Received NULL attributeName");
    }
    AttrItem_ &value = attrItems[attrName];
    value.reset(BLOB_ARRAY);
    if(value_.first) {
        value.null = false;
        value.barray.ref.reserve(value_.second-value_.first);
        value.barray.raw.reserve(value_.second-value_.first);
        for(auto it = value_.first; it != value_.second; it++) {
            const Blob &blob = *it;
            if(blob.first) {
                value.barray.ref.push_back(std::vector<uint8_t>(blob.second-blob.first));
                auto &blobr = value.barray.ref.back();
                memcpy(blobr.data(), blob.first, blobr.size());
                value.barray.raw.push_back(Blob(blobr.data(), blobr.data()+blobr.size()));
            } else {
                value.barray.ref.push_back(std::vector<uint8_t>());
                value.barray.raw.push_back(Blob());
            }
        }
        setArray<Blob>(value.object, std::make_pair(value.barray.raw.data(), value.barray.raw.data()+value.barray.raw.size()));
    }
}



void
AttributeSet::setDouble(const char* attrName,
    double value_)
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("setDouble")
            "Received NULL attributeName");
    }

    AttrItem_ &value = attrItems[attrName];
    value.reset(DOUBLE);
    value.primitive.d = value_;
}



void
AttributeSet::setDoubleArray(const char* attrName,
    const std::pair<const double*, const double*>& value_)
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("setDoubleArray")
            "Received NULL attributeName");
    }

    AttrItem_ &value = attrItems[attrName];
    value.reset(DOUBLE_ARRAY);
    value.null = setArray<double>(value.object, value_);
}



void
AttributeSet::setInt(const char* attrName,
    int value_)
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("setInt")
            "Received NULL attributeName");
    }

    AttrItem_ &value = attrItems[attrName];
    value.reset(INT);
    value.primitive.i = value_;
}



void
AttributeSet::setIntArray(const char* attrName,
    const std::pair<const int*, const int*>& value_)
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("setIntArray")
            "Received NULL attributeName");
    }
    AttrItem_ &value = attrItems[attrName];
    value.reset(INT_ARRAY);
    value.null = setArray<int>(value.object, value_);
}



void
AttributeSet::setLong(const char* attrName,
    int64_t value_)
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("setLong")
            "Received NULL attributeName");
    }

    AttrItem_ &value = attrItems[attrName];
    value.reset(LONG);
    value.primitive.l = value_;
}



void
AttributeSet::setLongArray(const char* attrName,
    const std::pair<const int64_t*, const int64_t*>& value_)
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("setLongArray")
            "Received NULL attributeName");
    }
    AttrItem_ &value = attrItems[attrName];
    value.reset(LONG_ARRAY);
    value.null = setArray<int64_t>(value.object, value_);
}



void
AttributeSet::setString(const char* attrName,
    const char* value_)
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("setString")
            "Received NULL attributeName");
    }

    AttrItem_ &value = attrItems[attrName];
    value.reset(STRING);
    if(value_) {
        const auto len = strlen(value_)+1;
        setArray<char>(value.object, std::pair<const char*, const char*>(value_, value_ + len));
        value.null = false;
    }
}



void
AttributeSet::setStringArray(const char* attrName,
    const std::pair<const char* const*, const char* const*>& value_)
{
    if (!attrName)
    {
        throw std::invalid_argument(MEM_FN("setStringArray")
            "Received NULL attributeName");
    }
    AttrItem_ &value = attrItems[attrName];
    value.reset(STRING_ARRAY);
    if(value_.first) {
        value.null = false;
        value.sarray.ref.reserve(value_.second-value_.first);
        value.sarray.raw.reserve(value_.second-value_.first);
        for(auto it = value_.first; it != value_.second; it++) {
            const char *cstr = *it;
            if(cstr) {
                value.sarray.ref.push_back(std::string(cstr));
                value.sarray.raw.push_back(value.sarray.ref.back().c_str());
            } else {
                value.sarray.ref.push_back(std::string());
                value.sarray.raw.push_back(nullptr);
            }
        }
        setArray<const char *>(value.object, std::make_pair(value.sarray.raw.data(), value.sarray.raw.data()+value.sarray.raw.size()));
    }
}

//==================================
//  PRIVATE IMPLEMENTATION
//==================================


bool
AttributeSet::invalidBlob(const Blob& blob)
{
    return !blob.first || !blob.second;
}

bool
AttributeSet::isNULL(const void* ptr)
{
    return !ptr;
}

AttributeSet::AttrItem_::AttrItem_(const AttributeSet::AttrItem_ &other)
{
    *this = other;
    // 2D arrays need to have references rebuilt as we've copied the backing store
    if (type == STRING_ARRAY) {
        auto refi = sarray.ref.begin();
        auto rawi = sarray.raw.begin();
        while(refi != sarray.ref.end()) {
            if(*rawi != nullptr) {
                *rawi = refi->c_str();
            }
            refi++;
            rawi++;
        }
        setArray<const char *>(object, std::make_pair(sarray.raw.data(), sarray.raw.data()+sarray.raw.size()));
    } else if(type == BLOB_ARRAY) {
        auto refi = barray.ref.begin();
        auto rawi = barray.raw.begin();
        while(refi != barray.ref.end()) {
            if((*rawi).first != nullptr) {
                const auto &blob = *refi;
                *rawi = Blob(blob.data(), blob.data()+blob.size());
            }
            refi++;
            rawi++;
        }
        setArray<Blob>(object, std::make_pair(barray.raw.data(), barray.raw.data()+barray.raw.size()));
    }
}


#undef MEM_FN
