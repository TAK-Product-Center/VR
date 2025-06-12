using UnrealBuildTool;
using System;
using System.IO;
using System.Collections.Generic;

public class mySQL : ModuleRules
{
    public mySQL(ReadOnlyTargetRules target) : base(target)
    {
        Type = ModuleType.External;

		LoadMySQL(target);
    }

    public bool LoadMySQL(ReadOnlyTargetRules target)
    {
        bool isLibrarySupported = false;

		if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            isLibrarySupported = true;

            // get library path 
			string libPath = Path.Combine(ModuleDirectory, "lib/x64");
        
			//add include paths
			PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "include") });

			// add library path 
			PublicAdditionalLibraries.Add(Path.Combine(libPath, "mysqlcppconn.lib"));

            // handle dlls
            string[] dllNames = {
                "libmysql.dll",
                "mysqlcppconn.dll",
            };

            // NOTE: This will auto-copy the dll's to the staged bin path!
            string sdkPath = Path.Combine(ModuleDirectory, "bin", "x64");
			foreach (string dllName in dllNames)
			{
                RuntimeDependencies.Add(Path.Combine("$(TargetOutputDir)", dllName), Path.Combine(sdkPath, dllName), StagedFileType.NonUFS);
            }
		}

		return isLibrarySupported;
    }
}
