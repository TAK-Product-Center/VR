// Required Includes
#include "Game_TileManager.h"
#include "Game.h"

// Engine Includes
#include "Async/Async.h"
#include "Engine/Texture2D.h"

// VH Plugin Includes
#include "VH_COTDelegates.h"
#include "VH_GlobeMathStatics.h"
#include "VH_GlobeReferenceActor.h"
#include "Developer_Statics.h"
#include "Developer_Subsystem_TaskTracker.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_TerrainTile.h"
#include "Game_TileComponent.h"
#include "Game_TileComponent_Mat.h"
#include "Game_MatComponent_XML.h"
#include "Game_MatComponent_TAKTICS.h"
#include "Game_MatComponent_CesiumIon.h"
#include "Game_MeshComponent_Mapbox.h"
#include "Game_MeshComponent_DTED.h"
#include "Game_MeshComponent_CesiumIon.h"
#include "Game_TileComponent_OWT.h"
#include "Game_TileComponent_NGAGrid.h"
#include "Game_VectorTile_MapBox.h"
#include "Game_PlayerState.h"
#include "Game_Statics.h"
#include "Game_GameState.h"
#include "Game_Subsystem_Core.h"
#include "Game_MeshComponent_Ellipsoid.h"
#include "Game_Pawn.h"

UGame_TileManager* UGame_TileManager::GlobalInstance = nullptr;

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_TileManager::UGame_TileManager() :
	InnerTileMaxViewDistanceMeters(50000),
	InnerTileAGLThresholdMeters(5000),  // must match in Game_Pawn::Tick | todo ohg: don't hardcode
	MaxActiveHTTPRequests(999),
    bEnabled(false),
	bSetEnabledInitial(false),
	TileUpdateTime(0.025),
	HTTPRequestLastCheck(0),
	HTTPRequestCooldown(0.1),
	MinImageryZoomLevel(14),
	MaxImageryZoomLevel(16),
	MinHeightmapZoomLevel(12),
	MaxHeightmapZoomLevel(13)
{
    if (!HasAnyFlags(RF_ClassDefaultObject))
    {
        GlobalInstance = this;
    }
}

// ---------------------------------
// --- FTickableObjectBase Interface
// ---------------------------------

bool UGame_TileManager::IsTickable() const
{
	return this == GlobalInstance;
}

void UGame_TileManager::Tick(float deltaSeconds)
{
	if (!bSetEnabledInitial)
	{
		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			SetEnabled(gameSettings->GetSettingBool(TEXT("ShouldStreamTiles")));
			bSetEnabledInitial = true;
		}
	}

	if (UWorld* world = UDeveloper_Statics::GetVHWorld())
	{
		float timeSeconds = world->GetTimeSeconds();

		if (timeSeconds - HTTPRequestLastCheck < 0)
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_TileManager::Tick | timeSeconds - HTTPRequestLastCheck is negative"));

			HTTPRequestLastCheck = 0;
		}

		if (timeSeconds - HTTPRequestLastCheck >= HTTPRequestCooldown)
		{
			ProcessHTTPRequests();

			HTTPRequestLastCheck = timeSeconds;
		}

		if (!bLatentInitialized)
		{
			LatentInitialize();
		}
	}
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_TileManager* UGame_TileManager::Create(TSubclassOf<class UGame_TileManager> managerClass)
{
	if (GlobalInstance == nullptr)
	{
		if (UGame_TileManager* tileManager = NewObject<UGame_TileManager>(GetTransientPackage(), managerClass))
		{
			return tileManager;
		}

		UE_LOG(Game, Warning, TEXT("-- UGame_TileManager::Create | could not create TileManager"));
		return nullptr;
	}

	return GlobalInstance;
}

UGame_TileManager* UGame_TileManager::Get()
{
    return UGame_TileManager::GlobalInstance;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool UGame_TileManager::IsReadyForFinishDestroy()
{
	return Super::IsReadyForFinishDestroy() && DestroyCounter.GetValue() == 0;
}

void UGame_TileManager::BeginDestroy()
{
	// cancel pending http requests
	for (TPair<FString, FHTTPRequestInfo>& entry : HTTPRequests)
	{
		entry.Value.HTTPRequest->CancelRequest();
	}

	HTTPRequests.Empty();

	GlobalInstance = nullptr;

	Super::BeginDestroy();
}

// ---------------------------------
// --- API
// ---------------------------------

bool UGame_TileManager::GetMinLoadedHAE(double& minLoadedHAE) const
{
	if (LoadedTiles.Num() == 0)
	{
		return false;
	}

	bool bValidHAE = false;

	minLoadedHAE = DBL_MAX;
	for (const TPair<ETileID, AGame_TerrainTile*>& pair : LoadedTiles)
	{
		FVector2D haeBounds;
		if (pair.Value->GetHAEBounds(haeBounds))
		{
			minLoadedHAE = FMath::Min<double>(minLoadedHAE, haeBounds.X);

			bValidHAE = true;
		}
	}

	return bValidHAE;
}

void UGame_TileManager::SetEnabled(bool isEnabled)
{
	if (bEnabled != isEnabled)
	{
		bEnabled = isEnabled;

		if (bEnabled)
		{
			UWorld* world = UDeveloper_Statics::GetVHWorld();

			world->GetTimerManager().SetTimer(LocationTimerHandle, this, &UGame_TileManager::PeriodicUpdateForViewpointLocation, 0.5, true);
			world->GetTimerManager().SetTimer(HelperThreadTimerHandle, this, &UGame_TileManager::PeriodicProcessHelperThreadQueue, TileUpdateTime, true);
			world->GetTimerManager().SetTimer(GameThreadTimerHandle, this, &UGame_TileManager::PeriodicProcessGameThreadQueue, TileUpdateTime, true);
			world->GetTimerManager().SetTimer(DestroyTimerHandle, this, &UGame_TileManager::PeriodicProcessDestroyQueue, 0.1, true);

			FCoreDelegates::PostWorldOriginOffset.AddUObject(this, &UGame_TileManager::PostWorldOriginOffset);

			if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
			{
				playerState->OnIsInTOCUpdated.AddUniqueDynamic(this, &UGame_TileManager::HandlePlayerIsInTOCUpdated);
			}

			bForceUpdate = true;
		}
		else
		{
			Cleanup();

			if (AGame_TerrainTile** tilePtr = LoadedTiles.Find(ETileID::Outer))
			{
				// NOTE: Might need more work. At this point, all the tiles are not actually destroyed yet, so its collision is still in the world, etc.
				OnTileDisabled.Broadcast(*tilePtr);
			}
		}
	}
}

bool UGame_TileManager::IsEnabled() const
{
	return bEnabled;
}

void UGame_TileManager::ClearTiles()
{
	DestroyLoadedTiles(true);
}

void UGame_TileManager::RegisterTileComponent(const FTerrainSourceInfo& terrainSourceInfo)
{
	IDToTerrainSourceInfo.Add(terrainSourceInfo.ID, terrainSourceInfo);
}

TArray<FString> UGame_TileManager::GetImageryComponentIDs() const
{
	TArray<FString> componentIDs;

	for (const TPair<FString, FTerrainSourceInfo>& entry : IDToTerrainSourceInfo)
	{
		if (entry.Value.ComponentClass->IsChildOf(UGame_TileComponent_Mat::StaticClass()))
		{
			componentIDs.AddUnique(entry.Key);
		}
	}

	return componentIDs;
}

TArray<FString> UGame_TileManager::GetHeightmapComponentIDs() const
{
	TArray<FString> componentIDs;

	for (const TPair<FString, FTerrainSourceInfo>& entry : IDToTerrainSourceInfo)
	{
		if (!entry.Key.Equals(TEXT("ellipsoid_heightmap")))
		{
			if (entry.Value.ComponentClass->IsChildOf(UGame_TileComponent_Mesh::StaticClass()))
			{
				componentIDs.AddUnique(entry.Key);
			}
		}
	}

	return componentIDs;
}

TArray<FString> UGame_TileManager::GetOtherComponentIDs() const
{
	TArray<FString> heightmap = GetHeightmapComponentIDs();
	TArray<FString> imagery = GetImageryComponentIDs();

	TArray<FString> componentIDs;

	for (const TPair<FString, FTerrainSourceInfo>& entry : IDToTerrainSourceInfo)
	{
		if (!entry.Key.Equals(TEXT("ellipsoid_heightmap")))
		{
			if (!heightmap.Contains(entry.Key) && !imagery.Contains(entry.Key))
			{
				componentIDs.AddUnique(entry.Key);
			}
		}
	}

	return componentIDs;
}

void UGame_TileManager::GetActiveComponentIDs(TArray<FString>& activeComponentIDs) const
{
	activeComponentIDs.Append(ActiveComponentIDs);
}

void UGame_TileManager::AddActiveComponentID(const FString& activeComponentID, bool bBroadcastDelegate)
{
	// ensure id is registered
	if (FTerrainSourceInfo* terrainSourceInfo = IDToTerrainSourceInfo.Find(activeComponentID))
	{
		TSubclassOf<UGame_TileComponent> classToAdd = terrainSourceInfo->ComponentClass;

		// ensure only 1 mesh producing component
		if ((*classToAdd)->IsChildOf(UGame_TileComponent_Mesh::StaticClass()))
		{
			for (const FString& id : ActiveComponentIDs)
			{
				if (FTerrainSourceInfo* terrainSourceInfoActive = IDToTerrainSourceInfo.Find(id))
				{
					TSubclassOf<UGame_TileComponent> activeClass = terrainSourceInfoActive->ComponentClass;
					if ((*activeClass)->IsChildOf(UGame_TileComponent_Mesh::StaticClass()))
					{
						UE_LOG(Game, Warning, TEXT("-- error adding %s | can only have 1 active heightmap component"), *activeComponentID);
						return;
					}
				}
			}
		}

		ActiveComponentIDs.AddUnique(activeComponentID);

		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			FString dbString = TEXT("");
			for (int32 i = 0; i < ActiveComponentIDs.Num(); i++)
			{
				dbString += ActiveComponentIDs[i];

				if (i + 1 < ActiveComponentIDs.Num())
				{
					dbString += "|";
				}
			}

			gameSettings->StoreSettingString(TEXT("ActiveStreamingComponentIDs"), dbString);

			bForceUpdate = true;
		}

		if (bBroadcastDelegate)
		{
			OnActiveComponentsModified.Broadcast();
		}
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- id is not registered with Game_TileManager, aborting | %s"), *activeComponentID);
		return;
	}
}

