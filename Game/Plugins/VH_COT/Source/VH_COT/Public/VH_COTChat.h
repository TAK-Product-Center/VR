#pragma once

#include "VH_COT.h"
#include "Database_Spatialite.h"
#include "VH_COTChat.generated.h"

UCLASS(Blueprintable, BlueprintType)
class VH_COT_API UVH_COTChat : public UObject
{
    GENERATED_BODY()

public:
    UVH_COTChat();

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString Message;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FDateTime Timestamp;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString OtherCallsign;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName OtherUID;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bSending;

    void AddToDatabase(UDatabase_Spatialite* database) const;

    void PopulateFromDB(const SpatialiteResult& result);
};