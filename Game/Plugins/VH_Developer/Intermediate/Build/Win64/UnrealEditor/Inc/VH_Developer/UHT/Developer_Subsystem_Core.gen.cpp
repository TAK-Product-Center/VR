// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Subsystems/Public/Developer_Subsystem_Core.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_Subsystem_Core() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_Core();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_Core_NoRegister();
	VH_DEVELOPER_API UEnum* Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode();
	VH_DEVELOPER_API UFunction* Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EHardwareInterfaceMode;
	static UEnum* EHardwareInterfaceMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EHardwareInterfaceMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EHardwareInterfaceMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode, (UObject*)Z_Construct_UPackage__Script_VH_Developer(), TEXT("EHardwareInterfaceMode"));
		}
		return Z_Registration_Info_UEnum_EHardwareInterfaceMode.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UEnum* StaticEnum<EHardwareInterfaceMode>()
	{
		return EHardwareInterfaceMode_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode_Statics::Enumerators[] = {
		{ "EHardwareInterfaceMode::Unknown", (int64)EHardwareInterfaceMode::Unknown },
		{ "EHardwareInterfaceMode::Desktop", (int64)EHardwareInterfaceMode::Desktop },
		{ "EHardwareInterfaceMode::VR", (int64)EHardwareInterfaceMode::VR },
		{ "EHardwareInterfaceMode::VREmulation", (int64)EHardwareInterfaceMode::VREmulation },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * This enum relates to the hardware-centric displays and input interfaces that the player uses.\n *   'Desktop' implies 2D displays with keyboard/mouse/gamepad/touchscreen interaction.\n *   'VR' implies a HMD (Head-Mounted Display) with hand controllers (or in some cases, hardware-tracked hands).\n *   'VREmulation' implies 2D displays, but using the keyboard/mouse/etc to manipulate emulated VR HMD and hand controllers.\n */" },
#endif
		{ "Desktop.Name", "EHardwareInterfaceMode::Desktop" },
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* This enum relates to the hardware-centric displays and input interfaces that the player uses.\n*   'Desktop' implies 2D displays with keyboard/mouse/gamepad/touchscreen interaction.\n*   'VR' implies a HMD (Head-Mounted Display) with hand controllers (or in some cases, hardware-tracked hands).\n*   'VREmulation' implies 2D displays, but using the keyboard/mouse/etc to manipulate emulated VR HMD and hand controllers." },
#endif
		{ "Unknown.Name", "EHardwareInterfaceMode::Unknown" },
		{ "VR.Name", "EHardwareInterfaceMode::VR" },
		{ "VREmulation.Name", "EHardwareInterfaceMode::VREmulation" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_Developer,
		nullptr,
		"EHardwareInterfaceMode",
		"EHardwareInterfaceMode",
		Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode()
	{
		if (!Z_Registration_Info_UEnum_EHardwareInterfaceMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EHardwareInterfaceMode.InnerSingleton, Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EHardwareInterfaceMode.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics
	{
		struct Developer_Subsystem_Core_eventOnHardwareInterfaceModeChanged_Parms
		{
			EHardwareInterfaceMode newMode;
			EHardwareInterfaceMode previousMode;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_newMode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_newMode;
		static const UECodeGen_Private::FBytePropertyParams NewProp_previousMode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_previousMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::NewProp_newMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::NewProp_newMode = { "newMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Core_eventOnHardwareInterfaceModeChanged_Parms, newMode), Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode, METADATA_PARAMS(0, nullptr) }; // 2688149405
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::NewProp_previousMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::NewProp_previousMode = { "previousMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Core_eventOnHardwareInterfaceModeChanged_Parms, previousMode), Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode, METADATA_PARAMS(0, nullptr) }; // 2688149405
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::NewProp_newMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::NewProp_newMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::NewProp_previousMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::NewProp_previousMode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Core, nullptr, "OnHardwareInterfaceModeChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::Developer_Subsystem_Core_eventOnHardwareInterfaceModeChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::Developer_Subsystem_Core_eventOnHardwareInterfaceModeChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UDeveloper_Subsystem_Core::FOnHardwareInterfaceModeChanged_DelegateWrapper(const FMulticastScriptDelegate& OnHardwareInterfaceModeChanged, EHardwareInterfaceMode newMode, EHardwareInterfaceMode previousMode)
{
	struct Developer_Subsystem_Core_eventOnHardwareInterfaceModeChanged_Parms
	{
		EHardwareInterfaceMode newMode;
		EHardwareInterfaceMode previousMode;
	};
	Developer_Subsystem_Core_eventOnHardwareInterfaceModeChanged_Parms Parms;
	Parms.newMode=newMode;
	Parms.previousMode=previousMode;
	OnHardwareInterfaceModeChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Core::execTest_SetHardwareInterfaceMode)
	{
		P_GET_TARRAY_REF(FString,Z_Param_Out_arguments);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Test_SetHardwareInterfaceMode(Z_Param_Out_arguments);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Core::execGetHardwareInterfaceMode)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EHardwareInterfaceMode*)Z_Param__Result=P_THIS->GetHardwareInterfaceMode();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Core::execSetHardwareInterfaceMode)
	{
		P_GET_ENUM(EHardwareInterfaceMode,Z_Param_newMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetHardwareInterfaceMode(EHardwareInterfaceMode(Z_Param_newMode));
		P_NATIVE_END;
	}
	void UDeveloper_Subsystem_Core::StaticRegisterNativesUDeveloper_Subsystem_Core()
	{
		UClass* Class = UDeveloper_Subsystem_Core::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetHardwareInterfaceMode", &UDeveloper_Subsystem_Core::execGetHardwareInterfaceMode },
			{ "SetHardwareInterfaceMode", &UDeveloper_Subsystem_Core::execSetHardwareInterfaceMode },
			{ "Test_SetHardwareInterfaceMode", &UDeveloper_Subsystem_Core::execTest_SetHardwareInterfaceMode },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode_Statics
	{
		struct Developer_Subsystem_Core_eventGetHardwareInterfaceMode_Parms
		{
			EHardwareInterfaceMode ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Core_eventGetHardwareInterfaceMode_Parms, ReturnValue), Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode, METADATA_PARAMS(0, nullptr) }; // 2688149405
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Core, nullptr, "GetHardwareInterfaceMode", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode_Statics::Developer_Subsystem_Core_eventGetHardwareInterfaceMode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode_Statics::Developer_Subsystem_Core_eventGetHardwareInterfaceMode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode_Statics
	{
		struct Developer_Subsystem_Core_eventSetHardwareInterfaceMode_Parms
		{
			EHardwareInterfaceMode newMode;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_newMode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_newMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode_Statics::NewProp_newMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode_Statics::NewProp_newMode = { "newMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Core_eventSetHardwareInterfaceMode_Parms, newMode), Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode, METADATA_PARAMS(0, nullptr) }; // 2688149405
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode_Statics::NewProp_newMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode_Statics::NewProp_newMode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Core, nullptr, "SetHardwareInterfaceMode", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode_Statics::Developer_Subsystem_Core_eventSetHardwareInterfaceMode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode_Statics::Developer_Subsystem_Core_eventSetHardwareInterfaceMode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics
	{
		struct Developer_Subsystem_Core_eventTest_SetHardwareInterfaceMode_Parms
		{
			TArray<FString> arguments;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_arguments_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_arguments_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_arguments;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::NewProp_arguments_Inner = { "arguments", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::NewProp_arguments_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::NewProp_arguments = { "arguments", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Core_eventTest_SetHardwareInterfaceMode_Parms, arguments), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::NewProp_arguments_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::NewProp_arguments_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::NewProp_arguments_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::NewProp_arguments,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Core, nullptr, "Test_SetHardwareInterfaceMode", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::Developer_Subsystem_Core_eventTest_SetHardwareInterfaceMode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420601, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::Developer_Subsystem_Core_eventTest_SetHardwareInterfaceMode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_Subsystem_Core);
	UClass* Z_Construct_UClass_UDeveloper_Subsystem_Core_NoRegister()
	{
		return UDeveloper_Subsystem_Core::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnHardwareInterfaceModeChanged_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnHardwareInterfaceModeChanged;
		static const UECodeGen_Private::FBytePropertyParams NewProp_DefaultHardwareInterfaceMode_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultHardwareInterfaceMode_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_DefaultHardwareInterfaceMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Core_GetHardwareInterfaceMode, "GetHardwareInterfaceMode" }, // 85295096
		{ &Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature, "OnHardwareInterfaceModeChanged__DelegateSignature" }, // 2405994998
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Core_SetHardwareInterfaceMode, "SetHardwareInterfaceMode" }, // 796460573
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Core_Test_SetHardwareInterfaceMode, "Test_SetHardwareInterfaceMode" }, // 1600063179
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Subsystems/Public/Developer_Subsystem_Core.h" },
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Core.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::NewProp_OnHardwareInterfaceModeChanged_MetaData[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::NewProp_OnHardwareInterfaceModeChanged = { "OnHardwareInterfaceModeChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_Subsystem_Core, OnHardwareInterfaceModeChanged), Z_Construct_UDelegateFunction_UDeveloper_Subsystem_Core_OnHardwareInterfaceModeChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::NewProp_OnHardwareInterfaceModeChanged_MetaData), Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::NewProp_OnHardwareInterfaceModeChanged_MetaData) }; // 2405994998
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::NewProp_DefaultHardwareInterfaceMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::NewProp_DefaultHardwareInterfaceMode_MetaData[] = {
		{ "Category", "Developer_Subsystem_Core" },
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::NewProp_DefaultHardwareInterfaceMode = { "DefaultHardwareInterfaceMode", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_Subsystem_Core, DefaultHardwareInterfaceMode), Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::NewProp_DefaultHardwareInterfaceMode_MetaData), Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::NewProp_DefaultHardwareInterfaceMode_MetaData) }; // 2688149405
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::NewProp_OnHardwareInterfaceModeChanged,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::NewProp_DefaultHardwareInterfaceMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::NewProp_DefaultHardwareInterfaceMode,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_Subsystem_Core>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::ClassParams = {
		&UDeveloper_Subsystem_Core::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDeveloper_Subsystem_Core()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_Subsystem_Core.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_Subsystem_Core.OuterSingleton, Z_Construct_UClass_UDeveloper_Subsystem_Core_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_Subsystem_Core.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_Subsystem_Core>()
	{
		return UDeveloper_Subsystem_Core::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_Subsystem_Core);
	UDeveloper_Subsystem_Core::~UDeveloper_Subsystem_Core() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_Statics::EnumInfo[] = {
		{ EHardwareInterfaceMode_StaticEnum, TEXT("EHardwareInterfaceMode"), &Z_Registration_Info_UEnum_EHardwareInterfaceMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2688149405U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_Subsystem_Core, UDeveloper_Subsystem_Core::StaticClass, TEXT("UDeveloper_Subsystem_Core"), &Z_Registration_Info_UClass_UDeveloper_Subsystem_Core, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_Subsystem_Core), 706866505U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_709185103(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Core_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
