#pragma once

#include "OpenCVHelper.h"
#include "PreOpenCVHeaders.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include "PostOpenCVHeaders.h"

#include "Components/ActorComponent.h"
#include "VH_GeodeticCoord.h"
#include "Game_TileComponent_Mesh.h"
#include "Game_MeshComponent_Mapbox.generated.h"

class AVH_GlobeReferenceActor;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_MeshComponent_Mapbox : public UGame_TileComponent_Mesh
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_MeshComponent_Mapbox();


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	TPair<int32, int32> NorthWestTile;
	TPair<int32, int32> SouthEastTile;


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static bool GetHAE(const FGeodeticCoord2D& coord, double& hae);

	static void HandleHTTPRequestComplete(FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void ExecuteHelperThreadLogic() override;

	virtual void OnHTTPRequestComplete(const FString& identifier, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) override;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void CreateMat();

	void PopulateMeshData(cv::Mat heightmapMat);

	cv::Mat CreateMatOfAllTiles(int32 pixelsX, int32 pixelsY);

	bool IsSafeToExecute();
};