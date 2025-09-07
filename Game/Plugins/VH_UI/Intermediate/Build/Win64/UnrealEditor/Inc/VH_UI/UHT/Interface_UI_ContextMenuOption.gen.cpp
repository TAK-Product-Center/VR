// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interface_UI_ContextMenuOption.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInterface_UI_ContextMenuOption() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_UI();
	VH_UI_API UClass* Z_Construct_UClass_UInterface_UI_ContextMenuOption();
	VH_UI_API UClass* Z_Construct_UClass_UInterface_UI_ContextMenuOption_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(IInterface_UI_ContextMenuOption::execExecute)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Execute_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_UI_ContextMenuOption::execSetInstigatorAndSource)
	{
		P_GET_OBJECT(AActor,Z_Param_instigator);
		P_GET_OBJECT(UObject,Z_Param_source);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetInstigatorAndSource_Implementation(Z_Param_instigator,Z_Param_source);
		P_NATIVE_END;
	}
	struct Interface_UI_ContextMenuOption_eventSetInstigatorAndSource_Parms
	{
		AActor* instigator;
		UObject* source;
	};
	void IInterface_UI_ContextMenuOption::Execute()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_Execute instead.");
	}
	void IInterface_UI_ContextMenuOption::SetInstigatorAndSource(AActor* instigator, UObject* source)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_SetInstigatorAndSource instead.");
	}
	void UInterface_UI_ContextMenuOption::StaticRegisterNativesUInterface_UI_ContextMenuOption()
	{
		UClass* Class = UInterface_UI_ContextMenuOption::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Execute", &IInterface_UI_ContextMenuOption::execExecute },
			{ "SetInstigatorAndSource", &IInterface_UI_ContextMenuOption::execSetInstigatorAndSource },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInterface_UI_ContextMenuOption_Execute_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_UI_ContextMenuOption_Execute_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Called when this option is clicked\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_UI_ContextMenuOption.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Called when this option is clicked" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_UI_ContextMenuOption_Execute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_UI_ContextMenuOption, nullptr, "Execute", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_ContextMenuOption_Execute_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_UI_ContextMenuOption_Execute_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInterface_UI_ContextMenuOption_Execute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_UI_ContextMenuOption_Execute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_UI_ContextMenuOption_SetInstigatorAndSource_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_instigator;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_source;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInterface_UI_ContextMenuOption_SetInstigatorAndSource_Statics::NewProp_instigator = { "instigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_UI_ContextMenuOption_eventSetInstigatorAndSource_Parms, instigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInterface_UI_ContextMenuOption_SetInstigatorAndSource_Statics::NewProp_source = { "source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_UI_ContextMenuOption_eventSetInstigatorAndSource_Parms, source), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_UI_ContextMenuOption_SetInstigatorAndSource_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_UI_ContextMenuOption_SetInstigatorAndSource_Statics::NewProp_instigator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_UI_ContextMenuOption_SetInstigatorAndSource_Statics::NewProp_source,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_UI_ContextMenuOption_SetInstigatorAndSource_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Sets instigator and source when this option is created\n\x09* \\param instigator Actor that caused this option to be created\n\x09* \\param source Object that was clicked on (if any) to generate the generate this option\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_UI_ContextMenuOption.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Sets instigator and source when this option is created\n* \\param instigator Actor that caused this option to be created\n* \\param source Object that was clicked on (if any) to generate the generate this option" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_UI_ContextMenuOption_SetInstigatorAndSource_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_UI_ContextMenuOption, nullptr, "SetInstigatorAndSource", nullptr, nullptr, Z_Construct_UFunction_UInterface_UI_ContextMenuOption_SetInstigatorAndSource_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_ContextMenuOption_SetInstigatorAndSource_Statics::PropPointers), sizeof(Interface_UI_ContextMenuOption_eventSetInstigatorAndSource_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_ContextMenuOption_SetInstigatorAndSource_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_UI_ContextMenuOption_SetInstigatorAndSource_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_ContextMenuOption_SetInstigatorAndSource_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_UI_ContextMenuOption_eventSetInstigatorAndSource_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_UI_ContextMenuOption_SetInstigatorAndSource()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_UI_ContextMenuOption_SetInstigatorAndSource_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInterface_UI_ContextMenuOption);
	UClass* Z_Construct_UClass_UInterface_UI_ContextMenuOption_NoRegister()
	{
		return UInterface_UI_ContextMenuOption::StaticClass();
	}
	struct Z_Construct_UClass_UInterface_UI_ContextMenuOption_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInterface_UI_ContextMenuOption_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_UI_ContextMenuOption_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UInterface_UI_ContextMenuOption_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInterface_UI_ContextMenuOption_Execute, "Execute" }, // 656487267
		{ &Z_Construct_UFunction_UInterface_UI_ContextMenuOption_SetInstigatorAndSource, "SetInstigatorAndSource" }, // 2766147760
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_UI_ContextMenuOption_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInterface_UI_ContextMenuOption_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Public/Interface_UI_ContextMenuOption.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInterface_UI_ContextMenuOption_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInterface_UI_ContextMenuOption>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInterface_UI_ContextMenuOption_Statics::ClassParams = {
		&UInterface_UI_ContextMenuOption::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_UI_ContextMenuOption_Statics::Class_MetaDataParams), Z_Construct_UClass_UInterface_UI_ContextMenuOption_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UInterface_UI_ContextMenuOption()
	{
		if (!Z_Registration_Info_UClass_UInterface_UI_ContextMenuOption.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInterface_UI_ContextMenuOption.OuterSingleton, Z_Construct_UClass_UInterface_UI_ContextMenuOption_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInterface_UI_ContextMenuOption.OuterSingleton;
	}
	template<> VH_UI_API UClass* StaticClass<UInterface_UI_ContextMenuOption>()
	{
		return UInterface_UI_ContextMenuOption::StaticClass();
	}
	UInterface_UI_ContextMenuOption::UInterface_UI_ContextMenuOption(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInterface_UI_ContextMenuOption);
	UInterface_UI_ContextMenuOption::~UInterface_UI_ContextMenuOption() {}
	static FName NAME_UInterface_UI_ContextMenuOption_Execute = FName(TEXT("Execute"));
	void IInterface_UI_ContextMenuOption::Execute_Execute(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_UI_ContextMenuOption::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInterface_UI_ContextMenuOption_Execute);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInterface_UI_ContextMenuOption*)(O->GetNativeInterfaceAddress(UInterface_UI_ContextMenuOption::StaticClass())))
		{
			I->Execute_Implementation();
		}
	}
	static FName NAME_UInterface_UI_ContextMenuOption_SetInstigatorAndSource = FName(TEXT("SetInstigatorAndSource"));
	void IInterface_UI_ContextMenuOption::Execute_SetInstigatorAndSource(UObject* O, AActor* instigator, UObject* source)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_UI_ContextMenuOption::StaticClass()));
		Interface_UI_ContextMenuOption_eventSetInstigatorAndSource_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_UI_ContextMenuOption_SetInstigatorAndSource);
		if (Func)
		{
			Parms.instigator=instigator;
			Parms.source=source;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInterface_UI_ContextMenuOption*)(O->GetNativeInterfaceAddress(UInterface_UI_ContextMenuOption::StaticClass())))
		{
			I->SetInstigatorAndSource_Implementation(instigator,source);
		}
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInterface_UI_ContextMenuOption, UInterface_UI_ContextMenuOption::StaticClass, TEXT("UInterface_UI_ContextMenuOption"), &Z_Registration_Info_UClass_UInterface_UI_ContextMenuOption, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInterface_UI_ContextMenuOption), 331437293U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_797780502(TEXT("/Script/VH_UI"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuOption_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
