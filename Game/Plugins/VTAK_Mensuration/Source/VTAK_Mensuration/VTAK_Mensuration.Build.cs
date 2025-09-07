using UnrealBuildTool;
using System.IO;

public class VTAK_Mensuration : ModuleRules
{
    public VTAK_Mensuration(ReadOnlyTargetRules target) : base(target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        
        PublicIncludePaths.AddRange(new string[] {
			// ... add public include paths required here ...
            Path.Combine(ModuleDirectory, "Core/Public"),
            Path.Combine(ModuleDirectory, "Entities/Public"),
            Path.Combine(ModuleDirectory, "UI/Public")
        });


        PublicDependencyModuleNames.AddRange(
            new string[]
			{
                // UE4 engine modules
				"Core", 
				"CoreUObject", 
				"Engine",
				"Projects"
            });

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                // Engine
                "UMG",
                "XmlParser",

                // VH plugin modules
                "VH_COT",
                "VH_Developer",
				"VH_Globe",
                "VH_UI",
				"VH_VR",
				"VH_Plugins",

                // Game layer modules
                "Game"
            });
    }
}
