// Parent Includes
#include "Game_UserWidget_RibbonButton.h"

// Generated Includes
#include "Game_UserWidget_RibbonButton_ConfirmPopup.generated.h"

class UGame_UserWidget_Popup;

UCLASS(BlueprintType, Blueprintable)
class GAME_API UGame_UserWidget_RibbonButton_ConfirmPopup : public UGame_UserWidget_RibbonButton
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_DELEGATE_TwoParams(FPopupClicked, UGame_UserWidget_Popup*, popupWidget, const FString&, buttonText);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FPopupClicked HandlePopupClicked;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FString PopupHeader;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	FString PopupBody;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	TArray<FString> PopupButtons;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn = true))
	TSubclassOf<UGame_UserWidget_Popup> PopupClass;

private:
	bool WasRibbonVisible;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_RibbonButton_ConfirmPopup(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

protected:
	virtual void PostClicked() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void SetPopupData(const FString& header, const FString& body, const TArray<FString>& buttons, const FPopupClicked& clickHandler);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	UFUNCTION()
	void ResetRibbonVisibility(UGame_UserWidget_Popup* popupWidget, const FString& buttonText);
};
