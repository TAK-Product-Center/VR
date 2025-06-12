#include "VH_COT.h"
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "IVH_COT.h"
#include "Misc/Paths.h"

class FVH_COT : public IVH_COT
{
public:
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

private:
    TArray<void*> DllHandles;

    void LoadDlls(const FString& dllPath, const TArray<FString>& dllNames, TArray<void*>& dllHandles);
};

IMPLEMENT_MODULE(FVH_COT, VH_COT)

DEFINE_LOG_CATEGORY(VH_COT);

void FVH_COT::StartupModule()
{
    // This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)

	// TODO: For now, the delay-loading of these dll's is disabled.  If we find that we don't ever need this for hot-reloading or dyanmic
	//		 toggling of these plugins, then we can remove this entirely!
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
    {
        // load Commo dlls
        FString dllPath = FPaths::ProjectPluginsDir() / TEXT("VH_COT/Source/ThirdParty/Commo/bin/x64/release");

        TArray<FString> dllNames;
        //dllNames.Add(TEXT("libcrypto-1_1-x64.dll"));
        //dllNames.Add(TEXT("libcurl.dll"));
        //dllNames.Add(TEXT("libmicrohttpd-dll.dll"));
        //dllNames.Add(TEXT("libssl-1_1-x64.dll"));
        //dllNames.Add(TEXT("libxml2.dll"));
        //dllNames.Add(TEXT("pgscthread.dll"));
        //dllNames.Add(TEXT("commoncommo.dll"));

        LoadDlls(dllPath, dllNames, DllHandles);
        dllNames.Empty();
    }

	{
		// load Gv2F dlls
		FString dllPath = FPaths::ProjectPluginsDir() / TEXT("VH_COT/Source/ThirdParty/Gv2F/bin/x64/release");

		TArray<FString> dllNames;

		//dllNames.Add(TEXT("libwinpthread-1.dll"));
		//dllNames.Add(TEXT("avutilpgsc.dll"));
		//dllNames.Add(TEXT("avcodecpgsc.dll"));
		//dllNames.Add(TEXT("avformatpgsc.dll"));
		//dllNames.Add(TEXT("avdevicepgsc.dll"));
		//dllNames.Add(TEXT("swresamplepgsc.dll"));
		//dllNames.Add(TEXT("swscalepgsc.dll"));
		//dllNames.Add(TEXT("avfilterpgsc.dll"));
		//dllNames.Add(TEXT("libgcc_s_sjlj-1.dll"));
		//dllNames.Add(TEXT("libstdc++-6.dll"));
		//dllNames.Add(TEXT("license.dll"));
		//dllNames.Add(TEXT("avvideopgsc.dll"));
		//dllNames.Add(TEXT("libssp-0.dll"));
		//dllNames.Add(TEXT("pgscmedia.dll"));

		LoadDlls(dllPath, dllNames, DllHandles);
		dllNames.Empty();
	}

#endif
}

void FVH_COT::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.

    for (auto dllHandle : DllHandles)
    {
        FPlatformProcess::FreeDllHandle(dllHandle);
    }
}

void FVH_COT::LoadDlls(const FString& dllPath, const TArray<FString>& dllNames, TArray<void*>& dllHandles)
{
    for (const auto dllName : dllNames)
    {
        auto dllHandle = FPlatformProcess::GetDllHandle(*(dllPath / dllName));
        if (dllHandle == NULL)
        {
            UE_LOG(VH_COT, Warning, TEXT("-- could not load dll: %s"), *(dllPath / dllName));
            continue;
        }

        dllHandles.Add(dllHandle);
    }
}
