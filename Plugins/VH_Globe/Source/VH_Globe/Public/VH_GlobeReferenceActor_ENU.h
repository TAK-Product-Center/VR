#pragma once

// Parent Includes
#include "VH_GlobeReferenceActor.h"

// Module Includes
#include "VH_GeodeticCoord.h"
#include "VH_GlobeTangentCoord.h"

//  Generated Includes
#include "VH_GlobeReferenceActor_ENU.generated.h"

class UVH_GlobeCoordConverter;

UCLASS(BlueprintType)
class VH_GLOBE_API AVH_GlobeReferenceActor_ENU : public AVH_GlobeReferenceActor
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FGeodeticCoord3D GeoLocation;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AVH_GlobeReferenceActor_ENU();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	/* returns world rotation given bearing in degrees off of north; north is 0, east is 90, etc */
	virtual FRotator BearingToWorldRotation(double bearing) const override;

	virtual FRotator BearingPitchToWorldRotation(double bearing, double pitch) const;

	/* returns bearing in degrees with 0 as north, 90 as east, etc */
	virtual double WorldRotationToBearing(const FRotator& worldRotation) const override;

	virtual double WorldRotationToPitch(const FRotator& worldRotation) const;

	virtual FGeodeticCoord3D WorldToGeodeticDouble(const FVector& worldLocation) const override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION()
	FGeodeticCoord3D GetLocation() const;

	// TODO: Switch to string-based BP version, then create double-precision native version!
	UFUNCTION(BlueprintCallable)
	void SetGeodeticLocation(const FGeodeticCoord3D& coordinate);

	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	FGlobeTangentCoord WorldToGlobeTangent(const FVector& worldLocation) const;
};