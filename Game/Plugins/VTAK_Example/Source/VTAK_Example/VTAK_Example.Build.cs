using UnrealBuildTool;
using System.IO;

public class VTAK_Example : ModuleRules
{
    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../ThirdParty/")); }
    }

    private string GameBinaryPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "../../../../Binaries/")); }
    }

    public VTAK_Example(ReadOnlyTargetRules target) : base(target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
			{
				"Core", 
				"CoreUObject", 
				"Engine",
				"Projects"
            });

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Game",
                "VH_COT",
                "VH_Developer",
				"VH_Plugins"
            });
    }
}
