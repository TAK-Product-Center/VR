#pragma once

#include "VH_GeodeticCoord.h"

#include "Game_EntityHandler.h"
#include "Game_EntityHandler_COT.generated.h"

class UVH_COTEvent;

UCLASS()
class GAME_API UGame_EntityHandler_COT : public UGame_EntityHandler
{
    GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UGame_EntityHandler_COT();

	// ---------------------------------
	// --- Variables
	// ---------------------------------
private:
	TMap<AActor*, TArray<FGeodeticCoord3D>> ActorToLocations;

	// ---------------------------------
	// --- Static Functions
	// ---------------------------------
public:
	FORCEINLINE static FString StaticGetClassUID() { return TEXT("7EACAF16D59911E9BB652A2AE2DBCCE4"); }

	// ---------------------------------
	// --- Inherited
	// ---------------------------------
public:
	virtual FString GetClassUID_Implementation() override { return StaticGetClassUID(); }

	virtual void UpdateEntity_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result) override;

	virtual void GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues) override;

	virtual void PreModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result) override;

	virtual void PostModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result) override;

	virtual void SnapEntityToGround_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result) override;

	virtual void GetGoToCoord_Implementation(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate) override;

	virtual void PageInEntity(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result) override;

	virtual bool RegisterFileToDatabaseSecondPass_Implementation(const FString& fullPathToFile, TSet<FString>& registeredEntityUIDs) override;

	virtual TMap<FString, FString> GetHashesToSyncForMUC_Implementation(const FSpatialiteResult_BP& result) override;

	// ---------------------------------
	// --- Implementation
	// ---------------------------------
private:
	FGeodeticCoord3D GetGoToCoord(UVH_COTEvent* cotEvent) const;
};