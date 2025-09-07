// Required Includes
#include "Game_Mark.h"
#include "Game.h"

// Engine Includes
#include "Components/StaticMeshComponent.h"

// Game Includes
#include "Game_CameraScalingComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Mark::AGame_Mark(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	PlaneStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName(TEXT("PlaneStaticMeshComponent")));
	PlaneStaticMeshComponent->SetupAttachment(CameraScalingComponent);

	HoverScaleModifier = 1;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_Mark::SetActorHiddenInGame(bool bNewHidden)
{
	Super::SetActorHiddenInGame(bNewHidden);

	PlaneStaticMeshComponent->SetCollisionEnabled(bNewHidden ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryOnly);
}
