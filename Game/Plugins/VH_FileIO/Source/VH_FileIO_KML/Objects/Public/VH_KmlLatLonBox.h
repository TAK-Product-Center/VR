// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlObject.h"

#include "kml/dom.h"

#include "Math/Box2D.h"

class VH_FILEIO_KML_API FKmlLatLonBox : public FKmlObject
{
public:
    FKmlLatLonBox(FKmlElement* parent = nullptr);
    virtual ~FKmlLatLonBox();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const;

public:
    // --- Elements ---
    double North;
    double South;
    double West;
    double East;
    double Rotation;

    // --- Internal ---
    FBox2D UnrotatedBBox;
};
