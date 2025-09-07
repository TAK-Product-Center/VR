// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlOverlay.h"

#include "kml/dom.h"

class FKmlLatLonBox;
class FKmlGxLatLonQuad;

class VH_FILEIO_KML_API FKmlGroundOverlay : public FKmlOverlay
{
public:
    FKmlGroundOverlay(FKmlElement* parent = nullptr);
    virtual ~FKmlGroundOverlay();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

	virtual bool HasAltitudeMode() const override { return true; }
	virtual EKmlAltitudeMode GetAltitudeMode() const override { return AltitudeMode; }

public:
    // --- Elements ---
    EKmlAltitudeMode AltitudeMode;
    double Altitude;
    FKmlLatLonBox* LatLonBox;
    FKmlGxLatLonQuad* GxLatLonQuad;
};
