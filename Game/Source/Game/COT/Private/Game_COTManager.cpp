// Required Includes
#include "Game_COTManager.h"
#include "Game.h"

// Engine Includes
#include "Containers/UnrealString.h"

// VH Plugin Includes
#include "Interface_COTReceiver.h"
#include "VH_COTComponent.h"
#include "Developer_Subsystem_Notification.h"
#include "VH_COTUserIcons.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"
#include "VH_COTStatics.h"

// Game Includes
#include "Game_DataSync.h"
#include "Game_DataPackage.h"
#include "Game_HandlerService.h"
#include "Interface_EntityHandler.h"
#include "Game_EntityHandler_COT.h"
#include "Game_EntityHandler_File.h"
#include "Game_EntityHandler_Kml.h"
#include "Game_PlayerController.h"
#include "Game_COTComponent.h"
#include "Game_Statics.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_COTComponent_DrawRangeBearing.h"
#include "Game_VehicleRepresentative.h"
#include "Game_ImportManager.h"
#include "Game_Subsystem_Core.h"
#include "Game_TOCBoardDB.h"
#include "Game_CameraScalingComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_COTManager::UGame_COTManager() :
	bBlockIncomingAtomCOTsExceptDataSyncs(true),
    HeartbeatCooldown(15.f)
{
    DataSyncClass = UGame_DataSync::StaticClass();
    DataPackageClass = UGame_DataPackage::StaticClass();
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UVH_COTManager* UGame_COTManager::Create(TSubclassOf<class UVH_COTManager> managerClass, bool bLoadTOCBoards)
{
	if (GlobalInstance == nullptr)
	{
		if (UVH_COTManager* cotManager = NewObject<UVH_COTManager>(GetTransientPackage(), managerClass))
		{
			cotManager->Initialize();

			if (bLoadTOCBoards)
			{
				if (UGame_TOCBoardDB* tocBoardDB = UGame_TOCBoardDB::Get())
				{
					tocBoardDB->LoadConfiguration(tocBoardDB->GetCurrentConfiguration());
				}
			}

			return cotManager;
		}

		UE_LOG(Game, Warning, TEXT("-- UGame_COTManager::Create | could not create COT Manager"));
		return nullptr;
	}

	return GlobalInstance;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_COTManager::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	if (APawn* pawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
	{
		FVector playerLocation = pawn->GetActorLocation();
		HeartbeatCooldown = (playerLocation == CachedPlayerLocation) ? 15.f : 0.5f;

		CachedPlayerLocation = playerLocation;

		if (HeartbeatCounter > HeartbeatCooldown)
		{
			HeartbeatCounter = HeartbeatCooldown;
		}
	}
}

UVH_COTEvent* UGame_COTManager::GetCotEventFromUID(const FString& entityUID) const
{
	// create the UVH_COTEvent from the database blob

	SpatialiteResults results = UGame_EntityDB::Get()->QueryUID(entityUID);
	if (results.Num() > 1)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_COTManager::GetCotEventFromUID | multiple results returned for uid: %s"), *entityUID);
	}

	if (results.Num() > 0)
	{
		// check the result has COT classUID
		FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), results[0]);
			
		if (classUID.Equals(UGame_EntityHandler_COT::StaticGetClassUID()))
		{
			TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), results[0]);

			if (blobData.Num() > 0)
			{
				// convert blob to COTEvent
				FMemoryReader fromBinary = FMemoryReader(blobData);
				fromBinary.Seek(0);

				FString xml;
				fromBinary << xml;

				if (!fromBinary.IsCriticalError())
				{
					// populate cotEvent
					UVH_COTEvent* cotEvent = NewObject<UVH_COTEvent>();
					cotEvent->PopulateFromXML(xml);

					return cotEvent;
				}
				else
				{
					UE_LOG(Game, Warning, TEXT("-- UGame_COTManager::GetCotEventFromUID | memory archive has critical error"));
				}
			}
		}
	}

	// not in database or not a COT entity
	return nullptr;
}

void UGame_COTManager::Notify(const FString& message, float duration) const
{
	if (UDeveloper_Subsystem_Notification* subsystem = UDeveloper_Subsystem_Notification::Get())
	{
		subsystem->AddNotification(FNotificationData(message, duration, true));
	}
}

