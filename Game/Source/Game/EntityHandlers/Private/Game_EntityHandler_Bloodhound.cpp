// Required Includes
#include "Game_EntityHandler_Bloodhound.h"
#include "Game.h"

// Engine Includes
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"
#include "Engine/World.h"

// VH Plugin Includes
#include "Developer_Statics.h"
#include "VH_GlobeReferenceActor.h"

// Game Includes
#include "Game_PlayerController.h"
#include "Game_BloodhoundManager.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_EntityDB.h"
#include "Game_HandlerService.h"
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_EntityHandler_Bloodhound::UGame_EntityHandler_Bloodhound()
{

}

// ---------------------------------
// --- Interface_EntityHandler
// ---------------------------------

void UGame_EntityHandler_Bloodhound::UpdateEntity_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	if (UGame_BloodhoundManager* bloodhoundManager = UGame_BloodhoundManager::Get())
	{
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
		TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);

		bloodhoundManager->PageOut(virtualObjective, entityUID);

		bloodhoundManager->PageIn(virtualObjective, entityUID, 1, blobData);
	}
}

void UGame_EntityHandler_Bloodhound::SetEntityDetailStatus_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, int32 detailStatus)
{
	if (UGame_BloodhoundManager* bloodhoundManager = UGame_BloodhoundManager::Get())
	{
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
		TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);
		
		switch (detailStatus)
		{
			case 0:
				virtualObjective->PageOutEntity(entityUID);
				bloodhoundManager->PageOut(virtualObjective, entityUID);
				break;

			case 1:
				bloodhoundManager->PageIn(virtualObjective, entityUID, detailStatus, blobData);
				break;
		}
	}
}

void UGame_EntityHandler_Bloodhound::SetEntityVisibility_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, bool bVisible)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	
	virtualObjective->SetEntityVisibility(entityUID, bVisible);
}

void UGame_EntityHandler_Bloodhound::GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues)
{
	keyValues.Add(TEXT("displayName"), TEXT("Bloodhound"));
}

void UGame_EntityHandler_Bloodhound::DeleteEntity_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	
	virtualObjective->PageOutEntity(entityUID);

	if (UGame_BloodhoundManager* bloodhoundManager = UGame_BloodhoundManager::Get())
	{
		bloodhoundManager->PageOut(virtualObjective, entityUID);
	}
}

void UGame_EntityHandler_Bloodhound::SetEntityScale3D_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FVector& scale3D)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	
	virtualObjective->SetEntityScale3D(entityUID, scale3D);
}

void UGame_EntityHandler_Bloodhound::PreModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	
}

void UGame_EntityHandler_Bloodhound::PostModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	
}

void UGame_EntityHandler_Bloodhound::SnapEntityToGround_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{

}

void UGame_EntityHandler_Bloodhound::GetGoToCoord_Implementation(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate)
{
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();
	UGame_HandlerService* handlerService = UGame_HandlerService::Get();

	if (entityDB != nullptr && handlerService != nullptr)
	{
		TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);
		
		FMemoryReader memoryReader = FMemoryReader(blobData, false);
		memoryReader.Seek(0);

		FString chaserEntityUID;
		FString targetEntityUID;

		memoryReader << chaserEntityUID;
		memoryReader << targetEntityUID;

		if (APawn* playerPawn = GetPlayerPawn(chaserEntityUID))
		{
			if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
			{
				if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
				{
					coordinate = globeReference->WorldToGeodeticDouble(playerPawn->GetActorLocation());

					return;
				}
			}
		}
		
		SpatialiteResults results = entityDB->QueryUID(chaserEntityUID);
		if (results.Num() > 0)
		{
			handlerService->GetGoToCoord(results[0], coordinate);
		}
		else
		{
			if (APawn* playerPawn = GetPlayerPawn(targetEntityUID))
			{
				if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
				{
					if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
					{
						coordinate = globeReference->WorldToGeodeticDouble(playerPawn->GetActorLocation());

						return;
					}
				}
			}

			SpatialiteResults results2 = entityDB->QueryUID(targetEntityUID);
			if (results2.Num() > 0)
			{
				handlerService->GetGoToCoord(results2[0], coordinate);
			}
		}
	}
}

TMap<FString, FString> UGame_EntityHandler_Bloodhound::GetHashesToSyncForMUC_Implementation(const FSpatialiteResult_BP& result)
{
	TMap<FString, FString> hashes;

	return hashes;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

APawn* UGame_EntityHandler_Bloodhound::GetPlayerPawn(const FString& entityUID) const
{
	if (AGameStateBase* gameState = UDeveloper_Statics::GetVHWorld()->GetGameState())
	{
		for (APlayerState* playerState : gameState->PlayerArray)
		{
			FString playerID = FString::Printf(TEXT("%d"), playerState->GetPlayerId());

			if (entityUID.Equals(playerID))
			{
				return playerState->GetPawn();
			}
		}
	}

	return nullptr;
}