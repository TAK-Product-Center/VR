#include "formats/dted/DtedSampler.h"

#include <map>
#include <vector>

#include "elevation/ElevationManager.h"
#include "formats/dted/DtedChunkReader.h"
#include "math/Rectangle.h"
#include "thread/Mutex.h"
#include "thread/Lock.h"
#include "util/ConfigOptions.h"
#include "util/DataInput2.h"
#include "util/MathUtils.h"

using namespace TAK::Engine::Formats::DTED;

using namespace TAK::Engine::Elevation;
using namespace TAK::Engine::Util;

#define _LNG_OF_ORIGIN_OFFSET 4
#define _LAT_OF_ORIGIN_OFFSET 12
#define _NUM_LNG_LINES_OFFSET 47
#define _HEADER_OFFSET 3428
#define _DATA_RECORD_PREFIX_SIZE 8
#define _DATA_RECORD_SUFFIX_SIZE 4

namespace {
/** Checks the sample and interprets it */
double interpretSample(const unsigned short s) NOTHROWS;
/** Actually acquires the height from the given parameters in MSL */
TAKErr getHeight(double *value, FileInput2 &fs, const double latOrigin, const double lngOrigin, const double latitude, const double longitude, const int latPoints, const int lngLines, const int dataRecSize) NOTHROWS;
/** Reads and interprets the DTED file. */
TAKErr readAndInterp(double *value, FileInput2 &fs, const int dataRecSize, const double xratio, const double yratio) NOTHROWS;
}  // namespace

DtedSampler::DtedSampler(const char *file_, const double latitude, const double longitude) NOTHROWS :
    bounds(longitude, latitude-1.0, 0.0, longitude+1.0, latitude, 0.0)
{
    file.valid = file.stream.open(file_);
}

TAKErr DtedSampler::sample(double *value, const double latitude, const double longitude) NOTHROWS {
    TAKErr code(TE_Ok);
    if (!atakmap::math::Rectangle<double>::contains(bounds.minX, bounds.minY, bounds.maxX, bounds.maxY, longitude, latitude))
        return TE_InvalidArg;

    double msl;
    if(file.valid != TE_Ok) return file.valid;

    if(!reader.initialized) {
        reader.value._cellLat = bounds.maxY;
        reader.value._cellLng = bounds.minX;
        code = reader.value.readHeader(file.stream);
        TE_CHECKRETURN_CODE(code);
        reader.initialized = true;
    }

    code = getHeight(&msl, file.stream, bounds.minY, bounds.minX, latitude, longitude, (int)reader.value._extentY, (int)reader.value._extentX, (int)reader.value._dataRecSize);
    TE_CHECKRETURN_CODE(code);
    double msl2hae;
    if (TE_ISNAN(msl) || ElevationManager_getGeoidHeight(&msl2hae, latitude, longitude) != TE_Ok) return TE_Err;
    *value = (msl + msl2hae);
    return code;
}