FGeodeticCoord3D UGame_COTManager::GetGeodeticLocation() const
{
	FGeodeticCoord3D geoLocation(0, 0, 0);

	if (AGame_VirtualObjective* activeVO = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AVH_GlobeReferenceActor* globeRef = activeVO->GetGlobeReference())
		{
			if (APawn* pawn = UGame_Statics::GetVHPlayerController()->GetPawn())
			{
				geoLocation = globeRef->WorldToGeodeticDouble(pawn->GetActorLocation());
			}
		}
	}

	return geoLocation;
}


void UGame_COTManager::StoreSettings() const
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingString(TEXT("callsign"), Callsign);
		gameSettings->StoreSettingString(TEXT("UID"), UID.ToString());
	}
}

void UGame_COTManager::LoadSettings()
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		Callsign = gameSettings->GetSettingString(TEXT("callsign"));
		//Callsign = FString::Printf(TEXT("abba%d"), FMath::RandRange(0, 1000)); // debug
		UID = FName(*gameSettings->GetSettingString(TEXT("UID")));
		
		HeartbeatCoordinate.FromString(gameSettings->GetSettingString(TEXT("HeartbeatCoordinate")));
	}
}

void UGame_COTManager::HandleAtomEvent_Virtual(UVH_COTEvent* cotEvent)
{
	InsertOrUpdate(cotEvent);
}

TSet<AActor*> UGame_COTManager::GetActorsForEntity(const FString& entityUID) const
{
	TSet<AActor*> actors;

	if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
	{
		actors.Append(voManager->GetActorsForEntityGlobal(entityUID));
	}

	return actors;
}

void UGame_COTManager::RegisterFile(const FString& fullPathToFile)
{
	if (UGame_ImportManager* importManager = Cast<UGame_ImportManager>(UGame_ImportManager::Get()))
	{
		importManager->RegisterFileToDatabase(fullPathToFile);
	}
}

float UGame_COTManager::GetHeartbeatCooldown() const
{
	return HeartbeatCooldown;
}

bool UGame_COTManager::PostInitialize()
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		bBroadcastGhost = gameSettings->GetSettingBool(TEXT("BroadcastName"));
	}

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->OnDelete.AddDynamic(this, &UGame_COTManager::HandleEntityDBDeleteEvent);
	}

	// vehicles
	for (TSubclassOf<AGame_VehicleRepresentative> vehicleBlueprint : VehicleBlueprints)
	{
		//RegisterVehicleClass(vehicleBlueprint);  // todo ohg | calling this causes crash

		AGame_VehicleRepresentative* vehicleObject = vehicleBlueprint.GetDefaultObject();
		VehicleDropperCategories.Add(vehicleObject->DropperCategory);

		if (UVH_COTUserIcons* userIcons = GetUserIcons())
		{
			FString modelName = vehicleObject->ModelName;

			if (!userIcons->ModelToBlueprint.Contains(modelName))
			{
				userIcons->ModelToBlueprint.Add(modelName, vehicleBlueprint);
			}
		}
	}

	if (UGame_HandlerService* handlerService = UGame_HandlerService::Get())
	{
		for (TSubclassOf<UObject> entityHandlerClass : EntityHandlers)
		{
			if (entityHandlerClass->ImplementsInterface(UInterface_EntityHandler::StaticClass()))
			{
				UObject* entityHandler = NewObject<UObject>(GetTransientPackage(), entityHandlerClass);

				handlerService->RegisterEntityHandler(entityHandler, true);
			} 
			else
			{
				UE_LOG(Game, Warning, TEXT("-- UGame_COTManager::PostInitialize | entity handler class does not implement Interface_EntityHandler | skipping"));
			}
		}

		UVH_COTStatics::BroadcastCOTMessage(TEXT("UVH_COTStatics::BroadcastCOTMessage"));
	}

    return true;
}

bool UGame_COTManager::ShouldHandleAtomCOT_Virtual(UVH_COTEvent* cotEvent) const
{
	if (UGame_Statics::IsLocalPlayerInSession())
	{
		if (UVH_COTManager::IsVTAKGhost(cotEvent))
		{
			return true;
		}

		if (vh_cot::GetWorld()->GetNetMode() == NM_Client)
		{
			return false;
		}

		if (bBlockIncomingAtomCOTsExceptDataSyncs)
		{
			TArray<UVH_DataSync*> dataSyncs = GetSortedDataSyncs();
			for (UVH_DataSync* dataSync : dataSyncs)
			{
				if (dataSync->IsSubscribed())
				{
					return dataSync->GetUIDs().Contains(cotEvent->GetAttribute(TEXT("uid")));
				}
			}

			TArray<UVH_DataPackage*> dataPackages = GetDataPackages();
			for (UVH_DataPackage* dataPackage : dataPackages)
			{
				return dataPackage->GetUIDs().Contains(cotEvent->GetAttribute(TEXT("uid")));
			}

			return false;
		}
	}
	
	return true;
}

