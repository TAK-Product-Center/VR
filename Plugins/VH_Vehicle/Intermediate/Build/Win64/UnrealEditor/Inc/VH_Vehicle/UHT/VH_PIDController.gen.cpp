// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../WheeledVehicle/Public/VH_PIDController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_PIDController() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VH_Vehicle();
	VH_VEHICLE_API UScriptStruct* Z_Construct_UScriptStruct_FPIDCoefficients();
	VH_VEHICLE_API UScriptStruct* Z_Construct_UScriptStruct_FPIDController();
	VH_VEHICLE_API UScriptStruct* Z_Construct_UScriptStruct_FPIDError();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PIDError;
class UScriptStruct* FPIDError::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PIDError.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PIDError.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPIDError, (UObject*)Z_Construct_UPackage__Script_VH_Vehicle(), TEXT("PIDError"));
	}
	return Z_Registration_Info_UScriptStruct_PIDError.OuterSingleton;
}
template<> VH_VEHICLE_API UScriptStruct* StaticStruct<FPIDError>()
{
	return FPIDError::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPIDError_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPIDError_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_PIDController.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPIDError_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPIDError>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPIDError_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Vehicle,
		nullptr,
		&NewStructOps,
		"PIDError",
		nullptr,
		0,
		sizeof(FPIDError),
		alignof(FPIDError),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPIDError_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPIDError_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPIDError()
	{
		if (!Z_Registration_Info_UScriptStruct_PIDError.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PIDError.InnerSingleton, Z_Construct_UScriptStruct_FPIDError_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PIDError.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PIDCoefficients;
class UScriptStruct* FPIDCoefficients::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PIDCoefficients.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PIDCoefficients.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPIDCoefficients, (UObject*)Z_Construct_UPackage__Script_VH_Vehicle(), TEXT("PIDCoefficients"));
	}
	return Z_Registration_Info_UScriptStruct_PIDCoefficients.OuterSingleton;
}
template<> VH_VEHICLE_API UScriptStruct* StaticStruct<FPIDCoefficients>()
{
	return FPIDCoefficients::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPIDCoefficients_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProportionalCoefficient_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ProportionalCoefficient;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IntegralCoefficient_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_IntegralCoefficient;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DerivativeCoefficient_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DerivativeCoefficient;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPIDCoefficients_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_PIDController.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPIDCoefficients>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewProp_ProportionalCoefficient_MetaData[] = {
		{ "Category", "PID Coefficients" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_PIDController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewProp_ProportionalCoefficient = { "ProportionalCoefficient", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPIDCoefficients, ProportionalCoefficient), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewProp_ProportionalCoefficient_MetaData), Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewProp_ProportionalCoefficient_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewProp_IntegralCoefficient_MetaData[] = {
		{ "Category", "PID Coefficients" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_PIDController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewProp_IntegralCoefficient = { "IntegralCoefficient", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPIDCoefficients, IntegralCoefficient), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewProp_IntegralCoefficient_MetaData), Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewProp_IntegralCoefficient_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewProp_DerivativeCoefficient_MetaData[] = {
		{ "Category", "PID Coefficients" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_PIDController.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewProp_DerivativeCoefficient = { "DerivativeCoefficient", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPIDCoefficients, DerivativeCoefficient), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewProp_DerivativeCoefficient_MetaData), Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewProp_DerivativeCoefficient_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPIDCoefficients_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewProp_ProportionalCoefficient,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewProp_IntegralCoefficient,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewProp_DerivativeCoefficient,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPIDCoefficients_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Vehicle,
		nullptr,
		&NewStructOps,
		"PIDCoefficients",
		Z_Construct_UScriptStruct_FPIDCoefficients_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPIDCoefficients_Statics::PropPointers),
		sizeof(FPIDCoefficients),
		alignof(FPIDCoefficients),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPIDCoefficients_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPIDCoefficients_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPIDCoefficients_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPIDCoefficients()
	{
		if (!Z_Registration_Info_UScriptStruct_PIDCoefficients.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PIDCoefficients.InnerSingleton, Z_Construct_UScriptStruct_FPIDCoefficients_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PIDCoefficients.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PIDController;
class UScriptStruct* FPIDController::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PIDController.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PIDController.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPIDController, (UObject*)Z_Construct_UPackage__Script_VH_Vehicle(), TEXT("PIDController"));
	}
	return Z_Registration_Info_UScriptStruct_PIDController.OuterSingleton;
}
template<> VH_VEHICLE_API UScriptStruct* StaticStruct<FPIDController>()
{
	return FPIDController::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPIDController_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPIDController_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_PIDController.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FPIDController_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPIDController>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPIDController_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Vehicle,
		nullptr,
		&NewStructOps,
		"PIDController",
		nullptr,
		0,
		sizeof(FPIDController),
		alignof(FPIDController),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPIDController_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPIDController_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPIDController()
	{
		if (!Z_Registration_Info_UScriptStruct_PIDController.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PIDController.InnerSingleton, Z_Construct_UScriptStruct_FPIDController_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PIDController.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_PIDController_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_PIDController_h_Statics::ScriptStructInfo[] = {
		{ FPIDError::StaticStruct, Z_Construct_UScriptStruct_FPIDError_Statics::NewStructOps, TEXT("PIDError"), &Z_Registration_Info_UScriptStruct_PIDError, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPIDError), 2814527799U) },
		{ FPIDCoefficients::StaticStruct, Z_Construct_UScriptStruct_FPIDCoefficients_Statics::NewStructOps, TEXT("PIDCoefficients"), &Z_Registration_Info_UScriptStruct_PIDCoefficients, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPIDCoefficients), 374115500U) },
		{ FPIDController::StaticStruct, Z_Construct_UScriptStruct_FPIDController_Statics::NewStructOps, TEXT("PIDController"), &Z_Registration_Info_UScriptStruct_PIDController, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPIDController), 1837391053U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_PIDController_h_4266266102(TEXT("/Script/VH_Vehicle"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_PIDController_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_PIDController_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
