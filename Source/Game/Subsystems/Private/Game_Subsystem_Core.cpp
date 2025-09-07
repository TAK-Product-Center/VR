// Required Includes
#include "Game_Subsystem_Core.h"
#include "Game.h"

// Engine Includes
#include "Engine/GameInstance.h"
#include "UObject/UObjectGlobals.h"
#include "UObject/Package.h"
#include "Misc/Paths.h"
#include "Engine/World.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_Database_ToolVisual.h"
#include "Game_Subsystem_Core_Settings.h"

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_Subsystem_Core* UGame_Subsystem_Core::Get()
{
	if (UWorld* world = UDeveloper_Statics::GetVHWorld())
	{
		if (UGameInstance* gameInstance = world->GetGameInstance())
		{
			return gameInstance->GetSubsystem<UGame_Subsystem_Core>();
		}
	}

	return nullptr;
}

UDatabase_PersistentSettings_Spatialite* UGame_Subsystem_Core::GetGameSettings()
{
	if (UGame_Subsystem_Core* subsystem = UGame_Subsystem_Core::Get())
	{
		return subsystem->GetGameSettingsDirect();
	}

	return nullptr;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_Subsystem_Core::Initialize(FSubsystemCollectionBase& collection)
{
	Super::Initialize(collection);

	if (const UGame_Subsystem_Core_Settings* settings = GetDefault<UGame_Subsystem_Core_Settings>())
	{
		ApplySettings(settings);
	}

	EntityDB = NewObject<UGame_EntityDB>(GetTransientPackage(), EntityDBClass);
}

// ---------------------------------
// --- API
// ---------------------------------

double UGame_Subsystem_Core::GetCallsignShowDistanceMeters() const
{
	return CallsignShowDistanceMeters;
}

UGame_Database_ToolVisual* UGame_Subsystem_Core::GetToolVisualDatabase()
{
	if (ToolVisualDatabase == nullptr)
	{
		ToolVisualDatabase = NewObject<UGame_Database_ToolVisual>(GetTransientPackage(), ToolVisualDatabaseClass);
		ToolVisualDatabase->Connect();
	}

	return ToolVisualDatabase;
}

UDatabase_PersistentSettings_Spatialite* UGame_Subsystem_Core::GetGameSettingsDirect()
{
	if (GameSettings == nullptr)
	{
		GameSettings = NewObject<UDatabase_PersistentSettings_Spatialite>();

		FString fullPathToDatabase = FPaths::Combine(UDeveloper_Statics::GetUserAppDataPath(), TEXT("VRTAK"), TEXT("Databases"), TEXT("SettingsDB.sqlite"));
		GameSettings->Connect(fullPathToDatabase);
	}

	return GameSettings;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_Subsystem_Core::ApplySettings(const UGame_Subsystem_Core_Settings* settings)
{
	ToolVisualDatabaseClass = settings->ToolVisualDatabaseClass;
	EntityDBClass = settings->EntityDBClass;
	CallsignShowDistanceMeters = settings->CallsignShowDistanceMeters;
}
