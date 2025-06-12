// Required Includes
#include "Game_UserWidget_InterfaceSettings.h"
#include "Game.h"

// Engine Includes
#include "Engine.h"
#include "Components/Button.h"
#include "Components/CheckBox.h"
#include "Components/Slider.h"
#include "Components/TextBlock.h"
#include "Components/ComboBoxString.h"
#include "Engine/UserInterfaceSettings.h"

// VH Plugin Includes
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"
#include "UI_Subsystem_Core.h"
#include "Keyboard_Subsystem_Core.h"

// Game Includes
#include "Game_EditPoint.h"
#include "Game_Pawn.h"
#include "Game_Point_Icon.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_Statics.h"
#include "Game_PlayerController.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_Subsystem_Core.h"
#include "Game_CameraScalingComponent.h"
#include "Game_UserWidget_Popup.h"
#include "Game_MovementComponent.h"
#include "Game_WorldInteractableActor.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_InterfaceSettings::UGame_UserWidget_InterfaceSettings(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	DefaultIconScale(.7f),
	MinIconScale(0.4f),
	MaxIconScale(1.f),
	DefaultLineScale(1.f),
	MinLineScale(0.5f),
	MaxLineScale(1.5f),
	ApplicationScale(1.0),
	MinApplicationScale(0.25),
	MaxApplicationScale(3)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_UserWidget_InterfaceSettings::NativeConstruct()
{
	Super::NativeConstruct();

	BindDelegates();

	InitWidgetsFromDatabase();
}

