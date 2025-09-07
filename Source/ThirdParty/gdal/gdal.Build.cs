using UnrealBuildTool;
using System.IO;

public class gdal : ModuleRules
{
    public gdal(ReadOnlyTargetRules target) : base(target)
    {
        Type = ModuleType.External;

        LoadGdal(target);
    }

    public bool LoadGdal(ReadOnlyTargetRules target)
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
				Path.Combine(libPath, "gdal.lib")
			});

			// handle dlls
			string[] dllNames = {
                "deflate.dll",
				"gdal.dll",
                "geotiff.dll",
                "Lerc.dll",
                "libjpeg.dll",
                "liblzma.dll",
                "libtiff.dll",
                "libzstd.dll",
                "proj_9_3.dll",
                "tiff.dll",
                "zlib.dll",
                "zstd.dll"
			};

            // NOTE: This will auto-copy the dll's to the staged bin path!
            string sdkPath = Path.Combine(ModuleDirectory, "bin");
			foreach (string dllName in dllNames)
			{
                RuntimeDependencies.Add(Path.Combine("$(TargetOutputDir)", dllName), Path.Combine(sdkPath, dllName), StagedFileType.NonUFS);
            }
        }

        return isLibrarySupported;
    }
}
