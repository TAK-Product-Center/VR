#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// Generated Includes
#include "Game_Actor_3DTile.generated.h"

struct FVH_MeshImportOptions;
class AVH_GlobeReferenceActor;
class UGame_ImportedMeshComponent_3DTile;
class UMaterialInstance;

UCLASS()
class GAME_API AGame_Actor_3DTile : public AActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(EditAnywhere)
	bool bReverseVertOrder;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_ImportedMeshComponent_3DTile* ImportedMesh;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Actor_3DTile(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void LoadFromFile(const FString& fullPathToFile, const FVH_MeshImportOptions& importOptions);

	void SetMaterialOverride(UMaterialInstance* materialOverride);

	AVH_GlobeReferenceActor* GetGlobeReference() const;
};