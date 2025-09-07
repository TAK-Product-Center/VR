// Required Includes
#include "Game_ImportedMeshComponent.h"
#include "Game.h"

// Engine Includes
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "TimerManager.h"
#include "Async/Async.h"
#include "Async/ParallelFor.h"
#include "Engine/Texture2D.h"
#include "Misc/Paths.h"
#include "Engine/World.h"

// VH Plugin Includes
#include "VH_MeshInfo.h"
#include "VH_GeodeticCoord.h"
#include "Developer_Statics.h"
#include "Developer_Subsystem_TaskTracker.h"
#include "Developer_TaskScheduler.h"
#include "VH_GlobeReferenceActor.h"
#include "VH_ImageLoader.h"
#include "Developer_PersistentSettings.h"
#include "Database_PersistentSettings_Spatialite.h"

// Game Includes
#include "Game_Statics.h"
#include "Game_PlayerController.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_EntityDB.h"
#include "Game_Subsystem_Core.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_ImportedMeshComponent::UGame_ImportedMeshComponent() :
	ParentComponent(this),
	TrianglesPerComponent(200000),
	MaxVerticesPerComponent(100000),
	SecondsBetweenComponentCreate(0.1),
	TaskStatus(ETaskStatus::Invalid),
	GeodeticBounds(EForceInit::ForceInit)
{
	ConstructorHelpers::FObjectFinder<UMaterialInterface> defaultMaterial(TEXT("Material'/Game/VTAK/Materials/KML/M_MeshImport_Game.M_MeshImport_Game'"));
	if (defaultMaterial.Succeeded())
	{
		MaterialTemplate = defaultMaterial.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D> defaultTexture(TEXT("Texture2D'/Game/VTAK/Textures/Generic/T_Gray.T_Gray'"));
	if (defaultTexture.Succeeded())
	{
		DefaultTexture = defaultTexture.Object;
	}

	bWantsInitializeComponent = true;

    PrimaryComponentTick.bCanEverTick = false;
}

// ---------------------------------
// --- Interface_Developer_Task
// ---------------------------------

ETaskStatus UGame_ImportedMeshComponent::GetTaskStatus_Implementation() const
{
	return TaskStatus;
}

bool UGame_ImportedMeshComponent::InitializeTask_Implementation()
{
	if (!bAbort)
	{
		TaskStatus = ETaskStatus::Initialized;
		
		return true;
	}

	return false;
}

void UGame_ImportedMeshComponent::StartTask_Implementation()
{
	if (!bAbort)
	{
		TaskStatus = ETaskStatus::Started;
		
		if (MeshInfo == nullptr)
		{
			Status = MeshInfoTaskStarted;

			DestroyCounter.Increment();
			Async(EAsyncExecution::ThreadPool, [this]()
			{
				UVH_MeshInfo* meshInfo = UVH_MeshInfo::Create(FullPathToFile, ImportOptions);

				AsyncTask(ENamedThreads::GameThread, [this, meshInfo]()
				{
					HandleMeshLoadCompleted(meshInfo);
					
					DestroyCounter.Decrement();
				});
			});
		}
		else
		{
			Status = MeshTaskStarted;

			CreateProceduralMeshComponent();
		}
	}
	else
	{
		if (AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController())
		{
			playerController->GetMeshBuilder()->RemoveTask(TScriptInterface<IInterface_Developer_Task>(this));
			
			TaskStatus = ETaskStatus::Invalid;
		}
	}
}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_ImportedMeshComponent::BeginPlay()
{
	Super::BeginPlay();

	LastOwnerWorldScale3D = GetOwner()->GetActorScale3D();

	if (UDeveloper_PersistentSettings* gameSettings = UGame_Subsystem_Core::GetGameSettings())
	{
		gameSettings->OnDoubleSettingStored.AddDynamic(this, &UGame_ImportedMeshComponent::HandleDoubleSettingChanged);
	}
}

void UGame_ImportedMeshComponent::EndPlay(EEndPlayReason::Type endPlayReason)
{
	Super::EndPlay(endPlayReason);

	DestroyGeneratedMesh();
}

bool UGame_ImportedMeshComponent::IsReadyForFinishDestroy()
{
	return Super::IsReadyForFinishDestroy() && DestroyCounter.GetValue() == 0;
}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_ImportedMeshComponent::LoadFromFile(const FString& fullPathToFile)
{
	if (Status != Initial)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_ImportedMeshComponent::LoadFromFile | loading %s, but Status (%d) is not Initial | aborting"), *fullPathToFile, (int32)Status);
		return;
	}

	if (!fullPathToFile.IsEmpty())
	{
		FullPathToFile = fullPathToFile;
		
		LoadFromFileInternal();
	}
	else
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_ImportedMeshComponent::LoadFromFile | fullPathToFile is empty | aborting"));
	}
}

