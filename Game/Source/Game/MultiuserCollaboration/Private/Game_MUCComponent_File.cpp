#include "Game_MUCComponent_File.h"

#include "Misc/Guid.h"
#include "Async/Async.h"

#include "VH_FileIOStatics.h"
#include "VH_DataChannelManager.h"
#include "Developer_Subsystem_TaskTracker.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"
#include "Developer_Subsystem_Core.h"

#include "Game_EntityDB.h"
#include "Game_Subsystem_Core.h"
#include "Game_PlayerController.h"
#include "Game_PlayerState.h"
#include "Game_Statics.h"
#include "Game_GameInstance.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_GameState.h"
#include "Game_MUCComponent_Database.h"
#include "Game_HandlerService.h"
#include "Game_ImportManager.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_MUCComponent_File::UGame_MUCComponent_File()
{
	bWantsInitializeComponent = true;

	PrimaryComponentTick.bCanEverTick = true;
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

const int32 UGame_MUCComponent_File::GetDataChannelManagerID()
{
	return 1;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool UGame_MUCComponent_File::IsReadyForFinishDestroy()
{
	return Super::IsReadyForFinishDestroy() && DestroyCounter.GetValue() == 0;
}

void UGame_MUCComponent_File::TickComponent(float deltaSeconds, enum ELevelTick tickType, FActorComponentTickFunction* thisTickFunction)
{
	Super::TickComponent(deltaSeconds, tickType, thisTickFunction);

	if (GetNetMode() == NM_ListenServer && DCM != nullptr)
	{
		for (int32 i = 0; i < PendingSends.Num(); i++)
		{
			FPendingSend pendingSend = PendingSends[i];

			if (!DCM->IsSendingServerToClient(pendingSend.PlayerController))
			{
				PendingSends.RemoveAt(i, 1);

				if (pendingSend.DataType == EMUCDataType::DT_FileInfo)
				{
					SendFileInfo(pendingSend.MD5Hash, pendingSend.PlayerController->PlayerState->GetPlayerId(), pendingSend.FullPathToFile);
				}
				else if (pendingSend.DataType == EMUCDataType::DT_File)
				{
					SendFile(pendingSend.MD5Hash, pendingSend.PlayerController->PlayerState->GetPlayerId(), pendingSend.FullPathToFile);
				}

				break;
			}
		}
	}
}

FString UGame_MUCComponent_File::GetTaskID(APlayerController* playerController, bool bSend) const
{
	if (playerController == nullptr)
	{
		if (bSend)
		{
			return FString::Printf(TEXT("MUCComponent_Send_File|Server"));
		}
		else
		{
			return FString::Printf(TEXT("MUCComponent_Receive_File|Server|%s"), *ClientReceivingHash);
		}
	}
	else if (APawn* pawn = playerController->GetPawn())
	{
		if (AGame_PlayerState* playerState = Cast<AGame_PlayerState>(pawn->GetPlayerState()))
		{
			if (bSend)
			{
				if (const FTransferInfo* transferInfoPtr = SendInfos.Find(playerController))
				{
					return FString::Printf(TEXT("MUCComponent_Send_File|%s|%s|%s"), *playerState->GetCallsign(), *(transferInfoPtr->FullPathToFile), *(transferInfoPtr->FileSize));
				}
			}
			else
			{
				return FString::Printf(TEXT("MUCComponent_Receive_File|%s"), *playerState->GetCallsign());
			}
		}
	}

	return TEXT("");
}

FString UGame_MUCComponent_File::GetTaskDescription(APlayerController* playerController, bool bSend) const
{
	if (playerController == nullptr)
	{
		if (bSend)
		{
			return TEXT("MUC: Send file to server");
		}
		else
		{
			return TEXT("MUC: Receive file from server");
		}
	}
	else if (APawn* pawn = playerController->GetPawn())
	{
		if (AGame_PlayerState* playerState = Cast<AGame_PlayerState>(pawn->GetPlayerState()))
		{
			if (bSend)
			{
				return FString::Printf(TEXT("MUC: Send file to %s"), *playerState->GetCallsign());
			}
			else
			{
				return FString::Printf(TEXT("MUC: Receive file from %s"), *playerState->GetCallsign());
			}
		}
	}

	return TEXT("");
}

void UGame_MUCComponent_File::PostServer_HandleChannelClosed(APlayerController* playerController)
{
	for (int32 i = 0; i < PendingSends.Num(); i++)
	{
		if (PendingSends[i].PlayerController == playerController)
		{
			PendingSends.RemoveAt(i, 1);
			i--;
		}
	}

	SendInfos.Remove(playerController);
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_MUCComponent_File::ClientBeginTransfer(const FString& hash)
{
	FMD5Hash md5Hash;
	LexFromString(md5Hash, *hash);

	SendFileRequest(md5Hash);
}

TMap<FString, FTransferInfo> UGame_MUCComponent_File::ClientGetReceiveInfos() const
{
	return ReceiveInfos;
}

TArray<FString> UGame_MUCComponent_File::GetSentFiles() const
{
	return SentFiles;
}

TArray<FString> UGame_MUCComponent_File::GetReceivedFiles() const
{
	return ReceivedFiles;
}

void UGame_MUCComponent_File::MUCInsertOrUpdateReceived(const SpatialiteResults& results)
{
	if (UGame_HandlerService* handlerService = UGame_HandlerService::Get())
	{
		for (const SpatialiteResult& result : results)
		{
			TMap<FString, FString> md5Strings = handlerService->GetHashesToSyncForMUC(result);

			for (const TPair<FString, FString>& entry : md5Strings)
			{
				FString md5String = entry.Key;
				FString fullPathToFile = entry.Value;

				FMD5Hash md5Hash;
				LexFromString(md5Hash, *md5String);

				if (md5Hash.IsValid())
				{
					Async(EAsyncExecution::ThreadPool, [this, fullPathToFile, md5Hash, md5String]()
					{
						DestroyCounter.Increment();

						if (!IsSafeToExecute())
						{
							DestroyCounter.Decrement();
							return;
						}

						// check if file already exists on local disk
						FString fullPath = FPaths::Combine(UGame_Statics::GetVTAKUserAppDataPath(), TEXT("MUCDownloads"));

						TArray<FString> files;
						UVH_FileIOStatics::GetFilesInPath(files, fullPath, TEXT(""), false, true, true);

						UGame_GameInstance* gi = UGame_GameInstance::Get();
						FString fileToRequest = TEXT("");
						for (const FString& file : files)
						{
							FMD5Hash hash;
							if (!gi->GetHashFromFile(file, hash))
							{
								hash = FMD5Hash::HashFile(*file);
								gi->AddHashForFile(hash, file);
							}

							if (hash == md5Hash)
							{
								fileToRequest = file;
								break;
							}
						}

						if (fileToRequest.IsEmpty())
						{
							AsyncTask(ENamedThreads::GameThread, [this, fullPathToFile, md5Hash, md5String]()
							{
								DestroyCounter.Increment();

								if (!IsSafeToExecute())
								{
									DestroyCounter.Decrement();
									return;
								}

								if (!ClientRequestedFiles.Contains(md5String))
								{
									FString filename = FPaths::GetCleanFilename(fullPathToFile);

									ClientRequestedFiles.Add(md5String);

									FTransferInfo transferInfo;
									transferInfo.FullPathToFile = fullPathToFile;
									transferInfo.FileSize = TEXT("");

									// store here for reference if no one is bound to OnFileRequest yet
									ReceiveInfos.Add(md5String, transferInfo);

									// don't know file size yet, but still notify listeners with the info we have
									OnFileRequest.Broadcast(md5String, transferInfo.FullPathToFile, transferInfo.FileSize);

									SendFileInfoRequest(md5Hash, fullPathToFile);
								}

								DestroyCounter.Decrement();
							});
						}

						DestroyCounter.Decrement();
					});
				}
				else
				{
					FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

					UE_LOG(Game, Warning, TEXT("-- UGame_MUCComponent_File::HandleMUCInsertOrUpdate | invalid md5 hash for file to sync | entityUID: %s"), *entityUID);
				}
			}
		}
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_MUCComponent_File::SendFileInfoRequest(const FMD5Hash& md5Hash, const FString& fullPathToFile)
{
	// request info for file with specified md5Hash from server
	EMUCDataType dataType = EMUCDataType::DT_RequestFileInfo;

	int32 playerID = UGame_Statics::GetVHPlayerController()->PlayerState->GetPlayerId();

	FMD5Hash md5HashToSend = md5Hash;
	FString fullPathToFileToSend = fullPathToFile;

	FBufferArchive toBinary;
	toBinary << dataType;
	toBinary << playerID;
	toBinary << md5HashToSend;
	toBinary << fullPathToFileToSend;

	TArray<uint8> data = (TArray<uint8>&)toBinary;

	if (DCM != nullptr)
	{
		DCM->SendDataToServer(data);
	}
}

void UGame_MUCComponent_File::SendFileInfo(const FMD5Hash& md5Hash, int32 onlyPlayerID, const FString& fullPathToFile)
{
	APlayerController* playerController = GetPlayerControllerFromPlayerID(onlyPlayerID);

	if (DCM != nullptr && DCM->IsSendingServerToClient(playerController))
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_MUCComponent_File::SendFileInfo | %d"), onlyPlayerID);
		// queue sends to keep percent complete accurate
		FPendingSend pendingSend;
		pendingSend.DataType = EMUCDataType::DT_FileInfo;
		pendingSend.PlayerController = playerController;
		pendingSend.MD5Hash = md5Hash;
		pendingSend.FullPathToFile = fullPathToFile;

		PendingSends.Add(pendingSend);

		return;
	}

	Async(EAsyncExecution::ThreadPool, [this, md5Hash, onlyPlayerID, fullPathToFile]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}

		UE_LOG(Game, Warning, TEXT("-- UGame_MUCComponent_File::SendFileInfo2 | %d"), onlyPlayerID);
		if (!fullPathToFile.IsEmpty())
		{
			AsyncTask(ENamedThreads::GameThread, [this, fullPathToFile, md5Hash, onlyPlayerID]()
			{
				DestroyCounter.Increment();

				if (!IsSafeToExecute())
				{
					DestroyCounter.Decrement();
					return;
				}

				EMUCDataType dataType = EMUCDataType::DT_FileInfo;

				FMD5Hash md5HashToSend = md5Hash;

				FString fullPathToFileToSend = fullPathToFile;

				int64 fileSizeBytes = IFileManager::Get().FileSize(*fullPathToFile);

				FBufferArchive toBinary;
				toBinary << dataType;
				toBinary << md5HashToSend;
				toBinary << fullPathToFileToSend;
				toBinary << fileSizeBytes;

				TArray<uint8> data = (TArray<uint8>&)toBinary;

				if (DCM != nullptr)
				{
					UE_LOG(Game, Warning, TEXT("-- UGame_MUCComponent_File::SendFileInfo3 | %d"), onlyPlayerID);
					DCM->BroadcastDataToClients(data, onlyPlayerID);
				}

				DestroyCounter.Decrement();
			});
		}

		DestroyCounter.Decrement();
	});
}

void UGame_MUCComponent_File::SendFileRequest(const FMD5Hash& md5Hash)
{
	// request file with specified md5Hash from server
	EMUCDataType dataType = EMUCDataType::DT_RequestFile;
	
	int32 playerID = UGame_Statics::GetVHPlayerController()->PlayerState->GetPlayerId();
	FMD5Hash md5HashToSend = md5Hash;
	FString fullPathToFile = ReceiveInfos[LexToString(md5Hash)].FullPathToFile;

	FBufferArchive toBinary;
	toBinary << dataType;
	toBinary << playerID;
	toBinary << md5HashToSend;
	toBinary << fullPathToFile;

	TArray<uint8> data = (TArray<uint8>&)toBinary;

	if (DCM != nullptr)
	{
		DCM->SendDataToServer(data);
	}
}

void UGame_MUCComponent_File::SendFile(const FMD5Hash& md5Hash, int32 onlyPlayerID, const FString& fullPathToFile)
{
	APlayerController* playerController = GetPlayerControllerFromPlayerID(onlyPlayerID);

	if (DCM != nullptr && DCM->IsSendingServerToClient(playerController))
	{
		// queue sends to keep percent complete accurate
		FPendingSend pendingSend;
		pendingSend.DataType = EMUCDataType::DT_File;
		pendingSend.PlayerController = playerController;
		pendingSend.MD5Hash = md5Hash;
		pendingSend.FullPathToFile = fullPathToFile;

		PendingSends.Add(pendingSend);

		return;
	}

	Async(EAsyncExecution::ThreadPool, [this, md5Hash, onlyPlayerID, playerController, fullPathToFile]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}

		if (!fullPathToFile.IsEmpty())
		{
			AsyncTask(ENamedThreads::GameThread, [this, fullPathToFile, md5Hash, onlyPlayerID, playerController]()
			{
				DestroyCounter.Increment();

				if (!IsSafeToExecute())
				{
					DestroyCounter.Decrement();
					return;
				}

				int64 fileSize = IFileManager::Get().FileSize(*fullPathToFile);
				float fileSizeFloat = fileSize / 1000000.f;

				FTransferInfo transferInfo;
				transferInfo.FullPathToFile = fullPathToFile;
				transferInfo.FileSize = FString::Printf(TEXT("%.2f MB"), fileSizeFloat);

				SendInfos.Add(playerController, transferInfo);

				FMD5Hash md5HashToSend = md5Hash;

				// DT_PreFile
				{
					EMUCDataType dataType = EMUCDataType::DT_PreFile;

					FBufferArchive toBinary;
					toBinary << dataType;
					toBinary << md5HashToSend;

					TArray<uint8> data = (TArray<uint8>&)toBinary;

					if (DCM != nullptr)
					{
						DCM->BroadcastDataToClients(data, onlyPlayerID);
					}
				}

				// DT_File
				{
					SentFiles.Add(FPaths::GetCleanFilename(fullPathToFile));

					EMUCDataType dataType = EMUCDataType::DT_File;

					TArray<uint8> fileData;
					FFileHelper::LoadFileToArray(fileData, *fullPathToFile);

					FString extension = FPaths::GetExtension(fullPathToFile);

					FBufferArchive toBinary;
					toBinary << dataType;
					toBinary << md5HashToSend;
					toBinary << extension;
					toBinary << fileData;

					TArray<uint8> data = (TArray<uint8>&)toBinary;

					if (DCM != nullptr)
					{
						DCM->BroadcastDataToClients(data, onlyPlayerID);
					}
				}

				DestroyCounter.Decrement();
			});
		}

		DestroyCounter.Decrement();
	});
}

