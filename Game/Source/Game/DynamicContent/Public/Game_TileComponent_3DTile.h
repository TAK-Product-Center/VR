#pragma once

// Parent Includes
#include "Game_TileComponent.h"

// Engine Includes
#include "HAL/ThreadSafeBool.h"
#include "Dom/JsonObject.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_TileComponent_3DTile.generated.h"

class AGame_TerrainTile;
class UGame_3DTileNode;
class AGame_Actor_3DTile;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_TileComponent_3DTile : public UGame_TileComponent
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

public:
	DECLARE_DELEGATE_OneParam(FOnReceiveFile, const FString&);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInterface* PolygonMaterial;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_Actor_3DTile> ActorClass;

protected:
	double LODMeters;
	double MinGeometricErrorWithinLOD;
	double MaxGeometricErrorWithinLOD;
	double GeometricErrorBeyondLOD;

	bool bInitialPass;
	double InitialGeometricError;
	
	/* must be set prior to ExecuteHelperThreadLogic */
	FString FullPathToTileset;  // for local datasets
	FString AssetID;  // for streamed datasets
	
	bool bReverseVertOrder;

	TArray<FGeoJsonNode> QueuedGeoJson;

	FString RESTBaseURL;
	FString RESTAccessToken;

	TMap<FString, FOnReceiveFile> ReceiveFileDelegates;

	FGeodeticCoord3D LastPlayerGeoLocation;
	FGeodeticCoord3D LastUpdateGeoLocation;

	FRotator LastPlayerRotation;
	FRotator LastUpdatePlayerRotation;

	mutable FCriticalSection FilesToLoadCritSection;
	TArray<FString> FilesToLoad;

	/* todo ohg | needed by root node; anything else? */
	UPROPERTY()
	TMap<FString, UGame_3DTileNode*> Nodes;

	/* map of fullPathToFile -> parent node of that file
	*  only used during REST request 
	*/
	TMap<FString, UGame_3DTileNode*> PathToNode;

	mutable FCriticalSection LoadedActorsCritSection;
	TMap<UGame_3DTileNode*, TArray<AActor*>> LoadedActors;

	UPROPERTY()
	TSet<AActor*> ActorReference;

	FThreadSafeBool bForceUpdateTileset;
	 
	// for google
	FString Session;
	TMap<FString, FString> GoogleFilenames;
	FDateTime LastTilesetRequest;

	FTimerHandle PeriodicLoadFilesTimerHandle;
	FTimerHandle PeriodicUpdateTilesetTimerHandle;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_TileComponent_3DTile();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;

	virtual void ExecuteHelperThreadLogic() override;

	virtual void ExecuteGameThreadLogic() override;

	virtual bool SetBoundsAndZoomVirtual(const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds, int32 zoomLevel) override;

	virtual void OnHTTPRequestComplete(const FString& fullPathToFile, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) override;

	virtual bool GlobeReferenceScaleUpdated(const FVector& newScale3D) override;

	bool GetHAEBounds(FVector2D& haeBounds) const override;

	// ---------------------------------
	// --- Implementation
	// ---------------------------------
	 
protected:
	void InitializeForLocalTilesets(FString localTilesets);

	virtual void InitializeForRemoteTileset(const FString& accessToken, FString assetID);

	virtual void PopulateComponentFromInfoArray(UGame_TileComponent* component, TArray<FString> assetInfo);

	virtual void RequestFile(const FString& fullPathToFile, FOnReceiveFile& receiveFileDelegate);

	bool IsSafeToExecute();
	
	void DestroyLoadedActors();
	
	void LoadFile(FString fullPathToFile);

	void PopulateNodeErrorAndBounding(UGame_3DTileNode* node, TSharedPtr<FJsonObject> rootObject);

	void PopulateNodeTransformMatrix(UGame_3DTileNode* node, TSharedPtr<FJsonObject> rootObject);

	void PopulateNodeChildren(UGame_3DTileNode* node, TSharedPtr<FJsonObject> rootObject);

	void PopulateNodeContent(UGame_3DTileNode* node, TSharedPtr<FJsonObject> rootObject);

	bool NodeIntersects(UGame_3DTileNode* node);

	void LoadImplicitTiles(UGame_3DTileNode* node);

	void LoadNodeContent(UGame_3DTileNode* node);

	void UnloadNodeContent(UGame_3DTileNode* node, bool bIncludeParentNodes);

	UGame_3DTileNode* LoadNode(UGame_3DTileNode* nodeParent, UGame_3DTileNode* node, const FString& fullPathToNode, TSharedPtr<FJsonObject> rootObject);

	FGeodeticCoord3D GetPlayerGeoLocation() const;

	bool IsLoadComplete() const;

	AActor* SpawnPolygon(const TArray<FGeodeticCoord3D>& coordinates, double msl);

	void AddLoadedActor(UGame_3DTileNode* node, AActor* actor);

	double GetDesiredMaxGeometricErrorForNode(UGame_3DTileNode* node) const;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

protected:
	void PeriodicLoadFiles();

	void PeriodicUpdateTileset();

	UFUNCTION()
	void HandleTileStatusChanged(AGame_TerrainTile* terrainTile, const ETileStatus tileStatus);
};
