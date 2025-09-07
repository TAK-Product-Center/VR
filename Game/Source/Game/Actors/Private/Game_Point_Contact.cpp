// Required Includes
#include "Game_Point_Contact.h"
#include "Game.h"

// Engine Includes
#include "Engine/Texture.h"

// VH Plugin Includes
#include "VH_COTEvent.h"
#include "VH_COTManager.h"

// Game Includes
#include "Game_COTComponent.h"
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Point_Contact::AGame_Point_Contact(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

bool AGame_Point_Contact::PostClickPressed(AActor* actor, const FKey& buttonPressed)
{
	// return true prevents selection and opening context menu
	return true;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_Point_Contact::HandleReceivedCOTUpdate(UVH_COTEvent* cotEvent)
{
	Super::HandleReceivedCOTUpdate(cotEvent);

	if (IconMID != nullptr && cotEvent != nullptr)
	{
		UGame_Statics::PopulateContactMaterial(cotEvent, IconMID, MachineGeneratedIcon, UserIcon);

		OnIconChanged.Broadcast();
	}
}