#pragma once

// Parent Includes
#include "Game_COTComponent_Draw.h"

// Generated Includes
#include "Game_COTComponent_DrawRoute.generated.h"

class FXmlNode;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_COTComponent_DrawRoute : public UGame_COTComponent_Draw
{
    GENERATED_BODY()

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

protected:
	FString RouteCallsign;

private:
	TArray<FXmlNode*> QueuedLinks;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_COTComponent_DrawRoute();

	// ---------------------------------
	// --- Inherited
	// ---------------------------------

protected:
	virtual void AddEditPoint_Virtual(AGame_SimpleSegmentedLineActor* line, AGame_EditPoint* editPoint, AGame_EditPoint* existingEditPoint) override;

	virtual void DeleteEditPoint_Virtual(AGame_SimpleSegmentedLineActor* line, AGame_EditPoint* editPoint) override;

	virtual void DeleteEditPoints_Virtual(AGame_SimpleSegmentedLineActor* line) override;

	virtual void ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent) override;

	virtual void PopulateCOT_Virtual() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
    void UpdateCallsigns();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void AddQueuedLink();
};
