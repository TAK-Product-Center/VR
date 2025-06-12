using UnrealBuildTool;
using System.IO;

public class VH_SessionPlayback : ModuleRules
{
    public VH_SessionPlayback(ReadOnlyTargetRules Target) : base(Target)
    {
	    bUsePrecompiled = true;
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {
			Path.Combine(ModuleDirectory, "Core/Public"),
			Path.Combine(ModuleDirectory, "Subsystems/Public"),
		});

        PublicDependencyModuleNames.AddRange(
            new string[] { 
            "Core", 
            "CoreUObject", 
            "Engine",
            "InputCore",
			"VH_Developer",
        });
	}
}
