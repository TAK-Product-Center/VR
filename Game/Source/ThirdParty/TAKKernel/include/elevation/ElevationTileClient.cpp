#include "elevation/ElevationTileClient.h"

#include <cmath>
#include <limits>
#include <set>

#include "renderer/core/ContentControl.h"
#include "elevation/ElevationChunkFactory.h"
#include "elevation/ElevationManager.h"
#include "elevation/ElevationSourceManager.h"
#include "raster/osm/OSMUtils.h"
#include "thread/Lock.h"
#include "thread/Mutex.h"
#include "util/DataInput2.h"
#include "util/IO2.h"
#include "util/MathUtils.h"
#include "util/MemBuffer2.h"
#include "util/Memory.h"

using namespace TAK::Engine::Elevation;

using namespace TAK::Engine::Core;
using namespace TAK::Engine::Feature;
using namespace TAK::Engine::Raster::TileMatrix;
using namespace TAK::Engine::Renderer::Core;
using namespace TAK::Engine::Thread;
using namespace TAK::Engine::Util;

namespace
{
    class ContentControlImpl : public ContentControl,
                               public ElevationSourcesChangedListener,
                               public ElevationSource::OnContentChangedListener
    {
    private :
        struct SubscribeOnContentChangedListenerBundle
        {
            ElevationSource::OnContentChangedListener *listener {nullptr};
            Mutex *mutex {nullptr};
            std::set<ElevationSource *> *sources {nullptr};
        };
    public :
        ContentControlImpl(ElevationSource *source) NOTHROWS;
        ~ContentControlImpl() NOTHROWS;
    public : // ContentControl
        TAKErr addOnContentChangedListener(ContentControl::OnContentChangedListener* l) NOTHROWS override;
        TAKErr removeOnContentChangedListener(ContentControl::OnContentChangedListener *l) NOTHROWS override;
    public : // ElevationSource::OnContentChangedListener
        TAKErr onContentChanged(const ElevationSource &source) NOTHROWS override;
    public : // ElevationSourcesChangedListener
        TAKErr onSourceAttached(const std::shared_ptr<ElevationSource> &src) NOTHROWS override;
        TAKErr onSourceDetached(const ElevationSource &src) NOTHROWS override;
    private :
        static TAKErr subscribeOnContentChangedListener(void* opaque, ElevationSource& src) NOTHROWS;
    private :
        Mutex mutex;
        std::set<ContentControl::OnContentChangedListener*> listeners;
        std::set<ElevationSource *> sources;
    };

    std::size_t getQuantizationBits(const double range, const double precision) NOTHROWS;
    TAKErr encodeHeightmap(uint8_t* data, std::size_t *len, const HeightmapParams& params, const double gsd) NOTHROWS;
    TAKErr decodeHeightmap(ElevationChunkPtr& value, const std::shared_ptr<const uint8_t>& data, const std::size_t dataLen) NOTHROWS;
    TAKErr getRegionTiles(TAK::Engine::Math::Point2<std::size_t>* min, TAK::Engine::Math::Point2<std::size_t>* max, const TAK::Engine::Math::Point2<double>& matrixOrigin, const TAK::Engine::Raster::TileMatrix::TileMatrix::ZoomLevel& zoom, const Envelope2& region) NOTHROWS;

    constexpr std::size_t encodedHeightmapHeaderLen = 4u + sizeof(HeightmapParams);

    constexpr std::size_t encodedHeightmapHeaderLen_v3 = 4u +
        // HeightmapParams
        6u * 8u + // bounds
        2u + 2u + // num posts
        4u; // invert Y axis
}

