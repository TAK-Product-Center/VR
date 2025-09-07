#pragma once

// Parent Includes
#include "Game_TileComponent_Mesh.h"

// Engine Includes
#include "OpenCVHelper.h"
#include "PreOpenCVHeaders.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include "PostOpenCVHeaders.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Required Includes
#include "Game_MeshComponent_CesiumIon.generated.h"

class AVH_GlobeReferenceActor;

namespace TAK::Engine::Formats::QuantizedMesh::Impl
{
	class QMElevationSampler;
}

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_MeshComponent_CesiumIon : public UGame_TileComponent_Mesh
{
	GENERATED_BODY()
	
		
	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	TPair<int32, int32> NorthWestTile;

	TPair<int32, int32> SouthEastTile;

	TMap<FString, std::shared_ptr<TAK::Engine::Formats::QuantizedMesh::Impl::QMElevationSampler>> Samplers;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_MeshComponent_CesiumIon();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static void GetTileFromGeodetic(const FGeodeticCoord2D& coordinate, int32 zoomLevel, TPair<int32, int32>& tileNumber);

	static bool GetHAE(const FGeodeticCoord2D& coordinate, double& hae);
	

	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void ExecuteHelperThreadLogic() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION()
	void MakeHttpRequests(const FString& assetID, const FString& accessToken, const FString& url);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	bool GetHAE(const FGeodeticCoord2D& coordinate, double& hae, int32 zoomLevel);

	void OnHTTPRequestComplete(const FString& identifier, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful);

	void ReadDataFromAllTiles();

	bool IsSafeToExecute();
	
	FGeodeticCoord2D GetNorthwestCoordinate(const TPair<int32, int32>& tileNumber, int32 zoomLevel) const;
};