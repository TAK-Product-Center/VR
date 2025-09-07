#include "raster/tilematrix/TileScraper.h"
#include "util/Memory.h"
#include "port/STLVectorAdapter.h"
#include "feature/GeometryTransformer.h"
#include "feature/GeometryCollection2.h"
#include "feature/Polygon2.h"
#include "math/Vector4.h"
#include "thread/Lock.h"
#include "thread/Thread.h"
#include "util/IO2.h"


using namespace TAK::Engine;
using namespace TAK::Engine::Raster::TileMatrix;
using namespace TAK::Engine::Port;

namespace {
    const char *TAG = "TileScraper";
    const int MAX_TILES = 300000;
    const int DOWNLOAD_ATTEMPTS = 2;

    int64_t defaultExpiry() NOTHROWS
    {
        return TAK::Engine::Port::Platform_systime_millis();
    }

#if defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN || \
    defined(__BIG_ENDIAN__) || \
    defined(__ARMEB__) || \
    defined(__THUMBEB__) || \
    defined(__AARCH64EB__) || \
    defined(_MIBSEB) || defined(__MIBSEB) || defined(__MIBSEB__)
#define TINT_BIG_ENDIAN 1
#else
#define TINT_BIG_ENDIAN 0
#endif

    inline float tintR(float r) { return 1.0f; }
    inline float tintG(float g) { return std::min(g * 0.95f, 1.0f); }
    inline float tintB(float b) { return  std::min(b * 0.95f, 1.0f); }

    template <size_t r_index, size_t g_index, size_t b_index, size_t step>
    void applyTintByteAligned(uint8_t *d, size_t width, size_t height, size_t stride) {
        for (int j = 0; j < height; ++j) {
            uint8_t* dr = d;
            for (int i = 0; i < width; ++i) {
                float r = (dr[r_index]) / 255.f;
                float b = (dr[b_index]) / 255.f;
                float g = (dr[g_index]) / 255.f;
                r = tintR(r);
                b = tintB(b);
                g = tintG(g);
                dr[r_index] = uint32_t(r * 255);
                dr[b_index] = uint32_t(b * 255);
                dr[g_index] = uint32_t(g * 255);
                dr += step;
            }
            d += stride;
        }
    }

    void tintARGB32(TAK::Engine::Renderer::BitmapPtr& bmp) {
        applyTintByteAligned<
#if !TINT_BIG_ENDIAN
        1, 2, 3,
#else
        3, 1, 0,
#endif
        4>(bmp->getData(), bmp->getWidth(), bmp->getHeight(), bmp->getStride());
    }

    void tintRGBA32(TAK::Engine::Renderer::BitmapPtr& bmp) {
        applyTintByteAligned<
#if !TINT_BIG_ENDIAN
        0, 1, 2,
#else
        3, 2, 1,
#endif
        4>(bmp->getData(), bmp->getWidth(), bmp->getHeight(), bmp->getStride());
    }

    void tintRGB24(TAK::Engine::Renderer::BitmapPtr& bmp) {
        applyTintByteAligned<
#if !TINT_BIG_ENDIAN
        0, 1, 2,
#else
        2, 1, 0,
#endif
        3>(bmp->getData(), bmp->getWidth(), bmp->getHeight(), bmp->getStride());
    }

    void tintRGB565(TAK::Engine::Renderer::BitmapPtr& bmp) {
        const size_t stride = bmp->getStride();
        const size_t width = bmp->getWidth();
        const size_t height = bmp->getHeight();
        uint8_t *d = bmp->getData();
        for (int j = 0; j < height; ++j) {
            uint8_t* dr = d;
            for (int i = 0; i < width; ++i) {
                uint16_t rgb =
#if !TINT_BIG_ENDIAN
                    uint16_t(dr[0]) << 8 | uint16_t(dr[1]);
#else
                    uint16_t(dr[1]) << 8 | uint16_t(dr[0]);
#endif
                float r = (rgb >> 11) / 31.f;
                float g = ((rgb >> 5) & 0x3f) / 63.f;
                float b = (rgb & 0x1f) / 31.f;
                r = tintR(r);
                b = tintB(b);
                g = tintG(g);
                rgb = uint16_t(r * 31) << 11 | (uint16_t(g * 63) & 0x3f) << 5 | (uint16_t(b * 31) & 0x1f);
                uint8_t* rgbp = reinterpret_cast<uint8_t*>(&rgb);
#if !TINT_BIG_ENDIAN
                dr[0] = rgbp[0];
                dr[1] = rgbp[1];
#else
                dr[0] = rgbp[1];
                dr[1] = rgbp[0];
#endif
                dr += 2;
            }
            d += stride;
        }
    }