void UGame_TileManager::RemoveActiveComponentID(const FString& activeComponentID, bool bBroadcastDelegate)
{
	ActiveComponentIDs.Remove(activeComponentID);

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		FString dbString = TEXT("");
		for (int32 i = 0; i < ActiveComponentIDs.Num(); i++)
		{
			dbString += ActiveComponentIDs[i];

			if (i + 1 < ActiveComponentIDs.Num())
			{
				dbString += "|";
			}
		}

		gameSettings->StoreSettingString(TEXT("ActiveStreamingComponentIDs"), dbString);
	}

	if (bBroadcastDelegate)
	{
		OnActiveComponentsModified.Broadcast();
	}
}

void UGame_TileManager::ClearActiveComponentIDs(bool bBroadcastDelegate)
{
	ActiveComponentIDs.Empty();

	if (bBroadcastDelegate)
	{
		OnActiveComponentsModified.Broadcast();
	}

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingString(TEXT("ActiveStreamingComponentIDs"), TEXT(""));
	}

	Cleanup();
}

bool UGame_TileManager::GetDTEDLevel(float latitude, float longitude, int32& dtedLevel)
{
	auto getDTEDLevel = [](FGeodeticCoord2D& coordinate, int32& dtedLevel, AGame_TerrainTile* terrainTile)
	{
		TPair<FGeodeticCoord2D, FGeodeticCoord2D> tileBounds = terrainTile->GetTileBounds();

		if (coordinate.Latitude <= tileBounds.Key.Latitude && coordinate.Longitude >= tileBounds.Key.Longitude &&
			coordinate.Latitude >= tileBounds.Value.Latitude && coordinate.Longitude <= tileBounds.Value.Longitude)
		{
			if (UGame_MeshComponent_DTED* meshComponent = Cast<UGame_MeshComponent_DTED>(terrainTile->GetComponentByClass(UGame_MeshComponent_DTED::StaticClass())))
			{
				return meshComponent->GetDTEDInfo(coordinate, dtedLevel);
			}
		}

		return false;
	};

	if (ActiveComponentIDs.Contains(TEXT("dted_heightmap")))
	{
		FGeodeticCoord2D coordinate(longitude, latitude);

		// try inner first
		if (AGame_TerrainTile** terrainTilePtr = LoadedTiles.Find(ETileID::Inner))
		{
			if (getDTEDLevel(coordinate, dtedLevel, *terrainTilePtr))
			{
				return true;
			}
		}

		// fallback to outer
		if (AGame_TerrainTile** terrainTilePtr = LoadedTiles.Find(ETileID::Outer))
		{
			if (getDTEDLevel(coordinate, dtedLevel, *terrainTilePtr))
			{
				return true;
			}
		}
	}

	return false;
}

void UGame_TileManager::SetMinImageryZoomLevel(int32 minImageryZoomLevel)
{
	if (minImageryZoomLevel != MinImageryZoomLevel)
	{
		MinImageryZoomLevel = minImageryZoomLevel;

		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			gameSettings->StoreSettingInt(TEXT("MinImageryZoomLevel"), MinImageryZoomLevel);
		}

		bForceUpdate = true;
	}
}

void UGame_TileManager::SetMaxImageryZoomLevel(int32 maxImageryZoomLevel)
{
	if (maxImageryZoomLevel != MaxImageryZoomLevel)
	{
		MaxImageryZoomLevel = maxImageryZoomLevel;

		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			gameSettings->StoreSettingInt(TEXT("MaxImageryZoomLevel"), MaxImageryZoomLevel);
		}

		bForceUpdate = true;
	}
}

void UGame_TileManager::SetMinHeightmapZoomLevel(int32 minHeightmapZoomLevel)
{
	if (minHeightmapZoomLevel != MinHeightmapZoomLevel)
	{
		MinHeightmapZoomLevel = minHeightmapZoomLevel;

		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			gameSettings->StoreSettingInt(TEXT("MinHeightmapZoomLevel"), MinHeightmapZoomLevel);
		}

		ClearTiles();

		bForceUpdate = true;
	}
}

void UGame_TileManager::SetMaxHeightmapZoomLevel(int32 maxHeightmapZoomLevel)
{
	if (maxHeightmapZoomLevel != MaxHeightmapZoomLevel)
	{
		MaxHeightmapZoomLevel = maxHeightmapZoomLevel;

		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			gameSettings->StoreSettingInt(TEXT("MaxHeightmapZoomLevel"), MaxHeightmapZoomLevel);
		}

		ClearTiles();

		bForceUpdate = true;
	}
}

