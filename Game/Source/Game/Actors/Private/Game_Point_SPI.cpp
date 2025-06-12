// Required Includes
#include "Game_Point_SPI.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_COTEvent.h"
#include "VH_COTManager.h"
#include "VH_GlobeReferenceActor.h"

// Game Includes
#include "Game_EntityDB.h"
#include "Game_Statics.h"
#include "Game_COTComponent.h"
#include "Game_COTManager.h"
#include "Game_SimpleSegmentedLineActor.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_PlayerController.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Point_SPI::AGame_Point_SPI(const FObjectInitializer& objectInitializer)
	: Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void AGame_Point_SPI::BeginPlay()
{
	Super::BeginPlay();

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{ 
		entityDB->OnInsertOrUpdate.AddDynamic(this, &AGame_Point_SPI::HandleInsertOrUpdate);
		entityDB->OnDelete.AddDynamic(this, &AGame_Point_SPI::HandleDelete);
	}
}

void AGame_Point_SPI::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	DestroyLineActor();

	Super::EndPlay(endPlayReason);
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_Point_SPI::UpdateCOT()
{
	if (UGame_COTManager* cotManager = Cast<UGame_COTManager>(UVH_COTManager::Get()))
	{
		int32 suffix = GetNextSPISuffix();

		UVH_COTEvent* cotEvent = COTComponent->GetCurrentCOTEvent();

		FString entityUID = FString::Printf(TEXT("%s.SPI%d"), *cotManager->GetSelfUID().ToString(), suffix);
		cotEvent->SetAttribute(TEXT("uid"), entityUID); 
		cotEvent->SetAttribute(TEXT("detail\tlink\tuid"), entityUID);

		FString callsign = FString::Printf(TEXT("%s.SPI%d"), *cotManager->GetCallsign(), suffix);
		cotEvent->SetAttribute(TEXT("callsign"), callsign);

		cotEvent->SetAttribute(TEXT("type"), TEXT("b-m-p-s-p-i"));
		cotEvent->SetAttribute(TEXT("how"), TEXT("h-e"));
		cotEvent->SetAttribute(TEXT("detail\tlink\tuid"), cotManager->GetSelfUID().ToString());
		cotEvent->SetAttribute(TEXT("detail\tlink\trelation"), TEXT("p-p"));
		cotEvent->SetAttribute(TEXT("detail\tlink\ttype"), TEXT("a-f-G-U-C-I"));
	
		cotEvent->PopulateTime(FTimespan(0, 0, 15));

		if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
		{
			virtualObjective->AddObjectToEntity(entityUID, this);
		}

		SetIconTexture(SPILocalIcon);

		cotManager->InsertOrUpdate(cotEvent);

		SyncCallsignWidget();
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

int32 AGame_Point_SPI::GetNextSPISuffix() const
{
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();

	UVH_COTManager* cotManager = UVH_COTManager::Get();

	if (entityDB != nullptr && cotManager != nullptr)
	{
		// find personal SPIs
		TMap<int32, FString> suffixToEntityUID;

		FSpatialiteResults_BP resultsBP = entityDB->GetCategoryEntities(TEXT("spi"));
		for (const FSpatialiteResult_BP& resultBP : resultsBP.Results)
		{
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), resultBP.Result);
			if (UVH_COTEvent* cotEvent = cotManager->GetCotEventFromUID(entityUID))
			{
				FString callsign = cotEvent->GetAttribute(TEXT("callsign"));
				if (IsPersonalSPI(cotEvent) && !callsign.IsEmpty())
				{
					suffixToEntityUID.Add(FCString::Atoi(*callsign.Right(1)), entityUID);
				}
			}
		}

		// delete last personal SPI if already at maximum
		if (suffixToEntityUID.Num() >= GetMaxNumberPersonalSPIs())
		{
			for (int32 i = GetMaxNumberPersonalSPIs(); i >= 1; i--)
			{
				if (suffixToEntityUID.Contains(i))
				{
					entityDB->Delete(UVH_COTManager::GetDataLoader_COT_ClassUID(), suffixToEntityUID[i]);

					suffixToEntityUID.Remove(i);

					break;
				}
			}
		}

		// determine new suffix
		for (int32 i = 1; i <= GetMaxNumberPersonalSPIs(); i++)
		{
			if (!suffixToEntityUID.Contains(i))
			{
				return i;
			}
		}
	}

	return -1;
}