TAKErr DtedSampler::sample(double *value, const std::size_t count, const double *srcLat, const double *srcLng,
                           const std::size_t srcLatStride, const std::size_t srcLngStride, const std::size_t dstStride) NOTHROWS {
    TAKErr code(TE_Ok);
    if (!value) return TE_InvalidArg;

    TE_CHECKRETURN_CODE(file.valid);
    auto &fs = file.stream;

    //Read the DTED header -From Dt2ElevationData.java
    auto &dt = reader.value;
    if(!reader.initialized) {
        reader.value._cellLat = bounds.maxY;
        reader.value._cellLng = bounds.minX;
        code = dt.readHeader(fs);
        TE_CHECKRETURN_CODE(code);
        reader.initialized = true;
    }

    //Start iterating the points -From Dt2ElevationData.java

    //We use a dictonary in place of the Java Hashmap

    struct PointRecord
    {
        double lat;
        double lng;
        std::size_t idx;
    };

    std::map<uint32_t, std::vector<PointRecord>> chunkedPoints;                
    for(std::size_t i = 0u; i < count; i++) {
        if (!TE_ISNAN(value[i * dstStride]))
            continue;

        PointRecord rec;
        rec.lat = srcLat[i*srcLatStride];
        rec.lng = srcLng[i*srcLngStride];
        rec.idx = i*dstStride;

        if (!atakmap::math::Rectangle<double>::contains(bounds.minX,
            bounds.minY,
            bounds.maxX,
            bounds.maxY,
            rec.lng,
            rec.lat))
        {
            // stays NAN, mark as incomplete
            code = TE_Done;
            continue;
        }

        std::size_t chunkX;
        if (dt.getChunkX(&chunkX, bounds.minX, rec.lng) != TE_Ok)
            continue;
        std::size_t chunkY;
        if (dt.getChunkY(&chunkY, bounds.maxY, rec.lat) != TE_Ok)
            continue;
        const uint32_t key = (uint32_t)((chunkX & 0xFFFF) << 16) | (chunkY & 0xFFFF);
        std::vector<PointRecord>& pts = chunkedPoints[key];
        if (pts.empty())
            pts.reserve(count - i);
        pts.push_back(rec);
    }

    for (auto chunksIter = chunkedPoints.begin(); chunksIter != chunkedPoints.end(); chunksIter++)
    {
        uint32_t key = chunksIter->first;
        const std::size_t chunkX = (key >> 16) & 0xFFFF;
        const std::size_t chunkY = (key & 0xFFFF);
        if (dt.loadChunk(fs, chunkX, chunkY) != TE_Ok) {
            // chunk failed to load, mark as incomplete
            code = TE_Done;
            continue;
        }
                    
        const auto chunkCols = dt.getChunkColumns();
        const auto chunkRows = dt.getChunkRows();
        const auto* chunkData = dt.getChunk();

        const auto& pts = chunksIter->second;
        const std::size_t lim = pts.size();
        for (std::size_t i = 0u; i < lim; i++)
        {
            const PointRecord& pt = pts[i];
            const double chunkPixelX = MathUtils_clamp<double>(dt.chunkLongitudeToPixelX(chunkX, pt.lng), 0.0, (double)chunkCols - 1.0);
            const double chunkPixelY = MathUtils_clamp<double>(dt.chunkLatitudeToPixelY(chunkY, pt.lat), 0.0, (double)chunkRows - 1.0);
            const std::size_t chunkLx = (std::size_t)chunkPixelX;
            const std::size_t chunkRx = (std::size_t)ceil(chunkPixelX);
            const std::size_t chunkTy = (std::size_t)chunkPixelY;
            const std::size_t chunkBy = (std::size_t)ceil(chunkPixelY);

            //These need testing, the bytebuffer in Java has a getshort, we're relying
            //on GetValue to do the same thing here.
#define getShortBE(arr, off) \
    ((short)(((arr[off] & 0xFFu) << 8u) | (arr[off + 1u] & 0xFFu)))

            double chunkUL = interpretSample(
                getShortBE(chunkData, 
                            (chunkTy * 2 * chunkCols) + chunkLx * 2));
            double chunkUR = interpretSample(
                getShortBE(chunkData,
                            (chunkTy * 2 * chunkCols) + chunkRx * 2));
            double chunkLR = interpretSample(
                getShortBE(chunkData,
                            (chunkBy * 2 * chunkCols) + chunkRx * 2));
            double chunkLL = interpretSample(
                getShortBE(chunkData,
                            (chunkBy * 2 * chunkCols) + chunkLx * 2));
#undef getShortBE

            const std::size_t dstIdx = pt.idx;
            if (TE_ISNAN(chunkUL)
                || TE_ISNAN(chunkUR)
                || TE_ISNAN(chunkLR)
                || TE_ISNAN(chunkLL)) {

                // remains NAN, mark as incomplete
                code = TE_Done;
            } else {
                double msl2hae;
                if (ElevationManager_getGeoidHeight(&msl2hae, pt.lat, pt.lng) != TE_Ok)
                    continue;

                const double wR = chunkPixelX
                    - chunkLx;
                const double wL = 1.0f - wR;
                const double wB = chunkPixelY
                    - chunkTy;
                const double wT = 1.0f - wB;

                // XXX - should we divide to average
                //       out nulls??? -From Dt2ElevationData.java
                value[dstIdx] = 
                    ((wL * wT) * chunkUL) +
                    ((wR * wT) * chunkUR) +
                    ((wR * wB) * chunkLR) +
                    ((wL * wB) * chunkLL) +
                    msl2hae;
            }
        }
    }

    return code;
}

