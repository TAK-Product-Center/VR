#pragma once

#include "VH_GlobeMath.h"
#include "VH_GeodeticCoord.h"
#include "VH_UtmCoord.h"
#include "VH_UpsCoord.h"
#include "VH_MgrsCoord.h"
#include "VH_GlobeTangentCoord.h"

#include "VH_GlobeCoordConverter.generated.h"

USTRUCT(BlueprintType)
struct FSGlobeDefinition
{
	GENERATED_BODY();

public:
	// Globe semi-major axis (m), from center to equator
	double SemiMajorAxis;

	// Globe semi-minor axis (m), from center to pole
	double SemiMinorAxis;

	// Ellipsoid Flatness
	double EllipsoidFlatness;

	// Inverse flattening
	double EllipsoidFlatnessInverse;

	// Square of Eccentricity
	double EllipsoidEccentricitySquared;

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	FSGlobeDefinition(double inSemiMajorAxis, double inSemiMinorAxis) :
		SemiMajorAxis(inSemiMajorAxis),
		SemiMinorAxis(inSemiMinorAxis),
		EllipsoidFlatness(SemiMajorAxis == 0.0 ? 1.0 : ((SemiMajorAxis - SemiMinorAxis) / SemiMajorAxis)),
		EllipsoidFlatnessInverse(EllipsoidFlatness == 0.0 ? 1.0 : 1.0 / EllipsoidFlatness),
		EllipsoidEccentricitySquared(EllipsoidFlatness * (2.0 - EllipsoidFlatness))
	{}

	// Defaults to WGS-84 Earth, values in meters
	FSGlobeDefinition() :
		FSGlobeDefinition(6378137.0, 6356752.314245)
	{}

};

// NOTE: Built-in C++ trig functions (sin, cos, tan, atan2, etc) are used in this INSTEAD of their FMath variants, because almost all of FMath is single-precision)
UCLASS(BlueprintType, Blueprintable)
class VH_GLOBEMATH_API UVH_GlobeCoordConverter : public UObject
{
    GENERATED_BODY()

public:
	UVH_GlobeCoordConverter(const FSGlobeDefinition& globeDef);
	UVH_GlobeCoordConverter();

    // ---------------------------------
    // --- API
    // ---------------------------------
public:
	void SetGlobeDefinition(const FSGlobeDefinition& globeDef);

	UFUNCTION(BlueprintCallable, Category = "VhGlobe|Math|Conversions", meta = (DisplayName = "SetGlobeDefinition"))
	void K2_SetGlobeDefinition(const FString& semiMajorAxis, const FString& semiMinorAxis);

	UFUNCTION(BlueprintPure, Category = "VhGlobe|Math|Conversions")
    FUtmCoord GeodeticToUTM(const FGeodeticCoord2D& geodeticCoord);

    UFUNCTION(BlueprintPure, Category = "VhGlobe|Math|Conversions")
    FGeodeticCoord2D UTMToGeodetic(const FUtmCoord& utmCoord);

	UFUNCTION(BlueprintPure, Category = "VhGlobe|Math|Conversions")
	FUpsCoord GeodeticToUPS(const FGeodeticCoord2D& geodeticCoord);

	UFUNCTION(BlueprintPure, Category = "VhGlobe|Math|Conversions")
	FGeodeticCoord2D UPSToGeodetic(const FUpsCoord& upsCoord);

	UFUNCTION(BlueprintPure, Category = "VhGlobe|Math|Conversions")
	FUtmCoord MGRSToUTM(const FMgrsCoord& mgrsCoord);

    UFUNCTION(BlueprintPure, Category = "VhGlobe|Math|Conversions")
    FMgrsCoord UTMToMGRS(const FUtmCoord& utmCoord);

	UFUNCTION(BlueprintPure, Category = "VhGlobe|Math|Conversions")
	FUpsCoord MGRSToUPS(const FMgrsCoord& mgrsCoord);

	UFUNCTION(BlueprintPure, Category = "VhGlobe|Math|Conversions")
	FMgrsCoord UPSToMGRS(const FUpsCoord& upsCoord);

	UFUNCTION(BlueprintPure, Category = "VhGlobe|Math|Conversions")
	FGlobeTangentCoord GeodeticToENU(const FGeodeticCoord3D& geodeticCoord, const FGeodeticCoord3D& geodeticRef);

    UFUNCTION(BlueprintPure, Category = "VhGlobe|Math|Conversions")
    FGeodeticCoord3D ENUToGeodetic(const FGlobeTangentCoord& enu);

	FGeodeticCoord3D ECEFToGeodetic(const FVector& ecef);

	UFUNCTION(BlueprintPure, Category = "VhGlobe|Math|Conversions", meta = (DisplayName = "GeodeticToECEF"))
	FVector GeodeticToECEF(const FGeodeticCoord3D& geodeticCoord);

    FVector ENUToECEF(const FGlobeTangentCoord& enu);

    FMgrsCoord ENUToMGRS(const FGlobeTangentCoord& enu);

    UFUNCTION(BlueprintPure, Category = "VhGlobe|Math|Conversions")
    FString GeodeticToMGRS(FString longitude, FString latitude);

    UFUNCTION(BlueprintPure, Category = "VhGlobe|Math|Conversions")
    void MGRSToGeodetic(const FString& mgrs, FString& longitude, FString& latitude);

	FMgrsCoord GeodeticToMGRSDouble(const FGeodeticCoord2D& geodeticCoord);

	FGeodeticCoord2D MGRSToGeodeticDouble(const FMgrsCoord& mgrsCoord);

	// ---------------------------------
    // --- Implementation
    // ---------------------------------
protected:
	double eatanhe(double x, double es);
	double taupf(double tau, double es);
	double tauf(double taup, double es);

	// ---------------------------------
    // --- Member Variables
    // ---------------------------------
protected:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FSGlobeDefinition GlobeDefinition;

    // MGRS latitude bands. The extra 'X' on the end covers north 80-84 deg range
    static const FString zoneBands;

    // 100km grid square easting (e) column, letters repeat every 3rd zone
    static const TArray<FString> easting100kLetters;

    // 100km grid square northing (n) row, letters repeat every other zone
    static const TArray<FString> northing100kLetters;

	// Center point "false northing" at N/S poles
	static const double poleFalseNorthing;

	// Center point "false easting" at N/S poles
	static const double poleFalseEasting;

	// 100km grid square easting (e) column at N/S poles
	static const FString poleEasting100kLetters;

	// 100km grid square northing (n) row at N/S poles
	static const FString poleNorthing100kLetters;
};
