#pragma once

// Engine includes
#include "Subsystems/GameInstanceSubsystem.h"

// Generated include
#include "Game_TerrainGameInstanceSubsystem.generated.h"

class UDatabase_Spatialite;

UCLASS()
class GAME_API UGame_TerrainGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	/* maps fullPathOnDisk to database object */
	UPROPERTY()
	TMap<FString, UDatabase_Spatialite*> ImageryDBs;

private:
	FCriticalSection ImageryDBCritSection;
	
	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void Disconnect(UDatabase_Spatialite* database);

	UDatabase_Spatialite* GetImageryDB(const FString& fullPathToDB);
};