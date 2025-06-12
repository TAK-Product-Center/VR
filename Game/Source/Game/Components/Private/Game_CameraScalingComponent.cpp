// Required includes
#include "Game_CameraScalingComponent.h"
#include "Game.h"

// Engine Includes
#include "GameFramework/SpringArmComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "TimerManager.h"

// Game Includes
#include "Game_PlayerState.h"
#include "Game_Statics.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_Pawn.h"
#include "Game_MovementComponent.h"
#include "Game_PlayerController.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_CameraScalingComponent::UGame_CameraScalingComponent(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	PrimaryComponentTick.TickInterval = 0.25;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_CameraScalingComponent::BeginPlay()
{
	Super::BeginPlay();

	MinMaxCameraDistanceForScalingWorld = MinMaxCameraDistanceForScaling;

	MinScaleWorld = MinScale;

	MaxScaleWorld = MaxScale;

	BindToPlayerState();
}

double UGame_CameraScalingComponent::GetDistance() const
{
	double distanceUU = 0;
	if (GetDistanceLambda.IsBound())
	{
		distanceUU = GetDistanceLambda.Execute();
	}	
	else
	{
		distanceUU = Super::GetDistance();
	}

	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		distanceUU *= (1 / virtualObjective->GetActorScale3D().X);
	}

	return distanceUU;
}

FVector UGame_CameraScalingComponent::GetUpVector() const
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

void UGame_CameraScalingComponent::PostTickDistance(double distanceUU)
{
	double distanceMeters = distanceUU / 100.0;

	for (double thresholdMeters : ThresholdMeters)
	{
		if ((LastDistanceMeters <= thresholdMeters && distanceMeters > thresholdMeters) || (LastDistanceMeters > thresholdMeters && distanceMeters <= thresholdMeters))
		{
			OnThresholdCrossed.Broadcast(thresholdMeters, distanceMeters);
		}
	}

	LastDistanceMeters = distanceMeters;
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_CameraScalingComponent::AddDistanceThreshold(double thresholdMeters)
{
	ThresholdMeters.Add(thresholdMeters);

	PostTickDistance(GetDistance());
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_CameraScalingComponent::BindToPlayerState()
{
	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		playerState->OnIsInTOCUpdated.AddDynamic(this, &UGame_CameraScalingComponent::HandleIsInTOCUpdated);

		HandleIsInTOCUpdated(playerState->GetIsInTOC());
	}
	else
	{
		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UGame_CameraScalingComponent::BindToPlayerState, 0.5f);
	}
}

void UGame_CameraScalingComponent::HandleIsInTOCUpdated(bool bIsInTOC)
{
	MinMaxCameraDistanceForScaling = bIsInTOC ? MinMaxCameraDistanceForScalingTOC : MinMaxCameraDistanceForScalingWorld;

	MinScale = bIsInTOC ? MinScaleTOC : MinScaleWorld;

	MaxScale = bIsInTOC ? MaxScaleTOC : MaxScaleWorld;
}