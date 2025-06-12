// Required Includes
#include "Game_GameState.h"
#include "Game.h"

// Engine Includes
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"
#include "Online.h"
#include "Net/UnrealNetwork.h"
#include "TimerManager.h"

// Game Includes
#include "Game_GameMode.h"
#include "Game_PlayerState.h"
#include "Game_Statics.h"
#include "Game_Subsystem_PresenterMode.h"
#include "Game_Subsystem_Ribbon.h"
#include "Game_TileManager.h"
#include "Game_PresentationMode_ReplicatedWindowComponent.h"
#include "Game_UserWidget_Popup.h"
#include "UI_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_GameState::AGame_GameState(const class FObjectInitializer& objectInitializer) : Super(objectInitializer)
{
	GameModeClass = AGame_GameMode::StaticClass();
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_GameState::BeginDestroy()
{
	Super::BeginDestroy();

	TArray<APlayerState*> pArrayCopy = PlayerArray;
	for (APlayerState* iter : pArrayCopy)
	{
		RemovePlayerState(iter);
	}
}

void AGame_GameState::AddPlayerState(APlayerState* playerState)
{
	Super::AddPlayerState(playerState);

	OnPlayerStateAdded.Broadcast(playerState);

	//AGame_PlaybackController* owningController = Cast<AGame_PlaybackController>(PlayerState ? PlayerState->GetOwner() : nullptr);
	//if (owningController)
	//{
	//	UE_LOG(Game, Error, TEXT(" WE ARE REGISTERING A PLAYBACK CONTROLLER FOR VOICE"));
	//}

	if (GetNetMode() != NM_DedicatedServer /*|| (owningController != nullptr)*/)
	{
		PendingRegistrations.Add(playerState);
		DoVoiceRegistrations();
	}
}

void AGame_GameState::RemovePlayerState(APlayerState* playerState)
{
	Super::RemovePlayerState(playerState);

	OnPlayerStateRemoved.Broadcast(playerState);

	AttemptEndDragPan(playerState);

	if(playerState == PresentingPlayerState)
	{
		if(AGame_PlayerState* castedState = Cast<AGame_PlayerState>(playerState))
		{
			castedState->Server_StopPresenting();
		}
	}

	AController* owningController = Cast<AController>(playerState ? playerState->GetOwner() : nullptr);
	if (owningController != nullptr)
	{
		PendingRegistrations.Empty();
		IOnlineVoicePtr VoiceInt = Online::GetVoiceInterface();
		if (VoiceInt.IsValid())
		{
			if (owningController->IsLocalPlayerController())
			{
				VoiceInt->RegisterLocalTalker(0);
			}
			else if (playerState->GetUniqueId().IsValid())
			{
				VoiceInt->UnregisterRemoteTalker(*playerState->GetUniqueId());
			}
		}
	}
}

// ---------------------------------
// --- Replication
// ---------------------------------

void AGame_GameState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AGame_GameState, PanningPlayerState);
	DOREPLIFETIME(AGame_GameState, PresentingPlayerState);
}

void AGame_GameState::OnRep_PanningPlayerState()
{
	OnPanningPlayerStateUpdated.Broadcast(PanningPlayerState);

	if (UGame_TileManager* tileManager = UGame_TileManager::Get())
	{
		tileManager->ForceUpdate();
	}
}

void AGame_GameState::OnRep_PresentingPlayerState()
{
	if (UGame_Subsystem_PresenterMode* presenterSubsystem = UGame_Subsystem_PresenterMode::Get())
	{
		presenterSubsystem->HandlePresentingUserChanged(PresentingPlayerState);
	}
	
	OnPresentingPlayerStateUpdated.Broadcast(PresentingPlayerState);
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_GameState::AttemptBeginDragPan(APlayerState* playerState)
{
	if (GetNetMode() == NM_Client)
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_GameState::AttemptBeginDragPan | should only be called with authority | aborting"));

		return;
	}

	if (PanningPlayerState == nullptr)
	{
		PanningPlayerState = playerState;

		if (GetNetMode() == NM_Standalone || GetNetMode() == NM_ListenServer)
		{
			OnRep_PanningPlayerState();
		}
	}
}

