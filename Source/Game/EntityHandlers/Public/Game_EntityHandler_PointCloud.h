#pragma once

#include "VH_GeodeticCoord.h"

#include "Game_EntityHandler.h"
#include "Game_EntityHandler_PointCloud.generated.h"

class AGame_VirtualObjective;
class AGame_PointCloudActor;

UCLASS()
class GAME_API UGame_EntityHandler_PointCloud : public UGame_EntityHandler
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UGame_EntityHandler_PointCloud();


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<class AGame_PointCloudActor> PointCloudActorBlueprint;


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	FORCEINLINE static FString StaticGetClassUID()
	{
		return TEXT("0F3CAE024E4D40CB91ADF83EF0B775C6");
	}


	// ---------------------------------
	// --- Interface_EntityHandler
	// ---------------------------------

	void PageInFileWithDefaultSettings_Implementation(AGame_VirtualObjective* virtualObjective, const FString& entityUID, const FString& fullPathToFile) override;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual FString GetClassUID_Implementation() override
	{
		return StaticGetClassUID();
	}

	virtual void GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues) override;

	virtual bool RegisterFileToDatabaseSecondPass_Implementation(const FString& fullPathToFile, TSet<FString>& registeredEntityUIDs) override;

	virtual void PageInFile(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FString& fullPathToFile) override;
};