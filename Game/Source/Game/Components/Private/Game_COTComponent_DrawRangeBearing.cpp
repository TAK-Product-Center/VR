// Required Includes
#include "Game_COTComponent_DrawRangeBearing.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_COTEvent.h"
#include "VH_GlobeMathStatics.h"

// Game Includes
#include "Game_COTManager.h"
#include "Game_DrawContainer.h"
#include "Game_EditPoint.h"
#include "Game_Arrow.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_UserWidget_Arrow.h"
#include "Game_WorldInteractableActor.h"
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_COTComponent_DrawRangeBearing::UGame_COTComponent_DrawRangeBearing()
{
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_COTComponent_DrawRangeBearing::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	Super::EndPlay(endPlayReason);

	if (Arrow != nullptr)
	{
		Arrow->Destroy();
	}
}

void UGame_COTComponent_DrawRangeBearing::ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent)
{
	Super::ReceiveCOTUpdate_Virtual(cotEvent);

	if (cotEvent != nullptr)
	{
		AVH_GlobeReferenceActor* globeReference = GetGlobeReference();

		if (Arrow == nullptr)
		{
			SpawnArrow(FVector(0, 0, 0));
		}

		Arrow->GetLine()->SetColor(cotEvent->GetAttribute<FColor>(TEXT("detail\tcolor\tvalue")));

		// base
		FGeodeticCoord3D baseCoordinate = cotEvent->GetPoint();
		
		AGame_EditPoint* baseEditPoint = Arrow->GetBaseEditPoint();
		baseEditPoint->SetGeoLocation(baseCoordinate);
		baseEditPoint->SyncWorldLocationToGeoLocation();

		// arrow
		double range = cotEvent->GetAttribute<double>(TEXT("detail\trange\tvalue"));
		double bearingDegrees = cotEvent->GetAttribute<double>(TEXT("detail\tbearing\tvalue"));
		double inclinationRadians = FMath::DegreesToRadians(cotEvent->GetAttribute<double>(TEXT("detail\tinclination\tvalue")));

		FGeodeticCoord2D arrowSurfaceCoordinate = UVH_GlobeMathStatics::CalculateSurfaceDestination(baseCoordinate.ToGeodeticCoord2D(), bearingDegrees, range);
		
		FGeodeticCoord3D arrowCoordinate = FGeodeticCoord3D(arrowSurfaceCoordinate, baseCoordinate.Altitude + (FMath::Tan(inclinationRadians) * range));

		if (FMath::IsNearlyEqual(baseCoordinate.Altitude, 9999999.0))
		{
			// base is snapped, inclination doesn't have meaning; set arrow to same height as base
			arrowCoordinate.Altitude = baseCoordinate.Altitude;
		}

		AGame_EditPoint* arrowEditPoint = Arrow->GetArrowEditPoint();
		arrowEditPoint->SetGeoLocation(arrowCoordinate);
		arrowEditPoint->SyncWorldLocationToGeoLocation();
		
		// 0 is true north
		// 1 is magnetic north
		//cotEvent->SetAttribute<int32>(TEXT("detail\tnorthRef"), 1)
	}
}

void UGame_COTComponent_DrawRangeBearing::PopulateCOT_Virtual()
{
	Super::PopulateCOT_Virtual();

	if (Arrow == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_COTComponent_DrawRangeBearing::PopulateCOT_Virtual | Arrow was null."));
		return;
	}

	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		if (UVH_COTEvent* cotEvent = GetCurrentCOTEvent())
		{
			cotEvent->SetAttribute(TEXT("type"), TEXT("u-rb-a"));

			if (cotEvent->GetAttribute(TEXT("callsign")).IsEmpty())
			{
				FString callsign = UGame_Statics::GetUniqueCOTEntityCallsign(cotEvent, TEXT("Range & Bearing"));

				cotEvent->SetAttribute(TEXT("callsign"), callsign);
			}

			cotEvent->PopulateTime(ActiveTime);

			// base
			FGeodeticCoord3D baseCoordinate = Arrow->GetBaseEditPoint()->GetGeoLocation();

			cotEvent->SetPoint(baseCoordinate);

			// details
			FGeodeticCoord3D arrowCoordinate = Arrow->GetArrowEditPoint()->GetGeoLocation();

			FGeodeticCoord2D baseCoordinate2D = baseCoordinate.ToGeodeticCoord2D();
			FGeodeticCoord2D arrowCoordinate2D = arrowCoordinate.ToGeodeticCoord2D();

			double range = UVH_GlobeMathStatics::CalculateSurfaceDistance(baseCoordinate2D, arrowCoordinate2D);
			double bearingDegrees = UVH_GlobeMathStatics::CalculateSurfaceBearing(baseCoordinate2D, arrowCoordinate2D);
			cotEvent->SetAttribute<double>(TEXT("detail\trange\tvalue"), range);
			cotEvent->SetAttribute<double>(TEXT("detail\tbearing\tvalue"), bearingDegrees);

			double heightDelta = arrowCoordinate.Altitude - baseCoordinate.Altitude;
			cotEvent->SetAttribute<double>(TEXT("detail\tinclination\tvalue"), FMath::RadiansToDegrees(FMath::Atan(heightDelta / range)));

			cotEvent->SetAttribute<FColor>(TEXT("detail\tcolor\tvalue"), Arrow->GetLine()->GetColor());
			cotEvent->SetAttribute<FColor>(TEXT("strokeColor"), Arrow->GetLine()->GetColor());

			// 0 is true north
			// 1 is magnetic north
			cotEvent->SetAttribute<int32>(TEXT("detail\tnorthRef"), 0);
		}
	}
}

