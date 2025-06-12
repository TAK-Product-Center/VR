// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlGeometry.h"

#include "kml/dom.h"

class FKmlGeometry;

class VH_FILEIO_KML_API FKmlMultiGeometry : public FKmlGeometry
{
public:
    FKmlMultiGeometry(FKmlElement* parent = nullptr);
    virtual ~FKmlMultiGeometry();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

    bool AddGeometry(const kmldom::GeometryPtr kmlGeometry);

public:
    // --- Elements ---
    TMap<EKmlElementType, TArray<FKmlGeometry*>> GeometryListMap;
};
