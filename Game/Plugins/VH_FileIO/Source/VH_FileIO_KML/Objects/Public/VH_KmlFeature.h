// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"
#include "VH_KmlObject.h"

#include "kml/dom.h"

class FKmlStyle;
class FKmlLookAt;
class FKmlStyleSelector;
class FKmlExtendedData;

// NOTE: Abstract class
class VH_FILEIO_KML_API FKmlFeature : public FKmlObject
{
public:
    FKmlFeature(FKmlElement* parent = nullptr);
    virtual ~FKmlFeature();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

    virtual const FKmlStyle* FindStyle(FString& styleID, EKmlStyleState styleState = EKmlStyleState::Normal) const override;
    virtual const FKmlStyle* GetStyle(EKmlStyleState styleState = EKmlStyleState::Normal) const;

public:
    // --- Elements ---
    FString Name;
    bool IsOpen;
    bool IsVisible;
    FString Address;
    //FString AddressDetails;		// NOTE: This is a structure. See xAL (eXtensible Address Language) at https://www.oasis-open.org/committees/ciq/ciq.html#6
    FString PhoneNumber;
    FString Snippet;  // TODO: Since this can have attributes (e.g. maxLines), this should probably be its own struct!
    FString Description;
    FKmlLookAt* LookAt;
    FString StyleUrl;
    FKmlStyleSelector* StyleSelector;
    //FKmlRegion* Region;
    FKmlExtendedData* ExtendedData;  // NOTE: This replaced <MetaData> tag starting in KML 2.2 spec

	// --- Internal ---
	// TODO: Cache 3D geodetic extents after parsing itself and its sub-hierarchy!  This includes folders, etc.
	//FGeoExtents GeoExtents;
};
