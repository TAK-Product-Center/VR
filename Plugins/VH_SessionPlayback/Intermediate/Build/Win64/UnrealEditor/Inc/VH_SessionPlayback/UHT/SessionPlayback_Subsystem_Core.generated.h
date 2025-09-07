// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystems/Public/SessionPlayback_Subsystem_Core.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USessionPlayback_Impl;
enum class EPlaybackStatus : uint8;
#ifdef VH_SESSIONPLAYBACK_SessionPlayback_Subsystem_Core_generated_h
#error "SessionPlayback_Subsystem_Core.generated.h already included, missing '#pragma once' in SessionPlayback_Subsystem_Core.h"
#endif
#define VH_SESSIONPLAYBACK_SessionPlayback_Subsystem_Core_generated_h

#define FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_41_DELEGATE \
static void FPlaybackRateUpdated_DelegateWrapper(const FMulticastScriptDelegate& PlaybackRateUpdated, float playbackRate);


#define FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_43_DELEGATE \
static void FPlaybackStatusUpdated_DelegateWrapper(const FMulticastScriptDelegate& PlaybackStatusUpdated, EPlaybackStatus status);


#define FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_25_SPARSE_DATA
#define FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_25_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_25_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execTest_StopRecordSessionPlayback); \
	DECLARE_FUNCTION(execTest_RecordSessionPlayback); \
	DECLARE_FUNCTION(execTest_LoadSessionPlayback); \
	DECLARE_FUNCTION(execIsPlaying); \
	DECLARE_FUNCTION(execGetPlaybackStatus); \
	DECLARE_FUNCTION(execStopRecord); \
	DECLARE_FUNCTION(execStartRecord); \
	DECLARE_FUNCTION(execGetSecondsPassed); \
	DECLARE_FUNCTION(execSetSecondsPassed); \
	DECLARE_FUNCTION(execGetPlaybackDuration); \
	DECLARE_FUNCTION(execGetPlaybackRate); \
	DECLARE_FUNCTION(execSetPlaybackRate); \
	DECLARE_FUNCTION(execUnloadPlayback); \
	DECLARE_FUNCTION(execLoadPlayback); \
	DECLARE_FUNCTION(execGetImplementation); \
	DECLARE_FUNCTION(execSetImplementation);


#define FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_25_ACCESSORS
#define FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSessionPlayback_Subsystem_Core(); \
	friend struct Z_Construct_UClass_USessionPlayback_Subsystem_Core_Statics; \
public: \
	DECLARE_CLASS(USessionPlayback_Subsystem_Core, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_SessionPlayback"), NO_API) \
	DECLARE_SERIALIZER(USessionPlayback_Subsystem_Core)


#define FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_25_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USessionPlayback_Subsystem_Core(USessionPlayback_Subsystem_Core&&); \
	NO_API USessionPlayback_Subsystem_Core(const USessionPlayback_Subsystem_Core&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USessionPlayback_Subsystem_Core); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USessionPlayback_Subsystem_Core); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USessionPlayback_Subsystem_Core) \
	NO_API virtual ~USessionPlayback_Subsystem_Core();


#define FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_22_PROLOG
#define FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_25_SPARSE_DATA \
	FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_25_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_25_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_25_ACCESSORS \
	FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_25_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_SESSIONPLAYBACK_API UClass* StaticClass<class USessionPlayback_Subsystem_Core>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_SessionPlayback_Source_VH_SessionPlayback_Subsystems_Public_SessionPlayback_Subsystem_Core_h


#define FOREACH_ENUM_EPLAYBACKSTATUS(op) \
	op(EPlaybackStatus::EPS_Idle) \
	op(EPlaybackStatus::EPS_PlaybackInProgress) \
	op(EPlaybackStatus::EPS_PlaybackFinished) \
	op(EPlaybackStatus::EPS_PlaybackRecording) 

enum class EPlaybackStatus : uint8;
template<> struct TIsUEnumClass<EPlaybackStatus> { enum { Value = true }; };
template<> VH_SESSIONPLAYBACK_API UEnum* StaticEnum<EPlaybackStatus>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
