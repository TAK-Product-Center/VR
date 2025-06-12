// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlColorStyle.h"

#include "kml/dom.h"

class VH_FILEIO_KML_API FKmlBalloonStyle : public FKmlColorStyle
{
public:
    FKmlBalloonStyle(FKmlElement* parent = nullptr);
    virtual ~FKmlBalloonStyle();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
    // --- Elements ---
    FLinearColor BGColor;
    FLinearColor TextColor;
    FString Text;
    EKmlDisplayMode DisplayMode;
};
