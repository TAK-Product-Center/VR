// Required includes
#include "VTAK_Line_Mensuration.h"
#include "VTAK_Mensuration.h"

// VH Plugin Includes
#include "Game_Subsystem_Gizmo.h"
#include "Game_TransformGizmo.h"

// Game Includes
#include "Game_PlayerState.h"
#include "Game_EditPoint.h"
#include "Game_Statics.h"

// Module Includes
#include "VTAK_Actor_Mensuration.h"

// --------------------------------- 
// --- Constructors
// ---------------------------------

AVTAK_Line_Mensuration::AVTAK_Line_Mensuration(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	FixedUILineScaleTOC(0.01)
{

}

// ---------------------------------
// --- Interface_Developer_Manipulation
// ---------------------------------

bool AVTAK_Line_Mensuration::GetWorldTransform_Implementation(FTransform& localToWorld)
{
	FVector baseToArrow = MensurationActor->GetArrowEditPoint()->GetActorLocation() - MensurationActor->GetBaseEditPoint()->GetActorLocation();

	localToWorld.SetLocation(MensurationActor->GetBaseEditPoint()->GetActorLocation() + (baseToArrow * 0.5));
	localToWorld.SetRotation(UGame_Statics::GetWorldTransformOverride(localToWorld.GetLocation()).GetRotation());
	localToWorld.SetScale3D(FVector(1, 1, 1));

	return true;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool AVTAK_Line_Mensuration::GetTranslationAxisList_Implementation(EAxisListBlueprint& axisList)
{
	if (MensurationActor != nullptr)
	{
		axisList = MensurationActor->AllowedLineTranslation;
	}
	else
	{
		axisList = EAxisListBlueprint::None;
	}

	return true;
}

bool AVTAK_Line_Mensuration::GetRotationAxisList_Implementation(EAxisListBlueprint& axisList)
{
	if (MensurationActor != nullptr)
	{
		axisList = MensurationActor->AllowedLineRotation;
	}
	else
	{
		axisList = EAxisListBlueprint::None;
	}

	return true;
}

void AVTAK_Line_Mensuration::PostManipulationBegin()
{
	if (UGame_Subsystem_Gizmo* subsystem = UGame_Subsystem_Gizmo::Get())
	{
		if (AGame_TransformGizmo* transformGizmo = subsystem->GetTransformGizmo())
		{
			FTransform transform;
			switch (transformGizmo->GetTransformMode())
			{
				case ETransformMode::ETM_Translate:
					transform = GetActorTransform();
					break;

				case ETransformMode::ETM_Rotate:
					Execute_GetWorldTransform(this, transform);
					break;
			} 

			ManipulationBeginBaseLocation = transform.InverseTransformPosition(MensurationActor->GetBaseEditPoint()->GetActorLocation());
			ManipulationBeginArrowLocation = transform.InverseTransformPosition(MensurationActor->GetArrowEditPoint()->GetActorLocation());
		}
	}
}

void AVTAK_Line_Mensuration::PostManipulationInProgress()
{
	if (UGame_Subsystem_Gizmo* subsystem = UGame_Subsystem_Gizmo::Get())
	{
		if (AGame_TransformGizmo* transformGizmo = subsystem->GetTransformGizmo())
		{
			FTransform transform;
			switch (transformGizmo->GetTransformMode())
			{
				case ETransformMode::ETM_Translate:
					transform = GetActorTransform();
					break;

				case ETransformMode::ETM_Rotate:
					Execute_GetWorldTransform(this, transform);

					FTransform transformOverride = UGame_Statics::GetWorldTransformOverride(transform.GetLocation());

					transform.SetRotation(transformOverride.TransformRotation(GetActorQuat()));
					break;
			}
				
			MensurationActor->GetBaseEditPoint()->SetActorLocation(transform.TransformPosition(ManipulationBeginBaseLocation));
			MensurationActor->GetBaseEditPoint()->SyncGeoLocationToWorldLocation();

			MensurationActor->GetArrowEditPoint()->SetActorLocation(transform.TransformPosition(ManipulationBeginArrowLocation));
			MensurationActor->GetArrowEditPoint()->SyncGeoLocationToWorldLocation();
		}
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

FTransform AVTAK_Line_Mensuration::GetLineManipulationTransform() const
{
	FTransform localToWorld = FTransform::Identity;

	if (MensurationActor != nullptr)
	{
		// center of line, facing from base to arrow
		FVector baseToArrow = MensurationActor->GetArrowEditPoint()->GetActorLocation() - MensurationActor->GetBaseEditPoint()->GetActorLocation();

		localToWorld.SetLocation(MensurationActor->GetBaseEditPoint()->GetActorLocation() + (baseToArrow * 0.5));
		localToWorld.SetRotation(baseToArrow.ToOrientationRotator().Quaternion());
		localToWorld.SetScale3D(GetActorScale3D());
	}
	else
	{
		UE_LOG(VTAK_Mensuration, Warning, TEXT("-- AVTAK_Line_Mensuration::GetLineManipulationTransform | MensurationActor is nullptr | returning FTransform::Identity"));
	}

	return localToWorld;
}