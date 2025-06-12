// Required Includes
#include "Game_VectorTile_Actor.h"
#include "Game.h"
 
// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"

// Game Includes
#include "Game_ImportedMeshComponent_VectorTile.h"
#include "Game_PlayerController.h"
#include "Game_VirtualObjective.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_VectorTile_Actor::AGame_VectorTile_Actor(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	ImportedMesh = CreateDefaultSubobject<UGame_ImportedMeshComponent_VectorTile>(TEXT("ImportedMesh"));
	SetRootComponent(ImportedMesh);
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_VectorTile_Actor::SetMaterialOverride(UMaterialInstance* materialOverride)
{
	ImportedMesh->MaterialOverride = materialOverride;
}

AVH_GlobeReferenceActor* AGame_VectorTile_Actor::GetGlobeReference() const
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		return virtualObjective->GetGlobeReference();
	}

	return nullptr;if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		return virtualObjective->GetGlobeReference();
	}

	return nullptr;if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		return virtualObjective->GetGlobeReference();
	}

	return nullptr;if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		return virtualObjective->GetGlobeReference();
	}

	return nullptr;if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		return virtualObjective->GetGlobeReference();
	}

	return nullptr;
}