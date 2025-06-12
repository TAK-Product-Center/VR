// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/Public/VH_VehicleAsyncMoveTo.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AAIController;
class UNavigationQueryFilter;
class UObject;
class UVH_VehicleAsyncMoveTo;
#ifdef VH_VEHICLE_VH_VehicleAsyncMoveTo_generated_h
#error "VH_VehicleAsyncMoveTo.generated.h already included, missing '#pragma once' in VH_VehicleAsyncMoveTo.h"
#endif
#define VH_VEHICLE_VH_VehicleAsyncMoveTo_generated_h

#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_19_DELEGATE \
VH_VEHICLE_API void FAsyncPathFindComplete_DelegateWrapper(const FMulticastScriptDelegate& AsyncPathFindComplete, ENavigationQueryResult::Type Result);


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_27_SPARSE_DATA
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_27_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_27_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAsyncMoveTo);


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_27_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVH_VehicleAsyncMoveTo(); \
	friend struct Z_Construct_UClass_UVH_VehicleAsyncMoveTo_Statics; \
public: \
	DECLARE_CLASS(UVH_VehicleAsyncMoveTo, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_Vehicle"), NO_API) \
	DECLARE_SERIALIZER(UVH_VehicleAsyncMoveTo)


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_27_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVH_VehicleAsyncMoveTo(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVH_VehicleAsyncMoveTo(UVH_VehicleAsyncMoveTo&&); \
	NO_API UVH_VehicleAsyncMoveTo(const UVH_VehicleAsyncMoveTo&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVH_VehicleAsyncMoveTo); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVH_VehicleAsyncMoveTo); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVH_VehicleAsyncMoveTo) \
	NO_API virtual ~UVH_VehicleAsyncMoveTo();


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_24_PROLOG
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_27_SPARSE_DATA \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_27_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_27_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_27_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_27_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_VEHICLE_API UClass* StaticClass<class UVH_VehicleAsyncMoveTo>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAsyncMoveTo_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
