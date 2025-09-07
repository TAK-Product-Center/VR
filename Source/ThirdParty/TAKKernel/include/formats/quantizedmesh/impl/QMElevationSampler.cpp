#include "formats/quantizedmesh/impl/QMElevationSampler.h"
#include "formats/quantizedmesh/TileCoord.h"
#include "formats/quantizedmesh/impl/TerrainDataCache.h"


using namespace TAK::Engine;
using namespace TAK::Engine::Formats::QuantizedMesh;
using namespace TAK::Engine::Formats::QuantizedMesh::Impl;

QMElevationSampler::QMElevationSampler(const char *file, double maxGsd) : data()
{
    int level = TileCoord_getLevel(maxGsd);
    data = TerrainDataCache_getData(file, level);
}

QMElevationSampler::QMElevationSampler(const std::shared_ptr<TerrainData> &data_) NOTHROWS :
    data(data_)
{}

QMElevationSampler::~QMElevationSampler() NOTHROWS
{
}


Util::TAKErr QMElevationSampler::sample(double *value, const double latitude, const double longitude) NOTHROWS
{
    // QM interpretation is HAE, no conversion from MSL required
    const auto convertToHae = false;
    double ret = data ? data->getElevation(latitude, longitude, convertToHae) : NAN;
    *value = ret;
    return TE_ISNAN(ret) ? Util::TE_Done : Util::TE_Ok;
}

Util::TAKErr QMElevationSampler::sample(double *value, const std::size_t count,
    const double *srcLat, const double *srcLng, 
    const std::size_t srcLatStride, const std::size_t srcLngStride,
    const std::size_t dstStride) NOTHROWS
{
    //return data->getElevation(value, count, srcLat, srcLng, srcLatStride, srcLngStride, dstStride, true);
    return data ?
        Sampler::sample(value, count, srcLat, srcLng, srcLatStride, srcLngStride, dstStride) :
        Util::TE_Done;
}