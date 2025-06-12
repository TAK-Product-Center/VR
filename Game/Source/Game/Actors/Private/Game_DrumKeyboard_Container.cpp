// Required Includes
#include "Game_DrumKeyboard_Container.h"

#include "Game_CameraComponent.h"
#include "Game_Pawn.h"
#include "Game_PlayerController.h"
#include "Game_Statics.h"
#include "Game_VirtualObjective.h"
#include "VH_GlobeReferenceActor.h"


// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_DrumKeyboard_Container::AGame_DrumKeyboard_Container(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	KeySpline = CreateDefaultSubobject<USplineComponent>(TEXT("KeySpline"));
	KeySpline->SetupAttachment(RootComponent);
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_DrumKeyboard_Container::BeginPlay()
{
	Super::BeginPlay();
}

#if WITH_EDITOR
void AGame_DrumKeyboard_Container::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	const FName NAME_USplineComponent = GET_MEMBER_NAME_CHECKED(AGame_DrumKeyboard_Container, KeySpline);

	if (PropertyChangedEvent.Property != NULL)
	{
		const FName propName = PropertyChangedEvent.MemberProperty->GetFName();
		if (propName == NAME_USplineComponent)
		{
			EditorSplineChanged();
		}
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void AGame_DrumKeyboard_Container::PostEditMove(bool bFinished)
{
	Super::PostEditMove(bFinished);
	EditorSplineChanged();
}
#endif

// ---------------------------------
// --- Interface_Keyboard_Container
// ---------------------------------

void AGame_DrumKeyboard_Container::InitializeForObject_Implementation(UObject* object)
{
	RepositionToObject(object);
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_DrumKeyboard_Container::RepositionToObject(UObject* object)
{
	if (AGame_PlayerController* playerController = Cast<AGame_PlayerController>(object))
	{
		if(AVH_GlobeReferenceActor* globe = playerController->GetActiveVO()->GetGlobeReference())
		{
			FVector headLocation;
			FRotator headRotation;
			playerController->GetPlayerViewPoint(headLocation, headRotation);

			double yaw = globe->WorldRotationToBearing(headRotation);
			FTransform playerTransform = UGame_Statics::GetPlayerWorldTransformOverride();

			if (AGame_Pawn* pawn = UGame_Statics::GetVHPlayerPawn())
			{
				FTransform cameraTransform = pawn->Camera->GetComponentTransform();
				playerTransform.SetLocation(pawn->GetActorLocation());
				cameraTransform.SetRotation(playerTransform.TransformRotation(FRotator(0, yaw, 0).Quaternion()));
				SetActorLocation(cameraTransform.TransformPosition(SpawnRelativeLocation));
				SetActorRotation(playerTransform.TransformRotation(FRotator(0, yaw, 0).Quaternion()));
			}
		}
	}
}
