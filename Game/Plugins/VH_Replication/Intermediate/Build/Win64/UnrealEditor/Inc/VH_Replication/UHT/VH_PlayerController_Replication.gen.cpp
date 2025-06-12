// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Deprecated/Public/VH_PlayerController_Replication.h"
#include "UObject/CoreNet.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_PlayerController_Replication() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_VH_Replication();
	VH_REPLICATION_API UClass* Z_Construct_UClass_AVH_PlayerController_Replication();
	VH_REPLICATION_API UClass* Z_Construct_UClass_AVH_PlayerController_Replication_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AVH_PlayerController_Replication::execServerSetChannelReady)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_id);
		P_GET_OBJECT(AActor,Z_Param_actor);
		P_GET_UBOOL(Z_Param_bReady);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->ServerSetChannelReady_Validate(Z_Param_id,Z_Param_actor,Z_Param_bReady))
		{
			RPC_ValidateFailed(TEXT("ServerSetChannelReady_Validate"));
			return;
		}
		P_THIS->ServerSetChannelReady_Implementation(Z_Param_id,Z_Param_actor,Z_Param_bReady);
		P_NATIVE_END;
	}
	struct VH_PlayerController_Replication_eventServerSetChannelReady_Parms
	{
		int32 id;
		AActor* actor;
		bool bReady;
	};
	static FName NAME_AVH_PlayerController_Replication_ServerSetChannelReady = FName(TEXT("ServerSetChannelReady"));
	void AVH_PlayerController_Replication::ServerSetChannelReady(int32 id, AActor* actor, bool bReady)
	{
		VH_PlayerController_Replication_eventServerSetChannelReady_Parms Parms;
		Parms.id=id;
		Parms.actor=actor;
		Parms.bReady=bReady ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_AVH_PlayerController_Replication_ServerSetChannelReady),&Parms);
	}
	void AVH_PlayerController_Replication::StaticRegisterNativesAVH_PlayerController_Replication()
	{
		UClass* Class = AVH_PlayerController_Replication::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ServerSetChannelReady", &AVH_PlayerController_Replication::execServerSetChannelReady },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics
	{
		static const UECodeGen_Private::FIntPropertyParams NewProp_id;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actor;
		static void NewProp_bReady_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bReady;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::NewProp_id = { "id", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PlayerController_Replication_eventServerSetChannelReady_Parms, id), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::NewProp_actor = { "actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_PlayerController_Replication_eventServerSetChannelReady_Parms, actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::NewProp_bReady_SetBit(void* Obj)
	{
		((VH_PlayerController_Replication_eventServerSetChannelReady_Parms*)Obj)->bReady = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::NewProp_bReady = { "bReady", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_PlayerController_Replication_eventServerSetChannelReady_Parms), &Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::NewProp_bReady_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::NewProp_id,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::NewProp_actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::NewProp_bReady,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Deprecated/Public/VH_PlayerController_Replication.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_PlayerController_Replication, nullptr, "ServerSetChannelReady", nullptr, nullptr, Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::PropPointers), sizeof(VH_PlayerController_Replication_eventServerSetChannelReady_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_PlayerController_Replication_eventServerSetChannelReady_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVH_PlayerController_Replication);
	UClass* Z_Construct_UClass_AVH_PlayerController_Replication_NoRegister()
	{
		return AVH_PlayerController_Replication::StaticClass();
	}
	struct Z_Construct_UClass_AVH_PlayerController_Replication_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVH_PlayerController_Replication_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Replication,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_PlayerController_Replication_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AVH_PlayerController_Replication_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVH_PlayerController_Replication_ServerSetChannelReady, "ServerSetChannelReady" }, // 3349144566
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_PlayerController_Replication_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_PlayerController_Replication_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Deprecated/Public/VH_PlayerController_Replication.h" },
		{ "ModuleRelativePath", "Deprecated/Public/VH_PlayerController_Replication.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVH_PlayerController_Replication_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVH_PlayerController_Replication>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AVH_PlayerController_Replication_Statics::ClassParams = {
		&AVH_PlayerController_Replication::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_PlayerController_Replication_Statics::Class_MetaDataParams), Z_Construct_UClass_AVH_PlayerController_Replication_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AVH_PlayerController_Replication()
	{
		if (!Z_Registration_Info_UClass_AVH_PlayerController_Replication.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVH_PlayerController_Replication.OuterSingleton, Z_Construct_UClass_AVH_PlayerController_Replication_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AVH_PlayerController_Replication.OuterSingleton;
	}
	template<> VH_REPLICATION_API UClass* StaticClass<AVH_PlayerController_Replication>()
	{
		return AVH_PlayerController_Replication::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVH_PlayerController_Replication);
	AVH_PlayerController_Replication::~AVH_PlayerController_Replication() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AVH_PlayerController_Replication, AVH_PlayerController_Replication::StaticClass, TEXT("AVH_PlayerController_Replication"), &Z_Registration_Info_UClass_AVH_PlayerController_Replication, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVH_PlayerController_Replication), 75014029U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_2819332761(TEXT("/Script/VH_Replication"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Deprecated_Public_VH_PlayerController_Replication_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
