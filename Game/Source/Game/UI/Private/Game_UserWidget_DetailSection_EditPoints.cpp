#include "Game_UserWidget_DetailSection_EditPoints.h"

#include "VH_COTEvent.h"
#include "VH_COTManager.h"
#include "VH_GeodeticCoord.h"
#include "VH_GlobeMathStatics.h"

#include "Game.h"
#include "Game_DrawContainer.h"
#include "Game_EditPoint.h"
#include "Game_COTComponent_Draw.h"
#include "Game_TileManager.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_COTManager.h"

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_UserWidget_DetailSection_EditPoints::NativeConstruct()
{
	Super::NativeConstruct();

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->OnInsertOrUpdate.AddUniqueDynamic(this, &UGame_UserWidget_DetailSection_EditPoints::HandleDatabaseInsertUpdate);
	}
}

// -------------------------------- -
// --- API
// ---------------------------------

void UGame_UserWidget_DetailSection_EditPoints::SetEntityUID(const FString& entityUID)
{
	EntityUID = entityUID;

	UpdateCOTEvent();
}

void UGame_UserWidget_DetailSection_EditPoints::UpdateCOTEvent()
{
	COTEvent = nullptr;

	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		COTEvent = cotManager->GetCotEventFromUID(EntityUID);

		PopulateEditPoints();
	}
}

