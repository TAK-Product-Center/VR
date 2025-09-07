using UnrealBuildTool;
using System.IO;

public class VH_Developer : ModuleRules
{
    public VH_Developer(ReadOnlyTargetRules Target) : base(Target)
	{
		bUsePrecompiled = true;

		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		bEnableExceptions = true;

		PublicIncludePaths.AddRange(new string[] {
			Path.Combine(ModuleDirectory, "Components/Public"),
			Path.Combine(ModuleDirectory, "ConverterUnits/Public"),
			Path.Combine(ModuleDirectory, "Core/Public"),
			Path.Combine(ModuleDirectory, "Subsystems/Public"),
            Path.Combine(ModuleDirectory, "ThirdParty/Public")
        });

		PublicDependencyModuleNames.AddRange(
            new string[] {
                "ApplicationCore",
				"Boost",
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
