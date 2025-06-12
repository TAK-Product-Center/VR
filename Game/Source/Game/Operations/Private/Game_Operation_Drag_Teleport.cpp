// Required Includes
#include "Game_Operation_Drag_Teleport.h"
#include "Game.h"

// Engine Includes
#include "InputAction.h"

// VH Plugin Includes
#include "Developer_Subsystem_Core.h"

// Game Includes
#include "Game_TutorialManager.h"
#include "Game_Tool.h"
#include "Game_MovementComponent.h"
#include "Game_Statics.h"
#include "Game_Pawn.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_Operation_Drag_Teleport::UGame_Operation_Drag_Teleport(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	bStopOnRightMouseDown = false;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_Operation_Drag_Teleport::ActionInput_Implementation(const FInputActionInstance& inputActionInstance)
{
	FString action = inputActionInstance.GetSourceAction()->ActionDescription.ToString();

	if (action.Equals(TEXT("Teleport_RotateTarget")))
	{
		FRotator rotation = DraggedActor->GetActorRotation();

		if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
		{
			FTransform transform = playerPawn->VRMovement->GetWorldTransformOverride();
			rotation = transform.InverseTransformRotation(rotation.Quaternion()).Rotator();

			rotation.Yaw += inputActionInstance.GetValue().Get<float>();

			rotation = transform.TransformRotation(rotation.Quaternion()).Rotator();
		}

		DraggedActor->SetActorRotation(rotation);

		if (UGame_TutorialManager* tutorialManager = UGame_TutorialManager::Get())
		{
			tutorialManager->TutorialActionOccurred(TEXT("teleportRotate"));
		}
	}
}

void UGame_Operation_Drag_Teleport::StartDrag(AActor* actor, AGame_Tool* tool, double delaySeconds)
{
	Super::StartDrag(actor, tool, delaySeconds);

	InitialToolRotation = DraggingTool->GetActorRotation();

	InitialTeleportPreviewRotation = actor->GetActorRotation();
}

void UGame_Operation_Drag_Teleport::PostTick(float deltaSeconds)
{
	Super::PostTick(deltaSeconds);

	if (UDeveloper_Subsystem_Core* subsystem = UDeveloper_Subsystem_Core::Get())
	{
		if (subsystem->GetHardwareInterfaceMode() == EHardwareInterfaceMode::VR || subsystem->GetHardwareInterfaceMode() == EHardwareInterfaceMode::VREmulation)
		{
			FRotator toolRotation = DraggingTool->GetActorRotation();

			float rollDifference = InitialToolRotation.Roll - toolRotation.Roll;

			FRotator teleportPreviewRotation = DraggedActor->GetActorRotation();
			teleportPreviewRotation.Yaw = InitialTeleportPreviewRotation.Yaw + rollDifference;
			
			DraggedActor->SetActorRotation(teleportPreviewRotation);

			if(abs(rollDifference) > 0)
			{
				if (UGame_TutorialManager* tutorialManager = UGame_TutorialManager::Get())
				{
					tutorialManager->TutorialActionOccurred(TEXT("teleportRotate"));
				}
			}
		}
	}
}

bool UGame_Operation_Drag_Teleport::GetDragLocation(FVector& dragLocation) const
{
	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		if (UGame_MovementComponent* movementComponent = playerPawn->GetComponentByClass<UGame_MovementComponent>())
		{
			return movementComponent->GetTeleportDragLocation(DraggingTool, dragLocation);
		}
	}

	return false;
}