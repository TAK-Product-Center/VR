#pragma once

#include "Styling/SlateTypes.h"

#include "VH_UmgListEntry.h"

#include "Game_ListEntry_Contact.generated.h"

class UVH_COTEvent;

UCLASS(Blueprintable, BlueprintType)
class UGame_ListEntry_Contact : public UVH_UmgListEntry
{
    GENERATED_BODY()


	//----------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_ListEntry_Contact();


    //----------------------------------
    // --- Variables
    // ---------------------------------

private:
	UPROPERTY()
	UVH_COTEvent* COTEvent;


	//----------------------------------
	// --- API
	// ---------------------------------
	
public:
	UFUNCTION(BlueprintPure)
	UVH_COTEvent* GetCOTEvent() const;

	UFUNCTION(BlueprintPure)
	FName GetContactUID() const;

	void SetCOTEvent(UVH_COTEvent* cotEvent);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetCOTEvent(UVH_COTEvent* outCOTEvent);
};
