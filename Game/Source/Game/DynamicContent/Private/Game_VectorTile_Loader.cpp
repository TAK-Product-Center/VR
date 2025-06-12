// Required Includes
#include "Game_VectorTile_Loader.h"
#include "Game.h"

// Engine Includes
#include "Kismet/KismetMaterialLibrary.h"
#include "HAL/RunnableThread.h"

// VH Plugin Includes
#include "VH_MeshInfo.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_GlobeMathStatics.h"
#include "VH_GlobeCoordConverter.h"

// Plugin Includes
#include "vtzero/vector_tile.hpp"

// Game Includes
#include "Game_PlayerController.h"
#include "Game_VirtualObjective.h"
#include "Game_TileUtilities.h"
#include "earcut.hpp"
#include "Game_VectorTile_Actor.h"
#include "Game_ImportedMeshComponent_VectorTile.h"


#define TILE_SIZE				(256)
#define TILE_EXTENT				(4096)
#define VECTOR_TILE_MATERIAL	TEXT("/Script/Engine.Material'/Game/VTAK/Materials/M_ShapePolyFill.M_ShapePolyFill'")


const FString GIdPropertyName				= TEXT("id");
const FString GTypePropertyName				= TEXT("type");
const FString GHeightPropertyName			= TEXT("height");
const FString GMinHeightPropertyName		= TEXT("min_height");
const FString GBuildingIdPropertyName		= TEXT("building_id");
const FString GBuildingPartPropertyName		= TEXT("building:part");

int32 UGame_VectorTile_Parser::NewId = 0;


// Helpers
namespace TileUtilities
{
	template <typename ObjClass>
	static ObjClass* LoadObjFromPath(const FName& Path)
	{
		if (Path == NAME_None) return nullptr;

		return Cast<ObjClass>(StaticLoadObject(ObjClass::StaticClass(), nullptr, *Path.ToString()));
	}

	static UMaterial* LoadMaterialFromPath(const FName& Path)
	{
		if (Path == NAME_None) return nullptr;

		return LoadObjFromPath<UMaterial>(Path);
	}
};


// ---------------------------------
// --- Static Functions
// ---------------------------------

bool UGame_VectorTile_Parser::Parse(const TArray<uint8>& data, FGame_VectorTile& vectorTile)
{
	if (data.Num())
	{
		// Initialize the vtzero tile with the PBF data
		vtzero::vector_tile vt((const char*)data.GetData(), data.Num());
	
		const FIntPoint tileSize(4096, 4096); // Size of the vector tiles we receive from MapBox are all 4096x4096

		// Iterate through layers in the tile
		vt.for_each_layer([&tileSize, &vectorTile](vtzero::layer layer)
		{
			const FString layerName = ANSI_TO_TCHAR(layer.name().to_string().c_str());

			// TODO: [TJ] Need to account for more than building layers eventually
			// Skipping everything that isn't building to improve performance (especially in dense city areas)
			if (layerName != TEXT("building"))
			{
				return true;
			}

			// New Layer
			FGame_VectorTile_Layer& Layer = vectorTile.Layers.Add(layerName, FGame_VectorTile_Layer());
			Layer.Name = layerName;

			// Iterate features in the layer
			while (vtzero::feature feature = layer.next_feature())
			{
				// Need to guarantee a unique ID for features that don't have an ID
				const FString sId = GetUniqueId(feature.id());

				FGame_VectorTile_Feature& Feature = Layer.Features.Add(sId, FGame_VectorTile_Feature());
				Feature.Properties.Add(GIdPropertyName, sId);
			
				// Extract properties (tags)
				feature.for_each_property(
					[&Feature](const vtzero::property& property)
					{
						// Name of the property
						FString sPropertyName = ANSI_TO_TCHAR(property.key().to_string().c_str());
						FString sValue;
						vtzero::PropertyToString(property.value(), sValue);

						Feature.Properties.Add(sPropertyName, sValue);
						return true;
					});

				vtzero::decode_geometry(feature.geometry(), UGame_VectorTile_GeometryHandler(&Feature));

				// Pre-calculating points as a micro-optimization for later
				for (int32 i = 0; i < Feature.Rings.Num(); ++i)
				{
					Layer.TotalPoints += Feature.Rings[i].Num();
				}
			}

			return true;
		});

		return vectorTile.Layers.Num() > 0;
	}
	return false;
}

