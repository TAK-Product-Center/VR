// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlVec2.h"

#include "kml/dom.h"

class VH_FILEIO_KML_API FKmlHotSpot : public FKmlVec2
{
public:
    FKmlHotSpot(FKmlElement* parent = nullptr);
    virtual ~FKmlHotSpot();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::Vec2Ptr kmlVec2) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
};