void UGame_COTManager::SetHeartbeatCoordinate(const FGeodeticCoord3D& coordinate)
{
	Super::SetHeartbeatCoordinate(coordinate);

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingString(TEXT("HeartbeatCoordinate"), coordinate.ToString());
	}
}

// ---------------------------------
// --- API
// ---------------------------------

AActor* UGame_COTManager::PageInEntity(AGame_VirtualObjective* virtualObjective, UVH_COTEvent* cotEvent, int32 detailLevel)
{
	if (virtualObjective != nullptr)
	{
		if (AActor* actor = SpawnActor(cotEvent))
		{
			if (actor->GetClass()->ImplementsInterface(UInterface_COTReceiver::StaticClass()))
			{
				if (bShowInformationLogs)
				{
					UE_LOG(Game, Warning, TEXT("-- UGame_COTManager::PageInEntity | %s"), *cotEvent->GetAttribute(TEXT("uid")));
				}

				virtualObjective->AddObjectToEntity(cotEvent->GetAttribute(TEXT("uid")), actor);

				if (UVH_COTComponent* cotComponent = IInterface_COTReceiver::Execute_GetCOTComponent(actor))
				{
					cotComponent->ReceiveCOTUpdate(cotEvent);

					cotComponent->SnapToGround();
				}
				else
				{
					UE_LOG(Game, Warning, TEXT("-- UGame_COTManager::PageInEntity | COTComponent is nullptr | %s"), *actor->GetName());
				}

				TArray<UActorComponent*> components;
				actor->GetComponents(UGame_CameraScalingComponent::StaticClass(), components);
			}

			return actor;
		}
	}

	return nullptr;
}

void UGame_COTManager::InsertOrUpdate(UVH_COTComponent* cotComponent, bool bForceTransient /* = false */)
{
	cotComponent->PopulateCOT();

	InsertOrUpdate(cotComponent->GetCurrentCOTEvent(), bForceTransient);
}

void UGame_COTManager::InsertOrUpdate(UVH_COTEvent* cotEvent, bool bForceTransient /* = false */)
{
	if (cotEvent == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_COTManager::InsertOrUpdate | cotEvent is nullptr"));
		return;
	}

	//UE_LOG(Game, Warning, TEXT("-- UGame_COTManager::InsertOrUpdate | storing: %s"), *cotEvent->UID.ToString());

	// locally added entities should always display regardless of start/stale (which means <archive> should be present)
	// determine if entity added by local user; if so, add <archive> so start/stale are ignored
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		// entity is added by local player if entity isn't in database yet but actors already exist for entity
		FString entityUID = cotEvent->GetAttribute(TEXT("uid"));
		if (!entityDB->IsEntityInDB(entityUID) && GetActorsForEntity(entityUID).Num() > 0)
		{
			cotEvent->AddNode(TEXT("archive"), true);
		}
	}

	FString xml = cotEvent->ToXML();

	FBufferArchive toBinary;
	toBinary << xml;
	TArray<uint8> data = (TArray<uint8>&)toBinary;

	FGeodeticCoord2D northWestBB;
	FGeodeticCoord2D southEastBB;
	GetCOTCoordinates(cotEvent, northWestBB, southEastBB);

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		bool bVisible = true;
		bool bNewer = true;

		SpatialiteResults results = entityDB->QueryUID(cotEvent->GetAttribute(TEXT("uid")));
		if (results.Num() > 0)
		{
			SpatialiteResult entry = results[0];

			// Check visibility
			bVisible = UDatabase_Spatialite::GetBool(TEXT("visible"), entry);
				
			// Verify incoming COT is newer than database entry
			TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), entry);
			FMemoryReader fromBinary = FMemoryReader(blobData);
			fromBinary.Seek(0);
				
			FString dbCotData;
			fromBinary << dbCotData;
			
			UVH_COTEvent* dbCotEvent = NewObject<UVH_COTEvent>();
			if (dbCotEvent->PopulateFromXML(dbCotData))
			{
				bNewer = cotEvent->GetAttribute<FDateTime>(TEXT("start")) >= dbCotEvent->GetAttribute<FDateTime>(TEXT("start"));
			}
			else
			{
				UE_LOG(Game, Warning, TEXT("-- UGame_COTManager::InsertOrUpdate | received malformed xml | %s | aborting"), *dbCotData);
				return;
			}
		}

		if (bNewer)
		{
			bool bTransient = UVH_COTManager::IsVTAKGhost(cotEvent) || Contacts.Find(FName(*cotEvent->GetAttribute(TEXT("uid")))) || bForceTransient;
			entityDB->InsertOrUpdate(cotEvent->GetAttribute(TEXT("uid")), GetDataLoader_COT_ClassUID(), GetOverlayCategory(cotEvent), northWestBB, southEastBB, data, bTransient, bVisible);
		}
	}
}

