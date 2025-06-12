// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(VH_GlobeMath, Warning, All);

class FVH_GlobeMathModule : public IModuleInterface
{
public:
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};