#include "elevation/ElevationManager.h"

#include <functional>
#include <list>

#include "core/ProjectionFactory3.h"
#include "elevation/ElevationSourceManager.h"
#include "elevation/MultiplexingElevationChunkCursor.h"
#include "feature/Geometry2.h"
#include "feature/GeometryTransformer.h"
#include "feature/Point2.h"
#include "feature/Polygon2.h"
#include "formats/egm/EGM96.h"
#pragma warning(push)
#pragma warning(disable : 4305 4838)
#include "formats/wmm/EGM9615.h"
#pragma warning(pop)
#include "formats/wmm/GeomagnetismHeader.h"
#include "raster/DatasetDescriptor.h"
#include "port/Collections.h"
#include "port/Vector.h"
#include "port/STLSetAdapter.h"
#include "port/STLListAdapter.h"
#include "port/STLVectorAdapter.h"
#include "port/String.h"
#include "thread/RWMutex.h"
#include "util/BlockPoolAllocator.h"
#include "util/ConfigOptions.h"
#include "util/DataInput2.h"
#include "util/Memory.h"
#include "util/Error.h"
#include "elevation/ElevationData.h"
#include "core/GeoPoint2.h"
#include "raster/mosaic/MultiplexingMosaicDatabaseCursor2.h"
#include "raster/mosaic/FilterMosaicDatabaseCursor2.h"

using namespace TAK::Engine;
using namespace TAK::Engine::Core;
using namespace TAK::Engine::Elevation;
using namespace TAK::Engine::Formats::EGM;
using namespace TAK::Engine::Raster;
using namespace TAK::Engine::Raster::Mosaic;
using namespace TAK::Engine::Thread;
using namespace TAK::Engine::Util;

typedef TAK_UNIQUE_PTR(Util::Filter<Mosaic::MosaicDatabase2::Cursor &>) ElevationModelFilterPtr;

namespace
{
    std::set<std::shared_ptr<TAK::Engine::Elevation::ElevationDataSpi>> &dataSpiRegistry()
    {
        static std::set<std::shared_ptr<TAK::Engine::Elevation::ElevationDataSpi>> r;
        return r;
    }

    RWMutex &spiMutex()
    {
        static RWMutex m;
        return m;
    }

    RWMutex &sourceMutex()
    {
        static RWMutex m;
        return m;
    }

    std::map<std::shared_ptr<MosaicDatabase2>, std::shared_ptr<ElevationSource>> &sources() {
        static std::map<std::shared_ptr<MosaicDatabase2>, std::shared_ptr<ElevationSource>> s;
        return s;
    }

    class ElevationModelFilter : public Util::Filter<Mosaic::MosaicDatabase2::Cursor &>
    {
    public :
        ElevationModelFilter(const int model) NOTHROWS;
    public :
        bool accept(Mosaic::MosaicDatabase2::Cursor &arg) NOTHROWS override ;
    private :
        const int model;
    };

    struct GeoMag
    {
        GeoMag() NOTHROWS
        {
            MAG_SetDefaults(&ellipsoid, &geoid);
            geoid.GeoidHeightBuffer = GeoidHeightBuffer;
            geoid.Geoid_Initialized = 1;
        }
        MAGtype_Geoid geoid;
        MAGtype_Ellipsoid ellipsoid;
    };
    struct GeoidContext_s
    {
        GeoidContext_s() NOTHROWS :
            dirty(true)
        {}

        GeoMag geomag;
        std::unique_ptr<EGM96> egm96;

        Mutex mutex;
        bool dirty;
    } GeoidContext;

    class MosaicDbStub : public ElevationSource
    {
    public:
        MosaicDbStub() NOTHROWS;
    public:
        const char *getName() const NOTHROWS override;
        TAKErr query(ElevationChunkCursorPtr &value, const QueryParameters &params) NOTHROWS override;
        Feature::Envelope2 getBounds() const NOTHROWS override;
        TAKErr addOnContentChangedListener(OnContentChangedListener *l) NOTHROWS override;
        TAKErr removeOnContentChangedListener(OnContentChangedListener *l) NOTHROWS override;
    };

    template<class T>
    TAKErr createHeightmapImpl(double* value, const double gsd, const HeightmapParams& params, const HeightmapStrategy strategy, T sourceQuery) NOTHROWS;
    TAKErr createHeightmapImpl(double* value, ElevationChunkCursor& cursor, const HeightmapParams& params, const bool clear, const bool constSpacing, const std::function<GeoPoint2(double, double)> &computePost) NOTHROWS;
}

//**************** ElevationManagerQueryParameters **/

ElevationManagerQueryParameters::ElevationManagerQueryParameters() NOTHROWS :
    minResolution(NAN),
    maxResolution(NAN),
    elevationModel(ElevationData::MODEL_SURFACE | ElevationData::MODEL_TERRAIN),
    spatialFilter(nullptr, nullptr),
    types(nullptr, nullptr),
    preferSpeed(false),
    interpolate(false)
{}

