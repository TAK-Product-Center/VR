// Required Includes
#include "Game_ListEntry_ViewItem.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_COTManager.h"
#include "VH_COTEvent.h"

// Game Includes
#include "Game_EntityDB.h"
#include "Game_HandlerService.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_ListEntry_ViewItem::UGame_ListEntry_ViewItem(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- API
// ---------------------------------

FString UGame_ListEntry_ViewItem::GetName(const FString& entityUID) const
{
	// if it's a COT type entity, return the callsign
	if (UVH_COTManager* cotManager = UVH_COTManager::Get())
	{
		if (UVH_COTEvent* cotEvent = cotManager->GetCotEventFromUID(entityUID))
		{
			return cotEvent->GetAttribute(TEXT("callsign"));
		}
	}

	// otherwise check if it has displayName in it's overlay info
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();
	UGame_HandlerService* handlerService = UGame_HandlerService::Get();
	if (entityDB != nullptr && handlerService != nullptr)
	{
		FSpatialiteResult_BP resultBP = entityDB->QueryUIDForResult(entityUID);

		TMap<FString, FString> keyValues;
		handlerService->GetEntityOverlayInfo(resultBP, keyValues);

		if (FString const* displayNamePtr = keyValues.Find(TEXT("displayName")))
		{
			return *displayNamePtr;
		}
	}

	// final fallback, return entityUID
	return entityUID;
}
