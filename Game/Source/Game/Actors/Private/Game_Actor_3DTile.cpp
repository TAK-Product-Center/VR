// Required Includes
#include "Game_Actor_3DTile.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"

// Game Includes
#include "Game_ImportedMeshComponent_3DTile.h"
#include "Game_PlayerController.h"
#include "Game_VirtualObjective.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Actor_3DTile::AGame_Actor_3DTile(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	ImportedMesh = CreateDefaultSubobject<UGame_ImportedMeshComponent_3DTile>(TEXT("UGame_ImportedMeshComponent_3DTile"));

	SetRootComponent(ImportedMesh);
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_Actor_3DTile::LoadFromFile(const FString& fullPathToFile, const FVH_MeshImportOptions& importOptions)
{
	ImportedMesh->ImportOptions = importOptions;

	ImportedMesh->LoadFromFile(fullPathToFile);
}

void AGame_Actor_3DTile::SetMaterialOverride(UMaterialInstance* materialOverride)
{
	ImportedMesh->MaterialOverride = materialOverride;
}

AVH_GlobeReferenceActor* AGame_Actor_3DTile::GetGlobeReference() const
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		return virtualObjective->GetGlobeReference();
	}

	return nullptr;
}