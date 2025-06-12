// Required includes
#include "Game_TOCTableHandleActor.h"
#include "Game.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_TOCTableHandleActor::AGame_TOCTableHandleActor(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Interface_Developer_Manipulation
// ---------------------------------

bool AGame_TOCTableHandleActor::GetTranslationAxisList_Implementation(EAxisListBlueprint& axisList)
{
	axisList = EAxisListBlueprint::XY;

	return true;
}