void UGame_COTComponent_DrawRangeBearing::SetEditPointsActive(AGame_SimpleSegmentedLineActor* line, bool bActive)
{
	// range and bearing edit points are always active
	Super::SetEditPointsActive(line, true);
}

void UGame_COTComponent_DrawRangeBearing::HandleOwnerSetHidden(bool bNewHidden)
{
	Super::HandleOwnerSetHidden(bNewHidden);

	if (Arrow != nullptr)
	{
		Arrow->SetActorHiddenInGame(bNewHidden);
	}
}

// ---------------------------------
// --- API
// ---------------------------------

AGame_Arrow* UGame_COTComponent_DrawRangeBearing::SpawnArrow(const FVector& editPointLocation)
{
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = GetOwner();
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	Arrow = Cast<AGame_Arrow>(GetWorld()->SpawnActor<AGame_Arrow>(ArrowClass, editPointLocation, FRotator(0, 0, 0), spawnParams));
	Arrow->bSyncLineToEditPoints = false;  // handled in UGame_DrawLineData::Tick
	Arrow->GetUIWidget()->VirtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(GetOwner());

	AGame_DrawContainer* drawContainer = Cast<AGame_DrawContainer>(GetOwner());
	Arrow->GetBaseEditPoint()->SetDrawContainer(drawContainer);
	Arrow->GetArrowEditPoint()->SetDrawContainer(drawContainer);
	Arrow->GetLine()->SetDrawContainer(drawContainer);

	AddLine(Arrow->GetLine());
	AddEditPoint(Arrow->GetLine(), Arrow->GetBaseEditPoint(), nullptr);
	AddEditPoint(Arrow->GetLine(), Arrow->GetArrowEditPoint(), nullptr);

	Arrow->GetBaseEditPoint()->SyncGeoLocationToWorldLocation();
	Arrow->GetArrowEditPoint()->SyncGeoLocationToWorldLocation();

	Arrow->GetBaseEditPoint()->OnManipulationEnd.AddDynamic(this, &UGame_COTComponent_DrawRangeBearing::HandleManipulationEnd);
	Arrow->GetArrowEditPoint()->OnManipulationEnd.AddDynamic(this, &UGame_COTComponent_DrawRangeBearing::HandleManipulationEnd);

	return Arrow;
}

AGame_Arrow* UGame_COTComponent_DrawRangeBearing::GetArrow() const
{
	return Arrow;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_COTComponent_DrawRangeBearing::HandleManipulationEnd(AActor* manipulatedActor)
{
	// TODO: consider if we can crash in this function if the baseditpoint don't exist. 
	
	if (AVH_GlobeReferenceActor* globeRef = GetGlobeReference())
	{
		AGame_EditPoint* baseEditPoint = Arrow->GetBaseEditPoint();
		AGame_EditPoint* arrowEditPoint = Arrow->GetArrowEditPoint();

		if (manipulatedActor == baseEditPoint)
		{
			baseEditPoint->SetGeoLocation(globeRef->WorldToGeodeticDouble(baseEditPoint->GetActorLocation()));

			RegisterWithDatabase();
		}
		else if (manipulatedActor == arrowEditPoint)
		{
			arrowEditPoint->SetGeoLocation(globeRef->WorldToGeodeticDouble(arrowEditPoint->GetActorLocation()));

			RegisterWithDatabase();
		}
	}
}
