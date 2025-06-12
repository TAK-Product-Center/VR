#pragma once

#include "VH_GeodeticCoord.h"

#include "Misc/SecureHash.h"
#include "HAL/ThreadSafeCounter.h"

#include "Interface_EntityHandler.h"
#include "Game.h"
#include "Game_ObjectImplementsGetWorld.h"
#include "Game_EntityHandler.generated.h"

class AVH_GlobeReferenceActor;
class AGame_VirtualObjective;

UCLASS()
class GAME_API UGame_EntityHandler : public UGame_ObjectImplementsGetWorld, public IInterface_EntityHandler
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UGame_EntityHandler();

	// ---------------------------------
	// --- Variables
	// ---------------------------------
protected:
	TMap<AActor*, FGeodeticCoord3D> ActorToLocation;

	FThreadSafeCounter DestroyCounter;

private:
	TSet<FString> InProgressPageIns;

	FCriticalSection InProgressCritSection;

	// ---------------------------------
	// --- Interface_EntityHandler
	// ---------------------------------
public:
	virtual FString GetClassUID_Implementation();

	virtual void UpdateEntity_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);

	virtual void SetEntityDetailStatus_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, int32 detailStatus);

	virtual void SetEntityVisibility_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, bool bVisible);

	virtual void GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues);

	virtual void DeleteEntity_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);

	virtual void SetEntityScale3D_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FVector& scale3D);

	virtual void PreModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);

	virtual void PostModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);

	virtual void SnapEntityToGround_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);

	virtual void GetGoToCoord_Implementation(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate);

	virtual TMap<FString, FString> GetHashesToSyncForMUC_Implementation(const FSpatialiteResult_BP& result);

	// ---------------------------------
	// --- Inherited
	// ---------------------------------
public:
	virtual bool IsReadyForFinishDestroy() override;

	// ---------------------------------
	// --- Implementation
	// ---------------------------------
protected:
	/*
	* \brief Unloads an entity
	* \param virtualObjective VO of entity
	* \param entityUID UID of entity to unload
	*/
	virtual void PageOutEntity(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);

private:
	virtual FString GetFilenameFromEntityUID(const FString& entityUID, const FSpatialiteResult_BP& result) const;

	/*
	* \brief Loads entity based on blobData from database
	* \param virtualObjective VO of entity
	* \param entityUID UID of entity to load
	* \param blobData Data from blob queried from database
	*/
	virtual void PageInEntity(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);

	virtual void PageInFile(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FString& fullPathToFile);

	virtual bool IsSafeToExecute();
};