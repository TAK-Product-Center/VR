#pragma once

// Parent Includes
#include "Game_EntityHandler.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_EntityHandler_File.generated.h"

class AGame_VirtualObjective;
class AGame_Actor_File;
class UMaterialInterface;

UCLASS()
class GAME_API UGame_EntityHandler_File : public UGame_EntityHandler
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_EntityHandler_File();


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_Actor_File> ActorClass;

private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	UMaterialInterface* DefaultMaterial;


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	FORCEINLINE static FString StaticGetClassUID()
	{
		return TEXT("1978D6E58A8C12340C7F86129D8B233B");
	}

	
	// ---------------------------------
	// --- Interface_EntityHandler
	// ---------------------------------

	void PageInFileWithDefaultSettings_Implementation(AGame_VirtualObjective* virtualObjective, const FString& entityUID, const FString& fullPathToFile) override;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
    virtual FString GetClassUID_Implementation() override { return StaticGetClassUID(); }

	virtual void GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues) override;

	virtual bool RegisterFileToDatabaseSecondPass_Implementation(const FString& fullPathToFile, TSet<FString>& registeredEntityUIDs) override;

	virtual void PageInFile(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FString& fullPathToFile) override;

	virtual void GetGoToCoord_Implementation(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate) override;
};