FString UGame_VectorTile_Parser::GetUniqueId(uint64_t id)
{
	if (id > 0)
	{
		return FString::Printf(TEXT("%d"), id);
	}
	else
	{
		++NewId;
		return FString::Printf(TEXT("[%d]"), NewId);
	}
}


// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_VectorTile_Parser::UGame_VectorTile_GeometryHandler::UGame_VectorTile_GeometryHandler(FGame_VectorTile_Feature* feature) :
	Feature(feature)
{
	check(feature != nullptr);
}


// ---------------------------------
// --- Vector Tile API
// ---------------------------------

void UGame_VectorTile_Parser::UGame_VectorTile_GeometryHandler::ring_begin(uint32_t count)
{
	Feature->Rings.Add(TArray<FVector2D>());
	Feature->Rings.Last().Reserve(static_cast<int32>(count));
	Feature->TotalPoints += static_cast<int32>(count) - 1;
}

void UGame_VectorTile_Parser::UGame_VectorTile_GeometryHandler::ring_point(const vtzero::point& point)
{
	Feature->Rings.Last().Add(FVector2D(point.x, point.y));
}

void UGame_VectorTile_Parser::UGame_VectorTile_GeometryHandler::ring_end(vtzero::ring_type type)
{
	// Removing the last point on the ring because it's always the same as the first point.  We don't need it.
	Feature->Rings.Last().RemoveAt(Feature->Rings.Last().Num() - 1);
}

void UGame_VectorTile_Parser::UGame_VectorTile_GeometryHandler::linestring_begin(uint32_t count)
{
	Feature->Rings.Add(TArray<FVector2D>());
	Feature->Rings.Last().Reserve(static_cast<int32>(count));
	Feature->TotalPoints += static_cast<int32>(count);
}

void UGame_VectorTile_Parser::UGame_VectorTile_GeometryHandler::linestring_point(const vtzero::point& point)
{
	Feature->Rings.Last().Add(FVector2D(point.x, point.y));
}

void UGame_VectorTile_Parser::UGame_VectorTile_GeometryHandler::linestring_end()
{
	// Nothing to do here...
}

void UGame_VectorTile_Parser::UGame_VectorTile_GeometryHandler::points_begin(uint32_t count)
{
	Feature->Rings.Add(TArray<FVector2D>());
	Feature->Rings.Last().Reserve(static_cast<int32>(count));
	Feature->TotalPoints += static_cast<int32>(count) - 1;
}

void UGame_VectorTile_Parser::UGame_VectorTile_GeometryHandler::points_point(const vtzero::point& point)
{
	Feature->Rings.Last().Add(FVector2D(point.x, point.y));
}

void UGame_VectorTile_Parser::UGame_VectorTile_GeometryHandler::points_end()
{
	// Nothing to do here...
}


// ---------------------------------
// --- Static Functions
// ---------------------------------

void UGame_VectorTile_Generator::Generate(FGame_VectorTile& vectorTile, TMap<FString, FGame_VectorTile_VertexBuffer>& outVertexBuffers, bool* isRunning)
{
	// Grabbing all layers
	TMap<FString, FGame_VectorTile_Layer>::TIterator layerIter(vectorTile.Layers);
	for (; layerIter && (*isRunning); ++layerIter)
	{
		FGame_VectorTile_Layer& layer = layerIter.Value();

		// NOTE: At the moment, only "building" layers exist - TJ A. (Search "TODO: [TJ]")
		if (layer.Name == TEXT("building"))
		{
			GenerateLayer_Buildings(vectorTile, layer, outVertexBuffers, isRunning);
		}
		else if (layer.Name == TEXT("road"))
		{
			GenerateLayer_Roads(vectorTile, layer, outVertexBuffers, isRunning);
		}
	}
}

