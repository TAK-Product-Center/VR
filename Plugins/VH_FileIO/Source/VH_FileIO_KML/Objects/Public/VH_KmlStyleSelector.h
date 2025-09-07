// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlObject.h"

#include "kml/dom.h"

// NOTE: Abstract class
class VH_FILEIO_KML_API FKmlStyleSelector : public FKmlObject
{
public:
    FKmlStyleSelector(FKmlElement* parent = nullptr);
    virtual ~FKmlStyleSelector();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const;

public:
    // --- Elements ---
};
