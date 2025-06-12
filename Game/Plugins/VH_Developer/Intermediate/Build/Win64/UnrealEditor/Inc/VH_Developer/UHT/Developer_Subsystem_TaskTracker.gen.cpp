// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Subsystems/Public/Developer_Subsystem_TaskTracker.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_Subsystem_TaskTracker() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_NoRegister();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_TaskInfo_NoRegister();
	VH_DEVELOPER_API UFunction* Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_ActiveNumChanged__DelegateSignature();
	VH_DEVELOPER_API UFunction* Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_HistoryNumChanged__DelegateSignature();
	VH_DEVELOPER_API UFunction* Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_ActiveNumChanged__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_ActiveNumChanged__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_ActiveNumChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker, nullptr, "ActiveNumChanged__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_ActiveNumChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_ActiveNumChanged__DelegateSignature_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_ActiveNumChanged__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_ActiveNumChanged__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UDeveloper_Subsystem_TaskTracker::FActiveNumChanged_DelegateWrapper(const FMulticastScriptDelegate& ActiveNumChanged)
{
	ActiveNumChanged.ProcessMulticastDelegate<UObject>(NULL);
}
	struct Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_HistoryNumChanged__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_HistoryNumChanged__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_HistoryNumChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker, nullptr, "HistoryNumChanged__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_HistoryNumChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_HistoryNumChanged__DelegateSignature_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_HistoryNumChanged__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_HistoryNumChanged__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UDeveloper_Subsystem_TaskTracker::FHistoryNumChanged_DelegateWrapper(const FMulticastScriptDelegate& HistoryNumChanged)
{
	HistoryNumChanged.ProcessMulticastDelegate<UObject>(NULL);
}
	struct Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature_Statics
	{
		struct Developer_Subsystem_TaskTracker_eventTaskInfoChanged_Parms
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature_Statics::NewProp_taskInfo = { "taskInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventTaskInfoChanged_Parms, taskInfo), Z_Construct_UClass_UDeveloper_TaskInfo_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature_Statics::NewProp_taskInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker, nullptr, "TaskInfoChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature_Statics::Developer_Subsystem_TaskTracker_eventTaskInfoChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature_Statics::Developer_Subsystem_TaskTracker_eventTaskInfoChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UDeveloper_Subsystem_TaskTracker::FTaskInfoChanged_DelegateWrapper(const FMulticastScriptDelegate& TaskInfoChanged, UDeveloper_TaskInfo* taskInfo)
{
	struct Developer_Subsystem_TaskTracker_eventTaskInfoChanged_Parms
	{
		UDeveloper_TaskInfo* taskInfo;
	};
	Developer_Subsystem_TaskTracker_eventTaskInfoChanged_Parms Parms;
	Parms.taskInfo=taskInfo;
	TaskInfoChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UDeveloper_Subsystem_TaskTracker::execHandleTaskInfoChanged)
	{
		P_GET_OBJECT(UDeveloper_TaskInfo,Z_Param_taskInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleTaskInfoChanged(Z_Param_taskInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_TaskTracker::execRemoveHistoryTask)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_id);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveHistoryTask(Z_Param_id);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_TaskTracker::execAddHistoryTask)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_id);
		P_GET_PROPERTY(FStrProperty,Z_Param_description);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddHistoryTask(Z_Param_id,Z_Param_description);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_TaskTracker::execSetDescription)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_taskInfoID);
		P_GET_PROPERTY(FStrProperty,Z_Param_description);
		P_GET_UBOOL(Z_Param_bAdd);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetDescription(Z_Param_taskInfoID,Z_Param_description,Z_Param_bAdd);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_TaskTracker::execSetPercentComplete)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_taskInfoID);
		P_GET_PROPERTY(FFloatProperty,Z_Param_percentComplete);
		P_GET_UBOOL(Z_Param_bAdd);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetPercentComplete(Z_Param_taskInfoID,Z_Param_percentComplete,Z_Param_bAdd);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_TaskTracker::execRemoveActiveTask)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_taskInfoID);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveActiveTask(Z_Param_taskInfoID);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_TaskTracker::execAddActiveTask)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_id);
		P_GET_PROPERTY(FStrProperty,Z_Param_description);
		P_GET_PROPERTY(FFloatProperty,Z_Param_percentComplete);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddActiveTask(Z_Param_id,Z_Param_description,Z_Param_percentComplete);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_TaskTracker::execGetActiveIDs)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TSet<FString>*)Z_Param__Result=P_THIS->GetActiveIDs();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_TaskTracker::execGetHistoryIDs)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TSet<FString>*)Z_Param__Result=P_THIS->GetHistoryIDs();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_TaskTracker::execGetHistoryTasks)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TMap<FString,FString>*)Z_Param__Result=P_THIS->GetHistoryTasks();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_TaskTracker::execGetActiveTasks)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TMap<FString,UDeveloper_TaskInfo*>*)Z_Param__Result=P_THIS->GetActiveTasks();
		P_NATIVE_END;
	}
	void UDeveloper_Subsystem_TaskTracker::StaticRegisterNativesUDeveloper_Subsystem_TaskTracker()
	{
		UClass* Class = UDeveloper_Subsystem_TaskTracker::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddActiveTask", &UDeveloper_Subsystem_TaskTracker::execAddActiveTask },
			{ "AddHistoryTask", &UDeveloper_Subsystem_TaskTracker::execAddHistoryTask },
			{ "GetActiveIDs", &UDeveloper_Subsystem_TaskTracker::execGetActiveIDs },
			{ "GetActiveTasks", &UDeveloper_Subsystem_TaskTracker::execGetActiveTasks },
			{ "GetHistoryIDs", &UDeveloper_Subsystem_TaskTracker::execGetHistoryIDs },
			{ "GetHistoryTasks", &UDeveloper_Subsystem_TaskTracker::execGetHistoryTasks },
			{ "HandleTaskInfoChanged", &UDeveloper_Subsystem_TaskTracker::execHandleTaskInfoChanged },
			{ "RemoveActiveTask", &UDeveloper_Subsystem_TaskTracker::execRemoveActiveTask },
			{ "RemoveHistoryTask", &UDeveloper_Subsystem_TaskTracker::execRemoveHistoryTask },
			{ "SetDescription", &UDeveloper_Subsystem_TaskTracker::execSetDescription },
			{ "SetPercentComplete", &UDeveloper_Subsystem_TaskTracker::execSetPercentComplete },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics
	{
		struct Developer_Subsystem_TaskTracker_eventAddActiveTask_Parms
		{
			FString id;
			FString description;
			float percentComplete;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_id_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_id;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_description_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_description;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_percentComplete;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::NewProp_id_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::NewProp_id = { "id", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventAddActiveTask_Parms, id), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::NewProp_id_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::NewProp_id_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::NewProp_description_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::NewProp_description = { "description", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventAddActiveTask_Parms, description), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::NewProp_description_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::NewProp_description_MetaData) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::NewProp_percentComplete = { "percentComplete", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventAddActiveTask_Parms, percentComplete), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::NewProp_id,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::NewProp_description,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::NewProp_percentComplete,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker, nullptr, "AddActiveTask", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::Developer_Subsystem_TaskTracker_eventAddActiveTask_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::Developer_Subsystem_TaskTracker_eventAddActiveTask_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics
	{
		struct Developer_Subsystem_TaskTracker_eventAddHistoryTask_Parms
		{
			FString id;
			FString description;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_id_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_id;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::NewProp_id_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::NewProp_id = { "id", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventAddHistoryTask_Parms, id), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::NewProp_id_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::NewProp_id_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::NewProp_description_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::NewProp_description = { "description", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventAddHistoryTask_Parms, description), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::NewProp_description_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::NewProp_description_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::NewProp_id,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::NewProp_description,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker, nullptr, "AddHistoryTask", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::Developer_Subsystem_TaskTracker_eventAddHistoryTask_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::Developer_Subsystem_TaskTracker_eventAddHistoryTask_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs_Statics
	{
		struct Developer_Subsystem_TaskTracker_eventGetActiveIDs_Parms
		{
			TSet<FString> ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_ElementProp;
		static const UECodeGen_Private::FSetPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs_Statics::NewProp_ReturnValue_ElementProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventGetActiveIDs_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs_Statics::NewProp_ReturnValue_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker, nullptr, "GetActiveIDs", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs_Statics::Developer_Subsystem_TaskTracker_eventGetActiveIDs_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x44020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs_Statics::Developer_Subsystem_TaskTracker_eventGetActiveIDs_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics
	{
		struct Developer_Subsystem_TaskTracker_eventGetActiveTasks_Parms
		{
			TMap<FString,UDeveloper_TaskInfo*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UDeveloper_TaskInfo_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventGetActiveTasks_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::NewProp_ReturnValue_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::NewProp_ReturnValue_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker, nullptr, "GetActiveTasks", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::Developer_Subsystem_TaskTracker_eventGetActiveTasks_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::Developer_Subsystem_TaskTracker_eventGetActiveTasks_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs_Statics
	{
		struct Developer_Subsystem_TaskTracker_eventGetHistoryIDs_Parms
		{
			TSet<FString> ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_ElementProp;
		static const UECodeGen_Private::FSetPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs_Statics::NewProp_ReturnValue_ElementProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventGetHistoryIDs_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs_Statics::NewProp_ReturnValue_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker, nullptr, "GetHistoryIDs", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs_Statics::Developer_Subsystem_TaskTracker_eventGetHistoryIDs_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x44020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs_Statics::Developer_Subsystem_TaskTracker_eventGetHistoryIDs_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics
	{
		struct Developer_Subsystem_TaskTracker_eventGetHistoryTasks_Parms
		{
			TMap<FString,FString> ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventGetHistoryTasks_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::NewProp_ReturnValue_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::NewProp_ReturnValue_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker, nullptr, "GetHistoryTasks", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::Developer_Subsystem_TaskTracker_eventGetHistoryTasks_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::Developer_Subsystem_TaskTracker_eventGetHistoryTasks_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_HandleTaskInfoChanged_Statics
	{
		struct Developer_Subsystem_TaskTracker_eventHandleTaskInfoChanged_Parms
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
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_HandleTaskInfoChanged_Statics::NewProp_taskInfo = { "taskInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventHandleTaskInfoChanged_Parms, taskInfo), Z_Construct_UClass_UDeveloper_TaskInfo_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_HandleTaskInfoChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_HandleTaskInfoChanged_Statics::NewProp_taskInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_HandleTaskInfoChanged_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_HandleTaskInfoChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker, nullptr, "HandleTaskInfoChanged", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_HandleTaskInfoChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_HandleTaskInfoChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_HandleTaskInfoChanged_Statics::Developer_Subsystem_TaskTracker_eventHandleTaskInfoChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_HandleTaskInfoChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_HandleTaskInfoChanged_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_HandleTaskInfoChanged_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_HandleTaskInfoChanged_Statics::Developer_Subsystem_TaskTracker_eventHandleTaskInfoChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_HandleTaskInfoChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_HandleTaskInfoChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics
	{
		struct Developer_Subsystem_TaskTracker_eventRemoveActiveTask_Parms
		{
			FString taskInfoID;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_taskInfoID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_taskInfoID;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics::NewProp_taskInfoID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics::NewProp_taskInfoID = { "taskInfoID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventRemoveActiveTask_Parms, taskInfoID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics::NewProp_taskInfoID_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics::NewProp_taskInfoID_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics::NewProp_taskInfoID,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker, nullptr, "RemoveActiveTask", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics::Developer_Subsystem_TaskTracker_eventRemoveActiveTask_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics::Developer_Subsystem_TaskTracker_eventRemoveActiveTask_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics
	{
		struct Developer_Subsystem_TaskTracker_eventRemoveHistoryTask_Parms
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics::NewProp_id_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics::NewProp_id = { "id", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventRemoveHistoryTask_Parms, id), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics::NewProp_id_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics::NewProp_id_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics::NewProp_id,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker, nullptr, "RemoveHistoryTask", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics::Developer_Subsystem_TaskTracker_eventRemoveHistoryTask_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics::Developer_Subsystem_TaskTracker_eventRemoveHistoryTask_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics
	{
		struct Developer_Subsystem_TaskTracker_eventSetDescription_Parms
		{
			FString taskInfoID;
			FString description;
			bool bAdd;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_taskInfoID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_taskInfoID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_description_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_description;
		static void NewProp_bAdd_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAdd;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::NewProp_taskInfoID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::NewProp_taskInfoID = { "taskInfoID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventSetDescription_Parms, taskInfoID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::NewProp_taskInfoID_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::NewProp_taskInfoID_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::NewProp_description_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::NewProp_description = { "description", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventSetDescription_Parms, description), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::NewProp_description_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::NewProp_description_MetaData) };
	void Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::NewProp_bAdd_SetBit(void* Obj)
	{
		((Developer_Subsystem_TaskTracker_eventSetDescription_Parms*)Obj)->bAdd = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::NewProp_bAdd = { "bAdd", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Subsystem_TaskTracker_eventSetDescription_Parms), &Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::NewProp_bAdd_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::NewProp_taskInfoID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::NewProp_description,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::NewProp_bAdd,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker, nullptr, "SetDescription", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::Developer_Subsystem_TaskTracker_eventSetDescription_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::Developer_Subsystem_TaskTracker_eventSetDescription_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics
	{
		struct Developer_Subsystem_TaskTracker_eventSetPercentComplete_Parms
		{
			FString taskInfoID;
			float percentComplete;
			bool bAdd;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_taskInfoID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_taskInfoID;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_percentComplete;
		static void NewProp_bAdd_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAdd;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::NewProp_taskInfoID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::NewProp_taskInfoID = { "taskInfoID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventSetPercentComplete_Parms, taskInfoID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::NewProp_taskInfoID_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::NewProp_taskInfoID_MetaData) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::NewProp_percentComplete = { "percentComplete", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_TaskTracker_eventSetPercentComplete_Parms, percentComplete), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::NewProp_bAdd_SetBit(void* Obj)
	{
		((Developer_Subsystem_TaskTracker_eventSetPercentComplete_Parms*)Obj)->bAdd = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::NewProp_bAdd = { "bAdd", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Subsystem_TaskTracker_eventSetPercentComplete_Parms), &Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::NewProp_bAdd_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::NewProp_taskInfoID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::NewProp_percentComplete,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::NewProp_bAdd,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker, nullptr, "SetPercentComplete", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::Developer_Subsystem_TaskTracker_eventSetPercentComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::Developer_Subsystem_TaskTracker_eventSetPercentComplete_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_Subsystem_TaskTracker);
	UClass* Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_NoRegister()
	{
		return UDeveloper_Subsystem_TaskTracker::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnActiveNumChanged_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnActiveNumChanged;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnHistoryNumChanged_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnHistoryNumChanged;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnTaskInfoChanged_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTaskInfoChanged;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveTasks_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ActiveTasks_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActiveTasks_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_ActiveTasks;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::FuncInfo[] = {
		{ &Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_ActiveNumChanged__DelegateSignature, "ActiveNumChanged__DelegateSignature" }, // 3593744537
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddActiveTask, "AddActiveTask" }, // 682389318
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_AddHistoryTask, "AddHistoryTask" }, // 11146198
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveIDs, "GetActiveIDs" }, // 1998989484
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetActiveTasks, "GetActiveTasks" }, // 2096737571
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryIDs, "GetHistoryIDs" }, // 1234101644
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_GetHistoryTasks, "GetHistoryTasks" }, // 775827014
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_HandleTaskInfoChanged, "HandleTaskInfoChanged" }, // 3799616389
		{ &Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_HistoryNumChanged__DelegateSignature, "HistoryNumChanged__DelegateSignature" }, // 2812110571
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveActiveTask, "RemoveActiveTask" }, // 3628776669
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_RemoveHistoryTask, "RemoveHistoryTask" }, // 1003186794
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetDescription, "SetDescription" }, // 2445347238
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_TaskTracker_SetPercentComplete, "SetPercentComplete" }, // 4263686503
		{ &Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature, "TaskInfoChanged__DelegateSignature" }, // 4015922365
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_OnActiveNumChanged_MetaData[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_OnActiveNumChanged = { "OnActiveNumChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_Subsystem_TaskTracker, OnActiveNumChanged), Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_ActiveNumChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_OnActiveNumChanged_MetaData), Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_OnActiveNumChanged_MetaData) }; // 3593744537
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_OnHistoryNumChanged_MetaData[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_OnHistoryNumChanged = { "OnHistoryNumChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_Subsystem_TaskTracker, OnHistoryNumChanged), Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_HistoryNumChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_OnHistoryNumChanged_MetaData), Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_OnHistoryNumChanged_MetaData) }; // 2812110571
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_OnTaskInfoChanged_MetaData[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_OnTaskInfoChanged = { "OnTaskInfoChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_Subsystem_TaskTracker, OnTaskInfoChanged), Z_Construct_UDelegateFunction_UDeveloper_Subsystem_TaskTracker_TaskInfoChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_OnTaskInfoChanged_MetaData), Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_OnTaskInfoChanged_MetaData) }; // 4015922365
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_ActiveTasks_ValueProp = { "ActiveTasks", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UDeveloper_TaskInfo_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_ActiveTasks_Key_KeyProp = { "ActiveTasks_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_ActiveTasks_MetaData[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_TaskTracker.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_ActiveTasks = { "ActiveTasks", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_Subsystem_TaskTracker, ActiveTasks), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_ActiveTasks_MetaData), Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_ActiveTasks_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_OnActiveNumChanged,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_OnHistoryNumChanged,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_OnTaskInfoChanged,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_ActiveTasks_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_ActiveTasks_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::NewProp_ActiveTasks,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_Subsystem_TaskTracker>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::ClassParams = {
		&UDeveloper_Subsystem_TaskTracker::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_Subsystem_TaskTracker.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_Subsystem_TaskTracker.OuterSingleton, Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_Subsystem_TaskTracker.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_Subsystem_TaskTracker>()
	{
		return UDeveloper_Subsystem_TaskTracker::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_Subsystem_TaskTracker);
	UDeveloper_Subsystem_TaskTracker::~UDeveloper_Subsystem_TaskTracker() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_Subsystem_TaskTracker, UDeveloper_Subsystem_TaskTracker::StaticClass, TEXT("UDeveloper_Subsystem_TaskTracker"), &Z_Registration_Info_UClass_UDeveloper_Subsystem_TaskTracker, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_Subsystem_TaskTracker), 913850947U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_1972154714(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_TaskTracker_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