ElevationManagerQueryParameters::ElevationManagerQueryParameters(const ElevationManagerQueryParameters &other) NOTHROWS :
    minResolution(other.minResolution),
    maxResolution(other.maxResolution),
    elevationModel(other.elevationModel),
    spatialFilter(nullptr, nullptr),
    types(nullptr, nullptr),
    preferSpeed(other.preferSpeed),
    interpolate(other.interpolate)
{
    if (other.spatialFilter.get()) {
        Util::TAKErr code(Util::TE_Ok);
        code = Feature::Geometry_clone(spatialFilter, *other.spatialFilter);
        // XXX - clone failed
    }
    if (other.types.get()) {
        types = TAK_UNIQUE_PTR(Port::Set<Port::String>)(new Port::STLSetAdapter<Port::String, TAK::Engine::Port::StringLess>(), Util::Memory_deleter_const<Port::Set<Port::String>, Port::STLSetAdapter<Port::String, TAK::Engine::Port::StringLess>>);
        Port::Collections_addAll<Port::String>(*types, *other.types);
    }
}

//**************** ElevationManager **/


Util::TAKErr TAK::Engine::Elevation::ElevationManager_registerElevationSource(std::shared_ptr<TAK::Engine::Raster::Mosaic::MosaicDatabase2> database) NOTHROWS
{
    if (!database.get())
        return Util::TE_InvalidArg;
    WriteLock lock(sourceMutex());
    TE_CHECKRETURN_CODE(lock.status);
    std::map<std::shared_ptr<MosaicDatabase2>, std::shared_ptr<ElevationSource>> &src = sources();
    for (auto it = src.begin(); it != src.end(); it++) {
        if (it->first.get() == database.get())
            return TE_Ok;
    }
    std::shared_ptr<ElevationSource> stub = std::move(std::unique_ptr<ElevationSource, void(*)(const ElevationSource *)>(new MosaicDbStub(), Memory_deleter_const<ElevationSource, MosaicDbStub>));

    src[database] = stub;
    ElevationSourceManager_attach(stub);

    return Util::TE_Ok;
}

Util::TAKErr TAK::Engine::Elevation::ElevationManager_unregisterElevationSource(std::shared_ptr<TAK::Engine::Raster::Mosaic::MosaicDatabase2> database) NOTHROWS
{
    if (!database.get())
        return Util::TE_InvalidArg;
    WriteLock lock(sourceMutex());
    TE_CHECKRETURN_CODE(lock.status);
    std::map<std::shared_ptr<MosaicDatabase2>, std::shared_ptr<ElevationSource>> &src = sources();
    for (auto it = src.begin(); it != src.end(); it++) {
        if (it->first.get() == database.get()) {
            ElevationSourceManager_detach(*it->second);
            src.erase(it);
            return TE_Ok;
        }
    }
    return TE_InvalidArg;
}

TAKErr TAK::Engine::Elevation::ElevationManager_queryElevationData(MosaicDatabase2::CursorPtr &cursor, const ElevationManagerQueryParameters &params) NOTHROWS
{
    Util::TAKErr code(Util::TE_Ok);
    Mosaic::MosaicDatabase2::QueryParameters mparams;
    bool isReject = false;

    TAK_UNIQUE_PTR(Port::Collection<std::shared_ptr<Util::Filter<MosaicDatabase2::Cursor &>>>) filters(new Port::STLSetAdapter<std::shared_ptr<Util::Filter<Mosaic::MosaicDatabase2::Cursor &>>>(), Util::Memory_deleter_const<Port::Collection<std::shared_ptr<Util::Filter<Mosaic::MosaicDatabase2::Cursor &>>>, Port::STLSetAdapter<std::shared_ptr<Util::Filter<MosaicDatabase2::Cursor &>>>>);

    mparams.minGsd = params.minResolution;
    mparams.maxGsd = params.maxResolution;
    if (params.spatialFilter) {
        code = Feature::Geometry_clone(mparams.spatialFilter, *params.spatialFilter);
        TE_CHECKRETURN_CODE(code);
    }
    if (params.types.get()) {
        mparams.types = TAK_UNIQUE_PTR(Port::Set<Port::String>)(new Port::STLSetAdapter<Port::String, TAK::Engine::Port::StringLess>(), Util::Memory_deleter_const<Port::Set<Port::String>, Port::STLSetAdapter<Port::String, TAK::Engine::Port::StringLess>>);
        Port::Collections_addAll(*mparams.types, *params.types);
    }
    if (params.elevationModel != (ElevationData::MODEL_SURFACE | ElevationData::MODEL_TERRAIN)) {
        ElevationModelFilterPtr filter(nullptr, nullptr);
        switch (params.elevationModel) {
        case 0:
            isReject = true;
            break;
        case ElevationData::MODEL_SURFACE:
        case ElevationData::MODEL_TERRAIN:
        default:
            filter = ElevationModelFilterPtr(new ElevationModelFilter(params.elevationModel), Util::Memory_deleter_const<Util::Filter<Mosaic::MosaicDatabase2::Cursor &>, ElevationModelFilter>);
            break;
        }

        if (filter.get())
            filters->add(std::move(filter));
    }

    std::unique_ptr<MultiplexingMosaicDatabaseCursor2> mcursor(new MultiplexingMosaicDatabaseCursor2());
    if (!isReject)
    {
        ReadLock lock(sourceMutex());
        code = lock.status;
        TE_CHECKRETURN_CODE(code);

        for (auto entry = sources().begin(); entry != sources().end(); entry++)
        {
            MosaicDatabase2::CursorPtr queryPtr(nullptr, nullptr);

            TAKErr success = entry->first->query(queryPtr, mparams);

            if (success == TE_Ok) {
                mcursor->add(move(queryPtr));
            }

        }
    }

    cursor = MosaicDatabase2::CursorPtr(mcursor.release(), Memory_deleter_const<MosaicDatabase2::Cursor, MultiplexingMosaicDatabaseCursor2>);

    if (!filters->empty())
    {
        MosaicDatabase2::CursorPtr filtered(nullptr, nullptr);
        code = FilterMosaicDatabaseCursor2_filter(filtered, std::move(cursor), std::move(filters));
        TE_CHECKRETURN_CODE(code);
        cursor = std::move(filtered);
    }

    return TE_Ok;
}

