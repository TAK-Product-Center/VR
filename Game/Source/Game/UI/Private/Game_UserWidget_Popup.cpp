// Required Includes
#include "Game_UserWidget_Popup.h"
#include "Game.h"

// Engine Includes
#include "Blueprint/WidgetLayoutLibrary.h"

// VH Plugin Includes
#include "UI_Subsystem_Core.h"
#include "Developer_Subsystem_Core.h"

// Game Includes
#include "Game_Statics.h"
#include "Game_Pawn.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_Popup::UGame_UserWidget_Popup(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_UserWidget_Popup* UGame_UserWidget_Popup::OpenPopup(TSubclassOf<UGame_UserWidget_Popup> popupClass, const FString& header, const FString& body, const TArray<FString> buttons, bool bModal)
{
	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		// close existing
		subsystem->CloseAllWidgetsByClass(UGame_UserWidget_Popup::StaticClass(), true);

		UGame_UserWidget_Popup* popup = Cast<UGame_UserWidget_Popup>(subsystem->OpenWithDefaultsByClass(popupClass));
		popup->SetModal(bModal);
		popup->SetHeader(header);
		popup->SetBody(body);
		popup->SetButtons(buttons);
		
		subsystem->OnUserWidgetClosed.AddUniqueDynamic(popup, &UGame_UserWidget_Popup::HandleUserWidgetClosed);

		return popup;
	}

	return nullptr;
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_Popup::SetModal(bool bModalArg)
{
	bModal = bModalArg;

	if (bModal)
	{
		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
			{
				// OK for this to be null
				AActor* worldUIActor = subsystem->GetUserWidgetWorldUIActor(this);

				playerPawn->SetModalPopupOpen(true, worldUIActor);
			}
		}
	}
}

void UGame_UserWidget_Popup::ButtonClicked(const FString& buttonText)
{
	OnButtonPressed.Broadcast(this, buttonText);

	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		subsystem->CloseUserWidget(this);
	}
}

void UGame_UserWidget_Popup::SetHeader(const FString& header)
{
	ReceiveSetHeader(header);
}

void UGame_UserWidget_Popup::SetBody(const FString& body)
{
	ReceiveSetBody(body);
}

void UGame_UserWidget_Popup::SetButtons(const TArray<FString>& buttons)
{
	ReceiveSetButtons(buttons);
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_UserWidget_Popup::CleanupModal()
{
	if (bModal)
	{
		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			playerPawn->SetModalPopupOpen(false, nullptr);
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_UserWidget_Popup::HandleUserWidgetClosed(UUserWidget* userWidget)
{
	if (userWidget == this)
	{
		CleanupModal();
	}
}