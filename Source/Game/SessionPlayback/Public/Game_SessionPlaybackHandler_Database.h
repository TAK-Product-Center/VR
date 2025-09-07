#pragma once

#include "Interface_SessionPlaybackHandler.h"

#include "Game_SessionPlaybackHandler_Database.generated.h"

class UGame_SessionPlayback_Impl;

UCLASS()
class GAME_API UGame_SessionPlaybackHandler_Database : public UObject, public IInterface_SessionPlaybackHandler
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_SessionPlaybackHandler_Database();

	
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

	virtual void FilterSetSecondsPassedResults_Implementation(FSpatialiteResults_BP& results);

	// ---------------------------------
	// --- Implementation
	// ---------------------------------
	 
private:
	void AddEntry(const FString& type, const SpatialiteResult& result) const;

	
	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleDatabaseInsertOrUpdate(const FSpatialiteResults_BP& results);

	UFUNCTION()
	void HandleDatabaseDelete(const FSpatialiteResults_BP& results);
};