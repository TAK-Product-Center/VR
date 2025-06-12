#include "Game_SessionPlayback_Impl.h"

#include "VH_COTManager.h"
#include "VH_COTConnectionInfo.h"
#include "Developer_Statics.h"
#include "SessionPlayback_Subsystem_Core.h"

#include "Game_SessionPlaybackHandler_Database.h"
#include "Game_SessionPlaybackHandler_Player.h"
#include "Game_SessionPlaybackHandler_VOIP.h"
#include "Game_SessionPlaybackDB.h"
#include "Game_EntityDB.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_Statics.h"
#include "Game_GameInstance.h"
#include "Game.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_SessionPlayback_Impl::UGame_SessionPlayback_Impl()
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_SessionPlayback_Impl::PostTick(float deltaSeconds)
{
	
}

bool UGame_SessionPlayback_Impl::PostLoadPlayback(const FString& fullPathToFile, float& playbackDuration, FString& error)
{
	UVH_COTManager* cotManager = UVH_COTManager::Get();
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();

	if (cotManager != nullptr && entityDB != nullptr)
	{
		if (SessionPlaybackDB == nullptr)
		{
			if (OpenSessionPlaybackDB(fullPathToFile))
			{
				playbackDuration = SessionPlaybackDB->GetPlaybackDuration();

				// cache connections and disconnect
				TArray<UVH_COTConnectionInfo*> connectionInfos = cotManager->GetConnectionInfos();
				for (UVH_COTConnectionInfo* connectionInfo : connectionInfos)
				{
					if (connectionInfo->bConnected)
					{
						CachedConnections.Add(connectionInfo);

						connectionInfo->bConnectAtInitialization = false;
						connectionInfo->Disconnect();
					}
				}

				// unload existing entities
				SpatialiteResults results = entityDB->QueryAllEntities();
				for (const SpatialiteResult& result : results)
				{
					if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
					{
						voManager->DeleteEntityGlobal(result);
					}
				}

				entityDB->SetDatabaseFilename(TEXT("SessionPlaybackEntityDB.sqlite"));
				entityDB->Clear();

				if (UWorld* world = UDeveloper_Statics::GetVHWorld())
				{
					world->GetTimerManager().SetTimer(TimePassedTimerHandle, this, &UGame_SessionPlayback_Impl::HandleTimePassed, 0.1, true);
				}

				return true;
			}

			error = TEXT("-- UGame_SessionPlayback_Impl::PostLoadPlayback | unable to create database | aborting");
		}
		else
		{
			error = TEXT("-- UGame_SessionPlayback_Impl::PostLoadPlayback | session playback or session recording in progress | aborting");
		}
	}

	return false;
}

void UGame_SessionPlayback_Impl::PostUnloadPlayback()
{
	for (const TPair<FString, UObject*>& entry : Handlers)
	{
		IInterface_SessionPlaybackHandler::Execute_UnloadPlayback(entry.Value);
	}

	UVH_COTManager* cotManager = UVH_COTManager::Get();
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();

	if (cotManager != nullptr && entityDB != nullptr)
	{
		// delete all entities
		entityDB->Clear();

		entityDB->SetDatabaseFilename(TEXT("EntityDB.sqlite"));

		// restore cached connections
		for (UVH_COTConnectionInfo* connectionInfo : CachedConnections)
		{
			connectionInfo->bConnectAtInitialization = true;
			connectionInfo->CreateConnection();
		}

		CachedConnections.Empty();
	}

	SessionPlaybackDB = nullptr;
}