    void tintRGBA5551(TAK::Engine::Renderer::BitmapPtr& bmp) {
        const size_t stride = bmp->getStride();
        const size_t width = bmp->getWidth();
        const size_t height = bmp->getHeight();
        uint8_t *d = bmp->getData();
        for (int j = 0; j < height; ++j) {
            uint8_t* dr = d;
            for (int i = 0; i < width; ++i) {
                uint16_t rgb =
#if !TINT_BIG_ENDIAN
                    uint16_t(dr[0]) << 8 | uint16_t(dr[1]);
#else
                    uint16_t(dr[1]) << 8 | uint16_t(dr[0]);
#endif
                float r = (rgb >> 11) / 31.f;
                float g = ((rgb >> 6) & 0x1f) / 31.f;
                float b = (rgb & 0x1f) / 31.f;
                r = tintR(r);
                b = tintB(b);
                g = tintG(g);
                rgb = uint16_t(r * 31) << 11 | (uint16_t(g * 31) & 0x1f) << 6 | (uint16_t(b * 31) & 0x1f) << 1;
                uint8_t* rgbp = reinterpret_cast<uint8_t*>(&rgb);
#if !TINT_BIG_ENDIAN
                dr[0] = rgbp[0];
                dr[1] = rgbp[1];
#else
                dr[0] = rgbp[1];
                dr[1] = rgbp[0];
#endif
                dr += 2;
            }
            d += stride;
        }
    }

    void tintBGRA32(TAK::Engine::Renderer::BitmapPtr& bmp) {
        applyTintByteAligned<
#if !TINT_BIG_ENDIAN
        2, 1, 0,
#else
        1, 2, 3,
#endif
        4>(bmp->getData(), bmp->getWidth(), bmp->getHeight(), bmp->getStride());
    }

    void tintBGR24(TAK::Engine::Renderer::BitmapPtr& bmp) {
        applyTintByteAligned<
#if !TINT_BIG_ENDIAN
        2, 1, 0,
#else
        0, 1, 2,
#endif
        3>(bmp->getData(), bmp->getWidth(), bmp->getHeight(), bmp->getStride());
    }
}

Util::TAKErr TAK::Engine::Raster::TileMatrix::TileScraper_create(TileScraperPtr &value, std::shared_ptr<TileMatrix> client, 
    std::shared_ptr<TileContainer> sink, const CacheRequest &request, std::shared_ptr<CacheRequestListener> callback)
{
    bool ro;
    Util::TAKErr code = sink->isReadOnly(&ro);
    if (code != Util::TE_Ok || ro)
        return Util::TE_InvalidArg;
    
    std::unique_ptr<CacheRequest> req(new CacheRequest(request));
    std::unique_ptr<TileScraper::ScrapeContext> ctx;
    code = TileScraper::ScrapeContext::create(ctx, client.get(), sink.get(), req.get());
    TE_CHECKRETURN_CODE(code);
    TileScraperPtr ret(new TileScraper(std::move(ctx), client, sink, std::move(req), callback), Util::Memory_deleter_const<TileScraper>);
    value = std::move(ret);
    return Util::TE_Ok;
}

