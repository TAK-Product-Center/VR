#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_ListEntry_Bloodhound_Player.generated.h"

class AGame_PlayerState;

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_ListEntry_Bloodhound_Player : public UUserWidget
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	UPROPERTY()
	AGame_PlayerState* PlayerState;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void SetPlayerState(APlayerState* playerStateArg);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetCallsign(const FString& callsign);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetCoordinate(const FString& coordinateString);

	
	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void UpdateUI();
};
