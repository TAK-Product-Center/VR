// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Core/Public/Developer_Statics.h"
#include "InputCoreTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDeveloper_Statics() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTimespan();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponent2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
	INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
	UPackage* Z_Construct_UPackage__Script_VH_Developer();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Statics();
	VH_DEVELOPER_API UClass* Z_Construct_UClass_UDeveloper_Statics_NoRegister();
	VH_DEVELOPER_API UEnum* Z_Construct_UEnum_VH_Developer_EDriveType();
	VH_DEVELOPER_API UEnum* Z_Construct_UEnum_VH_Developer_ELogMessageColor();
	VH_DEVELOPER_API UEnum* Z_Construct_UEnum_VH_Developer_ELogMessageVerbosityLevel();
	VH_DEVELOPER_API UEnum* Z_Construct_UEnum_VH_Developer_EVH_NetMode();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ELogMessageVerbosityLevel;
	static UEnum* ELogMessageVerbosityLevel_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ELogMessageVerbosityLevel.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ELogMessageVerbosityLevel.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_Developer_ELogMessageVerbosityLevel, (UObject*)Z_Construct_UPackage__Script_VH_Developer(), TEXT("ELogMessageVerbosityLevel"));
		}
		return Z_Registration_Info_UEnum_ELogMessageVerbosityLevel.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UEnum* StaticEnum<ELogMessageVerbosityLevel>()
	{
		return ELogMessageVerbosityLevel_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_Developer_ELogMessageVerbosityLevel_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_Developer_ELogMessageVerbosityLevel_Statics::Enumerators[] = {
		{ "ELogMessageVerbosityLevel::Log", (int64)ELogMessageVerbosityLevel::Log },
		{ "ELogMessageVerbosityLevel::Warning", (int64)ELogMessageVerbosityLevel::Warning },
		{ "ELogMessageVerbosityLevel::Error", (int64)ELogMessageVerbosityLevel::Error },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_Developer_ELogMessageVerbosityLevel_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Enums\n// ---------------------------------\n" },
#endif
		{ "Error.Name", "ELogMessageVerbosityLevel::Error" },
		{ "Log.Name", "ELogMessageVerbosityLevel::Log" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Enums" },
#endif
		{ "Warning.Name", "ELogMessageVerbosityLevel::Warning" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_Developer_ELogMessageVerbosityLevel_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_Developer,
		nullptr,
		"ELogMessageVerbosityLevel",
		"ELogMessageVerbosityLevel",
		Z_Construct_UEnum_VH_Developer_ELogMessageVerbosityLevel_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Developer_ELogMessageVerbosityLevel_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Developer_ELogMessageVerbosityLevel_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_Developer_ELogMessageVerbosityLevel_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_Developer_ELogMessageVerbosityLevel()
	{
		if (!Z_Registration_Info_UEnum_ELogMessageVerbosityLevel.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ELogMessageVerbosityLevel.InnerSingleton, Z_Construct_UEnum_VH_Developer_ELogMessageVerbosityLevel_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ELogMessageVerbosityLevel.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ELogMessageColor;
	static UEnum* ELogMessageColor_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ELogMessageColor.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ELogMessageColor.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_Developer_ELogMessageColor, (UObject*)Z_Construct_UPackage__Script_VH_Developer(), TEXT("ELogMessageColor"));
		}
		return Z_Registration_Info_UEnum_ELogMessageColor.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UEnum* StaticEnum<ELogMessageColor>()
	{
		return ELogMessageColor_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_Developer_ELogMessageColor_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_Developer_ELogMessageColor_Statics::Enumerators[] = {
		{ "ELogMessageColor::None", (int64)ELogMessageColor::None },
		{ "ELogMessageColor::DarkRed", (int64)ELogMessageColor::DarkRed },
		{ "ELogMessageColor::DarkGreen", (int64)ELogMessageColor::DarkGreen },
		{ "ELogMessageColor::DarkBlue", (int64)ELogMessageColor::DarkBlue },
		{ "ELogMessageColor::DarkYellow", (int64)ELogMessageColor::DarkYellow },
		{ "ELogMessageColor::DarkCyan", (int64)ELogMessageColor::DarkCyan },
		{ "ELogMessageColor::DarkPurple", (int64)ELogMessageColor::DarkPurple },
		{ "ELogMessageColor::Red", (int64)ELogMessageColor::Red },
		{ "ELogMessageColor::Green", (int64)ELogMessageColor::Green },
		{ "ELogMessageColor::Blue", (int64)ELogMessageColor::Blue },
		{ "ELogMessageColor::Yellow", (int64)ELogMessageColor::Yellow },
		{ "ELogMessageColor::Cyan", (int64)ELogMessageColor::Cyan },
		{ "ELogMessageColor::Purple", (int64)ELogMessageColor::Purple },
		{ "ELogMessageColor::White", (int64)ELogMessageColor::White },
		{ "ELogMessageColor::Black", (int64)ELogMessageColor::Black },
		{ "ELogMessageColor::Gray", (int64)ELogMessageColor::Gray },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_Developer_ELogMessageColor_Statics::Enum_MetaDataParams[] = {
		{ "Black.Name", "ELogMessageColor::Black" },
		{ "Blue.Name", "ELogMessageColor::Blue" },
		{ "BlueprintType", "true" },
		{ "Cyan.Name", "ELogMessageColor::Cyan" },
		{ "DarkBlue.Name", "ELogMessageColor::DarkBlue" },
		{ "DarkCyan.Name", "ELogMessageColor::DarkCyan" },
		{ "DarkGreen.Name", "ELogMessageColor::DarkGreen" },
		{ "DarkPurple.Name", "ELogMessageColor::DarkPurple" },
		{ "DarkRed.Name", "ELogMessageColor::DarkRed" },
		{ "DarkYellow.Name", "ELogMessageColor::DarkYellow" },
		{ "Gray.Name", "ELogMessageColor::Gray" },
		{ "Green.Name", "ELogMessageColor::Green" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
		{ "None.Name", "ELogMessageColor::None" },
		{ "Purple.Name", "ELogMessageColor::Purple" },
		{ "Red.Name", "ELogMessageColor::Red" },
		{ "White.Name", "ELogMessageColor::White" },
		{ "Yellow.Name", "ELogMessageColor::Yellow" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_Developer_ELogMessageColor_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_Developer,
		nullptr,
		"ELogMessageColor",
		"ELogMessageColor",
		Z_Construct_UEnum_VH_Developer_ELogMessageColor_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Developer_ELogMessageColor_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Developer_ELogMessageColor_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_Developer_ELogMessageColor_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_Developer_ELogMessageColor()
	{
		if (!Z_Registration_Info_UEnum_ELogMessageColor.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ELogMessageColor.InnerSingleton, Z_Construct_UEnum_VH_Developer_ELogMessageColor_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ELogMessageColor.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDriveType;
	static UEnum* EDriveType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EDriveType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EDriveType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_Developer_EDriveType, (UObject*)Z_Construct_UPackage__Script_VH_Developer(), TEXT("EDriveType"));
		}
		return Z_Registration_Info_UEnum_EDriveType.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UEnum* StaticEnum<EDriveType>()
	{
		return EDriveType_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_Developer_EDriveType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_Developer_EDriveType_Statics::Enumerators[] = {
		{ "EDriveType::Unknown", (int64)EDriveType::Unknown },
		{ "EDriveType::NoRootDir", (int64)EDriveType::NoRootDir },
		{ "EDriveType::Removable", (int64)EDriveType::Removable },
		{ "EDriveType::Fixed", (int64)EDriveType::Fixed },
		{ "EDriveType::Remote", (int64)EDriveType::Remote },
		{ "EDriveType::CDRom", (int64)EDriveType::CDRom },
		{ "EDriveType::RamDisk", (int64)EDriveType::RamDisk },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_Developer_EDriveType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CDRom.Name", "EDriveType::CDRom" },
		{ "Fixed.Name", "EDriveType::Fixed" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
		{ "NoRootDir.Name", "EDriveType::NoRootDir" },
		{ "RamDisk.Name", "EDriveType::RamDisk" },
		{ "Remote.Name", "EDriveType::Remote" },
		{ "Removable.Name", "EDriveType::Removable" },
		{ "Unknown.Name", "EDriveType::Unknown" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_Developer_EDriveType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_Developer,
		nullptr,
		"EDriveType",
		"EDriveType",
		Z_Construct_UEnum_VH_Developer_EDriveType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Developer_EDriveType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Developer_EDriveType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_Developer_EDriveType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_Developer_EDriveType()
	{
		if (!Z_Registration_Info_UEnum_EDriveType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDriveType.InnerSingleton, Z_Construct_UEnum_VH_Developer_EDriveType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EDriveType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EVH_NetMode;
	static UEnum* EVH_NetMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EVH_NetMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EVH_NetMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_Developer_EVH_NetMode, (UObject*)Z_Construct_UPackage__Script_VH_Developer(), TEXT("EVH_NetMode"));
		}
		return Z_Registration_Info_UEnum_EVH_NetMode.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UEnum* StaticEnum<EVH_NetMode>()
	{
		return EVH_NetMode_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_Developer_EVH_NetMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_Developer_EVH_NetMode_Statics::Enumerators[] = {
		{ "EVH_NetMode::NM_Standalone", (int64)EVH_NetMode::NM_Standalone },
		{ "EVH_NetMode::NM_DedicatedServer", (int64)EVH_NetMode::NM_DedicatedServer },
		{ "EVH_NetMode::NM_ListenServer", (int64)EVH_NetMode::NM_ListenServer },
		{ "EVH_NetMode::NM_Client", (int64)EVH_NetMode::NM_Client },
		{ "EVH_NetMode::NM_MAX", (int64)EVH_NetMode::NM_MAX },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_Developer_EVH_NetMode_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// copied from Engine because ENetMode not blueprint accessible\n" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
		{ "NM_Client.Comment", "/*\n\x09 * Network client: client connected to a remote server.\n\x09 * Note that every mode less than this value is a kind of server, so checking NetMode < NM_Client is always some variety of server.\n\x09 */" },
		{ "NM_Client.Name", "EVH_NetMode::NM_Client" },
		{ "NM_Client.ToolTip", "* Network client: client connected to a remote server.\n* Note that every mode less than this value is a kind of server, so checking NetMode < NM_Client is always some variety of server." },
		{ "NM_DedicatedServer.Comment", "/* Dedicated server: server with no local players. */" },
		{ "NM_DedicatedServer.Name", "EVH_NetMode::NM_DedicatedServer" },
		{ "NM_DedicatedServer.ToolTip", "Dedicated server: server with no local players." },
		{ "NM_ListenServer.Comment", "/* Listen server: a server that also has a local player who is hosting the game, available to other players on the network. */" },
		{ "NM_ListenServer.Name", "EVH_NetMode::NM_ListenServer" },
		{ "NM_ListenServer.ToolTip", "Listen server: a server that also has a local player who is hosting the game, available to other players on the network." },
		{ "NM_MAX.Name", "EVH_NetMode::NM_MAX" },
		{ "NM_Standalone.Comment", "/* Standalone: a game without networking, with one or more local players. Still considered a server because it has all server functionality. */" },
		{ "NM_Standalone.Name", "EVH_NetMode::NM_Standalone" },
		{ "NM_Standalone.ToolTip", "Standalone: a game without networking, with one or more local players. Still considered a server because it has all server functionality." },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "copied from Engine because ENetMode not blueprint accessible" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_Developer_EVH_NetMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_Developer,
		nullptr,
		"EVH_NetMode",
		"EVH_NetMode",
		Z_Construct_UEnum_VH_Developer_EVH_NetMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Developer_EVH_NetMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_Developer_EVH_NetMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_Developer_EVH_NetMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_Developer_EVH_NetMode()
	{
		if (!Z_Registration_Info_UEnum_EVH_NetMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EVH_NetMode.InnerSingleton, Z_Construct_UEnum_VH_Developer_EVH_NetMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EVH_NetMode.InnerSingleton;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execDateTimeToFormattedString)
	{
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_dateTime);
		P_GET_PROPERTY(FStrProperty,Z_Param_format);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UDeveloper_Statics::DateTimeToFormattedString(Z_Param_Out_dateTime,Z_Param_format);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execTimeSpanToString)
	{
		P_GET_STRUCT_REF(FTimespan,Z_Param_Out_timespan);
		P_GET_PROPERTY(FStrProperty,Z_Param_format);
		P_GET_UBOOL(Z_Param_bIncludePlusMinus);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UDeveloper_Statics::TimeSpanToString(Z_Param_Out_timespan,Z_Param_format,Z_Param_bIncludePlusMinus);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execDoubleToString)
	{
		P_GET_PROPERTY(FDoubleProperty,Z_Param_inValue);
		P_GET_PROPERTY(FIntProperty,Z_Param_numDecimalPlaces);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UDeveloper_Statics::DoubleToString(Z_Param_inValue,Z_Param_numDecimalPlaces);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execIsClient)
	{
		P_GET_OBJECT(UObject,Z_Param_worldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDeveloper_Statics::IsClient(Z_Param_worldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execDeprojectSceneCaptureComponent2DToWorld)
	{
		P_GET_OBJECT(USceneCaptureComponent2D,Z_Param_SceneCaptureComponent2D);
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_TargetUV);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_WorldPosition);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_WorldDirection);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDeveloper_Statics::DeprojectSceneCaptureComponent2DToWorld(Z_Param_SceneCaptureComponent2D,Z_Param_Out_TargetUV,Z_Param_Out_WorldPosition,Z_Param_Out_WorldDirection);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execSendKeyChar)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_keyString);
		P_GET_UBOOL(Z_Param_bRepeat);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDeveloper_Statics::SendKeyChar(Z_Param_keyString,Z_Param_bRepeat);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execPressAndReleaseKey)
	{
		P_GET_STRUCT_REF(FKey,Z_Param_Out_key);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDeveloper_Statics::PressAndReleaseKey(Z_Param_Out_key);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execReleaseKey)
	{
		P_GET_STRUCT_REF(FKey,Z_Param_Out_key);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDeveloper_Statics::ReleaseKey(Z_Param_Out_key);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execPressKey)
	{
		P_GET_STRUCT_REF(FKey,Z_Param_Out_key);
		P_GET_UBOOL(Z_Param_bRepeat);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDeveloper_Statics::PressKey(Z_Param_Out_key,Z_Param_bRepeat);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetPlayerViewpoint)
	{
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_localToWorld);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDeveloper_Statics::GetPlayerViewpoint(Z_Param_Out_localToWorld);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execCompareStringBP)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_stringA);
		P_GET_PROPERTY(FStrProperty,Z_Param_stringB);
		P_GET_UBOOL(Z_Param_isCaseSensitive);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UDeveloper_Statics::CompareStringBP(Z_Param_stringA,Z_Param_stringB,Z_Param_isCaseSensitive);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetDPIScaleFactorAtPoint)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_mouseX);
		P_GET_PROPERTY(FFloatProperty,Z_Param_mouseY);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UDeveloper_Statics::GetDPIScaleFactorAtPoint(Z_Param_mouseX,Z_Param_mouseY);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execVerifyMultihome)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDeveloper_Statics::VerifyMultihome();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetNetInfo)
	{
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_ipAddress);
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_netAdapter);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDeveloper_Statics::GetNetInfo(Z_Param_Out_ipAddress,Z_Param_Out_netAdapter);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execExploreFolderOrFile)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_folderOrFilePath);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDeveloper_Statics::ExploreFolderOrFile(Z_Param_folderOrFilePath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execExecuteFile)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_cmdCommand);
		P_GET_PROPERTY(FStrProperty,Z_Param_cmdParams);
		P_GET_UBOOL(Z_Param_bWaitForFinish);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDeveloper_Statics::ExecuteFile(Z_Param_cmdCommand,Z_Param_cmdParams,Z_Param_bWaitForFinish);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execOpenFileWithDefaultApp)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_pathToFile);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDeveloper_Statics::OpenFileWithDefaultApp(Z_Param_pathToFile);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execOpenFolderWithDefaultApp)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_fullPathToFolder);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDeveloper_Statics::OpenFolderWithDefaultApp(Z_Param_fullPathToFolder);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execK2_HasLocalNetOwner)
	{
		P_GET_OBJECT(AActor,Z_Param_actor);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDeveloper_Statics::K2_HasLocalNetOwner(Z_Param_actor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetActorNetMode)
	{
		P_GET_OBJECT(AActor,Z_Param_actor);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EVH_NetMode*)Z_Param__Result=UDeveloper_Statics::GetActorNetMode(Z_Param_actor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetFromClipboard)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UDeveloper_Statics::GetFromClipboard();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execSendToClipboard)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_inString);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDeveloper_Statics::SendToClipboard(Z_Param_inString);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execParseCommandLineParams)
	{
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_commandLine);
		P_GET_TARRAY_REF(FString,Z_Param_Out_tokens);
		P_GET_TARRAY_REF(FString,Z_Param_Out_switches);
		P_GET_TARRAY_REF(FString,Z_Param_Out_args);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDeveloper_Statics::ParseCommandLineParams(Z_Param_Out_commandLine,Z_Param_Out_tokens,Z_Param_Out_switches,Z_Param_Out_args);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetClassObjectFromFullName)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_fullName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UClass**)Z_Param__Result=UDeveloper_Statics::GetClassObjectFromFullName(Z_Param_fullName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetClassObjectFromPath)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_path);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UClass**)Z_Param__Result=UDeveloper_Statics::GetClassObjectFromPath(Z_Param_path);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execDateTimeToString)
	{
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_dateTime);
		P_GET_PROPERTY(FStrProperty,Z_Param_format);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UDeveloper_Statics::DateTimeToString(Z_Param_Out_dateTime,Z_Param_format);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execDateTimeFromISO8601)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_DateTimeISO8601);
		P_GET_STRUCT_REF(FDateTime,Z_Param_Out_OutDateTime);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDeveloper_Statics::DateTimeFromISO8601(Z_Param_DateTimeISO8601,Z_Param_Out_OutDateTime);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execConvertToPlatformPath)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_unrealEnginePath);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UDeveloper_Statics::ConvertToPlatformPath(Z_Param_unrealEnginePath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execFormatFloat)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_inFloat);
		P_GET_PROPERTY(FIntProperty,Z_Param_numDecimals);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UDeveloper_Statics::FormatFloat(Z_Param_inFloat,Z_Param_numDecimals);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execCreateTextureFromPixels)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_width);
		P_GET_PROPERTY(FIntProperty,Z_Param_height);
		P_GET_TARRAY_REF(uint8,Z_Param_Out_pixelData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UTexture2D**)Z_Param__Result=UDeveloper_Statics::CreateTextureFromPixels(Z_Param_width,Z_Param_height,Z_Param_Out_pixelData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetStackTrace)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_maxLines);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UDeveloper_Statics::GetStackTrace(Z_Param_maxLines);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execPrintMessage)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_message);
		P_GET_UBOOL(Z_Param_bPrintToScreen);
		P_GET_UBOOL(Z_Param_bPrintToConsole);
		P_GET_UBOOL(Z_Param_bPrintToLog);
		P_GET_ENUM(ELogMessageVerbosityLevel,Z_Param_verbosityLevel);
		P_GET_UBOOL(Z_Param_bShowStackTrace);
		P_GET_ENUM(ELogMessageColor,Z_Param_logColor);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDeveloper_Statics::PrintMessage(Z_Param_message,Z_Param_bPrintToScreen,Z_Param_bPrintToConsole,Z_Param_bPrintToLog,ELogMessageVerbosityLevel(Z_Param_verbosityLevel),Z_Param_bShowStackTrace,ELogMessageColor(Z_Param_logColor));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execFixedCollapseRelativeDirectoriesInline)
	{
		P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_path);
		P_FINISH;
		P_NATIVE_BEGIN;
		UDeveloper_Statics::FixedCollapseRelativeDirectoriesInline(Z_Param_Out_path);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetLogicalDriveType)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_drive);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EDriveType*)Z_Param__Result=UDeveloper_Statics::GetLogicalDriveType(Z_Param_drive);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetLogicalDrives)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<FString>*)Z_Param__Result=UDeveloper_Statics::GetLogicalDrives();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetUserVideosPath)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UDeveloper_Statics::GetUserVideosPath();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetUserPicturesPath)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UDeveloper_Statics::GetUserPicturesPath();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetUserProfilePath)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UDeveloper_Statics::GetUserProfilePath();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetUserAppDataPath)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UDeveloper_Statics::GetUserAppDataPath();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetCommonAppDataPath)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UDeveloper_Statics::GetCommonAppDataPath();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execIsPlayInVulkanPreview)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDeveloper_Statics::IsPlayInVulkanPreview();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execIsPlayInMobilePreview)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDeveloper_Statics::IsPlayInMobilePreview();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execIsPlayInPreview)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDeveloper_Statics::IsPlayInPreview();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execIsPlayInEditor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDeveloper_Statics::IsPlayInEditor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetVHIsBuildTest)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDeveloper_Statics::GetVHIsBuildTest();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetVHIsBuildShipping)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDeveloper_Statics::GetVHIsBuildShipping();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetVHIsWithEditor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDeveloper_Statics::GetVHIsWithEditor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execIsListenServer)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UDeveloper_Statics::IsListenServer(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UDeveloper_Statics::execGetVHWorld)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UWorld**)Z_Param__Result=UDeveloper_Statics::GetVHWorld();
		P_NATIVE_END;
	}
	void UDeveloper_Statics::StaticRegisterNativesUDeveloper_Statics()
	{
		UClass* Class = UDeveloper_Statics::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CompareStringBP", &UDeveloper_Statics::execCompareStringBP },
			{ "ConvertToPlatformPath", &UDeveloper_Statics::execConvertToPlatformPath },
			{ "CreateTextureFromPixels", &UDeveloper_Statics::execCreateTextureFromPixels },
			{ "DateTimeFromISO8601", &UDeveloper_Statics::execDateTimeFromISO8601 },
			{ "DateTimeToFormattedString", &UDeveloper_Statics::execDateTimeToFormattedString },
			{ "DateTimeToString", &UDeveloper_Statics::execDateTimeToString },
			{ "DeprojectSceneCaptureComponent2DToWorld", &UDeveloper_Statics::execDeprojectSceneCaptureComponent2DToWorld },
			{ "DoubleToString", &UDeveloper_Statics::execDoubleToString },
			{ "ExecuteFile", &UDeveloper_Statics::execExecuteFile },
			{ "ExploreFolderOrFile", &UDeveloper_Statics::execExploreFolderOrFile },
			{ "FixedCollapseRelativeDirectoriesInline", &UDeveloper_Statics::execFixedCollapseRelativeDirectoriesInline },
			{ "FormatFloat", &UDeveloper_Statics::execFormatFloat },
			{ "GetActorNetMode", &UDeveloper_Statics::execGetActorNetMode },
			{ "GetClassObjectFromFullName", &UDeveloper_Statics::execGetClassObjectFromFullName },
			{ "GetClassObjectFromPath", &UDeveloper_Statics::execGetClassObjectFromPath },
			{ "GetCommonAppDataPath", &UDeveloper_Statics::execGetCommonAppDataPath },
			{ "GetDPIScaleFactorAtPoint", &UDeveloper_Statics::execGetDPIScaleFactorAtPoint },
			{ "GetFromClipboard", &UDeveloper_Statics::execGetFromClipboard },
			{ "GetLogicalDrives", &UDeveloper_Statics::execGetLogicalDrives },
			{ "GetLogicalDriveType", &UDeveloper_Statics::execGetLogicalDriveType },
			{ "GetNetInfo", &UDeveloper_Statics::execGetNetInfo },
			{ "GetPlayerViewpoint", &UDeveloper_Statics::execGetPlayerViewpoint },
			{ "GetStackTrace", &UDeveloper_Statics::execGetStackTrace },
			{ "GetUserAppDataPath", &UDeveloper_Statics::execGetUserAppDataPath },
			{ "GetUserPicturesPath", &UDeveloper_Statics::execGetUserPicturesPath },
			{ "GetUserProfilePath", &UDeveloper_Statics::execGetUserProfilePath },
			{ "GetUserVideosPath", &UDeveloper_Statics::execGetUserVideosPath },
			{ "GetVHIsBuildShipping", &UDeveloper_Statics::execGetVHIsBuildShipping },
			{ "GetVHIsBuildTest", &UDeveloper_Statics::execGetVHIsBuildTest },
			{ "GetVHIsWithEditor", &UDeveloper_Statics::execGetVHIsWithEditor },
			{ "GetVHWorld", &UDeveloper_Statics::execGetVHWorld },
			{ "IsClient", &UDeveloper_Statics::execIsClient },
			{ "IsListenServer", &UDeveloper_Statics::execIsListenServer },
			{ "IsPlayInEditor", &UDeveloper_Statics::execIsPlayInEditor },
			{ "IsPlayInMobilePreview", &UDeveloper_Statics::execIsPlayInMobilePreview },
			{ "IsPlayInPreview", &UDeveloper_Statics::execIsPlayInPreview },
			{ "IsPlayInVulkanPreview", &UDeveloper_Statics::execIsPlayInVulkanPreview },
			{ "K2_HasLocalNetOwner", &UDeveloper_Statics::execK2_HasLocalNetOwner },
			{ "OpenFileWithDefaultApp", &UDeveloper_Statics::execOpenFileWithDefaultApp },
			{ "OpenFolderWithDefaultApp", &UDeveloper_Statics::execOpenFolderWithDefaultApp },
			{ "ParseCommandLineParams", &UDeveloper_Statics::execParseCommandLineParams },
			{ "PressAndReleaseKey", &UDeveloper_Statics::execPressAndReleaseKey },
			{ "PressKey", &UDeveloper_Statics::execPressKey },
			{ "PrintMessage", &UDeveloper_Statics::execPrintMessage },
			{ "ReleaseKey", &UDeveloper_Statics::execReleaseKey },
			{ "SendKeyChar", &UDeveloper_Statics::execSendKeyChar },
			{ "SendToClipboard", &UDeveloper_Statics::execSendToClipboard },
			{ "TimeSpanToString", &UDeveloper_Statics::execTimeSpanToString },
			{ "VerifyMultihome", &UDeveloper_Statics::execVerifyMultihome },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics
	{
		struct Developer_Statics_eventCompareStringBP_Parms
		{
			FString stringA;
			FString stringB;
			bool isCaseSensitive;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_stringA;
		static const UECodeGen_Private::FStrPropertyParams NewProp_stringB;
		static void NewProp_isCaseSensitive_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_isCaseSensitive;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::NewProp_stringA = { "stringA", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventCompareStringBP_Parms, stringA), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::NewProp_stringB = { "stringB", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventCompareStringBP_Parms, stringB), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::NewProp_isCaseSensitive_SetBit(void* Obj)
	{
		((Developer_Statics_eventCompareStringBP_Parms*)Obj)->isCaseSensitive = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::NewProp_isCaseSensitive = { "isCaseSensitive", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventCompareStringBP_Parms), &Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::NewProp_isCaseSensitive_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventCompareStringBP_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::NewProp_stringA,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::NewProp_stringB,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::NewProp_isCaseSensitive,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Exposes the string compare function to blueprint*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Exposes the string compare function to blueprint" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "CompareStringBP", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::Developer_Statics_eventCompareStringBP_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::Developer_Statics_eventCompareStringBP_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics
	{
		struct Developer_Statics_eventConvertToPlatformPath_Parms
		{
			FString unrealEnginePath;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_unrealEnginePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_unrealEnginePath;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::NewProp_unrealEnginePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::NewProp_unrealEnginePath = { "unrealEnginePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventConvertToPlatformPath_Parms, unrealEnginePath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::NewProp_unrealEnginePath_MetaData), Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::NewProp_unrealEnginePath_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventConvertToPlatformPath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::NewProp_unrealEnginePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|Format" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * @brief\x09This function is used to convert a standard Unreal Engine path to the current operating system path. This is \n\x09 *\x09\x09\x09particularly useful when using Windows format and need the slashes to be '\\' rather than '/'.\n\x09 *\n\x09 * @return\x09static FString - The return will be the full path in the format of the current operating system platform.\n\x09 */" },
#endif
		{ "DisplayName", "VH Convert To Platform Path" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* @brief       This function is used to convert a standard Unreal Engine path to the current operating system path. This is\n*                      particularly useful when using Windows format and need the slashes to be '\\' rather than '/'.\n*\n* @return      static FString - The return will be the full path in the format of the current operating system platform." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "ConvertToPlatformPath", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::Developer_Statics_eventConvertToPlatformPath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::Developer_Statics_eventConvertToPlatformPath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics
	{
		struct Developer_Statics_eventCreateTextureFromPixels_Parms
		{
			int32 width;
			int32 height;
			TArray<uint8> pixelData;
			UTexture2D* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_width;
		static const UECodeGen_Private::FIntPropertyParams NewProp_height;
		static const UECodeGen_Private::FBytePropertyParams NewProp_pixelData_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pixelData_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_pixelData;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::NewProp_width = { "width", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventCreateTextureFromPixels_Parms, width), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::NewProp_height = { "height", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventCreateTextureFromPixels_Parms, height), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::NewProp_pixelData_Inner = { "pixelData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::NewProp_pixelData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::NewProp_pixelData = { "pixelData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventCreateTextureFromPixels_Parms, pixelData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::NewProp_pixelData_MetaData), Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::NewProp_pixelData_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventCreateTextureFromPixels_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::NewProp_width,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::NewProp_height,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::NewProp_pixelData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::NewProp_pixelData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "CreateTextureFromPixels", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::Developer_Statics_eventCreateTextureFromPixels_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::Developer_Statics_eventCreateTextureFromPixels_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics
	{
		struct Developer_Statics_eventDateTimeFromISO8601_Parms
		{
			FString DateTimeISO8601;
			FDateTime OutDateTime;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DateTimeISO8601_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_DateTimeISO8601;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutDateTime;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::NewProp_DateTimeISO8601_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::NewProp_DateTimeISO8601 = { "DateTimeISO8601", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventDateTimeFromISO8601_Parms, DateTimeISO8601), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::NewProp_DateTimeISO8601_MetaData), Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::NewProp_DateTimeISO8601_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::NewProp_OutDateTime = { "OutDateTime", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventDateTimeFromISO8601_Parms, OutDateTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Statics_eventDateTimeFromISO8601_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventDateTimeFromISO8601_Parms), &Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::NewProp_DateTimeISO8601,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::NewProp_OutDateTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|Conversion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Parses an ISO 8601 string (e.g. \"2019-02-06T20:04:26Z\") into a UE4 DateTime. See https://en.wikipedia.org/wiki/ISO_8601 for more details. */" },
#endif
		{ "DisplayName", "VH DateTime From ISO8601" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Parses an ISO 8601 string (e.g. \"2019-02-06T20:04:26Z\") into a UE4 DateTime. See https://en.wikipedia.org/wiki/ISO_8601 for more details." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "DateTimeFromISO8601", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::Developer_Statics_eventDateTimeFromISO8601_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::Developer_Statics_eventDateTimeFromISO8601_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics
	{
		struct Developer_Statics_eventDateTimeToFormattedString_Parms
		{
			FDateTime dateTime;
			FString format;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_dateTime_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_dateTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_format_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_format;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::NewProp_dateTime_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::NewProp_dateTime = { "dateTime", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventDateTimeToFormattedString_Parms, dateTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::NewProp_dateTime_MetaData), Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::NewProp_dateTime_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::NewProp_format_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::NewProp_format = { "format", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventDateTimeToFormattedString_Parms, format), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::NewProp_format_MetaData), Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::NewProp_format_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventDateTimeToFormattedString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::NewProp_dateTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::NewProp_format,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::Function_MetaDataParams[] = {
		{ "DisplayName", "VH DateTime To Formatted String" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "DateTimeToFormattedString", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::Developer_Statics_eventDateTimeToFormattedString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C42401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::Developer_Statics_eventDateTimeToFormattedString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics
	{
		struct Developer_Statics_eventDateTimeToString_Parms
		{
			FDateTime dateTime;
			FString format;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_dateTime_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_dateTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_format_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_format;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::NewProp_dateTime_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::NewProp_dateTime = { "dateTime", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventDateTimeToString_Parms, dateTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::NewProp_dateTime_MetaData), Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::NewProp_dateTime_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::NewProp_format_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::NewProp_format = { "format", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventDateTimeToString_Parms, format), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::NewProp_format_MetaData), Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::NewProp_format_MetaData) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventDateTimeToString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::NewProp_dateTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::NewProp_format,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|Conversion" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Outputs string of DateTime based on passed in format\n\x09* \\param dateTime DateTime to generate string from\n\x09* \\param format Format of generated string (see notes below)\n\x09* \\return String generated from dateTime\n\x09*\n\x09*\x09""Ex: %Y.%m.%d-%H.%M.%S\n\x09*\x09""case TCHAR('a'): Result += IsMorning() ? TEXT(\"am\") : TEXT(\"pm\"); break;\n\x09*\x09""case TCHAR('A'): Result += IsMorning() ? TEXT(\"AM\") : TEXT(\"PM\"); break;\n\x09*\x09""case TCHAR('d'): Result += FString::Printf(TEXT(\"%02i\"), GetDay()); break;\n\x09*\x09""case TCHAR('D'): Result += FString::Printf(TEXT(\"%03i\"), GetDayOfYear()); break;\n\x09*\x09""case TCHAR('m'): Result += FString::Printf(TEXT(\"%02i\"), GetMonth()); break;\n\x09*\x09""case TCHAR('y'): Result += FString::Printf(TEXT(\"%02i\"), GetYear() % 100); break;\n\x09*\x09""case TCHAR('Y'): Result += FString::Printf(TEXT(\"%04i\"), GetYear()); break;\n\x09*\x09""case TCHAR('h'): Result += FString::Printf(TEXT(\"%02i\"), GetHour12()); break;\n\x09*\x09""case TCHAR('H'): Result += FString::Printf(TEXT(\"%02i\"), GetHour()); break;\n\x09*\x09""case TCHAR('M'): Result += FString::Printf(TEXT(\"%02i\"), GetMinute()); break;\n\x09*\x09""case TCHAR('S'): Result += FString::Printf(TEXT(\"%02i\"), GetSecond()); break;\n\x09*\x09""case TCHAR('s'): Result += FString::Printf(TEXT(\"%03i\"), GetMillisecond()); break;\n\x09*/" },
#endif
		{ "DisplayName", "VH DateTime To String" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Outputs string of DateTime based on passed in format\n* \\param dateTime DateTime to generate string from\n* \\param format Format of generated string (see notes below)\n* \\return String generated from dateTime\n*\n*       Ex: %Y.%m.%d-%H.%M.%S\n*       case TCHAR('a'): Result += IsMorning() ? TEXT(\"am\") : TEXT(\"pm\"); break;\n*       case TCHAR('A'): Result += IsMorning() ? TEXT(\"AM\") : TEXT(\"PM\"); break;\n*       case TCHAR('d'): Result += FString::Printf(TEXT(\"%02i\"), GetDay()); break;\n*       case TCHAR('D'): Result += FString::Printf(TEXT(\"%03i\"), GetDayOfYear()); break;\n*       case TCHAR('m'): Result += FString::Printf(TEXT(\"%02i\"), GetMonth()); break;\n*       case TCHAR('y'): Result += FString::Printf(TEXT(\"%02i\"), GetYear() % 100); break;\n*       case TCHAR('Y'): Result += FString::Printf(TEXT(\"%04i\"), GetYear()); break;\n*       case TCHAR('h'): Result += FString::Printf(TEXT(\"%02i\"), GetHour12()); break;\n*       case TCHAR('H'): Result += FString::Printf(TEXT(\"%02i\"), GetHour()); break;\n*       case TCHAR('M'): Result += FString::Printf(TEXT(\"%02i\"), GetMinute()); break;\n*       case TCHAR('S'): Result += FString::Printf(TEXT(\"%02i\"), GetSecond()); break;\n*       case TCHAR('s'): Result += FString::Printf(TEXT(\"%03i\"), GetMillisecond()); break;" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "DateTimeToString", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::Developer_Statics_eventDateTimeToString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::Developer_Statics_eventDateTimeToString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics
	{
		struct Developer_Statics_eventDeprojectSceneCaptureComponent2DToWorld_Parms
		{
			USceneCaptureComponent2D* SceneCaptureComponent2D;
			FVector2D TargetUV;
			FVector WorldPosition;
			FVector WorldDirection;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SceneCaptureComponent2D_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneCaptureComponent2D;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetUV_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_TargetUV;
		static const UECodeGen_Private::FStructPropertyParams NewProp_WorldPosition;
		static const UECodeGen_Private::FStructPropertyParams NewProp_WorldDirection;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_SceneCaptureComponent2D_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_SceneCaptureComponent2D = { "SceneCaptureComponent2D", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventDeprojectSceneCaptureComponent2DToWorld_Parms, SceneCaptureComponent2D), Z_Construct_UClass_USceneCaptureComponent2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_SceneCaptureComponent2D_MetaData), Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_SceneCaptureComponent2D_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_TargetUV_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_TargetUV = { "TargetUV", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventDeprojectSceneCaptureComponent2DToWorld_Parms, TargetUV), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_TargetUV_MetaData), Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_TargetUV_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_WorldPosition = { "WorldPosition", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventDeprojectSceneCaptureComponent2DToWorld_Parms, WorldPosition), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_WorldDirection = { "WorldDirection", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventDeprojectSceneCaptureComponent2DToWorld_Parms, WorldDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Statics_eventDeprojectSceneCaptureComponent2DToWorld_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventDeprojectSceneCaptureComponent2DToWorld_Parms), &Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_SceneCaptureComponent2D,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_TargetUV,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_WorldPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_WorldDirection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Deprojects the given UV coordinate to world space using the given SceneCaptureComponent2D\n\x09* \\param SceneCaptureComponent2D The target scene capture component 2d to use\n\x09* \\param TargetUV FVector2D of a screen space position (0 - 1 values)\n\x09* \\param WorldPosition out variable for the position in world space corresponding to the screen space position\n\x09* \\param WorldDirection out variable for the direction from the scene capture camera to the world space position\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Deprojects the given UV coordinate to world space using the given SceneCaptureComponent2D\n* \\param SceneCaptureComponent2D The target scene capture component 2d to use\n* \\param TargetUV FVector2D of a screen space position (0 - 1 values)\n* \\param WorldPosition out variable for the position in world space corresponding to the screen space position\n* \\param WorldDirection out variable for the direction from the scene capture camera to the world space position" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "DeprojectSceneCaptureComponent2DToWorld", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::Developer_Statics_eventDeprojectSceneCaptureComponent2DToWorld_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::Developer_Statics_eventDeprojectSceneCaptureComponent2DToWorld_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics
	{
		struct Developer_Statics_eventDoubleToString_Parms
		{
			double inValue;
			int32 numDecimalPlaces;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FDoublePropertyParams NewProp_inValue;
		static const UECodeGen_Private::FIntPropertyParams NewProp_numDecimalPlaces;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::NewProp_inValue = { "inValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventDoubleToString_Parms, inValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::NewProp_numDecimalPlaces = { "numDecimalPlaces", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventDoubleToString_Parms, numDecimalPlaces), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventDoubleToString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::NewProp_inValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::NewProp_numDecimalPlaces,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "CompactNodeTitle", "->" },
		{ "CPP_Default_numDecimalPlaces", "8" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "DoubleToString", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::Developer_Statics_eventDoubleToString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14042401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::Developer_Statics_eventDoubleToString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_DoubleToString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_DoubleToString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics
	{
		struct Developer_Statics_eventExecuteFile_Parms
		{
			FString cmdCommand;
			FString cmdParams;
			bool bWaitForFinish;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_cmdCommand_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_cmdCommand;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_cmdParams_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_cmdParams;
		static void NewProp_bWaitForFinish_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWaitForFinish;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_cmdCommand_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_cmdCommand = { "cmdCommand", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventExecuteFile_Parms, cmdCommand), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_cmdCommand_MetaData), Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_cmdCommand_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_cmdParams_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_cmdParams = { "cmdParams", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventExecuteFile_Parms, cmdParams), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_cmdParams_MetaData), Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_cmdParams_MetaData) };
	void Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_bWaitForFinish_SetBit(void* Obj)
	{
		((Developer_Statics_eventExecuteFile_Parms*)Obj)->bWaitForFinish = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_bWaitForFinish = { "bWaitForFinish", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventExecuteFile_Parms), &Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_bWaitForFinish_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Statics_eventExecuteFile_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventExecuteFile_Parms), &Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_cmdCommand,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_cmdParams,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_bWaitForFinish,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Attempts to execute the command at the specified file location.\n\x09 * Returns whether the command was successfully executed\n\x09 */" },
#endif
		{ "CPP_Default_bWaitForFinish", "true" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Attempts to execute the command at the specified file location.\n* Returns whether the command was successfully executed" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "ExecuteFile", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::Developer_Statics_eventExecuteFile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::Developer_Statics_eventExecuteFile_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics
	{
		struct Developer_Statics_eventExploreFolderOrFile_Parms
		{
			FString folderOrFilePath;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_folderOrFilePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_folderOrFilePath;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics::NewProp_folderOrFilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics::NewProp_folderOrFilePath = { "folderOrFilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventExploreFolderOrFile_Parms, folderOrFilePath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics::NewProp_folderOrFilePath_MetaData), Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics::NewProp_folderOrFilePath_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics::NewProp_folderOrFilePath,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Opens a path in the OS (Windows) File Explorer.  If a file is specified, the Explorer window will initially find/highlight the file.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Opens a path in the OS (Windows) File Explorer.  If a file is specified, the Explorer window will initially find/highlight the file." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "ExploreFolderOrFile", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics::Developer_Statics_eventExploreFolderOrFile_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics::Developer_Statics_eventExploreFolderOrFile_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_FixedCollapseRelativeDirectoriesInline_Statics
	{
		struct Developer_Statics_eventFixedCollapseRelativeDirectoriesInline_Parms
		{
			FString path;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_path;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_FixedCollapseRelativeDirectoriesInline_Statics::NewProp_path = { "path", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventFixedCollapseRelativeDirectoriesInline_Parms, path), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_FixedCollapseRelativeDirectoriesInline_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_FixedCollapseRelativeDirectoriesInline_Statics::NewProp_path,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_FixedCollapseRelativeDirectoriesInline_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|FileIO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Version of FPaths:CollapseRelativeDirectories() that correctly handles starting with \"../\" */" },
#endif
		{ "DisplayName", "VH Collapse Relative Directories" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Version of FPaths:CollapseRelativeDirectories() that correctly handles starting with \"../\"" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_FixedCollapseRelativeDirectoriesInline_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "FixedCollapseRelativeDirectoriesInline", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_FixedCollapseRelativeDirectoriesInline_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_FixedCollapseRelativeDirectoriesInline_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_FixedCollapseRelativeDirectoriesInline_Statics::Developer_Statics_eventFixedCollapseRelativeDirectoriesInline_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_FixedCollapseRelativeDirectoriesInline_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_FixedCollapseRelativeDirectoriesInline_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_FixedCollapseRelativeDirectoriesInline_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_FixedCollapseRelativeDirectoriesInline_Statics::Developer_Statics_eventFixedCollapseRelativeDirectoriesInline_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_FixedCollapseRelativeDirectoriesInline()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_FixedCollapseRelativeDirectoriesInline_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics
	{
		struct Developer_Statics_eventFormatFloat_Parms
		{
			float inFloat;
			int32 numDecimals;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_inFloat;
		static const UECodeGen_Private::FIntPropertyParams NewProp_numDecimals;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::NewProp_inFloat = { "inFloat", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventFormatFloat_Parms, inFloat), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::NewProp_numDecimals = { "numDecimals", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventFormatFloat_Parms, numDecimals), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventFormatFloat_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::NewProp_inFloat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::NewProp_numDecimals,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|Format" },
		{ "CPP_Default_numDecimals", "2" },
		{ "DisplayName", "VH Format Float" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "FormatFloat", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::Developer_Statics_eventFormatFloat_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::Developer_Statics_eventFormatFloat_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_FormatFloat()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_FormatFloat_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics
	{
		struct Developer_Statics_eventGetActorNetMode_Parms
		{
			AActor* actor;
			EVH_NetMode ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actor;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::NewProp_actor = { "actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetActorNetMode_Parms, actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetActorNetMode_Parms, ReturnValue), Z_Construct_UEnum_VH_Developer_EVH_NetMode, METADATA_PARAMS(0, nullptr) }; // 1476578788
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::NewProp_actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetActorNetMode", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::Developer_Statics_eventGetActorNetMode_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::Developer_Statics_eventGetActorNetMode_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics
	{
		struct Developer_Statics_eventGetClassObjectFromFullName_Parms
		{
			FString fullName;
			UClass* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fullName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_fullName;
		static const UECodeGen_Private::FClassPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::NewProp_fullName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::NewProp_fullName = { "fullName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetClassObjectFromFullName_Parms, fullName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::NewProp_fullName_MetaData), Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::NewProp_fullName_MetaData) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetClassObjectFromFullName_Parms, ReturnValue), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::NewProp_fullName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Get class pointer from the full name of that class\n" },
#endif
		{ "DisplayName", "VH Get Class Object From Full Name" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get class pointer from the full name of that class" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetClassObjectFromFullName", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::Developer_Statics_eventGetClassObjectFromFullName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::Developer_Statics_eventGetClassObjectFromFullName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics
	{
		struct Developer_Statics_eventGetClassObjectFromPath_Parms
		{
			FString path;
			UClass* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_path_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_path;
		static const UECodeGen_Private::FClassPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::NewProp_path_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::NewProp_path = { "path", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetClassObjectFromPath_Parms, path), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::NewProp_path_MetaData), Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::NewProp_path_MetaData) };
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetClassObjectFromPath_Parms, ReturnValue), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::NewProp_path,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Get Class pointer from the path of that class\n" },
#endif
		{ "DisplayName", "VH Get Class Object From Path" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get Class pointer from the path of that class" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetClassObjectFromPath", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::Developer_Statics_eventGetClassObjectFromPath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::Developer_Statics_eventGetClassObjectFromPath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetCommonAppDataPath_Statics
	{
		struct Developer_Statics_eventGetCommonAppDataPath_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetCommonAppDataPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetCommonAppDataPath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetCommonAppDataPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetCommonAppDataPath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetCommonAppDataPath_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|FileIO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * @brief\x09This static function is used to get the shared \"AppData\" folder on a Windows environment. This function will return the \n\x09 *\x09\x09\x09""C:\\ProgramData\\ folder for all users.\n\x09 *\n\x09 * @return\x09static FString - The return will be the full path of the %PROGRAMDATA% folder in the Windows environment.\n\x09 * @warning This function will only work in an Windows environment.\n\x09 */" },
#endif
		{ "DisplayName", "VH Get Common AppData Path" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* @brief       This static function is used to get the shared \"AppData\" folder on a Windows environment. This function will return the\n*                      C:\\ProgramData\\ folder for all users.\n*\n* @return      static FString - The return will be the full path of the %PROGRAMDATA% folder in the Windows environment.\n* @warning This function will only work in an Windows environment." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetCommonAppDataPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetCommonAppDataPath", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetCommonAppDataPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetCommonAppDataPath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetCommonAppDataPath_Statics::Developer_Statics_eventGetCommonAppDataPath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetCommonAppDataPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetCommonAppDataPath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetCommonAppDataPath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetCommonAppDataPath_Statics::Developer_Statics_eventGetCommonAppDataPath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetCommonAppDataPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetCommonAppDataPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics
	{
		struct Developer_Statics_eventGetDPIScaleFactorAtPoint_Parms
		{
			float mouseX;
			float mouseY;
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_mouseX;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_mouseY;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::NewProp_mouseX = { "mouseX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetDPIScaleFactorAtPoint_Parms, mouseX), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::NewProp_mouseY = { "mouseY", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetDPIScaleFactorAtPoint_Parms, mouseY), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetDPIScaleFactorAtPoint_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::NewProp_mouseX,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::NewProp_mouseY,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Returns DPI scale at given mouse location */" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns DPI scale at given mouse location" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetDPIScaleFactorAtPoint", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::Developer_Statics_eventGetDPIScaleFactorAtPoint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::Developer_Statics_eventGetDPIScaleFactorAtPoint_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetFromClipboard_Statics
	{
		struct Developer_Statics_eventGetFromClipboard_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetFromClipboard_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetFromClipboard_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetFromClipboard_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetFromClipboard_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetFromClipboard_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|Clipboard" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Gets a string containing the current contents of the clipboard\x09*/" },
#endif
		{ "DisplayName", "VH Get String from Clipboard" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets a string containing the current contents of the clipboard" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetFromClipboard_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetFromClipboard", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetFromClipboard_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetFromClipboard_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetFromClipboard_Statics::Developer_Statics_eventGetFromClipboard_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetFromClipboard_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetFromClipboard_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetFromClipboard_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetFromClipboard_Statics::Developer_Statics_eventGetFromClipboard_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetFromClipboard()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetFromClipboard_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives_Statics
	{
		struct Developer_Statics_eventGetLogicalDrives_Parms
		{
			TArray<FString> ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetLogicalDrives_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|FileIO" },
		{ "DisplayName", "VH Get Logical Drives" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetLogicalDrives", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives_Statics::Developer_Statics_eventGetLogicalDrives_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives_Statics::Developer_Statics_eventGetLogicalDrives_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics
	{
		struct Developer_Statics_eventGetLogicalDriveType_Parms
		{
			FString drive;
			EDriveType ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_drive_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_drive;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::NewProp_drive_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::NewProp_drive = { "drive", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetLogicalDriveType_Parms, drive), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::NewProp_drive_MetaData), Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::NewProp_drive_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetLogicalDriveType_Parms, ReturnValue), Z_Construct_UEnum_VH_Developer_EDriveType, METADATA_PARAMS(0, nullptr) }; // 1428584734
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::NewProp_drive,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|FileIO" },
		{ "DisplayName", "VH Get Logical Drive Type" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetLogicalDriveType", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::Developer_Statics_eventGetLogicalDriveType_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::Developer_Statics_eventGetLogicalDriveType_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo_Statics
	{
		struct Developer_Statics_eventGetNetInfo_Parms
		{
			FString ipAddress;
			FString netAdapter;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ipAddress;
		static const UECodeGen_Private::FStrPropertyParams NewProp_netAdapter;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo_Statics::NewProp_ipAddress = { "ipAddress", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetNetInfo_Parms, ipAddress), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo_Statics::NewProp_netAdapter = { "netAdapter", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetNetInfo_Parms, netAdapter), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo_Statics::NewProp_ipAddress,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo_Statics::NewProp_netAdapter,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* Returns the IP address and network adapter of current connection\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Returns the IP address and network adapter of current connection" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetNetInfo", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo_Statics::Developer_Statics_eventGetNetInfo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo_Statics::Developer_Statics_eventGetNetInfo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetPlayerViewpoint_Statics
	{
		struct Developer_Statics_eventGetPlayerViewpoint_Parms
		{
			FTransform localToWorld;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_localToWorld;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetPlayerViewpoint_Statics::NewProp_localToWorld = { "localToWorld", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetPlayerViewpoint_Parms, localToWorld), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetPlayerViewpoint_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetPlayerViewpoint_Statics::NewProp_localToWorld,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetPlayerViewpoint_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetPlayerViewpoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetPlayerViewpoint", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetPlayerViewpoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetPlayerViewpoint_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetPlayerViewpoint_Statics::Developer_Statics_eventGetPlayerViewpoint_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetPlayerViewpoint_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetPlayerViewpoint_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetPlayerViewpoint_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetPlayerViewpoint_Statics::Developer_Statics_eventGetPlayerViewpoint_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetPlayerViewpoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetPlayerViewpoint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace_Statics
	{
		struct Developer_Statics_eventGetStackTrace_Parms
		{
			int32 maxLines;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_maxLines;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace_Statics::NewProp_maxLines = { "maxLines", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetStackTrace_Parms, maxLines), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetStackTrace_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace_Statics::NewProp_maxLines,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Get the current stack trace (usually from an error).  Specify 'maxLines' value <= 0 to get ALL lines. */" },
#endif
		{ "CPP_Default_maxLines", "8" },
		{ "DisplayName", "VH Get StackTrace" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Get the current stack trace (usually from an error).  Specify 'maxLines' value <= 0 to get ALL lines." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetStackTrace", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace_Statics::Developer_Statics_eventGetStackTrace_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace_Statics::Developer_Statics_eventGetStackTrace_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetUserAppDataPath_Statics
	{
		struct Developer_Statics_eventGetUserAppDataPath_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetUserAppDataPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetUserAppDataPath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetUserAppDataPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetUserAppDataPath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetUserAppDataPath_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|FileIO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * @brief\x09This static function is used to get the user local \"AppData\" folder on a Windows environment. This function will return the\n\x09 *\x09\x09\x09\"C:/Users/[current user]/AppData/Local/\" folder for the current user.\n\x09 *\n\x09 * @return\x09static FString - The return will be the full path of the %APPDATA% folder for the current user in the Windows environment.\n\x09 * @warning This function will only work in an Windows environment.\n\x09 */" },
#endif
		{ "DisplayName", "VH Get User AppData Path" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* @brief       This static function is used to get the user local \"AppData\" folder on a Windows environment. This function will return the\n*                      \"C:/Users/[current user]/AppData/Local/\" folder for the current user.\n*\n* @return      static FString - The return will be the full path of the %APPDATA% folder for the current user in the Windows environment.\n* @warning This function will only work in an Windows environment." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetUserAppDataPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetUserAppDataPath", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetUserAppDataPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetUserAppDataPath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetUserAppDataPath_Statics::Developer_Statics_eventGetUserAppDataPath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetUserAppDataPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetUserAppDataPath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetUserAppDataPath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetUserAppDataPath_Statics::Developer_Statics_eventGetUserAppDataPath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetUserAppDataPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetUserAppDataPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetUserPicturesPath_Statics
	{
		struct Developer_Statics_eventGetUserPicturesPath_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetUserPicturesPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetUserPicturesPath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetUserPicturesPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetUserPicturesPath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetUserPicturesPath_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|FileIO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * @brief\x09This static function is used to get the user \"Pictures\" folder on a Windows environment. This function will return the\n\x09 *\x09\x09\x09\"C:/Users/[current user]/Pictures/\" folder for the current user.\n\x09 *\n\x09 * @return\x09static FString - The return will be the full path of the %USERPROFILE%/Pictures/ folder for the current user in the Windows environment.\n\x09 * @warning This function will only work in an Windows environment.\n\x09 */" },
#endif
		{ "DisplayName", "VH Get User Pictures Path" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* @brief       This static function is used to get the user \"Pictures\" folder on a Windows environment. This function will return the\n*                      \"C:/Users/[current user]/Pictures/\" folder for the current user.\n*\n* @return      static FString - The return will be the full path of the %USERPROFILE%/Pictures/ folder for the current user in the Windows environment.\n* @warning This function will only work in an Windows environment." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetUserPicturesPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetUserPicturesPath", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetUserPicturesPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetUserPicturesPath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetUserPicturesPath_Statics::Developer_Statics_eventGetUserPicturesPath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetUserPicturesPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetUserPicturesPath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetUserPicturesPath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetUserPicturesPath_Statics::Developer_Statics_eventGetUserPicturesPath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetUserPicturesPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetUserPicturesPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetUserProfilePath_Statics
	{
		struct Developer_Statics_eventGetUserProfilePath_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetUserProfilePath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetUserProfilePath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetUserProfilePath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetUserProfilePath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetUserProfilePath_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|FileIO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * @brief\x09This static function is used to get the user profile folder on a Windows environment. This function will return the\n\x09 *\x09\x09\x09\"C:/Users/[current user]/\" folder for the current user.  \n\x09 *\n\x09 * @return\x09static FString - The return will be the full path of the %USERPROFILE% folder for the current user in the Windows environment.\n\x09 * @warning This function will only work in an Windows environment.\n\x09 */" },
#endif
		{ "DisplayName", "VH Get User Profile Path" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* @brief       This static function is used to get the user profile folder on a Windows environment. This function will return the\n*                      \"C:/Users/[current user]/\" folder for the current user.\n*\n* @return      static FString - The return will be the full path of the %USERPROFILE% folder for the current user in the Windows environment.\n* @warning This function will only work in an Windows environment." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetUserProfilePath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetUserProfilePath", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetUserProfilePath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetUserProfilePath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetUserProfilePath_Statics::Developer_Statics_eventGetUserProfilePath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetUserProfilePath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetUserProfilePath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetUserProfilePath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetUserProfilePath_Statics::Developer_Statics_eventGetUserProfilePath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetUserProfilePath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetUserProfilePath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetUserVideosPath_Statics
	{
		struct Developer_Statics_eventGetUserVideosPath_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetUserVideosPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetUserVideosPath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetUserVideosPath_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetUserVideosPath_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetUserVideosPath_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|FileIO" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * @brief\x09This static function is used to get the user \"Videos\" folder on a Windows environment. This function will return the\n\x09 *\x09\x09\x09\"C:/Users/[current user]/Videos/\" folder for the current user.\n\x09 *\n\x09 * @return\x09static FString - The return will be the full path of the %USERPROFILE%/Videos/ folder for the current user in the Windows environment.\n\x09 * @warning This function will only work in an Windows environment.\n\x09 */" },
#endif
		{ "DisplayName", "VH Get User Videos Path" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* @brief       This static function is used to get the user \"Videos\" folder on a Windows environment. This function will return the\n*                      \"C:/Users/[current user]/Videos/\" folder for the current user.\n*\n* @return      static FString - The return will be the full path of the %USERPROFILE%/Videos/ folder for the current user in the Windows environment.\n* @warning This function will only work in an Windows environment." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetUserVideosPath_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetUserVideosPath", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetUserVideosPath_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetUserVideosPath_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetUserVideosPath_Statics::Developer_Statics_eventGetUserVideosPath_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetUserVideosPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetUserVideosPath_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetUserVideosPath_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetUserVideosPath_Statics::Developer_Statics_eventGetUserVideosPath_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetUserVideosPath()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetUserVideosPath_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping_Statics
	{
		struct Developer_Statics_eventGetVHIsBuildShipping_Parms
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
	void Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Statics_eventGetVHIsBuildShipping_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventGetVHIsBuildShipping_Parms), &Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGame" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetVHIsBuildShipping", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping_Statics::Developer_Statics_eventGetVHIsBuildShipping_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping_Statics::Developer_Statics_eventGetVHIsBuildShipping_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest_Statics
	{
		struct Developer_Statics_eventGetVHIsBuildTest_Parms
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
	void Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Statics_eventGetVHIsBuildTest_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventGetVHIsBuildTest_Parms), &Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGame" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetVHIsBuildTest", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest_Statics::Developer_Statics_eventGetVHIsBuildTest_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest_Statics::Developer_Statics_eventGetVHIsBuildTest_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor_Statics
	{
		struct Developer_Statics_eventGetVHIsWithEditor_Parms
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
	void Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Statics_eventGetVHIsWithEditor_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventGetVHIsWithEditor_Parms), &Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhGame" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetVHIsWithEditor", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor_Statics::Developer_Statics_eventGetVHIsWithEditor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor_Statics::Developer_Statics_eventGetVHIsWithEditor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_GetVHWorld_Statics
	{
		struct Developer_Statics_eventGetVHWorld_Parms
		{
			UWorld* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Statics_GetVHWorld_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventGetVHWorld_Parms, ReturnValue), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_GetVHWorld_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_GetVHWorld_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_GetVHWorld_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper" },
		{ "DisplayName", "VH Get World" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_GetVHWorld_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "GetVHWorld", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_GetVHWorld_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetVHWorld_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetVHWorld_Statics::Developer_Statics_eventGetVHWorld_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetVHWorld_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_GetVHWorld_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_GetVHWorld_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_GetVHWorld_Statics::Developer_Statics_eventGetVHWorld_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_GetVHWorld()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_GetVHWorld_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics
	{
		struct Developer_Statics_eventIsClient_Parms
		{
			const UObject* worldContextObject;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_worldContextObject_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_worldContextObject;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::NewProp_worldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::NewProp_worldContextObject = { "worldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventIsClient_Parms, worldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::NewProp_worldContextObject_MetaData), Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::NewProp_worldContextObject_MetaData) };
	void Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Statics_eventIsClient_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventIsClient_Parms), &Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::NewProp_worldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "IsClient", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::Developer_Statics_eventIsClient_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::Developer_Statics_eventIsClient_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_IsClient()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_IsClient_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics
	{
		struct Developer_Statics_eventIsListenServer_Parms
		{
			UObject* WorldContextObject;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventIsListenServer_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Statics_eventIsListenServer_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventIsListenServer_Parms), &Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::Function_MetaDataParams[] = {
		{ "Category", "Networking" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Returns whether this game instance is a Listen Server. */" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Returns whether this game instance is a Listen Server." },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "IsListenServer", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::Developer_Statics_eventIsListenServer_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::Developer_Statics_eventIsListenServer_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_IsListenServer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_IsListenServer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor_Statics
	{
		struct Developer_Statics_eventIsPlayInEditor_Parms
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
	void Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Statics_eventIsPlayInEditor_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventIsPlayInEditor_Parms), &Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|Modes" },
		{ "DisplayName", "VH Is Play In Editor" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "IsPlayInEditor", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor_Statics::Developer_Statics_eventIsPlayInEditor_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor_Statics::Developer_Statics_eventIsPlayInEditor_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview_Statics
	{
		struct Developer_Statics_eventIsPlayInMobilePreview_Parms
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
	void Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Statics_eventIsPlayInMobilePreview_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventIsPlayInMobilePreview_Parms), &Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|Modes" },
		{ "DisplayName", "VH Is Play In Mobile Preview" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "IsPlayInMobilePreview", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview_Statics::Developer_Statics_eventIsPlayInMobilePreview_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview_Statics::Developer_Statics_eventIsPlayInMobilePreview_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview_Statics
	{
		struct Developer_Statics_eventIsPlayInPreview_Parms
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
	void Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Statics_eventIsPlayInPreview_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventIsPlayInPreview_Parms), &Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|Modes" },
		{ "DisplayName", "VH Is Play In Preview" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "IsPlayInPreview", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview_Statics::Developer_Statics_eventIsPlayInPreview_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview_Statics::Developer_Statics_eventIsPlayInPreview_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview_Statics
	{
		struct Developer_Statics_eventIsPlayInVulkanPreview_Parms
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
	void Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Statics_eventIsPlayInVulkanPreview_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventIsPlayInVulkanPreview_Parms), &Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|Modes" },
		{ "DisplayName", "VH Is Play In Vulkan Preview" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "IsPlayInVulkanPreview", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview_Statics::Developer_Statics_eventIsPlayInVulkanPreview_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview_Statics::Developer_Statics_eventIsPlayInVulkanPreview_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics
	{
		struct Developer_Statics_eventK2_HasLocalNetOwner_Parms
		{
			AActor* actor;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_actor;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::NewProp_actor = { "actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventK2_HasLocalNetOwner_Parms, actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Statics_eventK2_HasLocalNetOwner_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventK2_HasLocalNetOwner_Parms), &Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::NewProp_actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::Function_MetaDataParams[] = {
		{ "CallableWithoutWorldContext", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Return true if the topmost owner of this actor is locally controlled */" },
#endif
		{ "DisplayName", "HasLocalNetOwner" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Return true if the topmost owner of this actor is locally controlled" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "K2_HasLocalNetOwner", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::Developer_Statics_eventK2_HasLocalNetOwner_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::Developer_Statics_eventK2_HasLocalNetOwner_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics
	{
		struct Developer_Statics_eventOpenFileWithDefaultApp_Parms
		{
			FString pathToFile;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_pathToFile_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_pathToFile;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::NewProp_pathToFile_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::NewProp_pathToFile = { "pathToFile", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventOpenFileWithDefaultApp_Parms, pathToFile), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::NewProp_pathToFile_MetaData), Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::NewProp_pathToFile_MetaData) };
	void Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Statics_eventOpenFileWithDefaultApp_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventOpenFileWithDefaultApp_Parms), &Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::NewProp_pathToFile,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Attempts to open the file at the specified path using window's default application for that file type\n\x09 * Returns whether the file was successfully opened\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Attempts to open the file at the specified path using window's default application for that file type\n* Returns whether the file was successfully opened" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "OpenFileWithDefaultApp", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::Developer_Statics_eventOpenFileWithDefaultApp_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::Developer_Statics_eventOpenFileWithDefaultApp_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics
	{
		struct Developer_Statics_eventOpenFolderWithDefaultApp_Parms
		{
			FString fullPathToFolder;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_fullPathToFolder_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_fullPathToFolder;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::NewProp_fullPathToFolder_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::NewProp_fullPathToFolder = { "fullPathToFolder", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventOpenFolderWithDefaultApp_Parms, fullPathToFolder), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::NewProp_fullPathToFolder_MetaData), Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::NewProp_fullPathToFolder_MetaData) };
	void Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Statics_eventOpenFolderWithDefaultApp_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventOpenFolderWithDefaultApp_Parms), &Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::NewProp_fullPathToFolder,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "OpenFolderWithDefaultApp", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::Developer_Statics_eventOpenFolderWithDefaultApp_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::Developer_Statics_eventOpenFolderWithDefaultApp_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics
	{
		struct Developer_Statics_eventParseCommandLineParams_Parms
		{
			FString commandLine;
			TArray<FString> tokens;
			TArray<FString> switches;
			TArray<FString> args;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_commandLine;
		static const UECodeGen_Private::FStrPropertyParams NewProp_tokens_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_tokens;
		static const UECodeGen_Private::FStrPropertyParams NewProp_switches_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_switches;
		static const UECodeGen_Private::FStrPropertyParams NewProp_args_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_args;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::NewProp_commandLine = { "commandLine", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventParseCommandLineParams_Parms, commandLine), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::NewProp_tokens_Inner = { "tokens", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::NewProp_tokens = { "tokens", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventParseCommandLineParams_Parms, tokens), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::NewProp_switches_Inner = { "switches", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::NewProp_switches = { "switches", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventParseCommandLineParams_Parms, switches), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::NewProp_args_Inner = { "args", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::NewProp_args = { "args", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventParseCommandLineParams_Parms, args), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::NewProp_commandLine,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::NewProp_tokens_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::NewProp_tokens,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::NewProp_switches_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::NewProp_switches,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::NewProp_args_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::NewProp_args,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Parses 'commandLine' into arrays of tokens, switches, and args.\n\x09 * NOTE: If 'commandLine' is empty when called, it will be filled with the cached commandLine string.\n\x09 */" },
#endif
		{ "DisplayName", "VH Parse Command Line Params" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Parses 'commandLine' into arrays of tokens, switches, and args.\n* NOTE: If 'commandLine' is empty when called, it will be filled with the cached commandLine string." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "ParseCommandLineParams", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::Developer_Statics_eventParseCommandLineParams_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::Developer_Statics_eventParseCommandLineParams_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics
	{
		struct Developer_Statics_eventPressAndReleaseKey_Parms
		{
			FKey key;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_key_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_key;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics::NewProp_key_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics::NewProp_key = { "key", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventPressAndReleaseKey_Parms, key), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics::NewProp_key_MetaData), Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics::NewProp_key_MetaData) }; // 46000949
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics::NewProp_key,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Sends key down, then key up to current keyboard focus\n\x09* \\param key Key to press and release\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Sends key down, then key up to current keyboard focus\n* \\param key Key to press and release" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "PressAndReleaseKey", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics::Developer_Statics_eventPressAndReleaseKey_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics::Developer_Statics_eventPressAndReleaseKey_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics
	{
		struct Developer_Statics_eventPressKey_Parms
		{
			FKey key;
			bool bRepeat;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_key_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_key;
		static void NewProp_bRepeat_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bRepeat;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::NewProp_key_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::NewProp_key = { "key", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventPressKey_Parms, key), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::NewProp_key_MetaData), Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::NewProp_key_MetaData) }; // 46000949
	void Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::NewProp_bRepeat_SetBit(void* Obj)
	{
		((Developer_Statics_eventPressKey_Parms*)Obj)->bRepeat = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::NewProp_bRepeat = { "bRepeat", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventPressKey_Parms), &Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::NewProp_bRepeat_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::NewProp_key,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::NewProp_bRepeat,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Sends key down to current keyboard focus\n\x09* \\param key Key to press\n\x09* \\param bRepeat If true, press is sent as a repeating press\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Sends key down to current keyboard focus\n* \\param key Key to press\n* \\param bRepeat If true, press is sent as a repeating press" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "PressKey", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::Developer_Statics_eventPressKey_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::Developer_Statics_eventPressKey_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_PressKey()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_PressKey_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics
	{
		struct Developer_Statics_eventPrintMessage_Parms
		{
			FString message;
			bool bPrintToScreen;
			bool bPrintToConsole;
			bool bPrintToLog;
			ELogMessageVerbosityLevel verbosityLevel;
			bool bShowStackTrace;
			ELogMessageColor logColor;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_message_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_message;
		static void NewProp_bPrintToScreen_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPrintToScreen;
		static void NewProp_bPrintToConsole_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPrintToConsole;
		static void NewProp_bPrintToLog_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPrintToLog;
		static const UECodeGen_Private::FBytePropertyParams NewProp_verbosityLevel_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_verbosityLevel;
		static void NewProp_bShowStackTrace_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowStackTrace;
		static const UECodeGen_Private::FBytePropertyParams NewProp_logColor_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_logColor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_message = { "message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventPrintMessage_Parms, message), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_message_MetaData), Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_message_MetaData) };
	void Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_bPrintToScreen_SetBit(void* Obj)
	{
		((Developer_Statics_eventPrintMessage_Parms*)Obj)->bPrintToScreen = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_bPrintToScreen = { "bPrintToScreen", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventPrintMessage_Parms), &Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_bPrintToScreen_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_bPrintToConsole_SetBit(void* Obj)
	{
		((Developer_Statics_eventPrintMessage_Parms*)Obj)->bPrintToConsole = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_bPrintToConsole = { "bPrintToConsole", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventPrintMessage_Parms), &Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_bPrintToConsole_SetBit, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_bPrintToLog_SetBit(void* Obj)
	{
		((Developer_Statics_eventPrintMessage_Parms*)Obj)->bPrintToLog = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_bPrintToLog = { "bPrintToLog", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventPrintMessage_Parms), &Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_bPrintToLog_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_verbosityLevel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_verbosityLevel = { "verbosityLevel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventPrintMessage_Parms, verbosityLevel), Z_Construct_UEnum_VH_Developer_ELogMessageVerbosityLevel, METADATA_PARAMS(0, nullptr) }; // 2405737658
	void Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_bShowStackTrace_SetBit(void* Obj)
	{
		((Developer_Statics_eventPrintMessage_Parms*)Obj)->bShowStackTrace = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_bShowStackTrace = { "bShowStackTrace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventPrintMessage_Parms), &Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_bShowStackTrace_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_logColor_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_logColor = { "logColor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventPrintMessage_Parms, logColor), Z_Construct_UEnum_VH_Developer_ELogMessageColor, METADATA_PARAMS(0, nullptr) }; // 627902310
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_message,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_bPrintToScreen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_bPrintToConsole,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_bPrintToLog,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_verbosityLevel_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_verbosityLevel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_bShowStackTrace,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_logColor_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::NewProp_logColor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|Debug" },
		{ "CPP_Default_bPrintToConsole", "false" },
		{ "CPP_Default_bPrintToLog", "true" },
		{ "CPP_Default_bPrintToScreen", "false" },
		{ "CPP_Default_bShowStackTrace", "false" },
		{ "CPP_Default_logColor", "Gray" },
		{ "CPP_Default_verbosityLevel", "Log" },
		{ "DisplayName", "VH Print Message" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "PrintMessage", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::Developer_Statics_eventPrintMessage_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::Developer_Statics_eventPrintMessage_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_PrintMessage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_PrintMessage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics
	{
		struct Developer_Statics_eventReleaseKey_Parms
		{
			FKey key;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_key_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_key;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics::NewProp_key_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics::NewProp_key = { "key", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventReleaseKey_Parms, key), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics::NewProp_key_MetaData), Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics::NewProp_key_MetaData) }; // 46000949
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics::NewProp_key,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Sends key up to current keyboard focus\n\x09* * \\param key Key to release\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Sends key up to current keyboard focus\n* * \\param key Key to release" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "ReleaseKey", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics::Developer_Statics_eventReleaseKey_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics::Developer_Statics_eventReleaseKey_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics
	{
		struct Developer_Statics_eventSendKeyChar_Parms
		{
			FString keyString;
			bool bRepeat;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_keyString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_keyString;
		static void NewProp_bRepeat_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bRepeat;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::NewProp_keyString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::NewProp_keyString = { "keyString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventSendKeyChar_Parms, keyString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::NewProp_keyString_MetaData), Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::NewProp_keyString_MetaData) };
	void Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::NewProp_bRepeat_SetBit(void* Obj)
	{
		((Developer_Statics_eventSendKeyChar_Parms*)Obj)->bRepeat = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::NewProp_bRepeat = { "bRepeat", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventSendKeyChar_Parms), &Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::NewProp_bRepeat_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::NewProp_keyString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::NewProp_bRepeat,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "SendKeyChar", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::Developer_Statics_eventSendKeyChar_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::Developer_Statics_eventSendKeyChar_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics
	{
		struct Developer_Statics_eventSendToClipboard_Parms
		{
			FString inString;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_inString_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_inString;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics::NewProp_inString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics::NewProp_inString = { "inString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventSendToClipboard_Parms, inString), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics::NewProp_inString_MetaData), Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics::NewProp_inString_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics::NewProp_inString,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper|Clipboard" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Sets the clipboard contents to the specified string\x09 */" },
#endif
		{ "DisplayName", "VH Send String to Clipboard" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sets the clipboard contents to the specified string" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "SendToClipboard", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics::Developer_Statics_eventSendToClipboard_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics::Developer_Statics_eventSendToClipboard_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics
	{
		struct Developer_Statics_eventTimeSpanToString_Parms
		{
			FTimespan timespan;
			FString format;
			bool bIncludePlusMinus;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_timespan_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_timespan;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_format_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_format;
		static void NewProp_bIncludePlusMinus_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludePlusMinus;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::NewProp_timespan_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::NewProp_timespan = { "timespan", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventTimeSpanToString_Parms, timespan), Z_Construct_UScriptStruct_FTimespan, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::NewProp_timespan_MetaData), Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::NewProp_timespan_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::NewProp_format_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::NewProp_format = { "format", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventTimeSpanToString_Parms, format), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::NewProp_format_MetaData), Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::NewProp_format_MetaData) };
	void Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::NewProp_bIncludePlusMinus_SetBit(void* Obj)
	{
		((Developer_Statics_eventTimeSpanToString_Parms*)Obj)->bIncludePlusMinus = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::NewProp_bIncludePlusMinus = { "bIncludePlusMinus", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventTimeSpanToString_Parms), &Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::NewProp_bIncludePlusMinus_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Developer_Statics_eventTimeSpanToString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::NewProp_timespan,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::NewProp_format,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::NewProp_bIncludePlusMinus,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09 * Convert this time span to its string representation.\n\x09 *\n\x09 * The following formatting codes are available:\n\x09 *\x09\x09%d - prints the days component\n\x09 *\x09\x09%D - prints the zero-padded days component (00000000..10675199)\n\x09 *\x09\x09%h - prints the zero-padded hours component (00..23)\n\x09 *\x09\x09%m - prints the zero-padded minutes component (00..59)\n\x09 *\x09\x09%s - prints the zero-padded seconds component (00..59)\n\x09 *\x09\x09%f - prints the zero-padded fractional seconds (000..999)\n\x09 *\x09\x09%u - prints the zero-padded fractional seconds (000000..999999)\n\x09 *\x09\x09%n - prints the zero-padded fractional seconds (000000000..999999999)\n\x09 *\n\x09 * Depending on whether the time span is positive or negative, a plus or minus\n\x09 * sign character will always be added in front of the generated string.\n\x09 */" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* Convert this time span to its string representation.\n*\n* The following formatting codes are available:\n*              %d - prints the days component\n*              %D - prints the zero-padded days component (00000000..10675199)\n*              %h - prints the zero-padded hours component (00..23)\n*              %m - prints the zero-padded minutes component (00..59)\n*              %s - prints the zero-padded seconds component (00..59)\n*              %f - prints the zero-padded fractional seconds (000..999)\n*              %u - prints the zero-padded fractional seconds (000000..999999)\n*              %n - prints the zero-padded fractional seconds (000000000..999999999)\n*\n* Depending on whether the time span is positive or negative, a plus or minus\n* sign character will always be added in front of the generated string." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "TimeSpanToString", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::Developer_Statics_eventTimeSpanToString_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C42401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::Developer_Statics_eventTimeSpanToString_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome_Statics
	{
		struct Developer_Statics_eventVerifyMultihome_Parms
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
	void Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Developer_Statics_eventVerifyMultihome_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Developer_Statics_eventVerifyMultihome_Parms), &Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome_Statics::Function_MetaDataParams[] = {
		{ "Category", "VhDeveloper" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* if -multihome is specified, checks that IP maps to network adapter; returns true if -multihome is not specified */" },
#endif
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "if -multihome is specified, checks that IP maps to network adapter; returns true if -multihome is not specified" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UDeveloper_Statics, nullptr, "VerifyMultihome", nullptr, nullptr, Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome_Statics::PropPointers), sizeof(Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome_Statics::Developer_Statics_eventVerifyMultihome_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome_Statics::Developer_Statics_eventVerifyMultihome_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UDeveloper_Statics);
	UClass* Z_Construct_UClass_UDeveloper_Statics_NoRegister()
	{
		return UDeveloper_Statics::StaticClass();
	}
	struct Z_Construct_UClass_UDeveloper_Statics_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UDeveloper_Statics_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Developer,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Statics_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UDeveloper_Statics_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UDeveloper_Statics_CompareStringBP, "CompareStringBP" }, // 34028965
		{ &Z_Construct_UFunction_UDeveloper_Statics_ConvertToPlatformPath, "ConvertToPlatformPath" }, // 168734040
		{ &Z_Construct_UFunction_UDeveloper_Statics_CreateTextureFromPixels, "CreateTextureFromPixels" }, // 3352129592
		{ &Z_Construct_UFunction_UDeveloper_Statics_DateTimeFromISO8601, "DateTimeFromISO8601" }, // 3655261703
		{ &Z_Construct_UFunction_UDeveloper_Statics_DateTimeToFormattedString, "DateTimeToFormattedString" }, // 1323061374
		{ &Z_Construct_UFunction_UDeveloper_Statics_DateTimeToString, "DateTimeToString" }, // 1158370706
		{ &Z_Construct_UFunction_UDeveloper_Statics_DeprojectSceneCaptureComponent2DToWorld, "DeprojectSceneCaptureComponent2DToWorld" }, // 1019062285
		{ &Z_Construct_UFunction_UDeveloper_Statics_DoubleToString, "DoubleToString" }, // 2211772473
		{ &Z_Construct_UFunction_UDeveloper_Statics_ExecuteFile, "ExecuteFile" }, // 4179481531
		{ &Z_Construct_UFunction_UDeveloper_Statics_ExploreFolderOrFile, "ExploreFolderOrFile" }, // 29005842
		{ &Z_Construct_UFunction_UDeveloper_Statics_FixedCollapseRelativeDirectoriesInline, "FixedCollapseRelativeDirectoriesInline" }, // 199202937
		{ &Z_Construct_UFunction_UDeveloper_Statics_FormatFloat, "FormatFloat" }, // 1065111790
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetActorNetMode, "GetActorNetMode" }, // 3865056738
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromFullName, "GetClassObjectFromFullName" }, // 3723186362
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetClassObjectFromPath, "GetClassObjectFromPath" }, // 1857496147
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetCommonAppDataPath, "GetCommonAppDataPath" }, // 3179720370
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetDPIScaleFactorAtPoint, "GetDPIScaleFactorAtPoint" }, // 2226376431
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetFromClipboard, "GetFromClipboard" }, // 1003320784
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDrives, "GetLogicalDrives" }, // 2293611474
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetLogicalDriveType, "GetLogicalDriveType" }, // 1731636937
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetNetInfo, "GetNetInfo" }, // 1070410123
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetPlayerViewpoint, "GetPlayerViewpoint" }, // 3375926297
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetStackTrace, "GetStackTrace" }, // 4036708306
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetUserAppDataPath, "GetUserAppDataPath" }, // 3450722056
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetUserPicturesPath, "GetUserPicturesPath" }, // 3720691733
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetUserProfilePath, "GetUserProfilePath" }, // 3632060576
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetUserVideosPath, "GetUserVideosPath" }, // 414953243
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildShipping, "GetVHIsBuildShipping" }, // 450980350
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetVHIsBuildTest, "GetVHIsBuildTest" }, // 2399246406
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetVHIsWithEditor, "GetVHIsWithEditor" }, // 3828923839
		{ &Z_Construct_UFunction_UDeveloper_Statics_GetVHWorld, "GetVHWorld" }, // 2751326312
		{ &Z_Construct_UFunction_UDeveloper_Statics_IsClient, "IsClient" }, // 300073583
		{ &Z_Construct_UFunction_UDeveloper_Statics_IsListenServer, "IsListenServer" }, // 2106405563
		{ &Z_Construct_UFunction_UDeveloper_Statics_IsPlayInEditor, "IsPlayInEditor" }, // 4231101640
		{ &Z_Construct_UFunction_UDeveloper_Statics_IsPlayInMobilePreview, "IsPlayInMobilePreview" }, // 1633194001
		{ &Z_Construct_UFunction_UDeveloper_Statics_IsPlayInPreview, "IsPlayInPreview" }, // 3117074296
		{ &Z_Construct_UFunction_UDeveloper_Statics_IsPlayInVulkanPreview, "IsPlayInVulkanPreview" }, // 1784887738
		{ &Z_Construct_UFunction_UDeveloper_Statics_K2_HasLocalNetOwner, "K2_HasLocalNetOwner" }, // 1987902974
		{ &Z_Construct_UFunction_UDeveloper_Statics_OpenFileWithDefaultApp, "OpenFileWithDefaultApp" }, // 1238891859
		{ &Z_Construct_UFunction_UDeveloper_Statics_OpenFolderWithDefaultApp, "OpenFolderWithDefaultApp" }, // 531182805
		{ &Z_Construct_UFunction_UDeveloper_Statics_ParseCommandLineParams, "ParseCommandLineParams" }, // 1733457937
		{ &Z_Construct_UFunction_UDeveloper_Statics_PressAndReleaseKey, "PressAndReleaseKey" }, // 1341985195
		{ &Z_Construct_UFunction_UDeveloper_Statics_PressKey, "PressKey" }, // 2325673752
		{ &Z_Construct_UFunction_UDeveloper_Statics_PrintMessage, "PrintMessage" }, // 336495940
		{ &Z_Construct_UFunction_UDeveloper_Statics_ReleaseKey, "ReleaseKey" }, // 4096870031
		{ &Z_Construct_UFunction_UDeveloper_Statics_SendKeyChar, "SendKeyChar" }, // 3553655896
		{ &Z_Construct_UFunction_UDeveloper_Statics_SendToClipboard, "SendToClipboard" }, // 2000938381
		{ &Z_Construct_UFunction_UDeveloper_Statics_TimeSpanToString, "TimeSpanToString" }, // 3835028737
		{ &Z_Construct_UFunction_UDeveloper_Statics_VerifyMultihome, "VerifyMultihome" }, // 596746760
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Statics_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UDeveloper_Statics_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Core/Public/Developer_Statics.h" },
		{ "ModuleRelativePath", "Core/Public/Developer_Statics.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UDeveloper_Statics_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDeveloper_Statics>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UDeveloper_Statics_Statics::ClassParams = {
		&UDeveloper_Statics::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDeveloper_Statics_Statics::Class_MetaDataParams), Z_Construct_UClass_UDeveloper_Statics_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UDeveloper_Statics()
	{
		if (!Z_Registration_Info_UClass_UDeveloper_Statics.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDeveloper_Statics.OuterSingleton, Z_Construct_UClass_UDeveloper_Statics_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UDeveloper_Statics.OuterSingleton;
	}
	template<> VH_DEVELOPER_API UClass* StaticClass<UDeveloper_Statics>()
	{
		return UDeveloper_Statics::StaticClass();
	}
	UDeveloper_Statics::UDeveloper_Statics(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UDeveloper_Statics);
	UDeveloper_Statics::~UDeveloper_Statics() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_Statics::EnumInfo[] = {
		{ ELogMessageVerbosityLevel_StaticEnum, TEXT("ELogMessageVerbosityLevel"), &Z_Registration_Info_UEnum_ELogMessageVerbosityLevel, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2405737658U) },
		{ ELogMessageColor_StaticEnum, TEXT("ELogMessageColor"), &Z_Registration_Info_UEnum_ELogMessageColor, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 627902310U) },
		{ EDriveType_StaticEnum, TEXT("EDriveType"), &Z_Registration_Info_UEnum_EDriveType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1428584734U) },
		{ EVH_NetMode_StaticEnum, TEXT("EVH_NetMode"), &Z_Registration_Info_UEnum_EVH_NetMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1476578788U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UDeveloper_Statics, UDeveloper_Statics::StaticClass, TEXT("UDeveloper_Statics"), &Z_Registration_Info_UClass_UDeveloper_Statics, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDeveloper_Statics), 1172537915U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_3025073862(TEXT("/Script/VH_Developer"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
