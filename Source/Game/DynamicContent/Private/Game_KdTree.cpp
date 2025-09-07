// Required Includes
#include "Game_KdTree.h"

// Engine Includes
#include "Chaos/Triangle.h"
#include "Trace/Trace.h"
#include "Async/Async.h"
#include "DrawDebugHelpers.h"

#include "Engine/World.h"

#include "VH_Developer/Core/Public/Developer_Statics.h"

constexpr int32 GLeafThreshold = 8;
constexpr int32 GNumBins = 16;
constexpr int32 GMaxTreeLayers = 64; //  Can increase this or decrease as needed
const double GOneThird = 1.0 / 3.0;

static FORCEINLINE void GetPlaneNormal(const FVector& p0, const FVector& p1, const FVector& p2, FVector& outNormal)
{
	const FVector AB = p1 - p0;
	const FVector AC = p2 - p0;

	outNormal = AC.Cross(AB).GetUnsafeNormal();
}

static FORCEINLINE bool RayToPlaneIntersection(const FVector& start, const FVector& dir, const FVector& planeOrigin, const FVector& planeNormal, FVector& OutIntersection)
{
	// Denominator = N·D
	const double Den = planeNormal | dir;

	// Only front-facing planes
	if (Den >= 0.0)
	{
		return false;
	}

	// Numerator = N·(O - P0)
	const double Num = planeNormal | (start - planeOrigin);

	// Calculate the intersection point
	double t = -Num / Den;
	if (t >= 0.0)
	{
		OutIntersection = start + dir * t;
		return true;
	}
	return false; // Intersection is outside the line segment
}

static FORCEINLINE FVector ComputeBaryCentric2D(const FVector& point, const FVector& p0, const FVector& p1, const FVector& p2, const FVector& planeNormal)
{
	// Compute the normal of the triangle
	const FVector TriNorm = (p1 - p0) ^ (p2 - p0);
	
	// Compute twice area of triangle ABC
	const FVector::FReal AreaABCInv = 1.0 / (planeNormal | TriNorm);
	
	// Compute a contribution
	const FVector::FReal AreaPBC = planeNormal | ((p1 - point) ^ (p2 - point));
	const FVector::FReal a = AreaPBC * AreaABCInv;
	
	// Compute b contribution
	const FVector::FReal AreaPCA = planeNormal | ((p2 - point) ^ (p0 - point));
	const FVector::FReal b = AreaPCA * AreaABCInv;
	
	// Compute c contribution
	return FVector(a, b, 1.0 - a - b);
}

static FORCEINLINE bool RayTriangleIntersection(const FVector& start, const FVector& dir, const FVector& p0, const FVector& p1, const FVector& p2, const FVector& triNormal, const FVector& triCentroid, FVector& OutIntersectPoint)
{
	if (!RayToPlaneIntersection(start, dir, triCentroid, triNormal, OutIntersectPoint))
	{
		return false;
	}

	const FVector BaryCentric = ComputeBaryCentric2D(OutIntersectPoint, p0, p1, p2, -triNormal);
	return BaryCentric.X >= 0.0 && BaryCentric.Y >= 0.0 && BaryCentric.Z >= 0.0;
}

static FORCEINLINE bool RayAABBIntersect(const FBox& box, const FVector& origin, const FVector& invDir)
{
	// X slabs
	double t1 = (box.Min.X - origin.X) * invDir.X;
	double t2 = (box.Max.X - origin.X) * invDir.X;
	double tmin = FMath::Min(t1, t2);
	double tmax = FMath::Max(t1, t2);
	
	// Y slabs
	t1 = (box.Min.Y - origin.Y) * invDir.Y;
	t2 = (box.Max.Y - origin.Y) * invDir.Y;
	tmin = FMath::Max(tmin, FMath::Min(t1, t2));
	tmax = FMath::Min(tmax, FMath::Max(t1, t2));
	
	// Early out if no overlap
	if (tmax < tmin)
	{
		return false;
	}
	
	// Z slabs
	t1 = (box.Min.Z - origin.Z) * invDir.Z;
	t2 = (box.Max.Z - origin.Z) * invDir.Z;
	tmin = FMath::Max(tmin, FMath::Min(t1, t2));
	tmax = FMath::Min(tmax, FMath::Max(t1, t2));
	
	return (tmax >= tmin) && (tmax >= 0.0);
}

