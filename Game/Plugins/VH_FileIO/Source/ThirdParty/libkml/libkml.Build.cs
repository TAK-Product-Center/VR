using UnrealBuildTool;
using System.IO;

public class libkml : ModuleRules
{
    public libkml(ReadOnlyTargetRules target) : base(target)
    {
        Type = ModuleType.External;

        LoadLibKML(target);
    }

    // NOTE: See https://github.com/google/libkml/wiki for how to use this library!
    public bool LoadLibKML(ReadOnlyTargetRules target)
    {
        bool isLibrarySupported = false;

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            isLibrarySupported = true;

            // get library path 
            string libPath = Path.Combine(ModuleDirectory, "lib", "x64", "release");

            //add include paths
            PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "include") });

            // add libs
            PublicAdditionalLibraries.AddRange(new string[]
			{
				Path.Combine(libPath, "libkmlbase.lib"),
				Path.Combine(libPath, "libkmlconvenience.lib"),
				Path.Combine(libPath, "libkmldom.lib"),
				Path.Combine(libPath, "libkmlengine.lib"),
				Path.Combine(libPath, "libkmlregionator.lib"),
				Path.Combine(libPath, "libkmlxsd.lib")
	        });

            // handle dlls
            string[] dllNames = {
				"libexpat.dll"
			};

			// NOTE: This will auto-copy the dll's to the staged bin path!
            string sdkPath = Path.Combine(ModuleDirectory, "bin", "x64", "release");
            foreach (string dllName in dllNames)
            {
                RuntimeDependencies.Add(Path.Combine("$(TargetOutputDir)", dllName), Path.Combine(sdkPath, dllName), StagedFileType.NonUFS);
            }
        }

        PublicDefinitions.Add(string.Format("WITH_FILEIO_LIBKML={0}", (isLibrarySupported ? 1 : 0)));
        return isLibrarySupported;
    }
}
