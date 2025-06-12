#include "Game_COTComponent_DrawRubbersheet.h"
#include "Game.h"

#include "VH_COTEvent.h"
#include "VH_GlobeMathStatics.h"
#include "VH_COTStatics.h"
#include "Developer_Statics.h"

#include "Game_COTManager.h"
#include "Game_EntityDB.h"
#include "Game_PlayerController.h"
#include "Game_ImportedMeshComponent.h"
#include "Game_AdjustableModelImportComponent.h"
#include "Game_EditPoint_Center.h"
#include "Game_VirtualObjective.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_COTComponent_DrawRubbersheet::UGame_COTComponent_DrawRubbersheet() :
	InitialWidthInMeters(-1),
	InitialLengthInMeters(-1),
	InitialScale(FVector(1, 1, 1))
{
	bFixOppositeWhileResizing = false;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_COTComponent_DrawRubbersheet::UpdateRectangleShape(AGame_EditPoint* inManipulatedPoint)
{
	Super::UpdateRectangleShape(inManipulatedPoint);

	WatchActor->SetActorScale3D(GetVirtualObjective()->GetActorScale3D() * ComputeScale());
}

void UGame_COTComponent_DrawRubbersheet::PostManipulationEnd(AActor* manipulatedActor)
{
	Super::PostManipulationEnd(manipulatedActor);

	if (manipulatedActor == CenterEditPoint)
	{
		FVector currentEditPointLocation = CenterEditPoint->GetActorLocation();

		FVector locationDiff = currentEditPointLocation - CenterEditPointLocationCache;
		CenterEditPointLocationCache = currentEditPointLocation;

		WatchActor->SetActorLocation(WatchActor->GetActorLocation() + locationDiff);
	}
}

AGame_VirtualObjective* UGame_COTComponent_DrawRubbersheet::GetVirtualObjective() const
{
	return AGame_PlayerController::GetPlayerActiveVO();
}

AVH_GlobeReferenceActor* UGame_COTComponent_DrawRubbersheet::GetGlobeReference() const
{
	if (AGame_VirtualObjective* virtualObjective = GetVirtualObjective())
	{
		return virtualObjective->GetGlobeReference();
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_COTComponent_DrawRubbersheet::GetGlobeReference | cannot determine globe reference"));
	return nullptr;
}

void UGame_COTComponent_DrawRubbersheet::UpdateRectangleRotation(AGame_EditPoint_RectangleRotator* inManipulatedPoint)
{
	Super::UpdateRectangleRotation(inManipulatedPoint);

	FRotator rotator = WatchActor->GetActorRotation();
	rotator.Yaw = RotationInDegrees;
	
	WatchActor->SetActorRotation(rotator);
}

void UGame_COTComponent_DrawRubbersheet::RegisterWithDatabase(AGame_VirtualObjective* virtualObjective)
{
	if (ImportComponent != nullptr)
	{
		// scale
		ImportComponent->SetScale(ComputeScale());

		// rotation
		FRotator rotator = WatchActor->GetActorRotation();
		rotator.Yaw = RotationInDegrees;

		ImportComponent->SetRotation(rotator);

		// location
		FVector modifiedWorldLocation = CenterEditPoint->GetActorLocation() + FVector(0, 0, HeightDiffUU);
		ImportComponent->SetGeoLocation(GetGlobeReference()->WorldToGeodeticDouble(modifiedWorldLocation));

		ImportComponent->SaveDataToDatabase();
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_COTComponent_DrawRubbersheet::SetWatchEntityUID(const FString& inWatchEntityUID)
{
	WatchEntityUID = inWatchEntityUID;
	WatchActor = nullptr;

	TSet<AActor*> actorSet = GetVirtualObjective()->GetActorsForEntity(WatchEntityUID);
	for (AActor* actor : actorSet)
	{
		if (UGame_AdjustableModelImportComponent* importComponent = actor->FindComponentByClass<UGame_AdjustableModelImportComponent>())
		{
			WatchActor = actor;
			ImportComponent = importComponent;

			break;
		}
	}

	if (WatchActor == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_COTComponent_DrawRubbersheet::UpdateWatchActor | no actors had UGame_AdjustableModelImportComponent for WatchUID | %s | numEntities: %d"), *WatchEntityUID, actorSet.Num());
		return;
	}

	// not tracking rubbersheet draw container in database
	// if WatchActor is paged out (i.e. destroyed), then destroy rubbersheet draw container
	WatchActor->OnDestroyed.AddDynamic(this, &UGame_COTComponent_DrawRubbersheet::HandleWatchActorDestroyed);

	UpdateRectangle();
}

UGame_AdjustableModelImportComponent* UGame_COTComponent_DrawRubbersheet::GetImportComponent() const
{
	return ImportComponent;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_COTComponent_DrawRubbersheet::UpdateRectangle()
{
	// create rectangle size of bounding box, then rotate
	//		can make for a rectangle bigger than model, but it's an acceptable approximation
	SpatialiteResults results = UGame_EntityDB::Get()->QueryUID(WatchEntityUID);
	if (results.Num() > 0)
	{
		// longitude is index 0, latitude is index 1
		TArray<double> northWestBB = UDatabase_Spatialite::GetPoint(TEXT("northWestBB"), results[0]);
		TArray<double> southEastBB = UDatabase_Spatialite::GetPoint(TEXT("southEastBB"), results[0]);

		// get corners
		FGeodeticCoord3D northEast(southEastBB[0], northWestBB[1], 0);
		FGeodeticCoord3D southEast(southEastBB[0], southEastBB[1], 0);
		FGeodeticCoord3D southWest(northWestBB[0], southEastBB[1], 0);
		FGeodeticCoord3D northWest(northWestBB[0], northWestBB[1], 0);

		// get center
		double nWToSEBearing_Degrees = UVH_GlobeMathStatics::CalculateSurfaceBearing(northWest.ToGeodeticCoord2D(), southEast.ToGeodeticCoord2D());
		double nWToSERange_Meters = UVH_GlobeMathStatics::CalculateSurfaceDistance(northWest.ToGeodeticCoord2D(), southEast.ToGeodeticCoord2D());
		FGeodeticCoord2D center = UVH_GlobeMathStatics::CalculateSurfaceDestination(northWest.ToGeodeticCoord2D(), nWToSEBearing_Degrees, nWToSERange_Meters / 2);
		FGeodeticCoord3D center3D = FGeodeticCoord3D(center.Longitude, center.Latitude, 0);

		AVH_GlobeReferenceActor* globeRef = GetGlobeReference();
		FVector centerWorldLocation;
		if (UGame_ImportedMeshComponent* meshComponent = WatchActor->FindComponentByClass<UGame_ImportedMeshComponent>())
		{
			FBox meshBB;
			if (meshComponent->GetGeodeticBounds(meshBB))
			{
				center3D.Altitude = meshBB.GetCenter().Z;
				centerWorldLocation = globeRef->GeodeticToWorldDouble(center3D);
			}
			else
			{
				// bounds not calculated yet, delay and try again
				if (UWorld* world = UDeveloper_Statics::GetVHWorld())
				{
					FTimerHandle timerHandle;
					world->GetTimerManager().SetTimer(timerHandle, this, &UGame_COTComponent_DrawRubbersheet::UpdateRectangle, 0.5, false);

					return;
				}
			}
		}
		else
		{
			centerWorldLocation = globeRef->GeodeticToWorldDouble(center3D);
			centerWorldLocation.Z = WatchActor->GetActorLocation().Z;
		}

		SpawnDrawElements(centerWorldLocation, FLinearColor::Green);

		CenterEditPoint->SetCallsign(TEXT("Rubbersheet"));

		CenterEditPointLocationCache = CenterEditPoint->GetActorLocation();
		HeightDiffUU = WatchActor->GetActorLocation().Z - CenterEditPointLocationCache.Z;


		// todo ohg | disabling for now do to performance hitches
		/*if (UGame_ImportedMeshComponent* meshComponent = WatchActor->FindComponentByClass<UGame_ImportedMeshComponent>())
		{
			FBox boundsBox =  meshComponent->CalculateBounds(true);
			FGeodeticCoord2D northWestCoord(boundsBox.Min.X, boundsBox.Max.Y);
			FGeodeticCoord2D northEastCoord(boundsBox.Max.X, boundsBox.Max.Y);
			FGeodeticCoord2D southEastCoord(boundsBox.Max.X, boundsBox.Min.Y);
			FGeodeticCoord2D southWestCoord(boundsBox.Min.X, boundsBox.Min.Y);
			CalculateRectangleLengthWidth(northWestCoord, northEastCoord, southEastCoord, southWestCoord, LengthInMeters, WidthInMeters);
			WidthInMeters *= ImportComponent->GetScale().X;
			LengthInMeters *= ImportComponent->GetScale().Y;
			UE_LOG(Game, Warning, TEXT("l: %f, w: %f | nw: %s | se: %s | scale: %s"), LengthInMeters, WidthInMeters, *northWest.ToString(), *southEast.ToString(), *ImportComponent->GetScale().ToString());
		}
		else
		{*/
			UVH_COTStatics::CalculateRectangleLengthWidth(northEast.ToGeodeticCoord2D(), southEast.ToGeodeticCoord2D(), southWest.ToGeodeticCoord2D(), northWest.ToGeodeticCoord2D(), LengthInMeters, WidthInMeters);
		//}
			
		if (ImportComponent != nullptr)
		{
			FRotator rotationFromComponent = ImportComponent->GetRotation();
			RotationInDegrees = rotationFromComponent.Yaw;

			InitialScale = ImportComponent->GetScale();
		}

		// todo ohg | set to actual length/width after prevent core rectangle code from swapping length/width
		InitialWidthInMeters = -1;
		InitialLengthInMeters = -1;

		UpdateRectangleFromFields(true);
	}
}

FVector UGame_COTComponent_DrawRubbersheet::ComputeScale()
{
	// todo ohg | set to actual length/width after prevent core rectangle code from swapping length/width
	if (InitialLengthInMeters == -1)
	{
		InitialLengthInMeters = LengthInMeters;
	}

	if (InitialWidthInMeters == -1)
	{
		InitialWidthInMeters = WidthInMeters;
	}
	
	// todo ohg | had to flip this, but not sure why or if that was the correct way to handle things
	FVector rubbersheetScale = InitialScale * FVector(WidthInMeters / InitialWidthInMeters, LengthInMeters / InitialLengthInMeters, 1);

	return rubbersheetScale;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_COTComponent_DrawRubbersheet::HandleWatchActorDestroyed(AActor* destroyedActor)
{
	UE_LOG(Game, Warning, TEXT("-- UGame_COTComponent_DrawRubbersheet::HandleWatchActorDestroyed | watchActor destroyed, removing rubbersheet"));

	GetOwner()->Destroy();
}
