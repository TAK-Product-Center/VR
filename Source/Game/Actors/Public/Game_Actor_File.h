#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// Generated Includes
#include "Game_Actor_File.generated.h"

struct FVH_MeshImportOptions;
struct FGeodeticCoord3D;
class AVH_GlobeReferenceActor;
class UGame_ImportedMeshComponent;
class UGame_AdjustableModelImportComponent;
class UVH_MeshInfo;
class UMaterialInstance;

UCLASS()
class GAME_API AGame_Actor_File : public AActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_AdjustableModelImportComponent* AdjustableModelImportComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_ImportedMeshComponent* ImportedMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> LowLODActorClass;

private:
	UPROPERTY()
	AActor* LowLODActor;

	bool bLoadedOnce;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Actor_File(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void LoadFromFile(const FString& fullPathToFile, const FVH_MeshImportOptions& importOptions);

	void SetMaterialOverride(UMaterialInstance* materialOverride);

	AVH_GlobeReferenceActor* GetGlobeReference() const;

	bool GetModelLocationWithoutTag(FGeodeticCoord3D& coordinate);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleImportedMeshInfo(UGame_ImportedMeshComponent* importedMeshComponent, UVH_MeshInfo* meshInfo);

	UFUNCTION()
	void PeriodicCheckLOD();
};