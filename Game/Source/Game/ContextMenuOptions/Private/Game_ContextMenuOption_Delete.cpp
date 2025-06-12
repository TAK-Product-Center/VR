// Required Includes
#include "Game_ContextMenuOption_Delete.h"
#include "Game.h"

// Game Includes
#include "Game_Statics.h"
#include "Game_EntityDB.h"
#include "Game_VirtualObjective.h"
#include "Game_PlayerController.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_ContextMenuOption_Delete::UGame_ContextMenuOption_Delete(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_ContextMenuOption_Delete::PostExecute()
{
	Super::PostExecute();
	
	TSet<UObject*> subOptions;
	if (!GetSubOptions(subOptions))
	{
		TSet<TSubclassOf<UObject>> subOptionClasses = GetSubOptionClasses();
		if (subOptionClasses.Num() == 0)
		{
			FString entityID;
			FString classUID;
			if (GetEntityInfo(entityID, classUID))
			{
				if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
				{
					entityDB->Delete(classUID, entityID, true);
				}
			}
		}
	}
}

// ---------------------------------
// --- API
// ---------------------------------

bool UGame_ContextMenuOption_Delete::GetEntityInfo(FString& entityID, FString& classUID) const
{
	AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO();
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();

	if (virtualObjective != nullptr && entityDB != nullptr)
	{
		AActor* actor = Cast<AActor>(Source);
		while (entityID.IsEmpty() && actor != nullptr)
		{
			entityID = virtualObjective->GetObjectEntityUID(actor);

			if (entityID.IsEmpty())
			{
				actor = actor->GetOwner();
			}
		}
		
		if (!entityID.IsEmpty())
		{
			SpatialiteResults results = entityDB->QueryUID(entityID);
			if (results.Num() > 0)
			{
				classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), results[0]);

				return true;
			}
		}
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_ContextMenuOption_Delete::GetEntityInfo | unable to get entity information | returning false"));
	return false;
}