void AGame_GameState::AttemptEndDragPan(APlayerState* playerState)
{
	if (GetNetMode() == NM_Client)
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_GameState::AttemptEndDragPan | should only be called with authority | aborting"));

		return;
	}

	if (playerState == PanningPlayerState)
	{
		PanningPlayerState = nullptr;

		if (GetNetMode() == NM_Standalone || GetNetMode() == NM_ListenServer)
		{
			OnRep_PanningPlayerState();
		}
	}
}

void AGame_GameState::DoVoiceRegistrations()
{
	for (int32 idx = PendingRegistrations.Num() - 1; idx >= 0; idx--)
	{
		APlayerState* iter = PendingRegistrations[idx];
		AController* owningController = Cast<AController>(iter ? iter->GetOwner() : nullptr);
		if (true || owningController != nullptr)
		{
			PendingRegistrations.RemoveAt(idx, 1);
			IOnlineVoicePtr VoiceInt = Online::GetVoiceInterface();
			if (VoiceInt.IsValid())
			{
				if (owningController != nullptr && owningController->IsLocalPlayerController())
				{
					VoiceInt->RegisterLocalTalker(0);
				}
				else if (iter->GetUniqueId().IsValid())
				{
					VoiceInt->RegisterRemoteTalker(*iter->GetUniqueId());
				}
			}
		}
	}

	if (PendingRegistrations.Num() > 0)
	{
		if (UWorld* world = GetWorld())
		{
			FTimerHandle DummyHandle;
			world->GetTimerManager().SetTimer(DummyHandle, this, &AGame_GameState::DoVoiceRegistrations, 0.2f, false);
		}
	}
}

TArray<APlayerState*> AGame_GameState::GetPlayerArray() const
{
	return PlayerArray;
}

APlayerState* AGame_GameState::GetPanningPlayerState() const
{
	return PanningPlayerState;
}

AGame_Tool* AGame_GameState::GetPanningTool() const
{
	return PanningTool;
}

bool AGame_GameState::SetPanningTool(AGame_Tool* panningTool)
{
	if (panningTool != nullptr && PanningTool != nullptr)
	{	
		UE_LOG(Game, Warning, TEXT("-- AGame_GameState::SetPanningTool | cannot forcefully override an existing valid panning tool | aborting"));
		
		return false;
	}

	PanningTool = panningTool;
	
	return true;
}

APlayerState* AGame_GameState::GetPresentingPlayerState() const
{
	return PresentingPlayerState;
}

void AGame_GameState::SetPresentingPlayerState(APlayerState* presentingPlayer)
{
	PresentingPlayerState = presentingPlayer;

	if (GetNetMode() == NM_Standalone || GetNetMode() == NM_ListenServer)
	{
		OnRep_PresentingPlayerState();
	}
}

FString AGame_GameState::GenerateUniqueCallsign(const FString& callsign)
{
	FString uniqueCallsign = "Unassigned-ChangeMe";

	// TODO: Get new callsign from gamestate instead
	if (CallsignSuffixes.Contains(callsign))
	{
		uniqueCallsign = FString::Printf(TEXT("%s_%d"), *callsign, CallsignSuffixes[callsign]);
		CallsignSuffixes[callsign]++;
	}
	else
	{
		uniqueCallsign = FString::Printf(TEXT("%s_0"), *callsign);
		CallsignSuffixes.Add(callsign, 1);
	}

	return uniqueCallsign;
}

bool AGame_GameState::PlayerCallsignExists(const AGame_PlayerState* playerState, const FString& callsign) const
{
	for (const APlayerState* checkState : GetPlayerArray())
	{
		const AGame_PlayerState* checkPlayerState = Cast<AGame_PlayerState>(checkState);
		if (checkPlayerState == nullptr)
		{
			UE_LOG(Game, Error, TEXT("Failed to cast player state to Game_PlayerState | Skipping callsign exists check"));
			return false;
		}

		// Don't compare with self
		if (playerState == checkPlayerState)
		{
			continue;
		}

		if (checkPlayerState->GetCallsign().Compare(callsign) == 0)
		{
			return true;
		}
	}

	// No duplicates found
	return false;
}