void UGame_ImportedMeshComponent::BuildMeshFromVerticesAndTriangles(const TArray<FVector>& vertices, const TArray<int32>& triangles)
{
	if (Status != Initial)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_ImportedMeshComponent::BuildMeshFromVerticesAndTriangles | Status (%d) is not Initial | aborting"), (int32)Status);
		return;
	}

	FVH_MeshImportMeshNode meshNode;
	meshNode.NodeIndex = 0;
	meshNode.Meshes.Add(0);

	FVH_MeshImportMeshData meshData;
	meshData.Vertices.Append(vertices);
	meshData.Triangles.Append(triangles);
	meshData.MaterialIndex = 0;

	FVH_MeshImportOptions importOptions;

	UVH_MeshInfo* meshInfo = NewObject<UVH_MeshInfo>();
	meshInfo->bIsValid = true;
	meshInfo->NodeList.Add(meshNode);
	meshInfo->MeshDataList.Add(meshData);
	meshInfo->MaterialList.Add(TEXT(""));

	SetMeshInfoAndBuild(meshInfo);
}

void UGame_ImportedMeshComponent::DestroyGeneratedMesh()
{
	if (AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController())
	{
		playerController->GetMeshBuilder()->RemoveTask(TScriptInterface<IInterface_Developer_Task>(this));
			
		TaskStatus = ETaskStatus::Invalid;
	}

	bAbort = true;
	
	if (DestroyCounter.GetValue() == 0)
	{
		bAbort = false;

		if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
		{
			taskTracker->RemoveActiveTask(FullPathToFile);
		}

		GetWorld()->GetTimerManager().ClearAllTimersForObject(this);

		for (UProceduralMeshComponent* meshComponent : ProceduralMeshComponents)
		{
			meshComponent->DestroyComponent();
		}
		ProceduralMeshComponents.Empty();

		MeshInfo = nullptr;

		Status = Initial;
	}
	else
	{
		FTimerHandle timerHandle;
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UGame_ImportedMeshComponent::DestroyGeneratedMesh, 0.5, false);
	}
}

void UGame_ImportedMeshComponent::SetMeshInfoAndBuild(UVH_MeshInfo* meshInfo)
{
	if (Status != Initial)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_ImportedMeshComponent::SetMeshInfoAndBuild | Status (%d) is not Initial | aborting"), (int32)Status);
		return;
	}

	MeshInfo = meshInfo;

	if (MeshInfo != nullptr)
	{
		BuildMesh();
	}
}

bool UGame_ImportedMeshComponent::HasCurrentOrPendingMesh() const
{
	return DestroyCounter.GetValue() > 0 || Status != Initial;
}

bool UGame_ImportedMeshComponent::GetGeodeticBounds(FBox& geodeticBounds) const
{
	if (bCalculatedBounds)
	{
		geodeticBounds = GeodeticBounds;

		return true;
	}

	return false;
}

void UGame_ImportedMeshComponent::ForceBoundsUpdate()
{
	UpdateBBFromBounds();
}

// ---------------------------------
// --- Implementation
// ---------------------------------

AGame_VirtualObjective* UGame_ImportedMeshComponent::GetVirtualObjective() const
{
	if (AGame_VirtualObjective* virtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(GetOwner(), false))
	{
		return virtualObjective;
	}

	return AGame_PlayerController::GetPlayerActiveVO();
}

