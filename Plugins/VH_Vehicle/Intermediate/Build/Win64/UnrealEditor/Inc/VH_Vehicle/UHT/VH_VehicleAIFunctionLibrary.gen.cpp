// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_VehicleAIFunctionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_VehicleAIFunctionLibrary() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_AAIController_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_USplineComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_Vehicle();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UVH_VehicleAIFunctionLibrary();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UVH_VehicleAIFunctionLibrary_NoRegister();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UVH_VehiclePathFollowingComponent_NoRegister();
	VH_VEHICLE_API UEnum* Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed();
// End Cross Module References
	DEFINE_FUNCTION(UVH_VehicleAIFunctionLibrary::execFollowSplinePath)
	{
		P_GET_OBJECT(AAIController,Z_Param_AIController);
		P_GET_OBJECT(USplineComponent,Z_Param_Spline);
		P_GET_PROPERTY(FFloatProperty,Z_Param_SpaceBetweenParts);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UVH_VehicleAIFunctionLibrary::FollowSplinePath(Z_Param_AIController,Z_Param_Spline,Z_Param_SpaceBetweenParts);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehicleAIFunctionLibrary::execSetPathPoints)
	{
		P_GET_OBJECT(AAIController,Z_Param_AIController);
		P_GET_TARRAY(FVector,Z_Param_NewPathPoints);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UVH_VehicleAIFunctionLibrary::SetPathPoints(Z_Param_AIController,Z_Param_NewPathPoints);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehicleAIFunctionLibrary::execConvertToTankSteering)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_InSteering);
		P_GET_PROPERTY(FFloatProperty,Z_Param_InThrottle);
		P_GET_PROPERTY(FFloatProperty,Z_Param_TurnInPlaceThreshold);
		P_GET_PROPERTY(FFloatProperty,Z_Param_NormalTurnMultiplier);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutLeftTrack);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_OutRightTrack);
		P_FINISH;
		P_NATIVE_BEGIN;
		UVH_VehicleAIFunctionLibrary::ConvertToTankSteering(Z_Param_InSteering,Z_Param_InThrottle,Z_Param_TurnInPlaceThreshold,Z_Param_NormalTurnMultiplier,Z_Param_Out_OutLeftTrack,Z_Param_Out_OutRightTrack);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehicleAIFunctionLibrary::execConvertVelocityByUnit)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_InputVelocity);
		P_GET_ENUM(EUnitOfSpeed,Z_Param_InputVelocityType);
		P_GET_ENUM(EUnitOfSpeed,Z_Param_OutputVelocityType);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UVH_VehicleAIFunctionLibrary::ConvertVelocityByUnit(Z_Param_InputVelocity,EUnitOfSpeed(Z_Param_InputVelocityType),EUnitOfSpeed(Z_Param_OutputVelocityType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_VehicleAIFunctionLibrary::execGetVehiclePathFollowingComponent)
	{
		P_GET_OBJECT(APawn,Z_Param_Pawn);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UVH_VehiclePathFollowingComponent**)Z_Param__Result=UVH_VehicleAIFunctionLibrary::GetVehiclePathFollowingComponent(Z_Param_Pawn);
		P_NATIVE_END;
	}
	void UVH_VehicleAIFunctionLibrary::StaticRegisterNativesUVH_VehicleAIFunctionLibrary()
	{
		UClass* Class = UVH_VehicleAIFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ConvertToTankSteering", &UVH_VehicleAIFunctionLibrary::execConvertToTankSteering },
			{ "ConvertVelocityByUnit", &UVH_VehicleAIFunctionLibrary::execConvertVelocityByUnit },
			{ "FollowSplinePath", &UVH_VehicleAIFunctionLibrary::execFollowSplinePath },
			{ "GetVehiclePathFollowingComponent", &UVH_VehicleAIFunctionLibrary::execGetVehiclePathFollowingComponent },
			{ "SetPathPoints", &UVH_VehicleAIFunctionLibrary::execSetPathPoints },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics
	{
		struct VH_VehicleAIFunctionLibrary_eventConvertToTankSteering_Parms
		{
			float InSteering;
			float InThrottle;
			float TurnInPlaceThreshold;
			float NormalTurnMultiplier;
			float OutLeftTrack;
			float OutRightTrack;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_InSteering;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_InThrottle;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TurnInPlaceThreshold;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_NormalTurnMultiplier;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_OutLeftTrack;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_OutRightTrack;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::NewProp_InSteering = { "InSteering", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventConvertToTankSteering_Parms, InSteering), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::NewProp_InThrottle = { "InThrottle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventConvertToTankSteering_Parms, InThrottle), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::NewProp_TurnInPlaceThreshold = { "TurnInPlaceThreshold", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventConvertToTankSteering_Parms, TurnInPlaceThreshold), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::NewProp_NormalTurnMultiplier = { "NormalTurnMultiplier", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventConvertToTankSteering_Parms, NormalTurnMultiplier), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::NewProp_OutLeftTrack = { "OutLeftTrack", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventConvertToTankSteering_Parms, OutLeftTrack), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::NewProp_OutRightTrack = { "OutRightTrack", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventConvertToTankSteering_Parms, OutRightTrack), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::NewProp_InSteering,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::NewProp_InThrottle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::NewProp_TurnInPlaceThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::NewProp_NormalTurnMultiplier,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::NewProp_OutLeftTrack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::NewProp_OutRightTrack,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Converts the steering of a vehicle into one usable for a tank */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehicleAIFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Converts the steering of a vehicle into one usable for a tank" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehicleAIFunctionLibrary, nullptr, "ConvertToTankSteering", nullptr, nullptr, Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::VH_VehicleAIFunctionLibrary_eventConvertToTankSteering_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::VH_VehicleAIFunctionLibrary_eventConvertToTankSteering_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics
	{
		struct VH_VehicleAIFunctionLibrary_eventConvertVelocityByUnit_Parms
		{
			float InputVelocity;
			EUnitOfSpeed InputVelocityType;
			EUnitOfSpeed OutputVelocityType;
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_InputVelocity;
		static const UECodeGen_Private::FBytePropertyParams NewProp_InputVelocityType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_InputVelocityType;
		static const UECodeGen_Private::FBytePropertyParams NewProp_OutputVelocityType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_OutputVelocityType;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::NewProp_InputVelocity = { "InputVelocity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventConvertVelocityByUnit_Parms, InputVelocity), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::NewProp_InputVelocityType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::NewProp_InputVelocityType = { "InputVelocityType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventConvertVelocityByUnit_Parms, InputVelocityType), Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed, METADATA_PARAMS(0, nullptr) }; // 2057425959
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::NewProp_OutputVelocityType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::NewProp_OutputVelocityType = { "OutputVelocityType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventConvertVelocityByUnit_Parms, OutputVelocityType), Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed, METADATA_PARAMS(0, nullptr) }; // 2057425959
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventConvertVelocityByUnit_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::NewProp_InputVelocity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::NewProp_InputVelocityType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::NewProp_InputVelocityType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::NewProp_OutputVelocityType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::NewProp_OutputVelocityType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Converts the input velocity into the output velocity. Used to change between units of data */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehicleAIFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Converts the input velocity into the output velocity. Used to change between units of data" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehicleAIFunctionLibrary, nullptr, "ConvertVelocityByUnit", nullptr, nullptr, Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::VH_VehicleAIFunctionLibrary_eventConvertVelocityByUnit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::VH_VehicleAIFunctionLibrary_eventConvertVelocityByUnit_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics
	{
		struct VH_VehicleAIFunctionLibrary_eventFollowSplinePath_Parms
		{
			AAIController* AIController;
			USplineComponent* Spline;
			float SpaceBetweenParts;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AIController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Spline_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Spline;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SpaceBetweenParts;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::NewProp_AIController = { "AIController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventFollowSplinePath_Parms, AIController), Z_Construct_UClass_AAIController_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::NewProp_Spline_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::NewProp_Spline = { "Spline", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventFollowSplinePath_Parms, Spline), Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::NewProp_Spline_MetaData), Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::NewProp_Spline_MetaData) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::NewProp_SpaceBetweenParts = { "SpaceBetweenParts", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventFollowSplinePath_Parms, SpaceBetweenParts), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_VehicleAIFunctionLibrary_eventFollowSplinePath_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehicleAIFunctionLibrary_eventFollowSplinePath_Parms), &Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::NewProp_AIController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::NewProp_Spline,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::NewProp_SpaceBetweenParts,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Sets a path onto a spline that an agent can follow */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehicleAIFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets a path onto a spline that an agent can follow" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehicleAIFunctionLibrary, nullptr, "FollowSplinePath", nullptr, nullptr, Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::VH_VehicleAIFunctionLibrary_eventFollowSplinePath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::VH_VehicleAIFunctionLibrary_eventFollowSplinePath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics
	{
		struct VH_VehicleAIFunctionLibrary_eventGetVehiclePathFollowingComponent_Parms
		{
			APawn* Pawn;
			UVH_VehiclePathFollowingComponent* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Pawn;
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::NewProp_Pawn = { "Pawn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventGetVehiclePathFollowingComponent_Parms, Pawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventGetVehiclePathFollowingComponent_Parms, ReturnValue), Z_Construct_UClass_UVH_VehiclePathFollowingComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::NewProp_Pawn,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Helper function that returns the path following component from a provided pawn by getting the controller and its path following component. */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehicleAIFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Helper function that returns the path following component from a provided pawn by getting the controller and its path following component." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehicleAIFunctionLibrary, nullptr, "GetVehiclePathFollowingComponent", nullptr, nullptr, Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::VH_VehicleAIFunctionLibrary_eventGetVehiclePathFollowingComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::VH_VehicleAIFunctionLibrary_eventGetVehiclePathFollowingComponent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics
	{
		struct VH_VehicleAIFunctionLibrary_eventSetPathPoints_Parms
		{
			AAIController* AIController;
			TArray<FVector> NewPathPoints;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AIController;
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewPathPoints_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_NewPathPoints;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::NewProp_AIController = { "AIController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventSetPathPoints_Parms, AIController), Z_Construct_UClass_AAIController_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::NewProp_NewPathPoints_Inner = { "NewPathPoints", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::NewProp_NewPathPoints = { "NewPathPoints", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIFunctionLibrary_eventSetPathPoints_Parms, NewPathPoints), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_VehicleAIFunctionLibrary_eventSetPathPoints_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehicleAIFunctionLibrary_eventSetPathPoints_Parms), &Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::NewProp_AIController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::NewProp_NewPathPoints_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::NewProp_NewPathPoints,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::Function_MetaDataParams[] = {
		{ "Category", "Vehicle AI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Manually sets path points for the current path on an AI controller */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehicleAIFunctionLibrary.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Manually sets path points for the current path on an AI controller" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_VehicleAIFunctionLibrary, nullptr, "SetPathPoints", nullptr, nullptr, Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::VH_VehicleAIFunctionLibrary_eventSetPathPoints_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::VH_VehicleAIFunctionLibrary_eventSetPathPoints_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_VehicleAIFunctionLibrary);
	UClass* Z_Construct_UClass_UVH_VehicleAIFunctionLibrary_NoRegister()
	{
		return UVH_VehicleAIFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UVH_VehicleAIFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_VehicleAIFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Vehicle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehicleAIFunctionLibrary_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_VehicleAIFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertToTankSteering, "ConvertToTankSteering" }, // 3071131194
		{ &Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_ConvertVelocityByUnit, "ConvertVelocityByUnit" }, // 796878987
		{ &Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_FollowSplinePath, "FollowSplinePath" }, // 1659631849
		{ &Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_GetVehiclePathFollowingComponent, "GetVehiclePathFollowingComponent" }, // 3603191215
		{ &Z_Construct_UFunction_UVH_VehicleAIFunctionLibrary_SetPathPoints, "SetPathPoints" }, // 285013264
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehicleAIFunctionLibrary_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_VehicleAIFunctionLibrary_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "AI/Public/VH_VehicleAIFunctionLibrary.h" },
		{ "ModuleRelativePath", "AI/Public/VH_VehicleAIFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_VehicleAIFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_VehicleAIFunctionLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_VehicleAIFunctionLibrary_Statics::ClassParams = {
		&UVH_VehicleAIFunctionLibrary::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_VehicleAIFunctionLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_VehicleAIFunctionLibrary_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UVH_VehicleAIFunctionLibrary()
	{
		if (!Z_Registration_Info_UClass_UVH_VehicleAIFunctionLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_VehicleAIFunctionLibrary.OuterSingleton, Z_Construct_UClass_UVH_VehicleAIFunctionLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_VehicleAIFunctionLibrary.OuterSingleton;
	}
	template<> VH_VEHICLE_API UClass* StaticClass<UVH_VehicleAIFunctionLibrary>()
	{
		return UVH_VehicleAIFunctionLibrary::StaticClass();
	}
	UVH_VehicleAIFunctionLibrary::UVH_VehicleAIFunctionLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_VehicleAIFunctionLibrary);
	UVH_VehicleAIFunctionLibrary::~UVH_VehicleAIFunctionLibrary() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_VehicleAIFunctionLibrary, UVH_VehicleAIFunctionLibrary::StaticClass, TEXT("UVH_VehicleAIFunctionLibrary"), &Z_Registration_Info_UClass_UVH_VehicleAIFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_VehicleAIFunctionLibrary), 2502517279U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_2922148616(TEXT("/Script/VH_Vehicle"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIFunctionLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