TAKErr TAK::Engine::Elevation::ElevationManager_queryElevationSources(ElevationChunkCursorPtr &value, const std::shared_ptr<ElevationSource> *sources, const std::size_t numSources, const ElevationSource::QueryParameters &params) NOTHROWS
{
    TAKErr code(TE_Ok);

    std::list<std::shared_ptr<ElevationChunkCursor>> cursors;
    if(numSources) {
        for(std::size_t i = 0u; i < numSources; i++) {
            ElevationChunkCursorPtr cursor(nullptr, nullptr);
            code = sources[i]->query(cursor, params);
            TE_CHECKBREAK_CODE(code);
            cursors.push_back(std::move(cursor));
        }
        TE_CHECKRETURN_CODE(code);
    }

    std::list<bool(*)(ElevationChunkCursor &, ElevationChunkCursor &) NOTHROWS> order;
    if(params.order.get() && !params.order->empty()) {
        TAK::Engine::Port::Collection<ElevationSource::QueryParameters::Order >::IteratorPtr oit(nullptr, nullptr);
        code = params.order->iterator(oit);
        TE_CHECKRETURN_CODE(code);
        do {
            ElevationSource::QueryParameters::Order v;
            code = oit->get(v);
            TE_CHECKBREAK_CODE(code);
            switch(v) {
                case ElevationSource::QueryParameters::ResolutionAsc :
                    order.push_back(ElevationSource_resolutionAsc);
                    break;
                case ElevationSource::QueryParameters::ResolutionDesc :
                    order.push_back(ElevationSource_resolutionDesc);
                    break;
                case ElevationSource::QueryParameters::CEAsc :
                    order.push_back(ElevationSource_ceAsc);
                    break;
                case ElevationSource::QueryParameters::CEDesc :
                    order.push_back(ElevationSource_ceDesc);
                    break;
                case ElevationSource::QueryParameters::LEAsc :
                    order.push_back(ElevationSource_leAsc);
                    break;
                case ElevationSource::QueryParameters::LEDesc :
                    order.push_back(ElevationSource_leDesc);
                    break;
                default :
                    return TE_InvalidArg;
            }
            code = oit->next();
            TE_CHECKBREAK_CODE(code);
        } while(true);
        if(code == TE_Done)
            code = TE_Ok;
        TE_CHECKRETURN_CODE(code);

    }

    TAK::Engine::Port::STLListAdapter<std::shared_ptr<ElevationChunkCursor>> cursors_w(cursors);
    TAK::Engine::Port::STLListAdapter<bool(*)(ElevationChunkCursor &, ElevationChunkCursor &) NOTHROWS> order_w(order);
    value = ElevationChunkCursorPtr(new MultiplexingElevationChunkCursor(cursors_w, order_w), Memory_deleter_const<ElevationChunkCursor, MultiplexingElevationChunkCursor>);

    return code;
}
TAKErr TAK::Engine::Elevation::ElevationManager_queryElevationSources(ElevationChunkCursorPtr &value, const ElevationSource::QueryParameters &params) NOTHROWS
{
    TAKErr code(TE_Ok);

    std::vector<std::shared_ptr<ElevationSource>> sources;
    TAK::Engine::Port::STLVectorAdapter<std::shared_ptr<ElevationSource>> sources_w(sources);
    code = ElevationSourceManager_getSources(sources_w);
    TE_CHECKRETURN_CODE(code);

    return ElevationManager_queryElevationSources(value, sources.data(), sources.size(), params);
}
TAKErr TAK::Engine::Elevation::ElevationManager_queryElevationSourcesCount(std::size_t *value, const ElevationSource::QueryParameters &params) NOTHROWS
{
    if(!value)
        return TE_InvalidArg;
    TAKErr code(TE_Ok);
    ElevationChunkCursorPtr result(nullptr, nullptr);
    code = ElevationManager_queryElevationSources(result, ElevationSource::QueryParameters());
    TE_CHECKRETURN_CODE(code);
    std::size_t retval = 0u;
    do {
        code = result->moveToNext();
        TE_CHECKBREAK_CODE(code);
        retval++;
    } while(true);
    if(code == TE_Done)
        code = TE_Ok;
    *value = retval;
    return code;
}

