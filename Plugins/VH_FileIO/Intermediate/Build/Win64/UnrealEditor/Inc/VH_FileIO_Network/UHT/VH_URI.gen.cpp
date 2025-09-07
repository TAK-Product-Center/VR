// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_FileIO_Network/Public/VH_URI.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_URI() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VH_FileIO_Network();
	VH_FILEIO_NETWORK_API UClass* Z_Construct_UClass_UVH_URI();
	VH_FILEIO_NETWORK_API UClass* Z_Construct_UClass_UVH_URI_NoRegister();
	VH_FILEIO_NETWORK_API UEnum* Z_Construct_UEnum_VH_FileIO_Network_ESchemeTypeEnum();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESchemeTypeEnum;
	static UEnum* ESchemeTypeEnum_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESchemeTypeEnum.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESchemeTypeEnum.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_FileIO_Network_ESchemeTypeEnum, (UObject*)Z_Construct_UPackage__Script_VH_FileIO_Network(), TEXT("ESchemeTypeEnum"));
		}
		return Z_Registration_Info_UEnum_ESchemeTypeEnum.OuterSingleton;
	}
	template<> VH_FILEIO_NETWORK_API UEnum* StaticEnum<ESchemeTypeEnum>()
	{
		return ESchemeTypeEnum_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_FileIO_Network_ESchemeTypeEnum_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_FileIO_Network_ESchemeTypeEnum_Statics::Enumerators[] = {
		{ "ESchemeTypeEnum::EST_UNKNOWN", (int64)ESchemeTypeEnum::EST_UNKNOWN },
		{ "ESchemeTypeEnum::EST_UDP", (int64)ESchemeTypeEnum::EST_UDP },
		{ "ESchemeTypeEnum::EST_RTSP", (int64)ESchemeTypeEnum::EST_RTSP },
		{ "ESchemeTypeEnum::EST_HTTP", (int64)ESchemeTypeEnum::EST_HTTP },
		{ "ESchemeTypeEnum::EST_HTTPS", (int64)ESchemeTypeEnum::EST_HTTPS },
		{ "ESchemeTypeEnum::EST_TCP", (int64)ESchemeTypeEnum::EST_TCP },
		{ "ESchemeTypeEnum::EST_RTMP", (int64)ESchemeTypeEnum::EST_RTMP },
		{ "ESchemeTypeEnum::EST_RTMPS", (int64)ESchemeTypeEnum::EST_RTMPS },
		{ "ESchemeTypeEnum::EST_RTP", (int64)ESchemeTypeEnum::EST_RTP },
		{ "ESchemeTypeEnum::EST_SRT", (int64)ESchemeTypeEnum::EST_SRT },
		{ "ESchemeTypeEnum::EST_FTP", (int64)ESchemeTypeEnum::EST_FTP },
		{ "ESchemeTypeEnum::EST_FILE", (int64)ESchemeTypeEnum::EST_FILE },
		{ "ESchemeTypeEnum::EST_DIRECTORY", (int64)ESchemeTypeEnum::EST_DIRECTORY },
		{ "ESchemeTypeEnum::EST_RAW", (int64)ESchemeTypeEnum::EST_RAW },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_FileIO_Network_ESchemeTypeEnum_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Enumerator\n// ---------------------------------\n" },
#endif
		{ "EST_DIRECTORY.Name", "ESchemeTypeEnum::EST_DIRECTORY" },
		{ "EST_FILE.Name", "ESchemeTypeEnum::EST_FILE" },
		{ "EST_FTP.Name", "ESchemeTypeEnum::EST_FTP" },
		{ "EST_HTTP.Name", "ESchemeTypeEnum::EST_HTTP" },
		{ "EST_HTTPS.Name", "ESchemeTypeEnum::EST_HTTPS" },
		{ "EST_RAW.Name", "ESchemeTypeEnum::EST_RAW" },
		{ "EST_RTMP.Name", "ESchemeTypeEnum::EST_RTMP" },
		{ "EST_RTMPS.Name", "ESchemeTypeEnum::EST_RTMPS" },
		{ "EST_RTP.Name", "ESchemeTypeEnum::EST_RTP" },
		{ "EST_RTSP.Name", "ESchemeTypeEnum::EST_RTSP" },
		{ "EST_SRT.Name", "ESchemeTypeEnum::EST_SRT" },
		{ "EST_TCP.Name", "ESchemeTypeEnum::EST_TCP" },
		{ "EST_UDP.Name", "ESchemeTypeEnum::EST_UDP" },
		{ "EST_UNKNOWN.Name", "ESchemeTypeEnum::EST_UNKNOWN" },
		{ "ModuleRelativePath", "Public/VH_URI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Enumerator" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_FileIO_Network_ESchemeTypeEnum_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_FileIO_Network,
		nullptr,
		"ESchemeTypeEnum",
		"ESchemeTypeEnum",
		Z_Construct_UEnum_VH_FileIO_Network_ESchemeTypeEnum_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_FileIO_Network_ESchemeTypeEnum_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_FileIO_Network_ESchemeTypeEnum_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_FileIO_Network_ESchemeTypeEnum_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_FileIO_Network_ESchemeTypeEnum()
	{
		if (!Z_Registration_Info_UEnum_ESchemeTypeEnum.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESchemeTypeEnum.InnerSingleton, Z_Construct_UEnum_VH_FileIO_Network_ESchemeTypeEnum_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESchemeTypeEnum.InnerSingleton;
	}
	void UVH_URI::StaticRegisterNativesUVH_URI()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_URI);
	UClass* Z_Construct_UClass_UVH_URI_NoRegister()
	{
		return UVH_URI::StaticClass();
	}
	struct Z_Construct_UClass_UVH_URI_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_URI_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_FileIO_Network,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_URI_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_URI_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * This class is designed to take a URI (which is pretty much a URL) and turn it into manangable segments\n */" },
#endif
		{ "IncludePath", "VH_URI.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/VH_URI.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This class is designed to take a URI (which is pretty much a URL) and turn it into manangable segments" },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_URI_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_URI>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_URI_Statics::ClassParams = {
		&UVH_URI::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_URI_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_URI_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UVH_URI()
	{
		if (!Z_Registration_Info_UClass_UVH_URI.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_URI.OuterSingleton, Z_Construct_UClass_UVH_URI_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_URI.OuterSingleton;
	}
	template<> VH_FILEIO_NETWORK_API UClass* StaticClass<UVH_URI>()
	{
		return UVH_URI::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_URI);
	UVH_URI::~UVH_URI() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_Statics::EnumInfo[] = {
		{ ESchemeTypeEnum_StaticEnum, TEXT("ESchemeTypeEnum"), &Z_Registration_Info_UEnum_ESchemeTypeEnum, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3759424617U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_URI, UVH_URI::StaticClass, TEXT("UVH_URI"), &Z_Registration_Info_UClass_UVH_URI, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_URI), 608584008U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_324397761(TEXT("/Script/VH_FileIO_Network"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
