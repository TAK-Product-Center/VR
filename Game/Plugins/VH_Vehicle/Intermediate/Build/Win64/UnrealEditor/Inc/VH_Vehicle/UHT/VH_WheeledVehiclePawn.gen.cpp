// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../WheeledVehicle/Public/VH_WheeledVehiclePawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_WheeledVehiclePawn() {}
// Cross Module References
	CHAOSVEHICLES_API UClass* Z_Construct_UClass_AWheeledVehiclePawn();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UAudioComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponent2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpotLightComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTextRenderComponent_NoRegister();
	PHYSICSCORE_API UClass* Z_Construct_UClass_UPhysicalMaterial_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_Vehicle();
	VH_VEHICLE_API UClass* Z_Construct_UClass_AVH_WheeledVehiclePawn();
	VH_VEHICLE_API UClass* Z_Construct_UClass_AVH_WheeledVehiclePawn_NoRegister();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UVH_VehicleAIInterface_NoRegister();
	VH_VEHICLE_API UEnum* Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed();
// End Cross Module References
	DEFINE_FUNCTION(AVH_WheeledVehiclePawn::execSetLeadVehicleFollowPoints)
	{
		P_GET_TARRAY_REF(FVector,Z_Param_Out_worldLocations);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLeadVehicleFollowPoints(Z_Param_Out_worldLocations);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehiclePawn::execGetEngineSoundComponent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UAudioComponent**)Z_Param__Result=P_THIS->GetEngineSoundComponent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehiclePawn::execGetInCarGear)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UTextRenderComponent**)Z_Param__Result=P_THIS->GetInCarGear();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehiclePawn::execGetInCarSpeed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UTextRenderComponent**)Z_Param__Result=P_THIS->GetInCarSpeed();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehiclePawn::execGetSteeringWheel)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UStaticMeshComponent**)Z_Param__Result=P_THIS->GetSteeringWheel();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehiclePawn::execGetInternalCamera)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UCameraComponent**)Z_Param__Result=P_THIS->GetInternalCamera();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehiclePawn::execGetCamera)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UCameraComponent**)Z_Param__Result=P_THIS->GetCamera();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehiclePawn::execGetSpringArm)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USpringArmComponent**)Z_Param__Result=P_THIS->GetSpringArm();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehiclePawn::execTeleportLeadVehicleToRoute)
	{
		P_GET_STRUCT(FTransform,Z_Param_playerTransform);
		P_GET_UBOOL(Z_Param_matchPlayerRotation);
		P_GET_PROPERTY(FFloatProperty,Z_Param_desiredDistanceToPlayer);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->TeleportLeadVehicleToRoute(Z_Param_playerTransform,Z_Param_matchPlayerRotation,Z_Param_desiredDistanceToPlayer);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehiclePawn::execGetMaxDrivingSpeed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetMaxDrivingSpeed();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehiclePawn::execSetMaxDrivingSpeed)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_inSpeed);
		P_GET_ENUM(EUnitOfSpeed,Z_Param_inUnit);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMaxDrivingSpeed(Z_Param_inSpeed,EUnitOfSpeed(Z_Param_inUnit));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_WheeledVehiclePawn::execSetHeadlightsEnabled)
	{
		P_GET_UBOOL(Z_Param_inEnabled);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetHeadlightsEnabled(Z_Param_inEnabled);
		P_NATIVE_END;
	}
	struct VH_WheeledVehiclePawn_eventGetLeftSceneCaptureComponent_Parms
	{
		USceneCaptureComponent2D* ReturnValue;

		/** Constructor, initializes return property only **/
		VH_WheeledVehiclePawn_eventGetLeftSceneCaptureComponent_Parms()
			: ReturnValue(NULL)
		{
		}
	};
	struct VH_WheeledVehiclePawn_eventGetRightSceneCaptureComponent_Parms
	{
		USceneCaptureComponent2D* ReturnValue;

		/** Constructor, initializes return property only **/
		VH_WheeledVehiclePawn_eventGetRightSceneCaptureComponent_Parms()
			: ReturnValue(NULL)
		{
		}
	};
	static FName NAME_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent = FName(TEXT("GetLeftSceneCaptureComponent"));
	USceneCaptureComponent2D* AVH_WheeledVehiclePawn::GetLeftSceneCaptureComponent() const
	{
		VH_WheeledVehiclePawn_eventGetLeftSceneCaptureComponent_Parms Parms;
		const_cast<AVH_WheeledVehiclePawn*>(this)->ProcessEvent(FindFunctionChecked(NAME_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent = FName(TEXT("GetRightSceneCaptureComponent"));
	USceneCaptureComponent2D* AVH_WheeledVehiclePawn::GetRightSceneCaptureComponent() const
	{
		VH_WheeledVehiclePawn_eventGetRightSceneCaptureComponent_Parms Parms;
		const_cast<AVH_WheeledVehiclePawn*>(this)->ProcessEvent(FindFunctionChecked(NAME_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent),&Parms);
		return Parms.ReturnValue;
	}
	void AVH_WheeledVehiclePawn::StaticRegisterNativesAVH_WheeledVehiclePawn()
	{
		UClass* Class = AVH_WheeledVehiclePawn::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCamera", &AVH_WheeledVehiclePawn::execGetCamera },
			{ "GetEngineSoundComponent", &AVH_WheeledVehiclePawn::execGetEngineSoundComponent },
			{ "GetInCarGear", &AVH_WheeledVehiclePawn::execGetInCarGear },
			{ "GetInCarSpeed", &AVH_WheeledVehiclePawn::execGetInCarSpeed },
			{ "GetInternalCamera", &AVH_WheeledVehiclePawn::execGetInternalCamera },
			{ "GetMaxDrivingSpeed", &AVH_WheeledVehiclePawn::execGetMaxDrivingSpeed },
			{ "GetSpringArm", &AVH_WheeledVehiclePawn::execGetSpringArm },
			{ "GetSteeringWheel", &AVH_WheeledVehiclePawn::execGetSteeringWheel },
			{ "SetHeadlightsEnabled", &AVH_WheeledVehiclePawn::execSetHeadlightsEnabled },
			{ "SetLeadVehicleFollowPoints", &AVH_WheeledVehiclePawn::execSetLeadVehicleFollowPoints },
			{ "SetMaxDrivingSpeed", &AVH_WheeledVehiclePawn::execSetMaxDrivingSpeed },
			{ "TeleportLeadVehicleToRoute", &AVH_WheeledVehiclePawn::execTeleportLeadVehicleToRoute },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics
	{
		struct VH_WheeledVehiclePawn_eventGetCamera_Parms
		{
			UCameraComponent* ReturnValue;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehiclePawn_eventGetCamera_Parms, ReturnValue), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics::Function_MetaDataParams[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns Camera subobject **/" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns Camera subobject *" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehiclePawn, nullptr, "GetCamera", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics::VH_WheeledVehiclePawn_eventGetCamera_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics::VH_WheeledVehiclePawn_eventGetCamera_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics
	{
		struct VH_WheeledVehiclePawn_eventGetEngineSoundComponent_Parms
		{
			UAudioComponent* ReturnValue;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehiclePawn_eventGetEngineSoundComponent_Parms, ReturnValue), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns EngineSoundComponent subobject **/" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns EngineSoundComponent subobject *" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehiclePawn, nullptr, "GetEngineSoundComponent", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics::VH_WheeledVehiclePawn_eventGetEngineSoundComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics::VH_WheeledVehiclePawn_eventGetEngineSoundComponent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics
	{
		struct VH_WheeledVehiclePawn_eventGetInCarGear_Parms
		{
			UTextRenderComponent* ReturnValue;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehiclePawn_eventGetInCarGear_Parms, ReturnValue), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics::Function_MetaDataParams[] = {
		{ "Category", "Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns InCarGear subobject **/" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns InCarGear subobject *" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehiclePawn, nullptr, "GetInCarGear", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics::VH_WheeledVehiclePawn_eventGetInCarGear_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics::VH_WheeledVehiclePawn_eventGetInCarGear_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics
	{
		struct VH_WheeledVehiclePawn_eventGetInCarSpeed_Parms
		{
			UTextRenderComponent* ReturnValue;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehiclePawn_eventGetInCarSpeed_Parms, ReturnValue), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns InCarSpeed subobject **/" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns InCarSpeed subobject *" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehiclePawn, nullptr, "GetInCarSpeed", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics::VH_WheeledVehiclePawn_eventGetInCarSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics::VH_WheeledVehiclePawn_eventGetInCarSpeed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics
	{
		struct VH_WheeledVehiclePawn_eventGetInternalCamera_Parms
		{
			UCameraComponent* ReturnValue;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehiclePawn_eventGetInternalCamera_Parms, ReturnValue), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics::Function_MetaDataParams[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns InternalCamera subobject **/" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns InternalCamera subobject *" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehiclePawn, nullptr, "GetInternalCamera", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics::VH_WheeledVehiclePawn_eventGetInternalCamera_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics::VH_WheeledVehiclePawn_eventGetInternalCamera_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent_Statics
	{
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehiclePawn_eventGetLeftSceneCaptureComponent_Parms, ReturnValue), Z_Construct_UClass_USceneCaptureComponent2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehiclePawn, nullptr, "GetLeftSceneCaptureComponent", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent_Statics::PropPointers), sizeof(VH_WheeledVehiclePawn_eventGetLeftSceneCaptureComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_WheeledVehiclePawn_eventGetLeftSceneCaptureComponent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetMaxDrivingSpeed_Statics
	{
		struct VH_WheeledVehiclePawn_eventGetMaxDrivingSpeed_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetMaxDrivingSpeed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehiclePawn_eventGetMaxDrivingSpeed_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetMaxDrivingSpeed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetMaxDrivingSpeed_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetMaxDrivingSpeed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetMaxDrivingSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehiclePawn, nullptr, "GetMaxDrivingSpeed", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetMaxDrivingSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetMaxDrivingSpeed_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetMaxDrivingSpeed_Statics::VH_WheeledVehiclePawn_eventGetMaxDrivingSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetMaxDrivingSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetMaxDrivingSpeed_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetMaxDrivingSpeed_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetMaxDrivingSpeed_Statics::VH_WheeledVehiclePawn_eventGetMaxDrivingSpeed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetMaxDrivingSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetMaxDrivingSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent_Statics
	{
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehiclePawn_eventGetRightSceneCaptureComponent_Parms, ReturnValue), Z_Construct_UClass_USceneCaptureComponent2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehiclePawn, nullptr, "GetRightSceneCaptureComponent", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent_Statics::PropPointers), sizeof(VH_WheeledVehiclePawn_eventGetRightSceneCaptureComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_WheeledVehiclePawn_eventGetRightSceneCaptureComponent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics
	{
		struct VH_WheeledVehiclePawn_eventGetSpringArm_Parms
		{
			USpringArmComponent* ReturnValue;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehiclePawn_eventGetSpringArm_Parms, ReturnValue), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics::Function_MetaDataParams[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns SpringArm subobject **/" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns SpringArm subobject *" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehiclePawn, nullptr, "GetSpringArm", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics::VH_WheeledVehiclePawn_eventGetSpringArm_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics::VH_WheeledVehiclePawn_eventGetSpringArm_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics
	{
		struct VH_WheeledVehiclePawn_eventGetSteeringWheel_Parms
		{
			UStaticMeshComponent* ReturnValue;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehiclePawn_eventGetSteeringWheel_Parms, ReturnValue), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics::Function_MetaDataParams[] = {
		{ "Category", "Steering" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Returns steering wheel mesh subobject **/" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns steering wheel mesh subobject *" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehiclePawn, nullptr, "GetSteeringWheel", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics::VH_WheeledVehiclePawn_eventGetSteeringWheel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics::VH_WheeledVehiclePawn_eventGetSteeringWheel_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled_Statics
	{
		struct VH_WheeledVehiclePawn_eventSetHeadlightsEnabled_Parms
		{
			bool inEnabled;
		};
		static void NewProp_inEnabled_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_inEnabled;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled_Statics::NewProp_inEnabled_SetBit(void* Obj)
	{
		((VH_WheeledVehiclePawn_eventSetHeadlightsEnabled_Parms*)Obj)->inEnabled = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled_Statics::NewProp_inEnabled = { "inEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_WheeledVehiclePawn_eventSetHeadlightsEnabled_Parms), &Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled_Statics::NewProp_inEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled_Statics::NewProp_inEnabled,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehiclePawn, nullptr, "SetHeadlightsEnabled", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled_Statics::VH_WheeledVehiclePawn_eventSetHeadlightsEnabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled_Statics::VH_WheeledVehiclePawn_eventSetHeadlightsEnabled_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics
	{
		struct VH_WheeledVehiclePawn_eventSetLeadVehicleFollowPoints_Parms
		{
			TArray<FVector> worldLocations;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_worldLocations_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_worldLocations_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_worldLocations;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::NewProp_worldLocations_Inner = { "worldLocations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::NewProp_worldLocations_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::NewProp_worldLocations = { "worldLocations", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehiclePawn_eventSetLeadVehicleFollowPoints_Parms, worldLocations), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::NewProp_worldLocations_MetaData), Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::NewProp_worldLocations_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::NewProp_worldLocations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::NewProp_worldLocations,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehiclePawn, nullptr, "SetLeadVehicleFollowPoints", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::VH_WheeledVehiclePawn_eventSetLeadVehicleFollowPoints_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::VH_WheeledVehiclePawn_eventSetLeadVehicleFollowPoints_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics
	{
		struct VH_WheeledVehiclePawn_eventSetMaxDrivingSpeed_Parms
		{
			float inSpeed;
			EUnitOfSpeed inUnit;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_inSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_inSpeed;
		static const UECodeGen_Private::FBytePropertyParams NewProp_inUnit_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_inUnit_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_inUnit;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::NewProp_inSpeed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::NewProp_inSpeed = { "inSpeed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehiclePawn_eventSetMaxDrivingSpeed_Parms, inSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::NewProp_inSpeed_MetaData), Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::NewProp_inSpeed_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::NewProp_inUnit_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::NewProp_inUnit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::NewProp_inUnit = { "inUnit", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehiclePawn_eventSetMaxDrivingSpeed_Parms, inUnit), Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::NewProp_inUnit_MetaData), Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::NewProp_inUnit_MetaData) }; // 2057425959
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::NewProp_inSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::NewProp_inUnit_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::NewProp_inUnit,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehiclePawn, nullptr, "SetMaxDrivingSpeed", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::VH_WheeledVehiclePawn_eventSetMaxDrivingSpeed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::VH_WheeledVehiclePawn_eventSetMaxDrivingSpeed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics
	{
		struct VH_WheeledVehiclePawn_eventTeleportLeadVehicleToRoute_Parms
		{
			FTransform playerTransform;
			bool matchPlayerRotation;
			float desiredDistanceToPlayer;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_playerTransform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_playerTransform;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_matchPlayerRotation_MetaData[];
#endif
		static void NewProp_matchPlayerRotation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_matchPlayerRotation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_desiredDistanceToPlayer_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_desiredDistanceToPlayer;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_playerTransform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_playerTransform = { "playerTransform", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehiclePawn_eventTeleportLeadVehicleToRoute_Parms, playerTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_playerTransform_MetaData), Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_playerTransform_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_matchPlayerRotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_matchPlayerRotation_SetBit(void* Obj)
	{
		((VH_WheeledVehiclePawn_eventTeleportLeadVehicleToRoute_Parms*)Obj)->matchPlayerRotation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_matchPlayerRotation = { "matchPlayerRotation", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_WheeledVehiclePawn_eventTeleportLeadVehicleToRoute_Parms), &Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_matchPlayerRotation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_matchPlayerRotation_MetaData), Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_matchPlayerRotation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_desiredDistanceToPlayer_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_desiredDistanceToPlayer = { "desiredDistanceToPlayer", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_WheeledVehiclePawn_eventTeleportLeadVehicleToRoute_Parms, desiredDistanceToPlayer), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_desiredDistanceToPlayer_MetaData), Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_desiredDistanceToPlayer_MetaData) };
	void Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_WheeledVehiclePawn_eventTeleportLeadVehicleToRoute_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_WheeledVehiclePawn_eventTeleportLeadVehicleToRoute_Parms), &Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_playerTransform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_matchPlayerRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_desiredDistanceToPlayer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_WheeledVehiclePawn, nullptr, "TeleportLeadVehicleToRoute", nullptr, nullptr, Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::PropPointers), sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::VH_WheeledVehiclePawn_eventTeleportLeadVehicleToRoute_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::VH_WheeledVehiclePawn_eventTeleportLeadVehicleToRoute_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVH_WheeledVehiclePawn);
	UClass* Z_Construct_UClass_AVH_WheeledVehiclePawn_NoRegister()
	{
		return AVH_WheeledVehiclePawn::StaticClass();
	}
	struct Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InternalCameraBase_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InternalCameraBase;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SteeringWheelMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SteeringWheelMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InternalCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InternalCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InCarSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InCarSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InCarGear_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InCarGear;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EngineSoundComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_EngineSoundComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HeadlightLeft_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HeadlightLeft;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HeadlightRight_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HeadlightRight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpeedDisplayString_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_SpeedDisplayString;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GearDisplayString_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_GearDisplayString;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GearDisplayColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GearDisplayColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GearDisplayReverseColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_GearDisplayReverseColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bInCarCameraActive_MetaData[];
#endif
		static void NewProp_bInCarCameraActive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bInCarCameraActive;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bInReverseGear_MetaData[];
#endif
		static void NewProp_bInReverseGear_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bInReverseGear;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlipperyMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SlipperyMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NonSlipperyMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NonSlipperyMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SteeringWheelInterpSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SteeringWheelInterpSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SteeringWheelRotationScale_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SteeringWheelRotationScale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveToHardSteeringAngle_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MoveToHardSteeringAngle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxThrottle_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxThrottle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxPathingSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxPathingSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DrivingSpeedRPMScale_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DrivingSpeedRPMScale;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PathingSlowdownFactor_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PathingSlowdownFactor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PathingSlowdownSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PathingSlowdownSpeed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HighSpeedSteerThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HighSpeedSteerThreshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HighSpeedSteeringFactor_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HighSpeedSteeringFactor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AWheeledVehiclePawn,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Vehicle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetCamera, "GetCamera" }, // 1531385930
		{ &Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetEngineSoundComponent, "GetEngineSoundComponent" }, // 3777700401
		{ &Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarGear, "GetInCarGear" }, // 633024165
		{ &Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInCarSpeed, "GetInCarSpeed" }, // 2918639345
		{ &Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetInternalCamera, "GetInternalCamera" }, // 3130013418
		{ &Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetLeftSceneCaptureComponent, "GetLeftSceneCaptureComponent" }, // 3908654372
		{ &Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetMaxDrivingSpeed, "GetMaxDrivingSpeed" }, // 1261665051
		{ &Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetRightSceneCaptureComponent, "GetRightSceneCaptureComponent" }, // 2732198145
		{ &Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSpringArm, "GetSpringArm" }, // 2091292172
		{ &Z_Construct_UFunction_AVH_WheeledVehiclePawn_GetSteeringWheel, "GetSteeringWheel" }, // 2161201125
		{ &Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetHeadlightsEnabled, "SetHeadlightsEnabled" }, // 1982594121
		{ &Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetLeadVehicleFollowPoints, "SetLeadVehicleFollowPoints" }, // 2379742030
		{ &Z_Construct_UFunction_AVH_WheeledVehiclePawn_SetMaxDrivingSpeed, "SetMaxDrivingSpeed" }, // 1807834626
		{ &Z_Construct_UFunction_AVH_WheeledVehiclePawn_TeleportLeadVehicleToRoute, "TeleportLeadVehicleToRoute" }, // 1451921690
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SpringArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Spring arm that will offset the camera */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spring arm that will offset the camera" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x00200800000b001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SpringArm_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SpringArm_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_Camera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera component that will be our viewpoint */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera component that will be our viewpoint" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x00200800000b001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_Camera_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_Camera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InternalCameraBase_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Scene component for the In-Car view origin */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Scene component for the In-Car view origin" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InternalCameraBase = { "InternalCameraBase", nullptr, (EPropertyFlags)0x00200800000b001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, InternalCameraBase), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InternalCameraBase_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InternalCameraBase_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SteeringWheelMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Steering" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Steering wheel component */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Steering wheel component" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SteeringWheelMesh = { "SteeringWheelMesh", nullptr, (EPropertyFlags)0x00200800000b001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, SteeringWheelMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SteeringWheelMesh_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SteeringWheelMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InternalCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Camera component for the In-Car view */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Camera component for the In-Car view" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InternalCamera = { "InternalCamera", nullptr, (EPropertyFlags)0x00200800000b001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, InternalCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InternalCamera_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InternalCamera_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InCarSpeed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Text component for the In-Car speed */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Text component for the In-Car speed" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InCarSpeed = { "InCarSpeed", nullptr, (EPropertyFlags)0x00200800000b001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, InCarSpeed), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InCarSpeed_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InCarSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InCarGear_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Text component for the In-Car gear */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Text component for the In-Car gear" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InCarGear = { "InCarGear", nullptr, (EPropertyFlags)0x00200800000b001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, InCarGear), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InCarGear_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InCarGear_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_EngineSoundComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Audio component for the engine sound */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Audio component for the engine sound" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_EngineSoundComponent = { "EngineSoundComponent", nullptr, (EPropertyFlags)0x00200800000b001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, EngineSoundComponent), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_EngineSoundComponent_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_EngineSoundComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HeadlightLeft_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HeadlightLeft = { "HeadlightLeft", nullptr, (EPropertyFlags)0x00200800000b001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, HeadlightLeft), Z_Construct_UClass_USpotLightComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HeadlightLeft_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HeadlightLeft_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HeadlightRight_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Display" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HeadlightRight = { "HeadlightRight", nullptr, (EPropertyFlags)0x00200800000b001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, HeadlightRight), Z_Construct_UClass_USpotLightComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HeadlightRight_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HeadlightRight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SpeedDisplayString_MetaData[] = {
		{ "Category", "Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The current speed as a string eg 10 km/h */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The current speed as a string eg 10 km/h" },
#endif
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SpeedDisplayString = { "SpeedDisplayString", nullptr, (EPropertyFlags)0x0010000000030015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, SpeedDisplayString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SpeedDisplayString_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SpeedDisplayString_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_GearDisplayString_MetaData[] = {
		{ "Category", "Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The current gear as a string (R,N, 1,2 etc) */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The current gear as a string (R,N, 1,2 etc)" },
#endif
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_GearDisplayString = { "GearDisplayString", nullptr, (EPropertyFlags)0x0010000000030015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, GearDisplayString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_GearDisplayString_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_GearDisplayString_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_GearDisplayColor_MetaData[] = {
		{ "Category", "Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The color of the incar gear text in forward gears */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The color of the incar gear text in forward gears" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_GearDisplayColor = { "GearDisplayColor", nullptr, (EPropertyFlags)0x0010000000030015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, GearDisplayColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_GearDisplayColor_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_GearDisplayColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_GearDisplayReverseColor_MetaData[] = {
		{ "Category", "Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** The color of the incar gear text when in reverse */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The color of the incar gear text when in reverse" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_GearDisplayReverseColor = { "GearDisplayReverseColor", nullptr, (EPropertyFlags)0x0010000000030015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, GearDisplayReverseColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_GearDisplayReverseColor_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_GearDisplayReverseColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_bInCarCameraActive_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Are we using incar camera */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Are we using incar camera" },
#endif
	};
#endif
	void Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_bInCarCameraActive_SetBit(void* Obj)
	{
		((AVH_WheeledVehiclePawn*)Obj)->bInCarCameraActive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_bInCarCameraActive = { "bInCarCameraActive", nullptr, (EPropertyFlags)0x0010000000030015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AVH_WheeledVehiclePawn), &Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_bInCarCameraActive_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_bInCarCameraActive_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_bInCarCameraActive_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_bInReverseGear_MetaData[] = {
		{ "Category", "Camera" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Are we in reverse gear */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Are we in reverse gear" },
#endif
	};
#endif
	void Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_bInReverseGear_SetBit(void* Obj)
	{
		((AVH_WheeledVehiclePawn*)Obj)->bInReverseGear = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_bInReverseGear = { "bInReverseGear", nullptr, (EPropertyFlags)0x0010000000030015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AVH_WheeledVehiclePawn), &Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_bInReverseGear_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_bInReverseGear_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_bInReverseGear_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SlipperyMaterial_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Slippery Material instance */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Slippery Material instance" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SlipperyMaterial = { "SlipperyMaterial", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, SlipperyMaterial), Z_Construct_UClass_UPhysicalMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SlipperyMaterial_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SlipperyMaterial_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_NonSlipperyMaterial_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Non Slippery Material instance */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Non Slippery Material instance" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_NonSlipperyMaterial = { "NonSlipperyMaterial", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, NonSlipperyMaterial), Z_Construct_UClass_UPhysicalMaterial_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_NonSlipperyMaterial_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_NonSlipperyMaterial_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SteeringWheelInterpSpeed_MetaData[] = {
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How fast the steering wheel will turn towards the steering input. */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How fast the steering wheel will turn towards the steering input." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SteeringWheelInterpSpeed = { "SteeringWheelInterpSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, SteeringWheelInterpSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SteeringWheelInterpSpeed_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SteeringWheelInterpSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SteeringWheelRotationScale_MetaData[] = {
		{ "Category", "Animation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How fast the steering wheel will turn towards the steering input. */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How fast the steering wheel will turn towards the steering input." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SteeringWheelRotationScale = { "SteeringWheelRotationScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, SteeringWheelRotationScale), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SteeringWheelRotationScale_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SteeringWheelRotationScale_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_MoveToHardSteeringAngle_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How fast the steering wheel will turn towards the steering input. */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How fast the steering wheel will turn towards the steering input." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_MoveToHardSteeringAngle = { "MoveToHardSteeringAngle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, MoveToHardSteeringAngle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_MoveToHardSteeringAngle_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_MoveToHardSteeringAngle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_MaxThrottle_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Max throttle input provided for AI movement */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Max throttle input provided for AI movement" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_MaxThrottle = { "MaxThrottle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, MaxThrottle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_MaxThrottle_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_MaxThrottle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_MaxPathingSpeed_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** When vehicle speed is above this value, no further AI movement will be added. */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When vehicle speed is above this value, no further AI movement will be added." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_MaxPathingSpeed = { "MaxPathingSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, MaxPathingSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_MaxPathingSpeed_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_MaxPathingSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_DrivingSpeedRPMScale_MetaData[] = {
		{ "Category", "Movement" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_DrivingSpeedRPMScale = { "DrivingSpeedRPMScale", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, DrivingSpeedRPMScale), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_DrivingSpeedRPMScale_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_DrivingSpeedRPMScale_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_PathingSlowdownFactor_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Multiplier that determines when to \"step off\" the max throttle. The higher the number, the sooner the vehicle will slow down when close to its goal. */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Multiplier that determines when to \"step off\" the max throttle. The higher the number, the sooner the vehicle will slow down when close to its goal." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_PathingSlowdownFactor = { "PathingSlowdownFactor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, PathingSlowdownFactor), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_PathingSlowdownFactor_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_PathingSlowdownFactor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_PathingSlowdownSpeed_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** AI pathing will not apply the brakes when vehicle forward speed is above this value */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AI pathing will not apply the brakes when vehicle forward speed is above this value" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_PathingSlowdownSpeed = { "PathingSlowdownSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, PathingSlowdownSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_PathingSlowdownSpeed_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_PathingSlowdownSpeed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HighSpeedSteerThreshold_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** When to clamp down the max throttle when turning and making a sharp turn. Only affects pathing behavior. */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When to clamp down the max throttle when turning and making a sharp turn. Only affects pathing behavior." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HighSpeedSteerThreshold = { "HighSpeedSteerThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, HighSpeedSteerThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HighSpeedSteerThreshold_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HighSpeedSteerThreshold_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HighSpeedSteeringFactor_MetaData[] = {
		{ "Category", "Movement" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** When to clamp down the max throttle when turning and making a sharp turn. Only affects pathing behavior. */" },
#endif
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheeledVehiclePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "When to clamp down the max throttle when turning and making a sharp turn. Only affects pathing behavior." },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HighSpeedSteeringFactor = { "HighSpeedSteeringFactor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AVH_WheeledVehiclePawn, HighSpeedSteeringFactor), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HighSpeedSteeringFactor_MetaData), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HighSpeedSteeringFactor_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SpringArm,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_Camera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InternalCameraBase,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SteeringWheelMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InternalCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InCarSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_InCarGear,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_EngineSoundComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HeadlightLeft,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HeadlightRight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SpeedDisplayString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_GearDisplayString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_GearDisplayColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_GearDisplayReverseColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_bInCarCameraActive,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_bInReverseGear,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SlipperyMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_NonSlipperyMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SteeringWheelInterpSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_SteeringWheelRotationScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_MoveToHardSteeringAngle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_MaxThrottle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_MaxPathingSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_DrivingSpeedRPMScale,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_PathingSlowdownFactor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_PathingSlowdownSpeed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HighSpeedSteerThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::NewProp_HighSpeedSteeringFactor,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UVH_VehicleAIInterface_NoRegister, (int32)VTABLE_OFFSET(AVH_WheeledVehiclePawn, IVH_VehicleAIInterface), false },  // 1234054905
		};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::InterfaceParams) < 64);
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVH_WheeledVehiclePawn>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::ClassParams = {
		&AVH_WheeledVehiclePawn::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::Class_MetaDataParams), Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AVH_WheeledVehiclePawn()
	{
		if (!Z_Registration_Info_UClass_AVH_WheeledVehiclePawn.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVH_WheeledVehiclePawn.OuterSingleton, Z_Construct_UClass_AVH_WheeledVehiclePawn_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AVH_WheeledVehiclePawn.OuterSingleton;
	}
	template<> VH_VEHICLE_API UClass* StaticClass<AVH_WheeledVehiclePawn>()
	{
		return AVH_WheeledVehiclePawn::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVH_WheeledVehiclePawn);
	AVH_WheeledVehiclePawn::~AVH_WheeledVehiclePawn() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AVH_WheeledVehiclePawn, AVH_WheeledVehiclePawn::StaticClass, TEXT("AVH_WheeledVehiclePawn"), &Z_Registration_Info_UClass_AVH_WheeledVehiclePawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVH_WheeledVehiclePawn), 906175349U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_1218384190(TEXT("/Script/VH_Vehicle"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheeledVehiclePawn_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
