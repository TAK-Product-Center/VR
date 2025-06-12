#pragma once

// Parent includes
#include "Game_ObjectImplementsGetWorld.h"
#include "Interface_EntityHandler.h"

// Generated include
#include "VTAK_EntityHandler_Orbit.generated.h"

// Forward declarations
class AGame_VirtualObjective;
class UVTAK_DatabaseComponent_Orbit;


UCLASS(Blueprintable, BlueprintType)
class VTAK_ORBIT_API UVTAK_EntityHandler_Orbit : public UGame_ObjectImplementsGetWorld, public IInterface_EntityHandler
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Members
	// ---------------------------------
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName CategoryID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> OrbitTargetClass;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:

	UVTAK_EntityHandler_Orbit();


	// ---------------------------------
	// --- Interface_EntityHandler
	// ---------------------------------
public:

    virtual FString GetClassUID_Implementation() { return StaticGetClassUID(); }

	virtual void GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues);

	virtual void GetGoToCoord_Implementation(const FSpatialiteResult_BP& result, FGeodeticCoord3D& coordinate);

	virtual void DeleteEntity_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);

	virtual void PreModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);

	virtual void PostModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);

	virtual void SetEntityDetailStatus_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, int32 detailStatus);

	virtual void SetEntityScale3D_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FVector& scale3D);

	virtual void SetEntityVisibility_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, bool bVisible);

	virtual void SnapEntityToGround_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);

	virtual void UpdateEntity_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result);


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------
public:

	FORCEINLINE static FString StaticGetClassUID() { return TEXT("0CB008E61CD5E4F0AE6FD764B5DF9E29"); }


	// ---------------------------------
	// --- Implementation Methods
	// ---------------------------------
private:

	UVTAK_DatabaseComponent_Orbit* GetDatabaseComponent(AGame_VirtualObjective* virtualObjective, const FString& entityUID) const;

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

};