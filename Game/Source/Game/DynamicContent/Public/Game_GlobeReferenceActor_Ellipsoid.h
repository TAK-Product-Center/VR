#pragma once

// Parent Includes
#include "VH_GlobeReferenceActor_Ellipsoid.h"

// Generated Includes
#include "Game_GlobeReferenceActor_Ellipsoid.generated.h"

UCLASS(BlueprintType)
class GAME_API AGame_GlobeReferenceActor_Ellipsoid : public AVH_GlobeReferenceActor_Ellipsoid
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