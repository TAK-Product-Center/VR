// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interface_UI_ContextMenuSource.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInterface_UI_ContextMenuSource() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_UI();
	VH_UI_API UClass* Z_Construct_UClass_UInterface_UI_ContextMenuSource();
	VH_UI_API UClass* Z_Construct_UClass_UInterface_UI_ContextMenuSource_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(IInterface_UI_ContextMenuSource::execGetContextMenuClass)
	{
		P_GET_OBJECT_REF_NO_PTR(TSubclassOf<UUserWidget> ,Z_Param_Out_contextMenuClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetContextMenuClass_Implementation(Z_Param_Out_contextMenuClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_UI_ContextMenuSource::execGetContextOptionClasses)
	{
		P_GET_TSET_REF(TSubclassOf<UObject> ,Z_Param_Out_contextOptionClasses);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GetContextOptionClasses_Implementation(Z_Param_Out_contextOptionClasses);
		P_NATIVE_END;
	}
	struct Interface_UI_ContextMenuSource_eventGetContextMenuClass_Parms
	{
		TSubclassOf<UUserWidget>  contextMenuClass;
	};
	struct Interface_UI_ContextMenuSource_eventGetContextOptionClasses_Parms
	{
		TSet<TSubclassOf<UObject> > contextOptionClasses;
	};
	void IInterface_UI_ContextMenuSource::GetContextMenuClass(TSubclassOf<UUserWidget> & contextMenuClass)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetContextMenuClass instead.");
	}
	void IInterface_UI_ContextMenuSource::GetContextOptionClasses(TSet<TSubclassOf<UObject> >& contextOptionClasses)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetContextOptionClasses instead.");
	}
	void UInterface_UI_ContextMenuSource::StaticRegisterNativesUInterface_UI_ContextMenuSource()
	{
		UClass* Class = UInterface_UI_ContextMenuSource::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetContextMenuClass", &IInterface_UI_ContextMenuSource::execGetContextMenuClass },
			{ "GetContextOptionClasses", &IInterface_UI_ContextMenuSource::execGetContextOptionClasses },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextMenuClass_Statics
	{
		static const UECodeGen_Private::FClassPropertyParams NewProp_contextMenuClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextMenuClass_Statics::NewProp_contextMenuClass = { "contextMenuClass", nullptr, (EPropertyFlags)0x0014000000000180, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_UI_ContextMenuSource_eventGetContextMenuClass_Parms, contextMenuClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextMenuClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextMenuClass_Statics::NewProp_contextMenuClass,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextMenuClass_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Interface_UI_ContextMenuSource.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextMenuClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_UI_ContextMenuSource, nullptr, "GetContextMenuClass", nullptr, nullptr, Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextMenuClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextMenuClass_Statics::PropPointers), sizeof(Interface_UI_ContextMenuSource_eventGetContextMenuClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextMenuClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextMenuClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextMenuClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_UI_ContextMenuSource_eventGetContextMenuClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextMenuClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextMenuClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextOptionClasses_Statics
	{
		static const UECodeGen_Private::FClassPropertyParams NewProp_contextOptionClasses_ElementProp;
		static const UECodeGen_Private::FSetPropertyParams NewProp_contextOptionClasses;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextOptionClasses_Statics::NewProp_contextOptionClasses_ElementProp = { "contextOptionClasses", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextOptionClasses_Statics::NewProp_contextOptionClasses = { "contextOptionClasses", nullptr, (EPropertyFlags)0x0014000000000180, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_UI_ContextMenuSource_eventGetContextOptionClasses_Parms, contextOptionClasses), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextOptionClasses_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextOptionClasses_Statics::NewProp_contextOptionClasses_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextOptionClasses_Statics::NewProp_contextOptionClasses,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextOptionClasses_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Interface_UI_ContextMenuSource.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextOptionClasses_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_UI_ContextMenuSource, nullptr, "GetContextOptionClasses", nullptr, nullptr, Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextOptionClasses_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextOptionClasses_Statics::PropPointers), sizeof(Interface_UI_ContextMenuSource_eventGetContextOptionClasses_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextOptionClasses_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextOptionClasses_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextOptionClasses_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_UI_ContextMenuSource_eventGetContextOptionClasses_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextOptionClasses()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextOptionClasses_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInterface_UI_ContextMenuSource);
	UClass* Z_Construct_UClass_UInterface_UI_ContextMenuSource_NoRegister()
	{
		return UInterface_UI_ContextMenuSource::StaticClass();
	}
	struct Z_Construct_UClass_UInterface_UI_ContextMenuSource_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInterface_UI_ContextMenuSource_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_UI_ContextMenuSource_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UInterface_UI_ContextMenuSource_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextMenuClass, "GetContextMenuClass" }, // 3370372872
		{ &Z_Construct_UFunction_UInterface_UI_ContextMenuSource_GetContextOptionClasses, "GetContextOptionClasses" }, // 2441123100
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_UI_ContextMenuSource_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInterface_UI_ContextMenuSource_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Public/Interface_UI_ContextMenuSource.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInterface_UI_ContextMenuSource_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInterface_UI_ContextMenuSource>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInterface_UI_ContextMenuSource_Statics::ClassParams = {
		&UInterface_UI_ContextMenuSource::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_UI_ContextMenuSource_Statics::Class_MetaDataParams), Z_Construct_UClass_UInterface_UI_ContextMenuSource_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UInterface_UI_ContextMenuSource()
	{
		if (!Z_Registration_Info_UClass_UInterface_UI_ContextMenuSource.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInterface_UI_ContextMenuSource.OuterSingleton, Z_Construct_UClass_UInterface_UI_ContextMenuSource_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInterface_UI_ContextMenuSource.OuterSingleton;
	}
	template<> VH_UI_API UClass* StaticClass<UInterface_UI_ContextMenuSource>()
	{
		return UInterface_UI_ContextMenuSource::StaticClass();
	}
	UInterface_UI_ContextMenuSource::UInterface_UI_ContextMenuSource(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInterface_UI_ContextMenuSource);
	UInterface_UI_ContextMenuSource::~UInterface_UI_ContextMenuSource() {}
	static FName NAME_UInterface_UI_ContextMenuSource_GetContextMenuClass = FName(TEXT("GetContextMenuClass"));
	void IInterface_UI_ContextMenuSource::Execute_GetContextMenuClass(UObject* O, TSubclassOf<UUserWidget> & contextMenuClass)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_UI_ContextMenuSource::StaticClass()));
		Interface_UI_ContextMenuSource_eventGetContextMenuClass_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_UI_ContextMenuSource_GetContextMenuClass);
		if (Func)
		{
			Parms.contextMenuClass=contextMenuClass;
			O->ProcessEvent(Func, &Parms);
			contextMenuClass=Parms.contextMenuClass;
		}
		else if (auto I = (IInterface_UI_ContextMenuSource*)(O->GetNativeInterfaceAddress(UInterface_UI_ContextMenuSource::StaticClass())))
		{
			I->GetContextMenuClass_Implementation(contextMenuClass);
		}
	}
	static FName NAME_UInterface_UI_ContextMenuSource_GetContextOptionClasses = FName(TEXT("GetContextOptionClasses"));
	void IInterface_UI_ContextMenuSource::Execute_GetContextOptionClasses(UObject* O, TSet<TSubclassOf<UObject> >& contextOptionClasses)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_UI_ContextMenuSource::StaticClass()));
		Interface_UI_ContextMenuSource_eventGetContextOptionClasses_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_UI_ContextMenuSource_GetContextOptionClasses);
		if (Func)
		{
			Parms.contextOptionClasses=contextOptionClasses;
			O->ProcessEvent(Func, &Parms);
			contextOptionClasses=Parms.contextOptionClasses;
		}
		else if (auto I = (IInterface_UI_ContextMenuSource*)(O->GetNativeInterfaceAddress(UInterface_UI_ContextMenuSource::StaticClass())))
		{
			I->GetContextOptionClasses_Implementation(contextOptionClasses);
		}
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuSource_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuSource_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInterface_UI_ContextMenuSource, UInterface_UI_ContextMenuSource::StaticClass, TEXT("UInterface_UI_ContextMenuSource"), &Z_Registration_Info_UClass_UInterface_UI_ContextMenuSource, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInterface_UI_ContextMenuSource), 1466779540U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuSource_h_2711482646(TEXT("/Script/VH_UI"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuSource_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_ContextMenuSource_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
