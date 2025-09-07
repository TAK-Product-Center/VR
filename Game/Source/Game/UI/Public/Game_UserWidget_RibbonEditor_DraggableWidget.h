#pragma once

// Parent Includes
#include "Game_UserWidget_RibbonEditor_DropTarget.h"

// Generated Includes
#include "Game_UserWidget_RibbonEditor_DraggableWidget.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UGame_UserWidget_RibbonEditor_DraggableWidget : public UGame_UserWidget_RibbonEditor_DropTarget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FRibbonEditorOnBeginDrag,
		UGame_UserWidget_RibbonEditor_DraggableWidget*, DragWidget,
		const FGeometry&, InGeometry,
		const FPointerEvent&, InMouseEvent,
		UDragDropOperation*, InOperation);
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSetText, const FString&, text);
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDoubleClick, UGame_UserWidget_RibbonEditor_DraggableWidget*, self);
	 
	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FRibbonEditorOnBeginDrag OnBeginDragEvent;
	
	UPROPERTY(BlueprintAssignable)
	FOnSetText OnSetText;
	
	UPROPERTY(BlueprintAssignable)
	FOnDoubleClick OnDoubleClick;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	UPanelWidget* Parent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FVector2D DragOffset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FString Text;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	int Index;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_RibbonEditor_DraggableWidget(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& inGeometry, const FPointerEvent& inMouseEvent) override;

	virtual FReply NativeOnMouseButtonDoubleClick(const FGeometry& inGeometry, const FPointerEvent& inMouseEvent) override;

	virtual void NativeOnDragDetected(const FGeometry& inGeometry, const FPointerEvent& inMouseEvent, UDragDropOperation*& outOperation) override;

	virtual void NativeOnDragLeave(const FDragDropEvent& inDragDropEvent, UDragDropOperation* inOperation) override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------
	
public:
	UFUNCTION(BlueprintCallable)
	void SetText(const FString& textArg);
	
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetText(const FString& textArg);

};
