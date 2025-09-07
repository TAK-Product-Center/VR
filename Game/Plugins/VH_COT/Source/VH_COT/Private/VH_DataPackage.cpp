// Required Includes
#include "VH_DataPackage.h"
#include "VH_COT.h"

// Engine Includes
#include "Misc/Guid.h"
#include "XmlFile.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Serialization/JsonReader.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"

// VH Plugin Includes
#include "VH_FileIOStatics.h"
#include "Database_Spatialite.h"
#include "Developer_Statics.h"

// Module Includes
#include "VH_COTManager.h"
#include "VH_COTConnectionInfo.h"
#include "VH_COTEvent.h"
#include "VH_COTComponent.h"
#include "Interface_COTReceiver.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UVH_DataPackage::UVH_DataPackage()
{

}

// ---------------------------------
// --- API
// ---------------------------------

void UVH_DataPackage::AddUID(const FString& uid)
{
    Super::AddUID(uid);

    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
    {
        FString query = FString::Printf(TEXT("select * from dataPackageContents where fullPathOnDisk = \"%s\" and uid = \"%s\" and type = \"cot\""), *FullPathToZipOnDisk, *uid);

        SpatialiteResults results;
        cotManager->NonSpatialDB->SyncQuery(query, results);

        if (results.Num() == 0)
        {
            query = FString::Printf(TEXT("insert into dataPackageContents values (\"%s\", \"%s\", \"%s\")"), *FullPathToZipOnDisk, *uid, TEXT("cot"));
            cotManager->NonSpatialDB->SyncQuery(query);
        }
    }
}

void UVH_DataPackage::RemoveUID(const FString& uid)
{
	Super::RemoveUID(uid);

	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		FString query = FString::Printf(TEXT("delete from dataPackageContents where fullPathOnDisk = \"%s\" and uid = \"%s\" and type = \"%s\""), *FullPathToZipOnDisk, *uid, TEXT("cot"));
		cotManager->NonSpatialDB->SyncQuery(query);
	}
}

void UVH_DataPackage::AddFile(const FString& fullPathToFile)
{
    Super::AddFile(fullPathToFile);

    FString modifiedPath = fullPathToFile.Replace(TEXT("\\"), TEXT("/"));

    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
    {
        FString query = FString::Printf(TEXT("select * from dataPackageContents where fullPathOnDisk = \"%s\" and uid = \"%s\" and type = \"file\""), *FullPathToZipOnDisk, *fullPathToFile);

        SpatialiteResults results;
        cotManager->NonSpatialDB->SyncQuery(query, results);
        if (results.Num() == 0)
        {
            query = FString::Printf(TEXT("insert into dataPackageContents values (\"%s\", \"%s\", \"%s\")"), *FullPathToZipOnDisk, *modifiedPath, TEXT("file"));
            cotManager->NonSpatialDB->SyncQuery(query);
        }
    }
}

void UVH_DataPackage::RemoveFile(const FString& fullPathToFile)
{
    Super::RemoveFile(fullPathToFile);

    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
    {
        FString query = FString::Printf(TEXT("delete from dataPackageContents where fullPathOnDisk = \"%s\" and uid = \"%s\" and type = \"%s\""), *FullPathToZipOnDisk, *fullPathToFile, TEXT("file"));
        cotManager->NonSpatialDB->SyncQuery(query);
    }
}

void UVH_DataPackage::RemoveContent()
{
    Super::RemoveContent();

    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
    {
        FString query = FString::Printf(TEXT("delete from dataPackageContents where fullPathOnDisk = \"%s\""), *FullPathToZipOnDisk);
        cotManager->NonSpatialDB->SyncQuery(query);
    }
}

void UVH_DataPackage::Load()
{
    if (!bLoaded)
    {
        // create zip file if it doesn't exist
        //		Example: user creates and populates data package but hasn't sent yet (so no zip file generated)
        IFileManager& fileManager = IFileManager::Get();
        if (!fileManager.FileExists(*FullPathToZipOnDisk))
        {
            FullPathToZipOnDisk = CreateZipFile();
        }

        UVH_COTManager::Get()->LoadDataPackageFromDisk(FullPathToZipOnDisk, true);
    }

    FString query = FString::Printf(TEXT("update dataPackages set isLoaded = 1 where fullPathOnDisk = \"%s\""), *FullPathToZipOnDisk);
    UVH_COTManager::Get()->NonSpatialDB->SyncQuery(query);
}

