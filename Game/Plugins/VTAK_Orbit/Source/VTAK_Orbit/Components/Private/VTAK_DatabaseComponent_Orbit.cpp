// Required includes
#include "VTAK_DatabaseComponent_Orbit.h"

// Engine Includes
#include "Serialization/BufferArchive.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"

// Game Includes
#include "Game_EntityDB.h"
#include "Game_PlayerController.h"
#include "Game_VirtualObjective.h"
#include "Game_VirtualObjectiveManager.h"

// Module Includes
#include "VTAK_Actor_Orbit.h"
#include "VTAK_EntityHandler_Orbit.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UVTAK_DatabaseComponent_Orbit::UVTAK_DatabaseComponent_Orbit()
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

FString UVTAK_DatabaseComponent_Orbit::GetEntityUID()
{
	// there is only ever be one orbit entity
	return TEXT("orbitEntityUID");
}

FString UVTAK_DatabaseComponent_Orbit::GetCategoryID()
{
	return TEXT("orbit");
}

bool UVTAK_DatabaseComponent_Orbit::GetData(FGeodeticCoord3D& coordinate, double& radius, double& speed)
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		SpatialiteResults results = entityDB->QueryUID(GetEntityUID());
		if (results.Num() > 0)
		{
			SpatialiteResult result = results[0];

			TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);

			FMemoryReader memoryReader = FMemoryReader(blobData, false);
			memoryReader.Seek(0);

			memoryReader << coordinate;
			memoryReader << radius;
			memoryReader << speed;

			return true;
		}
	}

	return false;
}

void UVTAK_DatabaseComponent_Orbit::SetCoordinate(const FGeodeticCoord3D& coordinate)
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		FString entityUID = GetEntityUID();
		SpatialiteResults results = entityDB->QueryUID(entityUID);
		if (results.Num() > 0)
		{
			// update database
			SpatialiteResult result = results[0];

			TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);

			FMemoryReader memoryReader = FMemoryReader(blobData, false);
			memoryReader.Seek(0);

			FGeodeticCoord3D coordinateDB;
			double radius;
			double speed;
				
			memoryReader << coordinateDB;
			memoryReader << radius;
			memoryReader << speed;

			FBufferArchive toBinary;

			coordinateDB = coordinate;
			toBinary << coordinateDB;
			toBinary << radius;
			toBinary << speed;

			TArray<uint8> data = (TArray<uint8>&)toBinary;

			FGeodeticCoord2D boundingBoxPoint = coordinate.ToGeodeticCoord2D();
			entityDB->InsertOrUpdate(entityUID, UVTAK_EntityHandler_Orbit::StaticGetClassUID(), FName(*GetCategoryID()), boundingBoxPoint, boundingBoxPoint, data, true, true);

			// update actor if it's paged in
			if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
			{
				voManager->UpdateEntityGlobal(GetEntityUID());
			}
		}
	}
}

void UVTAK_DatabaseComponent_Orbit::SetRadius(double radius)
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		FString entityUID = GetEntityUID();
		SpatialiteResults results = entityDB->QueryUID(entityUID);
		if (results.Num() > 0)
		{
			// update database
			SpatialiteResult result = results[0];

			TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);

			FMemoryReader memoryReader = FMemoryReader(blobData, false);
			memoryReader.Seek(0);

			FGeodeticCoord3D coordinate;
			double radiusDB;
			double speed;
				
			memoryReader << coordinate;
			memoryReader << radiusDB;
			memoryReader << speed;

			FBufferArchive toBinary;

			radiusDB = radius;
			toBinary << coordinate;
			toBinary << radiusDB;
			toBinary << speed;

			TArray<uint8> data = (TArray<uint8>&)toBinary;

			FGeodeticCoord2D boundingBoxPoint = coordinate.ToGeodeticCoord2D();
			entityDB->InsertOrUpdate(entityUID, UVTAK_EntityHandler_Orbit::StaticGetClassUID(), FName(*GetCategoryID()), boundingBoxPoint, boundingBoxPoint, data, true, true);

			// update actor if it's paged in
			if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
			{
				voManager->UpdateEntityGlobal(GetEntityUID());
			}
		}
	}
}

