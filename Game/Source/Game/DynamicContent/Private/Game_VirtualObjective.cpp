// Required Includes
#include "Game_VirtualObjective.h"
#include "Game.h"

// Engine Includes
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "GameFramework/Character.h"

// VH Plugin Includes
#include "Database_Spatialite.h"
#include "Developer_TaskScheduler.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_GlobeMathStatics.h"
#include "Developer_Statics.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_Subsystem_Core.h"
#include "Game_Statics.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_PlayerController.h"
#include "Game_ImportManager.h"
#include "Game_EntityDB.h"
#include "Game_HandlerService.h"
#include "Game_TileManager.h"
#include "Game_TerrainTile.h"
#include "Game_PlayerState.h"
#include "Interface_EntityHandler.h"
#include "Game_ImportedMeshComponent.h"
#include "Game_AdjustableModelImportComponent.h"
#include "Game_GlobeReferenceActor_ENU.h"
#include "Game_Pawn.h"
#include "Game_CameraComponent.h"
#include "Game_MovementComponent.h"

DEFINE_LOG_CATEGORY(LogGameVirtualObjective);

AGame_VirtualObjective::FOnObjectAddedToVO AGame_VirtualObjective::OnObjectAddedToVO;
UGame_VirtualObjectiveManager::FOnObjectAddedToVO UGame_VirtualObjectiveManager::OnObjectAddedToVO;

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_VirtualObjective::AGame_VirtualObjective() :
	EntityDetailLevel(1),
	ReplicatedVOGlobeCoordinate(FGeodeticCoord3D::Invalid),
	ReplicatedScale3D(FVector(0.005, 0.005, 0.005)),
    ViewDistance(3000),
	LoadEntitiesCooldown(0.075)
{
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;

	bReplicates = true;
	bAlwaysRelevant = true;

    GlobeReferenceActorClass = AVH_GlobeReferenceActor::StaticClass();
}

// ---------------------------------
// --- Replication
// ---------------------------------

void AGame_VirtualObjective::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AGame_VirtualObjective, ReplicatedVOGlobeCoordinate);
	DOREPLIFETIME(AGame_VirtualObjective, ReplicatedScale3D);
	DOREPLIFETIME(AGame_VirtualObjective, TOCTileViewDistance);
}

void AGame_VirtualObjective::OnRep_ReplicatedVOGlobeCoordinate()
{
	SyncToTOCLocation();
}

void AGame_VirtualObjective::OnRep_ReplicatedScale3D()
{
	SyncToTOCScale3D();
}

void AGame_VirtualObjective::OnRep_TOCTileViewDistance()
{
	SyncToTOCTileViewDistance();
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_VirtualObjective::BeginPlay()
{
    Super::BeginPlay();

    UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get();
    if (voManager)
    {
        voManager->RegisterVirtualObjective(this);
    }

	if (GetNetMode() == NM_Client)
	{
		CheckForMUCDBReceived();
	}
	else
	{
		Initialize();
	}

    if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
    {
		gameSettings->OnDoubleSettingStored.AddDynamic(this, &AGame_VirtualObjective::HandleDoubleSettingStored);

		gameSettings->StoreDefaultSettingDouble(TEXT("ObjectViewDistance"), 3000);

        SetViewDistance(gameSettings->GetSettingDouble(TEXT("ObjectViewDistance")));
    }

	BindToTileManager();

	if (AGame_PlayerController* pc = UGame_Statics::GetVHPlayerController())
	{
		pc->GetMeshBuilder()->OnTaskFinished.AddUniqueDynamic(this, &AGame_VirtualObjective::HandleMeshBuilderTaskFinished);
	}

	FTimerHandle timerHandle;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AGame_VirtualObjective::PeriodicCheckRelevancy, 0.5, true);
}

void AGame_VirtualObjective::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	Shutdown();

	UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get();
	if (voManager)
	{
		voManager->UnregisterVirtualObjective(this);
	}

	if (GetNetMode() == NM_Client)
	{
		if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
		{
			playerState->OnServerDatabaseReady.RemoveDynamic(this, &AGame_VirtualObjective::HandleServerDatabaseReady);
		}
	}

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->OnInsertOrUpdate.RemoveDynamic(this, &AGame_VirtualObjective::HandleEntityDBInsertOrUpdateEvent);
		entityDB->OnDelete.RemoveDynamic(this, &AGame_VirtualObjective::HandleEntityDBDeleteEvent);
	}

	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->OnTileFinishedLoading.RemoveAll(this);
	}

	if (AGame_PlayerController* pc = UGame_Statics::GetVHPlayerController())
	{
		if (pc->GetMeshBuilder())
		{
			pc->GetMeshBuilder()->OnTaskFinished.RemoveAll(this);
		}
	}

	Super::EndPlay(endPlayReason);
}

