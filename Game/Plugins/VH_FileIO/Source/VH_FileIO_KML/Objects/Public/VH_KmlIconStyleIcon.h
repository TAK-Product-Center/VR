// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlObject.h"

#include "kml/dom.h"

// NOTE: Normally this class would derive from a new FKmlBasicLink class for the 'HRef', but since there is no kmldom::AsBasicLink(),
//		 this class must instead just handle its own 'HRef' member.
class VH_FILEIO_KML_API FKmlIconStyleIcon : public FKmlObject
{
public:
    FKmlIconStyleIcon(FKmlElement* parent = nullptr);
    virtual ~FKmlIconStyleIcon();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
    // --- Elements ---
    FString HRef;
    double gxX;
    double gxY;
    double gxW;
    double gxH;
};
