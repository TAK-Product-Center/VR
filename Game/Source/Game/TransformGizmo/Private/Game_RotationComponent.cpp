// The following is adapted from the MIT-licensed GitHub repository https://github.com/xyahh/UE4RuntimeTransformer/

// Required Includes
#include "Game_RotationComponent.h"
#include "Game.h"

// Engine Includes
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

// VH Plugin Includes
#include "Developer_Subsystem_Manipulation.h"
#include "Developer_Subsystem_Selection.h"

// Game Includes
#include "Game_Statics.h"

constexpr float DELTA_DIFF_THRESHOLD = 0.01f;

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_RotationComponent::UGame_RotationComponent(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_RotationComponent::UpdateComponentRotation()
{
	FQuat baseRotation = FQuat::Identity;

	if (Origin == ETransformOrigin::ETO_World)
	{
		// todo: implement
	}
	else
	{
		baseRotation = GetSelectedActorTransform().GetRotation();
	}

	switch (Axis)
	{
		case ETransformAxis::TA_Y:
		{
			SetWorldRotation(baseRotation * FQuat(FVector::UnitZ(), FMath::DegreesToRadians(90.0f)));
		}
		break;

		case ETransformAxis::TA_Z:
		{
			SetWorldRotation(baseRotation * FQuat(FVector::UnitX(), FMath::DegreesToRadians(-90.0f)));
		}
		break;

		case ETransformAxis::TA_X:
		default:
		{
			SetWorldRotation(baseRotation);
		}
		break;
	}
}

void UGame_RotationComponent::PerformTransform()
{
	FVector planeNormal = FVector(1.0f, 0.0f, 0.0f);

	AActor* owner = GetOwner();

	FVector forwardVector;
	FVector rightVector;
	FVector upVector;

	if (Origin == ETransformOrigin::ETO_World)
	{
		// todo: implement
	}
	else
	{
		FTransform surfaceTransform = GetSelectedActorTransform();
		surfaceTransform.SetLocation(FVector(0, 0, 0));

		forwardVector = surfaceTransform.TransformPosition(FVector(1, 0, 0));
		rightVector = surfaceTransform.TransformPosition(FVector(0, 1, 0));
		upVector = surfaceTransform.TransformPosition(FVector(0, 0, 1));
	}

	switch (Axis)
	{
		case ETransformAxis::TA_X:
		{
			planeNormal = rightVector;
		}
		break;

		case ETransformAxis::TA_Y:
		{
			planeNormal = forwardVector;
		}
		break;

		case ETransformAxis::TA_Z:
		{
			planeNormal = upVector;
		}
		break;
	}

	FVector rayStart, rayEnd;
	GetInputRay(rayStart, rayEnd);

	FVector gizmoLocation = GetSelectedActorTransform().GetLocation();// GetOwner()->GetActorLocation();
	FPlane plane(planeNormal, FVector::PointPlaneDist(gizmoLocation, FVector::ZeroVector, planeNormal));

	FVector currentPlaneIntersection = FMath::LinePlaneIntersection(rayStart, rayEnd, plane);
	FVector lastPlaneIntersection = FMath::LinePlaneIntersection(LastRayStart, LastRayEnd, plane);

	FVector currentDeltaLocation = currentPlaneIntersection - gizmoLocation;
	FVector lastDeltaLocation = lastPlaneIntersection - gizmoLocation;

	FVector deltaDiff = currentDeltaLocation - lastDeltaLocation;

	// early out if haven't moved a significant amount
	if (deltaDiff.Size() < 0.01)
	{
		LastRayStart = rayStart;
		LastRayEnd = rayEnd;

		return;
	}
	
	FTransform transform;	
	if (UGame_Statics::IsLocalPlayerInTOC())
	{
		transform = GetSelectedActorTransform();
		transform.SetScale3D(FVector(1, 1, 1));
	}
	else
	{
		transform = UGame_Statics::GetWorldTransformOverride(GetSelectedActorTransform().GetLocation());
	}
	
	FVector last = transform.InverseTransformPosition(lastPlaneIntersection);
	FVector current = transform.InverseTransformPosition(currentPlaneIntersection);

	double calculatedAngle = 0;

	switch (Axis)
	{
		case ETransformAxis::TA_X:
		{
			calculatedAngle = current.Z - last.Z;

			if (!UGame_Statics::IsLocalPlayerInTOC())
			{
				calculatedAngle *= 0.01;
			}
		}
		break;

		case ETransformAxis::TA_Y:
		{
			calculatedAngle = current.X - last.X;
		}
		break;

		case ETransformAxis::TA_Z:
		{
			double angleFromDot = FMath::Acos(FVector::DotProduct(currentDeltaLocation, lastDeltaLocation) / (currentDeltaLocation.Size() * lastDeltaLocation.Size()));

			// try each direction and go with whichever gets closer to currentPlaneIntersection
			FVector positive = lastPlaneIntersection.RotateAngleAxisRad(angleFromDot, transform.TransformPosition(FVector(0, 0, 1)) - transform.GetLocation());
			FVector negative = lastPlaneIntersection.RotateAngleAxisRad(-angleFromDot, transform.TransformPosition(FVector(0, 0, 1)) - transform.GetLocation());

			positive = (currentPlaneIntersection - positive);
			negative = (currentPlaneIntersection - negative);

			bool bNegative = negative.Size() < positive.Size();

			calculatedAngle = FMath::RadiansToDegrees(angleFromDot);
			if (bNegative)
			{
				calculatedAngle *= -1;
			}
		}
		break;
	}

	double rotationAngle = calculatedAngle * Sensitivity;

	UDeveloper_Subsystem_Selection* selectSubsystem = GetWorld()->GetSubsystem<UDeveloper_Subsystem_Selection>();
	TSet<AActor*> selectedActors = selectSubsystem->GetSelectedByClass<AActor>(AActor::StaticClass());

	UDeveloper_Subsystem_Manipulation* manipSubsystem = UGameplayStatics::GetGameInstance(GetWorld())->GetSubsystem<UDeveloper_Subsystem_Manipulation>();

	switch (Origin)
	{
		case ETransformOrigin::ETO_World:
		{
			manipSubsystem->AddRotationInWorldSpace(selectedActors, FQuat(planeNormal, rotationAngle));
		}
		break;

		case ETransformOrigin::ETO_Local:
		{
			FRotator angle = FRotator(0, 0, 0);
			switch (Axis)
			{
				case ETransformAxis::TA_X:
				{
					angle.Pitch = rotationAngle;
				}
				break;

				case ETransformAxis::TA_Y:
				{
					angle.Roll = rotationAngle;
				}
				break;

				case ETransformAxis::TA_Z:
				{
					angle.Yaw = rotationAngle;
				}
				break;
			}

			manipSubsystem->AddRotationInLocalSpace(selectedActors, angle.Quaternion());
		}
		break;
	}

	LastRayStart = rayStart;
	LastRayEnd = rayEnd;

	NotifyManipulationInProgress();
}
