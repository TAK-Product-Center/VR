// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Database_MySQL.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDatabase_MySQL() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VH_Database_MySQL();
	VH_DATABASE_MYSQL_API UClass* Z_Construct_UClass_UDatabase_MySQL();
	VH_DATABASE_MYSQL_API UClass* Z_Construct_UClass_UDatabase_MySQL_NoRegister();
	VH_DATABASE_MYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FMySQLResult_BP();
	VH_DATABASE_MYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FMySQLResults_BP();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MySQLResult_BP;
class UScriptStruct* FMySQLResult_BP::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MySQLResult_BP.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MySQLResult_BP.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMySQLResult_BP, (UObject*)Z_Construct_UPackage__Script_VH_Database_MySQL(), TEXT("MySQLResult_BP"));
	}
	return Z_Registration_Info_UScriptStruct_MySQLResult_BP.OuterSingleton;
}
template<> VH_DATABASE_MYSQL_API UScriptStruct* StaticStruct<FMySQLResult_BP>()
{
	return FMySQLResult_BP::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FMySQLResult_BP_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMySQLResult_BP_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// work-around for dynamic delegates\n" },
#endif
		{ "ModuleRelativePath", "Core/Public/Database_MySQL.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "work-around for dynamic delegates" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FMySQLResult_BP_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMySQLResult_BP>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMySQLResult_BP_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Database_MySQL,
		nullptr,
		&NewStructOps,
		"MySQLResult_BP",
		nullptr,
		0,
		sizeof(FMySQLResult_BP),
		alignof(FMySQLResult_BP),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMySQLResult_BP_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMySQLResult_BP_Statics::Struct_MetaDataParams)
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMySQLResult_BP()
	{
		if (!Z_Registration_Info_UScriptStruct_MySQLResult_BP.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MySQLResult_BP.InnerSingleton, Z_Construct_UScriptStruct_FMySQLResult_BP_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_MySQLResult_BP.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MySQLResults_BP;
class UScriptStruct* FMySQLResults_BP::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MySQLResults_BP.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MySQLResults_BP.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMySQLResults_BP, (UObject*)Z_Construct_UPackage__Script_VH_Database_MySQL(), TEXT("MySQLResults_BP"));
	}
	return Z_Registration_Info_UScriptStruct_MySQLResults_BP.OuterSingleton;
}
template<> VH_DATABASE_MYSQL_API UScriptStruct* StaticStruct<FMySQLResults_BP>()
{
	return FMySQLResults_BP::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FMySQLResults_BP_Statics
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// work-around for dynamic delegates\n" },
#endif
		{ "ModuleRelativePath", "Core/Public/Database_MySQL.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "work-around for dynamic delegates" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMySQLResults_BP>();
	}
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::NewProp_Results_Inner = { "Results", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FMySQLResult_BP, METADATA_PARAMS(0, nullptr) }; // 3925351600
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::NewProp_Results_MetaData[] = {
		{ "Category", "MySQLResults_BP" },
		{ "ModuleRelativePath", "Core/Public/Database_MySQL.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::NewProp_Results = { "Results", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMySQLResults_BP, Results), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::NewProp_Results_MetaData), Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::NewProp_Results_MetaData) }; // 3925351600
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::NewProp_Results_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::NewProp_Results,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Database_MySQL,
		nullptr,
		&NewStructOps,
		"MySQLResults_BP",
		Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::PropPointers),
		sizeof(FMySQLResults_BP),
		alignof(FMySQLResults_BP),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FMySQLResults_BP()
	{
		if (!Z_Registration_Info_UScriptStruct_MySQLResults_BP.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MySQLResults_BP.InnerSingleton, Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_MySQLResults_BP.InnerSingleton;
	}
	DEFINE_FUNCTION(UDatabase_MySQL::execSetString)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_columnName);
		P_GET_STRUCT_REF(FMySQLResult_BP,Z_Param_Out_result_BP);
		P_GET_PROPERTY(FStrProperty,Z_Param_value);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDatabase_MySQL::SetString(Z_Param_columnName,Z_Param_Out_result_BP,Z_Param_value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDatabase_MySQL::execGetBlob)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_columnName);
		P_GET_STRUCT_REF(FMySQLResult_BP,Z_Param_Out_result_BP);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<uint8>*)Z_Param__Result=UDatabase_MySQL::GetBlob(Z_Param_columnName,Z_Param_Out_result_BP);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDatabase_MySQL::execGetString)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_columnName);
		P_GET_STRUCT_REF(FMySQLResult_BP,Z_Param_Out_result_BP);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UDatabase_MySQL::GetString(Z_Param_columnName,Z_Param_Out_result_BP);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDatabase_MySQL::execGetDouble)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_columnName);
		P_GET_STRUCT_REF(FMySQLResult_BP,Z_Param_Out_result_BP);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(double*)Z_Param__Result=UDatabase_MySQL::GetDouble(Z_Param_columnName,Z_Param_Out_result_BP);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDatabase_MySQL::execGetInteger64)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_columnName);
		P_GET_STRUCT_REF(FMySQLResult_BP,Z_Param_Out_result_BP);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int64*)Z_Param__Result=UDatabase_MySQL::GetInteger64(Z_Param_columnName,Z_Param_Out_result_BP);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDatabase_MySQL::execGetInteger)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_columnName);
		P_GET_STRUCT_REF(FMySQLResult_BP,Z_Param_Out_result_BP);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UDatabase_MySQL::GetInteger(Z_Param_columnName,Z_Param_Out_result_BP);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDatabase_MySQL::execGetBool)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_columnName);
		P_GET_STRUCT_REF(FMySQLResult_BP,Z_Param_Out_result_BP);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDatabase_MySQL::GetBool(Z_Param_columnName,Z_Param_Out_result_BP);
		P_NATIVE_END;
	}
	void UDatabase_MySQL::StaticRegisterNativesUDatabase_MySQL()
	{
		UClass* Class = UDatabase_MySQL::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetBlob", &UDatabase_MySQL::execGetBlob },
			{ "GetBool", &UDatabase_MySQL::execGetBool },
			{ "GetDouble", &UDatabase_MySQL::execGetDouble },
			{ "GetInteger", &UDatabase_MySQL::execGetInteger },
			{ "GetInteger64", &UDatabase_MySQL::execGetInteger64 },
			{ "GetString", &UDatabase_MySQL::execGetString },
			{ "SetString", &UDatabase_MySQL::execSetString },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics
	{
		struct Database_MySQL_eventGetBlob_Parms
		{
			FString columnName;
			FMySQLResult_BP result_BP;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::NewProp_columnName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::NewProp_columnName = { "columnName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetBlob_Parms, columnName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::NewProp_columnName_MetaData), Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::NewProp_columnName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::NewProp_result_BP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::NewProp_result_BP = { "result_BP", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetBlob_Parms, result_BP), Z_Construct_UScriptStruct_FMySQLResult_BP, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::NewProp_result_BP_MetaData), Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::NewProp_result_BP_MetaData) }; // 3925351600
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetBlob_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::NewProp_columnName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::NewProp_result_BP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Database_MySQL.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_MySQL, nullptr, "GetBlob", nullptr, nullptr, Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::Database_MySQL_eventGetBlob_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::Database_MySQL_eventGetBlob_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDatabase_MySQL_GetBlob()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDatabase_MySQL_GetBlob_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics
	{
		struct Database_MySQL_eventGetBool_Parms
		{
			FString columnName;
			FMySQLResult_BP result_BP;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::NewProp_columnName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::NewProp_columnName = { "columnName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetBool_Parms, columnName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::NewProp_columnName_MetaData), Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::NewProp_columnName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::NewProp_result_BP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::NewProp_result_BP = { "result_BP", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetBool_Parms, result_BP), Z_Construct_UScriptStruct_FMySQLResult_BP, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::NewProp_result_BP_MetaData), Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::NewProp_result_BP_MetaData) }; // 3925351600
	void Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Database_MySQL_eventGetBool_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Database_MySQL_eventGetBool_Parms), &Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::NewProp_columnName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::NewProp_result_BP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Database_MySQL.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_MySQL, nullptr, "GetBool", nullptr, nullptr, Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::Database_MySQL_eventGetBool_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::Database_MySQL_eventGetBool_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDatabase_MySQL_GetBool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDatabase_MySQL_GetBool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics
	{
		struct Database_MySQL_eventGetDouble_Parms
		{
			FString columnName;
			FMySQLResult_BP result_BP;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::NewProp_columnName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::NewProp_columnName = { "columnName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetDouble_Parms, columnName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::NewProp_columnName_MetaData), Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::NewProp_columnName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::NewProp_result_BP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::NewProp_result_BP = { "result_BP", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetDouble_Parms, result_BP), Z_Construct_UScriptStruct_FMySQLResult_BP, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::NewProp_result_BP_MetaData), Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::NewProp_result_BP_MetaData) }; // 3925351600
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetDouble_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::NewProp_columnName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::NewProp_result_BP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Database_MySQL.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_MySQL, nullptr, "GetDouble", nullptr, nullptr, Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::Database_MySQL_eventGetDouble_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::Database_MySQL_eventGetDouble_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDatabase_MySQL_GetDouble()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDatabase_MySQL_GetDouble_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics
	{
		struct Database_MySQL_eventGetInteger_Parms
		{
			FString columnName;
			FMySQLResult_BP result_BP;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::NewProp_columnName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::NewProp_columnName = { "columnName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetInteger_Parms, columnName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::NewProp_columnName_MetaData), Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::NewProp_columnName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::NewProp_result_BP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::NewProp_result_BP = { "result_BP", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetInteger_Parms, result_BP), Z_Construct_UScriptStruct_FMySQLResult_BP, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::NewProp_result_BP_MetaData), Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::NewProp_result_BP_MetaData) }; // 3925351600
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetInteger_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::NewProp_columnName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::NewProp_result_BP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Database_MySQL.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_MySQL, nullptr, "GetInteger", nullptr, nullptr, Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::Database_MySQL_eventGetInteger_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::Database_MySQL_eventGetInteger_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDatabase_MySQL_GetInteger()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDatabase_MySQL_GetInteger_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics
	{
		struct Database_MySQL_eventGetInteger64_Parms
		{
			FString columnName;
			FMySQLResult_BP result_BP;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::NewProp_columnName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::NewProp_columnName = { "columnName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetInteger64_Parms, columnName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::NewProp_columnName_MetaData), Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::NewProp_columnName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::NewProp_result_BP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::NewProp_result_BP = { "result_BP", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetInteger64_Parms, result_BP), Z_Construct_UScriptStruct_FMySQLResult_BP, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::NewProp_result_BP_MetaData), Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::NewProp_result_BP_MetaData) }; // 3925351600
	const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetInteger64_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::NewProp_columnName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::NewProp_result_BP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Database_MySQL.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_MySQL, nullptr, "GetInteger64", nullptr, nullptr, Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::Database_MySQL_eventGetInteger64_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::Database_MySQL_eventGetInteger64_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDatabase_MySQL_GetInteger64()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDatabase_MySQL_GetInteger64_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics
	{
		struct Database_MySQL_eventGetString_Parms
		{
			FString columnName;
			FMySQLResult_BP result_BP;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::NewProp_columnName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::NewProp_columnName = { "columnName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetString_Parms, columnName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::NewProp_columnName_MetaData), Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::NewProp_columnName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::NewProp_result_BP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::NewProp_result_BP = { "result_BP", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetString_Parms, result_BP), Z_Construct_UScriptStruct_FMySQLResult_BP, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::NewProp_result_BP_MetaData), Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::NewProp_result_BP_MetaData) }; // 3925351600
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventGetString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::NewProp_columnName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::NewProp_result_BP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Database_MySQL.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_MySQL, nullptr, "GetString", nullptr, nullptr, Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::Database_MySQL_eventGetString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::Database_MySQL_eventGetString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDatabase_MySQL_GetString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDatabase_MySQL_GetString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics
	{
		struct Database_MySQL_eventSetString_Parms
		{
			FString columnName;
			FMySQLResult_BP result_BP;
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::NewProp_columnName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::NewProp_columnName = { "columnName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventSetString_Parms, columnName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::NewProp_columnName_MetaData), Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::NewProp_columnName_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::NewProp_result_BP = { "result_BP", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventSetString_Parms, result_BP), Z_Construct_UScriptStruct_FMySQLResult_BP, METADATA_PARAMS(0, nullptr) }; // 3925351600
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::NewProp_value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Database_MySQL_eventSetString_Parms, value), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::NewProp_value_MetaData), Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::NewProp_value_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::NewProp_columnName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::NewProp_result_BP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::NewProp_value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Database_MySQL.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDatabase_MySQL, nullptr, "SetString", nullptr, nullptr, Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::Database_MySQL_eventSetString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::Database_MySQL_eventSetString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDatabase_MySQL_SetString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDatabase_MySQL_SetString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDatabase_MySQL);
	UClass* Z_Construct_UClass_UDatabase_MySQL_NoRegister()
	{
		return UDatabase_MySQL::StaticClass();
	}
	struct Z_Construct_UClass_UDatabase_MySQL_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDatabase_MySQL_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Database_MySQL,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDatabase_MySQL_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDatabase_MySQL_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDatabase_MySQL_GetBlob, "GetBlob" }, // 3500153977
		{ &Z_Construct_UFunction_UDatabase_MySQL_GetBool, "GetBool" }, // 4093022966
		{ &Z_Construct_UFunction_UDatabase_MySQL_GetDouble, "GetDouble" }, // 887950615
		{ &Z_Construct_UFunction_UDatabase_MySQL_GetInteger, "GetInteger" }, // 1494792347
		{ &Z_Construct_UFunction_UDatabase_MySQL_GetInteger64, "GetInteger64" }, // 2246306103
		{ &Z_Construct_UFunction_UDatabase_MySQL_GetString, "GetString" }, // 1646032075
		{ &Z_Construct_UFunction_UDatabase_MySQL_SetString, "SetString" }, // 2817913306
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDatabase_MySQL_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDatabase_MySQL_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Core/Public/Database_MySQL.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Public/Database_MySQL.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDatabase_MySQL_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDatabase_MySQL>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDatabase_MySQL_Statics::ClassParams = {
		&UDatabase_MySQL::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDatabase_MySQL_Statics::Class_MetaDataParams), Z_Construct_UClass_UDatabase_MySQL_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UDatabase_MySQL()
	{
		if (!Z_Registration_Info_UClass_UDatabase_MySQL.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDatabase_MySQL.OuterSingleton, Z_Construct_UClass_UDatabase_MySQL_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDatabase_MySQL.OuterSingleton;
	}
	template<> VH_DATABASE_MYSQL_API UClass* StaticClass<UDatabase_MySQL>()
	{
		return UDatabase_MySQL::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDatabase_MySQL);
	UDatabase_MySQL::~UDatabase_MySQL() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_Statics::ScriptStructInfo[] = {
		{ FMySQLResult_BP::StaticStruct, Z_Construct_UScriptStruct_FMySQLResult_BP_Statics::NewStructOps, TEXT("MySQLResult_BP"), &Z_Registration_Info_UScriptStruct_MySQLResult_BP, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMySQLResult_BP), 3925351600U) },
		{ FMySQLResults_BP::StaticStruct, Z_Construct_UScriptStruct_FMySQLResults_BP_Statics::NewStructOps, TEXT("MySQLResults_BP"), &Z_Registration_Info_UScriptStruct_MySQLResults_BP, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMySQLResults_BP), 868877592U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDatabase_MySQL, UDatabase_MySQL::StaticClass, TEXT("UDatabase_MySQL"), &Z_Registration_Info_UClass_UDatabase_MySQL, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDatabase_MySQL), 3633318094U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_4276546931(TEXT("/Script/VH_Database_MySQL"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Database_Source_VH_Database_MySQL_Core_Public_Database_MySQL_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
