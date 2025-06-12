#pragma once

#include "GameFramework/Actor.h"

#include "VH_GeodeticCoord.h"
#include "Database_Spatialite.h"
#include "Interface_Developer_Task.h"

#include "Game_VirtualObjective.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogGameVirtualObjective, Warning, All);

class AVH_GlobeReferenceActor;
class AGame_TerrainTile;

/*
 * A VirtualObjective controls the loading and unloading of dynamic content, based on some monitored criteria.
 * The default behavior loads / unloads content based on relevancy (e.g.proximity and orientation) to the viewpoint (e.g.player or VOTable proxy actor).
 */
UCLASS(Blueprintable)
class GAME_API AGame_VirtualObjective : public AActor
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTOCViewDistanceChanged, float, viewDistance, float, tileViewDistance);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGlobeReferenceGeoLocationChanged, AVH_GlobeReferenceActor*, globeReference);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnObjectAddedToVO, UObject*, AGame_VirtualObjective*);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScale3DChanged, const FVector&, scale3D);

public:
	UPROPERTY(BlueprintAssignable)
	FTOCViewDistanceChanged OnTOCViewDistanceChanged;

	UPROPERTY(BlueprintAssignable)
	FOnGlobeReferenceGeoLocationChanged OnGlobeReferenceGeoLocationChanged;

	UPROPERTY(BlueprintAssignable)
	FOnScale3DChanged OnScale3DChanged;

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	static FOnObjectAddedToVO OnObjectAddedToVO;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TOCViewDistance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing = OnRep_TOCTileViewDistance)
	float TOCTileViewDistance;

	FString ScrapeRectangleEntityUID;

protected:
	bool bIsInitialized;

	bool bIsShuttingDown;

	int32 EntityDetailLevel;

	UPROPERTY()
	AActor* ViewpointActor;

	// causes a paging update when true
	bool bNeedsUpdate;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AVH_GlobeReferenceActor> GlobeReferenceActorClass;

	TMap<FString, TSet<UObject*>> EntityUIDToObjects;

	UPROPERTY()
	TMap<UObject*, FString> ObjectToEntityUID;

	bool bForcePageEntities;

private:
	UPROPERTY(ReplicatedUsing = OnRep_ReplicatedVOGlobeCoordinate)
	FGeodeticCoord3D ReplicatedVOGlobeCoordinate;

	UPROPERTY(ReplicatedUsing = OnRep_ReplicatedScale3D)
	FVector ReplicatedScale3D;

	UPROPERTY()
	AVH_GlobeReferenceActor* GlobeReference;

	float ViewDistance;

	FBox2D ViewCullBox;

	FGeodeticCoord3D LastRelevancyUpdateCoordinate;

	FDelegateHandle TileLoadedDelegateHandle;

	bool bUpdateCoord;

	bool bEnabled;

	TSet<FString> QueuedToLoad;
	double LoadEntitiesElapsed;
	double LoadEntitiesCooldown;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_VirtualObjective();


	// ---------------------------------
	// --- Replication
	// ---------------------------------

private:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
	void OnRep_ReplicatedVOGlobeCoordinate();

	UFUNCTION()
	void OnRep_ReplicatedScale3D();

	UFUNCTION()
	void OnRep_TOCTileViewDistance();


	// ---------------------------------
    // --- Inherited
    // ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;

	virtual void Tick(float deltaSeconds) override;

	virtual void SetActorScale3D(FVector newScale3D) override;
    
	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void SetEnabled(bool bEnabled);

	int32 GetEntityDetailLevel() const;

	TSet<FString> GetPagedInEntities() const;

	UFUNCTION(BlueprintCallable)
	void PageOutEntities();

	UFUNCTION(BlueprintPure)
	bool IsEntityPagedIn(const FString& entityUID) const;

	UFUNCTION(BlueprintCallable)
	void AddObjectToEntity(const FString& entityUID, UObject* object);

	UFUNCTION(BlueprintCallable)
	void AddObjectsToEntity(const FString& entityUID, const TSet<UObject*>& objects);

	UFUNCTION(BlueprintCallable)
	void RemoveObjectFromEntity(const FString& entityUID, UObject* object);

	UFUNCTION(BlueprintPure)
	TSet<UObject*> GetObjectsForEntity(const FString& entityUID) const;

	UFUNCTION(BlueprintPure)
	TSet<AActor*> GetActorsForEntity(const FString& entityUID) const;

	UFUNCTION(BlueprintPure)
	bool HasObject(UObject* object) const;

	UFUNCTION(BlueprintPure)
	FString GetObjectEntityUID(UObject* object) const;

	UFUNCTION(BlueprintCallable)
	void PageOutEntity(const FString& entityUID);

	UFUNCTION(BlueprintCallable)
	void SetEntityVisibility(const FString& entityUID, bool bVisible);

	UFUNCTION(BlueprintCallable)
	void SetEntityScale3D(const FString& entityUID, FVector scale3D);

	bool IsInitialized() const;

	virtual void Shutdown();

	void SetReplicatedVOGlobeCoordinate(const FGeodeticCoord3D& coordinate);

	void SetReplicatedScale3D(const FVector& scale3D);

    UFUNCTION(BlueprintPure)
    AVH_GlobeReferenceActor* GetGlobeReference();

	// dev function, only use when manually placing globe reference in a map
	UFUNCTION(BlueprintCallable)
	void SetGlobeReference(AVH_GlobeReferenceActor* inGlobeReference);

    UFUNCTION(BlueprintPure)
    AActor* GetViewpointActor() const;

    UFUNCTION(BlueprintCallable)
    virtual void SetViewpointActor(AActor* actor);

	UFUNCTION(BlueprintPure)
	float GetViewDistance() const;

    UFUNCTION(BlueprintCallable)
    void SetViewDistance(float viewDistance);

	UFUNCTION(BlueprintPure)
	FBox2D GetViewCullBox();

	UFUNCTION(BlueprintCallable)
	void SetViewCullBox(const FBox2D& cullBox);
	
	UFUNCTION(BlueprintCallable)
	bool IsPointInViewCullBox(const FVector& point);

	UFUNCTION(BlueprintCallable)
    void TriggerUpdate();

    void EntityHandlerRegistered(UObject* handler);

	/* sets scale for actors paged in by this VO and associated with an entityUID */
	UFUNCTION(BlueprintCallable)
	void SetScaleFor(const FString& entityUID);

	UFUNCTION(BlueprintCallable)
	void SetVisibilityFor(const FString& entityUID);

	UFUNCTION(BlueprintCallable)
	void TOCMoveViewpoint(const FVector& offset);

	UFUNCTION(BlueprintCallable)
	void SetScale3D(const FVector& newScale);

	UFUNCTION(BlueprintCallable)
	void SetCoord(const FGeodeticCoord3D& coordinate, bool bSnapTileToTable);

	void SetCoord_Implementation(const FGeodeticCoord3D& coordinate);

	// Snap-to-ground all paged-in entities within the given geoExtents (min/max -- e.g. SW/NE)
	void SnapToGround(const FBox2D& geoExtents);

	UFUNCTION(BlueprintCallable)
	void SyncToTOCLocation();

	UFUNCTION(BlueprintCallable)
	void SyncToTOCScale3D();

	UFUNCTION(BlueprintCallable)
	void SyncToTOCTileViewDistance();

	UFUNCTION(BlueprintPure)
	virtual float GetUnrealUnitsPerMeter();

	UFUNCTION(BlueprintPure)
	virtual int32 GetVOIndex();

	UFUNCTION(BlueprintPure)
	float GetExpectedTOCTileDistance();

	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	virtual void UpdateRelevancySet(const FGeodeticCoord3D& geoLocation);

private:
	virtual bool Initialize();

	/* Called before this VO's globe reference's long/lat are modified */
	virtual void PreModifyGlobeReference(class UGame_EntityDB* entityDB, class UGame_HandlerService* handlerService, AVH_GlobeReferenceActor* globeReference);

	/* Called after this VO's globe reference's long/lat are modified */
	virtual void PostModifyGlobeReference(UGame_EntityDB* entityDB, UGame_HandlerService* handlerService, AVH_GlobeReferenceActor* globeReference);

	bool IsLocalPlayerInTOC() const;

	void CheckForMUCDBReceived();


    // ---------------------------------
    // --- Event Handlers
    // ---------------------------------

private:
	UFUNCTION()
	void BindToTileManager();

	UFUNCTION()
	void HandleDoubleSettingStored(const FString& settingName, double value);

    UFUNCTION()
    void HandleEntityDBInsertOrUpdateEvent(const FSpatialiteResults_BP& results);

	UFUNCTION()
	void HandleEntityDBDeleteEvent(const FSpatialiteResults_BP& results);

	UFUNCTION()
	void HandleTerrainTileFinishedLoading(AGame_TerrainTile* terrainTile);
	
	UFUNCTION()
	void HandleTerrainTileDisabled(AGame_TerrainTile* terrainTile);

	UFUNCTION()
	void HandleMeshBuilderTaskFinished(TScriptInterface<IInterface_Developer_Task> task);

	UFUNCTION()
	void HandleServerDatabaseReady();

	UFUNCTION()
	void PeriodicCheckRelevancy();

	UFUNCTION()
	void PeriodicLoadEntities();
};
