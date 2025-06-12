// Parent includes
#include "Game_DrawLineData.h"
#include "Game.h"

// Game layer includes
#include "Game_EditPoint.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_Statics.h"


// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_DrawLineData::UGame_DrawLineData() :
	SyncLineToEditPointsCooldown(0.1)
{

}


// ---------------------------------
// --- FTickableObjectBase
// ---------------------------------

bool UGame_DrawLineData::IsTickable() const
{
	return Line != nullptr && EditPoints.Num() > 0;
}

void UGame_DrawLineData::Tick(float deltaSeconds)
{
	TimeSinceLastSync += deltaSeconds;

	if (TimeSinceLastSync >= SyncLineToEditPointsCooldown)
	{
		SyncLineToEditPoints();

		TimeSinceLastSync = 0;
	}
}

TStatId UGame_DrawLineData::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UGame_DrawLineData, STATGROUP_Tickables);
}


// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_DrawLineData::BeginDestroy()
{
	if (Line != nullptr && !Line->IsActorBeingDestroyed())
	{
		Line->Destroy();
		Line = nullptr;
	}

	for (AGame_EditPoint* editPoint : EditPoints)
	{
		if (editPoint != nullptr && !editPoint->IsActorBeingDestroyed())
		{
			editPoint->Destroy();
		}
	}

	EditPoints.Empty();

	Super::BeginDestroy();
}


// ---------------------------------
// --- API
// ---------------------------------

void UGame_DrawLineData::SetEditPoints(const TArray<AGame_EditPoint*>& editPoints)
{
	EditPoints.Empty();

	EditPoints.Append(editPoints);

	PostModifyEditPoints(GetEditPoints());
}

TArray<AGame_EditPoint*> UGame_DrawLineData::GetEditPoints() const
{
	return EditPoints;
}

void UGame_DrawLineData::SetLine(AGame_SimpleSegmentedLineActor* line)
{
	Line = line;

	PostSetLine(line);
}

AGame_SimpleSegmentedLineActor* UGame_DrawLineData::GetLine() const
{
	return Line;
}

void UGame_DrawLineData::PreModifyVOGlobeReference(TArray<FVector>& positions)
{
	if (EditPoints.Num() > 0)
	{
		positions.Add(FVector(EditPoints.Num(), 0, 0));
		for (AGame_EditPoint* editPoint : EditPoints)
		{
			positions.Add(editPoint->GetActorLocation());
		}
	}
	else if (Line != nullptr)
	{
		positions.Add(FVector(Line->LinePoints.Num(), 0, 0));
		for (const FLinePoint& linePoint : Line->LinePoints)
		{
			positions.Add(linePoint.Location);
		}
	}
}

void UGame_DrawLineData::PostModifyVOGlobeReference(const TArray<FVector>& updatedPositions, int32& index)
{
	int32 numPoints = updatedPositions[index].X;
	index++;

	if (EditPoints.Num() > 0)
	{
		for (AGame_EditPoint* editPoint : EditPoints)
		{
			if (updatedPositions.IsValidIndex(index))
			{
				editPoint->SetActorLocation(updatedPositions[index]);
				index++;
			}
			else
			{
				UE_LOG(Game, Warning, TEXT("-- UGame_DrawLineData::PostModifyVOGlobeReference | %d | mismatch between EditPoints (%d) and updatedPositions (%d)"), numPoints, EditPoints.Num(), updatedPositions.Num());
			}
		}
		
		Line->GenerateMesh();
	}
	else
	{
		if (Line != nullptr)
		{
			for (FLinePoint& linePoint : Line->LinePoints)
			{
				if (updatedPositions.IsValidIndex(index))
				{
					linePoint.Location = updatedPositions[index];
					index++;
				}
				else
				{
					UE_LOG(Game, Warning, TEXT("-- UGame_DrawLineData::PostModifyVOGlobeReference | %d | mismatch between LinePoints (%d) and updatedPositions (%d)"), numPoints, Line->LinePoints.Num(), updatedPositions.Num());
				}
			}

			Line->GenerateMesh();
		}
	}
}