double FORCEINLINE GetSurfaceArea(const FBox& Box)
{
	const FVector Extent = Box.Max - Box.Min;
	return 2.0 * (Extent.X * Extent.Y + Extent.Y * Extent.Z + Extent.Z * Extent.X);
}


// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_KdTree_Terrain::UGame_KdTree_Terrain() :
	bBuildRunning(false),
	bIsReady(false)
{
}


// ---------------------------------
// --- API
// ---------------------------------

void UGame_KdTree_Terrain::Build()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(VR-TAK UGame_KdTree_Terrain::Build);

	bBuildRunning = true;

	// Prepare a list of triangle IDs (0..NumTris-1)
	const int32 nNumTris = StagedIndices.Num() / 3;
	const int32 nNumIndices = StagedIndices.Num();

	// Reserve enough nodes (rough heuristic)
	Nodes.Empty(nNumTris * 2);

	TArray<int32> triangleIds;
	triangleIds.Reserve(nNumTris);
	for (int32 i = 0; i < nNumIndices; i += 3)
	{
		triangleIds.Add(i);
	}

	RootNode = BuildRecursive_SAH(triangleIds, 0, nNumTris);
	bIsReady = true;
	bBuildRunning = false;
}

void UGame_KdTree_Terrain::AsyncBuild()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(VR-TAK UGame_KdTree_Terrain::AsyncBuild);

	bBuildRunning = true;
	Async(EAsyncExecution::ThreadPool, [this]()
	{
		// Prepare a list of triangle IDs (0..NumTris-1)
		const int32 nNumTris = StagedIndices.Num() / 3;
		const int32 nNumIndices = StagedIndices.Num();

		// Reserve enough nodes (rough heuristic)
		Nodes.Empty(nNumTris * 2);

		TArray<int32> triangleIds;
		triangleIds.Reserve(nNumTris);
		for (int32 i = 0; i < nNumIndices; i += 3)
		{
			triangleIds.Add(i);
		}

		// Build recursively
		RootNode = AsyncBuildRecursive_SAH(triangleIds, 0, nNumTris);
		bBuildRunning = false;
		bIsReady = true;
	});
}

void UGame_KdTree_Terrain::Append(const TArray<FVector>& points, const TArray<int32>& triangles)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(VR-TAK UGame_KdTree_Terrain::Append);

	if (bIsReady)
	{
		StagedPoints.Empty(StagedPoints.Num());
		StagedIndices.Empty(StagedIndices.Num());
	}

	bIsReady = false;
	StagedPoints.Append(points);
	StagedIndices.Append(triangles);
}

bool UGame_KdTree_Terrain::LineTrace(const FVector& start, const FVector& dir, FVector& outClosestPoint) const
{
	return TraverseNode_LineTrace(0, start, dir, outClosestPoint);
}

void UGame_KdTree_Terrain::Stop()
{
	bBuildRunning = false;
}

bool UGame_KdTree_Terrain::IsReady() const
{
	return bIsReady;
}

bool UGame_KdTree_Terrain::IsBuilding() const
{
	return bBuildRunning;
}


// ---------------------------------
// --- Implementation
// ---------------------------------

