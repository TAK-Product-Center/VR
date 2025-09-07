#pragma once

// Parent Includes
#include "GameFramework/Actor.h"

// Generated includes
#include "Game_SnapLocation.generated.h"

UCLASS(Blueprintable, BlueprintType)
class AGame_SnapLocation : public AActor
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Constructor
	// ---------------------------------

public:
	AGame_SnapLocation();


	// ---------------------------------
	// --- Variables
	// ---------------------------------

protected:
	AActor* CurrentHeldActor;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	 * Checks if the current actor exists. Returns false if null
	 */
	UFUNCTION(BlueprintPure)
	bool DoesCurrentActorExist() const;

	UFUNCTION(BlueprintCallable)
	void SetCurrentHeldActor(AActor* newActor);

	UFUNCTION(BlueprintPure)
	AActor* GetCurrentHeldActor() const;
};