void UGame_COTManager::RegisterVehicleClass(TSubclassOf<AGame_VehicleRepresentative> vehicleBlueprint)
{
	if (vehicleBlueprint == nullptr)
	{
		return;
	}

	VehicleBlueprints.Add(vehicleBlueprint);
	AGame_VehicleRepresentative* vehicleObject = vehicleBlueprint.GetDefaultObject();
	VehicleDropperCategories.Add(vehicleObject->DropperCategory);

	if (UVH_COTUserIcons* userIcons = GetUserIcons())
	{
		FString modelName = vehicleObject->ModelName;

		if (userIcons->ModelToBlueprint.Contains(modelName))
		{
			UE_LOG(Game, Verbose, TEXT("-- UGame_COTManager::RegisterVehicleClass | model already exists | %s"), *modelName);
			return;
		}

		userIcons->ModelToBlueprint.Add(modelName, vehicleBlueprint);
	}
}

TArray<TSubclassOf<AGame_VehicleRepresentative>> UGame_COTManager::GetVehicleBlueprints() const
{
	TArray<TSubclassOf<AGame_VehicleRepresentative>> vehicleBlueprintArray = VehicleBlueprints.Array();

	vehicleBlueprintArray.Sort([](const TSubclassOf<AGame_VehicleRepresentative>& a, const TSubclassOf<AGame_VehicleRepresentative>& b) { return a.GetDefaultObject()->FriendlyName < b.GetDefaultObject()->FriendlyName; });

	return vehicleBlueprintArray;
}

void UGame_COTManager::GetVehicleBlueprintsInCategory(const FName& inCategory, TArray<TSubclassOf<AGame_VehicleRepresentative>>& outArray)
{
	outArray.Empty();
	TArray<TSubclassOf<AGame_VehicleRepresentative>> allVehicles = GetVehicleBlueprints();
	for (TSubclassOf<AGame_VehicleRepresentative> iter : allVehicles)
	{
		if (iter == nullptr)
		{
			continue;
		}

		if (Cast<AGame_VehicleRepresentative>(iter->GetDefaultObject())->DropperCategory == inCategory)
		{
			outArray.Add(iter);
		}
	}

}

void UGame_COTManager::DeleteStaleEntitiesFromResults(SpatialiteResults& results) const
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		for (int32 i = 0; i < results.Num(); i++)
		{
			SpatialiteResult result = results[i];

			FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);

			if (classUID.Equals(GetDataLoader_COT_ClassUID(), ESearchCase::IgnoreCase))
			{
				TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);

				FMemoryReader fromBinary = FMemoryReader(blobData);
				fromBinary.Seek(0);

				FString cotString;
				fromBinary << cotString;

				UVH_COTEvent* cotEvent = NewObject<UVH_COTEvent>();
				if (cotEvent->PopulateFromXML(cotString))
				{
					if (!cotEvent->HasNode(TEXT("archive")) && cotEvent->GetAttribute<FDateTime>(TEXT("stale")) < FDateTime::UtcNow())
					{
						FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
						if (!Contacts.Contains(FName(*entityUID)))
						{
							UE_LOG(Game, Verbose, TEXT("-- UGame_COTManager::DeleteStaleEntitiesFromResults | removing: %s | cot: %s | now: %s"), *entityUID, *cotEvent->GetAttribute<FDateTime>(TEXT("stale")).ToString(), *FDateTime::UtcNow().ToString());
						}
					
						// Remove stale COT from results AND delete entry from database
						entityDB->DeleteFromResult(result);

						results.RemoveAt(i, 1);
						i--;
					}
				}
			}
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_COTManager::HandleEntityDBDeleteEvent(const FSpatialiteResults_BP& results)
{
	for (const FSpatialiteResult_BP& result : results.Results)
	{
		RemoveAttachedFiles(UDatabase_Spatialite::GetString(TEXT("entityUID"), result.Result), TEXT(""));
	}
}
