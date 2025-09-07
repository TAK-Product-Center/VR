#pragma once

// Parent Includes
#include "Game_EntityHandler.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_EntityHandler_Viewshed.generated.h"

class AGame_VirtualObjective;
class AGame_Actor_Viewshed;

UCLASS()
class GAME_API UGame_EntityHandler_Viewshed : public UGame_EntityHandler
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<class AGame_Actor_Viewshed> ViewshedActorClass;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_EntityHandler_Viewshed();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	FORCEINLINE static FString StaticGetClassUID()
	{
		return TEXT("3D363EF6F70811ECB9390242AC120002");
	}


	// ---------------------------------
	// --- Interface_EntityHandler
	// ---------------------------------

public:
	virtual TMap<FString, FString> GetHashesToSyncForMUC_Implementation(const FSpatialiteResult_BP& result) override;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual FString GetClassUID_Implementation() override
	{
		return StaticGetClassUID();
	}

	virtual void GetEntityOverlayInfo_Implementation(const FSpatialiteResult_BP& result, TMap<FString, FString>& keyValues) override;

	virtual void SnapEntityToGround_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result) override;

	virtual void PreModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result) override;

	virtual void PostModifyVOGlobeReference_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result) override;

	void SetEntityScale3D_Implementation(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result, const FVector& scale3D) override;

private:
	virtual void PageInEntity(AGame_VirtualObjective* virtualObjective, const FSpatialiteResult_BP& result) override;
};