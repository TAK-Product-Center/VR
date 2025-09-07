#pragma once

// Parent Includes
#include "Subsystems/GameInstanceSubsystem.h"

// Game Includes
#include "Game_EntityDB.h"

// Generated Includes
#include "Game_Subsystem_Core.generated.h"

class UGame_Subsystem_Core_Settings;
class UDatabase_PersistentSettings_Spatialite;
class UGame_Database_ToolVisual;

UCLASS()
class GAME_API UGame_Subsystem_Core : public UGameInstanceSubsystem
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadOnly)
	UGame_EntityDB* EntityDB;

private:
	UPROPERTY()
	UDatabase_PersistentSettings_Spatialite* GameSettings;

	TSubclassOf<UGame_Database_ToolVisual> ToolVisualDatabaseClass;

	TSubclassOf<UGame_EntityDB> EntityDBClass;

	UPROPERTY()
	UGame_Database_ToolVisual* ToolVisualDatabase;

	double CallsignShowDistanceMeters;


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UGame_Subsystem_Core* Get();

	UFUNCTION(BlueprintPure)
	static UDatabase_PersistentSettings_Spatialite* GetGameSettings();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	void Initialize(FSubsystemCollectionBase& collection) override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure)
	double GetCallsignShowDistanceMeters() const;

	UFUNCTION(BlueprintPure)
	UGame_Database_ToolVisual* GetToolVisualDatabase();

	UDatabase_PersistentSettings_Spatialite* GetGameSettingsDirect();


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void ApplySettings(const UGame_Subsystem_Core_Settings* settings);
};