FBox UGame_ImportedMeshComponent::CalculateBounds(bool bUseScale)
{
	FBox extents;

	if (AVH_GlobeReferenceActor* globeReference = UGame_VirtualObjectiveManager::GetObjectGlobeReference(GetOwner()))
	{
		// iterate through AsyncMeshDatas and determine bounds
		for (const FAsyncMeshData& asyncMeshData : AsyncMeshDatas)
		{
			if (bAbort)
			{
				break;
			}

			FTransform localToWorld = asyncMeshData.SceneComponent->GetComponentTransform();
			
			if (!bUseScale)
			{
				localToWorld.SetScale3D(FVector(1, 1, 1));
			}

			for (const FVector& vertex : asyncMeshData.MeshData.Vertices)
			{
				if (bAbort)
				{
					break;
				}

				FGeodeticCoord3D coordinate = globeReference->WorldToGeodeticDouble(localToWorld.TransformPosition(vertex));

				extents += coordinate.ToVector();
			}
		}

		bCalculatedBounds = true;
	}

	return extents;
}

void UGame_ImportedMeshComponent::LoadFromFileInternal()
{
	MeshInfo = nullptr;

	if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
	{
		taskTracker->AddActiveTask(FullPathToFile, FString::Printf(TEXT("Read model | %s"), *FPaths::GetCleanFilename(FullPathToFile)), 0);
	}

	if (AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController())
	{
		if (UDeveloper_TaskScheduler* taskScheduler = playerController->GetMeshLoader())
		{
			Status = AddedMeshInfoTask;

			TaskStatus = ETaskStatus::Initialized;
			
			taskScheduler->RemoveTask(TScriptInterface<IInterface_Developer_Task>(this));
			taskScheduler->AddTask(TScriptInterface<IInterface_Developer_Task>(this));
		}
	}
}

void UGame_ImportedMeshComponent::ImportMaterials()
{
	if (MaterialTemplate == nullptr)
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_ImportedMeshComponent::ImportMaterials | MaterialTemplate is nullptr for %s | aborting"), *FullPathToFile);
		
		return;
	}

	for (const FString& materialListEntry : MeshInfo->MaterialList)
	{
		FString pathOnDisk;

		// handle redirect from TextureResourceMap
		pathOnDisk = materialListEntry;
		if (FString* stringPtr = TextureResourceMap.Find(materialListEntry))
		{
			pathOnDisk = *stringPtr;
		}

		if (!materialListEntry.IsEmpty() && !materialListEntry.Equals(TEXT("<default>"), ESearchCase::IgnoreCase))
		{
			pathOnDisk = FPaths::Combine(FPaths::GetPath(FullPathToFile), pathOnDisk);
		}

		if (!TexturePathToData.Contains(pathOnDisk))
		{
			FTextureData textureData;
			textureData.Material = UMaterialInstanceDynamic::Create(MaterialTemplate, this);
			Cast<UMaterialInstanceDynamic>(textureData.Material)->SetTextureParameterValue(FName("BaseColor"), DefaultTexture);

			if (TArray<uint8>* embeddedTexturePixelsPtr = MeshInfo->EmbeddedTexturePixels.Find(materialListEntry))
			{
				if (FVector2D* embeddedTextureSizePtr = MeshInfo->EmbeddedTextureSize.Find(materialListEntry))
				{
					textureData.EmbeddedTexturePixels.Empty();
					textureData.EmbeddedTexturePixels.Append(*embeddedTexturePixelsPtr);

					textureData.EmbeddedTextureSize = *embeddedTextureSizePtr;
				}
			}

			TexturePathToData.Add(pathOnDisk, textureData);
		}
	}
}

