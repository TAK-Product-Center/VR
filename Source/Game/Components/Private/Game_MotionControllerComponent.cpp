// Required Includes
#include "Game_MotionControllerComponent.h"
#include "Game.h"

// Engine Includes
#include "Net/UnrealNetwork.h"

// VH Module Includes
#include "VH_GlobeReferenceActor.h"

// Game Includes
#include "Game_PlayerController.h"
#include "Game_VirtualObjective.h"
#include "Game_Statics.h"
#include "Game_Pawn.h"
#include "Game_CameraComponent.h"
#include "Game_MovementComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_MotionControllerComponent::UGame_MotionControllerComponent(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	bDisableLowLatencyUpdate = true;

	StabilityFactor = 0.1;
}

// ---------------------------------
// --- Replication
// ---------------------------------

void UGame_MotionControllerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(UGame_MotionControllerComponent, TraceStartCoordinate, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(UGame_MotionControllerComponent, TraceEndCoordinate, COND_SkipOwner);
}

void UGame_MotionControllerComponent::Server_SetTraceCoordinates_Implementation(const FGeodeticCoord3D& startCoordinate, const FGeodeticCoord3D& endCoordinate)
{
	TraceStartCoordinate = startCoordinate;
	TraceEndCoordinate = endCoordinate;

	if (GetNetMode() == NM_ListenServer && !IsLocallyControlled())
	{
		OnRep_TraceStartCoordinate();
		OnRep_TraceEndCoordinate();
	}
}

void UGame_MotionControllerComponent::OnRep_TraceStartCoordinate()
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
		{
			FVector traceStartLocation = globeReference->GeodeticToWorldDouble(TraceStartCoordinate);

			SetWorldLocation(traceStartLocation);
		}
	}
}

void UGame_MotionControllerComponent::OnRep_TraceEndCoordinate()
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
		{
			FVector traceEndLocation = globeReference->GeodeticToWorldDouble(TraceEndCoordinate);
			
			FQuat componentRotation = FRotationMatrix::MakeFromXZ(traceEndLocation - GetComponentLocation(), FVector::UpVector).ToQuat();

			SetWorldRotation(componentRotation);
		}
	}
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_MotionControllerComponent::PreReplication(IRepChangedPropertyTracker& ChangedPropertyTracker)
{
	Super::PreReplication(ChangedPropertyTracker);

	// location/rotation replication is handled through TraceStartCoordinate/TraceEndCoordinate
	DOREPLIFETIME_ACTIVE_OVERRIDE_FAST(USceneComponent, RelativeLocation, false);
	DOREPLIFETIME_ACTIVE_OVERRIDE_FAST(USceneComponent, RelativeRotation, false);
	DOREPLIFETIME_ACTIVE_OVERRIDE_FAST(USceneComponent, RelativeScale3D, false);
}

void UGame_MotionControllerComponent::ReplicateTransform()
{
	// intentionally not calling Super::ReplicateTransform()
}

bool UGame_MotionControllerComponent::GetNewPositionAndRotation(FVector& inOutNewRelativeLocation, FRotator& inOutNewRelativeRotation)
{
	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		FTransform worldTransformOverride = playerPawn->Camera->GetCameraTransformOverride();
		worldTransformOverride.SetLocation(GetOwner()->GetActorLocation() + AGame_Pawn::GetCameraSceneRelativeLocation());

		FQuat orientation = worldTransformOverride.TransformRotation(inOutNewRelativeRotation.Quaternion());
		FVector position = worldTransformOverride.TransformPosition(inOutNewRelativeLocation);

		if (playerPawn->VRMovement->Velocity.Size() == 0 && !playerPawn->IsPanning())
		{
			FTransform transform = FTransform(orientation, position);

			double currentTime = GetWorld()->GetTimeSeconds();

			PreviousTransforms.Add(TPair<double, FTransform>(currentTime, transform));

			// get average transform over last delta time
			FVector averageLocation = FVector::ZeroVector;
			FQuat averageQuat = FQuat(0, 0, 0, 0);
			int32 count = 0;

			for (int32 i = 0; i < PreviousTransforms.Num(); i++)
			{
				if (PreviousTransforms[i].Key >= currentTime - StabilityFactor)
				{
					averageLocation += PreviousTransforms[i].Value.GetLocation();
				
					averageQuat.X += PreviousTransforms[i].Value.GetRotation().X;
					averageQuat.Y += PreviousTransforms[i].Value.GetRotation().Y;
					averageQuat.Z += PreviousTransforms[i].Value.GetRotation().Z;
					averageQuat.W += PreviousTransforms[i].Value.GetRotation().W;

					count++;
				}
				else
				{
					PreviousTransforms.RemoveAt(i, 1);
					i--;
				}
			}

			averageLocation /= count;

			averageQuat.X /= count;
			averageQuat.Y /= count;
			averageQuat.Z /= count;
			averageQuat.W /= count;

			SetWorldTransform(FTransform(averageQuat, averageLocation));
		}
		else
		{
			PreviousTransforms.Empty();

			SetWorldTransform(FTransform(orientation, position));
		}
	}

	// set world transform in this function; don't set world transform in super 
	return false;
}

FVector UGame_MotionControllerComponent::GetUpVector() const
{
	FVector upVector = Super::GetUpVector();

	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		FTransform transformNoLocation = playerPawn->VRMovement->GetWorldTransformOverride();
		transformNoLocation.SetLocation(FVector(0, 0, 0));

		upVector = transformNoLocation.TransformPosition(upVector);
	}

	return upVector;
}

// ---------------------------------
// --- API
// ---------------------------------

FGeodeticCoord3D UGame_MotionControllerComponent::GetTraceStartCoordinate() const
{
	return TraceStartCoordinate;
}

FGeodeticCoord3D UGame_MotionControllerComponent::GetTraceEndCoordinate() const
{
	return TraceEndCoordinate;
}