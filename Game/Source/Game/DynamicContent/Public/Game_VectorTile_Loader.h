#pragma once

// Parent Includes
#include "UObject/NoExportTypes.h"
#include "HAL/Runnable.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Plugin Includes
#include "vtzero/vector_tile.hpp"

// Game Includes
#include "Game_ImportedMeshComponent.h"


class AVH_GlobeReferenceActor;
class AGame_VectorTile_Actor;
class UVH_MeshInfo;


DECLARE_DELEGATE_OneParam(FGame_VectorTile_Delegate, AGame_VectorTile_Actor*)


struct FGame_VectorTile_VertexBuffer
{
	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	double Height;
	double MinHeight;
};


struct FGame_VectorTile_Feature
{
	TArray<TArray<FVector2D>> Rings;
	TMap<FString, FString> Properties;
	int32 TotalPoints;

	FGame_VectorTile_Feature() :
		TotalPoints(0) { }
};


struct FGame_VectorTile_Layer
{
	FString Name;
	TMap<FString, FGame_VectorTile_Feature> Features;
	int32 TotalPoints;

	FGame_VectorTile_Layer() {}
	FGame_VectorTile_Layer(const FString& name) :
		Name(name),
		TotalPoints(0) {}
};


struct FGame_VectorTile
{
	TArray<uint8> Data;
	TMap<FString, FGame_VectorTile_Layer> Layers;
	FIntPoint Tile;
	int32 ZoomLevel;
	int32 TotalPoints;
	int32 TotalTriangles;

	FGame_VectorTile() :
		Tile(0, 0),
		ZoomLevel(12),
		TotalPoints(0),
		TotalTriangles(0) { }
};


class UGame_VectorTile_Parser
{
	class UGame_VectorTile_GeometryHandler
	{
		// ---------------------------------
		// --- Variables
		// ---------------------------------

		FGame_VectorTile_Feature* Feature;


		// ---------------------------------
		// --- Constructors
		// ---------------------------------

	public:

		UGame_VectorTile_GeometryHandler(FGame_VectorTile_Feature* feature);


		// ---------------------------------
		// --- Vector Tile API
		// ---------------------------------

		void ring_begin(uint32_t count);
		void ring_point(const vtzero::point& point);
		void ring_end(vtzero::ring_type type);

		void linestring_begin(uint32_t count);
		void linestring_point(const vtzero::point& point);
		void linestring_end();

		void points_begin(uint32_t count);
		void points_point(const vtzero::point& point);
		void points_end();
	};


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:

	static int32 NewId;


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:

	static bool Parse(const TArray<uint8>& data, FGame_VectorTile& vectorTile);


private:

	static FString GetUniqueId(uint64_t id);
};


class UGame_VectorTile_Generator
{


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:

	static void Generate(FGame_VectorTile& vectorTile, TMap<FString, FGame_VectorTile_VertexBuffer>& outVertexBuffers, bool* isRunning);
	static AGame_VectorTile_Actor* BuildMesh(FGame_VectorTile& vectorTile, TMap<FString, FGame_VectorTile_VertexBuffer>& vertexBuffers, FGame_VectorTile_Delegate onBuildFinishedDelegate, bool* isRunning);
	static void CalculateTileBounds(const FGame_VectorTile& vectorTile, FGeodeticCoord2D& outNorthWest, FGeodeticCoord2D& outSouthEast);


private:

	static void GenerateLayer_Buildings(FGame_VectorTile& vectorTile, FGame_VectorTile_Layer& layer, TMap<FString, FGame_VectorTile_VertexBuffer>& outVertexBuffers, bool* isRunning);
	static void GenerateLayer_Roads(FGame_VectorTile& vectorTile, FGame_VectorTile_Layer& layer, TMap<FString, FGame_VectorTile_VertexBuffer>& outVertexBuffers, bool* isRunning);
	static void GenerateBuilding(FGame_VectorTile& vectorTile, FGame_VectorTile_Feature& feature, TMap<FString, FGame_VectorTile_VertexBuffer>& outVertexBuffers, FGame_VectorTile_VertexBuffer& outBuffer, bool* isRunning);
	static void GenerateBuildingIndices(FGame_VectorTile_Feature& feature, FGame_VectorTile_VertexBuffer& outBuffer, bool* isRunning);
	static void GenerateBuildingVertices(FGame_VectorTile& vectorTile, FGame_VectorTile_Feature& feature, TMap<FString, FGame_VectorTile_VertexBuffer>& outVertexBuffers, FGame_VectorTile_VertexBuffer& outBuffer, bool* isRunning);
	static void SpawnVectorTileActor(UVH_MeshInfo* meshInfo, FGame_VectorTile_Delegate onBuildFinishedDelegate);
	static FGeodeticCoord3D CalculateWorldPos(const FVector2D& tilePos, const FGeodeticCoord2D& tileNW, const FGeodeticCoord2D& tileSE, FVector& outWorldPos, AVH_GlobeReferenceActor* globeRef, bool* isRunning);
	static UVH_MeshInfo* CreateMeshInfo();
	static AVH_GlobeReferenceActor* GetGlobeRef();
};


class Game_VectorTile_Task : public FRunnable
{

	// ---------------------------------
	// --- Delegates
	// ---------------------------------

public:

	FGame_VectorTile_Delegate VectorTileFinishedDelegate;


	// ---------------------------------
	// --- Variables
	// ---------------------------------

private:

	TMap<FIntPoint, FGame_VectorTile> VectorTiles;
	FRunnableThread* Thread;
	FCriticalSection VectorTilesMutex;
	bool bIsRunning;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:

	Game_VectorTile_Task();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:

	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	virtual void Exit() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:

	void QueueTile(const FIntPoint tile, int32 zoomLevel, const TArray<uint8>& data);
	void StartThread();
	void StopThread();
};
