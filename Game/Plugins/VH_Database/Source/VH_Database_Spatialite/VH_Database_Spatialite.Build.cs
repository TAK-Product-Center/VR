using UnrealBuildTool;

public class VH_Database_Spatialite : ModuleRules
{
    public VH_Database_Spatialite(ReadOnlyTargetRules target) : base(target)
    {
	bUsePrecompiled = true;
        bEnableExceptions = true;

        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[] { 
            "Core", 
            "CoreUObject", 
            "Engine",
            "spatialite",

			// VH modules (sorted alphabetically)
            "VH_Developer"
        });
	}
}