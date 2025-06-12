// Required Includes
#include "Game_TransformGizmo.h"
#include "Game.h"

// Engine Includes
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Pawn.h"

// VH Plugin Includes
#include "Developer_Subsystem_Selection.h"
#include "Interface_Developer_Manipulation.h"

// Game Includes
#include "Game_Subsystem_Gizmo.h"
#include "Game_TranslationComponent.h"
#include "Game_RotationComponent.h"
#include "Game_ScaleComponent.h"
#include "Game_Statics.h"

const FString COMPONENT_SUFFIX[6] {
	"X", "Y", "Z", "XY", "XZ", "YZ"
};

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_TransformGizmo::AGame_TransformGizmo(const FObjectInitializer& objectInitializer) : 
	Super(objectInitializer), 
	DefaultTransformMode(ETransformMode::ETM_Translate),
	TranslationGizmoSensitivity(0.01f),
	RotationGizmoSensitivity(0.01f),
	ScaleGizmoSensitivity(0.01f),
	ScreenSize(0.0025f),
	TransformMode(ETransformMode::ETM_Translate)
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	// Init root components
	TranslationRoot = CreateDefaultSubobject<USceneComponent>(TEXT("TranslationRoot"));
	TranslationRoot->SetupAttachment(RootComponent);

	RotationRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RotationRoot"));
	RotationRoot->SetupAttachment(RootComponent);

	ScaleRoot = CreateDefaultSubobject<USceneComponent>(TEXT("ScaleRoot"));
	ScaleRoot->SetupAttachment(RootComponent);

	for (ETransformAxis axis : TEnumRange<ETransformAxis>())
	{
		// Create translation component
		FString tCompName = TEXT("TranslationComponent");
		tCompName += COMPONENT_SUFFIX[(uint8)axis];

		UGame_TranslationComponent* newTComponent = CreateDefaultSubobject<UGame_TranslationComponent>(FName(tCompName));
		newTComponent->SetAxisType(axis);
		newTComponent->SetupAttachment(TranslationRoot);
		newTComponent->SetSensitivity(TranslationGizmoSensitivity);
		newTComponent->TranslucencySortPriority = 80;

		TranslationComponents.Add(axis, newTComponent);

		// Create scale component
		FString sCompName = TEXT("ScaleComponent");
		sCompName += COMPONENT_SUFFIX[(uint8)axis];

		UGame_ScaleComponent* newSComponent = CreateDefaultSubobject<UGame_ScaleComponent>(FName(sCompName));
		newSComponent->SetAxisType(axis);
		newSComponent->SetupAttachment(ScaleRoot);
		newSComponent->SetSensitivity(ScaleGizmoSensitivity);
		newSComponent->TranslucencySortPriority = 80;

		ScaleComponents.Add(axis, newSComponent);

		// Rotation only matters on X/Y/Z, so don't create components for anything after Z.
		if (axis <= ETransformAxis::TA_Z)
		{
			// Create rotation component
			FString rCompName = TEXT("RotationComponent");
			rCompName += COMPONENT_SUFFIX[(uint8)axis];

			UGame_RotationComponent* newRComponent = CreateDefaultSubobject<UGame_RotationComponent>(FName(rCompName));
			newRComponent->SetAxisType(axis);
			newRComponent->SetupAttachment(RotationRoot);
			newRComponent->SetSensitivity(RotationGizmoSensitivity);
			newRComponent->TranslucencySortPriority = 80;

			RotationComponents.Add(axis, newRComponent);
		}
	}

	PrimaryActorTick.bCanEverTick = true;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_TransformGizmo::BeginPlay()
{
	Super::BeginPlay();

	for (ETransformAxis axis : TEnumRange<ETransformAxis>())
	{
		TranslationComponents[axis]->SetSensitivity(TranslationGizmoSensitivity);
		ScaleComponents[axis]->SetSensitivity(ScaleGizmoSensitivity);

		if (axis <= ETransformAxis::TA_Z)
		{
			RotationComponents[axis]->SetSensitivity(RotationGizmoSensitivity);
		}
	}

	if (APlayerController* playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		if (UEnhancedInputComponent* inputComponent = Cast<UEnhancedInputComponent>(playerController->InputComponent))
		{
			inputComponent->BindAction(ToggleModeInputAction, ETriggerEvent::Triggered, this, &AGame_TransformGizmo::HandleToggleTransformMode);
		}
	}
	
	if (UDeveloper_Subsystem_Selection* selectSubsystem = GetWorld()->GetSubsystem<UDeveloper_Subsystem_Selection>())
	{
		selectSubsystem->OnSelectionChanged.AddDynamic(this, &AGame_TransformGizmo::HandleSelectionChanged);
	}
}

