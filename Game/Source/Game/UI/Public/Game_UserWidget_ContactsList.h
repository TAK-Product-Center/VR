#pragma once

#include "Blueprint/UserWidget.h"

#include "VH_COTManager.h"
#include "VH_UmgListEntry.h"
#include "VH_UmgWidget_List.h"

#include "Game_ListEntry_Contact.h"
#include "Game_UserWidget_ContactsList.generated.h"

// ---------------------------------
// --- Enumerators
// ---------------------------------

UENUM(BlueprintType)
enum class EContactSortingMethod : uint8
{
	Unknown,
	Callsign,
	Proximity,
	UnreadMessage,
	OnlinePresence
};

/**
 *  This menu holds some native code for the contact menu list.
 */
UCLASS()
class GAME_API UGame_UserWidget_ContactsList : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_ContactsList(const FObjectInitializer& objectInitializer);

	
	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPopulateCustomEntries);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FOnPopulateCustomEntries OnPopulateCustomEntries;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EContactSortingMethod SortingMethod;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UVH_UmgWidget_List* ContactList;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGame_ListEntry_Contact> ListEntryClass;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void PopulateContacts();

	UFUNCTION(BlueprintCallable)
	void SetSortingMethod(EContactSortingMethod inSortingMethod);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	TArray<UVH_COTEvent*> GetSortedContacts();
};
