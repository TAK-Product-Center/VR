#pragma once

// Parent Includes
#include "Game_Tool.h"

// Generated Includes
#include "Game_Tool_LaserPointer.generated.h"

class AGame_PlayerState;

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_Tool_LaserPointer : public AGame_Tool
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	UPROPERTY(ReplicatedUsing = OnRep_ShowBeamToAll)
	bool bShowBeamToAll;
	

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Tool_LaserPointer(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Replication
	// ---------------------------------

public:
	UFUNCTION(Server, Reliable)
	void Server_ShowBeamToAll(bool bShowBeam);

	UFUNCTION()
	void OnRep_ShowBeamToAll();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void OnRep_Owner() override;

	virtual void PostTriggerPressed(ECollisionChannel traceChannel, const TArray<FHitResult>& hitResults) override;

	virtual void PostTriggerActionPressed() override;

	virtual void PostTriggerReleased() override;

	virtual void PostTickUpdateBeam(float deltaSeconds) override;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void ShowBeam();

	void SetCursorColor(const FLinearColor& color);

	void BindToPlayerState();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleCallsignChanged(const FString& callsign, const FLinearColor& collaborationColor);
};