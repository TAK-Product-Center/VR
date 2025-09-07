// Required Includes
#include "Game_MUCComponent_Database.h"
#include "Game.h"

// Engine Includes
#include "Misc/Guid.h"
#include "Async/Async.h"
#include "HAL/PlatformProcess.h"
#include "Serialization/BufferArchive.h"
#include "HAL/FileManager.h"
#include "GameFramework/Pawn.h"

// VH Plugin Includes
#include "Developer_Subsystem_TaskTracker.h"
#include "VH_DataChannelManager.h"
#include "VH_COTManager.h"
#include "VH_FileIOStatics.h"
#include "Developer_Statics.h"

// Game Includes
#include "Game_EntityDB.h"
#include "Game_MUCComponent_File.h"
#include "Game_PlayerController.h"
#include "Game_MUCTransferLog.h"
#include "Game_Statics.h"
#include "Game_GameInstance.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_PlayerState.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_MUCComponent_Database::UGame_MUCComponent_Database()
{
	bWantsInitializeComponent = true;
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

const int32 UGame_MUCComponent_Database::GetDataChannelManagerID()
{
	return 0;
}

bool UGame_MUCComponent_Database::AllowGlobalDelete(const FName& entityUID)
{
	if (UDeveloper_Statics::GetVHWorld()->GetNetMode() == NM_Client)
	{
		if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
		{
			if (UGame_MUCComponent_Database* mucComponent = Cast<UGame_MUCComponent_Database>(playerState->GetMUCComponentFromID(GetDataChannelManagerID())))
			{
				return mucComponent->AllowGlobalDelete_Internal(entityUID);
			}
		}
	}

	return true;
}

void UGame_MUCComponent_Database::MUCDelete(const FName& entityUID, bool bGlobal)
{
	UGame_GameInstance* gi = UGame_GameInstance::Get();

	UGame_EntityDB* entityDB = UGame_EntityDB::Get();

	if (gi != nullptr && entityDB != nullptr)
	{
		SpatialiteResults results = entityDB->QueryUID(entityUID.ToString());
		entityDB->DeleteResults(results);

		gi->MUC_RemoveCreatedEntityUID(entityUID);

		if (bGlobal)
		{
			if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
			{
				if (UDeveloper_Statics::GetVHWorld()->GetNetMode() == NM_Client)
				{
					if (UGame_MUCComponent_Database* mucComponent = Cast<UGame_MUCComponent_Database>(playerState->GetMUCComponentFromID(GetDataChannelManagerID())))
					{
						mucComponent->SendData(results, true, EMUCDataType::DT_Delete);
					}
				}
				else
				{
					playerState->SendDBDeleteToClients(results);
				}
			}
		}
		else
		{
			gi->MUCDeletedEntityUIDs.Add(entityUID);
		}
	}
}

// ---------------------------------
// --- Inherited Methods
// ---------------------------------

void UGame_MUCComponent_Database::InitializeComponent()
{
	Super::InitializeComponent();

	// Owner hierarchy is PlayerController -> PlayerState -> MUCComponent_Database
	if (APlayerController* pc = Cast<APlayerController>(GetOwner()->GetOwner()))
	{
		if (GetNetMode() == NM_Client && pc->IsLocalController())
		{
			// Create a new MUCEntityDB and connect to it
			if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
			{
				// Generate a unique DB name to ensure a clean local testing environment when running multiple clients
				int32 pid = FGenericPlatformProcess::GetCurrentProcessId();
				if (pid == 0)
				{
					pid = FMath::Rand();
				}
				FString databaseFilename = FString::Printf(TEXT("MUCEntityDB_%d.sqlite"), pid);
				FString fullPathToServerDB = FPaths::Combine(UGame_Statics::GetVTAKUserAppDataPath(), TEXT("Databases"), databaseFilename);

				// Catch-all to remove any hanging DBs that couldn't be deleted due to crashes or otherwise
				DeleteStaleDBs();

				entityDB->SetDatabaseFilename(databaseFilename);

				if (AGame_PlayerState* playerState = Cast<AGame_PlayerState>(GetOwner()))
				{
					playerState->SetMUCServerDBReceived(true);
					playerState->OnServerDatabaseReady.Broadcast();
				}
				else
				{
					UE_LOG(Game, Warning, TEXT("-- UGame_MUCComponent_Database::HandleReceivedData | playerState is nullptr"));
				}

				entityDB->OnInsertOrUpdate.AddDynamic(this, &UGame_MUCComponent_Database::SendDBUpdateToServer);
			}
		}
	}
}

void UGame_MUCComponent_Database::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	if (DCM != nullptr)
	{
		DCM->OnDataReceived.RemoveDynamic(this, &UGame_MUCComponent_Database::HandleReceivedData);
	}

	// Only delete the MUCEntityDB from the local controller, not other clients. NetMode can change before this is called on disconnect.
	if (APlayerController* pc = Cast<APlayerController>(GetOwner()->GetOwner()))
	{
		if (pc->IsLocalController())
		{
			if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
			{
				entityDB->OnInsertOrUpdate.RemoveDynamic(this, &UGame_MUCComponent_Database::SendDBUpdateToServer);
				DeleteMUCEntityDB();
			}
		}
	}

	Super::OnComponentDestroyed(bDestroyingHierarchy);
}

