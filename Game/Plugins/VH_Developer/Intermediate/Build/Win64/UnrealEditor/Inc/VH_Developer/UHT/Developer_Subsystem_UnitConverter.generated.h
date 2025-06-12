// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystems/Public/Developer_Subsystem_UnitConverter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDeveloper_ConverterUnit;
class UDeveloper_Subsystem_UnitConverter_Settings;
#ifdef VH_DEVELOPER_Developer_Subsystem_UnitConverter_generated_h
#error "Developer_Subsystem_UnitConverter.generated.h already included, missing '#pragma once' in Developer_Subsystem_UnitConverter.h"
#endif
#define VH_DEVELOPER_Developer_Subsystem_UnitConverter_generated_h

#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_32_SPARSE_DATA
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_32_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_32_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAbbreviationFromName); \
	DECLARE_FUNCTION(execGetUnit); \
	DECLARE_FUNCTION(execGetUnitIDs); \
	DECLARE_FUNCTION(execConvertUnitsAndFormatByClass); \
	DECLARE_FUNCTION(execConvertUnitsByClass); \
	DECLARE_FUNCTION(execConvertUnitsAndFormat); \
	DECLARE_FUNCTION(execConvertUnits); \
	DECLARE_FUNCTION(execRegisterConverterUnitByClass); \
	DECLARE_FUNCTION(execUpdateSettings);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_32_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_32_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDeveloper_Subsystem_UnitConverter(); \
	friend struct Z_Construct_UClass_UDeveloper_Subsystem_UnitConverter_Statics; \
public: \
	DECLARE_CLASS(UDeveloper_Subsystem_UnitConverter, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Developer"), NO_API) \
	DECLARE_SERIALIZER(UDeveloper_Subsystem_UnitConverter)


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_32_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDeveloper_Subsystem_UnitConverter(UDeveloper_Subsystem_UnitConverter&&); \
	NO_API UDeveloper_Subsystem_UnitConverter(const UDeveloper_Subsystem_UnitConverter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDeveloper_Subsystem_UnitConverter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDeveloper_Subsystem_UnitConverter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UDeveloper_Subsystem_UnitConverter) \
	NO_API virtual ~UDeveloper_Subsystem_UnitConverter();


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_29_PROLOG
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_32_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_32_SPARSE_DATA \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_32_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_32_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_32_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_32_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h_32_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DEVELOPER_API UClass* StaticClass<class UDeveloper_Subsystem_UnitConverter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Developer_Source_VH_Developer_Subsystems_Public_Developer_Subsystem_UnitConverter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
