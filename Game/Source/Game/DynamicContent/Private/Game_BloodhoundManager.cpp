// Required Includes
#include "Game_BloodhoundManager.h"
#include "Game.h"

// Engine Includes
#include "Serialization/BufferArchive.h"

// Game Includes
#include "Game_EntityHandler_Bloodhound.h"
#include "Game_HandlerService.h"
#include "Game_Arrow.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_PlayerState.h"
#include "Game_Bloodhound.h"
#include "Game_Statics.h"
#include "Game_GameInstance.h"

UGame_BloodhoundManager* UGame_BloodhoundManager::GlobalInstance = nullptr;

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_BloodhoundManager::UGame_BloodhoundManager() 
{
	if (!HasAnyFlags(RF_ClassDefaultObject))
	{	
		GlobalInstance = this;
	}
}

// ---------------------------------
// --- FTickableObjectBase
// ---------------------------------

bool UGame_BloodhoundManager::IsTickable() const
{
	return BloodhoundUIDRelations.Num() > 0;
}

TStatId UGame_BloodhoundManager::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UBloodhoundManager, STATGROUP_Tickables);
}

void UGame_BloodhoundManager::Tick(float deltaSeconds)
{
	if (AGame_PlayerState* playerState = UGame_Statics::GetLocalPlayerState())
	{
		bool bIsInTOC = playerState->GetIsInTOC();

		for (const TPair<FString, FBloodhoundUIDRelation>& entry : BloodhoundUIDRelations)
		{
			UpdateBloodhoundActors(entry.Value, bIsInTOC);
		}
	}
}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_BloodhoundManager* UGame_BloodhoundManager::Get()
{
	return UGame_BloodhoundManager::GlobalInstance;
}

// ---------------------------------
// --- API
// ---------------------------------

bool UGame_BloodhoundManager::GetBloodhoundEntityUID(AActor* testActor, FString& entityUID) const
{
	if (testActor != nullptr)
	{
		if (AGame_Arrow* arrow = Cast<AGame_Arrow>(testActor->GetOwner()))
		{
			if (AGame_Bloodhound* bloodhound = Cast<AGame_Bloodhound>(arrow->GetOwner()))
			{
				entityUID = UGame_VirtualObjectiveManager::GetObjectEntityUID(bloodhound);

				return true;
			}
		}
	}

	return false;
}

bool UGame_BloodhoundManager::GetBloodhoundInfo(const FString& entityUID, FString& chaserEntityUID, FString& targetEntityUID) const
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		SpatialiteResults results = entityDB->QueryUID(entityUID);
		if (results.Num() > 0)
		{
			TArray<uint8> blob = UDatabase_Spatialite::GetBlob(TEXT("data"), results[0]);

			FMemoryReader fromBinary = FMemoryReader(blob, false);
			fromBinary.Seek(0);

			fromBinary << chaserEntityUID;
			fromBinary << targetEntityUID;

			return true;
		}
	}
	
	return false;
}

void UGame_BloodhoundManager::InsertBloodhound(FString chaserEntityUID, FString targetEntityUID)
{
	if (chaserEntityUID.IsEmpty() || targetEntityUID.IsEmpty())
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_BloodhoundManager::InsertBloodhound | chaser or target entity UID is nullptr | aborting"));

		return;
	}

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		FString entityUID = FGuid::NewGuid().ToString();

		FBufferArchive toBinary;
		toBinary << chaserEntityUID;
		toBinary << targetEntityUID;

		TArray<uint8> data = (TArray<uint8>&)toBinary;

		FGeodeticCoord2D northWestBB;
		FGeodeticCoord2D southEastBB;
		GetBoundingBox(chaserEntityUID, targetEntityUID, northWestBB, southEastBB);

		entityDB->InsertOrUpdate(entityUID, UGame_EntityHandler_Bloodhound::StaticGetClassUID(), TEXT("bloodhound"), northWestBB, southEastBB, data, true, true);

		if (UGame_GameInstance* gi = UGame_GameInstance::Get())
		{
			gi->MUC_AddCreatedEntityUID(FName(*entityUID));
		}
	}
}

void UGame_BloodhoundManager::PageIn(AGame_VirtualObjective* inVO, const FString& inBloodhoundUID, const int32& detailStatus, const TArray<uint8>& inBlobData)
{
	AddBloodhoundUIDRelation(inBloodhoundUID, inBlobData);

	if (FBloodhoundUIDRelation* relation = BloodhoundUIDRelations.Find(inBloodhoundUID))
	{
		relation->PagedInVOs.Add(inVO, detailStatus);
	}
}

