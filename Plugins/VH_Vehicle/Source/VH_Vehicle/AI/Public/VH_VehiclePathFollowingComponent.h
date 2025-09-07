#pragma once

// Engine
#include "Navigation/CrowdFollowingComponent.h"

// Module
#include "VH_PIDController.h"
#include "VH_VehicleEnums.h"

// Generated
#include "VH_VehiclePathFollowingComponent.generated.h"

// Declares the stat group for CPU performance tracking
DECLARE_STATS_GROUP(TEXT("Vehicle Path Following"), STATGROUP_VehiclePathFollowing, STATCAT_Advanced);

class UCurveFloat;

// ---------------------------------
// --- Struct
// ---------------------------------

/* Defines a set of properties that changes how this vehicle handles */
USTRUCT(BlueprintType)
struct FVehicleHandlingConfig
{
	GENERATED_BODY()

	/////// Speed Control //////////

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed Control")
	float MinThrottle = 0.1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed Control")
	float DesiredSpeedThreshold = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed Control")
	FPIDCoefficients ThrottlePIDConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed Control")
	bool bUseBrakes = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed Control")
	float BrakeThreshold = 300.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed Control")
	float BrakeAmount = 0.5f;

	/////// Slowdown //////////

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed Control")
	bool bEnableSlowdown = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed Control")
	float SlowdownDistance = 4000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed Control")
	int CornerSlowdownSamples = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed Control")
	float MaxCornerSpeed = 200.f;

	/////// Steering Control //////////

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Steering Control")
	FPIDCoefficients SteeringPIDConfig = FPIDCoefficients(1.f, 0.1f, 0.f);
};

/**
 * Handles the path following for a wheeled vehicle. Inherits from Crowd Following for Detour Crowd control
 */
