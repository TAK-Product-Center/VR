#pragma once

// Module
#include "VH_GlobeMath.h"
#include "VH_GeodeticCoord.h"
#include "WorldMagneticModel/GeomagnetismHeader.h"

// Generated
#include "VH_GlobeMathStatics.generated.h"

// TODO: Consider changing parent class to UBlueprintFunctionLibrary -- is there any added benefit?


/**
 * 
 */
UCLASS()
class VH_GLOBEMATH_API UVH_GlobeMathStatics : public UObject
{
    GENERATED_BODY()

    // ---------------------------------
	// --- Constants
	// ---------------------------------
public:
	// Derived Earth semi-minor axis (m)
	static const double EARTH_MINOR_RADIUS;

	// WGS-84 Earth semi-major axis (m)
	static const double EARTH_MAJOR_RADIUS;

	static const double EARTH_MINOR_SQR_RADIUS;
	static const double EARTH_MAJOR_SQR_RADIUS;

	// Ellipsoid Flatness
	static const double EARTH_FLATTENING;

	// Inverse flattening
	//1/(1-flattening)^2
	//tan(geodetic) = tan(geocentric)/(1-flattening)^2
	static const double EARTH_INV_ONE_MINUS_FLATTENING_SQR;

	// Square of Eccentricity
	// 1 - ( minor/major )^2
	static const double FIRST_ECCENTRICITY_SQR;

	static const double EARTH_MODEL_DEGREE_OFFSET;
	static const double EARTH_MODEL_RADIAN_OFFSET;
	static const double EVEREST_HEIGHT;
	static const double EVEREST_ALPHA;

	static const double DBLE_SQRT_3;

	// ---------------------------------
    // --- API
    // ---------------------------------
public:
	static double GeoidHeight(const FGeodeticCoord2D& coordinate);

	static double MSLToHAE(const FGeodeticCoord2D& coordinate, double msl);

	static double HAEToMSL(const FGeodeticCoord2D& coordinate, double hae);

	static double MagneticToTrue(const FGeodeticCoord2D& coordinate, double magneticNorthDegrees);

	static double TrueToMagnetic(const FGeodeticCoord2D& coordinate, double trueNorthDegrees);

	// declination is degrees difference magnetic to true; true -> magnetic means subtract declination from true
	static double GetDeclination(const FGeodeticCoord2D& coordinate);

	// Calculate the distance (m) from the center to the geo-ellipsoid surface at the given latitude.
	static double CalculateEllipsoidRadius(double latitude);

	/**
	 * \brief Calculate the distance (m) for the most direct path between 2 points along the surface of a geo-ellipsoid.
	 * \param geoStart Starting geodetic position.
	 * \param geoEnd Ending/destination geodetic position.
	 * \param altitudeMeters Altitude (meters) above the surface of the geo-ellipsoid.
	 * \return Surface distance (meters) between geoStart and geoEnd at the given altitudeMeters.
	 */
	UFUNCTION(BlueprintPure, Category = "VhGlobeMath", meta = (DisplayName = "VH Calculate Surface Distance"))
	static double CalculateSurfaceDistance(const FGeodeticCoord2D& geoStart, const FGeodeticCoord2D& geoEnd, double altitudeMeters = 0.0);

	/**
	 * \brief Calculate the bearing (deg) for the most direct path between 2 points on a geo-ellipsoid.
	 * \param geoStart Starting geodetic position.
	 * \param geoEnd Ending/destination geodetic position.
	 * \return The bearing (degrees) for the most direct path between geoStart and geoEnd.
	 * \note Bearing is interpreted as: 0 = True North, with values [0..360) winding clockwise as viewed from above the surface.
	 */
	 // Calculate the bearing (deg) for the most direct path between 2 points on a geo-ellipsoid.
	UFUNCTION(BlueprintPure, Category = "VhGlobeMath", meta = (DisplayName = "VH Calculate Surface Bearing"))
	static double CalculateSurfaceBearing(const FGeodeticCoord2D& geoStart, const FGeodeticCoord2D& geoEnd);

	/**
	 * \brief Calculate the destination of movement distance (m) along the surface of a geo-ellipsoid.
	 * \param geoStart Starting geodetic position.
	 * \param bearing Direction (degrees) to travel from the starting point.
	 * \param distanceMeters Distance (meters) to travel from the starting point.
	 * \param altitudeMeters Altitude (meters) above the surface of the geo-ellipsoid.
	 * \return The destination geodetic position.
	 * \note Bearing is interpreted as: 0 = True North, with values [0..360) winding clockwise as viewed from above the surface.
	 */
	UFUNCTION(BlueprintPure, Category = "VhGlobeMath", meta = (DisplayName = "VH Calculate Surface Destination"))
	static FGeodeticCoord2D CalculateSurfaceDestination(const FGeodeticCoord2D& geoStart, double bearing, double distanceMeters, double altitudeMeters = 0.0);

	/**
	 * \brief Generate a series of interpolated points between (inclusively) two 3D geodetic locations.
	 * \param geoStart Starting geodetic position.
	 * \param geoEnd Ending/destination geodetic position.
	 * \param interpDistanceMeters Distance (meters) threshold to interpolate along the geo-ellipsoid surface. It's basically a max threshold for tessellation/segmentation across the curved surface.
	 * \param bUseConstantDist Set to TRUE to preserve interpDistanceMeters when interpolating points (i.e. each segment is exactly 'interpDistanceMeters' in length). Set to FALSE to uniformly distribute the interpolated points (i.e. each segment is the same length).
	 * \return And array of interpolated geodetic points.
	 */
	static TArray<FGeodeticCoord3D> InterpolateLocations(const FGeodeticCoord3D& geoStart, const FGeodeticCoord3D& geoEnd, double interpDistanceMeters, bool bUseConstantDist = false);

	/*
	* \brief Find intersection between two points with bearings
	* \param a first point
	* \param bearingA bearing of first point in degrees
	* \param b second point
	* \param bearingB bearing of second point in degrees
	* \param intersection coordinate of intersection
	* \return if intersection is valid
	*/
	static bool CalculateIntersection(const FGeodeticCoord2D& a, double bearingA, const FGeodeticCoord2D& b, double bearingB, FGeodeticCoord2D& intersection);

private:
	static MAGtype_Geoid* Geoid;

	static MAGtype_Ellipsoid* Ellipsoid;

	static MAGtype_MagneticModel* MagneticModel;

	static MAGtype_MagneticModel* TimedMagneticModel;

	static MAGtype_Geoid* GetGeoid();

	static void InitializeMagneticModel();
};
