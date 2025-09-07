#pragma once

// Parent Includes
#include "Game_EditPoint.h"

// Generated Includes
#include "Game_EditPoint_Center.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_EditPoint_Center : public AGame_EditPoint
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------
	
private:
	FString Callsign;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------
	
public:
	AGame_EditPoint_Center(const FObjectInitializer& objectInitializer);

	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void PostBeginHover(AActor* actor) override;

	virtual void PostEndHover(AActor* actor) override;


	// ---------------------------------
	// --- API
	// ---------------------------------
	
public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetCallsign(const FString& inCallsign);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetCallsignHidden(bool bHiddenArg);

	UFUNCTION(BlueprintCallable)
	void SetCallsign(const FString& inCallsign);

	UFUNCTION(BlueprintPure)
	FString GetCallsign() const;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleDistanceThresholdCrossed(double thresholdMeters, double distanceMeters);
};