TileScraper::TileScraper(std::unique_ptr<ScrapeContext> ctx, std::shared_ptr<TileMatrix> client,
    std::shared_ptr<TileContainer> sink, std::unique_ptr<CacheRequest> request, std::shared_ptr<CacheRequestListener> callback) :
    client(client),
    sink(sink),
    request(std::move(request)),
    callback(callback),
    scrapeContext(std::move(ctx)),
    downloader()
{
}

int TileScraper::getTotalTiles()
{
    return scrapeContext->getTotalTiles();
}
void TileScraper::getTilesDownloaded(int& tilesDownloaded, std::size_t& bytesDownloaded)
{
    tilesDownloaded = scrapeContext->getNumTilesDownloaded();
    bytesDownloaded = scrapeContext->getBytesDownloaded();
}


TileScraper::~TileScraper()
{
    downloader.reset();
}

void TileScraper::run() {
    if(request->maxThreads > 1)
        downloader = std::unique_ptr<Downloader>(new TileScraper::MultiThreadDownloader(callback, request->maxThreads));
    else
        downloader = std::unique_ptr<Downloader>(new TileScraper::LegacyDownloader(callback));

    downloader->download(scrapeContext);

    //MultiThreadDownloader may have outstanding threads
    downloader->stop();
}

void TileScraper::cancel()
{
    scrapeContext->isCanceled = true;
}

Util::TAKErr TAK::Engine::Raster::TileMatrix::TileScraper_estimateTileCount(int &value, TileClient *client, CacheRequest *request)
{
    std::unique_ptr<TileScraper::ScrapeContext> v;
    TileScraper::ScrapeContext::create(v, client, nullptr, request);
    value = v->totalTiles;
    return Util::TE_Ok;
}

/**************************************************************************/

TileScraper::TilePoint::TilePoint(int row, int column) : r(row), c(column)
{
}


/**************************************************************************/

TileScraper::DownloadTask::DownloadTask(std::shared_ptr<ScrapeContext> context, size_t tileZ, size_t tileX, size_t tileY) : context(context), tileX(tileX), tileY(tileY), tileZ(tileZ)
{
}


Util::TAKErr TileScraper::DownloadTask::run()
{
    bool success = false;
    Util::TAKErr err = Util::TE_Ok;

    // attempt to download the tile
    int attempts = 0;

    bool doDownload = true;
    if (context->request->skipUnexpiredTiles)
    {
        int64_t expiration(-1LL);
        expiration = this->context->sink->getTileExpiration(this->tileZ, this->tileX, this->tileY);
        // not expired, no fetch required
        if (expiration >= defaultExpiry())
            doDownload = false;
    }

    size_t len = 0;
    while (doDownload && attempts < DOWNLOAD_ATTEMPTS) {

        // clear the error for the attempt
        err = Util::TE_Ok;
        // load the tile
        std::unique_ptr<const uint8_t, void(*)(const uint8_t *)> d(NULL, NULL);
        err = this->context->client->getTileData(d, &len, this->tileZ, this->tileX, this->tileY);

        if (err == Util::TE_Ok && d.get() != nullptr) {

            TAK::Engine::Renderer::BitmapPtr bitmap(nullptr, nullptr);
            if (context->debugTint) {
                TAK::Engine::Renderer::BitmapFactory2_decode(bitmap, d.get(), len, nullptr);
            }

            // valid entry in cache
            if (bitmap) {
                // have a bitmap only only when debugTint == true, but check in case that changes
                if (context->debugTint)
                    TileScraper_applyDebugTint(bitmap);
                this->context->sink->setTile(this->tileZ, this->tileX, this->tileY, bitmap.get(),
                                             TAK::Engine::Port::Platform_systime_millis() +
                                             context->request->expirationOffset);
            } else {
                this->context->sink->setTile(this->tileZ, this->tileX, this->tileY, d.get(), len,
                                             TAK::Engine::Port::Platform_systime_millis() +
                                             context->request->expirationOffset);
            }
            success = true;
            break;
        } else if (err == Util::TE_Ok) {
            // there was no exception raised during which means that
            // the client is unable to download
            break;
        } else {
            attempts++;
        }
    }

    // set the error if necessary
    this->context->downloadError |= (err != Util::TE_Ok);
    this->context->downloadComplete(success, len);
    return err;
}

