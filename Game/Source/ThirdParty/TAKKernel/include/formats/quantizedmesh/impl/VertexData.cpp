#include "formats/quantizedmesh/impl/VertexData.h"

using namespace TAK::Engine;
using namespace TAK::Engine::Formats::QuantizedMesh;
using namespace TAK::Engine::Formats::QuantizedMesh::Impl;


namespace {
    int zzDec(int value)
    {
        return (value >> 1) ^ (-(value & 1));
    }

    Util::TAKErr zzDec(int16_t *dst, int previous, Util::DataInput2 &input)
    {
        int16_t ss;
        Util::TAKErr code = input.readShort(&ss);
        TE_CHECKRETURN_CODE(code);
        int s = ss;
        if (s < 0)
            s += 65536;
        previous += zzDec(s);
        *dst = ((int16_t)previous);
        return Util::TE_Ok;
    }
}

VertexData::VertexData() NOTHROWS
{}

Util::TAKErr TAK::Engine::Formats::QuantizedMesh::Impl::VertexData_deserialize(std::unique_ptr<VertexData> &result, Util::DataInput2 &input) NOTHROWS
{
    result.reset(new VertexData());
    return VertexData_deserialize(*result, input);
}
Util::TAKErr TAK::Engine::Formats::QuantizedMesh::Impl::VertexData_deserialize(VertexData &result, Util::DataInput2 &input) NOTHROWS
{
    Util::TAKErr code = Util::TE_Ok;
    code = input.readInt(&result.vertexCount);
    TE_CHECKRETURN_CODE(code);

    result.totalSize = (8 + 4 + (result.vertexCount * 6));
    result.u.resize(result.vertexCount, 0);
    result.v.resize(result.vertexCount, 0);
    result.height.resize(result.vertexCount, 0);

    auto ubuf = result.u.data();
    auto vbuf = result.v.data();
    auto hbuf = result.height.data();

    int u = 0, v = 0, height = 0;
    for (int i = 0; i < result.vertexCount; i++) {
        code = zzDec(ubuf + i, u, input);
        TE_CHECKRETURN_CODE(code);
        u = ubuf[i];
    }
    for (int i = 0; i < result.vertexCount; i++) {
        code = zzDec(vbuf + i, v, input);
        TE_CHECKRETURN_CODE(code);
        v = vbuf[i];
    }
    for (int i = 0; i < result.vertexCount; i++) {
        code = zzDec(hbuf + i, height, input);
        TE_CHECKRETURN_CODE(code);
        height = hbuf[i];
    }

    return Util::TE_Ok;
}

void VertexData::get(Math::Vector4<double> *result, int index) const
{
    result->x = u[index];
    result->y = v[index];
    result->z = height[index];
}
Math::Vector4<double> VertexData::operator[](const int index) const
{
    return Math::Vector4<double>(u[index], v[index], height[index]);
}

