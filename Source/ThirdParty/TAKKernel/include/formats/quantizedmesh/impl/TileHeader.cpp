#include "formats/quantizedmesh/impl/TileHeader.h"

using namespace TAK::Engine;
using namespace TAK::Engine::Formats::QuantizedMesh;
using namespace TAK::Engine::Formats::QuantizedMesh::Impl;


TileHeader::TileHeader() NOTHROWS
{}

Util::TAKErr TAK::Engine::Formats::QuantizedMesh::Impl::TileHeader_deserialize(std::unique_ptr<TileHeader> &result, Util::DataInput2 &input) NOTHROWS
{
    result.reset(new TileHeader());
    return TileHeader_deserialize(*result, input);
}
Util::TAKErr TAK::Engine::Formats::QuantizedMesh::Impl::TileHeader_deserialize(TileHeader &result, Util::DataInput2 &input) NOTHROWS
{
    Util::TAKErr code = Util::TE_Ok;

    code = input.readDouble(&result.centerX);
    TE_CHECKRETURN_CODE(code);
    code = input.readDouble(&result.centerY);
    TE_CHECKRETURN_CODE(code);
    code = input.readDouble(&result.centerZ);
    TE_CHECKRETURN_CODE(code);

    code = input.readFloat(&result.minimumHeight);
    TE_CHECKRETURN_CODE(code);
    code = input.readFloat(&result.maximumHeight);
    TE_CHECKRETURN_CODE(code);

    code = input.readDouble(&result.boundingSphereCenterX);
    TE_CHECKRETURN_CODE(code);
    code = input.readDouble(&result.boundingSphereCenterY);
    TE_CHECKRETURN_CODE(code);
    code = input.readDouble(&result.boundingSphereCenterZ);
    TE_CHECKRETURN_CODE(code);
    code = input.readDouble(&result.boundingSphereRadius);
    TE_CHECKRETURN_CODE(code);

    code = input.readDouble(&result.horizonOcclusionPointX);
    TE_CHECKRETURN_CODE(code);
    code = input.readDouble(&result.horizonOcclusionPointY);
    TE_CHECKRETURN_CODE(code);
    code = input.readDouble(&result.horizonOcclusionPointZ);
    TE_CHECKRETURN_CODE(code);

    return Util::TE_Ok;
}

float TileHeader::getHeight() const
{
    return maximumHeight - minimumHeight;
}