#pragma once

#include "Game_ObjectImplementsGetWorld.h"
#include "Game.h"
#include "Interface_EntityHandler.h"
#include "GameFramework/Actor.h"
#include "Game_EntityHandler_Mark.generated.h"

class AGame_VirtualObjective;
class UGame_DatabaseComponent_Mark;

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_EntityHandler_Mark : public UGame_ObjectImplementsGetWorld, public IInterface_EntityHandler
{
    GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UGame_EntityHandler_Mark();

	// ---------------------------------
	// --- Members
	// ---------------------------------
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName CategoryID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> MarkTargetClass;

	// ---------------------------------
	// --- Interface_EntityHandler
	// ---------------------------------
public:
    virtual FString GetClassUID_Implementation() { return StaticGetClassUID(); }

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
	// --- Static Functions
	// ---------------------------------
public:
	FORCEINLINE static FString StaticGetClassUID() { return TEXT("C1467096A3AA436C8509B8A19E84A804"); }

	// ---------------------------------
	// --- Implementation Methods
	// ---------------------------------
private:
	/*
	 * \brief Loads entity based on blobData from database
	 * \param entityUID UID of entity to load
	 * \param blobData Data from blob queried from database
	 */
	void PageInEntity(AGame_VirtualObjective* virtualObjective, const FString& entityUID, const TArray<uint8>& blobData);

	/*
	* \brief Unloads an entity
	* \param entityUID UID of entity to unload
	*/
	void PageOutEntity(AGame_VirtualObjective* virtualObjective, const FString& entityUID);

	UGame_DatabaseComponent_Mark* GetDatabaseComponent(AGame_VirtualObjective* virtualObjective, const FString& entityUID) const;
};