using UnrealBuildTool;

public class VH_ArtUtilities : ModuleRules
{
	public VH_ArtUtilities(ReadOnlyTargetRules Target) : base(Target)
	{
		bUsePrecompiled = true;
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		bLegacyPublicIncludePaths = false;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core"
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Foliage",
				"Slate",
				"SlateCore"
			}
			);
	}
}
