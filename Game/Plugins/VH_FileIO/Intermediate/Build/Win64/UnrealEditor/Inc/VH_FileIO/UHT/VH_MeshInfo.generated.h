// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Mesh/Public/VH_MeshInfo.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UVH_MeshInfo;
struct FVH_MeshImportOptions;
#ifdef VH_FILEIO_VH_MeshInfo_generated_h
#error "VH_MeshInfo.generated.h already included, missing '#pragma once' in VH_MeshInfo.h"
#endif
#define VH_FILEIO_VH_MeshInfo_generated_h

#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_14_SPARSE_DATA
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_14_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetDefaultImportOptions); \
	DECLARE_FUNCTION(execCreate);


#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_14_ACCESSORS
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVH_MeshInfo(); \
	friend struct Z_Construct_UClass_UVH_MeshInfo_Statics; \
public: \
	DECLARE_CLASS(UVH_MeshInfo, UObject, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/VH_FileIO"), NO_API) \
	DECLARE_SERIALIZER(UVH_MeshInfo) \
	static const TCHAR* StaticConfigName() {return TEXT("VH_FileIO");} \



#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVH_MeshInfo(UVH_MeshInfo&&); \
	NO_API UVH_MeshInfo(const UVH_MeshInfo&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVH_MeshInfo); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVH_MeshInfo); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UVH_MeshInfo) \
	NO_API virtual ~UVH_MeshInfo();


#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_11_PROLOG
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_14_SPARSE_DATA \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_14_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_14_ACCESSORS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_14_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_FILEIO_API UClass* StaticClass<class UVH_MeshInfo>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Mesh_Public_VH_MeshInfo_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
