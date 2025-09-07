// Required Includes
#include "Game_3DTileNode.h"
#include "Game.h"

// Engine Includes
#include "Dom/JsonObject.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "VH_GlobeCoordConverter.h"
#include "VH_GlobeMathStatics.h"
#include "VH_COTManager.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_3DTileNode::UGame_3DTileNode()
{
	TransformMatrix.SetIdentity();
}

TStatId UGame_3DTileNode::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UGame_3DTileNode, STATGROUP_Tickables);
}

bool UGame_3DTileNode::IsTickable() const
{
	return false;
}

void UGame_3DTileNode::Tick(float deltaSeconds)
{
	// leaving for debug later
	// use UDeveloper_Statics::GetVHWorld() for draw debug calls
}

// ---------------------------------
// --- API
// ---------------------------------

FMatrix UGame_3DTileNode::GetTransformMatrix() const
{
	if (IsValid(Parent))
	{
		return Parent->GetTransformMatrix() * TransformMatrix;
	}

	return TransformMatrix;
}

void UGame_3DTileNode::TransformECEF()
{
	FMatrix cumulativeTransformMatrix = GetTransformMatrix();

	auto applyTransform = [cumulativeTransformMatrix](const FVector& toTransform)
	{
		FMatrix vectorMatrix;
		vectorMatrix.SetIdentity();
		vectorMatrix.M[0][0] = toTransform.X;
		vectorMatrix.M[1][0] = toTransform.Y;
		vectorMatrix.M[2][0] = toTransform.Z;
		vectorMatrix.M[3][0] = 1;

		FMatrix result = cumulativeTransformMatrix * vectorMatrix;

		FVector transformed;
		transformed.X = result.M[0][0];
		transformed.Y = result.M[1][0];
		transformed.Z = result.M[2][0];

		return transformed;
	};

	if (!cumulativeTransformMatrix.Equals(FMatrix::Identity))
	{
		// transform to actual ECEF (Z up)
		FVector centerRaw = ECEFCenter;

		ECEFCenter = applyTransform(ECEFCenter);

		ECEFX = applyTransform(centerRaw + ECEFX) - ECEFCenter;
		ECEFY = applyTransform(centerRaw + ECEFY) - ECEFCenter;
		ECEFZ = applyTransform(centerRaw + ECEFZ) - ECEFCenter;
	}
}

// todo ohg | work-in-progress; finish
void UGame_3DTileNode::GetImplictTilesToLoad(const FGeodeticCoord2D& northWestBound, const FGeodeticCoord2D& southEastBound, AVH_GlobeReferenceActor* globeReference, double desiredGeometricError, int32& level, TArray<TPair<int32, int32>>& tileXYs)
{
	if (!BoundingVolumeType.Equals(TEXT("region"), ESearchCase::IgnoreCase))
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_3DTileNode::GetImplictTilesToLoad | BoudingVolumeType is not region: %s | aborting"), *BoundingVolumeType);

		return;
	}
	
	if (!IntersectsRectangle(northWestBound, southEastBound, globeReference, 5000))
	{
		return;
	}

	// assume this node's GeometricError is for level 0
	level = 0;
	double geometricError = GeometricError;

	while (geometricError > desiredGeometricError)
	{
		level++;

		geometricError /= 2.f;
	}

	double tilesPerRowColumn = FMath::Pow(2.f, level);

	double longitudePerTile = (NorthEastHigh.Longitude - SouthWestLow.Longitude) / tilesPerRowColumn;
	double latitudePerTile = (NorthEastHigh.Latitude - SouthWestLow.Latitude) / tilesPerRowColumn;

	//UE_LOG(LogTemp, Warning, TEXT("-- longitudePer: %f | latitudePer: %f | southwest: %s | northeast: %s"), longitudePerTile, latitudePerTile, *SouthWestLow.ToString(), *NorthEastHigh.ToString());

	int32 startingX = 0;
	double startingLongitude = SouthWestLow.Longitude;
	if (SouthWestLow.Longitude < northWestBound.Longitude)
	{
		startingX = FMath::FloorToInt32(FMath::Abs(SouthWestLow.Longitude - northWestBound.Longitude) / longitudePerTile);

		startingLongitude += (longitudePerTile * startingX);
	}

	int32 y = 0;
	double startingLatitude = SouthWestLow.Latitude;
	if (SouthWestLow.Latitude < southEastBound.Latitude)
	{
		y = FMath::FloorToInt32(FMath::Abs(SouthWestLow.Latitude - southEastBound.Latitude) / latitudePerTile);

		startingLatitude += (latitudePerTile * y);
	}

	//UE_LOG(LogTemp, Warning, TEXT("-- startingX: %d | y: %d | startingLongitude: %f | startingLatitude: %f"), startingX, y, startingLongitude, startingLatitude)

	for (double latitude = startingLatitude; latitude <= northWestBound.Latitude; latitude += latitudePerTile)
	{
		int32 x = startingX;
		for (double longitude = startingLongitude; longitude <= southEastBound.Longitude; longitude += longitudePerTile)
		{
			if (latitude >= southEastBound.Latitude && latitude <= northWestBound.Latitude &&
				longitude >= northWestBound.Longitude && longitude <= southEastBound.Longitude)
			{
				tileXYs.Add(TPair<int32, int32>(x, y));
			}

			x++;
		}
		y++;
	}
}

