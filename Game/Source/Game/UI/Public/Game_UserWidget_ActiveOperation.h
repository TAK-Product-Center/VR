#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_ActiveOperation.generated.h"

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_ActiveOperation : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_ActiveOperation(const FObjectInitializer& objectInitializer);
};