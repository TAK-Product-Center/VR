#pragma once


#include "GameFramework/GameSession.h"
#include "Game_GameSession.generated.h"


/**
*
*/
UCLASS(Blueprintable)
class AGame_GameSession : public AGameSession
{
    GENERATED_UCLASS_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

public:

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerJoined, APlayerController*, newPlayer);


    // ---------------------------------
    // --- Properties
    // ---------------------------------

public:
    UPROPERTY(BlueprintAssignable)
    FOnPlayerJoined OnPlayerJoinedCallback;


    // ---------------------------------
    // --- Inherited functions
    // ---------------------------------

public:
    /**
	* Called by GameMode::PostLogin to give session code chance to do work after PostLogin
	*
	* @param NewPlayer player logging in
	*/
    virtual void PostLogin(APlayerController* NewPlayer) override;


    // ---------------------------------
    // --- New functions
    // ---------------------------------

public:
    // ---------------------------------
    // --- Event Handlers
    // ---------------------------------

    UFUNCTION(BlueprintImplementableEvent)
    void OnPlayerJoined(APlayerController* newPlayer);


    // ---------------------------------
    // --- Debug/TESTING
    // ---------------------------------
};
