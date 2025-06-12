// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Deprecated/Public/VH_ListEntryData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_ListEntryData() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VH_UI();
	VH_UI_API UClass* Z_Construct_UClass_UVH_ListEntryData();
	VH_UI_API UClass* Z_Construct_UClass_UVH_ListEntryData_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UVH_ListEntryData::execGetHoverText)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FText*)Z_Param__Result=P_THIS->GetHoverText();
		P_NATIVE_END;
	}
	static FName NAME_UVH_ListEntryData_OnDataUpdated = FName(TEXT("OnDataUpdated"));
	void UVH_ListEntryData::OnDataUpdated()
	{
		ProcessEvent(FindFunctionChecked(NAME_UVH_ListEntryData_OnDataUpdated),NULL);
	}
	void UVH_ListEntryData::StaticRegisterNativesUVH_ListEntryData()
	{
		UClass* Class = UVH_ListEntryData::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetHoverText", &UVH_ListEntryData::execGetHoverText },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_ListEntryData_GetHoverText_Statics
	{
		struct VH_ListEntryData_eventGetHoverText_Parms
		{
			FText ReturnValue;
		};
		static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UVH_ListEntryData_GetHoverText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_ListEntryData_eventGetHoverText_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_ListEntryData_GetHoverText_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_ListEntryData_GetHoverText_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_ListEntryData_GetHoverText_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List Entry" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_ListEntryData.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_ListEntryData_GetHoverText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_ListEntryData, nullptr, "GetHoverText", nullptr, nullptr, Z_Construct_UFunction_UVH_ListEntryData_GetHoverText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_ListEntryData_GetHoverText_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_ListEntryData_GetHoverText_Statics::VH_ListEntryData_eventGetHoverText_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_ListEntryData_GetHoverText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_ListEntryData_GetHoverText_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_ListEntryData_GetHoverText_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_ListEntryData_GetHoverText_Statics::VH_ListEntryData_eventGetHoverText_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_ListEntryData_GetHoverText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_ListEntryData_GetHoverText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_ListEntryData_OnDataUpdated_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_ListEntryData_OnDataUpdated_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Handler for when data has been assigned or updated\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_ListEntryData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Handler for when data has been assigned or updated" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_ListEntryData_OnDataUpdated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_ListEntryData, nullptr, "OnDataUpdated", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_ListEntryData_OnDataUpdated_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_ListEntryData_OnDataUpdated_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UVH_ListEntryData_OnDataUpdated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_ListEntryData_OnDataUpdated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_ListEntryData);
	UClass* Z_Construct_UClass_UVH_ListEntryData_NoRegister()
	{
		return UVH_ListEntryData::StaticClass();
	}
	struct Z_Construct_UClass_UVH_ListEntryData_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HoverText_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_HoverText;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_ListEntryData_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_ListEntryData_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_ListEntryData_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVH_ListEntryData_GetHoverText, "GetHoverText" }, // 2752896628
		{ &Z_Construct_UFunction_UVH_ListEntryData_OnDataUpdated, "OnDataUpdated" }, // 4142719774
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_ListEntryData_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_ListEntryData_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n* Base class for object that holds data for a list entry.  List entry data is meant to be a data only class and agnostic to visualization of the data.\n*\x09See VH_UmgWidget_List.h for more information on implementation\n*/" },
#endif
		{ "HideCategories", "VH List Entry" },
		{ "IncludePath", "Deprecated/Public/VH_ListEntryData.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_ListEntryData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Base class for object that holds data for a list entry.  List entry data is meant to be a data only class and agnostic to visualization of the data.\n     See VH_UmgWidget_List.h for more information on implementation" },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_ListEntryData_Statics::NewProp_HoverText_MetaData[] = {
		{ "Category", "Defaults" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Hover text to show for this data */" },
#endif
		{ "ExposeOnSpawn", "" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_ListEntryData.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Hover text to show for this data" },
#endif
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UVH_ListEntryData_Statics::NewProp_HoverText = { "HoverText", nullptr, (EPropertyFlags)0x0011000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_ListEntryData, HoverText), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_ListEntryData_Statics::NewProp_HoverText_MetaData), Z_Construct_UClass_UVH_ListEntryData_Statics::NewProp_HoverText_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVH_ListEntryData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_ListEntryData_Statics::NewProp_HoverText,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_ListEntryData_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_ListEntryData>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_ListEntryData_Statics::ClassParams = {
		&UVH_ListEntryData::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVH_ListEntryData_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVH_ListEntryData_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_ListEntryData_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_ListEntryData_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_ListEntryData_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVH_ListEntryData()
	{
		if (!Z_Registration_Info_UClass_UVH_ListEntryData.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_ListEntryData.OuterSingleton, Z_Construct_UClass_UVH_ListEntryData_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_ListEntryData.OuterSingleton;
	}
	template<> VH_UI_API UClass* StaticClass<UVH_ListEntryData>()
	{
		return UVH_ListEntryData::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_ListEntryData);
	UVH_ListEntryData::~UVH_ListEntryData() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_ListEntryData_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_ListEntryData_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_ListEntryData, UVH_ListEntryData::StaticClass, TEXT("UVH_ListEntryData"), &Z_Registration_Info_UClass_UVH_ListEntryData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_ListEntryData), 3953304635U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_ListEntryData_h_2832992602(TEXT("/Script/VH_UI"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_ListEntryData_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_ListEntryData_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
