#pragma once

// VH Plugin Includes
#include "VH_COTManager.h"
#include "VH_GlobeReferenceActor.h"

// Generated Includes
#include "Game_COTManager.generated.h"

class AGame_VirtualObjective;
class APawn;
class UVH_COTEvent;
class UVH_COTComponent;
class AGame_VehicleRepresentative;

UCLASS(Blueprintable, BlueprintType)
class GAME_API UGame_COTManager : public UVH_COTManager
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	/* if true, only allows incoming atom COTs that are associated with subscribed data sync */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bBlockIncomingAtomCOTsExceptDataSyncs;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSet<TSubclassOf<UObject>> EntityHandlers;

private:
	float HeartbeatCooldown;

	FVector CachedPlayerLocation;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TSet<TSubclassOf<AGame_VehicleRepresentative>> VehicleBlueprints;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TSet<FName> VehicleDropperCategories;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_COTManager();


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create COT Manager"))
	static UVH_COTManager* Create(TSubclassOf<class UVH_COTManager> managerClass, bool bLoadTOCBoards);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Tick(float deltaSeconds) override;

	virtual UVH_COTEvent* GetCotEventFromUID(const FString& entityUID) const override;

	virtual void Notify(const FString& message, float duration) const override;

	virtual FGeodeticCoord3D GetGeodeticLocation() const override;

	virtual void SetHeartbeatCoordinate(const FGeodeticCoord3D& coordinate) override;

protected:
	virtual void StoreSettings() const override;

	virtual void LoadSettings() override;

	virtual void HandleAtomEvent_Virtual(UVH_COTEvent* cotEvent) override;

	/* returns actors from all VOs associated with an entity uid */
	virtual TSet<AActor*> GetActorsForEntity(const FString& entityUID) const override;

	virtual void RegisterFile(const FString& fullPathToFile) override;

private:
	virtual float GetHeartbeatCooldown() const override;

	virtual bool PostInitialize() override;

	virtual bool ShouldHandleAtomCOT_Virtual(UVH_COTEvent* cotEvent) const override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	AActor* PageInEntity(AGame_VirtualObjective* virtualObjective, UVH_COTEvent* cotEvent, int32 detailLevel = 1);

	void InsertOrUpdate(UVH_COTComponent* cotComponent, bool bForceTransient = false);

	UFUNCTION(BlueprintCallable)
	void InsertOrUpdate(UVH_COTEvent* cotEvent, bool bForceTransient = false);

	UFUNCTION(BlueprintCallable)
	void RegisterVehicleClass(TSubclassOf<AGame_VehicleRepresentative> vehicleBlueprint);

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	TArray<TSubclassOf<AGame_VehicleRepresentative>> GetVehicleBlueprints() const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	void GetVehicleBlueprintsInCategory(const FName& inCategory, TArray<TSubclassOf<AGame_VehicleRepresentative>>& outArray);

	void DeleteStaleEntitiesFromResults(SpatialiteResults& results) const;


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleEntityDBDeleteEvent(const FSpatialiteResults_BP& results);
};
