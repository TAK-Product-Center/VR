// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Subsystems/Public/Developer_Subsystem_Manipulation.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_Subsystem_Manipulation() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_ManipulationComponent_NoRegister();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_Manipulation();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UDeveloper_Subsystem_Manipulation::execSetScaleInWorldSpace)
	{
		P_GET_TSET_REF(AActor*,Z_Param_Out_actors);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_scale);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetScaleInWorldSpace(Z_Param_Out_actors,Z_Param_Out_scale);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Manipulation::execAddScaleInLocalSpace)
	{
		P_GET_TSET_REF(AActor*,Z_Param_Out_actors);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_scale);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddScaleInLocalSpace(Z_Param_Out_actors,Z_Param_Out_scale);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Manipulation::execAddScaleInWorldSpace)
	{
		P_GET_TSET_REF(AActor*,Z_Param_Out_actors);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_scale);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddScaleInWorldSpace(Z_Param_Out_actors,Z_Param_Out_scale);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Manipulation::execSetRotationInTransformSpace)
	{
		P_GET_TSET_REF(AActor*,Z_Param_Out_actors);
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_rotation);
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetRotationInTransformSpace(Z_Param_Out_actors,Z_Param_Out_rotation,Z_Param_Out_transform);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Manipulation::execSetRotationInWorldSpace)
	{
		P_GET_TSET_REF(AActor*,Z_Param_Out_actors);
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_rotation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetRotationInWorldSpace(Z_Param_Out_actors,Z_Param_Out_rotation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Manipulation::execAddRotationInTransformSpace)
	{
		P_GET_TSET_REF(AActor*,Z_Param_Out_actors);
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_rotation);
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddRotationInTransformSpace(Z_Param_Out_actors,Z_Param_Out_rotation,Z_Param_Out_transform);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Manipulation::execAddRotationInLocalSpace)
	{
		P_GET_TSET_REF(AActor*,Z_Param_Out_actors);
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_rotation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddRotationInLocalSpace(Z_Param_Out_actors,Z_Param_Out_rotation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Manipulation::execAddRotationInWorldSpace)
	{
		P_GET_TSET_REF(AActor*,Z_Param_Out_actors);
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_rotation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddRotationInWorldSpace(Z_Param_Out_actors,Z_Param_Out_rotation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Manipulation::execSetLocationInTransformSpace)
	{
		P_GET_TSET_REF(AActor*,Z_Param_Out_actors);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_location);
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLocationInTransformSpace(Z_Param_Out_actors,Z_Param_Out_location,Z_Param_Out_transform);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Manipulation::execSetLocationInWorldSpace)
	{
		P_GET_TSET_REF(AActor*,Z_Param_Out_actors);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_location);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLocationInWorldSpace(Z_Param_Out_actors,Z_Param_Out_location);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Manipulation::execAddOffsetInTransformSpace)
	{
		P_GET_TSET_REF(AActor*,Z_Param_Out_actors);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_offset);
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddOffsetInTransformSpace(Z_Param_Out_actors,Z_Param_Out_offset,Z_Param_Out_transform);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Manipulation::execAddOffsetInLocalSpace)
	{
		P_GET_TSET_REF(AActor*,Z_Param_Out_actors);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_offset);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddOffsetInLocalSpace(Z_Param_Out_actors,Z_Param_Out_offset);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Manipulation::execAddOffsetInWorldSpace)
	{
		P_GET_TSET_REF(AActor*,Z_Param_Out_actors);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_offset);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddOffsetInWorldSpace(Z_Param_Out_actors,Z_Param_Out_offset);
		P_NATIVE_END;
	}
	void UDeveloper_Subsystem_Manipulation::StaticRegisterNativesUDeveloper_Subsystem_Manipulation()
	{
		UClass* Class = UDeveloper_Subsystem_Manipulation::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddOffsetInLocalSpace", &UDeveloper_Subsystem_Manipulation::execAddOffsetInLocalSpace },
			{ "AddOffsetInTransformSpace", &UDeveloper_Subsystem_Manipulation::execAddOffsetInTransformSpace },
			{ "AddOffsetInWorldSpace", &UDeveloper_Subsystem_Manipulation::execAddOffsetInWorldSpace },
			{ "AddRotationInLocalSpace", &UDeveloper_Subsystem_Manipulation::execAddRotationInLocalSpace },
			{ "AddRotationInTransformSpace", &UDeveloper_Subsystem_Manipulation::execAddRotationInTransformSpace },
			{ "AddRotationInWorldSpace", &UDeveloper_Subsystem_Manipulation::execAddRotationInWorldSpace },
			{ "AddScaleInLocalSpace", &UDeveloper_Subsystem_Manipulation::execAddScaleInLocalSpace },
			{ "AddScaleInWorldSpace", &UDeveloper_Subsystem_Manipulation::execAddScaleInWorldSpace },
			{ "SetLocationInTransformSpace", &UDeveloper_Subsystem_Manipulation::execSetLocationInTransformSpace },
			{ "SetLocationInWorldSpace", &UDeveloper_Subsystem_Manipulation::execSetLocationInWorldSpace },
			{ "SetRotationInTransformSpace", &UDeveloper_Subsystem_Manipulation::execSetRotationInTransformSpace },
			{ "SetRotationInWorldSpace", &UDeveloper_Subsystem_Manipulation::execSetRotationInWorldSpace },
			{ "SetScaleInWorldSpace", &UDeveloper_Subsystem_Manipulation::execSetScaleInWorldSpace },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics
	{
		struct Developer_Subsystem_Manipulation_eventAddOffsetInLocalSpace_Parms
		{
			TSet<AActor*> actors;
			FVector offset;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actors_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_actors_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_actors;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_offset_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_offset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::NewProp_actors_ElementProp = { "actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::NewProp_actors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::NewProp_actors = { "actors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddOffsetInLocalSpace_Parms, actors), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::NewProp_actors_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::NewProp_actors_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::NewProp_offset_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::NewProp_offset = { "offset", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddOffsetInLocalSpace_Parms, offset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::NewProp_offset_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::NewProp_offset_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::NewProp_actors_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::NewProp_actors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::NewProp_offset,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Manipulation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Manipulation, nullptr, "AddOffsetInLocalSpace", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::Developer_Subsystem_Manipulation_eventAddOffsetInLocalSpace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::Developer_Subsystem_Manipulation_eventAddOffsetInLocalSpace_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics
	{
		struct Developer_Subsystem_Manipulation_eventAddOffsetInTransformSpace_Parms
		{
			TSet<AActor*> actors;
			FVector offset;
			FTransform transform;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actors_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_actors_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_actors;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_offset_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_offset;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_actors_ElementProp = { "actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_actors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_actors = { "actors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddOffsetInTransformSpace_Parms, actors), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_actors_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_actors_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_offset_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_offset = { "offset", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddOffsetInTransformSpace_Parms, offset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_offset_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_offset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_transform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_transform = { "transform", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddOffsetInTransformSpace_Parms, transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_transform_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_transform_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_actors_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_actors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_offset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::NewProp_transform,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Manipulation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Manipulation, nullptr, "AddOffsetInTransformSpace", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::Developer_Subsystem_Manipulation_eventAddOffsetInTransformSpace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::Developer_Subsystem_Manipulation_eventAddOffsetInTransformSpace_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics
	{
		struct Developer_Subsystem_Manipulation_eventAddOffsetInWorldSpace_Parms
		{
			TSet<AActor*> actors;
			FVector offset;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actors_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_actors_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_actors;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_offset_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_offset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::NewProp_actors_ElementProp = { "actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::NewProp_actors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::NewProp_actors = { "actors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddOffsetInWorldSpace_Parms, actors), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::NewProp_actors_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::NewProp_actors_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::NewProp_offset_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::NewProp_offset = { "offset", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddOffsetInWorldSpace_Parms, offset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::NewProp_offset_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::NewProp_offset_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::NewProp_actors_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::NewProp_actors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::NewProp_offset,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Manipulation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Manipulation, nullptr, "AddOffsetInWorldSpace", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::Developer_Subsystem_Manipulation_eventAddOffsetInWorldSpace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::Developer_Subsystem_Manipulation_eventAddOffsetInWorldSpace_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics
	{
		struct Developer_Subsystem_Manipulation_eventAddRotationInLocalSpace_Parms
		{
			TSet<AActor*> actors;
			FRotator rotation;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actors_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_actors_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_actors;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::NewProp_actors_ElementProp = { "actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::NewProp_actors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::NewProp_actors = { "actors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddRotationInLocalSpace_Parms, actors), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::NewProp_actors_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::NewProp_actors_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::NewProp_rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::NewProp_rotation = { "rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddRotationInLocalSpace_Parms, rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::NewProp_rotation_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::NewProp_rotation_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::NewProp_actors_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::NewProp_actors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::NewProp_rotation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Manipulation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Manipulation, nullptr, "AddRotationInLocalSpace", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::Developer_Subsystem_Manipulation_eventAddRotationInLocalSpace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::Developer_Subsystem_Manipulation_eventAddRotationInLocalSpace_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics
	{
		struct Developer_Subsystem_Manipulation_eventAddRotationInTransformSpace_Parms
		{
			TSet<AActor*> actors;
			FRotator rotation;
			FTransform transform;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actors_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_actors_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_actors;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_rotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_rotation;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_actors_ElementProp = { "actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_actors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_actors = { "actors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddRotationInTransformSpace_Parms, actors), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_actors_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_actors_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_rotation = { "rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddRotationInTransformSpace_Parms, rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_rotation_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_rotation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_transform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_transform = { "transform", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddRotationInTransformSpace_Parms, transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_transform_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_transform_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_actors_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_actors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_rotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::NewProp_transform,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Manipulation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Manipulation, nullptr, "AddRotationInTransformSpace", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::Developer_Subsystem_Manipulation_eventAddRotationInTransformSpace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::Developer_Subsystem_Manipulation_eventAddRotationInTransformSpace_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics
	{
		struct Developer_Subsystem_Manipulation_eventAddRotationInWorldSpace_Parms
		{
			TSet<AActor*> actors;
			FRotator rotation;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actors_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_actors_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_actors;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::NewProp_actors_ElementProp = { "actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::NewProp_actors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::NewProp_actors = { "actors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddRotationInWorldSpace_Parms, actors), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::NewProp_actors_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::NewProp_actors_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::NewProp_rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::NewProp_rotation = { "rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddRotationInWorldSpace_Parms, rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::NewProp_rotation_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::NewProp_rotation_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::NewProp_actors_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::NewProp_actors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::NewProp_rotation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Manipulation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Manipulation, nullptr, "AddRotationInWorldSpace", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::Developer_Subsystem_Manipulation_eventAddRotationInWorldSpace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::Developer_Subsystem_Manipulation_eventAddRotationInWorldSpace_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics
	{
		struct Developer_Subsystem_Manipulation_eventAddScaleInLocalSpace_Parms
		{
			TSet<AActor*> actors;
			FVector scale;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actors_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_actors_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_actors;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::NewProp_actors_ElementProp = { "actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::NewProp_actors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::NewProp_actors = { "actors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddScaleInLocalSpace_Parms, actors), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::NewProp_actors_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::NewProp_actors_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::NewProp_scale_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::NewProp_scale = { "scale", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddScaleInLocalSpace_Parms, scale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::NewProp_scale_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::NewProp_scale_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::NewProp_actors_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::NewProp_actors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::NewProp_scale,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Manipulation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Manipulation, nullptr, "AddScaleInLocalSpace", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::Developer_Subsystem_Manipulation_eventAddScaleInLocalSpace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::Developer_Subsystem_Manipulation_eventAddScaleInLocalSpace_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics
	{
		struct Developer_Subsystem_Manipulation_eventAddScaleInWorldSpace_Parms
		{
			TSet<AActor*> actors;
			FVector scale;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actors_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_actors_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_actors;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::NewProp_actors_ElementProp = { "actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::NewProp_actors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::NewProp_actors = { "actors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddScaleInWorldSpace_Parms, actors), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::NewProp_actors_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::NewProp_actors_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::NewProp_scale_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::NewProp_scale = { "scale", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventAddScaleInWorldSpace_Parms, scale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::NewProp_scale_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::NewProp_scale_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::NewProp_actors_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::NewProp_actors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::NewProp_scale,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Manipulation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Manipulation, nullptr, "AddScaleInWorldSpace", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::Developer_Subsystem_Manipulation_eventAddScaleInWorldSpace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::Developer_Subsystem_Manipulation_eventAddScaleInWorldSpace_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics
	{
		struct Developer_Subsystem_Manipulation_eventSetLocationInTransformSpace_Parms
		{
			TSet<AActor*> actors;
			FVector location;
			FTransform transform;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actors_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_actors_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_actors;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_location;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_actors_ElementProp = { "actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_actors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_actors = { "actors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventSetLocationInTransformSpace_Parms, actors), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_actors_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_actors_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_location = { "location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventSetLocationInTransformSpace_Parms, location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_location_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_location_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_transform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_transform = { "transform", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventSetLocationInTransformSpace_Parms, transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_transform_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_transform_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_actors_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_actors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::NewProp_transform,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Manipulation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Manipulation, nullptr, "SetLocationInTransformSpace", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::Developer_Subsystem_Manipulation_eventSetLocationInTransformSpace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::Developer_Subsystem_Manipulation_eventSetLocationInTransformSpace_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics
	{
		struct Developer_Subsystem_Manipulation_eventSetLocationInWorldSpace_Parms
		{
			TSet<AActor*> actors;
			FVector location;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actors_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_actors_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_actors;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::NewProp_actors_ElementProp = { "actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::NewProp_actors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::NewProp_actors = { "actors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventSetLocationInWorldSpace_Parms, actors), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::NewProp_actors_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::NewProp_actors_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::NewProp_location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::NewProp_location = { "location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventSetLocationInWorldSpace_Parms, location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::NewProp_location_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::NewProp_location_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::NewProp_actors_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::NewProp_actors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::NewProp_location,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Manipulation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Manipulation, nullptr, "SetLocationInWorldSpace", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::Developer_Subsystem_Manipulation_eventSetLocationInWorldSpace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::Developer_Subsystem_Manipulation_eventSetLocationInWorldSpace_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics
	{
		struct Developer_Subsystem_Manipulation_eventSetRotationInTransformSpace_Parms
		{
			TSet<AActor*> actors;
			FRotator rotation;
			FTransform transform;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actors_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_actors_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_actors;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_rotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_rotation;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_actors_ElementProp = { "actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_actors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_actors = { "actors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventSetRotationInTransformSpace_Parms, actors), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_actors_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_actors_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_rotation = { "rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventSetRotationInTransformSpace_Parms, rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_rotation_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_rotation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_transform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_transform = { "transform", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventSetRotationInTransformSpace_Parms, transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_transform_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_transform_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_actors_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_actors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_rotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::NewProp_transform,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Manipulation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Manipulation, nullptr, "SetRotationInTransformSpace", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::Developer_Subsystem_Manipulation_eventSetRotationInTransformSpace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::Developer_Subsystem_Manipulation_eventSetRotationInTransformSpace_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics
	{
		struct Developer_Subsystem_Manipulation_eventSetRotationInWorldSpace_Parms
		{
			TSet<AActor*> actors;
			FRotator rotation;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actors_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_actors_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_actors;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::NewProp_actors_ElementProp = { "actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::NewProp_actors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::NewProp_actors = { "actors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventSetRotationInWorldSpace_Parms, actors), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::NewProp_actors_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::NewProp_actors_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::NewProp_rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::NewProp_rotation = { "rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventSetRotationInWorldSpace_Parms, rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::NewProp_rotation_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::NewProp_rotation_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::NewProp_actors_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::NewProp_actors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::NewProp_rotation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Manipulation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Manipulation, nullptr, "SetRotationInWorldSpace", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::Developer_Subsystem_Manipulation_eventSetRotationInWorldSpace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::Developer_Subsystem_Manipulation_eventSetRotationInWorldSpace_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics
	{
		struct Developer_Subsystem_Manipulation_eventSetScaleInWorldSpace_Parms
		{
			TSet<AActor*> actors;
			FVector scale;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actors_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_actors_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_actors;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::NewProp_actors_ElementProp = { "actors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::NewProp_actors_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::NewProp_actors = { "actors", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventSetScaleInWorldSpace_Parms, actors), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::NewProp_actors_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::NewProp_actors_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::NewProp_scale_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::NewProp_scale = { "scale", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Manipulation_eventSetScaleInWorldSpace_Parms, scale), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::NewProp_scale_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::NewProp_scale_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::NewProp_actors_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::NewProp_actors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::NewProp_scale,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Manipulation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Manipulation, nullptr, "SetScaleInWorldSpace", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::Developer_Subsystem_Manipulation_eventSetScaleInWorldSpace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::Developer_Subsystem_Manipulation_eventSetScaleInWorldSpace_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_Subsystem_Manipulation);
	UClass* Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_NoRegister()
	{
		return UDeveloper_Subsystem_Manipulation::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ManipulationComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ManipulationComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInLocalSpace, "AddOffsetInLocalSpace" }, // 3450951563
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInTransformSpace, "AddOffsetInTransformSpace" }, // 1310516396
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddOffsetInWorldSpace, "AddOffsetInWorldSpace" }, // 1168884771
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInLocalSpace, "AddRotationInLocalSpace" }, // 2327716964
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInTransformSpace, "AddRotationInTransformSpace" }, // 3290804761
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddRotationInWorldSpace, "AddRotationInWorldSpace" }, // 1410268388
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInLocalSpace, "AddScaleInLocalSpace" }, // 393017107
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_AddScaleInWorldSpace, "AddScaleInWorldSpace" }, // 1260340696
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInTransformSpace, "SetLocationInTransformSpace" }, // 1769664898
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetLocationInWorldSpace, "SetLocationInWorldSpace" }, // 1391719181
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInTransformSpace, "SetRotationInTransformSpace" }, // 1628091568
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetRotationInWorldSpace, "SetRotationInWorldSpace" }, // 349296441
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Manipulation_SetScaleInWorldSpace, "SetScaleInWorldSpace" }, // 2689806617
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Subsystems/Public/Developer_Subsystem_Manipulation.h" },
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Manipulation.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::NewProp_ManipulationComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Manipulation.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::NewProp_ManipulationComponent = { "ManipulationComponent", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_Subsystem_Manipulation, ManipulationComponent), Z_Construct_UClass_UDeveloper_ManipulationComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::NewProp_ManipulationComponent_MetaData), Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::NewProp_ManipulationComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::NewProp_ManipulationComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_Subsystem_Manipulation>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::ClassParams = {
		&UDeveloper_Subsystem_Manipulation::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDeveloper_Subsystem_Manipulation()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_Subsystem_Manipulation.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_Subsystem_Manipulation.OuterSingleton, Z_Construct_UClass_UDeveloper_Subsystem_Manipulation_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_Subsystem_Manipulation.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_Subsystem_Manipulation>()
	{
		return UDeveloper_Subsystem_Manipulation::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_Subsystem_Manipulation);
	UDeveloper_Subsystem_Manipulation::~UDeveloper_Subsystem_Manipulation() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Manipulation_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Manipulation_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_Subsystem_Manipulation, UDeveloper_Subsystem_Manipulation::StaticClass, TEXT("UDeveloper_Subsystem_Manipulation"), &Z_Registration_Info_UClass_UDeveloper_Subsystem_Manipulation, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_Subsystem_Manipulation), 1283103408U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Manipulation_h_1788306105(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Manipulation_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Manipulation_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
