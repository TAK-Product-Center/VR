#pragma once

// Parent Includes
#include "Engine/GameViewportClient.h"

// Generated Includes
#include "Game_GameViewportClient.generated.h"

UCLASS()
class GAME_API UGame_GameViewportClient : public UGameViewportClient
{
    GENERATED_UCLASS_BODY()


    // ---------------------------------
    // --- Variables
    // ---------------------------------

private:
    bool bInitialized;


    // ---------------------------------
    // --- Static Functions
    // ---------------------------------

public:
    UFUNCTION(BlueprintCallable, Category = "Viewport", meta = (DisplayName = "Get Game Viewport"))
    static UGame_GameViewportClient* Get();
};
