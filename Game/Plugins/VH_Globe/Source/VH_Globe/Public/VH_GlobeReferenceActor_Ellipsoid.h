#pragma once

// Parent Includes
#include "VH_GlobeReferenceActor.h"

// Module Includes
#include "VH_GeodeticCoord.h"
#include "VH_GlobeTangentCoord.h"

// Generated Includes
#include "VH_GlobeReferenceActor_Ellipsoid.generated.h"

UCLASS(BlueprintType)
class VH_GLOBE_API AVH_GlobeReferenceActor_Ellipsoid : public AVH_GlobeReferenceActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AVH_GlobeReferenceActor_Ellipsoid();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual FRotator BearingToWorldRotation(double bearing) const override;

	virtual FRotator BearingPitchToWorldRotation(double bearing, double pitch) const;

	virtual double WorldRotationToBearing(const FRotator& worldRotation) const override;

	virtual double WorldRotationToPitch(const FRotator& worldRotation) const;

	virtual FGeodeticCoord3D WorldToGeodeticDouble(const FVector& worldLocation) const override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	FTransform GetSurfaceTransform() const;

	FTransform GetSurfaceTransform(const FGeodeticCoord2D& coordinate) const;

	FTransform GetSurfaceTransform(const FVector& worldLocation) const;
};
