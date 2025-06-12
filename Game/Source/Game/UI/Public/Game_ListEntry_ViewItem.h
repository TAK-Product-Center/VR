#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_ListEntry_ViewItem.generated.h"

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_ListEntry_ViewItem : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_ListEntry_ViewItem(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	FString GetName(const FString& entityUID) const;
};