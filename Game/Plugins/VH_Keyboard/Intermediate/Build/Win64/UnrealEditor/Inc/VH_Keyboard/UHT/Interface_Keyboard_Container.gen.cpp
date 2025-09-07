// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Core/Public/Interface_Keyboard_Container.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInterface_Keyboard_Container() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	UPackage* Z_Construct_UPackage__Script_VH_Keyboard();
	VH_KEYBOARD_API UClass* Z_Construct_UClass_UInterface_Keyboard_Container();
	VH_KEYBOARD_API UClass* Z_Construct_UClass_UInterface_Keyboard_Container_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(IInterface_Keyboard_Container::execInitializeForObject)
	{
		P_GET_OBJECT(UObject,Z_Param_object);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InitializeForObject_Implementation(Z_Param_object);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_Keyboard_Container::execInitializeAtTransform)
	{
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InitializeAtTransform_Implementation(Z_Param_Out_transform);
		P_NATIVE_END;
	}
	struct Interface_Keyboard_Container_eventInitializeAtTransform_Parms
	{
		FTransform transform;
	};
	struct Interface_Keyboard_Container_eventInitializeForObject_Parms
	{
		UObject* object;
	};
	void IInterface_Keyboard_Container::InitializeAtTransform(FTransform const& transform)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_InitializeAtTransform instead.");
	}
	void IInterface_Keyboard_Container::InitializeForObject(UObject* object)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_InitializeForObject instead.");
	}
	void UInterface_Keyboard_Container::StaticRegisterNativesUInterface_Keyboard_Container()
	{
		UClass* Class = UInterface_Keyboard_Container::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "InitializeAtTransform", &IInterface_Keyboard_Container::execInitializeAtTransform },
			{ "InitializeForObject", &IInterface_Keyboard_Container::execInitializeForObject },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_transform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_transform;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform_Statics::NewProp_transform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform_Statics::NewProp_transform = { "transform", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_Keyboard_Container_eventInitializeAtTransform_Parms, transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform_Statics::NewProp_transform_MetaData), Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform_Statics::NewProp_transform_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform_Statics::NewProp_transform,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \n\x09* \\brief Called to initialize keyboard at a given transform\n\x09* \\param transform Transform to initialize keyboard to\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_Keyboard_Container.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Called to initialize keyboard at a given transform\n* \\param transform Transform to initialize keyboard to" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_Keyboard_Container, nullptr, "InitializeAtTransform", nullptr, nullptr, Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform_Statics::PropPointers), sizeof(Interface_Keyboard_Container_eventInitializeAtTransform_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08C20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_Keyboard_Container_eventInitializeAtTransform_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeForObject_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_object;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeForObject_Statics::NewProp_object = { "object", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_Keyboard_Container_eventInitializeForObject_Parms, object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeForObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeForObject_Statics::NewProp_object,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeForObject_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Called to initialize keyboard for a given object\n\x09* \\param object Object to initialize keyboard to\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_Keyboard_Container.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Called to initialize keyboard for a given object\n* \\param object Object to initialize keyboard to" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeForObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_Keyboard_Container, nullptr, "InitializeForObject", nullptr, nullptr, Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeForObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeForObject_Statics::PropPointers), sizeof(Interface_Keyboard_Container_eventInitializeForObject_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeForObject_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeForObject_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeForObject_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_Keyboard_Container_eventInitializeForObject_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeForObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeForObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInterface_Keyboard_Container);
	UClass* Z_Construct_UClass_UInterface_Keyboard_Container_NoRegister()
	{
		return UInterface_Keyboard_Container::StaticClass();
	}
	struct Z_Construct_UClass_UInterface_Keyboard_Container_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInterface_Keyboard_Container_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Keyboard,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_Keyboard_Container_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UInterface_Keyboard_Container_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeAtTransform, "InitializeAtTransform" }, // 3448968263
		{ &Z_Construct_UFunction_UInterface_Keyboard_Container_InitializeForObject, "InitializeForObject" }, // 2934935122
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_Keyboard_Container_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInterface_Keyboard_Container_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Public/Interface_Keyboard_Container.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInterface_Keyboard_Container_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInterface_Keyboard_Container>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInterface_Keyboard_Container_Statics::ClassParams = {
		&UInterface_Keyboard_Container::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_Keyboard_Container_Statics::Class_MetaDataParams), Z_Construct_UClass_UInterface_Keyboard_Container_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UInterface_Keyboard_Container()
	{
		if (!Z_Registration_Info_UClass_UInterface_Keyboard_Container.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInterface_Keyboard_Container.OuterSingleton, Z_Construct_UClass_UInterface_Keyboard_Container_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInterface_Keyboard_Container.OuterSingleton;
	}
	template<> VH_KEYBOARD_API UClass* StaticClass<UInterface_Keyboard_Container>()
	{
		return UInterface_Keyboard_Container::StaticClass();
	}
	UInterface_Keyboard_Container::UInterface_Keyboard_Container(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInterface_Keyboard_Container);
	UInterface_Keyboard_Container::~UInterface_Keyboard_Container() {}
	static FName NAME_UInterface_Keyboard_Container_InitializeAtTransform = FName(TEXT("InitializeAtTransform"));
	void IInterface_Keyboard_Container::Execute_InitializeAtTransform(UObject* O, FTransform const& transform)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_Keyboard_Container::StaticClass()));
		Interface_Keyboard_Container_eventInitializeAtTransform_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_Keyboard_Container_InitializeAtTransform);
		if (Func)
		{
			Parms.transform=transform;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInterface_Keyboard_Container*)(O->GetNativeInterfaceAddress(UInterface_Keyboard_Container::StaticClass())))
		{
			I->InitializeAtTransform_Implementation(transform);
		}
	}
	static FName NAME_UInterface_Keyboard_Container_InitializeForObject = FName(TEXT("InitializeForObject"));
	void IInterface_Keyboard_Container::Execute_InitializeForObject(UObject* O, UObject* object)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_Keyboard_Container::StaticClass()));
		Interface_Keyboard_Container_eventInitializeForObject_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_Keyboard_Container_InitializeForObject);
		if (Func)
		{
			Parms.object=object;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInterface_Keyboard_Container*)(O->GetNativeInterfaceAddress(UInterface_Keyboard_Container::StaticClass())))
		{
			I->InitializeForObject_Implementation(object);
		}
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInterface_Keyboard_Container, UInterface_Keyboard_Container::StaticClass, TEXT("UInterface_Keyboard_Container"), &Z_Registration_Info_UClass_UInterface_Keyboard_Container, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInterface_Keyboard_Container), 1527791843U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_336903939(TEXT("/Script/VH_Keyboard"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Core_Public_Interface_Keyboard_Container_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
