// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class VH_FileIO : ModuleRules
{
    public VH_FileIO(ReadOnlyTargetRules Target) : base(Target)
	{
		bUsePrecompiled = true;
        bEnableExceptions = true;

        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {
			// ... add public include paths required here ...
            Path.Combine(ModuleDirectory, "Core/Public"),
            Path.Combine(ModuleDirectory, "Mesh/Public"),
            Path.Combine(ModuleDirectory, "Misc/Public"),
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
			"OpenCV",
			"OpenCVHelper",
            "RHI",
            "RenderCore",
            "XmlParser",

			// VH modules
			"VH_Database_Spatialite",
        });

        PrivateDependencyModuleNames.AddRange(new string[] {
			// ... add private dependencies that you statically link with here ...

			// VH modules
            "VH_Developer",
            "VH_Globe",
            "VH_GlobeMath",

			// ThirdParty modules
            "assimp",
            "VH_TP_FreeImage",
            "FreeImagePlus",
			"bit7z",

			// UE4 engine modules
            "ImageWrapper",
            "ProceduralMeshComponent",
            "RenderCore",
            "Slate",
            "SlateCore",
        });
		
		DynamicallyLoadedModuleNames.AddRange(new string[] {
			// ... add any modules that your module loads dynamically here ...
        });

    }
}
