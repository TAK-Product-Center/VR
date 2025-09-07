#pragma once

// Parent Includes
#include "Engine/DeveloperSettings.h"

// Engine Includes
#include "Templates/SubclassOf.h"

// Generated Includes
#include "Game_Subsystem_Core_Settings.generated.h"

class UUserWidget;
class UGame_Database_ToolVisual;
class UGame_EntityDB;

UCLASS(BlueprintType, Blueprintable, Config = Game)
class GAME_API UGame_Subsystem_Core_Settings : public UDeveloperSettings
{
	GENERATED_BODY()


	// --------------------
	// --- Variables
	// --------------------

public:
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGame_Database_ToolVisual> ToolVisualDatabaseClass;

	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGame_EntityDB> EntityDBClass;

	/// @brief callsigns always show at this distance and beyond; shorter than this, callsigns only show on mouseover
	UPROPERTY(Config, BlueprintReadWrite, EditAnywhere)
	double CallsignShowDistanceMeters;
};