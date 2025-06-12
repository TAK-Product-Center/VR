#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_MapScrape.generated.h"

class AGame_DrawContainer;
class AGame_EditPoint;
class UGame_TileComponent;
class AGame_SimpleSegmentedLineActor;
class AGame_Tool;
struct FGeodeticCoord2D;

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_MapScrape : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	FString DrawContainerEntityUID;

	UPROPERTY()
	UGame_TileComponent* MapScrapeComponent;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_MapScrape(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginDestroy() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveChooseBounds(const FString& callsign, const FString& swBound, const FString& neBound);
	
	void LineClicked(AGame_SimpleSegmentedLineActor* line);

	UFUNCTION(BlueprintCallable)
	void Abort();

	UFUNCTION(BlueprintCallable)
	bool Execute(int32 minZoom, int32 maxZoom, const FString& fullPathToOfflineFile, FString& error);

	UFUNCTION(BlueprintCallable)
	void SelectTool(TSubclassOf<AGame_Tool> toolClass);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveMapScrapeFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveMapScrapeProgress(const FString& progress);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	AGame_DrawContainer* GetDrawContainer() const;

	void GetBounds(AGame_SimpleSegmentedLineActor* line, FGeodeticCoord2D& northWestBound, FGeodeticCoord2D& southEastBound) const;
};