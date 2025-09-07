#pragma once

// Parent Includes
#include "Components/SceneComponent.h"

// Generated Includes
#include "Developer_CameraScalingComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class VH_DEVELOPER_API UDeveloper_CameraScalingComponent : public USceneComponent
{
    GENERATED_BODY()	


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	/* if true, component rotates to face player camera */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bRotate;

	/* if true, component scaled based on scaling parameters */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bScale;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector2D MinMaxCameraDistanceForScaling;

	/* scale when distance <= MinCameraDistanceForScaling */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector MinScale;

	/* scale when distance >= MaxCameraDistanceForScaling */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector MaxScale;

	/* across the board multiplier when determining scale */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	double CustomScaleMultiplier;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
    UDeveloper_CameraScalingComponent(const FObjectInitializer& objectInitializer);


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
	virtual FVector GetScaleForDistance(double distanceUU) const;

	virtual double GetDistance() const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	virtual bool InView() const;

	virtual FRotator GetRotateWorldRotation() const;

	virtual FVector GetUpVector() const;

	virtual void PostTickDistance(double distance);

    /* Updates scale on Tick based on GetDistance() */
    void ScaleToCamera(double distance);

    /* Sets rotation towards GetRotateToWorldLocation() */
    void RotateToCamera();
};
