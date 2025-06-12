// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Keyboard_ContainerComponent.h"
#include "../../Examples/Public/KeyData.h"
#include "InputCoreTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKeyboard_ContainerComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
	UMG_API UClass* Z_Construct_UClass_UWidget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_Keyboard();
	VH_KEYBOARD_API UClass* Z_Construct_UClass_UKeyboard_ContainerComponent();
	VH_KEYBOARD_API UClass* Z_Construct_UClass_UKeyboard_ContainerComponent_NoRegister();
	VH_KEYBOARD_API UFunction* Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature();
	VH_KEYBOARD_API UFunction* Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature();
	VH_KEYBOARD_API UFunction* Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature();
	VH_KEYBOARD_API UFunction* Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature();
	VH_KEYBOARD_API UScriptStruct* Z_Construct_UScriptStruct_FKeyData();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics
	{
		struct Keyboard_ContainerComponent_eventOnCommit_Parms
		{
			FString entry;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_entry_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_entry;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics::NewProp_entry_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics::NewProp_entry = { "entry", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_ContainerComponent_eventOnCommit_Parms, entry), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics::NewProp_entry_MetaData), Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics::NewProp_entry_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics::NewProp_entry,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/Keyboard_ContainerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKeyboard_ContainerComponent, nullptr, "OnCommit__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics::Keyboard_ContainerComponent_eventOnCommit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics::Keyboard_ContainerComponent_eventOnCommit_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UKeyboard_ContainerComponent::FOnCommit_DelegateWrapper(const FMulticastScriptDelegate& OnCommit, const FString& entry)
{
	struct Keyboard_ContainerComponent_eventOnCommit_Parms
	{
		FString entry;
	};
	Keyboard_ContainerComponent_eventOnCommit_Parms Parms;
	Parms.entry=entry;
	OnCommit.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics
	{
		struct Keyboard_ContainerComponent_eventOnKeyPressed_Parms
		{
			FKeyData keyData;
			FString keyString;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_keyData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_keyData;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_keyString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_keyString;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::NewProp_keyData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::NewProp_keyData = { "keyData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_ContainerComponent_eventOnKeyPressed_Parms, keyData), Z_Construct_UScriptStruct_FKeyData, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::NewProp_keyData_MetaData), Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::NewProp_keyData_MetaData) }; // 941138177
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::NewProp_keyString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::NewProp_keyString = { "keyString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_ContainerComponent_eventOnKeyPressed_Parms, keyString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::NewProp_keyString_MetaData), Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::NewProp_keyString_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::NewProp_keyData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::NewProp_keyString,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/Keyboard_ContainerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKeyboard_ContainerComponent, nullptr, "OnKeyPressed__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::Keyboard_ContainerComponent_eventOnKeyPressed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::Keyboard_ContainerComponent_eventOnKeyPressed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UKeyboard_ContainerComponent::FOnKeyPressed_DelegateWrapper(const FMulticastScriptDelegate& OnKeyPressed, FKeyData const& keyData, const FString& keyString)
{
	struct Keyboard_ContainerComponent_eventOnKeyPressed_Parms
	{
		FKeyData keyData;
		FString keyString;
	};
	Keyboard_ContainerComponent_eventOnKeyPressed_Parms Parms;
	Parms.keyData=keyData;
	Parms.keyString=keyString;
	OnKeyPressed.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature_Statics
	{
		struct Keyboard_ContainerComponent_eventOnShiftModified_Parms
		{
			bool bShiftActive;
		};
		static void NewProp_bShiftActive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShiftActive;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature_Statics::NewProp_bShiftActive_SetBit(void* Obj)
	{
		((Keyboard_ContainerComponent_eventOnShiftModified_Parms*)Obj)->bShiftActive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature_Statics::NewProp_bShiftActive = { "bShiftActive", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Keyboard_ContainerComponent_eventOnShiftModified_Parms), &Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature_Statics::NewProp_bShiftActive_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature_Statics::NewProp_bShiftActive,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/Keyboard_ContainerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKeyboard_ContainerComponent, nullptr, "OnShiftModified__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature_Statics::Keyboard_ContainerComponent_eventOnShiftModified_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature_Statics::Keyboard_ContainerComponent_eventOnShiftModified_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UKeyboard_ContainerComponent::FOnShiftModified_DelegateWrapper(const FMulticastScriptDelegate& OnShiftModified, bool bShiftActive)
{
	struct Keyboard_ContainerComponent_eventOnShiftModified_Parms
	{
		bool bShiftActive;
	};
	Keyboard_ContainerComponent_eventOnShiftModified_Parms Parms;
	Parms.bShiftActive=bShiftActive ? true : false;
	OnShiftModified.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature_Statics
	{
		struct Keyboard_ContainerComponent_eventRequestCommitString_Parms
		{
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_ContainerComponent_eventRequestCommitString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/Keyboard_ContainerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKeyboard_ContainerComponent, nullptr, "RequestCommitString__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature_Statics::Keyboard_ContainerComponent_eventRequestCommitString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature_Statics::Keyboard_ContainerComponent_eventRequestCommitString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
FString UKeyboard_ContainerComponent::FRequestCommitString_DelegateWrapper(const FScriptDelegate& RequestCommitString)
{
	struct Keyboard_ContainerComponent_eventRequestCommitString_Parms
	{
		FString ReturnValue;
	};
	Keyboard_ContainerComponent_eventRequestCommitString_Parms Parms;
	RequestCommitString.ProcessDelegate<UObject>(&Parms);
	return Parms.ReturnValue;
}
	void UKeyboard_ContainerComponent::StaticRegisterNativesUKeyboard_ContainerComponent()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UKeyboard_ContainerComponent);
	UClass* Z_Construct_UClass_UKeyboard_ContainerComponent_NoRegister()
	{
		return UKeyboard_ContainerComponent::StaticClass();
	}
	struct Z_Construct_UClass_UKeyboard_ContainerComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_EDITOR
		static const FClassFunctionLinkInfo FuncInfo[];
#endif //WITH_EDITOR
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnCommit_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCommit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnKeyPressed_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnKeyPressed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnShiftModified_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnShiftModified;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WidgetToSendPress_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WidgetToSendPress;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ShiftToggleKey_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ShiftToggleKey;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CloseKeyString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_CloseKeyString;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CommitKeyString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_CommitKeyString;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RequestCommitString_MetaData[];
#endif
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_RequestCommitString;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CooldownSeconds_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_CooldownSeconds;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Keyboard,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::DependentSingletons) < 16);
#if WITH_EDITOR
	const FClassFunctionLinkInfo Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature, "OnCommit__DelegateSignature" }, // 448343077
		{ &Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature, "OnKeyPressed__DelegateSignature" }, // 1963770937
		{ &Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature, "OnShiftModified__DelegateSignature" }, // 2904696639
		{ &Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature, "RequestCommitString__DelegateSignature" }, // 963006827
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::FuncInfo) < 2048);
#endif //WITH_EDITOR
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "IncludePath", "Components/Public/Keyboard_ContainerComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Components/Public/Keyboard_ContainerComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_OnCommit_MetaData[] = {
		{ "ModuleRelativePath", "Components/Public/Keyboard_ContainerComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_OnCommit = { "OnCommit", nullptr, (EPropertyFlags)0x0010100010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_ContainerComponent, OnCommit), Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnCommit__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_OnCommit_MetaData), Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_OnCommit_MetaData) }; // 448343077
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_OnKeyPressed_MetaData[] = {
		{ "ModuleRelativePath", "Components/Public/Keyboard_ContainerComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_OnKeyPressed = { "OnKeyPressed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_ContainerComponent, OnKeyPressed), Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnKeyPressed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_OnKeyPressed_MetaData), Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_OnKeyPressed_MetaData) }; // 1963770937
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_OnShiftModified_MetaData[] = {
		{ "ModuleRelativePath", "Components/Public/Keyboard_ContainerComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_OnShiftModified = { "OnShiftModified", nullptr, (EPropertyFlags)0x0010100010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_ContainerComponent, OnShiftModified), Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_OnShiftModified__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_OnShiftModified_MetaData), Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_OnShiftModified_MetaData) }; // 2904696639
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_WidgetToSendPress_MetaData[] = {
		{ "Category", "Keyboard_ContainerComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* send keyboard presses to this widget; nullptr is ignored */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Components/Public/Keyboard_ContainerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "send keyboard presses to this widget; nullptr is ignored" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_WidgetToSendPress = { "WidgetToSendPress", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_ContainerComponent, WidgetToSendPress), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_WidgetToSendPress_MetaData), Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_WidgetToSendPress_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_ShiftToggleKey_MetaData[] = {
		{ "Category", "Keyboard_ContainerComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* key that toggles shift; defaults to Caps Lock */" },
#endif
		{ "ModuleRelativePath", "Components/Public/Keyboard_ContainerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "key that toggles shift; defaults to Caps Lock" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_ShiftToggleKey = { "ShiftToggleKey", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_ContainerComponent, ShiftToggleKey), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_ShiftToggleKey_MetaData), Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_ShiftToggleKey_MetaData) }; // 46000949
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_CloseKeyString_MetaData[] = {
		{ "Category", "Keyboard_ContainerComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* key string that closes keyboard; empty string is ignored */" },
#endif
		{ "ModuleRelativePath", "Components/Public/Keyboard_ContainerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "key string that closes keyboard; empty string is ignored" },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_CloseKeyString = { "CloseKeyString", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_ContainerComponent, CloseKeyString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_CloseKeyString_MetaData), Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_CloseKeyString_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_CommitKeyString_MetaData[] = {
		{ "Category", "Keyboard_ContainerComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* key string that commits; empty string is ignored */" },
#endif
		{ "ModuleRelativePath", "Components/Public/Keyboard_ContainerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "key string that commits; empty string is ignored" },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_CommitKeyString = { "CommitKeyString", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_ContainerComponent, CommitKeyString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_CommitKeyString_MetaData), Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_CommitKeyString_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_RequestCommitString_MetaData[] = {
		{ "Category", "Keyboard_ContainerComponent" },
		{ "ModuleRelativePath", "Components/Public/Keyboard_ContainerComponent.h" },
	};
#endif
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_RequestCommitString = { "RequestCommitString", nullptr, (EPropertyFlags)0x0010000000080005, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_ContainerComponent, RequestCommitString), Z_Construct_UDelegateFunction_UKeyboard_ContainerComponent_RequestCommitString__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_RequestCommitString_MetaData), Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_RequestCommitString_MetaData) }; // 963006827
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_CooldownSeconds_MetaData[] = {
		{ "Category", "Keyboard_ContainerComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* seconds that must pass between presses */" },
#endif
		{ "ModuleRelativePath", "Components/Public/Keyboard_ContainerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "seconds that must pass between presses" },
#endif
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_CooldownSeconds = { "CooldownSeconds", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_ContainerComponent, CooldownSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_CooldownSeconds_MetaData), Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_CooldownSeconds_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_OnCommit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_OnKeyPressed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_OnShiftModified,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_WidgetToSendPress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_ShiftToggleKey,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_CloseKeyString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_CommitKeyString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_RequestCommitString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::NewProp_CooldownSeconds,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UKeyboard_ContainerComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::ClassParams = {
		&UKeyboard_ContainerComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		IF_WITH_EDITOR(FuncInfo, nullptr),
		Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		IF_WITH_EDITOR(UE_ARRAY_COUNT(FuncInfo), 0),
		UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UKeyboard_ContainerComponent()
	{
		if (!Z_Registration_Info_UClass_UKeyboard_ContainerComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UKeyboard_ContainerComponent.OuterSingleton, Z_Construct_UClass_UKeyboard_ContainerComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UKeyboard_ContainerComponent.OuterSingleton;
	}
	template<> VH_KEYBOARD_API UClass* StaticClass<UKeyboard_ContainerComponent>()
	{
		return UKeyboard_ContainerComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UKeyboard_ContainerComponent);
	UKeyboard_ContainerComponent::~UKeyboard_ContainerComponent() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UKeyboard_ContainerComponent, UKeyboard_ContainerComponent::StaticClass, TEXT("UKeyboard_ContainerComponent"), &Z_Registration_Info_UClass_UKeyboard_ContainerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UKeyboard_ContainerComponent), 4100920310U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_956020330(TEXT("/Script/VH_Keyboard"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Components_Public_Keyboard_ContainerComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
