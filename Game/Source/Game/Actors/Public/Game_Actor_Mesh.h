#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// Generated Includes
#include "Game_Actor_Mesh.generated.h"

class UGame_ImportedMeshComponent;
class UProceduralMeshComponent;

UCLASS()
class GAME_API AGame_Actor_Mesh : public AActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_ImportedMeshComponent* ImportedMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UProceduralMeshComponent* ProceduralMesh;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Actor_Mesh(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void BuildMeshFromVerticesAndTriangles(const TArray<FVector>& vertices, const TArray<int32>& triangles, UMaterialInterface* material);
};