void UGame_UserWidget_InterfaceSettings::NativeTick(const FGeometry& myGeometry, float deltaSeconds)
{
	Super::NativeTick(myGeometry, deltaSeconds);

	// handles multiple callbacks triggering popup in same tick
	if (bOpenPopup)
	{
		OpenPopup();

		bOpenPopup = false;
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_InterfaceSettings::OpenPopup()
{
	// close old popup if still open
	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		subsystem->CloseUserWidget(PopupApplicationScale);

		PopupApplicationScale = nullptr;
	}

	// create confirmation popup;
	TArray<FString> buttons;
	buttons.Add(TEXT("No"));
	buttons.Add(TEXT("Yes"));

	PopupApplicationScale = UGame_UserWidget_Popup::OpenPopup(PopupClass, TEXT("Settings Confirmation"), TEXT("Would you like to keep this UI scale?  The UI scale will reset after 15 seconds."), buttons, true);
	PopupApplicationScale->OnButtonPressed.AddDynamic(this, &UGame_UserWidget_InterfaceSettings::HandleConfirmApplicationScale);
	
	GetWorld()->GetTimerManager().SetTimer(TimerHandleConfirmApplicationScale, this, &UGame_UserWidget_InterfaceSettings::RestorePreviousApplicationScale, 15, false);
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_UserWidget_InterfaceSettings::BindDelegates()
{
	if (IsValid(CenterOnBeamCheckBox))
	{
		CenterOnBeamCheckBox->OnCheckStateChanged.AddUniqueDynamic(this, &UGame_UserWidget_InterfaceSettings::HandleCenterOnBeamCheckStateChange);
	}

	if (IsValid(SnapToModelsCheckbox))
	{
		SnapToModelsCheckbox->OnCheckStateChanged.AddUniqueDynamic(this, &UGame_UserWidget_InterfaceSettings::HandleSnapToModelsCheckStateChange);
	}

	if (IsValid(InvertThumbstickCheckBox))
	{
		InvertThumbstickCheckBox->OnCheckStateChanged.AddUniqueDynamic(this, &UGame_UserWidget_InterfaceSettings::HandleInvertThumbstickCheckStateChange);
	}

	if (IsValid(XRayIconsCheckBox))
	{
		XRayIconsCheckBox->OnCheckStateChanged.AddUniqueDynamic(this, &UGame_UserWidget_InterfaceSettings::HandleXRayCheckStateChange);
	}

	if (IsValid(IconScaleSlider))
	{
		IconScaleSlider->OnMouseCaptureEnd.AddUniqueDynamic(this, &UGame_UserWidget_InterfaceSettings::HandleIconViewSliderEndCapture);
		IconScaleSlider->OnValueChanged.AddUniqueDynamic(this, &UGame_UserWidget_InterfaceSettings::HandleIconScaleSliderValueChanged);
	}

	if (IsValid(LineEditPointScaleSlider))
	{
		LineEditPointScaleSlider->OnMouseCaptureEnd.AddUniqueDynamic(this, &UGame_UserWidget_InterfaceSettings::HandleLineEditPointSliderEndCapture);
		LineEditPointScaleSlider->OnValueChanged.AddUniqueDynamic(this, &UGame_UserWidget_InterfaceSettings::HandleLineEditPointScaleSliderValueChanged);
	}

	if (IsValid(MoveSpeedSlider))
	{
		MoveSpeedSlider->OnMouseCaptureEnd.AddUniqueDynamic(this, &UGame_UserWidget_InterfaceSettings::HandleMoveSpeedSliderEndCapture);
	}

	if (IsValid(ComboBoxKeyboard))
	{ 
		ComboBoxKeyboard->OnSelectionChanged.AddUniqueDynamic(this, &UGame_UserWidget_InterfaceSettings::HandleComboBoxKeyboardSelectionChanged);
	}

	if (IsValid(ApplicationScaleSlider))
	{
		ApplicationScaleSlider->OnMouseCaptureEnd.AddUniqueDynamic(this, &UGame_UserWidget_InterfaceSettings::HandleApplicationScaleSliderValueEndCapture);
		ApplicationScaleSlider->OnValueChanged.AddUniqueDynamic(this, &UGame_UserWidget_InterfaceSettings::HandleApplicationScaleSliderValueChanged);
	}

	if (IsValid(ApplicationScaleEditableText))
	{
		ApplicationScaleEditableText->OnEntrySubmittedCallback.AddUniqueDynamic(this, &UGame_UserWidget_InterfaceSettings::HandleApplicationScaleTextEdited);
	}

	if (UKeyboard_Subsystem_Core* subsystem = UKeyboard_Subsystem_Core::Get())
	{
		subsystem->OnKeyboardSpawnDestroy.AddUniqueDynamic(this, &UGame_UserWidget_InterfaceSettings::HandleKeyboardSpawnDestroyed);
	}
}

void UGame_UserWidget_InterfaceSettings::ResetSnapToModels()
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		bool bIsChecked = gameSettings->GetDefaultSettingBool("SnapToModels");
		gameSettings->StoreSettingBool(TEXT("SnapToModels"), bIsChecked);

		SnapToModelsCheckbox->SetCheckedState(bIsChecked ? ECheckBoxState::Checked : ECheckBoxState::Unchecked);
	}
}

void UGame_UserWidget_InterfaceSettings::ResetInvertThumbstick()
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		bool bIsChecked = gameSettings->GetDefaultSettingBool("InvertLook");
		gameSettings->StoreSettingBool(TEXT("InvertLook"), bIsChecked);

		InvertThumbstickCheckBox->SetCheckedState(bIsChecked ? ECheckBoxState::Checked : ECheckBoxState::Unchecked);
	}
}

void UGame_UserWidget_InterfaceSettings::ResetXRayIcons()
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		bool bIsChecked = gameSettings->GetDefaultSettingBool("XRayIcons");
		gameSettings->StoreSettingBool(TEXT("XRayIcons"), bIsChecked);

		XRayIconsCheckBox->SetCheckedState(bIsChecked ? ECheckBoxState::Checked : ECheckBoxState::Unchecked);
	}
}

