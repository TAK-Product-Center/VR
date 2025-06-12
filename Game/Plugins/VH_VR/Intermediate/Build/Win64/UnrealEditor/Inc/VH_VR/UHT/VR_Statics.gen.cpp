// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Core/Public/VR_Statics.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVR_Statics() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UMG_API UClass* Z_Construct_UClass_UWidgetInteractionComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_VR();
	VH_VR_API UClass* Z_Construct_UClass_UVR_Statics();
	VH_VR_API UClass* Z_Construct_UClass_UVR_Statics_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UVR_Statics::execIsUsingHMD)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UVR_Statics::IsUsingHMD();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_Statics::execSetWidgetInteractionIndices)
	{
		P_GET_OBJECT(UWidgetInteractionComponent,Z_Param_widgetInteractionComponent);
		P_FINISH;
		P_NATIVE_BEGIN;
		UVR_Statics::SetWidgetInteractionIndices(Z_Param_widgetInteractionComponent);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_Statics::execGetUniqueIndex)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UVR_Statics::GetUniqueIndex();
		P_NATIVE_END;
	}
	void UVR_Statics::StaticRegisterNativesUVR_Statics()
	{
		UClass* Class = UVR_Statics::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetUniqueIndex", &UVR_Statics::execGetUniqueIndex },
			{ "IsUsingHMD", &UVR_Statics::execIsUsingHMD },
			{ "SetWidgetInteractionIndices", &UVR_Statics::execSetWidgetInteractionIndices },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVR_Statics_GetUniqueIndex_Statics
	{
		struct VR_Statics_eventGetUniqueIndex_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UVR_Statics_GetUniqueIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_Statics_eventGetUniqueIndex_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_Statics_GetUniqueIndex_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_Statics_GetUniqueIndex_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_Statics_GetUniqueIndex_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/VR_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_Statics_GetUniqueIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_Statics, nullptr, "GetUniqueIndex", nullptr, nullptr, Z_Construct_UFunction_UVR_Statics_GetUniqueIndex_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_Statics_GetUniqueIndex_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVR_Statics_GetUniqueIndex_Statics::VR_Statics_eventGetUniqueIndex_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_Statics_GetUniqueIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_Statics_GetUniqueIndex_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_Statics_GetUniqueIndex_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVR_Statics_GetUniqueIndex_Statics::VR_Statics_eventGetUniqueIndex_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_Statics_GetUniqueIndex()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_Statics_GetUniqueIndex_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_Statics_IsUsingHMD_Statics
	{
		struct VR_Statics_eventIsUsingHMD_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVR_Statics_IsUsingHMD_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VR_Statics_eventIsUsingHMD_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVR_Statics_IsUsingHMD_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VR_Statics_eventIsUsingHMD_Parms), &Z_Construct_UFunction_UVR_Statics_IsUsingHMD_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_Statics_IsUsingHMD_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_Statics_IsUsingHMD_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_Statics_IsUsingHMD_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/VR_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_Statics_IsUsingHMD_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_Statics, nullptr, "IsUsingHMD", nullptr, nullptr, Z_Construct_UFunction_UVR_Statics_IsUsingHMD_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_Statics_IsUsingHMD_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVR_Statics_IsUsingHMD_Statics::VR_Statics_eventIsUsingHMD_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_Statics_IsUsingHMD_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_Statics_IsUsingHMD_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_Statics_IsUsingHMD_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVR_Statics_IsUsingHMD_Statics::VR_Statics_eventIsUsingHMD_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_Statics_IsUsingHMD()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_Statics_IsUsingHMD_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics
	{
		struct VR_Statics_eventSetWidgetInteractionIndices_Parms
		{
			UWidgetInteractionComponent* widgetInteractionComponent;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_widgetInteractionComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_widgetInteractionComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics::NewProp_widgetInteractionComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics::NewProp_widgetInteractionComponent = { "widgetInteractionComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_Statics_eventSetWidgetInteractionIndices_Parms, widgetInteractionComponent), Z_Construct_UClass_UWidgetInteractionComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics::NewProp_widgetInteractionComponent_MetaData), Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics::NewProp_widgetInteractionComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics::NewProp_widgetInteractionComponent,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/VR_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_Statics, nullptr, "SetWidgetInteractionIndices", nullptr, nullptr, Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics::VR_Statics_eventSetWidgetInteractionIndices_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics::VR_Statics_eventSetWidgetInteractionIndices_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVR_Statics);
	UClass* Z_Construct_UClass_UVR_Statics_NoRegister()
	{
		return UVR_Statics::StaticClass();
	}
	struct Z_Construct_UClass_UVR_Statics_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVR_Statics_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_VR,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_Statics_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVR_Statics_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVR_Statics_GetUniqueIndex, "GetUniqueIndex" }, // 3961610393
		{ &Z_Construct_UFunction_UVR_Statics_IsUsingHMD, "IsUsingHMD" }, // 1564570094
		{ &Z_Construct_UFunction_UVR_Statics_SetWidgetInteractionIndices, "SetWidgetInteractionIndices" }, // 3358417846
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_Statics_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_Statics_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Core/Public/VR_Statics.h" },
		{ "ModuleRelativePath", "Core/Public/VR_Statics.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVR_Statics_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVR_Statics>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVR_Statics_Statics::ClassParams = {
		&UVR_Statics::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_Statics_Statics::Class_MetaDataParams), Z_Construct_UClass_UVR_Statics_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UVR_Statics()
	{
		if (!Z_Registration_Info_UClass_UVR_Statics.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVR_Statics.OuterSingleton, Z_Construct_UClass_UVR_Statics_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVR_Statics.OuterSingleton;
	}
	template<> VH_VR_API UClass* StaticClass<UVR_Statics>()
	{
		return UVR_Statics::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVR_Statics);
	UVR_Statics::~UVR_Statics() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_VR_Statics_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_VR_Statics_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVR_Statics, UVR_Statics::StaticClass, TEXT("UVR_Statics"), &Z_Registration_Info_UClass_UVR_Statics, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVR_Statics), 3548290826U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_VR_Statics_h_1144365534(TEXT("/Script/VH_VR"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_VR_Statics_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_VR_Statics_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
