// Required Includes
#include "VH_DataSync.h"
#include "VH_COT.h"

// Engine Includes
#include "Misc/Paths.h"
#include "HAL/FileManager.h"
#include "Misc/FileHelper.h"
#include "Async/TaskGraphInterfaces.h"
#include "Serialization/JsonReader.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "Async/Async.h"

//  VH Plugin Includes
#include "Database_Spatialite.h"
#include "Developer_Statics.h"

// Module Includes
#include "VH_COTManager.h"
#include "VH_COTConnectionInfo.h"
#include "Interface_COTReceiver.h"
#include "VH_COTComponent.h"
#include "VH_COTEvent.h"

#include "commo.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UVH_DataSync::UVH_DataSync()
{

}

// ---------------------------------
// --- API
// ---------------------------------

void UVH_DataSync::Unload()
{

}

void UVH_DataSync::SetSubscribed(bool bSubscribe)
{
    if (bSubscribe != bSubscribed)
    {
        if (UVH_COTManager* cotManager = UVH_COTManager::Get())
        {
            FString url = FString::Printf(TEXT("https://%s:8443/Marti/api/missions/%s/subscription?uid=%s"), *ConnectionInfo->Host, *FGenericPlatformHttp::UrlEncode(Name), *FGenericPlatformHttp::UrlEncode(cotManager->UID.ToString()));
            FString verb = bSubscribe ? TEXT("PUT") : TEXT("DELETE");

            TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = cotManager->CreateRESTRequest(ConnectionInfo->GetCommoEndpoint(), url, verb);
            request->ProcessRequest();

            if (bSubscribe)
            {
                // add datasync to database
                FString query = FString::Printf(TEXT("replace into dataSyncs values (\"%s\", \"%s\", \"%d\", \"%s\")"), *Name, *ConnectionInfo->Host, ConnectionInfo->Port, *ConnectionInfo->ClientCertificateName);
                cotManager->NonSpatialDB->SyncQuery(query);
            }
            else
            {
                // remove datasync from database
                FString query = FString::Printf(TEXT("delete from dataSyncs where name = \"%s\""), *Name);
                cotManager->NonSpatialDB->SyncQuery(query);
            }
        }

        bSubscribed = bSubscribe;
    }
}

bool UVH_DataSync::IsSubscribed() const
{
     return bSubscribed; 
}

// pulls down cots and files for datasync, adds them to Cache, and registers them with database
// populates UIDs and Files
void UVH_DataSync::Sync()
{
    UVH_COTManager* cotManager = UVH_COTManager::Get();

    if (cotManager != nullptr && ConnectionInfo != nullptr)
    {
        // remove old files and uids
        RemoveContent();

        // download cots from data sync
        {
            FString url = FString::Printf(TEXT("https://%s:8443/Marti/api/missions/%s/cot"), *ConnectionInfo->Host, *FGenericPlatformHttp::UrlEncode(Name));
            TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = cotManager->CreateRESTRequest(ConnectionInfo->GetCommoEndpoint(), url);

            request->OnProcessRequestComplete().BindLambda([dataSyncName = Name](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded) 
			{
                if (bSucceeded)
                {
                    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
                    {
						if (UVH_DataSync* dataSync = cotManager->GetDataSync(dataSyncName))
						{
                            dataSync->Sync_COTRequestCompleted(response->GetContent());
                        }
                    }
                }
            });

            request->ProcessRequest();
        }

        // download non-cot metadata
        {
            FString url = FString::Printf(TEXT("https://%s:8443/Marti/api/missions/%s"), *ConnectionInfo->Host, *FGenericPlatformHttp::UrlEncode(Name));
            TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = cotManager->CreateRESTRequest(ConnectionInfo->GetCommoEndpoint(), url);

            request->OnProcessRequestComplete().BindLambda([dataSyncName = Name](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded) 
			{
                if (bSucceeded)
                {
                    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
                    {
						if (UVH_DataSync* dataSync = cotManager->GetDataSync(dataSyncName))
						{
                            dataSync->Sync_DataRequestCompleted(response->GetContent());
                        }
                    }
                }
            });

            request->ProcessRequest();
        }

		// download mission changes
		RequestChanges();
    }
}

void UVH_DataSync::SendToTAKServer()
{
    UVH_COTManager* cotManager = UVH_COTManager::Get();

    if (cotManager != nullptr && ConnectionInfo != nullptr)
    {
        FString url = FString::Printf(TEXT("https://%s:8443/Marti/api/missions/%s?creatorUid=%s"), *ConnectionInfo->Host, *FGenericPlatformHttp::UrlEncode(Name), *FGenericPlatformHttp::UrlEncode(cotManager->UID.ToString()));

        TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = cotManager->CreateRESTRequest(ConnectionInfo->GetCommoEndpoint(), url, TEXT("PUT"));
        request->ProcessRequest();
    }
}