TAKErr TAK::Engine::Elevation::ElevationManager_getElevation(double *value, Port::String *source, const double latitude, const double longitude, const ElevationManagerQueryParameters &filter) NOTHROWS
{
    TAKErr code(TE_Ok);
    ElevationManagerQueryParameters params(filter);

    params.spatialFilter = Feature::Geometry2Ptr(new Feature::Point2(longitude, latitude), Util::Memory_deleter_const<Feature::Geometry2>);

    MosaicDatabase2::CursorPtr cursor(nullptr, nullptr);
    code = ElevationManager_queryElevationData(cursor, params);
    TE_CHECKRETURN_CODE(code);

    *value = NAN;

    do
    {
        code = cursor->moveToNext();
        TE_CHECKBREAK_CODE(code);

        MosaicDatabase2::FramePtr_const frame(nullptr, nullptr);
        if (MosaicDatabase2::Frame::createFrame(frame, *cursor) != TE_Ok)
            continue;

        ElevationDataPtr elptr(nullptr, nullptr);
        if(ElevationManager_create(elptr, *frame) != TE_Ok)
            continue;

        double hae;
        TAKErr success = elptr->getElevation(&hae, latitude, longitude);
        if (TE_ISNAN(hae) || success != TE_Ok)
            continue;
        if (source)
            success = elptr->getType(*source);
        *value = hae;
        break;
    } while (true);
    if (code == TE_Done)
        code = TE_Ok;

    return code;
}

TAKErr TAK::Engine::Elevation::ElevationManager_getElevation(double *value, Port::String *source, const double latitude, const double longitude, const ElevationSource::QueryParameters &filter_) NOTHROWS
{
    if(!value)
        return TE_InvalidArg;

    TAKErr code(TE_Ok);

    ElevationSource::QueryParameters filter(filter_);
    TAK::Engine::Feature::Point2 spatialFilter(longitude, latitude);
    filter.spatialFilter = TAK::Engine::Feature::Geometry2Ptr(&spatialFilter, Memory_leaker_const<TAK::Engine::Feature::Geometry2>);

    ElevationChunkCursorPtr result(nullptr, nullptr);
    code = ElevationManager_queryElevationSources(result, filter);
    TE_CHECKRETURN_CODE(code);

    do {
        code = result->moveToNext();
        TE_CHECKBREAK_CODE(code);

        ElevationChunkPtr chunk(nullptr, nullptr);
        if(result->get(chunk) != TE_Ok)
            continue;
        double hae;
        if(chunk->sample(&hae, latitude, longitude) != TE_Ok || TE_ISNAN(hae))
            continue;
        *value = hae;
        if(source)
            *source = chunk->getType();
        return code;
    } while(true);
    if(code == TE_Done)
        code = TE_Ok;

    *value = NAN;
    // no elevation value found
    return TE_InvalidArg;
}

Util::TAKErr TAK::Engine::Elevation::ElevationManager_getElevation(
    double *elevations,
    Port::Collection<GeoPoint2>::IteratorPtr &points,
    const ElevationManagerQueryParameters &filter,
    const ElevationData::Hints &hint) NOTHROWS
{
    struct GeoPoint2_LT
    {
        bool operator()(const GeoPoint2 &a, const GeoPoint2 &b) const
        {
            if (a.latitude < b.latitude)
                return true;
            else if (a.latitude > b.latitude)
                return false;
            else
                return a.longitude < b.longitude;
        }
    };
    std::list<GeoPoint2> src;
    std::size_t srcSize;
    std::map<GeoPoint2, std::size_t, GeoPoint2_LT> sourceLocations;
    std::size_t idx = 0u;
    double north = -90;
    double south = 90;
    double east = -180;
    double west = 180;

    Util::TAKErr code;
    do {
        GeoPoint2 point;
        code = points->get(point);
        TE_CHECKBREAK_CODE(code);

        src.push_back(point);
        elevations[idx] = NAN;
        sourceLocations[point] = idx++;

        double lat = point.latitude;
        if (lat > north) { north = lat; }
        if (lat < south) { south = lat; }

        double lng = point.longitude;
        if (lng > east) { east = lng; }
        if (lng < west) { west = lng; }

        code = points->next();
        TE_CHECKBREAK_CODE(code);
    } while (true);
    if((north < south) || (east < west)) {
        // the input set is malformed, nothing else to do as all output values have been NaN`d
        return TE_Done;
    }

    srcSize = idx;

    ElevationData::Hints hintCopy(hint);

    // TODO: Does this have issues when the envelope crosses the International Date Line?
    // This code copies what is done in ATAK, so that may need to be checked too.
    hintCopy.bounds = Feature::Envelope2(west, south, NAN, east, north, NAN);

    ElevationManagerQueryParameters filterCopy(filter);
    Feature::LineString2 ring;
    code = ring.addPoint(west, north);
    TE_CHECKRETURN_CODE(code);
    ring.addPoint(east, north);
    TE_CHECKRETURN_CODE(code);
    ring.addPoint(east, south);
    TE_CHECKRETURN_CODE(code);
    ring.addPoint(west, south);
    TE_CHECKRETURN_CODE(code);
    ring.addPoint(west, north);
    TE_CHECKRETURN_CODE(code);

    filterCopy.spatialFilter = Feature::Geometry2Ptr(
        new Feature::Polygon2(ring),
        Util::Memory_deleter_const<Feature::Geometry2>);

    Mosaic::MosaicDatabase2::CursorPtr cursor(nullptr, nullptr);

    code = ElevationManager_queryElevationData(cursor, filterCopy);
    TE_CHECKRETURN_CODE(code);
    code = Util::TE_Ok;
    do
    {
        code = cursor->moveToNext();
        TE_CHECKBREAK_CODE(code);

        ElevationDataPtr data(nullptr, nullptr);

        TAK::Engine::Raster::Mosaic::MosaicDatabase2::FramePtr_const frame(nullptr, nullptr);
        TAK::Engine::Raster::Mosaic::MosaicDatabase2::Frame::createFrame(frame, *cursor);

        code = ElevationManager_create(data, *frame);
        if (code != Util::TE_Ok || !data.get()) {
            continue;
        }

        Port::STLListAdapter<GeoPoint2> srcAdapter(src);
        Port::Collection<GeoPoint2>::IteratorPtr iterator(nullptr, nullptr);
        code = srcAdapter.iterator(iterator);
        if (code != Util::TE_Ok) {
            continue;
        }

        Util::array_ptr<double> dataEls(new double[srcSize]);
        code = data->getElevation(dataEls.get(), iterator, hintCopy);
        if (code != Util::TE_Ok) {
            continue;
        }

        auto srcIter = src.begin();
        const std::size_t limit = srcSize;
        for (std::size_t i = 0u; i < limit; i++) {
            const double value = dataEls[i];
            if (TE_ISNAN(value))
            {
                srcIter++;
                continue;
            }

            elevations[sourceLocations[*srcIter]] = value;
            srcIter = src.erase(srcIter);
            srcSize--;
        }

        if (src.empty())
        {
            break;
        }
    } while (true);
    if(code == Util::TE_Done)
    {
        code = Util::TE_Ok;
    }
    TE_CHECKRETURN_CODE(code);

    return code;
}

