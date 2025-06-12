// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "VH_URI.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VH_FILEIO_NETWORK_VH_URI_generated_h
#error "VH_URI.generated.h already included, missing '#pragma once' in VH_URI.h"
#endif
#define VH_FILEIO_NETWORK_VH_URI_generated_h

#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_37_SPARSE_DATA
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_37_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_37_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_37_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_37_ACCESSORS
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_37_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVH_URI(); \
	friend struct Z_Construct_UClass_UVH_URI_Statics; \
public: \
	DECLARE_CLASS(UVH_URI, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/VH_FileIO_Network"), NO_API) \
	DECLARE_SERIALIZER(UVH_URI)


#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_37_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVH_URI(UVH_URI&&); \
	NO_API UVH_URI(const UVH_URI&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVH_URI); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVH_URI); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UVH_URI) \
	NO_API virtual ~UVH_URI();


#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_34_PROLOG
#define FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_37_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_37_SPARSE_DATA \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_37_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_37_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_37_ACCESSORS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_37_INCLASS_NO_PURE_DECLS \
	FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h_37_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> VH_FILEIO_NETWORK_API UClass* StaticClass<class UVH_URI>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_Network_Public_VH_URI_h


#define FOREACH_ENUM_ESCHEMETYPEENUM(op) \
	op(ESchemeTypeEnum::EST_UNKNOWN) \
	op(ESchemeTypeEnum::EST_UDP) \
	op(ESchemeTypeEnum::EST_RTSP) \
	op(ESchemeTypeEnum::EST_HTTP) \
	op(ESchemeTypeEnum::EST_HTTPS) \
	op(ESchemeTypeEnum::EST_TCP) \
	op(ESchemeTypeEnum::EST_RTMP) \
	op(ESchemeTypeEnum::EST_RTMPS) \
	op(ESchemeTypeEnum::EST_RTP) \
	op(ESchemeTypeEnum::EST_SRT) \
	op(ESchemeTypeEnum::EST_FTP) \
	op(ESchemeTypeEnum::EST_FILE) \
	op(ESchemeTypeEnum::EST_DIRECTORY) \
	op(ESchemeTypeEnum::EST_RAW) 

enum class ESchemeTypeEnum : uint8;
template<> struct TIsUEnumClass<ESchemeTypeEnum> { enum { Value = true }; };
template<> VH_FILEIO_NETWORK_API UEnum* StaticEnum<ESchemeTypeEnum>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
