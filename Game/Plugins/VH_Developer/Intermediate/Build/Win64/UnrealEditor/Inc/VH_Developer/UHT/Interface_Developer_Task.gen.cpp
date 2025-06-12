// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Core/Public/Interface_Developer_Task.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInterface_Developer_Task() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UInterface_Developer_Task();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UInterface_Developer_Task_NoRegister();
	VH_DEVELOPER_API UEnum* Z_Construct_UEnum_VH_Developer_ETaskStatus();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ETaskStatus;
	static UEnum* ETaskStatus_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ETaskStatus.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ETaskStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_Developer_ETaskStatus, (UObject*)Z_Construct_UPackage__Script_VH_Developer(), TEXT("ETaskStatus"));
		}
		return Z_Registration_Info_UEnum_ETaskStatus.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UEnum* StaticEnum<ETaskStatus>()
	{
		return ETaskStatus_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_Developer_ETaskStatus_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_Developer_ETaskStatus_Statics::Enumerators[] = {
		{ "ETaskStatus::Invalid", (int64)ETaskStatus::Invalid },
		{ "ETaskStatus::Initialized", (int64)ETaskStatus::Initialized },
		{ "ETaskStatus::Started", (int64)ETaskStatus::Started },
		{ "ETaskStatus::Finished", (int64)ETaskStatus::Finished },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_Developer_ETaskStatus_Statics::Enum_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Enums\n// ---------------------------------\n" },
#endif
		{ "Finished.Name", "ETaskStatus::Finished" },
		{ "Initialized.Name", "ETaskStatus::Initialized" },
		{ "Invalid.Name", "ETaskStatus::Invalid" },
		{ "ModuleRelativePath", "Core/Public/Interface_Developer_Task.h" },
		{ "Started.Name", "ETaskStatus::Started" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Enums" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_Developer_ETaskStatus_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_Developer,
		nullptr,
		"ETaskStatus",
		"ETaskStatus",
		Z_Construct_UEnum_VH_Developer_ETaskStatus_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Developer_ETaskStatus_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Developer_ETaskStatus_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_Developer_ETaskStatus_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_Developer_ETaskStatus()
	{
		if (!Z_Registration_Info_UEnum_ETaskStatus.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ETaskStatus.InnerSingleton, Z_Construct_UEnum_VH_Developer_ETaskStatus_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ETaskStatus.InnerSingleton;
	}
	DEFINE_FUNCTION(IInterface_Developer_Task::execStartTask)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartTask_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_Developer_Task::execInitializeTask)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->InitializeTask_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_Developer_Task::execGetTaskStatus)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ETaskStatus*)Z_Param__Result=P_THIS->GetTaskStatus_Implementation();
		P_NATIVE_END;
	}
	struct Interface_Developer_Task_eventGetTaskStatus_Parms
	{
		ETaskStatus ReturnValue;

		/** Constructor, initializes return property only **/
		Interface_Developer_Task_eventGetTaskStatus_Parms()
			: ReturnValue((ETaskStatus)0)
		{
		}
	};
	struct Interface_Developer_Task_eventInitializeTask_Parms
	{
		bool ReturnValue;

		/** Constructor, initializes return property only **/
		Interface_Developer_Task_eventInitializeTask_Parms()
			: ReturnValue(false)
		{
		}
	};
	ETaskStatus IInterface_Developer_Task::GetTaskStatus() const
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetTaskStatus instead.");
		Interface_Developer_Task_eventGetTaskStatus_Parms Parms;
		return Parms.ReturnValue;
	}
	bool IInterface_Developer_Task::InitializeTask()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_InitializeTask instead.");
		Interface_Developer_Task_eventInitializeTask_Parms Parms;
		return Parms.ReturnValue;
	}
	void IInterface_Developer_Task::StartTask()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_StartTask instead.");
	}
	void UInterface_Developer_Task::StaticRegisterNativesUInterface_Developer_Task()
	{
		UClass* Class = UInterface_Developer_Task::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetTaskStatus", &IInterface_Developer_Task::execGetTaskStatus },
			{ "InitializeTask", &IInterface_Developer_Task::execInitializeTask },
			{ "StartTask", &IInterface_Developer_Task::execStartTask },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInterface_Developer_Task_GetTaskStatus_Statics
	{
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UInterface_Developer_Task_GetTaskStatus_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UInterface_Developer_Task_GetTaskStatus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_Developer_Task_eventGetTaskStatus_Parms, ReturnValue), Z_Construct_UEnum_VH_Developer_ETaskStatus, METADATA_PARAMS(0, nullptr) }; // 3975634848
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_Developer_Task_GetTaskStatus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Developer_Task_GetTaskStatus_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Developer_Task_GetTaskStatus_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_Developer_Task_GetTaskStatus_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Interface_Developer_Task.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_Developer_Task_GetTaskStatus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_Developer_Task, nullptr, "GetTaskStatus", nullptr, nullptr, Z_Construct_UFunction_UInterface_Developer_Task_GetTaskStatus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Task_GetTaskStatus_Statics::PropPointers), sizeof(Interface_Developer_Task_eventGetTaskStatus_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Task_GetTaskStatus_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_Developer_Task_GetTaskStatus_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Task_GetTaskStatus_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_Developer_Task_eventGetTaskStatus_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_Developer_Task_GetTaskStatus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_Developer_Task_GetTaskStatus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_Developer_Task_InitializeTask_Statics
	{
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UInterface_Developer_Task_InitializeTask_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Interface_Developer_Task_eventInitializeTask_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInterface_Developer_Task_InitializeTask_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Interface_Developer_Task_eventInitializeTask_Parms), &Z_Construct_UFunction_UInterface_Developer_Task_InitializeTask_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_Developer_Task_InitializeTask_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Developer_Task_InitializeTask_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_Developer_Task_InitializeTask_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Interface_Developer_Task.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_Developer_Task_InitializeTask_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_Developer_Task, nullptr, "InitializeTask", nullptr, nullptr, Z_Construct_UFunction_UInterface_Developer_Task_InitializeTask_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Task_InitializeTask_Statics::PropPointers), sizeof(Interface_Developer_Task_eventInitializeTask_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Task_InitializeTask_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_Developer_Task_InitializeTask_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Task_InitializeTask_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_Developer_Task_eventInitializeTask_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_Developer_Task_InitializeTask()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_Developer_Task_InitializeTask_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_Developer_Task_StartTask_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_Developer_Task_StartTask_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Interface_Developer_Task.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_Developer_Task_StartTask_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_Developer_Task, nullptr, "StartTask", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Task_StartTask_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_Developer_Task_StartTask_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInterface_Developer_Task_StartTask()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_Developer_Task_StartTask_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInterface_Developer_Task);
	UClass* Z_Construct_UClass_UInterface_Developer_Task_NoRegister()
	{
		return UInterface_Developer_Task::StaticClass();
	}
	struct Z_Construct_UClass_UInterface_Developer_Task_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInterface_Developer_Task_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_Developer_Task_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UInterface_Developer_Task_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInterface_Developer_Task_GetTaskStatus, "GetTaskStatus" }, // 2871932487
		{ &Z_Construct_UFunction_UInterface_Developer_Task_InitializeTask, "InitializeTask" }, // 1778343011
		{ &Z_Construct_UFunction_UInterface_Developer_Task_StartTask, "StartTask" }, // 1584709732
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_Developer_Task_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInterface_Developer_Task_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Public/Interface_Developer_Task.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInterface_Developer_Task_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInterface_Developer_Task>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInterface_Developer_Task_Statics::ClassParams = {
		&UInterface_Developer_Task::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001040A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_Developer_Task_Statics::Class_MetaDataParams), Z_Construct_UClass_UInterface_Developer_Task_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UInterface_Developer_Task()
	{
		if (!Z_Registration_Info_UClass_UInterface_Developer_Task.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInterface_Developer_Task.OuterSingleton, Z_Construct_UClass_UInterface_Developer_Task_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInterface_Developer_Task.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UInterface_Developer_Task>()
	{
		return UInterface_Developer_Task::StaticClass();
	}
	UInterface_Developer_Task::UInterface_Developer_Task(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInterface_Developer_Task);
	UInterface_Developer_Task::~UInterface_Developer_Task() {}
	static FName NAME_UInterface_Developer_Task_GetTaskStatus = FName(TEXT("GetTaskStatus"));
	ETaskStatus IInterface_Developer_Task::Execute_GetTaskStatus(const UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_Developer_Task::StaticClass()));
		Interface_Developer_Task_eventGetTaskStatus_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_Developer_Task_GetTaskStatus);
		if (Func)
		{
			const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (const IInterface_Developer_Task*)(O->GetNativeInterfaceAddress(UInterface_Developer_Task::StaticClass())))
		{
			Parms.ReturnValue = I->GetTaskStatus_Implementation();
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UInterface_Developer_Task_InitializeTask = FName(TEXT("InitializeTask"));
	bool IInterface_Developer_Task::Execute_InitializeTask(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_Developer_Task::StaticClass()));
		Interface_Developer_Task_eventInitializeTask_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_Developer_Task_InitializeTask);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInterface_Developer_Task*)(O->GetNativeInterfaceAddress(UInterface_Developer_Task::StaticClass())))
		{
			Parms.ReturnValue = I->InitializeTask_Implementation();
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UInterface_Developer_Task_StartTask = FName(TEXT("StartTask"));
	void IInterface_Developer_Task::Execute_StartTask(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_Developer_Task::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInterface_Developer_Task_StartTask);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInterface_Developer_Task*)(O->GetNativeInterfaceAddress(UInterface_Developer_Task::StaticClass())))
		{
			I->StartTask_Implementation();
		}
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_Statics::EnumInfo[] = {
		{ ETaskStatus_StaticEnum, TEXT("ETaskStatus"), &Z_Registration_Info_UEnum_ETaskStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3975634848U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInterface_Developer_Task, UInterface_Developer_Task::StaticClass, TEXT("UInterface_Developer_Task"), &Z_Registration_Info_UClass_UInterface_Developer_Task, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInterface_Developer_Task), 3689907523U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_1621637428(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Task_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
