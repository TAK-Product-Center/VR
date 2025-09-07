#include "Game_DatabaseComponent_LOS.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_EntityDB.h"
#include "Game_EntityHandler_LOS.h"
#include "Game_GameInstance.h"
#include "Game_Statics.h"
#include "Game_PlayerController.h"
#include "Game_MUCComponent_Database.h"

#include "VH_GlobeReferenceActor.h"
#include "VH_GeodeticCoord.h"

#include "Runtime/Core/Public/Misc/Guid.h"
#include "Serialization/BufferArchive.h"

UGame_DatabaseComponent_LOS::UGame_DatabaseComponent_LOS() :
    CategoryID(TEXT("LOS"))
{
}

void UGame_DatabaseComponent_LOS::Insert(const TArray<AActor*>& viewpoints, int32 stance)
{
	if (AGame_VirtualObjective* activeVO = AGame_PlayerController::GetPlayerActiveVO())
	{
		if (AVH_GlobeReferenceActor* globeRef = activeVO->GetGlobeReference())
		{
			// generate entity UID if needed
			if (EntityUID.IsEmpty())
			{
				EntityUID = FGuid::NewGuid().ToString();
			}

			AActor* target = GetOwner();

			FGeodeticCoord3D geoLocation = globeRef->WorldToGeodeticDouble(target->GetActorLocation());
			FGeodeticCoord2D boundingBoxPoint = geoLocation.ToGeodeticCoord2D();

			FBufferArchive toBinary;
			toBinary << geoLocation.Longitude;
			toBinary << geoLocation.Latitude;
			toBinary << geoLocation.Altitude;

			FRotator rotation = target->GetActorRotation();
			toBinary << rotation;

			toBinary << stance;

			int32 numViewpoints = viewpoints.Num();
			toBinary << numViewpoints;

			// add each viewpoint's location and rotation
			for (AActor* currentActor : viewpoints)
			{
				geoLocation = globeRef->WorldToGeodeticDouble(currentActor->GetActorLocation());

				toBinary << geoLocation.Longitude;
				toBinary << geoLocation.Latitude;
				toBinary << geoLocation.Altitude;

				rotation = currentActor->GetActorRotation();
				toBinary << rotation;
			}

			TArray<uint8> data = (TArray<uint8>&)toBinary;

			if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
			{
				activeVO->AddObjectToEntity(EntityUID, GetOwner());

				entityDB->InsertOrUpdate(EntityUID, UGame_EntityHandler_LOS::StaticGetClassUID(), CategoryID, boundingBoxPoint, boundingBoxPoint, data, true, true);

				activeVO->SetScaleFor(EntityUID);
			}

			if (UGame_GameInstance* gi = UGame_GameInstance::Get())
			{
				gi->MUC_AddCreatedEntityUID(FName(*EntityUID));
			}
		}
    }
}

void UGame_DatabaseComponent_LOS::Delete()
{
	if (UGame_Statics::IsLocalPlayerInSession())
	{
		UGame_MUCComponent_Database::MUCDelete(FName(*EntityUID), true);
	}
	else
	{
		if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
		{
			entityDB->Delete(UGame_EntityHandler_LOS::StaticGetClassUID(), EntityUID, true);
		}
	}
}

void UGame_DatabaseComponent_LOS::PageIn(const FString& entityUID, const TArray<uint8>& blobData)
{
	if (AVH_GlobeReferenceActor* globeRef = UGame_VirtualObjectiveManager::GetObjectGlobeReference(GetOwner()))
	{
        EntityUID = entityUID;

        FMemoryReader memoryReader = FMemoryReader(blobData, false);
        memoryReader.Seek(0);

        double longitude;
		double latitude;
		double altitude;

        // TODO: Save/load FGeodeticCoord3D instead.  This would also include the bIsAltitudeRelativeToGround flag!
        memoryReader << longitude;
        memoryReader << latitude;
        memoryReader << altitude;

        FRotator rotation;
        memoryReader << rotation;

        FVector worldLocation;
		worldLocation = globeRef->GeodeticToWorldDouble(FGeodeticCoord3D(longitude, latitude, altitude));
        GetOwner()->SetActorLocation(worldLocation);
        GetOwner()->SetActorRotation(rotation);

        int32 stance;
        memoryReader << stance;

        int32 numViewpoints;
        memoryReader << numViewpoints;

        for (auto i = 0; i < numViewpoints; i++)
        {
			// TODO: Save/load FGeodeticCoord3D instead.  This would also include the bIsAltitudeRelativeToGround flag!
			memoryReader << longitude;
            memoryReader << latitude;
            memoryReader << altitude;

            memoryReader << rotation;

			worldLocation = globeRef->GeodeticToWorldDouble(FGeodeticCoord3D(longitude, latitude, altitude));
			SpawnViewpoint(worldLocation, rotation, false);
        }

        SetStance(stance, false);
    }
}

void UGame_DatabaseComponent_LOS::PageOut()
{
    GetOwner()->Destroy();
}

void UGame_DatabaseComponent_LOS::SetScale3D(const FVector& scale3D)
{
	TArray<AActor*> actors = GetGlobeReferenceActors();

	for (AActor* actor : actors)
	{
		actor->SetActorScale3D(scale3D);
	}
}

void UGame_DatabaseComponent_LOS::PreModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference)
{
	TArray<AActor*> actors = GetGlobeReferenceActors();

	for (AActor* actor : actors)
	{
		FGeodeticCoord3D coord = globeReference->WorldToGeodeticDouble(actor->GetActorLocation());
		ActorToLocation.Add(actor, coord);
	}
}

void UGame_DatabaseComponent_LOS::PostModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference)
{
	for (const TPair<AActor*, FGeodeticCoord3D>& entry : ActorToLocation)
	{
		FVector worldLocation = globeReference->GeodeticToWorldDouble(entry.Value);

		entry.Key->SetActorLocation(worldLocation);
	}

	ActorToLocation.Empty();
}