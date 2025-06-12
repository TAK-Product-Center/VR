#include "elevation/TileMatrixElevationSource.h"

#include <set>

#include "elevation/ElevationData.h"
#include "feature/GeometryTransformer.h"
#include "feature/SpatialCalculator2.h"
#include "math/Rectangle2.h"
#include "port/STLVectorAdapter.h"
#include "renderer/core/ContentControl.h"
#include "renderer/raster/TileCacheControl.h"
#include "thread/Lock.h"

using namespace TAK::Engine::Elevation;

using namespace TAK::Engine::Core;
using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Raster::TileMatrix;
using namespace TAK::Engine::Renderer::Core;
using namespace TAK::Engine::Renderer::Raster;
using namespace TAK::Engine::Thread;
using namespace TAK::Engine::Util;

namespace {
    class TMESCursorImpl : public ElevationChunkCursor
    {
    public :
        TMESCursorImpl(const ElevationTileMatrix &tilesDef, const std::shared_ptr<TileMatrix> &tiles, const std::vector<TileMatrix::ZoomLevel> &levels, const Envelope2 queryBounds, const int iterDir) NOTHROWS;
        ~TMESCursorImpl() NOTHROWS;
    public :
        TAKErr moveToNext() NOTHROWS override;
    public :
        TAKErr get(ElevationChunkPtr &value) NOTHROWS override;
        TAKErr getResolution(double *value) NOTHROWS override;
        TAKErr isAuthoritative(bool *value) NOTHROWS override;
        TAKErr getCE(double *value) NOTHROWS override;
        TAKErr getLE(double *value) NOTHROWS override;
        TAKErr getUri(const char **value) NOTHROWS override;
        TAKErr getType(const char **value) NOTHROWS override;
        TAKErr getBounds(const Polygon2 **value) NOTHROWS override;
        TAKErr getFlags(unsigned int *value) NOTHROWS override;
    private :
        std::shared_ptr<TileMatrix> tiles;
        Envelope2 queryBounds;
        std::vector<TileMatrix::ZoomLevel> zoomLevels;
        TileMatrix::ZoomLevel currentZoom;
        int zoomIterDir;
        int zoomIdx;
        int zoomLimit;
        std::size_t stx;
        std::size_t ftx;
        std::size_t sty;
        std::size_t fty;
        std::size_t tileIdx;
        std::size_t tileLimit;
        bool tileMiss;
        struct {
            std::shared_ptr<const uint8_t> data;
            std::size_t len {0u};
            Polygon2 bounds;
            std::shared_ptr<LineString2> boundsRing;
        } row;
        ElevationTileMatrix tilesDef;
    };
}

class TileMatrixElevationSource::SourceContentChangedDispatcher :
    public ContentControl::OnContentChangedListener,
    public TileCacheControl::OnTileUpdateListener
{
public :
    SourceContentChangedDispatcher(TileMatrixElevationSource& owner) NOTHROWS;
public :
    void addListener(ElevationSource::OnContentChangedListener* listener) NOTHROWS;
    void removeListener(const ElevationSource::OnContentChangedListener &listener) NOTHROWS;
public : // ContentControl::OnContentChangedListener
    TAKErr onContentChanged() NOTHROWS override;
public : // TileCacheControl::OnTileUpdateListener
    void onTileUpdated(const std::size_t level, const std::size_t x, const std::size_t y) NOTHROWS override;
private :
    void dispatchContentChanged() NOTHROWS;
public :
    TileMatrixElevationSource& owner;
    Mutex mutex;
    std::set<ElevationSource::OnContentChangedListener*> listeners;
};

