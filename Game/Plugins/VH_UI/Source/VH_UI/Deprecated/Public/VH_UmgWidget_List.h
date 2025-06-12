#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Engine Includes
#include "Components/PanelWidget.h"
#include "Components/SlateWrapperTypes.h"

// Module Includes
#include "VH_ListEntryData.h"
#include "VH_UmgListEntry.h"

// Generated Include
#include "VH_UmgWidget_List.generated.h"


UENUM(BlueprintType)
enum class EListInteractionStyle : uint8
{
	/** Standard List interaction.  Only a single item is selected by clicking, but modifier keys allow multi-selection */
	ELIS_List,
	/** Only a single item can be selected at a time.  A selection is not required currently*/
	ELIS_RadioButtons,
	/** clicks will toggle selection on each entry.  Multiple entries can be selected. */
	ELIS_Checkboxes
};

UENUM(BlueprintType)
enum class ESortType : uint8
{
	Ascending UMETA(DisplayName = "Ascending"),
	Descending UMETA(DisplayName = "Descending"),
	Default UMETA(DisplayName = "Default")
};


/**
 * @brief Class that is responsible for managing list entry selection and activation. 
 *	The primary function of the list is managing list entry states. List can be created dynamically and does not need a widget representation.
 *	Lists are composed of 4 basic elements
 *		1: the list which manages the selection states of elements
 *		2: listEntries which are widgets responsible for visualization of a list element and all interactions. May not have list entries for all data, especially if there is a lot of data where only a 
 *			small subset is visible at any time. Generally assigned to data as it is added since there can be multiple List Entry classes used within a single list.
 *		3: ListEntryData which is the data for all list elements.  Data is contained for all elements even those not visualized
 *		4: ListEntry Layout is handled by an assigned panel which is resposible for layout out all List entries.  Entries can be swapped from vertical, horizontal, grid, etc. without changing anything
 *			else about the list.  Assign through 'AssignLayoutHandler'
 * 
 *	Most common implementation is to create a UVH_UmgWidget_List widget at runtime, call 'SetLayoutHandler' on it with the panel to layout entries, and add entries to it through CreateEntryByClass.
 *	Unique listEntryData class and a ListEntry blueprint are nearly always desired.
 */
UCLASS(Blueprintable, BlueprintType, ShowCategories=("Defaults"), HideCategories=("VH List"))
class VH_UI_API UVH_UmgWidget_List : public UUserWidget
{
    GENERATED_UCLASS_BODY()

	// ---------------------------------
	// --- Delegates
	// ---------------------------------
public:

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnListSelectionChanged, const TArray<UVH_UmgListEntry*>&, curSelectedEntries);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEntryEvent, UVH_ListEntryData*, data, UVH_UmgListEntry*, listEntry);
	/** Return true if the sorting has been handled.  Otherwise default algorithms will be used */
	DECLARE_DYNAMIC_DELEGATE_RetVal_TwoParams(bool, FOnSortRequest, int32, sortColumn, ESortType, sortType);


    // ---------------------------------
    // --- Variables
    // ---------------------------------

public:
    /** 
	 * @brief Called whenever any selection has changed 
	 * @param curSelectedEntries List of all entries that are now selected.  Range of allowed simultaneously selected entries is defined by listInteractionStyle
	 */
	UPROPERTY(BlueprintAssignable)
	FOnListSelectionChanged DelegateListSelectionChanged;

	/** 
	 * @brief Called when a list entry has received a click event
	 * @param data Data associated with the clicked list entry
	 * @param listEntry List entry widget that was clicked
	 */
	UPROPERTY(BlueprintAssignable)
	FOnEntryEvent DelegateEntryClicked;

	/**
	 * @brief Called when a list entry has received a double click event
	 * @param data Data associated with the double clicked list entry
	 * @param listEntry List entry widget that was double clicked
	 */
	UPROPERTY(BlueprintAssignable)
	FOnEntryEvent DelegateEntryDoubleClicked;

	/**
	 * @brief Called when a list entry has received an enter press event.  List entry widget must have been focused to receive event
	 * @param data Data associated with the list entry
	 * @param listEntry List entry widget that received an enter press event
	 */
	UPROPERTY(BlueprintAssignable)
	FOnEntryEvent DelegateEnterPressed;

protected:

	/**
	 * @brief Called when a list entry has become selected.
	 * @param data Data associated with the list entry
	 * @param listEntry List entry widget that was selected
	 */
    FOnEntryEvent DelegateEntrySelected;

