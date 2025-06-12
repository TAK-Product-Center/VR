#include "Game_UserWidget_DetailSection_RoutePoints.h"

#include "VH_COTEvent.h"
#include "VH_COTManager.h"
#include "Developer_Statics.h"

#include "Game.h"
#include "Game_PlayerController.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_EditPoint_Route.h"
#include "Game_COTManager.h"

//--------------------
//--- Implementation
//--------------------

void UGame_UserWidget_DetailSection_RoutePoints::PopulateRouteEditPoints()
{
	TArray<FGeodeticCoord3D> coordinates;
	TArray<FString> navCues;
	TArray<FString> callsigns;
	TArray<bool> checkpointIndicators;

	AGame_VirtualObjective* activeVO = AGame_PlayerController::GetPlayerActiveVO();
	
	TArray<FXmlNode*> links = COTEvent->GetNodes(TEXT("link"));
	navCues.AddDefaulted(links.Num());

	for (int32 i = 0; i < links.Num(); i++)
	{
		FXmlNode* link = links[i];
		FGeodeticCoord3D linkCoordinate = UVH_COTStatics::LinkToCoordinate(link);

		coordinates.Add(linkCoordinate);

		TArray<FXmlNode*> cotNavCues = COTEvent->GetNodes(TEXT("detail\t__routeinfo\t__navcues\t__navcue"));
		if (!cotNavCues.IsEmpty()) 
		{
			FString linkUID = link->GetAttribute(TEXT("uid"));
			for (FXmlNode* cotNavCue : cotNavCues)
			{
				if (cotNavCue->GetAttribute(TEXT("id")).Equals(linkUID))
				{
					navCues[i] = cotNavCue->GetAttribute(TEXT("text"));
				}
			}
		}
			
		checkpointIndicators.Add(link->GetAttribute(TEXT("type")).Equals(TEXT("b-m-p-w"), ESearchCase::IgnoreCase));
		
		callsigns.Add(link->GetAttribute(TEXT("callsign")));
	}

	UpdateRoutePoints(coordinates, callsigns, navCues, checkpointIndicators);
}

void UGame_UserWidget_DetailSection_RoutePoints::PopulateEditPoints()
{
	if (COTEvent != nullptr)
	{
		FString type = COTEvent->GetAttribute(TEXT("type"));
		if (type.Equals(TEXT("b-m-r")))
		{
			PopulateRouteEditPoints();
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_DetailSection_RoutePoints::PopulateEditPoints | Not Route Type | %s"), *COTEvent->GetAttribute(TEXT("type")));
		}
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_UserWidget_DetailSection_RoutePoints::SetEntityUID | COTEvent is nullptr "));
	}
}

//--------------------
//--- API
//--------------------

void UGame_UserWidget_DetailSection_RoutePoints::UpdateNavCue(int32 index, const FString& newNavCue) 
{
	TArray<FXmlNode*> links = COTEvent->GetNodes(TEXT("link"));
	if (links.IsValidIndex(index))
	{
		FString uid = links[index]->GetAttribute(TEXT("uid"));

		TArray<FXmlNode*> navCues = COTEvent->GetNodes(TEXT("detail\t__routeinfo\t__navcues\t__navcue"));
		for (FXmlNode* navCue : navCues)
		{
			if (navCue->GetAttribute(TEXT("id")).Equals(uid))
			{
				navCue->SetAttribute(TEXT("text"), newNavCue);
				return;
			}
		}

		TArray<FXmlAttribute> attributes;
		attributes.Add(FXmlAttribute(TEXT("id"), uid));
		attributes.Add(FXmlAttribute(TEXT("text"), newNavCue));
		attributes.Add(FXmlAttribute(TEXT("voice"), newNavCue));

		COTEvent->AddNode(TEXT("detail\t__routeinfo\t__navcues\t__navcue"), attributes);
	}

	TArray<FXmlNode*> navCues = COTEvent->GetNodes(TEXT("detail\t__routeinfo\t__navcues\t__navcue"));
	for (FXmlNode* navCue : navCues)
	{
		TArray<FXmlAttribute> attributes;
		attributes.Add(FXmlAttribute(TEXT("mode"), TEXT("d")));
		attributes.Add(FXmlAttribute(TEXT("value"), TEXT("70")));

		navCue->AppendChildNode(TEXT("trigger"), TEXT(""), attributes);
	}
}

void UGame_UserWidget_DetailSection_RoutePoints::PromotePoint(int32 index)
{
	TArray<FXmlNode*> links = COTEvent->GetNodes(TEXT("link"));
	if (links.IsValidIndex(index))
	{
		links[index]->SetAttribute(TEXT("type"), TEXT("b-m-p-w"));
	}
}

void UGame_UserWidget_DetailSection_RoutePoints::DemotePoint(int32 index)
{
	TArray<FXmlNode*> links = COTEvent->GetNodes(TEXT("link"));
	if (links.IsValidIndex(index))
	{
		FString linkUID = links[index]->GetAttribute(TEXT("uid"));

		links[index]->SetAttribute(TEXT("type"), TEXT("b-m-p-c"));
		links[index]->SetAttribute(TEXT("callsign"), TEXT(""));

		TArray<FXmlNode*> navCues = COTEvent->GetNodes(TEXT("detail\t__routeinfo\t__navcues\t__navcue"));
		for (FXmlNode* navCue : navCues)
		{
			if (navCue->GetAttribute(TEXT("id")).Equals(linkUID))
			{
				TArray<FXmlNode*> navCueParent = COTEvent->GetNodes(TEXT("detail\t__routeinfo\t__navcues"));
				navCueParent[0]->RemoveChildNode(navCue);

				break;
			}
		}
	}
}

void UGame_UserWidget_DetailSection_RoutePoints::UpdateCallsign(int32 index, const FString& newCallsign)
{
	TArray<FXmlNode*> links = COTEvent->GetNodes(TEXT("link"));
	if (links.IsValidIndex(index))
	{
		links[index]->SetAttribute(TEXT("callsign"), newCallsign);
	}
}

void UGame_UserWidget_DetailSection_RoutePoints::UpdateEntity()
{
	if (COTEvent != nullptr)
	{
		if (UGame_COTManager* cotManager = Cast<UGame_COTManager>(UVH_COTManager::Get()))
		{
			cotManager->InsertOrUpdate(COTEvent);
		}

		if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
		{
			if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
			{
				SpatialiteResults results = entityDB->QueryUID(COTEvent->GetAttribute(TEXT("uid")));
				if (results.Num() > 0)
				{
					voManager->UpdateEntityGlobal(results[0]);
				}
			}
		}
	}
}
