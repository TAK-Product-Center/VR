// Required Includes
#include "Game_EntityHandler_Viewshed.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "Developer_Statics.h"

// Game Includes
#include "Game_VirtualObjective.h"
#include "Game_EntityDB.h"
#include "Game_Actor_Viewshed.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_EntityHandler_Viewshed::UGame_EntityHandler_Viewshed() :
	ViewshedActorClass(AGame_Actor_Viewshed::StaticClass())
{
}

// ---------------------------------
// --- Interface_EntityHandler
// ---------------------------------

TMap<FString, FString> UGame_EntityHandler_Viewshed::GetHashesToSyncForMUC_Implementation(const FSpatialiteResult_BP& result)
{
	return TMap<FString, FString>();
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_EntityHandler_Viewshed::GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues)
{
	Super::GetEntityOverlayInfo_Implementation(result, keyValues);

	keyValues.Add(TEXT("displayName"), TEXT("Viewshed"));
}

void UGame_EntityHandler_Viewshed::SnapEntityToGround_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	PageOutEntity(virtualObjective, result);

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

		entityDB->LoadEntity(virtualObjective, entityUID);
	}
}

void UGame_EntityHandler_Viewshed::PreModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	
}

void UGame_EntityHandler_Viewshed::PostModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	PageOutEntity(virtualObjective, result);

	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

		entityDB->LoadEntity(virtualObjective, entityUID);
	}
}

void UGame_EntityHandler_Viewshed::SetEntityScale3D_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FVector& scale3D)
{

}

void UGame_EntityHandler_Viewshed::PageInEntity(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result)
{
	FString entityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

	if (virtualObjective->IsEntityPagedIn(entityUID))
	{
		return;
	}

	if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
	{
		// pull parameters from blobData
		TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);

		FMemoryReader fromBinary = FMemoryReader(blobData);
		fromBinary.Seek(0);

		FGeodeticCoord3D coordinate;
		fromBinary << coordinate;

		int32 gridX;
		fromBinary << gridX;

		int32 gridY;
		fromBinary << gridY;

		double radiusMeters;
		fromBinary << radiusMeters;

		int32 pointsPerBeam;
		fromBinary << pointsPerBeam;

		double pointSize;
		fromBinary << pointSize;

		bool bTraceGround;
		fromBinary << bTraceGround;

		// spawn AGame_Actor_Viewshed
		FActorSpawnParameters spawnParams;
		spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		AGame_Actor_Viewshed* viewshedActor = UDeveloper_Statics::GetVHWorld()->SpawnActor<AGame_Actor_Viewshed>(ViewshedActorClass, spawnParams);

		viewshedActor->SetActorLocation(globeReference->GeodeticToWorldDouble(coordinate));

		virtualObjective->AddObjectToEntity(entityUID, viewshedActor);

		// pass parameters to AGame_Actor_Viewshed
		viewshedActor->CreateViewshedPointCloud(entityUID, coordinate, gridX, gridY, radiusMeters, pointsPerBeam, pointSize, bTraceGround);
	}
}