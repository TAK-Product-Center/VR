// Required Includes
#include "Game_DragDropOperation_RibbonEditor.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_DragDropOperation_RibbonEditor::UGame_DragDropOperation_RibbonEditor(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{
	DragOffset = FVector2D(0, 0);
}