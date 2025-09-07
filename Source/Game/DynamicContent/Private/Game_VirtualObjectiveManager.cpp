// Required Includes
#include "Game_VirtualObjectiveManager.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "Developer_Statics.h"

// Game Includes
#include "Game_HandlerService.h"
#include "Game_VirtualObjective.h"
#include "Game_EntityDB.h"

DEFINE_LOG_CATEGORY(LogGameVirtualObjectiveManager);

UGame_VirtualObjectiveManager* UGame_VirtualObjectiveManager::GlobalInstance = nullptr;

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_VirtualObjectiveManager::UGame_VirtualObjectiveManager()
{
    if (!HasAnyFlags(RF_ClassDefaultObject))
    {
        GlobalInstance = this;
    }
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_VirtualObjectiveManager* UGame_VirtualObjectiveManager::Get()
{
    return UGame_VirtualObjectiveManager::GlobalInstance;
}

AGame_VirtualObjective* UGame_VirtualObjectiveManager::GetObjectVO(UObject* object, bool bLogError)
{
	if (object != nullptr)
	{
		UGame_VirtualObjectiveManager* voManager = Get();
		if (voManager != nullptr && voManager->IsValidLowLevelFast())
		{
			TArray<AGame_VirtualObjective*> virtualObjectives = voManager->VirtualObjectives.Array();

			for (int32 i = 0; i < virtualObjectives.Num(); i++)
			{
				AGame_VirtualObjective* virtualObjective = virtualObjectives[i];
				if (virtualObjective != nullptr && virtualObjective->IsValidLowLevelFast() && virtualObjective->HasObject(object))
				{
					return virtualObjective;
				}
			}
		}

		if (bLogError)
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_VirtualObjectiveManager::GetObjectVO | virtualObjective is nullptr for %s"), *object->GetName());
		}
	}
	else if (bLogError)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_VirtualObjectiveManager::GetObjectVO | object is nullptr"));
	}

	return nullptr;
}

AGame_VirtualObjective* UGame_VirtualObjectiveManager::GetObjectVO(const UObject* object, bool bLogError)
{
	return GetObjectVO(const_cast<UObject*>(object), bLogError);
}

FString UGame_VirtualObjectiveManager::GetObjectEntityUID(UObject* object, bool bLogError)
{
	if (object != nullptr)
	{
		if (AGame_VirtualObjective* virtualObjective = GetObjectVO(object, bLogError))
		{
			return virtualObjective->GetObjectEntityUID(object);
		}

		if (bLogError)
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_VirtualObjectiveManager::GetObjectEntityUID | unable to find object's entityUID: %s"), *object->GetName());
		}
	}

	return TEXT("");
}

AVH_GlobeReferenceActor* UGame_VirtualObjectiveManager::GetObjectGlobeReference(UObject* object, bool bLogError)
{
	AVH_GlobeReferenceActor* globeReference = nullptr;

	if (object != nullptr)
	{
		if (AGame_VirtualObjective* virtualObjective = GetObjectVO(object))
		{
			globeReference = virtualObjective->GetGlobeReference();
		}

		if (bLogError && globeReference == nullptr)
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_VirtualObjectiveManager::GetObjectGlobeReference | globeReference is nullptr for %s"), *object->GetName());
		}
	}
	else if (bLogError)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_VirtualObjectiveManager::GetObjectGlobeReference | object is nullptr"));
	}

	return globeReference;
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_VirtualObjectiveManager::RegisterVirtualObjective(AGame_VirtualObjective* virtualObjective)
{
	if (virtualObjective != nullptr)
	{
		UDeveloper_Statics::PrintMessageLog(FString::Printf(TEXT("registering VirtualObjective = \"%s\""), *virtualObjective->GetName()), false, false, true, false, ELogMessageColor::Cyan);
		VirtualObjectives.Add(virtualObjective);
	}
}

void UGame_VirtualObjectiveManager::UnregisterVirtualObjective(AGame_VirtualObjective* virtualObjective)
{
	if (virtualObjective != nullptr)
	{
		UDeveloper_Statics::PrintMessageLog(FString::Printf(TEXT("unregistering VirtualObjective = \"%s\""), *virtualObjective->GetName()), false, false, true, false, ELogMessageColor::Cyan);
		VirtualObjectives.Remove(virtualObjective);
	}
}

void UGame_VirtualObjectiveManager::TriggerUpdateGlobal()
{
	for (AGame_VirtualObjective* virtualObjective : VirtualObjectives)
	{
		virtualObjective->TriggerUpdate();
	}
}

