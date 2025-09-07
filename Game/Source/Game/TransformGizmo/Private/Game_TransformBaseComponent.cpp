// Required Includes
#include "Game_TransformBaseComponent.h"
#include "Game.h"

// Engine Includes
#include "MotionControllerComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"

// VH Plugin Includes
#include "Interface_Developer_Manipulation.h"
#include "Developer_Subsystem_Selection.h"

// Game Includes
#include "Game_Subsystem_Gizmo.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_TransformBaseComponent::UGame_TransformBaseComponent(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	Axis(ETransformAxis::TA_X),
	bActive(false)
{
	PrimaryComponentTick.bCanEverTick = true;

	OnClicked.AddDynamic(this, &UGame_TransformBaseComponent::HandleClick);
	OnReleased.AddDynamic(this, &UGame_TransformBaseComponent::HandleRelease);
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_TransformBaseComponent::BeginPlay()
{
	Super::BeginPlay();

	if (UGame_Subsystem_Gizmo* subsystem = UGame_Subsystem_Gizmo::Get())
	{
		SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

		SetCollisionResponseToChannel(subsystem->GizmoCollisionChannel, ECollisionResponse::ECR_Overlap);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_TransformBaseComponent::BeginPlay | could not set collision channel for gizmo"));
	}
}

void UGame_TransformBaseComponent::TickComponent(float deltaSeconds, ELevelTick tickType, FActorComponentTickFunction* thisTickFunction)
{
	UpdateComponentRotation();

	if (!bActive || bHiddenInGame || GetOwner() == nullptr)
	{
		return;
	}

	PerformTransform();
}

// ---------------------------------
// --- API
// ---------------------------------

FVector UGame_TransformBaseComponent::GetAxisVector() const
{
	switch (Axis)
	{
		case ETransformAxis::TA_X:
		case ETransformAxis::TA_YZ:
		{
			return FVector::UnitX();
		}
		break;

		case ETransformAxis::TA_Y:
		case ETransformAxis::TA_XZ:
		{
			return FVector::UnitY();
		}
		break;

		case ETransformAxis::TA_Z:
		case ETransformAxis::TA_XY:
		{
			return FVector::UnitZ();
		}
		break;

		default:
		{
			return FVector::ZeroVector;
		}
		break;
	}
}

void UGame_TransformBaseComponent::SetAxisType(const ETransformAxis& axis)
{
	Axis = axis;
}

void UGame_TransformBaseComponent::SetTransformOrigin(const ETransformOrigin& origin)
{
	Origin = origin;
}

void UGame_TransformBaseComponent::SetSensitivity(float sensitivity)
{
	Sensitivity = sensitivity;
}

void UGame_TransformBaseComponent::ResetLastRay()
{
	LastRayStart = FVector::ZeroVector;
	LastRayEnd = FVector::ZeroVector;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_TransformBaseComponent::NotifyManipulationInProgress()
{
	// notify end manipulation
	UDeveloper_Subsystem_Selection* selectSubsystem = GetWorld()->GetSubsystem<UDeveloper_Subsystem_Selection>();
	TSet<AActor*> selectedActors = selectSubsystem->GetSelectedByClass<AActor>(AActor::StaticClass());

	for (AActor* actor : selectedActors)
	{
		if (actor->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()))
		{
			IInterface_Developer_Manipulation::Execute_ManipulationInProgress(actor);
		}
	}
}

void UGame_TransformBaseComponent::GetInputRay(FVector& start, FVector& end)
{
	if (UGame_Subsystem_Gizmo* subsystem = UGame_Subsystem_Gizmo::Get())
	{
		for (const UGame_Subsystem_Gizmo::FGetInputRay& getInputRayDelegate : subsystem->GetInputRayLambdas)
		{
			if (getInputRayDelegate.IsBound() && getInputRayDelegate.Execute(start, end))
			{
				return;
			}
		}
	}

	APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	APawn* pawn = playerController->GetPawn();

	UMotionControllerComponent* motionControllerComponent = Cast<UMotionControllerComponent>(pawn->GetComponentByClass(UMotionControllerComponent::StaticClass()));

	// If there's a valid VR controller, use it to get the ray endpoints.
	if (motionControllerComponent != nullptr)
	{
		start = motionControllerComponent->GetComponentLocation();
		end = start + (RAY_END_DIST * motionControllerComponent->GetForwardVector().GetSafeNormal());
	}
	// When there's no VR controller, use the mouse.
	else
	{
		FVector direction;
		playerController->DeprojectMousePositionToWorld(start, direction);
		end = start + (RAY_END_DIST * direction);
	}
}

void UGame_TransformBaseComponent::PerformTransform()
{

}

FTransform UGame_TransformBaseComponent::GetSelectedActorTransform() const
{
	if (UDeveloper_Subsystem_Selection* selectSubsystem = GetWorld()->GetSubsystem<UDeveloper_Subsystem_Selection>())
	{
		if (AActor* lastSelectedActor = Cast<AActor>(selectSubsystem->GetLastSelected()))
		{
			if (lastSelectedActor->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()))
			{
				FTransform transform;
				if (IInterface_Developer_Manipulation::Execute_GetWorldTransform(lastSelectedActor, transform))
				{
					return transform;
				}
			}

			return lastSelectedActor->GetActorTransform();
		}
	}

	return FTransform::Identity;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_TransformBaseComponent::HandleClick(UPrimitiveComponent* touchedComponent, FKey buttonPressed)
{
	if (!bHiddenInGame)
	{
		bActive = true;

		// notify manipulation begin
		UDeveloper_Subsystem_Selection* selectSubsystem = GetWorld()->GetSubsystem<UDeveloper_Subsystem_Selection>();
		TSet<AActor*> selectedActors = selectSubsystem->GetSelectedByClass<AActor>(AActor::StaticClass());

		for (AActor* actor : selectedActors)
		{
			if (actor->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()))
			{
				IInterface_Developer_Manipulation::Execute_ManipulationBegin(actor);
			}
		}
	}
}

void UGame_TransformBaseComponent::HandleRelease(UPrimitiveComponent* touchedComponent, FKey buttonReleased)
{
	bActive = false;

	LastRayStart = FVector::ZeroVector;
	LastRayEnd = FVector::ZeroVector;

	// notify manipulation end
	UDeveloper_Subsystem_Selection* selectSubsystem = GetWorld()->GetSubsystem<UDeveloper_Subsystem_Selection>();
	TSet<AActor*> selectedActors = selectSubsystem->GetSelectedByClass<AActor>(AActor::StaticClass());

	for (AActor* actor : selectedActors)
	{
		if (actor->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()))
		{
			IInterface_Developer_Manipulation::Execute_ManipulationEnd(actor);
		}
	}
}