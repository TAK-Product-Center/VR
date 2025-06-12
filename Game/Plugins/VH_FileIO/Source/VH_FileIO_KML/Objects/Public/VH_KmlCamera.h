#pragma once

// Parent Includes
#include "VH_KmlObject.h"

// Engine Includes
#include "Misc/DateTime.h"

// VH Plugin Includes
#include "VH_GeodeticCoord.h"

// Module Includes
#include "VH_KmlTypes.h"

#include "kml/dom.h"

class VH_FILEIO_KML_API FKmlCamera : public FKmlObject
{
public:
    FKmlCamera(FKmlElement* parent = nullptr);
    virtual ~FKmlCamera();

    virtual EKmlElementType GetType() const override;
    virtual bool IsA(EKmlElementType searchType) const override;

    virtual bool ParseKml(const kmldom::ObjectPtr kmlObject) override;
    virtual void LogDump(FString& LogDumpIndent, const FString& LogDumpIndentInc) const override;

	virtual bool HasAltitudeMode() const override { return true; }
	virtual EKmlAltitudeMode GetAltitudeMode() const override { return AltitudeMode; }

public:
    // --- Elements ---
    FGeodeticCoord3D Location;
    EKmlAltitudeMode AltitudeMode;
    FRotator Rotation;
    FDateTime TimeStamp;

    // --- Internal ---
    bool IsGxAltitudeMode;
};
