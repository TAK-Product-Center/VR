#include "Game_UserWidget_SendTo.h"

#include "VH_COTComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_SendTo::UGame_UserWidget_SendTo(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_SendTo::SetCOTComponent(UVH_COTComponent* inCOTComponent)
{
	if (COTComponent != inCOTComponent)
	{
		COTComponent = inCOTComponent;

		ReceiveSetCOTComponent(COTComponent);
	}
}