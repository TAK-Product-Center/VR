// Required Includes
#include "Game_UserWidget_GoTo.h"
#include "Game.h"

// Game Includes
#include "Game_Subsystem_Core.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_GoTo::UGame_UserWidget_GoTo(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	NumberOfRecentCoordinates(10)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------
	
void UGame_UserWidget_GoTo::NativeConstruct()
{
	Super::NativeConstruct();

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		FString coordinates = gameSettings->GetSettingString(TEXT("RecentCoordinates"));

		TArray<FString> coordinatesString;
		coordinates.ParseIntoArray(coordinatesString, TEXT("|"));

		for (const FString& coordinateString : coordinatesString)
		{
			FGeodeticCoord3D coordinate;
			if (coordinate.FromString(coordinateString))
			{
				RecentCoordinates.Add(coordinate);
			}
		}

		ReceiveRecentCoordinates(RecentCoordinates);
	}
}
	
// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_GoTo::AddRecentCoordinate(const FGeodeticCoord3D& coordinate)
{
	for (int32 i = 0; i < RecentCoordinates.Num(); i++)
	{
		if (coordinate == RecentCoordinates[i])
		{
			RecentCoordinates.RemoveAt(i, 1);
			
			break;
		}
	}

	RecentCoordinates.Insert(coordinate, 0);

	if (RecentCoordinates.Num() > NumberOfRecentCoordinates)
	{
		RecentCoordinates.SetNum(NumberOfRecentCoordinates);
	}

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		FString coordinateString = TEXT("");
		for (const FGeodeticCoord3D& recentCoordinate : RecentCoordinates)
		{
			coordinateString = FString::Printf(TEXT("%s"), *recentCoordinate.ToString());
		}

		gameSettings->StoreSettingString(TEXT("RecentCoordinates"), coordinateString);
	}

	ReceiveRecentCoordinates(RecentCoordinates);
}

void UGame_UserWidget_GoTo::ClearRecentCoordinates()
{
	RecentCoordinates.Empty();

	ReceiveRecentCoordinates(RecentCoordinates);

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingString(TEXT("RecentCoordinates"), TEXT(""));
	}
}