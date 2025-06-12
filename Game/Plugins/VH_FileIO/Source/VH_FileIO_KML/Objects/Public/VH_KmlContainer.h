// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlFeature.h"

#include "kml/dom.h"

class FKmlFeature;

// NOTE: Abstract class
class VH_FILEIO_KML_API FKmlContainer : public FKmlFeature
{
public:
    FKmlContainer(FKmlElement* parent = nullptr);
    virtual ~FKmlContainer();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

    bool AddFeature(const kmldom::FeaturePtr kmlFeature);
    int32 GetAllFeatures(TArray<FKmlFeature*>& featureList, EKmlElementType type, bool bRecursive = true);

public:
    // --- Elements ---
    TMap<EKmlElementType, TArray<FKmlFeature*>> FeatureListMap;
};