void UGame_DrawLineData::MoveEditPoint(const FVector& newPosition, int32 index)
{
	if (EditPoints.IsValidIndex(index))
	{
		AGame_EditPoint* editPoint = EditPoints[index];

		editPoint->SetActorLocation(newPosition);
		editPoint->SyncGeoLocationToWorldLocation();
	}

	PostModifyEditPoints(GetEditPoints());
}

void UGame_DrawLineData::AddEditPoint(AGame_EditPoint* editPoint, AGame_EditPoint* existingEditPoint)
{
	// verify edit point not already added
	if (EditPoints.Contains(editPoint))
	{
		return;
	}

	if (existingEditPoint == nullptr)
	{
		// add to the end
		EditPoints.Add(editPoint);
	}
	else
	{
		for (int32 i = 0; i < EditPoints.Num(); i++)
		{
			if (EditPoints[i] == existingEditPoint)
			{
				EditPoints.Insert(editPoint, i);
				break;
			}
		}
	}

	PostModifyEditPoints(GetEditPoints());
}

void UGame_DrawLineData::DeleteEditPoint(AGame_EditPoint* editPoint)
{
	for (int32 i = 0; i < EditPoints.Num(); i++)
	{
		if (EditPoints[i] == editPoint)
		{
			EditPoints.RemoveAt(i);
		}
	}

	editPoint->Destroy();

	PostModifyEditPoints(GetEditPoints());
}

void UGame_DrawLineData::DeleteEditPoints()
{
	for (int32 i = 0; i < EditPoints.Num(); i++)
	{
		EditPoints[i]->Destroy();
	}

	EditPoints.Empty();

	PostModifyEditPoints(GetEditPoints());
}

void UGame_DrawLineData::SetScale3D(const FVector& scale3D)
{
	if (Line != nullptr)
	{
		Line->SetActorScale3D(scale3D);
	}

	for (AGame_EditPoint* editPoint : EditPoints)
	{
		editPoint->SetActorScale3D(scale3D);
	}

	//Line->ClearLinePoints();
	//SyncLineToEditPoints();
}

void UGame_DrawLineData::SetHidden(bool bNewHidden)
{
	if (Line != nullptr)
	{
		Line->SetActorHiddenInGame(bNewHidden);
	}

	for (AGame_EditPoint* editPoint : EditPoints)
	{
		editPoint->SetActorHiddenInGame(bNewHidden);
	}
}


// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_DrawLineData::SyncLineToEditPoints()
{
	if (Line != nullptr && EditPoints.Num() > 0)
	{
		bool bGenerateMesh = false;

		if (Line->LinePoints.Num() != EditPoints.Num() || !Line->AreCoordinatesValid())
		{
			Line->ClearLinePoints();

			for (int32 i = 0; i < EditPoints.Num(); i++)
			{
				Line->AddLocationAndGeoLocation(EditPoints[i]->GetActorLocation(), EditPoints[i]->GetGeoLocation());
			}

			bGenerateMesh = true;
		}
		else
		{
			for (int32 i = 0; i < EditPoints.Num(); i++)
			{
				FVector currentLocation = EditPoints[i]->GetLineDrawLocation();
				FGeodeticCoord3D currentGeoLocation = EditPoints[i]->GetGeoLocation();

				if (!currentLocation.Equals(Line->LinePoints[i].Location) || currentGeoLocation != Line->GetGeoLocation(i))
				{
					if (currentLocation.IsZero())
					{
						UE_LOG(Game, Warning, TEXT("-- UGame_DrawLineData::SyncLineToEditPoints | EditPoints[%d] line draw location is [0, 0, 0]"), i);
					}
					if (currentGeoLocation == FGeodeticCoord3D(0, 0, 0))
					{
						UE_LOG(Game, Warning, TEXT("-- UGame_DrawLineData::SyncLineToEditPoints | EditPoints[%d] geodetic location is [0, 0, 0]"), i);
					}

					Line->UpdateLocationAndGeoLocation(i, currentLocation, currentGeoLocation);

					bGenerateMesh = true;
				}
			}
		}

		if (bGenerateMesh)
		{
			Line->GenerateMesh();
		}
	}
}

void UGame_DrawLineData::PostSetLine(AGame_SimpleSegmentedLineActor* line)
{

}

void UGame_DrawLineData::PostModifyEditPoints(const TArray<AGame_EditPoint*>& editPoints)
{

}