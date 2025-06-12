#pragma once

#include "Blueprint/UserWidget.h"

// Engine Includes
#include "Input/Reply.h"

// Module Includes
#include "VH_ListEntryData.h"

// Generated Includes
#include "VH_UmgListEntry.generated.h"



DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSelected, UVH_UmgListEntry*, entrySelected);

UENUM(BlueprintType)
enum class EListInteractionState : uint8
{
    /** No interaction happening */
    ELIS_Available,
    ELIS_AvailablePressed,
    /** Being hovered and nothing is clicked */
    ELIS_Hovered,
    /** Currently Selected*/
    ELIS_Selected,
    ELIS_SelectedPressed,
    /** This is both selected and hovered */
    ELIS_SelectedHovered,
    /** Currently not Used */
    ELIS_Disabled
};

class UVH_UmgWidget_List;

/**
*
*/
UCLASS(Blueprintable, BlueprintType, ShowCategories = ("Defaults"), HideCategories = ("VH List Entry"))
class VH_UI_API UVH_UmgListEntry : public UUserWidget
{
    GENERATED_UCLASS_BODY()

public:

    // ---------------------------------
    // --- Member variables
    // ---------------------------------

	/** Use this to layout all the cells/columns visually. */
	UPROPERTY(BlueprintReadWrite, Category = "VH ListHeader")
	UPanelWidget* CellLayoutHandler;

    /** If we have a timeout on the popup, this is the remaining time before it auto-pops*/
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Defaults")
    UVH_ListEntryData* Data;

    EListInteractionState InteractionState;

	/** True if hover/click events need to happen based on external assignment. . .like if hit locations overlap and cannot be properly identified */
	UPROPERTY()
	bool bExternalActivation;

protected:

    /** This should be a subclass of VH_UmgWidget_List but cannot set as such or we would have a circular reference. */
    UPROPERTY(BlueprintReadOnly, Category = "Defaults")
    UVH_UmgWidget_List* OwningList;

    bool bPendingMouseClick;
	int32 PendingMouseClickIndex;

	/** True if a layout has been applied to this */
	bool bLayoutInitialized;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VH List Entry")
    bool bSupportsDragging;


    // ---------------------------------
    // --- Delegates
    // ---------------------------------

public:

    /** This is visually selected.  Could be from focus,click,multi-select,etc. */
    FOnSelected DelegateSelected;


    // ---------------------------------
    // --- Inherited Methods
    // ---------------------------------

public:

    virtual FReply NativeOnFocusReceived(const FGeometry& InGeometry, const FFocusEvent& InFocusEvent) override;
    virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;

    virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

    virtual FReply NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;


    // ---------------------------------
    // --- New Methods
    // ---------------------------------

public:

    UFUNCTION(BlueprintCallable, Category = "VH List Entry")
    virtual void SetData(UVH_ListEntryData* newData);

    UFUNCTION(BlueprintCallable, Category = "VH List Entry")
    UVH_ListEntryData* GetData() const;

	UFUNCTION(BlueprintCallable, Category = "VH List Entry")
	virtual bool SetColumnSize(int32 columnIndex, FSlateChildSize& sizingData);

	/** gets the index of this entry in a list if it is part of one.  False is returned if there is not a valid list */
	UFUNCTION(BlueprintCallable, Category = "VH List Entry")
	virtual bool GetIndexInList(int32& outListIndex) const;

    UFUNCTION(BlueprintCallable, Category = "VH List Entry")
    virtual FText GetHoverText() const;

    UFUNCTION(BlueprintCallable, Category = "VH List Entry")
    virtual void SetInteractionState(EListInteractionState newState);

    UFUNCTION(BlueprintCallable, Category = "VH List Entry")
    virtual EListInteractionState GetInteractionState() const;

	UFUNCTION(BlueprintCallable, Category = "VH List Entry")
	virtual bool IsLayoutInitialized() { return bLayoutInitialized; }

	UFUNCTION(BlueprintCallable, Category = "VH List Entry")
	virtual bool InitializeLayout(TArray<FSlateChildSize>& layoutData);

	UFUNCTION()
	virtual void SelectedChanged(bool isSelected);

    UFUNCTION()
    virtual void SetSelected(bool isSelected);

	UFUNCTION()
	virtual void SetHovered(bool newHovered);

	/** @return true if the widget is currently being hovered by a pointer device */
	UFUNCTION(BlueprintCallable, meta=(DisplayName="Is Hovered"))
	virtual bool K2_IsHovered() { return IsHovered(); }
	virtual bool IsHovered() const override { return IsHovered(InteractionState); }
	virtual bool IsHovered(EListInteractionState stateToCheck) const;

	UFUNCTION(BlueprintCallable)
	virtual bool IsSelected() { return IsSelected(InteractionState); }
	virtual bool IsSelected(EListInteractionState stateToCheck) const;

	UFUNCTION(BlueprintCallable)
	virtual bool IsDisabled() { return IsDisabled(InteractionState); }
	virtual bool IsDisabled(EListInteractionState stateToCheck) const;

    /** Called when our owning list is assigned.  We may not yet be in the list - for that use AddedToList */
    virtual void SetOwningList(UVH_UmgWidget_List* list);
	/** Called when we are a valid entry in the list */
	virtual void AddedToList(int32 indexInList);

	UFUNCTION(BlueprintCallable)
	virtual void SetLayoutHandler(UPanelWidget* newLayoutHandler);

	virtual void SetDisabled(bool isDisabled);

	// ---------------------------------
	// ---  Implementation
	// ---------------------------------


protected:

    // ---------------------------------
    // --- Blueprint Implemented
    // ---------------------------------

public:

    /** Called when data has been updated on this List Entry */
    UFUNCTION(BlueprintImplementableEvent, Category = "VH List Entry")
    void OnDataSet(UVH_ListEntryData* newData);

    UFUNCTION(BlueprintImplementableEvent, Category = "VH List Entry")
    void OnInteractionStateChanged(EListInteractionState newState);

    UFUNCTION(BlueprintImplementableEvent, Category = "VH List Entry")
    void OnSelectedChanged(bool isSelected);

	UFUNCTION(BlueprintImplementableEvent, Category = "VH List Entry")
	void OnAddedToList(int32 indexInList);
};

