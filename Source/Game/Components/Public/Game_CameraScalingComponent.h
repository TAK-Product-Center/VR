#pragma once

// Parent Includes
#include "Developer_CameraScalingComponent.h"

// Generated Includes
#include "Game_CameraScalingComponent.generated.h"

class AGame_VirtualObjective;
class AGame_PlayerState;

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_CameraScalingComponent : public UDeveloper_CameraScalingComponent
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

public:
	DECLARE_DELEGATE_RetVal(double, FGetCameraDistance);

	DECLARE_DELEGATE_RetVal(AGame_PlayerState*, FGetPlayerState);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FThresholdCrossed, double, thresholdMeters, double, distanceMeters);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FThresholdCrossed OnThresholdCrossed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector2D MinMaxCameraDistanceForScalingTOC;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector MinScaleTOC;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector MaxScaleTOC;

	FGetCameraDistance GetDistanceLambda;

private:
	FVector2D MinMaxCameraDistanceForScalingWorld;

	FVector MinScaleWorld;

	FVector MaxScaleWorld;

	double LastDistanceMeters;

	/* in meters */
	TSet<double> ThresholdMeters;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_CameraScalingComponent(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual double GetDistance() const override;

protected:
	virtual FVector GetUpVector() const override;

	virtual void PostTickDistance(double distanceUU) override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void AddDistanceThreshold(double thresholdMeters);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void BindToPlayerState();

	UFUNCTION()
	void HandleIsInTOCUpdated(bool bIsInTOC);
};