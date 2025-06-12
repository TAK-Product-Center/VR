// Required Includes
#include "Game_SessionPlaybackDB.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_COTManager.h"
#include "VH_COTEvent.h"

// Game Includes
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_SessionPlaybackDB::UGame_SessionPlaybackDB() :
	PrimaryTableName(TEXT("playback"))
{
	PrimaryTableFields.Empty();
	PrimaryTableFields.Add(TEXT("id integer not null primary key autoincrement"));
	PrimaryTableFields.Add(TEXT("secondsPassed real not null"));
	PrimaryTableFields.Add(TEXT("handlerUID string not null"));
	PrimaryTableFields.Add(TEXT("data blob not null"));
}

// ---------------------------------
// --- API
// ---------------------------------

bool UGame_SessionPlaybackDB::Initialize()
{
	if (Connect())
	{
		StartTime = FDateTime::Now();

		return true;
	}

	return false;
}

void UGame_SessionPlaybackDB::SetFullPathToDatabase(const FString& fullPathToDatabase)
{
	if (!IsDatabaseReady())
	{
		FullPathToDatabase = fullPathToDatabase;
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_SessionPlaybackDB::SetDatabaseName | must be called prior to Initialize"));
	}
}

void UGame_SessionPlaybackDB::AddEvent(const FString& handlerUID, const TArray<uint8>& data) const
{
	double secondsPassed = (FDateTime::Now() - StartTime).GetTotalSeconds();

	AddEvent(handlerUID, secondsPassed, data);
}

void UGame_SessionPlaybackDB::AddEvent(const FString& handlerUID, double secondsPassed, const TArray<uint8>& data) const
{
	//double secondsPassed = (FDateTime::Now() - StartTime).GetTotalSeconds();

	FString query = FString::Printf(TEXT("insert into %s ("), *PrimaryTableName);
	query += TEXT("secondsPassed, ");
	query += TEXT("handlerUID, ");
	query += TEXT("data) values (");
	query += FString::Printf(TEXT("%f, "), secondsPassed);
	query += FString::Printf(TEXT("\"%s\", "), *handlerUID);
	query += FString::Printf(TEXT("?)"));

	if (sqlite3_stmt* statement = PrepareStatement(query))
	{
		BindBlob(statement, data, 1);

		SyncQuery(statement);
	}
}

SpatialiteResults UGame_SessionPlaybackDB::GetEvents(float minNotInclusive, float maxInclusive, bool bAsc) const
{
	FString query = FString::Printf(TEXT("select * from %s where secondsPassed > %f and secondsPassed <= %f order by secondsPassed %s"), *PrimaryTableName, minNotInclusive, maxInclusive, bAsc ? TEXT("asc") : TEXT("desc"));
	
	SpatialiteResults results;
	SyncQuery(query, results);

	return results;
}

float UGame_SessionPlaybackDB::GetPlaybackDuration() const
{
	SpatialiteResults results;
	SyncQuery(FString::Printf(TEXT("select max(secondsPassed) as secondsPassed from %s"), *PrimaryTableName), results);

	if (results.Num() > 0)
	{
		return UDatabase_Spatialite::GetDouble(TEXT("secondsPassed"), results[0]);
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_SessionPlaybackDB::GetPlaybackDuration | no results | returning 0"));

	return 0;
}

void UGame_SessionPlaybackDB::Clear() const
{
	SyncQuery(FString::Printf(TEXT("delete from %s"), *PrimaryTableName));
}

void UGame_SessionPlaybackDB::ClearPostSeconds(float secondsPassed)
{
	//UE_LOG(LogTemp, Warning, TEXT("delete from %s where secondsPassed > %f"), *PrimaryTableName, secondsPassed);
	SyncQuery(FString::Printf(TEXT("delete from %s where secondsPassed > %f"), *PrimaryTableName, secondsPassed));
}

void UGame_SessionPlaybackDB::StartTransaction()
{
	SyncQuery(TEXT("begin transaction"));
}

void UGame_SessionPlaybackDB::EndTransaction()
{
	SyncQuery(TEXT("commit"));
}

double UGame_SessionPlaybackDB::GetSecondsElapsed() const
{
	return (FDateTime::Now() - StartTime).GetTotalSeconds();
}

// ---------------------------------
// --- Implementation
// ---------------------------------

bool UGame_SessionPlaybackDB::Connect()
{
	if (OpenDatabase(FullPathToDatabase, true))
	{
		// create primary table if necessary
		FString query = FString::Printf(TEXT("create table if not exists %s ("), *PrimaryTableName);
		query += FString::Join(PrimaryTableFields, TEXT(", "));
		query += TEXT(")");

		SyncQuery(query);

		return true;
	}

	return false;
}
