// Required Includes
#include "Game_ListEntry_Bloodhound_Player.h"
#include "Game.h"

// Engine Includes
#include "TimerManager.h"
#include "GameFramework/Pawn.h"

// VH Plugin Includes
#include "VH_COTManager.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_GeodeticCoord.h"

// Game Includes
#include "Game_VirtualObjective.h"
#include "Game_Statics.h"
#include "Game_PlayerState.h"
#include "Game_PlayerController.h"

// ---------------------------------
// --- API
// ---------------------------------

void UGame_ListEntry_Bloodhound_Player::SetPlayerState(APlayerState* playerState)
{
	PlayerState = Cast<AGame_PlayerState>(playerState);

	FTimerHandle timerHandle;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UGame_ListEntry_Bloodhound_Player::UpdateUI, 0.5, true);
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_ListEntry_Bloodhound_Player::UpdateUI()
{
	if (IsValid(PlayerState))
	{
		ReceiveSetCallsign(PlayerState->GetCallsign());

		if (APawn* playerPawn = PlayerState->GetPawn())
		{
			if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
			{
				if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
				{
					FGeodeticCoord3D coordinate = globeReference->WorldToGeodeticDouble(playerPawn->GetActorLocation());

					FString coordinateString = UGame_Statics::GetCoordinateStringInPreferredUnits(coordinate, true);

					ReceiveSetCoordinate(coordinateString);
				}
			}
		}
	}
}