void UVH_DataSync::RemoveFromTAKServer()
{
    UVH_COTManager* cotManager = UVH_COTManager::Get();

    if (cotManager != nullptr && ConnectionInfo != nullptr)
    {
        FString url = FString::Printf(TEXT("https://%s:8443/Marti/api/missions/%s?creatorUid=%s"), *ConnectionInfo->Host, *FGenericPlatformHttp::UrlEncode(Name), *FGenericPlatformHttp::UrlEncode(cotManager->UID.ToString()));

        TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = cotManager->CreateRESTRequest(ConnectionInfo->GetCommoEndpoint(), url, TEXT("DELETE"));
        request->ProcessRequest();
    }
}

void UVH_DataSync::AddFileToTAKServer(const FString& fullPathToFile)
{
    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
    {
        // copy to VTAK/Cache to preserve for subsequent loads
        IFileManager& fileManager = IFileManager::Get();

        FString outPath = TEXT("");
        FString path = TEXT("");
        FString filename = TEXT("");
        FString extension = TEXT("");
        FPaths::Split(fullPathToFile, path, filename, extension);
        if (!path.EndsWith(TEXT("VTAK/Cache"), ESearchCase::IgnoreCase))
        {
            outPath = UDeveloper_Statics::GetUserAppDataPath() / TEXT("VRTAK") / TEXT("Cache") / filename + TEXT(".") + extension;
            fileManager.Copy(*outPath, *fullPathToFile);
        }
        else
        {
            outPath = fullPathToFile;
        }

        AddFile(outPath);

        FOnFileUploaded uploadedDelegate;
        uploadedDelegate.BindUObject(this, &UVH_DataSync::HandleAddedFileUploaded);

		FString encodedFilename = FGenericPlatformHttp::UrlEncode(filename + TEXT(".") + extension);
        FString url = FString::Printf(TEXT("https://%s:8443/Marti/sync/upload?name=%s&creatorUid=%s"), *ConnectionInfo->Host, *encodedFilename, *cotManager->UID.ToString());

        cotManager->UploadFileToTAKServer(ConnectionInfo->GetCommoEndpoint(), url, outPath, uploadedDelegate);
    }
}

void UVH_DataSync::AddCOTToTAKServer(const FString& uid)
{
    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
    {
        // send cot to tak server
        if (UVH_COTEvent* cotEvent = cotManager->GetCotEventFromUID(uid))
        {
			FString name = Name.ToLower();

			TArray<FXmlAttribute> attributes;
			attributes.Add(FXmlAttribute(TEXT("mission"), name));
			
			cotEvent->AddNode(TEXT("\tdetail\tmarti\tdest"), attributes, true);

            cotManager->Commo->sendCoTToServerMissionDest(TCHAR_TO_ANSI(*ConnectionInfo->GetCommoEndpoint()), TCHAR_TO_ANSI(*name), TCHAR_TO_ANSI(*cotEvent->ToXML()));

            AddUID(uid);
          
            OnAddCOTToTAKServer.Broadcast(this, uid);
        }
    }
}

void UVH_DataSync::RemoveContentFromTAKServer(const FString& uid)
{
    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
    {
        FString path = TEXT("");
        FString filename = TEXT("");
        FString extension = TEXT("");
        FPaths::Split(uid, path, filename, extension);

        FString urlIdentifier = TEXT("");
        if (FString* hashPtr = FileToHash.Find(filename + TEXT(".") + extension))
        {
            // check just filename
            urlIdentifier = TEXT("hash=") + FGenericPlatformHttp::UrlEncode(*(*hashPtr));
        }
        else if (FString* hashPtr2 = FileToHash.Find(uid))
        {
            // check full path
            urlIdentifier = TEXT("hash=") + FGenericPlatformHttp::UrlEncode(*(*hashPtr2));
        }
        else if (UIDs.Find(uid) != INDEX_NONE)
        {
            urlIdentifier = TEXT("uid=") + FGenericPlatformHttp::UrlEncode(*uid);
        }

        if (!urlIdentifier.IsEmpty())
        {
			FString selfUID = cotManager->GetSelfUID().ToString();
            FString url = FString::Printf(TEXT("https://%s:8443/Marti/api/missions/%s/contents?%s&creatorUid=%s"), *ConnectionInfo->Host, *FGenericPlatformHttp::UrlEncode(Name), *urlIdentifier, *selfUID);
            FString verb = TEXT("DELETE");

            TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = cotManager->CreateRESTRequest(ConnectionInfo->GetCommoEndpoint(), url, verb);
            request->ProcessRequest();
        }

        RemoveFile(uid);
        RemoveUID(uid);
    }
}