TAKErr TAK::Engine::Elevation::ElevationManager_getElevation(double *value, const std::size_t count, const double *srcLat, const double *srcLng, const std::size_t srcLatStride, const std::size_t srcLngStride, const std::size_t dstStride, const ElevationSource::QueryParameters &filter_) NOTHROWS {
    if (!value)
        return TE_InvalidArg;
    if (!srcLat)
        return TE_InvalidArg;
    if (!srcLng)
        return TE_InvalidArg;
    if (!count)
        return TE_Ok;

    TAKErr code(TE_Ok);

    ElevationSource::QueryParameters filter(filter_);
    if (!filter_.spatialFilter.get()) {
        TAK::Engine::Feature::Envelope2 mbr(srcLng[0], srcLat[0], 0.0, srcLng[0], srcLat[0], 0.0);
        for (std::size_t i = 1u; i < count; i++) {
            GeoPoint2 pt(srcLat[i * srcLatStride], srcLng[i * srcLngStride]);

            if (pt.longitude < mbr.minX)
                mbr.minX = pt.longitude;
            if (pt.latitude < mbr.minY)
                mbr.minY = pt.latitude;
            if (pt.longitude > mbr.maxX)
                mbr.maxX = pt.longitude;
            if (pt.latitude > mbr.maxY)
                mbr.maxY = pt.latitude;
        }

        // recompute spatial filter using MBR
        // XXX - should be intersection of user specified and computed ???
        code = TAK::Engine::Feature::Polygon2_fromEnvelope(filter.spatialFilter, mbr);
        TE_CHECKRETURN_CODE(code);
    }

    ElevationChunkCursorPtr result(nullptr, nullptr);
    code = ElevationManager_queryElevationSources(result, filter);
    TE_CHECKRETURN_CODE(code);

    // XXX - should we allow client to fill holes
    for(std::size_t i = 0u; i < count; i++)
        value[i*dstStride] = NAN;

    do {
        code = result->moveToNext();
        TE_CHECKBREAK_CODE(code);

        ElevationChunkPtr data(nullptr, nullptr);
        if(result->get(data) != TE_Ok)
            continue;
        if(data->sample(value, count, srcLat, srcLng, srcLatStride, srcLngStride, dstStride) == TE_Ok)
            return TE_Ok;
    } while(true);

    // all processing is done, but we haven't
    return TE_Done;
}


//**************** SPI Methods **/

Util::TAKErr TAK::Engine::Elevation::ElevationManager_create(ElevationDataPtr &value, const ImageInfo &info) NOTHROWS
{
    Util::TAKErr code(Util::TE_Ok);
    ReadLock lock(spiMutex());
    code = lock.status;
    TE_CHECKRETURN_CODE(code);
    std::set<std::shared_ptr<ElevationDataSpi>> &spis = dataSpiRegistry();
    std::set<std::shared_ptr<ElevationDataSpi>>::iterator spi;
    for (spi = spis.begin(); spi != spis.end(); spi++) {
        code = (*spi)->create(value, info);
        if (code == Util::TE_Ok)
            return code;
    }

    return Util::TE_InvalidArg;
}