AGame_VectorTile_Actor* UGame_VectorTile_Generator::BuildMesh(FGame_VectorTile& vectorTile, TMap<FString, FGame_VectorTile_VertexBuffer>& vertexBuffers, FGame_VectorTile_Delegate onBuildFinishedDelegate, bool* isRunning)
{
	if (UVH_MeshInfo* pMeshInfo = CreateMeshInfo())
	{
		FVH_MeshImportMeshData& mesh = pMeshInfo->MeshDataList[0];
		mesh.Vertices.Reserve(vectorTile.TotalPoints);
		mesh.Triangles.Reserve(vectorTile.TotalTriangles);

		// Add Vertices
		FVector normal = FVector::UpVector;
		TMap<FString, FGame_VectorTile_VertexBuffer>::TIterator iter(vertexBuffers);
		for (; iter && (*isRunning); ++iter)
		{
			const FGame_VectorTile_VertexBuffer& buffer = iter->Value;

			// Add Positions
			const int32 nStartIndex = mesh.Vertices.Num();
			mesh.Vertices.Append(buffer.Vertices);

			// Add Normals
			const int32 nNumVerts = buffer.Vertices.Num();
			for (int32 i = 0; i < nNumVerts && (*isRunning); ++i)
			{
				if (normal == FVector::UpVector)
				{
					// Cheap way to calculate the "Up Vector" which works in the world map.
					normal = buffer.Vertices[i] - buffer.Vertices[i + buffer.Vertices.Num() / 2];
					normal.Normalize();
				}
				mesh.Normals.Add(normal);
			}

			// Add Triangles
			const int32 nNumTriangles = buffer.Triangles.Num();
			for (int32 i = 0; i < nNumTriangles && (*isRunning); i += 3)
			{
				mesh.Triangles.Add(nStartIndex + buffer.Triangles[i]);
				mesh.Triangles.Add(nStartIndex + buffer.Triangles[i + 1]);
				mesh.Triangles.Add(nStartIndex + buffer.Triangles[i + 2]);
			}
		}

		if (*isRunning)
		{
			SpawnVectorTileActor(pMeshInfo, onBuildFinishedDelegate);
		}
	}

	return nullptr;
}

void UGame_VectorTile_Generator::GenerateLayer_Buildings(FGame_VectorTile& vectorTile, FGame_VectorTile_Layer& layer, TMap<FString, FGame_VectorTile_VertexBuffer>& outVertexBuffers, bool* isRunning)
{
	TMap<FString, FGame_VectorTile_Feature>::TIterator featureIter(layer.Features);
	for (; featureIter && (*isRunning); ++featureIter)
	{
		if (featureIter.Value().TotalPoints >= 3)
		{
			const FString& sId = featureIter.Value().Properties[GIdPropertyName];
			GenerateBuilding(vectorTile, featureIter.Value(), outVertexBuffers, outVertexBuffers.FindOrAdd(sId), isRunning);
		}
	}
}

void UGame_VectorTile_Generator::GenerateLayer_Roads(FGame_VectorTile& vectorTile, FGame_VectorTile_Layer& layer, TMap<FString, FGame_VectorTile_VertexBuffer>& outVertexBuffers, bool* isRunning)
{
}

void UGame_VectorTile_Generator::CalculateTileBounds(const FGame_VectorTile& vectorTile, FGeodeticCoord2D& outNorthWest, FGeodeticCoord2D& outSouthEast)
{
	outNorthWest = TileUtilities::GetNorthwestCoordinate(TPair<int32, int32>(vectorTile.Tile.X, vectorTile.Tile.Y), vectorTile.ZoomLevel);
	outSouthEast = TileUtilities::GetNorthwestCoordinate(TPair<int32, int32>(vectorTile.Tile.X + 1, vectorTile.Tile.Y + 1), vectorTile.ZoomLevel);
}

void UGame_VectorTile_Generator::GenerateBuilding(FGame_VectorTile& vectorTile, FGame_VectorTile_Feature& feature, TMap<FString, FGame_VectorTile_VertexBuffer>& outVertexBuffers, FGame_VectorTile_VertexBuffer& outBuffer, bool* isRunning)
{
	outBuffer.Height	= FCString::Atod(*feature.Properties[GHeightPropertyName]);
	outBuffer.MinHeight	= FCString::Atod(*feature.Properties[GMinHeightPropertyName]);
	outBuffer.Vertices.Reserve(feature.TotalPoints * 2); // Double it to account for both roof/floor vertices

	// Tile Coordinates
	if (*isRunning)
	{
		GenerateBuildingIndices(feature, outBuffer, isRunning);
	}

	if (*isRunning)
	{
		GenerateBuildingVertices(vectorTile, feature, outVertexBuffers, outBuffer, isRunning);
	}

	vectorTile.TotalPoints += outBuffer.Vertices.Num();
	vectorTile.TotalTriangles += outBuffer.Triangles.Num();
}

