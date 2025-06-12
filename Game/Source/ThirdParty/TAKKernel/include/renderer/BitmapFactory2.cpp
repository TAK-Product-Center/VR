#include "renderer/BitmapFactory2.h"

#include <algorithm>
#include <sstream>

#include "formats/gdal/GdalBitmapReader.h"
#include "util/DataOutput2.h"
#include "util/Memory.h"
#include "util/Logging2.h"

#include "gdal_priv.h"

using namespace TAK::Engine::Renderer;
using namespace TAK::Engine::Util;
using namespace TAK::Engine::Formats::GDAL;

TAKErr TAK::Engine::Renderer::BitmapFactory2_decode(BitmapPtr &result, DataInput2 &input, const BitmapDecodeOptions *opts) NOTHROWS
{
    TAKErr code(TE_Ok);
    if (input.length() <= 0LL) {
        DynamicOutput membuf;
        code = membuf.open(64u * 1024u);
        TE_CHECKRETURN_CODE(code);
        code = IO_copy(membuf, input);
        TE_CHECKRETURN_CODE(code);

        const uint8_t* data;
        std::size_t dataLen;
        code = membuf.get(&data, &dataLen);
        TE_CHECKRETURN_CODE(code);

        return BitmapFactory2_decode(result, data, dataLen, opts);
    } else {
        const std::size_t dataLen = (std::size_t)input.length();
        array_ptr<uint8_t> data(new uint8_t[dataLen]);
        std::size_t n;
        code = input.read(data.get(), &n, dataLen);
        TE_CHECKRETURN_CODE(code);
        if (n < dataLen)
            return TE_EOF;
        return BitmapFactory2_decode(result, data.get(), dataLen, opts);
    }
}
TAKErr TAK::Engine::Renderer::BitmapFactory2_decode(BitmapPtr &result, const uint8_t *data, const std::size_t dataLen, const BitmapDecodeOptions *opts) NOTHROWS
{
    TAKErr code(TE_Ok);

    std::ostringstream os;
    os << "/vsimem/";
    os << (uintptr_t)(void *)data;

    const std::string gdalMemoryFile(os.str().c_str());

    VSILFILE *fpMem = VSIFileFromMemBuffer(gdalMemoryFile.c_str(), (GByte*) data , (vsi_l_offset) dataLen, FALSE);
    if (nullptr == fpMem)
        return TE_IllegalState;

    int gdalCode = VSIFCloseL(fpMem);
    code = 0 == gdalCode ?
        BitmapFactory2_decode(result, gdalMemoryFile.c_str(), opts) :
        TE_IllegalState;

    VSIUnlink(gdalMemoryFile.c_str());

    return code;
}
TAKErr TAK::Engine::Renderer::BitmapFactory2_decode(BitmapPtr &result, const char *bitmapFilePath, const BitmapDecodeOptions *opts) NOTHROWS
{
    TAKErr code(TE_Ok);
    GdalBitmapReader reader(bitmapFilePath);
    // check if the dataset could be opened
    if (nullptr == reader.getDataset())
        return TE_InvalidArg;

    const int srcWidth = reader.getWidth();
    const int srcHeight = reader.getHeight();
    int dstWidth = srcWidth;
    int dstHeight = srcHeight;

#if 1
    // XXX - force subsampling
    if (dstWidth > 2048 || dstHeight > 2048) {
        double sampleX = 2048.0 / (double)srcWidth;
        double sampleY = 2048.0 / (double)srcHeight;
        double sample = std::min(sampleX, sampleY);
        dstWidth = static_cast<int>((double)dstWidth * sample);
        dstHeight = static_cast<int>((double)dstHeight * sample);
    }
#endif

    int numDataElements(0);
    code = reader.getPixelSize(numDataElements);
    TE_CHECKRETURN_CODE(code);
    const auto byteCount = static_cast<std::size_t>(numDataElements * dstWidth * dstHeight);

    if (TE_Ok == code) {
        Bitmap2::Format bitmapFormat;
        switch(reader.getFormat()) {
        case GdalBitmapReader::MONOCHROME:
            bitmapFormat = Bitmap2::MONOCHROME;
            break;
        case GdalBitmapReader::MONOCHROME_ALPHA:
            bitmapFormat = Bitmap2::MONOCHROME_ALPHA;
            break;
        case GdalBitmapReader::RGB:
            bitmapFormat = Bitmap2::RGB24;
            break;
        case GdalBitmapReader::RGBA:
            bitmapFormat = Bitmap2::RGBA32;
            break;
        case GdalBitmapReader::ARGB:
            bitmapFormat = Bitmap2::ARGB32;
            break;
        default:
            return TE_IllegalState;
        }

        if (opts &&
            opts->emplaceData &&
            result.get() &&
            result->getFormat() == bitmapFormat &&
            result->getWidth() == dstWidth &&
            result->getHeight() == dstHeight) {

            // nothing to do
        } else{
            Bitmap2::DataPtr data = Bitmap2::DataPtr(new(std::nothrow) uint8_t[byteCount], Util::Memory_array_deleter_const<uint8_t>);
            if (!data.get())
                return TE_OutOfMemory;
            result = BitmapPtr(new(std::nothrow) Bitmap2(std::move(data), dstWidth, dstHeight, bitmapFormat), Memory_deleter_const<Bitmap2>);
            if (!result.get())
                return TE_OutOfMemory;
        }

        code = reader.read(0, 0, srcWidth, srcHeight, dstWidth, dstHeight, result->getData(), byteCount);
        TE_CHECKRETURN_CODE(code);
    }

    return code;
}