void AGame_VirtualObjective::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	if (bUpdateCoord)
	{
		bUpdateCoord = false;

		SyncToTOCLocation();
	}

	if (QueuedToLoad.Num() > 0)
	{
		// try to maintain 90fps or more
		LoadEntitiesCooldown = FMath::Clamp<double>(deltaSeconds < 0.0111 ? LoadEntitiesCooldown - 0.001 : LoadEntitiesCooldown + 0.001 , 0.05, 0.1);
		
		LoadEntitiesElapsed += deltaSeconds;

		if (LoadEntitiesElapsed > LoadEntitiesCooldown)
		{
			PeriodicLoadEntities();

			LoadEntitiesElapsed = 0;
		}
	}
}

void AGame_VirtualObjective::SetActorScale3D(FVector newScale3D)
{
	if (!newScale3D.Equals(GetActorScale3D(), 0.00001f))
	{
		// assumes scale is uniform
		TOCTileViewDistance = FMath::Min<float>(50000, 3.5 / newScale3D.X);
		TOCViewDistance = TOCTileViewDistance;

		AVH_GlobeReferenceActor* globeReference = GetGlobeReference();
		UGame_HandlerService* handlerService = UGame_HandlerService::Get();
		UGame_EntityDB* entityDB = UGame_EntityDB::Get();

		if (globeReference != nullptr && handlerService != nullptr && entityDB != nullptr)
		{
			PreModifyGlobeReference(entityDB, handlerService, globeReference);

			globeReference->SetActorScale3D(newScale3D);
			if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
			{
				playerState->Server_SetGlobeReferenceScale3D(newScale3D);
			}

			for (const TPair<FString, TSet<UObject*>>& entry : EntityUIDToObjects)
			{
				SpatialiteResults results = entityDB->QueryUID(entry.Key);
				for (const SpatialiteResult& result : results)
				{
					handlerService->SetEntityScale3D(this, result, newScale3D);
				}
			}

			if (UGame_TileManager* tileManager = UGame_TileManager::Get())
			{
				tileManager->GlobeReferenceScaleUpdated(newScale3D);
			}

			PostModifyGlobeReference(entityDB, handlerService, globeReference);

			OnTOCViewDistanceChanged.Broadcast(TOCViewDistance, TOCTileViewDistance);

			TriggerUpdate();
		}
	}

	Super::SetActorScale3D(newScale3D);

	OnScale3DChanged.Broadcast(newScale3D);
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_VirtualObjective::SetEnabled(bool bEnabledArg)
{
	bEnabled = bEnabledArg;

	QueuedToLoad.Empty();

	if (!bEnabled)
	{
		bNeedsUpdate = false;

		PageOutEntities();
	}
	else
	{
		bNeedsUpdate = true;
	}
}

int32 AGame_VirtualObjective::GetEntityDetailLevel() const
{
	return EntityDetailLevel;
}

TSet<FString> AGame_VirtualObjective::GetPagedInEntities() const
{
	TSet<FString> keys;
	EntityUIDToObjects.GetKeys(keys);

	return keys;
}

void AGame_VirtualObjective::PageOutEntities()
{
	TArray<FString> entityUIDs;
	EntityUIDToObjects.GenerateKeyArray(entityUIDs);

	for (const FString& entityUID : entityUIDs)
	{
		PageOutEntity(entityUID);
	}
}

bool AGame_VirtualObjective::IsEntityPagedIn(const FString& entityUID) const
{
	return EntityUIDToObjects.Contains(entityUID);
}

void AGame_VirtualObjective::AddObjectToEntity(const FString& entityUID, UObject* object)
{
	if (TSet<UObject*>* objectsPtr = EntityUIDToObjects.Find(entityUID))
	{
		objectsPtr->Add(object);
	}
	else
	{
		TSet<UObject*> set;
		set.Add(object);

		EntityUIDToObjects.Add(entityUID, set);
	}

	ObjectToEntityUID.Add(object, entityUID);

	OnObjectAddedToVO.Broadcast(object, this);

	if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
	{
		voManager->OnObjectAddedToVO.Broadcast(object, this);
	}
}

void AGame_VirtualObjective::AddObjectsToEntity(const FString& entityUID, const TSet<UObject*>& objects)
{
	for (UObject* object : objects)
	{
		AddObjectToEntity(entityUID, object);
	}
}

void AGame_VirtualObjective::RemoveObjectFromEntity(const FString& entityUID, UObject* object)
{
	if (TSet<UObject*>* objectsPtr = EntityUIDToObjects.Find(entityUID))
	{
		objectsPtr->Remove(object);

		if (objectsPtr->Num() == 0)
		{
			EntityUIDToObjects.Remove(entityUID);
		}
	}

	ObjectToEntityUID.Remove(object);
}

TSet<UObject*> AGame_VirtualObjective::GetObjectsForEntity(const FString& entityUID) const
{
	TSet<UObject*> objectSet;

	if (const TSet<UObject*>* objectsPtr = EntityUIDToObjects.Find(entityUID))
	{
		TSet<UObject*> objects = *objectsPtr;
		for (UObject* object : objects)
		{
			if (object != nullptr && object->IsValidLowLevel())
			{
				objectSet.Add(object);
			}
		}
	}
	
	return objectSet;
}

TSet<AActor*> AGame_VirtualObjective::GetActorsForEntity(const FString& entityUID) const
{
	TSet<AActor*> actorSet;

	if (const TSet<UObject*>* objectsPtr = EntityUIDToObjects.Find(entityUID))
	{
		TSet<UObject*> objects = *objectsPtr;

		for (UObject* object : objects)
		{
			if (object->IsValidLowLevel())
			{
				if (AActor* actor = Cast<AActor>(object))
				{
					actorSet.Add(actor);
				}
			}
		}
	}

	return actorSet;
}

bool AGame_VirtualObjective::HasObject(UObject* object) const
{
	return ObjectToEntityUID.Contains(object);
}

FString AGame_VirtualObjective::GetObjectEntityUID(UObject* object) const
{
	if (const FString* entityUIDPtr = ObjectToEntityUID.Find(object))
	{
		return *entityUIDPtr;
	}

	return TEXT("");
}

void AGame_VirtualObjective::PageOutEntity(const FString& entityUID)
{
	TSet<UObject*> entityObjects = GetObjectsForEntity(entityUID);

	for (UObject* object : entityObjects)
	{
		if (!object->IsRooted())
		{
			if (AActor* actor = Cast<AActor>(object))
			{
				actor->Destroy();
			}
			else
			{
				object->ConditionalBeginDestroy();
			}
		}

		ObjectToEntityUID.Remove(object);
	}

	EntityUIDToObjects.Remove(entityUID);
}

void AGame_VirtualObjective::SetEntityVisibility(const FString& entityUID, bool bVisible)
{
	TSet<AActor*> actorSet = GetActorsForEntity(entityUID);

	for (AActor* actor : actorSet)
	{
		actor->SetActorHiddenInGame(!bVisible);

		actor->SetActorEnableCollision(bVisible);
	}
}

void AGame_VirtualObjective::SetEntityScale3D(const FString& entityUID, FVector scale3D)
{
	TSet<AActor*> actorSet = GetActorsForEntity(entityUID);

	for (AActor* actor : actorSet)
	{
		FVector modifiedScale = scale3D;
		if (UGame_AdjustableModelImportComponent* importComponent = actor->FindComponentByClass<UGame_AdjustableModelImportComponent>())
		{
			FVector importComponentScale = importComponent->GetScale();
			if (importComponentScale.Size() != 0)
			{
				modifiedScale *= importComponent->GetScale();
			}
		}

		actor->SetActorScale3D(modifiedScale);
	}
}

bool AGame_VirtualObjective::IsInitialized() const
{
	return bIsInitialized;
}

void AGame_VirtualObjective::Shutdown()
{

}

void AGame_VirtualObjective::SetReplicatedVOGlobeCoordinate(const FGeodeticCoord3D& location)
{
	ReplicatedVOGlobeCoordinate = location;
}

void AGame_VirtualObjective::SetReplicatedScale3D(const FVector& scale3D)
{
	ReplicatedScale3D = scale3D;
}

AVH_GlobeReferenceActor* AGame_VirtualObjective::GetGlobeReference()
{
	if (!bIsInitialized)
	{
		return nullptr;
	}

	if (GlobeReference == nullptr)
	{
		FTransform spawnTransform = GetActorTransform();
		FActorSpawnParameters spawnParams;
		spawnParams.Owner = this;
		spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		GlobeReference = GetWorld()->SpawnActor<AVH_GlobeReferenceActor>(GlobeReferenceActorClass, spawnTransform, spawnParams);
		if (GlobeReference != nullptr)
		{
			FGeodeticCoord3D initialCoordinate;
			if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
			{
				initialCoordinate.FromString(gameSettings->GetSettingString(TEXT("InitialCoordinate")));

				if (initialCoordinate == FGeodeticCoord3D::Invalid)
				{
					UE_LOG(Game, Warning, TEXT("-- AGame_VirtualObjective | initialCoordinate is invalid"));
				}

				GlobeReference->SetActorScale3D(GetActorScale3D());
				if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
				{
					playerState->Server_SetGlobeReferenceScale3D(GetActorScale3D());
				}

				if (AGame_GlobeReferenceActor_ENU* globeReferenceENU = Cast<AGame_GlobeReferenceActor_ENU>(GlobeReference))
				{
					globeReferenceENU->SetGeodeticLocation(initialCoordinate);
				}

				OnGlobeReferenceGeoLocationChanged.Broadcast(GlobeReference);
			}
		}
	}

	return GlobeReference;
}

void AGame_VirtualObjective::SetGlobeReference(AVH_GlobeReferenceActor* inGlobeReference)
{
	GlobeReference = inGlobeReference;
}

AActor* AGame_VirtualObjective::GetViewpointActor() const
{
	return ViewpointActor;
}

void AGame_VirtualObjective::SetViewpointActor(AActor* actor)
{
	ViewpointActor = actor;
}

float AGame_VirtualObjective::GetViewDistance() const
{
	return ViewDistance;
}

void AGame_VirtualObjective::SetViewDistance(float viewDistance)
{
	ViewDistance = viewDistance;

	TriggerUpdate();
}

FBox2D AGame_VirtualObjective::GetViewCullBox()
{
	return ViewCullBox;
}

void AGame_VirtualObjective::SetViewCullBox(const FBox2D& cullBox)
{
	// Check for valid cullBox
	if (cullBox.bIsValid && !FMath::IsNearlyZero(cullBox.GetArea()))
	{
		ViewCullBox = cullBox;
	}
	else
	{
		// Invalidate cached cullBox
		ViewCullBox.Init();
	}
}

bool AGame_VirtualObjective::IsPointInViewCullBox(const FVector& point)
{
	return ViewCullBox.IsInside(FVector2D(point));
}

void AGame_VirtualObjective::TriggerUpdate()
{
	bNeedsUpdate = true;
}

void AGame_VirtualObjective::EntityHandlerRegistered(UObject* handler)
{
	TriggerUpdate();
}

void AGame_VirtualObjective::SetScaleFor(const FString& entityUID)
{
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();

	UGame_HandlerService* handlerService = UGame_HandlerService::Get();

	if (entityDB != nullptr && handlerService != nullptr)
	{
		SpatialiteResults results = entityDB->QueryUID(entityUID);
		for (const SpatialiteResult& result : results)
		{
			handlerService->SetEntityScale3D(this, result, GetActorScale3D());
		}
	}
}

void AGame_VirtualObjective::SetVisibilityFor(const FString& entityUID)
{
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();

	UGame_HandlerService* handlerService = UGame_HandlerService::Get();

	if (entityDB != nullptr && handlerService != nullptr)
	{
		SpatialiteResults results = entityDB->QueryUID(entityUID);
		for (const SpatialiteResult& result : results)
		{
			bool bVisible = UDatabase_Spatialite::GetBool(TEXT("visible"), result);

			handlerService->SetEntityVisibility(this, result, bVisible);
		}
	}
}

void AGame_VirtualObjective::TOCMoveViewpoint(const FVector& offset)
{
	if (IsLocalPlayerInTOC())
	{
		if (AGame_GlobeReferenceActor_ENU* globeReferenceENU = Cast<AGame_GlobeReferenceActor_ENU>(GetGlobeReference()))
		{
			FGeodeticCoord3D newGeoLocation = globeReferenceENU->GetLocation();

			if (!FMath::IsNearlyEqual(offset.SizeSquared2D(), 0.f))
			{
				double bearing = FMath::RadiansToDegrees<double>(FMath::Atan2(offset.Y, offset.X));
				double distance = (double)offset.Size2D();
				double avgAltitude = newGeoLocation.Altitude + ((double)offset.Z * 0.5);
				FGeodeticCoord2D geoDestination2D = UVH_GlobeMathStatics::CalculateSurfaceDestination(newGeoLocation.ToGeodeticCoord2D(), bearing, distance, avgAltitude);
				newGeoLocation = FGeodeticCoord3D(geoDestination2D, newGeoLocation.Altitude);
			}

			newGeoLocation.Altitude += (double)offset.Z;

			SetCoord_Implementation(newGeoLocation);

			if (IsLocalPlayerInTOC())
			{
				ReplicatedVOGlobeCoordinate = newGeoLocation;
				ReplicatedVOGlobeCoordinate.bIsAltitudeRelativeToGround = false;

				if (AGame_PlayerController* pc = UGame_Statics::GetVHPlayerController())
				{
					if (GetNetMode() == NM_Client)
					{
						pc->Server_TOCSetReplicatedPosition(this, ReplicatedVOGlobeCoordinate);

						pc->Server_SetCoord(this, newGeoLocation);
					}
				}
			}

		}
	}
}

void AGame_VirtualObjective::SetScale3D(const FVector& newScale)
{
	if (IsLocalPlayerInTOC())
	{
		ReplicatedScale3D = newScale;

		SetActorScale3D(ReplicatedScale3D);

		if (AGame_PlayerController* pc = UGame_Statics::GetVHPlayerController())
		{
			if (GetNetMode() == NM_Client)
			{
				pc->Server_VOSetReplicatedScale3D(this, newScale);
				pc->Server_VOSetScale3D(this, newScale);
			}
		}
	}
}

void AGame_VirtualObjective::SetCoord(const FGeodeticCoord3D& coordinate, bool bSnapTileToTable)
{
	FGeodeticCoord3D updatedCoordinate = coordinate;

	if (bSnapTileToTable)
	{
		updatedCoordinate.Altitude = 0;
	}

	updatedCoordinate.bIsAltitudeRelativeToGround = bSnapTileToTable;

	SetCoord_Implementation(updatedCoordinate);

	if (IsLocalPlayerInTOC())
	{
		ReplicatedVOGlobeCoordinate = updatedCoordinate;

		if (AGame_PlayerController* pc = UGame_Statics::GetVHPlayerController())
		{
			if (GetNetMode() == NM_Client)
			{
				pc->Server_TOCSetReplicatedPosition(this, ReplicatedVOGlobeCoordinate);
				pc->Server_SetCoord(this, updatedCoordinate);
			}
		}
	}
}

void AGame_VirtualObjective::SetCoord_Implementation(const FGeodeticCoord3D& coordinate)
{
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();
	UGame_HandlerService* handlerService = UGame_HandlerService::Get();
	AGame_GlobeReferenceActor_ENU* globeReferenceENU = Cast<AGame_GlobeReferenceActor_ENU>(GetGlobeReference());
	AActor* viewpointActor = GetViewpointActor();

	if (entityDB != nullptr && handlerService != nullptr && globeReferenceENU != nullptr && viewpointActor != nullptr)
	{
		FGeodeticCoord3D currentGlobeLocation = globeReferenceENU->GetLocation();

		if (UVH_GlobeMathStatics::CalculateSurfaceDistance(currentGlobeLocation.ToGeodeticCoord2D(), coordinate.ToGeodeticCoord2D()) > 20000)
		{
			// page out everything when move large enough distance
			// if we didn't, objects with a large enough bounding box to still be relevant could have precision issues
			bForcePageEntities = true;
		}

		PreModifyGlobeReference(entityDB, handlerService, globeReferenceENU);
		globeReferenceENU->SetActorLocation(viewpointActor->GetActorLocation());
		globeReferenceENU->SetGeodeticLocation(coordinate);
		PostModifyGlobeReference(entityDB, handlerService, globeReferenceENU);

		OnGlobeReferenceGeoLocationChanged.Broadcast(GlobeReference);
	}
}

void AGame_VirtualObjective::SnapToGround(const FBox2D& geoExtents)
{
	//UDeveloper_Statics::PrintMessage(FString::Printf(TEXT("AGame_VirtualObjective::SnapToGround() IsInGameThread=%s"), IsInGameThread() ? TEXT("TRUE") : TEXT("FALSE")));

	// TODO: Ignore if 'geoExtents' is outside the relevancy bounds of this VO. 

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		if (UGame_HandlerService* handlerService = UGame_HandlerService::Get())
		{
			FVector2D boxCenter = geoExtents.GetCenter();
			FGeodeticCoord2D geoCenter(boxCenter.X, boxCenter.Y);
			FGeodeticCoord2D geoMax(geoExtents.Max.X, geoExtents.Max.Y);
			double geoRadius = UVH_GlobeMathStatics::CalculateSurfaceDistance(geoCenter, geoMax) * 1.2;	// TODO: Increasing 1.2x for now, until a query for each KML placemark is implemented!

			SpatialiteResults results = entityDB->QuerySquare2D(geoCenter, geoRadius);
			//UDeveloper_Statics::PrintMessageLog(FString::Printf(TEXT("-- ROWS TO SNAP_TO_GROUND (%d) | geoRadius: %.8Lf, geoCenter: %s"), results.Num(), geoRadius, *geoCenter.ToString()), false, false, true, false, ELogMessageColor::Cyan);
			for (const SpatialiteResult& result : results)
			{
				FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

				if (IsEntityPagedIn(entityUID))
				{
					handlerService->SnapEntityToGround(this, result);
				}
			}
		}
	}
}

