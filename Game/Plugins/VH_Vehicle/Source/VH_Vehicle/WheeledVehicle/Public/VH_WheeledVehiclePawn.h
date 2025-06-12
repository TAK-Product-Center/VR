#pragma once

// Parent Includes
#include "WheeledVehiclePawn.h"

// Engine Includes
#include "CoreMinimal.h"

// Module Includes
#include "VH_VehicleAIInterface.h"

// Generated Includes
#include "VH_WheeledVehiclePawn.generated.h"

// Forward declarations
class UPhysicalMaterial;
class UCameraComponent;
class USpringArmComponent;
class UTextRenderComponent;
class UInputComponent;
class UAudioComponent;
class USceneCaptureComponent2D;
class USpotLightComponent;

PRAGMA_DISABLE_DEPRECATION_WARNINGS

UCLASS()
class VH_VEHICLE_API AVH_WheeledVehiclePawn : public AWheeledVehiclePawn, public IVH_VehicleAIInterface
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

protected:
	/** Spring arm that will offset the camera */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	/** Camera component that will be our viewpoint */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	/** Scene component for the In-Car view origin */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* InternalCameraBase;

	/** Steering wheel component */
	UPROPERTY(Category = Steering, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* SteeringWheelMesh;

	/** Camera component for the In-Car view */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* InternalCamera;

	/** Text component for the In-Car speed */
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* InCarSpeed;

	/** Text component for the In-Car gear */
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTextRenderComponent* InCarGear;

	/** Audio component for the engine sound */
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UAudioComponent* EngineSoundComponent;

	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USpotLightComponent* HeadlightLeft;

	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USpotLightComponent* HeadlightRight;

public:
	/** The current speed as a string eg 10 km/h */
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly)
	FText SpeedDisplayString;

	/** The current gear as a string (R,N, 1,2 etc) */
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly)
	FText GearDisplayString;

	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly)
	/** The color of the incar gear text in forward gears */
	FColor	GearDisplayColor;

	/** The color of the incar gear text when in reverse */
	UPROPERTY(Category = Display, VisibleDefaultsOnly, BlueprintReadOnly)
	FColor	GearDisplayReverseColor;

	/** Are we using incar camera */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly)
	bool bInCarCameraActive;

	/** Are we in reverse gear */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly)
	bool bInReverseGear;

	/** Initial offset of incar camera */
	FVector InternalCameraOrigin;

	/** Slippery Material instance */
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	UPhysicalMaterial* SlipperyMaterial;

	/** Non Slippery Material instance */
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	UPhysicalMaterial* NonSlipperyMaterial;

	/** How fast the steering wheel will turn towards the steering input. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	float SteeringWheelInterpSpeed;

	/** How fast the steering wheel will turn towards the steering input. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	float SteeringWheelRotationScale;

	/** How fast the steering wheel will turn towards the steering input. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MoveToHardSteeringAngle;

	/** Max throttle input provided for AI movement */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxThrottle;

	/** When vehicle speed is above this value, no further AI movement will be added. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxPathingSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float DrivingSpeedRPMScale;

	/** Multiplier that determines when to "step off" the max throttle. The higher the number, the sooner the vehicle will slow down when close to its goal. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float PathingSlowdownFactor;

	/** AI pathing will not apply the brakes when vehicle forward speed is above this value */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float PathingSlowdownSpeed;

	/** When to clamp down the max throttle when turning and making a sharp turn. Only affects pathing behavior. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float HighSpeedSteerThreshold;

	/** When to clamp down the max throttle when turning and making a sharp turn. Only affects pathing behavior. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float HighSpeedSteeringFactor;

	static const FName LookUpBinding;
	static const FName LookRightBinding;
	static const FName EngineAudioRPM;

private:
	/** Are we on a 'slippery' surface */
	bool bIsLowFriction;

	/** The roll added to the steering wheel for animation purposes. Is interpolated over time. */
	float SteeringWheelTurnRoll;

	FQuat InitSteeringWheelRotation;

	TArray<FVector> LeadLocations;
	int32 LeadLocationIndex;
	float MaxDrivingSpeed;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AVH_WheeledVehiclePawn(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------
	
public:
	virtual void BeginPlay() override;
	
	virtual void Tick(float deltaSeconds) override;

	virtual void SetupPlayerInputComponent(UInputComponent* inputComponent) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/** Handle pressing forwards */
	void MoveForward(float val);

	/** Handle pressing right */
	void MoveRight(float val);

	/** Handle handbrake pressed */
	void OnHandbrakePressed();

	/** Handle handbrake released */
	void OnHandbrakeReleased();

	/** Switch between cameras */
	void OnToggleCamera();

	/** Handle reset VR device */
	void OnResetVR();

	/** Setup the strings used on the hud */
	void SetupInCarHUD();

	/** Update the physics material used by the vehicle mesh */
	void UpdatePhysicsMaterial();

	/** Used by AI Controller for pathing */
	void UpdateMoveToThrottle(const FVector TargetLocation, float inTargetRadius);

	/** Used by AI Controller for pathing */
	void SteerTowardsMoveToTarget(const FVector TargetLocation);

	UFUNCTION(BlueprintImplementableEvent)
	USceneCaptureComponent2D* GetLeftSceneCaptureComponent() const;

	UFUNCTION(BlueprintImplementableEvent)
	USceneCaptureComponent2D* GetRightSceneCaptureComponent() const;

	UFUNCTION(BlueprintCallable)
	void SetHeadlightsEnabled(bool inEnabled);

	UFUNCTION(BlueprintCallable)
	void SetMaxDrivingSpeed(const float inSpeed, const EUnitOfSpeed inUnit);

	UFUNCTION(BlueprintCallable)
	float GetMaxDrivingSpeed() const { return MaxDrivingSpeed; };

	UFUNCTION(BlueprintCallable)
	bool TeleportLeadVehicleToRoute(const FTransform playerTransform, const bool matchPlayerRotation, const float desiredDistanceToPlayer);

	/** Returns SpringArm subobject **/
	UFUNCTION(BlueprintPure, category = "Camera")
	FORCEINLINE USpringArmComponent* GetSpringArm() const { return SpringArm; }

	/** Returns Camera subobject **/
	UFUNCTION(BlueprintPure, category = "Camera")
	FORCEINLINE UCameraComponent* GetCamera() const { return Camera; }

	/** Returns InternalCamera subobject **/
	UFUNCTION(BlueprintPure, category = "Camera")
	FORCEINLINE UCameraComponent* GetInternalCamera() const { return InternalCamera; }

	/** Returns steering wheel mesh subobject **/
	UFUNCTION(BlueprintPure, category = "Steering")
	FORCEINLINE UStaticMeshComponent* GetSteeringWheel() const { return SteeringWheelMesh; }

	/** Returns InCarSpeed subobject **/
	UFUNCTION(BlueprintPure, category = "Display")
	FORCEINLINE UTextRenderComponent* GetInCarSpeed() const { return InCarSpeed; }

	/** Returns InCarGear subobject **/
	UFUNCTION(BlueprintPure, category = "Display")
	FORCEINLINE UTextRenderComponent* GetInCarGear() const { return InCarGear; }

	/** Returns EngineSoundComponent subobject **/
	UFUNCTION(BlueprintPure, category = "Display")
	FORCEINLINE UAudioComponent* GetEngineSoundComponent() const { return EngineSoundComponent; }

	UFUNCTION(BlueprintCallable)
	void SetLeadVehicleFollowPoints(const TArray<FVector>& worldLocations);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	/** 
	 * Activate In-Car camera. Enable camera and sets visibility of incar hud display
	 *
	 * @param	bState true will enable in car view and set visibility of various
	 */
	void EnableIncarView( bool bState);

	/** Update the gear and speed strings */
	void UpdateHUDStrings();

	/** Update the rotation of the steering wheel mesh component */
	void UpdateSteeringWheelRotation(float deltaSeconds);

	void HandleLeadAI(float deltaSeconds);
};

PRAGMA_ENABLE_DEPRECATION_WARNINGS
