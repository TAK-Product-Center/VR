// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class VH_Globe : ModuleRules
{
    public VH_Globe(ReadOnlyTargetRules Target) : base(Target)
	{
		bUsePrecompiled = true;

		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {
        	// engine paths (sorted alphabetically)

			// project paths (sorted alphabetically)

		});
		
		PrivateIncludePaths.AddRange(new string[] {
        	// engine paths (sorted alphabetically)

			// project paths (sorted alphabetically)

		});
		
		PublicDependencyModuleNames.AddRange(new string[] {
            // ... add other public dependencies that you statically link with here ...

            // UE4 engine modules (sorted alphabetically)
			"Core",
            "CoreUObject",
            "Engine",
            "RHI",
            "RenderCore",

            // VH modules (sorted alphabetically)
            "VH_Database_Spatialite",
            "VH_GlobeMath",

            // ThirdParty modules (sorted alphabetically)

        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            // ... add private dependencies that you statically link with here ...	

            // UE4 engine modules (sorted alphabetically)
            //"Slate",
			//"SlateCore",

            // VH modules (sorted alphabetically)
            "VH_Developer",

            // ThirdParty modules (sorted alphabetically)

        });
		
		DynamicallyLoadedModuleNames.AddRange(new string[] {
            // ... add any modules that your module loads dynamically here ...

            // UE4 engine modules (sorted alphabetically)

            // VH modules (sorted alphabetically)

            // ThirdParty modules (sorted alphabetically)

        });

    }
}
