// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlContainer.h"

#include "kml/dom.h"

class FKmlStyle;
class FKmlStyleMap;

class VH_FILEIO_KML_API FKmlDocument : public FKmlContainer
{
public:
    FKmlDocument(FKmlElement* parent = nullptr);
    virtual ~FKmlDocument();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

    virtual const FKmlStyle* FindStyle(FString& styleID, EKmlStyleState styleState = EKmlStyleState::Normal) const override;

protected:
    const FKmlStyle* FindSharedStyle(FString& styleID, EKmlStyleState styleState = EKmlStyleState::Normal) const;
    bool AddStyleSelector(const kmldom::StyleSelectorPtr kmlStyleSelector);

public:
    // --- Elements ---
    TMap<FString, FKmlStyle*> StylesMap;
    TMap<FString, FKmlStyleMap*> StyleMapsMap;
};
