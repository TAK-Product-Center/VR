#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_RibbonEditor_DropTarget.generated.h"


// ---------------------------------
// --- Enums
// ---------------------------------

UENUM()
enum class EDragDropTargetType : uint8
{
	RibbonButton,
	Category,
	TabButton,
	TabContainer,
	Trash,
	Spacer,
	Background
};

UCLASS(BlueprintType, Blueprintable)
class UGame_UserWidget_RibbonEditor_DropTarget : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FRibbonEditorDragEvent,
		UGame_UserWidget_RibbonEditor_DropTarget*, dropTarget,
		const FGeometry&, inGeometry,
		const FVector2D&, inDragDropEvent,
		UDragDropOperation*, inOperation);
	 
	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FRibbonEditorDragEvent OnDragOverEvent;
	
	UPROPERTY(BlueprintAssignable)
	FRibbonEditorDragEvent OnDropEvent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	EDragDropTargetType Type;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_RibbonEditor_DropTarget(const FObjectInitializer& objectInitializer);

	
	// ---------------------------------
	// --- API
	// ---------------------------------
	
public:
	UFUNCTION(BlueprintImplementableEvent)
	UPanelWidget* GetPanelWidget();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual bool NativeOnDragOver(const FGeometry& inGeometry, const FDragDropEvent& inDragDropEvent, UDragDropOperation* inOperation) override;
	
	virtual bool NativeOnDrop(const FGeometry& inGeometry, const FDragDropEvent& inDragDropEvent, UDragDropOperation* inOperation) override;
};
