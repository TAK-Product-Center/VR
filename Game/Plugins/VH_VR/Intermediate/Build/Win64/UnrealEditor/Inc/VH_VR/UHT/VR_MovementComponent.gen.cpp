// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VR_MovementComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVR_MovementComponent() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UFloatingPawnMovement();
	UPackage* Z_Construct_UPackage__Script_VH_VR();
	VH_VR_API UClass* Z_Construct_UClass_UVR_MovementComponent();
	VH_VR_API UClass* Z_Construct_UClass_UVR_MovementComponent_NoRegister();
	VH_VR_API UFunction* Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics
	{
		struct VR_MovementComponent_eventOnWorldTransformOverrideUpdated_Parms
		{
			FTransform worldTransformOverride;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_worldTransformOverride_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_worldTransformOverride;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics::NewProp_worldTransformOverride_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics::NewProp_worldTransformOverride = { "worldTransformOverride", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_MovementComponent_eventOnWorldTransformOverrideUpdated_Parms, worldTransformOverride), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics::NewProp_worldTransformOverride_MetaData), Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics::NewProp_worldTransformOverride_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics::NewProp_worldTransformOverride,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MovementComponent, nullptr, "OnWorldTransformOverrideUpdated__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics::VR_MovementComponent_eventOnWorldTransformOverrideUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00D30000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics::VR_MovementComponent_eventOnWorldTransformOverrideUpdated_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UVR_MovementComponent::FOnWorldTransformOverrideUpdated_DelegateWrapper(const FMulticastScriptDelegate& OnWorldTransformOverrideUpdated, FTransform const& worldTransformOverride)
{
	struct VR_MovementComponent_eventOnWorldTransformOverrideUpdated_Parms
	{
		FTransform worldTransformOverride;
	};
	VR_MovementComponent_eventOnWorldTransformOverrideUpdated_Parms Parms;
	Parms.worldTransformOverride=worldTransformOverride;
	OnWorldTransformOverrideUpdated.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UVR_MovementComponent::execGetWorldTransformOverride)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FTransform*)Z_Param__Result=P_THIS->GetWorldTransformOverride();
		P_NATIVE_END;
	}
	void UVR_MovementComponent::StaticRegisterNativesUVR_MovementComponent()
	{
		UClass* Class = UVR_MovementComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetWorldTransformOverride", &UVR_MovementComponent::execGetWorldTransformOverride },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVR_MovementComponent_GetWorldTransformOverride_Statics
	{
		struct VR_MovementComponent_eventGetWorldTransformOverride_Parms
		{
			FTransform ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVR_MovementComponent_GetWorldTransformOverride_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_MovementComponent_eventGetWorldTransformOverride_Parms, ReturnValue), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_MovementComponent_GetWorldTransformOverride_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MovementComponent_GetWorldTransformOverride_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MovementComponent_GetWorldTransformOverride_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MovementComponent_GetWorldTransformOverride_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MovementComponent, nullptr, "GetWorldTransformOverride", nullptr, nullptr, Z_Construct_UFunction_UVR_MovementComponent_GetWorldTransformOverride_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MovementComponent_GetWorldTransformOverride_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVR_MovementComponent_GetWorldTransformOverride_Statics::VR_MovementComponent_eventGetWorldTransformOverride_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MovementComponent_GetWorldTransformOverride_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MovementComponent_GetWorldTransformOverride_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MovementComponent_GetWorldTransformOverride_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVR_MovementComponent_GetWorldTransformOverride_Statics::VR_MovementComponent_eventGetWorldTransformOverride_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_MovementComponent_GetWorldTransformOverride()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MovementComponent_GetWorldTransformOverride_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVR_MovementComponent);
	UClass* Z_Construct_UClass_UVR_MovementComponent_NoRegister()
	{
		return UVR_MovementComponent::StaticClass();
	}
	struct Z_Construct_UClass_UVR_MovementComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnWorldTransformOverrideUpdated_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnWorldTransformOverrideUpdated;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MovementDirectionMultiplier_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MovementDirectionMultiplier;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Gravity_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Gravity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GroundCheckDistance_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_GroundCheckDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bInstantAcceleration_MetaData[];
#endif
		static void NewProp_bInstantAcceleration_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bInstantAcceleration;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bInstantDeceleration_MetaData[];
#endif
		static void NewProp_bInstantDeceleration_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bInstantDeceleration;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVR_MovementComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFloatingPawnMovement,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_VR,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MovementComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVR_MovementComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVR_MovementComponent_GetWorldTransformOverride, "GetWorldTransformOverride" }, // 2165166408
		{ &Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature, "OnWorldTransformOverrideUpdated__DelegateSignature" }, // 2273776349
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MovementComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_MovementComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "IncludePath", "Components/Public/VR_MovementComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Components/Public/VR_MovementComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_OnWorldTransformOverrideUpdated_MetaData[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_OnWorldTransformOverrideUpdated = { "OnWorldTransformOverrideUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVR_MovementComponent, OnWorldTransformOverrideUpdated), Z_Construct_UDelegateFunction_UVR_MovementComponent_OnWorldTransformOverrideUpdated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_OnWorldTransformOverrideUpdated_MetaData), Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_OnWorldTransformOverrideUpdated_MetaData) }; // 2273776349
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_MovementDirectionMultiplier_MetaData[] = {
		{ "Category", "VR_MovementComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* scales movement in particular world direction; set to 0 to disable movement on particular axis */" },
#endif
		{ "ModuleRelativePath", "Components/Public/VR_MovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "scales movement in particular world direction; set to 0 to disable movement on particular axis" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_MovementDirectionMultiplier = { "MovementDirectionMultiplier", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVR_MovementComponent, MovementDirectionMultiplier), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_MovementDirectionMultiplier_MetaData), Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_MovementDirectionMultiplier_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_Gravity_MetaData[] = {
		{ "Category", "VR_MovementComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* acceleration vector applied each tick;  units are UnrealUnits / second / second. */" },
#endif
		{ "ModuleRelativePath", "Components/Public/VR_MovementComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "acceleration vector applied each tick;  units are UnrealUnits / second / second." },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_Gravity = { "Gravity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVR_MovementComponent, Gravity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_Gravity_MetaData), Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_Gravity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_GroundCheckDistance_MetaData[] = {
		{ "Category", "VR_MovementComponent" },
		{ "ModuleRelativePath", "Components/Public/VR_MovementComponent.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_GroundCheckDistance = { "GroundCheckDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVR_MovementComponent, GroundCheckDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_GroundCheckDistance_MetaData), Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_GroundCheckDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_bInstantAcceleration_MetaData[] = {
		{ "Category", "VR_MovementComponent" },
		{ "ModuleRelativePath", "Components/Public/VR_MovementComponent.h" },
	};
#endif
	void Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_bInstantAcceleration_SetBit(void* Obj)
	{
		((UVR_MovementComponent*)Obj)->bInstantAcceleration = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_bInstantAcceleration = { "bInstantAcceleration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVR_MovementComponent), &Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_bInstantAcceleration_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_bInstantAcceleration_MetaData), Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_bInstantAcceleration_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_bInstantDeceleration_MetaData[] = {
		{ "Category", "VR_MovementComponent" },
		{ "ModuleRelativePath", "Components/Public/VR_MovementComponent.h" },
	};
#endif
	void Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_bInstantDeceleration_SetBit(void* Obj)
	{
		((UVR_MovementComponent*)Obj)->bInstantDeceleration = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_bInstantDeceleration = { "bInstantDeceleration", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVR_MovementComponent), &Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_bInstantDeceleration_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_bInstantDeceleration_MetaData), Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_bInstantDeceleration_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVR_MovementComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_OnWorldTransformOverrideUpdated,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_MovementDirectionMultiplier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_Gravity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_GroundCheckDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_bInstantAcceleration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MovementComponent_Statics::NewProp_bInstantDeceleration,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVR_MovementComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVR_MovementComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVR_MovementComponent_Statics::ClassParams = {
		&UVR_MovementComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVR_MovementComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MovementComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MovementComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UVR_MovementComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MovementComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVR_MovementComponent()
	{
		if (!Z_Registration_Info_UClass_UVR_MovementComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVR_MovementComponent.OuterSingleton, Z_Construct_UClass_UVR_MovementComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVR_MovementComponent.OuterSingleton;
	}
	template<> VH_VR_API UClass* StaticClass<UVR_MovementComponent>()
	{
		return UVR_MovementComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVR_MovementComponent);
	UVR_MovementComponent::~UVR_MovementComponent() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MovementComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MovementComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVR_MovementComponent, UVR_MovementComponent::StaticClass, TEXT("UVR_MovementComponent"), &Z_Registration_Info_UClass_UVR_MovementComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVR_MovementComponent), 2231588233U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MovementComponent_h_1477722564(TEXT("/Script/VH_VR"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MovementComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MovementComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
