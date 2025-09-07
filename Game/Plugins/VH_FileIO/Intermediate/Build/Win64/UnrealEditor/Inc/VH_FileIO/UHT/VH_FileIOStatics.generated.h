// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/VH_FileIOStatics.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 
class UObject;
#ifdef VH_FILEIO_VH_FileIOStatics_generated_h
#error "VH_FileIOStatics.generated.h already included, missing '#pragma once' in VH_FileIOStatics.h"
#endif
#define VH_FILEIO_VH_FileIOStatics_generated_h

#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_17_SPARSE_DATA
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_17_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_17_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOpenFileWithDefaultProgram); \
	DECLARE_FUNCTION(execIsZipArchive); \
	DECLARE_FUNCTION(execParseExtensionsIntoArray); \
	DECLARE_FUNCTION(execDirectoryOrFileExistsInZip); \
	DECLARE_FUNCTION(execUnzipFile); \
	DECLARE_FUNCTION(execZipFile); \
	DECLARE_FUNCTION(execLoadAssetsInPath); \
	DECLARE_FUNCTION(execGetDirectoriesInPath); \
	DECLARE_FUNCTION(execGetFilesInPath);


#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_17_ACCESSORS
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVH_FileIOStatics(); \
	friend struct Z_Construct_UClass_UVH_FileIOStatics_Statics; \
public: \
	DECLARE_CLASS(UVH_FileIOStatics, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_FileIO"), NO_API) \
	DECLARE_SERIALIZER(UVH_FileIOStatics)


#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVH_FileIOStatics(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVH_FileIOStatics(UVH_FileIOStatics&&); \
	NO_API UVH_FileIOStatics(const UVH_FileIOStatics&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVH_FileIOStatics); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVH_FileIOStatics); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVH_FileIOStatics) \
	NO_API virtual ~UVH_FileIOStatics();


#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_14_PROLOG
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_17_SPARSE_DATA \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_17_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_17_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_17_ACCESSORS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_17_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_FILEIO_API UClass* StaticClass<class UVH_FileIOStatics>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Core_Public_VH_FileIOStatics_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