UCLASS()
class VH_VEHICLE_API UVH_VehiclePathFollowingComponent : public UCrowdFollowingComponent
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	////////////////////////////////////
	//  Path Following
	////////////////////////////////////

	/* Changes the acceptance radius from the defaults set in the project settings */
	UPROPERTY(EditDefaultsOnly, Category = "Path Following")
	bool bUseCustomAcceptanceRadius = false;

	/* The acceptance radius for an individual path point */
	UPROPERTY(EditDefaultsOnly, Category = "Path Following")
	float VehiclePathPointAcceptanceRadius = 50.f;

	/* The acceptance radius for an navigation link */
	UPROPERTY(EditDefaultsOnly, Category = "Path Following")
	float VehicleNavLinkAcceptanceRadius = 50.f;

	////////////////////////////////////
	//  Custom Handling
	////////////////////////////////////

	/* Let an interface on the agent handle the steering output */
	UPROPERTY(EditDefaultsOnly, Category = "Custom Handling")
	bool bCustomSteering = false;

	/* Let an interface on the agent handle the throttle output */
	UPROPERTY(EditDefaultsOnly, Category = "Custom Handling")
	bool bCustomThrottle = false;

	/* Let an interface on the agent handle the brake output */
	UPROPERTY(EditDefaultsOnly, Category = "Custom Handling")
	bool bCustomBrake = false;

	////////////////////////////////////
	//  Speed Control
	////////////////////////////////////

	/* Minimum throttle to step down to when controlling speed. Don't set the value too low or the vehicle might not move */
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float MinThrottle = 0.1f;

	/* Curve that changes the percentage of the desired speed (0 -> 1) based on the normalised steering angle (0 -> 1)
	This property will be deprecated in a future release as it doesn't seem to be that useful and getting the same functionality can be done using
	the blueprint interface. If you are actively using this feature and would not like it removed, then */
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control|Deprecated")
	UCurveFloat* DesiredSpeedCurve;

	/* Threshold where throttle will be adjusted for meet the desired speed */
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control|Desired Speed")
	float DesiredSpeedThreshold = 10.f;

	/* The starting desired speed of this vehicle, the units of which are defined by the Start Speed Unit */
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control|Desired Speed")
	float StartingDesiredSpeed = 1000.f;

	/* The speed units this vehicle will use when the desired speed */
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control|Desired Speed")
	EUnitOfSpeed StartSpeedUnit = EUnitOfSpeed::CentimetersPerSecond;

	/* The speed of this vehicle in cm/s, speed is always converted into cm/s in the plugin as this is the default velocity units
	This value changes as the Starting Desired Speed changes and/or its units change */
	UPROPERTY(VisibleAnywhere, Category = "Speed Control|Desired Speed")
	float DesiredSpeed = 1000.f;
	
	/* The amount of change the throttle by each frame to keep the speed within the threshold */
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control|Throttle")
	float DesiredSpeedThrottleStepMax = 0.05f;

	/* The amount of change the throttle by each frame to keep the speed within the threshold */
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control|Throttle")
	float DesiredSpeedThrottleStepMin = 0.001f;

	/* When the speed is above or below this value, use the full throttle value */
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control|Throttle")
	float DesiredSpeedThrottleThreshold = 300.f;

	/* Steps the throttle up or down to make the agent meet the desired speed */
	float AdjustThrottleForDesiredSpeed(float InDesiredSpeed);

	/* Whether this AI is allowed to use its brakes  */
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control|Brakes")
	bool bUseBrakes = true;

	/* The threshold above the desired speed (+ speed threshold) at which to apply the brakes
	*  Decrease this if the vehicle doesnt apply brakes quickly enough 	*/
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control|Brakes")
	float BrakeThreshold = 300.f;

	/* If the normalized turn value is greater than this you can force the throttle to be off (where 1 is fully right and -1 is fully left)
	*  then we don't want to accelerate anymore as it means the vehicle will miss its turning.
	*  Reduce this if the vehicle keeps overshooting corners
	*/
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control|Throttle")
	float NormalisedTurnThreshold = 1.f;
	
	/* The amount of intensity you want the brakes to apply when using brakes to slow down, use higher values if you want the brakes to be applied
	   more aggressively such as in a racing game */
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control|Brakes", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float BrakeAmount = 0.5f;

	/* The amount of intensity you want the brakes to apply if normal braking wouldn't slow the vehicle down in time */
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control|Brakes", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float MaxEmergencyBrakeAmount = 1.0f;

	/* Should throttle use a PID controller, instead of any other method. The other method just steps up and down the throttle
	*  to get to the desired speed, which can in some cases work better (especially with abnormal vehicle types) 
	*/
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control")
	bool bThrottleUsePID = true;

	/* Sets up each coefficient for the throttle PID controller
	*  P: Proportional to the amount needed to speed up, generally fine left as 1
	*  I: Adjust this value if the throttle keeps oscillating (increase in small intervals 0.1)
	*  D: Generally not needed, but increase if I doesn't fix the oscillating
	*/
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control")
	FPIDCoefficients ThrottlePIDSetup = FPIDCoefficients(1.f, 0.1f, 0.f);

	/* The PID controller used for the Throttle */
	FPIDController ThrottlePID;

	/* This is an experimental setting to calculate the maximum speed the vehicle can take a corner with the given parameters.
	*  It hasn't been tested in enough scenarios to enable as default yet, but if you want to try it out on your project it could greatly improve cornering
	*  with no additional steps required. This also does have a slightly bigger impact on performance too, but its relatively negligible. 
	*  This uses the physical properties of the vehicle such as its mass and the friction coefficient to calculate things like stopping distance. The goal here is to use
	*  physical values that are pulled directly from the vehicle, so that very little manual tweaking is required to get it working 
	*/
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control|Advanced")
	bool bUseAdvancedSpeedControl = false;

	/* This is the value that the speed control scales by when using the advanced control, 1 means it goes the max speed it physically can around a corner
	*  (within the desired speed), but the default of 0.5 means it should easily follow the path exactly around a corner.
	* 
	*  Tweaking:
	* 
	*  Vehicle doesn't follow corner precisely enough: Reduce
	*  Vehicle goes around corners too slowly: Increase (until it starts to not handle very well)
	*/
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control|Advanced", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float CornerSpeedControlPercentage = 0.5f;

	/* Automatically calculates the slowdown distance instead of having a fixed value, generally want this on if using advanced speed control
	and it is enabled by default but you can disable it to maintain the older functionality */
	UPROPERTY(EditDefaultsOnly, Category = "Speed Control|Advanced")
	bool bAutoCalculateSlowdownDistance = true;

