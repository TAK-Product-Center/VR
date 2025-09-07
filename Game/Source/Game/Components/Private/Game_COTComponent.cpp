// Required Includes
#include "Game_COTComponent.h"
#include "Game.h"

// Engine Includes
#include "Engine/World.h"
#include "HAL/FileManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

// VH Plugin Includes
#include "VH_COTEvent.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_DataPackage.h"
#include "VH_FileIOStatics.h"
#include "Developer_Statics.h"
#include "Interface_Developer_Manipulation.h"

// Game Includes
#include "Game_COTManager.h"
#include "Game_EntityDB.h"
#include "Game_PlayerController.h"
#include "Game_Statics.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_COTComponent::UGame_COTComponent()
{
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_COTComponent::BroadcastCOT()
{
	TSet<FString> attachmentsToSend = GetAttachmentsToSend();

	if (attachmentsToSend.Num() == 0)
	{
		Super::BroadcastCOT();
	}
	else
	{
		PopulateCOT();

		FString zipFilePath = GetAttachmentZipForSend(attachmentsToSend);

		UVH_DataPackage* dataPackage = NewObject<UVH_DataPackage>();
		dataPackage->Name = FPaths::GetBaseFilename(zipFilePath);

		dataPackage->Broadcast(zipFilePath);
	}
}

void UGame_COTComponent::SendCOT(const TArray<FName>& contactUIDs)
{
	TSet<FString> attachmentsToSend = GetAttachmentsToSend();

	if (attachmentsToSend.Num() == 0)
	{
		Super::SendCOT(contactUIDs);
	}
	else
	{
		PopulateCOT();

		FString zipFilePath = GetAttachmentZipForSend(attachmentsToSend);

		UVH_DataPackage* dataPackage = NewObject<UVH_DataPackage>();
		dataPackage->Name = FPaths::GetBaseFilename(zipFilePath);

		dataPackage->Send(contactUIDs, zipFilePath);
	}
}

void UGame_COTComponent::ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent)
{
	if (AVH_GlobeReferenceActor* globeReference = GetGlobeReference())
	{
		FVector worldLocation = globeReference->GeodeticToWorldDouble(cotEvent->GetPoint());

		// update location
		GetOwner()->SetActorLocation(worldLocation);

		// If needed, snap this actor to the ground. Normally, paging in an entity would handle this step, but when the entity is already 
		// paged in and a location update comes in, the entity is placed at the wrong altitude. 
		SnapToGround();

		// update rotation
		FRotator worldRotation = globeReference->BearingPitchToWorldRotation(cotEvent->GetAttribute<double>(TEXT("detail\ttrack\tcourse")), cotEvent->GetAttribute<double>(TEXT("detail\ttrack\tslope")));

		GetOwner()->SetActorRotation(worldRotation);

		//UE_LOG(Game, Warning, TEXT("-- setting yaw for %s (%f) to %s"), *cotEvent->UID.ToString(), detail->Course, *GetOwner()->GetActorRotation().ToString());

		if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
		{
			if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
			{
				SpatialiteResults results = entityDB->QueryUID(cotEvent->GetAttribute(TEXT("uid")));
				for (const SpatialiteResult& result : results)
				{
					bool bVisible = UDatabase_Spatialite::GetBool(TEXT("visible"), result);
					
					voManager->SetEntityVisibilityGlobal(result, bVisible);
				}
			}
		}
	}
}

void UGame_COTComponent::PopulateCOT_Virtual()
{
	if (AVH_GlobeReferenceActor* globeReference = GetGlobeReference())
	{
		// update rotation
		FRotator ownerRotation = GetOwner()->GetActorRotation();

		UVH_COTEvent* cotEvent = GetCurrentCOTEvent();

		if (GetOwner()->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()))
		{
			if (!IInterface_Developer_Manipulation::Execute_GetRotationDisabled(GetOwner()))
			{
				cotEvent->SetAttribute<double>(TEXT("detail\ttrack\tcourse"), globeReference->WorldRotationToBearing(ownerRotation));
				cotEvent->SetAttribute<double>(TEXT("detail\ttrack\tslope"), globeReference->WorldRotationToPitch(ownerRotation));
			}
		}
	}
}

void UGame_COTComponent::SnapToGround()
{
	if (FMath::IsNearlyEqual(GetCurrentCOTEvent()->GetAttribute<double>(TEXT("hae")), 9999999.0, 0.001))
	{
		UGame_Statics::SnapToGround(GetOwner());
	}
}

void UGame_COTComponent::CleanupStaleEntity()
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		FString entityUID = GetCurrentCOTEvent()->GetAttribute(TEXT("uid"));
		SpatialiteResults dbEntries = UGame_EntityDB::Get()->QueryUID(entityUID);
		
		entityDB->DeleteResults(dbEntries);
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_COTComponent::RegisterWithDatabase(AGame_VirtualObjective* virtualObjective)
{
	if (!IsValid(virtualObjective))
	{
		virtualObjective = AGame_PlayerController::GetPlayerActiveVO();
	}

	// AddObjectToEntity before InsertOrUpdate so the relevancy check triggered by InsertOrUpdate won't try load the entity
	if (IsValid(virtualObjective))
	{
		virtualObjective->AddObjectToEntity(GetCurrentCOTEvent()->GetAttribute(TEXT("uid")), GetOwner());

		PopulateCOT();

		if (UGame_COTManager* cotManager = Cast<UGame_COTManager>(UVH_COTManager::Get()))
		{
			cotManager->InsertOrUpdate(this);
		}

		virtualObjective->SetScaleFor(GetCurrentCOTEvent()->GetAttribute(TEXT("uid")));
	}
}