void UGame_ImportedMeshComponent::BuildMesh()
{
    if (MeshInfo->NodeList.Num() == 0)
    {
		UE_LOG(Game, Warning, TEXT("-- UGame_ImportedMeshComponent::BuildMesh | MeshInfo->NodeList is empty for %s | aborting"), *FullPathToFile);

        return;
    }

    if (MeshInfo->MeshDataList.Num() == 0)
    {
        UE_LOG(Game, Warning, TEXT("-- UGame_ImportedMeshComponent::BuildMesh | MeshInfo->MeshDataList is empty for %s | aborting"), *FullPathToFile);

        return;
    }

	// populate array of FAsyncMeshData from MeshInfo
	AsyncMeshDatas.Empty();

	AddNodeToAsyncData(MeshInfo->NodeList[0], this);
	PostAddNodesToAsyncData();

	UpdateBBFromBounds();

	// add self to task scheduler
	if (AGame_PlayerController* playerController = UGame_Statics::GetVHPlayerController())
	{
		if (UDeveloper_TaskScheduler* taskScheduler = playerController->GetMeshLoader())
		{
			Status = AddedMeshInfoTask;

			TaskStatus = ETaskStatus::Initialized;

			taskScheduler->RemoveTask(TScriptInterface<IInterface_Developer_Task>(this));
			taskScheduler->AddTask(TScriptInterface<IInterface_Developer_Task>(this));
		}
	}
}

void UGame_ImportedMeshComponent::UpdateBBFromBounds()
{
	FString entityUID = UGame_VirtualObjectiveManager::GetObjectEntityUID(GetOwner(), false);
	if (!entityUID.IsEmpty())
	{
		if (UGame_EntityDB* entityDB = UGame_EntityDB::Get())
		{
			SpatialiteResults results = entityDB->QueryUID(entityUID);
			if (results.Num() > 0)
			{
				Async(EAsyncExecution::ThreadPool, [this, entityDB, entityUID]()
				{
					DestroyCounter.Increment();

					if (!IsSafeToExecute())
					{
						DestroyCounter.Decrement();
						return;
					}

					if (CalculateBoundsCriticalSection.TryLock())
					{
						GeodeticBounds = CalculateBounds(true);

						// update database bounds 
						FGeodeticCoord2D northWestCoord(GeodeticBounds.Min.X, GeodeticBounds.Max.Y);
						FGeodeticCoord2D southEastCoord(GeodeticBounds.Max.X, GeodeticBounds.Min.Y);
					
						entityDB->UpdateBoundingBox(entityUID, northWestCoord, southEastCoord);

						CalculateBoundsCriticalSection.Unlock();
					}

					DestroyCounter.Decrement();
				});
			}
		}
	}
}

void UGame_ImportedMeshComponent::SetProcMeshCollision(UProceduralMeshComponent* proceduralMeshComponent, bool bShouldCollide)
{
	if (proceduralMeshComponent)
	{
		proceduralMeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
		
		proceduralMeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);

		bool bIsInWorld = !UGame_Statics::IsLocalPlayerInTOC();

		// Disable step-up in the TOC
		proceduralMeshComponent->CanCharacterStepUpOn = ECanBeCharacterBase(bIsInWorld);

		if (bShouldCollide)
		{
			proceduralMeshComponent->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
			
			if (bIsInWorld)
			{
				proceduralMeshComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
			}
			
			proceduralMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		}
		else
		{
			proceduralMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}
}

