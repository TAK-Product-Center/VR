#pragma once

// Parent Includes
#include "Blueprint/UserWidget.h"

// Generated Includes
#include "Game_UserWidget_EditableLabeledSlider.generated.h"

class USlider;
class UVH_TextInput;
class UTextBlock;

UCLASS()
class GAME_API UGame_UserWidget_EditableLabeledSlider : public UUserWidget
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPostValueChanged, float, newValue);

	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FPostValueChanged PostValueChanged;
	
	UPROPERTY(BlueprintReadOnly, Category = "Sliders|Public", meta = (BindWidget))
	USlider* ValueSlider;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* ValueLabel;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UVH_TextInput* ValueEditableText;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* UnitLabel;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DefaultValue;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MinValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MaxValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float StepSize;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Label;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText Units;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString SettingName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int DecimalPlaces;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_UserWidget_EditableLabeledSlider(const FObjectInitializer& objectInitializer);

	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------

protected:
	virtual void NativeConstruct() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void SetValue(float newValue, bool saveToDB = true);

private:
	UFUNCTION(BlueprintCallable)
	void SaveValue();

	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	void BindDelegates();

	void InitWidgetsFromDatabase();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION(BlueprintCallable, Category = "Events|Protected")
	void HandleSliderValueChanged(float value);

	UFUNCTION(BlueprintCallable, Category = "Events|Protected")
	void HandleSliderEndCapture();

	UFUNCTION(BlueprintCallable, Category = "Events|Protected")
	void HandleResetValueClicked(UUserWidget* button);
	
	UFUNCTION()
	void HandleValueTextEdited(FString inString);
};
