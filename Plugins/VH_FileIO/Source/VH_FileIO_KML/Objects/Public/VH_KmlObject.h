// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlElement.h"

#include "kml/dom.h"

// NOTE: Abstract class
class VH_FILEIO_KML_API FKmlObject : public FKmlElement
{
public:
    FKmlObject(FKmlElement* parent = nullptr);
    virtual ~FKmlObject();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject);
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
    // --- Attributes ---
    FString ID;
};
