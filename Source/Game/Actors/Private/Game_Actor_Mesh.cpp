// Required Includes
#include "Game_Actor_Mesh.h"
#include "Game.h"

// Engine Includes
#include "ProceduralMeshComponent.h"

// Game Includes
#include "Game_ImportedMeshComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Actor_Mesh::AGame_Actor_Mesh(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	ImportedMesh = CreateDefaultSubobject<UGame_ImportedMeshComponent>(TEXT("ImportedMesh"));
	SetRootComponent(ImportedMesh);

	ProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("ProceduralMesh"));
	ProceduralMesh->SetupAttachment(GetRootComponent());
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_Actor_Mesh::BuildMeshFromVerticesAndTriangles(const TArray<FVector>& vertices, const TArray<int32>& triangles, UMaterialInterface* material)
{
	ProceduralMesh->ClearAllMeshSections();
    
	ProceduralMesh->CreateMeshSection(0, vertices, triangles, TArray<FVector>(), TArray<FVector2D>(), TArray<FVector2D>(), TArray<FVector2D>(), TArray<FVector2D>(), TArray<FColor>(), TArray<FProcMeshTangent>(), false);

	ProceduralMesh->SetMaterial(0, material);
}
