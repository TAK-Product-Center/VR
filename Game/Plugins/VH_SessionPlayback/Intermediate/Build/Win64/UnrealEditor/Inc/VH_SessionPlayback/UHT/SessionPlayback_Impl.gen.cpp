// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SessionPlayback_Impl.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSessionPlayback_Impl() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VH_SessionPlayback();
	VH_SESSIONPLAYBACK_API UClass* Z_Construct_UClass_USessionPlayback_Impl();
	VH_SESSIONPLAYBACK_API UClass* Z_Construct_UClass_USessionPlayback_Impl_NoRegister();
// End Cross Module References
	void USessionPlayback_Impl::StaticRegisterNativesUSessionPlayback_Impl()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USessionPlayback_Impl);
	UClass* Z_Construct_UClass_USessionPlayback_Impl_NoRegister()
	{
		return USessionPlayback_Impl::StaticClass();
	}
	struct Z_Construct_UClass_USessionPlayback_Impl_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USessionPlayback_Impl_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_SessionPlayback,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USessionPlayback_Impl_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USessionPlayback_Impl_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Core/Public/SessionPlayback_Impl.h" },
		{ "ModuleRelativePath", "Core/Public/SessionPlayback_Impl.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USessionPlayback_Impl_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USessionPlayback_Impl>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USessionPlayback_Impl_Statics::ClassParams = {
		&USessionPlayback_Impl::StaticClass,
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
		0x001000A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USessionPlayback_Impl_Statics::Class_MetaDataParams), Z_Construct_UClass_USessionPlayback_Impl_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_USessionPlayback_Impl()
	{
		if (!Z_Registration_Info_UClass_USessionPlayback_Impl.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USessionPlayback_Impl.OuterSingleton, Z_Construct_UClass_USessionPlayback_Impl_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USessionPlayback_Impl.OuterSingleton;
	}
	template<> VH_SESSIONPLAYBACK_API UClass* StaticClass<USessionPlayback_Impl>()
	{
		return USessionPlayback_Impl::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USessionPlayback_Impl);
	USessionPlayback_Impl::~USessionPlayback_Impl() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Core_Public_SessionPlayback_Impl_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Core_Public_SessionPlayback_Impl_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USessionPlayback_Impl, USessionPlayback_Impl::StaticClass, TEXT("USessionPlayback_Impl"), &Z_Registration_Info_UClass_USessionPlayback_Impl, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USessionPlayback_Impl), 3543949160U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Core_Public_SessionPlayback_Impl_h_1404836515(TEXT("/Script/VH_SessionPlayback"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Core_Public_SessionPlayback_Impl_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Core_Public_SessionPlayback_Impl_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
