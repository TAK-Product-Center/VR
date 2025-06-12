using UnrealBuildTool;
using System.IO;

public class TAKKernel : ModuleRules
{
    public TAKKernel(ReadOnlyTargetRules target) : base(target)
    {
        Type = ModuleType.External;

        LoadTAKKernel(target);
    }

    public bool LoadTAKKernel(ReadOnlyTargetRules target)
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
			});

			// add libs
			PublicAdditionalLibraries.AddRange(new string[]
			{
				Path.Combine(libPath, "TAK.Engine.lib"),
				Path.Combine(libPath, "takengine.lib")
			});

			// handle dlls
			string[] dllNames = {
				"assimp.dll",
				"engine-bcrypt.dll",
				"engine-ncrypt.dll",
				"gdal_csharp.dll",
				"gdal_wrap.dll",
				"gdal204.dll",
				"gdalconst_csharp.dll",
				"gdalconst_wrap.dll",
				//"geos_c.dll",  // ? geos_cpp.dll in spatialite.build.cs
				//"iconv-2.dll",
				"kdu_v64R.dll",
				"libcrypto-81_1_1.dll",
				//"libcurl.dll",
				//"libexpat.dll",
				"liblas.dll",
				"liblas_c.dll",
				"libssl-81_1_1.dll",
				//"libxml2.dll",
				"lti_dsdk_9.5.dll",
				//"nghttp2.dll",
				"ogdi.dll",
				"ogr_csharp.dll",
				"ogr_wrap.dll",
				"osr_csharp.dll",
				"osr_wrap.dll",
				//"proj.dll",
				//"spatialite.dll",
				"sqlite3.dll",
				"TAK.Engine.dll",
				"takengine.dll",
				//"tbb.dll",
				"vrf.dll"
				//"zlibwapi.dll"
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
