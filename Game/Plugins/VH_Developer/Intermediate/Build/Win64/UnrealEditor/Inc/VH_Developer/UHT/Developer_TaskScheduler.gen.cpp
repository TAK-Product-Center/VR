// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Core/Public/Developer_TaskScheduler.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_TaskScheduler() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_TaskScheduler();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_TaskScheduler_NoRegister();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UInterface_Developer_Task_NoRegister();
	VH_DEVELOPER_API UFunction* Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature();
	VH_DEVELOPER_API UFunction* Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature();
	VH_DEVELOPER_API UFunction* Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature_Statics
	{
		struct Developer_TaskScheduler_eventTaskAdded_Parms
		{
			TScriptInterface<IInterface_Developer_Task> task;
		};
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_task;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature_Statics::NewProp_task = { "task", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventTaskAdded_Parms, task), Z_Construct_UClass_UInterface_Developer_Task_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature_Statics::NewProp_task,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "TaskAdded__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature_Statics::Developer_TaskScheduler_eventTaskAdded_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature_Statics::Developer_TaskScheduler_eventTaskAdded_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UDeveloper_TaskScheduler::FTaskAdded_DelegateWrapper(const FMulticastScriptDelegate& TaskAdded, const TScriptInterface<IInterface_Developer_Task>& task)
{
	struct Developer_TaskScheduler_eventTaskAdded_Parms
	{
		TScriptInterface<IInterface_Developer_Task> task;
	};
	Developer_TaskScheduler_eventTaskAdded_Parms Parms;
	Parms.task=task;
	TaskAdded.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature_Statics
	{
		struct Developer_TaskScheduler_eventTaskStarted_Parms
		{
			TScriptInterface<IInterface_Developer_Task> task;
		};
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_task;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature_Statics::NewProp_task = { "task", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventTaskStarted_Parms, task), Z_Construct_UClass_UInterface_Developer_Task_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature_Statics::NewProp_task,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "TaskStarted__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature_Statics::Developer_TaskScheduler_eventTaskStarted_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature_Statics::Developer_TaskScheduler_eventTaskStarted_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UDeveloper_TaskScheduler::FTaskStarted_DelegateWrapper(const FMulticastScriptDelegate& TaskStarted, const TScriptInterface<IInterface_Developer_Task>& task)
{
	struct Developer_TaskScheduler_eventTaskStarted_Parms
	{
		TScriptInterface<IInterface_Developer_Task> task;
	};
	Developer_TaskScheduler_eventTaskStarted_Parms Parms;
	Parms.task=task;
	TaskStarted.ProcessMulticastDelegate<UObject>(&Parms);
}
	struct Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature_Statics
	{
		struct Developer_TaskScheduler_eventTaskFinished_Parms
		{
			TScriptInterface<IInterface_Developer_Task> task;
		};
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_task;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature_Statics::NewProp_task = { "task", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventTaskFinished_Parms, task), Z_Construct_UClass_UInterface_Developer_Task_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature_Statics::NewProp_task,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "TaskFinished__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature_Statics::Developer_TaskScheduler_eventTaskFinished_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature_Statics::Developer_TaskScheduler_eventTaskFinished_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UDeveloper_TaskScheduler::FTaskFinished_DelegateWrapper(const FMulticastScriptDelegate& TaskFinished, const TScriptInterface<IInterface_Developer_Task>& task)
{
	struct Developer_TaskScheduler_eventTaskFinished_Parms
	{
		TScriptInterface<IInterface_Developer_Task> task;
	};
	Developer_TaskScheduler_eventTaskFinished_Parms Parms;
	Parms.task=task;
	TaskFinished.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UDeveloper_TaskScheduler::execGetNumActiveTasks)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetNumActiveTasks();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskScheduler::execGetNumTasks)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetNumTasks();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskScheduler::execGetNumTasksOfType)
	{
		P_GET_OBJECT(UClass,Z_Param_objectClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetNumTasksOfType(Z_Param_objectClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskScheduler::execRemoveTask)
	{
		P_GET_TINTERFACE_REF(IInterface_Developer_Task,Z_Param_Out_task);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveTask(Z_Param_Out_task);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskScheduler::execAddTask)
	{
		P_GET_TINTERFACE_REF(IInterface_Developer_Task,Z_Param_Out_task);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->AddTask(Z_Param_Out_task);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskScheduler::execInsertTaskAt)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_index);
		P_GET_TINTERFACE_REF(IInterface_Developer_Task,Z_Param_Out_task);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InsertTaskAt(Z_Param_index,Z_Param_Out_task);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskScheduler::execHasTask)
	{
		P_GET_TINTERFACE_REF(IInterface_Developer_Task,Z_Param_Out_task);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasTask(Z_Param_Out_task);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskScheduler::execSetMaxConcurrentTasks)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_maxConcurrentTasks);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMaxConcurrentTasks(Z_Param_maxConcurrentTasks);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskScheduler::execGetMaxConcurrentTasks)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetMaxConcurrentTasks();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskScheduler::execSetSecondsBetweenChecks)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_secondsBetweenChecks);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSecondsBetweenChecks(Z_Param_secondsBetweenChecks);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskScheduler::execGetSecondsBetweenChecks)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetSecondsBetweenChecks();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskScheduler::execGetID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetID();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskScheduler::execStop)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Stop();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_TaskScheduler::execStart)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_inID);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Start(Z_Param_inID);
		P_NATIVE_END;
	}
	void UDeveloper_TaskScheduler::StaticRegisterNativesUDeveloper_TaskScheduler()
	{
		UClass* Class = UDeveloper_TaskScheduler::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddTask", &UDeveloper_TaskScheduler::execAddTask },
			{ "GetID", &UDeveloper_TaskScheduler::execGetID },
			{ "GetMaxConcurrentTasks", &UDeveloper_TaskScheduler::execGetMaxConcurrentTasks },
			{ "GetNumActiveTasks", &UDeveloper_TaskScheduler::execGetNumActiveTasks },
			{ "GetNumTasks", &UDeveloper_TaskScheduler::execGetNumTasks },
			{ "GetNumTasksOfType", &UDeveloper_TaskScheduler::execGetNumTasksOfType },
			{ "GetSecondsBetweenChecks", &UDeveloper_TaskScheduler::execGetSecondsBetweenChecks },
			{ "HasTask", &UDeveloper_TaskScheduler::execHasTask },
			{ "InsertTaskAt", &UDeveloper_TaskScheduler::execInsertTaskAt },
			{ "RemoveTask", &UDeveloper_TaskScheduler::execRemoveTask },
			{ "SetMaxConcurrentTasks", &UDeveloper_TaskScheduler::execSetMaxConcurrentTasks },
			{ "SetSecondsBetweenChecks", &UDeveloper_TaskScheduler::execSetSecondsBetweenChecks },
			{ "Start", &UDeveloper_TaskScheduler::execStart },
			{ "Stop", &UDeveloper_TaskScheduler::execStop },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics
	{
		struct Developer_TaskScheduler_eventAddTask_Parms
		{
			TScriptInterface<IInterface_Developer_Task> task;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_task_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_task;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::NewProp_task_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::NewProp_task = { "task", nullptr, (EPropertyFlags)0x0014000008000182, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventAddTask_Parms, task), Z_Construct_UClass_UInterface_Developer_Task_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::NewProp_task_MetaData), Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::NewProp_task_MetaData) };
	void Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_TaskScheduler_eventAddTask_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_TaskScheduler_eventAddTask_Parms), &Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::NewProp_task,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Adds a task to the scheduler queue. Returns FALSE if task could not be added. */" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adds a task to the scheduler queue. Returns FALSE if task could not be added." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "AddTask", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::Developer_TaskScheduler_eventAddTask_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::Developer_TaskScheduler_eventAddTask_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskScheduler_GetID_Statics
	{
		struct Developer_TaskScheduler_eventGetID_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_GetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventGetID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskScheduler_GetID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_GetID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_GetID_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskScheduler_GetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "GetID", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskScheduler_GetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetID_Statics::Developer_TaskScheduler_eventGetID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskScheduler_GetID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetID_Statics::Developer_TaskScheduler_eventGetID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskScheduler_GetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskScheduler_GetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskScheduler_GetMaxConcurrentTasks_Statics
	{
		struct Developer_TaskScheduler_eventGetMaxConcurrentTasks_Parms
		{
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_GetMaxConcurrentTasks_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventGetMaxConcurrentTasks_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskScheduler_GetMaxConcurrentTasks_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_GetMaxConcurrentTasks_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_GetMaxConcurrentTasks_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskScheduler_GetMaxConcurrentTasks_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "GetMaxConcurrentTasks", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskScheduler_GetMaxConcurrentTasks_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetMaxConcurrentTasks_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetMaxConcurrentTasks_Statics::Developer_TaskScheduler_eventGetMaxConcurrentTasks_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetMaxConcurrentTasks_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskScheduler_GetMaxConcurrentTasks_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetMaxConcurrentTasks_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetMaxConcurrentTasks_Statics::Developer_TaskScheduler_eventGetMaxConcurrentTasks_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskScheduler_GetMaxConcurrentTasks()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskScheduler_GetMaxConcurrentTasks_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumActiveTasks_Statics
	{
		struct Developer_TaskScheduler_eventGetNumActiveTasks_Parms
		{
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumActiveTasks_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventGetNumActiveTasks_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumActiveTasks_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumActiveTasks_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumActiveTasks_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumActiveTasks_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "GetNumActiveTasks", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumActiveTasks_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumActiveTasks_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumActiveTasks_Statics::Developer_TaskScheduler_eventGetNumActiveTasks_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumActiveTasks_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumActiveTasks_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumActiveTasks_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumActiveTasks_Statics::Developer_TaskScheduler_eventGetNumActiveTasks_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumActiveTasks()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumActiveTasks_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasks_Statics
	{
		struct Developer_TaskScheduler_eventGetNumTasks_Parms
		{
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasks_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventGetNumTasks_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasks_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasks_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasks_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasks_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "GetNumTasks", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasks_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasks_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasks_Statics::Developer_TaskScheduler_eventGetNumTasks_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasks_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasks_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasks_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasks_Statics::Developer_TaskScheduler_eventGetNumTasks_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasks()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasks_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType_Statics
	{
		struct Developer_TaskScheduler_eventGetNumTasksOfType_Parms
		{
			TSubclassOf<UObject>  objectClass;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_objectClass;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType_Statics::NewProp_objectClass = { "objectClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventGetNumTasksOfType_Parms, objectClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventGetNumTasksOfType_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType_Statics::NewProp_objectClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "GetNumTasksOfType", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType_Statics::Developer_TaskScheduler_eventGetNumTasksOfType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType_Statics::Developer_TaskScheduler_eventGetNumTasksOfType_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskScheduler_GetSecondsBetweenChecks_Statics
	{
		struct Developer_TaskScheduler_eventGetSecondsBetweenChecks_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_GetSecondsBetweenChecks_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventGetSecondsBetweenChecks_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskScheduler_GetSecondsBetweenChecks_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_GetSecondsBetweenChecks_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_GetSecondsBetweenChecks_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskScheduler_GetSecondsBetweenChecks_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "GetSecondsBetweenChecks", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskScheduler_GetSecondsBetweenChecks_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetSecondsBetweenChecks_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetSecondsBetweenChecks_Statics::Developer_TaskScheduler_eventGetSecondsBetweenChecks_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetSecondsBetweenChecks_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskScheduler_GetSecondsBetweenChecks_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetSecondsBetweenChecks_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_GetSecondsBetweenChecks_Statics::Developer_TaskScheduler_eventGetSecondsBetweenChecks_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskScheduler_GetSecondsBetweenChecks()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskScheduler_GetSecondsBetweenChecks_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics
	{
		struct Developer_TaskScheduler_eventHasTask_Parms
		{
			TScriptInterface<IInterface_Developer_Task> task;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_task_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_task;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::NewProp_task_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::NewProp_task = { "task", nullptr, (EPropertyFlags)0x0014000008000182, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventHasTask_Parms, task), Z_Construct_UClass_UInterface_Developer_Task_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::NewProp_task_MetaData), Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::NewProp_task_MetaData) };
	void Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_TaskScheduler_eventHasTask_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_TaskScheduler_eventHasTask_Parms), &Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::NewProp_task,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "HasTask", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::Developer_TaskScheduler_eventHasTask_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::Developer_TaskScheduler_eventHasTask_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics
	{
		struct Developer_TaskScheduler_eventInsertTaskAt_Parms
		{
			int32 index;
			TScriptInterface<IInterface_Developer_Task> task;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_index;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_task_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_task;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::NewProp_index = { "index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventInsertTaskAt_Parms, index), METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::NewProp_task_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::NewProp_task = { "task", nullptr, (EPropertyFlags)0x0014000008000182, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventInsertTaskAt_Parms, task), Z_Construct_UClass_UInterface_Developer_Task_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::NewProp_task_MetaData), Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::NewProp_task_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::NewProp_index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::NewProp_task,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "InsertTaskAt", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::Developer_TaskScheduler_eventInsertTaskAt_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::Developer_TaskScheduler_eventInsertTaskAt_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics
	{
		struct Developer_TaskScheduler_eventRemoveTask_Parms
		{
			TScriptInterface<IInterface_Developer_Task> task;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_task_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_task;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics::NewProp_task_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics::NewProp_task = { "task", nullptr, (EPropertyFlags)0x0014000008000182, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventRemoveTask_Parms, task), Z_Construct_UClass_UInterface_Developer_Task_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics::NewProp_task_MetaData), Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics::NewProp_task_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics::NewProp_task,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Removes a task from the scheduler queue. */" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Removes a task from the scheduler queue." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "RemoveTask", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics::Developer_TaskScheduler_eventRemoveTask_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics::Developer_TaskScheduler_eventRemoveTask_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskScheduler_SetMaxConcurrentTasks_Statics
	{
		struct Developer_TaskScheduler_eventSetMaxConcurrentTasks_Parms
		{
			int32 maxConcurrentTasks;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_maxConcurrentTasks;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_SetMaxConcurrentTasks_Statics::NewProp_maxConcurrentTasks = { "maxConcurrentTasks", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventSetMaxConcurrentTasks_Parms, maxConcurrentTasks), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskScheduler_SetMaxConcurrentTasks_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_SetMaxConcurrentTasks_Statics::NewProp_maxConcurrentTasks,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_SetMaxConcurrentTasks_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskScheduler_SetMaxConcurrentTasks_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "SetMaxConcurrentTasks", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskScheduler_SetMaxConcurrentTasks_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_SetMaxConcurrentTasks_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_SetMaxConcurrentTasks_Statics::Developer_TaskScheduler_eventSetMaxConcurrentTasks_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_SetMaxConcurrentTasks_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskScheduler_SetMaxConcurrentTasks_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_SetMaxConcurrentTasks_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_SetMaxConcurrentTasks_Statics::Developer_TaskScheduler_eventSetMaxConcurrentTasks_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskScheduler_SetMaxConcurrentTasks()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskScheduler_SetMaxConcurrentTasks_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskScheduler_SetSecondsBetweenChecks_Statics
	{
		struct Developer_TaskScheduler_eventSetSecondsBetweenChecks_Parms
		{
			float secondsBetweenChecks;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_secondsBetweenChecks;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_SetSecondsBetweenChecks_Statics::NewProp_secondsBetweenChecks = { "secondsBetweenChecks", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventSetSecondsBetweenChecks_Parms, secondsBetweenChecks), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskScheduler_SetSecondsBetweenChecks_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_SetSecondsBetweenChecks_Statics::NewProp_secondsBetweenChecks,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_SetSecondsBetweenChecks_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskScheduler_SetSecondsBetweenChecks_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "SetSecondsBetweenChecks", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskScheduler_SetSecondsBetweenChecks_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_SetSecondsBetweenChecks_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_SetSecondsBetweenChecks_Statics::Developer_TaskScheduler_eventSetSecondsBetweenChecks_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_SetSecondsBetweenChecks_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskScheduler_SetSecondsBetweenChecks_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_SetSecondsBetweenChecks_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_SetSecondsBetweenChecks_Statics::Developer_TaskScheduler_eventSetSecondsBetweenChecks_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskScheduler_SetSecondsBetweenChecks()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskScheduler_SetSecondsBetweenChecks_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics
	{
		struct Developer_TaskScheduler_eventStart_Parms
		{
			FString inID;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_inID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_inID;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics::NewProp_inID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics::NewProp_inID = { "inID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_TaskScheduler_eventStart_Parms, inID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics::NewProp_inID_MetaData), Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics::NewProp_inID_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics::NewProp_inID,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "Start", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics::Developer_TaskScheduler_eventStart_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics::Developer_TaskScheduler_eventStart_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_TaskScheduler_Start()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskScheduler_Start_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_TaskScheduler_Stop_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_TaskScheduler_Stop_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_TaskScheduler_Stop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_TaskScheduler, nullptr, "Stop", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_TaskScheduler_Stop_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_TaskScheduler_Stop_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UDeveloper_TaskScheduler_Stop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_TaskScheduler_Stop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_TaskScheduler);
	UClass* Z_Construct_UClass_UDeveloper_TaskScheduler_NoRegister()
	{
		return UDeveloper_TaskScheduler::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_TaskScheduler_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnTaskAdded_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTaskAdded;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnTaskStarted_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTaskStarted;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnTaskFinished_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTaskFinished;
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_Tasks_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Tasks_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Tasks;
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_ActiveTasks_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActiveTasks_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ActiveTasks;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDeveloper_TaskScheduler_AddTask, "AddTask" }, // 4069298147
		{ &Z_Construct_UFunction_UDeveloper_TaskScheduler_GetID, "GetID" }, // 1303534451
		{ &Z_Construct_UFunction_UDeveloper_TaskScheduler_GetMaxConcurrentTasks, "GetMaxConcurrentTasks" }, // 2804607450
		{ &Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumActiveTasks, "GetNumActiveTasks" }, // 2964181948
		{ &Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasks, "GetNumTasks" }, // 41421689
		{ &Z_Construct_UFunction_UDeveloper_TaskScheduler_GetNumTasksOfType, "GetNumTasksOfType" }, // 475483064
		{ &Z_Construct_UFunction_UDeveloper_TaskScheduler_GetSecondsBetweenChecks, "GetSecondsBetweenChecks" }, // 1238302140
		{ &Z_Construct_UFunction_UDeveloper_TaskScheduler_HasTask, "HasTask" }, // 3217725114
		{ &Z_Construct_UFunction_UDeveloper_TaskScheduler_InsertTaskAt, "InsertTaskAt" }, // 4060738187
		{ &Z_Construct_UFunction_UDeveloper_TaskScheduler_RemoveTask, "RemoveTask" }, // 1750306065
		{ &Z_Construct_UFunction_UDeveloper_TaskScheduler_SetMaxConcurrentTasks, "SetMaxConcurrentTasks" }, // 1488579479
		{ &Z_Construct_UFunction_UDeveloper_TaskScheduler_SetSecondsBetweenChecks, "SetSecondsBetweenChecks" }, // 2866227360
		{ &Z_Construct_UFunction_UDeveloper_TaskScheduler_Start, "Start" }, // 3418861236
		{ &Z_Construct_UFunction_UDeveloper_TaskScheduler_Stop, "Stop" }, // 1718654811
		{ &Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature, "TaskAdded__DelegateSignature" }, // 1410401730
		{ &Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature, "TaskFinished__DelegateSignature" }, // 3604058553
		{ &Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature, "TaskStarted__DelegateSignature" }, // 1349015567
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Core/Public/Developer_TaskScheduler.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_OnTaskAdded_MetaData[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_OnTaskAdded = { "OnTaskAdded", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_TaskScheduler, OnTaskAdded), Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskAdded__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_OnTaskAdded_MetaData), Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_OnTaskAdded_MetaData) }; // 1410401730
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_OnTaskStarted_MetaData[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_OnTaskStarted = { "OnTaskStarted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_TaskScheduler, OnTaskStarted), Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskStarted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_OnTaskStarted_MetaData), Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_OnTaskStarted_MetaData) }; // 1349015567
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_OnTaskFinished_MetaData[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_OnTaskFinished = { "OnTaskFinished", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_TaskScheduler, OnTaskFinished), Z_Construct_UDelegateFunction_UDeveloper_TaskScheduler_TaskFinished__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_OnTaskFinished_MetaData), Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_OnTaskFinished_MetaData) }; // 3604058553
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_Tasks_Inner = { "Tasks", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UInterface_Developer_Task_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_Tasks_MetaData[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_Tasks = { "Tasks", nullptr, (EPropertyFlags)0x0044000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_TaskScheduler, Tasks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_Tasks_MetaData), Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_Tasks_MetaData) };
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_ActiveTasks_Inner = { "ActiveTasks", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UInterface_Developer_Task_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_ActiveTasks_MetaData[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_TaskScheduler.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_ActiveTasks = { "ActiveTasks", nullptr, (EPropertyFlags)0x0044000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_TaskScheduler, ActiveTasks), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_ActiveTasks_MetaData), Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_ActiveTasks_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_OnTaskAdded,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_OnTaskStarted,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_OnTaskFinished,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_Tasks_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_Tasks,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_ActiveTasks_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::NewProp_ActiveTasks,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_TaskScheduler>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::ClassParams = {
		&UDeveloper_TaskScheduler::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDeveloper_TaskScheduler()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_TaskScheduler.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_TaskScheduler.OuterSingleton, Z_Construct_UClass_UDeveloper_TaskScheduler_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_TaskScheduler.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_TaskScheduler>()
	{
		return UDeveloper_TaskScheduler::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_TaskScheduler);
	UDeveloper_TaskScheduler::~UDeveloper_TaskScheduler() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_TaskScheduler, UDeveloper_TaskScheduler::StaticClass, TEXT("UDeveloper_TaskScheduler"), &Z_Registration_Info_UClass_UDeveloper_TaskScheduler, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_TaskScheduler), 1029911480U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_3320733853(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_TaskScheduler_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