void UGame_TileManager::AddHTTPRequest(const FString& identifier, UGame_TileComponent* requester, const TSharedRef<IHttpRequest, ESPMode::ThreadSafe>& httpRequest)
{
	AsyncTask(ENamedThreads::GameThread, [this, identifier, requester, httpRequest]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}

		if (HasHTTPRequest(identifier))
		{
			AddHTTPRequester(identifier, requester);
		}
		else
		{
			FHTTPRequestInfo httpRequestInfo(httpRequest);
			httpRequestInfo.Requesters.Add(requester);

			httpRequestInfo.HTTPRequest->OnProcessRequestComplete().BindLambda([identifier](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
			{
				if (UGame_TileManager* tileManager = UGame_TileManager::Get())
				{
					tileManager->OnHTTPRequestComplete(identifier, request, response, bSucceeded);
				}
			});

			HTTPRequests.Add(identifier, httpRequestInfo);
			
			UpdateTaskTracker();
		}

		DestroyCounter.Decrement();
	});
}

void UGame_TileManager::AddHTTPRequester(const FString& identifier, UGame_TileComponent* requester)
{
	AsyncTask(ENamedThreads::GameThread, [this, identifier, requester]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}

		if (FHTTPRequestInfo* httpRequestInfoPtr = HTTPRequests.Find(identifier))
		{
			httpRequestInfoPtr->Requesters.AddUnique(requester);
		}
		
		DestroyCounter.Decrement();
	});
}

void UGame_TileManager::RemoveHTTPRequests(UGame_TileComponent* requester)
{
	AsyncTask(ENamedThreads::GameThread, [this, requester]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}

		TArray<FString> toRemove;

		for (TPair<FString, FHTTPRequestInfo>& entry : HTTPRequests)
		{
			entry.Value.Requesters.Remove(requester);

			if (entry.Value.Requesters.Num() == 0)
			{
				entry.Value.HTTPRequest->CancelRequest();

				toRemove.Add(entry.Key);
			}
		}

		if (toRemove.Num() > 0)
		{
			for (const FString& key : toRemove)
			{
				HTTPRequests.Remove(key);
			}

			UpdateTaskTracker();
		}

		DestroyCounter.Decrement();
	});
}

int32 UGame_TileManager::GetNumHTTPRequests(UGame_TileComponent* requestor) const
{
	int32 numberOfRequests = 0;

	if (requestor == nullptr)
	{
		numberOfRequests = HTTPRequests.Num();
	}
	else
	{
		for (const TPair<FString, FHTTPRequestInfo>& entry : HTTPRequests)
		{
			if (entry.Value.Requesters.Contains(requestor))
			{
				numberOfRequests++;
			}
		}
	}

	return numberOfRequests;
}

void UGame_TileManager::PreModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference)
{
	TArray<ETileID> toRemove;
	for (const TPair<ETileID, AGame_TerrainTile*>& entry : LoadedTiles)
	{
		if (entry.Value->GetTileStatus() != ETileStatus::GameThreadFinished)
		{
			toRemove.Add(entry.Key);

			ToDestroy.Add(entry.Value);

			entry.Value->SetTileStatus(ETileStatus::ReadyForDestroy);

			entry.Value->SetActorHiddenInGame(true);
		}
		else
		{
			entry.Value->PreModifyVOGlobeReference(globeReference);
		}
	}

	for (int32 i = 0; i < toRemove.Num(); i++)
	{
		LoadedTiles.Remove(toRemove[i]);
	}
}

void UGame_TileManager::PostModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference)
{
	for (const TPair<ETileID, AGame_TerrainTile*>& entry : LoadedTiles)
	{
		entry.Value->PostModifyVOGlobeReference(globeReference);
	}
}

void UGame_TileManager::GlobeReferenceScaleUpdated(const FVector& newScale3D)
{
	for (const TPair<ETileID, AGame_TerrainTile*>& entry : LoadedTiles)
	{
		entry.Value->GlobeReferenceScaleUpdated(newScale3D);
	}
}

void UGame_TileManager::UpdateTileDrawDistances()
{
	float drawDistanceMeters = GetDrawDistanceMeters();

	if (AActor* actor = GetViewpointActor())
	{
		FVector centerLoc = actor->GetActorLocation() * FVector(1, 1, 0);

		for (const TPair<ETileID, AGame_TerrainTile*>& entry : LoadedTiles)
		{
			entry.Value->SetDrawDistance(centerLoc, drawDistanceMeters);
		}
	}
}

AGame_VirtualObjective* UGame_TileManager::GetVirtualObjective() const
{
	return VirtualObjective;
}

void UGame_TileManager::SetVirtualObjective(AGame_VirtualObjective* inVirtualObjective)
{
	if (VirtualObjective != inVirtualObjective)
	{
		VirtualObjective = inVirtualObjective;
	}
}

