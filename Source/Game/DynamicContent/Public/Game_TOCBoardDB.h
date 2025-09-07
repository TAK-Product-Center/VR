#pragma once

// Parent Includes
#include "Database_Spatialite.h"

// Engine Includes
#include "Templates/SubclassOf.h"

// Generated Includes
#include "Game_TOCBoardDB.generated.h"

class AGame_TOCBoard;

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_TOCBoardDB : public UDatabase_Spatialite
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FConfigurationLoaded);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintAssignable)
	FConfigurationLoaded OnConfigurationLoaded;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_TOCBoard> TOCBoardClass;

private:
	static UGame_TOCBoardDB* GlobalInstance;

	UPROPERTY()
	TArray<AGame_TOCBoard*> TOCBoards;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_TOCBoardDB();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get TOCBoardDB"))
	static UGame_TOCBoardDB* Get();

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure)
	TArray<AGame_TOCBoard*> GetTOCBoards() const;

	UFUNCTION(BlueprintCallable)
	void AddTOCBoard(AGame_TOCBoard* newTOCBoard);

	UFUNCTION(BlueprintCallable)
	void Connect();

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	FString GetCurrentConfiguration() const;

	UFUNCTION(BlueprintPure)
	FString GetFullPathToDatabase() const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	TSet<FString> GetConfigurationIDs() const;

	UFUNCTION(BlueprintCallable)
	void LoadConfiguration(const FString& configurationID);

	UFUNCTION(BlueprintCallable)
	void SaveConfiguration(const FString& configurationID, const TArray<AGame_TOCBoard*>& tocBoardsArg);

	UFUNCTION(BlueprintCallable)
	void DeleteConfiguration(const FString& configurationID, bool bDestroyBoards);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	void SetCurrentConfiguration(const FString& configurationID);
};
