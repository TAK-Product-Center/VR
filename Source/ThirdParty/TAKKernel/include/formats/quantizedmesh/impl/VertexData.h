#ifndef TAK_ENGINE_FORMATS_QUANTIZEDMESH_VERTEXDATA_H_INCLUDED
#define TAK_ENGINE_FORMATS_QUANTIZEDMESH_VERTEXDATA_H_INCLUDED

#include "port/Platform.h"
#include "util/Error.h"

#include <cstdint>
#include <vector>

#include "math/Vector4.h"
#include "util/DataInput2.h"

namespace TAK {
namespace Engine {
namespace Formats {
namespace QuantizedMesh {
namespace Impl {

class VertexData {
  public:
    VertexData() NOTHROWS;

    int vertexCount;
  public :
    std::vector<int16_t> u;
    std::vector<int16_t> v;
    std::vector<int16_t> height;
public :
    int totalSize;

    void get(Math::Vector4<double> *result, int index) const;
    Math::Vector4<double> operator[](const int index) const;

  private:

    friend Util::TAKErr VertexData_deserialize(std::unique_ptr<VertexData> &result, Util::DataInput2 &input) NOTHROWS;
    friend Util::TAKErr VertexData_deserialize(VertexData &result, Util::DataInput2 &input) NOTHROWS;
    //Util::TAKErr EdgeIndices_deserializeOneEdge(Indices &result, int64_t *totalSize, EdgeIndices::Direction d, const VertexData &vertexData, bool is32bit, Util::DataInput2 &input) NOTHROWS;
};

Util::TAKErr VertexData_deserialize(std::unique_ptr<VertexData> &result, Util::DataInput2 &input) NOTHROWS;
Util::TAKErr VertexData_deserialize(VertexData &result, Util::DataInput2 &input) NOTHROWS;

}  // namespace Impl
}  // namespace QuantizedMesh
}  // namespace Formats
}  // namespace Engine
}  // namespace TAK


#endif
