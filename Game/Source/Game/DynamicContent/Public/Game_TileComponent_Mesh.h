#pragma once

#include "Game_TileComponent.h"
#include "Game_TileComponent_Mesh.generated.h"

class AVH_GlobeReferenceActor;

DECLARE_DELEGATE_ThreeParams(FGameLogicCompletedMesh, const TArray<FVector>&, const TArray<int32>&, const TArray<FVector2D>&);

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_TileComponent_Mesh : public UGame_TileComponent
{
	GENERATED_BODY()

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_TileComponent_Mesh();

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	FGameLogicCompletedMesh OnGameLogicCompleted;

protected:
	bool bDrawDistanceDirty;

	FCriticalSection* VerticesCritSection;

	FCriticalSection* TrianglesCritSection;

	FCriticalSection* UVsCritSection;

	TArray<FVector> Vertices;

	TArray<int32> Triangles;
	TArray<int32> TrianglesInRange;

	TArray<FVector2D> UVs;

	int32 NumDataX;
	int32 NumDataY;

private:
	float DrawDistance;
	FVector DrawDistanceCenter;
	FBox2D DrawCullBoxUU;

	bool bScaleUpdated;

	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual bool IsReadyForFinishDestroy() override;

	virtual void ExecuteGameThreadLogic() override;

	virtual bool SetBoundsAndZoomVirtual(const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds, int32 zoomLevel) override;

	virtual bool GlobeReferenceScaleUpdated(const FVector& newScale3D) override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	bool SetDrawDistance(const FVector& center, const double distanceMeters);

	/* return true if valid draw distance */
	bool GetDrawDistance(float& distanceUU, FVector& center) const;

	void SetDrawCullBox(const FBox2D& cullBox);

	FBox2D GetDrawCullBox() const;

	void SetDrawDistanceDirty();

	
	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	AVH_GlobeReferenceActor* GetGlobeReference() const;

	virtual void ApplyDrawDistance();

	virtual bool IsSafeToExecute();
};