ElevationTileClient::ElevationTileClient(const HeightmapParams &params) NOTHROWS :
    ElevationTileClient(params, 1u)
{}
ElevationTileClient::ElevationTileClient(const HeightmapParams &params, const std::size_t overlap_) NOTHROWS :
    ElevationTileClient(std::shared_ptr<ElevationSource>(), 4326, params, overlap_)
{}
ElevationTileClient::ElevationTileClient(const std::shared_ptr<ElevationSource> &source_, const int srid_, const HeightmapParams &params, const std::size_t overlap_, const bool forcePointsSample_) NOTHROWS :
    source(source_),
    srid(srid_),
    forcePointSample(forcePointsSample_),
    heightmapParams(params),
    overlap(overlap_),
    // observed max simultaenous block drawdown is 7, block allocate approximately 2X observed max
    tileDataAllocator(std::max(encodedHeightmapHeaderLen, encodedHeightmapHeaderLen_v3)+(params.numPostsLat+(overlap*2u))*(params.numPostsLng+(overlap*2u))*sizeof(double), 16u)
{
    constexpr auto maxZoom = 21u;
    zoomLevels_v.reserve(maxZoom);
    // XXX - implement SRIDs
    srid = 4326;
    for(auto zoom = 0u; zoom < maxZoom; zoom++) {
        TileMatrix::ZoomLevel level;
        level.tileWidth = (int)heightmapParams.numPostsLng;
        level.tileHeight = (int)heightmapParams.numPostsLat;
        level.resolution = atakmap::raster::osm::OSMUtils::mapnikTileResolution((int)zoom);
        level.pixelSizeX = (180.0 / (double)(1u<<zoom)) / (double)level.tileWidth;
        level.pixelSizeY = (180.0 / (double)(1u<<zoom)) / (double)level.tileHeight;
        level.level = (int)zoom;
        zoomLevels_v.push_back(level);
    }
    zoomLevels.count = zoomLevels_v.size();
    zoomLevels.value = zoomLevels_v.data();

    // Controls
    {
        controls.content = std::unique_ptr<ContentControl, void(*)(const ContentControl *)>(new ContentControlImpl(source.get()), Memory_deleter_const<ContentControl, ContentControlImpl>);
        Control ctrl;
        ctrl.type = ContentControl_getType();
        ctrl.value = controls.content.get();
        controls.value.push_back(ctrl);
    }
}
ElevationTileClient::~ElevationTileClient() NOTHROWS
{}

