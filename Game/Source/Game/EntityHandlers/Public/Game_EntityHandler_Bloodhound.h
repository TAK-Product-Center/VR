#pragma once

// Parent Includes
#include "Game_ObjectImplementsGetWorld.h"

// Engine Includes
#include "GameFramework/Actor.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Game Includes
#include "Interface_EntityHandler.h"
#include "Game_EntityHandler_Bloodhound.generated.h"

class AGame_VirtualObjective;
class APawn;

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_EntityHandler_Bloodhound : public UGame_ObjectImplementsGetWorld, public IInterface_EntityHandler
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------


public:
	UGame_EntityHandler_Bloodhound();

	
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
	UFUNCTION(BlueprintPure)
	static FString StaticGetClassUID() { return TEXT("2H78DF299DK27RHNFLI7SHJSMK20JLS0"); }


	// ---------------------------------
	// --- Implemenation
	// ---------------------------------

private:
	APawn* GetPlayerPawn(const FString& entityUID) const;
};
