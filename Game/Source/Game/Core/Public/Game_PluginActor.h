#pragma once

// Parent includes
#include "VH_PluginActor.h"

// Generated include
#include "Game_PluginActor.generated.h"


UCLASS()
class GAME_API AGame_PluginActor : public AVH_PluginActor
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:

    AGame_PluginActor();


	// ---------------------------------
	// --- API
	// ---------------------------------
public:

	void HandleCOTMessageReceived(const FString& messageType);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------
protected:

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "Handle COTMessage Received"))
	void ReceiveHandleCOTMessageReceived(const FString& messageType);

private:

	virtual void PostHandleCOTMessageReceived(const FString& messageType);

};