bool UGame_TileManager::GetHAE(const FGeodeticCoord2D& coordinate, double& hae) const
{
	for (const FString& componentID : ActiveComponentIDs)
	{
		if (const FGetHAE* lambdaPtr = ComponentIDToHAELambda.Find(componentID))
		{
			return lambdaPtr->Execute(coordinate, hae);
		}
	}

	if (const FGetHAE* lambdaPtr = ComponentIDToHAELambda.Find(TEXT("dted_heightmap")))
	{
		return lambdaPtr->Execute(coordinate, hae);
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_TileManager::GetHAE | could not find lambda for active components | returning false"));
	return false;
}

bool UGame_TileManager::GetHAEFromDTED(const FGeodeticCoord2D& coordinate, double& hae) const
{
	if (const FGetHAE* lambdaPtr = ComponentIDToHAELambda.Find(TEXT("dted_heightmap")))
	{
		return lambdaPtr->Execute(coordinate, hae);
	}

	return false;
}

bool UGame_TileManager::GetTerrainGrid(int32 xSlots, int32 ySlots, double distance, const FVector& viewshedCenter, TSet<FVector>& averageGridVertices) const
{
	// make sure all tiles are finished loading
	if (PendingTiles())
	{
		return false;
	}

	AGame_VirtualObjective* activeVO = GetVirtualObjective();
	if (activeVO != nullptr && activeVO->IsInitialized())
	{
		AVH_GlobeReferenceActor* globeReference = activeVO->GetGlobeReference();

		FGeodeticCoord2D center = globeReference->WorldToGeodeticDouble(viewshedCenter).ToGeodeticCoord2D();

		// find the edges of the visible terrain for the active virtual objective
		FGeodeticCoord2D midNorth = UVH_GlobeMathStatics::CalculateSurfaceDestination(center, 0.0, distance / 2.0);
		FGeodeticCoord2D northWest = UVH_GlobeMathStatics::CalculateSurfaceDestination(midNorth, 270.0, distance / 2.0);

		FGeodeticCoord2D midSouth = UVH_GlobeMathStatics::CalculateSurfaceDestination(center, 180.0, distance / 2.0);
		FGeodeticCoord2D southEast = UVH_GlobeMathStatics::CalculateSurfaceDestination(midSouth, 90.0, distance / 2.0);
			
		FGeodeticCoord2D northEast = FGeodeticCoord2D(southEast.Longitude, northWest.Latitude);
		FGeodeticCoord2D southWest = FGeodeticCoord2D(northWest.Longitude, southEast.Latitude);

		// divide the longitude and latitude into the number of slots requested in the parameters
		double longitudeSlotSize = (northEast.Longitude - northWest.Longitude) / xSlots;
		double latitudeSlotSize = (northEast.Latitude - southEast.Latitude) / ySlots;

		FCriticalSection addCriticalSection;
		FCriticalSection waitCriticalSection;

		/*
		* 0,2 1,2 2,2
		* 0,1 1,1 2,1
		* 0,0 1,0 2,0
		* 
		* populate gridLocations with middle of each grid cell
		*/
		waitCriticalSection.Lock();
		int32 totalSlots = xSlots * ySlots;

		TSet<FVector> gridLocations;
		ParallelFor(ySlots, [xSlots, globeReference, &waitCriticalSection, &addCriticalSection, totalSlots, northWest, southWest, latitudeSlotSize, longitudeSlotSize, &averageGridVertices](int32 y)
		{
			ParallelFor(xSlots, [globeReference, &waitCriticalSection, &addCriticalSection, totalSlots, northWest, southWest, latitudeSlotSize, longitudeSlotSize, &averageGridVertices, y](int32 x)
			{
				FGeodeticCoord2D min = FGeodeticCoord2D(northWest.Longitude + (longitudeSlotSize * x), southWest.Latitude + (latitudeSlotSize * y));
				FGeodeticCoord2D max = FGeodeticCoord2D(min.Longitude + longitudeSlotSize, min.Latitude + latitudeSlotSize);

				FGeodeticCoord2D middleGrid;
				middleGrid.Latitude = (min.Latitude + max.Latitude) / 2.f;
				middleGrid.Longitude = (min.Longitude + max.Longitude) / 2.f;
					
				FVector gridLocation = globeReference->GeodeticToWorldDouble(FGeodeticCoord3D(middleGrid, 0, true));

				{
					FScopeLock scopeLock(&addCriticalSection);

					averageGridVertices.Add(gridLocation);

					if (averageGridVertices.Num() == totalSlots)
					{
						waitCriticalSection.Unlock();
					}
				}
			});
		});

		FScopeLock scopeLock(&waitCriticalSection);
		return true;
	}

	return false;
}

void UGame_TileManager::ForceUpdate()
{
	bForceUpdate = true;
}

AGame_TerrainTile* UGame_TileManager::GetTile(ETileID tileID) const
{
	if (AGame_TerrainTile* const* terrainTilePtr = LoadedTiles.Find(tileID))
	{
		return *terrainTilePtr;
	}

	return nullptr;
}

bool UGame_TileManager::PendingTiles() const
{
	for (const TPair<ETileID, AGame_TerrainTile*>& entry : LoadedTiles)
	{
		if (entry.Value->GetTileStatus() == ETileStatus::Default)
		{
			return true;
		}
	}

	return false;
}

float UGame_TileManager::GetDrawDistanceMeters() const
{
	float drawDistanceMeters = 10000;

	AGame_VirtualObjective* activeVO = GetVirtualObjective();
	if (activeVO == nullptr || !activeVO->IsInitialized())
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_TileManager::GetDrawDistance | activeVO is nullptr or not initialized"));
	}
	else 
	{
		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			drawDistanceMeters = gameSettings->GetSettingDouble(TEXT("TileViewDistance"));
		}

		if (UGame_Statics::IsLocalPlayerInTOC())
		{
			drawDistanceMeters = activeVO->TOCTileViewDistance;
		}
	}

	return drawDistanceMeters;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_TileManager::LatentInitialize()
{
	bool bSuccess = false;

	FWorldDelegates::OnWorldCleanup.AddUObject(this, &UGame_TileManager::HandleWorldCleanup);

	for (int32 i = 0; i < 2; i++)
	{
		UTexture2D* texture = UTexture2D::CreateTransient(16384, 16384);
		texture->AddressX = TextureAddress::TA_Clamp;
		texture->AddressY = TextureAddress::TA_Clamp;
		texture->UpdateResource();

		InnerTextures.Add(texture, nullptr);
	}

	for (int32 i = 0; i < 2; i++)
	{
		UTexture2D* texture = UTexture2D::CreateTransient(4096, 4096);
		texture->AddressX = TextureAddress::TA_Clamp;
		texture->AddressY = TextureAddress::TA_Clamp;
		texture->UpdateResource();

		InnerTOCTextures.Add(texture, nullptr);
	}
	
	for (int32 i = 0; i < 2; i++)
	{
		UTexture2D* texture = UTexture2D::CreateTransient(8192, 8192);
		texture->AddressX = TextureAddress::TA_Clamp;
		texture->AddressY = TextureAddress::TA_Clamp;
		texture->UpdateResource();

		OuterTextures.Add(texture, nullptr);
	}

	EllipsoidTexture = UTexture2D::CreateTransient(8192, 8192);
	EllipsoidTexture->AddressX = TextureAddress::TA_Clamp;
	EllipsoidTexture->AddressY = TextureAddress::TA_Clamp;
	EllipsoidTexture->UpdateResource();

	// initialize all default settings
	UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings();
	if (gameSettings != nullptr)
	{
		bSuccess = true;

		// store default advanced settings
		// TODO: Expose these literals (and others set above) in a config ini (or maybe just a TileManagerBP?) so they can be overridden without a code compile.
		//       (e.g. "DefaultTileTrianglesPerComponent", etc.)
		gameSettings->StoreDefaultSettingDouble(TEXT("TileTrianglesPerComponent"), 200000);
		gameSettings->StoreDefaultSettingDouble(TEXT("TileSecondsBetweenComponentCreate"), 0.05);
		gameSettings->StoreDefaultSettingBool(TEXT("ShouldStreamTiles"), true);
		gameSettings->StoreDefaultSettingDouble(TEXT("TileViewDistance"), 10000);
		gameSettings->StoreDefaultSettingInt(TEXT("MinImageryZoomLevel"), 14);
		gameSettings->StoreDefaultSettingInt(TEXT("MaxImageryZoomLevel"), 16);
		gameSettings->StoreDefaultSettingInt(TEXT("MinHeightmapZoomLevel"), 12);
		gameSettings->StoreDefaultSettingInt(TEXT("MaxHeightmapZoomLevel"), 13);
		gameSettings->StoreDefaultSettingString(TEXT("ImageryDirectory"), TEXT("C:\\ProgramData\\WinTAK\\ImageCache"));
		gameSettings->StoreDefaultSettingString(TEXT("OfflineImageryDirectory"), TEXT("C:\\ProgramData\\WinTAK\\Imagery"));
		gameSettings->StoreDefaultSettingBool(TEXT("OverrideOuterTileSource"), true);

		// store default active streaming component ids
		gameSettings->StoreDefaultSettingString(TEXT("ActiveStreamingComponentIDs"), TEXT("xml_imagery|dted_heightmap"));

		// store defaults for terrain sources
		FString defaultDTEDPath = gameSettings->GetDefaultSettingString(TEXT("dted_heightmap.FullPathsToDTED"));
		UGame_MeshComponent_DTED::StaticAutoExtractArchive(defaultDTEDPath);
		
		gameSettings->StoreDefaultSettingString(TEXT("xml_imagery.FullPathsToImageryXMLs"), FPaths::Combine(FPaths::RootDir(), TEXT("Data"), TEXT("TerrainXML")));
		gameSettings->StoreDefaultSettingString(TEXT("xml_imagery.ImagerySourceName"), FString::Printf(TEXT("Bing Hybrid")));

		gameSettings->StoreDefaultSettingString(TEXT("dted_heightmap.FullPathsToDTED"), FString::Printf(TEXT("%s/VRTAK/dted"), *UDeveloper_Statics::GetCommonAppDataPath()));

		gameSettings->StoreDefaultSettingDouble(TEXT("taktics_imagery.GammaCorrection"), 1);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_TileManager::Initialize | GameSettings is nullptr"));
	}

	// mapbox
	if (FParse::Param(FCommandLine::Get(), TEXT("dev")))
	{
		FGetHAE getHAEDelegate;
		getHAEDelegate.BindLambda([](const FGeodeticCoord2D& coord, double& hae)
		{
			return UGame_MeshComponent_Mapbox::GetHAE(coord, hae);
		});

		ComponentIDToHAELambda.Add(TEXT("mapbox_heightmap"), getHAEDelegate);
	}

	// dted
	{
		FGetHAE getHAEDelegate;
		getHAEDelegate.BindLambda([](const FGeodeticCoord2D& coord, double& hae)
		{
			return UGame_MeshComponent_DTED::GetHAE(coord, hae);
		});

		ComponentIDToHAELambda.Add(TEXT("dted_heightmap"), getHAEDelegate);
	}

	// Cesium heightmap
	{
		FGetHAE getHAEDelegate;
		getHAEDelegate.BindLambda([](const FGeodeticCoord2D& coord, double& hae)
		{
			return UGame_MeshComponent_CesiumIon::GetHAE(coord, hae);
		});

		ComponentIDToHAELambda.Add(TEXT("cesium_heightmap"), getHAEDelegate);
	}

	// init values from stored settings
	if (gameSettings != nullptr)
	{
		gameSettings->OnDoubleSettingStored.AddDynamic(this, &UGame_TileManager::HandleDoubleSettingChanged);
		gameSettings->OnBoolSettingStored.AddDynamic(this, &UGame_TileManager::HandleBoolSettingChanged);

		// load advanced settings
		MinImageryZoomLevel = gameSettings->GetSettingInt(TEXT("MinImageryZoomLevel"));
		MaxImageryZoomLevel = gameSettings->GetSettingInt(TEXT("MaxImageryZoomLevel"));

		MinHeightmapZoomLevel = gameSettings->GetSettingInt(TEXT("MinHeightmapZoomLevel"));
		MaxHeightmapZoomLevel = gameSettings->GetSettingInt(TEXT("MaxHeightmapZoomLevel"));

		bOverrideOuterTileSource = gameSettings->GetSettingBool(TEXT("OverrideOuterTileSource"));

		// load active streaming component ids
		FString activeIDs = gameSettings->GetSettingString(TEXT("ActiveStreamingComponentIDs"));
		TArray<FString> tempArray;
		activeIDs.ParseIntoArray(tempArray, TEXT("|"));

		for (const FString& entry : tempArray)
		{
			ActiveComponentIDs.AddUnique(entry);
		}
	}

	FVH_COTDelegates::OnCOTMessageReceived.Broadcast(TEXT("TileManagerInitialized"), FVariant());

	bLatentInitialized = true;
}