void AGame_TransformGizmo::Tick(float deltaSeconds)
{
	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	FVector controllerGizmoVector = controller->GetPawn()->GetActorLocation() - GetActorLocation();

	// Update the gizmo's scale so that it has the same size on the screen at any distance.
	float size = controllerGizmoVector.Size() * ScreenSize;
	SetActorScale3D(FVector(size));
}
 
// ---------------------------------
// --- API
// ---------------------------------

ETransformMode AGame_TransformGizmo::GetTransformMode() const
{
	return TransformMode;
}

void AGame_TransformGizmo::SetTransformMode(ETransformMode mode, const TSet<ETransformAxis>& allowedAxes)
{
	TransformMode = mode;
	AllowedAxes = allowedAxes;
	
	for (const TPair<ETransformAxis, UGame_TranslationComponent*>& entry : TranslationComponents)
	{
		bool bActiveMode = TransformMode == ETransformMode::ETM_Translate;
		bool bAllowed = AllowedAxes.Contains(entry.Key);
		bool bIsHidden = !bActiveMode || !bAllowed;
		
		if (bActiveMode)
		{
			TranslationRoot->SetHiddenInGame(false, false);
		}

		entry.Value->SetHiddenInGame(bIsHidden);
		entry.Value->SetCollisionEnabled(bIsHidden ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryOnly);
	}
			
	for (const TPair<ETransformAxis, UGame_RotationComponent*>& entry : RotationComponents)
	{
		if (entry.Key > ETransformAxis::TA_Z)
		{
			continue;
		}

		bool bActiveMode = TransformMode == ETransformMode::ETM_Rotate;
		bool bAllowed = AllowedAxes.Contains(entry.Key);
		bool bIsHidden = !bActiveMode || !bAllowed;

		if (bActiveMode)
		{
			RotationRoot->SetHiddenInGame(false, false);
		}

		entry.Value->SetHiddenInGame(bIsHidden);
		
		entry.Value->SetCollisionEnabled(bIsHidden ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryOnly);
	}
	
	for (const TPair<ETransformAxis, UGame_ScaleComponent*>& entry : ScaleComponents)
	{
		bool bActiveMode = TransformMode == ETransformMode::ETM_Scale;
		bool bAllowed = AllowedAxes.Contains(entry.Key);
		bool bIsHidden = !bActiveMode || !bAllowed;

		if (bActiveMode)
		{
			ScaleRoot->SetHiddenInGame(false, false);
		}

		entry.Value->SetHiddenInGame(bIsHidden);
		entry.Value->SetCollisionEnabled(bIsHidden ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryOnly);
	}
}

ETransformOrigin AGame_TransformGizmo::GetTransformOrigin() const
{
	return TransformOrigin;
}

void AGame_TransformGizmo::SetTransformOrigin(ETransformOrigin origin)
{
	TransformOrigin = origin;

	for (ETransformAxis axis : TEnumRange<ETransformAxis>())
	{
		TranslationComponents[axis]->SetTransformOrigin(origin);
		ScaleComponents[axis]->SetTransformOrigin(origin);

		if (axis <= ETransformAxis::TA_Z)
		{
			RotationComponents[axis]->SetTransformOrigin(origin);
		}
	}
}

TSet<ETransformAxis> AGame_TransformGizmo::GetAllowedAxes() const
{
	return AllowedAxes;
}

