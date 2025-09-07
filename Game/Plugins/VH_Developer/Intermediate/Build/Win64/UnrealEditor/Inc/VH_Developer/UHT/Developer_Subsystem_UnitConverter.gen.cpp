// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Subsystems/Public/Developer_Subsystem_UnitConverter.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_Subsystem_UnitConverter() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_ConverterUnit_NoRegister();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_NoRegister();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UDeveloper_Subsystem_UnitConverter::execGetAbbreviationFromName)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_unitID);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetAbbreviationFromName(Z_Param_unitID);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_UnitConverter::execGetUnit)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_unitID);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UDeveloper_ConverterUnit**)Z_Param__Result=P_THIS->GetUnit(Z_Param_unitID);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_UnitConverter::execGetUnitIDs)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TSet<FString>*)Z_Param__Result=P_THIS->GetUnitIDs();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_UnitConverter::execConvertUnitsAndFormatByClass)
	{
		P_GET_OBJECT(UClass,Z_Param_startConverterClass);
		P_GET_PROPERTY(FStrProperty,Z_Param_startValue);
		P_GET_OBJECT(UClass,Z_Param_endConverterClass);
		P_GET_PROPERTY(FIntProperty,Z_Param_numDigits);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->ConvertUnitsAndFormatByClass(Z_Param_startConverterClass,Z_Param_startValue,Z_Param_endConverterClass,Z_Param_numDigits);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_UnitConverter::execConvertUnitsByClass)
	{
		P_GET_OBJECT(UClass,Z_Param_startConverterClass);
		P_GET_PROPERTY(FStrProperty,Z_Param_startValue);
		P_GET_OBJECT(UClass,Z_Param_endConverterClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->ConvertUnitsByClass(Z_Param_startConverterClass,Z_Param_startValue,Z_Param_endConverterClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_UnitConverter::execConvertUnitsAndFormat)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_startConverterName);
		P_GET_PROPERTY(FStrProperty,Z_Param_startValue);
		P_GET_PROPERTY(FStrProperty,Z_Param_endConverterName);
		P_GET_PROPERTY(FIntProperty,Z_Param_numDigits);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->ConvertUnitsAndFormat(Z_Param_startConverterName,Z_Param_startValue,Z_Param_endConverterName,Z_Param_numDigits);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_UnitConverter::execConvertUnits)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_startConverterName);
		P_GET_PROPERTY(FStrProperty,Z_Param_startValue);
		P_GET_PROPERTY(FStrProperty,Z_Param_endConverterName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->ConvertUnits(Z_Param_startConverterName,Z_Param_startValue,Z_Param_endConverterName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_UnitConverter::execRegisterConverterUnitByClass)
	{
		P_GET_OBJECT(UClass,Z_Param_unitClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->RegisterConverterUnitByClass(Z_Param_unitClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Subsystem_UnitConverter::execUpdateSettings)
	{
		P_GET_OBJECT(UClass,Z_Param_settingsClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateSettings(Z_Param_settingsClass);
		P_NATIVE_END;
	}
	void UDeveloper_Subsystem_UnitConverter::StaticRegisterNativesUDeveloper_Subsystem_UnitConverter()
	{
		UClass* Class = UDeveloper_Subsystem_UnitConverter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ConvertUnits", &UDeveloper_Subsystem_UnitConverter::execConvertUnits },
			{ "ConvertUnitsAndFormat", &UDeveloper_Subsystem_UnitConverter::execConvertUnitsAndFormat },
			{ "ConvertUnitsAndFormatByClass", &UDeveloper_Subsystem_UnitConverter::execConvertUnitsAndFormatByClass },
			{ "ConvertUnitsByClass", &UDeveloper_Subsystem_UnitConverter::execConvertUnitsByClass },
			{ "GetAbbreviationFromName", &UDeveloper_Subsystem_UnitConverter::execGetAbbreviationFromName },
			{ "GetUnit", &UDeveloper_Subsystem_UnitConverter::execGetUnit },
			{ "GetUnitIDs", &UDeveloper_Subsystem_UnitConverter::execGetUnitIDs },
			{ "RegisterConverterUnitByClass", &UDeveloper_Subsystem_UnitConverter::execRegisterConverterUnitByClass },
			{ "UpdateSettings", &UDeveloper_Subsystem_UnitConverter::execUpdateSettings },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics
	{
		struct Developer_Subsystem_UnitConverter_eventConvertUnits_Parms
		{
			FString startConverterName;
			FString startValue;
			FString endConverterName;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_startConverterName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_startConverterName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_startValue_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_startValue;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_endConverterName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_endConverterName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_startConverterName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_startConverterName = { "startConverterName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnits_Parms, startConverterName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_startConverterName_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_startConverterName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_startValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_startValue = { "startValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnits_Parms, startValue), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_startValue_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_startValue_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_endConverterName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_endConverterName = { "endConverterName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnits_Parms, endConverterName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_endConverterName_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_endConverterName_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnits_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_startConverterName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_startValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_endConverterName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_UnitConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter, nullptr, "ConvertUnits", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::Developer_Subsystem_UnitConverter_eventConvertUnits_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x44020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::Developer_Subsystem_UnitConverter_eventConvertUnits_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics
	{
		struct Developer_Subsystem_UnitConverter_eventConvertUnitsAndFormat_Parms
		{
			FString startConverterName;
			FString startValue;
			FString endConverterName;
			int32 numDigits;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_startConverterName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_startConverterName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_startValue_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_startValue;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_endConverterName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_endConverterName;
		static const UECodeGen_Private::FIntPropertyParams NewProp_numDigits;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_startConverterName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_startConverterName = { "startConverterName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnitsAndFormat_Parms, startConverterName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_startConverterName_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_startConverterName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_startValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_startValue = { "startValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnitsAndFormat_Parms, startValue), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_startValue_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_startValue_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_endConverterName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_endConverterName = { "endConverterName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnitsAndFormat_Parms, endConverterName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_endConverterName_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_endConverterName_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_numDigits = { "numDigits", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnitsAndFormat_Parms, numDigits), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnitsAndFormat_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_startConverterName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_startValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_endConverterName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_numDigits,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_UnitConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter, nullptr, "ConvertUnitsAndFormat", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::Developer_Subsystem_UnitConverter_eventConvertUnitsAndFormat_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x44020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::Developer_Subsystem_UnitConverter_eventConvertUnitsAndFormat_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics
	{
		struct Developer_Subsystem_UnitConverter_eventConvertUnitsAndFormatByClass_Parms
		{
			TSubclassOf<UDeveloper_ConverterUnit>  startConverterClass;
			FString startValue;
			TSubclassOf<UDeveloper_ConverterUnit>  endConverterClass;
			int32 numDigits;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_startConverterClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_startValue_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_startValue;
		static const UECodeGen_Private::FClassPropertyParams NewProp_endConverterClass;
		static const UECodeGen_Private::FIntPropertyParams NewProp_numDigits;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::NewProp_startConverterClass = { "startConverterClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnitsAndFormatByClass_Parms, startConverterClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDeveloper_ConverterUnit_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::NewProp_startValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::NewProp_startValue = { "startValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnitsAndFormatByClass_Parms, startValue), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::NewProp_startValue_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::NewProp_startValue_MetaData) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::NewProp_endConverterClass = { "endConverterClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnitsAndFormatByClass_Parms, endConverterClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDeveloper_ConverterUnit_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::NewProp_numDigits = { "numDigits", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnitsAndFormatByClass_Parms, numDigits), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnitsAndFormatByClass_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::NewProp_startConverterClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::NewProp_startValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::NewProp_endConverterClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::NewProp_numDigits,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_UnitConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter, nullptr, "ConvertUnitsAndFormatByClass", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::Developer_Subsystem_UnitConverter_eventConvertUnitsAndFormatByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::Developer_Subsystem_UnitConverter_eventConvertUnitsAndFormatByClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics
	{
		struct Developer_Subsystem_UnitConverter_eventConvertUnitsByClass_Parms
		{
			TSubclassOf<UDeveloper_ConverterUnit>  startConverterClass;
			FString startValue;
			TSubclassOf<UDeveloper_ConverterUnit>  endConverterClass;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_startConverterClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_startValue_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_startValue;
		static const UECodeGen_Private::FClassPropertyParams NewProp_endConverterClass;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::NewProp_startConverterClass = { "startConverterClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnitsByClass_Parms, startConverterClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDeveloper_ConverterUnit_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::NewProp_startValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::NewProp_startValue = { "startValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnitsByClass_Parms, startValue), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::NewProp_startValue_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::NewProp_startValue_MetaData) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::NewProp_endConverterClass = { "endConverterClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnitsByClass_Parms, endConverterClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDeveloper_ConverterUnit_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventConvertUnitsByClass_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::NewProp_startConverterClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::NewProp_startValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::NewProp_endConverterClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_UnitConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter, nullptr, "ConvertUnitsByClass", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::Developer_Subsystem_UnitConverter_eventConvertUnitsByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::Developer_Subsystem_UnitConverter_eventConvertUnitsByClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics
	{
		struct Developer_Subsystem_UnitConverter_eventGetAbbreviationFromName_Parms
		{
			FString unitID;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_unitID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_unitID;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::NewProp_unitID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::NewProp_unitID = { "unitID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventGetAbbreviationFromName_Parms, unitID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::NewProp_unitID_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::NewProp_unitID_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventGetAbbreviationFromName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::NewProp_unitID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_UnitConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter, nullptr, "GetAbbreviationFromName", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::Developer_Subsystem_UnitConverter_eventGetAbbreviationFromName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::Developer_Subsystem_UnitConverter_eventGetAbbreviationFromName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics
	{
		struct Developer_Subsystem_UnitConverter_eventGetUnit_Parms
		{
			FString unitID;
			UDeveloper_ConverterUnit* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_unitID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_unitID;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::NewProp_unitID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::NewProp_unitID = { "unitID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventGetUnit_Parms, unitID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::NewProp_unitID_MetaData), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::NewProp_unitID_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventGetUnit_Parms, ReturnValue), Z_Construct_UClass_UDeveloper_ConverterUnit_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::NewProp_unitID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_UnitConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter, nullptr, "GetUnit", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::Developer_Subsystem_UnitConverter_eventGetUnit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::Developer_Subsystem_UnitConverter_eventGetUnit_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs_Statics
	{
		struct Developer_Subsystem_UnitConverter_eventGetUnitIDs_Parms
		{
			TSet<FString> ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_ElementProp;
		static const UECodeGen_Private::FSetPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs_Statics::NewProp_ReturnValue_ElementProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventGetUnitIDs_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs_Statics::NewProp_ReturnValue_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_UnitConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter, nullptr, "GetUnitIDs", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs_Statics::Developer_Subsystem_UnitConverter_eventGetUnitIDs_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs_Statics::Developer_Subsystem_UnitConverter_eventGetUnitIDs_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass_Statics
	{
		struct Developer_Subsystem_UnitConverter_eventRegisterConverterUnitByClass_Parms
		{
			TSubclassOf<UDeveloper_ConverterUnit>  unitClass;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_unitClass;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass_Statics::NewProp_unitClass = { "unitClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventRegisterConverterUnitByClass_Parms, unitClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDeveloper_ConverterUnit_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventRegisterConverterUnitByClass_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass_Statics::NewProp_unitClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_UnitConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter, nullptr, "RegisterConverterUnitByClass", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass_Statics::Developer_Subsystem_UnitConverter_eventRegisterConverterUnitByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass_Statics::Developer_Subsystem_UnitConverter_eventRegisterConverterUnitByClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_UpdateSettings_Statics
	{
		struct Developer_Subsystem_UnitConverter_eventUpdateSettings_Parms
		{
			TSubclassOf<UDeveloper_Subsystem_UnitConverter_Settings>  settingsClass;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_settingsClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_UpdateSettings_Statics::NewProp_settingsClass = { "settingsClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Subsystem_UnitConverter_eventUpdateSettings_Parms, settingsClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Settings_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_UpdateSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_UpdateSettings_Statics::NewProp_settingsClass,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_UpdateSettings_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_UnitConverter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_UpdateSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter, nullptr, "UpdateSettings", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_UpdateSettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_UpdateSettings_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_UpdateSettings_Statics::Developer_Subsystem_UnitConverter_eventUpdateSettings_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_UpdateSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_UpdateSettings_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_UpdateSettings_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_UpdateSettings_Statics::Developer_Subsystem_UnitConverter_eventUpdateSettings_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_UpdateSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_UpdateSettings_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_Subsystem_UnitConverter);
	UClass* Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_NoRegister()
	{
		return UDeveloper_Subsystem_UnitConverter::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Converters_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Converters_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Converters_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_Converters;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnits, "ConvertUnits" }, // 1185191201
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormat, "ConvertUnitsAndFormat" }, // 3655364439
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsAndFormatByClass, "ConvertUnitsAndFormatByClass" }, // 864264137
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_ConvertUnitsByClass, "ConvertUnitsByClass" }, // 876469034
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetAbbreviationFromName, "GetAbbreviationFromName" }, // 2684079400
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnit, "GetUnit" }, // 3274865052
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_GetUnitIDs, "GetUnitIDs" }, // 3132573641
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_RegisterConverterUnitByClass, "RegisterConverterUnitByClass" }, // 3394912403
		{ &Z_Construct_UFunction_UDeveloper_Subsystem_UnitConverter_UpdateSettings, "UpdateSettings" }, // 3259566730
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n* To convert between two units you call the ConvertUnits function with the names(as strings) of the units you want to convert toand from.\n*\n* float valueInFeet = 123;\n* float valueInMeters = UDeveloper_UnitConverter::Get()->ConvertUnits(\"feet\", valueInFeet, \"meters\");\n* The unit names come from the 'Name' field within UDeveloper_ConverterUnit.The format is the unit name in plural and lowercase.\n*\n* The converter can also format the result as a string.\n*\n* FString result = UDeveloper_UnitConverter::Get()->ConvertUnitsAndFormat(\"kilometers\", 5.6, \"meters\", 1);\n* In this example result ends with the value \"5600.0m\".The unit is converted, the unit abbreviation is appended, and it is displayed rounded to the number of decimal places specified in the last argument,\n*/" },
#endif
		{ "IncludePath", "Subsystems/Public/Developer_Subsystem_UnitConverter.h" },
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_UnitConverter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* To convert between two units you call the ConvertUnits function with the names(as strings) of the units you want to convert toand from.\n*\n* float valueInFeet = 123;\n* float valueInMeters = UDeveloper_UnitConverter::Get()->ConvertUnits(\"feet\", valueInFeet, \"meters\");\n* The unit names come from the 'Name' field within UDeveloper_ConverterUnit.The format is the unit name in plural and lowercase.\n*\n* The converter can also format the result as a string.\n*\n* FString result = UDeveloper_UnitConverter::Get()->ConvertUnitsAndFormat(\"kilometers\", 5.6, \"meters\", 1);\n* In this example result ends with the value \"5600.0m\".The unit is converted, the unit abbreviation is appended, and it is displayed rounded to the number of decimal places specified in the last argument," },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::NewProp_Converters_ValueProp = { "Converters", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UDeveloper_ConverterUnit_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::NewProp_Converters_Key_KeyProp = { "Converters_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::NewProp_Converters_MetaData[] = {
		{ "ModuleRelativePath", "Subsystems/Public/Developer_Subsystem_UnitConverter.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::NewProp_Converters = { "Converters", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_Subsystem_UnitConverter, Converters), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::NewProp_Converters_MetaData), Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::NewProp_Converters_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::NewProp_Converters_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::NewProp_Converters_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::NewProp_Converters,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_Subsystem_UnitConverter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::ClassParams = {
		&UDeveloper_Subsystem_UnitConverter::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_Subsystem_UnitConverter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_Subsystem_UnitConverter.OuterSingleton, Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_Subsystem_UnitConverter.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_Subsystem_UnitConverter>()
	{
		return UDeveloper_Subsystem_UnitConverter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_Subsystem_UnitConverter);
	UDeveloper_Subsystem_UnitConverter::~UDeveloper_Subsystem_UnitConverter() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter, UDeveloper_Subsystem_UnitConverter::StaticClass, TEXT("UDeveloper_Subsystem_UnitConverter"), &Z_Registration_Info_UClass_UDeveloper_Subsystem_UnitConverter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_Subsystem_UnitConverter), 686881582U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_3063835744(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
