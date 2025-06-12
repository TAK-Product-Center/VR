#include "Game_Subsystem_PresenterMode.h"

#include "Developer_Statics.h"
#include "Game_PlayerState.h"
#include "Game_Statics.h"
#include "Game_Subsystem_PresenterMode_Settings.h"
#include "Game_Subsystem_Ribbon.h"
#include "Game_UserWidget_Popup.h"
#include "UI_Subsystem_Core.h"
#include "Blueprint/UserWidget.h"


// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_Subsystem_PresenterMode::UGame_Subsystem_PresenterMode()
{
}


// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_Subsystem_PresenterMode* UGame_Subsystem_PresenterMode::Get()
{
	if (UWorld* world = UDeveloper_Statics::GetVHWorld())
	{
		return world->GetSubsystem<UGame_Subsystem_PresenterMode>();
	}

	return nullptr;
}


// ---------------------------------
// --- API
// ---------------------------------

void UGame_Subsystem_PresenterMode::HandlePresentingUserChanged(APlayerState* presentingPlayerState)
{
	if(UUI_Subsystem_Core* uiSubsystem = UUI_Subsystem_Core::Get())
	{
		if (const UGame_Subsystem_PresenterMode_Settings* settings = GetDefault<UGame_Subsystem_PresenterMode_Settings>())
		{
			if(presentingPlayerState == nullptr)
			{
				CurrentPresenter = nullptr;
				uiSubsystem->CloseAllWidgetsByClass(settings->DisplayWindowClass, true);
				if(UGame_Subsystem_Ribbon* ribbonSubsystem = UGame_Subsystem_Ribbon::Get())
				{
					ribbonSubsystem->SetButtonEnabledCondition(TEXT("IsPresentationOngoing"), 0, false);
					ribbonSubsystem->SetButtonEnabledCondition(TEXT("IsPresentationPresenter"), 0);
				}
			}
			else if(AGame_PlayerState* playerState = Cast<AGame_PlayerState>(presentingPlayerState))
			{
				CurrentPresenter = playerState;
				TSet<UUserWidget*> widgetList = uiSubsystem->GetUserWidgetsByClass(settings->DisplayWindowClass, true);
		
				if(UGame_Subsystem_Ribbon* ribbonSubsystem = UGame_Subsystem_Ribbon::Get())
				{
					ribbonSubsystem->SetButtonEnabledCondition(TEXT("IsPresentationOngoing"), 1, false);
					ribbonSubsystem->SetButtonEnabledCondition(TEXT("IsPresentationPresenter"), playerState == UGame_Statics::GetLocalPlayerState());
				}
		
				if(!widgetList.IsEmpty())
				{
					uiSubsystem->OpenWithDefaultsByClass(settings->DisplayWindowClass);
				}
				else if(playerState != UGame_Statics::GetLocalPlayerState())
				{
					FString body = playerState->GetPlayerName() + " has begun presenting. Do you want to tune in?";
					TArray<FString> PopupButtons{TEXT("No"), TEXT("Yes")};
					if (UGame_UserWidget_Popup* popup = UGame_UserWidget_Popup::OpenPopup(settings->PopupMenuClass, TEXT("Presenter Mode"), body, PopupButtons, true))
					{
						popup->OnButtonPressed.AddUniqueDynamic(this, &UGame_Subsystem_PresenterMode::HandlePresenterPopupResponse);
					}
				}
			}
		}
	}
}


// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_Subsystem_PresenterMode::HandlePresenterPopupResponse(UGame_UserWidget_Popup* popupWidget, const FString& buttonText)
{
	if(buttonText.Equals("Yes") && CurrentPresenter != nullptr)
	{
		if(UUI_Subsystem_Core* uiSubsystem = UUI_Subsystem_Core::Get())
		{
			if (const UGame_Subsystem_PresenterMode_Settings* settings = GetDefault<UGame_Subsystem_PresenterMode_Settings>())
			{
				uiSubsystem->OpenWithDefaultsByClass(settings->DisplayWindowClass);
			}
		}
	}
}
