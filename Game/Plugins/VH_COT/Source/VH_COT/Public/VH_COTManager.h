#pragma once

#include "netinterface.h"
#include <sstream>
#include <ios>

// Engine Includes
#include "Tickable.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "Misc/DateTime.h"
#include "HAL/ThreadSafeBool.h"
#include "Misc/Timespan.h"
#include "Misc/Guid.h"
#include "Http.h"
#include "UnrealEngine.h"
#include "Engine/GameViewportClient.h"

// Module Includes
#include "VH_COT.h"
#include "VH_COTEvent.h"
#include "VH_GeodeticCoord.h"
#include "VH_DataSync.h"
#include "VH_COTDetail_Video.h"

// Generated Includes
#include "VH_COTManager.generated.h"

class FXmlNode;
class CoTListener;
class UVH_COTPoint;
class UVH_COTUserIcons;
class UDatabase_Spatialite;
class UVH_COTChat;
class UVH_COTConnectionInfo;

namespace atakmap
{
    namespace commoncommo
    {
        class Commo;
        class StreamingNetInterface;
        class NetInterface;
    }  // namespace commoncommo
}  // namespace atakmap

// ---------------------------------
// --- Utilities
// ---------------------------------

namespace vh_cot
{
    inline UWorld* GetWorld()
    {
        if (GEngine != nullptr && GEngine->GameViewport != nullptr)
        {
            return GEngine->GameViewport->GetWorld();
        }

        return nullptr;
    }

    inline FString GenerateCallsign(UVH_COTEvent* cotEvent)
    {
        FString type = cotEvent->GetAttribute(TEXT("type"));

        FString prefix = TEXT("");
        if (type.StartsWith(TEXT("a-h"), ESearchCase::IgnoreCase))
        {
            prefix = TEXT("TGT");
        }
        else if (type.StartsWith(TEXT("a-f"), ESearchCase::IgnoreCase))
        {
            prefix = TEXT("F");
        }
        else if (type.StartsWith(TEXT("a-u"), ESearchCase::IgnoreCase))
        {
            prefix = TEXT("U");
        }
        else if (type.StartsWith(TEXT("a-n"), ESearchCase::IgnoreCase))
        {
            prefix = TEXT("N");
        }
        else if (type.StartsWith(TEXT("b-m-p-s-m"), ESearchCase::IgnoreCase))
        {
            prefix = TEXT("S");
        }
        else if (type.StartsWith(TEXT("b-r-f-h-c"), ESearchCase::IgnoreCase))
        {
            prefix = TEXT("MED");
        }

        FDateTime date = FDateTime::Now();

        FString hour = FString::Printf(TEXT("%d"), date.GetHour());
        FString minute = FString::Printf(TEXT("%d"), date.GetMinute());
        FString second = FString::Printf(TEXT("%d"), date.GetSecond());

        if (hour.Len() == 1)
        {
            hour = FString::Printf(TEXT("0%s"), *hour);
        }

        if (minute.Len() == 1)
        {
            minute = FString::Printf(TEXT("0%s"), *minute);
        }

        if (second.Len() == 1)
        {
            second = FString::Printf(TEXT("0%s"), *second);
        }

        return FString::Printf(TEXT("%s.%s.%s%s"), *prefix, *hour, *minute, *second);
    }

    // converts FDateTime to ISO 8601 (2019-01-31T22:03:33Z)
    inline FString GetISOTime(const FDateTime& dateTime)
    {
		return dateTime.ToIso8601();
    }

    // converts ISO 8601 (2019-01-31T22:03:33Z) to FDateTime
    inline FDateTime GetDateTime(const FString& cotTime)
    {
		FDateTime dateTime;
		FDateTime::ParseIso8601(*cotTime, dateTime);

		return dateTime;
    }

    // converts string bytes from UTF16 to UTF8
    inline FString ConvertFromCommoString(const FString& commoString)
    {
        FString updatedString = TEXT("");
        for (auto i = 0; i < commoString.Len(); i++)
        {
            updatedString.AppendChar(commoString[i] - 1);
        }

        return updatedString;
    }

