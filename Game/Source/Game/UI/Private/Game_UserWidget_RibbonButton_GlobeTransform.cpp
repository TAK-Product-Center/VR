// Required Includes
#include "Game_UserWidget_RibbonButton_GlobeTransform.h"
#include "Game.h"

// VH Platform Includes
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_Pawn.h"
#include "Game_Statics.h"
#include "Game_PlayerState.h"
#include "Game_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_RibbonButton_GlobeTransform::UGame_UserWidget_RibbonButton_GlobeTransform(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool UGame_UserWidget_RibbonButton_GlobeTransform::Initialize()
{
	bool bToReturn = Super::Initialize();

	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		playerState->OnIsInTOCUpdated.AddUniqueDynamic(this, &UGame_UserWidget_RibbonButton_GlobeTransform::HandleIsInTOCUpdated);

		if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
		{
			HandleIsInTOCUpdated(playerState->GetNetMode() == NM_Client || gameSettings->GetSettingBool(TEXT("bInitialInTOC")));
		}
	}

	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		playerPawn->VRMovement->OnWorldTransformOverrideUpdated.AddDynamic(this, &UGame_UserWidget_RibbonButton_GlobeTransform::HandleWorldTransformOverrideUpdated);
	}

	return bToReturn;
}

void UGame_UserWidget_RibbonButton_GlobeTransform::NativeConstruct()
{
	Super::NativeConstruct();

	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		HandleIsInTOCUpdated(playerState->GetIsInTOC());
	}
}

void UGame_UserWidget_RibbonButton_GlobeTransform::PostClicked()
{
	if (!UGame_Statics::IsLocalPlayerInTOC())
	{
		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			playerPawn->ToggleGlobeTransform();

			if (UGame_Statics::GetPlayerWorldTransformOverride().Equals(FTransform::Identity))
			{
				SetIcon(IconFirstPerson);
				
				SetText(TEXT("First Person"));
			}
			else
			{
				SetIcon(IconTopDown);
				
				SetText(TEXT("Top Down"));
			}
		}
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_RibbonButton_GlobeTransform::RenewBinding()
{
	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		HandleIsInTOCUpdated(playerState->GetIsInTOC());

		playerState->OnIsInTOCUpdated.AddUniqueDynamic(this, &UGame_UserWidget_RibbonButton_GlobeTransform::HandleIsInTOCUpdated);
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_UserWidget_RibbonButton_GlobeTransform::HandleIsInTOCUpdated(bool bIsInTOC)
{
	if (bIsInTOC)
	{
		SetIcon(IconTopDown);

		SetText(TEXT("Top Down"));
	}
}

void UGame_UserWidget_RibbonButton_GlobeTransform::HandleWorldTransformOverrideUpdated(const FTransform& transform)
{
	if (UGame_Statics::GetPlayerWorldTransformOverride().Equals(FTransform::Identity))
	{
		SetIcon(IconFirstPerson);
				
		SetText(TEXT("First Person"));
	}
	else
	{
		SetIcon(IconTopDown);
				
		SetText(TEXT("Top Down"));
	}
}
