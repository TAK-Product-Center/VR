#pragma once

#include "VH_GameMode_Replication.h"
#include "Game_GameMode.generated.h"

class AGame_PlayerState;
class AGame_SessionPlaybackAvatar;
class AGameSession;

UCLASS()
class GAME_API AGame_GameMode : public AVH_GameMode_Replication
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_GameMode(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_SessionPlaybackAvatar> SessionPlaybackAvatarClass;


    // ---------------------------------
    // --- Inherited
    // ---------------------------------

public:
    virtual TSubclassOf<AGameSession> GetGameSessionClass() const override;

	virtual void InitGame(const FString& mapName, const FString& options, FString& errorMessage) override;

	virtual void StartToLeaveMap() override;

	virtual void SetMatchState(FName newState) override;
};