public:

	/* The mass of the vehicle being used, can be changed if using a different vehicle setup */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Speed Control|Advanced")
	float VehicleMass = 1500.f;

	/* The coefficient of static friction of the type and road surface */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Speed Control|Advanced")
	float StaticFrictionCoefficient = 0.7f;

	/* The world gravity, if you use a custom gravity setting you can change this here */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Speed Control|Advanced")
	float WorldGravity = 980.f;

private:

	////////////////////////////////////
	//  Slowdown System
	////////////////////////////////////

	/* Enables the ability to slowdown at the final destination, generally you want this on unless
	*  you want to control this yourself using the interface */
	UPROPERTY(EditAnywhere, Category = "Slowdown")
	bool bEnableSlowdown = true;

	/* The vehicle will attempt to slow down at path points that are Nav Links, this is important if   */
	UPROPERTY(EditAnywhere, Category = "Slowdown")
	bool bSlowdownAtNavLinks = true;

	/* The distance at which to start the slowdown, the greater this is, the smoother the slowdown is,
	   especially at higher speeds */
	UPROPERTY(EditAnywhere, Category = "Slowdown")
	float SlowdownDistance = 2000.f;

	/* The number of samples taken to calculate the speed at which to slow down
	   they are only included if within the slowdown distance. This helps a vehicle get
	   around a corner which could be made up of multiple path points, close together. This is mainly here for performance reasons*/
	UPROPERTY(EditAnywhere, Category = "Slowdown")
	int CornerSlowdownSamples = 8;

	/* The maximum speed that a corner of 180 degrees will be taken.
	   For example if the desired speed is 1000cm/s and the corner is at 90 degrees, this will result in
	   a desired speed of 600cm/s. This value is overridden if using the advanced speed control method. */
	UPROPERTY(EditAnywhere, Category = "Slowdown")
	float MaxCornerSpeed = 200.f;

	/* How far ahead to sample path point corners to start the slow down, defaults to 200m
	Increase this if the vehicle is emergency braking too much */
	UPROPERTY(EditAnywhere, Category = "Slowdown|Advanced")
	float AverageCornerSampleRange = 2000.f;

	/* The average angle ahead within the sample range */
	float AverageAheadAngle = 0.f;

	/* The last sample index used by the slowdown system, used for debugging */
	int SlowdownSampleIndex = 0;

	/* The largest angle ahead of the vehicle that has been calculated within the slowdown range */
	float SlowdownAngle = 0.f;

	/* The final points distance away */
	float FinalDestinationDistance = 0.f;

	////////////////////////////////////
	//  Stuck Detection System
	////////////////////////////////////

	/* Is this vehicle currently stuck and unable to move? */
	bool bIsStuck = false;

	/* Amount of samples in an array to use for stuck detection */
	UPROPERTY(EditDefaultsOnly, Category = "Stuck Detection")
	int StuckDetectionSampleCount = 8;

	/* used to determine the next index of the array to populate with a stuck location */
	int NextStuckSampleIdx = 0;

	/* Sample of vectors used to decide if the agent is stuck */
	TArray<FVector> StuckLocationSamples;

	/* The last time a sample of the location was taken */
	float LastStuckSampleTime;

	/* Enables detecting when this agent hasn't moved in a while, then executing the UnStuck code */
	UPROPERTY(EditDefaultsOnly, Category = "Stuck Detection")
	bool bUseStuckDetection = true;

	/* The location when we're stuck we want to move to */
	FVector UnStuckDestination;

	/* If true this vehicle is manually executing unstuck code */
	bool bManualUnStuck = false;

	/* Calculates a destination to move to which will stop this vehicle being stuck, default implementation just finds distance behind it */
	FVector CalculateUnStuckDestination();

	/* Distance to try and move when stuck */
	UPROPERTY(EditDefaultsOnly, Category = "Stuck Detection")
	float UnStuckDistance = 500.f;

	/* Distance at which the agent will be classified as stuck */
	UPROPERTY(EditDefaultsOnly, Category = "Stuck Detection")
	float StuckDetectionDistance = 100.f;

	/* Distance at which to stop and recheck if stuck */
	UPROPERTY(EditDefaultsOnly, Category = "Stuck Detection")
	float StuckAcceptanceRadius = 50.f;

	/* Time interval when to add to the stuck sample array */
	UPROPERTY(EditDefaultsOnly, Category = "Stuck Detection")
	float StuckDetectionInterval = 0.5f;

	/* Updates the location samples for stuck checking, returns true if it was updated  */
	bool UpdateStuckSamples();

	////////////////////////////////////
	//  Crowd Agent Properties
	////////////////////////////////////

	/* Enables crowd simulation */
	UPROPERTY(EditDefaultsOnly, Category = "Crowd Following")
	E_CrowdSimulationState DetourCrowdSimulationState = E_CrowdSimulationState::Disabled;

	/* Multiplies the range at which the crowd simulation will attempt to avoid obstacles, use this if the vehicle is crashing into obstacles during crowd simulation */
	UPROPERTY(EditDefaultsOnly, Category = "Crowd Following")
	float CrowdAvoidanceRangeMultiplier = 2.0f;

	/* The maximum speed this vehicle is able to get to. Used by crowd following for collision sampling */
	UPROPERTY(EditDefaultsOnly, Category = "Crowd Following")
	float VehicleMaxSpeed = 1000.f;

	/////// Reverse Handling //////////

	/* If the angle to the target is greater than this, the vehicle will reverse to the target point */
	UPROPERTY(EditDefaultsOnly, Category = "Reverse", meta = (ClampMin = "0.0", ClampMax = "180.0"))
	float ShouldReverseAngle = 140.f;

	/* If the distance is lower than this then the vehicle will reverse to the target point */
	UPROPERTY(EditDefaultsOnly, Category = "Reverse")
	float ReverseMaxDistance = 1000.f;

	/* Threshold to toggle the reverse state */
	UPROPERTY(EditDefaultsOnly, Category = "Reverse", meta = (ClampMin = "0.0", ClampMax = "180.0"))
	float ReverseThreshold = 40.f;

	/* Allow the vehicle to automatically reverse whenever it meets the reverse conditions */
	UPROPERTY(EditDefaultsOnly, Category = "Reverse")
	bool bAutoReverse = true;

	/* Only let this vehicle reverse when its in a stuck position, bAllowReverse must be set to true! */
	UPROPERTY(EditDefaultsOnly, Category = "Reverse")
	bool bOnlyReverseWhenStuck = false;

	/* Flag set to true if reversing, used with the threshold */
	bool bReversing = false;

	/* Checks if this vehicle should reverse */
	bool ShouldReverse(float TurnAngle, float TargetDistance);

	/* Flag that should be set if you want to force reverse */
	bool bWantsReverse;

	////////////////////////////////////
	//  Steering Control
	////////////////////////////////////

	/* The muliplier used to increase steering based on on the size of the angle if there is no curve (normalised steering * multiplier) */
	UPROPERTY(EditDefaultsOnly, Category = "Steering", meta = (DeprecatedProperty, DeprecationMessage = "Use the Steering PID controller instead"))
	float SteeringMultiplier = 2.f;

	/* How steering output is adjusted based on the size of the angle. */
	UPROPERTY(EditDefaultsOnly, Category = "Steering", meta = (DeprecatedProperty, DeprecationMessage = "The steering curve is relatively complicated and unnecessary and will be removed, if you still want this functionality, implement this with the interface"))
	UCurveFloat* SteeringCurve;

	/* Should steering use a PID controller, instead of any other method */
	UPROPERTY(EditDefaultsOnly, Category = "Steering", meta = (DeprecatedProperty, DeprecationMessage = "The steering will use the PID controller as default in a future version, the old method is just the proportional part of the PID controller"))
	bool bSteeringUsePID = true;

	/* Sets up each coefficient for the steering PID controller */
	UPROPERTY(EditDefaultsOnly, Category = "Steering")
	FPIDCoefficients SteeringPIDSetup = FPIDCoefficients(2.f, 0.2f, 0.f);

	/* The PID controller used for steering */
	FPIDController SteeringPID;

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UVH_VehiclePathFollowingComponent(const FObjectInitializer& objectInitializer);

	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent);

