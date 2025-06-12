#pragma once

// Parent Includes
#include "Game_ImportedMeshComponent.h"

// Generated Includes
#include "Game_ImportedMeshComponent_VectorTile.generated.h"

class AGame_VirtualObjective;

UCLASS()
class GAME_API UGame_ImportedMeshComponent_VectorTile : public UGame_ImportedMeshComponent
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


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:

	FVector2D HAEBounds;
	bool bValidHAEBounds;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:

	UGame_ImportedMeshComponent_VectorTile();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

private:

	virtual void UpdateBBFromBounds() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:

	bool GetHAEBounds(FVector2D& haeBounds) const;
};