#pragma once

// Engine
#include "CoreMinimal.h"
#include "UObject/Interface.h"

// Generated
#include "VH_VehicleAIInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable)
class VH_VEHICLE_API UVH_VehicleAIInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class VH_VEHICLE_API IVH_VehicleAIInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	/* 
	* Called when the vehicle gets stuck according to the stuck detection
	* @param UnStuckLocation - The location we want to move to, to get this actor unstuck, this is for simple unstuck custom behavior
	* @return true will keep the vehicle in a stuck state until you manually notify. False (default) will handle the stuck behavior internally
	*/
	UFUNCTION(BlueprintNativeEvent, Category = "Vehicle AI")
	bool OnVehicleStuck(FVector& UnStuckLocation);

	/*
	* Called to implement custom steering behavior
	* @param TargetAngle - Angle towards the target move location
	* @param Steering - Normalized adjusted steering angle, this is whats normally used by the system internally
	* @param DestinationDistance - Distance to the current move destination
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "Vehicle AI")
	void CustomSteering(float TargetAngle, float Steering, float DestinationDistance);

	/*
	* Called to implement custom steering behavior
	* @param TargetAngle - Angle towards the target move location
	* @param DestinationDistance - Distance to the current move destination
	* @param DesiredSpeed - The adjusted desired speed
	* @param CalculatedThrottle - The throttle thats been calculated, this is whats normally used by the system internally
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "Vehicle AI")
	void CustomThrottle(float TargetAngle, float DestinationDistance, float DesiredSpeed, float CalculatedThrottle);

	/*
	* Called to implement custom braking behavior
	* @param TargetAngle - Angle towards the target move location
	* @param DestinationDistance - Distance to the current move destination
	* @param DesiredSpeed - The adjusted desired speed
	* @param CalculatedThrottle - The throttle thats been calculated, this is whats normally used by the system internally
	*/
	UFUNCTION(BlueprintImplementableEvent, Category = "Vehicle AI")
	void CustomBraking(float TargetAngle, float DestinationDistance, float DesiredSpeed, float CalculatedBrake);

};