TArray<FString> UVH_DataSync::GetKeywords() const
{
    return Keywords;
}

void UVH_DataSync::SetKeywords(const TArray<FString>& keywords)
{
    Keywords.Empty();

    Keywords.Append(keywords);

    SendKeywordsToTAKServer();
}

void UVH_DataSync::SetKeywordsFromTAKServer(const TArray<FString>& keywords)
{
	Keywords.Empty();

	Keywords.Append(keywords);
}

TArray<FString> UVH_DataSync::GetEntityKeywords(const FString& entityUID) const
{
	if (const TArray<FString>* keywordsPtr = EntityKeywords.Find(entityUID))
	{
		return *keywordsPtr;
	}

	return TArray<FString>();
}

void UVH_DataSync::SetEntityKeywords(const FString& entityUID, const TArray<FString>& keywords)
{
	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		// set locally
        {
            FScopeLock scopeLock(&EntityKeywordsCritSection);
		  
            EntityKeywords[entityUID] = keywords;
        }

		// send to TAK server
		FString url = FString::Printf(TEXT("https://%s:8443/Marti/api/missions/%s/uid/%s/keywords?creatorUID=%s"), *ConnectionInfo->Host, *FGenericPlatformHttp::UrlEncode(Name), *entityUID, *cotManager->UID.ToString());
		
		FString verb = TEXT("PUT");

		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = cotManager->CreateRESTRequest(ConnectionInfo->GetCommoEndpoint(), url, verb, TEXT("application/json"));

		FString content = TEXT("[");
		for (int32 i = 0; i < keywords.Num(); i++)
		{
			content += FString::Printf(TEXT("\"%s\""), *keywords[i]);

			if (i + 1 < keywords.Num())
			{
				content += TEXT(",");
			}
		}
		content += TEXT("]");

		request->SetContentAsString(content);

		request->ProcessRequest();

        OnEntityKeywordsUpdated.Broadcast(entityUID, keywords);
	}
}

void UVH_DataSync::SendKeywordsToTAKServer()
{
    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
    {
        FString url = FString::Printf(TEXT("https://%s:8443/Marti/api/missions/%s/keywords?creatorUID=%s"), *ConnectionInfo->Host, *FGenericPlatformHttp::UrlEncode(Name), *cotManager->UID.ToString());
        FString verb = TEXT("PUT");

        TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = cotManager->CreateRESTRequest(ConnectionInfo->GetCommoEndpoint(), url, verb, TEXT("application/json"));

        FString content = TEXT("[");
        for (int32 i = 0; i < Keywords.Num(); i++)
        {
            content += FString::Printf(TEXT("\"%s\""), *Keywords[i]);
        
            if (i + 1 < Keywords.Num())
            {
                content += TEXT(",");
            }
        }
        content += TEXT("]");

        request->SetContentAsString(content);
   
        request->ProcessRequest();
    }
}

void UVH_DataSync::RequestChanges()
{
    UVH_COTManager* cotManager = UVH_COTManager::Get();

	if (cotManager == nullptr || ConnectionInfo == nullptr)
	{
		UE_LOG(VH_COT, Error, TEXT("Failed to get COT Manager or connection info.  Change-list request aborted."));
		return;
	}

	FString url = FString::Printf(TEXT("https://%s:8443/Marti/api/missions/%s/changes"), *ConnectionInfo->Host, *FGenericPlatformHttp::UrlEncode(Name));
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = cotManager->CreateRESTRequest(ConnectionInfo->GetCommoEndpoint(), url);

	FString dataSyncName = Name;
	request->OnProcessRequestComplete().BindLambda([dataSyncName](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded) 
    {
		if (bSucceeded)
		{
			if (UVH_COTManager* cotManager = UVH_COTManager::Get())
			{
				UVH_DataSync* dataSync = cotManager->GetDataSync(dataSyncName);
				if (dataSync)
				{
					dataSync->Sync_GetChangesRequestCompleted(response->GetContent());
				}
			}
		}
	});

	request->ProcessRequest();
	
	cotManager->OnUpdateContacts.AddUniqueDynamic(this, &UVH_DataSync::HandleContactsUpdated);
}

