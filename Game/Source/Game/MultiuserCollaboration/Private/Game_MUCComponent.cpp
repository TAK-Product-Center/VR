#include "Game_MUCComponent.h"
#include "Game_PlayerController.h"
#include "Game_Statics.h"
#include "Game_GameInstance.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_PlayerState.h"

#include "Developer_Subsystem_TaskTracker.h"
#include "VH_DataChannelManager.h"
#include "VH_COTManager.h"
#include "VH_FileIOStatics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_MUCComponent::UGame_MUCComponent()
{
	SetIsReplicatedByDefault(true);
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_MUCComponent::OnComponentDestroyed(bool bDestroyingHierarchy)
{
	if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
	{
		for (FString taskID : TaskIDs)
		{
			taskTracker->RemoveActiveTask(taskID);
			taskTracker->RemoveActiveTask(taskID);
		}
	}

	if (DCM != nullptr)
	{
		DCM->OnDataReceived.RemoveDynamic(this, &UGame_MUCComponent::HandleReceivedData);

		if (GetNetMode() == NM_ListenServer)
		{
			DCM->OnServerSendProgress.RemoveDynamic(this, &UGame_MUCComponent::HandleServerSendProgress);
			DCM->OnServerReceiveProgress.RemoveDynamic(this, &UGame_MUCComponent::HandleServerReceiveProgress);

			DCM->OnServerChannelClosed.RemoveDynamic(this, &UGame_MUCComponent::Server_HandleChannelClosed);
		}
		else if (GetNetMode() == NM_Client)
		{
			DCM->OnClientSendProgress.RemoveDynamic(this, &UGame_MUCComponent::HandleClientSendProgress);
			DCM->OnClientReceiveProgress.RemoveDynamic(this, &UGame_MUCComponent::HandleClientReceiveProgress);
		}
	}

	Super::OnComponentDestroyed(bDestroyingHierarchy);
}

bool UGame_MUCComponent::IsReadyForFinishDestroy()
{
	return Super::IsReadyForFinishDestroy() && DestroyCounter.GetValue() == 0;
}

// ---------------------------------
// --- API
// ---------------------------------

UVH_DataChannelManager* UGame_MUCComponent::GetDCM(int32 id)
{
	if (DCM == nullptr)
	{
		CreateDCM(id);
	}

	return DCM;
}

bool UGame_MUCComponent::GetChannelReady()
{
	return bChannelReady;
}

void UGame_MUCComponent::SetChannelReady(bool bReady)
{
	bChannelReady = bReady;
}

void UGame_MUCComponent::CreateDCM(int32 id)
{
	DCM = NewObject<UVH_DataChannelManager>(this);
	DCM->Initialize(id, GetOwner());
	DCM->SetCompression(true, 30000000);

	DCM->OnDataReceived.AddDynamic(this, &UGame_MUCComponent::HandleReceivedData);

	if (GetNetMode() == NM_ListenServer)
	{
		DCM->OnServerSendProgress.AddDynamic(this, &UGame_MUCComponent::HandleServerSendProgress);
		DCM->OnServerReceiveProgress.AddDynamic(this, &UGame_MUCComponent::HandleServerReceiveProgress);

		DCM->OnServerChannelClosed.AddDynamic(this, &UGame_MUCComponent::Server_HandleChannelClosed);
	}
	else if (GetNetMode() == NM_Client)
	{
		DCM->OnClientSendProgress.AddDynamic(this, &UGame_MUCComponent::HandleClientSendProgress);
		DCM->OnClientReceiveProgress.AddDynamic(this, &UGame_MUCComponent::HandleClientReceiveProgress);
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

bool UGame_MUCComponent::IsSafeToExecute()
{
	if (!IsValidLowLevelFast() || HasAnyFlags(RF_BeginDestroyed) || GetClass() == nullptr)
	{
		return false;
	}

	return true;
}

FString UGame_MUCComponent::GetTaskID(APlayerController* playerController, bool bSend) const
{
	return TEXT("");
}

FString UGame_MUCComponent::GetTaskDescription(APlayerController* playerController, bool bSend) const
{
	return TEXT("");
}

void UGame_MUCComponent::UpdateTasks(APlayerController* playerController, bool bSend, float pctComplete)
{
	if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
	{
		FString taskID = GetTaskID(playerController, bSend);

		FString taskDescription = GetTaskDescription(playerController, bSend);

		if (pctComplete < 1)
		{
			TaskIDs.Add(taskID);
		}

		taskTracker->AddActiveTask(taskID, taskDescription, pctComplete);

		if (pctComplete >= 1)
		{
			TaskIDs.Remove(taskID);

			taskTracker->RemoveActiveTask(taskID);
		}
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_MUCComponent::HandleReceivedData(const TArray<uint8>& receivedData)
{

}

void UGame_MUCComponent::HandleClientSendProgress(float pctComplete)
{
	UpdateTasks(nullptr, true, pctComplete);
}

void UGame_MUCComponent::HandleClientReceiveProgress(float pctComplete)
{
	UpdateTasks(nullptr, false, pctComplete);
}

void UGame_MUCComponent::HandleServerSendProgress(APlayerController* playerController, float pctComplete)
{
	UpdateTasks(playerController, true, pctComplete);
}

void UGame_MUCComponent::HandleServerReceiveProgress(APlayerController* playerController, float pctComplete)
{
	UpdateTasks(playerController, false, pctComplete);
}

void UGame_MUCComponent::Server_HandleChannelClosed(APlayerController* playerController)
{
	// clear any pending sends/receives from client
	UpdateTasks(playerController, false, 1);

	UpdateTasks(playerController, true, 1);

	PostServer_HandleChannelClosed(playerController);
}