void UGame_MUCComponent_Database::HandleReceivedData(const TArray<uint8>& receivedData)
{
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();
	if (entityDB == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_MUCComponent_Database::HandleReceivedData | entityDB is nullptr, aborting"));
		return;
	}

	TArray<uint8> data;
	data.Append(receivedData);

	EMUCDataType dataType;
	FMemory::Memcpy(&dataType, data.GetData(), sizeof(EMUCDataType));
	data.RemoveAt(0, sizeof(EMUCDataType));

	bool bClient = GetNetMode() == NM_Client;

	// server and client
	if (dataType == EMUCDataType::DT_InsertOrUpdate || dataType == EMUCDataType::DT_Delete)
	{
		int32 numResults = -1;

		FMemoryReader fromBinary = FMemoryReader(data);
		fromBinary.Seek(0);

		int32 playerID = -1;
		if (!bClient)
		{
			fromBinary << playerID;
		}

		fromBinary << numResults;

		UGame_GameInstance* gi = UGame_GameInstance::Get();

		SpatialiteResults allResults;
		SpatialiteResults nonDeletedResults;
		for (int32 i = 0; i < numResults; i++)
		{
			SpatialiteResult result;
			fromBinary << result;

			allResults.Add(result);

			// only sync to entities not in the deleted entities set
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
			if (!gi->MUCDeletedEntityUIDs.Contains(FName(*entityUID)))
			{
				nonDeletedResults.Add(result);

				ReceiveLog.Add(UGame_MUCTransferLog::CreateMUCTransferLog(result));
			}
		}

		SetReplicatesUpdates(false);
		if (dataType == EMUCDataType::DT_InsertOrUpdate)
		{
			// update database
			entityDB->InsertOrUpdateResults(nonDeletedResults);

			if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
			{
				// update paged in entities
				for (const SpatialiteResult& result : nonDeletedResults)
				{
					voManager->UpdateEntityGlobal(result);
				}

				// page out/in entities based on updated database
				voManager->TriggerUpdateGlobal();
			}

			OnMUCInsertOrUpdateReceived.Broadcast(FSpatialiteResults_BP(nonDeletedResults));

			if (GetNetMode() == NM_Client)
			{
				if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
				{
					if (UGame_MUCComponent_File* mucComponent = Cast<UGame_MUCComponent_File>(playerState->GetMUCComponentFromID(UGame_MUCComponent_File::GetDataChannelManagerID())))
					{
						mucComponent->MUCInsertOrUpdateReceived(nonDeletedResults);
					}
				}
			}
		}
		else
		{
			entityDB->DeleteResults(allResults);
		}
		SetReplicatesUpdates(true);

		if (!bClient)
		{
			PushUpdateToOtherClients(allResults, dataType, playerID);
		}
	}
}