void UVH_DataSync::RequestEntityKeywords()
{
    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
    {
        FString url = FString::Printf(TEXT("https://%s:8443/Marti/api/missions/%s"), *ConnectionInfo->Host, *FGenericPlatformHttp::UrlEncode(Name));
        TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = cotManager->CreateRESTRequest(ConnectionInfo->GetCommoEndpoint(), url);

        request->OnProcessRequestComplete().BindLambda([this, dataSyncName = Name](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded) 
	    {
            if (bSucceeded)
            {
                TArray<uint8> data = response->GetContent();

                std::string jsonString(reinterpret_cast<const char*>(data.GetData()), data.Num());

                FString jsonFString(jsonString.c_str());

                if (UVH_COTManager* cotManager = UVH_COTManager::Get())
                {
				    if (UVH_DataSync* dataSync = cotManager->GetDataSync(dataSyncName))
				    {
                        TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(*jsonFString);

                        TSharedPtr<FJsonObject> jsonObject;
                        if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
                        {
                            const TArray<TSharedPtr<FJsonValue>>* dataArray;
                            if (jsonObject->TryGetArrayField(TEXT("data"), dataArray))
                            {
                                if (TSharedPtr<FJsonObject> dataObj = (*dataArray)[0]->AsObject())
                                {
				                    TArray<TSharedPtr<FJsonValue>> uidsArray = dataObj->GetArrayField(TEXT("uids"));
				                    for (int32 i = 0; i < uidsArray.Num(); i++)
				                    {
					                    TSharedPtr<FJsonObject> uidsObj = uidsArray[i]->AsObject();

					                    FString entityUID = uidsObj->GetStringField(TEXT("data"));

					                    TArray<FString> keywords;
					                    const TArray<TSharedPtr<FJsonValue>>* keywordsArrayPtr;
                                        if (uidsObj->TryGetArrayField(TEXT("keywords"), keywordsArrayPtr))
                                        {
                                            TArray<TSharedPtr<FJsonValue>> keywordsArray = *keywordsArrayPtr;

					                        for (int32 j = 0; j < keywordsArray.Num(); j++)
					                        {
						                        keywords.Add(keywordsArray[j]->AsString());
					                        }

                                            {
                                                FScopeLock scopeLock(&EntityKeywordsCritSection);
					                    
                                                dataSync->EntityKeywords.Add(entityUID, keywords);
                                            }

                                            AsyncTask(ENamedThreads::GameThread, [this, dataSync, entityUID, keywords]()
                                            {
                                                dataSync->OnEntityKeywordsUpdated.Broadcast(entityUID, keywords);
                                            });
                                        }
				                    }
                                }
                            }
                        }
                    }
                }
            }
        });

        request->ProcessRequest();
    }
}

void UVH_DataSync::ChangesReceived()
{

}

void UVH_DataSync::RemoveFile(const FString& fullPathToFile)
{
    Super::RemoveFile(fullPathToFile);

    FileToHash.Remove(fullPathToFile);
}

void UVH_DataSync::RemoveContent()
{
    Super::RemoveContent();

    FileToHash.Empty();
}

