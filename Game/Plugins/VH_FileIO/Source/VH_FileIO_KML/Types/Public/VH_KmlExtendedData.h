// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlElement.h"

#include "kml/dom.h"

class FKmlData;

// NOTE: ExtendedData is not a KML object subclass!
class VH_FILEIO_KML_API FKmlExtendedData : public FKmlElement
{
public:
    FKmlExtendedData(FKmlElement* parent = nullptr);
    virtual ~FKmlExtendedData();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ExtendedDataPtr kmlObject);
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
    // --- Elements ---
    TMap<FString, FKmlData*> DataMap;
};
