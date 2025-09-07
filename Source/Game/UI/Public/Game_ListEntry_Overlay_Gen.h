#pragma once

// Parent Includes
#include "Game_ListEntry_Overlay_Base.h"

// Generated includes
#include "Game_ListEntry_Overlay_Gen.generated.h"

class UButton;
class UCheckBox;
class UImage;
class UTextBlock;

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_ListEntry_Overlay_Gen : public UGame_ListEntry_Overlay_Base
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* BtnVisible;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UCheckBox* SelectionCheckbox;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UImage* ImgCategory;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UImage* ImgVisible;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextCallsign;

	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void NativeConstruct() override;

	/////// Native Events ///////

	virtual void HandleInsertOrUpdate_Native(const FSpatialiteResult_BP& dbResult) override;

	virtual void SetSelectionCheckboxValue_Native(bool bIsChecked) override;

	virtual void ShowSelectionCheckbox_Native(bool bShouldShow) override;

	virtual void UpdateUI_Native(const TMap<FString, FString>& overlayInfo) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Functions|Public")
	UTexture2D* GetIconTexture() const;

	virtual UTexture2D* GetIconTexture_Native() const;

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetCoordinate(const FString& coordinateString);

	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	void UpdateUIVisibility();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION(BlueprintCallable, Category = "Event Handlers|Public")
	void HandleCheckboxStateChanged(bool bIsChecked);

	UFUNCTION(BlueprintCallable, Category = "Event Handlers|Public")
	void HandleVisibilityToggleClicked();
};