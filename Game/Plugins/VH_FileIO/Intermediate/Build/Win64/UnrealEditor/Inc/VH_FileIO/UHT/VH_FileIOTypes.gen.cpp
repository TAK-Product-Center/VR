// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_FileIOTypes.h"
#include "ProceduralMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_FileIOTypes() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	PROCEDURALMESHCOMPONENT_API UScriptStruct* Z_Construct_UScriptStruct_FProcMeshTangent();
	UPackage* Z_Construct_UPackage__Script_VH_FileIO();
	VH_FILEIO_API UScriptStruct* Z_Construct_UScriptStruct_FVH_MeshImportMeshData();
	VH_FILEIO_API UScriptStruct* Z_Construct_UScriptStruct_FVH_MeshImportMeshNode();
	VH_FILEIO_API UScriptStruct* Z_Construct_UScriptStruct_FVH_MeshImportOptions();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_VH_MeshImportOptions;
class UScriptStruct* FVH_MeshImportOptions::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_VH_MeshImportOptions.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_VH_MeshImportOptions.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FVH_MeshImportOptions, (UObject*)Z_Construct_UPackage__Script_VH_FileIO(), TEXT("VH_MeshImportOptions"));
	}
	return Z_Registration_Info_UScriptStruct_VH_MeshImportOptions.OuterSingleton;
}
template<> VH_FILEIO_API UScriptStruct* StaticStruct<FVH_MeshImportOptions>()
{
	return FVH_MeshImportOptions::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RootTransform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RootTransform;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVH_MeshImportOptions>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics::NewProp_RootTransform_MetaData[] = {
		{ "Category", "VhFileIO|MeshImportOptions" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics::NewProp_RootTransform = { "RootTransform", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportOptions, RootTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics::NewProp_RootTransform_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics::NewProp_RootTransform_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics::NewProp_RootTransform,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_FileIO,
		nullptr,
		&NewStructOps,
		"VH_MeshImportOptions",
		Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics::PropPointers),
		sizeof(FVH_MeshImportOptions),
		alignof(FVH_MeshImportOptions),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FVH_MeshImportOptions()
	{
		if (!Z_Registration_Info_UScriptStruct_VH_MeshImportOptions.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_VH_MeshImportOptions.InnerSingleton, Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_VH_MeshImportOptions.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_VH_MeshImportMeshData;
class UScriptStruct* FVH_MeshImportMeshData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_VH_MeshImportMeshData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_VH_MeshImportMeshData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FVH_MeshImportMeshData, (UObject*)Z_Construct_UPackage__Script_VH_FileIO(), TEXT("VH_MeshImportMeshData"));
	}
	return Z_Registration_Info_UScriptStruct_VH_MeshImportMeshData.OuterSingleton;
}
template<> VH_FILEIO_API UScriptStruct* StaticStruct<FVH_MeshImportMeshData>()
{
	return FVH_MeshImportMeshData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Vertices_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Vertices_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Vertices;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Triangles_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Triangles_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Triangles;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Normals_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Normals_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Normals;
		static const UECodeGen_Private::FStructPropertyParams NewProp_UV0_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UV0_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_UV0;
		static const UECodeGen_Private::FStructPropertyParams NewProp_UV1_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UV1_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_UV1;
		static const UECodeGen_Private::FStructPropertyParams NewProp_UV2_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UV2_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_UV2;
		static const UECodeGen_Private::FStructPropertyParams NewProp_UV3_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UV3_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_UV3;
		static const UECodeGen_Private::FStructPropertyParams NewProp_VertexColors_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VertexColors_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_VertexColors;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tangents_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Tangents_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Tangents;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaterialIndex_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_MaterialIndex;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVH_MeshImportMeshData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "VhFileIO|MeshData" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshData, Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Name_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Name_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Vertices_Inner = { "Vertices", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Vertices_MetaData[] = {
		{ "Category", "VhFileIO|MeshData" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Vertices = { "Vertices", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshData, Vertices), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Vertices_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Vertices_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Triangles_Inner = { "Triangles", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Triangles_MetaData[] = {
		{ "Category", "VhFileIO|MeshData" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Triangles = { "Triangles", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshData, Triangles), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Triangles_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Triangles_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Normals_Inner = { "Normals", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Normals_MetaData[] = {
		{ "Category", "VhFileIO|MeshData" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Normals = { "Normals", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshData, Normals), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Normals_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Normals_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV0_Inner = { "UV0", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV0_MetaData[] = {
		{ "Category", "VhFileIO|MeshData" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV0 = { "UV0", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshData, UV0), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV0_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV0_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV1_Inner = { "UV1", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV1_MetaData[] = {
		{ "Category", "VhFileIO|MeshData" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV1 = { "UV1", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshData, UV1), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV1_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV1_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV2_Inner = { "UV2", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV2_MetaData[] = {
		{ "Category", "VhFileIO|MeshData" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV2 = { "UV2", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshData, UV2), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV2_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV2_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV3_Inner = { "UV3", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV3_MetaData[] = {
		{ "Category", "VhFileIO|MeshData" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV3 = { "UV3", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshData, UV3), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV3_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV3_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_VertexColors_Inner = { "VertexColors", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_VertexColors_MetaData[] = {
		{ "Category", "VhFileIO|MeshData" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_VertexColors = { "VertexColors", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshData, VertexColors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_VertexColors_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_VertexColors_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Tangents_Inner = { "Tangents", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FProcMeshTangent, METADATA_PARAMS(0, nullptr) }; // 2099358922
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Tangents_MetaData[] = {
		{ "Category", "VhFileIO|MeshData" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Tangents = { "Tangents", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshData, Tangents), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Tangents_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Tangents_MetaData) }; // 2099358922
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_MaterialIndex_MetaData[] = {
		{ "Category", "VhFileIO|MeshData" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_MaterialIndex = { "MaterialIndex", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshData, MaterialIndex), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_MaterialIndex_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_MaterialIndex_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Vertices_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Vertices,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Triangles_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Triangles,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Normals_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Normals,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV0_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV0,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV1_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV1,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV2_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV2,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV3_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_UV3,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_VertexColors_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_VertexColors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Tangents_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_Tangents,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewProp_MaterialIndex,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_FileIO,
		nullptr,
		&NewStructOps,
		"VH_MeshImportMeshData",
		Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::PropPointers),
		sizeof(FVH_MeshImportMeshData),
		alignof(FVH_MeshImportMeshData),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FVH_MeshImportMeshData()
	{
		if (!Z_Registration_Info_UScriptStruct_VH_MeshImportMeshData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_VH_MeshImportMeshData.InnerSingleton, Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_VH_MeshImportMeshData.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_VH_MeshImportMeshNode;
class UScriptStruct* FVH_MeshImportMeshNode::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_VH_MeshImportMeshNode.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_VH_MeshImportMeshNode.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FVH_MeshImportMeshNode, (UObject*)Z_Construct_UPackage__Script_VH_FileIO(), TEXT("VH_MeshImportMeshNode"));
	}
	return Z_Registration_Info_UScriptStruct_VH_MeshImportMeshNode.OuterSingleton;
}
template<> VH_FILEIO_API UScriptStruct* StaticStruct<FVH_MeshImportMeshNode>()
{
	return FVH_MeshImportMeshNode::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NodeIndex_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_NodeIndex;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ParentNode_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ParentNode;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ChildNodes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChildNodes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ChildNodes;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RelativeTransform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RelativeTransform;
		static const UECodeGen_Private::FIntPropertyParams NewProp_Meshes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Meshes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Meshes;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVH_MeshImportMeshNode>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "VhFileIO|MeshNode" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshNode, Name), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_Name_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_Name_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_NodeIndex_MetaData[] = {
		{ "Category", "VhFileIO|MeshNode" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_NodeIndex = { "NodeIndex", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshNode, NodeIndex), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_NodeIndex_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_NodeIndex_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_ParentNode_MetaData[] = {
		{ "Category", "VhFileIO|MeshNode" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_ParentNode = { "ParentNode", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshNode, ParentNode), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_ParentNode_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_ParentNode_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_ChildNodes_Inner = { "ChildNodes", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_ChildNodes_MetaData[] = {
		{ "Category", "VhFileIO|MeshNode" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_ChildNodes = { "ChildNodes", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshNode, ChildNodes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_ChildNodes_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_ChildNodes_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_RelativeTransform_MetaData[] = {
		{ "Category", "VhFileIO|MeshNode" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_RelativeTransform = { "RelativeTransform", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshNode, RelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_RelativeTransform_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_RelativeTransform_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_Meshes_Inner = { "Meshes", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_Meshes_MetaData[] = {
		{ "Category", "VhFileIO|MeshNode" },
		{ "ModuleRelativePath", "Core/Public/VH_FileIOTypes.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_Meshes = { "Meshes", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVH_MeshImportMeshNode, Meshes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_Meshes_MetaData), Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_Meshes_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_NodeIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_ParentNode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_ChildNodes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_ChildNodes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_RelativeTransform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_Meshes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewProp_Meshes,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_FileIO,
		nullptr,
		&NewStructOps,
		"VH_MeshImportMeshNode",
		Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::PropPointers),
		sizeof(FVH_MeshImportMeshNode),
		alignof(FVH_MeshImportMeshNode),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FVH_MeshImportMeshNode()
	{
		if (!Z_Registration_Info_UScriptStruct_VH_MeshImportMeshNode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_VH_MeshImportMeshNode.InnerSingleton, Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_VH_MeshImportMeshNode.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOTypes_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOTypes_h_Statics::ScriptStructInfo[] = {
		{ FVH_MeshImportOptions::StaticStruct, Z_Construct_UScriptStruct_FVH_MeshImportOptions_Statics::NewStructOps, TEXT("VH_MeshImportOptions"), &Z_Registration_Info_UScriptStruct_VH_MeshImportOptions, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FVH_MeshImportOptions), 3180495876U) },
		{ FVH_MeshImportMeshData::StaticStruct, Z_Construct_UScriptStruct_FVH_MeshImportMeshData_Statics::NewStructOps, TEXT("VH_MeshImportMeshData"), &Z_Registration_Info_UScriptStruct_VH_MeshImportMeshData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FVH_MeshImportMeshData), 1565652211U) },
		{ FVH_MeshImportMeshNode::StaticStruct, Z_Construct_UScriptStruct_FVH_MeshImportMeshNode_Statics::NewStructOps, TEXT("VH_MeshImportMeshNode"), &Z_Registration_Info_UScriptStruct_VH_MeshImportMeshNode, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FVH_MeshImportMeshNode), 3443388292U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOTypes_h_2679480906(TEXT("/Script/VH_FileIO"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOTypes_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