TAKErr ElevationTileClient::clearAuthFailed() NOTHROWS
{
    return TE_Ok;
}
TAKErr ElevationTileClient::checkConnectivity() NOTHROWS
{
    return TE_Ok;
}
TAKErr ElevationTileClient::cache(const CacheRequest &request, std::shared_ptr<CacheRequestListener> &listener) NOTHROWS
{
    return TE_NotImplemented;
}
TAKErr ElevationTileClient::estimateTilecount(int *count, const CacheRequest &request) NOTHROWS
{
    return TE_NotImplemented;
}
const char* ElevationTileClient::getName() const NOTHROWS
{
    return "ElevationManager";
}
int ElevationTileClient::getSRID() const NOTHROWS
{
    return srid;
}
TAKErr ElevationTileClient::getZoomLevel(Port::Collection<TileMatrix::ZoomLevel>& value) const NOTHROWS
{
    for(std::size_t i = 0u; i < zoomLevels.count; i++)
        value.add(zoomLevels.value[i]);
    return TE_Ok;
}
double ElevationTileClient::getOriginX() const NOTHROWS
{
    // XXX - srid
    return -180.0;
}
double ElevationTileClient::getOriginY() const NOTHROWS
{
    // XXX - srid
    return 90.0;
}
TAKErr ElevationTileClient::getTile(Renderer::BitmapPtr& result, const std::size_t zoom, const std::size_t x, const std::size_t y) NOTHROWS
{
    return TE_NotImplemented;
}
TAKErr ElevationTileClient::getTileData(std::unique_ptr<const uint8_t, void (*)(const uint8_t*)>& value, std::size_t* len,
                                 const std::size_t zoom, const std::size_t x, const std::size_t y) NOTHROWS
{
    TAKErr code(TE_Ok);
    if(zoom > zoomLevels.count)
        return TE_InvalidArg;

    const auto zoomLevel = zoomLevels.value[zoom];

    // XXX - srid
    const double tileSize = 180.0 / (double)(1u<<zoom);
    const double cellSizeLat = tileSize / (zoomLevel.tileHeight - 1);
    const double cellSizeLng = tileSize / (zoomLevel.tileWidth - 1);

    HeightmapParams tileDataParams(heightmapParams);
    tileDataParams.numPostsLat = zoomLevel.tileHeight + 2*overlap;
    tileDataParams.numPostsLng = zoomLevel.tileWidth + 2*overlap;
    tileDataParams.bounds.minX = -180.0 + (x * tileSize) - (overlap*cellSizeLng);
    tileDataParams.bounds.minY = 90.0 - ((y + 1) * tileSize) - (overlap*cellSizeLat);
    tileDataParams.bounds.maxX = -180.0 + ((x + 1) * tileSize) + (overlap*cellSizeLng);
    tileDataParams.bounds.maxY = 90.0 - (y * tileSize) + (overlap*cellSizeLat);
    std::unique_ptr<uint8_t, void(*)(const uint8_t*)> heightmap(nullptr, nullptr);
    code = tileDataAllocator.allocate<uint8_t>(heightmap, true);
    TE_CHECKRETURN_CODE(code);

    memcpy(heightmap.get(), &tileDataParams, sizeof(HeightmapParams));
    const double gsd = atakmap::raster::osm::OSMUtils::mapnikTileResolution((int)zoom);
    double* els = reinterpret_cast<double*>(heightmap.get() + encodedHeightmapHeaderLen_v3);
    code = createHeightmap(els, gsd, tileDataParams);
    if(code == TE_Done)
        code = TE_Ok;
    TE_CHECKRETURN_CODE(code);
    tileDataParams.bounds.minZ = els[0u];
    tileDataParams.bounds.maxZ = els[0u];
    for (std::size_t i = 1u; i < (tileDataParams.numPostsLat * tileDataParams.numPostsLng); i++) {
        if(TE_ISNAN(tileDataParams.bounds.minZ) || els[i] < tileDataParams.bounds.minZ)
            tileDataParams.bounds.minZ = els[i];
        if(TE_ISNAN(tileDataParams.bounds.maxZ) || els[i] > tileDataParams.bounds.maxZ)
            tileDataParams.bounds.maxZ = els[i];
    }
    if(tileDataParams.bounds.minZ == tileDataParams.bounds.maxZ)
        tileDataParams.bounds.maxZ = tileDataParams.bounds.minZ+1.0;
    encodeHeightmap(heightmap.get(), len, tileDataParams, gsd);
    value = std::move(heightmap);
    return code;
}
TAKErr ElevationTileClient::getBounds(Envelope2 *value) const NOTHROWS
{
    if(!value)
        return TE_InvalidArg;
    // XXX - srid
    value->minX = -180.0;
    value->minY = -90.0;
    value->maxX = 180.0;
    value->maxY = 90.0;
    return TE_Ok;
}
TAKErr ElevationTileClient::getControl(Control* value, const char* controlName) NOTHROWS
{
    for(const auto &ctrl : controls.value) {
        if(TAK::Engine::Port::String_equal(controlName, ctrl.type)) {
            *value = ctrl;
            return TE_Ok;
        }
    }

    return TE_InvalidArg;
}
TAKErr ElevationTileClient::getControls(TAK::Engine::Port::Collection<Control> &value) NOTHROWS
{
    TAKErr code(TE_Ok);
    for(const auto &ctrl : controls.value) {
        code = value.add(ctrl);
        TE_CHECKBREAK_CODE(code);
    }
    TE_CHECKRETURN_CODE(code);

    return code;
}
TAKErr ElevationTileClient::createHeightmap(double *els, const double gsd, const HeightmapParams &tileDataParams) NOTHROWS
{
    return forcePointSample ?
           createHeightmapPoints(els, gsd, tileDataParams) :
           createHeightmapDefault(els, gsd, tileDataParams);
}
TAKErr ElevationTileClient::createHeightmapDefault(double *els, const double gsd, const HeightmapParams &tileDataParams) NOTHROWS
{
    if(source)
        return ElevationManager_createHeightmap(els, *source, gsd, tileDataParams, HeightmapStrategy::HighestResolution);
    else
        return ElevationManager_createHeightmap(els, gsd, tileDataParams, HeightmapStrategy::HighestResolution);
}
TAKErr ElevationTileClient::createHeightmapPoints(double *value, const double gsd, const HeightmapParams &params) NOTHROWS
{
    TAKErr code(TE_Ok);

    const auto count = (params.numPostsLat*params.numPostsLng);

    const double cellHeightLat = ((params.bounds.maxY - params.bounds.minY) / (params.numPostsLat - 1));
    const double cellWidthLng = ((params.bounds.maxX - params.bounds.minX) / (params.numPostsLng - 1));

    TAK::Engine::Feature::Point2 spatialFilter(NAN, NAN);
    ElevationSource::QueryParameters sourceParams;
    sourceParams.spatialFilter = Geometry2Ptr_const(&spatialFilter, Memory_leaker_const<Geometry2>);

    std::vector<double> ll;
    ll.resize(params.numPostsLat*params.numPostsLng*2u);

    //auto  ss = Platform_systime_millis();
    bool miss = false;
    std::size_t post = 0u;
    for (int postLat = 0; postLat < (int)params.numPostsLat; postLat++) {
        double ptLat = params.invertYAxis ?
                       params.bounds.minY + cellHeightLat * postLat :
                       params.bounds.maxY - cellHeightLat * postLat;
        // flip over pole if necessary
        if(ptLat > 90.0)
            ptLat = 180.0 - ptLat;
        else if(ptLat < -90.0)
            ptLat = -180.0 - ptLat;
        for (int postLng = 0; postLng < (int)params.numPostsLng; postLng++) {
            double ptLng = params.bounds.minX + cellWidthLng * postLng;
            // flip over anti-meridian if necessary
            if(ptLng < -180.0)
                ptLng += 360.0;
            else if(ptLng > 180.0)
                ptLng -= 360.0;

            ll[post*2u] = ptLat;
            ll[post*2u+1u] = ptLng;
            value[post] = NAN;
            post++;
        }
    }

    const auto limit = (params.numPostsLng*params.numPostsLat);
    for(std::size_t i = 0u; i < limit; i++) {
        spatialFilter.x = ll[i*2u+1u];
        spatialFilter.y = ll[i*2u];

        ElevationChunkCursorPtr result(nullptr, nullptr);
        const auto queryCode = source ?
            source->query(result, sourceParams) :
            ElevationManager_queryElevationSources(result, sourceParams);
        if(queryCode != TE_Ok)
            continue;
        do {
            code = result->moveToNext();
            if(code != TE_Ok)
                break;

            ElevationChunkPtr chunk(nullptr, nullptr);
            if(result->get(chunk) != TE_Ok)
                continue;
            // advance `i` as long as we are filling data from the current chunk
            for( ; i < limit; i++) {
                if(!TE_ISNAN(value[i]))
                    continue;
                if(chunk->sample(value+i, ll[i*2], ll[i*2+1]) != TE_Ok)
                    break;
            }
            // continue to attempt to populate the heightmap from the chunk
            for(std::size_t j = i; j < limit; j++) {
                if(!TE_ISNAN(value[j]))
                    continue;
                chunk->sample(value+j, ll[j*2], ll[j*2+1]);
            }
        } while(i < limit);
        if(code == TE_Done)
            code = TE_Ok;
        // `i` should always point to a value that was missed across all chunks
        if(i < limit) {
            miss |= TE_ISNAN(value[i]);
        }
    }
    //auto es = Platform_systime_millis();
    //Logger_log(TELL_Info, "createHeightmap P node@%d %ux%u in %ums", atakmap::raster::osm::OSMUtils::mapnikTileLevel(gsd), (unsigned)params.numPostsLng, (unsigned)params.numPostsLat, (unsigned)(es-ss));

    return miss ? TE_Done : TE_Ok;
}

