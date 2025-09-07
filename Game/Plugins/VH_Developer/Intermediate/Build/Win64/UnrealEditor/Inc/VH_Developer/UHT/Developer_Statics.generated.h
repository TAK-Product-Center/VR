// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/Developer_Statics.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UObject;
class USceneCaptureComponent2D;
class UTexture2D;
class UWorld;
enum class EDriveType : uint8;
enum class ELogMessageColor : uint8;
enum class ELogMessageVerbosityLevel : uint8;
enum class EVH_NetMode : uint8;
struct FDateTime;
struct FKey;
struct FTimespan;
#ifdef VH_DEVELOPER_Developer_Statics_generated_h
#error "Developer_Statics.generated.h already included, missing '#pragma once' in Developer_Statics.h"
#endif
#define VH_DEVELOPER_Developer_Statics_generated_h

#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_104_SPARSE_DATA
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_104_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_104_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_104_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDateTimeToFormattedString); \
	DECLARE_FUNCTION(execTimeSpanToString); \
	DECLARE_FUNCTION(execDoubleToString); \
	DECLARE_FUNCTION(execIsClient); \
	DECLARE_FUNCTION(execDeprojectSceneCaptureComponent2DToWorld); \
	DECLARE_FUNCTION(execSendKeyChar); \
	DECLARE_FUNCTION(execPressAndReleaseKey); \
	DECLARE_FUNCTION(execReleaseKey); \
	DECLARE_FUNCTION(execPressKey); \
	DECLARE_FUNCTION(execGetPlayerViewpoint); \
	DECLARE_FUNCTION(execCompareStringBP); \
	DECLARE_FUNCTION(execGetDPIScaleFactorAtPoint); \
	DECLARE_FUNCTION(execVerifyMultihome); \
	DECLARE_FUNCTION(execGetNetInfo); \
	DECLARE_FUNCTION(execExploreFolderOrFile); \
	DECLARE_FUNCTION(execExecuteFile); \
	DECLARE_FUNCTION(execOpenFileWithDefaultApp); \
	DECLARE_FUNCTION(execOpenFolderWithDefaultApp); \
	DECLARE_FUNCTION(execK2_HasLocalNetOwner); \
	DECLARE_FUNCTION(execGetActorNetMode); \
	DECLARE_FUNCTION(execGetFromClipboard); \
	DECLARE_FUNCTION(execSendToClipboard); \
	DECLARE_FUNCTION(execParseCommandLineParams); \
	DECLARE_FUNCTION(execGetClassObjectFromFullName); \
	DECLARE_FUNCTION(execGetClassObjectFromPath); \
	DECLARE_FUNCTION(execDateTimeToString); \
	DECLARE_FUNCTION(execDateTimeFromISO8601); \
	DECLARE_FUNCTION(execConvertToPlatformPath); \
	DECLARE_FUNCTION(execFormatFloat); \
	DECLARE_FUNCTION(execCreateTextureFromPixels); \
	DECLARE_FUNCTION(execGetStackTrace); \
	DECLARE_FUNCTION(execPrintMessage); \
	DECLARE_FUNCTION(execFixedCollapseRelativeDirectoriesInline); \
	DECLARE_FUNCTION(execGetLogicalDriveType); \
	DECLARE_FUNCTION(execGetLogicalDrives); \
	DECLARE_FUNCTION(execGetUserVideosPath); \
	DECLARE_FUNCTION(execGetUserPicturesPath); \
	DECLARE_FUNCTION(execGetUserProfilePath); \
	DECLARE_FUNCTION(execGetUserAppDataPath); \
	DECLARE_FUNCTION(execGetCommonAppDataPath); \
	DECLARE_FUNCTION(execIsPlayInVulkanPreview); \
	DECLARE_FUNCTION(execIsPlayInMobilePreview); \
	DECLARE_FUNCTION(execIsPlayInPreview); \
	DECLARE_FUNCTION(execIsPlayInEditor); \
	DECLARE_FUNCTION(execGetVHIsBuildTest); \
	DECLARE_FUNCTION(execGetVHIsBuildShipping); \
	DECLARE_FUNCTION(execGetVHIsWithEditor); \
	DECLARE_FUNCTION(execIsListenServer); \
	DECLARE_FUNCTION(execGetVHWorld);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_104_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_104_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDeveloper_Statics(); \
	friend struct Z_Construct_UClass_UDeveloper_Statics_Statics; \
