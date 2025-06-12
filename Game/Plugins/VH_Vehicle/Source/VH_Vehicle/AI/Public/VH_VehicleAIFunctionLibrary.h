#pragma once

// Engine
#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"

// Module
#include "VH_VehiclePathFollowingComponent.h"
#include "VH_VehicleEnums.h"

// Generated
#include "VH_VehicleAIFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class VH_VEHICLE_API UVH_VehicleAIFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	/* Helper function that returns the path following component from a provided pawn by getting the controller and its path following component. */
	UFUNCTION(BlueprintPure, Category = "Vehicle AI")
	static UVH_VehiclePathFollowingComponent* GetVehiclePathFollowingComponent(APawn* Pawn);

	/* Converts the input velocity into the output velocity. Used to change between units of data */
	UFUNCTION(BlueprintPure, Category = "Vehicle AI")
	static float ConvertVelocityByUnit(float InputVelocity, EUnitOfSpeed InputVelocityType, EUnitOfSpeed OutputVelocityType);

	/* Converts the steering of a vehicle into one usable for a tank */
	UFUNCTION(BlueprintPure, Category = "Vehicle AI")
	static void ConvertToTankSteering(float InSteering, float InThrottle, float TurnInPlaceThreshold, float NormalTurnMultiplier, float & OutLeftTrack, float & OutRightTrack);

	/* Manually sets path points for the current path on an AI controller */
	UFUNCTION(BlueprintCallable, Category = "Vehicle AI")
	static bool SetPathPoints(AAIController* AIController, TArray<FVector> NewPathPoints);

	/* Sets a path onto a spline that an agent can follow */
	UFUNCTION(BlueprintCallable, Category = "Vehicle AI")
	static bool FollowSplinePath(AAIController* AIController, USplineComponent* Spline, float SpaceBetweenParts);

};

