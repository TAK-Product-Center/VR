// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Replication_DataChannel.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReplication_DataChannel() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UChannel();
	UPackage* Z_Construct_UPackage__Script_VH_Replication();
	VH_REPLICATION_API UClass* Z_Construct_UClass_UReplication_DataChannel();
	VH_REPLICATION_API UClass* Z_Construct_UClass_UReplication_DataChannel_NoRegister();
	VH_REPLICATION_API UEnum* Z_Construct_UEnum_VH_Replication_EReplicationDataType();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EReplicationDataType;
	static UEnum* EReplicationDataType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EReplicationDataType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EReplicationDataType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_Replication_EReplicationDataType, (UObject*)Z_Construct_UPackage__Script_VH_Replication(), TEXT("EReplicationDataType"));
		}
		return Z_Registration_Info_UEnum_EReplicationDataType.OuterSingleton;
	}
	template<> VH_REPLICATION_API UEnum* StaticEnum<EReplicationDataType>()
	{
		return EReplicationDataType_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_Replication_EReplicationDataType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_Replication_EReplicationDataType_Statics::Enumerators[] = {
		{ "EReplicationDataType::InitialParameters", (int64)EReplicationDataType::InitialParameters },
		{ "EReplicationDataType::Data", (int64)EReplicationDataType::Data },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_Replication_EReplicationDataType_Statics::Enum_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Enums\n// ---------------------------------\n" },
#endif
		{ "Data.Name", "EReplicationDataType::Data" },
		{ "InitialParameters.Name", "EReplicationDataType::InitialParameters" },
		{ "ModuleRelativePath", "Core/Public/Replication_DataChannel.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Enums" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_Replication_EReplicationDataType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_Replication,
		nullptr,
		"EReplicationDataType",
		"EReplicationDataType",
		Z_Construct_UEnum_VH_Replication_EReplicationDataType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Replication_EReplicationDataType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Replication_EReplicationDataType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_Replication_EReplicationDataType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_Replication_EReplicationDataType()
	{
		if (!Z_Registration_Info_UEnum_EReplicationDataType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EReplicationDataType.InnerSingleton, Z_Construct_UEnum_VH_Replication_EReplicationDataType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EReplicationDataType.InnerSingleton;
	}
	void UReplication_DataChannel::StaticRegisterNativesUReplication_DataChannel()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UReplication_DataChannel);
	UClass* Z_Construct_UClass_UReplication_DataChannel_NoRegister()
	{
		return UReplication_DataChannel::StaticClass();
	}
	struct Z_Construct_UClass_UReplication_DataChannel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UReplication_DataChannel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UChannel,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Replication,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UReplication_DataChannel_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UReplication_DataChannel_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Core/Public/Replication_DataChannel.h" },
		{ "ModuleRelativePath", "Core/Public/Replication_DataChannel.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UReplication_DataChannel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UReplication_DataChannel>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UReplication_DataChannel_Statics::ClassParams = {
		&UReplication_DataChannel::StaticClass,
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
		0x001000A8u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UReplication_DataChannel_Statics::Class_MetaDataParams), Z_Construct_UClass_UReplication_DataChannel_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UReplication_DataChannel()
	{
		if (!Z_Registration_Info_UClass_UReplication_DataChannel.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UReplication_DataChannel.OuterSingleton, Z_Construct_UClass_UReplication_DataChannel_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UReplication_DataChannel.OuterSingleton;
	}
	template<> VH_REPLICATION_API UClass* StaticClass<UReplication_DataChannel>()
	{
		return UReplication_DataChannel::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UReplication_DataChannel);
	UReplication_DataChannel::~UReplication_DataChannel() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_Statics::EnumInfo[] = {
		{ EReplicationDataType_StaticEnum, TEXT("EReplicationDataType"), &Z_Registration_Info_UEnum_EReplicationDataType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3803715893U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UReplication_DataChannel, UReplication_DataChannel::StaticClass, TEXT("UReplication_DataChannel"), &Z_Registration_Info_UClass_UReplication_DataChannel, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UReplication_DataChannel), 1432054880U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_3918420870(TEXT("/Script/VH_Replication"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Core_Public_Replication_DataChannel_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