public:
	/** Use this to layout all the header regions visually. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VH List")
	UPanelWidget* RegionLayoutHandler;

	/** Panel that is responsible for visual layout of all list entries. Can be null if list widget handles layout of entries (not recommended) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VH List")
	UPanelWidget* LayoutHandler;

    /** List of all ListEntry widgets that are registered */
    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "VH List")
    TArray<UVH_UmgListEntry*> ListEntries;

	/** How list should be interacted with or thought of from a high level.  Defines range of allowed item selections and selection/deselection behavior. 
	 *	For instance, RadioButton style required exactly one active selection at all times
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Defaults")
	EListInteractionStyle ListInteractionStyle;

	/** 
	 * @brief For NATIVE ONLY requests for sorting.  Consider using in conjunction with a BlueprintNativeEvent.  LastSortColumn and LastSortType data from previous sort and have not yet 
	 *	been updated.
	 * @param sortColumn column the sort was requested for
	 * @param sortType If sort should be in ascending or descending order
	 * @return bool True if sort was successful
	 */
	UPROPERTY()
	FOnSortRequest OnSortRequested;

	/** Column that was previously sorted on, -1 if no sort has been performed*/
	int32 LastSortColumn;
	/** Sort type used for previously performed sort, ESortType::Default if none performed */
	ESortType LastSortType;

protected:

	/** NOT CURRENTLY IMPLEMENTED */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "VH List")
	bool bShowHeader;

	/** NOT CURRENTLY IMPLEMENTED */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Defaults")
	bool bDynamicColumnSizes;

	/** Current layout data for cells in the list.  We cache this for speed reasons. Each FSlateChildSize corresponds to a column within the list. */
	TArray<FSlateChildSize> CurrentLayoutData;

	/** All currently selected entries*/
    UPROPERTY()
    TArray<UVH_UmgListEntry*> SelectedEntries;

    /** This can coincide with selected indices, but most closely is tied to the current focus location for keyboard/hotkey input */
    // Not currently used since we can use the last index in the selectedIndices as our focused index and each input method can have a unique focus chain
    /*UPROPERTY()
    int32 FocusedIndex;*/

	/** True if list has been updated and layout data needs to be regenerated.  Handled as a latent action since it is very common to have many list entries added/removed
	 *	within the same frame/update cycle
	 */
	bool bNeedsRebuild;


    // ---------------------------------
    // --- Inherited
    // ---------------------------------

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

    virtual FReply NativeOnFocusReceived(const FGeometry& InGeometry, const FFocusEvent& InFocusEvent) override;
    virtual FReply NativeOnKeyChar(const FGeometry& InGeometry, const FCharacterEvent& InCharEvent) override;
    virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

    
    // ---------------------------------
    // --- API
    // ---------------------------------