void UGame_UserWidget_InterfaceSettings::ResetCenterOnBeam()
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		bool bIsChecked = gameSettings->GetDefaultSettingBool("CenterAllPlaceables");
		gameSettings->StoreSettingBool(TEXT("CenterAllPlaceables"), bIsChecked);

		CenterOnBeamCheckBox->SetCheckedState(bIsChecked ? ECheckBoxState::Checked : ECheckBoxState::Unchecked);
	}
}

void UGame_UserWidget_InterfaceSettings::ResetApplicationScale()
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		float applicationScaleDefault = gameSettings->GetDefaultSettingDouble("ApplicationScale");
		
		float sliderValue = FMath::GetRangePct(MinApplicationScale, MaxApplicationScale, applicationScaleDefault);
		ApplicationScaleSlider->SetValue(sliderValue);

		ApplicationScaleEditableText->SetText(FText::FromString(FString::Printf(TEXT("%f"), applicationScaleDefault)), false);

		SetApplicationScale(applicationScaleDefault);
	}
}

void UGame_UserWidget_InterfaceSettings::ResetMovementSpeed()
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		double defaultMovementSpeed = gameSettings->GetDefaultSettingDouble(TEXT("MovementSpeed"));
		gameSettings->StoreSettingDouble(TEXT("MovementSpeed"), defaultMovementSpeed);

		MoveSpeedSlider->SetValue(defaultMovementSpeed);
	}
}

void UGame_UserWidget_InterfaceSettings::ResetKeyboard()
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		FString defaultKeyboard = gameSettings->GetDefaultSettingString(TEXT("Keyboard"));
		gameSettings->StoreSettingString(TEXT("Keyboard"), defaultKeyboard);

		ComboBoxKeyboard->SetSelectedOption(defaultKeyboard);
		UKeyboard_Subsystem_Core::Get()->DefaultKeyboardClass = UKeyboard_Subsystem_Core::Get()->KeyboardClassMap[defaultKeyboard];
	}
}