/**************************************************************************/

Util::TAKErr TileScraper::ScrapeContext::create(std::unique_ptr<TileScraper::ScrapeContext>& v, TileMatrix* client, TileContainer* container, CacheRequest* request)
{
    std::unique_ptr<TileScraper::ScrapeContext> ret(new ScrapeContext(client, container, request));
    Util::TAKErr code = Util::TE_Ok;

    Port::STLVectorAdapter<TileMatrix::ZoomLevel> pcZoom(ret->zooms);
    code = client->getZoomLevel(pcZoom);
    TE_CHECKRETURN_CODE(code);

    std::map<int, bool> lvlArray;
    for (std::size_t i = 0u; i < ret->zooms.size(); i++) {
        if (ret->zooms[i].resolution <= request->minResolution
            && ret->zooms[i].resolution >= request->maxResolution)
            lvlArray[ret->zooms[i].level] = true;
    }
    if (lvlArray.size() == 0)
        lvlArray[ret->zooms[ret->zooms.size() - 1].level] = true;

    // NOTE: order of 'keyAt' is guaranteed to be ascending
    for (auto iter = lvlArray.begin(); iter != lvlArray.end(); ++iter)
        ret->levels.push_back(iter->first);

    if (ret->levels.size() > 0) {
        ret->minLevel = ret->levels[0];
        ret->maxLevel = ret->levels[ret->levels.size() - 1];
    }

    Feature::Geometry2Ptr_const geo(NULL, NULL);
    code = Feature::GeometryTransformer_transform(geo, *(request->region), 4326, client->getSRID());
    TE_CHECKRETURN_CODE(code);

    code = ret->getTiles(geo.get());
    TE_CHECKRETURN_CODE(code);

    ret->isCanceled = false;
    
    v = std::move(ret);

    return Util::TE_Ok;
}
Util::TAKErr TileScraper::ScrapeContext::getTiles(const Feature::Geometry2*geo)
{
    Feature::Envelope2 env;
    Util::TAKErr code = geo->getEnvelope(&env);
    TE_CHECKRETURN_CODE(code);

    // Convert geometry to Vector2D for use with intersection math
    std::shared_ptr<Feature::LineString2> ls_shared(nullptr);
    Feature::LineString2 *ls = nullptr;
    Feature::Point2* p = nullptr;
    if (geo->getClass() == Feature::GeometryClass::TEGC_LineString)
        ls = (Feature::LineString2 *) geo;
    else if (geo->getClass() == Feature::GeometryClass::TEGC_Polygon) {
        code = ((Feature::Polygon2 *) geo)->getExteriorRing(ls_shared);
        TE_CHECKRETURN_CODE(code);
        ls = ls_shared.get();
    }
    else if (geo->getClass() == Feature::GeometryClass::TEGC_Point) {
        p = (Feature::Point2*)geo;
    }
    else if (geo->getClass() == Feature::GeometryClass::TEGC_GeometryCollection) {
        Feature::GeometryCollection2* collection = (Feature::GeometryCollection2*) geo;
        for (int i = 0; i < collection->getNumGeometries(); ++i) {
            std::shared_ptr<Feature::Geometry2> geom;
            collection->getGeometry(geom, i);
            code = getTiles(geom.get());
            TE_CHECKRETURN_CODE(code);
        }
        return Util::TE_Ok;
    }

    std::vector< Math::Point2<double>> points;
    if (ls != nullptr) {
        for (size_t i = 0; i < ls->getNumPoints(); ++i) {
            double x, y;
            code = ls->getX(&x, i);
            TE_CHECKRETURN_CODE(code);
            code = ls->getY(&y, i);
            TE_CHECKRETURN_CODE(code);
            points.push_back(Math::Point2<double>(x, y));
        }
    }
    else if (p != nullptr) {
        points.push_back(Math::Point2<double>(p->x, p->y));
    }
    bool closed = points[0].x == points[points.size() - 1].x
        && points[0].y == points[points.size() - 1].y;

    // Scan for intersecting tiles
    Math::Point2<double> minTile;
    Math::Point2<double> maxTile;
    code = TileMatrix_getTileIndex(&minTile, *client, 0, env.minX, env.maxY);
    TE_CHECKRETURN_CODE(code);
    code = TileMatrix_getTileIndex(&maxTile, *client, 0, env.maxX, env.minY);
    TE_CHECKRETURN_CODE(code);

    for (int r = (int)minTile.y; r <= (int)maxTile.y; r++)
        for (int c = (int)minTile.x; c <= (int)maxTile.x; c++)
            getTiles(c, r, 0, maxLevel, points, closed);


    return Util::TE_Ok;
}


