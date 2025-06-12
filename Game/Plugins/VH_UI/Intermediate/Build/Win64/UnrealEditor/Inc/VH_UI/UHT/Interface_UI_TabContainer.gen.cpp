// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interface_UI_TabContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInterface_UI_TabContainer() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_UI();
	VH_UI_API UClass* Z_Construct_UClass_UInterface_UI_TabContainer();
	VH_UI_API UClass* Z_Construct_UClass_UInterface_UI_TabContainer_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(IInterface_UI_TabContainer::execGetNumberOfTabs)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetNumberOfTabs_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_UI_TabContainer::execSetFocusedTab)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_tab);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetFocusedTab_Implementation(Z_Param_tab);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_UI_TabContainer::execRemoveAllTabs)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveAllTabs_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_UI_TabContainer::execRemoveTab)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_tab);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveTab_Implementation(Z_Param_tab);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_UI_TabContainer::execAddTab)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_tab);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddTab_Implementation(Z_Param_tab);
		P_NATIVE_END;
	}
	struct Interface_UI_TabContainer_eventAddTab_Parms
	{
		UUserWidget* tab;
	};
	struct Interface_UI_TabContainer_eventGetNumberOfTabs_Parms
	{
		int32 ReturnValue;

		/** Constructor, initializes return property only **/
		Interface_UI_TabContainer_eventGetNumberOfTabs_Parms()
			: ReturnValue(0)
		{
		}
	};
	struct Interface_UI_TabContainer_eventRemoveTab_Parms
	{
		UUserWidget* tab;
	};
	struct Interface_UI_TabContainer_eventSetFocusedTab_Parms
	{
		UUserWidget* tab;
	};
	void IInterface_UI_TabContainer::AddTab(UUserWidget* tab)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_AddTab instead.");
	}
	int32 IInterface_UI_TabContainer::GetNumberOfTabs() const
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetNumberOfTabs instead.");
		Interface_UI_TabContainer_eventGetNumberOfTabs_Parms Parms;
		return Parms.ReturnValue;
	}
	void IInterface_UI_TabContainer::RemoveAllTabs()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_RemoveAllTabs instead.");
	}
	void IInterface_UI_TabContainer::RemoveTab(UUserWidget* tab)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_RemoveTab instead.");
	}
	void IInterface_UI_TabContainer::SetFocusedTab(UUserWidget* tab)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_SetFocusedTab instead.");
	}
	void UInterface_UI_TabContainer::StaticRegisterNativesUInterface_UI_TabContainer()
	{
		UClass* Class = UInterface_UI_TabContainer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddTab", &IInterface_UI_TabContainer::execAddTab },
			{ "GetNumberOfTabs", &IInterface_UI_TabContainer::execGetNumberOfTabs },
			{ "RemoveAllTabs", &IInterface_UI_TabContainer::execRemoveAllTabs },
			{ "RemoveTab", &IInterface_UI_TabContainer::execRemoveTab },
			{ "SetFocusedTab", &IInterface_UI_TabContainer::execSetFocusedTab },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_tab_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_tab;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab_Statics::NewProp_tab_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab_Statics::NewProp_tab = { "tab", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_UI_TabContainer_eventAddTab_Parms, tab), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab_Statics::NewProp_tab_MetaData), Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab_Statics::NewProp_tab_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab_Statics::NewProp_tab,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Interface_UI_TabContainer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_UI_TabContainer, nullptr, "AddTab", nullptr, nullptr, Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab_Statics::PropPointers), sizeof(Interface_UI_TabContainer_eventAddTab_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_UI_TabContainer_eventAddTab_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_UI_TabContainer_GetNumberOfTabs_Statics
	{
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInterface_UI_TabContainer_GetNumberOfTabs_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_UI_TabContainer_eventGetNumberOfTabs_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_UI_TabContainer_GetNumberOfTabs_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_UI_TabContainer_GetNumberOfTabs_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_UI_TabContainer_GetNumberOfTabs_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Interface_UI_TabContainer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_UI_TabContainer_GetNumberOfTabs_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_UI_TabContainer, nullptr, "GetNumberOfTabs", nullptr, nullptr, Z_Construct_UFunction_UInterface_UI_TabContainer_GetNumberOfTabs_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_TabContainer_GetNumberOfTabs_Statics::PropPointers), sizeof(Interface_UI_TabContainer_eventGetNumberOfTabs_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x5C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_TabContainer_GetNumberOfTabs_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_UI_TabContainer_GetNumberOfTabs_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_TabContainer_GetNumberOfTabs_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_UI_TabContainer_eventGetNumberOfTabs_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_UI_TabContainer_GetNumberOfTabs()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_UI_TabContainer_GetNumberOfTabs_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveAllTabs_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveAllTabs_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Interface_UI_TabContainer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveAllTabs_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_UI_TabContainer, nullptr, "RemoveAllTabs", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveAllTabs_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveAllTabs_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveAllTabs()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveAllTabs_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_tab_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_tab;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab_Statics::NewProp_tab_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab_Statics::NewProp_tab = { "tab", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_UI_TabContainer_eventRemoveTab_Parms, tab), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab_Statics::NewProp_tab_MetaData), Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab_Statics::NewProp_tab_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab_Statics::NewProp_tab,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Interface_UI_TabContainer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_UI_TabContainer, nullptr, "RemoveTab", nullptr, nullptr, Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab_Statics::PropPointers), sizeof(Interface_UI_TabContainer_eventRemoveTab_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_UI_TabContainer_eventRemoveTab_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_tab_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_tab;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab_Statics::NewProp_tab_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab_Statics::NewProp_tab = { "tab", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_UI_TabContainer_eventSetFocusedTab_Parms, tab), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab_Statics::NewProp_tab_MetaData), Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab_Statics::NewProp_tab_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab_Statics::NewProp_tab,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Interface_UI_TabContainer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_UI_TabContainer, nullptr, "SetFocusedTab", nullptr, nullptr, Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab_Statics::PropPointers), sizeof(Interface_UI_TabContainer_eventSetFocusedTab_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_UI_TabContainer_eventSetFocusedTab_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInterface_UI_TabContainer);
	UClass* Z_Construct_UClass_UInterface_UI_TabContainer_NoRegister()
	{
		return UInterface_UI_TabContainer::StaticClass();
	}
	struct Z_Construct_UClass_UInterface_UI_TabContainer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInterface_UI_TabContainer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_UI_TabContainer_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UInterface_UI_TabContainer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInterface_UI_TabContainer_AddTab, "AddTab" }, // 2571179584
		{ &Z_Construct_UFunction_UInterface_UI_TabContainer_GetNumberOfTabs, "GetNumberOfTabs" }, // 1037587963
		{ &Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveAllTabs, "RemoveAllTabs" }, // 3319078767
		{ &Z_Construct_UFunction_UInterface_UI_TabContainer_RemoveTab, "RemoveTab" }, // 1241977599
		{ &Z_Construct_UFunction_UInterface_UI_TabContainer_SetFocusedTab, "SetFocusedTab" }, // 2602353520
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_UI_TabContainer_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInterface_UI_TabContainer_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Public/Interface_UI_TabContainer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInterface_UI_TabContainer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInterface_UI_TabContainer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInterface_UI_TabContainer_Statics::ClassParams = {
		&UInterface_UI_TabContainer::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_UI_TabContainer_Statics::Class_MetaDataParams), Z_Construct_UClass_UInterface_UI_TabContainer_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UInterface_UI_TabContainer()
	{
		if (!Z_Registration_Info_UClass_UInterface_UI_TabContainer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInterface_UI_TabContainer.OuterSingleton, Z_Construct_UClass_UInterface_UI_TabContainer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInterface_UI_TabContainer.OuterSingleton;
	}
	template<> VH_UI_API UClass* StaticClass<UInterface_UI_TabContainer>()
	{
		return UInterface_UI_TabContainer::StaticClass();
	}
	UInterface_UI_TabContainer::UInterface_UI_TabContainer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInterface_UI_TabContainer);
	UInterface_UI_TabContainer::~UInterface_UI_TabContainer() {}
	static FName NAME_UInterface_UI_TabContainer_AddTab = FName(TEXT("AddTab"));
	void IInterface_UI_TabContainer::Execute_AddTab(UObject* O, UUserWidget* tab)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_UI_TabContainer::StaticClass()));
		Interface_UI_TabContainer_eventAddTab_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_UI_TabContainer_AddTab);
		if (Func)
		{
			Parms.tab=tab;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInterface_UI_TabContainer*)(O->GetNativeInterfaceAddress(UInterface_UI_TabContainer::StaticClass())))
		{
			I->AddTab_Implementation(tab);
		}
	}
	static FName NAME_UInterface_UI_TabContainer_GetNumberOfTabs = FName(TEXT("GetNumberOfTabs"));
	int32 IInterface_UI_TabContainer::Execute_GetNumberOfTabs(const UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_UI_TabContainer::StaticClass()));
		Interface_UI_TabContainer_eventGetNumberOfTabs_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_UI_TabContainer_GetNumberOfTabs);
		if (Func)
		{
			const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (const IInterface_UI_TabContainer*)(O->GetNativeInterfaceAddress(UInterface_UI_TabContainer::StaticClass())))
		{
			Parms.ReturnValue = I->GetNumberOfTabs_Implementation();
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UInterface_UI_TabContainer_RemoveAllTabs = FName(TEXT("RemoveAllTabs"));
	void IInterface_UI_TabContainer::Execute_RemoveAllTabs(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_UI_TabContainer::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInterface_UI_TabContainer_RemoveAllTabs);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInterface_UI_TabContainer*)(O->GetNativeInterfaceAddress(UInterface_UI_TabContainer::StaticClass())))
		{
			I->RemoveAllTabs_Implementation();
		}
	}
	static FName NAME_UInterface_UI_TabContainer_RemoveTab = FName(TEXT("RemoveTab"));
	void IInterface_UI_TabContainer::Execute_RemoveTab(UObject* O, UUserWidget* tab)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_UI_TabContainer::StaticClass()));
		Interface_UI_TabContainer_eventRemoveTab_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_UI_TabContainer_RemoveTab);
		if (Func)
		{
			Parms.tab=tab;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInterface_UI_TabContainer*)(O->GetNativeInterfaceAddress(UInterface_UI_TabContainer::StaticClass())))
		{
			I->RemoveTab_Implementation(tab);
		}
	}
	static FName NAME_UInterface_UI_TabContainer_SetFocusedTab = FName(TEXT("SetFocusedTab"));
	void IInterface_UI_TabContainer::Execute_SetFocusedTab(UObject* O, UUserWidget* tab)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_UI_TabContainer::StaticClass()));
		Interface_UI_TabContainer_eventSetFocusedTab_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_UI_TabContainer_SetFocusedTab);
		if (Func)
		{
			Parms.tab=tab;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInterface_UI_TabContainer*)(O->GetNativeInterfaceAddress(UInterface_UI_TabContainer::StaticClass())))
		{
			I->SetFocusedTab_Implementation(tab);
		}
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInterface_UI_TabContainer, UInterface_UI_TabContainer::StaticClass, TEXT("UInterface_UI_TabContainer"), &Z_Registration_Info_UClass_UInterface_UI_TabContainer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInterface_UI_TabContainer), 4239301716U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_2357934564(TEXT("/Script/VH_UI"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Core_Public_Interface_UI_TabContainer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
