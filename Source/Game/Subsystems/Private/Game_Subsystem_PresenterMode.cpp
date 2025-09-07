// Required Includes
#include "Game_Subsystem_PresenterMode.h"
#include "Game.h"

// Engine Includes
#include "Blueprint/UserWidget.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "UI_Subsystem_Core.h"

// Game Includes
#include "Game_PlayerState.h"
#include "Game_Statics.h"
#include "Game_Subsystem_PresenterMode_Settings.h"
#include "Game_Subsystem_Ribbon.h"
#include "Game_UserWidget_Popup.h"

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
// --- Inherited
// ---------------------------------

void UGame_Subsystem_PresenterMode::Initialize(FSubsystemCollectionBase& collection)
{
	Super::Initialize(collection);

	if (const UGame_Subsystem_PresenterMode_Settings* settings = GetDefault<UGame_Subsystem_PresenterMode_Settings>())
	{
		ApplySettings(settings);
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_Subsystem_PresenterMode::HandlePresentingUserChanged(APlayerState* presentingPlayerState)
{
	if (UUI_Subsystem_Core* uiSubsystem = UUI_Subsystem_Core::Get())
	{
		if (presentingPlayerState == nullptr)
		{
			CurrentPresenter = nullptr;

			uiSubsystem->CloseAllWidgetsByClass(DisplayWindowClass, true);

			if (UGame_Subsystem_Ribbon* ribbonSubsystem = UGame_Subsystem_Ribbon::Get())
			{
				ribbonSubsystem->SetButtonEnabledCondition(TEXT("IsPresentationOngoing"), 0, false);
				ribbonSubsystem->SetButtonEnabledCondition(TEXT("IsPresentationPresenter"), 0);
			}
		}
		else if (AGame_PlayerState* playerState = Cast<AGame_PlayerState>(presentingPlayerState))
		{
			CurrentPresenter = playerState;
			TSet<UUserWidget*> widgetList = uiSubsystem->GetUserWidgetsByClass(DisplayWindowClass, true);
		
			if (UGame_Subsystem_Ribbon* ribbonSubsystem = UGame_Subsystem_Ribbon::Get())
			{
				ribbonSubsystem->SetButtonEnabledCondition(TEXT("IsPresentationOngoing"), 1, false);
				ribbonSubsystem->SetButtonEnabledCondition(TEXT("IsPresentationPresenter"), playerState == UGame_Statics::GetLocalPlayerState());
			}
		
			if (!widgetList.IsEmpty())
			{
				uiSubsystem->OpenWithDefaultsByClass(DisplayWindowClass);
			}
			else if (playerState != UGame_Statics::GetLocalPlayerState())
			{
				FString body = playerState->GetPlayerName() + TEXT(" has begun presenting. Do you want to tune in?");
					
				TArray<FString> popupButtons{TEXT("No"), TEXT("Yes")};
				if (UGame_UserWidget_Popup* popup = UGame_UserWidget_Popup::OpenPopup(PopupMenuClass, TEXT("Presenter Mode"), body, popupButtons, true))
				{
					popup->OnButtonPressed.AddUniqueDynamic(this, &UGame_Subsystem_PresenterMode::HandlePresenterPopupResponse);
				}
			}
		}
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_Subsystem_PresenterMode::ApplySettings(const UGame_Subsystem_PresenterMode_Settings* settings)
{
	PopupMenuClass = settings->PopupMenuClass;
	DisplayWindowClass = settings->DisplayWindowClass;
	CaptureActorClass = settings->CaptureActorClass;

	FActorSpawnParameters spawnParameters;
	spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	CaptureActor = GetWorld()->SpawnActor<AActor>(CaptureActorClass, spawnParameters);
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_Subsystem_PresenterMode::HandlePresenterPopupResponse(UGame_UserWidget_Popup* popupWidget, const FString& buttonText)
{
	if (buttonText.Equals(TEXT("Yes")) && CurrentPresenter != nullptr)
	{
		if (UUI_Subsystem_Core* uiSubsystem = UUI_Subsystem_Core::Get())
		{
			uiSubsystem->OpenWithDefaultsByClass(DisplayWindowClass);
		}
	}
}
