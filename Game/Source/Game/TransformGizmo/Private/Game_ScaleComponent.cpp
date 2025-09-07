// The following is adapted from the MIT-licensed GitHub repository https://github.com/xyahh/UE4RuntimeTransformer/

// Required Includes
#include "Game_ScaleComponent.h"
#include "Game.h"

// Engine Includes
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/GameInstance.h"

// VH Plugin Includes
#include "Developer_Subsystem_Manipulation.h"
#include "Developer_Subsystem_Selection.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_ScaleComponent::UGame_ScaleComponent(const FObjectInitializer& objectInitializer) : 
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_ScaleComponent::UpdateComponentRotation()
{
	FQuat baseRotation = FQuat::Identity;

	if (Origin == ETransformOrigin::ETO_Local)
	{
		baseRotation = GetSelectedActorTransform().GetRotation();
	}

	switch (Axis)
	{
		case ETransformAxis::TA_XY:
		{
			SetWorldRotation(baseRotation * FQuat(FVector::UnitX(), FMath::DegreesToRadians(-90.0f)));
		}
		break;

		case ETransformAxis::TA_Z:
		{
			SetWorldRotation(baseRotation * FQuat(FVector::UnitY(), FMath::DegreesToRadians(-90.0f)));
		}
		break;

		case ETransformAxis::TA_Y:
		case ETransformAxis::TA_YZ:
		{
			SetWorldRotation(baseRotation * FQuat(FVector::UnitZ(), FMath::DegreesToRadians(90.0f)));
		}
		break;

		case ETransformAxis::TA_X:
		case ETransformAxis::TA_XZ:
		default:
		{
			SetWorldRotation(baseRotation);
		}
		break;
	}
}

void UGame_ScaleComponent::PerformTransform()
{
	FVector planeNormal, targetDirection;
	CalculateNormalAndDirection(planeNormal, targetDirection);

	FVector rayStart, rayEnd;
	GetInputRay(rayStart, rayEnd);

	FPlane plane(planeNormal, FVector::PointPlaneDist(GetOwner()->GetActorLocation(), FVector::ZeroVector, planeNormal));
	
	FVector currentPlaneIntersection = FMath::LinePlaneIntersection(rayStart, rayEnd, plane);
	FVector lastPlaneIntersection = FMath::LinePlaneIntersection(LastRayStart, LastRayEnd, plane);

	FVector deltaLocation = currentPlaneIntersection - lastPlaneIntersection;
	deltaLocation = deltaLocation.ProjectOnTo(targetDirection) * Sensitivity;

	UDeveloper_Subsystem_Selection* selectSubsystem = GetWorld()->GetSubsystem<UDeveloper_Subsystem_Selection>();
	TSet<AActor*> selectedActors = selectSubsystem->GetSelectedByClass<AActor>(AActor::StaticClass());

	UDeveloper_Subsystem_Manipulation* manipSubsystem = UGameplayStatics::GetGameInstance(GetWorld())->GetSubsystem<UDeveloper_Subsystem_Manipulation>();

	switch (Origin)
	{
		case ETransformOrigin::ETO_World:
		{
			manipSubsystem->AddScaleInWorldSpace(selectedActors, deltaLocation);
		}
		break;

		case ETransformOrigin::ETO_Local:
		{
			manipSubsystem->AddScaleInLocalSpace(selectedActors, deltaLocation);
		}
		break;
	}

	LastRayStart = rayStart;
	LastRayEnd = rayEnd;

	NotifyManipulationInProgress();
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_ScaleComponent::CalculateNormalAndDirection(FVector& planeNormal, FVector& targetDirection)
{
	AActor* owner = GetOwner();
	FVector forwardVector = owner->GetActorForwardVector();
	FVector rightVector = owner->GetActorRightVector();
	FVector upVector = owner->GetActorUpVector();

	FVector lookingVector = UGameplayStatics::GetPlayerController(GetWorld(), 0)->PlayerCameraManager->GetActorForwardVector();

	switch (Axis)
	{
		case ETransformAxis::TA_X:
		{
			targetDirection = forwardVector;
			if (FMath::Abs(lookingVector.Dot(rightVector)) > COS_45_DEG)
			{
				planeNormal = rightVector;
			}
			else
			{
				planeNormal = upVector;
			}
		}
		break;

		case ETransformAxis::TA_Y:
		{
			targetDirection = rightVector;
			if (FMath::Abs(lookingVector.Dot(forwardVector)) > COS_45_DEG)
			{
				planeNormal = forwardVector;
			}
			else
			{
				planeNormal = upVector;
			}
		}
		break;

		case ETransformAxis::TA_Z:
		{
			targetDirection = upVector;
			if (FMath::Abs(lookingVector.Dot(forwardVector)) > COS_45_DEG)
			{
				planeNormal = forwardVector;
			}
			else
			{
				planeNormal = rightVector;
			}
		}
		break;

		case ETransformAxis::TA_XY:
		{
			targetDirection = forwardVector + rightVector;
			planeNormal = upVector;
		}
		break;

		case ETransformAxis::TA_XZ:
		{
			targetDirection = forwardVector + upVector;
			planeNormal = rightVector;
		}
		break;

		case ETransformAxis::TA_YZ:
		{
			targetDirection = rightVector + upVector;
			planeNormal = forwardVector;
		}
		break;
	}
}
