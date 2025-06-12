#include "Game_DataPackage.h"
#include "Game_EntityDB.h"
#include "VH_COTManager.h"

UGame_DataPackage::UGame_DataPackage()
{
}

void UGame_DataPackage::SetVisibility(bool bVisibleArg)
{
    if (bVisibleArg != bVisible)
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
                entityDB->SetEntityVisibility(file, bVisible);
            }
        }
    }
}
