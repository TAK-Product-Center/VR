#pragma once

// Parent Includes
#include "Game_COTComponent.h"

// Generated Includes
#include "Game_COTComponent_Draw.generated.h"

class AGame_SimpleSegmentedLineActor;
class AGame_EditPoint;
class UGame_DrawLineData;
class AVH_GlobeReferenceActor;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_COTComponent_Draw : public UGame_COTComponent
{
    GENERATED_BODY()

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_SimpleSegmentedLineActor> LineClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AGame_EditPoint> EditPointClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGame_DrawLineData> DrawLineDataClass;

protected:
	UPROPERTY()
	TMap<AGame_SimpleSegmentedLineActor*, UGame_DrawLineData*> Lines;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_COTComponent_Draw();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;

	virtual void SnapToGround() override;

	virtual TArray<FVector> PreModifyVOGlobeReference() override;

	virtual void PostModifyVOGlobeReference(const TArray<FVector>& updatedPositions) override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
    /* adds editPoint to line at end or after existingEditPoint; if line is nullptr, spawns line */
    UFUNCTION(BlueprintCallable)
    void AddEditPoint(AGame_SimpleSegmentedLineActor* line, AGame_EditPoint* editPoint, AGame_EditPoint* existingEditPoint);

	/* spawns EditPoint at location, then calls AddEditPoint */
	UFUNCTION(BlueprintCallable)
	AGame_EditPoint* SpawnEditPoint(AGame_SimpleSegmentedLineActor* line, const FVector& location, AGame_EditPoint* existingEditPoint);

	UFUNCTION(BlueprintCallable)
	AGame_EditPoint* SpawnEditPointAtIndex(AGame_SimpleSegmentedLineActor* line, const FVector& location, int32 index);

    UFUNCTION(BlueprintCallable)
    void DeleteEditPoint(AGame_SimpleSegmentedLineActor* line, AGame_EditPoint* editPoint);

	UFUNCTION(BlueprintCallable)
	void SetLineCollision(AGame_SimpleSegmentedLineActor* line, bool bShouldCollide);

	UFUNCTION(BlueprintCallable)
	virtual void AddLine(AGame_SimpleSegmentedLineActor* line);

	UFUNCTION(BlueprintCallable)
	AGame_SimpleSegmentedLineActor* SpawnLine();

	virtual void HandleOwnerSetScale3D(const FVector& scale3D);

	virtual void HandleOwnerSetHidden(bool bNewHidden);

	UFUNCTION(BlueprintPure)
	AGame_SimpleSegmentedLineActor* GetLineForEditPoint(AGame_EditPoint* editPoint) const;

	UFUNCTION(BlueprintPure)
	bool GetEditPoints(AGame_SimpleSegmentedLineActor* line, TArray<AGame_EditPoint*>& editPoints) const;

	UFUNCTION(BlueprintPure)
	TArray<AGame_SimpleSegmentedLineActor*> GetLines() const;

	UFUNCTION(BlueprintCallable)
	virtual void SetEditPointsActive(AGame_SimpleSegmentedLineActor* line, bool bActive);

	UFUNCTION(BlueprintPure)
	bool IsLineActive(AGame_SimpleSegmentedLineActor* line) const;

	UFUNCTION(BlueprintPure)
	AGame_EditPoint* GetClosestEditPoint(AGame_SimpleSegmentedLineActor* line, const FVector& location) const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	virtual void AddEditPoint_Virtual(AGame_SimpleSegmentedLineActor* line, AGame_EditPoint* editPoint, AGame_EditPoint* existingEditPoint) {}

	virtual void DeleteEditPoint_Virtual(AGame_SimpleSegmentedLineActor* line, AGame_EditPoint* editPoint) {}

	void DeleteEditPoints(AGame_SimpleSegmentedLineActor* line);

    virtual void DeleteEditPoints_Virtual(AGame_SimpleSegmentedLineActor* line) {}

	virtual bool ShouldSnapEditPoint(AGame_EditPoint* editPoint) const;
};
