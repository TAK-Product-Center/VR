#ifdef MSVC
#include "renderer/raster/tilereader/GLQuadTileNode2.h"

using namespace TAK::Engine::Renderer::Raster::TileReader;

/**************************************************************************/
// Initializer

GLQuadTileNode2::Initializer::~Initializer() {}

/**************************************************************************/
// Options

GLQuadTileNode2::Options::Options()
    : textureCopyEnabled(true),
      childTextureCopyResolvesParent(true),
      textureCache(nullptr),
      progressiveLoad(true),
      levelTransitionAdjustment(0.0),
      textureBorrowEnabled(true)
{}

/**************************************************************************/
// GridVertex

GLQuadTileNode2::GridVertex::GridVertex() : value(), resolved(false), projected(0.0, 0.0), projectedSrid(-1) {}

#endif