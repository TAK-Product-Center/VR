// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlElement.h"

#include "VH_GeodeticCoord.h"

#include "kml/dom.h"

// NOTE: Coordinates is not a kml Object subclass!
class VH_FILEIO_KML_API FKmlCoordinates : public FKmlElement
{
public:
    FKmlCoordinates(FKmlElement* parent = nullptr);
    virtual ~FKmlCoordinates();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::CoordinatesPtr kmlCoordinates);
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
    // --- Elements ---
    TArray<FGeodeticCoord3D> CoordinateList;
};
