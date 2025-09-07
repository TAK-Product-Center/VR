// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VR_WidgetInteractionComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVR_WidgetInteractionComponent() {}
// Cross Module References
	UMG_API UClass* Z_Construct_UClass_UWidgetInteractionComponent();
	UPackage* Z_Construct_UPackage__Script_VH_VR();
	VH_VR_API UClass* Z_Construct_UClass_UVR_WidgetInteractionComponent();
	VH_VR_API UClass* Z_Construct_UClass_UVR_WidgetInteractionComponent_NoRegister();
// End Cross Module References
	void UVR_WidgetInteractionComponent::StaticRegisterNativesUVR_WidgetInteractionComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVR_WidgetInteractionComponent);
	UClass* Z_Construct_UClass_UVR_WidgetInteractionComponent_NoRegister()
	{
		return UVR_WidgetInteractionComponent::StaticClass();
	}
	struct Z_Construct_UClass_UVR_WidgetInteractionComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVR_WidgetInteractionComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UWidgetInteractionComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_VR,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_WidgetInteractionComponent_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_WidgetInteractionComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "Components/Public/VR_WidgetInteractionComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Components/Public/VR_WidgetInteractionComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVR_WidgetInteractionComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVR_WidgetInteractionComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVR_WidgetInteractionComponent_Statics::ClassParams = {
		&UVR_WidgetInteractionComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_WidgetInteractionComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UVR_WidgetInteractionComponent_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UVR_WidgetInteractionComponent()
	{
		if (!Z_Registration_Info_UClass_UVR_WidgetInteractionComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVR_WidgetInteractionComponent.OuterSingleton, Z_Construct_UClass_UVR_WidgetInteractionComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVR_WidgetInteractionComponent.OuterSingleton;
	}
	template<> VH_VR_API UClass* StaticClass<UVR_WidgetInteractionComponent>()
	{
		return UVR_WidgetInteractionComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVR_WidgetInteractionComponent);
	UVR_WidgetInteractionComponent::~UVR_WidgetInteractionComponent() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_WidgetInteractionComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_WidgetInteractionComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVR_WidgetInteractionComponent, UVR_WidgetInteractionComponent::StaticClass, TEXT("UVR_WidgetInteractionComponent"), &Z_Registration_Info_UClass_UVR_WidgetInteractionComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVR_WidgetInteractionComponent), 47017480U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_WidgetInteractionComponent_h_1788987630(TEXT("/Script/VH_VR"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_WidgetInteractionComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_WidgetInteractionComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
