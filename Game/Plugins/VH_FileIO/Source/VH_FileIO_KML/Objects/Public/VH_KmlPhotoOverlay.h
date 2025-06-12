// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlOverlay.h"

#include "kml/dom.h"

class FKmlCamera;
class FKmlLookAt;
class FKmlViewVolume;
class FKmlPoint;

class VH_FILEIO_KML_API FKmlPhotoOverlay : public FKmlOverlay
{
public:
    FKmlPhotoOverlay(FKmlElement* parent = nullptr);
    virtual ~FKmlPhotoOverlay();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
    // --- Elements ---
    // <type?> Rotation;
    FString StyleUrl;
    FKmlCamera* Camera;  // NOTE: Either Camera or LookAt, so maybe just replace with AbstractView (parent of both)?
    FKmlLookAt* LookAt;
    FKmlViewVolume* ViewVolume;
    FKmlPoint* Point;
};