TileMatrixElevationSource::TileMatrixElevationSource(const std::shared_ptr<Raster::TileMatrix::TileMatrix> &tiles_, const ElevationTileMatrix &tilesDef_, const Control *controls_, const std::size_t numControls) NOTHROWS :
    TileMatrixElevationSource(tiles_->getName(), tiles_, tilesDef_, controls_, numControls)
{}
TileMatrixElevationSource::TileMatrixElevationSource(const char *name_, const std::shared_ptr<Raster::TileMatrix::TileMatrix> &tiles_, const ElevationTileMatrix &tilesDef_, const Control *controls_, const std::size_t numControls) NOTHROWS :
    name(name_),
    tiles(tiles_),
    tilesDef(tilesDef_)
{
    contentChangedDispatcher = std::unique_ptr<SourceContentChangedDispatcher>(new SourceContentChangedDispatcher(*this));

    tiles->getBounds(&bounds);
    GeometryTransformer_transform(&bounds, bounds, tiles->getSRID(), 4326);

    TAK::Engine::Port::STLVectorAdapter<TileMatrix::ZoomLevel> allZooms_w(allZooms);
    tiles->getZoomLevel(allZooms_w);

    if (numControls)
        controls.reserve(numControls);
    for(std::size_t i = 0u; i < numControls; i++) {
        const auto ctrl = controls_[i];
        controls.push_back(ctrl);
        if(TAK::Engine::Port::String_equal(ctrl.type, ContentControl_getType())) {
            auto impl = static_cast<ContentControl*>(ctrl.value);
            impl->addOnContentChangedListener(contentChangedDispatcher.get());
        } else if(TAK::Engine::Port::String_equal(ctrl.type, TileCacheControl_getType())) {
            auto impl = static_cast<TileCacheControl*>(ctrl.value);
            impl->setOnTileUpdateListener(contentChangedDispatcher.get());
        }
    }
}
TileMatrixElevationSource::~TileMatrixElevationSource() NOTHROWS
{
    for(const auto &ctrl : controls) {
        if(TAK::Engine::Port::String_equal(ctrl.type, ContentControl_getType())) {
            auto impl = static_cast<ContentControl*>(ctrl.value);
            impl->removeOnContentChangedListener(contentChangedDispatcher.get());
        } else if(TAK::Engine::Port::String_equal(ctrl.type, TileCacheControl_getType())) {
            auto impl = static_cast<TileCacheControl*>(ctrl.value);
            impl->setOnTileUpdateListener(nullptr);
        }
    }
}
const char *TileMatrixElevationSource::getName() const NOTHROWS
{
    return name;
}
TAKErr TileMatrixElevationSource::query(ElevationChunkCursorPtr &value, const QueryParameters &params) NOTHROWS
{
    std::vector<TileMatrix::ZoomLevel> zoomLevels;
    auto queryBounds = bounds;
    int iterDir = -1; // -1 = high to low, 1 = low to high
    do {
        if (params.spatialFilter) {
            Envelope2 filterBounds;
            params.spatialFilter->getEnvelope(&filterBounds);
            // if no intersect, leave empty params
            if(!SpatialCalculator_intersects(bounds, filterBounds))
                break;
            queryBounds.minX = std::max(bounds.minX, filterBounds.minX);
            queryBounds.minY = std::max(bounds.minY, filterBounds.minY);
            queryBounds.maxX = std::min(bounds.maxX, filterBounds.maxX);
            queryBounds.maxY = std::min(bounds.maxY, filterBounds.maxY);
        }

        if(params.order && !params.order->empty()) {
            TAK::Engine::Port::Collection<ElevationSource::QueryParameters::Order>::IteratorPtr orderIter(nullptr, nullptr);
            params.order->iterator(orderIter);
            do {
                ElevationSource::QueryParameters::Order order;
                if(orderIter->get(order) != TE_Ok)
                    continue;
                if(order == ElevationSource::QueryParameters::ResolutionAsc) {
                    iterDir = 1;
                    break;
                } else if(order == ElevationSource::QueryParameters::ResolutionDesc) {
                    iterDir = -1;
                    break;
                }
                if(orderIter->next() != TE_Ok)
                    break;
            } while(true);
        }

        double minRes = TE_ISNAN(params.minResolution) ? allZooms.front().resolution : params.minResolution;
        double maxRes = TE_ISNAN(params.maxResolution) ? allZooms.back().resolution : params.maxResolution;
        for (const auto& zoom : allZooms) {
            if (zoom.resolution > minRes)
                continue;
            else if (zoom.resolution < maxRes)
                break;
            zoomLevels.push_back(zoom);
        }
    } while(false);

    value = ElevationChunkCursorPtr(new TMESCursorImpl(tilesDef, tiles, zoomLevels, queryBounds, iterDir), Memory_deleter_const<ElevationChunkCursor, TMESCursorImpl>);
    return TE_Ok;
}
Envelope2 TileMatrixElevationSource::getBounds() const NOTHROWS
{
    return bounds;
}
TAKErr TileMatrixElevationSource::addOnContentChangedListener(ElevationSource::OnContentChangedListener *l) NOTHROWS
{
    contentChangedDispatcher->addListener(l);
    return TE_Ok;
}
TAKErr TileMatrixElevationSource::removeOnContentChangedListener(ElevationSource::OnContentChangedListener *l) NOTHROWS
{
    if(l)
        contentChangedDispatcher->removeListener(*l);
    return TE_Ok;
}

