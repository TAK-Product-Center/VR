#pragma once

// Parent Includes
#include "SessionPlayback_Impl.h"

// Engine Includes
#include "TimerManager.h"

// VH Plugin Includes
#include "Database_Spatialite.h"
#include "Interface_SessionPlaybackHandler.h"

// Generated Includes
#include "Game_SessionPlayback_Impl.generated.h"

class UVH_COTConnectionInfo;
class UGame_SessionPlaybackDB;

UCLASS()
class GAME_API UGame_SessionPlayback_Impl : public USessionPlayback_Impl
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

protected:
	UPROPERTY()
	TMap<FString, UObject*> Handlers;

	UPROPERTY()
	UGame_SessionPlaybackDB* SessionPlaybackDB;

	FTimerHandle TimePassedTimerHandle;

private:
	float LastSecondsPassed;

	UPROPERTY()
	TArray<UVH_COTConnectionInfo*> CachedConnections;
	
	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_SessionPlayback_Impl();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UObject* GetHandler(const FString& handlerUID);
	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------

protected:
	virtual void PostTick(float deltaSeconds) override;
	
	virtual bool PostLoadPlayback(const FString& fullPathToFile, float& playbackDuration, FString& error) override;

	virtual void PostUnloadPlayback() override;

	virtual void PostSetSecondsPassed(float secondsPassed) override; 

	virtual void PostStartRecord(const FString& fullPathToFile) override;

	virtual void PostStopRecord() override;

	virtual void PostSetPlaybackRate(float playbackRate) override;

	virtual void PostSetAsImplementation() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void RegisterHandler(const TScriptInterface<IInterface_SessionPlaybackHandler>& handler);

	void AddEvent(const FString& handlerUID, const TArray<uint8>& data) const;

	/// Writes an event to the playback DB
	/// @param handlerUID The string identifier used to determine which parser should interpret the blob daata
	/// @param data Raw array of bytes to be stored and interpreted later
	/// @param secondsElapsed The relative runtime of the playback when the event occured
	void AddEvent(const FString& handlerUID, const TArray<uint8>& data, double secondsElapsed);

	/// Calls Sync("begin transaction") on the database.  Must be paired with CommitTransaction to complete the DB call
	void BeginTransaction();

	/// Calls Sync("commit") on the database, ending a transaction.  This is used to speed up large groups of queries
	/// that happen back to back
	void CommitTransaction();

	/// Use this to determine how long the playback has been recording
	/// @return The number of seconds elapsed since the playback was started
	double GetSecondsElapsed(); 


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	bool OpenSessionPlaybackDB(const FString& fullPathToDatabase);

private:
	void ApplyEvents(const SpatialiteResults& results) const;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

public:
	void HandleTimePassed();
};