    // converts string bytes from UTF8 to UTF16
    inline FString ConvertFromUE4String(const FString& ue4String)
    {
        FString updatedString = TEXT("");
        for (auto i = 0; i < ue4String.Len(); i++)
        {
            updatedString.AppendChar(ue4String[i] + 1);
        }

        return updatedString;
    }

    // converts FString to TArray<BYTE>
    inline TArray<BYTE> ConvertStringToBytes(const FString& string)
    {
        auto numBytes = string.Len() * sizeof(TCHAR);
        TArray<BYTE> byteArray;
        byteArray.AddZeroed(numBytes);
        StringToBytes(string, byteArray.GetData(), numBytes);

        return byteArray;
    }
}  // namespace vh_cot

// ---------------------------------
// --- Structs
// ---------------------------------

USTRUCT(BlueprintType)
struct FVideoDetails
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    UVH_COTDetail_Video* VideoDetail;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    FString Name;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    FString URL;

    FVideoDetails() : VideoDetail()
    {
		VideoDetail = nullptr;
		Name = TEXT("");
		URL = TEXT("");
	}

    FVideoDetails(UVH_COTDetail_Video* videoDetail) : VideoDetail(videoDetail)
    {
		if (VideoDetail != nullptr)
		{
			Name = VideoDetail->Alias;
			URL = VideoDetail->GetVideoURL();
		}
	}
};

USTRUCT(BlueprintType)
struct FSDataPackageInfo
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    UVH_COTConnectionInfo* ConnectionInfo;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    TMap<FString, FString> KeyValues;

	FSDataPackageInfo()
	{
		ConnectionInfo = nullptr;
	}
};

DECLARE_DELEGATE_ThreeParams(FOnFileUploaded, const FString&, int32, const FString&);

USTRUCT()
struct FUploadedFile
{
    GENERATED_BODY();

    FString ResponseBody;

    int32 FileSize;

    FString Endpoint;

    FOnFileUploaded UploadedDelegate;
};

USTRUCT(BlueprintType)
struct FCOTTypeData
{
	GENERATED_BODY()

	/* blueprint to spawn when receiving this cot type, must implement Interface_COTReceiver */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> ActorClass;
};

UCLASS(Blueprintable, BlueprintType, Config = VH_COT)
class VH_COT_API UVH_COTManager : public UObject, public FTickableGameObject
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UVH_COTManager();


	// ---------------------------------
	// --- Friend Classes
	// ---------------------------------

public:
    friend class CommoListener;
    friend class UVH_DataPackage;
    friend class UVH_DataSync;
	friend class UVH_COTConnectionInfo;


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

