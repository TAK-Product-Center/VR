#pragma once

// Parent Includes
#include "Game_COTComponent_Draw.h"

// Generated Includes
#include "Game_COTComponent_DrawRangeBearing.generated.h"

class AGame_Arrow;
class AGame_WorldInteractableActor;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_COTComponent_DrawRangeBearing : public UGame_COTComponent_Draw
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_Arrow> ArrowClass;

private:
	UPROPERTY()
	AGame_Arrow* Arrow;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_COTComponent_DrawRangeBearing();


	// ---------------------------------
	// --- Inherited 
	// ---------------------------------

protected:
	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;

    virtual void ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent) override;

    virtual void PopulateCOT_Virtual() override;

	virtual void SetEditPointsActive(AGame_SimpleSegmentedLineActor* line, bool bActive) override;

	virtual void HandleOwnerSetHidden(bool bNewHidden) override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	AGame_Arrow* SpawnArrow(const FVector& editPointLocation);

	UFUNCTION(BlueprintPure)
	AGame_Arrow* GetArrow() const;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleManipulationEnd(AActor* manipulatedActor);
};