#pragma once

#include "VH_COT.h"
#include "VH_DataPackageBase.generated.h"

class UVH_COTConnectionInfo;
class UDatabase_Spatialite;

USTRUCT()
struct FSSendInfo
{
    GENERATED_BODY();

    TArray<FName> ContactUIDs;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpdateContent);

UCLASS(Blueprintable, BlueprintType)
class VH_COT_API UVH_DataPackageBase : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable)
    FUpdateContent OnUpdateContent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString Name;

    UVH_DataPackageBase();

    UFUNCTION(BlueprintCallable)
    virtual void AddUID(const FString& uid);

    UFUNCTION(BlueprintCallable)
    virtual void AddFile(const FString& fullPathToFile);

    UFUNCTION(BlueprintCallable)
    virtual void RemoveUID(const FString& uid);

    UFUNCTION(BlueprintCallable)
    virtual void RemoveFile(const FString& fullPathToFile);

    UFUNCTION(BlueprintCallable)
    virtual void RemoveContent();

    UFUNCTION(BlueprintPure)
    TArray<FString> GetUIDs() const { return UIDs; }

    UFUNCTION(BlueprintPure)
    TArray<FString> GetFiles() const { return Files; }

    UFUNCTION(BlueprintCallable)
    FString CreateZipFile(const FString& fullPathToFile = TEXT(""));

protected:
    TMap<UVH_COTConnectionInfo*, FSSendInfo> PendingSendInfo;

    // array of COTManager UIDs in this data package
    TArray<FString> UIDs;

    // array of full path on disk for files in this data package
    TArray<FString> Files;
};