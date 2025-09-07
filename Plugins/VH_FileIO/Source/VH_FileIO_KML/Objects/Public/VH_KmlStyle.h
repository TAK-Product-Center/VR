// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlStyleSelector.h"

#include "kml/dom.h"

class FKmlBalloonStyle;
class FKmlIconStyle;
class FKmlLabelStyle;
class FKmlLineStyle;
class FKmlPolyStyle;

class VH_FILEIO_KML_API FKmlStyle : public FKmlStyleSelector
{
public:
    FKmlStyle(FKmlElement* parent = nullptr);
    virtual ~FKmlStyle();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
    // --- Elements ---
    // NOTE: For now, this omits ListStyle, since it only affects how the item is displayed in GoogleEarth's list view.  But it can be implemented here if we need to display that info (or to export kml).
    FKmlBalloonStyle* BalloonStyle;
    FKmlIconStyle* IconStyle;
    FKmlLabelStyle* LabelStyle;
    FKmlLineStyle* LineStyle;
    FKmlPolyStyle* PolyStyle;
};
