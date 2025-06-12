// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlStyleSelector.h"
#include "VH_KmlTypes.h"

#include "kml/dom.h"

class FKmlStyle;

class VH_FILEIO_KML_API FKmlStyleMap : public FKmlStyleSelector
{
public:
    FKmlStyleMap(FKmlElement* parent = nullptr);
    virtual ~FKmlStyleMap();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

    // NOTE: 'styleID' might be changed here
    virtual const FKmlStyle* FindStyle(FString& styleID, EKmlStyleState styleState = EKmlStyleState::Normal) const override;

public:
    // --- Elements ---
    TMap<EKmlStyleState, FString> StyleUrlMap;
    TMap<EKmlStyleState, FKmlStyle*> InlineStylesMap;
};
