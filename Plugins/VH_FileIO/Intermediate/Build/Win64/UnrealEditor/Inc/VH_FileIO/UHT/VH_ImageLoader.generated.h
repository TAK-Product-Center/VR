// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Misc/Public/VH_ImageLoader.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTexture2D;
#ifdef VH_FILEIO_VH_ImageLoader_generated_h
#error "VH_ImageLoader.generated.h already included, missing '#pragma once' in VH_ImageLoader.h"
#endif
#define VH_FILEIO_VH_ImageLoader_generated_h

#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_26_DELEGATE \
static void FOnImageLoadCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnImageLoadCompleted, UTexture2D* Texture);


#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_18_SPARSE_DATA
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_18_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_18_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLoadImageFromDB); \
	DECLARE_FUNCTION(execLoadImageFromDisk);


#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_18_ACCESSORS
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVH_ImageLoader(); \
	friend struct Z_Construct_UClass_UVH_ImageLoader_Statics; \
public: \
	DECLARE_CLASS(UVH_ImageLoader, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_FileIO"), NO_API) \
	DECLARE_SERIALIZER(UVH_ImageLoader)


#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVH_ImageLoader(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVH_ImageLoader(UVH_ImageLoader&&); \
	NO_API UVH_ImageLoader(const UVH_ImageLoader&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVH_ImageLoader); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVH_ImageLoader); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVH_ImageLoader) \
	NO_API virtual ~UVH_ImageLoader();


#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_15_PROLOG
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_18_SPARSE_DATA \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_18_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_18_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_18_ACCESSORS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_18_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_FILEIO_API UClass* StaticClass<class UVH_ImageLoader>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Misc_Public_VH_ImageLoader_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
