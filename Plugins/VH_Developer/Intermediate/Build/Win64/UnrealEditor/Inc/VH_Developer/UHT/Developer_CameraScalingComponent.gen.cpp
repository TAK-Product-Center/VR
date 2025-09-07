// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Developer_CameraScalingComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_CameraScalingComponent() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_CameraScalingComponent();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_CameraScalingComponent_NoRegister();
// End Cross Module References
	void UDeveloper_CameraScalingComponent::StaticRegisterNativesUDeveloper_CameraScalingComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_CameraScalingComponent);
	UClass* Z_Construct_UClass_UDeveloper_CameraScalingComponent_NoRegister()
	{
		return UDeveloper_CameraScalingComponent::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bRotate_MetaData[];
#endif
		static void NewProp_bRotate_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bRotate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bScale_MetaData[];
#endif
		static void NewProp_bScale_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bScale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MinMaxCameraDistanceForScaling_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MinMaxCameraDistanceForScaling;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MinScale_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MinScale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxScale_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MaxScale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CustomScaleMultiplier_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_CustomScaleMultiplier;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USceneComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "Components/Public/Developer_CameraScalingComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Components/Public/Developer_CameraScalingComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_bRotate_MetaData[] = {
		{ "Category", "Developer_CameraScalingComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* if true, component rotates to face player camera */" },
#endif
		{ "ModuleRelativePath", "Components/Public/Developer_CameraScalingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "if true, component rotates to face player camera" },
#endif
	};
#endif
	void Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_bRotate_SetBit(void* Obj)
	{
		((UDeveloper_CameraScalingComponent*)Obj)->bRotate = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_bRotate = { "bRotate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDeveloper_CameraScalingComponent), &Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_bRotate_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_bRotate_MetaData), Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_bRotate_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_bScale_MetaData[] = {
		{ "Category", "Developer_CameraScalingComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* if true, component scaled based on scaling parameters */" },
#endif
		{ "ModuleRelativePath", "Components/Public/Developer_CameraScalingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "if true, component scaled based on scaling parameters" },
#endif
	};
#endif
	void Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_bScale_SetBit(void* Obj)
	{
		((UDeveloper_CameraScalingComponent*)Obj)->bScale = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_bScale = { "bScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UDeveloper_CameraScalingComponent), &Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_bScale_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_bScale_MetaData), Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_bScale_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_MinMaxCameraDistanceForScaling_MetaData[] = {
		{ "Category", "Developer_CameraScalingComponent" },
		{ "ModuleRelativePath", "Components/Public/Developer_CameraScalingComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_MinMaxCameraDistanceForScaling = { "MinMaxCameraDistanceForScaling", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_CameraScalingComponent, MinMaxCameraDistanceForScaling), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_MinMaxCameraDistanceForScaling_MetaData), Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_MinMaxCameraDistanceForScaling_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_MinScale_MetaData[] = {
		{ "Category", "Developer_CameraScalingComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* scale when distance <= MinCameraDistanceForScaling */" },
#endif
		{ "ModuleRelativePath", "Components/Public/Developer_CameraScalingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "scale when distance <= MinCameraDistanceForScaling" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_MinScale = { "MinScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_CameraScalingComponent, MinScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_MinScale_MetaData), Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_MinScale_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_MaxScale_MetaData[] = {
		{ "Category", "Developer_CameraScalingComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* scale when distance >= MaxCameraDistanceForScaling */" },
#endif
		{ "ModuleRelativePath", "Components/Public/Developer_CameraScalingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "scale when distance >= MaxCameraDistanceForScaling" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_MaxScale = { "MaxScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_CameraScalingComponent, MaxScale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_MaxScale_MetaData), Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_MaxScale_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_CustomScaleMultiplier_MetaData[] = {
		{ "Category", "Developer_CameraScalingComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* across the board multiplier when determining scale */" },
#endif
		{ "ModuleRelativePath", "Components/Public/Developer_CameraScalingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "across the board multiplier when determining scale" },
#endif
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_CustomScaleMultiplier = { "CustomScaleMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_CameraScalingComponent, CustomScaleMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_CustomScaleMultiplier_MetaData), Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_CustomScaleMultiplier_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_bRotate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_bScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_MinMaxCameraDistanceForScaling,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_MinScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_MaxScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::NewProp_CustomScaleMultiplier,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_CameraScalingComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::ClassParams = {
		&UDeveloper_CameraScalingComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDeveloper_CameraScalingComponent()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_CameraScalingComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_CameraScalingComponent.OuterSingleton, Z_Construct_UClass_UDeveloper_CameraScalingComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_CameraScalingComponent.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_CameraScalingComponent>()
	{
		return UDeveloper_CameraScalingComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_CameraScalingComponent);
	UDeveloper_CameraScalingComponent::~UDeveloper_CameraScalingComponent() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_CameraScalingComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_CameraScalingComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_CameraScalingComponent, UDeveloper_CameraScalingComponent::StaticClass, TEXT("UDeveloper_CameraScalingComponent"), &Z_Registration_Info_UClass_UDeveloper_CameraScalingComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_CameraScalingComponent), 2513969976U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_CameraScalingComponent_h_859596941(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_CameraScalingComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_CameraScalingComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
