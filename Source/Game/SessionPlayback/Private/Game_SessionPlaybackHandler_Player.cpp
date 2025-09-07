// Required Includes
#include "Game_SessionPlaybackHandler_Player.h"
#include "Game.h"

// Engine Includes
#include "Serialization/BufferArchive.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "Developer_Statics.h"

// Game Includes
#include "Game_SessionPlayback_Impl.h"
#include "Game_EntityDB.h"
#include "Game_VirtualObjective.h"
#include "Game_Pawn.h"
#include "Game_PlayerState.h"
#include "Game_PlayerController.h"
#include "Game_SessionPlaybackAvatar.h"
#include "Game_Statics.h"
#include "Game_GameMode.h"
#include "Game_CameraComponent.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_SessionPlaybackHandler_Player::UGame_SessionPlaybackHandler_Player()
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

FString UGame_SessionPlaybackHandler_Player::GetHandlerUIDStatic()
{
	return TEXT("sessionplayback.handler.player");
}

// ---------------------------------
// --- Interface_SessionPlaybackHandler
// ---------------------------------

FString UGame_SessionPlaybackHandler_Player::GetHandlerUID_Implementation() const
{
	return GetHandlerUIDStatic();
}

void UGame_SessionPlaybackHandler_Player::SetImpl_Implementation(UGame_SessionPlayback_Impl* impl)
{
	Implementation = impl;
}

void UGame_SessionPlaybackHandler_Player::ApplyEvent_Implementation(const FSpatialiteResult_BP& result)
{
	AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO();

	UGame_EntityDB* entityDB = UGame_EntityDB::Get();

	if (virtualObjective != nullptr && entityDB != nullptr)
	{
		TArray<uint8> data = UDatabase_Spatialite::GetBlob(TEXT("data"), result.Result);

		FMemoryReader fromBinary = FMemoryReader(data);
		fromBinary.Seek(0);

		FString type;
		fromBinary << type;

		int32 playerID;
		fromBinary << playerID;

		FString callsign;
		fromBinary << callsign;

		if (type.Equals(TEXT("headLocation")))
		{
			FRotator rotation;
			fromBinary << rotation;

			AGame_SessionPlaybackAvatar* avatar = GetAvatar(playerID);
			avatar->SetHeadRotation(rotation);
			avatar->SetCallsign(callsign);
		}
		else if (type.Equals(TEXT("pawnLocation")))
		{
			FGeodeticCoord3D coordinate;
			fromBinary << coordinate;

			FRotator rotation;
			fromBinary << rotation;

			AGame_SessionPlaybackAvatar* avatar = GetAvatar(playerID);
			avatar->SetTargetRotation(rotation);
			avatar->SetCallsign(callsign);

			if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
			{
				avatar->SetTargetPosition(globeReference->GeodeticToWorldDouble(coordinate));
			}
		}
		else
		{
			FString controllerName;
			fromBinary << controllerName;

			FTransform transform;
			fromBinary << transform;

			AGame_SessionPlaybackAvatar* avatar = GetAvatar(playerID);
			avatar->SetCallsign(callsign);
			avatar->SetControllerTransform(controllerName, transform);
		}
	}
}

void UGame_SessionPlaybackHandler_Player::StartRecord_Implementation()
{

}

void UGame_SessionPlaybackHandler_Player::StopRecord_Implementation()
{

}

void UGame_SessionPlaybackHandler_Player::SetSecondsPassed_Implementation(float secondsPassed)
{
	DestroyAvatars();
}

void UGame_SessionPlaybackHandler_Player::UnloadPlayback_Implementation()
{
	DestroyAvatars();
}