TileScraper::ScrapeContext::ScrapeContext(TileMatrix *client, TileContainer *container, CacheRequest *request) : 
    client(client), sink(container), request(request), uri(client->getName()),
    levels(), currentLevelIdx(0), totalTilesCurrentLevel(0), totalTiles(0),
    downloadError(false), tilesDownloaded(0),
    tiles(), minLevel(0), maxLevel(0), zooms(),
    bytesDownloaded(0), tp {
        Math::Point2<double>(0, 0),
        Math::Point2<double>(0, 0),
        Math::Point2<double>(0, 0),
        Math::Point2<double>(0, 0),
    },
    tmpSeg {
        Math::Point2<double>(0, 0),
        Math::Point2<double>(0, 0),
        Math::Point2<double>(0, 0),
    },
    debugTint(false)
{
}

void TileScraper::ScrapeContext::getTiles(int col, int row, int level, int max, const std::vector<Math::Point2<double>>& points, bool closed)
{
    if (level > max || this->totalTiles >= MAX_TILES)
        return;

    TileMatrix::ZoomLevel &zoom = this->zooms[level];

    // Get tile points for checking intersection
    getSourcePoint(this->tp + 0, zoom, col, row);
    getSourcePoint(this->tp + 1, zoom, col + 1, row);
    getSourcePoint(this->tp + 2, zoom, col + 1, row + 1);
    getSourcePoint(this->tp + 3, zoom, col, row + 1);

    // Intersects or contains
    bool add = Math::Vector2_polygonContainsPoint(points[0], this->tp, 4);
    if (!add) {
        bool breakOuter = false;
        for (int i = 0; i < 4 && !breakOuter; i++) {
            const Math::Point2<double> &s = this->tp[i];
            const Math::Point2<double> &e = this->tp[i == 3 ? 0 : i + 1];
            for (std::size_t j = 0u; j < points.size() - 1; j++) {
                if (segmentIntersects(s, e, points[j], points[j + 1])) {
                    add = true;

                    breakOuter = true;
                    break;
                }
            }
        }
        if (!add && closed)
            add = Math::Vector2_polygonContainsPoint(this->tp[0], &points[0], points.size());
    }

    if (add) {
        // Add this tile
        if (level >= this->minLevel && level <= this->maxLevel) {
            if (!this->request->countOnly) {
                auto iter = this->tiles.find(level);
                if (iter == this->tiles.end()) {
                    this->tiles[level] = std::list<TileScraper::TilePoint>();
                    iter = this->tiles.insert(std::pair<int, std::list<TileScraper::TilePoint>>(level, std::list<TileScraper::TilePoint>())).first;
                }
                iter->second.push_back(TilePoint(row, col));
            }
            this->totalTiles++;
        }


        // Check sub-tiles
        row *= 2;
        col *= 2;
        for (int r = row; r <= row + 1; r++)
            for (int c = col; c <= col + 1; c++)
                getTiles(c, r, level + 1, max, points, closed);
    }
}

