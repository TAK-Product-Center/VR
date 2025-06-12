// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../WheeledVehicle/Public/VH_WheeledVehicleAIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_WheeledVehicleAIController() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBlackboardData_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_USplineComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_Vehicle();
	VH_VEHICLE_API UClass* Z_Construct_UClass_AVH_VehicleAIController();
	VH_VEHICLE_API UClass* Z_Construct_UClass_AVH_WheeledVehicleAIController();
	VH_VEHICLE_API UClass* Z_Construct_UClass_AVH_WheeledVehicleAIController_NoRegister();
	VH_VEHICLE_API UEnum* Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingResult();
	VH_VEHICLE_API UEnum* Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingState();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EVehiclePathfindingState;
	static UEnum* EVehiclePathfindingState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EVehiclePathfindingState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EVehiclePathfindingState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingState, (UObject*)Z_Construct_UPackage__Script_VH_Vehicle(), TEXT("EVehiclePathfindingState"));
		}
		return Z_Registration_Info_UEnum_EVehiclePathfindingState.OuterSingleton;
	}
	template<> VH_VEHICLE_API UEnum* StaticEnum<EVehiclePathfindingState>()
	{
		return EVehiclePathfindingState_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingState_Statics::Enumerators[] = {
		{ "EVehiclePathfindingState::Inactive", (int64)EVehiclePathfindingState::Inactive },
		{ "EVehiclePathfindingState::InProgress", (int64)EVehiclePathfindingState::InProgress },
		{ "EVehiclePathfindingState::Suspended", (int64)EVehiclePathfindingState::Suspended },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Inactive.Name", "EVehiclePathfindingState::Inactive" },
		{ "InProgress.Name", "EVehiclePathfindingState::InProgress" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehicleAIController.h" },
		{ "Suspended.Name", "EVehiclePathfindingState::Suspended" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_Vehicle,
		nullptr,
		"EVehiclePathfindingState",
		"EVehiclePathfindingState",
		Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingState()
	{
		if (!Z_Registration_Info_UEnum_EVehiclePathfindingState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EVehiclePathfindingState.InnerSingleton, Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EVehiclePathfindingState.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EVehiclePathfindingResult;
	static UEnum* EVehiclePathfindingResult_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EVehiclePathfindingResult.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EVehiclePathfindingResult.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingResult, (UObject*)Z_Construct_UPackage__Script_VH_Vehicle(), TEXT("EVehiclePathfindingResult"));
		}
		return Z_Registration_Info_UEnum_EVehiclePathfindingResult.OuterSingleton;
	}
	template<> VH_VEHICLE_API UEnum* StaticEnum<EVehiclePathfindingResult>()
	{
		return EVehiclePathfindingResult_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingResult_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingResult_Statics::Enumerators[] = {
		{ "EVehiclePathfindingResult::Success", (int64)EVehiclePathfindingResult::Success },
		{ "EVehiclePathfindingResult::Aborted", (int64)EVehiclePathfindingResult::Aborted },
		{ "EVehiclePathfindingResult::Failed", (int64)EVehiclePathfindingResult::Failed },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingResult_Statics::Enum_MetaDataParams[] = {
		{ "Aborted.Name", "EVehiclePathfindingResult::Aborted" },
		{ "BlueprintType", "true" },
		{ "Failed.Name", "EVehiclePathfindingResult::Failed" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehicleAIController.h" },
		{ "Success.Name", "EVehiclePathfindingResult::Success" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingResult_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_Vehicle,
		nullptr,
		"EVehiclePathfindingResult",
		"EVehiclePathfindingResult",
		Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingResult_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingResult_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingResult_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingResult_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingResult()
	{
		if (!Z_Registration_Info_UEnum_EVehiclePathfindingResult.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EVehiclePathfindingResult.InnerSingleton, Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingResult_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EVehiclePathfindingResult.InnerSingleton;
	}
	DEFINE_FUNCTION(AVH_WheeledVehicleAIController::execFindPathInputKeyAtLocationAndDistance)
	{
		P_GET_STRUCT_REF(FVector,Z_Param_Out_worldLocation);
		P_GET_PROPERTY(FFloatProperty,Z_Param_minDistance);
		P_GET_PROPERTY(FFloatProperty,Z_Param_maxDistance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->FindPathInputKeyAtLocationAndDistance(Z_Param_Out_worldLocation,Z_Param_minDistance,Z_Param_maxDistance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehicleAIController::execSetFollowSplineFromVectorArray)
	{
		P_GET_TARRAY_REF(FVector,Z_Param_Out_inArray);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SetFollowSplineFromVectorArray(Z_Param_Out_inArray);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehicleAIController::execSetTargetLocation)
	{
		P_GET_STRUCT(FVector,Z_Param_newTargetLocation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SetTargetLocation(Z_Param_newTargetLocation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehicleAIController::execBeginMoveToTargetLocation)
	{
		P_GET_STRUCT(FVector,Z_Param_inTargetLocation);
		P_GET_PROPERTY(FFloatProperty,Z_Param_acceptanceRadius);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BeginMoveToTargetLocation(Z_Param_inTargetLocation,Z_Param_acceptanceRadius);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehicleAIController::execForcePathingComplete)
	{
		P_GET_UBOOL(Z_Param_inSuccessful);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ForcePathingComplete(Z_Param_inSuccessful);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehicleAIController::execSuspendPathing)
	{
		P_GET_UBOOL(Z_Param_inSuspendState);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SuspendPathing(Z_Param_inSuspendState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehicleAIController::execGetFollowSpline)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USplineComponent**)Z_Param__Result=P_THIS->GetFollowSpline();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehicleAIController::execGetPathingState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EVehiclePathfindingState*)Z_Param__Result=P_THIS->GetPathingState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehicleAIController::execGetPathingTargetLocation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetPathingTargetLocation();
		P_NATIVE_END;
	}
	void AVH_WheeledVehicleAIController::StaticRegisterNativesAVH_WheeledVehicleAIController()
	{
		UClass* Class = AVH_WheeledVehicleAIController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BeginMoveToTargetLocation", &AVH_WheeledVehicleAIController::execBeginMoveToTargetLocation },
			{ "FindPathInputKeyAtLocationAndDistance", &AVH_WheeledVehicleAIController::execFindPathInputKeyAtLocationAndDistance },
			{ "ForcePathingComplete", &AVH_WheeledVehicleAIController::execForcePathingComplete },
			{ "GetFollowSpline", &AVH_WheeledVehicleAIController::execGetFollowSpline },
			{ "GetPathingState", &AVH_WheeledVehicleAIController::execGetPathingState },
			{ "GetPathingTargetLocation", &AVH_WheeledVehicleAIController::execGetPathingTargetLocation },
			{ "SetFollowSplineFromVectorArray", &AVH_WheeledVehicleAIController::execSetFollowSplineFromVectorArray },
			{ "SetTargetLocation", &AVH_WheeledVehicleAIController::execSetTargetLocation },
			{ "SuspendPathing", &AVH_WheeledVehicleAIController::execSuspendPathing },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics
	{
		struct VH_WheeledVehicleAIController_eventBeginMoveToTargetLocation_Parms
		{
			FVector inTargetLocation;
			float acceptanceRadius;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_inTargetLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_inTargetLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_acceptanceRadius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_acceptanceRadius;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::NewProp_inTargetLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::NewProp_inTargetLocation = { "inTargetLocation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehicleAIController_eventBeginMoveToTargetLocation_Parms, inTargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::NewProp_inTargetLocation_MetaData), Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::NewProp_inTargetLocation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::NewProp_acceptanceRadius_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::NewProp_acceptanceRadius = { "acceptanceRadius", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehicleAIController_eventBeginMoveToTargetLocation_Parms, acceptanceRadius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::NewProp_acceptanceRadius_MetaData), Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::NewProp_acceptanceRadius_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::NewProp_inTargetLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::NewProp_acceptanceRadius,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Starts pathing for the agent */" },
#endif
		{ "CPP_Default_acceptanceRadius", "100.000000" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehicleAIController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Starts pathing for the agent" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehicleAIController, nullptr, "BeginMoveToTargetLocation", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::VH_WheeledVehicleAIController_eventBeginMoveToTargetLocation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::VH_WheeledVehicleAIController_eventBeginMoveToTargetLocation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics
	{
		struct VH_WheeledVehicleAIController_eventFindPathInputKeyAtLocationAndDistance_Parms
		{
			FVector worldLocation;
			float minDistance;
			float maxDistance;
			float ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_worldLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_worldLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_minDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_minDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_maxDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_maxDistance;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_worldLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_worldLocation = { "worldLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehicleAIController_eventFindPathInputKeyAtLocationAndDistance_Parms, worldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_worldLocation_MetaData), Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_worldLocation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_minDistance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_minDistance = { "minDistance", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehicleAIController_eventFindPathInputKeyAtLocationAndDistance_Parms, minDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_minDistance_MetaData), Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_minDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_maxDistance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_maxDistance = { "maxDistance", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehicleAIController_eventFindPathInputKeyAtLocationAndDistance_Parms, maxDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_maxDistance_MetaData), Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_maxDistance_MetaData) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehicleAIController_eventFindPathInputKeyAtLocationAndDistance_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_worldLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_minDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_maxDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns the nearest input key given a world location. No keys outside the distance bounds will be considered. */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehicleAIController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the nearest input key given a world location. No keys outside the distance bounds will be considered." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehicleAIController, nullptr, "FindPathInputKeyAtLocationAndDistance", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::VH_WheeledVehicleAIController_eventFindPathInputKeyAtLocationAndDistance_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::VH_WheeledVehicleAIController_eventFindPathInputKeyAtLocationAndDistance_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete_Statics
	{
		struct VH_WheeledVehicleAIController_eventForcePathingComplete_Parms
		{
			bool inSuccessful;
		};
		static void NewProp_inSuccessful_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_inSuccessful;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete_Statics::NewProp_inSuccessful_SetBit(void* Obj)
	{
		((VH_WheeledVehicleAIController_eventForcePathingComplete_Parms*)Obj)->inSuccessful = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete_Statics::NewProp_inSuccessful = { "inSuccessful", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_WheeledVehicleAIController_eventForcePathingComplete_Parms), &Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete_Statics::NewProp_inSuccessful_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete_Statics::NewProp_inSuccessful,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete_Statics::Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
		{ "Keywords", "Stop" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehicleAIController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehicleAIController, nullptr, "ForcePathingComplete", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete_Statics::VH_WheeledVehicleAIController_eventForcePathingComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete_Statics::VH_WheeledVehicleAIController_eventForcePathingComplete_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics
	{
		struct VH_WheeledVehicleAIController_eventGetFollowSpline_Parms
		{
			USplineComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehicleAIController_eventGetFollowSpline_Parms, ReturnValue), Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics::Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehicleAIController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehicleAIController, nullptr, "GetFollowSpline", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics::VH_WheeledVehicleAIController_eventGetFollowSpline_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics::VH_WheeledVehicleAIController_eventGetFollowSpline_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState_Statics
	{
		struct VH_WheeledVehicleAIController_eventGetPathingState_Parms
		{
			EVehiclePathfindingState ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehicleAIController_eventGetPathingState_Parms, ReturnValue), Z_Construct_UEnum_VH_Vehicle_EVehiclePathfindingState, METADATA_PARAMS(0, nullptr) }; // 4058808264
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehicleAIController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehicleAIController, nullptr, "GetPathingState", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState_Statics::VH_WheeledVehicleAIController_eventGetPathingState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState_Statics::VH_WheeledVehicleAIController_eventGetPathingState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingTargetLocation_Statics
	{
		struct VH_WheeledVehicleAIController_eventGetPathingTargetLocation_Parms
		{
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingTargetLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehicleAIController_eventGetPathingTargetLocation_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingTargetLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingTargetLocation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingTargetLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehicleAIController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingTargetLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehicleAIController, nullptr, "GetPathingTargetLocation", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingTargetLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingTargetLocation_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingTargetLocation_Statics::VH_WheeledVehicleAIController_eventGetPathingTargetLocation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingTargetLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingTargetLocation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingTargetLocation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingTargetLocation_Statics::VH_WheeledVehicleAIController_eventGetPathingTargetLocation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingTargetLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingTargetLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics
	{
		struct VH_WheeledVehicleAIController_eventSetFollowSplineFromVectorArray_Parms
		{
			TArray<FVector> inArray;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_inArray_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_inArray;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::NewProp_inArray_Inner = { "inArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::NewProp_inArray = { "inArray", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehicleAIController_eventSetFollowSplineFromVectorArray_Parms, inArray), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_WheeledVehicleAIController_eventSetFollowSplineFromVectorArray_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_WheeledVehicleAIController_eventSetFollowSplineFromVectorArray_Parms), &Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::NewProp_inArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::NewProp_inArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Supplied vector should be in world space. Fails if less than two points are provided */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehicleAIController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Supplied vector should be in world space. Fails if less than two points are provided" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehicleAIController, nullptr, "SetFollowSplineFromVectorArray", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::VH_WheeledVehicleAIController_eventSetFollowSplineFromVectorArray_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::VH_WheeledVehicleAIController_eventSetFollowSplineFromVectorArray_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics
	{
		struct VH_WheeledVehicleAIController_eventSetTargetLocation_Parms
		{
			FVector newTargetLocation;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_newTargetLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_newTargetLocation;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::NewProp_newTargetLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::NewProp_newTargetLocation = { "newTargetLocation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehicleAIController_eventSetTargetLocation_Parms, newTargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::NewProp_newTargetLocation_MetaData), Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::NewProp_newTargetLocation_MetaData) };
	void Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_WheeledVehicleAIController_eventSetTargetLocation_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_WheeledVehicleAIController_eventSetTargetLocation_Parms), &Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::NewProp_newTargetLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** A non-mutator method to update the target location. Fails if the agent is not currently pathing or in a suspended state. */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehicleAIController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A non-mutator method to update the target location. Fails if the agent is not currently pathing or in a suspended state." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehicleAIController, nullptr, "SetTargetLocation", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::VH_WheeledVehicleAIController_eventSetTargetLocation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::VH_WheeledVehicleAIController_eventSetTargetLocation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing_Statics
	{
		struct VH_WheeledVehicleAIController_eventSuspendPathing_Parms
		{
			bool inSuspendState;
		};
		static void NewProp_inSuspendState_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_inSuspendState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing_Statics::NewProp_inSuspendState_SetBit(void* Obj)
	{
		((VH_WheeledVehicleAIController_eventSuspendPathing_Parms*)Obj)->inSuspendState = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing_Statics::NewProp_inSuspendState = { "inSuspendState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_WheeledVehicleAIController_eventSuspendPathing_Parms), &Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing_Statics::NewProp_inSuspendState_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing_Statics::NewProp_inSuspendState,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing_Statics::Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehicleAIController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehicleAIController, nullptr, "SuspendPathing", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing_Statics::VH_WheeledVehicleAIController_eventSuspendPathing_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing_Statics::VH_WheeledVehicleAIController_eventSuspendPathing_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVH_WheeledVehicleAIController);
	UClass* Z_Construct_UClass_AVH_WheeledVehicleAIController_NoRegister()
	{
		return AVH_WheeledVehicleAIController::StaticClass();
	}
	struct Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BlackboardAsset_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BlackboardAsset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BehaviorTreeAsset_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BehaviorTreeAsset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SplineTangentMaxSize_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SplineTangentMaxSize;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AVH_VehicleAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Vehicle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVH_WheeledVehicleAIController_BeginMoveToTargetLocation, "BeginMoveToTargetLocation" }, // 4035771692
		{ &Z_Construct_UFunction_AVH_WheeledVehicleAIController_FindPathInputKeyAtLocationAndDistance, "FindPathInputKeyAtLocationAndDistance" }, // 391497957
		{ &Z_Construct_UFunction_AVH_WheeledVehicleAIController_ForcePathingComplete, "ForcePathingComplete" }, // 2894804047
		{ &Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetFollowSpline, "GetFollowSpline" }, // 4064587592
		{ &Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingState, "GetPathingState" }, // 2672572968
		{ &Z_Construct_UFunction_AVH_WheeledVehicleAIController_GetPathingTargetLocation, "GetPathingTargetLocation" }, // 1204678681
		{ &Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetFollowSplineFromVectorArray, "SetFollowSplineFromVectorArray" }, // 3677638857
		{ &Z_Construct_UFunction_AVH_WheeledVehicleAIController_SetTargetLocation, "SetTargetLocation" }, // 2734640099
		{ &Z_Construct_UFunction_AVH_WheeledVehicleAIController_SuspendPathing, "SuspendPathing" }, // 1449902425
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "WheeledVehicle/Public/VH_WheeledVehicleAIController.h" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehicleAIController.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::NewProp_BlackboardAsset_MetaData[] = {
		{ "Category", "AI Behavior" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehicleAIController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::NewProp_BlackboardAsset = { "BlackboardAsset", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehicleAIController, BlackboardAsset), Z_Construct_UClass_UBlackboardData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::NewProp_BlackboardAsset_MetaData), Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::NewProp_BlackboardAsset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::NewProp_BehaviorTreeAsset_MetaData[] = {
		{ "Category", "AI Behavior" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehicleAIController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::NewProp_BehaviorTreeAsset = { "BehaviorTreeAsset", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehicleAIController, BehaviorTreeAsset), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::NewProp_BehaviorTreeAsset_MetaData), Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::NewProp_BehaviorTreeAsset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::NewProp_SplineTangentMaxSize_MetaData[] = {
		{ "Category", "Pathing Behavior" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehicleAIController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::NewProp_SplineTangentMaxSize = { "SplineTangentMaxSize", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehicleAIController, SplineTangentMaxSize), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::NewProp_SplineTangentMaxSize_MetaData), Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::NewProp_SplineTangentMaxSize_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::NewProp_BlackboardAsset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::NewProp_BehaviorTreeAsset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::NewProp_SplineTangentMaxSize,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVH_WheeledVehicleAIController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::ClassParams = {
		&AVH_WheeledVehicleAIController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::Class_MetaDataParams), Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AVH_WheeledVehicleAIController()
	{
		if (!Z_Registration_Info_UClass_AVH_WheeledVehicleAIController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVH_WheeledVehicleAIController.OuterSingleton, Z_Construct_UClass_AVH_WheeledVehicleAIController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AVH_WheeledVehicleAIController.OuterSingleton;
	}
	template<> VH_VEHICLE_API UClass* StaticClass<AVH_WheeledVehicleAIController>()
	{
		return AVH_WheeledVehicleAIController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVH_WheeledVehicleAIController);
	AVH_WheeledVehicleAIController::~AVH_WheeledVehicleAIController() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_Statics::EnumInfo[] = {
		{ EVehiclePathfindingState_StaticEnum, TEXT("EVehiclePathfindingState"), &Z_Registration_Info_UEnum_EVehiclePathfindingState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4058808264U) },
		{ EVehiclePathfindingResult_StaticEnum, TEXT("EVehiclePathfindingResult"), &Z_Registration_Info_UEnum_EVehiclePathfindingResult, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 754549561U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AVH_WheeledVehicleAIController, AVH_WheeledVehicleAIController::StaticClass, TEXT("AVH_WheeledVehicleAIController"), &Z_Registration_Info_UClass_AVH_WheeledVehicleAIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVH_WheeledVehicleAIController), 448474073U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_1935827188(TEXT("/Script/VH_Vehicle"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehicleAIController_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
