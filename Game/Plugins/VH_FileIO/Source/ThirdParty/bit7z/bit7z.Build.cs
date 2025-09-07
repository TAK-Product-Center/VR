using UnrealBuildTool;
using System.IO;

public class bit7z : ModuleRules
{
    public bit7z(ReadOnlyTargetRules target) : base(target)
    {
        Type = ModuleType.External;

		Loadbit7z(target);
    }

	// NOTE: See https://github.com/rikyoz/bit7z for how to use this library!
	public bool Loadbit7z(ReadOnlyTargetRules target)
    {
        bool isLibrarySupported = false;

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            isLibrarySupported = true;

            // get library path 
            string libPath = Path.Combine(ModuleDirectory, "lib");

            //add include paths
            PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "include") });

            // add libs
            PublicAdditionalLibraries.AddRange(new string[]
			{
				Path.Combine(libPath, "bit7z64.lib")
				//Path.Combine(libPath, "bit7z64_d.lib")
	        });

            // handle dlls
            string[] dllNames = {
				"7z.dll"
			};

			// NOTE: This will auto-copy the dll's to the staged bin path!
            string sdkPath = Path.Combine(ModuleDirectory, "bin", "x64", "release");
            foreach (string dllName in dllNames)
            {
                RuntimeDependencies.Add(Path.Combine("$(TargetOutputDir)", dllName), Path.Combine(sdkPath, dllName), StagedFileType.NonUFS);
            }
        }

        PublicDefinitions.Add(string.Format("WITH_FILEIO_BIT7Z={0}", (isLibrarySupported ? 1 : 0)));
		PublicDefinitions.Add(string.Format("BIT7Z_AUTO_FORMAT={0}", (isLibrarySupported ? 1 : 0)));
		return isLibrarySupported;
    }
}
