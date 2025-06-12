// Required Includes
#include "Game_UserWidget_RibbonButton_ConfirmPopup.h"
#include "Game.h"

// VH Plugin Includes
#include "Developer_Subsystem_Core.h"

// Game Includes
#include "Game_Subsystem_Ribbon.h"
#include "Game_UserWidget_Popup.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_RibbonButton_ConfirmPopup::UGame_UserWidget_RibbonButton_ConfirmPopup(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	PopupButtons.Add(TEXT("Cancel"));
	PopupButtons.Add(TEXT("Confirm"));
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_UserWidget_RibbonButton_ConfirmPopup::PostClicked()
{
	if(UGame_Subsystem_Ribbon* ribbonSubsystem = UGame_Subsystem_Ribbon::Get())
	{
		WasRibbonVisible = ribbonSubsystem->GetRibbonVisible();
		
		if(WasRibbonVisible)
		{
			ribbonSubsystem->ToggleRibbonVisibility();
		}
	}
		
	if (UGame_UserWidget_Popup* popup = UGame_UserWidget_Popup::OpenPopup(PopupClass, PopupHeader, PopupBody, PopupButtons, true))
	{
		popup->OnButtonPressed.AddUniqueDynamic(this, &UGame_UserWidget_RibbonButton_ConfirmPopup::ResetRibbonVisibility);
		popup->OnButtonPressed.Add(HandlePopupClicked);
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_RibbonButton_ConfirmPopup::SetPopupData(const FString& header, const FString& body, const TArray<FString>& buttons, const FPopupClicked& clickHandler)
{
	PopupHeader = header;
	PopupBody = body;

	PopupButtons.Empty();
	PopupButtons.Append(buttons);

	HandlePopupClicked = clickHandler;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_UserWidget_RibbonButton_ConfirmPopup::ResetRibbonVisibility(UGame_UserWidget_Popup* popupWidget, const FString& buttonText)
{
	if(UGame_Subsystem_Ribbon* ribbonSubsystem = UGame_Subsystem_Ribbon::Get())
	{
		if(WasRibbonVisible != ribbonSubsystem->GetRibbonVisible())
		{
			ribbonSubsystem->ToggleRibbonVisibility();
		}
	}
}
