#pragma once

// Parent Includes
#include "Game_EntityHandler.h"

// Engine Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_EntityHandler_Kml.generated.h"

class AActor;
class AGame_VirtualObjective;
class UVH_KmlInfo;
class AGame_Actor_KmlPlacemark;

UCLASS()
class GAME_API UGame_EntityHandler_Kml : public UGame_EntityHandler
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_EntityHandler_Kml();


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> GRGActorBlueprint;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_Actor_KmlPlacemark> KmlActorClass;

	
	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	FORCEINLINE static FString StaticGetClassUID() { return TEXT("Core-KmlCollection"); }


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

	virtual void PreModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result) override;

	virtual void PostModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result) override;

	virtual void SnapEntityToGround_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result) override;

	virtual bool RegisterFileToDatabaseFirstPass_Implementation(const FString& fullPathToFile, TSet<FString>& registeredEntityUIDs) override;

	virtual void PageInFile(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FString& fullPathToFile) override;

	virtual void GetGoToCoord_Implementation(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate) override;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	bool PageInGRG(AGame_VirtualObjective* virtualObjective, const FString& entityUID, UVH_KmlInfo* kmlInfo);

	void PageInNonGRG(AGame_VirtualObjective* virtualObjective, const FString& entityUID, UVH_KmlInfo* kmlInfo);
};