#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_Popup.generated.h"

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_Popup : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnButtonPressed, UGame_UserWidget_Popup*, popupWigdet, const FString&, popupButton);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FOnButtonPressed OnButtonPressed;

private:
	bool bModal;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_Popup(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	static UGame_UserWidget_Popup* OpenPopup(TSubclassOf<UGame_UserWidget_Popup> popupClass, const FString& header, const FString& body, const TArray<FString> buttons, bool bModal = true);

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void SetModal(bool bModalArg);

	UFUNCTION(BlueprintCallable)
	void ButtonClicked(const FString& buttonText);

	UFUNCTION(BlueprintCallable)
	void SetHeader(const FString& text);

	UFUNCTION(BlueprintCallable)
	void SetBody(const FString& text);

	UFUNCTION(BlueprintCallable)
	void SetButtons(const TArray<FString>& buttons);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetHeader(const FString& text);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetBody(const FString& text);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetButtons(const TArray<FString>& buttons);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void CleanupModal();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleUserWidgetClosed(UUserWidget* userWidget);
};