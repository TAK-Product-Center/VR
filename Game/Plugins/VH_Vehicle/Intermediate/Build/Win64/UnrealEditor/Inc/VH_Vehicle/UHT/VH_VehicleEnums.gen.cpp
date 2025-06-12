// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Data/Public/VH_VehicleEnums.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_VehicleEnums() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VH_Vehicle();
	VH_VEHICLE_API UEnum* Z_Construct_UEnum_VH_Vehicle_E_CrowdSimulationState();
	VH_VEHICLE_API UEnum* Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EUnitOfSpeed;
	static UEnum* EUnitOfSpeed_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EUnitOfSpeed.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EUnitOfSpeed.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed, (UObject*)Z_Construct_UPackage__Script_VH_Vehicle(), TEXT("EUnitOfSpeed"));
		}
		return Z_Registration_Info_UEnum_EUnitOfSpeed.OuterSingleton;
	}
	template<> VH_VEHICLE_API UEnum* StaticEnum<EUnitOfSpeed>()
	{
		return EUnitOfSpeed_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed_Statics::Enumerators[] = {
		{ "EUnitOfSpeed::MilesPerHour", (int64)EUnitOfSpeed::MilesPerHour },
		{ "EUnitOfSpeed::KilometersPerHour", (int64)EUnitOfSpeed::KilometersPerHour },
		{ "EUnitOfSpeed::CentimetersPerSecond", (int64)EUnitOfSpeed::CentimetersPerSecond },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CentimetersPerSecond.Name", "EUnitOfSpeed::CentimetersPerSecond" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Enums\n// ---------------------------------\n" },
#endif
		{ "KilometersPerHour.Name", "EUnitOfSpeed::KilometersPerHour" },
		{ "MilesPerHour.Name", "EUnitOfSpeed::MilesPerHour" },
		{ "ModuleRelativePath", "Data/Public/VH_VehicleEnums.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Enums" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_Vehicle,
		nullptr,
		"EUnitOfSpeed",
		"EUnitOfSpeed",
		Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed()
	{
		if (!Z_Registration_Info_UEnum_EUnitOfSpeed.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EUnitOfSpeed.InnerSingleton, Z_Construct_UEnum_VH_Vehicle_EUnitOfSpeed_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EUnitOfSpeed.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_E_CrowdSimulationState;
	static UEnum* E_CrowdSimulationState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_E_CrowdSimulationState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_E_CrowdSimulationState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_Vehicle_E_CrowdSimulationState, (UObject*)Z_Construct_UPackage__Script_VH_Vehicle(), TEXT("E_CrowdSimulationState"));
		}
		return Z_Registration_Info_UEnum_E_CrowdSimulationState.OuterSingleton;
	}
	template<> VH_VEHICLE_API UEnum* StaticEnum<E_CrowdSimulationState>()
	{
		return E_CrowdSimulationState_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_Vehicle_E_CrowdSimulationState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_Vehicle_E_CrowdSimulationState_Statics::Enumerators[] = {
		{ "E_CrowdSimulationState::Enabled", (int64)E_CrowdSimulationState::Enabled },
		{ "E_CrowdSimulationState::ObstacleOnly", (int64)E_CrowdSimulationState::ObstacleOnly },
		{ "E_CrowdSimulationState::Disabled", (int64)E_CrowdSimulationState::Disabled },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_Vehicle_E_CrowdSimulationState_Statics::Enum_MetaDataParams[] = {
		{ "Disabled.Name", "E_CrowdSimulationState::Disabled" },
		{ "Enabled.Name", "E_CrowdSimulationState::Enabled" },
		{ "ModuleRelativePath", "Data/Public/VH_VehicleEnums.h" },
		{ "ObstacleOnly.Name", "E_CrowdSimulationState::ObstacleOnly" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_Vehicle_E_CrowdSimulationState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_Vehicle,
		nullptr,
		"E_CrowdSimulationState",
		"E_CrowdSimulationState",
		Z_Construct_UEnum_VH_Vehicle_E_CrowdSimulationState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Vehicle_E_CrowdSimulationState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Vehicle_E_CrowdSimulationState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_Vehicle_E_CrowdSimulationState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_Vehicle_E_CrowdSimulationState()
	{
		if (!Z_Registration_Info_UEnum_E_CrowdSimulationState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_E_CrowdSimulationState.InnerSingleton, Z_Construct_UEnum_VH_Vehicle_E_CrowdSimulationState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_E_CrowdSimulationState.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Data_Public_VH_VehicleEnums_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Data_Public_VH_VehicleEnums_h_Statics::EnumInfo[] = {
		{ EUnitOfSpeed_StaticEnum, TEXT("EUnitOfSpeed"), &Z_Registration_Info_UEnum_EUnitOfSpeed, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2057425959U) },
		{ E_CrowdSimulationState_StaticEnum, TEXT("E_CrowdSimulationState"), &Z_Registration_Info_UEnum_E_CrowdSimulationState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 252967047U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Data_Public_VH_VehicleEnums_h_2912420693(TEXT("/Script/VH_Vehicle"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Data_Public_VH_VehicleEnums_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_Data_Public_VH_VehicleEnums_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