void UGame_BloodhoundManager::PageOut(AGame_VirtualObjective* inVO, const FString& inBloodhoundUID)
{
	if (FBloodhoundUIDRelation* relation = BloodhoundUIDRelations.Find(inBloodhoundUID))
	{
		relation->PagedInVOs.Remove(inVO);

		if (relation->PagedInVOs.Num() == 0)
		{
			BloodhoundUIDRelations.Remove(inBloodhoundUID);
		}
	}
}

bool UGame_BloodhoundManager::Initialize()
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->OnInsertOrUpdate.AddDynamic(this, &UGame_BloodhoundManager::HandleInsertOrUpdateEvent);

		entityDB->OnDelete.AddDynamic(this, &UGame_BloodhoundManager::HandleDelete);
	}

	bIsInitialized = true;

	return bIsInitialized;
}

void UGame_BloodhoundManager::Shutdown()
{
	GlobalInstance = nullptr;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_BloodhoundManager::AddBloodhoundUIDRelation(const FString& inBloodhoundUID, const TArray<uint8>& inBlobData)
{
	if (!BloodhoundUIDRelations.Contains(inBloodhoundUID))
	{
		FMemoryReader memoryReader = FMemoryReader(inBlobData, false);
		memoryReader.Seek(0);

		FString chaser_EntityUID;
		FString target_EntityUID;
		memoryReader << chaser_EntityUID;
		memoryReader << target_EntityUID;

		BloodhoundUIDRelations.Add(inBloodhoundUID, FBloodhoundUIDRelation(inBloodhoundUID, target_EntityUID, chaser_EntityUID));
	}
}

bool UGame_BloodhoundManager::ContainsPlayer(const FBloodhoundUIDRelation& relation) const
{
	return relation.ChaserUID.Equals(UGame_EntityHandler_Bloodhound::StaticGetPlayerIdentifier()) || relation.TargetUID.Equals(UGame_EntityHandler_Bloodhound::StaticGetPlayerIdentifier());
}

bool UGame_BloodhoundManager::EntitiesArePagedIn(AGame_VirtualObjective* virtualObjective, const FBloodhoundUIDRelation& relation) const
{
	bool bPagedIn = true;

	if (!relation.ChaserUID.Equals(UGame_EntityHandler_Bloodhound::StaticGetPlayerIdentifier()))
	{
		bPagedIn = virtualObjective->IsEntityPagedIn(relation.ChaserUID);
	}

	if (!relation.TargetUID.Equals(UGame_EntityHandler_Bloodhound::StaticGetPlayerIdentifier()))
	{
		bPagedIn = bPagedIn && virtualObjective->IsEntityPagedIn(relation.TargetUID);
	}

	return  bPagedIn;
}

void UGame_BloodhoundManager::UpdateBloodhoundActors(const FBloodhoundUIDRelation& relation, bool bIsInTOC)
{
	TArray<AGame_VirtualObjective*> outRelationKeys;
	relation.PagedInVOs.GetKeys(outRelationKeys);
	for (AGame_VirtualObjective* virtualObjective : outRelationKeys)
	{
		// if bloodhound contains player, do not allow in TOC and destroy existing bloodhound actors
		if (ContainsPlayer(relation))
		{
			if (bIsInTOC)
			{
				virtualObjective->PageOutEntity(relation.BloodhoundUID);
				continue;
			}
		}

		bool bBloodhoundActorExists = virtualObjective->GetActorsForEntity(relation.BloodhoundUID).Num() > 0;

		// if bloodhound actor not spawned and chaser/target are paged in; spawn bloodhound
		if (!bBloodhoundActorExists && EntitiesArePagedIn(virtualObjective, relation))
		{
			AGame_Bloodhound* bloodhound = UDeveloper_Statics::GetVHWorld()->SpawnActor<AGame_Bloodhound>(BloodhoundActorClass);

			virtualObjective->AddObjectToEntity(relation.BloodhoundUID, bloodhound);

			bloodhound->SetChaser(relation.ChaserUID);
			bloodhound->SetTarget(relation.TargetUID);

			bloodhound->SpawnActors(virtualObjective, relation.PagedInVOs[virtualObjective]);

			virtualObjective->AddObjectToEntity(relation.BloodhoundUID, bloodhound);
		}

		// if chaser or target are not paged in, destroy associated bloodhound actors
		if (bBloodhoundActorExists && !EntitiesArePagedIn(virtualObjective, relation))
		{
			virtualObjective->PageOutEntity(relation.BloodhoundUID);
		}
	}
}

bool UGame_BloodhoundManager::HasEntityUID(const FBloodhoundUIDRelation& relation, const FString& entityUID) const
{
	return relation.ChaserUID.Equals(entityUID) || relation.TargetUID.Equals(entityUID);
}

void UGame_BloodhoundManager::GetBoundingBox(const FString& chaserEntityUID, const FString& targetEntityUID, FGeodeticCoord2D& northWestBB, FGeodeticCoord2D& southEastBB) const
{
	UGame_EntityDB* entityDB = UGame_EntityDB::Get();
	UGame_HandlerService* handlerService = UGame_HandlerService::Get();

	if (entityDB != nullptr && handlerService != nullptr)
	{
		FGeodeticCoord3D coordinate;
		TArray<double> longitudes;
		TArray<double> latitudes;

		if (!chaserEntityUID.Equals(UGame_EntityHandler_Bloodhound::StaticGetPlayerIdentifier()))
		{
			SpatialiteResults results = entityDB->QueryUID(chaserEntityUID);
			if (results.Num() > 0)
			{
				handlerService->GetGoToCoord(results[0], coordinate);

				longitudes.Add(coordinate.Longitude);
				latitudes.Add(coordinate.Latitude);
			}
		}

		if (!targetEntityUID.Equals(UGame_EntityHandler_Bloodhound::StaticGetPlayerIdentifier()))
		{
			SpatialiteResults results = entityDB->QueryUID(targetEntityUID);
			if (results.Num() > 0)
			{
				handlerService->GetGoToCoord(results[0], coordinate);

				longitudes.Add(coordinate.Longitude);
				latitudes.Add(coordinate.Latitude);
			}
		}

		double westLongitude = MAX_dbl;
		double eastLongitude = -181.f;
		double northLatitude = -181.f;
		double southLatitude = MAX_dbl;

		for (int32 i = 0; i < longitudes.Num(); i++)
		{
			westLongitude = FMath::Min<double>(westLongitude, longitudes[i]);
			eastLongitude = FMath::Max<double>(eastLongitude, longitudes[i]);
		}

		for (int32 i = 0; i < latitudes.Num(); i++)
		{
			northLatitude = FMath::Max<double>(northLatitude, latitudes[i]);
			southLatitude = FMath::Min<double>(southLatitude, latitudes[i]);
		}

		northWestBB = FGeodeticCoord2D(westLongitude, northLatitude);
		southEastBB = FGeodeticCoord2D(eastLongitude, southLatitude);
	}
}

void UGame_BloodhoundManager::UpdateBoundingBox(const FBloodhoundUIDRelation& relation)
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		FGeodeticCoord2D northWestBB;
		FGeodeticCoord2D southEastBB;
		GetBoundingBox(relation.ChaserUID, relation.TargetUID, northWestBB, southEastBB);

		entityDB->UpdateBoundingBox(relation.BloodhoundUID, northWestBB, southEastBB);
	}
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_BloodhoundManager::HandleInsertOrUpdateEvent(const FSpatialiteResults_BP& results)
{
	// update existing bloodhound's bounding boxes

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		for (const FSpatialiteResult_BP& result_BP : results.Results)
		{
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result_BP.Result);
			FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result_BP.Result);

			for (const TPair<FString, FBloodhoundUIDRelation>& entry : BloodhoundUIDRelations)
			{
				if (HasEntityUID(entry.Value, entityUID))
				{
					UpdateBoundingBox(entry.Value);
				}
			}
		}
	}
}

void UGame_BloodhoundManager::HandleDelete(const FSpatialiteResults_BP& results)
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		for (const FSpatialiteResult_BP& result_BP : results.Results)
		{
			FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result_BP.Result);
			FString classUID = UDatabase_Spatialite::GetString(TEXT("classUID"), result_BP.Result);

			TArray<FString> toRemove;
			for (const TPair<FString, FBloodhoundUIDRelation>& entry : BloodhoundUIDRelations)
			{
				if (HasEntityUID(entry.Value, entityUID))
				{
					toRemove.Add(entry.Value.BloodhoundUID);
				}
			}

			for (const FString& entityUIDToRemove : toRemove)
			{
				entityDB->Delete(UGame_EntityHandler_Bloodhound::StaticGetClassUID(), entityUIDToRemove, false);

				BloodhoundUIDRelations.Remove(entityUIDToRemove);
			}
		}
	}
}
