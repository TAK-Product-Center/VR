// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_VehicleAsyncMoveTo.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_VehicleAsyncMoveTo() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_AAIController_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ENavigationQueryResult();
	NAVIGATIONSYSTEM_API UClass* Z_Construct_UClass_UNavigationQueryFilter_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_Vehicle();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UVH_VehicleAsyncMoveTo();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UVH_VehicleAsyncMoveTo_NoRegister();
	VH_VEHICLE_API UFunction* Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature_Statics
	{
		struct _Script_VH_Vehicle_eventAsyncPathFindComplete_Parms
		{
			TEnumAsByte<ENavigationQueryResult::Type> Result;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VH_Vehicle_eventAsyncPathFindComplete_Parms, Result), Z_Construct_UEnum_Engine_ENavigationQueryResult, METADATA_PARAMS(0, nullptr) }; // 1131878593
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature_Statics::NewProp_Result,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Delegates\n// ---------------------------------\n" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehicleAsyncMoveTo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Delegates" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_VH_Vehicle, nullptr, "AsyncPathFindComplete__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature_Statics::_Script_VH_Vehicle_eventAsyncPathFindComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature_Statics::_Script_VH_Vehicle_eventAsyncPathFindComplete_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FAsyncPathFindComplete_DelegateWrapper(const FMulticastScriptDelegate& AsyncPathFindComplete, ENavigationQueryResult::Type Result)
{
	struct _Script_VH_Vehicle_eventAsyncPathFindComplete_Parms
	{
		TEnumAsByte<ENavigationQueryResult::Type> Result;
	};
	_Script_VH_Vehicle_eventAsyncPathFindComplete_Parms Parms;
	Parms.Result=Result;
	AsyncPathFindComplete.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UVH_VehicleAsyncMoveTo::execAsyncMoveTo)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_OBJECT(AAIController,Z_Param_Controller);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Dest);
		P_GET_PROPERTY(FFloatProperty,Z_Param_AcceptanceRadius);
		P_GET_UBOOL(Z_Param_bStopOnOverlap);
		P_GET_UBOOL(Z_Param_bUsePathfinding);
		P_GET_UBOOL(Z_Param_bProjectDestinationToNavigation);
		P_GET_UBOOL(Z_Param_bCanStrafe);
		P_GET_OBJECT(UClass,Z_Param_FilterClass);
		P_GET_UBOOL(Z_Param_bAllowPartialPath);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UVH_VehicleAsyncMoveTo**)Z_Param__Result=UVH_VehicleAsyncMoveTo::AsyncMoveTo(Z_Param_WorldContextObject,Z_Param_Controller,Z_Param_Out_Dest,Z_Param_AcceptanceRadius,Z_Param_bStopOnOverlap,Z_Param_bUsePathfinding,Z_Param_bProjectDestinationToNavigation,Z_Param_bCanStrafe,Z_Param_FilterClass,Z_Param_bAllowPartialPath);
		P_NATIVE_END;
	}
	void UVH_VehicleAsyncMoveTo::StaticRegisterNativesUVH_VehicleAsyncMoveTo()
	{
		UClass* Class = UVH_VehicleAsyncMoveTo::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AsyncMoveTo", &UVH_VehicleAsyncMoveTo::execAsyncMoveTo },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics
	{
		struct VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms
		{
			const UObject* WorldContextObject;
			AAIController* Controller;
			FVector Dest;
			float AcceptanceRadius;
			bool bStopOnOverlap;
			bool bUsePathfinding;
			bool bProjectDestinationToNavigation;
			bool bCanStrafe;
			TSubclassOf<UNavigationQueryFilter>  FilterClass;
			bool bAllowPartialPath;
			UVH_VehicleAsyncMoveTo* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Controller;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Dest_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Dest;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AcceptanceRadius;
		static void NewProp_bStopOnOverlap_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bStopOnOverlap;
		static void NewProp_bUsePathfinding_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUsePathfinding;
		static void NewProp_bProjectDestinationToNavigation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bProjectDestinationToNavigation;
		static void NewProp_bCanStrafe_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanStrafe;
		static const UECodeGen_Private::FClassPropertyParams NewProp_FilterClass;
		static void NewProp_bAllowPartialPath_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowPartialPath;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_WorldContextObject_MetaData), Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_WorldContextObject_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_Controller = { "Controller", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms, Controller), Z_Construct_UClass_AAIController_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_Dest_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_Dest = { "Dest", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms, Dest), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_Dest_MetaData), Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_Dest_MetaData) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_AcceptanceRadius = { "AcceptanceRadius", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms, AcceptanceRadius), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bStopOnOverlap_SetBit(void* Obj)
	{
		((VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms*)Obj)->bStopOnOverlap = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bStopOnOverlap = { "bStopOnOverlap", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms), &Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bStopOnOverlap_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bUsePathfinding_SetBit(void* Obj)
	{
		((VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms*)Obj)->bUsePathfinding = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bUsePathfinding = { "bUsePathfinding", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms), &Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bUsePathfinding_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bProjectDestinationToNavigation_SetBit(void* Obj)
	{
		((VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms*)Obj)->bProjectDestinationToNavigation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bProjectDestinationToNavigation = { "bProjectDestinationToNavigation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms), &Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bProjectDestinationToNavigation_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bCanStrafe_SetBit(void* Obj)
	{
		((VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms*)Obj)->bCanStrafe = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bCanStrafe = { "bCanStrafe", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms), &Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bCanStrafe_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_FilterClass = { "FilterClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms, FilterClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UNavigationQueryFilter_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bAllowPartialPath_SetBit(void* Obj)
	{
		((VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms*)Obj)->bAllowPartialPath = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bAllowPartialPath = { "bAllowPartialPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms), &Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bAllowPartialPath_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms, ReturnValue), Z_Construct_UClass_UVH_VehicleAsyncMoveTo_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_Controller,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_Dest,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_AcceptanceRadius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bStopOnOverlap,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bUsePathfinding,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bProjectDestinationToNavigation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bCanStrafe,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_FilterClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_bAllowPartialPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Using the Async Pathfinder to find a path, this works with all AI and not just vehicles and can greatly help performance especially for complicated paths that need updating regularly.\n\x09This is also experimental and some crashes have been reported, so test it in your own project to ensure robustness before deploying. */" },
#endif
		{ "CPP_Default_AcceptanceRadius", "-1.000000" },
		{ "CPP_Default_bAllowPartialPath", "true" },
		{ "CPP_Default_bCanStrafe", "true" },
		{ "CPP_Default_bProjectDestinationToNavigation", "false" },
		{ "CPP_Default_bStopOnOverlap", "true" },
		{ "CPP_Default_bUsePathfinding", "true" },
		{ "CPP_Default_FilterClass", "None" },
		{ "DisplayName", "Vehicle AI Move To" },
		{ "ModuleRelativePath", "AI/Public/VH_VehicleAsyncMoveTo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Using the Async Pathfinder to find a path, this works with all AI and not just vehicles and can greatly help performance especially for complicated paths that need updating regularly.\n      This is also experimental and some crashes have been reported, so test it in your own project to ensure robustness before deploying." },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehicleAsyncMoveTo, nullptr, "AsyncMoveTo", nullptr, nullptr, Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C42401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::VH_VehicleAsyncMoveTo_eventAsyncMoveTo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_VehicleAsyncMoveTo);
	UClass* Z_Construct_UClass_UVH_VehicleAsyncMoveTo_NoRegister()
	{
		return UVH_VehicleAsyncMoveTo::StaticClass();
	}
	struct Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CompletedPathCreation_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_CompletedPathCreation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Vehicle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVH_VehicleAsyncMoveTo_AsyncMoveTo, "AsyncMoveTo" }, // 3233323207
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Finds a path for an AI agent asynchronously\n */" },
#endif
		{ "IncludePath", "AI/Public/VH_VehicleAsyncMoveTo.h" },
		{ "ModuleRelativePath", "AI/Public/VH_VehicleAsyncMoveTo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Finds a path for an AI agent asynchronously" },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::NewProp_CompletedPathCreation_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Called to blueprints when the pathfinding request has completed */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehicleAsyncMoveTo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called to blueprints when the pathfinding request has completed" },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::NewProp_CompletedPathCreation = { "CompletedPathCreation", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehicleAsyncMoveTo, CompletedPathCreation), Z_Construct_UDelegateFunction_VH_Vehicle_AsyncPathFindComplete__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::NewProp_CompletedPathCreation_MetaData), Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::NewProp_CompletedPathCreation_MetaData) }; // 3261125246
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::NewProp_CompletedPathCreation,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_VehicleAsyncMoveTo>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::ClassParams = {
		&UVH_VehicleAsyncMoveTo::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVH_VehicleAsyncMoveTo()
	{
		if (!Z_Registration_Info_UClass_UVH_VehicleAsyncMoveTo.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_VehicleAsyncMoveTo.OuterSingleton, Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_VehicleAsyncMoveTo.OuterSingleton;
	}
	template<> VH_VEHICLE_API UClass* StaticClass<UVH_VehicleAsyncMoveTo>()
	{
		return UVH_VehicleAsyncMoveTo::StaticClass();
	}
	UVH_VehicleAsyncMoveTo::UVH_VehicleAsyncMoveTo(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_VehicleAsyncMoveTo);
	UVH_VehicleAsyncMoveTo::~UVH_VehicleAsyncMoveTo() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_VehicleAsyncMoveTo, UVH_VehicleAsyncMoveTo::StaticClass, TEXT("UVH_VehicleAsyncMoveTo"), &Z_Registration_Info_UClass_UVH_VehicleAsyncMoveTo, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_VehicleAsyncMoveTo), 3199367401U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_2266742209(TEXT("/Script/VH_Vehicle"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
