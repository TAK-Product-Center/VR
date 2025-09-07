//
// Created by Geo Dev on 1/31/24.
//

#ifndef TAK_ENGNIE_FORMATS_MAPBOXGLSTYLESHEET_H
#define TAK_ENGNIE_FORMATS_MAPBOXGLSTYLESHEET_H

#include <map>
#include <sstream>
#include <vector>


#include <tinygltf/json.hpp>

#include "feature/Style.h"
#include "feature/StyleSheet.h"
#include "port/Platform.h"
#include "port/String.h"
#include "util/AttributeSet.h"
#include "util/Error.h"

namespace TAK {
    namespace Engine {
        namespace Formats {
            namespace MBTiles {
                ENGINE_API std::shared_ptr<Feature::StyleSheet> MapBoxGLStyleSheet_parse(const nlohmann::json& json, const char* styleDocPath = nullptr) NOTHROWS;
            }
        }
    }
}

#endif //ATAK_MAPBOXGLSTYLESHEET_H
