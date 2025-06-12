#pragma once

// Parent Includes
#include "Engine/DeveloperSettings.h"

// Engine Includes
#include "Templates/SubclassOf.h"

// Generated Includes
#include "Game_Subsystem_Help_Settings.generated.h"

class UUserWidget;
class UGame_HelpVideo;

UCLASS(BlueprintType, Blueprintable, Config = Game)
class GAME_API UGame_Subsystem_Help_Settings : public UDeveloperSettings
{
	GENERATED_BODY()


	// --------------------
	// --- Variables
	// --------------------

public:
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	TSet<TSubclassOf<UGame_HelpVideo>> CoreHelpVideos;
};
