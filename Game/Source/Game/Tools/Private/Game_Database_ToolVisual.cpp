// Required Includes
#include "Game_Database_ToolVisual.h"
#include "Game.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "VH_COTManager.h"

// Game Includes
#include "Game_Statics.h"
#include "Game_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_Database_ToolVisual::UGame_Database_ToolVisual()
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_Database_ToolVisual* UGame_Database_ToolVisual::Get()
{
	if (UGame_Subsystem_Core* subsystem = UGame_Subsystem_Core::Get())
	{
		return subsystem->GetToolVisualDatabase();
	}

	return nullptr;
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_Database_ToolVisual::Connect()
{
	if (OpenDatabase(GetFullPathToDatabase(), true))
	{
		// create tables if necessary
		FString query = TEXT("create table if not exists configurations (configurationID string not null primary key, ");
		query += TEXT("mesh string not null, ");
		query += TEXT("meshScale string not null, ");
		query += TEXT("beamOffset string not null, ");
		query += TEXT("beamRotation string not null, ");
		query += TEXT("beamScale string not null, ");
		query += TEXT("defaultBeamColor string not null, ");
		query += TEXT("vrKeyboardBeamColor string not null, ");
		query += TEXT("transformGizmoBeamColor string not null, ");
		query += TEXT("uiBeamColor string not null, ");
		query += TEXT("interactionBeamColor string not null, ");
		query += TEXT("contextMenuBeamColor string not null, ");
		query += TEXT("current int null)");
		
		SyncQuery(query);

		// populate current configuration if empty
		query = TEXT("select * from configurations");

		SpatialiteResults results;
		SyncQuery(query, results);

		if (results.Num() == 0)
		{
			if (UVH_COTManager* cotManager = UVH_COTManager::Get())
			{
				TMap<FName, FLinearColor> groupColors = cotManager->GetGroupColors();

				auto getColor = [groupColors](const FName& colorID)
				{
					if (const FLinearColor* colorPtr = groupColors.Find(colorID))
					{
						return *colorPtr;
					}

					return FLinearColor::Black;
				};

				TMap<FString, FString> keyValues;
				keyValues.Add(TEXT("configurationID"), TEXT("default"));
				keyValues.Add(TEXT("mesh"), TEXT("Default"));
				keyValues.Add(TEXT("meshScale"), FVector(1, 1, 1).ToString());
				keyValues.Add(TEXT("beamOffset"), FVector(0, 0, 0).ToString());
				keyValues.Add(TEXT("beamRotation"), FRotator(-30, 0, 0).ToString());
				keyValues.Add(TEXT("beamScale"), FVector(0, 0.005, 0.005).ToString());
				keyValues.Add(TEXT("defaultBeamColor"), getColor(TEXT("Green")).ToString());
				keyValues.Add(TEXT("vrKeyboardBeamColor"), getColor(TEXT("Blue")).ToString());
				keyValues.Add(TEXT("transformGizmoBeamColor"), getColor(TEXT("Blue")).ToString());
				keyValues.Add(TEXT("uiBeamColor"), getColor(TEXT("Orange")).ToString());
				keyValues.Add(TEXT("interactionBeamColor"), getColor(TEXT("Blue")).ToString());
				keyValues.Add(TEXT("contextMenuBeamColor"), getColor(TEXT("Orange")).ToString());

				SaveConfiguration(keyValues);

				SetCurrentConfiguration(TEXT("default"));
			}
			else
			{
				UE_LOG(Game, Warning, TEXT("-- UGame_Database_ToolVisual::Connect | COTManager is nullptr | aborting"));
			}
		}
		else
		{
			// update legacy databases
			FString updateQuery = FString::Printf(TEXT("update configurations set beamRotation = \"%s\" where configurationID = \"default\""), *FRotator(-30, 0, 0).ToString());

			SyncQuery(updateQuery);
		}
	}
}

FString UGame_Database_ToolVisual::GetCurrentConfiguration() const
{
	FString query = TEXT("select * from configurations where current = 1");

	SpatialiteResults results;
	SyncQuery(query, results);

	if (results.Num() > 0)
	{
		return UDatabase_Spatialite::GetString(TEXT("configurationID"), results[0]);
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_Database_ToolVisual::GetCurrentConfiguration | no current configuration in database | returning default"));

	return TEXT("default");
}

FString UGame_Database_ToolVisual::GetFullPathToDatabase() const
{
	return FPaths::Combine(UGame_Statics::GetVTAKUserAppDataPath(), TEXT("Databases"), TEXT("BeamVisualDB.sqlite"));
}

TSet<FString> UGame_Database_ToolVisual::GetConfigurationIDs() const
{
	TSet<FString> configurationIDs;

	SpatialiteResults results;
	SyncQuery(TEXT("select configurationID from configurations"), results);

	for (const SpatialiteResult& result : results)
	{
		configurationIDs.Add(UDatabase_Spatialite::GetString(TEXT("configurationID"), result));
	}


	return configurationIDs;
}

bool UGame_Database_ToolVisual::LoadConfiguration(const FString& configurationID, FSpatialiteResult_BP& result)
{
	return LoadConfiguration(configurationID, result.Result);
}

bool UGame_Database_ToolVisual::LoadConfiguration(const FString& configurationID, SpatialiteResult& result)
{
	FString query = FString::Printf(TEXT("select * from configurations where configurationID = \"%s\""), *configurationID);
	
	SpatialiteResults results;
	SyncQuery(query, results);

	if (results.Num() > 0)
	{
		result = results[0];

		SetCurrentConfiguration(configurationID);

		return true;
	}

	return false;
}

void UGame_Database_ToolVisual::SaveConfiguration(const TMap<FString, FString>& keyValues)
{
	FString configurationID = keyValues[TEXT("configurationID")];

	int32 current = GetCurrentConfiguration().Equals(configurationID) ? 1 : 0;

	DeleteConfiguration(configurationID);

	FString query = TEXT("insert into configurations (configurationID, mesh, meshScale, beamOffset, beamRotation, beamScale, defaultBeamColor, vrKeyboardBeamColor, transformGizmoBeamColor, uiBeamColor, interactionBeamColor, contextMenuBeamColor, current) values (");
	query += FString::Printf(TEXT("\"%s\", "), *keyValues[TEXT("configurationID")]);
	query += FString::Printf(TEXT("\"%s\", "), *keyValues[TEXT("mesh")]);
	query += FString::Printf(TEXT("\"%s\", "), *keyValues[TEXT("meshScale")]);
	query += FString::Printf(TEXT("\"%s\", "), *keyValues[TEXT("beamOffset")]);
	query += FString::Printf(TEXT("\"%s\", "), *keyValues[TEXT("beamRotation")]);
	query += FString::Printf(TEXT("\"%s\", "), *keyValues[TEXT("beamScale")]);
	query += FString::Printf(TEXT("\"%s\", "), *keyValues[TEXT("defaultBeamColor")]);
	query += FString::Printf(TEXT("\"%s\", "), *keyValues[TEXT("vrKeyboardBeamColor")]);
	query += FString::Printf(TEXT("\"%s\", "), *keyValues[TEXT("transformGizmoBeamColor")]);
	query += FString::Printf(TEXT("\"%s\", "), *keyValues[TEXT("uiBeamColor")]);
	query += FString::Printf(TEXT("\"%s\", "), *keyValues[TEXT("interactionBeamColor")]);
	query += FString::Printf(TEXT("\"%s\", "), *keyValues[TEXT("contextMenuBeamColor")]);
	query += FString::Printf(TEXT("%d)"), current);

	SyncQuery(query);
}

void UGame_Database_ToolVisual::DeleteConfiguration(const FString& configurationID)
{
	FString query = FString::Printf(TEXT("delete from configurations where configurationID = \"%s\""), *configurationID);
	SyncQuery(query);
}

void UGame_Database_ToolVisual::SetCurrentConfiguration(const FString& configurationID)
{
	FString query = TEXT("update configurations set current = 0");
	SyncQuery(query);

	query = FString::Printf(TEXT("update configurations set current = 1 where configurationID = \"%s\""), *configurationID);
	SyncQuery(query);
}