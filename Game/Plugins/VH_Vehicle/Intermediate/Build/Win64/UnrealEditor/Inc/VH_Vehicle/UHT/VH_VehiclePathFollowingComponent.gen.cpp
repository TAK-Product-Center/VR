// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_VehiclePathFollowingComponent.h"
#include "../../WheeledVehicle/Public/VH_PIDController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_VehiclePathFollowingComponent() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UCrowdFollowingComponent();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_Vehicle();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UVH_VehiclePathFollowingComponent();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UVH_VehiclePathFollowingComponent_NoRegister();
	VH_VEHICLE_API UEnum* Z_Construct_UEnum_VH_Vehicle_E_CrowdSimulationState();
	VH_VEHICLE_API UEnum* Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed();
	VH_VEHICLE_API UScriptStruct* Z_Construct_UScriptStruct_FPIDCoefficients();
	VH_VEHICLE_API UScriptStruct* Z_Construct_UScriptStruct_FVehicleHandlingConfig();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_VehicleHandlingConfig;
class UScriptStruct* FVehicleHandlingConfig::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_VehicleHandlingConfig.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_VehicleHandlingConfig.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FVehicleHandlingConfig, (UObject*)Z_Construct_UPackage__Script_VH_Vehicle(), TEXT("VehicleHandlingConfig"));
	}
	return Z_Registration_Info_UScriptStruct_VehicleHandlingConfig.OuterSingleton;
}
template<> VH_VEHICLE_API UScriptStruct* StaticStruct<FVehicleHandlingConfig>()
{
	return FVehicleHandlingConfig::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MinThrottle_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MinThrottle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DesiredSpeedThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DesiredSpeedThreshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThrottlePIDConfig_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ThrottlePIDConfig;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseBrakes_MetaData[];
#endif
		static void NewProp_bUseBrakes_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseBrakes;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BrakeThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_BrakeThreshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BrakeAmount_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_BrakeAmount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableSlowdown_MetaData[];
#endif
		static void NewProp_bEnableSlowdown_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableSlowdown;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlowdownDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SlowdownDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CornerSlowdownSamples_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_CornerSlowdownSamples;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxCornerSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxCornerSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SteeringPIDConfig_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SteeringPIDConfig;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Defines a set of properties that changes how this vehicle handles */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Defines a set of properties that changes how this vehicle handles" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FVehicleHandlingConfig>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_MinThrottle_MetaData[] = {
		{ "Category", "Speed Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/////// Speed Control //////////\n" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "/ Speed Control /" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_MinThrottle = { "MinThrottle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVehicleHandlingConfig, MinThrottle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_MinThrottle_MetaData), Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_MinThrottle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_DesiredSpeedThreshold_MetaData[] = {
		{ "Category", "Speed Control" },
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_DesiredSpeedThreshold = { "DesiredSpeedThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVehicleHandlingConfig, DesiredSpeedThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_DesiredSpeedThreshold_MetaData), Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_DesiredSpeedThreshold_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_ThrottlePIDConfig_MetaData[] = {
		{ "Category", "Speed Control" },
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_ThrottlePIDConfig = { "ThrottlePIDConfig", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVehicleHandlingConfig, ThrottlePIDConfig), Z_Construct_UScriptStruct_FPIDCoefficients, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_ThrottlePIDConfig_MetaData), Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_ThrottlePIDConfig_MetaData) }; // 374115500
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_bUseBrakes_MetaData[] = {
		{ "Category", "Speed Control" },
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_bUseBrakes_SetBit(void* Obj)
	{
		((FVehicleHandlingConfig*)Obj)->bUseBrakes = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_bUseBrakes = { "bUseBrakes", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FVehicleHandlingConfig), &Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_bUseBrakes_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_bUseBrakes_MetaData), Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_bUseBrakes_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_BrakeThreshold_MetaData[] = {
		{ "Category", "Speed Control" },
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_BrakeThreshold = { "BrakeThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVehicleHandlingConfig, BrakeThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_BrakeThreshold_MetaData), Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_BrakeThreshold_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_BrakeAmount_MetaData[] = {
		{ "Category", "Speed Control" },
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_BrakeAmount = { "BrakeAmount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVehicleHandlingConfig, BrakeAmount), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_BrakeAmount_MetaData), Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_BrakeAmount_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_bEnableSlowdown_MetaData[] = {
		{ "Category", "Speed Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/////// Slowdown //////////\n" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "/ Slowdown /" },
#endif
	};
#endif
	void Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_bEnableSlowdown_SetBit(void* Obj)
	{
		((FVehicleHandlingConfig*)Obj)->bEnableSlowdown = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_bEnableSlowdown = { "bEnableSlowdown", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FVehicleHandlingConfig), &Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_bEnableSlowdown_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_bEnableSlowdown_MetaData), Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_bEnableSlowdown_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_SlowdownDistance_MetaData[] = {
		{ "Category", "Speed Control" },
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_SlowdownDistance = { "SlowdownDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVehicleHandlingConfig, SlowdownDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_SlowdownDistance_MetaData), Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_SlowdownDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_CornerSlowdownSamples_MetaData[] = {
		{ "Category", "Speed Control" },
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_CornerSlowdownSamples = { "CornerSlowdownSamples", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVehicleHandlingConfig, CornerSlowdownSamples), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_CornerSlowdownSamples_MetaData), Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_CornerSlowdownSamples_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_MaxCornerSpeed_MetaData[] = {
		{ "Category", "Speed Control" },
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_MaxCornerSpeed = { "MaxCornerSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVehicleHandlingConfig, MaxCornerSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_MaxCornerSpeed_MetaData), Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_MaxCornerSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_SteeringPIDConfig_MetaData[] = {
		{ "Category", "Steering Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/////// Steering Control //////////\n" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "/ Steering Control /" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_SteeringPIDConfig = { "SteeringPIDConfig", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FVehicleHandlingConfig, SteeringPIDConfig), Z_Construct_UScriptStruct_FPIDCoefficients, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_SteeringPIDConfig_MetaData), Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_SteeringPIDConfig_MetaData) }; // 374115500
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_MinThrottle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_DesiredSpeedThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_ThrottlePIDConfig,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_bUseBrakes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_BrakeThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_BrakeAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_bEnableSlowdown,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_SlowdownDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_CornerSlowdownSamples,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_MaxCornerSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewProp_SteeringPIDConfig,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Vehicle,
		nullptr,
		&NewStructOps,
		"VehicleHandlingConfig",
		Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::PropPointers),
		sizeof(FVehicleHandlingConfig),
		alignof(FVehicleHandlingConfig),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FVehicleHandlingConfig()
	{
		if (!Z_Registration_Info_UScriptStruct_VehicleHandlingConfig.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_VehicleHandlingConfig.InnerSingleton, Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_VehicleHandlingConfig.InnerSingleton;
	}
	DEFINE_FUNCTION(UVH_VehiclePathFollowingComponent::execToggleDebug)
	{
		P_GET_UBOOL(Z_Param_bActive);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ToggleDebug(Z_Param_bActive);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehiclePathFollowingComponent::execSetHandlingConfig)
	{
		P_GET_STRUCT(FVehicleHandlingConfig,Z_Param_HandlingConfig);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetHandlingConfig(Z_Param_HandlingConfig);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehiclePathFollowingComponent::execGetHandlingConfig)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVehicleHandlingConfig*)Z_Param__Result=P_THIS->GetHandlingConfig();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehiclePathFollowingComponent::execIsStuck)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsStuck();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehiclePathFollowingComponent::execSetStuckStatus)
	{
		P_GET_UBOOL(Z_Param_NewStuckState);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetStuckStatus(Z_Param_NewStuckState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehiclePathFollowingComponent::execSetStuckDetection)
	{
		P_GET_UBOOL(Z_Param_bActive);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetStuckDetection(Z_Param_bActive);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehiclePathFollowingComponent::execSetCustomControl)
	{
		P_GET_UBOOL(Z_Param_bToggleCustomSteering);
		P_GET_UBOOL(Z_Param_bToggleCustomThrottle);
		P_GET_UBOOL(Z_Param_bToggleCustomBrake);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCustomControl(Z_Param_bToggleCustomSteering,Z_Param_bToggleCustomThrottle,Z_Param_bToggleCustomBrake);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehiclePathFollowingComponent::execSetVehicleCrowdSimulation)
	{
		P_GET_ENUM(E_CrowdSimulationState,Z_Param_NewState);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetVehicleCrowdSimulation(E_CrowdSimulationState(Z_Param_NewState));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehiclePathFollowingComponent::execSetDesiredSpeed)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewSpeed);
		P_GET_ENUM(EUnitOfSpeed,Z_Param_Unit);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetDesiredSpeed(Z_Param_NewSpeed,EUnitOfSpeed(Z_Param_Unit));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehiclePathFollowingComponent::execSetDestinationRotation)
	{
		P_GET_UBOOL(Z_Param_bActive);
		P_GET_STRUCT(FRotator,Z_Param_WorldRotation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetDestinationRotation(Z_Param_bActive,Z_Param_WorldRotation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehiclePathFollowingComponent::execIsReversing)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsReversing();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehiclePathFollowingComponent::execSetAutoReverse)
	{
		P_GET_UBOOL(Z_Param_Reverse);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetAutoReverse(Z_Param_Reverse);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehiclePathFollowingComponent::execSetReverse)
	{
		P_GET_UBOOL(Z_Param_Reverse);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetReverse(Z_Param_Reverse);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehiclePathFollowingComponent::execGetPathPointDataByIndex)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Index);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_PointLocation);
		P_GET_OBJECT_REF(UClass,Z_Param_Out_AreaClass);
		P_GET_UBOOL_REF(Z_Param_Out_bIsOnNavLink);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetPathPointDataByIndex(Z_Param_Index,Z_Param_Out_PointLocation,Z_Param_Out_AreaClass,Z_Param_Out_bIsOnNavLink);
		P_NATIVE_END;
	}
	void UVH_VehiclePathFollowingComponent::StaticRegisterNativesUVH_VehiclePathFollowingComponent()
	{
		UClass* Class = UVH_VehiclePathFollowingComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetHandlingConfig", &UVH_VehiclePathFollowingComponent::execGetHandlingConfig },
			{ "GetPathPointDataByIndex", &UVH_VehiclePathFollowingComponent::execGetPathPointDataByIndex },
			{ "IsReversing", &UVH_VehiclePathFollowingComponent::execIsReversing },
			{ "IsStuck", &UVH_VehiclePathFollowingComponent::execIsStuck },
			{ "SetAutoReverse", &UVH_VehiclePathFollowingComponent::execSetAutoReverse },
			{ "SetCustomControl", &UVH_VehiclePathFollowingComponent::execSetCustomControl },
			{ "SetDesiredSpeed", &UVH_VehiclePathFollowingComponent::execSetDesiredSpeed },
			{ "SetDestinationRotation", &UVH_VehiclePathFollowingComponent::execSetDestinationRotation },
			{ "SetHandlingConfig", &UVH_VehiclePathFollowingComponent::execSetHandlingConfig },
			{ "SetReverse", &UVH_VehiclePathFollowingComponent::execSetReverse },
			{ "SetStuckDetection", &UVH_VehiclePathFollowingComponent::execSetStuckDetection },
			{ "SetStuckStatus", &UVH_VehiclePathFollowingComponent::execSetStuckStatus },
			{ "SetVehicleCrowdSimulation", &UVH_VehiclePathFollowingComponent::execSetVehicleCrowdSimulation },
			{ "ToggleDebug", &UVH_VehiclePathFollowingComponent::execToggleDebug },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetHandlingConfig_Statics
	{
		struct VH_VehiclePathFollowingComponent_eventGetHandlingConfig_Parms
		{
			FVehicleHandlingConfig ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetHandlingConfig_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehiclePathFollowingComponent_eventGetHandlingConfig_Parms, ReturnValue), Z_Construct_UScriptStruct_FVehicleHandlingConfig, METADATA_PARAMS(0, nullptr) }; // 3961916097
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetHandlingConfig_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetHandlingConfig_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetHandlingConfig_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI|Stuck Detection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Returns the handling configuration for this vehicle\n\x09* @return the current handling configuration\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns the handling configuration for this vehicle\n@return the current handling configuration" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetHandlingConfig_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehiclePathFollowingComponent, nullptr, "GetHandlingConfig", nullptr, nullptr, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetHandlingConfig_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetHandlingConfig_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetHandlingConfig_Statics::VH_VehiclePathFollowingComponent_eventGetHandlingConfig_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetHandlingConfig_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetHandlingConfig_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetHandlingConfig_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetHandlingConfig_Statics::VH_VehiclePathFollowingComponent_eventGetHandlingConfig_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetHandlingConfig()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetHandlingConfig_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics
	{
		struct VH_VehiclePathFollowingComponent_eventGetPathPointDataByIndex_Parms
		{
			int32 Index;
			FVector PointLocation;
			UClass* AreaClass;
			bool bIsOnNavLink;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
		static const UECodeGen_Private::FStructPropertyParams NewProp_PointLocation;
		static const UECodeGen_Private::FClassPropertyParams NewProp_AreaClass;
		static void NewProp_bIsOnNavLink_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsOnNavLink;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehiclePathFollowingComponent_eventGetPathPointDataByIndex_Parms, Index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::NewProp_PointLocation = { "PointLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehiclePathFollowingComponent_eventGetPathPointDataByIndex_Parms, PointLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::NewProp_AreaClass = { "AreaClass", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehiclePathFollowingComponent_eventGetPathPointDataByIndex_Parms, AreaClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::NewProp_bIsOnNavLink_SetBit(void* Obj)
	{
		((VH_VehiclePathFollowingComponent_eventGetPathPointDataByIndex_Parms*)Obj)->bIsOnNavLink = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::NewProp_bIsOnNavLink = { "bIsOnNavLink", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehiclePathFollowingComponent_eventGetPathPointDataByIndex_Parms), &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::NewProp_bIsOnNavLink_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_VehiclePathFollowingComponent_eventGetPathPointDataByIndex_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehiclePathFollowingComponent_eventGetPathPointDataByIndex_Parms), &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::NewProp_Index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::NewProp_PointLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::NewProp_AreaClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::NewProp_bIsOnNavLink,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI|Helpers" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Get data about a path point by supplying an index. Useful when you want to look up data ahead on a path for a vehicle so you can make speed adjustments */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get data about a path point by supplying an index. Useful when you want to look up data ahead on a path for a vehicle so you can make speed adjustments" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehiclePathFollowingComponent, nullptr, "GetPathPointDataByIndex", nullptr, nullptr, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::VH_VehiclePathFollowingComponent_eventGetPathPointDataByIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::VH_VehiclePathFollowingComponent_eventGetPathPointDataByIndex_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing_Statics
	{
		struct VH_VehiclePathFollowingComponent_eventIsReversing_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_VehiclePathFollowingComponent_eventIsReversing_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehiclePathFollowingComponent_eventIsReversing_Parms), &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI|Reverse" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Toggles the automatic reverse capability\n\x09* @param Reverse - Toggle the automatic reverse\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Toggles the automatic reverse capability\n@param Reverse - Toggle the automatic reverse" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehiclePathFollowingComponent, nullptr, "IsReversing", nullptr, nullptr, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing_Statics::VH_VehiclePathFollowingComponent_eventIsReversing_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing_Statics::VH_VehiclePathFollowingComponent_eventIsReversing_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck_Statics
	{
		struct VH_VehiclePathFollowingComponent_eventIsStuck_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_VehiclePathFollowingComponent_eventIsStuck_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehiclePathFollowingComponent_eventIsStuck_Parms), &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI|Stuck Detection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Checks if this vehicle is stuck (on path but hasn't moved in a while according to sample data)\n\x09* @return true if the vehicle is stuck\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Checks if this vehicle is stuck (on path but hasn't moved in a while according to sample data)\n@return true if the vehicle is stuck" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehiclePathFollowingComponent, nullptr, "IsStuck", nullptr, nullptr, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck_Statics::VH_VehiclePathFollowingComponent_eventIsStuck_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck_Statics::VH_VehiclePathFollowingComponent_eventIsStuck_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse_Statics
	{
		struct VH_VehiclePathFollowingComponent_eventSetAutoReverse_Parms
		{
			bool Reverse;
		};
		static void NewProp_Reverse_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Reverse;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse_Statics::NewProp_Reverse_SetBit(void* Obj)
	{
		((VH_VehiclePathFollowingComponent_eventSetAutoReverse_Parms*)Obj)->Reverse = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse_Statics::NewProp_Reverse = { "Reverse", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehiclePathFollowingComponent_eventSetAutoReverse_Parms), &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse_Statics::NewProp_Reverse_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse_Statics::NewProp_Reverse,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI|Reverse" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Toggles the automatic reverse capability\n\x09* @param Reverse - Toggle the automatic reverse\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Toggles the automatic reverse capability\n@param Reverse - Toggle the automatic reverse" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehiclePathFollowingComponent, nullptr, "SetAutoReverse", nullptr, nullptr, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse_Statics::VH_VehiclePathFollowingComponent_eventSetAutoReverse_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse_Statics::VH_VehiclePathFollowingComponent_eventSetAutoReverse_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics
	{
		struct VH_VehiclePathFollowingComponent_eventSetCustomControl_Parms
		{
			bool bToggleCustomSteering;
			bool bToggleCustomThrottle;
			bool bToggleCustomBrake;
		};
		static void NewProp_bToggleCustomSteering_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bToggleCustomSteering;
		static void NewProp_bToggleCustomThrottle_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bToggleCustomThrottle;
		static void NewProp_bToggleCustomBrake_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bToggleCustomBrake;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::NewProp_bToggleCustomSteering_SetBit(void* Obj)
	{
		((VH_VehiclePathFollowingComponent_eventSetCustomControl_Parms*)Obj)->bToggleCustomSteering = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::NewProp_bToggleCustomSteering = { "bToggleCustomSteering", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehiclePathFollowingComponent_eventSetCustomControl_Parms), &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::NewProp_bToggleCustomSteering_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::NewProp_bToggleCustomThrottle_SetBit(void* Obj)
	{
		((VH_VehiclePathFollowingComponent_eventSetCustomControl_Parms*)Obj)->bToggleCustomThrottle = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::NewProp_bToggleCustomThrottle = { "bToggleCustomThrottle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehiclePathFollowingComponent_eventSetCustomControl_Parms), &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::NewProp_bToggleCustomThrottle_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::NewProp_bToggleCustomBrake_SetBit(void* Obj)
	{
		((VH_VehiclePathFollowingComponent_eventSetCustomControl_Parms*)Obj)->bToggleCustomBrake = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::NewProp_bToggleCustomBrake = { "bToggleCustomBrake", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehiclePathFollowingComponent_eventSetCustomControl_Parms), &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::NewProp_bToggleCustomBrake_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::NewProp_bToggleCustomSteering,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::NewProp_bToggleCustomThrottle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::NewProp_bToggleCustomBrake,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI|Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Toggles this vehicle to use custom controls at runtime. Useful if you need to use specific custom controlling at a particular event\n\x09* @param bToggleCustomSteering - Toggles the custom steering\n\x09* @param bToggleCustomThrottle - Toggles the custom throttle setting\n\x09* @param bToggleCustomBrake - Toggles the custom brake setting\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Toggles this vehicle to use custom controls at runtime. Useful if you need to use specific custom controlling at a particular event\n@param bToggleCustomSteering - Toggles the custom steering\n@param bToggleCustomThrottle - Toggles the custom throttle setting\n@param bToggleCustomBrake - Toggles the custom brake setting" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehiclePathFollowingComponent, nullptr, "SetCustomControl", nullptr, nullptr, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::VH_VehiclePathFollowingComponent_eventSetCustomControl_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::VH_VehiclePathFollowingComponent_eventSetCustomControl_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics
	{
		struct VH_VehiclePathFollowingComponent_eventSetDesiredSpeed_Parms
		{
			float NewSpeed;
			EUnitOfSpeed Unit;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_NewSpeed;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Unit_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Unit;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::NewProp_NewSpeed = { "NewSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehiclePathFollowingComponent_eventSetDesiredSpeed_Parms, NewSpeed), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::NewProp_Unit_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::NewProp_Unit = { "Unit", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehiclePathFollowingComponent_eventSetDesiredSpeed_Parms, Unit), Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed, METADATA_PARAMS(0, nullptr) }; // 2057425959
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::NewProp_NewSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::NewProp_Unit_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::NewProp_Unit,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI|Speed Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Updates this agents desired speed\n\x09* @param NewSpeed - Defines the new speed, given in Unreal Units (cm/s)\n\x09* @param Unit - The units of data to use for the speed conversion which is done internally\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Updates this agents desired speed\n@param NewSpeed - Defines the new speed, given in Unreal Units (cm/s)\n@param Unit - The units of data to use for the speed conversion which is done internally" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehiclePathFollowingComponent, nullptr, "SetDesiredSpeed", nullptr, nullptr, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::VH_VehiclePathFollowingComponent_eventSetDesiredSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::VH_VehiclePathFollowingComponent_eventSetDesiredSpeed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics
	{
		struct VH_VehiclePathFollowingComponent_eventSetDestinationRotation_Parms
		{
			bool bActive;
			FRotator WorldRotation;
		};
		static void NewProp_bActive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bActive;
		static const UECodeGen_Private::FStructPropertyParams NewProp_WorldRotation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::NewProp_bActive_SetBit(void* Obj)
	{
		((VH_VehiclePathFollowingComponent_eventSetDestinationRotation_Parms*)Obj)->bActive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::NewProp_bActive = { "bActive", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehiclePathFollowingComponent_eventSetDestinationRotation_Parms), &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::NewProp_bActive_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::NewProp_WorldRotation = { "WorldRotation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehiclePathFollowingComponent_eventSetDestinationRotation_Parms, WorldRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::NewProp_bActive,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::NewProp_WorldRotation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI|Reverse" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Toggles the ability to face a direction when at a target location\n\x09* @param bActive - Toggles the rotation ability\n\x09* @param WorldRotation - The rotation the vehicle should face\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Toggles the ability to face a direction when at a target location\n@param bActive - Toggles the rotation ability\n@param WorldRotation - The rotation the vehicle should face" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehiclePathFollowingComponent, nullptr, "SetDestinationRotation", nullptr, nullptr, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::VH_VehiclePathFollowingComponent_eventSetDestinationRotation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::VH_VehiclePathFollowingComponent_eventSetDestinationRotation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetHandlingConfig_Statics
	{
		struct VH_VehiclePathFollowingComponent_eventSetHandlingConfig_Parms
		{
			FVehicleHandlingConfig HandlingConfig;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_HandlingConfig;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetHandlingConfig_Statics::NewProp_HandlingConfig = { "HandlingConfig", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehiclePathFollowingComponent_eventSetHandlingConfig_Parms, HandlingConfig), Z_Construct_UScriptStruct_FVehicleHandlingConfig, METADATA_PARAMS(0, nullptr) }; // 3961916097
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetHandlingConfig_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetHandlingConfig_Statics::NewProp_HandlingConfig,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetHandlingConfig_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI|Stuck Detection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Set a handling configuration profile onto this controller\n\x09* @param HandlingConfig\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set a handling configuration profile onto this controller\n@param HandlingConfig" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetHandlingConfig_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehiclePathFollowingComponent, nullptr, "SetHandlingConfig", nullptr, nullptr, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetHandlingConfig_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetHandlingConfig_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetHandlingConfig_Statics::VH_VehiclePathFollowingComponent_eventSetHandlingConfig_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetHandlingConfig_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetHandlingConfig_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetHandlingConfig_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetHandlingConfig_Statics::VH_VehiclePathFollowingComponent_eventSetHandlingConfig_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetHandlingConfig()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetHandlingConfig_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse_Statics
	{
		struct VH_VehiclePathFollowingComponent_eventSetReverse_Parms
		{
			bool Reverse;
		};
		static void NewProp_Reverse_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_Reverse;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse_Statics::NewProp_Reverse_SetBit(void* Obj)
	{
		((VH_VehiclePathFollowingComponent_eventSetReverse_Parms*)Obj)->Reverse = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse_Statics::NewProp_Reverse = { "Reverse", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehiclePathFollowingComponent_eventSetReverse_Parms), &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse_Statics::NewProp_Reverse_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse_Statics::NewProp_Reverse,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI|Reverse" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Set this agent to force reverse manually\n\x09* @param Reverse - Toggle the force reverse\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Set this agent to force reverse manually\n@param Reverse - Toggle the force reverse" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehiclePathFollowingComponent, nullptr, "SetReverse", nullptr, nullptr, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse_Statics::VH_VehiclePathFollowingComponent_eventSetReverse_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse_Statics::VH_VehiclePathFollowingComponent_eventSetReverse_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection_Statics
	{
		struct VH_VehiclePathFollowingComponent_eventSetStuckDetection_Parms
		{
			bool bActive;
		};
		static void NewProp_bActive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bActive;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection_Statics::NewProp_bActive_SetBit(void* Obj)
	{
		((VH_VehiclePathFollowingComponent_eventSetStuckDetection_Parms*)Obj)->bActive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection_Statics::NewProp_bActive = { "bActive", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehiclePathFollowingComponent_eventSetStuckDetection_Parms), &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection_Statics::NewProp_bActive_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection_Statics::NewProp_bActive,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI|Stuck Detection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Toggles this vehicles stuck detection, which you might want to disable in certain scenarios\n\x09* @param bActive - Toggles the stuck detection\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Toggles this vehicles stuck detection, which you might want to disable in certain scenarios\n@param bActive - Toggles the stuck detection" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehiclePathFollowingComponent, nullptr, "SetStuckDetection", nullptr, nullptr, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection_Statics::VH_VehiclePathFollowingComponent_eventSetStuckDetection_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection_Statics::VH_VehiclePathFollowingComponent_eventSetStuckDetection_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus_Statics
	{
		struct VH_VehiclePathFollowingComponent_eventSetStuckStatus_Parms
		{
			bool NewStuckState;
		};
		static void NewProp_NewStuckState_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_NewStuckState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus_Statics::NewProp_NewStuckState_SetBit(void* Obj)
	{
		((VH_VehiclePathFollowingComponent_eventSetStuckStatus_Parms*)Obj)->NewStuckState = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus_Statics::NewProp_NewStuckState = { "NewStuckState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehiclePathFollowingComponent_eventSetStuckStatus_Parms), &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus_Statics::NewProp_NewStuckState_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus_Statics::NewProp_NewStuckState,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI|Stuck Detection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Sets the stuck status of this vehicle. Use to manually perform unstuck behaviour. Can also implement custom stuck behavior\n\x09* @param NewStuckState - Sets if this vehicle is stuck or not\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the stuck status of this vehicle. Use to manually perform unstuck behaviour. Can also implement custom stuck behavior\n@param NewStuckState - Sets if this vehicle is stuck or not" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehiclePathFollowingComponent, nullptr, "SetStuckStatus", nullptr, nullptr, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus_Statics::VH_VehiclePathFollowingComponent_eventSetStuckStatus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus_Statics::VH_VehiclePathFollowingComponent_eventSetStuckStatus_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation_Statics
	{
		struct VH_VehiclePathFollowingComponent_eventSetVehicleCrowdSimulation_Parms
		{
			E_CrowdSimulationState NewState;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_NewState_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_NewState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation_Statics::NewProp_NewState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation_Statics::NewProp_NewState = { "NewState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehiclePathFollowingComponent_eventSetVehicleCrowdSimulation_Parms, NewState), Z_Construct_UEnum_VH_Vehicle_E_CrowdSimulationState, METADATA_PARAMS(0, nullptr) }; // 252967047
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation_Statics::NewProp_NewState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation_Statics::NewProp_NewState,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI|Avoidance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Update the crowd simulation, allows for setting crowd simulation on a per agent basis\n\x09* @param NewState - Changes the crowd simulation state\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Update the crowd simulation, allows for setting crowd simulation on a per agent basis\n@param NewState - Changes the crowd simulation state" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehiclePathFollowingComponent, nullptr, "SetVehicleCrowdSimulation", nullptr, nullptr, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation_Statics::VH_VehiclePathFollowingComponent_eventSetVehicleCrowdSimulation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation_Statics::VH_VehiclePathFollowingComponent_eventSetVehicleCrowdSimulation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug_Statics
	{
		struct VH_VehiclePathFollowingComponent_eventToggleDebug_Parms
		{
			bool bActive;
		};
		static void NewProp_bActive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bActive;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug_Statics::NewProp_bActive_SetBit(void* Obj)
	{
		((VH_VehiclePathFollowingComponent_eventToggleDebug_Parms*)Obj)->bActive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug_Statics::NewProp_bActive = { "bActive", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehiclePathFollowingComponent_eventToggleDebug_Parms), &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug_Statics::NewProp_bActive_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug_Statics::NewProp_bActive,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI|Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Toggles the debug state on this agent. Debug shows information such as target angle, desired speed etc.\n\x09* @param bActive - Toggles whether the debug is active\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Toggles the debug state on this agent. Debug shows information such as target angle, desired speed etc.\n@param bActive - Toggles whether the debug is active" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehiclePathFollowingComponent, nullptr, "ToggleDebug", nullptr, nullptr, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug_Statics::VH_VehiclePathFollowingComponent_eventToggleDebug_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug_Statics::VH_VehiclePathFollowingComponent_eventToggleDebug_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_VehiclePathFollowingComponent);
	UClass* Z_Construct_UClass_UVH_VehiclePathFollowingComponent_NoRegister()
	{
		return UVH_VehiclePathFollowingComponent::StaticClass();
	}
	struct Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseCustomAcceptanceRadius_MetaData[];
#endif
		static void NewProp_bUseCustomAcceptanceRadius_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseCustomAcceptanceRadius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VehiclePathPointAcceptanceRadius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VehiclePathPointAcceptanceRadius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VehicleNavLinkAcceptanceRadius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VehicleNavLinkAcceptanceRadius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCustomSteering_MetaData[];
#endif
		static void NewProp_bCustomSteering_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCustomSteering;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCustomThrottle_MetaData[];
#endif
		static void NewProp_bCustomThrottle_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCustomThrottle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCustomBrake_MetaData[];
#endif
		static void NewProp_bCustomBrake_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCustomBrake;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MinThrottle_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MinThrottle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DesiredSpeedCurve_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DesiredSpeedCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DesiredSpeedThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DesiredSpeedThreshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StartingDesiredSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_StartingDesiredSpeed;
		static const UECodeGen_Private::FBytePropertyParams NewProp_StartSpeedUnit_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StartSpeedUnit_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_StartSpeedUnit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DesiredSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DesiredSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DesiredSpeedThrottleStepMax_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DesiredSpeedThrottleStepMax;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DesiredSpeedThrottleStepMin_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DesiredSpeedThrottleStepMin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DesiredSpeedThrottleThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DesiredSpeedThrottleThreshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseBrakes_MetaData[];
#endif
		static void NewProp_bUseBrakes_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseBrakes;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BrakeThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_BrakeThreshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NormalisedTurnThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_NormalisedTurnThreshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BrakeAmount_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_BrakeAmount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxEmergencyBrakeAmount_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxEmergencyBrakeAmount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bThrottleUsePID_MetaData[];
#endif
		static void NewProp_bThrottleUsePID_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bThrottleUsePID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThrottlePIDSetup_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ThrottlePIDSetup;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseAdvancedSpeedControl_MetaData[];
#endif
		static void NewProp_bUseAdvancedSpeedControl_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseAdvancedSpeedControl;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CornerSpeedControlPercentage_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CornerSpeedControlPercentage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutoCalculateSlowdownDistance_MetaData[];
#endif
		static void NewProp_bAutoCalculateSlowdownDistance_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoCalculateSlowdownDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VehicleMass_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VehicleMass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StaticFrictionCoefficient_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_StaticFrictionCoefficient;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WorldGravity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_WorldGravity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bEnableSlowdown_MetaData[];
#endif
		static void NewProp_bEnableSlowdown_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableSlowdown;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSlowdownAtNavLinks_MetaData[];
#endif
		static void NewProp_bSlowdownAtNavLinks_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSlowdownAtNavLinks;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlowdownDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SlowdownDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CornerSlowdownSamples_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_CornerSlowdownSamples;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxCornerSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxCornerSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AverageCornerSampleRange_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AverageCornerSampleRange;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StuckDetectionSampleCount_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_StuckDetectionSampleCount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseStuckDetection_MetaData[];
#endif
		static void NewProp_bUseStuckDetection_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseStuckDetection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UnStuckDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_UnStuckDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StuckDetectionDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_StuckDetectionDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StuckAcceptanceRadius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_StuckAcceptanceRadius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StuckDetectionInterval_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_StuckDetectionInterval;
		static const UECodeGen_Private::FBytePropertyParams NewProp_DetourCrowdSimulationState_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DetourCrowdSimulationState_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DetourCrowdSimulationState;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CrowdAvoidanceRangeMultiplier_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CrowdAvoidanceRangeMultiplier;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VehicleMaxSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VehicleMaxSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShouldReverseAngle_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ShouldReverseAngle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReverseMaxDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReverseMaxDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReverseThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReverseThreshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutoReverse_MetaData[];
#endif
		static void NewProp_bAutoReverse_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoReverse;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bOnlyReverseWhenStuck_MetaData[];
#endif
		static void NewProp_bOnlyReverseWhenStuck_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOnlyReverseWhenStuck;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SteeringMultiplier_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SteeringMultiplier;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SteeringCurve_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SteeringCurve;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSteeringUsePID_MetaData[];
#endif
		static void NewProp_bSteeringUsePID_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSteeringUsePID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SteeringPIDSetup_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SteeringPIDSetup;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDebug_MetaData[];
#endif
		static void NewProp_bDebug_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebug;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UCrowdFollowingComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Vehicle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetHandlingConfig, "GetHandlingConfig" }, // 1406931237
		{ &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_GetPathPointDataByIndex, "GetPathPointDataByIndex" }, // 1100481276
		{ &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsReversing, "IsReversing" }, // 2629805788
		{ &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_IsStuck, "IsStuck" }, // 225988020
		{ &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetAutoReverse, "SetAutoReverse" }, // 738054951
		{ &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetCustomControl, "SetCustomControl" }, // 2433954472
		{ &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDesiredSpeed, "SetDesiredSpeed" }, // 779754592
		{ &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetDestinationRotation, "SetDestinationRotation" }, // 3338793525
		{ &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetHandlingConfig, "SetHandlingConfig" }, // 273540265
		{ &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetReverse, "SetReverse" }, // 2192252708
		{ &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckDetection, "SetStuckDetection" }, // 1035683180
		{ &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetStuckStatus, "SetStuckStatus" }, // 1787328118
		{ &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_SetVehicleCrowdSimulation, "SetVehicleCrowdSimulation" }, // 1775357102
		{ &Z_Construct_UFunction_UVH_VehiclePathFollowingComponent_ToggleDebug, "ToggleDebug" }, // 2972087349
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Handles the path following for a wheeled vehicle. Inherits from Crowd Following for Detour Crowd control\n */" },
#endif
		{ "IncludePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handles the path following for a wheeled vehicle. Inherits from Crowd Following for Detour Crowd control" },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseCustomAcceptanceRadius_MetaData[] = {
		{ "Category", "Path Following" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Changes the acceptance radius from the defaults set in the project settings */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Changes the acceptance radius from the defaults set in the project settings" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseCustomAcceptanceRadius_SetBit(void* Obj)
	{
		((UVH_VehiclePathFollowingComponent*)Obj)->bUseCustomAcceptanceRadius = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseCustomAcceptanceRadius = { "bUseCustomAcceptanceRadius", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_VehiclePathFollowingComponent), &Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseCustomAcceptanceRadius_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseCustomAcceptanceRadius_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseCustomAcceptanceRadius_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehiclePathPointAcceptanceRadius_MetaData[] = {
		{ "Category", "Path Following" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The acceptance radius for an individual path point */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The acceptance radius for an individual path point" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehiclePathPointAcceptanceRadius = { "VehiclePathPointAcceptanceRadius", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, VehiclePathPointAcceptanceRadius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehiclePathPointAcceptanceRadius_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehiclePathPointAcceptanceRadius_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehicleNavLinkAcceptanceRadius_MetaData[] = {
		{ "Category", "Path Following" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The acceptance radius for an navigation link */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The acceptance radius for an navigation link" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehicleNavLinkAcceptanceRadius = { "VehicleNavLinkAcceptanceRadius", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, VehicleNavLinkAcceptanceRadius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehicleNavLinkAcceptanceRadius_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehicleNavLinkAcceptanceRadius_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomSteering_MetaData[] = {
		{ "Category", "Custom Handling" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Let an interface on the agent handle the steering output */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Let an interface on the agent handle the steering output" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomSteering_SetBit(void* Obj)
	{
		((UVH_VehiclePathFollowingComponent*)Obj)->bCustomSteering = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomSteering = { "bCustomSteering", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_VehiclePathFollowingComponent), &Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomSteering_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomSteering_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomSteering_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomThrottle_MetaData[] = {
		{ "Category", "Custom Handling" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Let an interface on the agent handle the throttle output */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Let an interface on the agent handle the throttle output" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomThrottle_SetBit(void* Obj)
	{
		((UVH_VehiclePathFollowingComponent*)Obj)->bCustomThrottle = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomThrottle = { "bCustomThrottle", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_VehiclePathFollowingComponent), &Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomThrottle_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomThrottle_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomThrottle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomBrake_MetaData[] = {
		{ "Category", "Custom Handling" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Let an interface on the agent handle the brake output */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Let an interface on the agent handle the brake output" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomBrake_SetBit(void* Obj)
	{
		((UVH_VehiclePathFollowingComponent*)Obj)->bCustomBrake = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomBrake = { "bCustomBrake", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_VehiclePathFollowingComponent), &Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomBrake_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomBrake_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomBrake_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_MinThrottle_MetaData[] = {
		{ "Category", "Speed Control" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Minimum throttle to step down to when controlling speed. Don't set the value too low or the vehicle might not move */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Minimum throttle to step down to when controlling speed. Don't set the value too low or the vehicle might not move" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_MinThrottle = { "MinThrottle", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, MinThrottle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_MinThrottle_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_MinThrottle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedCurve_MetaData[] = {
		{ "Category", "Speed Control|Deprecated" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Curve that changes the percentage of the desired speed (0 -> 1) based on the normalised steering angle (0 -> 1)\n\x09This property will be deprecated in a future release as it doesn't seem to be that useful and getting the same functionality can be done using\n\x09the blueprint interface. If you are actively using this feature and would not like it removed, then */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Curve that changes the percentage of the desired speed (0 -> 1) based on the normalised steering angle (0 -> 1)\n      This property will be deprecated in a future release as it doesn't seem to be that useful and getting the same functionality can be done using\n      the blueprint interface. If you are actively using this feature and would not like it removed, then" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedCurve = { "DesiredSpeedCurve", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, DesiredSpeedCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedCurve_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedCurve_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThreshold_MetaData[] = {
		{ "Category", "Speed Control|Desired Speed" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Threshold where throttle will be adjusted for meet the desired speed */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Threshold where throttle will be adjusted for meet the desired speed" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThreshold = { "DesiredSpeedThreshold", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, DesiredSpeedThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThreshold_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThreshold_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StartingDesiredSpeed_MetaData[] = {
		{ "Category", "Speed Control|Desired Speed" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The starting desired speed of this vehicle, the units of which are defined by the Start Speed Unit */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The starting desired speed of this vehicle, the units of which are defined by the Start Speed Unit" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StartingDesiredSpeed = { "StartingDesiredSpeed", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, StartingDesiredSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StartingDesiredSpeed_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StartingDesiredSpeed_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StartSpeedUnit_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StartSpeedUnit_MetaData[] = {
		{ "Category", "Speed Control|Desired Speed" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The speed units this vehicle will use when the desired speed */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The speed units this vehicle will use when the desired speed" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StartSpeedUnit = { "StartSpeedUnit", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, StartSpeedUnit), Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StartSpeedUnit_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StartSpeedUnit_MetaData) }; // 2057425959
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeed_MetaData[] = {
		{ "Category", "Speed Control|Desired Speed" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The speed of this vehicle in cm/s, speed is always converted into cm/s in the plugin as this is the default velocity units\n\x09This value changes as the Starting Desired Speed changes and/or its units change */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The speed of this vehicle in cm/s, speed is always converted into cm/s in the plugin as this is the default velocity units\n      This value changes as the Starting Desired Speed changes and/or its units change" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeed = { "DesiredSpeed", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, DesiredSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeed_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThrottleStepMax_MetaData[] = {
		{ "Category", "Speed Control|Throttle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The amount of change the throttle by each frame to keep the speed within the threshold */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The amount of change the throttle by each frame to keep the speed within the threshold" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThrottleStepMax = { "DesiredSpeedThrottleStepMax", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, DesiredSpeedThrottleStepMax), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThrottleStepMax_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThrottleStepMax_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThrottleStepMin_MetaData[] = {
		{ "Category", "Speed Control|Throttle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The amount of change the throttle by each frame to keep the speed within the threshold */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The amount of change the throttle by each frame to keep the speed within the threshold" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThrottleStepMin = { "DesiredSpeedThrottleStepMin", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, DesiredSpeedThrottleStepMin), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThrottleStepMin_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThrottleStepMin_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThrottleThreshold_MetaData[] = {
		{ "Category", "Speed Control|Throttle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* When the speed is above or below this value, use the full throttle value */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When the speed is above or below this value, use the full throttle value" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThrottleThreshold = { "DesiredSpeedThrottleThreshold", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, DesiredSpeedThrottleThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThrottleThreshold_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThrottleThreshold_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseBrakes_MetaData[] = {
		{ "Category", "Speed Control|Brakes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Whether this AI is allowed to use its brakes  */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Whether this AI is allowed to use its brakes" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseBrakes_SetBit(void* Obj)
	{
		((UVH_VehiclePathFollowingComponent*)Obj)->bUseBrakes = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseBrakes = { "bUseBrakes", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_VehiclePathFollowingComponent), &Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseBrakes_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseBrakes_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseBrakes_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_BrakeThreshold_MetaData[] = {
		{ "Category", "Speed Control|Brakes" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The threshold above the desired speed (+ speed threshold) at which to apply the brakes\n\x09*  Decrease this if the vehicle doesnt apply brakes quickly enough \x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The threshold above the desired speed (+ speed threshold) at which to apply the brakes\n      *  Decrease this if the vehicle doesnt apply brakes quickly enough" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_BrakeThreshold = { "BrakeThreshold", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, BrakeThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_BrakeThreshold_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_BrakeThreshold_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_NormalisedTurnThreshold_MetaData[] = {
		{ "Category", "Speed Control|Throttle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* If the normalized turn value is greater than this you can force the throttle to be off (where 1 is fully right and -1 is fully left)\n\x09*  then we don't want to accelerate anymore as it means the vehicle will miss its turning.\n\x09*  Reduce this if the vehicle keeps overshooting corners\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If the normalized turn value is greater than this you can force the throttle to be off (where 1 is fully right and -1 is fully left)\n      *  then we don't want to accelerate anymore as it means the vehicle will miss its turning.\n      *  Reduce this if the vehicle keeps overshooting corners" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_NormalisedTurnThreshold = { "NormalisedTurnThreshold", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, NormalisedTurnThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_NormalisedTurnThreshold_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_NormalisedTurnThreshold_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_BrakeAmount_MetaData[] = {
		{ "Category", "Speed Control|Brakes" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The amount of intensity you want the brakes to apply when using brakes to slow down, use higher values if you want the brakes to be applied\n\x09   more aggressively such as in a racing game */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The amount of intensity you want the brakes to apply when using brakes to slow down, use higher values if you want the brakes to be applied\n         more aggressively such as in a racing game" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_BrakeAmount = { "BrakeAmount", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, BrakeAmount), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_BrakeAmount_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_BrakeAmount_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_MaxEmergencyBrakeAmount_MetaData[] = {
		{ "Category", "Speed Control|Brakes" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The amount of intensity you want the brakes to apply if normal braking wouldn't slow the vehicle down in time */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The amount of intensity you want the brakes to apply if normal braking wouldn't slow the vehicle down in time" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_MaxEmergencyBrakeAmount = { "MaxEmergencyBrakeAmount", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, MaxEmergencyBrakeAmount), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_MaxEmergencyBrakeAmount_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_MaxEmergencyBrakeAmount_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bThrottleUsePID_MetaData[] = {
		{ "Category", "Speed Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Should throttle use a PID controller, instead of any other method. The other method just steps up and down the throttle\n\x09*  to get to the desired speed, which can in some cases work better (especially with abnormal vehicle types) \n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should throttle use a PID controller, instead of any other method. The other method just steps up and down the throttle\n      *  to get to the desired speed, which can in some cases work better (especially with abnormal vehicle types)" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bThrottleUsePID_SetBit(void* Obj)
	{
		((UVH_VehiclePathFollowingComponent*)Obj)->bThrottleUsePID = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bThrottleUsePID = { "bThrottleUsePID", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_VehiclePathFollowingComponent), &Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bThrottleUsePID_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bThrottleUsePID_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bThrottleUsePID_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ThrottlePIDSetup_MetaData[] = {
		{ "Category", "Speed Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Sets up each coefficient for the throttle PID controller\n\x09*  P: Proportional to the amount needed to speed up, generally fine left as 1\n\x09*  I: Adjust this value if the throttle keeps oscillating (increase in small intervals 0.1)\n\x09*  D: Generally not needed, but increase if I doesn't fix the oscillating\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets up each coefficient for the throttle PID controller\n      *  P: Proportional to the amount needed to speed up, generally fine left as 1\n      *  I: Adjust this value if the throttle keeps oscillating (increase in small intervals 0.1)\n      *  D: Generally not needed, but increase if I doesn't fix the oscillating" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ThrottlePIDSetup = { "ThrottlePIDSetup", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, ThrottlePIDSetup), Z_Construct_UScriptStruct_FPIDCoefficients, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ThrottlePIDSetup_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ThrottlePIDSetup_MetaData) }; // 374115500
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseAdvancedSpeedControl_MetaData[] = {
		{ "Category", "Speed Control|Advanced" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* This is an experimental setting to calculate the maximum speed the vehicle can take a corner with the given parameters.\n\x09*  It hasn't been tested in enough scenarios to enable as default yet, but if you want to try it out on your project it could greatly improve cornering\n\x09*  with no additional steps required. This also does have a slightly bigger impact on performance too, but its relatively negligible. \n\x09*  This uses the physical properties of the vehicle such as its mass and the friction coefficient to calculate things like stopping distance. The goal here is to use\n\x09*  physical values that are pulled directly from the vehicle, so that very little manual tweaking is required to get it working \n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This is an experimental setting to calculate the maximum speed the vehicle can take a corner with the given parameters.\n      *  It hasn't been tested in enough scenarios to enable as default yet, but if you want to try it out on your project it could greatly improve cornering\n      *  with no additional steps required. This also does have a slightly bigger impact on performance too, but its relatively negligible.\n      *  This uses the physical properties of the vehicle such as its mass and the friction coefficient to calculate things like stopping distance. The goal here is to use\n      *  physical values that are pulled directly from the vehicle, so that very little manual tweaking is required to get it working" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseAdvancedSpeedControl_SetBit(void* Obj)
	{
		((UVH_VehiclePathFollowingComponent*)Obj)->bUseAdvancedSpeedControl = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseAdvancedSpeedControl = { "bUseAdvancedSpeedControl", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_VehiclePathFollowingComponent), &Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseAdvancedSpeedControl_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseAdvancedSpeedControl_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseAdvancedSpeedControl_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_CornerSpeedControlPercentage_MetaData[] = {
		{ "Category", "Speed Control|Advanced" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* This is the value that the speed control scales by when using the advanced control, 1 means it goes the max speed it physically can around a corner\n\x09*  (within the desired speed), but the default of 0.5 means it should easily follow the path exactly around a corner.\n\x09* \n\x09*  Tweaking:\n\x09* \n\x09*  Vehicle doesn't follow corner precisely enough: Reduce\n\x09*  Vehicle goes around corners too slowly: Increase (until it starts to not handle very well)\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This is the value that the speed control scales by when using the advanced control, 1 means it goes the max speed it physically can around a corner\n      *  (within the desired speed), but the default of 0.5 means it should easily follow the path exactly around a corner.\n      *\n      *  Tweaking:\n      *\n      *  Vehicle doesn't follow corner precisely enough: Reduce\n      *  Vehicle goes around corners too slowly: Increase (until it starts to not handle very well)" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_CornerSpeedControlPercentage = { "CornerSpeedControlPercentage", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, CornerSpeedControlPercentage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_CornerSpeedControlPercentage_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_CornerSpeedControlPercentage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bAutoCalculateSlowdownDistance_MetaData[] = {
		{ "Category", "Speed Control|Advanced" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Automatically calculates the slowdown distance instead of having a fixed value, generally want this on if using advanced speed control\n\x09""and it is enabled by default but you can disable it to maintain the older functionality */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Automatically calculates the slowdown distance instead of having a fixed value, generally want this on if using advanced speed control\n      and it is enabled by default but you can disable it to maintain the older functionality" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bAutoCalculateSlowdownDistance_SetBit(void* Obj)
	{
		((UVH_VehiclePathFollowingComponent*)Obj)->bAutoCalculateSlowdownDistance = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bAutoCalculateSlowdownDistance = { "bAutoCalculateSlowdownDistance", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_VehiclePathFollowingComponent), &Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bAutoCalculateSlowdownDistance_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bAutoCalculateSlowdownDistance_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bAutoCalculateSlowdownDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehicleMass_MetaData[] = {
		{ "Category", "Speed Control|Advanced" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The mass of the vehicle being used, can be changed if using a different vehicle setup */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The mass of the vehicle being used, can be changed if using a different vehicle setup" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehicleMass = { "VehicleMass", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, VehicleMass), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehicleMass_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehicleMass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StaticFrictionCoefficient_MetaData[] = {
		{ "Category", "Speed Control|Advanced" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The coefficient of static friction of the type and road surface */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The coefficient of static friction of the type and road surface" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StaticFrictionCoefficient = { "StaticFrictionCoefficient", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, StaticFrictionCoefficient), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StaticFrictionCoefficient_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StaticFrictionCoefficient_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_WorldGravity_MetaData[] = {
		{ "Category", "Speed Control|Advanced" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The world gravity, if you use a custom gravity setting you can change this here */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The world gravity, if you use a custom gravity setting you can change this here" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_WorldGravity = { "WorldGravity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, WorldGravity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_WorldGravity_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_WorldGravity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bEnableSlowdown_MetaData[] = {
		{ "Category", "Slowdown" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Enables the ability to slowdown at the final destination, generally you want this on unless\n\x09*  you want to control this yourself using the interface */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enables the ability to slowdown at the final destination, generally you want this on unless\n      *  you want to control this yourself using the interface" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bEnableSlowdown_SetBit(void* Obj)
	{
		((UVH_VehiclePathFollowingComponent*)Obj)->bEnableSlowdown = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bEnableSlowdown = { "bEnableSlowdown", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_VehiclePathFollowingComponent), &Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bEnableSlowdown_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bEnableSlowdown_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bEnableSlowdown_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bSlowdownAtNavLinks_MetaData[] = {
		{ "Category", "Slowdown" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The vehicle will attempt to slow down at path points that are Nav Links, this is important if   */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The vehicle will attempt to slow down at path points that are Nav Links, this is important if" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bSlowdownAtNavLinks_SetBit(void* Obj)
	{
		((UVH_VehiclePathFollowingComponent*)Obj)->bSlowdownAtNavLinks = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bSlowdownAtNavLinks = { "bSlowdownAtNavLinks", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_VehiclePathFollowingComponent), &Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bSlowdownAtNavLinks_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bSlowdownAtNavLinks_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bSlowdownAtNavLinks_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SlowdownDistance_MetaData[] = {
		{ "Category", "Slowdown" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The distance at which to start the slowdown, the greater this is, the smoother the slowdown is,\n\x09   especially at higher speeds */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The distance at which to start the slowdown, the greater this is, the smoother the slowdown is,\n         especially at higher speeds" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SlowdownDistance = { "SlowdownDistance", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, SlowdownDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SlowdownDistance_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SlowdownDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_CornerSlowdownSamples_MetaData[] = {
		{ "Category", "Slowdown" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The number of samples taken to calculate the speed at which to slow down\n\x09   they are only included if within the slowdown distance. This helps a vehicle get\n\x09   around a corner which could be made up of multiple path points, close together. This is mainly here for performance reasons*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The number of samples taken to calculate the speed at which to slow down\n         they are only included if within the slowdown distance. This helps a vehicle get\n         around a corner which could be made up of multiple path points, close together. This is mainly here for performance reasons" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_CornerSlowdownSamples = { "CornerSlowdownSamples", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, CornerSlowdownSamples), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_CornerSlowdownSamples_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_CornerSlowdownSamples_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_MaxCornerSpeed_MetaData[] = {
		{ "Category", "Slowdown" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The maximum speed that a corner of 180 degrees will be taken.\n\x09   For example if the desired speed is 1000cm/s and the corner is at 90 degrees, this will result in\n\x09   a desired speed of 600cm/s. This value is overridden if using the advanced speed control method. */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The maximum speed that a corner of 180 degrees will be taken.\n         For example if the desired speed is 1000cm/s and the corner is at 90 degrees, this will result in\n         a desired speed of 600cm/s. This value is overridden if using the advanced speed control method." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_MaxCornerSpeed = { "MaxCornerSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, MaxCornerSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_MaxCornerSpeed_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_MaxCornerSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_AverageCornerSampleRange_MetaData[] = {
		{ "Category", "Slowdown|Advanced" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* How far ahead to sample path point corners to start the slow down, defaults to 200m\n\x09Increase this if the vehicle is emergency braking too much */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How far ahead to sample path point corners to start the slow down, defaults to 200m\n      Increase this if the vehicle is emergency braking too much" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_AverageCornerSampleRange = { "AverageCornerSampleRange", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, AverageCornerSampleRange), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_AverageCornerSampleRange_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_AverageCornerSampleRange_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckDetectionSampleCount_MetaData[] = {
		{ "Category", "Stuck Detection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Amount of samples in an array to use for stuck detection */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Amount of samples in an array to use for stuck detection" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckDetectionSampleCount = { "StuckDetectionSampleCount", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, StuckDetectionSampleCount), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckDetectionSampleCount_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckDetectionSampleCount_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseStuckDetection_MetaData[] = {
		{ "Category", "Stuck Detection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Enables detecting when this agent hasn't moved in a while, then executing the UnStuck code */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enables detecting when this agent hasn't moved in a while, then executing the UnStuck code" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseStuckDetection_SetBit(void* Obj)
	{
		((UVH_VehiclePathFollowingComponent*)Obj)->bUseStuckDetection = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseStuckDetection = { "bUseStuckDetection", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_VehiclePathFollowingComponent), &Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseStuckDetection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseStuckDetection_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseStuckDetection_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_UnStuckDistance_MetaData[] = {
		{ "Category", "Stuck Detection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Distance to try and move when stuck */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Distance to try and move when stuck" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_UnStuckDistance = { "UnStuckDistance", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, UnStuckDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_UnStuckDistance_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_UnStuckDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckDetectionDistance_MetaData[] = {
		{ "Category", "Stuck Detection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Distance at which the agent will be classified as stuck */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Distance at which the agent will be classified as stuck" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckDetectionDistance = { "StuckDetectionDistance", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, StuckDetectionDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckDetectionDistance_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckDetectionDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckAcceptanceRadius_MetaData[] = {
		{ "Category", "Stuck Detection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Distance at which to stop and recheck if stuck */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Distance at which to stop and recheck if stuck" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckAcceptanceRadius = { "StuckAcceptanceRadius", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, StuckAcceptanceRadius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckAcceptanceRadius_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckAcceptanceRadius_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckDetectionInterval_MetaData[] = {
		{ "Category", "Stuck Detection" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Time interval when to add to the stuck sample array */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Time interval when to add to the stuck sample array" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckDetectionInterval = { "StuckDetectionInterval", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, StuckDetectionInterval), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckDetectionInterval_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckDetectionInterval_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DetourCrowdSimulationState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DetourCrowdSimulationState_MetaData[] = {
		{ "Category", "Crowd Following" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Enables crowd simulation */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enables crowd simulation" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DetourCrowdSimulationState = { "DetourCrowdSimulationState", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, DetourCrowdSimulationState), Z_Construct_UEnum_VH_Vehicle_E_CrowdSimulationState, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DetourCrowdSimulationState_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DetourCrowdSimulationState_MetaData) }; // 252967047
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_CrowdAvoidanceRangeMultiplier_MetaData[] = {
		{ "Category", "Crowd Following" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Multiplies the range at which the crowd simulation will attempt to avoid obstacles, use this if the vehicle is crashing into obstacles during crowd simulation */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Multiplies the range at which the crowd simulation will attempt to avoid obstacles, use this if the vehicle is crashing into obstacles during crowd simulation" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_CrowdAvoidanceRangeMultiplier = { "CrowdAvoidanceRangeMultiplier", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, CrowdAvoidanceRangeMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_CrowdAvoidanceRangeMultiplier_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_CrowdAvoidanceRangeMultiplier_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehicleMaxSpeed_MetaData[] = {
		{ "Category", "Crowd Following" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The maximum speed this vehicle is able to get to. Used by crowd following for collision sampling */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The maximum speed this vehicle is able to get to. Used by crowd following for collision sampling" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehicleMaxSpeed = { "VehicleMaxSpeed", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, VehicleMaxSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehicleMaxSpeed_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehicleMaxSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ShouldReverseAngle_MetaData[] = {
		{ "Category", "Reverse" },
		{ "ClampMax", "180.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* If the angle to the target is greater than this, the vehicle will reverse to the target point */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If the angle to the target is greater than this, the vehicle will reverse to the target point" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ShouldReverseAngle = { "ShouldReverseAngle", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, ShouldReverseAngle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ShouldReverseAngle_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ShouldReverseAngle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ReverseMaxDistance_MetaData[] = {
		{ "Category", "Reverse" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* If the distance is lower than this then the vehicle will reverse to the target point */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If the distance is lower than this then the vehicle will reverse to the target point" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ReverseMaxDistance = { "ReverseMaxDistance", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, ReverseMaxDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ReverseMaxDistance_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ReverseMaxDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ReverseThreshold_MetaData[] = {
		{ "Category", "Reverse" },
		{ "ClampMax", "180.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Threshold to toggle the reverse state */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Threshold to toggle the reverse state" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ReverseThreshold = { "ReverseThreshold", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, ReverseThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ReverseThreshold_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ReverseThreshold_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bAutoReverse_MetaData[] = {
		{ "Category", "Reverse" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Allow the vehicle to automatically reverse whenever it meets the reverse conditions */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Allow the vehicle to automatically reverse whenever it meets the reverse conditions" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bAutoReverse_SetBit(void* Obj)
	{
		((UVH_VehiclePathFollowingComponent*)Obj)->bAutoReverse = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bAutoReverse = { "bAutoReverse", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_VehiclePathFollowingComponent), &Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bAutoReverse_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bAutoReverse_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bAutoReverse_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bOnlyReverseWhenStuck_MetaData[] = {
		{ "Category", "Reverse" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Only let this vehicle reverse when its in a stuck position, bAllowReverse must be set to true! */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Only let this vehicle reverse when its in a stuck position, bAllowReverse must be set to true!" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bOnlyReverseWhenStuck_SetBit(void* Obj)
	{
		((UVH_VehiclePathFollowingComponent*)Obj)->bOnlyReverseWhenStuck = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bOnlyReverseWhenStuck = { "bOnlyReverseWhenStuck", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_VehiclePathFollowingComponent), &Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bOnlyReverseWhenStuck_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bOnlyReverseWhenStuck_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bOnlyReverseWhenStuck_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SteeringMultiplier_MetaData[] = {
		{ "Category", "Steering" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* The muliplier used to increase steering based on on the size of the angle if there is no curve (normalised steering * multiplier) */" },
#endif
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "Use the Steering PID controller instead" },
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The muliplier used to increase steering based on on the size of the angle if there is no curve (normalised steering * multiplier)" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SteeringMultiplier = { "SteeringMultiplier", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, SteeringMultiplier), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SteeringMultiplier_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SteeringMultiplier_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SteeringCurve_MetaData[] = {
		{ "Category", "Steering" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* How steering output is adjusted based on the size of the angle. */" },
#endif
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "The steering curve is relatively complicated and unnecessary and will be removed, if you still want this functionality, implement this with the interface" },
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How steering output is adjusted based on the size of the angle." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SteeringCurve = { "SteeringCurve", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, SteeringCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SteeringCurve_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SteeringCurve_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bSteeringUsePID_MetaData[] = {
		{ "Category", "Steering" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Should steering use a PID controller, instead of any other method */" },
#endif
		{ "DeprecatedProperty", "" },
		{ "DeprecationMessage", "The steering will use the PID controller as default in a future version, the old method is just the proportional part of the PID controller" },
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Should steering use a PID controller, instead of any other method" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bSteeringUsePID_SetBit(void* Obj)
	{
		((UVH_VehiclePathFollowingComponent*)Obj)->bSteeringUsePID = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bSteeringUsePID = { "bSteeringUsePID", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_VehiclePathFollowingComponent), &Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bSteeringUsePID_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bSteeringUsePID_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bSteeringUsePID_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SteeringPIDSetup_MetaData[] = {
		{ "Category", "Steering" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Sets up each coefficient for the steering PID controller */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets up each coefficient for the steering PID controller" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SteeringPIDSetup = { "SteeringPIDSetup", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_VehiclePathFollowingComponent, SteeringPIDSetup), Z_Construct_UScriptStruct_FPIDCoefficients, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SteeringPIDSetup_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SteeringPIDSetup_MetaData) }; // 374115500
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bDebug_MetaData[] = {
		{ "Category", "Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Shows debug data on screen for this agent */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehiclePathFollowingComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Shows debug data on screen for this agent" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bDebug_SetBit(void* Obj)
	{
		((UVH_VehiclePathFollowingComponent*)Obj)->bDebug = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bDebug = { "bDebug", nullptr, (EPropertyFlags)0x0020080000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_VehiclePathFollowingComponent), &Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bDebug_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bDebug_MetaData), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bDebug_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseCustomAcceptanceRadius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehiclePathPointAcceptanceRadius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehicleNavLinkAcceptanceRadius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomSteering,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomThrottle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bCustomBrake,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_MinThrottle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StartingDesiredSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StartSpeedUnit_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StartSpeedUnit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThrottleStepMax,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThrottleStepMin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DesiredSpeedThrottleThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseBrakes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_BrakeThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_NormalisedTurnThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_BrakeAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_MaxEmergencyBrakeAmount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bThrottleUsePID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ThrottlePIDSetup,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseAdvancedSpeedControl,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_CornerSpeedControlPercentage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bAutoCalculateSlowdownDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehicleMass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StaticFrictionCoefficient,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_WorldGravity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bEnableSlowdown,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bSlowdownAtNavLinks,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SlowdownDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_CornerSlowdownSamples,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_MaxCornerSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_AverageCornerSampleRange,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckDetectionSampleCount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bUseStuckDetection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_UnStuckDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckDetectionDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckAcceptanceRadius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_StuckDetectionInterval,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DetourCrowdSimulationState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_DetourCrowdSimulationState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_CrowdAvoidanceRangeMultiplier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_VehicleMaxSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ShouldReverseAngle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ReverseMaxDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_ReverseThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bAutoReverse,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bOnlyReverseWhenStuck,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SteeringMultiplier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SteeringCurve,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bSteeringUsePID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_SteeringPIDSetup,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::NewProp_bDebug,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_VehiclePathFollowingComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::ClassParams = {
		&UVH_VehiclePathFollowingComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVH_VehiclePathFollowingComponent()
	{
		if (!Z_Registration_Info_UClass_UVH_VehiclePathFollowingComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_VehiclePathFollowingComponent.OuterSingleton, Z_Construct_UClass_UVH_VehiclePathFollowingComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_VehiclePathFollowingComponent.OuterSingleton;
	}
	template<> VH_VEHICLE_API UClass* StaticClass<UVH_VehiclePathFollowingComponent>()
	{
		return UVH_VehiclePathFollowingComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_VehiclePathFollowingComponent);
	UVH_VehiclePathFollowingComponent::~UVH_VehiclePathFollowingComponent() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_Statics::ScriptStructInfo[] = {
		{ FVehicleHandlingConfig::StaticStruct, Z_Construct_UScriptStruct_FVehicleHandlingConfig_Statics::NewStructOps, TEXT("VehicleHandlingConfig"), &Z_Registration_Info_UScriptStruct_VehicleHandlingConfig, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FVehicleHandlingConfig), 3961916097U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_VehiclePathFollowingComponent, UVH_VehiclePathFollowingComponent::StaticClass, TEXT("UVH_VehiclePathFollowingComponent"), &Z_Registration_Info_UClass_UVH_VehiclePathFollowingComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_VehiclePathFollowingComponent), 4245192835U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_2231946838(TEXT("/Script/VH_Vehicle"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehiclePathFollowingComponent_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