void UGame_UserWidget_InterfaceSettings::InitWidgetsFromDatabase()
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		if (IsValid(CenterOnBeamCheckBox))
		{
			bool bCenterAllPlaceables = gameSettings->GetSettingBool(TEXT("CenterAllPlaceables"));

			CenterOnBeamCheckBox->SetIsChecked(bCenterAllPlaceables);
		}

		if (IsValid(SnapToModelsCheckbox))
		{
			bool bInvertLook = gameSettings->GetSettingBool(TEXT("SnapToModels"));

			SnapToModelsCheckbox->SetIsChecked(bInvertLook);
		}

		if (IsValid(InvertThumbstickCheckBox))
		{
			bool bInvertLook = gameSettings->GetSettingBool(TEXT("InvertLook"));

			InvertThumbstickCheckBox->SetIsChecked(bInvertLook);
		}

		if (IsValid(XRayIconsCheckBox))
		{
			bool bXRayIcons = gameSettings->GetSettingBool(TEXT("XRayIcons"));

			XRayIconsCheckBox->SetIsChecked(bXRayIcons);
		}

		if (IsValid(IconScaleSlider))
		{
			float iconScale = gameSettings->GetSettingDouble(TEXT("IconScale"));
			float iconScalePct = FMath::GetRangePct(MinIconScale, MaxIconScale, iconScale);
			CachedIconScalePct = iconScalePct;

			IconScaleSlider->SetValue(iconScalePct);
		}

		if (IsValid(LineEditPointScaleSlider))
		{
			float lineScale = gameSettings->GetSettingDouble(TEXT("LineScale"));
			float lineScalePct = FMath::GetRangePct(MinLineScale, MaxLineScale, lineScale);
			CachedLineEditPointScalePct = lineScalePct;

			LineEditPointScaleSlider->SetValue(lineScalePct);
		}

		if (IsValid(MoveSpeedSlider))
		{
			if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
			{
				MoveSpeedSlider->SetMaxValue(playerPawn->VRMovement->MaxSettingsMovementMultiplier);
			}

			MoveSpeedSlider->SetValue(gameSettings->GetSettingDouble(TEXT("MovementSpeed")));
		}

		if (IsValid(ComboBoxKeyboard))
		{
			ComboBoxKeyboard->ClearOptions();

			for (const TPair<FString, TSubclassOf<AActor>>& pair : UKeyboard_Subsystem_Core::Get()->KeyboardClassMap)
			{
				ComboBoxKeyboard->AddOption(pair.Key);
			}
			
			FString keyboardSetting = gameSettings->GetSettingString(TEXT("Keyboard"));
			if (ComboBoxKeyboard->FindOptionIndex(keyboardSetting) != -1)
			{
				ComboBoxKeyboard->SetSelectedOption(keyboardSetting);
				if (UKeyboard_Subsystem_Core::Get()->KeyboardClassMap.Contains(keyboardSetting))
				{
					UKeyboard_Subsystem_Core::Get()->DefaultKeyboardClass = UKeyboard_Subsystem_Core::Get()->KeyboardClassMap[keyboardSetting];
				}
			}
			else
			{
				FString defaultKeyboard = gameSettings->GetDefaultSettingString(TEXT("Keyboard"));
				ComboBoxKeyboard->SetSelectedOption(defaultKeyboard);
				if (UKeyboard_Subsystem_Core::Get()->KeyboardClassMap.Contains(defaultKeyboard))
				{
					UKeyboard_Subsystem_Core::Get()->DefaultKeyboardClass = UKeyboard_Subsystem_Core::Get()->KeyboardClassMap[defaultKeyboard];
				}
			}
		}

		if (IsValid(ApplicationScaleSlider) && IsValid(ApplicationScaleEditableText))
		{
			float applicationScale = gameSettings->GetSettingDouble("ApplicationScale");

			float sliderValue = FMath::GetRangePct(MinApplicationScale, MaxApplicationScale, applicationScale);
			ApplicationScaleSlider->SetValue(sliderValue);

			ApplicationScaleEditableText->SetText(FText::FromString(FString::Printf(TEXT("%f"), applicationScale)), false);
		}
	}
}

void UGame_UserWidget_InterfaceSettings::SetIconScaling(float iconScaling)
{
	
}

void UGame_UserWidget_InterfaceSettings::SetLineEditPointScale(float lineEditPointScaling)
{
	
}

void UGame_UserWidget_InterfaceSettings::SetApplicationScale(float value)
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingDouble(TEXT("ApplicationScale"), value);
	}

	if (UUserInterfaceSettings* userInterfaceSettings = GetMutableDefault<UUserInterfaceSettings>(UUserInterfaceSettings::StaticClass()))
	{
		userInterfaceSettings->ApplicationScale = value;

		if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
		{
			subsystem->SyncUserWidgetsToApplicationScale();
		}
	}
}

void UGame_UserWidget_InterfaceSettings::RestorePreviousApplicationScale()
{
	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		subsystem->CloseUserWidget(PopupApplicationScale);
	}

	// restore PreviousApplicationScale after 15 seconds
	float sliderValue = FMath::GetRangePct(MinApplicationScale, MaxApplicationScale, PreviousApplicationScale);
	ApplicationScaleSlider->SetValue(sliderValue);

	ApplicationScaleEditableText->SetText(FText::FromString(FString::Printf(TEXT("%f"), PreviousApplicationScale)), false);
	
	SetApplicationScale(PreviousApplicationScale);
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_UserWidget_InterfaceSettings::HandleCenterOnBeamCheckStateChange(bool bIsChecked)
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingBool(TEXT("CenterAllPlaceables"), bIsChecked);

		for (TActorIterator<AGame_WorldInteractableActor> iterator(GetWorld()); iterator; ++iterator)
		{
			if (AGame_WorldInteractableActor* worldActor = *iterator)
			{
				worldActor->bCenterOnTraceBeam = bIsChecked;
			}
		}
	}
}

