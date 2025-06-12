using UnrealBuildTool;
using System.IO;

public class VH_Database_MySQL : ModuleRules
{
    public VH_Database_MySQL(ReadOnlyTargetRules target) : base(target)
    {
	bUsePrecompiled = true;
        bEnableExceptions = true;

        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(new string[] {
			Path.Combine(ModuleDirectory, "Core/Public")
		});

		PublicDependencyModuleNames.AddRange(
            new string[] { 
            "Core", 
            "CoreUObject", 
            "Engine",
			"mySQL",

			// VH modules (sorted alphabetically)
            "VH_Developer",
			"VH_Replication"
        });
	}
}