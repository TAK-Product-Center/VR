#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_HUD_Desktop.generated.h"

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_HUD_Desktop : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_HUD_Desktop(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetCursorColor(const FLinearColor& color);
};