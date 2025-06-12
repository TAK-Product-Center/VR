#include "Game_EntityHandler_PointCloud.h"

#include "Misc/SecureHash.h"
#include "LidarPointCloud.h"
#include "LidarPointCloudComponent.h"
#include "IO/LidarPointCloudFileIO.h"

#include "VH_GlobeReferenceActor.h"
#include "Developer_Statics.h"
#include "VH_FileIOStatics.h"
#include "VH_GeodeticCoord.h"

#include "Game.h"
#include "Game_ImportManager.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_PointCloudActor.h"
#include "Game_EntityDB.h"
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_EntityHandler_PointCloud::UGame_EntityHandler_PointCloud()
{
}

// ---------------------------------
// --- Interface_EntityHandler
// ---------------------------------

void UGame_EntityHandler_PointCloud::PageInFileWithDefaultSettings_Implementation(AGame_VirtualObjective* virtualObjective, const FString& entityUID, const FString& fullPathToFile)
{
	if (ULidarPointCloudFileIO::FindHandlerByFilename(fullPathToFile))
	{
		// xyz could be something other than a pointcloud; verify it's a valid pointcloud
		if (FPaths::GetExtension(fullPathToFile).Equals(TEXT("xyz"), ESearchCase::IgnoreCase))
		{
			TArray<FString> fileContents;
			FFileHelper::LoadFileToStringArray(fileContents, *fullPathToFile);

			if (fileContents.Num() == 1)
			{
				return;
			}
		}

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

void UGame_EntityHandler_PointCloud::GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues)
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

bool UGame_EntityHandler_PointCloud::RegisterFileToDatabaseSecondPass_Implementation(const FString& fullPathToFile, TSet<FString>& registeredEntityUIDs)
{
	if (ULidarPointCloudFileIO::FindHandlerByFilename(fullPathToFile))
	{
		// xyz could be something other than a pointcloud; verify it's a valid pointcloud
		if (FPaths::GetExtension(fullPathToFile).Equals(TEXT("xyz"), ESearchCase::IgnoreCase))
		{
			TArray<FString> fileContents;
			FFileHelper::LoadFileToStringArray(fileContents, *fullPathToFile);

			if (fileContents.Num() == 1)
			{
				return false;
			}
		}

		FGeodeticCoord3D coordinate;
		if (UGame_ImportManager::GetGeoLocationForFile(fullPathToFile, coordinate))
		{
			float pointSize = 1;
			ELidarPointCloudColorationMode colorSource = ELidarPointCloudColorationMode::Data;

			FBufferArchive toBinary;
			toBinary << pointSize;
			toBinary << colorSource;

			TArray<uint8> data = (TArray<uint8>&)toBinary;

			UGame_EntityDB* entityDB = UGame_EntityDB::Get();

			FGeodeticCoord2D geodeticCoordinate2D = coordinate.ToGeodeticCoord2D();
			entityDB->InsertOrUpdate(fullPathToFile, UGame_EntityHandler_PointCloud::StaticGetClassUID(), TEXT("pointcloud"), geodeticCoordinate2D, geodeticCoordinate2D, data);

			registeredEntityUIDs.Add(fullPathToFile);

			return true;
		}
	}

	return false;
}

void UGame_EntityHandler_PointCloud::PageInFile(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FString& fullPathToFile)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);

	UGame_ImportManager::ExtractIfNecessary(entityUID, fullPathToFile);

	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AGame_PointCloudActor* pointCloudActor = UDeveloper_Statics::GetVHWorld()->SpawnActor<AGame_PointCloudActor>(*PointCloudActorBlueprint, spawnParams);

	virtualObjective->AddObjectToEntity(entityUID, pointCloudActor);

	pointCloudActor->SetFile(fullPathToFile);

	FGeodeticCoord3D coordinate;
	if (UGame_ImportManager::GetGeoLocationForFile(fullPathToFile, coordinate))
	{
		if (AVH_GlobeReferenceActor* globeRef = virtualObjective->GetGlobeReference())
		{
			FVector worldLocation = globeRef->GeodeticToWorldDouble(coordinate);

			pointCloudActor->SetActorLocation(worldLocation);

			FTransform transform = UGame_Statics::GetWorldTransformOverride(coordinate);
			pointCloudActor->SetActorRotation(transform.TransformRotation(FRotator(0, 90, 0).Quaternion()));
		}
	}

	if (ULidarPointCloudComponent* component = pointCloudActor->GetPointCloudComponent())
	{
		if (blobData.Num() > 0)
		{
			float pointSize;
			ELidarPointCloudColorationMode colorSource;

			FMemoryReader fromBinary = FMemoryReader(blobData);
			fromBinary.Seek(0);
			
			fromBinary << pointSize;
			fromBinary << colorSource;

			component->PointSize = pointSize;
			component->ColorSource = colorSource;
		}
	}
}
