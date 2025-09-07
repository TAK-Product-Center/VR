// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_Database_Spatialite/Public/Database_Spatialite.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDatabase_Spatialite() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VH_Database_Spatialite();
	VH_DATABASE_SPATIALITE_API UClass* Z_Construct_UClass_UDatabase_Spatialite();
	VH_DATABASE_SPATIALITE_API UClass* Z_Construct_UClass_UDatabase_Spatialite_NoRegister();
	VH_DATABASE_SPATIALITE_API UFunction* Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature();
	VH_DATABASE_SPATIALITE_API UScriptStruct* Z_Construct_UScriptStruct_FSpatialiteResult_BP();
	VH_DATABASE_SPATIALITE_API UScriptStruct* Z_Construct_UScriptStruct_FSpatialiteResults_BP();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SpatialiteResult_BP;
class UScriptStruct* FSpatialiteResult_BP::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SpatialiteResult_BP.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SpatialiteResult_BP.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSpatialiteResult_BP, (UObject*)Z_Construct_UPackage__Script_VH_Database_Spatialite(), TEXT("SpatialiteResult_BP"));
	}
	return Z_Registration_Info_UScriptStruct_SpatialiteResult_BP.OuterSingleton;
}
template<> VH_DATABASE_SPATIALITE_API UScriptStruct* StaticStruct<FSpatialiteResult_BP>()
{
	return FSpatialiteResult_BP::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSpatialiteResult_BP_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSpatialiteResult_BP_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// work-around for dynamic delegates\n" },
#endif
		{ "ModuleRelativePath", "Public/Database_Spatialite.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "work-around for dynamic delegates" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FSpatialiteResult_BP_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSpatialiteResult_BP>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSpatialiteResult_BP_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Database_Spatialite,
		nullptr,
		&NewStructOps,
		"SpatialiteResult_BP",
		nullptr,
		0,
		sizeof(FSpatialiteResult_BP),
		alignof(FSpatialiteResult_BP),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpatialiteResult_BP_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSpatialiteResult_BP_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSpatialiteResult_BP()
	{
		if (!Z_Registration_Info_UScriptStruct_SpatialiteResult_BP.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SpatialiteResult_BP.InnerSingleton, Z_Construct_UScriptStruct_FSpatialiteResult_BP_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SpatialiteResult_BP.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SpatialiteResults_BP;
class UScriptStruct* FSpatialiteResults_BP::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SpatialiteResults_BP.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SpatialiteResults_BP.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSpatialiteResults_BP, (UObject*)Z_Construct_UPackage__Script_VH_Database_Spatialite(), TEXT("SpatialiteResults_BP"));
	}
	return Z_Registration_Info_UScriptStruct_SpatialiteResults_BP.OuterSingleton;
}
template<> VH_DATABASE_SPATIALITE_API UScriptStruct* StaticStruct<FSpatialiteResults_BP>()
{
	return FSpatialiteResults_BP::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructPropertyParams NewProp_Results_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Results_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Results;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// work-around for dynamic delegates\n" },
#endif
		{ "ModuleRelativePath", "Public/Database_Spatialite.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "work-around for dynamic delegates" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSpatialiteResults_BP>();
	}
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::NewProp_Results_Inner = { "Results", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FSpatialiteResult_BP, METADATA_PARAMS(0, nullptr) }; // 3348435351
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::NewProp_Results_MetaData[] = {
		{ "Category", "SpatialiteResults_BP" },
		{ "ModuleRelativePath", "Public/Database_Spatialite.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::NewProp_Results = { "Results", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSpatialiteResults_BP, Results), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::NewProp_Results_MetaData), Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::NewProp_Results_MetaData) }; // 3348435351
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::NewProp_Results_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::NewProp_Results,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Database_Spatialite,
		nullptr,
		&NewStructOps,
		"SpatialiteResults_BP",
		Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::PropPointers),
		sizeof(FSpatialiteResults_BP),
		alignof(FSpatialiteResults_BP),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FSpatialiteResults_BP()
	{
		if (!Z_Registration_Info_UScriptStruct_SpatialiteResults_BP.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SpatialiteResults_BP.InnerSingleton, Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SpatialiteResults_BP.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics
	{
		struct Database_Spatialite_eventDBEvent_Parms
		{
			FSpatialiteResults_BP results;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_results_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_results;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics::NewProp_results_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics::NewProp_results = { "results", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventDBEvent_Parms, results), Z_Construct_UScriptStruct_FSpatialiteResults_BP, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics::NewProp_results_MetaData), Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics::NewProp_results_MetaData) }; // 16529445
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics::NewProp_results,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Database_Spatialite.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_Spatialite, nullptr, "DBEvent__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics::Database_Spatialite_eventDBEvent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics::Database_Spatialite_eventDBEvent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UDatabase_Spatialite::FDBEvent_DelegateWrapper(const FMulticastScriptDelegate& DBEvent, FSpatialiteResults_BP const& results)
{
	struct Database_Spatialite_eventDBEvent_Parms
	{
		FSpatialiteResults_BP results;
	};
	Database_Spatialite_eventDBEvent_Parms Parms;
	Parms.results=results;
	DBEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UDatabase_Spatialite::execInitialize)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Initialize();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDatabase_Spatialite::execSetString)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_columnName);
		P_GET_STRUCT_REF(FSpatialiteResult_BP,Z_Param_Out_result_BP);
		P_GET_PROPERTY(FStrProperty,Z_Param_value);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDatabase_Spatialite::SetString(Z_Param_columnName,Z_Param_Out_result_BP,Z_Param_value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDatabase_Spatialite::execGetPoint)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_columnName);
		P_GET_STRUCT_REF(FSpatialiteResult_BP,Z_Param_Out_result_BP);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<double>*)Z_Param__Result=UDatabase_Spatialite::GetPoint(Z_Param_columnName,Z_Param_Out_result_BP);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDatabase_Spatialite::execGetBlob)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_columnName);
		P_GET_STRUCT_REF(FSpatialiteResult_BP,Z_Param_Out_result_BP);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<uint8>*)Z_Param__Result=UDatabase_Spatialite::GetBlob(Z_Param_columnName,Z_Param_Out_result_BP);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDatabase_Spatialite::execGetString)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_columnName);
		P_GET_STRUCT_REF(FSpatialiteResult_BP,Z_Param_Out_result_BP);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UDatabase_Spatialite::GetString(Z_Param_columnName,Z_Param_Out_result_BP);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDatabase_Spatialite::execGetDouble)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_columnName);
		P_GET_STRUCT_REF(FSpatialiteResult_BP,Z_Param_Out_result_BP);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(double*)Z_Param__Result=UDatabase_Spatialite::GetDouble(Z_Param_columnName,Z_Param_Out_result_BP);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDatabase_Spatialite::execGetInteger64)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_columnName);
		P_GET_STRUCT_REF(FSpatialiteResult_BP,Z_Param_Out_result_BP);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=UDatabase_Spatialite::GetInteger64(Z_Param_columnName,Z_Param_Out_result_BP);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDatabase_Spatialite::execGetInteger)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_columnName);
		P_GET_STRUCT_REF(FSpatialiteResult_BP,Z_Param_Out_result_BP);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UDatabase_Spatialite::GetInteger(Z_Param_columnName,Z_Param_Out_result_BP);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDatabase_Spatialite::execGetBool)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_columnName);
		P_GET_STRUCT_REF(FSpatialiteResult_BP,Z_Param_Out_result_BP);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDatabase_Spatialite::GetBool(Z_Param_columnName,Z_Param_Out_result_BP);
		P_NATIVE_END;
	}
	void UDatabase_Spatialite::StaticRegisterNativesUDatabase_Spatialite()
	{
		UClass* Class = UDatabase_Spatialite::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetBlob", &UDatabase_Spatialite::execGetBlob },
			{ "GetBool", &UDatabase_Spatialite::execGetBool },
			{ "GetDouble", &UDatabase_Spatialite::execGetDouble },
			{ "GetInteger", &UDatabase_Spatialite::execGetInteger },
			{ "GetInteger64", &UDatabase_Spatialite::execGetInteger64 },
			{ "GetPoint", &UDatabase_Spatialite::execGetPoint },
			{ "GetString", &UDatabase_Spatialite::execGetString },
			{ "Initialize", &UDatabase_Spatialite::execInitialize },
			{ "SetString", &UDatabase_Spatialite::execSetString },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics
	{
		struct Database_Spatialite_eventGetBlob_Parms
		{
			FString columnName;
			FSpatialiteResult_BP result_BP;
			TArray<uint8> ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_columnName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_columnName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_result_BP_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_result_BP;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::NewProp_columnName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::NewProp_columnName = { "columnName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetBlob_Parms, columnName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::NewProp_columnName_MetaData), Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::NewProp_columnName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::NewProp_result_BP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::NewProp_result_BP = { "result_BP", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetBlob_Parms, result_BP), Z_Construct_UScriptStruct_FSpatialiteResult_BP, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::NewProp_result_BP_MetaData), Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::NewProp_result_BP_MetaData) }; // 3348435351
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetBlob_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::NewProp_columnName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::NewProp_result_BP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Database_Spatialite.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_Spatialite, nullptr, "GetBlob", nullptr, nullptr, Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::Database_Spatialite_eventGetBlob_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::Database_Spatialite_eventGetBlob_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDatabase_Spatialite_GetBlob()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDatabase_Spatialite_GetBlob_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics
	{
		struct Database_Spatialite_eventGetBool_Parms
		{
			FString columnName;
			FSpatialiteResult_BP result_BP;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_columnName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_columnName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_result_BP_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_result_BP;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::NewProp_columnName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::NewProp_columnName = { "columnName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetBool_Parms, columnName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::NewProp_columnName_MetaData), Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::NewProp_columnName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::NewProp_result_BP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::NewProp_result_BP = { "result_BP", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetBool_Parms, result_BP), Z_Construct_UScriptStruct_FSpatialiteResult_BP, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::NewProp_result_BP_MetaData), Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::NewProp_result_BP_MetaData) }; // 3348435351
	void Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Database_Spatialite_eventGetBool_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Database_Spatialite_eventGetBool_Parms), &Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::NewProp_columnName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::NewProp_result_BP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Database_Spatialite.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_Spatialite, nullptr, "GetBool", nullptr, nullptr, Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::Database_Spatialite_eventGetBool_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::Database_Spatialite_eventGetBool_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDatabase_Spatialite_GetBool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDatabase_Spatialite_GetBool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics
	{
		struct Database_Spatialite_eventGetDouble_Parms
		{
			FString columnName;
			FSpatialiteResult_BP result_BP;
			double ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_columnName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_columnName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_result_BP_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_result_BP;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::NewProp_columnName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::NewProp_columnName = { "columnName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetDouble_Parms, columnName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::NewProp_columnName_MetaData), Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::NewProp_columnName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::NewProp_result_BP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::NewProp_result_BP = { "result_BP", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetDouble_Parms, result_BP), Z_Construct_UScriptStruct_FSpatialiteResult_BP, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::NewProp_result_BP_MetaData), Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::NewProp_result_BP_MetaData) }; // 3348435351
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetDouble_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::NewProp_columnName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::NewProp_result_BP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Database_Spatialite.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_Spatialite, nullptr, "GetDouble", nullptr, nullptr, Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::Database_Spatialite_eventGetDouble_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::Database_Spatialite_eventGetDouble_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDatabase_Spatialite_GetDouble()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDatabase_Spatialite_GetDouble_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics
	{
		struct Database_Spatialite_eventGetInteger_Parms
		{
			FString columnName;
			FSpatialiteResult_BP result_BP;
			int32 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_columnName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_columnName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_result_BP_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_result_BP;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::NewProp_columnName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::NewProp_columnName = { "columnName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetInteger_Parms, columnName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::NewProp_columnName_MetaData), Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::NewProp_columnName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::NewProp_result_BP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::NewProp_result_BP = { "result_BP", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetInteger_Parms, result_BP), Z_Construct_UScriptStruct_FSpatialiteResult_BP, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::NewProp_result_BP_MetaData), Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::NewProp_result_BP_MetaData) }; // 3348435351
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetInteger_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::NewProp_columnName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::NewProp_result_BP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Database_Spatialite.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_Spatialite, nullptr, "GetInteger", nullptr, nullptr, Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::Database_Spatialite_eventGetInteger_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::Database_Spatialite_eventGetInteger_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDatabase_Spatialite_GetInteger()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDatabase_Spatialite_GetInteger_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics
	{
		struct Database_Spatialite_eventGetInteger64_Parms
		{
			FString columnName;
			FSpatialiteResult_BP result_BP;
			int64 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_columnName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_columnName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_result_BP_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_result_BP;
		static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::NewProp_columnName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::NewProp_columnName = { "columnName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetInteger64_Parms, columnName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::NewProp_columnName_MetaData), Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::NewProp_columnName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::NewProp_result_BP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::NewProp_result_BP = { "result_BP", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetInteger64_Parms, result_BP), Z_Construct_UScriptStruct_FSpatialiteResult_BP, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::NewProp_result_BP_MetaData), Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::NewProp_result_BP_MetaData) }; // 3348435351
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetInteger64_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::NewProp_columnName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::NewProp_result_BP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Database_Spatialite.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_Spatialite, nullptr, "GetInteger64", nullptr, nullptr, Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::Database_Spatialite_eventGetInteger64_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::Database_Spatialite_eventGetInteger64_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics
	{
		struct Database_Spatialite_eventGetPoint_Parms
		{
			FString columnName;
			FSpatialiteResult_BP result_BP;
			TArray<double> ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_columnName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_columnName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_result_BP_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_result_BP;
		static const UECodeGen_Private::FDoublePropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::NewProp_columnName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::NewProp_columnName = { "columnName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetPoint_Parms, columnName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::NewProp_columnName_MetaData), Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::NewProp_columnName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::NewProp_result_BP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::NewProp_result_BP = { "result_BP", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetPoint_Parms, result_BP), Z_Construct_UScriptStruct_FSpatialiteResult_BP, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::NewProp_result_BP_MetaData), Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::NewProp_result_BP_MetaData) }; // 3348435351
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetPoint_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::NewProp_columnName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::NewProp_result_BP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Database_Spatialite.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_Spatialite, nullptr, "GetPoint", nullptr, nullptr, Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::Database_Spatialite_eventGetPoint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::Database_Spatialite_eventGetPoint_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDatabase_Spatialite_GetPoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDatabase_Spatialite_GetPoint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics
	{
		struct Database_Spatialite_eventGetString_Parms
		{
			FString columnName;
			FSpatialiteResult_BP result_BP;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_columnName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_columnName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_result_BP_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_result_BP;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::NewProp_columnName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::NewProp_columnName = { "columnName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetString_Parms, columnName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::NewProp_columnName_MetaData), Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::NewProp_columnName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::NewProp_result_BP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::NewProp_result_BP = { "result_BP", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetString_Parms, result_BP), Z_Construct_UScriptStruct_FSpatialiteResult_BP, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::NewProp_result_BP_MetaData), Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::NewProp_result_BP_MetaData) }; // 3348435351
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventGetString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::NewProp_columnName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::NewProp_result_BP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Database_Spatialite.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_Spatialite, nullptr, "GetString", nullptr, nullptr, Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::Database_Spatialite_eventGetString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::Database_Spatialite_eventGetString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDatabase_Spatialite_GetString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDatabase_Spatialite_GetString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDatabase_Spatialite_Initialize_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_Initialize_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Database_Spatialite.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDatabase_Spatialite_Initialize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_Spatialite, nullptr, "Initialize", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_Initialize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDatabase_Spatialite_Initialize_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UDatabase_Spatialite_Initialize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDatabase_Spatialite_Initialize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics
	{
		struct Database_Spatialite_eventSetString_Parms
		{
			FString columnName;
			FSpatialiteResult_BP result_BP;
			FString value;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_columnName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_columnName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_result_BP;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_value_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::NewProp_columnName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::NewProp_columnName = { "columnName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventSetString_Parms, columnName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::NewProp_columnName_MetaData), Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::NewProp_columnName_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::NewProp_result_BP = { "result_BP", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventSetString_Parms, result_BP), Z_Construct_UScriptStruct_FSpatialiteResult_BP, METADATA_PARAMS(0, nullptr) }; // 3348435351
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::NewProp_value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_Spatialite_eventSetString_Parms, value), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::NewProp_value_MetaData), Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::NewProp_value_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::NewProp_columnName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::NewProp_result_BP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::NewProp_value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Database_Spatialite.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_Spatialite, nullptr, "SetString", nullptr, nullptr, Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::Database_Spatialite_eventSetString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::Database_Spatialite_eventSetString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDatabase_Spatialite_SetString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDatabase_Spatialite_SetString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDatabase_Spatialite);
	UClass* Z_Construct_UClass_UDatabase_Spatialite_NoRegister()
	{
		return UDatabase_Spatialite::StaticClass();
	}
	struct Z_Construct_UClass_UDatabase_Spatialite_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDatabase_Spatialite_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Database_Spatialite,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDatabase_Spatialite_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDatabase_Spatialite_Statics::FuncInfo[] = {
		{ &Z_Construct_UDelegateFunction_UDatabase_Spatialite_DBEvent__DelegateSignature, "DBEvent__DelegateSignature" }, // 1812856377
		{ &Z_Construct_UFunction_UDatabase_Spatialite_GetBlob, "GetBlob" }, // 1757790449
		{ &Z_Construct_UFunction_UDatabase_Spatialite_GetBool, "GetBool" }, // 4289881999
		{ &Z_Construct_UFunction_UDatabase_Spatialite_GetDouble, "GetDouble" }, // 2008292971
		{ &Z_Construct_UFunction_UDatabase_Spatialite_GetInteger, "GetInteger" }, // 1224092188
		{ &Z_Construct_UFunction_UDatabase_Spatialite_GetInteger64, "GetInteger64" }, // 2100316316
		{ &Z_Construct_UFunction_UDatabase_Spatialite_GetPoint, "GetPoint" }, // 4213180833
		{ &Z_Construct_UFunction_UDatabase_Spatialite_GetString, "GetString" }, // 179385625
		{ &Z_Construct_UFunction_UDatabase_Spatialite_Initialize, "Initialize" }, // 2305971087
		{ &Z_Construct_UFunction_UDatabase_Spatialite_SetString, "SetString" }, // 1144368379
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDatabase_Spatialite_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDatabase_Spatialite_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Database_Spatialite.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Database_Spatialite.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDatabase_Spatialite_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDatabase_Spatialite>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDatabase_Spatialite_Statics::ClassParams = {
		&UDatabase_Spatialite::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDatabase_Spatialite_Statics::Class_MetaDataParams), Z_Construct_UClass_UDatabase_Spatialite_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UDatabase_Spatialite()
	{
		if (!Z_Registration_Info_UClass_UDatabase_Spatialite.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDatabase_Spatialite.OuterSingleton, Z_Construct_UClass_UDatabase_Spatialite_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDatabase_Spatialite.OuterSingleton;
	}
	template<> VH_DATABASE_SPATIALITE_API UClass* StaticClass<UDatabase_Spatialite>()
	{
		return UDatabase_Spatialite::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDatabase_Spatialite);
	UDatabase_Spatialite::~UDatabase_Spatialite() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_Statics::ScriptStructInfo[] = {
		{ FSpatialiteResult_BP::StaticStruct, Z_Construct_UScriptStruct_FSpatialiteResult_BP_Statics::NewStructOps, TEXT("SpatialiteResult_BP"), &Z_Registration_Info_UScriptStruct_SpatialiteResult_BP, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSpatialiteResult_BP), 3348435351U) },
		{ FSpatialiteResults_BP::StaticStruct, Z_Construct_UScriptStruct_FSpatialiteResults_BP_Statics::NewStructOps, TEXT("SpatialiteResults_BP"), &Z_Registration_Info_UScriptStruct_SpatialiteResults_BP, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSpatialiteResults_BP), 16529445U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDatabase_Spatialite, UDatabase_Spatialite::StaticClass, TEXT("UDatabase_Spatialite"), &Z_Registration_Info_UClass_UDatabase_Spatialite, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDatabase_Spatialite), 2940776853U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_579076491(TEXT("/Script/VH_Database_Spatialite"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_Spatialite_Public_Database_Spatialite_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
