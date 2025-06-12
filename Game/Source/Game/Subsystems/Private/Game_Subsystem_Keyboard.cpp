// Required Includes
#include "Game_Subsystem_Keyboard.h"
#include "Game.h"

// Engine Includes
#include "GameFramework/PlayerInput.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Application/SlateUser.h"
#include "Engine/World.h"
#include "TimerManager.h"

// VH Plugin Includes
#include "Developer_Subsystem_Core.h"
#include "Developer_Statics.h"
#include "Keyboard_ContainerComponent.h"

// Game Includes
#include "Game_Statics.h"
#include "Game_PlayerController.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_Subsystem_Keyboard::UGame_Subsystem_Keyboard()
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_Subsystem_Keyboard::Initialize(FSubsystemCollectionBase& collection)
{
	Super::Initialize(collection);

	KeyboardWidgets.Add(TEXT("SEditableTextBox"));
	KeyboardWidgets.Add(TEXT("SEditableText"));
	KeyboardWidgets.Add(TEXT("CEFWebBrowserWindow"));

	BindToFocusChange();
}

void UGame_Subsystem_Keyboard::Deinitialize()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication& slateApplication = FSlateApplication::Get();

		int32 keyboardUserIndex = slateApplication.GetUserIndexForKeyboard();
		TSharedPtr<FSlateUser> slateUser = slateApplication.GetUser(keyboardUserIndex);
		slateUser->SetFocusLocked(false);
	}

	Super::Deinitialize();
}

bool UGame_Subsystem_Keyboard::ShouldCreateSubsystem(UObject* outer) const
{
	return true;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_Subsystem_Keyboard::BindToFocusChange()
{
	if (GetWorld()->WorldType == EWorldType::Game || GetWorld()->WorldType == EWorldType::PIE)
	{
		if (FSlateApplication::IsInitialized())
		{
			FSlateApplication::Get().OnFocusChanging().AddUObject(this, &UGame_Subsystem_Keyboard::HandleFocusChanging);
		}
		else
		{
			FTimerHandle timerHandle;
			GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UGame_Subsystem_Keyboard::BindToFocusChange, 0.5, false);
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_Subsystem_Keyboard::HandleFocusChanging(const FFocusEvent& focusEvent, const FWeakWidgetPath& oldFocusedWidgetPath, const TSharedPtr<SWidget>& OldFocusedWidget, const FWidgetPath& newFocusedWidgetPath, const TSharedPtr<SWidget>& newFocusedWidget)
{
	if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
	{
		EHardwareInterfaceMode hardwareInterfaceMode = subsystem->GetHardwareInterfaceMode();
		if (hardwareInterfaceMode == EHardwareInterfaceMode::VREmulation || hardwareInterfaceMode == EHardwareInterfaceMode::VR)
		{
			if (!IsKeyboardOpen())
			{
				if (newFocusedWidget.IsValid())
				{
					if (KeyboardWidgets.Contains(newFocusedWidget->GetTypeAsString()))
					{
						/*if (hardwareInterfaceMode == EHardwareInterfaceMode::VR)
						{
							UGame_Statics::GetVHPlayerController()->PlayerInput->FlushPressedKeys();
						}*/

						AActor* keyboardContainer = CreateKeyBoardForObject(UGame_Statics::GetVHPlayerController());
						
						keyboardContainer->SetActorRotation(UGame_Statics::GetWorldTransformOverride(keyboardContainer->GetActorLocation()).TransformRotation(FRotator::ZeroRotator.Quaternion()).Rotator());

						if (hardwareInterfaceMode == EHardwareInterfaceMode::VREmulation)
						{
							FSlateApplication& slateApplication = FSlateApplication::Get();

							int32 keyboardUserIndex = slateApplication.GetUserIndexForKeyboard();
							TSharedPtr<FSlateUser> slateUser = slateApplication.GetUser(keyboardUserIndex);

							slateApplication.SetKeyboardFocus(newFocusedWidget);
							slateUser->SetFocusLocked(true);

							// puts cursor at the end of any existing text in focused widget
							UDeveloper_Statics::PressAndReleaseKey(EKeys::Right);
						}

						if (hardwareInterfaceMode == EHardwareInterfaceMode::VR)
						{
							UGame_Statics::GetVHPlayerController()->PlayerInput->FlushPressedKeys();

							if (UKeyboard_ContainerComponent* containerComponent = keyboardContainer->GetComponentByClass<UKeyboard_ContainerComponent>())
							{
								containerComponent->SWidgetToSendPress = newFocusedWidget;
							}
						}
					}
				}
			}
		}
	}
}