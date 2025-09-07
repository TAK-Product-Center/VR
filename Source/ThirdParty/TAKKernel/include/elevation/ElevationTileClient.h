//
// Created by Geo Dev on 6/3/22.
//

#ifndef TAK_ENGINE_ELEVATION_ELEVATIONTILECLIENT_H_INCLUDED
#define TAK_ENGINE_ELEVATION_ELEVATIONTILECLIENT_H_INCLUDED

#include <list>
#include <map>

#include "core/Control.h"
#include "elevation/HeightmapParams.h"
#include "elevation/TileMatrixElevationSource.h"
#include "port/Platform.h"
#include "raster/tilematrix/TileClient.h"
#include "renderer/core/ContentControl.h"
#include "util/BlockPoolAllocator.h"
#include "util/Error.h"

namespace TAK {
    namespace Engine {
        namespace Elevation {
            class ENGINE_API ElevationTileClient : public TAK::Engine::Raster::TileMatrix::TileClient
            {
            public :
                ElevationTileClient(const HeightmapParams &params) NOTHROWS;
                ElevationTileClient(const HeightmapParams &params, std::size_t overlap) NOTHROWS;
                ElevationTileClient(const std::shared_ptr<ElevationSource> &source, const int srid, const HeightmapParams &params, const std::size_t overlap = 1u, const bool forcePointSample = false) NOTHROWS;
            public:
                ~ElevationTileClient() NOTHROWS;
            public : // controls
                Util::TAKErr getControl(Core::Control* control, const char* controlName) NOTHROWS;
                Util::TAKErr getControls(Port::Collection<Core::Control> &controls) NOTHROWS;
            public : // TileClient
                Util::TAKErr clearAuthFailed() NOTHROWS override;
                Util::TAKErr checkConnectivity() NOTHROWS override;
                Util::TAKErr cache(const TAK::Engine::Raster::TileMatrix::CacheRequest &request, std::shared_ptr<TAK::Engine::Raster::TileMatrix::CacheRequestListener> &listener) NOTHROWS override;
                Util::TAKErr estimateTilecount(int *count, const TAK::Engine::Raster::TileMatrix::CacheRequest &request) NOTHROWS override;
            public : // TileMatrix
                const char* getName() const NOTHROWS override;
                int getSRID() const NOTHROWS override;
                Util::TAKErr getZoomLevel(Port::Collection<TAK::Engine::Raster::TileMatrix::TileMatrix::ZoomLevel>& value) const NOTHROWS override;
                double getOriginX() const NOTHROWS override;
                double getOriginY() const NOTHROWS override;
                Util::TAKErr getTile(Renderer::BitmapPtr& result, const std::size_t zoom, const std::size_t x, const std::size_t y) NOTHROWS override;
                Util::TAKErr getTileData(std::unique_ptr<const uint8_t, void (*)(const uint8_t*)>& value, std::size_t* len,
                                                 const std::size_t zoom, const std::size_t x, const std::size_t y) NOTHROWS override;
                Util::TAKErr getBounds(Feature::Envelope2 *value) const NOTHROWS override;
            protected :
                virtual Util::TAKErr createHeightmap(double *value, const double gsd, const HeightmapParams &tileDataParams) NOTHROWS;
            private :
                Util::TAKErr createHeightmapDefault(double *value, const double gsd, const HeightmapParams &tileDataParams) NOTHROWS;
                Util::TAKErr createHeightmapPoints(double *value, const double gsd, const HeightmapParams &tileDataParams) NOTHROWS;
            protected :
                struct {
                    ZoomLevel *value;
                    std::size_t count;
                } zoomLevels;
            private :
                std::shared_ptr<ElevationSource> source;
                int srid;
                HeightmapParams heightmapParams;
                std::size_t overlap;
                bool forcePointSample;
                struct {
                    std::vector<Core::Control> value;
                    std::unique_ptr<Renderer::Core::ContentControl, void(*)(const Renderer::Core::ContentControl *)> content{ nullptr, nullptr };
                } controls;
                Util::BlockPoolAllocator tileDataAllocator;
                std::vector<ZoomLevel> zoomLevels_v;
            };

            ENGINE_API ElevationTileMatrix ElevationTileClient_info() NOTHROWS;


        }
    }
}

#endif //TAK_ENGINE_ELEVATION_ELEVATIONTILECONTAINER_H_INCLUDED
