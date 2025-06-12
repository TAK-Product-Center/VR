// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Deprecated/Public/VH_UmgWidget_List.h"
#include "Components/SlateWrapperTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_UmgWidget_List() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UPanelSlot_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UPanelWidget_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UMG_API UScriptStruct* Z_Construct_UScriptStruct_FSlateChildSize();
	UPackage* Z_Construct_UPackage__Script_VH_UI();
	VH_UI_API UClass* Z_Construct_UClass_UVH_ListEntryData_NoRegister();
	VH_UI_API UClass* Z_Construct_UClass_UVH_UmgListEntry_NoRegister();
	VH_UI_API UClass* Z_Construct_UClass_UVH_UmgWidget_List();
	VH_UI_API UClass* Z_Construct_UClass_UVH_UmgWidget_List_NoRegister();
	VH_UI_API UEnum* Z_Construct_UEnum_VH_UI_EListInteractionStyle();
	VH_UI_API UEnum* Z_Construct_UEnum_VH_UI_ESortType();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EListInteractionStyle;
	static UEnum* EListInteractionStyle_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EListInteractionStyle.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EListInteractionStyle.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_UI_EListInteractionStyle, (UObject*)Z_Construct_UPackage__Script_VH_UI(), TEXT("EListInteractionStyle"));
		}
		return Z_Registration_Info_UEnum_EListInteractionStyle.OuterSingleton;
	}
	template<> VH_UI_API UEnum* StaticEnum<EListInteractionStyle>()
	{
		return EListInteractionStyle_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_UI_EListInteractionStyle_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_UI_EListInteractionStyle_Statics::Enumerators[] = {
		{ "EListInteractionStyle::ELIS_List", (int64)EListInteractionStyle::ELIS_List },
		{ "EListInteractionStyle::ELIS_RadioButtons", (int64)EListInteractionStyle::ELIS_RadioButtons },
		{ "EListInteractionStyle::ELIS_Checkboxes", (int64)EListInteractionStyle::ELIS_Checkboxes },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_UI_EListInteractionStyle_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ELIS_Checkboxes.Comment", "/** clicks will toggle selection on each entry.  Multiple entries can be selected. */" },
		{ "ELIS_Checkboxes.Name", "EListInteractionStyle::ELIS_Checkboxes" },
		{ "ELIS_Checkboxes.ToolTip", "clicks will toggle selection on each entry.  Multiple entries can be selected." },
		{ "ELIS_List.Comment", "/** Standard List interaction.  Only a single item is selected by clicking, but modifier keys allow multi-selection */" },
		{ "ELIS_List.Name", "EListInteractionStyle::ELIS_List" },
		{ "ELIS_List.ToolTip", "Standard List interaction.  Only a single item is selected by clicking, but modifier keys allow multi-selection" },
		{ "ELIS_RadioButtons.Comment", "/** Only a single item can be selected at a time.  A selection is not required currently*/" },
		{ "ELIS_RadioButtons.Name", "EListInteractionStyle::ELIS_RadioButtons" },
		{ "ELIS_RadioButtons.ToolTip", "Only a single item can be selected at a time.  A selection is not required currently" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_UI_EListInteractionStyle_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_UI,
		nullptr,
		"EListInteractionStyle",
		"EListInteractionStyle",
		Z_Construct_UEnum_VH_UI_EListInteractionStyle_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_UI_EListInteractionStyle_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_UI_EListInteractionStyle_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_UI_EListInteractionStyle_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_UI_EListInteractionStyle()
	{
		if (!Z_Registration_Info_UEnum_EListInteractionStyle.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EListInteractionStyle.InnerSingleton, Z_Construct_UEnum_VH_UI_EListInteractionStyle_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EListInteractionStyle.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESortType;
	static UEnum* ESortType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESortType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESortType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_UI_ESortType, (UObject*)Z_Construct_UPackage__Script_VH_UI(), TEXT("ESortType"));
		}
		return Z_Registration_Info_UEnum_ESortType.OuterSingleton;
	}
	template<> VH_UI_API UEnum* StaticEnum<ESortType>()
	{
		return ESortType_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_UI_ESortType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_UI_ESortType_Statics::Enumerators[] = {
		{ "ESortType::Ascending", (int64)ESortType::Ascending },
		{ "ESortType::Descending", (int64)ESortType::Descending },
		{ "ESortType::Default", (int64)ESortType::Default },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_UI_ESortType_Statics::Enum_MetaDataParams[] = {
		{ "Ascending.DisplayName", "Ascending" },
		{ "Ascending.Name", "ESortType::Ascending" },
		{ "BlueprintType", "true" },
		{ "Default.DisplayName", "Default" },
		{ "Default.Name", "ESortType::Default" },
		{ "Descending.DisplayName", "Descending" },
		{ "Descending.Name", "ESortType::Descending" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_UI_ESortType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_UI,
		nullptr,
		"ESortType",
		"ESortType",
		Z_Construct_UEnum_VH_UI_ESortType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_UI_ESortType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_UI_ESortType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_UI_ESortType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_UI_ESortType()
	{
		if (!Z_Registration_Info_UEnum_ESortType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESortType.InnerSingleton, Z_Construct_UEnum_VH_UI_ESortType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESortType.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics
	{
		struct VH_UmgWidget_List_eventOnListSelectionChanged_Parms
		{
			TArray<UVH_UmgListEntry*> curSelectedEntries;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_curSelectedEntries_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_curSelectedEntries_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_curSelectedEntries;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::NewProp_curSelectedEntries_Inner = { "curSelectedEntries", nullptr, (EPropertyFlags)0x0000000000080000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::NewProp_curSelectedEntries_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::NewProp_curSelectedEntries = { "curSelectedEntries", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventOnListSelectionChanged_Parms, curSelectedEntries), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::NewProp_curSelectedEntries_MetaData), Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::NewProp_curSelectedEntries_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::NewProp_curSelectedEntries_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::NewProp_curSelectedEntries,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "OnListSelectionChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::VH_UmgWidget_List_eventOnListSelectionChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::VH_UmgWidget_List_eventOnListSelectionChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UVH_UmgWidget_List::FOnListSelectionChanged_DelegateWrapper(const FMulticastScriptDelegate& OnListSelectionChanged, TArray<UVH_UmgListEntry*> const& curSelectedEntries)
{
	struct VH_UmgWidget_List_eventOnListSelectionChanged_Parms
	{
		TArray<UVH_UmgListEntry*> curSelectedEntries;
	};
	VH_UmgWidget_List_eventOnListSelectionChanged_Parms Parms;
	Parms.curSelectedEntries=curSelectedEntries;
	OnListSelectionChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics
	{
		struct VH_UmgWidget_List_eventOnEntryEvent_Parms
		{
			UVH_ListEntryData* data;
			UVH_UmgListEntry* listEntry;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_data;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_listEntry_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_listEntry;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::NewProp_data = { "data", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventOnEntryEvent_Parms, data), Z_Construct_UClass_UVH_ListEntryData_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::NewProp_listEntry_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::NewProp_listEntry = { "listEntry", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventOnEntryEvent_Parms, listEntry), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::NewProp_listEntry_MetaData), Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::NewProp_listEntry_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::NewProp_data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::NewProp_listEntry,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "OnEntryEvent__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::VH_UmgWidget_List_eventOnEntryEvent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::VH_UmgWidget_List_eventOnEntryEvent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UVH_UmgWidget_List::FOnEntryEvent_DelegateWrapper(const FMulticastScriptDelegate& OnEntryEvent, UVH_ListEntryData* data, UVH_UmgListEntry* listEntry)
{
	struct VH_UmgWidget_List_eventOnEntryEvent_Parms
	{
		UVH_ListEntryData* data;
		UVH_UmgListEntry* listEntry;
	};
	VH_UmgWidget_List_eventOnEntryEvent_Parms Parms;
	Parms.data=data;
	Parms.listEntry=listEntry;
	OnEntryEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics
	{
		struct VH_UmgWidget_List_eventOnSortRequest_Parms
		{
			int32 sortColumn;
			ESortType sortType;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_sortColumn;
		static const UECodeGen_Private::FBytePropertyParams NewProp_sortType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_sortType;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::NewProp_sortColumn = { "sortColumn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventOnSortRequest_Parms, sortColumn), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::NewProp_sortType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::NewProp_sortType = { "sortType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventOnSortRequest_Parms, sortType), Z_Construct_UEnum_VH_UI_ESortType, METADATA_PARAMS(0, nullptr) }; // 913682698
	void Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_UmgWidget_List_eventOnSortRequest_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgWidget_List_eventOnSortRequest_Parms), &Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::NewProp_sortColumn,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::NewProp_sortType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::NewProp_sortType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Return true if the sorting has been handled.  Otherwise default algorithms will be used */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Return true if the sorting has been handled.  Otherwise default algorithms will be used" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "OnSortRequest__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::VH_UmgWidget_List_eventOnSortRequest_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::VH_UmgWidget_List_eventOnSortRequest_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
bool UVH_UmgWidget_List::FOnSortRequest_DelegateWrapper(const FScriptDelegate& OnSortRequest, int32 sortColumn, ESortType sortType)
{
	struct VH_UmgWidget_List_eventOnSortRequest_Parms
	{
		int32 sortColumn;
		ESortType sortType;
		bool ReturnValue;

		/** Constructor, initializes return property only **/
		VH_UmgWidget_List_eventOnSortRequest_Parms()
			: ReturnValue(false)
		{
		}
	};
	VH_UmgWidget_List_eventOnSortRequest_Parms Parms;
	Parms.sortColumn=sortColumn;
	Parms.sortType=sortType;
	OnSortRequest.ProcessDelegate<UObject>(&Parms);
	return !!Parms.ReturnValue;
}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execInsertItem)
	{
		P_GET_OBJECT(UVH_UmgListEntry,Z_Param_widgetInstance);
		P_GET_PROPERTY(FIntProperty,Z_Param_insertIdx);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InsertItem_Implementation(Z_Param_widgetInstance,Z_Param_insertIdx);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execAddItem)
	{
		P_GET_OBJECT(UVH_UmgListEntry,Z_Param_widgetInstance);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddItem_Implementation(Z_Param_widgetInstance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execRemoveItem)
	{
		P_GET_OBJECT(UVH_UmgListEntry,Z_Param_widgetInstance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->RemoveItem_Implementation(Z_Param_widgetInstance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execClearItems)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearItems_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execHandleEnterPressed)
	{
		P_GET_OBJECT(UVH_UmgListEntry,Z_Param_entry);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleEnterPressed(Z_Param_entry);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execHandleEntryDoubleClicked)
	{
		P_GET_OBJECT(UVH_UmgListEntry,Z_Param_entry);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleEntryDoubleClicked(Z_Param_entry);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execHandleEntryClicked)
	{
		P_GET_OBJECT(UVH_UmgListEntry,Z_Param_entry);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleEntryClicked(Z_Param_entry);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execUpdateCellSizes)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_columnIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateCellSizes(Z_Param_columnIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execUpdateAllCellSizes)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateAllCellSizes();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execSetSlotSizeData)
	{
		P_GET_OBJECT(UPanelSlot,Z_Param_slotHandle);
		P_GET_STRUCT_REF(FSlateChildSize,Z_Param_Out_sizingData);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSlotSizeData(Z_Param_slotHandle,Z_Param_Out_sizingData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execSortByColumn)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_columnIdx);
		P_GET_ENUM(ESortType,Z_Param_sortType);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SortByColumn(Z_Param_columnIdx,ESortType(Z_Param_sortType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execRebuildVisualList)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RebuildVisualList();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execClearSelections)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearSelections();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execDeselectEntry)
	{
		P_GET_OBJECT(UVH_UmgListEntry,Z_Param_entry);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DeselectEntry(Z_Param_entry);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execSetEntryDataSelected)
	{
		P_GET_OBJECT(UVH_ListEntryData,Z_Param_data);
		P_GET_UBOOL(Z_Param_bForceClearPreviousSelections);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetEntryDataSelected(Z_Param_data,Z_Param_bForceClearPreviousSelections);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execSetEntrySelected)
	{
		P_GET_OBJECT(UVH_UmgListEntry,Z_Param_entry);
		P_GET_UBOOL(Z_Param_bForceClearPreviousSelections);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetEntrySelected(Z_Param_entry,Z_Param_bForceClearPreviousSelections);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execSetIndicesSelected)
	{
		P_GET_TARRAY(int32,Z_Param_selectedIndices);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetIndicesSelected(Z_Param_selectedIndices);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execSetIndexSelected)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_entryIdx);
		P_GET_UBOOL(Z_Param_bForceClearPreviousSelections);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetIndexSelected(Z_Param_entryIdx,Z_Param_bForceClearPreviousSelections);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execGetSelectedEntries)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UVH_UmgListEntry*>*)Z_Param__Result=P_THIS->GetSelectedEntries();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execGetSelectedIndices)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<int32>*)Z_Param__Result=P_THIS->GetSelectedIndices();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execGetEntryForData)
	{
		P_GET_OBJECT(UVH_ListEntryData,Z_Param_data);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UVH_UmgListEntry**)Z_Param__Result=P_THIS->GetEntryForData(Z_Param_data);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execGetEntryAtIndex)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_entryIdx);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UVH_UmgListEntry**)Z_Param__Result=P_THIS->GetEntryAtIndex(Z_Param_entryIdx);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execGetDataIndex)
	{
		P_GET_OBJECT(UVH_ListEntryData,Z_Param_data);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetDataIndex(Z_Param_data);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execSetEntryIndex)
	{
		P_GET_OBJECT(UVH_UmgListEntry,Z_Param_entry);
		P_GET_PROPERTY(FIntProperty,Z_Param_desiredIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->SetEntryIndex(Z_Param_entry,Z_Param_desiredIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execGetEntryIndex)
	{
		P_GET_OBJECT(UVH_UmgListEntry,Z_Param_entry);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetEntryIndex(Z_Param_entry);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execGetListEntries)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UVH_UmgListEntry*>*)Z_Param__Result=P_THIS->GetListEntries();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execClearEntries)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearEntries();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execRemoveEntryByData)
	{
		P_GET_OBJECT(UVH_ListEntryData,Z_Param_data);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->RemoveEntryByData(Z_Param_data);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execRemoveEntry)
	{
		P_GET_OBJECT(UVH_UmgListEntry,Z_Param_widgetInstance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->RemoveEntry(Z_Param_widgetInstance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execCreateEntryByClass)
	{
		P_GET_OBJECT(UVH_ListEntryData,Z_Param_data);
		P_GET_OBJECT(UClass,Z_Param_widgetInstance);
		P_GET_PROPERTY(FIntProperty,Z_Param_overrideIdx);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UVH_UmgListEntry**)Z_Param__Result=P_THIS->CreateEntryByClass(Z_Param_data,Z_Param_widgetInstance,Z_Param_overrideIdx);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execCreateEntry)
	{
		P_GET_OBJECT(UVH_ListEntryData,Z_Param_data);
		P_GET_OBJECT(UVH_UmgListEntry,Z_Param_widgetInstance);
		P_GET_PROPERTY(FIntProperty,Z_Param_overrideIdx);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CreateEntry(Z_Param_data,Z_Param_widgetInstance,Z_Param_overrideIdx);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execSetLayoutHandler)
	{
		P_GET_OBJECT(UPanelWidget,Z_Param_newLayoutHandler);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLayoutHandler(Z_Param_newLayoutHandler);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execCanToggleSelection)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CanToggleSelection();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execPreferSingleSelection)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->PreferSingleSelection();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execCanMultiSelect)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CanMultiSelect();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execSetInteractionStyle)
	{
		P_GET_ENUM(EListInteractionStyle,Z_Param_newInteractionStyle);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetInteractionStyle(EListInteractionStyle(Z_Param_newInteractionStyle));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgWidget_List::execGetNumEntries)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetNumEntries();
		P_NATIVE_END;
	}
	struct VH_UmgWidget_List_eventAddItem_Parms
	{
		UVH_UmgListEntry* widgetInstance;
	};
	struct VH_UmgWidget_List_eventInsertItem_Parms
	{
		UVH_UmgListEntry* widgetInstance;
		int32 insertIdx;
	};
	struct VH_UmgWidget_List_eventOnInternalSelectionChanged_Parms
	{
		TArray<UVH_UmgListEntry*> curSelectedEntries;
	};
	struct VH_UmgWidget_List_eventRemoveItem_Parms
	{
		UVH_UmgListEntry* widgetInstance;
		bool ReturnValue;

		/** Constructor, initializes return property only **/
		VH_UmgWidget_List_eventRemoveItem_Parms()
			: ReturnValue(false)
		{
		}
	};
	static FName NAME_UVH_UmgWidget_List_AddItem = FName(TEXT("AddItem"));
	void UVH_UmgWidget_List::AddItem(UVH_UmgListEntry* widgetInstance)
	{
		VH_UmgWidget_List_eventAddItem_Parms Parms;
		Parms.widgetInstance=widgetInstance;
		ProcessEvent(FindFunctionChecked(NAME_UVH_UmgWidget_List_AddItem),&Parms);
	}
	static FName NAME_UVH_UmgWidget_List_ClearItems = FName(TEXT("ClearItems"));
	void UVH_UmgWidget_List::ClearItems()
	{
		ProcessEvent(FindFunctionChecked(NAME_UVH_UmgWidget_List_ClearItems),NULL);
	}
	static FName NAME_UVH_UmgWidget_List_InsertItem = FName(TEXT("InsertItem"));
	void UVH_UmgWidget_List::InsertItem(UVH_UmgListEntry* widgetInstance, int32 insertIdx)
	{
		VH_UmgWidget_List_eventInsertItem_Parms Parms;
		Parms.widgetInstance=widgetInstance;
		Parms.insertIdx=insertIdx;
		ProcessEvent(FindFunctionChecked(NAME_UVH_UmgWidget_List_InsertItem),&Parms);
	}
	static FName NAME_UVH_UmgWidget_List_OnInternalSelectionChanged = FName(TEXT("OnInternalSelectionChanged"));
	void UVH_UmgWidget_List::OnInternalSelectionChanged(TArray<UVH_UmgListEntry*> const& curSelectedEntries)
	{
		VH_UmgWidget_List_eventOnInternalSelectionChanged_Parms Parms;
		Parms.curSelectedEntries=curSelectedEntries;
		ProcessEvent(FindFunctionChecked(NAME_UVH_UmgWidget_List_OnInternalSelectionChanged),&Parms);
	}
	static FName NAME_UVH_UmgWidget_List_RemoveItem = FName(TEXT("RemoveItem"));
	bool UVH_UmgWidget_List::RemoveItem(UVH_UmgListEntry* widgetInstance)
	{
		VH_UmgWidget_List_eventRemoveItem_Parms Parms;
		Parms.widgetInstance=widgetInstance;
		ProcessEvent(FindFunctionChecked(NAME_UVH_UmgWidget_List_RemoveItem),&Parms);
		return !!Parms.ReturnValue;
	}
	void UVH_UmgWidget_List::StaticRegisterNativesUVH_UmgWidget_List()
	{
		UClass* Class = UVH_UmgWidget_List::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddItem", &UVH_UmgWidget_List::execAddItem },
			{ "CanMultiSelect", &UVH_UmgWidget_List::execCanMultiSelect },
			{ "CanToggleSelection", &UVH_UmgWidget_List::execCanToggleSelection },
			{ "ClearEntries", &UVH_UmgWidget_List::execClearEntries },
			{ "ClearItems", &UVH_UmgWidget_List::execClearItems },
			{ "ClearSelections", &UVH_UmgWidget_List::execClearSelections },
			{ "CreateEntry", &UVH_UmgWidget_List::execCreateEntry },
			{ "CreateEntryByClass", &UVH_UmgWidget_List::execCreateEntryByClass },
			{ "DeselectEntry", &UVH_UmgWidget_List::execDeselectEntry },
			{ "GetDataIndex", &UVH_UmgWidget_List::execGetDataIndex },
			{ "GetEntryAtIndex", &UVH_UmgWidget_List::execGetEntryAtIndex },
			{ "GetEntryForData", &UVH_UmgWidget_List::execGetEntryForData },
			{ "GetEntryIndex", &UVH_UmgWidget_List::execGetEntryIndex },
			{ "GetListEntries", &UVH_UmgWidget_List::execGetListEntries },
			{ "GetNumEntries", &UVH_UmgWidget_List::execGetNumEntries },
			{ "GetSelectedEntries", &UVH_UmgWidget_List::execGetSelectedEntries },
			{ "GetSelectedIndices", &UVH_UmgWidget_List::execGetSelectedIndices },
			{ "HandleEnterPressed", &UVH_UmgWidget_List::execHandleEnterPressed },
			{ "HandleEntryClicked", &UVH_UmgWidget_List::execHandleEntryClicked },
			{ "HandleEntryDoubleClicked", &UVH_UmgWidget_List::execHandleEntryDoubleClicked },
			{ "InsertItem", &UVH_UmgWidget_List::execInsertItem },
			{ "PreferSingleSelection", &UVH_UmgWidget_List::execPreferSingleSelection },
			{ "RebuildVisualList", &UVH_UmgWidget_List::execRebuildVisualList },
			{ "RemoveEntry", &UVH_UmgWidget_List::execRemoveEntry },
			{ "RemoveEntryByData", &UVH_UmgWidget_List::execRemoveEntryByData },
			{ "RemoveItem", &UVH_UmgWidget_List::execRemoveItem },
			{ "SetEntryDataSelected", &UVH_UmgWidget_List::execSetEntryDataSelected },
			{ "SetEntryIndex", &UVH_UmgWidget_List::execSetEntryIndex },
			{ "SetEntrySelected", &UVH_UmgWidget_List::execSetEntrySelected },
			{ "SetIndexSelected", &UVH_UmgWidget_List::execSetIndexSelected },
			{ "SetIndicesSelected", &UVH_UmgWidget_List::execSetIndicesSelected },
			{ "SetInteractionStyle", &UVH_UmgWidget_List::execSetInteractionStyle },
			{ "SetLayoutHandler", &UVH_UmgWidget_List::execSetLayoutHandler },
			{ "SetSlotSizeData", &UVH_UmgWidget_List::execSetSlotSizeData },
			{ "SortByColumn", &UVH_UmgWidget_List::execSortByColumn },
			{ "UpdateAllCellSizes", &UVH_UmgWidget_List::execUpdateAllCellSizes },
			{ "UpdateCellSizes", &UVH_UmgWidget_List::execUpdateCellSizes },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_AddItem_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_widgetInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_widgetInstance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_AddItem_Statics::NewProp_widgetInstance_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_AddItem_Statics::NewProp_widgetInstance = { "widgetInstance", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventAddItem_Parms, widgetInstance), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_AddItem_Statics::NewProp_widgetInstance_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_AddItem_Statics::NewProp_widgetInstance_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_AddItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_AddItem_Statics::NewProp_widgetInstance,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_AddItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Adds the entry to the list.  Native has a default implementation to add it to a specified handler.\n\x09 * @param widgetInstance Widget that should be added to the list.  \n\x09 */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Adds the entry to the list.  Native has a default implementation to add it to a specified handler.\n@param widgetInstance Widget that should be added to the list." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_AddItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "AddItem", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_AddItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_AddItem_Statics::PropPointers), sizeof(VH_UmgWidget_List_eventAddItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_AddItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_AddItem_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_AddItem_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_UmgWidget_List_eventAddItem_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_AddItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_AddItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect_Statics
	{
		struct VH_UmgWidget_List_eventCanMultiSelect_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_UmgWidget_List_eventCanMultiSelect_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgWidget_List_eventCanMultiSelect_Parms), &Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief True if we can select more than one entry (Checkbox interaction style)\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief True if we can select more than one entry (Checkbox interaction style)" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "CanMultiSelect", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect_Statics::VH_UmgWidget_List_eventCanMultiSelect_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect_Statics::VH_UmgWidget_List_eventCanMultiSelect_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection_Statics
	{
		struct VH_UmgWidget_List_eventCanToggleSelection_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_UmgWidget_List_eventCanToggleSelection_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgWidget_List_eventCanToggleSelection_Parms), &Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** True if re-clicking an index will toggle the selection */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "True if re-clicking an index will toggle the selection" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "CanToggleSelection", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection_Statics::VH_UmgWidget_List_eventCanToggleSelection_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection_Statics::VH_UmgWidget_List_eventCanToggleSelection_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_ClearEntries_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_ClearEntries_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * @brief Removes all list entries, data, and selections\n    */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Removes all list entries, data, and selections" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_ClearEntries_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "ClearEntries", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_ClearEntries_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_ClearEntries_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_ClearEntries()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_ClearEntries_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_ClearItems_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_ClearItems_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * @brief Removes all item from the List.  Native will remove all elements from a specified handler.\n    */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Removes all item from the List.  Native will remove all elements from a specified handler." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_ClearItems_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "ClearItems", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_ClearItems_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_ClearItems_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_ClearItems()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_ClearItems_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_ClearSelections_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_ClearSelections_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * @brief Clears all selections.  RadioButton ListInteractionStyle may reapply a selection if at least one is required\n    */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Clears all selections.  RadioButton ListInteractionStyle may reapply a selection if at least one is required" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_ClearSelections_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "ClearSelections", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_ClearSelections_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_ClearSelections_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_ClearSelections()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_ClearSelections_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics
	{
		struct VH_UmgWidget_List_eventCreateEntry_Parms
		{
			UVH_ListEntryData* data;
			UVH_UmgListEntry* widgetInstance;
			int32 overrideIdx;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_data;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_widgetInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_widgetInstance;
		static const UECodeGen_Private::FIntPropertyParams NewProp_overrideIdx;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::NewProp_data = { "data", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventCreateEntry_Parms, data), Z_Construct_UClass_UVH_ListEntryData_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::NewProp_widgetInstance_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::NewProp_widgetInstance = { "widgetInstance", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventCreateEntry_Parms, widgetInstance), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::NewProp_widgetInstance_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::NewProp_widgetInstance_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::NewProp_overrideIdx = { "overrideIdx", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventCreateEntry_Parms, overrideIdx), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::NewProp_data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::NewProp_widgetInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::NewProp_overrideIdx,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \n\x09 * @brief Adds a ListEntry widget to the list and initializes it with all appropriate data.\n\x09 * @param data ListEntryData for the new list element\n\x09 * @param widgetInstance ListEntry widget we are adding to the list.\n\x09 * @param overrideIdx Optional index at which to insert new entry into the list.  List entry will be added to the end of the list if not specified\n    */" },
#endif
		{ "CPP_Default_overrideIdx", "-1" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Adds a ListEntry widget to the list and initializes it with all appropriate data.\n@param data ListEntryData for the new list element\n@param widgetInstance ListEntry widget we are adding to the list.\n@param overrideIdx Optional index at which to insert new entry into the list.  List entry will be added to the end of the list if not specified" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "CreateEntry", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::VH_UmgWidget_List_eventCreateEntry_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::VH_UmgWidget_List_eventCreateEntry_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics
	{
		struct VH_UmgWidget_List_eventCreateEntryByClass_Parms
		{
			UVH_ListEntryData* data;
			TSubclassOf<UVH_UmgListEntry>  widgetInstance;
			int32 overrideIdx;
			UVH_UmgListEntry* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_data;
		static const UECodeGen_Private::FClassPropertyParams NewProp_widgetInstance;
		static const UECodeGen_Private::FIntPropertyParams NewProp_overrideIdx;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::NewProp_data = { "data", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventCreateEntryByClass_Parms, data), Z_Construct_UClass_UVH_ListEntryData_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::NewProp_widgetInstance = { "widgetInstance", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventCreateEntryByClass_Parms, widgetInstance), Z_Construct_UClass_UClass, Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::NewProp_overrideIdx = { "overrideIdx", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventCreateEntryByClass_Parms, overrideIdx), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventCreateEntryByClass_Parms, ReturnValue), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::NewProp_data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::NewProp_widgetInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::NewProp_overrideIdx,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Creates and registers a new ListEntry widget of the specified type for the passed in data\n\x09 * @param data ListEntryData for the new list element\n\x09 * @param widgetInstance class of ListEntry widget to create/initialize.\n\x09 * @param overrideIdx Optional index at which to insert new entry into the list.  List entry will be added to the end of the list if not specified\n\x09*/" },
#endif
		{ "CPP_Default_overrideIdx", "-1" },
		{ "DeterminesOutputType", "widgetInstance" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Creates and registers a new ListEntry widget of the specified type for the passed in data\n@param data ListEntryData for the new list element\n@param widgetInstance class of ListEntry widget to create/initialize.\n@param overrideIdx Optional index at which to insert new entry into the list.  List entry will be added to the end of the list if not specified" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "CreateEntryByClass", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::VH_UmgWidget_List_eventCreateEntryByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::VH_UmgWidget_List_eventCreateEntryByClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics
	{
		struct VH_UmgWidget_List_eventDeselectEntry_Parms
		{
			UVH_UmgListEntry* entry;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_entry_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_entry;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics::NewProp_entry_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics::NewProp_entry = { "entry", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventDeselectEntry_Parms, entry), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics::NewProp_entry_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics::NewProp_entry_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics::NewProp_entry,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Deselects a specified entry.  May be disallowed by ListInteractionStyle such as with RadioButtons\n\x09 * @param entry ListEntry widget to deselect\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Deselects a specified entry.  May be disallowed by ListInteractionStyle such as with RadioButtons\n@param entry ListEntry widget to deselect" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "DeselectEntry", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics::VH_UmgWidget_List_eventDeselectEntry_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics::VH_UmgWidget_List_eventDeselectEntry_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics
	{
		struct VH_UmgWidget_List_eventGetDataIndex_Parms
		{
			const UVH_ListEntryData* data;
			int32 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_data_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_data;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::NewProp_data_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::NewProp_data = { "data", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventGetDataIndex_Parms, data), Z_Construct_UClass_UVH_ListEntryData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::NewProp_data_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::NewProp_data_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventGetDataIndex_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::NewProp_data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * @brief Retrieves the index of the ListEntry widget associated with the specified data\n\x09 * @param data ListEntryData we want to get the index for\n\x09 * @return index of the ListEntryData or INDEX_NONE (-1) if not found\n    */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Retrieves the index of the ListEntry widget associated with the specified data\n@param data ListEntryData we want to get the index for\n@return index of the ListEntryData or INDEX_NONE (-1) if not found" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "GetDataIndex", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::VH_UmgWidget_List_eventGetDataIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x44020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::VH_UmgWidget_List_eventGetDataIndex_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics
	{
		struct VH_UmgWidget_List_eventGetEntryAtIndex_Parms
		{
			int32 entryIdx;
			UVH_UmgListEntry* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_entryIdx;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::NewProp_entryIdx = { "entryIdx", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventGetEntryAtIndex_Parms, entryIdx), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventGetEntryAtIndex_Parms, ReturnValue), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::NewProp_entryIdx,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * @brief Retrieves ListEntry widget at the specified index\n\x09 * @param entryIdx Index to retrieve the list entry from\n\x09 * @retrun ListEntry widget at the specified index or nullptr if index was invalid\n    */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Retrieves ListEntry widget at the specified index\n@param entryIdx Index to retrieve the list entry from\n@retrun ListEntry widget at the specified index or nullptr if index was invalid" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "GetEntryAtIndex", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::VH_UmgWidget_List_eventGetEntryAtIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x44020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::VH_UmgWidget_List_eventGetEntryAtIndex_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics
	{
		struct VH_UmgWidget_List_eventGetEntryForData_Parms
		{
			const UVH_ListEntryData* data;
			UVH_UmgListEntry* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_data_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_data;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::NewProp_data_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::NewProp_data = { "data", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventGetEntryForData_Parms, data), Z_Construct_UClass_UVH_ListEntryData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::NewProp_data_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::NewProp_data_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventGetEntryForData_Parms, ReturnValue), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::NewProp_data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Retrieves the ListEntry widget for the specified ListEntryData\n\x09 * @param data ListEntryData to find associated ListEntry for\n\x09 * @return ListEntry widget for the specified data, or nullptr if not found\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Retrieves the ListEntry widget for the specified ListEntryData\n@param data ListEntryData to find associated ListEntry for\n@return ListEntry widget for the specified data, or nullptr if not found" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "GetEntryForData", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::VH_UmgWidget_List_eventGetEntryForData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x44020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::VH_UmgWidget_List_eventGetEntryForData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics
	{
		struct VH_UmgWidget_List_eventGetEntryIndex_Parms
		{
			const UVH_UmgListEntry* entry;
			int32 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_entry_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_entry;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::NewProp_entry_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::NewProp_entry = { "entry", nullptr, (EPropertyFlags)0x0010000000080082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventGetEntryIndex_Parms, entry), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::NewProp_entry_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::NewProp_entry_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventGetEntryIndex_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::NewProp_entry,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * @brief Finds the index of a specified entry\n\x09 * @param entry ListEntry widget to find\n\x09 * @return Index of the widget in the list, INDEX_NONE(-1) if not found\n    */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Finds the index of a specified entry\n@param entry ListEntry widget to find\n@return Index of the widget in the list, INDEX_NONE(-1) if not found" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "GetEntryIndex", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::VH_UmgWidget_List_eventGetEntryIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x44020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::VH_UmgWidget_List_eventGetEntryIndex_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics
	{
		struct VH_UmgWidget_List_eventGetListEntries_Parms
		{
			TArray<UVH_UmgListEntry*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000588, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventGetListEntries_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * @brief Retrieves a list of all list entries registered to the list\n\x09 * @return all registered list entries\n    */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Retrieves a list of all list entries registered to the list\n@return all registered list entries" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "GetListEntries", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::VH_UmgWidget_List_eventGetListEntries_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::VH_UmgWidget_List_eventGetListEntries_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_GetNumEntries_Statics
	{
		struct VH_UmgWidget_List_eventGetNumEntries_Parms
		{
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_GetNumEntries_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventGetNumEntries_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_GetNumEntries_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_GetNumEntries_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_GetNumEntries_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * @brief Retrieves the total number of entries within the list\n    */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Retrieves the total number of entries within the list" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_GetNumEntries_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "GetNumEntries", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_GetNumEntries_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetNumEntries_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_GetNumEntries_Statics::VH_UmgWidget_List_eventGetNumEntries_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetNumEntries_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_GetNumEntries_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetNumEntries_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_GetNumEntries_Statics::VH_UmgWidget_List_eventGetNumEntries_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_GetNumEntries()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_GetNumEntries_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics
	{
		struct VH_UmgWidget_List_eventGetSelectedEntries_Parms
		{
			TArray<UVH_UmgListEntry*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000588, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventGetSelectedEntries_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Retrieves a list of all selected ListEntry widgets\n\x09 * @return list of all selected ListEntry widgets\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Retrieves a list of all selected ListEntry widgets\n@return list of all selected ListEntry widgets" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "GetSelectedEntries", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::VH_UmgWidget_List_eventGetSelectedEntries_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x44020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::VH_UmgWidget_List_eventGetSelectedEntries_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices_Statics
	{
		struct VH_UmgWidget_List_eventGetSelectedIndices_Parms
		{
			TArray<int32> ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventGetSelectedIndices_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Retrieves a list of all indices that are currently selected\n\x09 * @return all currently selected indices\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Retrieves a list of all indices that are currently selected\n@return all currently selected indices" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "GetSelectedIndices", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices_Statics::VH_UmgWidget_List_eventGetSelectedIndices_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x44020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices_Statics::VH_UmgWidget_List_eventGetSelectedIndices_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics
	{
		struct VH_UmgWidget_List_eventHandleEnterPressed_Parms
		{
			UVH_UmgListEntry* entry;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_entry_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_entry;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics::NewProp_entry_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics::NewProp_entry = { "entry", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventHandleEnterPressed_Parms, entry), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics::NewProp_entry_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics::NewProp_entry_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics::NewProp_entry,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "HandleEnterPressed", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics::VH_UmgWidget_List_eventHandleEnterPressed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics::VH_UmgWidget_List_eventHandleEnterPressed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics
	{
		struct VH_UmgWidget_List_eventHandleEntryClicked_Parms
		{
			UVH_UmgListEntry* entry;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_entry_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_entry;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics::NewProp_entry_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics::NewProp_entry = { "entry", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventHandleEntryClicked_Parms, entry), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics::NewProp_entry_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics::NewProp_entry_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics::NewProp_entry,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Event Handlers\n// ---------------------------------\n// Make this not blueprint callable\n" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Event Handlers\n---------------------------------\nMake this not blueprint callable" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "HandleEntryClicked", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics::VH_UmgWidget_List_eventHandleEntryClicked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics::VH_UmgWidget_List_eventHandleEntryClicked_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics
	{
		struct VH_UmgWidget_List_eventHandleEntryDoubleClicked_Parms
		{
			UVH_UmgListEntry* entry;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_entry_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_entry;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics::NewProp_entry_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics::NewProp_entry = { "entry", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventHandleEntryDoubleClicked_Parms, entry), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics::NewProp_entry_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics::NewProp_entry_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics::NewProp_entry,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "HandleEntryDoubleClicked", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics::VH_UmgWidget_List_eventHandleEntryDoubleClicked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics::VH_UmgWidget_List_eventHandleEntryDoubleClicked_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_widgetInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_widgetInstance;
		static const UECodeGen_Private::FIntPropertyParams NewProp_insertIdx;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics::NewProp_widgetInstance_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics::NewProp_widgetInstance = { "widgetInstance", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventInsertItem_Parms, widgetInstance), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics::NewProp_widgetInstance_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics::NewProp_widgetInstance_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics::NewProp_insertIdx = { "insertIdx", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventInsertItem_Parms, insertIdx), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics::NewProp_widgetInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics::NewProp_insertIdx,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Inserts the entry to the list. Native has a default implementation to add it to a specified handler.\n\x09 * @param widgetInstance Widget that should be inserted into the list. \n\x09 */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Inserts the entry to the list. Native has a default implementation to add it to a specified handler.\n@param widgetInstance Widget that should be inserted into the list." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "InsertItem", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics::PropPointers), sizeof(VH_UmgWidget_List_eventInsertItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_UmgWidget_List_eventInsertItem_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_curSelectedEntries_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_curSelectedEntries_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_curSelectedEntries;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics::NewProp_curSelectedEntries_Inner = { "curSelectedEntries", nullptr, (EPropertyFlags)0x0000000000080000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics::NewProp_curSelectedEntries_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics::NewProp_curSelectedEntries = { "curSelectedEntries", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventOnInternalSelectionChanged_Parms, curSelectedEntries), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics::NewProp_curSelectedEntries_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics::NewProp_curSelectedEntries_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics::NewProp_curSelectedEntries_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics::NewProp_curSelectedEntries,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \n\x09 * @brief Nearly identical to signing up for the selection delegate, but easier to discover \n\x09 */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Nearly identical to signing up for the selection delegate, but easier to discover" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "OnInternalSelectionChanged", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics::PropPointers), sizeof(VH_UmgWidget_List_eventOnInternalSelectionChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_UmgWidget_List_eventOnInternalSelectionChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection_Statics
	{
		struct VH_UmgWidget_List_eventPreferSingleSelection_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_UmgWidget_List_eventPreferSingleSelection_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgWidget_List_eventPreferSingleSelection_Parms), &Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief True if InteractionStyle prefers (may not require) single selection. A List style prefers single selection but multi-select can be achieved with \n\x09 *\x09shift/ctrl keys.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief True if InteractionStyle prefers (may not require) single selection. A List style prefers single selection but multi-select can be achieved with\n     shift/ctrl keys." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "PreferSingleSelection", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection_Statics::VH_UmgWidget_List_eventPreferSingleSelection_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection_Statics::VH_UmgWidget_List_eventPreferSingleSelection_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_RebuildVisualList_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_RebuildVisualList_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Updates layout data for list and re-adds all children to layoutHandler.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Updates layout data for list and re-adds all children to layoutHandler." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_RebuildVisualList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "RebuildVisualList", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_RebuildVisualList_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_RebuildVisualList_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_RebuildVisualList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_RebuildVisualList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics
	{
		struct VH_UmgWidget_List_eventRemoveEntry_Parms
		{
			UVH_UmgListEntry* widgetInstance;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_widgetInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_widgetInstance;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::NewProp_widgetInstance_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::NewProp_widgetInstance = { "widgetInstance", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventRemoveEntry_Parms, widgetInstance), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::NewProp_widgetInstance_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::NewProp_widgetInstance_MetaData) };
	void Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_UmgWidget_List_eventRemoveEntry_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgWidget_List_eventRemoveEntry_Parms), &Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::NewProp_widgetInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * @brief Removes an entry from the list\n\x09 * @param widgetInstance Widget instance to be removed from the list\n\x09 * @return True if widgetInstance was valid and successfully removed from the list\n    */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Removes an entry from the list\n@param widgetInstance Widget instance to be removed from the list\n@return True if widgetInstance was valid and successfully removed from the list" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "RemoveEntry", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::VH_UmgWidget_List_eventRemoveEntry_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::VH_UmgWidget_List_eventRemoveEntry_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics
	{
		struct VH_UmgWidget_List_eventRemoveEntryByData_Parms
		{
			UVH_ListEntryData* data;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_data;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::NewProp_data = { "data", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventRemoveEntryByData_Parms, data), Z_Construct_UClass_UVH_ListEntryData_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_UmgWidget_List_eventRemoveEntryByData_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgWidget_List_eventRemoveEntryByData_Parms), &Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::NewProp_data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Removes a widgetInstance base on the represented ListEntryData\n\x09 * @param data Data we we want to remove from the list\n\x09 * @return true if ListEntry was successfully removed from the list\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Removes a widgetInstance base on the represented ListEntryData\n@param data Data we we want to remove from the list\n@return true if ListEntry was successfully removed from the list" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "RemoveEntryByData", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::VH_UmgWidget_List_eventRemoveEntryByData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::VH_UmgWidget_List_eventRemoveEntryByData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_widgetInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_widgetInstance;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::NewProp_widgetInstance_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::NewProp_widgetInstance = { "widgetInstance", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventRemoveItem_Parms, widgetInstance), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::NewProp_widgetInstance_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::NewProp_widgetInstance_MetaData) };
	void Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_UmgWidget_List_eventRemoveItem_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgWidget_List_eventRemoveItem_Parms), &Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::NewProp_widgetInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Removes the entry from the list.  Native has a default implementation to remove it from the specified handler.\n\x09 * @param widgetInstance Widget that should be removed from the list.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Removes the entry from the list.  Native has a default implementation to remove it from the specified handler.\n@param widgetInstance Widget that should be removed from the list." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "RemoveItem", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::PropPointers), sizeof(VH_UmgWidget_List_eventRemoveItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_UmgWidget_List_eventRemoveItem_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics
	{
		struct VH_UmgWidget_List_eventSetEntryDataSelected_Parms
		{
			UVH_ListEntryData* data;
			bool bForceClearPreviousSelections;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_data;
		static void NewProp_bForceClearPreviousSelections_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceClearPreviousSelections;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::NewProp_data = { "data", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventSetEntryDataSelected_Parms, data), Z_Construct_UClass_UVH_ListEntryData_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::NewProp_bForceClearPreviousSelections_SetBit(void* Obj)
	{
		((VH_UmgWidget_List_eventSetEntryDataSelected_Parms*)Obj)->bForceClearPreviousSelections = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::NewProp_bForceClearPreviousSelections = { "bForceClearPreviousSelections", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgWidget_List_eventSetEntryDataSelected_Parms), &Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::NewProp_bForceClearPreviousSelections_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::NewProp_data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::NewProp_bForceClearPreviousSelections,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * @brief Set ListEntry widget as selected based on specified ListEntryData\n\x09 * @param data ListEntryData we want associated ListEntry widget to be marked as selected for\n\x09 * @param bForceClearPreviousSelections True if we want all previous selections to be cleared.  Default is false\n    */" },
#endif
		{ "CPP_Default_bForceClearPreviousSelections", "false" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Set ListEntry widget as selected based on specified ListEntryData\n@param data ListEntryData we want associated ListEntry widget to be marked as selected for\n@param bForceClearPreviousSelections True if we want all previous selections to be cleared.  Default is false" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "SetEntryDataSelected", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::VH_UmgWidget_List_eventSetEntryDataSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::VH_UmgWidget_List_eventSetEntryDataSelected_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics
	{
		struct VH_UmgWidget_List_eventSetEntryIndex_Parms
		{
			UVH_UmgListEntry* entry;
			int32 desiredIndex;
			int32 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_entry_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_entry;
		static const UECodeGen_Private::FIntPropertyParams NewProp_desiredIndex;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::NewProp_entry_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::NewProp_entry = { "entry", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventSetEntryIndex_Parms, entry), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::NewProp_entry_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::NewProp_entry_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::NewProp_desiredIndex = { "desiredIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventSetEntryIndex_Parms, desiredIndex), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventSetEntryIndex_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::NewProp_entry,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::NewProp_desiredIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Moves an entry within the list to a desired index, or as close to it as possible\n\x09 * @param entry ListEntry widget we want to move\n\x09 * @param desiredIndex Index we want the entry in\n\x09 * @return Index the entry index is now at, INDEX_NONE (-1) if not in list\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Moves an entry within the list to a desired index, or as close to it as possible\n@param entry ListEntry widget we want to move\n@param desiredIndex Index we want the entry in\n@return Index the entry index is now at, INDEX_NONE (-1) if not in list" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "SetEntryIndex", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::VH_UmgWidget_List_eventSetEntryIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::VH_UmgWidget_List_eventSetEntryIndex_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics
	{
		struct VH_UmgWidget_List_eventSetEntrySelected_Parms
		{
			UVH_UmgListEntry* entry;
			bool bForceClearPreviousSelections;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_entry_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_entry;
		static void NewProp_bForceClearPreviousSelections_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceClearPreviousSelections;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::NewProp_entry_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::NewProp_entry = { "entry", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventSetEntrySelected_Parms, entry), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::NewProp_entry_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::NewProp_entry_MetaData) };
	void Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::NewProp_bForceClearPreviousSelections_SetBit(void* Obj)
	{
		((VH_UmgWidget_List_eventSetEntrySelected_Parms*)Obj)->bForceClearPreviousSelections = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::NewProp_bForceClearPreviousSelections = { "bForceClearPreviousSelections", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgWidget_List_eventSetEntrySelected_Parms), &Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::NewProp_bForceClearPreviousSelections_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::NewProp_entry,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::NewProp_bForceClearPreviousSelections,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \n\x09 * @brief Use to mark an entries selection status from external stimulus.  Subject to limitations of ListInteractionStyle. \n\x09 * @param bForceClearPreviousSelections True if we want all previous selections to be cleared.  Default is false\n\x09 */" },
#endif
		{ "CPP_Default_bForceClearPreviousSelections", "false" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Use to mark an entries selection status from external stimulus.  Subject to limitations of ListInteractionStyle.\n@param bForceClearPreviousSelections True if we want all previous selections to be cleared.  Default is false" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "SetEntrySelected", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::VH_UmgWidget_List_eventSetEntrySelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::VH_UmgWidget_List_eventSetEntrySelected_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics
	{
		struct VH_UmgWidget_List_eventSetIndexSelected_Parms
		{
			int32 entryIdx;
			bool bForceClearPreviousSelections;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_entryIdx;
		static void NewProp_bForceClearPreviousSelections_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceClearPreviousSelections;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::NewProp_entryIdx = { "entryIdx", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventSetIndexSelected_Parms, entryIdx), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::NewProp_bForceClearPreviousSelections_SetBit(void* Obj)
	{
		((VH_UmgWidget_List_eventSetIndexSelected_Parms*)Obj)->bForceClearPreviousSelections = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::NewProp_bForceClearPreviousSelections = { "bForceClearPreviousSelections", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgWidget_List_eventSetIndexSelected_Parms), &Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::NewProp_bForceClearPreviousSelections_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::NewProp_entryIdx,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::NewProp_bForceClearPreviousSelections,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * @brief Marks a specified index as selected.  InteractionStyle may clear other selection but can be affected by active modifiers such at ctrl/alt\n\x09 * @param bForceClearPreviousSelections True if we want all previous selections to be cleared.  Default is false\n    */" },
#endif
		{ "CPP_Default_bForceClearPreviousSelections", "false" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Marks a specified index as selected.  InteractionStyle may clear other selection but can be affected by active modifiers such at ctrl/alt\n@param bForceClearPreviousSelections True if we want all previous selections to be cleared.  Default is false" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "SetIndexSelected", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::VH_UmgWidget_List_eventSetIndexSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::VH_UmgWidget_List_eventSetIndexSelected_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected_Statics
	{
		struct VH_UmgWidget_List_eventSetIndicesSelected_Parms
		{
			TArray<int32> selectedIndices;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_selectedIndices_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_selectedIndices;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected_Statics::NewProp_selectedIndices_Inner = { "selectedIndices", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected_Statics::NewProp_selectedIndices = { "selectedIndices", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventSetIndicesSelected_Parms, selectedIndices), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected_Statics::NewProp_selectedIndices_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected_Statics::NewProp_selectedIndices,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \n\x09 * @brief Marks set of indices as the selected indices. We always clear previous selections or the intent of the method becomes ambiguous.  Subject\n\x09 *\x09to limitations of ListInteractionStyle.  If not all specified elements may be selected then first selectable elements will be used until limit reached\n\x09 * @param selectedIndices Set of indices we want to try and select\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Marks set of indices as the selected indices. We always clear previous selections or the intent of the method becomes ambiguous.  Subject\n     to limitations of ListInteractionStyle.  If not all specified elements may be selected then first selectable elements will be used until limit reached\n@param selectedIndices Set of indices we want to try and select" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "SetIndicesSelected", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected_Statics::VH_UmgWidget_List_eventSetIndicesSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected_Statics::VH_UmgWidget_List_eventSetIndicesSelected_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle_Statics
	{
		struct VH_UmgWidget_List_eventSetInteractionStyle_Parms
		{
			EListInteractionStyle newInteractionStyle;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_newInteractionStyle_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_newInteractionStyle;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle_Statics::NewProp_newInteractionStyle_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle_Statics::NewProp_newInteractionStyle = { "newInteractionStyle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventSetInteractionStyle_Parms, newInteractionStyle), Z_Construct_UEnum_VH_UI_EListInteractionStyle, METADATA_PARAMS(0, nullptr) }; // 3086364997
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle_Statics::NewProp_newInteractionStyle_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle_Statics::NewProp_newInteractionStyle,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Set list selection behavior for min/max number of selected items.  List: min=0, max=1  Checkbox: min=0, max=all   radioButton: min=1, max=1. \n\x09 *\x09Will deselect entries when applied if too many are selected, but should not select an entry if one is required (RadioButton)\n\x09 * @param newInteractionStyle The new interaction style to apply to the list.  \n\x09*/" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Set list selection behavior for min/max number of selected items.  List: min=0, max=1  Checkbox: min=0, max=all   radioButton: min=1, max=1.\n     Will deselect entries when applied if too many are selected, but should not select an entry if one is required (RadioButton)\n@param newInteractionStyle The new interaction style to apply to the list." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "SetInteractionStyle", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle_Statics::VH_UmgWidget_List_eventSetInteractionStyle_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle_Statics::VH_UmgWidget_List_eventSetInteractionStyle_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics
	{
		struct VH_UmgWidget_List_eventSetLayoutHandler_Parms
		{
			UPanelWidget* newLayoutHandler;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_newLayoutHandler_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_newLayoutHandler;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics::NewProp_newLayoutHandler_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics::NewProp_newLayoutHandler = { "newLayoutHandler", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventSetLayoutHandler_Parms, newLayoutHandler), Z_Construct_UClass_UPanelWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics::NewProp_newLayoutHandler_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics::NewProp_newLayoutHandler_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics::NewProp_newLayoutHandler,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Assign the panel widget that entries will be added to.  Assign this to allow the list to interact with the panel directly for add/remove/index operations\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Assign the panel widget that entries will be added to.  Assign this to allow the list to interact with the panel directly for add/remove/index operations" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "SetLayoutHandler", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics::VH_UmgWidget_List_eventSetLayoutHandler_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics::VH_UmgWidget_List_eventSetLayoutHandler_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics
	{
		struct VH_UmgWidget_List_eventSetSlotSizeData_Parms
		{
			UPanelSlot* slotHandle;
			FSlateChildSize sizingData;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_slotHandle_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_slotHandle;
		static const UECodeGen_Private::FStructPropertyParams NewProp_sizingData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::NewProp_slotHandle_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::NewProp_slotHandle = { "slotHandle", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventSetSlotSizeData_Parms, slotHandle), Z_Construct_UClass_UPanelSlot_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::NewProp_slotHandle_MetaData), Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::NewProp_slotHandle_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::NewProp_sizingData = { "sizingData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventSetSlotSizeData_Parms, sizingData), Z_Construct_UScriptStruct_FSlateChildSize, METADATA_PARAMS(0, nullptr) }; // 1742874166
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::NewProp_slotHandle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::NewProp_sizingData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Assign sizing data to a specified slot in the HeaderLayoutHandler\n\x09 * @param slotHandle Specific slot we want to update the sizing data for.  Mostly assigned dynamically the list, but can be handled externally\n\x09 * @param sizingData sizingData that we want to apply to the panel slot\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Assign sizing data to a specified slot in the HeaderLayoutHandler\n@param slotHandle Specific slot we want to update the sizing data for.  Mostly assigned dynamically the list, but can be handled externally\n@param sizingData sizingData that we want to apply to the panel slot" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "SetSlotSizeData", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::VH_UmgWidget_List_eventSetSlotSizeData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::VH_UmgWidget_List_eventSetSlotSizeData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics
	{
		struct VH_UmgWidget_List_eventSortByColumn_Parms
		{
			int32 columnIdx;
			ESortType sortType;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_columnIdx;
		static const UECodeGen_Private::FBytePropertyParams NewProp_sortType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_sortType;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::NewProp_columnIdx = { "columnIdx", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventSortByColumn_Parms, columnIdx), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::NewProp_sortType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::NewProp_sortType = { "sortType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventSortByColumn_Parms, sortType), Z_Construct_UEnum_VH_UI_ESortType, METADATA_PARAMS(0, nullptr) }; // 913682698
	void Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_UmgWidget_List_eventSortByColumn_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgWidget_List_eventSortByColumn_Parms), &Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::NewProp_columnIdx,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::NewProp_sortType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::NewProp_sortType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \n\x09 * @brief Sorts list entry data\n\x09 * @param columnIdx Column index to sort by\n\x09 * @param sortType Specified sort direction such as ascending or descending \n\x09 * @return True if successfully sorted by specified column and type\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Sorts list entry data\n@param columnIdx Column index to sort by\n@param sortType Specified sort direction such as ascending or descending\n@return True if successfully sorted by specified column and type" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "SortByColumn", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::VH_UmgWidget_List_eventSortByColumn_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::VH_UmgWidget_List_eventSortByColumn_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_UpdateAllCellSizes_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_UpdateAllCellSizes_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Requests an update of all cell sizes by asking header for desired column sizes and applying to ListEntry widgets\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Requests an update of all cell sizes by asking header for desired column sizes and applying to ListEntry widgets" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_UpdateAllCellSizes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "UpdateAllCellSizes", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_UpdateAllCellSizes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_UpdateAllCellSizes_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_UpdateAllCellSizes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_UpdateAllCellSizes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgWidget_List_UpdateCellSizes_Statics
	{
		struct VH_UmgWidget_List_eventUpdateCellSizes_Parms
		{
			int32 columnIndex;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_columnIndex;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgWidget_List_UpdateCellSizes_Statics::NewProp_columnIndex = { "columnIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgWidget_List_eventUpdateCellSizes_Parms, columnIndex), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgWidget_List_UpdateCellSizes_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgWidget_List_UpdateCellSizes_Statics::NewProp_columnIndex,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgWidget_List_UpdateCellSizes_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Requests column size from header for specified column index and applies it to all ListEntries\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Requests column size from header for specified column index and applies it to all ListEntries" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgWidget_List_UpdateCellSizes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgWidget_List, nullptr, "UpdateCellSizes", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgWidget_List_UpdateCellSizes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_UpdateCellSizes_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_UpdateCellSizes_Statics::VH_UmgWidget_List_eventUpdateCellSizes_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_UpdateCellSizes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgWidget_List_UpdateCellSizes_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgWidget_List_UpdateCellSizes_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgWidget_List_UpdateCellSizes_Statics::VH_UmgWidget_List_eventUpdateCellSizes_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgWidget_List_UpdateCellSizes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgWidget_List_UpdateCellSizes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_UmgWidget_List);
	UClass* Z_Construct_UClass_UVH_UmgWidget_List_NoRegister()
	{
		return UVH_UmgWidget_List::StaticClass();
	}
	struct Z_Construct_UClass_UVH_UmgWidget_List_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DelegateListSelectionChanged_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_DelegateListSelectionChanged;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DelegateEntryClicked_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_DelegateEntryClicked;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DelegateEntryDoubleClicked_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_DelegateEntryDoubleClicked;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DelegateEnterPressed_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_DelegateEnterPressed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RegionLayoutHandler_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RegionLayoutHandler;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LayoutHandler_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LayoutHandler;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ListEntries_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ListEntries_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ListEntries;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ListInteractionStyle_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ListInteractionStyle_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ListInteractionStyle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnSortRequested_MetaData[];
#endif
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_OnSortRequested;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bShowHeader_MetaData[];
#endif
		static void NewProp_bShowHeader_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowHeader;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDynamicColumnSizes_MetaData[];
#endif
		static void NewProp_bDynamicColumnSizes_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDynamicColumnSizes;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedEntries_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SelectedEntries_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SelectedEntries;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_UmgWidget_List_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_UmgWidget_List_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_AddItem, "AddItem" }, // 2689174250
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_CanMultiSelect, "CanMultiSelect" }, // 1470338152
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_CanToggleSelection, "CanToggleSelection" }, // 1335949469
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_ClearEntries, "ClearEntries" }, // 1958433023
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_ClearItems, "ClearItems" }, // 4205001274
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_ClearSelections, "ClearSelections" }, // 3788304986
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntry, "CreateEntry" }, // 637383770
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_CreateEntryByClass, "CreateEntryByClass" }, // 2339129536
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_DeselectEntry, "DeselectEntry" }, // 1506174014
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_GetDataIndex, "GetDataIndex" }, // 2899195863
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryAtIndex, "GetEntryAtIndex" }, // 3618547827
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryForData, "GetEntryForData" }, // 3370377971
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_GetEntryIndex, "GetEntryIndex" }, // 2614212732
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_GetListEntries, "GetListEntries" }, // 3245247641
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_GetNumEntries, "GetNumEntries" }, // 765053822
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedEntries, "GetSelectedEntries" }, // 2528813023
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_GetSelectedIndices, "GetSelectedIndices" }, // 1030849211
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_HandleEnterPressed, "HandleEnterPressed" }, // 3350887372
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryClicked, "HandleEntryClicked" }, // 929462706
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_HandleEntryDoubleClicked, "HandleEntryDoubleClicked" }, // 3843942568
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_InsertItem, "InsertItem" }, // 116312232
		{ &Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature, "OnEntryEvent__DelegateSignature" }, // 1386365874
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_OnInternalSelectionChanged, "OnInternalSelectionChanged" }, // 371146485
		{ &Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature, "OnListSelectionChanged__DelegateSignature" }, // 1847164044
		{ &Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature, "OnSortRequest__DelegateSignature" }, // 1897377023
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_PreferSingleSelection, "PreferSingleSelection" }, // 2111220062
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_RebuildVisualList, "RebuildVisualList" }, // 909893831
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntry, "RemoveEntry" }, // 3514055455
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_RemoveEntryByData, "RemoveEntryByData" }, // 450818533
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_RemoveItem, "RemoveItem" }, // 1547750728
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryDataSelected, "SetEntryDataSelected" }, // 581727117
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_SetEntryIndex, "SetEntryIndex" }, // 3845865843
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_SetEntrySelected, "SetEntrySelected" }, // 4258181437
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_SetIndexSelected, "SetIndexSelected" }, // 4059591800
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_SetIndicesSelected, "SetIndicesSelected" }, // 2747252373
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_SetInteractionStyle, "SetInteractionStyle" }, // 1548789651
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_SetLayoutHandler, "SetLayoutHandler" }, // 593243284
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_SetSlotSizeData, "SetSlotSizeData" }, // 3912761307
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_SortByColumn, "SortByColumn" }, // 3089336908
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_UpdateAllCellSizes, "UpdateAllCellSizes" }, // 147365138
		{ &Z_Construct_UFunction_UVH_UmgWidget_List_UpdateCellSizes, "UpdateCellSizes" }, // 3272579927
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgWidget_List_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * @brief Class that is responsible for managing list entry selection and activation. \n *\x09The primary function of the list is managing list entry states. List can be created dynamically and does not need a widget representation.\n *\x09Lists are composed of 4 basic elements\n *\x09\x09""1: the list which manages the selection states of elements\n *\x09\x09""2: listEntries which are widgets responsible for visualization of a list element and all interactions. May not have list entries for all data, especially if there is a lot of data where only a \n *\x09\x09\x09small subset is visible at any time. Generally assigned to data as it is added since there can be multiple List Entry classes used within a single list.\n *\x09\x09""3: ListEntryData which is the data for all list elements.  Data is contained for all elements even those not visualized\n *\x09\x09""4: ListEntry Layout is handled by an assigned panel which is resposible for layout out all List entries.  Entries can be swapped from vertical, horizontal, grid, etc. without changing anything\n *\x09\x09\x09""else about the list.  Assign through 'AssignLayoutHandler'\n * \n *\x09Most common implementation is to create a UVH_UmgWidget_List widget at runtime, call 'SetLayoutHandler' on it with the panel to layout entries, and add entries to it through CreateEntryByClass.\n *\x09Unique listEntryData class and a ListEntry blueprint are nearly always desired.\n */" },
#endif
		{ "HideCategories", "VH List" },
		{ "IncludePath", "Deprecated/Public/VH_UmgWidget_List.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Class that is responsible for managing list entry selection and activation.\n    The primary function of the list is managing list entry states. List can be created dynamically and does not need a widget representation.\n    Lists are composed of 4 basic elements\n            1: the list which manages the selection states of elements\n            2: listEntries which are widgets responsible for visualization of a list element and all interactions. May not have list entries for all data, especially if there is a lot of data where only a\n                    small subset is visible at any time. Generally assigned to data as it is added since there can be multiple List Entry classes used within a single list.\n            3: ListEntryData which is the data for all list elements.  Data is contained for all elements even those not visualized\n            4: ListEntry Layout is handled by an assigned panel which is resposible for layout out all List entries.  Entries can be swapped from vertical, horizontal, grid, etc. without changing anything\n                    else about the list.  Assign through 'AssignLayoutHandler'\n\n    Most common implementation is to create a UVH_UmgWidget_List widget at runtime, call 'SetLayoutHandler' on it with the panel to layout entries, and add entries to it through CreateEntryByClass.\n    Unique listEntryData class and a ListEntry blueprint are nearly always desired." },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateListSelectionChanged_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \n\x09 * @brief Called whenever any selection has changed \n\x09 * @param curSelectedEntries List of all entries that are now selected.  Range of allowed simultaneously selected entries is defined by listInteractionStyle\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Called whenever any selection has changed\n@param curSelectedEntries List of all entries that are now selected.  Range of allowed simultaneously selected entries is defined by listInteractionStyle" },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateListSelectionChanged = { "DelegateListSelectionChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_UmgWidget_List, DelegateListSelectionChanged), Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateListSelectionChanged_MetaData), Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateListSelectionChanged_MetaData) }; // 1847164044
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateEntryClicked_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \n\x09 * @brief Called when a list entry has received a click event\n\x09 * @param data Data associated with the clicked list entry\n\x09 * @param listEntry List entry widget that was clicked\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Called when a list entry has received a click event\n@param data Data associated with the clicked list entry\n@param listEntry List entry widget that was clicked" },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateEntryClicked = { "DelegateEntryClicked", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_UmgWidget_List, DelegateEntryClicked), Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateEntryClicked_MetaData), Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateEntryClicked_MetaData) }; // 1386365874
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateEntryDoubleClicked_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Called when a list entry has received a double click event\n\x09 * @param data Data associated with the double clicked list entry\n\x09 * @param listEntry List entry widget that was double clicked\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Called when a list entry has received a double click event\n@param data Data associated with the double clicked list entry\n@param listEntry List entry widget that was double clicked" },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateEntryDoubleClicked = { "DelegateEntryDoubleClicked", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_UmgWidget_List, DelegateEntryDoubleClicked), Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateEntryDoubleClicked_MetaData), Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateEntryDoubleClicked_MetaData) }; // 1386365874
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateEnterPressed_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09 * @brief Called when a list entry has received an enter press event.  List entry widget must have been focused to receive event\n\x09 * @param data Data associated with the list entry\n\x09 * @param listEntry List entry widget that received an enter press event\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Called when a list entry has received an enter press event.  List entry widget must have been focused to receive event\n@param data Data associated with the list entry\n@param listEntry List entry widget that received an enter press event" },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateEnterPressed = { "DelegateEnterPressed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_UmgWidget_List, DelegateEnterPressed), Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateEnterPressed_MetaData), Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateEnterPressed_MetaData) }; // 1386365874
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_RegionLayoutHandler_MetaData[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Use this to layout all the header regions visually. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Use this to layout all the header regions visually." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_RegionLayoutHandler = { "RegionLayoutHandler", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_UmgWidget_List, RegionLayoutHandler), Z_Construct_UClass_UPanelWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_RegionLayoutHandler_MetaData), Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_RegionLayoutHandler_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_LayoutHandler_MetaData[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Panel that is responsible for visual layout of all list entries. Can be null if list widget handles layout of entries (not recommended) */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Panel that is responsible for visual layout of all list entries. Can be null if list widget handles layout of entries (not recommended)" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_LayoutHandler = { "LayoutHandler", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_UmgWidget_List, LayoutHandler), Z_Construct_UClass_UPanelWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_LayoutHandler_MetaData), Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_LayoutHandler_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_ListEntries_Inner = { "ListEntries", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_ListEntries_MetaData[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** List of all ListEntry widgets that are registered */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "List of all ListEntry widgets that are registered" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_ListEntries = { "ListEntries", nullptr, (EPropertyFlags)0x001000800000001d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_UmgWidget_List, ListEntries), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_ListEntries_MetaData), Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_ListEntries_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_ListInteractionStyle_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_ListInteractionStyle_MetaData[] = {
		{ "Category", "Defaults" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** How list should be interacted with or thought of from a high level.  Defines range of allowed item selections and selection/deselection behavior. \n\x09 *\x09""For instance, RadioButton style required exactly one active selection at all times\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "How list should be interacted with or thought of from a high level.  Defines range of allowed item selections and selection/deselection behavior.\n    For instance, RadioButton style required exactly one active selection at all times" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_ListInteractionStyle = { "ListInteractionStyle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_UmgWidget_List, ListInteractionStyle), Z_Construct_UEnum_VH_UI_EListInteractionStyle, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_ListInteractionStyle_MetaData), Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_ListInteractionStyle_MetaData) }; // 3086364997
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_OnSortRequested_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \n\x09 * @brief For NATIVE ONLY requests for sorting.  Consider using in conjunction with a BlueprintNativeEvent.  LastSortColumn and LastSortType data from previous sort and have not yet \n\x09 *\x09""been updated.\n\x09 * @param sortColumn column the sort was requested for\n\x09 * @param sortType If sort should be in ascending or descending order\n\x09 * @return bool True if sort was successful\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief For NATIVE ONLY requests for sorting.  Consider using in conjunction with a BlueprintNativeEvent.  LastSortColumn and LastSortType data from previous sort and have not yet\n     been updated.\n@param sortColumn column the sort was requested for\n@param sortType If sort should be in ascending or descending order\n@return bool True if sort was successful" },
#endif
	};
#endif
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_OnSortRequested = { "OnSortRequested", nullptr, (EPropertyFlags)0x0010000000080000, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_UmgWidget_List, OnSortRequested), Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_OnSortRequested_MetaData), Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_OnSortRequested_MetaData) }; // 1897377023
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_bShowHeader_MetaData[] = {
		{ "Category", "VH List" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** NOT CURRENTLY IMPLEMENTED */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "NOT CURRENTLY IMPLEMENTED" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_bShowHeader_SetBit(void* Obj)
	{
		((UVH_UmgWidget_List*)Obj)->bShowHeader = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_bShowHeader = { "bShowHeader", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_UmgWidget_List), &Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_bShowHeader_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_bShowHeader_MetaData), Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_bShowHeader_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_bDynamicColumnSizes_MetaData[] = {
		{ "Category", "Defaults" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** NOT CURRENTLY IMPLEMENTED */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "NOT CURRENTLY IMPLEMENTED" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_bDynamicColumnSizes_SetBit(void* Obj)
	{
		((UVH_UmgWidget_List*)Obj)->bDynamicColumnSizes = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_bDynamicColumnSizes = { "bDynamicColumnSizes", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_UmgWidget_List), &Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_bDynamicColumnSizes_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_bDynamicColumnSizes_MetaData), Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_bDynamicColumnSizes_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_SelectedEntries_Inner = { "SelectedEntries", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_SelectedEntries_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** All currently selected entries*/" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgWidget_List.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "All currently selected entries" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_SelectedEntries = { "SelectedEntries", nullptr, (EPropertyFlags)0x0020088000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_UmgWidget_List, SelectedEntries), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_SelectedEntries_MetaData), Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_SelectedEntries_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVH_UmgWidget_List_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateListSelectionChanged,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateEntryClicked,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateEntryDoubleClicked,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_DelegateEnterPressed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_RegionLayoutHandler,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_LayoutHandler,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_ListEntries_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_ListEntries,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_ListInteractionStyle_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_ListInteractionStyle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_OnSortRequested,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_bShowHeader,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_bDynamicColumnSizes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_SelectedEntries_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgWidget_List_Statics::NewProp_SelectedEntries,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_UmgWidget_List_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_UmgWidget_List>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_UmgWidget_List_Statics::ClassParams = {
		&UVH_UmgWidget_List::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVH_UmgWidget_List_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_UmgWidget_List_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgWidget_List_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVH_UmgWidget_List()
	{
		if (!Z_Registration_Info_UClass_UVH_UmgWidget_List.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_UmgWidget_List.OuterSingleton, Z_Construct_UClass_UVH_UmgWidget_List_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_UmgWidget_List.OuterSingleton;
	}
	template<> VH_UI_API UClass* StaticClass<UVH_UmgWidget_List>()
	{
		return UVH_UmgWidget_List::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_UmgWidget_List);
	UVH_UmgWidget_List::~UVH_UmgWidget_List() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_Statics::EnumInfo[] = {
		{ EListInteractionStyle_StaticEnum, TEXT("EListInteractionStyle"), &Z_Registration_Info_UEnum_EListInteractionStyle, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3086364997U) },
		{ ESortType_StaticEnum, TEXT("ESortType"), &Z_Registration_Info_UEnum_ESortType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 913682698U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_UmgWidget_List, UVH_UmgWidget_List::StaticClass, TEXT("UVH_UmgWidget_List"), &Z_Registration_Info_UClass_UVH_UmgWidget_List, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_UmgWidget_List), 4204469136U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_211452931(TEXT("/Script/VH_UI"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
