// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VR_TraceComponent.h"
#include "../../Source/Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVR_TraceComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	UPackage* Z_Construct_UPackage__Script_VH_VR();
	VH_VR_API UClass* Z_Construct_UClass_UVR_TraceComponent();
	VH_VR_API UClass* Z_Construct_UClass_UVR_TraceComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UVR_TraceComponent::execUpdateTrace)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateTrace();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_TraceComponent::execGetHitResults)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_collisionChannel);
		P_GET_TARRAY_REF(FHitResult,Z_Param_Out_hitResults);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetHitResults(ECollisionChannel(Z_Param_collisionChannel),Z_Param_Out_hitResults);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_TraceComponent::execRemoveTraceChannel)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_collisionChannel);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveTraceChannel(ECollisionChannel(Z_Param_collisionChannel));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_TraceComponent::execAddTraceChannel)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_collisionChannel);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddTraceChannel(ECollisionChannel(Z_Param_collisionChannel));
		P_NATIVE_END;
	}
	void UVR_TraceComponent::StaticRegisterNativesUVR_TraceComponent()
	{
		UClass* Class = UVR_TraceComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddTraceChannel", &UVR_TraceComponent::execAddTraceChannel },
			{ "GetHitResults", &UVR_TraceComponent::execGetHitResults },
			{ "RemoveTraceChannel", &UVR_TraceComponent::execRemoveTraceChannel },
			{ "UpdateTrace", &UVR_TraceComponent::execUpdateTrace },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVR_TraceComponent_AddTraceChannel_Statics
	{
		struct VR_TraceComponent_eventAddTraceChannel_Parms
		{
			TEnumAsByte<ECollisionChannel> collisionChannel;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_collisionChannel;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVR_TraceComponent_AddTraceChannel_Statics::NewProp_collisionChannel = { "collisionChannel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_TraceComponent_eventAddTraceChannel_Parms, collisionChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(0, nullptr) }; // 1822723181
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_TraceComponent_AddTraceChannel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_TraceComponent_AddTraceChannel_Statics::NewProp_collisionChannel,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_TraceComponent_AddTraceChannel_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_TraceComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_TraceComponent_AddTraceChannel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_TraceComponent, nullptr, "AddTraceChannel", nullptr, nullptr, Z_Construct_UFunction_UVR_TraceComponent_AddTraceChannel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_TraceComponent_AddTraceChannel_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVR_TraceComponent_AddTraceChannel_Statics::VR_TraceComponent_eventAddTraceChannel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_TraceComponent_AddTraceChannel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_TraceComponent_AddTraceChannel_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_TraceComponent_AddTraceChannel_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVR_TraceComponent_AddTraceChannel_Statics::VR_TraceComponent_eventAddTraceChannel_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_TraceComponent_AddTraceChannel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_TraceComponent_AddTraceChannel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics
	{
		struct VR_TraceComponent_eventGetHitResults_Parms
		{
			TEnumAsByte<ECollisionChannel> collisionChannel;
			TArray<FHitResult> hitResults;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_collisionChannel;
		static const UECodeGen_Private::FStructPropertyParams NewProp_hitResults_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_hitResults;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::NewProp_collisionChannel = { "collisionChannel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_TraceComponent_eventGetHitResults_Parms, collisionChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(0, nullptr) }; // 1822723181
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::NewProp_hitResults_Inner = { "hitResults", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(0, nullptr) }; // 1891709922
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::NewProp_hitResults = { "hitResults", nullptr, (EPropertyFlags)0x0010008000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_TraceComponent_eventGetHitResults_Parms, hitResults), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1891709922
	void Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VR_TraceComponent_eventGetHitResults_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VR_TraceComponent_eventGetHitResults_Parms), &Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::NewProp_collisionChannel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::NewProp_hitResults_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::NewProp_hitResults,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_TraceComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_TraceComponent, nullptr, "GetHitResults", nullptr, nullptr, Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::VR_TraceComponent_eventGetHitResults_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::VR_TraceComponent_eventGetHitResults_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_TraceComponent_GetHitResults()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_TraceComponent_GetHitResults_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_TraceComponent_RemoveTraceChannel_Statics
	{
		struct VR_TraceComponent_eventRemoveTraceChannel_Parms
		{
			TEnumAsByte<ECollisionChannel> collisionChannel;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_collisionChannel;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVR_TraceComponent_RemoveTraceChannel_Statics::NewProp_collisionChannel = { "collisionChannel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_TraceComponent_eventRemoveTraceChannel_Parms, collisionChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(0, nullptr) }; // 1822723181
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_TraceComponent_RemoveTraceChannel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_TraceComponent_RemoveTraceChannel_Statics::NewProp_collisionChannel,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_TraceComponent_RemoveTraceChannel_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_TraceComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_TraceComponent_RemoveTraceChannel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_TraceComponent, nullptr, "RemoveTraceChannel", nullptr, nullptr, Z_Construct_UFunction_UVR_TraceComponent_RemoveTraceChannel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_TraceComponent_RemoveTraceChannel_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVR_TraceComponent_RemoveTraceChannel_Statics::VR_TraceComponent_eventRemoveTraceChannel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_TraceComponent_RemoveTraceChannel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_TraceComponent_RemoveTraceChannel_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_TraceComponent_RemoveTraceChannel_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVR_TraceComponent_RemoveTraceChannel_Statics::VR_TraceComponent_eventRemoveTraceChannel_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_TraceComponent_RemoveTraceChannel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_TraceComponent_RemoveTraceChannel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_TraceComponent_UpdateTrace_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_TraceComponent_UpdateTrace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_TraceComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_TraceComponent_UpdateTrace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_TraceComponent, nullptr, "UpdateTrace", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_TraceComponent_UpdateTrace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_TraceComponent_UpdateTrace_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UVR_TraceComponent_UpdateTrace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_TraceComponent_UpdateTrace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVR_TraceComponent);
	UClass* Z_Construct_UClass_UVR_TraceComponent_NoRegister()
	{
		return UVR_TraceComponent::StaticClass();
	}
	struct Z_Construct_UClass_UVR_TraceComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultChannelsToTrace_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultChannelsToTrace_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_DefaultChannelsToTrace;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bShouldTrace_MetaData[];
#endif
		static void NewProp_bShouldTrace_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShouldTrace;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TraceDistance_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_TraceDistance;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_IgnoredActors_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IgnoredActors_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_IgnoredActors;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDrawDebugLine_MetaData[];
#endif
		static void NewProp_bDrawDebugLine_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDrawDebugLine;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TraceCooldown_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_TraceCooldown;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVR_TraceComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USceneComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_VR,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_TraceComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVR_TraceComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVR_TraceComponent_AddTraceChannel, "AddTraceChannel" }, // 3582367961
		{ &Z_Construct_UFunction_UVR_TraceComponent_GetHitResults, "GetHitResults" }, // 92868144
		{ &Z_Construct_UFunction_UVR_TraceComponent_RemoveTraceChannel, "RemoveTraceChannel" }, // 455100177
		{ &Z_Construct_UFunction_UVR_TraceComponent_UpdateTrace, "UpdateTrace" }, // 2494501613
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_TraceComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_TraceComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "Components/Public/VR_TraceComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Components/Public/VR_TraceComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_DefaultChannelsToTrace_ElementProp = { "DefaultChannelsToTrace", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(0, nullptr) }; // 1822723181
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_DefaultChannelsToTrace_MetaData[] = {
		{ "Category", "VR_TraceComponent" },
		{ "ModuleRelativePath", "Components/Public/VR_TraceComponent.h" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_DefaultChannelsToTrace = { "DefaultChannelsToTrace", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVR_TraceComponent, DefaultChannelsToTrace), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_DefaultChannelsToTrace_MetaData), Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_DefaultChannelsToTrace_MetaData) }; // 1822723181
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_bShouldTrace_MetaData[] = {
		{ "Category", "VR_TraceComponent" },
		{ "ModuleRelativePath", "Components/Public/VR_TraceComponent.h" },
	};
#endif
	void Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_bShouldTrace_SetBit(void* Obj)
	{
		((UVR_TraceComponent*)Obj)->bShouldTrace = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_bShouldTrace = { "bShouldTrace", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVR_TraceComponent), &Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_bShouldTrace_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_bShouldTrace_MetaData), Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_bShouldTrace_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_TraceDistance_MetaData[] = {
		{ "Category", "VR_TraceComponent" },
		{ "ModuleRelativePath", "Components/Public/VR_TraceComponent.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_TraceDistance = { "TraceDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVR_TraceComponent, TraceDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_TraceDistance_MetaData), Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_TraceDistance_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_IgnoredActors_ElementProp = { "IgnoredActors", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_IgnoredActors_MetaData[] = {
		{ "Category", "VR_TraceComponent" },
		{ "ModuleRelativePath", "Components/Public/VR_TraceComponent.h" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_IgnoredActors = { "IgnoredActors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVR_TraceComponent, IgnoredActors), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_IgnoredActors_MetaData), Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_IgnoredActors_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_bDrawDebugLine_MetaData[] = {
		{ "Category", "VR_TraceComponent" },
		{ "ModuleRelativePath", "Components/Public/VR_TraceComponent.h" },
	};
#endif
	void Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_bDrawDebugLine_SetBit(void* Obj)
	{
		((UVR_TraceComponent*)Obj)->bDrawDebugLine = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_bDrawDebugLine = { "bDrawDebugLine", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVR_TraceComponent), &Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_bDrawDebugLine_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_bDrawDebugLine_MetaData), Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_bDrawDebugLine_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_TraceCooldown_MetaData[] = {
		{ "Category", "VR_TraceComponent" },
		{ "ModuleRelativePath", "Components/Public/VR_TraceComponent.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_TraceCooldown = { "TraceCooldown", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVR_TraceComponent, TraceCooldown), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_TraceCooldown_MetaData), Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_TraceCooldown_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVR_TraceComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_DefaultChannelsToTrace_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_DefaultChannelsToTrace,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_bShouldTrace,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_TraceDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_IgnoredActors_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_IgnoredActors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_bDrawDebugLine,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_TraceComponent_Statics::NewProp_TraceCooldown,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVR_TraceComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVR_TraceComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVR_TraceComponent_Statics::ClassParams = {
		&UVR_TraceComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVR_TraceComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVR_TraceComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_TraceComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UVR_TraceComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_TraceComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVR_TraceComponent()
	{
		if (!Z_Registration_Info_UClass_UVR_TraceComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVR_TraceComponent.OuterSingleton, Z_Construct_UClass_UVR_TraceComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVR_TraceComponent.OuterSingleton;
	}
	template<> VH_VR_API UClass* StaticClass<UVR_TraceComponent>()
	{
		return UVR_TraceComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVR_TraceComponent);
	UVR_TraceComponent::~UVR_TraceComponent() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVR_TraceComponent, UVR_TraceComponent::StaticClass, TEXT("UVR_TraceComponent"), &Z_Registration_Info_UClass_UVR_TraceComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVR_TraceComponent), 3806745043U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_1266104199(TEXT("/Script/VH_VR"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_TraceComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
