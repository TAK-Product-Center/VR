#pragma once

// Parent Includes
#include "Keyboard_Container.h"

// Generated Includes
#include "Game_Keyboard_Container.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_Keyboard_Container : public AKeyboard_Container
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Keyboard_Container(const FObjectInitializer& objectInitializer);

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void StartDrag();

	UFUNCTION(BlueprintCallable)
	void EndDrag();
};