public:
	DECLARE_DELEGATE_RetVal_ThreeParams(bool, FGetCOTBoundingBox, UVH_COTEvent*, FGeodeticCoord2D&, FGeodeticCoord2D&);
	DECLARE_DELEGATE_RetVal_OneParam(bool, FPreHandleCOTEvent, UVH_COTEvent*);

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReceivedDataPackage);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpdateContacts);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpdateDataSyncList);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpdatedDataPackageList);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpdatedVideoList);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPostHandleCOTEvent, UVH_COTEvent*, cotEvent);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReceivedConnectionError, UVH_COTConnectionInfo*, connectionInfo);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReceivedConnectionStatusUpdate, UVH_COTConnectionInfo*, connectionInfo);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReceivedDataPackageQuery, const TArray<FSDataPackageInfo>&, dataPackageInfos);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReceivedVideoDetails, const TArray<FVideoDetails>&, videoDetails);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUpdatedCallsign, const FString&, callsign);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FViewedChat, const FName&, otherUID);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FReceivedChat, const FName&, otherUID, UVH_COTChat*, chat);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAttachmentsModified, const FString&, entityUID);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	TArray<FGetCOTBoundingBox> COTBoundingBoxLambdas;

	UPROPERTY(BlueprintAssignable)
	FPostHandleCOTEvent OnPostHandleCOTEvent;

	UPROPERTY(BlueprintAssignable)
	FReceivedChat OnReceivedChat;

	UPROPERTY(BlueprintAssignable)
	FReceivedConnectionError OnReceivedConnectionError;

	UPROPERTY(BlueprintAssignable)
	FReceivedConnectionStatusUpdate OnReceivedConnectionStatusUpdate;

	UPROPERTY(BlueprintAssignable)
	FReceivedDataPackage OnReceivedDataPackage;

	UPROPERTY(BlueprintAssignable)
	FReceivedDataPackageQuery OnReceivedDataPackageQuery;

	UPROPERTY(BlueprintAssignable)
	FReceivedVideoDetails OnReceivedVideoDetails;

	UPROPERTY(BlueprintAssignable)
	FUpdatedCallsign OnUpdatedCallsign;

	UPROPERTY(BlueprintAssignable)
	FUpdateContacts OnUpdateContacts;

	UPROPERTY(BlueprintAssignable)
	FUpdateDataSyncList OnUpdatedDataSyncList;

	UPROPERTY(BlueprintAssignable)
	FUpdatedDataPackageList OnUpdatedDataPackageList;

	UPROPERTY(BlueprintAssignable)
	FUpdatedVideoList OnUpdatedVideoList;

	UPROPERTY(BlueprintAssignable)
	FViewedChat OnViewedChat;

	UPROPERTY(BlueprintAssignable)
	FAttachmentsModified OnAttachmentsModified;

    /*
	* \brief Maps COT type to data for spawning; wildcard (*) accepted, matches without wildcard take precedence
	*/
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FString, FCOTTypeData> TypeToData;

	// key is type, value is category name
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    TMap<FString, FName> OverlayCategories;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bBroadcastGhost;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bShowInformationLogs;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<class UVH_COTUserIcons> UserIconsClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<class UVH_DataSync> DataSyncClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TSubclassOf<class UVH_DataPackage> DataPackageClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FString, UTexture2D*> GroupRoles;

protected:
	FString Callsign;

	float HeartbeatCounter;

	// stored here for fast queries; also stored in database
	UPROPERTY()
	TMap<FName, UVH_COTEvent*> Contacts;

	TSet<FName> PotentialContacts;

	FName UID;

	static UVH_COTManager* GlobalInstance;

	FGeodeticCoord3D HeartbeatCoordinate;

private:
	TMap<FName, FPreHandleCOTEvent> PreHandleCOTEventDelegateMap;

	UPROPERTY()
	TArray<UVH_COTConnectionInfo*> ConnectionInfos;

	UPROPERTY()
	UDatabase_Spatialite* NonSpatialDB;

	UPROPERTY()
	TArray<UVH_COTDetail_Video*> Videos;

	// maps data package name to data package object
	UPROPERTY()
	TMap<FString, UVH_DataPackage*> DataPackages;

	UPROPERTY()
	TMap<FString, UVH_DataSync*> DataSyncs;

	UPROPERTY()
	FTimerHandle StoreConnectionsTimerHandle;

	TArray<FVideoDetails> VideoDetails;

	TArray<TSharedRef<IHttpRequest, ESPMode::ThreadSafe>> VideoListRequests;

	int32 MaxCOTsPerTick;

	FName GroupName;
	FName GroupRole;
	FName UIDGhost;

	FThreadSafeBool bEnabled;

	UPROPERTY()
	UVH_COTUserIcons* UserIcons;

	mutable FCriticalSection COTReceivedCritSection;

	FCriticalSection ShutdownCritSection;

	UPROPERTY()
	TArray<UVH_COTEvent*> QueuedEvents;

	UPROPERTY()
	TMap<FName, FLinearColor> GroupNameToColor;

	atakmap::commoncommo::Commo* Commo;

	CommoListener* CommoListenerInstance;


	// ---------------------------------
	// --- FTickableObjectBase
	// ---------------------------------