TileMatrixElevationSource::SourceContentChangedDispatcher::SourceContentChangedDispatcher(TileMatrixElevationSource &owner_) NOTHROWS :
    owner(owner_)
{}
void TileMatrixElevationSource::SourceContentChangedDispatcher::addListener(ElevationSource::OnContentChangedListener* listener) NOTHROWS
{
    Lock lock(mutex);
    listeners.insert(listener);
}
void TileMatrixElevationSource::SourceContentChangedDispatcher::removeListener(const ElevationSource::OnContentChangedListener &listener) NOTHROWS
{
    Lock lock(mutex);
    for(auto it = listeners.begin(); it != listeners.end(); it++) {
        if ((*it) == &listener) {
            listeners.erase(it);
            break;
        }
    }
}
TAKErr TileMatrixElevationSource::SourceContentChangedDispatcher::onContentChanged() NOTHROWS
{
    dispatchContentChanged();
    return TE_Ok;
}
void TileMatrixElevationSource::SourceContentChangedDispatcher::onTileUpdated(const std::size_t level, const std::size_t x, const std::size_t y) NOTHROWS 
{
    dispatchContentChanged();
}
void TileMatrixElevationSource::SourceContentChangedDispatcher::dispatchContentChanged() NOTHROWS
{
    Lock lock(mutex);
    auto it = listeners.begin();
    while(it != listeners.end()) {
        if ((*it)->onContentChanged(owner) == TE_Done)
            it = listeners.erase(it);
        else
            it++;
    }
}

