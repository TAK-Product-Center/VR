#pragma once

#include "UObject/Object.h"

#include "Database_Spatialite.h"

#include "Game_VirtualObjectiveManager.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogGameVirtualObjectiveManager, Warning, All);

class AGame_VirtualObjective;
class AVH_GlobeReferenceActor;

UCLASS(Blueprintable, Config = "Game")
class GAME_API UGame_VirtualObjectiveManager : public UObject
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

private:
	DECLARE_MULTICAST_DELEGATE_TwoParams(FOnObjectAddedToVO, UObject*, AGame_VirtualObjective*);

public:
	static FOnObjectAddedToVO OnObjectAddedToVO;

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:
	static UGame_VirtualObjectiveManager* GlobalInstance;

	UPROPERTY()
	TSet<AGame_VirtualObjective*> VirtualObjectives;

	bool bIsInitialized;

	bool bIsShuttingDown;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_VirtualObjectiveManager();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure, Category = "Game|VirtualObjectiveManager", meta = (DisplayName = "VH Get VirtualObjectiveManager"))
	static UGame_VirtualObjectiveManager* Get();

	UFUNCTION(BlueprintPure)
	static AGame_VirtualObjective* GetObjectVO(UObject* object, bool bLogError = true);

	static AGame_VirtualObjective* GetObjectVO(const UObject* object, bool bLogError = true);

	UFUNCTION(BlueprintPure)
	static FString GetObjectEntityUID(UObject* object, bool bLogError = true);

	UFUNCTION(BlueprintPure)
	static AVH_GlobeReferenceActor* GetObjectGlobeReference(UObject* object, bool bLogError = true);


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void RegisterVirtualObjective(AGame_VirtualObjective* virtualObjective);

	void UnregisterVirtualObjective(AGame_VirtualObjective* virtualObjective);

	UFUNCTION(BlueprintCallable)
	void TriggerUpdateGlobal();

	UFUNCTION(BlueprintPure)
	TSet<AActor*> GetActorsForEntityGlobal(const FString& entityUID) const;

	void DeleteEntityGlobal(const SpatialiteResult& result);

	UFUNCTION(BlueprintCallable)
	void DeleteEntityGlobal(const FString& entityUID);

	void SetEntityVisibilityGlobal(const SpatialiteResult& result, bool bVisible);

	UFUNCTION(BlueprintCallable)
	void SetEntityVisibilityGlobal(const FString& entityUID, bool bVisible);

	void UpdateEntityGlobal(const SpatialiteResult& result);

	UFUNCTION(BlueprintCallable)
	void UpdateEntityGlobal(const FString& entityUID);

	UFUNCTION(BlueprintCallable)
	void PageOutEntitiesGlobal();

	bool Initialize();

	void Shutdown();

	void OnGameModeInit();

	void OnGameModeStartToLeaveMap();

	void EntityHandlerRegistered(UObject* handler);

	AGame_VirtualObjective* GetVirtualObjectiveByEntityDetailLevel(int32 entityDetailLevel) const;


    // ---------------------------------
    // --- Debug/Testing
    // ---------------------------------

public:
	UFUNCTION(exec)
	void VOMgrTest_SetVOScale(float newScale);
};
