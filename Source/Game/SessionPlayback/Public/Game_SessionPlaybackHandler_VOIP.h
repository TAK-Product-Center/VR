#pragma once

// Parent Includes
#include "UObject/Object.h"
#include "Interface_SessionPlaybackHandler.h"

// Engine Includes
#include "Net/DataBunch.h"
#include "Net/VoiceDataCommon.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_SessionPlaybackHandler_VOIP.generated.h"

class UGame_SessionPlayback_Impl;

UCLASS()
class GAME_API UGame_SessionPlaybackHandler_VOIP : public UObject, public IInterface_SessionPlaybackHandler
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_SessionPlaybackHandler_VOIP();

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------
	 
private:
	UPROPERTY()
	UGame_SessionPlayback_Impl* Implementation;


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static FString GetHandlerUIDStatic();
	 
	 
	// ---------------------------------
	// --- Interface_SessionPlaybackHandler
	// ---------------------------------

public:
	virtual FString GetHandlerUID_Implementation() const;

	virtual void SetImpl_Implementation(UGame_SessionPlayback_Impl* impl);

	virtual void ApplyEvent_Implementation(const FSpatialiteResult_BP& result);

	virtual void StartRecord_Implementation();

	virtual void StopRecord_Implementation();

	virtual void SetSecondsPassed_Implementation(float secondsPassed);

	virtual void UnloadPlayback_Implementation();

	virtual void FilterSetSecondsPassedResults_Implementation(FSpatialiteResults_BP& results);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void AddEntry(const TArray<uint8>& data) const;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------
	
private:
	void HandlePacketSent(TSharedPtr<FVoicePacket> packet);

	void HandlePacketReceived(TSharedPtr<FVoicePacket> packet);
};