void UGame_ImportedMeshComponent::AddNodeToAsyncData(FVH_MeshImportMeshNode& meshNode, USceneComponent* parentComponent)
{
	USceneComponent* groupComponent = nullptr;
	
	if (meshNode.ChildNodes.Num() > 0 || meshNode.Meshes.Num() > 1)
	{
		// Insert a SceneComponent into the hierarchy, if NOT a leaf node with exactly 1 mesh. This will serve as a mesh/node "group" component.
		groupComponent = NewObject<USceneComponent>(parentComponent);

		groupComponent->SetWorldTransform(meshNode.RelativeTransform);
		if (parentComponent != nullptr)
		{
			groupComponent->AttachToComponent(parentComponent, FAttachmentTransformRules::KeepRelativeTransform);
		}
		groupComponent->RegisterComponent();

		// Update 'parentComponent' for submeshes and/or child nodes
		parentComponent = groupComponent;
	}
	
	for (const int32 meshDataIndex : meshNode.Meshes)
	{
		if (MeshInfo->MeshDataList[meshDataIndex].Triangles.Num() % 3 == 0)
		{
			FAsyncMeshData asyncMeshData;
			// NOTE: Only apply RelativeTransform here if not already applied to groupComponent
			asyncMeshData.RelativeTransform = (groupComponent == nullptr) ? meshNode.RelativeTransform : FTransform::Identity;
			asyncMeshData.MeshData = MeshInfo->MeshDataList[meshDataIndex];
			asyncMeshData.TriangleIndex = 0;
			asyncMeshData.SceneComponent = parentComponent;

			FString materialName = MeshInfo->MaterialList[asyncMeshData.MeshData.MaterialIndex];
			if (!materialName.IsEmpty() && !materialName.Equals(TEXT("<default>"), ESearchCase::IgnoreCase))
			{
				// handle redirect from TextureResourceMap
				materialName = TextureResourceMap.Contains(materialName) ? TextureResourceMap[materialName] : materialName;

				asyncMeshData.FullPathToTexture = FPaths::Combine(FPaths::GetPath(FullPathToFile), materialName);
			}
			else
			{
				asyncMeshData.FullPathToTexture = TEXT("<default>");
			}

			for (int32 i = 0; i < asyncMeshData.MeshData.Triangles.Num(); i += 3)
			{
				FTriangle triangle;
				triangle.Vert1 = asyncMeshData.MeshData.Triangles[i];
				triangle.Vert2 = asyncMeshData.MeshData.Triangles[i + 1];
				triangle.Vert3 = asyncMeshData.MeshData.Triangles[i + 2];

				asyncMeshData.TrianglesToBuild.Add(triangle);
			}

			AsyncMeshDatas.Add(asyncMeshData);
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- triangle entries not a multiple of 3: %d"), MeshInfo->MeshDataList[meshDataIndex].Triangles.Num());
		}
	}
	
	for (const int32 childNodeIndex : meshNode.ChildNodes)
	{
		AddNodeToAsyncData(MeshInfo->NodeList[childNodeIndex], parentComponent);
	}
}

