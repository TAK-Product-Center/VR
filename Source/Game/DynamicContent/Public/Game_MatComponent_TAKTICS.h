#pragma once

// Parent Includes
#include "Game_TileComponent_Mat.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_MatComponent_TAKTICS.generated.h"

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_MatComponent_TAKTICS : public UGame_TileComponent_Mat
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_MatComponent_TAKTICS();


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	TPair<int32, int32> NorthWestTile;
	TPair<int32, int32> SouthEastTile;

	FString SourceName;
	FString SourceType;

	FString RequestURL;

	FString TileMatrixSet;

	// tile matrix is zoom level
	int32 MinTileMatrix;
	int32 MaxTileMatrix;

	TMap<TPair<int32, int32>, TArray<uint8>> TileToMatData;

	bool bGeneratedMat;

	int32 PixelWidth;
	int32 PixelHeight;

	double GammaCorrection;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;

	virtual void ExecuteHelperThreadLogic() override;

	virtual void ExecuteGameThreadLogic() override;

	virtual float GetAlpha() override;

protected:
	virtual bool SetBoundsAndZoomVirtual(const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds, int32 zoomLevel) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION()
	void MakeHttpRequests();

	void OnHTTPRequestComplete(const FString& identifier, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void CreateMat();

	cv::Mat CreateMatOfAllTiles(int32 pixelsX, int32 pixelsY);

	bool IsSafeToExecute();

	bool GetCachedMat(const TPair<int32, int32>& tileNumber, cv::Mat& tileMat);

	void AddGammaCorrection(cv::Mat& src, cv::Mat& dst, float fGamma);
};
