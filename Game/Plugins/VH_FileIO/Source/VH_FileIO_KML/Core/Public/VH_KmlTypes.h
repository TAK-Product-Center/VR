// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.generated.h"

// clang-format off
UENUM(BlueprintType)
enum class EKmlElementType : uint8
{
	Element,				// Element
	Object,					// -- Object

	Feature,				// ---- Feature

	Container,				// ------ Container
	Folder,					// -------- Folder
	Document,				// -------- Document

	NetworkLink,			// ------ NetworkLink

	Overlay,				// ------ Overlay
	GroundOverlay,			// -------- GroundOverlay
	PhotoOverlay,			// -------- PhotoOverlay
	ScreenOverlay,			// -------- ScreenOverlay

	Placemark,				// ------ Placemark

	Geometry,				// ---- Geometry
	LinearRing,				// ------ LinearRing
	LineString,				// ------ LineString
	MultiGeometry,			// ------ MultiGeometry
	Model,					// ------ Model
	Point,					// ------ Point
	Polygon,				// ------ Polygon

	ColorStyle,				// ---- ColorStyle
	BalloonStyle,			// ------ BalloonStyle
	LabelStyle,				// ------ LabelStyle
	LineStyle,				// ------ LineStyle
	IconStyle,				// ------ IconStyle
	PolyStyle,				// ------ PolyStyle

	Data,					// ---- Data
	ViewVolume,				// ---- ViewVolume
	Icon,					// ---- Icon
	IconStyleIcon,			// ---- IconStyleIcon
	GxLatLonQuad,			// ---- GxLatLonQuad
	LatLonBox,				// ---- LatLonBox

	// TODO: Add AbstractView
	Camera,					// ---- Camera
	LookAt,					// ---- LookAt

	StyleSelector,			// -- StyleSelector
	Style,					// ---- Style
	StyleMap,				// ---- StyleMap

	Coordinates,			// -- Coordinates
	ExtendedData,			// -- ExtendedData

	Vec2,					// -- Vec2
    HotSpot,				// ---- HotSpot

};
// clang-format on

/*
 * NOTE: Normal AltitudeMode contains ClampToGround, RelativeToGround, and Absolute (relative to sea level).
 *		 gx:AltitudeMode contains RelativeToSeaFloor and ClampToSeaFloor. This enum includes all values.
 */
UENUM(BlueprintType)
enum class EKmlAltitudeMode : uint8
{
    ClampToGround,
    RelativeToGround,
    Absolute,  // NOTE: Relative to sea level
    RelativeToSeaFloor,
    ClampToSeaFloor,
};

/*
 * (see https://developers.google.com/kml/documentation/kmlreference#hotspot)
 */
UENUM(BlueprintType)
enum class EKmlUnits : uint8
{
    Fraction,
    Pixels,
    InsetPixels,
};

/*
 * (see https://developers.google.com/kml/documentation/kmlreference#colorstyle)
 */
UENUM(BlueprintType)
enum class EKmlColorMode : uint8
{
    Normal,
    Random,
};

/*
 * (see https://developers.google.com/kml/documentation/kmlreference#kml-fields)
 */
UENUM(BlueprintType)
enum class EKmlStyleState : uint8
{
    Normal,
    Highlight,
};

/*
 * (see https://developers.google.com/kml/documentation/kmlreference#kml-fields)
 */
UENUM(BlueprintType)
enum class EKmlDisplayMode : uint8
{
    Default,
    Hide,
};