void AGame_VirtualObjective::SyncToTOCLocation()
{
	if (IsLocalPlayerInTOC())
	{
		if (AVH_GlobeReferenceActor* globeReference = GetGlobeReference())
		{
			if (ReplicatedVOGlobeCoordinate != FGeodeticCoord3D::Invalid)
			{
				SetCoord_Implementation(ReplicatedVOGlobeCoordinate);
			}
		}
		else
		{
			bUpdateCoord = true;
		}
	}
}

void AGame_VirtualObjective::SyncToTOCScale3D()
{
	if (IsLocalPlayerInTOC())
	{
		SetActorScale3D(ReplicatedScale3D);
	}
}

void AGame_VirtualObjective::SyncToTOCTileViewDistance()
{
	if (IsLocalPlayerInTOC())
	{
		SetActorScale3D(ReplicatedScale3D);
	}
}

float AGame_VirtualObjective::GetUnrealUnitsPerMeter()
{
	return GetActorScale3D().X * 100.f;
}

int32 AGame_VirtualObjective::GetVOIndex()
{
	return 1;
}

float AGame_VirtualObjective::GetExpectedTOCTileDistance()
{
	return FMath::Min<float>(50000, 3.5 / GetActorScale3D().X);;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void AGame_VirtualObjective::UpdateRelevancySet(const FGeodeticCoord3D& geoLocation)
{
	LastRelevancyUpdateCoordinate = geoLocation;
	
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		double viewDistanceMeters = 0;
		if (IsLocalPlayerInTOC())
		{
			viewDistanceMeters = TOCViewDistance;
		}
		else
		{
			viewDistanceMeters = 5037500;

			FGeodeticCoord3D viewpointActorCoordinate = GetGlobeReference()->WorldToGeodeticDouble(ViewpointActor->GetActorLocation());

			double terrainHAE = GetGlobeReference()->GetTerrainElevationDouble(viewpointActorCoordinate.ToGeodeticCoord2D());
			if (!FMath::IsNearlyEqual(terrainHAE, -999999.f))
			{
				double playerAGL = viewpointActorCoordinate.Altitude - terrainHAE;
				if (playerAGL < 1000)
				{
					viewDistanceMeters = ViewDistance;
				}
				else
				{
					// set viewDistance as distance to horizon
					double earthRadius = 6367444.6571225; // (6378137.0 + 6356752.314245) / 2;
					viewDistanceMeters = FMath::Min(5037500, FMath::Sqrt(FMath::Pow((playerAGL + earthRadius), 2) - FMath::Pow(earthRadius, 2)));
				}
			}
		}

		TSet<FString> loadedEntityIDs;
		for (const TPair<FString, TSet<UObject*>>& entry : EntityUIDToObjects)
		{
			loadedEntityIDs.Add(entry.Key);
		}

		// get relevancy set at new location
		SpatialiteResults relevantResults = entityDB->QuerySquare2D(geoLocation.ToGeodeticCoord2D(), viewDistanceMeters);

		TSet<FString> relevantEntityIDs;
		TMap<FString, SpatialiteResult> entityIDToResult;
		for (const SpatialiteResult& result : relevantResults)
		{
			FString entityID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

			relevantEntityIDs.Add(entityID);

			entityIDToResult.Add(entityID, result);
		}

		TSet<FString> toUnloadEntityIDs;

		if (bForcePageEntities)
		{
			toUnloadEntityIDs.Append(loadedEntityIDs);
		}
		else
		{
			// in loadedEntityIDs, not in relevantEntityIDs
			toUnloadEntityIDs = loadedEntityIDs.Difference(relevantEntityIDs);
		}

		//UDeveloper_Statics::PrintMessageLog(FString::Printf(TEXT("-- ROWS TO REMOVE (%d)"), toUnloadEntityIDs.Num()), false, false, true, false, ELogMessageColor::DarkCyan);
		for (const FString& entityUID : toUnloadEntityIDs)
		{
			entityDB->UnloadEntity(this, entityUID);
		}

		QueuedToLoad = QueuedToLoad.Intersect(relevantEntityIDs);

		if (bForcePageEntities)
		{
			QueuedToLoad.Append(relevantEntityIDs);

			bForcePageEntities = false;
		}
		else
		{
			// in relevantEntityIDs, not in loadedEntityIDs
			QueuedToLoad.Append(relevantEntityIDs.Difference(loadedEntityIDs));
		}
	}
}

