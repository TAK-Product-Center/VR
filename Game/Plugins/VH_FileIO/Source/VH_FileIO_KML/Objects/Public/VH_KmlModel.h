// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlGeometry.h"

#include "VH_GeodeticCoord.h"

#include "kml/dom.h"

class VH_FILEIO_KML_API FKmlModel : public FKmlGeometry
{
public:
    FKmlModel(FKmlElement* parent = nullptr);
    virtual ~FKmlModel();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const;

public:
    // --- Elements ---
    FGeodeticCoord3D Location;
    FRotator Rotation;
    FVector Scale;
    FString Link;  // TODO: Should be a FKml* struct/class
    TMap<FString, FString> ResourceMap;

	bool bHasLocationTag;
	bool bHasScaleTag;
};
