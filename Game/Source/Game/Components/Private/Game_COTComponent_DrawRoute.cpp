// Required Includes
#include "Game_COTComponent_DrawRoute.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_COTEvent.h"

// Game Includes
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_COTManager.h"
#include "Game_EditPoint_Route.h"
#include "Game_DrawLineData.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_COTComponent_DrawRoute::UGame_COTComponent_DrawRoute() :
    RouteCallsign(TEXT("Route"))
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_COTComponent_DrawRoute::AddEditPoint_Virtual(AGame_SimpleSegmentedLineActor* line, AGame_EditPoint* editPoint, AGame_EditPoint* existingEditPoint)
{
	Super::AddEditPoint_Virtual(line, editPoint, existingEditPoint);

	UpdateCallsigns();
}

void UGame_COTComponent_DrawRoute::DeleteEditPoint_Virtual(AGame_SimpleSegmentedLineActor* line, AGame_EditPoint* editPoint)
{
	Super::DeleteEditPoint_Virtual(line, editPoint);

	UpdateCallsigns();
}

void UGame_COTComponent_DrawRoute::DeleteEditPoints_Virtual(AGame_SimpleSegmentedLineActor* line)
{
	Super::DeleteEditPoints_Virtual(line);

	UpdateCallsigns();
}

void UGame_COTComponent_DrawRoute::ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent)
{
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
			line->SetColor(cotEvent->GetAttribute<FColor>(TEXT("detail\tlink_attr\tcolor")));

			DeleteEditPoints(line);

			TArray<FXmlNode*> links = cotEvent->GetNodes(TEXT("link"));
			for (FXmlNode* link : links)
			{
				QueuedLinks = cotEvent->GetNodes(TEXT("link"));
				AddQueuedLink();
			}
		}
	}
}