UTexture2D* UGame_TileManager::GetHighResTexture(AGame_TerrainTile* terrainTile)
{
	if (terrainTile == GetTile(ETileID::Ellipsoid))
	{
		return EllipsoidTexture;
	}
	else if (terrainTile == GetTile(ETileID::Outer))
	{
		for (TPair<UTexture2D*, AGame_TerrainTile*>& entry : OuterTextures)
		{
			if (entry.Value == nullptr || entry.Value->IsHidden())
			{
				entry.Value = terrainTile;

				return entry.Key;
			}
		}
	}
	else if (terrainTile == GetTile(ETileID::Inner))
	{
		if (UGame_Statics::IsLocalPlayerInTOC())
		{
			for (TPair<UTexture2D*, AGame_TerrainTile*>& entry : InnerTOCTextures)
			{
				if (entry.Value == nullptr || entry.Value->IsHidden())
				{
					entry.Value = terrainTile;

					return entry.Key;
				}
			}
		}
		else
		{
			for (TPair<UTexture2D*, AGame_TerrainTile*>& entry : InnerTextures)
			{
				if (entry.Value == nullptr || entry.Value->IsHidden())
				{
					entry.Value = terrainTile;

					return entry.Key;
				}
			}
		}
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_TileManager::GetHighResTexture | could not find texture | returning nullptr"));
	return nullptr;
}

bool UGame_TileManager::HasHTTPRequest(const FString& identifier)
{
	return HTTPRequests.Contains(identifier);
}

void UGame_TileManager::OnHTTPRequestComplete(const FString& identifier, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful)
{
	AsyncTask(ENamedThreads::GameThread, [this, identifier, request, response, bWasSuccessful]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}

		TArray<UGame_TileComponent*> requesters;
		if (FHTTPRequestInfo* fileRequestInfoPtr = HTTPRequests.Find(identifier))
		{
			requesters.Append(fileRequestInfoPtr->Requesters);
		
			for (UGame_TileComponent* requester : requesters)
			{
				requester->OnHTTPRequestComplete(identifier, request, response, bWasSuccessful);
			}
		}

		HTTPRequests.Remove(identifier);

		UpdateTaskTracker();

		DestroyCounter.Decrement();
	});
}

AActor* UGame_TileManager::GetViewpointActor() const
{
	if (AGame_VirtualObjective* activeVO = GetVirtualObjective())
	{
		return activeVO->GetViewpointActor();
	}

	return nullptr;
}