void UGame_UserWidget_InterfaceSettings::HandleSnapToModelsCheckStateChange(bool bIsChecked)
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingBool(TEXT("SnapToModels"), bIsChecked);
	}
}

void UGame_UserWidget_InterfaceSettings::HandleInvertThumbstickCheckStateChange(bool bIsChecked)
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingBool(TEXT("InvertLook"), bIsChecked);
	}

	UInputSettings* inputSettings = UInputSettings::StaticClass()->GetDefaultObject<UInputSettings>();
	if (IsValid(inputSettings))
	{
		inputSettings->RemoveAxisMapping(FInputAxisKeyMapping(TEXT("LookUp"), EKeys::Gamepad_RightY, bIsChecked ? 1.f : -1.f), false);
		inputSettings->AddAxisMapping(FInputAxisKeyMapping(TEXT("LookUp"), EKeys::Gamepad_RightY, bIsChecked ? -1.f : 1.f), true);
	}
}

void UGame_UserWidget_InterfaceSettings::HandleXRayCheckStateChange(bool bIsChecked)
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingBool(TEXT("XRayIcons"), bIsChecked);

		for (TActorIterator<AGame_Point_Icon> pointIcon(GetWorld()); pointIcon; ++pointIcon)
		{
			AGame_Point_Icon* currentPoint = *pointIcon;
			if (IsValid(currentPoint))
			{
				currentPoint->bIsXRay = bIsChecked;
			}
		}
	}
}

void UGame_UserWidget_InterfaceSettings::HandleIconScaleSliderValueChanged(float value)
{
	CachedIconScalePct = value;
	float iconScale = FMath::Lerp(MinIconScale, MaxIconScale, value);
	SetIconScaling(iconScale);
}

void UGame_UserWidget_InterfaceSettings::HandleLineEditPointScaleSliderValueChanged(float value)
{
	CachedLineEditPointScalePct = value;
	float lineEditPointScale = FMath::Lerp(MinLineScale, MaxLineScale, value);

	SetLineEditPointScale(lineEditPointScale);
}

void UGame_UserWidget_InterfaceSettings::HandleMoveSpeedSliderEndCapture()
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingDouble(TEXT("MovementSpeed"), MoveSpeedSlider->GetValue());
	}
}

void UGame_UserWidget_InterfaceSettings::HandleComboBoxKeyboardSelectionChanged(FString selected, ESelectInfo::Type selectedType)
{
	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{

		if (UKeyboard_Subsystem_Core::Get()->KeyboardClassMap.Contains(selected))
		{
			gameSettings->StoreSettingString(TEXT("Keyboard"), selected);
			UKeyboard_Subsystem_Core::Get()->DefaultKeyboardClass = UKeyboard_Subsystem_Core::Get()->KeyboardClassMap[selected];
		}
	}
}

void UGame_UserWidget_InterfaceSettings::HandleResetIconScaleClick()
{
	if (IsValid(IconScaleSlider))
	{
		float iconScalingPct = FMath::GetRangePct(MinIconScale, MaxIconScale, DefaultIconScale);

		IconScaleSlider->SetValue(iconScalingPct);
	}

	SetIconScaling(DefaultIconScale);

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingDouble(TEXT("IconScale"), DefaultIconScale);
	}
}

void UGame_UserWidget_InterfaceSettings::HandleResetLineScaleClick()
{
	if (IsValid(LineEditPointScaleSlider))
	{
		float lineEditPointScalingPct = FMath::GetRangePct(MinLineScale, MaxLineScale, DefaultLineScale);

		LineEditPointScaleSlider->SetValue(lineEditPointScalingPct);
	}
	
	SetLineEditPointScale(DefaultLineScale);

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingDouble(TEXT("LineScale"), DefaultLineScale);
	}
}