void UGame_ImportedMeshComponent::CreateProceduralMeshComponent()
{
	// find next mesh data that needs a rebuild
	int32 asyncMeshDataIndex = 0;
	while (asyncMeshDataIndex < AsyncMeshDatas.Num())
	{
		FAsyncMeshData& asyncMeshData = AsyncMeshDatas[asyncMeshDataIndex];

		if (asyncMeshData.TrianglesToBuild.Num() * 3 > asyncMeshData.TriangleIndex)
		{
			break;
		}
		
		asyncMeshDataIndex++;
	}

	if (!AsyncMeshDatas.IsValidIndex(asyncMeshDataIndex))
	{
		if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
		{
			taskTracker->RemoveActiveTask(FullPathToFile);

			taskTracker->AddHistoryTask(FullPathToFile, FString::Printf(TEXT("Build | %s"), *FPaths::GetCleanFilename(FullPathToFile)));
		}

		TaskStatus = ETaskStatus::Finished;

		Status = MeshTaskFinished;

		if (UWorld* world = UDeveloper_Statics::GetVHWorld())
		{
			FTimerHandle textureHandle;
			world->GetTimerManager().SetTimer(textureHandle, this, &UGame_ImportedMeshComponent::PeriodicUpdateTextures, 0.1, true);

			FTimerHandle boundingBoxHandle;
			world->GetTimerManager().SetTimer(boundingBoxHandle, this, &UGame_ImportedMeshComponent::PeriodicUpdateBoundingBox, 1, true);
		}

		return;
	}

	Async(EAsyncExecution::ThreadPool, [this, asyncMeshDataIndex]()
	{
		DestroyCounter.Increment();

		if (!IsSafeToExecute())
		{
			DestroyCounter.Decrement();
			return;
		}

		FAsyncMeshData& asyncMeshData = AsyncMeshDatas[asyncMeshDataIndex];

		TArray<int32> triangles;
		for (const FTriangle& triangle : asyncMeshData.TrianglesToBuild)
		{
			triangles.Add(triangle.Vert1);
			triangles.Add(triangle.Vert2);
			triangles.Add(triangle.Vert3);
		}

		if (asyncMeshData.TriangleIndex > 0)
		{
			triangles.RemoveAt(0, asyncMeshData.TriangleIndex);
		}

		int32 toProcess = TrianglesPerComponent * 3;
		bool bTrianglesLeft = false;
		if (triangles.Num() > toProcess)
		{
			triangles.RemoveAt(toProcess, triangles.Num() - toProcess);

			asyncMeshData.TriangleIndex += toProcess;

			bTrianglesLeft = true;

			TrianglesProcessedSinceLastTimer += TrianglesPerComponent;
		}
		else
		{
			asyncMeshData.TriangleIndex = asyncMeshData.TrianglesToBuild.Num() * 3;

			TrianglesProcessedSinceLastTimer += (triangles.Num() / 3);
		}

		if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
		{
			int32 builtTriangles = 0;
			int32 totalTriangles = 0;

			for (int32 i = 0; i < AsyncMeshDatas.Num(); i++)
			{
				if (i < asyncMeshDataIndex)
				{
					builtTriangles += AsyncMeshDatas[i].TrianglesToBuild.Num();
				}

				totalTriangles += AsyncMeshDatas[i].TrianglesToBuild.Num();
			}

			builtTriangles += (asyncMeshData.TriangleIndex / 3);

			taskTracker->AddActiveTask(FullPathToFile, FString::Printf(TEXT("Build model | %s"), *FPaths::GetCleanFilename(FullPathToFile)), (float)builtTriangles / totalTriangles);
		}
		
		// create vertices, triangles, uvs for only triangles and vertices referenced in triangles
		TArray<int32> processedTriangles;
		TArray<FVector> processedVertices;
		TArray<FVector2D> processedUVs;
		TArray<FLinearColor> processedVertexColors;
		TArray<FProcMeshTangent> processedTangents;
		TArray<FVector> processedNormals;

		TMap<int32, int32> oldIndexToNewIndex;
		for (int32 i = 0; i < triangles.Num(); i++)
		{
			int32 triangleIndex = triangles[i];

			if (int32* newIndexPtr = oldIndexToNewIndex.Find(triangleIndex))
			{
				processedTriangles.Add(*newIndexPtr);
			}
			else
			{
				int32 newIndex = processedVertices.Add(asyncMeshData.MeshData.Vertices[triangleIndex]);

				if (asyncMeshData.MeshData.UV0.Num() > 0)
				{
					processedUVs.Add(asyncMeshData.MeshData.UV0[triangleIndex]);
				}

				if (asyncMeshData.MeshData.VertexColors.Num() > 0)
				{
					processedVertexColors.Add(asyncMeshData.MeshData.VertexColors[triangleIndex]);
				}

				if (asyncMeshData.MeshData.Tangents.IsValidIndex(triangleIndex))
				{
					processedTangents.Add(asyncMeshData.MeshData.Tangents[triangleIndex]);
				}

				if (asyncMeshData.MeshData.Normals.IsValidIndex(triangleIndex))
				{
					processedNormals.Add(asyncMeshData.MeshData.Normals[triangleIndex]);
				}

				processedTriangles.Add(newIndex);

				oldIndexToNewIndex.Add(triangleIndex, newIndex);
			}

			if (i + 1 < triangles.Num())
			{
				if ((i + 1) % 3 == 0 && processedVertices.Num() >= MaxVerticesPerComponent)
				{
					bTrianglesLeft = true;

					asyncMeshData.TriangleIndex = asyncMeshData.TriangleIndex - (triangles.Num() - i) + 1;

					triangles.RemoveAt(i + 1, triangles.Num() - (i + 1));

					break;
				}
			}
		}

		AsyncTask(ENamedThreads::GameThread, [this, asyncMeshDataIndex, triangles, processedTriangles, processedVertices, processedUVs, processedVertexColors, processedTangents, processedNormals, bTrianglesLeft]()
		{
			DestroyCounter.Increment();

			if (!IsSafeToExecute())
			{
				DestroyCounter.Decrement();
				return;
			}

			if (!AsyncMeshDatas.IsValidIndex(asyncMeshDataIndex))
			{
				UE_LOG(Game, Warning, TEXT("-- asyncMeshDataIndex was invalid | %d"), asyncMeshDataIndex);

				DestroyCounter.Decrement();
				return;
			}

			FAsyncMeshData& asyncMeshData = AsyncMeshDatas[asyncMeshDataIndex];
			USceneComponent* parentComponent = asyncMeshData.SceneComponent;

			UProceduralMeshComponent* proceduralMeshComponent = NewObject<UProceduralMeshComponent>(parentComponent, UProceduralMeshComponent::StaticClass());
			proceduralMeshComponent->OnComponentCreated();
			proceduralMeshComponent->bUseAsyncCooking = true;

			proceduralMeshComponent->SetWorldTransform(asyncMeshData.RelativeTransform);

			proceduralMeshComponent->AttachToComponent(parentComponent, FAttachmentTransformRules::KeepRelativeTransform);

			if (proceduralMeshComponent->bAutoRegister)
			{
				AActor* owner = proceduralMeshComponent->GetOwner();
				if (owner != nullptr && owner->GetWorld() != nullptr)
				{
					proceduralMeshComponent->RegisterComponent();
				}
				else
				{
					DestroyCounter.Decrement();
					return;
				}
			}

			// create mesh 
			proceduralMeshComponent->CreateMeshSection_LinearColor(0, processedVertices, processedTriangles, processedNormals, processedUVs, processedVertexColors, processedTangents, true);
			SetProcMeshCollision(proceduralMeshComponent, !GetOwner()->IsHidden());

			if (FTextureData* textureDataPtr = TexturePathToData.Find(asyncMeshData.FullPathToTexture))
			{
				if (!textureDataPtr->bTextureNeedsUpdate && textureDataPtr->Texture == nullptr && !asyncMeshData.FullPathToTexture.IsEmpty() && !asyncMeshData.FullPathToTexture.Equals(TEXT("<default>"), ESearchCase::IgnoreCase))
				{
					textureDataPtr->bTextureNeedsUpdate = true;
				}

				proceduralMeshComponent->SetMaterial(0, textureDataPtr->Material);
			}
			else if (MaterialOverride != nullptr)
			{
				proceduralMeshComponent->SetMaterial(0, MaterialOverride);
			}

			TSet<FTriangle> triangleSet;
			for (int32 i = 0; i < triangles.Num(); i += 3)
			{
				FTriangle triangle;
				triangle.Vert1 = triangles[i];
				triangle.Vert2 = triangles[i + 1];
				triangle.Vert3 = triangles[i + 2];

				triangleSet.Add(triangle);
			}

			asyncMeshData.MeshToTriangles.Add(proceduralMeshComponent, triangleSet);
			ProceduralMeshComponents.Add(proceduralMeshComponent);

			FTimerHandle timerHandle;
			if (TrianglesProcessedSinceLastTimer < TrianglesPerComponent)
			{
				GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UGame_ImportedMeshComponent::CreateProceduralMeshComponent, 0.001);
			}
			else
			{
				TrianglesProcessedSinceLastTimer = 0;
				GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UGame_ImportedMeshComponent::CreateProceduralMeshComponent, SecondsBetweenComponentCreate);
			}

			DestroyCounter.Decrement();
		});

		DestroyCounter.Decrement();
	});
}

