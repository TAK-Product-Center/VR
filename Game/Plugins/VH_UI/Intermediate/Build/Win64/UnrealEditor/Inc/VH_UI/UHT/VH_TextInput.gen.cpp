// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Deprecated/Public/VH_TextInput.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_TextInput() {}
// Cross Module References
	SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextCommit();
	UMG_API UClass* Z_Construct_UClass_UEditableTextBox_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_VH_UI();
	VH_UI_API UClass* Z_Construct_UClass_UVH_TextInput();
	VH_UI_API UClass* Z_Construct_UClass_UVH_TextInput_NoRegister();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_VH_UI_OnEntryCancelled__DelegateSignature();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature();
	VH_UI_API UFunction* Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature_Statics
	{
		struct _Script_VH_UI_eventOnEntrySubmitted_Parms
		{
			FString inString;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_inString;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature_Statics::NewProp_inString = { "inString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VH_UI_eventOnEntrySubmitted_Parms, inString), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature_Statics::NewProp_inString,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* To be called when text is submitted */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_TextInput.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "To be called when text is submitted" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_VH_UI, nullptr, "OnEntrySubmitted__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature_Statics::_Script_VH_UI_eventOnEntrySubmitted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature_Statics::_Script_VH_UI_eventOnEntrySubmitted_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnEntrySubmitted_DelegateWrapper(const FMulticastScriptDelegate& OnEntrySubmitted, const FString& inString)
{
	struct _Script_VH_UI_eventOnEntrySubmitted_Parms
	{
		FString inString;
	};
	_Script_VH_UI_eventOnEntrySubmitted_Parms Parms;
	Parms.inString=inString;
	OnEntrySubmitted.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_VH_UI_OnEntryCancelled__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_VH_UI_OnEntryCancelled__DelegateSignature_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* To be called when entry into textbox is cancelled */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_TextInput.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "To be called when entry into textbox is cancelled" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_VH_UI_OnEntryCancelled__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_VH_UI, nullptr, "OnEntryCancelled__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_UI_OnEntryCancelled__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_VH_UI_OnEntryCancelled__DelegateSignature_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UDelegateFunction_VH_UI_OnEntryCancelled__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_VH_UI_OnEntryCancelled__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnEntryCancelled_DelegateWrapper(const FMulticastScriptDelegate& OnEntryCancelled)
{
	OnEntryCancelled.ProcessMulticastDelegate<UObject>(NULL);
}
	struct Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature_Statics
	{
		struct _Script_VH_UI_eventOnTextEdited_Parms
		{
			FString inString;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_inString;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature_Statics::NewProp_inString = { "inString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VH_UI_eventOnTextEdited_Parms, inString), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature_Statics::NewProp_inString,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Called any time the text within the box is edited */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_TextInput.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called any time the text within the box is edited" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_VH_UI, nullptr, "OnTextEdited__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature_Statics::_Script_VH_UI_eventOnTextEdited_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature_Statics::_Script_VH_UI_eventOnTextEdited_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnTextEdited_DelegateWrapper(const FMulticastScriptDelegate& OnTextEdited, const FString& inString)
{
	struct _Script_VH_UI_eventOnTextEdited_Parms
	{
		FString inString;
	};
	_Script_VH_UI_eventOnTextEdited_Parms Parms;
	Parms.inString=inString;
	OnTextEdited.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UVH_TextInput::execHandleTextEdited)
	{
		P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_inCommittedText);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleTextEdited_Implementation(Z_Param_Out_inCommittedText);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_TextInput::execHandleTextBoxCommitted)
	{
		P_GET_PROPERTY(FByteProperty,Z_Param_inCommitMethod);
		P_GET_PROPERTY(FTextProperty,Z_Param_inCommittedText);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleTextBoxCommitted(ETextCommit::Type(Z_Param_inCommitMethod),Z_Param_inCommittedText);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_TextInput::execSetTextBox)
	{
		P_GET_OBJECT(UEditableTextBox,Z_Param_inTextBox);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetTextBox_Implementation(Z_Param_inTextBox);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_TextInput::execSetText)
	{
		P_GET_PROPERTY(FTextProperty,Z_Param_inText);
		P_GET_UBOOL(Z_Param_inSkipEvent);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetText(Z_Param_inText,Z_Param_inSkipEvent);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_TextInput::execGetText)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FText*)Z_Param__Result=P_THIS->GetText();
		P_NATIVE_END;
	}
	struct VH_TextInput_eventHandleTextEdited_Parms
	{
		FText inCommittedText;
	};
	struct VH_TextInput_eventSetTextBox_Parms
	{
		UEditableTextBox* inTextBox;
	};
	static FName NAME_UVH_TextInput_HandleTextEdited = FName(TEXT("HandleTextEdited"));
	void UVH_TextInput::HandleTextEdited(FText const& inCommittedText)
	{
		VH_TextInput_eventHandleTextEdited_Parms Parms;
		Parms.inCommittedText=inCommittedText;
		ProcessEvent(FindFunctionChecked(NAME_UVH_TextInput_HandleTextEdited),&Parms);
	}
	static FName NAME_UVH_TextInput_SetTextBox = FName(TEXT("SetTextBox"));
	void UVH_TextInput::SetTextBox(UEditableTextBox* inTextBox)
	{
		VH_TextInput_eventSetTextBox_Parms Parms;
		Parms.inTextBox=inTextBox;
		ProcessEvent(FindFunctionChecked(NAME_UVH_TextInput_SetTextBox),&Parms);
	}
	void UVH_TextInput::StaticRegisterNativesUVH_TextInput()
	{
		UClass* Class = UVH_TextInput::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetText", &UVH_TextInput::execGetText },
			{ "HandleTextBoxCommitted", &UVH_TextInput::execHandleTextBoxCommitted },
			{ "HandleTextEdited", &UVH_TextInput::execHandleTextEdited },
			{ "SetText", &UVH_TextInput::execSetText },
			{ "SetTextBox", &UVH_TextInput::execSetTextBox },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_TextInput_GetText_Statics
	{
		struct VH_TextInput_eventGetText_Parms
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
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UVH_TextInput_GetText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_TextInput_eventGetText_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_TextInput_GetText_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_TextInput_GetText_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_TextInput_GetText_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Get the text currently in this TextInput */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_TextInput.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the text currently in this TextInput" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_TextInput_GetText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_TextInput, nullptr, "GetText", nullptr, nullptr, Z_Construct_UFunction_UVH_TextInput_GetText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_GetText_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_TextInput_GetText_Statics::VH_TextInput_eventGetText_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_GetText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_TextInput_GetText_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_GetText_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_TextInput_GetText_Statics::VH_TextInput_eventGetText_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_TextInput_GetText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_TextInput_GetText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted_Statics
	{
		struct VH_TextInput_eventHandleTextBoxCommitted_Parms
		{
			TEnumAsByte<ETextCommit::Type> inCommitMethod;
			FText inCommittedText;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_inCommitMethod;
		static const UECodeGen_Private::FTextPropertyParams NewProp_inCommittedText;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted_Statics::NewProp_inCommitMethod = { "inCommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_TextInput_eventHandleTextBoxCommitted_Parms, inCommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 3724737095
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted_Statics::NewProp_inCommittedText = { "inCommittedText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_TextInput_eventHandleTextBoxCommitted_Parms, inCommittedText), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted_Statics::NewProp_inCommitMethod,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted_Statics::NewProp_inCommittedText,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Called when text is finished being entered into box */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_TextInput.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when text is finished being entered into box" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_TextInput, nullptr, "HandleTextBoxCommitted", nullptr, nullptr, Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted_Statics::VH_TextInput_eventHandleTextBoxCommitted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted_Statics::VH_TextInput_eventHandleTextBoxCommitted_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_TextInput_HandleTextEdited_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_inCommittedText_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_inCommittedText;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_TextInput_HandleTextEdited_Statics::NewProp_inCommittedText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UVH_TextInput_HandleTextEdited_Statics::NewProp_inCommittedText = { "inCommittedText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_TextInput_eventHandleTextEdited_Parms, inCommittedText), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_HandleTextEdited_Statics::NewProp_inCommittedText_MetaData), Z_Construct_UFunction_UVH_TextInput_HandleTextEdited_Statics::NewProp_inCommittedText_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_TextInput_HandleTextEdited_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_TextInput_HandleTextEdited_Statics::NewProp_inCommittedText,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_TextInput_HandleTextEdited_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Called when text within the text box is changed */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_TextInput.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when text within the text box is changed" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_TextInput_HandleTextEdited_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_TextInput, nullptr, "HandleTextEdited", nullptr, nullptr, Z_Construct_UFunction_UVH_TextInput_HandleTextEdited_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_HandleTextEdited_Statics::PropPointers), sizeof(VH_TextInput_eventHandleTextEdited_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C480C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_HandleTextEdited_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_TextInput_HandleTextEdited_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_HandleTextEdited_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_TextInput_eventHandleTextEdited_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_TextInput_HandleTextEdited()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_TextInput_HandleTextEdited_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_TextInput_SetText_Statics
	{
		struct VH_TextInput_eventSetText_Parms
		{
			FText inText;
			bool inSkipEvent;
		};
		static const UECodeGen_Private::FTextPropertyParams NewProp_inText;
		static void NewProp_inSkipEvent_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_inSkipEvent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UVH_TextInput_SetText_Statics::NewProp_inText = { "inText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_TextInput_eventSetText_Parms, inText), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVH_TextInput_SetText_Statics::NewProp_inSkipEvent_SetBit(void* Obj)
	{
		((VH_TextInput_eventSetText_Parms*)Obj)->inSkipEvent = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_TextInput_SetText_Statics::NewProp_inSkipEvent = { "inSkipEvent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_TextInput_eventSetText_Parms), &Z_Construct_UFunction_UVH_TextInput_SetText_Statics::NewProp_inSkipEvent_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_TextInput_SetText_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_TextInput_SetText_Statics::NewProp_inText,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_TextInput_SetText_Statics::NewProp_inSkipEvent,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_TextInput_SetText_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_TextInput.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_TextInput_SetText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_TextInput, nullptr, "SetText", nullptr, nullptr, Z_Construct_UFunction_UVH_TextInput_SetText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_SetText_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_TextInput_SetText_Statics::VH_TextInput_eventSetText_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_SetText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_TextInput_SetText_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_SetText_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_TextInput_SetText_Statics::VH_TextInput_eventSetText_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_TextInput_SetText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_TextInput_SetText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_TextInput_SetTextBox_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_inTextBox_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_inTextBox;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_TextInput_SetTextBox_Statics::NewProp_inTextBox_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_TextInput_SetTextBox_Statics::NewProp_inTextBox = { "inTextBox", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_TextInput_eventSetTextBox_Parms, inTextBox), Z_Construct_UClass_UEditableTextBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_SetTextBox_Statics::NewProp_inTextBox_MetaData), Z_Construct_UFunction_UVH_TextInput_SetTextBox_Statics::NewProp_inTextBox_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_TextInput_SetTextBox_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_TextInput_SetTextBox_Statics::NewProp_inTextBox,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_TextInput_SetTextBox_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Sets a widget in the hirearchy as the textbox for this Text Input */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_TextInput.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets a widget in the hirearchy as the textbox for this Text Input" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_TextInput_SetTextBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_TextInput, nullptr, "SetTextBox", nullptr, nullptr, Z_Construct_UFunction_UVH_TextInput_SetTextBox_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_SetTextBox_Statics::PropPointers), sizeof(VH_TextInput_eventSetTextBox_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C080C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_SetTextBox_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_TextInput_SetTextBox_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_TextInput_SetTextBox_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_TextInput_eventSetTextBox_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_TextInput_SetTextBox()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_TextInput_SetTextBox_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_TextInput);
	UClass* Z_Construct_UClass_UVH_TextInput_NoRegister()
	{
		return UVH_TextInput::StaticClass();
	}
	struct Z_Construct_UClass_UVH_TextInput_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnEntrySubmittedCallback_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEntrySubmittedCallback;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnEntryCancelledCallback_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEntryCancelledCallback;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnTextEditedCallback_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTextEditedCallback;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TextBox_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TextBox;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LastEntry_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_LastEntry;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_TextInput_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_TextInput_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_TextInput_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVH_TextInput_GetText, "GetText" }, // 922690844
		{ &Z_Construct_UFunction_UVH_TextInput_HandleTextBoxCommitted, "HandleTextBoxCommitted" }, // 2672974863
		{ &Z_Construct_UFunction_UVH_TextInput_HandleTextEdited, "HandleTextEdited" }, // 1630828078
		{ &Z_Construct_UFunction_UVH_TextInput_SetText, "SetText" }, // 3024734617
		{ &Z_Construct_UFunction_UVH_TextInput_SetTextBox, "SetTextBox" }, // 2334365272
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_TextInput_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_TextInput_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Deprecated/Public/VH_TextInput.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_TextInput.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_TextInput_Statics::NewProp_OnEntrySubmittedCallback_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_TextInput.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_TextInput_Statics::NewProp_OnEntrySubmittedCallback = { "OnEntrySubmittedCallback", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_TextInput, OnEntrySubmittedCallback), Z_Construct_UDelegateFunction_VH_UI_OnEntrySubmitted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_TextInput_Statics::NewProp_OnEntrySubmittedCallback_MetaData), Z_Construct_UClass_UVH_TextInput_Statics::NewProp_OnEntrySubmittedCallback_MetaData) }; // 1936368741
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_TextInput_Statics::NewProp_OnEntryCancelledCallback_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_TextInput.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_TextInput_Statics::NewProp_OnEntryCancelledCallback = { "OnEntryCancelledCallback", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_TextInput, OnEntryCancelledCallback), Z_Construct_UDelegateFunction_VH_UI_OnEntryCancelled__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_TextInput_Statics::NewProp_OnEntryCancelledCallback_MetaData), Z_Construct_UClass_UVH_TextInput_Statics::NewProp_OnEntryCancelledCallback_MetaData) }; // 675015889
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_TextInput_Statics::NewProp_OnTextEditedCallback_MetaData[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_TextInput.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_TextInput_Statics::NewProp_OnTextEditedCallback = { "OnTextEditedCallback", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_TextInput, OnTextEditedCallback), Z_Construct_UDelegateFunction_VH_UI_OnTextEdited__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_TextInput_Statics::NewProp_OnTextEditedCallback_MetaData), Z_Construct_UClass_UVH_TextInput_Statics::NewProp_OnTextEditedCallback_MetaData) }; // 2202380895
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_TextInput_Statics::NewProp_TextBox_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Native reference to Editable Text Box */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_TextInput.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native reference to Editable Text Box" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVH_TextInput_Statics::NewProp_TextBox = { "TextBox", nullptr, (EPropertyFlags)0x002008000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_TextInput, TextBox), Z_Construct_UClass_UEditableTextBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_TextInput_Statics::NewProp_TextBox_MetaData), Z_Construct_UClass_UVH_TextInput_Statics::NewProp_TextBox_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_TextInput_Statics::NewProp_LastEntry_MetaData[] = {
		{ "Category", "Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Native reference to Editable Text Box */" },
#endif
		{ "ModuleRelativePath", "Deprecated/Public/VH_TextInput.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Native reference to Editable Text Box" },
#endif
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UVH_TextInput_Statics::NewProp_LastEntry = { "LastEntry", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_TextInput, LastEntry), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_TextInput_Statics::NewProp_LastEntry_MetaData), Z_Construct_UClass_UVH_TextInput_Statics::NewProp_LastEntry_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVH_TextInput_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_TextInput_Statics::NewProp_OnEntrySubmittedCallback,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_TextInput_Statics::NewProp_OnEntryCancelledCallback,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_TextInput_Statics::NewProp_OnTextEditedCallback,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_TextInput_Statics::NewProp_TextBox,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_TextInput_Statics::NewProp_LastEntry,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_TextInput_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_TextInput>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_TextInput_Statics::ClassParams = {
		&UVH_TextInput::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVH_TextInput_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVH_TextInput_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_TextInput_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_TextInput_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_TextInput_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVH_TextInput()
	{
		if (!Z_Registration_Info_UClass_UVH_TextInput.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_TextInput.OuterSingleton, Z_Construct_UClass_UVH_TextInput_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_TextInput.OuterSingleton;
	}
	template<> VH_UI_API UClass* StaticClass<UVH_TextInput>()
	{
		return UVH_TextInput::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_TextInput);
	UVH_TextInput::~UVH_TextInput() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_TextInput, UVH_TextInput::StaticClass, TEXT("UVH_TextInput"), &Z_Registration_Info_UClass_UVH_TextInput, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_TextInput), 2816687259U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_4212995439(TEXT("/Script/VH_UI"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
