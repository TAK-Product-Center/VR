// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Subsystems/Public/Developer_Subsystem_Selection.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_Subsystem_Selection() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_Selection();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_Selection_NoRegister();
	VH_DEVELOPER_API UFunction* Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics
	{
		struct Developer_Subsystem_Selection_eventOnSelectionChanged_Parms
		{
			UObject* object;
			bool bSelected;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_object;
		static void NewProp_bSelected_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSelected;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::NewProp_object = { "object", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Selection_eventOnSelectionChanged_Parms, object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::NewProp_bSelected_SetBit(void* Obj)
	{
		((Developer_Subsystem_Selection_eventOnSelectionChanged_Parms*)Obj)->bSelected = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::NewProp_bSelected = { "bSelected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Subsystem_Selection_eventOnSelectionChanged_Parms), &Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::NewProp_bSelected_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::NewProp_object,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::NewProp_bSelected,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Selection.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Selection, nullptr, "OnSelectionChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::Developer_Subsystem_Selection_eventOnSelectionChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::Developer_Subsystem_Selection_eventOnSelectionChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UDeveloper_Subsystem_Selection::FOnSelectionChanged_DelegateWrapper(const FMulticastScriptDelegate& OnSelectionChanged, UObject* object, bool bSelected)
{
	struct Developer_Subsystem_Selection_eventOnSelectionChanged_Parms
	{
		UObject* object;
		bool bSelected;
	};
	Developer_Subsystem_Selection_eventOnSelectionChanged_Parms Parms;
	Parms.object=object;
	Parms.bSelected=bSelected ? true : false;
	OnSelectionChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Selection::execGetLastSelected)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UObject**)Z_Param__Result=P_THIS->GetLastSelected();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Selection::execGetSelected)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TSet<UObject*>*)Z_Param__Result=P_THIS->GetSelected();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Selection::execGetSelectedByClass)
	{
		P_GET_OBJECT(UClass,Z_Param_selectedClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TSet<UObject*>*)Z_Param__Result=P_THIS->GetSelectedByClass(Z_Param_selectedClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Selection::execIsSelected)
	{
		P_GET_OBJECT(UObject,Z_Param_object);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsSelected(Z_Param_object);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Selection::execDeselect)
	{
		P_GET_OBJECT(UObject,Z_Param_object);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Deselect(Z_Param_object);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Selection::execSelect)
	{
		P_GET_OBJECT(UObject,Z_Param_object);
		P_GET_UBOOL(Z_Param_bClearExisting);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Select(Z_Param_object,Z_Param_bClearExisting);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Selection::execClearSelections)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearSelections();
		P_NATIVE_END;
	}
	void UDeveloper_Subsystem_Selection::StaticRegisterNativesUDeveloper_Subsystem_Selection()
	{
		UClass* Class = UDeveloper_Subsystem_Selection::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ClearSelections", &UDeveloper_Subsystem_Selection::execClearSelections },
			{ "Deselect", &UDeveloper_Subsystem_Selection::execDeselect },
			{ "GetLastSelected", &UDeveloper_Subsystem_Selection::execGetLastSelected },
			{ "GetSelected", &UDeveloper_Subsystem_Selection::execGetSelected },
			{ "GetSelectedByClass", &UDeveloper_Subsystem_Selection::execGetSelectedByClass },
			{ "IsSelected", &UDeveloper_Subsystem_Selection::execIsSelected },
			{ "Select", &UDeveloper_Subsystem_Selection::execSelect },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Selection_ClearSelections_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Selection_ClearSelections_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* /brief Removes all objects from the selection list\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Selection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* /brief Removes all objects from the selection list" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_ClearSelections_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Selection, nullptr, "ClearSelections", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_ClearSelections_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Selection_ClearSelections_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Selection_ClearSelections()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Selection_ClearSelections_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Deselect_Statics
	{
		struct Developer_Subsystem_Selection_eventDeselect_Parms
		{
			UObject* object;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_object;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Deselect_Statics::NewProp_object = { "object", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Selection_eventDeselect_Parms, object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Deselect_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Deselect_Statics::NewProp_object,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Deselect_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* /brief Removes the given object from the selection if it is currently selected\n\x09* /param object Object to remove\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Selection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* /brief Removes the given object from the selection if it is currently selected\n* /param object Object to remove" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Deselect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Selection, nullptr, "Deselect", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Deselect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Deselect_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Deselect_Statics::Developer_Subsystem_Selection_eventDeselect_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Deselect_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Deselect_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Deselect_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Deselect_Statics::Developer_Subsystem_Selection_eventDeselect_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Deselect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Deselect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetLastSelected_Statics
	{
		struct Developer_Subsystem_Selection_eventGetLastSelected_Parms
		{
			UObject* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetLastSelected_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Selection_eventGetLastSelected_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetLastSelected_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetLastSelected_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetLastSelected_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* /brief Returns the last selected object, sorted by time of selection.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Selection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* /brief Returns the last selected object, sorted by time of selection." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetLastSelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Selection, nullptr, "GetLastSelected", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetLastSelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetLastSelected_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetLastSelected_Statics::Developer_Subsystem_Selection_eventGetLastSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetLastSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetLastSelected_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetLastSelected_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetLastSelected_Statics::Developer_Subsystem_Selection_eventGetLastSelected_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetLastSelected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetLastSelected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected_Statics
	{
		struct Developer_Subsystem_Selection_eventGetSelected_Parms
		{
			TSet<UObject*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_ElementProp;
		static const UECodeGen_Private::FSetPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected_Statics::NewProp_ReturnValue_ElementProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Selection_eventGetSelected_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected_Statics::NewProp_ReturnValue_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* /brief Returns a set of all selected objects as UObject*\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Selection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* /brief Returns a set of all selected objects as UObject*" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Selection, nullptr, "GetSelected", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected_Statics::Developer_Subsystem_Selection_eventGetSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected_Statics::Developer_Subsystem_Selection_eventGetSelected_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics
	{
		struct Developer_Subsystem_Selection_eventGetSelectedByClass_Parms
		{
			TSubclassOf<UObject>  selectedClass;
			TSet<UObject*> ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_selectedClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_ElementProp;
		static const UECodeGen_Private::FSetPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::NewProp_selectedClass = { "selectedClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Selection_eventGetSelectedByClass_Parms, selectedClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::NewProp_ReturnValue_ElementProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Selection_eventGetSelectedByClass_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::NewProp_selectedClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::NewProp_ReturnValue_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* /brief Returns a list of selected objects matching the given subclass as UObject*\n\x09* /param selectedClass Subclass to match the selected objects with\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Selection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* /brief Returns a list of selected objects matching the given subclass as UObject*\n* /param selectedClass Subclass to match the selected objects with" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Selection, nullptr, "GetSelectedByClass", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::Developer_Subsystem_Selection_eventGetSelectedByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::Developer_Subsystem_Selection_eventGetSelectedByClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics
	{
		struct Developer_Subsystem_Selection_eventIsSelected_Parms
		{
			UObject* object;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_object;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::NewProp_object = { "object", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Selection_eventIsSelected_Parms, object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Subsystem_Selection_eventIsSelected_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Subsystem_Selection_eventIsSelected_Parms), &Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::NewProp_object,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* /brief Returns whether the given object is currently selected\n\x09* /param object Object to check for selection\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Selection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* /brief Returns whether the given object is currently selected\n* /param object Object to check for selection" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Selection, nullptr, "IsSelected", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::Developer_Subsystem_Selection_eventIsSelected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::Developer_Subsystem_Selection_eventIsSelected_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics
	{
		struct Developer_Subsystem_Selection_eventSelect_Parms
		{
			UObject* object;
			bool bClearExisting;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_object;
		static void NewProp_bClearExisting_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bClearExisting;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::NewProp_object = { "object", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Selection_eventSelect_Parms, object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::NewProp_bClearExisting_SetBit(void* Obj)
	{
		((Developer_Subsystem_Selection_eventSelect_Parms*)Obj)->bClearExisting = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::NewProp_bClearExisting = { "bClearExisting", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Subsystem_Selection_eventSelect_Parms), &Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::NewProp_bClearExisting_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::NewProp_object,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::NewProp_bClearExisting,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* /brief Selects object, optionally clearing list\n\x09* /param object Object to select\n\x09* /param bClearExisting If true, clears existing selection before selecting object\n\x09* /note Selected objects will not be garbage collected while selected \n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Selection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* /brief Selects object, optionally clearing list\n* /param object Object to select\n* /param bClearExisting If true, clears existing selection before selecting object\n* /note Selected objects will not be garbage collected while selected" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Selection, nullptr, "Select", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::Developer_Subsystem_Selection_eventSelect_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::Developer_Subsystem_Selection_eventSelect_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_Subsystem_Selection);
	UClass* Z_Construct_UClass_UDeveloper_Subsystem_Selection_NoRegister()
	{
		return UDeveloper_Subsystem_Selection::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnSelectionChanged_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSelectionChanged;
		static const UECodeGen_Private::FInt64PropertyParams NewProp_SelectedObjects_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SelectedObjects_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SelectedObjects_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_SelectedObjects;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Selection_ClearSelections, "ClearSelections" }, // 1673691522
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Deselect, "Deselect" }, // 2448728424
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetLastSelected, "GetLastSelected" }, // 2136624132
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelected, "GetSelected" }, // 3793505821
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Selection_GetSelectedByClass, "GetSelectedByClass" }, // 197642884
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Selection_IsSelected, "IsSelected" }, // 1647115840
		{ &Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature, "OnSelectionChanged__DelegateSignature" }, // 4145522240
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Selection_Select, "Select" }, // 1433000680
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Subsystems/Public/Developer_Subsystem_Selection.h" },
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Selection.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::NewProp_OnSelectionChanged_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* broadcast when an object is selected or deselected */" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Selection.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "broadcast when an object is selected or deselected" },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::NewProp_OnSelectionChanged = { "OnSelectionChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_Subsystem_Selection, OnSelectionChanged), Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Selection_OnSelectionChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::NewProp_OnSelectionChanged_MetaData), Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::NewProp_OnSelectionChanged_MetaData) }; // 4145522240
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::NewProp_SelectedObjects_ValueProp = { "SelectedObjects", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::NewProp_SelectedObjects_Key_KeyProp = { "SelectedObjects_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::NewProp_SelectedObjects_MetaData[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Selection.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::NewProp_SelectedObjects = { "SelectedObjects", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_Subsystem_Selection, SelectedObjects), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::NewProp_SelectedObjects_MetaData), Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::NewProp_SelectedObjects_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::NewProp_OnSelectionChanged,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::NewProp_SelectedObjects_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::NewProp_SelectedObjects_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::NewProp_SelectedObjects,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_Subsystem_Selection>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::ClassParams = {
		&UDeveloper_Subsystem_Selection::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDeveloper_Subsystem_Selection()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_Subsystem_Selection.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_Subsystem_Selection.OuterSingleton, Z_Construct_UClass_UDeveloper_Subsystem_Selection_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_Subsystem_Selection.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_Subsystem_Selection>()
	{
		return UDeveloper_Subsystem_Selection::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_Subsystem_Selection);
	UDeveloper_Subsystem_Selection::~UDeveloper_Subsystem_Selection() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Selection_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Selection_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_Subsystem_Selection, UDeveloper_Subsystem_Selection::StaticClass, TEXT("UDeveloper_Subsystem_Selection"), &Z_Registration_Info_UClass_UDeveloper_Subsystem_Selection, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_Subsystem_Selection), 2865668178U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Selection_h_2225342199(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Selection_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Selection_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
