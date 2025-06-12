// Required Includes
#include "Game_SnapLocation.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_SnapLocation::AGame_SnapLocation()
{

}


// ---------------------------------
// --- API
// ---------------------------------

bool AGame_SnapLocation::DoesCurrentActorExist() const
{
	return IsValid(CurrentHeldActor);
}

void AGame_SnapLocation::SetCurrentHeldActor(AActor* newActor)
{
	CurrentHeldActor = newActor;
}

AActor* AGame_SnapLocation::GetCurrentHeldActor() const
{
	return CurrentHeldActor;
}