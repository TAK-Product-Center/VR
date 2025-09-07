// Required Includes
#include "Game_UserWidget_TextInput_DragSelect.h"
#include "Game.h"

// Engine Includes
#include "Engine/World.h"
#include "TimerManager.h"
#include "Components/EditableText.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

// VH Plugin Includes
#include "Developer_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_TextInput_DragSelect::UGame_UserWidget_TextInput_DragSelect(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_UserWidget_TextInput_DragSelect::NativeOnRemovedFromFocusPath(const FFocusEvent& inFocusEvent)
{
	if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
	{
		if (subsystem->GetHardwareInterfaceMode() == EHardwareInterfaceMode::Desktop)
		{
			// set keyboard focus if lost focus due to selecting text (and not immediately followed by other focus loss)
			if (inFocusEvent.GetCause() == EFocusCause::Mouse && inFocusEvent.GetUser() == 0)
			{
				GetWorld()->GetTimerManager().SetTimer(TextSelectionTimerHandle, this, &UGame_UserWidget_TextInput_DragSelect::HandleFocusLostDueToTextSelection, 0.5, false);
			}
			else
			{
				GetWorld()->GetTimerManager().ClearTimer(TextSelectionTimerHandle);
			}
		}
	}

	Super::NativeOnRemovedFromFocusPath(inFocusEvent);
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_UserWidget_TextInput_DragSelect::HandleFocusLostDueToTextSelection()
{
	if (APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		if (playerController->IsInputKeyDown(EKeys::LeftMouseButton))
		{
			// wait until text selection finishes
			GetWorld()->GetTimerManager().SetTimer(TextSelectionTimerHandle, this, &UGame_UserWidget_TextInput_DragSelect::HandleFocusLostDueToTextSelection, 0.5, false);
		}
		else
		{
			GetEditableText()->SetKeyboardFocus();
		}
	}
}