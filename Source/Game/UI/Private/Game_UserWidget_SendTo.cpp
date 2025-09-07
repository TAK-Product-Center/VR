// Required Includes
#include "Game_UserWidget_SendTo.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_DataPackage.h"
#include "VH_DataSync.h"
#include "VH_COTComponent.h"
#include "Interface_COTReceiver.h"
#include "UI_Subsystem_Core.h"

// Game Includes
#include "Game_COTManager.h"
#include "Game_PlayerController.h"
#include "Game_VirtualObjective.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_SendTo::UGame_UserWidget_SendTo(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_SendTo::SetEntityUID(const FString& entityUID)
{
	EntityUID = entityUID;

	ReceiveSetEntityUID(EntityUID);
}

FString UGame_UserWidget_SendTo::GetEntityUID() const
{
	return EntityUID;
}

void UGame_UserWidget_SendTo::SetDataPackage(UVH_DataPackage* dataPackage)
{
	DataPackage = dataPackage;

	ReceiveSetDataPackage(DataPackage);
}

UVH_DataPackage* UGame_UserWidget_SendTo::GetDataPackage() const
{
	return DataPackage;
}

void UGame_UserWidget_SendTo::Broadcast()
{
	InternalSend(true, TSet<FString>(), TSet<UVH_DataPackage*>(), TSet<UVH_DataSync*>());
}

void UGame_UserWidget_SendTo::Send(const TSet<FString>& contactUIDs, const TSet<UVH_DataPackage*>& dataPackages, const TSet<UVH_DataSync*>& dataSyncs)
{
	InternalSend(false, contactUIDs, dataPackages, dataSyncs);
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_UserWidget_SendTo::InternalSend(bool bBroadcast, const TSet<FString>& contactUIDs, const TSet<UVH_DataPackage*>& dataPackages, const TSet<UVH_DataSync*>& dataSyncs)
{
	TArray<FName> contactNames;
	for (const FString& contactUID : contactUIDs)
	{
		contactNames.Add(FName(*contactUID));
	}

	if (IsValid(DataPackage))
	{
		if (bBroadcast)
		{
			DataPackage->Broadcast(TEXT(""));
		}
		else
		{
			DataPackage->Send(contactNames, TEXT(""));
		}
	}
	else
	{
		if (EntityUID.IsEmpty())
		{
			return;
		}

		if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
		{
			if (virtualObjective->IsEntityPagedIn(EntityUID))
			{
				TSet<AActor*> actors = virtualObjective->GetActorsForEntity(EntityUID);
				for (AActor* actor : actors)
				{
					if (actor->GetClass()->ImplementsInterface(UInterface_COTReceiver::StaticClass()))
					{
						if (UVH_COTComponent* cotComponent = IInterface_COTReceiver::Execute_GetCOTComponent(actor))
						{
							if (bBroadcast)
							{
								cotComponent->BroadcastCOT();
							}
							else
							{
								if (!contactNames.IsEmpty())
								{
									cotComponent->SendCOT(contactNames);
								}
							}
						}
					}
				}
			}
			else
			{
				if (UGame_COTManager* cotManager = UGame_COTManager::Get())
				{
					if (UVH_COTEvent* cotEvent = cotManager->GetCotEventFromUID(EntityUID))
					{
						if (bBroadcast)
						{
							cotManager->BroadcastCOT(cotEvent->ToXML());
						}
						else
						{
							if (!contactNames.IsEmpty())
							{
								cotManager->SendCOT(contactNames, cotEvent->ToXML());
							}
						}
					}
				}
			}
		}

		if (!bBroadcast)
		{
			for (UVH_DataPackage* dataPackage : dataPackages)
			{
				dataPackage->AddUID(EntityUID);
			}

			for (UVH_DataSync* dataSync : dataSyncs)
			{
				dataSync->AddCOTToTAKServer(EntityUID);
			}
		}
	}

	if (UUI_Subsystem_Core* subsystem = UUI_Subsystem_Core::Get())
	{
		subsystem->CloseUserWidget(this);
	}
}