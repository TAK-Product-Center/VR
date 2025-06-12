#include "Game_GameMode.h"

#include "Net/UnrealNetwork.h"
#include "Engine/DemoNetDriver.h"
#include "GameFramework/GameSession.h"
#include "OnlineSubsystemUtils.h"

#include "VH_GlobeReferenceActor.h"
#include "Developer_Statics.h"

#include "Game_GameInstance.h"
#include "Game_PlayerController.h"
#include "Game_GameSession.h"
#include "Game_GameState.h"
#include "Game_PlayerState.h"
#include "Game_Pawn.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_ImportManager.h"
#include "Game_SessionPlaybackAvatar.h"
#include "Game.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_GameMode::AGame_GameMode(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
    PlayerControllerClass = AGame_PlayerController::StaticClass();
    DefaultPawnClass = AGame_Pawn::StaticClass();
    PlayerStateClass = AGame_PlayerState::StaticClass();
    GameStateClass = AGame_GameState::StaticClass();
    GameSessionClass = AGame_GameSession::StaticClass();
	SessionPlaybackAvatarClass = AGame_SessionPlaybackAvatar::StaticClass();
}

// ---------------------------------
// --- Inherited
// ---------------------------------

TSubclassOf<AGameSession> AGame_GameMode::GetGameSessionClass() const
{
    return (GameSessionClass.Get() != nullptr) ? GameSessionClass.Get() : AGame_GameSession::StaticClass();
}

void AGame_GameMode::InitGame(const FString& mapName, const FString& options, FString& errorMessage)
{
    Super::InitGame(mapName, options, errorMessage);

    // TODO: Convert to delegate instead?
    UGame_GameInstance* gameInstance = UGame_GameInstance::Get();
    if (gameInstance)
    {
        gameInstance->OnGameModeInit();
    }
}

void AGame_GameMode::StartToLeaveMap()
{
    // TODO: Convert to delegate instead?
    UGame_GameInstance* gameInstance = UGame_GameInstance::Get();
    if (gameInstance)
    {
        gameInstance->OnGameModeStartToLeaveMap();
    }

    Super::StartToLeaveMap();
}

void AGame_GameMode::SetMatchState(FName newState)
{
	Super::SetMatchState(newState);

	if (newState.ToString().Equals(TEXT("Aborted"), ESearchCase::IgnoreCase))
	{
		// destroy session when unable to connect to host
		if (IOnlineSubsystem* onlineSub = IOnlineSubsystem::Get())
		{
			IOnlineSessionPtr sessionInterface = Online::GetSessionInterface(UDeveloper_Statics::GetVHWorld());

			sessionInterface->DestroySession(NAME_GameSession);
		}
	}
}
