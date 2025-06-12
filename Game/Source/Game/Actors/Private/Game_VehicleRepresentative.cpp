// Required Includes
#include "Game_VehicleRepresentative.h"
#include "Game.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_VehicleRepresentative::AGame_VehicleRepresentative(const FObjectInitializer& objectInitializer) : Super(objectInitializer)
{
	DropperCategory = FName(TEXT("Vehicle"));
}