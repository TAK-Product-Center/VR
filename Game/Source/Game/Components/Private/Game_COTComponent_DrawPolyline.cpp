// Required Includes
#include "Game_COTComponent_DrawPolyline.h"
#include "Game.h"

// VH Includes
#include "VH_COTEvent.h"

// Game Includes
#include "Game_COTManager.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_EditPoint.h"
#include "Game_DrawLineData.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_COTComponent_DrawPolyline::UGame_COTComponent_DrawPolyline()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_COTComponent_DrawPolyline::ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent)
{
	UE_LOG(LogTemp, Warning, TEXT("-- UGame_COTComponent_DrawPolyline::ReceiveCOTUpdate_Virtual"));
	Super::ReceiveCOTUpdate_Virtual(cotEvent);

	if (cotEvent != nullptr)
	{
		if (Lines.Num() == 0)
		{
			SpawnLine();
		}

		if (Lines.Num() == 1)
		{
			AGame_SimpleSegmentedLineActor* line = GetLines()[0];
			line->SetColor(cotEvent->GetAttribute<FColor>(TEXT("strokeColor")));

			DeleteEditPoints(line);

			QueuedLinks = cotEvent->GetNodes(TEXT("link"));
			AddQueuedLink();
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("UGame_COTComponent_DrawPolyline::ReceiveCOTUpdate_Virtual | invalid number of lines: %d"), Lines.Num());
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("-- UGame_COTComponent_DrawPolyline::ReceiveCOTUpdate_Virtual2"));
}

void UGame_COTComponent_DrawPolyline::PopulateCOT_Virtual()
{
	Super::PopulateCOT_Virtual();

	if (Lines.Num() != 1)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_COTComponent_DrawPolyline::PopulateCOT_Virtual | more than 1 line: %d"), Lines.Num());
		return;
	}

	if (UVH_COTEvent* cotEvent = GetCurrentCOTEvent())
	{
		AGame_SimpleSegmentedLineActor* line = GetLines()[0];

		cotEvent->SetAttribute(TEXT("type"), TEXT("u-d-f"));

		if (cotEvent->GetAttribute(TEXT("callsign")).IsEmpty())
		{
			cotEvent->SetAttribute(TEXT("callsign"), TEXT("Polyline"));  // todo ohg | create unique title
		}

		cotEvent->PopulateTime(ActiveTime);

		cotEvent->SetAttribute<double>(TEXT("detail\theight\tvalue"), 0);
		cotEvent->SetAttribute<int32>(TEXT("detail\theight_unit\tvalue"), 1);
		cotEvent->SetAttribute<int32>(TEXT("fillColor"), 16777216);
		cotEvent->SetAttribute<FColor>(TEXT("strokeColor"), line->GetColor());

		cotEvent->RemoveNodes(TEXT("link"));

		TArray<AGame_EditPoint*> editPoints = Lines[line]->GetEditPoints();
		for (AGame_EditPoint* editPoint : editPoints)
		{
			FGeodeticCoord3D coordinate = editPoint->GetGeoLocation();

			TArray<FXmlAttribute> attributes;
			attributes.Add(FXmlAttribute(TEXT("point"), UVH_COTStatics::GetLongLatHAE(coordinate)));
			
			cotEvent->AddNode(TEXT("link"), attributes);
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_COTComponent_DrawPolyline::AddQueuedLink()
{
	if (QueuedLinks.Num() > 0)
	{
		AGame_SimpleSegmentedLineActor* line = GetLines()[0];

		AGame_EditPoint* editPoint = SpawnEditPoint(line, FVector(0, 0, 0), nullptr);
		editPoint->SetActive(false);
		editPoint->SetGeoLocation(UVH_COTStatics::LinkToCoordinate(QueuedLinks[0]));
		editPoint->SyncWorldLocationToGeoLocation();

		QueuedLinks.RemoveAt(0, 1);

		if (QueuedLinks.Num() > 0)
		{
			FTimerHandle timerHandle;
			GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UGame_COTComponent_DrawPolyline::AddQueuedLink, 0.01);
		}
	}
}
