// Required Includes
#include "Game_ImportedMeshComponent_VectorTile.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_MeshInfo.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_GlobeCoordConverter.h"
#include "VH_GlobeMathStatics.h"

// Game Includes
#include "Game_VirtualObjective.h"
#include "Game_PlayerController.h"
#include "Game_PlayerState.h"
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_ImportedMeshComponent_VectorTile::UGame_ImportedMeshComponent_VectorTile() :
	HAEBounds(FVector2D(9999999.0, -9999999.0))
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_ImportedMeshComponent_VectorTile::UpdateBBFromBounds()
{
	// purposefully not allowing
}


// ---------------------------------
// --- API
// ---------------------------------

bool UGame_ImportedMeshComponent_VectorTile::GetHAEBounds(FVector2D& haeBounds) const
{
	if (bValidHAEBounds)
	{
		haeBounds = HAEBounds;
	}

	return bValidHAEBounds;
}
