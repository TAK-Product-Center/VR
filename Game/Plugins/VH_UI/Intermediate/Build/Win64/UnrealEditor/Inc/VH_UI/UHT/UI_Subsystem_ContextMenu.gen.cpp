// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Subsystems/Public/UI_Subsystem_ContextMenu.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_Subsystem_ContextMenu() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_UI();
	VH_UI_API UClass* Z_Construct_UClass_UUI_Subsystem_ContextMenu();
	VH_UI_API UClass* Z_Construct_UClass_UUI_Subsystem_ContextMenu_NoRegister();
	VH_UI_API UClass* Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_NoRegister();
	VH_UI_API UScriptStruct* Z_Construct_UScriptStruct_FContextOptionClasses();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ContextOptionClasses;
class UScriptStruct* FContextOptionClasses::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ContextOptionClasses.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ContextOptionClasses.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FContextOptionClasses, (UObject*)Z_Construct_UPackage__Script_VH_UI(), TEXT("ContextOptionClasses"));
	}
	return Z_Registration_Info_UScriptStruct_ContextOptionClasses.OuterSingleton;
}
template<> VH_UI_API UScriptStruct* StaticStruct<FContextOptionClasses>()
{
	return FContextOptionClasses::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FContextOptionClasses_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FClassPropertyParams NewProp_ContextOptionClasses_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ContextOptionClasses_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_ContextOptionClasses;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FContextOptionClasses_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FContextOptionClasses_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FContextOptionClasses>();
	}
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FContextOptionClasses_Statics::NewProp_ContextOptionClasses_ElementProp = { "ContextOptionClasses", nullptr, (EPropertyFlags)0x0004000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FContextOptionClasses_Statics::NewProp_ContextOptionClasses_MetaData[] = {
		{ "Category", "ContextOptionClasses" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UScriptStruct_FContextOptionClasses_Statics::NewProp_ContextOptionClasses = { "ContextOptionClasses", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FContextOptionClasses, ContextOptionClasses), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FContextOptionClasses_Statics::NewProp_ContextOptionClasses_MetaData), Z_Construct_UScriptStruct_FContextOptionClasses_Statics::NewProp_ContextOptionClasses_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FContextOptionClasses_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FContextOptionClasses_Statics::NewProp_ContextOptionClasses_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FContextOptionClasses_Statics::NewProp_ContextOptionClasses,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FContextOptionClasses_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
		nullptr,
		&NewStructOps,
		"ContextOptionClasses",
		Z_Construct_UScriptStruct_FContextOptionClasses_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FContextOptionClasses_Statics::PropPointers),
		sizeof(FContextOptionClasses),
		alignof(FContextOptionClasses),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FContextOptionClasses_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FContextOptionClasses_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FContextOptionClasses_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FContextOptionClasses()
	{
		if (!Z_Registration_Info_UScriptStruct_ContextOptionClasses.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ContextOptionClasses.InnerSingleton, Z_Construct_UScriptStruct_FContextOptionClasses_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ContextOptionClasses.InnerSingleton;
	}
	DEFINE_FUNCTION(UUI_Subsystem_ContextMenu::execHandleUserWidgetClosed)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_userWidget);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleUserWidgetClosed(Z_Param_userWidget);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_ContextMenu::execCloseContextMenusOfClass)
	{
		P_GET_OBJECT(UClass,Z_Param_contextMenuClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloseContextMenusOfClass(Z_Param_contextMenuClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_ContextMenu::execCloseContextMenusForClass)
	{
		P_GET_OBJECT(UClass,Z_Param_sourceClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloseContextMenusForClass(Z_Param_sourceClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_ContextMenu::execRegisterContextMenu)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_contextMenu);
		P_GET_OBJECT(UObject,Z_Param_source);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RegisterContextMenu(Z_Param_contextMenu,Z_Param_source);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_ContextMenu::execGetSourceFromContextMenu)
	{
		P_GET_OBJECT(UUserWidget,Z_Param_contextMenu);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UObject**)Z_Param__Result=P_THIS->GetSourceFromContextMenu(Z_Param_contextMenu);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_ContextMenu::execGetContextMenuFromSource)
	{
		P_GET_OBJECT(UObject,Z_Param_source);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UUserWidget**)Z_Param__Result=P_THIS->GetContextMenuFromSource(Z_Param_source);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_ContextMenu::execGetContextOptions)
	{
		P_GET_OBJECT(AActor,Z_Param_instigator);
		P_GET_OBJECT(UObject,Z_Param_source);
		P_GET_TSET_REF(UObject*,Z_Param_Out_contextOptions);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetContextOptions(Z_Param_instigator,Z_Param_source,Z_Param_Out_contextOptions);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_ContextMenu::execOpenContextMenuWithDefaults)
	{
		P_GET_OBJECT(AActor,Z_Param_instigator);
		P_GET_OBJECT(UObject,Z_Param_source);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UUserWidget**)Z_Param__Result=P_THIS->OpenContextMenuWithDefaults(Z_Param_instigator,Z_Param_source);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUI_Subsystem_ContextMenu::execUpdateSettings)
	{
		P_GET_OBJECT(UClass,Z_Param_settingsClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateSettings(Z_Param_settingsClass);
		P_NATIVE_END;
	}
	void UUI_Subsystem_ContextMenu::StaticRegisterNativesUUI_Subsystem_ContextMenu()
	{
		UClass* Class = UUI_Subsystem_ContextMenu::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CloseContextMenusForClass", &UUI_Subsystem_ContextMenu::execCloseContextMenusForClass },
			{ "CloseContextMenusOfClass", &UUI_Subsystem_ContextMenu::execCloseContextMenusOfClass },
			{ "GetContextMenuFromSource", &UUI_Subsystem_ContextMenu::execGetContextMenuFromSource },
			{ "GetContextOptions", &UUI_Subsystem_ContextMenu::execGetContextOptions },
			{ "GetSourceFromContextMenu", &UUI_Subsystem_ContextMenu::execGetSourceFromContextMenu },
			{ "HandleUserWidgetClosed", &UUI_Subsystem_ContextMenu::execHandleUserWidgetClosed },
			{ "OpenContextMenuWithDefaults", &UUI_Subsystem_ContextMenu::execOpenContextMenuWithDefaults },
			{ "RegisterContextMenu", &UUI_Subsystem_ContextMenu::execRegisterContextMenu },
			{ "UpdateSettings", &UUI_Subsystem_ContextMenu::execUpdateSettings },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusForClass_Statics
	{
		struct UI_Subsystem_ContextMenu_eventCloseContextMenusForClass_Parms
		{
			TSubclassOf<UObject>  sourceClass;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_sourceClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusForClass_Statics::NewProp_sourceClass = { "sourceClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_ContextMenu_eventCloseContextMenusForClass_Parms, sourceClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusForClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusForClass_Statics::NewProp_sourceClass,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusForClass_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \\brief Closes all context menus that have a source of a particular class\n\x09*  \\param sourceClass Class to search for when determining which context menus to close\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief Closes all context menus that have a source of a particular class\n      *  \\param sourceClass Class to search for when determining which context menus to close" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusForClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_ContextMenu, nullptr, "CloseContextMenusForClass", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusForClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusForClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusForClass_Statics::UI_Subsystem_ContextMenu_eventCloseContextMenusForClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusForClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusForClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusForClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusForClass_Statics::UI_Subsystem_ContextMenu_eventCloseContextMenusForClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusForClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusForClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusOfClass_Statics
	{
		struct UI_Subsystem_ContextMenu_eventCloseContextMenusOfClass_Parms
		{
			TSubclassOf<UObject>  contextMenuClass;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_contextMenuClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusOfClass_Statics::NewProp_contextMenuClass = { "contextMenuClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_ContextMenu_eventCloseContextMenusOfClass_Parms, contextMenuClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusOfClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusOfClass_Statics::NewProp_contextMenuClass,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusOfClass_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \\brief Closes all context menus of a particular class\n\x09*  \\param sourceClass Class to search for when determining which context menus to close\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief Closes all context menus of a particular class\n      *  \\param sourceClass Class to search for when determining which context menus to close" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusOfClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_ContextMenu, nullptr, "CloseContextMenusOfClass", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusOfClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusOfClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusOfClass_Statics::UI_Subsystem_ContextMenu_eventCloseContextMenusOfClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusOfClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusOfClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusOfClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusOfClass_Statics::UI_Subsystem_ContextMenu_eventCloseContextMenusOfClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusOfClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusOfClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics
	{
		struct UI_Subsystem_ContextMenu_eventGetContextMenuFromSource_Parms
		{
			UObject* source;
			UUserWidget* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_source;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::NewProp_source = { "source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_ContextMenu_eventGetContextMenuFromSource_Parms, source), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_ContextMenu_eventGetContextMenuFromSource_Parms, ReturnValue), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::NewProp_source,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_ContextMenu, nullptr, "GetContextMenuFromSource", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::UI_Subsystem_ContextMenu_eventGetContextMenuFromSource_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::UI_Subsystem_ContextMenu_eventGetContextMenuFromSource_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics
	{
		struct UI_Subsystem_ContextMenu_eventGetContextOptions_Parms
		{
			AActor* instigator;
			UObject* source;
			TSet<UObject*> contextOptions;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_instigator;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_source;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_contextOptions_ElementProp;
		static const UECodeGen_Private::FSetPropertyParams NewProp_contextOptions;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::NewProp_instigator = { "instigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_ContextMenu_eventGetContextOptions_Parms, instigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::NewProp_source = { "source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_ContextMenu_eventGetContextOptions_Parms, source), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::NewProp_contextOptions_ElementProp = { "contextOptions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::NewProp_contextOptions = { "contextOptions", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_ContextMenu_eventGetContextOptions_Parms, contextOptions), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((UI_Subsystem_ContextMenu_eventGetContextOptions_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UI_Subsystem_ContextMenu_eventGetContextOptions_Parms), &Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::NewProp_instigator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::NewProp_source,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::NewProp_contextOptions_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::NewProp_contextOptions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_ContextMenu, nullptr, "GetContextOptions", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::UI_Subsystem_ContextMenu_eventGetContextOptions_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x44420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::UI_Subsystem_ContextMenu_eventGetContextOptions_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics
	{
		struct UI_Subsystem_ContextMenu_eventGetSourceFromContextMenu_Parms
		{
			UUserWidget* contextMenu;
			UObject* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_contextMenu_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_contextMenu;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::NewProp_contextMenu_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::NewProp_contextMenu = { "contextMenu", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_ContextMenu_eventGetSourceFromContextMenu_Parms, contextMenu), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::NewProp_contextMenu_MetaData), Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::NewProp_contextMenu_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_ContextMenu_eventGetSourceFromContextMenu_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::NewProp_contextMenu,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_ContextMenu, nullptr, "GetSourceFromContextMenu", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::UI_Subsystem_ContextMenu_eventGetSourceFromContextMenu_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::UI_Subsystem_ContextMenu_eventGetSourceFromContextMenu_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics
	{
		struct UI_Subsystem_ContextMenu_eventHandleUserWidgetClosed_Parms
		{
			UUserWidget* userWidget;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_userWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_userWidget;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics::NewProp_userWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics::NewProp_userWidget = { "userWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_ContextMenu_eventHandleUserWidgetClosed_Parms, userWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics::NewProp_userWidget_MetaData), Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics::NewProp_userWidget_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics::NewProp_userWidget,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_ContextMenu, nullptr, "HandleUserWidgetClosed", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics::UI_Subsystem_ContextMenu_eventHandleUserWidgetClosed_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics::UI_Subsystem_ContextMenu_eventHandleUserWidgetClosed_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics
	{
		struct UI_Subsystem_ContextMenu_eventOpenContextMenuWithDefaults_Parms
		{
			AActor* instigator;
			UObject* source;
			UUserWidget* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_instigator;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_source;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::NewProp_instigator = { "instigator", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_ContextMenu_eventOpenContextMenuWithDefaults_Parms, instigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::NewProp_source = { "source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_ContextMenu_eventOpenContextMenuWithDefaults_Parms, source), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_ContextMenu_eventOpenContextMenuWithDefaults_Parms, ReturnValue), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::NewProp_instigator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::NewProp_source,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \\brief Opens context menu using default options based on source and contextMenuClass; calls RegisterContextMenu\n\x09*  \\note closes any existing context menus for source that are registered with this subsystem \n\x09*  \\param instigator Actor that caused the context menu to open\n\x09*  \\param source Object that was clicked on (if any) to generate the generate this option\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief Opens context menu using default options based on source and contextMenuClass; calls RegisterContextMenu\n      *  \\note closes any existing context menus for source that are registered with this subsystem\n      *  \\param instigator Actor that caused the context menu to open\n      *  \\param source Object that was clicked on (if any) to generate the generate this option" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_ContextMenu, nullptr, "OpenContextMenuWithDefaults", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::UI_Subsystem_ContextMenu_eventOpenContextMenuWithDefaults_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::UI_Subsystem_ContextMenu_eventOpenContextMenuWithDefaults_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics
	{
		struct UI_Subsystem_ContextMenu_eventRegisterContextMenu_Parms
		{
			UUserWidget* contextMenu;
			UObject* source;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_contextMenu_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_contextMenu;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_source;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::NewProp_contextMenu_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::NewProp_contextMenu = { "contextMenu", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_ContextMenu_eventRegisterContextMenu_Parms, contextMenu), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::NewProp_contextMenu_MetaData), Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::NewProp_contextMenu_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::NewProp_source = { "source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_ContextMenu_eventRegisterContextMenu_Parms, source), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::NewProp_contextMenu,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::NewProp_source,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \\brief Registers context menu for source with this subsystem. \n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\\brief Registers context menu for source with this subsystem." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_ContextMenu, nullptr, "RegisterContextMenu", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::UI_Subsystem_ContextMenu_eventRegisterContextMenu_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::UI_Subsystem_ContextMenu_eventRegisterContextMenu_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUI_Subsystem_ContextMenu_UpdateSettings_Statics
	{
		struct UI_Subsystem_ContextMenu_eventUpdateSettings_Parms
		{
			TSubclassOf<UUI_Subsystem_ContextMenu_Settings>  settingsClass;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_settingsClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_UpdateSettings_Statics::NewProp_settingsClass = { "settingsClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UI_Subsystem_ContextMenu_eventUpdateSettings_Parms, settingsClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUI_Subsystem_ContextMenu_Settings_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUI_Subsystem_ContextMenu_UpdateSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUI_Subsystem_ContextMenu_UpdateSettings_Statics::NewProp_settingsClass,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUI_Subsystem_ContextMenu_UpdateSettings_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Convenience function to set class variables\n\x09* \\param settings Settings object to use to set class variables\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Convenience function to set class variables\n* \\param settings Settings object to use to set class variables" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UUI_Subsystem_ContextMenu_UpdateSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUI_Subsystem_ContextMenu, nullptr, "UpdateSettings", nullptr, nullptr, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_UpdateSettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_UpdateSettings_Statics::PropPointers), sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_UpdateSettings_Statics::UI_Subsystem_ContextMenu_eventUpdateSettings_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_UpdateSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UUI_Subsystem_ContextMenu_UpdateSettings_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_UpdateSettings_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UUI_Subsystem_ContextMenu_UpdateSettings_Statics::UI_Subsystem_ContextMenu_eventUpdateSettings_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UUI_Subsystem_ContextMenu_UpdateSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UUI_Subsystem_ContextMenu_UpdateSettings_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUI_Subsystem_ContextMenu);
	UClass* Z_Construct_UClass_UUI_Subsystem_ContextMenu_NoRegister()
	{
		return UUI_Subsystem_ContextMenu::StaticClass();
	}
	struct Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AdditionalContextOptionsPerClass_ValueProp;
		static const UECodeGen_Private::FClassPropertyParams NewProp_AdditionalContextOptionsPerClass_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AdditionalContextOptionsPerClass_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_AdditionalContextOptionsPerClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultContextMenuClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_DefaultContextMenuClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ContextMenuCollisionChannel_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_ContextMenuCollisionChannel;
		static const UECodeGen_Private::FClassPropertyParams NewProp_UniqueContextMenuClasses_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UniqueContextMenuClasses_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_UniqueContextMenuClasses;
		static const UECodeGen_Private::FClassPropertyParams NewProp_DisabledContextOptionClasses_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DisabledContextOptionClasses_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_DisabledContextOptionClasses;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_UI,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusForClass, "CloseContextMenusForClass" }, // 1261126613
		{ &Z_Construct_UFunction_UUI_Subsystem_ContextMenu_CloseContextMenusOfClass, "CloseContextMenusOfClass" }, // 3975466333
		{ &Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextMenuFromSource, "GetContextMenuFromSource" }, // 3853049534
		{ &Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetContextOptions, "GetContextOptions" }, // 2714090726
		{ &Z_Construct_UFunction_UUI_Subsystem_ContextMenu_GetSourceFromContextMenu, "GetSourceFromContextMenu" }, // 3587313627
		{ &Z_Construct_UFunction_UUI_Subsystem_ContextMenu_HandleUserWidgetClosed, "HandleUserWidgetClosed" }, // 3089487373
		{ &Z_Construct_UFunction_UUI_Subsystem_ContextMenu_OpenContextMenuWithDefaults, "OpenContextMenuWithDefaults" }, // 2752803626
		{ &Z_Construct_UFunction_UUI_Subsystem_ContextMenu_RegisterContextMenu, "RegisterContextMenu" }, // 1224361201
		{ &Z_Construct_UFunction_UUI_Subsystem_ContextMenu_UpdateSettings, "UpdateSettings" }, // 1565269124
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_AdditionalContextOptionsPerClass_ValueProp = { "AdditionalContextOptionsPerClass", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UScriptStruct_FContextOptionClasses, METADATA_PARAMS(0, nullptr) }; // 2687691300
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_AdditionalContextOptionsPerClass_Key_KeyProp = { "AdditionalContextOptionsPerClass_Key", nullptr, (EPropertyFlags)0x0004000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_AdditionalContextOptionsPerClass_MetaData[] = {
		{ "Category", "UI_Subsystem_ContextMenu" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_AdditionalContextOptionsPerClass = { "AdditionalContextOptionsPerClass", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_ContextMenu, AdditionalContextOptionsPerClass), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_AdditionalContextOptionsPerClass_MetaData), Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_AdditionalContextOptionsPerClass_MetaData) }; // 2687691300
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_DefaultContextMenuClass_MetaData[] = {
		{ "Category", "UI_Subsystem_ContextMenu" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_DefaultContextMenuClass = { "DefaultContextMenuClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_ContextMenu, DefaultContextMenuClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_DefaultContextMenuClass_MetaData), Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_DefaultContextMenuClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_ContextMenuCollisionChannel_MetaData[] = {
		{ "Category", "UI_Subsystem_ContextMenu" },
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_ContextMenuCollisionChannel = { "ContextMenuCollisionChannel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_ContextMenu, ContextMenuCollisionChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_ContextMenuCollisionChannel_MetaData), Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_ContextMenuCollisionChannel_MetaData) }; // 1822723181
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_UniqueContextMenuClasses_ElementProp = { "UniqueContextMenuClasses", nullptr, (EPropertyFlags)0x0004000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_UniqueContextMenuClasses_MetaData[] = {
		{ "Category", "UI_Subsystem_ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief Context menu classes that should only allow one instance at a time\n" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Context menu classes that should only allow one instance at a time" },
#endif
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_UniqueContextMenuClasses = { "UniqueContextMenuClasses", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_ContextMenu, UniqueContextMenuClasses), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_UniqueContextMenuClasses_MetaData), Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_UniqueContextMenuClasses_MetaData) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_DisabledContextOptionClasses_ElementProp = { "DisabledContextOptionClasses", nullptr, (EPropertyFlags)0x0004000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_DisabledContextOptionClasses_MetaData[] = {
		{ "Category", "UI_Subsystem_ContextMenu" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/// @brief Context menu options that should not show in any context menu\n" },
#endif
		{ "ModuleRelativePath", "Subsystems/Public/UI_Subsystem_ContextMenu.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Context menu options that should not show in any context menu" },
#endif
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_DisabledContextOptionClasses = { "DisabledContextOptionClasses", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UUI_Subsystem_ContextMenu, DisabledContextOptionClasses), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_DisabledContextOptionClasses_MetaData), Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_DisabledContextOptionClasses_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_AdditionalContextOptionsPerClass_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_AdditionalContextOptionsPerClass_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_AdditionalContextOptionsPerClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_DefaultContextMenuClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_ContextMenuCollisionChannel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_UniqueContextMenuClasses_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_UniqueContextMenuClasses,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_DisabledContextOptionClasses_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::NewProp_DisabledContextOptionClasses,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_Subsystem_ContextMenu>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::ClassParams = {
		&UUI_Subsystem_ContextMenu::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::Class_MetaDataParams), Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UUI_Subsystem_ContextMenu()
	{
		if (!Z_Registration_Info_UClass_UUI_Subsystem_ContextMenu.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUI_Subsystem_ContextMenu.OuterSingleton, Z_Construct_UClass_UUI_Subsystem_ContextMenu_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUI_Subsystem_ContextMenu.OuterSingleton;
	}
	template<> VH_UI_API UClass* StaticClass<UUI_Subsystem_ContextMenu>()
	{
		return UUI_Subsystem_ContextMenu::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_Subsystem_ContextMenu);
	UUI_Subsystem_ContextMenu::~UUI_Subsystem_ContextMenu() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_Statics::ScriptStructInfo[] = {
		{ FContextOptionClasses::StaticStruct, Z_Construct_UScriptStruct_FContextOptionClasses_Statics::NewStructOps, TEXT("ContextOptionClasses"), &Z_Registration_Info_UScriptStruct_ContextOptionClasses, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FContextOptionClasses), 2687691300U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUI_Subsystem_ContextMenu, UUI_Subsystem_ContextMenu::StaticClass, TEXT("UUI_Subsystem_ContextMenu"), &Z_Registration_Info_UClass_UUI_Subsystem_ContextMenu, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUI_Subsystem_ContextMenu), 3238406516U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_3189600014(TEXT("/Script/VH_UI"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_UI_Source_VH_UI_Subsystems_Public_UI_Subsystem_ContextMenu_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
