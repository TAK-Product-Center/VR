// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlObject.h"

#include "kml/dom.h"

// NOTE: Abstract class
// See https://developers.google.com/kml/documentation/kmlreference#colorstyle
class VH_FILEIO_KML_API FKmlColorStyle : public FKmlObject
{
public:
    FKmlColorStyle(FKmlElement* parent = nullptr);
    virtual ~FKmlColorStyle();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
    // --- Elements ---
    FLinearColor Color;
    EKmlColorMode ColorMode;

    // --- Internal ---
    FLinearColor ColorRandomSource;
};
