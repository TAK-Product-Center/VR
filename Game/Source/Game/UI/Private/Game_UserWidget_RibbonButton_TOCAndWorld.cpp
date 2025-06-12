// Required Includes
#include "Game_UserWidget_RibbonButton_TOCAndWorld.h"
#include "Game.h"

// Engine Includes
#include "TimerManager.h"

// Game Includes
#include "Game_Statics.h"
#include "Game_PlayerState.h"
#include "Game_PlayerController.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_RibbonButton_TOCAndWorld::UGame_UserWidget_RibbonButton_TOCAndWorld(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	CooldownSeconds(2)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool UGame_UserWidget_RibbonButton_TOCAndWorld::Initialize()
{
	bool bToReturn = Super::Initialize();

	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		playerState->OnIsInTOCUpdated.AddUniqueDynamic(this, &UGame_UserWidget_RibbonButton_TOCAndWorld::HandleIsInTOCUpdated);

		HandleIsInTOCUpdated(playerState->GetIsInTOC());
	}

	return bToReturn;
}

void UGame_UserWidget_RibbonButton_TOCAndWorld::NativeConstruct()
{
	Super::NativeConstruct();

	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		HandleIsInTOCUpdated(playerState->GetIsInTOC());
	}
}

void UGame_UserWidget_RibbonButton_TOCAndWorld::PostClicked()
{
	if (AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController())
	{
		if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
		{
			playerState->OnIsInTOCUpdated.AddUniqueDynamic(this, &UGame_UserWidget_RibbonButton_TOCAndWorld::HandleIsInTOCUpdated);
			if (playerState->GetIsInTOC())
			{
				playerController->ConsoleCommand(TEXT("ce GoToWorld"));
			}
			else
			{
				playerController->ConsoleCommand(TEXT("ce GoToTOC"));
			}
		}
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_RibbonButton_TOCAndWorld::RenewBinding()
{
	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		playerState->OnIsInTOCUpdated.AddUniqueDynamic(this, &UGame_UserWidget_RibbonButton_TOCAndWorld::HandleIsInTOCUpdated);
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_UserWidget_RibbonButton_TOCAndWorld::Cooldown()
{
	SetIsEnabled(true);
}

void UGame_UserWidget_RibbonButton_TOCAndWorld::HandleIsInTOCUpdated(bool bIsInTOC)
{
	SetIsEnabled(false);

	FTimerHandle timerHandle;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UGame_UserWidget_RibbonButton_TOCAndWorld::Cooldown, CooldownSeconds, false);

	SetIcon(bIsInTOC ? IconToWorld : IconToTOC);

	SetText(bIsInTOC ? TEXT("Enter World") : TEXT("Enter TOC"));
}