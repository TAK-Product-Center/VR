// Required Includes
#include "Game_HandlerService.h"
#include "Game.h"

// VH Plugin Includes
#include "Developer_Statics.h"

// Game Includes
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Interface_EntityHandler.h"

DEFINE_LOG_CATEGORY(LogVhHandlerService);

UGame_HandlerService* UGame_HandlerService::GlobalInstance = nullptr;

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_HandlerService::UGame_HandlerService() 
{
    if (!HasAnyFlags(RF_ClassDefaultObject))
    {
        GlobalInstance = this;
    }
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_HandlerService* UGame_HandlerService::Get()
{
    return UGame_HandlerService::GlobalInstance;
}

// ---------------------------------
// --- API
// ---------------------------------

bool UGame_HandlerService::Initialize()
{
    bIsShuttingDown = false;

	FWorldDelegates::OnWorldCleanup.AddUObject(this, &UGame_HandlerService::HandleWorldCleanup);

    bIsInitialized = true;
    return bIsInitialized;
}

void UGame_HandlerService::Shutdown()
{
    bIsShuttingDown = true;

    // NOTE: Do cleanup BEFORE setting GlobalInstance = nullptr
    GlobalInstance = nullptr;
}

void UGame_HandlerService::OnGameModeInit()
{

}

void UGame_HandlerService::OnGameModeStartToLeaveMap()
{
    
}

TArray<UObject*> UGame_HandlerService::GetEntityHandlers(const FString& classUID) const
{
	for (const TPair<FString, FSEntityClassHandlers>& entry : EntityHandlerMap)
	{
		if (classUID.Equals(entry.Key))
		{
			return entry.Value.Handlers;
		}
	}

	TArray<UObject*> emptyArray;
	return emptyArray;
}

TArray<UObject*> UGame_HandlerService::GetAllEntityHandlers() const
{
	TArray<UObject*> handlers;

	for (const TPair<FString, FSEntityClassHandlers>& entry : EntityHandlerMap)
	{
		handlers.Append(entry.Value.Handlers);
	}

	return handlers;
}

void UGame_HandlerService::RegisterEntityHandler(const TScriptInterface<IInterface_EntityHandler>& handler, bool bLoadHandlerObjects)
{
	UObject* handlerObject = handler.GetObject();

	// clear out null handlers
	for (auto& handlerEntry : EntityHandlerMap)
	{
		for (auto i = 0; i < handlerEntry.Value.Handlers.Num(); i++)
		{
			if (handlerEntry.Value.Handlers[i] == nullptr)
			{
				handlerEntry.Value.Handlers.RemoveAt(i);
				i--;
			}
		}
	}

	// ensure unique
	bool bExists = false;
	for (const auto& handlerEntry : EntityHandlerMap)
	{
		for (UObject* objHandler : handlerEntry.Value.Handlers)
		{
			if (objHandler->GetClass() == handlerObject->GetClass())
			{
				bExists = true;
			}
		}
	}

	if (!bExists)
	{
		FString classUID = IInterface_EntityHandler::Execute_GetClassUID(handlerObject);
		UDeveloper_Statics::PrintMessageLog(FString::Printf(TEXT("-- UGame_HandlerService::RegisterEntityHandler | entity classUID: %s | handler class: %s"), *classUID, *handlerObject->GetName()), false, false, true, false, ELogMessageColor::White);

		if (FSEntityClassHandlers* classHandlers = EntityHandlerMap.Find(classUID))
		{
			(*classHandlers).Handlers.AddUnique(handlerObject);
		}
		else
		{
			FSEntityClassHandlers newClassHandlers;
			newClassHandlers.Handlers.Add(handlerObject);

			EntityHandlerMap.Add(classUID, newClassHandlers);
		}
	}

	// load objects for this handler
	if (bLoadHandlerObjects)
	{
		if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
		{
			// TODO: Consider switching this to a delegate, assuming voManager is initialized before handlers are registered! (or else it can queue them up)
			voManager->EntityHandlerRegistered(handlerObject);
		}
	}
}

void UGame_HandlerService::UpdateEntity(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, UObject* handler)
{
	if (handler == nullptr)
	{
		FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);

		if (FSEntityClassHandlers* classHandlersPtr = EntityHandlerMap.Find(classUID))
		{
			TArray<UObject*> handlers = (*classHandlersPtr).Handlers;
			for (UObject* loopHandler : handlers)
			{
				IInterface_EntityHandler::Execute_UpdateEntity(loopHandler, virtualObjective, result);
			}
		}
		else
		{
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
			
			UE_LOG(Game, Warning, TEXT("-- UGame_HandlerService::UpdateEntity | could not find handler for | entityUID: %s | classUID: %s"), *entityUID, *classUID);
		}
	}
	else
	{
		if (handler->GetClass()->ImplementsInterface(UInterface_EntityHandler::StaticClass()))
		{
			IInterface_EntityHandler::Execute_UpdateEntity(handler, virtualObjective, result);
		}
	}
}

