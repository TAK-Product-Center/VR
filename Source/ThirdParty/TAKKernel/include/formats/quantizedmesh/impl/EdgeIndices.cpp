#include "formats/quantizedmesh/impl/EdgeIndices.h"


using namespace TAK::Engine;
using namespace TAK::Engine::Formats::QuantizedMesh;
using namespace TAK::Engine::Formats::QuantizedMesh::Impl;


EdgeIndices::EdgeIndices() NOTHROWS
{}

EdgeIndices::~EdgeIndices() NOTHROWS
{}

Util::TAKErr TAK::Engine::Formats::QuantizedMesh::Impl::EdgeIndices_deserializeOneEdge(
        std::unique_ptr<Indices> &result,
        int64_t *totalSize,
        EdgeIndices::Direction d,
        const VertexData &vertexData,
        bool is32bit,
        Util::DataInput2 &input,
        const bool sortEdges) NOTHROWS
{
    result.reset(new Indices());
    return EdgeIndices_deserializeOneEdge(*result, totalSize, d, vertexData, is32bit, input, sortEdges);
}
Util::TAKErr TAK::Engine::Formats::QuantizedMesh::Impl::EdgeIndices_deserializeOneEdge(
    Indices &result,
    int64_t *totalSize,
    EdgeIndices::Direction d,
    const VertexData &vertexData,
    bool is32bit,
    Util::DataInput2 &input,
    const bool sortEdges) NOTHROWS
{
    int len;
    Util::TAKErr code = input.readInt(&len);
    TE_CHECKRETURN_CODE(code);
    code = Indices_deserialize(result, len, is32bit, false, input);
    TE_CHECKRETURN_CODE(code);

    if(sortEdges)
        result.sort(vertexData.u.data(), vertexData.v.data(), d == EdgeIndices::NORTH || d == EdgeIndices::SOUTH);

    *totalSize += result.getTotalSize();

    return code;
}

Util::TAKErr TAK::Engine::Formats::QuantizedMesh::Impl::EdgeIndices_deserialize(
    std::unique_ptr<EdgeIndices> &result,
    const VertexData &vertexData,
    bool is32bit,
    Util::DataInput2 &input,
    const bool sortEdges) NOTHROWS
{
    result.reset(new EdgeIndices());
    return EdgeIndices_deserialize(*result, vertexData, is32bit, input, sortEdges);
}
Util::TAKErr TAK::Engine::Formats::QuantizedMesh::Impl::EdgeIndices_deserialize(
        EdgeIndices &result,
        const VertexData &vertexData,
        bool is32bit,
        Util::DataInput2 &input,
        const bool sortEdges) NOTHROWS
{
    Util::TAKErr code = Util::TE_Ok;
    result.totalSize = 8;

    code = EdgeIndices_deserializeOneEdge(result.edges[EdgeIndices::WEST], &result.totalSize, EdgeIndices::WEST, vertexData, is32bit, input, sortEdges);
    TE_CHECKRETURN_CODE(code);
    std::unique_ptr<Indices> south;
    code = EdgeIndices_deserializeOneEdge(result.edges[EdgeIndices::SOUTH], &result.totalSize, EdgeIndices::SOUTH, vertexData, is32bit, input, sortEdges);
    TE_CHECKRETURN_CODE(code);
    std::unique_ptr<Indices> east;
    code = EdgeIndices_deserializeOneEdge(result.edges[EdgeIndices::EAST], &result.totalSize, EdgeIndices::EAST, vertexData, is32bit, input, sortEdges);
    TE_CHECKRETURN_CODE(code);
    std::unique_ptr<Indices> north;
    code = EdgeIndices_deserializeOneEdge(result.edges[EdgeIndices::NORTH], &result.totalSize, EdgeIndices::NORTH, vertexData, is32bit, input, sortEdges);
    TE_CHECKRETURN_CODE(code);

    return Util::TE_Ok;
}

const Indices *EdgeIndices::getIndicesForEdge(int edge) const
{
    return (edge >= 0 && edge < 4) ? (edges + edge) : nullptr;
}

int64_t EdgeIndices::getTotalSize() const
{
    return totalSize;
}



