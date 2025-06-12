// Required Includes
#include "Game_UserWidget_TerrainSettings.h"
#include "Game.h"

// Engine Includes
#include "Components/CheckBox.h"

// VH Plugin Includes
#include "VH_TextInput.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_TileManager.h"
#include "Game_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_TerrainSettings::UGame_UserWidget_TerrainSettings(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_UserWidget_TerrainSettings::NativeConstruct()
{
	Super::NativeConstruct();

	InitWidgetsFromDatabase();

	BindDelegates();
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_TerrainSettings::SetImageryDirectory(const FString& imageryDirectory)
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingString(TEXT("ImageryDirectory"), imageryDirectory);
	}
}

void UGame_UserWidget_TerrainSettings::SetOfflineImageryDirectory(const FString& offlineImageryDirectory)
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingString(TEXT("OfflineImageryDirectory"), offlineImageryDirectory);
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_UserWidget_TerrainSettings::SetStartingLocation(const FGeodeticCoord3D& coordinate)
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingString(TEXT("InitialCoordinate"), coordinate.ToString());
	}
}

void UGame_UserWidget_TerrainSettings::ResetStartingLocation()
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		FGeodeticCoord3D coordinate;
		coordinate.FromString(gameSettings->GetDefaultSettingString(TEXT("InitialCoordinate")));

		SetStartingLocation(coordinate);

		gameSettings->StoreSettingBool(TEXT("bInitialInTOC"), true);
	}
}

void UGame_UserWidget_TerrainSettings::BindDelegates()
{
	EnableStreamingCheckBox->OnCheckStateChanged.AddUniqueDynamic(this, &UGame_UserWidget_TerrainSettings::HandleEnableStreamingCheckStateChange);

	MinImageryZoomLevel->OnEntrySubmittedCallback.AddUniqueDynamic(this, &UGame_UserWidget_TerrainSettings::HandleMinImageryEdited);
	MaxImageryZoomLevel->OnEntrySubmittedCallback.AddUniqueDynamic(this, &UGame_UserWidget_TerrainSettings::HandleMaxImageryEdited);
	MinHeightmapZoomLevel->OnEntrySubmittedCallback.AddUniqueDynamic(this, &UGame_UserWidget_TerrainSettings::HandleMinHeightmapEdited);
	MaxHeightmapZoomLevel->OnEntrySubmittedCallback.AddUniqueDynamic(this, &UGame_UserWidget_TerrainSettings::HandleMaxHeightmapEdited);
}

void UGame_UserWidget_TerrainSettings::InitWidgetsFromDatabase()
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		bool bShouldStreamTiles = gameSettings->GetSettingBool(TEXT("ShouldStreamTiles"));

		EnableStreamingCheckBox->SetIsChecked(bShouldStreamTiles);

		MinImageryZoomLevel->SetText(FText::FromString(FString::Printf(TEXT("%d"), gameSettings->GetSettingInt(TEXT("MinImageryZoomLevel")))), true);
		MaxImageryZoomLevel->SetText(FText::FromString(FString::Printf(TEXT("%d"), gameSettings->GetSettingInt(TEXT("MaxImageryZoomLevel")))), true);
		MinHeightmapZoomLevel->SetText(FText::FromString(FString::Printf(TEXT("%d"), gameSettings->GetSettingInt(TEXT("MinHeightmapZoomLevel")))), true);
		MaxHeightmapZoomLevel->SetText(FText::FromString(FString::Printf(TEXT("%d"), gameSettings->GetSettingInt(TEXT("MaxHeightmapZoomLevel")))), true);

		ReceiveImageryDirectoryUpdate(gameSettings->GetSettingString(TEXT("ImageryDirectory")));

		ReceiveOfflineImageryDirectoryUpdate(gameSettings->GetSettingString(TEXT("OfflineImageryDirectory")));

		gameSettings->OnStringSettingStored.AddUniqueDynamic(this, &UGame_UserWidget_TerrainSettings::HandleStringSettingChanged);
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_UserWidget_TerrainSettings::HandleMinImageryEdited(FString text)
{
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->SetMinImageryZoomLevel(FCString::Atoi(*text));
	}
}

void UGame_UserWidget_TerrainSettings::HandleMaxImageryEdited(FString text)
{
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->SetMaxImageryZoomLevel(FCString::Atoi(*text));
	}
}

void UGame_UserWidget_TerrainSettings::HandleMinHeightmapEdited(FString text)
{
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->SetMinHeightmapZoomLevel(FCString::Atoi(*text));
	}
}

void UGame_UserWidget_TerrainSettings::HandleMaxHeightmapEdited(FString text)
{
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->SetMaxHeightmapZoomLevel(FCString::Atoi(*text));
	}
}

void UGame_UserWidget_TerrainSettings::HandleEnableStreamingCheckStateChange(bool bIsChecked)
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingBool(TEXT("ShouldStreamTiles"), bIsChecked);
	}

	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->SetEnabled(bIsChecked);
	}
}

void UGame_UserWidget_TerrainSettings::HandleStringSettingChanged(const FString& settingName, const FString& value)
{
	if (settingName.Equals(TEXT("ImageryDirectory")))
	{
		ReceiveImageryDirectoryUpdate(value);
	}
	else if (settingName.Equals(TEXT("OfflineImageryDirectory")))
	{
		ReceiveOfflineImageryDirectoryUpdate(value);
	}
}
