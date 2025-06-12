#pragma once

// Parent Includes
#include "GameFramework/FloatingPawnMovement.h"

// Generated Includes
#include "VR_MovementComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class VH_VR_API UVR_MovementComponent : public UFloatingPawnMovement
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Delegates
	// ---------------------------------

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWorldTransformOverrideUpdated, const FTransform&, worldTransformOverride);

	UPROPERTY(BlueprintAssignable)
	FOnWorldTransformOverrideUpdated OnWorldTransformOverrideUpdated;


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	/* scales movement in particular world direction; set to 0 to disable movement on particular axis */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector MovementDirectionMultiplier;

	/* acceleration vector applied each tick;  units are UnrealUnits / second / second. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector Gravity;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double GroundCheckDistance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bInstantAcceleration;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bInstantDeceleration;

private:
	FTransform WorldTransformOverride;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UVR_MovementComponent(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void AddInputVector(FVector worldVector, bool bForce) override;

protected:
	virtual void ApplyControlInputToVelocity(float deltaSeconds) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void SetWorldTransformOverride(const FTransform& worldTransformOverride);

	UFUNCTION(BlueprintPure)
	FTransform GetWorldTransformOverride() const;

	virtual void PostSetWorldTransformOverride(const FTransform& worldTransformOverride);
};
