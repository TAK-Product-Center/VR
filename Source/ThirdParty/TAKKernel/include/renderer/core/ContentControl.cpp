#include "renderer/core/ContentControl.h"

using namespace TAK::Engine::Renderer::Core;

ContentControl::~ContentControl() NOTHROWS
{}

ContentControl::OnContentChangedListener::~OnContentChangedListener() NOTHROWS
{}

const char* TAK::Engine::Renderer::Core::ContentControl_getType() NOTHROWS
{
    return "TAK::Engine::Renderer::Core::ContentControl";
}
