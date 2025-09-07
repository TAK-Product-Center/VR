#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Engine Includes
#include "Misc/DateTime.h"

// Generated Includes
#include "Game_UserWidget_DatePicker.generated.h"

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_DatePicker : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_DatePicker(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void PopulateDays(const FDateTime& selectedDate);

	UFUNCTION(BlueprintCallable)
	void SetToPreviousMonth(UPARAM(ref) FDateTime& date);

	UFUNCTION(BlueprintCallable)
	void SetToNextMonth(UPARAM(ref) FDateTime& date);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveDay(int32 column, int32 row, const FDateTime& dateTime);
};