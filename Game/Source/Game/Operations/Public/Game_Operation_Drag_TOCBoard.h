#pragma once

// Parent Includes
#include "Game_Operation_Drag.h"

// Engine Includes
#include "Engine/HitResult.h"

// Required Includes
#include "Game_Operation_Drag_TOCBoard.generated.h"

class UPhysicsHandleComponent;
class AGame_Tool;
class AGame_SnapLocation;

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_Operation_Drag_TOCBoard : public UGame_Operation_Drag
{
	GENERATED_BODY()
	

	// ---------------------------------
	// --- Variables
	// ---------------------------------

protected:
	/* Maximum distance that an object will be held at in front of a player (aka current distance held) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxInteractionDistance;

	/* Minimum distance that an object will be held at in front of a player */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinInteractionDistance;

	/* Maximum distance that objects behind the held object will be used to adjust the held object */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxAdjustmentDistance;

	/* Multiplier that changes interaction/adjustment distances when zooming board in/out */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InteractionDistanceMultiplier;

	/* Determines whether to grab at the center of the object or at the interacted point */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bGrabCenterPoint;

private:
	/* Used to gate updates until coordinator has fully initialized */
	bool bCanTick;

	/* Used to set the snap location only once to prohibit jittering between snap and cursor locations */
	bool bSetSnapLocOnce;

	bool bPickedUpObj;

	UPROPERTY()
	AActor* ActorToPlace;

	UPROPERTY()
	AActor* HeldObj;

	UPROPERTY()
	UPrimitiveComponent* HeldObjComp;

	UPROPERTY()
	AGame_SnapLocation* SnapLocationObj;

	FVector GrabLocationPoint;

	/* Used to adjust the board to its center when snapping to a location */
	FVector GrabLocationAdjustment;

	UPhysicsHandleComponent* PhysicsHandle;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_Operation_Drag_TOCBoard(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void PostStop() override;

	virtual void PostTick(float deltaSeconds) override;

	virtual void ActionInput_Implementation(const FInputActionInstance& inputActionInstance) override;

	virtual void PostStartDragInternal() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	/*
	 * Handles default movement of the held object if nothing was hit by the trace
	 */
	void DefaultMovement();

	/*
	 * Handles snap movement of the held object when placing it over a snap location
	 */
	void SnapLocationMovement(const FHitResult& adjustmentHitResult);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	bool GetHitResult(FHitResult& hitResult, float distance) const;
};

