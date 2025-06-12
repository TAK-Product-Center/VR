// Required Includes
#include "Game_EntityHandler_COT.h"
#include "Game.h"

// Engine Includes
#include "XmlFile.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "VH_COTEvent.h"
#include "VH_GlobeReferenceActor.h"
#include "Interface_COTReceiver.h"

// Game Includes
#include "Game_VirtualObjective.h"
#include "Game_COTComponent.h"
#include "Game_Statics.h"
#include "Game_COTManager.h"
#include "Game_EntityDB.h"
#include "Game_ImportManager.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_EntityHandler_COT::UGame_EntityHandler_COT()
{
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_EntityHandler_COT::UpdateEntity_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);

	FMemoryReader fromBinary = FMemoryReader(blobData);
	fromBinary.Seek(0);

	FString xml;
	fromBinary << xml;

	UVH_COTEvent* cotEvent = NewObject<UVH_COTEvent>();
	cotEvent->PopulateFromXML(xml);

	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

	TSet<AActor*> actors = virtualObjective->GetActorsForEntity(entityUID);

	if (actors.Num() > 0)
	{
		for (AActor* entityActor : actors)
		{
			if (entityActor->GetClass()->ImplementsInterface(UInterface_COTReceiver::StaticClass()))
			{
				if (UVH_COTComponent* cotComponent = IInterface_COTReceiver::Execute_GetCOTComponent(entityActor))
				{
					cotComponent->ReceiveCOTUpdate(cotEvent);

					cotComponent->SnapToGround();
				}
			}
		}
	}
	else
	{
		PageOutEntity(virtualObjective, result);

		if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
		{
			entityDB->LoadEntity(virtualObjective, entityUID, nullptr, 1);
		}
	}
}

void UGame_EntityHandler_COT::GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues)
{
	Super::GetEntityOverlayInfo_Implementation(result, keyValues);

	TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);
	
    FMemoryReader fromBinary = FMemoryReader(blobData);
    fromBinary.Seek(0);

    FString xml;
    fromBinary << xml;

    UVH_COTEvent* cotEvent = NewObject<UVH_COTEvent>();
    if (cotEvent->PopulateFromXML(xml))
	{
		keyValues.Add(TEXT("displayName"), cotEvent->GetAttribute(TEXT("callsign")).IsEmpty() ? cotEvent->GetAttribute(TEXT("uid")) : cotEvent->GetAttribute(TEXT("callsign")));
		keyValues.Add(TEXT("type"), cotEvent->GetAttribute(TEXT("type")));
		keyValues.Add(TEXT("groupName"), cotEvent->GetAttribute(TEXT("groupName")));
		keyValues.Add(TEXT("groupRole"), cotEvent->GetAttribute(TEXT("groupRole")));
	}
}

void UGame_EntityHandler_COT::PreModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	
	TSet<AActor*> actors = virtualObjective->GetActorsForEntity(entityUID);

	for (AActor* actor : actors)
	{
		if (actor->GetClass()->ImplementsInterface(UInterface_COTReceiver::StaticClass()))
		{
			if (UVH_COTComponent* cotComponent = IInterface_COTReceiver::Execute_GetCOTComponent(actor))
			{
				TArray<FGeodeticCoord3D> coords;
				TArray<FVector> worldLocations = cotComponent->PreModifyVOGlobeReference();
				for (const FVector& worldLocation : worldLocations)
				{
					coords.Add(virtualObjective->GetGlobeReference()->WorldToGeodeticDouble(worldLocation));
				}

				ActorToLocations.Add(actor, coords);
			}
		}
	}
}

void UGame_EntityHandler_COT::PostModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	
	TSet<AActor*> entityActors = virtualObjective->GetActorsForEntity(entityUID);

	for (AActor* actor : entityActors)
	{
		if (TArray<FGeodeticCoord3D>* coordsPtr = ActorToLocations.Find(actor))
		{
			if (actor->GetClass()->ImplementsInterface(UInterface_COTReceiver::StaticClass()))
			{
				if (UVH_COTComponent* cotComponent = IInterface_COTReceiver::Execute_GetCOTComponent(actor))
				{
					TArray<FVector> worldPositions;
					for (const FGeodeticCoord3D& coord : (*coordsPtr))
					{
						worldPositions.Add(virtualObjective->GetGlobeReference()->GeodeticToWorldDouble(coord));
					}

					cotComponent->PostModifyVOGlobeReference(worldPositions);
				}
			}
		}
	}

	ActorToLocation.Empty();
}

void UGame_EntityHandler_COT::SnapEntityToGround_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
		
		TSet<AActor*> entityActors = virtualObjective->GetActorsForEntity(entityUID);

		for (AActor* actor : entityActors)
		{
			if (actor->GetClass()->ImplementsInterface(UInterface_COTReceiver::StaticClass()))
			{
				if (UVH_COTComponent* cotComponent = IInterface_COTReceiver::Execute_GetCOTComponent(actor))
				{
					cotComponent->SnapToGround();
				}
			}
		}
	}
}

void UGame_EntityHandler_COT::GetGoToCoord_Implementation(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate)
{
	TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);
	
	FMemoryReader fromBinary = FMemoryReader(blobData);
	fromBinary.Seek(0);

	FString xml;
	fromBinary << xml;

	UVH_COTEvent* cotEvent = NewObject<UVH_COTEvent>();
	if (cotEvent->PopulateFromXML(xml))
	{
		coordinate = GetGoToCoord(cotEvent);
	}
}