FString UGame_MUCComponent_Database::GetTaskID(APlayerController* playerController, bool bSend) const
{
	if (playerController == nullptr)
	{
		if (bSend)
		{
			return TEXT("MUCComponent_Send_Database_Server");
		}
		else
		{
			return TEXT("MUCComponent_Receive_Database_Server");
		}
	}
	else if (APawn* pawn = playerController->GetPawn())
	{
		if (AGame_PlayerState* playerState = Cast<AGame_PlayerState>(pawn->GetPlayerState()))
		{
			if (bSend)
			{
				return FString::Printf(TEXT("MUCComponent_Send_Database_%s"), *playerState->GetCallsign());
			}
			else
			{
				return FString::Printf(TEXT("MUCComponent_Receive_Database_%s"), *playerState->GetCallsign());
			}
		}
	}

	return TEXT("");
}

FString UGame_MUCComponent_Database::GetTaskDescription(APlayerController* playerController, bool bSend) const
{
	if (playerController == nullptr)
	{
		if (bSend)
		{
			return TEXT("MUC: Send database to server");
		}
		else
		{
			return TEXT("MUC: Receive database from server");
		}
	}
	else if (APawn* pawn = playerController->GetPawn())
	{
		if (AGame_PlayerState* playerState = Cast<AGame_PlayerState>(pawn->GetPlayerState()))
		{
			if (bSend)
			{
				return FString::Printf(TEXT("MUC: Send database update to %s"), *playerState->GetCallsign());
			}
			else
			{
				return FString::Printf(TEXT("MUC: Receive database update from %s"), *playerState->GetCallsign());
			}
		}
	}

	return TEXT("");
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_MUCComponent_Database::SendDBUpdateToClients(const FSpatialiteResults_BP& results)
{
	SendData(results, false, EMUCDataType::DT_InsertOrUpdate);
}

void UGame_MUCComponent_Database::SendDBDeleteToClients(const FSpatialiteResults_BP& results)
{
	SendData(results, false, EMUCDataType::DT_Delete);
}

void UGame_MUCComponent_Database::AddSendLog(const SpatialiteResult& result)
{
	SendLog.Add(UGame_MUCTransferLog::CreateMUCTransferLog(result));
}

TArray<UGame_MUCTransferLog*> UGame_MUCComponent_Database::GetSendLog() const
{
	return SendLog;
}

TArray<UGame_MUCTransferLog*> UGame_MUCComponent_Database::GetReceiveLog() const
{
	return ReceiveLog;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

bool UGame_MUCComponent_Database::AllowGlobalDelete_Internal(const FName& entityUID)
{
	if (UGame_GameInstance* gi = UGame_GameInstance::Get())
	{
		return gi->MUC_HasCreatedEntityUID(entityUID);
	}

	return false;
}

void UGame_MUCComponent_Database::SetReplicatesUpdates(bool shouldReplicateUpdates)
{
	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		playerState->bReplicateMUCUpdates = shouldReplicateUpdates;
	}
}

void UGame_MUCComponent_Database::SendData(const FSpatialiteResults_BP& results, bool bToServer, EMUCDataType dataType)
{
	AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState();
	if (playerState != nullptr)
	{
		if (!playerState->bReplicateMUCUpdates)
		{
			return;
		}
	}
	else
	{
		return;
	}

	APlayerController* pc = nullptr;
	if (bToServer)
	{
		pc = UGame_Statics::GetVHPlayerController();
		if (pc == nullptr)
		{
			return;
		}
	}

	UVH_COTManager* cotManager = UVH_COTManager::Get();
	if (cotManager == nullptr)
	{
		return;
	}

	TArray<int32> validIndices;

	for (int32 i = 0; i < results.Results.Num(); i++)
	{
		FString categoryID = UDatabase_Spatialite::GetString(TEXT("categoryID"), results.Results[i].Result);

		if (!categoryID.Equals(TEXT("contact")))
		{
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), results.Results[i].Result);

			// cotEvent could legitimately be nullptr here if sending something that doesn't have cot in its blob (e.g. RedX)
			UVH_COTEvent* cotEvent = cotManager->GetCotEventFromUID(entityUID);
			if (!UVH_COTManager::IsVTAKGhost(cotEvent))
			{
				validIndices.Add(i);
			}
		}
	}

	int32 numResults = validIndices.Num();

	if (numResults == 0)
	{
		// nothing to send
		return;
	}

	FBufferArchive toBinary;

	toBinary << dataType;

	if (bToServer)
	{
		int32 playerID = playerState->GetPlayerId();
		toBinary << playerID;
	}

	toBinary << numResults;

	SpatialiteResults validResults;
	for (const int32& validIndex : validIndices)
	{
		SpatialiteResult validResult = results.Results[validIndex].Result;
		toBinary << validResult;

		validResults.Add(validResult);

		AddSendLog(validResult);
	}

	TArray<uint8> data = (TArray<uint8>&)toBinary;

	if (DCM != nullptr)
	{
		if (bToServer)
		{
			DCM->SendDataToServer(data);
		}
		else
		{
			DCM->BroadcastDataToClients(data);
		}
	}

	OnMUCInsertOrUpdateSent.Broadcast(FSpatialiteResults_BP(validResults));
}

