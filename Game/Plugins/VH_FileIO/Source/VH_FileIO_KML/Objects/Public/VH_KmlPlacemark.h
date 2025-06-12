// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlFeature.h"

#include "kml/dom.h"

class FKmlCamera;
class FKmlGeometry;

class VH_FILEIO_KML_API FKmlPlacemark : public FKmlFeature
{
public:
    FKmlPlacemark(FKmlElement* parent = nullptr);
    virtual ~FKmlPlacemark();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
    // --- Elements ---
    FKmlCamera* Camera;
    FKmlGeometry* Geometry;
};
