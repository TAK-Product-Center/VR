// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AI/Public/VH_SplineNavLinkComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UVH_SplineNavLinkComponent;
#ifdef VH_VEHICLE_VH_SplineNavLinkComponent_generated_h
#error "VH_SplineNavLinkComponent.generated.h already included, missing '#pragma once' in VH_SplineNavLinkComponent.h"
#endif
#define VH_VEHICLE_VH_SplineNavLinkComponent_generated_h

#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_18_DELEGATE \
VH_VEHICLE_API void FOnMoveReachedLink_DelegateWrapper(const FMulticastScriptDelegate& OnMoveReachedLink, UVH_SplineNavLinkComponent* ThisComp, AActor* Agent, FVector const& DestPoint);


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_26_SPARSE_DATA
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_26_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_26_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetAllowTraverse); \
	DECLARE_FUNCTION(execResumePathFollowing); \
	DECLARE_FUNCTION(execCanTraverseLink);


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_26_ACCESSORS
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVH_SplineNavLinkComponent(); \
	friend struct Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics; \
public: \
	DECLARE_CLASS(UVH_SplineNavLinkComponent, USplineComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VH_Vehicle"), NO_API) \
	DECLARE_SERIALIZER(UVH_SplineNavLinkComponent) \
	virtual UObject* _getUObject() const override { return const_cast<UVH_SplineNavLinkComponent*>(this); }


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_26_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVH_SplineNavLinkComponent(UVH_SplineNavLinkComponent&&); \
	NO_API UVH_SplineNavLinkComponent(const UVH_SplineNavLinkComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVH_SplineNavLinkComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVH_SplineNavLinkComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVH_SplineNavLinkComponent) \
	NO_API virtual ~UVH_SplineNavLinkComponent();


#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_23_PROLOG
#define FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_26_SPARSE_DATA \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_26_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_26_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_26_ACCESSORS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_26_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_VEHICLE_API UClass* StaticClass<class UVH_SplineNavLinkComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