ElevationTileMatrix TAK::Engine::Elevation::ElevationTileClient_info() NOTHROWS
{
    ElevationTileMatrix tilesDef;
    tilesDef.decodeTileData = decodeHeightmap;
    tilesDef.getRegionTileIndices = getRegionTiles;
    return tilesDef;
}

namespace
{

    template<class T>
    class QuantizedHeightmap : public Sampler
    {
    public:
        QuantizedHeightmap(const uint8_t version_, const std::shared_ptr<const uint8_t>& data_, const std::size_t off_, const HeightmapParams& params_) NOTHROWS :
            version(version_),
            data(data_),
            heightmap(reinterpret_cast<const T *>(data.get()+off_)),
            params(params_)
        {
            postSpacing.lng = (params.bounds.maxX - params.bounds.minX) / (double)(params.numPostsLng - 1u);
            postSpacing.lat = (params.bounds.maxY - params.bounds.minY) / (double)(params.numPostsLat - 1u);
        }
    public:
        TAKErr sample(double* value, const double latitude, const double longitude) NOTHROWS override
        {
            if (longitude < params.bounds.minX || longitude > params.bounds.maxX || latitude < params.bounds.minY || latitude > params.bounds.maxY)
                return TE_InvalidArg;
            const double postX = (longitude - params.bounds.minX) / postSpacing.lng;
            const double postY = params.invertYAxis ?
                (latitude - params.bounds.minY) / postSpacing.lat :
                (params.bounds.maxY - latitude) / postSpacing.lat;
            const std::size_t postT = (std::size_t)MathUtils_clamp(postY, 0.0, (double)params.numPostsLat - 1u);
            const std::size_t postB = (std::size_t)MathUtils_clamp(ceil(postY), 0.0, (double)params.numPostsLat - 1u);
            const std::size_t postL = (std::size_t)MathUtils_clamp(postX, 0.0, (double)params.numPostsLng - 1u);
            const std::size_t postR = (std::size_t)MathUtils_clamp(ceil(postX), 0.0, (double)params.numPostsLng - 1u);

            if(version == 1u) {
                *value = MathUtils_interpolate(
                        dequantize1(heightmap[(postT * params.numPostsLng) + postL]),
                        dequantize1(heightmap[(postT * params.numPostsLng) + postR]),
                        dequantize1(heightmap[(postB * params.numPostsLng) + postR]),
                        dequantize1(heightmap[(postB * params.numPostsLng) + postL]),
                        MathUtils_clamp(postX - (double) postL, 0.0, 1.0),
                        MathUtils_clamp(postY - (double) postT, 0.0, 1.0));
            } else {
                *value = MathUtils_interpolate(
                        dequantize2(heightmap[(postT * params.numPostsLng) + postL]),
                        dequantize2(heightmap[(postT * params.numPostsLng) + postR]),
                        dequantize2(heightmap[(postB * params.numPostsLng) + postR]),
                        dequantize2(heightmap[(postB * params.numPostsLng) + postL]),
                        MathUtils_clamp(postX - (double) postL, 0.0, 1.0),
                        MathUtils_clamp(postY - (double) postT, 0.0, 1.0));
            }
            return TE_ISNAN(*value) ? TE_Done : TE_Ok;
        }
    private :
        double dequantize1(const T v) NOTHROWS
        {
            const auto qmax = std::numeric_limits<T>::max();
            return (((double)v / (double)qmax) * (params.bounds.maxZ - params.bounds.minZ)) + params.bounds.minZ;
        }
        double dequantize2(const T v) NOTHROWS
        {
            const auto qmax = std::numeric_limits<T>::max();
            if(v == qmax)
                return NAN;
            return (((double)v / (double)(qmax-1u)) * (params.bounds.maxZ - params.bounds.minZ)) + params.bounds.minZ;
        }
    public :
        static void quantize(MemBuffer2 &dst, const double *elevations, const std::size_t count, const double min, const double max) NOTHROWS
        {
            const T qmax = std::numeric_limits<T>::max();
            const double range = (max - min);
            for(std::size_t i = 0u; i < count; i++) {
                dst.put<T>(TE_ISNAN(elevations[i]) ?
                        qmax : (T) ((elevations[i] - min) / range * (qmax-1u)));
            }
        }
        static void dequantize(double *elevations, const T *quantized, const std::size_t count, const double min, const double max) NOTHROWS
        {
            const auto qmax = std::numeric_limits<T>::max();
            const double range = (max - min);
            for(std::size_t i = 0u; i < count; i++) {
                if(quantized[i] == qmax)
                    elevations[i] = NAN;
                else
                    elevations[i] = (((double)quantized[i] / (double)(qmax-1u)) * (range)) + min;
            }
        }
    public:
        std::shared_ptr<const uint8_t> data;
        const T *heightmap;
        HeightmapParams params;
        struct {
            double lng;
            double lat;
        } postSpacing;
        uint8_t version;
    };

