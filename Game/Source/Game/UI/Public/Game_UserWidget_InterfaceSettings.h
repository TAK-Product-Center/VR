#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// VH Includes
#include "VH_TextInput.h"

// Generated Includes
#include "Game_UserWidget_InterfaceSettings.generated.h"

// Forward declarations
class USlider;
class UCheckBox;
class UGame_UserWidget_Popup;
class UComboBoxString;

UCLASS()
class GAME_API UGame_UserWidget_InterfaceSettings : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UCheckBox* CenterOnBeamCheckBox;
		
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UCheckBox* SnapToModelsCheckbox;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UCheckBox* InvertThumbstickCheckBox;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UCheckBox* XRayIconsCheckBox;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	USlider* IconScaleSlider;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	USlider* LineEditPointScaleSlider;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	USlider* MoveSpeedSlider;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UComboBoxString* ComboBoxKeyboard;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	USlider* ApplicationScaleSlider;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UVH_TextInput* ApplicationScaleEditableText;
	
	UPROPERTY(BlueprintReadWrite)
	UUserWidget* ParentMenu;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGame_UserWidget_Popup> PopupClass;

protected:
	TMap<float, UCheckBox*> MenuSizeScales;

	float CachedIconScalePct;

	float CachedLineEditPointScalePct;

	float CachedObjectViewDistancePct;

	float DefaultIconScale;

	float MinIconScale;

	float MaxIconScale;

	float DefaultLineScale;

	float MinLineScale;

	float MaxLineScale;

	float ApplicationScale;

	float MinApplicationScale;

	float MaxApplicationScale;

	FTimerHandle TimerHandleConfirmApplicationScale;

	float PreviousApplicationScale;

	UPROPERTY()
	UGame_UserWidget_Popup* PopupApplicationScale;

	bool bOpenPopup;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_InterfaceSettings(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

protected:
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& myGeometry, float deltaSeconds) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void OpenPopup();

	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	void BindDelegates();

	void ResetSnapToModels();

	void ResetInvertThumbstick();

	void ResetXRayIcons();

	void ResetCenterOnBeam();

	void ResetApplicationScale();

	void ResetMovementSpeed();

	void ResetKeyboard();

	void InitWidgetsFromDatabase();
	
	void SetIconScaling(float value);
	
	void SetLineEditPointScale(float value);

	void SetApplicationScale(float value);

	void RestorePreviousApplicationScale();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION(BlueprintCallable)
	void HandleCenterOnBeamCheckStateChange(bool bIsChecked);

	UFUNCTION(BlueprintCallable)
	void HandleSnapToModelsCheckStateChange(bool bIsChecked);

	UFUNCTION(BlueprintCallable)
	void HandleInvertThumbstickCheckStateChange(bool bIsChecked);

	UFUNCTION(BlueprintCallable)
	void HandleXRayCheckStateChange(bool bIsChecked);

	UFUNCTION(BlueprintCallable)
	void HandleIconScaleSliderValueChanged(float value);

	UFUNCTION(BlueprintCallable)
	void HandleLineEditPointScaleSliderValueChanged(float value);

	UFUNCTION(BlueprintCallable)
	void HandleMoveSpeedSliderEndCapture();

	UFUNCTION(BlueprintCallable)
	void HandleComboBoxKeyboardSelectionChanged(FString selected, ESelectInfo::Type selectedType);

	UFUNCTION(BlueprintCallable)
	void HandleResetIconScaleClick();

	UFUNCTION(BlueprintCallable)
	void HandleResetLineScaleClick();

	UFUNCTION(BlueprintCallable)
	void HandleResetAll();

	UFUNCTION(BlueprintCallable)
	void HandleIconViewSliderEndCapture();

	UFUNCTION(BlueprintCallable)
	void HandleLineEditPointSliderEndCapture();

	UFUNCTION()
	void HandleApplicationScaleSliderValueEndCapture();

	UFUNCTION()
	void HandleApplicationScaleSliderValueChanged(float value);

	UFUNCTION()
	void HandleConfirmApplicationScale(UGame_UserWidget_Popup* popup, const FString& button);

	UFUNCTION()
	void HandleApplicationScaleTextEdited(FString inString);

	UFUNCTION()
	void HandleKeyboardSpawnDestroyed(bool bSpawn, AActor* keyboardContainer);
};