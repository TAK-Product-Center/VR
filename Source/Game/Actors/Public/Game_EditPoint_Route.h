#pragma once

#include "Game_EditPoint.h"
#include "Game_EditPoint_Route.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_EditPoint_Route : public AGame_EditPoint
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCheckpointUpdated, bool, bCheckpoint);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCallsignUpdated, const FString&, callsign);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNavCueUpdated, const FString&, callsign);

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FOnCheckpointUpdated OnCheckpointUpdated;

	UPROPERTY(BlueprintAssignable)
	FOnCallsignUpdated OnCallsignUpdated;

	UPROPERTY(BlueprintAssignable)
	FOnNavCueUpdated OnNavCueUpdated;

private:
	bool bIsCheckpoint;

	/* true if user set this to a checkpoint */
	bool bUserCheckpoint;

	/* callsign set by user */
	FString UserCallsign;

	FString GeneratedCallsign;

	FString NavCue;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_EditPoint_Route(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void SetActive(bool bActive) override;

	virtual void BeginPlay() override;

	virtual void PostBeginHover(AActor* actor) override;

	virtual void PostEndHover(AActor* actor) override;

protected:
	virtual void UpdateMaterial() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetCallsign(const FString& inCallsign);

	UFUNCTION(BlueprintImplementableEvent)
	void ReceiveSetCallsignHidden(bool bHiddenArg);

	UFUNCTION(BlueprintPure)
	bool IsCheckpoint();

	UFUNCTION(BlueprintCallable)
	void SetIsCheckpoint(bool bCheckpoint);

	void SetUserCheckpoint(bool bInUserCheckpoint);

	bool GetUserCheckpoint() const;

	UFUNCTION(BlueprintCallable)
	void SetUserCallsign(const FString& userCallsign);

	UFUNCTION(BlueprintPure)
	FString GetUserCallsign() const;

	void SetGeneratedCallsign(const FString& generatedCallsign);

	UFUNCTION(BlueprintPure)
	FString GetCallsign() const;

	UFUNCTION(BlueprintCallable)
	void SetNavCue(const FString& navCue);

	UFUNCTION(BlueprintPure)
	FString GetNavCue() const;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleDistanceThresholdCrossed(double thresholdMeters, double distanceMeters);
};