TAKErr TAK::Engine::Formats::DTED::DTED_sample(double *value, const char *file, const double latitude, const double longitude) NOTHROWS {
    TAKErr code(TE_Ok);
    FileInput2 fs;
    code = fs.open(file);
    TE_CHECKRETURN_CODE(code);

    code = fs.seek(_NUM_LNG_LINES_OFFSET);
    TE_CHECKRETURN_CODE(code);
    uint8_t bytes[8u];

    std::size_t numRead;
    if (fs.read(bytes, &numRead, 8u) != TE_Ok || numRead < 8u) {  // read did not get all of the information required
        *value = NAN;
        return TE_EOF;
    }

    // read header
    char lngBytes[5u];
    char latBytes[5u];
    for (std::size_t i = 0u; i < 4u; i++) {
        lngBytes[i] = bytes[i];
        latBytes[i] = bytes[i + 4u];
    }
    lngBytes[4u] = '\0';
    latBytes[4u] = '\0';

    int lngLines;
    code = TAK::Engine::Port::String_parseInteger(&lngLines, lngBytes);
    TE_CHECKRETURN_CODE(code);
    int latPoints;
    code = TAK::Engine::Port::String_parseInteger(&latPoints, latBytes);
    TE_CHECKRETURN_CODE(code);
    int dataRecSize = _DATA_RECORD_PREFIX_SIZE + (latPoints * 2) + _DATA_RECORD_SUFFIX_SIZE;

    double latOrigin = floor(latitude);
    double lngOrigin = floor(longitude);
    if(fabs(latOrigin-latitude) < 1e-12 || fabs(lngOrigin-longitude) < 1e-12) {
        // longitude origin
        code = fs.seek(_LNG_OF_ORIGIN_OFFSET);
        TE_CHECKRETURN_CODE(code);

        if (fs.read(bytes, &numRead, 8u) != TE_Ok || numRead < 8u) {  // read did not get all of the information required
            *value = NAN;
            return TE_EOF;
        }

        bytes[4u] = '\0';
        int lngDegrees;
        code = TAK::Engine::Port::String_parseInteger(&lngDegrees, reinterpret_cast<const char *>(bytes));
        TE_CHECKRETURN_CODE(code);
        lngOrigin = lngDegrees * ((bytes[7u] == 'W') ? -1 : 1);

        // latitude origin
        code = fs.seek(_LAT_OF_ORIGIN_OFFSET);
        TE_CHECKRETURN_CODE(code);

        if (fs.read(bytes, &numRead, 8u) != TE_Ok || numRead < 8u) {  // read did not get all of the information required
            *value = NAN;
            return TE_EOF;
        }

        bytes[3u] = '\0';
        int latDegrees;
        code = TAK::Engine::Port::String_parseInteger(&latDegrees, reinterpret_cast<const char *>(bytes));
        TE_CHECKRETURN_CODE(code);
        latOrigin = latDegrees * ((bytes[7u] == 'S') ? -1 : 1);
    }

    return getHeight(value, fs, latOrigin, lngOrigin, latitude, longitude, latPoints, lngLines, dataRecSize);
}