void UVH_DataSync::HandleUpdate(UVH_COTEvent* cotEvent)
{
    UVH_COTManager* cotManager = UVH_COTManager::Get();

    if (cotManager != nullptr && ConnectionInfo != nullptr)
    {
        TArray<FXmlNode*> missionChanges = cotEvent->GetNodes(TEXT("detail\tmission\tmissionChanges\tmissionChange"));
        for (FXmlNode* missionChange : missionChanges)
        {
            FString missionChangeType = UVH_COTStatics::GetNodeContent(missionChange, TEXT("type"));

            if (missionChangeType.Equals(TEXT("remove_content"), ESearchCase::IgnoreCase))
            {
                FString fileName = UVH_COTStatics::GetNodeContent(missionChange, TEXT("contentResource\tfilename"));

                // make sure the filename gets filled out correctly
                if (fileName.IsEmpty())
                {
                    // it's not a file, unregister uid from database
                    FString contentUID = UVH_COTStatics::GetNodeContent(missionChange, TEXT("contentUID"));
                    
                    DeleteFromDatabase(contentUID, cotManager->GetDataLoader_COT_ClassUID());

                    RemoveUID(contentUID);
                }
                else
                {
                    // it's a file, unregister from database

                    // find file in Files that ends with fileName, unregister that uid from database
                    for (int32 i = 0; i < Files.Num(); i++)
                    {
                        if (Files[i].EndsWith(fileName))
                        {
							DeleteFromDatabase(Files[i], cotManager->GetDataLoader_File_ClassUID());

                            RemoveFile(Files[i]);

                            break;
                        }
                    }
                }
            }
            else if (missionChangeType.Equals(TEXT("add_content"), ESearchCase::IgnoreCase))
            {
                FString fileName = UVH_COTStatics::GetNodeContent(missionChange, TEXT("contentResource\tfilename"));
                
                FString contentUID = UVH_COTStatics::GetNodeContent(missionChange, TEXT("contentUID"));

				// Added check for empty content uid to prevent empty items from being added to the map
                if (fileName.IsEmpty() && !contentUID.IsEmpty())
                {
                    // cot entity; add uid to UIDs
                    //		don't register with database here, cot for this uid comes at a different time
                    AddUID(contentUID);
                }
                else
                {
                    // file
                    FString hash = UVH_COTStatics::GetNodeContent(missionChange, TEXT("contentResource\thash"));
                    FString contentName = UVH_COTStatics::GetNodeContent(missionChange, TEXT("contentResource\tname"));
                    
                    // download file, register it with database, then add uid to datasync
                    FString url = FString::Printf(TEXT("https://%s:8443/Marti/sync/content?hash=%s"), *ConnectionInfo->Host, *hash);
                    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = cotManager->CreateRESTRequest(ConnectionInfo->GetCommoEndpoint(), url);

					// Currently filenames may not be included in the json response, so I relying on Name to contain the filename
                    FString filename = fileName.IsEmpty() ? contentName : fileName;

                    FString dataSyncName = Name;

                    request->OnProcessRequestComplete().BindLambda([filename, dataSyncName](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded) 
                    {
                        if (bSucceeded)
                        {
                            FString filePath = UDeveloper_Statics::GetUserAppDataPath() / TEXT("VRTAK") / TEXT("Cache") / filename;
                            FFileHelper::SaveArrayToFile(response->GetContent(), *filePath);

                            AsyncTask(ENamedThreads::GameThread, [filePath, dataSyncName]()
							{
                                if (UVH_COTManager* cotManager = UVH_COTManager::Get())
                                {
									UVH_DataSync* dataSync = cotManager->GetDataSync(dataSyncName);
									if (dataSync)
                                    {
										dataSync->RegisterFile(filePath);

                                        dataSync->AddFile(filePath);
                                    }
                                }
                            });
                        }
                    });

                    request->ProcessRequest();
                }
            }
        }

		// Send off to server for changes to update the log
		if (missionChanges.Num() > 0)
		{
			RequestChanges();
		}

        // update keywords
        FString url = FString::Printf(TEXT("https://%s:8443/Marti/api/missions/%s"), *ConnectionInfo->Host, *FGenericPlatformHttp::UrlEncode(Name));
        
        TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = cotManager->CreateRESTRequest(ConnectionInfo->GetCommoEndpoint(), url);

        request->OnProcessRequestComplete().BindLambda([dataSyncName = Name](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded) 
		{
            if (bSucceeded)
            {
                if (UVH_COTManager* cotManager = UVH_COTManager::Get())
                {
                    if (UVH_DataSync* dataSync = cotManager->GetDataSync(dataSyncName))
				    {
                        dataSync->Sync_GetKeywords(response->GetContent());
                    }
                }
            }
        });

        request->ProcessRequest();
    }
}

void UVH_DataSync::AddUpdateHistory(const FString& contactUID, const FDateTime& timestamp)
{
	UpdateHistory.Add(TPair<FString, FDateTime>(contactUID, timestamp));
}

