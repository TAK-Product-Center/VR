#pragma once

#include "Database_Spatialite.h"

#include "Game_MUCTransferLog.generated.h"

UCLASS(Blueprintable)
class GAME_API UGame_MUCTransferLog : public UObject
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Variables
	// ---------------------------------
private:
	FDateTime Timestamp;

	SpatialiteResult Result;

	FString EntityUID;

	FString CategoryID;

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UGame_MUCTransferLog();

	// ---------------------------------
	// --- Static Functions
	// ---------------------------------
public:
	UFUNCTION(BlueprintCallable)
	static UGame_MUCTransferLog* CreateMUCTransferLog(const FSpatialiteResult_BP& result);

	static UGame_MUCTransferLog* CreateMUCTransferLog(const SpatialiteResult& result);

	// ---------------------------------
	// --- API
	// ---------------------------------
public:
	UFUNCTION(BlueprintPure)
	FDateTime GetTimestamp() const;

	UFUNCTION(BlueprintPure)
	FSpatialiteResult_BP GetResult() const;

	UFUNCTION(BlueprintPure)
	FString GetEntityUID() const;

	UFUNCTION(BlueprintPure)
	FString GetCategoryID() const;

	void SetResult(const SpatialiteResult& result);

	/* return true if this is repeat of otherLog (same entityUID, <= 2s after other) */
	UFUNCTION(BlueprintCallable)
	bool IsRepeat(UGame_MUCTransferLog* otherLog);
};