int32 UGame_KdTree_Terrain::CreateLeafNode(const TArray<int32>& tris, int32 start, int32 end)
{
	int32 NodeIndex = Nodes.AddDefaulted();
	FGame_KdNode& Node = Nodes[NodeIndex];
	Node.Bounds.Init();
	Node.Bounds.IsValid = 1;

	for (int32 i = start; i < end; ++i)
	{
		const int32 Idx = tris[i];
		const FVector& A = StagedPoints[StagedIndices[Idx]];
		const FVector& B = StagedPoints[StagedIndices[Idx + 1]];
		const FVector& C = StagedPoints[StagedIndices[Idx + 2]];

		Node.Bounds += A;
		Node.Bounds += B;
		Node.Bounds += C;

		Node.TriangleIndices.Add(StagedIndices[Idx]);
		Node.TriangleIndices.Add(StagedIndices[Idx + 1]);
		Node.TriangleIndices.Add(StagedIndices[Idx + 2]);

		Node.Points.Add((A + B + C) * GOneThird);
		FVector Normal; GetPlaneNormal(A, B, C, Normal);
		Node.Normals.Add(Normal);
	}

	return NodeIndex;
}

int32 UGame_KdTree_Terrain::BuildRecursive_SAH(TArray<int32>& Tris, int32 Start, int32 End)
{
	int32 Count = End - Start;
	if (Count <= GLeafThreshold)
	{
		return CreateLeafNode(Tris, Start, End);
	}

	FBox Bounds(ForceInit);
	for (int32 i = Start; i < End; ++i)
	{
		const int32 Idx = Tris[i];
		Bounds += StagedPoints[StagedIndices[Idx]];
		Bounds += StagedPoints[StagedIndices[Idx + 1]];
		Bounds += StagedPoints[StagedIndices[Idx + 2]];
	}

	FVector Extent = Bounds.GetSize();
	int32 Axis = (Extent.X > Extent.Y) ? ((Extent.X > Extent.Z) ? 0 : 2) : ((Extent.Y > Extent.Z) ? 1 : 2);

	// Compute binning information
	struct BinInfo
	{
		FBox Bounds = FBox(ForceInit);
		int32 Count = 0;
	} Bins[GNumBins];

	const double MinBound = Bounds.Min[Axis];
	const double MaxBound = Bounds.Max[Axis];
	const double Scale = MaxBound > MinBound ? (GNumBins / (MaxBound - MinBound)) : 0.0;

	for (int32 i = Start; i < End; ++i)
	{
		const int32 nTriId = Tris[i];

		FVector Centroid = (StagedPoints[StagedIndices[nTriId]] + StagedPoints[StagedIndices[nTriId + 1]] + StagedPoints[StagedIndices[nTriId + 2]]) * GOneThird;
		int32 nBinIndex = FMath::Clamp(int32((Centroid[Axis] - MinBound) * Scale), 0, GNumBins - 1);

		Bins[nBinIndex].Bounds += StagedPoints[StagedIndices[nTriId]];
		Bins[nBinIndex].Bounds += StagedPoints[StagedIndices[nTriId + 1]];
		Bins[nBinIndex].Bounds += StagedPoints[StagedIndices[nTriId + 2]];
		++Bins[nBinIndex].Count;
	}

	double BestCost = FLT_MAX;
	int32 BestSplit = -1;

	FBox LeftBoxes[GNumBins];
	FBox RightBoxes[GNumBins];
	int32 LeftCounts[GNumBins] = {};
	int32 RightCounts[GNumBins] = {};

	FBox AccumLeft(ForceInit);
	int32 CountLeft = 0;
	for (int32 i = 0; i < GNumBins - 1; ++i)
	{
		AccumLeft += Bins[i].Bounds;
		CountLeft += Bins[i].Count;
		LeftBoxes[i] = AccumLeft;
		LeftCounts[i] = CountLeft;
	}

	FBox AccumRight(ForceInit);
	int32 CountRight = 0;
	for (int32 i = GNumBins - 1; i > 0; --i)
	{
		AccumRight += Bins[i].Bounds;
		CountRight += Bins[i].Count;
		RightBoxes[i - 1] = AccumRight;
		RightCounts[i - 1] = CountRight;
	}

	double ParentSA = GetSurfaceArea(Bounds);
	for (int32 i = 0; i < GNumBins - 1; ++i)
	{
		double SALeft = GetSurfaceArea(LeftBoxes[i]);
		double SARight = GetSurfaceArea(RightBoxes[i]);
		double Cost = 0.125 + (SALeft * LeftCounts[i] + SARight * RightCounts[i]) / ParentSA;

		if (Cost < BestCost)
		{
			BestCost = Cost;
			BestSplit = i;
		}
	}

	if (BestSplit == -1 || BestCost >= Count)
	{
		return CreateLeafNode(Tris, Start, End);
	}

	// Partition triangles
	TArray<int32> LeftTris, RightTris;
	for (int32 i = Start; i < End; ++i)
	{
		const int32 nTriId = Tris[i];

		FVector Centroid = (StagedPoints[StagedIndices[nTriId]] + StagedPoints[StagedIndices[nTriId + 1]] + StagedPoints[StagedIndices[nTriId + 2]]) * GOneThird;
		int32 nBinIndex = FMath::Clamp(int32((Centroid[Axis] - MinBound) * Scale), 0, GNumBins - 1);

		if (nBinIndex <= BestSplit)
		{
			LeftTris.Add(nTriId);
		}
		else
		{
			RightTris.Add(nTriId);
		}
	}

	int32 NodeIndex = Nodes.Add(FGame_KdNode());
	FGame_KdNode& Node = Nodes[NodeIndex];
	Node.Bounds = Bounds;

	Node.Left = BuildRecursive_SAH(LeftTris, 0, LeftTris.Num());
	Node.Right = BuildRecursive_SAH(RightTris, 0, RightTris.Num());

	return NodeIndex;
}

