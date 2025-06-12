// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../ConverterUnits/Public/Developer_ConverterUnit.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_ConverterUnit() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_ConverterUnit();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_ConverterUnit_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UDeveloper_ConverterUnit::execFormatText)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_unitValue);
		P_GET_PROPERTY(FIntProperty,Z_Param_numDigits);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->FormatText(Z_Param_unitValue,Z_Param_numDigits);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_ConverterUnit::execConvertToStandard)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_unitValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->ConvertToStandard_Implementation(Z_Param_unitValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_ConverterUnit::execConvertFromStandard)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_standardValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->ConvertFromStandard_Implementation(Z_Param_standardValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_ConverterUnit::execGetStandardUnit)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetStandardUnit();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_ConverterUnit::execGetID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetID();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_ConverterUnit::execGetAbbreviation)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetAbbreviation();
		P_NATIVE_END;
	}
	struct Developer_ConverterUnit_eventConvertFromStandard_Parms
	{
		FString standardValue;
		FString ReturnValue;
	};
	struct Developer_ConverterUnit_eventConvertToStandard_Parms
	{
		FString unitValue;
		FString ReturnValue;
	};
	static FName NAME_UDeveloper_ConverterUnit_ConvertFromStandard = FName(TEXT("ConvertFromStandard"));
	FString UDeveloper_ConverterUnit::ConvertFromStandard(const FString& standardValue)
	{
		Developer_ConverterUnit_eventConvertFromStandard_Parms Parms;
		Parms.standardValue=standardValue;
		ProcessEvent(FindFunctionChecked(NAME_UDeveloper_ConverterUnit_ConvertFromStandard),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_UDeveloper_ConverterUnit_ConvertToStandard = FName(TEXT("ConvertToStandard"));
	FString UDeveloper_ConverterUnit::ConvertToStandard(const FString& unitValue)
	{
		Developer_ConverterUnit_eventConvertToStandard_Parms Parms;
		Parms.unitValue=unitValue;
		ProcessEvent(FindFunctionChecked(NAME_UDeveloper_ConverterUnit_ConvertToStandard),&Parms);
		return Parms.ReturnValue;
	}
	void UDeveloper_ConverterUnit::StaticRegisterNativesUDeveloper_ConverterUnit()
	{
		UClass* Class = UDeveloper_ConverterUnit::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ConvertFromStandard", &UDeveloper_ConverterUnit::execConvertFromStandard },
			{ "ConvertToStandard", &UDeveloper_ConverterUnit::execConvertToStandard },
			{ "FormatText", &UDeveloper_ConverterUnit::execFormatText },
			{ "GetAbbreviation", &UDeveloper_ConverterUnit::execGetAbbreviation },
			{ "GetID", &UDeveloper_ConverterUnit::execGetID },
			{ "GetStandardUnit", &UDeveloper_ConverterUnit::execGetStandardUnit },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_standardValue_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_standardValue;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics::NewProp_standardValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics::NewProp_standardValue = { "standardValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_ConverterUnit_eventConvertFromStandard_Parms, standardValue), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics::NewProp_standardValue_MetaData), Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics::NewProp_standardValue_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_ConverterUnit_eventConvertFromStandard_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics::NewProp_standardValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Converts from standard unit to this unit type.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "ConverterUnits/Public/Developer_ConverterUnit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Converts from standard unit to this unit type." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_ConverterUnit, nullptr, "ConvertFromStandard", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics::PropPointers), sizeof(Developer_ConverterUnit_eventConvertFromStandard_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics::PropPointers) < 2048);
	static_assert(sizeof(Developer_ConverterUnit_eventConvertFromStandard_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_unitValue_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_unitValue;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics::NewProp_unitValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics::NewProp_unitValue = { "unitValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_ConverterUnit_eventConvertToStandard_Parms, unitValue), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics::NewProp_unitValue_MetaData), Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics::NewProp_unitValue_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_ConverterUnit_eventConvertToStandard_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics::NewProp_unitValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Converts from this unit to the standard unit type.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "ConverterUnits/Public/Developer_ConverterUnit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Converts from this unit to the standard unit type." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_ConverterUnit, nullptr, "ConvertToStandard", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics::PropPointers), sizeof(Developer_ConverterUnit_eventConvertToStandard_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics::PropPointers) < 2048);
	static_assert(sizeof(Developer_ConverterUnit_eventConvertToStandard_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics
	{
		struct Developer_ConverterUnit_eventFormatText_Parms
		{
			FString unitValue;
			int32 numDigits;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_unitValue_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_unitValue;
		static const UECodeGen_Private::FIntPropertyParams NewProp_numDigits;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::NewProp_unitValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::NewProp_unitValue = { "unitValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_ConverterUnit_eventFormatText_Parms, unitValue), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::NewProp_unitValue_MetaData), Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::NewProp_unitValue_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::NewProp_numDigits = { "numDigits", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_ConverterUnit_eventFormatText_Parms, numDigits), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_ConverterUnit_eventFormatText_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::NewProp_unitValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::NewProp_numDigits,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Takes a value that is already in this unit and formats it to display correctly\n\x09*/" },
#endif
		{ "ModuleRelativePath", "ConverterUnits/Public/Developer_ConverterUnit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Takes a value that is already in this unit and formats it to display correctly" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_ConverterUnit, nullptr, "FormatText", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::Developer_ConverterUnit_eventFormatText_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::Developer_ConverterUnit_eventFormatText_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_ConverterUnit_GetAbbreviation_Statics
	{
		struct Developer_ConverterUnit_eventGetAbbreviation_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_ConverterUnit_GetAbbreviation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_ConverterUnit_eventGetAbbreviation_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_ConverterUnit_GetAbbreviation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_ConverterUnit_GetAbbreviation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_ConverterUnit_GetAbbreviation_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Returns the abbreviation used by this unit, such as ft for feet or km for kilometers\n\x09*/" },
#endif
		{ "ModuleRelativePath", "ConverterUnits/Public/Developer_ConverterUnit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Returns the abbreviation used by this unit, such as ft for feet or km for kilometers" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_ConverterUnit_GetAbbreviation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_ConverterUnit, nullptr, "GetAbbreviation", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_ConverterUnit_GetAbbreviation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_GetAbbreviation_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_ConverterUnit_GetAbbreviation_Statics::Developer_ConverterUnit_eventGetAbbreviation_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_GetAbbreviation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_ConverterUnit_GetAbbreviation_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_GetAbbreviation_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_ConverterUnit_GetAbbreviation_Statics::Developer_ConverterUnit_eventGetAbbreviation_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_ConverterUnit_GetAbbreviation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_ConverterUnit_GetAbbreviation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_ConverterUnit_GetID_Statics
	{
		struct Developer_ConverterUnit_eventGetID_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_ConverterUnit_GetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_ConverterUnit_eventGetID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_ConverterUnit_GetID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_ConverterUnit_GetID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_ConverterUnit_GetID_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Returns the name of the unit\n\x09*/" },
#endif
		{ "ModuleRelativePath", "ConverterUnits/Public/Developer_ConverterUnit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Returns the name of the unit" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_ConverterUnit_GetID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_ConverterUnit, nullptr, "GetID", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_ConverterUnit_GetID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_GetID_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_ConverterUnit_GetID_Statics::Developer_ConverterUnit_eventGetID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_GetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_ConverterUnit_GetID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_GetID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_ConverterUnit_GetID_Statics::Developer_ConverterUnit_eventGetID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_ConverterUnit_GetID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_ConverterUnit_GetID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_ConverterUnit_GetStandardUnit_Statics
	{
		struct Developer_ConverterUnit_eventGetStandardUnit_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_ConverterUnit_GetStandardUnit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_ConverterUnit_eventGetStandardUnit_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_ConverterUnit_GetStandardUnit_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_ConverterUnit_GetStandardUnit_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_ConverterUnit_GetStandardUnit_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Returns the type of value this unit measures.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "ConverterUnits/Public/Developer_ConverterUnit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Returns the type of value this unit measures." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_ConverterUnit_GetStandardUnit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_ConverterUnit, nullptr, "GetStandardUnit", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_ConverterUnit_GetStandardUnit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_GetStandardUnit_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_ConverterUnit_GetStandardUnit_Statics::Developer_ConverterUnit_eventGetStandardUnit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_GetStandardUnit_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_ConverterUnit_GetStandardUnit_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_ConverterUnit_GetStandardUnit_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_ConverterUnit_GetStandardUnit_Statics::Developer_ConverterUnit_eventGetStandardUnit_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_ConverterUnit_GetStandardUnit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_ConverterUnit_GetStandardUnit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_ConverterUnit);
	UClass* Z_Construct_UClass_UDeveloper_ConverterUnit_NoRegister()
	{
		return UDeveloper_ConverterUnit::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_ConverterUnit_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ToStandardUnitRatio_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_ToStandardUnitRatio;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Abbreviation_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Abbreviation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ID_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BaseUnit_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_BaseUnit;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertFromStandard, "ConvertFromStandard" }, // 1642675343
		{ &Z_Construct_UFunction_UDeveloper_ConverterUnit_ConvertToStandard, "ConvertToStandard" }, // 2025751156
		{ &Z_Construct_UFunction_UDeveloper_ConverterUnit_FormatText, "FormatText" }, // 342151477
		{ &Z_Construct_UFunction_UDeveloper_ConverterUnit_GetAbbreviation, "GetAbbreviation" }, // 173398374
		{ &Z_Construct_UFunction_UDeveloper_ConverterUnit_GetID, "GetID" }, // 2927376124
		{ &Z_Construct_UFunction_UDeveloper_ConverterUnit_GetStandardUnit, "GetStandardUnit" }, // 872888934
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "ConverterUnits/Public/Developer_ConverterUnit.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "ConverterUnits/Public/Developer_ConverterUnit.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_ToStandardUnitRatio_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Developer_ConverterUnit" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * \\brief The conversion ratio to the standard unit type.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "ConverterUnits/Public/Developer_ConverterUnit.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief The conversion ratio to the standard unit type." },
#endif
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_ToStandardUnitRatio = { "ToStandardUnitRatio", nullptr, (EPropertyFlags)0x0040000000010005, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_ConverterUnit, ToStandardUnitRatio), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_ToStandardUnitRatio_MetaData), Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_ToStandardUnitRatio_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_Abbreviation_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Developer_ConverterUnit" },
		{ "ModuleRelativePath", "ConverterUnits/Public/Developer_ConverterUnit.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_Abbreviation = { "Abbreviation", nullptr, (EPropertyFlags)0x0040000000010005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_ConverterUnit, Abbreviation), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_Abbreviation_MetaData), Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_Abbreviation_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_ID_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Developer_ConverterUnit" },
		{ "ModuleRelativePath", "ConverterUnits/Public/Developer_ConverterUnit.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_ID = { "ID", nullptr, (EPropertyFlags)0x0040000000010005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_ConverterUnit, ID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_ID_MetaData), Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_ID_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_BaseUnit_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "Developer_ConverterUnit" },
		{ "ModuleRelativePath", "ConverterUnits/Public/Developer_ConverterUnit.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_BaseUnit = { "BaseUnit", nullptr, (EPropertyFlags)0x0040000000010005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDeveloper_ConverterUnit, BaseUnit), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_BaseUnit_MetaData), Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_BaseUnit_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_ToStandardUnitRatio,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_Abbreviation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_ID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::NewProp_BaseUnit,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_ConverterUnit>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::ClassParams = {
		&UDeveloper_ConverterUnit::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::PropPointers),
		0,
		0x001000A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UDeveloper_ConverterUnit()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_ConverterUnit.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_ConverterUnit.OuterSingleton, Z_Construct_UClass_UDeveloper_ConverterUnit_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_ConverterUnit.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_ConverterUnit>()
	{
		return UDeveloper_ConverterUnit::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_ConverterUnit);
	UDeveloper_ConverterUnit::~UDeveloper_ConverterUnit() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_ConverterUnit, UDeveloper_ConverterUnit::StaticClass, TEXT("UDeveloper_ConverterUnit"), &Z_Registration_Info_UClass_UDeveloper_ConverterUnit, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_ConverterUnit), 2879673830U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_3425357844(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
