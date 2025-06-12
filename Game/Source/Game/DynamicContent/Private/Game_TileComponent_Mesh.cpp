// Required Includes
#include "Game_TileComponent_Mesh.h"
#include "Game.h"

// VH platform
#include "VH_GlobeReferenceActor.h"
#include "Developer_Statics.h"

// Game Includes
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_TerrainTile.h"
#include "Game_PlayerState.h"
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_TileComponent_Mesh::UGame_TileComponent_Mesh() :
	bDrawDistanceDirty(false),
	DrawDistance(-1),
	DrawDistanceCenter(FVector::ZeroVector),
	DrawCullBoxUU(EForceInit::ForceInit)
{
	VerticesCritSection = new FCriticalSection();
	TrianglesCritSection = new FCriticalSection();
	UVsCritSection = new FCriticalSection();
}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool UGame_TileComponent_Mesh::IsReadyForFinishDestroy()
{
	if (Super::IsReadyForFinishDestroy())
	{
		if (VerticesCritSection != nullptr)
		{
			delete VerticesCritSection;
			VerticesCritSection = nullptr;
		}

		if (TrianglesCritSection != nullptr)
		{
			delete TrianglesCritSection;
			TrianglesCritSection = nullptr;
		}

		if (UVsCritSection != nullptr)
		{
			delete UVsCritSection;
			UVsCritSection = nullptr;
		}

		return true;
	}

	return false;
}

void UGame_TileComponent_Mesh::ExecuteGameThreadLogic()
{
	if (GetComponentStatus() == EComponentStatus::HelperThreadFinished)
	{
		SetComponentStatus(EComponentStatus::GameThreadStarted);

		TArray<FVector> vertices;
		TArray<int32> triangles;
		TArray<FVector2D> uvs;

		{
			FScopeLock scopeLock(TrianglesCritSection);
			triangles.Append(TrianglesInRange);
		}

		{
			FScopeLock scopeLock(VerticesCritSection);
			vertices.Append(Vertices);
		}

		{
			FScopeLock scopeLock(UVsCritSection);
			uvs.Append(UVs);
		}

		if (bDrawDistanceDirty)
		{
			SetComponentStatus(EComponentStatus::Initialized);
		}
		else
		{
			SetComponentStatus(EComponentStatus::GameThreadFinished);

			OnGameLogicCompleted.ExecuteIfBound(vertices, triangles, uvs);
		}
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent_Mesh::ExecuteGameThreadLogic | unable to start game thread logic because of status: %d"), (int32)GetComponentStatus());
	}
}

bool UGame_TileComponent_Mesh::SetBoundsAndZoomVirtual(const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds, int32 zoomLevel)
{
	Vertices.Empty();
	Triangles.Empty();
	UVs.Empty();

	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		if (playerState->GetIsInTOC() && zoomLevel < 13)
		{
			// if zoom is too little, no vertices will be in the table's view
			ZoomLevel = 13;
		}
	}

	return true;
}

bool UGame_TileComponent_Mesh::GlobeReferenceScaleUpdated(const FVector& newScale3D)
{
	SetDrawDistanceDirty();

	return true;
}

// ---------------------------------
// --- API
// ---------------------------------

bool UGame_TileComponent_Mesh::SetDrawDistance(const FVector& center, const double distanceMeters)
{
	if (AGame_VirtualObjective* activeVO = GetVirtualObjective())
	{
		float distanceUU = distanceMeters * activeVO->GetUnrealUnitsPerMeter();

		if (DrawDistance != distanceUU || !DrawDistanceCenter.Equals(center))
		{
			DrawDistance = distanceUU;
			DrawDistanceCenter = center;

			bDrawDistanceDirty = true;
		}
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent_Mesh::SetDrawDistance | activeVO is nullptr"));
	}

	return bDrawDistanceDirty;
}

bool UGame_TileComponent_Mesh::GetDrawDistance(float& distanceUU, FVector& center) const
{
	distanceUU = DrawDistance;

	center = DrawDistanceCenter;

	return distanceUU > 0;
}


void UGame_TileComponent_Mesh::SetDrawCullBox(const FBox2D& cullBox)
{
	DrawCullBoxUU = cullBox;
}

FBox2D UGame_TileComponent_Mesh::GetDrawCullBox() const
{
	return DrawCullBoxUU;
}

void UGame_TileComponent_Mesh::SetDrawDistanceDirty()
{
	bDrawDistanceDirty = true;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

AVH_GlobeReferenceActor* UGame_TileComponent_Mesh::GetGlobeReference() const
{
	if (AGame_VirtualObjective* activeVO = GetVirtualObjective())
	{
		return activeVO->GetGlobeReference();
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_TileComponent_Mesh::GetGlobeReference | globeRef is nullptr"));
	return nullptr;
}

void UGame_TileComponent_Mesh::ApplyDrawDistance()
{
	// todo ohg | no longer needed | remove
	bDrawDistanceDirty = false;

	{
		FScopeLock scopeLock(TrianglesCritSection);
		TrianglesInRange.Empty();
		TrianglesInRange.Append(Triangles);
	}

	SetComponentStatus(EComponentStatus::HelperThreadFinished);
}

bool UGame_TileComponent_Mesh::IsSafeToExecute()
{
	if (!IsValidLowLevelFast() ||
		HasAnyFlags(RF_BeginDestroyed) ||
		GetClass() == nullptr ||
		VerticesCritSection == nullptr ||
		TrianglesCritSection == nullptr ||
		UVsCritSection == nullptr)
	{
		return false;
	}

	return true;
}
