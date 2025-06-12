#pragma once

// Engine
#include "CoreMinimal.h"
#include "NavMesh/RecastNavMesh.h"
#include "AI/Navigation/NavigationTypes.h"
#include "AITypes.h"
#include "Kismet/BlueprintAsyncActionBase.h"

// Generated
#include "VH_VehicleAsyncMoveTo.generated.h"

class AAIController;

// ---------------------------------
// --- Delegates
// ---------------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAsyncPathFindComplete, ENavigationQueryResult::Type, Result);

/**
 * Finds a path for an AI agent asynchronously
 */
UCLASS()
class VH_VEHICLE_API UVH_VehicleAsyncMoveTo : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Delegates
	// ---------------------------------

public:
	/* Called to blueprints when the pathfinding request has completed */
	UPROPERTY(BlueprintAssignable)
	FAsyncPathFindComplete CompletedPathCreation;

	FNavPathQueryDelegate PathCompleted;

	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	FAIMoveRequest MoveReq;

	UObject* WorldContextObject;
	AAIController* AIController;
	FVector GoalLocation;

	/* Navigation Mesh */
	ARecastNavMesh* NavMesh;

	/* Nav Path Shared Pointer */
	FNavPathSharedPtr NavPath;

	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

	/* Using the Async Pathfinder to find a path, this works with all AI and not just vehicles and can greatly help performance especially for complicated paths that need updating regularly.
	This is also experimental and some crashes have been reported, so test it in your own project to ensure robustness before deploying. */
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DisplayName = "Vehicle AI Move To"), Category = "AI")
	static UVH_VehicleAsyncMoveTo* AsyncMoveTo(const UObject* WorldContextObject, AAIController* Controller, const FVector& Dest, float AcceptanceRadius = -1, bool bStopOnOverlap = true,
			bool bUsePathfinding = true, bool bProjectDestinationToNavigation = false, bool bCanStrafe = true,
			TSubclassOf<UNavigationQueryFilter> FilterClass = NULL, bool bAllowPartialPath = true);

	// ---------------------------------
	// --- Inherited
	// ---------------------------------

	/* Activates the async function */
	virtual void Activate() override;

	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

	/* Called when the pathing request is completed */
	void OnPathRequestCompleted(uint32 RequestID, ENavigationQueryResult::Type Result, FNavPathSharedPtr NewPath);
	
};