void UGame_SessionPlayback_Impl::PostSetSecondsPassed(float secondsPassed)
{
	for (const TPair<FString, UObject*>& entry : Handlers)
	{
		IInterface_SessionPlaybackHandler::Execute_SetSecondsPassed(entry.Value, secondsPassed);
	}

	if (SessionPlaybackDB != nullptr)
	{
		// get rows between 0 and secondPassed
		SpatialiteResults results = SessionPlaybackDB->GetEvents(0, secondsPassed, true);

		// for performance, allow handlers to filter results; may not need to apply all results
		FSpatialiteResults_BP resultsBP(results);
		for (const TPair<FString, UObject*>& entry : Handlers)
		{
			IInterface_SessionPlaybackHandler::Execute_FilterSetSecondsPassedResults(entry.Value, resultsBP);
		}
		
		results.Empty();
		for (const FSpatialiteResult_BP& resultBP : resultsBP.Results)
		{
			results.Add(resultBP.Result);
		}

		ApplyEvents(results);
	}
}

void UGame_SessionPlayback_Impl::PostStartRecord(const FString& fullPathToFile)
{
	if (SessionPlaybackDB == nullptr)
	{
		if (OpenSessionPlaybackDB(fullPathToFile))
		{
			SessionPlaybackDB->Clear();

			for (const TPair<FString, UObject*>& entry : Handlers)
			{
				IInterface_SessionPlaybackHandler::Execute_StartRecord(entry.Value);
			}
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_SessionPlayback_Impl::PostStartRecord | unable to open SessionPlaybackDB | aborting"));
		}
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_SessionPlayback_Impl::PostStartRecord | session playback or session recording in progress | aborting"));
	}
}

void UGame_SessionPlayback_Impl::PostStopRecord()
{
	if (SessionPlaybackDB != nullptr)
	{
		for (const TPair<FString, UObject*>& entry : Handlers)
		{
			IInterface_SessionPlaybackHandler::Execute_StopRecord(entry.Value);
		}

		SessionPlaybackDB->ConditionalBeginDestroy();
		SessionPlaybackDB = nullptr;
	}
}