void UVH_DataPackage::SetVisibility(bool bVisibleArg)
{
    if (bVisibleArg != bVisible)
    {
        bVisible = bVisibleArg;

        if (bVisible && !bLoaded)
        {
            Load();
        }

        FString query = FString::Printf(TEXT("update dataPackages set isVisible = %d where fullPathOnDisk = \"%s\""), bVisible ? 1 : 0, *FullPathToZipOnDisk);
        UVH_COTManager::Get()->NonSpatialDB->SyncQuery(query);
    }
}

void UVH_DataPackage::UpdateContents(const FString& fullPathOnDisk)
{
    FString path = TEXT("");
    FString filename = TEXT("");
    FString extension = TEXT("");
    FPaths::Split(fullPathOnDisk, path, filename, extension);

    if (extension.Equals(TEXT("cot"), ESearchCase::IgnoreCase))
    {
        FString fileContents;
        FFileHelper::LoadFileToString(fileContents, *fullPathOnDisk);

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
            AddUID(cotEvent->GetAttribute(TEXT("uid")));
        }
    }
    else
    {
        AddFile(fullPathOnDisk);
    }
}

void UVH_DataPackage::PopulateContentsFromDB(UDatabase_Spatialite* db)
{
    FString query = FString::Printf(TEXT("select * from dataPackageContents where fullPathOnDisk = \"%s\""), *FullPathToZipOnDisk);

    SpatialiteResults results;
    db->SyncQuery(query, results);
    for (const SpatialiteResult& result : results)
    {
        FString uid = UDatabase_Spatialite::GetString(TEXT("uid"), result);

        FString type = UDatabase_Spatialite::GetString(TEXT("type"), result);

        if (type.Equals(TEXT("cot"), ESearchCase::IgnoreCase))
        {
            AddUID(uid);
        }
        else if (type.Equals(TEXT("file"), ESearchCase::IgnoreCase))
        {
            AddFile(uid);
        }
    }
}

void UVH_DataPackage::Broadcast(const FString& fullPathToZip)
{
	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		// send to all contacts
		TMap<FName, UVH_COTEvent*> allContacts = cotManager->GetContacts();

		TArray<FName> contactUIDs;
		allContacts.GenerateKeyArray(contactUIDs);

		Send(contactUIDs, fullPathToZip);
	}
}

void UVH_DataPackage::Send(const TArray<FName>& contactUIDs, const FString& fullPathToZip)
{
    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
    {
        // get contacts and connection infos from cotManager
        TMap<FName, UVH_COTEvent*> allContacts = cotManager->GetContacts();
        TArray<UVH_COTConnectionInfo*> allConnectionInfos = cotManager->GetConnectionInfos();

        // group contacts by connectionInfos and send

        // maps endpoint to connectionInfo
        TMap<FString, UVH_COTConnectionInfo*> connectionInfos;

        for (const FName& contactUID : contactUIDs)
        {
            if (UVH_COTEvent** cotEventPtr = allContacts.Find(contactUID))
            {
                UVH_COTEvent* cotEvent = *cotEventPtr;
				FString endpoint = cotEvent->GetAttribute(TEXT("endpoint"));

				UVH_COTConnectionInfo* copyFrom = nullptr;
				for (UVH_COTConnectionInfo* info : allConnectionInfos)
				{
					// endpoint starts with * means unknown endpoint for this contact, so accept first connected connection
					if (info->bConnected && (info->GetCommoEndpoint().Equals(endpoint) || endpoint.StartsWith(TEXT("*"))))
					{
                        connectionInfos.Add(endpoint, info);
						break;
					}
				}
            }
        }

		if (fullPathToZip.IsEmpty())
		{
			FullPathToZipOnDisk = CreateZipFile();
		}
		else
		{
			FullPathToZipOnDisk = fullPathToZip;
		}

        for (const auto& connectionInfo : connectionInfos)
        {
            FString endpoint = connectionInfo.Key;

            TArray<FName> contactsForConnectionInfo;
            for (const FName& contactUID : contactUIDs)
            {
                if (UVH_COTEvent** cotEventPtr = allContacts.Find(contactUID))
                {
                    UVH_COTEvent* cotEvent = *cotEventPtr;
                    if (cotEvent->GetAttribute(TEXT("endpoint")).Equals(endpoint))
                    {
                        contactsForConnectionInfo.Add(contactUID);
                    }
                }
            }

            FSSendInfo sendInfo;
            sendInfo.ContactUIDs.Append(contactsForConnectionInfo);
            PendingSendInfo.Add(connectionInfo.Value, sendInfo);

            SendToTAKServer(FullPathToZipOnDisk, connectionInfo.Value, false);
        }
    }
}

