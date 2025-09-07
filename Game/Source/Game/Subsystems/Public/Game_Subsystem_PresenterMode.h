#pragma once

// Parent Includes
#include "Subsystems/WorldSubsystem.h"

// Generated Includes
#include "Game_Subsystem_PresenterMode.generated.h"

class APlayerState;
class UUserWidget;
class UGame_UserWidget_Popup;
class AActor;
class UGame_Subsystem_PresenterMode_Settings;

UCLASS()
class GAME_API UGame_Subsystem_PresenterMode : public UWorldSubsystem
{
	GENERATED_BODY()
	

	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	TSubclassOf<UGame_UserWidget_Popup> PopupMenuClass;

	TSubclassOf<UUserWidget> DisplayWindowClass;

	TSubclassOf<AActor> CaptureActorClass;

	UPROPERTY()
	APlayerState* CurrentPresenter;

	UPROPERTY()
	AActor* CaptureActor;


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
	// --- Inherited
	// ---------------------------------

	virtual void Initialize(FSubsystemCollectionBase& collection) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void HandlePresentingUserChanged(APlayerState* presentingPlayerState);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void ApplySettings(const UGame_Subsystem_PresenterMode_Settings* settings);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandlePresenterPopupResponse(UGame_UserWidget_Popup* popupWidget, const FString& buttonText);


};
