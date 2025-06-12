// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_KmlTypes.h"

class FKmlStyle;

// NOTE: Abstract class
class VH_FILEIO_KML_API FKmlElement
{
public:
    FKmlElement(FKmlElement* parent = nullptr);
    virtual ~FKmlElement();

    virtual EKmlElementType GetType() const;
    virtual bool IsA(EKmlElementType searchType) const;
    FKmlElement* FindParentElementOfType(EKmlElementType searchType) const;

    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const;

    virtual const FKmlStyle* FindStyle(FString& styleID, EKmlStyleState styleState = EKmlStyleState::Normal) const;

	/* Returns TRUE if this KmlElement has an AltitudeMode. */
	virtual bool HasAltitudeMode() const;

	/* Returns this KmlElement's AltitudeMode, if available. Otherwise, it returns the closest ancestor with a valid AltitudeMode. */
	virtual EKmlAltitudeMode GetAltitudeMode() const;

public:
    // --- Internal ---
    FKmlElement* ParentNode;
    TArray<FKmlElement*> ChildNodeList;
};