public:
	virtual TStatId GetStatId() const override;

	virtual bool IsTickable() const override;

	virtual void Tick(float deltaSeconds) override;


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure)
	static const FString GetDataLoader_COT_ClassUID();

	UFUNCTION(BlueprintPure)
	static const FString GetDataLoader_File_ClassUID();

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get COT Manager"))
	static UVH_COTManager* Get();

	static UVH_COTManager* Create(AActor* outer, TSubclassOf<class UVH_COTManager> managerClass);

	static bool IsVTAKGhost(UVH_COTEvent* cotEvent);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginDestroy() override;

	virtual UWorld* GetWorld() const override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
    bool Initialize();

	UFUNCTION(BlueprintCallable)
	void HandleCotMessageReceived(const FString& cotMessage, const FString& rxIfaceEndpointId);

    bool ShouldHandleAtomCOT(UVH_COTEvent* cotEvent) const;

    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> CreateRESTRequest(const FString& commoInterfaceEndpoint, const FString& url, const FString& verb = TEXT("GET"), const FString& mimeType = TEXT("application/x-www-form-urlencoded")) const;

    bool UploadFileToTAKServer(const FString& commoInterfaceEndpoint, const FString& url, const FString& fullPathOnDisk, FOnFileUploaded uploadedDelegate);

    /*
	* \brief Immediately handles cot event on game thread (i.e. spawns associated actors, etc)
	* \param cotEvent UVH_COTEvent to handle
	*/
    UFUNCTION(BlueprintCallable)
    virtual void HandleCOTEvent(UVH_COTEvent* cotEvent);

    /*
	* \brief Adds cot event to queue that is handled on game thread next tick
	* \param cotEvent UVH_COTEvent to handle
	*/
    void AddReceivedCOT(UVH_COTEvent* cotEvent);

	virtual void Notify(const FString& message, float duration) const;

	UFUNCTION(BlueprintCallable)
    void DownloadDataPackageFromTAKServer(UVH_COTConnectionInfo* connectionInfo, const FString& filename, const FString& hash);

    UFUNCTION(BlueprintCallable)
    bool SendCOT(const TArray<FName>& contactUIDs, const FString& cotMessage);

    UFUNCTION(BlueprintCallable)
    UVH_COTChat* SendGeochatEvent(const FName& contactUID, const FString& message);

    /*
	 * \brief sends COT to all known contacts
	 * \param cotMessage XML to send (use UVH_COTEvent::ToXML())
	 * \return true if COT was successfully sent
	*/
    UFUNCTION(BlueprintCallable)
    bool BroadcastCOT(const FString& cotMessage);

    /* store ConnectionInfos to xml on local disk */
    UFUNCTION(BlueprintCallable)
    void StoreConnectionInfos();

    /* loads ConnectionInfos from xml; replaces current ConnectionInfos array */
    UFUNCTION(BlueprintCallable)
    void LoadConnectionInfos();

	/* Attempts to add a new connection to the ConnectionInfos array. If connection exists, delete original connection from array 
	 * and add a new one with updated properties. 
	 * 
	 * @param connectionInfo Pointer to a UVH_COTConnectionInfo object with new connection or updated connection properties. 
	 * @return True if success. 
	 */
	UFUNCTION(BlueprintCallable)
	bool AddOrUpdateConnection(UVH_COTConnectionInfo* connectionObject);

	/* Finds and attempts to remove a connection from ConnectionInfos array, disconnecting if necessary. 
	 *
	 * @param connectionInfoToBeRemoved Connection to be removed. Uses connections' RootDirectory as a means of comparison.
	 * @param bDeleteRootDirectory optional parameter that determines whether the root directory should also be deleted. In cases where a connection just needs to be 
	 *        updated, this should be false to avoid having to recreate the root directory.
	 * @return True if success.
	 */
	UFUNCTION(BlueprintCallable)
	bool RemoveConnection(UVH_COTConnectionInfo* connectionInfoToBeRemoved, bool bDeleteRootDirectory = true);

    UFUNCTION(BlueprintCallable)
    void AddVideo(UVH_COTDetail_Video* cotVideo);

    UFUNCTION(BlueprintCallable)
    void RemoveVideo(UVH_COTDetail_Video* cotVideo);

    /* populates DataSyncs array from local db and from connected servers */
    UFUNCTION(BlueprintCallable)
    void PopulateDataSyncsFromTAKServer();

	UFUNCTION(BlueprintPure)
	TArray<UVH_COTConnectionInfo*> GetConnectionInfos() const;

	UFUNCTION(BlueprintPure)
	bool IsConnectedToTAKServer() const;

	UFUNCTION(BlueprintPure)
	UVH_COTUserIcons* GetUserIcons() const;

	UFUNCTION(BlueprintPure)
	FName GetSelfUID() const;

	UFUNCTION(BlueprintPure)
	FName GetGroupName() const;

	UFUNCTION(BluePrintPure)
	FName GetGroupRole() const;

	UFUNCTION(BlueprintPure)
	TArray<UVH_COTDetail_Video*> GetVideos() const;

    UFUNCTION(BlueprintCallable)
    TArray<UVH_DataPackage*> GetDataPackages() const;

	UFUNCTION(BlueprintPure)
	UVH_DataPackage* GetDataPackage(const FString& name) const;

    UFUNCTION(BlueprintCallable)
    UVH_DataPackage* AddDataPackage(const FString& name);

    UFUNCTION(BlueprintCallable)
    void RemoveDataPackage(const FString& fullPathOnDisk);

    UFUNCTION(BlueprintCallable)
    UVH_DataSync* AddDataSync(const FString& name, UVH_COTConnectionInfo* connectionInfo = nullptr, bool bNotify = true);

    UFUNCTION(BlueprintCallable)
    void RemoveDataSync(UVH_DataSync* dataSync, bool bUnload);

	UFUNCTION(BlueprintCallable)
	TArray<UVH_DataSync*> GetSortedDataSyncs(EDataSyncSort sortType = EDataSyncSort::EDS_Name, const FString& filter = TEXT("")) const;

	UFUNCTION(BlueprintCallable)
	UVH_DataSync* GetDataSync(const FString& name) const;

    UFUNCTION(BlueprintCallable)
    bool AddColorToGroupColorMap(FName colorName, FLinearColor groupColor);

    UFUNCTION(BlueprintPure)
    bool GetGroupColor(FName colorName, FLinearColor& groupColor);

    UFUNCTION(BlueprintPure)
    TMap<FName, FLinearColor> GetGroupColors();

    UFUNCTION(BlueprintPure)
    TArray<UVH_COTChat*> GetChatsWith(const FName& uid, bool bUpdateChatsViewedTime = false);

    UFUNCTION(BlueprintPure)
    int32 GetNumberOfNewChats(const FName& uid) const;

    UFUNCTION(BlueprintCallable)
    void UpdateChatViewedTime(const FName& uid);

	UFUNCTION(BlueprintCallable)
    void BroadcastHeartbeat();

	UFUNCTION(BlueprintPure)
	virtual UVH_COTEvent* GetCotEventFromUID(const FString& entityUID) const;

    UFUNCTION(BlueprintCallable)
    void QueryServerForDataPackages(UVH_COTConnectionInfo* connectionInfo);

    UFUNCTION(BlueprintPure)
    FName GetOverlayCategory(UVH_COTEvent* cotEvent) const;

	/* Return a copy of entire list of contacts in whatever order they are currently in.  Key of the returned TMap is UID of contact */
	UFUNCTION(BlueprintPure)
	TMap<FName, UVH_COTEvent*> GetContacts() const;

	UFUNCTION(BlueprintCallable)
	void GetVideoList();

	UFUNCTION(BlueprintCallable)
	void PopulateVideos();

	UFUNCTION(BlueprintCallable)
	virtual FGeodeticCoord3D GetGeodeticLocation() const;

	UFUNCTION(BlueprintImplementableEvent)
	void GetLDAPCredentials(UVH_COTConnectionInfo* connectionInfo);

	UFUNCTION(BlueprintPure)
	FString GetCallsign() const;

	UFUNCTION(BlueprintCallable)
	void SetCallsign(const FString& inCallsign);

	UFUNCTION(BlueprintPure)
	bool IsContact(const FString& entityUID) const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	TArray<FString> GetRoles() const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	TArray<UVH_COTEvent*> GetContactsInRole(const FString& role) const;

	void GetTypeData(const FString& type, FCOTTypeData& typeData) const;

	void GetCOTCoordinates(UVH_COTEvent* cotEvent, FGeodeticCoord2D& northWest, FGeodeticCoord2D& southEast) const;

	AActor* SpawnActorFromType(const FString& type) const;

	FName AddPreHandleCOTEventDelegate(FPreHandleCOTEvent eventDelegate);

	bool RemovePreHandleCOTEventDelegate(FName uid);

	UFUNCTION(BlueprintCallable)
	void SetAttachedFile(const FString& entityUID, const FString& fullPathToFile, bool bShouldSend);

	UFUNCTION(BlueprintCallable)
	void RemoveAttachedFiles(const FString& entityUID, const FString& fullPathToFile);

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	FSpatialiteResults_BP GetAttachedFiles(const FString& entityUID) const;

	UTexture2D* GetAttachmentTexture(const FString& entityUID, FVector2D& dimensions) const;

	UFUNCTION(BlueprintCallable)
	void SetShouldShowAttachment(const FString& entityUID, const FString& fullPathToFile, bool bShow);

	// loads data package files (that the COTManager can ingest) into current map
	bool LoadDataPackageFromDisk(FString fullPathToZipFile, bool bForceImport = false);

	UFUNCTION(BlueprintCallable)
	virtual void SetHeartbeatCoordinate(const FGeodeticCoord3D& coordinate);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	/* returns all actors associated with an entity uid */
	UFUNCTION(BlueprintPure)
	virtual TSet<AActor*> GetActorsForEntity(const FString& entityUID) const;

	virtual void StoreSettings() const;

	virtual void LoadSettings();

	AActor* SpawnActor(UVH_COTEvent* cotEvent) const;

	virtual void HandleAtomEvent_Virtual(UVH_COTEvent* cotEvent);

	virtual bool HandleDataPackageEvent(UVH_COTEvent* cotEvent);

	virtual void RegisterFile(const FString& fullPathToFile) { }

