// Parent Includes
#include "VTAK_EntityHandler_Orbit.h"
#include "VTAK_Orbit.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "Developer_Statics.h"

// Game Includes
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_EntityDB.h"

// Module Includes
#include "VTAK_DatabaseComponent_Orbit.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UVTAK_EntityHandler_Orbit::UVTAK_EntityHandler_Orbit() : 
	CategoryID(TEXT(""))
{
}

// ---------------------------------
// --- Interface_EntityHandler
// ---------------------------------

void UVTAK_EntityHandler_Orbit::GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues)
{
	keyValues.Add(TEXT("displayName"), TEXT("Orbit"));
}

void UVTAK_EntityHandler_Orbit::GetGoToCoord_Implementation(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate)
{
	TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);
	
	FMemoryReader memoryReader = FMemoryReader(blobData, false);
	memoryReader.Seek(0);

	memoryReader << coordinate;
}

void UVTAK_EntityHandler_Orbit::DeleteEntity_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	
	PageOutEntity(virtualObjective, entityUID);
}

void UVTAK_EntityHandler_Orbit::PreModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	if (virtualObjective != nullptr)
	{
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
		
		if (UVTAK_DatabaseComponent_Orbit* databaseComponent = GetDatabaseComponent(virtualObjective, entityUID))
		{
			databaseComponent->PreModifyVOGlobeReference(virtualObjective->GetGlobeReference());
		}
	}
}

void UVTAK_EntityHandler_Orbit::PostModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	if (virtualObjective != nullptr)
	{
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
		
		if (UVTAK_DatabaseComponent_Orbit* databaseComponent = GetDatabaseComponent(virtualObjective, entityUID))
		{
			databaseComponent->PostModifyVOGlobeReference(virtualObjective->GetGlobeReference());
		}
	}
}

void UVTAK_EntityHandler_Orbit::SetEntityDetailStatus_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, int32 detailStatus)
{
	if (virtualObjective != nullptr)
	{
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
		TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);
		
		switch (detailStatus)
		{
			case 0:
				PageOutEntity(virtualObjective, entityUID);
				break;

			case 1:
				PageInEntity(virtualObjective, entityUID, blobData);
				break;
		}
	}
}

void UVTAK_EntityHandler_Orbit::SetEntityScale3D_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FVector& scale3D)
{
	if (virtualObjective != nullptr)
	{
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
		
		if (UVTAK_DatabaseComponent_Orbit* databaseComponent = GetDatabaseComponent(virtualObjective, entityUID))
		{
			databaseComponent->SetScale3D(scale3D);
		}
	}
}

void UVTAK_EntityHandler_Orbit::SetEntityVisibility_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, bool bVisible)
{
	if (virtualObjective != nullptr)
	{
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

		if (UVTAK_DatabaseComponent_Orbit* databaseComponent = GetDatabaseComponent(virtualObjective, entityUID))
		{
			if (AActor* owner = databaseComponent->GetOwner())
			{
				owner->SetActorHiddenInGame(!bVisible);
			}
		}
	}
}

void UVTAK_EntityHandler_Orbit::SnapEntityToGround_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	
}

void UVTAK_EntityHandler_Orbit::UpdateEntity_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	if (virtualObjective != nullptr)
	{
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

		if (UVTAK_DatabaseComponent_Orbit* databaseComponent = GetDatabaseComponent(virtualObjective, entityUID))
		{
			databaseComponent->Update(virtualObjective, UDatabase_Spatialite::GetBlob(TEXT("data"), result));
		}
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

UVTAK_DatabaseComponent_Orbit* UVTAK_EntityHandler_Orbit::GetDatabaseComponent(AGame_VirtualObjective* virtualObjective, const FString& entityUID) const
{
	if (virtualObjective != nullptr)
	{
		TSet<AActor*> actors = virtualObjective->GetActorsForEntity(entityUID);
		for (AActor* actor : actors)
		{
			if (UVTAK_DatabaseComponent_Orbit* databaseComponent = Cast<UVTAK_DatabaseComponent_Orbit>(actor->GetComponentByClass(UVTAK_DatabaseComponent_Orbit::StaticClass())))
			{
				return databaseComponent;
			}
		}
	}

	return nullptr;
}

void UVTAK_EntityHandler_Orbit::PageInEntity(AGame_VirtualObjective* virtualObjective, const FString& entityUID, const TArray<uint8>& blobData)
{
	if (virtualObjective)
	{
		if (virtualObjective->IsEntityPagedIn(entityUID))
		{
			return;
		}

		if (UWorld* world = UDeveloper_Statics::GetVHWorld())
		{
			if (AActor* actor = world->SpawnActor<AActor>(OrbitTargetClass))
			{
				if (UVTAK_DatabaseComponent_Orbit* databaseComponent = Cast<UVTAK_DatabaseComponent_Orbit>(actor->GetComponentByClass(UVTAK_DatabaseComponent_Orbit::StaticClass())))
				{
					virtualObjective->AddObjectToEntity(entityUID, actor);

					databaseComponent->PageIn(entityUID, blobData);
				}
				else
				{
					UE_LOG(VTAK_Orbit, Warning, TEXT("-- UVTAK_EntityHandler_Orbit::PageInEntity | OrbitTargetClass does not have a Game_DatabaseComponent_Orbit"));
				}
			}
		}
	}
}

void UVTAK_EntityHandler_Orbit::PageOutEntity(AGame_VirtualObjective* virtualObjective, const FString& entityUID)
{
	if (virtualObjective)
	{
		if (UVTAK_DatabaseComponent_Orbit* databaseComponent = GetDatabaseComponent(virtualObjective, entityUID))
		{
			databaseComponent->PageOut();
		}

		virtualObjective->PageOutEntity(entityUID);
	}
}