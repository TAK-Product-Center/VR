// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Developer_ManipulationComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_ManipulationComponent() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuat();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_ManipulationComponent();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_ManipulationComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UDeveloper_ManipulationComponent::execServer_SetWorldScale)
	{
		P_GET_OBJECT(AActor,Z_Param_actor);
		P_GET_STRUCT(FVector,Z_Param_scale);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Server_SetWorldScale_Implementation(Z_Param_actor,Z_Param_scale);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_ManipulationComponent::execServer_SetWorldRotation)
	{
		P_GET_OBJECT(AActor,Z_Param_actor);
		P_GET_STRUCT(FQuat,Z_Param_rotation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Server_SetWorldRotation_Implementation(Z_Param_actor,Z_Param_rotation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_ManipulationComponent::execServer_SetWorldLocation)
	{
		P_GET_OBJECT(AActor,Z_Param_actor);
		P_GET_STRUCT(FVector,Z_Param_location);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Server_SetWorldLocation_Implementation(Z_Param_actor,Z_Param_location);
		P_NATIVE_END;
	}
	struct Developer_ManipulationComponent_eventServer_SetWorldLocation_Parms
	{
		AActor* actor;
		FVector location;
	};
	struct Developer_ManipulationComponent_eventServer_SetWorldRotation_Parms
	{
		AActor* actor;
		FQuat rotation;
	};
	struct Developer_ManipulationComponent_eventServer_SetWorldScale_Parms
	{
		AActor* actor;
		FVector scale;
	};
	static FName NAME_UDeveloper_ManipulationComponent_Server_SetWorldLocation = FName(TEXT("Server_SetWorldLocation"));
	void UDeveloper_ManipulationComponent::Server_SetWorldLocation(AActor* actor, FVector const& location)
	{
		Developer_ManipulationComponent_eventServer_SetWorldLocation_Parms Parms;
		Parms.actor=actor;
		Parms.location=location;
		ProcessEvent(FindFunctionChecked(NAME_UDeveloper_ManipulationComponent_Server_SetWorldLocation),&Parms);
	}
	static FName NAME_UDeveloper_ManipulationComponent_Server_SetWorldRotation = FName(TEXT("Server_SetWorldRotation"));
	void UDeveloper_ManipulationComponent::Server_SetWorldRotation(AActor* actor, FQuat const& rotation)
	{
		Developer_ManipulationComponent_eventServer_SetWorldRotation_Parms Parms;
		Parms.actor=actor;
		Parms.rotation=rotation;
		ProcessEvent(FindFunctionChecked(NAME_UDeveloper_ManipulationComponent_Server_SetWorldRotation),&Parms);
	}
	static FName NAME_UDeveloper_ManipulationComponent_Server_SetWorldScale = FName(TEXT("Server_SetWorldScale"));
	void UDeveloper_ManipulationComponent::Server_SetWorldScale(AActor* actor, FVector const& scale)
	{
		Developer_ManipulationComponent_eventServer_SetWorldScale_Parms Parms;
		Parms.actor=actor;
		Parms.scale=scale;
		ProcessEvent(FindFunctionChecked(NAME_UDeveloper_ManipulationComponent_Server_SetWorldScale),&Parms);
	}
	void UDeveloper_ManipulationComponent::StaticRegisterNativesUDeveloper_ManipulationComponent()
	{
		UClass* Class = UDeveloper_ManipulationComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Server_SetWorldLocation", &UDeveloper_ManipulationComponent::execServer_SetWorldLocation },
			{ "Server_SetWorldRotation", &UDeveloper_ManipulationComponent::execServer_SetWorldRotation },
			{ "Server_SetWorldScale", &UDeveloper_ManipulationComponent::execServer_SetWorldScale },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_location;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics::NewProp_actor = { "actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_ManipulationComponent_eventServer_SetWorldLocation_Parms, actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics::NewProp_location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics::NewProp_location = { "location", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_ManipulationComponent_eventServer_SetWorldLocation_Parms, location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics::NewProp_location_MetaData), Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics::NewProp_location_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics::NewProp_actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics::NewProp_location,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/Developer_ManipulationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_ManipulationComponent, nullptr, "Server_SetWorldLocation", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics::PropPointers), sizeof(Developer_ManipulationComponent_eventServer_SetWorldLocation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00A40CC1, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Developer_ManipulationComponent_eventServer_SetWorldLocation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_rotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_rotation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics::NewProp_actor = { "actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_ManipulationComponent_eventServer_SetWorldRotation_Parms, actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics::NewProp_rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics::NewProp_rotation = { "rotation", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_ManipulationComponent_eventServer_SetWorldRotation_Parms, rotation), Z_Construct_UScriptStruct_FQuat, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics::NewProp_rotation_MetaData), Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics::NewProp_rotation_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics::NewProp_actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics::NewProp_rotation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/Developer_ManipulationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_ManipulationComponent, nullptr, "Server_SetWorldRotation", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics::PropPointers), sizeof(Developer_ManipulationComponent_eventServer_SetWorldRotation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00A40CC1, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Developer_ManipulationComponent_eventServer_SetWorldRotation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_scale_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_scale;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics::NewProp_actor = { "actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_ManipulationComponent_eventServer_SetWorldScale_Parms, actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics::NewProp_scale_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics::NewProp_scale = { "scale", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_ManipulationComponent_eventServer_SetWorldScale_Parms, scale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics::NewProp_scale_MetaData), Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics::NewProp_scale_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics::NewProp_actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics::NewProp_scale,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/Developer_ManipulationComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_ManipulationComponent, nullptr, "Server_SetWorldScale", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics::PropPointers), sizeof(Developer_ManipulationComponent_eventServer_SetWorldScale_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00A40CC1, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics::PropPointers) < 2048);
	static_assert(sizeof(Developer_ManipulationComponent_eventServer_SetWorldScale_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_ManipulationComponent);
	UClass* Z_Construct_UClass_UDeveloper_ManipulationComponent_NoRegister()
	{
		return UDeveloper_ManipulationComponent::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_ManipulationComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_ManipulationComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_ManipulationComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDeveloper_ManipulationComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldLocation, "Server_SetWorldLocation" }, // 3767744826
		{ &Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldRotation, "Server_SetWorldRotation" }, // 2701205565
		{ &Z_Construct_UFunction_UDeveloper_ManipulationComponent_Server_SetWorldScale, "Server_SetWorldScale" }, // 3724978553
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_ManipulationComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_ManipulationComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "IncludePath", "Components/Public/Developer_ManipulationComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Components/Public/Developer_ManipulationComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_ManipulationComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_ManipulationComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_ManipulationComponent_Statics::ClassParams = {
		&UDeveloper_ManipulationComponent::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_ManipulationComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_ManipulationComponent_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UDeveloper_ManipulationComponent()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_ManipulationComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_ManipulationComponent.OuterSingleton, Z_Construct_UClass_UDeveloper_ManipulationComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_ManipulationComponent.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_ManipulationComponent>()
	{
		return UDeveloper_ManipulationComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_ManipulationComponent);
	UDeveloper_ManipulationComponent::~UDeveloper_ManipulationComponent() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_ManipulationComponent, UDeveloper_ManipulationComponent::StaticClass, TEXT("UDeveloper_ManipulationComponent"), &Z_Registration_Info_UClass_UDeveloper_ManipulationComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_ManipulationComponent), 2353362818U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_2558574469(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
