#pragma once

// Parent Includes
#include "GameFramework/Actor.h"
#include "Interface_COTReceiver.h"

// Generated Includes
#include "Game_DrawContainer.generated.h"

class AGame_VirtualObjective;

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_DrawContainer : public AActor, public IInterface_COTReceiver
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_DrawContainer();

	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void SetActorScale3D(FVector newScale3D) override;

	virtual void SetActorHiddenInGame(bool bNewHidden) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure)
	UGame_COTComponent_Draw* GetDrawComponent() const;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetInEditMode(bool InEditMode);

	UFUNCTION(BlueprintNativeEvent)
	AGame_VirtualObjective* GetVirtualObjective() const;
};
