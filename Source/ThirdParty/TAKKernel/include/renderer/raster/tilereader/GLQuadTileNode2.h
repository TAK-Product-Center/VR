#pragma once

#include "core/GeoPoint2.h"
#include "port/Platform.h"
#include "raster/DatasetProjection2.h"
#include "raster/ImageInfo.h"
#include "raster/tilereader/TileReaderFactory2.h"
#include "renderer/GLTextureCache2.h"

namespace TAK {
namespace Engine {
namespace Renderer {
namespace Raster {
namespace TileReader {

class ENGINE_API GLQuadTileNode2
{
   public:
    struct Initializer
    {
        virtual ~Initializer() = 0;
        /**
         * Perform initialization of the TileReader and projection pointers
         * based on information in provided ImageInfo and Factory options. reader and imprecise
         * must be populated; precise is optional. Return TE_Ok for success,
         * any other value for error.
         */
        virtual Util::TAKErr init(std::shared_ptr<TAK::Engine::Raster::TileReader::TileReader2> &reader,
                                  TAK::Engine::Raster::DatasetProjection2Ptr &imprecise,
                                  TAK::Engine::Raster::DatasetProjection2Ptr &precise, const TAK::Engine::Raster::ImageInfo *info,
                                  TAK::Engine::Raster::TileReader::TileReaderFactory2Options &readerOpts) const = 0;
    };

    struct Options
    {
        bool textureCopyEnabled;
        bool childTextureCopyResolvesParent;
        GLTextureCache2 *textureCache;
        bool progressiveLoad;
        double levelTransitionAdjustment;
        bool textureBorrowEnabled;
        Options();
    };

   protected:
    // Forward declared impl-private interface
    struct GridVertex
    {
        TAK::Engine::Core::GeoPoint2 value;
        bool resolved;
        TAK::Engine::Math::Point2<double> projected;
        int projectedSrid;

        GridVertex();
    };

   public:
};

}  // namespace TileReader
}  // namespace Raster
}  // namespace Renderer
}  // namespace Engine
}  // namespace TAK