void UGame_VectorTile_Generator::GenerateBuildingIndices(FGame_VectorTile_Feature& feature, FGame_VectorTile_VertexBuffer& outBuffer, bool* isRunning)
{
	// Cache these for simple use
	TArray<FVector2D>& vertices = feature.Rings[0];
	const int32 nNumPoints = vertices.Num();

	// Build the triangles and copy the index buffer
	TArray<uint32> indices = mapbox::earcut(feature.Rings);
	const int32 nNumIndices = indices.Num();

	outBuffer.Triangles.Reserve(nNumIndices + nNumPoints * 6);

	for (int32 i = 0; i < nNumIndices && (*isRunning); i += 3)
	{
		outBuffer.Triangles.Add(static_cast<int32>(indices[i]));
		outBuffer.Triangles.Add(static_cast<int32>(indices[i + 1]));
		outBuffer.Triangles.Add(static_cast<int32>(indices[i + 2]));
	}

	// Create the indices for the sides of the buildings
	for (int32 i = 0; i < nNumPoints && (*isRunning); ++i)
	{
		// For each edge, create two triangles forming a quad.
		// The mod allows it to wrap around to the first vertex (index 0) when reaching the end of the list.
		const int32 NextIndex = (i + 1) % nNumPoints;
			
		// First triangle of the side face
		outBuffer.Triangles.Add(i);					// Top point
		outBuffer.Triangles.Add(NextIndex);			// Next top point
		outBuffer.Triangles.Add(i + nNumPoints);	// Ground point
			
		// Second triangle of the side face
		outBuffer.Triangles.Add(NextIndex);					// Next top point
		outBuffer.Triangles.Add(NextIndex + nNumPoints);	// Next ground point
		outBuffer.Triangles.Add(i + nNumPoints);			// ground point
	}

	// Need to merge the points from all the rings into one single list
	const int32 nNumRings = feature.Rings.Num();
	for (int32 i = 1; i < nNumRings; ++i)
	{
		vertices.Append(feature.Rings[i]);
	}
}

void UGame_VectorTile_Generator::GenerateBuildingVertices(FGame_VectorTile& vectorTile, FGame_VectorTile_Feature& feature, TMap<FString, FGame_VectorTile_VertexBuffer>& outVertexBuffers, FGame_VectorTile_VertexBuffer& outBuffer, bool* isRunning)
{
	// Need a valid globe reference actor to properly caclulate world locations
	AVH_GlobeReferenceActor* pGlobeRef = GetGlobeRef();
	if (!IsValid(pGlobeRef))
	{
		return;
	}

	// Cache this for simple use
	TArray<FVector2D>& vertices = feature.Rings[0];
	const int32 nNumPoints = vertices.Num();

	TArray<FGeodeticCoord3D> floorCoordinates;
	floorCoordinates.SetNumUninitialized(nNumPoints);

	FGeodeticCoord2D nw;
	FGeodeticCoord2D se;
	CalculateTileBounds(vectorTile, nw, se);

	// Calculate the floor positions for the building
	// Need to keep track of the highest point of the terrain for the building
	double maxFloorAltitude = -FLT_MAX;
	for (int32 i = 0; i < nNumPoints && (*isRunning); ++i)
	{
		FVector vertexPos;
		FGeodeticCoord3D floorCoordinate = CalculateWorldPos(vertices[i], nw, se, vertexPos, pGlobeRef, isRunning);
		floorCoordinates[i] = floorCoordinate;

		if (floorCoordinate.Altitude > maxFloorAltitude)
		{
			maxFloorAltitude = floorCoordinate.Altitude;
		}

		outBuffer.Vertices.Add(vertexPos);
	}

	// This will help with building sections.  May not be 100%, but gives solves most cases.
	if (feature.Properties[GTypePropertyName].Contains(TEXT(":"))) // A colon means we have a building part
	{
		const FString* pIter = feature.Properties.Find(GBuildingIdPropertyName);
		if (pIter)
		{
			// TODO: Need to store these meshes by building ID first
			FGame_VectorTile_VertexBuffer* pBaseBuilding = outVertexBuffers.Find(*pIter);
			if (pBaseBuilding)
			{
				if (pBaseBuilding->Height > outBuffer.MinHeight)
				{
					outBuffer.MinHeight = pBaseBuilding->Height;
				}
			}
		}
	}

	// Add the floor vertices to the building and update roof vertices
	double fBuildingAdjustedHeight = outBuffer.Height + outBuffer.MinHeight;
	for (int32 i = 0; i < nNumPoints && (*isRunning); ++i)
	{
		const double heightAboveFloor = maxFloorAltitude - floorCoordinates[i].Altitude + fBuildingAdjustedHeight;

		FVector floorPos = outBuffer.Vertices[i];

		FGeodeticCoord3D roofCoordinate = floorCoordinates[i];
		roofCoordinate.Altitude += heightAboveFloor;

		outBuffer.Vertices[i] = pGlobeRef->GeodeticToECEF(roofCoordinate);
		outBuffer.Vertices.Add(floorPos);
	}
}

