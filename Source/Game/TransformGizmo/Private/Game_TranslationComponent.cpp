// The following is adapted from the MIT-licensed GitHub repository https://github.com/xyahh/UE4RuntimeTransformer/

// Required Includes
#include "Game_TranslationComponent.h"
#include "Game.h"

// Engine Includes
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

// VH Plugin Includes
#include "Developer_Subsystem_Manipulation.h"
#include "Developer_Subsystem_Selection.h"
#include "Interface_Developer_Manipulation.h"

// Game Includes
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_TranslationComponent::UGame_TranslationComponent(const FObjectInitializer& objectInitializer) : 
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_TranslationComponent::UpdateComponentRotation()
{
	FTransform transform = UGame_Statics::GetWorldTransformOverride(GetSelectedActorTransform().GetLocation());
	transform.SetLocation(FVector(0, 0, 0));

	FQuat baseRotation = FQuat::Identity;

	if (!UGame_Statics::IsLocalPlayerInTOC() || Origin == ETransformOrigin::ETO_Local)
	{
		baseRotation = transform.GetRotation();
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

void UGame_TranslationComponent::PerformTransform()
{
	FVector planeNormal, targetDirection;
	CalculateNormalAndDirection(planeNormal, targetDirection);
	//UE_LOG(LogTemp, Warning, TEXT("-- targetDirection: %s | origin: %d"), *targetDirection.ToString(), (int32)Origin);
	FVector rayStart, rayEnd;
	GetInputRay(rayStart, rayEnd);

	FPlane plane(planeNormal, FVector::PointPlaneDist(GetOwner()->GetActorLocation(), FVector::ZeroVector, planeNormal));

	FVector currentPlaneIntersection = FMath::LinePlaneIntersection(rayStart, rayEnd, plane);
	FVector lastPlaneIntersection = FMath::LinePlaneIntersection(LastRayStart, LastRayEnd, plane);

	FVector deltaLocation = currentPlaneIntersection - lastPlaneIntersection;

	// If we're moving on one specific axis, project our delta onto that axis.
	if (Axis <= ETransformAxis::TA_Z)
	{
		deltaLocation = deltaLocation.ProjectOnTo(targetDirection);
	}
	else
	{
		// limit movement (these values are usually 0, but sometimes a little more/less)
		if (Origin == ETransformOrigin::ETO_World)
		{
			switch (Axis)
			{
				case ETransformAxis::TA_XY:
				{
					if (UGame_Statics::IsLocalPlayerInTOC())
					{
						deltaLocation.Z = 0;
					}
					else
					{
						FTransform transform = UGame_Statics::GetWorldTransformOverride(GetOwner()->GetActorLocation());
						transform.SetLocation(FVector(0, 0, 0));
						
						FVector localDelta = transform.InverseTransformPosition(deltaLocation);
						localDelta.Z = 0;
						
						deltaLocation = transform.TransformPosition(localDelta);
						
					}
				}
				break;

				case ETransformAxis::TA_XZ:
				{
					if (UGame_Statics::IsLocalPlayerInTOC())
					{
						deltaLocation.Y = 0;
					}
					else
					{
						FTransform transform = UGame_Statics::GetWorldTransformOverride(GetOwner()->GetActorLocation());
						transform.SetLocation(FVector(0, 0, 0));

						FVector localDelta = transform.InverseTransformPosition(deltaLocation);
						localDelta.Y = 0;

						deltaLocation = transform.TransformPosition(localDelta);
					}
				}
				break;

				case ETransformAxis::TA_YZ:
				{
					if (UGame_Statics::IsLocalPlayerInTOC())
					{
						deltaLocation.X = 0;
					}
					else
					{
						FTransform transform = UGame_Statics::GetWorldTransformOverride(GetOwner()->GetActorLocation());
						transform.SetLocation(FVector(0, 0, 0));

						FVector localDelta = transform.InverseTransformPosition(deltaLocation);
						localDelta.X = 0;

						deltaLocation = transform.TransformPosition(localDelta);
					}
				}
				break;
			}
		}

		// todo ohg | see if anything similar is needed for ETransformOrign::ETO_Local
	}

	deltaLocation *= Sensitivity;

	UDeveloper_Subsystem_Selection* selectSubsystem = GetWorld()->GetSubsystem<UDeveloper_Subsystem_Selection>();
	TSet<AActor*> selectedActors = selectSubsystem->GetSelectedByClass<AActor>(AActor::StaticClass());

	UDeveloper_Subsystem_Manipulation* manipSubsystem = UGameplayStatics::GetGameInstance(GetWorld())->GetSubsystem<UDeveloper_Subsystem_Manipulation>();

	switch (Origin)
	{
		case ETransformOrigin::ETO_World:
		{
			// Move the gizmo and the selected actors together.
			selectedActors.Add(GetOwner());
			manipSubsystem->AddOffsetInWorldSpace(selectedActors, deltaLocation);
		}
		break;
		case ETransformOrigin::ETO_Local:
		{
			// Apply translation to selected actors...
			manipSubsystem->AddOffsetInLocalSpace(selectedActors, deltaLocation);

			AActor* lastSelectedActor = Cast<AActor>(selectedActors.Array()[selectedActors.Num() - 1]);
			manipSubsystem->AddOffsetInTransformSpace(TSet<AActor*> { GetOwner() }, deltaLocation, lastSelectedActor->GetActorTransform());
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

void UGame_TranslationComponent::CalculateNormalAndDirection(FVector& planeNormal, FVector& targetDirection)
{
	AActor* owner = GetOwner();

	FVector forwardVector;
	FVector rightVector;
	FVector upVector;

	if (Origin == ETransformOrigin::ETO_World)
	{
		if (UGame_Statics::IsLocalPlayerInTOC())
		{
			forwardVector = FVector(1, 0, 0);
			rightVector = FVector(0, 1, 0);
			upVector = FVector(0, 0, 1);
		}
		else
		{
			FTransform surfaceTransform = UGame_Statics::GetWorldTransformOverride(GetSelectedActorTransform().GetLocation());
			surfaceTransform.SetLocation(FVector(0, 0, 0));
			
			forwardVector = surfaceTransform.TransformPosition(FVector(1, 0, 0));
			rightVector = surfaceTransform.TransformPosition(FVector(0, 1, 0));
			upVector = surfaceTransform.TransformPosition(FVector(0, 0, 1));
		}
	}
	else
	{
		forwardVector = owner->GetActorForwardVector();
		rightVector = owner->GetActorRightVector();
		upVector = owner->GetActorUpVector();
	}

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
			planeNormal = upVector;
		}
		break;

		case ETransformAxis::TA_XZ:
		{
			planeNormal = rightVector;
		}
		break;

		case ETransformAxis::TA_YZ:
		{
			planeNormal = forwardVector;
		}
		break;
	}
}