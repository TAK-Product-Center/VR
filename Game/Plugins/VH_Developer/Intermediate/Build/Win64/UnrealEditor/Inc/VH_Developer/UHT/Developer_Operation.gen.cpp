// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Core/Public/Developer_Operation.h"
#include "InputAction.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_Operation() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	ENHANCEDINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FInputActionInstance();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Operation();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Operation_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UDeveloper_Operation::execActionInput)
	{
		P_GET_STRUCT_REF(FInputActionInstance,Z_Param_Out_inputActionInstance);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ActionInput_Implementation(Z_Param_Out_inputActionInstance);
		P_NATIVE_END;
	}
	struct Developer_Operation_eventActionInput_Parms
	{
		FInputActionInstance inputActionInstance;
	};
	struct Developer_Operation_eventReceiveTick_Parms
	{
		float deltaSeconds;
	};
	static FName NAME_UDeveloper_Operation_ActionInput = FName(TEXT("ActionInput"));
	void UDeveloper_Operation::ActionInput(FInputActionInstance const& inputActionInstance)
	{
		Developer_Operation_eventActionInput_Parms Parms;
		Parms.inputActionInstance=inputActionInstance;
		ProcessEvent(FindFunctionChecked(NAME_UDeveloper_Operation_ActionInput),&Parms);
	}
	static FName NAME_UDeveloper_Operation_ReceiveStart = FName(TEXT("ReceiveStart"));
	void UDeveloper_Operation::ReceiveStart()
	{
		ProcessEvent(FindFunctionChecked(NAME_UDeveloper_Operation_ReceiveStart),NULL);
	}
	static FName NAME_UDeveloper_Operation_ReceiveStop = FName(TEXT("ReceiveStop"));
	void UDeveloper_Operation::ReceiveStop()
	{
		ProcessEvent(FindFunctionChecked(NAME_UDeveloper_Operation_ReceiveStop),NULL);
	}
	static FName NAME_UDeveloper_Operation_ReceiveTick = FName(TEXT("ReceiveTick"));
	void UDeveloper_Operation::ReceiveTick(float deltaSeconds)
	{
		Developer_Operation_eventReceiveTick_Parms Parms;
		Parms.deltaSeconds=deltaSeconds;
		ProcessEvent(FindFunctionChecked(NAME_UDeveloper_Operation_ReceiveTick),&Parms);
	}
	void UDeveloper_Operation::StaticRegisterNativesUDeveloper_Operation()
	{
		UClass* Class = UDeveloper_Operation::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ActionInput", &UDeveloper_Operation::execActionInput },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDeveloper_Operation_ActionInput_Statics
	{
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Operation_ActionInput_Statics::NewProp_inputActionInstance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Operation_ActionInput_Statics::NewProp_inputActionInstance = { "inputActionInstance", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Operation_eventActionInput_Parms, inputActionInstance), Z_Construct_UScriptStruct_FInputActionInstance, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Operation_ActionInput_Statics::NewProp_inputActionInstance_MetaData), Z_Construct_UFunction_UDeveloper_Operation_ActionInput_Statics::NewProp_inputActionInstance_MetaData) }; // 2153033866
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Operation_ActionInput_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Operation_ActionInput_Statics::NewProp_inputActionInstance,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Operation_ActionInput_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_Operation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Operation_ActionInput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Operation, nullptr, "ActionInput", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Operation_ActionInput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Operation_ActionInput_Statics::PropPointers), sizeof(Developer_Operation_eventActionInput_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Operation_ActionInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Operation_ActionInput_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Operation_ActionInput_Statics::PropPointers) < 2048);
	static_assert(sizeof(Developer_Operation_eventActionInput_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Operation_ActionInput()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Operation_ActionInput_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Operation_ReceiveStart_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Operation_ReceiveStart_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_Operation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Operation_ReceiveStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Operation, nullptr, "ReceiveStart", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Operation_ReceiveStart_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Operation_ReceiveStart_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UDeveloper_Operation_ReceiveStart()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Operation_ReceiveStart_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Operation_ReceiveStop_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Operation_ReceiveStop_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_Operation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Operation_ReceiveStop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Operation, nullptr, "ReceiveStop", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Operation_ReceiveStop_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Operation_ReceiveStop_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UDeveloper_Operation_ReceiveStop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Operation_ReceiveStop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Operation_ReceiveTick_Statics
	{
		static const UECodeGen_Private::FFloatPropertyParams NewProp_deltaSeconds;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDeveloper_Operation_ReceiveTick_Statics::NewProp_deltaSeconds = { "deltaSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Operation_eventReceiveTick_Parms, deltaSeconds), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Operation_ReceiveTick_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Operation_ReceiveTick_Statics::NewProp_deltaSeconds,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Operation_ReceiveTick_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_Operation.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Operation_ReceiveTick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Operation, nullptr, "ReceiveTick", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Operation_ReceiveTick_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Operation_ReceiveTick_Statics::PropPointers), sizeof(Developer_Operation_eventReceiveTick_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Operation_ReceiveTick_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Operation_ReceiveTick_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Operation_ReceiveTick_Statics::PropPointers) < 2048);
	static_assert(sizeof(Developer_Operation_eventReceiveTick_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Operation_ReceiveTick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Operation_ReceiveTick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_Operation);
	UClass* Z_Construct_UClass_UDeveloper_Operation_NoRegister()
	{
		return UDeveloper_Operation::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_Operation_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InputActions_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InputActions_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_InputActions;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InputMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InputMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InputMappingContextPriority_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_InputMappingContextPriority;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_Operation_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Operation_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDeveloper_Operation_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDeveloper_Operation_ActionInput, "ActionInput" }, // 3900009107
		{ &Z_Construct_UFunction_UDeveloper_Operation_ReceiveStart, "ReceiveStart" }, // 213412035
		{ &Z_Construct_UFunction_UDeveloper_Operation_ReceiveStop, "ReceiveStop" }, // 1782929883
		{ &Z_Construct_UFunction_UDeveloper_Operation_ReceiveTick, "ReceiveTick" }, // 2283398259
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Operation_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Operation_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Core/Public/Developer_Operation.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Public/Developer_Operation.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputActions_ElementProp = { "InputActions", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputActions_MetaData[] = {
		{ "Category", "Developer_Operation" },
		{ "ModuleRelativePath", "Core/Public/Developer_Operation.h" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputActions = { "InputActions", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_Operation, InputActions), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputActions_MetaData), Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputActions_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputMappingContext_MetaData[] = {
		{ "Category", "Developer_Operation" },
		{ "ModuleRelativePath", "Core/Public/Developer_Operation.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputMappingContext = { "InputMappingContext", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_Operation, InputMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputMappingContext_MetaData), Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputMappingContext_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputMappingContextPriority_MetaData[] = {
		{ "Category", "Developer_Operation" },
		{ "ModuleRelativePath", "Core/Public/Developer_Operation.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputMappingContextPriority = { "InputMappingContextPriority", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_Operation, InputMappingContextPriority), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputMappingContextPriority_MetaData), Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputMappingContextPriority_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDeveloper_Operation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputActions_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputActions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Operation_Statics::NewProp_InputMappingContextPriority,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_Operation_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_Operation>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_Operation_Statics::ClassParams = {
		&UDeveloper_Operation::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDeveloper_Operation_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Operation_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Operation_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_Operation_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Operation_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDeveloper_Operation()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_Operation.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_Operation.OuterSingleton, Z_Construct_UClass_UDeveloper_Operation_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_Operation.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_Operation>()
	{
		return UDeveloper_Operation::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_Operation);
	UDeveloper_Operation::~UDeveloper_Operation() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_Operation, UDeveloper_Operation::StaticClass, TEXT("UDeveloper_Operation"), &Z_Registration_Info_UClass_UDeveloper_Operation, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_Operation), 3209527536U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_1595416629(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Operation_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
