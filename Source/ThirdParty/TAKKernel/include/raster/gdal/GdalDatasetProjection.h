#ifndef ATAKMAP_RASTER_GDAL_GDALDATASETPROJECTION_H_INCLUDED
#define ATAKMAP_RASTER_GDAL_GDALDATASETPROJECTION_H_INCLUDED

#include "port/Platform.h"
#include "core/Projection.h"
#include "math/Point.h"
#include "gdal_priv.h"
#include "ogr_spatialref.h"
#include "core/GeoPoint.h"

namespace atakmap {
    namespace raster {
        namespace gdal {

            class ENGINE_API GdalDatasetProjection : public core::Projection
            {
            public:
                virtual ~GdalDatasetProjection() override;

                virtual void forward(const core::GeoPoint *geo, math::Point<double> *proj) override;
                virtual void inverse(const math::Point<double> *proj, core::GeoPoint *geo) override;
                virtual double getMinLatitude() override;
                virtual double getMaxLatitude() override;
                virtual double getMinLongitude() override;
                virtual double getMaxLongitude() override;
                virtual bool is3D() override;

                int getSpatialReferenceID() override;
                int getNativeSpatialReferenceID();

                // Caller must delete returned projection.
                // Dataset assumed valid for life of the returned object.
                static GdalDatasetProjection *getInstance(GDALDataset *dataset);

                static bool isUsableGeoTransform(double geoTransform[6]);
                static bool shouldUseNitfHighPrecisionCoordinates(GDALDataset *dataset);


            protected:
                OGRSpatialReferenceH datasetSpatialReference;
                OGRCoordinateTransformationH proj2geo;
                OGRCoordinateTransformationH geo2proj;
                const int nativeSpatialReferenceID;

                double minLat;
                double minLon;
                double maxLat;
                double maxLon;

                GdalDatasetProjection(const char *projectionWkt);
                void initMinimumBoundingBox(GDALDataset *dataset);

                virtual math::PointD image2projected(const math::PointD &p) = 0;
                virtual math::PointD projected2image(const math::PointD &p) = 0;

            };
        }
    }
}

#endif
