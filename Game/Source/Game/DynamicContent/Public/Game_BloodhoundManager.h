#pragma once

#include "UObject/Object.h"
#include "Tickable.h"

#include "Database_Spatialite.h"

#include "Game_EntityDB.h"
#include "Game_BloodhoundManager.generated.h"

// ---------------------------------
// --- Structs
// ---------------------------------

USTRUCT()
struct FBloodhoundUIDRelation
{
	GENERATED_BODY()

	FString BloodhoundUID;
	FString TargetUID;
	FString ChaserUID;

	UPROPERTY()
	TMap<AGame_VirtualObjective*, int32> PagedInVOs;

	FBloodhoundUIDRelation()
	{

	}

	FBloodhoundUIDRelation(const FString& uid, const FString& targetUID, const FString& chaserUID)
	{
		BloodhoundUID = uid;

		TargetUID = targetUID;

		ChaserUID = chaserUID;
	}
};

class AGame_Bloodhound;
class APlayerState;

/*
 *Bloodhound manager keeps track of Bloodhound entities in the database entities, and updates or spawns them as their target entities update. 
 */
UCLASS(Blueprintable)
class GAME_API UGame_BloodhoundManager : public UObject, public FTickableGameObject
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	/*
	 * The actor class to instantiate during page in events.
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_Bloodhound> BloodhoundActorClass;

private:
	static UGame_BloodhoundManager* GlobalInstance;

	TMap<FString, FBloodhoundUIDRelation> BloodhoundUIDRelations;

	bool bIsInitialized;


	// ---------------------------------
	// --- Constructors

	// ---------------------------------

public:
	UGame_BloodhoundManager();
	

	// ---------------------------------
	// --- FTickableObjectBase
	// ---------------------------------

public:
	virtual bool IsTickable() const override;

	virtual TStatId GetStatId() const override;

	virtual void Tick(float deltaSeconds) override;


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Game Get Bloodhound Manager"))
	static UGame_BloodhoundManager* Get();


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	bool GetBloodhoundEntityUID(AActor* testActor, FString& entityUID) const;

	UFUNCTION(BlueprintCallable, BlueprintPure = false)
	bool GetBloodhoundInfo(const FString& entityUID, FString& chaserEntityUID, FString& targetEntityUID) const;

	UFUNCTION(BlueprintCallable)
	void InsertBloodhound(FString chaserEntityUID, FString targetEntityUID);
	
	/*
	 * Adds requests toBloodhoundUIDRelations to paged in on tick if possible.
	 * @param inVO - The virtual objective into which to page in the bloodhound.
	 * @param inBloodhoundUID - The UID of the bloodhound to attempt to page in.
	 * @param inBlobData - The information on the UID pulled from the database.
	 */ 
	void PageIn(AGame_VirtualObjective* inVO, const FString& inBloodhoundUID, const int32& detailStatus, const TArray<uint8>& inBlobData);

	/*
	 * Removes the bloodhound UID from BloodhoundUIDRelations.
	 * @param inVO - The virtual objective into which to page out the bloodhound.
	 * @param inBloodhoundUID - The UID of the bloodhound to page out.
	 */
	void PageOut(AGame_VirtualObjective* inVO, const FString& inBloodhoundUID);

	/*
	 * Called on managers during creation.
	 */
	bool Initialize();

	/*
	 * Called on managers during shut down.
	 */
	void Shutdown();

	UFUNCTION(BlueprintPure)
	APlayerState* IsAPlayer(const FString& entityUID) const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	/*
	 * Helper function for populating an FBloodhoundUIDRelation.
	 * @param inBloodhoundUID - The UID of the bloodhound to add to BloodhoundUIDRelations.
	 * @param inBlobData - The information on the UID pulled from the database.
	 */
	void AddBloodhoundUIDRelation(const FString& inBloodhoundUID, const TArray<uint8>& inBlobData);

	bool HasLocalPlayer(const FBloodhoundUIDRelation& relation) const;

	bool EntitiesArePagedIn(AGame_VirtualObjective* virtualObjective, const FBloodhoundUIDRelation& relation) const;

	void UpdateBloodhoundActors(const FBloodhoundUIDRelation& relation, bool bIsInTOC);

	bool HasEntityUID(const FBloodhoundUIDRelation& relation, const FString& entityUID) const;

	void GetBoundingBox(const FString& chaserEntityUID, const FString& targetEntityUID, FGeodeticCoord2D& northWestBB, FGeodeticCoord2D& southEastBB) const;

	void UpdateBoundingBox(const FBloodhoundUIDRelation& relation);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	/*
	 * Called when The entityDB inserts or updates.
	 * @param results - The inserted or updated fields.
	 */
	UFUNCTION()
	void HandleInsertOrUpdateEvent(const FSpatialiteResults_BP& results);

	UFUNCTION()
	void HandleDelete(const FSpatialiteResults_BP& results);
};

