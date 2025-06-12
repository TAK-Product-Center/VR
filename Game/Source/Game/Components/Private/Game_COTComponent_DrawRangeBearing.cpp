#include "Game_COTComponent_DrawRangeBearing.h"
#include "Game.h"
#include "Game_COTManager.h"
#include "Game_DrawContainer.h"
#include "Game_EditPoint.h"
#include "Game_Arrow.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_UserWidget_Arrow.h"
#include "Game_WorldInteractableActor.h"

#include "VH_COTEvent.h"
#include "VH_GlobeMathStatics.h"

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
		AGame_EditPoint* baseEditPoint = Arrow->GetBaseEditPoint();

		FGeodeticCoord3D baseCoordinate = cotEvent->GetPoint();
		
		baseEditPoint->SetGeoLocation(baseCoordinate);

		baseEditPoint->SetActorLocation(globeReference->GeodeticToWorldDouble(baseCoordinate));

		// arrow
		double range = cotEvent->GetAttribute<double>(TEXT("detail\trange\tvalue"));
		double bearing = cotEvent->GetAttribute<double>(TEXT("detail\tbearing\tvalue"));

		AGame_EditPoint* arrowEditPoint = Arrow->GetArrowEditPoint();

		FGeodeticCoord2D arrowCoord2D = UVH_GlobeMathStatics::CalculateSurfaceDestination(baseEditPoint->GetGeoLocation().ToGeodeticCoord2D(), bearing, range);
		FGeodeticCoord3D arrowCoord3D(arrowCoord2D);

		double baseHeight = baseEditPoint->GetGeoLocation().Altitude;
		bool bSnapToGround = FMath::IsNearlyEqual(baseHeight, 9999999.0);

		if (bSnapToGround)
		{
			arrowCoord3D.Altitude = 9999999;
		}
		else
		{
			double inclination = cotEvent->GetAttribute<double>(TEXT("detail\tinclination\tvalue"));
			
			arrowCoord3D.Altitude = baseHeight + (FMath::Sin(FMath::DegreesToRadians(inclination)) * range);
		}

		arrowEditPoint->SetGeoLocation(arrowCoord3D);

		if (bSnapToGround)
		{
			arrowCoord3D.Altitude = 0;
			arrowCoord3D.bIsAltitudeRelativeToGround = true;
		}

		FVector worldLocation = globeReference->GeodeticToWorldDouble(arrowCoord3D);
		arrowEditPoint->SetActorLocation(worldLocation);
		
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
				cotEvent->SetAttribute(TEXT("callsign"), TEXT("Range & Bearing"));  // todo ohg | create unique title
			}

			cotEvent->PopulateTime(ActiveTime);

			// base
			FGeodeticCoord3D baseCoordinate = Arrow->GetBaseEditPoint()->GetGeoLocation();

			cotEvent->SetPoint(baseCoordinate);

			// todo ohg | implement linked actors
			/*if (LinkedBaseActor != nullptr)
			{
				FName anchorUID = FName();
				if (cotManager->GetUID(LinkedBaseActor, anchorUID))
				{
					detail->AnchorUID = anchorUID;
				}
			}*/

			// details
			FGeodeticCoord3D arrowCoordinate = Arrow->GetArrowEditPoint()->GetGeoLocation();

			FGeodeticCoord2D baseCoordinate2D = baseCoordinate.ToGeodeticCoord2D();
			FGeodeticCoord2D arrowCoordinate2D = arrowCoordinate.ToGeodeticCoord2D();

			double range = UVH_GlobeMathStatics::CalculateSurfaceDistance(baseCoordinate2D, arrowCoordinate2D);
			double bearing = UVH_GlobeMathStatics::CalculateSurfaceBearing(baseCoordinate2D, arrowCoordinate2D);
			cotEvent->SetAttribute<double>(TEXT("detail\trange\tvalue"), range);
			cotEvent->SetAttribute<double>(TEXT("detail\tbearing\tvalue"), bearing);

			// only care about inclination if neither are snapped
			if (!FMath::IsNearlyEqual(baseCoordinate.Altitude, 9999999.0) && !FMath::IsNearlyEqual(arrowCoordinate.Altitude, 9999999.0))
			{
				// neither snapped
				double heightDelta = arrowCoordinate.Altitude - baseCoordinate.Altitude;
				cotEvent->SetAttribute<double>(TEXT("detail\tinclination\tvalue"), FMath::Asin(heightDelta / range));
			}
			else
			{
				// at least one is snapped
				cotEvent->SetAttribute<double>(TEXT("detail\tinclination\tvalue"), 0);
			}

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

			// either both snap or both don't snap
			FGeodeticCoord3D arrowCoord = arrowEditPoint->GetGeoLocation();
			if (FMath::IsNearlyEqual(arrowCoord.Altitude, 9999999.0))
			{
				arrowCoord.Altitude = baseEditPoint->GetGeoLocation().Altitude;
				arrowEditPoint->SetGeoLocation(arrowCoord);
			}

			RegisterWithDatabase();
		}
		else if (manipulatedActor == arrowEditPoint)
		{
			arrowEditPoint->SetGeoLocation(globeRef->WorldToGeodeticDouble(arrowEditPoint->GetActorLocation()));

			// either both snap or both don't snap
			FGeodeticCoord3D baseCoord = baseEditPoint->GetGeoLocation();
			if (FMath::IsNearlyEqual(baseCoord.Altitude, 9999999.0))
			{
				baseCoord.Altitude = arrowEditPoint->GetGeoLocation().Altitude;
				baseEditPoint->SetGeoLocation(baseCoord);
			}

			RegisterWithDatabase();
		}
	}
}
