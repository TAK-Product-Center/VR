// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Examples/Public/Replication_ExampleActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReplication_ExampleActor() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_VH_Replication();
	VH_REPLICATION_API UClass* Z_Construct_UClass_AReplication_ExampleActor();
	VH_REPLICATION_API UClass* Z_Construct_UClass_AReplication_ExampleActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AReplication_ExampleActor::execOnRep_ReplicationID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRep_ReplicationID();
		P_NATIVE_END;
	}
	void AReplication_ExampleActor::StaticRegisterNativesAReplication_ExampleActor()
	{
		UClass* Class = AReplication_ExampleActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnRep_ReplicationID", &AReplication_ExampleActor::execOnRep_ReplicationID },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AReplication_ExampleActor_OnRep_ReplicationID_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AReplication_ExampleActor_OnRep_ReplicationID_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Examples/Public/Replication_ExampleActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AReplication_ExampleActor_OnRep_ReplicationID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AReplication_ExampleActor, nullptr, "OnRep_ReplicationID", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AReplication_ExampleActor_OnRep_ReplicationID_Statics::Function_MetaDataParams), Z_Construct_UFunction_AReplication_ExampleActor_OnRep_ReplicationID_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AReplication_ExampleActor_OnRep_ReplicationID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AReplication_ExampleActor_OnRep_ReplicationID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AReplication_ExampleActor);
	UClass* Z_Construct_UClass_AReplication_ExampleActor_NoRegister()
	{
		return AReplication_ExampleActor::StaticClass();
	}
	struct Z_Construct_UClass_AReplication_ExampleActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReplicationID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReplicationID;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AReplication_ExampleActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Replication,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AReplication_ExampleActor_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AReplication_ExampleActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AReplication_ExampleActor_OnRep_ReplicationID, "OnRep_ReplicationID" }, // 3871132413
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AReplication_ExampleActor_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AReplication_ExampleActor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Examples/Public/Replication_ExampleActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Examples/Public/Replication_ExampleActor.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AReplication_ExampleActor_Statics::NewProp_ReplicationID_MetaData[] = {
		{ "ModuleRelativePath", "Examples/Public/Replication_ExampleActor.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_AReplication_ExampleActor_Statics::NewProp_ReplicationID = { "ReplicationID", "OnRep_ReplicationID", (EPropertyFlags)0x0040000100000020, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReplication_ExampleActor, ReplicationID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AReplication_ExampleActor_Statics::NewProp_ReplicationID_MetaData), Z_Construct_UClass_AReplication_ExampleActor_Statics::NewProp_ReplicationID_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AReplication_ExampleActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReplication_ExampleActor_Statics::NewProp_ReplicationID,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AReplication_ExampleActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AReplication_ExampleActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AReplication_ExampleActor_Statics::ClassParams = {
		&AReplication_ExampleActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AReplication_ExampleActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AReplication_ExampleActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AReplication_ExampleActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AReplication_ExampleActor_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AReplication_ExampleActor_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AReplication_ExampleActor()
	{
		if (!Z_Registration_Info_UClass_AReplication_ExampleActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AReplication_ExampleActor.OuterSingleton, Z_Construct_UClass_AReplication_ExampleActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AReplication_ExampleActor.OuterSingleton;
	}
	template<> VH_REPLICATION_API UClass* StaticClass<AReplication_ExampleActor>()
	{
		return AReplication_ExampleActor::StaticClass();
	}

	void AReplication_ExampleActor::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_ReplicationID(TEXT("ReplicationID"));

		const bool bIsValid = true
			&& Name_ReplicationID == ClassReps[(int32)ENetFields_Private::ReplicationID].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AReplication_ExampleActor"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AReplication_ExampleActor);
	AReplication_ExampleActor::~AReplication_ExampleActor() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AReplication_ExampleActor, AReplication_ExampleActor::StaticClass, TEXT("AReplication_ExampleActor"), &Z_Registration_Info_UClass_AReplication_ExampleActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AReplication_ExampleActor), 2285056157U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_352982050(TEXT("/Script/VH_Replication"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Replication_Source_VH_Replication_Examples_Public_Replication_ExampleActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
