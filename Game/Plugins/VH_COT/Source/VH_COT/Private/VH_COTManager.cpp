// Required Includes
#include "VH_COTManager.h"
#include "VH_COT.h"

// C++ Standard Library
#include <string>
#include <thread>

// Engine Includes
#include "Async/Async.h"
#include "Misc/FileHelper.h"
#include "GameDelegates.h"
#include "GenericPlatform/GenericPlatformHttp.h"
#include "Misc/Guid.h"
#include "Dom/JsonObject.h"
#include "Math/UnrealMathUtility.h"
#include "XmlFile.h"
#include "OpenCVHelper.h"
#include "PreOpenCVHeaders.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include "PostOpenCVHeaders.h"
#include "Engine/World.h"
#include "Serialization/JsonSerializer.h"
#include "Misc/Paths.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "VH_FileIOStatics.h"
#include "VH_GlobeMathStatics.h"
#include "VH_ImageLoader.h"
#include "Database_Spatialite.h"

// Module Includes
#include "Interface_COTReceiver.h"
#include "VH_COTChat.h"
#include "VH_COTComponent.h"
#include "VH_COTConnectionInfo.h"
#include "VH_COTDelegates.h"
#include "VH_COTEvent.h"
#include "VH_COTUserIcons.h"
#include "VH_DataPackage.h"
#include "VH_DataSync.h"
#include "VH_MilStd2525.h"

// Commo Library
#include "commo.h"

class CommoListener :
    public atakmap::commoncommo::CoTMessageListener,
    public atakmap::commoncommo::ContactPresenceListener,
    public atakmap::commoncommo::MissionPackageIO,
    public atakmap::commoncommo::InterfaceStatusListener,
    public atakmap::commoncommo::CoTSendFailureListener
{
    virtual void cotMessageReceived(const char* cotMessage, const char* rxIfaceEndpointId)
    {
        FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- CoTListener::cotMessageReceived | %s"), ANSI_TO_TCHAR(cotMessage));
		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			cotManager->HandleCotMessageReceived(FString(cotMessage), FString(rxIfaceEndpointId));
		}
    }

    virtual void contactAdded(const atakmap::commoncommo::ContactUID* c)
    {
		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			FString uidString = vh_cot::ConvertFromCommoString(BytesToString(c->contactUID, c->contactUIDLen));
			cotManager->HandleContactUpdated(FName(*uidString), true);
		}
    }

    virtual void contactRemoved(const atakmap::commoncommo::ContactUID* c)
    {
		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			FString uidString = vh_cot::ConvertFromCommoString(BytesToString(c->contactUID, c->contactUIDLen));
			cotManager->HandleContactUpdated(FName(*uidString), false);
		}
    }

    // todo ohg | implement
    virtual atakmap::commoncommo::MissionPackageTransferStatus missionPackageReceiveInit(char* destFile, size_t destFileSize, const char* transferName, const char* sha256hash, uint64_t expectedByteSize, const char* senderCallsign)
    {
        FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- CoTListener::dataPackageReceiveInit"));

        return atakmap::commoncommo::MissionPackageTransferStatus::MP_TRANSFER_FINISHED_SUCCESS;
    }

    // todo ohg | implement
    virtual void missionPackageReceiveStatusUpdate(const atakmap::commoncommo::MissionPackageReceiveStatusUpdate* update)
    {
        FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- CoTListener::dataPackageReceiveStatusUpdate"));
    }

    // todo ohg | implement
    virtual void missionPackageSendStatusUpdate(const atakmap::commoncommo::MissionPackageSendStatusUpdate* update)
    {
        FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- CoTListener::dataPackageSendStatusUpdate"));
    }

    // todo ohg | implement
    virtual atakmap::commoncommo::CoTPointData getCurrentPoint()
    {
        FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- CoTListener::getCurrentPoint"));

        // todo ohg | remove
        atakmap::commoncommo::CoTPointData p(36.5261810013514, -77.3862509255614, COMMO_COT_POINT_NO_VALUE,
                                             COMMO_COT_POINT_NO_VALUE, COMMO_COT_POINT_NO_VALUE);
        return p;
    }

    // todo ohg | implement
    virtual void createUUID(char* uuidString)
    {
        FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- CoTListener::createUUID"));
    }

    virtual void interfaceUp(atakmap::commoncommo::NetInterface* iface)
    {
		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			cotManager->HandleInterfaceStatusUpdate(iface, true);
		}
    }

    virtual void interfaceDown(atakmap::commoncommo::NetInterface* iface)
    {
		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			cotManager->HandleInterfaceStatusUpdate(iface, false);
		}
    }

    virtual void interfaceError(atakmap::commoncommo::NetInterface* iface, atakmap::commoncommo::netinterfaceenums::NetInterfaceErrorCode err)
    {
		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			cotManager->HandleInterfaceError(iface, err);
		}
    }

    virtual void sendCoTFailure(const char* host, int port, const char* errorReason)
    {
        FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- CoTListener::sendCoTFailure | host: %s | port: %d | error: %s"), host, port, ANSI_TO_TCHAR(errorReason));
    }
};

class CommoLogger : public atakmap::commoncommo::CommoLogger
{
	virtual void log(atakmap::commoncommo::CommoLogger::Level level, atakmap::commoncommo::CommoLogger::Type type, const char* message, void* detail)
	{
        FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- CommoLogger::log | %s"), ANSI_TO_TCHAR(message));
    }
};

UVH_COTManager* UVH_COTManager::GlobalInstance = nullptr;

// ---------------------------------
// --- Constructors
// ---------------------------------

UVH_COTManager::UVH_COTManager() :
	MaxCOTsPerTick(2),
	GroupName(TEXT("Cyan")),
	GroupRole(TEXT("Team Member"))
{
	
}

// ---------------------------------
// --- FTickableObjectBase
// ---------------------------------

TStatId UVH_COTManager::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UVH_COTManager, STATGROUP_Tickables);
}

bool UVH_COTManager::IsTickable() const
{
	return bEnabled && Commo != nullptr;
}

void UVH_COTManager::Tick(float deltaSeconds)
{
	// heartbeat
	HeartbeatCounter = FMath::Clamp<float>(HeartbeatCounter, 0, GetHeartbeatCooldown()) - deltaSeconds;
	if (HeartbeatCounter < 0)
	{
		BroadcastHeartbeat();
	}

	// process queued cot events
	TArray<UVH_COTEvent*> cotEvents;
	if (COTReceivedCritSection.TryLock())
	{
		int32 numToHandle = FMath::Min<int32>(QueuedEvents.Num(), MaxCOTsPerTick);
		if (numToHandle > 0)
		{
			for (int32 i = 0; i < numToHandle; i++)
			{
				cotEvents.Add(QueuedEvents[i]);
			}

			QueuedEvents.RemoveAt(0, numToHandle);
			COTReceivedCritSection.Unlock();
			
			for (UVH_COTEvent* cotEvent : cotEvents)
			{
				HandleCOTEvent(cotEvent);
			}
		}
		else
		{
			COTReceivedCritSection.Unlock();
		}
	}
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

const FString UVH_COTManager::GetDataLoader_COT_ClassUID()
{
	return TEXT("7EACAF16D59911E9BB652A2AE2DBCCE4");
}

const FString UVH_COTManager::GetDataLoader_File_ClassUID()
{
	return TEXT("1978D6E58A8C12340C7F86129D8B233B");
}

UVH_COTManager* UVH_COTManager::Get()
{
	return GlobalInstance;
}

bool UVH_COTManager::IsVTAKGhost(UVH_COTEvent* cotEvent)
{
	if (cotEvent != nullptr)
	{
		FString testIconPath = FString(TEXT("ad78aafb-83a6-4c07-b2b9-a897a8b6a38f/Shapes/man.png"));
		FString actualIconPath = cotEvent->GetAttribute(TEXT("detail\tusericon\ticonsetpath"));

		return cotEvent->GetAttribute(TEXT("type")).Equals(TEXT("a-f-G-I-U")) && cotEvent->GetAttribute(TEXT("callsign")).EndsWith(FString("-VRTAK"), ESearchCase::CaseSensitive) && actualIconPath.Equals(testIconPath);
	}

	return false;
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UVH_COTManager::BeginDestroy()
{
	Super::BeginDestroy();

	Cleanup();
}

UWorld* UVH_COTManager::GetWorld() const
{
	return UDeveloper_Statics::GetVHWorld();
}

// ---------------------------------
// --- API
// ---------------------------------

bool UVH_COTManager::Initialize()
{
	GlobalInstance = this;

	if (OverlayCategories.Num() == 0)
	{
		OverlayCategories.Add(TEXT("u-d-v"), TEXT("vehicle"));
		OverlayCategories.Add(TEXT("a-u"), TEXT("unknown_marker"));
		OverlayCategories.Add(TEXT("a-h"), TEXT("hostile_marker"));
		OverlayCategories.Add(TEXT("a-n"), TEXT("neutral_marker"));
		OverlayCategories.Add(TEXT("a-f"), TEXT("friendly_marker"));
		OverlayCategories.Add(TEXT("u-d-f"), TEXT("polyline"));
		OverlayCategories.Add(TEXT("u-d-f-m"), TEXT("telestration"));
		OverlayCategories.Add(TEXT("u-r"), TEXT("rangebearing"));
		OverlayCategories.Add(TEXT("b-m-r"), TEXT("route"));
		OverlayCategories.Add(TEXT("b-m-p-s"), TEXT("spi"));
		OverlayCategories.Add(TEXT("a-contact"), TEXT("contact"));
		OverlayCategories.Add(TEXT("u-d-c-c"), TEXT("circle"));
		OverlayCategories.Add(TEXT("u-d-r"), TEXT("rectangle"));
	}

	LoadSettings();

	// create and initialize UserIcons
	if (UserIconsClass != nullptr)
	{
		UserIcons = NewObject<UVH_COTUserIcons>(this, UserIconsClass, FName("UserIcons"));

		if (UserIcons != nullptr)
		{
			UserIcons->Initialize();
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::Initialize | could not create UserIcons object with class | %s"), *UserIconsClass->GetName());
		}
	}

	InitializeColors();

	// load connection info from local disk
	LoadConnectionInfos();

	// initialize commo
	CommoListenerInstance = new CommoListener();

	if (UID == NAME_None)
	{
		UID = FName(*FGuid::NewGuid().ToString());
	}

	UIDGhost = FName(*FGuid::NewGuid().ToString());

	TArray<BYTE> uidBytes = vh_cot::ConvertStringToBytes(vh_cot::ConvertFromUE4String(UID.ToString()));
	auto contactUID = new atakmap::commoncommo::ContactUID(uidBytes.GetData(), uidBytes.Num());

	if (Callsign.IsEmpty())
	{
		SetCallsign(FPlatformProcess::ComputerName());
	}

	StoreSettings();

	Commo = new atakmap::commoncommo::Commo(new CommoLogger(), contactUID, TCHAR_TO_UTF8(*Callsign));
	if (Commo != nullptr)
	{
		// add listeners
		Commo->addCoTMessageListener(CommoListenerInstance);
		Commo->addContactPresenceListener(CommoListenerInstance);
		Commo->addInterfaceStatusListener(CommoListenerInstance);
		Commo->addCoTSendFailureListener(CommoListenerInstance);
		Commo->setEnableAddressReuse(false);      // todo ohg | copied, make sure this is correct

		for (UVH_COTConnectionInfo* connectionInfo : ConnectionInfos)
		{
			if (connectionInfo->bConnectAtInitialization)
			{
				connectionInfo->CreateConnection();
			}
		}
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("-- Commo == nullptr"));
	}

	bEnabled = true;

	NonSpatialDB_Connect();

	PopulateDataPackages();

	PopulateDataSyncsFromDB();

	FVH_COTDelegates::OnCOTMessageReceived.Broadcast(TEXT("COTManagerInitialized"), FVariant());

	AddGetCOTBoundingBoxDelegate();

	return PostInitialize();
}

void UVH_COTManager::HandleCotMessageReceived(const FString& cotMessage, const FString& rxIfaceEndpointId)
{
	AsyncTask(ENamedThreads::GameThread, [cotMessage, rxIfaceEndpointId]()
	{
		if (UWorld* world = UDeveloper_Statics::GetVHWorld())
		{
			if (world->bIsTearingDown)
			{
				return;
			}
		}
		else
		{
			return;
		}

		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			if (cotManager->bEnabled)
			{
				FGCScopeGuard garbageCollectionGuard;

				const FString& cotMessageSanitized = UVH_COTStatics::SanitizeRawCOTAttributes(cotMessage);

				UVH_COTEvent* cotEvent = NewObject<UVH_COTEvent>();
				cotEvent->PopulateFromXML(cotMessageSanitized);
				//UE_LOG(VH_COT, Warning, TEXT("-- received cot: %s"), *cotMessageSanitized);
			
				cotEvent->CommoInterfaceEndpointID = rxIfaceEndpointId;

				cotManager->AddReceivedCOT(cotEvent);
			}
		}
	});
}

bool UVH_COTManager::ShouldHandleAtomCOT(UVH_COTEvent* cotEvent) const
{
	// only handle atom events that have a corresponding entry in TypeToData or are a contact

	if (!Contacts.Contains(FName(*cotEvent->GetAttribute(TEXT("uid")))))
	{
		FString type = cotEvent->GetAttribute(TEXT("type"));
		
		TSubclassOf<class AActor> actorClass;
		if (!GetBlueprintToSpawn(type, actorClass))
		{
			UE_LOG(VH_COT, Verbose, TEXT("-- UVH_COTManager::ShouldHandleAtomCOT | no actor class associated with %s | returning false"), *type);
			return false;
		}
	}

	return ShouldHandleAtomCOT_Virtual(cotEvent);
}

