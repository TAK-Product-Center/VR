// Required Includes
#include "Game_GameViewportClient.h"
#include "Game.h"

// Engine Includes
#include "Engine/Engine.h"

UGame_GameViewportClient::UGame_GameViewportClient(const FObjectInitializer& objectInitializer) :
    Super(objectInitializer)
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_GameViewportClient* UGame_GameViewportClient::Get()
{
    if (GEngine != nullptr && GEngine->GameViewport != nullptr)
    {
        UGame_GameViewportClient* viewportClient = Cast<UGame_GameViewportClient>(GEngine->GameViewport);

        return viewportClient;
    }
    return nullptr;
}