namespace {
    TMESCursorImpl::TMESCursorImpl(const ElevationTileMatrix &tilesDef_, const std::shared_ptr<TileMatrix> &tiles_, const std::vector<TileMatrix::ZoomLevel> &levels_, const Envelope2 queryBounds_, const int iterDir_) NOTHROWS :
        tiles(tiles_),
        zoomLevels(levels_),
        queryBounds(queryBounds_),
        zoomIterDir(iterDir_),
        zoomIdx((iterDir_ < 0) ? (int)levels_.size() : -1),
        zoomLimit((iterDir_ < 0) ? -1 : (int)levels_.size()),
        tileIdx(0u),
        tileLimit(0u),
        tilesDef(tilesDef_),
        tileMiss(true)
    {
        row.bounds.getExteriorRing(row.boundsRing);
    }
    TMESCursorImpl::~TMESCursorImpl() NOTHROWS
    {}
    TAKErr TMESCursorImpl::moveToNext() NOTHROWS
    {
        do {
            if(zoomIdx == zoomLimit)
                return TE_Done;
            if (tileIdx == tileLimit) {
                // if one or more tiles were missing on last iterated level, bump to next; if no
                // tiles were missed, no data will be available from subsequent levels
                if (tileMiss)
                    zoomIdx += zoomIterDir;
                else
                    zoomIdx = zoomLimit;
                if(zoomIdx == zoomLimit)
                    continue;

                tileMiss = false;

                row.data.reset();

                currentZoom = zoomLevels[zoomIdx];
                TAK::Engine::Math::Point2<std::size_t> minTile;
                TAK::Engine::Math::Point2<std::size_t> maxTile;
                if (tilesDef.getRegionTileIndices(&minTile, &maxTile, TAK::Engine::Math::Point2<double>(tiles->getOriginX(), tiles->getOriginY(), 0.0), currentZoom, queryBounds) == TE_Ok) {

                    // reset tile iteration parameters
                    stx = minTile.x;
                    sty = minTile.y;
                    ftx = maxTile.x;
                    fty = maxTile.y;

                    tileIdx = 0u;
                    tileLimit = (ftx - stx + 1u) * (fty - sty + 1u);

                    // prevent excessive tile iteration
                    if ((ftx - stx + 1u) > 10 || (fty - sty + 1u) > 10 || (tileLimit > 64)) {
                        tileIdx = 0u;
                        tileLimit = 0u;
                    }
                } else {
                    // no intersection
                    tileIdx = 0u;
                    tileLimit = 0u;
                }
                continue;
            }

            const std::size_t tx = tileIdx%(ftx-stx+1) + stx;
            const std::size_t ty = tileIdx/(ftx-stx+1) + sty;
            tileIdx++;

            std::unique_ptr<const uint8_t, void(*)(const uint8_t *)> rowData(nullptr, nullptr);
            if (tiles->getTileData(rowData, &row.len, currentZoom.level, tx, ty) != TE_Ok) {
                tileMiss = true;
                continue;
            }
            row.data = std::move(rowData);

            Envelope2 tileBounds;
            TileMatrix_getTileBounds(&tileBounds, tiles->getOriginX(), tiles->getOriginY(), currentZoom, (int)tx, (int)ty);
            GeometryTransformer_transform(&tileBounds, tileBounds, tiles->getSRID(), 4326);
            row.boundsRing->clear();
            row.boundsRing->addPoint(tileBounds.minX, tileBounds.minY);
            row.boundsRing->addPoint(tileBounds.minX, tileBounds.maxY);
            row.boundsRing->addPoint(tileBounds.maxX, tileBounds.maxY);
            row.boundsRing->addPoint(tileBounds.maxX, tileBounds.minY);
            row.boundsRing->addPoint(tileBounds.minX, tileBounds.minY);
            break;
        } while(true);

        return TE_Ok;
    }
    TAKErr TMESCursorImpl::get(ElevationChunkPtr &value) NOTHROWS
    {
        if(!row.data)
            return TE_IllegalState;
        return tilesDef.decodeTileData(value, row.data, row.len);
    }
    TAKErr TMESCursorImpl::getResolution(double *value) NOTHROWS
    {
        *value = currentZoom.resolution;
        return TE_Ok;
    }
    TAKErr TMESCursorImpl::isAuthoritative(bool *value) NOTHROWS
    {
        *value = false;
        return TE_Ok;
    }
    TAKErr TMESCursorImpl::getCE(double *value) NOTHROWS
    {
        *value = NAN;
        return TE_Ok;
    }
    TAKErr TMESCursorImpl::getLE(double *value) NOTHROWS
    {
        *value = NAN;
        return TE_Ok;
    }
    TAKErr TMESCursorImpl::getUri(const char **value) NOTHROWS
    {
        // XXX -
        *value = tiles->getName();
        return TE_Ok;
    }
    TAKErr TMESCursorImpl::getType(const char **value) NOTHROWS
    {
        // XXX -
        *value = tiles->getName();
        return TE_Ok;
    }
    TAKErr TMESCursorImpl::getBounds(const Polygon2 **value) NOTHROWS
    {
        *value = &row.bounds;
        return TE_Ok;
    }
    TAKErr TMESCursorImpl::getFlags(unsigned int *value) NOTHROWS
    {
        *value = ElevationData::MODEL_TERRAIN;
        return TE_Ok;
    }
}