Util::TAKErr TAK::Engine::Elevation::ElevationManager_registerDataSpi(std::shared_ptr<TAK::Engine::Elevation::ElevationDataSpi> spi) NOTHROWS
{
    if (!spi.get())
        return Util::TE_InvalidArg;

    Util::TAKErr code(Util::TE_Ok);
    WriteLock lock(spiMutex());
    code = lock.status;
    TE_CHECKRETURN_CODE(code);
    dataSpiRegistry().insert(spi);
    // XXX - invalid arg if already registered???
    return Util::TE_Ok;
}

Util::TAKErr TAK::Engine::Elevation::ElevationManager_unregisterDataSpi(std::shared_ptr<TAK::Engine::Elevation::ElevationDataSpi> spi) NOTHROWS
{
    if (!spi.get())
        return Util::TE_InvalidArg;

    Util::TAKErr code(Util::TE_Ok);
    WriteLock lock(spiMutex());
    code = lock.status;
    TE_CHECKRETURN_CODE(code);
    return dataSpiRegistry().erase(spi) ? Util::TE_Ok : Util::TE_InvalidArg;
}

Util::TAKErr TAK::Engine::Elevation::ElevationManager_getGeoidHeight(double *height, const double latitude, const double longitude_) NOTHROWS
{
    if(TE_ISNAN(latitude) || TE_ISNAN(longitude_))
        return TE_InvalidArg;
    if(latitude < -90.0 || latitude > 90.0)
        return TE_InvalidArg;
    double longitude = longitude_;
    if(longitude < -180.0)
        longitude += 360.0;
    else if(longitude > 180.0)
        longitude -= 360.0;

    do {
        TAKErr code(TE_Ok);
        Lock lock(GeoidContext.mutex);
        code = lock.status;
        TE_CHECKBREAK_CODE(code);
        if(GeoidContext.dirty) {
            GeoidContext.dirty = false;

            // initialize from the EGM96 file
            TAK::Engine::Port::String egmFilePath;
            code = ConfigOptions_getOption(egmFilePath, "egm96-file");
            if (code != TE_Ok) {
                Logger_log(TELL_Info, "EGM96 file is not configured");
                break;
            }

            // XXX - read the file into a byte array
            bool exists;
            code = IO_exists(&exists, egmFilePath);
            TE_CHECKBREAK_CODE(code);
            if(!exists) {
                Logger_log(TELL_Warning, "EGM96 file not found");
                break;
            }
            int64_t fileLen;
            code = IO_length(&fileLen, egmFilePath);
            TE_CHECKBREAK_CODE(code);

            if(fileLen > SIZE_MAX) {
                Logger_log(TELL_Warning, "EGM96 file size exceeds SIZE_MAX");
                break;
            }

            array_ptr<uint8_t> egmData(new uint8_t[(std::size_t)fileLen]);

            FileInput2 file;
            code = file.open(egmFilePath);
            TE_CHECKBREAK_CODE(code);
            std::size_t egmDataLen;
            code = file.read(egmData.get(), &egmDataLen, (std::size_t)fileLen);
            TE_CHECKBREAK_CODE(code);

            std::unique_ptr<EGM96> egm96(new EGM96());
            code = egm96->open(egmData.get(), egmDataLen);
            TE_CHECKBREAK_CODE(code);

            GeoidContext.egm96 = std::move(egm96);
        }
        if(GeoidContext.egm96.get()) {
            code = GeoidContext.egm96->getHeight(height, GeoPoint2(latitude, longitude));
            TE_CHECKBREAK_CODE(code);

            return code;
        }
    } while(false);

    // drop through to WMM EGM96 dataset
    if(MAG_GetGeoidHeight(latitude, longitude, height, &GeoidContext.geomag.geoid) != TRUE)
      return Util::TE_InvalidArg;
    return TE_Ok;
}

TAKErr TAK::Engine::Elevation::ElevationManager_createHeightmap(double* value, const double gsd, const HeightmapParams &params, const HeightmapStrategy strategy) NOTHROWS
{
    return createHeightmapImpl(value, gsd, params, strategy, [](ElevationChunkCursorPtr &result, const ElevationSource::QueryParameters& qparams)
    {
        return ElevationManager_queryElevationSources(result, qparams);
    });
}
TAKErr TAK::Engine::Elevation::ElevationManager_createHeightmap(double* value, ElevationSource &source, const double gsd, const HeightmapParams &params, const HeightmapStrategy strategy) NOTHROWS
{
    return createHeightmapImpl(value, gsd, params, strategy, [&source](ElevationChunkCursorPtr &result, const ElevationSource::QueryParameters& qparams)
    {
        return source.query(result, qparams);
    });
}
TAKErr TAK::Engine::Elevation::ElevationManager_createHeightmap(double* value, ElevationChunkCursor &cursor, const HeightmapParams &params) NOTHROWS
{
    Projection2Ptr proj(nullptr, nullptr);
    if(params.srid != 4326 && ProjectionFactory3_create(proj, params.srid) != TE_Ok)
        return TE_InvalidArg;
    std::function<GeoPoint2(double, double)> computePost_lla = [](double x, double y)
       {
           // flip over pole if necessary
           if(y > 90.0) y = 180.0 - y;
           else if(y < -90.0) y = -180.0 - y;
           // flip over anti-meridian if necessary
           if(x < -180.0) x += 360.0;
           else if(x > 180.0) x -= 360.0;
           return GeoPoint2(y, x);
       };
    std::function<GeoPoint2(double, double)> computePost_generic =
       [&proj](double x, double y)
       {
           GeoPoint2 lla;
           proj->inverse(&lla, TAK::Engine::Math::Point2<double>(x, y));
           return lla;
       };
        const bool constSpacing =
            (params.srid == 4326) ||
            (params.srid == 3857) ||
            (params.srid == 3395);
    return createHeightmapImpl(value, cursor, params, true, constSpacing, params.srid == 4326 ? computePost_lla : computePost_generic);
}