void UGame_HandlerService::SetEntityDetailStatus(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, int32 detailStatus, UObject* handler)
{
    if (handler == nullptr)
    {
		FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);

        if (FSEntityClassHandlers* classHandlersPtr = EntityHandlerMap.Find(classUID))
        {
            TArray<UObject*> handlers = (*classHandlersPtr).Handlers;
            for (UObject* loopHandler : handlers)
            {
                IInterface_EntityHandler::Execute_SetEntityDetailStatus(loopHandler, virtualObjective, result, detailStatus);
            }
        }
        else
        {
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
			
            UE_LOG(Game, Warning, TEXT("-- UGame_HandlerService::SetEntityDetailStatus | could not find handler for | entityUID: %s | classUID: %s"), *entityUID, *classUID);
        }
    }
    else
    {
        if (handler->GetClass()->ImplementsInterface(UInterface_EntityHandler::StaticClass()))
        {
            IInterface_EntityHandler::Execute_SetEntityDetailStatus(handler, virtualObjective, result, detailStatus);
        }
    }
}

void UGame_HandlerService::SetEntityVisibility(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, bool bVisible, UObject* handler)
{
    if (handler == nullptr)
    {
		FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);
		
        if (FSEntityClassHandlers* classHandlersPtr = EntityHandlerMap.Find(classUID))
        {
            TArray<UObject*> handlers = (*classHandlersPtr).Handlers;
            for (UObject* loopHandler : handlers)
            {
                IInterface_EntityHandler::Execute_SetEntityVisibility(loopHandler, virtualObjective, result, bVisible);
            }
        }
        else
        {
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
			
			UE_LOG(Game, Warning, TEXT("-- UGame_HandlerService::SetEntityVisibility | could not find handler for | entityUID: %s | classUID: %s"), *entityUID, *classUID);
        }
    }
    else
    {
        if (handler->GetClass()->ImplementsInterface(UInterface_EntityHandler::StaticClass()))
        {
            IInterface_EntityHandler::Execute_SetEntityVisibility(handler, virtualObjective, result, bVisible);
        }
    }
}

void UGame_HandlerService::GetEntityOverlayInfo(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues, UObject* handler)
{
    if (handler == nullptr)
    {
		FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);
		
        if (FSEntityClassHandlers* classHandlersPtr = EntityHandlerMap.Find(classUID))
        {
            TArray<UObject*> handlers = (*classHandlersPtr).Handlers;
            for (UObject* loopHandler : handlers)
            {
                IInterface_EntityHandler::Execute_GetEntityOverlayInfo(loopHandler, result, keyValues);
            }
        }
        else
        {
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
			
            UE_LOG(Game, Warning, TEXT("-- UGame_HandlerService::GetEntityOverlayInfo | could not find handler for | entityUID: %s | classUID: %s"), *entityUID, *classUID);
        }
    }
    else
    {
        if (handler->GetClass()->ImplementsInterface(UInterface_EntityHandler::StaticClass()))
        {
            IInterface_EntityHandler::Execute_GetEntityOverlayInfo(handler, result, keyValues);
        }
    }
}

void UGame_HandlerService::DeleteEntity(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, UObject* handler)
{
    if (handler == nullptr)
    {
		FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);

        if (FSEntityClassHandlers* classHandlersPtr = EntityHandlerMap.Find(classUID))
        {
            TArray<UObject*> handlers = (*classHandlersPtr).Handlers;
            for (UObject* loopHandler : handlers)
            {
                IInterface_EntityHandler::Execute_DeleteEntity(loopHandler, virtualObjective, result);
            }
        }
        else
        {
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
			
            UE_LOG(Game, Warning, TEXT("-- UGame_HandlerService::DeleteEntity | could not find handler for | entityUID: %s | classUID: %s"), *entityUID, *classUID);
        }
    }
    else
    {
        if (handler->GetClass()->ImplementsInterface(UInterface_EntityHandler::StaticClass()))
        {
            IInterface_EntityHandler::Execute_DeleteEntity(handler, virtualObjective, result);
        }
    }
}

