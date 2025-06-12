#include "Game_COTComponent_DrawTelestration.h"
#include "Game.h"
#include "Game_COTManager.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_DrawLineData.h"

#include "VH_COTEvent.h"
#include "VH_GlobeReferenceActor.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_COTComponent_DrawTelestration::UGame_COTComponent_DrawTelestration()
{
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_COTComponent_DrawTelestration::ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent)
{
	Super::ReceiveCOTUpdate_Virtual(cotEvent);

	if (cotEvent != nullptr)
	{
		AVH_GlobeReferenceActor* globeReference = GetGlobeReference();

		for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
		{
			entry.Value->ConditionalBeginDestroy();
		}

		Lines.Empty();

		FActorSpawnParameters spawnParams;
		spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		TArray<FXmlNode*> links = cotEvent->GetNodes(TEXT("link"));
		for (FXmlNode* link : links)
		{
			FString lineXML = link->GetAttribute(TEXT("line"));
			if (!lineXML.IsEmpty())
			{
				UVH_COTEvent* lineCOTEvent = NewObject<UVH_COTEvent>();
				if (lineCOTEvent->PopulateFromXML(lineXML))
				{
					AGame_SimpleSegmentedLineActor* line = SpawnLine();

					line->SetColor(lineCOTEvent->GetAttribute<FColor>(TEXT("strokeColor")));

					TArray<FXmlNode*> lineLinks = lineCOTEvent->GetNodes(TEXT("link"));
					for (FXmlNode* lineLink : lineLinks)
					{
						FGeodeticCoord3D coordinate = UVH_COTStatics::LinkToCoordinate(lineLink);
						FVector worldLocation = globeReference->GeodeticToWorldDouble(coordinate);

						line->AddLocationAndGeoLocation(worldLocation, coordinate);
					}
				}
			}
		}
	}
}

void UGame_COTComponent_DrawTelestration::PopulateCOT_Virtual()
{
	Super::PopulateCOT_Virtual();

	if (UVH_COTEvent* cotEvent = GetCurrentCOTEvent())
	{
		AVH_GlobeReferenceActor* globeRef = GetGlobeReference();

		cotEvent->SetAttribute(TEXT("type"), TEXT("u-d-f-m"));

		if (cotEvent->GetAttribute(TEXT("detail\ttitle\ttitle")).IsEmpty())
		{
			cotEvent->SetAttribute(TEXT("detail\ttitle\ttitle"), TEXT("Telestration"));  // todo ohg | create unique title
		}

		if (cotEvent->GetAttribute(TEXT("callsign")).IsEmpty())
		{
			cotEvent->SetAttribute(TEXT("callsign"), TEXT("Telestration"));  // todo ohg | create unique callsign
		}

		cotEvent->RemoveNodes(TEXT("link"));
		
		for (const TPair<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*>& entry : Lines)
		{
			AGame_SimpleSegmentedLineActor* line = entry.Key;

			float maxHeight = 0;
			TArray<FGeodeticCoord3D> lineCoordinates;
			for (int32 i = 0; i < line->LinePoints.Num(); i++)
			{
				lineCoordinates.Add(line->GetGeoLocation(i));

				FLinePoint linePoint = line->LinePoints[i];
				if (linePoint.Location.Z > maxHeight)
				{
					maxHeight = linePoint.Location.Z;
				}
			}

			cotEvent->SetAttribute<float>(TEXT("detail\theight"), maxHeight);
			cotEvent->SetAttribute(TEXT("detail\tstrokeStyle\tvalue"), TEXT("solid"));

			UVH_COTEvent* lineEvent = NewObject<UVH_COTEvent>();
			lineEvent->SetAttribute(TEXT("uid"), FGuid::NewGuid().ToString());
			lineEvent->SetAttribute(TEXT("type"), TEXT("u-d-f"));
			lineEvent->SetAttribute<FColor>(TEXT("strokeColor"), line->GetColor());
			lineEvent->SetAttribute(TEXT("detail\tstrokeStyle\tvalue"), TEXT("solid"));
			
			lineEvent->PopulateTime(ActiveTime);

			for (const FGeodeticCoord3D& lineCoordinate : lineCoordinates)
			{
				TArray<FXmlAttribute> attributes;
				attributes.Add(FXmlAttribute(TEXT("point"), UVH_COTStatics::GetLongLatHAE(lineCoordinate)));
				
				lineEvent->AddNode(TEXT("link"), attributes);
			}

			TArray<FXmlAttribute> attributes;
			attributes.Add(FXmlAttribute(TEXT("line"), lineEvent->ToXML()));

			cotEvent->AddNode(TEXT("link"), attributes);
		}
	}
}
