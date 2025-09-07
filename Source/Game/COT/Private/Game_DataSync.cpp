#include "Game_DataSync.h"
#include "Game_EntityDB.h"
#include "Game_EntityHandler_COT.h"
#include "Game_EntityHandler_File.h"
#include "Game_ImportManager.h"

#include "VH_COTConnectionInfo.h"
#include "VH_COTManager.h"
#include "Developer_Subsystem_Notification.h"

UGame_DataSync::UGame_DataSync()
{
}

void UGame_DataSync::Unload()
{
    UGame_EntityDB* entityDB = UGame_EntityDB::Get();

    if (entityDB != nullptr)
    {
        for (const FString& uid : UIDs)
        {
            entityDB->Delete(UGame_EntityHandler_COT::StaticGetClassUID(), uid);
        }

        for (const FString& file : Files)
        {
            SpatialiteResults results = entityDB->QueryUID(file);
            if (results.Num() > 0)
            {
                FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), results[0]);

                entityDB->Delete(classUID, file);
            }
        }
    }
}

void UGame_DataSync::ChangesReceived()
{
	if (OnChangesReceived.IsBound())
	{
		OnChangesReceived.Broadcast();
	}
}

void UGame_DataSync::RegisterFile(const FString& fullPathToFile)
{
	if (UGame_ImportManager* importManager = Cast<UGame_ImportManager>(UGame_ImportManager::Get()))
	{
		importManager->RegisterFileToDatabase(fullPathToFile);
	}
}

void UGame_DataSync::Notify(const FString& message, float duration) const
{
	if (UDeveloper_Subsystem_Notification* subsystem = UDeveloper_Subsystem_Notification::Get())
	{
		subsystem->AddNotification(FNotificationData(message, duration, true));
	}
}

bool UGame_DataSync::IsFileRegistered(const FString& fullPathToFile) const
{
    if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
    {
        return entityDB->QueryUID(fullPathToFile).Num() > 0;
    }

    return false;
}

void UGame_DataSync::DeleteFromDatabase(const FString& entityUID, const FString& classUID)
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->Delete(classUID, entityUID);
	}
}
