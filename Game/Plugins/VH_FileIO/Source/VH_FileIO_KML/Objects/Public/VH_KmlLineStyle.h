// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlColorStyle.h"

#include "kml/dom.h"

// See https://developers.google.com/kml/documentation/kmlreference#linestyle
class VH_FILEIO_KML_API FKmlLineStyle : public FKmlColorStyle
{
public:
    FKmlLineStyle(FKmlElement* parent = nullptr);
    virtual ~FKmlLineStyle();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
    // --- Elements ---
    double Width;

    // TODO: These are not yet implemented/accessible in libkml.  Implement them here once we can!
    /*
    FLinearColor gxOuterColor;
    float gxOuterWidth;
    float gxPhysicalWidth;
    bool gxLabelVisibility;
	*/
};
