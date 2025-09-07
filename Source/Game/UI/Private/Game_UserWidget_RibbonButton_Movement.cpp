// Required Includes
#include "Game_UserWidget_RibbonButton_Movement.h"
#include "Game.h"

// Game Includes
#include "Game_Pawn.h"
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_RibbonButton_Movement::UGame_UserWidget_RibbonButton_Movement(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer),
	TrackedMovementType(EMovementType::Walk)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool UGame_UserWidget_RibbonButton_Movement::Initialize()
{
	bool bToReturn = Super::Initialize();

	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		playerPawn->VRMovement->OnMovementTypeChanged.AddDynamic(this, &UGame_UserWidget_RibbonButton_Movement::HandleMovementTypeChanged);
	}

	return bToReturn;
}

void UGame_UserWidget_RibbonButton_Movement::NativeConstruct()
{
	Super::NativeConstruct();

	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		HandleMovementTypeChanged(playerPawn->VRMovement->GetMovementType());
	}
}

void UGame_UserWidget_RibbonButton_Movement::PostClicked()
{
	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		playerPawn->VRMovement->SetMovementType(TrackedMovementType);
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_RibbonButton_Movement::SetTrackedMovementType(EMovementType newMoveType)
{
	TrackedMovementType = newMoveType;

	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		HandleMovementTypeChanged(playerPawn->VRMovement->GetMovementType());
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_UserWidget_RibbonButton_Movement::HandleMovementTypeChanged(EMovementType movementType)
{
	SetSelected(movementType == TrackedMovementType);
}