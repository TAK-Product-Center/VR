#pragma once

// Parent Includes
#include "Subsystems/WorldSubsystem.h"

// Generated Includes
#include "Game_Subsystem_PresenterMode.generated.h"

class APlayerState;

UCLASS()
class GAME_API UGame_Subsystem_PresenterMode : public UWorldSubsystem
{
	GENERATED_BODY()
	

	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	UPROPERTY()
	APlayerState* CurrentPresenter;

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_Subsystem_PresenterMode();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UGame_Subsystem_PresenterMode* Get();
	

	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void HandlePresentingUserChanged(APlayerState* presentingPlayerState);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	UFUNCTION()
	void HandlePresenterPopupResponse(UGame_UserWidget_Popup* popupWidget, const FString& buttonText);
};
