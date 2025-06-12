using UnrealBuildTool;
using System;
using System.IO;
using System.Collections.Generic;

public class libVLC : ModuleRules
{
    public libVLC(ReadOnlyTargetRules target) : base(target)
    {
        Type = ModuleType.External;

        LoadLibVLC(target);
    }

    public bool LoadLibVLC(ReadOnlyTargetRules target)
    {
        bool isLibrarySupported = false;

        if (target.Platform == UnrealTargetPlatform.Win64)
        {
            isLibrarySupported = true;

            string libPath = Path.Combine(ModuleDirectory, "lib");

            //add include paths
            PublicIncludePaths.AddRange(new string[]
            {
                Path.Combine(ModuleDirectory, "include"),
            });

            // add libs
            PublicAdditionalLibraries.AddRange(new string[]
            {
                Path.Combine(libPath, "libvlc.lib"),
                Path.Combine(libPath, "libvlccore.lib")
                //Path.Combine(libPath, "vlc.lib")
                //Path.Combine(libPath, "vlccore.lib")
            });

			// handle dlls
			string[] dllNames = 
            {
				"libvlc.dll",
				"libvlccore.dll"
			};

            string sdkPath = Path.Combine(ModuleDirectory, "bin");
            foreach (string dllName in dllNames)
            {
                RuntimeDependencies.Add(Path.Combine("$(TargetOutputDir)", dllName), Path.Combine(sdkPath, dllName), StagedFileType.NonUFS);
            }

            // copy plugins directory
            string pluginsPath = Path.Combine(ModuleDirectory, "plugins/...");
            RuntimeDependencies.Add(Path.Combine("$(TargetOutputDir)", "plugins"), pluginsPath, StagedFileType.NonUFS);
        }

		return isLibrarySupported;
    }
}
