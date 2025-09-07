// Required Includes
#include "Game_DataPackage.h"
#include "Game.h"

// Engine Includes
#include "Misc/Paths.h"

// VH Plugin Includes
#include "VH_COTManager.h"

// Game Includes
#include "Game_EntityDB.h"

UGame_DataPackage::UGame_DataPackage()
{
}

void UGame_DataPackage::SetVisibility(bool bVisibleArg)
{
    Super::SetVisibility(bVisibleArg);

    if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
    {
        for (const FString& uid : UIDs)
        {
            entityDB->SetEntityVisibility(uid, bVisible);
        }

        for (const FString& file : Files)
        {
			FString modifiedFilename = file;

			// special case for zip files
			if (file.EndsWith(TEXT(".zip")) || file.EndsWith(TEXT(".7z")) || file.EndsWith(TEXT(".kmz")))
			{
				FString query = TEXT("select entityUID from entities where entityUID like \"%");
				query += FPaths::GetBaseFilename(file);
				query += TEXT("%\"");

				SpatialiteResults results;
				entityDB->SyncQuery(query, results);

				for (const SpatialiteResult& result : results)
				{
					FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

					if (FPaths::GetBaseFilename(FPaths::GetPath(entityUID)).Equals(FPaths::GetBaseFilename(file)))
					{
						modifiedFilename = entityUID;
						break;
					}
				}
			}
            
			entityDB->SetEntityVisibility(modifiedFilename, bVisible);
        }
    }
}