    class NoDataSampler : public Sampler
    {
    public:
        NoDataSampler(const HeightmapParams& params_) NOTHROWS :
            params(params_)
        {}
    public:
        TAKErr sample(double* value, const double latitude, const double longitude) NOTHROWS override
        {
            return TE_Done;
        }
    public:
        HeightmapParams params;
    };

    // ContentControlImpl
    ContentControlImpl::ContentControlImpl(ElevationSource *source) NOTHROWS
    {
        if(!source)
            ElevationSourceManager_addOnSourcesChangedListener(this);
        SubscribeOnContentChangedListenerBundle arg;
        arg.listener = this;
        arg.mutex = &this->mutex;
        arg.sources = &this->sources;
        if(source)
            subscribeOnContentChangedListener(&arg, *source);
        else
            ElevationSourceManager_visitSources(subscribeOnContentChangedListener, &arg);
    }
    ContentControlImpl::~ContentControlImpl() NOTHROWS
    {
        ElevationSourceManager_removeOnSourcesChangedListener(this);
        Lock lock(mutex);
        for(auto it = sources.begin(); it != sources.end(); it++) {
            (*it)->removeOnContentChangedListener(this);
        }
        sources.clear();
    }
    TAKErr ContentControlImpl::addOnContentChangedListener(ContentControl::OnContentChangedListener* l) NOTHROWS
    {
        Lock lock(mutex);
        TE_CHECKRETURN_CODE(lock.status);
        listeners.insert(l);
        return TE_Ok;
    }
    TAKErr ContentControlImpl::removeOnContentChangedListener(ContentControl::OnContentChangedListener* l) NOTHROWS
    {
        Lock lock(mutex);
        TE_CHECKRETURN_CODE(lock.status);
        for (auto it = listeners.begin(); it != listeners.end(); it++) {
            if((*it) == l) {
                listeners.erase(it);
                return TE_Ok;
            }
        }
        return TE_InvalidArg;
    }
    TAKErr ContentControlImpl::onContentChanged(const ElevationSource &source) NOTHROWS
    {
        Lock lock(mutex);
        TE_CHECKRETURN_CODE(lock.status);
        for (auto& l : listeners)
            l->onContentChanged();
        return TE_Ok;
    }
    TAKErr ContentControlImpl::onSourceAttached(const std::shared_ptr<ElevationSource> &src) NOTHROWS
    {
        Lock lock(mutex);
        TE_CHECKRETURN_CODE(lock.status);
        for (auto& l : listeners)
            l->onContentChanged();

        if(sources.find(src.get()) == sources.end()) {
            sources.insert(src.get());
            src->addOnContentChangedListener(this);
        }

        return TE_Ok;
    }
    TAKErr ContentControlImpl::onSourceDetached(const ElevationSource &src) NOTHROWS
    {
        Lock lock(mutex);
        TE_CHECKRETURN_CODE(lock.status);
        auto entry = sources.find(const_cast<ElevationSource *>(&src));
        if(entry != sources.end()) {
            (*entry)->removeOnContentChangedListener(this);
            sources.erase(entry);
        }
        for (auto& l : listeners)
            l->onContentChanged();
        return TE_Ok;
    }
    TAKErr ContentControlImpl::subscribeOnContentChangedListener(void *opaque, ElevationSource &src) NOTHROWS
    {
        auto *arg = static_cast<SubscribeOnContentChangedListenerBundle *>(opaque);
        LockPtr lock(nullptr, nullptr);
        if(arg->mutex)
            Lock_create(lock, *arg->mutex);
        src.addOnContentChangedListener(arg->listener);
        if(arg->sources)
            arg->sources->insert(&src);
        return TE_Ok;
    }

