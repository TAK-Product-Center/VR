#pragma once

// Parent Includes
#include "Components/ActorComponent.h"

// Engine Includes
#include "Misc/Timespan.h"

// Generated Includes
#include "VH_COTComponent.generated.h"

class UVH_COTEvent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPopulateCOT);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReceivedCOTUpdate, UVH_COTEvent*, cotEvent);

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class VH_COT_API UVH_COTComponent : public UActorComponent
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------
public:
	UPROPERTY(BlueprintAssignable)
	FPopulateCOT OnPopulateCOT;

	UPROPERTY(BlueprintAssignable)
	FReceivedCOTUpdate OnReceivedCOTUpdate;


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	FTimespan ActiveTime;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	bool bGenerateCallsign;

protected:
	/* last received COTEvent */
	UPROPERTY()
	UVH_COTEvent* CurrentCOTEvent;

private:
	FString CachedType;

	bool bLockCallsign;

	bool bReceivedCOTUpdate;


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
    UVH_COTComponent();

	virtual void BeginPlay() override;

    virtual void TickComponent(float deltaSeconds, enum ELevelTick tickType, FActorComponentTickFunction* thisTickFunction) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	virtual void SnapToGround();

	/* Returns positions that need to be shifted when the GlobeReference changes */
	UFUNCTION(BlueprintCallable)
	virtual TArray<FVector> PreModifyVOGlobeReference();

	/* Pass in updated positions for each vector that was in PreModifyGlobeReference */
	UFUNCTION(BlueprintCallable)
	virtual void PostModifyVOGlobeReference(const TArray<FVector>& updatedPositions);

	UFUNCTION(BlueprintPure)
	virtual UVH_COTEvent* GetCurrentCOTEvent();

    UFUNCTION(BlueprintCallable)
    void PopulateCOT();

    /* sends information in CurrentCOTEvent to all contacts */
    UFUNCTION(BlueprintCallable)
    virtual void BroadcastCOT();

    /* sends information in CurrentCOTEvent to specified contact UIDs */
    UFUNCTION(BlueprintCallable)
    virtual void SendCOT(const TArray<FName>& contactUIDs);

	UFUNCTION(BlueprintCallable)
	void ReceiveCOTUpdate(UVH_COTEvent* cotEvent);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	virtual void ReceiveCOTUpdate_Virtual(UVH_COTEvent* cotEvent);

    /** populate CurrentCOTEvent with data from virtual environment (e.g. location, rotation) */
	virtual void PopulateCOT_Virtual();

	virtual bool ShouldHandleStale_Virtual();

    bool ShouldHandleStale();

	virtual void CleanupStaleEntity();
};