#pragma once

#include "Database_Spatialite.h"

#include "Game_SessionPlaybackDB.generated.h"

class UVH_COTEvent;

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_SessionPlaybackDB : public UDatabase_Spatialite
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_SessionPlaybackDB();

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	FString PrimaryTableName;
	
	TArray<FString> PrimaryTableFields;

	FString FullPathToDatabase;

	FDateTime StartTime;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	bool Initialize();

	void SetFullPathToDatabase(const FString& fullPathToDatabase);

	void AddEvent(const FString& handlerUID, const TArray<uint8>& data) const;
	void AddEvent(const FString& handlerUID, double secondsPassed, const TArray<uint8>& data) const;

	/*
	* \brief Returns rows where row.secondsPassed > minNotInclusive and row.secondsPassed <= maxInclusive
	*/
	SpatialiteResults GetEvents(float minNotInclusive, float maxInclusive, bool bAsc) const;

	float GetPlaybackDuration() const;

	void Clear() const;

	void ClearPostSeconds(float secondsPassed);

	void StartTransaction();

	void EndTransaction();

    /// Use this to determine how long the game has been recording
    /// @return The number of seconds since the DB connection has been opened
    double GetSecondsElapsed() const;

	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
    bool Connect();
};