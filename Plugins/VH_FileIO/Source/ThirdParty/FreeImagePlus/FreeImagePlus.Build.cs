using UnrealBuildTool;
using System;
using System.IO;

public class FreeImagePlus : ModuleRules
{
    public FreeImagePlus(ReadOnlyTargetRules target) : base(target)
    {
        Type = ModuleType.External;

        LoadFreeImagePlus(target);
    }

    public bool LoadFreeImagePlus(ReadOnlyTargetRules target)
    {
        bool isLibrarySupported = false;

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            isLibrarySupported = true;

            // get library path 
			string libPath = Path.Combine(ModuleDirectory, "dist", "x64");

			//add include paths
			PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "dist", "x64") });

            // add libs
            PublicAdditionalLibraries.AddRange(new string[]
            {
                Path.Combine(libPath, "FreeImagePlus.lib")
            });

            // handle dlls
            string[] dllNames = {
                "FreeImagePlus.dll"
            };

            // NOTE: This will auto-copy the dll's to the staged bin path!
            string sdkPath = Path.Combine(ModuleDirectory, "dist", "x64");
            foreach (string dllName in dllNames)
            {
	            RuntimeDependencies.Add(Path.Combine("$(TargetOutputDir)", dllName), Path.Combine(sdkPath, dllName), StagedFileType.NonUFS);
			}
        }

        PublicDefinitions.Add(string.Format("WITH_FILEIO_FREEIMAGEPLUS={0}", (isLibrarySupported ? 1 : 0)));
        return isLibrarySupported;
    }
}