void UGame_EntityHandler_COT::PageInEntity(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);

	if (UGame_COTManager* cotManager = Cast<UGame_COTManager>(UVH_COTManager::Get()))
	{
		if (virtualObjective->IsEntityPagedIn(entityUID))
		{
			return;
		}

		FMemoryReader fromBinary = FMemoryReader(blobData);
		fromBinary.Seek(0);

		FString xml;
		fromBinary << xml;
		
		UVH_COTEvent* cotEvent = NewObject<UVH_COTEvent>();
		if (cotEvent->PopulateFromXML(xml))
		{
			cotManager->PageInEntity(virtualObjective, cotEvent);

			//UE_LOG(Game, Warning, TEXT("-- UGame_EntityHandler_COT::PageInEntity | loading | UID: %s | Type: %s"), *cotEvent->UID.ToString(), *cotEvent->GetAttribute(TEXT("type")));
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_EntityHandler_COT::PageInEntity | invalid xml | %s"), *xml);
		}
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_EntityHandler_COT::PageInEntity | COTManager is nullptr"));
	}
}

bool UGame_EntityHandler_COT::RegisterFileToDatabaseSecondPass_Implementation(const FString& fullPathToFile, TSet<FString>& registeredEntityUIDs)
{
	FString extension = FPaths::GetExtension(fullPathToFile);

	if (extension.Equals(TEXT("cot"), ESearchCase::IgnoreCase))
	{
		if (UGame_COTManager* cotManager = Cast<UGame_COTManager>(UVH_COTManager::Get()))
		{
			FString fileContents = TEXT("");
			if (FFileHelper::LoadFileToString(fileContents, *fullPathToFile))
			{
				fileContents.ReplaceInline(TEXT("<?"), TEXT("\n<?"));
				fileContents.ReplaceInline(TEXT("?>"), TEXT("?>\n"));

				// remove everything in front of "<event"
				int32 index = fileContents.Find(TEXT("<event"));
				if (index != INDEX_NONE)
				{
					fileContents = fileContents.RightChop(index);
				}
				
				UVH_COTEvent* cotEvent = NewObject<UVH_COTEvent>();
				if (cotEvent->PopulateFromXML(fileContents))
				{
					cotManager->InsertOrUpdate(cotEvent);
					
					registeredEntityUIDs.Add(cotEvent->GetAttribute(TEXT("uid")));

					return true;
				}
			}
		}
	}

	if (extension.Equals(TEXT("pref"), ESearchCase::IgnoreCase) || extension.Equals(TEXT("p12"), ESearchCase::IgnoreCase))
	{
		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			IFileManager& fileManager = IFileManager::Get();

			FString path = TEXT("");
			FString filename = TEXT("");
			FPaths::Split(fullPathToFile, path, filename, extension);

			FString connectionsPath = FPaths::Combine(UDeveloper_Statics::GetUserAppDataPath(), TEXT("VRTAK"), TEXT("Connections"));
			fileManager.Copy(*(connectionsPath / filename + TEXT(".") + extension), *fullPathToFile);

			cotManager->LoadConnectionInfos();

			return true;
		}
	}

	return false;
}

TMap<FString, FString> UGame_EntityHandler_COT::GetHashesToSyncForMUC_Implementation(const FSpatialiteResult_BP& result)
{
	TMap<FString, FString> hashes;

	return hashes;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

FGeodeticCoord3D UGame_EntityHandler_COT::GetGoToCoord(UVH_COTEvent* cotEvent) const
{
	FGeodeticCoord3D coordinate = cotEvent->GetPoint();

	FString type = cotEvent->GetAttribute(TEXT("type"));

	TArray<FXmlNode*> links = cotEvent->GetNodes(TEXT("link"));

	if (type.Equals(TEXT("u-d-f-m"), ESearchCase::IgnoreCase))
	{
		if (links.Num() > 0)
		{
			FString lineXML = links[0]->GetAttribute(TEXT("line"));

			UVH_COTEvent* lineCOTEvent = NewObject<UVH_COTEvent>();
			lineCOTEvent->PopulateFromXML(lineXML);

			TArray<FXmlNode*> innerLinks = lineCOTEvent->GetNodes(TEXT("link"));
			if (innerLinks.Num() > 0)
			{
				coordinate = UVH_COTStatics::LinkToCoordinate(innerLinks[0]);
			}
		}
	}
	else if (type.Equals(TEXT("u-d-f"), ESearchCase::IgnoreCase))
	{
		if (links.Num() > 0)
		{
			coordinate = UVH_COTStatics::LinkToCoordinate(links[0]);
		}
	}
	else if (type.StartsWith(TEXT("u-d-m")))
	{
		if (links.Num() > 0)
		{
			coordinate = UVH_COTStatics::LinkToCoordinate(links[0]);
		}
	}
	else if (type.Equals(TEXT("b-m-r"), ESearchCase::IgnoreCase))
	{
		if (links.Num() > 0)
		{
			coordinate = UVH_COTStatics::LinkToCoordinate(links[0]);
		}
	}

	return coordinate;
}