bool AGame_Point_SPI::IsPersonalSPI(UVH_COTEvent* cotEvent) const
{
	FString relationUID;
	if (GetRelationUID(cotEvent, relationUID))
	{
		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			FString selfUID = cotManager->GetSelfUID().ToString();

			return selfUID.Equals(relationUID);
		}
	}

	return false;
}

int32 AGame_Point_SPI::GetMaxNumberPersonalSPIs() const
{
	return 3;
}

bool AGame_Point_SPI::GetRelationUID(UVH_COTEvent* cotEvent, FString& relationUID) const
{
	TArray<FXmlNode*> links = cotEvent->GetNodes(TEXT("link"));
	if (links.Num() > 0)
	{
		relationUID = links[0]->GetAttribute(TEXT("uid"));

		return true;
	}

	return false;
}

void AGame_Point_SPI::SpawnLine()
{
	if (IsValid(LineActor))
	{
		DestroyLineActor();
	}

	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	LineActor = GetWorld()->SpawnActor<AGame_SimpleSegmentedLineActor>(LineActorClass, GetActorTransform(), spawnParams);
	LineActor->SetColor(FColor::White);

	if (AGame_VirtualObjective* virtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(this))
	{
		FString entityUID = COTComponent->GetCurrentCOTEvent()->GetAttribute(TEXT("uid"));

		virtualObjective->AddObjectToEntity(entityUID, LineActor);
	}

	UpdateLinePoints();
}

void AGame_Point_SPI::UpdateLinePoints()
{
	if (IsValid(LineActor))
	{
		if (AVH_GlobeReferenceActor* globeReference = UGame_VirtualObjectiveManager::GetObjectGlobeReference(this))
		{
			if (UGame_COTManager* cotManager = Cast<UGame_COTManager>(UVH_COTManager::Get()))
			{	 
				LineActor->ClearLinePoints();

				UVH_COTEvent* cotEvent = COTComponent->GetCurrentCOTEvent();

				// add self
				FGeodeticCoord3D selfCoordinate = cotEvent->GetPoint();
				LineActor->AddLocationAndGeoLocation(globeReference->GeodeticToWorldDouble(selfCoordinate), selfCoordinate);

				// add creator
				FString relationUID;
				if (GetRelationUID(cotEvent, relationUID))
				{
					if (UVH_COTEvent* creatorCOTEvent = cotManager->GetCotEventFromUID(relationUID))
					{
						FGeodeticCoord3D creatorCoordinate = creatorCOTEvent->GetPoint();
						LineActor->AddLocationAndGeoLocation(globeReference->GeodeticToWorldDouble(creatorCoordinate), creatorCoordinate);
					}
				}
			}
		}
	}
}

void AGame_Point_SPI::DestroyLineActor()
{
	if (IsValid(LineActor))
	{
		if (AGame_VirtualObjective* virtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(this))
		{
			FString entityUID = COTComponent->GetCurrentCOTEvent()->GetAttribute(TEXT("uid"));

			virtualObjective->RemoveObjectFromEntity(entityUID, LineActor);
		}

		LineActor->Destroy();
		LineActor = nullptr;
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_Point_SPI::HandleReceivedCOTUpdate(UVH_COTEvent* cotEvent)
{
	Super::HandleReceivedCOTUpdate(cotEvent);

	bPersonalSPI = IsPersonalSPI(COTComponent->GetCurrentCOTEvent());
	
	SetIconTexture(bPersonalSPI ? SPILocalIcon : SPIIcon);

	if (!bPersonalSPI)
	{
		SpawnLine();
	}
}

void AGame_Point_SPI::HandleInsertOrUpdate(const FSpatialiteResults_BP& results)
{
	if (!bPersonalSPI)
	{
		for (const FSpatialiteResult_BP& resultBP : results.Results)
		{
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), resultBP.Result);
			
			FString relationUID;
			if (GetRelationUID(COTComponent->GetCurrentCOTEvent(), relationUID))
			{
				if (entityUID.Equals(relationUID))
				{
					UpdateLinePoints();
				}
			}
		}
	}
}

void AGame_Point_SPI::HandleDelete(const FSpatialiteResults_BP& results)
{
	if (!bPersonalSPI)
	{
		for (const FSpatialiteResult_BP& resultBP : results.Results)
		{
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), resultBP.Result);

			FString relationUID;
			if (GetRelationUID(COTComponent->GetCurrentCOTEvent(), relationUID))
			{
				if (entityUID.Equals(relationUID))
				{
					DestroyLineActor();
				}
			}
		}
	}
}