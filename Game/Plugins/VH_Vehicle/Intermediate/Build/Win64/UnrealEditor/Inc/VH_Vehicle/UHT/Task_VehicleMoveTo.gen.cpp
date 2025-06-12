// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Task_VehicleMoveTo.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTask_VehicleMoveTo() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_UBTTask_MoveTo();
	UPackage* Z_Construct_UPackage__Script_VH_Vehicle();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UTask_VehicleMoveTo();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UTask_VehicleMoveTo_NoRegister();
// End Cross Module References
	void UTask_VehicleMoveTo::StaticRegisterNativesUTask_VehicleMoveTo()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTask_VehicleMoveTo);
	UClass* Z_Construct_UClass_UTask_VehicleMoveTo_NoRegister()
	{
		return UTask_VehicleMoveTo::StaticClass();
	}
	struct Z_Construct_UClass_UTask_VehicleMoveTo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bReverseTowardsTarget_MetaData[];
#endif
		static void NewProp_bReverseTowardsTarget_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bReverseTowardsTarget;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTask_VehicleMoveTo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBTTask_MoveTo,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Vehicle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTask_VehicleMoveTo_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTask_VehicleMoveTo_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Same as normal MoveTo node but includes the ability to optionally tell this vehicle to reverse\n */" },
#endif
		{ "IncludePath", "AI/Public/Task_VehicleMoveTo.h" },
		{ "ModuleRelativePath", "AI/Public/Task_VehicleMoveTo.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Same as normal MoveTo node but includes the ability to optionally tell this vehicle to reverse" },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTask_VehicleMoveTo_Statics::NewProp_bReverseTowardsTarget_MetaData[] = {
		{ "Category", "Vehicle AI" },
		{ "ModuleRelativePath", "AI/Public/Task_VehicleMoveTo.h" },
	};
#endif
	void Z_Construct_UClass_UTask_VehicleMoveTo_Statics::NewProp_bReverseTowardsTarget_SetBit(void* Obj)
	{
		((UTask_VehicleMoveTo*)Obj)->bReverseTowardsTarget = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UTask_VehicleMoveTo_Statics::NewProp_bReverseTowardsTarget = { "bReverseTowardsTarget", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UTask_VehicleMoveTo), &Z_Construct_UClass_UTask_VehicleMoveTo_Statics::NewProp_bReverseTowardsTarget_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTask_VehicleMoveTo_Statics::NewProp_bReverseTowardsTarget_MetaData), Z_Construct_UClass_UTask_VehicleMoveTo_Statics::NewProp_bReverseTowardsTarget_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTask_VehicleMoveTo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTask_VehicleMoveTo_Statics::NewProp_bReverseTowardsTarget,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTask_VehicleMoveTo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTask_VehicleMoveTo>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTask_VehicleMoveTo_Statics::ClassParams = {
		&UTask_VehicleMoveTo::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UTask_VehicleMoveTo_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UTask_VehicleMoveTo_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTask_VehicleMoveTo_Statics::Class_MetaDataParams), Z_Construct_UClass_UTask_VehicleMoveTo_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTask_VehicleMoveTo_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UTask_VehicleMoveTo()
	{
		if (!Z_Registration_Info_UClass_UTask_VehicleMoveTo.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTask_VehicleMoveTo.OuterSingleton, Z_Construct_UClass_UTask_VehicleMoveTo_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTask_VehicleMoveTo.OuterSingleton;
	}
	template<> VH_VEHICLE_API UClass* StaticClass<UTask_VehicleMoveTo>()
	{
		return UTask_VehicleMoveTo::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTask_VehicleMoveTo);
	UTask_VehicleMoveTo::~UTask_VehicleMoveTo() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_Task_VehicleMoveTo_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_Task_VehicleMoveTo_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UTask_VehicleMoveTo, UTask_VehicleMoveTo::StaticClass, TEXT("UTask_VehicleMoveTo"), &Z_Registration_Info_UClass_UTask_VehicleMoveTo, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTask_VehicleMoveTo), 3241327691U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_Task_VehicleMoveTo_h_627338921(TEXT("/Script/VH_Vehicle"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_Task_VehicleMoveTo_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_Task_VehicleMoveTo_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
