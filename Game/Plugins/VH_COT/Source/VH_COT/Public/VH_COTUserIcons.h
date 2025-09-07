#pragma once

// Parent Includes
#include "UObject/Object.h"

// Engine Includes
#include "GameFramework/Actor.h"

// Generated Includes
#include "VH_COTUserIcons.generated.h"

class UDatabase_Spatialite;

UCLASS(Blueprintable, BlueprintType)
class VH_COT_API UVH_COTUserIcons : public UObject
{
    GENERATED_BODY()

public:
    /* relative path (from FPaths::RootDir()) to sqlite icon database */
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString PathToIconDB;

    /* map userIcon path to actor representative blueprint */
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FString, TSubclassOf<class AActor>> PathToBlueprint;

    /* map model to actor representative blueprint */
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FString, TSubclassOf<class AActor>> ModelToBlueprint;

    UVH_COTUserIcons();

    void Initialize();

    UFUNCTION(BlueprintPure)
    UTexture2D* GetIcon(const FString& iconSetPath);

    UFUNCTION()
    virtual void BeginDestroy() override;

private:
    UPROPERTY()
    TMap<FString, UTexture2D*> PathToIcon;

    UPROPERTY()
    UDatabase_Spatialite* IconDB;

    bool bDatabaseOpen;

    void Cleanup();

    UTexture2D* CreateTexture(const TArray<uint8>& imageBytes) const;
};
