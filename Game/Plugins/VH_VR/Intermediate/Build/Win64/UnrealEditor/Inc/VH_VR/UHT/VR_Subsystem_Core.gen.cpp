// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Subsystems/Public/VR_Subsystem_Core.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVR_Subsystem_Core() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	UPackage* Z_Construct_UPackage__Script_VH_VR();
	VH_DEVELOPER_API UEnum* Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode();
	VH_VR_API UClass* Z_Construct_UClass_UVR_Subsystem_Core();
	VH_VR_API UClass* Z_Construct_UClass_UVR_Subsystem_Core_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UVR_Subsystem_Core::execHandleHardwareInterfaceModeChanged)
	{
		P_GET_ENUM(EHardwareInterfaceMode,Z_Param_newMode);
		P_GET_ENUM(EHardwareInterfaceMode,Z_Param_previousMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode(Z_Param_newMode),EHardwareInterfaceMode(Z_Param_previousMode));
		P_NATIVE_END;
	}
	void UVR_Subsystem_Core::StaticRegisterNativesUVR_Subsystem_Core()
	{
		UClass* Class = UVR_Subsystem_Core::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "HandleHardwareInterfaceModeChanged", &UVR_Subsystem_Core::execHandleHardwareInterfaceModeChanged },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics
	{
		struct VR_Subsystem_Core_eventHandleHardwareInterfaceModeChanged_Parms
		{
			EHardwareInterfaceMode newMode;
			EHardwareInterfaceMode previousMode;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_newMode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_newMode;
		static const UECodeGen_Private::FBytePropertyParams NewProp_previousMode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_previousMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::NewProp_newMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::NewProp_newMode = { "newMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_Subsystem_Core_eventHandleHardwareInterfaceModeChanged_Parms, newMode), Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode, METADATA_PARAMS(0, nullptr) }; // 2688149405
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::NewProp_previousMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::NewProp_previousMode = { "previousMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_Subsystem_Core_eventHandleHardwareInterfaceModeChanged_Parms, previousMode), Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode, METADATA_PARAMS(0, nullptr) }; // 2688149405
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::NewProp_newMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::NewProp_newMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::NewProp_previousMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::NewProp_previousMode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/VR_Subsystem_Core.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_Subsystem_Core, nullptr, "HandleHardwareInterfaceModeChanged", nullptr, nullptr, Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::VR_Subsystem_Core_eventHandleHardwareInterfaceModeChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::VR_Subsystem_Core_eventHandleHardwareInterfaceModeChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVR_Subsystem_Core);
	UClass* Z_Construct_UClass_UVR_Subsystem_Core_NoRegister()
	{
		return UVR_Subsystem_Core::StaticClass();
	}
	struct Z_Construct_UClass_UVR_Subsystem_Core_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVR_Subsystem_Core_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_VR,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_Subsystem_Core_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVR_Subsystem_Core_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVR_Subsystem_Core_HandleHardwareInterfaceModeChanged, "HandleHardwareInterfaceModeChanged" }, // 836511087
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_Subsystem_Core_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_Subsystem_Core_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Subsystems/Public/VR_Subsystem_Core.h" },
		{ "ModuleRelativePath", "Subsystems/Public/VR_Subsystem_Core.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVR_Subsystem_Core_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVR_Subsystem_Core>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVR_Subsystem_Core_Statics::ClassParams = {
		&UVR_Subsystem_Core::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_Subsystem_Core_Statics::Class_MetaDataParams), Z_Construct_UClass_UVR_Subsystem_Core_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UVR_Subsystem_Core()
	{
		if (!Z_Registration_Info_UClass_UVR_Subsystem_Core.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVR_Subsystem_Core.OuterSingleton, Z_Construct_UClass_UVR_Subsystem_Core_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVR_Subsystem_Core.OuterSingleton;
	}
	template<> VH_VR_API UClass* StaticClass<UVR_Subsystem_Core>()
	{
		return UVR_Subsystem_Core::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVR_Subsystem_Core);
	UVR_Subsystem_Core::~UVR_Subsystem_Core() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Subsystems_Public_VR_Subsystem_Core_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Subsystems_Public_VR_Subsystem_Core_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVR_Subsystem_Core, UVR_Subsystem_Core::StaticClass, TEXT("UVR_Subsystem_Core"), &Z_Registration_Info_UClass_UVR_Subsystem_Core, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVR_Subsystem_Core), 2328883925U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Subsystems_Public_VR_Subsystem_Core_h_559878605(TEXT("/Script/VH_VR"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Subsystems_Public_VR_Subsystem_Core_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Subsystems_Public_VR_Subsystem_Core_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
