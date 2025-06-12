// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Core/Public/VH_KmlTypes.h"
#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VH_FILEIO_KML_VH_KmlTypes_generated_h
#error "VH_KmlTypes.generated.h already included, missing '#pragma once' in VH_KmlTypes.h"
#endif
#define VH_FILEIO_KML_VH_KmlTypes_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_KML_Core_Public_VH_KmlTypes_h


#define FOREACH_ENUM_EKMLELEMENTTYPE(op) \
	op(EKmlElementType::Element) \
	op(EKmlElementType::Object) \
	op(EKmlElementType::Feature) \
	op(EKmlElementType::Container) \
	op(EKmlElementType::Folder) \
	op(EKmlElementType::Document) \
	op(EKmlElementType::NetworkLink) \
	op(EKmlElementType::Overlay) \
	op(EKmlElementType::GroundOverlay) \
	op(EKmlElementType::PhotoOverlay) \
	op(EKmlElementType::ScreenOverlay) \
	op(EKmlElementType::Placemark) \
	op(EKmlElementType::Geometry) \
	op(EKmlElementType::LinearRing) \
	op(EKmlElementType::LineString) \
	op(EKmlElementType::MultiGeometry) \
	op(EKmlElementType::Model) \
	op(EKmlElementType::Point) \
	op(EKmlElementType::Polygon) \
	op(EKmlElementType::ColorStyle) \
	op(EKmlElementType::BalloonStyle) \
	op(EKmlElementType::LabelStyle) \
	op(EKmlElementType::LineStyle) \
	op(EKmlElementType::IconStyle) \
	op(EKmlElementType::PolyStyle) \
	op(EKmlElementType::Data) \
	op(EKmlElementType::ViewVolume) \
	op(EKmlElementType::Icon) \
	op(EKmlElementType::IconStyleIcon) \
	op(EKmlElementType::GxLatLonQuad) \
	op(EKmlElementType::LatLonBox) \
	op(EKmlElementType::Camera) \
	op(EKmlElementType::LookAt) \
	op(EKmlElementType::StyleSelector) \
	op(EKmlElementType::Style) \
	op(EKmlElementType::StyleMap) \
	op(EKmlElementType::Coordinates) \
	op(EKmlElementType::ExtendedData) \
	op(EKmlElementType::Vec2) \
	op(EKmlElementType::HotSpot) 

enum class EKmlElementType : uint8;
template<> struct TIsUEnumClass<EKmlElementType> { enum { Value = true }; };
template<> VH_FILEIO_KML_API UEnum* StaticEnum<EKmlElementType>();

#define FOREACH_ENUM_EKMLALTITUDEMODE(op) \
	op(EKmlAltitudeMode::ClampToGround) \
	op(EKmlAltitudeMode::RelativeToGround) \
	op(EKmlAltitudeMode::Absolute) \
	op(EKmlAltitudeMode::RelativeToSeaFloor) \
	op(EKmlAltitudeMode::ClampToSeaFloor) 

enum class EKmlAltitudeMode : uint8;
template<> struct TIsUEnumClass<EKmlAltitudeMode> { enum { Value = true }; };
template<> VH_FILEIO_KML_API UEnum* StaticEnum<EKmlAltitudeMode>();

#define FOREACH_ENUM_EKMLUNITS(op) \
	op(EKmlUnits::Fraction) \
	op(EKmlUnits::Pixels) \
	op(EKmlUnits::InsetPixels) 

enum class EKmlUnits : uint8;
template<> struct TIsUEnumClass<EKmlUnits> { enum { Value = true }; };
template<> VH_FILEIO_KML_API UEnum* StaticEnum<EKmlUnits>();

#define FOREACH_ENUM_EKMLCOLORMODE(op) \
	op(EKmlColorMode::Normal) \
	op(EKmlColorMode::Random) 

enum class EKmlColorMode : uint8;
template<> struct TIsUEnumClass<EKmlColorMode> { enum { Value = true }; };
template<> VH_FILEIO_KML_API UEnum* StaticEnum<EKmlColorMode>();

#define FOREACH_ENUM_EKMLSTYLESTATE(op) \
	op(EKmlStyleState::Normal) \
	op(EKmlStyleState::Highlight) 

enum class EKmlStyleState : uint8;
template<> struct TIsUEnumClass<EKmlStyleState> { enum { Value = true }; };
template<> VH_FILEIO_KML_API UEnum* StaticEnum<EKmlStyleState>();

#define FOREACH_ENUM_EKMLDISPLAYMODE(op) \
	op(EKmlDisplayMode::Default) \
	op(EKmlDisplayMode::Hide) 

enum class EKmlDisplayMode : uint8;
template<> struct TIsUEnumClass<EKmlDisplayMode> { enum { Value = true }; };
template<> VH_FILEIO_KML_API UEnum* StaticEnum<EKmlDisplayMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
