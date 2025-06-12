// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Deprecated/Public/VH_TextInput.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UEditableTextBox;
#ifdef VH_UI_VH_TextInput_generated_h
#error "VH_TextInput.generated.h already included, missing '#pragma once' in VH_TextInput.h"
#endif
#define VH_UI_VH_TextInput_generated_h

#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_14_DELEGATE \
VH_UI_API void FOnEntrySubmitted_DelegateWrapper(const FMulticastScriptDelegate& OnEntrySubmitted, const FString& inString);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_18_DELEGATE \
VH_UI_API void FOnEntryCancelled_DelegateWrapper(const FMulticastScriptDelegate& OnEntryCancelled);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_22_DELEGATE \
VH_UI_API void FOnTextEdited_DelegateWrapper(const FMulticastScriptDelegate& OnTextEdited, const FString& inString);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_SPARSE_DATA
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_RPC_WRAPPERS \
	virtual void HandleTextEdited_Implementation(FText const& inCommittedText); \
	virtual void SetTextBox_Implementation(UEditableTextBox* inTextBox); \
 \
	DECLARE_FUNCTION(execHandleTextEdited); \
	DECLARE_FUNCTION(execHandleTextBoxCommitted); \
	DECLARE_FUNCTION(execSetTextBox); \
	DECLARE_FUNCTION(execSetText); \
	DECLARE_FUNCTION(execGetText);


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_ACCESSORS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_CALLBACK_WRAPPERS
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_INCLASS \
private: \
	static void StaticRegisterNativesUVH_TextInput(); \
	friend struct Z_Construct_UClass_UVH_TextInput_Statics; \
public: \
	DECLARE_CLASS(UVH_TextInput, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_UI"), NO_API) \
	DECLARE_SERIALIZER(UVH_TextInput)


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVH_TextInput(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVH_TextInput) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVH_TextInput); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVH_TextInput); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVH_TextInput(UVH_TextInput&&); \
	NO_API UVH_TextInput(const UVH_TextInput&); \
public: \
	NO_API virtual ~UVH_TextInput();


#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_24_PROLOG
#define FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_SPARSE_DATA \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_RPC_WRAPPERS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_ACCESSORS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_CALLBACK_WRAPPERS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_INCLASS \
	FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h_27_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_UI_API UClass* StaticClass<class UVH_TextInput>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_UI_Source_VH_UI_Deprecated_Public_VH_TextInput_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