void UGame_VectorTile_Generator::SpawnVectorTileActor(UVH_MeshInfo* meshInfo, FGame_VectorTile_Delegate onBuildFinishedDelegate)
{
	// Spawn the vector tile actor on the game thread
	AsyncTask(ENamedThreads::GameThread, [meshInfo, onBuildFinishedDelegate]()
	{
		UWorld* pWorld = UDeveloper_Statics::GetVHWorld();
		if (IsValid(pWorld))
		{
			bool bDestroyActor = true;
			AGame_VectorTile_Actor* pActor = pWorld->SpawnActor<AGame_VectorTile_Actor>();
		
			UGame_ImportedMeshComponent_VectorTile* VectorTileComponent = Cast<UGame_ImportedMeshComponent_VectorTile>(pActor->GetComponentByClass(UGame_ImportedMeshComponent_VectorTile::StaticClass()));
			if (IsValid(VectorTileComponent))
			{
				meshInfo->NodeList.Last().RelativeTransform = VectorTileComponent->GetRelativeTransform();
				meshInfo->bIsValid = meshInfo->MeshDataList.Num() && meshInfo->MeshDataList.Last().Vertices.Num() >= 3;
				if (meshInfo->bIsValid)
				{
					VectorTileComponent->MaterialOverride = UKismetMaterialLibrary::CreateDynamicMaterialInstance(pWorld, TileUtilities::LoadMaterialFromPath(VECTOR_TILE_MATERIAL));
					VectorTileComponent->SetMeshInfoAndBuild(meshInfo);
		
					onBuildFinishedDelegate.ExecuteIfBound(pActor);

					bDestroyActor = false;
				}
			}

			if (bDestroyActor)
			{
				pActor->Destroy();
				meshInfo->ConditionalBeginDestroy();
			}
		}
	});
}

FGeodeticCoord3D UGame_VectorTile_Generator::CalculateWorldPos(const FVector2D& tilePos, const FGeodeticCoord2D& tileNW, const FGeodeticCoord2D& tileSE, FVector& outWorldPos, AVH_GlobeReferenceActor* globeRef, bool* isRunning)
{
	// Convert the local position into a latitude and longitude
	FGeodeticCoord3D vertexCoordinate;
	vertexCoordinate.Longitude = FMath::Lerp<double>(tileNW.Longitude, tileSE.Longitude, tilePos.X / (TILE_EXTENT - 1.0));
	vertexCoordinate.Latitude = FMath::Lerp<double>(tileNW.Latitude, tileSE.Latitude, tilePos.Y / (TILE_EXTENT - 1.0));
	vertexCoordinate.Altitude = 0;
	vertexCoordinate.bIsAltitudeRelativeToGround = true;

	// NOTE: Setting these values skips the terrain elevation check and MASSIVELY improves load time
	// This means the LineTraces on the terrain are a huge performance hit.  Consider ways to improve this
	//vertexCoordinate.Altitude = 231.44986157305539;
	//vertexCoordinate.bIsAltitudeRelativeToGround = false;

	outWorldPos = globeRef->GeodeticToWorldDouble(vertexCoordinate);

	if (*isRunning)
	{
		return globeRef->WorldToGeodeticDouble(outWorldPos);
	}
	return vertexCoordinate;
}

