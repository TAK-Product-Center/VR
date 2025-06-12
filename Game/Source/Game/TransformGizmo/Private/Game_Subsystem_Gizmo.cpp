// Required Includes
#include "Game_Subsystem_Gizmo.h"
#include "Game.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "Developer_Subsystem_Selection.h"
#include "VR_TraceComponent.h"

// Game Includes
#include "Game_TransformGizmo.h"
#include "Game_Subsystem_Gizmo_Settings.h"
#include "Game_Statics.h"
#include "Game_Tool.h"
#include "Game_Pawn.h"
#include "Game_MotionControllerComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_Subsystem_Gizmo::UGame_Subsystem_Gizmo() :
	TransformGizmo(nullptr)
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_Subsystem_Gizmo* UGame_Subsystem_Gizmo::Get()
{
	if (UWorld* world = UDeveloper_Statics::GetVHWorld())
	{
		return world->GetSubsystem<UGame_Subsystem_Gizmo>();
	}

	return nullptr;
}

ETransformAxis UGame_Subsystem_Gizmo::AxisListToTransformAxis(EAxisListBlueprint axisList)
{
	switch (axisList)
	{
		case EAxisListBlueprint::X:
			return ETransformAxis::TA_X;

		case EAxisListBlueprint::Y:
			return ETransformAxis::TA_Y;

		case EAxisListBlueprint::Z:
			return ETransformAxis::TA_Z;

		case EAxisListBlueprint::XY:
			return ETransformAxis::TA_XY;

		case EAxisListBlueprint::XZ:
			return ETransformAxis::TA_XZ;

		case EAxisListBlueprint::YZ:
			return ETransformAxis::TA_YZ;
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_Subsystem_Gizmo::AxisListToTransformAxis | could not find conversion | return ETransformAxis::TA_MAX"));
	return ETransformAxis::TA_MAX;
}

TSet<ETransformAxis> UGame_Subsystem_Gizmo::AxisListToTransformAxisSet(ETransformMode transformMode, EAxisListBlueprint axisList)
{
	TSet<ETransformAxis> allowedAxes;
	if (transformMode == ETransformMode::ETM_Translate)
	{
		if (axisList != EAxisListBlueprint::XYZ)
		{
			allowedAxes.Add(AxisListToTransformAxis(axisList));
		}
		else
		{
			allowedAxes.Add(ETransformAxis::TA_X);
			allowedAxes.Add(ETransformAxis::TA_Y);
			allowedAxes.Add(ETransformAxis::TA_Z);
			allowedAxes.Add(ETransformAxis::TA_XY);
			allowedAxes.Add(ETransformAxis::TA_XZ);
			allowedAxes.Add(ETransformAxis::TA_YZ);
		}
	}
	else if (transformMode == ETransformMode::ETM_Rotate)
	{
		switch (axisList)
		{
			case EAxisListBlueprint::X:
			case EAxisListBlueprint::Y:
			case EAxisListBlueprint::Z:
				allowedAxes.Add(AxisListToTransformAxis(axisList));
				break;

			case EAxisListBlueprint::XY:
				allowedAxes.Add(ETransformAxis::TA_X);
				allowedAxes.Add(ETransformAxis::TA_Y);
				break;

			case EAxisListBlueprint::YZ:
				allowedAxes.Add(ETransformAxis::TA_Y);
				allowedAxes.Add(ETransformAxis::TA_Z);
				break;

			case EAxisListBlueprint::XZ:
				allowedAxes.Add(ETransformAxis::TA_X);
				allowedAxes.Add(ETransformAxis::TA_Z);
				break;

			case EAxisListBlueprint::XYZ:
				allowedAxes.Add(ETransformAxis::TA_X);
				allowedAxes.Add(ETransformAxis::TA_Y);
				allowedAxes.Add(ETransformAxis::TA_Z);
				break;
		}
	}

	return allowedAxes;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_Subsystem_Gizmo::Initialize(FSubsystemCollectionBase& collection)
{
	Super::Initialize(collection);

	if (const UGame_Subsystem_Gizmo_Settings* settings = GetDefault<UGame_Subsystem_Gizmo_Settings>())
	{
		UpdateSettings(settings);
	}

	UGame_Subsystem_Gizmo::FGetInputRay getInputRayDelegate;
	getInputRayDelegate.BindLambda([](FVector& start, FVector& end)
		{
			if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
			{
				if (AGame_Tool* tool = Cast<AGame_Tool>(playerPawn->LeftController->GetInputToolStackTop()))
				{
					if (tool->GetInteract())
					{
						tool->VRTrace->GetStartAndEnd(start, end);

						return true;
					}
				}

				if (AGame_Tool* tool = Cast<AGame_Tool>(playerPawn->RightController->GetInputToolStackTop()))
				{
					if (tool->GetInteract())
					{
						tool->VRTrace->GetStartAndEnd(start, end);

						return true;
					}
				}
			}

			return false;
		});

	GetInputRayLambdas.Add(getInputRayDelegate);
}

bool UGame_Subsystem_Gizmo::ShouldCreateSubsystem(UObject* outer) const
{
	return true;
}

// ---------------------------------
// --- API
// ---------------------------------

AGame_TransformGizmo* UGame_Subsystem_Gizmo::GetTransformGizmo() const
{
	return TransformGizmo;
}

void UGame_Subsystem_Gizmo::SetGizmoTo(AActor* actor, ETransformMode transformMode)
{
	TSet<ETransformAxis> allowedAxes;
	if (actor->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()))
	{
		EAxisListBlueprint axisList;
		if (transformMode == ETransformMode::ETM_Translate && IInterface_Developer_Manipulation::Execute_GetTranslationAxisList(actor, axisList))
		{
			if (axisList != EAxisListBlueprint::XYZ)
			{
				allowedAxes.Add(AxisListToTransformAxis(axisList));
			}
			else
			{
				allowedAxes.Add(ETransformAxis::TA_X);
				allowedAxes.Add(ETransformAxis::TA_Y);
				allowedAxes.Add(ETransformAxis::TA_Z);
				allowedAxes.Add(ETransformAxis::TA_XY);
				allowedAxes.Add(ETransformAxis::TA_XZ);
				allowedAxes.Add(ETransformAxis::TA_YZ);
			}
		}
		else
		{
			if (transformMode == ETransformMode::ETM_Rotate && IInterface_Developer_Manipulation::Execute_GetRotationAxisList(actor, axisList))
			{
				switch (axisList)
				{
					case EAxisListBlueprint::X:
					case EAxisListBlueprint::Y:
					case EAxisListBlueprint::Z:
						allowedAxes.Add(AxisListToTransformAxis(axisList));
						break;

					case EAxisListBlueprint::XY:
						allowedAxes.Add(ETransformAxis::TA_X);
						allowedAxes.Add(ETransformAxis::TA_Y);
						break;

					case EAxisListBlueprint::YZ:
						allowedAxes.Add(ETransformAxis::TA_Y);
						allowedAxes.Add(ETransformAxis::TA_Z);
						break;

					case EAxisListBlueprint::XZ:
						allowedAxes.Add(ETransformAxis::TA_X);
						allowedAxes.Add(ETransformAxis::TA_Z);
						break;

					case EAxisListBlueprint::XYZ:
						allowedAxes.Add(ETransformAxis::TA_X);
						allowedAxes.Add(ETransformAxis::TA_Y);
						allowedAxes.Add(ETransformAxis::TA_Z);
						break;
				}
			}
			else
			{
				for (ETransformAxis axis : TEnumRange<ETransformAxis>())
				{
					allowedAxes.Add(axis);
				}
			}
		}
	}
	else
	{
		for (ETransformAxis axis : TEnumRange<ETransformAxis>())
		{
			allowedAxes.Add(axis);
		}
	}

	SetGizmoToWithAllowed(actor, transformMode, allowedAxes);
}

void UGame_Subsystem_Gizmo::SetGizmoToWithAllowed(AActor* actor, ETransformMode transformMode, const TSet<ETransformAxis>& allowedAxes)
{	
	if (actor == nullptr)
	{
		TransformGizmo->Destroy();
		TransformGizmo = nullptr;
	}
	else
	{
		if (TransformGizmo == nullptr)
		{
			const FTransform spawnTransform;
			TransformGizmo = GetWorld()->SpawnActorDeferred<AGame_TransformGizmo>(DefaultGizmoClass, spawnTransform, actor, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
			
			TransformGizmo->SetTransformMode(transformMode, allowedAxes);
			
			TransformGizmo->FinishSpawning(spawnTransform);
		}

		if (UDeveloper_Subsystem_Selection* subsystem = UDeveloper_Subsystem_Selection::Get())
		{
			subsystem->Select(actor, true);
		}
	}
}

bool UGame_Subsystem_Gizmo::DestroyGizmo()
{
	if (TransformGizmo != nullptr)
	{
		TransformGizmo->Destroy();
		TransformGizmo = nullptr;

		if (UDeveloper_Subsystem_Selection* subsystem = UDeveloper_Subsystem_Selection::Get())
		{
			subsystem->ClearSelections();
		}

		return true;
	}

	return false;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_Subsystem_Gizmo::UpdateSettings(const UGame_Subsystem_Gizmo_Settings* settings)
{
	DefaultGizmoClass = settings->DefaultGizmoClass;
	GizmoCollisionChannel = settings->GizmoCollisionChannel;
}