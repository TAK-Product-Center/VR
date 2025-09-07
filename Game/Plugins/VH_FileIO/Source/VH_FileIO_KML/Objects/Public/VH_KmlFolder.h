// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlContainer.h"

#include "kml/dom.h"

class VH_FILEIO_KML_API FKmlFolder : public FKmlContainer
{
public:
    FKmlFolder(FKmlElement* parent = nullptr);
    virtual ~FKmlFolder();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

public:
    // --- Elements ---
};
