#include "Game_EntityHandler_Hivemapper.h"

#include "VH_GlobeReferenceActor.h"
#include "VH_FileIOStatics.h"

#include "Game.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_GameInstance.h"
#include "Game_Statics.h"
#include "Game_HandlerService.h"
#include "Game_EntityDB.h"
#include "Game_PlayerController.h"
#include "Game_ImportManager.h"
#include "Game_AdjustableModelImportComponent.h"
#include "Game_TileManager.h"
#include "Game_PlayerState.h"
#include "Game_PlayerController.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_EntityHandler_Hivemapper::UGame_EntityHandler_Hivemapper()
{

}

// ---------------------------------
// --- Interface_EntityHandler
// ---------------------------------

void UGame_EntityHandler_Hivemapper::PageInFileWithDefaultSettings_Implementation(AGame_VirtualObjective* virtualObjective, const FString& entityUID, const FString& fullPathToFile)
{
	if (FPaths::GetExtension(fullPathToFile).Equals(TEXT("xml"), ESearchCase::IgnoreCase))
	{
		FSpatialiteResult_BP result;

		FVariant entityUIDVariant = entityUID;
		result.Result.Add(TEXT("entityUID"), entityUIDVariant);

		TArray<uint8> blobData;
		result.Result.Add(TEXT("blobData"), entityUIDVariant);

		PageInFile(virtualObjective, result, fullPathToFile);
	}
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_EntityHandler_Hivemapper::GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues)
{
	Super::GetEntityOverlayInfo_Implementation(result, keyValues);

	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	
	FString fullPathToZipArchive;
	FMD5Hash md5Hash;
	if (UGame_ImportManager::GetZipReference(result, fullPathToZipArchive, md5Hash))
	{
		keyValues.Add(TEXT("displayName"), FPaths::GetBaseFilename(fullPathToZipArchive) + TEXT(" - ") + FPaths::GetBaseFilename(entityUID));
	}
	else
	{
		keyValues.Add(TEXT("displayName"), FPaths::GetBaseFilename(entityUID));
	}
}

bool UGame_EntityHandler_Hivemapper::RegisterFileToDatabaseFirstPass_Implementation(const FString& fullPathToFile, TSet<FString>& registeredEntityUIDs)
{
	if (!FPaths::GetExtension(fullPathToFile).Equals(TEXT("xml"), ESearchCase::IgnoreCase))
	{
		return false;
	}

	FGeodeticCoord3D coordinate;
	if (!UGame_ImportManager::GetGeoLocationForFile(fullPathToFile, coordinate))
	{
		if (AGame_VirtualObjective* activeVO = AGame_PlayerController::GetPlayerActiveVO())
		{
			if (AVH_GlobeReferenceActor* globeRef = activeVO->GetGlobeReference())
			{
				FVector spawnLocation;

				if (UGame_Statics::GetLocalPlayerState()->GetIsInTOC())
				{
					// in TOC, VO's viewpointActor is center of TOC table
					spawnLocation = activeVO->GetViewpointActor()->GetActorLocation();
				}
				else
				{
					// spawn 500 units in front of the player
					APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

					FVector playerLocation;
					FRotator playerRotation;
					playerPawn->Controller->GetPlayerViewPoint(playerLocation, playerRotation);

					spawnLocation = playerLocation + (playerRotation.Vector() * 500);
				}

				coordinate = globeRef->WorldToGeodeticDouble(spawnLocation);
			}
		}
	}
	
	FBufferArchive toBinary;

	FMD5Hash md5Hash = FMD5Hash::HashFile(*fullPathToFile);
	toBinary << md5Hash;

	UGame_AdjustableModelImportComponent::AddDefaultRubbersheetData(toBinary, coordinate);

	TArray<uint8> data = (TArray<uint8>&)toBinary;

	FGeodeticCoord2D coordinate2D = coordinate.ToGeodeticCoord2D();

	UGame_EntityDB* entityDB = UGame_EntityDB::Get();
	entityDB->InsertOrUpdate(fullPathToFile, UGame_EntityHandler_Hivemapper::StaticGetClassUID(), TEXT("hivemapper"), coordinate2D, coordinate2D, data);
	entityDB->SetEntityDataVersion(fullPathToFile, TEXT("1|"));

	registeredEntityUIDs.Add(fullPathToFile);
	
	return true;
}

