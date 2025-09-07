#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_TextInput.generated.h"

class UEditableText;

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_TextInput : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_TextInput(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	UEditableText* GetEditableText() const;
};