// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Examples/Public/DrumKeyboard_Key.h"
#include "../../Examples/Public/KeyData.h"
#include "InputCoreTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDrumKeyboard_Key() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
	UPackage* Z_Construct_UPackage__Script_VH_Keyboard();
	VH_KEYBOARD_API UClass* Z_Construct_UClass_ADrumKeyboard_Key();
	VH_KEYBOARD_API UClass* Z_Construct_UClass_ADrumKeyboard_Key_NoRegister();
	VH_KEYBOARD_API UClass* Z_Construct_UClass_UKeyboard_ContainerComponent_NoRegister();
	VH_KEYBOARD_API UScriptStruct* Z_Construct_UScriptStruct_FKeyData();
// End Cross Module References
	DEFINE_FUNCTION(ADrumKeyboard_Key::execHandleClickReleased)
	{
		P_GET_OBJECT(AActor,Z_Param_actor);
		P_GET_STRUCT(FKey,Z_Param_buttonPressed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleClickReleased(Z_Param_actor,Z_Param_buttonPressed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ADrumKeyboard_Key::execHandleClickPressed)
	{
		P_GET_OBJECT(AActor,Z_Param_actor);
		P_GET_STRUCT(FKey,Z_Param_buttonPressed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleClickPressed(Z_Param_actor,Z_Param_buttonPressed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ADrumKeyboard_Key::execHandleShiftModified)
	{
		P_GET_UBOOL(Z_Param_bShiftActive);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleShiftModified(Z_Param_bShiftActive);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ADrumKeyboard_Key::execSetContainerComponent)
	{
		P_GET_OBJECT(UKeyboard_ContainerComponent,Z_Param_keyContainerComponent);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetContainerComponent(Z_Param_keyContainerComponent);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ADrumKeyboard_Key::execPressed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Pressed();
		P_NATIVE_END;
	}
	struct DrumKeyboard_Key_eventReceiveClickPressed_Parms
	{
		AActor* actor;
		FKey buttonReleased;
	};
	struct DrumKeyboard_Key_eventReceiveClickReleased_Parms
	{
		AActor* actor;
		FKey buttonReleased;
	};
	struct DrumKeyboard_Key_eventReceiveSetDisplayString_Parms
	{
		FString keyString;
	};
	static FName NAME_ADrumKeyboard_Key_EditorTextChanged = FName(TEXT("EditorTextChanged"));
	void ADrumKeyboard_Key::EditorTextChanged()
	{
		ProcessEvent(FindFunctionChecked(NAME_ADrumKeyboard_Key_EditorTextChanged),NULL);
	}
	static FName NAME_ADrumKeyboard_Key_ReceiveClickPressed = FName(TEXT("ReceiveClickPressed"));
	void ADrumKeyboard_Key::ReceiveClickPressed(AActor* actor, FKey const& buttonReleased)
	{
		DrumKeyboard_Key_eventReceiveClickPressed_Parms Parms;
		Parms.actor=actor;
		Parms.buttonReleased=buttonReleased;
		ProcessEvent(FindFunctionChecked(NAME_ADrumKeyboard_Key_ReceiveClickPressed),&Parms);
	}
	static FName NAME_ADrumKeyboard_Key_ReceiveClickReleased = FName(TEXT("ReceiveClickReleased"));
	void ADrumKeyboard_Key::ReceiveClickReleased(AActor* actor, FKey const& buttonReleased)
	{
		DrumKeyboard_Key_eventReceiveClickReleased_Parms Parms;
		Parms.actor=actor;
		Parms.buttonReleased=buttonReleased;
		ProcessEvent(FindFunctionChecked(NAME_ADrumKeyboard_Key_ReceiveClickReleased),&Parms);
	}
	static FName NAME_ADrumKeyboard_Key_ReceiveSetDisplayString = FName(TEXT("ReceiveSetDisplayString"));
	void ADrumKeyboard_Key::ReceiveSetDisplayString(const FString& keyString)
	{
		DrumKeyboard_Key_eventReceiveSetDisplayString_Parms Parms;
		Parms.keyString=keyString;
		ProcessEvent(FindFunctionChecked(NAME_ADrumKeyboard_Key_ReceiveSetDisplayString),&Parms);
	}
	void ADrumKeyboard_Key::StaticRegisterNativesADrumKeyboard_Key()
	{
		UClass* Class = ADrumKeyboard_Key::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "HandleClickPressed", &ADrumKeyboard_Key::execHandleClickPressed },
			{ "HandleClickReleased", &ADrumKeyboard_Key::execHandleClickReleased },
			{ "HandleShiftModified", &ADrumKeyboard_Key::execHandleShiftModified },
			{ "Pressed", &ADrumKeyboard_Key::execPressed },
			{ "SetContainerComponent", &ADrumKeyboard_Key::execSetContainerComponent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ADrumKeyboard_Key_EditorTextChanged_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADrumKeyboard_Key_EditorTextChanged_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Examples/Public/DrumKeyboard_Key.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADrumKeyboard_Key_EditorTextChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADrumKeyboard_Key, nullptr, "EditorTextChanged", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_EditorTextChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADrumKeyboard_Key_EditorTextChanged_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ADrumKeyboard_Key_EditorTextChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADrumKeyboard_Key_EditorTextChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed_Statics
	{
		struct DrumKeyboard_Key_eventHandleClickPressed_Parms
		{
			AActor* actor;
			FKey buttonPressed;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actor;
		static const UECodeGen_Private::FStructPropertyParams NewProp_buttonPressed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed_Statics::NewProp_actor = { "actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DrumKeyboard_Key_eventHandleClickPressed_Parms, actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed_Statics::NewProp_buttonPressed = { "buttonPressed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DrumKeyboard_Key_eventHandleClickPressed_Parms, buttonPressed), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(0, nullptr) }; // 46000949
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed_Statics::NewProp_actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed_Statics::NewProp_buttonPressed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Examples/Public/DrumKeyboard_Key.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADrumKeyboard_Key, nullptr, "HandleClickPressed", nullptr, nullptr, Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed_Statics::DrumKeyboard_Key_eventHandleClickPressed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed_Statics::DrumKeyboard_Key_eventHandleClickPressed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased_Statics
	{
		struct DrumKeyboard_Key_eventHandleClickReleased_Parms
		{
			AActor* actor;
			FKey buttonPressed;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actor;
		static const UECodeGen_Private::FStructPropertyParams NewProp_buttonPressed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased_Statics::NewProp_actor = { "actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DrumKeyboard_Key_eventHandleClickReleased_Parms, actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased_Statics::NewProp_buttonPressed = { "buttonPressed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DrumKeyboard_Key_eventHandleClickReleased_Parms, buttonPressed), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(0, nullptr) }; // 46000949
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased_Statics::NewProp_actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased_Statics::NewProp_buttonPressed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Examples/Public/DrumKeyboard_Key.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADrumKeyboard_Key, nullptr, "HandleClickReleased", nullptr, nullptr, Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased_Statics::DrumKeyboard_Key_eventHandleClickReleased_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased_Statics::DrumKeyboard_Key_eventHandleClickReleased_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified_Statics
	{
		struct DrumKeyboard_Key_eventHandleShiftModified_Parms
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
	void Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified_Statics::NewProp_bShiftActive_SetBit(void* Obj)
	{
		((DrumKeyboard_Key_eventHandleShiftModified_Parms*)Obj)->bShiftActive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified_Statics::NewProp_bShiftActive = { "bShiftActive", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(DrumKeyboard_Key_eventHandleShiftModified_Parms), &Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified_Statics::NewProp_bShiftActive_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified_Statics::NewProp_bShiftActive,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Examples/Public/DrumKeyboard_Key.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADrumKeyboard_Key, nullptr, "HandleShiftModified", nullptr, nullptr, Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified_Statics::DrumKeyboard_Key_eventHandleShiftModified_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified_Statics::DrumKeyboard_Key_eventHandleShiftModified_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADrumKeyboard_Key_Pressed_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADrumKeyboard_Key_Pressed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Examples/Public/DrumKeyboard_Key.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADrumKeyboard_Key_Pressed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADrumKeyboard_Key, nullptr, "Pressed", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_Pressed_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADrumKeyboard_Key_Pressed_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ADrumKeyboard_Key_Pressed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADrumKeyboard_Key_Pressed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_buttonReleased_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_buttonReleased;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics::NewProp_actor = { "actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DrumKeyboard_Key_eventReceiveClickPressed_Parms, actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics::NewProp_buttonReleased_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics::NewProp_buttonReleased = { "buttonReleased", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DrumKeyboard_Key_eventReceiveClickPressed_Parms, buttonReleased), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics::NewProp_buttonReleased_MetaData), Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics::NewProp_buttonReleased_MetaData) }; // 46000949
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics::NewProp_actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics::NewProp_buttonReleased,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Examples/Public/DrumKeyboard_Key.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADrumKeyboard_Key, nullptr, "ReceiveClickPressed", nullptr, nullptr, Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics::PropPointers), sizeof(DrumKeyboard_Key_eventReceiveClickPressed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics::PropPointers) < 2048);
	static_assert(sizeof(DrumKeyboard_Key_eventReceiveClickPressed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_buttonReleased_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_buttonReleased;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics::NewProp_actor = { "actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DrumKeyboard_Key_eventReceiveClickReleased_Parms, actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics::NewProp_buttonReleased_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics::NewProp_buttonReleased = { "buttonReleased", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DrumKeyboard_Key_eventReceiveClickReleased_Parms, buttonReleased), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics::NewProp_buttonReleased_MetaData), Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics::NewProp_buttonReleased_MetaData) }; // 46000949
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics::NewProp_actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics::NewProp_buttonReleased,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Examples/Public/DrumKeyboard_Key.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADrumKeyboard_Key, nullptr, "ReceiveClickReleased", nullptr, nullptr, Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics::PropPointers), sizeof(DrumKeyboard_Key_eventReceiveClickReleased_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics::PropPointers) < 2048);
	static_assert(sizeof(DrumKeyboard_Key_eventReceiveClickReleased_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString_Statics
	{
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString_Statics::NewProp_keyString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString_Statics::NewProp_keyString = { "keyString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DrumKeyboard_Key_eventReceiveSetDisplayString_Parms, keyString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString_Statics::NewProp_keyString_MetaData), Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString_Statics::NewProp_keyString_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString_Statics::NewProp_keyString,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Examples/Public/DrumKeyboard_Key.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADrumKeyboard_Key, nullptr, "ReceiveSetDisplayString", nullptr, nullptr, Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString_Statics::PropPointers), sizeof(DrumKeyboard_Key_eventReceiveSetDisplayString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString_Statics::PropPointers) < 2048);
	static_assert(sizeof(DrumKeyboard_Key_eventReceiveSetDisplayString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics
	{
		struct DrumKeyboard_Key_eventSetContainerComponent_Parms
		{
			UKeyboard_ContainerComponent* keyContainerComponent;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_keyContainerComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_keyContainerComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics::NewProp_keyContainerComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics::NewProp_keyContainerComponent = { "keyContainerComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DrumKeyboard_Key_eventSetContainerComponent_Parms, keyContainerComponent), Z_Construct_UClass_UKeyboard_ContainerComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics::NewProp_keyContainerComponent_MetaData), Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics::NewProp_keyContainerComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics::NewProp_keyContainerComponent,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Examples/Public/DrumKeyboard_Key.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADrumKeyboard_Key, nullptr, "SetContainerComponent", nullptr, nullptr, Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics::DrumKeyboard_Key_eventSetContainerComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics::DrumKeyboard_Key_eventSetContainerComponent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADrumKeyboard_Key);
	UClass* Z_Construct_UClass_ADrumKeyboard_Key_NoRegister()
	{
		return ADrumKeyboard_Key::StaticClass();
	}
	struct Z_Construct_UClass_ADrumKeyboard_Key_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KeyData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_KeyData;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Collider_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Collider;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ContainerComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ContainerComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADrumKeyboard_Key_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Keyboard,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADrumKeyboard_Key_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ADrumKeyboard_Key_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ADrumKeyboard_Key_EditorTextChanged, "EditorTextChanged" }, // 1361502733
		{ &Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickPressed, "HandleClickPressed" }, // 1915075345
		{ &Z_Construct_UFunction_ADrumKeyboard_Key_HandleClickReleased, "HandleClickReleased" }, // 2203301557
		{ &Z_Construct_UFunction_ADrumKeyboard_Key_HandleShiftModified, "HandleShiftModified" }, // 2410782838
		{ &Z_Construct_UFunction_ADrumKeyboard_Key_Pressed, "Pressed" }, // 2320388472
		{ &Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickPressed, "ReceiveClickPressed" }, // 1394199435
		{ &Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveClickReleased, "ReceiveClickReleased" }, // 2599160064
		{ &Z_Construct_UFunction_ADrumKeyboard_Key_ReceiveSetDisplayString, "ReceiveSetDisplayString" }, // 3622171230
		{ &Z_Construct_UFunction_ADrumKeyboard_Key_SetContainerComponent, "SetContainerComponent" }, // 2599846223
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADrumKeyboard_Key_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADrumKeyboard_Key_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Examples/Public/DrumKeyboard_Key.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Examples/Public/DrumKeyboard_Key.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADrumKeyboard_Key_Statics::NewProp_KeyData_MetaData[] = {
		{ "Category", "DrumKeyboard_Key" },
		{ "ModuleRelativePath", "Examples/Public/DrumKeyboard_Key.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ADrumKeyboard_Key_Statics::NewProp_KeyData = { "KeyData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADrumKeyboard_Key, KeyData), Z_Construct_UScriptStruct_FKeyData, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADrumKeyboard_Key_Statics::NewProp_KeyData_MetaData), Z_Construct_UClass_ADrumKeyboard_Key_Statics::NewProp_KeyData_MetaData) }; // 941138177
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADrumKeyboard_Key_Statics::NewProp_Collider_MetaData[] = {
		{ "Category", "DrumKeyboard_Key" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Examples/Public/DrumKeyboard_Key.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADrumKeyboard_Key_Statics::NewProp_Collider = { "Collider", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADrumKeyboard_Key, Collider), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADrumKeyboard_Key_Statics::NewProp_Collider_MetaData), Z_Construct_UClass_ADrumKeyboard_Key_Statics::NewProp_Collider_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADrumKeyboard_Key_Statics::NewProp_ContainerComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Examples/Public/DrumKeyboard_Key.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADrumKeyboard_Key_Statics::NewProp_ContainerComponent = { "ContainerComponent", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADrumKeyboard_Key, ContainerComponent), Z_Construct_UClass_UKeyboard_ContainerComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADrumKeyboard_Key_Statics::NewProp_ContainerComponent_MetaData), Z_Construct_UClass_ADrumKeyboard_Key_Statics::NewProp_ContainerComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADrumKeyboard_Key_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADrumKeyboard_Key_Statics::NewProp_KeyData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADrumKeyboard_Key_Statics::NewProp_Collider,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADrumKeyboard_Key_Statics::NewProp_ContainerComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADrumKeyboard_Key_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADrumKeyboard_Key>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ADrumKeyboard_Key_Statics::ClassParams = {
		&ADrumKeyboard_Key::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ADrumKeyboard_Key_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ADrumKeyboard_Key_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADrumKeyboard_Key_Statics::Class_MetaDataParams), Z_Construct_UClass_ADrumKeyboard_Key_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADrumKeyboard_Key_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ADrumKeyboard_Key()
	{
		if (!Z_Registration_Info_UClass_ADrumKeyboard_Key.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADrumKeyboard_Key.OuterSingleton, Z_Construct_UClass_ADrumKeyboard_Key_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ADrumKeyboard_Key.OuterSingleton;
	}
	template<> VH_KEYBOARD_API UClass* StaticClass<ADrumKeyboard_Key>()
	{
		return ADrumKeyboard_Key::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADrumKeyboard_Key);
	ADrumKeyboard_Key::~ADrumKeyboard_Key() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADrumKeyboard_Key, ADrumKeyboard_Key::StaticClass, TEXT("ADrumKeyboard_Key"), &Z_Registration_Info_UClass_ADrumKeyboard_Key, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADrumKeyboard_Key), 710191142U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_1450960801(TEXT("/Script/VH_Keyboard"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_DrumKeyboard_Key_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
