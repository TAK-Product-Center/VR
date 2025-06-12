#include "Game_DatabaseComponent_Mark.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_EntityDB.h"
#include "Game_Mark.h"
#include "Game_PlayerController.h"
#include "Game_EntityHandler_Mark.h"
#include "Game_Statics.h"
#include "Game_MUCComponent_Database.h"

#include "VH_GlobeReferenceActor.h"
#include "VH_GeodeticCoord.h"

#include "Runtime/Core/Public/Misc/Guid.h"
#include "Serialization/BufferArchive.h"

UGame_DatabaseComponent_Mark::UGame_DatabaseComponent_Mark() :
    CategoryID(TEXT("Red X"))
{
}

void UGame_DatabaseComponent_Mark::Insert()
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

			TArray<uint8> data = (TArray<uint8>&)toBinary;

			if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
			{
				activeVO->AddObjectToEntity(EntityUID, GetOwner());

				entityDB->InsertOrUpdate(EntityUID, UGame_EntityHandler_Mark::StaticGetClassUID(), CategoryID, boundingBoxPoint, boundingBoxPoint, data, true, true);

				activeVO->SetScaleFor(EntityUID);
			}
		}
	}
}

void UGame_DatabaseComponent_Mark::Delete()
{
	if (UGame_Statics::IsLocalPlayerInSession())
	{
		UGame_MUCComponent_Database::MUCDelete(FName(*EntityUID), true);
	}
	else
	{
		if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
		{
			entityDB->Delete(UGame_EntityHandler_Mark::StaticGetClassUID(), EntityUID, true);
		}
	}
}

void UGame_DatabaseComponent_Mark::PageIn(const FString& entityUID, const TArray<uint8>& blobData)
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
			
        FVector worldLocation;
		worldLocation = globeRef->GeodeticToWorldDouble(FGeodeticCoord3D(longitude, latitude, altitude));
        GetOwner()->SetActorLocation(worldLocation);

		if (AGame_PlayerController* pc = UGame_Statics::GetVHPlayerController())
		{
			FString redXEntityUID = TEXT("");
			pc->GetRedX(redXEntityUID);

			if (redXEntityUID.Equals(EntityUID))
			{
				pc->SetRedX(Cast<AGame_Mark>(GetOwner()));
			}
		}
    }
}

void UGame_DatabaseComponent_Mark::PageOut()
{
	if (AGame_PlayerController* pc = UGame_Statics::GetVHPlayerController())
	{
		FString entityUID = TEXT("");
		AGame_Mark* redX = pc->GetRedX(entityUID);

		if (entityUID.Equals(EntityUID))
		{
			pc->SetRedX(nullptr);
		}
	}

    GetOwner()->Destroy();
}

void UGame_DatabaseComponent_Mark::SetScale3D(const FVector& scale3D)
{
	GetOwner()->SetActorScale3D(scale3D);
}

void UGame_DatabaseComponent_Mark::PreModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference)
{
	FGeodeticCoord3D coord = globeReference->WorldToGeodeticDouble(GetOwner()->GetActorLocation());

	ActorToLocation.Add(GetOwner(), coord);
}

void UGame_DatabaseComponent_Mark::PostModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference)
{
	for (const TPair<AActor*, FGeodeticCoord3D>& entry : ActorToLocation)
	{
		FVector worldLocation = globeReference->GeodeticToWorldDouble(entry.Value);

		entry.Key->SetActorLocation(worldLocation);
	}

	ActorToLocation.Empty();
}