bool AGame_VirtualObjective::Initialize()
{
	// default to player if not set explicitly
	if (!IsValid(ViewpointActor))
	{
		if (AGame_PlayerController* pc = UGame_Statics::GetVHPlayerController())
		{
			SetViewpointActor(pc->GetPawn());
		}
	}

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->OnInsertOrUpdate.AddDynamic(this, &AGame_VirtualObjective::HandleEntityDBInsertOrUpdateEvent);
		entityDB->OnDelete.AddDynamic(this, &AGame_VirtualObjective::HandleEntityDBDeleteEvent);
	}

	bIsInitialized = true;

	TriggerUpdate();

	return true;
}

void AGame_VirtualObjective::PreModifyGlobeReference(UGame_EntityDB* entityDB, UGame_HandlerService* handlerService, AVH_GlobeReferenceActor* globeReference)
{
	// cache VO's objects locations
	for (const TPair<FString, TSet<UObject*>>& entry : EntityUIDToObjects)
	{
		SpatialiteResults results = entityDB->QueryUID(entry.Key);
		for (const SpatialiteResult& result : results)
		{
			handlerService->PreModifyVOGlobeReference(this, result);
		}
	}

	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->PreModifyVOGlobeReference(globeReference);
	}
}

void AGame_VirtualObjective::PostModifyGlobeReference(UGame_EntityDB* entityDB, UGame_HandlerService* handlerService, AVH_GlobeReferenceActor* globeReference)
{
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->PostModifyVOGlobeReference(globeReference);
	}

	// update VO's objects locations for new globe reference position
	for (const TPair<FString, TSet<UObject*>>& entry : EntityUIDToObjects)
	{
		SpatialiteResults results = entityDB->QueryUID(entry.Key);
		for (const SpatialiteResult& result : results)
		{
			handlerService->PostModifyVOGlobeReference(this, result);
		}
	}

	TriggerUpdate();
}

