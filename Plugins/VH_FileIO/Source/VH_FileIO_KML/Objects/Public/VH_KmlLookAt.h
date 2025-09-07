// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlObject.h"

#include "VH_GeodeticCoord.h"

#include "kml/dom.h"

class VH_FILEIO_KML_API FKmlLookAt : public FKmlObject
{
public:
    FKmlLookAt(FKmlElement* parent = nullptr);
    virtual ~FKmlLookAt();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

	virtual bool HasAltitudeMode() const override { return true; }
	virtual EKmlAltitudeMode GetAltitudeMode() const override { return AltitudeMode; }

public:
    // --- Elements ---
    FGeodeticCoord3D Location;
    EKmlAltitudeMode AltitudeMode;
    FRotator Rotation;
    double Range;

    // --- Internal ---
    bool IsGxAltitudeMode;
};
