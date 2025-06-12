// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VR_CoreComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVR_CoreComponent() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_VH_VR();
	VH_VR_API UClass* Z_Construct_UClass_UVR_CoreComponent();
	VH_VR_API UClass* Z_Construct_UClass_UVR_CoreComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UVR_CoreComponent::execServer_SetRelativeTransform)
	{
		P_GET_STRUCT(FTransform,Z_Param_transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Server_SetRelativeTransform_Implementation(Z_Param_transform);
		P_NATIVE_END;
	}
	struct VR_CoreComponent_eventServer_SetRelativeTransform_Parms
	{
		FTransform transform;
	};
	static FName NAME_UVR_CoreComponent_Server_SetRelativeTransform = FName(TEXT("Server_SetRelativeTransform"));
	void UVR_CoreComponent::Server_SetRelativeTransform(FTransform const& transform)
	{
		VR_CoreComponent_eventServer_SetRelativeTransform_Parms Parms;
		Parms.transform=transform;
		ProcessEvent(FindFunctionChecked(NAME_UVR_CoreComponent_Server_SetRelativeTransform),&Parms);
	}
	void UVR_CoreComponent::StaticRegisterNativesUVR_CoreComponent()
	{
		UClass* Class = UVR_CoreComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Server_SetRelativeTransform", &UVR_CoreComponent::execServer_SetRelativeTransform },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_transform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_transform;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform_Statics::NewProp_transform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform_Statics::NewProp_transform = { "transform", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_CoreComponent_eventServer_SetRelativeTransform_Parms, transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform_Statics::NewProp_transform_MetaData), Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform_Statics::NewProp_transform_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform_Statics::NewProp_transform,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_CoreComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_CoreComponent, nullptr, "Server_SetRelativeTransform", nullptr, nullptr, Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform_Statics::PropPointers), sizeof(VR_CoreComponent_eventServer_SetRelativeTransform_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00A40C41, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform_Statics::PropPointers) < 2048);
	static_assert(sizeof(VR_CoreComponent_eventServer_SetRelativeTransform_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVR_CoreComponent);
	UClass* Z_Construct_UClass_UVR_CoreComponent_NoRegister()
	{
		return UVR_CoreComponent::StaticClass();
	}
	struct Z_Construct_UClass_UVR_CoreComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVR_CoreComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_VR,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_CoreComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVR_CoreComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVR_CoreComponent_Server_SetRelativeTransform, "Server_SetRelativeTransform" }, // 3207332786
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_CoreComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_CoreComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "IncludePath", "Components/Public/VR_CoreComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Components/Public/VR_CoreComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVR_CoreComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVR_CoreComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVR_CoreComponent_Statics::ClassParams = {
		&UVR_CoreComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_CoreComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UVR_CoreComponent_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UVR_CoreComponent()
	{
		if (!Z_Registration_Info_UClass_UVR_CoreComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVR_CoreComponent.OuterSingleton, Z_Construct_UClass_UVR_CoreComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVR_CoreComponent.OuterSingleton;
	}
	template<> VH_VR_API UClass* StaticClass<UVR_CoreComponent>()
	{
		return UVR_CoreComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVR_CoreComponent);
	UVR_CoreComponent::~UVR_CoreComponent() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVR_CoreComponent, UVR_CoreComponent::StaticClass, TEXT("UVR_CoreComponent"), &Z_Registration_Info_UClass_UVR_CoreComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVR_CoreComponent), 2567496334U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_108519610(TEXT("/Script/VH_VR"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_CoreComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
