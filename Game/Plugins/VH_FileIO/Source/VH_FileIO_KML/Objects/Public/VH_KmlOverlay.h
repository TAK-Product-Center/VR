// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlFeature.h"

#include "kml/dom.h"

class FKmlIcon;

// NOTE: Abstract class
class VH_FILEIO_KML_API FKmlOverlay : public FKmlFeature
{
public:
    FKmlOverlay(FKmlElement* parent = nullptr);
    virtual ~FKmlOverlay();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
    // --- Elements ---
    FLinearColor Color;
    int DrawOrder;
    FKmlIcon* Icon;
};
