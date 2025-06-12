// Required Includes
#include "VTAK_COTComponent_Orbit.h"

// VH Plugin Includes
#include "VH_COTEvent.h"
#include "VH_GlobeReferenceActor.h"

// Game Includes
#include "Game_COTManager.h"
#include "Game_PlayerController.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"

// Module Includes
#include "VTAK_Actor_Orbit.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UVTAK_COTComponent_Orbit::UVTAK_COTComponent_Orbit()
{
	bGenerateCallsign = false;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

// Receieve a COT and do something with it
void UVTAK_COTComponent_Orbit::ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent)
{
	Super::ReceiveCOTUpdate_Virtual(cotEvent);

	if (cotEvent != nullptr)
	{
		if (AVH_GlobeReferenceActor* globeReference = GetGlobeReference())
		{
			if (AVTAK_Actor_Orbit* orbit = Cast<AVTAK_Actor_Orbit>(GetOwner()))
			{
				FVector worldLocation = globeReference->GeodeticToWorldDouble(cotEvent->GetPoint());

				orbit->SetActorLocation(worldLocation);
			}
		}
	}
}

// Make a COT and send it out
void UVTAK_COTComponent_Orbit::PopulateCOT_Virtual()
{
	Super::PopulateCOT_Virtual();

	if (UVH_COTEvent* cotEvent = GetCurrentCOTEvent())
	{
		cotEvent->SetAttribute(TEXT("type"), TEXT("u-d-o"));

		if (cotEvent->GetAttribute(TEXT("callsign")).IsEmpty())
		{
			cotEvent->SetAttribute(TEXT("callsign"), TEXT("Orbit"));  // todo ohg | create unique title
		}

		cotEvent->PopulateTime(ActiveTime);

		if (AGame_VirtualObjective* activeVO = AGame_PlayerController::GetPlayerActiveVO())
		{
			if (AVH_GlobeReferenceActor* globeReference = activeVO->GetGlobeReference())
			{
				FGeodeticCoord3D coordinate = globeReference->WorldToGeodeticDouble(GetOwner()->GetActorLocation());

				cotEvent->SetPoint(coordinate);
			}
		}
	}
}

// ---------------------------------
// --- API
// ---------------------------------

AVH_GlobeReferenceActor* UVTAK_COTComponent_Orbit::GetGlobeReference() const
{
	return UGame_VirtualObjectiveManager::GetObjectGlobeReference(GetOwner());
}

void UVTAK_COTComponent_Orbit::RegisterWithDatabase()
{
	if (AVTAK_Actor_Orbit* orbit = Cast<AVTAK_Actor_Orbit>(GetOwner()))
	{
		orbit->InsertIntoEntityDB();
	}
}