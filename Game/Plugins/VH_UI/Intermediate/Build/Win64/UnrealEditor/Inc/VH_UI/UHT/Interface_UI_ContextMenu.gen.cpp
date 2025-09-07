// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interface_UI_ContextMenu.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInterface_UI_ContextMenu() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_UI();
	VH_UI_API UClass* Z_Construct_UClass_UInterface_UI_ContextMenu();
	VH_UI_API UClass* Z_Construct_UClass_UInterface_UI_ContextMenu_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(IInterface_UI_ContextMenu::execSetContextMenuInformation)
	{
		P_GET_OBJECT(AActor,Z_Param_instigator);
		P_GET_OBJECT(UObject,Z_Param_source);
		P_GET_TSET_REF(UObject*,Z_Param_Out_contextOptions);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetContextMenuInformation_Implementation(Z_Param_instigator,Z_Param_source,Z_Param_Out_contextOptions);
		P_NATIVE_END;
	}
	struct Interface_UI_ContextMenu_eventSetContextMenuInformation_Parms
	{
		AActor* instigator;
		UObject* source;
		TSet<UObject*> contextOptions;
	};
	void IInterface_UI_ContextMenu::SetContextMenuInformation(AActor* instigator, UObject* source, TSet<UObject*> const& contextOptions)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_SetContextMenuInformation instead.");
	}
	void UInterface_UI_ContextMenu::StaticRegisterNativesUInterface_UI_ContextMenu()
	{
		UClass* Class = UInterface_UI_ContextMenu::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetContextMenuInformation", &IInterface_UI_ContextMenu::execSetContextMenuInformation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_instigator;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_source;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_contextOptions_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_contextOptions_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_contextOptions;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::NewProp_instigator = { "instigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_UI_ContextMenu_eventSetContextMenuInformation_Parms, instigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::NewProp_source = { "source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_UI_ContextMenu_eventSetContextMenuInformation_Parms, source), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::NewProp_contextOptions_ElementProp = { "contextOptions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::NewProp_contextOptions_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::NewProp_contextOptions = { "contextOptions", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_UI_ContextMenu_eventSetContextMenuInformation_Parms, contextOptions), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::NewProp_contextOptions_MetaData), Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::NewProp_contextOptions_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::NewProp_instigator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::NewProp_source,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::NewProp_contextOptions_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::NewProp_contextOptions,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Interface_UI_ContextMenu.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_UI_ContextMenu, nullptr, "SetContextMenuInformation", nullptr, nullptr, Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::PropPointers), sizeof(Interface_UI_ContextMenu_eventSetContextMenuInformation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_UI_ContextMenu_eventSetContextMenuInformation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInterface_UI_ContextMenu);
	UClass* Z_Construct_UClass_UInterface_UI_ContextMenu_NoRegister()
	{
		return UInterface_UI_ContextMenu::StaticClass();
	}
	struct Z_Construct_UClass_UInterface_UI_ContextMenu_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInterface_UI_ContextMenu_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_UI_ContextMenu_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UInterface_UI_ContextMenu_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInterface_UI_ContextMenu_SetContextMenuInformation, "SetContextMenuInformation" }, // 1600203161
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_UI_ContextMenu_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInterface_UI_ContextMenu_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Public/Interface_UI_ContextMenu.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInterface_UI_ContextMenu_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInterface_UI_ContextMenu>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInterface_UI_ContextMenu_Statics::ClassParams = {
		&UInterface_UI_ContextMenu::StaticClass,
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
		0x001040A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_UI_ContextMenu_Statics::Class_MetaDataParams), Z_Construct_UClass_UInterface_UI_ContextMenu_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UInterface_UI_ContextMenu()
	{
		if (!Z_Registration_Info_UClass_UInterface_UI_ContextMenu.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInterface_UI_ContextMenu.OuterSingleton, Z_Construct_UClass_UInterface_UI_ContextMenu_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInterface_UI_ContextMenu.OuterSingleton;
	}
	template<> VH_UI_API UClass* StaticClass<UInterface_UI_ContextMenu>()
	{
		return UInterface_UI_ContextMenu::StaticClass();
	}
	UInterface_UI_ContextMenu::UInterface_UI_ContextMenu(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInterface_UI_ContextMenu);
	UInterface_UI_ContextMenu::~UInterface_UI_ContextMenu() {}
	static FName NAME_UInterface_UI_ContextMenu_SetContextMenuInformation = FName(TEXT("SetContextMenuInformation"));
	void IInterface_UI_ContextMenu::Execute_SetContextMenuInformation(UObject* O, AActor* instigator, UObject* source, TSet<UObject*> const& contextOptions)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_UI_ContextMenu::StaticClass()));
		Interface_UI_ContextMenu_eventSetContextMenuInformation_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_UI_ContextMenu_SetContextMenuInformation);
		if (Func)
		{
			Parms.instigator=instigator;
			Parms.source=source;
			Parms.contextOptions=contextOptions;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInterface_UI_ContextMenu*)(O->GetNativeInterfaceAddress(UInterface_UI_ContextMenu::StaticClass())))
		{
			I->SetContextMenuInformation_Implementation(instigator,source,contextOptions);
		}
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInterface_UI_ContextMenu, UInterface_UI_ContextMenu::StaticClass, TEXT("UInterface_UI_ContextMenu"), &Z_Registration_Info_UClass_UInterface_UI_ContextMenu, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInterface_UI_ContextMenu), 2914617264U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_40544023(TEXT("/Script/VH_UI"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenu_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
