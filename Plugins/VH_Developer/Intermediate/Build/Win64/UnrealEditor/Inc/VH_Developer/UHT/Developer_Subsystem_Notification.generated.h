// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystems/Public/Developer_Subsystem_Notification.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FNotificationData;
#ifdef VH_DEVELOPER_Developer_Subsystem_Notification_generated_h
#error "Developer_Subsystem_Notification.generated.h already included, missing '#pragma once' in Developer_Subsystem_Notification.h"
#endif
#define VH_DEVELOPER_Developer_Subsystem_Notification_generated_h

#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_20_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FNotificationData_Statics; \
	VH_DEVELOPER_API static class UScriptStruct* StaticStruct();


template<> VH_DEVELOPER_API UScriptStruct* StaticStruct<struct FNotificationData>();

#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_68_DELEGATE \
static void FNotificationDelegate_DelegateWrapper(const FMulticastScriptDelegate& NotificationDelegate, FNotificationData const& notificationData);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_60_SPARSE_DATA
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_60_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_60_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_60_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEndNotification); \
	DECLARE_FUNCTION(execAddNotification);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_60_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_60_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDeveloper_Subsystem_Notification(); \
	friend struct Z_Construct_UClass_UDeveloper_Subsystem_Notification_Statics; \
public: \
	DECLARE_CLASS(UDeveloper_Subsystem_Notification, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Developer"), NO_API) \
	DECLARE_SERIALIZER(UDeveloper_Subsystem_Notification)


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_60_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDeveloper_Subsystem_Notification(UDeveloper_Subsystem_Notification&&); \
	NO_API UDeveloper_Subsystem_Notification(const UDeveloper_Subsystem_Notification&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDeveloper_Subsystem_Notification); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDeveloper_Subsystem_Notification); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDeveloper_Subsystem_Notification) \
	NO_API virtual ~UDeveloper_Subsystem_Notification();


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_57_PROLOG
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_60_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_60_SPARSE_DATA \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_60_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_60_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_60_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_60_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_60_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h_60_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DEVELOPER_API UClass* StaticClass<class UDeveloper_Subsystem_Notification>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_Notification_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
