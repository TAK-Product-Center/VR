#ifndef TAK_ENGINE_MODEL_MESHSIMPLIFICATION_H
#define TAK_ENGINE_MODEL_MESHSIMPLIFICATION_H

#include "model/Mesh.h"
#include "port/Platform.h"
#include "util/Error.h"

namespace TAK {
    namespace Engine {
        namespace Model {
            ENGINE_API Util::TAKErr MeshSimplication_simplify(MeshPtr &value, const Mesh &src, const double maxError) NOTHROWS;
        }
    }
}

///////////////////////////////////////////

#endif //TAK_ENGINE_MODEL_MESHSIMPLIFICATION_H