void UGame_UserWidget_DetailSection_EditPoints::SetEditPointLocation(int32 index, FGeodeticCoord3D geoLocation)
{
	if (COTEvent != nullptr)
	{
		FString type = COTEvent->GetAttribute(TEXT("type"));

		if (type.Equals(TEXT("u-d-f")))
		{
			SetPolylineLocation(index, geoLocation);
		}
		else if (type.Equals(TEXT("b-m-r")))
		{
			SetRouteLocation(index, geoLocation);
		}
		else if (type.Equals(TEXT("u-rb-a")))
		{
			SetRangeBearingLocation(index, geoLocation);
		}
		else if (type.Equals("u-d-r"))
		{
			SetRectangleLocation(index, geoLocation);
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_DetailSection_EditPoints::SetEditPointLocation | unknown type | %s"), *COTEvent->GetAttribute(TEXT("type")));
		}
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_DetailSection_EditPoints::SetEntityUID | COTEvent is nullptr | entityUID: %s"), *EntityUID);
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_UserWidget_DetailSection_EditPoints::PopulateEditPoints()
{
	if (COTEvent != nullptr)
	{
		FString type = COTEvent->GetAttribute(TEXT("type"));
		
		if (type.Equals(TEXT("u-d-f")))
		{
			PopulatePolylineEditPoints();
		}
		else if (type.Equals(TEXT("b-m-r")))
		{
			PopulateRouteEditPoints();
		}
		else if (type.Equals(TEXT("u-rb-a")))
		{
			PopulateRangeBearingEditPoints();
		}
		else if (type.Equals(TEXT("u-d-r")))
		{
			PopulateRectangleEditPoints();
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_DetailSection_EditPoints::PopulateEditPoints | unknown type | %s"), *COTEvent->GetAttribute(TEXT("type")));
		}
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_DetailSection_EditPoints::SetEntityUID | COTEvent is nullptr | entityUID: %s"), *EntityUID);
	}
}

void UGame_UserWidget_DetailSection_EditPoints::PopulateRectangleEditPoints()
{
	TArray<FGeodeticCoord3D> coordinates;

	TArray<FXmlNode*> links = COTEvent->GetNodes(TEXT("link"));
	for (FXmlNode* link : links)
	{
		FGeodeticCoord3D linkCoordinate = UVH_COTStatics::LinkToCoordinate(link);

		coordinates.Add(linkCoordinate);
	}

	UpdateEditPoints(coordinates);
}

void UGame_UserWidget_DetailSection_EditPoints::PopulatePolylineEditPoints()
{
	TArray<FGeodeticCoord3D> coordinates;

	TArray<FXmlNode*> links = COTEvent->GetNodes(TEXT("link"));
	for (FXmlNode* link : links)
	{
		FGeodeticCoord3D linkCoordinate = UVH_COTStatics::LinkToCoordinate(link);

		coordinates.Add(linkCoordinate);
	}

	UpdateEditPoints(coordinates);
}

void UGame_UserWidget_DetailSection_EditPoints::PopulateRouteEditPoints()
{
	TArray<FGeodeticCoord3D> coordinates;

	TArray<FXmlNode*> links = COTEvent->GetNodes(TEXT("link"));
	for (FXmlNode* link : links)
	{
		FGeodeticCoord3D linkCoordinate = UVH_COTStatics::LinkToCoordinate(link);

		coordinates.Add(linkCoordinate);
	}

	UpdateEditPoints(coordinates);
}

void UGame_UserWidget_DetailSection_EditPoints::PopulateRangeBearingEditPoints()
{
	TArray<FGeodeticCoord3D> geoLocations;

	// base
	FGeodeticCoord3D baseCoordinate = COTEvent->GetPoint();

	geoLocations.Add(baseCoordinate);

	// arrow
	double range = COTEvent->GetAttribute<double>(TEXT("detail\trange\tvalue"));
	double bearing = COTEvent->GetAttribute<double>(TEXT("detail\tbearing\tvalue"));
	double inclination = COTEvent->GetAttribute<double>(TEXT("detail\tinclination\tvalue"));

	FGeodeticCoord2D arrowCoord2D = UVH_GlobeMathStatics::CalculateSurfaceDestination(baseCoordinate.ToGeodeticCoord2D(), bearing, range);
	FGeodeticCoord3D arrowCoord3D(arrowCoord2D);

	double baseHeight = baseCoordinate.Altitude;
	bool bSnapToGround = FMath::IsNearlyEqual(baseHeight, 9999999.0);

	if (bSnapToGround)
	{
		arrowCoord3D.Altitude = 9999999;
	}
	else
	{
		arrowCoord3D.Altitude = baseHeight + FMath::Sin(inclination) * range;
	}

	geoLocations.Add(arrowCoord3D);

	UpdateEditPoints(geoLocations);
}

void UGame_UserWidget_DetailSection_EditPoints::SetRectangleLocation(int32 index, const FGeodeticCoord3D& geoLocation)
{
	TArray<FXmlNode*> links = COTEvent->GetNodes(TEXT("link"));
	if (links.IsValidIndex(index))
	{
		links[index]->SetAttribute(TEXT("point"), UVH_COTStatics::GetLongLatHAE(geoLocation));

		UpdateEntity();
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_DetailSection_EditPoints::SetRectangleLocation | invalid index | index: %d"), index);
	}
}

void UGame_UserWidget_DetailSection_EditPoints::SetPolylineLocation(int32 index, const FGeodeticCoord3D& geoLocation)
{
	TArray<FXmlNode*> links = COTEvent->GetNodes(TEXT("link"));
	if (links.IsValidIndex(index))
	{
		links[index]->SetAttribute(TEXT("point"), UVH_COTStatics::GetLongLatHAE(geoLocation));

		UpdateEntity();
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_DetailSection_EditPoints::SetPolylineLocation | invalid index | index: %d"), index);
	}
}

void UGame_UserWidget_DetailSection_EditPoints::SetRouteLocation(int32 index, const FGeodeticCoord3D& geoLocation)
{
	TArray<FXmlNode*> links = COTEvent->GetNodes(TEXT("link"));
	if (links.IsValidIndex(index))
	{
		links[index]->SetAttribute(TEXT("point"), UVH_COTStatics::GetLongLatHAE(geoLocation));

		UpdateEntity();
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_DetailSection_EditPoints::SetRouteLocation | invalid index | index: %d"), index);
	}
}

void UGame_UserWidget_DetailSection_EditPoints::SetRangeBearingLocation(int32 index, const FGeodeticCoord3D& geoLocation)
{
	FGeodeticCoord3D baseCoordinate = COTEvent->GetPoint();

	FGeodeticCoord3D updatedCoord = geoLocation;

	// populated in if/else below, then used to calculate inclination/range/bearing and update COTEvent
	FGeodeticCoord3D baseLocation3D;
	FGeodeticCoord3D arrowLocation3D;

	if (index == 0)
	{
		// base

		// calculate arrow location from current (non-updated) base location
		FGeodeticCoord2D oldBaseLocation2D = FGeodeticCoord2D(baseCoordinate.Longitude, baseCoordinate.Latitude);
		FGeodeticCoord3D oldBaseLocation3D(oldBaseLocation2D);
		oldBaseLocation3D.Altitude = baseCoordinate.Altitude;

		double oldRange = COTEvent->GetAttribute<double>(TEXT("detail\trange\tvalue"));
		double oldBearing = COTEvent->GetAttribute<double>(TEXT("detail\tbearing\tvalue"));
		double oldInclination = COTEvent->GetAttribute<double>(TEXT("detail\tinclination\tvalue"));

		FGeodeticCoord2D oldArrowLocation2D = UVH_GlobeMathStatics::CalculateSurfaceDestination(oldBaseLocation2D, oldBearing, oldRange);
		FGeodeticCoord3D oldArrowLocation3D(oldArrowLocation2D);
		oldArrowLocation3D.Altitude = oldBaseLocation3D.Altitude + FMath::Sin(oldInclination) * oldRange;
		
		// populate updated base and current arrow location to calculate inclination/range/bearing later, then update COTEvent
		baseLocation3D.Longitude = updatedCoord.Longitude;
		baseLocation3D.Latitude = updatedCoord.Latitude;
		baseLocation3D.Altitude = updatedCoord.Altitude;

		arrowLocation3D.Longitude = oldArrowLocation3D.Longitude;
		arrowLocation3D.Latitude = oldArrowLocation3D.Latitude;
		arrowLocation3D.Altitude = oldArrowLocation3D.Altitude;
	}
	else if (index == 1)
	{
		// arrow

		// populate current base and updated arrow location to calculate inclination/range/bearing later, then update COTEvent
		baseLocation3D = baseCoordinate;

		arrowLocation3D.Longitude = updatedCoord.Longitude;
		arrowLocation3D.Latitude = updatedCoord.Latitude;
		arrowLocation3D.Altitude = updatedCoord.Altitude;
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_DetailSection_EditPoints::SetRangeBearingLocation | invalid index | index: %d"), index);
		return;
	}

	// update COTEvent
	COTEvent->SetPoint(baseLocation3D);

	FGeodeticCoord2D baseLocation2D = baseLocation3D.ToGeodeticCoord2D();
	FGeodeticCoord2D arrowLocation2D = arrowLocation3D.ToGeodeticCoord2D();

	double range = UVH_GlobeMathStatics::CalculateSurfaceDistance(baseLocation2D, arrowLocation2D);
	COTEvent->SetAttribute<double>(TEXT("detail\trange\tvalue"), range);

	COTEvent->SetAttribute<double>(TEXT("detail\tbearing\tvalue"), UVH_GlobeMathStatics::CalculateSurfaceBearing(baseLocation2D, arrowLocation2D));

	if (FMath::IsNearlyEqual(baseLocation3D.Altitude, 9999999.0))
	{
		// base is snapped, inclination doesn't have meaning; set it to 0
		COTEvent->SetAttribute<double>(TEXT("detail\tinclination\tvalue"), 0);
	}
	else if (FMath::IsNearlyEqual(arrowLocation3D.Altitude, 9999999.0))
	{
		// arrow is snapped, use terrain height to calculate inclination
		bool bFoundHeight = false;
		if (UGame_TileManager* tileManager = UGame_TileManager::Get())
		{
			double arrowHAE;
			if (tileManager->GetHAE(arrowLocation2D, arrowHAE))
			{
				double heightDelta = arrowHAE - baseLocation3D.Altitude;
				COTEvent->SetAttribute<double>(TEXT("detail\tinclination\tvalue"), FMath::Asin(heightDelta / range));

				bFoundHeight = true;
			}
		}

		if (!bFoundHeight)
		{
			// couldn't find height, set inclination to 0
			COTEvent->SetAttribute<double>(TEXT("detail\tinclination\tvalue"), 0);
		}
	}
	else
	{
		// neither are snapped, use height from UI to calculate inclination
		double heightDelta = arrowLocation3D.Altitude - baseLocation3D.Altitude;
		COTEvent->SetAttribute<double>(TEXT("detail\tinclination\tvalue"), FMath::Asin(heightDelta / range));
	}

	UpdateEntity();
}

void UGame_UserWidget_DetailSection_EditPoints::UpdateEntity()
{
	if (COTEvent != nullptr)
	{
		if (UGame_COTManager* cotManager = Cast<UGame_COTManager>(UVH_COTManager::Get()))
		{
			cotManager->InsertOrUpdate(COTEvent);
		}

		if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
		{
			if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
			{
				SpatialiteResults results = entityDB->QueryUID(COTEvent->GetAttribute(TEXT("uid")));
				if (results.Num() > 0)
				{
					voManager->UpdateEntityGlobal(results[0]);
				}
			}
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_UserWidget_DetailSection_EditPoints::HandleDatabaseInsertUpdate(const FSpatialiteResults_BP& results)
{
	for (const FSpatialiteResult_BP& resultBP : results.Results)
	{
		SpatialiteResult result = resultBP.Result;

		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

		if (entityUID.Equals(EntityUID))
		{
			UpdateCOTEvent();
		}
	}
}