void UGame_EntityHandler_Hivemapper::PageInFile(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FString& fullPathToFile)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);

	UGame_ImportManager::ExtractIfNecessary(entityUID, fullPathToFile);

	// determine if dataset is in expected format (models with name Tile_..._L..)
	TArray<FString> files;
	UVH_FileIOStatics::GetFilesInPath(files, FPaths::GetPath(fullPathToFile), TEXT(""), true, true, true);

	bool bExpectedFormat = false;
	for (const FString& file : files)
	{
		FString filename = FPaths::GetBaseFilename(file);
		if (filename.StartsWith(TEXT("Tile_"), ESearchCase::IgnoreCase) && filename.Contains(TEXT("_L"), ESearchCase::IgnoreCase))
		{
			bExpectedFormat = true;
			break;
		}
	}

	// get geolocation
	FGeodeticCoord3D coordinate;
	UGame_AdjustableModelImportComponent::GetUnloadedEntityGeoLocation(entityUID, coordinate);
	
	// get models to page in
	IFileManager& fileManager = IFileManager::Get();

	TSet<FString> modelsToPageIn;
	if (bExpectedFormat)
	{
		FString basePath = FPaths::GetPath(fullPathToFile);

		TArray<FString> paths;
		UVH_FileIOStatics::GetDirectoriesInPath(paths, basePath, false, true, true);
		
		for (const FString& path : paths)
		{
			TArray<FString> tilePaths;
			UVH_FileIOStatics::GetDirectoriesInPath(tilePaths, path, false, true, true);

			for (const FString& tilePath : tilePaths)
			{
				TArray<FString> modelfiles;
				UVH_FileIOStatics::GetFilesInPath(modelfiles, tilePath, TEXT("obj,fbx,dae"), false, true, true);

				// find model with highest LOD and add it to modelsToPageIn
				int32 highestLOD = -1;
				FString modelToPageIn = TEXT("");
				for (const FString& file : modelfiles)
				{
					FString filename = FPaths::GetBaseFilename(file);

					TArray<FString> parsed;
					filename.ParseIntoArray(parsed, TEXT("_"));

					if (parsed.Last().StartsWith(TEXT("L")))
					{
						int32 lod = FCString::Atoi(*(parsed.Last().RightChop(1)));
						if (lod > highestLOD)
						{
							modelToPageIn = file;

							highestLOD = lod;
						}
					}
				}

				if (!modelToPageIn.IsEmpty())
				{
					modelsToPageIn.Add(modelToPageIn);
				}
			}
		}
	}
	else
	{
		TArray<FString> modelFiles;
		UVH_FileIOStatics::GetFilesInPath(modelFiles, FPaths::GetPath(fullPathToFile), TEXT(""), true, true, true);

		for (const FString& file : modelFiles)
		{
			if (!FPaths::GetExtension(file).Equals(TEXT("xml"), ESearchCase::IgnoreCase))
			{
				modelsToPageIn.Add(file);
			}
		}
	}

	if (UGame_HandlerService* handlerService = UGame_HandlerService::Get())
	{
		TArray<UObject*> entityHandlers = handlerService->GetAllEntityHandlers();

		for (const FString& modelToPageIn : modelsToPageIn)
		{
			for (UObject* entityHandler : entityHandlers)
			{
				IInterface_EntityHandler::Execute_PageInFileWithDefaultSettings(entityHandler, virtualObjective, entityUID, modelToPageIn);
			}
		}
	}
}

void UGame_EntityHandler_Hivemapper::GetGoToCoord_Implementation(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

	bool bValidCoordinate = true;
	if (!UGame_AdjustableModelImportComponent::GetUnloadedEntityGeoLocation(entityUID, coordinate))
	{
		if (!UGame_ImportManager::GetGeoLocationForFile(entityUID, coordinate))
		{
			bValidCoordinate = false;
		}
	}

	if (!bValidCoordinate)
	{
		Super::GetGoToCoord_Implementation(result, coordinate);
	}
}

