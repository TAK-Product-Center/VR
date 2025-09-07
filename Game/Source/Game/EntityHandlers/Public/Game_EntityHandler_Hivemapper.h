#pragma once

// Parent Includes
#include "Game_EntityHandler.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Game Includes
#include "Game_EntityHandler.h"

// Generated Includes
#include "Game_EntityHandler_Hivemapper.generated.h"

class UMaterialInterface;

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_EntityHandler_Hivemapper : public UGame_EntityHandler
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_EntityHandler_Hivemapper();


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = "true"))
	UMaterialInterface* DefaultMaterial;


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------
public:
	FORCEINLINE static FString StaticGetClassUID()
	{
		return TEXT("Core-Hivemapper");
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

    virtual void GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues);

	virtual bool RegisterFileToDatabaseFirstPass_Implementation(const FString& fullPathToFile, TSet<FString>& registeredEntityUIDs) override;

	virtual void PageInFile(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FString& fullPathToFile) override;

	virtual void GetGoToCoord_Implementation(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate) override;
};