AGame_TerrainTile* UGame_TileManager::LoadTile(ETileID tileID, const FGeodeticCoord2D& centerGeodetic, double viewDistanceMeters, int32 imageryZoomLevel, int32 heightmapZoomLevel, TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds)
{
	auto compareBounds = [](const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& boundsA, const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& boundsB) -> bool
	{
		return boundsA.Key == boundsB.Key && boundsA.Value == boundsB.Value;
	};

	if (viewDistanceMeters == -1)
	{
		tileBounds.Key = FGeodeticCoord2D(-180, 85.0511);
		tileBounds.Value = FGeodeticCoord2D(180, -85.0511);
	}
	else
	{
		FGeodeticCoord2D midNorth = UVH_GlobeMathStatics::CalculateSurfaceDestination(centerGeodetic, 0.0, viewDistanceMeters / 2.0);
		FGeodeticCoord2D northWest = UVH_GlobeMathStatics::CalculateSurfaceDestination(midNorth, 270.0, viewDistanceMeters / 2.0);

		FGeodeticCoord2D midSouth = UVH_GlobeMathStatics::CalculateSurfaceDestination(centerGeodetic, 180.0, viewDistanceMeters / 2.0);
		FGeodeticCoord2D southEast = UVH_GlobeMathStatics::CalculateSurfaceDestination(midSouth, 90.0, viewDistanceMeters / 2.0);

		tileBounds.Key = northWest;
		tileBounds.Value = southEast;
	}

	TPair<FGeodeticCoord2D, FGeodeticCoord2D> newTileBounds(tileBounds.Key, tileBounds.Value);

	if (AGame_TerrainTile** loadedTileForZoomPtr = LoadedTiles.Find(tileID))
	{
		// tile exists with requested tileID
		AGame_TerrainTile* loadedTile = *loadedTileForZoomPtr;

		if (heightmapZoomLevel == loadedTile->GetHeightmapZoomLevel() &&
			imageryZoomLevel == loadedTile->GetImageryZoomLevel() &&
			compareBounds(tileBounds, loadedTile->GetTileBounds()))
		{
			// existing tile has requested specs; return early
			return loadedTile;
		}
		else
		{
			// existing tile does not have correct specs; destroy it
			loadedTile->SetTileStatus(ETileStatus::ReadyForDestroy);

			LoadedTiles.Remove(tileID);

			ToDestroy.AddUnique(loadedTile);
		}
	}

	// create new tile
	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		
	AGame_TerrainTile* terrainTile = UDeveloper_Statics::GetVHWorld()->SpawnActor<AGame_TerrainTile>(AGame_TerrainTile::StaticClass(), spawnParams);

#if WITH_EDITOR
	FName runtimeFolderName = FName(*FString::Printf(TEXT("/Runtime/DynContent/TerrainTiles/%d"), (int32)tileID));
	terrainTile->SetFolderPath(runtimeFolderName);
#endif

	// set material size
	if (tileID == ETileID::Inner)
	{
		if (UGame_Statics::IsLocalPlayerInTOC())
		{
			terrainTile->MatSizeX = 4096;
			terrainTile->MatSizeY = 4096;
		}
		else
		{
			terrainTile->MatSizeX = 16384;
			terrainTile->MatSizeY = 16384;
		}
	}
	else
	{
		terrainTile->MatSizeX = 8192;
		terrainTile->MatSizeY = 8192;
	}

	if (tileID == ETileID::Ellipsoid)
	{
		terrainTile->MatSizeX = 8192;
		terrainTile->MatSizeY = 8192;
	}

	terrainTile->SetActorHiddenInGame(ToDestroy.Num() > 0);
	terrainTile->SetBoundsAndZoom(tileBounds, heightmapZoomLevel, imageryZoomLevel);

	terrainTile->OnTileStatusChanged.AddUObject(this, &UGame_TileManager::HandleTileStatusChanged);
	terrainTile->OnDestroyed.AddDynamic(this, &UGame_TileManager::RemoveDestroyedTile);

	bool bAddedAtLeastOneComponent = false;
	for (const FString& activeID : ActiveComponentIDs)
	{
		if (FTerrainSourceInfo* terrainSourceInfo = IDToTerrainSourceInfo.Find(activeID))
		{
			TSubclassOf<UGame_TileComponent> componentClass = terrainSourceInfo->ComponentClass;
			terrainTile->AddTileComponent(activeID, componentClass);

			bAddedAtLeastOneComponent = true;
		}
	}

	if (bAddedAtLeastOneComponent)
	{
		LoadedTiles.Add(tileID, terrainTile);

		terrainTile->Texture = GetHighResTexture(terrainTile);

		return terrainTile;
	}
		
	// no added components; delete tile
	UE_LOG(Game, Warning, TEXT("-- UGame_TileManager::LoadTile | no active components added | returning nullptr"))

	terrainTile->Destroy();
	
	return nullptr;
}

