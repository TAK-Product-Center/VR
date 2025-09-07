// Required Includes
#include "Game_EntityHandler.h"
#include "Game.h"

// Engine Includes
#include "Async/Async.h"
#include "Misc/Paths.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "Developer_Statics.h"
#include "VH_FileIOStatics.h"

// Game Includes
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_GameInstance.h"
#include "Game_EntityDB.h"
#include "Game_Statics.h"
#include "Game_ImportManager.h"


// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_EntityHandler::UGame_EntityHandler()
{
}

// ---------------------------------
// --- Interface_EntityHandler
// ---------------------------------

FString UGame_EntityHandler::GetClassUID_Implementation()
{
	UE_LOG(Game, Warning, TEXT("-- UGame_EntityHandler::GetClassUID_Implementation | should be implemented in sub-class"));

	return TEXT("classUID error");
}

void UGame_EntityHandler::UpdateEntity_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

	PageOutEntity(virtualObjective, result);

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->LoadEntity(virtualObjective, entityUID);
	}
}

void UGame_EntityHandler::SetEntityDetailStatus_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, int32 detailStatus)
{
	switch (detailStatus)
	{
		case 0:
			PageOutEntity(virtualObjective, result);
			break;

		case 1:
			PageInEntity(virtualObjective, result);
			break;

		default:
			break;
	}
}

void UGame_EntityHandler::SetEntityVisibility_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, bool bVisible)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	
	virtualObjective->SetEntityVisibility(entityUID, bVisible);
}

void UGame_EntityHandler::GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues)
{

}

void UGame_EntityHandler::DeleteEntity_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	PageOutEntity(virtualObjective, result);
}

void UGame_EntityHandler::SetEntityScale3D_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FVector& scale3D)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	
	virtualObjective->SetEntityScale3D(entityUID, scale3D);
}

void UGame_EntityHandler::PreModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	AVH_GlobeReferenceActor* globeRef = virtualObjective->GetGlobeReference();

	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	
	TSet<AActor*> actors = virtualObjective->GetActorsForEntity(entityUID);

	for (AActor* actor : actors)
	{
		FGeodeticCoord3D coord = globeRef->WorldToGeodeticDouble(actor->GetActorLocation());
		ActorToLocation.Add(actor, coord);
	}
}

void UGame_EntityHandler::PostModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	AVH_GlobeReferenceActor* globeRef = virtualObjective->GetGlobeReference();

	for (const TPair<AActor*, FGeodeticCoord3D>& entry : ActorToLocation)
	{
		FVector worldLocation = globeRef->GeodeticToWorldDouble(entry.Value);
		entry.Key->SetActorLocation(worldLocation);
	}

	ActorToLocation.Empty();
}

void UGame_EntityHandler::SnapEntityToGround_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{

}

void UGame_EntityHandler::GetGoToCoord_Implementation(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate)
{
	TArray<double> northWestBB = UDatabase_Spatialite::GetPoint(TEXT("northWestBB"), result.Result);
	TArray<double> southEastBB = UDatabase_Spatialite::GetPoint(TEXT("southEastBB"), result.Result);

	coordinate.Longitude = (northWestBB[0] + southEastBB[0]) / 2;
	coordinate.Latitude = (northWestBB[1] + southEastBB[1]) / 2;
	coordinate.Altitude = 0;
}

TMap<FString, FString> UGame_EntityHandler::GetHashesToSyncForMUC_Implementation(const FSpatialiteResult_BP& result)
{
	TMap<FString, FString> hashes;

	FString fullPathToZipArchive;
	FMD5Hash md5Hash;
	if (UGame_ImportManager::GetZipReference(result, fullPathToZipArchive, md5Hash))
	{
		hashes.Add(LexToString(md5Hash), fullPathToZipArchive);
	}
	else
	{
		// todo ohg | implement?  or communicate that it's not going to work to the user
	}

	return hashes;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool UGame_EntityHandler::IsReadyForFinishDestroy()
{
	return Super::IsReadyForFinishDestroy() && DestroyCounter.GetValue() == 0;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_EntityHandler::PageOutEntity(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

	virtualObjective->PageOutEntity(entityUID);
}

FString UGame_EntityHandler::GetFilenameFromEntityUID(const FString& entityUID, const FSpatialiteResult_BP& result) const
{
	return entityUID;
}

void UGame_EntityHandler::PageInEntity(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	auto updateInProgress = [this](const FString& entityUID, bool bAdd)
	{
		FScopeLock lock(&InProgressCritSection);

		if (bAdd)
		{
			InProgressPageIns.Add(entityUID);
		}
		else
		{
			InProgressPageIns.Remove(entityUID);
		}
	};

	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);

	if (virtualObjective->IsEntityPagedIn(entityUID) || InProgressPageIns.Contains(entityUID))
	{
		return;
	}

	FString fullPathToFile = GetFilenameFromEntityUID(entityUID, result);

	if (FPaths::FileExists(*fullPathToFile))
	{
		PageInFile(virtualObjective, result, fullPathToFile);
	}
	else
	{
		// get md5 from blob data and compare to other files
		FMD5Hash md5Hash;

		FMemoryReader fromBinary = FMemoryReader(blobData);
		fromBinary << md5Hash;
		
		// check if already have a file for this hash
		if (UGame_GameInstance* gi = UGame_GameInstance::Get())
		{
			FString file;
			if (gi->GetFileFromHash(md5Hash, file))
			{
				PageInFile(virtualObjective, result, file);

				return;
			}
		}

		updateInProgress(entityUID, true);

		Async(EAsyncExecution::ThreadPool, [this, updateInProgress, entityUID, md5Hash, virtualObjective, blobData, result]()
		{
			DestroyCounter.Increment();

			if (!IsSafeToExecute())
			{
				updateInProgress(entityUID, false);

				DestroyCounter.Decrement();
				return;
			}

			FString fullPath = UGame_Statics::GetVTAKTempPath();

			TArray<FString> files;
			UVH_FileIOStatics::GetFilesInPath(files, fullPath, TEXT(""), true, true, true);

			UGame_GameInstance* gi = UGame_GameInstance::Get();

			FString fileToImport = TEXT("");
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
					fileToImport = file;
					break;
				}
			}

			AsyncTask(ENamedThreads::GameThread, [this, updateInProgress, fileToImport, virtualObjective, entityUID, blobData, result]()
			{
				DestroyCounter.Increment();

				if (!IsSafeToExecute())
				{
					updateInProgress(entityUID, false);

					DestroyCounter.Decrement();
					return;
				}

				if (!fileToImport.IsEmpty())
				{
					PageInFile(virtualObjective, result, fileToImport);

					// page in occurs after async block, so scale and hidden may have already been called from VO
					virtualObjective->SetScaleFor(entityUID);

					virtualObjective->SetVisibilityFor(entityUID);

					updateInProgress(entityUID, false);
				}
				else
				{
					// can't find a valid file
					UE_LOG(Game, Warning, TEXT("-- UGame_EntityHandler::PageInEntity | md5Hash in database did not match md5Hash from any files in cache with same extension | %s"), *entityUID);

					updateInProgress(entityUID, false);
				}

				DestroyCounter.Decrement();
			});

			DestroyCounter.Decrement();
		});
	}
}

void UGame_EntityHandler::PageInFile(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FString& fullPathToFile)
{

}

bool UGame_EntityHandler::IsSafeToExecute()
{
	if (!IsValidLowLevelFast() || HasAnyFlags(RF_BeginDestroyed) || GetClass() == nullptr)
	{
		return false;
	}

	return true;
}