APlayerController* UGame_MUCComponent_File::GetPlayerControllerFromPlayerID(int32 playerID) const
{
	if (AGame_GameState* gameState = GetWorld()->GetGameState<AGame_GameState>())
	{
		for (APlayerState* playerState : gameState->PlayerArray)
		{
			if (playerState->GetPlayerId() == playerID)
			{
				return Cast<APlayerController>(playerState->GetOwner());
			}
		}
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_MUCComponent_File::GetPlayerControllerFromPlayerID | no PlayerController found for %d"), playerID);

	return nullptr;
}

bool UGame_MUCComponent_File::IsSafeToExecute()
{
	if (!IsValidLowLevelFast() || HasAnyFlags(RF_BeginDestroyed) || GetClass() == nullptr)
	{
		return false;
	}

	return true;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_MUCComponent_File::HandleReceivedData(const TArray<uint8>& receivedData)
{
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();
	if (entityDB == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_MUCComponent_File::HandleReceivedData | entityDB is nullptr, aborting"));
		return;
	}

	TArray<uint8> data;
	data.Append(receivedData);

	EMUCDataType dataType;
	FMemory::Memcpy(&dataType, data.GetData(), sizeof(EMUCDataType));
	data.RemoveAt(0, sizeof(EMUCDataType));

	bool bClient = GetNetMode() == NM_Client;

	if (bClient)
	{
		// client
		if (dataType == EMUCDataType::DT_FileInfo)
		{
			FMemoryReader fromBinary = FMemoryReader(data);
			fromBinary.Seek(0);

			FMD5Hash md5Hash;
			FString fullPathToFile;
			int64 fileSize;

			fromBinary << md5Hash;
			fromBinary << fullPathToFile;
			fromBinary << fileSize;

			UE_LOG(Game, Warning, TEXT("-- EMUCDataType::DT_FileInfo | %s"), *fullPathToFile);

			float fileSizeFloat = fileSize / 1000000.f;

			FTransferInfo transferInfo;
			transferInfo.FullPathToFile = fullPathToFile;
			transferInfo.FileSize = FString::Printf(TEXT("%.2f MB"), fileSizeFloat);

			FString hashString = LexToString(md5Hash);

			// store here for reference if no one is bound to OnFileRequest yet
			ReceiveInfos.Add(hashString, transferInfo);

			OnFileRequest.Broadcast(hashString, fullPathToFile, transferInfo.FileSize);

			UE_LOG(Game, Warning, TEXT("-- client received file info: %s"), *fullPathToFile);

			if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
			{
				if (gameSettings->GetSettingBool(TEXT("MUC_AutoReceive")))
				{
					ClientBeginTransfer(hashString);
				}
			}
			
		}
		else if (dataType == EMUCDataType::DT_PreFile)
		{
			FMemoryReader fromBinary = FMemoryReader(data);
			fromBinary.Seek(0);

			FMD5Hash md5Hash;

			fromBinary << md5Hash;

			ClientReceivingHash = LexToString(md5Hash);
		}
		else if (dataType == EMUCDataType::DT_File)
		{
			FMemoryReader fromBinary = FMemoryReader(data);
			fromBinary.Seek(0);

			FMD5Hash md5Hash;
			FString extension;
			TArray<uint8> fileData;

			fromBinary << md5Hash;
			fromBinary << extension;
			fromBinary << fileData;

			// add to ReceivedFiles
			FTransferInfo* transferInfoPtr = ReceiveInfos.Find(LexToString(md5Hash));
			if (transferInfoPtr == nullptr)
			{
				UE_LOG(Game, Warning, TEXT("-- UGame_MUCComponent_File::HandleReceivedData | transferInfoPtr is nullptr | aborting"));
			}
			
			ReceivedFiles.Add(transferInfoPtr->FullPathToFile);

			// handle ClientReceivingHash getting overwritten before removing task for received file
			if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
			{
				taskTracker->RemoveActiveTask(GetTaskID(nullptr, false));
			}

			// save file to disk
			FString filename = FString::Printf(TEXT("%s.%s"), *FGuid::NewGuid().ToString(), *extension);

			FString fullPathToFile = FPaths::Combine(UGame_Statics::GetVTAKUserAppDataPath(), TEXT("MUCDownloads"), filename);

			FFileHelper::SaveArrayToFile(fileData, *fullPathToFile);

			if (UVH_FileIOStatics::IsZipArchive(fullPathToFile))
			{
				IFileManager& fileManager = IFileManager::Get();

				FString extractDir = FString(FPlatformProcess::UserTempDir()) / TEXT("VRTAK") / FPaths::GetBaseFilename(transferInfoPtr->FullPathToFile);

				fileManager.DeleteDirectory(*extractDir, false, true);
				UVH_FileIOStatics::UnzipFile(fullPathToFile, extractDir);

				UGame_ImportManager::RecursivelyExtractZipArchives(extractDir, true);
			}

			if (UGame_GameInstance* gi = UGame_GameInstance::Get())
			{
				gi->AddHashForFile(md5Hash, fullPathToFile);
			}

			// page in if necessary
			if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
			{
				voManager->TriggerUpdateGlobal();
			}
		}
	}
	else
	{
		// server
		if (dataType == EMUCDataType::DT_RequestFileInfo)
		{
			FMD5Hash md5Hash;
			int32 playerID = -1;
			FString fullPathToFile;

			FMemoryReader fromBinary = FMemoryReader(data);
			fromBinary.Seek(0);

			fromBinary << playerID;
			fromBinary << md5Hash;
			fromBinary << fullPathToFile;

			SendFileInfo(md5Hash, playerID, fullPathToFile);
		}
		else if (dataType == EMUCDataType::DT_RequestFile)
		{
			FMD5Hash md5Hash;
			int32 playerID = -1;
			FString fullPathToFile;

			FMemoryReader fromBinary = FMemoryReader(data);
			fromBinary.Seek(0);

			fromBinary << playerID;
			fromBinary << md5Hash;
			fromBinary << fullPathToFile;

			SendFile(md5Hash, playerID, fullPathToFile);
		}
	}
}
