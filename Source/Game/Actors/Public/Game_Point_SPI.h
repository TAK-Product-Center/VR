#pragma once

// Parent Includes
#include "Game_Point_Icon.h"

// Generated Includes
#include "Game_Point_SPI.generated.h"

class UVH_COTEvent;
class AGame_SimpleSegmentedLineActor;
struct FSpatialiteResults_BP;

UCLASS()
class GAME_API AGame_Point_SPI : public AGame_Point_Icon
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UTexture2D* SPILocalIcon;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UTexture2D* SPIIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_SimpleSegmentedLineActor> LineActorClass;

private:
	UPROPERTY()
	AGame_SimpleSegmentedLineActor* LineActor;

	bool bPersonalSPI;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Point_SPI(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	void UpdateCOT();
	

	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	int32 GetNextSPISuffix() const;

	bool IsPersonalSPI(UVH_COTEvent* cotEvent) const;

	int32 GetMaxNumberPersonalSPIs() const;

	bool GetRelationUID(UVH_COTEvent* cotEvent, FString& relationUID) const;

	void SpawnLine();

	void UpdateLinePoints();
	
	void DestroyLineActor();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	virtual void HandleReceivedCOTUpdate(UVH_COTEvent* cotEvent) override;

	UFUNCTION()
	void HandleInsertOrUpdate(const FSpatialiteResults_BP& results);

	UFUNCTION()
	void HandleDelete(const FSpatialiteResults_BP& results);
};
