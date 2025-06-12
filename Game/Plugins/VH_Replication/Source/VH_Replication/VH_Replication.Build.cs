using UnrealBuildTool;
using System.IO;

public class VH_Replication : ModuleRules
{
    public VH_Replication(ReadOnlyTargetRules Target) : base(Target)
    {
	    bUsePrecompiled = true;
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] 
	{
		Path.Combine(ModuleDirectory, "Core/Public"),
		Path.Combine(ModuleDirectory, "Examples/Public"),
		Path.Combine(ModuleDirectory, "Subsystems/Public"),
		
		// deprecated
		Path.Combine(ModuleDirectory, "Deprecated/Public"),
	});

        PublicDependencyModuleNames.AddRange(new string[] 
	{ 
            "Core", 
            "CoreUObject", 
            "Engine",
        });

        PrivateDependencyModuleNames.AddRange(new string[] { 
        
	});
	
    }
}
