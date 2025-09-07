#include "GdalDatasetProjection.h"
#include "GdalLibrary.h"
#include "RapidPositioningControlB.h"
#include "math/Utils.h"
#include "math/Matrix.h"
#include "util/IO.h"
#include <map>

namespace {
    using namespace atakmap;
    using namespace atakmap::raster::gdal;

    class GCPHolder {
    public:
        TAK::Engine::Port::String id;
        TAK::Engine::Port::String info;
        GDAL_GCP gcp;

        GCPHolder(const GDAL_GCP &sgcp) :
            GCPHolder(sgcp.dfGCPX, sgcp.dfGCPY, sgcp.dfGCPPixel, sgcp.dfGCPLine, sgcp.pszId, sgcp.pszInfo)
        {}
        GCPHolder(double x, double y, double pixel, double line, const char *id_, const char *info_) :
            id(id_),
            info(info_)
        {
            gcp.pszInfo = info.get();
            gcp.pszId = id.get();
            gcp.dfGCPLine = line;
            gcp.dfGCPPixel = pixel;
            gcp.dfGCPX = x;
            gcp.dfGCPY = y;

        }
        GCPHolder(const GCPHolder &sgcp) :
            GCPHolder(sgcp.gcp.dfGCPX, sgcp.gcp.dfGCPY, sgcp.gcp.dfGCPPixel, sgcp.gcp.dfGCPLine, sgcp.gcp.pszId, sgcp.gcp.pszInfo)
        {}
    };

    class ICHIPB
    {
    private:
        math::Matrix op2fi;

    public:
        // XXX - Consider not assigning/removing unreferenced variables from this class if possible.
        ICHIPB(util::DataInput *input) : op2fi() {
            /*const int xform_flag =*/ input->readAsciiInt(2);
            /*const double scale_factor =*/ input->readAsciiDouble(10);
            /*const int anamrph_corr =*/ input->readAsciiInt(2);
            /*const int scanblk_num =*/ input->readAsciiInt(2);
            const double op_row_11 = input->readAsciiDouble(12);
            const double op_col_11 = input->readAsciiDouble(12);
            const double op_row_12 = input->readAsciiDouble(12);
            const double op_col_12 = input->readAsciiDouble(12);
            const double op_row_21 = input->readAsciiDouble(12);
            const double op_col_21 = input->readAsciiDouble(12);
            const double op_row_22 = input->readAsciiDouble(12);
            const double op_col_22 = input->readAsciiDouble(12);
            const double fi_row_11 = input->readAsciiDouble(12);
            const double fi_col_11 = input->readAsciiDouble(12);
            const double fi_row_12 = input->readAsciiDouble(12);
            const double fi_col_12 = input->readAsciiDouble(12);
            const double fi_row_21 = input->readAsciiDouble(12);
            const double fi_col_21 = input->readAsciiDouble(12);
            const double fi_row_22 = input->readAsciiDouble(12);
            const double fi_col_22 = input->readAsciiDouble(12);
            /*const int fi_row =*/ input->readAsciiInt(8);
            /*const int fi_col =*/ input->readAsciiInt(8);

            math::Matrix::mapQuads(op_col_11, op_row_11,
                                         op_col_12, op_row_12,
                                         op_col_22, op_row_22,
                                         op_col_21, op_row_21,
                                         fi_col_11, fi_row_11,
                                         fi_col_12, fi_row_12,
                                         fi_col_22, fi_row_22,
                                         fi_col_21, fi_row_21,
                                         &op2fi);
        }

        const math::Matrix *getTransform() {
            return &op2fi;
        }

    };



    class GroundControlPoints : public GdalDatasetProjection {
        math::Matrix img2proj;
        math::Matrix proj2img;

    public:
        GroundControlPoints(GDALDataset *dataset, const std::vector<GCPHolder> &gcps, const char *projectionRef, ICHIPB *ichipb = nullptr)  :
            GdalDatasetProjection(projectionRef)
        {
            std::map<std::string, unsigned> id2idx;
            id2idx["UpperLeft"] = 0u;
            id2idx["UpperRight"] = 1u;
            id2idx["LowerRight"] = 2u;
            id2idx["LowerLeft"] = 3u;

            math::PointD src[4];
            math::PointD dst[4];
            uint8_t src2dst = 0u;
            int idx;
            for (size_t i = 0; i < gcps.size(); i++) {
                if (!gcps[i].id)
                    continue;
                std::string id(gcps[i].id.get());
                auto iter = id2idx.find(id);
                if (iter == id2idx.end())
                    continue;
                idx = iter->second;
                if (src2dst & (1u << idx))
                    continue;
                const auto &gcp = gcps[i].gcp;
                src[idx] = math::PointD(gcp.dfGCPPixel, gcp.dfGCPLine);
                dst[idx] = math::PointD(gcp.dfGCPX, gcp.dfGCPY);
                src2dst |= (1u << idx);
                if (src2dst == 0xFu)
                    break;
            }

            if(src2dst != 0xFu) {
                throw std::invalid_argument("missing GCPs");
            }

            math::Matrix::mapQuads(src + 0, src + 1, src + 2, src + 3,
                                    dst + 0, dst + 1, dst + 2, dst + 4,
                                    &img2proj);
            if (ichipb)
                img2proj.concatenate(ichipb->getTransform());

            img2proj.createInverse(&proj2img);

            initMinimumBoundingBox(dataset);
        }

