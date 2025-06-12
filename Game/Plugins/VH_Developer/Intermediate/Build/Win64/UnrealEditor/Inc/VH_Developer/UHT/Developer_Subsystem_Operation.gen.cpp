// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Subsystems/Public/Developer_Subsystem_Operation.h"
#include "InputAction.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_Subsystem_Operation() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UWorldSubsystem();
	ENHANCEDINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FInputActionInstance();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Operation_NoRegister();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_Operation();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_Operation_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UDeveloper_Subsystem_Operation::execHandleInputAction)
	{
		P_GET_STRUCT_REF(FInputActionInstance,Z_Param_Out_inputActionInstance);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleInputAction(Z_Param_Out_inputActionInstance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Operation::execGetOperationsByClass)
	{
		P_GET_OBJECT(UClass,Z_Param_operationClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TSet<UDeveloper_Operation*>*)Z_Param__Result=P_THIS->GetOperationsByClass(Z_Param_operationClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Operation::execStopOperation)
	{
		P_GET_OBJECT(UDeveloper_Operation,Z_Param_operation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StopOperation(Z_Param_operation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Operation::execStartOperation)
	{
		P_GET_OBJECT(UDeveloper_Operation,Z_Param_operation);
		P_GET_PROPERTY(FDoubleProperty,Z_Param_priority);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->StartOperation(Z_Param_operation,Z_Param_priority);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_Operation::execStartOperationByClass)
	{
		P_GET_OBJECT(UClass,Z_Param_operationClass);
		P_GET_PROPERTY(FDoubleProperty,Z_Param_priority);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UDeveloper_Operation**)Z_Param__Result=P_THIS->StartOperationByClass(Z_Param_operationClass,Z_Param_priority);
		P_NATIVE_END;
	}
	void UDeveloper_Subsystem_Operation::StaticRegisterNativesUDeveloper_Subsystem_Operation()
	{
		UClass* Class = UDeveloper_Subsystem_Operation::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetOperationsByClass", &UDeveloper_Subsystem_Operation::execGetOperationsByClass },
			{ "HandleInputAction", &UDeveloper_Subsystem_Operation::execHandleInputAction },
			{ "StartOperation", &UDeveloper_Subsystem_Operation::execStartOperation },
			{ "StartOperationByClass", &UDeveloper_Subsystem_Operation::execStartOperationByClass },
			{ "StopOperation", &UDeveloper_Subsystem_Operation::execStopOperation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics
	{
		struct Developer_Subsystem_Operation_eventGetOperationsByClass_Parms
		{
			TSubclassOf<UDeveloper_Operation>  operationClass;
			TSet<UDeveloper_Operation*> ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_operationClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_ElementProp;
		static const UECodeGen_Private::FSetPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::NewProp_operationClass = { "operationClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Operation_eventGetOperationsByClass_Parms, operationClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDeveloper_Operation_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::NewProp_ReturnValue_ElementProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDeveloper_Operation_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Operation_eventGetOperationsByClass_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::NewProp_operationClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::NewProp_ReturnValue_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Operation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Operation, nullptr, "GetOperationsByClass", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::Developer_Subsystem_Operation_eventGetOperationsByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::Developer_Subsystem_Operation_eventGetOperationsByClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics
	{
		struct Developer_Subsystem_Operation_eventHandleInputAction_Parms
		{
			FInputActionInstance inputActionInstance;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_inputActionInstance_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_inputActionInstance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics::NewProp_inputActionInstance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics::NewProp_inputActionInstance = { "inputActionInstance", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Operation_eventHandleInputAction_Parms, inputActionInstance), Z_Construct_UScriptStruct_FInputActionInstance, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics::NewProp_inputActionInstance_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics::NewProp_inputActionInstance_MetaData) }; // 2153033866
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics::NewProp_inputActionInstance,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Operation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Operation, nullptr, "HandleInputAction", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics::Developer_Subsystem_Operation_eventHandleInputAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics::Developer_Subsystem_Operation_eventHandleInputAction_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics
	{
		struct Developer_Subsystem_Operation_eventStartOperation_Parms
		{
			UDeveloper_Operation* operation;
			double priority;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_operation;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_priority;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::NewProp_operation = { "operation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Operation_eventStartOperation_Parms, operation), Z_Construct_UClass_UDeveloper_Operation_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::NewProp_priority = { "priority", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Operation_eventStartOperation_Parms, priority), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Subsystem_Operation_eventStartOperation_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Subsystem_Operation_eventStartOperation_Parms), &Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::NewProp_operation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::NewProp_priority,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \\brief Starts an operation \n\x09*  \\param operation Operation to start\n\x09*  \\param priority Operations receive input in order of priority (highest to lowest). \n\x09*  \\return False if operation already started\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Operation.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief Starts an operation\n      *  \\param operation Operation to start\n      *  \\param priority Operations receive input in order of priority (highest to lowest).\n      *  \\return False if operation already started" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Operation, nullptr, "StartOperation", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::Developer_Subsystem_Operation_eventStartOperation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::Developer_Subsystem_Operation_eventStartOperation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics
	{
		struct Developer_Subsystem_Operation_eventStartOperationByClass_Parms
		{
			TSubclassOf<UDeveloper_Operation>  operationClass;
			double priority;
			UDeveloper_Operation* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_operationClass;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_priority;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::NewProp_operationClass = { "operationClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Operation_eventStartOperationByClass_Parms, operationClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDeveloper_Operation_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::NewProp_priority = { "priority", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Operation_eventStartOperationByClass_Parms, priority), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Operation_eventStartOperationByClass_Parms, ReturnValue), Z_Construct_UClass_UDeveloper_Operation_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::NewProp_operationClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::NewProp_priority,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \\brief Starts an operation by class\n\x09*  \\param operationClass Class of operation to start\n\x09*  \\param priority Operations receive input in order of priority (highest to lowest).\n\x09*  \\return Created operation\n\x09*/" },
#endif
		{ "DeterminesOutputType", "operationClass" },
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Operation.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief Starts an operation by class\n      *  \\param operationClass Class of operation to start\n      *  \\param priority Operations receive input in order of priority (highest to lowest).\n      *  \\return Created operation" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Operation, nullptr, "StartOperationByClass", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::Developer_Subsystem_Operation_eventStartOperationByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::Developer_Subsystem_Operation_eventStartOperationByClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StopOperation_Statics
	{
		struct Developer_Subsystem_Operation_eventStopOperation_Parms
		{
			UDeveloper_Operation* operation;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_operation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StopOperation_Statics::NewProp_operation = { "operation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_Operation_eventStopOperation_Parms, operation), Z_Construct_UClass_UDeveloper_Operation_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StopOperation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StopOperation_Statics::NewProp_operation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StopOperation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Operation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StopOperation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_Operation, nullptr, "StopOperation", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StopOperation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StopOperation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StopOperation_Statics::Developer_Subsystem_Operation_eventStopOperation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StopOperation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StopOperation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StopOperation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StopOperation_Statics::Developer_Subsystem_Operation_eventStopOperation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StopOperation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StopOperation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_Subsystem_Operation);
	UClass* Z_Construct_UClass_UDeveloper_Subsystem_Operation_NoRegister()
	{
		return UDeveloper_Subsystem_Operation::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Operations_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Operations_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_Operations;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UWorldSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Operation_GetOperationsByClass, "GetOperationsByClass" }, // 416036414
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Operation_HandleInputAction, "HandleInputAction" }, // 2285585757
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperation, "StartOperation" }, // 169131098
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StartOperationByClass, "StartOperationByClass" }, // 9067381
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_Operation_StopOperation, "StopOperation" }, // 3278471905
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Subsystems/Public/Developer_Subsystem_Operation.h" },
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Operation.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::NewProp_Operations_ElementProp = { "Operations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UDeveloper_Operation_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::NewProp_Operations_MetaData[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_Operation.h" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::NewProp_Operations = { "Operations", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_Subsystem_Operation, Operations), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::NewProp_Operations_MetaData), Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::NewProp_Operations_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::NewProp_Operations_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::NewProp_Operations,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_Subsystem_Operation>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::ClassParams = {
		&UDeveloper_Subsystem_Operation::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDeveloper_Subsystem_Operation()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_Subsystem_Operation.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_Subsystem_Operation.OuterSingleton, Z_Construct_UClass_UDeveloper_Subsystem_Operation_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_Subsystem_Operation.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_Subsystem_Operation>()
	{
		return UDeveloper_Subsystem_Operation::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_Subsystem_Operation);
	UDeveloper_Subsystem_Operation::~UDeveloper_Subsystem_Operation() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_Subsystem_Operation, UDeveloper_Subsystem_Operation::StaticClass, TEXT("UDeveloper_Subsystem_Operation"), &Z_Registration_Info_UClass_UDeveloper_Subsystem_Operation, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_Subsystem_Operation), 1107490516U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_1786213254(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Operation_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
