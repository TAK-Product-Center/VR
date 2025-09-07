#ifndef TAK_ENGINE_FORMATS_QUANTIZEDMESH_INDICES_H_INCLUDED
#define TAK_ENGINE_FORMATS_QUANTIZEDMESH_INDICES_H_INCLUDED

#include "port/Platform.h"
#include "util/Error.h"

#include "util/DataInput2.h"

#include <vector>

namespace TAK {
namespace Engine {
namespace Formats {
namespace QuantizedMesh {
namespace Impl {

    /**
     * Generic struct for 16/32-bit indices
     */
    class Indices {
    public:
        Indices() NOTHROWS;

        int get(int i) const;
        const int operator[](int idx) const;
        int64_t getTotalSize() const;
        bool getIs32Bit() const;
        int getLength() const;
        void sort(const int16_t *vertexDataU, const int16_t *vertexDataV, bool isNorthSouth);
        
    private:
        bool is32bit;

        // Only one of these is used, depending on is32bit value
        std::vector<int32_t> value;

        friend Util::TAKErr Indices_deserialize(std::unique_ptr<Indices> &result, int length, bool is32bit, bool isCompressed, Util::DataInput2 &input) NOTHROWS;
        friend Util::TAKErr Indices_deserialize(Indices &result, int length, bool is32bit, bool isCompressed, Util::DataInput2 &input) NOTHROWS;
    };

    Util::TAKErr Indices_deserialize(std::unique_ptr<Indices> &result, int length, bool is32bit, bool isCompressed, Util::DataInput2 &input) NOTHROWS;
    Util::TAKErr Indices_deserialize(Indices &result, int length, bool is32bit, bool isCompressed, Util::DataInput2 &input) NOTHROWS;
}
}
}
}
}

#endif
