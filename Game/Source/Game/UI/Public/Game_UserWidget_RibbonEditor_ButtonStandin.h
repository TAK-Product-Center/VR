#pragma once

// Parent Includes
#include "Game_UserWidget_RibbonEditor_DraggableWidget.h"

// Generated Includes
#include "Game_UserWidget_RibbonEditor_ButtonStandin.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UGame_UserWidget_RibbonEditor_ButtonStandin : public UGame_UserWidget_RibbonEditor_DraggableWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSetIcon, const FSlateBrush&, icon);
	 
	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FOnSetIcon OnSetIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FString ID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FSlateBrush Icon;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_RibbonEditor_ButtonStandin(const FObjectInitializer& objectInitializer);

	
	// ---------------------------------
	// --- API
	// ---------------------------------
	
public:
	UFUNCTION(BlueprintCallable)
	void SetIcon(const FSlateBrush& iconArg);
	
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetIcon(const FSlateBrush& iconArg);
};
