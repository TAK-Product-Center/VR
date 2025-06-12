// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlFeature.h"

#include "kml/dom.h"

class VH_FILEIO_KML_API FKmlNetworkLink : public FKmlFeature
{
public:
    FKmlNetworkLink(FKmlElement* parent = nullptr);
    virtual ~FKmlNetworkLink();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const;

public:
    // --- Elements ---
	bool IsRefreshVisibility;
	bool IsFlyToView;
	FString Link;  // TODO: Should be a FKml* struct/class
};
