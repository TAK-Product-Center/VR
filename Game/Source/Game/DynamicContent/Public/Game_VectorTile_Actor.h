#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// Generated Includes
#include "Game_VectorTile_Actor.generated.h"

struct FVH_MeshImportOptions;
class AVH_GlobeReferenceActor;
class UGame_ImportedMeshComponent_VectorTile;
class UMaterialInstance;

UCLASS()
class GAME_API AGame_VectorTile_Actor : public AActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:

	UPROPERTY(EditAnywhere)
	bool bReverseVertOrder;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_ImportedMeshComponent_VectorTile* ImportedMesh;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_VectorTile_Actor(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:

	void SetMaterialOverride(UMaterialInstance* materialOverride);

	AVH_GlobeReferenceActor* GetGlobeReference() const;
};