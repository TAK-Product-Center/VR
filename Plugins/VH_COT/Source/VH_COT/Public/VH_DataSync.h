#pragma once

// Parent Includes
#include "VH_DataPackageBase.h"

// Engine Includes
#include "Misc/DateTime.h"

// Generated Includes
#include "VH_DataSync.generated.h"

class UVH_COTConnectionInfo;
class UVH_COTEvent;

UENUM(BlueprintType)
enum class EDataSyncSort : uint8
{
    EDS_Name,
    EDS_Status,
	EDS_None
};

UCLASS(Blueprintable, BlueprintType)
class VH_COT_API UVH_DataSync : public UVH_DataPackageBase
{
	GENERATED_BODY()


    // ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FKeywordsUpdated, const TArray<FString>&, keywords);

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEntityKeywordsUpdated, const FString&, entityUID, const TArray<FString>&, keywords);

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAddCOTToTAKServer, UVH_DataSync*, dataSync, const FString&, entityUID);


    // ---------------------------------
	// --- Variables
	// ---------------------------------

   public:
    UPROPERTY(BlueprintAssignable)
    FKeywordsUpdated OnKeywordsUpdated;

    UPROPERTY(BlueprintAssignable)
    FEntityKeywordsUpdated OnEntityKeywordsUpdated;

    UPROPERTY(BlueprintAssignable)
    FAddCOTToTAKServer OnAddCOTToTAKServer;

    UPROPERTY(BlueprintReadWrite)
    FString Description;

	UPROPERTY(BlueprintReadWrite)
	FDateTime CreateTime;

    UPROPERTY(BlueprintReadOnly)
    UVH_COTConnectionInfo* ConnectionInfo;

	/** Stores events related to the data sync.  May be able to replace UpdateHistory.  This data type should be re-evaluated if searching/sorting is on the menu */
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> ChangeLogs;

	TArray<FString> UnknownUIDs;

protected:
    TMap<FString, FString> FileToHash;

private:
    TArray<FString> Keywords;

	TMap<FString, TArray<FString>> EntityKeywords;

	int32 LastLogCount;

    bool bSubscribed;

	// creator UID, update time
	TArray<TPair<FString, FDateTime>> UpdateHistory;

    FCriticalSection EntityKeywordsCritSection;


    // ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UVH_DataSync();


    // ---------------------------------
	// --- API
	// ---------------------------------

public:
    UFUNCTION(BlueprintCallable)
    virtual void Unload();

    UFUNCTION(BlueprintCallable)
    void SetSubscribed(bool bSubscribe);

    UFUNCTION(BlueprintPure)
    bool IsSubscribed() const;

    UFUNCTION(BlueprintCallable)
    void Sync();

    UFUNCTION(BlueprintCallable)
    void SendToTAKServer();

    UFUNCTION(BlueprintCallable)
    void RemoveFromTAKServer();

    UFUNCTION(BlueprintCallable)
    void AddFileToTAKServer(const FString& fullPathToFile);

    UFUNCTION(BlueprintCallable)
    void AddCOTToTAKServer(const FString& uid);

    UFUNCTION(BlueprintCallable)
    void RemoveContentFromTAKServer(const FString& uid);

    UFUNCTION(BlueprintCallable)
    TArray<FString> GetKeywords() const;

    UFUNCTION(BlueprintCallable)
    void SetKeywords(const TArray<FString>& keywords);

	void SetKeywordsFromTAKServer(const TArray<FString>& keywords);

    UFUNCTION(BlueprintPure)
	TArray<FString> GetEntityKeywords(const FString& entityUID) const;

	UFUNCTION(BlueprintCallable)
	void SetEntityKeywords(const FString& entityUID, const TArray<FString>& keywords);

    UFUNCTION(BlueprintCallable)
    void SendKeywordsToTAKServer();

	/**
	 * Uses a REST API to request a list of changes associated with this data sync.  When successful, will call ChangesReceived()
	 */
	 UFUNCTION(BlueprintCallable)
	void RequestChanges();

    UFUNCTION(BlueprintCallable)
    void RequestEntityKeywords();

	virtual void ChangesReceived();

    virtual void RemoveFile(const FString& fullPathToFile) override;

    virtual void RemoveContent() override;

    void HandleUpdate(UVH_COTEvent* cotEvent);

	void AddUpdateHistory(const FString& contactUID, const FDateTime& timestamp);

	UFUNCTION(BlueprintPure)
	FDateTime GetLastUpdate() const;


    // ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	virtual void RegisterFile(const FString& fullPathToFile);

    virtual void Notify(const FString& message, float duration) const;

    virtual bool IsFileRegistered(const FString& fullPathToFile) const;

	virtual void DeleteFromDatabase(const FString& entityUID, const FString& classUID);

private:
    void Sync_COTRequestCompleted(const TArray<uint8>& data);

    void Sync_FileRequestCompleted(const TArray<uint8>& data, const FString& filename);

    void Sync_DataRequestCompleted(const TArray<uint8>& data);

    void Sync_GetChangesRequestCompleted(const TArray<uint8>& data);

    void Sync_GetKeywords(const TArray<uint8>& data);
    
    void HandleAddedFileUploaded(const FString& responseBody, int32 fileSize, const FString& endpoint);

	UFUNCTION()
	void HandleContactsUpdated();
};