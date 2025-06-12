#pragma once

// Parent Includes
#include "Game_TileComponent.h"

// Plugin Includes
#include "vtzero/geometry.hpp"

// Game Includes
#include "Game_TerrainTile.h"
#include "Game_VectorTile_Loader.h"

// Generated Includes
#include "Game_VectorTile_MapBox.generated.h"

class AGame_VectorTile_Actor;

enum class EVectorTileLoadStatus : uint8
{
	PendingTerrain,
	LoadingTiles,
	TilesLoaded
};


USTRUCT()
struct FRawData
{
	GENERATED_BODY()


	TArray<uint8> Data;

	FRawData() {}
	FRawData(const TArray<uint8>& data) :
		Data(data) { }
	FRawData(const TArray<uint8>&& data) :
		Data(data) { }
};


/// UGame_VectorTile_MapBox is responsible for:
/// 1. Downloading vector tile data from MapBox.  All downloaded data is saved locally to disk.
/// 2. Parsing the vector tile data received from MapBox.
/// 3. Generating the geometry from the vector tile data which can be displayed on a terrain with geographical correctness.
/// 
/// NOTE: Currently, buildings are the only types of geometry generated.
UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_VectorTile_MapBox : public UGame_TileComponent
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:

	const FString StreetsUrl;			// The URL used to download street vector tile data.
	const FString Source;				// Name of the source data "MapBox".  To be used with the Tile Manager.
	const FString SourceType;			// Type of data receiving from MapBox "vector-tile".  To be used with the Tile Manager.
	FString AccessToken;				// MapBox Access Token.  A valid token from MapBox is required to download MapBox vector tiles.
	FString VectorTilePath;				// Location the vector tiles will be saved to/loaded from.
	FTimerHandle TerrainTimerHandle;
	TPair<int32, int32> NorthWestTile;	// The North-West corner tile.  Combined with SouthEastTile, this creates the "bounds" region to download vector tiles.
	TPair<int32, int32> SouthEastTile;	// The South-East corner tile.  Combined with NorthWestTile, this creates the "bounds" region to download vector tiles.
	TArray<AGame_VectorTile_Actor*> VectorTileActors;
	Game_VectorTile_Task Task;

	UPROPERTY()
	TMap<FIntPoint, FRawData> TileData;
	EVectorTileLoadStatus Status;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:

	UGame_VectorTile_MapBox();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:

	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;
	virtual void ExecuteGameThreadLogic() override;
	virtual void ExecuteHelperThreadLogic() override;
	virtual bool GlobeReferenceScaleUpdated(const FVector& newScale3D) override;
	virtual bool SetBoundsAndZoomVirtual(const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds, int32 zoomLevel) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:

	void AddVectorTileActor(AGame_VectorTile_Actor* actor);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:

	/// After the Access Token is validated, this is called.
	/// RequestTiles() calculates the tile bounds and sends a request for each vector tile within that range.
	void RequestTiles();

	/// Triggered when receving a response for the MapBox Access Token validation as well as for each vector tile that was requested.
	/// @param identifier		A unique identifier created by the request to represent this specific data request.
	/// @param request			The HTTP handler for the original request.
	/// @param response			The HTTP handler for the response, which will include all the data that was requested.
	/// @param bWasSuccessful	True: The HTTP request was successful.  False: The HTTP request was unsuccessful and may have never reached it's destination.
	void OnHTTPRequestComplete(const FString& identifier, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful);

	/// Sends an HTTP GET request to MapBox for a specific vector tile.
	/// @param tileX	Column for the vector tile.
	/// @param tileY	Row for the vector tile.
	/// @return	A handle to the HTTP request object for this request.
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> RequestVectorTile(int32 tileX, int32 tileY);

	/// Sends an HTTP GET request to MapBox to validate the Access Token.
	void RequestAccess();

	void DestroyActors();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleTerrainUpdate();

	UFUNCTION()
	void PeriodicCheckLOD();

	void OnVectorTileFinished(AGame_VectorTile_Actor* actor);

	UFUNCTION()
	void BindToTileManager();
};
