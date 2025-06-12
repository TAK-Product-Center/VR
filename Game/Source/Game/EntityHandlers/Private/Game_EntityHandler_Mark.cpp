#include "Game_EntityHandler_Mark.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_DatabaseComponent_Mark.h"
#include "Game_EntityDB.h"

#include "VH_GlobeReferenceActor.h"
#include "Developer_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_EntityHandler_Mark::UGame_EntityHandler_Mark()
{
}

// ---------------------------------
// --- Interface_EntityHandler
// ---------------------------------

void UGame_EntityHandler_Mark::UpdateEntity_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	
	PageOutEntity(virtualObjective, entityUID);

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->LoadEntity(virtualObjective, entityUID);
	}
}

void UGame_EntityHandler_Mark::SetEntityDetailStatus_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, int32 detailStatus)
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

void UGame_EntityHandler_Mark::SetEntityVisibility_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, bool bVisible)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	
	if (UGame_DatabaseComponent_Mark* databaseComponent = GetDatabaseComponent(virtualObjective, entityUID))
	{
		databaseComponent->GetOwner()->SetActorHiddenInGame(!bVisible);
	}
}

void UGame_EntityHandler_Mark::GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues)
{
    keyValues.Add(TEXT("displayName"), TEXT("Red X"));
}

void UGame_EntityHandler_Mark::DeleteEntity_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	
	PageOutEntity(virtualObjective, entityUID);
}

void UGame_EntityHandler_Mark::SetEntityScale3D_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FVector& scale3D)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	
	if (UGame_DatabaseComponent_Mark* databaseComponent = GetDatabaseComponent(virtualObjective, entityUID))
	{
		databaseComponent->SetScale3D(scale3D);
	}
}

void UGame_EntityHandler_Mark::PreModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	
	if (UGame_DatabaseComponent_Mark* databaseComponent = GetDatabaseComponent(virtualObjective, entityUID))
	{
		databaseComponent->PreModifyVOGlobeReference(virtualObjective->GetGlobeReference());
	}
}

void UGame_EntityHandler_Mark::PostModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);
	
	if (UGame_DatabaseComponent_Mark* databaseComponent = GetDatabaseComponent(virtualObjective, entityUID))
	{
		databaseComponent->PostModifyVOGlobeReference(virtualObjective->GetGlobeReference());
	}
}

void UGame_EntityHandler_Mark::SnapEntityToGround_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{

}

void UGame_EntityHandler_Mark::GetGoToCoord_Implementation(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate)
{
	TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);
	
	FMemoryReader memoryReader = FMemoryReader(blobData, false);
	memoryReader.Seek(0);

	memoryReader << coordinate.Longitude;
	memoryReader << coordinate.Latitude;
	memoryReader << coordinate.Altitude;
}

TMap<FString, FString> UGame_EntityHandler_Mark::GetHashesToSyncForMUC_Implementation(const FSpatialiteResult_BP& result)
{
	TMap<FString, FString> hashes;

	return hashes;
}

// ---------------------------------
// --- Implementation Methods
// ---------------------------------

void UGame_EntityHandler_Mark::PageInEntity(AGame_VirtualObjective* virtualObjective, const FString& entityUID, const TArray<uint8>& blobData)
{
	if (virtualObjective->IsEntityPagedIn(entityUID))
	{
		return;
	}

	AActor* actor = UDeveloper_Statics::GetVHWorld()->SpawnActor<AActor>(MarkTargetClass);

	if (UGame_DatabaseComponent_Mark* databaseComponent = Cast<UGame_DatabaseComponent_Mark>(actor->GetComponentByClass(UGame_DatabaseComponent_Mark::StaticClass())))
	{
		virtualObjective->AddObjectToEntity(entityUID, actor);

		databaseComponent->PageIn(entityUID, blobData);
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_EntityHandler_Mark::PageInEntity | MarkTargetClass does not have a Game_DatabaseComponent_Mark"));
	}
}

void UGame_EntityHandler_Mark::PageOutEntity(AGame_VirtualObjective* virtualObjective, const FString& entityUID)
{
	if (UGame_DatabaseComponent_Mark* databaseComponent = GetDatabaseComponent(virtualObjective, entityUID))
	{
		databaseComponent->PageOut();
	}

	virtualObjective->PageOutEntity(entityUID);
}

UGame_DatabaseComponent_Mark* UGame_EntityHandler_Mark::GetDatabaseComponent(AGame_VirtualObjective* virtualObjective, const FString& entityUID) const
{
	TSet<AActor*> actors = virtualObjective->GetActorsForEntity(entityUID);

	TArray<AActor*> actorsArray = actors.Array();

	if (actorsArray.Num() > 0)
	{
		if (UGame_DatabaseComponent_Mark* databaseComponent = Cast<UGame_DatabaseComponent_Mark>(actorsArray[0]->GetComponentByClass(UGame_DatabaseComponent_Mark::StaticClass())))
		{
			return databaseComponent;
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_DatabaseComponent_Mark::GetDatabaseComponent | MarkTargetClass does not have a Game_DatabaseComponent_Mark"));
		}
	}

	return nullptr;
}