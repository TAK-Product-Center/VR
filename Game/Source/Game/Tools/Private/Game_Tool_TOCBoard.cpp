// Required Includes
#include "Game_Tool_TOCBoard.h"
#include "Game.h"

// VH Plugin Includes
#include "VR_TraceComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Tool_TOCBoard::AGame_Tool_TOCBoard(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_Tool_TOCBoard::BeginPlay()
{
	Super::BeginPlay();

	VRTrace->AddTraceChannel(SpawnTOCBoardCollisionChannel);
}

void AGame_Tool_TOCBoard::PostTriggerActionPressed()
{
	Super::PostTriggerActionPressed();

	TArray<FHitResult> hitResults;
	if (VRTrace->GetHitResults(SpawnTOCBoardCollisionChannel, hitResults))
	{
		TriggerPressed(SpawnTOCBoardCollisionChannel, hitResults);
	}
}