namespace
{
    ElevationModelFilter::ElevationModelFilter(int model_) NOTHROWS :
        model(model_)
    {}

    bool ElevationModelFilter::accept(Mosaic::MosaicDatabase2::Cursor &arg) NOTHROWS
    {
        Util::TAKErr code(Util::TE_Ok);

        Mosaic::MosaicDatabase2::FramePtr_const frame(nullptr, nullptr);
        code = Mosaic::MosaicDatabase2::Frame::createFrame(frame, arg);
        if (code != Util::TE_Ok)
            return false;

        ElevationDataPtr data(nullptr, nullptr);
        code = ElevationManager_create(data, *frame);
        if (code != Util::TE_Ok)
            return false;

        return ((data->getElevationModel()&this->model) != 0);
    }

    MosaicDbStub::MosaicDbStub() NOTHROWS
    {}
    const char *MosaicDbStub::getName() const NOTHROWS
    {
        return nullptr;
    }
    TAKErr MosaicDbStub::query(ElevationChunkCursorPtr &value, const QueryParameters &params) NOTHROWS
    {
        std::list<std::shared_ptr<ElevationChunkCursor>> empty;
        TAK::Engine::Port::STLListAdapter<std::shared_ptr<ElevationChunkCursor>> empty_w(empty);
        value = ElevationChunkCursorPtr(new MultiplexingElevationChunkCursor(empty_w), Memory_deleter_const<ElevationChunkCursor, MultiplexingElevationChunkCursor>);
        return TE_Ok;
    }
    Feature::Envelope2 MosaicDbStub::getBounds() const NOTHROWS
    {
        return Feature::Envelope2(0.0, 0.0, 0.0, 0.0);
    }
    TAKErr MosaicDbStub::addOnContentChangedListener(OnContentChangedListener *l) NOTHROWS
    {
        return TE_Ok;
    }
    TAKErr MosaicDbStub::removeOnContentChangedListener(OnContentChangedListener *l) NOTHROWS
    {
        return TE_Ok;
    }