UGame_TransformBaseComponent* AGame_TransformGizmo::SimulateMousePress(AActor* source, ETransformMode mode, ETransformAxis axis)
{
	UGame_TransformBaseComponent* component = nullptr;

	switch (mode)
	{
		case ETransformMode::ETM_Translate:
		{
			if (UGame_TranslationComponent** componentPtr = TranslationComponents.Find(axis))
			{
				component = *componentPtr;
			}
		}
		break;

		case ETransformMode::ETM_Rotate:
		{
			if (UGame_RotationComponent** componentPtr = RotationComponents.Find(axis))
			{
				component = *componentPtr;
			}
		}
		break;

		case ETransformMode::ETM_Scale:
		{
			if (UGame_ScaleComponent** componentPtr = ScaleComponents.Find(axis))
			{
				component = *componentPtr;
			}
		}
		break;
	}

	if (component != nullptr)
	{
		component->GetOwner()->OnClicked.Broadcast(source, EKeys::LeftMouseButton);
		component->OnClicked.Broadcast(component, EKeys::LeftMouseButton);
	}

	return component;
}

void AGame_TransformGizmo::ResetLastRay()
{
	for (ETransformAxis axis : TEnumRange<ETransformAxis>())
	{
		TranslationComponents[axis]->ResetLastRay();
		ScaleComponents[axis]->ResetLastRay();

		if (axis <= ETransformAxis::TA_Z)
		{
			RotationComponents[axis]->ResetLastRay();
		}
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

FTransform AGame_TransformGizmo::GetSelectedActorTransform() const
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

			if (UGame_Statics::IsLocalPlayerInTOC())
			{
				return lastSelectedActor->GetActorTransform();
			}
			
			return UGame_Statics::GetWorldTransformOverride(lastSelectedActor->GetActorLocation());
		}
	}

	return FTransform::Identity;
}

void AGame_TransformGizmo::UpdateComponentRotation()
{
	for (ETransformAxis axis : TEnumRange<ETransformAxis>())
	{
		TranslationComponents[axis]->UpdateComponentRotation();
		ScaleComponents[axis]->UpdateComponentRotation();

		if (axis <= ETransformAxis::TA_Z)
		{
			RotationComponents[axis]->UpdateComponentRotation();
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_TransformGizmo::HandleToggleTransformMode()
{
	bool bTranslationEnabled = false;
	bool bRotationEnabled = false;

	if (UDeveloper_Subsystem_Selection* selectSubsystem = GetWorld()->GetSubsystem<UDeveloper_Subsystem_Selection>())
	{
		if (AActor* lastSelectedActor = Cast<AActor>(selectSubsystem->GetLastSelected()))
		{
			if (lastSelectedActor->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()))
			{
				EAxisListBlueprint rotationAxisList = EAxisListBlueprint::XYZ;
				if (IInterface_Developer_Manipulation::Execute_GetRotationAxisList(lastSelectedActor, rotationAxisList))
				{
					bRotationEnabled = rotationAxisList != EAxisListBlueprint::None;
				}

				EAxisListBlueprint translationAxisList = EAxisListBlueprint::XYZ;
				if (IInterface_Developer_Manipulation::Execute_GetTranslationAxisList(lastSelectedActor, translationAxisList))
				{
					bTranslationEnabled = translationAxisList != EAxisListBlueprint::None;
				}

				switch (TransformMode)
				{
					case ETransformMode::ETM_Translate:
					{
						if (bRotationEnabled)
						{
							SetTransformOrigin(ETransformOrigin::ETO_Local);
							SetTransformMode(ETransformMode::ETM_Rotate, UGame_Subsystem_Gizmo::AxisListToTransformAxisSet(ETransformMode::ETM_Rotate, rotationAxisList));
						}
					}
					break;

					case ETransformMode::ETM_Rotate:
					{
						if (bTranslationEnabled)
						{
							SetTransformOrigin(ETransformOrigin::ETO_World);
							SetTransformMode(ETransformMode::ETM_Translate, UGame_Subsystem_Gizmo::AxisListToTransformAxisSet(ETransformMode::ETM_Translate, translationAxisList));
						}
					}
					break;
				}

				UpdateComponentRotation();
			}
		}
	}
}

void AGame_TransformGizmo::HandleSelectionChanged(UObject* object, bool bSelected)
{
	if (bSelected)
	{
		SetActorTransform(GetSelectedActorTransform());
	}
}