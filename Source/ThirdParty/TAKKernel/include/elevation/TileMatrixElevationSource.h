#ifndef TAK_ENGINE_ELEVATION_TILECONTAINERELEVATIONSOURCE_H_INCLUDED
#define TAK_ENGINE_ELEVATION_TILECONTAINERELEVATIONSOURCE_H_INCLUDED

#include <set>
#include <vector>

#include "core/Control.h"
#include "elevation/ElevationSource.h"
#include "elevation/ElevationManagerElevationSource.h"
#include "port/Collection.h"
#include "port/Platform.h"
#include "raster/tilematrix/TileMatrix.h"
#include "thread/Mutex.h"
#include "util/Error.h"

namespace TAK {
    namespace Engine {
        namespace Elevation {
            struct ENGINE_API ElevationTileMatrix
            {
                /**
                 * Decodes the result of `getTileData` as an `ElevationChunk`
                 */
                Util::TAKErr(*decodeTileData)(ElevationChunkPtr& value, const std::shared_ptr<const uint8_t>& data, const std::size_t dataLen) NOTHROWS {nullptr};
                /**
                 * Returns the indices (inclusive) of the tiles containing the specified region.
                 * @param min       The minimum tile containing `region`, inclusive
                 * @param max       The maximum tile containing `region`, inclusive
                 * @param zoom      The zoom level
                 * @param region    The region
                 * 
                 * @return  TE_Ok on success, TE_Done if the specified region does not intersect
                 *          the matrix, various codes on failure
                 */
                Util::TAKErr(*getRegionTileIndices)(Math::Point2<std::size_t>* min, Math::Point2<std::size_t>* max, const Math::Point2<double>& matrixOrigin, const TAK::Engine::Raster::TileMatrix::TileMatrix::ZoomLevel& zoom, const Feature::Envelope2& region) NOTHROWS { nullptr };
            };

            class ENGINE_API TileMatrixElevationSource : public ElevationSource
            {
            private :
                class SourceContentChangedDispatcher;
            public:
                /**
                 * @param tiles         The tile matrix containing elevation chunks
                 * @param tileDef       Utility functions defining interaction with the tile matrix
                 * @param controls      Optionally specified controls associated with `tiles`. The
                 *                      lifetime of the control values MUST match or exceed the
                 *                      lifetime of `tiles`. The following controls are supported:
                 *                      <UL>
                 *                          <LI>ContentControl</LI>
                 *                          <LI>TileCacheControl</LI>
                 *                      </UL>
                 * @param numControls   Length of `controls`
                 */
                TileMatrixElevationSource(const std::shared_ptr<Raster::TileMatrix::TileMatrix> &tiles, const ElevationTileMatrix &tilesDef, const Core::Control *controls = nullptr, const std::size_t numControls = 0u) NOTHROWS;
                TileMatrixElevationSource(const char *name, const std::shared_ptr<Raster::TileMatrix::TileMatrix> &tiles, const ElevationTileMatrix &tilesDef, const Core::Control *controls = nullptr, const std::size_t numControls = 0u) NOTHROWS;
                ~TileMatrixElevationSource() NOTHROWS;
            public:
                virtual const char *getName() const NOTHROWS override;
                virtual Util::TAKErr query(ElevationChunkCursorPtr &value, const QueryParameters &params) NOTHROWS override;
                virtual Feature::Envelope2 getBounds() const NOTHROWS override;
                virtual Util::TAKErr addOnContentChangedListener(ElevationSource::OnContentChangedListener *l) NOTHROWS override;
                virtual Util::TAKErr removeOnContentChangedListener(ElevationSource::OnContentChangedListener *l) NOTHROWS override;
            private :
                TAK::Engine::Port::String name;
                std::shared_ptr<Raster::TileMatrix::TileMatrix> tiles;
                std::vector<Raster::TileMatrix::TileMatrix::ZoomLevel> allZooms;
                ElevationTileMatrix tilesDef;
                Feature::Envelope2 bounds;
                std::unique_ptr<SourceContentChangedDispatcher> contentChangedDispatcher;
                std::vector<Core::Control> controls;
            };
        }
    }
}

#endif