FDateTime UVH_DataSync::GetLastUpdate() const
{
	FDateTime lastUpdate = CreateTime;

	for (const TPair<FString, FDateTime>& entry : UpdateHistory)
	{
		if (entry.Value > lastUpdate)
		{
			lastUpdate = entry.Value;
		}
	}

	return lastUpdate;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UVH_DataSync::RegisterFile(const FString& fullPathToFile)
{

}

void UVH_DataSync::Notify(const FString& message, float duration) const
{

}

bool UVH_DataSync::IsFileRegistered(const FString& fullPathToFile) const
{
    return false;
}

void UVH_DataSync::DeleteFromDatabase(const FString& entityUID, const FString& classUID)
{

}

void UVH_DataSync::Sync_COTRequestCompleted(const TArray<uint8>& data)
{
    std::string xmlString(reinterpret_cast<const char*>(data.GetData()), data.Num());

    FString xmlFString(xmlString.c_str());

    // remove <?...?>
    TArray<FString> xmlArray;
    xmlFString.ParseIntoArray(xmlArray, TEXT("?>"));

    if (xmlArray.Num() == 2)
    {
        xmlFString = xmlArray[1];
    }

    FXmlFile xmlFile(xmlFString, EConstructMethod::ConstructFromBuffer);
    if (xmlFile.IsValid())
    {
        FXmlNode* root = xmlFile.GetRootNode();
        TArray<FXmlNode*> eventNodes = root->GetChildrenNodes();

        FString cachePath = UDeveloper_Statics::GetUserAppDataPath() / TEXT("VRTAK") / TEXT("Cache");
        for (FXmlNode* eventNode : eventNodes)
        {
            UVH_COTEvent* cotEvent = NewObject<UVH_COTEvent>();
            cotEvent->PopulateFromXML(eventNode);

            FString uid = cotEvent->GetAttribute(TEXT("uid"));

            FString xml = cotEvent->ToXML();
            FFileHelper::SaveStringToFile(xml, *(cachePath / uid + TEXT(".cot")));

            UVH_COTManager::Get()->AddReceivedCOT(cotEvent);

            FString dataSyncName = Name;
            AsyncTask(ENamedThreads::GameThread, [uid, dataSyncName]()
			{
                if (UVH_COTManager* cotManager = UVH_COTManager::Get())
                {
					UVH_DataSync* dataSync = cotManager->GetDataSync(dataSyncName);
					if (dataSync)
					{
                        dataSync->AddUID(uid);
                    }
                }
            });
        }
    }
}

void UVH_DataSync::Sync_FileRequestCompleted(const TArray<uint8>& data, const FString& filename)
{
    FString filePath = UDeveloper_Statics::GetUserAppDataPath() / TEXT("VRTAK") / TEXT("Cache") / filename;

    IFileManager& fileManager = IFileManager::Get();
    if (fileManager.FileExists(*filePath))
    {
        // file already downloaded by another thread, abort
        return;
    }

    FFileHelper::SaveArrayToFile(data, *filePath);

    FString dataSyncName = Name;
    AsyncTask(ENamedThreads::GameThread, [filePath, dataSyncName]()
	{
        if (UVH_COTManager* cotManager = UVH_COTManager::Get())
        {
			UVH_DataSync* dataSync = cotManager->GetDataSync(dataSyncName);
			if (dataSync)
			{
                dataSync->Notify(FString::Printf(TEXT("File \"%s\" received"), *FPaths::GetCleanFilename(filePath)), 5.f);

				dataSync->RegisterFile(filePath);

                dataSync->AddFile(filePath);
            }
        }
    });
}

void UVH_DataSync::Sync_DataRequestCompleted(const TArray<uint8>& data)
{
    Sync_GetKeywords(data);

    IFileManager& fileManager = IFileManager::Get();

    std::string jsonString(reinterpret_cast<const char*>(data.GetData()), data.Num());

    FString jsonFString(jsonString.c_str());

    TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(*jsonFString);

    TSharedPtr<FJsonObject> jsonObject;
    if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
    {
        const TArray<TSharedPtr<FJsonValue>>* dataArray;
        if (jsonObject->TryGetArrayField(TEXT("data"), dataArray))
        {
            if (TSharedPtr<FJsonObject> dataObj = (*dataArray)[0]->AsObject())
            {
                TArray<TSharedPtr<FJsonValue>> contentsArray = dataObj->GetArrayField(TEXT("contents"));
                for (int32 i = 0; i < contentsArray.Num(); i++)
                {
                    TSharedPtr<FJsonObject> contentsObj = contentsArray[i]->AsObject();

                    TSharedPtr<FJsonObject> contentsDataObj = contentsObj->GetObjectField(TEXT("data"));
                    FString filename = TEXT("");
                    if (!contentsDataObj->TryGetStringField(TEXT("filename"), filename))
                    {
                        contentsDataObj->TryGetStringField(TEXT("name"), filename);
                    }

                    FString hash = contentsDataObj->GetStringField(TEXT("hash"));

                    int32 size = contentsDataObj->GetIntegerField(TEXT("size"));

					FString dataSyncName = Name;

                    // check filename and size
                    FString filePath = UDeveloper_Statics::GetUserAppDataPath() / TEXT("VRTAK") / TEXT("Cache") / filename;
                    if (fileManager.FileExists(*filePath) && fileManager.FileSize(*filePath) == size)
                    {
                        // file with same name and size already exists, add to datasync and database
                        AsyncTask(ENamedThreads::GameThread, [filePath, dataSyncName, hash, filename]()
						{
                            if (UVH_COTManager* cotManager = UVH_COTManager::Get())
                            {
								UVH_DataSync* dataSync = cotManager->GetDataSync(dataSyncName);
								if (dataSync)
								{
                                    dataSync->AddFile(filePath);

									// Make sure to add hashes to the map so future deletes can be successful
									if (dataSync->FileToHash.Contains(filename) == false)
									{
										dataSync->FileToHash.Add(filename, hash);
									}

                                    // add to database if it's not already in
                                    if (!dataSync->IsFileRegistered(filePath))
                                    {
										dataSync->RegisterFile(filePath);
                                    }
                                }
                            }
                        });
                    }
                    else
                    {
                        // file does not exist, download it
                        FString url = FString::Printf(TEXT("https://%s:8443/Marti/sync/content?hash=%s"), *ConnectionInfo->Host, *hash);

                        TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = UVH_COTManager::Get()->CreateRESTRequest(ConnectionInfo->GetCommoEndpoint(), url);

                        request->OnProcessRequestComplete().BindLambda([filename, hash, dataSyncName](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded) {
                            if (bSucceeded)
                            {
                                AsyncTask(ENamedThreads::GameThread, [filename, hash, dataSyncName, response]()
								{
                                    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
                                    {
										UVH_DataSync* dataSync = cotManager->GetDataSync(dataSyncName);
										if (dataSync)
										{
                                            dataSync->FileToHash.Add(filename, hash);
                                            dataSync->Sync_FileRequestCompleted(response->GetContent(), filename);
                                        }
                                    }
                                });
                            }
                        });

                        request->ProcessRequest();
                    }
                }

				TArray<TSharedPtr<FJsonValue>> uidsArray = dataObj->GetArrayField(TEXT("uids"));
				for (int32 i = 0; i < uidsArray.Num(); i++)
				{
					TSharedPtr<FJsonObject> uidsObj = uidsArray[i]->AsObject();

					FString entityUID = uidsObj->GetStringField(TEXT("data"));

					TArray<FString> keywords;
					const TArray<TSharedPtr<FJsonValue>>* keywordsArrayPtr;
                    if (uidsObj->TryGetArrayField(TEXT("keywords"), keywordsArrayPtr))
                    {
                        TArray<TSharedPtr<FJsonValue>> keywordsArray = *keywordsArrayPtr;

					    for (int32 j = 0; j < keywordsArray.Num(); j++)
					    {
						    keywords.Add(keywordsArray[j]->AsString());
					    }

                        {
                            FScopeLock scopeLock(&EntityKeywordsCritSection);
	
                            EntityKeywords.Add(entityUID, keywords);

                            OnEntityKeywordsUpdated.Broadcast(entityUID, keywords);
                        }
                    }
				}
            }
        }
    }
}

void UVH_DataSync::Sync_GetChangesRequestCompleted(const TArray<uint8>& data)
{
    std::string jsonString(reinterpret_cast<const char*>(data.GetData()), data.Num());

    FString jsonFString(jsonString.c_str());

    TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(*jsonFString);

    TSharedPtr<FJsonObject> jsonObject;
    if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
    {
        const TArray<TSharedPtr<FJsonValue>>* dataArray;
		if (!jsonObject->TryGetArrayField(TEXT("data"), dataArray))
		{
			UE_LOG(VH_COT, Error, TEXT("No 'data' array found in /changes/ API response"));
			return;
		}

		// Only parse the most recent logs
		int32 startElement = dataArray->Num() - LastLogCount;

		// If the number of changes has decreased for some reason, reparse and refill the entire Logs array
		if (dataArray->Num() < LastLogCount)
		{
			UE_LOG(VH_COT, Warning, TEXT("Unexpected shrinkage of change list.  Re-parsing and refilling ChangeLogs"));
			ChangeLogs.Empty(dataArray->Num());
			startElement = dataArray->Num();
			LastLogCount = 0;
		}

		UVH_COTManager* cotManager = UVH_COTManager::Get();

		for (int32 i = startElement - 1; i >= 0; --i)
		{
			TSharedPtr<FJsonObject> dataObj = (*dataArray)[i]->AsObject();
			if (dataObj == nullptr)
			{
				continue;
			}

			FString dataType = dataObj->GetStringField(TEXT("type"));
			FString timestamp = dataObj->GetStringField(TEXT("timestamp"));

			FString userUID = dataObj->GetStringField(TEXT("creatorUid"));
			FString user = TEXT("User");
			TMap<FName, UVH_COTEvent*> allContacts = cotManager->GetContacts();
			if (userUID == cotManager->GetSelfUID().ToString())
			{
				user = cotManager->GetCallsign();
			}
			else
			{
				if (UVH_COTEvent** contactEvent = allContacts.Find(FName(userUID)))
				{
					user = (*contactEvent)->GetAttribute(TEXT("callsign"));
				}
				else
				{
					UnknownUIDs.Add(userUID);
				}
			}

			// Special case: mission created
			if (dataType.Compare(TEXT("CREATE_MISSION"), ESearchCase::IgnoreCase) == 0)
			{
				FString missionName = dataObj->GetStringField(TEXT("missionName"));
				FString changeLog = FString::Printf(TEXT("[%s] Mission '%s' created"), *timestamp, *missionName);
				ChangeLogs.Add(changeLog);
				continue;
			}

			bool isAddingContent = (dataType.Compare(TEXT("ADD_CONTENT"), ESearchCase::IgnoreCase) == 0);
			FString callsign = FString("an object"); // Default value

			if (dataObj->HasField(TEXT("details")))
			{
				const TSharedPtr<FJsonObject>* detailsObj;
				if (dataObj->TryGetObjectField(TEXT("details"), detailsObj))
				{
					callsign = (*detailsObj)->GetStringField(TEXT("callsign"));
				}
			}

			FString verb = (isAddingContent) ? FString("added") : FString("removed");
			FString changeLog = FString::Printf(TEXT("[%s]: %s %s %s"), *timestamp, *user, *verb, *callsign);
			ChangeLogs.Add(changeLog);
		}

		LastLogCount = ChangeLogs.Num();
		ChangesReceived();
	}
}

void UVH_DataSync::Sync_GetKeywords(const TArray<uint8>& data)
{
    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
    {
        std::string jsonString(reinterpret_cast<const char*>(data.GetData()), data.Num());

        FString jsonFString(jsonString.c_str());

        TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(*jsonFString);

        TSharedPtr<FJsonObject> jsonObject;
        if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
        {
            const TArray<TSharedPtr<FJsonValue>>* dataArray;
            if (jsonObject->TryGetArrayField(TEXT("data"), dataArray))
            {
                if (TSharedPtr<FJsonObject> dataObj = (*dataArray)[0]->AsObject())
                {
                    Keywords.Empty();

                    const TArray<TSharedPtr<FJsonValue>>* keywordsArrayPtr;
                    if (dataObj->TryGetArrayField(TEXT("keywords"), keywordsArrayPtr))
                    {
                        TArray<TSharedPtr<FJsonValue>> keywordsArray = *keywordsArrayPtr;

                        for (int32 i = 0; i < keywordsArray.Num(); i++)
                        {
                            Keywords.Add(keywordsArray[i]->AsString());
                        }

                        OnKeywordsUpdated.Broadcast(Keywords);
                    }
                }
            }
        }
    }
}

void UVH_DataSync::HandleAddedFileUploaded(const FString& responseBody, int32 fileSize, const FString& endpoint)
{
    if (UVH_COTManager* cotManager = UVH_COTManager::Get())
    {
        TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(*responseBody);

        TSharedPtr<FJsonObject> jsonObject;
        if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
        {
            FString name = jsonObject->GetStringField(TEXT("Name"));
            FString hash = jsonObject->GetStringField(TEXT("Hash"));

            for (const FString& fullPathToFile : Files)
            {
                if (fullPathToFile.EndsWith(name))
                {
                    FileToHash.Add(fullPathToFile, hash);

                    FString url = FString::Printf(TEXT("https://%s:8443/Marti/api/missions/%s/contents?creatorUID=%s"), *ConnectionInfo->Host, *FGenericPlatformHttp::UrlEncode(Name), *cotManager->UID.ToString());
                    FString verb = TEXT("PUT");

                    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = cotManager->CreateRESTRequest(ConnectionInfo->GetCommoEndpoint(), url, verb, TEXT("application/json"));

                    FString content = FString::Printf(TEXT("{ \"hashes\" : [ \"%s\" ] }"), *hash);
                    request->SetContentAsString(content);

                    request->ProcessRequest();

                    break;
                }
            }
        }
    }
}

void UVH_DataSync::HandleContactsUpdated()
{
	UVH_COTManager* cotManager = UVH_COTManager::Get();
	TMap<FName, UVH_COTEvent*> allContacts = cotManager->GetContacts();

	for (int i = 0; i < UnknownUIDs.Num(); i++)
	{
		FString uid = UnknownUIDs[i];
		if (allContacts.Contains(FName(uid)))
		{
			// Reset changelogs
			UnknownUIDs.Empty();
			ChangeLogs.Empty();
			LastLogCount = 0;
			Sync();
			return;
		}
	}

}
