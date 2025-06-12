using UnrealBuildTool;
using System.IO;

public class gv2F : ModuleRules
{
    public gv2F(ReadOnlyTargetRules target) : base(target)
    {
        Type = ModuleType.External;

        LoadGv2F(target);
    }

    public bool LoadGv2F(ReadOnlyTargetRules target)
    {
        bool isLibrarySupported = false;

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            isLibrarySupported = true;

            // get library path 
			string libPath = Path.Combine(ModuleDirectory, "lib");
        
			// add include paths
			PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "include") });

			// add libs
			PublicAdditionalLibraries.AddRange(new string[]
			{
				Path.Combine(libPath, "mspgscmedia.lib")
			});

			// handle dlls
			string[] dllNames = {
                "avcodecpgsc.dll",
                "avdevicepgsc.dll",
                "avfilterpgsc.dll",
                "avformatpgsc.dll",
                "avutilpgsc.dll",
                "avvideopgsc.dll",
                "libgcc_s_sjlj-1.dll",
                "libssp-0.dll",
                "libstdc++-6.dll",
                "libwinpthread-1.dll",
                "license.dll",
                "pgscmedia.dll",
                "swresamplepgsc.dll",
                "swscalepgsc.dll"
            };

            // NOTE: This will auto-copy the dll's to the staged bin path!
            string sdkPath = Path.Combine(ModuleDirectory, "bin", "x64", "release");
			foreach (string dllName in dllNames)
			{
                RuntimeDependencies.Add(Path.Combine("$(TargetOutputDir)", dllName), Path.Combine(sdkPath, dllName), StagedFileType.NonUFS);
            }
        }

        PublicDefinitions.Add(string.Format("WITH_COT_GV2F={0}", (isLibrarySupported ? 1 : 0)));
        return isLibrarySupported;
    }
}