bool AGame_VirtualObjective::IsLocalPlayerInTOC() const
{
	AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState();

	return playerState != nullptr && playerState->GetIsInTOC();
}

void AGame_VirtualObjective::CheckForMUCDBReceived()
{
	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		if (playerState->IsMUCServerDBReceived())
		{
			Initialize();
		}
		else
		{
			playerState->OnServerDatabaseReady.AddDynamic(this, &AGame_VirtualObjective::HandleServerDatabaseReady);
		}
	}
	else
	{
		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AGame_VirtualObjective::CheckForMUCDBReceived, 0.5, false);
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_VirtualObjective::BindToTileManager()
{
	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->OnTileFinishedLoading.AddUObject(this, &AGame_VirtualObjective::HandleTerrainTileFinishedLoading);
		tileManager->OnTileDisabled.AddUObject(this, &AGame_VirtualObjective::HandleTerrainTileDisabled);
	}
	else
	{
		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AGame_VirtualObjective::BindToTileManager, 0.5);
	}
}

void AGame_VirtualObjective::HandleDoubleSettingStored(const FString& settingName, double value)
{
	if (settingName.Equals(TEXT("ObjectViewDistance")))
	{
		SetViewDistance(value);
	}
}

void AGame_VirtualObjective::HandleEntityDBInsertOrUpdateEvent(const FSpatialiteResults_BP& results)
{
	//UDeveloper_Statics::PrintMessageLog(FString::Printf(TEXT("VirtualObjective::HandleEntityDBInsertOrUpdateEvent()")), false, false, true, false, ELogMessageColor::Cyan);
	TriggerUpdate();
}

