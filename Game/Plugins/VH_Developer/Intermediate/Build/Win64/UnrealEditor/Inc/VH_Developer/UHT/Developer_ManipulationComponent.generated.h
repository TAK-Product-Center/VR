// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Components/Public/Developer_ManipulationComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef VH_DEVELOPER_Developer_ManipulationComponent_generated_h
#error "Developer_ManipulationComponent.generated.h already included, missing '#pragma once' in Developer_ManipulationComponent.h"
#endif
#define VH_DEVELOPER_Developer_ManipulationComponent_generated_h

#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_SPARSE_DATA
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Server_SetWorldScale_Implementation(AActor* actor, FVector const& scale); \
	virtual void Server_SetWorldRotation_Implementation(AActor* actor, FQuat const& rotation); \
	virtual void Server_SetWorldLocation_Implementation(AActor* actor, FVector const& location); \
 \
	DECLARE_FUNCTION(execServer_SetWorldScale); \
	DECLARE_FUNCTION(execServer_SetWorldRotation); \
	DECLARE_FUNCTION(execServer_SetWorldLocation);


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_ACCESSORS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDeveloper_ManipulationComponent(); \
	friend struct Z_Construct_UClass_UDeveloper_ManipulationComponent_Statics; \
public: \
	DECLARE_CLASS(UDeveloper_ManipulationComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VH_Developer"), NO_API) \
	DECLARE_SERIALIZER(UDeveloper_ManipulationComponent)


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDeveloper_ManipulationComponent(UDeveloper_ManipulationComponent&&); \
	NO_API UDeveloper_ManipulationComponent(const UDeveloper_ManipulationComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDeveloper_ManipulationComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDeveloper_ManipulationComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDeveloper_ManipulationComponent) \
	NO_API virtual ~UDeveloper_ManipulationComponent();


#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_11_PROLOG
#define FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_SPARSE_DATA \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_ACCESSORS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_DEVELOPER_API UClass* StaticClass<class UDeveloper_ManipulationComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_Developer_Source_VH_Developer_Components_Public_Developer_ManipulationComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
