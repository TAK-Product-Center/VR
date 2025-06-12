#pragma once

// Parent Includes
#include "UObject/Object.h"

// Generated Include
#include "VH_ListEntryData.generated.h"


/**
* Base class for object that holds data for a list entry.  List entry data is meant to be a data only class and agnostic to visualization of the data.
*	See VH_UmgWidget_List.h for more information on implementation
*/
UCLASS(Blueprintable, BlueprintType,HideCategories=("VH List Entry"))
class VH_UI_API UVH_ListEntryData : public UObject
{
    GENERATED_UCLASS_BODY()


    // ---------------------------------
    // --- Variables
    // ---------------------------------

public:

	/** Hover text to show for this data */
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Defaults", meta = (ExposeOnSpawn))
    FText HoverText;


    // ---------------------------------
    // --- API
    // ---------------------------------

public:

    UFUNCTION(BlueprintCallable, Category = "VH List Entry")
    virtual FText GetHoverText() const { return HoverText; }

	/**
	 * @brief Handler for when data has been assigned or updated
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "VH List Entry")
	void OnDataUpdated();
};

