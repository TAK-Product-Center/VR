// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Deprecated/Public/VH_UmgListEntry.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPanelWidget;
class UVH_ListEntryData;
class UVH_UmgListEntry;
enum class EListInteractionState : uint8;
struct FSlateChildSize;
#ifdef VH_UI_VH_UmgListEntry_generated_h
#error "VH_UmgListEntry.generated.h already included, missing '#pragma once' in VH_UmgListEntry.h"
#endif
#define VH_UI_VH_UmgListEntry_generated_h

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_16_DELEGATE \
VH_UI_API void FOnSelected_DelegateWrapper(const FScriptDelegate& OnSelected, UVH_UmgListEntry* entrySelected);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_SPARSE_DATA
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetLayoutHandler); \
	DECLARE_FUNCTION(execIsDisabled); \
	DECLARE_FUNCTION(execIsSelected); \
	DECLARE_FUNCTION(execK2_IsHovered); \
	DECLARE_FUNCTION(execSetHovered); \
	DECLARE_FUNCTION(execSetSelected); \
	DECLARE_FUNCTION(execSelectedChanged); \
	DECLARE_FUNCTION(execInitializeLayout); \
	DECLARE_FUNCTION(execIsLayoutInitialized); \
	DECLARE_FUNCTION(execGetInteractionState); \
	DECLARE_FUNCTION(execSetInteractionState); \
	DECLARE_FUNCTION(execGetHoverText); \
	DECLARE_FUNCTION(execGetIndexInList); \
	DECLARE_FUNCTION(execSetColumnSize); \
	DECLARE_FUNCTION(execGetData); \
	DECLARE_FUNCTION(execSetData);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_INCLASS \
private: \
	static void StaticRegisterNativesUVH_UmgListEntry(); \
	friend struct Z_Construct_UClass_UVH_UmgListEntry_Statics; \
public: \
	DECLARE_CLASS(UVH_UmgListEntry, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_UI"), NO_API) \
	DECLARE_SERIALIZER(UVH_UmgListEntry)


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVH_UmgListEntry(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVH_UmgListEntry) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVH_UmgListEntry); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVH_UmgListEntry); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVH_UmgListEntry(UVH_UmgListEntry&&); \
	NO_API UVH_UmgListEntry(const UVH_UmgListEntry&); \
public: \
	NO_API virtual ~UVH_UmgListEntry();


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_40_PROLOG
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_SPARSE_DATA \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_RPC_WRAPPERS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_INCLASS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h_43_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_UI_API UClass* StaticClass<class UVH_UmgListEntry>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgListEntry_h


#define FOREACH_ENUM_ELISTINTERACTIONSTATE(op) \
	op(EListInteractionState::ELIS_Available) \
	op(EListInteractionState::ELIS_AvailablePressed) \
	op(EListInteractionState::ELIS_Hovered) \
	op(EListInteractionState::ELIS_Selected) \
	op(EListInteractionState::ELIS_SelectedPressed) \
	op(EListInteractionState::ELIS_SelectedHovered) \
	op(EListInteractionState::ELIS_Disabled) 

enum class EListInteractionState : uint8;
template<> struct TIsUEnumClass<EListInteractionState> { enum { Value = true }; };
template<> VH_UI_API UEnum* StaticEnum<EListInteractionState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
