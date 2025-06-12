using UnrealBuildTool;
using System.IO;

public class VH_Developer : ModuleRules
{
    public VH_Developer(ReadOnlyTargetRules Target) : base(Target)
	{
		bUsePrecompiled = true;
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(new string[] {
			Path.Combine(ModuleDirectory, "Components/Public"),
			Path.Combine(ModuleDirectory, "ConverterUnits/Public"),
			Path.Combine(ModuleDirectory, "Core/Public"),
			Path.Combine(ModuleDirectory, "Subsystems/Public"),
		});

		PublicDependencyModuleNames.AddRange(
            new string[] {
                "ApplicationCore",
                "Core", 
				"CoreUObject", 
			    "Engine",
				"EnhancedInput",
		        "InputCore",
				"RHI",
				"RenderCore",
                "XmlParser",
				"Slate",
				"SlateCore",
				"Sockets",
				"HeadMountedDisplay"
            }
		);

		PrivateDependencyModuleNames.AddRange(
		new string[] {
				"Projects",
			}
		);

		if (Target.bBuildEditor == true)
		{
			PrivateDependencyModuleNames.Add("UnrealEd");
			PrivateDependencyModuleNames.Add("Settings");
		}
	}
}
