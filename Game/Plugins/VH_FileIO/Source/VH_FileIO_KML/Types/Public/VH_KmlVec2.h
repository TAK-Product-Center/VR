// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlElement.h"

#include "kml/dom.h"

// NOTE: Abstract class
// NOTE: See https://developers.google.com/kml/documentation/kmlreference#kml-fields for more info on KML data types.
class VH_FILEIO_KML_API FKmlVec2 : public FKmlElement
{
public:
    FKmlVec2(FKmlElement* parent = nullptr);
    virtual ~FKmlVec2();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::Vec2Ptr kmlVec2);
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
    // --- Attributes ---
    double X;
    double Y;
    EKmlUnits XUnits;
    EKmlUnits YUnits;
};
