#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_Operations.generated.h"

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_Operations : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_Operations(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure)
	bool GetStartTime(const FDateTime& date, const FString& time, FDateTime& startTime) const;
};