TSharedRef<IHttpRequest, ESPMode::ThreadSafe> UVH_COTManager::CreateRESTRequest(const FString& commoInterfaceEndpoint, const FString& url, const FString& verb, const FString& mimeType) const
{
	if (bShowInformationLogs)
	{
		UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::CreateRESTRequest | url: %s"), *url);
	}

	TMap<FString, FString> keyValues;

	for (UVH_COTConnectionInfo* connectionInfo : ConnectionInfos)
	{
		if (connectionInfo->GetCommoEndpoint().Equals(commoInterfaceEndpoint, ESearchCase::IgnoreCase))
		{
			if (FPaths::FileExists(connectionInfo->RootDirectory / TEXT("cert.pem")))
			{
				keyValues.Add(TEXT("cert"), connectionInfo->RootDirectory / TEXT("cert.pem"));
			}

			if (FPaths::FileExists(connectionInfo->RootDirectory / TEXT("key.pem")))
			{
				keyValues.Add(TEXT("key"), connectionInfo->RootDirectory / TEXT("key.pem"));
			}

			if (FPaths::FileExists(connectionInfo->RootDirectory / TEXT("caCert.pem")))
			{
				keyValues.Add(TEXT("caCert"), connectionInfo->RootDirectory / TEXT("caCert.pem"));
			}
		}
	}
	
	FHttpModule* http = &FHttpModule::Get();

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = http->CreateRequest();

	request->SetHeader(TEXT("Content-Type"), mimeType);
	request->SetURL(url);
	request->SetVerb(verb);

	if (keyValues.Num() > 0)
	{
		request->CustomizeForVH(keyValues);
	}

	return request;
}

