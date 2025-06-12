using UnrealBuildTool;
using System.IO;

public class VH_UI : ModuleRules
{
	public VH_UI(ReadOnlyTargetRules Target) : base(Target)
	{
		bUsePrecompiled = true;
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(new string[] 
		{
			Path.Combine(ModuleDirectory, "Core/Public"),
			Path.Combine(ModuleDirectory, "Subsystems/Public"),



			// deprecated
			Path.Combine(ModuleDirectory, "Deprecated/Public"),
		});

		PublicDependencyModuleNames.AddRange(new string[] 
		{
			"ApplicationCore",
			"Core",
			"CoreUObject",
            "DeveloperSettings",
            "Engine",
			"InputCore",
			"UMG",
			"MoviePlayer",
			"VH_Developer"
		});

		PrivateDependencyModuleNames.AddRange(new string[] 
		{
			"Slate",
			"SlateCore"
		});

		if (Target.bBuildEditor == true)
		{
			PrivateDependencyModuleNames.Add("Settings");
		}
	}
}
