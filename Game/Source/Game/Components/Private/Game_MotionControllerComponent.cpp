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

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_MotionControllerComponent::UGame_MotionControllerComponent(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

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

void UGame_MotionControllerComponent::TickComponent(float deltaSeconds, enum ELevelTick tickType, FActorComponentTickFunction* thisTickFunction)
{
	Super::TickComponent(deltaSeconds, tickType, thisTickFunction);

	if (IsActive() && bTracked)
	{
		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			FTransform worldTransformOverride = playerPawn->Camera->CameraTransformOverride;
			worldTransformOverride.SetLocation(GetOwner()->GetActorLocation() + AGame_Pawn::GetCameraSceneRelativeLocation());

			FQuat orientation = worldTransformOverride.TransformRotation(GetRelativeRotation().Quaternion());
			FVector position = worldTransformOverride.TransformPosition(GetRelativeLocation());

			SetWorldTransform(FTransform(orientation, position));
		}
	}
}

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