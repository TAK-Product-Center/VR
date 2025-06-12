#pragma once

#include "GameFramework/Actor.h"

#include "Game_WorldActor.generated.h"

class AVH_GlobeReferenceActor;

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_WorldActor : public AActor
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_WorldActor(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USceneComponent* Root;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void SetActorHiddenInGame(bool bNewHidden) override;

	virtual void SetActorScale3D(FVector newScale3D) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleSetActorHiddenInGame(bool bNewHidden);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleSetActorScale3D(const FVector& newScale3D);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	virtual AVH_GlobeReferenceActor* GetGlobeReference() const;
};
