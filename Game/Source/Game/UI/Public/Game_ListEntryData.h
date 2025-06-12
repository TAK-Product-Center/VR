#pragma once
#include "VH_ListEntryData.h"
#include "Materials/MaterialInstance.h"
#include "Engine/Texture2D.h"

#include "Game_ListEntryData.generated.h"

/*
Replaces the old Generic01_ListEntryData with a native implementation
Contains arrays of generic data which can be passed to any ListEntry regardless of the type
*/
UCLASS(Blueprintable, BlueprintType)
class UGame_ListEntryData : public UVH_ListEntryData
{
    GENERATED_UCLASS_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Strings", ExposeOnSpawn = true))
    TArray<FString> Strings;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Textures", ExposeOnSpawn = true))
    TArray<UTexture2D*> Textures;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Materials", ExposeOnSpawn = true))
    TArray<UMaterialInstance*> Materials;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "Bools", ExposeOnSpawn = true))
    TArray<bool> Bools;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (DisplayName = "NameList", ExposeOnSpawn = true))
    TArray<FName> NameList;
};