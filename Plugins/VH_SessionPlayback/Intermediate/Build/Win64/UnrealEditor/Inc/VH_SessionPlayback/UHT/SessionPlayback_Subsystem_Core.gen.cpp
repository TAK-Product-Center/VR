// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Subsystems/Public/SessionPlayback_Subsystem_Core.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSessionPlayback_Subsystem_Core() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	UPackage* Z_Construct_UPackage__Script_VH_SessionPlayback();
	VH_SESSIONPLAYBACK_API UClass* Z_Construct_UClass_USessionPlayback_Impl_NoRegister();
	VH_SESSIONPLAYBACK_API UClass* Z_Construct_UClass_USessionPlayback_Subsystem_Core();
	VH_SESSIONPLAYBACK_API UClass* Z_Construct_UClass_USessionPlayback_Subsystem_Core_NoRegister();
	VH_SESSIONPLAYBACK_API UEnum* Z_Construct_UEnum_VH_SessionPlayback_EPlaybackStatus();
	VH_SESSIONPLAYBACK_API UFunction* Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature();
	VH_SESSIONPLAYBACK_API UFunction* Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EPlaybackStatus;
	static UEnum* EPlaybackStatus_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EPlaybackStatus.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EPlaybackStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_SessionPlayback_EPlaybackStatus, (UObject*)Z_Construct_UPackage__Script_VH_SessionPlayback(), TEXT("EPlaybackStatus"));
		}
		return Z_Registration_Info_UEnum_EPlaybackStatus.OuterSingleton;
	}
	template<> VH_SESSIONPLAYBACK_API UEnum* StaticEnum<EPlaybackStatus>()
	{
		return EPlaybackStatus_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_SessionPlayback_EPlaybackStatus_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_SessionPlayback_EPlaybackStatus_Statics::Enumerators[] = {
		{ "EPlaybackStatus::EPS_Idle", (int64)EPlaybackStatus::EPS_Idle },
		{ "EPlaybackStatus::EPS_PlaybackInProgress", (int64)EPlaybackStatus::EPS_PlaybackInProgress },
		{ "EPlaybackStatus::EPS_PlaybackFinished", (int64)EPlaybackStatus::EPS_PlaybackFinished },
		{ "EPlaybackStatus::EPS_PlaybackRecording", (int64)EPlaybackStatus::EPS_PlaybackRecording },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_SessionPlayback_EPlaybackStatus_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Enums\n// ---------------------------------\n" },
#endif
		{ "EPS_Idle.Name", "EPlaybackStatus::EPS_Idle" },
		{ "EPS_PlaybackFinished.Name", "EPlaybackStatus::EPS_PlaybackFinished" },
		{ "EPS_PlaybackInProgress.Name", "EPlaybackStatus::EPS_PlaybackInProgress" },
		{ "EPS_PlaybackRecording.Name", "EPlaybackStatus::EPS_PlaybackRecording" },
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Enums" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_SessionPlayback_EPlaybackStatus_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_SessionPlayback,
		nullptr,
		"EPlaybackStatus",
		"EPlaybackStatus",
		Z_Construct_UEnum_VH_SessionPlayback_EPlaybackStatus_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_SessionPlayback_EPlaybackStatus_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_SessionPlayback_EPlaybackStatus_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_SessionPlayback_EPlaybackStatus_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_SessionPlayback_EPlaybackStatus()
	{
		if (!Z_Registration_Info_UEnum_EPlaybackStatus.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EPlaybackStatus.InnerSingleton, Z_Construct_UEnum_VH_SessionPlayback_EPlaybackStatus_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EPlaybackStatus.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature_Statics
	{
		struct SessionPlayback_Subsystem_Core_eventPlaybackRateUpdated_Parms
		{
			float playbackRate;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_playbackRate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature_Statics::NewProp_playbackRate = { "playbackRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SessionPlayback_Subsystem_Core_eventPlaybackRateUpdated_Parms, playbackRate), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature_Statics::NewProp_playbackRate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "PlaybackRateUpdated__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature_Statics::SessionPlayback_Subsystem_Core_eventPlaybackRateUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature_Statics::SessionPlayback_Subsystem_Core_eventPlaybackRateUpdated_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void USessionPlayback_Subsystem_Core::FPlaybackRateUpdated_DelegateWrapper(const FMulticastScriptDelegate& PlaybackRateUpdated, float playbackRate)
{
	struct SessionPlayback_Subsystem_Core_eventPlaybackRateUpdated_Parms
	{
		float playbackRate;
	};
	SessionPlayback_Subsystem_Core_eventPlaybackRateUpdated_Parms Parms;
	Parms.playbackRate=playbackRate;
	PlaybackRateUpdated.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature_Statics
	{
		struct SessionPlayback_Subsystem_Core_eventPlaybackStatusUpdated_Parms
		{
			EPlaybackStatus status;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_status_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_status;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature_Statics::NewProp_status_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature_Statics::NewProp_status = { "status", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SessionPlayback_Subsystem_Core_eventPlaybackStatusUpdated_Parms, status), Z_Construct_UEnum_VH_SessionPlayback_EPlaybackStatus, METADATA_PARAMS(0, nullptr) }; // 3817341635
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature_Statics::NewProp_status_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature_Statics::NewProp_status,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "PlaybackStatusUpdated__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature_Statics::SessionPlayback_Subsystem_Core_eventPlaybackStatusUpdated_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature_Statics::SessionPlayback_Subsystem_Core_eventPlaybackStatusUpdated_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void USessionPlayback_Subsystem_Core::FPlaybackStatusUpdated_DelegateWrapper(const FMulticastScriptDelegate& PlaybackStatusUpdated, EPlaybackStatus status)
{
	struct SessionPlayback_Subsystem_Core_eventPlaybackStatusUpdated_Parms
	{
		EPlaybackStatus status;
	};
	SessionPlayback_Subsystem_Core_eventPlaybackStatusUpdated_Parms Parms;
	Parms.status=status;
	PlaybackStatusUpdated.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(USessionPlayback_Subsystem_Core::execTest_StopRecordSessionPlayback)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Test_StopRecordSessionPlayback();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USessionPlayback_Subsystem_Core::execTest_RecordSessionPlayback)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_fullPathToFile);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Test_RecordSessionPlayback(Z_Param_fullPathToFile);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USessionPlayback_Subsystem_Core::execTest_LoadSessionPlayback)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_fullPathToFile);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Test_LoadSessionPlayback(Z_Param_fullPathToFile);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USessionPlayback_Subsystem_Core::execIsPlaying)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsPlaying();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USessionPlayback_Subsystem_Core::execGetPlaybackStatus)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EPlaybackStatus*)Z_Param__Result=P_THIS->GetPlaybackStatus();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USessionPlayback_Subsystem_Core::execStopRecord)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopRecord();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USessionPlayback_Subsystem_Core::execStartRecord)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_fullPathToFile);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->StartRecord(Z_Param_fullPathToFile);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USessionPlayback_Subsystem_Core::execGetSecondsPassed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetSecondsPassed();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USessionPlayback_Subsystem_Core::execSetSecondsPassed)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_secondsPassed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSecondsPassed(Z_Param_secondsPassed);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USessionPlayback_Subsystem_Core::execGetPlaybackDuration)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetPlaybackDuration();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USessionPlayback_Subsystem_Core::execGetPlaybackRate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetPlaybackRate();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USessionPlayback_Subsystem_Core::execSetPlaybackRate)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_playbackRate);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPlaybackRate(Z_Param_playbackRate);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USessionPlayback_Subsystem_Core::execUnloadPlayback)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UnloadPlayback();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USessionPlayback_Subsystem_Core::execLoadPlayback)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_fullPathToFile);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_playbackDuration);
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_error);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->LoadPlayback(Z_Param_fullPathToFile,Z_Param_Out_playbackDuration,Z_Param_Out_error);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USessionPlayback_Subsystem_Core::execGetImplementation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USessionPlayback_Impl**)Z_Param__Result=P_THIS->GetImplementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USessionPlayback_Subsystem_Core::execSetImplementation)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_implementationID);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SetImplementation(Z_Param_implementationID);
		P_NATIVE_END;
	}
	void USessionPlayback_Subsystem_Core::StaticRegisterNativesUSessionPlayback_Subsystem_Core()
	{
		UClass* Class = USessionPlayback_Subsystem_Core::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetImplementation", &USessionPlayback_Subsystem_Core::execGetImplementation },
			{ "GetPlaybackDuration", &USessionPlayback_Subsystem_Core::execGetPlaybackDuration },
			{ "GetPlaybackRate", &USessionPlayback_Subsystem_Core::execGetPlaybackRate },
			{ "GetPlaybackStatus", &USessionPlayback_Subsystem_Core::execGetPlaybackStatus },
			{ "GetSecondsPassed", &USessionPlayback_Subsystem_Core::execGetSecondsPassed },
			{ "IsPlaying", &USessionPlayback_Subsystem_Core::execIsPlaying },
			{ "LoadPlayback", &USessionPlayback_Subsystem_Core::execLoadPlayback },
			{ "SetImplementation", &USessionPlayback_Subsystem_Core::execSetImplementation },
			{ "SetPlaybackRate", &USessionPlayback_Subsystem_Core::execSetPlaybackRate },
			{ "SetSecondsPassed", &USessionPlayback_Subsystem_Core::execSetSecondsPassed },
			{ "StartRecord", &USessionPlayback_Subsystem_Core::execStartRecord },
			{ "StopRecord", &USessionPlayback_Subsystem_Core::execStopRecord },
			{ "Test_LoadSessionPlayback", &USessionPlayback_Subsystem_Core::execTest_LoadSessionPlayback },
			{ "Test_RecordSessionPlayback", &USessionPlayback_Subsystem_Core::execTest_RecordSessionPlayback },
			{ "Test_StopRecordSessionPlayback", &USessionPlayback_Subsystem_Core::execTest_StopRecordSessionPlayback },
			{ "UnloadPlayback", &USessionPlayback_Subsystem_Core::execUnloadPlayback },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetImplementation_Statics
	{
		struct SessionPlayback_Subsystem_Core_eventGetImplementation_Parms
		{
			USessionPlayback_Impl* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetImplementation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SessionPlayback_Subsystem_Core_eventGetImplementation_Parms, ReturnValue), Z_Construct_UClass_USessionPlayback_Impl_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetImplementation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetImplementation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetImplementation_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Returns currently used implementation or nullptr if no implementation is set\n\x09* \\return current implementation\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Returns currently used implementation or nullptr if no implementation is set\n* \\return current implementation" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetImplementation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "GetImplementation", nullptr, nullptr, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetImplementation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetImplementation_Statics::PropPointers), sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetImplementation_Statics::SessionPlayback_Subsystem_Core_eventGetImplementation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetImplementation_Statics::Function_MetaDataParams), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetImplementation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetImplementation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetImplementation_Statics::SessionPlayback_Subsystem_Core_eventGetImplementation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetImplementation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetImplementation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackDuration_Statics
	{
		struct SessionPlayback_Subsystem_Core_eventGetPlaybackDuration_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackDuration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SessionPlayback_Subsystem_Core_eventGetPlaybackDuration_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackDuration_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackDuration_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackDuration_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Returns playback duration in seconds\n\x09* \\return Playback duration\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Returns playback duration in seconds\n* \\return Playback duration" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackDuration_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "GetPlaybackDuration", nullptr, nullptr, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackDuration_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackDuration_Statics::PropPointers), sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackDuration_Statics::SessionPlayback_Subsystem_Core_eventGetPlaybackDuration_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackDuration_Statics::Function_MetaDataParams), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackDuration_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackDuration_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackDuration_Statics::SessionPlayback_Subsystem_Core_eventGetPlaybackDuration_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackDuration()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackDuration_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackRate_Statics
	{
		struct SessionPlayback_Subsystem_Core_eventGetPlaybackRate_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackRate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SessionPlayback_Subsystem_Core_eventGetPlaybackRate_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackRate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackRate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackRate_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Returns playback rate\n\x09* \\return Playback rate\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Returns playback rate\n* \\return Playback rate" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackRate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "GetPlaybackRate", nullptr, nullptr, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackRate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackRate_Statics::PropPointers), sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackRate_Statics::SessionPlayback_Subsystem_Core_eventGetPlaybackRate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackRate_Statics::Function_MetaDataParams), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackRate_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackRate_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackRate_Statics::SessionPlayback_Subsystem_Core_eventGetPlaybackRate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackRate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackRate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus_Statics
	{
		struct SessionPlayback_Subsystem_Core_eventGetPlaybackStatus_Parms
		{
			EPlaybackStatus ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SessionPlayback_Subsystem_Core_eventGetPlaybackStatus_Parms, ReturnValue), Z_Construct_UEnum_VH_SessionPlayback_EPlaybackStatus, METADATA_PARAMS(0, nullptr) }; // 3817341635
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Returns status of playback\n\x09* \\return Playback status\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Returns status of playback\n* \\return Playback status" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "GetPlaybackStatus", nullptr, nullptr, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus_Statics::PropPointers), sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus_Statics::SessionPlayback_Subsystem_Core_eventGetPlaybackStatus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus_Statics::Function_MetaDataParams), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus_Statics::SessionPlayback_Subsystem_Core_eventGetPlaybackStatus_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetSecondsPassed_Statics
	{
		struct SessionPlayback_Subsystem_Core_eventGetSecondsPassed_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetSecondsPassed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SessionPlayback_Subsystem_Core_eventGetSecondsPassed_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetSecondsPassed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetSecondsPassed_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetSecondsPassed_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Returns number of seconds passed in the session playback\n\x09* \\return Number of seconds passed\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Returns number of seconds passed in the session playback\n* \\return Number of seconds passed" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetSecondsPassed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "GetSecondsPassed", nullptr, nullptr, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetSecondsPassed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetSecondsPassed_Statics::PropPointers), sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetSecondsPassed_Statics::SessionPlayback_Subsystem_Core_eventGetSecondsPassed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetSecondsPassed_Statics::Function_MetaDataParams), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetSecondsPassed_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetSecondsPassed_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetSecondsPassed_Statics::SessionPlayback_Subsystem_Core_eventGetSecondsPassed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetSecondsPassed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetSecondsPassed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying_Statics
	{
		struct SessionPlayback_Subsystem_Core_eventIsPlaying_Parms
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
	void Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SessionPlayback_Subsystem_Core_eventIsPlaying_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SessionPlayback_Subsystem_Core_eventIsPlaying_Parms), &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Returns if playback is occurring\n\x09* \\return True if playback is occurring\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Returns if playback is occurring\n* \\return True if playback is occurring" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "IsPlaying", nullptr, nullptr, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying_Statics::PropPointers), sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying_Statics::SessionPlayback_Subsystem_Core_eventIsPlaying_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying_Statics::Function_MetaDataParams), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying_Statics::SessionPlayback_Subsystem_Core_eventIsPlaying_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics
	{
		struct SessionPlayback_Subsystem_Core_eventLoadPlayback_Parms
		{
			FString fullPathToFile;
			float playbackDuration;
			FString error;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fullPathToFile_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_fullPathToFile;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_playbackDuration;
		static const UECodeGen_Private::FStrPropertyParams NewProp_error;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::NewProp_fullPathToFile_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::NewProp_fullPathToFile = { "fullPathToFile", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SessionPlayback_Subsystem_Core_eventLoadPlayback_Parms, fullPathToFile), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::NewProp_fullPathToFile_MetaData), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::NewProp_fullPathToFile_MetaData) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::NewProp_playbackDuration = { "playbackDuration", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SessionPlayback_Subsystem_Core_eventLoadPlayback_Parms, playbackDuration), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::NewProp_error = { "error", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SessionPlayback_Subsystem_Core_eventLoadPlayback_Parms, error), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SessionPlayback_Subsystem_Core_eventLoadPlayback_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SessionPlayback_Subsystem_Core_eventLoadPlayback_Parms), &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::NewProp_fullPathToFile,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::NewProp_playbackDuration,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::NewProp_error,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Loads playback file from disk\n\x09* \\param fullPathToFile Full path to playback file on disk\n\x09* \\param playbackDuration Populated with duration of playback in seconds\n\x09* \\param error Populated with error message when load fails\n\x09* \\return True on successful load\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Loads playback file from disk\n* \\param fullPathToFile Full path to playback file on disk\n* \\param playbackDuration Populated with duration of playback in seconds\n* \\param error Populated with error message when load fails\n* \\return True on successful load" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "LoadPlayback", nullptr, nullptr, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::PropPointers), sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::SessionPlayback_Subsystem_Core_eventLoadPlayback_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::Function_MetaDataParams), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::SessionPlayback_Subsystem_Core_eventLoadPlayback_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics
	{
		struct SessionPlayback_Subsystem_Core_eventSetImplementation_Parms
		{
			FString implementationID;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_implementationID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_implementationID;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::NewProp_implementationID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::NewProp_implementationID = { "implementationID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SessionPlayback_Subsystem_Core_eventSetImplementation_Parms, implementationID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::NewProp_implementationID_MetaData), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::NewProp_implementationID_MetaData) };
	void Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SessionPlayback_Subsystem_Core_eventSetImplementation_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SessionPlayback_Subsystem_Core_eventSetImplementation_Parms), &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::NewProp_implementationID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Sets the implementation to use\n\x09* \\param implementationID ID of implementation; should be same ID used when registering the implementation\n\x09* \\return True if successfully set implementation\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Sets the implementation to use\n* \\param implementationID ID of implementation; should be same ID used when registering the implementation\n* \\return True if successfully set implementation" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "SetImplementation", nullptr, nullptr, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::PropPointers), sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::SessionPlayback_Subsystem_Core_eventSetImplementation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::Function_MetaDataParams), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::SessionPlayback_Subsystem_Core_eventSetImplementation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetPlaybackRate_Statics
	{
		struct SessionPlayback_Subsystem_Core_eventSetPlaybackRate_Parms
		{
			float playbackRate;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_playbackRate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetPlaybackRate_Statics::NewProp_playbackRate = { "playbackRate", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SessionPlayback_Subsystem_Core_eventSetPlaybackRate_Parms, playbackRate), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetPlaybackRate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetPlaybackRate_Statics::NewProp_playbackRate,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetPlaybackRate_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Sets the playback rate; ex: 2 means play at 2x speed, 0 means pause\n\x09*\x09\x09 Negative playback rates not allowed in most implementations\n\x09* \\param playbackRate Rate to set\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Sets the playback rate; ex: 2 means play at 2x speed, 0 means pause\n*                Negative playback rates not allowed in most implementations\n* \\param playbackRate Rate to set" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetPlaybackRate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "SetPlaybackRate", nullptr, nullptr, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetPlaybackRate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetPlaybackRate_Statics::PropPointers), sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetPlaybackRate_Statics::SessionPlayback_Subsystem_Core_eventSetPlaybackRate_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetPlaybackRate_Statics::Function_MetaDataParams), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetPlaybackRate_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetPlaybackRate_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetPlaybackRate_Statics::SessionPlayback_Subsystem_Core_eventSetPlaybackRate_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetPlaybackRate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetPlaybackRate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetSecondsPassed_Statics
	{
		struct SessionPlayback_Subsystem_Core_eventSetSecondsPassed_Parms
		{
			float secondsPassed;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_secondsPassed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetSecondsPassed_Statics::NewProp_secondsPassed = { "secondsPassed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SessionPlayback_Subsystem_Core_eventSetSecondsPassed_Parms, secondsPassed), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetSecondsPassed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetSecondsPassed_Statics::NewProp_secondsPassed,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetSecondsPassed_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Sets the seconds passed in the session playback\n\x09* \\param secondsPassed Number of seconds passed\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Sets the seconds passed in the session playback\n* \\param secondsPassed Number of seconds passed" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetSecondsPassed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "SetSecondsPassed", nullptr, nullptr, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetSecondsPassed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetSecondsPassed_Statics::PropPointers), sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetSecondsPassed_Statics::SessionPlayback_Subsystem_Core_eventSetSecondsPassed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetSecondsPassed_Statics::Function_MetaDataParams), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetSecondsPassed_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetSecondsPassed_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetSecondsPassed_Statics::SessionPlayback_Subsystem_Core_eventSetSecondsPassed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetSecondsPassed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetSecondsPassed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics
	{
		struct SessionPlayback_Subsystem_Core_eventStartRecord_Parms
		{
			FString fullPathToFile;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fullPathToFile_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_fullPathToFile;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::NewProp_fullPathToFile_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::NewProp_fullPathToFile = { "fullPathToFile", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SessionPlayback_Subsystem_Core_eventStartRecord_Parms, fullPathToFile), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::NewProp_fullPathToFile_MetaData), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::NewProp_fullPathToFile_MetaData) };
	void Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SessionPlayback_Subsystem_Core_eventStartRecord_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SessionPlayback_Subsystem_Core_eventStartRecord_Parms), &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::NewProp_fullPathToFile,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Starts recording playback\n\x09* \\param fullPathToFile Full path to local file to save playback\n\x09* \\return True if successfully started recording playback\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Starts recording playback\n* \\param fullPathToFile Full path to local file to save playback\n* \\return True if successfully started recording playback" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "StartRecord", nullptr, nullptr, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::PropPointers), sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::SessionPlayback_Subsystem_Core_eventStartRecord_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::Function_MetaDataParams), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::SessionPlayback_Subsystem_Core_eventStartRecord_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StopRecord_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StopRecord_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Stops recording playback\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Stops recording playback" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StopRecord_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "StopRecord", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StopRecord_Statics::Function_MetaDataParams), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StopRecord_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StopRecord()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StopRecord_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics
	{
		struct SessionPlayback_Subsystem_Core_eventTest_LoadSessionPlayback_Parms
		{
			FString fullPathToFile;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fullPathToFile_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_fullPathToFile;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics::NewProp_fullPathToFile_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics::NewProp_fullPathToFile = { "fullPathToFile", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SessionPlayback_Subsystem_Core_eventTest_LoadSessionPlayback_Parms, fullPathToFile), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics::NewProp_fullPathToFile_MetaData), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics::NewProp_fullPathToFile_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics::NewProp_fullPathToFile,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "Test_LoadSessionPlayback", nullptr, nullptr, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics::PropPointers), sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics::SessionPlayback_Subsystem_Core_eventTest_LoadSessionPlayback_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040601, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics::Function_MetaDataParams), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics::SessionPlayback_Subsystem_Core_eventTest_LoadSessionPlayback_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics
	{
		struct SessionPlayback_Subsystem_Core_eventTest_RecordSessionPlayback_Parms
		{
			FString fullPathToFile;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fullPathToFile_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_fullPathToFile;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics::NewProp_fullPathToFile_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics::NewProp_fullPathToFile = { "fullPathToFile", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SessionPlayback_Subsystem_Core_eventTest_RecordSessionPlayback_Parms, fullPathToFile), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics::NewProp_fullPathToFile_MetaData), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics::NewProp_fullPathToFile_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics::NewProp_fullPathToFile,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "Test_RecordSessionPlayback", nullptr, nullptr, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics::PropPointers), sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics::SessionPlayback_Subsystem_Core_eventTest_RecordSessionPlayback_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040601, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics::Function_MetaDataParams), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics::SessionPlayback_Subsystem_Core_eventTest_RecordSessionPlayback_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_StopRecordSessionPlayback_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_StopRecordSessionPlayback_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_StopRecordSessionPlayback_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "Test_StopRecordSessionPlayback", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040601, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_StopRecordSessionPlayback_Statics::Function_MetaDataParams), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_StopRecordSessionPlayback_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_StopRecordSessionPlayback()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_StopRecordSessionPlayback_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USessionPlayback_Subsystem_Core_UnloadPlayback_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USessionPlayback_Subsystem_Core_UnloadPlayback_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Unload and cleanup playback; call when user is finished with playback session\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Unload and cleanup playback; call when user is finished with playback session" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USessionPlayback_Subsystem_Core_UnloadPlayback_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USessionPlayback_Subsystem_Core, nullptr, "UnloadPlayback", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USessionPlayback_Subsystem_Core_UnloadPlayback_Statics::Function_MetaDataParams), Z_Construct_UFunction_USessionPlayback_Subsystem_Core_UnloadPlayback_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_USessionPlayback_Subsystem_Core_UnloadPlayback()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USessionPlayback_Subsystem_Core_UnloadPlayback_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USessionPlayback_Subsystem_Core);
	UClass* Z_Construct_UClass_USessionPlayback_Subsystem_Core_NoRegister()
	{
		return USessionPlayback_Subsystem_Core::StaticClass();
	}
	struct Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnPlaybackRateUpdated_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPlaybackRateUpdated;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnPlaybackStatusUpdated_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPlaybackStatusUpdated;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Implementation_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Implementation;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Implementations_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Implementations_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Implementations_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_Implementations;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_SessionPlayback,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetImplementation, "GetImplementation" }, // 479179608
		{ &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackDuration, "GetPlaybackDuration" }, // 2746244416
		{ &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackRate, "GetPlaybackRate" }, // 1081492303
		{ &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetPlaybackStatus, "GetPlaybackStatus" }, // 1562417229
		{ &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_GetSecondsPassed, "GetSecondsPassed" }, // 3872953859
		{ &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_IsPlaying, "IsPlaying" }, // 2604884700
		{ &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_LoadPlayback, "LoadPlayback" }, // 1224399122
		{ &Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature, "PlaybackRateUpdated__DelegateSignature" }, // 2769354070
		{ &Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature, "PlaybackStatusUpdated__DelegateSignature" }, // 100643512
		{ &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetImplementation, "SetImplementation" }, // 2913321657
		{ &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetPlaybackRate, "SetPlaybackRate" }, // 525351435
		{ &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_SetSecondsPassed, "SetSecondsPassed" }, // 1384980201
		{ &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StartRecord, "StartRecord" }, // 2231591594
		{ &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_StopRecord, "StopRecord" }, // 1857355223
		{ &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_LoadSessionPlayback, "Test_LoadSessionPlayback" }, // 2763544716
		{ &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_RecordSessionPlayback, "Test_RecordSessionPlayback" }, // 2951653630
		{ &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_Test_StopRecordSessionPlayback, "Test_StopRecordSessionPlayback" }, // 1026829722
		{ &Z_Construct_UFunction_USessionPlayback_Subsystem_Core_UnloadPlayback, "UnloadPlayback" }, // 2219892343
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_OnPlaybackRateUpdated_MetaData[] = {
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_OnPlaybackRateUpdated = { "OnPlaybackRateUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USessionPlayback_Subsystem_Core, OnPlaybackRateUpdated), Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackRateUpdated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_OnPlaybackRateUpdated_MetaData), Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_OnPlaybackRateUpdated_MetaData) }; // 2769354070
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_OnPlaybackStatusUpdated_MetaData[] = {
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_OnPlaybackStatusUpdated = { "OnPlaybackStatusUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USessionPlayback_Subsystem_Core, OnPlaybackStatusUpdated), Z_Construct_UDelegateFunction_USessionPlayback_Subsystem_Core_PlaybackStatusUpdated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_OnPlaybackStatusUpdated_MetaData), Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_OnPlaybackStatusUpdated_MetaData) }; // 100643512
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_Implementation_MetaData[] = {
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_Implementation = { "Implementation", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USessionPlayback_Subsystem_Core, Implementation), Z_Construct_UClass_USessionPlayback_Impl_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_Implementation_MetaData), Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_Implementation_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_Implementations_ValueProp = { "Implementations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_USessionPlayback_Impl_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_Implementations_Key_KeyProp = { "Implementations_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_Implementations_MetaData[] = {
		{ "ModuleRelativePath", "Subsystems/Public/SessionPlayback_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_Implementations = { "Implementations", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USessionPlayback_Subsystem_Core, Implementations), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_Implementations_MetaData), Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_Implementations_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_OnPlaybackRateUpdated,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_OnPlaybackStatusUpdated,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_Implementation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_Implementations_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_Implementations_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::NewProp_Implementations,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USessionPlayback_Subsystem_Core>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::ClassParams = {
		&USessionPlayback_Subsystem_Core::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::Class_MetaDataParams), Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_USessionPlayback_Subsystem_Core()
	{
		if (!Z_Registration_Info_UClass_USessionPlayback_Subsystem_Core.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USessionPlayback_Subsystem_Core.OuterSingleton, Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USessionPlayback_Subsystem_Core.OuterSingleton;
	}
	template<> VH_SESSIONPLAYBACK_API UClass* StaticClass<USessionPlayback_Subsystem_Core>()
	{
		return USessionPlayback_Subsystem_Core::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USessionPlayback_Subsystem_Core);
	USessionPlayback_Subsystem_Core::~USessionPlayback_Subsystem_Core() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_Statics::EnumInfo[] = {
		{ EPlaybackStatus_StaticEnum, TEXT("EPlaybackStatus"), &Z_Registration_Info_UEnum_EPlaybackStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3817341635U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USessionPlayback_Subsystem_Core, USessionPlayback_Subsystem_Core::StaticClass, TEXT("USessionPlayback_Subsystem_Core"), &Z_Registration_Info_UClass_USessionPlayback_Subsystem_Core, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USessionPlayback_Subsystem_Core), 1756878461U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_4202888365(TEXT("/Script/VH_SessionPlayback"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