bool TileScraper::ScrapeContext::segmentIntersects(Math::Point2<double> seg10,
    Math::Point2<double> seg11,
    Math::Point2<double> seg01,
    Math::Point2<double> seg00)
{
    tmpSeg[0].x = seg01.x - seg00.x;
    tmpSeg[0].y = seg01.y - seg00.y;
    tmpSeg[1].x = seg11.x - seg10.x;
    tmpSeg[1].y = seg11.y - seg10.y;
    Math::Point2<double> c;
    Math::Vector2_cross(&c, tmpSeg[1], tmpSeg[0]);
    double c1 = c.z;
    if (c1 != 0.0) {
        tmpSeg[2].x = seg00.x - seg10.x;
        tmpSeg[2].y = seg00.y - seg10.y;
        Math::Vector2_cross(&c, tmpSeg[2], tmpSeg[0]);
        double t = c.z / c1;
        Math::Vector2_cross(&c, tmpSeg[2], tmpSeg[1]);
        double u = c.z / c1;
        return t >= 0 && t <= 1 && u >= 0 && u <= 1;
    }
    return false;
}

void TileScraper::ScrapeContext::getSourcePoint(Math::Point2<double> *v, const TileMatrix::ZoomLevel &z,
    int c, int r)
{
    v->x = client->getOriginX() + (c * z.pixelSizeX * z.tileWidth);
    v->y = client->getOriginY() - (r * z.pixelSizeY * z.tileHeight);
}

void TileScraper::ScrapeContext::downloadComplete(bool success, std::size_t downloadSize)
{
    Thread::Lock lock(this->mutex);
    if (success) {
        this->tilesDownloaded++;
        this->bytesDownloaded += downloadSize;
    }
    else {
        this->downloadError = true;
    }
}


void TileScraper::ScrapeContext::downloadComplete(bool success)
{
    downloadComplete(success, 0);
}

bool TileScraper::ScrapeContext::hadDownloadError() {
    Thread::Lock lock(this->mutex);
    return this->downloadError;
}

int TileScraper::ScrapeContext::getNumTilesDownloaded() {
    Thread::Lock lock(this->mutex);
    return this->tilesDownloaded;
}

std::size_t TileScraper::ScrapeContext::getBytesDownloaded() {
    Thread::Lock lock(this->mutex);
    return this->bytesDownloaded;
}

int TileScraper::ScrapeContext::getTotalTiles()
{
    Thread::Lock lock(this->mutex);
    return this->totalTiles;
}

/**************************************************************************/

TileScraper::Downloader::Downloader(std::shared_ptr<CacheRequestListener> callback) : callback(callback), levelStartTiles(0)
{
}

TileScraper::Downloader::~Downloader()
{
}

void TileScraper::Downloader::reportStatus(std::shared_ptr<ScrapeContext> downloadContext)
{
    const int numDownload = downloadContext->getNumTilesDownloaded();

    if (callback.get() != nullptr) {
        callback->onRequestProgress(downloadContext->currentLevelIdx,
            (int)downloadContext->levels.size(),
            numDownload - this->levelStartTiles,
            downloadContext->totalTilesCurrentLevel,
            numDownload,
            downloadContext->totalTiles);
    }            
}

void TileScraper::Downloader::onDownloadEnter(std::shared_ptr<ScrapeContext> context)
{
}

void TileScraper::Downloader::onDownloadExit(std::shared_ptr<ScrapeContext> context, int jobStatus)
{
}

bool TileScraper::Downloader::checkReadyForDownload(std::shared_ptr<ScrapeContext> context)
{
    return true;
}

void TileScraper::Downloader::onLevelDownloadComplete(std::shared_ptr<ScrapeContext> context)
{
}

void TileScraper::Downloader::onLevelDownloadStart(std::shared_ptr<ScrapeContext> context)
{
}

