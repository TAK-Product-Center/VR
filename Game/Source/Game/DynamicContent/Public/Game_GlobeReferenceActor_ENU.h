#pragma once

// Parent Includes
#include "VH_GlobeReferenceActor_ENU.h"

// Generated Includes
#include "Game_GlobeReferenceActor_ENU.generated.h"

UCLASS(BlueprintType)
class GAME_API AGame_GlobeReferenceActor_ENU : public AVH_GlobeReferenceActor_ENU
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual double GetTerrainElevationDouble(const FGeodeticCoord2D& geoLocation) const override;

	virtual FVector GeodeticToWorldDouble(const FGeodeticCoord3D& geoLocation) const override;

	virtual FVector GeodeticToECEF(const FGeodeticCoord3D& geoLocation) const override;
};