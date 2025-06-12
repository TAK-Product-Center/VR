// Required includes
#include "Game_WorldInteractableActor.h"
#include "Game.h"

// VH Plugin Includes
#include "Developer_Subsystem_Operation.h"
#include "UI_Subsystem_ContextMenu.h"
#include "Interface_UI_ContextMenuSource.h"

// Game Includes
#include "Game_CameraScalingComponent.h"
#include "Game_Operation_Drag.h"
#include "Game_Tool.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_WorldInteractableActor::AGame_WorldInteractableActor(const FObjectInitializer& objectInitializer) : 
	Super(objectInitializer),
	HoverScaleModifier(1.3),
	DragDelaySeconds(0.25),
	DragOperationClass(UGame_Operation_Drag::StaticClass())
{
	CameraScalingComponent = CreateDefaultSubobject<UGame_CameraScalingComponent>(TEXT("CameraScalingComponent"));
	CameraScalingComponent->SetupAttachment(RootComponent);
	CameraScalingComponent->CustomScaleMultiplier = GetSettingScaleMultiplier();
}

// ---------------------------------
// --- IInterface_UI_ContextMenuSource
// ---------------------------------

void AGame_WorldInteractableActor::GetContextOptionClasses_Implementation(TSet<TSubclassOf<UObject>>& contextOptionClasses)
{
	contextOptionClasses.Append(ContextOptionClasses);
}

// ---------------------------------
// --- Interface_Developer_Manipulation
// ---------------------------------

bool AGame_WorldInteractableActor::GetTranslationAxisList_Implementation(EAxisListBlueprint& axisList)
{
	axisList = EAxisListBlueprint::XYZ;

	return true;
}

bool AGame_WorldInteractableActor::GetRotationAxisList_Implementation(EAxisListBlueprint& axisList)
{
	axisList = EAxisListBlueprint::None;

	return true;
}

bool AGame_WorldInteractableActor::GetRotationDisabled_Implementation()
{
	EAxisListBlueprint axisList;
	IInterface_Developer_Manipulation::Execute_GetRotationAxisList(this, axisList);

	return axisList == EAxisListBlueprint::None;
}

bool AGame_WorldInteractableActor::GetScaleAxisList_Implementation(EAxisListBlueprint& axisList)
{
	axisList = EAxisListBlueprint::None;

	return true;
}

void AGame_WorldInteractableActor::ManipulationBegin_Implementation()
{
	PostManipulationBegin();

	ReceiveManipulationBegin();

	OnManipulationBegin.Broadcast(this);
}

void AGame_WorldInteractableActor::ManipulationInProgress_Implementation()
{
	PostManipulationInProgress();

	ReceiveManipulationInProgress();

	OnManipulationInProgress.Broadcast(this);
}

void AGame_WorldInteractableActor::ManipulationEnd_Implementation()
{
	PostManipulationEnd();

	ReceiveManipulationEnd();

	OnManipulationEnd.Broadcast(this);
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_WorldInteractableActor::BeginPlay()
{
	Super::BeginPlay();

	CameraScalingComponent->CustomScaleMultiplier = GetSettingScaleMultiplier();

	// bind to mouse events
	OnClicked.AddDynamic(this, &AGame_WorldInteractableActor::HandleClickPressed);

	OnReleased.AddDynamic(this, &AGame_WorldInteractableActor::HandleClickReleased);

	OnBeginCursorOver.AddDynamic(this, &AGame_WorldInteractableActor::HandleBeginCursorOver);

	OnEndCursorOver.AddDynamic(this, &AGame_WorldInteractableActor::HandleEndCursorOver);
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void AGame_WorldInteractableActor::BeginHover(AActor* actor)
{
	CameraScalingComponent->CustomScaleMultiplier = HoverScaleModifier * GetSettingScaleMultiplier();

	PostBeginHover(actor);

	ReceiveBeginHover(actor);
}

void AGame_WorldInteractableActor::EndHover(AActor* actor)
{
	CameraScalingComponent->CustomScaleMultiplier = GetSettingScaleMultiplier();

	PostEndHover(actor);

	ReceiveEndHover(actor);
}

void AGame_WorldInteractableActor::ClickPressed(AActor* actor, const FKey& buttonPressed)
{
	ClickPressedTime = GetWorld()->GetRealTimeSeconds();

	if (!PostClickPressed(actor, buttonPressed) && !ReceiveClickPressed(actor, buttonPressed))
	{
		// if a tool clicked on this, start the drag operation on this
		if (AGame_Tool* gameTool = Cast<AGame_Tool>(actor))
		{
			if (UDeveloper_Subsystem_Operation* subsystem = UDeveloper_Subsystem_Operation::Get())
			{
				DragOperation = Cast<UGame_Operation_Drag>(subsystem->StartOperationByClass(DragOperationClass, 0));
				DragOperation->StartDrag(this, gameTool, DragDelaySeconds);
			}
		}
	}
}

void AGame_WorldInteractableActor::ClickReleased(AActor* actor, const FKey& buttonReleased)
{
	if (UDeveloper_Subsystem_Operation* subsystem = UDeveloper_Subsystem_Operation::Get())
	{
		subsystem->StopOperation(DragOperation);
	}

	PostClickReleased(actor, buttonReleased);

	ReceiveClickReleased(actor, buttonReleased);

	TSet<TSubclassOf<UObject>> contextOptionClasses;
	IInterface_UI_ContextMenuSource::Execute_GetContextOptionClasses(this, contextOptionClasses);
	
	if (contextOptionClasses.Num() > 0 && GetWorld()->GetRealTimeSeconds() - ClickPressedTime < DragDelaySeconds)
	{
		if (UUI_Subsystem_ContextMenu* subsystem = UUI_Subsystem_ContextMenu::Get())
		{
			subsystem->OpenContextMenuWithDefaults(actor, this);
		}
	}
}

void AGame_WorldInteractableActor::PostBeginHover(AActor* actor)
{

}

void AGame_WorldInteractableActor::PostEndHover(AActor* actor)
{

}

bool AGame_WorldInteractableActor::PostClickPressed(AActor* actor, const FKey& buttonPressed)
{
	return false;
}

void AGame_WorldInteractableActor::PostClickReleased(AActor* actor, const FKey& buttonReleased)
{

}

void AGame_WorldInteractableActor::PostManipulationBegin()
{

}

void AGame_WorldInteractableActor::PostManipulationInProgress()
{

}

void AGame_WorldInteractableActor::PostManipulationEnd()
{

}

double AGame_WorldInteractableActor::GetSettingScaleMultiplier() const
{
	return 1;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_WorldInteractableActor::HandleBeginCursorOver(AActor* actor)
{
	BeginHover(actor);
}

void AGame_WorldInteractableActor::HandleEndCursorOver(AActor* actor)
{
	EndHover(actor);
}

void AGame_WorldInteractableActor::HandleClickPressed(AActor* actor, FKey buttonPressed)
{
	ClickPressed(actor, buttonPressed);
}

void AGame_WorldInteractableActor::HandleClickReleased(AActor* actor, FKey buttonReleased)
{
	ClickReleased(actor, buttonReleased);
}