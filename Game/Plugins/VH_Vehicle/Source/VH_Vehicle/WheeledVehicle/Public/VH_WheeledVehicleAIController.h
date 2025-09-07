// Developed by Virtual Heroes, 2019-2020

#pragma once

// Engine

// Module
#include "VH_VehicleAIController.h"

// Generated
#include "VH_WheeledVehicleAIController.generated.h"

UENUM(BlueprintType)
enum class EVehiclePathfindingState : uint8
{
	Inactive,
	InProgress,
	Suspended
};

UENUM(BlueprintType)
enum class EVehiclePathfindingResult : uint8
{
	Success,
	Aborted,
	Failed
};

/**
 * 
 */
UCLASS()
class VH_VEHICLE_API AVH_WheeledVehicleAIController : public AVH_VehicleAIController
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(EditDefaultsOnly, Category = "AI Behavior")
	UBlackboardData* BlackboardAsset;

	UPROPERTY(EditDefaultsOnly, Category = "AI Behavior")
	UBehaviorTree* BehaviorTreeAsset;

	UPROPERTY(EditDefaultsOnly, Category = "Pathing Behavior")
	float SplineTangentMaxSize;

protected:
	FVector TargetLocation;
	
	EVehiclePathfindingState PathingState;

	float AcceptanceThreshold;

	class USplineComponent* FollowSpline;

	class AVH_WheeledVehiclePawn* ControlledHumvee;

private:
	EVehiclePathfindingState PreSuspendedState;

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AVH_WheeledVehicleAIController(const FObjectInitializer& ObjectInitializer);

	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

protected:
	virtual void OnPossess(APawn* InPawn) override;

	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure, Category = "Gameplay")
	FVector GetPathingTargetLocation() const {return TargetLocation; };

	UFUNCTION(BlueprintPure, Category = "Gameplay")
	EVehiclePathfindingState GetPathingState() const { return PathingState; };

	UFUNCTION(BlueprintPure, Category = "Gameplay")
	USplineComponent* GetFollowSpline() const { return FollowSpline; };

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void SuspendPathing(bool inSuspendState);

	UFUNCTION(BlueprintCallable, Category = "Gameplay", meta = (Keywords = "Stop"))
	void ForcePathingComplete(bool inSuccessful);
	
	/** Starts pathing for the agent */
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void BeginMoveToTargetLocation(const FVector inTargetLocation, const float acceptanceRadius = 100.f);
	
	/** A non-mutator method to update the target location. Fails if the agent is not currently pathing or in a suspended state. */
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	bool SetTargetLocation(const FVector newTargetLocation);

	/** Supplied vector should be in world space. Fails if less than two points are provided */
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	bool SetFollowSplineFromVectorArray(UPARAM(ref) TArray<FVector>& inArray);

	/** Returns the nearest input key given a world location. No keys outside the distance bounds will be considered. */
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	float FindPathInputKeyAtLocationAndDistance(const FVector& worldLocation, const float minDistance, const float maxDistance) const;

	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	void TickPathing(); 

	void PathingComplete(bool inSuccessful);
};
