#include "Game_DrawContainer.h"
#include "Game.h"

#include "Components/SceneCaptureComponent2D.h"

#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_COTComponent_Draw.h"
#include "Game_EditPoint.h"
#include "Game_SimpleSegmentedLineActor.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_DrawContainer::AGame_DrawContainer()
{
	
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_DrawContainer::SetActorScale3D(FVector newScale3D)
{
	Super::SetActorScale3D(newScale3D);

	if (UGame_COTComponent_Draw* drawComponent = GetDrawComponent())
	{
		drawComponent->HandleOwnerSetScale3D(newScale3D);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_DrawContainer::SetActorScale3D | COTComponent does not extend Game_COTComponent_Draw"));
	}
}

void AGame_DrawContainer::SetActorHiddenInGame(bool bNewHidden)
{
	Super::SetActorHiddenInGame(bNewHidden);

	if (UGame_COTComponent_Draw* drawComponent = GetDrawComponent())
	{
		drawComponent->HandleOwnerSetHidden(bNewHidden);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- AGame_DrawContainer::SetActorHiddenInGame | COTComponent does not extend Game_COTComponent_Draw"));
	}
}

// ---------------------------------
// --- API
// ---------------------------------

UGame_COTComponent_Draw* AGame_DrawContainer::GetDrawComponent() const
{
	return Cast<UGame_COTComponent_Draw>(IInterface_COTReceiver::Execute_GetCOTComponent(this));
}

AGame_VirtualObjective* AGame_DrawContainer::GetVirtualObjective_Implementation() const
{
	return UGame_VirtualObjectiveManager::GetObjectVO(this);
}
