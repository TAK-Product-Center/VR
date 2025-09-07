using UnrealBuildTool;
using System.IO;

public class VTAK_Orbit : ModuleRules
{
    public VTAK_Orbit(ReadOnlyTargetRules target) : base(target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        
        PublicIncludePaths.AddRange(new string[] {
			Path.Combine(ModuleDirectory, "Components/Public"),
			Path.Combine(ModuleDirectory, "Core/Public"),
			Path.Combine(ModuleDirectory, "Entities/Public"),
			Path.Combine(ModuleDirectory, "EntityHandlers/Public"),
			Path.Combine(ModuleDirectory, "UI/Public")
        });


        PublicDependencyModuleNames.AddRange(
            new string[]
			{
				"Core", 
				"CoreUObject", 
				"Engine",
				"InputCore",
				"Projects"
            });

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "UMG",
                "VH_COT",
				"VH_Database_Spatialite",
                "VH_Developer",
				"VH_Globe",
                "VH_GlobeMath",
                "VH_UI",
				"VH_VR",
				"VH_Plugins",
                "XmlParser",

                // Game layer modules
                "Game"
            });
    }
}
