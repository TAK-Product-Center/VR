using UnrealBuildTool;

public class VH_ArtUtilitiesEditor : ModuleRules
{
	public VH_ArtUtilitiesEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		bUsePrecompiled = true;
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		bLegacyPublicIncludePaths = false;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"Slate",
				"SlateCore",
				"UMG"
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Foliage",
				"Slate",
				"SlateCore",
				"UMG",
				"Blutility"
			}
			);
	}
}
