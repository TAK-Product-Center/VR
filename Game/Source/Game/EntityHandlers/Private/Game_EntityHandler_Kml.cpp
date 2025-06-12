// Required Includes
#include "Game_EntityHandler_Kml.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "VH_FileIOStatics.h"
#include "VH_KmlInfo.h"
#include "VH_KmlTypes.h"
#include "VH_KmlPlacemark.h"
#include "VH_KmlFeature.h"
#include "VH_KmlGeometry.h"
#include "VH_KmlModel.h"
#include "Interface_COTReceiver.h"

// Game Includes
#include "Game_COTComponent_GRG.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_Statics.h"
#include "Game_PlayerState.h"
#include "Game_ImportManager.h"
#include "Game_PlayerController.h"
#include "Game_EntityDB.h"
#include "Game_AdjustableModelImportComponent.h"
#include "Game_Actor_KmlPlacemark.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_EntityHandler_Kml::UGame_EntityHandler_Kml()
{

}

// ---------------------------------
// --- Interface_EntityHandler
// ---------------------------------

void UGame_EntityHandler_Kml::PageInFileWithDefaultSettings_Implementation(AGame_VirtualObjective* virtualObjective, const FString& entityUID, const FString& fullPathToFile)
{
	if (FPaths::GetExtension(fullPathToFile).Equals(TEXT("kml"), ESearchCase::IgnoreCase))
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

void UGame_EntityHandler_Kml::GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);
	
	FString fullPathToZipArchive;
	FMD5Hash md5HashZip;
	if (UGame_ImportManager::GetZipReference(result, fullPathToZipArchive, md5HashZip))
	{
		keyValues.Add(TEXT("displayName"), FPaths::GetBaseFilename(fullPathToZipArchive) + TEXT(" - ") + FPaths::GetBaseFilename(entityUID));
	}
	else
	{
		keyValues.Add(TEXT("displayName"), FPaths::GetBaseFilename(entityUID));
	}

    keyValues.Add(TEXT("type"), FPaths::GetExtension(entityUID));

	FMemoryReader fromBinary = FMemoryReader(blobData);
	fromBinary.Seek(0);

	FString numItems;

	fromBinary << numItems;

    TArray<FString> dataArray;
    numItems.ParseIntoArray(dataArray, TEXT("|"), true);
    keyValues.Add(TEXT("numItemsText"), (dataArray.Num() > 0) ? dataArray[0] : TEXT(""));
}

void UGame_EntityHandler_Kml::PreModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
	{
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

		TSet<UObject*> objects = virtualObjective->GetObjectsForEntity(entityUID);

		ActorToLocation.Empty();
		for (UObject* object : objects)
		{
			if (AActor* actor = Cast<AActor>(object))
			{
				FGeodeticCoord3D coord = globeReference->WorldToGeodeticDouble(actor->GetActorLocation());
				
				ActorToLocation.Add(actor, coord);
			}
		}
	}
}

void UGame_EntityHandler_Kml::PostModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	for (const TPair<AActor*, FGeodeticCoord3D>& entry : ActorToLocation)
	{
		FVector worldLocation = virtualObjective->GetGlobeReference()->GeodeticToWorldDouble(entry.Value);
		entry.Key->SetActorLocation(worldLocation);
	}
}

void UGame_EntityHandler_Kml::SnapEntityToGround_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	
}

bool UGame_EntityHandler_Kml::RegisterFileToDatabaseFirstPass_Implementation(const FString& fullPathToFile, TSet<FString>& registeredEntityUIDs)
{
	if (!FPaths::GetExtension(fullPathToFile).Equals(TEXT("kml"), ESearchCase::IgnoreCase))
	{
		return false;
	}
	
	if (UVH_KmlInfo* kmlInfo = UVH_KmlInfo::Create(fullPathToFile))
	{
		TArray<FKmlFeature*> features;
		kmlInfo->GetAllFeatures(features, EKmlElementType::Placemark, true);

		int32 numItems = features.Num();
		FString dataString = FString::Printf(TEXT("%d %s"), numItems, (numItems == 1) ? TEXT("item") : TEXT("items"));

		FBufferArchive toBinary;
		toBinary << dataString;

		FMD5Hash md5Hash = FMD5Hash::HashFile(*fullPathToFile);
		toBinary << md5Hash;

		FGeodeticCoord3D coordinate;
		if (!kmlInfo->GetCenterCoordinate(coordinate))
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

		UGame_AdjustableModelImportComponent::AddDefaultRubbersheetData(toBinary, coordinate);

		TArray<uint8> data = (TArray<uint8>&)toBinary;

		FGeodeticCoord2D geodeticCoordinate2D = coordinate.ToGeodeticCoord2D();
		
		FString overlayCategory = TEXT("kml");
		
		TArray<FKmlFeature*> groundOverlayFeatures;
		kmlInfo->GetAllFeatures(groundOverlayFeatures, EKmlElementType::GroundOverlay, true);
		
		if (groundOverlayFeatures.Num() > 0)
		{
			overlayCategory = TEXT("grg");
		}

		UGame_EntityDB* entityDB = UGame_EntityDB::Get();
		entityDB->InsertOrUpdate(fullPathToFile, UGame_EntityHandler_Kml::StaticGetClassUID(), FName(*overlayCategory), geodeticCoordinate2D, geodeticCoordinate2D, data);
		entityDB->SetEntityDataVersion(fullPathToFile, TEXT("1|"));

		registeredEntityUIDs.Add(fullPathToFile);

		return true;
	}
	else if (kmlInfo == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("UGame_EntityHandler_Kml::RegisterFileToDatabaseFirstPass_Implementation -- kmlInfo was nullptr"));
	}

	return false;
}