void UVH_DataPackage::SendToTAKServer(const FString& fullPathToZip, UVH_COTConnectionInfo* connectionInfo, bool bPublic)
{
    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
    {
        FOnFileUploaded uploadedDelegate;
        uploadedDelegate.BindUObject(this, &UVH_DataPackage::HandleFileUploaded);

        FString url = FString::Printf(TEXT("https://%s:8443/Marti/sync/upload?name=%s&creatorUid=%s"), *connectionInfo->Host, *FGenericPlatformHttp::UrlEncode(Name + TEXT(".zip")), *cotManager->UID.ToString());
        if (bPublic)
        {
            url = FString::Printf(TEXT("%s&tool=public&keywords=missionpackage"), *url);
        }
        else
        {
            url = FString::Printf(TEXT("%s&tool=private"), *url);
        }

        cotManager->UploadFileToTAKServer(connectionInfo->GetCommoEndpoint(), url, fullPathToZip, uploadedDelegate);
    }
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UVH_DataPackage::HandleFileUploaded(const FString& responseBody, int32 fileSize, const FString& endpoint)
{
    // create and send COT
    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
    {
        TArray<UVH_COTConnectionInfo*> toRemove;
        for (const TPair<UVH_COTConnectionInfo*, FSSendInfo>& entry : PendingSendInfo)
        {
            if (entry.Key->GetCommoEndpoint().Equals(endpoint))
            {
                TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(*responseBody);

                TSharedPtr<FJsonObject> jsonObject;
                if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
                {
                    FString name = jsonObject->GetStringField(TEXT("Name"));
                    FString hash = jsonObject->GetStringField(TEXT("Hash"));

                    FString path = TEXT("");
                    FString filename = TEXT("");
                    FString extension = TEXT("");
                    FPaths::Split(name, path, filename, extension);

                    UVH_COTEvent* cotEvent = NewObject<UVH_COTEvent>();
                    cotEvent->SetAttribute(TEXT("uid"), *FGuid::NewGuid().ToString());
                    cotEvent->SetAttribute(TEXT("type"), TEXT("b-f-t-r"));
                    cotEvent->PopulateTime(FTimespan(1, 0, 0));

                    cotEvent->SetPoint(FGeodeticCoord3D(0, 0, 0));

					TArray<FXmlAttribute> attributes;
					attributes.Add(FXmlAttribute(TEXT("filename"), filename + TEXT(".") + extension));
					attributes.Add(FXmlAttribute(TEXT("name"), filename));
					attributes.Add(FXmlAttribute(TEXT("senderUrl"), FString::Printf(TEXT("https://%s:8443/Marti/sync/content?hash=%s"), *entry.Key->Host, *hash)));
					attributes.Add(FXmlAttribute(TEXT("sizeInBytes"), FString::Printf(TEXT("%d"), fileSize)));
					attributes.Add(FXmlAttribute(TEXT("sha256"), hash));
					attributes.Add(FXmlAttribute(TEXT("senderUid"), cotManager->GetSelfUID().ToString()));
					attributes.Add(FXmlAttribute(TEXT("senderCallsign"), cotManager->Callsign));

                    cotEvent->AddNode(TEXT("detail\tfileshare"), attributes);
					
                    cotManager->SendCOT(entry.Value.ContactUIDs, cotEvent->ToXML());
                }

                toRemove.Add(entry.Key);
            }
        }

        for (UVH_COTConnectionInfo* remove : toRemove)
        {
            PendingSendInfo.Remove(remove);
        }
    }
}