#pragma once

// Parent Includes
#include "Game_UserWidget_TextInput.h"

// Generated Includes
#include "Game_UserWidget_TextInput_DragSelect.generated.h"

class UEditableText;

/* Allows user to drag select text when owing user widget is in a widgetComponent and player is accessing via
*  widgetInteractionComponent.  Be careful using this, as it breaks many focus loss interactions (tab, click off, etc).
*/
UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_TextInput_DragSelect : public UGame_UserWidget_TextInput
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	FTimerHandle TextSelectionTimerHandle;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_TextInput_DragSelect(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void NativeOnRemovedFromFocusPath(const FFocusEvent& inFocusEvent) override;

	
	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleFocusLostDueToTextSelection();
};