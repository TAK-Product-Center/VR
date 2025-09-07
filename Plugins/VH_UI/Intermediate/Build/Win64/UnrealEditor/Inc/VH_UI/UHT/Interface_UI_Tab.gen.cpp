// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interface_UI_Tab.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInterface_UI_Tab() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_UI();
	VH_UI_API UClass* Z_Construct_UClass_UInterface_UI_Tab();
	VH_UI_API UClass* Z_Construct_UClass_UInterface_UI_Tab_NoRegister();
	VH_UI_API UScriptStruct* Z_Construct_UScriptStruct_FTabInfo();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_TabInfo;
class UScriptStruct* FTabInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_TabInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_TabInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FTabInfo, (UObject*)Z_Construct_UPackage__Script_VH_UI(), TEXT("TabInfo"));
	}
	return Z_Registration_Info_UScriptStruct_TabInfo.OuterSingleton;
}
template<> VH_UI_API UScriptStruct* StaticStruct<FTabInfo>()
{
	return FTabInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FTabInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Title;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Icon;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTabInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Structs\n// ---------------------------------\n" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_UI_Tab.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Structs" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FTabInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTabInfo>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTabInfo_Statics::NewProp_Title_MetaData[] = {
		{ "Category", "TabInfo" },
		{ "ModuleRelativePath", "Core/Public/Interface_UI_Tab.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FTabInfo_Statics::NewProp_Title = { "Title", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTabInfo, Title), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTabInfo_Statics::NewProp_Title_MetaData), Z_Construct_UScriptStruct_FTabInfo_Statics::NewProp_Title_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTabInfo_Statics::NewProp_Icon_MetaData[] = {
		{ "Category", "TabInfo" },
		{ "ModuleRelativePath", "Core/Public/Interface_UI_Tab.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FTabInfo_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FTabInfo, Icon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTabInfo_Statics::NewProp_Icon_MetaData), Z_Construct_UScriptStruct_FTabInfo_Statics::NewProp_Icon_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTabInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTabInfo_Statics::NewProp_Title,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTabInfo_Statics::NewProp_Icon,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTabInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
		nullptr,
		&NewStructOps,
		"TabInfo",
		Z_Construct_UScriptStruct_FTabInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTabInfo_Statics::PropPointers),
		sizeof(FTabInfo),
		alignof(FTabInfo),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTabInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FTabInfo_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FTabInfo_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FTabInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_TabInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_TabInfo.InnerSingleton, Z_Construct_UScriptStruct_FTabInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_TabInfo.InnerSingleton;
	}
	DEFINE_FUNCTION(IInterface_UI_Tab::execGetTabInfo)
	{
		P_GET_STRUCT_REF(FTabInfo,Z_Param_Out_tabInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetTabInfo_Implementation(Z_Param_Out_tabInfo);
		P_NATIVE_END;
	}
	struct Interface_UI_Tab_eventGetTabInfo_Parms
	{
		FTabInfo tabInfo;
	};
	void IInterface_UI_Tab::GetTabInfo(FTabInfo& tabInfo) const
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetTabInfo instead.");
	}
	void UInterface_UI_Tab::StaticRegisterNativesUInterface_UI_Tab()
	{
		UClass* Class = UInterface_UI_Tab::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetTabInfo", &IInterface_UI_Tab::execGetTabInfo },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInterface_UI_Tab_GetTabInfo_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_tabInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInterface_UI_Tab_GetTabInfo_Statics::NewProp_tabInfo = { "tabInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_UI_Tab_eventGetTabInfo_Parms, tabInfo), Z_Construct_UScriptStruct_FTabInfo, METADATA_PARAMS(0, nullptr) }; // 4241683748
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_UI_Tab_GetTabInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_UI_Tab_GetTabInfo_Statics::NewProp_tabInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_UI_Tab_GetTabInfo_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Gives information about the tab\n\x09* \\param tabInfo FTabInfo struct to populate\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_UI_Tab.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Gives information about the tab\n* \\param tabInfo FTabInfo struct to populate" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_UI_Tab_GetTabInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_UI_Tab, nullptr, "GetTabInfo", nullptr, nullptr, Z_Construct_UFunction_UInterface_UI_Tab_GetTabInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_Tab_GetTabInfo_Statics::PropPointers), sizeof(Interface_UI_Tab_eventGetTabInfo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_Tab_GetTabInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_UI_Tab_GetTabInfo_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_Tab_GetTabInfo_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_UI_Tab_eventGetTabInfo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_UI_Tab_GetTabInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_UI_Tab_GetTabInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInterface_UI_Tab);
	UClass* Z_Construct_UClass_UInterface_UI_Tab_NoRegister()
	{
		return UInterface_UI_Tab::StaticClass();
	}
	struct Z_Construct_UClass_UInterface_UI_Tab_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInterface_UI_Tab_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_UI_Tab_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UInterface_UI_Tab_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInterface_UI_Tab_GetTabInfo, "GetTabInfo" }, // 905312089
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_UI_Tab_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInterface_UI_Tab_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Public/Interface_UI_Tab.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInterface_UI_Tab_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInterface_UI_Tab>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInterface_UI_Tab_Statics::ClassParams = {
		&UInterface_UI_Tab::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_UI_Tab_Statics::Class_MetaDataParams), Z_Construct_UClass_UInterface_UI_Tab_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UInterface_UI_Tab()
	{
		if (!Z_Registration_Info_UClass_UInterface_UI_Tab.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInterface_UI_Tab.OuterSingleton, Z_Construct_UClass_UInterface_UI_Tab_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInterface_UI_Tab.OuterSingleton;
	}
	template<> VH_UI_API UClass* StaticClass<UInterface_UI_Tab>()
	{
		return UInterface_UI_Tab::StaticClass();
	}
	UInterface_UI_Tab::UInterface_UI_Tab(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInterface_UI_Tab);
	UInterface_UI_Tab::~UInterface_UI_Tab() {}
	static FName NAME_UInterface_UI_Tab_GetTabInfo = FName(TEXT("GetTabInfo"));
	void IInterface_UI_Tab::Execute_GetTabInfo(const UObject* O, FTabInfo& tabInfo)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_UI_Tab::StaticClass()));
		Interface_UI_Tab_eventGetTabInfo_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_UI_Tab_GetTabInfo);
		if (Func)
		{
			Parms.tabInfo=tabInfo;
			const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
			tabInfo=Parms.tabInfo;
		}
		else if (auto I = (const IInterface_UI_Tab*)(O->GetNativeInterfaceAddress(UInterface_UI_Tab::StaticClass())))
		{
			I->GetTabInfo_Implementation(tabInfo);
		}
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_Statics::ScriptStructInfo[] = {
		{ FTabInfo::StaticStruct, Z_Construct_UScriptStruct_FTabInfo_Statics::NewStructOps, TEXT("TabInfo"), &Z_Registration_Info_UScriptStruct_TabInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FTabInfo), 4241683748U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInterface_UI_Tab, UInterface_UI_Tab::StaticClass, TEXT("UInterface_UI_Tab"), &Z_Registration_Info_UClass_UInterface_UI_Tab, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInterface_UI_Tab), 3798981940U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_3185768177(TEXT("/Script/VH_UI"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_Tab_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
