// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../WheeledVehicle/Public/VH_WheelRear.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_WheelRear() {}
// Cross Module References
	CHAOSVEHICLES_API UClass* Z_Construct_UClass_UChaosVehicleWheel();
	UPackage* Z_Construct_UPackage__Script_VH_Vehicle();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UVH_WheelRear();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UVH_WheelRear_NoRegister();
// End Cross Module References
	void UVH_WheelRear::StaticRegisterNativesUVH_WheelRear()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_WheelRear);
	UClass* Z_Construct_UClass_UVH_WheelRear_NoRegister()
	{
		return UVH_WheelRear::StaticClass();
	}
	struct Z_Construct_UClass_UVH_WheelRear_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_WheelRear_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UChaosVehicleWheel,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Vehicle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_WheelRear_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_WheelRear_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "WheeledVehicle/Public/VH_WheelRear.h" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheelRear.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_WheelRear_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_WheelRear>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_WheelRear_Statics::ClassParams = {
		&UVH_WheelRear::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_WheelRear_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_WheelRear_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UVH_WheelRear()
	{
		if (!Z_Registration_Info_UClass_UVH_WheelRear.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_WheelRear.OuterSingleton, Z_Construct_UClass_UVH_WheelRear_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_WheelRear.OuterSingleton;
	}
	template<> VH_VEHICLE_API UClass* StaticClass<UVH_WheelRear>()
	{
		return UVH_WheelRear::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_WheelRear);
	UVH_WheelRear::~UVH_WheelRear() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheelRear_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheelRear_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_WheelRear, UVH_WheelRear::StaticClass, TEXT("UVH_WheelRear"), &Z_Registration_Info_UClass_UVH_WheelRear, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_WheelRear), 1747774329U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheelRear_h_144815808(TEXT("/Script/VH_Vehicle"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheelRear_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheelRear_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
