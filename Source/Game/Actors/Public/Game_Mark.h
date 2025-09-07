#pragma once

// Parent Includes
#include "Game_WorldInteractableActor.h"

// Generated Includes
#include "Game_Mark.generated.h"

class UStaticMeshComponent;

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_Mark : public AGame_WorldInteractableActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components")
	UStaticMeshComponent* PlaneStaticMeshComponent;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Mark(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void SetActorHiddenInGame(bool bNewHidden) override;
};
