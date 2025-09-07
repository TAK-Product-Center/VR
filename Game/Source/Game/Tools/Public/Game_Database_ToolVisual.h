#pragma once

// Parent Includes
#include "Database_Spatialite.h"

// Generated Includes
#include "Game_Database_ToolVisual.generated.h"

class UStaticMesh;

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_Database_ToolVisual : public UDatabase_Spatialite
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------
	 
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FString, UStaticMesh*> MeshIDToAsset;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_Database_ToolVisual();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UGame_Database_ToolVisual* Get();


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void Connect();

	UFUNCTION(BlueprintPure)
	FString GetCurrentConfiguration() const;

	FString GetFullPathToDatabase() const;

	UFUNCTION(BlueprintPure)
	TSet<FString> GetConfigurationIDs() const;

	UFUNCTION(BlueprintCallable)
	bool LoadConfiguration(const FString& configurationID, FSpatialiteResult_BP& result);

	bool LoadConfiguration(const FString& configurationID, SpatialiteResult& result);

	UFUNCTION(BlueprintCallable)
	void SaveConfiguration(const TMap<FString, FString>& keyValues);

	UFUNCTION(BlueprintCallable)
	void DeleteConfiguration(const FString& configurationID);

	UFUNCTION(BlueprintCallable)
	void SetCurrentConfiguration(const FString& configurationID);
};
