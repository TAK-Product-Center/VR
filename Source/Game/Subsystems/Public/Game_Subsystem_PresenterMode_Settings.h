#pragma once

// Parent Includes
#include "Engine/DeveloperSettings.h"

// Game Includes
#include "Game_UserWidget_Popup.h"

// Generated Includes
#include "Game_Subsystem_PresenterMode_Settings.generated.h"

class UGame_PresentationMode_ReplicatedWindowComponent;

UCLASS(BlueprintType, Blueprintable, Config = Game)
class GAME_API UGame_Subsystem_PresenterMode_Settings : public UDeveloperSettings
{
	GENERATED_BODY()


	// --------------------
	// --- Variables
	// --------------------

public:
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGame_UserWidget_Popup> PopupMenuClass;

	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UUserWidget> DisplayWindowClass;

	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> CaptureActorClass;
};
