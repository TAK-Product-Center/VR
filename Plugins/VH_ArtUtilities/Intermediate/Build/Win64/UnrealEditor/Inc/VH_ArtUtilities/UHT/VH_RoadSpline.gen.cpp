// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_ArtUtilities/Public/VH_RoadSpline.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_RoadSpline() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_USplineComponent_NoRegister();
	FOLIAGE_API UClass* Z_Construct_UClass_UFoliageInstancedStaticMeshComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_ArtUtilities();
	VH_ARTUTILITIES_API UClass* Z_Construct_UClass_AVH_RoadSpline();
	VH_ARTUTILITIES_API UClass* Z_Construct_UClass_AVH_RoadSpline_NoRegister();
	VH_ARTUTILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FFoliageTransforms();
	VH_ARTUTILITIES_API UScriptStruct* Z_Construct_UScriptStruct_FRoadData();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_RoadData;
class UScriptStruct* FRoadData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_RoadData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_RoadData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRoadData, (UObject*)Z_Construct_UPackage__Script_VH_ArtUtilities(), TEXT("RoadData"));
	}
	return Z_Registration_Info_UScriptStruct_RoadData.OuterSingleton;
}
template<> VH_ARTUTILITIES_API UScriptStruct* StaticStruct<FRoadData>()
{
	return FRoadData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FRoadData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RoadBank_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RoadBank;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RoadWidth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RoadWidth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RoadThickness_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_RoadThickness;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRoadData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Structs\n// ---------------------------------\n" },
#endif
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/VH_RoadSpline.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Structs" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FRoadData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRoadData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRoadData_Statics::NewProp_RoadBank_MetaData[] = {
		{ "Category", "RoadData" },
		{ "ModuleRelativePath", "Public/VH_RoadSpline.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRoadData_Statics::NewProp_RoadBank = { "RoadBank", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoadData, RoadBank), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoadData_Statics::NewProp_RoadBank_MetaData), Z_Construct_UScriptStruct_FRoadData_Statics::NewProp_RoadBank_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRoadData_Statics::NewProp_RoadWidth_MetaData[] = {
		{ "Category", "RoadData" },
		{ "ModuleRelativePath", "Public/VH_RoadSpline.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRoadData_Statics::NewProp_RoadWidth = { "RoadWidth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoadData, RoadWidth), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoadData_Statics::NewProp_RoadWidth_MetaData), Z_Construct_UScriptStruct_FRoadData_Statics::NewProp_RoadWidth_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRoadData_Statics::NewProp_RoadThickness_MetaData[] = {
		{ "Category", "RoadData" },
		{ "ModuleRelativePath", "Public/VH_RoadSpline.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FRoadData_Statics::NewProp_RoadThickness = { "RoadThickness", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FRoadData, RoadThickness), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoadData_Statics::NewProp_RoadThickness_MetaData), Z_Construct_UScriptStruct_FRoadData_Statics::NewProp_RoadThickness_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FRoadData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoadData_Statics::NewProp_RoadBank,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoadData_Statics::NewProp_RoadWidth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FRoadData_Statics::NewProp_RoadThickness,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRoadData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_ArtUtilities,
		nullptr,
		&NewStructOps,
		"RoadData",
		Z_Construct_UScriptStruct_FRoadData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoadData_Statics::PropPointers),
		sizeof(FRoadData),
		alignof(FRoadData),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoadData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FRoadData_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRoadData_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FRoadData()
	{
		if (!Z_Registration_Info_UScriptStruct_RoadData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_RoadData.InnerSingleton, Z_Construct_UScriptStruct_FRoadData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_RoadData.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FoliageTransforms;
class UScriptStruct* FFoliageTransforms::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FoliageTransforms.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FoliageTransforms.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFoliageTransforms, (UObject*)Z_Construct_UPackage__Script_VH_ArtUtilities(), TEXT("FoliageTransforms"));
	}
	return Z_Registration_Info_UScriptStruct_FoliageTransforms.OuterSingleton;
}
template<> VH_ARTUTILITIES_API UScriptStruct* StaticStruct<FFoliageTransforms>()
{
	return FFoliageTransforms::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FFoliageTransforms_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructPropertyParams NewProp_Transforms_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Transforms_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Transforms;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFoliageTransforms_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/VH_RoadSpline.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FFoliageTransforms_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFoliageTransforms>();
	}
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FFoliageTransforms_Statics::NewProp_Transforms_Inner = { "Transforms", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFoliageTransforms_Statics::NewProp_Transforms_MetaData[] = {
		{ "Category", "FoliageTransforms" },
		{ "ModuleRelativePath", "Public/VH_RoadSpline.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FFoliageTransforms_Statics::NewProp_Transforms = { "Transforms", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFoliageTransforms, Transforms), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFoliageTransforms_Statics::NewProp_Transforms_MetaData), Z_Construct_UScriptStruct_FFoliageTransforms_Statics::NewProp_Transforms_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFoliageTransforms_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFoliageTransforms_Statics::NewProp_Transforms_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFoliageTransforms_Statics::NewProp_Transforms,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFoliageTransforms_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_ArtUtilities,
		nullptr,
		&NewStructOps,
		"FoliageTransforms",
		Z_Construct_UScriptStruct_FFoliageTransforms_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFoliageTransforms_Statics::PropPointers),
		sizeof(FFoliageTransforms),
		alignof(FFoliageTransforms),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFoliageTransforms_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FFoliageTransforms_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFoliageTransforms_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FFoliageTransforms()
	{
		if (!Z_Registration_Info_UScriptStruct_FoliageTransforms.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FoliageTransforms.InnerSingleton, Z_Construct_UScriptStruct_FFoliageTransforms_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_FoliageTransforms.InnerSingleton;
	}
	void AVH_RoadSpline::StaticRegisterNativesAVH_RoadSpline()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVH_RoadSpline);
	UClass* Z_Construct_UClass_AVH_RoadSpline_NoRegister()
	{
		return AVH_RoadSpline::StaticClass();
	}
	struct Z_Construct_UClass_AVH_RoadSpline_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Spline_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Spline;
		static const UECodeGen_Private::FStructPropertyParams NewProp_RoadDataArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RoadDataArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_RoadDataArray;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RoadMeshDefaults_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RoadMeshDefaults;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bLoopingTrack_MetaData[];
#endif
		static void NewProp_bLoopingTrack_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bLoopingTrack;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FloorTraceLength_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FloorTraceLength;
		static const UECodeGen_Private::FStructPropertyParams NewProp_DestroyedFoliage_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DestroyedFoliage_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DestroyedFoliage_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_DestroyedFoliage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDestroyFoliage_MetaData[];
#endif
		static void NewProp_bDestroyFoliage_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDestroyFoliage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FoliageSphereTraceRadius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FoliageSphereTraceRadius;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVH_RoadSpline_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_ArtUtilities,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_RoadSpline_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_RoadSpline_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "VH_RoadSpline.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/VH_RoadSpline.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_Spline_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Road" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/VH_RoadSpline.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_Spline = { "Spline", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_RoadSpline, Spline), Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_Spline_MetaData), Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_Spline_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_RoadDataArray_Inner = { "RoadDataArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FRoadData, METADATA_PARAMS(0, nullptr) }; // 3994996717
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_RoadDataArray_MetaData[] = {
		{ "Category", "Track Setup" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The spline mesh construction information for each road segment. */" },
#endif
		{ "ModuleRelativePath", "Public/VH_RoadSpline.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The spline mesh construction information for each road segment." },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_RoadDataArray = { "RoadDataArray", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_RoadSpline, RoadDataArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_RoadDataArray_MetaData), Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_RoadDataArray_MetaData) }; // 3994996717
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_RoadMeshDefaults_MetaData[] = {
		{ "Category", "Track Setup" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**  The road data that new road segments are initialized to. */" },
#endif
		{ "ModuleRelativePath", "Public/VH_RoadSpline.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The road data that new road segments are initialized to." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_RoadMeshDefaults = { "RoadMeshDefaults", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_RoadSpline, RoadMeshDefaults), Z_Construct_UScriptStruct_FRoadData, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_RoadMeshDefaults_MetaData), Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_RoadMeshDefaults_MetaData) }; // 3994996717
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_bLoopingTrack_MetaData[] = {
		{ "Category", "Track Setup" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Should this road build an additional segment to close the loop */" },
#endif
		{ "ModuleRelativePath", "Public/VH_RoadSpline.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should this road build an additional segment to close the loop" },
#endif
	};
#endif
	void Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_bLoopingTrack_SetBit(void* Obj)
	{
		((AVH_RoadSpline*)Obj)->bLoopingTrack = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_bLoopingTrack = { "bLoopingTrack", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AVH_RoadSpline), &Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_bLoopingTrack_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_bLoopingTrack_MetaData), Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_bLoopingTrack_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_FloorTraceLength_MetaData[] = {
		{ "Category", "Track Setup" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How far each segment should trace down to find a blocking floor. If no floor is found, the segment will not be adjusted. Always applied to -Z */" },
#endif
		{ "ModuleRelativePath", "Public/VH_RoadSpline.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How far each segment should trace down to find a blocking floor. If no floor is found, the segment will not be adjusted. Always applied to -Z" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_FloorTraceLength = { "FloorTraceLength", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_RoadSpline, FloorTraceLength), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_FloorTraceLength_MetaData), Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_FloorTraceLength_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_DestroyedFoliage_ValueProp = { "DestroyedFoliage", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FFoliageTransforms, METADATA_PARAMS(0, nullptr) }; // 3402924986
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_DestroyedFoliage_Key_KeyProp = { "DestroyedFoliage_Key", nullptr, (EPropertyFlags)0x0000000000080001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UFoliageInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_DestroyedFoliage_MetaData[] = {
		{ "Category", "Foliage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The cached transforms of destroyed foliage actors. Used for the restoration function. */" },
#endif
		{ "ModuleRelativePath", "Public/VH_RoadSpline.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The cached transforms of destroyed foliage actors. Used for the restoration function." },
#endif
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_DestroyedFoliage = { "DestroyedFoliage", nullptr, (EPropertyFlags)0x0020088000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_RoadSpline, DestroyedFoliage), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_DestroyedFoliage_MetaData), Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_DestroyedFoliage_MetaData) }; // 3402924986
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_bDestroyFoliage_MetaData[] = {
		{ "Category", "Foliage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If enabled, foliage will be destroyed on begin play */" },
#endif
		{ "ModuleRelativePath", "Public/VH_RoadSpline.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If enabled, foliage will be destroyed on begin play" },
#endif
	};
#endif
	void Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_bDestroyFoliage_SetBit(void* Obj)
	{
		((AVH_RoadSpline*)Obj)->bDestroyFoliage = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_bDestroyFoliage = { "bDestroyFoliage", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AVH_RoadSpline), &Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_bDestroyFoliage_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_bDestroyFoliage_MetaData), Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_bDestroyFoliage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_FoliageSphereTraceRadius_MetaData[] = {
		{ "Category", "Foliage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The trace radius for foliage destruction. Should be greater than the width of the road. */" },
#endif
		{ "ModuleRelativePath", "Public/VH_RoadSpline.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The trace radius for foliage destruction. Should be greater than the width of the road." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_FoliageSphereTraceRadius = { "FoliageSphereTraceRadius", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_RoadSpline, FoliageSphereTraceRadius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_FoliageSphereTraceRadius_MetaData), Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_FoliageSphereTraceRadius_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVH_RoadSpline_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_Spline,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_RoadDataArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_RoadDataArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_RoadMeshDefaults,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_bLoopingTrack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_FloorTraceLength,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_DestroyedFoliage_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_DestroyedFoliage_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_DestroyedFoliage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_bDestroyFoliage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_RoadSpline_Statics::NewProp_FoliageSphereTraceRadius,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVH_RoadSpline_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVH_RoadSpline>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AVH_RoadSpline_Statics::ClassParams = {
		&AVH_RoadSpline::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AVH_RoadSpline_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AVH_RoadSpline_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_RoadSpline_Statics::Class_MetaDataParams), Z_Construct_UClass_AVH_RoadSpline_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_RoadSpline_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AVH_RoadSpline()
	{
		if (!Z_Registration_Info_UClass_AVH_RoadSpline.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVH_RoadSpline.OuterSingleton, Z_Construct_UClass_AVH_RoadSpline_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AVH_RoadSpline.OuterSingleton;
	}
	template<> VH_ARTUTILITIES_API UClass* StaticClass<AVH_RoadSpline>()
	{
		return AVH_RoadSpline::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVH_RoadSpline);
	AVH_RoadSpline::~AVH_RoadSpline() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilities_Public_VH_RoadSpline_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilities_Public_VH_RoadSpline_h_Statics::ScriptStructInfo[] = {
		{ FRoadData::StaticStruct, Z_Construct_UScriptStruct_FRoadData_Statics::NewStructOps, TEXT("RoadData"), &Z_Registration_Info_UScriptStruct_RoadData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRoadData), 3994996717U) },
		{ FFoliageTransforms::StaticStruct, Z_Construct_UScriptStruct_FFoliageTransforms_Statics::NewStructOps, TEXT("FoliageTransforms"), &Z_Registration_Info_UScriptStruct_FoliageTransforms, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFoliageTransforms), 3402924986U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilities_Public_VH_RoadSpline_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AVH_RoadSpline, AVH_RoadSpline::StaticClass, TEXT("AVH_RoadSpline"), &Z_Registration_Info_UClass_AVH_RoadSpline, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVH_RoadSpline), 3548361089U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilities_Public_VH_RoadSpline_h_1614225755(TEXT("/Script/VH_ArtUtilities"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilities_Public_VH_RoadSpline_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilities_Public_VH_RoadSpline_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilities_Public_VH_RoadSpline_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_ArtUtilities_Source_VH_ArtUtilities_Public_VH_RoadSpline_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
