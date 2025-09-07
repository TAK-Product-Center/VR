using UnrealBuildTool;
using System.IO;

public class VH_Keyboard : ModuleRules
{
    public VH_Keyboard(ReadOnlyTargetRules Target) : base(Target)
    {
		bUsePrecompiled = true;

		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {
			Path.Combine(ModuleDirectory, "Components/Public"),
			Path.Combine(ModuleDirectory, "Core/Public"),
			Path.Combine(ModuleDirectory, "Examples/Public"),
			Path.Combine(ModuleDirectory, "Subsystems/Public"),
		});

        PublicDependencyModuleNames.AddRange(
            new string[] { 
            "Core", 
            "CoreUObject", 
            "Engine",
            "InputCore",
            "UMG",
			"VH_Developer"
        });

        PrivateDependencyModuleNames.AddRange(
            new string[] { 
            "Slate", 
            "SlateCore"
        });

		if (Target.bBuildEditor == true)
		{
			PrivateDependencyModuleNames.Add("Settings");
		}
	}
}
