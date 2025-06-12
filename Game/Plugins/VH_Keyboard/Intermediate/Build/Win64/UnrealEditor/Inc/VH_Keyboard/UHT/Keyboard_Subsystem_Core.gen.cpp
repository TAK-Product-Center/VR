// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Subsystems/Public/Keyboard_Subsystem_Core.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKeyboard_Subsystem_Core() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
	UPackage* Z_Construct_UPackage__Script_VH_Keyboard();
	VH_KEYBOARD_API UClass* Z_Construct_UClass_UKeyboard_Subsystem_Core();
	VH_KEYBOARD_API UClass* Z_Construct_UClass_UKeyboard_Subsystem_Core_NoRegister();
	VH_KEYBOARD_API UClass* Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_NoRegister();
	VH_KEYBOARD_API UFunction* Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics
	{
		struct Keyboard_Subsystem_Core_eventKeyboardSpawnDestroy_Parms
		{
			bool bSpawn;
			AActor* keyboardContainer;
		};
		static void NewProp_bSpawn_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSpawn;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_keyboardContainer;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::NewProp_bSpawn_SetBit(void* Obj)
	{
		((Keyboard_Subsystem_Core_eventKeyboardSpawnDestroy_Parms*)Obj)->bSpawn = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::NewProp_bSpawn = { "bSpawn", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Keyboard_Subsystem_Core_eventKeyboardSpawnDestroy_Parms), &Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::NewProp_bSpawn_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::NewProp_keyboardContainer = { "keyboardContainer", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_Subsystem_Core_eventKeyboardSpawnDestroy_Parms, keyboardContainer), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::NewProp_bSpawn,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::NewProp_keyboardContainer,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKeyboard_Subsystem_Core, nullptr, "KeyboardSpawnDestroy__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::Keyboard_Subsystem_Core_eventKeyboardSpawnDestroy_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::Keyboard_Subsystem_Core_eventKeyboardSpawnDestroy_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UKeyboard_Subsystem_Core::FKeyboardSpawnDestroy_DelegateWrapper(const FMulticastScriptDelegate& KeyboardSpawnDestroy, bool bSpawn, AActor* keyboardContainer)
{
	struct Keyboard_Subsystem_Core_eventKeyboardSpawnDestroy_Parms
	{
		bool bSpawn;
		AActor* keyboardContainer;
	};
	Keyboard_Subsystem_Core_eventKeyboardSpawnDestroy_Parms Parms;
	Parms.bSpawn=bSpawn ? true : false;
	Parms.keyboardContainer=keyboardContainer;
	KeyboardSpawnDestroy.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UKeyboard_Subsystem_Core::execHandleKeyboardDestroyed)
	{
		P_GET_OBJECT(AActor,Z_Param_actor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleKeyboardDestroyed(Z_Param_actor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKeyboard_Subsystem_Core::execIsKeyboardOpen)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsKeyboardOpen();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKeyboard_Subsystem_Core::execCreateKeyboardByClassForObject)
	{
		P_GET_OBJECT(UClass,Z_Param_keyboardClass);
		P_GET_OBJECT(UObject,Z_Param_object);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AActor**)Z_Param__Result=P_THIS->CreateKeyboardByClassForObject(Z_Param_keyboardClass,Z_Param_object);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKeyboard_Subsystem_Core::execCreateKeyboardByClassAtTransform)
	{
		P_GET_OBJECT(UClass,Z_Param_keyboardClass);
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AActor**)Z_Param__Result=P_THIS->CreateKeyboardByClassAtTransform(Z_Param_keyboardClass,Z_Param_Out_transform);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKeyboard_Subsystem_Core::execCreateKeyBoardForObject)
	{
		P_GET_OBJECT(UObject,Z_Param_object);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AActor**)Z_Param__Result=P_THIS->CreateKeyBoardForObject(Z_Param_object);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKeyboard_Subsystem_Core::execCreateKeyboardAtTransform)
	{
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AActor**)Z_Param__Result=P_THIS->CreateKeyboardAtTransform(Z_Param_Out_transform);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UKeyboard_Subsystem_Core::execUpdateSettings)
	{
		P_GET_OBJECT(UClass,Z_Param_settingsClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateSettings(Z_Param_settingsClass);
		P_NATIVE_END;
	}
	void UKeyboard_Subsystem_Core::StaticRegisterNativesUKeyboard_Subsystem_Core()
	{
		UClass* Class = UKeyboard_Subsystem_Core::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateKeyboardAtTransform", &UKeyboard_Subsystem_Core::execCreateKeyboardAtTransform },
			{ "CreateKeyboardByClassAtTransform", &UKeyboard_Subsystem_Core::execCreateKeyboardByClassAtTransform },
			{ "CreateKeyboardByClassForObject", &UKeyboard_Subsystem_Core::execCreateKeyboardByClassForObject },
			{ "CreateKeyBoardForObject", &UKeyboard_Subsystem_Core::execCreateKeyBoardForObject },
			{ "HandleKeyboardDestroyed", &UKeyboard_Subsystem_Core::execHandleKeyboardDestroyed },
			{ "IsKeyboardOpen", &UKeyboard_Subsystem_Core::execIsKeyboardOpen },
			{ "UpdateSettings", &UKeyboard_Subsystem_Core::execUpdateSettings },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics
	{
		struct Keyboard_Subsystem_Core_eventCreateKeyboardAtTransform_Parms
		{
			FTransform transform;
			AActor* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_transform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_transform;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::NewProp_transform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::NewProp_transform = { "transform", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_Subsystem_Core_eventCreateKeyboardAtTransform_Parms, transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::NewProp_transform_MetaData), Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::NewProp_transform_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_Subsystem_Core_eventCreateKeyboardAtTransform_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::NewProp_transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKeyboard_Subsystem_Core, nullptr, "CreateKeyboardAtTransform", nullptr, nullptr, Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::Keyboard_Subsystem_Core_eventCreateKeyboardAtTransform_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::Keyboard_Subsystem_Core_eventCreateKeyboardAtTransform_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics
	{
		struct Keyboard_Subsystem_Core_eventCreateKeyboardByClassAtTransform_Parms
		{
			UClass* keyboardClass;
			FTransform transform;
			AActor* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_keyboardClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_transform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_transform;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::NewProp_keyboardClass = { "keyboardClass", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_Subsystem_Core_eventCreateKeyboardByClassAtTransform_Parms, keyboardClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::NewProp_transform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::NewProp_transform = { "transform", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_Subsystem_Core_eventCreateKeyboardByClassAtTransform_Parms, transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::NewProp_transform_MetaData), Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::NewProp_transform_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_Subsystem_Core_eventCreateKeyboardByClassAtTransform_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::NewProp_keyboardClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::NewProp_transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKeyboard_Subsystem_Core, nullptr, "CreateKeyboardByClassAtTransform", nullptr, nullptr, Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::Keyboard_Subsystem_Core_eventCreateKeyboardByClassAtTransform_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::Keyboard_Subsystem_Core_eventCreateKeyboardByClassAtTransform_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics
	{
		struct Keyboard_Subsystem_Core_eventCreateKeyboardByClassForObject_Parms
		{
			UClass* keyboardClass;
			UObject* object;
			AActor* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_keyboardClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_object;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::NewProp_keyboardClass = { "keyboardClass", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_Subsystem_Core_eventCreateKeyboardByClassForObject_Parms, keyboardClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::NewProp_object = { "object", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_Subsystem_Core_eventCreateKeyboardByClassForObject_Parms, object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_Subsystem_Core_eventCreateKeyboardByClassForObject_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::NewProp_keyboardClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::NewProp_object,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKeyboard_Subsystem_Core, nullptr, "CreateKeyboardByClassForObject", nullptr, nullptr, Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::Keyboard_Subsystem_Core_eventCreateKeyboardByClassForObject_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::Keyboard_Subsystem_Core_eventCreateKeyboardByClassForObject_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject_Statics
	{
		struct Keyboard_Subsystem_Core_eventCreateKeyBoardForObject_Parms
		{
			UObject* object;
			AActor* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_object;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject_Statics::NewProp_object = { "object", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_Subsystem_Core_eventCreateKeyBoardForObject_Parms, object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_Subsystem_Core_eventCreateKeyBoardForObject_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject_Statics::NewProp_object,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKeyboard_Subsystem_Core, nullptr, "CreateKeyBoardForObject", nullptr, nullptr, Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject_Statics::Keyboard_Subsystem_Core_eventCreateKeyBoardForObject_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject_Statics::Keyboard_Subsystem_Core_eventCreateKeyBoardForObject_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKeyboard_Subsystem_Core_HandleKeyboardDestroyed_Statics
	{
		struct Keyboard_Subsystem_Core_eventHandleKeyboardDestroyed_Parms
		{
			AActor* actor;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_HandleKeyboardDestroyed_Statics::NewProp_actor = { "actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_Subsystem_Core_eventHandleKeyboardDestroyed_Parms, actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKeyboard_Subsystem_Core_HandleKeyboardDestroyed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKeyboard_Subsystem_Core_HandleKeyboardDestroyed_Statics::NewProp_actor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKeyboard_Subsystem_Core_HandleKeyboardDestroyed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_HandleKeyboardDestroyed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKeyboard_Subsystem_Core, nullptr, "HandleKeyboardDestroyed", nullptr, nullptr, Z_Construct_UFunction_UKeyboard_Subsystem_Core_HandleKeyboardDestroyed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_HandleKeyboardDestroyed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKeyboard_Subsystem_Core_HandleKeyboardDestroyed_Statics::Keyboard_Subsystem_Core_eventHandleKeyboardDestroyed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_HandleKeyboardDestroyed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKeyboard_Subsystem_Core_HandleKeyboardDestroyed_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_HandleKeyboardDestroyed_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKeyboard_Subsystem_Core_HandleKeyboardDestroyed_Statics::Keyboard_Subsystem_Core_eventHandleKeyboardDestroyed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKeyboard_Subsystem_Core_HandleKeyboardDestroyed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKeyboard_Subsystem_Core_HandleKeyboardDestroyed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen_Statics
	{
		struct Keyboard_Subsystem_Core_eventIsKeyboardOpen_Parms
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
	void Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Keyboard_Subsystem_Core_eventIsKeyboardOpen_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Keyboard_Subsystem_Core_eventIsKeyboardOpen_Parms), &Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKeyboard_Subsystem_Core, nullptr, "IsKeyboardOpen", nullptr, nullptr, Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen_Statics::Keyboard_Subsystem_Core_eventIsKeyboardOpen_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen_Statics::Keyboard_Subsystem_Core_eventIsKeyboardOpen_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UKeyboard_Subsystem_Core_UpdateSettings_Statics
	{
		struct Keyboard_Subsystem_Core_eventUpdateSettings_Parms
		{
			TSubclassOf<UKeyboard_Subsystem_Core_Settings>  settingsClass;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_settingsClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_UpdateSettings_Statics::NewProp_settingsClass = { "settingsClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_Subsystem_Core_eventUpdateSettings_Parms, settingsClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UKeyboard_Subsystem_Core_Settings_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UKeyboard_Subsystem_Core_UpdateSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UKeyboard_Subsystem_Core_UpdateSettings_Statics::NewProp_settingsClass,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UKeyboard_Subsystem_Core_UpdateSettings_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UKeyboard_Subsystem_Core_UpdateSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UKeyboard_Subsystem_Core, nullptr, "UpdateSettings", nullptr, nullptr, Z_Construct_UFunction_UKeyboard_Subsystem_Core_UpdateSettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_UpdateSettings_Statics::PropPointers), sizeof(Z_Construct_UFunction_UKeyboard_Subsystem_Core_UpdateSettings_Statics::Keyboard_Subsystem_Core_eventUpdateSettings_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_UpdateSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UKeyboard_Subsystem_Core_UpdateSettings_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UKeyboard_Subsystem_Core_UpdateSettings_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UKeyboard_Subsystem_Core_UpdateSettings_Statics::Keyboard_Subsystem_Core_eventUpdateSettings_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UKeyboard_Subsystem_Core_UpdateSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UKeyboard_Subsystem_Core_UpdateSettings_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UKeyboard_Subsystem_Core);
	UClass* Z_Construct_UClass_UKeyboard_Subsystem_Core_NoRegister()
	{
		return UKeyboard_Subsystem_Core::StaticClass();
	}
	struct Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultKeyboardClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_DefaultKeyboardClass;
		static const UECodeGen_Private::FClassPropertyParams NewProp_KeyboardClassMap_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_KeyboardClassMap_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KeyboardClassMap_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_KeyboardClassMap;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_KeyboardCollisionChannel_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_KeyboardCollisionChannel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnKeyboardSpawnDestroy_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnKeyboardSpawnDestroy;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Keyboard_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Keyboard;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Keyboard,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardAtTransform, "CreateKeyboardAtTransform" }, // 62031912
		{ &Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassAtTransform, "CreateKeyboardByClassAtTransform" }, // 15399276
		{ &Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyboardByClassForObject, "CreateKeyboardByClassForObject" }, // 2733643399
		{ &Z_Construct_UFunction_UKeyboard_Subsystem_Core_CreateKeyBoardForObject, "CreateKeyBoardForObject" }, // 2987019494
		{ &Z_Construct_UFunction_UKeyboard_Subsystem_Core_HandleKeyboardDestroyed, "HandleKeyboardDestroyed" }, // 1907706226
		{ &Z_Construct_UFunction_UKeyboard_Subsystem_Core_IsKeyboardOpen, "IsKeyboardOpen" }, // 2702235712
		{ &Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature, "KeyboardSpawnDestroy__DelegateSignature" }, // 1428342530
		{ &Z_Construct_UFunction_UKeyboard_Subsystem_Core_UpdateSettings, "UpdateSettings" }, // 3759496928
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Subsystems/Public/Keyboard_Subsystem_Core.h" },
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_DefaultKeyboardClass_MetaData[] = {
		{ "Category", "Keyboard_Subsystem_Core" },
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_DefaultKeyboardClass = { "DefaultKeyboardClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_Subsystem_Core, DefaultKeyboardClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_DefaultKeyboardClass_MetaData), Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_DefaultKeyboardClass_MetaData) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_KeyboardClassMap_ValueProp = { "KeyboardClassMap", nullptr, (EPropertyFlags)0x0004000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_KeyboardClassMap_Key_KeyProp = { "KeyboardClassMap_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_KeyboardClassMap_MetaData[] = {
		{ "Category", "Keyboard_Subsystem_Core" },
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_KeyboardClassMap = { "KeyboardClassMap", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_Subsystem_Core, KeyboardClassMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_KeyboardClassMap_MetaData), Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_KeyboardClassMap_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_KeyboardCollisionChannel_MetaData[] = {
		{ "Category", "Keyboard_Subsystem_Core" },
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_KeyboardCollisionChannel = { "KeyboardCollisionChannel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_Subsystem_Core, KeyboardCollisionChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_KeyboardCollisionChannel_MetaData), Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_KeyboardCollisionChannel_MetaData) }; // 1822723181
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_OnKeyboardSpawnDestroy_MetaData[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_OnKeyboardSpawnDestroy = { "OnKeyboardSpawnDestroy", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_Subsystem_Core, OnKeyboardSpawnDestroy), Z_Construct_UDelegateFunction_UKeyboard_Subsystem_Core_KeyboardSpawnDestroy__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_OnKeyboardSpawnDestroy_MetaData), Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_OnKeyboardSpawnDestroy_MetaData) }; // 1428342530
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_Keyboard_MetaData[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Keyboard_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_Keyboard = { "Keyboard", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UKeyboard_Subsystem_Core, Keyboard), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_Keyboard_MetaData), Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_Keyboard_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_DefaultKeyboardClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_KeyboardClassMap_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_KeyboardClassMap_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_KeyboardClassMap,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_KeyboardCollisionChannel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_OnKeyboardSpawnDestroy,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::NewProp_Keyboard,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UKeyboard_Subsystem_Core>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::ClassParams = {
		&UKeyboard_Subsystem_Core::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::Class_MetaDataParams), Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UKeyboard_Subsystem_Core()
	{
		if (!Z_Registration_Info_UClass_UKeyboard_Subsystem_Core.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UKeyboard_Subsystem_Core.OuterSingleton, Z_Construct_UClass_UKeyboard_Subsystem_Core_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UKeyboard_Subsystem_Core.OuterSingleton;
	}
	template<> VH_KEYBOARD_API UClass* StaticClass<UKeyboard_Subsystem_Core>()
	{
		return UKeyboard_Subsystem_Core::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UKeyboard_Subsystem_Core);
	UKeyboard_Subsystem_Core::~UKeyboard_Subsystem_Core() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UKeyboard_Subsystem_Core, UKeyboard_Subsystem_Core::StaticClass, TEXT("UKeyboard_Subsystem_Core"), &Z_Registration_Info_UClass_UKeyboard_Subsystem_Core, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UKeyboard_Subsystem_Core), 2556326511U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_2766811398(TEXT("/Script/VH_Keyboard"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Subsystems_Public_Keyboard_Subsystem_Core_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
