// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Deprecated/Public/VH_UmgWidget_List.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPanelSlot;
class UPanelWidget;
class UVH_ListEntryData;
class UVH_UmgListEntry;
enum class EListInteractionStyle : uint8;
enum class ESortType : uint8;
struct FSlateChildSize;
#ifdef VH_UI_VH_UmgWidget_List_generated_h
#error "VH_UmgWidget_List.generated.h already included, missing '#pragma once' in VH_UmgWidget_List.h"
#endif
#define VH_UI_VH_UmgWidget_List_generated_h

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_62_DELEGATE \
static void FOnListSelectionChanged_DelegateWrapper(const FMulticastScriptDelegate& OnListSelectionChanged, TArray<UVH_UmgListEntry*> const& curSelectedEntries);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_63_DELEGATE \
static void FOnEntryEvent_DelegateWrapper(const FMulticastScriptDelegate& OnEntryEvent, UVH_ListEntryData* data, UVH_UmgListEntry* listEntry);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_65_DELEGATE \
static bool FOnSortRequest_DelegateWrapper(const FScriptDelegate& OnSortRequest, int32 sortColumn, ESortType sortType);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_SPARSE_DATA
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_RPC_WRAPPERS \
	virtual void InsertItem_Implementation(UVH_UmgListEntry* widgetInstance, int32 insertIdx); \
	virtual void AddItem_Implementation(UVH_UmgListEntry* widgetInstance); \
	virtual bool RemoveItem_Implementation(UVH_UmgListEntry* widgetInstance); \
	virtual void ClearItems_Implementation(); \
 \
	DECLARE_FUNCTION(execInsertItem); \
	DECLARE_FUNCTION(execAddItem); \
	DECLARE_FUNCTION(execRemoveItem); \
	DECLARE_FUNCTION(execClearItems); \
	DECLARE_FUNCTION(execHandleEnterPressed); \
	DECLARE_FUNCTION(execHandleEntryDoubleClicked); \
	DECLARE_FUNCTION(execHandleEntryClicked); \
	DECLARE_FUNCTION(execUpdateCellSizes); \
	DECLARE_FUNCTION(execUpdateAllCellSizes); \
	DECLARE_FUNCTION(execSetSlotSizeData); \
	DECLARE_FUNCTION(execSortByColumn); \
	DECLARE_FUNCTION(execRebuildVisualList); \
	DECLARE_FUNCTION(execClearSelections); \
	DECLARE_FUNCTION(execDeselectEntry); \
	DECLARE_FUNCTION(execSetEntryDataSelected); \
	DECLARE_FUNCTION(execSetEntrySelected); \
	DECLARE_FUNCTION(execSetIndicesSelected); \
	DECLARE_FUNCTION(execSetIndexSelected); \
	DECLARE_FUNCTION(execGetSelectedEntries); \
	DECLARE_FUNCTION(execGetSelectedIndices); \
	DECLARE_FUNCTION(execGetEntryForData); \
	DECLARE_FUNCTION(execGetEntryAtIndex); \
	DECLARE_FUNCTION(execGetDataIndex); \
	DECLARE_FUNCTION(execSetEntryIndex); \
	DECLARE_FUNCTION(execGetEntryIndex); \
	DECLARE_FUNCTION(execGetListEntries); \
	DECLARE_FUNCTION(execClearEntries); \
	DECLARE_FUNCTION(execRemoveEntryByData); \
	DECLARE_FUNCTION(execRemoveEntry); \
	DECLARE_FUNCTION(execCreateEntryByClass); \
	DECLARE_FUNCTION(execCreateEntry); \
	DECLARE_FUNCTION(execSetLayoutHandler); \
	DECLARE_FUNCTION(execCanToggleSelection); \
	DECLARE_FUNCTION(execPreferSingleSelection); \
	DECLARE_FUNCTION(execCanMultiSelect); \
	DECLARE_FUNCTION(execSetInteractionStyle); \
	DECLARE_FUNCTION(execGetNumEntries);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_INCLASS \
private: \
	static void StaticRegisterNativesUVH_UmgWidget_List(); \
	friend struct Z_Construct_UClass_UVH_UmgWidget_List_Statics; \
public: \
	DECLARE_CLASS(UVH_UmgWidget_List, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_UI"), NO_API) \
	DECLARE_SERIALIZER(UVH_UmgWidget_List)


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVH_UmgWidget_List(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVH_UmgWidget_List) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVH_UmgWidget_List); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVH_UmgWidget_List); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVH_UmgWidget_List(UVH_UmgWidget_List&&); \
	NO_API UVH_UmgWidget_List(const UVH_UmgWidget_List&); \
public: \
	NO_API virtual ~UVH_UmgWidget_List();


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_52_PROLOG
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_SPARSE_DATA \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_RPC_WRAPPERS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_INCLASS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h_55_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_UI_API UClass* StaticClass<class UVH_UmgWidget_List>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_UmgWidget_List_h


#define FOREACH_ENUM_ELISTINTERACTIONSTYLE(op) \
	op(EListInteractionStyle::ELIS_List) \
	op(EListInteractionStyle::ELIS_RadioButtons) \
	op(EListInteractionStyle::ELIS_Checkboxes) 

enum class EListInteractionStyle : uint8;
template<> struct TIsUEnumClass<EListInteractionStyle> { enum { Value = true }; };
template<> VH_UI_API UEnum* StaticEnum<EListInteractionStyle>();

#define FOREACH_ENUM_ESORTTYPE(op) \
	op(ESortType::Ascending) \
	op(ESortType::Descending) \
	op(ESortType::Default) 

enum class ESortType : uint8;
template<> struct TIsUEnumClass<ESortType> { enum { Value = true }; };
template<> VH_UI_API UEnum* StaticEnum<ESortType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