bool UGame_3DTileNode::IntersectsRectangle(const FGeodeticCoord2D& northWestBound, const FGeodeticCoord2D& southEastBound, AVH_GlobeReferenceActor* globeReference, double viewDistanceMeters) const
{
	if (BoundingVolumeType.Equals(TEXT("region"), ESearchCase::IgnoreCase))
	{
		FBox2D nodeBox(FVector2D(SouthWestLow.Longitude, SouthWestLow.Latitude), FVector2D(NorthEastHigh.Longitude, NorthEastHigh.Latitude));
		FBox2D tileBox(FVector2D(northWestBound.Longitude, southEastBound.Latitude), FVector2D(southEastBound.Longitude, northWestBound.Latitude));

		return nodeBox.Intersect(tileBox);
	}
	else if (BoundingVolumeType.Equals(TEXT("sphere"), ESearchCase::IgnoreCase))
	{
		FGeodeticCoord3D tileCenter = FGeodeticCoord3D(southEastBound.Longitude + ((northWestBound.Longitude - southEastBound.Longitude) / 2), northWestBound.Latitude + ((southEastBound.Latitude - northWestBound.Latitude) / 2), 0);
		FVector tileCenterECEF = globeReference->GetGlobeCoordConverter()->GeodeticToECEF(tileCenter);

		double longitudeDistanceMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(southEastBound, FGeodeticCoord2D(northWestBound.Longitude, southEastBound.Latitude));
		double latitudeDistanceMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(northWestBound, FGeodeticCoord2D(northWestBound.Longitude, southEastBound.Latitude));

		FSphere3d nodeSphere(ECEFCenter, RadiusMeters);
		FSphere3d tileSphere(tileCenterECEF, FMath::Max<double>(longitudeDistanceMeters, latitudeDistanceMeters));

		return nodeSphere.Intersects(tileSphere);
	}
	else if (BoundingVolumeType.Equals(TEXT("box"), ESearchCase::IgnoreCase))
	{
		auto updateMinMax3D = [](FVector& min, FVector& max, const FVector& ecef)
		{
			min.X = FMath::Min<double>(min.X, ecef.X);
			min.Y = FMath::Min<double>(min.Y, ecef.Y);
			min.Z = FMath::Min<double>(min.Z, ecef.Z);

			max.X = FMath::Max<double>(max.X, ecef.X);
			max.Y = FMath::Max<double>(max.Y, ecef.Y);
			max.Z = FMath::Max<double>(max.Z, ecef.Z);
		};

		UVH_GlobeCoordConverter* converter = globeReference->GetGlobeCoordConverter();

		// node box
		FVector min3D = ECEFCenter + ECEFX + ECEFY + ECEFZ;
		FVector max3D = ECEFCenter + ECEFX + ECEFY + ECEFZ;

		updateMinMax3D(min3D, max3D, ECEFCenter + ECEFX + ECEFY - ECEFZ);
		updateMinMax3D(min3D, max3D, ECEFCenter + ECEFX - ECEFY + ECEFZ);
		updateMinMax3D(min3D, max3D, ECEFCenter + ECEFX - ECEFY - ECEFZ);
		updateMinMax3D(min3D, max3D, ECEFCenter - ECEFX + ECEFY + ECEFZ);
		updateMinMax3D(min3D, max3D, ECEFCenter - ECEFX + ECEFY - ECEFZ);
		updateMinMax3D(min3D, max3D, ECEFCenter - ECEFX - ECEFY + ECEFZ);
		updateMinMax3D(min3D, max3D, ECEFCenter - ECEFX - ECEFY - ECEFZ);
		
		FBox nodeBox3D(min3D, max3D);
		
		// tile box
		FGeodeticCoord3D playerGeoLocation;
		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			playerGeoLocation = cotManager->GetGeodeticLocation();
		}

		min3D = converter->GeodeticToECEF(FGeodeticCoord3D(northWestBound, playerGeoLocation.Altitude - viewDistanceMeters));
		max3D = min3D;

		updateMinMax3D(min3D, max3D, converter->GeodeticToECEF(FGeodeticCoord3D(northWestBound, playerGeoLocation.Altitude + viewDistanceMeters)));
		updateMinMax3D(min3D, max3D, converter->GeodeticToECEF(FGeodeticCoord3D(southEastBound, playerGeoLocation.Altitude - viewDistanceMeters)));
		updateMinMax3D(min3D, max3D, converter->GeodeticToECEF(FGeodeticCoord3D(southEastBound, playerGeoLocation.Altitude + viewDistanceMeters)));

		FBox tileBox3D(min3D, max3D);

		// check for intersection between tile box and node box
		return tileBox3D.Intersect(nodeBox3D) || nodeBox3D.Intersect(tileBox3D) || nodeBox3D.IsInside(tileBox3D) || tileBox3D.IsInside(nodeBox3D);
	}
	else if (BoundingVolumeType.Equals(TEXT("extensions"), ESearchCase::IgnoreCase))
	{
		if (IsValid(Parent))
		{
			return Parent->IntersectsRectangle(northWestBound, southEastBound, globeReference, viewDistanceMeters);
		}

		UE_LOG(Game, Warning, TEXT("-- UGame_3DTileNode::Intersects | boundingVolumeType is extensions but Parent is invalid | returning false"));
		return false;
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_3DTileNode::Intersects | unknown BoundingVolumeType: %s | returning false"), *BoundingVolumeType);
	return false;
}

