#ifndef TAK_ENGINE_FORMATS_QUANTIZEDMESH_EDGEINDICES_H_INCLUDED
#define TAK_ENGINE_FORMATS_QUANTIZEDMESH_EDGEINDICES_H_INCLUDED

#include "Indices.h"
#include "VertexData.h"
#include "port/Platform.h"
#include "util/Error.h"

namespace TAK {
namespace Engine {
namespace Formats {
namespace QuantizedMesh {
namespace Impl {

    /**
     * Indices which point to vertices that are on the edge of the tile.
     * Note: Marked ENGINE_API for test purposes only
     */
    class ENGINE_API EdgeIndices {

    public:
        typedef enum {
            NORTH = 0,
            EAST = 1,
            SOUTH = 2,
            WEST = 3
        } Direction;

        EdgeIndices() NOTHROWS;
        ~EdgeIndices() NOTHROWS;

        const Indices *getIndicesForEdge(int edge) const;
        int64_t getTotalSize() const;

    private:
        int64_t totalSize;
        Indices edges[4];

        friend Util::TAKErr EdgeIndices_deserialize(EdgeIndices &result, const VertexData &vertexData, bool is32bit, Util::DataInput2 &input, const bool sortEdges) NOTHROWS;
        friend Util::TAKErr EdgeIndices_deserializeOneEdge(Indices &result, int64_t *totalSize, EdgeIndices::Direction d, const VertexData &vertexData, bool is32bit, Util::DataInput2 &input, const bool sortEdges) NOTHROWS;
    };

    Util::TAKErr EdgeIndices_deserialize(std::unique_ptr<EdgeIndices> &result, const VertexData &vertexData, bool is32bit, Util::DataInput2 &input, const bool sortEdges = true) NOTHROWS;
    Util::TAKErr EdgeIndices_deserialize(EdgeIndices &result, const VertexData &vertexData, bool is32bit, Util::DataInput2 &input, const bool sortEdges = true) NOTHROWS;
    Util::TAKErr EdgeIndices_deserializeOneEdge(std::unique_ptr<Indices> &result, int64_t *totalSize, EdgeIndices::Direction d, const VertexData &vertexData, bool is32bit, Util::DataInput2 &input, const bool sortEdges = true) NOTHROWS;
    Util::TAKErr EdgeIndices_deserializeOneEdge(Indices &result, int64_t *totalSize, EdgeIndices::Direction d, const VertexData &vertexData, bool is32bit, Util::DataInput2 &input, const bool sortEdges = true) NOTHROWS;
}
}
}
}
}

#endif