    protected:
        math::PointD projected2image(const math::PointD &p) override {
            math::PointD ret;
            proj2img.transform(&p, &ret);
            return ret;
        }

        math::PointD image2projected(const math::PointD &p) override {
            math::PointD ret;
            img2proj.transform(&p, &ret);
            return ret;
        }
    };


    class GeoTransform : public GdalDatasetProjection {
    private:
        double img2proj[6];
        double proj2img[6];

    public:
        GeoTransform(GDALDataset *dataset) : GdalDatasetProjection(dataset->GetProjectionRef()) {

            if (dataset->GetGeoTransform(img2proj) == CE_Failure
                || !GDALInvGeoTransform(img2proj, proj2img))
              {
                throw std::invalid_argument
                          ("Received GDALDataset with uninvertable geo transform");
              }

            initMinimumBoundingBox(dataset);
        }

    protected:
        math::PointD image2projected(const math::PointD &p) override
        {
            double projX = img2proj[0] + p.x * img2proj[1] + p.y * img2proj[2];
            double projY = img2proj[3] + p.x * img2proj[4] + p.y * img2proj[5];

            return math::PointD(projX, projY);
        }

        math::PointD projected2image(const math::PointD &p) override
        {
            double imgX = proj2img[0] + p.x * proj2img[1] + p.y * proj2img[2];
            double imgY = proj2img[3] + p.x * proj2img[4] + p.y * proj2img[5];

            return math::PointD(imgX, imgY);
        }
    };




    bool CSLContainsValue(char **csl, const char *v)
    {
        if (!csl)
            return false;
        size_t vlen = strlen(v);

        int c = 0;
        while (csl[c]) {
            char *cc = csl[c++];
            size_t cclen = strlen(cc);
            if (cclen < vlen + 1)
                // too small to have the separator + value
                continue;

            char *comparePoint = cc + (cclen - vlen - 1);
            if (*comparePoint != ':' && *comparePoint != '=')
                continue;

            comparePoint++;
            if (strcmp(comparePoint, v) == 0)
                return true;
        }
        return false;
    }

    bool checkBLOCKA(const char *blocka) {
        const char *locationSection = blocka + 34;
        std::string locationSectionTrimmed = atakmap::util::trimASCII(locationSection);
        if (locationSectionTrimmed.size() < 84)
            return false;
#if 0 // XXX - needs regex matching....
        else if (locationSection
                 .matches("([NS]0{6}\\.00\\[EW]0{7}\\.00|[\\+\\-]0{2}\\.0{6}[\\+\\-]0{3}\\.0{6}){4}"))
                 return false;
        return locationSection
            .matches("([NS]\\d{6}\\.\\d{2}\\[EW]\\d{7}\\.\\d{2}|[\\+\\-]\\d{2}\\.\\d{6}[\\+\\-]\\d{3}\\.\\d{6}){4}");
#else
        return false;
#endif
    }

    std::vector<GCPHolder> getCscrnaGCPs(GDALDataset *dataset, const char *cscrna) {
        std::vector<GCPHolder> gcps;
        gcps.reserve(4u);
        const char *ids[4] = {
            "UpperLeft", "UpperRight", "LowerRight", "LowerLeft"
        };
        double pixel[] = {
            0.5, (double)dataset->GetRasterXSize() - 0.5
        };
        double line[] = {
            0.5, (double)dataset->GetRasterYSize() - 0.5
        };

        util::MemoryInput input;
        input.open((uint8_t *)cscrna, strlen(cscrna));

        try {
            input.skip(1); // predict_corners
            for (int i = 0; i < 4; i++) {
                double lat = input.readAsciiDouble(9);
                double lon = input.readAsciiDouble(10);
                input.skip(8); // XXcnr_ht

                gcps.push_back(GCPHolder(lon, lat,
                    pixel[((i + (i / 2)) % 2)], line[(i / 2)], ids[i], "CSCRNA"));
            }
        } catch (...) {
            input.close();
            throw std::invalid_argument("Invalid cscrna string");
        }
        input.close();

        return gcps;
    }