void UGame_HandlerService::SetEntityScale3D(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FVector& scale3D, UObject* handler)
{
	if (handler == nullptr)
	{
		FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);

		if (FSEntityClassHandlers* classHandlersPtr = EntityHandlerMap.Find(classUID))
		{
			TArray<UObject*> handlers = (*classHandlersPtr).Handlers;
			for (UObject* loopHandler : handlers)
			{
				IInterface_EntityHandler::Execute_SetEntityScale3D(loopHandler, virtualObjective, result, scale3D);
			}
		}
		else
		{
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
			
			UE_LOG(Game, Warning, TEXT("-- UGame_HandlerService::SetEntityScale3D | could not find handler for | entityUID: %s | classUID: %s"), *entityUID, *classUID);
		}
	}
	else
	{
		if (handler->GetClass()->ImplementsInterface(UInterface_EntityHandler::StaticClass()))
		{
			IInterface_EntityHandler::Execute_SetEntityScale3D(handler, virtualObjective, result, scale3D);
		}
	}
}

void UGame_HandlerService::PreModifyVOGlobeReference(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, UObject* handler)
{
	if (handler == nullptr)
	{
		FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);

		if (FSEntityClassHandlers* classHandlersPtr = EntityHandlerMap.Find(classUID))
		{
			TArray<UObject*> handlers = (*classHandlersPtr).Handlers;
			for (UObject* loopHandler : handlers)
			{
				IInterface_EntityHandler::Execute_PreModifyVOGlobeReference(loopHandler, virtualObjective, result);
			}
		}
		else
		{
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
			
			UE_LOG(Game, Warning, TEXT("-- UGame_HandlerService::PreModifyVOGlobeReference | could not find handler for | entityUID: %s | classUID: %s"), *entityUID, *classUID);
		}
	}
	else
	{
		if (handler->GetClass()->ImplementsInterface(UInterface_EntityHandler::StaticClass()))
		{
			IInterface_EntityHandler::Execute_PreModifyVOGlobeReference(handler, virtualObjective, result);
		}
	}
}

void UGame_HandlerService::PostModifyVOGlobeReference(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, UObject* handler)
{
	if (handler == nullptr)
	{
		FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);

		if (FSEntityClassHandlers* classHandlersPtr = EntityHandlerMap.Find(classUID))
		{
			TArray<UObject*> handlers = (*classHandlersPtr).Handlers;
			for (UObject* loopHandler : handlers)
			{
				IInterface_EntityHandler::Execute_PostModifyVOGlobeReference(loopHandler, virtualObjective, result);
			}
		}
		else
		{
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
			
			UE_LOG(Game, Warning, TEXT("-- UGame_HandlerService::PostModifyVOGlobeReference | could not find handler for | entityUID: %s | classUID: %s"), *entityUID, *classUID);
		}
	}
	else
	{
		if (handler->GetClass()->ImplementsInterface(UInterface_EntityHandler::StaticClass()))
		{
			IInterface_EntityHandler::Execute_PostModifyVOGlobeReference(handler, virtualObjective, result);
		}
	}
}

void UGame_HandlerService::SnapEntityToGround(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, UObject* handler)
{
	if (handler == nullptr)
	{
		FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);

		if (FSEntityClassHandlers* classHandlersPtr = EntityHandlerMap.Find(classUID))
		{
			TArray<UObject*> handlers = (*classHandlersPtr).Handlers;
			for (UObject* loopHandler : handlers)
			{
				IInterface_EntityHandler::Execute_SnapEntityToGround(loopHandler, virtualObjective, result);
			}
		}
		else
		{
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
			
			UE_LOG(Game, Warning, TEXT("-- UGame_HandlerService::SnapEntityToGround | could not find handler for | entityUID: %s | classUID: %s"), *entityUID, *classUID);
		}
	}
	else
	{
		if (handler->GetClass()->ImplementsInterface(UInterface_EntityHandler::StaticClass()))
		{
			IInterface_EntityHandler::Execute_SnapEntityToGround(handler, virtualObjective, result);
		}
	}
}

