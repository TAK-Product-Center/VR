// Required Includes
#include "Game_GlobeReferenceActor_Ellipsoid.h"

// Engine Includes
#include "Trace/Trace.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

// VH Plugin Includes
#include "VH_GlobeCoordConverter.h"
#include "Developer_Statics.h"

// Game Includes
#include "Game_GameInstance.h"
#include "Game_TileManager.h"
#include "Game_TerrainTile.h"

// ---------------------------------
// --- Inherited
// ---------------------------------

double AGame_GlobeReferenceActor_Ellipsoid::GetTerrainElevationDouble(const FGeodeticCoord2D& geoLocation) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(VR-TAK AGame_GlobeReferenceActor_Ellipsoid::GetTerrainElevationDouble);

	double terrainHAE = -999999.0f;
	if (TryGetTerrainElevationFromTerrainTile(geoLocation, terrainHAE))
	{
		return terrainHAE;
	}

	FTransform surfaceTransform = GetSurfaceTransform(geoLocation);

	FVector worldLocation = surfaceTransform.GetLocation();

	FVector startTrace = surfaceTransform.TransformPosition(FVector(0, 0, 1000000000));
	FVector endTrace = surfaceTransform.TransformPosition(FVector(0, 0, -1000000000));

	ECollisionChannel collisionChannel = UGame_GameInstance::GetTerrainCollisionChannel();

	FCollisionResponseParams collisionResponse = FCollisionResponseParams(ECollisionResponse::ECR_Block);

	FCollisionQueryParams queryParams(NAME_None, true);
	queryParams.AddIgnoredActor(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

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
	TRACE_CPUPROFILER_EVENT_SCOPE(VR-TAK AGame_GlobeReferenceActor_Ellipsoid::GeodeticToWorldDouble);

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

FGeodeticCoord3D AGame_GlobeReferenceActor_Ellipsoid::ECEFToGeodetic(const FVector& ecef) const
{
	FVector ecefModified = ecef;
	ecefModified.X = -ecefModified.X;
	
	ecefModified /= UnrealUnitsPerMeter;

	UVH_GlobeCoordConverter* globeConverter = GetGlobeCoordConverter();
	return globeConverter->ECEFToGeodetic(ecefModified);
}

bool AGame_GlobeReferenceActor_Ellipsoid::TryGetTerrainElevationFromTerrainTile(const FGeodeticCoord2D& geoLocation, double& outElevation) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(VR-TAK AGame_GlobeReferenceActor_Ellipsoid::TryGetTerrainElevationFromTerrainTile);

	AGame_TerrainTile* pTile = GetTileAtCoord(geoLocation);
	if (IsValid(pTile))
	{
		const FTransform surfaceTransform = GetSurfaceTransform(geoLocation);

		const FVector start = surfaceTransform.TransformPosition(FVector(0, 0, 200000));
		const FVector down = surfaceTransform.TransformVector(FVector(0, 0, -1));

		FVector closestPt;
		if (pTile->RayTrace(start, down, closestPt))
		{
			FVector hitLocal = surfaceTransform.InverseTransformPosition(closestPt);

			outElevation = hitLocal.Z / UnrealUnitsPerMeter;
			return true;
		}
	}
	return false;
}

AGame_TerrainTile* AGame_GlobeReferenceActor_Ellipsoid::GetTileAtCoord(const FGeodeticCoord2D& geoLocation) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(VR-TAK AGame_GlobeReferenceActor_Ellipsoid::GetTileAtCoord);

	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		AGame_TerrainTile* pTile = tileManager->GetTile(ETileID::Inner);
		if (IsValid(pTile) && pTile->IsCoordInBounds(geoLocation) && pTile->IsWorldPartioningReady())
		{
			return pTile;
		}

		pTile = tileManager->GetTile(ETileID::Outer);
		if (IsValid(pTile) && pTile->IsCoordInBounds(geoLocation) && pTile->IsWorldPartioningReady())
		{
			return pTile;
		}

		pTile = tileManager->GetTile(ETileID::Ellipsoid);
		if (IsValid(pTile) && pTile->IsWorldPartioningReady())
		{
			return pTile;
		}
	}
	return nullptr;
}
