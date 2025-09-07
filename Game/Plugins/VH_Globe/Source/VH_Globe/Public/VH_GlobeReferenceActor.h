#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// Module Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "VH_GlobeReferenceActor.generated.h"

class UVH_GlobeCoordConverter;

UCLASS(BlueprintType, Abstract)
class VH_GLOBE_API AVH_GlobeReferenceActor : public AActor
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

protected:
	double UnrealUnitsPerMeter;

private:
	UPROPERTY()
	UVH_GlobeCoordConverter* GlobeCoordConverter;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
    AVH_GlobeReferenceActor();


	// ---------------------------------
    // --- Inherited
    // ---------------------------------

public:
    virtual void BeginPlay() override;

	virtual void SetActorScale3D(FVector newScale3D) override;
	

	// ---------------------------------
    // --- API
    // ---------------------------------

public:
    /* returns world rotation given bearing in degrees off of north; north is 0, east is 90, etc */
    UFUNCTION(BlueprintPure)
    virtual FRotator BearingToWorldRotation(double bearing) const PURE_VIRTUAL(AVH_GlobeReferenceActor, return FRotator(););

	virtual FRotator BearingPitchToWorldRotation(double bearing, double pitch) const PURE_VIRTUAL(AVH_GlobeReferenceActor, return FRotator(););

    /* returns bearing in degrees with 0 as north, 90 as east, etc */
    UFUNCTION(BlueprintPure)
    virtual double WorldRotationToBearing(const FRotator& worldRotation) const PURE_VIRTUAL(AVH_GlobeReferenceActor, return 0;);

	UFUNCTION(BlueprintPure)
	virtual double WorldRotationToPitch(const FRotator& worldRotation) const PURE_VIRTUAL(AVH_GlobeReferenceActor, return 0;);

	/* returns terrain elevation HAE (height above ellipsoid, in meters) at the given geodetic coordinates */
	UFUNCTION(BlueprintPure)
	virtual double GetTerrainElevationDouble(const FGeodeticCoord2D& geoLocation) const PURE_VIRTUAL(AVH_GlobeReferenceActor, return 0;);

	UFUNCTION(BlueprintPure)
	virtual FGeodeticCoord3D WorldToGeodeticDouble(const FVector& worldLocation) const PURE_VIRTUAL(AVH_GlobeReferenceActor, return FGeodeticCoord3D(););

	UFUNCTION(BlueprintPure)
	virtual FVector GeodeticToECEF(const FGeodeticCoord3D & geoLocation) const PURE_VIRTUAL(AVH_GlobeReferenceActor, return FVector(););

	UFUNCTION(BlueprintPure)
	virtual FGeodeticCoord3D ECEFToGeodetic(const FVector& ecef) const PURE_VIRTUAL(AVH_GlobeReferenceActor, return FGeodeticCoord3D(););

	UFUNCTION(BlueprintPure)
	UVH_GlobeCoordConverter* GetGlobeCoordConverter() const;

	UFUNCTION(BlueprintPure)
	virtual FVector GeodeticToWorldDouble(const FGeodeticCoord3D& geoLocation) const PURE_VIRTUAL(AVH_GlobeReferenceActor, return FVector(););

    UFUNCTION(BlueprintPure)
    FString WorldToMGRS(const FVector& worldLocation) const;

    UFUNCTION(BlueprintPure)
    FVector MGRSToWorld(const FString& mgrs) const;

	UFUNCTION(BlueprintCallable)
	bool IsValidMGRS(const FString& mgrs, bool& isValidZone, bool& isValid100kmSquareID, bool& isValidEasting, bool& isValidNorthing) const;
};
