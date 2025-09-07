// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlGeometry.h"

#include "kml/dom.h"

class FKmlCoordinates;

class VH_FILEIO_KML_API FKmlLinearRing : public FKmlGeometry
{
public:
    FKmlLinearRing(FKmlElement* parent = nullptr);
    virtual ~FKmlLinearRing();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const;

public:
    // --- Elements ---
    FKmlCoordinates* Coordinates;
};
