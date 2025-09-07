#pragma once

// Generate Include
#include "GameFramework/GameState.h"

// Generate Include
#include "Game_GameState.generated.h"

class AGame_PlayerState;
class APlayerState;
class AGame_Tool;

UCLASS()
class GAME_API AGame_GameState : public AGameState
{
	GENERATED_UCLASS_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerStateAdded, APlayerState*, playerState);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlayerStateRemoved, APlayerState*, playerState);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPanningPlayerStateUpdated, APlayerState*, panningPlayerState);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPresentingPlayerStateUpdated, APlayerState*, presentingPlayerState);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPresentingLockStateUpdated, bool, presentingLockState);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FPlayerStateAdded OnPlayerStateAdded;

	UPROPERTY(BlueprintAssignable)
	FPlayerStateRemoved OnPlayerStateRemoved;

	UPROPERTY()
	TArray<APlayerState*> PendingRegistrations;

	UPROPERTY(BlueprintAssignable)
	FPanningPlayerStateUpdated OnPanningPlayerStateUpdated;

	UPROPERTY(BlueprintAssignable)
	FPresentingPlayerStateUpdated OnPresentingPlayerStateUpdated;

	UPROPERTY(BlueprintAssignable)
	FPresentingLockStateUpdated OnPresentingLockStateUpdated;

private:
	UPROPERTY(ReplicatedUsing = OnRep_PanningPlayerState)
	APlayerState* PanningPlayerState;
	
	UPROPERTY(ReplicatedUsing = OnRep_PresentingPlayerState)
	APlayerState* PresentingPlayerState;
	
	UPROPERTY(ReplicatedUsing = OnRep_PresentingLockState)
	bool PresentingLockState;

	// client-side only
	UPROPERTY()
	AGame_Tool* PanningTool;

	TMap<FString, int32> CallsignSuffixes;


	// ---------------------------------
	// --- Replication
	// ---------------------------------

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& outLifetimeProps) const override;

private:
	UFUNCTION()
	void OnRep_PanningPlayerState();
	
	UFUNCTION()
	void OnRep_PresentingPlayerState();
	
	UFUNCTION()
	void OnRep_PresentingLockState();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginDestroy() override;

	/** Add PlayerState to the PlayerArray */
	virtual void AddPlayerState(APlayerState* playerState) override;

	/** Remove PlayerState from the PlayerArray. */
	virtual void RemovePlayerState(APlayerState* playerState) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void AttemptBeginDragPan(APlayerState* playerState);

	void AttemptEndDragPan(APlayerState* playerState);

	UFUNCTION()
	void DoVoiceRegistrations();

	/** todo ohg UE5 | remove this when Epic fixes direct blueprint references to PlayerState */
	UFUNCTION(BlueprintPure)
	TArray<APlayerState*> GetPlayerArray() const;

	UFUNCTION(BlueprintPure)
	APlayerState* GetPanningPlayerState() const;

	UFUNCTION(BlueprintPure)
	AGame_Tool* GetPanningTool() const;

	UFUNCTION(BlueprintCallable)
	bool SetPanningTool(AGame_Tool* panningToolArg);

	UFUNCTION(BlueprintPure)
	APlayerState* GetPresentingPlayerState() const;

	UFUNCTION(BlueprintCallable)
	void SetPresentingPlayerState(APlayerState* presentingPlayer);

	UFUNCTION(BlueprintPure)
	bool GetIsPresentingPlayerLocked() const;

	UFUNCTION(BlueprintCallable)
	void SetIsPresentingPlayerLocked(bool presentingLocked);

	/**
	 * Returns a callsign that does not collide with other players
	 * @param callsign The base callsign to append a suffix to in order to ensure uniqueness
	 * @return A unique callsign ({callsign}_#) where the number increments automatically
	 */
	FString GenerateUniqueCallsign(const FString& callsign);

	/**
	 * Checks if the callsign is already being used by another player
	 * @param playerState Reference to the player state attempting to change their callsign
	 * @param callsign The new callsign to attempt to assign
	 * @return True if callsign already exists for another player
	 */
	bool PlayerCallsignExists(const AGame_PlayerState* playerState, const FString& callsign) const;
};