void UGame_TileManager::PeriodicUpdateForViewpointLocation()
{
	auto setImageryCutOn = [this](ETileID tileID, const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& cutBounds)
	{
		if (AGame_TerrainTile** terrainTilePtr = LoadedTiles.Find(tileID))
		{
			AGame_TerrainTile* terrainTile = *terrainTilePtr;
			
			terrainTile->SetImageryCut(cutBounds.Key, cutBounds.Value);
		}
	};

	auto clearImageryCutFrom = [this](ETileID tileID)
	{
		if (AGame_TerrainTile** terrainTilePtr = LoadedTiles.Find(tileID))
		{
			AGame_TerrainTile* terrainTile = *terrainTilePtr;
			
			terrainTile->ClearImageryCut();
		}
	};

	auto setCollisionCutOn = [this](ETileID tileID, const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& cutBounds, bool bCutAllCollision)
	{
		if (AGame_TerrainTile** terrainTilePtr = LoadedTiles.Find(tileID))
		{
			AGame_TerrainTile* terrainTile = *terrainTilePtr;

			terrainTile->SetCollisionCut(cutBounds.Key, cutBounds.Value, bCutAllCollision);
		}
	};

	auto clearCollisionCutFrom = [this](ETileID tileID)
	{
		if (AGame_TerrainTile** terrainTilePtr = LoadedTiles.Find(tileID))
		{
			AGame_TerrainTile* terrainTile = *terrainTilePtr;

			terrainTile->ClearCollisionCut();
		}
	};

	auto unloadTile = [this](ETileID tileID)
	{
		if (AGame_TerrainTile** terrainTilePtr = LoadedTiles.Find(tileID))
		{
			AGame_TerrainTile* terrainTile = *terrainTilePtr;

			terrainTile->SetTileStatus(ETileStatus::ReadyForDestroy);

			LoadedTiles.Remove(tileID);

			ToDestroy.AddUnique(terrainTile);
		}
	};

	auto setDrawDistance = [this](AGame_TerrainTile* tile, const FVector& center, float drawDistance)
	{
		// disregard height for render distance checks with heightmap mesh vertices
		FVector adjustedCenter = center * FVector(1, 1, 0);

		tile->SetDrawDistance(adjustedCenter, drawDistance);
	};

	if (bPauseUpdate)
	{
		return;
	}

	if (AGame_GameState* gameState = UGame_Statics::GetVHGameState())
	{
		if (gameState->GetPanningPlayerState() != nullptr)
		{
			return;
		}
	}

	AGame_VirtualObjective* activeVO = GetVirtualObjective();
	if (activeVO == nullptr || !activeVO->IsInitialized())
	{
		bForceUpdate = true;
		return;
	}

	AVH_GlobeReferenceActor* globeRef = activeVO->GetGlobeReference();
	if (!IsValid(globeRef))
	{
		bForceUpdate = true;
		return;
	}
	
	// todo ohg | attempt to bind to the delegate only once
	activeVO->OnTOCViewDistanceChanged.AddUniqueDynamic(this, &UGame_TileManager::HandleTOCViewDistanceChanged);
	activeVO->OnGlobeReferenceGeoLocationChanged.AddUniqueDynamic(this, &UGame_TileManager::HandleVOGlobeReferenceGeoLocationChanged);

	bool bInTOC = UGame_Statics::IsLocalPlayerInTOC();

	int32 outerImageryZoomLevel = 11;
	double outerTileDistanceMeters = 100000;

	if (bInTOC)
	{
		unloadTile(ETileID::Outer);
		unloadTile(ETileID::Ellipsoid);
	}
	else
	{
		// ellipsoid tile if doesn't exist already and not in TOC
		if (!LoadedTiles.Contains(ETileID::Ellipsoid))
		{
			TArray<FString> activeComponentIDsCache;
			activeComponentIDsCache.Append(ActiveComponentIDs);

			ActiveComponentIDs.Empty();
			ActiveComponentIDs.Add("ellipsoid_heightmap");
			ActiveComponentIDs.Add("xml_imagery");

			TPair<FGeodeticCoord2D, FGeodeticCoord2D> tileBounds;
			LoadTile(ETileID::Ellipsoid, FGeodeticCoord2D(0, 0), -1, 5, 5, tileBounds);

			ActiveComponentIDs.Empty();
			ActiveComponentIDs.Append(activeComponentIDsCache);
		}

		// if above certain AGL and not in TOC, unload inner and outer
		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			FGeodeticCoord3D playerCoordinate = globeRef->WorldToGeodeticDouble(playerPawn->GetActorLocation());

			double terrainHAE = globeRef->GetTerrainElevationDouble(playerCoordinate.ToGeodeticCoord2D());
			if (!FMath::IsNearlyEqual(terrainHAE, -999999.f))
			{
				double metersAGL = playerCoordinate.Altitude - terrainHAE;
				//UE_LOG(LogTemp, Warning, TEXT("-- agl: %f"), metersAGL);
				if (metersAGL >= 400000)
				{
					unloadTile(ETileID::Inner);
					unloadTile(ETileID::Outer);

					clearImageryCutFrom(ETileID::Ellipsoid);
					clearCollisionCutFrom(ETileID::Ellipsoid);

					LastMetersAGL = metersAGL;

					// finished
					return;
				}

				TArray<double> thresholds;
				thresholds.Add(5000);
				thresholds.Add(50000);
				thresholds.Add(100000);
				thresholds.Add(200000);
				thresholds.Add(400000);
				for (double threshold : thresholds)
				{
					if (metersAGL <= threshold && LastMetersAGL > threshold || metersAGL > threshold && LastMetersAGL <= threshold)
					{
						// player crossed AGL threshold
						bForceUpdate = true;
					}
				}
				
				if (metersAGL > 200000)
				{
					outerImageryZoomLevel = 7;
					outerTileDistanceMeters = 1600000;
				}
				else if (metersAGL > 100000)
				{
					outerImageryZoomLevel = 8;
					outerTileDistanceMeters = 800000;
				}
				else if (metersAGL > 50000)
				{
					outerImageryZoomLevel = 9;
					outerTileDistanceMeters = 200000;
				}
				else
				{
					outerImageryZoomLevel = 11;
					outerTileDistanceMeters = 200000;
				}
				
				LastMetersAGL = metersAGL;
			}
			else
			{
				// couldn't determine AGL; abort and try again next time
				bForceUpdate = true;

				return;
			}
		}
	}

	if (AActor* viewpointActor = GetViewpointActor())
	{
		// determine if terrain tiles need an update
		bool bShouldUpdate = bForceUpdate;

		FGeodeticCoord2D viewpointCoordinate = globeRef->WorldToGeodeticDouble(viewpointActor->GetActorLocation()).ToGeodeticCoord2D();

		if (!bShouldUpdate)
		{
			// check if viewpointCoordinate has changed more than specified threshold
			double surfaceDistanceMeters = UVH_GlobeMathStatics::CalculateSurfaceDistance(viewpointCoordinate, ViewpointCoordinateOfLastUpdate);

			// movement threshold uses outer tile when inner tile is not rendered
			double movementThresholdMeters;
			if (IsValid(GetTile(ETileID::Inner)))
			{
				movementThresholdMeters = FMath::Min<double>(GetDrawDistanceMeters(), InnerTileMaxViewDistanceMeters) * 0.2;
			}
			else
			{
				movementThresholdMeters = outerTileDistanceMeters * 0.2;
			}
			

			if (surfaceDistanceMeters > movementThresholdMeters)
			{
				bShouldUpdate = true;
			}
		}

		// update if we need to
		if (bShouldUpdate)
		{
			OnTerrainUpdate.Broadcast();

			ViewpointCoordinateOfLastUpdate = viewpointCoordinate;

			bForceUpdate = false;

			float drawDistanceMeters = GetDrawDistanceMeters();

			// outer tile (always off in TOC; always on outside of TOC if we get to this part of code)
			{
				if (!bInTOC)
				{
					TArray<FString> activeComponentIDsCache;
					if (bOverrideOuterTileSource)
					{
						activeComponentIDsCache.Append(ActiveComponentIDs);

						ActiveComponentIDs.Empty();
						ActiveComponentIDs.Add("dted_heightmap");
						ActiveComponentIDs.Add("xml_imagery");
					}

					TPair<FGeodeticCoord2D, FGeodeticCoord2D> tileBounds;
					if (AGame_TerrainTile* tile = LoadTile(ETileID::Outer, viewpointCoordinate, outerTileDistanceMeters, outerImageryZoomLevel, outerImageryZoomLevel, tileBounds))
					{
						setDrawDistance(tile, viewpointActor->GetActorLocation(), outerTileDistanceMeters);

						tile->OnTileStatusChanged.AddLambda([setImageryCutOn, tileBounds](AGame_TerrainTile* terrainTile, const ETileStatus tileStatus)
						{
							if (tileStatus == ETileStatus::GameThreadFinished)
							{
								setImageryCutOn(ETileID::Ellipsoid, tileBounds);
							}
						});
					}

					if (bOverrideOuterTileSource)
					{
						ActiveComponentIDs.Empty();
						ActiveComponentIDs.Append(activeComponentIDsCache);
					}
				}
			}

			// inner tile (always on in TOC; on when under InnerTileAGLThresholdMeters outside of TOC)
			{
				if (bInTOC || LastMetersAGL <= InnerTileAGLThresholdMeters)
				{
					double tileViewDistanceMeters = FMath::Min<double>(InnerTileMaxViewDistanceMeters, drawDistanceMeters);

					TPair<FGeodeticCoord2D, FGeodeticCoord2D> tileBounds;
					if (AGame_TerrainTile* tile = LoadTile(ETileID::Inner, viewpointCoordinate, tileViewDistanceMeters, MaxImageryZoomLevel, MaxHeightmapZoomLevel, tileBounds))
					{
						setDrawDistance(tile, viewpointActor->GetActorLocation(), tileViewDistanceMeters);

						// cut inner tile bounds on outer tile)
						tile->OnTileStatusChanged.AddLambda([setImageryCutOn, setCollisionCutOn, tileBounds](AGame_TerrainTile* terrainTile, const ETileStatus tileStatus)
						{
							if (tileStatus == ETileStatus::GameThreadFinished)
							{
								setImageryCutOn(ETileID::Outer, tileBounds);

								// disable collision on ellipsoid, cut inner tile from outer tile's collision
								setCollisionCutOn(ETileID::Outer, tileBounds, false);
								setCollisionCutOn(ETileID::Ellipsoid, TPair<FGeodeticCoord2D, FGeodeticCoord2D>(), true);
							}
						});
					}
				}
				else
				{
					unloadTile(ETileID::Inner);

					clearImageryCutFrom(ETileID::Outer);

					// disable collision on outer, remove collision cut on ellipsoid
					setCollisionCutOn(ETileID::Outer, TPair<FGeodeticCoord2D, FGeodeticCoord2D>(), true);
					clearCollisionCutFrom(ETileID::Ellipsoid);
				}
			}
		}
	}
}

void UGame_TileManager::PeriodicProcessHelperThreadQueue()
{
	for (const TPair<ETileID, AGame_TerrainTile*> entry : LoadedTiles)
	{
		TArray<UGame_TileComponent*> components;
		entry.Value->GetComponentsByStatus(EComponentStatus::Initialized, components);

		for (UGame_TileComponent* tileComponent : components)
		{
			//UE_LOG(LogTemp, Warning, TEXT("-- UGame_TileManager::ProcessHelperThreadQueue | executing helper thread logic | %s | %s"), *tileComponent->GetClass()->GetName(), *tileComponent->GetName());
			tileComponent->ExecuteHelperThreadLogic();
		}
	}
}

