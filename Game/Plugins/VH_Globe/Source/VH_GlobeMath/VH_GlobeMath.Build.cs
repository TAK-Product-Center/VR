// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;
using System;

public class VH_GlobeMath : ModuleRules
{
    public VH_GlobeMath(ReadOnlyTargetRules Target) : base(Target)
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

		// NOTE: This will auto-copy the files to the appropriate dev/shipping bin path!
		string filename = "WMM.COF";
		RuntimeDependencies.Add(Path.Combine("$(TargetOutputDir)", filename), Path.Combine(ModuleDirectory, "Resources", filename), StagedFileType.NonUFS);
	}
}
