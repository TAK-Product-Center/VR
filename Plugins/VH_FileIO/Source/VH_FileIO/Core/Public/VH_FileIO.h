#pragma once

#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(VH_FileIO, Warning, All);

class FVH_FileIOModule : public IModuleInterface
{
public:
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

private:
    TArray<void*> DllHandles;

    virtual void LoadDlls(const FString& dllPath, const TArray<FString>& dllNames, TArray<void*>& dllHandles);
};
