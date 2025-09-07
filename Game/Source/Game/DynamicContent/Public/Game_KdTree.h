#pragma once

// Parent Includes
#include "UObject/NoExportTypes.h"

#include "Game_KdTree.generated.h"


struct FGame_KdNode
{
	FBox Bounds;
	TArray<FVector> Points;
	TArray<FVector> Normals;
	int32 Left;
	int32 Right;
	TArray<int32> TriangleIndices;  // Only at leaf
	int32 SplitAxis = -1;
	double SplitPos = 0.0;

	FGame_KdNode() :
		Left(-1),
		Right(-1) {}

	FGame_KdNode(const FVector& InPoint) :
		Left(-1),
		Right(-1) {}

	FGame_KdNode(const FVector& InPoint, int32 axis) :
		Left(-1),
		Right(-1) {}
};


/// SAH-optimized kd-tree with triangle clipping (spatial splits)
/// SAH = Split-Aligned Hierarchy
UCLASS()
class GAME_API UGame_KdTree_Terrain : public UObject
{
	GENERATED_BODY()


	uint8 bBuildRunning : 1;
	uint8 bIsReady : 1;

	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:

	TArray<FGame_KdNode> Nodes;
	TArray<FVector> StagedPoints;
	int32 RootNode = -1;
	TArray<int32> StagedIndices;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:

	UGame_KdTree_Terrain();


	// ---------------------------------
	// --- API
	// ---------------------------------

public:

	void Append(const TArray<FVector>& points, const TArray<int32>& triangles);
	void Build();
	void AsyncBuild();
	bool LineTrace(const FVector& start, const FVector& dir, FVector& outClosestPoint) const;

	/// When runninig an AsyncBuild(), this will stop the build and force it to return immediately.
	/// Doesn't do anything for the normal Build().
	void Stop();

	bool IsReady() const;
	bool IsBuilding() const;
	

	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:

	int32 CreateLeafNode(const TArray<int32>& tris, int32 start, int32 end);
	int32 BuildRecursive_SAH(TArray<int32>& Tris, int32 Start, int32 End);
	int32 AsyncBuildRecursive_SAH(TArray<int32>& Tris, int32 Start, int32 End);

	bool TraverseNode_LineTrace(int32 nodeIndex, const FVector& start, const FVector& dir, FVector& outHit) const;
};
