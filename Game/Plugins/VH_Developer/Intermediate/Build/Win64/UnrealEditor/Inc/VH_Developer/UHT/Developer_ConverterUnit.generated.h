// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ConverterUnits/Public/Developer_ConverterUnit.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VH_DEVELOPER_Developer_ConverterUnit_generated_h
#error "Developer_ConverterUnit.generated.h already included, missing '#pragma once' in Developer_ConverterUnit.h"
#endif
#define VH_DEVELOPER_Developer_ConverterUnit_generated_h

#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_SPARSE_DATA
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual FString ConvertToStandard_Implementation(const FString& unitValue); \
	virtual FString ConvertFromStandard_Implementation(const FString& standardValue); \
 \
	DECLARE_FUNCTION(execFormatText); \
	DECLARE_FUNCTION(execConvertToStandard); \
	DECLARE_FUNCTION(execConvertFromStandard); \
	DECLARE_FUNCTION(execGetStandardUnit); \
	DECLARE_FUNCTION(execGetID); \
	DECLARE_FUNCTION(execGetAbbreviation);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDeveloper_ConverterUnit(); \
	friend struct Z_Construct_UClass_UDeveloper_ConverterUnit_Statics; \
public: \
	DECLARE_CLASS(UDeveloper_ConverterUnit, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/VH_Developer"), NO_API) \
	DECLARE_SERIALIZER(UDeveloper_ConverterUnit)


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDeveloper_ConverterUnit(UDeveloper_ConverterUnit&&); \
	NO_API UDeveloper_ConverterUnit(const UDeveloper_ConverterUnit&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDeveloper_ConverterUnit); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDeveloper_ConverterUnit); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(UDeveloper_ConverterUnit) \
	NO_API virtual ~UDeveloper_ConverterUnit();


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_9_PROLOG
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_SPARSE_DATA \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DEVELOPER_API UClass* StaticClass<class UDeveloper_ConverterUnit>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Developer_Source_VH_Developer_ConverterUnits_Public_Developer_ConverterUnit_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
