// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_KmlTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_KmlTypes() {}
// Cross Module References
	UPackage* Z_Construct_UPackage__Script_VH_FileIO_Kml();
	VH_FILEIO_KML_API UEnum* Z_Construct_UEnum_VH_FileIO_Kml_EKmlAltitudeMode();
	VH_FILEIO_KML_API UEnum* Z_Construct_UEnum_VH_FileIO_Kml_EKmlColorMode();
	VH_FILEIO_KML_API UEnum* Z_Construct_UEnum_VH_FileIO_Kml_EKmlDisplayMode();
	VH_FILEIO_KML_API UEnum* Z_Construct_UEnum_VH_FileIO_Kml_EKmlElementType();
	VH_FILEIO_KML_API UEnum* Z_Construct_UEnum_VH_FileIO_Kml_EKmlStyleState();
	VH_FILEIO_KML_API UEnum* Z_Construct_UEnum_VH_FileIO_Kml_EKmlUnits();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EKmlElementType;
	static UEnum* EKmlElementType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EKmlElementType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EKmlElementType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_FileIO_Kml_EKmlElementType, (UObject*)Z_Construct_UPackage__Script_VH_FileIO_Kml(), TEXT("EKmlElementType"));
		}
		return Z_Registration_Info_UEnum_EKmlElementType.OuterSingleton;
	}
	template<> VH_FILEIO_KML_API UEnum* StaticEnum<EKmlElementType>()
	{
		return EKmlElementType_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_FileIO_Kml_EKmlElementType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_FileIO_Kml_EKmlElementType_Statics::Enumerators[] = {
		{ "EKmlElementType::Element", (int64)EKmlElementType::Element },
		{ "EKmlElementType::Object", (int64)EKmlElementType::Object },
		{ "EKmlElementType::Feature", (int64)EKmlElementType::Feature },
		{ "EKmlElementType::Container", (int64)EKmlElementType::Container },
		{ "EKmlElementType::Folder", (int64)EKmlElementType::Folder },
		{ "EKmlElementType::Document", (int64)EKmlElementType::Document },
		{ "EKmlElementType::NetworkLink", (int64)EKmlElementType::NetworkLink },
		{ "EKmlElementType::Overlay", (int64)EKmlElementType::Overlay },
		{ "EKmlElementType::GroundOverlay", (int64)EKmlElementType::GroundOverlay },
		{ "EKmlElementType::PhotoOverlay", (int64)EKmlElementType::PhotoOverlay },
		{ "EKmlElementType::ScreenOverlay", (int64)EKmlElementType::ScreenOverlay },
		{ "EKmlElementType::Placemark", (int64)EKmlElementType::Placemark },
		{ "EKmlElementType::Geometry", (int64)EKmlElementType::Geometry },
		{ "EKmlElementType::LinearRing", (int64)EKmlElementType::LinearRing },
		{ "EKmlElementType::LineString", (int64)EKmlElementType::LineString },
		{ "EKmlElementType::MultiGeometry", (int64)EKmlElementType::MultiGeometry },
		{ "EKmlElementType::Model", (int64)EKmlElementType::Model },
		{ "EKmlElementType::Point", (int64)EKmlElementType::Point },
		{ "EKmlElementType::Polygon", (int64)EKmlElementType::Polygon },
		{ "EKmlElementType::ColorStyle", (int64)EKmlElementType::ColorStyle },
		{ "EKmlElementType::BalloonStyle", (int64)EKmlElementType::BalloonStyle },
		{ "EKmlElementType::LabelStyle", (int64)EKmlElementType::LabelStyle },
		{ "EKmlElementType::LineStyle", (int64)EKmlElementType::LineStyle },
		{ "EKmlElementType::IconStyle", (int64)EKmlElementType::IconStyle },
		{ "EKmlElementType::PolyStyle", (int64)EKmlElementType::PolyStyle },
		{ "EKmlElementType::Data", (int64)EKmlElementType::Data },
		{ "EKmlElementType::ViewVolume", (int64)EKmlElementType::ViewVolume },
		{ "EKmlElementType::Icon", (int64)EKmlElementType::Icon },
		{ "EKmlElementType::IconStyleIcon", (int64)EKmlElementType::IconStyleIcon },
		{ "EKmlElementType::GxLatLonQuad", (int64)EKmlElementType::GxLatLonQuad },
		{ "EKmlElementType::LatLonBox", (int64)EKmlElementType::LatLonBox },
		{ "EKmlElementType::Camera", (int64)EKmlElementType::Camera },
		{ "EKmlElementType::LookAt", (int64)EKmlElementType::LookAt },
		{ "EKmlElementType::StyleSelector", (int64)EKmlElementType::StyleSelector },
		{ "EKmlElementType::Style", (int64)EKmlElementType::Style },
		{ "EKmlElementType::StyleMap", (int64)EKmlElementType::StyleMap },
		{ "EKmlElementType::Coordinates", (int64)EKmlElementType::Coordinates },
		{ "EKmlElementType::ExtendedData", (int64)EKmlElementType::ExtendedData },
		{ "EKmlElementType::Vec2", (int64)EKmlElementType::Vec2 },
		{ "EKmlElementType::HotSpot", (int64)EKmlElementType::HotSpot },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_FileIO_Kml_EKmlElementType_Statics::Enum_MetaDataParams[] = {
		{ "BalloonStyle.Comment", "// ---- ColorStyle\n" },
		{ "BalloonStyle.Name", "EKmlElementType::BalloonStyle" },
		{ "BalloonStyle.ToolTip", "---- ColorStyle" },
		{ "BlueprintType", "true" },
		{ "Camera.Comment", "// TODO: Add AbstractView\n" },
		{ "Camera.Name", "EKmlElementType::Camera" },
		{ "Camera.ToolTip", "TODO: Add AbstractView" },
		{ "ColorStyle.Comment", "// ------ Polygon\n" },
		{ "ColorStyle.Name", "EKmlElementType::ColorStyle" },
		{ "ColorStyle.ToolTip", "------ Polygon" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// clang-format off\n" },
#endif
		{ "Container.Comment", "// ---- Feature\n" },
		{ "Container.Name", "EKmlElementType::Container" },
		{ "Container.ToolTip", "---- Feature" },
		{ "Coordinates.Comment", "// ---- StyleMap\n" },
		{ "Coordinates.Name", "EKmlElementType::Coordinates" },
		{ "Coordinates.ToolTip", "---- StyleMap" },
		{ "Data.Comment", "// ------ PolyStyle\n" },
		{ "Data.Name", "EKmlElementType::Data" },
		{ "Data.ToolTip", "------ PolyStyle" },
		{ "Document.Comment", "// -------- Folder\n" },
		{ "Document.Name", "EKmlElementType::Document" },
		{ "Document.ToolTip", "-------- Folder" },
		{ "Element.Name", "EKmlElementType::Element" },
		{ "ExtendedData.Comment", "// -- Coordinates\n" },
		{ "ExtendedData.Name", "EKmlElementType::ExtendedData" },
		{ "ExtendedData.ToolTip", "-- Coordinates" },
		{ "Feature.Comment", "// -- Object\n" },
		{ "Feature.Name", "EKmlElementType::Feature" },
		{ "Feature.ToolTip", "-- Object" },
		{ "Folder.Comment", "// ------ Container\n" },
		{ "Folder.Name", "EKmlElementType::Folder" },
		{ "Folder.ToolTip", "------ Container" },
		{ "Geometry.Comment", "// ------ Placemark\n" },
		{ "Geometry.Name", "EKmlElementType::Geometry" },
		{ "Geometry.ToolTip", "------ Placemark" },
		{ "GroundOverlay.Comment", "// ------ Overlay\n" },
		{ "GroundOverlay.Name", "EKmlElementType::GroundOverlay" },
		{ "GroundOverlay.ToolTip", "------ Overlay" },
		{ "GxLatLonQuad.Comment", "// ---- IconStyleIcon\n" },
		{ "GxLatLonQuad.Name", "EKmlElementType::GxLatLonQuad" },
		{ "GxLatLonQuad.ToolTip", "---- IconStyleIcon" },
		{ "HotSpot.Comment", "// -- Vec2\n" },
		{ "HotSpot.Name", "EKmlElementType::HotSpot" },
		{ "HotSpot.ToolTip", "-- Vec2" },
		{ "Icon.Comment", "// ---- ViewVolume\n" },
		{ "Icon.Name", "EKmlElementType::Icon" },
		{ "Icon.ToolTip", "---- ViewVolume" },
		{ "IconStyle.Comment", "// ------ LineStyle\n" },
		{ "IconStyle.Name", "EKmlElementType::IconStyle" },
		{ "IconStyle.ToolTip", "------ LineStyle" },
		{ "IconStyleIcon.Comment", "// ---- Icon\n" },
		{ "IconStyleIcon.Name", "EKmlElementType::IconStyleIcon" },
		{ "IconStyleIcon.ToolTip", "---- Icon" },
		{ "LabelStyle.Comment", "// ------ BalloonStyle\n" },
		{ "LabelStyle.Name", "EKmlElementType::LabelStyle" },
		{ "LabelStyle.ToolTip", "------ BalloonStyle" },
		{ "LatLonBox.Comment", "// ---- GxLatLonQuad\n" },
		{ "LatLonBox.Name", "EKmlElementType::LatLonBox" },
		{ "LatLonBox.ToolTip", "---- GxLatLonQuad" },
		{ "LinearRing.Comment", "// ---- Geometry\n" },
		{ "LinearRing.Name", "EKmlElementType::LinearRing" },
		{ "LinearRing.ToolTip", "---- Geometry" },
		{ "LineString.Comment", "// ------ LinearRing\n" },
		{ "LineString.Name", "EKmlElementType::LineString" },
		{ "LineString.ToolTip", "------ LinearRing" },
		{ "LineStyle.Comment", "// ------ LabelStyle\n" },
		{ "LineStyle.Name", "EKmlElementType::LineStyle" },
		{ "LineStyle.ToolTip", "------ LabelStyle" },
		{ "LookAt.Comment", "// ---- Camera\n" },
		{ "LookAt.Name", "EKmlElementType::LookAt" },
		{ "LookAt.ToolTip", "---- Camera" },
		{ "Model.Comment", "// ------ MultiGeometry\n" },
		{ "Model.Name", "EKmlElementType::Model" },
		{ "Model.ToolTip", "------ MultiGeometry" },
		{ "ModuleRelativePath", "Core/Public/VH_KmlTypes.h" },
		{ "MultiGeometry.Comment", "// ------ LineString\n" },
		{ "MultiGeometry.Name", "EKmlElementType::MultiGeometry" },
		{ "MultiGeometry.ToolTip", "------ LineString" },
		{ "NetworkLink.Comment", "// -------- Document\n" },
		{ "NetworkLink.Name", "EKmlElementType::NetworkLink" },
		{ "NetworkLink.ToolTip", "-------- Document" },
		{ "Object.Comment", "// Element\n" },
		{ "Object.Name", "EKmlElementType::Object" },
		{ "Object.ToolTip", "Element" },
		{ "Overlay.Comment", "// ------ NetworkLink\n" },
		{ "Overlay.Name", "EKmlElementType::Overlay" },
		{ "Overlay.ToolTip", "------ NetworkLink" },
		{ "PhotoOverlay.Comment", "// -------- GroundOverlay\n" },
		{ "PhotoOverlay.Name", "EKmlElementType::PhotoOverlay" },
		{ "PhotoOverlay.ToolTip", "-------- GroundOverlay" },
		{ "Placemark.Comment", "// -------- ScreenOverlay\n" },
		{ "Placemark.Name", "EKmlElementType::Placemark" },
		{ "Placemark.ToolTip", "-------- ScreenOverlay" },
		{ "Point.Comment", "// ------ Model\n" },
		{ "Point.Name", "EKmlElementType::Point" },
		{ "Point.ToolTip", "------ Model" },
		{ "Polygon.Comment", "// ------ Point\n" },
		{ "Polygon.Name", "EKmlElementType::Polygon" },
		{ "Polygon.ToolTip", "------ Point" },
		{ "PolyStyle.Comment", "// ------ IconStyle\n" },
		{ "PolyStyle.Name", "EKmlElementType::PolyStyle" },
		{ "PolyStyle.ToolTip", "------ IconStyle" },
		{ "ScreenOverlay.Comment", "// -------- PhotoOverlay\n" },
		{ "ScreenOverlay.Name", "EKmlElementType::ScreenOverlay" },
		{ "ScreenOverlay.ToolTip", "-------- PhotoOverlay" },
		{ "Style.Comment", "// -- StyleSelector\n" },
		{ "Style.Name", "EKmlElementType::Style" },
		{ "Style.ToolTip", "-- StyleSelector" },
		{ "StyleMap.Comment", "// ---- Style\n" },
		{ "StyleMap.Name", "EKmlElementType::StyleMap" },
		{ "StyleMap.ToolTip", "---- Style" },
		{ "StyleSelector.Comment", "// ---- LookAt\n" },
		{ "StyleSelector.Name", "EKmlElementType::StyleSelector" },
		{ "StyleSelector.ToolTip", "---- LookAt" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "clang-format off" },
#endif
		{ "Vec2.Comment", "// -- ExtendedData\n" },
		{ "Vec2.Name", "EKmlElementType::Vec2" },
		{ "Vec2.ToolTip", "-- ExtendedData" },
		{ "ViewVolume.Comment", "// ---- Data\n" },
		{ "ViewVolume.Name", "EKmlElementType::ViewVolume" },
		{ "ViewVolume.ToolTip", "---- Data" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_FileIO_Kml_EKmlElementType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_FileIO_Kml,
		nullptr,
		"EKmlElementType",
		"EKmlElementType",
		Z_Construct_UEnum_VH_FileIO_Kml_EKmlElementType_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_FileIO_Kml_EKmlElementType_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_FileIO_Kml_EKmlElementType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_FileIO_Kml_EKmlElementType_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_FileIO_Kml_EKmlElementType()
	{
		if (!Z_Registration_Info_UEnum_EKmlElementType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EKmlElementType.InnerSingleton, Z_Construct_UEnum_VH_FileIO_Kml_EKmlElementType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EKmlElementType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EKmlAltitudeMode;
	static UEnum* EKmlAltitudeMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EKmlAltitudeMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EKmlAltitudeMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_FileIO_Kml_EKmlAltitudeMode, (UObject*)Z_Construct_UPackage__Script_VH_FileIO_Kml(), TEXT("EKmlAltitudeMode"));
		}
		return Z_Registration_Info_UEnum_EKmlAltitudeMode.OuterSingleton;
	}
	template<> VH_FILEIO_KML_API UEnum* StaticEnum<EKmlAltitudeMode>()
	{
		return EKmlAltitudeMode_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_FileIO_Kml_EKmlAltitudeMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_FileIO_Kml_EKmlAltitudeMode_Statics::Enumerators[] = {
		{ "EKmlAltitudeMode::ClampToGround", (int64)EKmlAltitudeMode::ClampToGround },
		{ "EKmlAltitudeMode::RelativeToGround", (int64)EKmlAltitudeMode::RelativeToGround },
		{ "EKmlAltitudeMode::Absolute", (int64)EKmlAltitudeMode::Absolute },
		{ "EKmlAltitudeMode::RelativeToSeaFloor", (int64)EKmlAltitudeMode::RelativeToSeaFloor },
		{ "EKmlAltitudeMode::ClampToSeaFloor", (int64)EKmlAltitudeMode::ClampToSeaFloor },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_FileIO_Kml_EKmlAltitudeMode_Statics::Enum_MetaDataParams[] = {
		{ "Absolute.Name", "EKmlAltitudeMode::Absolute" },
		{ "BlueprintType", "true" },
		{ "ClampToGround.Name", "EKmlAltitudeMode::ClampToGround" },
		{ "ClampToSeaFloor.Name", "EKmlAltitudeMode::ClampToSeaFloor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * NOTE: Normal AltitudeMode contains ClampToGround, RelativeToGround, and Absolute (relative to sea level).\n *\x09\x09 gx:AltitudeMode contains RelativeToSeaFloor and ClampToSeaFloor. This enum includes all values.\n */" },
#endif
		{ "ModuleRelativePath", "Core/Public/VH_KmlTypes.h" },
		{ "RelativeToGround.Name", "EKmlAltitudeMode::RelativeToGround" },
		{ "RelativeToSeaFloor.Comment", "// NOTE: Relative to sea level\n" },
		{ "RelativeToSeaFloor.Name", "EKmlAltitudeMode::RelativeToSeaFloor" },
		{ "RelativeToSeaFloor.ToolTip", "NOTE: Relative to sea level" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* NOTE: Normal AltitudeMode contains ClampToGround, RelativeToGround, and Absolute (relative to sea level).\n*              gx:AltitudeMode contains RelativeToSeaFloor and ClampToSeaFloor. This enum includes all values." },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_FileIO_Kml_EKmlAltitudeMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_FileIO_Kml,
		nullptr,
		"EKmlAltitudeMode",
		"EKmlAltitudeMode",
		Z_Construct_UEnum_VH_FileIO_Kml_EKmlAltitudeMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_FileIO_Kml_EKmlAltitudeMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_FileIO_Kml_EKmlAltitudeMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_FileIO_Kml_EKmlAltitudeMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_FileIO_Kml_EKmlAltitudeMode()
	{
		if (!Z_Registration_Info_UEnum_EKmlAltitudeMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EKmlAltitudeMode.InnerSingleton, Z_Construct_UEnum_VH_FileIO_Kml_EKmlAltitudeMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EKmlAltitudeMode.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EKmlUnits;
	static UEnum* EKmlUnits_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EKmlUnits.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EKmlUnits.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_FileIO_Kml_EKmlUnits, (UObject*)Z_Construct_UPackage__Script_VH_FileIO_Kml(), TEXT("EKmlUnits"));
		}
		return Z_Registration_Info_UEnum_EKmlUnits.OuterSingleton;
	}
	template<> VH_FILEIO_KML_API UEnum* StaticEnum<EKmlUnits>()
	{
		return EKmlUnits_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_FileIO_Kml_EKmlUnits_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_FileIO_Kml_EKmlUnits_Statics::Enumerators[] = {
		{ "EKmlUnits::Fraction", (int64)EKmlUnits::Fraction },
		{ "EKmlUnits::Pixels", (int64)EKmlUnits::Pixels },
		{ "EKmlUnits::InsetPixels", (int64)EKmlUnits::InsetPixels },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_FileIO_Kml_EKmlUnits_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * (see https://developers.google.com/kml/documentation/kmlreference#hotspot)\n */" },
#endif
		{ "Fraction.Name", "EKmlUnits::Fraction" },
		{ "InsetPixels.Name", "EKmlUnits::InsetPixels" },
		{ "ModuleRelativePath", "Core/Public/VH_KmlTypes.h" },
		{ "Pixels.Name", "EKmlUnits::Pixels" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* (see https://developers.google.com/kml/documentation/kmlreference#hotspot)" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_FileIO_Kml_EKmlUnits_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_FileIO_Kml,
		nullptr,
		"EKmlUnits",
		"EKmlUnits",
		Z_Construct_UEnum_VH_FileIO_Kml_EKmlUnits_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_FileIO_Kml_EKmlUnits_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_FileIO_Kml_EKmlUnits_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_FileIO_Kml_EKmlUnits_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_FileIO_Kml_EKmlUnits()
	{
		if (!Z_Registration_Info_UEnum_EKmlUnits.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EKmlUnits.InnerSingleton, Z_Construct_UEnum_VH_FileIO_Kml_EKmlUnits_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EKmlUnits.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EKmlColorMode;
	static UEnum* EKmlColorMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EKmlColorMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EKmlColorMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_FileIO_Kml_EKmlColorMode, (UObject*)Z_Construct_UPackage__Script_VH_FileIO_Kml(), TEXT("EKmlColorMode"));
		}
		return Z_Registration_Info_UEnum_EKmlColorMode.OuterSingleton;
	}
	template<> VH_FILEIO_KML_API UEnum* StaticEnum<EKmlColorMode>()
	{
		return EKmlColorMode_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_FileIO_Kml_EKmlColorMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_FileIO_Kml_EKmlColorMode_Statics::Enumerators[] = {
		{ "EKmlColorMode::Normal", (int64)EKmlColorMode::Normal },
		{ "EKmlColorMode::Random", (int64)EKmlColorMode::Random },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_FileIO_Kml_EKmlColorMode_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * (see https://developers.google.com/kml/documentation/kmlreference#colorstyle)\n */" },
#endif
		{ "ModuleRelativePath", "Core/Public/VH_KmlTypes.h" },
		{ "Normal.Name", "EKmlColorMode::Normal" },
		{ "Random.Name", "EKmlColorMode::Random" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* (see https://developers.google.com/kml/documentation/kmlreference#colorstyle)" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_FileIO_Kml_EKmlColorMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_FileIO_Kml,
		nullptr,
		"EKmlColorMode",
		"EKmlColorMode",
		Z_Construct_UEnum_VH_FileIO_Kml_EKmlColorMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_FileIO_Kml_EKmlColorMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_FileIO_Kml_EKmlColorMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_FileIO_Kml_EKmlColorMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_FileIO_Kml_EKmlColorMode()
	{
		if (!Z_Registration_Info_UEnum_EKmlColorMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EKmlColorMode.InnerSingleton, Z_Construct_UEnum_VH_FileIO_Kml_EKmlColorMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EKmlColorMode.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EKmlStyleState;
	static UEnum* EKmlStyleState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EKmlStyleState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EKmlStyleState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_FileIO_Kml_EKmlStyleState, (UObject*)Z_Construct_UPackage__Script_VH_FileIO_Kml(), TEXT("EKmlStyleState"));
		}
		return Z_Registration_Info_UEnum_EKmlStyleState.OuterSingleton;
	}
	template<> VH_FILEIO_KML_API UEnum* StaticEnum<EKmlStyleState>()
	{
		return EKmlStyleState_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_FileIO_Kml_EKmlStyleState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_FileIO_Kml_EKmlStyleState_Statics::Enumerators[] = {
		{ "EKmlStyleState::Normal", (int64)EKmlStyleState::Normal },
		{ "EKmlStyleState::Highlight", (int64)EKmlStyleState::Highlight },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_FileIO_Kml_EKmlStyleState_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * (see https://developers.google.com/kml/documentation/kmlreference#kml-fields)\n */" },
#endif
		{ "Highlight.Name", "EKmlStyleState::Highlight" },
		{ "ModuleRelativePath", "Core/Public/VH_KmlTypes.h" },
		{ "Normal.Name", "EKmlStyleState::Normal" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* (see https://developers.google.com/kml/documentation/kmlreference#kml-fields)" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_FileIO_Kml_EKmlStyleState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_FileIO_Kml,
		nullptr,
		"EKmlStyleState",
		"EKmlStyleState",
		Z_Construct_UEnum_VH_FileIO_Kml_EKmlStyleState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_FileIO_Kml_EKmlStyleState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_FileIO_Kml_EKmlStyleState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_FileIO_Kml_EKmlStyleState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_FileIO_Kml_EKmlStyleState()
	{
		if (!Z_Registration_Info_UEnum_EKmlStyleState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EKmlStyleState.InnerSingleton, Z_Construct_UEnum_VH_FileIO_Kml_EKmlStyleState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EKmlStyleState.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EKmlDisplayMode;
	static UEnum* EKmlDisplayMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EKmlDisplayMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EKmlDisplayMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_VH_FileIO_Kml_EKmlDisplayMode, (UObject*)Z_Construct_UPackage__Script_VH_FileIO_Kml(), TEXT("EKmlDisplayMode"));
		}
		return Z_Registration_Info_UEnum_EKmlDisplayMode.OuterSingleton;
	}
	template<> VH_FILEIO_KML_API UEnum* StaticEnum<EKmlDisplayMode>()
	{
		return EKmlDisplayMode_StaticEnum();
	}
	struct Z_Construct_UEnum_VH_FileIO_Kml_EKmlDisplayMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_VH_FileIO_Kml_EKmlDisplayMode_Statics::Enumerators[] = {
		{ "EKmlDisplayMode::Default", (int64)EKmlDisplayMode::Default },
		{ "EKmlDisplayMode::Hide", (int64)EKmlDisplayMode::Hide },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_VH_FileIO_Kml_EKmlDisplayMode_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n * (see https://developers.google.com/kml/documentation/kmlreference#kml-fields)\n */" },
#endif
		{ "Default.Name", "EKmlDisplayMode::Default" },
		{ "Hide.Name", "EKmlDisplayMode::Hide" },
		{ "ModuleRelativePath", "Core/Public/VH_KmlTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* (see https://developers.google.com/kml/documentation/kmlreference#kml-fields)" },
#endif
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_VH_FileIO_Kml_EKmlDisplayMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_VH_FileIO_Kml,
		nullptr,
		"EKmlDisplayMode",
		"EKmlDisplayMode",
		Z_Construct_UEnum_VH_FileIO_Kml_EKmlDisplayMode_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_VH_FileIO_Kml_EKmlDisplayMode_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_VH_FileIO_Kml_EKmlDisplayMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_VH_FileIO_Kml_EKmlDisplayMode_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_VH_FileIO_Kml_EKmlDisplayMode()
	{
		if (!Z_Registration_Info_UEnum_EKmlDisplayMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EKmlDisplayMode.InnerSingleton, Z_Construct_UEnum_VH_FileIO_Kml_EKmlDisplayMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EKmlDisplayMode.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_KML_Core_Public_VH_KmlTypes_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_KML_Core_Public_VH_KmlTypes_h_Statics::EnumInfo[] = {
		{ EKmlElementType_StaticEnum, TEXT("EKmlElementType"), &Z_Registration_Info_UEnum_EKmlElementType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3276733147U) },
		{ EKmlAltitudeMode_StaticEnum, TEXT("EKmlAltitudeMode"), &Z_Registration_Info_UEnum_EKmlAltitudeMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4255910581U) },
		{ EKmlUnits_StaticEnum, TEXT("EKmlUnits"), &Z_Registration_Info_UEnum_EKmlUnits, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2246740537U) },
		{ EKmlColorMode_StaticEnum, TEXT("EKmlColorMode"), &Z_Registration_Info_UEnum_EKmlColorMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 956418992U) },
		{ EKmlStyleState_StaticEnum, TEXT("EKmlStyleState"), &Z_Registration_Info_UEnum_EKmlStyleState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2797339218U) },
		{ EKmlDisplayMode_StaticEnum, TEXT("EKmlDisplayMode"), &Z_Registration_Info_UEnum_EKmlDisplayMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2397223847U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_KML_Core_Public_VH_KmlTypes_h_2661095312(TEXT("/Script/VH_FileIO_Kml"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_KML_Core_Public_VH_KmlTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_FileIO_Source_VH_FileIO_KML_Core_Public_VH_KmlTypes_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
