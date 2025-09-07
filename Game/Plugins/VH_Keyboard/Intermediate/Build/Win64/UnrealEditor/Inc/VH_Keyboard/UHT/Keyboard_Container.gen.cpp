// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Examples/Public/Keyboard_Container.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKeyboard_Container() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_VH_Keyboard();
	VH_KEYBOARD_API UClass* Z_Construct_UClass_AKeyboard_Container();
	VH_KEYBOARD_API UClass* Z_Construct_UClass_AKeyboard_Container_NoRegister();
	VH_KEYBOARD_API UClass* Z_Construct_UClass_UInterface_Keyboard_Container_NoRegister();
	VH_KEYBOARD_API UClass* Z_Construct_UClass_UKeyboard_ContainerComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AKeyboard_Container::execGetFocusedWidgetText)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetFocusedWidgetText();
		P_NATIVE_END;
	}
	void AKeyboard_Container::StaticRegisterNativesAKeyboard_Container()
	{
		UClass* Class = AKeyboard_Container::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetFocusedWidgetText", &AKeyboard_Container::execGetFocusedWidgetText },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AKeyboard_Container_GetFocusedWidgetText_Statics
	{
		struct Keyboard_Container_eventGetFocusedWidgetText_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AKeyboard_Container_GetFocusedWidgetText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Keyboard_Container_eventGetFocusedWidgetText_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AKeyboard_Container_GetFocusedWidgetText_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AKeyboard_Container_GetFocusedWidgetText_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AKeyboard_Container_GetFocusedWidgetText_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Examples/Public/Keyboard_Container.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AKeyboard_Container_GetFocusedWidgetText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AKeyboard_Container, nullptr, "GetFocusedWidgetText", nullptr, nullptr, Z_Construct_UFunction_AKeyboard_Container_GetFocusedWidgetText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AKeyboard_Container_GetFocusedWidgetText_Statics::PropPointers), sizeof(Z_Construct_UFunction_AKeyboard_Container_GetFocusedWidgetText_Statics::Keyboard_Container_eventGetFocusedWidgetText_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AKeyboard_Container_GetFocusedWidgetText_Statics::Function_MetaDataParams), Z_Construct_UFunction_AKeyboard_Container_GetFocusedWidgetText_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AKeyboard_Container_GetFocusedWidgetText_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AKeyboard_Container_GetFocusedWidgetText_Statics::Keyboard_Container_eventGetFocusedWidgetText_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AKeyboard_Container_GetFocusedWidgetText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AKeyboard_Container_GetFocusedWidgetText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AKeyboard_Container);
	UClass* Z_Construct_UClass_AKeyboard_Container_NoRegister()
	{
		return AKeyboard_Container::StaticClass();
	}
	struct Z_Construct_UClass_AKeyboard_Container_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ContainerComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ContainerComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpawnRelativeLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnRelativeLocation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AKeyboard_Container_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Keyboard,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AKeyboard_Container_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AKeyboard_Container_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AKeyboard_Container_GetFocusedWidgetText, "GetFocusedWidgetText" }, // 2365533929
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AKeyboard_Container_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKeyboard_Container_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Examples/Public/Keyboard_Container.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Examples/Public/Keyboard_Container.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKeyboard_Container_Statics::NewProp_ContainerComponent_MetaData[] = {
		{ "Category", "Keyboard_Container" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Examples/Public/Keyboard_Container.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AKeyboard_Container_Statics::NewProp_ContainerComponent = { "ContainerComponent", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AKeyboard_Container, ContainerComponent), Z_Construct_UClass_UKeyboard_ContainerComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AKeyboard_Container_Statics::NewProp_ContainerComponent_MetaData), Z_Construct_UClass_AKeyboard_Container_Statics::NewProp_ContainerComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AKeyboard_Container_Statics::NewProp_SpawnRelativeLocation_MetaData[] = {
		{ "Category", "Keyboard_Container" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* from player viewpoint */" },
#endif
		{ "ModuleRelativePath", "Examples/Public/Keyboard_Container.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "from player viewpoint" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AKeyboard_Container_Statics::NewProp_SpawnRelativeLocation = { "SpawnRelativeLocation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AKeyboard_Container, SpawnRelativeLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AKeyboard_Container_Statics::NewProp_SpawnRelativeLocation_MetaData), Z_Construct_UClass_AKeyboard_Container_Statics::NewProp_SpawnRelativeLocation_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AKeyboard_Container_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AKeyboard_Container_Statics::NewProp_ContainerComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AKeyboard_Container_Statics::NewProp_SpawnRelativeLocation,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AKeyboard_Container_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UInterface_Keyboard_Container_NoRegister, (int32)VTABLE_OFFSET(AKeyboard_Container, IInterface_Keyboard_Container), false },  // 1527791843
		};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AKeyboard_Container_Statics::InterfaceParams) < 64);
	const FCppClassTypeInfoStatic Z_Construct_UClass_AKeyboard_Container_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AKeyboard_Container>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AKeyboard_Container_Statics::ClassParams = {
		&AKeyboard_Container::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AKeyboard_Container_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AKeyboard_Container_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AKeyboard_Container_Statics::Class_MetaDataParams), Z_Construct_UClass_AKeyboard_Container_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AKeyboard_Container_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AKeyboard_Container()
	{
		if (!Z_Registration_Info_UClass_AKeyboard_Container.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AKeyboard_Container.OuterSingleton, Z_Construct_UClass_AKeyboard_Container_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AKeyboard_Container.OuterSingleton;
	}
	template<> VH_KEYBOARD_API UClass* StaticClass<AKeyboard_Container>()
	{
		return AKeyboard_Container::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AKeyboard_Container);
	AKeyboard_Container::~AKeyboard_Container() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_Keyboard_Container_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_Keyboard_Container_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AKeyboard_Container, AKeyboard_Container::StaticClass, TEXT("AKeyboard_Container"), &Z_Registration_Info_UClass_AKeyboard_Container, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AKeyboard_Container), 1192126409U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_Keyboard_Container_h_1211617898(TEXT("/Script/VH_Keyboard"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_Keyboard_Container_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Keyboard_Source_VH_Keyboard_Examples_Public_Keyboard_Container_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