void AGame_VirtualObjective::HandleEntityDBDeleteEvent(const FSpatialiteResults_BP& results)
{
	//UDeveloper_Statics::PrintMessageLog(FString::Printf(TEXT("VirtualObjective::HandleEntityDBDeleteEvent()")), false, false, true, false, ELogMessageColor::Cyan);
	TriggerUpdate();
}

void AGame_VirtualObjective::HandleTerrainTileFinishedLoading(AGame_TerrainTile* terrainTile)
{
	// adjust TOC table altitude
	if (IsLocalPlayerInTOC())
	{
		if (terrainTile->GetTileStatus() != ETileStatus::ReadyForDestroy)
		{
			if (AGame_GlobeReferenceActor_ENU* globeReferenceENU = Cast<AGame_GlobeReferenceActor_ENU>(GetGlobeReference()))
			{
				FGeodeticCoord3D tableCoordinates = globeReferenceENU->GetLocation();

				if (UGame_TileManager* tileManager = UGame_TileManager::Get())
				{
					double minLoadedHAE;
					if (tileManager->GetMinLoadedHAE(minLoadedHAE))
					{
						SetCoord(FGeodeticCoord3D(tableCoordinates.Longitude, tableCoordinates.Latitude, minLoadedHAE - 10), false);
					}
				}
			}
		}
	}

	// NOTE: Tile bounds are NW/SE, so remap to min/max (e.g. SW/NE)
	TPair<FGeodeticCoord2D, FGeodeticCoord2D> tileBounds = terrainTile->GetTileBounds();
	FVector2D minBounds(tileBounds.Key.Longitude, tileBounds.Value.Latitude);
	FVector2D maxBounds(tileBounds.Value.Longitude, tileBounds.Key.Latitude);
	FBox2D geoExtents(minBounds, maxBounds);

	SnapToGround(geoExtents);
}