int32 UGame_KdTree_Terrain::AsyncBuildRecursive_SAH(TArray<int32>& Tris, int32 Start, int32 End)
{
	int32 Count = End - Start;
	if (Count <= GLeafThreshold)
	{
		return CreateLeafNode(Tris, Start, End);
	}

	FBox Bounds(ForceInit);
	for (int32 i = Start; i < End && bBuildRunning; ++i)
	{
		const int32 Idx = Tris[i];
		Bounds += StagedPoints[StagedIndices[Idx]];
		Bounds += StagedPoints[StagedIndices[Idx + 1]];
		Bounds += StagedPoints[StagedIndices[Idx + 2]];
	}

	FVector Extent = Bounds.GetSize();
	int32 Axis = (Extent.X > Extent.Y) ? ((Extent.X > Extent.Z) ? 0 : 2) : ((Extent.Y > Extent.Z) ? 1 : 2);

	// Compute binning information
	struct BinInfo
	{
		FBox Bounds = FBox(ForceInit);
		int32 Count = 0;
	} Bins[GNumBins];

	const double MinBound = Bounds.Min[Axis];
	const double MaxBound = Bounds.Max[Axis];
	const double Scale = MaxBound > MinBound ? (GNumBins / (MaxBound - MinBound)) : 0.0;

	for (int32 i = Start; i < End && bBuildRunning; ++i)
	{
		const int32 nTriId = Tris[i];

		FVector Centroid = (StagedPoints[StagedIndices[nTriId]] + StagedPoints[StagedIndices[nTriId + 1]] + StagedPoints[StagedIndices[nTriId + 2]]) * GOneThird;
		int32 nBinIndex = FMath::Clamp(int32((Centroid[Axis] - MinBound) * Scale), 0, GNumBins - 1);

		Bins[nBinIndex].Bounds += StagedPoints[StagedIndices[nTriId]];
		Bins[nBinIndex].Bounds += StagedPoints[StagedIndices[nTriId + 1]];
		Bins[nBinIndex].Bounds += StagedPoints[StagedIndices[nTriId + 2]];
		++Bins[nBinIndex].Count;
	}

	double BestCost = FLT_MAX;
	int32 BestSplit = -1;

	FBox LeftBoxes[GNumBins];
	FBox RightBoxes[GNumBins];
	int32 LeftCounts[GNumBins] = {};
	int32 RightCounts[GNumBins] = {};

	FBox AccumLeft(ForceInit);
	int32 CountLeft = 0;
	for (int32 i = 0; i < GNumBins - 1 && bBuildRunning; ++i)
	{
		AccumLeft += Bins[i].Bounds;
		CountLeft += Bins[i].Count;
		LeftBoxes[i] = AccumLeft;
		LeftCounts[i] = CountLeft;
	}

	FBox AccumRight(ForceInit);
	int32 CountRight = 0;
	for (int32 i = GNumBins - 1; i > 0 && bBuildRunning; --i)
	{
		AccumRight += Bins[i].Bounds;
		CountRight += Bins[i].Count;
		RightBoxes[i - 1] = AccumRight;
		RightCounts[i - 1] = CountRight;
	}

	double ParentSA = GetSurfaceArea(Bounds);
	for (int32 i = 0; i < GNumBins - 1 && bBuildRunning; ++i)
	{
		double SALeft = GetSurfaceArea(LeftBoxes[i]);
		double SARight = GetSurfaceArea(RightBoxes[i]);
		double Cost = 0.125 + (SALeft * LeftCounts[i] + SARight * RightCounts[i]) / ParentSA;

		if (Cost < BestCost)
		{
			BestCost = Cost;
			BestSplit = i;
		}
	}

	if (BestSplit == -1 || BestCost >= Count)
	{
		return CreateLeafNode(Tris, Start, End);
	}

	// Partition triangles
	TArray<int32> LeftTris, RightTris;
	for (int32 i = Start; i < End && bBuildRunning; ++i)
	{
		const int32 nTriId = Tris[i];

		FVector Centroid = (StagedPoints[StagedIndices[nTriId]] + StagedPoints[StagedIndices[nTriId + 1]] + StagedPoints[StagedIndices[nTriId + 2]]) * GOneThird;
		int32 nBinIndex = FMath::Clamp(int32((Centroid[Axis] - MinBound) * Scale), 0, GNumBins - 1);

		if (nBinIndex <= BestSplit)
		{
			LeftTris.Add(nTriId);
		}
		else
		{
			RightTris.Add(nTriId);
		}
	}

	int32 NodeIndex = Nodes.Add(FGame_KdNode());
	FGame_KdNode& Node = Nodes[NodeIndex];
	Node.Bounds = Bounds;

	Node.Left = AsyncBuildRecursive_SAH(LeftTris, 0, LeftTris.Num());
	Node.Right = AsyncBuildRecursive_SAH(RightTris, 0, RightTris.Num());

	return NodeIndex;
}

