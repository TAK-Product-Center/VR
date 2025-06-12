// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Deprecated/Public/VH_UmgListEntry.h"
#include "Components/SlateWrapperTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_UmgListEntry() {}
// Cross Module References
	UMG_API UClass* Z_Construct_UClass_UPanelWidget_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UMG_API UScriptStruct* Z_Construct_UScriptStruct_FSlateChildSize();
	UPackage* Z_Construct_UPackage__Script_VH_UI();
	VH_UI_API UClass* Z_Construct_UClass_UVH_ListEntryData_NoRegister();
	VH_UI_API UClass* Z_Construct_UClass_UVH_UmgListEntry();
	VH_UI_API UClass* Z_Construct_UClass_UVH_UmgListEntry_NoRegister();
	VH_UI_API UClass* Z_Construct_UClass_UVH_UmgWidget_List_NoRegister();
	VH_UI_API UEnum* Z_Construct_UEnum_VH_UI_EListInteractionState();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics
	{
		struct _Script_VH_UI_eventOnSelected_Parms
		{
			UVH_UmgListEntry* entrySelected;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_entrySelected_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_entrySelected;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics::NewProp_entrySelected_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics::NewProp_entrySelected = { "entrySelected", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VH_UI_eventOnSelected_Parms, entrySelected), Z_Construct_UClass_UVH_UmgListEntry_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics::NewProp_entrySelected_MetaData), Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics::NewProp_entrySelected_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics::NewProp_entrySelected,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_VH_UI, nullptr, "OnSelected__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics::_Script_VH_UI_eventOnSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics::_Script_VH_UI_eventOnSelected_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnSelected_DelegateWrapper(const FScriptDelegate& OnSelected, UVH_UmgListEntry* entrySelected)
{
	struct _Script_VH_UI_eventOnSelected_Parms
	{
		UVH_UmgListEntry* entrySelected;
	};
	_Script_VH_UI_eventOnSelected_Parms Parms;
	Parms.entrySelected=entrySelected;
	OnSelected.ProcessDelegate<UObject>(&Parms);
}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EListInteractionState;
	static UEnum* EListInteractionState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EListInteractionState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EListInteractionState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_UI_EListInteractionState, (UObject*)Z_Construct_UPackage__Script_VH_UI(), TEXT("EListInteractionState"));
		}
		return Z_Registration_Info_UEnum_EListInteractionState.OuterSingleton;
	}
	template<> VH_UI_API UEnum* StaticEnum<EListInteractionState>()
	{
		return EListInteractionState_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_UI_EListInteractionState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_UI_EListInteractionState_Statics::Enumerators[] = {
		{ "EListInteractionState::ELIS_Available", (int64)EListInteractionState::ELIS_Available },
		{ "EListInteractionState::ELIS_AvailablePressed", (int64)EListInteractionState::ELIS_AvailablePressed },
		{ "EListInteractionState::ELIS_Hovered", (int64)EListInteractionState::ELIS_Hovered },
		{ "EListInteractionState::ELIS_Selected", (int64)EListInteractionState::ELIS_Selected },
		{ "EListInteractionState::ELIS_SelectedPressed", (int64)EListInteractionState::ELIS_SelectedPressed },
		{ "EListInteractionState::ELIS_SelectedHovered", (int64)EListInteractionState::ELIS_SelectedHovered },
		{ "EListInteractionState::ELIS_Disabled", (int64)EListInteractionState::ELIS_Disabled },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_UI_EListInteractionState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ELIS_Available.Comment", "/** No interaction happening */" },
		{ "ELIS_Available.Name", "EListInteractionState::ELIS_Available" },
		{ "ELIS_Available.ToolTip", "No interaction happening" },
		{ "ELIS_AvailablePressed.Name", "EListInteractionState::ELIS_AvailablePressed" },
		{ "ELIS_Disabled.Comment", "/** Currently not Used */" },
		{ "ELIS_Disabled.Name", "EListInteractionState::ELIS_Disabled" },
		{ "ELIS_Disabled.ToolTip", "Currently not Used" },
		{ "ELIS_Hovered.Comment", "/** Being hovered and nothing is clicked */" },
		{ "ELIS_Hovered.Name", "EListInteractionState::ELIS_Hovered" },
		{ "ELIS_Hovered.ToolTip", "Being hovered and nothing is clicked" },
		{ "ELIS_Selected.Comment", "/** Currently Selected*/" },
		{ "ELIS_Selected.Name", "EListInteractionState::ELIS_Selected" },
		{ "ELIS_Selected.ToolTip", "Currently Selected" },
		{ "ELIS_SelectedHovered.Comment", "/** This is both selected and hovered */" },
		{ "ELIS_SelectedHovered.Name", "EListInteractionState::ELIS_SelectedHovered" },
		{ "ELIS_SelectedHovered.ToolTip", "This is both selected and hovered" },
		{ "ELIS_SelectedPressed.Name", "EListInteractionState::ELIS_SelectedPressed" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_UI_EListInteractionState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_UI,
		nullptr,
		"EListInteractionState",
		"EListInteractionState",
		Z_Construct_UEnum_VH_UI_EListInteractionState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_UI_EListInteractionState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_UI_EListInteractionState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_UI_EListInteractionState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_UI_EListInteractionState()
	{
		if (!Z_Registration_Info_UEnum_EListInteractionState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EListInteractionState.InnerSingleton, Z_Construct_UEnum_VH_UI_EListInteractionState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EListInteractionState.InnerSingleton;
	}
	DEFINE_FUNCTION(UVH_UmgListEntry::execSetLayoutHandler)
	{
		P_GET_OBJECT(UPanelWidget,Z_Param_newLayoutHandler);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetLayoutHandler(Z_Param_newLayoutHandler);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgListEntry::execIsDisabled)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsDisabled();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgListEntry::execIsSelected)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsSelected();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgListEntry::execK2_IsHovered)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->K2_IsHovered();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgListEntry::execSetHovered)
	{
		P_GET_UBOOL(Z_Param_newHovered);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetHovered(Z_Param_newHovered);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgListEntry::execSetSelected)
	{
		P_GET_UBOOL(Z_Param_isSelected);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSelected(Z_Param_isSelected);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgListEntry::execSelectedChanged)
	{
		P_GET_UBOOL(Z_Param_isSelected);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SelectedChanged(Z_Param_isSelected);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgListEntry::execInitializeLayout)
	{
		P_GET_TARRAY_REF(FSlateChildSize,Z_Param_Out_layoutData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->InitializeLayout(Z_Param_Out_layoutData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgListEntry::execIsLayoutInitialized)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsLayoutInitialized();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgListEntry::execGetInteractionState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EListInteractionState*)Z_Param__Result=P_THIS->GetInteractionState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgListEntry::execSetInteractionState)
	{
		P_GET_ENUM(EListInteractionState,Z_Param_newState);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetInteractionState(EListInteractionState(Z_Param_newState));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgListEntry::execGetHoverText)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FText*)Z_Param__Result=P_THIS->GetHoverText();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgListEntry::execGetIndexInList)
	{
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_outListIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetIndexInList(Z_Param_Out_outListIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgListEntry::execSetColumnSize)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_columnIndex);
		P_GET_STRUCT_REF(FSlateChildSize,Z_Param_Out_sizingData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SetColumnSize(Z_Param_columnIndex,Z_Param_Out_sizingData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgListEntry::execGetData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UVH_ListEntryData**)Z_Param__Result=P_THIS->GetData();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_UmgListEntry::execSetData)
	{
		P_GET_OBJECT(UVH_ListEntryData,Z_Param_newData);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetData(Z_Param_newData);
		P_NATIVE_END;
	}
	struct VH_UmgListEntry_eventOnAddedToList_Parms
	{
		int32 indexInList;
	};
	struct VH_UmgListEntry_eventOnDataSet_Parms
	{
		UVH_ListEntryData* newData;
	};
	struct VH_UmgListEntry_eventOnInteractionStateChanged_Parms
	{
		EListInteractionState newState;
	};
	struct VH_UmgListEntry_eventOnSelectedChanged_Parms
	{
		bool isSelected;
	};
	static FName NAME_UVH_UmgListEntry_OnAddedToList = FName(TEXT("OnAddedToList"));
	void UVH_UmgListEntry::OnAddedToList(int32 indexInList)
	{
		VH_UmgListEntry_eventOnAddedToList_Parms Parms;
		Parms.indexInList=indexInList;
		ProcessEvent(FindFunctionChecked(NAME_UVH_UmgListEntry_OnAddedToList),&Parms);
	}
	static FName NAME_UVH_UmgListEntry_OnDataSet = FName(TEXT("OnDataSet"));
	void UVH_UmgListEntry::OnDataSet(UVH_ListEntryData* newData)
	{
		VH_UmgListEntry_eventOnDataSet_Parms Parms;
		Parms.newData=newData;
		ProcessEvent(FindFunctionChecked(NAME_UVH_UmgListEntry_OnDataSet),&Parms);
	}
	static FName NAME_UVH_UmgListEntry_OnInteractionStateChanged = FName(TEXT("OnInteractionStateChanged"));
	void UVH_UmgListEntry::OnInteractionStateChanged(EListInteractionState newState)
	{
		VH_UmgListEntry_eventOnInteractionStateChanged_Parms Parms;
		Parms.newState=newState;
		ProcessEvent(FindFunctionChecked(NAME_UVH_UmgListEntry_OnInteractionStateChanged),&Parms);
	}
	static FName NAME_UVH_UmgListEntry_OnSelectedChanged = FName(TEXT("OnSelectedChanged"));
	void UVH_UmgListEntry::OnSelectedChanged(bool isSelected)
	{
		VH_UmgListEntry_eventOnSelectedChanged_Parms Parms;
		Parms.isSelected=isSelected ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UVH_UmgListEntry_OnSelectedChanged),&Parms);
	}
	void UVH_UmgListEntry::StaticRegisterNativesUVH_UmgListEntry()
	{
		UClass* Class = UVH_UmgListEntry::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetData", &UVH_UmgListEntry::execGetData },
			{ "GetHoverText", &UVH_UmgListEntry::execGetHoverText },
			{ "GetIndexInList", &UVH_UmgListEntry::execGetIndexInList },
			{ "GetInteractionState", &UVH_UmgListEntry::execGetInteractionState },
			{ "InitializeLayout", &UVH_UmgListEntry::execInitializeLayout },
			{ "IsDisabled", &UVH_UmgListEntry::execIsDisabled },
			{ "IsLayoutInitialized", &UVH_UmgListEntry::execIsLayoutInitialized },
			{ "IsSelected", &UVH_UmgListEntry::execIsSelected },
			{ "K2_IsHovered", &UVH_UmgListEntry::execK2_IsHovered },
			{ "SelectedChanged", &UVH_UmgListEntry::execSelectedChanged },
			{ "SetColumnSize", &UVH_UmgListEntry::execSetColumnSize },
			{ "SetData", &UVH_UmgListEntry::execSetData },
			{ "SetHovered", &UVH_UmgListEntry::execSetHovered },
			{ "SetInteractionState", &UVH_UmgListEntry::execSetInteractionState },
			{ "SetLayoutHandler", &UVH_UmgListEntry::execSetLayoutHandler },
			{ "SetSelected", &UVH_UmgListEntry::execSetSelected },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_GetData_Statics
	{
		struct VH_UmgListEntry_eventGetData_Parms
		{
			UVH_ListEntryData* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_GetData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgListEntry_eventGetData_Parms, ReturnValue), Z_Construct_UClass_UVH_ListEntryData_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_GetData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_GetData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_GetData_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List Entry" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_GetData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "GetData", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_GetData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_GetData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgListEntry_GetData_Statics::VH_UmgListEntry_eventGetData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_GetData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_GetData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_GetData_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgListEntry_GetData_Statics::VH_UmgListEntry_eventGetData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_GetData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_GetData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_GetHoverText_Statics
	{
		struct VH_UmgListEntry_eventGetHoverText_Parms
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
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_GetHoverText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgListEntry_eventGetHoverText_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_GetHoverText_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_GetHoverText_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_GetHoverText_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List Entry" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_GetHoverText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "GetHoverText", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_GetHoverText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_GetHoverText_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgListEntry_GetHoverText_Statics::VH_UmgListEntry_eventGetHoverText_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_GetHoverText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_GetHoverText_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_GetHoverText_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgListEntry_GetHoverText_Statics::VH_UmgListEntry_eventGetHoverText_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_GetHoverText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_GetHoverText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics
	{
		struct VH_UmgListEntry_eventGetIndexInList_Parms
		{
			int32 outListIndex;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_outListIndex;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::NewProp_outListIndex = { "outListIndex", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgListEntry_eventGetIndexInList_Parms, outListIndex), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_UmgListEntry_eventGetIndexInList_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgListEntry_eventGetIndexInList_Parms), &Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::NewProp_outListIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** gets the index of this entry in a list if it is part of one.  False is returned if there is not a valid list */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "gets the index of this entry in a list if it is part of one.  False is returned if there is not a valid list" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "GetIndexInList", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::VH_UmgListEntry_eventGetIndexInList_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::VH_UmgListEntry_eventGetIndexInList_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState_Statics
	{
		struct VH_UmgListEntry_eventGetInteractionState_Parms
		{
			EListInteractionState ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgListEntry_eventGetInteractionState_Parms, ReturnValue), Z_Construct_UEnum_VH_UI_EListInteractionState, METADATA_PARAMS(0, nullptr) }; // 2342253011
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List Entry" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "GetInteractionState", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState_Statics::VH_UmgListEntry_eventGetInteractionState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState_Statics::VH_UmgListEntry_eventGetInteractionState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics
	{
		struct VH_UmgListEntry_eventInitializeLayout_Parms
		{
			TArray<FSlateChildSize> layoutData;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_layoutData_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_layoutData;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::NewProp_layoutData_Inner = { "layoutData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSlateChildSize, METADATA_PARAMS(0, nullptr) }; // 1742874166
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::NewProp_layoutData = { "layoutData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgListEntry_eventInitializeLayout_Parms, layoutData), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1742874166
	void Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_UmgListEntry_eventInitializeLayout_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgListEntry_eventInitializeLayout_Parms), &Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::NewProp_layoutData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::NewProp_layoutData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List Entry" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "InitializeLayout", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::VH_UmgListEntry_eventInitializeLayout_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::VH_UmgListEntry_eventInitializeLayout_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled_Statics
	{
		struct VH_UmgListEntry_eventIsDisabled_Parms
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
	void Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_UmgListEntry_eventIsDisabled_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgListEntry_eventIsDisabled_Parms), &Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "IsDisabled", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled_Statics::VH_UmgListEntry_eventIsDisabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled_Statics::VH_UmgListEntry_eventIsDisabled_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized_Statics
	{
		struct VH_UmgListEntry_eventIsLayoutInitialized_Parms
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
	void Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_UmgListEntry_eventIsLayoutInitialized_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgListEntry_eventIsLayoutInitialized_Parms), &Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List Entry" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "IsLayoutInitialized", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized_Statics::VH_UmgListEntry_eventIsLayoutInitialized_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized_Statics::VH_UmgListEntry_eventIsLayoutInitialized_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_IsSelected_Statics
	{
		struct VH_UmgListEntry_eventIsSelected_Parms
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
	void Z_Construct_UFunction_UVH_UmgListEntry_IsSelected_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_UmgListEntry_eventIsSelected_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_IsSelected_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgListEntry_eventIsSelected_Parms), &Z_Construct_UFunction_UVH_UmgListEntry_IsSelected_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_IsSelected_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_IsSelected_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_IsSelected_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_IsSelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "IsSelected", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_IsSelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_IsSelected_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgListEntry_IsSelected_Statics::VH_UmgListEntry_eventIsSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_IsSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_IsSelected_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_IsSelected_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgListEntry_IsSelected_Statics::VH_UmgListEntry_eventIsSelected_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_IsSelected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_IsSelected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered_Statics
	{
		struct VH_UmgListEntry_eventK2_IsHovered_Parms
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
	void Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_UmgListEntry_eventK2_IsHovered_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgListEntry_eventK2_IsHovered_Parms), &Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** @return true if the widget is currently being hovered by a pointer device */" },
#endif
		{ "DisplayName", "Is Hovered" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@return true if the widget is currently being hovered by a pointer device" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "K2_IsHovered", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered_Statics::VH_UmgListEntry_eventK2_IsHovered_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered_Statics::VH_UmgListEntry_eventK2_IsHovered_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_OnAddedToList_Statics
	{
		static const UECodeGen_Private::FIntPropertyParams NewProp_indexInList;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_OnAddedToList_Statics::NewProp_indexInList = { "indexInList", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgListEntry_eventOnAddedToList_Parms, indexInList), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_OnAddedToList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_OnAddedToList_Statics::NewProp_indexInList,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_OnAddedToList_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List Entry" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_OnAddedToList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "OnAddedToList", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_OnAddedToList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_OnAddedToList_Statics::PropPointers), sizeof(VH_UmgListEntry_eventOnAddedToList_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_OnAddedToList_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_OnAddedToList_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_OnAddedToList_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_UmgListEntry_eventOnAddedToList_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_OnAddedToList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_OnAddedToList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_OnDataSet_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_newData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_OnDataSet_Statics::NewProp_newData = { "newData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgListEntry_eventOnDataSet_Parms, newData), Z_Construct_UClass_UVH_ListEntryData_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_OnDataSet_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_OnDataSet_Statics::NewProp_newData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_OnDataSet_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List Entry" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Called when data has been updated on this List Entry */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when data has been updated on this List Entry" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_OnDataSet_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "OnDataSet", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_OnDataSet_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_OnDataSet_Statics::PropPointers), sizeof(VH_UmgListEntry_eventOnDataSet_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_OnDataSet_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_OnDataSet_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_OnDataSet_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_UmgListEntry_eventOnDataSet_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_OnDataSet()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_OnDataSet_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_OnInteractionStateChanged_Statics
	{
		static const UECodeGen_Private::FBytePropertyParams NewProp_newState_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_newState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVH_UmgListEntry_OnInteractionStateChanged_Statics::NewProp_newState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_OnInteractionStateChanged_Statics::NewProp_newState = { "newState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgListEntry_eventOnInteractionStateChanged_Parms, newState), Z_Construct_UEnum_VH_UI_EListInteractionState, METADATA_PARAMS(0, nullptr) }; // 2342253011
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_OnInteractionStateChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_OnInteractionStateChanged_Statics::NewProp_newState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_OnInteractionStateChanged_Statics::NewProp_newState,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_OnInteractionStateChanged_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List Entry" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_OnInteractionStateChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "OnInteractionStateChanged", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_OnInteractionStateChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_OnInteractionStateChanged_Statics::PropPointers), sizeof(VH_UmgListEntry_eventOnInteractionStateChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_OnInteractionStateChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_OnInteractionStateChanged_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_OnInteractionStateChanged_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_UmgListEntry_eventOnInteractionStateChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_OnInteractionStateChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_OnInteractionStateChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_OnSelectedChanged_Statics
	{
		static void NewProp_isSelected_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isSelected;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_UmgListEntry_OnSelectedChanged_Statics::NewProp_isSelected_SetBit(void* Obj)
	{
		((VH_UmgListEntry_eventOnSelectedChanged_Parms*)Obj)->isSelected = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_OnSelectedChanged_Statics::NewProp_isSelected = { "isSelected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgListEntry_eventOnSelectedChanged_Parms), &Z_Construct_UFunction_UVH_UmgListEntry_OnSelectedChanged_Statics::NewProp_isSelected_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_OnSelectedChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_OnSelectedChanged_Statics::NewProp_isSelected,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_OnSelectedChanged_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List Entry" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_OnSelectedChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "OnSelectedChanged", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_OnSelectedChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_OnSelectedChanged_Statics::PropPointers), sizeof(VH_UmgListEntry_eventOnSelectedChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_OnSelectedChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_OnSelectedChanged_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_OnSelectedChanged_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_UmgListEntry_eventOnSelectedChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_OnSelectedChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_OnSelectedChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged_Statics
	{
		struct VH_UmgListEntry_eventSelectedChanged_Parms
		{
			bool isSelected;
		};
		static void NewProp_isSelected_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isSelected;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged_Statics::NewProp_isSelected_SetBit(void* Obj)
	{
		((VH_UmgListEntry_eventSelectedChanged_Parms*)Obj)->isSelected = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged_Statics::NewProp_isSelected = { "isSelected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgListEntry_eventSelectedChanged_Parms), &Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged_Statics::NewProp_isSelected_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged_Statics::NewProp_isSelected,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "SelectedChanged", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged_Statics::VH_UmgListEntry_eventSelectedChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged_Statics::VH_UmgListEntry_eventSelectedChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics
	{
		struct VH_UmgListEntry_eventSetColumnSize_Parms
		{
			int32 columnIndex;
			FSlateChildSize sizingData;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_columnIndex;
		static const UECodeGen_Private::FStructPropertyParams NewProp_sizingData;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::NewProp_columnIndex = { "columnIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgListEntry_eventSetColumnSize_Parms, columnIndex), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::NewProp_sizingData = { "sizingData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgListEntry_eventSetColumnSize_Parms, sizingData), Z_Construct_UScriptStruct_FSlateChildSize, METADATA_PARAMS(0, nullptr) }; // 1742874166
	void Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_UmgListEntry_eventSetColumnSize_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgListEntry_eventSetColumnSize_Parms), &Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::NewProp_columnIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::NewProp_sizingData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List Entry" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "SetColumnSize", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::VH_UmgListEntry_eventSetColumnSize_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::VH_UmgListEntry_eventSetColumnSize_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_SetData_Statics
	{
		struct VH_UmgListEntry_eventSetData_Parms
		{
			UVH_ListEntryData* newData;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_newData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_SetData_Statics::NewProp_newData = { "newData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgListEntry_eventSetData_Parms, newData), Z_Construct_UClass_UVH_ListEntryData_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_SetData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_SetData_Statics::NewProp_newData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_SetData_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List Entry" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_SetData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "SetData", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_SetData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetData_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgListEntry_SetData_Statics::VH_UmgListEntry_eventSetData_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_SetData_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetData_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgListEntry_SetData_Statics::VH_UmgListEntry_eventSetData_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_SetData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_SetData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_SetHovered_Statics
	{
		struct VH_UmgListEntry_eventSetHovered_Parms
		{
			bool newHovered;
		};
		static void NewProp_newHovered_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_newHovered;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_UmgListEntry_SetHovered_Statics::NewProp_newHovered_SetBit(void* Obj)
	{
		((VH_UmgListEntry_eventSetHovered_Parms*)Obj)->newHovered = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_SetHovered_Statics::NewProp_newHovered = { "newHovered", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgListEntry_eventSetHovered_Parms), &Z_Construct_UFunction_UVH_UmgListEntry_SetHovered_Statics::NewProp_newHovered_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_SetHovered_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_SetHovered_Statics::NewProp_newHovered,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_SetHovered_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_SetHovered_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "SetHovered", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_SetHovered_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetHovered_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgListEntry_SetHovered_Statics::VH_UmgListEntry_eventSetHovered_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetHovered_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_SetHovered_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetHovered_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgListEntry_SetHovered_Statics::VH_UmgListEntry_eventSetHovered_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_SetHovered()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_SetHovered_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState_Statics
	{
		struct VH_UmgListEntry_eventSetInteractionState_Parms
		{
			EListInteractionState newState;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_newState_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_newState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState_Statics::NewProp_newState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState_Statics::NewProp_newState = { "newState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgListEntry_eventSetInteractionState_Parms, newState), Z_Construct_UEnum_VH_UI_EListInteractionState, METADATA_PARAMS(0, nullptr) }; // 2342253011
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState_Statics::NewProp_newState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState_Statics::NewProp_newState,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState_Statics::Function_MetaDataParams[] = {
		{ "Category", "VH List Entry" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "SetInteractionState", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState_Statics::VH_UmgListEntry_eventSetInteractionState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState_Statics::VH_UmgListEntry_eventSetInteractionState_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics
	{
		struct VH_UmgListEntry_eventSetLayoutHandler_Parms
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics::NewProp_newLayoutHandler_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics::NewProp_newLayoutHandler = { "newLayoutHandler", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_UmgListEntry_eventSetLayoutHandler_Parms, newLayoutHandler), Z_Construct_UClass_UPanelWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics::NewProp_newLayoutHandler_MetaData), Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics::NewProp_newLayoutHandler_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics::NewProp_newLayoutHandler,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "SetLayoutHandler", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics::VH_UmgListEntry_eventSetLayoutHandler_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics::VH_UmgListEntry_eventSetLayoutHandler_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_UmgListEntry_SetSelected_Statics
	{
		struct VH_UmgListEntry_eventSetSelected_Parms
		{
			bool isSelected;
		};
		static void NewProp_isSelected_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isSelected;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_UmgListEntry_SetSelected_Statics::NewProp_isSelected_SetBit(void* Obj)
	{
		((VH_UmgListEntry_eventSetSelected_Parms*)Obj)->isSelected = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_UmgListEntry_SetSelected_Statics::NewProp_isSelected = { "isSelected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_UmgListEntry_eventSetSelected_Parms), &Z_Construct_UFunction_UVH_UmgListEntry_SetSelected_Statics::NewProp_isSelected_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_UmgListEntry_SetSelected_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_UmgListEntry_SetSelected_Statics::NewProp_isSelected,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_UmgListEntry_SetSelected_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_UmgListEntry_SetSelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_UmgListEntry, nullptr, "SetSelected", nullptr, nullptr, Z_Construct_UFunction_UVH_UmgListEntry_SetSelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetSelected_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_UmgListEntry_SetSelected_Statics::VH_UmgListEntry_eventSetSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_UmgListEntry_SetSelected_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_UmgListEntry_SetSelected_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_UmgListEntry_SetSelected_Statics::VH_UmgListEntry_eventSetSelected_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_UmgListEntry_SetSelected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_UmgListEntry_SetSelected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_UmgListEntry);
	UClass* Z_Construct_UClass_UVH_UmgListEntry_NoRegister()
	{
		return UVH_UmgListEntry::StaticClass();
	}
	struct Z_Construct_UClass_UVH_UmgListEntry_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CellLayoutHandler_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CellLayoutHandler;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Data_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Data;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bExternalActivation_MetaData[];
#endif
		static void NewProp_bExternalActivation_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bExternalActivation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OwningList_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OwningList;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSupportsDragging_MetaData[];
#endif
		static void NewProp_bSupportsDragging_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSupportsDragging;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_UmgListEntry_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgListEntry_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_UmgListEntry_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVH_UmgListEntry_GetData, "GetData" }, // 3456516169
		{ &Z_Construct_UFunction_UVH_UmgListEntry_GetHoverText, "GetHoverText" }, // 1282261679
		{ &Z_Construct_UFunction_UVH_UmgListEntry_GetIndexInList, "GetIndexInList" }, // 2699835132
		{ &Z_Construct_UFunction_UVH_UmgListEntry_GetInteractionState, "GetInteractionState" }, // 1556154956
		{ &Z_Construct_UFunction_UVH_UmgListEntry_InitializeLayout, "InitializeLayout" }, // 4036561406
		{ &Z_Construct_UFunction_UVH_UmgListEntry_IsDisabled, "IsDisabled" }, // 3810172064
		{ &Z_Construct_UFunction_UVH_UmgListEntry_IsLayoutInitialized, "IsLayoutInitialized" }, // 2315870456
		{ &Z_Construct_UFunction_UVH_UmgListEntry_IsSelected, "IsSelected" }, // 1706888352
		{ &Z_Construct_UFunction_UVH_UmgListEntry_K2_IsHovered, "K2_IsHovered" }, // 2620338040
		{ &Z_Construct_UFunction_UVH_UmgListEntry_OnAddedToList, "OnAddedToList" }, // 181763689
		{ &Z_Construct_UFunction_UVH_UmgListEntry_OnDataSet, "OnDataSet" }, // 1652892182
		{ &Z_Construct_UFunction_UVH_UmgListEntry_OnInteractionStateChanged, "OnInteractionStateChanged" }, // 599825006
		{ &Z_Construct_UFunction_UVH_UmgListEntry_OnSelectedChanged, "OnSelectedChanged" }, // 325791793
		{ &Z_Construct_UFunction_UVH_UmgListEntry_SelectedChanged, "SelectedChanged" }, // 3647946745
		{ &Z_Construct_UFunction_UVH_UmgListEntry_SetColumnSize, "SetColumnSize" }, // 1707935535
		{ &Z_Construct_UFunction_UVH_UmgListEntry_SetData, "SetData" }, // 2551573806
		{ &Z_Construct_UFunction_UVH_UmgListEntry_SetHovered, "SetHovered" }, // 1880531467
		{ &Z_Construct_UFunction_UVH_UmgListEntry_SetInteractionState, "SetInteractionState" }, // 334122293
		{ &Z_Construct_UFunction_UVH_UmgListEntry_SetLayoutHandler, "SetLayoutHandler" }, // 3165059001
		{ &Z_Construct_UFunction_UVH_UmgListEntry_SetSelected, "SetSelected" }, // 1147603566
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgListEntry_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgListEntry_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n*\n*/" },
#endif
		{ "HideCategories", "VH List Entry" },
		{ "IncludePath", "Deprecated/Public/VH_UmgListEntry.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_CellLayoutHandler_MetaData[] = {
		{ "Category", "VH ListHeader" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Use this to layout all the cells/columns visually. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Use this to layout all the cells/columns visually." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_CellLayoutHandler = { "CellLayoutHandler", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_UmgListEntry, CellLayoutHandler), Z_Construct_UClass_UPanelWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_CellLayoutHandler_MetaData), Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_CellLayoutHandler_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_Data_MetaData[] = {
		{ "Category", "Defaults" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** If we have a timeout on the popup, this is the remaining time before it auto-pops*/" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "If we have a timeout on the popup, this is the remaining time before it auto-pops" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_UmgListEntry, Data), Z_Construct_UClass_UVH_ListEntryData_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_Data_MetaData), Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_Data_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_bExternalActivation_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** True if hover/click events need to happen based on external assignment. . .like if hit locations overlap and cannot be properly identified */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "True if hover/click events need to happen based on external assignment. . .like if hit locations overlap and cannot be properly identified" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_bExternalActivation_SetBit(void* Obj)
	{
		((UVH_UmgListEntry*)Obj)->bExternalActivation = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_bExternalActivation = { "bExternalActivation", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_UmgListEntry), &Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_bExternalActivation_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_bExternalActivation_MetaData), Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_bExternalActivation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_OwningList_MetaData[] = {
		{ "Category", "Defaults" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** This should be a subclass of VH_UmgWidget_List but cannot set as such or we would have a circular reference. */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This should be a subclass of VH_UmgWidget_List but cannot set as such or we would have a circular reference." },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_OwningList = { "OwningList", nullptr, (EPropertyFlags)0x002008000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_UmgListEntry, OwningList), Z_Construct_UClass_UVH_UmgWidget_List_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_OwningList_MetaData), Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_OwningList_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_bSupportsDragging_MetaData[] = {
		{ "Category", "VH List Entry" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_UmgListEntry.h" },
	};
#endif
	void Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_bSupportsDragging_SetBit(void* Obj)
	{
		((UVH_UmgListEntry*)Obj)->bSupportsDragging = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_bSupportsDragging = { "bSupportsDragging", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UVH_UmgListEntry), &Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_bSupportsDragging_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_bSupportsDragging_MetaData), Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_bSupportsDragging_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVH_UmgListEntry_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_CellLayoutHandler,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_Data,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_bExternalActivation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_OwningList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_UmgListEntry_Statics::NewProp_bSupportsDragging,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_UmgListEntry_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_UmgListEntry>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_UmgListEntry_Statics::ClassParams = {
		&UVH_UmgListEntry::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVH_UmgListEntry_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgListEntry_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgListEntry_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_UmgListEntry_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_UmgListEntry_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVH_UmgListEntry()
	{
		if (!Z_Registration_Info_UClass_UVH_UmgListEntry.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_UmgListEntry.OuterSingleton, Z_Construct_UClass_UVH_UmgListEntry_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_UmgListEntry.OuterSingleton;
	}
	template<> VH_UI_API UClass* StaticClass<UVH_UmgListEntry>()
	{
		return UVH_UmgListEntry::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_UmgListEntry);
	UVH_UmgListEntry::~UVH_UmgListEntry() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_Statics::EnumInfo[] = {
		{ EListInteractionState_StaticEnum, TEXT("EListInteractionState"), &Z_Registration_Info_UEnum_EListInteractionState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2342253011U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_UmgListEntry, UVH_UmgListEntry::StaticClass, TEXT("UVH_UmgListEntry"), &Z_Registration_Info_UClass_UVH_UmgListEntry, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_UmgListEntry), 4189827433U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_3150229203(TEXT("/Script/VH_UI"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
