#pragma once

// Parent Includes
#include "Subsystems/WorldSubsystem.h"

// Generated Includes
#include "Developer_Subsystem_Selection.generated.h"

class UObject;

UCLASS()
class VH_DEVELOPER_API UDeveloper_Subsystem_Selection : public UWorldSubsystem
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// --------------------------------
	
private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSelectionChanged, UObject*, object, bool, bSelected);

	 
	// ---------------------------------
	// --- Variables
	// ---------------------------------
	 
public:
	/* broadcast when an object is selected or deselected */
	UPROPERTY(BlueprintAssignable)
	FOnSelectionChanged OnSelectionChanged;

private:
	UPROPERTY()
	TMap<UObject*, int64> SelectedObjects;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_Subsystem_Selection();

	
	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UDeveloper_Subsystem_Selection* Get();


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	* /brief Removes all objects from the selection list
	*/
	UFUNCTION(BlueprintCallable)
	void ClearSelections();

	/*
	* /brief Selects object, optionally clearing list
	* /param object Object to select
	* /param bClearExisting If true, clears existing selection before selecting object
	* /note Selected objects will not be garbage collected while selected 
	*/
	UFUNCTION(BlueprintCallable)
	void Select(UObject* object, bool bClearExisting);

	/*
	* /brief Removes the given object from the selection if it is currently selected
	* /param object Object to remove
	*/
	UFUNCTION(BlueprintCallable)
	void Deselect(UObject* object);

	/*
	* /brief Returns whether the given object is currently selected
	* /param object Object to check for selection
	*/
	UFUNCTION(BlueprintPure)
	bool IsSelected(UObject* object) const;

	/*
	* /brief Returns a list of selected objects matching the given subclass as pointers of the given template type
	* /param selectedClass Subclass to match the selected objects with
	*/
	template <class T>
	TSet<T*> GetSelectedByClass(TSubclassOf<UObject> selectedClass) const
	{
		TSet<T*> toReturn;

		for (TPair<UObject*, int64> selectedObject : SelectedObjects)
		{
			if (selectedObject.Key->GetClass()->IsChildOf(selectedClass))
			{
				// This is 99% safe since we ensure it's valid with the above IsChildOf() call.
				toReturn.Add((T*)selectedObject.Key);
			}
		}

		return toReturn;
	}

	/*
	* /brief Returns a list of selected objects matching the given subclass as UObject*
	* /param selectedClass Subclass to match the selected objects with
	*/
	UFUNCTION(BlueprintCallable)
	TSet<UObject*> GetSelectedByClass(TSubclassOf<UObject> selectedClass) const;

	/*
	* /brief Returns a set of all selected objects as UObject*
	*/
	UFUNCTION(BlueprintCallable)
	TSet<UObject*> GetSelected() const;

	/*
	* /brief Returns the last selected object, sorted by time of selection.
	*/
	UFUNCTION(BlueprintCallable)
	UObject* GetLastSelected();
};
