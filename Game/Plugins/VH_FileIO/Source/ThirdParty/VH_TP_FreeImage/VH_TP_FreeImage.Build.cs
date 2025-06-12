using UnrealBuildTool;
using System;
using System.IO;

public class VH_TP_FreeImage : ModuleRules
{
    public VH_TP_FreeImage(ReadOnlyTargetRules target) : base(target)
    {
        Type = ModuleType.External;

        LoadFreeImage(target);
    }

    public bool LoadFreeImage(ReadOnlyTargetRules target)
    {
        bool isLibrarySupported = false;

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            isLibrarySupported = true;

			// get library path 
			string libPath = Path.Combine(ModuleDirectory, "Dist", "x64");

			//add include paths
			PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "Dist", "x64") });

            // add libs
            PublicAdditionalLibraries.AddRange(new string[]
            {
                Path.Combine(libPath, "FreeImage.lib")
            });

            // handle dlls
            string[] dllNames = {
                "FreeImage.dll"
            };

            // NOTE: This will auto-copy the dll's to the staged bin path!
            string sdkPath = Path.Combine(ModuleDirectory, "Dist", "x64");
            foreach (string dllName in dllNames)
            {
                RuntimeDependencies.Add(Path.Combine("$(TargetOutputDir)", dllName), Path.Combine(sdkPath, dllName), StagedFileType.NonUFS);
            }
        }

        PublicDefinitions.Add(string.Format("WITH_FILEIO_FREEIMAGE={0}", (isLibrarySupported ? 1 : 0)));
        return isLibrarySupported;
    }
}
