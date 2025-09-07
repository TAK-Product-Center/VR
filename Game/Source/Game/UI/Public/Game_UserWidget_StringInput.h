#pragma once

#include "Blueprint/UserWidget.h"
#include "Game_UserWidget_StringInput.generated.h"

/* Called whenever the input is changed */
UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStringEdited, FString, outString, bool, outValid);

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStringSubmitted, FString, outString);

/**
* A widget that takes string input from the user.
* The string (or strings) is verified and can be passed back to the owning menu when requested or on any edit
*/
UCLASS(Blueprintable, BlueprintType)
class UGame_UserWidget_StringInput : public UUserWidget
{
	GENERATED_UCLASS_BODY()

public:
// ---------------------------------
// --- Delegate
// ---------------------------------
	/*
	* Runs whenever the string is edited
	* Make sure to run input validation /filtering (if needed) before calling this delegate!
	*/
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnStringEdited OnStringEdited;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnStringSubmitted OnStringSubmitted;

	// ---------------------------------
	// --- Member variables
	// ---------------------------------

public:


protected:


	// ---------------------------------
	// --- Inherited Methods
	// ---------------------------------

public:

	// ---------------------------------
	// --- Methods
	// ---------------------------------

public:

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category=Output)
	void GetLatestString(FString& outString, bool& outIsValid);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category=Input)
	void SetNewString(const FString& inString);

protected:

	/* Submits the input string if/f it is valid */
	UFUNCTION(BlueprintCallable, Category=Output)
	void Submit();

	// ---------------------------------
	// --- Implementation
	// ---------------------------------

	// ---------------------------------
	// --- Blueprint Implemented
	// ---------------------------------

	/* Whether or not the user-entered text is valid for this string input */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category=Input)
	bool IsStringValid();

	/* Update the visuals on this widget, usually called within IsInputValid */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category=Visuals)
	void UpdateVisuals();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

};
