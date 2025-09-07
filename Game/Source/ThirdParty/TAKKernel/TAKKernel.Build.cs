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
                Path.Combine(libPath, "assimp.lib"),
                Path.Combine(libPath, "gdal_i.lib"),
                Path.Combine(libPath, "geos_c_i.lib"),
                Path.Combine(libPath, "geos_i.lib"),
                Path.Combine(libPath, "iconv.dll.lib"),
                Path.Combine(libPath, "libcrypto.lib"),
                Path.Combine(libPath, "libcurl.lib"),
                Path.Combine(libPath, "libexpat.lib"),
                Path.Combine(libPath, "libkmlbase.lib"),
                Path.Combine(libPath, "libkmlconvenience.lib"),
                Path.Combine(libPath, "libkmldom.lib"),
                Path.Combine(libPath, "libkmlengine.lib"),
                Path.Combine(libPath, "libkmlregionator.lib"),
                Path.Combine(libPath, "libkmlxsd.lib"),
                Path.Combine(libPath, "libmdbsql.lib"),
                Path.Combine(libPath, "libssl.lib"),
                Path.Combine(libPath, "libxml2.lib"),
                Path.Combine(libPath, "mdb.lib"),
                Path.Combine(libPath, "minizip_static.lib"),
                Path.Combine(libPath, "nghttp2.lib"),
                Path.Combine(libPath, "ogdi.lib"),
                Path.Combine(libPath, "proj_i.lib"),
                Path.Combine(libPath, "spatialite.lib"),
                Path.Combine(libPath, "spatialite_i.lib"),
                Path.Combine(libPath, "sqlite3_i.lib"),
                Path.Combine(libPath, "uriparser.lib"),
                Path.Combine(libPath, "zlibwapi.lib"),
				Path.Combine(libPath, "takengine.lib")
			});

            // handle dlls (commented means added as a RuntimeDependency in other project or not needed)
            string[] dllNames = {
                "assimp.dll",
                "gdal_wrap.dll",
                "gdal204.dll",
                "gdalconst_wrap.dll",
				//"geos_c.dll",  
				//"iconv-2.dll",
                //"jassimp.dll",
				"kdu_v64R.dll",
                //"libcrypto-81_3.dll",
				//"libcurl.dll",
				//"libexpat.dll",
                "libmdb.dll",
                "libmdbsql.dll",
                //"libssl-81_3.dll",
				//"libxml2.dll",
				"liblas.dll",
				"liblas_c.dll",
				"lti_dsdk_9.5.dll",
				//"nghttp2.dll",
				"ogdi.dll",
                "ogr_wrap.dll",
                "osr_wrap.dll",
				//"proj.dll",
                //"provider-ncrypt.dll",
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
