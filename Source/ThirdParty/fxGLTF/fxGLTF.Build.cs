using UnrealBuildTool;
using System.IO;

public class fxGLTF : ModuleRules
{
    public fxGLTF(ReadOnlyTargetRules target) : base(target)
    {
        Type = ModuleType.External;

		LoadfxGLTF(target);
    }

    public bool LoadfxGLTF(ReadOnlyTargetRules target)
    {
        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
			//add include paths
			PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "include") });
		}

		return true;
    }
}
