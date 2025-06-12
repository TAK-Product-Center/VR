
#include "Game_GameSession.h"
#include "Game.h"


AGame_GameSession::AGame_GameSession(const FObjectInitializer& objectInitializer) :
    Super(objectInitializer)
{
}


// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_GameSession::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    OnPlayerJoined(NewPlayer);
    OnPlayerJoinedCallback.Broadcast(NewPlayer);
}