bool UGame_KdTree_Terrain::TraverseNode_LineTrace(int32 nodeIndex, const FVector& start, const FVector& dir, FVector& outHit) const
{
	const FVector invDir = FVector(1.0 / dir.X, 1.0 / dir.Y, 1.0 / dir.Z);

	int32 stack[GMaxTreeLayers];
	int32 nStackTop = 0;
	stack[nStackTop] = RootNode;
	++nStackTop;

	for (; nStackTop; )
	{
		const FGame_KdNode& Node = Nodes[stack[--nStackTop]];

		if (RayAABBIntersect(Node.Bounds, start, invDir))
		{
			const int32 nNumIndices = Node.TriangleIndices.Num();
			for (int32 i = 0, j = 0; i < nNumIndices; i += 3, ++j)
			{
				const FVector A = StagedPoints[Node.TriangleIndices[i]];
				const FVector B = StagedPoints[Node.TriangleIndices[i + 1]];
				const FVector C = StagedPoints[Node.TriangleIndices[i + 2]];

				if (RayTriangleIntersection(start, dir, A, B, C, Node.Normals[j], Node.Points[j], outHit))
				{
					return true;
				}
			}

			if (Node.Left >= 0)
			{
				stack[nStackTop] = Node.Left;
				++nStackTop;
			}

			if (Node.Right >= 0)
			{
				stack[nStackTop] = Node.Right;
				++nStackTop;
			}
		}
	}

	return false;
}
