#pragma once

// Parent Includes
#include "GameFramework/PlayerController.h"

// Generated Includes
#include "VH_PlayerController_Replication.generated.h"

UCLASS()
class VH_REPLICATION_API AVH_PlayerController_Replication : public APlayerController
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	AVH_PlayerController_Replication(const FObjectInitializer& objectInitializer);

	// ---------------------------------
	// --- Public Methods
	// ---------------------------------
public:
	UFUNCTION(Reliable, Server, WithValidation)
	virtual void ServerSetChannelReady(int32 id, AActor* actor, bool bReady);
};