#pragma once

// Parent Includes
#include "Game_TileComponent_Mat.h"

// Engine Includes
#include "HAL/ThreadSafeBool.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_MatComponent_CesiumIon.generated.h"

// ---------------------------------
// --- Enums
// ---------------------------------

UENUM(BlueprintType)
enum class EProjection: uint8
{
	Geodetic,
	Mercator
};

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_MatComponent_CesiumIon : public UGame_TileComponent_Mat
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_MatComponent_CesiumIon();


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	TPair<int32, int32> NorthWestTile;
	TPair<int32, int32> SouthEastTile;

	FString SourceName;

	FString SourceType;

	EProjection Projection;

	int32 MinZoom;

	int32 MaxZoom;

	FString URL;

	int32 PixelWidth;

	int32 PixelHeight;

	bool bXMLLoaded;

	bool bOffline;

	FThreadSafeBool bGeneratedMat;

	TMap<TPair<int32, int32>, TArray<uint8>> TileToMatData;

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
	void MakeHttpRequests(const FString& assetID, const FString& accessToken, const FString& url);

	void OnHTTPRequestComplete(const FString& identifier, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void GetTileFromGeodetic_Geodetic(const FGeodeticCoord2D& coordinate, const int32 zoomLevel, TPair<int32, int32>& tileNumber);

	FGeodeticCoord2D GetNorthwestCoordinate_Geodetic(const TPair<int32, int32>& tileNumber, const int32 zoomLevel);

	void CreateMat();

	cv::Mat CreateMatOfAllTiles(int32 pixelsX, int32 pixelsY);

	bool IsSafeToExecute();

	bool GetCachedMat(const TPair<int32, int32>& tileNumber, cv::Mat& tileMat);

	void HandleExternalBing(const FString& imagerySet, const FString& bingKey);

	void AddGammaCorrection(cv::Mat& src, cv::Mat& dst, float fGamma);
};
