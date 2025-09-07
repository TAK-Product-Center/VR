using UnrealBuildTool;
using System;
using System.IO;

// Modifying file to force Jenkins to rebuild this module
public class assimp : ModuleRules
{
    public assimp(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;

        LoadAssimp(Target);
    }

    public bool LoadAssimp(ReadOnlyTargetRules Target)
    {
        bool IsPlatformSupported = false;
        string PlatformDir = Target.Platform.ToString();

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            IsPlatformSupported = true;

            // get library path 
            string libPath = Path.Combine(ModuleDirectory, "lib");

            // add libs
            PublicAdditionalLibraries.AddRange(new string[]
            {
                Path.Combine(libPath, "assimp-vc143-mt.lib"),
				Path.Combine(libPath, "draco.lib")
            });

            // handle dlls
            string[] dllNames = {
                "assimp-vc143-mt.dll",
		"draco.dll"
			};

            // NOTE: This will auto-copy the dll's to the staged bin path!
            string sdkPath = Path.Combine(ModuleDirectory, "bin");
            foreach (string dllName in dllNames)
            {
				RuntimeDependencies.Add(Path.Combine("$(TargetOutputDir)", dllName), Path.Combine(sdkPath, dllName), StagedFileType.NonUFS);
            }
        }

		if (IsPlatformSupported)
        {
            //add include paths
            PublicIncludePaths.AddRange(new string[] {
				// ... add public include paths required here ...
				Path.Combine(ModuleDirectory, "include"),
			});
        }

        PublicDefinitions.Add(String.Format("WITH_FILEIO_ASSIMP={0}", IsPlatformSupported ? "1" : "0"));
        return IsPlatformSupported;
    }

}