void UGame_SessionPlayback_Impl::PostSetAsImplementation()
{
	if (!Handlers.Find(UGame_SessionPlaybackHandler_Database::GetHandlerUIDStatic()))
	{
		// database handler
		UGame_SessionPlaybackHandler_Database* databaseHandler = NewObject<UGame_SessionPlaybackHandler_Database>();
		IInterface_SessionPlaybackHandler::Execute_SetImpl(databaseHandler, this);

		RegisterHandler(databaseHandler);
	}

	if (!Handlers.Find(UGame_SessionPlaybackHandler_Player::GetHandlerUIDStatic()))
	{
		// register player handler
		UGame_SessionPlaybackHandler_Player* playerHandler = NewObject<UGame_SessionPlaybackHandler_Player>();
		IInterface_SessionPlaybackHandler::Execute_SetImpl(playerHandler, this);

		RegisterHandler(playerHandler);
	}

	if (!Handlers.Find(UGame_SessionPlaybackHandler_VOIP::GetHandlerUIDStatic()))
	{
		// register voip handler
		UGame_SessionPlaybackHandler_VOIP* voipHandler = NewObject<UGame_SessionPlaybackHandler_VOIP>();
		IInterface_SessionPlaybackHandler::Execute_SetImpl(voipHandler, this);

		RegisterHandler(voipHandler);
	}
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UObject* UGame_SessionPlayback_Impl::GetHandler(const FString& handlerUID)
{
	if (UGame_GameInstance* gameInstance = UGame_Statics::GetVHGameInstance())
	{
		if (USessionPlayback_Subsystem_Core* playbackSubsystem = gameInstance->GetSubsystem<USessionPlayback_Subsystem_Core>())
		{
			if (UGame_SessionPlayback_Impl* implementation = Cast<UGame_SessionPlayback_Impl>(playbackSubsystem->GetImplementation()))
			{
				if (UObject** handlerPtr = implementation->Handlers.Find(handlerUID))
				{
					return *handlerPtr;
				}
			}
		}
	}

	//UE_LOG(Game, Warning, TEXT("-- UGame_SessionPlayback_Impl::GetHandler | unable to find handler for: %s | returning nullptr"), *handlerUID);

	return nullptr;
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_SessionPlayback_Impl::RegisterHandler(const TScriptInterface<IInterface_SessionPlaybackHandler>& handler)
{
	UObject* object = handler.GetObject();

	FString handlerUID = IInterface_SessionPlaybackHandler::Execute_GetHandlerUID(object);

	Handlers.Add(handlerUID, object);
}

void UGame_SessionPlayback_Impl::AddEvent(const FString& handlerUID, const TArray<uint8>& data) const
{
	if (IsValid(SessionPlaybackDB))
	{
		SessionPlaybackDB->AddEvent(handlerUID, data);
	}
	else
	{
		UE_LOG(Game, Error, TEXT("No PlaybackDB found.  AddEvent() aborted"));
	}
}

void UGame_SessionPlayback_Impl::AddEvent(const FString& handlerUID, const TArray<uint8>& data, double secondsElapsed)
{
	if (IsValid(SessionPlaybackDB))
	{
		SessionPlaybackDB->AddEvent(handlerUID, secondsElapsed, data);
	}
	else
	{
		UE_LOG(Game, Error, TEXT("No PlaybackDB found.  AddEvent() aborted"));
	}
}

void UGame_SessionPlayback_Impl::BeginTransaction()
{
	if (IsValid(SessionPlaybackDB))
	{
		SessionPlaybackDB->StartTransaction();
	}
	else
	{
		UE_LOG(Game, Error, TEXT("No PlaybackDB found.  BeginTransaction() aborted"));
	}
}

void UGame_SessionPlayback_Impl::CommitTransaction()
{
	if (IsValid(SessionPlaybackDB))
	{
		SessionPlaybackDB->EndTransaction();
	}
	else
	{
		UE_LOG(Game, Error, TEXT("No PlaybackDB found.  CommitTransaction() aborted"));
	}
}

double UGame_SessionPlayback_Impl::GetSecondsElapsed()
{
	if (IsValid(SessionPlaybackDB))
	{
		return SessionPlaybackDB->GetSecondsElapsed();
	}

	UE_LOG(Game, Error, TEXT("No PlaybackDB found.  GetSecondsElapsed() is returning 0.0"));
	return 0.0;
}

// ---------------------------------
// --- Implementation
// ---------------------------------
 
bool UGame_SessionPlayback_Impl::OpenSessionPlaybackDB(const FString& fullPathToDatabase)
{
	SessionPlaybackDB = NewObject<UGame_SessionPlaybackDB>(UGame_SessionPlaybackDB::StaticClass());

	SessionPlaybackDB->SetFullPathToDatabase(fullPathToDatabase);

	return SessionPlaybackDB->Initialize();
}

void UGame_SessionPlayback_Impl::ApplyEvents(const SpatialiteResults& results) const
{
	for (const SpatialiteResult& result : results)
	{
		FString handlerUID = UDatabase_Spatialite::GetString(TEXT("handlerUID"), result);

		if (UObject* const* objectPtr = Handlers.Find(handlerUID))
		{
			UObject* object = *objectPtr;

			IInterface_SessionPlaybackHandler::Execute_ApplyEvent(object, FSpatialiteResult_BP(result));
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_SessionPlayback_Impl::HandleTimePassed()
{
	if (SessionPlaybackDB != nullptr && GetPlaybackRate() != 0)
	{
		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			// get rows between LastSecondsPassed and GetSecondsPassed()
			float start = GetPlaybackRate() > 0 ? LastSecondsPassed : GetSecondsPassed();
			float finish = GetPlaybackRate() > 0 ? GetSecondsPassed() : LastSecondsPassed;

			SpatialiteResults results = SessionPlaybackDB->GetEvents(start, finish, GetPlaybackRate() > 0);
			
			ApplyEvents(results);

			LastSecondsPassed = GetSecondsPassed();
		}
	}
}

void UGame_SessionPlayback_Impl::PostSetPlaybackRate(float playbackRate)
{

}