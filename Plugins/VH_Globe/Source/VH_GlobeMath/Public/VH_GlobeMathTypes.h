// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "VH_GlobeMathTypes.generated.h"

/*
 *
 */
UENUM(BlueprintType)
enum class EGeoLocationType : uint8
{
    Geodetic,
    MGRS,
    UTM,
};
