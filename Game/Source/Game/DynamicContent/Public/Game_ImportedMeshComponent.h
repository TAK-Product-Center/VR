#pragma once

// Parent Includes
#include "Components/SceneComponent.h"

// Engine Includes
#include "HAL/ThreadSafeCounter.h"
#include "HAL/ThreadSafeBool.h"

// VH Plugin Includes
#include "Interface_Developer_Task.h"
#include "VH_FileIOTypes.h"

// Generated Includes
#include "Game_ImportedMeshComponent.generated.h"

class UVH_MeshInfo;
class UMaterialInterface;
class UMaterialInstance;

// ---------------------------------
// --- Structs
// ---------------------------------

USTRUCT()
struct FTextureData
{
	GENERATED_BODY()

	UPROPERTY()
	UTexture2D* Texture;

	TArray<uint8> EmbeddedTexturePixels;

	/* x: width | y : height */
	FVector2D EmbeddedTextureSize;  

	UPROPERTY()
	UMaterialInstance* Material;

	int32 NumUsing;

	bool bTextureNeedsUpdate;

	bool bTextureUpdating;

	FTextureData() :
		Texture(nullptr),
		Material(nullptr),
		NumUsing(0),
		bTextureNeedsUpdate(false),
		bTextureUpdating(false)
	{

	}
};

USTRUCT()
struct FTriangle
{
	GENERATED_BODY()

	int32 Vert1;
	int32 Vert2;
	int32 Vert3;

	friend uint32 GetTypeHash(const FTriangle& triangle)
	{
		uint32 hash1 = GetTypeHash(triangle.Vert1);
		uint32 hash23 = HashCombine(GetTypeHash(triangle.Vert2), GetTypeHash(triangle.Vert3));
		return HashCombine(hash1, hash23);
	}

	bool operator==(const FTriangle &other) const
	{
		return Vert1 == other.Vert1 && Vert2 == other.Vert2 && Vert3 == other.Vert3;
	}
};

USTRUCT()
struct FAsyncMeshData
{
	GENERATED_BODY()

	FTransform RelativeTransform;

	UPROPERTY()
	FVH_MeshImportMeshData MeshData;

	TArray<FTriangle> TrianglesToBuild;

	TMap<UProceduralMeshComponent*, TSet<FTriangle>> MeshToTriangles;

	int32 TriangleIndex;

	UPROPERTY()
	USceneComponent* SceneComponent;

	FString FullPathToTexture;
};

class AGame_VirtualObjective;

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAME_API UGame_ImportedMeshComponent : public USceneComponent, public IInterface_Developer_Task
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Delegates
	// ---------------------------------

public:
	DECLARE_MULTICAST_DELEGATE_TwoParams(FImportedMeshInfo, UGame_ImportedMeshComponent*, UVH_MeshInfo*);

	DECLARE_MULTICAST_DELEGATE_OneParam(FMaterialUpdated, UMaterialInstance*);

	
	// ---------------------------------
	// --- Variables
	// ---------------------------------

public:
	FMaterialUpdated OnMaterialUpdated;

	FImportedMeshInfo OnImportedMeshInfo;

	FString FullPathToFile;

	FVH_MeshImportOptions ImportOptions;

	UPROPERTY()
	UMaterialInstance* MaterialOverride;

	// todo ohg | seems like this should be private
	UPROPERTY()
    UMaterialInterface* MaterialTemplate;

	TMap<FString, FString> TextureResourceMap;

protected:
	UPROPERTY()
    UVH_MeshInfo* MeshInfo;

	TArray<FAsyncMeshData> AsyncMeshDatas;

	UPROPERTY()
    USceneComponent* ParentComponent;

    UPROPERTY()
    USceneComponent* ImportedMesh;

    // maps full path on disk to data about that texture
	UPROPERTY()
    TMap<FString, FTextureData> TexturePathToData;

private:
	UPROPERTY()
	UTexture2D* DefaultTexture;

	int32 TrianglesPerComponent;

	int32 MaxVerticesPerComponent;

	float SecondsBetweenComponentCreate;

	ETaskStatus TaskStatus;

	FThreadSafeCounter DestroyCounter;

	FVector LastOwnerLocation;

	FVector LastOwnerWorldScale3D;

	FThreadSafeBool bAbort;

	// 3D bounding box from SW to NE corner with altitude in HAE meters
	FBox GeodeticBounds;

	FThreadSafeBool bCalculatedBounds;

	FCriticalSection CalculateBoundsCriticalSection;

	int32 TrianglesProcessedSinceLastTimer;

	UPROPERTY()
	TSet<UProceduralMeshComponent*> ProceduralMeshComponents;

	// true when MeshInfo is populating off the game thread
	bool bPendingMeshInfo;

	enum EStatus : uint8
	{
		Initial, // nothing loaded or pending
		AddedMeshInfoTask,
		MeshInfoTaskStarted,
		MeshInfoTaskFinished,
		AddMeshTask,
		MeshTaskStarted,
		MeshTaskFinished
	};
	
	EStatus Status;

	
	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UGame_ImportedMeshComponent();


	// ---------------------------------
	// --- Interface_Developer_Task
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

	virtual void EndPlay(EEndPlayReason::Type endPlayReason) override;

	virtual bool IsReadyForFinishDestroy() override;


	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	void LoadFromFile(const FString& fullPathToFile);

	void BuildMeshFromVerticesAndTriangles(const TArray<FVector>& vertices, const TArray<int32>& triangles);

	void DestroyGeneratedMesh();

	void SetMeshInfoAndBuild(UVH_MeshInfo* meshInfo);

	bool HasCurrentOrPendingMesh() const;

	bool GetGeodeticBounds(FBox& geodeticBounds) const;

	UFUNCTION(BlueprintCallable)
	void ForceBoundsUpdate();


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

protected:
	AGame_VirtualObjective* GetVirtualObjective() const;

	FBox CalculateBounds(bool bUseScale);

private:
	void LoadFromFileInternal();

	void ImportMaterials();

	void BuildMesh();
		 
	/// @brief calculates bounds, then stores bounds in database if database bounds are invalid
	virtual void UpdateBBFromBounds();

	void SetProcMeshCollision(UProceduralMeshComponent* proceduralMeshComponent, bool bShouldCollide);

	virtual void AddNodeToAsyncData(FVH_MeshImportMeshNode& meshNode, USceneComponent* parentComponent);

	void CreateProceduralMeshComponent();

	void PeriodicUpdateBoundingBox();

	void PeriodicUpdateTextures();

	bool IsSafeToExecute();

	virtual void PostAddNodesToAsyncData();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleMeshLoadCompleted(UVH_MeshInfo* meshInfoArg);

	UFUNCTION()
	void HandleDoubleSettingChanged(const FString& settingName, double value);
};
