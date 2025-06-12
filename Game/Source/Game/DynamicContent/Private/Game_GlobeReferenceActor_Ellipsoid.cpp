// Required Includes
#include "Game_GlobeReferenceActor_Ellipsoid.h"

// VH Plugin Includes
#include "VH_GlobeCoordConverter.h"
#include "Developer_Statics.h"

// Game Includes
#include "Game_GameInstance.h"
#include "Game_TileManager.h"

// ---------------------------------
// --- Inherited
// ---------------------------------

double AGame_GlobeReferenceActor_Ellipsoid::GetTerrainElevationDouble(const FGeodeticCoord2D& geoLocation) const
{
	FTransform surfaceTransform = GetSurfaceTransform(geoLocation);

	FVector worldLocation = surfaceTransform.GetLocation();

	FVector startTrace = surfaceTransform.TransformPosition(FVector(0, 0, 1000000000));
	FVector endTrace = surfaceTransform.TransformPosition(FVector(0, 0, -1000000000));

	ECollisionChannel collisionChannel = UGame_GameInstance::GetTerrainCollisionChannel();

	FCollisionResponseParams collisionResponse = FCollisionResponseParams(ECollisionResponse::ECR_Block);

	FCollisionQueryParams queryParams(NAME_None, true);
	queryParams.AddIgnoredActor(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	double terrainHAE = -999999.0f;
	FHitResult hit;
	if (GetWorld()->LineTraceSingleByChannel(hit, startTrace, endTrace, collisionChannel, queryParams, collisionResponse))
	{
		FVector hitLocal = surfaceTransform.InverseTransformPosition(hit.Location);

		terrainHAE = hitLocal.Z / UnrealUnitsPerMeter;
	}
	else
	{
		// fall back to DTED
		if (UGame_TileManager* tileManager = UGame_TileManager::Get())
		{
			tileManager->GetHAEFromDTED(geoLocation, terrainHAE);
		}
	}
	
	return terrainHAE;
}

FVector AGame_GlobeReferenceActor_Ellipsoid::GeodeticToWorldDouble(const FGeodeticCoord3D& geoLocation) const
{
	FGeodeticCoord3D coordinate = geoLocation;
	if (FMath::IsNearlyEqual(coordinate.Altitude, 9999999.0))
	{
		coordinate.Altitude = 0;
		coordinate.bIsAltitudeRelativeToGround = true;
	}

	if (coordinate.bIsAltitudeRelativeToGround)
	{
		double terrainHAE = GetTerrainElevationDouble(geoLocation.ToGeodeticCoord2D());
		if (terrainHAE == -999999)
		{
			// use dted to get approximate ground height
			if (UGame_TileManager* tileManager = UGame_TileManager::Get())
			{
				if (!tileManager->GetHAEFromDTED(coordinate.ToGeodeticCoord2D(), terrainHAE))
				{
					terrainHAE = 0;
				}
			}
		}

		coordinate.Altitude += terrainHAE;

		coordinate.bIsAltitudeRelativeToGround = false;
	}

	return GeodeticToECEF(coordinate);
}

FVector AGame_GlobeReferenceActor_Ellipsoid::GeodeticToECEF(const FGeodeticCoord3D& geoLocation) const
{
	UVH_GlobeCoordConverter* globeConverter = GetGlobeCoordConverter();
	FVector ecef = globeConverter->GeodeticToECEF(geoLocation);

	ecef.X = -ecef.X;
	return ecef * UnrealUnitsPerMeter;
}
