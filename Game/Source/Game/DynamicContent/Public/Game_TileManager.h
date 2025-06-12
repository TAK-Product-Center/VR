#pragma once

// Parent Includes
#include "UObject/Object.h"

// Engine Includes
#include "Blueprint/UserWidget.h"
#include "Tickable.h"
#include "HAL/ThreadSafeCounter.h"
#include "Interfaces/IHttpRequest.h"
#include "Templates/SubclassOf.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_TileManager.generated.h"

class AGame_VirtualObjective;
class AVH_GlobeReferenceActor;
class AGame_TerrainTile;
class APawn;
class UGame_TileComponent_OWT;
class UGame_TileComponent_NGAGrid;


// ---------------------------------
// --- Enums
// ---------------------------------

UENUM()
enum class ETileID : uint8
{
	Inner,
	Outer,
	Ellipsoid
};


// ---------------------------------
// --- Structs
// ---------------------------------

struct FHTTPRequestInfo
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HTTPRequest;

	UPROPERTY()
	TArray<UGame_TileComponent*> Requesters;

	FHTTPRequestInfo(TSharedRef<IHttpRequest, ESPMode::ThreadSafe> httpRequest) :
		HTTPRequest(httpRequest)
	{
	}
};

USTRUCT(BlueprintType)
struct FTerrainSourceInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString ID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString DisplayName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UUserWidget> SourceInfoUIClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGame_TileComponent> ComponentClass;
};

UCLASS(Blueprintable)
class GAME_API UGame_TileManager : public UObject, public FTickableGameObject
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_TileManager();


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FActiveComponentsModified);

	DECLARE_MULTICAST_DELEGATE_OneParam(FTileFinishedLoading, AGame_TerrainTile*);

	DECLARE_MULTICAST_DELEGATE_OneParam(FTileDisabled, AGame_TerrainTile*);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTerrainUpdate);

	DECLARE_DELEGATE_RetVal_TwoParams(bool, FGetHAE, const FGeodeticCoord2D&, double&);

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	TMap<FString, FGetHAE> ComponentIDToHAELambda;

	UPROPERTY(BlueprintAssignable)
	FActiveComponentsModified OnActiveComponentsModified;

	UPROPERTY(BlueprintAssignable)
	FTerrainUpdate OnTerrainUpdate;

	/* min is northWest bounds, max is northEast bounds */
	FTileFinishedLoading OnTileFinishedLoading;

	/* min is northWest bounds, max is northEast bounds of lowest zoom level */
	FTileDisabled OnTileDisabled;

	/* maximum length and width of inner tile in meters */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double InnerTileMaxViewDistanceMeters;

	/* imagery switches to MinImageryZoomLevel when user is this many meters AGL */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double InnerTileAGLThresholdMeters;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FString, FTerrainSourceInfo> IDToTerrainSourceInfo;

	bool bPauseUpdate;  // debug

private:
	static UGame_TileManager* GlobalInstance;

	FThreadSafeCounter DestroyCounter;

	int32 MaxActiveHTTPRequests;

	bool bEnabled;
	bool bSetEnabledInitial;

	TArray<FString> ActiveComponentIDs;

	/* key is full path on disk */
	TMap<FString, FHTTPRequestInfo> HTTPRequests;

	UPROPERTY()
	TMap<ETileID, AGame_TerrainTile*> LoadedTiles;

	UPROPERTY()
	TArray<AGame_TerrainTile*> ToDestroy;

	FGeodeticCoord2D ViewpointCoordinateOfLastUpdate;
	double LastMetersAGL;
	bool bForceUpdate;

	FTimerHandle LocationTimerHandle;
	FTimerHandle HelperThreadTimerHandle;
	FTimerHandle GameThreadTimerHandle;
	FTimerHandle DestroyTimerHandle;
	FTimerHandle HTTPRequestTimerHandle;

	float TileUpdateTime;

	float HTTPRequestLastCheck;
	float HTTPRequestCooldown;

	int32 MinImageryZoomLevel;

	int32 MaxImageryZoomLevel;

	int32 MinHeightmapZoomLevel;

	int32 MaxHeightmapZoomLevel;

	UPROPERTY()
	AGame_VirtualObjective* VirtualObjective;

	UPROPERTY()
	TMap<UTexture2D*, AGame_TerrainTile*> InnerTOCTextures;

	UPROPERTY()
	TMap<UTexture2D*, AGame_TerrainTile*> InnerTextures;

	UPROPERTY()
	TMap<UTexture2D*, AGame_TerrainTile*> OuterTextures;

	UPROPERTY()
	UTexture2D* EllipsoidTexture;

	bool bLatentInitialized;

	bool bOverrideOuterTileSource;


	// ---------------------------------
	// --- FTickableObjectBase
	// ---------------------------------

