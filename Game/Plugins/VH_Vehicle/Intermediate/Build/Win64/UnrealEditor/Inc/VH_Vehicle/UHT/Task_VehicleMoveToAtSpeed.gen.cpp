// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Task_VehicleMoveToAtSpeed.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTask_VehicleMoveToAtSpeed() {}
// Cross Module References
	AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FBlackboardKeySelector();
	UPackage* Z_Construct_UPackage__Script_VH_Vehicle();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UTask_VehicleMoveTo();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UTask_VehicleMoveToAtSpeed();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_NoRegister();
// End Cross Module References
	void UTask_VehicleMoveToAtSpeed::StaticRegisterNativesUTask_VehicleMoveToAtSpeed()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UTask_VehicleMoveToAtSpeed);
	UClass* Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_NoRegister()
	{
		return UTask_VehicleMoveToAtSpeed::StaticClass();
	}
	struct Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DesiredSpeed_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DesiredSpeed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UTask_VehicleMoveTo,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Vehicle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Makes this vehicle move to a location but at a blackboard defined desired speed\n */" },
#endif
		{ "IncludePath", "AI/Public/Task_VehicleMoveToAtSpeed.h" },
		{ "ModuleRelativePath", "AI/Public/Task_VehicleMoveToAtSpeed.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Makes this vehicle move to a location but at a blackboard defined desired speed" },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::NewProp_DesiredSpeed_MetaData[] = {
		{ "Category", "Blackboard" },
		{ "ModuleRelativePath", "AI/Public/Task_VehicleMoveToAtSpeed.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::NewProp_DesiredSpeed = { "DesiredSpeed", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UTask_VehicleMoveToAtSpeed, DesiredSpeed), Z_Construct_UScriptStruct_FBlackboardKeySelector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::NewProp_DesiredSpeed_MetaData), Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::NewProp_DesiredSpeed_MetaData) }; // 3137324432
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::NewProp_DesiredSpeed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTask_VehicleMoveToAtSpeed>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::ClassParams = {
		&UTask_VehicleMoveToAtSpeed::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::PropPointers),
		0,
		0x001000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::Class_MetaDataParams), Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UTask_VehicleMoveToAtSpeed()
	{
		if (!Z_Registration_Info_UClass_UTask_VehicleMoveToAtSpeed.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UTask_VehicleMoveToAtSpeed.OuterSingleton, Z_Construct_UClass_UTask_VehicleMoveToAtSpeed_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UTask_VehicleMoveToAtSpeed.OuterSingleton;
	}
	template<> VH_VEHICLE_API UClass* StaticClass<UTask_VehicleMoveToAtSpeed>()
	{
		return UTask_VehicleMoveToAtSpeed::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTask_VehicleMoveToAtSpeed);
	UTask_VehicleMoveToAtSpeed::~UTask_VehicleMoveToAtSpeed() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_Task_VehicleMoveToAtSpeed_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_Task_VehicleMoveToAtSpeed_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UTask_VehicleMoveToAtSpeed, UTask_VehicleMoveToAtSpeed::StaticClass, TEXT("UTask_VehicleMoveToAtSpeed"), &Z_Registration_Info_UClass_UTask_VehicleMoveToAtSpeed, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UTask_VehicleMoveToAtSpeed), 486372817U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_Task_VehicleMoveToAtSpeed_h_1970821230(TEXT("/Script/VH_Vehicle"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_Task_VehicleMoveToAtSpeed_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_Task_VehicleMoveToAtSpeed_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
