// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Core/Public/Interface_Developer_Manipulation.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInterface_Developer_Manipulation() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UInterface_Developer_Manipulation();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UInterface_Developer_Manipulation_NoRegister();
	VH_DEVELOPER_API UEnum* Z_Construct_UEnum_VH_Developer_EAxisListBlueprint();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAxisListBlueprint;
	static UEnum* EAxisListBlueprint_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EAxisListBlueprint.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EAxisListBlueprint.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_Developer_EAxisListBlueprint, (UObject*)Z_Construct_UPackage__Script_VH_Developer(), TEXT("EAxisListBlueprint"));
		}
		return Z_Registration_Info_UEnum_EAxisListBlueprint.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UEnum* StaticEnum<EAxisListBlueprint>()
	{
		return EAxisListBlueprint_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_Developer_EAxisListBlueprint_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_Developer_EAxisListBlueprint_Statics::Enumerators[] = {
		{ "EAxisListBlueprint::None", (int64)EAxisListBlueprint::None },
		{ "EAxisListBlueprint::X", (int64)EAxisListBlueprint::X },
		{ "EAxisListBlueprint::Y", (int64)EAxisListBlueprint::Y },
		{ "EAxisListBlueprint::Z", (int64)EAxisListBlueprint::Z },
		{ "EAxisListBlueprint::XY", (int64)EAxisListBlueprint::XY },
		{ "EAxisListBlueprint::XZ", (int64)EAxisListBlueprint::XZ },
		{ "EAxisListBlueprint::YZ", (int64)EAxisListBlueprint::YZ },
		{ "EAxisListBlueprint::XYZ", (int64)EAxisListBlueprint::XYZ },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_Developer_EAxisListBlueprint_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// similar to EAxisList::Type from Math/Axis.h but exposed to blueprint\n" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_Developer_Manipulation.h" },
		{ "None.Name", "EAxisListBlueprint::None" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "similar to EAxisList::Type from Math/Axis.h but exposed to blueprint" },
#endif
		{ "X.Name", "EAxisListBlueprint::X" },
		{ "XY.Name", "EAxisListBlueprint::XY" },
		{ "XYZ.Name", "EAxisListBlueprint::XYZ" },
		{ "XZ.Name", "EAxisListBlueprint::XZ" },
		{ "Y.Name", "EAxisListBlueprint::Y" },
		{ "YZ.Name", "EAxisListBlueprint::YZ" },
		{ "Z.Name", "EAxisListBlueprint::Z" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_Developer_EAxisListBlueprint_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_Developer,
		nullptr,
		"EAxisListBlueprint",
		"EAxisListBlueprint",
		Z_Construct_UEnum_VH_Developer_EAxisListBlueprint_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Developer_EAxisListBlueprint_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Developer_EAxisListBlueprint_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_Developer_EAxisListBlueprint_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_Developer_EAxisListBlueprint()
	{
		if (!Z_Registration_Info_UEnum_EAxisListBlueprint.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAxisListBlueprint.InnerSingleton, Z_Construct_UEnum_VH_Developer_EAxisListBlueprint_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EAxisListBlueprint.InnerSingleton;
	}
	DEFINE_FUNCTION(IInterface_Developer_Manipulation::execManipulationEnd)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ManipulationEnd_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_Developer_Manipulation::execManipulationInProgress)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ManipulationInProgress_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_Developer_Manipulation::execManipulationBegin)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ManipulationBegin_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_Developer_Manipulation::execGetWorldTransform)
	{
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_localToWorld);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetWorldTransform_Implementation(Z_Param_Out_localToWorld);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_Developer_Manipulation::execGetScaleAxisList)
	{
		P_GET_ENUM_REF(EAxisListBlueprint,Z_Param_Out_axisList);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetScaleAxisList_Implementation((EAxisListBlueprint&)(Z_Param_Out_axisList));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_Developer_Manipulation::execGetRotationDisabled)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetRotationDisabled_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_Developer_Manipulation::execGetRotationAxisList)
	{
		P_GET_ENUM_REF(EAxisListBlueprint,Z_Param_Out_axisList);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetRotationAxisList_Implementation((EAxisListBlueprint&)(Z_Param_Out_axisList));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_Developer_Manipulation::execGetTranslationAxisList)
	{
		P_GET_ENUM_REF(EAxisListBlueprint,Z_Param_Out_axisList);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetTranslationAxisList_Implementation((EAxisListBlueprint&)(Z_Param_Out_axisList));
		P_NATIVE_END;
	}
	struct Interface_Developer_Manipulation_eventGetRotationAxisList_Parms
	{
		EAxisListBlueprint axisList;
		bool ReturnValue;

		/** Constructor, initializes return property only **/
		Interface_Developer_Manipulation_eventGetRotationAxisList_Parms()
			: ReturnValue(false)
		{
		}
	};
	struct Interface_Developer_Manipulation_eventGetRotationDisabled_Parms
	{
		bool ReturnValue;

		/** Constructor, initializes return property only **/
		Interface_Developer_Manipulation_eventGetRotationDisabled_Parms()
			: ReturnValue(false)
		{
		}
	};
	struct Interface_Developer_Manipulation_eventGetScaleAxisList_Parms
	{
		EAxisListBlueprint axisList;
		bool ReturnValue;

		/** Constructor, initializes return property only **/
		Interface_Developer_Manipulation_eventGetScaleAxisList_Parms()
			: ReturnValue(false)
		{
		}
	};
	struct Interface_Developer_Manipulation_eventGetTranslationAxisList_Parms
	{
		EAxisListBlueprint axisList;
		bool ReturnValue;

		/** Constructor, initializes return property only **/
		Interface_Developer_Manipulation_eventGetTranslationAxisList_Parms()
			: ReturnValue(false)
		{
		}
	};
	struct Interface_Developer_Manipulation_eventGetWorldTransform_Parms
	{
		FTransform localToWorld;
		bool ReturnValue;

		/** Constructor, initializes return property only **/
		Interface_Developer_Manipulation_eventGetWorldTransform_Parms()
			: ReturnValue(false)
		{
		}
	};
	bool IInterface_Developer_Manipulation::GetRotationAxisList(EAxisListBlueprint& axisList)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetRotationAxisList instead.");
		Interface_Developer_Manipulation_eventGetRotationAxisList_Parms Parms;
		return Parms.ReturnValue;
	}
	bool IInterface_Developer_Manipulation::GetRotationDisabled()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetRotationDisabled instead.");
		Interface_Developer_Manipulation_eventGetRotationDisabled_Parms Parms;
		return Parms.ReturnValue;
	}
	bool IInterface_Developer_Manipulation::GetScaleAxisList(EAxisListBlueprint& axisList)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetScaleAxisList instead.");
		Interface_Developer_Manipulation_eventGetScaleAxisList_Parms Parms;
		return Parms.ReturnValue;
	}
	bool IInterface_Developer_Manipulation::GetTranslationAxisList(EAxisListBlueprint& axisList)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetTranslationAxisList instead.");
		Interface_Developer_Manipulation_eventGetTranslationAxisList_Parms Parms;
		return Parms.ReturnValue;
	}
	bool IInterface_Developer_Manipulation::GetWorldTransform(FTransform& localToWorld)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetWorldTransform instead.");
		Interface_Developer_Manipulation_eventGetWorldTransform_Parms Parms;
		return Parms.ReturnValue;
	}
	void IInterface_Developer_Manipulation::ManipulationBegin()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ManipulationBegin instead.");
	}
	void IInterface_Developer_Manipulation::ManipulationEnd()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ManipulationEnd instead.");
	}
	void IInterface_Developer_Manipulation::ManipulationInProgress()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ManipulationInProgress instead.");
	}
	void UInterface_Developer_Manipulation::StaticRegisterNativesUInterface_Developer_Manipulation()
	{
		UClass* Class = UInterface_Developer_Manipulation::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetRotationAxisList", &IInterface_Developer_Manipulation::execGetRotationAxisList },
			{ "GetRotationDisabled", &IInterface_Developer_Manipulation::execGetRotationDisabled },
			{ "GetScaleAxisList", &IInterface_Developer_Manipulation::execGetScaleAxisList },
			{ "GetTranslationAxisList", &IInterface_Developer_Manipulation::execGetTranslationAxisList },
			{ "GetWorldTransform", &IInterface_Developer_Manipulation::execGetWorldTransform },
			{ "ManipulationBegin", &IInterface_Developer_Manipulation::execManipulationBegin },
			{ "ManipulationEnd", &IInterface_Developer_Manipulation::execManipulationEnd },
			{ "ManipulationInProgress", &IInterface_Developer_Manipulation::execManipulationInProgress },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics
	{
		static const UECodeGen_Private::FBytePropertyParams NewProp_axisList_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_axisList;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::NewProp_axisList_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::NewProp_axisList = { "axisList", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_Developer_Manipulation_eventGetRotationAxisList_Parms, axisList), Z_Construct_UEnum_VH_Developer_EAxisListBlueprint, METADATA_PARAMS(0, nullptr) }; // 2628997991
	void Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Interface_Developer_Manipulation_eventGetRotationAxisList_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Interface_Developer_Manipulation_eventGetRotationAxisList_Parms), &Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::NewProp_axisList_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::NewProp_axisList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Sets axisList to enabled axes for rotation\n\x09* \\return False to enable all axes; true to specify the axisList\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_Developer_Manipulation.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Sets axisList to enabled axes for rotation\n* \\return False to enable all axes; true to specify the axisList" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_Developer_Manipulation, nullptr, "GetRotationAxisList", nullptr, nullptr, Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::PropPointers), sizeof(Interface_Developer_Manipulation_eventGetRotationAxisList_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_Developer_Manipulation_eventGetRotationAxisList_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationDisabled_Statics
	{
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationDisabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Interface_Developer_Manipulation_eventGetRotationDisabled_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationDisabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Interface_Developer_Manipulation_eventGetRotationDisabled_Parms), &Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationDisabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationDisabled_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationDisabled_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationDisabled_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Returns true if rotation should be disabled\n\x09* \\return True to disable rotation\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_Developer_Manipulation.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Returns true if rotation should be disabled\n* \\return True to disable rotation" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationDisabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_Developer_Manipulation, nullptr, "GetRotationDisabled", nullptr, nullptr, Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationDisabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationDisabled_Statics::PropPointers), sizeof(Interface_Developer_Manipulation_eventGetRotationDisabled_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationDisabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationDisabled_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationDisabled_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_Developer_Manipulation_eventGetRotationDisabled_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationDisabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationDisabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics
	{
		static const UECodeGen_Private::FBytePropertyParams NewProp_axisList_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_axisList;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::NewProp_axisList_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::NewProp_axisList = { "axisList", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_Developer_Manipulation_eventGetScaleAxisList_Parms, axisList), Z_Construct_UEnum_VH_Developer_EAxisListBlueprint, METADATA_PARAMS(0, nullptr) }; // 2628997991
	void Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Interface_Developer_Manipulation_eventGetScaleAxisList_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Interface_Developer_Manipulation_eventGetScaleAxisList_Parms), &Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::NewProp_axisList_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::NewProp_axisList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Sets axisList to enabled axes for scale\n\x09* \\return False to enable all axes; true to specify the axisList\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_Developer_Manipulation.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Sets axisList to enabled axes for scale\n* \\return False to enable all axes; true to specify the axisList" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_Developer_Manipulation, nullptr, "GetScaleAxisList", nullptr, nullptr, Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::PropPointers), sizeof(Interface_Developer_Manipulation_eventGetScaleAxisList_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_Developer_Manipulation_eventGetScaleAxisList_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics
	{
		static const UECodeGen_Private::FBytePropertyParams NewProp_axisList_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_axisList;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::NewProp_axisList_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::NewProp_axisList = { "axisList", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_Developer_Manipulation_eventGetTranslationAxisList_Parms, axisList), Z_Construct_UEnum_VH_Developer_EAxisListBlueprint, METADATA_PARAMS(0, nullptr) }; // 2628997991
	void Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Interface_Developer_Manipulation_eventGetTranslationAxisList_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Interface_Developer_Manipulation_eventGetTranslationAxisList_Parms), &Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::NewProp_axisList_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::NewProp_axisList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Sets axisList to enabled axes for translation\n\x09* \\return False to enable all axes; true to specify the axisList\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_Developer_Manipulation.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Sets axisList to enabled axes for translation\n* \\return False to enable all axes; true to specify the axisList" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_Developer_Manipulation, nullptr, "GetTranslationAxisList", nullptr, nullptr, Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::PropPointers), sizeof(Interface_Developer_Manipulation_eventGetTranslationAxisList_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_Developer_Manipulation_eventGetTranslationAxisList_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_localToWorld;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform_Statics::NewProp_localToWorld = { "localToWorld", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_Developer_Manipulation_eventGetWorldTransform_Parms, localToWorld), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Interface_Developer_Manipulation_eventGetWorldTransform_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Interface_Developer_Manipulation_eventGetWorldTransform_Parms), &Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform_Statics::NewProp_localToWorld,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Allows override for local-to-world transform of this object; defaults to GetActorTransform() if not implemented\n\x09* \\return true if override should occur\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_Developer_Manipulation.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Allows override for local-to-world transform of this object; defaults to GetActorTransform() if not implemented\n* \\return true if override should occur" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_Developer_Manipulation, nullptr, "GetWorldTransform", nullptr, nullptr, Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform_Statics::PropPointers), sizeof(Interface_Developer_Manipulation_eventGetWorldTransform_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08C20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_Developer_Manipulation_eventGetWorldTransform_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationBegin_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationBegin_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Called when manipulation begins\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_Developer_Manipulation.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Called when manipulation begins" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_Developer_Manipulation, nullptr, "ManipulationBegin", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationBegin_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationBegin_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationEnd_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationEnd_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Called when manipulation ends\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_Developer_Manipulation.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Called when manipulation ends" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_Developer_Manipulation, nullptr, "ManipulationEnd", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationEnd_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationInProgress_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationInProgress_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Called after each manipulation\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_Developer_Manipulation.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Called after each manipulation" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationInProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_Developer_Manipulation, nullptr, "ManipulationInProgress", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationInProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationInProgress_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationInProgress()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationInProgress_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInterface_Developer_Manipulation);
	UClass* Z_Construct_UClass_UInterface_Developer_Manipulation_NoRegister()
	{
		return UInterface_Developer_Manipulation::StaticClass();
	}
	struct Z_Construct_UClass_UInterface_Developer_Manipulation_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInterface_Developer_Manipulation_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_Developer_Manipulation_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UInterface_Developer_Manipulation_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationAxisList, "GetRotationAxisList" }, // 624482339
		{ &Z_Construct_UFunction_UInterface_Developer_Manipulation_GetRotationDisabled, "GetRotationDisabled" }, // 1030407014
		{ &Z_Construct_UFunction_UInterface_Developer_Manipulation_GetScaleAxisList, "GetScaleAxisList" }, // 407506610
		{ &Z_Construct_UFunction_UInterface_Developer_Manipulation_GetTranslationAxisList, "GetTranslationAxisList" }, // 1444000968
		{ &Z_Construct_UFunction_UInterface_Developer_Manipulation_GetWorldTransform, "GetWorldTransform" }, // 939274293
		{ &Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationBegin, "ManipulationBegin" }, // 157717126
		{ &Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationEnd, "ManipulationEnd" }, // 580930004
		{ &Z_Construct_UFunction_UInterface_Developer_Manipulation_ManipulationInProgress, "ManipulationInProgress" }, // 1035659710
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_Developer_Manipulation_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInterface_Developer_Manipulation_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Public/Interface_Developer_Manipulation.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInterface_Developer_Manipulation_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInterface_Developer_Manipulation>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInterface_Developer_Manipulation_Statics::ClassParams = {
		&UInterface_Developer_Manipulation::StaticClass,
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
		0x001040A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_Developer_Manipulation_Statics::Class_MetaDataParams), Z_Construct_UClass_UInterface_Developer_Manipulation_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UInterface_Developer_Manipulation()
	{
		if (!Z_Registration_Info_UClass_UInterface_Developer_Manipulation.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInterface_Developer_Manipulation.OuterSingleton, Z_Construct_UClass_UInterface_Developer_Manipulation_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInterface_Developer_Manipulation.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UInterface_Developer_Manipulation>()
	{
		return UInterface_Developer_Manipulation::StaticClass();
	}
	UInterface_Developer_Manipulation::UInterface_Developer_Manipulation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInterface_Developer_Manipulation);
	UInterface_Developer_Manipulation::~UInterface_Developer_Manipulation() {}
	static FName NAME_UInterface_Developer_Manipulation_GetRotationAxisList = FName(TEXT("GetRotationAxisList"));
	bool IInterface_Developer_Manipulation::Execute_GetRotationAxisList(UObject* O, EAxisListBlueprint& axisList)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()));
		Interface_Developer_Manipulation_eventGetRotationAxisList_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_Developer_Manipulation_GetRotationAxisList);
		if (Func)
		{
			Parms.axisList=axisList;
			O->ProcessEvent(Func, &Parms);
			axisList=Parms.axisList;
		}
		else if (auto I = (IInterface_Developer_Manipulation*)(O->GetNativeInterfaceAddress(UInterface_Developer_Manipulation::StaticClass())))
		{
			Parms.ReturnValue = I->GetRotationAxisList_Implementation(axisList);
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UInterface_Developer_Manipulation_GetRotationDisabled = FName(TEXT("GetRotationDisabled"));
	bool IInterface_Developer_Manipulation::Execute_GetRotationDisabled(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()));
		Interface_Developer_Manipulation_eventGetRotationDisabled_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_Developer_Manipulation_GetRotationDisabled);
		if (Func)
		{
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInterface_Developer_Manipulation*)(O->GetNativeInterfaceAddress(UInterface_Developer_Manipulation::StaticClass())))
		{
			Parms.ReturnValue = I->GetRotationDisabled_Implementation();
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UInterface_Developer_Manipulation_GetScaleAxisList = FName(TEXT("GetScaleAxisList"));
	bool IInterface_Developer_Manipulation::Execute_GetScaleAxisList(UObject* O, EAxisListBlueprint& axisList)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()));
		Interface_Developer_Manipulation_eventGetScaleAxisList_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_Developer_Manipulation_GetScaleAxisList);
		if (Func)
		{
			Parms.axisList=axisList;
			O->ProcessEvent(Func, &Parms);
			axisList=Parms.axisList;
		}
		else if (auto I = (IInterface_Developer_Manipulation*)(O->GetNativeInterfaceAddress(UInterface_Developer_Manipulation::StaticClass())))
		{
			Parms.ReturnValue = I->GetScaleAxisList_Implementation(axisList);
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UInterface_Developer_Manipulation_GetTranslationAxisList = FName(TEXT("GetTranslationAxisList"));
	bool IInterface_Developer_Manipulation::Execute_GetTranslationAxisList(UObject* O, EAxisListBlueprint& axisList)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()));
		Interface_Developer_Manipulation_eventGetTranslationAxisList_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_Developer_Manipulation_GetTranslationAxisList);
		if (Func)
		{
			Parms.axisList=axisList;
			O->ProcessEvent(Func, &Parms);
			axisList=Parms.axisList;
		}
		else if (auto I = (IInterface_Developer_Manipulation*)(O->GetNativeInterfaceAddress(UInterface_Developer_Manipulation::StaticClass())))
		{
			Parms.ReturnValue = I->GetTranslationAxisList_Implementation(axisList);
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UInterface_Developer_Manipulation_GetWorldTransform = FName(TEXT("GetWorldTransform"));
	bool IInterface_Developer_Manipulation::Execute_GetWorldTransform(UObject* O, FTransform& localToWorld)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()));
		Interface_Developer_Manipulation_eventGetWorldTransform_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_Developer_Manipulation_GetWorldTransform);
		if (Func)
		{
			Parms.localToWorld=localToWorld;
			O->ProcessEvent(Func, &Parms);
			localToWorld=Parms.localToWorld;
		}
		else if (auto I = (IInterface_Developer_Manipulation*)(O->GetNativeInterfaceAddress(UInterface_Developer_Manipulation::StaticClass())))
		{
			Parms.ReturnValue = I->GetWorldTransform_Implementation(localToWorld);
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UInterface_Developer_Manipulation_ManipulationBegin = FName(TEXT("ManipulationBegin"));
	void IInterface_Developer_Manipulation::Execute_ManipulationBegin(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInterface_Developer_Manipulation_ManipulationBegin);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInterface_Developer_Manipulation*)(O->GetNativeInterfaceAddress(UInterface_Developer_Manipulation::StaticClass())))
		{
			I->ManipulationBegin_Implementation();
		}
	}
	static FName NAME_UInterface_Developer_Manipulation_ManipulationEnd = FName(TEXT("ManipulationEnd"));
	void IInterface_Developer_Manipulation::Execute_ManipulationEnd(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInterface_Developer_Manipulation_ManipulationEnd);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInterface_Developer_Manipulation*)(O->GetNativeInterfaceAddress(UInterface_Developer_Manipulation::StaticClass())))
		{
			I->ManipulationEnd_Implementation();
		}
	}
	static FName NAME_UInterface_Developer_Manipulation_ManipulationInProgress = FName(TEXT("ManipulationInProgress"));
	void IInterface_Developer_Manipulation::Execute_ManipulationInProgress(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_Developer_Manipulation::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_UInterface_Developer_Manipulation_ManipulationInProgress);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
		else if (auto I = (IInterface_Developer_Manipulation*)(O->GetNativeInterfaceAddress(UInterface_Developer_Manipulation::StaticClass())))
		{
			I->ManipulationInProgress_Implementation();
		}
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_Statics::EnumInfo[] = {
		{ EAxisListBlueprint_StaticEnum, TEXT("EAxisListBlueprint"), &Z_Registration_Info_UEnum_EAxisListBlueprint, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2628997991U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInterface_Developer_Manipulation, UInterface_Developer_Manipulation::StaticClass, TEXT("UInterface_Developer_Manipulation"), &Z_Registration_Info_UClass_UInterface_Developer_Manipulation, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInterface_Developer_Manipulation), 333838210U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_437146060(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Interface_Developer_Manipulation_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
