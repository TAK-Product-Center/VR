#pragma once

// Parent Includes
#include "GameFramework/GameMode.h"

#include "VH_DataChannelManager.h"
#include "VH_GameMode_Replication.generated.h"

UCLASS()
class VH_REPLICATION_API AVH_GameMode_Replication : public AGameMode
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Member Variables
	// ---------------------------------
public:
	TArray<UVH_DataChannelManager*> DataChannelManagers;

	// ---------------------------------
	// --- Inherited Methods
	// ---------------------------------
public:
	virtual void PostLogin(APlayerController* pc) override;

	virtual void Logout(AController* c) override;

	// ---------------------------------
	// --- Public Methods
	// ---------------------------------
public: 
	AVH_GameMode_Replication(const FObjectInitializer& objectInitializer);
};
