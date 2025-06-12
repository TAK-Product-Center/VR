// Required Includes
#include "Game_SessionPlaybackHandler_Database.h"
#include "Game.h"

// Engine Includes
#include "Serialization/BufferArchive.h"

// Game Includes
#include "Game_SessionPlayback_Impl.h"
#include "Game_EntityDB.h"
#include "Game_VirtualObjectiveManager.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_SessionPlaybackHandler_Database::UGame_SessionPlaybackHandler_Database()
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

FString UGame_SessionPlaybackHandler_Database::GetHandlerUIDStatic()
{
	return TEXT("sessionplayback.handler.database");
}

// ---------------------------------
// --- Interface_SessionPlaybackHandler
// ---------------------------------

FString UGame_SessionPlaybackHandler_Database::GetHandlerUID_Implementation() const
{
	return GetHandlerUIDStatic();
}

void UGame_SessionPlaybackHandler_Database::SetImpl_Implementation(UGame_SessionPlayback_Impl* impl)
{
	Implementation = impl;
}

void UGame_SessionPlaybackHandler_Database::ApplyEvent_Implementation(const FSpatialiteResult_BP& result)
{
	UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get();
	
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();

	if (voManager != nullptr && entityDB != nullptr)
	{
		TArray<uint8> data = UDatabase_Spatialite::GetBlob(TEXT("data"), result.Result);

		FMemoryReader fromBinary = FMemoryReader(data);
		fromBinary.Seek(0);

		FString type;
		fromBinary << type;

		SpatialiteResult resultToApply;
		fromBinary << resultToApply;

		if (type.Equals(TEXT("delete")))
		{
			entityDB->DeleteFromResult(resultToApply);
		}
		else
		{
			entityDB->InsertOrUpdateResult(resultToApply);
			
			voManager->UpdateEntityGlobal(resultToApply);
		}
	}
}

void UGame_SessionPlaybackHandler_Database::StartRecord_Implementation()
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->OnInsertOrUpdate.AddDynamic(this, &UGame_SessionPlaybackHandler_Database::HandleDatabaseInsertOrUpdate);

		entityDB->OnDelete.AddDynamic(this, &UGame_SessionPlaybackHandler_Database::HandleDatabaseDelete);
	}
}

void UGame_SessionPlaybackHandler_Database::StopRecord_Implementation()
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->OnInsertOrUpdate.RemoveDynamic(this, &UGame_SessionPlaybackHandler_Database::HandleDatabaseInsertOrUpdate);

		entityDB->OnDelete.RemoveDynamic(this, &UGame_SessionPlaybackHandler_Database::HandleDatabaseDelete);
	}
}

void UGame_SessionPlaybackHandler_Database::SetSecondsPassed_Implementation(float secondsPassed)
{
	// delete all entities
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->Clear();
	}
}

void UGame_SessionPlaybackHandler_Database::FilterSetSecondsPassedResults_Implementation(FSpatialiteResults_BP& results)
{
	FString handlerUID = IInterface_SessionPlaybackHandler::Execute_GetHandlerUID(this);

	// keep the most recent result for each entityUID, remove the rest
	TSet<FString> entityUIDs;
	for (int32 i = 0; i < results.Results.Num(); i++)
	{
		if (UDatabase_Spatialite::GetString(TEXT("handlerUID"), results.Results[i]).Equals(handlerUID))
		{
			TArray<uint8> data = UDatabase_Spatialite::GetBlob(TEXT("data"), results.Results[i]);

			FMemoryReader fromBinary = FMemoryReader(data);
			fromBinary.Seek(0);

			FString type;
			fromBinary << type;

			SpatialiteResult result;
			fromBinary << result;

			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
			if (entityUIDs.Contains(entityUID))
			{
				results.Results.RemoveAt(i, 1);
				i--;
			}
			else
			{
				entityUIDs.Add(entityUID);
			}
		}
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_SessionPlaybackHandler_Database::AddEntry(const FString& type, const SpatialiteResult& result) const
{
	FBufferArchive toBinary;

	FString typeForBinary = type;
	toBinary << typeForBinary;

	SpatialiteResult resultForBinary = result;
	toBinary << resultForBinary;

	TArray<uint8> data = (TArray<uint8>&)toBinary;

	FString handlerUID = IInterface_SessionPlaybackHandler::Execute_GetHandlerUID(this);
	Implementation->AddEvent(handlerUID, data);
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_SessionPlaybackHandler_Database::HandleDatabaseInsertOrUpdate(const FSpatialiteResults_BP& results)
{
	for (int32 i = 0; i < results.Results.Num(); i++)
	{
		AddEntry(TEXT("update"), results.Results[i].Result);
	}
}

void UGame_SessionPlaybackHandler_Database::HandleDatabaseDelete(const FSpatialiteResults_BP& results)
{
	for (int32 i = 0; i < results.Results.Num(); i++)
	{
		AddEntry(TEXT("delete"), results.Results[i].Result);
	}
}
