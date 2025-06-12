// Required Includes
#include "Game_TOCBoard.h"
#include "Game.h"

// Engine Includes
#include "Misc/Guid.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Framework/Application/SlateApplication.h"
#include "Engine/World.h"

// VH Plugin Includes
#include "Developer_Subsystem_Operation.h"
#include "Database_Spatialite.h"
#include "VR_TraceComponent.h"

// Game Includes
#include "Game_Operation_Drag_TOCBoard.h"
#include "Game_PopoutInputListener.h"
#include "Game_Tool.h"

// ---------------------------------
// --- Static Variables
// ---------------------------------

TSharedPtr<AGame_PopoutInputListener> AGame_TOCBoard::SharedListener = nullptr;

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_TOCBoard::AGame_TOCBoard(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	ScaleMultiplerIncrement(0.25),
	ScaleMultiplier(1),
	bCanAdjustDist(true)
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("StaticMeshRoot")));

	StaticMesh->OnComponentHit.AddDynamic(this, &AGame_TOCBoard::OnHit);

	RootComponent = StaticMesh;

	CollisionMesh = CreateDefaultSubobject<UBoxComponent>(FName("CollisionMesh"));

	CollisionMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	CollisionMesh->SetBoxExtent(FVector(32, 230, 140));
	CollisionMesh->SetRelativeLocation(FVector(17, 0, 5));

	CollisionMesh->OnComponentEndOverlap.AddDynamic(this, &AGame_TOCBoard::OnEndOverlap);
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_TOCBoard::BeginPlay()
{
	Super::BeginPlay();

	OriginalScale = GetActorScale3D();

	ID = FGuid::NewGuid().ToString();

	if (!SharedListener.IsValid())
	{
		SharedListener = MakeShareable(new AGame_PopoutInputListener);

		if (ensure(FSlateApplication::IsInitialized()))
		{
			FSlateApplication::Get().RegisterInputPreProcessor(SharedListener);
		}
	}

	SharedListener->RegisterListener(this);
}

void AGame_TOCBoard::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	SharedListener->UnregisterListener(this);
}

bool AGame_TOCBoard::PostClickPressed(AActor* actor, const FKey& buttonPressed)
{
	return !AllowInteraction(actor);
}

void AGame_TOCBoard::PostClickReleased(AActor* actor, const FKey& buttonReleased)
{
	if (!AllowInteraction(actor))
	{
		ClickPressedTime = 0;
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_TOCBoard::ScaleUp()
{
	ScaleMultiplier += ScaleMultiplerIncrement;

	FVector scale = OriginalScale * ScaleMultiplier;
	scale.X = OriginalScale.X;

	SetActorScale3D(scale);
}

void AGame_TOCBoard::ScaleDown()
{
	ScaleMultiplier = FMath::Max<double>(ScaleMultiplier - ScaleMultiplerIncrement, 0.5);

	FVector scale = OriginalScale * ScaleMultiplier;
	scale.X = OriginalScale.X;

	SetActorScale3D(scale);
}

void AGame_TOCBoard::OnHit(UPrimitiveComponent* hitComponent, AActor* otherActor, UPrimitiveComponent* otherComp, FVector normalImpulse, const FHitResult& hit)
{
	bCanAdjustDist = false;
}

void AGame_TOCBoard::OnEndOverlap(UPrimitiveComponent* overlappedComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex)
{
	bCanAdjustDist = true;
}

void AGame_TOCBoard::SyncToResult(const SpatialiteResult& result)
{
	SetID(UDatabase_Spatialite::GetString(TEXT("boardID"), result));
	
	ReceiveSetURL(UDatabase_Spatialite::GetString(TEXT("url"), result));

	FTransform transform;
	transform.InitFromString(UDatabase_Spatialite::GetString(TEXT("transform"), result));

	SetActorTransform(transform, false, nullptr, ETeleportType::ResetPhysics);
}

void AGame_TOCBoard::SetID(const FString& id)
{
	ID = id;
}

FString AGame_TOCBoard::GetID() const
{
	return ID;
}

bool AGame_TOCBoard::GetCanAdjustDist() const
{
	return bCanAdjustDist;
}

void AGame_TOCBoard::SetCanAdjustDist(bool bNewCanAdjustDist)
{
	bCanAdjustDist = bNewCanAdjustDist;
}

void AGame_TOCBoard::HandleKeyDownEvent(const FKeyEvent& inKeyEvent)
{
	if (inKeyEvent.IsAltDown() && inKeyEvent.GetKey().GetFName().IsEqual("T"))
	{
		AttemptShortcutToggle();
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

bool AGame_TOCBoard::AllowInteraction(AActor* actor) const
{
	if (AGame_Tool* tool = Cast<AGame_Tool>(actor))
	{
		FVector start;
		FVector end;
		tool->VRTrace->GetStartAndEnd(start, end);

		FHitResult hitResult;
		FCollisionObjectQueryParams objectParams = FCollisionObjectQueryParams(ECC_WorldStatic);
		GetWorld()->LineTraceSingleByObjectType(hitResult, start, end, objectParams);

		FVector interactionHitLocation;
		tool->GetInteractionHitLocation(interactionHitLocation);

		if (hitResult.bBlockingHit && hitResult.Distance < (start - interactionHitLocation).Size())
		{
			return false;
		}

		return true;
	}

	return true;
}