#include "Game_ListEntry_Bloodhound.h"

#include "VH_UmgWidget_List.h"
#include "VH_COTManager.h"
#include "VH_COTEvent.h"
#include "VH_GlobeCoordConverter.h"
#include "VH_GlobeReferenceActor.h"
#include "Developer_Subsystem_UnitConverter.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

#include "Game_Pawn.h"
#include "Game_Point_Icon.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_Statics.h"
#include "Game_EntityDB.h"
#include "Game_PlayerController.h"
#include "Game_COTComponent.h"
#include "Game_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_ListEntry_Bloodhound::UGame_ListEntry_Bloodhound()
{

}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_ListEntry_Bloodhound::SetActor(AActor* inActor)
{
	if (Actor != inActor)
	{
		if (Actor != nullptr)
		{
			Actor->OnDestroyed.RemoveDynamic(this, &UGame_ListEntry_Bloodhound::HandleActorDestroyed);
		}

		Actor = inActor;

		if (Actor != nullptr)
		{
			Actor->OnDestroyed.AddDynamic(this, &UGame_ListEntry_Bloodhound::HandleActorDestroyed);
		}

		UpdateListEntryText();
	}
}

AActor* UGame_ListEntry_Bloodhound::GetActor() const
{
	return Actor;
}

void UGame_ListEntry_Bloodhound::UpdateListEntryText()
{
	FSlateBrush iconBrush = FSlateBrush();
	FString callsign = TEXT("");
	FString mgrs = TEXT("");
	float bearing = 0.f;
	float distance = 0.f;
	float elevation = 0.f;

	if (AGame_Pawn* pawn = Cast<AGame_Pawn>(Actor))
	{
		iconBrush.SetResourceObject((UObject*)PlayerIcon);

		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			callsign = cotManager->GetCallsign();
		}

		if (AGame_VirtualObjective* activeVO = AGame_PlayerController::GetPlayerActiveVO())
		{
			if (AVH_GlobeReferenceActor* globeRef = activeVO->GetGlobeReference())
			{
				mgrs = globeRef->WorldToMGRS(pawn->GetActorLocation());

				FGeodeticCoord3D pawnGeodetic = globeRef->WorldToGeodeticDouble(pawn->GetActorLocation());
				elevation = pawnGeodetic.Altitude;
			}
		}

		UpdateIcon(iconBrush);

		UpdateCallsign(callsign);

		UpdateMGRS(mgrs);

		UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings();

		FString bearingUnit = gameSettings->GetSettingString(TEXT("BearingUnit"));
		FString bearingString = UDeveloper_Subsystem_UnitConverter::Get()->ConvertUnitsAndFormat(TEXT("degrees"), FString::Printf(TEXT("%.8Lf"), bearing), bearingUnit, 2);
		UpdateBearing(bearingString);

		FString rangeUnit = gameSettings->GetSettingString(TEXT("RangeUnit"));
		if (rangeUnit == TEXT("miles") && distance < 1609.344f)
		{
			rangeUnit = TEXT("feet");
		}
		if (rangeUnit == TEXT("kilometers") && distance < 1000.f)
		{
			rangeUnit = TEXT("meters");
		}

		FString distanceString = UDeveloper_Subsystem_UnitConverter::Get()->ConvertUnitsAndFormat(TEXT("meters"), FString::Printf(TEXT("%.8Lf"), distance), rangeUnit, 2);
		UpdateDistance(distanceString);

		FString elevationString = UDeveloper_Subsystem_UnitConverter::Get()->ConvertUnitsAndFormat(TEXT("degrees"), FString::Printf(TEXT("%.8Lf"), elevation), bearingUnit, 2);
		if (elevationString[0] != TCHAR('-'))
		{
			elevationString = TEXT("+") + elevationString;
		}
		UpdateElevation(elevationString);
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_ListEntry_Bloodhound::HandleActorDestroyed(AActor* destroyedActor)
{
	if (OwningList != nullptr)
	{
		OwningList->RemoveEntry(this);
	}
}