void UGame_EntityHandler_Kml::PageInFile(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FString& fullPathToFile)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

	AsyncTask(ENamedThreads::AnyThread, [this, virtualObjective, entityUID, fullPathToFile]()
	{
		UGame_ImportManager::ExtractIfNecessary(entityUID, fullPathToFile);

		if (UVH_KmlInfo* kmlInfo = UVH_KmlInfo::Create(fullPathToFile))
		{
			AsyncTask(ENamedThreads::GameThread, [this, virtualObjective, kmlInfo, entityUID]()
			{
				// attempt to load as GRG first
				if (!PageInGRG(virtualObjective, entityUID, kmlInfo))
				{
					// load as non-GRG
					PageInNonGRG(virtualObjective, entityUID, kmlInfo);
				}
			});
		}
	});
}

void UGame_EntityHandler_Kml::GetGoToCoord_Implementation(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate)
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

// ---------------------------------
// --- Implementation
// ---------------------------------

bool UGame_EntityHandler_Kml::PageInGRG(AGame_VirtualObjective* virtualObjective, const FString& entityUID, UVH_KmlInfo* kmlInfo)
{
	if (UWorld* world = UDeveloper_Statics::GetVHWorld())
	{
		const FKmlDocument& kmlDoc = kmlInfo->GetKmlDocument();
		if (kmlDoc.FeatureListMap.Contains(EKmlElementType::GroundOverlay))
		{
			// todo ohg | assuming GRG here, need to ask user to import as GRG or image
			FActorSpawnParameters spawnParams;
			spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			AActor* grgActor = world->SpawnActor<AActor>(*GRGActorBlueprint, spawnParams);

			if (UGame_COTComponent_GRG* grgComponent = Cast<UGame_COTComponent_GRG>(IInterface_COTReceiver::Execute_GetCOTComponent(grgActor)))
			{
				virtualObjective->AddObjectToEntity(entityUID, grgActor);

				grgComponent->LoadFromKML(kmlInfo);
			}
			else
			{
				UE_LOG(Game, Warning, TEXT("UGame_EntityHandler_Kml::LoadGRGFromKML | GRGActorBlueprint does not have Game_COTComponent_GRG"));
			}

			return true;
		}
	}

	return false;
}

void UGame_EntityHandler_Kml::PageInNonGRG(AGame_VirtualObjective* virtualObjective, const FString& entityUID, UVH_KmlInfo* kmlInfo)
{
	if (KmlActorClass != nullptr)
	{
		TArray<FKmlFeature*> features;
		kmlInfo->GetAllFeatures(features, EKmlElementType::Placemark, true);

		if (UWorld* world = UDeveloper_Statics::GetVHWorld())
		{
			for (FKmlFeature* feature : features)
			{
				if (FKmlPlacemark* kmlPlacemark = (FKmlPlacemark*)feature)
				{
					FActorSpawnParameters spawnParameters;
					spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

					AGame_Actor_KmlPlacemark* kmlPlacemarkActor = Cast<AGame_Actor_KmlPlacemark>(world->SpawnActor(KmlActorClass, nullptr, spawnParameters));
					
					virtualObjective->AddObjectToEntity(entityUID, kmlPlacemarkActor);
					
					kmlPlacemarkActor->PopulateFromKml(virtualObjective, kmlInfo, kmlPlacemark);
				}
			}

			virtualObjective->SetScaleFor(entityUID);
			virtualObjective->SetVisibilityFor(entityUID);
		}
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_EntityHandler_Kml::PageInNonGRG | KmlActorClass is nullptr | aborting"));
	}
}