void UGame_UserWidget_InterfaceSettings::HandleResetAll()
{
	HandleResetIconScaleClick();
	HandleResetLineScaleClick();
	ResetSnapToModels();
	ResetInvertThumbstick();
	ResetXRayIcons();
	ResetCenterOnBeam();
	ResetApplicationScale();
	ResetMovementSpeed();
}

void UGame_UserWidget_InterfaceSettings::HandleIconViewSliderEndCapture()
{
	float iconScaling = FMath::Lerp(MinIconScale, MaxIconScale, CachedIconScalePct);

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingDouble(TEXT("IconScale"), iconScaling);
	}
}

void UGame_UserWidget_InterfaceSettings::HandleLineEditPointSliderEndCapture()
{
	float lineEditPointScale = FMath::Lerp(MinLineScale, MaxLineScale, CachedLineEditPointScalePct);

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->StoreSettingDouble(TEXT("LineScale"), lineEditPointScale);
	}
}

void UGame_UserWidget_InterfaceSettings::HandleApplicationScaleSliderValueEndCapture()
{
	PreviousApplicationScale = 1;
	if (const UUserInterfaceSettings* userInterfaceSettings = GetDefault<UUserInterfaceSettings>(UUserInterfaceSettings::StaticClass()))
	{
		PreviousApplicationScale = userInterfaceSettings->ApplicationScale;
	}

	float applicationScale = FMath::Lerp<float>(MinApplicationScale, MaxApplicationScale, ApplicationScaleSlider->GetValue());

	if (applicationScale != PreviousApplicationScale)
	{
		ApplicationScaleEditableText->SetText(FText::FromString(FString::Printf(TEXT("%f"), applicationScale)), false);

		SetApplicationScale(applicationScale);

		bOpenPopup = true;
	}
}

void UGame_UserWidget_InterfaceSettings::HandleApplicationScaleSliderValueChanged(float value)
{
	float applicationScale = FMath::Lerp<float>(MinApplicationScale, MaxApplicationScale, ApplicationScaleSlider->GetValue());

	ApplicationScaleEditableText->SetText(FText::FromString(FString::Printf(TEXT("%f"), applicationScale)), false);
}

void UGame_UserWidget_InterfaceSettings::HandleConfirmApplicationScale(UGame_UserWidget_Popup* popup, const FString& button)
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandleConfirmApplicationScale);

	if (button.Equals(TEXT("No")))
	{
		RestorePreviousApplicationScale();
	}
}

void UGame_UserWidget_InterfaceSettings::HandleApplicationScaleTextEdited(FString inString)
{
	if (UDeveloper_Subsystem_Core* developerSubsystem = UDeveloper_Subsystem_Core::Get())
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
	}
	
	PreviousApplicationScale = 1;
	if (const UUserInterfaceSettings* userInterfaceSettings = GetDefault<UUserInterfaceSettings>(UUserInterfaceSettings::StaticClass()))
	{
		PreviousApplicationScale = userInterfaceSettings->ApplicationScale;
	}
	
	if (inString.IsNumeric())
	{
		float applicationScale = FCString::Atof(*inString);
		applicationScale = FMath::Clamp(applicationScale, MinApplicationScale, MaxApplicationScale);
		
		if (applicationScale != PreviousApplicationScale)
		{
			float sliderValue = FMath::GetRangePct(MinApplicationScale, MaxApplicationScale, applicationScale);
			ApplicationScaleSlider->SetValue(sliderValue);

			SetApplicationScale(applicationScale);
			bOpenPopup = true;
		}
	}
	else
	{
		RestorePreviousApplicationScale();
	}
}

void UGame_UserWidget_InterfaceSettings::HandleKeyboardSpawnDestroyed(bool bSpawn, AActor* keyboardContainer)
{
	if (!bSpawn)
	{
		HandleApplicationScaleTextEdited(ApplicationScaleEditableText->GetText().ToString());
	}
}
