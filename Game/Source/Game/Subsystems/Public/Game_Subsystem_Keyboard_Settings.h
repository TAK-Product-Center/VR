#pragma once

// Parent Includes
#include "Engine/DeveloperSettings.h"

// Engine Includes
#include "Templates/SubclassOf.h"
#include "Engine/EngineTypes.h"

// Generated Includes
#include "Game_Subsystem_Keyboard_Settings.generated.h"

class AActor;

UCLASS(BlueprintType, Blueprintable, Config = Game)
class GAME_API UGame_Subsystem_Keyboard_Settings : public UDeveloperSettings
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Config)
	TMap<FString, TSubclassOf<AActor>> KeyboardClassMap;
};