    template<class T>
    TAKErr createHeightmapImpl(double* value, const double gsd, const HeightmapParams& params, const HeightmapStrategy strategy, T sourceQuery) NOTHROWS
    {
        TAKErr code(TE_Ok);

        struct {
            ElevationSource::QueryParameters::Order order {ElevationSource::QueryParameters::ResolutionDesc};
            struct {
                double min {NAN};
                double max {NAN};
            } gsd;
        } queries[3u];
        std::size_t numQueries = 0u;

        switch(strategy)
        {
            case HighestResolution :
                // single query
                queries[0].order = ElevationSource::QueryParameters::ResolutionDesc;
                queries[0].gsd.min = NAN;
                queries[0].gsd.max = NAN;
                numQueries = 1u;
                break;
            case Low :
                // single query
                queries[0].order = ElevationSource::QueryParameters::ResolutionDesc;
                queries[0].gsd.min = NAN;
                queries[0].gsd.max = gsd;
                numQueries = 1u;
                break;
            case LowFillHoles :
                // first query, low
                queries[0].order = ElevationSource::QueryParameters::ResolutionDesc;
                queries[0].gsd.min = NAN;
                queries[0].gsd.max = gsd;
                // second query, high, asc
                queries[1].order = ElevationSource::QueryParameters::ResolutionAsc;
                queries[1].gsd.min = gsd;
                queries[1].gsd.max = NAN;
                // two queries
                numQueries = 2u;
                break;
            default :
                return TE_InvalidArg;
        }
        Projection2Ptr proj(nullptr, nullptr);
        if(params.srid != 4326 && ProjectionFactory3_create(proj, params.srid) != TE_Ok)
            return TE_InvalidArg;
        std::function<GeoPoint2(double, double)> computePost_lla = [](double x, double y)
           {
               // flip over pole if necessary
               if(y > 90.0) y = 180.0 - y;
               else if(y < -90.0) y = -180.0 - y;
               // flip over anti-meridian if necessary
               if(x < -180.0) x += 360.0;
               else if(x > 180.0) x -= 360.0;
               return GeoPoint2(y, x);
           };
        std::function<GeoPoint2(double, double)> computePost_generic =
           [&proj](double x, double y)
           {
               GeoPoint2 lla;
               proj->inverse(&lla, TAK::Engine::Math::Point2<double>(x, y));
               return lla;
           };
        std::function<GeoPoint2(double, double)> computePost = params.srid == 4326 ? computePost_lla : computePost_generic;
        const bool constSpacing =
            (params.srid == 4326) ||
            (params.srid == 3857) ||
            (params.srid == 3395);

        auto queryBounds = params.bounds;
        if(proj)
            GeometryTransformer_inverse(&queryBounds, queryBounds, *proj);
        ElevationSource::QueryParameters queryParams;
        code = Polygon2_fromEnvelope(queryParams.spatialFilter, queryBounds);
        TE_CHECKRETURN_CODE(code);
        queryParams.order = TAK::Engine::Port::Collection<ElevationSource::QueryParameters::Order>::Ptr(new TAK::Engine::Port::STLVectorAdapter<ElevationSource::QueryParameters::Order>(), Memory_deleter_const<TAK::Engine::Port::Collection<ElevationSource::QueryParameters::Order>, TAK::Engine::Port::STLVectorAdapter<ElevationSource::QueryParameters::Order>>);
        for(std::size_t i = 0u; i < numQueries; i++) {
            // configure order
            code = queryParams.order->clear();
            TE_CHECKBREAK_CODE(code);
            code = queryParams.order->add(queries[i].order);
            TE_CHECKBREAK_CODE(code);

            // configure GSD thresholds
            queryParams.minResolution = queries[i].gsd.min;
            queryParams.maxResolution = queries[i].gsd.max;

            ElevationChunkCursorPtr result(nullptr, nullptr);
            code = sourceQuery(result, queryParams);
            if(code != TE_Ok)
                continue;
            code = createHeightmapImpl(value, *result, params, (i==0u), constSpacing, computePost);
            if(code == TE_Ok)
                return code;
        }
        return TE_Done;
    }
    TAKErr createHeightmapImpl(double* value, ElevationChunkCursor &cursor, const HeightmapParams &params, const bool init, const bool constSpacing, const std::function<GeoPoint2(double, double)> &computePost) NOTHROWS
    {
        TAKErr code(TE_Ok);

        const auto count = (params.numPostsLat*params.numPostsLng);
    
        const double cellHeightProj = ((params.bounds.maxY - params.bounds.minY) / (params.numPostsLat - 1));
        const double cellWidthProj = ((params.bounds.maxX - params.bounds.minX) / (params.numPostsLng - 1));

        // XXX - clean way to allow client to specify preallocated buffer ???

        std::unique_ptr<double, void(*)(const double *)> srcllptr(nullptr, nullptr);

        // XXX - hacky means to avoid minimize heap allocations for the hotspot path supporting
        //       the `ElMgrTerrainRenderService` pending a good API to allow client to specify a
        //       pre-allocated "working" buffer
        constexpr auto terrainServicePosts = 34u; // 32 plus one post border
        constexpr auto terrainServiceFetchCount = terrainServicePosts * terrainServicePosts;
        if (count == terrainServiceFetchCount) {
            static BlockPoolAllocator renderServiceAllocator(2u * terrainServiceFetchCount * sizeof(double), 4u);
            code = renderServiceAllocator.allocate<double>(srcllptr);
        } else {
            srcllptr = std::unique_ptr<double, void(*)(const double *)>(new(std::nothrow) double[count*2u], Memory_array_deleter_const<double>);
            if (!srcllptr)
                code = TE_OutOfMemory;
        }
        TE_CHECKRETURN_CODE(code);
        double* srcll = srcllptr.get();

        std::size_t post = 0u;
        for (int postY = 0; postY < (int)params.numPostsLat; postY++) {
            const double y = params.invertYAxis ?
                    params.bounds.minY + cellHeightProj * postY :
                    params.bounds.maxY - cellHeightProj * postY;
            const auto rowMin = constSpacing ? computePost(params.bounds.minX, y) : GeoPoint2();
            const auto rowMax = constSpacing ? computePost(params.bounds.maxX, y) : GeoPoint2();
            const auto cellWidthLng = (rowMax.longitude-rowMin.longitude) / (params.numPostsLng-1);
            for (int postX = 0; postX < (int)params.numPostsLng; postX++) {
                double x = params.bounds.minX + cellWidthProj * postX;
                const auto pt = constSpacing ?
                 GeoPoint2(rowMin.latitude, rowMin.longitude + cellWidthLng*postX) :
                 computePost(x, y);
                srcll[post*2u] = pt.latitude;
                srcll[post*2u+1] = pt.longitude;

                if(init)
                    value[post] = NAN;
                post++;
            }
        }

        do {
            code = cursor.moveToNext();
            TE_CHECKBREAK_CODE(code);

            ElevationChunkPtr data(nullptr, nullptr);
            if(cursor.get(data) != TE_Ok)
                continue;
            if(data->sample(value, count, srcll, srcll+1u, 2u, 2u, 1u) == TE_Ok)
                return TE_Ok;
        } while(true);

        // all processing is done, but we haven't
        return TE_Done;
    }
}
