// Required Includes
#include "Game_GlobeReferenceActor_ENU.h"

// VH Plugin Includes
#include "VH_GlobeCoordConverter.h"
#include "Developer_Statics.h"

// Game Includes
#include "Game_GameInstance.h"
#include "Game_TileManager.h"

// ---------------------------------
// --- Inherited
// ---------------------------------

double AGame_GlobeReferenceActor_ENU::GetTerrainElevationDouble(const FGeodeticCoord2D& geoLocation) const
{
	double terrainHAE = -999999.0f;

	// World location at ellipsoid surface (0 HAE)
	FVector worldLocation = GeodeticToWorldDouble(FGeodeticCoord3D(geoLocation, 0));

	// TODO: For now, do line trace against terrain.  In the future, this should be a lookup instead! This will be better for performance, and it will auto-adjust for props/buildings/etc.
	FVector startTrace = worldLocation + FVector(0, 0, 10000000);
	FVector endTrace = worldLocation - FVector(0, 0, 10000000);

	ECollisionChannel collisionChannel = UGame_GameInstance::GetTerrainCollisionChannel();

	FCollisionResponseParams collisionResponse = FCollisionResponseParams(ECollisionResponse::ECR_Block);

	FCollisionQueryParams queryParams(NAME_None, true);
	queryParams.AddIgnoredActor(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	FHitResult hit;
	if (GetWorld()->LineTraceSingleByChannel(hit, startTrace, endTrace, collisionChannel, queryParams, collisionResponse))
	{
		terrainHAE = (hit.Location.Z - worldLocation.Z) / UnrealUnitsPerMeter;
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

FVector AGame_GlobeReferenceActor_ENU::GeodeticToWorldDouble(const FGeodeticCoord3D& geoLocation) const
{
	FGeodeticCoord3D geoLoc = geoLocation;
	if (FMath::IsNearlyEqual(geoLoc.Altitude, 9999999.0))
	{
		geoLoc.Altitude = 0;
		geoLoc.bIsAltitudeRelativeToGround = true;
	}

	// East-North-Up coordinates of passed in geodetic position in a Local Tangent Plan that is centered at this marker's geodetic position
	UVH_GlobeCoordConverter* globeConverter = GetGlobeCoordConverter();
	FGlobeTangentCoord enu = globeConverter->GeodeticToENU(geoLoc, GeoLocation);

	// East-North-Up to world-space, assume this marker is rotated such that x axis points north, y axis points east, z axis points up
	FVector enuPosition = FVector(enu.Northing, enu.Easting, enu.Height);

	// Convert to unreal units (scale3D taken into account in transform below)
	enuPosition *= 100.f;

	// TODO: Consider using DoubleMatrix instead of UE4's FTransform::TransformPosition(), for better precision.
	FTransform localToWorld = RootComponent->GetComponentTransform();
	FVector worldLocation = localToWorld.TransformPosition(enuPosition);

	// adjust for AGL
	if (geoLoc.bIsAltitudeRelativeToGround)
	{
		float terrainHAE = GetTerrainElevationDouble(geoLoc.ToGeodeticCoord2D());
		worldLocation.Z += (terrainHAE > -999990.0f) ? (terrainHAE * UnrealUnitsPerMeter) : 0;
	}

	return worldLocation;
}

FVector AGame_GlobeReferenceActor_ENU::GeodeticToECEF(const FGeodeticCoord3D& geoLocation) const
{
	UVH_GlobeCoordConverter* globeConverter = GetGlobeCoordConverter();
	FGlobeTangentCoord enu = globeConverter->GeodeticToENU(geoLocation, GeoLocation);

	// East-North-Up to world-space, assume this marker is rotated such that x axis points north, y axis points east, z axis points up
	FVector enuPosition = FVector(enu.Northing, enu.Easting, enu.Height);

	// Convert to unreal units (scale3D taken into account in transform below)
	enuPosition *= 100.f;

	// TODO: Consider using DoubleMatrix instead of UE4's FTransform::TransformPosition(), for better precision.
	FTransform localToWorld = RootComponent->GetComponentTransform();
	FVector worldLocation = localToWorld.TransformPosition(enuPosition);

	// Adjust for AGL
	if (geoLocation.bIsAltitudeRelativeToGround)
	{
		float terrainHAE = GetTerrainElevationDouble(geoLocation.ToGeodeticCoord2D());
		worldLocation.Z += (terrainHAE > -999990.0f) ? (terrainHAE * UnrealUnitsPerMeter) : 0;
	}

	return worldLocation;
}
