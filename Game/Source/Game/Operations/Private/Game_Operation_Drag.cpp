// Required Includes
#include "Game_Operation_Drag.h"
#include "Game.h"

// Engine Includes
#include "Components/ChildActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TimerManager.h"

// VH Plugin Includes
#include "Interface_Developer_Manipulation.h"
#include "Developer_Subsystem_Operation.h"
#include "Developer_Statics.h"

// Game Includes
#include "Game_Tool.h"
#include "Game_Statics.h"
#include "Game_PlayerController.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_Operation_Drag::UGame_Operation_Drag(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	bStopOnRightMouseDown(true)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_Operation_Drag::PostStart()
{
	Super::PostStart();

	MouseCaptureMode = UGameplayStatics::GetViewportMouseCaptureMode(UDeveloper_Statics::GetVHWorld());
}

void UGame_Operation_Drag::PostStop()
{
	Super::PostStop();

	if (bDelayTimerFinished)
	{
		DraggingTool->RemoveTraceIgnoredActor(DraggedActor);

		TArray<UChildActorComponent*> childActorComponents;
		DraggedActor->GetComponents<UChildActorComponent>(childActorComponents);

		for (UChildActorComponent* childActorComponent : childActorComponents)
		{
			DraggingTool->RemoveTraceIgnoredActor(childActorComponent->GetChildActor());
		}

		if (DraggedActor->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()))
		{
			IInterface_Developer_Manipulation::Execute_ManipulationEnd(DraggedActor);
		}
	}

	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

void UGame_Operation_Drag::PostTick(float deltaSeconds)
{
	Super::PostTick(deltaSeconds);

	if (bStopOnRightMouseDown)
	{
		EMouseCaptureMode mouseCaptureMode = UGameplayStatics::GetViewportMouseCaptureMode(UDeveloper_Statics::GetVHWorld());
		bool bRightMouseDown = UGame_Statics::GetVHPlayerController()->IsInputKeyDown(EKeys::RightMouseButton);
		if ((mouseCaptureMode != MouseCaptureMode) || (mouseCaptureMode == EMouseCaptureMode::CaptureDuringRightMouseDown && bRightMouseDown))
		{
			if (UDeveloper_Subsystem_Operation* subsystem = UDeveloper_Subsystem_Operation::Get())
			{
				subsystem->StopOperation(this);

				return;
			}
		}
	}

	if (bDelayTimerFinished && DraggedActor != nullptr && DraggingTool != nullptr)
	{
		FVector dragLocation;
		if (GetDragLocation(dragLocation))
		{
			dragLocation.X = dragLocation.X + DragOffset.X;
			dragLocation.Y = dragLocation.Y + DragOffset.Y;

			DraggedActor->SetActorLocation(dragLocation);
			
			if (DraggedActor->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()))
			{
				IInterface_Developer_Manipulation::Execute_ManipulationInProgress(DraggedActor);
			}
		}
	}
}

// ---------------------------------
// --- API
// ---------------------------------

AActor* UGame_Operation_Drag::GetDraggedActor() const
{
	return DraggedActor;
}

AGame_Tool* UGame_Operation_Drag::GetDraggingTool() const
{
	return DraggingTool;
}

void UGame_Operation_Drag::StartDrag(AActor* actor, AGame_Tool* tool, double dragDelaySeconds)
{
	DraggedActor = actor;

	DraggingTool = tool;

	FVector dragLocation;
	if (GetDragLocation(dragLocation))
	{
		DragOffset = DraggedActor->GetActorLocation() - dragLocation;

		if (!UGame_Statics::IsInnerTileLoaded())
		{
			DragOffset = FVector::Zero();
		}
	}

	bDelayTimerFinished = false;

	OperationStartTime = GetWorld()->GetRealTimeSeconds();

	if (dragDelaySeconds <= 0)
	{
		StartDragInternal();
	}
	else
	{
		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UGame_Operation_Drag::StartDragInternal, dragDelaySeconds, false);
	}
}
	

// ---------------------------------
// --- Implementation
// ---------------------------------

bool UGame_Operation_Drag::GetDragLocation(FVector& dragLocation) const
{
	if (DraggingTool->GetInteractionHitLocation(dragLocation))
	{
		dragLocation = UGame_Statics::GetModifiedDragLocation(dragLocation);

		return true;
	}

	return false;
}

void UGame_Operation_Drag::PostStartDragInternal()
{

}

void UGame_Operation_Drag::StartDragInternal()
{
	bDelayTimerFinished = true;

	DraggingTool->AddTraceIgnoredActor(DraggedActor);

	TArray<UChildActorComponent*> childActorComponents;
	DraggedActor->GetComponents<UChildActorComponent>(childActorComponents);

	for (UChildActorComponent* childActorComponent : childActorComponents)
	{
		DraggingTool->AddTraceIgnoredActor(childActorComponent->GetChildActor());
	}

	if (DraggedActor->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()))
	{
		IInterface_Developer_Manipulation::Execute_ManipulationBegin(DraggedActor);
	}

	PostStartDragInternal();
}