    std::vector<GCPHolder> getRpcGCPs(GDALDataset *dataset) {
        RapidPositioningControlB rpc00b(dataset);

        std::vector<GCPHolder> gcps;
        gcps.reserve(4u);
        const char *ids[4] = {
            "UpperLeft", "UpperRight", "LowerRight", "LowerLeft"
        };
        double pixel[] = {
            0.5, (double)dataset->GetRasterXSize() - 0.5
        };
        double line[] = {
            0.5, (double)dataset->GetRasterYSize() - 0.5
        };

        for (int i = 0; i < 4; i++) {
            core::GeoPoint p = rpc00b.inverse(math::PointD(pixel[((i + (i / 2)) % 2)], line[(i / 2)]));

            gcps.push_back(GCPHolder(p.longitude, p.latitude, pixel[((i + (i / 2)) % 2)],
                line[(i / 2)], ids[i], "RPC00B"));
        }

        return gcps;
    }


    bool isUsableProjection(const char *wkt) {
        return (wkt != nullptr && strlen(wkt) > 0);
    }

}

namespace atakmap {
    namespace raster {
        namespace gdal {

            GdalDatasetProjection::GdalDatasetProjection(const char *projectionRef) :
                datasetSpatialReference(OSRNewSpatialReference(projectionRef)),
                proj2geo(OCTNewCoordinateTransformation(datasetSpatialReference, (OGRSpatialReferenceH)GdalLibrary::EPSG_4326)),
                geo2proj(OCTNewCoordinateTransformation((OGRSpatialReferenceH)GdalLibrary::EPSG_4326, datasetSpatialReference)),
                nativeSpatialReferenceID(GdalLibrary::getSpatialReferenceID((OGRSpatialReference *)datasetSpatialReference)),
                minLat(0),
                minLon(0),
                maxLat(0),
                maxLon(0)
            {
            }

            GdalDatasetProjection::~GdalDatasetProjection()
            {
                OCTDestroyCoordinateTransformation(proj2geo);
                OCTDestroyCoordinateTransformation(geo2proj);
                OSRDestroySpatialReference(datasetSpatialReference);
            }

            void GdalDatasetProjection::forward(const core::GeoPoint *geo, math::Point<double> *proj)
            {
                double x = geo->longitude;
                double y = geo->latitude;
                OCTTransform(geo2proj, 1, &x, &y, nullptr);

                math::PointD r = projected2image(math::PointD(x, y));
                proj->x = r.x;
                proj->y = r.y;
            }

            void GdalDatasetProjection::inverse(const math::Point<double> *proj, core::GeoPoint *geo)
            {
                math::PointD p = image2projected(*proj);

                double x = p.x;
                double y = p.y;
                double z = 0.0;
                OCTTransform(proj2geo, 1, &x, &y, nullptr);

                geo->set(y, x);
            }

            double GdalDatasetProjection::getMinLatitude()
            {
                return minLat;
            }

            double GdalDatasetProjection::getMaxLatitude()
            {
                return maxLat;
            }

            double GdalDatasetProjection::getMinLongitude()
            {
                return minLon;
            }

            double GdalDatasetProjection::getMaxLongitude()
            {
                return maxLon;
            }

            bool GdalDatasetProjection::is3D()
            {
                // XXX - (marked such in Java)
                return false;
            }

            int GdalDatasetProjection::getSpatialReferenceID()
            {
                return -1;
            }

            int GdalDatasetProjection::getNativeSpatialReferenceID()
            {
                return nativeSpatialReferenceID;
            }

            bool GdalDatasetProjection::isUsableGeoTransform(double geoTransform[6])
            {
                if (geoTransform == nullptr)
                    return false;
                for (size_t i = 0; i < 6; i++)
                    if (geoTransform[i] != 0)
                        return true;
                return false;
            }

            bool GdalDatasetProjection::shouldUseNitfHighPrecisionCoordinates(GDALDataset *dataset)
            {
                bool ret = true;
                GDALDriver *driver = dataset->GetDriver();
                if (strcmp(driver->GetDescription(), "NITF") != 0)
                    return false;
#if 1
                char **TREs = dataset->GetMetadata("TRE");
                bool hasCSCRNA = false;
                if (TREs != nullptr) {
                    // GDAL will automatically utilize high precision coordinates in the
                    // presence of some TREs, check for these TREs, and, if present, return

                    // RPF TREs
                    if (CSLFetchNameValue(TREs, "RPFIMG") && CSLFetchNameValue(TREs, "RPFDES") && CSLContainsValue(TREs, "RPFHDR"))
                        ret = false;
                    // BLOCKA
                    if (ret && CSLFetchNameValue(TREs, "BLOCKA") && checkBLOCKA(CSLFetchNameValue(TREs, "BLOCKA")))
                        ret = false;
                    // GEOSDEs
                    if (ret && CSLFetchNameValue(TREs, "GEOPSB") && CSLFetchNameValue(TREs, "PRJPSB") && CSLFetchNameValue(TREs, "MAPLOB"))
                        ret = false;

                    if (ret)
                        hasCSCRNA = CSLFetchNameValue(TREs, "CSCRNA") != nullptr;
                    //CSLDestroy(TREs);
                }

                bool hasRPC = false;
                if (ret && !hasCSCRNA) {
                    char **RPCList = dataset->GetMetadata("RPC");
                    if (RPCList) {
                        hasRPC = CSLCount(RPCList) > 0;
                        //CSLDestroy(RPCList);
                    }
                }
                ret &= (hasCSCRNA || hasRPC);
#endif
                return ret;
            }


