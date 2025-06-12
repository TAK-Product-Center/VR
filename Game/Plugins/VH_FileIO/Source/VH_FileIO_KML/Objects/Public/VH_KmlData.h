// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlObject.h"

#include "kml/dom.h"

class VH_FILEIO_KML_API FKmlData : public FKmlObject
{
public:
    FKmlData(FKmlElement* parent = nullptr);
    virtual ~FKmlData();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
    // --- Attributes ---
    FString Name;

    // --- Elements ---
    FString DisplayName;
    FString Value;
};
