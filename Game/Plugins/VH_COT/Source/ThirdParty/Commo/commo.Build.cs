using UnrealBuildTool;
using System.IO;

public class commo : ModuleRules
{
    public commo(ReadOnlyTargetRules target) : base(target)
    {
        Type = ModuleType.External;

        LoadCommo(target);
    }

    public bool LoadCommo(ReadOnlyTargetRules target)
    {
        bool isLibrarySupported = false;

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            isLibrarySupported = true;

            // get library path 
			string libPath = Path.Combine(ModuleDirectory, "lib");
        
			//add include paths
			PublicIncludePaths.AddRange(new string[] 
			{
				Path.Combine(ModuleDirectory, "include"),
				Path.Combine(ModuleDirectory, "includeCommo")
			});

			// add libs
			PublicAdditionalLibraries.AddRange(new string[]
			{
				Path.Combine(libPath, "commoncommo.lib")
			});

			// handle dlls
			string[] dllNames = {
				"charset-1.dll",
				"commoncommo.dll",
				"iconv-2.dll",
				"libcrypto-81_3.dll",
				"libcurl.dll",
				"libmicrohttpd-dll.dll",
				"libprotobuf.dll",
				"libprotobuf-lite.dll",
				"libssl-81_3.dll",
				//"libxml2.dll",  // in VH_Database_Spatialite
				"nghttp2.dll",
				"ngtcp2.dll",
				"ngtcp2_crypto_quictls.dll",
				"provider-ncrypt.dll",
				"zlibwapi.dll"
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