void UVTAK_DatabaseComponent_Orbit::SetSpeed(double speed)
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		FString entityUID = GetEntityUID();
		SpatialiteResults results = entityDB->QueryUID(entityUID);
		if (results.Num() > 0)
		{
			// update database
			SpatialiteResult result = results[0];

			TArray<uint8> blobData = UDatabase_Spatialite::GetBlob(TEXT("data"), result);

			FMemoryReader memoryReader = FMemoryReader(blobData, false);
			memoryReader.Seek(0);

			FGeodeticCoord3D coordinate;
			double radius;
			double speedDB;
				
			memoryReader << coordinate;
			memoryReader << radius;
			memoryReader << speedDB;

			FBufferArchive toBinary;

			speedDB = speed;
			toBinary << coordinate;
			toBinary << radius;
			toBinary << speedDB;

			TArray<uint8> data = (TArray<uint8>&)toBinary;

			FGeodeticCoord2D boundingBoxPoint = coordinate.ToGeodeticCoord2D();
			entityDB->InsertOrUpdate(entityUID, UVTAK_EntityHandler_Orbit::StaticGetClassUID(), FName(*GetCategoryID()), boundingBoxPoint, boundingBoxPoint, data, true, true);

			// update actor if it's paged in
			if (UGame_VirtualObjectiveManager* voManager = UGame_VirtualObjectiveManager::Get())
			{
				voManager->UpdateEntityGlobal(GetEntityUID());
			}
		}
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UVTAK_DatabaseComponent_Orbit::Delete()
{
	if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
	{
		entityDB->Delete(UVTAK_EntityHandler_Orbit::StaticGetClassUID(), GetEntityUID(), true);
	}
}

void UVTAK_DatabaseComponent_Orbit::Insert()
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
		{
			AVTAK_Actor_Orbit* orbit = Cast<AVTAK_Actor_Orbit>(GetOwner());
			UGame_EntityDB* entityDB = UGame_EntityDB::Get();

			if (orbit != nullptr && entityDB != nullptr)
			{
				FString entityUID = GetEntityUID();  

				FGeodeticCoord3D coordinate = globeReference->WorldToGeodeticDouble(orbit->GetActorLocation());

				double radius = orbit->RadiusMeters;
				double speed = orbit->SpeedMetersPerSecond;

				FBufferArchive toBinary;

				toBinary << coordinate;
				toBinary << radius;
				toBinary << speed;

				TArray<uint8> data = (TArray<uint8>&)toBinary;

				virtualObjective->AddObjectToEntity(entityUID, GetOwner());

				FGeodeticCoord2D boundingBoxPoint = coordinate.ToGeodeticCoord2D();
				entityDB->InsertOrUpdate(entityUID, UVTAK_EntityHandler_Orbit::StaticGetClassUID(), FName(*GetCategoryID()), boundingBoxPoint, boundingBoxPoint, data, true, true);

				virtualObjective->SetScaleFor(entityUID);
			}
		}
	}
}

void UVTAK_DatabaseComponent_Orbit::Update(AGame_VirtualObjective* virtualObjective, const TArray<uint8>& blobData)
{
	if (AVTAK_Actor_Orbit* orbitActor = Cast<AVTAK_Actor_Orbit>(GetOwner()))
	{
		FMemoryReader memoryReader = FMemoryReader(blobData, false);
		memoryReader.Seek(0);

		FGeodeticCoord3D coordinate;
		double radius;
		double speed;
				
		memoryReader << coordinate;
		memoryReader << radius;
		memoryReader << speed;

		if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
		{
			orbitActor->SetActorLocation(globeReference->GeodeticToWorldDouble(coordinate));
		}

		orbitActor->RadiusMeters = radius;
		orbitActor->SpeedMetersPerSecond = speed;
	}
}

void UVTAK_DatabaseComponent_Orbit::PageIn(const FString& entityUID, const TArray<uint8>& blobData)
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
		{
			if (AVTAK_Actor_Orbit* orbit = Cast<AVTAK_Actor_Orbit>(GetOwner()))
			{
				FMemoryReader memoryReader = FMemoryReader(blobData, false);
				memoryReader.Seek(0);

				FGeodeticCoord3D coordinate;
				double radius;
				double speed;
				
				memoryReader << coordinate;
				memoryReader << radius;
				memoryReader << speed;

				orbit->SetActorLocation(globeReference->GeodeticToWorldDouble(coordinate));
				orbit->RadiusMeters = radius;
				orbit->SpeedMetersPerSecond = speed;
			}
		}
    }
}

void UVTAK_DatabaseComponent_Orbit::PageOut()
{
	Insert();

	// Owner should be the orbit entity
	if (AActor* owner = GetOwner())
	{
		owner->Destroy();
	}
}

void UVTAK_DatabaseComponent_Orbit::PreModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference)
{
	AActor* owner = GetOwner();
	if (owner && globeReference)
	{
		FGeodeticCoord3D coord = globeReference->WorldToGeodeticDouble(owner->GetActorLocation());

		ActorToLocation.Add(owner, coord);
	}
}

void UVTAK_DatabaseComponent_Orbit::PostModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference)
{
	if (globeReference)
	{
		for (const TPair<AActor*, FGeodeticCoord3D>& entry : ActorToLocation)
		{
			if (AActor* owner = entry.Key)
			{
				FVector worldLocation = globeReference->GeodeticToWorldDouble(entry.Value);

				owner->SetActorLocation(worldLocation);
			}
		}

		ActorToLocation.Empty();
	}
}

void UVTAK_DatabaseComponent_Orbit::SetScale3D(const FVector& scale3D)
{
	// Owner should be the orbit entity
	if (AActor* owner = GetOwner())
	{
		owner->SetActorScale3D(scale3D);
	}
}