void UGame_HandlerService::GetGoToCoord(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate, UObject* handler)
{
	if (handler == nullptr)
	{
		FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);

		if (FSEntityClassHandlers* classHandlersPtr = EntityHandlerMap.Find(classUID))
		{
			TArray<UObject*> handlers = (*classHandlersPtr).Handlers;
			for (UObject* loopHandler : handlers)
			{
				IInterface_EntityHandler::Execute_GetGoToCoord(loopHandler, result, coordinate);
			}
		}
		else
		{
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
			
			UE_LOG(Game, Warning, TEXT("-- UGame_HandlerService::GetGoToCoord | could not find handler for | entityUID: %s | classUID: %s"), *entityUID, *classUID);
		}
	}
	else
	{
		if (handler->GetClass()->ImplementsInterface(UInterface_EntityHandler::StaticClass()))
		{
			IInterface_EntityHandler::Execute_GetGoToCoord(handler, result, coordinate);
		}
	}
}

TSubclassOf<class UUserWidget> UGame_HandlerService::GetDetailsWidgetClass(const FSpatialiteResult_BP& result, UObject* handler)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);

	if (handler == nullptr)
	{
		if (FSEntityClassHandlers* classHandlersPtr = EntityHandlerMap.Find(classUID))
		{
			TArray<UObject*> handlers = (*classHandlersPtr).Handlers;
			for (UObject* loopHandler : handlers)
			{
				return IInterface_EntityHandler::Execute_GetDetailsWidgetClass(loopHandler, result);
			}
		}
		else
		{
			
			
			UE_LOG(Game, Warning, TEXT("-- UGame_HandlerService::GetDetailsWidgetClass | could not find handler for | entityUID: %s | classUID: %s"), *entityUID, *classUID);
		}
	}
	else
	{
		if (handler->GetClass()->ImplementsInterface(UInterface_EntityHandler::StaticClass()))
		{
			return IInterface_EntityHandler::Execute_GetDetailsWidgetClass(handler, result);
		}
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_HandlerService::GetDetailsWidgetClass | failed, returning nullptr | entityUID: %s | classUID: %s"), *entityUID, *classUID);

	return nullptr;
}

TMap<FString, FString> UGame_HandlerService::GetHashesToSyncForMUC(const FSpatialiteResult_BP& result, UObject* handler)
{
	if (handler == nullptr)
	{
		FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result);

		if (FSEntityClassHandlers* classHandlersPtr = EntityHandlerMap.Find(classUID))
		{
			TArray<UObject*> handlers = (*classHandlersPtr).Handlers;
			for (UObject* loopHandler : handlers)
			{
				return IInterface_EntityHandler::Execute_GetHashesToSyncForMUC(loopHandler, result);
			}
		}
		else
		{
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
			
			UE_LOG(Game, Warning, TEXT("-- UGame_HandlerService::GetHashesToSyncForMUC | could not find handler for | entityUID: %s | classUID: %s"), *entityUID, *classUID);
		}
	}
	else
	{
		if (handler->GetClass()->ImplementsInterface(UInterface_EntityHandler::StaticClass()))
		{
			return IInterface_EntityHandler::Execute_GetHashesToSyncForMUC(handler, result);
		}
	}

	TMap<FString, FString> hashes;
	return hashes;
}

bool UGame_HandlerService::RegisterFileToDatabaseFirstPass(const FString& fullPathToFile, TSet<FString>& registeredEntityUIDs)
{
	bool bHandled = false;

	for (const TPair<FString, FSEntityClassHandlers>& entry : EntityHandlerMap)
	{
		for (UObject* object : entry.Value.Handlers)
		{
			bHandled = bHandled || IInterface_EntityHandler::Execute_RegisterFileToDatabaseFirstPass(object, fullPathToFile, registeredEntityUIDs);
		}
	}

	return bHandled;
}

bool UGame_HandlerService::RegisterFileToDatabaseSecondPass(const FString& fullPathToFile, TSet<FString>& registeredEntityUIDs)
{
	bool bHandled = false;

	for (const TPair<FString, FSEntityClassHandlers>& entry : EntityHandlerMap)
	{
		for (UObject* object : entry.Value.Handlers)
		{
			bHandled = bHandled || IInterface_EntityHandler::Execute_RegisterFileToDatabaseSecondPass(object, fullPathToFile, registeredEntityUIDs);
		}
	}

	return bHandled;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_HandlerService::HandleWorldCleanup(UWorld* world, bool bSessionEnded, bool bCleanupResources)
{
	// TODO: For now, clearing handlers when changing maps.  However, we do eventually want to support handlers persisting across map loads!
	//		 This was only added to prevent RegisterEntityHandler() from reloading a mesh (e.g. Range74.zip) after the initial UpdateRelevancySet() already loaded it.
	EntityHandlerMap.Empty();
}
