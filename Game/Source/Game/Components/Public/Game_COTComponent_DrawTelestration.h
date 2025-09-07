#pragma once

#include "Game_COTComponent_Draw.h"
#include "Game_COTComponent_DrawTelestration.generated.h"

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_COTComponent_DrawTelestration : public UGame_COTComponent_Draw
{
    GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UGame_COTComponent_DrawTelestration();

	// ---------------------------------
	// --- Inherited
	// ---------------------------------
protected:
	virtual void ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent) override;

	virtual void PopulateCOT_Virtual() override;
};
