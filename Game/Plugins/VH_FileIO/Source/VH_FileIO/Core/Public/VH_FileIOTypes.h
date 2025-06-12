// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProceduralMeshComponent.h"

#include "VH_FileIOTypes.generated.h"

class UVH_MeshInfo;

struct FVH_MeshImportMeshNode;

/**
 *
 */
USTRUCT(BlueprintType)
struct FVH_MeshImportOptions
{
    GENERATED_BODY()

public:
    FVH_MeshImportOptions() :
        RootTransform(FTransform::Identity)
    {
		Matrix.SetIdentity();
	}

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "VhFileIO|MeshImportOptions")
    FTransform RootTransform;

	FMatrix Matrix;
};

/**
 *
 */
USTRUCT(BlueprintType)
struct FVH_MeshImportMeshData
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshData")
    FString Name;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshData")
    TArray<FVector> Vertices;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshData")
    TArray<int32> Triangles;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshData")
    TArray<FVector> Normals;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshData")
    TArray<FVector2D> UV0;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshData")
    TArray<FVector2D> UV1;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshData")
    TArray<FVector2D> UV2;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshData")
    TArray<FVector2D> UV3;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshData")
    TArray<FLinearColor> VertexColors;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshData")
    TArray<FProcMeshTangent> Tangents;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshData")
    int32 MaterialIndex;

	FVH_MeshImportMeshData()
	{
		Name = TEXT("");
		MaterialIndex = 0;
	}
};

/**
 *
 */
USTRUCT(BlueprintType)
struct FVH_MeshImportMeshNode
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshNode")
    FString Name;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshNode")
    int32 NodeIndex;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshNode")
    int32 ParentNode;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshNode")
    TArray<int32> ChildNodes;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshNode")
    FTransform RelativeTransform;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshNode")
    TArray<int32> Meshes;

	FVH_MeshImportMeshNode()
	{
		Name = TEXT("");
		NodeIndex = 0;
		ParentNode = 0;
	}
};
