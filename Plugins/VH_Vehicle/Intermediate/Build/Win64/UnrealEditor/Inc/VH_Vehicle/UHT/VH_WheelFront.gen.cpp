// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../WheeledVehicle/Public/VH_WheelFront.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_WheelFront() {}
// Cross Module References
	CHAOSVEHICLES_API UClass* Z_Construct_UClass_UChaosVehicleWheel();
	UPackage* Z_Construct_UPackage__Script_VH_Vehicle();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UVH_WheelFront();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UVH_WheelFront_NoRegister();
// End Cross Module References
	void UVH_WheelFront::StaticRegisterNativesUVH_WheelFront()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_WheelFront);
	UClass* Z_Construct_UClass_UVH_WheelFront_NoRegister()
	{
		return UVH_WheelFront::StaticClass();
	}
	struct Z_Construct_UClass_UVH_WheelFront_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_WheelFront_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UChaosVehicleWheel,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Vehicle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_WheelFront_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_WheelFront_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "WheeledVehicle/Public/VH_WheelFront.h" },
		{ "ModuleRelativePath", "WheeledVehicle/Public/VH_WheelFront.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_WheelFront_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_WheelFront>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_WheelFront_Statics::ClassParams = {
		&UVH_WheelFront::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_WheelFront_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_WheelFront_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UVH_WheelFront()
	{
		if (!Z_Registration_Info_UClass_UVH_WheelFront.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_WheelFront.OuterSingleton, Z_Construct_UClass_UVH_WheelFront_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_WheelFront.OuterSingleton;
	}
	template<> VH_VEHICLE_API UClass* StaticClass<UVH_WheelFront>()
	{
		return UVH_WheelFront::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_WheelFront);
	UVH_WheelFront::~UVH_WheelFront() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheelFront_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheelFront_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_WheelFront, UVH_WheelFront::StaticClass, TEXT("UVH_WheelFront"), &Z_Registration_Info_UClass_UVH_WheelFront, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_WheelFront), 1225669500U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheelFront_h_3183269421(TEXT("/Script/VH_Vehicle"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheelFront_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_WheeledVehicle_Public_VH_WheelFront_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
