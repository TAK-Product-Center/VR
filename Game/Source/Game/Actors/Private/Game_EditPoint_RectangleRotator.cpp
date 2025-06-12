// Required Includes
#include "Game_EditPoint_RectangleRotator.h"
#include "Game.h"

// Engine Includes
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_EditPoint_RectangleRotator::AGame_EditPoint_RectangleRotator(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	MID(nullptr),
	Thickness(2.f)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_EditPoint_RectangleRotator::BeginPlay()
{
	Super::BeginPlay();

	if (ShapeMeshComponent != nullptr)
	{
		MID = ShapeMeshComponent->CreateDynamicMaterialInstance(0);

		SetThickness(1.f);
	}
}


// ---------------------------------
// --- API
// ---------------------------------

bool AGame_EditPoint_RectangleRotator::SetThickness(const float& thicknessMultiplier)
{
	if (MID != nullptr)
	{
		MID->SetScalarParameterValue(FName(TEXT("ThickenAmount")), Thickness * thicknessMultiplier);

		return true;
	}

	return false;
}