void UGame_SessionPlaybackHandler_Player::FilterSetSecondsPassedResults_Implementation(FSpatialiteResults_BP& results)
{
	FString handlerUID = IInterface_SessionPlaybackHandler::Execute_GetHandlerUID(this);

	// keep the most recent result for each playerID, for each type; remove the rest
	TMap<int32, TSet<FString>> playerIDToTypes;
	for (int32 i = 0; i < results.Results.Num(); i++)
	{
		if (UDatabase_Spatialite::GetString(TEXT("handlerUID"), results.Results[i]).Equals(handlerUID))
		{
			TArray<uint8> data = UDatabase_Spatialite::GetBlob(TEXT("data"), results.Results[i]);

			FMemoryReader fromBinary = FMemoryReader(data);
			fromBinary.Seek(0);

			FString type;
			fromBinary << type;

			int32 playerID;
			fromBinary << playerID;

			if (TSet<FString>* typesPtr = playerIDToTypes.Find(playerID))
			{
				TSet<FString> types = *typesPtr;
				if (types.Contains(type))
				{
					results.Results.RemoveAt(i, 1);
					i--;
				}
				else
				{
					// playerID exists, but haven't see this type yet
					types.Add(type);
					playerIDToTypes.Add(playerID, types);
				}
			}
			else
			{
				// playerID does not exist
				TSet<FString> types;
				types.Add(type);

				playerIDToTypes.Add(playerID, types);
			}
		}
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_SessionPlaybackHandler_Player::AddPawnLocationEvent(const AGame_Pawn* pawn, const FGeodeticCoord3D& coordinate) const
{
	int32 playerID;
	FString callsign;
	if (GetPlayerInfoFromPawn(pawn, playerID, callsign))
	{
		FString type = TEXT("pawnLocation");

		FGeodeticCoord3D coordinateForBinary = coordinate;

		FQuat rotationForBinary = pawn->Camera->GetComponentQuat();

		FBufferArchive toBinary;
		toBinary << type;
		toBinary << playerID;
		toBinary << callsign;
		toBinary << coordinateForBinary;
		toBinary << rotationForBinary;

		TArray<uint8> data = (TArray<uint8>&)toBinary;

		FString handlerUID = IInterface_SessionPlaybackHandler::Execute_GetHandlerUID(this);
		Implementation->AddEvent(handlerUID, data);
	}
}

void UGame_SessionPlaybackHandler_Player::AddHeadPositionEvent(const AGame_Pawn* pawn, const FQuat& rotation) const
{
	int32 playerID;
	FString callsign;
	if (GetPlayerInfoFromPawn(pawn, playerID, callsign))
	{
		FString type = TEXT("headLocation");

		FQuat rotationForBinary = rotation;

		FBufferArchive toBinary;
		toBinary << type;
		toBinary << playerID;
		toBinary << callsign;
		toBinary << rotationForBinary;

		TArray<uint8> data = (TArray<uint8>&)toBinary;
		
		FString handlerUID = IInterface_SessionPlaybackHandler::Execute_GetHandlerUID(this);
		Implementation->AddEvent(handlerUID, data);
	}
}

void UGame_SessionPlaybackHandler_Player::AddControllerOffsetEvent(const AGame_Pawn* pawn, const FString& controllerName, const FTransform& transform) const
{
	int32 playerID;
	FString callsign;
	if (GetPlayerInfoFromPawn(pawn, playerID, callsign))
	{
		FString type = TEXT("controllerOffset");

		FTransform transformForBinary = transform;

		FString controllerNameForBinary = controllerName;

		FBufferArchive toBinary;
		toBinary << type;
		toBinary << playerID;
		toBinary << callsign;
		toBinary << controllerNameForBinary;
		toBinary << transformForBinary;

		TArray<uint8> data = (TArray<uint8>&)toBinary;

		FString handlerUID = IInterface_SessionPlaybackHandler::Execute_GetHandlerUID(this);
		Implementation->AddEvent(handlerUID, data);
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_SessionPlaybackHandler_Player::DestroyAvatars()
{
	for (const TPair<int32, AGame_SessionPlaybackAvatar*>& entry : Avatars)
	{
		entry.Value->SetActorHiddenInGame(true);

		entry.Value->Destroy();
	}

	Avatars.Empty();
}

AGame_SessionPlaybackAvatar* UGame_SessionPlaybackHandler_Player::GetAvatar(int32 playerID)
{
	AGame_SessionPlaybackAvatar* avatar = nullptr;

	if (AGame_SessionPlaybackAvatar** avatarPtr = Avatars.Find(playerID))
	{
		avatar = *avatarPtr;
	}
	else
	{
		FActorSpawnParameters spawnInfo;
		spawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		avatar = Cast<AGame_SessionPlaybackAvatar>(UDeveloper_Statics::GetVHWorld()->SpawnActor(GetPlaybackAvatarClass(), nullptr, nullptr, spawnInfo));

		Avatars.Add(playerID, avatar);
	}

	return avatar;
}

TSubclassOf<AGame_SessionPlaybackAvatar> UGame_SessionPlaybackHandler_Player::GetPlaybackAvatarClass() const
{
	if (AGame_GameMode* gameMode = UGame_Statics::GetVHGameMode())
	{
		return gameMode->SessionPlaybackAvatarClass;
	}

	UE_LOG(Game, Warning, TEXT("-- UGame_SessionPlaybackHandler_Player::GetPlaybackAvatarClass | gameMode is nullptr | returning AGame_SessionPlaybackAvatar::StaticClass()"));

	return AGame_SessionPlaybackAvatar::StaticClass();
}

bool UGame_SessionPlaybackHandler_Player::GetPlayerInfoFromPawn(const AGame_Pawn* pawn, int32& playerID, FString& callsign) const
{
	if (AGame_PlayerState* playerState = Cast<AGame_PlayerState>(pawn->GetPlayerState()))
	{
		playerID = playerState->GetPlayerId();

		callsign = playerState->GetCallsign();

		return true;
	}

	return false;
}
