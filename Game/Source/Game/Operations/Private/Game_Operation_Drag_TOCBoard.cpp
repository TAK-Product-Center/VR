// Required Includes
#include "Game_Operation_Drag_TOCBoard.h"
#include "Game.h"

// Engine Includes
#include "Kismet/GameplayStatics.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "InputAction.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/HitResult.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"

// VH Plugin Includes
#include "VR_TraceComponent.h"
#include "Developer_Statics.h"

// Game Includes
#include "Game_Tool.h"
#include "Game_SnapLocation.h"
#include "Game_TOCBoard.h"
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_Operation_Drag_TOCBoard::UGame_Operation_Drag_TOCBoard(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	MaxInteractionDistance(1200),
	MinInteractionDistance(400),
	MaxAdjustmentDistance(3000),
	InteractionDistanceMultiplier(1.1),
	bGrabCenterPoint(false),
	bSetSnapLocOnce(true),
	bPickedUpObj(false)
{
	
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_Operation_Drag_TOCBoard::PostStop()
{
	Super::PostStop();

	if (bPickedUpObj)
	{
		PhysicsHandle->ReleaseComponent();

		bPickedUpObj = false;

		HeldObjComp->SetAllPhysicsLinearVelocity(FVector(0, 0, 0), false);
		HeldObjComp->SetSimulatePhysics(false);

		HeldObjComp = nullptr;
	}

	if (ActorToPlace)
	{
		SnapLocationObj->SetCurrentHeldActor(ActorToPlace);
	}
}

void UGame_Operation_Drag_TOCBoard::PostTick(float deltaSeconds)
{
	if (bPickedUpObj && DraggedActor != nullptr && DraggingTool != nullptr)
	{
		FHitResult hitResult;
		if (GetHitResult(hitResult, MaxInteractionDistance * InteractionDistanceMultiplier))
		{
			// If trace hits the ground, ceiling, or snap location
			SnapLocationObj = Cast<AGame_SnapLocation>(hitResult.GetActor());

			if (FMath::Abs<double>(hitResult.Normal.Z) > 0.5 || SnapLocationObj)
			{
				SnapLocationMovement(hitResult);
			}
			// If trace hits a static object, rotate held object to normal to be flesh with it
			else
			{
				FTransform localToWorld = DraggingTool->VRTrace->GetComponentTransform();

				FVector newLoc = localToWorld.TransformPosition(FVector(MaxInteractionDistance, 0, 0));
				FRotator newRot = FRotationMatrix::MakeFromX(hitResult.Normal).Rotator();
				PhysicsHandle->SetTargetLocationAndRotation(newLoc, newRot);

				ActorToPlace = nullptr;

				bSetSnapLocOnce = true;
			}
		}
		else
		{
			DefaultMovement();
		}

		if (DraggedActor->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()))
		{
			IInterface_Developer_Manipulation::Execute_ManipulationInProgress(DraggedActor);
		}
	}
}

void UGame_Operation_Drag_TOCBoard::ActionInput_Implementation(const FInputActionInstance& inputActionInstance)
{
	FString action = inputActionInstance.GetSourceAction()->ActionDescription.ToString();

	if (action.Equals(TEXT("TOCBoard_Move")))
	{
		float value = inputActionInstance.GetValue().Get<float>();

		AGame_TOCBoard* tocBoard = Cast<AGame_TOCBoard>(DraggedActor);

		if (value > 0)
		{
			// If the held object did not hit something or if the held object is at the minimum distance, allow it to zoom out
			// Don't zoom out otherwise to prevent it from going through objects
			if (tocBoard->GetCanAdjustDist() || MaxInteractionDistance == MinInteractionDistance)
			{
				MaxInteractionDistance = MaxInteractionDistance * InteractionDistanceMultiplier;
				MaxAdjustmentDistance = MaxAdjustmentDistance * InteractionDistanceMultiplier;
			}
		}
		else
		{
			tocBoard->SetCanAdjustDist(true);

			float adjustmentRatio = MaxAdjustmentDistance / MaxInteractionDistance;
			MaxInteractionDistance = FMath::Max<int32>(MinInteractionDistance, MaxInteractionDistance / InteractionDistanceMultiplier);
			MaxAdjustmentDistance = FMath::Max<int32>(MinInteractionDistance * adjustmentRatio, MaxAdjustmentDistance / InteractionDistanceMultiplier);
		}
	}
}

void UGame_Operation_Drag_TOCBoard::PostStartDragInternal()
{
	Super::PostStartDragInternal();

	APawn* playerPawn = UGameplayStatics::GetPlayerPawn(UDeveloper_Statics::GetVHWorld(), 0);

	PhysicsHandle = playerPawn->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle != nullptr)
	{
		FHitResult hitResult;
		if (GetHitResult(hitResult, MaxAdjustmentDistance))
		{
			MaxInteractionDistance = FVector::Distance(hitResult.Location, hitResult.TraceStart);

			HeldObjComp = Cast<UPrimitiveComponent>(DraggedActor->GetRootComponent());
			if (HeldObjComp == nullptr)
			{
				UE_LOG(Game, Warning, TEXT("-- UGame_Operation_Drag_TOCBoard::PostStartDragInternal | HeldObjComp is nullptr | aborting"));

				return;
			}

			HeldObjComp->SetSimulatePhysics(true);
			HeldObjComp->WakeRigidBody();

			// Grabs at the center point of the object or at the world location of the hit on the object
			if (bGrabCenterPoint)
			{
				GrabLocationPoint = DraggedActor->GetActorLocation();
			}
			else
			{
				TArray<FHitResult> hitResults;
				if (DraggingTool->GetInteractionHitResults(hitResults))
				{
					GrabLocationPoint = hitResults[0].Location;
					MaxInteractionDistance = FVector::Distance(hitResults[0].Location, hitResults[0].TraceStart);
				}
				else
				{
					GrabLocationPoint = DraggedActor->GetActorLocation();
				}
			}

			PhysicsHandle->GrabComponentAtLocationWithRotation(HeldObjComp, FName(), GrabLocationPoint, HeldObjComp->GetComponentRotation());

			FVector targetLoc;
			FRotator targetRot;
			PhysicsHandle->GetTargetLocationAndRotation(targetLoc, targetRot);

			float distance = FVector::Distance(DraggedActor->GetActorLocation(), targetLoc);
			FVector unitDirection = (targetLoc - DraggedActor->GetActorLocation()).GetSafeNormal();

			GrabLocationAdjustment = unitDirection * distance;

			bPickedUpObj = true;
		}
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_Operation_Drag_TOCBoard::DefaultMovement()
{
	FTransform localToWorld = DraggingTool->VRTrace->GetComponentTransform();
	
	FVector newLoc = localToWorld.TransformPosition(FVector(MaxInteractionDistance, 0, 0));
	
	// rotate to face player
	FVector tempLoc = ((localToWorld.GetLocation() - DraggedActor->GetActorLocation()) *FVector(1, 1, 0)).GetSafeNormal();
	FRotator newRot = FRotator(0, 0, 0).RotateVector(tempLoc).ToOrientationRotator();

	PhysicsHandle->SetTargetLocationAndRotation(newLoc, newRot);

	ActorToPlace = nullptr;

	bSetSnapLocOnce = true;
}

void UGame_Operation_Drag_TOCBoard::SnapLocationMovement(const FHitResult& adjustmentHitResult)
{
	SnapLocationObj = Cast<AGame_SnapLocation>(adjustmentHitResult.GetActor());
	if (SnapLocationObj)
	{
		FVector newLoc;
		FRotator newRot;

		// If there is not an object placed in the snap location
		if (!SnapLocationObj->DoesCurrentActorExist())
		{
			if (bSetSnapLocOnce)
			{
				bSetSnapLocOnce = false;

				ActorToPlace = DraggedActor;

				newLoc = SnapLocationObj->GetActorLocation();
				newRot = SnapLocationObj->GetActorRotation();

				// Forces held obj to go to the snap location instead of getting blocked by walls
				DraggedActor->SetActorLocationAndRotation(newLoc, newRot);

				if (bGrabCenterPoint)
				{
					newLoc = SnapLocationObj->GetActorLocation();
				}
				else
				{
					newLoc = SnapLocationObj->GetActorLocation() + GrabLocationAdjustment;
				}

				PhysicsHandle->SetTargetLocationAndRotation(newLoc, newRot);
			}
		}
		else
		{
			DefaultMovement();
		}
	}
	// If nothing has been hit, rotate board to face player
	else
	{
		DefaultMovement();
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

bool UGame_Operation_Drag_TOCBoard::GetHitResult(FHitResult& hitResult, float distance) const
{
	FTransform localToWorld = DraggingTool->VRTrace->GetComponentTransform();
	
	FVector traceEnd = localToWorld.TransformPosition(FVector(distance, 0, 0));

	FCollisionQueryParams queryParams;
	queryParams.AddIgnoredActor(DraggedActor);

	if (GetWorld()->LineTraceSingleByChannel(hitResult, localToWorld.GetLocation(), traceEnd, ECollisionChannel::ECC_WorldStatic, queryParams))
	{
		return true;
	}

	return false;
}