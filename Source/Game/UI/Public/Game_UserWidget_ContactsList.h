#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
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

class UVH_COTEvent;

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
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	TArray<UVH_COTEvent*> GetSortedContacts(EContactSortingMethod sortingMethod);
};
