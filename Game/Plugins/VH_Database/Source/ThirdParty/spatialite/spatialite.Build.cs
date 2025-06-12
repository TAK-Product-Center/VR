using UnrealBuildTool;
using System;
using System.IO;
using System.Collections.Generic;

public class spatialite : ModuleRules
{
    public spatialite(ReadOnlyTargetRules target) : base(target)
    {
        Type = ModuleType.External;

        LoadSpatialite(target);
    }

    public bool LoadSpatialite(ReadOnlyTargetRules target)
    {
        bool isLibrarySupported = false;

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            isLibrarySupported = true;

            // get library path 
			string libPath = Path.Combine(ModuleDirectory, "lib/x64/release");
        
			//add include paths
			PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "include") });

			// add library path 
			PublicAdditionalLibraries.Add(Path.Combine(libPath, "freexl.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(libPath, "geos.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(libPath, "libiconv.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(libPath, "libxml2.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(libPath, "proj.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(libPath, "proj_i.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(libPath, "sqlite.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(libPath, "spatialite.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(libPath, "spatialite_i.lib"));
            PublicAdditionalLibraries.Add(Path.Combine(libPath, "zlibstatic.lib"));

            // handle dlls
            string[] dllNames = {
                "freexl.dll",
                "geos.dll",
                "geos_cpp.dll",
                "libiconv.dll",     
                "libxml2.dll",
                "proj.dll",
                "spatialite.dll",
                //"sqlite3.dll",
                "zlib1.dll",		
            };

            // NOTE: This will auto-copy the dll's to the staged bin path!
            string sdkPath = Path.Combine(ModuleDirectory, "bin", "x64", "release");
			foreach (string dllName in dllNames)
			{
                RuntimeDependencies.Add(Path.Combine("$(TargetOutputDir)", dllName), Path.Combine(sdkPath, dllName), StagedFileType.NonUFS);
            }
		}

		return isLibrarySupported;
    }
}