bool TileScraper::Downloader::download(std::shared_ptr<ScrapeContext> downloadContext)
{
    Util::Logger_log(Util::LogLevel::TELL_Debug, "%s Starting download of %s cache...", TAG, downloadContext->client->getName());

    if (callback.get() != nullptr)
        callback->onRequestStarted();

    reportStatus(downloadContext);

    this->onDownloadEnter(downloadContext);

    Util::TAKErr code = Util::TE_Ok;
    for (std::size_t l = 0u; code == Util::TE_Ok && l < downloadContext->levels.size(); l++) {
        downloadContext->currentLevelIdx = static_cast<int>(l);
        int currentLevel = downloadContext->levels[l];

        TileMatrix::ZoomLevel zoom;
        Util::TAKErr zoomCode = TileMatrix_findZoomLevel(&zoom, *(downloadContext->client), currentLevel);
        int tile180X = (zoomCode == Util::TE_Ok) ? (int) ((downloadContext->client->getOriginX() * -2)
            / (zoom.pixelSizeX * zoom.tileWidth)) : -1;

        auto tilesListIter = downloadContext->tiles.find(downloadContext->levels[l]);
        auto tiles = tilesListIter->second;
        downloadContext->totalTilesCurrentLevel = (int)tiles.size();
        this->levelStartTiles = downloadContext->getNumTilesDownloaded();

        this->onLevelDownloadStart(downloadContext);

        for (auto tilesIter = tiles.begin(); tilesIter != tiles.end(); ++tilesIter) {
            while (true) {
                // check for error
                if (downloadContext->hadDownloadError()) {
                    if (callback.get() != nullptr)
                        callback->onRequestError(nullptr, true);

                    Util::Logger_log(Util::LogLevel::TELL_Debug, "%s Lost network connection during map download.", TAG);

                    return false;
                } else
                    // check for cancel
                    if (downloadContext->request->canceled || downloadContext->isCanceled) {
                    if (callback.get() != nullptr)
                            callback->onRequestCanceled();
                        return false;
                    }

                // report status
                this->reportStatus(downloadContext);

                // check if we should sleep for a little bit
                // before proceeding to initiate download of
                // the next tile
                if (!this->checkReadyForDownload(downloadContext)) {
                    Thread::Thread_sleep(50);
                    continue;
                }

                // proceed to download
                break;
            }

            int tileX = tilesIter->c;
            int tileY = tilesIter->r;

            // download
            if (tile180X > -1 && tilesIter->c >= tile180X)
            {
                tileX = tilesIter->c - tile180X;
            }

            bool doDownload = true;
            if (downloadContext->request->skipUnexpiredTiles)
            {
                int64_t expiration(-1LL);
                expiration = downloadContext->sink->getTileExpiration(currentLevel, tileX, tileY);
                // not expired, no fetch required
                if (expiration >= defaultExpiry())
                    doDownload = false;;
            }

            if(doDownload)
                code = downloadTileImpl(downloadContext, currentLevel, tileX, tileY);

            this->onLevelDownloadComplete(downloadContext);

            if (downloadContext->request->maxDownloadBytes && downloadContext->getBytesDownloaded() > downloadContext->request->maxDownloadBytes)
                break;
        }
    }

    bool retval;
    if (code == Util::TE_Ok) {
        if (callback.get() != nullptr)
            callback->onRequestComplete();
        retval = true;
    } else {
        Util::Logger_log(Util::LogLevel::TELL_Error, "%s Error while trying to download from %s", TAG, downloadContext->uri.c_str());
        retval = false;
    }
    this->onDownloadExit(downloadContext, 0);
    return retval;
}


TileScraper::MultiThreadDownloader::MultiThreadDownloader(std::shared_ptr<CacheRequestListener> callback, int numDownloadThreads) : 
    Downloader(callback), queue(), shutdown(false), terminate(false), queueMonitor(), poolSize(numDownloadThreads), pool(NULL, NULL)
{
    Thread::ThreadPool_create(pool, poolSize, TileScraper::MultiThreadDownloader::threadEntry, this);
}

void TileScraper::MultiThreadDownloader::stop()
{
    {
        Thread::Monitor::Lock mLock(queueMonitor);
        terminate = true;
        mLock.broadcast();
    }
    pool->joinAll();

}
TileScraper::MultiThreadDownloader::~MultiThreadDownloader()
{
    stop();
}

