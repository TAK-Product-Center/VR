#pragma once

// Engine
#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"

// Generated
#include "Task_VehicleMoveTo.generated.h"

class UVH_VehiclePathFollowingComponent;

/**
 * Same as normal MoveTo node but includes the ability to optionally tell this vehicle to reverse
 */
UCLASS()
class VH_VEHICLE_API UTask_VehicleMoveTo : public UBTTask_MoveTo
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Variables
	// ---------------------------------

protected:

	UPROPERTY(EditAnywhere, Category = "Vehicle AI")
	bool bReverseTowardsTarget = false;

	UBlackboardComponent* MyBlackboard;
	UVH_VehiclePathFollowingComponent* VehiclePathComp;

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:

	UTask_VehicleMoveTo(const FObjectInitializer& ObjectInitializer);
	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult) override;

};