namespace {
double interpretSample(const unsigned short s) NOTHROWS {
    if (s == 0xFFFF) return NAN;
    double val = (1 - (2 * ((s & 0x8000) >> 15))) * (s & 0x7FFF);
    // per MIL-PRF89020B 3.11.2, elevation values should never exceed these values
    if ((val < -12000) || (val > 9000)) return NAN;
    return val;
}

/*
Actually acquires the height from the given parameters in MSL
*/
TAKErr getHeight(double *value, FileInput2 &fs, const double latOrigin, const double lngOrigin, const double latitude, const double longitude, const int latPoints, const int lngLines, const int dataRecSize) NOTHROWS {
    TAKErr code(TE_Ok);

    double latRatio = latitude - latOrigin;
    double lngRatio = longitude - lngOrigin;

    double yd = latRatio * (latPoints - 1);
    double xd = lngRatio * (lngLines - 1);

    int x = (int)xd;
    int y = (int)yd;

    int byteOffset = _HEADER_OFFSET + x * dataRecSize + _DATA_RECORD_PREFIX_SIZE + y * 2;

    code = fs.seek(byteOffset);
    TE_CHECKRETURN_CODE(code);

    return readAndInterp(value, fs, dataRecSize, xd - x, yd - y);
}

/*
Reads and interprets the DTED file.
*/
TAKErr readAndInterp(double *value, FileInput2 &fs, const int dataRecSize, const double xratio, const double yratio) NOTHROWS {
    TAKErr code(TE_Ok);

    auto readSample = [&]()
    {
        uint8_t bb[2];
        std::size_t numRead;
        if(fs.read(bb, &numRead, 2u) != TE_Ok) return (double)NAN;
        if (numRead < 2u) return (double)NAN;
        return (double)interpretSample((bb[0] << 8) | (bb[1]));
    };

    double sw = readSample();
    double nw = readSample();

    fs.skip(dataRecSize - 4);

    double se = readSample();
    double ne = readSample();

    if (TE_ISNAN(sw) && TE_ISNAN(nw) && TE_ISNAN(se) && TE_ISNAN(ne)) {
        *value = NAN;
        return TE_Ok;
    }

    double mids = 0;
    double midn = 0;

    constexpr unsigned NW_NODATA = 1u;
    constexpr unsigned NE_NODATA = 2u;
    constexpr unsigned SW_NODATA = 4u;
    constexpr unsigned SE_NODATA = 8u;

    unsigned noDataMask = 0u;
    if(TE_ISNAN(nw)) noDataMask |= NW_NODATA;
    if(TE_ISNAN(ne)) noDataMask |= NE_NODATA;
    if(TE_ISNAN(sw)) noDataMask |= SW_NODATA;
    if(TE_ISNAN(se)) noDataMask |= SE_NODATA;
    switch(noDataMask) {
        case 0u :
            mids = sw + (se - sw) * xratio;
            midn = nw + (ne - nw) * xratio;
            break;
        case NW_NODATA :
            mids = sw + (se - sw) * xratio;
            midn = ne;
            break;
        case NE_NODATA :
            mids = sw + (se - sw) * xratio;
            midn = nw;
            break;
        case NW_NODATA|NE_NODATA :
            mids = sw + (se - sw) * xratio;
            midn = sw + (se - sw) * xratio;
            break;
        case SW_NODATA :
            mids = se;
            midn = nw + (ne - nw) * xratio;
            break;
        case NW_NODATA|SW_NODATA :
            mids = se;
            midn = ne;
            break;
        case NE_NODATA|SW_NODATA :
            mids = se;
            midn = nw;
            break;
        case NW_NODATA|NE_NODATA|SW_NODATA:
            mids = se;
            midn = se;
            break;
        case SE_NODATA :
            mids = sw;
            midn = nw + (ne - nw) * xratio;
            break;
        case NW_NODATA|SE_NODATA :
            mids = sw;
            midn = ne;
            break;
        case NE_NODATA|SE_NODATA :
            mids = sw;
            midn = nw;
            break;
        case NW_NODATA|NE_NODATA|SE_NODATA :
            mids = sw;
            midn = sw;
            break;
        case SW_NODATA|SE_NODATA :
            mids = nw + (ne - nw) * xratio;
            midn = nw + (ne - nw) * xratio;
            break;
        case NW_NODATA|SW_NODATA|SE_NODATA :
            mids = ne;
            midn = ne;
            break;
        case NE_NODATA|SW_NODATA|SE_NODATA :
            mids = nw;
            midn = nw;
            break;
        case NW_NODATA|NE_NODATA|SW_NODATA|SE_NODATA :
        default :
            *value = NAN;
            return code;
    }

    *value = mids + (midn - mids) * yratio;
    return code;
}
}  // namespace
