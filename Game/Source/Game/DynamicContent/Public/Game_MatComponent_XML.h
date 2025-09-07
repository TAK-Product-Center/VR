#pragma once

// Parent Includes
#include "Game_TileComponent_Mat.h"

// Engine Includes
#include "HAL/ThreadSafeBool.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_MatComponent_XML.generated.h"


// ---------------------------------
// --- Enums
// ---------------------------------

UENUM()
enum class EAttempt : uint8
{
	Google,
	TMS,
	TMS_Y_Reversed
};

class FXmlNode;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_MatComponent_XML : public UGame_TileComponent_Mat
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	TPair<int32, int32> NorthWestTile;
	TPair<int32, int32> SouthEastTile;

	FString SourceName;

	FString SourceType;

	int32 MinZoom;

	int32 MaxZoom;

	FString URL;

	TArray<FString> ServerParts;

	int32 PixelWidth;

	int32 PixelHeight;

	bool bXMLLoaded;

	bool bOffline;

	FString OfflineDownloadFilename;

	FThreadSafeBool bGeneratedMat;

	TMap<TPair<int32, int32>, TArray<uint8>> TileToMatData;

	EAttempt Attempt;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_MatComponent_XML();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	static TArray<FString> GetImageryXMLSources();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;

	virtual void ExecuteHelperThreadLogic() override;

	virtual void ExecuteGameThreadLogic() override;

	virtual float GetAlpha() override;

	virtual void DownloadForOffline(const FGeodeticCoord2D& northWestBound, const FGeodeticCoord2D& southEastBound, double minZoom, double maxZoom, const FString& fullPathToOfflineFile, TFunction<void(const FString& progress)> onProgress, TFunction<void()> onDownloadComplete) override;

protected:
	virtual bool SetBoundsAndZoomVirtual(const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds, int32 zoomLevel) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void OnHTTPRequestComplete(const FString& identifier, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful);

	void ReadFromXML(FXmlNode* rootNode);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	bool ReadFromXML(const FString& fullPathToXMLs, const FString& sourceName);

	void CreateMat();

	cv::Mat CreateMatOfAllTiles(int32 pixelsX, int32 pixelsY);

	bool IsSafeToExecute();

	bool GetCachedMat(const TPair<int32, int32>& tileNumber, cv::Mat& tileMat);
};