    std::size_t getQuantizationBits(const double range, const double precision) NOTHROWS
    {
        const double qrange = range / precision;
        return (std::size_t)MathUtils_clamp(log(qrange) / log(2.0), 1.0, 32.0);
    }
    TAKErr encodeHeightmap(uint8_t* data, std::size_t *len, const HeightmapParams& params, const double gsd) NOTHROWS
    {
        TAKErr code(TE_Ok);
        const bool nodata = TE_ISNAN(params.bounds.minZ);
        const std::size_t qbits = getQuantizationBits(params.bounds.maxZ - params.bounds.minZ, gsd / 2.0);
        const uint8_t qbytes = (qbits <= 8u) ? 1u : (qbits <= 16) ? 2u : 4u;

        *len = encodedHeightmapHeaderLen_v3 +
            (nodata ? 0u : (qbytes * params.numPostsLat * params.numPostsLng));

        MemBuffer2 encoded(data, *len);

        // write header
        encoded.put<uint8_t>(0x03); // version
        encoded.put<uint8_t>(TE_PlatformEndian == TE_BigEndian ? 0xFF : 0x00); // endian
        encoded.put<uint8_t>(qbytes<<3u); // quantization bits
        encoded.put<uint8_t>(nodata ? 0x1u : 0x0u); // nodata flag

        // write params
        // .bounds
        encoded.put<double>(params.bounds.minX);
        encoded.put<double>(params.bounds.minY);
        encoded.put<double>(params.bounds.minZ);
        encoded.put<double>(params.bounds.maxX);
        encoded.put<double>(params.bounds.maxY);
        encoded.put<double>(params.bounds.maxZ);
        // .numPostsLat
        encoded.put<uint16_t>((uint16_t)params.numPostsLat);
        // .numPostsLng
        encoded.put<uint16_t>((uint16_t)params.numPostsLng);
        // invert Y axis
        encoded.put<uint32_t>(params.invertYAxis);

        if (nodata)
            return TE_Ok;

        // write quantized values
        const double* els = reinterpret_cast<const double*>(data + encodedHeightmapHeaderLen_v3);
        if (qbytes == 1u)
            QuantizedHeightmap<uint8_t>::quantize(encoded, els, (params.numPostsLat * params.numPostsLng), params.bounds.minZ, params.bounds.maxZ);
        else if (qbytes == 2u)
            QuantizedHeightmap<uint16_t>::quantize(encoded, els, (params.numPostsLat * params.numPostsLng), params.bounds.minZ, params.bounds.maxZ);
        else if (qbytes == 4u)
            QuantizedHeightmap<uint32_t>::quantize(encoded, els, (params.numPostsLat * params.numPostsLng), params.bounds.minZ, params.bounds.maxZ);
        else
            return TE_IllegalState;

        return TE_Ok;
    }

