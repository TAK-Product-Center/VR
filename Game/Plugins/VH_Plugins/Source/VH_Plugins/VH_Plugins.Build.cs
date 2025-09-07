using UnrealBuildTool;
using System.IO;

public class VH_Plugins : ModuleRules
{
	public VH_Plugins(ReadOnlyTargetRules Target) : base(Target)
	{
		bUsePrecompiled = true;

		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
				
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"AssetRegistry"
				
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "AssetRegistry",
                "Projects",
				"VH_Developer",
				"VH_FileIO"
			}
			);
		
	}
}
