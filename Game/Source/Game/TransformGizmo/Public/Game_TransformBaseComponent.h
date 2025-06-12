#pragma once

// Parent Includes
#include "Components/StaticMeshComponent.h"

// Game Includes
#include "Game_TransformGizmo_Enum.h"

// Generated Includes
#include "Game_TransformBaseComponent.generated.h"

// The distance between the start and end points of the input ray.
constexpr float RAY_END_DIST = 1000.0f;

// Constant used to ensure that the plane normal is correct (to perspective?)
// when transforming on a single axis.
constexpr float COS_45_DEG = 0.707106f;

// Base class for the transform gizmo's components.
UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_TransformBaseComponent : public UStaticMeshComponent
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

protected:
	// The axis on which this component performs its transformation.
	ETransformAxis Axis;

	// What origin the transformation is performed on.
	ETransformOrigin Origin;
	
	// How quickly the component changes its transform.
	float Sensitivity;

	// The starting point of the last motion controller ray used for transformation.
	FVector LastRayStart;

	// The ending point of the last motion controller ray used for transformation.
	FVector LastRayEnd;

	// Whether this component should be performing its transformation.
	bool bActive;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_TransformBaseComponent(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void TickComponent(float deltaSeconds, ELevelTick tickType, FActorComponentTickFunction* thisTickFunction) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	// Returns the primary axis vector that this component uses in its transformation.
	UFUNCTION(BlueprintPure)
	FVector GetAxisVector() const;

	// Sets the primary axis that this component uses in its transform.
	UFUNCTION(BlueprintCallable)
	void SetAxisType(const ETransformAxis& axis);

	UFUNCTION(BlueprintCallable)
	void SetTransformOrigin(const ETransformOrigin& origin);

	// Updates the component's rotation based on the current Axis.
	UFUNCTION(BlueprintCallable)
	virtual void UpdateComponentRotation() {};

	UFUNCTION(BlueprintCallable)
	void SetSensitivity(float sensitivity);

	void ResetLastRay();


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	void NotifyManipulationInProgress();

	// Extracts a ray from the motion controller's current position and orientation.
	void GetInputRay(FVector& start, FVector& end);

	// Implements this component's specific kind of transformation.
	virtual void PerformTransform();

	FTransform GetSelectedActorTransform() const;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	// Callback for when the component is clicked by a controller.
	UFUNCTION()
	void HandleClick(UPrimitiveComponent* touchedComponent, FKey buttonPressed);

	// Callback for when the component is released by a controller.
	UFUNCTION()
	void HandleRelease(UPrimitiveComponent* touchedComponent, FKey buttonReleased);
};
