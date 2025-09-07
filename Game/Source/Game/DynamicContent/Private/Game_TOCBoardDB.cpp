// Required Includes
#include "Game_TOCBoardDB.h"
#include "Game.h"

// Engine Includes
#include "Engine/World.h"
#include "Misc/Paths.h"

// VH Plugin Includes
#include "Developer_Statics.h"

// Game Includes
#include "Game_Statics.h"
#include "Game_TOCBoard.h"

UGame_TOCBoardDB* UGame_TOCBoardDB::GlobalInstance = nullptr;

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_TOCBoardDB::UGame_TOCBoardDB() :
	TOCBoardClass(AGame_TOCBoard::StaticClass())
{
    if (!HasAnyFlags(RF_ClassDefaultObject))
    {
        GlobalInstance = this;
    }
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_TOCBoardDB* UGame_TOCBoardDB::Get()
{
	return GlobalInstance;
}

// ---------------------------------
// --- API
// ---------------------------------

TArray<AGame_TOCBoard*> UGame_TOCBoardDB::GetTOCBoards() const
{
	return TOCBoards;
}

void UGame_TOCBoardDB::AddTOCBoard(AGame_TOCBoard* newTOCBoard)
{
	if (newTOCBoard != nullptr)
	{
		TOCBoards.Add(newTOCBoard);
	}
}

void UGame_TOCBoardDB::Connect()
{
	if (OpenDatabase(GetFullPathToDatabase(), true))
	{
		// create tables if necessary
		FString query = TEXT("create table if not exists configurationToBoard (configurationID string not null, boardID string not null)");
		SyncQuery(query);
		query = TEXT("create table if not exists boards (boardID string not null primary key, transform string not null, url string)");
		SyncQuery(query);
		query = TEXT("create table if not exists configurations (configurationID string not null primary key, current int null)");
		SyncQuery(query);

		// populate current configuration if empty
		query = TEXT("select * from configurations");

		SpatialiteResults results;
		SyncQuery(query, results);

		TArray<FTransform> transforms;
		transforms.Add(FTransform(FRotator(0, 103.956634, 0), FVector(259.298, -995.958, 180), FVector(1, 1, 1)));
		transforms.Add(FTransform(FRotator(0, 127.87976, 0), FVector(639.699, -809.660, 180), FVector(1, 1, 1)));
		transforms.Add(FTransform(FRotator(0, 152.893432, 0), FVector(903.567, -484.322, 180), FVector(1, 1, 1)));
		transforms.Add(FTransform(FRotator(0, -152.61486, 0), FVector(910.903, 481.646, 180), FVector(1, 1, 1)));
		transforms.Add(FTransform(FRotator(0, -128.246656, 0), FVector(637.558, 803.672, 180), FVector(1, 1, 1)));
		transforms.Add(FTransform(FRotator(0, -104.032174, 0), FVector(255.342, 986.457, 180), FVector(1, 1, 1)));

		if (results.Num() == 0)
		{
			query = TEXT("insert into configurations (configurationID, current) values (\"default\", 1)");
			SyncQuery(query);

			TArray<FString> urls;
			urls.Add("https://www.virtualheroes.com/capabilities#overview");
			urls.Add("https://www.twitter.com/VirtualHeroes");
			urls.Add("https://www.virtualheroes.com/cs-virtual-tactical-assault-kit/");
			urls.Add("https://www.ara.com/vtak-virtual-tactical-assault-kit/");
			urls.Add("https://www.twitter.com/ProductCtr");
			urls.Add("https://www.tak.gov");

			for (int32 i = 0; i < transforms.Num(); i++)
			{
				query = FString::Printf(TEXT("insert into boards (boardID, transform, url) values (\"default%d\", \"%s\", \"%s\")"), i, *transforms[i].ToString(), *urls[i]);
				SyncQuery(query);

				query = FString::Printf(TEXT("insert into configurationToBoard (configurationID, boardID) values (\"default\", \"default%d\")"), i);
				SyncQuery(query);
			}
		}
		else
		{
			// update scale from previous version
			for (int32 i = 0; i < transforms.Num(); i++)
			{
				query = FString::Printf(TEXT("update boards set transform = \"%s\" where boardID = \"default%d\""), *transforms[i].ToString(), i);
				SyncQuery(query);
			}
		}
	}
}

FString UGame_TOCBoardDB::GetCurrentConfiguration() const
{
	FString query = TEXT("select * from configurations where current = 1");

	SpatialiteResults results;
	SyncQuery(query, results);


	for (const SpatialiteResult& result : results)
	{
		int32 currentInt = UDatabase_Spatialite::GetInteger(TEXT("current"), result);
		if(currentInt != 0)
		{
			return UDatabase_Spatialite::GetString(TEXT("configurationID"), result);
		}
	}

	if (results.Num() > 0)
	{
		return UDatabase_Spatialite::GetString(TEXT("configurationID"), results[0]);
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_TOCBoardDB::GetCurrentConfiguration | no current configuration in database | returning default"));

	return TEXT("default");
}

FString UGame_TOCBoardDB::GetFullPathToDatabase() const
{
	return FPaths::Combine(UGame_Statics::GetVTAKUserAppDataPath(), TEXT("Databases"), TEXT("TOCBoardDB.sqlite"));
}

TSet<FString> UGame_TOCBoardDB::GetConfigurationIDs() const
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

void UGame_TOCBoardDB::LoadConfiguration(const FString& configurationID)
{
	FString configurationQuery = FString::Printf(TEXT("select * from configurations where configurationID = \"%s\""), *configurationID);
	SpatialiteResults configurationResults;
	SyncQuery(configurationQuery, configurationResults);

	if (configurationResults.Num() > 0)
	{
		// destroy existing TOCBoards
		for (AGame_TOCBoard* tocBoard : TOCBoards)
		{
			if (IsValid(tocBoard))
			{
				tocBoard->Destroy();
			}
		}
		TOCBoards.Empty();

		// query for configuration
		FString query = FString::Printf(TEXT("select boards.boardID, transform, url from boards inner join configurationToBoard on configurationToBoard.boardID = boards.boardID where configurationToBoard.configurationID = \"%s\""), *configurationID);

		SpatialiteResults results;
		SyncQuery(query, results);

		if (results.Num() > 0)
		{
			if (UWorld* world = UDeveloper_Statics::GetVHWorld())
			{
				// spawn new boards and populate from results
				for (const SpatialiteResult& result : results)
				{
					FActorSpawnParameters spawnParams;
					spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

					AGame_TOCBoard* tocBoard = world->SpawnActor<AGame_TOCBoard>(TOCBoardClass, spawnParams);
					tocBoard->SyncToResult(result);

					AddTOCBoard(tocBoard);
				}
			}
		}

		SetCurrentConfiguration(configurationID);

		OnConfigurationLoaded.Broadcast();
	}

}

void UGame_TOCBoardDB::SaveConfiguration(const FString& configurationID, const TArray<AGame_TOCBoard*>& tocBoards)
{
	DeleteConfiguration(configurationID, false);

	FString query;
	for (AGame_TOCBoard* tocBoard : tocBoards)
	{
		tocBoard->SetID(FGuid::NewGuid().ToString());

		query = FString::Printf(TEXT("insert into configurationToBoard (configurationID, boardID) values (\"%s\", \"%s\")"), *configurationID, *tocBoard->GetID());
		SyncQuery(query);

		query = FString::Printf(TEXT("insert into boards (boardID, transform, url) values (\"%s\", \"%s\", \"%s\")"), *tocBoard->GetID(), *tocBoard->GetActorTransform().ToString(), *tocBoard->ReceiveGetURL());
		SyncQuery(query);
	}

	query = FString::Printf(TEXT("insert into configurations (configurationID, current) values (\"%s\", 0)"), *configurationID);
	SyncQuery(query);

	SetCurrentConfiguration(configurationID);

	TOCBoards.Append(tocBoards);
}

void UGame_TOCBoardDB::DeleteConfiguration(const FString& configurationID, bool bDestroyBoards)
{
	if(GetCurrentConfiguration() == configurationID)
	{
		SetCurrentConfiguration("default");
	}

	FString query = FString::Printf(TEXT("select boards.boardID from boards inner join configurationToBoard on configurationToBoard.boardID = boards.boardID where configurationToBoard.configurationID = \"%s\""), *configurationID);
	
	SpatialiteResults results;
	SyncQuery(query, results);

	for (const SpatialiteResult& result : results)
	{
		query = FString::Printf(TEXT("delete from boards where boardID = \"%s\""), *UDatabase_Spatialite::GetString(TEXT("boardID"), result));
		SyncQuery(query);
	}

	query = FString::Printf(TEXT("delete from configurationToBoard where configurationID = \"%s\""), *configurationID);
	SyncQuery(query);

	query = FString::Printf(TEXT("delete from configurations where configurationID = \"%s\""), *configurationID);
	SyncQuery(query);

	if (bDestroyBoards)
	{
		for (AGame_TOCBoard* tocBoard : TOCBoards)
		{
			tocBoard->Destroy();
		}

		TOCBoards.Empty();
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_TOCBoardDB::SetCurrentConfiguration(const FString& configurationID)
{
	FString query;

	//modify other  1 confs
	query = FString::Printf(TEXT("update configurations set current = 0"));
	SyncQuery(query);

	//add our conf in

	query = TEXT("update configurations set current = 1 where configurationID = \"" + configurationID + "\"");
	SyncQuery(query);
}