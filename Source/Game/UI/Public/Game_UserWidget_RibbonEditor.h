#pragma once

// Parent Includes
#include "Game_UserWidget_RibbonEditor_DropTarget.h"

// Engine Includes
#include "TimerManager.h"
#include "Components/ScaleBox.h"
#include "Components/Spacer.h"
#include "Components/WidgetSwitcher.h"

// Game Includes
#include "Game_UserWidget_RibbonEditor_ButtonStandin.h"
#include "Game_UserWidget_RibbonEditor_CategoryStandin.h"
#include "Game_UserWidget_RibbonEditor_TabButtonStandin.h"

// Generated Includes
#include "Game_UserWidget_RibbonEditor.generated.h"

// ---------------------------------
// --- Structs
// ---------------------------------

USTRUCT(BlueprintType)
struct FRibbonButtonProxyOverride
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Text;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FSlateBrush Icon;

	FRibbonButtonProxyOverride()
	{
		Text = "";
	}
};

UCLASS(BlueprintType, Blueprintable)
class UGame_UserWidget_RibbonEditor : public UGame_UserWidget_RibbonEditor_DropTarget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	bool IsDragging;

	FVector2D CurrentLocation;

	UPROPERTY()
	UGame_UserWidget_RibbonEditor_DropTarget* CurrentHover;
	
	float HoverTimer;

protected:
	UPROPERTY(BlueprintReadOnly)
	FString CurrentLayout;
	
	UPROPERTY(BlueprintReadOnly)
	FString ErrorMessage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_UserWidget_RibbonEditor_DraggableWidget* RenameTarget;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UWidgetSwitcher* TabContainers;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UPanelWidget* TabButtonList;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_UserWidget_RibbonEditor_CategoryStandin* Trash;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGame_UserWidget_RibbonEditor_ButtonStandin> ButtonWidgetClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGame_UserWidget_RibbonEditor_CategoryStandin> CategoryWidgetClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGame_UserWidget_RibbonEditor_DropTarget> TabWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGame_UserWidget_RibbonEditor_TabButtonStandin> TabButtonWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_UserWidget_RibbonEditor_DropTarget* Background;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UGame_UserWidget_RibbonEditor_DropTarget* Spacer;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UPanelWidget* SpacerParent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int SpacerIndex;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString LayoutFolderPath;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FString, FRibbonButtonProxyOverride> VisualOverrides;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float HoverTabSwapDelay;

	// ---------------------------------
	// --- Constructor
	// ---------------------------------

public:
	UGame_UserWidget_RibbonEditor(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetSpacerSize(const FVector2D& inDragDropLocation);

public:
	UFUNCTION(BlueprintCallable)
	void LoadLayout(const FString& layoutName);

	UFUNCTION(BlueprintCallable)
	void LoadDefaultLayout();
	
	UFUNCTION(BlueprintCallable)
	bool SaveLayout(const FString& layoutName);

	UFUNCTION(BlueprintCallable)
	void SwitchToTab(UGame_UserWidget_RibbonEditor_TabButtonStandin* tabToLoad);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowRename(UGame_UserWidget_RibbonEditor_DraggableWidget* widgetToRename);

	UFUNCTION(BlueprintCallable)
	FString AttemptRename(const FString& newName);

	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void InsertChild(UWidget* newChild, UPanelWidget* newParent, int newIndex);
	
	void SetSpacerLocation(UPanelWidget* newParent, int newIndex);

	UGame_UserWidget_RibbonEditor_CategoryStandin* TabContainsCatOfName(UPanelWidget* containingTab, const FString& categoryName);

protected:
	void EmplaceButton(UGame_UserWidget_RibbonEditor_ButtonStandin* ribbonButton, const FString& tabName, const FString& categoryName, int index);
	
	UFUNCTION(BlueprintCallable)
	bool AddTab(const FString& tabName, UGame_UserWidget_RibbonEditor_TabButtonStandin*& outNewTabButton);

	UFUNCTION(BlueprintCallable)
	bool AddCategory(const FString& catName, UGame_UserWidget_RibbonEditor_DropTarget* containingTab, UGame_UserWidget_RibbonEditor_CategoryStandin*& outNewCategory);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ShowError(const FString& error);
	
	UFUNCTION(BlueprintCallable)
	FString GetPathForLayout(const FString& layoutName);
	
	UFUNCTION(BlueprintCallable)
	void ImportLayout(const FString& layoutPath);
	
	UFUNCTION(BlueprintCallable)
	void ExportLayout(const FString& newPath);
	
	UFUNCTION(BlueprintCallable)
	void DeleteLayout(const FString& layoutName);
	
	
	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

protected:
	UFUNCTION()
	void HandleBeginWidgetDrag(UGame_UserWidget_RibbonEditor_DraggableWidget* dragWidget, const FGeometry& inGeometry, const FPointerEvent& inMouseEvent, UDragDropOperation* inOperation);

	UFUNCTION()
	void HandleWidgetOver(UGame_UserWidget_RibbonEditor_DropTarget* overTarget, const FGeometry& inGeometry, const FVector2D& inDragDropLocation, UDragDropOperation* inOperation);
	
	UFUNCTION()
	void HandleWidgetDropped(UGame_UserWidget_RibbonEditor_DropTarget* dropTarget, const FGeometry& inGeometry, const FVector2D& inDragDropLocation, UDragDropOperation* inOperation);
};
