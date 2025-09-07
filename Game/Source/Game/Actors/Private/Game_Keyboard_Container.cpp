// Required Includes
#include "Game_Keyboard_Container.h"
#include "Game.h"

// VH Plugin Includes
#include "VR_MotionControllerComponent.h"

// Game Includes
#include "Game_Statics.h"
#include "Game_Pawn.h"
#include "Game_Tool.h"
#include "Game_MotionControllerComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Keyboard_Container::AGame_Keyboard_Container(const FObjectInitializer& objectInitializer) : 
	Super(objectInitializer)
{
	
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_Keyboard_Container::StartDrag()
{
	if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
	{
		if (AGame_Tool* gameTool = Cast<AGame_Tool>(playerPawn->LeftController->GetInputToolStackTop()))
		{
			if (gameTool->GetHoveredActor() == this)
			{
				AttachToActor(gameTool, FAttachmentTransformRules::KeepWorldTransform);

				return;
			}
		}

		if (AGame_Tool* gameTool = Cast<AGame_Tool>(playerPawn->RightController->GetInputToolStackTop()))
		{
			if (gameTool->GetHoveredActor() == this)
			{
				AttachToActor(gameTool, FAttachmentTransformRules::KeepWorldTransform);
			}
		}
	}
}

void AGame_Keyboard_Container::EndDrag()
{
	DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
}