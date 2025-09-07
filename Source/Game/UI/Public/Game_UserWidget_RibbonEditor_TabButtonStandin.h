#pragma once

// Parent Includes
#include "Game_UserWidget_RibbonEditor_DraggableWidget.h"

// Generated Includes
#include "Game_UserWidget_RibbonEditor_TabButtonStandin.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UGame_UserWidget_RibbonEditor_TabButtonStandin : public UGame_UserWidget_RibbonEditor_DraggableWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClick, UGame_UserWidget_RibbonEditor_TabButtonStandin*, self);
	
	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FOnClick OnClick;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	UGame_UserWidget_RibbonEditor_DropTarget* LinkedContainer;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_RibbonEditor_TabButtonStandin(const FObjectInitializer& objectInitializer);

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetHoverBarPercent(float percent);
		
	
	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

protected:
	UFUNCTION(BlueprintCallable)
	void HandleOnClick(UGame_UserWidget_RibbonEditor_TabButtonStandin* tabButton);
};