TAKErr TAK::Engine::Renderer::BitmapFactory2_encode(const char *path, const Bitmap2 &bitmap, const BitmapEncodeOptions &opts) NOTHROWS
{
    FileOutput2 file;
    file.open(path);
    return BitmapFactory2_encode(file, bitmap, opts);
}
TAKErr TAK::Engine::Renderer::BitmapFactory2_encode(uint8_t* value, std::size_t* len, const std::size_t capacity, const Bitmap2 &bitmap, const BitmapEncodeOptions &opts) NOTHROWS
{
    TAKErr code(TE_Ok);
    if (!value || !len)
        return TE_InvalidArg;

    MemoryOutput2 sink;
    code = sink.open(value, capacity);
    TE_CHECKRETURN_CODE(code);
    code = BitmapFactory2_encode(sink, bitmap, opts);
    TE_CHECKRETURN_CODE(code);

    std::size_t remaining;
    code = sink.remaining(&remaining);
    TE_CHECKRETURN_CODE(code);

    *len = (capacity - remaining);
    return code;
}
TAKErr TAK::Engine::Renderer::BitmapFactory2_encode(Util::DataOutput2 &sink, const Bitmap2 &bitmap, const BitmapEncodeOptions &opts) NOTHROWS
{
    GDALDriverH outdriver;
    if (opts.format == TEBF_JPEG)
        outdriver = GDALGetDriverByName("JPEG");
    else if (opts.format == TEBF_PNG)
        outdriver = GDALGetDriverByName("PNG");
    else return TE_InvalidArg;

    auto memdriver = GDALGetDriverByName("MEM");

    std::ostringstream os;
    os << "/vsimem/";
    os << (uintptr_t)(void*)&bitmap << ".bmp";
    const std::string gdalMemoryFileBmp(os.str().c_str());
    
    std::ostringstream os2;
    os2 << "/vsimem/";
    os2 << (uintptr_t)(void*)&bitmap << ".out";
    const std::string gdalMemoryFileOut(os2.str().c_str());

    std::vector<uint8_t> jpgdata, output;
    bool hasAlpha = bitmap.getFormat() == Bitmap2::ARGB32 || bitmap.getFormat() == Bitmap2::RGBA32 || bitmap.getFormat() == Bitmap2::BGRA32 || bitmap.getFormat() == Bitmap2::RGBA5551;
    int bytes = hasAlpha ? 4 : 3;
    jpgdata.resize(bitmap.getWidth() * bitmap.getHeight() * bytes + 54);
    output.resize(bitmap.getWidth() * bitmap.getHeight() * bytes + 54);

    VSILFILE* fpJpg = VSIFileFromMemBuffer(gdalMemoryFileOut.c_str(), (GByte*)jpgdata.data(), (vsi_l_offset)jpgdata.size(), FALSE);
    if (!fpJpg)
        return TE_Err;
    VSIFCloseL(fpJpg);
    std::shared_ptr<VSILFILE> sharedJpg(fpJpg, [&gdalMemoryFileOut](VSILFILE* file) {VSIUnlink(gdalMemoryFileOut.c_str()); });

    BitmapPtr_const rgbptr(&bitmap, Memory_leaker_const<Bitmap2>);
    if (hasAlpha && bitmap.getFormat() != Bitmap2::RGBA32) 
        rgbptr = BitmapPtr_const(new Bitmap2(bitmap, Bitmap2::RGBA32), Memory_deleter_const<Bitmap2>);
    else if(!hasAlpha && bitmap.getFormat() != Bitmap2::RGB24) 
        rgbptr = BitmapPtr_const(new Bitmap2(bitmap, Bitmap2::RGB24), Memory_deleter_const<Bitmap2>);
    auto& rgb = *rgbptr;

    auto dataset = (GDALDataset*)GDALCreate(memdriver, gdalMemoryFileBmp.c_str(), (int)rgb.getWidth(), (int)rgb.getHeight(), bytes, GDT_Byte, nullptr);
    if (!dataset)
        return TE_Err;
    std::shared_ptr<GDALDataset> datasetPtr(dataset, [](GDALDataset* ds) {GDALClose(ds); });

    dataset->GetRasterBand(1)->SetColorInterpretation(GCI_RedBand);
    dataset->GetRasterBand(2)->SetColorInterpretation(GCI_GreenBand);
    dataset->GetRasterBand(3)->SetColorInterpretation(GCI_BlueBand);
    if(hasAlpha)
        dataset->GetRasterBand(4)->SetColorInterpretation(GCI_AlphaBand);

    CPLErr err = CE_None;
    if(hasAlpha)
        err = GDALRasterIO(dataset->GetRasterBand(4), GF_Write, 0, 0, (int)rgb.getWidth(), (int)rgb.getHeight(), (char*)rgb.getData() + 3, (int)rgb.getWidth(), (int)rgb.getHeight(), GDT_Byte, bytes, 0);
    err = GDALRasterIO(dataset->GetRasterBand(1), GF_Write, 0, 0, (int)rgb.getWidth(), (int)rgb.getHeight(), (char*)rgb.getData() + 0, (int)rgb.getWidth(), (int)rgb.getHeight(), GDT_Byte, bytes, 0);
    err = GDALRasterIO(dataset->GetRasterBand(2), GF_Write, 0, 0, (int)rgb.getWidth(), (int)rgb.getHeight(), (char*)rgb.getData() + 1, (int)rgb.getWidth(), (int)rgb.getHeight(), GDT_Byte, bytes, 0);
    err = GDALRasterIO(dataset->GetRasterBand(3), GF_Write, 0, 0, (int)rgb.getWidth(), (int)rgb.getHeight(), (char*)rgb.getData() + 2, (int)rgb.getWidth(), (int)rgb.getHeight(), GDT_Byte, bytes, 0);

    auto jpgdataset = (GDALDataset*)GDALCreateCopy(outdriver, gdalMemoryFileOut.c_str(), dataset, false, nullptr, nullptr, nullptr);
    if (!jpgdataset)
        return TE_Err;

    GDALClose(jpgdataset);

    fpJpg = VSIFOpenL(gdalMemoryFileOut.c_str(), "rb");
    if (!fpJpg)
        return TE_Err;

    auto read = VSIFReadL(output.data(), 1, output.size(), fpJpg);
    if (!read || read == output.size())
    {
        VSIFCloseL(fpJpg);
        return TE_Err;
    }

    sink.write(output.data(), read);
    
    VSIFCloseL(fpJpg);
    
    return TE_Ok;
}