void UGame_COTComponent_DrawRoute::PopulateCOT_Virtual()
{
	Super::PopulateCOT_Virtual();

	if (Lines.Num() != 1)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_COTComponent_DrawRoute::PopulateCOT_Virtual | more than 1 line: %d"), Lines.Num());
		return;
	}

	if (UVH_COTEvent* cotEvent = GetCurrentCOTEvent())
	{
		cotEvent->SetAttribute(TEXT("type"), TEXT("b-m-r"));

		AGame_SimpleSegmentedLineActor* line = GetLines()[0];

		if (cotEvent->GetAttribute(TEXT("callsign")).IsEmpty())
		{
			cotEvent->SetAttribute(TEXT("callsign"), TEXT("Route"));  // todo ohg | create unique route callsign
		}

		cotEvent->PopulateTime(ActiveTime);

		cotEvent->SetAttribute<FColor>(TEXT("detail\tlink_attr\tcolor"), line->GetColor());

		if (cotEvent->GetAttribute(TEXT("detail\tlink_attr\tmethod")).IsEmpty())
		{
			cotEvent->SetAttribute(TEXT("detail\tlink_attr\tmethod"), TEXT("Driving"));
		}

		if (cotEvent->GetAttribute(TEXT("detail\tlink_attr\tdirection")).IsEmpty())
		{
			cotEvent->SetAttribute(TEXT("detail\tlink_attr\tdirection"), TEXT("Infil"));
		}

		if (cotEvent->GetAttribute(TEXT("detail\tlink_attr\troutetype")).IsEmpty())
		{
			cotEvent->SetAttribute(TEXT("detail\tlink_attr\troutetype"), TEXT("Primary"));
		}

		if (cotEvent->GetAttribute(TEXT("detail\tlink_attr\torder")).IsEmpty())
		{
			cotEvent->SetAttribute(TEXT("detail\tlink_attr\torder"), TEXT("Ascending"));
		}

		cotEvent->RemoveNodes(TEXT("link"));
		cotEvent->RemoveNodes(TEXT("detail\t__routeinfo\t__navcues"));

		TArray<AGame_EditPoint*> editPoints = Lines[line]->GetEditPoints();
		for (AGame_EditPoint* editPoint : editPoints)
		{
			AGame_EditPoint_Route* routeEditPoint = Cast<AGame_EditPoint_Route>(editPoint);

			FGeodeticCoord3D coordinate = editPoint->GetGeoLocation();

			FString uid = FGuid::NewGuid().ToString();

			TArray<FXmlAttribute> attributes;
			attributes.Add(FXmlAttribute(TEXT("uid"), uid));
			attributes.Add(FXmlAttribute(TEXT("point"), UVH_COTStatics::GetLongLatHAE(coordinate)));
			
			if (routeEditPoint->IsCheckpoint())
			{
				attributes.Add(FXmlAttribute(TEXT("type"), TEXT("b-m-p-w")));
				attributes.Add(FXmlAttribute(TEXT("callsign"), routeEditPoint->GetCallsign()));
			}
			else
			{
				attributes.Add(FXmlAttribute(TEXT("type"), TEXT("b-m-p-c")));
				attributes.Add(FXmlAttribute(TEXT("callsign"), TEXT("")));
			}

			cotEvent->AddNode(TEXT("link"), attributes);

			if (routeEditPoint->IsCheckpoint() && routeEditPoint->GetNavCue() != TEXT(""))
			{
				attributes.Empty();
				attributes.Add(FXmlAttribute(TEXT("id"), uid));
				attributes.Add(FXmlAttribute(TEXT("text"), routeEditPoint->GetNavCue()));
				attributes.Add(FXmlAttribute(TEXT("voice"), routeEditPoint->GetNavCue()));

				cotEvent->AddNode(TEXT("detail\t__routeinfo\t__navcues\t__navcue"), attributes);
			}
		}

		TArray<FXmlNode*> navCues = cotEvent->GetNodes(TEXT("detail\t__routeinfo\t__navcues\t__navcue"));
		for (FXmlNode* navCue : navCues)
		{
			TArray<FXmlAttribute> attributes;
			attributes.Add(FXmlAttribute(TEXT("mode"), TEXT("d")));
			attributes.Add(FXmlAttribute(TEXT("value"), TEXT("70")));

			navCue->AppendChildNode(TEXT("trigger"), TEXT(""), attributes);
		}
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_COTComponent_DrawRoute::UpdateCallsigns()
{
	int32 count = 1;

	if (Lines.Num() == 1)
	{
		AGame_SimpleSegmentedLineActor* line = GetLines()[0];

		TArray<AGame_EditPoint*> editPoints = Lines[line]->GetEditPoints();
		for (int32 i = 0; i < editPoints.Num(); i++)
		{
			AGame_EditPoint_Route* routeEditPoint = Cast<AGame_EditPoint_Route>(editPoints[i]);

			if (i == 0)
			{
				routeEditPoint->SetGeneratedCallsign(FString::Printf(TEXT("%s SP"), *RouteCallsign));

				bool bUserCheckpoint = routeEditPoint->GetUserCheckpoint();

				routeEditPoint->SetIsCheckpoint(true);
				routeEditPoint->SetUserCheckpoint(bUserCheckpoint);
			}
			else if (i == editPoints.Num() - 1)
			{
				FString generatedCallsign = TEXT("VDO");
				if (UVH_COTEvent* cotEvent = GetCurrentCOTEvent())
				{ 
					FString method = cotEvent->GetAttribute(TEXT("detail\tlink_attr\tmethod"));

					if (!method.IsEmpty() && !method.Equals(TEXT("Driving")))
					{
						generatedCallsign = TEXT("TGT");
					}
				}

				routeEditPoint->SetGeneratedCallsign(generatedCallsign);

				bool bUserCheckpoint = routeEditPoint->GetUserCheckpoint();

				routeEditPoint->SetIsCheckpoint(true);
				routeEditPoint->SetUserCheckpoint(bUserCheckpoint);
			}
			else
			{
				if (!routeEditPoint->GetUserCheckpoint())
				{
					routeEditPoint->SetIsCheckpoint(false);
				}

				if (routeEditPoint->IsCheckpoint() && routeEditPoint->GetUserCallsign().IsEmpty())
				{
					routeEditPoint->SetGeneratedCallsign(FString::Printf(TEXT("CP%d"), count));
					count++;
				}
				else
				{
					routeEditPoint->SetGeneratedCallsign(TEXT(""));
				}
			}
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_COTComponent_DrawRoute::AddQueuedLink()
{
	if (QueuedLinks.Num() > 0)
	{
		AGame_SimpleSegmentedLineActor* line = GetLines()[0];

		if (AGame_EditPoint_Route* editPoint = Cast<AGame_EditPoint_Route>(SpawnEditPoint(line, FVector(0, 0, 0), nullptr)))
		{
			FXmlNode* link = QueuedLinks[0];

			FGeodeticCoord3D linkCoordinate = UVH_COTStatics::LinkToCoordinate(link);
			editPoint->SetGeoLocation(linkCoordinate);
			editPoint->SyncWorldLocationToGeoLocation();

			FString linkType = link->GetAttribute(TEXT("type"));
			editPoint->SetIsCheckpoint(linkType.Equals(TEXT("b-m-p-w"), ESearchCase::IgnoreCase));
					
			if (editPoint->IsCheckpoint())
			{
				FString linkCallsign = link->GetAttribute(TEXT("callsign"));
				editPoint->SetUserCallsign(linkCallsign);

				FString linkUID = link->GetAttribute(TEXT("uid"));
						
				if (UVH_COTEvent* cotEvent = GetCurrentCOTEvent())
				{
					TArray<FXmlNode*> navCues = cotEvent->GetNodes(TEXT("detail\t__routeinfo\t__navcues\t__navcue"));
					for (FXmlNode* navCue : navCues)
					{
						if (navCue->GetAttribute(TEXT("id")).Equals(linkUID))
						{
							editPoint->SetNavCue(navCue->GetAttribute(TEXT("text")));
						}
					}
				}
			}

			editPoint->SetActive(false);
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_COTComponent_DrawRoute::AddQueuedLink | EditPointClass must be AGame_EditPoint_Route or child of it"));
		}

		QueuedLinks.RemoveAt(0, 1);

		if (QueuedLinks.Num() > 0)
		{
			FTimerHandle timerHandle;
			GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UGame_COTComponent_DrawRoute::AddQueuedLink, 0.01);
		}
		else
		{
			UpdateCallsigns();
		}
	}
}