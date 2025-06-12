// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Core/Public/VH_VehicleAIInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_VehicleAIInterface() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	UPackage* Z_Construct_UPackage__Script_VH_Vehicle();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UVH_VehicleAIInterface();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UVH_VehicleAIInterface_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(IVH_VehicleAIInterface::execOnVehicleStuck)
	{
		P_GET_STRUCT_REF(FVector,Z_Param_Out_UnStuckLocation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->OnVehicleStuck_Implementation(Z_Param_Out_UnStuckLocation);
		P_NATIVE_END;
	}
	struct VH_VehicleAIInterface_eventCustomBraking_Parms
	{
		float TargetAngle;
		float DestinationDistance;
		float DesiredSpeed;
		float CalculatedBrake;
	};
	struct VH_VehicleAIInterface_eventCustomSteering_Parms
	{
		float TargetAngle;
		float Steering;
		float DestinationDistance;
	};
	struct VH_VehicleAIInterface_eventCustomThrottle_Parms
	{
		float TargetAngle;
		float DestinationDistance;
		float DesiredSpeed;
		float CalculatedThrottle;
	};
	struct VH_VehicleAIInterface_eventOnVehicleStuck_Parms
	{
		FVector UnStuckLocation;
		bool ReturnValue;

		/** Constructor, initializes return property only **/
		VH_VehicleAIInterface_eventOnVehicleStuck_Parms()
			: ReturnValue(false)
		{
		}
	};
	void IVH_VehicleAIInterface::CustomBraking(float TargetAngle, float DestinationDistance, float DesiredSpeed, float CalculatedBrake)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CustomBraking instead.");
	}
	void IVH_VehicleAIInterface::CustomSteering(float TargetAngle, float Steering, float DestinationDistance)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CustomSteering instead.");
	}
	void IVH_VehicleAIInterface::CustomThrottle(float TargetAngle, float DestinationDistance, float DesiredSpeed, float CalculatedThrottle)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_CustomThrottle instead.");
	}
	bool IVH_VehicleAIInterface::OnVehicleStuck(FVector& UnStuckLocation)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_OnVehicleStuck instead.");
		VH_VehicleAIInterface_eventOnVehicleStuck_Parms Parms;
		return Parms.ReturnValue;
	}
	void UVH_VehicleAIInterface::StaticRegisterNativesUVH_VehicleAIInterface()
	{
		UClass* Class = UVH_VehicleAIInterface::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnVehicleStuck", &IVH_VehicleAIInterface::execOnVehicleStuck },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TargetAngle;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DestinationDistance;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DesiredSpeed;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CalculatedBrake;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::NewProp_TargetAngle = { "TargetAngle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIInterface_eventCustomBraking_Parms, TargetAngle), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::NewProp_DestinationDistance = { "DestinationDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIInterface_eventCustomBraking_Parms, DestinationDistance), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::NewProp_DesiredSpeed = { "DesiredSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIInterface_eventCustomBraking_Parms, DesiredSpeed), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::NewProp_CalculatedBrake = { "CalculatedBrake", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIInterface_eventCustomBraking_Parms, CalculatedBrake), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::NewProp_TargetAngle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::NewProp_DestinationDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::NewProp_DesiredSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::NewProp_CalculatedBrake,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Called to implement custom braking behavior\n\x09* @param TargetAngle - Angle towards the target move location\n\x09* @param DestinationDistance - Distance to the current move destination\n\x09* @param DesiredSpeed - The adjusted desired speed\n\x09* @param CalculatedThrottle - The throttle thats been calculated, this is whats normally used by the system internally\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/VH_VehicleAIInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Called to implement custom braking behavior\n* @param TargetAngle - Angle towards the target move location\n* @param DestinationDistance - Distance to the current move destination\n* @param DesiredSpeed - The adjusted desired speed\n* @param CalculatedThrottle - The throttle thats been calculated, this is whats normally used by the system internally" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehicleAIInterface, nullptr, "CustomBraking", nullptr, nullptr, Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::PropPointers), sizeof(VH_VehicleAIInterface_eventCustomBraking_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_VehicleAIInterface_eventCustomBraking_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TargetAngle;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Steering;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DestinationDistance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering_Statics::NewProp_TargetAngle = { "TargetAngle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIInterface_eventCustomSteering_Parms, TargetAngle), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering_Statics::NewProp_Steering = { "Steering", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIInterface_eventCustomSteering_Parms, Steering), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering_Statics::NewProp_DestinationDistance = { "DestinationDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIInterface_eventCustomSteering_Parms, DestinationDistance), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering_Statics::NewProp_TargetAngle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering_Statics::NewProp_Steering,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering_Statics::NewProp_DestinationDistance,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Called to implement custom steering behavior\n\x09* @param TargetAngle - Angle towards the target move location\n\x09* @param Steering - Normalized adjusted steering angle, this is whats normally used by the system internally\n\x09* @param DestinationDistance - Distance to the current move destination\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/VH_VehicleAIInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Called to implement custom steering behavior\n* @param TargetAngle - Angle towards the target move location\n* @param Steering - Normalized adjusted steering angle, this is whats normally used by the system internally\n* @param DestinationDistance - Distance to the current move destination" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehicleAIInterface, nullptr, "CustomSteering", nullptr, nullptr, Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering_Statics::PropPointers), sizeof(VH_VehicleAIInterface_eventCustomSteering_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_VehicleAIInterface_eventCustomSteering_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TargetAngle;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DestinationDistance;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DesiredSpeed;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CalculatedThrottle;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::NewProp_TargetAngle = { "TargetAngle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIInterface_eventCustomThrottle_Parms, TargetAngle), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::NewProp_DestinationDistance = { "DestinationDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIInterface_eventCustomThrottle_Parms, DestinationDistance), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::NewProp_DesiredSpeed = { "DesiredSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIInterface_eventCustomThrottle_Parms, DesiredSpeed), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::NewProp_CalculatedThrottle = { "CalculatedThrottle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIInterface_eventCustomThrottle_Parms, CalculatedThrottle), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::NewProp_TargetAngle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::NewProp_DestinationDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::NewProp_DesiredSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::NewProp_CalculatedThrottle,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Called to implement custom steering behavior\n\x09* @param TargetAngle - Angle towards the target move location\n\x09* @param DestinationDistance - Distance to the current move destination\n\x09* @param DesiredSpeed - The adjusted desired speed\n\x09* @param CalculatedThrottle - The throttle thats been calculated, this is whats normally used by the system internally\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/VH_VehicleAIInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Called to implement custom steering behavior\n* @param TargetAngle - Angle towards the target move location\n* @param DestinationDistance - Distance to the current move destination\n* @param DesiredSpeed - The adjusted desired speed\n* @param CalculatedThrottle - The throttle thats been calculated, this is whats normally used by the system internally" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehicleAIInterface, nullptr, "CustomThrottle", nullptr, nullptr, Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::PropPointers), sizeof(VH_VehicleAIInterface_eventCustomThrottle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_VehicleAIInterface_eventCustomThrottle_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_UnStuckLocation;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck_Statics::NewProp_UnStuckLocation = { "UnStuckLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIInterface_eventOnVehicleStuck_Parms, UnStuckLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_VehicleAIInterface_eventOnVehicleStuck_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehicleAIInterface_eventOnVehicleStuck_Parms), &Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck_Statics::NewProp_UnStuckLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \n\x09* Called when the vehicle gets stuck according to the stuck detection\n\x09* @param UnStuckLocation - The location we want to move to, to get this actor unstuck, this is for simple unstuck custom behavior\n\x09* @return true will keep the vehicle in a stuck state until you manually notify. False (default) will handle the stuck behavior internally\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/VH_VehicleAIInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Called when the vehicle gets stuck according to the stuck detection\n* @param UnStuckLocation - The location we want to move to, to get this actor unstuck, this is for simple unstuck custom behavior\n* @return true will keep the vehicle in a stuck state until you manually notify. False (default) will handle the stuck behavior internally" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehicleAIInterface, nullptr, "OnVehicleStuck", nullptr, nullptr, Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck_Statics::PropPointers), sizeof(VH_VehicleAIInterface_eventOnVehicleStuck_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08C20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_VehicleAIInterface_eventOnVehicleStuck_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_VehicleAIInterface);
	UClass* Z_Construct_UClass_UVH_VehicleAIInterface_NoRegister()
	{
		return UVH_VehicleAIInterface::StaticClass();
	}
	struct Z_Construct_UClass_UVH_VehicleAIInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_VehicleAIInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Vehicle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehicleAIInterface_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_VehicleAIInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVH_VehicleAIInterface_CustomBraking, "CustomBraking" }, // 4158743657
		{ &Z_Construct_UFunction_UVH_VehicleAIInterface_CustomSteering, "CustomSteering" }, // 3381146451
		{ &Z_Construct_UFunction_UVH_VehicleAIInterface_CustomThrottle, "CustomThrottle" }, // 3588695975
		{ &Z_Construct_UFunction_UVH_VehicleAIInterface_OnVehicleStuck, "OnVehicleStuck" }, // 707258972
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehicleAIInterface_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehicleAIInterface_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Public/VH_VehicleAIInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_VehicleAIInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IVH_VehicleAIInterface>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_VehicleAIInterface_Statics::ClassParams = {
		&UVH_VehicleAIInterface::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001040A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehicleAIInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_VehicleAIInterface_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UVH_VehicleAIInterface()
	{
		if (!Z_Registration_Info_UClass_UVH_VehicleAIInterface.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_VehicleAIInterface.OuterSingleton, Z_Construct_UClass_UVH_VehicleAIInterface_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_VehicleAIInterface.OuterSingleton;
	}
	template<> VH_VEHICLE_API UClass* StaticClass<UVH_VehicleAIInterface>()
	{
		return UVH_VehicleAIInterface::StaticClass();
	}
	UVH_VehicleAIInterface::UVH_VehicleAIInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_VehicleAIInterface);
	UVH_VehicleAIInterface::~UVH_VehicleAIInterface() {}
	static FName NAME_UVH_VehicleAIInterface_CustomBraking = FName(TEXT("CustomBraking"));
	void IVH_VehicleAIInterface::Execute_CustomBraking(UObject* O, float TargetAngle, float DestinationDistance, float DesiredSpeed, float CalculatedBrake)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UVH_VehicleAIInterface::StaticClass()));
		VH_VehicleAIInterface_eventCustomBraking_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UVH_VehicleAIInterface_CustomBraking);
		if (Func)
		{
			Parms.TargetAngle=TargetAngle;
			Parms.DestinationDistance=DestinationDistance;
			Parms.DesiredSpeed=DesiredSpeed;
			Parms.CalculatedBrake=CalculatedBrake;
			O->ProcessEvent(Func, &Parms);
		}
	}
	static FName NAME_UVH_VehicleAIInterface_CustomSteering = FName(TEXT("CustomSteering"));
	void IVH_VehicleAIInterface::Execute_CustomSteering(UObject* O, float TargetAngle, float Steering, float DestinationDistance)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UVH_VehicleAIInterface::StaticClass()));
		VH_VehicleAIInterface_eventCustomSteering_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UVH_VehicleAIInterface_CustomSteering);
		if (Func)
		{
			Parms.TargetAngle=TargetAngle;
			Parms.Steering=Steering;
			Parms.DestinationDistance=DestinationDistance;
			O->ProcessEvent(Func, &Parms);
		}
	}
	static FName NAME_UVH_VehicleAIInterface_CustomThrottle = FName(TEXT("CustomThrottle"));
	void IVH_VehicleAIInterface::Execute_CustomThrottle(UObject* O, float TargetAngle, float DestinationDistance, float DesiredSpeed, float CalculatedThrottle)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UVH_VehicleAIInterface::StaticClass()));
		VH_VehicleAIInterface_eventCustomThrottle_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UVH_VehicleAIInterface_CustomThrottle);
		if (Func)
		{
			Parms.TargetAngle=TargetAngle;
			Parms.DestinationDistance=DestinationDistance;
			Parms.DesiredSpeed=DesiredSpeed;
			Parms.CalculatedThrottle=CalculatedThrottle;
			O->ProcessEvent(Func, &Parms);
		}
	}
	static FName NAME_UVH_VehicleAIInterface_OnVehicleStuck = FName(TEXT("OnVehicleStuck"));
	bool IVH_VehicleAIInterface::Execute_OnVehicleStuck(UObject* O, FVector& UnStuckLocation)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UVH_VehicleAIInterface::StaticClass()));
		VH_VehicleAIInterface_eventOnVehicleStuck_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UVH_VehicleAIInterface_OnVehicleStuck);
		if (Func)
		{
			Parms.UnStuckLocation=UnStuckLocation;
			O->ProcessEvent(Func, &Parms);
			UnStuckLocation=Parms.UnStuckLocation;
		}
		else if (auto I = (IVH_VehicleAIInterface*)(O->GetNativeInterfaceAddress(UVH_VehicleAIInterface::StaticClass())))
		{
			Parms.ReturnValue = I->OnVehicleStuck_Implementation(UnStuckLocation);
		}
		return Parms.ReturnValue;
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_VehicleAIInterface, UVH_VehicleAIInterface::StaticClass, TEXT("UVH_VehicleAIInterface"), &Z_Registration_Info_UClass_UVH_VehicleAIInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_VehicleAIInterface), 1234054905U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_2747304598(TEXT("/Script/VH_Vehicle"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Core_Public_VH_VehicleAIInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
