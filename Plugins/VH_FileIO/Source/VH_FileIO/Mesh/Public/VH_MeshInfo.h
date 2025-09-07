#pragma once

#include "UObject/Object.h"
#include "VH_FileIOTypes.h"

#include "VH_MeshInfo.generated.h"

struct aiScene;
struct aiNode;

UCLASS(BlueprintType, Config = "VH_FileIO")
class VH_FILEIO_API UVH_MeshInfo : public UObject
{
    GENERATED_BODY()

public:
    UVH_MeshInfo();

    // ---------------------------------
    // --- Methods
    // ---------------------------------
public:
    UFUNCTION(BlueprintCallable, Category = "VhFileIO|MeshInfo", meta = (DisplayName = "VH Create MeshInfo"))
    static UVH_MeshInfo* Create(const FString& meshFilename, const FVH_MeshImportOptions& importOptions);

    UFUNCTION(BlueprintPure, Category = "VhFileIO|MeshInfo", meta = (DisplayName = "VH Create MeshInfo"))
    static FVH_MeshImportOptions GetDefaultImportOptions(const FString& meshFilename);

    // ---------------------------------
    // --- Implementation
    // ---------------------------------
protected:
    void ImportData(const FString& meshFilename);

    /** Recursively get the total number of subnodes (including itself) contained within a node tree. */
    int32 ImportMeshGetNodeCount(const aiNode* importNode);

    /** Parses mesh data for a scene node.  There can be multiple meshes on each node. */
    void ParseNode(aiNode* importNode, FVH_MeshImportMeshNode& meshNode, int32 depth);

    /** Recursively parses a scene node (tree). */
    void ParseNodeMeshData(aiNode* importNode, FVH_MeshImportMeshNode& meshNode, int32 depth);

    // ---------------------------------
    // --- Variables
    // ---------------------------------
public:
    /** Filename for mesh to import. Absolute paths are allowed. If relative, it will be relative to project/game's Content folder. */
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshInfo")
    FString Filename;

    /** Filename for mesh to import, including fully-qualified (i.e. absolute) path. */
    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshInfo")
    FString FullFilename;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshInfo")
    bool bIsValid;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshInfo")
    TArray<FVH_MeshImportMeshNode> NodeList;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshInfo")
    TArray<FVH_MeshImportMeshData> MeshDataList;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshInfo")
    TArray<FString> MaterialList;

	TMap<FString, TArray<uint8>> EmbeddedTexturePixels;
	
	/* x: width | y: height */
	TMap<FString, FVector2D> EmbeddedTextureSize;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "VhFileIO|MeshInfo")
    FVH_MeshImportOptions ImportOptions;

protected:
    const aiScene* ImportedScene;

    UPROPERTY(Config)
    bool EnableLogDump;
};
