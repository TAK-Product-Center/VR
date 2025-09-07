#include "Game_UserWidget_EditableLabeledSlider.h"

// Engine Includes
#include "Components/Slider.h"
#include "Components/TextBlock.h"
#include "Components/EditableText.h"

// VH Plugin Includes
#include "Developer_PersistentSettings.h"

// Game Includes
#include "Game_UserWidget_TextInput.h"
#include "Database_PersistentSettings_Spatialite.h"
#include "Game_Subsystem_Core.h"
#include "Keyboard_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_EditableLabeledSlider::UGame_UserWidget_EditableLabeledSlider(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	DefaultValue(60.f),
	MinValue(0.f),
	MaxValue(250.f),
	StepSize(1.f)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_UserWidget_EditableLabeledSlider::NativeConstruct()
{
	Super::NativeConstruct();

	InitWidgetsFromDatabase();

	BindDelegates();
}

void UGame_UserWidget_EditableLabeledSlider::SetValue(float newValue, bool saveToDB)
{
	ValueSlider->SetValue(newValue);
	ValueSlider->SetMinValue(MinValue);
	ValueSlider->SetMaxValue(MaxValue);
	ValueSlider->SetStepSize(StepSize);

	if (IsValid(ValueEditableText))
	{
		FNumberFormattingOptions numberFormatOptions = FNumberFormattingOptions();
		numberFormatOptions.MaximumFractionalDigits = DecimalPlaces;
			
		ValueEditableText->GetEditableText()->SetText(FText::AsNumber(newValue, &numberFormatOptions));
	}

	if(saveToDB)
	{
		SaveValue();
	}
}

void UGame_UserWidget_EditableLabeledSlider::SaveValue()
{
	if(!SettingName.IsEmpty())
	{
		if (UDatabase_PersistentSettings_Spatialite* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			gameSettings->StoreSettingDouble(SettingName, ValueSlider->GetValue());
		}
	}
	
	PostValueChanged.Broadcast(ValueSlider->GetValue());
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_UserWidget_EditableLabeledSlider::BindDelegates()
{
	ValueSlider->OnControllerCaptureEnd.AddUniqueDynamic(this, &UGame_UserWidget_EditableLabeledSlider::HandleSliderEndCapture);
	ValueSlider->OnMouseCaptureEnd.AddUniqueDynamic(this, &UGame_UserWidget_EditableLabeledSlider::HandleSliderEndCapture);
	ValueSlider->OnValueChanged.AddUniqueDynamic(this, &UGame_UserWidget_EditableLabeledSlider::HandleSliderValueChanged);

	if (IsValid(ValueEditableText))
	{
		ValueEditableText->GetEditableText()->OnTextCommitted.AddUniqueDynamic(this, &UGame_UserWidget_EditableLabeledSlider::HandleValueTextEdited);
	}
}

void UGame_UserWidget_EditableLabeledSlider::InitWidgetsFromDatabase()
{
	if (UDatabase_PersistentSettings_Spatialite* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		if (!SettingName.IsEmpty())
		{
			SetValue(gameSettings->GetSettingDouble(SettingName));
		}
		else
		{
			SetValue(DefaultValue);
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_UserWidget_EditableLabeledSlider::HandleSliderValueChanged(float value)
{
	SetValue(value, false);
}

void UGame_UserWidget_EditableLabeledSlider::HandleSliderEndCapture()
{
	SaveValue();
}

void UGame_UserWidget_EditableLabeledSlider::HandleResetValueClicked(UUserWidget* button)
{
	SetValue(DefaultValue);
}

void UGame_UserWidget_EditableLabeledSlider::HandleValueTextEdited(const FText& text, ETextCommit::Type commitMethod)
{
	if (UKeyboard_Subsystem_Core* keyboardSubsystem = UKeyboard_Subsystem_Core::Get())
	{
		if (keyboardSubsystem->IsKeyboardOpen())
		{
			// VR keyboard causes text field to gain, then immediately lose focus on each keypress, resulting in false positives here
			// instead wait until user closes keyboard, then perform this check
			//TODO - One day, by someone. Figure out why only in VR (not VR emulation) this focus is an issue
			return;
		}
	}

	FString inString = text.ToString();

	inString = inString.Replace(TEXT(","), TEXT(""));
	if (inString.IsNumeric())
	{
		float newValue = FCString::Atof(*inString);
		newValue = FMath::Clamp(newValue, MinValue, MaxValue);
		
		if (newValue != ValueSlider->GetValue())
		{
			SetValue(newValue);
		}
	}
	else
	{
		SetValue(ValueSlider->GetValue(), false);
	}
}