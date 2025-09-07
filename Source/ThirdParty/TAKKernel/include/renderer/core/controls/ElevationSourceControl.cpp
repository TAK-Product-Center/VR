//
// Created by Geo Dev on 9/13/23.
//

#include "renderer/core/controls/ElevationSourceControl.h"

using namespace TAK::Engine::Renderer::Core::Controls;

using namespace TAK::Engine::Util;

ElevationSourceControl::~ElevationSourceControl() NOTHROWS
{}

ENGINE_API const char* TAK::Engine::Renderer::Core::Controls::ElevationSourceControl_getType() NOTHROWS
{
    return "TAK.Engine.Renderer.Core.Controls.ElevationSourceControl";
}