void TileScraper::MultiThreadDownloader::flush(std::shared_ptr<ScrapeContext> context, bool reportStatus)
{
    // wait for queue to empty 
    while (this->queue.size() > 0) {
        // check for cancel
        if (context->request->canceled || context->isCanceled)
            break;

        Thread::Thread_sleep(50);

        // report status
        if (reportStatus)
            this->reportStatus(context);
    }
}

void TileScraper::MultiThreadDownloader::onDownloadExit(std::shared_ptr<ScrapeContext> context, int jobStatus)
{
    this->flush(context, false);
    {
        Thread::Monitor::Lock mLock(queueMonitor);
        shutdown = true;
        mLock.broadcast();
    }
}

bool TileScraper::MultiThreadDownloader::checkReadyForDownload(std::shared_ptr<ScrapeContext> context)
{
    Thread::Monitor::Lock mLock(queueMonitor);
    return (this->queue.size() < (3u * static_cast<std::size_t>(poolSize)));
}

void TileScraper::MultiThreadDownloader::onLevelDownloadComplete(std::shared_ptr<ScrapeContext> context) {
    this->flush(context, true);
}

Util::TAKErr TileScraper::MultiThreadDownloader::downloadTileImpl(std::shared_ptr<ScrapeContext> context, int tileLevel,
                int tileX, int tileY)
{
    Thread::Monitor::Lock mLock(queueMonitor);
    queue.push_back(std::unique_ptr<DownloadTask>(new DownloadTask(context, tileLevel, tileX, tileY)));
    mLock.broadcast();
    return Util::TE_Ok;
}

void *TileScraper::MultiThreadDownloader::threadEntry(void *selfPtr)
{
    TileScraper::MultiThreadDownloader *self = (TileScraper::MultiThreadDownloader *)selfPtr;
    self->threadRun();
    return nullptr;
}

void TileScraper::MultiThreadDownloader::threadRun()
{
    while (true) {
        std::unique_ptr<DownloadTask> task;
        {
            Thread::Monitor::Lock mLock(queueMonitor);
            if (terminate)
                break;
            if (queue.empty()) {
                if (shutdown)
                    break;
                mLock.wait();
                continue;
            }
            task = std::move(queue.front());
            queue.pop_front();
        }
        task->run();
        task.reset();
    }
}



TileScraper::LegacyDownloader::LegacyDownloader(std::shared_ptr<CacheRequestListener> callback) : Downloader(callback)
{
}

TileScraper::LegacyDownloader::~LegacyDownloader()
{
}

Util::TAKErr TileScraper::LegacyDownloader::downloadTileImpl(std::shared_ptr<ScrapeContext> context, int tileLevel,
                int tileX, int tileY)
{
    DownloadTask t(context, tileLevel, tileX, tileY);
    return t.run();
}

Util::TAKErr TAK::Engine::Raster::TileMatrix::TileScraper_enableDebugTint(TileScraper& scraper) NOTHROWS {
    scraper.scrapeContext->debugTint = true;
    return Util::TE_Ok;
}


Util::TAKErr TAK::Engine::Raster::TileMatrix::TileScraper_applyDebugTint(TAK::Engine::Renderer::BitmapPtr& bmp) NOTHROWS {

    using namespace TAK::Engine::Renderer;
    Bitmap2::Format fmt = bmp->getFormat();

    switch (fmt) {
        case Bitmap2::ARGB32: tintARGB32(bmp); break;
        case Bitmap2::RGBA32: tintRGBA32(bmp); break;
        case Bitmap2::RGB24: tintRGB24(bmp); break;
        case Bitmap2::RGB565: tintRGB565(bmp); break;
        case Bitmap2::RGBA5551: tintRGBA5551(bmp); break;
        case Bitmap2::BGRA32: tintBGRA32(bmp); break;
        case Bitmap2::BGR24: tintBGR24(bmp); break;
        default:
            // XXX- if needed, could convert to RGB and tint
            return Util::TE_Unsupported;
    }

    return Util::TE_Ok;
}
