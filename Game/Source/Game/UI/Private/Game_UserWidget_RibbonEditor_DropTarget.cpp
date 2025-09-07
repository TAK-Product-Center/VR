#include "Game_UserWidget_RibbonEditor_DropTarget.h"

#include "Blueprint/WidgetLayoutLibrary.h"

UGame_UserWidget_RibbonEditor_DropTarget::UGame_UserWidget_RibbonEditor_DropTarget(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{
}

bool UGame_UserWidget_RibbonEditor_DropTarget::NativeOnDragOver(const FGeometry& inGeometry,
	const FDragDropEvent& inDragDropEvent, UDragDropOperation* inOperation)
{
	FVector2D location = UWidgetLayoutLibrary::GetMousePositionOnPlatform();
	OnDragOverEvent.Broadcast(this, inGeometry, location, inOperation);
	return true;
}

bool UGame_UserWidget_RibbonEditor_DropTarget::NativeOnDrop(const FGeometry& inGeometry,
                                                            const FDragDropEvent& inDragDropEvent, UDragDropOperation* inOperation)
{
	FVector2D location = UWidgetLayoutLibrary::GetMousePositionOnPlatform();
	OnDropEvent.Broadcast(this, inGeometry, location, inOperation);
	return true;
}