AGame_VirtualObjective* UGame_COTComponent::GetVirtualObjective() const
{
	return UGame_VirtualObjectiveManager::GetObjectVO(GetOwner());
}

AVH_GlobeReferenceActor* UGame_COTComponent::GetGlobeReference() const
{
	return UGame_VirtualObjectiveManager::GetObjectGlobeReference(GetOwner());
}

// ---------------------------------
// --- Implementation
// ---------------------------------

TSet<FString> UGame_COTComponent::GetAttachmentsToSend()
{
	TSet<FString> attachmentsToSend;

	UVH_COTEvent* cotEvent = GetCurrentCOTEvent();
	FString entityUID = cotEvent->GetAttribute(TEXT("uid"));

	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		FSpatialiteResults_BP resultsBP = cotManager->GetAttachedFiles(entityUID);
		for (const FSpatialiteResult_BP& resultBP : resultsBP.Results)
		{
			if (UDatabase_Spatialite::GetInteger(TEXT("shouldSend"), resultBP.Result))
			{
				attachmentsToSend.Add(UDatabase_Spatialite::GetString(TEXT("fullPathToFile"), resultBP.Result));
			}
		}
	}

	return attachmentsToSend;
}

FString UGame_COTComponent::GetAttachmentZipForSend(const TSet<FString>& attachmentsToSend)
{
	UVH_COTEvent* cotEvent = GetCurrentCOTEvent();
	FString entityUID = cotEvent->GetAttribute(TEXT("uid"));

	FString zipRootPath = FString::Printf(TEXT("%s/VRTAK/Temp/%s"), *UDeveloper_Statics::GetUserAppDataPath(), *entityUID);
	FString zipFilename = FString::Printf(TEXT("%s.zip"), *entityUID);

	IFileManager& fileManager = IFileManager::Get();
	fileManager.MakeDirectory(*zipRootPath, true);

	TMap<FString, FString> fullPathToNameInZip;

	// .cot for self
	{
		FString filePath = FString::Printf(TEXT("%s/%s.cot"), *zipRootPath, *entityUID);
		FFileHelper::SaveStringToFile(cotEvent->ToXML(), *filePath);

		fullPathToNameInZip.Add(filePath, FString::Printf(TEXT("%s/%s.cot"), *entityUID, *entityUID));
	}

	// attachments
	{
		for (const FString& fullPathToAttachment : attachmentsToSend)
		{
			FString guid = FGuid::NewGuid().ToString();

			fullPathToNameInZip.Add(fullPathToAttachment, FString::Printf(TEXT("%s/%s"), *guid, *FPaths::GetCleanFilename(fullPathToAttachment)));
		}
	}

	// manifest
	{
		FString xml = TEXT("<MissionPackageManifest version=\"2\">");
		xml += TEXT("<Configuration>");
		xml += FString::Printf(TEXT("<Parameter name=\"uid\" value=\"%s\"/>"), *entityUID);
		xml += FString::Printf(TEXT("<Parameter name=\"name\" value=\"%s\"/>"), *cotEvent->GetAttribute(TEXT("callsign")));
		xml += TEXT("<Parameter name=\"onReceiveDelete\" value=\"true\"/>");
		xml += TEXT("<Parameter name=\"onReceiveImport\" value=\"true\"/>");
		xml += FString::Printf(TEXT("<Parameter name=\"callsign\" value=\"%s\"/>"), *cotEvent->GetAttribute(TEXT("callsign")));
		xml += TEXT("</Configuration>");
		xml += TEXT("<Contents>");

		TArray<FString> namesInZip;
		fullPathToNameInZip.GenerateValueArray(namesInZip);

		for (const FString& nameInZip : namesInZip)
		{
			xml += FString::Printf(TEXT("<Content zipEntry=\"%s\" ignore=\"false\">"), *nameInZip);
			xml += FString::Printf(TEXT("<Parameter name=\"uid\" value=\"%s\"/>"), *entityUID);
			xml += TEXT("</Content>");
		}

		xml += TEXT("</Contents>");
		xml += TEXT("</MissionPackageManifest>");

		FString manifestFullPath = zipRootPath / TEXT("manifest.xml");

		FFileHelper::SaveStringToFile(xml, *manifestFullPath);

		fullPathToNameInZip.Add(manifestFullPath, TEXT("MANIFEST/manifest.xml"));
	}

	// create zip file
	FString zipFilePath = FString::Printf(TEXT("%s/%s"), *zipRootPath, *zipFilename);
	UVH_FileIOStatics::ZipFile(zipFilePath, fullPathToNameInZip);

	return zipFilePath;
}