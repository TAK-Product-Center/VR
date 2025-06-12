// Required includes
#include "VTAK_COTComponent_DrawMensuration.h"
#include "VTAK_Mensuration.h"

// VH Plugin includes
#include "VH_COTEvent.h"
#include "VH_GlobeMathStatics.h"

// Game layer includes
#include "Game_EditPoint.h"
#include "Game_COTManager.h"
#include "Game_DrawLineData.h"

// VH Mensuration includes
#include "VTAK_DrawContainer_Mensuration.h"
#include "VTAK_Line_Mensuration.h"
#include "VTAK_Actor_Mensuration.h"
#include "VTAK_Actor_Mensuration_Angle.h"
#include "VTAK_Actor_Mensuration_Range.h"
#include "VTAK_Actor_Mensuration_Height.h"
#include "VTAK_EditPoint_Mensuration.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UVTAK_COTComponent_DrawMensuration::UVTAK_COTComponent_DrawMensuration()
{
	bGenerateCallsign = false;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UVTAK_COTComponent_DrawMensuration::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	if (Mensuration != nullptr)
	{
		Mensuration->Destroy();
	}

	Super::EndPlay(endPlayReason);
}

void UVTAK_COTComponent_DrawMensuration::ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent)
{
	Super::ReceiveCOTUpdate_Virtual(cotEvent);

	if (cotEvent != nullptr)
	{
		if (Mensuration == nullptr)
		{
			SpawnMensuration(FVector(0.f, 0.f, 0.f));
		}

		if (Mensuration != nullptr)
		{
			AVTAK_Line_Mensuration* line = Cast<AVTAK_Line_Mensuration>(Mensuration->GetLine());
			AVH_GlobeReferenceActor* globeRef = GetGlobeReference();

			TArray<AVTAK_EditPoint_Mensuration*> editPoints = Mensuration->GetEditPoints();

			TArray<FXmlNode*> links = cotEvent->GetNodes(TEXT("link"));
			for (int32 i = 0; i < editPoints.Num(); i++)
			{
				if (editPoints[i] != nullptr)
				{
					if (links.IsValidIndex(i))
					{
						FGeodeticCoord3D coordinate = UVH_COTStatics::LinkToCoordinate(links[i]);
						editPoints[i]->SetGeoLocation(coordinate);
						editPoints[i]->SyncWorldLocationToGeoLocation();
					}
				}
			}
			
			line->SetColor(cotEvent->GetAttribute<FColor>(TEXT("strokeColor")));
		}
	}
}

void UVTAK_COTComponent_DrawMensuration::PopulateCOT_Virtual()
{
	Super::PopulateCOT_Virtual();

	UVH_COTEvent* cotEvent = GetCurrentCOTEvent();
	if (cotEvent != nullptr && Mensuration != nullptr)
	{
		AVTAK_Line_Mensuration* line = Cast<AVTAK_Line_Mensuration>(Mensuration->GetLine());

		if (Cast<AVTAK_Actor_Mensuration_Angle>(Mensuration))
		{
			cotEvent->SetAttribute(TEXT("type"), TEXT("u-d-m-a"));
		}
		else if (Cast<AVTAK_Actor_Mensuration_Range>(Mensuration))
		{
			cotEvent->SetAttribute(TEXT("type"), TEXT("u-d-m-r"));
		}
		else if (Cast<AVTAK_Actor_Mensuration_Height>(Mensuration))
		{
			cotEvent->SetAttribute(TEXT("type"), TEXT("u-d-m-h"));
		}
		else
		{
			UE_LOG(VTAK_Mensuration, Warning, TEXT("-- UVTAK_COTComponent_DrawMensuration::PopulateCOT_Virtual | unknown mensuration type"));
		}

		if (cotEvent->GetAttribute(TEXT("callsign")).IsEmpty())
		{
			cotEvent->SetAttribute(TEXT("callsign"), TEXT("Mensuration"));  // todo ohg | create unique title
		}

		cotEvent->PopulateTime(ActiveTime);

		cotEvent->SetAttribute<FColor>(TEXT("strokeColor"), line->GetColor());

		cotEvent->RemoveNodes(TEXT("link"));

		for (AVTAK_EditPoint_Mensuration* editPoint : Mensuration->GetEditPoints())
		{
			FGeodeticCoord3D coordinate = editPoint->GetGeoLocation();

			TArray<FXmlAttribute> attributes;
			attributes.Add(FXmlAttribute(TEXT("point"), UVH_COTStatics::GetLongLatHAE(coordinate)));

			cotEvent->AddNode(TEXT("link"), attributes);
		}
	}
}

void UVTAK_COTComponent_DrawMensuration::SetEditPointsActive(AGame_SimpleSegmentedLineActor* line, bool bActive)
{
	// The Mensuration tool edit points are always active
	Super::SetEditPointsActive(line, true);
}

void UVTAK_COTComponent_DrawMensuration::SnapToGround()
{
}

void UVTAK_COTComponent_DrawMensuration::HandleOwnerSetHidden(bool bNewHidden)
{
	Super::HandleOwnerSetHidden(bNewHidden);

	if (Mensuration != nullptr)
	{
		Mensuration->SetActorHiddenInGame(bNewHidden);
	}
}

void UVTAK_COTComponent_DrawMensuration::HandleOwnerSetScale3D(const FVector& scale3D)
{
	if (IsValid(Mensuration))
	{
		Mensuration->SetActorScale3D(scale3D);
	}
}

// ---------------------------------
// --- API
// ---------------------------------

AVTAK_Actor_Mensuration* UVTAK_COTComponent_DrawMensuration::SpawnMensuration(const FVector& editPointLocation, const TSubclassOf<AVTAK_Actor_Mensuration> mnsClass /* = nullptr */)
{
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = GetOwner();
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if (UWorld* world = GetWorld())
	{
		TSubclassOf<AVTAK_Actor_Mensuration> mensurClass;

		if (mnsClass)
		{
			mensurClass = mnsClass;
		}
		else if (MensurationClass)
		{
			mensurClass = MensurationClass;
		}
		else
		{
			UE_LOG(VTAK_Mensuration, Warning, TEXT("-- UVTAK_COTComponent_DrawMensuration::SpawnMensuration -- Both of the classes to spawn are nullptr"));
			return nullptr;
		}

		Mensuration = Cast<AVTAK_Actor_Mensuration>(world->SpawnActor<AVTAK_Actor_Mensuration>(mensurClass, editPointLocation, FRotator(0.f, 0.f, 0.f), spawnParams));
		if (Mensuration != nullptr)
		{
			if (AVTAK_Line_Mensuration* line = Cast<AVTAK_Line_Mensuration>(Mensuration->GetLine()))
			{
				AVTAK_DrawContainer_Mensuration* drawContainer = Cast<AVTAK_DrawContainer_Mensuration>(GetOwner());

				line->DrawContainer = drawContainer;
				AddLine(line);

				for (AVTAK_EditPoint_Mensuration* editPoint : Mensuration->GetEditPoints())
				{
					if (editPoint != nullptr)
					{
						editPoint->DrawContainer = drawContainer;
						AddEditPoint(line, editPoint, nullptr);
						editPoint->SyncGeoLocationToWorldLocation();
					}
				}
			}
		}
	}

	return Mensuration;
}

AVTAK_Actor_Mensuration* UVTAK_COTComponent_DrawMensuration::GetMensuration() const
{
	return Mensuration;
}