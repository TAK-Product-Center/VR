#pragma once

#include "Types/SlateEnums.h"
#include "Blueprint/UserWidget.h"
#include "VH_TextInput.generated.h"

/**
 * The TextInput allows the user to type text regardless of whether they are in VR
 * Behavior is similar to a TextBox
 */

/* To be called when text is submitted */
UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEntrySubmitted, FString, inString);

/* To be called when entry into textbox is cancelled */
UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEntryCancelled);

/* Called any time the text within the box is edited */
UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTextEdited, FString, inString);

UCLASS(Blueprintable, BlueprintType)
class VH_UI_API UVH_TextInput : public UUserWidget
{
	GENERATED_UCLASS_BODY()

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FOnEntrySubmitted OnEntrySubmittedCallback;

	UPROPERTY(BlueprintAssignable)
	FOnEntryCancelled OnEntryCancelledCallback;

	UPROPERTY(BlueprintAssignable)
	FOnTextEdited OnTextEditedCallback;

protected:
	/* Native reference to Editable Text Box */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category=Components)
	UEditableTextBox* TextBox;

	/* Native reference to Editable Text Box */
	UPROPERTY(BlueprintReadOnly, Category=Text)
	FText LastEntry;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/* Get the text currently in this TextInput */
	UFUNCTION(BlueprintCallable)
	FText GetText();

	UFUNCTION(BlueprintCallable)
	void SetText(FText inText, bool inSkipEvent);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	/* Sets a widget in the hirearchy as the textbox for this Text Input */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetTextBox(UEditableTextBox* inTextBox);

	/* Called when text is finished being entered into box */
	UFUNCTION(BlueprintCallable)
	void HandleTextBoxCommitted(ETextCommit::Type inCommitMethod, FText inCommittedText);

	/* Called when text within the text box is changed */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void HandleTextEdited(const FText& inCommittedText);
};