#pragma once

// Parent Includes
#include "Components/SceneComponent.h"

// Engine Includes
#include "Interfaces/IHttpRequest.h"
#include "HAL/ThreadSafeCounter.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_TileComponent.generated.h"


// ---------------------------------
// --- Enums
// ---------------------------------

UENUM()
enum class EComponentStatus : uint8
{
	Uninitialized,
	Initialized,
	HelperThreadStarted,
	HelperThreadFinished,
	GameThreadStarted,
	GameThreadFinished
};


// ---------------------------------
// --- Structs
// ---------------------------------

USTRUCT()
struct FGeoJsonNode
{
	GENERATED_BODY()

	FString FullPathToFile;

	FString Type;

	TArray<FGeodeticCoord3D> Coordinates;

	double MSL;
};

class AGame_VirtualObjective;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_TileComponent : public USceneComponent
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DELEGATE(FGameLogicCompletedGeneric)

public:
	FGameLogicCompletedGeneric OnGameLogicCompletedGeneric;


	// ---------------------------------
	// --- Variables
	// ---------------------------------

protected:
	int32 ZoomLevel;

	FThreadSafeCounter DestroyCounter;

	TArray<TSharedRef<IHttpRequest>> HTTPRequests;

	FThreadSafeCounter RequestsCounter;

	/*
	*\brief Key is northwest bound, value is southeast bound
	*/
	TPair<FGeodeticCoord2D, FGeodeticCoord2D> TileBounds;

	FVector2D HAEBounds;
	bool bValidHAEBounds;

private:
	EComponentStatus ComponentStatus;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
    UGame_TileComponent();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------
	 
public:
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;

	virtual bool IsReadyForFinishDestroy() override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	virtual void DownloadForOffline(const FGeodeticCoord2D& northWestBound, const FGeodeticCoord2D& southEastBound, double minZoom, double maxZoom, const FString& fullPathToOfflineFile, TFunction<void(const FString& progress)> onProgress, TFunction<void()> onDownloadComplete);

	virtual void SetComponentStatus(const EComponentStatus status);

	virtual bool GlobeReferenceScaleUpdated(const FVector& newScale3D);
	
	void SetBoundsAndZoom(const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds, int32 zoomLevel);

	bool IsMatTooBig(const int32 cols, const int32 rows) const;

	AGame_VirtualObjective* GetVirtualObjective() const;

	/* return True on successful initialization */
	virtual bool SetBoundsAndZoomVirtual(const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds, int32 zoomLevel) { return true; };

	FGeodeticCoord2D GetNorthWestBound() const { return TileBounds.Key; }

	FGeodeticCoord2D GetSouthEastBound() const { return TileBounds.Value; }

	int32 GetZoomLevel() const { return ZoomLevel; }

	EComponentStatus GetComponentStatus() const { return ComponentStatus; }

	virtual void ExecuteHelperThreadLogic() { };

	virtual void ExecuteGameThreadLogic() { };

	virtual void OnHTTPRequestComplete(const FString& fullPathOnDisk, FHttpRequestPtr request, FHttpResponsePtr response, bool bWasSuccessful) { };

	virtual bool GetHAEBounds(FVector2D& haeBounds) const;
};