#pragma once

#include "VH_COT.h"
#include "VH_MilStd2525.generated.h"

USTRUCT(BlueprintType)
struct FSMilStd2525Icon
{
    GENERATED_BODY()

    /* same as COT type */
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName ID;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString DisplayName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    UTexture2D* Texture;

    bool bTextureInitialized;

    FString FilePath;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<FName> ChildrenIDs;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FName ParentID;

    FSMilStd2525Icon() :
        ID(FName(TEXT(""))),
        DisplayName(TEXT("")),
        bTextureInitialized(false),
		FilePath(TEXT("")),
        ParentID(FName(TEXT("")))
    {
        Texture = nullptr;
    }
};

UCLASS(Blueprintable, BlueprintType)
class VH_COT_API UVH_MilStd2525 : public UObject
{
    GENERATED_BODY()

public:
    /* relative path (from FPaths::RootDir()) to raw icon images */
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString PathToIconImages;

    /* relative path (from FPaths::RootDir()) to MilStd2525 xml file */
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString PathToXML;

    /* relative path (from FPaths::RootDir()) to symbols.dat from ATAK */
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString PathToSymbolsDat;

	/* relative path (from FPaths::RootDir()) to archive of icon files (images and symbols.dat) */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString PathToArchive;

	/* id/display name for affiliation */
    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TMap<FName, FString> AffiliationData;

    UVH_MilStd2525();

	/* milStdID should be formatted as a-f-A-B-... */
    UFUNCTION(BlueprintPure)
    FSMilStd2525Icon GetIconData(const FName& milStdID);

    /* get child ID(s) data of milStdID (formatted as a-f-A-B-...) */
    UFUNCTION(BlueprintPure)
    TArray<FSMilStd2525Icon> GetChildrenData(const FName& milStdID);

    /* get parent ID data of milStdID (formatted as a-f-A-B-...) */
    UFUNCTION(BlueprintPure)
    FSMilStd2525Icon GetParentData(const FName& milStdID);

private:
    /* maps MilStdID (ex: a-f-A-b-...) to FSMilStd2525Data */
    UPROPERTY()
    TMap<FName, FSMilStd2525Icon> IDToIcon;

	bool bInitialized;

	bool ReadFromXML();

    void WriteToXML() const;

	bool AutoExtractArchive();

	void PopulateIcons();

    void CreateTexture(const FName& milStdID);

    FName ConvertCOTTypeToID(const FName& cotType);

	void Initialize();
};
