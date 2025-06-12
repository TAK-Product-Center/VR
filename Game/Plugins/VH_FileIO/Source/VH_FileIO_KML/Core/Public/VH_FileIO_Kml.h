#pragma once

#include "Engine.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(VH_FileIO_Kml, Warning, All);

class FVH_FileIO_KmlModule : public IModuleInterface
{
public:
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

private:
    TArray<void*> DllHandles;

    virtual void LoadDlls(const FString& dllPath, const TArray<FString>& dllNames, TArray<void*>& dllHandles);
};
