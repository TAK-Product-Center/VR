// Required includes
#include "VTAK_EditPoint_Mensuration.h"

// VH Plugin Includes
#include "Developer_Subsystem_Operation.h"

// Game Includes
#include "Game_Subsystem_Gizmo.h"
#include "Game_TransformGizmo_Enum.h"
#include "Game_TransformGizmo.h"
#include "Game_TransformBaseComponent.h"
#include "Game_CameraScalingComponent.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_Tool.h"
#include "Game_Operation_Drag.h"
#include "Game_Statics.h"

// Module Includes
#include "VTAK_Actor_Mensuration.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AVTAK_EditPoint_Mensuration::AVTAK_EditPoint_Mensuration(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{
	LevelMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LevelMeshComponent"));
	LevelMeshComponent->SetupAttachment(ShapeMeshComponent);
}

// ---------------------------------
// --- Interface_Developer_Manipulation
// ---------------------------------

bool AVTAK_EditPoint_Mensuration::GetWorldTransform_Implementation(FTransform& localToWorld)
{
	localToWorld = UGame_Statics::GetWorldTransformOverride(GetActorLocation());
	localToWorld.SetLocation(GetActorLocation());

	return true;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AVTAK_EditPoint_Mensuration::BeginPlay()
{
	Super::BeginPlay();

	SetActive(true);
}

bool AVTAK_EditPoint_Mensuration::GetTranslationAxisList_Implementation(EAxisListBlueprint& axisList)
{
	if (MensurationActor != nullptr)
	{
		axisList = bBase ? MensurationActor->AllowedBaseTranslation : MensurationActor->AllowedArrowTranslation;
	}
	else
	{
		axisList = EAxisListBlueprint::None;
	}

	return true;
}

bool AVTAK_EditPoint_Mensuration::GetRotationAxisList_Implementation(EAxisListBlueprint& axisList)
{
	if (MensurationActor != nullptr)
	{
		axisList = bBase ? MensurationActor->AllowedBaseRotation : MensurationActor->AllowedArrowRotation;
	}
	else
	{
		axisList = EAxisListBlueprint::None;
	}

	return true;
}

void AVTAK_EditPoint_Mensuration::PostManipulationBegin()
{
	if (UDeveloper_Subsystem_Operation* subsystem = UDeveloper_Subsystem_Operation::Get())
	{
		TSet<UGame_Operation_Drag*> dragOperations = subsystem->GetOperationsByClass<UGame_Operation_Drag>();
		for (UGame_Operation_Drag* dragOperation : dragOperations)
		{
			if (dragOperation->GetDraggedActor() == this)
			{
				// if dragging; add line to ignored actors for tool dragging
				DraggingTool = dragOperation->GetDraggingTool();

				DraggingTool->AddTraceIgnoredActor(MensurationActor->GetLine());
			}
		}
	}

	if (DraggingTool == nullptr)
	{
		if (UGame_Subsystem_Gizmo* subsystem = UGame_Subsystem_Gizmo::Get())
		{
			if (AGame_TransformGizmo* transformGizmo = subsystem->GetTransformGizmo())
			{
				if (subsystem->GetTransformGizmo()->GetTransformMode() == ETransformMode::ETM_Rotate)
				{
					FTransform transform;
					Execute_GetWorldTransform(this, transform);

					AGame_EditPoint* otherEditPoint = bBase ? MensurationActor->GetArrowEditPoint() : MensurationActor->GetBaseEditPoint();

					ManipulationBeginEditPointLocation = transform.InverseTransformPosition(otherEditPoint->GetActorLocation());
				}
			}
		}
	}
}

void AVTAK_EditPoint_Mensuration::PostManipulationInProgress()
{
	if (UGame_Subsystem_Gizmo* subsystem = UGame_Subsystem_Gizmo::Get())
	{
		if (IsValid(subsystem->GetTransformGizmo()) && subsystem->GetTransformGizmo()->GetTransformMode() == ETransformMode::ETM_Rotate)
		{
			FTransform transform;
			Execute_GetWorldTransform(this, transform);

			FTransform transformOverride = UGame_Statics::GetWorldTransformOverride(transform.GetLocation());

			transform.SetRotation(transformOverride.TransformRotation(GetActorQuat()));

			AGame_EditPoint* otherEditPoint = bBase ? MensurationActor->GetArrowEditPoint() : MensurationActor->GetBaseEditPoint();

			otherEditPoint->SetActorLocation(transform.TransformPosition(ManipulationBeginEditPointLocation));
			otherEditPoint->SyncGeoLocationToWorldLocation();
		}
	}

	if (bCollideDuringManipulation && bWorldLocationCacheValid)
	{
		if (UWorld* world = GetWorld())
		{
			// turn off collision with line and other point so it can invert and isn't restricted to only getting longer
			FCollisionQueryParams queryParams = FCollisionQueryParams::DefaultQueryParam;
			queryParams.AddIgnoredActor(MensurationActor->GetArrowEditPoint());
			queryParams.AddIgnoredActor(MensurationActor->GetBaseEditPoint());
			queryParams.AddIgnoredActor(MensurationActor->GetLine());

			TArray<FHitResult> hitResults;
			world->LineTraceMultiByChannel(hitResults, WorldLocationCache, GetActorLocation(), ECollisionChannel::ECC_Visibility, queryParams);

			if (hitResults.Num() > 0)
			{
				// if new location hit something, move back to previous location
				SetActorLocation(WorldLocationCache);

				// set gizmo to previous location
				if (UGame_Subsystem_Gizmo* subsystem = UGame_Subsystem_Gizmo::Get())
				{
					AGame_TransformGizmo* gizmo = subsystem->GetTransformGizmo();
					gizmo->SetActorLocation(WorldLocationCache);
					gizmo->ResetLastRay();
				}
			}
		}
	}

	WorldLocationCache = GetActorLocation();
	bWorldLocationCacheValid = true;	
}

void AVTAK_EditPoint_Mensuration::PostManipulationEnd()
{
	if (IsValid(DraggingTool))
	{
		DraggingTool->RemoveTraceIgnoredActor(MensurationActor->GetLine());

		DraggingTool = nullptr;
	}
}

bool AVTAK_EditPoint_Mensuration::PostClickPressed(AActor* actor, const FKey& buttonPressed)
{
	if (AGame_Tool* tool = Cast<AGame_Tool>(actor))
	{
		if (UGame_Subsystem_Gizmo* subsystem = UGame_Subsystem_Gizmo::Get())
		{
			subsystem->SetGizmoTo(this, ETransformMode::ETM_Translate);

			EAxisListBlueprint axisList;
			IInterface_Developer_Manipulation::Execute_GetTranslationAxisList(this, axisList);
		
			UGame_TransformBaseComponent* clickedComponent = subsystem->GetTransformGizmo()->SimulateMousePress(actor, ETransformMode::ETM_Translate, subsystem->AxisListToTransformAxis(axisList));

			tool->AddClickedComponent(clickedComponent);
		}
	}

	return true;
}

void AVTAK_EditPoint_Mensuration::PostClickReleased(AActor* actor, const FKey& buttonPressed)
{
	if (UGame_Subsystem_Gizmo* subsystem = UGame_Subsystem_Gizmo::Get())
	{
		subsystem->DestroyGizmo();
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void AVTAK_EditPoint_Mensuration::ShowLevel(bool bShowLevel)
{
	if (bShowLevel)
	{
		FTransform transform = UGame_Statics::GetWorldTransformOverride(GetActorLocation());
		LevelMeshComponent->SetWorldRotation(transform.GetRotation());
	}

	LevelMeshComponent->SetHiddenInGame(!bShowLevel);
}
