#pragma once

// Parent Includes
#include "Game_COTComponent_Draw.h"

// Generated Includes
#include "Game_COTComponent_DrawPolyline.generated.h"

class FXmlNode;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_COTComponent_DrawPolyline : public UGame_COTComponent_Draw
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	TArray<FXmlNode*> QueuedLinks;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_COTComponent_DrawPolyline();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

protected:
	virtual void ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent) override;

	virtual void PopulateCOT_Virtual() override;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void AddQueuedLink();
};