void AGame_VirtualObjective::HandleTerrainTileDisabled(AGame_TerrainTile* terrainTile)
{
	// NOTE: Tile bounds are NW/SE, so remap to min/max (e.g. SW/NE)
	TPair<FGeodeticCoord2D, FGeodeticCoord2D> tileBounds = terrainTile->GetTileBounds();
	FVector2D minBounds(tileBounds.Key.Longitude, tileBounds.Value.Latitude);
	FVector2D maxBounds(tileBounds.Value.Longitude, tileBounds.Key.Latitude);
	FBox2D geoExtents(minBounds, maxBounds);

	SnapToGround(geoExtents);
}

void AGame_VirtualObjective::HandleMeshBuilderTaskFinished(TScriptInterface<IInterface_Developer_Task> task)
{
	FBox geoExtents;

	if (UGame_ImportedMeshComponent* taskMeshComp = Cast<UGame_ImportedMeshComponent>(task.GetObject()))
	{
		AActor* taskMeshActor = taskMeshComp->GetOwner();
		if (IsValid(taskMeshActor))
		{
			if (taskMeshComp->GetGeodeticBounds(geoExtents))
			{
				// Adjust TOC table altitude
				if (IsLocalPlayerInTOC())
				{
					// Only adjust TOC table if NOT streaming terrain tiles too!
					UGame_TileManager* tileManager = UGame_TileManager::Get();
					if (tileManager == nullptr || !tileManager->IsEnabled())
					{
						if (AGame_GlobeReferenceActor_ENU* globeReferenceENU = Cast<AGame_GlobeReferenceActor_ENU>(GetGlobeReference()))
						{
							FGeodeticCoord3D globeLocation = globeReferenceENU->GetLocation();
							FVector actorPos = taskMeshActor->GetActorLocation();

							FVector startTrace = actorPos + FVector(0, 0, 10000000);
							FVector endTrace = actorPos - FVector(0, 0, 10000000);

							FCollisionQueryParams queryParams(NAME_None, true);
							queryParams.AddIgnoredActor(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

							TArray<FHitResult> hitResults;
							GetWorld()->LineTraceMultiByChannel(hitResults, startTrace, endTrace, ECC_Visibility, queryParams);
							
							for (const FHitResult& hitResult : hitResults)
							{
								if (hitResult.GetActor()  == taskMeshActor)
								{
									SetCoord(FGeodeticCoord3D(globeLocation.Longitude, globeLocation.Latitude, geoExtents.Min.Z), false);
								}
							}
						}
					}
				}
			}
		}
	}

	if (geoExtents.IsValid)
	{
		SnapToGround(FBox2D(FVector2D(geoExtents.Min), FVector2D(geoExtents.Max)));
	}
}

void AGame_VirtualObjective::HandleServerDatabaseReady()
{
	Initialize();
}

void AGame_VirtualObjective::PeriodicCheckRelevancy()
{
	if (bIsInitialized && bEnabled)
	{
		AVH_GlobeReferenceActor* globeReference = GetGlobeReference();

		if (!IsValid(ViewpointActor) || !IsValid(globeReference))
		{
			return;
		}

		FGeodeticCoord3D updateCoordinate;

		FGeodeticCoord3D viewpointActorCoordinate = globeReference->WorldToGeodeticDouble(ViewpointActor->GetActorLocation());

		if (IsLocalPlayerInTOC())
		{
			// in the TOC, update if viewpoint has changed
			if (bNeedsUpdate || (viewpointActorCoordinate != LastRelevancyUpdateCoordinate))
			{
				updateCoordinate = viewpointActorCoordinate;

				bNeedsUpdate = true;
			}
		}
		else
		{
			// outside the TOC, update if viewpoint coordinate has changed more than 200m
			double distanceMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(viewpointActorCoordinate.ToGeodeticCoord2D(), LastRelevancyUpdateCoordinate.ToGeodeticCoord2D());
			distanceMeters = FMath::Max<double>(distanceMeters, FMath::Abs<double>(viewpointActorCoordinate.Altitude - LastRelevancyUpdateCoordinate.Altitude));
			if (bNeedsUpdate || distanceMeters > 200)
			{
				updateCoordinate = viewpointActorCoordinate;

				bNeedsUpdate = true;
			}
		}

		if (bNeedsUpdate)
		{
			bNeedsUpdate = false;

			UpdateRelevancySet(updateCoordinate);
		}
	}
}

void AGame_VirtualObjective::PeriodicLoadEntities()
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		for (int32 i = 0; i < 10; i++)
		{
			if (QueuedToLoad.Num() > 0)
			{
				FString loadedEntityUID = *QueuedToLoad.begin();

				SpatialiteResult result = entityDB->QueryUIDForResult(loadedEntityUID).Result;
			
				entityDB->LoadEntity(this, result, nullptr, EntityDetailLevel);
			
				QueuedToLoad.Remove(loadedEntityUID);
			}
			else
			{
				break;
			}
		}
	}
}