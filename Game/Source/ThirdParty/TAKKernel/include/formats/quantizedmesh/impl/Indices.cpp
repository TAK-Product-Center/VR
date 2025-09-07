#include "formats/quantizedmesh/impl/Indices.h"

#include <algorithm>


using namespace TAK::Engine;
using namespace TAK::Engine::Formats::QuantizedMesh;
using namespace TAK::Engine::Formats::QuantizedMesh::Impl;


namespace {
    template <typename CmpInt>
    struct AdaptCmp16
    {
        CmpInt &cmp;

        AdaptCmp16(CmpInt &cmp) : cmp(cmp)
        {
        }

        virtual bool operator()(const int16_t &a16, const int16_t &b16) const
        {
            int a = a16;
            int b = b16;
            return cmp(a16, b16);
        }
    };


    struct IndexCompare {
        const int16_t *vertexDataU;
        const int16_t *vertexDataV;
        const bool isNS;

        IndexCompare(const int16_t *vertexDataU, const int16_t *vertexDataV, bool isNS);
        bool operator()(const int32_t &i1, const int32_t &i2) const;
    };
}


Indices::Indices() NOTHROWS :
    is32bit(false)
{}

Util::TAKErr TAK::Engine::Formats::QuantizedMesh::Impl::Indices_deserialize(std::unique_ptr<Indices> &result, int length, bool is32bit, bool isCompressed, Util::DataInput2 &input) NOTHROWS
{
    result.reset(new Indices());
    return Indices_deserialize(*result, length, is32bit, isCompressed, input);
}
Util::TAKErr TAK::Engine::Formats::QuantizedMesh::Impl::Indices_deserialize(Indices &result, int length, bool is32bit, bool isCompressed, Util::DataInput2 &input) NOTHROWS
{
    Util::TAKErr rc = Util::TE_Ok;
    result.is32bit = is32bit;

    result.value.reserve(length);

    if (isCompressed) {
        int highest = 0;
        for (int i = 0; i < length; ++i) {
            int index;
            if (is32bit) {
                int code;
                rc = input.readInt(&code);
                TE_CHECKRETURN_CODE(rc);
                index = highest - code;

                if (code == 0)
                    ++highest;
            } else {
                int16_t code16;
                rc = input.readShort(&code16);
                TE_CHECKRETURN_CODE(rc);
                int code = (unsigned short)code16;
                index = highest - code;
                if (code == 0)
                    ++highest;
            }
            result.value.push_back(index);
        }
    } else {
        for (int i = 0; i < length; ++i) {
            int code;
            if (is32bit) {
                rc = input.readInt(&code);
                TE_CHECKRETURN_CODE(rc);
            } else { // 16-bit
                int16_t scode;
                rc = input.readShort(&scode);
                TE_CHECKRETURN_CODE(rc);
                code = scode;
            }
            result.value.push_back(code);
        }
    }

    return Util::TE_Ok;
}

int Indices::get(int i) const
{
    return value[i];
}
const int Indices::operator[](int idx) const
{
    return value[idx];
}

int64_t Indices::getTotalSize() const
{
    return (int64_t)value.size() * (int64_t)(is32bit ? 4 : 2);
}

bool Indices::getIs32Bit() const
{
    return is32bit;
}

int Indices::getLength() const
{
    return (int)value.size();
}

void Indices::sort(const int16_t *vertexDataU, const int16_t *vertexDataV, bool isNorthSouth)
{
    // For the sake of a faster skirt function, sorts indices by X/Y along
    // their respective edges
    IndexCompare cmp(vertexDataU, vertexDataV, isNorthSouth);
    std::sort(value.begin(), value.end(), cmp);
}


IndexCompare::IndexCompare(const int16_t *vertexDataU, const int16_t *vertexDataV, bool isNS) : 
    vertexDataU(vertexDataU), vertexDataV(vertexDataV), isNS(isNS)
{
}


bool IndexCompare::operator()(const int32_t &i1, const int32_t &i2) const
{
    const auto ns = vertexDataU[i1]-vertexDataU[i2];
    const auto ew = vertexDataV[i1]-vertexDataV[i2];
    const auto a = isNS ? ns : ew;
    const auto b = isNS ? ew : ns;
    return a ? (a<0) : (b<0);
}