void UGame_TileManager::PeriodicProcessGameThreadQueue()
{
	auto runGameThread = [](AGame_TerrainTile* tile)
	{
		TArray<UGame_TileComponent*> tileComponents;
		tile->GetComponentsByStatus(EComponentStatus::HelperThreadFinished, tileComponents);

		for (UGame_TileComponent* tileComponent : tileComponents)
		{
			//UE_LOG(LogTemp, Warning, TEXT("-- UGame_TileManager::ProcessGameThreadQueue | executing game thread logic | %s | %s"), *tileComponent->GetClass()->GetName(), *tileComponent->GetName());
			tileComponent->ExecuteGameThreadLogic();
		}

		return tileComponents.Num() > 0;
	};

	if (AGame_TerrainTile** tilePtr = LoadedTiles.Find(ETileID::Inner))
	{
		if (runGameThread(*tilePtr))
		{
			return;
		}
	}

	if (AGame_TerrainTile** tilePtr = LoadedTiles.Find(ETileID::Outer))
	{
		if (runGameThread(*tilePtr))
		{
			return;
		}
	}

	if (AGame_TerrainTile** tilePtr = LoadedTiles.Find(ETileID::Ellipsoid))
	{
		runGameThread(*tilePtr);
	}
}

void UGame_TileManager::PeriodicProcessDestroyQueue()
{
	for (const TPair<ETileID, AGame_TerrainTile*>& entry : LoadedTiles)
	{
		if (entry.Value->GetTileStatus() != ETileStatus::GameThreadFinished)
		{
			return;
		}
	}
	
	for (AGame_TerrainTile* tile : ToDestroy)
	{
		if (tile->HasActorBegunPlay())
		{
			tile->AddToRoot();
		}
	}

	ToDestroy.Empty();

	for (const TPair<ETileID, AGame_TerrainTile*>& entry : LoadedTiles)
	{
		entry.Value->SetActorHiddenInGame(false);
	}
}

void UGame_TileManager::ProcessHTTPRequests()
{
	AsyncTask(ENamedThreads::GameThread, [this]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}
		
		int32 numActive = 0;

		TArray<FHTTPRequestInfo> requestInfos;
		HTTPRequests.GenerateValueArray(requestInfos);

		for (const FHTTPRequestInfo& requestInfo : requestInfos)
		{
			if (requestInfo.HTTPRequest->GetStatus() == EHttpRequestStatus::Processing)
			{
				numActive++;
			}
		}

		if (numActive < MaxActiveHTTPRequests)
		{
			for (TPair<FString, FHTTPRequestInfo>& entry : HTTPRequests)
			{
				if (entry.Value.HTTPRequest->GetStatus() == EHttpRequestStatus::NotStarted)
				{
					entry.Value.HTTPRequest->ProcessRequest();
					numActive++;

					if (numActive >= MaxActiveHTTPRequests)
					{
						DestroyCounter.Decrement();
						return;
					}
				}
			}
		}
		
		DestroyCounter.Decrement();
	});
}

void UGame_TileManager::Cleanup()
{
	DestroyLoadedTiles(true);

	for (AGame_TerrainTile* tile : ToDestroy)
	{
		if (tile->HasActorBegunPlay())
		{
			tile->AddToRoot();
		}
	}

	ToDestroy.Empty();

	if (UWorld* world = UDeveloper_Statics::GetVHWorld())
	{
		world->GetTimerManager().ClearAllTimersForObject(this);
	}

	FCoreDelegates::PostWorldOriginOffset.RemoveAll(this);
}

void UGame_TileManager::DestroyLoadedTiles(bool bSync)
{
	TArray<AGame_TerrainTile*> toDestroySync;
	TArray<ETileID> toDestroyAsync;

	for (const TPair<ETileID, AGame_TerrainTile*>& entry : LoadedTiles)
	{
		entry.Value->SetTileStatus(ETileStatus::ReadyForDestroy);
		if (bSync)
		{
			toDestroySync.Add(entry.Value);
		}
		else
		{
			toDestroyAsync.Add(entry.Key);
			ToDestroy.Add(entry.Value);
		}
	}

	if (bSync)
	{
		LoadedTiles.Empty();

		for (auto i = 0; i < toDestroySync.Num(); i++)
		{
			if (toDestroySync[i]->HasActorBegunPlay())
			{
				toDestroySync[i]->AddToRoot();
			}
		}
	}
	else
	{
		for (ETileID tileID : toDestroyAsync)
		{
			LoadedTiles.Remove(tileID);
		}
	}
}

void UGame_TileManager::PostWorldOriginOffset(UWorld* world, FIntVector previousOrigin, FIntVector newOrigin)
{
	bForceUpdate = true;
}

void UGame_TileManager::RemoveDestroyedTile(AActor* actor)
{
	bool bFound = false;

	ETileID toRemove = ETileID::Inner;
	for (const TPair<ETileID, AGame_TerrainTile*>& entry : LoadedTiles)
	{
		if (entry.Value == actor)
		{
			toRemove = entry.Key;

			bFound = true;

			break;
		}
	}

	if (bFound)
	{
		LoadedTiles.Remove(toRemove);
	}

	for (TPair<UTexture2D*, AGame_TerrainTile*>& entry : OuterTextures)
	{
		if (entry.Value == actor)
		{
			entry.Value = nullptr;

			continue;
		}
	}

	for (TPair<UTexture2D*, AGame_TerrainTile*>& entry : InnerTextures)
	{
		if (entry.Value == actor)
		{
			entry.Value = nullptr;

			continue;
		}
	}

	for (TPair<UTexture2D*, AGame_TerrainTile*>& entry : InnerTOCTextures)
	{
		if (entry.Value == actor)
		{
			entry.Value = nullptr;

			continue;
		}
	}
}

void UGame_TileManager::UpdateTaskTracker() const
{
	if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
	{
		FString taskInfoID = TEXT("TileManager_HTTPRequests");
		int32 numRequests = HTTPRequests.Num();

		if (numRequests > 0)
		{
			FString description = FString::Printf(TEXT("Terrain Tile HTTP Requests | %d left"), HTTPRequests.Num());
			taskTracker->AddActiveTask(taskInfoID, description, -1);
		}
		else
		{
			taskTracker->RemoveActiveTask(taskInfoID);
		}
	}
}

bool UGame_TileManager::IsSafeToExecute()
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

void UGame_TileManager::HandleDoubleSettingChanged(const FString& settingName, double value)
{
	if (settingName.Equals(TEXT("TileViewDistance")))
	{
		UpdateTileDrawDistances();

		bForceUpdate = true;
	}
}

void UGame_TileManager::HandleBoolSettingChanged(const FString& settingName, bool bValue)
{
	if (settingName.Equals(TEXT("OverrideOuterTileSource")))
	{
		bOverrideOuterTileSource = bValue;
		
		SetEnabled(false);
		SetEnabled(true);
	}
}

void UGame_TileManager::HandleTileStatusChanged(AGame_TerrainTile* terrainTile, const ETileStatus tileStatus)
{
	if (tileStatus == ETileStatus::GameThreadFinished)
	{
		OnTileFinishedLoading.Broadcast(terrainTile);
	}
}

void UGame_TileManager::HandleWorldCleanup(UWorld* world, bool bSessionEnded, bool bCleanupResources)
{
	Cleanup();

	bEnabled = false;
	bSetEnabledInitial = false;
}

void UGame_TileManager::HandleTOCViewDistanceChanged(float viewDistance, float tileViewDistance)
{
	bForceUpdate = true;
}

void UGame_TileManager::HandleVOGlobeReferenceGeoLocationChanged(AVH_GlobeReferenceActor* globeReference)
{
	bForceUpdate = true;
}

void UGame_TileManager::HandlePlayerIsInTOCUpdated(bool isInTOC)
{
	DestroyLoadedTiles(true);

	bForceUpdate = true;
}