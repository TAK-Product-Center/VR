// Required Includes
#include "Game_EntityHandler_File.h"
#include "Game.h"

// Engine Includes
#include "Misc/SecureHash.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "Developer_Statics.h"
#include "VH_FileIOStatics.h"
#include "VH_FileIOTypes.h"
#include "VH_MeshInfo.h"

// Game Includes
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_GameInstance.h"
#include "Game_EntityDB.h"
#include "Game_ImportManager.h"
#include "Game_Statics.h"
#include "Game_PlayerController.h"
#include "Game_Actor_File.h"
#include "Game_AdjustableModelImportComponent.h"
#include "Game_PlayerState.h"
#include "Game_TileManager.h"
#include "Game_ImportedMeshComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_EntityHandler_File::UGame_EntityHandler_File()
{
	ActorClass = AGame_Actor_File::StaticClass();
}

// ---------------------------------
// --- Interface_EntityHandler
// ---------------------------------

void UGame_EntityHandler_File::PageInFileWithDefaultSettings_Implementation(AGame_VirtualObjective* virtualObjective, const FString& entityUID, const FString& fullPathToFile)
{
	FString extension = FPaths::GetExtension(fullPathToFile).ToLower();

	if (extension.Equals(TEXT("b3dm")))
	{
		if (!UGame_Statics::ConvertB3DMToGLBInPlace(fullPathToFile))
		{
			FString fullPathToGLB = FPaths::Combine(FPaths::GetPath(fullPathToFile), FString::Printf(TEXT("%s.glb"), *FPaths::GetBaseFilename(fullPathToFile)));

			PageInFileWithDefaultSettings(virtualObjective, entityUID, fullPathToGLB);
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_EntityHandler_File::PageInFileWithDefaultSettings_Implementation | unable to convert b3dm to glb | fullPathToFile: %s | aborting"), *fullPathToFile);
		}

		return;
	}

	if (extension.Equals(TEXT("obj")) || 
		extension.Equals(TEXT("fbx")) ||
		extension.Equals(TEXT("dae")) ||
		extension.Equals(TEXT("glb")) ||
		extension.Equals(TEXT("gltf")))
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

void UGame_EntityHandler_File::GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues)
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

bool UGame_EntityHandler_File::RegisterFileToDatabaseSecondPass_Implementation(const FString& fullPathToFile, TSet<FString>& registeredEntityUIDs)
{
	FString extension = FPaths::GetExtension(fullPathToFile).ToLower();

	if (extension.Equals(TEXT("b3dm")))
	{
		if (UGame_Statics::ConvertB3DMToGLBInPlace(fullPathToFile))
		{
			FString fullPathToGLB = FPaths::Combine(FPaths::GetPath(fullPathToFile), FString::Printf(TEXT("%s.glb"), *FPaths::GetBaseFilename(fullPathToFile)));

			return Execute_RegisterFileToDatabaseSecondPass(this, fullPathToGLB, registeredEntityUIDs);
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_EntityHandler_File::RegisterFileToDatabaseSecondPass_Implementation | unable to convert b3dm to glb | fullPathToFile: %s | aborting"), *fullPathToFile);

			return false;
		}
	}

	if (!extension.Equals(TEXT("obj")) &&
		!extension.Equals(TEXT("fbx")) &&
		!extension.Equals(TEXT("dae")) &&
		!extension.Equals(TEXT("glb")) &&
		!extension.Equals(TEXT("gltf")))
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
	
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();

	FBufferArchive toBinary;
	
	FMD5Hash md5Hash = FMD5Hash::HashFile(*fullPathToFile);
	toBinary << md5Hash;

	UGame_AdjustableModelImportComponent::AddDefaultRubbersheetData(toBinary, coordinate);
	
	TArray<uint8> data = (TArray<uint8>&)toBinary;

	FGeodeticCoord2D geodeticCoordinate2D = coordinate.ToGeodeticCoord2D();
	entityDB->InsertOrUpdate(fullPathToFile, UGame_EntityHandler_File::StaticGetClassUID(), TEXT("3d_model"), geodeticCoordinate2D, geodeticCoordinate2D, data);
	entityDB->SetEntityDataVersion(fullPathToFile, TEXT("1|"));
	
	registeredEntityUIDs.Add(fullPathToFile);

	return true;
}

void UGame_EntityHandler_File::PageInFile(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FString& fullPathToFile)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);

	UGame_ImportManager::ExtractIfNecessary(entityUID, fullPathToFile);

	FTransform spawnTransform = FTransform::Identity;

	AGame_Actor_File* fileActor = UDeveloper_Statics::GetVHWorld()->SpawnActorDeferred<AGame_Actor_File>(ActorClass, spawnTransform, nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	if (fileActor != nullptr)
	{
		virtualObjective->AddObjectToEntity(entityUID, fileActor);

		if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
		{
			FGeodeticCoord3D coordinate;
			if (UGame_AdjustableModelImportComponent::GetUnloadedEntityGeoLocation(entityUID, coordinate))
			{
				fileActor->SetActorLocation(globeReference->GeodeticToWorldDouble(coordinate));
			}
		}

		FVH_MeshImportOptions importOptions;
		importOptions = UVH_MeshInfo::GetDefaultImportOptions(entityUID);

		fileActor->LoadFromFile(fullPathToFile, importOptions);

		UGameplayStatics::FinishSpawningActor(fileActor, spawnTransform);
	}
}

void UGame_EntityHandler_File::GetGoToCoord_Implementation(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate)
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
