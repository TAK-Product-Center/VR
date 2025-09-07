// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlGeometry.h"

#include "kml/dom.h"

class FKmlLinearRing;

class VH_FILEIO_KML_API FKmlPolygon : public FKmlGeometry
{
public:
    FKmlPolygon(FKmlElement* parent = nullptr);
    virtual ~FKmlPolygon();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const;

public:
    // --- Elements ---
    FKmlLinearRing* OuterBoundary;
    TArray<FKmlLinearRing*> InnerBoundaryList;
};
