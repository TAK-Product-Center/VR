// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Core/Public/Developer_TaskInfo.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_TaskInfo() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_TaskInfo();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_TaskInfo_NoRegister();
	VH_DEVELOPER_API UFunction* Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature();
	VH_DEVELOPER_API UFunction* Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature_Statics
	{
		struct Developer_TaskInfo_eventTaskInfoChanged_Parms
		{
			UDeveloper_TaskInfo* taskInfo;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_taskInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature_Statics::NewProp_taskInfo = { "taskInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskInfo_eventTaskInfoChanged_Parms, taskInfo), Z_Construct_UClass_UDeveloper_TaskInfo_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature_Statics::NewProp_taskInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskInfo.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskInfo, nullptr, "TaskInfoChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature_Statics::Developer_TaskInfo_eventTaskInfoChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature_Statics::Developer_TaskInfo_eventTaskInfoChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UDeveloper_TaskInfo::FTaskInfoChanged_DelegateWrapper(const FMulticastScriptDelegate& TaskInfoChanged, UDeveloper_TaskInfo* taskInfo)
{
	struct Developer_TaskInfo_eventTaskInfoChanged_Parms
	{
		UDeveloper_TaskInfo* taskInfo;
	};
	Developer_TaskInfo_eventTaskInfoChanged_Parms Parms;
	Parms.taskInfo=taskInfo;
	TaskInfoChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics
	{
		struct Developer_TaskInfo_eventTaskInfoIDChanged_Parms
		{
			UDeveloper_TaskInfo* taskInfo;
			FString oldID;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_taskInfo;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_oldID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_oldID;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::NewProp_taskInfo = { "taskInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskInfo_eventTaskInfoIDChanged_Parms, taskInfo), Z_Construct_UClass_UDeveloper_TaskInfo_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::NewProp_oldID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::NewProp_oldID = { "oldID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskInfo_eventTaskInfoIDChanged_Parms, oldID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::NewProp_oldID_MetaData), Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::NewProp_oldID_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::NewProp_taskInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::NewProp_oldID,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskInfo.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskInfo, nullptr, "TaskInfoIDChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::Developer_TaskInfo_eventTaskInfoIDChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::Developer_TaskInfo_eventTaskInfoIDChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UDeveloper_TaskInfo::FTaskInfoIDChanged_DelegateWrapper(const FMulticastScriptDelegate& TaskInfoIDChanged, UDeveloper_TaskInfo* taskInfo, const FString& oldID)
{
	struct Developer_TaskInfo_eventTaskInfoIDChanged_Parms
	{
		UDeveloper_TaskInfo* taskInfo;
		FString oldID;
	};
	Developer_TaskInfo_eventTaskInfoIDChanged_Parms Parms;
	Parms.taskInfo=taskInfo;
	Parms.oldID=oldID;
	TaskInfoIDChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UDeveloper_TaskInfo::execGetPercentComplete)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetPercentComplete();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskInfo::execGetDescription)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetDescription();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskInfo::execGetID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetID();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskInfo::execSetPercentComplete)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_percentComplete);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPercentComplete(Z_Param_percentComplete);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskInfo::execSetDescription)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_description);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetDescription(Z_Param_description);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskInfo::execSetID)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_id);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetID(Z_Param_id);
		P_NATIVE_END;
	}
	void UDeveloper_TaskInfo::StaticRegisterNativesUDeveloper_TaskInfo()
	{
		UClass* Class = UDeveloper_TaskInfo::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetDescription", &UDeveloper_TaskInfo::execGetDescription },
			{ "GetID", &UDeveloper_TaskInfo::execGetID },
			{ "GetPercentComplete", &UDeveloper_TaskInfo::execGetPercentComplete },
			{ "SetDescription", &UDeveloper_TaskInfo::execSetDescription },
			{ "SetID", &UDeveloper_TaskInfo::execSetID },
			{ "SetPercentComplete", &UDeveloper_TaskInfo::execSetPercentComplete },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDeveloper_TaskInfo_GetDescription_Statics
	{
		struct Developer_TaskInfo_eventGetDescription_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_TaskInfo_GetDescription_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskInfo_eventGetDescription_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskInfo_GetDescription_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskInfo_GetDescription_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskInfo_GetDescription_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskInfo.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskInfo_GetDescription_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskInfo, nullptr, "GetDescription", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskInfo_GetDescription_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_GetDescription_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskInfo_GetDescription_Statics::Developer_TaskInfo_eventGetDescription_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_GetDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskInfo_GetDescription_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_GetDescription_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskInfo_GetDescription_Statics::Developer_TaskInfo_eventGetDescription_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskInfo_GetDescription()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskInfo_GetDescription_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskInfo_GetID_Statics
	{
		struct Developer_TaskInfo_eventGetID_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_TaskInfo_GetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskInfo_eventGetID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskInfo_GetID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskInfo_GetID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskInfo_GetID_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskInfo.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskInfo_GetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskInfo, nullptr, "GetID", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskInfo_GetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_GetID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskInfo_GetID_Statics::Developer_TaskInfo_eventGetID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_GetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskInfo_GetID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_GetID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskInfo_GetID_Statics::Developer_TaskInfo_eventGetID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskInfo_GetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskInfo_GetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskInfo_GetPercentComplete_Statics
	{
		struct Developer_TaskInfo_eventGetPercentComplete_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDeveloper_TaskInfo_GetPercentComplete_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskInfo_eventGetPercentComplete_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskInfo_GetPercentComplete_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskInfo_GetPercentComplete_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskInfo_GetPercentComplete_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskInfo.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskInfo_GetPercentComplete_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskInfo, nullptr, "GetPercentComplete", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskInfo_GetPercentComplete_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_GetPercentComplete_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskInfo_GetPercentComplete_Statics::Developer_TaskInfo_eventGetPercentComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_GetPercentComplete_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskInfo_GetPercentComplete_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_GetPercentComplete_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskInfo_GetPercentComplete_Statics::Developer_TaskInfo_eventGetPercentComplete_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskInfo_GetPercentComplete()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskInfo_GetPercentComplete_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics
	{
		struct Developer_TaskInfo_eventSetDescription_Parms
		{
			FString description;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_description_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_description;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics::NewProp_description_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics::NewProp_description = { "description", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskInfo_eventSetDescription_Parms, description), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics::NewProp_description_MetaData), Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics::NewProp_description_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics::NewProp_description,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskInfo.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskInfo, nullptr, "SetDescription", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics::Developer_TaskInfo_eventSetDescription_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics::Developer_TaskInfo_eventSetDescription_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics
	{
		struct Developer_TaskInfo_eventSetID_Parms
		{
			FString id;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_id_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_id;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics::NewProp_id_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics::NewProp_id = { "id", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskInfo_eventSetID_Parms, id), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics::NewProp_id_MetaData), Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics::NewProp_id_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics::NewProp_id,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskInfo.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskInfo, nullptr, "SetID", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics::Developer_TaskInfo_eventSetID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics::Developer_TaskInfo_eventSetID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskInfo_SetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskInfo_SetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskInfo_SetPercentComplete_Statics
	{
		struct Developer_TaskInfo_eventSetPercentComplete_Parms
		{
			float percentComplete;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_percentComplete;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDeveloper_TaskInfo_SetPercentComplete_Statics::NewProp_percentComplete = { "percentComplete", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskInfo_eventSetPercentComplete_Parms, percentComplete), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskInfo_SetPercentComplete_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskInfo_SetPercentComplete_Statics::NewProp_percentComplete,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskInfo_SetPercentComplete_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskInfo.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskInfo_SetPercentComplete_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskInfo, nullptr, "SetPercentComplete", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskInfo_SetPercentComplete_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_SetPercentComplete_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskInfo_SetPercentComplete_Statics::Developer_TaskInfo_eventSetPercentComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_SetPercentComplete_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskInfo_SetPercentComplete_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskInfo_SetPercentComplete_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskInfo_SetPercentComplete_Statics::Developer_TaskInfo_eventSetPercentComplete_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskInfo_SetPercentComplete()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskInfo_SetPercentComplete_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_TaskInfo);
	UClass* Z_Construct_UClass_UDeveloper_TaskInfo_NoRegister()
	{
		return UDeveloper_TaskInfo::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_TaskInfo_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnTaskInfoChanged_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTaskInfoChanged;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnTaskInfoIDChanged_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTaskInfoIDChanged;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_TaskInfo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskInfo_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDeveloper_TaskInfo_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDeveloper_TaskInfo_GetDescription, "GetDescription" }, // 1950292236
		{ &Z_Construct_UFunction_UDeveloper_TaskInfo_GetID, "GetID" }, // 2566464451
		{ &Z_Construct_UFunction_UDeveloper_TaskInfo_GetPercentComplete, "GetPercentComplete" }, // 3957542235
		{ &Z_Construct_UFunction_UDeveloper_TaskInfo_SetDescription, "SetDescription" }, // 170728633
		{ &Z_Construct_UFunction_UDeveloper_TaskInfo_SetID, "SetID" }, // 3054691313
		{ &Z_Construct_UFunction_UDeveloper_TaskInfo_SetPercentComplete, "SetPercentComplete" }, // 3064691178
		{ &Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature, "TaskInfoChanged__DelegateSignature" }, // 3149784405
		{ &Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature, "TaskInfoIDChanged__DelegateSignature" }, // 3652743938
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskInfo_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_TaskInfo_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Core/Public/Developer_TaskInfo.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Public/Developer_TaskInfo.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_TaskInfo_Statics::NewProp_OnTaskInfoChanged_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* called if Description or PercentComplete changes */" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_TaskInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "called if Description or PercentComplete changes" },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDeveloper_TaskInfo_Statics::NewProp_OnTaskInfoChanged = { "OnTaskInfoChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_TaskInfo, OnTaskInfoChanged), Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskInfo_Statics::NewProp_OnTaskInfoChanged_MetaData), Z_Construct_UClass_UDeveloper_TaskInfo_Statics::NewProp_OnTaskInfoChanged_MetaData) }; // 3149784405
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_TaskInfo_Statics::NewProp_OnTaskInfoIDChanged_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* called if ID changes */" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_TaskInfo.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "called if ID changes" },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDeveloper_TaskInfo_Statics::NewProp_OnTaskInfoIDChanged = { "OnTaskInfoIDChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_TaskInfo, OnTaskInfoIDChanged), Z_Construct_UDelegateFunction_UDeveloper_TaskInfo_TaskInfoIDChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskInfo_Statics::NewProp_OnTaskInfoIDChanged_MetaData), Z_Construct_UClass_UDeveloper_TaskInfo_Statics::NewProp_OnTaskInfoIDChanged_MetaData) }; // 3652743938
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDeveloper_TaskInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_TaskInfo_Statics::NewProp_OnTaskInfoChanged,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_TaskInfo_Statics::NewProp_OnTaskInfoIDChanged,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_TaskInfo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_TaskInfo>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_TaskInfo_Statics::ClassParams = {
		&UDeveloper_TaskInfo::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDeveloper_TaskInfo_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskInfo_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskInfo_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_TaskInfo_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskInfo_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDeveloper_TaskInfo()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_TaskInfo.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_TaskInfo.OuterSingleton, Z_Construct_UClass_UDeveloper_TaskInfo_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_TaskInfo.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_TaskInfo>()
	{
		return UDeveloper_TaskInfo::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_TaskInfo);
	UDeveloper_TaskInfo::~UDeveloper_TaskInfo() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_TaskInfo, UDeveloper_TaskInfo::StaticClass, TEXT("UDeveloper_TaskInfo"), &Z_Registration_Info_UClass_UDeveloper_TaskInfo, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_TaskInfo), 125860994U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_625012305(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskInfo_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
