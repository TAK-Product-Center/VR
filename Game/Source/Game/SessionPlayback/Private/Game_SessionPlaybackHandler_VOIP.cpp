#include "Game_SessionPlaybackHandler_VOIP.h"

#include "Engine/VoiceChannel.h"
#include "Engine/NetConnection.h"
#include "Serialization/BufferArchive.h"

#include "Developer_Statics.h"

#include "Game_SessionPlayback_Impl.h"
#include "Game_PlayerController.h"
#include "Game_Statics.h"
#include "Game.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_SessionPlaybackHandler_VOIP::UGame_SessionPlaybackHandler_VOIP()
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

FString UGame_SessionPlaybackHandler_VOIP::GetHandlerUIDStatic()
{
	return TEXT("sessionplayback.handler.voip");
}

// ---------------------------------
// --- Interface_SessionPlaybackHandler
// ---------------------------------

FString UGame_SessionPlaybackHandler_VOIP::GetHandlerUID_Implementation() const
{
	return GetHandlerUIDStatic();
}

void UGame_SessionPlaybackHandler_VOIP::SetImpl_Implementation(UGame_SessionPlayback_Impl* impl)
{
	Implementation = impl;
}

void UGame_SessionPlaybackHandler_VOIP::ApplyEvent_Implementation(const FSpatialiteResult_BP& result)
{
	IOnlineVoicePtr voiceInt = Online::GetVoiceInterface();
	if (voiceInt.IsValid())
	{
		TArray<uint8> data = UDatabase_Spatialite::GetBlob(TEXT("data"), result.Result);

		FMemoryReader fromBinary = FMemoryReader(data);
		fromBinary.Seek(0);
		
		voiceInt->SerializeRemotePacket(fromBinary);
	}
}

void UGame_SessionPlaybackHandler_VOIP::StartRecord_Implementation()
{
	UWorld* world = UDeveloper_Statics::GetVHWorld();
	if (UDeveloper_Statics::IsListenServer(world))
	{
		// listen server has no net connection, so sign up on all the other players' net connections
		for (FConstPlayerControllerIterator iterator = world->GetPlayerControllerIterator(); iterator; ++iterator)
		{
			if (UNetConnection* netConnection = iterator->Get()->GetNetConnection())
			{
				if (UVoiceChannel* voiceChannel = netConnection->GetVoiceChannel())
				{
					voiceChannel->OnPacketReceived.AddUObject(this, &UGame_SessionPlaybackHandler_VOIP::HandlePacketReceived);

					voiceChannel->OnPacketSent.AddUObject(this, &UGame_SessionPlaybackHandler_VOIP::HandlePacketSent);
				}
			}
		}
	}
	else
	{
		if (UNetConnection* netConnection = UGame_Statics::GetVHPlayerController()->GetNetConnection())
		{
			if (UVoiceChannel* voiceChannel = netConnection->GetVoiceChannel())
			{
				voiceChannel->OnPacketReceived.AddUObject(this, &UGame_SessionPlaybackHandler_VOIP::HandlePacketReceived);

				voiceChannel->OnPacketSent.AddUObject(this, &UGame_SessionPlaybackHandler_VOIP::HandlePacketSent);
			}
		}
	}
}

void UGame_SessionPlaybackHandler_VOIP::StopRecord_Implementation()
{
	UWorld* world = UDeveloper_Statics::GetVHWorld();
	if (UDeveloper_Statics::IsListenServer(world))
	{
		for (FConstPlayerControllerIterator iterator = world->GetPlayerControllerIterator(); iterator; ++iterator)
		{
			if (UNetConnection* netConnection = iterator->Get()->GetNetConnection())
			{
				if (UVoiceChannel* voiceChannel = netConnection->GetVoiceChannel())
				{
					voiceChannel->OnPacketReceived.RemoveAll(this);

					voiceChannel->OnPacketSent.RemoveAll(this);
				}
			}
		}
	}
	else
	{
		if (UNetConnection* netConnection = UGame_Statics::GetVHPlayerController()->GetNetConnection())
		{
			if (UVoiceChannel* voiceChannel = netConnection->GetVoiceChannel())
			{
				voiceChannel->OnPacketReceived.RemoveAll(this);

				voiceChannel->OnPacketSent.RemoveAll(this);
			}
		}
	}
}

void UGame_SessionPlaybackHandler_VOIP::SetSecondsPassed_Implementation(float secondsPassed)
{
	
}

void UGame_SessionPlaybackHandler_VOIP::UnloadPlayback_Implementation()
{
	
}


void UGame_SessionPlaybackHandler_VOIP::FilterSetSecondsPassedResults_Implementation(FSpatialiteResults_BP& results)
{
	FString handlerUID = IInterface_SessionPlaybackHandler::Execute_GetHandlerUID(this);

	// remove all voip playback
	for (int32 i = 0; i < results.Results.Num(); i++)
	{
		if (UDatabase_Spatialite::GetString(TEXT("handlerUID"), results.Results[i]).Equals(handlerUID))
		{
			results.Results.RemoveAt(i, 1);
			i--;
		}
	}
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_SessionPlaybackHandler_VOIP::AddEntry(const TArray<uint8>& data) const
{
	FString handlerUID = IInterface_SessionPlaybackHandler::Execute_GetHandlerUID(this);
	
	Implementation->AddEvent(handlerUID, data);
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_SessionPlaybackHandler_VOIP::HandlePacketSent(TSharedPtr<FVoicePacket> packet)
{
	FBufferArchive archive;
	packet->Serialize(archive);

	AddEntry((TArray<uint8>&)archive);
}

void UGame_SessionPlaybackHandler_VOIP::HandlePacketReceived(TSharedPtr<FVoicePacket> packet)
{
	FBufferArchive archive;
	packet->Serialize(archive);

	AddEntry((TArray<uint8>&)archive);
}