void UGame_ImportedMeshComponent::PeriodicUpdateBoundingBox()
{
	// location
	FVector ownerLocation = GetOwner()->GetActorLocation();
	if (!LastOwnerLocation.Equals(ownerLocation))
	{
		UpdateBBFromBounds();

		LastOwnerLocation = ownerLocation;
	}

	// scale
	FVector ownerScale3D = GetOwner()->GetActorScale3D();
	if (!ownerScale3D.Equals(LastOwnerWorldScale3D))
	{
		UpdateBBFromBounds();

		LastOwnerWorldScale3D = ownerScale3D;
	}
}

void UGame_ImportedMeshComponent::PeriodicUpdateTextures()
{
	for (TPair<FString, FTextureData>& entry : TexturePathToData)
	{
		if (entry.Value.bTextureNeedsUpdate)
		{
			if (entry.Value.EmbeddedTexturePixels.Num() > 0)
			{
				int32 width = entry.Value.EmbeddedTextureSize.X;
				int32 height = entry.Value.EmbeddedTextureSize.Y;

				entry.Value.Texture = UDeveloper_Statics::CreateTextureFromPixels(width, height, entry.Value.EmbeddedTexturePixels);
			}

			if (entry.Value.Texture != nullptr)
			{
				Cast<UMaterialInstanceDynamic>(entry.Value.Material)->SetTextureParameterValue(FName("BaseColor"), entry.Value.Texture);
				OnMaterialUpdated.Broadcast(entry.Value.Material);

				entry.Value.bTextureNeedsUpdate = false;

				entry.Value.bTextureUpdating = false;
			}
		}
	}

	for (const TPair<FString, FTextureData>& entry : TexturePathToData)
	{
		if (entry.Value.bTextureUpdating)
		{
			// already reading in a texture; abort
			return;
		}
	}

	TArray<FString> texturePaths;
	for (TPair<FString, FTextureData>& entry : TexturePathToData)
	{
		if (entry.Value.bTextureNeedsUpdate && !entry.Value.bTextureUpdating)
		{
			texturePaths.AddUnique(entry.Key);

			entry.Value.bTextureUpdating = true;

			break;
		}
	}

	ParallelFor(texturePaths.Num(),
		[this, texturePaths](int32 i)
		{
			DestroyCounter.Increment();

			if (!IsSafeToExecute())
			{
				DestroyCounter.Decrement();
				return;
			}

			FString texturePath = texturePaths[i];

			FVector2D scaledDimensions;
			FVector2D originalDimensions;
			TArray<uint8> pixelData;
			if (!UVH_ImageLoader::LoadImageFromDisk(texturePath, scaledDimensions, originalDimensions, pixelData))
			{
				UE_LOG(Game, Warning, TEXT("-- UGame_ImportedMeshComponent::UpdateTextures | failed to load pixels | %s"), *texturePath);
				
				DestroyCounter.Decrement();
				return;
			}
			
			AsyncTask(ENamedThreads::GameThread, [this, scaledDimensions, pixelData, texturePath]()
			{
				DestroyCounter.Increment();

				if (!IsSafeToExecute())
				{
					DestroyCounter.Decrement();
					return;
				}

				UTexture2D* texture = UDeveloper_Statics::CreateTextureFromPixels(scaledDimensions.X, scaledDimensions.Y, pixelData);

				for (TPair<FString, FTextureData>& entry : TexturePathToData)
				{
					if (entry.Key.Equals(texturePath, ESearchCase::IgnoreCase))
					{
						entry.Value.Texture = texture;
					}
				}

				DestroyCounter.Decrement();
			});

			DestroyCounter.Decrement();
		},
		EParallelForFlags::None
	);
}

