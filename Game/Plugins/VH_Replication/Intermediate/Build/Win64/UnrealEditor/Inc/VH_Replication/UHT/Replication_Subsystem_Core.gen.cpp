// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Subsystems/Public/Replication_Subsystem_Core.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReplication_Subsystem_Core() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
	UPackage* Z_Construct_UPackage__Script_VH_Replication();
	VH_REPLICATION_API UClass* Z_Construct_UClass_UReplication_Subsystem_Core();
	VH_REPLICATION_API UClass* Z_Construct_UClass_UReplication_Subsystem_Core_NoRegister();
	VH_REPLICATION_API UScriptStruct* Z_Construct_UScriptStruct_FPriorityInfo();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PriorityInfo;
class UScriptStruct* FPriorityInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PriorityInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PriorityInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPriorityInfo, (UObject*)Z_Construct_UPackage__Script_VH_Replication(), TEXT("PriorityInfo"));
	}
	return Z_Registration_Info_UScriptStruct_PriorityInfo.OuterSingleton;
}
template<> VH_REPLICATION_API UScriptStruct* StaticStruct<FPriorityInfo>()
{
	return FPriorityInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPriorityInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPriorityInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Structs\n// ---------------------------------\n" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/Replication_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Structs" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FPriorityInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPriorityInfo>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPriorityInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Replication,
		nullptr,
		&NewStructOps,
		"PriorityInfo",
		nullptr,
		0,
		sizeof(FPriorityInfo),
		alignof(FPriorityInfo),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPriorityInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPriorityInfo_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FPriorityInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_PriorityInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PriorityInfo.InnerSingleton, Z_Construct_UScriptStruct_FPriorityInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PriorityInfo.InnerSingleton;
	}
	void UReplication_Subsystem_Core::StaticRegisterNativesUReplication_Subsystem_Core()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UReplication_Subsystem_Core);
	UClass* Z_Construct_UClass_UReplication_Subsystem_Core_NoRegister()
	{
		return UReplication_Subsystem_Core::StaticClass();
	}
	struct Z_Construct_UClass_UReplication_Subsystem_Core_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UReplication_Subsystem_Core_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Replication,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UReplication_Subsystem_Core_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReplication_Subsystem_Core_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Subsystems/Public/Replication_Subsystem_Core.h" },
		{ "ModuleRelativePath", "Subsystems/Public/Replication_Subsystem_Core.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UReplication_Subsystem_Core_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UReplication_Subsystem_Core>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UReplication_Subsystem_Core_Statics::ClassParams = {
		&UReplication_Subsystem_Core::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UReplication_Subsystem_Core_Statics::Class_MetaDataParams), Z_Construct_UClass_UReplication_Subsystem_Core_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UReplication_Subsystem_Core()
	{
		if (!Z_Registration_Info_UClass_UReplication_Subsystem_Core.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UReplication_Subsystem_Core.OuterSingleton, Z_Construct_UClass_UReplication_Subsystem_Core_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UReplication_Subsystem_Core.OuterSingleton;
	}
	template<> VH_REPLICATION_API UClass* StaticClass<UReplication_Subsystem_Core>()
	{
		return UReplication_Subsystem_Core::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UReplication_Subsystem_Core);
	UReplication_Subsystem_Core::~UReplication_Subsystem_Core() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Subsystems_Public_Replication_Subsystem_Core_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Subsystems_Public_Replication_Subsystem_Core_h_Statics::ScriptStructInfo[] = {
		{ FPriorityInfo::StaticStruct, Z_Construct_UScriptStruct_FPriorityInfo_Statics::NewStructOps, TEXT("PriorityInfo"), &Z_Registration_Info_UScriptStruct_PriorityInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPriorityInfo), 3754723162U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Subsystems_Public_Replication_Subsystem_Core_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UReplication_Subsystem_Core, UReplication_Subsystem_Core::StaticClass, TEXT("UReplication_Subsystem_Core"), &Z_Registration_Info_UClass_UReplication_Subsystem_Core, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UReplication_Subsystem_Core), 3509616100U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Subsystems_Public_Replication_Subsystem_Core_h_1413796166(TEXT("/Script/VH_Replication"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Subsystems_Public_Replication_Subsystem_Core_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Subsystems_Public_Replication_Subsystem_Core_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Subsystems_Public_Replication_Subsystem_Core_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Subsystems_Public_Replication_Subsystem_Core_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
