// Required Includes
#include "Game_COTComponent_Draw.h"
#include "Game.h"

// Engine Includes
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"

// Game Includes
#include "Game_GameInstance.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_EditPoint.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_DrawLineData.h"
#include "Game_TerrainTile.h"
#include "Game_DrawContainer.h"
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_COTComponent_Draw::UGame_COTComponent_Draw() :
	LineClass(AGame_SimpleSegmentedLineActor::StaticClass()),
	EditPointClass(AGame_EditPoint::StaticClass()),
	DrawLineDataClass(UGame_DrawLineData::StaticClass())
{
	bGenerateCallsign = false;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_COTComponent_Draw::EndPlay(const EEndPlayReason::Type endPlayReason) 
{
	Super::EndPlay(endPlayReason);

	for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
	{
		entry.Value->ConditionalBeginDestroy();
	}

	Lines.Empty();
}

void UGame_COTComponent_Draw::SnapToGround()
{
	for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
	{
		TArray<AGame_EditPoint*> editPoints = entry.Value->GetEditPoints();
		AGame_SimpleSegmentedLineActor* line = entry.Key;
		
		if (editPoints.Num() > 0)
		{
			if (line != nullptr)
			{
				line->SetActorEnableCollision(false);
			}

			for (AGame_EditPoint* editPoint : editPoints)
			{
				if (ShouldSnapEditPoint(editPoint))
				{
					FVector worldLocation = editPoint->GetActorLocation();

					// snap to ground to find Z
					FTransform surfaceTransform = UGame_Statics::GetWorldTransformOverride(worldLocation);
					surfaceTransform.SetLocation(worldLocation);

					FVector startLocation = surfaceTransform.TransformPosition(FVector(0, 0, 10000000));
					FVector endLocation = surfaceTransform.TransformPosition(FVector(0, 0, -10000000));

					FCollisionQueryParams queryParams(NAME_None, true);
					queryParams.AddIgnoredActor(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
					queryParams.AddIgnoredActor(editPoint);

					FHitResult hit;
					if (GetWorld()->LineTraceSingleByChannel(hit, startLocation, endLocation, UGame_GameInstance::GetTerrainCollisionChannel(), queryParams))
					{
						worldLocation.Z = hit.Location.Z;

						editPoint->SetActorLocation(worldLocation);
					}
				}
			}

			if (line != nullptr)
			{
				line->SetActorEnableCollision(true);
			}
		}
		else if (line != nullptr)
		{
			line->SnapToGround();
		}
	}
}

TArray<FVector> UGame_COTComponent_Draw::PreModifyVOGlobeReference()
{
	TArray<FVector> positions;
	positions.Add(GetOwner()->GetActorLocation());

	for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
	{
		entry.Value->PreModifyVOGlobeReference(positions);
	}

	return positions;
}

void UGame_COTComponent_Draw::PostModifyVOGlobeReference(const TArray<FVector>& updatedPositions)
{
	// index 0 is for draw container, 1+ is for edit points

	int32 index = 0;
	GetOwner()->SetActorLocation(updatedPositions[index]);
	index++;

	for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
	{
		entry.Value->PostModifyVOGlobeReference(updatedPositions, index);
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_COTComponent_Draw::AddEditPoint(AGame_SimpleSegmentedLineActor* line, AGame_EditPoint* editPoint, AGame_EditPoint* existingEditPoint)
{
	if (editPoint != nullptr)
	{
		if (line == nullptr)
		{
			line = SpawnLine();
		}

		if (UGame_DrawLineData** lineDataPtr = Lines.Find(line))
		{
			(*lineDataPtr)->AddEditPoint(editPoint, existingEditPoint);
		}

		AddEditPoint_Virtual(line, editPoint, existingEditPoint);
	}
}

AGame_EditPoint* UGame_COTComponent_Draw::SpawnEditPoint(AGame_SimpleSegmentedLineActor* line, const FVector& location, AGame_EditPoint* existingEditPoint)
{
	FTransform spawnTransform = FTransform(FRotator(0, 0, 0), location, GetOwner()->GetActorScale3D());
	
	AGame_EditPoint* editPoint = GetWorld()->SpawnActorDeferred<AGame_EditPoint>(EditPointClass, spawnTransform, GetOwner(), nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	editPoint->SetDrawContainer(Cast<AGame_DrawContainer>(GetOwner()));

	UGameplayStatics::FinishSpawningActor(editPoint, spawnTransform);

	editPoint->SetActive(true);
	editPoint->SetLineActor(line);

	if (AVH_GlobeReferenceActor* globeRef = GetGlobeReference())
	{
		editPoint->SetGeoLocation(globeRef->WorldToGeodeticDouble(editPoint->GetActorLocation()));
	}

	AddEditPoint(line, editPoint, existingEditPoint);

	return editPoint;
}

AGame_EditPoint* UGame_COTComponent_Draw::SpawnEditPointAtIndex(AGame_SimpleSegmentedLineActor* line, const FVector& location, int32 index)
{
	if(index >= 0 && index < line->LinePoints.Num())
	{
		if (UGame_DrawLineData** lineDataPtr = Lines.Find(line))
		{
			if((*lineDataPtr)->GetEditPoints().Num() > index)
			{
				return SpawnEditPoint(line, location, (*lineDataPtr)->GetEditPoints()[index]);
			}
		}
	}
	
	return nullptr;

}

void UGame_COTComponent_Draw::DeleteEditPoint(AGame_SimpleSegmentedLineActor* line, AGame_EditPoint* editPoint)
{
	if (editPoint != nullptr)
	{
		if (UGame_DrawLineData** lineDataPtr = Lines.Find(line))
		{
			(*lineDataPtr)->DeleteEditPoint(editPoint);
		}

		DeleteEditPoint_Virtual(line, editPoint);

		editPoint->Destroy();
	}
}

void UGame_COTComponent_Draw::SetLineCollision(AGame_SimpleSegmentedLineActor* line, bool bShouldCollide)
{
	for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
	{
		if (line == nullptr || entry.Key == line)
		{
			entry.Key->SetActorEnableCollision(bShouldCollide);
		}
	}
}

void UGame_COTComponent_Draw::AddLine(AGame_SimpleSegmentedLineActor* line)
{
	UGame_DrawLineData* drawLineData = NewObject<UGame_DrawLineData>(this, DrawLineDataClass);
	drawLineData->SetLine(line);

	Lines.Add(line, drawLineData);
}

AGame_SimpleSegmentedLineActor* UGame_COTComponent_Draw::SpawnLine()
{
	FTransform spawnTransform = FTransform(FRotator(0, 0, 0), FVector(0, 0, 0), GetOwner()->GetActorScale3D());

	AGame_SimpleSegmentedLineActor* line = Cast<AGame_SimpleSegmentedLineActor>(GetWorld()->SpawnActorDeferred<AGame_SimpleSegmentedLineActor>(LineClass, spawnTransform, GetOwner(), nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn));
	line->SetDrawContainer(Cast<AGame_DrawContainer>(GetOwner()));

	UGameplayStatics::FinishSpawningActor(line, spawnTransform);

	AddLine(line);

	return line;
}

void UGame_COTComponent_Draw::HandleOwnerSetScale3D(const FVector& scale3D)
{
	for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
	{
		entry.Value->SetScale3D(scale3D);
	}
}

void UGame_COTComponent_Draw::HandleOwnerSetHidden(bool bNewHidden)
{
	for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
	{
		entry.Value->SetHidden(bNewHidden);
	}
}

AGame_SimpleSegmentedLineActor* UGame_COTComponent_Draw::GetLineForEditPoint(AGame_EditPoint* editPoint) const
{
	for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
	{
		if (entry.Value->GetEditPoints().Contains(editPoint))
		{
			return entry.Key;
		}
	}

	return nullptr;
}

bool UGame_COTComponent_Draw::GetEditPoints(AGame_SimpleSegmentedLineActor* line, TArray<AGame_EditPoint*>& editPoints) const
{
	if (UGame_DrawLineData* const* lineDataPtr = Lines.Find(line))
	{
		editPoints.Append((*lineDataPtr)->GetEditPoints());

		return true;
	}

	return false;
}

TArray<AGame_SimpleSegmentedLineActor*> UGame_COTComponent_Draw::GetLines() const
{
	TArray<AGame_SimpleSegmentedLineActor*> lines;

	Lines.GenerateKeyArray(lines);

	return lines;
}

void UGame_COTComponent_Draw::SetEditPointsActive(AGame_SimpleSegmentedLineActor* line, bool bActive)
{
	if (line != nullptr)
	{
		TArray<AGame_EditPoint*> editPoints;
		if (GetEditPoints(line, editPoints))
		{
			for (AGame_EditPoint* editPoint : editPoints)
			{
				editPoint->SetActive(bActive);
			}
		}
	}
	else
	{
		for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
		{
			SetEditPointsActive(entry.Key, bActive);
		}
	}
}

bool UGame_COTComponent_Draw::IsLineActive(AGame_SimpleSegmentedLineActor* line) const
{
	TArray<AGame_EditPoint*> editPoints;
	GetEditPoints(line, editPoints);

	if (editPoints.Num() > 0)
	{
		return editPoints[0]->GetActive();
	}

	return false;
}

AGame_EditPoint* UGame_COTComponent_Draw::GetClosestEditPoint(AGame_SimpleSegmentedLineActor* line, const FVector& location) const
{
	AGame_EditPoint* closestEditPoint = nullptr;
	double distance = MAX_dbl;

	TArray<AGame_EditPoint*> editPoints;
	if (GetEditPoints(line, editPoints))
	{
		for (AGame_EditPoint* editPoint : editPoints)
		{
			double distanceCheck = FVector::Dist(location, editPoint->GetActorLocation());
			if (distanceCheck < distance)
			{
				distance = distanceCheck;

				closestEditPoint = editPoint;
			}
		}
	}

	return closestEditPoint;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_COTComponent_Draw::DeleteEditPoints(AGame_SimpleSegmentedLineActor* line)
{
	if (UGame_DrawLineData** lineDataPtr = Lines.Find(line))
	{
		(*lineDataPtr)->DeleteEditPoints();
	}

    DeleteEditPoints_Virtual(line);
}

bool UGame_COTComponent_Draw::ShouldSnapEditPoint(AGame_EditPoint* editPoint) const
{
	if (editPoint != nullptr)
	{
		return FMath::IsNearlyEqual(editPoint->GetGeoLocation().Altitude, 9999999.0);
	}

	return false;
}