double UGame_3DTileNode::GetDistanceMeters(const FGeodeticCoord3D& playerCoordinate, AVH_GlobeReferenceActor* globeReference) const
{
	if (BoundingVolumeType.Equals(TEXT("region"), ESearchCase::IgnoreCase))
	{
		FBox2D nodeBox(FVector2D(SouthWestLow.Longitude, SouthWestLow.Latitude), FVector2D(NorthEastHigh.Longitude, NorthEastHigh.Latitude));
		FVector2D closest = nodeBox.GetClosestPointTo(FVector2D(playerCoordinate.Longitude, playerCoordinate.Latitude));

		return UVH_GlobeMathStatics::CalculateSurfaceDistance(playerCoordinate.ToGeodeticCoord2D(), FGeodeticCoord2D(closest.X, closest.Y));
	}
	else if (BoundingVolumeType.Equals(TEXT("sphere"), ESearchCase::IgnoreCase))
	{
		FVector playerECEF = globeReference->GetGlobeCoordConverter()->GeodeticToECEF(playerCoordinate);

		return FMath::Max<double>(FVector::Distance(playerECEF, ECEFCenter) - RadiusMeters, 0);
	}
	else if (BoundingVolumeType.Equals(TEXT("box"), ESearchCase::IgnoreCase))
	{
		auto updateMinMax3D = [](FVector& min, FVector& max, const FVector& ecef)
		{
			min.X = FMath::Min<double>(min.X, ecef.X);
			min.Y = FMath::Min<double>(min.Y, ecef.Y);
			min.Z = FMath::Min<double>(min.Z, ecef.Z);

			max.X = FMath::Max<double>(max.X, ecef.X);
			max.Y = FMath::Max<double>(max.Y, ecef.Y);
			max.Z = FMath::Max<double>(max.Z, ecef.Z);
		};

		// node box
		FVector min3D = ECEFCenter + ECEFX + ECEFY + ECEFZ;
		FVector max3D = ECEFCenter + ECEFX + ECEFY + ECEFZ;

		updateMinMax3D(min3D, max3D, ECEFCenter + ECEFX + ECEFY - ECEFZ);
		updateMinMax3D(min3D, max3D, ECEFCenter + ECEFX - ECEFY + ECEFZ);
		updateMinMax3D(min3D, max3D, ECEFCenter + ECEFX - ECEFY - ECEFZ);
		updateMinMax3D(min3D, max3D, ECEFCenter - ECEFX + ECEFY + ECEFZ);
		updateMinMax3D(min3D, max3D, ECEFCenter - ECEFX + ECEFY - ECEFZ);
		updateMinMax3D(min3D, max3D, ECEFCenter - ECEFX - ECEFY + ECEFZ);
		updateMinMax3D(min3D, max3D, ECEFCenter - ECEFX - ECEFY - ECEFZ);

		FBox nodeBox3D(min3D, max3D);

		FVector playerECEFWorld = globeReference->GetGlobeCoordConverter()->GeodeticToECEF(playerCoordinate);

		if (nodeBox3D.IsInsideOrOn(playerECEFWorld))
		{
			return 0;
		}
		
		return FVector::Distance(playerECEFWorld, nodeBox3D.GetClosestPointTo(playerECEFWorld));
	}
	else if (BoundingVolumeType.Equals(TEXT("extensions"), ESearchCase::IgnoreCase))
	{
		return -1;
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_3DTileNode::GetDistanceMeters | unknown BoundingVolumeType: %s | returning -1"), *BoundingVolumeType);
	return -1;
}