void UGame_MUCComponent_Database::PushUpdateToOtherClients(const FSpatialiteResults_BP& results, EMUCDataType dataType, int32 excludePlayerID)
{
	FBufferArchive toBinary;

	toBinary << dataType;

	int32 numResults = results.Results.Num();
	toBinary << numResults;

	for (const FSpatialiteResult_BP& resultBP : results.Results)
	{
		SpatialiteResult result = resultBP.Result;
		toBinary << result;
	}

	TArray<uint8> data = (TArray<uint8>&)toBinary;

	if (DCM != nullptr)
	{
		DCM->BroadcastDataToClients(data, -1, excludePlayerID);
	}
}

void UGame_MUCComponent_Database::DeleteMUCEntityDB() const
{
	// Delete the current MUCEntityDB if one exists
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->OnInsertOrUpdate.RemoveDynamic(this, &UGame_MUCComponent_Database::SendDBUpdateToServer);
		if (entityDB->GetDatabaseFilename().StartsWith(TEXT("MUCEntityDB_")))
		{
			entityDB->Disconnect();
			
			FString dbFullPath = FPaths::Combine(entityDB->GetDatabasePath(), entityDB->GetDatabaseFilename());
			IFileManager::Get().Delete(*dbFullPath);
		}
	}
}

void UGame_MUCComponent_Database::DeleteStaleDBs() const
{
	FString fullPathToServerDB = FPaths::Combine(UGame_Statics::GetVTAKUserAppDataPath(), TEXT("Databases"));
	TArray<FString> files;
	IFileManager::Get().FindFiles(files, *fullPathToServerDB, TEXT(".sqlite"));

	// Attempt to delete all MUCEntityDB files. Files in use will be unaffected. 
	for (FString fileName : files)
	{
		if (fileName.StartsWith(TEXT("MUCEntityDB_")))
		{
			IFileManager::Get().Delete(*FPaths::Combine(fullPathToServerDB, fileName));
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_MUCComponent_Database::SendDBUpdateToServer(const FSpatialiteResults_BP& results)
{
	SendData(results, true, EMUCDataType::DT_InsertOrUpdate);
}
