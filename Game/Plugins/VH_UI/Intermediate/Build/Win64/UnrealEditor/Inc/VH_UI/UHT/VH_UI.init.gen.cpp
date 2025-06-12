// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_UI_init() {}
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_VH_UI_OnEntryCancelled__DelegateSignature();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_VH_UI;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_VH_UI()
	{
		if (!Z_Registration_Info_UPackage__Script_VH_UI.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_UUI_Statics_OnDialogComplete__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UUI_Subsystem_Core_OnUserWidgetClosed__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnEntryEvent__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnListSelectionChanged__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UVH_UmgWidget_List_OnSortRequest__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_VH_UI_OnEntryCancelled__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_VH_UI_OnSelected__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/VH_UI",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x5AAF30C8,
				0xC6BED181,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_VH_UI.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_VH_UI.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_VH_UI(Z_Construct_UPackage__Script_VH_UI, TEXT("/Script/VH_UI"), Z_Registration_Info_UPackage__Script_VH_UI, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x5AAF30C8, 0xC6BED181));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
