// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlObject.h"

#include "kml/dom.h"

// NOTE: This should derive from AbstractLink (which derives from BasicLink), but kmldom::AsBasicLink() doesn't exist! So for now, we're skipping those base classes until we need them.
class VH_FILEIO_KML_API FKmlIcon : public FKmlObject
{
public:
    FKmlIcon(FKmlElement* parent = nullptr);
    virtual ~FKmlIcon();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
    // --- Elements ---
    FString HRef;
    double ViewBoundScale;
};