UVH_MeshInfo* UGame_VectorTile_Generator::CreateMeshInfo()
{
	UWorld* pWorld = UDeveloper_Statics::GetVHWorld();
	if (IsValid(pWorld))
	{
		FVH_MeshImportMeshNode meshNode;
		meshNode.NodeIndex = 0;
		meshNode.Meshes.Add(0);

		FGCScopeGuard lock;
		UVH_MeshInfo* pMeshInfo = NewObject<UVH_MeshInfo>();
		pMeshInfo->MeshDataList.Add(FVH_MeshImportMeshData());
		pMeshInfo->NodeList.Add(meshNode);
		pMeshInfo->MaterialList.Add(TEXT(""));
		return pMeshInfo;
	}
	return nullptr;
}

AVH_GlobeReferenceActor* UGame_VectorTile_Generator::GetGlobeRef()
{
	if (IsValid(UDeveloper_Statics::GetVHWorld()))
	{
		AGame_VirtualObjective* pActiveVO = AGame_PlayerController::GetPlayerActiveVO();
		if (IsValid(pActiveVO))
		{
			return pActiveVO->GetGlobeReference();
		}
	}
	return nullptr;
}


// ---------------------------------
// --- Constructors
// ---------------------------------

Game_VectorTile_Task::Game_VectorTile_Task() :
	Thread(nullptr),
	bIsRunning(false)
{
	// NOTE: Considering spawning multiple threads and using this to limit how many threads are active at once.
	// MaxLoaderThreads = FMath::Max(1, FGenericPlatformMisc::NumberOfCoresIncludingHyperthreads() / 2);
}


// ---------------------------------
// --- Inherited
// ---------------------------------

bool Game_VectorTile_Task::Init()
{
	// Cancel the thread if there are no vector tiles to generate
	bIsRunning = VectorTiles.Num() > 0;
	return bIsRunning;
}

uint32 Game_VectorTile_Task::Run()
{
	TMap<FIntPoint, FGame_VectorTile>::TIterator tileIter(VectorTiles);
	for (; bIsRunning && tileIter; ++tileIter)
	{
		FGame_VectorTile& vectorTile = tileIter.Value();

		TMap<FString, FGame_VectorTile_VertexBuffer> buffers;

		// Parse the vector tile data into the Vector Tile struct
		if (bIsRunning)
		{
			UGame_VectorTile_Parser::Parse(vectorTile.Data, vectorTile);
		}

		// Generate geometry based on the data in the Vector Tile struct
		if (bIsRunning)
		{
			UGame_VectorTile_Generator::Generate(vectorTile, buffers, &bIsRunning);
		}

		// Create the actor/mesh in the world with the generated vector tile data
		if (bIsRunning)
		{
			UGame_VectorTile_Generator::BuildMesh(vectorTile, buffers, VectorTileFinishedDelegate, &bIsRunning);
		}

		// No longer need the data
		tileIter.RemoveCurrent();
	}

	// In case the loop was exited prematurely
	VectorTiles.Empty();
	return 0;
}

void Game_VectorTile_Task::Stop()
{
	bIsRunning = false;
}

void Game_VectorTile_Task::Exit()
{
	bIsRunning = false;
	VectorTiles.Empty();
}


// ---------------------------------
// --- API
// ---------------------------------

void Game_VectorTile_Task::QueueTile(const FIntPoint tile, int32 zoomLevel, const TArray<uint8>& data)
{
	FGame_VectorTile& vectorTile = VectorTiles.FindOrAdd(tile, FGame_VectorTile());

	vectorTile.ZoomLevel	= zoomLevel;
	vectorTile.Tile			= tile;
	vectorTile.Data			= data;
}

void Game_VectorTile_Task::StartThread()
{
	Thread = FRunnableThread::Create(this, TEXT("Game_VectorTile_Task"));
}

void Game_VectorTile_Task::StopThread()
{
	if (Thread)
	{
		// Tells the thread to exit.  This will wait infinitely until the thread has finished it's work.
		Thread->Kill();
		Thread = nullptr;
	}
}
