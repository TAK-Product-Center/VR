#ifndef TAK_ENGINE_FORMATS_QUANTIZEDMESH_INDEXDATA_H_INCLUDED
#define TAK_ENGINE_FORMATS_QUANTIZEDMESH_INDEXDATA_H_INCLUDED

#include "port/Platform.h"
#include "util/Error.h"

#include "formats/quantizedmesh/impl/Indices.h"
#include "formats/quantizedmesh/impl/VertexData.h"
#include "math/Rectangle2.h"

#include <vector>

namespace TAK {
namespace Engine {
namespace Formats {
namespace QuantizedMesh {
namespace Impl {

/**
 * Indices which make up the triangles in this elevation mesh
 */
class IndexData {
private :
    struct Quadtree {
        Quadtree(const Math::Rectangle2<double> &bounds, std::size_t depth) NOTHROWS;
        void push_back(const Math::Rectangle2<double> &bounds, const int triangleIndex) NOTHROWS;

        struct {
            std::vector<int> indices;
            std::vector<Math::Rectangle2<double>> bounds;
        } elements;
        std::vector<Quadtree> children;
        /** u/v relative bounds */
        Math::Rectangle2<double> bounds;
        std::size_t depth;
    };
public:
    IndexData() NOTHROWS;

    int get(int i) const;
    const int operator[](int idx) const;
    bool is32Bit() const;
    int getLength() const;
    int64_t getTotalSize() const;
    const std::vector<int> *getTriangleIndices(int level, int x, int y);

    static const int QUAD_MIN_LEVEL = 10;
    static const int QUAD_MAX_LEVEL = 15;

private:
    int64_t totalSize;
    int triangleCount;
    Indices indices;
    Quadtree quadtree;

    friend Util::TAKErr IndexData_deserialize(std::unique_ptr<IndexData> &result, const VertexData &vertexData, Util::DataInput2 &input) NOTHROWS;
    friend Util::TAKErr IndexData_deserialize(IndexData &result, const VertexData &vertexData, Util::DataInput2 &input) NOTHROWS;
};

Util::TAKErr IndexData_deserialize(std::unique_ptr<IndexData> &result, const VertexData &vertexData, Util::DataInput2 &input) NOTHROWS;
Util::TAKErr IndexData_deserialize(IndexData &result, const VertexData &vertexData, Util::DataInput2 &input) NOTHROWS;

}
}
}
}
}

#endif