    TAKErr decodeHeightmap(ElevationChunkPtr& value, const std::shared_ptr<const uint8_t>& data, const std::size_t dataLen) NOTHROWS
    {
        if (dataLen < 4u)
            return TE_InvalidArg;

        const auto version = data.get()[0];
        switch(version) {
            case 0x1u:
            case 0x2u:
            case 0x3u:
                break;
            default:
                return TE_InvalidArg;
        }
        const TAKEndian endian = !!data.get()[1] ? TE_BigEndian : TE_LittleEndian;
        const auto qbits = data.get()[2];
        const bool nodata = !!data.get()[3];

        const auto headerLen = (version < 3u) ? encodedHeightmapHeaderLen : encodedHeightmapHeaderLen_v3;
        if (dataLen < headerLen)
            return TE_InvalidArg;

        HeightmapParams params;
        if (version < 3u) {
            if(nodata && dataLen != headerLen) {
                // no data reported, but data section exists; assume corrupt
                return TE_IllegalState;
            } else {
                memcpy(&params, data.get() + 4u, sizeof(HeightmapParams));
            }
        } else {
            // HeightmapParams is coded in portable manner starting with v3
            MemoryInput2 buf;
            buf.open(data.get() + 4u, headerLen - 4u);
            buf.setSourceEndian2(endian);

            bool err = true;
            do {
                if (buf.readDouble(&params.bounds.minX) != TE_Ok) break;
                if (buf.readDouble(&params.bounds.minY) != TE_Ok) break;
                if (buf.readDouble(&params.bounds.minZ) != TE_Ok) break;
                if (buf.readDouble(&params.bounds.maxX) != TE_Ok) break;
                if (buf.readDouble(&params.bounds.maxY) != TE_Ok) break;
                if (buf.readDouble(&params.bounds.maxZ) != TE_Ok) break;
                short numPostsLat;
                if (buf.readShort(&numPostsLat) != TE_Ok) break;
                params.numPostsLat = (uint16_t)numPostsLat;
                short numPostsLng;
                if (buf.readShort(&numPostsLng) != TE_Ok) break;
                params.numPostsLng = (uint16_t)numPostsLng;
                int invertYAxis;
                if (buf.readInt(&invertYAxis) != TE_Ok) break;
                params.invertYAxis = !!invertYAxis;
                err = false;
            } while (false);
            if (err)
                return TE_IO;
        }

        const auto qhmlen = dataLen - headerLen;
        if ((!qhmlen) != nodata) {
            // no data reported, but data section exists; assume corrupt
            return TE_IllegalState;
        } else if (!nodata && (params.numPostsLat * params.numPostsLng * (qbits / 8u)) != qhmlen) {
            // data section does not match expected size; assume corrupt
            return TE_IllegalState;
        }

        TAK::Engine::Feature::LineString2 bounds;
        bounds.addPoint(params.bounds.minX, params.bounds.minY);
        bounds.addPoint(params.bounds.minX, params.bounds.maxY);
        bounds.addPoint(params.bounds.maxX, params.bounds.maxY);
        bounds.addPoint(params.bounds.maxX, params.bounds.minY);
        bounds.addPoint(params.bounds.minX, params.bounds.minY);

        SamplerPtr sampler(nullptr, nullptr);
        if (nodata)
            sampler = SamplerPtr(new NoDataSampler(params), Memory_deleter_const<Sampler, NoDataSampler>);
        else if (qbits == 8u)
            sampler = SamplerPtr(new QuantizedHeightmap<uint8_t>(version, data, headerLen, params), Memory_deleter_const<Sampler, QuantizedHeightmap<uint8_t>>);
        else if (qbits == 16u)
            sampler = SamplerPtr(new QuantizedHeightmap<uint16_t>(version, data, headerLen, params), Memory_deleter_const<Sampler, QuantizedHeightmap<uint16_t>>);
        else if (qbits == 32u)
            sampler = SamplerPtr(new QuantizedHeightmap<uint32_t>(version, data, headerLen, params), Memory_deleter_const<Sampler, QuantizedHeightmap<uint32_t>>);
        else
            return TE_InvalidArg;
        return ElevationChunkFactory_create(value, nullptr, nullptr, 0u, NAN, TAK::Engine::Feature::Polygon2(bounds), NAN, NAN, false, std::move(sampler));
    }