public:
	virtual bool IsTickable() const override;

	virtual void Tick(float deltaSeconds) override;

	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(UGame_TileManager, STATGROUP_Tickables); }


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create Tile Manager"))
	static UGame_TileManager* Create(TSubclassOf<class UGame_TileManager> managerClass);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Tile Manager"))
	static UGame_TileManager* Get();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual bool IsReadyForFinishDestroy() override;

	virtual void BeginDestroy() override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
    bool Initialize();

    void Shutdown();

    void OnGameModeInit();

    void OnGameModeStartToLeaveMap();

	bool GetMinLoadedHAE(double& minLoadedHAE) const;

	UFUNCTION(BlueprintCallable)
    void SetEnabled(bool isEnabled);

	UFUNCTION(BlueprintPure)
	bool IsEnabled() const;

	UFUNCTION(BlueprintCallable)
	void ClearTiles();

    UFUNCTION(BlueprintCallable)
    void RegisterTileComponent(const FTerrainSourceInfo& terrainSourceInfo);

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	TArray<FString> GetImageryComponentIDs() const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	TArray<FString> GetHeightmapComponentIDs() const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	TArray<FString> GetOtherComponentIDs() const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	void GetActiveComponentIDs(TArray<FString>& activeComponentIDs) const;

	UFUNCTION(BlueprintCallable)
	void AddActiveComponentID(const FString& activeComponentID, bool bBroadcastDelegate);

	UFUNCTION(BlueprintCallable)
	void RemoveActiveComponentID(const FString& activeComponentID, bool bBroadcastDelegate);

	UFUNCTION(BlueprintCallable)
	void ClearActiveComponentIDs(bool bBroadcastDelegate);

	UFUNCTION(BlueprintCallable)
	bool GetDTEDLevel(float latitude, float longitude, int32& dtedLevel);

	UFUNCTION(BlueprintCallable)
	void SetMinImageryZoomLevel(const int32 minImageryZoomLevel);

	UFUNCTION(BlueprintCallable)
	void SetMaxImageryZoomLevel(const int32 maxImageryZoomLevel);

	UFUNCTION(BlueprintCallable)
	void SetMinHeightmapZoomLevel(const int32 minHeightmapZoomLevel);

	UFUNCTION(BlueprintCallable)
	void SetMaxHeightmapZoomLevel(const int32 maxHeightmapZoomLevel);

	void AddHTTPRequest(const FString& identifier, UGame_TileComponent* requester, const TSharedRef<IHttpRequest, ESPMode::ThreadSafe>& httpRequest);

	void AddHTTPRequester(const FString& identifier, UGame_TileComponent* requester);

	void RemoveHTTPRequests(UGame_TileComponent* requester);

	UFUNCTION(BlueprintPure)
	int32 GetNumHTTPRequests(UGame_TileComponent* requestor = nullptr) const;

	void PreModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference);

	void PostModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference);

	void GlobeReferenceScaleUpdated(const FVector& newScale3D);

	UFUNCTION(BlueprintCallable)
	void UpdateTileDrawDistances();

	UFUNCTION(BlueprintPure)
	AGame_VirtualObjective* GetVirtualObjective() const;

	UFUNCTION(BlueprintCallable)
	void SetVirtualObjective(AGame_VirtualObjective* inVirtualObjective);

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	bool GetHAE(const FGeodeticCoord2D& coord, double& hae) const;

	bool GetHAEFromDTED(const FGeodeticCoord2D& coordinate, double& hae) const;

	/*
	* \brief: TMap's key defines grid as:
	* 
	* 0,2 1,2 2,2
	* 0,1 1,1 2,1
	* 0,0 1,0 2,0
	* 
	* TSet<FVector> in gridSlots are vertices in that grid
	* 
	* \returns: true with success 
	*/
	bool GetTerrainGrid(int32 xSlots, int32 ySlots, double distance, const FVector& viewshedCenter, TSet<FVector>& averageGridVertices) const;

	UFUNCTION(BlueprintCallable)
	void ForceUpdate();

	AGame_TerrainTile* GetTile(ETileID tileID) const;

	/// @brief Returns true if any tile is not finished building
	bool PendingTiles() const;

	float GetDrawDistanceMeters() const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void LatentInitialize();

	UTexture2D* GetHighResTexture(AGame_TerrainTile* terrainTile);

	bool HasHTTPRequest(const FString& identifier);

	void OnHTTPRequestComplete(const FString& identifier, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful);

	AActor* GetViewpointActor() const;

	AGame_TerrainTile* LoadTile(ETileID tileID, const FGeodeticCoord2D& centerGeodetic, double viewDistanceMeters, int32 imageryZoomLevel, int32 heightmapZoomLevel, TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds);

    void PeriodicUpdateForViewpointLocation();

	void PeriodicProcessHelperThreadQueue();

	void PeriodicProcessGameThreadQueue();

	void PeriodicProcessDestroyQueue();

	void ProcessHTTPRequests();

    void Cleanup();

    void DestroyLoadedTiles(bool bSync);

    UFUNCTION()
    void PostWorldOriginOffset(UWorld* world, FIntVector previousOrigin, FIntVector newOrigin);

	UFUNCTION()
	void RemoveDestroyedTile(AActor* actor);

	void UpdateTaskTracker() const;

	bool IsSafeToExecute();

	
	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleDoubleSettingChanged(const FString& settingName, double value);

	UFUNCTION()
	void HandleBoolSettingChanged(const FString& settingName, bool bValue);

	UFUNCTION()
	void HandleTileStatusChanged(AGame_TerrainTile* terrainTile, const ETileStatus tileStatus);

	UFUNCTION()
	void HandleWorldCleanup(UWorld* world, bool bSessionEnded, bool bCleanupResources);

	UFUNCTION()
	void HandleTOCViewDistanceChanged(float viewDistance, float tileViewDistance);

	UFUNCTION()
	void HandleVOGlobeReferenceGeoLocationChanged(AVH_GlobeReferenceActor* globeReference);

	UFUNCTION()
	void HandlePlayerIsInTOCUpdated(bool isInTOC);
};