public: \
	DECLARE_CLASS(UDeveloper_Statics, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Developer"), NO_API) \
	DECLARE_SERIALIZER(UDeveloper_Statics)


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_104_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDeveloper_Statics(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDeveloper_Statics(UDeveloper_Statics&&); \
	NO_API UDeveloper_Statics(const UDeveloper_Statics&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDeveloper_Statics); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDeveloper_Statics); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDeveloper_Statics) \
	NO_API virtual ~UDeveloper_Statics();


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_101_PROLOG
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_104_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_104_SPARSE_DATA \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_104_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_104_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_104_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_104_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_104_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h_104_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DEVELOPER_API UClass* StaticClass<class UDeveloper_Statics>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Developer_Source_VH_Developer_Core_Public_Developer_Statics_h


#define FOREACH_ENUM_ELOGMESSAGEVERBOSITYLEVEL(op) \
	op(ELogMessageVerbosityLevel::Log) \
	op(ELogMessageVerbosityLevel::Warning) \
	op(ELogMessageVerbosityLevel::Error) 

enum class ELogMessageVerbosityLevel : uint8;
template<> struct TIsUEnumClass<ELogMessageVerbosityLevel> { enum { Value = true }; };
template<> VH_DEVELOPER_API UEnum* StaticEnum<ELogMessageVerbosityLevel>();

#define FOREACH_ENUM_ELOGMESSAGECOLOR(op) \
	op(ELogMessageColor::None) \
	op(ELogMessageColor::DarkRed) \
	op(ELogMessageColor::DarkGreen) \
	op(ELogMessageColor::DarkBlue) \
	op(ELogMessageColor::DarkYellow) \
	op(ELogMessageColor::DarkCyan) \
	op(ELogMessageColor::DarkPurple) \
	op(ELogMessageColor::Red) \
	op(ELogMessageColor::Green) \
	op(ELogMessageColor::Blue) \
	op(ELogMessageColor::Yellow) \
	op(ELogMessageColor::Cyan) \
	op(ELogMessageColor::Purple) \
	op(ELogMessageColor::White) \
	op(ELogMessageColor::Black) \
	op(ELogMessageColor::Gray) 

enum class ELogMessageColor : uint8;
template<> struct TIsUEnumClass<ELogMessageColor> { enum { Value = true }; };
template<> VH_DEVELOPER_API UEnum* StaticEnum<ELogMessageColor>();

#define FOREACH_ENUM_EDRIVETYPE(op) \
	op(EDriveType::Unknown) \
	op(EDriveType::NoRootDir) \
	op(EDriveType::Removable) \
	op(EDriveType::Fixed) \
	op(EDriveType::Remote) \
	op(EDriveType::CDRom) \
	op(EDriveType::RamDisk) 

enum class EDriveType : uint8;
template<> struct TIsUEnumClass<EDriveType> { enum { Value = true }; };
template<> VH_DEVELOPER_API UEnum* StaticEnum<EDriveType>();

#define FOREACH_ENUM_EVH_NETMODE(op) \
	op(EVH_NetMode::NM_Standalone) \
	op(EVH_NetMode::NM_DedicatedServer) \
	op(EVH_NetMode::NM_ListenServer) \
	op(EVH_NetMode::NM_Client) 

enum class EVH_NetMode : uint8;
template<> struct TIsUEnumClass<EVH_NetMode> { enum { Value = true }; };
template<> VH_DEVELOPER_API UEnum* StaticEnum<EVH_NetMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