TSet<AActor*> UGame_VirtualObjectiveManager::GetActorsForEntityGlobal(const FString& entityUID) const
{
	TSet<AActor*> actors;

	for (AGame_VirtualObjective* virtualObjective : VirtualObjectives)
	{
		actors.Append(virtualObjective->GetActorsForEntity(entityUID));
	}

	return actors;
}

void UGame_VirtualObjectiveManager::DeleteEntityGlobal(const SpatialiteResult& result)
{
	if (UGame_HandlerService* handlerService = UGame_HandlerService::Get())
	{
		for (AGame_VirtualObjective* virtualObjective : VirtualObjectives)
		{
			handlerService->DeleteEntity(virtualObjective, result);
		}
	}
}

void UGame_VirtualObjectiveManager::DeleteEntityGlobal(const FString& entityUID)
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		SpatialiteResults results = entityDB->QueryUID(entityUID);
		if (results.Num() > 0)
		{
			DeleteEntityGlobal(results[0]);
		}
	}
}

void UGame_VirtualObjectiveManager::SetEntityVisibilityGlobal(const SpatialiteResult& result, bool bVisible)
{
	if (UGame_HandlerService* handlerService = UGame_HandlerService::Get())
	{
		for (AGame_VirtualObjective* virtualObjective : VirtualObjectives)
		{
			handlerService->SetEntityVisibility(virtualObjective, result, bVisible);
		}
	}
}

void UGame_VirtualObjectiveManager::SetEntityVisibilityGlobal(const FString& entityUID, bool bVisible)
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		SpatialiteResults results = entityDB->QueryUID(entityUID);
		if (results.Num() > 0)
		{
			SetEntityVisibilityGlobal(results[0], bVisible);
		}
	}
}

void UGame_VirtualObjectiveManager::UpdateEntityGlobal(const SpatialiteResult& result)
{
	if (UGame_HandlerService* handlerService = UGame_HandlerService::Get())
	{
		for (AGame_VirtualObjective* virtualObjective : VirtualObjectives)
		{
			if (virtualObjective->IsEntityPagedIn(UDatabase_Spatialite::GetString(TEXT("entityUID"), result)))
			{
				handlerService->UpdateEntity(virtualObjective, result);
			}
		}
	}
}

void UGame_VirtualObjectiveManager::UpdateEntityGlobal(const FString& entityUID)
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		SpatialiteResults results = entityDB->QueryUID(entityUID);
		if (results.Num() > 0)
		{
			UpdateEntityGlobal(results[0]);
		}
	}
}

void UGame_VirtualObjectiveManager::PageOutEntitiesGlobal()
{
	for (AGame_VirtualObjective* virtualObjective : VirtualObjectives)
	{
		virtualObjective->PageOutEntities();
	}
}

bool UGame_VirtualObjectiveManager::Initialize()
{
	bIsShuttingDown = false;

	bIsInitialized = true;

	return bIsInitialized;
}

void UGame_VirtualObjectiveManager::Shutdown()
{
	bIsShuttingDown = true;

	// NOTE: Do cleanup BEFORE setting GlobalInstance = nullptr
	GlobalInstance = nullptr;
}

void UGame_VirtualObjectiveManager::OnGameModeInit()
{

}

void UGame_VirtualObjectiveManager::OnGameModeStartToLeaveMap()
{

}

void UGame_VirtualObjectiveManager::EntityHandlerRegistered(UObject* handler)
{
	for (AGame_VirtualObjective* virtualObjective : VirtualObjectives)
	{
		virtualObjective->EntityHandlerRegistered(handler);
	}
}

AGame_VirtualObjective* UGame_VirtualObjectiveManager::GetVirtualObjectiveByEntityDetailLevel(int32 entityDetailLevel) const
{
	for (AGame_VirtualObjective* virtualObjective : VirtualObjectives)
	{
		if (virtualObjective->GetEntityDetailLevel() == entityDetailLevel)
		{
			return virtualObjective;
		}
	}

	return nullptr;
}

// ---------------------------------
// --- Debug/Testing
// ---------------------------------

void UGame_VirtualObjectiveManager::VOMgrTest_SetVOScale(float newScale)
{
	if (newScale <= 0)
	{
		UDeveloper_Statics::PrintMessageLog(FString::Printf(TEXT("VOMgrTest_SetVOScale | Error: Invalid scale value = %f"), newScale), true, true, true, false, ELogMessageColor::Red);
		return;
	}

	// todo ohg | get local player's active VO
	/*if (AGame_VirtualObjective* activeVO = GetActiveVirtualObjective())
	{
		activeVO->SetActorScale3D(FVector(newScale));
	}*/
}
