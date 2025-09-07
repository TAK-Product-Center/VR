// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class VH_FileIO_Kml : ModuleRules
{
    public VH_FileIO_Kml(ReadOnlyTargetRules Target) : base(Target)
	{
		bUsePrecompiled = true;

		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {
			// ... add public include paths required here ...
            Path.Combine(ModuleDirectory, "Core/Public"),
            Path.Combine(ModuleDirectory, "Types/Public"),
            Path.Combine(ModuleDirectory, "Objects/Public"),
        });
		
		PrivateIncludePaths.AddRange(new string[] {
			// ... add other private include paths required here ...
		});
		
		PublicDependencyModuleNames.AddRange(new string[] {
			// ... add other public dependencies that you statically link with here ...

			// UE4 engine modules
			"Core",
            "CoreUObject",
            "Engine",
            "RHI",
            "RenderCore",
            "ProceduralMeshComponent",

			// VH modules
            "VH_FileIO",

			// ThirdParty modules
            "libkml",
        });

        PrivateDependencyModuleNames.AddRange(new string[] {
            // ... add private dependencies that you statically link with here ...	

			// VH modules
            "VH_Developer",
            "VH_Globe",
            "VH_GlobeMath",
			
			// ThirdParty modules
            "libkml",

			// UE4 engine modules
            "Slate",
			"SlateCore",
            "ProceduralMeshComponent",
            "ImageWrapper",
			"RenderCore",
        });
		
		DynamicallyLoadedModuleNames.AddRange(new string[] {
			// ... add any modules that your module loads dynamically here ...
        });

    }
}