            void GdalDatasetProjection::initMinimumBoundingBox(GDALDataset *dataset)
            {
                core::GeoPoint p[4];
                math::PointD pts[4] = {
                    math::PointD(0, 0),
                    math::PointD(dataset->GetRasterXSize(), 0),
                    math::PointD(dataset->GetRasterXSize(), dataset->GetRasterYSize()),
                    math::PointD(0, dataset->GetRasterYSize())
                };

                for (int i = 0; i < 4; ++i)
                    inverse(pts + i, p + i);
                minLat = math::min(p[0].latitude, p[1].latitude, p[2].latitude, p[3].latitude);
                minLon = math::min(p[0].longitude, p[1].longitude, p[2].longitude, p[3].longitude);
                maxLat = math::max(p[0].latitude, p[1].latitude, p[2].latitude, p[3].latitude);
                maxLon = math::max(p[0].longitude, p[1].longitude, p[2].longitude, p[3].longitude);
            }


            GdalDatasetProjection *GdalDatasetProjection::getInstance(GDALDataset *dataset)
            {
                static bool initialized = GdalLibrary::init(nullptr);
#if 1
                if (shouldUseNitfHighPrecisionCoordinates(dataset)) {

                    char *wkt4326;
                    if (GdalLibrary::EPSG_4326->exportToWkt(&wkt4326) != OGRERR_NONE)
                        return nullptr;
                    std::unique_ptr<char, void(*)(void*)> wktCleaner(wkt4326, CPLFree);

                    std::unique_ptr<ICHIPB> ichipb;
                    const char *ichipbtre = dataset->GetMetadataItem("ICHIPB", "TRE");
                    if (ichipbtre != nullptr) {
                        util::MemoryInput input;
                        input.open((const uint8_t *)ichipbtre, strlen(ichipbtre));
                        try {
                            ichipb.reset(new ICHIPB(&input));
                        } catch (...) {
                        }
                        input.close();
                    }

                    GroundControlPoints *gcp = nullptr;

                    const char *cscrna = dataset->GetMetadataItem("CSCRNA", "TRE");
                    if (cscrna != nullptr) {
                        try {
                            gcp = new GroundControlPoints(dataset,
                                                           getCscrnaGCPs(dataset,
                                                                dataset->GetMetadataItem(
                                                                    "CSCRNA", "TRE")),
                                                           wkt4326,
                                                           ichipb.get());
                        } catch (...) {
                            //Log.w(TAG, "Failed to create GroundControlPoints for CSCRNA", e);
                        }
                    }

                    if (!gcp) {
                        char **rpcsl = dataset->GetMetadata("RPC");
                        if (rpcsl != nullptr) {
                            int c = CSLCount(rpcsl);
                            if (c > 0) {
                                try {
                                    gcp = new GroundControlPoints(dataset,
                                                                  getRpcGCPs(dataset),
                                                                  wkt4326,
                                                                  ichipb.get());
                                } catch (...) {
                                    //Log.w(TAG, "Failed to create GroundControlPoints for RPC", e);
                                }
                            }
                        }
                    }
                    if (gcp)
                        return gcp;
                }
#endif
                double geoTrans[6];
                dataset->GetGeoTransform(geoTrans);
                if (isUsableProjection(dataset->GetProjectionRef())
                    && isUsableGeoTransform(geoTrans)) {
                    return new GeoTransform(dataset);
#if 1
                } else if (dataset->GetGCPCount() >= 4) {
                    try {
                        std::vector<GCPHolder> gcps;
                        int ngcps = dataset->GetGCPCount();
                        const GDAL_GCP *ggcps = dataset->GetGCPs();
                        for (int i = 0; i < ngcps; ++i)
                            gcps.push_back(GCPHolder(ggcps[i]));

                        return new GroundControlPoints(dataset, gcps, dataset->GetGCPProjection(), nullptr);
                    } catch (math::NonInvertibleTransformException &) {
                        //Log.w(TAG, "Failed to create GroundControlPoints for Ground Control Points", e);
                        return nullptr;
                    }
#endif
                } else {
                    return nullptr;
                }

            }

        }
    }
}

