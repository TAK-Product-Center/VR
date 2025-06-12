#pragma once

// Engine
#include "CoreMinimal.h"

// Module
#include "Task_VehicleMoveTo.h"

// Generated
#include "Task_VehicleMoveToAtSpeed.generated.h"

class UVehiclePathFollowingComponent;

/**
 * Makes this vehicle move to a location but at a blackboard defined desired speed
 */
UCLASS()
class VH_VEHICLE_API UTask_VehicleMoveToAtSpeed : public UTask_VehicleMoveTo
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Variables
	// ---------------------------------
	
public:
	UPROPERTY(EditAnywhere, Category = Blackboard)
	struct FBlackboardKeySelector DesiredSpeed;

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UTask_VehicleMoveToAtSpeed(const FObjectInitializer& ObjectInitializer);

	// ---------------------------------
	// --- Inherited
	// ---------------------------------
	
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

};