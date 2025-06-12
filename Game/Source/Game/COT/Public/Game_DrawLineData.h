#pragma once

#include "UObject/Object.h"
#include "Containers/Map.h"
#include "Tickable.h"

#include "Game_DrawLineData.generated.h"

class AGame_EditPoint;
class AGame_SimpleSegmentedLineActor;

UCLASS()
class GAME_API UGame_DrawLineData : public UObject, public FTickableGameObject
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public: 
	UGame_DrawLineData();

	// ---------------------------------
	// --- Variables
	// ---------------------------------
protected:
	// TArray to preserve order
	UPROPERTY()
	TArray<AGame_EditPoint*> EditPoints;

	UPROPERTY()
	AGame_SimpleSegmentedLineActor* Line;

	float TimeSinceLastSync;
	float SyncLineToEditPointsCooldown;

	// ---------------------------------
	// --- FTickableObjectBase
	// ---------------------------------
public:
	virtual bool IsTickable() const override;

	virtual void Tick(float deltaSeconds) override;

	virtual TStatId GetStatId() const override;

	// ---------------------------------
	// --- Inherited
	// ---------------------------------
public:
	virtual void BeginDestroy() override;

	// ---------------------------------
	// --- API
	// ---------------------------------
public:
	void SetEditPoints(const TArray<AGame_EditPoint*>& editPoints);

	TArray<AGame_EditPoint*> GetEditPoints() const;

	void SetLine(AGame_SimpleSegmentedLineActor* line);

	AGame_SimpleSegmentedLineActor* GetLine() const;

	void PreModifyVOGlobeReference(TArray<FVector>& positions);

	void PostModifyVOGlobeReference(const TArray<FVector>& updatedPositions, int32& index);

	void MoveEditPoint(const FVector& newPosition, int32 index);
	
	void AddEditPoint(AGame_EditPoint* editPoint, AGame_EditPoint* existingEditPoint);

	void DeleteEditPoint(AGame_EditPoint* editPoint);

	void DeleteEditPoints();

	void SetScale3D(const FVector& scale3D);

	void SetHidden(bool bNewHidden);

	// ---------------------------------
	// --- Implementation
	// ---------------------------------
protected:
	virtual void SyncLineToEditPoints();

private:
	virtual void PostSetLine(AGame_SimpleSegmentedLineActor* line);

	virtual void PostModifyEditPoints(const TArray<AGame_EditPoint*>& editPoints);
};
