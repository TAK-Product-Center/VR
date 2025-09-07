#pragma once

// Parent Includes
#include "Game_UserWidget_RibbonEditor_DraggableWidget.h"

// Engine Includes
#include "Blueprint/DragDropOperation.h"

// Generated Includes
#include "Game_DragDropOperation_RibbonEditor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UGame_DragDropOperation_RibbonEditor : public UDragDropOperation
{
	GENERATED_BODY()
	 
	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	UGame_UserWidget_RibbonEditor_DraggableWidget* DragTarget;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FVector2D DragOffset;
	

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_DragDropOperation_RibbonEditor(const FObjectInitializer& objectInitializer);
};
