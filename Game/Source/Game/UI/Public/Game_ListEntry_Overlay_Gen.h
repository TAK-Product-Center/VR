// Developed by Virtual Heroes, 2019-2020

#pragma once

// Game Layer includes
#include "Game_ListEntry_Overlay_Base.h"

// Generated include
#include "Game_ListEntry_Overlay_Gen.generated.h"

// Forward declarations
class UButton;
class UCheckBox;
class UImage;
class UTextBlock;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_ListEntry_Overlay_Gen : public UGame_ListEntry_Overlay_Base
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Member
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
	UTextBlock* TextBearing;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextCallsign;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextDistance;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextHAE;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TextMGRS;

	// ---------------------------------
	// --- Inherited Methods
	// ---------------------------------

public:

	virtual void NativeConstruct() override;

	/////// Native Events ///////

	virtual void HandleInsertOrUpdate_Native(const FSpatialiteResult_BP& dbResult) override;

	virtual void SetSelectionCheckboxValue_Native(bool bIsChecked) override;

	virtual void ShowSelectionCheckbox_Native(bool bShouldShow) override;

	virtual void UpdateUI_Native(const TMap<FString, FString>& overlayInfo) override;

	// ---------------------------------
	// --- Public Methods
	// ---------------------------------

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Functions|Public")
	UTexture2D* GetIconTexture() const;

	/////// Native Events ///////

	virtual UTexture2D* GetIconTexture_Native() const;

public:

	// ---------------------------------
	// --- Implementation Methods
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