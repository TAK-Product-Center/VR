#pragma once

// Parent Includes
#include "UObject/Interface.h"

// Generated Includes
#include "Interface_DetailSection.generated.h"

// Forward declarations
class UVH_COTEvent;


/**
 *	This is interface is for the detail sections for detail menus
 */
UINTERFACE()
class GAME_API UInterface_DetailSection : public UInterface
{
    GENERATED_BODY()
};

class GAME_API IInterface_DetailSection
{
    GENERATED_BODY()


	// ---------------------------------
	// --- API
	// ---------------------------------
public:
    
	/*
	* @brief	This function sets the COT Event for the particular detail section.
	* 
	* @param	cotEvent - This is the COT Event that the detail section is supposed to handle.
	* @return	returns true if the COT Event was properly set to the class, returns false if not properly set.
	*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interface Detail Section")
	bool SetCOTEvent(UVH_COTEvent* cotEvent);

};