public:

    /**
     * @brief Retrieves the total number of entries within the list
    */
    UFUNCTION(BlueprintCallable, Category = "VH List")
    int32 GetNumEntries() const { return ListEntries.Num(); }

	/**
	 * @brief Set list selection behavior for min/max number of selected items.  List: min=0, max=1  Checkbox: min=0, max=all   radioButton: min=1, max=1. 
	 *	Will deselect entries when applied if too many are selected, but should not select an entry if one is required (RadioButton)
	 * @param newInteractionStyle The new interaction style to apply to the list.  
	*/
	UFUNCTION(BlueprintCallable, Category = "VH List")
	virtual void SetInteractionStyle (EListInteractionStyle newInteractionStyle);

	/**
	 * @brief True if we can select more than one entry (Checkbox interaction style)
	*/
	UFUNCTION(BlueprintCallable)
	virtual bool CanMultiSelect() const;

	/**
	 * @brief True if InteractionStyle prefers (may not require) single selection. A List style prefers single selection but multi-select can be achieved with 
	 *	shift/ctrl keys.
	*/
	UFUNCTION(BlueprintCallable)
	virtual bool PreferSingleSelection() const;

	/** True if re-clicking an index will toggle the selection */
	UFUNCTION(BlueprintCallable)
	virtual bool CanToggleSelection() const;

	/**
	 * @brief Assign the panel widget that entries will be added to.  Assign this to allow the list to interact with the panel directly for add/remove/index operations
	*/
	UFUNCTION(BlueprintCallable)
	virtual void SetLayoutHandler(UPanelWidget* newLayoutHandler) { SetEntryLayoutHandler(newLayoutHandler); }
	virtual void SetEntryLayoutHandler(UPanelWidget* newLayoutHandler);

    /** 
	 * @brief Adds a ListEntry widget to the list and initializes it with all appropriate data.
	 * @param data ListEntryData for the new list element
	 * @param widgetInstance ListEntry widget we are adding to the list.
	 * @param overrideIdx Optional index at which to insert new entry into the list.  List entry will be added to the end of the list if not specified
    */
    UFUNCTION(BlueprintCallable, Category = "VH List")
    virtual void CreateEntry(UVH_ListEntryData* data, UVH_UmgListEntry* widgetInstance, int32 overrideIdx = -1);

	/**
	 * @brief Creates and registers a new ListEntry widget of the specified type for the passed in data
	 * @param data ListEntryData for the new list element
	 * @param widgetInstance class of ListEntry widget to create/initialize.
	 * @param overrideIdx Optional index at which to insert new entry into the list.  List entry will be added to the end of the list if not specified
	*/
	UFUNCTION(BlueprintCallable, Category = "VH List", meta = (DeterminesOutputType = "widgetInstance"))
    virtual UVH_UmgListEntry* CreateEntryByClass(UVH_ListEntryData* data, TSubclassOf<class UVH_UmgListEntry> widgetInstance, int32 overrideIdx = -1);

    /**
     * @brief Removes an entry from the list
	 * @param widgetInstance Widget instance to be removed from the list
	 * @return True if widgetInstance was valid and successfully removed from the list
    */
    UFUNCTION(BlueprintCallable, Category = "VH List")
    virtual bool RemoveEntry(UVH_UmgListEntry* widgetInstance);

	/**
	 * @brief Removes a widgetInstance base on the represented ListEntryData
	 * @param data Data we we want to remove from the list
	 * @return true if ListEntry was successfully removed from the list
	*/
	UFUNCTION(BlueprintCallable, Category = "VH List")
	virtual bool RemoveEntryByData(UVH_ListEntryData* data);

    /**
     * @brief Removes all list entries, data, and selections
    */
    UFUNCTION(BlueprintCallable, Category = "VH List")
    virtual void ClearEntries();

    /**
     * @brief Retrieves a list of all list entries registered to the list
	 * @return all registered list entries
    */
    UFUNCTION(BlueprintCallable, Category = "VH List")
    virtual TArray<UVH_UmgListEntry*> GetListEntries() const;

    /**
     * @brief Finds the index of a specified entry
	 * @param entry ListEntry widget to find
	 * @return Index of the widget in the list, INDEX_NONE(-1) if not found
    */
    UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "VH List")
    virtual int32 GetEntryIndex(const UVH_UmgListEntry* entry) const;

	/**
	 * @brief Moves an entry within the list to a desired index, or as close to it as possible
	 * @param entry ListEntry widget we want to move
	 * @param desiredIndex Index we want the entry in
	 * @return Index the entry index is now at, INDEX_NONE (-1) if not in list
	*/
	UFUNCTION(BlueprintCallable, Category = "VH List")
	virtual int32 SetEntryIndex(UVH_UmgListEntry* entry, int32 desiredIndex);

    /**
     * @brief Retrieves the index of the ListEntry widget associated with the specified data
	 * @param data ListEntryData we want to get the index for
	 * @return index of the ListEntryData or INDEX_NONE (-1) if not found
    */
    UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "VH List")
    virtual int32 GetDataIndex(const UVH_ListEntryData* data) const;

    /**
     * @brief Retrieves ListEntry widget at the specified index
	 * @param entryIdx Index to retrieve the list entry from
	 * @retrun ListEntry widget at the specified index or nullptr if index was invalid
    */
    UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "VH List")
    virtual UVH_UmgListEntry* GetEntryAtIndex(int32 entryIdx) const;

	/**
	 * @brief Retrieves the ListEntry widget for the specified ListEntryData
	 * @param data ListEntryData to find associated ListEntry for
	 * @return ListEntry widget for the specified data, or nullptr if not found
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "VH List")
	virtual UVH_UmgListEntry* GetEntryForData(const UVH_ListEntryData* data) const;

	/**
	 * @brief Retrieves a list of all indices that are currently selected
	 * @return all currently selected indices
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure = false, Category = "VH List")
    virtual TArray<int32> GetSelectedIndices() const;

	/**
	 * @brief Retrieves a list of all selected ListEntry widgets
	 * @return list of all selected ListEntry widgets
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category = "VH List")
    virtual TArray<UVH_UmgListEntry*> GetSelectedEntries() const;

    /**
     * @brief Marks a specified index as selected.  InteractionStyle may clear other selection but can be affected by active modifiers such at ctrl/alt
	 * @param bForceClearPreviousSelections True if we want all previous selections to be cleared.  Default is false
    */
    UFUNCTION(BlueprintCallable, Category = "VH List")
    virtual void SetIndexSelected(int32 entryIdx, bool bForceClearPreviousSelections = false);

	/** 
	 * @brief Marks set of indices as the selected indices. We always clear previous selections or the intent of the method becomes ambiguous.  Subject
	 *	to limitations of ListInteractionStyle.  If not all specified elements may be selected then first selectable elements will be used until limit reached
	 * @param selectedIndices Set of indices we want to try and select
	 */
	UFUNCTION(BlueprintCallable, Category = "VH List")
	virtual void SetIndicesSelected(TArray<int32> selectedIndices);

    /** 
	 * @brief Use to mark an entries selection status from external stimulus.  Subject to limitations of ListInteractionStyle. 
	 * @param bForceClearPreviousSelections True if we want all previous selections to be cleared.  Default is false
	 */
    UFUNCTION(BlueprintCallable, Category = "VH List")
    virtual void SetEntrySelected(UVH_UmgListEntry* entry, bool bForceClearPreviousSelections = false);

    /**
     * @brief Set ListEntry widget as selected based on specified ListEntryData
	 * @param data ListEntryData we want associated ListEntry widget to be marked as selected for
	 * @param bForceClearPreviousSelections True if we want all previous selections to be cleared.  Default is false
    */
    UFUNCTION(BlueprintCallable, Category = "VH List")
    virtual void SetEntryDataSelected(UVH_ListEntryData* data, bool bForceClearPreviousSelections = false);

	/**
	 * @brief Deselects a specified entry.  May be disallowed by ListInteractionStyle such as with RadioButtons
	 * @param entry ListEntry widget to deselect
	*/
	UFUNCTION(BlueprintCallable, Category = "VH List")
	virtual void DeselectEntry(UVH_UmgListEntry* entry);

    /**
     * @brief Clears all selections.  RadioButton ListInteractionStyle may reapply a selection if at least one is required
    */
    UFUNCTION(BlueprintCallable, Category = "VH List")
    virtual void ClearSelections();

	/**
	 * @brief Updates layout data for list and re-adds all children to layoutHandler.
	*/
	UFUNCTION()
	virtual void RebuildVisualList();

	/** 
	 * @brief Sorts list entry data
	 * @param columnIdx Column index to sort by
	 * @param sortType Specified sort direction such as ascending or descending 
	 * @return True if successfully sorted by specified column and type
	 */
	UFUNCTION()
	virtual bool SortByColumn(int32 columnIdx, ESortType sortType);

	/**
	 * @brief Assign sizing data to a specified slot in the HeaderLayoutHandler
	 * @param slotHandle Specific slot we want to update the sizing data for.  Mostly assigned dynamically the list, but can be handled externally
	 * @param sizingData sizingData that we want to apply to the panel slot
	*/
	UFUNCTION()
	virtual void SetSlotSizeData(UPanelSlot* slotHandle, FSlateChildSize& sizingData);

	/**
	 * @brief Requests an update of all cell sizes by asking header for desired column sizes and applying to ListEntry widgets
	*/
	UFUNCTION()
	virtual void UpdateAllCellSizes();

	/**
	 * @brief Requests column size from header for specified column index and applies it to all ListEntries
	*/
	UFUNCTION()
	virtual void UpdateCellSizes(int32 columnIndex);



    // ---------------------------------
    // --- Event Handlers
    // ---------------------------------

    UFUNCTION(BlueprintCallable)   // Make this not blueprint callable
    virtual void HandleEntryClicked(UVH_UmgListEntry* entry);

    UFUNCTION()
    virtual void HandleEntryDoubleClicked(UVH_UmgListEntry* entry);

    UFUNCTION()
    virtual void HandleEnterPressed(UVH_UmgListEntry* entry);

	/** 
	 * @brief Nearly identical to signing up for the selection delegate, but easier to discover 
	 */
	UFUNCTION(BlueprintImplementableEvent)
	void OnInternalSelectionChanged(const TArray<UVH_UmgListEntry*>& curSelectedEntries);



protected:
	/////////// List entry BP Forwards ////////////////

    /**
     * @brief Removes all item from the List.  Native will remove all elements from a specified handler.
    */
    UFUNCTION(BlueprintNativeEvent, Category = "VH List")
    void ClearItems();

	/**
	 * @brief Removes the entry from the list.  Native has a default implementation to remove it from the specified handler.
	 * @param widgetInstance Widget that should be removed from the list.
	 */
    UFUNCTION(BlueprintNativeEvent, Category = "VH List")
    bool RemoveItem(UVH_UmgListEntry* widgetInstance);
    
	/**
	 * @brief Adds the entry to the list.  Native has a default implementation to add it to a specified handler.
	 * @param widgetInstance Widget that should be added to the list.  
	 */
    UFUNCTION(BlueprintNativeEvent, Category = "VH List")
    void AddItem(UVH_UmgListEntry* widgetInstance);

	/**
	 * @brief Inserts the entry to the list. Native has a default implementation to add it to a specified handler.
	 * @param widgetInstance Widget that should be inserted into the list. 
	 */
	UFUNCTION(BlueprintNativeEvent, Category = "VH List")
	void InsertItem(UVH_UmgListEntry* widgetInstance, int32 insertIdx);

};

