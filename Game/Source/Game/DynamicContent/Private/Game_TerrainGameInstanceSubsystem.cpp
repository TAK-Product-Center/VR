// Required Includes
#include "Game_TerrainGameInstanceSubsystem.h"
#include "Game.h"

// Engine Includes
#include "Misc/Paths.h"

// Game Includes
#include "Database_Spatialite.h"

// ---------------------------------
// --- API
// ---------------------------------

void UGame_TerrainGameInstanceSubsystem::Disconnect(UDatabase_Spatialite* database)
{
	database->Disconnect();

	FScopeLock scopeLock(&ImageryDBCritSection);

	FString toRemove = TEXT("");
	for (const TPair<FString, UDatabase_Spatialite*>& entry : ImageryDBs)
	{
		if (entry.Value == database)
		{
			toRemove = entry.Key;

			break;
		}
	}

	if (!toRemove.IsEmpty())
	{
		ImageryDBs.Remove(toRemove);
	}
}

UDatabase_Spatialite* UGame_TerrainGameInstanceSubsystem::GetImageryDB(const FString& fullPathToDB)
{
	FScopeLock scopeLock(&ImageryDBCritSection);

	if (UDatabase_Spatialite** imageryDB = ImageryDBs.Find(fullPathToDB))
	{
		return *imageryDB;
	}
	else
	{
		FGCScopeGuard garbageCollectionGuard;

		UDatabase_Spatialite* db = NewObject<UDatabase_Spatialite>();

		bool bCreate = true;
		if (FPaths::FileExists(fullPathToDB))
		{
			bCreate = !db->OpenDatabase(fullPathToDB, false);
		}

		if (bCreate)
		{
			db->OpenDatabase(fullPathToDB, true);
			
			db->SyncQuery(TEXT("CREATE TABLE ATAK_catalog (key INTEGER PRIMARY KEY, access INTEGER, expiration INTEGER, size INTEGER)"));

			db->SyncQuery(TEXT("CREATE TABLE ATAK_metadata (key TEXT, value TEXT)"));

			db->SyncQuery(TEXT("CREATE TABLE tiles (key INTEGER PRIMARY KEY, provider TEXT, tile BLOB)"));
		}

		ImageryDBs.Add(fullPathToDB, db);

		return db;
	}
}