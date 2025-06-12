#pragma once

// Parent Includes
#include "VH_DataPackageBase.h"

// Generated Includes
#include "VH_DataPackage.generated.h"

class UVH_COTConnectionInfo;
class UDatabase_Spatialite;

UCLASS(Blueprintable, BlueprintType)
class VH_COT_API UVH_DataPackage : public UVH_DataPackageBase
{
    GENERATED_BODY()

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
    UPROPERTY(BlueprintReadOnly)
    FString FullPathToZipOnDisk;

    UPROPERTY(BlueprintReadOnly, EditAnywhere)
    bool bVisible;

    // true if COTManager has loaded this data package
    UPROPERTY(BlueprintReadOnly)
    bool bLoaded;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
    UVH_DataPackage();


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	virtual void AddUID(const FString& uid) override;

	virtual void RemoveUID(const FString& uid) override;

	virtual void AddFile(const FString& fullPathToFile) override;

	virtual void RemoveFile(const FString& fullPathToFile) override;

	virtual void RemoveContent() override;

	// imports mission package, ignores onReceiveImport from data package manifest.xml
	void Load();

	UFUNCTION(BlueprintCallable)
	virtual void SetVisibility(bool bVisibleArg);

	void UpdateContents(const FString& fullPathOnDisk);

	void PopulateContentsFromDB(UDatabase_Spatialite* db);

	UFUNCTION(BlueprintCallable)
	void Broadcast(const FString& fullPathToZip);

    UFUNCTION(BlueprintCallable)
    void Send(const TArray<FName>& contactUIDs, const FString& fullPathToZip);

    UFUNCTION(BlueprintCallable)
    void SendToTAKServer(const FString& fullPathToZip, UVH_COTConnectionInfo* connectionInfo, bool bPublic);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
    void HandleFileUploaded(const FString& responseBody, int32 fileSize, const FString& endpoint);
};