private:
    virtual float GetHeartbeatCooldown() const;

	virtual bool PostInitialize();

	virtual bool ShouldHandleAtomCOT_Virtual(UVH_COTEvent* cotEvent) const;

	virtual void PostHandleCOTEvent_Virtual(UVH_COTEvent* cotEvent);

    void Cleanup();

    void HandleInterfaceStatusUpdate(atakmap::commoncommo::NetInterface* interface, bool bConnected);

    void HandleInterfaceError(atakmap::commoncommo::NetInterface* interface, atakmap::commoncommo::netinterfaceenums::NetInterfaceErrorCode error);

    virtual void HandleAtomEvent(UVH_COTEvent* cotEvent);

    bool HandleGeochatEvent(UVH_COTEvent* cotEvent);

    bool HandleVideoEvent(UVH_COTEvent* cotEvent);

    void HandleContactUpdated(const FName& uid, bool bAdded);

	bool GetBlueprintToSpawn(const FString& type, TSubclassOf<class AActor>& actorClass) const;

    void InitializeColors();

    void InitializeRoles();

    // populates DataPackages array based on zip files found in Data\Dynamic\DataPackages
    void PopulateDataPackages();

    TArray<FString> GetManifestFilenames(const FString& manifestFilepath) const;

    void NonSpatialDB_Connect();

    void PopulateDataSyncsFromDB();

    void HandleFileUploaded(const FString& responseBody, int32 fileSize, const FString& endpoint, FOnFileUploaded uploadedDelegate);

	atakmap::commoncommo::Commo* GetCommo() const;

	void AddGetCOTBoundingBoxDelegate();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleReceivedConnectionError(UVH_COTConnectionInfo* connectionInfo);

	UFUNCTION()
	void HandleReceivedConnectionStatusUpdate(UVH_COTConnectionInfo* connectionInfo);
};
