// Required includes
#include "Game_PluginActor.h"
#include "Game.h"


// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_PluginActor::AGame_PluginActor()
{
}


// ---------------------------------
// --- API
// ---------------------------------

void AGame_PluginActor::HandleCOTMessageReceived(const FString& messageType)
{
	PostHandleCOTMessageReceived(messageType);

	ReceiveHandleCOTMessageReceived(messageType);
}


// ---------------------------------
// --- Implementation
// ---------------------------------

void AGame_PluginActor::PostHandleCOTMessageReceived(const FString& messageType)
{
}