bool UVH_COTManager::UploadFileToTAKServer(const FString& commoInterfaceEndpoint, const FString& url, const FString& fullPathOnDisk, FOnFileUploaded uploadedDelegate)
{
	TArray<uint8> data;
	if (FFileHelper::LoadFileToArray(data, *fullPathOnDisk))
	{
		int32 fileSize = data.Num();

		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = CreateRESTRequest(commoInterfaceEndpoint, url, TEXT("POST"), FGenericPlatformHttp::GetMimeType(fullPathOnDisk));

		request->SetHeader(TEXT("Content-Length"), FString::Printf(TEXT("%d"), fileSize));
		request->SetContent(data);

		request->OnProcessRequestComplete().BindLambda([uploadedDelegate, fileSize, commoInterfaceEndpoint](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
		{
			if (bSucceeded)
			{
				UVH_COTManager::Get()->HandleFileUploaded(response->GetContentAsString(), fileSize, commoInterfaceEndpoint, uploadedDelegate);
			}
		});

		request->ProcessRequest();

		return true;
	}

	UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::UploadFileToTAKServer | could not load file: %s"), *fullPathOnDisk);
	return false;
}

void UVH_COTManager::HandleCOTEvent(UVH_COTEvent* cotEvent)
{
	// Check Delegates
	for (const TPair<FName, FPreHandleCOTEvent>& entry : PreHandleCOTEventDelegateMap)
	{	
		if (entry.Value.IsBound() && entry.Value.Execute(cotEvent))
		{
			return;
		}
	}

	// handle event based on type
	FString type = cotEvent->GetAttribute(TEXT("type"));

	if (type.Len() == 0)
	{
		UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::HandleCOTEvent | unknown type, aborting | uid: %s"), *cotEvent->GetAttribute(TEXT("uid")));
		return;
	}

	FString firstTypeChar = type.Left(1);

	if (firstTypeChar.Equals(TEXT("b")))
	{
		bool bHandled = false;

		bHandled = HandleGeochatEvent(cotEvent);

		if (!bHandled)
		{
			bHandled = HandleVideoEvent(cotEvent);
		}

		if (!bHandled)
		{
			bHandled = HandleDataPackageEvent(cotEvent);
		}

		if (!bHandled)
		{
			HandleAtomEvent(cotEvent);
		}
	}
	else if (firstTypeChar.Equals(TEXT("t")))
	{
		// handle data sync updates
		if (cotEvent->GetAttribute(TEXT("detail\tmission\ttype")).Equals(TEXT("change"), ESearchCase::IgnoreCase))
		{
			FString dataSyncName = cotEvent->GetAttribute(TEXT("detail\tmission\tname"));

			if (UVH_DataSync** dataSyncPtr = DataSyncs.Find(dataSyncName))
			{
				UVH_DataSync* dataSync = *dataSyncPtr;
				dataSync->HandleUpdate(cotEvent);
			}
		}
	}
	else 
	{
		HandleAtomEvent(cotEvent);
	}

	PostHandleCOTEvent_Virtual(cotEvent);

	OnPostHandleCOTEvent.Broadcast(cotEvent);
}

void UVH_COTManager::AddReceivedCOT(UVH_COTEvent* cotEvent)
{
	FScopeLock lock(&COTReceivedCritSection);
	QueuedEvents.Add(cotEvent);
}

void UVH_COTManager::Notify(const FString& message, float duration) const
{

}

void UVH_COTManager::DownloadDataPackageFromTAKServer(UVH_COTConnectionInfo* connectionInfo, const FString& filename, const FString& hash)
{
	FString url = FString::Printf(TEXT("https://%s:8443/Marti/sync/content?hash=%s"), *connectionInfo->Host, *hash);

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = CreateRESTRequest(connectionInfo->GetCommoEndpoint(), url);

	request->OnProcessRequestComplete().BindLambda([filename](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
	{
		if (bSucceeded)
		{
			FString filePath = UDeveloper_Statics::GetUserAppDataPath() / TEXT("VRTAK") / TEXT("Downloads") / filename;
			FFileHelper::SaveArrayToFile(response->GetContent(), *filePath);

			AsyncTask(ENamedThreads::GameThread, [filePath]()
			{
				if (UVH_COTManager* cotManager = UVH_COTManager::Get())
				{
					cotManager->Notify(FString::Printf(TEXT("File \"%s\" received"), *FPaths::GetCleanFilename(filePath)), 5.f);

					cotManager->LoadDataPackageFromDisk(filePath);
				}
			});
		}
	});

	request->ProcessRequest();
}

bool UVH_COTManager::SendCOT(const TArray<FName>& contactUIDs, const FString& cotMessage)
{
	if (Commo != nullptr)
	{
		for (const auto contact : contactUIDs)
		{
			std::string uid(TCHAR_TO_UTF8(*contact.ToString()));
			const atakmap::commoncommo::ContactUID* contactUID = new atakmap::commoncommo::ContactUID(reinterpret_cast<const uint8_t*>(&uid[0]), uid.length());

			atakmap::commoncommo::ContactList contactList(1, &contactUID);

			auto result = Commo->sendCoT(&contactList, TCHAR_TO_UTF8(*cotMessage), atakmap::commoncommo::CoTSendMethod::SEND_ANY);

			delete contactUID;

			if (result != atakmap::commoncommo::COMMO_SUCCESS)
			{
				FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- SendCOT | bad result | %d | %s"), (int)result, *cotMessage);
				UE_LOG(VH_COT, Verbose, TEXT("-- SendCOT | bad result | %d | %s"), (int) result, *cotMessage);

				return false;
			}
		}

		FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- SendCOT | %s"), *cotMessage);

		return true;
	}

	UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::SendCOT | tried to send COT message when Commo is nullptr | %s"), *cotMessage);
	return false;
}

UVH_COTChat* UVH_COTManager::SendGeochatEvent(const FName& contactUID, const FString& message)
{
	if (UVH_COTEvent** cotEventPtr = Contacts.Find(contactUID))
	{
		UVH_COTEvent* contactEvent = *cotEventPtr;

		UVH_COTEvent* cotEvent = NewObject<UVH_COTEvent>();
		
		cotEvent->SetAttribute(TEXT("uid"), FString::Printf(TEXT("GeoChat.%s.%s.%s"), *UID.ToString(), *cotEvent->GetAttribute(TEXT("callsign")), *FGuid::NewGuid().ToString()));
		cotEvent->SetAttribute(TEXT("type"), TEXT("b-t-f"));
		cotEvent->PopulateTime(FTimespan(24, 0, 0));

		TArray<FXmlAttribute> attributes;
		attributes.Add(FXmlAttribute(TEXT("uid"), UID.ToString()));
		attributes.Add(FXmlAttribute(TEXT("type"), TEXT("a-f-G-U-C-I")));
		attributes.Add(FXmlAttribute(TEXT("relation"), TEXT("p-p")));

		cotEvent->AddNode(TEXT("link"), attributes);

		attributes.Empty();
		attributes.Add(FXmlAttribute(TEXT("id"), contactUID.ToString()));
		attributes.Add(FXmlAttribute(TEXT("chatroom"), contactEvent->GetAttribute(TEXT("callsign"))));
		attributes.Add(FXmlAttribute(TEXT("senderCallsign"), Callsign));
		attributes.Add(FXmlAttribute(TEXT("groupOwner"), TEXT("false")));
		
		cotEvent->AddNode(TEXT("detail\t__chat"), attributes);

		attributes.Empty();
		attributes.Add(FXmlAttribute(TEXT("id"), contactUID.ToString()));
		attributes.Add(FXmlAttribute(TEXT("uid0"), UID.ToString()));
		attributes.Add(FXmlAttribute(TEXT("uid1"), contactUID.ToString()));

		cotEvent->AddNode(TEXT("detail\t__chat\tchatgrp"), attributes);

		attributes.Empty();
		attributes.Add(FXmlAttribute(TEXT("source"), FString::Printf(TEXT("VTAK.%s"), *UID.ToString())));
		attributes.Add(FXmlAttribute(TEXT("sourceID"), UID.ToString()));
		attributes.Add(FXmlAttribute(TEXT("to"), contactUID.ToString()));
		attributes.Add(FXmlAttribute(TEXT("time"), UVH_COTStatics::GetISOTime(FDateTime::UtcNow())));

		cotEvent->AddNode(TEXT("detail\tremarks"), attributes, true, message);

		TArray<FName> sendUIDs;
		sendUIDs.Add(contactUID);
		SendCOT(sendUIDs, cotEvent->ToXML());

		// add to history
		UVH_COTChat* chatItem = NewObject<UVH_COTChat>();
		chatItem->Timestamp = cotEvent->GetAttribute<FDateTime>(TEXT("time"));
		chatItem->OtherUID = contactUID;
		chatItem->OtherCallsign = contactEvent->GetAttribute(TEXT("callsign"));
		chatItem->Message = message;
		chatItem->bSending = true;
		chatItem->AddToDatabase(NonSpatialDB);

		return chatItem;
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::SendGeochatEvent | cannot find contactUID in Contacts"));
	}

	return nullptr;
}

bool UVH_COTManager::BroadcastCOT(const FString& cotMessage)
{
	if (Commo != nullptr)
	{
		auto result = Commo->broadcastCoT(TCHAR_TO_UTF8(*cotMessage), atakmap::commoncommo::CoTSendMethod::SEND_ANY);
		if (result != atakmap::commoncommo::COMMO_SUCCESS)
		{
			UE_LOG(VH_COT, Verbose, TEXT("-- UVH_COTManager::BroadcastCOT | bad result | %d | \n%s"), (int)result, *cotMessage);
			return false;
		}

		//UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::BroadcastCOT: \n\n%s"), *cotMessage);
		//FPlatformMisc::LowLevelOutputDebugStringf(TEXT("-- BroadcastCOT: \n%s"), *cotMessage);

		return true;
	}

	UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::BroadcastCOT | tried to send COT message when Commo is nullptr | %s"), *cotMessage);
	
	return false;
}

void UVH_COTManager::StoreConnectionInfos()
{
	for (UVH_COTConnectionInfo* connectionInfo : ConnectionInfos)
	{
		connectionInfo->WriteXMLToFile(connectionInfo->RootDirectory);
	}
}

void UVH_COTManager::LoadConnectionInfos()
{
	auto convertPrefToConnections = [](const FString& fullPathToPref)
	{
		TArray<UVH_COTConnectionInfo*> connectionInfos;

		FXmlFile xmlFile(fullPathToPref);
		if (xmlFile.IsValid())
		{
			FXmlNode* rootNode = xmlFile.GetRootNode();

			const TArray<FXmlNode*> preferenceNodes = rootNode->GetChildrenNodes();
			for (const auto& preferenceNode : preferenceNodes)
			{
				if (preferenceNode->GetAttribute(TEXT("name")).Equals("cot_streams", ESearchCase::IgnoreCase))
				{
					FString version = preferenceNode->GetAttribute(TEXT("version"));
					TMap<FString, FString> backupKeyToNodeToContent;
					for (int32 i = 0; i < preferenceNodes.Num(); i++)
					{
						if (preferenceNodes[i] != preferenceNode && preferenceNodes[i]->GetAttribute(TEXT("version")).Equals(version))
						{
							const TArray<FXmlNode*> entryNodes = preferenceNodes[i]->GetChildrenNodes();
							for (const auto& entryNode : entryNodes)
							{
								backupKeyToNodeToContent.Add(entryNode->GetAttribute(TEXT("key")), entryNode->GetContent());
							}
						}
					}

					// store entries
					TMap<FString, FString> keyToNodeContent;
					const TArray<FXmlNode*> entryNodes = preferenceNode->GetChildrenNodes();
					for (const auto& entryNode : entryNodes)
					{
						keyToNodeContent.Add(entryNode->GetAttribute(TEXT("key")), entryNode->GetContent());
					}

					int32 numStreams = 0;
					if (auto countFind = keyToNodeContent.Find(TEXT("count")))
					{
						numStreams = FCString::Atoi(*(*countFind));
					}

					auto getContent = [&keyToNodeContent, &backupKeyToNodeToContent](const FString& key, int32 index)
					{
						FString toFind = FString::Printf(TEXT("%s%d"), *key, index);

						auto findPointer = keyToNodeContent.Find(toFind);
						if (findPointer != nullptr)
						{
							return *findPointer;
						}
						else 
						{
							// try without suffix
							toFind = FString::Printf(TEXT("%s"), *key);

							findPointer = backupKeyToNodeToContent.Find(toFind);
							if (findPointer != nullptr)
							{
								return *findPointer;
							}
						}

						UE_LOG(VH_COT, Warning, TEXT("-- couldn't find connection param: %s"), *toFind);
						return FString();
					};

					for (int32 i = 0; i < numStreams; i++)
					{
						UVH_COTConnectionInfo* connectionInfo = NewObject<UVH_COTConnectionInfo>();
						connectionInfo->DisplayName = getContent(TEXT("description"), i);
						connectionInfo->bConnectAtInitialization = getContent(TEXT("enabled"), i).Equals(TEXT("true"), ESearchCase::IgnoreCase);

						TArray<FString> connectStringElements;
						FString connectString = getContent(TEXT("connectString"), i);
						connectString.ParseIntoArray(connectStringElements, TEXT(":"));
						if (connectStringElements.Num() == 3)
						{
							connectionInfo->ConnectionProtocol = EConnectionProtocolTypes::E_TCP;

							FString protocol = connectStringElements[2].ToLower();
							if (protocol.Equals(TEXT("ssl")) || protocol.Equals(TEXT("quic")))
							{
								connectionInfo->Host = connectStringElements[0];
								connectionInfo->Port = FCString::Atoi(*connectStringElements[1]);
								connectionInfo->ConnectionType = ECOTConnectionType::ECT_Stream;

								connectionInfo->ConnectionProtocol = EConnectionProtocolTypes::E_SSL;
								if (protocol.Equals(TEXT("quic")))
								{
									connectionInfo->ConnectionProtocol = EConnectionProtocolTypes::E_QUIC;
								}
							}
							else
							{
								UE_LOG(VH_COT, Warning, TEXT("-- unknown connectString type: %s"), *connectStringElements[2]);
								continue;
							}
						}
						else
						{
							UE_LOG(VH_COT, Warning, TEXT("-- connectString improper format: %s"), *connectString);
							continue;
						}

						TArray<FString> certLocationElements;
						FString certLocation = getContent(TEXT("certificateLocation"), i);
						certLocation.ParseIntoArray(certLocationElements, TEXT("/"));

						if (certLocationElements.Num() > 0)
						{
							connectionInfo->ClientCertificateName = certLocationElements.Last();
						}
						connectionInfo->ClientCertificatePassword = getContent(TEXT("clientPassword"), i);

						certLocationElements.Empty();
						certLocation = getContent(TEXT("caLocation"), i);
						certLocation.ParseIntoArray(certLocationElements, TEXT("/"));

						if (certLocationElements.Num() > 0)
						{
							connectionInfo->CertificateAuthorityName = certLocationElements.Last();
						}
						connectionInfo->CertificateAuthorityPassword = getContent(TEXT("caPassword"), i);

						connectionInfo->bEnrollForCert = getContent(TEXT("enrollForCertificateWithTrust"), i).Equals(TEXT("true"), ESearchCase::IgnoreCase);

						connectionInfo->bQUIC = getContent(TEXT("network_quic_enabled"), i).Equals(TEXT("true"), ESearchCase::IgnoreCase);

						connectionInfos.Add(connectionInfo);
					}
				}
			}
		}

		return connectionInfos;
	};

	TArray<UVH_COTConnectionInfo*> newConnectionInfos;
	TMap<FString, UVH_COTConnectionInfo*> connectedDirectories;
	for (UVH_COTConnectionInfo* connectionInfo : ConnectionInfos)
	{
		if (connectionInfo->bConnected)
		{
			connectedDirectories.Add(connectionInfo->RootDirectory, connectionInfo);
		}
	}

	FString fullPath = FPaths::Combine(UDeveloper_Statics::GetUserAppDataPath(), TEXT("VRTAK"), TEXT("Connections"));

	// convert pref files to xml
	TArray<FString> prefFiles;
	IFileManager& fileManager = IFileManager::Get();
	fileManager.FindFiles(prefFiles, *(fullPath / TEXT("*.pref")), true, false);
	for (const FString& prefFile : prefFiles)
	{
		TArray<UVH_COTConnectionInfo*> connectionInfos = convertPrefToConnections(fullPath / prefFile);
		for (UVH_COTConnectionInfo* connectionInfo : connectionInfos)
		{
			const FString connectionDirectory = fullPath / connectionInfo->DisplayName;

			fileManager.DeleteDirectory(*connectionDirectory, false, true);

			// create directory for connnection
			fileManager.MakeDirectory(*connectionDirectory, true);

			connectionInfo->RootDirectory = connectionDirectory;

			bool bDeletePref = true;

			// copy referenced certificates to connection directory
			if (!connectionInfo->ClientCertificateName.IsEmpty())
			{
				FString certPath = fullPath / connectionInfo->ClientCertificateName;
				if (FPaths::FileExists(*certPath))
				{
					fileManager.Copy(*(connectionDirectory / connectionInfo->ClientCertificateName), *certPath);
				}
				else
				{
					bDeletePref = false;
				}
			}

			if (!connectionInfo->CertificateAuthorityName.IsEmpty())
			{
				FString certPath = fullPath / connectionInfo->CertificateAuthorityName;
				if (FPaths::FileExists(*certPath))
				{
					fileManager.Copy(*(connectionDirectory / connectionInfo->CertificateAuthorityName), *certPath);
				}
				else
				{
					bDeletePref = false;
				}
			}

			connectionInfo->WriteXMLToFile(connectionDirectory);

			if (bDeletePref)
			{
				fileManager.Delete(*(fullPath / prefFile));

				if (!connectionInfo->ClientCertificateName.IsEmpty())
				{
					fileManager.Delete(*(fullPath / connectionInfo->ClientCertificateName));
				}

				if (!connectionInfo->CertificateAuthorityName.IsEmpty())
				{
					fileManager.Delete(*(fullPath / connectionInfo->CertificateAuthorityName));
				}
			}
		}
	}

	// parse xmls to create ConnectionInfos
	TArray<FString> connectionFolders;
	fileManager.FindFiles(connectionFolders, *(fullPath / TEXT("*")), false, true);
	for (const FString& connectionFolder : connectionFolders)
	{
		FString currentDirectory = fullPath / connectionFolder;

		// Skip if we already have a connection for this directory
		if (connectedDirectories.Contains(currentDirectory))
		{
			newConnectionInfos.Add(connectedDirectories[currentDirectory]);
			continue;
		}

		UVH_COTConnectionInfo* connectionInfo = UVH_COTConnectionInfo::CreateNewConnectionInfo(currentDirectory);

		if (connectionInfo != nullptr)
		{
			connectionInfo->OnReceivedConnectionError.AddDynamic(this, &UVH_COTManager::HandleReceivedConnectionError);
			connectionInfo->OnReceivedConnectionStatusUpdate.AddDynamic(this, &UVH_COTManager::HandleReceivedConnectionStatusUpdate);

			newConnectionInfos.Add(connectionInfo);
		}
	}

	ConnectionInfos.Empty();
	ConnectionInfos.Append(newConnectionInfos);
}

bool UVH_COTManager::AddOrUpdateConnection(UVH_COTConnectionInfo* connectionObject)
{
	if (connectionObject == nullptr)
	{
		UE_LOG(VH_COT, Warning, TEXT("AddOrUpdateConnection -- received pointer to null, please use pointer to valid UVH_COTConnectionInfo object."));
		return false;
	}

	// If a connection object with the same RootDirectory exists in ConnectionInfos array, delete it and replace it with the newer copy.
	RemoveConnection(connectionObject, false);

	if (connectionObject->RootDirectory.IsEmpty())
	{
		// This is a new connection, assign it a new root directory.
		if (connectionObject->DisplayName.IsEmpty())
		{
			// In case user hits submit without a proper display name.
			connectionObject->DisplayName = FString("NewConnection");
		}

		FString connectionNewRoot = FPaths::Combine(UDeveloper_Statics::GetUserAppDataPath(), TEXT("VRTAK"), TEXT("Connections"), connectionObject->DisplayName);
		connectionObject->RootDirectory = connectionNewRoot;
	}

	// Handle possibility of user having selected a new certificate. Check to see if a path to the new certificate has been chosen, and if it's valid.
	// Note: path to certificate is not saved to the XML, so if there was a certificate selected, ensure CertificateName is not empty.
	FString potentialCertificateAuthority = connectionObject->CertificateAuthorityPath;
	if (!potentialCertificateAuthority.IsEmpty())
	{
		if (FPaths::GetPath(potentialCertificateAuthority) != connectionObject->RootDirectory)
		{
			// If certificate is external to root, copy it over.
			IFileManager& fileManager = IFileManager::Get();

			if (fileManager.FileExists(*(potentialCertificateAuthority)))
			{
				FString destinationFile = connectionObject->RootDirectory / FPaths::GetCleanFilename(potentialCertificateAuthority);
				fileManager.Copy(*(destinationFile), *(potentialCertificateAuthority));
			}
			else
			{
				UE_LOG(VH_COT, Warning, TEXT("AddOrUpdateConnection -- unable to locate certificate, could not copy it to root directory."));
			}
		}
		connectionObject->CertificateAuthorityName = FPaths::GetCleanFilename(potentialCertificateAuthority);
	}
	else
	{
		connectionObject->CertificateAuthorityName.Empty();
	}

	FString potentialClientCertificate = connectionObject->ClientCertificatePath;
	if (!potentialClientCertificate.IsEmpty())
	{
		if (FPaths::GetPath(potentialClientCertificate) != connectionObject->RootDirectory)
		{
			// If certificate is external to root, copy it over.
			IFileManager& fileManager = IFileManager::Get();

			if (fileManager.FileExists(*(potentialClientCertificate)))
			{
				FString destinationFile = connectionObject->RootDirectory / FPaths::GetCleanFilename(potentialClientCertificate);
				fileManager.Copy(*(destinationFile), *(potentialClientCertificate));
			}
			else
			{
				UE_LOG(VH_COT, Warning, TEXT("AddOrUpdateConnection -- unable to locate certificate, could not copy it to root directory."));
			}
		}
		connectionObject->ClientCertificateName = FPaths::GetCleanFilename(potentialClientCertificate);
	}
	else
	{
		connectionObject->ClientCertificateName.Empty();
	}

	// Add to ConnectionInfos array and force a write to XML to save changes.
	ConnectionInfos.Add(connectionObject);

	connectionObject->WriteXMLToFile(connectionObject->RootDirectory);

	connectionObject->OnConnectionUpdated.Broadcast(connectionObject);

	return true;
}

bool UVH_COTManager::RemoveConnection(UVH_COTConnectionInfo* connectionInfoToBeRemoved, bool bDeleteRootDirectory)
{
	if (connectionInfoToBeRemoved == nullptr)
	{
		return false;
	}

	FString connectionID = connectionInfoToBeRemoved->RootDirectory;
	bool bFullDeletion = false;

	// Check to see if there is anything to even delete, using the connectionInfo RootDirectory as a unique ID.
	for (uint8 i = 0; i < ConnectionInfos.Num(); i++)
	{
		if (ConnectionInfos[i]->RootDirectory.Equals(connectionID, ESearchCase::CaseSensitive))
		{
			if (!ConnectionInfos[i]->IsDisconnected())
			{
				// Connection exists, before we remove it, we should make sure to disconnect it.
				ConnectionInfos[i]->Disconnect();
			}

			if (bDeleteRootDirectory)
			{
				// If we want to fully remove the connection, also delete the root directory.
				IFileManager& fileManager = IFileManager::Get();

				FString connectionRootToDelete = ConnectionInfos[i]->RootDirectory;
				bFullDeletion = fileManager.DeleteDirectory(*connectionRootToDelete, false, true);
			}

			ConnectionInfos.RemoveAt(i);

			break;
		}
	}

	if (bFullDeletion)
	{
		// If root directory was deleted, broadcast that this connection is to be removed permanently.
		connectionInfoToBeRemoved->OnConnectionDeleted.Broadcast();
	}

	return true;
}

void UVH_COTManager::AddVideo(UVH_COTDetail_Video* cotVideo)
{
	for (UVH_COTDetail_Video* video : Videos)
	{
		if (video->GetVideoURL().Equals(cotVideo->GetVideoURL()))
		{
			return;
		}
	}

	cotVideo->AddToDatabase(NonSpatialDB);

	Videos.Add(cotVideo);

	OnUpdatedVideoList.Broadcast();
}

void UVH_COTManager::RemoveVideo(UVH_COTDetail_Video* cotVideo)
{
	FString url = cotVideo->GetVideoURL();
	for (int32 i = 0; i < Videos.Num(); i++)
	{
		if (Videos[i]->GetVideoURL() == url)
		{
			Videos.RemoveAt(i, 1);
			cotVideo->RemoveFromDatabase(NonSpatialDB);
			OnUpdatedVideoList.Broadcast();
			return;
		}
	}
}

void UVH_COTManager::PopulateDataSyncsFromTAKServer()
{
	auto handleRequestCompleted = [](const TArray<uint8>& data, UVH_COTConnectionInfo* connectionInfo)
	{
		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			std::string jsonString(reinterpret_cast<const char*>(data.GetData()), data.Num());

			FString jsonFString(jsonString.c_str());

			TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(*jsonFString);

			TSharedPtr<FJsonObject> jsonObject;
			if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
			{
				TArray<TSharedPtr<FJsonValue>> dataArray = jsonObject->GetArrayField(TEXT("data"));
				for (int32 i = 0; i < dataArray.Num(); i++)
				{
					TSharedPtr<FJsonObject> obj = dataArray[i]->AsObject();

					UVH_DataSync* dataSync = cotManager->AddDataSync(obj->GetStringField(TEXT("name")), connectionInfo, false);
					dataSync->Description = obj->GetStringField(TEXT("description"));
					dataSync->CreateTime = vh_cot::GetDateTime(obj->GetStringField(TEXT("createTime")));

					TArray<FString> keywords;
					TArray<TSharedPtr<FJsonValue>> keywordsArray = obj->GetArrayField(TEXT("keywords"));
					for (int32 j = 0; j < keywordsArray.Num(); j++)
					{
						keywords.Add(keywordsArray[j]->AsString());
					}
					dataSync->SetKeywordsFromTAKServer(keywords);

					TArray<TSharedPtr<FJsonValue>> uidsDataArray = obj->GetArrayField(TEXT("uids"));
					for (int32 j = 0; j < uidsDataArray.Num(); j++)
					{
						TSharedPtr<FJsonObject> uidObj = uidsDataArray[j]->AsObject();

						FDateTime timestamp = vh_cot::GetDateTime(uidObj->GetStringField(TEXT("timestamp")));
						dataSync->AddUpdateHistory(uidObj->GetStringField(TEXT("creatorUid")), timestamp);
					}
				}

				cotManager->OnUpdatedDataSyncList.Broadcast();
			}
			else
			{
				UE_LOG(VH_COT, Warning, TEXT("-- unable to deserialize datasyncs"));
			}
		}
	};

	if (UWorld* world = GetWorld())
	{
		if (world->GetNetMode() != NM_Client)
		{
			for (UVH_COTConnectionInfo* connectionInfo : ConnectionInfos)
			{
				if (connectionInfo->bConnected)
				{
					FString url = FString::Printf(TEXT("https://%s:8443/Marti/api/missions?defaultRole=true"), *connectionInfo->Host);

					TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = CreateRESTRequest(connectionInfo->GetCommoEndpoint(), url);

					request->OnProcessRequestComplete().BindLambda([&handleRequestCompleted, connectionInfo](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
					{
						if (bSucceeded)
						{
							AsyncTask(ENamedThreads::GameThread, [&handleRequestCompleted, response, connectionInfo]()
							{
								if (UVH_COTManager* cotManager = UVH_COTManager::Get())
								{
									handleRequestCompleted(response->GetContent(), connectionInfo);
								}
							});
						}
					});

					request->ProcessRequest();
				}
			}
		}
	}
}

TArray<UVH_COTConnectionInfo*> UVH_COTManager::GetConnectionInfos() const
{
	return ConnectionInfos;
}

bool UVH_COTManager::IsConnectedToTAKServer() const
{
	TArray<UVH_COTConnectionInfo*> connectionInfos = GetConnectionInfos();
	for (UVH_COTConnectionInfo* connectionInfo : connectionInfos)
	{
		if (connectionInfo->bConnected)
		{
			return true;
		}
	}

	return false;
}

UVH_COTUserIcons* UVH_COTManager::GetUserIcons() const
{
	return UserIcons;
}

FName UVH_COTManager::GetSelfUID() const
{
	return UID;
}

FName UVH_COTManager::GetGroupName() const
{
	return GroupName;
}

FName UVH_COTManager::GetGroupRole() const
{
	return GroupRole;
}

TArray<UVH_COTDetail_Video*> UVH_COTManager::GetVideos() const
{
	return Videos;
}

TArray<UVH_DataPackage*> UVH_COTManager::GetDataPackages() const
{
	TArray<UVH_DataPackage*> dataPackages;
	DataPackages.GenerateValueArray(dataPackages);

	return dataPackages;
}

UVH_DataPackage* UVH_COTManager::GetDataPackage(const FString& name) const
{
	return *DataPackages.Find(name);
}

UVH_DataPackage* UVH_COTManager::AddDataPackage(const FString& name)
{
	FString fullPathOnDisk = UDeveloper_Statics::GetUserAppDataPath() / TEXT("VRTAK") / TEXT("DataPackages") / name + TEXT(".zip");

	if (!DataPackages.Contains(fullPathOnDisk))
	{
		UVH_DataPackage* dataPackage = NewObject<UVH_DataPackage>((UObject*)GetTransientPackage(), DataPackageClass);
		dataPackage->Name = name;
		dataPackage->FullPathToZipOnDisk = fullPathOnDisk;

		DataPackages.Add(fullPathOnDisk, dataPackage);

		FString query = FString::Printf(TEXT("replace into dataPackages values (\"%s\", \"%s\", \"%d\", \"%d\")"), *dataPackage->Name, *dataPackage->FullPathToZipOnDisk, dataPackage->bLoaded ? 1 : 0, dataPackage->bVisible ? 1 : 0);
		NonSpatialDB->SyncQuery(query);

		OnUpdatedDataPackageList.Broadcast();
	}

	return *DataPackages.Find(fullPathOnDisk);
}

void UVH_COTManager::RemoveDataPackage(const FString& fullPathOnDisk)
{
	if (UVH_DataPackage** dataPackagePtr = DataPackages.Find(fullPathOnDisk))
	{
		UVH_DataPackage* dataPackage = *dataPackagePtr;

		dataPackage->RemoveContent();

		DataPackages.Remove(fullPathOnDisk);

		FString query = FString::Printf(TEXT("delete from dataPackages where fullPathOnDisk = \"%s\""), *fullPathOnDisk);
		NonSpatialDB->SyncQuery(query);

		IFileManager& fileManager = IFileManager::Get();
		fileManager.Delete(*fullPathOnDisk, false, true, false);

		OnUpdatedDataPackageList.Broadcast();
	}
}

UVH_DataSync* UVH_COTManager::AddDataSync(const FString& name, UVH_COTConnectionInfo* connectionInfo, bool bNotify)
{
	UVH_DataSync* dataSync = nullptr;
	bool bUpdated = false;

	if (UVH_DataSync** dataSyncPtr = DataSyncs.Find(name))
	{
		dataSync = *dataSyncPtr;
		dataSync->ConnectionInfo = connectionInfo;
	}
	else
	{
		dataSync = NewObject<UVH_DataSync>((UObject*)GetTransientPackage(), DataSyncClass);
		dataSync->Name = name;
		dataSync->ConnectionInfo = connectionInfo;

		DataSyncs.Add(name, dataSync);

		bUpdated = true;
	}

	if (bNotify && bUpdated)
	{
		OnUpdatedDataSyncList.Broadcast();
	}

	return dataSync;
}

// todo ohg | support multiple datasyncs with same name but different tak servers
void UVH_COTManager::RemoveDataSync(UVH_DataSync* dataSync, bool bUnload)
{
	if (bUnload)
	{
		dataSync->Unload();
	}

	dataSync->RemoveContent();

	DataSyncs.Remove(dataSync->Name);

	FString query = FString::Printf(TEXT("delete from dataSyncs where name = \"%s\""), *dataSync->Name);
	NonSpatialDB->SyncQuery(query);

	OnUpdatedDataSyncList.Broadcast();
}

TArray<UVH_DataSync*> UVH_COTManager::GetSortedDataSyncs(EDataSyncSort sortType, const FString& filter) const
{
	TMap<FString, UVH_DataSync*> dataSyncs;

	dataSyncs.Append(DataSyncs);

	if (!filter.IsEmpty())
	{
		TArray<FString> toRemove;
		for (const TPair<FString, UVH_DataSync*>& entry : dataSyncs)
		{
			bool bNameMatch = entry.Value->Name.Contains(filter);

			bool bKeywordMatch = false;
			TArray<FString> keywords = entry.Value->GetKeywords();
			for (const FString& keyword : keywords)
			{
				if (keyword.Contains(filter))
				{
					bKeywordMatch = true;

					break;
				}
			}

			if (!bNameMatch && !bKeywordMatch)
			{
				toRemove.Add(entry.Value->Name);
			}
		}

		for (const FString& name : toRemove)
		{
			dataSyncs.Remove(name);
		}
	}

	switch (sortType)
	{
		case EDataSyncSort::EDS_None:
		{
			// Do not sort
		}
		break;

		case EDataSyncSort::EDS_Name:
		{
			// sort map by value's name
			dataSyncs.KeySort([](const FString a, const FString b)
			{
				return a < b;
			});
		}
		break;

		case EDataSyncSort::EDS_Status:
		{
			TMap<FString, UVH_DataSync*> dataSyncsSubscribed;
			TMap<FString, UVH_DataSync*> dataSyncsUnsubscribed;
			for (const auto& entry : dataSyncs)
			{
				if (entry.Value->IsSubscribed())
				{
					dataSyncsSubscribed.Add(entry.Key, entry.Value);
				}
				else
				{
					dataSyncsUnsubscribed.Add(entry.Key, entry.Value);
				}
			}

			// sort map by last update
			dataSyncsSubscribed.ValueSort([](UVH_DataSync& a, UVH_DataSync& b)
			{
				return a.GetLastUpdate() > b.GetLastUpdate();
			});

			dataSyncsUnsubscribed.ValueSort([](UVH_DataSync& a, UVH_DataSync& b)
			{
				return a.GetLastUpdate() > b.GetLastUpdate();
			});

			dataSyncs.Empty();
			dataSyncs.Append(dataSyncsSubscribed);
			dataSyncs.Append(dataSyncsUnsubscribed);
		}
		break;
	}

	TArray<UVH_DataSync*> dataSyncArray;
	dataSyncs.GenerateValueArray(dataSyncArray);
	return dataSyncArray;
}

UVH_DataSync* UVH_COTManager::GetDataSync(const FString& name) const
{
	if (DataSyncs.Contains(name))
	{
		return DataSyncs[name];
	}
	else
	{
		return nullptr;
	}
}

bool UVH_COTManager::AddColorToGroupColorMap(FName colorName, FLinearColor groupColor)
{
	GroupNameToColor.Add(colorName, groupColor);

	return GroupNameToColor.Contains(colorName);
}

bool UVH_COTManager::GetGroupColor(FName colorName, FLinearColor& groupColor)
{
	if (auto groupColorPtr = GroupNameToColor.Find(colorName))
	{
		groupColor = *groupColorPtr;

		return true;
	}

	groupColor = FLinearColor(0.f, 1.f, 1.f);

	return false;
}

TMap<FName, FLinearColor> UVH_COTManager::GetGroupColors()
{
	return GroupNameToColor;
}

TArray<UVH_COTChat*> UVH_COTManager::GetChatsWith(const FName& uid, bool bUpdateChatsViewedTime)
{
	TArray<UVH_COTChat*> chats;

	FString query = FString::Printf(TEXT("select * from chats where otherUID = \"%s\""), *uid.ToString());

	SpatialiteResults results;
	NonSpatialDB->SyncQuery(query, results);

	for (const SpatialiteResult& result : results)
	{
		UVH_COTChat* chat = NewObject<UVH_COTChat>();
		chat->PopulateFromDB(result);

		chats.Add(chat);
	}

	if (bUpdateChatsViewedTime)
	{
		UpdateChatViewedTime(uid);
	}

	return chats;
}

int32 UVH_COTManager::GetNumberOfNewChats(const FName& uid) const
{
	FString query = FString::Printf(TEXT("select count(otherUID) as count from chatViews where otherUID = \"%s\""), *uid.ToString());

	SpatialiteResults results;
	NonSpatialDB->SyncQuery(query, results);

	query = FString::Printf(TEXT("select count(otherUID) as count from chats where otherUID = \"%s\" and sending = 0"), *uid.ToString());

	if (UDatabase_Spatialite::GetInteger(TEXT("count"), results[0]) > 0)
	{
		// viewed chats before
		query = FString::Printf(TEXT("%s and timestamp > (select timestamp from chatViews where otherUID = \"%s\")"), *query, *uid.ToString());
	}

	SpatialiteResults results2;
	NonSpatialDB->SyncQuery(query, results2);
	if (results2.Num() == 1)
	{
		return UDatabase_Spatialite::GetInteger(TEXT("count"), results2[0]);
	}

	UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::GetNumberOfNewChats | query had bad number of results"), *query);

	return 0;
}

void UVH_COTManager::UpdateChatViewedTime(const FName& uid)
{
	FString query = FString::Printf(TEXT("replace into chatViews values (\"%s\", datetime(\"now\"))"), *uid.ToString());
	NonSpatialDB->SyncQuery(query);

	OnViewedChat.Broadcast(uid);
}

void UVH_COTManager::BroadcastHeartbeat()
{
	HeartbeatCounter = GetHeartbeatCooldown();

	// actual
	{
		UVH_COTEvent* contactEvent = NewObject<UVH_COTEvent>();
		contactEvent->SetAttribute(TEXT("uid"), UID.ToString());
		contactEvent->SetAttribute(TEXT("type"), TEXT("a-f-G-U-C"));
		contactEvent->SetAttribute(TEXT("detail\ttakv\tplatform"), TEXT("VR-TAK"));
        contactEvent->SetAttribute(TEXT("detail\ttakv\tversion"), TEXT("1.0"));

		contactEvent->PopulateTime(FTimespan(0, 0, 15));

		contactEvent->SetAttribute(TEXT("callsign"), Callsign);
		contactEvent->SetAttribute(TEXT("endpoint"), TEXT("*:-1:stcp"));
		contactEvent->SetAttribute(TEXT("groupName"), GetGroupName().ToString());
		contactEvent->SetAttribute(TEXT("groupRole"), GetGroupRole().ToString());

		contactEvent->SetPoint(HeartbeatCoordinate);
		
		BroadcastCOT(contactEvent->ToXML());
	}

	// virtual
	if (bBroadcastGhost)
	{
		UVH_COTEvent* ghostEvent = NewObject<UVH_COTEvent>();
		ghostEvent->SetAttribute(TEXT("uid"), UIDGhost.ToString());
		ghostEvent->SetAttribute(TEXT("type"), TEXT("a-f-G-I-U"));
		ghostEvent->PopulateTime(FTimespan(0, 0, 15));

		ghostEvent->SetAttribute(TEXT("callsign"), Callsign + FString(TEXT("-VRTAK")));
		ghostEvent->SetAttribute(TEXT("detail\tusericon\ticonsetpath"), TEXT("ad78aafb-83a6-4c07-b2b9-a897a8b6a38f/Shapes/man.png"));
		ghostEvent->SetAttribute<FColor>(TEXT("detail\tcolor\targb"), FColor(0, 255, 255, 255));

		ghostEvent->SetPoint(GetGeodeticLocation());

		BroadcastCOT(ghostEvent->ToXML());
	}
}

UVH_COTEvent* UVH_COTManager::GetCotEventFromUID(const FString& entityUID) const
{
	return nullptr;
}

void UVH_COTManager::QueryServerForDataPackages(UVH_COTConnectionInfo* connectionInfo)
{
	auto handleRequestCompleted = [](UVH_COTConnectionInfo* connectionInfo, const FString& responseBody)
	{
		TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(responseBody);

		TSharedPtr<FJsonObject> jsonObject;
		if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
		{
			TArray<FSDataPackageInfo> dataPackageInfos;

			TArray<TSharedPtr<FJsonValue>> dataArray = jsonObject->GetArrayField(TEXT("results"));
			for (int32 i = 0; i < dataArray.Num(); i++)
			{
				TSharedPtr<FJsonObject> obj = dataArray[i]->AsObject();

				FSDataPackageInfo dataPackageInfo;
				dataPackageInfo.ConnectionInfo = connectionInfo;

				FString temp = TEXT("");
				obj->TryGetStringField(TEXT("Tool"), temp);
				bool bPrivate = temp.Equals(TEXT("private"), ESearchCase::IgnoreCase);

				if (!bPrivate)
				{
					obj->TryGetStringField(TEXT("Name"), temp);
					dataPackageInfo.KeyValues.Add(TEXT("name"), temp);

					temp = TEXT("");
					obj->TryGetStringField(TEXT("SubmissionDateTime"), temp);
					dataPackageInfo.KeyValues.Add(TEXT("createTime"), temp);

					temp = TEXT("");
					obj->TryGetStringField(TEXT("SubmissionUser"), temp);
					dataPackageInfo.KeyValues.Add(TEXT("creator"), temp);

					temp = TEXT("");
					obj->TryGetStringField(TEXT("Hash"), temp);
					dataPackageInfo.KeyValues.Add(TEXT("hash"), temp);

					temp = TEXT("");
					obj->TryGetStringField(TEXT("Size"), temp);
					dataPackageInfo.KeyValues.Add(TEXT("size"), temp);

					dataPackageInfos.Add(dataPackageInfo);
				}
			}

			AsyncTask(ENamedThreads::GameThread, [dataPackageInfos]()
			{
				if (UVH_COTManager* cotManager = UVH_COTManager::Get())
				{
					cotManager->OnReceivedDataPackageQuery.Broadcast(dataPackageInfos);
				}
			});
		}
	};

	if (connectionInfo->bConnected)
	{
		FString url = FString::Printf(TEXT("https://%s:8443/Marti/sync/search?keywords=missionpackage"), *connectionInfo->Host);

		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = CreateRESTRequest(connectionInfo->GetCommoEndpoint(), url, TEXT("GET"));

		request->OnProcessRequestComplete().BindLambda([&handleRequestCompleted, connectionInfo](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
		{
			if (bSucceeded)
			{
				handleRequestCompleted(connectionInfo, response->GetContentAsString());
			}
		});

		request->ProcessRequest();
	}
}

FName UVH_COTManager::GetOverlayCategory(UVH_COTEvent* cotEvent) const
{
	if (Contacts.Contains(FName(*cotEvent->GetAttribute(TEXT("uid")))))
	{
		return OverlayCategories[TEXT("a-contact")];
	}

	FString type = cotEvent->GetAttribute(TEXT("type"));

	// search exact match
	for (const TPair<FString, FName>& entry : OverlayCategories)
	{
		if (type.Equals(entry.Key))
		{
			return entry.Value;
		}
	}

	// search using StartsWith
	for (const TPair<FString, FName>& entry : OverlayCategories)
	{
		if (type.StartsWith(entry.Key))
		{
			return entry.Value;
		}
	}

	UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::GetOverlayCategory | cannot determine category for type: %s"), *type);
	return TEXT("generic");
}

TMap<FName, UVH_COTEvent*> UVH_COTManager::GetContacts() const
{
	TMap<FName, UVH_COTEvent*> contactsCopy;

	contactsCopy.Append(Contacts);

	// filter out contacts that aren't fully populated
	TArray<FName> toRemove;
	for (const TPair<FName, UVH_COTEvent*>& entry : contactsCopy)
	{
		if (entry.Value->GetAttribute(TEXT("callsign")).IsEmpty())
		{
			toRemove.Add(entry.Key);
		}
	}

	for (const FName& uid : toRemove)
	{
		contactsCopy.Remove(uid);
	}

	return contactsCopy;
}

void UVH_COTManager::GetVideoList()
{
	auto handleRequestCompleted = [](const TArray<uint8>& data)
	{
		FString fileContents = TEXT("");
		FFileHelper::BufferToString(fileContents, data.GetData(), data.Num());

		int32 chopPos = fileContents.Find(TEXT("?>"));
		if (chopPos >= 0)
		{
			fileContents = fileContents.RightChop(chopPos + 2);
		}

		// put all the file contents into an FXmlFile
		FXmlFile xmlVideoFile(fileContents, EConstructMethod::ConstructFromBuffer);
		if (xmlVideoFile.IsValid())
		{
			if (FXmlNode* rootNode = xmlVideoFile.GetRootNode())
			{
				if (const FXmlNode* firstChild = rootNode->GetFirstChildNode())
				{
					TArray<FXmlNode*> xmlNodes = xmlVideoFile.GetRootNode()->GetChildrenNodes();

					// add the name, IP address, and COTDetail_Video to the struct and add it to the array for all xml nodes that were found
					for (FXmlNode* currentNode : xmlNodes)
					{
						if (currentNode != nullptr)
						{
							// create new video object
							if (UVH_COTDetail_Video* videoDetail = NewObject<UVH_COTDetail_Video>())
							{
								// populate the video from xml nodes.
								if (videoDetail->PopulateFromXMLRest(currentNode))
								{
									if(!videoDetail->Alias.Contains(".pdf") && !videoDetail->Alias.Contains(".ppt"))
									{
										AsyncTask(ENamedThreads::GameThread, [videoDetail]()
										{
											if (UVH_COTManager* cotManager = UVH_COTManager::Get())
											{
												cotManager->VideoDetails.Add(FVideoDetails(videoDetail));
											}
										});
									}
								}
								else
								{
									UE_LOG(VH_COT, Warning, TEXT("VH_COTManager::GetVideoList() -- ERROR: Populating the UVH_COTDetail_Video failed"));
								}
							}
						}
					}

					AsyncTask(ENamedThreads::GameThread, []()
					{
						if (UVH_COTManager* cotManager = UVH_COTManager::Get())
						{
							// only fire the delegate when all VideoListRequests have returned
							if (cotManager->VideoListRequests.Num() == 0)
							{
								cotManager->OnReceivedVideoDetails.Broadcast(cotManager->VideoDetails);
							}
						}
					});
				}
			}
		}
	};

	// empty previously populated video details
	VideoDetails.Empty();

	// cancel ongoing video list requests
	for (TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request : VideoListRequests)
	{
		request->CancelRequest();
	}
	VideoListRequests.Empty();

	// request video list from each valid connection
	for (UVH_COTConnectionInfo* connectionInfo : ConnectionInfos)
	{
		if (connectionInfo->bConnected)
		{
			TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = CreateRESTRequest(connectionInfo->GetCommoEndpoint(), "https://" + connectionInfo->Host + ":8443/Marti/vcm/");

			request->OnProcessRequestComplete().BindLambda([&handleRequestCompleted](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
			{
				if (bSucceeded && response.IsValid() && response->GetResponseCode() == EHttpResponseCodes::Type::Ok)
				{
					AsyncTask(ENamedThreads::GameThread, [request]()
					{
						if (UVH_COTManager* cotManager = UVH_COTManager::Get())
						{
							if(request.IsValid())
							{
								TSharedRef<IHttpRequest, ESPMode::ThreadSafe> requestRef = request.ToSharedRef();

								cotManager->VideoListRequests.Remove(requestRef);
							}
						}
					});

					handleRequestCompleted(response->GetContent());
				}
			});

			VideoListRequests.Add(request);

			request->ProcessRequest();
		}
	}
}

void UVH_COTManager::PopulateVideos()
{
	FString query = FString::Printf(TEXT("select * from videos"));

	SpatialiteResults results;
	NonSpatialDB->SyncQuery(query, results);

	for (const SpatialiteResult& result : results)
	{
		UVH_COTDetail_Video* video = NewObject<UVH_COTDetail_Video>();

		video->PopulateFromDB(result);

		AddVideo(video);
	}
}

FGeodeticCoord3D UVH_COTManager::GetGeodeticLocation() const
{
	return FGeodeticCoord3D(0, 0, 0);
}

FString UVH_COTManager::GetCallsign() const
{
	return Callsign;
}

void UVH_COTManager::SetCallsign(const FString& inCallsign)
{
	if (!Callsign.Equals(inCallsign))
	{
		Callsign = inCallsign;

		StoreSettings();

		OnUpdatedCallsign.Broadcast(Callsign);
	}
}

bool UVH_COTManager::IsContact(const FString& entityUID) const
{
	return Contacts.Contains(FName(*entityUID));
}

TArray<FString> UVH_COTManager::GetRoles() const
{
	TArray<FString> roles;

	TArray<UVH_COTEvent*> contacts;
	GetContacts().GenerateValueArray(contacts);

	for (UVH_COTEvent* cotEvent : contacts)
	{
		FString role = cotEvent->GetAttribute(TEXT("groupRole"));
		if (!role.Equals(TEXT("Team Member"), ESearchCase::IgnoreCase))
		{
			roles.AddUnique(role);
		}
	}

	return roles;
}

TArray<UVH_COTEvent*> UVH_COTManager::GetContactsInRole(const FString& role) const
{
	TArray<UVH_COTEvent*> roleContacts;

	TArray<UVH_COTEvent*> contacts;
	GetContacts().GenerateValueArray(contacts);

	for (UVH_COTEvent* cotEvent : contacts)
	{
		FString contactRole = cotEvent->GetAttribute(TEXT("groupRole"));
		if (role.Equals(contactRole))
		{
			roleContacts.Add(cotEvent);
		}
	}

	return roleContacts;
}

void UVH_COTManager::GetTypeData(const FString& type, FCOTTypeData& typeData) const
{
	auto getWildcardData = [this](const FString& type, FCOTTypeData& typeData)
	{
		TArray<FString> typeArray;
		type.ParseIntoArray(typeArray, TEXT("-"));

		for (const TPair<FString, FCOTTypeData>& entry : TypeToData)
		{
			bool bFoundMatch = true;
			if (entry.Key.Contains(TEXT("*")))
			{
				TArray<FString> blueprintType;
				entry.Key.ParseIntoArray(blueprintType, TEXT("-"));

				for (int32 i = 0; i < blueprintType.Num(); i++)
				{
					// wildcard always passes; continue
					if (blueprintType[i].Equals(TEXT("*")))
					{
						continue;
					}

					// blueprintType length is greater than typeArray and it's not a wildcard; fail out
					if (i > typeArray.Num() - 1)
					{
						bFoundMatch = false;
						break;
					}

					// blueprintType is same as typeArray; continue
					if (blueprintType[i].Equals(typeArray[i]))
					{
						continue;
					}

					bFoundMatch = false;
					break;
				}

				// if matching so far and typeArray length is greather than blueprint type, check last element of blueprint type for wildcard
				if (bFoundMatch && typeArray.Num() > blueprintType.Num())
				{
					bFoundMatch = blueprintType.Last().Equals(TEXT("*"));
				}

				if (bFoundMatch)
				{
					typeData = entry.Value;

					return true;
				}
			}
		}

		return false;
	};

	// check for exact match
	if (TypeToData.Contains(type))
	{
		typeData = TypeToData[type];
	}
	else
	{
		// search with wildcards
		getWildcardData(type, typeData);
	}
}

void UVH_COTManager::GetCOTCoordinates(UVH_COTEvent* cotEvent, FGeodeticCoord2D& northWest, FGeodeticCoord2D& southEast) const
{
	for (const FGetCOTBoundingBox& getBoundingBoxDelegate : COTBoundingBoxLambdas)
	{
		if (getBoundingBoxDelegate.Execute(cotEvent, northWest, southEast))
		{
			return;
		}
	}

	FGeodeticCoord2D geodeticCoordinate = cotEvent->GetPoint().ToGeodeticCoord2D();

	northWest = geodeticCoordinate;
	southEast = geodeticCoordinate;
}

AActor* UVH_COTManager::SpawnActorFromType(const FString& type) const
{
	TSubclassOf<class AActor> actorClass;
	if (GetBlueprintToSpawn(type, actorClass))
	{
		FActorSpawnParameters spawnParams;
		spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		return vh_cot::GetWorld()->SpawnActor<AActor>(actorClass, spawnParams);
	}

	if (bShowInformationLogs)
	{
		UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::SpawnActorFromType | no blueprint mapped to cot type: %s"), *type);
	}

	return nullptr;
}

FName UVH_COTManager::AddPreHandleCOTEventDelegate(FPreHandleCOTEvent eventDelegate)
{
	FName uid = FName(FGuid::NewGuid().ToString());

	PreHandleCOTEventDelegateMap.Add(uid, eventDelegate);

	return uid;
}

bool UVH_COTManager::RemovePreHandleCOTEventDelegate(FName uid)
{
	if (PreHandleCOTEventDelegateMap.Contains(uid))
	{
		PreHandleCOTEventDelegateMap.Remove(uid);

		return true;
	}

	return false;
}

void UVH_COTManager::SetAttachedFile(const FString& entityUID, const FString& fullPathToFile, bool bShouldSend)
{
	FString query = FString::Printf(TEXT("select entityUID from attachments where entityUID = \"%s\" and fullPathToFile = \"%s\""), *entityUID, *fullPathToFile);

	SpatialiteResults results;
	NonSpatialDB->SyncQuery(query, results);

	if (results.Num() == 0)
	{
		query = FString::Printf(TEXT("insert into attachments (entityUID, fullPathToFile, shouldSend, shouldShow) values (\"%s\", \"%s\", %d, 0)"), *entityUID, *fullPathToFile, bShouldSend);
	}
	else
	{
		query = FString::Printf(TEXT("update attachments set shouldSend = %d where entityUID = \"%s\" and fullPathToFile = \"%s\""), bShouldSend, *entityUID, *fullPathToFile);
	}

	NonSpatialDB->SyncQuery(query);

	OnAttachmentsModified.Broadcast(entityUID);
}

void UVH_COTManager::RemoveAttachedFiles(const FString& entityUID, const FString& fullPathToFile)
{
	// delete entries from database
	FString query = FString::Printf(TEXT("delete from attachments where entityUID = \"%s\""), *entityUID);

	if (!fullPathToFile.IsEmpty())
	{
		query = FString::Printf(TEXT("%s and fullPathToFile = \"%s\""), *query, *fullPathToFile);
	}
	
	NonSpatialDB->SyncQuery(query);

	OnAttachmentsModified.Broadcast(entityUID);
}

FSpatialiteResults_BP UVH_COTManager::GetAttachedFiles(const FString& entityUID) const
{
	FString query = FString::Printf(TEXT("select * from attachments where entityUID = \"%s\""), *entityUID);

	SpatialiteResults results;
	NonSpatialDB->SyncQuery(query, results);
	
	return FSpatialiteResults_BP(results);
}

UTexture2D* UVH_COTManager::GetAttachmentTexture(const FString& entityUID, FVector2D& dimensions) const
{
	FSpatialiteResults_BP resultsBP = GetAttachedFiles(entityUID);

	for (const FSpatialiteResult_BP& resultBP : resultsBP.Results)
	{
		bool bShouldShow = UDatabase_Spatialite::GetBool(TEXT("shouldShow"), resultBP.Result);

		if (bShouldShow)
		{
			FString fullPathToFile = UDatabase_Spatialite::GetString(TEXT("fullPathToFile"), resultBP.Result);

			FVector2D scaledDimensions;
			TArray<uint8> pixelData;
			if (UVH_ImageLoader::LoadImageFromDisk(fullPathToFile, scaledDimensions, dimensions, pixelData))
			{
				UTexture2D* texture = UDeveloper_Statics::CreateTextureFromPixels(scaledDimensions.X, scaledDimensions.Y, pixelData);

				return texture;
			}
		}
	}

	return nullptr;
}

void UVH_COTManager::SetShouldShowAttachment(const FString& entityUID, const FString& fullPathToFile, bool bShow)
{
	// only one attachment can show per entityUID
	if (bShow)
	{
		FString query = FString::Printf(TEXT("update attachments set shouldShow = 0 where entityUID = \"%s\" and fullPathToFile != \"%s\""), *entityUID, *fullPathToFile);
		NonSpatialDB->SyncQuery(query);
	}

	FString query = FString::Printf(TEXT("update attachments set shouldShow = %d where entityUID = \"%s\" and fullPathToFile = \"%s\""), bShow, *entityUID, *fullPathToFile);
	NonSpatialDB->SyncQuery(query);

	OnAttachmentsModified.Broadcast(entityUID);
}

bool UVH_COTManager::LoadDataPackageFromDisk(FString fullPathToZipFile, bool bForceImport)
{
	/* extract files
	*
	*  if !onReceiveDelete: copy data package .zip file to VRTAK/DataPackages so it shows up in DataPackages UI
	*
	*  if onReceiveImport: import data package through Import Manager
	*
	*  delete extracted files (should be copied to VRTAK/Cache during import through Import Manager)
	*/

	bool bHandled = false;

	IFileManager& fileManager = IFileManager::Get();

	// extract files
	FString path = TEXT("");
	FString filename = TEXT("");
	FString extension = TEXT("");
	FPaths::Split(fullPathToZipFile, path, filename, extension);

	const FString unzipPath = UDeveloper_Statics::GetUserAppDataPath() / TEXT("VRTAK") / TEXT("Temp") / filename + TEXT("_extracted");

	// delete old extracted files (if any) from previous load of data package
	fileManager.DeleteDirectory(*unzipPath, false, true);
	while (fileManager.DirectoryExists(*unzipPath))
	{
		// wait for OS to entirely delete the dir
		FPlatformProcess::Sleep(0.1f);
	}

	UVH_FileIOStatics::UnzipFile(fullPathToZipFile, unzipPath);

	bool bOnReceiveImport = true;
	bool bOnReceiveDelete = false;

	const FString manifestPath = unzipPath / TEXT("MANIFEST/manifest.xml");
	FXmlFile manifestXMLFile(manifestPath);
	if (manifestXMLFile.IsValid())
	{
		bHandled = true;

		// determine values for onReceiveImport and onReceiveDelete
		if (FXmlNode* configurationNode = manifestXMLFile.GetRootNode()->FindChildNode(TEXT("Configuration")))
		{
			const TArray<FXmlNode*> configurationChildren = configurationNode->GetChildrenNodes();
			for (FXmlNode* configurationChild : configurationChildren)
			{
				if (configurationChild->GetAttribute(TEXT("name")).Equals(TEXT("onReceiveImport"), ESearchCase::IgnoreCase))
				{
					bOnReceiveImport = configurationChild->GetAttribute(TEXT("value")).Equals(TEXT("true"), ESearchCase::IgnoreCase);
				}

				if (configurationChild->GetAttribute(TEXT("name")).Equals(TEXT("onReceiveDelete"), ESearchCase::IgnoreCase))
				{
					bOnReceiveDelete = configurationChild->GetAttribute(TEXT("value")).Equals(TEXT("true"), ESearchCase::IgnoreCase);
				}
			}
		}
	}

	bOnReceiveImport = bForceImport || bOnReceiveImport;

	// handle OnReceiveDelete
	UVH_DataPackage* dataPackage = nullptr;
	if (!bOnReceiveDelete)
	{
		// copy to VRTAK/DataPackages so it will show up in DataPackages UI
		if (!path.EndsWith(TEXT("VRTAK/DataPackages"), ESearchCase::IgnoreCase))
		{
			FString destination = UDeveloper_Statics::GetUserAppDataPath() / TEXT("VRTAK") / TEXT("DataPackages") / filename + TEXT(".") + extension;
			fileManager.Copy(*destination, *fullPathToZipFile);

			fullPathToZipFile = destination;
		}

		// create data package object if doesn't exist
		if (UVH_DataPackage** dataPackagePtr = DataPackages.Find(fullPathToZipFile))
		{
			dataPackage = *dataPackagePtr;

			if (bOnReceiveImport)
			{
				dataPackage->RemoveContent();
			}
		}
		else
		{
			dataPackage = NewObject<UVH_DataPackage>((UObject*)GetTransientPackage(), DataPackageClass);
			dataPackage->FullPathToZipOnDisk = fullPathToZipFile;
			dataPackage->Name = filename;

			DataPackages.Add(fullPathToZipFile, dataPackage);
		}
	}

	// handle OnReceiveImport
	if (bOnReceiveImport)
	{
		// register through Import Manager
		TArray<FString> extractedFiles;

		// register top level files
		fileManager.FindFiles(extractedFiles, *(unzipPath / TEXT("*.*")), true, false);
		for (const FString& extractedFilename : extractedFiles)
		{
			// register file
			FString destination = unzipPath / extractedFilename;

			RegisterFile(destination);

			if (dataPackage != nullptr)
			{
				dataPackage->UpdateContents(destination);
			}
		}

		// register files referenced in manifest
		if (manifestXMLFile.IsValid())
		{
			if (FXmlNode* contents = manifestXMLFile.GetRootNode()->FindChildNode(TEXT("Contents")))
			{
				TArray<FXmlNode*> contentNodes = contents->GetChildrenNodes();
				for (FXmlNode* contentNode : contentNodes)
				{
					FString zipEntry = contentNode->GetAttribute(TEXT("zipEntry"));

					// don't register top level files (handled above)
					if (zipEntry.Contains(TEXT("/")) || zipEntry.Contains(TEXT("\\")))
					{
						// check if it's an attachment
						bool bAttachment = false;

						TArray<FString> zipEntryParsed;
						zipEntry.ParseIntoArray(zipEntryParsed, TEXT("/"));

						if (zipEntryParsed.Num() > 0)
						{
							FString entityUID = zipEntryParsed[0];

							TArray<FXmlNode*> parameterNodes = contentNode->GetChildrenNodes();
							for (FXmlNode* parameterNode : parameterNodes)
							{
								FString parameterName = parameterNode->GetAttribute(TEXT("name"));
								if (parameterName.Equals(TEXT("uid"), ESearchCase::IgnoreCase))
								{
									FString uid = parameterNode->GetAttribute(TEXT("value"));
									if (!uid.IsEmpty() && !uid.Equals(entityUID))
									{
										bAttachment = true;

										// copy to attachments directory
										FString destination = UDeveloper_Statics::GetUserAppDataPath() / TEXT("VRTAK") / TEXT("Attachments") / zipEntry;
										fileManager.Copy(*destination, *(unzipPath / zipEntry));

										SetAttachedFile(uid, destination, true);
									}
								}
							}
						}

						if (!bAttachment)
						{
							// register file
							FString destination = unzipPath / zipEntry;

							RegisterFile(destination);

							if (dataPackage != nullptr)
							{
								dataPackage->UpdateContents(destination);
							}
						}
					}
				}
			}
		}

		if (dataPackage != nullptr)
		{
			dataPackage->bLoaded = true;
			dataPackage->bVisible = true;
		}
	}

	// handle OnReceiveDelete
	if (!bOnReceiveDelete)
	{
		OnReceivedDataPackage.Broadcast();

		OnUpdatedDataPackageList.Broadcast();
	}

	// update database
	if (dataPackage != nullptr)
	{
		FString query = FString::Printf(TEXT("replace into dataPackages values (\"%s\", \"%s\", \"%d\", \"%d\")"), *dataPackage->Name, *dataPackage->FullPathToZipOnDisk, dataPackage->bLoaded ? 1 : 0, dataPackage->bVisible ? 1 : 0);
		NonSpatialDB->SyncQuery(query);
	}

	// delete extracted files (copied to VTAK/Cache if imported)
	fileManager.DeleteDirectory(*unzipPath, false, true);

	return bHandled;
}

void UVH_COTManager::SetHeartbeatCoordinate(const FGeodeticCoord3D& coordinate)
{
	HeartbeatCoordinate = coordinate;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

TSet<AActor*> UVH_COTManager::GetActorsForEntity(const FString& entityUID) const
{
	UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::GetActorsForEntityUID | returning empty set, implement in game layer"));

	TSet<AActor*> actors;
	return actors;
}

void UVH_COTManager::StoreSettings() const
{

}

void UVH_COTManager::LoadSettings()
{

}

AActor* UVH_COTManager::SpawnActor(UVH_COTEvent* cotEvent) const
{
	FString cotType = cotEvent->GetAttribute(TEXT("type"));

	if (Contacts.Contains(FName(*cotEvent->GetAttribute(TEXT("uid")))))
	{
		cotType = TEXT("a-contact");
	}

	return SpawnActorFromType(cotType);
}

void UVH_COTManager::HandleAtomEvent_Virtual(UVH_COTEvent* cotEvent)
{

}

bool UVH_COTManager::HandleDataPackageEvent(UVH_COTEvent* cotEvent)
{
	if (cotEvent->GetAttribute(TEXT("type")).Equals(TEXT("b-f-t-r")))
	{
		FString senderURL = cotEvent->GetAttribute(TEXT("detail\tfileshare\tsenderUrl"));
		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = CreateRESTRequest(cotEvent->CommoInterfaceEndpointID, senderURL);

		request->OnProcessRequestComplete().BindLambda([cotEvent](FHttpRequestPtr request, FHttpResponsePtr response, bool bSucceeded)
		{
			if (cotEvent != nullptr)
			{
				if (bSucceeded)
				{
					FString filePath = FPaths::Combine(UDeveloper_Statics::GetUserAppDataPath(), TEXT("VRTAK"), TEXT("Downloads"), cotEvent->GetAttribute(TEXT("detail\tfileshare\tname")) + TEXT(".zip"));

					FFileHelper::SaveArrayToFile(response->GetContent(), *filePath);

					AsyncTask(ENamedThreads::GameThread, [filePath]()
						{
							if (UVH_COTManager* cotManager = UVH_COTManager::Get())
							{
								cotManager->Notify(FString::Printf(TEXT("File \"%s\" received"), *FPaths::GetCleanFilename(filePath)), 5.f);

								cotManager->LoadDataPackageFromDisk(filePath);
							}
						});
				}
			}
			else
			{
				UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::HandleDataPackageEvent | cotEvent is nullptr in OnProcessRequestComplete lambda | aborting"));
			}
		});

		request->ProcessRequest();

		return true;
	}

	return false;
}

float UVH_COTManager::GetHeartbeatCooldown() const
{
	return 15;
}

bool UVH_COTManager::PostInitialize()
{
	return true;
}

bool UVH_COTManager::ShouldHandleAtomCOT_Virtual(UVH_COTEvent* cotEvent) const
{
	return true;
}

void UVH_COTManager::PostHandleCOTEvent_Virtual(UVH_COTEvent* cotEvent)
{

}

void UVH_COTManager::Cleanup()
{
	if (GlobalInstance == nullptr)
	{
		return;
	}

	// NOTE: This lock ensures that we finish handling a COT message before continuing with cleanup
	FScopeLock scopeLock(&ShutdownCritSection);

	bEnabled = false;

	if (Commo != nullptr)
	{
		delete Commo;
		Commo = nullptr;
	}

	if (CommoListenerInstance != nullptr)
	{
		delete CommoListenerInstance;
		CommoListenerInstance = nullptr;
	}

	if (GlobalInstance == this)
	{
		GlobalInstance = nullptr;
	}
}

void UVH_COTManager::HandleInterfaceStatusUpdate(atakmap::commoncommo::NetInterface* interface, bool bConnected)
{
	AsyncTask(ENamedThreads::GameThread, [interface, bConnected]()
	{
		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			for (UVH_COTConnectionInfo* connectionInfo : cotManager->ConnectionInfos)
			{
				if (connectionInfo->Interface == interface)
				{
					connectionInfo->bConnected = bConnected;

					if (bConnected)
					{
						connectionInfo->ConnectionError = TEXT("");

						cotManager->HandleReceivedConnectionError(connectionInfo);
					}
					
					cotManager->HandleReceivedConnectionStatusUpdate(connectionInfo);
				}
			}
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::HandleInterfaceStatusUpdate | cotManager is nullptr"));
		}
	});
}

void UVH_COTManager::HandleInterfaceError(atakmap::commoncommo::NetInterface* interface, atakmap::commoncommo::netinterfaceenums::NetInterfaceErrorCode error)
{
	auto getErrorText = [](atakmap::commoncommo::netinterfaceenums::NetInterfaceErrorCode error)
	{
		switch (error)
		{
			case atakmap::commoncommo::netinterfaceenums::ERR_CONN_NAME_RES_FAILED:
				return FString(TEXT("Name resolution for a hostname failed"));

			case atakmap::commoncommo::netinterfaceenums::ERR_CONN_REFUSED:
				return FString(TEXT("Connection to remote host actively refused"));

			case atakmap::commoncommo::netinterfaceenums::ERR_CONN_TIMEOUT:
				return FString(TEXT("Connection to remote host timed out"));

			case atakmap::commoncommo::netinterfaceenums::ERR_CONN_HOST_UNREACHABLE:
				return FString(TEXT("Remote host is known to be unreachable at this time"));

			case atakmap::commoncommo::netinterfaceenums::ERR_CONN_SSL_NO_PEER_CERT:
				return FString(TEXT("Remote host was expected to present an SSL certificate but didn't"));

			case atakmap::commoncommo::netinterfaceenums::ERR_CONN_SSL_PEER_CERT_NOT_TRUSTED:
				return FString(TEXT("Remote host's SSL certificate was not trusted"));

			case atakmap::commoncommo::netinterfaceenums::ERR_CONN_SSL_HANDSHAKE:
				return FString(TEXT("SSL handshake with remote host encountered an error"));

			case atakmap::commoncommo::netinterfaceenums::ERR_CONN_OTHER:
				return FString(TEXT("Some other, non-specific, error occurred during attempting to connect to a remote host"));

			case atakmap::commoncommo::netinterfaceenums::ERR_IO_RX_DATA_TIMEOUT:
				return FString(TEXT("No data was received and the connection was considered in error/timed out and is being reset"));

			case atakmap::commoncommo::netinterfaceenums::ERR_IO:
				return FString(TEXT("A general IO error occurred"));

			case atakmap::commoncommo::netinterfaceenums::ERR_INTERNAL:
				return FString(TEXT("Some internal error occurred (out of memory, etc)"));

			case atakmap::commoncommo::netinterfaceenums::ERR_OTHER:
				return FString(TEXT("Some unclassified error has occurred"));
		}

		return FString::Printf(TEXT("Unknown error: %d"), (int32)error);
	};

	AsyncTask(ENamedThreads::GameThread, [interface, error, &getErrorText]()
	{
		if (UVH_COTManager* cotManager = UVH_COTManager::Get())
		{
			for (UVH_COTConnectionInfo* connectionInfo : cotManager->ConnectionInfos)
			{
				if (connectionInfo->Interface == interface)
				{
					connectionInfo->ConnectionError = getErrorText(error);

					cotManager->HandleReceivedConnectionError(connectionInfo);
				}
			}
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::HandleInterfaceError | cotManager is nullptr | error: %s"), *getErrorText(error));
		}
	});
}

void UVH_COTManager::HandleAtomEvent(UVH_COTEvent* cotEvent)
{
	if (bShowInformationLogs)
	{
		UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::HandleAtomEvent | %s"), *cotEvent->GetAttribute(TEXT("type")));
	}

	if (Contacts.Contains(FName(*cotEvent->GetAttribute(TEXT("uid")))))
	{
		// update contact's cotEvent to latest
		Contacts.Add(FName(*cotEvent->GetAttribute(TEXT("uid"))), cotEvent);
	}
	else if (PotentialContacts.Contains(FName(*cotEvent->GetAttribute(TEXT("uid")))) && !cotEvent->GetAttribute(TEXT("endpoint")).IsEmpty())
	{
		// graduate from potential contact to actual contact
		PotentialContacts.Remove(FName(*cotEvent->GetAttribute(TEXT("uid"))));

		Contacts.Add(FName(*cotEvent->GetAttribute(TEXT("uid"))), cotEvent);

		OnUpdateContacts.Broadcast();
	}

	if (ShouldHandleAtomCOT(cotEvent))
	{
		TSet<AActor*> actors = GetActorsForEntity(cotEvent->GetAttribute(TEXT("uid")));
		for (AActor* actor : actors)
		{
			if (actor->GetClass()->ImplementsInterface(UInterface_COTReceiver::StaticClass()))
			{
				if (UVH_COTComponent* cotComponent = IInterface_COTReceiver::Execute_GetCOTComponent(actor))
				{
					cotComponent->ReceiveCOTUpdate(cotEvent);
				}
				else
				{
					UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::HandleAtomEvent | cotComponent is nullptr | %s | %s"), *actor->GetName(), *cotEvent->GetAttribute(TEXT("type")));
				}
			}
		}

		HandleAtomEvent_Virtual(cotEvent);
	}
}

bool UVH_COTManager::HandleGeochatEvent(UVH_COTEvent* cotEvent)
{
	if (cotEvent->GetAttribute(TEXT("type")).Equals(TEXT("b-t-f")))
	{
		FName uid0 = FName(*cotEvent->GetAttribute(TEXT("detail\t__chat\tchatgrp\tuid0")));
		if (UVH_COTEvent** cotEventPtr = Contacts.Find(uid0))
		{
			// add to history
			UVH_COTChat* chatItem = NewObject<UVH_COTChat>();
			chatItem->Timestamp = cotEvent->GetAttribute<FDateTime>(TEXT("detail\tremarks\ttime"));
			chatItem->OtherUID = uid0;
			chatItem->OtherCallsign = cotEvent->GetAttribute(TEXT("detail\t__chat\tsenderCallsign"));
			chatItem->Message = cotEvent->GetNodeContent(TEXT("detail\tremarks"));
			chatItem->bSending = false;
			chatItem->AddToDatabase(NonSpatialDB);

			// broadcast
			OnReceivedChat.Broadcast(uid0, chatItem);

			return true;
		}
		else
		{
			UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::HandleGeochatEvent | received geochat but could not find contact | from: %s"), *cotEvent->GetAttribute(TEXT("detail\t__chat\tsenderCallsign")));
		}
	}

	return false;
}

bool UVH_COTManager::HandleVideoEvent(UVH_COTEvent* cotEvent)
{
	if (cotEvent->GetAttribute(TEXT("type")).Equals(TEXT("b-i-v")))
	{
		UVH_COTDetail_Video* cotVideo = NewObject<UVH_COTDetail_Video>();
		
		TArray<FXmlNode*> videoNodes = cotEvent->GetNodes(TEXT("detail\t__video"));
		for (FXmlNode* videoNode : videoNodes)
		{
			if (cotVideo->PopulateFromXML(videoNode))
			{
				AddVideo(cotVideo);
			}
		}
		
		return true;
	}

	return false;
}

void UVH_COTManager::HandleContactUpdated(const FName& uid, bool bAdded)
{
	AsyncTask(ENamedThreads::GameThread, [&, uid, bAdded]()
	{
		if (UVH_COTManager::Get() != nullptr)
		{
			if (bAdded)
			{
				PotentialContacts.Add(uid);
			}
			else
			{
				PotentialContacts.Remove(uid);
				Contacts.Remove(uid);

				OnUpdateContacts.Broadcast();
			}
		}
	});
}

bool UVH_COTManager::GetBlueprintToSpawn(const FString& type, TSubclassOf<class AActor>& actorClass) const
{
	FCOTTypeData typeData;
	GetTypeData(type, typeData);
	
	actorClass = typeData.ActorClass;
		
	return actorClass != nullptr;
}

void UVH_COTManager::InitializeColors()
{
	//There are discrepancies between TAK applications in what colors a user may self-assign.
	//e.g., a WinTAK user cannot set themself to Black or Grey but can still see users of those colors.

	float alpha = 1.f;

	GroupNameToColor.Add(TEXT("Black"), FLinearColor(0.f, 0.f, 0.f, alpha));
	GroupNameToColor.Add(TEXT("Grey"), FLinearColor(0.26f, 0.26f, 0.26f, alpha));
	GroupNameToColor.Add(TEXT("White"), FLinearColor(1.f, 1.f, 1.f, alpha));
	GroupNameToColor.Add(TEXT("Yellow"), FLinearColor(1.f, 1.f, 0.f, alpha));
	GroupNameToColor.Add(TEXT("Orange"), FLinearColor(1.f, 0.161886f, 0.032147f, alpha));
	GroupNameToColor.Add(TEXT("Magenta"), FLinearColor(1.f, 0.f, 1.f, alpha));
	GroupNameToColor.Add(TEXT("Red"), FLinearColor(1.f, 0.f, 0.f, alpha));
	GroupNameToColor.Add(TEXT("Maroon"), FLinearColor(0.5f, 0.f, 0.f, alpha));
	GroupNameToColor.Add(TEXT("Purple"), FLinearColor(0.5f, 0.f, 0.5f, alpha));
	GroupNameToColor.Add(TEXT("Dark Blue"), FLinearColor(0.f, 0.f, 0.5f, alpha));
	GroupNameToColor.Add(TEXT("Blue"), FLinearColor(0.f, 0.f, 1.f, alpha));
	GroupNameToColor.Add(TEXT("Cyan"), FLinearColor(0.f, 1.f, 1.f, alpha));
	GroupNameToColor.Add(TEXT("Teal"), FLinearColor(0.f, 0.5f, 0.5f, alpha));
	GroupNameToColor.Add(TEXT("Green"), FLinearColor(0.f, 1.f, 0.f, alpha));
	GroupNameToColor.Add(TEXT("Dark Green"), FLinearColor(0.f, 0.5f, 0.f, alpha));
}

void UVH_COTManager::PopulateDataPackages()
{
	const FString dataPackagesPath = UDeveloper_Statics::GetUserAppDataPath() / TEXT("VRTAK") / TEXT("DataPackages");

	// load from database
	FString query = FString::Printf(TEXT("select * from dataPackages"));

	SpatialiteResults results;
	NonSpatialDB->SyncQuery(query, results);
	for (const SpatialiteResult& result : results)
	{
		FString fullPathOnDisk = UDatabase_Spatialite::GetString(TEXT("fullPathOnDisk"), result);
		if (!DataPackages.Contains(fullPathOnDisk))
		{
			UVH_DataPackage* dataPackage = NewObject<UVH_DataPackage>((UObject*)GetTransientPackage(), DataPackageClass);

			dataPackage->FullPathToZipOnDisk = fullPathOnDisk;

			FString name = UDatabase_Spatialite::GetString(TEXT("name"), result);
			dataPackage->Name = name;

			dataPackage->bLoaded = UDatabase_Spatialite::GetBool(TEXT("isLoaded"), result);

			// populate uids and files from db
			dataPackage->PopulateContentsFromDB(NonSpatialDB);

			bool bVisible = UDatabase_Spatialite::GetBool(TEXT("isVisible"), result);
			dataPackage->SetVisibility(bVisible);

			DataPackages.Add(fullPathOnDisk, dataPackage);
		}
	}

	IFileManager& fileManager = IFileManager::Get();

	// load data packages that exist on disk but not in the database
	TArray<FString> dataPackageFilenames;
	fileManager.FindFiles(dataPackageFilenames, *(dataPackagesPath / TEXT("*.zip")), true, false);
	for (const FString& dataPackageFilename : dataPackageFilenames)
	{
		const FString filename = FPaths::GetBaseFilename(dataPackageFilename);
		const FString extension = FPaths::GetExtension(dataPackageFilename);

		FString fullPath = dataPackagesPath / dataPackageFilename;
		if (!DataPackages.Contains(fullPath))
		{
			UVH_DataPackage* dataPackage = NewObject<UVH_DataPackage>((UObject*)GetTransientPackage(), DataPackageClass);
			dataPackage->FullPathToZipOnDisk = fullPath;
			dataPackage->Name = filename;

			// populate uids and files from db
			dataPackage->PopulateContentsFromDB(NonSpatialDB);

			DataPackages.Add(fullPath, dataPackage);
		}
	}

	OnUpdatedDataPackageList.Broadcast();
}

TArray<FString> UVH_COTManager::GetManifestFilenames(const FString& manifestFilepath) const
{
	TArray<FString> filenames;

	FXmlFile xmlFile(manifestFilepath, EConstructMethod::ConstructFromFile);
	if (xmlFile.IsValid())
	{
		if (FXmlNode* contents = xmlFile.GetRootNode()->FindChildNode(TEXT("Contents")))
		{
			TArray<FXmlNode*> entries = contents->GetChildrenNodes();
			for (FXmlNode* entry : entries)
			{
				filenames.Add(entry->GetAttribute(TEXT("zipEntry")));
			}
		}
	}
	else
	{
		UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTManager::GetManifestFilenames | could not load manifest file | %s"), *manifestFilepath)
	}

	return filenames;
}

void UVH_COTManager::NonSpatialDB_Connect()
{
	NonSpatialDB = NewObject<UDatabase_Spatialite>(this);

	// Open db and init tables, if needed
	if (NonSpatialDB->OpenDatabase(FPaths::Combine(UDeveloper_Statics::GetUserAppDataPath(), TEXT("VRTAK"), TEXT("Databases"), TEXT("NonSpatialDB.sqlite")), true))
	{
		// chat
		FString query = TEXT("create table if not exists chats (otherUID string not null, otherName string not null, timestamp datetime not null, message string not null, sending integer not null)");
		NonSpatialDB->SyncQuery(query);

		query = TEXT("create table if not exists chatViews (otherUID string not null primary key, timestamp datetime not null)");
		NonSpatialDB->SyncQuery(query);

		// video
		query = TEXT("create table if not exists videos (address string not null, alias string not null, bufferTime integer not null, ignoreEmbeddedKLV integer not null, networkTimeout integer not null, path string not null, port integer not null, protocol string not null, roverPort integer not null, rtspReliable integer not null, uid string not null)");
		NonSpatialDB->SyncQuery(query);

		// data sync
		query = TEXT("create table if not exists dataSyncs (name string not null, host string not null, port integer not null, clientCertificateName string not null, unique(name, host, port, clientCertificateName))");
		NonSpatialDB->SyncQuery(query);

		// data packages
		query = TEXT("create table if not exists dataPackages (name string not null, fullPathOnDisk string unique not null, isLoaded integer not null, isVisible integer not null)");
		NonSpatialDB->SyncQuery(query);

		query = TEXT("create table if not exists dataPackageContents (fullPathOnDisk string not null, uid string not null, type string not null)");
		NonSpatialDB->SyncQuery(query);

		// attachments
		query = TEXT("create table if not exists attachments (entityUID string not null, fullPathToFile string not null, shouldSend integer not null, shouldShow integer not null)");
		NonSpatialDB->SyncQuery(query);
	}
}

void UVH_COTManager::PopulateDataSyncsFromDB()
{
	if (GetWorld()->GetNetMode() != NM_Client)
	{
		FString query = TEXT("select * from dataSyncs");

		SpatialiteResults results;
		NonSpatialDB->SyncQuery(query, results);

		bool bUpdatedList = false;

		// create datasyncs
		for (const SpatialiteResult& result : results)
		{
			UVH_DataSync* dataSync = nullptr;

			FString name = UDatabase_Spatialite::GetString(TEXT("name"), result);

			if (UVH_DataSync** dataSyncPtr = DataSyncs.Find(name))
			{
				dataSync = *dataSyncPtr;
			}
			else
			{
				dataSync = NewObject<UVH_DataSync>((UObject*)GetTransientPackage(), DataSyncClass);
				dataSync->Name = name;

				DataSyncs.Add(name, dataSync);

				bUpdatedList = true;
			}

			dataSync->ConnectionInfo = NewObject<UVH_COTConnectionInfo>();

			dataSync->ConnectionInfo->Host = UDatabase_Spatialite::GetString(TEXT("host"), result);

			dataSync->ConnectionInfo->Port = UDatabase_Spatialite::GetInteger(TEXT("port"), result);

			dataSync->ConnectionInfo->ClientCertificateName = UDatabase_Spatialite::GetString(TEXT("clientCertificateName"), result);

			dataSync->Sync();

			dataSync->SetSubscribed(true);
		}

		if (bUpdatedList)
		{
			OnUpdatedDataSyncList.Broadcast();
		}
	}
}

// occurs off game thread
void UVH_COTManager::HandleFileUploaded(const FString& responseBody, int32 fileSize, const FString& endpoint, FOnFileUploaded uploadedDelegate)
{
	TSharedRef<TJsonReader<>> jsonReader = TJsonReaderFactory<>::Create(*responseBody);

	TSharedPtr<FJsonObject> jsonObject;
	if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
	{
		FString filename = jsonObject->GetStringField(TEXT("Name"));
		if (!filename.IsEmpty())
		{
			AsyncTask(ENamedThreads::GameThread, [this, responseBody, fileSize, endpoint, uploadedDelegate]()
			{
				if (IsValid(this) || GetClass() == nullptr)
				{
					uploadedDelegate.ExecuteIfBound(responseBody, fileSize, endpoint);
				}
			});
		}
	}
}

atakmap::commoncommo::Commo* UVH_COTManager::GetCommo() const
{
	return Commo;
}

void UVH_COTManager::AddGetCOTBoundingBoxDelegate()
{
	FGetCOTBoundingBox boundingBoxDelegate;
	boundingBoxDelegate.BindLambda([](UVH_COTEvent* cotEvent, FGeodeticCoord2D& northWest, FGeodeticCoord2D& southEast)
	{
		FGeodeticCoord2D geodeticCoordinate = cotEvent->GetPoint().ToGeodeticCoord2D();

		northWest = geodeticCoordinate;
		southEast = geodeticCoordinate;

		FString type = cotEvent->GetAttribute(TEXT("type"));
		if (type.Equals(TEXT("u-rb-a"), ESearchCase::IgnoreCase))
		{
			// range and bearing

			double southLatitude = 180;
			double westLongitude = 180;

			double northLatitude = -180;
			double eastLongitude = -180;

			// base
			double pointLongitude = cotEvent->GetAttribute<double>(TEXT("longitude"));
			double pointLatitude = cotEvent->GetAttribute<double>(TEXT("latitude"));

			westLongitude = FMath::Min<double>(westLongitude, pointLongitude);
			eastLongitude = FMath::Max<double>(eastLongitude, pointLongitude);

			southLatitude = FMath::Min<double>(southLatitude, pointLatitude);
			northLatitude = FMath::Max<double>(northLatitude, pointLatitude);

			// arrow
			double bearing = cotEvent->GetAttribute<double>(TEXT("detail\tbearing\tvalue"));
			double range = cotEvent->GetAttribute<double>(TEXT("detail\trange\tvalue"));
			FGeodeticCoord2D arrowCoord = UVH_GlobeMathStatics::CalculateSurfaceDestination(FGeodeticCoord2D(pointLongitude, pointLatitude), bearing, range);

			westLongitude = FMath::Min<double>(westLongitude, arrowCoord.Longitude);
			eastLongitude = FMath::Max<double>(eastLongitude, arrowCoord.Longitude);

			southLatitude = FMath::Min<double>(southLatitude, arrowCoord.Latitude);
			northLatitude = FMath::Max<double>(northLatitude, arrowCoord.Latitude);

			northWest.Latitude = northLatitude;
			northWest.Longitude = westLongitude;

			southEast.Latitude = southLatitude;
			southEast.Longitude = eastLongitude;

			return true;
		}
		else if (type.Equals(TEXT("u-d-f-m"), ESearchCase::IgnoreCase))
		{
			// telestration

			double southLatitude = 180;
			double westLongitude = 180;

			double northLatitude = -180;
			double eastLongitude = -180;

			TArray<FXmlNode*> links = cotEvent->GetNodes(TEXT("link"));
			for (FXmlNode* link : links)
			{
				FString lineXML = link->GetAttribute(TEXT("line"));

				UVH_COTEvent* lineCOTEvent = NewObject<UVH_COTEvent>();
				if (lineCOTEvent->PopulateFromXML(lineXML))
				{
					TArray<FXmlNode*> lineLinks = lineCOTEvent->GetNodes(TEXT("link"));
					for (FXmlNode* lineLink : lineLinks)
					{
						FGeodeticCoord3D coordinate = UVH_COTStatics::LinkToCoordinate(lineLink);
						
						double pointLongitude = coordinate.Longitude;
						double pointLatitude = coordinate.Latitude;

						westLongitude = FMath::Min<double>(westLongitude, pointLongitude);
						eastLongitude = FMath::Max<double>(eastLongitude, pointLongitude);

						southLatitude = FMath::Min<double>(southLatitude, pointLatitude);
						northLatitude = FMath::Max<double>(northLatitude, pointLatitude);
					}
				}
			}

			northWest.Latitude = northLatitude;
			northWest.Longitude = westLongitude;

			southEast.Latitude = southLatitude;
			southEast.Longitude = eastLongitude;

			return true;
		}
		else if (type.Equals(TEXT("u-d-f"), ESearchCase::IgnoreCase))
		{
			// polyline

			double southLatitude = 180;
			double westLongitude = 180;

			double northLatitude = -180;
			double eastLongitude = -180;

			TArray<FXmlNode*> links = cotEvent->GetNodes(TEXT("link"));
			for (FXmlNode* link : links)
			{
				FGeodeticCoord3D coordinate = UVH_COTStatics::LinkToCoordinate(link);

				double pointLongitude = coordinate.Longitude;
				double pointLatitude = coordinate.Latitude;

				westLongitude = FMath::Min<double>(westLongitude, pointLongitude);
				eastLongitude = FMath::Max<double>(eastLongitude, pointLongitude);

				southLatitude = FMath::Min<double>(southLatitude, pointLatitude);
				northLatitude = FMath::Max<double>(northLatitude, pointLatitude);
			}

			northWest.Latitude = northLatitude;
			northWest.Longitude = westLongitude;

			southEast.Latitude = southLatitude;
			southEast.Longitude = eastLongitude;

			return true;
		}
		else if (type.Equals(TEXT("b-m-r"), ESearchCase::IgnoreCase))
		{
			// route

			double southLatitude = 180;
			double westLongitude = 180;

			double northLatitude = -180;
			double eastLongitude = -180;

			TArray<FXmlNode*> links = cotEvent->GetNodes(TEXT("link"));
			for (FXmlNode* link : links)
			{
				FGeodeticCoord3D coordinate = UVH_COTStatics::LinkToCoordinate(link);

				westLongitude = FMath::Min<double>(westLongitude, coordinate.Longitude);
				eastLongitude = FMath::Max<double>(eastLongitude, coordinate.Longitude);

				southLatitude = FMath::Min<double>(southLatitude, coordinate.Latitude);
				northLatitude = FMath::Max<double>(northLatitude, coordinate.Latitude);
			}

			northWest.Latitude = northLatitude;
			northWest.Longitude = westLongitude;

			southEast.Latitude = southLatitude;
			southEast.Longitude = eastLongitude;

			return true;
		}
		else if (type.Equals(TEXT("u-d-c-c"), ESearchCase::IgnoreCase))
		{
			// circle
			double maxRadiusMeters = 0;

			// get the greatest maximum radius of any ellipse, then multiply by the number of ellipses
			TArray<FXmlNode*> ellipseNodes = cotEvent->GetNodes(TEXT("detail\tshape\tellipse"));
			for (FXmlNode* ellipseNode : ellipseNodes)
			{
				double minor = FCString::Atod(*ellipseNode->GetAttribute(TEXT("minor")));
				double major = FCString::Atod(*ellipseNode->GetAttribute(TEXT("major")));

				maxRadiusMeters = FMath::Max<double>(maxRadiusMeters, FMath::Max<double>(minor, major));
			}

			// make a bounding box for a circle of the maximum radius
			FGeodeticCoord2D north = UVH_GlobeMathStatics::CalculateSurfaceDestination(geodeticCoordinate, 0, maxRadiusMeters);
			FGeodeticCoord2D east = UVH_GlobeMathStatics::CalculateSurfaceDestination(geodeticCoordinate, 90, maxRadiusMeters);
			FGeodeticCoord2D south = UVH_GlobeMathStatics::CalculateSurfaceDestination(geodeticCoordinate, 180, maxRadiusMeters);
			FGeodeticCoord2D west = UVH_GlobeMathStatics::CalculateSurfaceDestination(geodeticCoordinate, 270, maxRadiusMeters);

			northWest.Longitude = west.Longitude;
			northWest.Latitude = north.Latitude;

			southEast.Longitude = east.Longitude;
			southEast.Latitude = south.Latitude;

			UE_LOG(LogTemp, Warning, TEXT("-- nw: %s | se: %s"), *northWest.ToString(), *southEast.ToString());

			return true;
		}
		else if (type.Equals(TEXT("u-d-r"), ESearchCase::IgnoreCase))
		{
			// rectangle

			double southLatitude = 180;
			double westLongitude = 180;

			double northLatitude = -180;
			double eastLongitude = -180;

			TArray<FXmlNode*> links = cotEvent->GetNodes(TEXT("link"));
			for (FXmlNode* link : links)
			{
				FGeodeticCoord3D coordinate = UVH_COTStatics::LinkToCoordinate(link);

				westLongitude = FMath::Min<double>(westLongitude, coordinate.Longitude);
				eastLongitude = FMath::Max<double>(eastLongitude, coordinate.Longitude);

				southLatitude = FMath::Min<double>(southLatitude, coordinate.Latitude);
				northLatitude = FMath::Max<double>(northLatitude, coordinate.Latitude);
			}

			northWest.Latitude = northLatitude;
			northWest.Longitude = westLongitude;

			southEast.Latitude = southLatitude;
			southEast.Longitude = eastLongitude;

			return true;
		}

		return false;
	});

	COTBoundingBoxLambdas.Add(boundingBoxDelegate);
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UVH_COTManager::HandleReceivedConnectionError(UVH_COTConnectionInfo* connectionInfo)
{
	OnReceivedConnectionError.Broadcast(connectionInfo);
}

void UVH_COTManager::HandleReceivedConnectionStatusUpdate(UVH_COTConnectionInfo* connectionInfo)
{
	UE_LOG(VH_COT, Warning, TEXT("-- status of %s: %s"), *connectionInfo->DisplayName, connectionInfo->bConnected ? TEXT("connected") : TEXT("disconnected"));

	OnReceivedConnectionStatusUpdate.Broadcast(connectionInfo);
}