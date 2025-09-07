#pragma once

// Parent Includes
#include "Game_ImportedMeshComponent.h"

// Generated Includes
#include "Game_ImportedMeshComponent_3DTile.generated.h"

class AGame_VirtualObjective;

UCLASS()
class GAME_API UGame_ImportedMeshComponent_3DTile : public UGame_ImportedMeshComponent
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DELEGATE_TwoParams(FHAEBoundsUpdated, const FVector2D&, AActor*);

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	FHAEBoundsUpdated OnHAEBoundsUpdated;

private:
	FTransform RelativeTransform;

	FVector2D HAEBounds;
	bool bValidHAEBounds;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_ImportedMeshComponent_3DTile();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

protected:
	virtual void PostAddNodesToAsyncData() override;

private:
	virtual void UpdateBBFromBounds() override;

	virtual void AddNodeToAsyncData(FVH_MeshImportMeshNode& meshNode, USceneComponent* parentComponent) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	bool GetHAEBounds(FVector2D& haeBounds) const;
};