// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlColorStyle.h"

#include "kml/dom.h"

class FKmlIconStyleIcon;
class FKmlHotSpot;

class VH_FILEIO_KML_API FKmlIconStyle : public FKmlColorStyle
{
public:
    FKmlIconStyle(FKmlElement* parent = nullptr);
    virtual ~FKmlIconStyle();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
    // --- Elements ---
    double Scale;
    double Heading;  // 0-360
    FKmlIconStyleIcon* Icon;
    FKmlHotSpot* HotSpot;
};