    TAKErr getRegionTiles(TAK::Engine::Math::Point2<std::size_t>* min, TAK::Engine::Math::Point2<std::size_t>* max, const TAK::Engine::Math::Point2<double>& matrixOrigin, const TAK::Engine::Raster::TileMatrix::TileMatrix::ZoomLevel& zoom, const Envelope2& region_) NOTHROWS
    {
        constexpr std::size_t overlap = 1u;

        const double tileSizeX = (zoom.pixelSizeX * zoom.tileWidth);
        const double tileSizeY = (zoom.pixelSizeY * zoom.tileHeight);
        const double cellWidth = tileSizeX / (zoom.tileWidth-1u);
        const double cellHeight = tileSizeY / (zoom.tileHeight-1u);

        Envelope2 region(region_);
        region.minX -= (cellWidth * overlap);
        region.minY -= (cellHeight * (overlap+1u));
        region.maxX += (cellWidth * (overlap+1u));
        region.maxY += (cellHeight * overlap);

        TAK::Engine::Math::Point2<double> mind;
        TileMatrix_getTileIndex(&mind, matrixOrigin.x, matrixOrigin.y, zoom, region.minX, region.maxY);
        TAK::Engine::Math::Point2<double> maxd;
        TileMatrix_getTileIndex(&maxd, matrixOrigin.x, matrixOrigin.y, zoom, region.maxX, region.minY);

        min->x = (std::size_t)std::max(0.0, mind.x);
        min->y = (std::size_t)std::max(0.0, mind.y);
        max->x = (std::size_t)std::max(0.0, maxd.x);
        max->y = (std::size_t)std::max(0.0, maxd.y);

        return TE_Ok;
    }
} 