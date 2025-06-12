#pragma once

// Engine Includes
#include "GameFramework/Actor.h"
#include "Containers/Map.h"
#include "HAL/ThreadSafeCounter.h"
#include "HAL/ThreadSafeBool.h"

#include "OpenCVHelper.h"
#include "PreOpenCVHeaders.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include "PostOpenCVHeaders.h"

// VH Plugin Includes
#include "Interface_Developer_Task.h"
#include "VH_GeodeticCoord.h"

// Generated Includes
#include "Game_TerrainTile.generated.h"

// Forward declarations
class UTexture2D;
class AVH_GlobeReferenceActor;
class UGame_TileComponent;
class UMaterialInstanceDynamic;
class UProceduralMeshComponent;
class AGame_VirtualObjective;
class UGame_TileComponent_Mesh;
class UGame_TileComponent_Mat;
struct FUpdateTextureRegion2D;

enum class EComponentStatus : uint8;

// ---------------------------------
// --- Enums
// ---------------------------------

UENUM()
enum class ETileStatus : uint8
{
	Default,
	GameThreadFinished,
	ReadyForDestroy
};

UCLASS()
class GAME_API AGame_TerrainTile : public AActor, public IInterface_Developer_Task
{
    GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

public:
	DECLARE_MULTICAST_DELEGATE_TwoParams(FTileStatusChanged, AGame_TerrainTile*, const ETileStatus);


	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	FTileStatusChanged OnTileStatusChanged;

	int32 MatSizeX;

	int32 MatSizeY;

	UPROPERTY()
	UTexture2D* Texture;

private:
	FTimerHandle BuildMeshTimerHandle;
	FTimerHandle WaitForCollisionTimerHandle;

	FThreadSafeCounter DestroyCounter;

	TMultiMap<FString, UGame_TileComponent*> TileComponents;

	/*
	*\brief Key is northwest bound, value is southeast bound
	*/
	TPair<FGeodeticCoord2D, FGeodeticCoord2D> TileBounds;

	int32 HeightmapZoomLevel;

	int32 ImageryZoomLevel;

	ETileStatus TileStatus;

	ETaskStatus TaskStatus;

	UPROPERTY()
	UMaterialInterface* MaterialTemplate;

	TArray<FVector> Vertices;

	TArray<int32> Triangles;

	TArray<FVector2D> UVs;

	int32 TriangleIndex;
	int32 TrianglesPerComponent;
	float SecondsBetweenComponentCreate;

	UPROPERTY()
	UMaterialInstanceDynamic* MaterialInstance;

	UPROPERTY()
	TArray<UProceduralMeshComponent*> ProceduralMeshComponents;

	FGeodeticCoord3D PreModifyVOGlobeCoord;

	FThreadSafeBool bMeshDone;
	FThreadSafeBool bMaterialDone;

	FVector OriginalGlobeScale3D;

	bool bModifiedDuringTask;

	bool bScaleModifiedDuringTask;

	TArray<uint8> HighResTexturePixels;
	int32 HighResU;
	int32 HighResV;
	float HighResElapsed;
	double HighResCooldown;

	TArray<FUpdateTextureRegion2D*> Regions;

	bool bHasImageryCut;
	TPair<FGeodeticCoord2D, FGeodeticCoord2D> ImageryCut;

	bool bHasCollisionCut;
	bool bCutAllCollision;
	TPair<FGeodeticCoord2D, FGeodeticCoord2D> CollisionCut;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_TerrainTile();


	// ---------------------------------
	// --- Interface_Task
	// ---------------------------------

public:
	UFUNCTION(BlueprintNativeEvent)
	ETaskStatus GetTaskStatus() const;

	UFUNCTION(BlueprintNativeEvent)
	bool InitializeTask();

	UFUNCTION(BlueprintNativeEvent)
	void StartTask();

	
	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type endPlayReason) override;

	virtual bool IsReadyForFinishDestroy() override;

	virtual void Tick(float deltaSeconds) override;

	
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	TPair<FGeodeticCoord2D, FGeodeticCoord2D> GetTileBounds() const { return TileBounds; }

	int32 GetHeightmapZoomLevel() const { return HeightmapZoomLevel; }

	int32 GetImageryZoomLevel() const { return ImageryZoomLevel; }

	ETileStatus GetTileStatus() const { return TileStatus; }

	void SetTileStatus(const ETileStatus status);

    void SetBoundsAndZoom(const TPair<FGeodeticCoord2D, FGeodeticCoord2D>& tileBounds, const int32 heightmapZoomLevel, const int32 imageryZoomLevel);

	UGame_TileComponent* AddTileComponent(const FString& id, TSubclassOf<UGame_TileComponent> tileComponentClass);

	void SetImageryCut(const FGeodeticCoord2D& northWest, const FGeodeticCoord2D& southEast);

	void SetCollisionCut(const FGeodeticCoord2D& northWest, const FGeodeticCoord2D& southEast, bool bAll);

	void ClearImageryCut();

	void ClearCollisionCut();

	void SetDrawDistance(const FVector& center, const double distanceMeters);

	void GetComponentsByStatus(EComponentStatus componentStatus, TArray<UGame_TileComponent*>& components);

	FString GetComponentID(UGame_TileComponent* tileComponent) const;

	bool GetHAEBounds(FVector2D& haeBounds) const;

	void PreModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference);

	void PostModifyVOGlobeReference(AVH_GlobeReferenceActor* globeReference);

	void GlobeReferenceScaleUpdated(const FVector& newScale3D);

	UFUNCTION(BlueprintPure)
	AGame_VirtualObjective* GetVirtualObjective() const;

	void GetVerticesWithin(const TArray<FBox2D>& gridBoxes, TArray<TSet<FVector>>& gridBoxVertices) const;


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void ApplyCutToMaterial();

	void ApplyCutToMesh(UProceduralMeshComponent* meshComponent);

	void CreateMaterial();

	void CreateMesh();

	void AddTaskIfComponentsReady();

	bool IsSafeToExecute();

	FString GetTaskTrackerID() const;

	FString GetTaskTrackerDescription() const;

	void HandleModification(UGame_TileComponent* tileComponent);


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	void HandleWaitForCollisionTimer();

	void HandleGameLogicCompletedGeneric();

	void HandleMatGameLogicCompleted(UGame_TileComponent_Mat* tileComponent);

	void HandleMeshGameLogicCompleted(const TArray<FVector>& vertices, const TArray<int32>& triangles, const TArray<FVector2D>& uvs);

};