bool UGame_ImportedMeshComponent::IsSafeToExecute()
{
	if (!IsValidLowLevelFast() || HasAnyFlags(RF_BeginDestroyed) || GetClass() == nullptr || bAbort)
	{
		return false;
	}

	return true;
}

void UGame_ImportedMeshComponent::PostAddNodesToAsyncData()
{

}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_ImportedMeshComponent::HandleMeshLoadCompleted(UVH_MeshInfo* meshInfo)
{
	if (!bAbort)
	{
		Status = MeshInfoTaskFinished;

		MeshInfo = meshInfo;

		if (MeshInfo != nullptr)
		{
			OnImportedMeshInfo.Broadcast(this, MeshInfo);

			if (UDeveloper_Subsystem_TaskTracker* taskTracker = UDeveloper_Subsystem_TaskTracker::Get(GetWorld()))
			{
				taskTracker->RemoveActiveTask(FullPathToFile);

				taskTracker->AddHistoryTask(FullPathToFile, FString::Printf(TEXT("Load | %s"), *FPaths::GetCleanFilename(FullPathToFile)));
			}

			ImportMaterials();

			BuildMesh();
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- UGame_ImportedMeshComponent::LoadFromFileInternal | MeshInfo is nullptr for %s | aborting"), *FullPathToFile);
		}
	}
}

void UGame_ImportedMeshComponent::HandleDoubleSettingChanged(const FString& settingName, double value)
{
	if (settingName.Equals(TEXT("ModelTrianglesPerComponent")))
	{
		TrianglesPerComponent = FMath::RoundToInt(value);
	}
	else if (settingName.Equals(TEXT("ModelSecondsBetweenComponentCreate")))
	{
		SecondsBetweenComponentCreate = value;
	}
	else if (settingName.Equals(TEXT("ModelVerticesPerComponent")))
	{
		MaxVerticesPerComponent = FMath::RoundToInt(value);
	}
}