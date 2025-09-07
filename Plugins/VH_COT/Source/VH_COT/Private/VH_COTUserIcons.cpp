// Required Includes
#include "VH_COTUserIcons.h"
#include "VH_COT.h"

// Engine Includes
#include "Misc/Paths.h"

// VH Plugin Includes
#include "Database_Spatialite.h"

// Module Includes
#include "VH_COTStatics.h"

UVH_COTUserIcons::UVH_COTUserIcons() :
    PathToIconDB(TEXT("")),
    IconDB(nullptr),
    bDatabaseOpen(false)
{
}

void UVH_COTUserIcons::BeginDestroy()
{
    Cleanup();

    Super::BeginDestroy();
}

void UVH_COTUserIcons::Cleanup()
{
}

void UVH_COTUserIcons::Initialize()
{
    Cleanup();

    IconDB = NewObject<UDatabase_Spatialite>(this);

    bDatabaseOpen = IconDB->OpenDatabase(*(FPaths::RootDir() / PathToIconDB / TEXT("iconsets.sqlite")), false);
    if (!bDatabaseOpen)
    {
        UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTUserIcons::Initialize | could not open sqlite database | %s"), *(FPaths::RootDir() / PathToIconDB / TEXT("iconsets.sqlite")));
    }
}

UTexture2D* UVH_COTUserIcons::GetIcon(const FString& iconSetPath)
{
    if (UTexture2D** pTexture = PathToIcon.Find(iconSetPath))
    {
        return *pTexture;
    }

    if (bDatabaseOpen)
    {
        TArray<FString> elements;
        iconSetPath.ParseIntoArray(elements, TEXT("/"));
        if (elements.Num() == 3)
        {
            FString query = FString::Printf(TEXT("select bitmap from icons where iconset_uid =\"%s\" and groupName = \"%s\" and filename = \"%s\""), *elements[0], *elements[1], *elements[2]);

            SpatialiteResults results;
            IconDB->SyncQuery(query, results);

            if (results.Num() > 0)
            {
                TArray<uint8> imageBytes = UDatabase_Spatialite::GetBlob(TEXT("bitmap"), results[0]);
                UTexture2D* texture = UVH_COTStatics::CreateTexture(imageBytes, EImageFormat::PNG);
                PathToIcon.Add(iconSetPath, texture);

                return texture;
            }

            UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTUserIcons::GetIcon | no results from database | %s"), *iconSetPath);
            return nullptr;
        }
        else
        {
            UE_LOG(VH_COT, Warning, TEXT("-- UVH_COTUserIcons::GetIcon | incorrect iconSetPath | %s"), *iconSetPath);
        }
    }

    return nullptr;
}