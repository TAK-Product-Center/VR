// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Subsystems/Public/Developer_Subsystem_BuildInfo.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_Subsystem_BuildInfo() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo_NoRegister();
	VH_DEVELOPER_API UEnum* Z_Construct_UEnum_VH_Developer_EBuildInfo();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EBuildInfo;
	static UEnum* EBuildInfo_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EBuildInfo.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EBuildInfo.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_Developer_EBuildInfo, (UObject*)Z_Construct_UPackage__Script_VH_Developer(), TEXT("EBuildInfo"));
		}
		return Z_Registration_Info_UEnum_EBuildInfo.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UEnum* StaticEnum<EBuildInfo>()
	{
		return EBuildInfo_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_Developer_EBuildInfo_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_Developer_EBuildInfo_Statics::Enumerators[] = {
		{ "EBuildInfo::ProjectName", (int64)EBuildInfo::ProjectName },
		{ "EBuildInfo::ProjectVersion", (int64)EBuildInfo::ProjectVersion },
		{ "EBuildInfo::BuildType", (int64)EBuildInfo::BuildType },
		{ "EBuildInfo::BuildNumber", (int64)EBuildInfo::BuildNumber },
		{ "EBuildInfo::BuildDateTime", (int64)EBuildInfo::BuildDateTime },
		{ "EBuildInfo::COUNT", (int64)EBuildInfo::COUNT },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_Developer_EBuildInfo_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "BuildDateTime.Name", "EBuildInfo::BuildDateTime" },
		{ "BuildNumber.Name", "EBuildInfo::BuildNumber" },
		{ "BuildType.Name", "EBuildInfo::BuildType" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Enums\n// ---------------------------------\n" },
#endif
		{ "COUNT.Hidden", "" },
		{ "COUNT.Name", "EBuildInfo::COUNT" },
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_BuildInfo.h" },
		{ "ProjectName.Name", "EBuildInfo::ProjectName" },
		{ "ProjectVersion.Name", "EBuildInfo::ProjectVersion" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Enums" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_Developer_EBuildInfo_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_Developer,
		nullptr,
		"EBuildInfo",
		"EBuildInfo",
		Z_Construct_UEnum_VH_Developer_EBuildInfo_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Developer_EBuildInfo_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Developer_EBuildInfo_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_Developer_EBuildInfo_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_Developer_EBuildInfo()
	{
		if (!Z_Registration_Info_UEnum_EBuildInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EBuildInfo.InnerSingleton, Z_Construct_UEnum_VH_Developer_EBuildInfo_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EBuildInfo.InnerSingleton;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_BuildInfo::execGetInfo)
	{
		P_GET_ENUM(EBuildInfo,Z_Param_requestedInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetInfo(EBuildInfo(Z_Param_requestedInfo));
		P_NATIVE_END;
	}
	void UDeveloper_Subsystem_BuildInfo::StaticRegisterNativesUDeveloper_Subsystem_BuildInfo()
	{
		UClass* Class = UDeveloper_Subsystem_BuildInfo::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetInfo", &UDeveloper_Subsystem_BuildInfo::execGetInfo },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics
	{
		struct Developer_Subsystem_BuildInfo_eventGetInfo_Parms
		{
			EBuildInfo requestedInfo;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_requestedInfo_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_requestedInfo;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::NewProp_requestedInfo_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::NewProp_requestedInfo = { "requestedInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_BuildInfo_eventGetInfo_Parms, requestedInfo), Z_Construct_UEnum_VH_Developer_EBuildInfo, METADATA_PARAMS(0, nullptr) }; // 2727571592
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_BuildInfo_eventGetInfo_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::NewProp_requestedInfo_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::NewProp_requestedInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_BuildInfo.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo, nullptr, "GetInfo", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::Developer_Subsystem_BuildInfo_eventGetInfo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::Developer_Subsystem_BuildInfo_eventGetInfo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_Subsystem_BuildInfo);
	UClass* Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo_NoRegister()
	{
		return UDeveloper_Subsystem_BuildInfo::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_BuildInfo_GetInfo, "GetInfo" }, // 1571886946
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * \\brief: Stores information about current project name, project version, and build details\n */" },
#endif
		{ "IncludePath", "Subsystems/Public/Developer_Subsystem_BuildInfo.h" },
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_BuildInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief: Stores information about current project name, project version, and build details" },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_Subsystem_BuildInfo>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo_Statics::ClassParams = {
		&UDeveloper_Subsystem_BuildInfo::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_Subsystem_BuildInfo.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_Subsystem_BuildInfo.OuterSingleton, Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_Subsystem_BuildInfo.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_Subsystem_BuildInfo>()
	{
		return UDeveloper_Subsystem_BuildInfo::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_Subsystem_BuildInfo);
	UDeveloper_Subsystem_BuildInfo::~UDeveloper_Subsystem_BuildInfo() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_Statics::EnumInfo[] = {
		{ EBuildInfo_StaticEnum, TEXT("EBuildInfo"), &Z_Registration_Info_UEnum_EBuildInfo, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2727571592U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_Subsystem_BuildInfo, UDeveloper_Subsystem_BuildInfo::StaticClass, TEXT("UDeveloper_Subsystem_BuildInfo"), &Z_Registration_Info_UClass_UDeveloper_Subsystem_BuildInfo, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_Subsystem_BuildInfo), 1667207030U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_1882170670(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_BuildInfo_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