protected:
	/** follow current path segment */
	virtual void FollowPathSegment(float DeltaTime) override;

	/** check state of path following, update move segment if needed */
	virtual void UpdatePathSegment() override;

	/** sets properties relating to path following */
	virtual void SetMoveSegment(int32 SegmentStartIndex) override;

	/** notify about finished movement */
	virtual void OnPathFinished(const FPathFollowingResult& Result) override;

	/** Initialize all of the variables */
	virtual void Initialize() override;

	/* Default implementation uses a character movement component so won't work properly. We'll use the RVO groups on the vehicle component instead */

// ICrowdAgentInterface BEGIN
	virtual FVector GetCrowdAgentLocation() const override;
	virtual FVector GetCrowdAgentVelocity() const override;
	virtual float GetCrowdAgentMaxSpeed() const override;
	virtual int32 GetCrowdAgentAvoidanceGroup() const override;
	virtual int32 GetCrowdAgentGroupsToAvoid() const override;
	virtual int32 GetCrowdAgentGroupsToIgnore() const override;
	// ICrowdAgentInterface END

	// ---------------------------------
	// --- API
	// ---------------------------------
	
public:
	/* Get data about a path point by supplying an index. Useful when you want to look up data ahead on a path for a vehicle so you can make speed adjustments */
	UFUNCTION(BlueprintPure, Category = "Vehicle AI|Helpers")
	bool GetPathPointDataByIndex(int Index, FVector &PointLocation, class UClass* &AreaClass, bool &bIsOnNavLink);

	/* Calculates the distance it will take for a vehicle to stop within, based on the intensity of braking */
	float CalculateStoppingDistance(float BrakingIntensity, float FrictionCoefficient, float Velocity);

	/* Gets the upcoming path points and samples them by distance to work out what the curve will be and then returns it */
	float CalculateCurveRadius(FVector PointA, FVector PointB);

	/* Calculates the maximum speed that the vehicle can go around a corner without tipping over */
	float GetMaximumCorneringSpeed(float CurveRadius);

	/////// Reverse //////////

	/**
	* Set this agent to force reverse manually
	* @param Reverse - Toggle the force reverse
	*/
	UFUNCTION(BlueprintCallable, Category = "Vehicle AI|Reverse")
		void SetReverse(bool Reverse);

	/**
	* Toggles the automatic reverse capability
	* @param Reverse - Toggle the automatic reverse
	*/
	UFUNCTION(BlueprintCallable, Category = "Vehicle AI|Reverse")
		void SetAutoReverse(bool Reverse);


	/**
	* Toggles the automatic reverse capability
	* @param Reverse - Toggle the automatic reverse
	*/
	UFUNCTION(BlueprintPure, Category = "Vehicle AI|Reverse")
		bool IsReversing();

	/**
	* Toggles the ability to face a direction when at a target location
	* @param bActive - Toggles the rotation ability
	* @param WorldRotation - The rotation the vehicle should face
	*/
	UFUNCTION(BlueprintCallable, Category = "Vehicle AI|Reverse")
		void SetDestinationRotation(bool bActive, FRotator WorldRotation);

	/////// Minor sub-section //////////
	/* Speed Control */

	/**
	* Updates this agents desired speed
	* @param NewSpeed - Defines the new speed, given in Unreal Units (cm/s)
	* @param Unit - The units of data to use for the speed conversion which is done internally
	*/
	UFUNCTION(BlueprintCallable, Category = "Vehicle AI|Speed Control")
		void SetDesiredSpeed(float NewSpeed, EUnitOfSpeed Unit);


	/////// Avoidance //////////

	/**
	* Update the crowd simulation, allows for setting crowd simulation on a per agent basis
	* @param NewState - Changes the crowd simulation state
	*/
	UFUNCTION(BlueprintCallable, Category = "Vehicle AI|Avoidance")
		void SetVehicleCrowdSimulation(E_CrowdSimulationState NewState);


	/////// Minor sub-section //////////
	/* Control */

	/**
	* Toggles this vehicle to use custom controls at runtime. Useful if you need to use specific custom controlling at a particular event
	* @param bToggleCustomSteering - Toggles the custom steering
	* @param bToggleCustomThrottle - Toggles the custom throttle setting
	* @param bToggleCustomBrake - Toggles the custom brake setting
	*/
	UFUNCTION(BlueprintCallable, Category = "Vehicle AI|Control")
		void SetCustomControl(bool bToggleCustomSteering, bool bToggleCustomThrottle, bool bToggleCustomBrake);

	/////// Stuck detection //////////

	/**
	* Toggles this vehicles stuck detection, which you might want to disable in certain scenarios
	* @param bActive - Toggles the stuck detection
	*/
	UFUNCTION(BlueprintCallable, Category = "Vehicle AI|Stuck Detection")
		void SetStuckDetection(bool bActive);

	/**
	* Sets the stuck status of this vehicle. Use to manually perform unstuck behaviour. Can also implement custom stuck behavior
	* @param NewStuckState - Sets if this vehicle is stuck or not
	*/
	UFUNCTION(BlueprintCallable, Category = "Vehicle AI|Stuck Detection")
		void SetStuckStatus(bool NewStuckState);

	/**
	* Checks if this vehicle is stuck (on path but hasn't moved in a while according to sample data)
	* @return true if the vehicle is stuck
	*/
	UFUNCTION(BlueprintPure, Category = "Vehicle AI|Stuck Detection")
		bool IsStuck();

	/**
	* Returns the handling configuration for this vehicle
	* @return the current handling configuration
	*/
	UFUNCTION(BlueprintCallable, Category = "Vehicle AI|Stuck Detection")
		FVehicleHandlingConfig GetHandlingConfig();

	/**
	* Set a handling configuration profile onto this controller
	* @param HandlingConfig
	*/
	UFUNCTION(BlueprintCallable, Category = "Vehicle AI|Stuck Detection")
		void SetHandlingConfig(FVehicleHandlingConfig HandlingConfig);

	// ---------------------------------
	// --- Implementation
	// ---------------------------------

	/* Main steering and throttle update method */
	void UpdateDriving(FVector Destination, float DeltaTime);

	/* Update methods that pass this information to a component or pawn via an interface, call this instead of directly */
	void SetSteering(float Steering);
	void SetThrottle(float Throttle);
	void SetBrakes(float Brakes);

	/* Returns the maximum speed allowed to slow down in time to get to the next point  */
	float GetDesiredSlowdownSpeed(float DistanceToNextPoint);

	/* Returns the largest angle based on the number of samples and slowdown distance */
	float CalculateLargestAngleWithSamples();

	/* Calculates the average angle ahead with a number of fixed samples */
	float CalculateAverageAngleWithSamples();

	/* Calculates the maximum speed around a corner based on the corner angles as determined by the angle */
	float CalculateMaximumSpeedWithSamples();

	/* returns true if the controlled pawn implements the interface */
	bool DoesControlledPawnImplementInterface();

	/* returns a normalised value of a turn between 0 -> 180. Only use absolute values */
	float GetNormalisedValue(float Turn);

	/* returns the distance to the next Navigation Link on the path, used for calculating the slowdown for NavLinks which helps it take junctions */
	float GetNextNavLinkDistance();

	/* Holds the distance to the next NavLink on the path */
	float NextNavLinkDistance = 0.f;

	/* Returns the agents controlled pawn */
	APawn* GetControlledPawn();

	/* Cached pointer for the controlled pawn */
	APawn* ControlledPawn;

	/* Helper to return the agents current location in the world */
	FVector GetAgentLocation();

	/* The throttle value thats been calculated by the calculate throttle */
	float CalculatedThrottleValue;

	/* Calculate the throttle based on the angle to the destination  */
	float CalculateThrottle(float DestinationAngle);

	/* returns the angle delta between the two vectors, used for figuring out the turn angles */
	float GetVectorAngle(FVector A, FVector B);

	/* Returns the distance between this agent and the destination */
	float CalculateDestinationDistance(FVector Destination);

	/* Returns the angle between the agent and the destination from -180 to +180 */
	float CalculateDestinationAngle(FVector Destination);

	/* returns the angle to the next point on the path if valid, 0 if invalid */
	float AngleToNextPathPoint();

	/* Use the rotation when a destination is reached to face a particular way */
	bool bUseRotation;

	/* The rotation used for the final destination point */
	FRotator DestinationRotation;

	/* Update Driving Cached Values*/

	float TargetAngle;
	float DestinationDistance;
	float AdjustedDesiredSpeed;

	bool bImplementsInterface;

	// ---------------------------------
	// --- Debug/Testing
	// ---------------------------------

protected:
	/* Shows debug data on screen for this agent */
	UPROPERTY(EditDefaultsOnly, Category = "Debug")
	bool bDebug = false;

public:
	/**
	* Toggles the debug state on this agent. Debug shows information such as target angle, desired speed etc.
	* @param bActive - Toggles whether the debug is active
	*/
	UFUNCTION(BlueprintCallable, Category = "Vehicle AI|Debug")
	void ToggleDebug(bool bActive);

};
