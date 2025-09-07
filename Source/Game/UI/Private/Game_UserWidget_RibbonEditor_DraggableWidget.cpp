#include "Game_UserWidget_RibbonEditor_DraggableWidget.h"

#include "Game_DragDropOperation_RibbonEditor.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_RibbonEditor_DraggableWidget::UGame_UserWidget_RibbonEditor_DraggableWidget(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{
	DragOffset = FVector2D(0, 0);
}


// ---------------------------------
// --- Inherited
// ---------------------------------

FReply UGame_UserWidget_RibbonEditor_DraggableWidget::NativeOnMouseButtonDown(const FGeometry& inGeometry,
                                                                              const FPointerEvent& inMouseEvent)
{
	if(Type != EDragDropTargetType::Trash)
	{
		DragOffset = inGeometry.AbsoluteToLocal(inMouseEvent.GetScreenSpacePosition());
		return UWidgetBlueprintLibrary::DetectDragIfPressed(inMouseEvent, this, EKeys::LeftMouseButton).NativeReply;
	}
	return FReply::Handled();
}

FReply UGame_UserWidget_RibbonEditor_DraggableWidget::NativeOnMouseButtonDoubleClick(const FGeometry& inGeometry,
	const FPointerEvent& inMouseEvent)
{
	Super::NativeOnMouseButtonDoubleClick(inGeometry, inMouseEvent);
	OnDoubleClick.Broadcast(this);
	return FReply::Handled();
}

void UGame_UserWidget_RibbonEditor_DraggableWidget::NativeOnDragDetected(const FGeometry& inGeometry,
                                                                         const FPointerEvent& inMouseEvent, UDragDropOperation*& outOperation)
{
	if(Type != EDragDropTargetType::Trash)
	{
		Super::NativeOnDragDetected(inGeometry, inMouseEvent, outOperation);

		UGame_DragDropOperation_RibbonEditor* DragDropOperation = NewObject<class UGame_DragDropOperation_RibbonEditor>();
		SetVisibility(ESlateVisibility::HitTestInvisible);

		DragDropOperation->DragTarget = this;
		DragDropOperation->DragOffset = DragOffset;

		DragDropOperation->DefaultDragVisual = this;
		DragDropOperation->Pivot = EDragPivot::MouseDown;

		outOperation = DragDropOperation;

		OnBeginDragEvent.Broadcast(this, inGeometry, inMouseEvent, outOperation);
	}
}

void UGame_UserWidget_RibbonEditor_DraggableWidget::NativeOnDragLeave(const FDragDropEvent& inDragDropEvent,
	UDragDropOperation* inOperation)
{
	Super::NativeOnDragLeave(inDragDropEvent, inOperation);
}

void UGame_UserWidget_RibbonEditor_DraggableWidget::SetText(const FString& text)
{
	Text = text;

	ReceiveSetText(Text);

	OnSetText.Broadcast(text);
}
